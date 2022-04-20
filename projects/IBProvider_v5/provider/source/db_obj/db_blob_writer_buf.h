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
//containings

class t_db_blob_writer_buf;

////////////////////////////////////////////////////////////////////////////////
//class t_db_blob_writer_buf

/// <summary>
///  Класс для буферизированной записи данных в BLOB
/// </summary>
class t_db_blob_writer_buf:public structure::t_basic_ostream_buffer<char>
{
 private:
  typedef t_db_blob_writer_buf                            self_type;
  typedef structure::t_basic_ostream_buffer<char>         inherited;

  t_db_blob_writer_buf(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef value_type                                      char_type;

 public:
  t_db_blob_writer_buf(char*                   const buffer,
                       size_type               const sz,
                       t_db_seq_stream_writer* const writer);

  virtual ~t_db_blob_writer_buf();

 private:
  virtual void overflow() COMP_W000004_OVERRIDE_FINAL; //throw

 private:
  char* const m_buffer;

 #ifndef NDEBUG
  size_type const m_buffer_sz;
 #endif

  const t_db_seq_stream_writer_ptr m_blob_writer;
};//class t_db_blob_writer_buf

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
