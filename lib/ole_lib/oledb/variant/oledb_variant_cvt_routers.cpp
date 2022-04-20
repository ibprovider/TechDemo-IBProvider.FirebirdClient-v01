////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/oledb_variant_cvt_routers.h>
#include <ole_lib/oledb/variant/converter/oledb_var_cvt_interfaces.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//TO ERROR

HRESULT DBVariant__to_ERROR_ex(DBVARIANT::LPCCONVCONTEXT      pCvtContext,
                               const DBVARIANT&               Source,
                               t_oledb_value__SCODE_n*        pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(error)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_ERROR)))
 {
  return pConverter->to_error(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//to_error_ex

////////////////////////////////////////////////////////////////////////////////
//TO I1

HRESULT DBVariant__to_I1_ex(DBVARIANT::LPCCONVCONTEXT      pCvtContext,
                            const DBVARIANT&               Source,
                            t_oledb_value__I1_n*           pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(i1)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_I1)))
 {
  return pConverter->to_i1(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_I1_ex

////////////////////////////////////////////////////////////////////////////////
//TO I2

HRESULT DBVariant__to_I2_ex(DBVARIANT::LPCCONVCONTEXT      pCvtContext,
                            const DBVARIANT&               Source,
                            t_oledb_value__I2_n*           pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(i2)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_I2)))
 {
  return pConverter->to_i2(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_I2_ex

////////////////////////////////////////////////////////////////////////////////
//TO I4

HRESULT DBVariant__to_I4_ex(DBVARIANT::LPCCONVCONTEXT      pCvtContext,
                            const DBVARIANT&               Source,
                            t_oledb_value__I4_n*           pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(i4)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_I4)))
 {
  return pConverter->to_i4(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_I4_ex

////////////////////////////////////////////////////////////////////////////////
//TO I8

HRESULT DBVariant__to_I8_ex(DBVARIANT::LPCCONVCONTEXT      pCvtContext,
                            const DBVARIANT&               Source,
                            t_oledb_value__I8_n*           pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(i8)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_I8)))
 {
  return pConverter->to_i8(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_I8_ex

////////////////////////////////////////////////////////////////////////////////
//TO UI1

HRESULT DBVariant__to_UI1_ex(DBVARIANT::LPCCONVCONTEXT     pCvtContext,
                             const DBVARIANT&              Source,
                             t_oledb_value__UI1_n*         pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(ui1)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_UI1)))
 {
  return pConverter->to_ui1(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_UI1_ex

////////////////////////////////////////////////////////////////////////////////
//TO UI2

HRESULT DBVariant__to_UI2_ex(DBVARIANT::LPCCONVCONTEXT     pCvtContext,
                             const DBVARIANT&              Source,
                             t_oledb_value__UI2_n*         pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(ui2)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_UI2)))
 {
  return pConverter->to_ui2(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_UI2_ex

////////////////////////////////////////////////////////////////////////////////
//TO UI4

HRESULT DBVariant__to_UI4_ex(DBVARIANT::LPCCONVCONTEXT     pCvtContext,
                             const DBVARIANT&              Source,
                             t_oledb_value__UI4_n*         pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(ui4)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_UI4)))
 {
  return pConverter->to_ui4(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_UI4_ex

////////////////////////////////////////////////////////////////////////////////
//TO UI8

HRESULT DBVariant__to_UI8_ex(DBVARIANT::LPCCONVCONTEXT     pCvtContext,
                             const DBVARIANT&              Source,
                             t_oledb_value__UI8_n*         pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(ui8)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_UI8)))
 {
  return pConverter->to_ui8(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_UI8_ex

////////////////////////////////////////////////////////////////////////////////
//TO R4

HRESULT DBVariant__to_R4_ex(DBVARIANT::LPCCONVCONTEXT     pCvtContext,
                            const DBVARIANT&              Source,
                            DBVARIANT::value_r4_n_type*   pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(r4)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_R4)))
 {
  return pConverter->to_r4(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_R4_ex

////////////////////////////////////////////////////////////////////////////////
//TO R8

HRESULT DBVariant__to_R8_ex(DBVARIANT::LPCCONVCONTEXT     pCvtContext,
                            const DBVARIANT&              Source,
                            t_oledb_value__R8_n*          pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(r8)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_R8)))
 {
  return pConverter->to_r8(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_R8_ex

////////////////////////////////////////////////////////////////////////////////
//TO CY

HRESULT DBVariant__to_CY_ex(DBVARIANT::LPCCONVCONTEXT     pCvtContext,
                            const DBVARIANT&              Source,
                            t_oledb_value__CY_n*          pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(cy)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_CY)))
 {
  return pConverter->to_cy(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_CY_ex

////////////////////////////////////////////////////////////////////////////////
//TO NUMERIC

HRESULT DBVariant__to_NUMERIC_ex(DBVARIANT::LPCCONVCONTEXT        pCvtContext,
                                 const DBVARIANT&                 Source,
                                 t_oledb_value__NUMERIC_n*        pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(numeric)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_NUMERIC)))
 {
  return pConverter->to_numeric(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_NUMERIC_ex

////////////////////////////////////////////////////////////////////////////////
//TO DECIMAL

HRESULT DBVariant__to_DECIMAL_ex(DBVARIANT::LPCCONVCONTEXT        pCvtContext,
                                 const DBVARIANT&                 Source,
                                 t_oledb_value__DECIMAL_n*        pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(decimal)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_DECIMAL)))
 {
  return pConverter->to_decimal(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_DECIMAL_ex

////////////////////////////////////////////////////////////////////////////////
//to DATE

HRESULT DBVariant__to_DATE_ex(DBVARIANT::LPCCONVCONTEXT        pCvtContext,
                              const DBVARIANT&                 Source,
                              t_oledb_value__DATE_n*           pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(date)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_DATE)))
 {
  return pConverter->to_date(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_DATE_ex

////////////////////////////////////////////////////////////////////////////////
//to DBDATE

HRESULT DBVariant__to_DBDATE_ex(DBVARIANT::LPCCONVCONTEXT        pCvtContext,
                                const DBVARIANT&                 Source,
                                t_oledb_value__DBDATE_n*         pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(dbdate)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_DBDATE)))
 {
  return pConverter->to_dbdate(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_DBDATE_ex

////////////////////////////////////////////////////////////////////////////////
//to DBTIME

HRESULT DBVariant__to_DBTIME_ex(DBVARIANT::LPCCONVCONTEXT       pCvtContext,
                                const DBVARIANT&                Source,
                                t_oledb_value__DBTIME_n*        pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(dbtime)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_DBTIME)))
 {
  return pConverter->to_dbtime(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_DBTIME_ex

////////////////////////////////////////////////////////////////////////////////
//to DBTIME2

HRESULT DBVariant__to_DBTIME2_ex(DBVARIANT::LPCCONVCONTEXT const pCvtContext,
                                 const DBVARIANT&                Source,
                                 t_oledb_value__DBTIME2_n* const pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(dbtime2)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,oledb_typeid__DBTIME2)))
 {
  return pConverter->to_dbtime2(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_DBTIME2_ex

////////////////////////////////////////////////////////////////////////////////
//to DBTIMESTAMP

HRESULT DBVariant__to_DBTIMESTAMP_ex(DBVARIANT::LPCCONVCONTEXT        pCvtContext,
                                     const DBVARIANT&                 Source,
                                     t_oledb_value__DBTIMESTAMP_n*    pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(dbtimestamp)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_DBTIMESTAMP)))
 {
  return pConverter->to_dbtimestamp(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_DBTIMESTAMP_ex

////////////////////////////////////////////////////////////////////////////////
//to FILETIME

HRESULT DBVariant__to_FILETIME_ex(DBVARIANT::LPCCONVCONTEXT         pCvtContext,
                                  const DBVARIANT&                  Source,
                                  t_oledb_value__FILETIME_n*        pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(filetime)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_FILETIME)))
 {
  return pConverter->to_filetime(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_FILETIME_ex

////////////////////////////////////////////////////////////////////////////////
//TO STR

HRESULT DBVariant__to_STR_ex(DBVARIANT::LPCCONVCONTEXT            pCvtContext,
                             const DBVARIANT&                     Source,
                             t_oledb_value__CPP_STR_n*            pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(str)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_STR)))
 {
  return pConverter->to_str(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_STR_ex

////////////////////////////////////////////////////////////////////////////////
//TO WSTR

HRESULT DBVariant__to_WSTR_ex(DBVARIANT::LPCCONVCONTEXT          pCvtContext,
                              const DBVARIANT&                   Source,
                              t_oledb_value__CPP_WSTR_n*         pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(wstr)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_WSTR)))
 {
  return pConverter->to_wstr(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_WSTR_ex

////////////////////////////////////////////////////////////////////////////////
//TO BSTR

HRESULT DBVariant__to_BSTR_ex(DBVARIANT::LPCCONVCONTEXT          pCvtContext,
                              const DBVARIANT&                   Source,
                              t_oledb_value__CPP_BSTR_n*         pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(bstr)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_BSTR)))
 {
  return pConverter->to_bstr(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_BSTR_ex

////////////////////////////////////////////////////////////////////////////////
//TO BOOL

HRESULT DBVariant__to_BOOL_ex(DBVARIANT::LPCCONVCONTEXT           pCvtContext,
                              const DBVARIANT&                    Source,
                              t_oledb_value__CPP_BOOL_n*          pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(bool)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_BOOL)))
 {
  return pConverter->to_bool(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_BOOL_ex

////////////////////////////////////////////////////////////////////////////////
//TO GUID

HRESULT DBVariant__to_GUID_ex(DBVARIANT::LPCCONVCONTEXT          pCvtContext,
                              const DBVARIANT&                   Source,
                              t_oledb_value__GUID_n*             pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(guid)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_GUID)))
 {
  return pConverter->to_guid(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_GUID_ex

////////////////////////////////////////////////////////////////////////////////
//TO BYTES

HRESULT DBVariant__to_BYTES_ex(DBVARIANT::LPCCONVCONTEXT     const pCvtContext,
                               const DBVARIANT&                    Source,
                               DBVARIANT::bytes_writer_type* const pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(bytes)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_BYTES)))
 {
  return pConverter->to_bytes(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_BYTES_ex

////////////////////////////////////////////////////////////////////////////////
//TO VARIANT

HRESULT DBVariant__to_VARIANT_ex(DBVARIANT::LPCCONVCONTEXT        pCvtContext,
                                 const DBVARIANT&                 Source,
                                 VARIANT*                         pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(variant)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_VARIANT)))
 {
  HRESULT const hr=pConverter->to_variant(pCvtContext,Source,pResult);

  assert(hr==S_OK || hr==S_FALSE || FAILED(hr));

  assert(hr!=S_FALSE || pResult->vt==VT_NULL);

  return hr;
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_VARIANT_ex

////////////////////////////////////////////////////////////////////////////////
//TO IUNKNOWN

HRESULT DBVariant__to_IUNKNOWN_ex(DBVARIANT::LPCCONVCONTEXT         pCvtContext,
                                  const DBVARIANT&                  Source,
                                  REFIID                            ResultIID,
                                  t_oledb_value__CPP_IUNKNOWN_n*    pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(iunknown)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_IUNKNOWN)))
 {
  return pConverter->to_iunknown(pCvtContext,Source,ResultIID,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_IUNKNOWN_ex

////////////////////////////////////////////////////////////////////////////////
//TO IDISPATCH

HRESULT DBVariant__to_IDISPATCH_ex(DBVARIANT::LPCCONVCONTEXT         pCvtContext,
                                   const DBVARIANT&                  Source,
                                   t_oledb_value__CPP_IDISPATCH_n*   pResult)
{
 assert(pCvtContext);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(idispatch)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType,DBTYPE_IDISPATCH)))
 {
  return pConverter->to_idispatch(pCvtContext,Source,pResult);
 }

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_IDISPATCH_ex

////////////////////////////////////////////////////////////////////////////////

HRESULT DBVariant__to_ARRAY_ex(DBVARIANT::LPCCONVCONTEXT  const  pCvtContext,
                               const DBVARIANT&                  Source,
                               DBTYPE                     const  ArrayType,
                               REFIID                            ResultIID,
                               SAFEARRAY**                const  pResult)
{
 assert(pCvtContext);
 assert((ArrayType&DBTYPE_ARRAY)==DBTYPE_ARRAY);
 assert(pResult);

 typedef const OLEDB_TYPE_CONVERTER_INTERFACE(array)* cvt_ptr;

 if(cvt_ptr const pConverter
     =dynamic_cast<cvt_ptr>(pCvtContext->GetTypeConverter(Source.wType, ArrayType)))
 {
  return pConverter->to_array(pCvtContext,
                              Source,
                              ResultIID,
                              pResult);
 }//if

 return DB_E_UNSUPPORTEDCONVERSION;
}//DBVariant__to_ARRAY_ex

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
