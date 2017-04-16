cmake_minimum_required(VERSION 2.8.3)
project(test_pluginlib)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  image_transport
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
)

add_executable(image_transport_test src/test_pluginlib/image_transport_test.cpp)
target_link_libraries(image_transport_test ${catkin_LIBRARIES})
