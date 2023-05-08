////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_data_types.cpp
//! \brief   Определение типов данных
//! \author  Kovalenko Dmitry
//! \date    26.09.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/db_data_types.h"
#include "source/error_services/ibp_error_utils.h"

#include <structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//consts

extern const t_dbvalue__cpp_bool
 __null_dbvalue__cpp_bool
  =false;

//------------------------------------------------------------------------
extern const t_dbvalue__isc_numeric_i2
 __null_dbvalue__isc_numeric_i2
  ={0};

//------------------------------------------------------------------------
extern const t_dbvalue__isc_numeric_i4
 __null_dbvalue__isc_numeric_i4
  ={0};

//------------------------------------------------------------------------
extern const t_dbvalue__isc_numeric_i8
 __null_dbvalue__isc_numeric_i8
  ={0};

//------------------------------------------------------------------------
extern const t_dbvalue__bool_i1
 __null_dbvalue__bool_i1
  =dbvalue__bool_i1_false;

//------------------------------------------------------------------------
extern const t_dbvalue__bool_i2
 __null_dbvalue__bool_i2
  =dbvalue__bool_i2_false;

//------------------------------------------------------------------------
extern const DB_IBQUAD        __null_ib_quad          ={};
extern const DB_IBBLOBID      __null_ib_blob_id       ={};
extern const DB_IBARRAYID     __null_ib_array_id      ={};

////////////////////////////////////////////////////////////////////////////////

const t_dbvalue__fb040_int128
 __null_dbvalue__fb040_int128
  ={0,0};

//------------------------------------------------------------------------
const t_dbvalue__fb040_numeric_i16
 __null_dbvalue__fb040_numeric_i16
  ={{0,0}};

////////////////////////////////////////////////////////////////////////////////
//struct tag_dbtype_info

struct tag_dbtype_info
{
 t_dbtype        typeID;
 const wchar_t*  typeName;
};//struct tag_dbtype_info

////////////////////////////////////////////////////////////////////////////////
//dbtype descriptions

#define DEF_DBTYPE_INFO(id,name)                       \
static const tag_dbtype_info g_##id##_info=            \
 {id,L##name}

////////////////////////////////////////////////////////////////////////////////

DEF_DBTYPE_INFO(dbtype__empty                              ,"empty");
DEF_DBTYPE_INFO(dbtype__i2                                 ,"i2");
DEF_DBTYPE_INFO(dbtype__i4                                 ,"i4");
DEF_DBTYPE_INFO(dbtype__r4                                 ,"r4");
DEF_DBTYPE_INFO(dbtype__r8                                 ,"r8");
DEF_DBTYPE_INFO(dbtype__i8                                 ,"i8");
DEF_DBTYPE_INFO(dbtype__char                               ,"char");
DEF_DBTYPE_INFO(dbtype__varchar                            ,"varchar");
DEF_DBTYPE_INFO(dbtype__oledb_dbtimestamp                  ,"oledb_dbtimestamp");
DEF_DBTYPE_INFO(dbtype__oledb_dbdate                       ,"oledb_dbdate");
DEF_DBTYPE_INFO(dbtype__ib_bin_blob_id                     ,"ib_bin_blob_id");
DEF_DBTYPE_INFO(dbtype__ib_txt_blob_id                     ,"ib_txt_blob_id");
DEF_DBTYPE_INFO(dbtype__oledb_numeric                      ,"oledb_numeric");
DEF_DBTYPE_INFO(dbtype__ib_array_id                        ,"ib_array_id");
DEF_DBTYPE_INFO(dbtype__i1                                 ,"i1");
DEF_DBTYPE_INFO(dbtype__ui1                                ,"ui1");
DEF_DBTYPE_INFO(dbtype__ui2                                ,"ui2");
DEF_DBTYPE_INFO(dbtype__ui4                                ,"ui4");
DEF_DBTYPE_INFO(dbtype__ui8                                ,"ui8");
DEF_DBTYPE_INFO(dbtype__cy                                 ,"cy");
DEF_DBTYPE_INFO(dbtype__decimal                            ,"decimal");
DEF_DBTYPE_INFO(dbtype__vb_date                            ,"cb_date");
DEF_DBTYPE_INFO(dbtype__cpp_bool                           ,"cpp_bool");
DEF_DBTYPE_INFO(dbtype__binary                             ,"binary");
DEF_DBTYPE_INFO(dbtype__varbinary                          ,"varbinary");
DEF_DBTYPE_INFO(dbtype__sql_null                           ,"sql_null");
DEF_DBTYPE_INFO(dbtype__wchar                              ,"wchar");
DEF_DBTYPE_INFO(dbtype__wvarchar                           ,"wvarchar");
DEF_DBTYPE_INFO(dbtype__oledb_dbtime2                      ,"oledb_dbtime2");
DEF_DBTYPE_INFO(dbtype__long                               ,"long");
DEF_DBTYPE_INFO(dbtype__ulong                              ,"ulong");
DEF_DBTYPE_INFO(dbtype__isc_time                           ,"isc_time");
DEF_DBTYPE_INFO(dbtype__isc_date                           ,"isc_date");
DEF_DBTYPE_INFO(dbtype__isc_timestamp                      ,"isc_timestamp");
DEF_DBTYPE_INFO(dbtype__bool_i1                            ,"bool_i1");
DEF_DBTYPE_INFO(dbtype__bool_i2                            ,"bool_i2");
DEF_DBTYPE_INFO(dbtype__isc_numeric_i2                     ,"isc_numeric_i2");
DEF_DBTYPE_INFO(dbtype__isc_numeric_i4                     ,"isc_numeric_i4");
DEF_DBTYPE_INFO(dbtype__isc_numeric_i8                     ,"isc_numeric_i8");
DEF_DBTYPE_INFO(dbtype__fb040_timestamp_with_tz            ,"fb040_timestamp_with_tz");
DEF_DBTYPE_INFO(dbtype__fb040_time_with_tz                 ,"fb040_time_with_tz");
DEF_DBTYPE_INFO(dbtype__fb040_int128                       ,"fb040_int128");
DEF_DBTYPE_INFO(dbtype__fb040_numeric_i16                  ,"fb040_numeric_i16");
DEF_DBTYPE_INFO(dbtype__fb040_decfloat16                   ,"fb040_decfloat16");
DEF_DBTYPE_INFO(dbtype__fb040_decfloat34                   ,"fb040_decfloat34");

#undef DEF_DBTYPE_INFO

////////////////////////////////////////////////////////////////////////////////

#define ADD_DBTYPE_INFO(id) &g_##id##_info

static const tag_dbtype_info* const g_dbtype_descrs[]=
{
 /* 0*/  ADD_DBTYPE_INFO(dbtype__empty),
 /* 1*/  ADD_DBTYPE_INFO(dbtype__i2),
 /* 2*/  ADD_DBTYPE_INFO(dbtype__i4),
 /* 3*/  ADD_DBTYPE_INFO(dbtype__r4),
 /* 4*/  ADD_DBTYPE_INFO(dbtype__r8),
 /* 5*/  ADD_DBTYPE_INFO(dbtype__i8),
 /* 6*/  ADD_DBTYPE_INFO(dbtype__char),
 /* 7*/  ADD_DBTYPE_INFO(dbtype__varchar),
 /* 8*/  ADD_DBTYPE_INFO(dbtype__oledb_dbtimestamp),
 /* 9*/  ADD_DBTYPE_INFO(dbtype__oledb_dbdate),
 /*10*/  nullptr,
 /*11*/  ADD_DBTYPE_INFO(dbtype__ib_bin_blob_id),
 /*12*/  ADD_DBTYPE_INFO(dbtype__ib_txt_blob_id),
 /*13*/  ADD_DBTYPE_INFO(dbtype__oledb_numeric),
 /*14*/  ADD_DBTYPE_INFO(dbtype__ib_array_id),
 /*15*/  ADD_DBTYPE_INFO(dbtype__i1),
 /*16*/  ADD_DBTYPE_INFO(dbtype__ui1),
 /*17*/  ADD_DBTYPE_INFO(dbtype__ui2),
 /*18*/  ADD_DBTYPE_INFO(dbtype__ui4),
 /*19*/  ADD_DBTYPE_INFO(dbtype__ui8),
 /*20*/  nullptr,
 /*21*/  nullptr,
 /*22*/  nullptr,
 /*23*/  ADD_DBTYPE_INFO(dbtype__cy),
 /*24*/  ADD_DBTYPE_INFO(dbtype__decimal),
 /*25*/  ADD_DBTYPE_INFO(dbtype__vb_date),
 /*26*/  ADD_DBTYPE_INFO(dbtype__cpp_bool),
 /*27*/  ADD_DBTYPE_INFO(dbtype__binary),
 /*28*/  ADD_DBTYPE_INFO(dbtype__varbinary),
 /*29*/  ADD_DBTYPE_INFO(dbtype__sql_null),
 /*30*/  ADD_DBTYPE_INFO(dbtype__wchar),
 /*31*/  ADD_DBTYPE_INFO(dbtype__wvarchar),
 /*32*/  ADD_DBTYPE_INFO(dbtype__oledb_dbtime2),
 /*33*/  ADD_DBTYPE_INFO(dbtype__long),
 /*34*/  ADD_DBTYPE_INFO(dbtype__ulong),
 /*35*/  ADD_DBTYPE_INFO(dbtype__isc_time),
 /*36*/  ADD_DBTYPE_INFO(dbtype__isc_date),
 /*37*/  ADD_DBTYPE_INFO(dbtype__isc_timestamp),
 /*38*/  ADD_DBTYPE_INFO(dbtype__bool_i1),
 /*39*/  ADD_DBTYPE_INFO(dbtype__bool_i2),
 /*40*/  ADD_DBTYPE_INFO(dbtype__isc_numeric_i2),
 /*41*/  ADD_DBTYPE_INFO(dbtype__isc_numeric_i4),
 /*42*/  ADD_DBTYPE_INFO(dbtype__isc_numeric_i8),
 /*43*/  ADD_DBTYPE_INFO(dbtype__fb040_timestamp_with_tz),
 /*44*/  ADD_DBTYPE_INFO(dbtype__fb040_time_with_tz),
 /*45*/  ADD_DBTYPE_INFO(dbtype__fb040_int128),
 /*46*/  ADD_DBTYPE_INFO(dbtype__fb040_numeric_i16),
 /*47*/  ADD_DBTYPE_INFO(dbtype__fb040_decfloat16),
 /*48*/  ADD_DBTYPE_INFO(dbtype__fb040_decfloat34),
};//g_dbtype_descrs

#undef ADD_DBTYPE_INFO

////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void vertify__g_dbtype_descrs()
{
 for(size_t n=0;n!=_DIM_(g_dbtype_descrs);++n)
 {
  if(g_dbtype_descrs[n]==NULL)
   return;

  assert(g_dbtype_descrs[n]->typeID>=0);
  assert_msg(size_t(g_dbtype_descrs[n]->typeID)==n,"n="<<n);

  assert_msg(g_dbtype_descrs[n]->typeName!=NULL,"n="<<n);
 }//for
}//vertify__g_dbtype_descrs

STARTUP_CODE__DEBUG(vertify__g_dbtype_descrs)

#endif

////////////////////////////////////////////////////////////////////////////////

static const tag_dbtype_info* get_dbtype_info(t_dbtype const typeID)
{
 if(typeID<0)
  return nullptr;

 if(_DIM_(g_dbtype_descrs)<=typeID)
  return nullptr;

 assert_msg(g_dbtype_descrs[typeID]==NULL ||
            g_dbtype_descrs[typeID]->typeID==typeID,
            "typeID="<<int(typeID));

 return g_dbtype_descrs[typeID];
}//get_dbtype_info

////////////////////////////////////////////////////////////////////////////////

const wchar_t* get_dbtype_name(t_dbtype const typeID)
{
 if(const tag_dbtype_info* const x=get_dbtype_info(typeID))
 {
  assert(x->typeName);

  return x->typeName;
 }//if

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (L"db_obj::get_dbtype_name",
   L"#001",
   L"unknown dbtype id: %1",
   structure::to_underlying(typeID));
}//get_dbtype_name

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
