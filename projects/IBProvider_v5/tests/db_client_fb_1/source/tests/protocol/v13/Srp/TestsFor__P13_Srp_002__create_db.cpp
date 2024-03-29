////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/protocol/v13/Srp/TestsFor__P13_Srp_002__create_db.h"
#include "source/test_services.h"
#include "source/test_func.h"
#include "source/test_utilities.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"

#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////

#define DEF_DESCR2(id,propVal) {CryptMode::id,propVal}

#define DEF_DESCR(x) DEF_DESCR2(x,#x)

const TestsFor__P13_Srp_002__create_db::tagCryptModeDescr
 TestsFor__P13_Srp_002__create_db::sm_params__CryptModes[]=
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

const TestsFor__P13_Srp_002__create_db::tagCompressModeDescr
 TestsFor__P13_Srp_002__create_db::sm_params__CompressModes[]=
{
 DEF_DESCR2(default_,"default"),
 DEF_DESCR (disabled),
 DEF_DESCR (enabled),
 DEF_DESCR (required),
};//sm_params__CompressModes

#undef DEF_DESCR
#undef DEF_DESCR2

////////////////////////////////////////////////////////////////////////////////

const wchar_t* const
 TestsFor__P13_Srp_002__create_db::sm_params__srpNames[]=
{
 L"Srp",L"Srp224",L"Srp256",L"Srp384",L"Srp512",
};//sm_params__srpNames

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__P13_Srp_002__create_db

TestsFor__P13_Srp_002__create_db::TestsFor__P13_Srp_002__create_db
                                           (TTSO_GlobalContext* const pParams,
                                            const char*         const pTestID,
                                            const wchar_t*      const pSrpName,
                                            CryptMode           const cryptMode,
                                            CompressMode        const compressMode)
 :m_spParams(lib::structure::not_null_ptr(pParams))
 ,m_testID(lib::structure::not_null_ptr(pTestID))
 ,m_srpName(lib::structure::not_null_ptr(pSrpName))
 ,m_cryptMode(cryptMode)
 ,m_compressMode(compressMode)
{
 assert(m_spParams);
}//TestsFor__P13_Srp_002__create_db

//------------------------------------------------------------------------
TestsFor__P13_Srp_002__create_db::~TestsFor__P13_Srp_002__create_db()
{
}//TestsFor__P13_Srp_002__create_db

//------------------------------------------------------------------------
void TestsFor__P13_Srp_002__create_db::create(TTSO_PushTest*      const pTestPusher,
                                              TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher);
 assert(pParams);

 //------------------------------------
 typedef structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it_type;

 it_type it;

 it.add(0,_DIM_(sm_params__CompressModes)-1);
 it.add(0,_DIM_(sm_params__CryptModes)-1);
 it.add(0,_DIM_(sm_params__srpNames)-1);

 //------------------------------------
 structure::str_formatter ftestID("RemoteFB.protocol.v13.Srp.002.create_db.%1.crypt__%2.compress__%3");

 for(;it;++it)
 {
  const auto&       param__compressModeDescr=sm_params__CompressModes[it[0]];
  const auto&       param__cryptModeDescr=sm_params__CryptModes[it[1]];
  const auto* const param__srpName=sm_params__srpNames[it[2]];

  ftestID
   <<structure::flush
   <<param__srpName
   <<param__cryptModeDescr.sign
   <<param__compressModeDescr.sign;

  TTSO_TestPtr
   spTest
    (lib::structure::not_null_ptr
      (new self_type
        (pParams,
         ftestID.c_str(),
         param__srpName,
         param__cryptModeDescr.cryptMode,
         param__compressModeDescr.compressMode)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

//------------------------------------------------------------------------
const char* TestsFor__P13_Srp_002__create_db::get_id()const
{
 return m_testID.c_str();
}//get_id

//------------------------------------------------------------------------
bool TestsFor__P13_Srp_002__create_db::can_exec()const
{
 return m_spParams->calc_expression("SRV>=FB-3");
}//can_exec

//------------------------------------------------------------------------
void TestsFor__P13_Srp_002__create_db::run(context_type* const pCtx)const
{
 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"inet://[%1]/%2%3");

 dbLocation
  <<m_spParams->args().get(c_prog_arg__inet_host)->m_value
  <<m_spParams->args().get(c_prog_arg__new_db_dir)->m_value
  <<TSO_GenerateNewDatabaseFileName();

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(m_spParams);

 params.set_dbprop_init__location(dbLocation.str());

 params.set_dbprop_init__user_id(L"SYSDBA");

 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__13);

 params.set_dbprop_init__remote__auth(m_srpName);

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
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   =svc::RemoteFB_Connector__CreateDatabase
     (tracer,
      params,
      cns);

 svc::RemoteFB_Connector__DropDatabase
  (tracer,
   spConnector);
}//run

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
