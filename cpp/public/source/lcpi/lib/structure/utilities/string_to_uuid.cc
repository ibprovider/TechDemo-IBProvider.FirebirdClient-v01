////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 27.09.2022.
#ifndef _cpp_public_lcpi_lib_structure_utilities__string_to_uuid_CC_
#define _cpp_public_lcpi_lib_structure_utilities__string_to_uuid_CC_

#include <lcpi/lib/structure/t_char_traits2.h>
#include <lcpi/lib/structure/debug/assert_s.h>
#include <lcpi/lib/common_utilities.h>

#include <iterator> //std::iterator_traits
#include <type_traits>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class string_to_uuid__impl__random

template<typename Iterator>
class string_to_uuid__impl__random
{
 private:
  typedef string_to_uuid__impl__random                         self_type;

 public:
  typedef unsigned char                                        byte_type;

  typedef typename std::iterator_traits<Iterator>::value_type  char_type;

  typedef structure::t_char_traits2<char_type>                 char_traits2;

  //
  //  123456789012345678901234567890123456
  //  6CB31410-F4E9-4565-83A7-D263FD3FB4F8
  //

  static const size_t c_STR_SIZE=36;

 public:
  static std::pair<Iterator,bool> exec(Iterator  beg,
                                       Iterator  end,
                                       GUID*     pUUID);
 private:
  class tag_parse_hex_result
  {
   public:
    Iterator pos;
    bool     ok;

   public:
    tag_parse_hex_result()=default;

    tag_parse_hex_result(Iterator _pos,bool _ok)
    {
     this->pos = _pos;
     this->ok = _ok;
    }

    operator bool () const
    {
     return this->ok;
    }
  };//class tag_parse_hex_result

 private:
  static tag_parse_hex_result helper__parse_hex
                                   (size_t const nBytes,
                                    Iterator     s,
                                    byte_type*   d);
};//class string_to_uuid__impl__random

////////////////////////////////////////////////////////////////////////////////
//class string_to_uuid__impl__random<Iterator>

template<typename Iterator>
std::pair<Iterator,bool> string_to_uuid__impl__random<Iterator>::exec
                             (Iterator const beg,
                              Iterator const end,
                              GUID*    const pUUID)
{
 LCPI__assert(beg<=end);
 LCPI__assert(pUUID!=nullptr);

 (*pUUID)={};

 if((end-beg)!=self_type::c_STR_SIZE)
  return std::make_pair(beg,false);

 //123456789012345678901234567890123456
 //xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX

 Iterator s=beg;

 //typedef struct _GUID {
 //   unsigned long  Data1;    // 4
 //   unsigned short Data2;    // 2
 //   unsigned short Data3;    // 2
 //   unsigned char  Data4[8]; // 8
 //} GUID;

 tag_parse_hex_result parse_hex_result;

 byte_type data[16];

 byte_type* d=data;

 if(!(parse_hex_result=self_type::helper__parse_hex(4,s,d)))
  return std::make_pair(parse_hex_result.pos,false);

 LCPI__assert(parse_hex_result.pos==(s+8));

 s =parse_hex_result.pos;
 d+=4;

 if((*s)!=L'-')
  return std::make_pair(s,false);

 ++s;

 if(!(parse_hex_result=self_type::helper__parse_hex(2,s,d)))
  return std::make_pair(parse_hex_result.pos,false);

 LCPI__assert(parse_hex_result.pos==(s+4));

 s =parse_hex_result.pos;
 d+=2;

 if((*s)!=L'-')
  return std::make_pair(s,false);

 ++s;

 if(!(parse_hex_result=self_type::helper__parse_hex(2,s,d)))
  return std::make_pair(parse_hex_result.pos,false);

 LCPI__assert(parse_hex_result.pos==(s+4));

 s =parse_hex_result.pos;
 d+=2;

 if((*s)!=L'-')
  return std::make_pair(s,false);

 ++s;

 if(!(parse_hex_result=self_type::helper__parse_hex(2,s,d)))
  return std::make_pair(parse_hex_result.pos,false);

 LCPI__assert(parse_hex_result.pos==(s+4));

 s =parse_hex_result.pos;
 d+=2;

 if((*s)!=L'-')
  return std::make_pair(s,false);

 ++s;

 if(!(parse_hex_result=self_type::helper__parse_hex(6,s,d)))
  return std::make_pair(parse_hex_result.pos,false);

 LCPI__assert(parse_hex_result.pos==(s+12));

 s=parse_hex_result.pos;

 LCPI__assert((s  )==end);
 LCPI__assert((d+6)==_LCPI_END_(data));

 // 0 1 2 3
 //xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX

 typedef unsigned __int16 word_type;
 typedef unsigned __int32 dword_type;

 pUUID->Data1=((dword_type(data[0])<<24)
              +(dword_type(data[1])<<16)
              +(dword_type(data[2])<<8)
              +(dword_type(data[3])));

 pUUID->Data2=word_type((word_type(data[4])<<8)+(word_type(data[5])));

 pUUID->Data3=word_type((word_type(data[6])<<8)+(word_type(data[7])));

 LCPI__assert_s(_LCPI_DIM_(pUUID->Data4)==8);

 pUUID->Data4[0]=data[8];
 pUUID->Data4[1]=data[9];
 pUUID->Data4[2]=data[10];
 pUUID->Data4[3]=data[11];
 pUUID->Data4[4]=data[12];
 pUUID->Data4[5]=data[13];
 pUUID->Data4[6]=data[14];
 pUUID->Data4[7]=data[15];

 return std::make_pair(s,true);
}//exec

//------------------------------------------------------------------------
template<typename Iterator>
typename string_to_uuid__impl__random<Iterator>::tag_parse_hex_result
 string_to_uuid__impl__random<Iterator>::helper__parse_hex
                                           (size_t const nBytes,
                                            Iterator     s,
                                            byte_type*   d)
{
 //CHECK_READ_TYPED_PTR  (s,2*nBytes);
 //CHECK_WRITE_TYPED_PTR (d,nBytes);

 byte_type x[2];

 for(const byte_type* const ed=d+nBytes;d!=ed;++d)
 {
  byte_type*             px=x;
  const byte_type* const ex=_END_(x);

  for(;px!=ex;++px)
  {
   auto const ch=(*s);

   if(ch>=char_traits2::ch_0() && ch<=char_traits2::ch_9())
    (*px)=byte_type(ch-char_traits2::ch_0());
   else
   if(ch>=char_traits2::ch_letter_a() && ch<=char_traits2::ch_letter_f())
    (*px)=byte_type(10+(ch-char_traits2::ch_letter_a()));
   else
   if(ch>=char_traits2::ch_letter_A() && ch<=char_traits2::ch_letter_F())
    (*px)=byte_type(10+(ch-char_traits2::ch_letter_A()));
   else
    return tag_parse_hex_result(s,false);

   ++s;
  }//for px

  (*d)=byte_type((x[0]<<4)+x[1]);
 }//for d

 return tag_parse_hex_result(s,true);
}//helper__parse_hex

////////////////////////////////////////////////////////////////////////////////

template<typename Iterator>
std::pair<Iterator,bool> string_to_uuid__spec(Iterator                        beg,
                                              Iterator                        end,
                                              GUID*                           pUUID,
                                              std::random_access_iterator_tag /*cat*/)
{
 auto r
  =string_to_uuid__impl__random<Iterator>::exec
    (beg,
     end,
     pUUID);

 LCPI__assert(r.first>=beg);
 LCPI__assert(r.first<=end);

#ifndef NDEBUG
 if(r.second)
 {
  LCPI__assert(r.first==end);
 }
 else
 {
  LCPI__assert(r.first<end);
 }
#endif

 return r;
}//string_to_uuid__spec

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////

template<typename Iterator>
std::pair<Iterator,bool> string_to_uuid(Iterator    beg,
                                        Iterator    end,
                                        GUID* const pUUID)
{
 return detail::string_to_uuid__spec
         (beg,
          end,
          pUUID,
          typename std::iterator_traits<Iterator>::iterator_category());
}//string_to_uuid

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif //_cpp_public_lcpi_lib_structure_utilities__string_to_uuid_CC_
