////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01_writer.h
//! \brief   ���������� ���������� �������� � ����������� ����.
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#ifndef _remote_fb__ports__base_v01_writer_H_
#define _remote_fb__ports__base_v01_writer_H_

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__ports__base_v01
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01::tag_writer

/// <summary>
///  ���������� ���������� �������� � ����������� ����.
/// </summary>
//!  ���������� ������ ��������� �� ����������
class RemoteFB__Port_BASE_v01::tag_writer
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__PortWriter)
{
 private:
  typedef tag_writer                        self_type;

  tag_writer(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  ����������� �������������.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] IsDeferredPacket
  //!  ������� �����, ����������� ���������� �������� �� ������.
  tag_writer(RemoteFB__Port_BASE_v01* pPort,
             bool                     IsDeferredPacket);

  /// <summary>
  ///  ����������
  /// </summary>
 ~tag_writer();

  //writer interface -----------------------------------------------------

 #ifndef NDEBUG
  virtual protocol::P_ARCH debug__get_protocol_architecture()const COMP_W000004_OVERRIDE_FINAL;
 #endif

  /// <summary>
  ///  ����������� � ������ �������� ������.
  /// </summary>
  virtual void begin_write() COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  ����������� �� ��������� �������� ������.
  /// </summary>
  //! \param[in] success
  //!  true, ���� �������� ����������� ��� ������
  virtual void end_write(bool success) COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  ������ ������ � ����� P_LONG.
  /// </summary>
  //! \param[in] pv
  //!  Not null.
  virtual void write__long(const protocol::P_LONG* pv) COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  ������ ������� ����
  /// </summary>
  //! \param[in] n
  //! \param[in] pb
  virtual void write__bytes(size_type                n,
                            const protocol::P_UCHAR* pb) COMP_W000004_OVERRIDE_FINAL;

 private:
  /// <summary>
  ///  ��������� ���������� "������ ����������, ������ ��� ��������� ����������� ������."
  /// </summary>
  COMP_CONF_DECLSPEC_NORETURN
  void helper__throw_error__port_has_failed_state()const;

 private:
  /// ��������� �� ������������� ���� �����������. Not null.
  RemoteFB__Port_BASE_v01::self_ptr m_spPort;

  /// ���������� �� ���������� �������� ������.
  bool m_IsDeferredPacket;
};//class RemoteFB__Port_BASE_v01::tag_writer

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#endif
