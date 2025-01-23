import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO

class YOLODetectionNode(Node):
    def __init__(self):
        super().__init__('yolo_detection_node')
        
        # YOLO 모델 로드
        self.model = YOLO('yolov8n.pt')  # YOLO 모델 경로
        self.bridge = CvBridge()

        # /camera/image 토픽 구독
        self.subscription = self.create_subscription(
            Image,
            '/camera/image',  # 카메라 이미지 토픽 이름
            self.image_callback,
            10
        )
        self.subscription  # prevent unused variable warning

        self.get_logger().info("YOLO Detection Node Initialized")

    def image_callback(self, msg):
        self.get_logger().info("Image received")

        # ROS Image 메시지를 OpenCV 이미지로 변환
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        # YOLO로 객체 탐지
        results = self.model.predict(frame, imgsz=640, conf=0.5)

        # 탐지된 객체 처리
        for box in results[0].boxes:
            # 바운딩 박스 정보 가져오기
            x1, y1, x2, y2 = map(int, box.xyxy[0])
            conf = box.conf[0]
            cls = int(box.cls[0])
            label = self.model.names[cls]

            # 바운딩 박스 그리기
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.putText(frame, f"{label} {conf:.2f}", (x1, y1 - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

        # 이미지 출력 (선택 사항)
        cv2.imshow("YOLO Detection", frame)
        cv2.waitKey(1)  # ROS에서 비디오 스트림을 처리하려면 1ms 대기

def main(args=None):
    rclpy.init(args=args)
    node = YOLODetectionNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down YOLO Detection Node...')
    finally:
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

