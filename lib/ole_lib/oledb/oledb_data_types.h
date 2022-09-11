////////////////////////////////////////////////////////////////////////////////
//OLEDB Data Types
//                                                Kovalenko Dmitry. 27.10.2008.
#ifndef _oledb_data_types_H_
#define _oledb_data_types_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/t_value_with_null.h>
#include <ole_lib/ole_ptr_std.h>
#include <oledb.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

enum t_oledb_typeid
{
 // The following values exactly match VARENUM
 // in Automation and may be used in VARIANT.

 /*    0*/ oledb_typeid__EMPTY            = DBTYPE_EMPTY,
 /*    1*/ oledb_typeid__NULL             = DBTYPE_NULL,
 /*    2*/ oledb_typeid__I2               = DBTYPE_I2,
 /*    3*/ oledb_typeid__I4               = DBTYPE_I4,
 /*    4*/ oledb_typeid__R4               = DBTYPE_R4,
 /*    5*/ oledb_typeid__R8               = DBTYPE_R8,
 /*    6*/ oledb_typeid__CY               = DBTYPE_CY,
 /*    7*/ oledb_typeid__DATE             = DBTYPE_DATE,
 /*    8*/ oledb_typeid__BSTR             = DBTYPE_BSTR,
 /*    9*/ oledb_typeid__IDISPATCH        = DBTYPE_IDISPATCH,
 /*   10*/ oledb_typeid__ERROR            = DBTYPE_ERROR,
 /*   11*/ oledb_typeid__BOOL             = DBTYPE_BOOL,
 /*   12*/ oledb_typeid__VARIANT          = DBTYPE_VARIANT,
 /*   13*/ oledb_typeid__IUNKNOWN         = DBTYPE_IUNKNOWN,
 /*   14*/ oledb_typeid__DECIMAL          = DBTYPE_DECIMAL,

 /*   16*/ oledb_typeid__I1               = DBTYPE_I1,
 /*   17*/ oledb_typeid__UI1              = DBTYPE_UI1,
 /*   18*/ oledb_typeid__UI2              = DBTYPE_UI2,
 /*   19*/ oledb_typeid__UI4              = DBTYPE_UI4,

 // The following values exactly match VARENUM
 // in Automation but cannot be used in VARIANT.

 /*   20*/ oledb_typeid__I8               = DBTYPE_I8,
 /*   21*/ oledb_typeid__UI8              = DBTYPE_UI8,

 /*   64*/ oledb_typeid__FILETIME         = DBTYPE_FILETIME,

 /*   72*/ oledb_typeid__GUID             = DBTYPE_GUID,

 // The following values are not in VARENUM in OLE.

 /*  128*/ oledb_typeid__BYTES            = DBTYPE_BYTES,
 /*  129*/ oledb_typeid__STR              = DBTYPE_STR,
 /*  130*/ oledb_typeid__WSTR             = DBTYPE_WSTR,
 /*  131*/ oledb_typeid__NUMERIC          = DBTYPE_NUMERIC,
 /*  132*/ oledb_typeid__UDT              = DBTYPE_UDT,
 /*  133*/ oledb_typeid__DBDATE           = DBTYPE_DBDATE,
 /*  134*/ oledb_typeid__DBTIME           = DBTYPE_DBTIME,
 /*  135*/ oledb_typeid__DBTIMESTAMP      = DBTYPE_DBTIMESTAMP,
 /*  136*/ oledb_typeid__HCHAPTER         = DBTYPE_HCHAPTER,

 /*  138*/ oledb_typeid__PROPVARIANT      = DBTYPE_PROPVARIANT,
 /*  139*/ oledb_typeid__VARNUMERIC       = DBTYPE_VARNUMERIC,

 /*  145*/ oledb_typeid__DBTIME2          = 145, //introduced in MSSQL 2008

 /*x1000*/ oledb_typeid__VECTOR           = DBTYPE_VECTOR,
 /*x2000*/ oledb_typeid__ARRAY            = DBTYPE_ARRAY,
 /*x4000*/ oledb_typeid__BYREF            = DBTYPE_BYREF,
 /*x8000*/ oledb_typeid__RESERVED         = DBTYPE_RESERVED,

 /* ---------------------------------------------------------------------- */
 oledb_typeid__ARRAY_I2                   = oledb_typeid__ARRAY|oledb_typeid__I2,
 oledb_typeid__ARRAY_I4                   = oledb_typeid__ARRAY|oledb_typeid__I4,
 oledb_typeid__ARRAY_R4                   = oledb_typeid__ARRAY|oledb_typeid__R4,
 oledb_typeid__ARRAY_R8                   = oledb_typeid__ARRAY|oledb_typeid__R8,
 oledb_typeid__ARRAY_CY                   = oledb_typeid__ARRAY|oledb_typeid__CY,
 oledb_typeid__ARRAY_DATE                 = oledb_typeid__ARRAY|oledb_typeid__DATE,
 oledb_typeid__ARRAY_BSTR                 = oledb_typeid__ARRAY|oledb_typeid__BSTR,
 oledb_typeid__ARRAY_IDISPATCH            = oledb_typeid__ARRAY|oledb_typeid__IDISPATCH,
 oledb_typeid__ARRAY_ERROR                = oledb_typeid__ARRAY|oledb_typeid__ERROR,
 oledb_typeid__ARRAY_BOOL                 = oledb_typeid__ARRAY|oledb_typeid__BOOL,
 oledb_typeid__ARRAY_VARIANT              = oledb_typeid__ARRAY|oledb_typeid__VARIANT,
 oledb_typeid__ARRAY_IUNKNOWN             = oledb_typeid__ARRAY|oledb_typeid__IUNKNOWN,
 oledb_typeid__ARRAY_DECIMAL              = oledb_typeid__ARRAY|oledb_typeid__DECIMAL,

 oledb_typeid__ARRAY_I1                   = oledb_typeid__ARRAY|oledb_typeid__I1,
 oledb_typeid__ARRAY_UI1                  = oledb_typeid__ARRAY|oledb_typeid__UI1,
 oledb_typeid__ARRAY_UI2                  = oledb_typeid__ARRAY|oledb_typeid__UI2,
 oledb_typeid__ARRAY_UI4                  = oledb_typeid__ARRAY|oledb_typeid__UI4,

 oledb_typeid__ARRAY_I8                   = oledb_typeid__ARRAY|oledb_typeid__I8,
 oledb_typeid__ARRAY_UI8                  = oledb_typeid__ARRAY|oledb_typeid__UI8,

 oledb_typeid__ARRAY_FILETIME             = oledb_typeid__ARRAY|oledb_typeid__FILETIME,

 oledb_typeid__ARRAY_GUID                 = oledb_typeid__ARRAY|oledb_typeid__GUID,

 oledb_typeid__ARRAY_BYTES                = oledb_typeid__ARRAY|oledb_typeid__BYTES,
 oledb_typeid__ARRAY_STR                  = oledb_typeid__ARRAY|oledb_typeid__STR,
 oledb_typeid__ARRAY_WSTR                 = oledb_typeid__ARRAY|oledb_typeid__WSTR,   
 oledb_typeid__ARRAY_NUMERIC              = oledb_typeid__ARRAY|oledb_typeid__NUMERIC,

 oledb_typeid__ARRAY_DBDATE               = oledb_typeid__ARRAY|oledb_typeid__DBDATE,
 oledb_typeid__ARRAY_DBTIME               = oledb_typeid__ARRAY|oledb_typeid__DBTIME,
 oledb_typeid__ARRAY_DBTIMESTAMP          = oledb_typeid__ARRAY|oledb_typeid__DBTIMESTAMP,

 oledb_typeid__ARRAY_DBTIME2              = oledb_typeid__ARRAY|oledb_typeid__DBTIME2,
};//enum t_oledb_typeid

////////////////////////////////////////////////////////////////////////////////

typedef signed char                    t_oledb_value__I1;

typedef signed __int16                 t_oledb_value__I2;

typedef signed __int32                 t_oledb_value__I4;

typedef signed __int64                 t_oledb_value__I8;

typedef LARGE_INTEGER                  t_oledb_value__I8_s;

typedef unsigned char                  t_oledb_value__UI1;

typedef unsigned __int16               t_oledb_value__UI2;

typedef unsigned __int32               t_oledb_value__UI4;

typedef unsigned __int64               t_oledb_value__UI8;

typedef ULARGE_INTEGER                 t_oledb_value__UI8_s;

typedef float                          t_oledb_value__R4;

typedef double                         t_oledb_value__R8;

typedef signed long                    t_oledb_value__LONG;

typedef unsigned long                  t_oledb_value__ULONG;

typedef tagCY                          t_oledb_value__CY;

typedef tagDEC                         t_oledb_value__DECIMAL;

typedef DB_NUMERIC                     t_oledb_value__NUMERIC;

typedef DATE                           t_oledb_value__DATE;

typedef DBDATE                         t_oledb_value__DBDATE;

typedef DBTIME                         t_oledb_value__DBTIME;

typedef DBTIMESTAMP                    t_oledb_value__DBTIMESTAMP;

typedef FILETIME                       t_oledb_value__FILETIME;

typedef SCODE                          t_oledb_value__SCODE;

typedef GUID                           t_oledb_value__GUID;

typedef char                           t_oledb_value__CHAR;

typedef wchar_t                        t_oledb_value__WCHAR;

typedef ole_lib::IPtr2<IUnknown>       t_oledb_value__CPP_IUNKNOWN;

typedef ole_lib::IPtr2<IDispatch>      t_oledb_value__CPP_IDISPATCH;

typedef DBLENGTH                       t_oledb_value__DBLENGTH;

typedef DBORDINAL                      t_oledb_value__DBORDINAL;

////////////////////////////////////////////////////////////////////////////////
//DBTYPE2

//Was introduced in MSSQL 2008.

#include <structure/t_comp_push_pack8.h>    // 8-byte structure packing

struct tag_oledb_value__DBTIME2
{
 USHORT hour;
 USHORT minute;
 USHORT second;
 ULONG  fraction; //Nano-Seconds: 0..999 999 999
};//struct tag_oledb_value__DBTIME2

typedef tag_oledb_value__DBTIME2       t_oledb_value__DBTIME2;

#include <structure/t_comp_pop_pack.h>      // restore original structure packing

////////////////////////////////////////////////////////////////////////////////

typedef __STL_DEF_BASIC_STRING(t_oledb_value__CHAR)
 t_oledb_value__CPP_STR;

//------------------------------------------------------------------------
typedef __STL_DEF_BASIC_STRING(t_oledb_value__WCHAR)
 t_oledb_value__CPP_WSTR;

//------------------------------------------------------------------------
typedef ole_lib::TBSTR
 t_oledb_value__CPP_BSTR;

//------------------------------------------------------------------------
typedef bool
 t_oledb_value__CPP_BOOL;

////////////////////////////////////////////////////////////////////////////////

typedef structure::t_value_with_null<t_oledb_value__I1>
 t_oledb_value__I1_n;

typedef structure::t_value_with_null<t_oledb_value__I2>
 t_oledb_value__I2_n;

typedef structure::t_value_with_null<t_oledb_value__I4>
 t_oledb_value__I4_n;

typedef structure::t_value_with_null<t_oledb_value__I8>
 t_oledb_value__I8_n;

typedef structure::t_value_with_null<t_oledb_value__I8_s>
 t_oledb_value__I8_s_n;

typedef structure::t_value_with_null<t_oledb_value__UI1>
 t_oledb_value__UI1_n;

typedef structure::t_value_with_null<t_oledb_value__UI2>
 t_oledb_value__UI2_n;

typedef structure::t_value_with_null<t_oledb_value__UI4>
 t_oledb_value__UI4_n;

typedef structure::t_value_with_null<t_oledb_value__UI8>
 t_oledb_value__UI8_n;

typedef structure::t_value_with_null<t_oledb_value__UI8_s>
 t_oledb_value__UI8_s_n;

typedef structure::t_value_with_null<t_oledb_value__R4>
 t_oledb_value__R4_n;

typedef structure::t_value_with_null<t_oledb_value__R8>
 t_oledb_value__R8_n;

typedef structure::t_value_with_null<t_oledb_value__LONG>
 t_oledb_value__LONG_n;

typedef structure::t_value_with_null<t_oledb_value__ULONG>
 t_oledb_value__ULONG_n;

typedef structure::t_value_with_null<t_oledb_value__CY>
 t_oledb_value__CY_n;

typedef structure::t_value_with_null<t_oledb_value__DECIMAL>
 t_oledb_value__DECIMAL_n;

typedef structure::t_value_with_null<t_oledb_value__NUMERIC>
 t_oledb_value__NUMERIC_n;

typedef structure::t_value_with_null<t_oledb_value__DATE>
 t_oledb_value__DATE_n;

typedef structure::t_value_with_null<t_oledb_value__DBDATE>
 t_oledb_value__DBDATE_n;

typedef structure::t_value_with_null<t_oledb_value__DBTIME>
 t_oledb_value__DBTIME_n;

typedef structure::t_value_with_null<t_oledb_value__DBTIME2>
 t_oledb_value__DBTIME2_n;

typedef structure::t_value_with_null<t_oledb_value__DBTIMESTAMP>
 t_oledb_value__DBTIMESTAMP_n;

typedef structure::t_value_with_null<t_oledb_value__FILETIME>
 t_oledb_value__FILETIME_n;

typedef structure::t_value_with_null<t_oledb_value__SCODE>
 t_oledb_value__SCODE_n;

typedef structure::t_value_with_null<t_oledb_value__GUID>
 t_oledb_value__GUID_n;

typedef structure::t_value_with_null<t_oledb_value__CPP_STR>
 t_oledb_value__CPP_STR_n;

typedef structure::t_value_with_null<t_oledb_value__CPP_WSTR>
 t_oledb_value__CPP_WSTR_n;

typedef structure::t_value_with_null<t_oledb_value__CPP_BSTR>
 t_oledb_value__CPP_BSTR_n;

typedef structure::t_value_with_null<t_oledb_value__CPP_BOOL>
 t_oledb_value__CPP_BOOL_n;

typedef structure::t_value_with_null<t_oledb_value__CPP_IUNKNOWN>
 t_oledb_value__CPP_IUNKNOWN_n;

typedef structure::t_value_with_null<t_oledb_value__CPP_IDISPATCH>
 t_oledb_value__CPP_IDISPATCH_n;

typedef structure::t_value_with_null<t_oledb_value__DBLENGTH>
 t_oledb_value__DBLENGTH_n;

typedef structure::t_value_with_null<t_oledb_value__DBORDINAL>
 t_oledb_value__DBORDINAL_n;

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
