////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

namespace{
////////////////////////////////////////////////////////////////////////////////
//class tag_text_to_guid

template<typename charT>
class tag_text_to_guid
{
 public:
  typedef tag_text_to_guid                            self_type;

 public:
  typedef unsigned char                               byte_type;

  typedef structure::t_char_traits2<charT>            char_traits2;

 public:
  //
  //  12345678901234567890123456789012345678
  //  {6CB31410-F4E9-4565-83A7-D263FD3FB4F8}
  //

  static const size_t c_STR_SIZE=36+2;

 public:
  static bool exec(const charT* const str,
                   GUID*        const result);
  
 private:
  static bool helper__parse_hex(size_t const nBytes,
                                const charT* s,
                                byte_type*   d);  
};//class tag_text_to_guid

////////////////////////////////////////////////////////////////////////////////

template<typename charT>
bool tag_text_to_guid<charT>::exec(const charT* const str,
                                   GUID*        const result)
{
 assert(str!=nullptr);
 assert(result!=nullptr);

 (*result)=GUID_NULL;

 if(str==nullptr)
  return false;

 const charT* const beg=str;
 const charT* const end=beg+structure::string_length(str);

 if((end-beg)!=self_type::c_STR_SIZE)
  return false;

 //-----------------------------------------------------------------------
 const charT* s=beg;

 if((*s)!=char_traits2::ch_open_fbracket()) // '{'
  return false;

 ++s;

 //123456789012345678901234567890123456
 //xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX

 //typedef struct _GUID {
 //   unsigned long  Data1;    // 4
 //   unsigned short Data2;    // 2
 //   unsigned short Data3;    // 2
 //   unsigned char  Data4[8]; // 8
 //} GUID;

 byte_type data[16];

 byte_type* d=data;

 if(!self_type::helper__parse_hex(4,s,d))
  return false;

 s+=8; d+=4;

 if((*s)!=char_traits2::ch_minus()) // L'-'
  return false;

 ++s;

 if(!self_type::helper__parse_hex(2,s,d))
  return false;

 s+=4; d+=2;

 if((*s)!=char_traits2::ch_minus()) // L'-'
  return false;

 ++s;

 if(!self_type::helper__parse_hex(2,s,d))
  return false;

 s+=4; d+=2;

 if((*s)!=char_traits2::ch_minus()) // L'-'
  return false;

 ++s;

 if(!self_type::helper__parse_hex(2,s,d))
  return false;

 s+=4; d+=2;

 if((*s)!=char_traits2::ch_minus()) // L'-'
  return false;

 ++s;

 if(!self_type::helper__parse_hex(6,s,d))
  return false;

 s+=12;

 assert((s)<end);
 assert((d+6)==_END_(data));

 if((*s)!=char_traits2::ch_close_fbracket()) // '}'
  return false;

 assert((s+1)==end);

 // 0 1 2 3
 //xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX

 typedef unsigned __int16 word_type;
 typedef unsigned __int32 dword_type;

 result->Data1=((dword_type(data[0])<<24)
               +(dword_type(data[1])<<16)
               +(dword_type(data[2])<<8)
               +(dword_type(data[3])));

 result->Data2=word_type((word_type(data[4])<<8)+(word_type(data[5])));

 result->Data3=word_type((word_type(data[6])<<8)+(word_type(data[7])));

 assert_s(_DIM_(result->Data4)==8);

 result->Data4[0]=data[8];
 result->Data4[1]=data[9];
 result->Data4[2]=data[10];
 result->Data4[3]=data[11];
 result->Data4[4]=data[12];
 result->Data4[5]=data[13];
 result->Data4[6]=data[14];
 result->Data4[7]=data[15];

 return true;
}//exec

//------------------------------------------------------------------------
template<typename charT>
bool tag_text_to_guid<charT>::helper__parse_hex(size_t const nBytes,
                                                const charT* s,
                                                byte_type*   d)
{
 CHECK_READ_TYPED_PTR  (s,2*nBytes);
 CHECK_WRITE_TYPED_PTR (d,nBytes);

 byte_type x[2];

 for(const byte_type* const ed=d+nBytes;d!=ed;++d)
 {
  byte_type*             px=x;
  const byte_type* const ex=_END_(x);

  for(;px!=ex;++px)
  {
   if((*s)>=char_traits2::ch_0() && (*s)<=char_traits2::ch_9())
    (*px)=byte_type((*s)-char_traits2::ch_0());
   else
   if((*s)>=char_traits2::ch_letter_a() && (*s)<=char_traits2::ch_letter_f())
    (*px)=byte_type(10+((*s)-char_traits2::ch_letter_a()));
   else
   if((*s)>=char_traits2::ch_letter_A() && (*s)<=char_traits2::ch_letter_F())
    (*px)=byte_type(10+((*s)-char_traits2::ch_letter_A()));
   else
    return false;

   ++s;
  }//for px

  (*d)=byte_type((x[0]<<4)+x[1]);
 }//for d

 return true;
}//helper__parse_hex

////////////////////////////////////////////////////////////////////////////////
}//namespace

////////////////////////////////////////////////////////////////////////////////
//CLSID --> TEXT conversions

#if 0 // [2022-09-22] Temporary removed. They must have a different meaning.

//UNICODE ----------------------------------------------------------------
std::wstring clsid_to_wstring(REFCLSID rclsid)
{
 OLECHAR wsz_guid[128];

 //len will be containing terminate null
 const int len=LCPI_OS__StringFromGUID2(rclsid,wsz_guid,_DIM_(wsz_guid)-1);

 assert(len>0);
 assert(len<_DIM_(wsz_guid));
                               //no terminate null
 return std::wstring(wsz_guid,len-1);
}//clsid_to_wstring

//ANSI -------------------------------------------------------------------
std::string clsid_to_string(REFCLSID rclsid)
{
 OLECHAR wsz_guid[128];

 //len will be containing terminal null
 const int len=LCPI_OS__StringFromGUID2(rclsid,wsz_guid,_DIM_(wsz_guid)-1);

 assert(len>0);
 assert(len<_DIM_(wsz_guid));
                               //no terminate null
 return structure::unicode_to_ansi(wsz_guid,len-1);
}//clsid_to_string

//TSTR -------------------------------------------------------------------
t_string clsid_to_tstr(REFCLSID rclsid)
{
 OLECHAR wsz_guid[128];

 //len will be containing terminal null
 const int len=LCPI_OS__StringFromGUID2(rclsid,wsz_guid,_DIM_(wsz_guid)-1);

 assert(len>0);
 assert(len<_DIM_(wsz_guid));
                               //no terminate null
 return structure::wstr_to_tstr(wsz_guid,len-1);
}//clsid_to_tstr

#endif // if 0

////////////////////////////////////////////////////////////////////////////////
//TEXT --> CLSID conversions

//UNICODE ----------------------------------------------------------------
HRESULT string_to_clsid(structure::wstr_parameter str_clsid,GUID* pclsid)
{
 assert(pclsid!=NULL);

 const wchar_t* const p=str_clsid.c_str();

 if(p==nullptr)
  return E_INVALIDARG;

 if((*p)==0)
  return CO_E_CLASSSTRING;

 if(p[0]==L'{')
 {
  if(tag_text_to_guid<wchar_t>::exec(p,pclsid))
   return S_OK;

  return CO_E_CLASSSTRING;
 }//if

 assert(p[0]!=L'{');

 //second attempt
 return LCPI_OS__CLSIDFromProgID(p,pclsid);
}//string_to_clsid - UNICODE

//ANSI -------------------------------------------------------------------
HRESULT string_to_clsid(const structure::str_parameter str_clsid,GUID* pclsid)
{
 assert(pclsid!=NULL);

 const std::wstring wstr_clsid(structure::ansi_to_unicode(str_clsid.c_str()));

 return string_to_clsid(wstr_clsid,pclsid);
}//string_to_clsid - ANSI

////////////////////////////////////////////////////////////////////////////////
//GUID to TEXT

static const char g_hex_chars_for_guid_to_text[16]
 ={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

//------------------------------------------------------------------------
template<typename TChar>
__STL_DEF_BASIC_STRING(TChar) guid_to_text(REFGUID guid)
{
 //12345678901234567890123456789012345678  38
 //{xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX}

 TChar buffer[38];

 TChar* p=buffer;

#ifndef NDEBUG
 const TChar* const e=_END_(buffer);
#endif

 //-----------------------------------------
#define PUSH_CH(ch)                                                       \
 {                                                                        \
  assert(p!=e);                                                           \
                                                                          \
  (*p)=(ch);                                                              \
                                                                          \
  ++p;                                                                    \
 }

#define PUSH_HEX(x)                                                       \
 {                                                                        \
  assert(unsigned(x)<_DIM_(g_hex_chars_for_guid_to_text));                \
                                                                          \
  PUSH_CH(g_hex_chars_for_guid_to_text[unsigned(x)]);                     \
 }

#define PUSH_BYTE_AS_HEX(b)                                               \
 {                                                                        \
  const unsigned char b1=static_cast<unsigned char>(b);                   \
                                                                          \
  PUSH_HEX(b1>>4)                                                         \
  PUSH_HEX(0x0F&(b1))                                                     \
 }

 //-----------------------------------------
 PUSH_CH('{')                               //1
 PUSH_BYTE_AS_HEX(guid.Data1>>24)           //2 3
 PUSH_BYTE_AS_HEX(guid.Data1>>16)           //4 5
 PUSH_BYTE_AS_HEX(guid.Data1>>8)            //6 7
 PUSH_BYTE_AS_HEX(guid.Data1)               //8 9
 PUSH_CH('-')                               //10
 PUSH_BYTE_AS_HEX(guid.Data2>>8)            //11 12
 PUSH_BYTE_AS_HEX(guid.Data2)               //13 14
 PUSH_CH('-')                               //15
 PUSH_BYTE_AS_HEX(guid.Data3>>8)            //16 17
 PUSH_BYTE_AS_HEX(guid.Data3)               //18 19
 PUSH_CH('-')                               //20
 PUSH_BYTE_AS_HEX(guid.Data4[0])            //21 22
 PUSH_BYTE_AS_HEX(guid.Data4[1])            //23 24
 PUSH_CH('-')                               //25
 PUSH_BYTE_AS_HEX(guid.Data4[2])            //26 27
 PUSH_BYTE_AS_HEX(guid.Data4[3])            //28 29
 PUSH_BYTE_AS_HEX(guid.Data4[4])            //30 31
 PUSH_BYTE_AS_HEX(guid.Data4[5])            //32 33
 PUSH_BYTE_AS_HEX(guid.Data4[6])            //34 35
 PUSH_BYTE_AS_HEX(guid.Data4[7])            //36 37
 PUSH_CH('}')                               //38

//------------------------------------------
#undef PUSH_BYTE_AS_HEX
#undef PUSH_HEX
#undef PUSH_CH

//------------------------------------------
 assert(p==e);

 return __STL_DEF_BASIC_STRING(TChar)(buffer,_DIM_(buffer));
}//guid_to_text

//------------------------------------------------------------------------
std::wstring guid_to_wstring(REFGUID guid)
{
 return guid_to_text<wchar_t>(guid);
}//guid_to_wstring

//------------------------------------------------------------------------
std::string guid_to_string(REFGUID guid)
{
 return guid_to_text<char>(guid);
}//guid_to_string

//------------------------------------------------------------------------
t_string guid_to_tstr(REFGUID guid)
{
 return guid_to_text<structure::t_char>(guid);
}//guid_to_tstr

////////////////////////////////////////////////////////////////////////////////
