////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__port.h
//! \brief   ����������� ��� ������ � ��������� ������.
//! \author  Kovalenko Dmitry
//! \date    30.10.2014
#ifndef _remote_fb__port_H_
#define _remote_fb__port_H_

#include "source/db_client/remote_fb/remote_fb__srv_resource_id.h"
#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/db_obj/db_service_provider.h"
#include "source/error_services/ibp_error_bug_check.h"
#include <structure/t_value_with_null.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

class RemoteFB__PortWriter;
class RemoteFB__PortWriteGuard;
class RemoteFB__PortReader;
class RemoteFB__PortReadGuard;
class RemoteFB__Port;

class RemoteFB__PortOperationContext;
class RemoteFB__PacketMemory;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortWriter

/// <summary>
///  ��������� �������� � ��������� ����
/// </summary>
///  ������� ����� ������ ������������ � �������� ������� �������� � ������.
class RemoteFB__PortWriter:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

 public:
  /// <summary>
  ///  ������������� �������.
  /// </summary>
  static const GUID svcID;

 public:
 #ifndef NDEBUG
  virtual protocol::P_ARCH debug__get_protocol_architecture()const=0;
 #endif

  /// <summary>
  ///  ����������� � ������ �������� ������
  /// </summary>
  virtual void begin_write()=0;

  /// <summary>
  ///  ����������� �� ��������� �������� ������
  /// </summary>
  //! \param[in] success
  //!  true, ���� �������� ����������� ��� ������
  virtual void end_write(bool success)=0;

  /// <summary>
  ///  ������ ������ � ����� P_LONG
  /// </summary>
  //! \param[in] pv
  //!  Not null.
  virtual void write__long(const protocol::P_LONG* pv)=0;

  /// <summary>
  ///  ������ ������� ����
  /// </summary>
  //! \param[in] n
  //! \param[in] pb
  virtual void write__bytes(size_type                n,
                            const protocol::P_UCHAR* pb)=0;
};//class RemoteFB__PortWriter

/// <summary>
///  ����� ��������� �� ��������� �������� � ��������� ����
/// </summary>
typedef structure::t_smart_object_ptr<RemoteFB__PortWriter> RemoteFB__PortWriterPtr;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortWriteGuard

/// <summary>
///  ����������� �������� ������ � RemoteFB__PortWriter
/// </summary>
class RemoteFB__PortWriteGuard
{
 private:
  typedef RemoteFB__PortWriteGuard          self_type;

  RemoteFB__PortWriteGuard(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] op_ctx
  RemoteFB__PortWriteGuard(RemoteFB__PortOperationContext& op_ctx);

  /// <summary>
  ///  ����������
  /// </summary>
 ~RemoteFB__PortWriteGuard();

  /// <summary>
  ///  ��������� ��������� �� ��������.
  /// </summary>
  const RemoteFB__PortWriterPtr& writer()const;

  /// <summary>
  ///  ���������� �������� � ���������� �������� � ����������� �� ����. THROW.
  /// </summary>
  void complete();

 private:
  /// ��������� �� �������������� �������� � ���� �����������
  RemoteFB__PortWriterPtr m_spWriter;
};//class RemoteFB__PortWriteGuard

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortReader

/// <summary>
///  ��������� �������� �� ���������� �����
/// </summary>
///  ������� ����� ������ ������������ � �������� ������� �������� � ������.
class RemoteFB__PortReader:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

 public:
  /// <summary>
  ///  ������������� �������.
  /// </summary>
  static const GUID svcID;

 public:
 #ifndef NDEBUG
  virtual protocol::P_ARCH debug__get_protocol_architecture()const=0;
 #endif

  /// <summary>
  ///  ����������� � ������ �������� ������
  /// </summary>
  virtual void begin_read()=0;

  /// <summary>
  ///  ����������� �� ��������� �������� ������
  /// </summary>
  //! \param[in] success
  //!  true, ���� �������� ����������� ��� ������
  virtual void end_read(bool success)=0;

  /// <summary>
  ///  ������ ������ � ����� P_LONG
  /// </summary>
  //! \param[out] pv
  //!  Not null.
  virtual void read__long(protocol::P_LONG* pv)=0;

  /// <summary>
  ///  ������ ������� ����
  /// </summary>
  //! \param[in]  n
  //! \param[out] pb
  virtual void read__bytes(size_type          n,
                           protocol::P_UCHAR* pb)=0;
};//class RemoteFB__PortReader

/// <summary>
///  ����� ��������� �� ��������� �������� �� ���������� �����
/// </summary>
typedef structure::t_smart_object_ptr<RemoteFB__PortReader> RemoteFB__PortReaderPtr;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortReadGuard

/// <summary>
///  ����������� �������� ������ �� RemoteFB__PortReader
/// </summary>
class RemoteFB__PortReadGuard
{
 private:
  typedef RemoteFB__PortReadGuard    self_type;

  RemoteFB__PortReadGuard(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] op_ctx
  RemoteFB__PortReadGuard(RemoteFB__PortOperationContext& op_ctx);

  /// <summary>
  ///  ����������
  /// </summary>
 ~RemoteFB__PortReadGuard();

  /// <summary>
  ///  ��������� ��������� �� �������� ����� �����������.
  /// </summary>
  const RemoteFB__PortReaderPtr& reader()const;

  /// <summary>
  ///  ���������� �������� � ���������� �������� � ����������� �� ����. THROW.
  /// </summary>
  void complete();

 private:
  /// ��������� �� �������������� �������� �� ����� �����������
  RemoteFB__PortReaderPtr m_spReader;
};//class RemoteFB__PortReadGuard

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port

/// <summary>
///  ������� ����� ���������� �����
/// </summary>
class RemoteFB__Port
 :public db_obj::t_db_service_provider
 ,public RemoteFB__SmartObjectBase2
{
 private:
  typedef RemoteFB__Port                    self_type;

  RemoteFB__Port(const self_type&);
  self_type& operator = (const self_type&);

 public:
  enum EnumPortFlags
  {
   // Server/client architectures are symmetic
   PortFlag__symmetric      = 0x0001,

   // Protocol is remote procedure call
   PortFlag__rpc            = 0x0002,

   // Port is asynchronous channel for events
   //PortFlag__async        = 0x0004,

   // Don't send out of band data
   PortFlag__no_oob         = 0x0008,

   // Disconnect is in progress
   //PortFlag__disconnect   = 0x0010,

   // A dummy packet interval is set
   PortFlag__dummy_pckt_set = 0x0040,

   // Physical packet doesn't contain all API packet
   PortFlag__partial_data   = 0x0080,

   // Deferred operations are allowed
   PortFlag__lazy           = 0x0100,

   // Server (not client) port
   //PortFlag__server       = 0x0200,

   // op_detach, op_drop_database or op_service_detach was processed
   //PortFlag__detached     = 0x0400,

   // Database is shut down
   //PortFlag__rdb_shutdown = 0x0800,
  };//enum EnumPortFlags

  //! \brief ��� ��� ������������� ������ �����
  typedef unsigned int                      port_flags_type;

 public:
  /// ������������� �����������.
  RemoteFB__SrvResourceID m_ID;

 public:
  /// <summary>
  ///  ����������� ��-���������
  /// </summary>
  RemoteFB__Port();

 protected:
  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~RemoteFB__Port();

 public:
  //smart interface management -------------------------------------------

  SLIB__DECLARE_SMART_OBJ_MANAGEMENT_METHODS__FINAL

 public:
  /// <summary>
  ///  �������� ������ � ����.
  /// </summary>
  //! \param[in] op_ctx
  //! \param[in] packet
  virtual void send_packet(RemoteFB__PortOperationContext& op_ctx,
                           const protocol::PACKET&         packet)=0;

  /// <summary>
  ///  ���������� �������� ������ � ����.
  /// </summary>
  //! \param[in] op_ctx
  //! \param[in] packet
  virtual void send_packet_with_delay(RemoteFB__PortOperationContext& op_ctx,
                                      const protocol::PACKET&         packet)=0;

  /// <summary>
  ///  ������ ������ �� �����.
  /// </summary>
  //! \param[in]  op_ctx
  //! \param[out] packet
  virtual void receive_packet(RemoteFB__PortOperationContext& op_ctx,
                              protocol::PACKET&               packet)=0;

  /// <summary>
  ///  ��������� ����� ����������� �����������.
  /// </summary>
  //! \param[in] pExc
  //!  ��������� �� �������� ������, ������� ������� � ���������� �����. Can be NULL.
  virtual void set_invalid_port_state_v2(const std::exception* pExc)=0;

  /// <summary>
  ///  ������������ ����������������� ��������� �����.
  /// </summary>
  virtual bool port_has_invalid_state()const=0;

  /// <summary>
  ///  ��������� ������ ���������.
  /// </summary>
  virtual protocol::P_PROTOCOL_VERSION get_protocol_version()const=0;

  /// <summary>
  ///  ��������� ������ �����.
  /// </summary>
  virtual port_flags_type get_port_flags()const=0;

 public:
  /// <summary>
  ///  ������������ ������� ����� PortFlag__symmetric
  /// </summary>
  bool TestPortFlag__symmetric()const;

  /// <summary>
  ///  ������������ ������� ����� PortFlag__rpc
  /// </summary>
  bool TestPortFlag__rpc()const;

  /// <summary>
  ///  ������������ ������� ����� PortFlag__lazy
  /// </summary>
  bool TestPortFlag__lazy()const;
};//class RemoteFB__Port

/// <summary>
///  ����� ��������� �� ��������� ���������� �����
/// </summary>
typedef lib::structure::t_smart_object_ptr<RemoteFB__Port> RemoteFB__PortPtr;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortOperationContext

/// <summary>
///  �������� �������� � ������
/// </summary>
class RemoteFB__PortOperationContext
{
 public:
  virtual RemoteFB__SmartObjectPtr query_service(REFGUID serviceID)=0;
};//class RemoteFB__PortOperationContext

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PacketMemory

/// <summary>
///  ��������� ��� ��������� ������ ��� ������ ������
/// </summary>
class RemoteFB__PacketMemory:public RemoteFB__SmartInterface
{
 public:
  /// <summary>
  ///  ������������ ��������������� �����, ��� ������� �������������� ��������� ������.
  /// </summary>
  enum enumMemoryID
  {
   mem_id__p_op_resp__status_vector         =1,

   mem_id__status_vector_string             =2,

   mem_id__p_op_resp__data                  =100,

   mem_id__p_op_trau__data                  =101,

   mem_id__p_op_slice__data                 =102,

   mem_id__p_op_acpd__data                  =103,

   mem_id__p_op_acpd__plugin                =104,

   mem_id__p_op_acpd__keys                  =105,

   mem_id__p_op_auth_cont__data             =106,

   mem_id__p_op_auth_cont__name             =107,

   mem_id__p_op_auth_cont__list             =108,

   mem_id__p_op_auth_cont__keys             =109,
  };//enum enumMemoryID

 public:
  /// <summary>
  ///  ������������� �������.
  /// </summary>
  static const GUID svcID;

 public:
  /// <summary>
  ///  ��������� ������. THROW.
  /// </summary>
  //! \param[in] memID
  //!  ������������� ����, ��� �������� ����� ��������� ������
  //! \param[in] sz
  //!  ������ �����
  //! \return
  //!  ��������� �� ���������� ����.
  virtual void* allocate(enumMemoryID memID,
                         size_t       sz)=0;
};//class RemoteFB__PacketMemory

typedef structure::t_smart_object_ptr<RemoteFB__PacketMemory> RemoteFB__PacketMemoryPtr;

////////////////////////////////////////////////////////////////////////////////

template<class T>
structure::t_smart_object_ptr<T>
 RemoteFB__GetService(RemoteFB__PortOperationContext& op_ctx)
{
 const RemoteFB__SmartObjectPtr spSvc(op_ctx.query_service(T::svcID));

 if(!spSvc)
 {
  //ERROR - ������ �� ��������������

  IBP_ThrowBugCheck_SvcNotSupported
   (ibp_subsystem__remote_fb,
    T::svcID,
    typeid(T).name());
 }//if

 assert(spSvc);

 T* const pTypedSvc=dynamic_cast<T*>(spSvc.ptr());

 if(pTypedSvc==nullptr)
 {
  //ERROR - ������ �� ������������ ��������� ���������

  IBP_ThrowBugCheck_SvcNotImplReqInterface
   (ibp_subsystem__remote_fb,
    T::svcID,
    typeid(T).name());
 }//if

 assert(pTypedSvc);

 return structure::not_null_ptr(pTypedSvc);
}//RemoteFB__GetService

////////////////////////////////////////////////////////////////////////////////

template<typename T>
T* RemoteFB__AllocPacketMemory(RemoteFB__PacketMemory*              const pMem,
                               RemoteFB__PacketMemory::enumMemoryID const memID,
                               size_t                               const n)
{
 assert(pMem!=nullptr);
 assert_s(sizeof(T)>0);

 const size_t c_maxN
  =(structure::t_numeric_limits<size_t>::max_value()/sizeof(T));

 if(c_maxN<n)
  throw std::bad_alloc();

 return reinterpret_cast<T*>(pMem->allocate(memID,n*sizeof(T)));
}//RemoteFB__AllocPacketMemory

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(RemoteFB__Port* pPort);

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
