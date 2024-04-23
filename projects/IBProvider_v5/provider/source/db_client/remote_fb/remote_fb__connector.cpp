////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector.cpp
//! \brief   Класс управления подключением к FireBird.
//! \author  Kovalenko Dmitry
//! \date    28.10.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__connector.h"
#include "source/db_client/remote_fb/ports/factories/inet/remote_fb__ports__factories__inet.h"

#include "source/db_client/remote_fb/api/p10/remote_fb__p10__get_database_std_info.h"
#include "source/db_client/remote_fb/api/p11/remote_fb__p11__get_database_std_info.h"

#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include "source/db_obj/isc_base/isc_connection_settings.h"

#include "source/oledb/props2/values/datasource/ibp_oledb__props2__values__datasource.h"

#include <win32lib/win32lib.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__Connector::tag_port_factories

struct RemoteFB__Connector::tag_port_factories LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  using PFN_Factory_INET_t
   =RemoteFB__PortPtr (*)
     (int                                                  socketFamily,
      wstr_box_type                                        ucs2_host,
      wstr_box_type                                        ucs2_port,
      wstr_box_type                                        ucs2_database_name,
      oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

 public:
  PFN_Factory_INET_t Factory_INET;
};//class RemoteFB__Connector::tag_port_factories

////////////////////////////////////////////////////////////////////////////////

#define DEF_PORT_FACTORIES(table_name,                                    \
                           INET)                                          \
 const RemoteFB__Connector::tag_port_factories                            \
  RemoteFB__Connector::table_name=                                        \
   {INET}

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

DEF_PORT_FACTORIES
 (sm_port_factories_for_connect_to_db,
  ports::factories::inet::RemoteFB__PortFactory__INET::ConnectToDatabase);

//------------------------------------------------------------------------
DEF_PORT_FACTORIES
 (sm_port_factories_for_create_db,
  ports::factories::inet::RemoteFB__PortFactory__INET::CreateDatabase);

////////////////////////////////////////////////////////////////////////////////

#undef DEF_PORT_FACTORIES

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

RemoteFB__Connector::RemoteFB__Connector(RemoteFB__Port* const pPort)
 :m_Guard()
 ,m_spData(RemoteFB__ConnectorData::Create(pPort))
{
 assert(m_spData);
}//RemoteFB__Connector

//------------------------------------------------------------------------
RemoteFB__Connector::~RemoteFB__Connector()
{
}//~RemoteFB__Connector

//------------------------------------------------------------------------
RemoteFB__Connector::self_ptr
 RemoteFB__Connector::ConnectToDatabase
  (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
   cns_type&                                                  cns)
{
 assert(pDsPropValues);

 return self_type::Helper__Create
         (pDsPropValues,
          cns,
          sm_port_factories_for_connect_to_db);
}//ConnectToDatabase

//------------------------------------------------------------------------
RemoteFB__Connector::self_ptr
 RemoteFB__Connector::CreateDatabase
  (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
   cns_type&                                                  cns)
{
 assert(pDsPropValues);

 return self_type::Helper__Create
         (pDsPropValues,
          cns,
          sm_port_factories_for_create_db);
}//CreateDatabase

//helper methods ---------------------------------------------------------
RemoteFB__Connector::self_ptr
 RemoteFB__Connector::Helper__Create
  (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
   cns_type&                                                  cns,
   const tag_port_factories&                                  Factories)
{
 assert(pDsPropValues);

 const RemoteFB__PortPtr
  spPort
   (self_type::Helper__CreateRemotePort
     (pDsPropValues,
      cns,
      Factories));

 assert(spPort);

 //-----------------------------------------
 self_ptr spConnector
  (lib::structure::not_null_ptr
    (new self_type
      (spPort)));

 assert(spConnector);

 spConnector->Helper__FinalInitialize
  (pDsPropValues,
   cns);

 //-----------------------------------------
 return spConnector;
}//Helper__Create

//------------------------------------------------------------------------
RemoteFB__PortPtr
 RemoteFB__Connector::Helper__CreateRemotePort
  (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
   cns_type&                                                  cns,
   const tag_port_factories&                                  Factories)

{
 assert(pDsPropValues);

 cns.db_location
  =pDsPropValues->GetDatabaseLocation_REQ(ibp_subsystem__remote_fb);

 //-----------------------------------------
 if(RemoteFB__PortPtr x=self_type::Helper__TryCreateRemotePort_INET_v3(cns.db_location,pDsPropValues,Factories))
  return x;

 if(RemoteFB__PortPtr x=self_type::Helper__TryCreateRemotePort_INET_v2(cns.db_location,pDsPropValues,Factories))
  return x;

 //ERROR - unexpected format of string with database connection info

 IBP_ThrowSimpleError
  (E_FAIL,
   ibp_subsystem__remote_fb,
   ibp_mce_remote__cant_detect_type_of_cn_0);

#if(COMP_BUILD_UNUSED_CODE!=0)
 return nullptr;
#endif
}//Helper__CreateRemotePort

//------------------------------------------------------------------------
RemoteFB__PortPtr
 RemoteFB__Connector::Helper__TryCreateRemotePort_INET_v3
  (wstr_box_type                                        const ucs2DbLocation,
   oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
   const tag_port_factories&                                  Factories)
{
 assert(pDsPropValues);
 assert(Factories.Factory_INET!=nullptr);

 std::wstring hostName;
 std::wstring portName;
 std::wstring dbName;

 int socketFamily=0;

 if(ports::factories::inet::RemoteFB__PortFactory__INET::Analyze_v3
                                           (ucs2DbLocation,
                                            &hostName,
                                            &portName,
                                            &dbName))
 {
  socketFamily=ibp::os::win32::winsock::API::WinSock__AF_UNSPEC;
 }
 else
 if(ports::factories::inet::RemoteFB__PortFactory__INET::Analyze_v3__inet4
                                           (ucs2DbLocation,
                                            &hostName,
                                            &portName,
                                            &dbName))
 {
  socketFamily=ibp::os::win32::winsock::API::WinSock__AF_INET;
 }//if - inet4
 else
 if(ports::factories::inet::RemoteFB__PortFactory__INET::Analyze_v3__inet6
                                           (ucs2DbLocation,
                                            &hostName,
                                            &portName,
                                            &dbName))
 {
  socketFamily=ibp::os::win32::winsock::API::WinSock__AF_INET6;
 }//if - inet6
 else
 {
  return nullptr;
 }//else

 RemoteFB__PortPtr
  spPort
   (Factories.Factory_INET
     (socketFamily,
      hostName,
      portName,
      dbName,
      pDsPropValues)); //throw

 assert(spPort);

 return spPort;
}//Helper__TryCreateRemotePort_INET_v3

//------------------------------------------------------------------------
RemoteFB__PortPtr
 RemoteFB__Connector::Helper__TryCreateRemotePort_INET_v2
  (wstr_box_type                                              const ucs2DbLocation,
   oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE*       const pDsPropValues,
   const tag_port_factories&                                        Factories)
{
 assert(pDsPropValues);
 assert(Factories.Factory_INET!=nullptr);

 std::wstring hostName;
 std::wstring portName;
 std::wstring dbName;

 if(ports::factories::inet::RemoteFB__PortFactory__INET::Analyze_v2
                                           (ucs2DbLocation,
                                            &hostName,
                                            &portName,
                                            &dbName))
 {
  RemoteFB__PortPtr
   spPort
    (Factories.Factory_INET
      (ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName,
       portName,
       dbName,
       pDsPropValues)); //throw

  assert(spPort);

  return spPort;
 }//if

 return nullptr;
}//Helper__TryCreateRemotePort_INET_v2

//helper methods ---------------------------------------------------------
void RemoteFB__Connector::Helper__FinalInitialize
      (const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
       cns_type&                                                        cns)
{
 assert(pDsPropValues);
 assert(m_spData);
 assert(m_spData->GetPort());

 //-----------------------------------------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__Connector::Helper__FinalInitialize";

 //-----------------------------------------------------------------------
 switch(protocol::P_PROTOCOL_VERSION const pver=m_spData->GetPort()->get_protocol_version())
 {
  case protocol::FB_PROTOCOL_VERSION10:
  {
   if(m_spData->GetPort()->TestPortFlag__lazy())
   {
    this->Helper__FinalInitialize__P10__lazy_send();
   }
   else
   {
    this->Helper__FinalInitialize__P10__no_lazy();
   }//else

   //---------------------------------------
   api::p10::RemoteFB__P10__GetDatabaseStdInfo::exec(m_spData,cns);

   break;
  }//case v10

  case protocol::FB_PROTOCOL_VERSION11:
  {
   if(m_spData->GetPort()->TestPortFlag__lazy())
   {
    this->Helper__FinalInitialize__P11__lazy_send();
   }
   else
   {
    this->Helper__FinalInitialize__P11__no_lazy();
   }//else

   //---------------------------------------
   api::p11::RemoteFB__P11__GetDatabaseStdInfo::exec(m_spData,cns);

   break;
  }//case v11

  case protocol::FB_PROTOCOL_VERSION12:
  {
   if(m_spData->GetPort()->TestPortFlag__lazy())
   {
    this->Helper__FinalInitialize__P12__lazy_send();
   }
   else
   {
    this->Helper__FinalInitialize__P12__no_lazy();
   }//else

   //---------------------------------------
   api::p11::RemoteFB__P11__GetDatabaseStdInfo::exec(m_spData,cns);

   break;
  }//case v12

  case protocol::FB_PROTOCOL_VERSION13:
  {
   if(m_spData->GetPort()->TestPortFlag__lazy())
   {
    this->Helper__FinalInitialize__P13__lazy_send();
   }
   else
   {
    this->Helper__FinalInitialize__P13__no_lazy();
   }//else

   //---------------------------------------
   api::p11::RemoteFB__P11__GetDatabaseStdInfo::exec(m_spData,cns);

   break;
  }//case v13

  default:
  {
   RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedProtocolVersion
    (c_bugcheck_src,
     L"#001",
     pver);
  }//default
 }//switch

 //----------------------------------------- опознание сервера базы данных.
 assert(!cns.dbms.descr_Ex.null());

 if(cns.dbms.descr_Ex.value().find(isc_base::g_dbms_name_Firebird)!=std::string::npos)
 {
  this->Helper__FinalInitialize__FB
   (pDsPropValues,
    cns);
 }
 else
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb,
    ibp_mce_common__unknown_dbms_1,
    cns.dbms.descr_Ex.value());
 }//else
}//Helper__FinalInitialize

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
