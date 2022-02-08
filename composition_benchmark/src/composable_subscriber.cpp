#include <composition_benchmark/composable_subscriber.hpp>
#include <irobot_interfaces_plugin/msg/stamped_vector.hpp>
#include <performance_metrics/stat_logger.hpp>

ComposableSubscriber::ComposableSubscriber(const rclcpp::NodeOptions & options)
: performance_test::PerformanceNode<rclcpp::Node>(
  "composable_subscriber",
  "",
  options)
{
  auto topic_name = this->declare_parameter<std::string>("topic", "my_topic");

  this->add_subscriber<irobot_interfaces_plugin::msg::StampedVector>(topic_name, PASS_BY_SHARED_PTR);
}

ComposableSubscriber::~ComposableSubscriber()
{
  performance_metrics::log_latency_all_stats(std::cout, this->sub_trackers());
}

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(ComposableSubscriber)
