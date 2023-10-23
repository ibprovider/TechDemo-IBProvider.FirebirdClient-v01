////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__stmt__get_info_v01.h
//! \brief   The base implementation for getting statement information (v01).
//! \author  Kovalenko Dmitry
//! \date    25.03.2023
#ifndef _remote_fb__api_hlp__stmt__get_info_v01_H_
#define _remote_fb__api_hlp__stmt__get_info_v01_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__get_info.h"
#include "source/db_obj/isc_base/isc_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__GetStatementInfo_v01

/// <summary>
///  The base implementation for getting statement information (v01).
/// </summary>
///  It provides a support for using an already loaded statement information.
class RemoteFB__API_HLP__GetStatementInfo_v01
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__GetStatementInfo)
{
 private:
  using self_type=RemoteFB__API_HLP__GetStatementInfo_v01;

  RemoteFB__API_HLP__GetStatementInfo_v01(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using stmt_data_type=stmt_handle_type::item_type;

 protected:
  RemoteFB__API_HLP__GetStatementInfo_v01();

  virtual ~RemoteFB__API_HLP__GetStatementInfo_v01();

 public:
  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Получение сведений о запросе.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in]  pData
  //!  Not null.
  //! \param[in]  pStmtHandle
  //!  Действительный дескриптор запроса. Not null.
  //! \param[in]  Incornation
  //! \param[in]  cItems
  //! \param[in]  pItems
  //! \param[out] ResultBuffer
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    stmt_handle_type*               pStmtHandle,
                    unsigned short                  Incornation,
                    unsigned short                  cItems,
                    const unsigned char*            pItems,
                    RemoteFB__InfoBuffer&           ResultBuffer)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  /// <summary>
  ///  Direct loading data from server
  /// </summary>
  virtual void internal__exec__direct
               (db_obj::t_db_operation_context& OpCtx,
                RemoteFB__ConnectorData*        pData,
                stmt_handle_type*               pStmtHandle,
                unsigned short                  Incornation,
                unsigned short                  cItems,
                const unsigned char*            pItems,
                RemoteFB__InfoBuffer&           ResultBuffer)=0;

 private:
  enum class tagTestQTagResultFlag
  {
   unknown_tag,
   already_loaded,
   already_loaded_truncated,
   need_to_load,
  };//enum class tagTestQTagResultFlag

  struct tagTestQTagResult;
  struct tagQItemPtrData;
  struct tagCopyQValueResult;

 private:
  static tagTestQTagResult
          helper__test_qtag
           (stmt_handle_type*    pStmtHandle,
            const unsigned char* pItem,
            const unsigned char* eItem);

  static tagTestQTagResult
           helper__test_qtag__select
            (stmt_handle_type*    pStmtHandle,
             const unsigned char* pItem,
             const unsigned char* eItem);

  static tagTestQTagResult
           helper__test_qtag__bind
            (stmt_handle_type*    pStmtHandle,
             const unsigned char* pItem,
             const unsigned char* eItem);

 private:
  static const unsigned char sm_expected_qvars[];

  static std::pair<bool,const unsigned char*>
           helper__test_qvars
            (const unsigned char* pItem,
             const unsigned char* eItem);

 private:
  static void helper__rebuild_ResultBuffer
            (stmt_handle_type*               pStmtHandle,
             size_t                          cItems,
             const unsigned char*            pItems,
             size_t                          cQItemPtrs,
             const tagQItemPtrData*          pQItemPtrs,
             RemoteFB__InfoBuffer&           ResultBuffer);

  static tagCopyQValueResult
           helper__copy_qvalue
            (unsigned char                           itemTag,
             const unsigned char*                    pRBuf,
             const unsigned char*                    eRBuf,
             isc_base::t_isc_info_buffer_v1_builder& resultBuilder);
};//class RemoteFB__API_HLP__GetStatementInfo_v01

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
