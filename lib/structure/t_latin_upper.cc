////////////////////////////////////////////////////////////////////////////////
#ifndef _t_latin_upper_CC_
#define _t_latin_upper_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<typename charT>
inline charT latin_upper(charT const c)
{
 typedef t_char_traits2<charT>              ct2;

 if(c>=ct2::ch_letter_a() && c<=ct2::ch_letter_z())
  return static_cast<charT>(c-ct2::ch_letter_a()+ct2::ch_letter_A());

 return c;
}//latin_upper

////////////////////////////////////////////////////////////////////////////////
//class t_latin_upper

template<typename charT>
inline t_latin_upper<charT>::t_latin_upper()
{;}

//------------------------------------------------------------------------
template<typename charT>
inline typename t_latin_upper<charT>::char_type
 t_latin_upper<charT>::operator () (char_type const c)const
{
 return latin_upper(c);
}//operator ()

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
