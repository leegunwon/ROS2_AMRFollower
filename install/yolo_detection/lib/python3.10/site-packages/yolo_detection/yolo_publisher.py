import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
from my_interfaces.msg import ObjectData
from std_srvs.srv import Trigger


class YOLODetectionNode(Node):
    def __init__(self):
        super().__init__('yolo_detection_node')
        self.yolo_start = False
        self.image = None
        self.worker = None
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
        
        # 
        self.srv = self.create_service(Trigger, 'set_worker', self.handle_trigger)
        
        # ObjectData 메시지를 퍼블리시하는 퍼블리셔
        self.object_data_publisher = self.create_publisher(
            ObjectData,
            '/detected_worker',  # 퍼블리시할 토픽 이름
            10
        )

        self.get_logger().info("YOLO Detection Node Initialized")

    def image_callback(self, msg):
        self.image = msg
        if self.yolo_start:
            self.object_detection(self.image)
        
            
    def handle_trigger(self, request, response):
        # 요청 처리 로직
        self.get_logger().info('Trigger request received')
        frame = self.bridge.imgmsg_to_cv2(self.image, desired_encoding='bgr8')

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

            # ObjectData 메시지 생성
            object_data_msg = ObjectData()
            object_data_msg.position.data = [x1, y1, x2, y2]
            object_data_msg.image = self.bridge.cv2_to_imgmsg(frame[y1:y2, x1:x2], encoding='bgr8')

            self.worker = object_data_msg
            
            # 퍼블리시
            self.object_data_publisher.publish(object_data_msg)
            self.get_logger().info(f"Published ObjectData message for class: {label}, confidence: {conf:.2f}")

            # 바운딩 박스 그리기
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.putText(frame, f"{label} {conf:.2f}", (x1, y1 - 10),
            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)      
            
            self.yolo_start = False
            response.success = True  # True 또는 False 반환
            response.message = "Trigger executed successfully!"
            
        elif len(results[0].boxes) > 1:
            response.success = False
            response.message = "'Multiple workers detected'"
        else:
            response.success = False
            response.message = "No worker detected!"


        return response


    def object_detection(self):
        frame = self.bridge.imgmsg_to_cv2(self.image, desired_encoding='bgr8')

        # YOLO로 객체 탐지
        results = self.model.predict(frame, imgsz=640, conf=0.5)

        # 탐지된 객체 처리
        for box in results[0].boxes:
            # 바운딩 박스 정보 가져오기
            x1, y1, x2, y2 = map(int, box.xyxy[0])
            conf = float(box.conf[0])
            cls = int(box.cls[0])
            label = self.model.names[cls]

            # ObjectData 메시지 생성
            object_data_msg = ObjectData()
            object_data_msg.position.data = [x1, y1, x2, y2]
            object_data_msg.image = self.bridge.cv2_to_imgmsg(frame[y1:y2, x1:x2], encoding='bgr8')

            # 여기에 동일한 객체인지 확인 code 추가
            self.worker = object_data_msg
            
            # 퍼블리시
            self.object_data_publisher.publish(object_data_msg)
            self.get_logger().info(f"Published ObjectData message for class: {label}, confidence: {conf:.2f}")

            # 바운딩 박스 그리기
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.putText(frame, f"{label} {conf:.2f}", (x1, y1 - 10),
            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)      
  
            
            
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
