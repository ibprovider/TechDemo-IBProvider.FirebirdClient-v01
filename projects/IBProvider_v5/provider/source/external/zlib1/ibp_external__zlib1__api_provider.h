////////////////////////////////////////////////////////////////////////////////
//ZLib1 API.
//                                                 Dmitry Kovalenko. 06.01.2019.
#ifndef _ibp_external__zlib1__api_provider_H_
#define _ibp_external__zlib1__api_provider_H_

#include "source/external/zlib1/ibp_external__zlib1__api.h"
#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{namespace external{namespace zlib1{
////////////////////////////////////////////////////////////////////////////////
//class ZLIB1__ApiProvider

class COMP_CONF_DECLSPEC_NOVTABLE ZLIB1__ApiProvider:public IBP_SmartInterface
{
 public:
  virtual int zapi__deflateInit
                (api::z_stream* strm,
                 int            level)=0;

  virtual int zapi__deflate
                (api::z_stream* strm,
                 int       flush)=0;

  //NO THROW!
  virtual int zapi__deflateEnd
                 (api::z_stream* strm)=0;


  virtual int zapi__inflateInit
                (api::z_stream* strm)=0;

  virtual int zapi__inflate
                (api::z_stream* strm,
                 int       flush)=0;

  //NO THROW!
  virtual int zapi__inflateEnd
                (api::z_stream* strm)=0;
};//class ZLIB1__ApiProvider

////////////////////////////////////////////////////////////////////////////////

typedef lib::structure::t_smart_object_ptr<ZLIB1__ApiProvider> ZLIB1__ApiProviderPtr;

////////////////////////////////////////////////////////////////////////////////
}/*nms zlib1*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
#endif
