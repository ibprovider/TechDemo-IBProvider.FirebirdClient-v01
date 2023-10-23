////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v003
//! \file    ibp_cs_icu_v003__provider.h
//! \brief   Провайдер к ICU API v3
//! \author  Kovalenko Dmitry
//! \date    07.10.2008
#ifndef _ibp_cs_icu_v003__provider_H_
#define _ibp_cs_icu_v003__provider_H_

#include "source/charsets/ibp_charset_provider.h"

#include "source/external/icu/v003/ibp_external__icu_v003__api.h"
#include "source/external/icu/ibp_external__icu__dll.h"

#include "source/os/ibp_os__dll_entry_point.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v003{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_cs_icu_v003
//! @{
////////////////////////////////////////////////////////////////////////////////

namespace api=ibp::external::icu::v003::api;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_icu_provider

#define DEF_ICU_POINT(func_name)                                          \
 ibp::os::ibp_os__dll_entry_point<api::t_fn_##func_name*> m_##func_name

/// <summary>
///  Провайдер доступа к ICU API v3
/// </summary>
class t_ibp_icu_provider LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(charsets::t_ibp_charset_provider)
{
 private:
  using self_type=t_ibp_icu_provider;

  t_ibp_icu_provider(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~t_ibp_icu_provider();

 public: //typedefs ------------------------------------------------------
  /// Self smart-pointer
  using self_ptr =lib::structure::t_smart_object_ptr<self_type>;

  using dll_type =ibp::external::icu::ICU__Dll;
  using dll_ptr  =ibp::external::icu::ICU__Dll_Ptr;

 public:
  DEF_ICU_POINT(ucnv_open);
  DEF_ICU_POINT(ucnv_close);

  DEF_ICU_POINT(ucnv_setToUCallBack);
  DEF_ICU_POINT(ucnv_setFromUCallBack);

  DEF_ICU_POINT(UCNV_TO_U_CALLBACK_STOP);
  DEF_ICU_POINT(UCNV_FROM_U_CALLBACK_STOP);

  DEF_ICU_POINT(ucnv_fromUnicode);
  DEF_ICU_POINT(ucnv_toUnicode);

  DEF_ICU_POINT(ucnv_fromUChars);
  DEF_ICU_POINT(ucnv_toUChars);

  DEF_ICU_POINT(ucnv_getMinCharSize);
  DEF_ICU_POINT(ucnv_getMaxCharSize);

  DEF_ICU_POINT(ucnv_getType);

 public:
  /// <summary>
  ///  Конструктор инициалиации
  /// </summary>
  //! \param[in] pDLL
  t_ibp_icu_provider(dll_type* pDLL);

  /// <summary>
  ///  Символьный идентификатор ICU-провайдера
  /// </summary>
  /// Используется при обработке ошибок
  static const wchar_t* id()
   {return L"ICU3";}

  //t_ibp_charset_provider interface -------------------------------------
  virtual db_obj::t_db_charset_const_ptr
   load_cs(const cs_name_box_type& cs_name) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  /// Указатель на загрузчик DLL
  dll_ptr const m_spDLL;
};//class t_ibp_icu_provider

#undef DEF_ICU_POINT

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v003*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
#endif
