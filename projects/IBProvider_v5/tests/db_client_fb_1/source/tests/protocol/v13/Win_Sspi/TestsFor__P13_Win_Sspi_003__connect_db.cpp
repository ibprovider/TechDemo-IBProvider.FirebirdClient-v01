////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/protocol/v13/Win_Sspi/TestsFor__P13_Win_Sspi_003__connect_db.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"

#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////

#define DEF_DESCR2(id,propVal) {CryptMode::id,propVal}

#define DEF_DESCR(x) DEF_DESCR2(x,#x)

const TestsFor__P13_Win_Sspi_003__connect_db::tagCryptModeDescr
 TestsFor__P13_Win_Sspi_003__connect_db::sm_params__CryptModes[]=
{
 DEF_DESCR2(default_,"default"),
 DEF_DESCR (disabled),
 DEF_DESCR (enabled),
 DEF_DESCR (required),
};//sm_params__CryptModes

#undef DEF_DESCR
#undef DEF_DESCR2

////////////////////////////////////////////////////////////////////////////////

#define DEF_DESCR2(id,propVal) {CompressMode::id,propVal}

#define DEF_DESCR(x) DEF_DESCR2(x,#x)

const TestsFor__P13_Win_Sspi_003__connect_db::tagCompressModeDescr
 TestsFor__P13_Win_Sspi_003__connect_db::sm_params__CompressModes[]=
{
 DEF_DESCR2(default_,"default"),
 DEF_DESCR (disabled),
 DEF_DESCR (enabled),
 DEF_DESCR (required),
};//sm_params__CompressModes

#undef DEF_DESCR
#undef DEF_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__P13_Win_Sspi_003__connect_db

TestsFor__P13_Win_Sspi_003__connect_db::TestsFor__P13_Win_Sspi_003__connect_db
                                           (TTSO_GlobalContext* const pParams,
                                            const char*         const pTestID,
                                            CryptMode           const cryptMode,
                                            CompressMode        const compressMode,
                                            PFnExec             const pfnExec)
 :m_spParams(lib::structure::not_null_ptr(pParams))
 ,m_testID(lib::structure::not_null_ptr(pTestID))
 ,m_cryptMode(cryptMode)
 ,m_compressMode(compressMode)
 ,m_pfnExec(pfnExec)
{
 assert(m_spParams);
 assert(m_pfnExec);
}//TestsFor__P13_Win_Sspi_003__connect_db

//------------------------------------------------------------------------
TestsFor__P13_Win_Sspi_003__connect_db::~TestsFor__P13_Win_Sspi_003__connect_db()
{
}//TestsFor__P13_Win_Sspi_003__connect_db

//------------------------------------------------------------------------
void TestsFor__P13_Win_Sspi_003__connect_db::create(TTSO_PushTest*      const pTestPusher,
                                                    TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher);
 assert(pParams);

 //------------------------------------
 typedef structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it_type;

 it_type it;

 it.add(0,_DIM_(sm_params__CompressModes)-1);
 it.add(0,_DIM_(sm_params__CryptModes)-1);

 //------------------------------------
 structure::str_formatter ftestID("RemoteFB.protocol.v13.Win_Sspi.003.connect_db.crypt__%1.compress__%2");

 for(;it;++it)
 {
  const auto& param__compressModeDescr =sm_params__CompressModes[it[0]];
  const auto& param__cryptModeDescr    =sm_params__CryptModes[it[1]];

  ftestID
   <<structure::flush
   <<param__cryptModeDescr.sign
   <<param__compressModeDescr.sign;

  PFnExec pfnExec=self_type::Helper__Exec_Ok;

  if(param__cryptModeDescr.cryptMode==CryptMode::required)
  {
   pfnExec=self_type::Helper__Exec_Failed;
  }//if

  TTSO_TestPtr
   spTest
    (lib::structure::not_null_ptr
      (new self_type
        (pParams,
         ftestID.c_str(),
         param__cryptModeDescr.cryptMode,
         param__compressModeDescr.compressMode,
         pfnExec)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

//test interface ---------------------------------------------------------
std::string TestsFor__P13_Win_Sspi_003__connect_db::get_id()const
{
 return m_testID;
}//get_id

//------------------------------------------------------------------------
bool TestsFor__P13_Win_Sspi_003__connect_db::can_exec()const
{
 return m_spParams->calc_expression("SRV>=FB-3");
}//can_exec

//------------------------------------------------------------------------
void TestsFor__P13_Win_Sspi_003__connect_db::run(context_type* const pCtx)const
{
 assert(pCtx);
 assert(m_spParams);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(m_spParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(structure::tstr_to_wstr(m_spParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(m_spParams);

 params.set_dbprop_init__user_id(L"SYSDBA");

 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__13);

 params.set_dbprop_init__remote__auth(L"Win_Sspi");

 //-----------------------------------------
 switch(m_cryptMode)
 {
  case CryptMode::default_:
  {
   params.reset_dbprop_init__remote__wire_crypt();
   break;
  }

  case CryptMode::disabled:
  {
   params.set_dbprop_init__remote__wire_crypt(ibprovider::ibp_propval__remote__wire_crypt__disabled);
   break;
  }

  case CryptMode::enabled:
  {
   params.set_dbprop_init__remote__wire_crypt(ibprovider::ibp_propval__remote__wire_crypt__enabled);
   break;
  }

  case CryptMode::required:
  {
   params.set_dbprop_init__remote__wire_crypt(ibprovider::ibp_propval__remote__wire_crypt__required);
   break;
  }

  default:
  {
   assert(false);
   break;
  }
 }//switch

 //-----------------------------------------
 switch(m_compressMode)
 {
  case CompressMode::default_:
  {
   params.reset_dbprop_init__remote__wire_compression();
   break;
  }

  case CompressMode::disabled:
  {
   params.set_dbprop_init__remote__wire_compression(ibprovider::ibp_propval__remote__wire_compression__disabled);
   break;
  }

  case CompressMode::enabled:
  {
   params.set_dbprop_init__remote__wire_compression(ibprovider::ibp_propval__remote__wire_compression__enabled);
   break;
  }

  case CompressMode::required:
  {
   params.set_dbprop_init__remote__wire_compression(ibprovider::ibp_propval__remote__wire_compression__required);
   break;
  }

  default:
  {
   assert(false);
   break;
  }
 }//switch

 //-----------------------------------------
 assert(m_pfnExec);

 m_pfnExec
  (tracer,
   hostName,
   dbName,
   params);
}//run

//helper methods ---------------------------------------------------------
void TestsFor__P13_Win_Sspi_003__connect_db::Helper__Exec_Ok
                                           (TTSO_Tracer&  tracer,
                                            wstr_box_type hostName,
                                            wstr_box_type dbName,
                                            TestCnParams& params)
{
 typedef TestServices svc;

 const svc::remote_fb_inet_port_ptr
  spPort
   =svc::RemoteFB_INET_Port__ConnectToDatabase
     (tracer,
      ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
      hostName,
      nullptr,
      dbName,
      params);
}//Helper__Exec_Ok

//------------------------------------------------------------------------
void TestsFor__P13_Win_Sspi_003__connect_db::Helper__Exec_Failed
                                           (TTSO_Tracer&  tracer,
                                            wstr_box_type hostName,
                                            wstr_box_type dbName,
                                            TestCnParams& params)
{
 typedef TestServices svc;

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName,
       nullptr,
       dbName,
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__wire_crypt_not_possible__no_crypt_keys
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_p13,
    L"Win_Sspi");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//Helper__Exec_Failed

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
