#include "perception_process.h"

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  RCLCPP_INFO(rclcpp::get_logger("perception_process_main"), "perception start");
  auto node = std::make_shared<Perception::PerceptionProcess>();
  if (!node->process())
  {
    RCLCPP_ERROR(rclcpp::get_logger("perception_process_main"), "perception failed!");
    rclcpp::shutdown();
    return 1;
  }
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
