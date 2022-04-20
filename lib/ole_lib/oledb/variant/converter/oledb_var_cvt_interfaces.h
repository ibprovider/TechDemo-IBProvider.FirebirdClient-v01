////////////////////////////////////////////////////////////////////////////////
//Declaration of dbtype converters interfaces and maps
//                                                     Roman Piminov, 07.03.2008
#ifndef _oledb_var_cvt_interfaces_H_
#define _oledb_var_cvt_interfaces_H_

#ifndef _oledb_variant_H_
#include <ole_lib/oledb/variant/oledb_variant.h>
#endif

#include <ole_lib/oledb/variant/oledb_variant_cvt.h>

namespace oledb_lib{namespace oledb_lib_utils{
////////////////////////////////////////////////////////////////////////////////
//Type converters names

//tt - to type, ft - from type
#define OLEDB_TYPE_CONVERTER_INTERFACE_NAME(tt) DBTypeCvt__##tt

#define OLEDB_TYPE_CONVERTER_NAME(ft,tt)        t_oledb_type_cvt__##ft##__##tt

#define OLEDB_TYPE_CONVERTER_OBJ_NAME(ft,tt)    g_cvt__##ft##__##tt

////////////////////////////////////////////////////////////////////////////////

#define OLEDB_TYPE_CONVERTER_INTERFACE(TT)                             \
 oledb_lib::oledb_lib_utils::OLEDB_TYPE_CONVERTER_INTERFACE_NAME(TT)

////////////////////////////////////////////////////////////////////////////////
//Builder of type converter interface [v3]

#define DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_EX(TT,               \
                                                     RESULT_VALUE_TYPE,\
                                                     RESULT_TYPE)      \
struct OLEDB_TYPE_CONVERTER_INTERFACE_NAME(TT):                        \
 public TDBTypeConverter                                               \
{                                                                      \
 private:                                                              \
  typedef OLEDB_TYPE_CONVERTER_INTERFACE_NAME(TT)  self_type;          \
                                                                       \
 public:                                                               \
  typedef const TDBTypeConverterContext*           LPCCONVCONTEXT;     \
  typedef RESULT_VALUE_TYPE                        result_value_type;  \
  typedef RESULT_TYPE                              result_type;        \
                                                                       \
  HRESULT to_##TT(LPCCONVCONTEXT            pConvCtx,                  \
                  const DBVARIANT&          dbvar,                     \
                  result_type*              result)const;              \
                                                                       \
 private:                                                              \
  virtual HRESULT internal__convert_value_to_##TT                      \
                    (LPCCONVCONTEXT            pConvCtx,               \
                     const DBVARIANT&          dbvar,                  \
                     result_type*              result)const=0;         \
 protected:                                                            \
  static HRESULT helper__convert_null_to_##TT                          \
                    (result_type* result);                             \
};

#define DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3(TT,TARGET_TYPE)      \
 DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_EX(TT,                      \
                                              TARGET_TYPE,             \
                                              TARGET_TYPE)

#define DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(TT,RESULT_TYPE)    \
 DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_EX(TT,                      \
                                              RESULT_TYPE::value_type, \
                                              RESULT_TYPE)

////////////////////////////////////////////////////////////////////////////////
//Types convertors interfaces definition

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(error       ,t_oledb_value__SCODE_n)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(i1          ,t_oledb_value__I1_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(i2          ,t_oledb_value__I2_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(i4          ,t_oledb_value__I4_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(i8          ,t_oledb_value__I8_n)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(ui1         ,t_oledb_value__UI1_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(ui2         ,t_oledb_value__UI2_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(ui4         ,t_oledb_value__UI4_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(ui8         ,t_oledb_value__UI8_n)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(r4          ,t_oledb_value__R4_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(r8          ,t_oledb_value__R8_n)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(cy          ,t_oledb_value__CY_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(decimal     ,t_oledb_value__DECIMAL_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(numeric     ,t_oledb_value__NUMERIC_n)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(date        ,t_oledb_value__DATE_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(filetime    ,t_oledb_value__FILETIME_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(dbdate      ,t_oledb_value__DBDATE_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(dbtime      ,t_oledb_value__DBTIME_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(dbtime2     ,t_oledb_value__DBTIME2_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(dbtimestamp ,t_oledb_value__DBTIMESTAMP_n)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(str         ,t_oledb_value__CPP_STR_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(wstr        ,t_oledb_value__CPP_WSTR_n)
DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(bstr        ,t_oledb_value__CPP_BSTR_n)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(bool        ,t_oledb_value__CPP_BOOL_n)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(guid        ,t_oledb_value__GUID_n)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3(bytes         ,DBVARIANT_BYTES_WRITER)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3(variant       ,VARIANT)

DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N(idispatch   ,t_oledb_value__CPP_IDISPATCH_n)

//------------------------------------------------------------------------
#undef DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_EX
#undef DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3
#undef DECLARE_OLEDB_TYPE_CONVERTER_INTERFACE_V3_N

////////////////////////////////////////////////////////////////////////////////
//class to_iunknown

struct OLEDB_TYPE_CONVERTER_INTERFACE_NAME(iunknown):public TDBTypeConverter
{
 public: //typedefs
  typedef const TDBTypeConverterContext*          LPCCONVCONTEXT;
  typedef t_oledb_value__CPP_IUNKNOWN_n           result_type;
  typedef result_type::value_type                 result_value_type;

 public:
  HRESULT to_iunknown(LPCCONVCONTEXT    pConvCtx,
                      const DBVARIANT&  dbvar,
                      REFIID            result_iid,
                      result_type*      result)const;

 private:
  virtual HRESULT internal__convert_value_to_iunknown
                    (LPCCONVCONTEXT     pConvCtx,
                     const DBVARIANT&   dbvar,
                     REFIID             result_iid,
                     result_type*       result)const=0;

 protected:
  static HRESULT helper__convert_null_to_iunknown
                    (result_type* result);
};//struct converter to iunknown

////////////////////////////////////////////////////////////////////////////////
//class to_array

struct OLEDB_TYPE_CONVERTER_INTERFACE_NAME(array):public TDBTypeConverter
{
 public: //typedefs
  typedef const TDBTypeConverterContext*          LPCCONVCONTEXT;
  typedef SAFEARRAY*                              result_value_type;
  typedef SAFEARRAY*                              result_type;

 public:
  HRESULT to_array(LPCCONVCONTEXT    pConvCtx,
                   const DBVARIANT&  dbvar,
                   REFIID            result_iid,
                   result_type*      result)const;

 private:
  virtual HRESULT internal__convert_value_to_array
                    (LPCCONVCONTEXT     pConvCtx,
                     const DBVARIANT&   dbvar,
                     REFIID             result_iid,
                     result_type*       result)const=0;

 protected:
  static HRESULT helper__convert_null_to_array
                    (result_type* result);
};//struct converter to array

////////////////////////////////////////////////////////////////////////////////

#define DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ft)                          \
extern const DBVARIANT::TTypeConverterMap g_oledb_cvt_maps_for_##ft;

//------------------------------------------------------------------------
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(EMPTY)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(NULL)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ERROR)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(BOOL)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(VARIANT)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(I1)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(I2)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(I4)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(I8)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(UI1)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(UI2)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(UI4)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(UI8)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(R4)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(R8)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(CY)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(DECIMAL)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(NUMERIC)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(STR)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(WSTR)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(BSTR)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(DATE)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(DBDATE)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(DBTIME)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(DBTIME2)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(DBTIMESTAMP)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(FILETIME)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(BYTES)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(GUID)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(IUNKNOWN)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(IDISPATCH)

//------------------------------------------------------------------------
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_I1)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_I2)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_I4)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_I8)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_UI1)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_UI2)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_UI4)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_UI8)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_R4)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_R8)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_CY)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_DECIMAL)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_NUMERIC)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_BOOL)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_ERROR)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_VARIANT)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_DATE)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_DBDATE)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_DBTIME)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_DBTIME2)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_DBTIMESTAMP)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_FILETIME)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_GUID)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_STR)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_WSTR)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_BSTR)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_BYTES)

DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_IUNKNOWN)
DECLARE_OLEDB_TYPE_CONVERTERS_MAP(ARRAY_IDISPATCH)

//------------------------------------------------------------------------
#undef DECLARE_OLEDB_TYPE_CONVERTERS_MAP

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb_lib_utils*/}/*nms oledb_lib*/
#endif
