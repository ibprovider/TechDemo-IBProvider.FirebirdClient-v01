////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v003
//! \file    ibp_cs_icu_v003__provider.h
//! \brief   Провайдер к ICU API v3
//! \author  Kovalenko Dmitry
//! \date    07.10.2008
#ifndef _ibp_cs_icu_v003__provider_H_
#define _ibp_cs_icu_v003__provider_H_

#include "source/charsets/ibp_charset_provider.h"
#include "source/os/ibp_os__dll_entry_point.h"
#include "source/os/ibp_os__dll_loader.h"
#include "source/charsets/cs_code/icu/v003/ibp_cs_icu_v003__api.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v003{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_cs_icu_v003
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_icu_provider

#define DEF_ICU_POINT(func_name)                                          \
 ibp::ibp_os__dll_entry_point<api::t_fn_##func_name*>::type m_##func_name

/// <summary>
///  Провайдер доступа к ICU API v3
/// </summary>
class t_ibp_icu_provider
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(charsets::t_ibp_charset_provider)
{
 private:
  typedef t_ibp_icu_provider                         self_type;

  t_ibp_icu_provider(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~t_ibp_icu_provider();

 public: //typedefs ------------------------------------------------------
  /// Self smart-pointer
  typedef structure::t_smart_object_ptr<self_type>   self_ptr;

  typedef ibp::t_ibp_os__dll_loader                  dll_type;

  typedef dll_type::self_ptr                         dll_ptr;

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
   load_cs(const cs_name_box_type& cs_name) COMP_W000004_OVERRIDE_FINAL;

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
