#include <stdlib.h>
#include <ros/ros.h>
#include <image_transport/image_transport.h>

#define ALLOC_SIZE  (10ull << 28)   // It is large enough to occupy more than half of free memory

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  ROS_INFO("subscribe image");
}


int main(int argc, char *argv[])
{
  ros::init(argc, argv, "image_transport_test");
  void *p = malloc(ALLOC_SIZE);
  memset(p, 0x55, ALLOC_SIZE);  // Write real memory

  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("/usb_cam/image_raw", 1, imageCallback);
  ros::spin();
}
