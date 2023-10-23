////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__blr_reader_v1.h
//! \brief   The class for reading a BLR buffer [v1].
//! \author  Kovalenko Dmitry
//! \date    14.04.2023
#ifndef _remote_fb__blr_reader_v1_H_
#define _remote_fb__blr_reader_v1_H_

#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__BlrReader_v1

class RemoteFB__BlrReader_v1 LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__BlrReader_v1;

  RemoteFB__BlrReader_v1(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  RemoteFB__BlrReader_v1(size_t                   const msg_blr_size,
                         const protocol::P_UCHAR* const msg_blr)
   :m_ptr(msg_blr)
   ,m_end(msg_blr+msg_blr_size)
  {
  }

  //interface -------------------------------------------------------------
#ifndef NDEBUG
  bool debug__eof()const
  {
   return m_ptr==m_end;
  }//debug__eof
#endif

  protocol::P_UCHAR cur()const
  {
   if(!(m_ptr<m_end))
    self_type::helper__throw_bug_check__cur__001__eof();

   return *m_ptr;
  }//cur

  protocol::P_UCHAR read()
  {
   if(!(m_ptr<m_end))
    self_type::helper__throw_bug_check__read__001__eof();

   const protocol::P_UCHAR result=*m_ptr;

   ++m_ptr;

   return result;
  }//read

  protocol::P_USHORT read_word()
  {
   protocol::P_USHORT result=this->read();

   result+=protocol::P_USHORT(protocol::P_USHORT(this->read())<<8);

   return result;
  }//read_word

  void next()
  {
   if(!(m_ptr<m_end))
    self_type::helper__throw_bug_check__next__001__eof();

   ++m_ptr;
  }//next

 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_bug_check__cur__001__eof();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_bug_check__read__001__eof();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_bug_check__next__001__eof();

 private:
  const protocol::P_UCHAR*       m_ptr;
  const protocol::P_UCHAR* const m_end;
};//RemoteFB__BlrReader_v1

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
