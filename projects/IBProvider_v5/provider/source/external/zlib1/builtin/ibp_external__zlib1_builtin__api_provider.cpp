////////////////////////////////////////////////////////////////////////////////
//ZLib1 API Provider for builtin implementation.
//                                                 Dmitry Kovalenko. 19.01.2019.
#include <_pch_.h>
#pragma hdrstop

#include "source/external//zlib1/builtin/ibp_external__zlib1_builtin__api_provider.h"
#include "source/external//zlib1/builtin/set01/ibp_external__zlib1_set01__zlib.h"

namespace lcpi{namespace ibp{namespace external{namespace zlib1{namespace builtin{
////////////////////////////////////////////////////////////////////////////////
//class ZLIB1_BUILTIN__ApiProvider

ZLIB1_BUILTIN__ApiProvider
 ZLIB1_BUILTIN__ApiProvider::sm_Instance;

//------------------------------------------------------------------------
ZLIB1_BUILTIN__ApiProvider::ZLIB1_BUILTIN__ApiProvider()
{
}//ZLIB1_BUILTIN__ApiProvider

//------------------------------------------------------------------------
ZLIB1_BUILTIN__ApiProvider::~ZLIB1_BUILTIN__ApiProvider()
{
}//~ZLIB1_BUILTIN__ApiProvider

//------------------------------------------------------------------------
ZLIB1__ApiProviderPtr ZLIB1_BUILTIN__ApiProvider::create()
{
 return lib::structure::not_null_ptr(&sm_Instance);
}//create

//ZLIB1__ApiProvider interface -------------------------------------------
int ZLIB1_BUILTIN__ApiProvider::zapi__deflateInit
              (api::z_stream* const strm,
               int            const level)
{
 assert(strm);

 return set01::deflateInit_
          (reinterpret_cast<set01::z_stream*>(strm),
           level,
           api::ZLIB_VERSION,
           sizeof(*strm));
}//zapi__deflateInit

//------------------------------------------------------------------------
int ZLIB1_BUILTIN__ApiProvider::zapi__deflate
              (api::z_stream* const strm,
               int            const flush)
{
 assert(strm);

 return set01::deflate
          (reinterpret_cast<set01::z_stream*>(strm),
           flush);
}//zapi__deflate

//------------------------------------------------------------------------
int ZLIB1_BUILTIN__ApiProvider::zapi__deflateEnd
              (api::z_stream* const strm)
{
 assert(strm);

 return set01::deflateEnd
          (reinterpret_cast<set01::z_stream*>(strm));
}//zapi__deflateEnd

//------------------------------------------------------------------------
int ZLIB1_BUILTIN__ApiProvider::zapi__inflateInit
              (api::z_stream* const strm)
{
 assert(strm);

 return set01::inflateInit_
          (reinterpret_cast<set01::z_stream*>(strm),
           api::ZLIB_VERSION,
           sizeof(*strm));
}//zapi__inflateInit

//------------------------------------------------------------------------
int ZLIB1_BUILTIN__ApiProvider::zapi__inflate
              (api::z_stream* const strm,
               int            const flush)
{
 assert(strm);

 return set01::inflate
          (reinterpret_cast<set01::z_stream*>(strm),
           flush);
}//zapi__inflate

//------------------------------------------------------------------------
int ZLIB1_BUILTIN__ApiProvider::zapi__inflateEnd
              (api::z_stream* const strm)
{
 assert(strm);

 return set01::inflateEnd
          (reinterpret_cast<set01::z_stream*>(strm));
}//zapi__inflateEnd

////////////////////////////////////////////////////////////////////////////////
}/*nms builtin*/}/*nms zlib1*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
