////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_com_data.h
//! \brief   Данные менеджера COM-модуля
//! \author  Kovalenko Dmitry
//! \date    07.05.2009
#ifndef _ibp_com_data_H_
#define _ibp_com_data_H_

#ifndef IBP_BUILD_TESTCODE
# include "source/oledb/ibp_oledb__class_factory_data.h"
#endif

#include "source/ibp_memory.h"

#if(IBP_CFG_HAS_MODULE_CONFIG)
# include "source/config/ibp_cfg.h"
#endif

#ifndef IBP_BUILD_TESTCODE
# include <lcpi/lib/structure/t_fix_vector.h>
#endif

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class TIBP_ComModule::TData

/// <summary>
///  Управляющие данные COM-модуля
/// </summary>
class TIBP_ComModule::TData LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef TData                                           self_type;

  TData(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef IBP_MemoryAllocator                             allocator_type;

#ifndef IBP_BUILD_TESTCODE
  using class_factory_datas_type
   =lib::structure::t_fix_vector<IBP_OLEDB__ClassFactoryData,10>;
#endif

  typedef structure::t_multi_thread_traits                thread_traits;
  typedef thread_traits::guard_type                       guard_type;
  typedef thread_traits::lock_guard_type                  lock_guard_type;

 public:
  ///Identifier of used COM API.
  GUID m_ComApiID;

 public:
  ///Синхронизация модификаций счетчика блокировок модуля.
  thread_traits::guard_type   m_module_lock_count_guard;

  ///Счетчик компонент
  size_t volatile             m_module_lock_count;

 public:
  ///The count of components
  size_t volatile             m_component_count;

 public:
  unsigned __int64            m_server_lock_count;

 public:
#ifndef IBP_BUILD_TESTCODE
  ///Data for class factories
  class_factory_datas_type    m_ClassFactoryDatas;
#endif

  ///Параметры регистрации модуля
  string_type                 m_prog_reg_params;

 #ifdef _PROCESS_DEBUG_MESSAGE_
  ///TRACE_BUILD. Периодичность сброса лог-файла на диск.
  static LONG                 sm_FlushLogFilePeriod;
 #endif

 public:
  CLSID               m_CLSID_IBProvider;
  CLSID               m_CLSID_IBProviderErrors;
  CLSID               m_CLSID_IBProviderDataLinkPropPage;
  CLSID               m_CLSID_IBProviderDataLinkAdvPropPage;

  string_type         m_IBProvider_FileExt;
  string_type         m_IBProvider_ProgID;
  string_type         m_IBProvider_Descr;

 public:
 #if(IBP_CFG_HAS_MODULE_CONFIG)
  t_ibp_config        m_config;
 #endif

 public:
  /// <summary>
  ///  The initializing constructor
  /// </summary>
  //! \param[in] hInstance
  explicit TData(HINSTANCE hInstance);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~TData();

  //selectors ------------------------------------------------------------
  const string_type& GetModulePath()const;

  const string_type& GetModuleName()const;

  static REFCLSID Get_CLSID_IBProvider__private();

  static REFCLSID Get_CLSID_IBProviderErrorLookup__private();

  static REFCLSID Get_CLSID_IBProviderDataLinkPropPage__private();

  static REFCLSID Get_CLSID_IBProviderDataLinkAdvPropPage__private();

 public:
  typedef allocator_type::rebind<void>::other raw_alloc_type;

  static void* operator new (size_t sz)
  {
   return raw_alloc_type::instance.allocate(sz); //throw
  }

  static void operator delete (void* pv)
  {
   raw_alloc_type::instance.deallocate(pv,0);
  }

 private:
  ///Файловый путь с нашему модулю
  const string_type     m_ModulePath;

  ///Имя нашего модуля
  string_type           m_ModuleName;
};//class TIBP_ComModule::TData

////////////////////////////////////////////////////////////////////////////////
//class TIBP_ComModule::TData

inline const TIBP_ComModule::string_type& TIBP_ComModule::TData::GetModulePath()const
{
 return m_ModulePath;
}//GetModulePath
  
//------------------------------------------------------------------------
inline const TIBP_ComModule::string_type& TIBP_ComModule::TData::GetModuleName()const
{
 return m_ModuleName;
}//GetModuleName

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
