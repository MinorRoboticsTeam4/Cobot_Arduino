#ifndef _ROS_SERVICE_OrderWithProducts_h
#define _ROS_SERVICE_OrderWithProducts_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cobot_api_client
{

static const char ORDERWITHPRODUCTS[] = "cobot_api_client/OrderWithProducts";

  class OrderWithProductsRequest : public ros::Msg
  {
    public:
      bool request;

    OrderWithProductsRequest():
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

    const char * getType(){ return ORDERWITHPRODUCTS; };
    const char * getMD5(){ return "6f7e5ad6ab0ddf42c5727a195315a470"; };

  };

  class OrderWithProductsResponse : public ros::Msg
  {
    public:
      int32_t order_id;
      int32_t user_id;
      int32_t delivery_status;
      int64_t delivered_at;
      int32_t location_id;
      const char* location_name;
      float coordinate_x;
      float coordinate_y;
      float coordinate_z;
      float orientation_x;
      float orientation_y;
      float orientation_z;
      int32_t coffee_size;
      int32_t coffee_type[8];
      bool coffee_mug[8];
      int32_t http_response_code;
      const char* error_message;

    OrderWithProductsResponse():
      order_id(0),
      user_id(0),
      delivery_status(0),
      delivered_at(0),
      location_id(0),
      location_name(""),
      coordinate_x(0),
      coordinate_y(0),
      coordinate_z(0),
      orientation_x(0),
      orientation_y(0),
      orientation_z(0),
      coffee_size(0),
      coffee_type(),
      coffee_mug(),
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
      } u_order_id;
      u_order_id.real = this->order_id;
      *(outbuffer + offset + 0) = (u_order_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_order_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_order_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_order_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->order_id);
      union {
        int32_t real;
        uint32_t base;
      } u_user_id;
      u_user_id.real = this->user_id;
      *(outbuffer + offset + 0) = (u_user_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_user_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_user_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_user_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->user_id);
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
      union {
        int64_t real;
        uint64_t base;
      } u_delivered_at;
      u_delivered_at.real = this->delivered_at;
      *(outbuffer + offset + 0) = (u_delivered_at.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delivered_at.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delivered_at.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delivered_at.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_delivered_at.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_delivered_at.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_delivered_at.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_delivered_at.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->delivered_at);
      union {
        int32_t real;
        uint32_t base;
      } u_location_id;
      u_location_id.real = this->location_id;
      *(outbuffer + offset + 0) = (u_location_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_location_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_location_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_location_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->location_id);
      uint32_t length_location_name = strlen(this->location_name);
      memcpy(outbuffer + offset, &length_location_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->location_name, length_location_name);
      offset += length_location_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->coordinate_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->coordinate_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->coordinate_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_z);
      union {
        int32_t real;
        uint32_t base;
      } u_coffee_size;
      u_coffee_size.real = this->coffee_size;
      *(outbuffer + offset + 0) = (u_coffee_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coffee_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coffee_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coffee_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coffee_size);
      for( uint8_t i = 0; i < 8; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_coffee_typei;
      u_coffee_typei.real = this->coffee_type[i];
      *(outbuffer + offset + 0) = (u_coffee_typei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coffee_typei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coffee_typei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coffee_typei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coffee_type[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        bool real;
        uint8_t base;
      } u_coffee_mugi;
      u_coffee_mugi.real = this->coffee_mug[i];
      *(outbuffer + offset + 0) = (u_coffee_mugi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->coffee_mug[i]);
      }
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
      } u_order_id;
      u_order_id.base = 0;
      u_order_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_order_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_order_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_order_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->order_id = u_order_id.real;
      offset += sizeof(this->order_id);
      union {
        int32_t real;
        uint32_t base;
      } u_user_id;
      u_user_id.base = 0;
      u_user_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_user_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_user_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_user_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->user_id = u_user_id.real;
      offset += sizeof(this->user_id);
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
      union {
        int64_t real;
        uint64_t base;
      } u_delivered_at;
      u_delivered_at.base = 0;
      u_delivered_at.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delivered_at.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delivered_at.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delivered_at.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_delivered_at.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_delivered_at.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_delivered_at.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_delivered_at.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->delivered_at = u_delivered_at.real;
      offset += sizeof(this->delivered_at);
      union {
        int32_t real;
        uint32_t base;
      } u_location_id;
      u_location_id.base = 0;
      u_location_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_location_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_location_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_location_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->location_id = u_location_id.real;
      offset += sizeof(this->location_id);
      uint32_t length_location_name;
      memcpy(&length_location_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_location_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_location_name-1]=0;
      this->location_name = (char *)(inbuffer + offset-1);
      offset += length_location_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->coordinate_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->coordinate_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->coordinate_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_z));
      union {
        int32_t real;
        uint32_t base;
      } u_coffee_size;
      u_coffee_size.base = 0;
      u_coffee_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_coffee_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_coffee_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_coffee_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->coffee_size = u_coffee_size.real;
      offset += sizeof(this->coffee_size);
      for( uint8_t i = 0; i < 8; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_coffee_typei;
      u_coffee_typei.base = 0;
      u_coffee_typei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_coffee_typei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_coffee_typei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_coffee_typei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->coffee_type[i] = u_coffee_typei.real;
      offset += sizeof(this->coffee_type[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        bool real;
        uint8_t base;
      } u_coffee_mugi;
      u_coffee_mugi.base = 0;
      u_coffee_mugi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->coffee_mug[i] = u_coffee_mugi.real;
      offset += sizeof(this->coffee_mug[i]);
      }
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

    const char * getType(){ return ORDERWITHPRODUCTS; };
    const char * getMD5(){ return "003da5773d18299482c8424946a37967"; };

  };

  class OrderWithProducts {
    public:
    typedef OrderWithProductsRequest Request;
    typedef OrderWithProductsResponse Response;
  };

}
#endif
