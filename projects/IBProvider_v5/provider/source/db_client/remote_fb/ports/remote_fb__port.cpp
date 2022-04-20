////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__port.cpp
//! \brief   Конструкции для работы с удаленным портом.
//! \author  Kovalenko Dmitry
//! \date    30.10.2014
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/remote_fb__port.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortWriter

const GUID RemoteFB__PortWriter::svcID
 ={0x67FB9FB3,0x14CD,0x489D,{0x90,0x3B,0x5A,0x82,0x1E,0x74,0x30,0xDA}};

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortReader

const GUID RemoteFB__PortReader::svcID
 ={0x26163A68,0x4C4D,0x4DD9,{0xB8,0xA7,0x19,0xC2,0x5A,0xBB,0x70,0x08}};

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port

bool RemoteFB__Port::TestPortFlag__symmetric()const
{
 return (this->get_port_flags()&self_type::PortFlag__symmetric)==self_type::PortFlag__symmetric;
}//TestPortFlag__symmetric

//------------------------------------------------------------------------
bool RemoteFB__Port::TestPortFlag__rpc()const
{
 return (this->get_port_flags()&self_type::PortFlag__rpc)==self_type::PortFlag__rpc;
}//TestPortFlag__rpc

//------------------------------------------------------------------------
bool RemoteFB__Port::TestPortFlag__lazy()const
{
 return (this->get_port_flags()&self_type::PortFlag__lazy)==self_type::PortFlag__lazy;
}//TestPortFlag__lazy

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortWriteGuard

RemoteFB__PortWriteGuard::RemoteFB__PortWriteGuard(RemoteFB__PortOperationContext& op_ctx)
 :m_spWriter(RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx))
{
 assert(m_spWriter!=nullptr);

 m_spWriter->begin_write(); //throw
}//RemoteFB__PortWriteGuard

//------------------------------------------------------------------------
RemoteFB__PortWriteGuard::~RemoteFB__PortWriteGuard()
{
 RemoteFB__PortWriterPtr p;

 m_spWriter.swap(p);

 if(p!=nullptr)
  p->end_write(/*success*/false);
}//~RemoteFB__PortWriteGuard

//------------------------------------------------------------------------
const RemoteFB__PortWriterPtr& RemoteFB__PortWriteGuard::writer()const
{
 return m_spWriter;
}//writer

//------------------------------------------------------------------------
void RemoteFB__PortWriteGuard::complete()
{
 assert(m_spWriter!=nullptr);

 m_spWriter->end_write(/*success*/true); //throw

 /*OK*/

 m_spWriter.Release();
}//complete

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortReadGuard

RemoteFB__PortReadGuard::RemoteFB__PortReadGuard(RemoteFB__PortOperationContext& op_ctx)
 :m_spReader(RemoteFB__GetService<RemoteFB__PortReader>(op_ctx))
{
 assert(m_spReader!=nullptr);

 m_spReader->begin_read(); //throw
}//RemoteFB__PortReadGuard

//------------------------------------------------------------------------
RemoteFB__PortReadGuard::~RemoteFB__PortReadGuard()
{
 RemoteFB__PortReaderPtr p;

 m_spReader.swap(p);

 if(p!=nullptr)
  p->end_read(/*success*/false);
}//~RemoteFB__PortReadGuard

//------------------------------------------------------------------------
const RemoteFB__PortReaderPtr& RemoteFB__PortReadGuard::reader()const
{
 return m_spReader;
}//reader

//------------------------------------------------------------------------
void RemoteFB__PortReadGuard::complete()
{
 assert(m_spReader!=nullptr);

 m_spReader->end_read(/*success*/true); //throw

 /*OK*/

 m_spReader.Release();
}//complete

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port

RemoteFB__Port::RemoteFB__Port()
{;}

//------------------------------------------------------------------------
RemoteFB__Port::~RemoteFB__Port()
{;}

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PacketMemory

const GUID RemoteFB__PacketMemory::svcID
 ={0xA85AD606,0x3BEA,0x42B3,{0xA5,0x06,0xC5,0x8D,0xBE,0xCD,0xC5,0xCC}};

////////////////////////////////////////////////////////////////////////////////

void RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(RemoteFB__Port* const pPort)
{
 assert(pPort);

 try
 {
  throw;
 }
 catch(const std::exception& e)
 {
  pPort->set_invalid_port_state_v2(&e);
 }
 catch(...)
 {
  pPort->set_invalid_port_state_v2(nullptr);
 }//catch

 //! \todo
 //!  Есть мысль, в случае первичного перевода порта в заблокированное состояние,
 //!  добавлять к исключению запись "ПОРТ БУДЕТ ПЕРЕВЕДЕН В ЗАБЛОКИРОВАННОЕ СОСТОЯНИЕ".

 throw;
}//RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
