////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_com_helper.h
//! \brief   Реализация вспомогательного класса TIBP_ComModule::THelper
//! \author  Kovalenko Dmitry
//! \date    07.05.2009
#ifndef _ibp_com_helper_H_
#define _ibp_com_helper_H_

#include "source/ibp_com_data.h"
#include "source/ibp_parameter_list_parser.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class TIBP_ComModule::THelper

class TIBP_ComModule::THelper
{
 private:
  typedef THelper                               self_type;

 public: //Управление собственными кучами провайдера ---------------------
  static bool InitHeaps();
  static void TermHeaps();

 public: //Управление глобальными данными модуля -------------------------
  static bool InitData(HINSTANCE hInstance);
  static void TermData();

 public:
#ifdef IBP_BUILD_TESTCODE
  static size_t TestCode__GetAllocBlockCount();
#endif

 private:
  template<class THeap>
  static void Helper__DestroyHeap(THeap&);

 private:
  typedef IBP_ParameterListParserSelector<char_type>::type  param_parser_type;

 #if(IBP_CFG_HAS_MODULE_CONFIG)
  static void Helper__ProcessModuleConfig();
 #endif

  static void Helper__ProcessComponentConfig();

  /// <summary>
  ///  Обрабатываем идентификатор COM-класса
  /// </summary>
  //! \param[in]  params
  //! \param[in]  prop_id
  //! \param[in]  default_clsid
  //! \param[out] pclsid
  //!  Not NULL.
  static void Helper__ProcessRegParam__CLSID(param_parser_type&   params,
                                             const char_type*     prop_id,
                                             REFCLSID             default_clsid,
                                             CLSID*               pclsid);

  //проверка необходимости поддерживать компоненту
  // false
  //  - param_value==""
  //  - param_value==CLSID_NULL
  //  - недействительный идентификатор
  // true
  //  - действительный идентификатор
  static bool Helper__HasComponent(const string_type& param_value,
                                   CLSID&             clsid);

  /// <summary>
  ///  Обрабоатываем строковый параметр регистрации
  /// </summary>
  //! \param[in]  params
  //! \param[in]  prop_id
  //! \param[in]  prop_def_value
  //! \param[out] result_value
  //!  Can be NULL.
  static void Helper__ProcessRegParam__String(param_parser_type&   params,
                                              const char_type*     prop_id,
                                              const char_type*     prop_def_value,
                                              string_type*         value);

#ifndef IBP_BUILD_TESTCODE
 private:
  static void Helper__CreateFactoryData();

 private:
  typedef HRESULT (*PFNCREATEINSTANCE1)(IUnknown*                pUnkOuter,
                                        REFCLSID                 rClassID,
                                        ole_lib::TBaseUnknown2** ppObject);

  static void Helper__AddFactoryData(REFCLSID rClassID,
                                     PFNCREATEINSTANCE1 pfnCreateInstance);

 private:
  typedef HRESULT (*PFNCREATEINSTANCE2)(IUnknown*                pUnkOuter,
                                       ole_lib::TBaseUnknown2** ppObject);

  static void Helper__AddFactoryData(REFCLSID           rClassID,
                                     PFNCREATEINSTANCE2 ppObject);
#endif

 private://чтение служебных параметров модуля
 #ifdef _PROCESS_DEBUG_MESSAGE_
  static void Helper__ReadFlushLogFilePeriod();
 #endif
};//class TIBP_ComModule::THelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
