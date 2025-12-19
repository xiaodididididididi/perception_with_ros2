#ifndef LOCAL_TRAJECTORY_COMBINER_H_
#define LOCAL_TRAJECTORY_COMBINER_H_

#include "rclcpp/rclcpp.hpp"
#include "base_msgs_per/msg/local_path.hpp"
#include "base_msgs_per/msg/local_speeds.hpp"
#include "base_msgs_per/msg/local_trajectory.hpp"
#include "base_msgs_per/msg/local_trajectory_point.hpp"
#include "config_reader.h"

namespace Perception
{
    using base_msgs_per::msg::LocalPath;
    using base_msgs_per::msg::LocalSpeeds;
    using base_msgs_per::msg::LocalTrajectory;
    using base_msgs_per::msg::LocalTrajectoryPoint;

    class LocalTrajectoryCombiner
    {
    public:
        LocalTrajectoryCombiner();
        LocalTrajectory combin_trajectory(const LocalPath &path, const LocalSpeeds &speeds);
        inline LocalTrajectory local_trajectory() const { return local_trajector_; }

    private:
        std::unique_ptr<ConfigReader> trajectory_config_;
        LocalTrajectory local_trajector_;
    };
}

#endif