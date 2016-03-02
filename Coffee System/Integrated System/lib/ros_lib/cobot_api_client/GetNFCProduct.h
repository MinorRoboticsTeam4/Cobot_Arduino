#ifndef _ROS_SERVICE_GetNFCProduct_h
#define _ROS_SERVICE_GetNFCProduct_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cobot_api_client
{

static const char GETNFCPRODUCT[] = "cobot_api_client/GetNFCProduct";

  class GetNFCProductRequest : public ros::Msg
  {
    public:
      const char* nfc_id;

    GetNFCProductRequest():
      nfc_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_nfc_id = strlen(this->nfc_id);
      memcpy(outbuffer + offset, &length_nfc_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->nfc_id, length_nfc_id);
      offset += length_nfc_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_nfc_id;
      memcpy(&length_nfc_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_nfc_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_nfc_id-1]=0;
      this->nfc_id = (char *)(inbuffer + offset-1);
      offset += length_nfc_id;
     return offset;
    }

    const char * getType(){ return GETNFCPRODUCT; };
    const char * getMD5(){ return "960a7fe0949c8ed591d2cee3e069230b"; };

  };

  class GetNFCProductResponse : public ros::Msg
  {
    public:
      int32_t coffee_type;
      int32_t http_response_code;
      const char* error_message;

    GetNFCProductResponse():
      coffee_type(0),
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
      } u_coffee_type;
      u_coffee_type.real = this->coffee_type;
      *(outbuffer + offset + 0) = (u_coffee_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coffee_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coffee_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coffee_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coffee_type);
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
      } u_coffee_type;
      u_coffee_type.base = 0;
      u_coffee_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_coffee_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_coffee_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_coffee_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->coffee_type = u_coffee_type.real;
      offset += sizeof(this->coffee_type);
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

    const char * getType(){ return GETNFCPRODUCT; };
    const char * getMD5(){ return "41bc7dbc980d17993ba1a762ec1cbaff"; };

  };

  class GetNFCProduct {
    public:
    typedef GetNFCProductRequest Request;
    typedef GetNFCProductResponse Response;
  };

}
#endif
