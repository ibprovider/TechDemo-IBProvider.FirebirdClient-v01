////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Blob/WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::tag_impl

class WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::tag_impl
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  using self_type=tag_impl;

  tag_impl(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~tag_impl();

 public:
  tag_impl(TTSO_GlobalContext*     pParams,
           const char*             pTestID,
           const TTSO_TestData_v2& Data,
           bool                    forceFlush,
           size_t                  szBlob,
           size_t                  szBlock);

  //test interface -------------------------------------------------------
  virtual const char* get_id()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool can_exec()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  TTSO_TestData_v2 const m_Data;

 private:
  const bool   m_forceFlush;
  const size_t m_szBlob;
  const size_t m_szBlock;
};//class WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::tag_impl

WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::tag_impl::tag_impl
                                           (TTSO_GlobalContext* const pParams,
                                            const char*         const pTestID,
                                            const TTSO_TestData_v2&   Data,
                                            bool                const forceFlush,
                                            size_t              const szBlob,
                                            size_t              const szBlock)
 :m_spParams(lib::structure::not_null_ptr(pParams))
 ,m_TestID(pTestID)
 ,m_Data(Data)
 ,m_forceFlush(forceFlush)
 ,m_szBlob(szBlob)
 ,m_szBlock(szBlock)
{
 assert(m_spParams);

 assert(m_szBlock<=m_szBlob);

 assert(m_szBlock>0 || m_szBlock==0);
}//tag_impl

//------------------------------------------------------------------------
WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::tag_impl::~tag_impl()
{;}

//test interface ---------------------------------------------------------
const char* WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::tag_impl::get_id()const
{
 return m_TestID.c_str();
}//get_id

//------------------------------------------------------------------------
bool WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::tag_impl::run(context_type* const pCtx)const
{
 assert(pCtx);
 assert(m_spParams);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(m_spParams);

 params.set_dbprop_init__location(svc::BuildLocationString(m_spParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 m_Data.SetParams(params);

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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "execute block (A BLOB=?)\n"
    "returns(B BLOB)\n"
    "AS\n"
    "BEGIN\n"
    " B=A; SUSPEND;\n"
    "END;");

 //-----------------------------------------
 db_obj::DB_IBBLOBID blobID={};

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_blob;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
 xsqlda->sqlvar[0].sqllen     =sizeof(blobID);
 xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&blobID);
 xsqlda->sqlvar[0].sqlind     =nullptr;

 xsqlda->sqld=1;

 //-----------------------------------------
 typedef structure::t_typed_simple_buffer<unsigned char,TTSO_MemoryAllocator>
  blobData_type;

 blobData_type blobData(m_szBlob);

 for(size_t i=0;i!=blobData.size();++i)
 {
  blobData[i]=(unsigned char)(i%223);
 }//for i

 //-----------------------------------------
 svc::remote_fb_blob_handle_type hBlob(nullptr);

 svc::RemoteFB_Connector__CreateBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   &blobID);

 {
  blobData_type::const_pointer        pSrc=blobData.buffer();
  blobData_type::const_pointer const _eSrc=blobData.buffer_end();

  for(;;)
  {
   assert(pSrc<=_eSrc);

   size_t sz=size_t(_eSrc-pSrc);

   if(m_szBlock<sz)
    sz=m_szBlock;

   spConnector->WriteBlob
    (OpCtx,
     &hBlob,
     sz,
     pSrc); //throw

   _TSO_CHECK(hBlob);
   _TSO_CHECK(hBlob->m_WriteMode__BufferPos<=hBlob->m_Buffer.size());

   if(m_forceFlush)
   {
    spConnector->FlushBlob
     (OpCtx,
      &hBlob);

    _TSO_CHECK(hBlob);
    _TSO_CHECK(hBlob->m_WriteMode__BufferPos==0);
   }//if

   pSrc+=sz;

   if(pSrc==_eSrc)
    break;
  }//for[ever]
 }//local

 {
  const auto hCopyBlob(hBlob);

  svc::RemoteFB_Connector__CloseBlob
   (tracer,
    spConnector,
    OpCtx,
    &hBlob);

  _TSO_CHECK(!hBlob);

  _TSO_CHECK(spConnector->GetData()->DeletedBlobList__GetCount()==1);
  _TSO_CHECK(spConnector->GetData()->DeletedBlobList__GetHead()==hCopyBlob);
 }//local

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   xsqlda,
   /*out*/nullptr);

 _TSO_CHECK(spConnector->GetData()->DeletedBlobList__GetCount()==0);
 _TSO_CHECK(!spConnector->GetData()->DeletedBlobList__GetHead());

 //-----------------------------------------
 blobID=db_obj::__null_ib_blob_id;

 svc::RemoteFB_Connector__StmtFetch_ToRow
  (spConnector,
   OpCtx,
   &hStmt,
   xsqlda);

 svc::RemoteFB_Connector__OpenBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   blobID);

 svc::RemoteFB_Connector__StmtClose
  (tracer,
   spConnector,
   &hStmt);

 //----------------------------------------- check blob
 {
  blobData_type::const_pointer        pSrc=blobData.buffer();
  blobData_type::const_pointer const _eSrc=blobData.buffer_end();

  blobData_type blobData2(m_szBlock+1);

  size_t cbActualReaded=0;

  bool readResult=true;

  for(;;)
  {
   readResult
     =spConnector->ReadBlob
      (OpCtx,
       &hBlob,
       blobData2.size(),
       blobData2.buffer(),
       &cbActualReaded); //throw

   _TSO_CHECK(hBlob)

   _TSO_CHECK(cbActualReaded<=size_t(_eSrc-pSrc));

   if(readResult)
   {
    _TSO_CHECK(cbActualReaded==blobData2.size());
    _TSO_CHECK(cbActualReaded>0);
   }
   else
   {
    _TSO_CHECK(cbActualReaded<=blobData2.size());
   }

   _TSO_CHECK(structure::equal(pSrc,
                               pSrc+cbActualReaded,
                               blobData2.buffer(),
                               blobData2.buffer()+cbActualReaded));

   pSrc+=cbActualReaded;

   if(!readResult)
    break;
  }//for[ever]

  _TSO_CHECK(pSrc==_eSrc);
 }//local

 {
  const auto hCopyBlob(hBlob);

  svc::RemoteFB_Connector__CloseBlob
   (tracer,
    spConnector,
    OpCtx,
    &hBlob);

  _TSO_CHECK(!hBlob);

  _TSO_CHECK(spConnector->GetData()->DeletedBlobList__GetCount()==1);
  _TSO_CHECK(spConnector->GetData()->DeletedBlobList__GetHead()==hCopyBlob);
 }//local

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(spConnector->GetData()->DeletedBlobList__GetCount()==0);
 _TSO_CHECK(!spConnector->GetData()->DeletedBlobList__GetHead());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//run

////////////////////////////////////////////////////////////////////////////////
//class WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send

void WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.Blob.01.WriteAndReadBinData.v2.ptype__%1.Flush_%2.%3.BlobSize_%4.BlockSize_%5");

 //-----------------------------------------
 bool data_forceFlush[]={false,true};

 //-----------------------------------------
 typedef structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it_type;

 it_type it;

 it.add(0,_DIM_(data_forceFlush)-1);
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__lazy_send)-1);

 //-----------------------------------------
 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  const bool param_forceFlush=data_forceFlush[it[0]];

  Data.m_RemoteFB__ProtocolType=g_TestCfg__RemoteFB__ProtocolTypes__lazy_send[it[1]];

  helper__create(pTestPusher,
                 pParams,
                 ftestID,
                 Data,
                 param_forceFlush);
 }//it
}//create

//------------------------------------------------------------------------
void WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::helper__create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams,
                                            structure::str_formatter& ftestID,
                                            const TTSO_TestData_v2&   Data,
                                            bool                const forceFlush)
{
 size_t nTest=0;

 //-----------------------------------------
 helper__create(pTestPusher,
                pParams,
                ftestID,
                Data,
                forceFlush,
                nTest,
                0,
                129);

 //-----------------------------------------
 helper__create(pTestPusher,
                pParams,
                ftestID,
                Data,
                forceFlush,
                nTest,
                4*1024-9,
                4*1024+10);

 //-----------------------------------------
 helper__create(pTestPusher,
                pParams,
                ftestID,
                Data,
                forceFlush,
                nTest,
                64*1024-9,
                64*1024+10);

 //-----------------------------------------
 helper__create(pTestPusher,
                pParams,
                ftestID,
                Data,
                forceFlush,
                nTest,
                2*64*1024-9,
                2*64*1024+10);

 //-----------------------------------------
 helper__create(pTestPusher,
                pParams,
                ftestID,
                Data,
                forceFlush,
                nTest,
                3*64*1024-9,
                3*64*1024+10);

 //-----------------------------------------
 //! \todo
 //!  Следующую группу тестов не имеет смысл выполнять с forceFlush,
 //!  пока не появится параллельное выполнение тестов.
 //!
 //!  Потому что песец как медленно.

 if(!forceFlush)
 {
  helper__create(pTestPusher,
                 pParams,
                 ftestID,
                 Data,
                 forceFlush,
                 nTest,
                 1024*1024-64,
                 1024*1024+64);
 }//if !forceFlush
}//helper__create

//------------------------------------------------------------------------
void WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::helper__create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams,
                                            structure::str_formatter& ftestID,
                                            const TTSO_TestData_v2&   Data,
                                            bool                const forceFlush,
                                            size_t&                   nTest,
                                            size_t              const szBegin,
                                            size_t              const szEnd)
{
 const size_t Blocks[]={1,2,3,7,4*1024,8*1024,12345};

 for(size_t sz=szBegin;sz!=szEnd;++sz)
 {
  for(size_t iBlock=0;iBlock!=_DIM_(Blocks);++iBlock)
  {
   if(sz<=Blocks[iBlock])
    break;

   helper__create_test(pTestPusher,
                       pParams,
                       ftestID,
                       Data,
                       forceFlush,
                       nTest,
                       sz,
                       Blocks[iBlock]);
  }//for iSeg

  {
   //BlockSize == BlobSize
   helper__create_test(pTestPusher,
                       pParams,
                       ftestID,
                       Data,
                       forceFlush,
                       nTest,
                       sz,
                       sz);
  }//local
 }//for sz
}//helper__create

//------------------------------------------------------------------------
void WORK_Blob_Test_01__WriteAndReadBinData__v2_lazy_send::helper__create_test
                                           (TTSO_PushTest*       const pTestPusher,
                                            TTSO_GlobalContext*  const pParams,
                                            structure::str_formatter&  ftestID,
                                            const TTSO_TestData_v2&   Data,
                                            bool                 const forceFlush,
                                            size_t&                    nTest,
                                            size_t               const szBlob,
                                            size_t               const szBlock)
{
 assert(pTestPusher);
 assert(pParams);

 ++nTest;

 ftestID<<structure::flush
        <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
        <<forceFlush
        <<nTest
        <<szBlob
        <<szBlock;

 const TTSO_TestPtr spTest(new tag_impl(pParams,
                                        ftestID.c_str(),
                                        Data,
                                        forceFlush,
                                        szBlob,
                                        szBlock));
 pTestPusher->PushTest(spTest);
}//helper__create_test

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
