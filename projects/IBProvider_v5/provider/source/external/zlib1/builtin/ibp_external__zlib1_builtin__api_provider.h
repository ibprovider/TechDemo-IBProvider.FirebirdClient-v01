////////////////////////////////////////////////////////////////////////////////
//ZLib1 API Provider for builtin implementation.
//                                                 Dmitry Kovalenko. 19.01.2019.
#ifndef _ibp_external__zlib1_builtin__api_provider_H_
#define _ibp_external__zlib1_builtin__api_provider_H_

#include "source/external/zlib1/ibp_external__zlib1__api_provider.h"
#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{namespace external{namespace zlib1{namespace builtin{
////////////////////////////////////////////////////////////////////////////////
//class ZLIB1_BUILTIN__ApiProvider

class ZLIB1_BUILTIN__ApiProvider COMP_W000006_CLASS_FINAL
 :public IBP_DEF_INTERFACE_IMPL_STATIC(ZLIB1__ApiProvider)
{
 private:
  typedef ZLIB1_BUILTIN__ApiProvider                       self_type;

  ZLIB1_BUILTIN__ApiProvider(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  ZLIB1_BUILTIN__ApiProvider();

  virtual ~ZLIB1_BUILTIN__ApiProvider();

 public:
  /// <summary>
  ///  Фабрика класса.
  /// </summary>
  //! \param[in] pDLL
  //!  Not null.
  static ZLIB1__ApiProviderPtr create();

  //ZLIB1__ApiProvider interface -----------------------------------------
  virtual int zapi__deflateInit
                (api::z_stream* strm,
                 int            level) COMP_W000004_OVERRIDE_FINAL;

  virtual int zapi__deflate
                (api::z_stream* strm,
                 int            flush) COMP_W000004_OVERRIDE_FINAL;

  virtual int zapi__deflateEnd
                (api::z_stream* strm) COMP_W000004_OVERRIDE_FINAL;


  virtual int zapi__inflateInit
                (api::z_stream* strm) COMP_W000004_OVERRIDE_FINAL;

  virtual int zapi__inflate
                (api::z_stream* strm,
                 int            flush) COMP_W000004_OVERRIDE_FINAL;

  virtual int zapi__inflateEnd
                (api::z_stream* strm) COMP_W000004_OVERRIDE_FINAL;

 private:
  static self_type sm_Instance;
};//class ZLIB1_BUILTIN__ApiProvider

#undef DEF_ZLIB1_POINT

////////////////////////////////////////////////////////////////////////////////
}/*nms builtin*/}/*nms zlib1*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
#endif
