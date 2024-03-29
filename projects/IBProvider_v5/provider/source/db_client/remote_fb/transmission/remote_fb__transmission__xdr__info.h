////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__xdr__info.h
//! \brief   �������������� ������� ��� ������ � ������� �������� ������.
//! \author  Kovalenko Dmitry
//! \date    05.09.2015
#ifndef _remote_fb__transmission__xdr__info_H_
#define _remote_fb__transmission__xdr__info_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__XDR__Info

/// <summary>
///  �������������� ������� ��� ������ � ������� �������� ������.
/// </summary>
class RemoteFB__XDR__Info LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__XDR__Info;

 public:
  static size_t get_size__p_hyper_long();

  static size_t get_size__p_hyper_longlong();

 public:
  static size_t get_size__p_op();

  static size_t get_size__p_arch();

  static size_t get_size__p_objct();

  static size_t get_size__p_short();

  static size_t get_size__p_long();

  static size_t get_size__p_int64();

  static size_t get_size__p_ushort();

  static size_t get_size__p_ushort_as_p_short();

  static size_t get_size__p_ulong_as_p_long();

  static size_t get_size__p_float();

  static size_t get_size__p_double();

  static size_t get_size__p_bid();

  static size_t get_size__opaque(size_t length);

 public:
  static size_t get_size__p_uint64();

  static size_t get_size__p_int128();

  static size_t get_size__p_decfloat16();

  static size_t get_size__p_decfloat34();

 public:
  static size_t get_size__isc_time();

  static size_t get_size__isc_date();

  static size_t get_size__isc_timestamp();

  static size_t get_size__fb040_timezone();

  static size_t get_size__fb040_timestamp_with_tz();

  static size_t get_size__fb040_time_with_tz();
};//class RemoteFB__XDR__Info

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
