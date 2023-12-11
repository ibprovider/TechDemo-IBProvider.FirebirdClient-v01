////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__initialize_compressor.h
//! \brief   Утилиты подключения. Инициализация компрессора подключения.
//! \author  Kovalenko Dmitry
//! \date    07.01.2020
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__initialize_compressor.h"

#include "source/db_client/remote_fb/ports/streams/compressor/zlib1/remote_fb__ports__streams__compressor_zlib1.h"

#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"

#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include "source/external/zlib1/dll/ibp_external__zlib1_dll__api_provider.h"
#include "source/external/zlib1/builtin/ibp_external__zlib1_builtin__api_provider.h"

#include "source/ibp_global_objects_data__dlls.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__InitializeCompressor

const t_ibp_str_box
 RemoteFB__P13__InitializeCompressor::c_default__ZLIB1_DLL
  (IBP_T("zlib1.dll"));

//------------------------------------------------------------------------
void RemoteFB__P13__InitializeCompressor::exec
                                           (port_type*             const           pPort,
                                            const RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 assert(pPort);
 assert(pPort->m_spSocket);
 assert(pPort->m_spSocket->GetStreamClass()==RemoteFB__PortStream::stream_class__transport);

 //-----------------------------------------
 const ZLIB1__ApiProviderPtr
  spZProvider
   (self_type::helper__create_zprovider
     (clientConnectBlock));

 assert(spZProvider);

 //-----------------------------------------
 RemoteFB__PortStreamPtr
  spCompressor
   (ports::streams::compressor::zlib1::RemoteFB__PortStream__Compressor_ZLib1::Create
     (spZProvider,
      pPort->m_spSocket,
      pPort->m_spSocket->GetWriteBufSize()));

 assert(spCompressor);

 pPort->m_spSocket.swap(spCompressor);
}//exec

//helper methods ---------------------------------------------------------
ZLIB1__ApiProviderPtr
 RemoteFB__P13__InitializeCompressor::helper__create_zprovider
                                           (const RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 ole_lib::TVariant varPropValue__compressorType;

 if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_TYPE,nullptr,&varPropValue__compressorType))
 {
  return self_type::helper__create_zprovider__builtin();
 }//if

 assert(varPropValue__compressorType.vt==VT_BSTR);

 const auto
  strPropValue__compressorType=ole_lib::BStrToBox(varPropValue__compressorType.bstrVal);

 //-----------------------------------------
 if(structure::equal_to_string(strPropValue__compressorType,ibprovider::ibp_propval__remote__wire_compression_type__zlib1_builtin))
 {
  return self_type::helper__create_zprovider__builtin();
 }//if zlib1.builtin

 //-----------------------------------------
 if(structure::equal_to_string(strPropValue__compressorType,ibprovider::ibp_propval__remote__wire_compression_type__zlib1_dll))
 {
  return self_type::helper__create_zprovider__dll(clientConnectBlock);
 }//if zlib1.dll

 //-----------------------------------------
 RemoteFB__ErrorUtils::Throw__UnsupportedWireCompressionType
  (ibp_subsystem__remote_fb__p13,
   strPropValue__compressorType);
}//helper__create_zprovider

//------------------------------------------------------------------------
ZLIB1__ApiProviderPtr
 RemoteFB__P13__InitializeCompressor::helper__create_zprovider__builtin
                                           ()
{
 return ibp::external::zlib1::builtin::ZLIB1_BUILTIN__ApiProvider::create();
}//helper__create_zprovider__builtin

//------------------------------------------------------------------------
ZLIB1__ApiProviderPtr
 RemoteFB__P13__InitializeCompressor::helper__create_zprovider__dll
                                           (const RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 ole_lib::TVariant varPropValue__ZLibrary;

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)
 /// В случае 64-битной сборки, значение свойства "xxx_library_64" является приоритетным.
 if(clientConnectBlock.m_spDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY_64,nullptr,&varPropValue__ZLibrary))
 {
  /*OK*/

  assert(varPropValue__ZLibrary.vt==VT_BSTR);
 
  return self_type::helper__create_zprovider__dll(ole_lib::BStrToBox(varPropValue__ZLibrary.bstrVal));
 }//if
#elif(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)
#else
# error Unknown IBP_PLATFORM_ID!
#endif
 if(clientConnectBlock.m_spDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY,nullptr,&varPropValue__ZLibrary))
 {
  /*OK*/

  assert(varPropValue__ZLibrary.vt==VT_BSTR);

  return self_type::helper__create_zprovider__dll(ole_lib::BStrToBox(varPropValue__ZLibrary.bstrVal));
 }//if

 //zlib1 library is not defined
 return self_type::helper__create_zprovider__dll(self_type::c_default__ZLIB1_DLL);
}//helper__create_zprovider__dll

//------------------------------------------------------------------------
ZLIB1__ApiProviderPtr
 RemoteFB__P13__InitializeCompressor::helper__create_zprovider__dll
                                           (t_ibp_str_box const DLL_Name)
{
 using ZLIB1_DLL__ApiProvider
  =ibp::external::zlib1::dll::ZLIB1_DLL__ApiProvider;

 const ZLIB1_DLL__ApiProvider::dll_ptr
  spDll
   (IBP_GlobalObjectsData__DLLs::GetDLL
     (DLL_Name,
      ibprovider::ibp_propval_dll_lock_rule__force_unload)); //throw

 assert(spDll);

 //-----------------------------------------
 return ZLIB1_DLL__ApiProvider::create(spDll);
}//helper__create_zprovider__dll

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
