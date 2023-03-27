////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_hlp__stmt__get_info_v01.cpp
//! \brief   Получение сведений о запросе.
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__stmt__get_info_v01.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include "source/db_obj/isc_base/helpers/xsqlda/set01/isc_api_hlp__xsqlda_set01__msg_utilities.h"
#include "source/db_obj/isc_base/helpers/xsqlda/set01/isc_api_hlp__xsqlda_set01__xvar_info_ids.h"
#include "source/db_obj/isc_base/isc_info_buffer_v1_utilities.h"
#include "source/db_obj/isc_base/isc_info_buffer_v1_builder.h"

#include "source/db_obj/db_operation_reg.h"

#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"

#include <structure/t_pointer_cast.h>

#include <type_traits>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__API_HLP__GetStatementInfo::tagTestQTagResult

struct RemoteFB__API_HLP__GetStatementInfo::tagTestQTagResult
{
 public:
  /// <summary>
  ///  The test result flag
  /// </summary>
  tagTestQTagResultFlag flag;

  /// <summary>
  ///  The number of bytes in query buffer for skiping
  /// </summary>
  size_t size;

 public:
  /// <summary>
  ///  Constructor
  /// </summary>
  tagTestQTagResult(tagTestQTagResultFlag const fl,
                    size_t                const sz)
   :flag(fl)
   ,size(sz)
  {
  }
};//class tagTestQTagResult

////////////////////////////////////////////////////////////////////////////////
//RemoteFB__API_HLP__GetStatementInfo::tagQItemPtrData

/// <summary>
///  The definition of item which value will be loaded from server.
/// </summary>
struct RemoteFB__API_HLP__GetStatementInfo::tagQItemPtrData
{
 public:
  //! The pointer on the item from original query.
  const unsigned char* pItem;

  //! The size of item. It may be more than one for select/bind items.
  size_t               ItemSize;

 public:
  tagQItemPtrData(const unsigned char* const _pItem,
                  size_t               const _ItemSize)
   :pItem(_pItem)
   ,ItemSize(_ItemSize)
  {
   assert(pItem!=nullptr);
  }
};//struct tagQItemPtrData

////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__API_HLP__GetStatementInfo::tagCopyQValueResult

struct RemoteFB__API_HLP__GetStatementInfo::tagCopyQValueResult
{
 public:
  bool                 data_is_truncated;
  const unsigned char* position;

 public:
  tagCopyQValueResult(bool                 const _data_is_truncated,
                      const unsigned char* const _position)
   :data_is_truncated(_data_is_truncated)
   ,position         (_position)
  {
  }
};//struct tagCopyQValueResult

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__GetStatementInfo

RemoteFB__API_HLP__GetStatementInfo::RemoteFB__API_HLP__GetStatementInfo()
{
}

//------------------------------------------------------------------------
RemoteFB__API_HLP__GetStatementInfo::~RemoteFB__API_HLP__GetStatementInfo()
{
}

//interface --------------------------------------------------------------
void RemoteFB__API_HLP__GetStatementInfo::exec
                                           (db_obj::t_db_operation_context& OpCtx,
                                            RemoteFB__ConnectorData*  const pData,
                                            stmt_handle_type*         const pStmtHandle,
                                            unsigned short            const Incornation,
                                            unsigned short            const cItems,
                                            const unsigned char*      const pItems,
                                            RemoteFB__InfoBuffer&           ResultBuffer)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pStmtHandle!=nullptr);

 CHECK_READ_TYPED_PTR(pItems,cItems);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__GetStatementInfo::exec";

 //-----------------------------------------
 ResultBuffer.alloc(0);

 //----------------------------------------- проверка дескриптора запроса
 if((*pStmtHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 if(!(*pStmtHandle)->m_ID.has_value() && !(*pStmtHandle)->m_ID.is_defer())
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#002");
 }//if

 pData->BugCheck__CheckStmt
  (*pStmtHandle,
   c_bugcheck_src,
   L"#003");

 if(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED))
 {
  IBP_ThrowSimpleError
   (DB_E_NOTPREPARED,
    ibp_subsystem__remote_fb,
    ibp_mce_cmd_not_prepared_0);
 }//if

 assert((*pStmtHandle)->m_ID.has_value());

 //-----------------------------------------
 bool allTagsAreKnown
  =true;

 bool hasAlreadyLoadedTags
  =false;

 bool itNeedsToLoadFromServer
  =false;

 structure::t_stl_vector<unsigned char,RemoteFB__MemoryAllocator>
  QItems;

 // It is the list of pointers on elements from Items
 structure::t_stl_vector<self_type::tagQItemPtrData,RemoteFB__MemoryAllocator>
  QItemPtrs;

 const auto*        pItem=pItems;
 const auto* const _eItem=pItems+cItems;

 for(;pItem!=_eItem;)
 {
  assert(pItem<_eItem);

  const auto test_r
   =self_type::helper__test_qtag
     (pStmtHandle,
      pItem,
      _eItem);

  if(test_r.flag==tagTestQTagResultFlag::already_loaded)
  {
   assert(test_r.size>0);
   assert(test_r.size<=size_t(_eItem-pItem));

   if(!hasAlreadyLoadedTags)
   {
    if(itNeedsToLoadFromServer)
     QItems.insert(QItems.end(),pItems,pItem);

    hasAlreadyLoadedTags=true;
   }//if

   pItem+=test_r.size;

   continue;
  }//if - already_loaded

  if(test_r.flag==tagTestQTagResultFlag::already_loaded_truncated)
  {
   assert(test_r.size>0);
   assert(test_r.size<=size_t(_eItem-pItem));

   if(!hasAlreadyLoadedTags)
   {
    if(itNeedsToLoadFromServer)
     QItems.insert(QItems.end(),pItems,pItem);

    hasAlreadyLoadedTags=true;
   }//if

   pItem+=test_r.size;

   break;
  }//if - already_loaded_truncated

  if(test_r.flag==tagTestQTagResultFlag::need_to_load)
  {
   assert(test_r.size>0);
   assert(test_r.size<=size_t(_eItem-pItem));

   itNeedsToLoadFromServer=true;

   QItemPtrs.emplace_back(pItem,test_r.size);

   if(hasAlreadyLoadedTags)
    QItems.insert(QItems.end(),pItem,pItem+test_r.size);

   pItem+=test_r.size;

   continue;
  }//if - need_to_load

  assert(test_r.flag==tagTestQTagResultFlag::unknown_tag);
  assert(test_r.size==0);

  allTagsAreKnown=false;

  break;
 }//for pItem

 assert(pItems<=pItem);
 assert(pItem<=_eItem);

 if(!allTagsAreKnown || !hasAlreadyLoadedTags)
 {
  return this->internal__exec__direct
          (OpCtx,
           pData,
           pStmtHandle,
           Incornation,
           cItems,
           pItems,
           ResultBuffer); //throw
 }//if

 assert_hint(allTagsAreKnown);
 assert_hint(hasAlreadyLoadedTags);

 if(!QItems.empty())
 {
  assert(itNeedsToLoadFromServer);

  // cItems is unsigned short
  assert_s(std::is_same<std::remove_const<decltype(cItems)>::type _LITER_COMMA_ unsigned short>::value);

  assert(QItems.size()<cItems);

  assert(structure::can_numeric_cast<unsigned short>(QItems.size()));

  this->internal__exec__direct
   (OpCtx,
    pData,
    pStmtHandle,
    Incornation,
    static_cast<unsigned short>(QItems.size()),
    QItems.data(),
    ResultBuffer); //throw
 }//if

 // It needs to append already loaded values in ResultBuffer

 self_type::helper__rebuild_ResultBuffer
  (pStmtHandle,
   size_t(pItem-pItems),
   pItems,
   QItemPtrs.size(),
   QItemPtrs.data(),
   /*in out*/ResultBuffer);

#ifndef NDEBUG
 if(pItem!=_eItem)
 {
  assert(pItem<_eItem);

  //
  // We have processed not all the pItems.
  //
  // It means that last element in ResultBuffer is truncated.
  //

  assert(!ResultBuffer.empty());

  assert(ResultBuffer.back()==isc_api::ibp_isc_info_truncated);
 }//if pItem!=_eItem
#endif
}//exec

//helper methods ---------------------------------------------------------
RemoteFB__API_HLP__GetStatementInfo::tagTestQTagResult
 RemoteFB__API_HLP__GetStatementInfo::helper__test_qtag
               (stmt_handle_type*    const pStmtHandle,
                const unsigned char*       pItem,
                const unsigned char* const eItem)
{
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert(pItem!=eItem);

 //--------------------------------------------------------
 if((*pItem)==isc_api::ibp_isc_info_sql_stmt_type)
 {
  // this data must be already loaded during a prepare stage
  assert(!(*pStmtHandle)->m_StmtTypeID.null());

  return tagTestQTagResult(tagTestQTagResultFlag::already_loaded,1);
 }//if

 //--------------------------------------------------------
 if((*pItem)==isc_api::ibp_isc_info_sql_batch_fetch)
 {
  // this data must be already loaded during a prepare stage
  assert(!(*pStmtHandle)->m_BatchFetch.null());

  return tagTestQTagResult(tagTestQTagResultFlag::already_loaded,1);
 }//if

 //--------------------------------------------------------
 if((*pItem)==isc_api::ibp_isc_info_sql_select)
 {
  return helper__test_qtag__select(pStmtHandle,pItem,eItem);
 }//if

 //--------------------------------------------------------
 if((*pItem)==isc_api::ibp_isc_info_sql_bind)
 {
  return helper__test_qtag__bind(pStmtHandle,pItem,eItem);
 }//if

 //--------------------------------------------------------
 if((*pItem)==isc_api::ibp_isc_info_sql_records)
 {
  return tagTestQTagResult(tagTestQTagResultFlag::need_to_load,1);
 }//if

 //--------------------------------------------------------
 return tagTestQTagResult(tagTestQTagResultFlag::unknown_tag,0);
}//helper__test_qtag

//------------------------------------------------------------------------
RemoteFB__API_HLP__GetStatementInfo::tagTestQTagResult
 RemoteFB__API_HLP__GetStatementInfo::helper__test_qtag__select
               (stmt_handle_type*    const pStmtHandle,
                const unsigned char* const pItem,
                const unsigned char* const eItem)
{
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert(pItem!=eItem);

 assert((*pItem)==isc_api::ibp_isc_info_sql_select);

 const auto test_qvars_r
  =helper__test_qvars
    (pItem+1,
     eItem);

 if(!test_qvars_r.first)
  return tagTestQTagResult(tagTestQTagResultFlag::unknown_tag,0);

 const size_t sz=size_t(test_qvars_r.second-pItem);

 assert(sz>=3); //select, describe_vars, describe_end

 if(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__CACHE_COLS_INFO))
  return tagTestQTagResult(tagTestQTagResultFlag::need_to_load,sz);

 assert(!(*pStmtHandle)->m_ColumnsData.empty());

 if((*pStmtHandle)->m_ColumnsData.back()==isc_api::ibp_isc_info_truncated)
  return tagTestQTagResult(tagTestQTagResultFlag::already_loaded_truncated,sz);

 assert((*pStmtHandle)->m_ColumnsData.back()==isc_api::ibp_isc_info_end);

 return tagTestQTagResult(tagTestQTagResultFlag::already_loaded,sz);
}//helper__test_qtag__select

//------------------------------------------------------------------------
RemoteFB__API_HLP__GetStatementInfo::tagTestQTagResult
 RemoteFB__API_HLP__GetStatementInfo::helper__test_qtag__bind
               (stmt_handle_type*    const pStmtHandle,
                const unsigned char* const pItem,
                const unsigned char* const eItem)
{
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert(pItem!=eItem);

 assert((*pItem)==isc_api::ibp_isc_info_sql_bind);

 const auto test_qvars_r
  =helper__test_qvars
    (pItem+1,
     eItem);

 if(!test_qvars_r.first)
  return tagTestQTagResult(tagTestQTagResultFlag::unknown_tag,0);

 const size_t sz=size_t(test_qvars_r.second-pItem);

 assert(sz>=3); //bind, describe_vars, describe_end

 if(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__CACHE_PARAMS_INFO))
  return tagTestQTagResult(tagTestQTagResultFlag::need_to_load,sz);

 assert(!(*pStmtHandle)->m_ParametersData.empty());

 if((*pStmtHandle)->m_ParametersData.back()==isc_api::ibp_isc_info_truncated)
  return tagTestQTagResult(tagTestQTagResultFlag::already_loaded_truncated,sz);

 assert((*pStmtHandle)->m_ParametersData.back()==isc_api::ibp_isc_info_end);

 return tagTestQTagResult(tagTestQTagResultFlag::already_loaded,sz);
}//helper__test_qtag__bind

//------------------------------------------------------------------------
const unsigned char RemoteFB__API_HLP__GetStatementInfo::sm_expected_qvars[]=
{
 IBP_ISC_API_HLP__XSQLDA_SET01__XVAR_INFO_IDS__C11
};//sm_expected_qvars

//------------------------------------------------------------------------
std::pair<bool,const unsigned char*>
 RemoteFB__API_HLP__GetStatementInfo::helper__test_qvars
               (const unsigned char*       pItem,
                const unsigned char* const eItem)
{
 assert(pItem<=eItem);

 const auto r
  =structure::test_prefix
    (pItem,
     eItem,
     sm_expected_qvars,
     _LCPI_END_(sm_expected_qvars));

 if(r!=_LCPI_END_(sm_expected_qvars))
  return std::make_pair(false,pItem);

 return std::make_pair(true,pItem+_LCPI_DIM_(sm_expected_qvars));
}//helper__test_qvars

//------------------------------------------------------------------------
void RemoteFB__API_HLP__GetStatementInfo::helper__rebuild_ResultBuffer
                             (stmt_handle_type*      const pStmtHandle,
                              size_t                 const cItems,
                              const unsigned char*   const pItems,
                              size_t                 const cQItemPtrs,
                              const tagQItemPtrData* const pQItemPtrs,
                              RemoteFB__InfoBuffer&        ResultBuffer)
{
 assert(pStmtHandle!=nullptr);

 CHECK_READ_TYPED_PTR(pItems,cItems);
 CHECK_READ_TYPED_PTR(pQItemPtrs,cQItemPtrs);

 assert(cQItemPtrs<=cItems);

 //---------------------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__GetStatementInfo::helper__rebuild_ResultBuffer";

 isc_base::t_isc_info_buffer_v1_builder resultBuilder;

 const auto*       pItem=pItems;
 const auto* const eItem=pItems+cItems;

 const auto*       pQItemPtr=pQItemPtrs;
 const auto* const eQItemPtr=pQItemPtrs+cQItemPtrs;

 const auto*       pRBuf=ResultBuffer.buffer();
 const auto* const eRBuf=ResultBuffer.buffer_end();

 for(;;)
 {
  assert(pRBuf<=eRBuf);
  assert(pItem<=eItem);
  assert(pQItemPtr<=eQItemPtr);

  if(pItem==eItem)
  {
   //we had to process all the queried (loaded) tags
   assert(pQItemPtr==eQItemPtr);

   resultBuilder.append__END();
   break;
  }//if

  assert(pItem!=eItem);

  if(pQItemPtr!=eQItemPtr)
  {
   assert((*pQItemPtr).pItem!=nullptr);
   assert((*pQItemPtr).ItemSize>0);
   
   if((*pQItemPtr).pItem==pItem)
   {
    //data was loaded from server

    assert((*pQItemPtr).ItemSize<=size_t(eItem-pItem));

    const auto copy_r
     =self_type::helper__copy_qvalue
       (*pItem,
        pRBuf,
        eRBuf,
        resultBuilder);

    if(copy_r.data_is_truncated)
    {
     //loaded data is truncated

     resultBuilder.append__TRUNCATED();
     break;
    }//if

    assert(!copy_r.data_is_truncated);

    assert(pRBuf<copy_r.position); // we had to change position in ResultBuf
    assert(copy_r.position<=eRBuf);

    pRBuf=copy_r.position;

    pItem+=(*pQItemPtr).ItemSize;

    ++pQItemPtr;

    continue;
   }//if (*pQItemPtr).pItem==pItem
  }//if pQItem_Ptr!=eQItem_Ptr

  //------------------------------------------------------- gets from cache
  if((*pItem)==isc_api::ibp_isc_info_sql_stmt_type)
  {
   assert(!(*pStmtHandle)->m_StmtTypeID.null());

   resultBuilder.append__Int
    (isc_api::ibp_isc_info_sql_stmt_type,
     (*pStmtHandle)->m_StmtTypeID.value());

   ++pItem;

   continue;
  }//case ibp_isc_info_sql_stmt_type

  //-----------------------------------------------------------------
  if((*pItem)==isc_api::ibp_isc_info_sql_batch_fetch)
  {
   assert(!(*pStmtHandle)->m_BatchFetch.null());

   resultBuilder.append__Int
    (isc_api::ibp_isc_info_sql_batch_fetch,
     (*pStmtHandle)->m_BatchFetch.value()?1L:0L);

   ++pItem;

   continue;
  }//case ibp_isc_info_sql_batch_fetch

  //-----------------------------------------------------------------
  if((*pItem)==isc_api::ibp_isc_info_sql_select)
  {
   assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__CACHE_COLS_INFO));

   assert(!(*pStmtHandle)->m_ColumnsData.empty());

   resultBuilder.buffer().push_back(isc_api::ibp_isc_info_sql_select);

   resultBuilder.buffer().write((*pStmtHandle)->m_ColumnsData.data(),(*pStmtHandle)->m_ColumnsData.size()-1);

   const auto lastSrcElement
    =(*pStmtHandle)->m_ColumnsData.back();

   if(lastSrcElement==isc_api::ibp_isc_info_end)
   {
    //OK!

    ++pItem; //skip ibp_isc_info_sql_select

    assert(_LCPI_DIM_(sm_expected_qvars)<=size_t(eItem-pItem));

    pItem+=_LCPI_DIM_(sm_expected_qvars);

    continue;
   }//if

   if(lastSrcElement==isc_api::ibp_isc_info_truncated)
   {
    resultBuilder.append__TRUNCATED();
    break;
   }//if

   IBP_ThrowBugCheck_InfoBuf__UnknownTag
    (c_bugcheck_src,
     L"#001.SELECT",
     *pItem);
  }//case ibp_isc_info_sql_select

  //-----------------------------------------------------------------
  if((*pItem)==isc_api::ibp_isc_info_sql_bind)
  {
   assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__CACHE_PARAMS_INFO));

   assert(!(*pStmtHandle)->m_ParametersData.empty());

   resultBuilder.buffer().push_back(isc_api::ibp_isc_info_sql_bind);

   resultBuilder.buffer().write((*pStmtHandle)->m_ParametersData.data(),(*pStmtHandle)->m_ParametersData.size()-1);

   const auto lastSrcElement
    =(*pStmtHandle)->m_ParametersData.back();

   if(lastSrcElement==isc_api::ibp_isc_info_end)
   {
    //OK!

    ++pItem; //skip ibp_isc_info_sql_bind

    assert(_LCPI_DIM_(sm_expected_qvars)<=size_t(eItem-pItem));

    pItem+=_LCPI_DIM_(sm_expected_qvars);

    continue;
   }//if

   if(lastSrcElement==isc_api::ibp_isc_info_truncated)
   {
    resultBuilder.append__TRUNCATED();
    break;
   }//if

   IBP_ThrowBugCheck_InfoBuf__UnknownTag
    (c_bugcheck_src,
     L"#002.BIND",
     *pItem);
  }//case ibp_isc_info_sql_bind

  //-----------------------------------------------------------------
  IBP_ThrowBugCheck_InfoBuf__UnknownTag
   (c_bugcheck_src,
    L"#003",
    *pItem);

  assert(false);
 }//for[ever]

 //-------------------------------------------------------- copy to target
 ResultBuffer.alloc(resultBuilder.buffer().size());

 DEBUG_CODE(auto const copy_r=)
  structure::copy
   (resultBuilder.buffer().cbegin(),
    resultBuilder.buffer().cend(),
    ResultBuffer.buffer(),
    ResultBuffer.buffer_end());

 assert(copy_r.first==resultBuilder.buffer().cend());
 assert(copy_r.second==ResultBuffer.buffer_end());
}//helper__rebuild_ResultBuffer

//------------------------------------------------------------------------
RemoteFB__API_HLP__GetStatementInfo::tagCopyQValueResult
 RemoteFB__API_HLP__GetStatementInfo::helper__copy_qvalue
  (unsigned char                     const itemTag,
   const unsigned char*              const pRBuf,
   const unsigned char*              const eRBuf,
   isc_base::t_isc_info_buffer_v1_builder& resultBuilder)
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__GetStatementInfo::helper__copy_qvalue";

 if(pRBuf==eRBuf)
 {
  IBP_ErrorUtils::Throw__BugCheck
   (c_bugcheck_src,
    L"#001",
    L"the unexpected end of buffer. Expected data for tag [%1]",
    int(itemTag));
 }//if

 assert(pRBuf!=eRBuf);

 if((*pRBuf)==isc_api::ibp_isc_info_end)
 {
  IBP_ErrorUtils::Throw__BugCheck
   (c_bugcheck_src,
    L"#002",
    L"the unexpected end of loaded data. Expected data for tag [%1]",
    int(itemTag));
 }//if

 if((*pRBuf)==isc_api::ibp_isc_info_truncated)
  return tagCopyQValueResult(true,pRBuf);

 if((*pRBuf)!=itemTag)
 {
  IBP_ErrorUtils::Throw__BugCheck
   (c_bugcheck_src,
    L"#003",
    L"the unexpected tag [%1]. Expected tag [%1]",
    int(*pRBuf),
    int(itemTag));
 }//if

 switch(itemTag)
 {
  case isc_api::ibp_isc_info_sql_select:
  case isc_api::ibp_isc_info_sql_bind:
  {
   const auto r
    =isc_base::helpers::ISC_API_HLP__XSQLDA_SET01__MsgUtilities::Skip_XSQLVARS_Info
      (pRBuf+1,
       eRBuf);

   assert(r.position >  pRBuf);
   assert(r.position <= eRBuf);

   resultBuilder.buffer().write
    (pRBuf,
     size_t(r.position-pRBuf));

   return tagCopyQValueResult(r.data_is_truncated,r.position);
  }//case select, bind

  case isc_api::ibp_isc_info_sql_records:
  {
   const auto r
    =isc_base::isc_info_buffer_v1_utilities::skip_element_data
      (pRBuf+1,
       eRBuf,
       /*tagID*/*pRBuf);

   assert(r >  pRBuf);
   assert(r <= eRBuf);

   resultBuilder.buffer().write
    (pRBuf,
     size_t(r-pRBuf));

   return tagCopyQValueResult(/*data_is_truncated*/false,r);
  }//case

  default:
  {
   IBP_ThrowBugCheck_InfoBuf__UnknownTag
    (c_bugcheck_src,
     L"#004",
     *pRBuf);
  }//default
 }//switch itemTag
}//helper__copy_qvalue

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
