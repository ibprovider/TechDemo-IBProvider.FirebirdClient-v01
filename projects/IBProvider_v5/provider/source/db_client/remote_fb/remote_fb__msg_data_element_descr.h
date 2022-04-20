////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__msg_data_element_descr.h
//! \brief   Описатель элемента MSG-буфера с данными.
//! \author  Kovalenko Dmitry
//! \date    18.05.2015.
#ifndef _remote_fb__msg_data_element_descr_H_
#define _remote_fb__msg_data_element_descr_H_

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__MsgDataElementDescr

/// <summary>
///  Описатель элемента MSG-буфера с данными.
/// </summary>
class RemoteFB__MsgDataElementDescr
{
 public:
  /// Размер блока с данными
  size_t m_msg_value_block_size;

  /// Смещение блока с данными
  size_t m_msg_value_block_offset;

  /// Смещение индикатора состояния данных
  size_t m_msg_sqlind_offset;

  /// BLR-тип элемента данных
  unsigned m_msg_blrtype;

 public:
  /// Идентификатор SQL-типа данных, для которого рассчитан данный блок
  short m_xvar_sqltype;

  /// Масштаб значения
  short m_xvar_sqlscale;

 public:
  /// <summary>
  ///  Конструктор по умолчанию.
  /// </summary>
  RemoteFB__MsgDataElementDescr();
};//class RemoteFB__MsgDataElementDescr

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
