////////////////////////////////////////////////////////////////////////////////
#ifndef _t_base64_mime__block_decoder_CC_
#define _t_base64_mime__block_decoder_CC_

#include <structure/t_numeric_cast.h>
#include <structure/t_negative_one.h>

namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//class t_base64_mime__block_decoder

template<typename charT>
t_base64_mime__block_decoder<charT>::t_base64_mime__block_decoder()
 :m_nAlignChars(0)
{
 this->reset_bytes();
}//tag_decoder

//interface --------------------------------------------------------------
template<typename charT>
RELEASE_CODE(inline)
bool t_base64_mime__block_decoder<charT>::complete()const
{
 return m_nMimeChars==0 || m_nMimeChars==4;
}//complete

//------------------------------------------------------------------------
template<typename charT>
typename t_base64_mime__block_decoder<charT>::size_type
 t_base64_mime__block_decoder<charT>::result_size()const
{
 assert(this->complete());

 if(!this->complete())
  return 0;

 if(m_nMimeChars==0)
  return 0;

 assert(m_nMimeChars==4);
 assert(m_nAlignChars<=2);

 assert(_DIM_(m_Bytes)==3);

 return 3-m_nAlignChars;
}//result_size

//------------------------------------------------------------------------
template<typename charT>
typename t_base64_mime__block_decoder<charT>::byte_type
 t_base64_mime__block_decoder<charT>::result_byte(size_type const i)const
{
 assert_msg(i<this->result_size(),"i="<<i<<". result_size="<<this->result_size());

 assert(i<_DIM_(m_Bytes));

 return m_Bytes[i];
}//result_byte

//------------------------------------------------------------------------
template<typename charT>
bool t_base64_mime__block_decoder<charT>::push(char_type const ch)
{
 assert(m_nMimeChars<=4);

 if(m_nAlignChars!=0)
 {
  assert(m_nAlignChars<=2);

  if(m_nMimeChars==4)
   return false;

  if(ch!=char_traits2::ch_equal())
   return false;

  ++m_nAlignChars;
  ++m_nMimeChars;

  return true;
 }//if m_nAlignChars!=0

 assert(m_nAlignChars==0);

 if(m_nMimeChars==4)
 {
  this->reset_bytes();
 }
 
 //----------------------------------------- 0
 switch(m_nMimeChars)
 {
  case 0:
  {
   const decode_ch_result_type x(this->decode_ch(ch));

   if(!x.second)
    return false;

   assert(x.first<64);

   //----
   assert(m_Bytes[0]==0);

   m_Bytes[0]=(x.first<<2);

   //----
   ++m_nMimeChars;

   return true;
  }//case 0

  case 1:
  {
   const decode_ch_result_type x(this->decode_ch(ch));

   if(!x.second)
    return false;

   assert(x.first<64);

   //----
   assert((m_Bytes[1]&byte_type(0x03))==0);

   m_Bytes[0]=(m_Bytes[0]|(x.first>>4));

   //----
   assert(m_Bytes[1]==0);

   m_Bytes[1]=((x.first&byte_type(0x0F))<<4);

   //----
   ++m_nMimeChars;

   return true;
  }//case 1
  
  case 2:
  {
   if(ch==char_traits2::ch_equal())
   {
    if(m_Bytes[1]!=0)
     return false;

    ++m_nAlignChars;
    ++m_nMimeChars;

    return true;
   }//if is align char

   const decode_ch_result_type x(this->decode_ch(ch));

   if(!x.second)
    return false;

   assert(x.first<64);

   //----
   assert((m_Bytes[1]&byte_type(0x0F))==0);

   m_Bytes[1]=(m_Bytes[1]|(x.first>>2));

   //----
   assert(m_Bytes[2]==0);

   m_Bytes[2]=(x.first&byte_type(0x03))<<6;

   //----
   ++m_nMimeChars;

   return true;
  }//case 2

  case 3:
  {
   if(ch==char_traits2::ch_equal())
   {
    if(m_Bytes[2]!=0)
     return false;

    ++m_nAlignChars;
    ++m_nMimeChars;

    return true;
   }//if is align char

   const decode_ch_result_type x(this->decode_ch(ch));

   if(!x.second)
    return false;

   assert(x.first<64);

   //----
   assert((m_Bytes[2]&byte_type(0x3F))==0);

   m_Bytes[2]=(m_Bytes[2]|x.first);

   //----
   ++m_nMimeChars;

   return true;
  }//case 3
 }//switch m_nMimeChars

 assert(false);

 return false;
}//push

//------------------------------------------------------------------------
template<typename charT>
RELEASE_CODE(inline)
void t_base64_mime__block_decoder<charT>::reset_bytes()
{
 assert(_DIM_(m_Bytes)==3);

 m_nMimeChars=0;
 
 m_Bytes[0]=0;
 m_Bytes[1]=0;
 m_Bytes[2]=0;
}//reset_bytes

//------------------------------------------------------------------------
template<typename charT>
typename t_base64_mime__block_decoder<charT>::decode_ch_result_type
 t_base64_mime__block_decoder<charT>::decode_ch(char_type const base64_ch)
{
 assert(char_traits2::ch_letter_A()<char_traits2::ch_letter_Z());
 assert(char_traits2::ch_letter_a()<char_traits2::ch_letter_z());
 assert(char_traits2::ch_0()<char_traits2::ch_9());

 assert(char_traits2::ch_letter_Z()-char_traits2::ch_letter_A()==25);
 assert(char_traits2::ch_letter_z()-char_traits2::ch_letter_a()==25);
 assert(char_traits2::ch_9()-char_traits2::ch_0()==9);

 if(base64_ch>=char_traits2::ch_letter_A() && base64_ch<=char_traits2::ch_letter_Z())
 {
  const char_type start_ch=char_traits2::ch_letter_A();

  assert(structure::can_numeric_cast<byte_type>(base64_ch-start_ch));
  
  return decode_ch_result_type(static_cast<byte_type>(base64_ch-start_ch),true);
 }//if A..Z

 if(base64_ch>=char_traits2::ch_letter_a() && base64_ch<=char_traits2::ch_letter_z())
 {
  const char_type start_ch=char_traits2::ch_letter_a();

  assert(structure::can_numeric_cast<byte_type>(26+(base64_ch-start_ch)));

  return decode_ch_result_type(static_cast<byte_type>(26+(base64_ch-start_ch)),true);
 }//if a..z

 if(base64_ch>=char_traits2::ch_0() && base64_ch<=char_traits2::ch_9())
 {
  const char_type start_ch=char_traits2::ch_0();

  assert(structure::can_numeric_cast<byte_type>(52+(base64_ch-start_ch)));

  return decode_ch_result_type(static_cast<byte_type>(52+(base64_ch-start_ch)),true);
 }//if 0..9

 if(base64_ch==char_traits2::ch_plus())
 {
  return decode_ch_result_type(static_cast<byte_type>(62),true);
 }//if '+'

 if(base64_ch==char_traits2::ch_div())
 {
  return decode_ch_result_type(static_cast<byte_type>(63),true);
 }//if '/'
 
 //unexpected MIME-symbol
 return decode_ch_result_type(structure::t_negative_one(),false);
}//decode_ch

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms structure*/
#endif
