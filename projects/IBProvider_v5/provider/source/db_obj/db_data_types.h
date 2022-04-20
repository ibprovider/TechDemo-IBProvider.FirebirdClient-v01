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
typedef DBDATE                              t_dbvalue__dbdate;

///id: dbtype__dbtime2
typedef oledb_lib::t_oledb_value__DBTIME2   t_dbvalue__dbtime2;

///id: dbtype__timestamp
typedef DBTIMESTAMP                         t_dbvalue__dbtimestamp;

///id: dbtype__numeric, dbtype__numeric_i2, dbtype__numeric_i4, dbtype__numeric_i8
typedef DB_NUMERIC                          t_dbvalue__numeric;

///id: dbtype__cy
typedef tagCY                               t_dbvalue__cy;

///id: dbtype__decimal
typedef tagDEC                              t_dbvalue__decimal;

///id: dbtype__bool
typedef bool                                t_dbvalue__bool;

////////////////////////////////////////////////////////////////////////////////

extern const t_dbvalue__bool __null_dbvalue_bool;

////////////////////////////////////////////////////////////////////////////////
//struct DB_IBQUAD

struct DB_IBQUAD
{
 t_dbvalue__ui4  high;
 t_dbvalue__ui4  low;

#ifdef IBP_BUILD_TESTCODE
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
 dbtype__dbtimestamp         =8,  //DBTIMESTAMP
 dbtype__dbdate              =9,  //DBDATE

 dbtype__ib_bin_blob_id      =11, //DB_IBBLOBID   - бинарный BLOB
 dbtype__ib_txt_blob_id      =12, //DB_IBBLOBID   - текстовый BLOB
 dbtype__numeric             =13, //DB_NUMERIC
 dbtype__ib_array_id         =14, //DB_IBARRAYID

 dbtype__i1                  =15,
 dbtype__ui1                 =16,
 dbtype__ui2                 =17,
 dbtype__ui4                 =18,
 dbtype__ui8                 =19,

 //дополнительные типы данных

 ///DB_NUMERIC на базе SHORT
 dbtype__numeric_i2          =20,

 ///DB_NUMERIC на базе LONG
 dbtype__numeric_i4          =21,

 ///DB_NUMERIC на базе INT64
 dbtype__numeric_i8          =22,

 dbtype__cy                  =23, //tagCY
 dbtype__decimal             =24, //DECIMAL

 dbtype__vb_date             =25, //DATE
 dbtype__bool                =26, //bool

 dbtype__binary              =27,
 dbtype__varbinary           =28,

 dbtype__sql_null            =29,

 dbtype__wchar               =30, //wchar_t
 dbtype__wvarchar            =31,

 dbtype__dbtime2             =32, //DBTIME2

 dbtype__long                =33, //LONG
 dbtype__ulong               =34, //ULONG

 dbtype__none                =-1
};//enum tag_enum_dbtype

typedef tag_enum_dbtype t_dbtype;

////////////////////////////////////////////////////////////////////////////////

const wchar_t* get_dbtype_name(t_dbtype typeID);

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
