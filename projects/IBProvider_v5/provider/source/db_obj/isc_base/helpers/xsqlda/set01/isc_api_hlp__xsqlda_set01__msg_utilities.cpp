////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_api_hlp__xsqlda_set01__msg_utilities.cpp
//! \brief   M-утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    07.02.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/helpers/xsqlda/set01/isc_api_hlp__xsqlda_set01__msg_utilities.h"
#include "source/db_obj/isc_base/isc_info_buffer_v1_utilities.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace isc_base{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class ISC_API_HLP__XSQLDA_SET01__MsgUtilities

ISC_API_HLP__XSQLDA_SET01__MsgUtilities::tag_skip_result
 ISC_API_HLP__XSQLDA_SET01__MsgUtilities::Skip_XSQLVARS_Info
                                           (const byte_type* const beg,
                                            const byte_type* const end)
{
 assert(beg<=end);

 CHECK_READ_TYPED_PTR(beg,(end-beg));

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"ISC_API_HLP__XSQLDA_SET01__MsgUtilities::Skip_XSQLVARS_Info";

 //-----------------------------------------
 const byte_type* pos=beg;

 if(pos==end)
 {
  IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd
   (c_bugcheck_src,
    L"#001");
 }//if

 if((*pos)==isc_api::ibp_isc_info_truncated)
  return tag_skip_result(pos,beg,beg,/*is_truncated*/true); //no data [truncation].

 if((*pos)!=isc_api::ibp_isc_info_sql_describe_vars)
 {
  IBP_ThrowBugCheck_InfoBuf__UnknownTag
   (c_bugcheck_src,
    L"#002",
    *pos);
 }//if

 ++pos;

 //Skip count of column/parameters
 pos=isc_info_buffer_v1_utilities::skip_element_data
      (pos,
       end,
       isc_api::ibp_isc_info_sql_describe_vars); //throw

 for(const byte_type* data_end=pos;;)
 {
  assert(pos<=end);

  if(pos==end)
  {
   //мы должны находиться в конце данных VAR-блока
   assert(data_end==pos);

   return tag_skip_result(pos,beg,data_end,/*is_truncated*/false);
  }//if

  assert(pos<end);

  if((*pos)==isc_api::ibp_isc_info_truncated)
  {
   assert(beg<data_end); //the buffer has data

   return tag_skip_result(pos,beg,data_end,/*is_truncated*/true);
  }//if

  if((*pos)==isc_api::ibp_isc_info_sql_sqlda_seq)
  {
   ++pos;

   //
   // Data contains the ordinal number of element: 1, 2, 3 ...
   //
   pos=isc_info_buffer_v1_utilities::skip_element_data
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

    if((*pos)==isc_api::ibp_isc_info_truncated)
    {
     assert(beg<data_end);

     return tag_skip_result(pos,beg,data_end,/*is_truncated*/true);
    }//if

    const byte_type item_id=*pos;

    ++pos;

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
      pos=isc_info_buffer_v1_utilities::skip_element_data
           (pos,
            end,
            item_id); //throw

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

    //Space must be available
    assert(!processedIDs.full());

    processedIDs.push_back(item_id);
   }//for[ever]

   //We have finished processing the XSQLVAR data

   //Trying to process the next block
   continue;
  }//if ibp_isc_info_sql_sqlda_seq

  assert((*pos)!=isc_api::ibp_isc_info_sql_sqlda_seq);

  //Processing of blocks has been completed
  return tag_skip_result(pos,beg,data_end,false);
 }//for[ever]
}//Skip_XSQLVARS_Info

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
