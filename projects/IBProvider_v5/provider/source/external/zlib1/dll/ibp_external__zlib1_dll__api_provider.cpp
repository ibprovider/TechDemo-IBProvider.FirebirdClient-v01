////////////////////////////////////////////////////////////////////////////////
//ZLib1 API Provider for external implementation.
//                                                 Dmitry Kovalenko. 06.01.2019.
#include <_pch_.h>
#pragma hdrstop

#include "source/external//zlib1/dll/ibp_external__zlib1_dll__api_provider.h"

namespace lcpi{namespace ibp{namespace external{namespace zlib1{namespace dll{
////////////////////////////////////////////////////////////////////////////////
//class ZLIB1_DLL__ApiProvider

#define INIT_ZLIB1_POINT(func_name)  \
 m_##func_name(pDLL,#func_name)

ZLIB1_DLL__ApiProvider::ZLIB1_DLL__ApiProvider(dll_type* const pDLL)
 :INIT_ZLIB1_POINT(deflateInit_)
 ,INIT_ZLIB1_POINT(deflate)
 ,INIT_ZLIB1_POINT(deflateEnd)
 ,INIT_ZLIB1_POINT(inflateInit_)
 ,INIT_ZLIB1_POINT(inflate)
 ,INIT_ZLIB1_POINT(inflateEnd)
 ,m_spDLL(lib::structure::not_null_ptr(pDLL))
{
 //! \todo
 //!  Реализировать форсированную инициализацию через конструктор

 m_deflateEnd.point();//throw
 m_inflateEnd.point();//throw

 assert(m_spDLL);
}//ZLIB1_DLL__ApiProvider

#undef INIT_ZLIB1_POINT

//------------------------------------------------------------------------
ZLIB1_DLL__ApiProvider::~ZLIB1_DLL__ApiProvider()
{
}//~ZLIB1_DLL__ApiProvider

//------------------------------------------------------------------------
ZLIB1__ApiProviderPtr ZLIB1_DLL__ApiProvider::create(dll_type* const pDLL)
{
 assert(pDLL);

 return lib::structure::not_null_ptr(new self_type(pDLL));
}//create

//ZLIB1__ApiProvider interface -------------------------------------------
int ZLIB1_DLL__ApiProvider::zapi__deflateInit
              (api::z_stream* const strm,
               int            const level)
{
 assert(strm);

 return m_deflateInit_.point()
          (strm,
           level,
           api::ZLIB_VERSION,
           sizeof(*strm));
}//zapi__deflateInit

//------------------------------------------------------------------------
int ZLIB1_DLL__ApiProvider::zapi__deflate
              (api::z_stream* const strm,
               int            const flush)
{
 assert(strm);

 return m_deflate.point()
          (strm,
           flush);
}//zapi__deflate

//------------------------------------------------------------------------
int ZLIB1_DLL__ApiProvider::zapi__deflateEnd
              (api::z_stream* const strm)
{
 assert(strm);
 assert(m_deflateEnd.test_point());

 return m_deflateEnd.point()
          (strm);
}//zapi__deflateEnd

//------------------------------------------------------------------------
int ZLIB1_DLL__ApiProvider::zapi__inflateInit
              (api::z_stream* const strm)
{
 assert(strm);

 return m_inflateInit_.point()
          (strm,
           api::ZLIB_VERSION,
           sizeof(*strm));
}//zapi__inflateInit

//------------------------------------------------------------------------
int ZLIB1_DLL__ApiProvider::zapi__inflate
              (api::z_stream* const strm,
               int            const flush)
{
 assert(strm);

 return m_inflate.point()
          (strm,
           flush);
}//zapi__inflate

//------------------------------------------------------------------------
int ZLIB1_DLL__ApiProvider::zapi__inflateEnd
              (api::z_stream* const strm)
{
 assert(strm);
 assert(m_inflateEnd.test_point());

 return m_inflateEnd.point()
          (strm);
}//zapi__inflateEnd

////////////////////////////////////////////////////////////////////////////////
}/*nms dll*/}/*nms zlib1*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
