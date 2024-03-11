////////////////////////////////////////////////////////////////////////////////
#ifndef _t_str_version_CC_
#define _t_str_version_CC_

#include <structure/t_char_traits2.h>
#include <stdexcept>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//unpack versions parts

template<class charT,class containerT>
bool get_str_version_parts_v2(const charT* const ver,
                              containerT*  const ver_parts) //throw
{
 assert(ver_parts);
 
 return get_str_version_parts_v2
         (make_str_box(ver),
          ver_parts);
}//get_str_version_parts

//------------------------------------------------------------------------
template<class charT,class containerT>
bool get_str_version_parts_v2(t_basic_const_str_box<charT> const ver,
                              containerT*                  const ver_parts) //throw
{
 assert(ver_parts);

 using string_type=LCPI_STL_DEF_BASIC_STRING(charT);

 using ch_traits2=t_char_traits2<charT>;

 using box_type=t_basic_const_str_box<charT>;

 typename box_type::iterator        i(ver.begin());
 typename box_type::iterator const _e(ver.end());

 if(i==_e)
  return true; //empty string. at current time, we will allow this case

 for(;;)
 {
  assert(i!=_e);

  if(!ch_traits2::is_digit(*i))
   return false; //bad version format

  //get number
  typename box_type::iterator sv=i;

  for(;;)
  {
   ++i;

   if(i==_e)
    break;

   if(!ch_traits2::is_digit(*i))
    break;

   if((*sv)==ch_traits2::ch_0()) //skip the zeros in head
    sv=i;
  }//for[ever]

  ver_parts->push_back(string_type(sv,i));

  if(i==_e)
   return true;

  if((*i)!=ch_traits2::ch_point())
   return false;  //bad version format

  //skeep point
  ++i;

  if(i==_e)
   return false; //bad format
 }//for[ever]
}//get_str_version_parts_v2

////////////////////////////////////////////////////////////////////////////////
//class t_str_version_part

template<class charT>
RELEASE_CODE(inline)
t_str_version_part<charT>::t_str_version_part(const self_type& x)
 :m_value(x.m_value)
{
 assert(!m_value.empty());
}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT>
RELEASE_CODE(inline)
t_str_version_part<charT>::t_str_version_part(self_type&& x)
 :m_value(LCPI_STL_MOVE_VALUE(x.m_value))
{
 assert(!m_value.empty());
}

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class charT>
RELEASE_CODE(inline)
t_str_version_part<charT>::t_str_version_part(const string_type& x)
 :m_value(x)
{
 assert(!m_value.empty());
}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT>
RELEASE_CODE(inline)
t_str_version_part<charT>::t_str_version_part(string_type&& x)
 :m_value(LCPI_STL_MOVE_VALUE(x))
{
 assert(!m_value.empty());
}

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE

//------------------------------------------------------------------------
template<class charT>
t_str_version_part<charT>& t_str_version_part<charT>::operator = (const self_type& x)
{
 self_type tmp(x);

 this->swap(tmp);

 assert(!m_value.empty());

 return *this;
}//copy operator

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT>
t_str_version_part<charT>& t_str_version_part<charT>::operator = (self_type&& x)
{
 self_type tmp(LCPI_STL_MOVE_VALUE(x));

 this->swap(tmp);

 assert(!m_value.empty());

 return *this;
}//move operator

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE

//------------------------------------------------------------------------
template<class charT>
RELEASE_CODE(inline)
void t_str_version_part<charT>::swap(self_type& x)
{
 m_value.swap(x.m_value);
}//swap

//------------------------------------------------------------------------
template<class charT>
inline const typename t_str_version_part<charT>::string_type&
 t_str_version_part<charT>::value()const
{
 return m_value;
}//value

//------------------------------------------------------------------------
template<class charT>
inline bool t_str_version_part<charT>::is_zero()const
{
 assert(!m_value.empty());

 if(m_value.size()!=1)
  return false;

 return m_value[0]==structure::t_char_traits2<char_type>::ch_0();
}//is_empty

////////////////////////////////////////////////////////////////////////////////
//class t_str_version

template<class charT,class Allocator>
inline t_str_version<charT,Allocator>::t_str_version()
{;}

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline t_str_version<charT,Allocator>::t_str_version(const self_type& x)
 :m_parts(x.m_parts)
{;}

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline t_str_version<charT,Allocator>::t_str_version(str_box_type const str)
{
 this->internal_init(str);//throw
}

//------------------------------------------------------------------------
template<class charT,class Allocator>
t_str_version<charT,Allocator>&
 t_str_version<charT,Allocator>::operator = (const self_type& x)
{
 self_type tmp(x);

 this->swap(tmp);

 return *this;
}//operator =

//------------------------------------------------------------------------
template<class charT,class Allocator>
t_str_version<charT,Allocator>&
 t_str_version<charT,Allocator>::operator = (str_box_type const str)
{
 self_type tmp(str);

 this->swap(tmp);

 return *this;
}//operator =

//iterators --------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_str_version<charT,Allocator>::const_iterator
 t_str_version<charT,Allocator>::begin()const
{
 return m_parts.begin();
}//begin

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_str_version<charT,Allocator>::const_iterator
 t_str_version<charT,Allocator>::end()const
{
 return m_parts.end();
}//end

//selectors --------------------------------------------------------------
template<class charT,class Allocator>
inline bool
 t_str_version<charT,Allocator>::empty()const
{
 return m_parts.empty();
}//empty

//selectors --------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_str_version<charT,Allocator>::size_type
 t_str_version<charT,Allocator>::size()const
{
 return m_parts.size();
}//size

//------------------------------------------------------------------------
template<class charT,class Allocator>
RELEASE_CODE(inline)
typename t_str_version<charT,Allocator>::const_reference
 t_str_version<charT,Allocator>::operator [] (size_type i)const
{
 assert_msg(i<m_parts.size(),"i="<<i<<" size="<<m_parts.size());

 return m_parts[i];
}

//------------------------------------------------------------------------
template<class charT,class Allocator>
typename t_str_version<charT,Allocator>::string_type
 t_str_version<charT,Allocator>::str()const
{
 string_type s;

 s.reserve(5*this->size()); //xxxxx.xxxxx.xxxxx.....

 for(const_iterator i(this->begin()),_e(this->end());i!=_e;++i)
 {
  if(!s.empty())
   s+=t_char_traits2<char_type>::ch_point();

  s+=(*i).value();
 }

 return s;
}//str

//------------------------------------------------------------------------
template<class charT,class Allocator>
RELEASE_CODE(inline)
void t_str_version<charT,Allocator>::swap(self_type& x)
{
 m_parts.swap(x.m_parts);
}//swap

//------------------------------------------------------------------------
template<class charT,class Allocator>
void t_str_version<charT,Allocator>::internal_init(str_box_type const str)//throw
{
 if(!get_str_version_parts_v2(str,&m_parts))
 {
  throw std::runtime_error("can't process version string.");
 }
}//internal_init

////////////////////////////////////////////////////////////////////////////////
//external operators

template<class charT,class Allocator>
inline bool operator == (const t_str_version<charT,Allocator>& v1,
                         const t_str_version<charT,Allocator>& v2)
{
 return (v1.size()==v2.size()) && std::equal(v1.begin(),
                                             v1.end(),
                                             v2.begin());
}//operator ==

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool operator != (const t_str_version<charT,Allocator>& v1,
                         const t_str_version<charT,Allocator>& v2)
{
 return !(v1==v2);
}//operator !=

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool operator < (const t_str_version<charT,Allocator>& v1,
                        const t_str_version<charT,Allocator>& v2)
{
 return std::lexicographical_compare(v1.begin(),
                                     v1.end(),
                                     v2.begin(),
                                     v2.end());
}//operator <

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool operator > (const t_str_version<charT,Allocator>& v1,
                        const t_str_version<charT,Allocator>& v2)
{
 return v2<v1;
}//operator >

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool operator <= (const t_str_version<charT,Allocator>& v1,
                         const t_str_version<charT,Allocator>& v2)
{
 return !(v2<v1);
}//operator <=

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool operator >= (const t_str_version<charT,Allocator>& v1,
                         const t_str_version<charT,Allocator>& v2)
{
 return !(v1<v2);
}//operator >=

////////////////////////////////////////////////////////////////////////////////
//test version prefix

template<class charT,class Allocator>
int cmp_str_version_prefix(const t_str_version<charT,Allocator>& ver,
                           const t_str_version<charT,Allocator>& prefix)
{
 typedef t_str_version<charT,Allocator> ver_type;

 typename ver_type::const_iterator i_ver(ver.begin());
 typename ver_type::const_iterator e_ver(ver.end());

 typename ver_type::const_iterator i_prefix(prefix.begin());
 typename ver_type::const_iterator e_prefix(prefix.end());

 for(;;++i_ver,++i_prefix)
 {
  if(i_prefix==e_prefix)
   return 0;

  assert(i_prefix!=e_prefix);

  if(i_ver==e_ver)
  {
   for(;;++i_prefix)
   {
    if(i_prefix==e_prefix)
     return 0;

    if(!(*i_prefix).is_zero())
     return -1;
   }//for
  }//if i_ver==e_ver

  assert(i_ver!=e_ver);

  if((*i_ver)<(*i_prefix))
   return -1;

  if((*i_prefix)<(*i_ver))
   return 1; //prefix less that version
 }//for[ever]
}//cmp_str_version_prefix

//------------------------------------------------------------------------
template<class charT,class Allocator>
int cmp_str_version_prefix(const t_str_version<charT,Allocator>& ver,
                           const charT* const                    prefix)
{
 typedef t_str_version<charT,Allocator> ver_type;

 return cmp_str_version_prefix(ver,ver_type(prefix));
}//cmp_str_version_prefix

//------------------------------------------------------------------------
template<class charT>
int cmp_str_version_prefix(const charT* const ver,
                           const charT* const prefix)
{
 typedef t_str_version<charT> ver_type;

 return cmp_str_version_prefix(ver_type(ver),ver_type(prefix));
}//cmp_str_version_prefix

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool eq_str_version_prefix(const t_str_version<charT,Allocator>& ver,
                           const t_str_version<charT,Allocator>& prefix)
{
 typedef t_str_version<charT,Allocator> ver_type;

 typename ver_type::const_iterator i_ver(ver.begin());
 typename ver_type::const_iterator e_ver(ver.end());

 typename ver_type::const_iterator i_prefix(prefix.begin());
 typename ver_type::const_iterator e_prefix(prefix.end());

 for(;i_ver!=e_ver;++i_ver,++i_prefix)
 {
  if(i_prefix==e_prefix)
   return true;

  if((*i_ver)<(*i_prefix))
   return false;

  if((*i_prefix)<(*i_ver))
   return false; //prefix less that version
 }//for

 assert(i_ver==e_ver);

 for(;;++i_prefix)
 {
  if(i_prefix==e_prefix)
   return true;

  if(!(*i_prefix).is_zero())
   return false;
 }//for[ever]
}//eq_str_version_prefix

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool eq_str_version_prefix(const t_str_version<charT,Allocator>& ver,
                           const charT* const                    prefix)
{
 typedef t_str_version<charT,Allocator> ver_type;

 return eq_str_version_prefix(ver,ver_type(prefix));
}//eq_str_version_prefix

//------------------------------------------------------------------------
template<class charT>
bool eq_str_version_prefix(const charT* const ver,
                           const charT* const prefix)
{
 typedef t_str_version<charT> ver_type;

 return eq_str_version_prefix(ver_type(ver),ver_type(prefix));
}//eq_str_version_prefix

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
