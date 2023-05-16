////////////////////////////////////////////////////////////////////////////////
//ZLib1 API Provider for external implementation.
//                                                 Dmitry Kovalenko. 06.01.2019.
#ifndef _ibp_external__zlib1_dll__api_provider_H_
#define _ibp_external__zlib1_dll__api_provider_H_

#include "source/external/zlib1/ibp_external__zlib1__api_provider.h"
#include "source/os/ibp_os__dll_entry_point.h"
#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{namespace external{namespace zlib1{namespace dll{
////////////////////////////////////////////////////////////////////////////////
//class ZLIB1_DLL__ApiProvider

#define DEF_ZLIB1_POINT(func_name)                                          \
 ibp::os::ibp_os__dll_entry_point<api::t_fn_##func_name*> m_##func_name

class ZLIB1_DLL__ApiProvider LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_INTERFACE_IMPL_DYNAMIC(ZLIB1__ApiProvider)
{
 private:
  typedef ZLIB1_DLL__ApiProvider                       self_type;

  ZLIB1_DLL__ApiProvider(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  typedef os::t_ibp_os__dll                            dll_type;

  typedef os::t_ibp_os__dll_ptr                        dll_ptr;

 private:
  ZLIB1_DLL__ApiProvider(dll_type* pDLL);

  virtual ~ZLIB1_DLL__ApiProvider();

 public:
  /// <summary>
  ///  ‘абрика класса.
  /// </summary>
  //! \param[in] pDLL
  //!  Not null.
  static ZLIB1__ApiProviderPtr create(dll_type* pDLL);

  //ZLIB1__ApiProvider interface -----------------------------------------
  virtual int zapi__deflateInit
                (api::z_stream* strm,
                 int            level) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual int zapi__deflate
                (api::z_stream* strm,
                 int            flush) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual int zapi__deflateEnd
                (api::z_stream* strm) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;


  virtual int zapi__inflateInit
                (api::z_stream* strm) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual int zapi__inflate
                (api::z_stream* strm,
                 int            flush) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual int zapi__inflateEnd
                (api::z_stream* strm) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  DEF_ZLIB1_POINT(deflateInit_);
  DEF_ZLIB1_POINT(deflate);
  DEF_ZLIB1_POINT(deflateEnd);      //force init

  DEF_ZLIB1_POINT(inflateInit_);
  DEF_ZLIB1_POINT(inflate);
  DEF_ZLIB1_POINT(inflateEnd);      //force init

 private:
  /// ”казатель на загрузчик DLL
  dll_ptr const m_spDLL;
};//class ZLIB1_DLL__ApiProvider

#undef DEF_ZLIB1_POINT

////////////////////////////////////////////////////////////////////////////////
}/*nms dll*/}/*nms zlib1*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
#endif
