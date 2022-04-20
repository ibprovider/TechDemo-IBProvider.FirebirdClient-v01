////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error.h
//! \brief   COM Object for store the OLEDB Errors
//! \author  Kovalenko Dmitry
//! \date    17.10.2008
#ifndef _ibp_oledb__error_H_
#define _ibp_oledb__error_H_

#include "source/ibp_memory.h"
#include "source/ibp_debug.h"
#include <ole_lib/oledb/oledb_common.h>
#include <ole_lib/oledb/oledb_ex__db_primary_error.h>
#include <ole_lib/ole_auto/ole_auto_variant.h>
#include <ole_lib/ole_lib.h>
#include <structure/t_smart_vector.h>

#include <structure/stl/t_stl_map.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__Error

/// <summary>
///  Объект для экспорта ошибок за пределы модуля
/// </summary>
class IBP_OLEDB__Error LCPI_CPP_CFG__CLASS__FINAL
 :public IErrorInfo
 ,public IErrorRecords
 ,public IDBPrimaryError
 ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef IBP_OLEDB__Error                                     self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler       inherited;

  IBP_OLEDB__Error(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~IBP_OLEDB__Error();

 public: //typedefs ------------------------------------------------------
  typedef ole_lib::IPtr2<self_type>                            self_ptr;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  IBP_OLEDB__Error(IUnknown* pUnkOuter);

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //IErrorInfo iterface --------------------------------------------------
  virtual HRESULT __stdcall GetSource
                             (BSTR* pbstrSource) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetDescription
                             (BSTR* pbstrDescription) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetGUID
                             (GUID* pguid) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetHelpContext
                             (DWORD* pdwHelpContext) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetHelpFile
                             (BSTR* pbstrHelpFile) COMP_W000004_OVERRIDE_FINAL;

  //IErrorRecords interface ----------------------------------------------
  virtual HRESULT __stdcall AddErrorRecord
                             (ERRORINFO*   pErrorInfo,
                              DWORD        dwLookupID,
                              DISPPARAMS*  pdispparams,
                              IUnknown*    punkCustomError,
                              DWORD        dwDynamicErrorID) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetBasicErrorInfo
                             (ULONG      ulRecordNum,
                              ERRORINFO* pErrorInfo) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetCustomErrorObject
                             (ULONG      ulRecordNum,
                              REFIID     riid,
                              IUnknown** ppObject) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetErrorInfo
                             (ULONG        ulRecordNum,
                              LCID         lcid,
                              IErrorInfo** ppErrorInfo) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetErrorParameters
                             (ULONG       ulRecordNum,
                              DISPPARAMS* pdispparams) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetRecordCount
                             (ULONG* pcRecords) COMP_W000004_OVERRIDE_FINAL;

  //IDBPrimaryError interface --------------------------------------------
  virtual HRESULT __stdcall SetPrimaryError
                             (ULONG PrimaryErrorIndex) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall GetPrimaryError
                             (ULONG* pPrimaryErrorIndex) COMP_W000004_OVERRIDE_FINAL;

 private:
  class tag_item;

  typedef tag_item                                            item_type;
  typedef structure::t_smart_vector
           <const item_type,
            IBP_MemoryAllocator>                              items_type;

  typedef structure::t_multi_thread_traits                    thread_traits;
  typedef thread_traits::guard_type                           guard_type;
  typedef thread_traits::lock_guard_type                      lock_guard_type;

  typedef structure::t_stl_map
           <CLSID,
            oledb_lib::IErrorLookupPtr,
            ole_lib::TGuidLess,
            IBP_MemoryAllocator>                              err_lookup_map_type;

  typedef structure::t_value_with_null<ULONG>                 primary_err_idx_type_N;

 private:
  /// <summary>
  ///  Получение сведений об источнике ошибки и описание ошибки
  /// </summary>
  //! \param[in]  pItem
  //!  Not NULL
  //! \param[in]  lcid
  //! \param[out] pbstrSource
  //!  Can be NULL
  //! \param[out] pbstrDescription
  //!  Can be NULL
  void Helper__GetErrorDescription(const item_type*  pItem,
                                   LCID              lcid,
                                   BSTR*             pbstrSource,
                                   BSTR*             pbstrDescription);

  /// <summary>
  ///  Получение сведений о файле со справкой об ошибке
  /// </summary>
  //! \param[in]  pItem
  //!  Not NULL
  //! \param[in]  lcid
  //! \param[out] pbstrHelpFile
  //!  Can be NULL
  //! \param[out] pdwHelpContext
  //!  Can be NULL
  void Helper__GetHelpInfo(const item_type* pItem,
                           LCID             lcid,
                           BSTR*            pbstrHelpFile,
                           DWORD*           pdwHelpContext);

 private:
  /// <summary>
  ///  Освобождение динамических данных, связанных с ошибкой
  /// </summary>
  //! \param[in] pItem
  //!  Not NULL
  void Helper__ReleaseDynamicErrorData(const item_type* pItem);

 private:
  /// <summary>
  ///  Получение указателя на преобразователь ошибки. THROW
  /// </summary>
  //! \param[in] pItem
  //!  Not NULL
  const oledb_lib::IErrorLookupPtr& Helper__GetErrorLookup(const item_type* pItem); //throw

  /// <summary>
  ///  Создание обработчика ошибок.
  /// </summary>
  //! \param[in] ProviderClsID
  //! \return
  //!  Not NULL
  static oledb_lib::IErrorLookupPtr Helper__CreateErrorLookup(REFCLSID ProviderClsID);

  /// <summary>
  ///  Создание объекта обработки ошибок на основании сведений из реестра
  /// </summary>
  //! \param[in] ProviderClsID
  //! \return
  //!  NULL, если не удалось создать обработчик
  static oledb_lib::IErrorLookupPtr Helper__CreateErrorLookup_Reg_NoThrow(REFCLSID ProviderClsID);

  /// <summary>
  ///  Создание объекта обработки ошибок на основании сведений из реестра. THROW
  /// </summary>
  //! \param[in] ProviderClsID
  //!
  //! В случае любой ошибки будет сгенерировано исключение.
  static oledb_lib::IErrorLookupPtr Helper__CreateErrorLookup_Reg(REFCLSID ProviderClsID); //throw

  /// <summary>
  ///  Создание объекта обработки ошибок. THROW
  /// </summary>
  //!
  //! В случае любой ошибки будет сгенерировано исключение.
  static oledb_lib::IErrorLookupPtr Helper__CreateErrorLookup_Direct(); //throw

 private:
  ///MT-защита объекта
  guard_type              m_guard;

  ///Коллекция описаний ошибок
  items_type              m_items;

  ///Множество объектов для обработки ошибок
  err_lookup_map_type     m_err_lookups;

 #ifndef NDEBUG
  ///DEBUG: отладочная блокировка доступа к m_err_lookups
  t_ibp_debug__mt_guard   m_err_lookups__debug_guard;
 #endif

  ///Индекс главной ошибки
  primary_err_idx_type_N  m_primary_err_idx;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(IBP_OLEDB__Error)
};//class IBP_OLEDB__Error

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__Error::tag_item

/// <summary>
///  Объект для хранения описания элемента OLEDB ошибки
/// </summary>
class IBP_OLEDB__Error::tag_item:public IBP_SmartMemoryObject
{
 private:
  typedef tag_item                                            self_type;

  tag_item(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>            self_ptr;
  typedef structure::t_smart_object_ptr<const self_type>      self_cptr;

  typedef structure::t_built_in_array<ole_lib::TVariant>      vargs_type;

  typedef structure::t_built_in_array<DISPID>                 args_ids_type;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  tag_item(const ERRORINFO&  ErrorInfo,
           DWORD             dwLookupID,
           const VARIANTARG* pVarArgs,
           size_t            nVarArgs,
           const DISPID*     pArgsIDs,
           size_t            nArgsIDs,
           IUnknown*         pCustomError,
           DWORD             dwDynamicErrorID,
           void*             pvBegin_BuiltInVarArgs,
           void*             pvBegin_BuildInArgsIDs);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~tag_item();

 public:
  const ERRORINFO             m_ErrorInfo;
  const DWORD                 m_dwLookupID;
  const ole_lib::IUnknownPtr  m_spCustomError;
  const DWORD                 m_dwDynamicErrorID;

  const vargs_type            m_VarArgs;
  const args_ids_type         m_ArgsIDs;

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  //! \param[in] pErrorInfo
  //!  Can be NULL.
  //! \param[in] dwLookupID
  //! \param[in] pdispparams
  //!  Can be NULL.
  //! \param[in] punkCustomError
  //!  Can be NULL.
  //! \param[in] dwDynamicErrorID
  static self_ptr create(const ERRORINFO*  pErrorInfo,
                         DWORD             dwLookupID,
                         const DISPPARAMS* pdispparams,
                         IUnknown*         punkCustomError,
                         DWORD             dwDynamicErrorID);

 private:
  typedef IBP_MemoryAllocator raw_allocator_type;

  static void* operator new (size_t); //not impl

  static void* operator new (size_t,void* pv);

 public:
  static void operator delete (void* pv);

 #if(COMP_CONF_SUPPORT_OPERATOR_DELETE_EX)
  //memory will be deallocated in catch of self_type::Create
  static void operator delete(void* /*pv*/,void* /*pv2*/){;}
 #endif

 private:
  static const ERRORINFO   sm_zero_errorinfo;
  static const DISPPARAMS  sm_zero_dispparams;
};//class IBP_OLEDB__Error::tag_item

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
