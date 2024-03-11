////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_blob_writer_buf.h
//! \brief   Класс для буферизированной записи данных в BLOB
//! \author  Kovalenko Dmitry
//! \date    28.05.2004
#ifndef _db_blob_writer_buf_H_
#define _db_blob_writer_buf_H_

#include "source/db_obj/db_seq_stream_writer.h"
#include <structure/stream/t_ostream_buffer.h>

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

class t_db_blob_writer_buf;

////////////////////////////////////////////////////////////////////////////////
//class t_db_blob_writer_buf

/// <summary>
///  Класс для буферизированной записи данных в BLOB
/// </summary>
class t_db_blob_writer_buf LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_basic_ostream_buffer<char>
{
 private:
  using self_type=t_db_blob_writer_buf;
  using inherited=structure::t_basic_ostream_buffer<char>;

  t_db_blob_writer_buf(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using char_type=value_type;

 public:
  t_db_blob_writer_buf(t_db_operation_context* pOpCtx,
                       char*                   buffer,
                       size_type               sz,
                       t_db_seq_stream_writer* writer);

  virtual ~t_db_blob_writer_buf();

 private:
  virtual void overflow() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL; //throw

 private:
  t_db_operation_context*    const m_pOpCtx;
  t_db_seq_stream_writer_ptr const m_blob_writer;

 private:
  char* const m_buffer;

 #ifndef NDEBUG
  size_type const m_buffer_sz;
 #endif
};//class t_db_blob_writer_buf

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
