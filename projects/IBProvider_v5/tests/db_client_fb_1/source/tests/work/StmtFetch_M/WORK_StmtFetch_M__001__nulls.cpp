////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/StmtFetch_M/WORK_StmtFetch_M__001__nulls.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__001__nulls::tag_null_it

class WORK_StmtFetch_M__001__nulls::tag_null_it
{
 private:
  typedef tag_null_it                                 self_type;

  tag_null_it(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_stl_vector<size_t,TTSO_MemoryAllocator>    indexes_type;

 public:
  tag_null_it(size_t Size,size_t Bits);

 ~tag_null_it();

  //interface ------------------------------------------------------------
  const indexes_type& point()const;

  bool ok() const;

  void next();

  bool has(size_t index) const;

 private:
  size_t const m_Size;

  size_t const m_Bits;

  indexes_type m_indexes;
};//class WORK_StmtFetch_M__001__nulls::tag_null_it

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__001__nulls::tag_null_it

WORK_StmtFetch_M__001__nulls::tag_null_it::tag_null_it(size_t const Size,
                                                  size_t const Bits)
 :m_Size(Size)
 ,m_Bits(Bits)
{
 assert(m_Bits>0);
 assert(m_Bits<=m_Size);

 this->next();
}

//------------------------------------------------------------------------
WORK_StmtFetch_M__001__nulls::tag_null_it::~tag_null_it()
{;}

//------------------------------------------------------------------------
const WORK_StmtFetch_M__001__nulls::tag_null_it::indexes_type&
 WORK_StmtFetch_M__001__nulls::tag_null_it::point()const
{
 return m_indexes;
}//point

//------------------------------------------------------------------------
bool WORK_StmtFetch_M__001__nulls::tag_null_it::ok()const
{
 assert(m_Bits>0);
 assert(m_Bits<=m_Size);

 if(m_indexes.size()<m_Bits)
  return false;

 assert(!m_indexes.empty());

 assert(m_indexes.back()<m_Size);

 return true;
}//ok

//------------------------------------------------------------------------
void WORK_StmtFetch_M__001__nulls::tag_null_it::next()
{
 assert(m_Bits>0);
 assert(m_Bits<=m_Size);

 while(!m_indexes.empty())
 {
  assert(m_indexes.back()<m_Size);

  ++m_indexes.back();

  if(m_indexes.back()<(m_Size-(m_Bits-m_indexes.size())))
   break;

  m_indexes.pop_back();

  if(m_indexes.empty())
   return;
 }//while

 while(m_indexes.size()<m_Bits)
 {
  if(m_indexes.empty())
   m_indexes.push_back(0);
  else
  if(m_indexes.back()<m_Size)
   m_indexes.push_back(m_indexes.back()+1);
  else
   break;
 }//while
}//next

//------------------------------------------------------------------------
bool WORK_StmtFetch_M__001__nulls::tag_null_it::has(size_t const index)const
{
 return std::binary_search(m_indexes.cbegin(),m_indexes.cend(),index);
}//has

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__001__nulls::tag_impl

class WORK_StmtFetch_M__001__nulls::tag_impl LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef tag_impl                                     self_type;

  tag_impl(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~tag_impl();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>     self_ptr;

 public:
  tag_impl(TTSO_GlobalContext*     pParams,
           const char*             pTestID,
           const TTSO_TestData_v2& Data,
           bool                    Revert,
           size_t                  nFields,
           size_t                  nNulls);

  //test interface -------------------------------------------------------
  virtual std::string get_id()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool can_exec()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  TTSO_TestData_v2 const m_Data;

  bool   const m_Revert;

  size_t const m_nFields;

  size_t const m_nNulls;
};//class WORK_StmtFetch_M__001__nulls::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__001__nulls::tag_impl

WORK_StmtFetch_M__001__nulls::tag_impl::tag_impl(TTSO_GlobalContext* const pParams,
                                            const char*         const pTestID,
                                            const TTSO_TestData_v2&   Data,
                                            bool                const Revert,
                                            size_t              const nFields,
                                            size_t              const nNulls)
 :m_spParams(lib::structure::not_null_ptr(pParams))
 ,m_TestID  (lib::structure::not_null_ptr(pTestID))
 ,m_Data    (Data)
 ,m_Revert  (Revert)
 ,m_nFields (nFields)
 ,m_nNulls  (nNulls)
{
 assert(m_spParams);
 assert(m_nNulls>0);
 assert(m_nNulls<=m_nFields);
}//tag_impl

//------------------------------------------------------------------------
WORK_StmtFetch_M__001__nulls::tag_impl::~tag_impl()
{;}

//test interface ---------------------------------------------------------
std::string WORK_StmtFetch_M__001__nulls::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool WORK_StmtFetch_M__001__nulls::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_StmtFetch_M__001__nulls::tag_impl::run(context_type* const pCtx)const
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
 // XSQLDA_V1_Wrapper xsqlda(/*n*/m_nFields);
 //
 // assert(structure::can_numeric_cast(&xsqlda->sqld,m_nFields));
 //
 // structure::static_numeric_cast(&xsqlda->sqld,m_nFields);
 //
 // structure::t_stl_vector<db_obj::t_dbvalue__i4,TTSO_MemoryAllocator>
 //  fieldValues(m_nFields);
 //
 // structure::t_stl_vector<db_obj::t_dbvalue__i2,TTSO_MemoryAllocator>
 //  fieldSqlInds(m_nFields);
 //
 // for(size_t i=0;i!=m_nFields;++i)
 // {
 //  xsqlda->sqlvar[i].sqltype =isc_api::ibp_isc_sql_long|1;
 //
 //  xsqlda->sqlvar[i].sqllen  =sizeof(db_obj::t_dbvalue__i4);
 //
 //  xsqlda->sqlvar[i].sqldata =reinterpret_cast<char*>(&fieldValues[i]);
 //  xsqlda->sqlvar[i].sqlind  =&fieldSqlInds[i];
 // }//for i

 //------------------------------------------------- OUTPUT
 assert(m_nFields<=(USHRT_MAX/2));

 const unsigned short cPars=(unsigned short)(2*m_nFields);

 const unsigned char cPars__lower=(unsigned char)((cPars   )&0x00FF);
 const unsigned char cPars__upper=(unsigned char)((cPars>>8)&0x00FF);

 assert(size_t(256*cPars__upper+cPars__lower)==(2*m_nFields));

 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__BLR;

 OutMsg__BLR.reserve(6+4*m_nFields+2);

 OutMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ cPars__lower,
  /*  5 */ cPars__upper,
 };

 for(size_t i=0;i!=m_nFields;++i)
 {
  OutMsg__BLR.push_back(isc_api::ibp_isc_blr_dtype__long);
  OutMsg__BLR.push_back(0);
  OutMsg__BLR.push_back(isc_api::ibp_isc_blr_dtype__short);
  OutMsg__BLR.push_back(0);
 }//for i

 OutMsg__BLR.push_back(isc_api::ibp_isc_blr_end);
 OutMsg__BLR.push_back(isc_api::ibp_isc_blr_eoc);

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator>
  OutMsg__DATA
   (m_nFields*(/*value*/4+/*ind*/2+/*align*/2)-/*last align*/2);

 //-----------------------------------------
 structure::t_stl_vector<svc::remote_fb_in_msg_v1::descr_type,TTSO_MemoryAllocator>
  OutMsg__DATA_DESCRS
   (m_nFields);

 for(size_t i=0;i!=m_nFields;++i)
 {
  auto& descr=OutMsg__DATA_DESCRS[i];

  descr.m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
  descr.m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
  descr.m_xvar_sqlscale          =0;
  descr.m_msg_value_block_size   =4;
  descr.m_msg_value_block_offset =i*8;
  descr.m_msg_sqlind_offset      =descr.m_msg_value_block_offset+4;
 }//for i

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 unsigned __int64 nPass=0;

 tag_null_it null_it(m_nFields,m_nNulls);

 try
 {
  for(;null_it.ok();null_it.next())
  {
   ++nPass;

   if((nPass%200000)==0)
    tracer<<"nPass: "<<nPass<<send;

   //----------------------------------------
   std::ostringstream sql;

   sql<<"EXECUTE BLOCK RETURNS(";

   for(size_t i=0;i!=m_nFields;++i)
   {
    if(i>0)
     sql<<",";

    sql<<"N"<<i<<" INTEGER";
   }//for i

   sql<<")AS BEGIN ";

   for(size_t i=0;i!=m_nFields;++i)
   {
    sql<<"N"<<i<<"=";

    if(null_it.has(i) ^ m_Revert)
    {
     sql<<"NULL;";
    }
    else
    {
     sql<<i<<";";
    }
   }//for

   sql<<"SUSPEND;END;";

   //tracer<<sql.str()<<send;

   svc::RemoteFB_Connector__StmtPrepare
    (spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
     sql.str());

   svc::RemoteFB_Connector__StmtExecute
    (spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     /*in*/nullptr,
     /*out*/nullptr);

   // std::fill(fieldValues.begin(),fieldValues.end(),structure::negative_one);
   //
   // std::fill(fieldSqlInds.begin(),fieldSqlInds.end(),12345);

   std::fill(OutMsg__DATA.begin(),OutMsg__DATA.end(),0xBC);

   svc::RemoteFB_Connector__StmtFetch_M_ToRow
    (spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);

   for(size_t i=0;i!=m_nFields;++i)
   {
    db_obj::t_dbvalue__i4 columnValue=0;
    db_obj::t_dbvalue__i2 columnInd=0;

    //---
    assert_s(sizeof(columnValue)==4);

    memcpy(&columnValue,&OutMsg__DATA[OutMsg__DATA_DESCRS[i].m_msg_value_block_offset],sizeof(columnValue));

    //---
    assert_s(sizeof(columnInd)==2);

    memcpy(&columnInd,&OutMsg__DATA[OutMsg__DATA_DESCRS[i].m_msg_sqlind_offset],sizeof(columnInd));

    //---
    if(null_it.has(i) ^ m_Revert)
    {
     _TSO_CHECK(columnValue==0)
     _TSO_CHECK(columnInd==-1)
    }
    else
    {
     _TSO_CHECK(columnValue==i)
     _TSO_CHECK(columnInd==0)
    }
   }//for i

   svc::RemoteFB_Connector__StmtClose
    (spConnector,
     &hStmt);
  }//for null_it
 }
 catch(...)
 {
  tracer(tso_msg_error,-1)<<L"point: [";

  for(size_t i=0;i!=null_it.point().size();++i)
  {
   if(i)
    tracer<<L" ";

   tracer<<null_it.point()[i];
  }//for

  tracer<<L"] #"<<nPass<<send;

  throw;
 }//catch

 tracer<<L"nPass: "<<nPass<<send;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//run

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__001__nulls

void WORK_StmtFetch_M__001__nulls::create(TTSO_PushTest*      const pTestPusher,
                                     TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 //-----------------------------------------
 const bool FalseTrue[]={false,true};

 //-----------------------------------------
 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);    // 0
 it.add(0,_DIM_(FalseTrue)-1);                             // 1 //revert

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.StmtFetch_M.001.nulls.%1.%2.fields_%3.nulls_%4");

 TTSO_TestData_v2 Data;

 //-----------------------------------------
 for(;it;++it)
 {
  Data.m_RemoteFB__ProtocolType=g_TestCfg__RemoteFB__ProtocolTypes[it[0]];

  const bool Revert=FalseTrue[it[1]];

  for(size_t nFields=1;nFields<=33;++nFields)
  {
   size_t N;

   if(nFields<17)
    N=min(9,nFields);
   else
    N=min(3,nFields);

   for(size_t nNulls=1;nNulls<=N;++nNulls)
   {
    ftestID
     <<structure::flush
     <<(Revert?"revert":"direct")
     <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
     <<nFields
     <<nNulls;

    const tag_impl::self_ptr
     spTest
      (lib::structure::not_null_ptr
        (new tag_impl
          (pParams,
           ftestID.c_str(),
           Data,
           Revert,
           nFields,
           nNulls)));

    pTestPusher->PushTest(spTest);
   }//nNulls
  }//for nFields
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
