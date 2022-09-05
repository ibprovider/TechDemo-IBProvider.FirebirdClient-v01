////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__inet
//! \file    remote_fb__ports__factories__inet.cpp
//! \brief   Фабрика класса удаленного порта для работы через TCP/IP.
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/factories/inet/remote_fb__ports__factories__inet.h"
#include "source/db_client/remote_fb/ports/streams/inet/remote_fb__ports__streams__inet__static_cfg.h"
#include "source/db_client/remote_fb/ports/base/v01/initializers/pset01/v01/remote_fb__ports__base_v01__initializers__pset01_v01.h"
#include "source/db_client/remote_fb/ports/base/v01/initializers/pset02/v01/remote_fb__ports__base_v01__initializers__pset02_v01.h"
#include "source/db_client/remote_fb/ports/inet/remote_fb__ports__inet.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_utils.h"

#include "source/ibp_global_objects_data__dlls.h"

#include <structure/t_latin.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace factories{namespace inet{
////////////////////////////////////////////////////////////////////////////////

namespace winsock=ibp::os::win32::winsock;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortFactory__INET::tag_init_funcs

struct RemoteFB__PortFactory__INET::tag_init_funcs
{
 public: //typedefs ------------------------------------------------------
  typedef ports::base_v01::RemoteFB__Port_BASE_v01         port_type;

  typedef bool (*init_func_ptr)(port_type*                                           pPort,
                                wstr_box_type                                        ucs2_database_name,
                                oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

 public:
  init_func_ptr PSET01__P10_P11_P12;
  init_func_ptr PSET02__P13;
};//struct RemoteFB__PortFactory__INET::tag_init_funcs

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortFactory__INET

const RemoteFB__PortFactory__INET::tag_init_funcs
 RemoteFB__PortFactory__INET::sm_init_funcs_for_create_db=
{
 /*PSET01__P10_P11_P12*/
 ports::base_v01::initializers::pset01::v01::RemoteFB__PortInitializer_PSET01_v01::TryCreateDatabase,

 /*PSET02__P13*/
 ports::base_v01::initializers::pset02::v01::RemoteFB__PortInitializer_PSET02_v01::TryCreateDatabase,
};//struct sm_init_funcs_for_create_db

//------------------------------------------------------------------------
const RemoteFB__PortFactory__INET::tag_init_funcs
 RemoteFB__PortFactory__INET::sm_init_funcs_for_connect_db=
{
 /*PSET01__P10_P11_P12*/
 ports::base_v01::initializers::pset01::v01::RemoteFB__PortInitializer_PSET01_v01::TryConnectToDatabase,

 /*PSET02__P13*/
 ports::base_v01::initializers::pset02::v01::RemoteFB__PortInitializer_PSET02_v01::TryConnectToDatabase,
};//struct sm_init_funcs_for_connect_db

//------------------------------------------------------------------------
bool RemoteFB__PortFactory__INET::Analyze_v2(wstr_box_type const ucs2DbLocation,
                                             std::wstring* const pUcs2HostName,
                                             std::wstring* const pUcs2PortName,
                                             std::wstring* const pUcs2DatabaseName)
{
 assert(pUcs2HostName!=nullptr);
 assert(pUcs2PortName!=nullptr);
 assert(pUcs2DatabaseName!=nullptr);

 typedef structure::t_char_traits2<wstr_box_type::char_type> _ct2;

 pUcs2HostName->clear();
 pUcs2PortName->clear();
 pUcs2DatabaseName->clear();

 //-----------------------------------------
 if(ucs2DbLocation.empty())
  return false;

 //-----------------------------------------
 //формат:
 // host_name [ '/' port_name ] ':' <database_path>
 //
 // host name ::= name | '[' name ']'

 //-----------------------------------------
 wstr_box_type::iterator const _b=ucs2DbLocation.begin();
 wstr_box_type::iterator const _e=ucs2DbLocation.end();
 wstr_box_type::iterator        p=_b;

 wstr_box_type::iterator pNameBeg=_e;
 wstr_box_type::iterator pNameEnd=_e;

 wstr_box_type::iterator pPortBeg=_e;
 wstr_box_type::iterator pPortEnd=_e;

 if((*p)==L'[')
 {
  //ищем завершающую скобку
  ++p;

  pNameBeg=p;

  p=std::find(p,_e,L']');

  if(p==_e)
   return false;

  pNameEnd=p;

  ++p;

  const wstr_box_type::iterator pSep=std::find(p,_e,L':');

  if(pSep==_e) //не нашли разделитель
   return false;

  p=Helper__SkeepSpace(p,pSep);

  if(p==pSep)
  {
   //порт не указан
  }
  else
  if((*p)==L'/')
  {
   //указан порт подключения
   ++p;

   p=Helper__SkeepSpace(p,pSep);

   if(p==pSep)
   {
    //ERROR - не указан порт подключения

    self_type::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation__NoPort
     (wstr_box_type(pNameBeg,pNameEnd));
   }//if

   pPortBeg=p;

   pPortEnd=pSep;

   for(;;)
   {
    assert(pPortEnd!=pPortBeg);

    const wstr_box_type::iterator x=pPortEnd-1;

    //if(x==pPortBeg)
    // break;

    if(!Helper__IsSpace(*x))
     break;

    pPortEnd=x;
   }//for[ever]

   assert(pPortBeg!=pPortEnd);
  }
  else
  {
   //ERROR - обнаружены неизвестные символы между закрывающей квадратной скобкой и двоеточием.

   self_type::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation();
  }//else

  //пропускаем двоеточие
  p=pSep+1;
 }
 else
 {
  assert(p==_b);

  const wstr_box_type::iterator pSep=std::find(p,_e,L':');

  if(pSep==_e) //не нашли разделитель
   return false;

  if(pSep==_b) //разделитель в начале строки
   return false;

  pNameBeg=p;

  pNameEnd=p=std::find(p,pSep,L'/');

  if(p!=pSep)
  {
   //нашли разделитель указателя порта
   ++p;

   pPortBeg=Helper__SkeepSpace(p,pSep);

   if(pPortBeg==pSep)
   {
    self_type::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation__NoPort
     (wstr_box_type(pNameBeg,pNameEnd));
   }//if

   assert(pPortBeg!=pSep);

   pPortEnd=pSep;

   for(;;)
   {
    assert(pPortEnd!=pPortBeg);

    wstr_box_type::iterator const x=pPortEnd-1;

    //if(x==pPortBeg)
    // break;

    if(!Helper__IsSpace(*x))
     break;

    pPortEnd=x;
   }//for[ever]

   assert(pPortBeg!=pPortEnd);
  }
  else
  {
   //порт не указан

   assert(pNameBeg==_b);
   assert(p==pSep);

   //имя хоста из одной буквы. возможен конфликт с локальным подключением

   if((pNameEnd-pNameBeg)==1)
    return false;
  }//else

  //пропускаем двоеточие
  p=pSep+1;
 }//else

 if(p==_e) //не указано имя базы данных
  return false;

 //-----------------------------------------
 std::wstring tmp__ucs2HostName(pNameBeg,pNameEnd);

 std::wstring tmp__ucs2PortName(pPortBeg,pPortEnd);

 std::wstring tmp__ucs2DatabaseName(p,_e);

 //---- set out
 pUcs2HostName->swap(tmp__ucs2HostName);

 pUcs2PortName->swap(tmp__ucs2PortName);

 pUcs2DatabaseName->swap(tmp__ucs2DatabaseName);

 return true;
}//Analyze_v2

//------------------------------------------------------------------------
const RemoteFB__PortFactory__INET::wstr_box_type::char_type
 RemoteFB__PortFactory__INET::sm_inet_prefix[]=
{
 L'i',L'n',L'e',L't',L':',L'/',L'/'
};//sm_inet_prefix

//------------------------------------------------------------------------
bool RemoteFB__PortFactory__INET::Analyze_v3(wstr_box_type const ucs2DbLocation,
                                             std::wstring* const pUcs2HostName,
                                             std::wstring* const pUcs2PortName,
                                             std::wstring* const pUcs2DatabaseName)
{
 assert(pUcs2HostName!=nullptr);
 assert(pUcs2PortName!=nullptr);
 assert(pUcs2DatabaseName!=nullptr);

 return Helper__Analyze_v3
         (structure::make_str_box(sm_inet_prefix,_DIM_(sm_inet_prefix)),
          ucs2DbLocation,
          pUcs2HostName,
          pUcs2PortName,
          pUcs2DatabaseName);
}//Analyze_v3

//------------------------------------------------------------------------
const RemoteFB__PortFactory__INET::wstr_box_type::char_type
 RemoteFB__PortFactory__INET::sm_inet4_prefix[]=
{
 L'i',L'n',L'e',L't',L'4',L':',L'/',L'/'
};//sm_inet4_prefix

//------------------------------------------------------------------------
bool RemoteFB__PortFactory__INET::Analyze_v3__inet4
                                           (wstr_box_type const ucs2DbLocation,
                                            std::wstring* const pUcs2HostName,
                                            std::wstring* const pUcs2PortName,
                                            std::wstring* const pUcs2DatabaseName)
{
 assert(pUcs2HostName!=nullptr);
 assert(pUcs2PortName!=nullptr);
 assert(pUcs2DatabaseName!=nullptr);

 return Helper__Analyze_v3
         (structure::make_str_box(sm_inet4_prefix,_DIM_(sm_inet4_prefix)),
          ucs2DbLocation,
          pUcs2HostName,
          pUcs2PortName,
          pUcs2DatabaseName);
}//Analyze_v3__inet4

//------------------------------------------------------------------------
const RemoteFB__PortFactory__INET::wstr_box_type::char_type
 RemoteFB__PortFactory__INET::sm_inet6_prefix[]=
{
 L'i',L'n',L'e',L't',L'6',L':',L'/',L'/'
};//sm_inet6_prefix

//------------------------------------------------------------------------
bool RemoteFB__PortFactory__INET::Analyze_v3__inet6
                                           (wstr_box_type const ucs2DbLocation,
                                            std::wstring* const pUcs2HostName,
                                            std::wstring* const pUcs2PortName,
                                            std::wstring* const pUcs2DatabaseName)
{
 assert(pUcs2HostName!=nullptr);
 assert(pUcs2PortName!=nullptr);
 assert(pUcs2DatabaseName!=nullptr);

 return Helper__Analyze_v3
         (structure::make_str_box(sm_inet6_prefix,_DIM_(sm_inet6_prefix)),
          ucs2DbLocation,
          pUcs2HostName,
          pUcs2PortName,
          pUcs2DatabaseName);
}//Analyze_v3__inet6

//------------------------------------------------------------------------
RemoteFB__PortPtr
 RemoteFB__PortFactory__INET::ConnectToDatabase
  (int                                                  const socketFamily,
   wstr_box_type                                        const ucs2_host,
   wstr_box_type                                        const ucs2_port,
   wstr_box_type                                        const ucs2_database_name,
   oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues)
{
 return self_type::Helper__CreateAndInitPort
         (sm_init_funcs_for_connect_db,
          socketFamily,
          ucs2_host,
          ucs2_port,
          ucs2_database_name,
          pDsPropValues);
}//ConnectToDatabase

//------------------------------------------------------------------------
RemoteFB__PortPtr
 RemoteFB__PortFactory__INET::CreateDatabase
  (int                                                  const socketFamily,
   wstr_box_type                                        const ucs2_host,
   wstr_box_type                                        const ucs2_port,
   wstr_box_type                                        const ucs2_database_name,
   oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues)
{
 return self_type::Helper__CreateAndInitPort
         (sm_init_funcs_for_create_db,
          socketFamily,
          ucs2_host,
          ucs2_port,
          ucs2_database_name,
          pDsPropValues);
}//CreateDatabase

//helper methods ---------------------------------------------------------
RemoteFB__PortPtr
 RemoteFB__PortFactory__INET::Helper__CreateAndInitPort
  (const tag_init_funcs& InitFuncs,
   int                                                  const socketFamily,
   wstr_box_type                                        const ucs2_host,
   wstr_box_type                                        const ucs2_port,
   wstr_box_type                                        const ucs2_database_name,
   oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues)
{
 assert(InitFuncs.PSET02__P13);
 assert(InitFuncs.PSET01__P10_P11_P12);

 //-----------------------------------------
 ole_lib::TVariant varCnProp__Protocol;

 if(!pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__PROTOCOL,nullptr,&varCnProp__Protocol))
 {
  ports::streams::inet::RemoteFB__INET_Socket::self_ptr
   spSocket
    (Helper__CreateSocket
      (socketFamily,
       ucs2_host,
       ucs2_port));

  assert(spSocket);

  //----------------------------------------- PSET02 [P13]
  {
   /*const*/ ports::inet::RemoteFB__Port_INET::self_ptr
    spPort(ports::inet::RemoteFB__Port_INET::Create_PSET02(spSocket));

   assert(spPort);

   if(InitFuncs.PSET02__P13
        (spPort,
         ucs2_database_name,
         pDsPropValues))
   {
    assert(spPort);

    return /*move*/spPort;
   }//if
  }//local

  //----------------------------------------- PSET01 [P10, P11, P12]
  {
   spSocket=spSocket->CloneConnection();

   assert(spSocket);

   /*const*/ ports::inet::RemoteFB__Port_INET::self_ptr
    spPort(ports::inet::RemoteFB__Port_INET::Create_PSET01(spSocket));

   assert(spPort);

   if(InitFuncs.PSET01__P10_P11_P12
        (spPort,
         ucs2_database_name,
         pDsPropValues))
   {
    assert(spPort);

    return /*move*/spPort;
   }//if
  }//local
 }
 else
 {
  assert(varCnProp__Protocol.vt==VT_BSTR);

  const auto strCnProp__Protocol
   =ole_lib::BStrToBox(varCnProp__Protocol.bstrVal);

  if(
 #ifdef IBP_BUILD_TESTCODE
     structure::equal_to_string(strCnProp__Protocol,ibprovider::ibp_propval__remote__protocol__set01) ||
 #endif // IBP_BUILD_TESTCODE
     structure::equal_to_string(strCnProp__Protocol,ibprovider::ibp_propval__remote__protocol__10)    ||
     structure::equal_to_string(strCnProp__Protocol,ibprovider::ibp_propval__remote__protocol__11)    ||
     structure::equal_to_string(strCnProp__Protocol,ibprovider::ibp_propval__remote__protocol__12))
  {
   ports::streams::inet::RemoteFB__INET_Socket::self_ptr
    spSocket
     (Helper__CreateSocket
       (socketFamily,
        ucs2_host,
        ucs2_port));

   assert(spSocket);

   /*const*/ ports::inet::RemoteFB__Port_INET::self_ptr
    spPort
     (ports::inet::RemoteFB__Port_INET::Create_PSET01
      (spSocket));

   assert(spPort);

   if(InitFuncs.PSET01__P10_P11_P12
        (spPort,
         ucs2_database_name,
         pDsPropValues))
   {
    assert(spPort);

    return /*move*/spPort;
   }//if
  }
  else
  if(
 #ifdef IBP_BUILD_TESTCODE
     structure::equal_to_string(strCnProp__Protocol,ibprovider::ibp_propval__remote__protocol__set02) ||
 #endif // IBP_BUILD_TESTCODE
     structure::equal_to_string(strCnProp__Protocol,ibprovider::ibp_propval__remote__protocol__13))
  {
   ports::streams::inet::RemoteFB__INET_Socket::self_ptr
    spSocket
     (Helper__CreateSocket
      (socketFamily,
       ucs2_host,
       ucs2_port));

   assert(spSocket);

   /*const*/ ports::inet::RemoteFB__Port_INET::self_ptr
    spPort
     (ports::inet::RemoteFB__Port_INET::Create_PSET02
       (spSocket));

   assert(spPort);

   if(InitFuncs.PSET02__P13
        (spPort,
         ucs2_database_name,
         pDsPropValues))
   {
    assert(spPort);

    return /*move*/spPort;
   }//if
  }
  else
  {
   //ERROR - [BUG CHECK] unknown remote protocol identifier

   RemoteFB__ErrorUtils::Throw__RequestedProtocolNotSupported
    (ibp_subsystem__remote_fb__inet,
     strCnProp__Protocol);
  }//else
 }//else

 //----------------------------------------- ERROR - FAIL. connection has been rejected

 IBP_ThrowSimpleError
  (E_FAIL,
   ibp_subsystem__remote_fb__inet,
   ibp_mce_remote__connect_was_rejected_0);

#if(COMP_BUILD_UNUSED_CODE!=0)
 return nullptr;
#endif
}//Helper__CreateAndInitPort

//------------------------------------------------------------------------
bool RemoteFB__PortFactory__INET::Helper__Analyze_v3
                                           (wstr_box_type const ucs2DbLocationPrefix,
                                            wstr_box_type const ucs2DbLocation,
                                            std::wstring* const pUcs2HostName,
                                            std::wstring* const pUcs2PortName,
                                            std::wstring* const pUcs2DatabaseName)
{
 CHECK_READ_TYPED_PTR(ucs2DbLocationPrefix.ptr,ucs2DbLocationPrefix.len);
 CHECK_READ_TYPED_PTR(ucs2DbLocation.ptr,ucs2DbLocation.len);

 assert(pUcs2HostName!=nullptr);
 assert(pUcs2PortName!=nullptr);
 assert(pUcs2DatabaseName!=nullptr);

 typedef structure::t_char_traits2<wstr_box_type::char_type> _ct2;

 pUcs2HostName->clear();
 pUcs2PortName->clear();
 pUcs2DatabaseName->clear();

 //-----------------------------------------
 //формат:
 // inet:// host_name [ ':' port_name ] '/' <database_path>
 //
 // host name ::= name | '[' name ']'

 //-----------------------------------------
 wstr_box_type::iterator const _b=ucs2DbLocation.begin();
 wstr_box_type::iterator const _e=ucs2DbLocation.end();

 //-----------------------------------------
 if(structure::test_prefix(_b,
                           _e,
                           ucs2DbLocationPrefix.begin(),
                           ucs2DbLocationPrefix.end(),
                           structure::t_latin_equal_i<wstr_box_type::char_type>())!=ucs2DbLocationPrefix.end())
 {
  return false;
 }//if

 assert(ucs2DbLocationPrefix.len<=static_cast<size_t>(_e-_b));

 wstr_box_type::iterator p=_b+ucs2DbLocationPrefix.len;

 wstr_box_type::iterator const pSep=std::find(p,_e,L'/');

 //разделитель не найден
 if(pSep==_e)
  self_type::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation();

 assert(pSep<_e);

 //-----------------------------------------
 wstr_box_type::iterator pNameBeg=_e;
 wstr_box_type::iterator pNameEnd=_e;

 wstr_box_type::iterator pPortBeg=_e;
 wstr_box_type::iterator pPortEnd=_e;

 //-----------------------------------------
 if((*p)==L'[')
 {
  //ищем завершающую скобку
  ++p;

  pNameBeg=p;

  p=std::find(p,_e,L']');

  if(p==_e)
   self_type::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation();

  pNameEnd=p;

  ++p;

  p=Helper__SkeepSpace(p,pSep);

  if(p==pSep)
  {
   //порт не указан
  }
  else
  if((*p)==L':')
  {
   //указан порт подключения
   ++p;

   p=Helper__SkeepSpace(p,pSep);

   if(p==pSep)
   {
    //ERROR - не указан порт подключения

    self_type::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation__NoPort
     (wstr_box_type(pNameBeg,pNameEnd));
   }//if

   pPortBeg=p;

   pPortEnd=pSep;

   for(;;)
   {
    assert(pPortEnd!=pPortBeg);

    const wstr_box_type::iterator x=pPortEnd-1;

    //if(x==pPortBeg)
    // break;

    if(!Helper__IsSpace(*x))
     break;

    pPortEnd=x;
   }//for[ever]

   assert(pPortBeg!=pPortEnd);
  }
  else
  {
   //ERROR - обнаружены неизвестные символы между закрывающей квадратной скобкой и разделителем.

   self_type::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation();
  }//else
 }
 else
 {
  assert((*p)!=L'[');

  pNameBeg=p;

  p=pNameEnd=std::find(p,pSep,L':');

  if(p!=pSep)
  {
   //нашли описание порта подключения

   ++p;

   p=Helper__SkeepSpace(p,pSep);

   if(p==pSep)
   {
    // ERROR - пустое описание порта
    self_type::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation__NoPort
     (wstr_box_type(pNameBeg,pNameEnd));
   }//if

   pPortBeg=p;

   pPortEnd=pSep;

   for(;;)
   {
    assert(pPortEnd!=pPortBeg);

    const wstr_box_type::iterator x=pPortEnd-1;

    //if(x==pPortBeg)
    // break;

    if(!Helper__IsSpace(*x))
     break;

    pPortEnd=x;
   }//for[ever]

   assert(pPortBeg!=pPortEnd);
  }//if p!=pSep - нашли описание порта
 }//else

 //пропускаем разделитель имени хоста и имени базы данных
 p=pSep+1;

 if(p==_e)
  self_type::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation();

 //-----------------------------------------
 std::wstring tmp__ucs2HostName(pNameBeg,pNameEnd);

 std::wstring tmp__ucs2PortName(pPortBeg,pPortEnd);

 std::wstring tmp__ucs2DatabaseName(p,_e);

 //---- set out
 pUcs2HostName->swap(tmp__ucs2HostName);

 pUcs2PortName->swap(tmp__ucs2PortName);

 pUcs2DatabaseName->swap(tmp__ucs2DatabaseName);

 return true;
}//Helper__Analyze_v3

//------------------------------------------------------------------------
bool RemoteFB__PortFactory__INET::Helper__IsSpace(wstr_box_type::char_type ch)
{
 if(ch==L' ')
  return true;

 if(ch==L'\t')
  return true;

 return false;
}//Helper__IsSpace

//------------------------------------------------------------------------
RemoteFB__PortFactory__INET::wstr_box_type::iterator
 RemoteFB__PortFactory__INET::Helper__SkeepSpace(wstr_box_type::iterator i,
                                                 wstr_box_type::iterator e)
{
 for(;i!=e;++i)
 {
  if(Helper__IsSpace(*i))
   continue;

  break;
 }//for i

 return i;
}//Helper__SkeepSpace

//------------------------------------------------------------------------
ports::streams::inet::RemoteFB__INET_Socket::self_ptr
 RemoteFB__PortFactory__INET::Helper__CreateSocket
                                           (int           const socketFamily,
                                            wstr_box_type const ucs2_host,
                                            wstr_box_type const ucs2_port)
{
 const os::t_ibp_os__dll_ptr
  spWinsockDLL
   (IBP_GlobalObjectsData__DLLs::GetDLL
     (ports::streams::inet::RemoteFB__INET_StaticCfg::c_WinSockDllName,
      ibprovider::ibp_propval_dll_lock_rule__force_unload)); //throw

 assert(spWinsockDLL);

 winsock::t_winsock__provider::self_ptr
  spWinsockProvider
   (winsock::t_winsock__provider::create
     (spWinsockDLL)); //throw

 assert(spWinsockProvider);

 //-----------------------------------------
 ports::streams::inet::RemoteFB__INET_Socket::self_ptr
  spSocket
   (ports::streams::inet::RemoteFB__INET_Socket::Connect_v2
     (spWinsockProvider,
      socketFamily,
      ucs2_host,
      ucs2_port)); //throw

 assert(spSocket);

 return spSocket;
}//Helper__CreateSocket

//------------------------------------------------------------------------
void RemoteFB__PortFactory__INET::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation()
{
 //ERROR - некорректный формат строки подключения к базе данных через TCP/IP

 RemoteFB__ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_subsystem__remote_fb__inet,
   ibp_mce_remote__bad_inet_cn_to_db_str_format_0);
}//Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation

//------------------------------------------------------------------------
void RemoteFB__PortFactory__INET::Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation__NoPort
                                           (wstr_box_type const hostName)
{
 RemoteFB__ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_subsystem__remote_fb__inet,
   ibp_mce_remote__bad_inet_cn_to_db_str_format__port_not_defined_1,
   hostName);
}//Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation__NoPort

////////////////////////////////////////////////////////////////////////////////
}/*nms inet*/}/*nms factories*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
