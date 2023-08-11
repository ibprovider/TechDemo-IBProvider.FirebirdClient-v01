////////////////////////////////////////////////////////////////////////////////
//Structures for work with UTF16 charset.
//                                                 Kovalenko Dmitry. 10.03.2023.
#ifndef _structure_charsets_t_cs_utf16_CC_
#define _structure_charsets_t_cs_utf16_CC_

#include <limits>

namespace structure{namespace charsets{namespace cs_utf16{
////////////////////////////////////////////////////////////////////////////////

inline bool is_surrogate_high(traits::UTF16 ch)
{
 if(ch<traits::c_SURROGATE_HIGH_START)
  return false;

 if(traits::c_SURROGATE_HIGH_END<ch)
  return false;

 return true;
}//is_surrogate_high

//-----------------------------------------------------------------------
inline bool is_surrogate_low(traits::UTF16 ch)
{
 if(ch<traits::c_SURROGATE_LOW_START)
  return false;

 if(traits::c_SURROGATE_LOW_END<ch)
  return false;

 return true;
}//is_surrogate_low

////////////////////////////////////////////////////////////////////////////////

template<class TForwardIterator>
std::pair<TForwardIterator,t_cs_cvt_result>
 get_next_symbol(TForwardIterator source_beg,
                 TForwardIterator source_end)
{
 assert(source_beg!=source_end);

 const auto start=source_beg;

 const traits::UTF16 ch1=*source_beg;

 if(!is_surrogate_high(ch1))
 {
  if(!is_surrogate_low(ch1))
  {
   //ok

   return std::make_pair(++source_beg,cs_cvt_result__ok);
  }//if

  return std::make_pair(source_beg,cs_cvt_result__bad_input);
 }//if

 assert(is_surrogate_high(ch1));

 ++source_beg;

 if(source_beg==source_end)
 {
  return std::make_pair(start,cs_cvt_result__trunc_input);
 }//if

 const traits::UTF16 ch2=*source_beg;

 if(is_surrogate_low(ch2))
 {
  //ok

  return std::make_pair(++source_beg,cs_cvt_result__ok);
 }//if

 return std::make_pair(start,cs_cvt_result__bad_input);
}//get_next_symbol

////////////////////////////////////////////////////////////////////////////////

template<class TForwardIterator>
std::pair<size_t,t_cs_cvt_result>
 calc_symbol_count(TForwardIterator source_beg,
                   TForwardIterator source_end,
                   size_t     const max_length)
{
 size_t total_sz=0;

 for(;source_beg!=source_end;++source_beg)
 {
  const traits::UTF16 ch1=*source_beg;

  if(!is_surrogate_high(ch1))
  {
   if(!is_surrogate_low(ch1))
   {
    //ok
   }
   else
   {
    return std::make_pair(0,cs_cvt_result__bad_input);
   }//else
  }
  else
  {
   assert(is_surrogate_high(ch1));

   ++source_beg;

   if(source_beg==source_end)
   {
    return std::make_pair(0,cs_cvt_result__trunc_input);
   }

   const traits::UTF16 ch2=*source_beg;

   if(is_surrogate_low(ch2))
   {
    //ok
   }
   else
   {
    return std::make_pair(0,cs_cvt_result__bad_input);
   }//else
  }//else

  if(total_sz==max_length)
   return std::make_pair(0,cs_cvt_result__overflow);

  ++total_sz;
 }//for source_beg

 return std::make_pair(total_sz,cs_cvt_result__ok);
}//calc_symbol_count

//------------------------------------------------------------------------
template<class TForwardIterator>
std::pair<size_t,t_cs_cvt_result>
 calc_symbol_count(TForwardIterator source_beg,
                   TForwardIterator source_end)
{
 return calc_symbol_count
         (source_beg,
          source_end,
          (std::numeric_limits<size_t>::max)());
}//calc_symbol_count

////////////////////////////////////////////////////////////////////////////////
}/*nms cs_utf16*/}/*charsets*/}/*nms structure*/
#endif
