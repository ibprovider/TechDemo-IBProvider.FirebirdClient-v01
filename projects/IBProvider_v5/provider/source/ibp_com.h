////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_com.h
//! \brief   Менеджер COM-модуля
//! \author  Kovalenko Dmitry
//! \date    28.04.2004
#ifndef _ibp_com_H_
#define _ibp_com_H_

#include <structure/t_threads.h>
#include <structure/t_char_base.h>
#include <string>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//contents

class IBP_ComModule;

////////////////////////////////////////////////////////////////////////////////
//class IBP_ComModule

/// <summary>
///  Менеджер COM-модуля
/// </summary>
class IBP_ComModule LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=IBP_ComModule;

 public:  //typedefs -----------------------------------------------------
  using thread_traits=structure::t_multi_thread_traits;

  using string_type=structure::t_string;

  using char_type=structure::t_char;

  class TData;
  class THelper;

 public:
  /// <summary>
  ///  Инициализация модуля
  /// </summary>
  //! \param[in] hInstance
  static bool Init(HINSTANCE hInstance);

  /// <summary>
  ///  Деинициализация модуля
  /// </summary>
  static void Term();

 public:
  static HINSTANCE GetModuleInstance();

  static const string_type& GetModulePath();

  static const string_type& GetModuleName();

  /// <summary>
  ///  Формирование строки, содержащей версию модуля
  /// </summary>
  ///  Можно вызывать до инициализации
  static string_type GetModuleVersion(const char_type* const prefix=NULL);

 public:
  /// <summary>
  ///  Getting an identifier of used COM API.
  /// </summary>
  static REFGUID GetComApiID();

 public:
  /// <summary>
  ///  Формирование строки, содержащей название, версию и разрядность провайдера
  /// </summary>
  //! \return
  //!  Например, "IBProvider x.x.x.xxxxx [32-bit]"
  static string_type  GetProviderLabel();

  static size_t GetModuleLockCount();

  static size_t GetComponentCount();

  static bool DllCanUnloadNow();

#ifndef NDEBUG
  static bool DEBUG__ModuleIsActive();

  static bool DEBUG__ModuleIsShutdown();
#endif

#ifndef IBP_BUILD_TESTCODE
  static void CheckActiveState();
#endif

  static void IncrementModuleLockCount();
  static void DecrementModuleLockCount();

  static void IncrementComponentCount2();
  static void DecrementComponentCount2();

  static void LockServer();
  static void UnlockServer();

#ifndef IBP_BUILD_TESTCODE
  static HRESULT GetClassObject(REFGUID rComApiID,REFCLSID rclsid,REFIID riid,void** ppv);
#endif

 public: //получение параметров регистрации модуля в системе
  static const string_type& GetProgRegParams();

  static const string_type& Get_IBProvider_FileExt();
  static const string_type& Get_IBProvider_ProgID();
  static const string_type& Get_IBProvider_Descr();

 #ifdef _PROCESS_DEBUG_MESSAGE_
  //кол-во сообщений между принудительным сбросом лог-файла
  static LONG Get_FlushLogFilePeriod();
#endif

 public: //получение идентификаторов компонент модуля
  static REFCLSID Get_CLSID_IBProvider();
  static REFCLSID Get_CLSID_IBProvider__private();

  static REFCLSID Get_CLSID_IBProviderErrors();

  static REFCLSID Get_CLSID_IBProviderDataLinkPropPage();
  static REFCLSID Get_CLSID_IBProviderDataLinkPropPage__private();

  static REFCLSID Get_CLSID_IBProviderDataLinkAdvPropPage();
  static REFCLSID Get_CLSID_IBProviderDataLinkAdvPropPage__private();

 public:
  static HRESULT CurrentExceptionHandler
                   (ole_lib::TBaseUnknown2* pRootInterface,
                    REFCLSID                ComponentID,
                    REFIID                  InterfaceID,
                    bool                    CreateErrInfo);

 public:
#ifdef IBP_BUILD_TESTCODE
  static size_t TestCode__GetAllocBlockCount();
#endif

 private:
  static HINSTANCE sm_hInstance;
  static TData*    sm_pData;
};//class IBP_ComModule

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
