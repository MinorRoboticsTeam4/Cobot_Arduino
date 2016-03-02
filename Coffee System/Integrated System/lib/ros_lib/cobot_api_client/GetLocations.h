#ifndef _ROS_SERVICE_GetLocations_h
#define _ROS_SERVICE_GetLocations_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cobot_api_client
{

static const char GETLOCATIONS[] = "cobot_api_client/GetLocations";

  class GetLocationsRequest : public ros::Msg
  {
    public:
      bool request;

    GetLocationsRequest():
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

    const char * getType(){ return GETLOCATIONS; };
    const char * getMD5(){ return "6f7e5ad6ab0ddf42c5727a195315a470"; };

  };

  class GetLocationsResponse : public ros::Msg
  {
    public:
      int32_t location_count;
      int32_t location_id[128];
      char* location_name[128];
      float coordinate_x[128];
      float coordinate_y[128];
      float coordinate_z[128];
      float orientation_x[128];
      float orientation_y[128];
      float orientation_z[128];
      int32_t http_response_code;
      const char* error_message;

    GetLocationsResponse():
      location_count(0),
      location_id(),
      location_name(),
      coordinate_x(),
      coordinate_y(),
      coordinate_z(),
      orientation_x(),
      orientation_y(),
      orientation_z(),
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
      } u_location_count;
      u_location_count.real = this->location_count;
      *(outbuffer + offset + 0) = (u_location_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_location_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_location_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_location_count.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->location_count);
      for( uint8_t i = 0; i < 128; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_location_idi;
      u_location_idi.real = this->location_id[i];
      *(outbuffer + offset + 0) = (u_location_idi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_location_idi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_location_idi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_location_idi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->location_id[i]);
      }
      for( uint8_t i = 0; i < 128; i++){
      uint32_t length_location_namei = strlen(this->location_name[i]);
      memcpy(outbuffer + offset, &length_location_namei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->location_name[i], length_location_namei);
      offset += length_location_namei;
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coordinate_x[i]);
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coordinate_y[i]);
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coordinate_z[i]);
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_x[i]);
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_y[i]);
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_z[i]);
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
      } u_location_count;
      u_location_count.base = 0;
      u_location_count.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_location_count.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_location_count.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_location_count.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->location_count = u_location_count.real;
      offset += sizeof(this->location_count);
      for( uint8_t i = 0; i < 128; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_location_idi;
      u_location_idi.base = 0;
      u_location_idi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_location_idi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_location_idi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_location_idi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->location_id[i] = u_location_idi.real;
      offset += sizeof(this->location_id[i]);
      }
      for( uint8_t i = 0; i < 128; i++){
      uint32_t length_location_namei;
      memcpy(&length_location_namei, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_location_namei; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_location_namei-1]=0;
      this->location_name[i] = (char *)(inbuffer + offset-1);
      offset += length_location_namei;
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->coordinate_x[i]));
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->coordinate_y[i]));
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->coordinate_z[i]));
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_x[i]));
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_y[i]));
      }
      for( uint8_t i = 0; i < 128; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_z[i]));
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

    const char * getType(){ return GETLOCATIONS; };
    const char * getMD5(){ return "7c7be4cd383ffa7986a145623564d4cf"; };

  };

  class GetLocations {
    public:
    typedef GetLocationsRequest Request;
    typedef GetLocationsResponse Response;
  };

}
#endif
