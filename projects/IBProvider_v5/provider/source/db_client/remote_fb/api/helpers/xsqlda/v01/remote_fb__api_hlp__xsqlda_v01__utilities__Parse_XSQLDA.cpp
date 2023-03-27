////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda_v01__utilities__Parse_XSQLDA.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR (V1).
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__flags.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"

#include <structure/t_zero.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_V01__Utilities

RemoteFB__API_HLP__XSQLDA_V01__Utilities::parse_result_type
 RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
                                  (size_t              const buffer_size,
                                   const byte_type*    const buffer,
                                   bool                const is_first_info_block,
                                   protocol::P_USHORT        start_index,
                                   isc_api::XSQLDA_V1* const pXSQLDA)
{
 assert(pXSQLDA!=nullptr);
 assert(pXSQLDA->version==isc_api::XSQLDA_V1::c_version_num);
 assert(pXSQLDA->sqln==0 || pXSQLDA->sqln>0);

 CHECK_READ_TYPED_PTR(buffer,buffer_size);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA";

 //-----------------------------------------
 const byte_type* pos=buffer;

 const byte_type* const _e_buffer=buffer+buffer_size;

 if(pos==_e_buffer)
 {
  IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd
   (c_bugcheck_src,
    L"#001");
 }//if

 if((*pos)!=isc_api::ibp_isc_info_sql_describe_vars)
 {
  IBP_ThrowBugCheck_InfoBuf__UnknownTag
   (c_bugcheck_src,
    L"#002",
    *pos);
 }//if

 ++pos;

 //Читаем общее число элементов в XSQLDA

 //При обработке вторичных блоков проверяем стабильность sqld

 size_t sqld=0;

 pos=self_type::Helper__ReadNumber
      (pos,
       _e_buffer,
       &sqld,
       L"isc_info_sql_describe_vars"); //throw

 if(is_first_info_block)
 {
  assert(start_index==0);

  if(!structure::can_numeric_cast(&pXSQLDA->sqld,sqld))
  {
   //ERROR - [BUG CHECK] sqld is too large

   IBP_ErrorUtils::Throw__Error
    (DB_E_NOTSUPPORTED,
     ibp_subsystem__remote_fb,
     ibp_mce_isc__too_many_vars_for_XSQLDA_2,
     sqld,
     structure::get_numeric_limits(pXSQLDA->sqld).max_value());
  }//if

  structure::static_numeric_cast(&pXSQLDA->sqld,sqld);

  if(pXSQLDA->sqln<pXSQLDA->sqld)
   return parse_result_type(structure::zero,true); //обработка завершена
 }
 else
 {
  assert(!is_first_info_block);

  //при повторном вызове у нас должен быть корректный sqld
  assert(structure::can_numeric_cast<size_t>(pXSQLDA->sqld));

  //и, кстати, неотрицательный.
  assert(pXSQLDA->sqld>0);

  assert(pXSQLDA->sqld<=pXSQLDA->sqln);

  if(sqld!=static_cast<size_t>(pXSQLDA->sqld))
  {
   //ERROR - [BUG CHECK] incorrect data in secondary block

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_isc__bug_check__incorrect_sqld_in_secondary_block_with_xsqlda_data_5,
     c_bugcheck_src,
     L"#003",
     sqld,
     pXSQLDA->sqld,
     start_index);
  }//else
 }//else !is_first_block_info

 //формально, стартовый индекс должен быть меньше или равен sqld
 assert_msg(start_index<=sqld,"start_index: "<<start_index<<". sqld: "<<sqld);

 //-----------------------------------------
 for(;;)
 {
  if(pos==_e_buffer)
   break; //штатное завершение работы

  if((*pos)==isc_api::ibp_isc_info_end)
   break; //штатное завершение работы

  /* #PT001 */
  if((*pos)==isc_api::ibp_isc_info_truncated)
  {
   if(start_index==sqld)
   {
    //ERROR - WTF? все элементы обработали, а нам говорят, что данные обрезаны.

    Helper__ThrowBugCheck__UnexpectedTruncation
     (c_bugcheck_src,
      L"#004",
      sqld);
   }//if

   assert(start_index<sqld);

   return parse_result_type(start_index,false);
  }//if

  if((*pos)==isc_api::ibp_isc_info_sql_sqlda_seq)
  {
   if(start_index==sqld)
   {
    //ERROR - unexpected elements for XSQLDA

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_mce_isc__bug_check__unexpected_xvars_for_xsqlda_3,
      c_bugcheck_src,
      L"#005",
      sqld);
   }//if start_index==sqld

   assert(sqld>0);
   assert(start_index<sqld);

   //---------------------------------------
   ++pos;

   protocol::P_USHORT xvar_ordinal=0;

   pos=self_type::Helper__ReadNumber
        (pos,
         _e_buffer,
         &xvar_ordinal,
         L"isc_info_sql_sqlda_seq"); //throw

   if(xvar_ordinal==0 || sqld<xvar_ordinal)
   {
    //ERROR - xsqlvar sequential number is out of range

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_mce_isc__bug_check__out_of_range_of_xvar_sequential_number_5,
      c_bugcheck_src,
      L"#006",
      xvar_ordinal,
      sqld,
      start_index);
   }//if

   assert(xvar_ordinal>0);

   assert_msg(start_index<sqld,"start_index: "<<start_index<<". sqld: "<<sqld);

   const protocol::P_USHORT xvar_index=xvar_ordinal-1;

   //Контролируем упорядоченность xvar_index
   assert(start_index<sqld);
   assert(start_index<structure::get_numeric_limits(start_index).max_value());

   if(xvar_index!=start_index)
   {
    //ERROR - incorrect sequential number

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_mce_isc__bug_check__unexpected_xvar_sequential_number_4,
      c_bugcheck_src,
      L"#007",
      xvar_ordinal,
      start_index+1);
   }//if

   isc_api::XSQLVAR_V1* const pCurXSQLVAR=&pXSQLDA->sqlvar[xvar_index];

   enum
   {
    xvar_flag__sqltype    =0x01,         // 1
    xvar_flag__sqlsubtype =0x02,         // 2
    xvar_flag__scale      =0x04,         // 3
    xvar_flag__length     =0x08,         // 4
    xvar_flag__field      =0x10,         // 5
    xvar_flag__relation   =0x20,         // 6
    xvar_flag__owner      =0x40,         // 7
    xvar_flag__alias      =0x80,         // 8
   };

   RemoteFB__Flags<size_t> XVarFlags;

   try
   {
    for(;;)
    {
     //мы должны выйти или на truncated или на sql_describe_end
     if(pos==_e_buffer)
     {
      IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd
       (c_bugcheck_src,
        L"#008");
     }//if

     assert(pos<_e_buffer);

     //
     // [2023-02-24]
     //  We will stop in the 'truncated' tag.
     // 
     //  This is unified with above code [#PT001].
     //

     if((*pos)==isc_api::ibp_isc_info_truncated)
      return parse_result_type(start_index,false);

     //-------------------------------------------------------
     const byte_type item_id=*pos;

     ++pos;

     if(item_id==isc_api::ibp_isc_info_sql_describe_end)
      break; //закончили обрабатывать VAR-блок

     switch(item_id)
     {
      //------------------------------------------------------
      case isc_api::ibp_isc_info_sql_type:
      {
       if(XVarFlags.test(xvar_flag__sqltype))
       {
        //ERROR - повторное определение элемента

        Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue(L"sqltype");
       }//if

       pos=self_type::Helper__ReadNumber
            (pos,
             _e_buffer,
             &pCurXSQLVAR->sqltype,
             L"isc_info_sql_type"); //throw

       XVarFlags.set(xvar_flag__sqltype);
       break;
      }//case - sql_type

      //------------------------------------------------------
      case isc_api::ibp_isc_info_sql_sub_type:
      {
       if(XVarFlags.test(xvar_flag__sqlsubtype))
       {
        //ERROR - повторное определение элемента

        Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue(L"sqlsubtype");
       }//if

       pos=self_type::Helper__ReadNumber
            (pos,
             _e_buffer,
             &pCurXSQLVAR->sqlsubtype,
             L"isc_info_sql_sub_type"); //throw

       XVarFlags.set(xvar_flag__sqlsubtype);
       break;
      }//case - sqlsubtype

      //------------------------------------------------------
      case isc_api::ibp_isc_info_sql_scale:
      {
       if(XVarFlags.test(xvar_flag__scale))
       {
        //ERROR - повторное определение элемента

        Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue(L"sqlscale");
       }//if

       pos=self_type::Helper__ReadNumber
            (pos,
             _e_buffer,
             &pCurXSQLVAR->sqlscale,
             L"isc_info_sql_scale"); //throw

       XVarFlags.set(xvar_flag__scale);
       break;
      }//case - scale

      //------------------------------------------------------
      case isc_api::ibp_isc_info_sql_length:
      {
       if(XVarFlags.test(xvar_flag__length))
       {
        //ERROR - повторное определение элемента

        Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue(L"sqllen");
       }//if

       pos=self_type::Helper__ReadNumber
            (pos,
             _e_buffer,
             &pCurXSQLVAR->sqllen,
             L"isc_info_sql_length"); //throw

       XVarFlags.set(xvar_flag__length);
       break;
      }//case - length

      //------------------------------------------------------
      case isc_api::ibp_isc_info_sql_field:
      {
       if(XVarFlags.test(xvar_flag__field))
       {
        //ERROR - повторное определение элемента

        Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue(L"sqlname");
       }//if

       pos=Helper__ReadString
            (pos,
             _e_buffer,
             _DIM_(pCurXSQLVAR->sqlname),
             pCurXSQLVAR->sqlname,
             &pCurXSQLVAR->sqlname_length,
             L"isc_info_sql_field"); //throw

       XVarFlags.set(xvar_flag__field);
       break;
      }//case - field

      //------------------------------------------------------
      case isc_api::ibp_isc_info_sql_relation:
      {
       if(XVarFlags.test(xvar_flag__relation))
       {
        //ERROR - повторное определение элемента

        Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue(L"relname");
       }//if

       pos=Helper__ReadString
            (pos,
             _e_buffer,
             _DIM_(pCurXSQLVAR->relname),
             pCurXSQLVAR->relname,
             &pCurXSQLVAR->relname_length,
             L"isc_info_sql_relation"); //throw

       XVarFlags.set(xvar_flag__relation);
       break;
      }//case - relation

      //------------------------------------------------------
      case isc_api::ibp_isc_info_sql_owner:
      {
       if(XVarFlags.test(xvar_flag__owner))
       {
        //ERROR - повторное определение элемента

        Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue(L"ownname");
       }//if

       pos=Helper__ReadString
            (pos,
             _e_buffer,
             _DIM_(pCurXSQLVAR->ownname),
             pCurXSQLVAR->ownname,
             &pCurXSQLVAR->ownname_length,
             L"isc_info_sql_owner"); //throw

       XVarFlags.set(xvar_flag__owner);
       break;
      }//case - owner

      //------------------------------------------------------
      case isc_api::ibp_isc_info_sql_alias:
      {
       if(XVarFlags.test(xvar_flag__alias))
       {
        //ERROR - повторное определение элемента

        Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue(L"aliasname");
       }//if

       pos=Helper__ReadString
            (pos,
             _e_buffer,
             _DIM_(pCurXSQLVAR->aliasname),
             pCurXSQLVAR->aliasname,
             &pCurXSQLVAR->aliasname_length,
             L"isc_info_sql_alias"); //throw

       XVarFlags.set(xvar_flag__alias);
       break;
      }//case - alias

      //------------------------------------------------------
      default:
      {
       IBP_ThrowBugCheck_InfoBuf__UnknownTag
        (c_bugcheck_src,
         L"#009",
         item_id);
      }//default
     }//switch - item_id
    }//for[ever]

    //---------------------------------------закончили обработку данных XSQLVAR

    //Проверяем что заполнили все поля XSQLVAR

    if(!XVarFlags.test(xvar_flag__sqltype))
    {
     //ERROR - отсутствует описание поля

     Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
      (L"sqltype");
    }//if - type

    if(!XVarFlags.test(xvar_flag__sqlsubtype))
    {
     //ERROR - отсутствует описание поля

     Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
      (L"sqlsubtype");
    }//if - sub_type

    if(!XVarFlags.test(xvar_flag__scale))
    {
     //ERROR - отсутствует описание поля

     Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
      (L"sqlscale");
    }//if - scale

    if(!XVarFlags.test(xvar_flag__length))
    {
     //ERROR - отсутствует описание поля

     Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
      (L"sqllen");
    }//if - length

    if(!XVarFlags.test(xvar_flag__field))
    {
     //ERROR - отсутствует описание поля

     Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
      (L"sqlname");
    }//if - field

    if(!XVarFlags.test(xvar_flag__relation))
    {
     //ERROR - отсутствует описание поля

     Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
      (L"relname");
    }//if - relation

    if(!XVarFlags.test(xvar_flag__owner))
    {
     //ERROR - отсутствует описание поля

     Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
      (L"ownname");
    }//if - owner

    if(!XVarFlags.test(xvar_flag__alias))
    {
     //ERROR - отсутствует описание поля

     Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
      (L"aliasname");
    }//if - alias

    //Проверяем неотрицательное значение length поля
    if(pCurXSQLVAR->sqllen<0)
    {
     //ERROR - incorrect length of var

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_subsystem__remote_fb,
       ibp_mce_isc__bug_check__negative_sqllength_in_xsqlvar_1,
       pCurXSQLVAR->sqllen);
    }//if
   }
   catch(const std::exception& e)
   {
    IBP_ErrorUtils::Throw__Error
     (e,
      E_FAIL,
      ibp_subsystem__remote_fb,
      ibp_mce_isc__failed_to_process_xsqlvar_info_raw_data_1,
      xvar_index);
   }//catch

   //--------------------------------------- пытаемся обработать следующий блок

   //у нас не должно быть переполнения. индекс гуляет в диапазоне [0..65534].
   //65535 - это допустимое значение индекса недействительного элемента.
   assert(start_index!=structure::get_numeric_limits(start_index).max_value());

   ++start_index;

   continue;
  }//if ibp_isc_info_sql_sqlda_seq

  IBP_ThrowBugCheck_InfoBuf__UnknownTag
   (c_bugcheck_src,
    L"#010",
    *pos);
 }//for[ever]

 //Штатное достижение конца буфера с данными.

 //Проверяем что мы сформировали количество описаний равное sqld

 if(start_index!=sqld)
 {
  //ERROR - Количество загруженных описаний меньше чем ожидалось.

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb,
    ibp_mce_isc__bug_check__incompleted_definition_of_xvars_2,
    start_index,
    sqld);
 }//if

 assert(structure::can_numeric_cast<parse_result_type::first_type>(start_index));

 return parse_result_type(static_cast<parse_result_type::first_type>(start_index),true);
}//Parse_XSQLDA

//------------------------------------------------------------------------
template<typename T>
static const RemoteFB__API_HLP__XSQLDA_V01__Utilities::byte_type*
 RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ReadNumber
                                           (const byte_type*       beg,
                                            const byte_type* const end,
                                            T*               const pNumber,
                                            const wchar_t*   const tagSign)
{
 assert(beg<=end);

 CHECK_READ_PTR(beg,size_t(end-beg));

 assert(pNumber!=nullptr);
 assert(tagSign!=nullptr);

 //-----------------------------------------
 (*pNumber)=0;

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ReadNumber";

 //читаем длину блока
 if(size_t(end-beg)<isc_api::ibp_isc__info_tag__data_length__byte_count)
 {
  //ERROR - [BUG CHECK] некорректный формат элемента.

  IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
   (c_bugcheck_src,
    L"#001",
    tagSign);
 }//if

 size_t item_length=0;

 assert(isc_api::ibp_isc__info_tag__data_length__byte_count<=sizeof(item_length));

 _VERIFY(isc_base::isc_portable_format_to_integer::exec_r
             (isc_api::ibp_isc__info_tag__data_length__byte_count,
              beg,
              &item_length));

 beg+=isc_api::ibp_isc__info_tag__data_length__byte_count;

 assert(beg<=end);

 if(size_t(end-beg)<item_length)
 {
  //ERROR - [BUG CHECK] размер данных больше размера буфера под них.

  IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
   (c_bugcheck_src,
    L"#002",
    tagSign,
    item_length,
    size_t(end-beg));
 }//if

 isc_base::isc_portable_format_to_integer::exec
  (item_length,
   beg,
   pNumber,
   ibp_subsystem__remote_fb,
   tagSign); //throw

 beg+=item_length;

 return beg;
}//Helper__ReadNumber

//------------------------------------------------------------------------
const RemoteFB__API_HLP__XSQLDA_V01__Utilities::byte_type*
 RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ReadString
                                           (const byte_type*       beg,
                                            const byte_type* const end,
                                            size_t           const BufferLength,
                                            char*            const pBuffer,
                                            short*           const pActualLength,
                                            const wchar_t*   const tagSign)
{
 assert(beg<=end);

 CHECK_READ_PTR(beg,size_t(end-beg));

 assert(pBuffer!=nullptr);

 CHECK_WRITE_PTR(pBuffer,BufferLength);

 assert(pActualLength!=nullptr);

 assert(tagSign!=nullptr);

 assert(structure::can_numeric_cast(pActualLength,BufferLength));

 //-----------------------------------------
 (*pActualLength)=0;

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ReadString";

 //читаем длину блока
 if(size_t(end-beg)<isc_api::ibp_isc__info_tag__data_length__byte_count)
 {
  //ERROR - [BUG CHECK] некорректный формат элемента.

  IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
   (c_bugcheck_src,
    L"#001",
    tagSign);
 }//if

 size_t item_length=0;

 assert(isc_api::ibp_isc__info_tag__data_length__byte_count<=sizeof(item_length));

 _VERIFY(isc_base::isc_portable_format_to_integer::exec_r
             (isc_api::ibp_isc__info_tag__data_length__byte_count,
              beg,
              &item_length));

 beg+=isc_api::ibp_isc__info_tag__data_length__byte_count;

 assert(beg<=end);

 if(size_t(end-beg)<item_length)
 {
  //ERROR - [BUG CHECK] размер данных больше размера буфера под них.

  IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
   (c_bugcheck_src,
    L"#002",
    tagSign,
    item_length,
    size_t(end-beg));
 }//if

 if(BufferLength<item_length)
 {
  //ERROR - string value is too large

  IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
   (c_bugcheck_src,
    L"#003",
    tagSign,
    item_length,
    BufferLength);
 }//if

 //-----------------------------------------
 structure::static_numeric_cast(pActualLength,item_length);

 assert_s(sizeof(*pBuffer)==1);
 assert_s(sizeof(*beg)==1);

 memcpy(pBuffer,beg,item_length);

 std::fill(pBuffer+item_length,pBuffer+BufferLength,' ');

 //-----
 beg+=item_length;

 return beg;
}//Helper__ReadString

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
