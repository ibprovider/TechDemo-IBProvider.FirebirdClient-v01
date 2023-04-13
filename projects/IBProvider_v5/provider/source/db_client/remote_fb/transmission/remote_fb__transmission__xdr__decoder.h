////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__xdr__decoder.h
//! \brief   Утилиты для распаковки данных сетевого пакета.
//! \author  Kovalenko Dmitry
//! \date    23.11.2014.
#ifndef _remote_fb__transmission__xdr__decoder_H_
#define _remote_fb__transmission__xdr__decoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__XDR__Decoder

/// <summary>
///  Финальный трансформатор читаемых данных
/// </summary>
class RemoteFB__XDR__Decoder
{
 private:
  typedef RemoteFB__XDR__Decoder            self_type;

 public: //typedefs ------------------------------------------------------
  typedef RemoteFB__PortReader              buf_type;
  typedef RemoteFB__PacketMemory            mem_type;
  typedef mem_type::enumMemoryID            mem_id_type;

  typedef RemoteFB__ArraySliceDescr         asd_type;

 public:
  static void decode__p_arch
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_ARCH*   pv);

  static void decode__p_objct
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_OBJCT*  pv);

  static void decode__p_short
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_SHORT*  pv);

  static void decode__p_long
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_LONG*   pv);

  static void decode__p_int64
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_INT64*  pv);

  static void decode__p_ushort
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_USHORT* pv);

  static void decode__p_ushort_as_p_short
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_USHORT* pv);

  static void decode__p_ulong_as_p_long
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_ULONG*  pv);

  static void decode__p_float
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_FLOAT*  pv);

  static void decode__p_double
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_DOUBLE* pv);

  static void decode__p_bid
               (buf_type*           pBuf,
                const wchar_t*      pv_sign1__quad_high,
                const wchar_t*      pv_sign2__quad_low,
                protocol::P_BID*    pv);

  static void decode__opaque
               (buf_type*          pBuf,
                const wchar_t*     pv_sign,
                size_t             sz,
                protocol::P_UCHAR* pv);

  /// <summary>
  ///  Загрузка строки
  /// </summary>
  //! \param[in]  pBuf
  //! \param[in]  pMem
  //! \param[in]  memID
  //! \param[in]  pv_sign
  //! \param[in]  maxLength
  //! \param[out] pcchData
  //! \param[out] ppszData
  static void decode__string
               (buf_type*           pBuf,
                mem_type*           pMem,
                mem_id_type         memID,
                const wchar_t*      pv_sign,
                protocol::P_ULONG   maxLength,
                protocol::P_ULONG*  pcchData,
                protocol::P_UCHAR** ppszData);

  /// <summary>
  ///  Загрузка статус-вектора
  /// </summary>
  //! \param[in]  pBuf
  //! \param[in]  pMem
  //! \param[in]  memID
  //! \param[in]  maxSize
  //!  Максимальное количество элементов в векторе. Больше нуля.
  //! \param[in]  pv_sign
  //! \param[out] pv
  static void decode__status_vector__eset02
               (buf_type*                      pBuf,
                mem_type*                      pMem,
                mem_id_type                    memID,
                size_t                         maxSize,
                const wchar_t*                 pv_sign,
                protocol::P_ISC_STATUS_VECTOR* pv);

  /// <summary>
  ///  Unpacking array elements from "network" format.
  /// </summary>
  static void decode__array_slice
               (buf_type*               pBuf,
                const asd_type&         ArrSliceDescr,
                size_t                  szSlice,
                protocol::P_UCHAR*      pSlice);
 private:
  static void helper__read_align_uchars
               (buf_type*      pBuf,
                const wchar_t* pv_sign,
                size_t         cch);

 private:
  /// <summary>
  ///  Генерация исключения - длина статус вектора превышает максимально допустимое значение.
  /// </summary>
  //! \param[in] pv_sign
  //! \param[in] MaxLength
  //! \param[in] check_point
  static void helper__throw_err__status_vector_is_too_long
               (const wchar_t* const pv_sign,
                size_t               MaxLength,
                const wchar_t* const check_point);
};//class RemoteFB__XDR__Decoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
