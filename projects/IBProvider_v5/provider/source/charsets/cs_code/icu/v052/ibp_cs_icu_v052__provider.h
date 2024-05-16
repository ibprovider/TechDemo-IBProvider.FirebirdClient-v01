////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v052
//! \file    ibp_cs_icu_v052__provider.h
//! \brief   ��������� � ICU API v52
//! \author  Kovalenko Dmitry
//! \date    19.07.2017
#ifndef _ibp_cs_icu_v052__provider_H_
#define _ibp_cs_icu_v052__provider_H_

#include "source/charsets/ibp_charset_provider.h"

#include "source/external/icu/v052/ibp_external__icu_v052__api.h"
#include "source/external/icu/ibp_external__icu__dll.h"

#include "source/os/ibp_os__dll_entry_point.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v052{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_cs_icu_v052
//! @{
////////////////////////////////////////////////////////////////////////////////

namespace api=ibp::external::icu::v052::api;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_icu_provider

#define DEF_ICU_POINT(func_name)                                          \
 ibp::os::ibp_os__dll_entry_point<api::t_fn_##func_name*> m_##func_name

/// <summary>
///  ��������� ������� � ICU API v52
/// </summary>
class t_ibp_icu_provider LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(charsets::t_ibp_charset_provider)
{
 private:
  using self_type=t_ibp_icu_provider;

  t_ibp_icu_provider(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~t_ibp_icu_provider();

 public: //typedefs ------------------------------------------------------
  /// Self smart-pointer
  using self_ptr =structure::t_smart_object_ptr<self_type>;

  using dll_type =ibp::external::icu::ICU__Dll;
  using dll_ptr  =ibp::external::icu::ICU__Dll_Ptr;

 public:
  DEF_ICU_POINT(ucnv_open);
  DEF_ICU_POINT(ucnv_close);

  DEF_ICU_POINT(ucnv_setToUCallBack);
  DEF_ICU_POINT(ucnv_setFromUCallBack);

  DEF_ICU_POINT(ucnv_fromUnicode);
  DEF_ICU_POINT(ucnv_toUnicode);

  DEF_ICU_POINT(ucnv_fromUChars);
  DEF_ICU_POINT(ucnv_toUChars);

  DEF_ICU_POINT(ucnv_getMinCharSize);
  DEF_ICU_POINT(ucnv_getMaxCharSize);

  DEF_ICU_POINT(ucnv_getType);

 public:
  /// <summary>
  ///  ����������� ������������
  /// </summary>
  //! \param[in] pDLL
  t_ibp_icu_provider(dll_type* pDLL);

  /// <summary>
  ///  ���������� ������������� ICU-����������
  /// </summary>
  /// ������������ ��� ��������� ������
  static const wchar_t* id()
   {return L"ICU52";}

  //t_ibp_charset_provider interface -------------------------------------
  virtual db_obj::t_db_charset_const_ptr
   load_cs(const cs_name_box_type& cs_name) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  /// ��������� �� ��������� DLL
  dll_ptr const m_spDLL;
};//class t_ibp_icu_provider

#undef DEF_ICU_POINT

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v052*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
#endif
