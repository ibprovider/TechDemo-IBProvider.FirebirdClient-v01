////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_seq_stream_writer.h
//! \brief   ��������� ������ � ���������������� ����� ����
//! \author  Kovalenko Dmitry
//! \date    25.01.2010
#ifndef _db_seq_stream_writer_H_
#define _db_seq_stream_writer_H_

#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_db_seq_stream_writer

/// <summary>
///  ��������� ��� ������ ������ ����
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_db_seq_stream_writer
 :public t_db_smart_interface
{
 public:
  /// <summary>
  ///  ������ � �����
  /// </summary>
  //! \param[in] BufferSize
  //! \param[in] pBuffer
  virtual void write(size_t      BufferSize,
                     const void* pBuffer)=0;//throw
};//class t_db_seq_stream_writer

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
