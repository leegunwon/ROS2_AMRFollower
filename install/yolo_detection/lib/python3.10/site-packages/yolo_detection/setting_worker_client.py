import rclpy
from rclpy.node import Node
from std_srvs.srv import Trigger

class TriggerServiceClient(Node):
    def __init__(self):
        super().__init__('trigger_service_client')
        self.client = self.create_client(Trigger, 'set_worker')

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service...')

        self.get_logger().info('Service available. Sending trigger request...')
        self.send_request()

    def send_request(self):
        request = Trigger.Request()  # 요청 생성 (비어 있음)
        future = self.client.call_async(request)
        future.add_done_callback(self.callback)

    def callback(self, future):
        try:
            response = future.result()
            self.get_logger().info(f"Response: success={response.success}, message='{response.message}'")
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = TriggerServiceClient()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down Trigger Service Client...')
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()
