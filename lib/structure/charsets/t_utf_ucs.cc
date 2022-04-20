////////////////////////////////////////////////////////////////////////////////
//implementation of <structure/charsets/t_utf_ucs.h>

#ifndef _structure_charsets_t_utf_ucs_CC_
#define _structure_charsets_t_utf_ucs_CC_

namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//single ucs to utf convertor

template<class TForwardIterator>
TForwardIterator __single_ucs2_to_utf8(TForwardIterator       source_beg,
                                       TForwardIterator       source_end,
                                       t_utf8_traits::UTF8*   utf8,
                                       size_t&                sz_utf8,
                                       t_cs_cvt_result* const cvt_result)
{ 
 assert(cvt_result!=NULL);
 assert(utf8!=NULL || sz_utf8==0);

 CHECK_WRITE_TYPED_PTR(utf8,sz_utf8);

 const size_t sz_ucsValueStep  =_DIM_(t_utf8_traits::sm_utf8_ucs_map);
 const size_t original_sz_utf8 =sz_utf8;

 sz_utf8=0;

 if(source_beg==source_end)
 {
  (*cvt_result)=cs_cvt_result__ok;
  
  return source_beg;
 }//if

 t_utf8_traits::UCS4 wc=*source_beg;

 //detect size of utf8 sequential
 size_t result_sz;
 
 for(result_sz=1;
     ((result_sz!=sz_ucsValueStep) &&
      (wc>t_utf8_traits::sm_utf8_ucs_map[result_sz].lmask));
     ++result_sz);

 if(utf8!=NULL)
 {
  if(result_sz>original_sz_utf8)
  {
   (*cvt_result)=cs_cvt_result__small_output;
  
   return source_beg;
  }//if

  utf8+=result_sz;

  for(size_t i=1;i!=result_sz;++i)
  {
   (*(--utf8))=t_utf8_traits::UTF8((wc | t_utf8_traits::byteMark) & t_utf8_traits::byteMask);

   wc>>=6;
  }//for

  (*(--utf8))=t_utf8_traits::UTF8(wc | t_utf8_traits::sm_utf8_ucs_map[result_sz].cval);
 }//if utf8!=NULL

 sz_utf8=result_sz;

 (*cvt_result)=cs_cvt_result__ok;

 return ++source_beg;
}//__single_ucs2_to_utf8

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator __single_utf8_to_ucs2(TForwardIterator       source_beg,
                                       TForwardIterator       source_end,
                                       t_utf8_traits::UCS2*   ucs2,
                                       size_t&                sz_ucs2,
                                       t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result);
 assert(ucs2 || sz_ucs2==0);

 CHECK_WRITE_TYPED_PTR(ucs2,sz_ucs2);

 const t_utf8_traits::tag_utf8_ucs_map* const
  end_utf8_ucs_map=_END_(t_utf8_traits::sm_utf8_ucs_map);

 const size_t original_sz_ucs2 =sz_ucs2;

 sz_ucs2=0;

 if(source_beg==source_end) //нам не передали utf8 последовательность
 {
  (*cvt_result)=cs_cvt_result__ok;

  return source_beg;
 }//if

 //запоминаем первый байт utf8 последовательности
 const t_utf8_traits::UTF8 c0=(*source_beg);

 t_utf8_traits::UCS4 l=(c0&0xFF);

 if(l==0xFF)
 {
  //First byte can not be equal 0xFF
  
  (*cvt_result)=cs_cvt_result__bad_input;
  
  return source_beg;
 }//if

 for(const t_utf8_traits::tag_utf8_ucs_map* i_map=t_utf8_traits::sm_utf8_ucs_map+1;
     i_map!=end_utf8_ucs_map;
     ++i_map)
 {
  //последовательно сравниваем префикс первого байта
  if(static_cast<t_utf8_traits::UTF8>(c0&i_map->cmask)==i_map->cval)
  {
   //обрезаем лишние старшие биты (остались от c0)
   l=(l&i_map->lmask);

   //полученное число не должно быть меньше (проверяем корректность упаковки)
   if(l<i_map->lval)
   {
    (*cvt_result)=cs_cvt_result__bad_input;
    
    break;//return source_beg;
   }//if
   
   if(ucs2!=NULL)
   {
    //буфер получателя меньше допустимого?
    if(original_sz_ucs2<1)
    {
     (*cvt_result)=cs_cvt_result__small_output;
     
     break;//return source_beg;
    }//if

    //возвращаем сформированное UCS значение
    
    //TODO: обрабатывать ошибку переполнения!

    (*ucs2)=static_cast<t_utf8_traits::UCS2>(l);
   }//if ucs2!=NULL
   
   sz_ucs2=1;

   (*cvt_result)=cs_cvt_result__ok;
   
   return ++source_beg; //пропускаем последний обработанный байт UTF8 символа
  }//if

  //проверка длины UTF8 последовательности
  ++source_beg;
  
  if(source_beg==source_end)
  {
   (*cvt_result)=cs_cvt_result__trunc_input;
   
   break; //return source_beg;
  }//if
  
  //вытаскиваем префикс байта из последовательности
  const t_utf8_traits::UTF8 c=(((*source_beg)^0x80)&0xFF);
  
  //0xC0 == 1100 0000
  if((c&0xC0)!=0)
  {
   (*cvt_result)=cs_cvt_result__bad_input;

   //нарушен префикс дополнительного байта UTF8-цепочки 
   break; //return source_beg;
  }//if
  
  l=(l<<6)+c;
 }//for i_map

 return source_beg;
}//__single_utf8_to_ucs2

////////////////////////////////////////////////////////////////////////////////

template<class TForwardIterator>
inline TForwardIterator single_ucs2_to_utf8(TForwardIterator              source_beg,
                                            TForwardIterator              source_end,
                                            char*                   const utf8,
                                            /*in-out*/size_t&             sz_utf8,
                                            /*out*/t_cs_cvt_result* const cvt_result)
{
 return __single_ucs2_to_utf8(source_beg,source_end,
                              reinterpret_cast<t_utf8_traits::UTF8*>(utf8),
                              sz_utf8,
                              cvt_result);
}//single_ucs2_to_utf8

//------------------------------------------------------------------------
template<class TForwardIterator>
inline TForwardIterator single_utf8_to_ucs2(TForwardIterator              source_beg,
                                            TForwardIterator              source_end,
                                            wchar_t*                const ucs2,
                                            /*in-out*/size_t&             sz_ucs2,
                                            /*out*/t_cs_cvt_result* const cvt_result)
{
 return __single_utf8_to_ucs2(source_beg,source_end,
                              reinterpret_cast<t_utf8_traits::UCS2*>(ucs2),
                              sz_ucs2,
                              cvt_result);
}//single_utf8_to_ucs2

////////////////////////////////////////////////////////////////////////////////
//char sequential ucs2<-->utf8 converter

template<class TForwardIterator,class TDestIterator>
TForwardIterator ucs2_to_utf8(TForwardIterator       source_beg,
                              TForwardIterator       source_end,
                              TDestIterator          dest,
                              t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result!=NULL);

 t_utf8_traits::UTF8 utf8_buffer[32];
 
 size_t sz_utf8_buffer;

 size_t i_utf8_buffer;

 (*cvt_result)=cs_cvt_result__ok;

 while(source_beg!=source_end)
 {
  source_beg=__single_ucs2_to_utf8(source_beg,
                                   source_end,
                                   utf8_buffer,
                                   sz_utf8_buffer=_DIM_(utf8_buffer),
                                   cvt_result);

  if((*cvt_result)!=cs_cvt_result__ok)
   break;

  assert(sz_utf8_buffer<=_DIM_(utf8_buffer));

  for(i_utf8_buffer=0;i_utf8_buffer!=sz_utf8_buffer;++dest,++i_utf8_buffer)
   (*dest)=utf8_buffer[i_utf8_buffer];
 }//while

 return source_beg;
}//ucs2_to_utf8

//------------------------------------------------------------------------
template<class TForwardIterator,class TDestIterator>
TForwardIterator utf8_to_ucs2(TForwardIterator       source_beg,
                              TForwardIterator       source_end,
                              TDestIterator          dest,
                              t_cs_cvt_result* const cvt_result)
{
 assert(cvt_result!=NULL);
 
 t_utf8_traits::UCS2 ucs2_buffer[4];
 
 size_t sz_ucs2_buffer;

 size_t i_ucs2_buffer;

 (*cvt_result)=cs_cvt_result__ok;

 while(source_beg!=source_end)
 {
  source_beg=__single_utf8_to_ucs2(source_beg,
                                   source_end,
                                   ucs2_buffer,
                                   sz_ucs2_buffer=_DIM_(ucs2_buffer),
                                   cvt_result);

  if((*cvt_result)!=cs_cvt_result__ok)
   break;

  assert(sz_ucs2_buffer<=_DIM_(ucs2_buffer));

  for(i_ucs2_buffer=0;i_ucs2_buffer!=sz_ucs2_buffer;++dest,++i_ucs2_buffer)
   (*dest)=ucs2_buffer[i_ucs2_buffer];
 }//while

 return source_beg; 
}//utf8_to_ucs2

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}//nms structure
#endif
