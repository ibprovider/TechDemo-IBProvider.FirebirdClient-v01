////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/api/p13/RemoteFB__P13__XSQLDA_Utilities/TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__xsqlda_utilities.h"
#include "source/test_services.h"
#include "source/xsqlda_v1_wrapper.h"
#include <structure/test_obj/t_tso_user.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl

class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl self_type;

  TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~tag_impl();

 public: //typedefs ------------------------------------------------------
  typedef remote_fb::api::p13::RemoteFB__P13__XSQLDA_Utilities  xsqlda_utils_type;

 public:
  tag_impl(TTSO_GlobalContext*         pParams,
           structure::t_const_str_box  TestID,
           unsigned char               nXVars);

  //test interface -------------------------------------------------------
  virtual std::string get_id()const COMP_W000004_OVERRIDE_FINAL;

  virtual bool can_exec()const COMP_W000004_OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const COMP_W000004_OVERRIDE_FINAL;

 private:
  const TTSO_GlobalContext::self_ptr m_spParams;

  const std::string m_TestID;

  unsigned char const m_nXVars;
};//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl

TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl::tag_impl
                                           (TTSO_GlobalContext*        const pParams,
                                            structure::t_const_str_box const TestID,
                                            unsigned char              const nXVars)
 :m_spParams(structure::not_null_ptr(pParams))
 ,m_TestID(TestID.make_str())
 ,m_nXVars(nXVars)
{
 assert(m_spParams);
 assert(!m_TestID.empty());
 assert(m_nXVars<=32);
}//tag_impl

//------------------------------------------------------------------------
TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl::~tag_impl()
{;}

//test interface ---------------------------------------------------------
std::string TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl::can_exec()const
{
 return true;
}//can_exec

//------------------------------------------------------------------------
void TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::tag_impl::run
                                           (context_type* const pCtx)const
{
 assert(pCtx);
 assert(m_spParams);
 assert(m_nXVars<=32);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 structure::t_stl_vector<short,TTSO_MemoryAllocator> sqlinds(m_nXVars);

 XSQLDA_V1_Wrapper xsqlda(m_nXVars);

 for(size_t n=0;n!=m_nXVars;++n)
 {
  xsqlda->sqlvar[n].sqltype=(isc_api::ibp_isc_sql_long|1);

  xsqlda->sqlvar[n].sqlind=&sqlinds[n];
 }//for n

 xsqlda->sqld=m_nXVars;

 //-----------------------------------------
 xsqlda_utils_type::msg_nulls_buffer_type nulls;

 //-----------------------------------------
 const unsigned __int32 nVariants=(1<<m_nXVars);

 assert(nVariants);

 //-----------------------------------------
 const size_t nClusters=((m_nXVars/8) + ((m_nXVars%8)?1:0));

 //-----------------------------------------
 unsigned nPass=0;

 for(unsigned __int32 Mask=0;Mask!=nVariants;++Mask)
 {
  ++nPass;

  if((nPass%1000000)==0)
  {
   tracer<<L"Pass: "<<nPass<<send;
  }

  //build sqlinds
  for(size_t n=0;n!=m_nXVars;++n)
  {
   if((Mask&(1<<n))==0)
    sqlinds[n]=0;
   else
    sqlinds[n]=-1;
  }//for n

  //----------------------------------------
  nulls.alloc(nClusters+1);

  std::fill(nulls.buffer(),nulls.buffer_end(),0xFF);

  //----------------------------------------
  assert(xsqlda->sqld==m_nXVars);

  xsqlda_utils_type::Build_XSQLDA_MSG_NULLS
   (xsqlda,
    nulls);

  _TSO_CHECK(nulls.size()==nClusters);

  //----------------------------------------
  auto Mask1=Mask;

  for(size_t n=0;n!=nulls.size();++n)
  {
   const auto cluster=(Mask1&0xFF);

   _TSO_CHECK(nulls[n]==cluster);

   Mask1=(Mask1>>8);
  }//for
 }//for Mask

 tracer<<L"Pass: "<<nPass<<send;
}//run

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001

void TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__001::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher);
 assert(pParams);

 structure::str_formatter
  ftestID("RemoteFB.API.P13.XSQLDA_Utilities.Build_XSQLDA_MSG_NULLS.001.count__%1");

 for(unsigned char n=0;n!=26;++n)
 {
  ftestID
   <<structure::flush
   <<n;

  const TTSO_TestCPtr
   spTest(structure::not_null_ptr(new tag_impl(pParams,
                                               ftestID.str(),
                                               n)));

  pTestPusher->PushTest(spTest);
 }//for n
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
