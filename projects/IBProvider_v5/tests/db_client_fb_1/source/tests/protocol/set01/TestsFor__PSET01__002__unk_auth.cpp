////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/protocol/set01/TestsFor__PSET01__002__unk_auth.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/test_utilities.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"

#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////

const wchar_t* const
 TestsFor__PSET01__002__unk_auth::sm_params__authNames[]=
{
 L"USUS", L"Srp",L"Srp224",L"Srp256",L"Srp384",L"Srp512",
};//sm_params__authNames

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__PSET01__002__unk_auth

TestsFor__PSET01__002__unk_auth::TestsFor__PSET01__002__unk_auth
                                           (TTSO_GlobalContext* const pParams,
                                            const char*         const pTestID,
                                            const wchar_t*      const pAuthName)
 :m_spParams(lib::structure::not_null_ptr(pParams))
 ,m_testID(lib::structure::not_null_ptr(pTestID))
 ,m_authName(lib::structure::not_null_ptr(pAuthName))
{
 assert(m_spParams);
}//TestsFor__PSET01__002__unk_auth

//------------------------------------------------------------------------
TestsFor__PSET01__002__unk_auth::~TestsFor__PSET01__002__unk_auth()
{
}//TestsFor__PSET01__002__unk_auth

//------------------------------------------------------------------------
void TestsFor__PSET01__002__unk_auth::create(TTSO_PushTest*      const pTestPusher,
                                             TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher);
 assert(pParams);

 //------------------------------------
 typedef structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it_type;

 it_type it;

 it.add(0,_DIM_(sm_params__authNames)-1);

 //------------------------------------
 structure::str_formatter
  ftestID
   ("RemoteFB.protocol.set01.002.unk_auth.%1");

 for(;it;++it)
 {
  const auto* const param__authName=sm_params__authNames[it[0]];

  ftestID
   <<structure::flush
   <<param__authName;

  TTSO_TestPtr
   spTest
    (lib::structure::not_null_ptr
      (new self_type
        (pParams,
         ftestID.c_str(),
         param__authName)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

//------------------------------------------------------------------------
std::string TestsFor__PSET01__002__unk_auth::get_id()const
{
 return m_testID;
}//get_id

//------------------------------------------------------------------------
bool TestsFor__PSET01__002__unk_auth::can_exec()const
{
 return m_spParams->calc_expression("NE__PSET01");
}//can_exec

//------------------------------------------------------------------------
void TestsFor__PSET01__002__unk_auth::run(context_type* const pCtx)const
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

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__auth(m_authName);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
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

  errSvc::check_err_rec__cn_err__auth_service_not_supported
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset01,
    m_authName);

  errSvc::check_err_code
   (exc.com_code(),
    DB_SEC_E_AUTH_FAILED);

  errSvc::error_rec__check_sqlstate_and_native_code
   (tracer,
    exc.get_record(0),
    L"28000", //IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS
    DB_SEC_E_AUTH_FAILED);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//run

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
