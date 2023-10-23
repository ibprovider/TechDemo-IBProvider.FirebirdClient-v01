////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__crypt_arc4
//! \file    remote_fb__ports__streams__crypt_arc4.cpp
//! \brief   Реализация потока с шифрованием Arc4.
//! \author  Kovalenko Dmitry
//! \date    17.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/streams/crypt/arc4/remote_fb__ports__streams__crypt_arc4.h"
#include "source/db_client/remote_fb/remote_fb__crypt_key_data_view.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace streams{namespace crypt{namespace arc4{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortStream__Crypt_Arc4::tag_cypher

RemoteFB__PortStream__Crypt_Arc4::tag_cypher::tag_cypher(const RemoteFB__CryptKeyDataView& Key)
 :m_s1(0)
 ,m_s2(0)
{
 CHECK_READ_PTR(Key.ptr,Key.size)

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__PortStream__Crypt_Arc4::tag_cypher::tag_cypher";

 if(Key.size==0)
 {
  IBP_BUG_CHECK__DEBUG
   (c_bugcheck_src,
    L"#001",
    me_bug_check__crypt_key_cant_be_empty_0)
 }//if

 assert(Key.size>0);

 //-----------------------------------------
 assert(m_state.size()==256);

 for(size_t n=0;n!=m_state.size();++n)
 {
  assert(structure::can_numeric_cast<byte_type>(n));
  
  m_state[n]=static_cast<byte_type>(n);
 }//for n

 for(size_t k1=0,k2=0;k1!=m_state.size();++k1)
 {
  k2=((k2+reinterpret_cast<const byte_type*>(Key.ptr)[k1%Key.size]+m_state[k1])&0xFF);

  std::swap(m_state[k1],
			m_state[k2]);
 }//for
}//tag_cypher

//------------------------------------------------------------------------
RemoteFB__PortStream__Crypt_Arc4::tag_cypher::~tag_cypher()
{;}

//interface --------------------------------------------------------------
RemoteFB__PortStream__Crypt_Arc4::byte_type
 RemoteFB__PortStream__Crypt_Arc4::tag_cypher::transform(byte_type const x)
{
 m_s2+=m_state[++m_s1];
 
 std::swap(m_state[m_s1],
           m_state[m_s2]);
 
 //! \todo
 //!  Добавить контроль переполнения при сложении?
 const byte_type k=(m_state[this->m_s1]+m_state[m_s2]);
 
 return m_state[k]^x;
}//transform

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortStream__Crypt_Arc4

RemoteFB__PortStream__Crypt_Arc4::RemoteFB__PortStream__Crypt_Arc4
                                           (const RemoteFB__CryptKeyDataView& EncryptKey,
                                            const RemoteFB__CryptKeyDataView& DecryptKey,
                                            void*                 const       pWriteBufBeg,
                                            const void*           const       pWriteBufEnd)
 :m_Encoder(EncryptKey)
 ,m_Decoder(DecryptKey)
 ,m_write_buf_beg(reinterpret_cast<byte_type*>(pWriteBufBeg))
 ,m_write_buf_cur(reinterpret_cast<byte_type*>(pWriteBufBeg))
 ,m_write_buf_end(reinterpret_cast<const byte_type*>(pWriteBufEnd))
{
}//RemoteFB__PortStream__Crypt_Arc4

//------------------------------------------------------------------------
RemoteFB__PortStream__Crypt_Arc4::~RemoteFB__PortStream__Crypt_Arc4()
{
}

//------------------------------------------------------------------------
RemoteFB__PortStreamPtr
 RemoteFB__PortStream__Crypt_Arc4::Create(const RemoteFB__CryptKeyDataView& EncryptKey,
                                          const RemoteFB__CryptKeyDataView& DecryptKey,
                                          size_t                      const cbBuffer)
{
 assert(cbBuffer>0);

 //-----------------------------------------
 size_t total_sz=sizeof(self_type);

 //-----------------------------------------
 const size_t offset_write_buf=total_sz;

 if(!lib::structure::append_memory_size(total_sz,cbBuffer))
  throw std::bad_alloc();

 //-----------------------------------------
 void* const pv=raw_allocator_type::instance.allocate(total_sz);

 assert(pv!=nullptr);

 byte_type* const write_buf =reinterpret_cast<byte_type*>(pv)+offset_write_buf;

 try
 {
  new(pv)self_type(EncryptKey,
                   DecryptKey,
                   write_buf,
                   write_buf+cbBuffer);
 }
 catch(...)
 {
  raw_allocator_type::instance.deallocate(pv,total_sz);

  throw;
 }//catch

 assert(pv);

 return lib::structure::not_null_ptr(reinterpret_cast<self_type*>(pv));
}//Create

//port stream interface --------------------------------------------------
RemoteFB__PortStream__Crypt_Arc4::tag_stream_class
 RemoteFB__PortStream__Crypt_Arc4::GetStreamClass()const
{
 return self_type::stream_class__crypt;
}//GetStreamClass

//------------------------------------------------------------------------
RemoteFB__PortStream__Crypt_Arc4::RemoteFB__PortStream*
 RemoteFB__PortStream__Crypt_Arc4::GetParentStream()const
{
 return m_spParentStream;
}//GetParentStream

//------------------------------------------------------------------------
void RemoteFB__PortStream__Crypt_Arc4::SetParentStream(RemoteFB__PortStream* const pParentStream)
{
 assert(pParentStream);
 assert(pParentStream->GetStreamClass()==RemoteFB__PortStream::stream_class__transport);

 assert(!m_spParentStream);

 m_spParentStream=structure::not_null_ptr(pParentStream);

 assert(m_spParentStream);
}//SetParentStream

//------------------------------------------------------------------------
size_t RemoteFB__PortStream__Crypt_Arc4::GetWriteBufSize()const
{
 assert(m_write_buf_beg<m_write_buf_end);

 return static_cast<size_t>(m_write_buf_end-m_write_buf_beg);
}//GetWriteBufSize

//------------------------------------------------------------------------
void RemoteFB__PortStream__Crypt_Arc4::Write(size_t      const cb,
                                             const void* const pv)
{
 CHECK_READ_PTR(pv,cb);

 assert(m_spParentStream);

 const byte_type* p=reinterpret_cast<const byte_type*>(pv);

 const byte_type* const e=(p+cb);

 for(;;)
 {
  assert(m_write_buf_beg<=m_write_buf_cur);
  assert(m_write_buf_cur<=m_write_buf_end);

  for(;;++p,++m_write_buf_cur)
  {
   if(p==e)
    return;

   if(m_write_buf_cur==m_write_buf_end)
    break;

   (*m_write_buf_cur)=m_Encoder.transform(*p);
  }//for[ever]

  assert(m_write_buf_cur==m_write_buf_end);

  m_spParentStream->Write
   (m_write_buf_end-m_write_buf_beg,
    m_write_buf_beg); //throw

  m_write_buf_cur=m_write_buf_beg;
 }//for[ever]
}//Write

//------------------------------------------------------------------------
void RemoteFB__PortStream__Crypt_Arc4::FlushWriteBuf()
{
 assert(m_write_buf_beg<=m_write_buf_cur);
 assert(m_write_buf_cur<=m_write_buf_end);

 assert(m_spParentStream);

 //1. сброс буферизированных данных
 if(m_write_buf_cur!=m_write_buf_beg)
 {
  m_spParentStream->Write
   (m_write_buf_cur-m_write_buf_beg,
    m_write_buf_beg);

  m_write_buf_cur=m_write_buf_beg;
 }//if

 assert(m_write_buf_cur==m_write_buf_beg);

 //2. сброс буфера на нижнем уровне
 m_spParentStream->FlushWriteBuf(); //throw
}//FlushWriteBuf

//------------------------------------------------------------------------
size_t RemoteFB__PortStream__Crypt_Arc4::Read2(size_t const cb,
                                               void*  const pv)
{
 CHECK_READ_WRITE_PTR(pv,cb);

 assert(m_spParentStream);

 size_t const readed=m_spParentStream->Read2(cb,pv); //throw

 assert(readed>0);
 assert(readed<=cb);

 byte_type* p=reinterpret_cast<byte_type*>(pv);

 const byte_type* const e=(p+readed);

 for(;p!=e;++p)
 {
  (*p)=m_Decoder.transform(*p);
 }//for p

 return readed;
}//Read2

////////////////////////////////////////////////////////////////////////////////
}/*nms arc4*/}/*nms crypt*/}/*nms streams*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
