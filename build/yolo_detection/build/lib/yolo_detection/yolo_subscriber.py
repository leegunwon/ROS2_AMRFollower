import rclpy
from rclpy.node import Node
from my_interfaces.msg import ObjectData
from cv_bridge import CvBridge
import cv2

class ObjectDataSubscriber(Node):
    def __init__(self):
        super().__init__('object_data_subscriber')

        # ObjectData 메시지 구독
        self.subscription = self.create_subscription(
            ObjectData,
            '/detected_worker',  # 퍼블리시된 ObjectData 메시지 토픽
            self.object_data_callback,
            10
        )
        self.subscription  # prevent unused variable warning

        # CvBridge 객체 생성
        self.bridge = CvBridge()

        self.get_logger().info("ObjectData Subscriber Node Initialized")

    def object_data_callback(self, msg):
        self.get_logger().info(f"Received ObjectData: position={msg.position.data}")

        # ROS Image 메시지를 OpenCV 이미지로 변환
        cropped_frame = self.bridge.imgmsg_to_cv2(msg.image, desired_encoding='bgr8')

        # 이미지를 화면에 표시
        # cv2.imshow("Cropped Object Image", cropped_frame)
        cv2.imwrite("cropped_object_image.jpg", cropped_frame)

        cv2.waitKey(1)  # ROS에서 비디오 스트림을 처리하려면 1ms 대기

def main(args=None):
    rclpy.init(args=args)
    node = ObjectDataSubscriber()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down ObjectData Subscriber Node...')
    finally:
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
