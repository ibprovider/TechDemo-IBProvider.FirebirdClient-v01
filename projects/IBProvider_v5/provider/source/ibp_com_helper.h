////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_com_helper.h
//! \brief   ���������� ���������������� ������ IBP_ComModule::THelper
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
//class IBP_ComModule::THelper

class IBP_ComModule::THelper LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=THelper;

 public: //���������� ������������ ������ ���������� ---------------------
  static bool InitHeaps();
  static void TermHeaps();

 public: //���������� ����������� ������� ������ -------------------------
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

  static bool Helper__DetectComApiID();

 #if(IBP_CFG_HAS_MODULE_CONFIG)
  static void Helper__ProcessModuleConfig();
 #endif

  static void Helper__ProcessComponentConfig();

  /// <summary>
  ///  Processing a COM-class identifier
  /// </summary>
  //! \param[in]  params
  //! \param[in]  prop_id
  //! \param[in]  default_clsid
  //! \param[out] pclsid
  //!  Not NULL.
  static void Helper__ProcessRegParam__CLSID
               (param_parser_type&   params,
                const char_type*     prop_id,
                REFCLSID             default_clsid,
                CLSID*               pclsid);

  //
  // Checking to necessary to support a component
  // 
  // false
  //  - param_value==""
  //  - param_value==CLSID_NULL
  //  - it is an incorrect identifier
  // true
  //  - it is a valid identifier
  static bool Helper__HasComponent
               (const string_type& param_value,
                CLSID&             clsid);

  /// <summary>
  ///  Processing the string parameter of a registration
  /// </summary>
  //! \param[in]  params
  //! \param[in]  prop_id
  //! \param[in]  prop_def_value
  //! \param[out] result_value
  //!  Can be NULL.
  static void Helper__ProcessRegParam__String
               (param_parser_type& params,
                const char_type*   prop_id,
                const char*        prop_def_value,
                string_type*       value);

#ifndef IBP_BUILD_TESTCODE
 private:
  static void Helper__CreateFactoryData();

 private:
  using PFNCREATEINSTANCE1
   =IBP_OLEDB__ClassFactoryData::PFNCREATEINSTANCE;

  static void Helper__AddFactoryData(REFCLSID           rClassID,
                                     PFNCREATEINSTANCE1 pfnCreateInstance);
#endif

 private: //Reading helped parameters of module
 #ifdef _PROCESS_DEBUG_MESSAGE_
  static void Helper__ReadFlushLogFilePeriod();
 #endif
};//class IBP_ComModule::THelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
