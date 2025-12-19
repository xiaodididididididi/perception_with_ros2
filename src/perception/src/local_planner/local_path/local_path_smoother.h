#ifndef LOCAL_PATH_SMOOTHER_H_
#define LOCAL_PATH_SMOOTHER_H_

#include "rclcpp/rclcpp.hpp"
#include "base_msgs_per/msg/local_path.hpp"
#include <cmath>
#include "config_reader.h"

namespace Perception
{
    using base_msgs_per::msg::LocalPath;

    class LocalPathSmoother
    {
    public:
        LocalPathSmoother();
        void smooth_local_path(LocalPath &path);

    private:
        std::unique_ptr<ConfigReader> local_path_config_;
    };
}

#endif