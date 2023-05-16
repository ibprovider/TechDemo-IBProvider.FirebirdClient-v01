////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__crypt_arc4
//! \file    remote_fb__ports__streams__crypt_arc4.h
//! \brief   ���������� ������ � ����������� Arc4.
//! \author  Kovalenko Dmitry
//! \date    17.08.2016
#ifndef _remote_fb__ports__streams__crypt_arc4_H_
#define _remote_fb__ports__streams__crypt_arc4_H_

#include "source/db_client/remote_fb/ports/remote_fb__port_stream.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include <array>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace streams{namespace crypt{namespace arc4{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__crypt_arc4
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortStream__Crypt_Arc4

/// <summary>
///  ���������� ������ � ����������� Arc4.
/// </summary>
class RemoteFB__PortStream__Crypt_Arc4
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__PortStream)
{
 private:
  typedef RemoteFB__PortStream__Crypt_Arc4  self_type;

  RemoteFB__PortStream__Crypt_Arc4(const self_type&);
  self_type& operator = (const self_type&);

 private: //typedefs -----------------------------------------------------
  typedef unsigned char                     byte_type;

 private:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] EncryptKey
  //! \param[in] DecryptKey
  //! \param[in] pWriteBufBeg
  //! \param[in] pWriteBufEnd
  RemoteFB__PortStream__Crypt_Arc4(const RemoteFB__CryptKeyDataView& EncryptKey,
                                   const RemoteFB__CryptKeyDataView& DecryptKey,
                                   void*                             pWriteBufBeg,
                                   const void*                       pWriteBufEnd);

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~RemoteFB__PortStream__Crypt_Arc4();

 public:
  /// <summary>
  ///  ������� ������
  /// </summary>
  //! \param[in] EncryptKey
  //! \param[in] DecryptKey
  //! \param[in] cbBuffer
  //!  ������ write-������. ��������� ��������.
  //! \return
  //!  Not null.
  //!
  //!  ������������ ������ ����� ��������� � �����������
  //!  ������ � ������� ������ SetParentStream.
  //!
  static RemoteFB__PortStreamPtr Create(const RemoteFB__CryptKeyDataView& EncryptKey,
                                        const RemoteFB__CryptKeyDataView& DecryptKey,
                                        size_t                            cbBuffer);

  //port stream interface ------------------------------------------------

  /// <summary>
  ///  ��������� �������������� ��������� ������
  /// </summary>
  virtual tag_stream_class GetStreamClass()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ��������� ��������� �� ������������ �����.
  /// </summary>
  //! \return
  //!  Can be null.
  virtual RemoteFB__PortStream* GetParentStream()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ������ ������������� ������.
  /// </summary>
  //! \param[in] pParentStream
  //!  Not null.
  virtual void SetParentStream(RemoteFB__PortStream* pParentStream) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ��������� ������� ������ ��� ������.
  /// </summary>
  virtual size_t GetWriteBufSize()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ���������������� ������ ������ � ����. THROW.
  /// </summary>
  //! \param[in] cb
  //!  ���������� ����
  //! \param[in] pv
  //!  ��������� �� ����� � ������������� �������
  virtual void Write(size_t      cb,
                     const void* pv)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ����� write-������
  /// </summary>
  virtual void FlushWriteBuf()LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ���������������� ������ ������ �� �����. THROW
  /// </summary>
  //! \param[in]  cb
  //!  ������ ������ ��� ������. �������� ������ ���� ������ ����.
  //! \param[out] pv
  //!  ��������� �� �����. Not null.
  //! \return
  //!  ���������� ����������� ������. ������ ����, �� �� ������ ��� cb.
  virtual size_t Read2(size_t  cb,
                       void*   pv)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef RemoteFB__MemoryAllocator         raw_allocator_type;

  static void* operator new (size_t const sz); //not impl

  static void* operator new (size_t,void* const pv)
  {
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
  ///  ����� ��� �������������� ������
  /// </summary>
  class tag_cypher
  {
   private:
    typedef tag_cypher                      self_type;

    tag_cypher(const self_type&);
    self_type& operator = (const self_type);

   public:
    /// <summary>
    ///  ����������� �������������
    /// </summary>
    //! \param[in] Key
    tag_cypher(const RemoteFB__CryptKeyDataView& Key);

    /// <summary>
    ///  ����������
    /// </summary>
   ~tag_cypher();

    //interface ----------------------------------------------------------
    byte_type transform(byte_type x);

   private:
    std::array<byte_type,256> m_state;

    byte_type m_s1;
    byte_type m_s2;
  };//class tag_cypher

 private:
  /// ����������� ����� �����-������ ������.
  RemoteFB__PortStreamPtr m_spParentStream;

  tag_cypher m_Encoder;
  tag_cypher m_Decoder;

 private: //write buffer
  byte_type*       const m_write_buf_beg;
  byte_type*             m_write_buf_cur;
  const byte_type* const m_write_buf_end;
};//class RemoteFB__PortStream

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms arc4*/}/*nms crypt*/}/*nms streams*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif