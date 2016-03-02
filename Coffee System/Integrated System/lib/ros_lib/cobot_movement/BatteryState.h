#ifndef _ROS_cobot_movement_BatteryState_h
#define _ROS_cobot_movement_BatteryState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cobot_movement
{

  class BatteryState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t charge;
      uint16_t capacity;

    BatteryState():
      header(),
      charge(0),
      capacity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->charge >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->charge >> (8 * 1)) & 0xFF;
      offset += sizeof(this->charge);
      *(outbuffer + offset + 0) = (this->capacity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->capacity >> (8 * 1)) & 0xFF;
      offset += sizeof(this->capacity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->charge =  ((uint16_t) (*(inbuffer + offset)));
      this->charge |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->charge);
      this->capacity =  ((uint16_t) (*(inbuffer + offset)));
      this->capacity |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->capacity);
     return offset;
    }

    const char * getType(){ return "cobot_movement/BatteryState"; };
    const char * getMD5(){ return "39765a77ef11ef7a354f625ffa441c06"; };

  };

}
#endif