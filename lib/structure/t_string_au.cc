////////////////////////////////////////////////////////////////////////////////
#ifndef _t_string_au_CC_
#define _t_string_au_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_string_au

template<class stringT>
inline t_string_au<stringT>& t_string_au<stringT>::append(const self_type& x)
{
 m_str.append(x.m_str);

 return *this;
}//append

//-----------------------------------------------------------------------
template<class stringT>
inline t_string_au<stringT>& t_string_au<stringT>::append(const string_type& s)
{
 m_str.append(s);

 return *this;
}//append

//-----------------------------------------------------------------------
template<class stringT>
inline t_string_au<stringT>& t_string_au<stringT>::append(const char_type* const s,size_type const n)
{
 m_str.append(s?s:traits2_type::str_empty(),s?((n==-1)?traits_type::length(s):n):0);

 return *this;
}//append

//-----------------------------------------------------------------------
template<class stringT>
t_string_au<stringT>& t_string_au<stringT>::append(const other_string_type& s)
{
 string_type _s;

 m_str.append(tstr_to_tstr(_s,s));

 return *this;
}//append

//-----------------------------------------------------------------------
template<class stringT>
t_string_au<stringT>& t_string_au<stringT>::append(const other_char_type* const s,size_type const n)
{
 string_type _s;

 m_str.append(tstr_to_tstr(_s,s,n));

 return *this;
}//append

//------------------------------------------------------------------------
template<class stringT>
inline t_string_au<stringT>& t_string_au<stringT>::operator += (const self_type& x)
{
 return append(x);
}//+=

//------------------------------------------------------------------------
template<class stringT>
inline t_string_au<stringT>& t_string_au<stringT>::operator += (const string_type& s)
{
 return append(s);
}//+=

//------------------------------------------------------------------------
template<class stringT>
inline t_string_au<stringT>& t_string_au<stringT>::operator += (const char_type* const s)
{
 return append(s);
}//+=

//------------------------------------------------------------------------
template<class stringT>
inline t_string_au<stringT>& t_string_au<stringT>::operator += (const other_string_type& s)
{
 return append(s);
}//+=

//------------------------------------------------------------------------
template<class stringT>
inline t_string_au<stringT>& t_string_au<stringT>::operator += (const other_char_type* const s)
{
 return append(s);
}//+=

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
