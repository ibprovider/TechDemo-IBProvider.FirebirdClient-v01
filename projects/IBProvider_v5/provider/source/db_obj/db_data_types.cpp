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

#include <structure/t_str_formatter.h>
#include <structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//consts

extern const t_dbvalue__bool  __null_dbvalue_bool     =false;

extern const DB_IBQUAD        __null_ib_quad          ={};
extern const DB_IBBLOBID      __null_ib_blob_id       ={};
extern const DB_IBARRAYID     __null_ib_array_id      ={};

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

DEF_DBTYPE_INFO(dbtype__empty               ,"empty");
DEF_DBTYPE_INFO(dbtype__i2                  ,"i2");
DEF_DBTYPE_INFO(dbtype__i4                  ,"i4");
DEF_DBTYPE_INFO(dbtype__r4                  ,"r4");
DEF_DBTYPE_INFO(dbtype__r8                  ,"r8");
DEF_DBTYPE_INFO(dbtype__i8                  ,"i8");
DEF_DBTYPE_INFO(dbtype__char                ,"char");
DEF_DBTYPE_INFO(dbtype__varchar             ,"varchar");
DEF_DBTYPE_INFO(dbtype__dbtimestamp         ,"dbtimestamp");
DEF_DBTYPE_INFO(dbtype__dbdate              ,"dbdate");
DEF_DBTYPE_INFO(dbtype__ib_bin_blob_id      ,"ib_bin_blob_id");
DEF_DBTYPE_INFO(dbtype__ib_txt_blob_id      ,"ib_txt_blob_id");
DEF_DBTYPE_INFO(dbtype__numeric             ,"numeric");
DEF_DBTYPE_INFO(dbtype__ib_array_id         ,"ib_array_id");
DEF_DBTYPE_INFO(dbtype__i1                  ,"i1");
DEF_DBTYPE_INFO(dbtype__ui1                 ,"ui1");
DEF_DBTYPE_INFO(dbtype__ui2                 ,"ui2");
DEF_DBTYPE_INFO(dbtype__ui4                 ,"ui4");
DEF_DBTYPE_INFO(dbtype__ui8                 ,"ui8");
DEF_DBTYPE_INFO(dbtype__numeric_i2          ,"numeric_i2");
DEF_DBTYPE_INFO(dbtype__numeric_i4          ,"numeric_i4");
DEF_DBTYPE_INFO(dbtype__numeric_i8          ,"numeric_i8");
DEF_DBTYPE_INFO(dbtype__cy                  ,"cy");
DEF_DBTYPE_INFO(dbtype__decimal             ,"decimal");
DEF_DBTYPE_INFO(dbtype__vb_date             ,"cb_date");
DEF_DBTYPE_INFO(dbtype__bool                ,"bool");
DEF_DBTYPE_INFO(dbtype__binary              ,"binary");
DEF_DBTYPE_INFO(dbtype__varbinary           ,"varbinary");
DEF_DBTYPE_INFO(dbtype__sql_null            ,"sql_null");
DEF_DBTYPE_INFO(dbtype__wchar               ,"wchar");
DEF_DBTYPE_INFO(dbtype__wvarchar            ,"wvarchar");
DEF_DBTYPE_INFO(dbtype__dbtime2             ,"dbtime2");
DEF_DBTYPE_INFO(dbtype__long                ,"long");
DEF_DBTYPE_INFO(dbtype__ulong               ,"ulong");
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
 /* 8*/  ADD_DBTYPE_INFO(dbtype__dbtimestamp),
 /* 9*/  ADD_DBTYPE_INFO(dbtype__dbdate),
 /*10*/  NULL,
 /*11*/  ADD_DBTYPE_INFO(dbtype__ib_bin_blob_id),
 /*12*/  ADD_DBTYPE_INFO(dbtype__ib_txt_blob_id),
 /*13*/  ADD_DBTYPE_INFO(dbtype__numeric),
 /*14*/  ADD_DBTYPE_INFO(dbtype__ib_array_id),
 /*15*/  ADD_DBTYPE_INFO(dbtype__i1),
 /*16*/  ADD_DBTYPE_INFO(dbtype__ui1),
 /*17*/  ADD_DBTYPE_INFO(dbtype__ui2),
 /*18*/  ADD_DBTYPE_INFO(dbtype__ui4),
 /*19*/  ADD_DBTYPE_INFO(dbtype__ui8),
 /*20*/  ADD_DBTYPE_INFO(dbtype__numeric_i2),
 /*21*/  ADD_DBTYPE_INFO(dbtype__numeric_i4),
 /*22*/  ADD_DBTYPE_INFO(dbtype__numeric_i8),
 /*23*/  ADD_DBTYPE_INFO(dbtype__cy),
 /*24*/  ADD_DBTYPE_INFO(dbtype__decimal),
 /*25*/  ADD_DBTYPE_INFO(dbtype__vb_date),
 /*26*/  ADD_DBTYPE_INFO(dbtype__bool),
 /*27*/  ADD_DBTYPE_INFO(dbtype__binary),
 /*28*/  ADD_DBTYPE_INFO(dbtype__varbinary),
 /*29*/  ADD_DBTYPE_INFO(dbtype__sql_null),
 /*30*/  ADD_DBTYPE_INFO(dbtype__wchar),
 /*31*/  ADD_DBTYPE_INFO(dbtype__wvarchar),
 /*32*/  ADD_DBTYPE_INFO(dbtype__dbtime2),
 /*33*/  ADD_DBTYPE_INFO(dbtype__long),
 /*34*/  ADD_DBTYPE_INFO(dbtype__ulong),
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

 structure::wstr_formatter freason(L"unknown dbtype id: %1");

 freason<<structure::to_underlying(typeID);

 IBP_BUG_CHECK__DEBUG
  (L"db_obj::get_dbtype_name",
   L"#001",
   freason.c_str());
}//get_dbtype_name

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
