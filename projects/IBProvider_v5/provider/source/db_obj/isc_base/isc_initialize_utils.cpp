////////////////////////////////////////////////////////////////////////////////
//! \ingroup  isc_base
//! \file     isc_initialize_utils.cpp
//! \brief    Конструкции для выполнения стандартных операций инициализации ISC-подключения
//! \author   Kovalenko Dmitry
//! \date     04.10.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_initialize_utils.h"
#include "source/charsets/ibp_charset_manager_v2.h"

#include "source/ibp_utils.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>

#include <structure/t_latin_upper.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////

static t_ibp_string Helper__GetCharsetName
                     (const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues,
                      REFGUID                                            propGuid,
                      DBPROPID                                     const propId)
{
 assert(pDsPropValues);

 ole_lib::TVariant varPropValue;

 if(!pDsPropValues->Direct__GetValue(propGuid,propId,nullptr,&varPropValue))
  return IBP_T("NONE");

 //! \note
 //!  [2019-02-15] Раньше пустая строка также преобразовывалась в "NONE".

 assert(varPropValue.vt==VT_BSTR);

 auto strPropValue
  =ole_lib::BStrToUnkStr<t_ibp_char>(varPropValue.bstrVal);

 // [2019-02-21]
 //  pDsPropValues должен содержать корректное значение свойства
 assert(IBP_Utils::IsValidCharsetName(strPropValue));

 std::transform(strPropValue.begin(),
                strPropValue.end(),
                strPropValue.begin(),
                structure::t_latin_upper<t_ibp_char>());

 return strPropValue;
}//Helper__GetCharsetName

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Создание сервиса для работы с кодовыми страницами
/// </summary>
//! \param[in] pDsPropValues
//! \param[in] pIcuLoader
//! \param[in] pCsName__ODS
db_obj::t_db_charset_manager_v2_ptr
 isc_create_charset_manager_v2(const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues,
                               external::icu::ICU__Loader*                  const pIcuLoader,
                               const wchar_t*                               const pCsName__ODS)
{
 assert(pDsPropValues);
 assert(pIcuLoader);
 assert(pCsName__ODS);

 const t_ibp_string ctype_cn
  =Helper__GetCharsetName(pDsPropValues,ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__CTYPE);
  
 const t_ibp_string ctype_user
  =Helper__GetCharsetName(pDsPropValues,ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__CTYPE_USER);

 const t_ibp_string ctype_none
  =Helper__GetCharsetName(pDsPropValues,ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__CTYPE_NONE);

 //--------------
 const auto wchars_in_utf8_symbol
  =pDsPropValues->AUX__GetValue__long
   (ibprovider::IBP_DBPROPSET_INIT,
    ibprovider::IBP_DBPROP__INIT__WCHARS_IN_UTF8_SYMBOL);

 assert(wchars_in_utf8_symbol==1 ||
        wchars_in_utf8_symbol==2);

 //--------------
 const lib::structure::t_smart_object_ptr<ibp::t_ibp_charset_manager_v2>
  spCsMng
   (lib::structure::not_null_ptr
     (new ibp::t_ibp_charset_manager_v2
       (pIcuLoader,
        static_cast<BYTE>(wchars_in_utf8_symbol))));

 //--------------
 spCsMng->reg_cs_id_name
  (db_obj::db_cs_id::cn,
   ctype_cn);

 spCsMng->reg_cs_id_name
  (db_obj::db_cs_id::user,
   ctype_user);

 spCsMng->reg_cs_id_name
  (db_obj::db_cs_id::none,
   ctype_none);

 spCsMng->reg_cs_id_name
  (db_obj::db_cs_id::ods,
   pCsName__ODS);

 //--------------
 return spCsMng.not_null_ptr();
}//isc_create_charset_manager_v2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
