import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class CameraImagePublisher(Node):
    def __init__(self):
        super().__init__('camera_image_publisher')

        # 퍼블리셔 설정
        self.publisher_ = self.create_publisher(Image, '/camera/image', 10)

        # OpenCV를 ROS 메시지로 변환하기 위한 브리지
        self.bridge = CvBridge()

        # 타이머 생성 (0.1초 간격으로 실행)
        self.timer = self.create_timer(0.01, self.timer_callback)

        # 카메라 초기화 (0번 카메라 사용)
        self.cap = cv2.VideoCapture(0)
        if not self.cap.isOpened():
            self.get_logger().error("Failed to open camera.")

        self.get_logger().info("Camera Image Publisher Node Initialized")

    def timer_callback(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().error("Failed to capture image from camera.")
            return

        # OpenCV 이미지를 ROS Image 메시지로 변환
        image_msg = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')

        # 퍼블리시
        self.publisher_.publish(image_msg)

    def destroy_node(self):
        # 노드 종료 시 카메라 릴리즈
        self.cap.release()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = CameraImagePublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down Camera Image Publisher Node...')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
