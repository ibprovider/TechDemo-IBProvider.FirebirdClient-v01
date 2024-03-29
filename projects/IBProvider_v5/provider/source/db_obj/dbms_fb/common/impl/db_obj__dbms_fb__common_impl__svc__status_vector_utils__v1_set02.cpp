////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__common_impl
//! \file    db_obj__dbms_fb__common_impl__svc__status_vector_utils__v1_set02.cpp
//! \brief   Реализация сервиса для работы со статус вектором.
//! \author  Kovalenko Dmitry
//! \date    07.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/common/impl/db_obj__dbms_fb__common_impl__svc__status_vector_utils__v1_set02.h"
#include "source/db_obj/dbms_fb/common/api//errors/set02/db_obj__dbms_fb__common__api__errors__set02__scodes.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include "source/error_services/ibp_error_build_message.h"

#include <structure/t_str_formatter.h>

#include <lcpi/lib/structure/utilities/to_hex.h>
#include <lcpi/lib/structure/utilities/string/string_length.h>

#include <array>

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace common{namespace impl{
////////////////////////////////////////////////////////////////////////////////
//class fb_common_impl__svc__status_vector_utils__v1_set02

fb_common_impl__svc__status_vector_utils__v1_set02::fb_common_impl__svc__status_vector_utils__v1_set02
                                           (size_t                                   const cErrDescrs,
                                            const isc_base::t_isc_error_code_descr2* const pErrDescrs)
 :m_cErrDescrs(cErrDescrs)
 ,m_pErrDescrs(pErrDescrs)
{
 CHECK_READ_TYPED_PTR(m_pErrDescrs,m_cErrDescrs);
}

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::~fb_common_impl__svc__status_vector_utils__v1_set02()
{;}

//------------------------------------------------------------------------
const isc_base::t_isc_error_code_descr2*
 fb_common_impl__svc__status_vector_utils__v1_set02::get_err_descr2
                                           (isc_api::t_ibp_isc_status const status)
{
 return this->helper__get_err_descr2(status);
}//get_err_descr2

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::get_sqlstate
                                           (const status_type* const sv_beg,
                                            const status_type* const sv_end,
                                            std::string*       const sqlstate)
{
 //! Original code get from Firebird 2.5 code base.

 assert(sv_beg!=nullptr);
 assert(sv_beg<sv_end);
 assert(sqlstate!=nullptr);

 CHECK_READ_TYPED_PTR(sv_beg,static_cast<size_t>(sv_end-sv_beg));

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::get_sqlstate";

 //-----------------------------------------
 sqlstate->clear();

 //-----------------------------------------
 const size_t n_elements=static_cast<size_t>(sv_end-sv_beg);

 //-----------------------------------------
 if(n_elements==0)
 {
  //недействительный статус-вектор
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 if(sv_beg[0]==api::errors::set02::ibp_fb_scode__arg_end)
 {
  (*sqlstate)=IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS;

  return gresult_data_type::create_ok();
 }//if

 //-----------------------------------------
 if(sv_beg[0]!=api::errors::set02::ibp_fb_scode__arg_gds)
 {
  // wrong status vector?
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#002");
 }//if

 //-----------------------------------------
 if(n_elements<2)
 {
  // wrong status vector?
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#003");
 }//if

 //-----------------------------------------
 if(sv_beg[1]==0)
 {
  // status_vector[1] == 0 is no error, by definition
  (*sqlstate)=IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS;

  return gresult_data_type::create_ok();
 }//if

 const char* sqlstate1=nullptr;
 const char* sqlstate2=nullptr;
 const char* sqlstate3=nullptr;

 find_next_result_type s(sv_beg,gresult_data_type::create_ok());

 for(;s.first!=sv_end;s=self_type::helper__find_next_status_vector_element(s.first,sv_end))
 {
  assert(s.first>=sv_beg);
  assert(s.first<sv_end);

  //---------------- 1.
  //maybe we already have a SQLSTATE stuffed in the status vector

  if((*s.first)==api::errors::set02::ibp_fb_scode__arg_sql_state)
  {
   if(static_cast<size_t>(sv_end-s.first)<2)
   {
    //нарушенная структура статус-вектора
    assert(false);

    return gresult_data_type::create_bad_sv(c_bug_check_src,L"#004");
   }//if

   //easy, next argument points to sqlstate string
   const char* const _sqlstate = reinterpret_cast<const char*>(s.first[1]);

   if(_sqlstate==nullptr)
   {
    //у нас нулевой указатель на SQLCODE, чего быть не должно в принципе...
    assert(false);

    return gresult_data_type::create_bad_sv(c_bug_check_src,L"#005");
   }//if

   (*sqlstate)=_sqlstate;

   return gresult_data_type::create_ok();
  }//if api::errors::set02::ibp_fb_scode__arg_sql_state

  //---------------- 2.
  //see if we can find a mapping.

  if((*s.first)!=api::errors::set02::ibp_fb_scode__arg_gds)
   continue;

  if(static_cast<size_t>(sv_end-s.first)<2)
  {
   //нарушенная структура статус-вектора
   assert(false);

   return gresult_data_type::create_bad_sv(c_bug_check_src,L"#006");
  }//if

  const status_type gdscode=s.first[1];

  if(gdscode==0)
   continue;

  if(const descr2_type* const x=this->helper__get_err_descr2(gdscode))
  {
   //found it [das ist fantastish] !!!

   if(x->sqlstate2==nullptr)
    continue;

   assert(x->sqlstate2!=nullptr);
   assert(lib::structure::string_length(x->sqlstate2)==5);

   // we get 00000 for info messages like "Table %"
   // these are completely ignored
   if(x->eq_sqlstate2(IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS))
    continue;

   if(sqlstate1==nullptr)
    sqlstate1=x->sqlstate2;

   if(this->internal__is_useless_error_code(gdscode))
    continue;

   if(sqlstate2==nullptr)
    sqlstate2=x->sqlstate2;

   // 22000, 42000 and HY000 are general errors.
   // We may be able to find something more precise if we keep scanning.
   if(!self_type::helper__is_common_error_code(x))
   {
    if(sqlstate3==nullptr)
     sqlstate3=x->sqlstate2;
   }
  }//if found it
 }//for s

 if(s.second!=gresult__ok)
  return s.second;

 //-----------------------------------------
 // sqlstate will be exact match, or
 // 42000 for no_meta_update, or
 // HY000 if we didn't find a match

 if(sqlstate3!=nullptr)
 {
  (*sqlstate)=sqlstate3;

  return gresult_data_type::create_ok();
 }//if

 if(sqlstate2!=nullptr)
 {
  (*sqlstate)=sqlstate2;

  return gresult_data_type::create_ok();
 }//if

 if(sqlstate1!=nullptr)
 {
  (*sqlstate)=sqlstate1;

  return gresult_data_type::create_ok();
 }//if

 (*sqlstate)=IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS;

  return gresult_data_type::create_ok();
}//get_sqlstate

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::get_general_error
                                           (const status_type* const sv_beg,
                                            const status_type* const sv_end,
                                            status_type*       const general_error_code)
{
 assert(sv_beg!=nullptr);
 assert(sv_beg<sv_end);
 assert(general_error_code!=nullptr);

 CHECK_READ_TYPED_PTR(sv_beg,static_cast<size_t>(sv_end-sv_beg));

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::get_general_error";

 //-----------------------------------------
 (*general_error_code)=this->internal__get_unexpected_error_code();

 //-----------------------------------------
 const size_t n_elements=static_cast<size_t>(sv_end-sv_beg);

 //-----------------------------------------
 if(n_elements==0)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 if(sv_beg[0]==api::errors::set02::ibp_fb_scode__arg_end)
 {
  (*general_error_code)=0;

  return gresult_data_type::create_ok();
 }//if

 //-----------------------------------------
 if(sv_beg[0]!=api::errors::set02::ibp_fb_scode__arg_gds)
 {
  // wrong status vector?
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#002");
 }//if

 //-----------------------------------------
 if(n_elements<2)
 {
  // wrong status vector?
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#003");
 }//if

 //-----------------------------------------
 if(sv_beg[1]==0)
 {
  // status_vector[1] == 0 is no error, by definition
  (*general_error_code)=0;

  return gresult_data_type::create_ok();
 }//if

 //-----------------------------------------------------------------------
 lib::structure::t_value_with_null<status_type> result1;
 lib::structure::t_value_with_null<status_type> result2;

 find_next_result_type s(sv_beg,gresult_data_type::create_ok());

 for(;s.first!=sv_end;s=self_type::helper__find_next_status_vector_element(s.first,sv_end))
 {
  assert(s.first>=sv_beg);
  assert(s.first<sv_end);

  if((*s.first)!=api::errors::set02::ibp_fb_scode__arg_gds)
   continue;

  if(static_cast<size_t>(sv_end-s.first)<2)
  {
   assert(false);

   return gresult_data_type::create_bad_sv(c_bug_check_src,L"#004");
  }//if

  const status_type gdscode=s.first[1];

  if(gdscode==0)
   continue;

  typedef isc_base::t_isc_error_code_descr isc_err_descr_type;

  typedef structure::t_search_result<const isc_err_descr_type*> result_type;

  if(const descr2_type* const x=this->helper__get_err_descr2(gdscode))
  {
   //found it [das ist fantastish] !!!

   if(x->sqlstate2==nullptr)
    continue;

   assert(x->sqlstate2!=nullptr);
   assert(lib::structure::string_length(x->sqlstate2)==5);

   // we get 00000 for info messages like "Table %"
   // these are completely ignored
   if(x->eq_sqlstate2(IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS))
    continue;

   result1.assign_once(gdscode);

   if(this->internal__is_useless_error_code(gdscode))
    continue;

   result2.assign_once(gdscode);

   // 22000, 42000 and HY000 are general errors.
   // We may be able to find something more precise if we keep scanning.
   if(!self_type::helper__is_common_error_code(x))
   {
    (*general_error_code)=gdscode;

    return gresult_data_type::create_ok();
   }
  }//if found it
 }//for s

 if(s.second!=gresult__ok)
  return s.second;

 //-----------------------------------------
 if(!result2.null())
 {
  (*general_error_code)=result2.value();

  return gresult_data_type::create_ok();
 }//if

 if(!result1.null())
 {
  (*general_error_code)=result1.value();

  return gresult_data_type::create_ok();
 }//if

 //[2015-05-05]
 //статус вектор содержит херню какую-то.

 assert((*general_error_code)==this->internal__get_unexpected_error_code());

 return gresult_data_type::create_ok();
}//get_general_error

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::get_error
                                    (const status_type* const sv_beg,
                                     const status_type* const sv_end,
                                     status_type*       const error_code)
{
 assert(sv_beg!=nullptr);
 assert(sv_beg<sv_end);
 assert(error_code!=nullptr);

 CHECK_READ_TYPED_PTR(sv_beg,static_cast<size_t>(sv_end-sv_beg));

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::get_error";

 //-----------------------------------------
 (*error_code)=this->internal__get_unexpected_error_code();

 //-----------------------------------------
 const size_t n_elements=static_cast<size_t>(sv_end-sv_beg);

 //-----------------------------------------
 if(n_elements==0)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 if(sv_beg[0]==api::errors::set02::ibp_fb_scode__arg_end)
 {
  (*error_code)=0;

  return gresult_data_type::create_ok();
 }//if

 //-----------------------------------------
 if(sv_beg[0]!=api::errors::set02::ibp_fb_scode__arg_gds)
 {
  // wrong status vector?
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#002");
 }//if

 //-----------------------------------------
 if(n_elements<2)
 {
  // wrong status vector?
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#003");
 }//if

 //-----------------------------------------
 // status_vector[1] == 0 is no error, by definition
 (*error_code)=sv_beg[1];

 return gresult_data_type::create_ok();
}//get_error

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::get_message
                                      (const status_type* const sv_beg,
                                       const status_type* const sv_end,
                                       std::wstring*      const message,
                                       LCID               const lcid)
{
 assert(sv_beg!=nullptr);
 assert(sv_beg<sv_end);
 assert(message!=nullptr);

 CHECK_READ_TYPED_PTR(sv_beg,static_cast<size_t>(sv_end-sv_beg));

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::get_message";

 //-----------------------------------------
 message->clear();

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-sv_beg)==0)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 std::wstring resultMessage;

 const status_type* s=sv_beg;

 for(;;)
 {
  assert(s>=sv_beg);
  assert(s<sv_end);

  std::wstring msgPart;

  DEBUG_CODE(const status_type* const copy_s=s;)

  const gresult_data_type
   gresult=self_type::helper__translate_msg_part(&s,
                                                 sv_end,
                                                 &msgPart,
                                                 lcid);
  assert(s>=copy_s);
  assert(s<=sv_end);

  if(gresult.code!=gresult__ok)
   return gresult;

  if(!msgPart.empty())
  {
   if(!resultMessage.empty())
    resultMessage+=L"\n";

   resultMessage+=msgPart;
  }//if

  //должны сдвинуться с места или вернуть ошибку
  assert(s>copy_s);

  if(s==sv_end)
  {
   //достигли конца статус-вектора. завершаем работу цикла.
   break;
  }//if
 }//for[ever]

 //-----------------------------------------
 message->swap(resultMessage);

 return gresult_data_type::create_ok();
}//get_message

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::get_sv_info
                                      (const status_type* const sv_beg,
                                       const status_type* const sv_end,
                                       size_t*            const sv_info__num_of_elements,
                                       size_t*            const sv_info__indirect_data_size)
{
 assert(sv_beg!=nullptr);
 assert(sv_beg<sv_end);
 assert(sv_info__num_of_elements!=nullptr);
 assert(sv_info__indirect_data_size!=nullptr);

 CHECK_READ_TYPED_PTR(sv_beg,static_cast<size_t>(sv_end-sv_beg));

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::get_sv_info";

 //-----------------------------------------
 (*sv_info__num_of_elements)=0;
 (*sv_info__indirect_data_size)=0;

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-sv_beg)==0)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 const size_t c_max_sz=structure::t_numeric_limits<size_t>::max_value();

 //-----------------------------------------
 const isc_api::t_ibp_isc_status* ps=sv_beg;

 size_t tmp__num_of_elements=0;
 size_t tmp__indirect_data_size=0;

 while(ps!=sv_end)
 {
  size_t cur_idata_size=0;

  switch(*ps)
  {
   case api::errors::set02::ibp_fb_scode__arg_end:
   {
    tmp__num_of_elements+=1;

    ps=sv_end;

    //нет косвенных данных, можно сразу идти на начало цикла
    continue;
   }//arg_end

   case api::errors::set02::ibp_fb_scode__arg_gds:
   case api::errors::set02::ibp_fb_scode__arg_warning:
   case api::errors::set02::ibp_fb_scode__arg_win32:
   case api::errors::set02::ibp_fb_scode__arg_unix:
   case api::errors::set02::ibp_fb_scode__arg_next_mach:
   case api::errors::set02::ibp_fb_scode__arg_dos:
   case api::errors::set02::ibp_fb_scode__arg_number:
   {
    if(static_cast<size_t>(sv_end-ps)<2)
    {
     assert_msg(false,"argID: "<<(*ps));

     return gresult_data_type::create_bad_sv(c_bug_check_src,L"#002");
    }//if

    tmp__num_of_elements+=2;

    ps+=2;

    //нет косвенных данных, можно сразу идти на начало цикла
    continue;
   }//case

   case api::errors::set02::ibp_fb_scode__arg_string:
   case api::errors::set02::ibp_fb_scode__arg_interpreted:
   case api::errors::set02::ibp_fb_scode__arg_sql_state:
   {
    if(static_cast<size_t>(sv_end-ps)<2)
    {
     assert_msg(false,"argID: "<<(*ps));

     return gresult_data_type::create_bad_sv(c_bug_check_src,L"#003");
    }//if

    if(ps[1]!=0)
     cur_idata_size=strlen(reinterpret_cast<const char*>(ps[1]))+1;

    tmp__num_of_elements+=2;

    ps+=2;

    break;
   }//case

   case api::errors::set02::ibp_fb_scode__arg_cstring:
   {
    if(static_cast<size_t>(sv_end-ps)<3)
    {
     assert_msg(false,"argID: "<<(*ps));

     return gresult_data_type::create_bad_sv(c_bug_check_src,L"#004");
    }//if

    cur_idata_size=static_cast<size_t>(ps[1]);

    if(cur_idata_size!=0 && ps[2]==0)
    {
     //нулевой указатель на непустую строку

     assert(false);

     return gresult_data_type::create_bad_sv(c_bug_check_src,L"#005");
    }//if

    tmp__num_of_elements+=3;

    ps+=3;

    break;
   }//case cstring

   default:
   {
    assert_msg(false,"argID: "<<(*ps));

    return gresult_data_type::create_bad_sv(c_bug_check_src,L"#006");
   }//default
  }//switch

  assert(tmp__indirect_data_size<=c_max_sz);

  if((c_max_sz-tmp__indirect_data_size)<cur_idata_size)
  {
   assert(false);

   return gresult_data_type::create_bad_sv(c_bug_check_src,L"#007");
  }//if

  tmp__indirect_data_size+=cur_idata_size;
 }//while

 assert(tmp__num_of_elements>0);

 /*all is ok*/
 (*sv_info__num_of_elements)=tmp__num_of_elements;

 (*sv_info__indirect_data_size)=tmp__indirect_data_size;

 return gresult_data_type::create_ok();
}//get_sv_info

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::move_indirect_data_to_buf
                                           (status_type*       const sv_beg,
                                            const status_type* const sv_end,
                                            void*              const buf_beg,
                                            const void*        const buf_end)
{
 assert(sv_beg!=nullptr);
 assert(sv_beg<sv_end);

 CHECK_READ_TYPED_PTR(sv_beg,static_cast<size_t>(sv_end-sv_beg));

 assert(buf_beg<=buf_end);

 CHECK_WRITE_PTR(buf_beg,((const char*)buf_end)-((const char*)buf_beg));

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::move_indirect_data_to_buf";

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-sv_beg)==0)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 typedef unsigned char byte_type;

 assert_s(sizeof(byte_type)==1);

 void* buf=buf_beg;

 //-----------------------------------------
 isc_api::t_ibp_isc_status* ps=sv_beg;

 for(;;)
 {
  if(ps==sv_end)
   return gresult_data_type::create_ok();

  assert(ps<sv_end);
  assert(buf<=buf_end);

  switch(*ps)
  {
   case api::errors::set02::ibp_fb_scode__arg_end:
   {
    return gresult_data_type::create_ok();
   }//arg_end

   case api::errors::set02::ibp_fb_scode__arg_gds:
   case api::errors::set02::ibp_fb_scode__arg_warning:
   case api::errors::set02::ibp_fb_scode__arg_win32:
   case api::errors::set02::ibp_fb_scode__arg_unix:
   case api::errors::set02::ibp_fb_scode__arg_next_mach:
   case api::errors::set02::ibp_fb_scode__arg_dos:
   case api::errors::set02::ibp_fb_scode__arg_number:
   {
    if(static_cast<size_t>(sv_end-ps)<2)
    {
     assert_msg(false,"argID: "<<(*ps));

     return gresult_data_type::create_bad_sv(c_bug_check_src,L"#002");
    }//if

    ps+=2;

    break;
   }//case

   case api::errors::set02::ibp_fb_scode__arg_string:
   case api::errors::set02::ibp_fb_scode__arg_interpreted:
   case api::errors::set02::ibp_fb_scode__arg_sql_state:
   {
    //перемещение строки с нулевым терминальным символом

    if(static_cast<size_t>(sv_end-ps)<2)
    {
     assert_msg(false,"argID: "<<(*ps));

     return gresult_data_type::create_bad_sv(c_bug_check_src,L"#003");
    }//if

    if(ps[1]!=0)
    {
     const char* src=reinterpret_cast<const char*>(ps[1]);

     char* dst=reinterpret_cast<char*>(buf);

     const size_t c_buf_tail=(reinterpret_cast<const byte_type*>(buf_end)-reinterpret_cast<const byte_type*>(buf));

     const char* const dst_end=dst+(c_buf_tail/sizeof(char));

     //-----
     for(;;)
     {
      assert(dst<=dst_end);

      if(dst==dst_end)
      {
       assert_msg(false,"argID: "<<(*ps));

       return gresult_data_type::create_bad_sv(c_bug_check_src,L"#004");
      }//if

      (*dst)=(*src);

      ++dst;

      if((*src)==0)
       break;

      ++src;
     }//for[ever]

     assert(dst<=dst_end);

     ps[1]=reinterpret_cast<isc_api::t_ibp_isc_status>(buf);

     buf=dst;
    }//if

    ps+=2;

    break;
   }//case

   case api::errors::set02::ibp_fb_scode__arg_cstring:
   {
    if(static_cast<size_t>(sv_end-ps)<3)
    {
     assert_msg(false,"argID: "<<(*ps));

     return gresult_data_type::create_bad_sv(c_bug_check_src,L"#005");
    }//if

    const size_t cur_idata_size=static_cast<size_t>(ps[1]);

    if(cur_idata_size==0)
    {
     ps[2]=0;
    }
    else
    {
     assert_hint(cur_idata_size>0);

     if(ps[2]==0)
     {
      //нулевой указатель на непустую строку

      assert(false);

      return gresult_data_type::create_bad_sv(c_bug_check_src,L"#006");
     }//if

     const size_t c_buf_tail=(reinterpret_cast<const byte_type*>(buf_end)-reinterpret_cast<const byte_type*>(buf));

     if(c_buf_tail<cur_idata_size)
     {
      assert(false);

      return gresult_data_type::create_bad_sv(c_bug_check_src,L"#007");
     }//if

     memcpy(buf,reinterpret_cast<const char*>(ps[2]),cur_idata_size);

     ps[2]=reinterpret_cast<isc_api::t_ibp_isc_status>(buf);

     buf=reinterpret_cast<byte_type*>(buf)+cur_idata_size;
    }//else cur_idata_size>0

    ps+=3;

    break;
   }//case cstring

   default:
   {
    assert_msg(false,"argID: "<<(*ps));

    return gresult_data_type::create_bad_sv(c_bug_check_src,L"#008");
   }//default
  }//switch
 }//for[ever]
}//move_indirect_data_to_buf

//helper methods ---------------------------------------------------------
const fb_common_impl__svc__status_vector_utils__v1_set02::descr2_type*
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__get_err_descr2(status_type status)const
{
 typedef structure::t_search_result<const isc_base::t_isc_error_code_descr2*> result_type;

 if(result_type const x=structure::lower_search(m_pErrDescrs,
                                                m_pErrDescrs+m_cErrDescrs,
                                                status,
                                                isc_base::t_isc_error_code_descr2::tag_less()))
 {
  assert(x.position);
  assert(x.position->isc_code==status);

  return x.position;
 }//if

 return nullptr;
}//helper__get_err_descr2

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::find_next_result_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__find_next_status_vector_element
                                           (const status_type* const cur_sv,
                                            const status_type* const end_sv)
{
 assert(cur_sv<=end_sv);

 CHECK_READ_TYPED_PTR(cur_sv,static_cast<size_t>(end_sv-cur_sv));

 //-----------------------------------------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__find_next_status_vector_element";

 //-----------------------------------------------------------------------
 if(cur_sv==end_sv)
  return find_next_result_type(end_sv,gresult_data_type::create_ok());

 switch(*cur_sv)
 {
  case api::errors::set02::ibp_fb_scode__arg_end:
  {
   return find_next_result_type(end_sv,gresult_data_type::create_ok());
  }//ibp_fb_scode__arg_end

  case api::errors::set02::ibp_fb_scode__arg_cstring:       //3.  (length, pointer)
  {
   if(static_cast<size_t>(end_sv-cur_sv)<3)
   {
    //некорректная структура статус вектора
    assert(false);

    return find_next_result_type(end_sv,gresult_data_type::create_bad_sv(c_bug_check_src,L"#001"));
   }//if

   return find_next_result_type(cur_sv+3,gresult_data_type::create_ok());
  }//ibp_fb_scode__arg_cstring

  case api::errors::set02::ibp_fb_scode__arg_gds:           //1.  generic DSRI (status value)
  case api::errors::set02::ibp_fb_scode__arg_string:        //2.  string argument (string)
  case api::errors::set02::ibp_fb_scode__arg_number:        //4.  numeric argument (long)
  case api::errors::set02::ibp_fb_scode__arg_interpreted:   //5.  interpreted status code (string)
  case api::errors::set02::ibp_fb_scode__arg_vms:           //6.  VAX/VMS status code (long)
  case api::errors::set02::ibp_fb_scode__arg_unix:          //7.  UNIX (error code)
  case api::errors::set02::ibp_fb_scode__arg_domain:        //8.  Apollo/Domain (error code)
  case api::errors::set02::ibp_fb_scode__arg_dos:           //9.  MSDOS/OS2 (error code)
  case api::errors::set02::ibp_fb_scode__arg_mpexl:         //10. HP MPE/XL (error code)
  case api::errors::set02::ibp_fb_scode__arg_mpexl_ipc:     //11. HP MPE/XL IPC (error code)
  case api::errors::set02::ibp_fb_scode__arg_next_mach:     //15. NeXT/Mach (error code)
  case api::errors::set02::ibp_fb_scode__arg_netware:       //16. NetWare (error code)
  case api::errors::set02::ibp_fb_scode__arg_win32:         //17. Win32 (error code)
  case api::errors::set02::ibp_fb_scode__arg_warning:       //18. warning argument (status value)
  case api::errors::set02::ibp_fb_scode__arg_sql_state:     //19. sql_state (string)
  {
   if(static_cast<size_t>(end_sv-cur_sv)<2)
   {
    //некорректная структура статус вектора
    assert_msg(false,"arg: "<<(*cur_sv));

    return find_next_result_type(end_sv,gresult_data_type::create_bad_sv(c_bug_check_src,L"#002"));
   }//if

   return find_next_result_type(cur_sv+2,gresult_data_type::create_ok());
  }//api::errors::set02::ibp_fb_scode__arg_sql_state
 }//switch

 assert_msg(false,"arg: "<<(*cur_sv));

 return find_next_result_type(end_sv,gresult_data_type::create_bad_sv(c_bug_check_src,L"#003"));
}//helper__find_next_status_vector_element

//------------------------------------------------------------------------
bool fb_common_impl__svc__status_vector_utils__v1_set02::helper__is_common_error_code
                                           (const descr2_type* const err_descr2)
{
 assert(err_descr2);

 /// 22000, 42000 and HY000 are general errors.
 /// We may be able to find something more precise if we keep scanning.

 if(err_descr2->eq_sqlstate2(IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS))
  return true;

 if(err_descr2->eq_sqlstate2(IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS))
  return true;

 if(err_descr2->eq_sqlstate2(IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS))
  return true;

 return false;
}//helper__is_common_error_code

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            std::wstring*       const msg_part,
                                            LCID                const lcid)const
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<sv_end);
 assert(msg_part!=nullptr);

 CHECK_READ_TYPED_PTR(*pps,static_cast<size_t>(sv_end-(*pps)));

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part";

 //-----------------------------------------
 msg_part->clear();

 switch(**pps)
 {
  case api::errors::set02::ibp_fb_scode__arg_end:
   return helper__translate_msg_part__arg_end
           (pps,sv_end,msg_part);

  case api::errors::set02::ibp_fb_scode__arg_sql_state:
   return helper__translate_msg_part__arg_sql_state
           (pps,sv_end,msg_part);

  case api::errors::set02::ibp_fb_scode__arg_interpreted:
   return helper__translate_msg_part__arg_interpreted
           (pps,sv_end,msg_part,lcid);

  case api::errors::set02::ibp_fb_scode__arg_dos:
   return helper__translate_msg_part__arg_dos
           (pps,sv_end,msg_part,lcid);

  case api::errors::set02::ibp_fb_scode__arg_next_mach:
   return helper__translate_msg_part__arg_next_mach
           (pps,sv_end,msg_part,lcid);

  case api::errors::set02::ibp_fb_scode__arg_unix:
   return helper__translate_msg_part__arg_unix
           (pps,sv_end,msg_part,lcid);

  case api::errors::set02::ibp_fb_scode__arg_win32:
   return helper__translate_msg_part__arg_win32
           (pps,sv_end,msg_part,lcid);

  case api::errors::set02::ibp_fb_scode__arg_gds:
   return helper__translate_msg_part__arg_gds
           (pps,sv_end,msg_part,lcid);

  case api::errors::set02::ibp_fb_scode__arg_warning:
   return helper__translate_msg_part__arg_warning
           (pps,sv_end,msg_part,lcid);
 }//switch

 //-----------------------------------------
 assert_msg(false,"(**pps): "<<(**pps));

 return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
}//helper__translate_msg_part

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_end
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            std::wstring*       const DEBUG_CODE(msg_part))
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<sv_end);
 assert(msg_part!=nullptr);

 assert(msg_part->empty());

 CHECK_READ_TYPED_PTR(*pps,static_cast<size_t>(sv_end-(*pps)));

 assert((**pps)==api::errors::set02::ibp_fb_scode__arg_end);

 (*pps)=sv_end;

 return gresult_data_type::create_ok();
}//helper__translate_msg_part__arg_end

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_sql_state
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            std::wstring*       const DEBUG_CODE(msg_part))
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<sv_end);
 assert(msg_part!=nullptr);

 assert(msg_part->empty());

 CHECK_READ_TYPED_PTR(*pps,static_cast<size_t>(sv_end-(*pps)));

 assert((**pps)==api::errors::set02::ibp_fb_scode__arg_sql_state);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_sql_state";

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-(*pps))<2)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 (*pps)+=2;

 return gresult_data_type::create_ok();
}//helper__translate_msg_part__arg_sql_state

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_interpreted
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            std::wstring*       const msg_part,
                                            LCID                const lcid)
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<sv_end);
 assert(msg_part!=nullptr);

 assert(msg_part->empty());

 CHECK_READ_TYPED_PTR(*pps,static_cast<size_t>(sv_end-(*pps)));

 assert((**pps)==api::errors::set02::ibp_fb_scode__arg_interpreted);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_interpreted";

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-(*pps))<2)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 if((*pps)[1]!=0)
 {
  //! \todo
  //!  Возможно здесь имеет смысл конвертировать с учетом кодовой страницы подключения.

  bool error=false;

  std::wstring tmp;

  structure::ansi_to_unicode
   (&tmp,
    reinterpret_cast<const char*>((*pps)[1]),
    lib::structure::negative_one,
    &error);

  if(!error)
  {
   msg_part->swap(tmp);
  }
  else
  {
   const IBP_ErrorVariant arg(L"arg_interpreted");

   TIBP_MessageTextBuilder::Build
    (msg_part,
     /*varSubSystemId*/ole_lib::TVariant::empty_variant,
     ibp_mce_common__translate_sys_data_to_unicode_1,
     lcid,
     1,
     &arg,
     E_FAIL);
  }//if
 }//if

 (*pps)+=2;

 return gresult_data_type::create_ok();
}//translate_msg_part__arg_interpreted

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_dos
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            std::wstring*       const msg_part,
                                            LCID                const lcid)
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<sv_end);
 assert(msg_part!=nullptr);

 assert(msg_part->empty());

 CHECK_READ_TYPED_PTR(*pps,static_cast<size_t>(sv_end-(*pps)));

 assert((**pps)==api::errors::set02::ibp_fb_scode__arg_dos);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_dos";

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-(*pps))<2)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 const IBP_ErrorVariant arg((*pps)[1]);

 TIBP_MessageTextBuilder::Build
    (msg_part,
     /*varSubSystemId*/ole_lib::TVariant::empty_variant,
     ibp_mce__error_from_dos_1,
     lcid,
     1,
     &arg,
     E_FAIL);

 (*pps)+=2;

 return gresult_data_type::create_ok();
}//helper__translate_msg_part__arg_dos

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_next_mach
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            std::wstring*       const msg_part,
                                            LCID                const lcid)
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<sv_end);
 assert(msg_part!=nullptr);

 assert(msg_part->empty());

 CHECK_READ_TYPED_PTR(*pps,static_cast<size_t>(sv_end-(*pps)));

 assert((**pps)==api::errors::set02::ibp_fb_scode__arg_next_mach);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_next_mach";

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-(*pps))<2)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 const IBP_ErrorVariant arg((*pps)[1]);

 TIBP_MessageTextBuilder::Build
    (msg_part,
     /*varSubSystemId*/ole_lib::TVariant::empty_variant,
     ibp_mce__error_from_next_mach_1,
     lcid,
     1,
     &arg,
     E_FAIL);

 (*pps)+=2;

 return gresult_data_type::create_ok();
}//helper__translate_msg_part__arg_next_mach

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_unix
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            std::wstring*       const msg_part,
                                            LCID                const lcid)
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<sv_end);
 assert(msg_part!=nullptr);

 assert(msg_part->empty());

 CHECK_READ_TYPED_PTR(*pps,static_cast<size_t>(sv_end-(*pps)));

 assert((**pps)==api::errors::set02::ibp_fb_scode__arg_unix);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_unix";

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-(*pps))<2)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 {
  assert(structure::can_numeric_cast<int>((*pps)[1]));

  const int errnum=static_cast<int>((*pps)[1]);

  //---------
  std::array<IBP_ErrorVariant,2> args;

  args[0]=errnum;

  std::wstring msgtext;

  if(self_type::helper__get_unix_error_msg(errnum,&msgtext))
  {
   args[1]=msgtext;

   assert(args[1].Data().vt==IBP_EVT::V_WSTR);
  }
  else
  {
   args[1]=ibp_mce_text__unknown_error1_0;

   assert(args[1].Data().vt==IBP_EVT::V_IBP_MSG_CODE);
  }//else

  //---------
  TIBP_MessageTextBuilder::Build
     (msg_part,
      /*varSubSystemId*/ole_lib::TVariant::empty_variant,
      ibp_mce__error_from_unix_2,
      lcid,
      args.size(),
      args.data(),
      E_FAIL);
 }//local

 (*pps)+=2;

 return gresult_data_type::create_ok();
}//helper__translate_msg_part__arg_unix

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_win32
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            std::wstring*       const msg_part,
                                            LCID                const lcid)
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<sv_end);
 assert(msg_part!=nullptr);

 assert(msg_part->empty());

 CHECK_READ_TYPED_PTR(*pps,static_cast<size_t>(sv_end-(*pps)));

 assert((**pps)==api::errors::set02::ibp_fb_scode__arg_win32);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_win32";

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-(*pps))<2)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 {
  assert(static_cast<DWORD>((*pps)[1])==(*pps)[1]);

  const DWORD errnum=static_cast<DWORD>((*pps)[1]);

  //---------
  std::array<IBP_ErrorVariant,2> args;

  args[0]=std::wstring(L"0x").append(lib::structure::to_hex::upper<wchar_t>(errnum).c_str());

  std::wstring msgtext;

  if(self_type::helper__get_win32_error_msg(errnum,&msgtext,lcid))
  {
   args[1]=msgtext;

   assert(args[1].Data().vt==IBP_EVT::V_WSTR);
  }
  else
  if(self_type::helper__get_win32_error_msg(errnum,&msgtext,/*neutral*/0))
  {
   args[1]=msgtext;

   assert(args[1].Data().vt==IBP_EVT::V_WSTR);
  }
  else
  {
   args[1]=ibp_mce_text__unknown_error1_0;

   assert(args[1].Data().vt==IBP_EVT::V_IBP_MSG_CODE);
  }//else

  //---------
  TIBP_MessageTextBuilder::Build
     (msg_part,
      /*varSubSystemId*/ole_lib::TVariant::empty_variant,
      ibp_mce__error_from_win32_2,
      lcid,
      args.size(),
      args.data(),
      E_FAIL);
 }//local

 (*pps)+=2;

 return gresult_data_type::create_ok();
}//helper__translate_msg_part__arg_win32

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_gds
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            std::wstring*       const msg_part,
                                            LCID                const lcid)const
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<sv_end);
 assert(msg_part!=nullptr);

 assert(msg_part->empty());

 CHECK_READ_TYPED_PTR(*pps,static_cast<size_t>(sv_end-(*pps)));

 assert((**pps)==api::errors::set02::ibp_fb_scode__arg_gds);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_gds";

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-(*pps))<2)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 const isc_api::t_ibp_isc_status isc_error_code=(*pps)[1];

 (*pps)+=2;

 //----------------------------------------- 1. выборка параметров сообщения

 // [2015-12-09]
 //  Параметры нужно выбрать в любом случае.

 args_type args;

 {
  const gresult_data_type gresult=self_type::helper__get_args(pps,sv_end,args);

  if(gresult!=gresult__ok)
   return gresult;
 }//local

 //-----------------------------------------
 if(isc_error_code==0)
 {
  return gresult_data_type::create_ok();
 }//if

 //----------------------------------------- 2. ищем описание ошибки
 const isc_base::t_isc_error_code_descr2* const
  isc_error_descr2=this->helper__get_err_descr2(isc_error_code);

 if(isc_error_descr2==nullptr)
 {
  //Не нашли.

  //Пример:
  // FB 1.5: 336068783

  //---------
  const IBP_ErrorVariant arg(isc_error_code);

  //---------
  TIBP_MessageTextBuilder::Build
     (msg_part,
      /*varSubSystemId*/ole_lib::TVariant::empty_variant,
      ibp_mce__unexpected_isc_error_1,
      lcid,
      1,
      &arg,
      E_FAIL);

  //------- добавляем параметры, чтобы можно было хоть что-то понять.
  if(!args.empty())
  {
   (*msg_part)+=L' ';

   structure::wstr_formatter fparamInfo(L"[arg_%1=%2]");

   for(size_t i=0;i!=args.size();++i)
   {
    fparamInfo<<structure::flush<<i;

    std::wstring paramValue;

    TIBP_MessageTextBuilder::Build
       (&paramValue,
        /*varSubSystemId*/ole_lib::TVariant::empty_variant,
        ibp_mce_unknown_error_1,
        lcid,
        1,
        &args[i],
        E_FAIL);

    fparamInfo<<paramValue;

    (*msg_part)+=fparamInfo.str();
   }//for[ever]
  }//if !args.empty()

  return gresult_data_type::create_ok();
 }//if isc_error_descr2==nullptr

 //-----------------------------------------
 assert(isc_error_descr2!=nullptr);

 assert(isc_error_descr2->isc_code==isc_error_code);

 //----------------------------------------- 2. Формирование текста ошибки
 this->internal__build_err_message
  (msg_part,
   isc_error_descr2->message_id,
   lcid,
   args.size(),
   args.data());

 return gresult_data_type::create_ok();
}//helper__translate_msg_part__arg_gds

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_warning
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            std::wstring*       const msg_part,
                                            LCID                const lcid)const
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<sv_end);
 assert(msg_part!=nullptr);

 assert(msg_part->empty());

 CHECK_READ_TYPED_PTR(*pps,static_cast<size_t>(sv_end-(*pps)));

 assert((**pps)==api::errors::set02::ibp_fb_scode__arg_warning);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__translate_msg_part__arg_warning";

 //-----------------------------------------
 if(static_cast<size_t>(sv_end-(*pps))<2)
 {
  assert(false);

  return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
 }//if

 //-----------------------------------------
 const isc_api::t_ibp_isc_status isc_error_code=(*pps)[1];

 (*pps)+=2;

 //----------------------------------------- 1. выборка параметров сообщения

 // [2015-12-09]
 //  Параметры нужно выбрать в любом случае.

 args_type args;

 {
  const gresult_data_type gresult=self_type::helper__get_args(pps,sv_end,args);

  if(gresult!=gresult__ok)
   return gresult;
 }//local

 //-----------------------------------------
 if(isc_error_code==0)
 {
  return gresult_data_type::create_ok();
 }//if

 //----------------------------------------- 2. ищем описание ошибки
 const isc_base::t_isc_error_code_descr2* const
  isc_error_descr2=this->helper__get_err_descr2(isc_error_code);

 if(isc_error_descr2==nullptr)
 {
  //Не нашли.

  //Пример:
  // FB 1.5: 336068783

  //---------
  const IBP_ErrorVariant arg(isc_error_code);

  //---------
  TIBP_MessageTextBuilder::Build
     (msg_part,
      /*varSubSystemId*/ole_lib::TVariant::empty_variant,
      ibp_mce__unexpected_isc_warning_1,
      lcid,
      1,
      &arg,
      E_FAIL);

  //------- добавляем параметры, чтобы можно было хоть что-то понять.
  if(!args.empty())
  {
   (*msg_part)+=L' ';

   structure::wstr_formatter fparamInfo(L"[arg_%1=%2]");

   for(size_t i=0;i!=args.size();++i)
   {
    fparamInfo<<structure::flush<<i;

    std::wstring paramValue;

    TIBP_MessageTextBuilder::Build
       (&paramValue,
        /*varSubSystemId*/ole_lib::TVariant::empty_variant,
        ibp_mce_unknown_error_1,
        lcid,
        1,
        &args[i],
        E_FAIL);

    fparamInfo<<paramValue;

    (*msg_part)+=fparamInfo.str();
   }//for[ever]
  }//if !args.empty()

  return gresult_data_type::create_ok();
 }//if isc_error_descr2==nullptr

 //-----------------------------------------
 assert(isc_error_descr2!=nullptr);

 assert(isc_error_descr2->isc_code==isc_error_code);

 //----------------------------------------- 2. Формирование текста ошибки
 this->internal__build_err_message
  (msg_part,
   isc_error_descr2->message_id,
   lcid,
   args.size(),
   args.data());

 return gresult_data_type::create_ok();
}//helper__translate_msg_part__arg_warning

//------------------------------------------------------------------------
bool fb_common_impl__svc__status_vector_utils__v1_set02::helper__get_unix_error_msg
                                           (int           const errnum,
                                            std::wstring* const msg)

{
 assert(msg!=nullptr);

 msg->clear();

 wchar_t tmp[2048];

 if(_wcserror_s(tmp,_DIM_(tmp),errnum)!=0)
  return false;

 const wchar_t* const e=std::find(tmp,_END_(tmp),0);

 if(e==tmp)
  return false; //получен пустой текст

 msg->assign(tmp,e-tmp);

 return true;
}//helper__get_unix_error_msg

//------------------------------------------------------------------------
bool fb_common_impl__svc__status_vector_utils__v1_set02::helper__get_win32_error_msg
                                           (DWORD         const errnum,
                                            std::wstring* const msg,
                                            LCID          const lcid)
{
 assert(msg!=nullptr);

 msg->clear();

 WCHAR tmp[2048];

 const DWORD r=::FormatMessageW
                  (/*dwFlags*/FORMAT_MESSAGE_FROM_SYSTEM
                             |FORMAT_MESSAGE_IGNORE_INSERTS
                             |FORMAT_MESSAGE_MAX_WIDTH_MASK,
                   /*lpSource*/nullptr,
                   /*dwMessageId*/errnum,
                   /*dwLanguageId*/LANGIDFROMLCID(lcid),
                   /*lpBuffer*/tmp,
                   /*nSize*/_DIM_(tmp),
                   /*Arguments*/nullptr);
 if(r==0)
  return false;

 assert_hint(r>0);

 const WCHAR* const e=std::find(tmp,_END_(tmp),0);

 if(e==_END_(tmp))
  return false;

 const WCHAR* const e2
  =structure::total_skip_spaces_back(static_cast<const WCHAR*>(tmp),e);

 if(tmp==e2)
  return false;

 msg->assign(static_cast<const WCHAR*>(tmp),e2);

 return true;
}//helper__get_win32_error_msg

//------------------------------------------------------------------------
fb_common_impl__svc__status_vector_utils__v1_set02::gresult_data_type
 fb_common_impl__svc__status_vector_utils__v1_set02::helper__get_args
                                           (const status_type** const pps,
                                            const status_type*  const sv_end,
                                            args_type&                args)
{
 assert(pps!=nullptr);
 assert((*pps)!=nullptr);
 assert((*pps)<=sv_end);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"fb_common_impl__svc__status_vector_utils__v1_set02::helper__get_args";

 //-----------------------------------------
 args.clear();

 if((*pps)==sv_end)
  return gresult_data_type::create_ok();

 args.reserve(min(self_type::c_max_expected_args_count,(sv_end-(*pps))/2));

 while((*pps)!=sv_end)
 {
  assert((*pps)<sv_end);

  const isc_api::t_ibp_isc_status argID=(*pps)[0];

  //--------------------------------------------------------------
  if(argID==api::errors::set02::ibp_fb_scode__arg_string)
  {
   if(static_cast<size_t>(sv_end-(*pps))<2)
   {
    assert(false);

    return gresult_data_type::create_bad_sv(c_bug_check_src,L"#001");
   }//if

   args.emplace_back(reinterpret_cast<const char*>((*pps)[1]));

   assert(args.back().Data().vt==IBP_EVT::V_STR);

   (*pps)+=2;

   continue;
  }//if arg_string

  //--------------------------------------------------------------
  if(argID==api::errors::set02::ibp_fb_scode__arg_number)
  {
   if(static_cast<size_t>(sv_end-(*pps))<2)
   {
    assert(false);

    return gresult_data_type::create_bad_sv(c_bug_check_src,L"#002");
   }//if

   // [2022-10-20] was: push_back
   args.emplace_back((*pps)[1]);//throw

   (*pps)+=2;

   continue;
  }//if arg_number

  //--------------------------------------------------------------
  if(argID==api::errors::set02::ibp_fb_scode__arg_cstring)
  {
   if(static_cast<size_t>(sv_end-(*pps))<3)
   {
    assert(false);

    return gresult_data_type::create_bad_sv(c_bug_check_src,L"#003");
   }//if

   const size_t sz=static_cast<size_t>((*pps)[1]);

   const char* const ptr=reinterpret_cast<const char*>((*pps)[2]);

   if(sz!=0 && ptr==nullptr)
   {
    assert(false);

    return gresult_data_type::create_bad_sv(c_bug_check_src,L"#004");
   }//if

   args.emplace_back(structure::make_str_box(ptr,sz));//throw

   assert(args.back().Data().vt==IBP_EVT::V_STR);

   (*pps)+=3;

   continue;
  }//if

  break;
 }//while

 return gresult_data_type::create_ok();
}//helper__get_args

////////////////////////////////////////////////////////////////////////////////
}/*nms impl*/}/*nms common*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
