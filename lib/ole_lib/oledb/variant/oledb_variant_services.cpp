////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/oledb_variant_services.h>
#include <ole_lib/oledb/variant/converter/oledb_var_cvt_interfaces.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt_routers.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt_utils.h>
#include <ole_lib/oledb/variant/oledb_xvariant_stream_writer.h>
#include <ole_lib/oledb/oledb_datetime_services.h>
#include <ole_lib/ole_auto/ole_auto_variant.h>
#include <structure/t_numeric_cast.h>
#include <structure/t_str_args_traits.h>
#include <structure/t_zero.h>
#include <structure/utilities/to_hex.h>

namespace oledb_lib{namespace oledb_lib_utils{
////////////////////////////////////////////////////////////////////////////////
//helper macros

//----------------
#define DEFINE_OLEDB_TYPE_SERVICE_OBJ(dbtype)                                    \
t_oledb_type_service_##dbtype g_service_##dbtype;

//----------------
#define DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(dbtype)                              \
const t_oledb_type_service_ARRAY_##dbtype g_service_ARRAY_##dbtype;

//----------------
#define DEFINE_OLEDB_TYPE_SERVICE_GET_ALIGN(dbtype)                              \
t_oledb_type_service_##dbtype::length_type                                       \
t_oledb_type_service_##dbtype::get_align()const                                  \
{                                                                                \
 assert(this->get_type()==oledb_lib::oledb_typeid__##dbtype);                    \
                                                                                 \
 return __alignof(value_type);                                                   \
}

//----------------
#define DEFINE_OLEDB_TYPE_SERVICE_GET_LENGTH(dbtype)                             \
t_oledb_type_service_##dbtype::length_type                                       \
t_oledb_type_service_##dbtype::internal__get_length__ok(const DBVARIANT& DEBUG_CODE(dbvar))const \
{                                                                                \
 assert(this->get_type()==oledb_lib::oledb_typeid__##dbtype);                    \
 assert(dbvar.wType==this->get_type());                                          \
 assert(dbvar.TestDataStatus__IsOK());                                           \
                                                                                 \
 return sizeof(value_type);                                                      \
}

//----------------
#define DEFINE_OLEDB_TYPE_SERVICE_GET_BINARY_LENGTH(dbtype)                      \
t_oledb_type_service_##dbtype::length_type                                       \
t_oledb_type_service_##dbtype::get_binary_length(length_type)const               \
{                                                                                \
 assert(this->get_type()==oledb_lib::oledb_typeid__##dbtype);                    \
                                                                                 \
 return sizeof(value_type);                                                      \
}

//----------------
#define DEFINE_OLEDB_TYPE_SERVICE_GET_SIZE(dbtype)                               \
void t_oledb_type_service_##dbtype::internal__get_size__ok                       \
                                           (const DBVARIANT&  DEBUG_CODE(dbvar), \
                                            length_type&      cbSize,            \
                                            length_type&      cbMemSize,         \
                                            length_type&      cbMinSize)const    \
{                                                                                \
 assert(this->get_type()==oledb_lib::oledb_typeid__##dbtype);                    \
 assert(dbvar.wType==this->get_type());                                          \
 assert(dbvar.TestDataStatus__IsOK());                                           \
                                                                                 \
 cbSize=cbMemSize=cbMinSize=sizeof(value_type);                                  \
}

//----------------
#define DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(dbtype)                          \
DBVARIANT::LPCTYPECONVERTER                                                      \
t_oledb_type_service_##dbtype::get_convertor(DBTYPE const TargetType)const       \
{                                                                                \
 return g_oledb_cvt_maps_for_##dbtype.get_convertor(TargetType);                 \
}

////////////////////////////////////////////////////////////////////////////////

#include "ole_lib/oledb/variant/services/oledb_var_service__empty.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__null.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__ui1.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__ui2.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__ui4.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__ui8.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__i1.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__i2.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__i4.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__i8.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__cy.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__r4.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__r8.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__numeric.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__decimal.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__bool.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__error.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__variant.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__date.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__dbdate.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__dbtime.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__dbtime2.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__dbtimestamp.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__bstr.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__str.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__wstr.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__bytes.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__filetime.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__guid.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__iunknown.cxx"

#include "ole_lib/oledb/variant/services/oledb_var_service__idispatch.cxx"

////////////////////////////////////////////////////////////////////////////////
//ARRAY

#include "ole_lib/oledb/variant/services/oledb_var_service__array.cxx"

////////////////////////////////////////////////////////////////////////////////
//ARRAY

//define service objects -------------------------------------------------
//DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(EMPTY       )
//DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(NULL        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(UI1         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(UI2         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(UI4         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(UI8         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(I1          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(I2          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(I4          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(I8          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(CY          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(R4          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(R8          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(NUMERIC     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(DECIMAL     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(BOOL        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(ERROR       )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(VARIANT     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(DATE        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(DBDATE      )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(DBTIME      )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(DBTIME2     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(DBTIMESTAMP )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(BSTR        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(STR         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(WSTR        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(BYTES       )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(FILETIME    )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(GUID        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(IUNKNOWN    )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ(IDISPATCH   )

////////////////////////////////////////////////////////////////////////////////
//Custom implementation of get_length for several array element data types

//ARRAY_EMPTY ------------------------------------------------------------
t_oledb_type_service_ARRAY_EMPTY::length_type
 t_oledb_type_service_ARRAY_EMPTY::internal__get_length__ok(const DBVARIANT& DEBUG_CODE(dbvar))const
{
 assert(this->get_type()==(element_dbtype|DBTYPE_ARRAY));
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 return 0;
}//ARRAY_EMPTY::internal__get_length__ok

//ARRAY_NULL -------------------------------------------------------------
t_oledb_type_service_ARRAY_NULL::length_type
 t_oledb_type_service_ARRAY_NULL::internal__get_length__ok(const DBVARIANT& DEBUG_CODE(dbvar))const
{
 assert(this->get_type()==(element_dbtype|DBTYPE_ARRAY));
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 return 0;
}//ARRAY_NULL::internal__get_length__ok

////////////////////////////////////////////////////////////////////////////////
//GENERIC ARRAY_xxx::get_length definitions

#define DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(dbtype)                    \
                                                                              \
t_oledb_type_service_ARRAY_##dbtype::length_type                              \
 t_oledb_type_service_ARRAY_##dbtype::internal__get_length__ok(const DBVARIANT& DEBUG_CODE(dbvar))const \
{                                                                             \
 assert(this->get_type()==(element_dbtype|DBTYPE_ARRAY));                     \
 assert(dbvar.wType==this->get_type());                                       \
 assert(dbvar.TestDataStatus__IsOK());                                        \
                                                                              \
 DEBUG_CODE                                                                   \
 (                                                                            \
  if(dbvar.arrayVal2.ptr!=NULL)                                               \
  {                                                                           \
   const UINT x=LCPI_OS__SafeArrayGetElemsize(dbvar.arrayVal2.ptr);           \
                                                                              \
   assert_msg(x==sizeof(element_type),                                        \
              "Elemsize="<<x<<"\n"                                            \
              "sizeof  ="<<sizeof(element_type));                             \
  }                                                                           \
 )                                                                            \
                                                                              \
 return sizeof(element_type);                                                 \
}

////////////////////////////////////////////////////////////////////////////////
//t_oledb_type_service_ARRAY_xxx::get_length for simple types

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(UI1         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(UI2         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(UI4         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(UI8         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(I1          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(I2          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(I4          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(I8          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(CY          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(R4          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(R8          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(NUMERIC     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(DECIMAL     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(BOOL        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(ERROR       )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(VARIANT     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(DATE        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(DBDATE      )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(DBTIME      )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(DBTIME2     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(DBTIMESTAMP )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(BSTR        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(FILETIME    )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(GUID        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(IUNKNOWN    )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH(IDISPATCH   )

////////////////////////////////////////////////////////////////////////////////

#define DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(dbtype)             \
                                                                              \
t_oledb_type_service_ARRAY_##dbtype::length_type                              \
 t_oledb_type_service_ARRAY_##dbtype::get_binary_length(length_type x)const   \
{                                                                             \
 assert(this->get_type()==(element_dbtype|DBTYPE_ARRAY));                     \
                                                                              \
 return g_service_##dbtype.get_binary_length(x);                              \
}

//------------------------------------------------------------------------
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(EMPTY       )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(NULL        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(UI1         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(UI2         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(UI4         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(UI8         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(I1          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(I2          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(I4          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(I8          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(CY          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(R4          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(R8          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(NUMERIC     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(DECIMAL     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(BOOL        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(ERROR       )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(VARIANT     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(DATE        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(DBDATE      )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(DBTIME      )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(DBTIME2     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(DBTIMESTAMP )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(BSTR        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(STR         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(WSTR        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(BYTES       )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(FILETIME    )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(GUID        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(IUNKNOWN    )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH(IDISPATCH   )

////////////////////////////////////////////////////////////////////////////////
//ARRAY_STR

t_oledb_type_service_ARRAY_STR::length_type
 t_oledb_type_service_ARRAY_STR::internal__get_length__ok(const DBVARIANT& dbvar)const
{
 assert(this->get_type()==(element_dbtype|DBTYPE_ARRAY));
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 if(dbvar.arrayVal2.ptr==NULL)
  return 0;

 return LCPI_OS__SafeArrayGetElemsize(dbvar.arrayVal2.ptr)/sizeof(element_type);
}//ARRAY_STR::internal__get_length__ok

////////////////////////////////////////////////////////////////////////////////
//ARRAY_WSTR

t_oledb_type_service_ARRAY_WSTR::length_type
 t_oledb_type_service_ARRAY_WSTR::internal__get_length__ok(const DBVARIANT& dbvar)const
{
 assert(this->get_type()==(element_dbtype|DBTYPE_ARRAY));
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 if(dbvar.arrayVal2.ptr==NULL)
  return 0;

 return LCPI_OS__SafeArrayGetElemsize(dbvar.arrayVal2.ptr)/sizeof(element_type);
}//ARRAY_WSTR::internal__get_length__ok

////////////////////////////////////////////////////////////////////////////////
//ARRAY_BYTES

t_oledb_type_service_ARRAY_BYTES::length_type
 t_oledb_type_service_ARRAY_BYTES::internal__get_length__ok(const DBVARIANT& dbvar)const
{
 assert(this->get_type()==(element_dbtype|DBTYPE_ARRAY));
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 if(dbvar.arrayVal2.ptr==NULL)
  return 0;

 return LCPI_OS__SafeArrayGetElemsize(dbvar.arrayVal2.ptr)/sizeof(element_type);
}//ARRAY_BYTES::internal__get_length__ok

////////////////////////////////////////////////////////////////////////////////
//GENERIC ARRAY_xxx::get_convertor definitions

#define DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(dbtype)                 \
                                                                              \
t_oledb_type_service_ARRAY_##dbtype::LPCTYPECONVERTER                         \
 t_oledb_type_service_ARRAY_##dbtype::get_convertor(DBTYPE TargetType)const   \
{                                                                             \
 return g_oledb_cvt_maps_for_ARRAY_##dbtype.get_convertor(TargetType);        \
}

//------------------------------------------------------------------------
#define DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR_NONE(dbtype)             \
                                                                               \
t_oledb_type_service_ARRAY_##dbtype::LPCTYPECONVERTER                          \
 t_oledb_type_service_ARRAY_##dbtype::get_convertor(DBTYPE /*TargetType*/)const\
{                                                                              \
 return nullptr;                                                                  \
}

//------------------------------------------------------------------------
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR_NONE(EMPTY       )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR_NONE(NULL        )

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(UI1         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(UI2         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(UI4         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(UI8         )

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(I1          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(I2          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(I4          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(I8          )

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(CY          )

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(R4          )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(R8          )

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(NUMERIC     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(DECIMAL     )

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(BOOL        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(ERROR       )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(VARIANT     )

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(DATE        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(DBDATE      )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(DBTIME      )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(DBTIME2     )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(DBTIMESTAMP )

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(BSTR        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(STR         )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(WSTR        )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(BYTES       )

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(FILETIME    )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(GUID        )

DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(IUNKNOWN    )
DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR(IDISPATCH   )

////////////////////////////////////////////////////////////////////////////////
#undef DEFINE_OLEDB_TYPE_SERVICE_OBJ
#undef DEFINE_OLEDB_ARRAY_TYPE_SERVICE_OBJ
#undef DEFINE_OLEDB_TYPE_SERVICE_GET_SIZE
#undef DEFINE_OLEDB_TYPE_SERVICE_GET_BINARY_LENGTH
#undef DEFINE_OLEDB_TYPE_SERVICE_GET_LENGTH
#undef DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_LENGTH
#undef DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_BINARY_LENGTH
#undef DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR
#undef DEFINE_OLEDB_ARRAY_TYPE_SERVICE_GET_CONVERTOR_NONE
////////////////////////////////////////////////////////////////////////////////
}/*nms oledb_lib_utils*/}//nms oledb_lib
