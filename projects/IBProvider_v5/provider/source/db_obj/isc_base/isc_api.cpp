////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_api
//! \file    isc_api.cpp
//! \brief   ???????? ??????????? ISC API
//! \author  Kovalenko Dmitry
//! \date    23.11.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_api.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace isc_api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_api
//! @{
////////////////////////////////////////////////////////////////////////////////

extern const t_ibp_isc_timestamp __null__isc_timestamp={};

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ???????????? ???????? ? ??????? ?????
/// </summary>
//! \param[in] numeric_rules
//! \param[in] sqlscale
//! \param[in] sqlsubtype
bool isc_ignore_numeric_scale(long const numeric_rules,
                              long const sqlscale,
                              long const sqlsubtype)
{
 if(sqlscale!=0)
  return false;

 //????????????? ????????? ? ??????? ?????????
 if(numeric_rules&ibprovider::ibp_propval_numeric_rules__ignore_zero_scale)
  return true;

 if(sqlsubtype==ibp_isc_subtype__numeric)
  return false;

 if(sqlsubtype==ibp_isc_subtype__decimal)
  return false;

 return true;
}//isc_ignore_numeric_scale

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V1

XSQLVAR_V1::name_box_type
 XSQLVAR_V1::get_xsqlvar_relname_box()const
{
 const wchar_t c_bugcheck_src[]=
  L"XSQLVAR_V1::get_xsqlvar_relname_box";

 if(this->relname_length<0)
 {
  //ERROR - incorrect length
  IBP_ThrowBugCheck__IncorrectDataLength
   (c_bugcheck_src,
    L"#001",
    this->relname_length);
 }//if

 assert(structure::can_numeric_cast<size_t>(this->relname_length));

 if(_DIM_(this->relname)<static_cast<size_t>(this->relname_length))
 {
  //ERROR - too large length
  IBP_ThrowBugCheck__TooLargeDataLength
   (c_bugcheck_src,
    L"#002",
    this->relname_length,
    _DIM_(this->relname));
 }//if

 assert(static_cast<size_t>(this->relname_length)<=_DIM_(this->relname));

 return name_box_type(this->relname,static_cast<size_t>(this->relname_length));
}//get_xsqlvar_relname_box

//------------------------------------------------------------------------
XSQLVAR_V1::name_box_type
 XSQLVAR_V1::get_xsqlvar_sqlname_box()const
{
 const wchar_t c_bugcheck_src[]=
  L"XSQLVAR_V1::get_xsqlvar_sqlname_box";

 if(this->sqlname_length<0)
 {
  //ERROR - incorrect length
  IBP_ThrowBugCheck__IncorrectDataLength
   (c_bugcheck_src,
    L"#001",
    this->sqlname_length);
 }//if

 assert(structure::can_numeric_cast<size_t>(this->sqlname_length));

 if(_DIM_(this->sqlname)<static_cast<size_t>(this->sqlname_length))
 {
  //ERROR - too large length
  IBP_ThrowBugCheck__TooLargeDataLength
   (c_bugcheck_src,
    L"#002",
    this->sqlname_length,
    _DIM_(this->sqlname));
 }//if

 assert(static_cast<size_t>(this->sqlname_length)<=_DIM_(this->sqlname));

 return name_box_type(this->sqlname,static_cast<size_t>(this->sqlname_length));
}//get_xsqlvar_sqlname_box

//------------------------------------------------------------------------
XSQLVAR_V1::name_box_type
 XSQLVAR_V1::get_xsqlvar_aliasname_box()const
{
 const wchar_t c_bugcheck_src[]=
  L"XSQLVAR_V1::get_xsqlvar_aliasname_box";

 if(this->aliasname_length<0)
 {
  //ERROR - incorrect length
  IBP_ThrowBugCheck__IncorrectDataLength
   (c_bugcheck_src,
    L"#001",
    this->aliasname_length);
 }//if

 assert(structure::can_numeric_cast<size_t>(this->aliasname_length));

 if(_DIM_(this->aliasname)<static_cast<size_t>(this->aliasname_length))
 {
  //ERROR - too large length
  IBP_ThrowBugCheck__TooLargeDataLength
   (c_bugcheck_src,
    L"#002",
    this->aliasname_length,
    _DIM_(this->aliasname));
 }//if

 assert(static_cast<size_t>(this->aliasname_length)<=_DIM_(this->aliasname));

 return name_box_type(this->aliasname,static_cast<size_t>(this->aliasname_length));
}//get_xsqlvar_aliasname_box

//------------------------------------------------------------------------
bool XSQLVAR_V1::value_is_null__std()const
{
 const wchar_t* c_bugcheck_src
  =L"XSQLVAR_V1::value_is_null__std";
 
 //-----------------------------------------
 // [2016-03-17] ????????? ?????? ???? ???????????????!
 assert(this->sqlind!=nullptr);

 //-----------------------------------------
 //! \todo
 //!  [2016-03-17] ??????? ??? ????????
 if(this->sqlind==nullptr)
  return false;

 CHECK_READ_TYPED_PTR(this->sqlind,1)

 switch(*this->sqlind)
 {
  case  0: return false;
  case -1: return true;
 }//switch

 assert_msg(false,"sqlind: "<<*this->sqlind);

 t_ibp_error exc(E_FAIL,
                 ibp_mce_isc__bug_check__unknown_value_of_xsqlvar_indicator_3);

 exc<<c_bugcheck_src
    <<L"#001"
    <<*this->sqlind;

 exc.raise_me();
}//value_is_null__std

//------------------------------------------------------------------------
void XSQLVAR_V1::set_value_null_state__std(bool const nullState)
{
 assert(this->sqlind!=nullptr);

 //????, ???????, ????? ???????? runtime-???????? this->sqlind!=nullptr.
 //??, ????????? - ??? ? ??? ??????????????? ????? ? ?????????? ??????? ???????
 //???????????????? sqlind

 if(nullState)
  (*(this->sqlind))=-1;
 else
  (*(this->sqlind))=0;
}//set_value_null_state__std

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V1_EXT

XSQLVAR_V1_EXT::name_box_type
 XSQLVAR_V1_EXT::get_xsqlvar_sqldata_charsetname_box()const
{
 const name_box_type::size_type c=max(0,min((int)this->sqldata_charsetname_length,
                                            (int)_DIM_(this->sqldata_charsetname)));

 return name_box_type(this->sqldata_charsetname,c);
}//get_xsqlvar_sqldata_charsetname_box

//------------------------------------------------------------------------
XSQLVAR_V1_EXT::name_box_type
 XSQLVAR_V1_EXT::get_xsqlvar_base_charsetname_box()const
{
 const name_box_type::size_type c=max(0,min((int)this->base_charsetname_length,
                                            (int)_DIM_(this->base_charsetname)));

 return name_box_type(this->base_charsetname,c);
}//get_xsqlvar_base_charsetname_box

//------------------------------------------------------------------------
void XSQLVAR_V1_EXT::set_original_fields(const XSQLVAR_V1& xsqlvar)
{
 this->original__sqltype         =xsqlvar.sqltype;
 this->original__sqlscale        =xsqlvar.sqlscale;
 this->original__sqlsubtype      =xsqlvar.sqlsubtype;
 this->original__sqllen          =xsqlvar.sqllen;
}//set_original_fields

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V2

XSQLVAR_V2::name_box_type
 XSQLVAR_V2::get_xsqlvar_relname_box()const
{
 const wchar_t c_bugcheck_src[]=
  L"XSQLVAR_V2::get_xsqlvar_relname_box";

 if(this->relname_length<0)
 {
  //ERROR - incorrect length
  IBP_ThrowBugCheck__IncorrectDataLength
   (c_bugcheck_src,
    L"#001",
    this->relname_length);
 }//if

 assert(structure::can_numeric_cast<size_t>(this->relname_length));

 if(_DIM_(this->relname)<static_cast<size_t>(this->relname_length))
 {
  //ERROR - too large length
  IBP_ThrowBugCheck__TooLargeDataLength
   (c_bugcheck_src,
    L"#002",
    this->relname_length,
    _DIM_(this->relname));
 }//if

 assert(static_cast<size_t>(this->relname_length)<=_DIM_(this->relname));

 return name_box_type(this->relname,static_cast<size_t>(this->relname_length));
}//get_xsqlvar_relname_box

//------------------------------------------------------------------------
XSQLVAR_V2::name_box_type
 XSQLVAR_V2::get_xsqlvar_sqlname_box()const
{
 const wchar_t c_bugcheck_src[]=
  L"XSQLVAR_V2::get_xsqlvar_sqlname_box";

 if(this->sqlname_length<0)
 {
  //ERROR - incorrect length
  IBP_ThrowBugCheck__IncorrectDataLength
   (c_bugcheck_src,
    L"#001",
    this->sqlname_length);
 }//if

 assert(structure::can_numeric_cast<size_t>(this->sqlname_length));

 if(_DIM_(this->sqlname)<static_cast<size_t>(this->sqlname_length))
 {
  //ERROR - too large length
  IBP_ThrowBugCheck__TooLargeDataLength
   (c_bugcheck_src,
    L"#002",
    this->sqlname_length,
    _DIM_(this->sqlname));
 }//if

 assert(static_cast<size_t>(this->sqlname_length)<=_DIM_(this->sqlname));

 return name_box_type(this->sqlname,static_cast<size_t>(this->sqlname_length));
}//get_xsqlvar_sqlname_box

//------------------------------------------------------------------------
XSQLVAR_V2::name_box_type
 XSQLVAR_V2::get_xsqlvar_aliasname_box()const
{
 const wchar_t c_bugcheck_src[]=
  L"XSQLVAR_V2::get_xsqlvar_aliasname_box";

 if(this->aliasname_length<0)
 {
  //ERROR - incorrect length
  IBP_ThrowBugCheck__IncorrectDataLength
   (c_bugcheck_src,
    L"#001",
    this->aliasname_length);
 }//if

 assert(structure::can_numeric_cast<size_t>(this->aliasname_length));

 if(_DIM_(this->aliasname)<static_cast<size_t>(this->aliasname_length))
 {
  //ERROR - too large length
  IBP_ThrowBugCheck__TooLargeDataLength
   (c_bugcheck_src,
    L"#002",
    this->aliasname_length,
    _DIM_(this->aliasname));
 }//if

 assert(static_cast<size_t>(this->aliasname_length)<=_DIM_(this->aliasname));

 return name_box_type(this->aliasname,static_cast<size_t>(this->aliasname_length));
}//get_xsqlvar_aliasname_box

//------------------------------------------------------------------------
bool XSQLVAR_V2::value_is_null__std()const
{
 const wchar_t* c_bugcheck_src
  =L"XSQLVAR_V2::value_is_null__std";
 
 //-----------------------------------------
 // [2016-03-17] ????????? ?????? ???? ???????????????!
 assert(this->sqlind!=nullptr);

 //-----------------------------------------
 //! \todo
 //!  [2016-03-17] ??????? ??? ????????
 if(this->sqlind==nullptr)
  return false;

 CHECK_READ_TYPED_PTR(this->sqlind,1)

 switch(*this->sqlind)
 {
  case  0: return false;
  case -1: return true;
 }//switch

 assert_msg(false,"sqlind: "<<*this->sqlind);

 t_ibp_error exc(E_FAIL,
                 ibp_mce_isc__bug_check__unknown_value_of_xsqlvar_indicator_3);

 exc<<c_bugcheck_src
    <<L"#001"
    <<*this->sqlind;

 exc.raise_me();
}//value_is_null__std

//------------------------------------------------------------------------
void XSQLVAR_V2::set_value_null_state__std(bool const nullState)
{
 assert(this->sqlind!=nullptr);

 //????, ???????, ????? ???????? runtime-???????? this->sqlind!=nullptr.
 //??, ????????? - ??? ? ??? ??????????????? ????? ? ?????????? ??????? ???????
 //???????????????? sqlind

 if(nullState)
  (*(this->sqlind))=-1;
 else
  (*(this->sqlind))=0;
}//set_value_null_state__std

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V2_EXT

XSQLVAR_V2_EXT::name_box_type
 XSQLVAR_V2_EXT::get_xsqlvar_sqldata_charsetname_box()const
{
 const name_box_type::size_type c=max(0,min((int)this->sqldata_charsetname_length,
                                            (int)_DIM_(this->sqldata_charsetname)));

 return name_box_type(this->sqldata_charsetname,c);
}//get_xsqlvar_sqldata_charsetname_box

//------------------------------------------------------------------------
XSQLVAR_V2_EXT::name_box_type
 XSQLVAR_V2_EXT::get_xsqlvar_base_charsetname_box()const
{
 const name_box_type::size_type c=max(0,min((int)this->base_charsetname_length,
                                            (int)_DIM_(this->base_charsetname)));

 return name_box_type(this->base_charsetname,c);
}//get_xsqlvar_base_charsetname_box

//------------------------------------------------------------------------
void XSQLVAR_V2_EXT::set_original_fields(const XSQLVAR_V2& xsqlvar)
{
 this->original__sqltype         =xsqlvar.sqltype;
 this->original__sqlscale        =xsqlvar.sqlscale;
 this->original__sqlprecision    =xsqlvar.sqlprecision;
 this->original__sqlsubtype      =xsqlvar.sqlsubtype;
 this->original__sqllen          =xsqlvar.sqllen;
}//set_original_fields

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_api*/}/*nms ibp*/}/*nms lcpi*/
