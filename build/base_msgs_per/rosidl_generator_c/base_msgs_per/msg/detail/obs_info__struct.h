// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from base_msgs_per:msg/ObsInfo.idl
// generated code does not contain a copyright notice

#ifndef BASE_MSGS_PER__MSG__DETAIL__OBS_INFO__STRUCT_H_
#define BASE_MSGS_PER__MSG__DETAIL__OBS_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ObsInfo in the package base_msgs_per.
/**
  * 障碍物
 */
typedef struct base_msgs_per__msg__ObsInfo
{
  /// 长
  double obs_length;
  /// 宽
  double obs_width;
  /// 参考线投影的l
  double l;
  /// 参考线投影的s
  double s;
  /// 路径投影的s
  double s_2path;
  /// 路径投影的速度(就是笛卡尔坐标下的速度)
  double ds_dt_2path;
  /// 进入路径时间
  double t_in;
  /// 退出路径时间
  double t_out;
} base_msgs_per__msg__ObsInfo;

// Struct for a sequence of base_msgs_per__msg__ObsInfo.
typedef struct base_msgs_per__msg__ObsInfo__Sequence
{
  base_msgs_per__msg__ObsInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} base_msgs_per__msg__ObsInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BASE_MSGS_PER__MSG__DETAIL__OBS_INFO__STRUCT_H_
