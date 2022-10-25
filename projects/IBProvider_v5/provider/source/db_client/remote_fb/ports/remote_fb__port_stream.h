////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__port_stream.h
//! \brief   ��������� �����/������ ������ �����.
//! \author  Kovalenko Dmitry
//! \date    16.08.2016
#ifndef _remote_fb__port_stream_H_
#define _remote_fb__port_stream_H_

#include "source/db_client/remote_fb/remote_fb__memory.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortStream

/// <summary>
///  ��������� �����/������ ������ �����.
/// </summary>
class RemoteFB__PortStream:public RemoteFB__SmartInterface
{
 public:
  /// <summary>
  ///  ������������ ��������� ������� ����� ������
  /// </summary>
  enum tag_stream_class
  {
   /// ������������ �����
   stream_class__transport   =1,

   /// ����� ���������� ������
   stream_class__crypt       =2,

   /// ����� �����������
   stream_class__compressor  =3,
  };//enum tag_stream_class

 public:
  /// <summary>
  ///  ��������� �������������� ��������� ������
  /// </summary>
  virtual tag_stream_class GetStreamClass()const=0;

  /// <summary>
  ///  ��������� ��������� �� ������������ �����.
  /// </summary>
  //! \return
  //!  Can be null.
  virtual RemoteFB__PortStream* GetParentStream()const=0;

  /// <summary>
  ///  ������ ������������� ������.
  /// </summary>
  //! \param[in] pParentStream
  //!  Not null.
  virtual void SetParentStream(RemoteFB__PortStream* pParentStream)=0;

  /// <summary>
  ///  ��������� ������� ������ ��� ������.
  /// </summary>
  virtual size_t GetWriteBufSize()const=0;

  /// <summary>
  ///  ���������������� ������ ������ � ����. THROW.
  /// </summary>
  //! \param[in] cb
  //!  ���������� ����
  //! \param[in] pv
  //!  ��������� �� ����� � ������������� �������
  virtual void Write(size_t      cb,
                     const void* pv)=0;

  /// <summary>
  ///  ����� write-������
  /// </summary>
  virtual void FlushWriteBuf()=0;

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
                       void*   pv)=0;
};//class RemoteFB__PortStream

////////////////////////////////////////////////////////////////////////////////

typedef lib::structure::t_smart_object_ptr<RemoteFB__PortStream> RemoteFB__PortStreamPtr;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif