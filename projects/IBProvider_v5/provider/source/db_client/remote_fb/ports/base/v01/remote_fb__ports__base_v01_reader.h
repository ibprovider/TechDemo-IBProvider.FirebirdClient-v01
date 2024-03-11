////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01_reader.h
//! \brief   ���������� ���������� �������� �� ������������ �����.
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#ifndef _remote_fb__ports__base_v01_reader_H_
#define _remote_fb__ports__base_v01_reader_H_

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__ports__base_v01
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01::tag_reader

/// <summary>
///  ���������� ���������� �������� �� ������������ �����.
/// </summary>
class RemoteFB__Port_BASE_v01::tag_reader LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__PortReader)
{
 private:
  using self_type=tag_reader;

  tag_reader(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  /// <summary>
  ///  ����������� �������������.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  explicit tag_reader(RemoteFB__Port_BASE_v01* pPort);

  /// <summary>
  ///  ����������
  /// </summary>
 ~tag_reader();

  //reader interface -----------------------------------------------------

 #ifndef NDEBUG
  virtual protocol::P_ARCH debug__get_protocol_architecture()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
 #endif

  /// <summary>
  ///  ����������� � ������ �������� ������.
  /// </summary>
  virtual void begin_read() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ����������� �� ��������� �������� ������.
  /// </summary>
  //! \param[in] success
  //!  true, ���� �������� ����������� ��� ������
  virtual void end_read(bool success) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ������ ������ � ����� P_LONG.
  /// </summary>
  //! \param[out] pv
  virtual void read__long(protocol::P_LONG* pv) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ������ ������� ����.
  /// </summary>
  //! \param[in]  n
  //! \param[out] pb
  virtual void read__bytes(size_type          n,
                           protocol::P_UCHAR* pb) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  /// <summary>
  ///  ������ ���������� ���������� ����.
  /// </summary>
  //! \param[in]  cb
  //! \param[out] pv
  void helper__read(size_type cb,
                    void*     pv)const;

  /// <summary>
  ///  ��������� ���������� "������ ����������, ������ ��� ��������� ����������� ������."
  /// </summary>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  void helper__throw_error__port_has_failed_state()const;

 private:
  /// ��������� �� ������������� ���� �����������. Not null.
  RemoteFB__Port_BASE_v01::self_ptr const m_spPort;
};//class RemoteFB__Port_BASE_v01::tag_reader

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#endif
