////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_blob_writer.h
//! \brief   ��������� ������ ������ � BLOB ����
//! \author  Kovalenko Dmitry
//! \date    12.07.2003
#ifndef _db_blob_writer_H_
#define _db_blob_writer_H_

#include "source/db_obj/db_seq_stream_writer.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

class t_db_blob_writer;

////////////////////////////////////////////////////////////////////////////////
//class t_db_blob_writer

/// <summary>
///  ��������� ��� ������ ������ ���� � BLOB ����
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE t_db_blob_writer:public t_db_seq_stream_writer
{
 public:
  /// <summary>
  ///  ��������� ������� �������� ������
  /// </summary>
  virtual t_db_charset_const_ptr get_cp()const=0;

  /// <summary>
  ///  ���������� ������
  /// </summary>
  virtual void close_blob()=0;//throw

  /// <summary>
  ///  ������ ������
  /// </summary>
  virtual void cancel_blob()=0;//throw
};//class t_db_blob_writer

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
