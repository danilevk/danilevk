// Generated by gencpp from file ardrone_autonomy/Navdata.msg
// DO NOT EDIT!


#ifndef ARDRONE_AUTONOMY_MESSAGE_NAVDATA_H
#define ARDRONE_AUTONOMY_MESSAGE_NAVDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace ardrone_autonomy
{
template <class ContainerAllocator>
struct Navdata_
{
  typedef Navdata_<ContainerAllocator> Type;

  Navdata_()
    : header()
    , batteryPercent(0.0)
    , state(0)
    , magX(0)
    , magY(0)
    , magZ(0)
    , pressure(0)
    , temp(0)
    , wind_speed(0.0)
    , wind_angle(0.0)
    , wind_comp_angle(0.0)
    , rotX(0.0)
    , rotY(0.0)
    , rotZ(0.0)
    , altd(0)
    , vx(0.0)
    , vy(0.0)
    , vz(0.0)
    , ax(0.0)
    , ay(0.0)
    , az(0.0)
    , motor1(0)
    , motor2(0)
    , motor3(0)
    , motor4(0)
    , tags_count(0)
    , tags_type()
    , tags_xc()
    , tags_yc()
    , tags_width()
    , tags_height()
    , tags_orientation()
    , tags_distance()
    , tm(0.0)  {
    }
  Navdata_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , batteryPercent(0.0)
    , state(0)
    , magX(0)
    , magY(0)
    , magZ(0)
    , pressure(0)
    , temp(0)
    , wind_speed(0.0)
    , wind_angle(0.0)
    , wind_comp_angle(0.0)
    , rotX(0.0)
    , rotY(0.0)
    , rotZ(0.0)
    , altd(0)
    , vx(0.0)
    , vy(0.0)
    , vz(0.0)
    , ax(0.0)
    , ay(0.0)
    , az(0.0)
    , motor1(0)
    , motor2(0)
    , motor3(0)
    , motor4(0)
    , tags_count(0)
    , tags_type(_alloc)
    , tags_xc(_alloc)
    , tags_yc(_alloc)
    , tags_width(_alloc)
    , tags_height(_alloc)
    , tags_orientation(_alloc)
    , tags_distance(_alloc)
    , tm(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef float _batteryPercent_type;
  _batteryPercent_type batteryPercent;

   typedef uint32_t _state_type;
  _state_type state;

   typedef int32_t _magX_type;
  _magX_type magX;

   typedef int32_t _magY_type;
  _magY_type magY;

   typedef int32_t _magZ_type;
  _magZ_type magZ;

   typedef int32_t _pressure_type;
  _pressure_type pressure;

   typedef int32_t _temp_type;
  _temp_type temp;

   typedef float _wind_speed_type;
  _wind_speed_type wind_speed;

   typedef float _wind_angle_type;
  _wind_angle_type wind_angle;

   typedef float _wind_comp_angle_type;
  _wind_comp_angle_type wind_comp_angle;

   typedef float _rotX_type;
  _rotX_type rotX;

   typedef float _rotY_type;
  _rotY_type rotY;

   typedef float _rotZ_type;
  _rotZ_type rotZ;

   typedef int32_t _altd_type;
  _altd_type altd;

   typedef float _vx_type;
  _vx_type vx;

   typedef float _vy_type;
  _vy_type vy;

   typedef float _vz_type;
  _vz_type vz;

   typedef float _ax_type;
  _ax_type ax;

   typedef float _ay_type;
  _ay_type ay;

   typedef float _az_type;
  _az_type az;

   typedef uint8_t _motor1_type;
  _motor1_type motor1;

   typedef uint8_t _motor2_type;
  _motor2_type motor2;

   typedef uint8_t _motor3_type;
  _motor3_type motor3;

   typedef uint8_t _motor4_type;
  _motor4_type motor4;

   typedef uint32_t _tags_count_type;
  _tags_count_type tags_count;

   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _tags_type_type;
  _tags_type_type tags_type;

   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _tags_xc_type;
  _tags_xc_type tags_xc;

   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _tags_yc_type;
  _tags_yc_type tags_yc;

   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _tags_width_type;
  _tags_width_type tags_width;

   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _tags_height_type;
  _tags_height_type tags_height;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _tags_orientation_type;
  _tags_orientation_type tags_orientation;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _tags_distance_type;
  _tags_distance_type tags_distance;

   typedef float _tm_type;
  _tm_type tm;





  typedef boost::shared_ptr< ::ardrone_autonomy::Navdata_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ardrone_autonomy::Navdata_<ContainerAllocator> const> ConstPtr;

}; // struct Navdata_

typedef ::ardrone_autonomy::Navdata_<std::allocator<void> > Navdata;

typedef boost::shared_ptr< ::ardrone_autonomy::Navdata > NavdataPtr;
typedef boost::shared_ptr< ::ardrone_autonomy::Navdata const> NavdataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ardrone_autonomy::Navdata_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ardrone_autonomy::Navdata_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ardrone_autonomy

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'ardrone_autonomy': ['/home/daniellevkovits/catkin_ws/src/ardrone_autonomy/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_autonomy::Navdata_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_autonomy::Navdata_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_autonomy::Navdata_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_autonomy::Navdata_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_autonomy::Navdata_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_autonomy::Navdata_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ardrone_autonomy::Navdata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e1169f766234363125ac62c9a3f87eeb";
  }

  static const char* value(const ::ardrone_autonomy::Navdata_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe1169f7662343631ULL;
  static const uint64_t static_value2 = 0x25ac62c9a3f87eebULL;
};

template<class ContainerAllocator>
struct DataType< ::ardrone_autonomy::Navdata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ardrone_autonomy/Navdata";
  }

  static const char* value(const ::ardrone_autonomy::Navdata_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ardrone_autonomy::Navdata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
\n\
# Navdata including the ARDrone 2 specifica sensors\n\
# (magnetometer, barometer)\n\
\n\
# 0 means no battery, 100 means full battery\n\
float32 batteryPercent\n\
\n\
# 0: Unknown, 1: Init, 2: Landed, 3: Flying, 4: Hovering, 5: Test\n\
# 6: Taking off, 7: Goto Fix Point, 8: Landing, 9: Looping\n\
# Note: 3,7 seems to discriminate type of flying (isFly = 3 | 7)\n\
uint32 state\n\
\n\
int32 magX\n\
int32 magY\n\
int32 magZ\n\
\n\
# pressure sensor\n\
int32 pressure\n\
\n\
# apparently, there was a temperature sensor added as well.\n\
int32 temp\n\
\n\
# wind sensing...\n\
float32 wind_speed\n\
float32 wind_angle\n\
float32 wind_comp_angle\n\
\n\
# left/right tilt in degrees (rotation about the X axis)\n\
float32 rotX\n\
\n\
# forward/backward tilt in degrees (rotation about the Y axis)\n\
float32 rotY\n\
\n\
# orientation in degrees (rotation about the Z axis)\n\
float32 rotZ\n\
\n\
# estimated altitude (cm)\n\
int32 altd\n\
\n\
# linear velocity (mm/sec)\n\
float32 vx\n\
\n\
# linear velocity (mm/sec)\n\
float32 vy\n\
\n\
# linear velocity (mm/sec)\n\
float32 vz\n\
\n\
#linear accelerations (unit: g)\n\
float32 ax\n\
float32 ay\n\
float32 az\n\
\n\
#motor commands (unit 0 to 255)\n\
uint8 motor1\n\
uint8 motor2\n\
uint8 motor3\n\
uint8 motor4\n\
\n\
#Tags in Vision Detectoion\n\
uint32 tags_count\n\
uint32[] tags_type\n\
uint32[] tags_xc\n\
uint32[] tags_yc\n\
uint32[] tags_width\n\
uint32[] tags_height\n\
float32[] tags_orientation\n\
float32[] tags_distance\n\
\n\
#time stamp\n\
float32 tm\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::ardrone_autonomy::Navdata_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ardrone_autonomy::Navdata_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.batteryPercent);
      stream.next(m.state);
      stream.next(m.magX);
      stream.next(m.magY);
      stream.next(m.magZ);
      stream.next(m.pressure);
      stream.next(m.temp);
      stream.next(m.wind_speed);
      stream.next(m.wind_angle);
      stream.next(m.wind_comp_angle);
      stream.next(m.rotX);
      stream.next(m.rotY);
      stream.next(m.rotZ);
      stream.next(m.altd);
      stream.next(m.vx);
      stream.next(m.vy);
      stream.next(m.vz);
      stream.next(m.ax);
      stream.next(m.ay);
      stream.next(m.az);
      stream.next(m.motor1);
      stream.next(m.motor2);
      stream.next(m.motor3);
      stream.next(m.motor4);
      stream.next(m.tags_count);
      stream.next(m.tags_type);
      stream.next(m.tags_xc);
      stream.next(m.tags_yc);
      stream.next(m.tags_width);
      stream.next(m.tags_height);
      stream.next(m.tags_orientation);
      stream.next(m.tags_distance);
      stream.next(m.tm);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Navdata_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ardrone_autonomy::Navdata_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ardrone_autonomy::Navdata_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "batteryPercent: ";
    Printer<float>::stream(s, indent + "  ", v.batteryPercent);
    s << indent << "state: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.state);
    s << indent << "magX: ";
    Printer<int32_t>::stream(s, indent + "  ", v.magX);
    s << indent << "magY: ";
    Printer<int32_t>::stream(s, indent + "  ", v.magY);
    s << indent << "magZ: ";
    Printer<int32_t>::stream(s, indent + "  ", v.magZ);
    s << indent << "pressure: ";
    Printer<int32_t>::stream(s, indent + "  ", v.pressure);
    s << indent << "temp: ";
    Printer<int32_t>::stream(s, indent + "  ", v.temp);
    s << indent << "wind_speed: ";
    Printer<float>::stream(s, indent + "  ", v.wind_speed);
    s << indent << "wind_angle: ";
    Printer<float>::stream(s, indent + "  ", v.wind_angle);
    s << indent << "wind_comp_angle: ";
    Printer<float>::stream(s, indent + "  ", v.wind_comp_angle);
    s << indent << "rotX: ";
    Printer<float>::stream(s, indent + "  ", v.rotX);
    s << indent << "rotY: ";
    Printer<float>::stream(s, indent + "  ", v.rotY);
    s << indent << "rotZ: ";
    Printer<float>::stream(s, indent + "  ", v.rotZ);
    s << indent << "altd: ";
    Printer<int32_t>::stream(s, indent + "  ", v.altd);
    s << indent << "vx: ";
    Printer<float>::stream(s, indent + "  ", v.vx);
    s << indent << "vy: ";
    Printer<float>::stream(s, indent + "  ", v.vy);
    s << indent << "vz: ";
    Printer<float>::stream(s, indent + "  ", v.vz);
    s << indent << "ax: ";
    Printer<float>::stream(s, indent + "  ", v.ax);
    s << indent << "ay: ";
    Printer<float>::stream(s, indent + "  ", v.ay);
    s << indent << "az: ";
    Printer<float>::stream(s, indent + "  ", v.az);
    s << indent << "motor1: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motor1);
    s << indent << "motor2: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motor2);
    s << indent << "motor3: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motor3);
    s << indent << "motor4: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motor4);
    s << indent << "tags_count: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.tags_count);
    s << indent << "tags_type[]" << std::endl;
    for (size_t i = 0; i < v.tags_type.size(); ++i)
    {
      s << indent << "  tags_type[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.tags_type[i]);
    }
    s << indent << "tags_xc[]" << std::endl;
    for (size_t i = 0; i < v.tags_xc.size(); ++i)
    {
      s << indent << "  tags_xc[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.tags_xc[i]);
    }
    s << indent << "tags_yc[]" << std::endl;
    for (size_t i = 0; i < v.tags_yc.size(); ++i)
    {
      s << indent << "  tags_yc[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.tags_yc[i]);
    }
    s << indent << "tags_width[]" << std::endl;
    for (size_t i = 0; i < v.tags_width.size(); ++i)
    {
      s << indent << "  tags_width[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.tags_width[i]);
    }
    s << indent << "tags_height[]" << std::endl;
    for (size_t i = 0; i < v.tags_height.size(); ++i)
    {
      s << indent << "  tags_height[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.tags_height[i]);
    }
    s << indent << "tags_orientation[]" << std::endl;
    for (size_t i = 0; i < v.tags_orientation.size(); ++i)
    {
      s << indent << "  tags_orientation[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.tags_orientation[i]);
    }
    s << indent << "tags_distance[]" << std::endl;
    for (size_t i = 0; i < v.tags_distance.size(); ++i)
    {
      s << indent << "  tags_distance[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.tags_distance[i]);
    }
    s << indent << "tm: ";
    Printer<float>::stream(s, indent + "  ", v.tm);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARDRONE_AUTONOMY_MESSAGE_NAVDATA_H
