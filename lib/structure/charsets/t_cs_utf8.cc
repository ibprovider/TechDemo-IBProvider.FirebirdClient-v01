////////////////////////////////////////////////////////////////////////////////
#ifndef _structure_charsets_t_cs_utf8_CC_
#define _structure_charsets_t_cs_utf8_CC_

namespace structure{namespace charsets{namespace cs_utf8{
////////////////////////////////////////////////////////////////////////////////

/*
* Bits  Hex Min  Hex Max  Byte Sequence in Binary
*   7  00000000 0000007F 0vvvvvvv
*  11  00000080 000007FF 110vvvvv 10vvvvvv
*  16  00000800 0000FFFF 1110vvvv 10vvvvvv 10vvvvvv
*  21  00010000 001FFFFF 11110vvv 10vvvvvv 10vvvvvv 10vvvvvv
*  26  00200000 03FFFFFF 111110vv 10vvvvvv 10vvvvvv 10vvvvvv 10vvvvvv
*  31  04000000 7FFFFFFF 1111110v 10vvvvvv 10vvvvvv 10vvvvvv 10vvvvvv 10vvvvvv
*
*  символы UTF8 содержат максимум 4 байта
*/

////////////////////////////////////////////////////////////////////////////////
//signle UCS2 to UTF8

template<class TForwardIterator>
TForwardIterator __single_ucs2_to_utf8(TForwardIterator        source_beg,
                                       TForwardIterator        source_end,
                                       traits::UTF8*           utf8,
                                       /*in-out*/size_t&       sz_utf8,
                                       /*out*/t_cs_cvt_result* cvt_result)
{
 assert(cvt_result!=NULL);

 assert(utf8!=NULL || sz_utf8==0);

 CHECK_WRITE_TYPED_PTR(utf8,sz_utf8);

 //-----------------------------------------
 typedef traits::UTF8           UTF8;
 //typedef traits::UCS2           UCS2;
 typedef traits::UCS4           UCS4;

 //consts ----------------------------------
 const UCS4 c_byteMask          = 0xBF; //1011 1111
 const UCS4 c_byteMark          = 0x80; //1000 0000

 //-----------------------------------------
 const size_t original_sz_utf8=sz_utf8;

 sz_utf8=0;

 if(source_beg==source_end)
 {
  (*cvt_result)=cs_cvt_result__ok;
  
  return source_beg;
 }//if

 //-----------------------------------------
 UCS4 wc=*source_beg;

 if(wc<0x0080)
 {
  //  1 byte sequence
  //
  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*   7  00000000 0000007F 0vvvvvvv

  ++source_beg;

  //------------ install OUT parameters
  sz_utf8=1;                                // <---!!!

  if(utf8!=NULL)
  {
   if(original_sz_utf8<1)                   // <---!!!
   {
    (*cvt_result)=cs_cvt_result__small_output;
  
    return source_beg;
   }//if

   utf8[0]=static_cast<UTF8>(wc);
  }//if utf8!=NULL

  //----------------------------------------
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//if wc<0x0080

 assert(!(wc<0x0080));

 //-----------------------------------------------------------------------
 if(wc<0x0800)
 {
  //  2 byte sequence
  //
  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*  11  00000080 000007FF 110vvvvv 10vvvvvv

  ++source_beg;

  //------------ install OUT parameters
  sz_utf8=2;                                // <---!!!

  if(utf8!=NULL)
  {
   if(original_sz_utf8<2)                   // <---!!!
   {
    (*cvt_result)=cs_cvt_result__small_output;
  
    return source_beg;
   }//if

   utf8[1]=static_cast<UTF8>((wc | c_byteMark) & c_byteMask);

   wc>>=6;

   utf8[0]=static_cast<traits::UTF8>(wc | 0xC0);
  }//if utf8!=NULL

  //----------------------------------------
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//if wc<0x0800

 assert(!(wc<0x0800));

 //-----------------------------------------------------------------------
 if(wc<0x010000)
 {
  //  3 or 4 bit sequence
  //
  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*  16  00000800 0000FFFF 1110vvvv 10vvvvvv 10vvvvvv
  //*  21  00010000 001FFFFF 11110vvv 10vvvvvv 10vvvvvv 10vvvvvv

  if(!traits::is_surrogate(wc))
  {
   //  3 byte sequence
   //
   //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
   //*  16  00000800 0000FFFF 1110vvvv 10vvvvvv 10vvvvvv

   ++source_beg;

   //------------ install OUT parameters
   sz_utf8=3;                               // <---!!!

   if(utf8!=NULL)
   {
    if(original_sz_utf8<3)                  // <---!!!
    {
     (*cvt_result)=cs_cvt_result__small_output;
  
     return source_beg;
    }//if

    utf8[2]=static_cast<UTF8>((wc | c_byteMark) & c_byteMask);

    wc>>=6;

    utf8[1]=static_cast<UTF8>((wc | c_byteMark) & c_byteMask);

    wc>>=6;

    utf8[0]=static_cast<UTF8>(wc | 0xE0);
   }//if utf8!=NULL

   //---------------------------------------
   (*cvt_result)=cs_cvt_result__ok;

   return source_beg;
  }//if !traits::is_surrogate(wc)

  assert(traits::is_surrogate(wc));

  //----------------------------------------------------------------------
  //  4 byte sequence
  //
  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*  21  00010000 001FFFFF 11110vvv 10vvvvvv 10vvvvvv 10vvvvvv

  if(!traits::is_surrogate_ch1(wc))
  {
   (*cvt_result)=cs_cvt_result__bad_input;
  
   return source_beg;
  }//if !is_surrogate_ch1

  assert(wc>=traits::c_SURROGATE_HIGH_START);
  assert(wc<=traits::c_SURROGATE_HIGH_END);

  ++source_beg;

  //----------------------------------------
  if(source_beg==source_end)
  {
   (*cvt_result)=cs_cvt_result__trunc_input;
  
   return source_beg;
  }//if

  const UCS4 wc2=*source_beg;

  if(!traits::is_surrogate_ch2(wc2))
  {
   (*cvt_result)=cs_cvt_result__bad_input;
  
   return source_beg;
  }//if !is_surrogate_ch2

  assert(wc2>=traits::c_SURROGATE_LOW_START);
  assert(wc2<=traits::c_SURROGATE_LOW_END);

  ++source_beg;

  //----------------------------------------
  wc=(wc<<traits::c_HALF_SHIFT)+wc2-traits::c_SURROGATE_OFFSET;

  //----------------------------------------
  assert(wc>=traits::c_SURROGATE_BASE);
  assert(wc<=traits::c_SURROGATE_END);

  assert(traits::c_SURROGATE_BASE >=0x00010000);
  assert(traits::c_SURROGATE_END  <=0x001FFFFF);

  //------------ install OUT parameters
  sz_utf8=4;                                // <---!!!

  if(utf8!=NULL)
  {
   if(original_sz_utf8<4)                   // <---!!!
   {
    (*cvt_result)=cs_cvt_result__small_output;
  
    return source_beg;
   }//if

   utf8[3]=static_cast<UTF8>((wc | c_byteMark) & c_byteMask);

   wc>>=6;

   utf8[2]=static_cast<UTF8>((wc | c_byteMark) & c_byteMask);

   wc>>=6;

   utf8[1]=static_cast<UTF8>((wc | c_byteMark) & c_byteMask);

   wc>>=6;

   utf8[0]=static_cast<UTF8>(wc | 0xF0);
  }//if utf8!=NULL

  //----------------------------------------
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//if wc<0x010000
 
 //-----------------------------------------------------------------------
 assert(!(wc<0x010000));

 (*cvt_result)=cs_cvt_result__bad_input;

 return source_beg;
}//__single_ucs2_to_utf8

//------------------------------------------------------------------------
template<class TForwardIterator>
inline
TForwardIterator single_ucs2_to_utf8(TForwardIterator              source_beg,
                                     TForwardIterator              source_end,
                                     unsigned char*          const utf8,
                                     /*in-out*/size_t&             sz_utf8,
                                     /*out*/t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result);
 assert_s(sizeof(*utf8)==sizeof(traits::UTF8));

 return __single_ucs2_to_utf8(source_beg,
                              source_end,
                              reinterpret_cast<traits::UTF8*>(utf8),
                              sz_utf8,
                              cvt_result);
}//single_ucs2_to_utf8 - unsigned char

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator single_ucs2_to_utf8(TForwardIterator              source_beg,
                                     TForwardIterator              source_end,
                                     signed char*            const utf8,
                                     /*in-out*/size_t&             sz_utf8,
                                     /*out*/t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result);
 assert_s(sizeof(*utf8)==sizeof(traits::UTF8));

 return __single_ucs2_to_utf8(source_beg,
                              source_end,
                              reinterpret_cast<traits::UTF8*>(utf8),
                              sz_utf8,
                              cvt_result);
}//single_ucs2_to_utf8 - signed char

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator single_ucs2_to_utf8(TForwardIterator        source_beg,
                                     TForwardIterator        source_end,
                                     char*                   utf8,
                                     /*in-out*/size_t&       sz_utf8,
                                     /*out*/t_cs_cvt_result* cvt_result)
{
 assert(cvt_result);
 assert_s(sizeof(*utf8)==sizeof(traits::UTF8));

 return __single_ucs2_to_utf8(source_beg,
                              source_end,
                              reinterpret_cast<traits::UTF8*>(utf8),
                              sz_utf8,
                              cvt_result);
}//single_ucs2_to_utf8 - char

////////////////////////////////////////////////////////////////////////////////
//single UTF8 to UCS2

#define GET_UTF8_CH2(utf8_char)                         \
 if(source_beg==source_end)                             \
 {                                                      \
  (*cvt_result)=cs_cvt_result__trunc_input;             \
                                                        \
  return source_beg;                                    \
 }                                                      \
                                                        \
 const UTF8 utf8_char=(((*source_beg)^0x80)&0xFF);      \
                                                        \
 if((utf8_char&0xC0)!=0)                                \
 {                                                      \
  (*cvt_result)=cs_cvt_result__bad_input;               \
                                                        \
  return source_beg;                                    \
 }                                                      \
                                                        \
 ++source_beg;

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator single_utf8_to_ucs2(TForwardIterator              source_beg,
                                     TForwardIterator              source_end,
                                     traits::UCS2*           const ucs2,
                                     /*in-out*/size_t&             sz_ucs2,
                                     /*out*/t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result);
 assert(ucs2!=NULL || sz_ucs2==0);

 CHECK_WRITE_TYPED_PTR(ucs2,sz_ucs2);

 //----------------------------------------
 typedef traits::UTF8           UTF8;
 typedef traits::UCS2           UCS2;
 typedef traits::UCS4           UCS4;

 //----------------------------------------
 const size_t original_sz_ucs2=sz_ucs2;

 sz_ucs2=0;

 if(source_beg==source_end) //пустая последовательность
 {
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//if

 //запоминаем первый байт utf8 последовательности
 const UTF8 c0=(*source_beg);

 //-----------------------------------------------------------------------
 if(static_cast<UTF8>(c0&0x80)==0x00)
 {
  //1 byte sequential
  ++source_beg;  

  //корректность упаковки проверять не надо!

  //------------ install OUT parameters
  sz_ucs2=1;

  if(ucs2!=NULL)
  {
   //буфер получателя меньше допустимого?
   if(original_sz_ucs2<1)
   {
    (*cvt_result)=cs_cvt_result__small_output;
   
    return source_beg;
   }//if

   //возвращаем сформированное UCS значение
   (*ucs2)=(c0&0xFF);
  }//if

  //----------------------------------------
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//if //static_cast<UTF8>(c0&0x80)==0x00 ----- 1 byte sequential

 //-----------------------------------------------------------------------
 if(static_cast<UTF8>(c0&0xE0)==0xC0)
 {
  //2 byte sequential
  ++source_beg;
  
  GET_UTF8_CH2(c1)

  //------------ build
  UCS2 l=(c0&0xFF);

  l=(l<<6)+c1;

  //обрезаем лишние старшие биты (остались от c0)
  l=(l&0x7FF);

  //полученное число не должно быть меньше (проверяем корректность упаковки)
  if(l<0x80)
  {
   (*cvt_result)=cs_cvt_result__bad_input_packing;
  
   return source_beg;
  }//if

  //------------ install OUT parameters
  sz_ucs2=1;

  if(ucs2!=NULL)
  {
   //буфер получателя меньше допустимого?
   if(original_sz_ucs2<1)
   {
    (*cvt_result)=cs_cvt_result__small_output;
  
    return source_beg;
   }//if

   //возвращаем сформированное UCS значение

   (*ucs2)=l;
  }//if ucs2!=NULL

  //----------------------------------------
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//static_cast<UTF8>(c0&0xE0)==0xC0 ----- 2 byte sequential

 //-----------------------------------------------------------------------
 if(static_cast<UTF8>(c0&0xF0)==0xE0)
 {
  //3 byte sequential
  ++source_beg;
  
  GET_UTF8_CH2(c1)
  GET_UTF8_CH2(c2)

  //------------ build
  UCS2 l=(c0&0xFF);

  l=(l<<6)+c1;
  l=(l<<6)+c2;

  //обрезаем лишние старшие биты (остались от c0)
  l=(l&0xFFFF);

  //полученное число не должно быть меньше (проверяем корректность упаковки)
  if(l<0x800)
  {
   (*cvt_result)=cs_cvt_result__bad_input_packing;
  
   return source_beg;
  }//if

  //полученное число не должно быть суррогатным
  if(traits::is_surrogate(l))
  {
   (*cvt_result)=cs_cvt_result__bad_input;
  
   return source_beg;
  }//if

  //------------ install OUT parameters
  sz_ucs2=1;

  if(ucs2!=NULL)
  {
   //буфер получателя меньше допустимого?
   if(original_sz_ucs2<1)
   {
    (*cvt_result)=cs_cvt_result__small_output;
  
    return source_beg;
   }//if

   //возвращаем сформированное UCS значение

   (*ucs2)=l;
  }//if ucs2!=NULL

  //----------------------------------------
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//static_cast<UTF8>(c0&0xF0)==0xE0 ----- 3 byte sequential

 //-----------------------------------------------------------------------
 if(static_cast<UTF8>(c0&0xF8)==0xF0)
 {
  //4 byte sequential
  ++source_beg;

  GET_UTF8_CH2(c1)
  GET_UTF8_CH2(c2)
  GET_UTF8_CH2(c3)

  //------------ build
  UCS4 l=(c0&0xFF);

  l=(l<<6)+c1;
  l=(l<<6)+c2;
  l=(l<<6)+c3;

  //обрезаем лишние старшие биты (остались от c0)
  l=(l&0x1FFFFF);

  //полученное число не должно быть меньше (проверяем корректность упаковки)
  if(l<0x10000)
  {
   (*cvt_result)=cs_cvt_result__bad_input_packing;
  
   return source_beg;
  }//if

  if(l>traits::c_MAXIMUM_UTF)
  {
   (*cvt_result)=cs_cvt_result__bad_input;
  
   return source_beg;
  }//if

  //------------ install OUT parameters
  sz_ucs2=2;

  if(ucs2!=NULL)
  {
   //буфер получателя меньше допустимого?
   if(original_sz_ucs2<2)
   {
    (*cvt_result)=cs_cvt_result__small_output;
   
    return source_beg;
   }//if
   
   //возвращаем сформированное UCS значение
   assert(l>=traits::c_SURROGATE_BASE);
 
   l-=traits::c_SURROGATE_BASE;
 
   ucs2[0]=static_cast<UCS2>((l >> traits::c_HALF_SHIFT) + traits::c_SURROGATE_HIGH_START);
  
   assert(ucs2[0]>=traits::c_SURROGATE_HIGH_START);
   assert(ucs2[0]<=traits::c_SURROGATE_HIGH_END);
 
   ucs2[1]=static_cast<UCS2>((l & traits::c_HALF_MASK) + traits::c_SURROGATE_LOW_START);
 
   assert(ucs2[1]>=traits::c_SURROGATE_LOW_START);
   assert(ucs2[1]<=traits::c_SURROGATE_LOW_END);
  }//if ucs2!=NULL

  //----------------------------------------
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//static_cast<UTF8>(c0&0xF8)==0xF0 ----- 4 byte sequential

 //-----------------------------------------------------------------------
 (*cvt_result)=cs_cvt_result__bad_input;

 return source_beg;
}//single_utf8_to_ucs2

#undef GET_UTF8_CH2

////////////////////////////////////////////////////////////////////////////////
//char sequential ucs2-->utf8 converter

template<class TForwardIterator,class TDestIterator>
TForwardIterator ucs2_to_utf8(TForwardIterator              source_beg,
                              TForwardIterator              source_end,
                              TDestIterator                 dest,
                              /*out*/t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result);

 (*cvt_result)=cs_cvt_result__ok;

 //-----------------------------------------
 traits::UTF8 utf8_buffer[4];
 
 size_t sz_utf8_buffer;

 const traits::UTF8* utf8_ptr;

 while(source_beg!=source_end)
 {
  source_beg=__single_ucs2_to_utf8(source_beg,
                                   source_end,
                                   utf8_buffer,
                                   sz_utf8_buffer=_DIM_(utf8_buffer),
                                   cvt_result);

  assert((*cvt_result)!=cs_cvt_result__small_output);

  if((*cvt_result)!=cs_cvt_result__ok)
  {
   assert(sz_utf8_buffer==0);
   
   break;
  }//if

  assert(sz_utf8_buffer>=1);
  assert(sz_utf8_buffer<=4);

  utf8_ptr=utf8_buffer;

  switch(sz_utf8_buffer)
  {
   case 4: (*dest)=(*utf8_ptr);
           ++dest;
           ++utf8_ptr;

   case 3: (*dest)=(*utf8_ptr);
           ++dest;
           ++utf8_ptr;

   case 2: (*dest)=(*utf8_ptr);
           ++dest;
           ++utf8_ptr;

   case 1: (*dest)=(*utf8_ptr);
           ++dest;
           ++utf8_ptr;
  }//switch

  assert(utf8_ptr==(utf8_buffer+sz_utf8_buffer));
 }//while

 return source_beg;
}//ucs2_to_utf8

////////////////////////////////////////////////////////////////////////////////
//char sequential utf8-->ucs2 converter

template<class TForwardIterator,class TDestIterator>
TForwardIterator utf8_to_ucs2(TForwardIterator              source_beg,
                              TForwardIterator              source_end,
                              TDestIterator                 dest,
                              /*out*/t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result);
 
 (*cvt_result)=cs_cvt_result__ok;

 traits::UCS2 ucs2_buffer[2];
 
 size_t sz_ucs2_buffer;

 const traits::UCS2* ucs2_ptr;

 while(source_beg!=source_end)
 {
  source_beg=single_utf8_to_ucs2(source_beg,
                                 source_end,
                                 ucs2_buffer,
                                 sz_ucs2_buffer=_DIM_(ucs2_buffer),
                                 cvt_result);

  if((*cvt_result)!=cs_cvt_result__ok)
  {
   assert(sz_ucs2_buffer==0);
   
   break;
  }//if

  assert(sz_ucs2_buffer>=1);
  assert(sz_ucs2_buffer<=2);

  ucs2_ptr=ucs2_buffer;

  switch(sz_ucs2_buffer)
  {
   case 2: (*dest)=(*ucs2_ptr);
           ++dest;
           ++ucs2_ptr;

   case 1: (*dest)=(*ucs2_ptr);
           ++dest;
           ++ucs2_ptr;
  }//switch

  assert(ucs2_ptr==(ucs2_buffer+sz_ucs2_buffer));
 }//while

 return source_beg; 
}//utf8_to_ucs2

////////////////////////////////////////////////////////////////////////////////
}/*nms cs_utf8*/}/*charsets*/}/*nms structure*/
#endif
