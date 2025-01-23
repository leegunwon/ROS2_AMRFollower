from setuptools import setup

package_name = 'yolo_detection'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='your_name',
    maintainer_email='your_email@example.com',
    description='YOLO Detection Node',
    license='License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'yolo_publisher_node = yolo_detection.yolo_publisher:main',  # 이 부분 수정
            'camera_image_publisher_node = yolo_detection.camera_image_publisher:main',
            'yolo_subscriber_node = yolo_detection.yolo_subscriber:main',
        ],
    },
)

