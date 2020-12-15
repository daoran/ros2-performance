#pragma once

#include "performance_test/ros2/node.hpp"

  
#include "irobot_interfaces_plugin/msg/stamped_int64.hpp"
#include "irobot_interfaces_plugin/msg/stamped3_float32.hpp"
#include "irobot_interfaces_plugin/msg/stamped4_float32.hpp"
#include "irobot_interfaces_plugin/msg/stamped4_int32.hpp"
#include "irobot_interfaces_plugin/msg/stamped9_float32.hpp"
#include "irobot_interfaces_plugin/msg/stamped12_float32.hpp"
#include "irobot_interfaces_plugin/msg/stamped10b.hpp"
#include "irobot_interfaces_plugin/msg/stamped100b.hpp"
#include "irobot_interfaces_plugin/msg/stamped250b.hpp"
#include "irobot_interfaces_plugin/msg/stamped1kb.hpp"
#include "irobot_interfaces_plugin/msg/stamped10kb.hpp"
#include "irobot_interfaces_plugin/msg/stamped100kb.hpp"
#include "irobot_interfaces_plugin/msg/stamped250kb.hpp"
#include "irobot_interfaces_plugin/msg/stamped600kb.hpp"
#include "irobot_interfaces_plugin/msg/stamped1mb.hpp"
#include "irobot_interfaces_plugin/msg/stamped4mb.hpp"
#include "irobot_interfaces_plugin/msg/stamped8mb.hpp"
#include "irobot_interfaces_plugin/msg/stamped_vector.hpp"

#include "irobot_interfaces_plugin/srv/stamped10b.hpp"


  extern "C" void add_subscriber_impl(
    std::shared_ptr<performance_test::Node> n,
    std::string msg_type,
    std::string topic_name,
    performance_test::Tracker::TrackingOptions tracking_options,
    msg_pass_by_t msg_pass_by,
    rmw_qos_profile_t custom_qos_profile)
  {
    const std::map<std::string, std::function<void()>> subscribers_factory{
  
{"stamped_int64",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::StampedInt64>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped3_float32",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped3Float32>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped4_float32",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped4Float32>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped4_int32",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped4Int32>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped9_float32",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped9Float32>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped12_float32",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped12Float32>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped10b",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped10b>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped100b",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped100b>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped250b",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped250b>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped1kb",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped1kb>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped10kb",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped10kb>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped100kb",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped100kb>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped250kb",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped250kb>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped600kb",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped600kb>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped1mb",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped1mb>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped4mb",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped4mb>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped8mb",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped8mb>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } },
{"stamped_vector",  [&] { n->add_subscriber(performance_test::Topic<irobot_interfaces_plugin::msg::StampedVector>(topic_name), msg_pass_by, tracking_options, custom_qos_profile); } }
    };

    if (subscribers_factory.find(msg_type) == subscribers_factory.end()){
      throw std::runtime_error("unknown msg type passed to subscribers factory: " + msg_type);
    }

    subscribers_factory.at(msg_type)();
  }

  

  extern "C" void add_publisher_impl(
    std::shared_ptr<performance_test::Node> n,
    std::string msg_type,
    std::string topic_name,
    msg_pass_by_t msg_pass_by,
    rmw_qos_profile_t custom_qos_profile,
    std::chrono::microseconds period,
    size_t msg_size)
  {
    const std::map<std::string, std::function<void()>> publishers_factory{
  
{"stamped_int64",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::StampedInt64>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped3_float32",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped3Float32>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped4_float32",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped4Float32>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped4_int32",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped4Int32>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped9_float32",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped9Float32>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped12_float32",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped12Float32>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped10b",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped10b>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped100b",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped100b>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped250b",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped250b>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped1kb",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped1kb>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped10kb",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped10kb>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped100kb",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped100kb>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped250kb",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped250kb>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped600kb",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped600kb>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped1mb",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped1mb>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped4mb",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped4mb>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped8mb",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::Stamped8mb>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } },
{"stamped_vector",  [&] { n->add_periodic_publisher(performance_test::Topic<irobot_interfaces_plugin::msg::StampedVector>(topic_name), period, msg_pass_by, custom_qos_profile, msg_size); } }
    };

    if (publishers_factory.find(msg_type) == publishers_factory.end()){
      throw std::runtime_error("unknown msg type passed to publishers factory: " + msg_type);
    }

    publishers_factory.at(msg_type)();
  }

  

  extern "C" void add_server_impl(
    std::shared_ptr<performance_test::Node> n,
    std::string srv_type,
    std::string service_name,
    rmw_qos_profile_t custom_qos_profile)
  {
    const std::map<std::string, std::function<void()>> servers_factory{
  
{"stamped10b",  [&] { n->add_server(performance_test::Service<irobot_interfaces_plugin::srv::Stamped10b>(service_name), custom_qos_profile); } }
    };

    if (servers_factory.find(srv_type) == servers_factory.end()){
      throw std::runtime_error("unknown srv type passed to servers factory: " + srv_type);
    }

    servers_factory.at(srv_type)();
  }

  

  extern "C" void add_client_impl(
    std::shared_ptr<performance_test::Node> n,
    std::string srv_type,
    std::string service_name,
    rmw_qos_profile_t custom_qos_profile,
    std::chrono::microseconds period)
  {
    const std::map<std::string, std::function<void()>> clients_factory{
  
{"stamped10b",  [&] { n->add_periodic_client(performance_test::Service<irobot_interfaces_plugin::srv::Stamped10b>(service_name), period, custom_qos_profile); } }
    };
    if (clients_factory.find(srv_type) == clients_factory.end()){
      throw std::runtime_error("unknown srv type passed to clients factory: " + srv_type);
    }

    clients_factory.at(srv_type)();
}
