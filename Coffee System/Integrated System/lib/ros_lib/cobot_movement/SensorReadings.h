#ifndef _ROS_cobot_movement_SensorReadings_h
#define _ROS_cobot_movement_SensorReadings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cobot_movement
{

  class SensorReadings : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float distance;
      float angle;
      uint16_t charge;
      uint16_t capacity;
      int32_t cups;
      int32_t consumptions;
      float ultrasoonReadings[5];
      bool switches[2];

    SensorReadings():
      header(),
      distance(0),
      angle(0),
      charge(0),
      capacity(0),
      cups(0),
      consumptions(0),
      ultrasoonReadings(),
      switches()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->angle);
      *(outbuffer + offset + 0) = (this->charge >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->charge >> (8 * 1)) & 0xFF;
      offset += sizeof(this->charge);
      *(outbuffer + offset + 0) = (this->capacity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->capacity >> (8 * 1)) & 0xFF;
      offset += sizeof(this->capacity);
      union {
        int32_t real;
        uint32_t base;
      } u_cups;
      u_cups.real = this->cups;
      *(outbuffer + offset + 0) = (u_cups.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cups.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cups.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cups.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cups);
      union {
        int32_t real;
        uint32_t base;
      } u_consumptions;
      u_consumptions.real = this->consumptions;
      *(outbuffer + offset + 0) = (u_consumptions.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_consumptions.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_consumptions.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_consumptions.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->consumptions);
      for( uint8_t i = 0; i < 5; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->ultrasoonReadings[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        bool real;
        uint8_t base;
      } u_switchesi;
      u_switchesi.real = this->switches[i];
      *(outbuffer + offset + 0) = (u_switchesi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->switches[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle));
      this->charge =  ((uint16_t) (*(inbuffer + offset)));
      this->charge |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->charge);
      this->capacity =  ((uint16_t) (*(inbuffer + offset)));
      this->capacity |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->capacity);
      union {
        int32_t real;
        uint32_t base;
      } u_cups;
      u_cups.base = 0;
      u_cups.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cups.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cups.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cups.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cups = u_cups.real;
      offset += sizeof(this->cups);
      union {
        int32_t real;
        uint32_t base;
      } u_consumptions;
      u_consumptions.base = 0;
      u_consumptions.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_consumptions.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_consumptions.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_consumptions.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->consumptions = u_consumptions.real;
      offset += sizeof(this->consumptions);
      for( uint8_t i = 0; i < 5; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ultrasoonReadings[i]));
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        bool real;
        uint8_t base;
      } u_switchesi;
      u_switchesi.base = 0;
      u_switchesi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->switches[i] = u_switchesi.real;
      offset += sizeof(this->switches[i]);
      }
     return offset;
    }

    const char * getType(){ return "cobot_movement/SensorReadings"; };
    const char * getMD5(){ return "e3dbb4e9448b5e4616a6336edd9095c3"; };

  };

}
#endif