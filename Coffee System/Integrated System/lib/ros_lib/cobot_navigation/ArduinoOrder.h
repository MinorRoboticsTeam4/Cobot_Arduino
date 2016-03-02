#ifndef _ROS_cobot_navigation_ArduinoOrder_h
#define _ROS_cobot_navigation_ArduinoOrder_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cobot_navigation
{

  class ArduinoOrder : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t orderId;
      int32_t orderAmount;
      int32_t coffeeTypes[8];
      int32_t nfcID[8];
      bool isMug[8];

    ArduinoOrder():
      header(),
      orderId(0),
      orderAmount(0),
      coffeeTypes(),
      nfcID(),
      isMug()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_orderId;
      u_orderId.real = this->orderId;
      *(outbuffer + offset + 0) = (u_orderId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_orderId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_orderId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_orderId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orderId);
      union {
        int32_t real;
        uint32_t base;
      } u_orderAmount;
      u_orderAmount.real = this->orderAmount;
      *(outbuffer + offset + 0) = (u_orderAmount.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_orderAmount.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_orderAmount.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_orderAmount.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orderAmount);
      for( uint8_t i = 0; i < 8; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_coffeeTypesi;
      u_coffeeTypesi.real = this->coffeeTypes[i];
      *(outbuffer + offset + 0) = (u_coffeeTypesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coffeeTypesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coffeeTypesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coffeeTypesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coffeeTypes[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_nfcIDi;
      u_nfcIDi.real = this->nfcID[i];
      *(outbuffer + offset + 0) = (u_nfcIDi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nfcIDi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nfcIDi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nfcIDi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nfcID[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        bool real;
        uint8_t base;
      } u_isMugi;
      u_isMugi.real = this->isMug[i];
      *(outbuffer + offset + 0) = (u_isMugi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isMug[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_orderId;
      u_orderId.base = 0;
      u_orderId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_orderId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_orderId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_orderId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->orderId = u_orderId.real;
      offset += sizeof(this->orderId);
      union {
        int32_t real;
        uint32_t base;
      } u_orderAmount;
      u_orderAmount.base = 0;
      u_orderAmount.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_orderAmount.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_orderAmount.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_orderAmount.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->orderAmount = u_orderAmount.real;
      offset += sizeof(this->orderAmount);
      for( uint8_t i = 0; i < 8; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_coffeeTypesi;
      u_coffeeTypesi.base = 0;
      u_coffeeTypesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_coffeeTypesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_coffeeTypesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_coffeeTypesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->coffeeTypes[i] = u_coffeeTypesi.real;
      offset += sizeof(this->coffeeTypes[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_nfcIDi;
      u_nfcIDi.base = 0;
      u_nfcIDi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nfcIDi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nfcIDi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nfcIDi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nfcID[i] = u_nfcIDi.real;
      offset += sizeof(this->nfcID[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        bool real;
        uint8_t base;
      } u_isMugi;
      u_isMugi.base = 0;
      u_isMugi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isMug[i] = u_isMugi.real;
      offset += sizeof(this->isMug[i]);
      }
     return offset;
    }

    const char * getType(){ return "cobot_navigation/ArduinoOrder"; };
    const char * getMD5(){ return "9de48de854162b929daf3d28595d7d75"; };

  };

}
#endif