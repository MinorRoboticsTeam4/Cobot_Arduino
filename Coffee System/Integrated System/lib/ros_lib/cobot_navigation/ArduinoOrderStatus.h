#ifndef _ROS_cobot_navigation_ArduinoOrderStatus_h
#define _ROS_cobot_navigation_ArduinoOrderStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cobot_navigation
{

  class ArduinoOrderStatus : public ros::Msg
  {
    public:
      std_msgs::Header header;
      bool isCompleted;

    ArduinoOrderStatus():
      header(),
      isCompleted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isCompleted;
      u_isCompleted.real = this->isCompleted;
      *(outbuffer + offset + 0) = (u_isCompleted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isCompleted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isCompleted;
      u_isCompleted.base = 0;
      u_isCompleted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isCompleted = u_isCompleted.real;
      offset += sizeof(this->isCompleted);
     return offset;
    }

    const char * getType(){ return "cobot_navigation/ArduinoOrderStatus"; };
    const char * getMD5(){ return "11d03ad78156971d476fd1f645611346"; };

  };

}
#endif