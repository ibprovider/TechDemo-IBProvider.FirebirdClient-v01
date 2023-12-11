////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_locale_services.cc
//! \brief   Набор утилит для работы с локалями
//! \author  Kovalenko Dmitry
//! \date    03.11.2009
#ifndef _ibp_local_services_CC_
#define _ibp_local_services_CC_

#include <structure/t_latin_lower.h>
#include <structure/t_latin_upper.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_basic_locale_services

template<typename charT>
t_ibp_basic_locale_services<charT>::t_ibp_basic_locale_services()
{;}

//------------------------------------------------------------------------
template<typename charT>
t_ibp_basic_locale_services<charT>::~t_ibp_basic_locale_services()
{;}

//interface --------------------------------------------------------------

template<typename charT>
inline
bool t_ibp_basic_locale_services<charT>::isalpha(char_type const c)const
{
 return char_traits2::is_alpha(c);
}//isalpha

//------------------------------------------------------------------------
template<typename charT>
inline
bool t_ibp_basic_locale_services<charT>::isalnum(char_type const c)const
{
 return char_traits2::is_alnum(c);
}//isalnum

//------------------------------------------------------------------------
template<typename charT>
inline
bool t_ibp_basic_locale_services<charT>::isdigit(char_type const c)const
{
 return char_traits2::is_digit(c);
}//isalnum

//------------------------------------------------------------------------
template<typename charT>
inline typename t_ibp_basic_locale_services<charT>::char_type
 t_ibp_basic_locale_services<charT>::toupper_char(char_type const c)const
{
 return structure::latin_upper(c);
}//toupper_char

//------------------------------------------------------------------------
template<typename charT>
void t_ibp_basic_locale_services<charT>::toupper_str(string_type* const pstr)const
{
 assert(pstr);

 for(typename string_type::iterator i(pstr->begin()),_e(pstr->end());i!=_e;++i)
 {
  (*i)=self_type::toupper_char(*i);
 }//for
}//toupper_str

//------------------------------------------------------------------------
template<typename charT>
inline
typename t_ibp_basic_locale_services<charT>::char_type
 t_ibp_basic_locale_services<charT>::tolower_char(char_type const c)const
{
 return structure::latin_lower(c);
}//tolower_char

//------------------------------------------------------------------------
template<typename charT>
void t_ibp_basic_locale_services<charT>::tolower_str(string_type* const pstr)const
{
 assert(pstr);

 for(typename string_type::iterator i(pstr->begin()),_e(pstr->end());i!=_e;++i)
 {
  (*i)=self_type::tolower_char(*i);
 }//for
}//tolower_str

//------------------------------------------------------------------------
template<typename charT>
inline
int t_ibp_basic_locale_services<charT>::char_compare_i(char_type const c1,
                                                       char_type const c2)const
{
 return int(self_type::tolower_char(c1))-int(self_type::tolower_char(c2));
}//char_compare_i

//------------------------------------------------------------------------
template<typename charT>
inline
int t_ibp_basic_locale_services<charT>::string_compare_i
                                           (const string_type& s1,
                                            const string_type& s2)const
{
 return this->string_compare_i(s1.c_str(),
                               s1.size(),
                               s2.c_str(),
                               s2.size());
}//string_compare_i

//------------------------------------------------------------------------
template<typename charT>
int t_ibp_basic_locale_services<charT>::string_compare_i
                                           (const char_type* s1,
                                            size_type        n1,
                                            const char_type* s2,
                                            size_type        n2)const
{
 CHECK_READ_TYPED_PTR(s1,n1)
 CHECK_READ_TYPED_PTR(s2,n2)

 for(;;++s1,--n1,++s2,--n2)
 {
  if(n1==0)
  {
   if(n2==0)
    return 0;

   return -1;
  }//if

  if(n2==0)
   return 1;

  if(int const x=this->char_compare_i(*s1,*s2))
   return x;
 }//for[ever]
}//string_compare_i

//------------------------------------------------------------------------
template<typename charT>
RELEASE_CODE(inline)
bool t_ibp_basic_locale_services<charT>::eq_to_char_i(char_type const c1,
                                                      char_type const c2)const
{
 return self_type::tolower_char(c1)==self_type::tolower_char(c2);
}//eq_to_char_i

//------------------------------------------------------------------------
template<typename charT>
bool t_ibp_basic_locale_services<charT>::eq_to_str_i
                                           (const char_type* s1,
                                            size_type        n1,
                                            const char_type* s2)const
{
 CHECK_READ_TYPED_PTR(s1,n1)
 assert(s2!=NULL);

 if(s2==NULL)
  s2=structure::t_char_traits2<char_type>::str_empty();

 assert(s2!=NULL);

 for(;(*s2)!=0 && n1!=0;++s1,++s2,--n1)
 {
  if(!self_type::eq_to_char_i(*s1,*s2))
   return false;
 }//for

 return n1==0 && (*s2)==0;
}//eq_to_str_n_i

//------------------------------------------------------------------------
template<typename charT>
bool t_ibp_basic_locale_services<charT>::eq_to_str_i
                                           (const char_type* s1,
                                            const char_type* s2)const
{
 assert(s1);
 assert(s2);

 if(s1==NULL)
  s1=structure::t_char_traits2<char_type>::str_empty();

 assert(s1!=NULL);

 if(s2==NULL)
  s2=structure::t_char_traits2<char_type>::str_empty();

 assert(s2!=NULL);

 for(;(*s1)!=0 && (*s2)!=0;++s1,++s2)
 {
  if(!self_type::eq_to_char_i(*s1,*s2))
   return false;
 }//for

 return (*s1)==0 && (*s2)==0;
}//eq_to_str_i

//------------------------------------------------------------------------
template<typename charT>
template<typename Iterator>
bool t_ibp_basic_locale_services<charT>::eq_to_str_i(Iterator         first1,
                                                     Iterator   const last1,
                                                     const char_type* s2)const
{
 if(s2==NULL)
  s2=structure::t_char_traits2<char_type>::str_empty();

 assert(s2!=NULL);

 for(;(*s2)!=0 && first1!=last1;++first1,++s2)
 {
  if(!self_type::eq_to_char_i(*first1,*s2))
   return false;
 }//for

 return first1==last1 && (*s2)==0;
}//eq_to_str_i

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_basic_equal_char_i

template<typename charT>
t_ibp_basic_equal_char_i<charT>::t_ibp_basic_equal_char_i
                              (const locale_services_type* const pLocaleServices)
 :m_spLocaleServices(lib::structure::not_null_ptr(pLocaleServices))
{
 assert(m_spLocaleServices);
}

//------------------------------------------------------------------------
template<typename charT>
t_ibp_basic_equal_char_i<charT>::~t_ibp_basic_equal_char_i()
{;}

//------------------------------------------------------------------------
template<typename charT>
RELEASE_CODE(inline)
bool t_ibp_basic_equal_char_i<charT>::operator () (char_type const c1,
                                                   char_type const c2)const
{
 assert(m_spLocaleServices);

 return m_spLocaleServices->tolower_char(c1)==m_spLocaleServices->tolower_char(c2);
}//operator

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
