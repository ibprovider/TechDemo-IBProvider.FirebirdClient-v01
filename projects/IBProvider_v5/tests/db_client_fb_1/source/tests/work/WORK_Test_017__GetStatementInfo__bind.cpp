////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_017__GetStatementInfo__bind.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/db_obj/fb_base/fb_api.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////

#define _LOCAL_CHECK_VALUE(point,actual_v,expected_v)   \
  if((actual_v)!=(expected_v))                          \
  {                                                     \
   structure::str_formatter fmsg("point [%1]. Expected value: [%2]. Actual value: [%3]."); \
                                                        \
   fmsg<<(point)<<(expected_v)<<(actual_v);             \
                                                        \
   throw std::runtime_error(fmsg.str());                \
  }

//------------------------------------------------------------------------
#define _LOCAL_MAKE_WSTR(t) L##t

//------------------------------------------------------------------------
#define _LOCAL_CHECK_TAG(id,ptr,end)                    \
 {                                                      \
  self_type::helper__check_tag                          \
   ((tracer),                                           \
    _LOCAL_MAKE_WSTR(#id),                              \
    (id),                                               \
    (&ptr),                                             \
    (end));                                             \
 }

//------------------------------------------------------------------------
#define _LOCAL_CHECK_INT_TAG(id,value,ptr,end)          \
 {                                                      \
  self_type::helper__check_tag__Int                     \
   ((tracer),                                           \
    _LOCAL_MAKE_WSTR(#id),                              \
    (id),                                               \
    (value),                                            \
    (&ptr),                                             \
    (end));                                             \
 }

//------------------------------------------------------------------------
#define _LOCAL_CHECK_STR_TAG(id,value,ptr,end)          \
 {                                                      \
  self_type::helper__check_tag__Str                     \
   ((tracer),                                           \
    _LOCAL_MAKE_WSTR(#id),                              \
    (id),                                               \
    (value),                                            \
    (&ptr),                                             \
    (end));                                             \
 }

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_017__GetStatementInfo__bind::tag_impl

class WORK_Test_017__GetStatementInfo__bind::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_103__data__only_bind_tag
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_104__data__bind__describe_vars__describe_end
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_105__data__bindSTD___no_parameters
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_106__data__bindSTD___one_param
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_107__data__bindStdOneParam__records
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_108__data__bindStd2048
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_109__data__bindStd1000__selectStd1000
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_110__data__bindStd1000__selectStd2000
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_111__data__bindStd2000__selectStd2000
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static void helper__check_tag
                          (TTSO_Tracer&          tracer,
                           const wchar_t*        tagSign,
                           unsigned char         expected_tagID,
                           const unsigned char** pptr,
                           const unsigned char*  end);

  static void helper__check_tag__Int
                          (TTSO_Tracer&          tracer,
                           const wchar_t*        tagSign,
                           unsigned char         expected_tagID,
                           long                  expected_tagValue,
                           const unsigned char** pptr,
                           const unsigned char*  end);

  static void helper__check_tag__Str
                          (TTSO_Tracer&          tracer,
                           const wchar_t*        tagSign,
                           unsigned char         expected_tagID,
                           const char*           expected_tagValue,
                           const unsigned char** pptr,
                           const unsigned char*  end);

  static size_t helper__read_tag_length
                          (TTSO_Tracer&          tracer,
                           const wchar_t*        tagSign,
                           const unsigned char** pptr,
                           const unsigned char*  end);
};//class WORK_Test_017__GetStatementInfo__bind::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 103

void WORK_Test_017__GetStatementInfo__bind::tag_impl::test_103__data__only_bind_tag
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "set transaction");

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_bind,     // <----- IT IS AN INCOMPLETED QUERY!
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_bind
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_bind,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_end
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_end,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }

}//test_103__data__only_bind_tag

////////////////////////////////////////////////////////////////////////////////
//TEST 104

void WORK_Test_017__GetStatementInfo__bind::tag_impl::test_104__data__bind__describe_vars__describe_end
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "set transaction");

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_bind,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_describe_end,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_bind
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_bind,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_vars
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_describe_vars,
   0, // column count
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_end
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_end,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }
}//test_104__data__bind__describe_vars__describe_end

////////////////////////////////////////////////////////////////////////////////
//TEST 105

void WORK_Test_017__GetStatementInfo__bind::tag_impl::test_105__data__bindSTD___no_parameters
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "set transaction");

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_bind,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_sqlda_seq,
   isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_info_sql_sub_type,
   isc_api::ibp_isc_info_sql_scale,
   isc_api::ibp_isc_info_sql_length,
   isc_api::ibp_isc_info_sql_field,
   isc_api::ibp_isc_info_sql_relation,
   isc_api::ibp_isc_info_sql_owner,
   isc_api::ibp_isc_info_sql_alias,
   isc_api::ibp_isc_info_sql_describe_end,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_bind
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_bind,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_vars
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_describe_vars,
   0, // param count
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_end
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_end,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }
}//test_105__data__bindSTD___no_parameters

////////////////////////////////////////////////////////////////////////////////
//TEST 106

void WORK_Test_017__GetStatementInfo__bind::tag_impl::test_106__data__bindSTD___one_param
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "delete from DUAL where ID=?");

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_bind,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_sqlda_seq,
   isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_info_sql_sub_type,
   isc_api::ibp_isc_info_sql_scale,
   isc_api::ibp_isc_info_sql_length,
   isc_api::ibp_isc_info_sql_field,
   isc_api::ibp_isc_info_sql_relation,
   isc_api::ibp_isc_info_sql_owner,
   isc_api::ibp_isc_info_sql_alias,
   isc_api::ibp_isc_info_sql_describe_end,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_bind
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_bind,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_vars
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_describe_vars,
   1, // param count
   p,
   _e);

 //-----------------------------------------
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_sqlda_seq,
   1, // param ordinal
   p,
   _e);

 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_sql_long,
   p,
   _e);

 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_sub_type,
   0,
   p,
   _e);

 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_scale,
   0,
   p,
   _e);

 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_length,
   4,
   p,
   _e);

 _LOCAL_CHECK_STR_TAG
  (isc_api::ibp_isc_info_sql_field,
   "",
   p,
   _e);

 _LOCAL_CHECK_STR_TAG
  (isc_api::ibp_isc_info_sql_relation,
   "",
   p,
   _e);

 _LOCAL_CHECK_STR_TAG
  (isc_api::ibp_isc_info_sql_owner,
   "",
   p,
   _e);

 _LOCAL_CHECK_STR_TAG
  (isc_api::ibp_isc_info_sql_alias,
   "",
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_end
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_describe_end,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_end
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_end,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_106__data__bindSTD___one_param

////////////////////////////////////////////////////////////////////////////////
//TEST 107

void WORK_Test_017__GetStatementInfo__bind::tag_impl::test_107__data__bindStdOneParam__records
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "delete from DUAL where ID=?");

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_bind,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_sqlda_seq,
   isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_info_sql_sub_type,
   isc_api::ibp_isc_info_sql_scale,
   isc_api::ibp_isc_info_sql_length,
   isc_api::ibp_isc_info_sql_field,
   isc_api::ibp_isc_info_sql_relation,
   isc_api::ibp_isc_info_sql_owner,
   isc_api::ibp_isc_info_sql_alias,
   isc_api::ibp_isc_info_sql_describe_end,
   isc_api::ibp_isc_info_sql_records,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_bind
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_bind,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_vars
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_describe_vars,
   1, // param count
   p,
   _e);

 //-----------------------------------------
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_sqlda_seq,
   1, // param ordinal
   p,
   _e);

 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_sql_long,
   p,
   _e);

 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_sub_type,
   0,
   p,
   _e);

 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_scale,
   0,
   p,
   _e);

 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_length,
   4,
   p,
   _e);

 _LOCAL_CHECK_STR_TAG
  (isc_api::ibp_isc_info_sql_field,
   "",
   p,
   _e);

 _LOCAL_CHECK_STR_TAG
  (isc_api::ibp_isc_info_sql_relation,
   "",
   p,
   _e);

 _LOCAL_CHECK_STR_TAG
  (isc_api::ibp_isc_info_sql_owner,
   "",
   p,
   _e);

 _LOCAL_CHECK_STR_TAG
  (isc_api::ibp_isc_info_sql_alias,
   "",
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_end
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_describe_end,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_records
 {
  _LOCAL_CHECK_TAG
   (isc_api::ibp_isc_info_sql_records,
    p,
    _e);

  const size_t valueLength
   =helper__read_tag_length
    (tracer,
     L"isc_api::ibp_isc_info_sql_records",
     &p,
     _e);

  //----------- check sub items
  auto        p2=p;
  auto const _e2=p2+valueLength;

  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_req_update_count,
    0,
    p2,
    _e2);
 
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_req_delete_count,
    0,
    p2,
    _e2);
 
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_req_select_count,
    0,
    p2,
    _e2);
 
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_req_insert_count,
    0,
    p2,
    _e2);
 
  _LOCAL_CHECK_TAG
   (isc_api::ibp_isc_info_end,
    p2,
    _e2);

  _TSO_CHECK(p2==_e2);

  //-----------
  p+=valueLength;
 }//local

 //-------------------------------------------------------- ibp_isc_info_end
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_end,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_107__data__bindStdOneParam__records

////////////////////////////////////////////////////////////////////////////////
//TEST 108

void WORK_Test_017__GetStatementInfo__bind::tag_impl::test_108__data__bindStd2048
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 const size_t c_nParams  =2048;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 std::string sql("delete from DUAL where ID=?");

 for(size_t n=0;n!=c_nParams-1;++n)
  sql+=" AND ID=?";

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   sql.c_str());

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_bind,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_sqlda_seq,
   isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_info_sql_sub_type,
   isc_api::ibp_isc_info_sql_scale,
   isc_api::ibp_isc_info_sql_length,
   isc_api::ibp_isc_info_sql_field,
   isc_api::ibp_isc_info_sql_relation,
   isc_api::ibp_isc_info_sql_owner,
   isc_api::ibp_isc_info_sql_alias,
   isc_api::ibp_isc_info_sql_describe_end,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_bind
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_bind,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_vars
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_describe_vars,
   c_nParams, // column count
   p,
   _e);

 //-----------------------------------------
 //
 // FB4 returns only first 1364 columns
 //
 for(long n=0;n!=1364;)
 {
  ++n;

  tracer<<"--------------------- check column ["<<n<<"]"<<send;

  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_sqlda_seq,
    n, // column ordinal
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_type,
    isc_api::ibp_isc_sql_long,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_sub_type,
    0,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_scale,
    0,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_length,
    4,
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_field,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_relation,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_owner,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_alias,
    "",
    p,
    _e);

  _LOCAL_CHECK_TAG
   (isc_api::ibp_isc_info_sql_describe_end,
    p,
    _e);
 }//for n

 //-------------------------------------------------------- ibp_isc_info_truncated
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_truncated,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_108__data__bindStd2048

////////////////////////////////////////////////////////////////////////////////
//TEST 109

void WORK_Test_017__GetStatementInfo__bind::tag_impl::test_109__data__bindStd1000__selectStd1000
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 const size_t c_nColumns =1000;
 const size_t c_nParams  =1000;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 std::string sql("select ID");

 for(size_t n=0;n!=c_nColumns-1;++n)
  sql+=",ID";

 sql+=" from DUAL where ID=?";
 
 for(size_t n=0;n!=c_nParams-1;++n)
  sql+=" AND ID=?";

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   sql.c_str());

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_bind,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_sqlda_seq,
   isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_info_sql_sub_type,
   isc_api::ibp_isc_info_sql_scale,
   isc_api::ibp_isc_info_sql_length,
   isc_api::ibp_isc_info_sql_field,
   isc_api::ibp_isc_info_sql_relation,
   isc_api::ibp_isc_info_sql_owner,
   isc_api::ibp_isc_info_sql_alias,
   isc_api::ibp_isc_info_sql_describe_end,

   isc_api::ibp_isc_info_sql_select,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_sqlda_seq,
   isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_info_sql_sub_type,
   isc_api::ibp_isc_info_sql_scale,
   isc_api::ibp_isc_info_sql_length,
   isc_api::ibp_isc_info_sql_field,
   isc_api::ibp_isc_info_sql_relation,
   isc_api::ibp_isc_info_sql_owner,
   isc_api::ibp_isc_info_sql_alias,
   isc_api::ibp_isc_info_sql_describe_end,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_bind
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_bind,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_vars
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_describe_vars,
   c_nParams, // param count
   p,
   _e);

 //-----------------------------------------
 //
 // FB4 returns only first 93 parameters
 //
 for(long n=0;n!=93;)
 {
  ++n;

  tracer<<"--------------------- check parameter ["<<n<<"]"<<send;

  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_sqlda_seq,
    n, // param ordinal
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_type,
    isc_api::ibp_isc_sql_long,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_sub_type,
    0,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_scale,
    0,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_length,
    4,
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_field,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_relation,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_owner,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_alias,
    "",
    p,
    _e);

  _LOCAL_CHECK_TAG
   (isc_api::ibp_isc_info_sql_describe_end,
    p,
    _e);
 }//for n

 //-------------------------------------------------------- ibp_isc_info_truncated
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_truncated,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_109__data__bindStd1000__selectStd1000

////////////////////////////////////////////////////////////////////////////////
//TEST 110

void WORK_Test_017__GetStatementInfo__bind::tag_impl::test_110__data__bindStd1000__selectStd2000
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 const size_t c_nColumns =2000;
 const size_t c_nParams  =1000;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 std::string sql("select ID");

 for(size_t n=0;n!=c_nColumns-1;++n)
  sql+=",ID";

 sql+=" from DUAL where ID=?";
 
 for(size_t n=0;n!=c_nParams-1;++n)
  sql+=" AND ID=?";

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   sql.c_str());

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_bind,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_sqlda_seq,
   isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_info_sql_sub_type,
   isc_api::ibp_isc_info_sql_scale,
   isc_api::ibp_isc_info_sql_length,
   isc_api::ibp_isc_info_sql_field,
   isc_api::ibp_isc_info_sql_relation,
   isc_api::ibp_isc_info_sql_owner,
   isc_api::ibp_isc_info_sql_alias,
   isc_api::ibp_isc_info_sql_describe_end,

   isc_api::ibp_isc_info_sql_select,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_sqlda_seq,
   isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_info_sql_sub_type,
   isc_api::ibp_isc_info_sql_scale,
   isc_api::ibp_isc_info_sql_length,
   isc_api::ibp_isc_info_sql_field,
   isc_api::ibp_isc_info_sql_relation,
   isc_api::ibp_isc_info_sql_owner,
   isc_api::ibp_isc_info_sql_alias,
   isc_api::ibp_isc_info_sql_describe_end,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_bind
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_bind,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_vars
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_describe_vars,
   c_nParams, // column count
   p,
   _e);

 //-----------------------------------------
 for(long n=0;n!=c_nParams;)
 {
  ++n;

  tracer<<"--------------------- check parameter ["<<n<<"]"<<send;

  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_sqlda_seq,
    n, // column ordinal
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_type,
    isc_api::ibp_isc_sql_long,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_sub_type,
    0,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_scale,
    0,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_length,
    4,
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_field,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_relation,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_owner,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_alias,
    "",
    p,
    _e);

  _LOCAL_CHECK_TAG
   (isc_api::ibp_isc_info_sql_describe_end,
    p,
    _e);
 }//for n

 //-------------------------------------------------------- ibp_isc_info_sql_select
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_select,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_vars
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_describe_vars,
   c_nColumns, // column count
   p,
   _e);

 //-----------------------------------------
 //
 // FB4 returns only first 1073 columns
 //
 for(long n=0;n!=1073;)
 {
  ++n;

  tracer<<"--------------------- check column ["<<n<<"]"<<send;

  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_sqlda_seq,
    n, // column ordinal
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_type,
    isc_api::ibp_isc_sql_long,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_sub_type,
    0,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_scale,
    0,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_length,
    4,
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_field,
    "ID",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_relation,
    "DUAL",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_owner,
    "GAMER",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_alias,
    "ID",
    p,
    _e);

  _LOCAL_CHECK_TAG
   (isc_api::ibp_isc_info_sql_describe_end,
    p,
    _e);
 }//for n

 //-------------------------------------------------------- ibp_isc_info_truncated
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_truncated,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_110__data__bindStd1000__selectStd2000

////////////////////////////////////////////////////////////////////////////////
//TEST 111

void WORK_Test_017__GetStatementInfo__bind::tag_impl::test_111__data__bindStd2000__selectStd2000
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 const size_t c_nColumns =2000; // truncated
 const size_t c_nParams  =2000; // not loaded

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 std::string sql("select ID");

 for(size_t n=0;n!=c_nColumns-1;++n)
  sql+=",ID";

 sql+=" from DUAL where ID=?";
 
 for(size_t n=0;n!=c_nParams-1;++n)
  sql+=" AND ID=?";

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   sql.c_str());

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_bind,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_sqlda_seq,
   isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_info_sql_sub_type,
   isc_api::ibp_isc_info_sql_scale,
   isc_api::ibp_isc_info_sql_length,
   isc_api::ibp_isc_info_sql_field,
   isc_api::ibp_isc_info_sql_relation,
   isc_api::ibp_isc_info_sql_owner,
   isc_api::ibp_isc_info_sql_alias,
   isc_api::ibp_isc_info_sql_describe_end,

   isc_api::ibp_isc_info_sql_select,
   isc_api::ibp_isc_info_sql_describe_vars,
   isc_api::ibp_isc_info_sql_sqlda_seq,
   isc_api::ibp_isc_info_sql_type,
   isc_api::ibp_isc_info_sql_sub_type,
   isc_api::ibp_isc_info_sql_scale,
   isc_api::ibp_isc_info_sql_length,
   isc_api::ibp_isc_info_sql_field,
   isc_api::ibp_isc_info_sql_relation,
   isc_api::ibp_isc_info_sql_owner,
   isc_api::ibp_isc_info_sql_alias,
   isc_api::ibp_isc_info_sql_describe_end,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_bind
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_sql_bind,
   p,
   _e);

 //-------------------------------------------------------- ibp_isc_info_sql_describe_vars
 _LOCAL_CHECK_INT_TAG
  (isc_api::ibp_isc_info_sql_describe_vars,
   c_nParams, // column count
   p,
   _e);

 //-----------------------------------------
 for(long n=0;n!=1365;)
 {
  ++n;

  tracer<<"--------------------- check parameter ["<<n<<"]"<<send;

  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_sqlda_seq,
    n, // column ordinal
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_type,
    isc_api::ibp_isc_sql_long,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_sub_type,
    0,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_scale,
    0,
    p,
    _e);
  
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_length,
    4,
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_field,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_relation,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_owner,
    "",
    p,
    _e);
  
  _LOCAL_CHECK_STR_TAG
   (isc_api::ibp_isc_info_sql_alias,
    "",
    p,
    _e);

  _LOCAL_CHECK_TAG
   (isc_api::ibp_isc_info_sql_describe_end,
    p,
    _e);
 }//for n

 //-------------------------------------------------------- ibp_isc_info_truncated
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_truncated,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_111__data__bindStd2000__selectStd2000

////////////////////////////////////////////////////////////////////////////////

void WORK_Test_017__GetStatementInfo__bind::tag_impl::helper__check_tag
                          (TTSO_Tracer&                tracer,
                           const wchar_t*        const tagSign,
                           unsigned char         const expected_tagID,
                           const unsigned char** const pptr,
                           const unsigned char*  const end)
{
 assert(pptr);
 assert((*pptr)<=end);

 tracer<<L"check tag ["<<tagSign<<L"]"<<send;

 const auto*& p=*pptr;
 const auto* _e=end;

 _TSO_CHECK(p!=_e);

 _LOCAL_CHECK_VALUE
  ("#check_tag_id",
   *p,
   expected_tagID);

 ++p;
}//helper__check_tag

////////////////////////////////////////////////////////////////////////////////

void WORK_Test_017__GetStatementInfo__bind::tag_impl::helper__check_tag__Int
                          (TTSO_Tracer&                tracer,
                           const wchar_t*        const tagSign,
                           unsigned char         const expected_tagID,
                           long                  const expected_tagValue,
                           const unsigned char** const pptr,
                           const unsigned char*  const end)
{
 assert(pptr);
 assert((*pptr)<=end);

 tracer<<L"check int tag ["<<tagSign<<L"]"<<send;

 const auto*& p=*pptr;
 const auto* _e=end;

 _TSO_CHECK(p!=_e);

 _LOCAL_CHECK_VALUE
  ("#check_tag_id",
   *p,
   expected_tagID);

 ++p;

 _TSO_CHECK(p!=_e);
 _TSO_CHECK(isc_api::ibp_isc__info_tag__data_length__byte_count<=(_e-p));

 const size_t itemValueLength
  =helper__read_tag_length
    (tracer,
     tagSign,
     pptr,
     end);

 _LOCAL_CHECK_VALUE
  ("#check_length",
   itemValueLength,
   4);

 long itemValue=0;

 ibp::isc_base::isc_portable_format_to_integer::exec
  (itemValueLength,
   p,
   &itemValue,
   ibp::ibp_subsystem__remote_fb,
   L"itemValue");

 _LOCAL_CHECK_VALUE
  ("#check_value",
   itemValue,
   expected_tagValue);

 p+=itemValueLength;
}//helper__check_tag__Int

////////////////////////////////////////////////////////////////////////////////

void WORK_Test_017__GetStatementInfo__bind::tag_impl::helper__check_tag__Str
                          (TTSO_Tracer&                tracer,
                           const wchar_t*        const tagSign,
                           unsigned char         const expected_tagID,
                           const char*           const expected_tagValue,
                           const unsigned char** const pptr,
                           const unsigned char*  const end)
{
 assert(pptr);
 assert((*pptr)<=end);
 assert(expected_tagValue);

 tracer<<L"check str tag ["<<tagSign<<L"]"<<send;

 const auto*& p=*pptr;
 const auto* _e=end;

 _TSO_CHECK(p!=_e);

 _LOCAL_CHECK_VALUE
  ("#check_tag_id",
   *p,
   expected_tagID);

 ++p;

 _TSO_CHECK(p!=_e);
 _TSO_CHECK(isc_api::ibp_isc__info_tag__data_length__byte_count<=(_e-p));

 const size_t itemValueLength
  =helper__read_tag_length
    (tracer,
     tagSign,
     pptr,
     end);

 const size_t expected_tagValueSize
  =strlen(expected_tagValue);

 _LOCAL_CHECK_VALUE
  ("#check_length",
   itemValueLength,
   expected_tagValueSize);

 if(memcmp(expected_tagValue,p,expected_tagValueSize)!=0)
 {
  structure::str_formatter
   fmsg
    ("Wrong tag value: [%1].\n"
     "Expected value : [%2].");

  fmsg
   <<TestServices::PrepareStrForPrint(structure::make_str_box((const char*)p   ,expected_tagValueSize))
   <<TestServices::PrepareStrForPrint(structure::make_str_box(expected_tagValue,expected_tagValueSize));

  throw std::runtime_error(fmsg);
 }//if

 p+=itemValueLength;
}//helper__check_tag__Str

////////////////////////////////////////////////////////////////////////////////

size_t WORK_Test_017__GetStatementInfo__bind::tag_impl::helper__read_tag_length
                          (TTSO_Tracer&                tracer,
                           const wchar_t*        const tagSign,
                           const unsigned char** const pptr,
                           const unsigned char*  const end)
{
 assert(pptr);
 assert((*pptr)<=end);

 tracer<<L"read tag ["<<tagSign<<L"] length ...";

 const auto*& p=*pptr;
 const auto* _e=end;

 size_t itemValueLength=0;

 try
 {
  _TSO_CHECK(p!=_e);
  _TSO_CHECK(isc_api::ibp_isc__info_tag__data_length__byte_count<=(_e-p));

  ibp::isc_base::isc_portable_format_to_integer::exec
   (isc_api::ibp_isc__info_tag__data_length__byte_count,
    p,
    &itemValueLength,
    ibp::ibp_subsystem__remote_fb,
    L"itemValueLength");
 }
 catch(...)
 {
  tracer<<L"FAILED!"<<send;
  throw;
 }

 tracer<<itemValueLength<<send;

 p+=isc_api::ibp_isc__info_tag__data_length__byte_count;

 _TSO_CHECK(itemValueLength<=size_t(_e-p));

 return itemValueLength;
}//helper__read_tag_length

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_017__GetStatementInfo__bind::tag_descr

struct WORK_Test_017__GetStatementInfo__bind::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_017__GetStatementInfo__bind::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_017__GetStatementInfo__bind::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_017__GetStatementInfo__bind::tag_descr
 WORK_Test_017__GetStatementInfo__bind::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("103.data.only_bind_tag",
   test_103__data__only_bind_tag)

 DEF_TEST_DESCR
  ("104.data.bind__describe_vars__describe_end",
   test_104__data__bind__describe_vars__describe_end)

 DEF_TEST_DESCR
  ("105.data.bindSTD___no_parameters",
   test_105__data__bindSTD___no_parameters)

 DEF_TEST_DESCR
  ("106.data.bindSTD___one_param",
   test_106__data__bindSTD___one_param)

 DEF_TEST_DESCR
  ("107.data.bindStdOneParam__records",
   test_107__data__bindStdOneParam__records)

 DEF_TEST_DESCR
  ("108.data.bindStd2048",
   test_108__data__bindStd2048)

 DEF_TEST_DESCR
  ("109.data.bindStd1000__selectStd1000",
   test_109__data__bindStd1000__selectStd1000)

 DEF_TEST_DESCR
  ("110.data.bindStd1000__selectStd2000",
   test_110__data__bindStd1000__selectStd2000)

 DEF_TEST_DESCR
  ("111.data.bindStd2000__selectStd2000",
   test_111__data__bindStd2000__selectStd2000)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_017__GetStatementInfo__bind

void WORK_Test_017__GetStatementInfo__bind::create(TTSO_PushTest*      const pTestPusher,
                                             TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                              //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);    //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.017.GetStatementInfo__bind.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes[it[iPType]];

  ftestID
   <<structure::flush
   <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
   <<sm_Tests[it[iTest]].pTestSign;

  const TTSO_TestPtr
   spTest
    (structure::not_null_ptr
      (new TTSO_TestFunc_v2
        (pParams,
         ftestID.c_str(),
         sm_Tests[it[iTest]].Func,
         Data,
         sm_Tests[it[iTest]].pExecRules)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
#undef _LOCAL_CHECK_INT_TAG
#undef _LOCAL_MAKE_WSTR
#undef _LOCAL_CHECK_VALUE
////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
