////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__inet
//! \file    remote_fb__ports__streams__inet__socket.h
//! \brief   Управляющий объект для сокета TCP/IP-соединения.
//! \author  Kovalenko Dmitry
//! \date    07.11.2014.
#ifndef _remote_fb__ports__streams__inet__socket_H_
#define _remote_fb__ports__streams__inet__socket_H_

#include "source/db_client/remote_fb/ports/remote_fb__port_stream.h"
#include "source/db_client/remote_fb/ports/streams/inet/remote_fb__ports__streams__inet__types.h"
#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/os/win32/winsock/ibp_os_win32_winsock__provider.h"
#include <structure/t_simple_buffer.h>
#include <structure/t_str_parameter.h>
#include <structure/t_const_str_box.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace streams{namespace inet{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__inet
//! @{
////////////////////////////////////////////////////////////////////////////////

namespace winsock=ibp::os::win32::winsock;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__INET_Socket

/// <summary>
///  Управляющий объект для сокета TCP/IP-соединения.
/// </summary>
class RemoteFB__INET_Socket
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__PortStream)
{
 private:
  typedef RemoteFB__INET_Socket                                self_type;

  RemoteFB__INET_Socket(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>             self_ptr;

  typedef RemoteFB__INET_Types                                 inet_types;

  typedef inet_types::port_number_type                         port_number_type;

  typedef structure::t_const_wstr_box                          wstr_box_type;

 public:
  /// Провайдер доступа к Windows Socket API. Not NULL.
  winsock::t_winsock__provider::self_ptr const m_spProvider;

 private:
  typedef unsigned char                                        byte_type;

 private:
  /// <summary>
  ///  Конструктор по-умолчанию.
  /// </summary>
  //! \param[in] pProvider
  //!  Not null.
  //! \param[in] cbReadBuf
  //! \param[in] pReadBuf
  //! \param[in] pWriteBufBeg
  //! \param[in] pWriteBufEnd
  RemoteFB__INET_Socket(winsock::t_winsock__provider* pProvider,
                        size_t                        cbReadBuf,
                        byte_type*                    pReadBuf,
                        void*                         pWriteBufBeg,
                        const void*                   pWriteBufEnd);

  /// <summary>
  ///  Деструктор.
  /// </summary>
  virtual ~RemoteFB__INET_Socket();

  /// <summary>
  ///  Фабрика класса.
  /// </summary>
  //! \param[in] pProvider
  //!  Not null.
  //! \return
  //!  Not null. Сконструированный объект.
  static self_ptr Create(winsock::t_winsock__provider* pProvider);

 public:
  /// <summary>
  ///  Фабрика класса. Версия с поддержкой IPv4 и IPv6.
  /// </summary>
  //! \param[in] pProvider
  //! \param[in] socketFamily
  //!  AF_UNSPEC, AF_INET, AF_INET6
  //! \param[in] ucs2_host
  //!  Строка с идентификатором хоста, к которому необходимо выполнить подключение. Not null.
  //! \param[in] ucs2_port
  //!  Порт подключения. Can be null.
  //! \return
  //!  Not null. Объект с активизированным подключением к удаленному хосту.
  static self_ptr Connect_v2(winsock::t_winsock__provider* pProvider,
                             int                           socketFamily,
                             wstr_box_type                 ucs2_host,
                             wstr_box_type                 ucs2_port);

  /// <summary>
  ///  Создание клона подключения
  /// </summary>
  self_ptr CloneConnection()const;

  //port stream interface ------------------------------------------------

  /// <summary>
  ///  Получение идентификатора категории потока
  /// </summary>
  virtual tag_stream_class GetStreamClass()const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Получение указателя на родительский поток.
  /// </summary>
  //! \return
  //!  Can be null.
  virtual RemoteFB__PortStream* GetParentStream()const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Замена родительского потока.
  /// </summary>
  //! \param[in] pParentStream
  //!  Not null.
  virtual void SetParentStream(RemoteFB__PortStream* pParentStream) COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Получение размера буфера для записи.
  /// </summary>
  virtual size_t GetWriteBufSize()const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Буферизированная запись данных в порт. THROW.
  /// </summary>
  //! \param[in] cb
  //!  Количество байт
  //! \param[in] pv
  //!  Указатель на буфер с отправляемыми данными
  virtual void Write(size_t      cb,
                     const void* pv) COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Сброс write-буфера
  /// </summary>
  virtual void FlushWriteBuf() COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Буферизированное чтение данных из порта. THROW
  /// </summary>
  //! \param[in]  cb
  //!  Размер буфера под данные. Значение должно быть больше нуля.
  //! \param[out] pv
  //!  Указатель на буфер. Not null.
  //! \return
  //!  Количество загруженных данных. Больше нуля, но не больше чем cb.
  virtual size_t Read2(size_t  cb,
                       void*   pv) COMP_W000004_OVERRIDE_FINAL;

 private:
  typedef RemoteFB__MemoryAllocator         raw_allocator_type;

  static void* operator new (size_t const sz); //not impl

  static void* operator new (size_t,void* const pv)
  {//DONE: проверить
   return pv;
  }

 public:
  static void operator delete (void* pv)
  {
   return raw_allocator_type::instance.deallocate(pv,0);
  }

 #if(COMP_CONF_SUPPORT_OPERATOR_DELETE_EX)
  static void operator delete(void* /*pv*/,void* /*pv2*/)
  {
   //memory will be deallocated in catch of self_type::create
  }
 #endif

 private:
  /// <summary>
  ///  Отправка данных в порт. THROW.
  /// </summary>
  //! \param[in] cb
  //!  Количество байт
  //! \param[in] pv
  //!  Указатель на буфер с отправляемыми данными
  void Helper__Socket_Send(size_t      cb,
                           const void* pv);

  /// <summary>
  ///  Чтение данных из порта. THROW
  /// </summary>
  //! \param[in]  cb
  //!  Размер буфера под данные. Значение должно быть больше нуля.
  //! \param[out] pv
  //! \return
  //!  Количество прочитанных байт
  size_t Helper__Socket_Recv(size_t  cb,
                             void*   pv);

 private:
  void Helper__Socket_Init(int socket__family,
                           int socket__type,
                           int socket__protocol);

  void Helper__Socket_Close();

  void Helper__SaveData(wstr_box_type ucs2Host,
                        wstr_box_type ucs2Port,
                        size_t        cbAddress,
                        const void*   pvAddress); //throw

 private:
  static std::string Helper__GetDefaultPortNumberAsString();

 private:
  class tag_addrinfo_sptr;

 private:
  /// Дескриптор подключения к хосту.
  winsock::API::WinSock__SOCKET m_hSocket;

  int m_SocketFamily;
  int m_SocketType;
  int m_SocketProtocol;

 private: //данные для переподключения
  typedef structure::t_void_simple_buffer
   <RemoteFB__MemoryAllocator>              socket_address_type;

  std::wstring m_wstrHost;
  std::wstring m_wstrPort;

  socket_address_type m_SocketAddress;

 private: //read buffer
  byte_type*       const m_read_buf;
  size_t           const m_read_buf_size;
  size_t                 m_read_avail;
  byte_type*             m_read_next;

 private: //write buffer
  byte_type*       const m_write_buf_beg;
  byte_type*             m_write_buf_cur;
  const byte_type* const m_write_buf_end;
};//class RemoteFB__INET_Socket

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms inet*/}/*nms streams*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
