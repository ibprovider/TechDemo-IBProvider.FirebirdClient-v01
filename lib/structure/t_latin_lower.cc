////////////////////////////////////////////////////////////////////////////////
#ifndef _lcpi_lib_structure__t_latin_lower_CC_
#define _lcpi_lib_structure__t_latin_lower_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<typename charT>
inline charT latin_lower(charT const c)
{
 using ct2=t_char_traits2<charT>;

 if(c>=ct2::ch_letter_A() && c<=ct2::ch_letter_Z())
  return static_cast<charT>(c-ct2::ch_letter_A()+ct2::ch_letter_a());

 return c;
}//latin_lower

////////////////////////////////////////////////////////////////////////////////
//class t_latin_lower

template<typename charT>
inline t_latin_lower<charT>::t_latin_lower()
{
}

//------------------------------------------------------------------------
template<typename charT>
inline typename t_latin_lower<charT>::char_type
 t_latin_lower<charT>::operator () (char_type const c)const
{
 return latin_lower(c);
}//operator ()

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
