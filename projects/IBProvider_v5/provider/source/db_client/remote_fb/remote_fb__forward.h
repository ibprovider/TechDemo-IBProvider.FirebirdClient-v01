////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__forward.h
//! \brief   Forward-определения конструкций.
//! \author  Kovalenko Dmitry
//! \date    16.02.2015.
#ifndef _remote_fb__forward_H_
#define _remote_fb__forward_H_

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////

class RemoteFB__ClientConnectBlock_v1;
class RemoteFB__ClientConnectBlock_v2;

class RemoteFB__KnownServerKey;
class RemoteFB__InternalCryptKey;

class RemoteFB__CryptKeyDataView;

class RemoteFB__Connector;
class RemoteFB__ConnectorData;

class RemoteFB__Port;

class RemoteFB__MsgDataElementDescr;

namespace handles{
////////////////////////////////////////////////////////////////////////////////

class RemoteFB__HandleData_Transaction;
class RemoteFB__HandleData_Statement;
class RemoteFB__HandleData_Blob;

////////////////////////////////////////////////////////////////////////////////
}//namespace handles

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
