#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/get_pose_from_point.hpp"
#include <sensor_msgs/msg/point_cloud2.hpp>
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose.hpp"

from geometry_msgs.msg import PolygonStamped, Pose, Point, Point32, Quaternion, Vector3Stamped

void call(const std::shared_ptr<robot_planning_interfaces::srv::GetPoseFromPoint::Request> request,
          std::shared_ptr<robot_planning_interfaces::srv::GetPoseFromPoint::Response>      response)
{
//   response->sum = request->a + request->b;
//   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
//                 request->a, request->b);
//   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("get_pose_from_point.cpp");

  rclcpp::Service<robot_planning_interfaces::srv::GetPoseFromPoint>::SharedPtr service =
    node->create_service<robot_planning_interfaces::srv::GetPoseFromPoint>("get_pose_from_point", &call);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Called service to obtain sampling pose");

  rclcpp::spin(node);
  rclcpp::shutdown();
}