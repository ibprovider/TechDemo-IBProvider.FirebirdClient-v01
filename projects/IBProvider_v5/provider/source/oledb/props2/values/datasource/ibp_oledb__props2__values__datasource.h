////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__values__datasource.h
//! \brief   Контейнер значений свойств источника данных
//! \author  Kovalenko Dmitry
//! \date    14.12.2018
#ifndef _ibp_oledb__props2__values__datasource_H_
#define _ibp_oledb__props2__values__datasource_H_

#include "source/oledb/props2/values/ibp_oledb__props2__values.h"

#include "source/oledb/ibp_oledb__prop__internal_values.h"

#include "source/ibp_subsystem_ids.h"
#include "source/ibp_char.h"
#include "source/ibp_forward.h"

#include <structure/t_closure.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Values__DATASOURCE

/// <summary>
///  Контейнер значений свойств источника данных
/// </summary>
class IBP_OLEDB_Props2__Values__DATASOURCE COMP_W000006_CLASS_FINAL
 :public IBP_OLEDB_Props2__Values
{
 private:
  typedef IBP_OLEDB_Props2__Values__DATASOURCE      self_type;
  typedef IBP_OLEDB_Props2__Values                  inherited;

  IBP_OLEDB_Props2__Values__DATASOURCE(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>        self_ptr;
  typedef structure::t_smart_object_ptr<const self_type>  self_cptr;

  typedef structure::t_closure_r0<LONG>             TOnGetConnectionStatus;
  typedef structure::t_closure_r0<bool>             TOnCanResetConnection;

 public:
  enum enumAllowedValuesKind
  {
   AllowedValuesKind__DbInit               =0,
   AllowedValuesKind__DbInit_DsCreate      =1,
   AllowedValuesKind__DbInit_DsCreate_Sess =2,
  };//enumAllowedValuesKind

 public:
  //Допустимые для установки значения свойств
  enumAllowedValuesKind m_AllowedValuesKind;

 public:
  //Сбрасываются в ResetSinks!

  TOnGetConnectionStatus  OnGetConnectionStatus;

  TOnCanResetConnection   OnCanResetConnection;

 private:
  IBP_OLEDB_Props2__Values__DATASOURCE();

  IBP_OLEDB_Props2__Values__DATASOURCE(const self_type*  pX,
                                       tagCopyKind_Clone copyTag);

  IBP_OLEDB_Props2__Values__DATASOURCE(const self_type*  pX,
                                       tagCopyKind_Child copyTag);

  virtual ~IBP_OLEDB_Props2__Values__DATASOURCE();

 public:
  static self_ptr Create();

  self_ptr CreateClone()const;

  self_ptr CreateChild()const;

  /// <summary>
  ///  Отключение внешних обработчиков событий
  /// <summary>
  void ResetSinks();

  //interface ------------------------------------------------------------

  /// <summary>
  ///  Проверка наличия всех обязательных свойств, необходимых для подключения
  /// </summary>
  bool AllRequiredProps()const;

  /// <summary>
  ///  Проверка наличия обязательных параметров. THROW
  /// </summary>
  void CheckRequiredProps()const;//throw

  /// <summary>
  ///  Получение настроек подключения
  /// </summary>
  //! \param[in,out] ds
  void GetIBPDataSettings(t_ibp_data_settings& ds)const;

  /// <summary>
  ///  Получение значения свойства "Window Handle"
  /// </summary>
  HWND GetWindowHandle()const;

  /// <summary>
  ///  Получение сведений о DLL с серверным клиентом
  /// </summary>
  t_ibp_string GetDbLibrary()const;

  /// <summary>
  ///  Полученеие сведений о расположении базы данных. THROW.
  /// </summary>
  //! \param[in] subsystemID
  std::wstring GetDatabaseLocation_REQ(t_ibp_subsystem_id subsystemID)const;

  /// <summary>
  ///  Получение значения свойства инициализации "remote:wire_crypt"
  /// </summary>
  ibp_ipropval__remote__wire_crypt Get_Remote_WireCrypt()const;

  /// <summary>
  ///  Получение значения свойства инициализации "remote:wire_compression"
  /// </summary>
  ibp_ipropval__remote__wire_compression Get_Remote_WireCompression()const;

 public:
  bool TestValue__SchemaRestrictions(const ibprovider::IBP_CHAR* pValue)const;

 private:
  virtual const IBP_OLEDB_Props2__DescrData& Internal__GetStaticPropData
                        (REFGUID  propGuid,
                         DBPROPID propId)const COMP_W000004_OVERRIDE_FINAL;

 private:
  typedef structure::t_value_with_null<long> long_type_n;

  /// <summary>
  ///  Получение первого дня недели.
  /// </summary>
  long_type_n Helper__GetFirstDayNum()const;

 private:
  bool Helper__TestValue__normalized_str
        (REFGUID                     propGuid,
         DBPROPID                    propId,
         const ibprovider::IBP_CHAR* pValue)const;
};//class IBP_OLEDB_Props2__Values__DATASOURCE

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
