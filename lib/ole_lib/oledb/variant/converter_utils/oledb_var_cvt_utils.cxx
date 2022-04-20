////////////////////////////////////////////////////////////////////////////////
//DBVARIANT_CVT_UTILS Implementation.
//                                                Kovalenko Dmitry. 11.02.2010.

////////////////////////////////////////////////////////////////////////////////
//STR with HEX number to BYTE[]

//return:
// S_OK                   - no error
// DB_E_CANTCONVERTVALUE  - str not has hex number
// other                  - error

template<class charT>
HRESULT DBVARIANT_CVT_UTILS::TextWithHexNumberToByteArray3
                                  (const charT* const  str,
                                   const charT* const  end_str,
                                   BYTE*        const  value,
                                   size_t       const  value_size)
{
 assert(str<=end_str);

 CHECK_READ_PTR(str,(end_str-str)*sizeof(*str));

 CHECK_WRITE_PTR(value,value_size*sizeof(*value));

 std::fill(value,value+value_size,structure::zero);

 if(str==end_str)
  return DB_E_CANTCONVERTVALUE;

 //-----------------------------------------
 typedef charT                                         char_type;
 typedef structure::t_char_traits2<char_type>          char_traits2;

 const char_type c_ch_0=char_traits2::ch_0();
 const char_type c_ch_9=char_traits2::ch_9();

 const char_type c_ch_x=char_traits2::ch_letter_x();
 const char_type c_ch_X=char_traits2::ch_letter_X();

 const char_type c_ch_a=char_traits2::ch_letter_a();
 const char_type c_ch_A=char_traits2::ch_letter_A();

#ifndef NDEBUG
 const char_type c_ch_f=char_traits2::ch_letter_f();
#endif
 const char_type c_ch_F=char_traits2::ch_letter_F();

 //-----------------------------------------
 assert(c_ch_0<c_ch_9);
 assert(c_ch_A<c_ch_F);
 assert(c_ch_a<c_ch_f);

 assert(size_t(c_ch_9-c_ch_0)==9);
 assert(size_t(c_ch_F-c_ch_A)==5);
 assert(size_t(c_ch_f-c_ch_a)==5);

 //-----------------------------------------
 const char_type* cur=str;

 //detect hex prefix
 if((*cur)==c_ch_0)
  ++cur;

 if(cur==end_str)
  return DB_E_CANTCONVERTVALUE;

 if(!((*cur)==c_ch_x || (*cur)==c_ch_X))
  return DB_E_CANTCONVERTVALUE;

 ++cur;

 if(cur==end_str)
  return DB_E_CANTCONVERTVALUE;

 //cur has heximal value
 const char_type* const _hex_beg=cur;

 //skeep first '0'
 for(;cur!=end_str && (*cur)==c_ch_0;++cur);

 //search end of HEX number
 const char_type* const _beg=cur;

 for(;cur!=end_str && char_traits2::is_hex(*cur);++cur);

 //cur - END of hex-digits. hex in [_beg .. cur)

 if(structure::miss_space2(cur,const_cast<const char_type*>(end_str))!=end_str)
  return DB_E_CANTCONVERTVALUE;

 if(cur==_hex_beg) //no any hex-digit
  return DB_E_CANTCONVERTVALUE;

 //if(cur==_beg) //no hex-digit!=0
 // return S_OK;

 assert(_beg<=cur);

 //check of converted string can be writted to OUTPUT buffer
 if(((size_t(cur-_beg)/2)+(size_t(cur-_beg)%2))>value_size)//overflow
  return TDBTypeConverterCode::data_overflow;

 //-------------------------
 BYTE part;
 bool upper_part=false;
 UINT i_byte=0;

 while(_beg<cur)
 {
  assert(i_byte<value_size);

  --cur;

  const char_type cur_c=*cur;

  if(cur_c>=c_ch_0 && cur_c<=c_ch_9)
  {
   part=static_cast<BYTE>(cur_c-c_ch_0);
  }
  else
  if(cur_c>=c_ch_A && cur_c<=c_ch_F)
  {
   part=static_cast<BYTE>(10+(cur_c-c_ch_A));
  }
  else
  {
   assert(cur_c>=c_ch_a && cur_c<=c_ch_f);

   part=static_cast<BYTE>(10+(cur_c-c_ch_a));
  }//else

  if(upper_part)
  {
   value[i_byte]|=static_cast<BYTE>(part<<4);

   ++i_byte;
  }
  else
  {
   value[i_byte]|=part;
  }//else

  upper_part=!upper_part;
 }//while

 return S_OK;
}//TextWithHexNumberToByteArray3

////////////////////////////////////////////////////////////////////////////////
//STR to DBVARIANT::TNumericDigit

//return:
//  S_OK  - no error
//  other - error
//out params:
//  digit - digits of number
//  scale - negative scale

template<class charT>
HRESULT DBVARIANT_CVT_UTILS::TextToUnsignedNumericDigit2
                                  (const charT*          _str,
                                   const charT*   const  end_str,
                                   TNumericDigit&        digit,
                                   size_type&            scale,
                                   size_type      const  c_max_precision,
                                   size_type      const  c_max_scale)
{
 assert(_str<=end_str);

 //-----------------------------------------
 typedef size_type                                     scale_type;

 //-----------------------------------------
 digit.init();

 scale=0;

 //-----------------------------------------
 typedef charT                                         char_type;
 typedef structure::t_char_traits2<char_type>          char_traits2;
 typedef tag_float_parts_in_str<char_type>             parts_type;

 const char_type c_ch_0=char_traits2::ch_0();
#ifndef NDEBUG
 const char_type c_ch_9=char_traits2::ch_9();
#endif
 //-----------------------------------------
 parts_type parts;

 {
  const HRESULT
   get_hr
    =self_type::GetFloatNumberParts
      (_str,
       end_str,
       gnfp_flag__no_mantisse_sign,
       &_str,
       &parts);

  if(FAILED(get_hr)) //DB_E_CANTCONVERTVALUE
   return get_hr;

  assert(get_hr==S_OK);
 }//local

 //-----------------------------------------
 assert(c_ch_0<c_ch_9);

 assert(size_t(c_ch_9-c_ch_0)==9);

 //--------------------
 size_type iscale=0;//scale of whole part       *10^scale
 size_type fscale=0;//scale of fractional part  /10^scale

 scale_type escale=0;

 //-----------------------------------------
 for(typename parts_type::const_pointer pos=parts.int_part_beg;pos!=parts.int_part_end;++pos)
 {
  assert((*pos)>=c_ch_0 && (*pos)<=c_ch_9);

  if((*pos)==c_ch_0 && digit.empty()) //skeep forward 0
   continue;

  // [2021-02-25]
  assert(digit.size()<=digit.max_size());

  if(digit.size()==digit.max_size())
  {
   ++iscale;
  }
  else
  {
   _VERIFY(digit.shift_on_positive_scale(1)); //OVERFLOW must not occured

   digit[0]=static_cast<BYTE>((*pos)-c_ch_0);
  }
 }//for pos

 //-----------------------------------------
 for(typename parts_type::const_pointer pos=parts.float_part_beg;pos!=parts.float_part_end;++pos)
 {
  assert((*pos)>=c_ch_0 && (*pos)<=c_ch_9);

  if(digit.size()<digit.max_size()) //есть место дл€ записи дробной части
  {
   ++fscale;

   if(!digit.empty())
   {
    _VERIFY(digit.shift_on_positive_scale(1));
   }//if

   digit[0]=static_cast<BYTE>((*pos)-c_ch_0);

   assert(!digit.empty());
  }//if
 }//for pos

 //определ€ем наличие коэфициента масштабировани€
 {
  const scale_type
   max_scale=structure::t_numeric_limits<scale_type>().max_value();

  const scale_type
   max_scale_div10=max_scale/10;

  for(typename parts_type::const_pointer pos=parts.scale_part_beg;pos!=parts.scale_part_end;++pos)
  {
   assert((*pos)>=c_ch_0 && (*pos)<=c_ch_9);

   if((*pos)==c_ch_0 && escale==0)
    continue;

   if(escale>max_scale_div10)
    return TDBTypeConverterCode::numeric_overflow;

   escale*=10;

   assert(escale<=max_scale);

   const BYTE d=static_cast<BYTE>((*pos)-c_ch_0);

   if(static_cast<scale_type>(max_scale-escale)<scale_type(d))
    return TDBTypeConverterCode::numeric_overflow;

   escale+=d;
  }//for
 }//local

 //iscale и fscale одновременно не могут быть указаны
 assert(!(iscale && fscale));

 //формируем окончательный коэффициент масштабировани€

 //обрабатываем масштабирование целой части
 if(parts.scale_sign==parts_type::sign_kind__negative)
 {
  //указано отрицательное масштабирование
  if(escale>iscale)
  {
   escale-=iscale;
  }
  else
  {
   parts.scale_sign=parts_type::sign_kind__undefined;

   escale=iscale-escale;
  }
 }
 else
 {
  assert(parts.scale_sign!=parts_type::sign_kind__negative);

  if(escale+iscale<escale)
   return TDBTypeConverterCode::numeric_overflow;

  escale+=iscale;
 }//else

 //масштабирование дробной части
 if(parts.scale_sign==parts_type::sign_kind__negative)
 {
  //отрицательное масштабирование
  if(escale+fscale<escale)
   return TDBTypeConverterCode::numeric_overflow;

  escale+=fscale;
 }
 else
 {
  if(fscale>escale)
  {
   parts.scale_sign=parts_type::sign_kind__negative;

   escale=fscale-escale;
  }
  else
  {
   escale-=fscale;
  }
 }//else

 digit.pack();

 if(parts.scale_sign==parts_type::sign_kind__negative) //negative scale
 {
  //remove terminate null
  {
   size_t n_shift=0;

   for(;n_shift<escale && n_shift<digit.size() && digit[n_shift]==0;++n_shift);

   if(n_shift!=0)
   {
    _VERIFY(digit.shift_on_negative_scale(n_shift,false));

    assert(n_shift<=escale);

    escale-=n_shift;
   }
  }//local

  if(digit.size()>c_max_precision)
  {
   //срезаем хвост числа
   const size_type n_shift=digit.size()-c_max_precision;

   //будет срезана цела€ часть числа (escale - число знаков после зап€той)
   if(n_shift>escale)
    return TDBTypeConverterCode::numeric_overflow;

   _VERIFY(digit.shift_on_negative_scale(n_shift,true));

   //уменьшаем число знаков после зап€той
   escale-=n_shift;
  }//if
 }
 else
 {
  assert_hint(parts.scale_sign!=parts_type::sign_kind__negative);

  //положительное масштабирование не поддерживаетс€ (эмул€ци€)

  if(digit.size()>c_max_precision)
   return TDBTypeConverterCode::numeric_overflow;

  if((c_max_precision-digit.size())<escale)
   return TDBTypeConverterCode::numeric_overflow;

  if(!digit.shift_on_positive_scale(escale))
   return TDBTypeConverterCode::numeric_overflow;

  escale=0; //положительное масштабирование было эмулировано
 }//else - эмул€ци€ положительного масштабировани€

 assert(digit.size()<=c_max_precision);

 if(escale>c_max_scale)
 {
  //[2021-03-01]
  assert(parts.scale_sign==parts_type::sign_kind__negative);

  const size_type n_shift=(escale-c_max_scale);

  assert_hint(n_shift>0);

  //уменьшаем число знаков после зап€той на n_shift
  _VERIFY(digit.shift_on_negative_scale(n_shift,true));

  escale=c_max_scale;
 }//if

 scale=escale;

 return S_OK;
}//TextToUnsignedNumericDigit2

////////////////////////////////////////////////////////////////////////////////

const char DBVARIANT_CVT_UTILS::sm_hex_chars_u[16]
  ={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

const char DBVARIANT_CVT_UTILS::sm_hex_chars_l[16]
  ={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

//------------------------------------------------------------------------
template<class charT>
size_t DBVARIANT_CVT_UTILS::Helper__GuidToText(const cvt_ctx_type* const pCvtCtx,
                                               const GUID&               guid,
                                               size_t              const buffer_size,
                                               charT                     buffer[])
{
 assert(pCvtCtx);
 assert_s(sizeof(guid)==16);
 assert_s(sizeof(guid.Data1)==4);
 assert_s(sizeof(guid.Data2)==2);
 assert_s(sizeof(guid.Data3)==2);
 assert_s(sizeof(guid.Data4)==8);
 assert_s(_DIM_(guid.Data4)==8);

 assert(buffer_size>=c_min_buffer_size_for_cvt_from_guid_to_text);

 CHECK_READ_WRITE_PTR(buffer,buffer_size);

 //-------
#if CHAR_BIT!=8
# error Incorrect value of CHAR_BIT!
#endif

 //-------
 if(buffer_size<c_min_buffer_size_for_cvt_from_guid_to_text)
  throw std::runtime_error("[BUG CHECK] incorrect usage of DBVARIANT_CVT_UTILS::Helper__GuidToText");

 typedef structure::t_char_traits2<charT> ct2;

 //-------
 //typedef struct _GUID {
 //   unsigned long  Data1;    //3 2 1 0
 //   unsigned short Data2;    //5 4
 //   unsigned short Data3;    //7 6
 //   unsigned char  Data4[8]; //8 9 10 11 12 13 14 15
 //} GUID;

 //-------
 std::array<unsigned char,8> guid2;

 {
  DWORD Data1=guid.Data1;

  guid2[3]=(unsigned char)(Data1&0x000000FF);
  Data1>>=8;

  guid2[2]=(unsigned char)(Data1&0x000000FF);
  Data1>>=8;

  guid2[1]=(unsigned char)(Data1&0x000000FF);
  Data1>>=8;

  assert(Data1<256);

  guid2[0]=(unsigned char)(Data1&0x000000FF);
 }//local

 {
  WORD Data2=guid.Data2;

  guid2[5]=(unsigned char)(Data2&0x00FF);
  Data2>>=8;

  assert(Data2<256);

  guid2[4]=(unsigned char)(Data2&0x00FF);
 }//local

 {
  WORD Data3=guid.Data3;

  guid2[7]=(unsigned char)(Data3&0x00FF);
  Data3>>=8;

  assert(Data3<256);

  guid2[6]=(unsigned char)(Data3&0x00FF);
 }//local

 //------------------------------------ get settings
 const bool setting__LowerCase
  =TDBTypeConverterPropertyUtils::GetValue_Bool_N
    (pCvtCtx,TDBTypeConverterPropertyNames::GuidToText__LowerCase)
     .value_or_default(TDBTypeConverterPropertyDefaults::GuidToText__LowerCase);

 const bool setting__FBrackets
  =TDBTypeConverterPropertyUtils::GetValue_Bool_N
    (pCvtCtx,TDBTypeConverterPropertyNames::GuidToText__FBrackets)
     .value_or_default(TDBTypeConverterPropertyDefaults::GuidToText__FBrackets);

 //------------------------------------
 assert_s(_DIM_(sm_hex_chars_u)==16);
 assert_s(_DIM_(sm_hex_chars_l)==16);

 const char* const hex_chars
  =setting__LowerCase?sm_hex_chars_l:sm_hex_chars_u;

 //------------------------------------
 charT* p=buffer;

#ifndef NDEBUG
 const charT* const buffer_end=(p+buffer_size);
#endif

#define PUT_CH(_ch)                    \
 {                                     \
  assert(p!=buffer_end);               \
                                       \
  (*p)=_ch;                            \
                                       \
  ++p;                                 \
 }

#define PUT_BYTE(_b)                   \
 {                                     \
  const unsigned char t=_b;            \
                                       \
  assert((t>>4)<16);                   \
  assert((t&0x0F)<16);                 \
                                       \
  PUT_CH(hex_chars[t>>4])              \
  PUT_CH(hex_chars[t&0x0F])            \
 }

 //------------------------------------
 //xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX

 //4F0F4A9E-16B8-4CD9-82F2-C7EA65C8B8A8
 //0x4F0F4A9E,0x16B8,0x4CD9,{0x82,0xF2,0xC7,0xEA,0x65,0xC8,0xB8,0xA8;

 if(setting__FBrackets)
 {
  PUT_CH('{')
 }

 PUT_BYTE(guid2[0])
 PUT_BYTE(guid2[1])
 PUT_BYTE(guid2[2])
 PUT_BYTE(guid2[3])
 PUT_CH('-')
 PUT_BYTE(guid2[4])
 PUT_BYTE(guid2[5])
 PUT_CH('-')
 PUT_BYTE(guid2[6])
 PUT_BYTE(guid2[7])
 PUT_CH('-')
 PUT_BYTE(guid.Data4[0])
 PUT_BYTE(guid.Data4[1])
 PUT_CH('-')
 PUT_BYTE(guid.Data4[2])
 PUT_BYTE(guid.Data4[3])
 PUT_BYTE(guid.Data4[4])
 PUT_BYTE(guid.Data4[5])
 PUT_BYTE(guid.Data4[6])
 PUT_BYTE(guid.Data4[7])

 if(setting__FBrackets)
 {
  PUT_CH('}')
 }

 //------------------------------------
#undef PUT_BYTE
#undef PUT_CH

 //------------------------------------
 assert(p>buffer);
 assert(p<=buffer_end);

 return (p-buffer);
}//Helper__GuidToText

////////////////////////////////////////////////////////////////////////////////

template<class charT>
HRESULT DBVARIANT_CVT_UTILS::Helper__TextToGUID(const charT* const str,
                                                size_t       const length,
                                                GUID*        const  result)
{
 typedef structure::t_char_traits2<charT> ct2;

 CHECK_READ_TYPED_PTR(str,length);

 const charT*  s=str;
 const charT* _e=s+length;

 if(s==_e)
  return DB_E_CANTCONVERTVALUE;

 if((*s)==ct2::ch_open_fbracket())
 {
  //12345678901234567890123456789012345678
  //{xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX}

  if(length!=38)
   return DB_E_CANTCONVERTVALUE;

  ++s;

  assert(s!=_e);

  --_e;

  assert(s!=_e);

  if((*_e)!=ct2::ch_close_fbracket())
   return DB_E_CANTCONVERTVALUE;

  assert(s<_e);
  assert((_e-s)==36);

  return Helper__TextToGUID__HEX(s,_e,result);
 }//if

 //123456789012345678901234567890123456
 //xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX

 if(length==36)
 {
  return Helper__TextToGUID__HEX(str,str+length,result);
 }//if

 return DB_E_CANTCONVERTVALUE;
}//Helper__TextToGUID

//------------------------------------------------------------------------
template<class charT>
HRESULT DBVARIANT_CVT_UTILS::Helper__TextToGUID__HEX(const charT* const beg,
                                                     const charT* const DEBUG_CODE(end),
                                                     GUID*        const result)
{
 typedef structure::t_char_traits2<charT> ct2;

 //123456789012345678901234567890123456
 //xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX

 assert(beg<end);
 assert((end-beg)==36);

 const charT* s=beg;

 typedef unsigned char byte_type;

 //typedef struct _GUID {
 //   unsigned long  Data1;    //3 2 1 0
 //   unsigned short Data2;    //5 4
 //   unsigned short Data3;    //7 6
 //   unsigned char  Data4[8]; //8 9 10 11 12 13 14 15
 //} GUID;

 byte_type data[16];

 // 3 2 1 0
 //xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX

 const signed char
  rules[]
   ={3,2,1,0,
     -1,
     5,4,
     -1,
     7,6,
     -1,
     8,9,
     -1,
     10,11,12,13,14,15};

 for(size_t i=0;i!=_DIM_(rules);++i)
 {
  assert(s!=end);

  if(rules[i]==-1)
  {
   if((*s)!=ct2::ch_minus())
    return DB_E_CANTCONVERTVALUE;

   ++s;

   continue;
  }//if

  assert_hint(rules[i]>=0);
  assert_hint(rules[i]<_DIM_(data));

  byte_type cur_byte;

  if((*s)>='0' && (*s)<='9')
   cur_byte=byte_type((*s)-'0');
  else
  if((*s)>='a' && (*s)<='f')
   cur_byte=byte_type(10+((*s)-'a'));
  else
  if((*s)>='A' && (*s)<='F')
   cur_byte=byte_type(10+((*s)-'A'));
  else
   return DB_E_CANTCONVERTVALUE;

  ++s;

  assert(s!=end);

  cur_byte=byte_type(cur_byte<<4);

  if((*s)>='0' && (*s)<='9')
   cur_byte=byte_type(cur_byte+byte_type((*s)-'0'));
  else
  if((*s)>='a' && (*s)<='f')
   cur_byte=byte_type(cur_byte+byte_type(10+((*s)-'a')));
  else
  if((*s)>='A' && (*s)<='F')
   cur_byte=byte_type(cur_byte+byte_type(10+((*s)-'A')));
  else
   return DB_E_CANTCONVERTVALUE;

  data[rules[i]]=cur_byte;

  ++s;
 }//for i

 assert(s==end);

 typedef unsigned __int16 word_type;
 typedef unsigned __int32 dword_type;

 result->Data1= (dword_type(data[0]))
               +(dword_type(data[1])<<8)
               +(dword_type(data[2])<<16)
               +(dword_type(data[3])<<24);

 result->Data2=word_type((word_type(data[4]))+(word_type(data[5])<<8));

 result->Data3=word_type((word_type(data[6]))+(word_type(data[7])<<8));

 assert(_DIM_(result->Data4)==8);

 result->Data4[0]=data[8];
 result->Data4[1]=data[9];
 result->Data4[2]=data[10];
 result->Data4[3]=data[11];
 result->Data4[4]=data[12];
 result->Data4[5]=data[13];
 result->Data4[6]=data[14];
 result->Data4[7]=data[15];

 return S_OK;
}//Helper__TextToGUID__HEX

//////////////////////////////////////////////////////////////////////////

template<class charT>
HRESULT DBVARIANT_CVT_UTILS::GetFloatNumberParts
                             (const charT*                   const _str,
                              const charT*                   const end_str,
                              gnfp_flags_type                const gnfp_flags,
                              const charT**                  const pos_str,
                              tag_float_parts_in_str<charT>* const parts)
{
 assert(_str<=end_str);
 assert(pos_str!=NULL);
 assert(parts!=NULL);

 //-----------------------------------------
 typedef charT                                         char_type;
 typedef structure::t_char_traits2<char_type>          char_traits2;
 typedef tag_float_parts_in_str<charT>                 parts_type;

 //-----------------------------------------
 parts->init();

 const char_type*& pos=*pos_str;

 pos=_str;

 //-----------------------------------------
 const char_type c_ch_0=char_traits2::ch_0();
 const char_type c_ch_9=char_traits2::ch_9();

 const char_type c_ch_e=char_traits2::ch_letter_e();
 const char_type c_ch_E=char_traits2::ch_letter_E();

 const char_type c_ch_point =char_traits2::ch_point();
 const char_type c_ch_plus  =char_traits2::ch_plus();
 const char_type c_ch_minus =char_traits2::ch_minus();

 //--------------------
 assert(c_ch_0<c_ch_9);

 assert(size_t(c_ch_9-c_ch_0)==9);

 //-----------------------------------------
 pos=structure::miss_space2(pos,end_str);

 if(pos==end_str)
  return DB_E_CANTCONVERTVALUE;

 //-----------------------------------------
 if((*pos)==c_ch_plus)
 {
  if((gnfp_flags&gnfp_flag__no_mantisse_sign)!=0)
   return DB_E_CANTCONVERTVALUE;

  parts->mantisse_sign=parts_type::sign_kind__positive;

  ++pos;
 }
 else
 if((*pos)==c_ch_minus)
 {
  if((gnfp_flags&gnfp_flag__no_mantisse_sign)!=0)
   return DB_E_CANTCONVERTVALUE;

  parts->mantisse_sign=parts_type::sign_kind__negative;

  ++pos;
 }//if

 //-----------------------------------------
 bool is_float=false;

 bool has_ipart=false;
 bool has_fpart=false;

 for(;pos!=end_str;++pos)
 {
  if((*pos)>=c_ch_0 && (*pos)<=c_ch_9)
  {
   if(!is_float)
   {
    has_ipart=true;

    if(parts->int_part_beg==NULL)
    {
     if((*pos)==c_ch_0) //skeep forward 0
      continue;

     parts->int_part_beg=pos;
    }//if

    parts->int_part_end=pos+1;
   }
   else//float part
   {
    has_fpart=true;

    if(parts->float_part_beg==NULL)
    {
     parts->float_part_beg=pos;
    }

    parts->float_part_end=pos+1;
   }//else float part

   continue;
  }//if 0..9

  if(!is_float && (*pos)==c_ch_point)
  {
   is_float=true;
   continue;
  }

  //unknown symbol
  break;
 }//for pos...end_str

 if(!has_ipart && !has_fpart) //нет ни целой, ни дробной части
 {
  return DB_E_CANTCONVERTVALUE;
 }

 //определ€ем наличие коэфициента масштабировани€
 if(pos!=end_str)
 {
  if((*pos)==c_ch_e || (*pos)==c_ch_E)
  {
   ++pos; //skeep 'e'

   if(pos==end_str)
    return DB_E_CANTCONVERTVALUE;

   if((*pos)==c_ch_plus)
   {
    parts->scale_sign=parts_type::sign_kind__positive;

    ++pos; //пропускаем знак
   }
   else
   if((*pos)==c_ch_minus)
   {
    parts->scale_sign=parts_type::sign_kind__negative;

    ++pos; //пропускаем знак
   }//else

   const char_type* beg_escale=pos;

   for(;pos!=end_str && (*pos)>=c_ch_0 && (*pos)<=c_ch_9;++pos);

   //не указано масштабирование
   if(beg_escale==pos)
    return DB_E_CANTCONVERTVALUE;

   //ignore forward nulls
   for(;beg_escale!=pos && (*beg_escale)==c_ch_0;++beg_escale);

   //---
   parts->scale_part_beg=beg_escale;
   parts->scale_part_end=pos;
  }//показатель масштабировани€

  //провер€ем наличие неопознанных символов. будем немного жЄсткими,
  // а то автоматизированные тесты KD на рога станов€тс€.
  pos=structure::miss_space2(pos,end_str);

  if(pos!=end_str)
   return DB_E_CANTCONVERTVALUE;
 }//if pos!=end_str

 //ignore last zero of float part
 while(parts->float_part_beg!=parts->float_part_end)
 {
  if((*(parts->float_part_end-1))!=c_ch_0)
   break;

  --parts->float_part_end;
 }//while

 return S_OK;
}//GetFloatNumberParts

////////////////////////////////////////////////////////////////////////////////
