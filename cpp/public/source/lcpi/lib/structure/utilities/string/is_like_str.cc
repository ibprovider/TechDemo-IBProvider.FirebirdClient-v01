////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 23.11.2022
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__is_like_str_CC_
#define _cpp_public_lcpi_lib_structure_utilities__string__is_like_str_CC_

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

//
// Limitiation:
//  You can't define in a pattern the 'any_sym' and 'any_seq' symbols for
//  the search them as is in source string. These are special symbols which
//  will be processed by the special methods.
//

template<typename charT,typename StringIteratorT,typename PatterIteratorT>
bool is_like_str(charT           const any_sym,
                 charT           const any_seq,
                 StringIteratorT const b_str,
                 StringIteratorT const e_str,
                 PatterIteratorT const b_pattern,
                 PatterIteratorT const e_pattern)
{
 // the base idea was gotten from leecode

 PatterIteratorT  patPos=b_pattern;
 StringIteratorT  strPos=b_str;

 bool canRestart=false;

 PatterIteratorT  restart_patPos =PatterIteratorT();
 StringIteratorT  restart_strPos =StringIteratorT();

 for(;;)
 {
  if(strPos==e_str)
   break;

  if(patPos!=e_pattern)
  {
   if((*patPos)==any_seq)
   {
    ++patPos;

    canRestart=true;

    restart_patPos=patPos; // <-- next after any_seq!
    restart_strPos=strPos;

    continue;
   }//if

   if((*patPos)==any_sym || (*strPos)==(*patPos))
   {
    ++patPos;

    ++strPos;

    continue;
   }//if
  }//if patPos!=e_templ

  if(canRestart)
  {
   patPos=restart_patPos;

   ++restart_strPos;

   strPos=restart_strPos;

   continue;
  }//if

  return false;
 }//for[ever]

 for(;patPos!=e_pattern && (*patPos)==any_seq;++patPos);

 return strPos==e_str && patPos==e_pattern;
}//is_like_str

//------------------------------------------------------------------------
template<typename charT,class stringT,class patternT>
bool is_like_str(charT    const  any_sym,
                 charT    const  any_seq,
                 const stringT&  str,
                 const patternT& pattern)
{
 return is_like_str
         (any_sym,
          any_seq,
          str.begin(),
          str.end(),
          pattern.begin(),
          pattern.end());
}//is_like_str

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif