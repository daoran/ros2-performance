/* Software License Agreement (BSD License)
 *
 *  Copyright (c) 2020, iRobot ROS
 *  All rights reserved.
 *
 *  This file is part of ros2-performance, which is released under BSD-3-Clause.
 *  You may use, distribute and modify this code under the BSD-3-Clause license.
 */

#pragma once

using namespace std::chrono_literals;

namespace performance_test {

/// Generic timer. Periodically executes a user-specified callback.
template<typename FunctorT>
class WallTimer
{
public:
  WallTimer(
    std::chrono::microseconds period,
    FunctorT && callback): period_(period)
  {
    callbacks_.push_back(callback);
  }

  void
  execute_callbacks()
  {
    for (const auto& callback : callbacks_){
      callback();
    }
  }

  void start()
  {
    std::thread([this]()
    {
      while(rclcpp::ok())
      {
        auto wake_up_time = std::chrono::steady_clock::now() + period_;
        execute_callbacks();
        std::this_thread::sleep_until(wake_up_time);
      }
    }).detach();
  }

  void
  add_callback(FunctorT callback)
  {
    callbacks_.push_back(callback);
  }

protected:
  WallTimer(const WallTimer &) = delete;
  WallTimer & operator=(const WallTimer &) = delete;

  std::chrono::microseconds period_;
  std::vector<FunctorT> callbacks_;
};

} // namespace performance_test
