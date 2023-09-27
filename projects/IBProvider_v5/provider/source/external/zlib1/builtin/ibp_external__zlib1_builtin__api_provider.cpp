////////////////////////////////////////////////////////////////////////////////
//ZLib1 API Provider for builtin implementation.
//                                                 Dmitry Kovalenko. 19.01.2020.
#include <_pch_.h>
#pragma hdrstop

#include "source/external//zlib1/builtin/ibp_external__zlib1_builtin__api_provider.h"
#include "source/external//zlib1/builtin/v001_003_000/ibp_external__zlib1_builtin_v001_003_000__zlib.h"

namespace lcpi{namespace ibp{namespace external{namespace zlib1{namespace builtin{
////////////////////////////////////////////////////////////////////////////////

namespace builtin_impl=v001_003_000;

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

 assert_s(sizeof(api::z_stream)==sizeof(builtin_impl::z_stream));

 return builtin_impl::deflateInit_
          (reinterpret_cast<builtin_impl::z_stream*>(strm),
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

 return builtin_impl::deflate
          (reinterpret_cast<builtin_impl::z_stream*>(strm),
           flush);
}//zapi__deflate

//------------------------------------------------------------------------
int ZLIB1_BUILTIN__ApiProvider::zapi__deflateEnd
              (api::z_stream* const strm)
{
 assert(strm);

 return builtin_impl::deflateEnd
          (reinterpret_cast<builtin_impl::z_stream*>(strm));
}//zapi__deflateEnd

//------------------------------------------------------------------------
int ZLIB1_BUILTIN__ApiProvider::zapi__inflateInit
              (api::z_stream* const strm)
{
 assert(strm);

 assert_s(sizeof(api::z_stream)==sizeof(builtin_impl::z_stream));

 return builtin_impl::inflateInit_
          (reinterpret_cast<builtin_impl::z_stream*>(strm),
           api::ZLIB_VERSION,
           sizeof(*strm));
}//zapi__inflateInit

//------------------------------------------------------------------------
int ZLIB1_BUILTIN__ApiProvider::zapi__inflate
              (api::z_stream* const strm,
               int            const flush)
{
 assert(strm);

 return builtin_impl::inflate
          (reinterpret_cast<builtin_impl::z_stream*>(strm),
           flush);
}//zapi__inflate

//------------------------------------------------------------------------
int ZLIB1_BUILTIN__ApiProvider::zapi__inflateEnd
              (api::z_stream* const strm)
{
 assert(strm);

 return builtin_impl::inflateEnd
          (reinterpret_cast<builtin_impl::z_stream*>(strm));
}//zapi__inflateEnd

////////////////////////////////////////////////////////////////////////////////
}/*nms builtin*/}/*nms zlib1*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
