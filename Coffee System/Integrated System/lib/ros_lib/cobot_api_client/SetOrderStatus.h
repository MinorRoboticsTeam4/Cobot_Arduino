#ifndef _ROS_SERVICE_SetOrderStatus_h
#define _ROS_SERVICE_SetOrderStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cobot_api_client
{

static const char SETORDERSTATUS[] = "cobot_api_client/SetOrderStatus";

  class SetOrderStatusRequest : public ros::Msg
  {
    public:
      int32_t delivery_status;

    SetOrderStatusRequest():
      delivery_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_delivery_status;
      u_delivery_status.real = this->delivery_status;
      *(outbuffer + offset + 0) = (u_delivery_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delivery_status.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delivery_status.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delivery_status.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delivery_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_delivery_status;
      u_delivery_status.base = 0;
      u_delivery_status.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delivery_status.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delivery_status.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delivery_status.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delivery_status = u_delivery_status.real;
      offset += sizeof(this->delivery_status);
     return offset;
    }

    const char * getType(){ return SETORDERSTATUS; };
    const char * getMD5(){ return "02e5a53095440a4e9c18d8c77a72cdf9"; };

  };

  class SetOrderStatusResponse : public ros::Msg
  {
    public:
      int32_t http_response_code;
      const char* error_message;

    SetOrderStatusResponse():
      http_response_code(0),
      error_message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_http_response_code;
      u_http_response_code.real = this->http_response_code;
      *(outbuffer + offset + 0) = (u_http_response_code.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_http_response_code.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_http_response_code.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_http_response_code.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->http_response_code);
      uint32_t length_error_message = strlen(this->error_message);
      memcpy(outbuffer + offset, &length_error_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_message, length_error_message);
      offset += length_error_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_http_response_code;
      u_http_response_code.base = 0;
      u_http_response_code.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_http_response_code.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_http_response_code.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_http_response_code.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->http_response_code = u_http_response_code.real;
      offset += sizeof(this->http_response_code);
      uint32_t length_error_message;
      memcpy(&length_error_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_message-1]=0;
      this->error_message = (char *)(inbuffer + offset-1);
      offset += length_error_message;
     return offset;
    }

    const char * getType(){ return SETORDERSTATUS; };
    const char * getMD5(){ return "97c0975a23a6f80153a0745ef92b5a46"; };

  };

  class SetOrderStatus {
    public:
    typedef SetOrderStatusRequest Request;
    typedef SetOrderStatusResponse Response;
  };

}
#endif
