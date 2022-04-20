////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_blob_writer_buf.cpp
//! \brief   Класс для буферизированной записи данных в BLOB
//! \author  Kovalenko Dmitry
//! \date    28.05.2004
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/db_blob_writer_buf.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//class t_db_blob_writer_buf

t_db_blob_writer_buf::t_db_blob_writer_buf(char*                   const buffer,
                                           size_type               const sz,
                                           t_db_seq_stream_writer* const writer)
 :inherited    (buffer,buffer+sz)
 ,m_buffer     (buffer)
 #ifndef NDEBUG
 ,m_buffer_sz  (sz)
 #endif
 ,m_blob_writer(structure::not_null_ptr(writer))
{
 assert_s(sizeof(*buffer)==1);

 assert(this->get_buffer_pos()==m_buffer);
 assert(this->get_buffer_end()==(m_buffer+sz));

 assert(m_blob_writer);
}//t_db_blob_writer_buf

//------------------------------------------------------------------------
t_db_blob_writer_buf::~t_db_blob_writer_buf()
{;}

//------------------------------------------------------------------------
//запись сегмента

void t_db_blob_writer_buf::overflow()
{
 assert_s(sizeof(*m_buffer)==1);
 assert(m_blob_writer);

 assert(this->get_buffer_end()==(m_buffer+m_buffer_sz));

 pointer const ptr=this->get_buffer_pos();

 assert(m_buffer<=ptr);
 assert(ptr<=(m_buffer+m_buffer_sz));

 CHECK_READ_TYPED_PTR(m_buffer,static_cast<size_t>(this->get_buffer_end()-m_buffer));

 //---
 //DONE: Проверить тестовую генерацию исключения
 //t_ibp_error::throw_error("test error",E_FAIL);

 m_blob_writer->write(static_cast<size_t>(ptr-m_buffer),m_buffer); //throw

 //---
 assert(this->get_buffer_end()==(m_buffer+m_buffer_sz));

 this->set_ptrs(m_buffer,this->get_buffer_end());
}//overflow

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
