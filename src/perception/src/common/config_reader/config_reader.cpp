#include "config_reader.h"

namespace Perception
{
    ConfigReader::ConfigReader()
    {
        std::string perception_share_directory = ament_index_cpp::get_package_share_directory("perception");
        perception_config = YAML::LoadFile(perception_share_directory + "/config/perception_static_obs_config.yaml");
        // perception_config = YAML::LoadFile(perception_share_directory + "/config/perception_dynamic_obs_config.yaml");
    }

    void ConfigReader::read_vehicle_config(VehicleStruct &vehicle, const std::string &name)
    {
        vehicle.id_ = perception_config["vehicle"][name]["id"].as<int>();
        vehicle.frame_ = perception_config["vehicle"][name]["frame"].as<std::string>();
        vehicle.length_ = perception_config["vehicle"][name]["length"].as<double>();
        vehicle.width_ = perception_config["vehicle"][name]["width"].as<double>();
        vehicle.pose_x_ = perception_config["vehicle"][name]["pose_x"].as<double>();
        vehicle.pose_y_ = perception_config["vehicle"][name]["pose_y"].as<double>();
        vehicle.pose_theta_ = perception_config["vehicle"][name]["pose_theta"].as<double>();
        vehicle.speed_ori_ = perception_config["vehicle"][name]["speed_ori"].as<double>();
        if (name != "main_car")
        {
            obs_pair_.emplace(vehicle.id_, vehicle);
        }
    }

    void ConfigReader::read_vehicles_config()
    {
        try
        {
            read_pnc_map_config();
            read_vehicle_config(main_car_, "main_car");
            read_vehicle_config(obs_car1_, "obs_car1");
            read_vehicle_config(obs_car2_, "obs_car2");
            read_vehicle_config(obs_car3_, "obs_car3");
            read_vehicle_config(obs_car4_, "obs_car4");
            read_vehicle_config(obs_car5_, "obs_car5");
            read_vehicle_config(obs_car6_, "obs_car6");
        }
        catch (const YAML::Exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("config"), "Failed to load vehicles config: %s", e.what());
        }
    }

    void ConfigReader::read_pnc_map_config()
    {
        try
        {
            pnc_map_.frame_ = perception_config["pnc_map"]["frame"].as<std::string>();
            pnc_map_.type_ = perception_config["pnc_map"]["type"].as<int>();
            pnc_map_.road_length_ = perception_config["pnc_map"]["road_length"].as<double>();
            pnc_map_.road_half_width_ = perception_config["pnc_map"]["road_half_width"].as<double>();
            pnc_map_.segment_len_ = perception_config["pnc_map"]["segment_len"].as<double>();
            pnc_map_.speed_limit_ = perception_config["pnc_map"]["speed_limit"].as<double>();
        }
        catch (const YAML::Exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("config"), "Failed to load pnc_map config: %s", e.what());
        }
    }

    void ConfigReader::read_global_path_config()
    {
        try
        {
            global_path_.type_ = perception_config["global_path"]["type"].as<int>();
        }
        catch (const YAML::Exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("config"), "Failed to load global_path config: %s", e.what());
        }
    }

    void ConfigReader::read_reference_line_config()
    {
        try
        {
            read_pnc_map_config();
            refer_line_.type_ = perception_config["reference_line"]["type"].as<int>();
            refer_line_.front_size_ = perception_config["reference_line"]["front_size"].as<int>();
            refer_line_.back_size_ = perception_config["reference_line"]["back_size"].as<int>();
        }
        catch (const YAML::Exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("config"), "Failed to load reference_line config: %s", e.what());
        }
    }

    void ConfigReader::read_local_path_config()
    {
        try
        {
            read_pnc_map_config();
            read_reference_line_config();
            local_path_.curve_type_ = perception_config["local_path"]["curve_type"].as<int>();
            local_path_.path_size_ = perception_config["local_path"]["path_size"].as<int>();
        }
        catch (const YAML::Exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("config"), "Failed to load local_path config: %s", e.what());
        }
    }

    void ConfigReader::read_local_speeds_config()
    {
        try
        {
            read_pnc_map_config();
            // read_vehicles_config();
            local_speeds_.speed_size_ = perception_config["local_speed"]["speed_size"].as<int>();
        }
        catch (const YAML::Exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("config"), "Failed to load local_speeds config: %s", e.what());
        }
    }

    void ConfigReader::read_decision_config()
    {
        try
        {
            read_pnc_map_config();
            read_reference_line_config();
            read_local_path_config();
            read_local_speeds_config();
            decision_.safe_dis_l_ = perception_config["decision"]["safe_dis_l"].as<double>();
            decision_.safe_dis_s_ = perception_config["decision"]["safe_dis_s"].as<double>();
        }
        catch (const YAML::Exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("config"), "Failed to load decision config: %s", e.what());
        }
    }

    void ConfigReader::read_perception_process_config()
    {
        try
        {
            read_pnc_map_config();
            read_global_path_config();
            read_vehicles_config();
            process_.obs_dis_ = perception_config["perception_process"]["obs_dis"].as<double>();
        }
        catch (const YAML::Exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("config"), "Failed to load perception_process config: %s", e.what());
        }
    }

    void ConfigReader::read_move_cmd_config()
    {
        try
        {
            read_pnc_map_config();
        }
        catch (const YAML::Exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("config"), "Failed to load move_cmd config: %s", e.what());
        }
    }
}