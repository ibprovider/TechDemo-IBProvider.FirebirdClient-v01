////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v052
//! \file    ibp_cs_icu_v052__provider.h
//! \brief   Провайдер к ICU API v52
//! \author  Kovalenko Dmitry
//! \date    19.07.2017
#ifndef _ibp_cs_icu_v052__provider_H_
#define _ibp_cs_icu_v052__provider_H_

#include "source/charsets/ibp_charset_provider.h"
#include "source/charsets/cs_code/icu/v052/ibp_cs_icu_v052__api.h"

#include "source/os/ibp_os__dll_entry_point.h"
#include "source/os/ibp_os__dll_init_mutex.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v052{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_cs_icu_v052
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_icu_provider

#define DEF_ICU_POINT(func_name)                                          \
 ibp::os::ibp_os__dll_entry_point<api::t_fn_##func_name*> m_##func_name

/// <summary>
///  Провайдер доступа к ICU API v52
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

  typedef ibp::os::t_ibp_os__dll                     dll_type;
  typedef ibp::os::t_ibp_os__dll_ptr                 dll_ptr;

 public:
  DEF_ICU_POINT(u_setDataDirectory);

  DEF_ICU_POINT(u_init);
  DEF_ICU_POINT(u_cleanup);

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
   {return L"ICU52";}

  //t_ibp_charset_provider interface -------------------------------------
  virtual db_obj::t_db_charset_const_ptr
   load_cs(const cs_name_box_type& cs_name) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef os::t_ibp_os__dll_init_mutex           dll_init_mutex_type;
  typedef os::t_ibp_os__dll_init_mutex::self_ptr dll_init_mutex_ptr;

 private:
  static dll_init_mutex_ptr helper__get_dll_init_mutex(dll_type* pDLL);

  static IBP_SmartObjectPtr helper__create_dll_init_mutex();

  void helper__init_op();

  void helper__uninit_op();

 private:
  /// Указатель на загрузчик DLL
  dll_ptr const m_spDLL;

  /// DLL initialization mutex
  dll_init_mutex_ptr const m_spDllInitMutex;

 private:
  static const GUID sm_DllInitSvcObjID;
};//class t_ibp_icu_provider

#undef DEF_ICU_POINT

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v052*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
#endif
