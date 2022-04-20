////////////////////////////////////////////////////////////////////////////////
//implementation of <structure/charsets/t_utf_fss.h>

#ifndef _structure_charsets_t_cs_utf_fss_CC_
#define _structure_charsets_t_cs_utf_fss_CC_

namespace structure{namespace charsets{namespace cs_utf_fss{
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
*  символы UNICODE_FSS содержат максимум 3 байта
*/

////////////////////////////////////////////////////////////////////////////////
//single ucs to utf_fss convertor

template<class TForwardIterator>
TForwardIterator __single_ucs2_to_fss(TForwardIterator       source_beg,
                                      TForwardIterator       source_end,
                                      traits::UTF_FSS*       utf_fss,
                                      size_t&                sz_utf_fss,
                                      t_cs_cvt_result* const cvt_result)
{ 
 assert(cvt_result!=NULL);
 assert(utf_fss!=NULL || sz_utf_fss==0);

 CHECK_WRITE_TYPED_PTR(utf_fss,sz_utf_fss);

 //-----------------------------------------
 typedef traits::UTF_FSS        UTF_FSS;
 typedef traits::UCS2           UCS2;

 //consts ----------------------------------
 const UCS2 c_byteMask          = 0xBF; //1011 1111
 const UCS2 c_byteMark          = 0x80; //1000 0000

 //-----------------------------------------
 const size_t original_sz_utf_fss=sz_utf_fss;

 sz_utf_fss=0;

 if(source_beg==source_end)
 {
  (*cvt_result)=cs_cvt_result__ok;
  
  return source_beg;
 }//if

 //-----------------------------------------------------------------------
 UCS2 wc=*source_beg;

 if(wc<0x0080)
 {
  //1 byte sequence

  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*   7  00000000 0000007F 0vvvvvvv

  ++source_beg;

  sz_utf_fss=1;                             // <---!!!

  if(utf_fss!=NULL)
  {
   if(original_sz_utf_fss<1)                // <---!!!
   {
    (*cvt_result)=cs_cvt_result__small_output;
  
    return source_beg;
   }//if

   utf_fss[0]=static_cast<UTF_FSS>(wc);
  }//if utf_fss!=NULL

  //----------------------------------------
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//if

 assert(!(wc<0x0080));

 //-----------------------------------------------------------------------
 if(wc<0x0800)
 {
  //2 byte sequence
  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*  11  00000080 000007FF 110vvvvv 10vvvvvv

  ++source_beg;

  sz_utf_fss=2;                             // <---!!!

  if(utf_fss!=NULL)
  {
   if(original_sz_utf_fss<2)                // <---!!!
   {
    (*cvt_result)=cs_cvt_result__small_output;
  
    return source_beg;
   }//if

   utf_fss[1]=static_cast<UTF_FSS>((wc | c_byteMark) & c_byteMask);

   wc>>=6;

   utf_fss[0]=static_cast<traits::UTF_FSS>(wc | 0xC0);
  }//if utf_fss!=NULL

  //----------------------------------------
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//if
 
 assert(!(wc<0x0800));
 
 //-----------------------------------------------------------------------
 if(wc<0x10000)
 {
  //3 byte sequence
  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*  16  00000800 0000FFFF 1110vvvv 10vvvvvv 10vvvvvv

  ++source_beg;

  sz_utf_fss=3;                             // <---!!!

  if(utf_fss!=NULL)
  {
   if(original_sz_utf_fss<3)                // <---!!!
   {
    (*cvt_result)=cs_cvt_result__small_output;
  
    return source_beg;
   }//if

   utf_fss[2]=static_cast<UTF_FSS>((wc | c_byteMark) & c_byteMask);

   wc>>=6;

   utf_fss[1]=static_cast<UTF_FSS>((wc | c_byteMark) & c_byteMask);

   wc>>=6;

   utf_fss[0]=static_cast<UTF_FSS>(wc | 0xE0);
  }//if utf_fss!=NULL

  //----------------------------------------
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//if

 assert(!(wc<0x10000));

 //-----------------------------------------
 (*cvt_result)=cs_cvt_result__bad_input;

 return source_beg;
}//__single_ucs2_to_fss

//------------------------------------------------------------------------
template<class TForwardIterator>
inline
TForwardIterator single_ucs2_to_fss(TForwardIterator              source_beg,
                                    TForwardIterator              source_end,
                                    unsigned char*          const utf_fss,
                                    /*in-out*/size_t&             sz_utf_fss,
                                    /*out*/t_cs_cvt_result* const cvt_result)
{
 assert_s(sizeof(*utf_fss)==sizeof(traits::UTF_FSS));
 assert(cvt_result);

 return __single_ucs2_to_fss(source_beg,
                             source_end,
                             reinterpret_cast<traits::UTF_FSS*>(utf_fss),
                             sz_utf_fss,
                             cvt_result);
}//single_ucs2_to_fss - to UTF_FSS

//------------------------------------------------------------------------
template<class TForwardIterator>
inline
TForwardIterator single_ucs2_to_fss(TForwardIterator              source_beg,
                                    TForwardIterator              source_end,
                                    signed char*            const utf_fss,
                                    /*in-out*/size_t&             sz_utf_fss,
                                    /*out*/t_cs_cvt_result* const cvt_result)
{
 assert_s(sizeof(*utf_fss)==sizeof(traits::UTF_FSS));
 assert(cvt_result);

 return __single_ucs2_to_fss(source_beg,
                             source_end,
                             reinterpret_cast<traits::UTF_FSS*>(utf_fss),
                             sz_utf_fss,
                             cvt_result);
}//single_ucs2_to_fss - to UTF_FSS_s

//------------------------------------------------------------------------
template<class TForwardIterator>
inline
TForwardIterator single_ucs2_to_fss(TForwardIterator              source_beg,
                                    TForwardIterator              source_end,
                                    char*                   const utf_fss,
                                    /*in-out*/size_t&             sz_utf_fss,
                                    /*out*/t_cs_cvt_result* const cvt_result)
{
 assert_s(sizeof(*utf_fss)==sizeof(traits::UTF_FSS));
 assert(cvt_result);

 return __single_ucs2_to_fss(source_beg,
                             source_end,
                             reinterpret_cast<traits::UTF_FSS*>(utf_fss),
                             sz_utf_fss,
                             cvt_result);
}//single_ucs2_to_fss - to char

////////////////////////////////////////////////////////////////////////////////
//single FSS to UCS2

#define GET_FSS_CH2(fss_char)                              \
 if(source_beg==source_end)                                \
 {                                                         \
  (*cvt_result)=cs_cvt_result__trunc_input;                \
                                                           \
  return source_beg;                                       \
 }                                                         \
                                                           \
 const UTF_FSS fss_char=(((*source_beg)^0x80)&0xFF);       \
                                                           \
 if((fss_char&0xC0)!=0)                                    \
 {                                                         \
  (*cvt_result)=cs_cvt_result__bad_input;                  \
                                                           \
  return source_beg;                                       \
 }                                                         \
                                                           \
 ++source_beg;

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator single_fss_to_ucs2(TForwardIterator       source_beg,
                                    TForwardIterator       source_end,
                                    traits::UCS2*    const ucs2,
                                    size_t&                sz_ucs2,
                                    t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result);
 assert(ucs2!=NULL || sz_ucs2==0);

 CHECK_WRITE_TYPED_PTR(ucs2,sz_ucs2);

 //----------------------------------------
 typedef traits::UTF_FSS        UTF_FSS;
 typedef traits::UCS2           UCS2;

 //----------------------------------------
 const size_t original_sz_ucs2=sz_ucs2;

 sz_ucs2=0;

 if(source_beg==source_end) //пустая последовательность
 {
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//if

 //запоминаем первый байт utf8 последовательности
 const UTF_FSS c0=(*source_beg);

 //----------------------------------------
 if(static_cast<UTF_FSS>(c0&0x80)==0x00)
 {
  //1 byte sequential
  ++source_beg;  

  //корректность упаковки проверять не надо!

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
  }//if ucs2!=NULL
 }
 else
 if(static_cast<UTF_FSS>(c0&0xE0)==0xC0)
 {
  //2 byte sequential
  ++source_beg;
  
  GET_FSS_CH2(c1)

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
 }
 else
 if(static_cast<UTF_FSS>(c0&0xF0)==0xE0)
 {
  //3 byte sequential
  ++source_beg;
  
  GET_FSS_CH2(c1)
  GET_FSS_CH2(c2)

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
 }
 else
 {
  (*cvt_result)=cs_cvt_result__bad_input;
  
  return source_beg;
 }//else

 //-----------------------------------------
 (*cvt_result)=cs_cvt_result__ok;
 
 return source_beg;
}//single_fss_to_ucs2

//------------------------------------------------------------------------
#undef GET_FSS_CH2

////////////////////////////////////////////////////////////////////////////////
//char sequential ucs2<-->fss converter

template<class TForwardIterator,class TDestIterator>
TForwardIterator ucs2_to_fss(TForwardIterator       source_beg,
                             TForwardIterator       source_end,
                             TDestIterator          dest,
                             t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result!=NULL);

 (*cvt_result)=cs_cvt_result__ok;

 //-----------------------------------------
 traits::UTF_FSS fss_buffer[3];
 
 size_t sz_fss_buffer;

 const traits::UTF_FSS* fss_ptr;

 while(source_beg!=source_end)
 {
  source_beg=__single_ucs2_to_fss(source_beg,
                                  source_end,
                                  fss_buffer,
                                  sz_fss_buffer=_DIM_(fss_buffer),
                                  cvt_result);

  assert((*cvt_result)==cs_cvt_result__ok);

  assert(sz_fss_buffer>=1);
  assert(sz_fss_buffer<=3);

  fss_ptr=fss_buffer;

  switch(sz_fss_buffer)
  {
   case 3: (*dest)=(*fss_ptr);
           ++dest;
           ++fss_ptr;

   case 2: (*dest)=(*fss_ptr);
           ++dest;
           ++fss_ptr;

   case 1: (*dest)=(*fss_ptr);
           ++dest;
           ++fss_ptr;
  }//switch

  assert(fss_ptr==(fss_buffer+sz_fss_buffer));
 }//while

 return source_beg;
}//ucs2_to_fss

//------------------------------------------------------------------------
template<class TForwardIterator,class TDestIterator>
TForwardIterator fss_to_ucs2(TForwardIterator       source_beg,
                             TForwardIterator       source_end,
                             TDestIterator          dest,
                             t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result!=NULL);
 
 (*cvt_result)=cs_cvt_result__ok;

 traits::UCS2 ucs2_ch;
 
 size_t ucs2_count;

 while(source_beg!=source_end)
 {
  source_beg=single_fss_to_ucs2(source_beg,
                                source_end,
                                &ucs2_ch,
                                ucs2_count=1,
                                cvt_result);

  assert((*cvt_result)!=cs_cvt_result__small_output);
  
  if((*cvt_result)!=cs_cvt_result__ok)
  {
   assert(ucs2_count==0);
   
   break;
  }//if

  assert(ucs2_count==1);

  (*dest)=ucs2_ch;

  ++dest;
 }//while

 return source_beg; 
}//utf8_to_ucs2

////////////////////////////////////////////////////////////////////////////////
}/*nms cs_utf_fss*/}/*nms charsets*/}/*nms structure*/
#endif
