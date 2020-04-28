/* Software License Agreement (BSD License)
 *
 *  Copyright (c) 2019, iRobot ROS
 *  All rights reserved.
 *
 *  This file is part of ros2-performance, which is released under BSD-3-Clause.
 *  You may use, distribute and modify this code under the BSD-3-Clause license.
 */

#pragma once

#include <iomanip>
#include <vector>

#include "performance_test/ros2/node.hpp"
#include "performance_test/ros2/events_logger.hpp"
#include "performance_test/ros2/wall_timer.hpp"

namespace performance_test {

struct NamedExecutor
{
    rclcpp::executors::StaticSingleThreadedExecutor::SharedPtr executor;
    std::string name;
};


class System
{
public:

  System() = default;

  void add_node(std::vector<std::shared_ptr<Node>> nodes);

  void add_node(std::shared_ptr<Node> node);

  void create_timers();

  void spin(int duration_sec, bool wait_for_discovery = true);

  void enable_events_logger(std::string events_logger_path);

  void save_latency_all_stats(std::string filename) const;
  void save_latency_total_stats(std::string filename) const;

  void print_latency_all_stats() const;
  void print_latency_total_stats() const;
  void print_agregate_stats(std::vector<std::string> topology_json_list) const;

private:

  void wait_discovery();

  void wait_pdp_discovery(
    std::chrono::milliseconds period = std::chrono::milliseconds(20),
    std::chrono::milliseconds max_pdp_time = std::chrono::milliseconds(30 * 1000));

  void wait_edp_discovery(
    std::chrono::milliseconds period = std::chrono::milliseconds(20),
    std::chrono::milliseconds max_edp_time = std::chrono::milliseconds(30 * 1000));

  void log_latency_all_stats(std::ostream& stream) const;
  void log_latency_total_stats(std::ostream& stream) const;

  template<typename DurationRepT, typename DurationT, typename CallbackT>
  std::shared_ptr<WallTimer<CallbackT>>
  create_std_wall_timer(
    CallbackT callback,
    std::chrono::duration<DurationRepT, DurationT> period)
  {
    auto timer = std::make_shared<WallTimer<CallbackT>>(
      std::chrono::duration_cast<PeriodT>(period),
      std::move(callback)
      );
    return timer;
  }

  std::chrono::high_resolution_clock::time_point _start_time;

  int _experiment_duration_sec;

  std::vector<std::shared_ptr<Node>> _nodes;

  std::map<int, NamedExecutor> _executors_map;

  typedef std::function<void()> FunctorT;
  typedef std::shared_ptr<WallTimer<FunctorT>> WallTimerSharedPtr;
  typedef std::chrono::microseconds PeriodT;

  std::map<PeriodT, WallTimerSharedPtr> _timers_map;

  std::shared_ptr<EventsLogger> _events_logger;

  // the following values are used for comparing different plots using the python scripts
  bool _got_system_info;
  int _pubs;
  int _subs;
  float _frequency;
  size_t _msg_size;
};
}