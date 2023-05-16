////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_data_types.h
//! \brief   Определение типов данных
//! \author  Kovalenko Dmitry
//! \date    26.09.2015
#ifndef _db_data_types_H_
#define _db_data_types_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <ole_lib/oledb/oledb_data_types.h>

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//db-value types

///id: dbtype__i1
typedef signed char                         t_dbvalue__i1;

///id: dbtype__i2
typedef signed __int16                      t_dbvalue__i2;

///id: dbtype__i4
typedef signed __int32                      t_dbvalue__i4;

///id: dbtype__i8
typedef signed __int64                      t_dbvalue__i8;

///aliase for long
typedef signed long                         t_dbvalue__long;

///id: dbtype__ui1
typedef unsigned char                       t_dbvalue__ui1;

///id: dbtype__ui2
typedef unsigned __int16                    t_dbvalue__ui2;

///id: dbtype__ui4
typedef unsigned __int32                    t_dbvalue__ui4;

///id: dbtype__ui8
typedef unsigned __int64                    t_dbvalue__ui8;

///aliase for unsigned long
typedef unsigned long                       t_dbvalue__ulong;

///id: dbtype__r4
typedef float                               t_dbvalue__r4;

///id: dbtype__r8
typedef double                              t_dbvalue__r8;

///id: dbtype__vb_date
typedef DATE                                t_dbvalue__vb_date;

///id: dbtype__dbdate
typedef DBDATE                              t_dbvalue__oledb_dbdate;

///id: dbtype__dbtime2
typedef oledb_lib::t_oledb_value__DBTIME2   t_dbvalue__oledb_dbtime2;

///id: dbtype__timestamp
typedef DBTIMESTAMP                         t_dbvalue__oledb_dbtimestamp;

///id: dbtype__oledb_numeric
typedef DB_NUMERIC                          t_dbvalue__oledb_numeric;

///id: dbtype__cy
typedef tagCY                               t_dbvalue__cy;

///id: dbtype__decimal
typedef tagDEC                              t_dbvalue__decimal;

///id: dbtype__cpp_bool
typedef bool                                t_dbvalue__cpp_bool;

////////////////////////////////////////////////////////////////////////////////

extern const t_dbvalue__cpp_bool __null_dbvalue__cpp_bool;

////////////////////////////////////////////////////////////////////////////////

const long isc_time_seconds_precision=10000;

////////////////////////////////////////////////////////////////////////////////
//ISC_TIME, ISC_DATE, ISC_TIMESTAMP

typedef db_obj::t_dbvalue__i4               t_dbvalue__isc_date;

typedef db_obj::t_dbvalue__ui4              t_dbvalue__isc_time;

struct t_dbvalue__isc_timestamp
{
 t_dbvalue__isc_date  timestamp_date;
 t_dbvalue__isc_time  timestamp_time;

#ifdef IBP_BUILD_TESTCODE
 bool operator == (const t_dbvalue__isc_timestamp& x)const
 {
  return this->timestamp_date==x.timestamp_date && this->timestamp_time==x.timestamp_time;
 }

 bool operator != (const t_dbvalue__isc_timestamp& x)const
 {
  return !((*this)==x);
 }
#endif
};//struct t_dbvalue__isc_timestamp

////////////////////////////////////////////////////////////////////////////////
//ISC_NUMERIC_I2

///id: dbtype__isc_numeric_i2
struct t_dbvalue__isc_numeric_i2
{
 t_dbvalue__i2 data;
};//struct t_dbvalue__isc_numeric_i2

assert_s(sizeof(t_dbvalue__isc_numeric_i2)==sizeof(t_dbvalue__i2));

extern const t_dbvalue__isc_numeric_i2 __null_dbvalue__isc_numeric_i2;

////////////////////////////////////////////////////////////////////////////////
//ISC_NUMERIC_I4

///id: dbtype__isc_numeric_i4
struct t_dbvalue__isc_numeric_i4
{
 t_dbvalue__i4 data;
};//struct t_dbvalue__isc_numeric_i4

assert_s(sizeof(t_dbvalue__isc_numeric_i4)==sizeof(t_dbvalue__i4));

extern const t_dbvalue__isc_numeric_i4 __null_dbvalue__isc_numeric_i4;

////////////////////////////////////////////////////////////////////////////////
//ISC_NUMERIC_I8

///id: dbtype__isc_numeric_i8
struct t_dbvalue__isc_numeric_i8
{
 t_dbvalue__i8 data;
};//struct t_dbvalue__isc_numeric_i8

assert_s(sizeof(t_dbvalue__isc_numeric_i8)==sizeof(t_dbvalue__i8));

extern const t_dbvalue__isc_numeric_i8 __null_dbvalue__isc_numeric_i8;

////////////////////////////////////////////////////////////////////////////////
//one-byte boolean data type

typedef db_obj::t_dbvalue__i1 t_dbvalue__bool_i1;

const t_dbvalue__bool_i1 dbvalue__bool_i1_false =0;
const t_dbvalue__bool_i1 dbvalue__bool_i1_true  =1;

extern const t_dbvalue__bool_i1 __null_dbvalue__bool_i1;

////////////////////////////////////////////////////////////////////////////////
//two-bytes boolean data type

typedef db_obj::t_dbvalue__i2 t_dbvalue__bool_i2;

const t_dbvalue__bool_i2 dbvalue__bool_i2_false =0;
const t_dbvalue__bool_i2 dbvalue__bool_i2_true  =1;

extern const t_dbvalue__bool_i2 __null_dbvalue__bool_i2;

////////////////////////////////////////////////////////////////////////////////
//struct DB_IBQUAD

struct DB_IBQUAD
{
 t_dbvalue__ui4  high;
 t_dbvalue__ui4  low;

#if defined(IBP_BUILD_TESTCODE) || !defined(NDEBUG)
 bool operator == (const DB_IBQUAD& x)const
 {
  return this->low==x.low && this->high==x.high;
 }

 bool operator != (const DB_IBQUAD& x)const
 {
  return this->low!=x.low || this->high!=x.high;
 }
#endif
};//struct DB_IBQUAD

////////////////////////////////////////////////////////////////////////////////
//struct DB_IBBLOBID

/// <summary>
///  Идентификатор BLOB'a InterBase
/// </summary>
typedef DB_IBQUAD DB_IBBLOBID;

////////////////////////////////////////////////////////////////////////////////
//struct DB_IBARRAYID

/// <summary>
///  Идентификатор массива InterBase
/// </summary>
typedef DB_IBQUAD DB_IBARRAYID;

////////////////////////////////////////////////////////////////////////////////
//consts

extern const DB_IBQUAD     __null_ib_quad;
extern const DB_IBBLOBID   __null_ib_blob_id;
extern const DB_IBARRAYID  __null_ib_array_id;

////////////////////////////////////////////////////////////////////////////////

using t_dbvalue__fb040_timezone=t_dbvalue__ui2;

////////////////////////////////////////////////////////////////////////////////
//struct t_dbvalue__fb040_timestamp_with_tz

/// <summary>
///  FB4.0: Timestamp with timezone.
/// </summary>
struct t_dbvalue__fb040_timestamp_with_tz
{
 t_dbvalue__isc_timestamp utc_timestamp;

 t_dbvalue__fb040_timezone  time_zone;
};//struct t_dbvalue__fb040_timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//struct t_dbvalue__fb040_time_with_tz

/// <summary>
///  FB4.0: Time with timezone.
/// </summary>
struct t_dbvalue__fb040_time_with_tz
{
 t_dbvalue__isc_time     utc_time;

 t_dbvalue__fb040_timezone time_zone;
};//struct t_dbvalue__fb040_time_with_tz

////////////////////////////////////////////////////////////////////////////////
//struct t_dbvalue__fb040_int128

struct t_dbvalue__fb040_int128
{
 struct
 {
#if IBP_BYTE_ORDER==IBP_BYTE_ORDER__LOW_ENDIAN
  t_dbvalue__ui8 low;
  t_dbvalue__ui8 high;
#else
# error Is not tested!
#endif
 } data;
};//struct t_dbvalue__fb040_int128

//------------------------------------------------------------------------
inline t_dbvalue__fb040_int128 make_fb040_int128(t_dbvalue__ui8 l,t_dbvalue__ui8 h)
{
 t_dbvalue__fb040_int128 v;

 v.data.low  =l;
 v.data.high =h;

 return v;
}//make_fb040_int128

////////////////////////////////////////////////////////////////////////////////

extern const t_dbvalue__fb040_int128 __null_dbvalue__fb040_int128;

////////////////////////////////////////////////////////////////////////////////

#ifdef IBP_BUILD_TESTCODE

bool operator == (const t_dbvalue__fb040_int128& v1,const t_dbvalue__fb040_int128& v2);

bool operator != (const t_dbvalue__fb040_int128& v1,const t_dbvalue__fb040_int128& v2);

#endif

////////////////////////////////////////////////////////////////////////////////
//FB040_NUMERIC_I8

///id: dbtype__fb040_numeric_i16
struct t_dbvalue__fb040_numeric_i16
{
 t_dbvalue__fb040_int128 data;
};//struct t_dbvalue__fb040_numeric_i16

assert_s(sizeof(t_dbvalue__fb040_numeric_i16)==sizeof(t_dbvalue__fb040_int128));

extern const t_dbvalue__fb040_numeric_i16 __null_dbvalue__fb040_numeric_i16;

////////////////////////////////////////////////////////////////////////////////
//struct t_dbvalue__fb040_decfloat16

struct t_dbvalue__fb040_decfloat16
{
 t_dbvalue__ui8 data[1];
};//struct t_dbvalue__fb040_decfloat16

////////////////////////////////////////////////////////////////////////////////
//struct t_dbvalue__fb040_decfloat34

struct t_dbvalue__fb040_decfloat34
{
 t_dbvalue__ui8 data[2];
};//struct t_dbvalue__fb040_decfloat34

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Перечисление идентификаторов внутренних типов данных
/// </summary>
enum tag_enum_dbtype
{
 dbtype__empty               =0,
 dbtype__i2                  =1,
 dbtype__i4                  =2,
 dbtype__r4                  =3,
 dbtype__r8                  =4,
 dbtype__i8                  =5,
 dbtype__char                =6,
 dbtype__varchar             =7,
 dbtype__oledb_dbtimestamp   =8,  //DBTIMESTAMP
 dbtype__oledb_dbdate        =9,  //DBDATE

 dbtype__ib_bin_blob_id      =11, //DB_IBBLOBID   - бинарный BLOB
 dbtype__ib_txt_blob_id      =12, //DB_IBBLOBID   - текстовый BLOB
 dbtype__oledb_numeric       =13, //DB_NUMERIC
 dbtype__ib_array_id         =14, //DB_IBARRAYID

 dbtype__i1                  =15,
 dbtype__ui1                 =16,
 dbtype__ui2                 =17,
 dbtype__ui4                 =18,
 dbtype__ui8                 =19,

 //дополнительные типы данных

 dbtype__cy                  =23, //tagCY
 dbtype__decimal             =24, //DECIMAL

 dbtype__vb_date             =25, //DATE
 dbtype__cpp_bool            =26, //bool

 dbtype__binary              =27,
 dbtype__varbinary           =28,

 dbtype__sql_null            =29,

 dbtype__wchar               =30, //wchar_t
 dbtype__wvarchar            =31,

 dbtype__oledb_dbtime2       =32, //DBTIME2

 dbtype__long                =33, //LONG
 dbtype__ulong               =34, //ULONG

 dbtype__isc_timestamp       =35,
 dbtype__isc_date            =36,
 dbtype__isc_time            =37,

 dbtype__bool_i1             =38,  //t_dbvalue_bool_i1
 dbtype__bool_i2             =39,  //t_dbvalue_bool_i2

 dbtype__isc_numeric_i2      =40,  //t_dbvalue__isc_numeric_i2 + scale
 dbtype__isc_numeric_i4      =41,  //t_dbvalue__isc_numeric_i4 + scale
 dbtype__isc_numeric_i8      =42,  //t_dbvalue__isc_numeric_i8 + scale

 dbtype__fb040_timestamp_with_tz =43,  //t_dbvalue__fb040_timestamp_with_tz
 dbtype__fb040_time_with_tz      =44,  //t_dbvalue__fb040_time_with_tz

 dbtype__fb040_int128            =45,  //t_dbvalue__fb040_int128

 ///DB_NUMERIC on the base of INT128
 dbtype__fb040_numeric_i16       =46,  //t_dbvalue__fb040_numeric_i16 + scale

 dbtype__fb040_decfloat16        =47, // t_dbvalue__fb040_decfloat16
 dbtype__fb040_decfloat34        =48, // t_dbvalue__fb040_decfloat34

 dbtype__none                =-1
};//enum tag_enum_dbtype

typedef tag_enum_dbtype t_dbtype;

////////////////////////////////////////////////////////////////////////////////
//The enumeration of data type precisions and scales

enum
{
 //включая предельно допустимые значения типов
 dbprecision__isc_smallint              =5,
 dbprecision__isc_integer               =10,
 dbprecision__isc_int64                 =19,

 dbprecision__isc_float                 =7,
 dbprecision__isc_double                =15,

 dbprecision__isc_numeric_on_smallint   =4,
 dbprecision__isc_numeric_on_integer    =9,
 dbprecision__isc_numeric_on_double     =15,
 dbprecision__isc_numeric_on_int64      =18,

 dbprecision__isc_decimal_on_smallint   =4,
 dbprecision__isc_decimal_on_integer    =9,
 dbprecision__isc_decimal_on_int64      =18,

 dbprecision__ib_numeric_v5             =dbprecision__isc_double,
 dbprecision__ib_numeric_v6             =dbprecision__isc_numeric_on_int64,

 dbprecision__ib_decimal_v5             =dbprecision__isc_double,
 dbprecision__ib_decimal_v6             =dbprecision__isc_decimal_on_int64,

                                             //123456789012345678901234
 dbprecision__isc_timestamp             =24, //dd.mm.yyyy hh:mm:ss.msms
 dbprecision__isc_date                  =10, //dd.mm.yyyy

 dbprecision__isc_time2                 =13, //hh:mm:ss.msms

 //Для режима TIME_AS_WSTR.
 dbprecision__isc_time2_as_wstr         =32,

 //Для режима DATE_AS_WSTR.
 dbprecision__isc_date_as_wstr          =32,

 //Для режима TIMESTAMP_AS_WSTR
 dbprecision__isc_timestamp_as_wstr     =dbprecision__isc_date_as_wstr+
                                         1+
                                         dbprecision__isc_time2_as_wstr,

 dbprecision__fb040_int128                  =39,
 dbprecision__fb040_numeric_on_int128       =38,
 dbprecision__fb040_decimal_on_int128       =38,

 dbprecision__fb040_decfloat16              =16,
 dbprecision__fb040_decfloat34              =34,

                                                 //1234567890123456789012345678901
 dbprecision__fb040_timestamp_with_tz       =31, //dd.mm.yyyy hh:mm:ss.msms +hh:mm

 dbprecision__fb040_time2_with_tz           =20, //hh:mm:ss.msms +hh:mm

 //Для режима TIME2_WITH_TZ_AS_WSTR
 dbprecision__fb040_time2_with_tz_as_wstr   =64,

 //Для режима TIMESTAMP_WITH_TZ_AS_WSTR
 dbprecision__fb040_timestamp_with_tz_as_wstr
  =db_obj::dbprecision__isc_date_as_wstr+1+dbprecision__fb040_time2_with_tz_as_wstr,

 //For DECLFLOAT_AS_WSTR mode
 dbprecision__fb040_decfloat16_as_wstr      =dbprecision__fb040_decfloat16+16,
 dbprecision__fb040_decfloat34_as_wstr      =dbprecision__fb040_decfloat34+16,
};//enum

enum
{
 dbscale__isc_timestamp                 =4, //micro-seconds [0..9999]
 dbscale__isc_date                      =0,
 dbscale__isc_time2                     =4, //micro-seconds [0..9999]

 dbscale__fb040_timestamp_with_tz       =db_obj::dbscale__isc_timestamp,
 dbscale__fb040_time2_with_tz           =db_obj::dbscale__isc_time2,
};//enum

////////////////////////////////////////////////////////////////////////////////

const wchar_t* get_dbtype_name(t_dbtype typeID);

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
