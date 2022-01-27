#include <composition_benchmark/composable_subscriber.hpp>
#include <composition_benchmark/global_factory.hpp>
#include <irobot_interfaces_plugin/msg/stamped_vector.hpp>
#include <performance_test/utils/stat_logger.hpp>

ComposableSubscriber::ComposableSubscriber(const rclcpp::NodeOptions & options)
: performance_test::PerformanceNode<rclcpp::Node>(
  global_factory::get_node_name(),
  global_factory::get_namespace(),
  options,
  global_factory::get_executor_id())
{
  auto topic_name = this->declare_parameter<std::string>("topic", "my_topic");

  auto topic = performance_test::Topic<irobot_interfaces_plugin::msg::StampedVector>(topic_name);
  this->add_subscriber(topic, PASS_BY_SHARED_PTR);
  global_factory::mark_node_created();
}

ComposableSubscriber::~ComposableSubscriber()
{
  performance_test::log_latency_all_stats<performance_test::PerformanceNode<rclcpp::Node>>(std::cout, {this});
}

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(ComposableSubscriber)
