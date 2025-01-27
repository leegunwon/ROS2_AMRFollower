import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
from std_srvs.srv import Trigger
import time
from geometry_msgs.msg import Twist
import threading


class YOLODetectionNode(Node):
    def __init__(self):
        super().__init__('yolo_detect_node')
        self.yolo_start = False
        self.image = None
        self.worker_position = None
        self.image_lock = threading.Lock()  # 이미지 변수에 대한 스레드 동기화를 위한 Lock

        # YOLO 모델 로드
        self.model = YOLO('best.pt')  # YOLO 모델 경로
        self.bridge = CvBridge()

        self.prev_error_x = 0.0
        self.prev_error_y = 0.0
        self.prev_time = time.time()

        # 터틀봇3 제어를 위한 /cmd_vel 퍼블리셔
        self.cmd_vel_publisher = self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )

        # 서비스 생성
        self.srv = self.create_service(Trigger, 'set_worker', self.handle_trigger)

        # 카메라 초기화 (0번 카메라 사용)
        self.cap = cv2.VideoCapture(0)
        if not self.cap.isOpened():
            self.get_logger().error("Failed to open camera.")
        else:
            self.get_logger().info("Camera opened successfully.")

        # 타이머 생성 (0.01초 간격으로 실행)
        self.timer = self.create_timer(0.1, self.camera_callback)

        self.get_logger().info("YOLO Detection Node Initialized")

    def camera_callback(self):
        # 카메라에서 이미지 캡처
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().error("Failed to capture image from camera.")
            return

        # 이미지 데이터를 스레드 안전하게 저장
        with self.image_lock:
            self.image = frame

        # YOLO 탐지 시작 여부 확인
        if self.yolo_start:
            self.object_detection()

    def handle_trigger(self, request, response):
        # 이미지 데이터를 스레드 안전하게 읽기
        with self.image_lock:
            if self.image is None:
                response.success = False
                response.message = "No image received yet!"
                return response

            frame = self.image

        # YOLO로 객체 탐지
        results = self.model.predict(frame, imgsz=640, conf=0.5)

        # 탐지된 객체 처리
        if len(results[0].boxes) == 1:
            box = results[0].boxes[0]
            # 바운딩 박스 정보 가져오기
            x1, y1, x2, y2 = map(int, box.xyxy[0])
            conf = float(box.conf[0])
            cls = int(box.cls[0])
            label = self.model.names[cls]

            self.worker_position = [x1, y1, x2, y2]

            # 바운딩 박스 그리기
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.putText(frame, f"{label} {conf:.2f}", (x1, y1 - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

            # YOLO 탐지 시작
            self.yolo_start = True

            response.success = True  # True 또는 False 반환
            response.message = "Trigger executed successfully!"

        elif len(results[0].boxes) > 1:
            response.success = False
            response.message = "Multiple workers detected"
        else:
            response.success = False
            response.message = "No worker detected!"

        return response

    def object_detection(self):
        # 이미지 데이터를 스레드 안전하게 읽기
        with self.image_lock:
            if self.image is None:
                return

            frame = self.image

        # YOLO로 객체 탐지
        results = self.model.predict(frame, imgsz=640, conf=0.5)

        # 탐지된 객체 처리
        for box in results[0].boxes:
            # 바운딩 박스 정보 가져오기
            x1, y1, x2, y2 = map(int, box.xyxy[0])
            conf = float(box.conf[0])
            cls = int(box.cls[0])
            label = self.model.names[cls]

            self.worker_position = [x1, y1, x2, y2]

            # 바운딩 박스 그리기
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.putText(frame, f"{label} {conf:.2f}", (x1, y1 - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

        self.chasing_object()

    def chasing_object(self):
        if self.worker_position is None:
            self.get_logger().warning("추적할 객체가 없습니다.")
            twist_msg = Twist()
            twist_msg.linear.x = 0.0
            twist_msg.angular.z = 0.0

            self.cmd_vel_publisher.publish(twist_msg)
            return

        position = self.worker_position
        # 바운딩 박스 중심 계산
        x1, y1, x2, y2 = position
        center_x = (x1 + x2) // 2
        center_y = (y1 + y2) // 2

        # 화면 중심 계산
        image_width = 1280
        image_height = 720
        frame_center_x = image_width // 2
        frame_threshold_y = image_height // 3

        # 중심 오차 계산
        error_x = frame_center_x  - center_x 
        error_y = frame_threshold_y - center_y 

        # 현재 시간 및 시간 변화량 계산
        current_time = time.time()
        dt = current_time - self.prev_time

        # 비례, 미분, 적분 제어 계수 (튜닝 필요)
        self.integral_error_x = 0.0
        self.integral_error_y = 0.0
        Ki = 0.0001
        Kp = 0.002
        Kd = 0.001

        # 적분 오차 누적
        self.integral_error_x += error_x * dt
        self.integral_error_y += error_y * dt

        # 속도 계산 (PID 제어)
        angular_speed = -Kp * error_x # - Kd * (error_x - self.prev_error_x) / dt - Ki * self.integral_error_x
        linear_speed = Kp * error_y # + Kd * (error_y - self.prev_error_y) / dt + Ki * self.integral_error_y

        # 속도 제한
        linear_speed = max(min(linear_speed, 0.2), -0.2)
        angular_speed = max(min(angular_speed, 1.0), -1.0)

        # angular_speed = 0.0
        
        twist_msg = Twist()
        twist_msg.linear.x = linear_speed
        twist_msg.angular.z = angular_speed

        self.cmd_vel_publisher.publish(twist_msg)
        
        self.get_logger().info(
            f"Published Twist message: linear.x={linear_speed:.2f}, angular.z={angular_speed:.2f}"
        )
               
        self.prev_error_x = error_x
        self.prev_error_y = error_y
        self.prev_time = current_time

    def destroy_node(self):
        # 노드 종료 시 카메라 릴리즈
        self.cap.release()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = YOLODetectionNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down YOLO Detection Node...')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
