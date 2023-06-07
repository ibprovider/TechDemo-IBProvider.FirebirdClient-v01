////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__xdr__info.h
//! \brief   Информационные утилиты для работы с данными сетевого пакета.
//! \author  Kovalenko Dmitry
//! \date    05.09.2015
#ifndef _remote_fb__transmission__xdr__info_H_
#define _remote_fb__transmission__xdr__info_H_

#include <structure/t_common.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__XDR__Info

/// <summary>
///  Информационные утилиты для работы с данными сетевого пакета.
/// </summary>
class RemoteFB__XDR__Info
{
 private:
  typedef RemoteFB__XDR__Info             self_type;

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
};//class RemoteFB__XDR__Info

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
