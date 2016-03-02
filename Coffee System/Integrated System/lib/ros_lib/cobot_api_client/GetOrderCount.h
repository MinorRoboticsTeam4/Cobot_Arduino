#ifndef _ROS_SERVICE_GetOrderCount_h
#define _ROS_SERVICE_GetOrderCount_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cobot_api_client
{

static const char GETORDERCOUNT[] = "cobot_api_client/GetOrderCount";

  class GetOrderCountRequest : public ros::Msg
  {
    public:
      bool request;

    GetOrderCountRequest():
      request(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_request;
      u_request.real = this->request;
      *(outbuffer + offset + 0) = (u_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->request);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_request;
      u_request.base = 0;
      u_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->request = u_request.real;
      offset += sizeof(this->request);
     return offset;
    }

    const char * getType(){ return GETORDERCOUNT; };
    const char * getMD5(){ return "6f7e5ad6ab0ddf42c5727a195315a470"; };

  };

  class GetOrderCountResponse : public ros::Msg
  {
    public:
      int32_t order_count;
      int32_t http_response_code;
      const char* error_message;

    GetOrderCountResponse():
      order_count(0),
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
      } u_order_count;
      u_order_count.real = this->order_count;
      *(outbuffer + offset + 0) = (u_order_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_order_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_order_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_order_count.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->order_count);
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
      } u_order_count;
      u_order_count.base = 0;
      u_order_count.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_order_count.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_order_count.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_order_count.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->order_count = u_order_count.real;
      offset += sizeof(this->order_count);
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

    const char * getType(){ return GETORDERCOUNT; };
    const char * getMD5(){ return "5a6fb2b7795208ef063fd88a04d7a08b"; };

  };

  class GetOrderCount {
    public:
    typedef GetOrderCountRequest Request;
    typedef GetOrderCountResponse Response;
  };

}
#endif
