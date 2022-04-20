////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__p12__xsqlda_utilities.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/set01/remote_fb__api_hlp__xsqlda_set01__utilities.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_SET01__Utilities

const RemoteFB__API_HLP__XSQLDA_SET01__Utilities::byte_type
 RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__prepare[26]=
{
 isc_api::ibp_isc_info_sql_stmt_type,       //0
 isc_api::ibp_isc_info_sql_batch_fetch,     //1

 // describe_select_info
 isc_api::ibp_isc_info_sql_select,          //2
 isc_api::ibp_isc_info_sql_describe_vars,   //3
 isc_api::ibp_isc_info_sql_sqlda_seq,       //4
 isc_api::ibp_isc_info_sql_type,            //5
 isc_api::ibp_isc_info_sql_sub_type,        //6
 isc_api::ibp_isc_info_sql_scale,           //7
 isc_api::ibp_isc_info_sql_length,          //8
 isc_api::ibp_isc_info_sql_field,           //9
 isc_api::ibp_isc_info_sql_relation,        //10
 isc_api::ibp_isc_info_sql_owner,           //11
 isc_api::ibp_isc_info_sql_alias,           //12
 isc_api::ibp_isc_info_sql_describe_end,    //13

 // describe_bind_info
 isc_api::ibp_isc_info_sql_bind,            //14
 isc_api::ibp_isc_info_sql_describe_vars,   //15
 isc_api::ibp_isc_info_sql_sqlda_seq,       //16
 isc_api::ibp_isc_info_sql_type,            //17
 isc_api::ibp_isc_info_sql_sub_type,        //18
 isc_api::ibp_isc_info_sql_scale,           //19
 isc_api::ibp_isc_info_sql_length,          //20
 isc_api::ibp_isc_info_sql_field,           //21
 isc_api::ibp_isc_info_sql_relation,        //22
 isc_api::ibp_isc_info_sql_owner,           //23
 isc_api::ibp_isc_info_sql_alias,           //24
 isc_api::ibp_isc_info_sql_describe_end     //25
};//sm_sql_info__prepare

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Process_PrepareInfoBuf
                                            (stmt_data_type*  const pStmt,
                                             size_t           const szBuf,
                                             const byte_type* const pBuf)
{
 assert(pStmt!=nullptr);

 CHECK_READ_TYPED_PTR(pBuf,szBuf);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Process_PrepareInfoBuf";

 //-----------------------------------------
 //У нас четыре первичных элемента:
 // - ibp_isc_info_sql_stmt_type
 // - ibp_isc_info_sql_batch_fetch
 // - ibp_isc_info_sql_select
 // - ibp_isc_info_sql_bind

 const size_t c_primary_ids=4;

 typedef structure::t_fix_vector<c_primary_ids,unsigned char>  primary_ids_type;

 primary_ids_type processed_ids;

 //-----------------------------------------
 const byte_type* const _e_buffer=pBuf+szBuf;

 for(const byte_type* p=pBuf;p!=_e_buffer;)
 {
  const byte_type cluster_id=(*p);

  ++p;

  assert(p<=_e_buffer);

  //----------------------------------------
  if(cluster_id==isc_api::ibp_isc_info_end)
  {
   break;
  }//if

  //----------------------------------------
  if(cluster_id==isc_api::ibp_isc_info_truncated)
  {
   //ну, обрезаны, значит обрезаны. ничего страшного.
   break;
  }//if

  //----------------------------------------
  if(std::find(processed_ids.cbegin(),processed_ids.cend(),cluster_id)!=processed_ids.cend())
  {
   //ERROR - повторное указание cluster_id в полученном буфере

   IBP_ThrowBugCheck_InfoBuf__MultDefOfElement
    (c_bugcheck_src,
     L"#001",
     cluster_id);
  }//if

  //cluster_id будет зарегистрирован в processed_ids после обработки
  // - возможно нам подсунули что-то неизвестное.

  //----------------------------------------
  if(cluster_id==isc_api::ibp_isc_info_sql_select)
  {
   assert(!pStmt->m_PFlags.test(stmt_data_type::PFLAG__CACHE_COLS_INFO));

   const tag_skip_result
    skip_result=self_type::Helper__Skip_XSQLVARS_Info(p,_e_buffer);

   assert(p==skip_result.data_beg);
   assert(skip_result.data_beg<=skip_result.data_end);
   assert(skip_result.data_end<=skip_result.position);

   if(skip_result.data_beg!=skip_result.data_end)
   {
    //сохраняем полученные данные в дескрипторе запросе
    Helper__SaveElementData(skip_result.data_beg,
                            skip_result.data_end,
                            skip_result.data_is_truncated,
                            pStmt->m_ColumnsData);

    pStmt->m_PFlags.set(stmt_data_type::PFLAG__CACHE_COLS_INFO);
   }//else

   p=skip_result.position;
  }//if
  else
  if(cluster_id==isc_api::ibp_isc_info_sql_bind)
  {
   assert(!pStmt->m_PFlags.test(stmt_data_type::PFLAG__CACHE_PARAMS_INFO));

   const tag_skip_result
    skip_result=self_type::Helper__Skip_XSQLVARS_Info(p,_e_buffer);

   assert(p==skip_result.data_beg);
   assert(skip_result.data_beg<=skip_result.data_end);
   assert(skip_result.data_end<=skip_result.position);

   if(skip_result.data_beg!=skip_result.data_end)
   {
    //сохраняем полученные данные в дескрипторе запросе
    Helper__SaveElementData(skip_result.data_beg,
                            skip_result.data_end,
                            skip_result.data_is_truncated,
                            pStmt->m_ParametersData);

    pStmt->m_PFlags.set(stmt_data_type::PFLAG__CACHE_PARAMS_INFO);
   }//else

   p=skip_result.position;
  }//if
  else
  {
   //определяем длину данных кластера
   if(size_t(_e_buffer-p)<isc_api::ibp_isc__info_tag__data_length__byte_count)
   {
    //ERROR - [BUG CHECK] некорректный формат элемента.

    IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
     (c_bugcheck_src,
      L"#002",
      cluster_id);
   }//if

   size_t cluster_length=0;

   assert(isc_api::ibp_isc__info_tag__data_length__byte_count<=sizeof(cluster_length));

   _VERIFY(isc_base::isc_portable_format_to_integer::exec_r
               (isc_api::ibp_isc__info_tag__data_length__byte_count,
                p,
                &cluster_length));

   p+=isc_api::ibp_isc__info_tag__data_length__byte_count;

   assert(p<=_e_buffer);

   if(size_t(_e_buffer-p)<cluster_length)
   {
    //ERROR - [BUG CHECK] размер данных больше размера буфера под них.

    IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
     (c_bugcheck_src,
      L"#003",
      cluster_id,
      cluster_length,
      size_t(_e_buffer-p));
   }//if

   //----------------------------------------
   const unsigned char* const cluster_data=p;

   p+=cluster_length;

   bool known_clusterID=true;

   try
   {
    switch(cluster_id)
    {
     case isc_api::ibp_isc_info_sql_stmt_type:
     {
      assert(pStmt->m_StmtTypeID.null());

      isc_base::isc_portable_format_to_integer::exec
        (cluster_length,
         cluster_data,
         &pStmt->m_StmtTypeID,
         ibp_subsystem__remote_fb,
         L"isc_info_sql_stmt_type");

      break;
     }//case ibp_isc_info_sql_stmt_type

     case isc_api::ibp_isc_info_sql_batch_fetch:
     {
      assert(pStmt->m_BatchFetch.null());

      long v=0;

      isc_base::isc_portable_format_to_integer::exec
       (cluster_length,
        cluster_data,
        &v,
        ibp_subsystem__remote_fb,
        L"isc_info_sql_batch_fetch");

       pStmt->m_BatchFetch=(v!=0);
       break;
     }//case ibp_isc_info_sql_batch_fetch

     default:
      {
       //ERROR - unexpected data in result buffer

       known_clusterID=false;

       break;
      }//default
    }//switch
   }
   catch(const std::exception& e)
   {
    t_ibp_error exc(e);

    exc.add_error
     (E_FAIL,
      ibp_subsystem__remote_fb,
      ibp_mce_cmd__in_stmt_info_processing_error_occurred_1);

    exc<<cluster_id;

    exc.raise_me();
   }//catch

   if(!known_clusterID)
   {
    IBP_ThrowBugCheck_InfoBuf__UnknownTag
     (c_bugcheck_src,
      L"#004",
      cluster_id);
   }//if
  }//else

  //----------------------------------------
  assert(processed_ids.size()<processed_ids.capacity());

  processed_ids.push_back(cluster_id);
 }//for p

 //проверка загрузки обязательных сведений о запросе ---------------------
 if(pStmt->m_StmtTypeID.null())
 {
  Helper__ThrowError__GetStmtInfo__NoData(L"isc_info_sql_stmt_type");
 }//if

 if(pStmt->m_BatchFetch.null())
 {
  Helper__ThrowError__GetStmtInfo__NoData(L"isc_info_sql_batch_fetch");
 }//if
}//Process_PrepareInfoBuf

//------------------------------------------------------------------------
RemoteFB__API_HLP__XSQLDA_SET01__Utilities::tag_skip_result
 RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Helper__Skip_XSQLVARS_Info
                                           (const byte_type* const beg,
                                            const byte_type* const end)
{
 assert(beg<=end);

 CHECK_READ_TYPED_PTR(beg,(end-beg));

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Helper__Skip_XSQLVARS_Info";

 //-----------------------------------------
 const byte_type* pos=beg;

 if(pos==end)
 {
  IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd
   (c_bugcheck_src,
    L"#001");
 }//if

 if((*pos)==isc_api::ibp_isc_info_truncated)
  return tag_skip_result(pos,beg,beg,false); //нет данных.

 if((*pos)!=isc_api::ibp_isc_info_sql_describe_vars)
 {
  IBP_ThrowBugCheck_InfoBuf__UnknownTag
   (c_bugcheck_src,
    L"#002",
    *pos);
 }//if

 ++pos;

 //Skip message->msg_index
 pos=Helper__SkipElementData
      (pos,
       end,
       isc_api::ibp_isc_info_sql_describe_vars); //throw

 for(const byte_type* data_end=pos;;)
 {
  if(pos==end)
  {
   //мы должны находиться в конце данных VAR-блока
   assert(data_end==pos);

   return tag_skip_result(pos,beg,data_end,/*is_truncated*/false);
  }//if

  if((*pos)==isc_api::ibp_isc_info_truncated)
  {
   assert(beg<data_end); //есть данные

   return tag_skip_result(end,beg,data_end,/*is_truncated*/true);
  }//if

  if((*pos)==isc_api::ibp_isc_info_sql_sqlda_seq)
  {
   ++pos;

   pos=Helper__SkipElementData
        (pos,
         end,
         isc_api::ibp_isc_info_sql_sqlda_seq); //throw

   structure::t_fix_vector<8,byte_type> processedIDs;

   for(bool stop=false;;)
   {
    if(pos==end)
    {
     IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd
      (c_bugcheck_src,
       L"#003");
    }//if

    const byte_type item_id=*pos;

    ++pos;

    if(item_id==isc_api::ibp_isc_info_truncated)
    {
     assert(beg<data_end);

     return tag_skip_result(end,beg,data_end,/*is_truncated*/true);
    }//if

    if(std::find(processedIDs.cbegin(),processedIDs.cend(),item_id)!=processedIDs.cend())
    {
     //ERROR - повторное определение элемента

     IBP_ThrowBugCheck_InfoBuf__MultDefOfElement
      (c_bugcheck_src,
       L"#004",
       item_id);
    }//if

    //элемент будет зарегистрирован в processedIDs после обработки

    switch(item_id)
    {
     case isc_api::ibp_isc_info_sql_describe_end:
     {
      data_end=pos;

      stop=true;
      break;
     }//case - end

     case isc_api::ibp_isc_info_sql_type:          // 1
     case isc_api::ibp_isc_info_sql_sub_type:      // 2
     case isc_api::ibp_isc_info_sql_scale:         // 3
     case isc_api::ibp_isc_info_sql_length:        // 4
     case isc_api::ibp_isc_info_sql_field:         // 5
     case isc_api::ibp_isc_info_sql_relation:      // 6
     case isc_api::ibp_isc_info_sql_owner:         // 7
     case isc_api::ibp_isc_info_sql_alias:         // 8
     {
      pos=Helper__SkipElementData(pos,end,item_id); //throw

      break;
     }//case - value

     default:
     {
      IBP_ThrowBugCheck_InfoBuf__UnknownTag
       (c_bugcheck_src,
        L"#005",
        item_id);
     }//default
    }//switch - item_id

    if(stop)
     break;

    //у нас должно оставаться место
    assert(!processedIDs.full());

    processedIDs.push_back(item_id);
   }//for[ever]

   //закончили обработку данных XSQLVAR

   //пытаемся обработать следующий блок
   continue;
  }//if ibp_isc_info_sql_sqlda_seq

  //закончена обработка блоков
  return tag_skip_result(pos,beg,data_end,false);
 }//for[ever]
}//Helper__Skip_XSQLVARS_Info

//------------------------------------------------------------------------
const RemoteFB__API_HLP__XSQLDA_SET01__Utilities::byte_type*
 RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Helper__SkipElementData
                                           (const byte_type*       beg,
                                            const byte_type* const end,
                                            long             const tagID)
{
 assert(beg<=end);

 CHECK_READ_TYPED_PTR(beg,end-beg);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Helper__SkipElementData";

 //читаем длину блока
 if(size_t(end-beg)<isc_api::ibp_isc__info_tag__data_length__byte_count)
 {
  //ERROR - [BUG CHECK] некорректный формат элемента.

  IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
   (c_bugcheck_src,
    L"#001",
    tagID);
 }//if

 size_t item_length=0;

 assert(isc_api::ibp_isc__info_tag__data_length__byte_count<=sizeof(item_length));

 _VERIFY(isc_base::isc_portable_format_to_integer::exec_r
             (isc_api::ibp_isc__info_tag__data_length__byte_count,
              beg,
              &item_length));

 beg+=isc_api::ibp_isc__info_tag__data_length__byte_count;

 assert(beg<=end);

 //пропускаем данные блока
 if(size_t(end-beg)<item_length)
 {
  //ERROR - [BUG CHECK] размер данных больше размера буфера под них.

  IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
   (c_bugcheck_src,
    L"#002",
    tagID,
    item_length,
    size_t(end-beg));
 }//if

 beg+=item_length;

 return beg;
}//Helper__SkipElementData

//------------------------------------------------------------------------
template<class TBuffer>
void RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Helper__SaveElementData
                                           (const byte_type* const data_beg,
                                            const byte_type* const data_end,
                                            bool             const data_is_truncated,
                                            TBuffer&               buffer)
{
 assert(data_beg<data_end);

 const size_t n=size_t(data_end-data_beg);

 assert(n<structure::get_numeric_limits(n).max_value());

 buffer.alloc(n+1);

 assert(buffer.size()==(n+1));

 memcpy(buffer.buffer(),
        data_beg,
        n);

 if(data_is_truncated)
  buffer[n]=isc_api::ibp_isc_info_truncated;
 else
  buffer[n]=isc_api::ibp_isc_info_end;
}//Helper__SaveElementData

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Helper__ThrowError__GetStmtInfo__NoData
                                           (const wchar_t* const propSign)
{
 assert(propSign!=nullptr);

 IBP_ThrowCmdError__GetStmtInfo_NoData
  (ibp_subsystem__remote_fb,
   propSign);
}//Helper__ThrowError__GetStmtInfo__NoData

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
