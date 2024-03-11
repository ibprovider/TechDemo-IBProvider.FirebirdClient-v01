////////////////////////////////////////////////////////////////////////////////
#ifndef _t_dimension_iterator_CC_
#define _t_dimension_iterator_CC_

#include <structure/t_str_formatter.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_dimension_iterator::tag_range

template<class T,class Allocator>
RELEASE_CODE(inline)
t_dimension_iterator<T,Allocator>::tag_range::tag_range
                                           (value_type const _lower,
                                            value_type const _upper)
 :lower(_lower)
 ,upper(_upper)
{
 assert(test_range(_lower,_upper)!=range_is_bad);
}//tag_range

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
bool t_dimension_iterator<T,Allocator>::tag_range::empty()const
{
 assert(test_range(this->lower,this->upper)!=range_is_bad);

 return value_type(this->upper+1)==this->lower;
}//empty

////////////////////////////////////////////////////////////////////////////////
//class t_dimension_iterator

template<class T,class Allocator>
t_dimension_iterator<T,Allocator>::t_dimension_iterator()
 :m_state       (self_type::state_ok)
 ,m_no_elements (true)
{;}

//------------------------------------------------------------------------
template<class T,class Allocator>
t_dimension_iterator<T,Allocator>::t_dimension_iterator(const self_type& x)
 :m_pt          (x.m_pt)
 ,m_bounds      (x.m_bounds)
 ,m_state       (x.m_state)
 ,m_no_elements (x.m_no_elements)
{;}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class T,class Allocator>
t_dimension_iterator<T,Allocator>::t_dimension_iterator(self_type&& x)
 :m_pt          (LCPI_STL_MOVE_VALUE(x.m_pt))
 ,m_bounds      (LCPI_STL_MOVE_VALUE(x.m_bounds))
 ,m_state       (LCPI_STL_MOVE_VALUE(x.m_state))
 ,m_no_elements (LCPI_STL_MOVE_VALUE(x.m_no_elements))
{
 assert(x.m_bounds.empty());
 assert(x.m_pt.empty());

 x.clear();
}//t_dimension_iterator - move constructor

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class T,class Allocator>
t_dimension_iterator<T,Allocator>::~t_dimension_iterator()
{
}

//------------------------------------------------------------------------
template<class T,class Allocator>
t_dimension_iterator<T,Allocator>&
 t_dimension_iterator<T,Allocator>::operator = (const self_type& x)
{
 self_type __copy(x);

 return this->swap(__copy);
}//operator =

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class T,class Allocator>
t_dimension_iterator<T,Allocator>&
 t_dimension_iterator<T,Allocator>::operator = (self_type&& x)
{
 DEBUG_CODE(x.debug__self_check("move operator #001"));

 if(this==&x)
  return *this;

 m_bounds      =LCPI_STL_MOVE_VALUE(x.m_bounds);
 m_pt          =LCPI_STL_MOVE_VALUE(x.m_pt);
 m_state       =LCPI_STL_MOVE_VALUE(x.m_state);
 m_no_elements =LCPI_STL_MOVE_VALUE(x.m_no_elements);

 assert(x.m_bounds.empty());
 assert(x.m_pt.empty());

 x.clear();

 DEBUG_CODE(x.debug__self_check("move operator #002"));
 DEBUG_CODE(this->debug__self_check("move operator #003"));

 return *this;
}//move operator

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class T,class Allocator>
t_dimension_iterator<T,Allocator>&
 t_dimension_iterator<T,Allocator>::swap(self_type& x)
{
 m_pt       .swap(x.m_pt);
 m_bounds   .swap(x.m_bounds);

 std::swap(m_state       ,x.m_state);
 std::swap(m_no_elements ,x.m_no_elements);

 return *this;
}//swap

//test range -------------------------------------------------------------

template<class T,class Allocator>
typename t_dimension_iterator<T,Allocator>::test_range_result
 t_dimension_iterator<T,Allocator>::test_range(value_type const lower,
                                               value_type const upper)
{
 if(value_type(upper+1)==lower)
  return self_type::range_is_empty;

 if(lower<=upper)
  return self_type::range_is_not_empty;

 assert(upper<lower);

 return range_is_bad;
}//test_range

//dimension definiton ----------------------------------------------------
template<class T,class Allocator>
t_dimension_iterator<T,Allocator>&
 t_dimension_iterator<T,Allocator>::clear()
{
 m_pt.clear();
 m_bounds.clear();

 m_state=self_type::state_ok;

 m_no_elements=true;

 return *this;
}//clear

//------------------------------------------------------------------------
template<class T,class Allocator>
t_dimension_iterator<T,Allocator>&
 t_dimension_iterator<T,Allocator>::add(value_type const lower,
                                        value_type const upper)
{
 assert(test_range(lower,upper)!=self_type::range_is_bad);

 DEBUG_CODE(this->debug__self_check("add");)

 //-----------------------------------------
 m_bounds.push_back(range_type(lower,upper));

 try
 {
  m_pt.push_back(lower);
 }
 catch(...)
 {
  m_bounds.pop_back();
  throw;
 }//catch

 assert(!m_bounds.empty());

 if(m_bounds.size()==1)
 {
  m_no_elements=m_bounds.back().empty();
 }
 else
 if(m_bounds.back().empty())
 {
  m_no_elements=true;
 }//else-if

 m_state=self_type::state_ok;

 return *this;
}//add

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dimension_iterator<T,Allocator>::size_type
 t_dimension_iterator<T,Allocator>::dim()const
{
 DEBUG_CODE(this->debug__self_check("dim");)

 return m_pt.size();
}//dim

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
const typename t_dimension_iterator<T,Allocator>::value_type&
 t_dimension_iterator<T,Allocator>::get_lower_bound(size_type const i_dim)const
{
 assert(i_dim<m_bounds.size());

 return m_bounds[i_dim].lower;
}//get_lower_bound

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
const typename t_dimension_iterator<T,Allocator>::value_type&
 t_dimension_iterator<T,Allocator>::get_upper_bound(size_type const i_dim)const
{
 assert(i_dim<m_bounds.size());

 return m_bounds[i_dim].upper;
}//get_upper_bound

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
bool t_dimension_iterator<T,Allocator>::empty()const
{
 DEBUG_CODE(this->debug__self_check("empty");)

 return m_pt.empty();
}//empty

//dimension navigations --------------------------------------------------
template<class T,class Allocator>
bool t_dimension_iterator<T,Allocator>::ok()const
{
 if(m_state!=self_type::state_ok)
 {
  assert(m_state==self_type::state_bof ||
         m_state==self_type::state_eof);

  return false;
 }//if

 assert(m_state==self_type::state_ok);

 if(m_no_elements)
  return false;

 assert(!m_bounds.empty());
 assert(m_pt.size()==m_bounds.size());

 return true;
}//ok

//------------------------------------------------------------------------
template<class T,class Allocator>
bool t_dimension_iterator<T,Allocator>::bof()const
{
 return m_state==self_type::state_bof;
}//bof

//------------------------------------------------------------------------
template<class T,class Allocator>
bool t_dimension_iterator<T,Allocator>::eof()const
{
 if(m_state==self_type::state_bof)
  return false;

 if(m_state==self_type::state_eof)
  return true;

 assert(m_state==self_type::state_ok);

 if(m_no_elements)
  return true;

 assert(!m_bounds.empty());
 assert(m_pt.size()==m_bounds.size());

 return false;
}//eof

//------------------------------------------------------------------------
template<class T,class Allocator>
void t_dimension_iterator<T,Allocator>::restart()
{
 DEBUG_CODE(this->debug__self_check("restart");)

 for(typename bounds_type::size_type i=0,_c(m_bounds.size());i!=_c;++i)
  m_pt[i]=m_bounds[i].lower;

 m_state=self_type::state_ok;
}//restart

//------------------------------------------------------------------------
template<class T,class Allocator>
void t_dimension_iterator<T,Allocator>::restart_from_end()
{
 DEBUG_CODE(this->debug__self_check("restart_from_end");)

 for(typename bounds_type::size_type i=0,_c(m_bounds.size());i!=_c;++i)
  m_pt[i]=m_bounds[i].upper;

 m_state=self_type::state_ok;
}//restart_from_end

//------------------------------------------------------------------------
template<class T,class Allocator>
bool t_dimension_iterator<T,Allocator>::next()
{
 DEBUG_CODE(this->debug__self_check("next");)

 if(m_state==self_type::state_eof)
  return false;

 if(m_state==self_type::state_bof)
 {
  //exit from BOF

  if(m_no_elements)
  {
   m_state=self_type::state_eof;

   return false;
  }//if m_no_elements

  assert(!m_bounds.empty());
  assert(m_pt.size()==m_bounds.size());

 #ifndef NDEBUG
  for(typename point_type::size_type i(0),_c(m_pt.size());i!=_c;++i)
  {
   assert(!m_bounds[i].empty());

   assert(m_pt[i]==m_bounds[i].lower);
  }//for i
 #endif

  m_state=self_type::state_ok;

  return true;
 }//if m_state==self_type::state_bof

 assert(m_state==self_type::state_ok);

 if(m_no_elements)
 {
  m_state=self_type::state_eof;

  return false;
 }//if

 assert(!m_bounds.empty());
 assert(m_pt.size()==m_bounds.size());

 {
  size_type  x=0;
  size_type _c=m_pt.size();

  while(x!=_c)
  {
   assert(!m_bounds[x].empty());
   assert(m_bounds[x].lower<=m_pt[x]);
   assert(m_pt[x]<=m_bounds[x].upper);

   if(m_pt[x]<m_bounds[x].upper)
   {
    ++m_pt[x];

    break;
   }//if

   ++x;
  }//while x!=_c

  if(x==_c)
  {
   m_state=self_type::state_eof;

   return false;
  }//if x==_c

  assert(x<_c);

  while(x>0)
  {
   --x;

   m_pt[x]=m_bounds[x].lower;
  }//while
 }//local

 assert(m_state==self_type::state_ok);

 return true;
}//next

//------------------------------------------------------------------------
template<class T,class Allocator>
bool t_dimension_iterator<T,Allocator>::prev()
{
 DEBUG_CODE(this->debug__self_check("prev");)

 if(m_state==self_type::state_bof)
  return false;

 if(m_state==self_type::state_eof)
 {
  //exit from EOF

  if(m_no_elements)
  {
   m_state=self_type::state_bof;

   return false;
  }//if m_no_elements

  assert(!m_bounds.empty());
  assert(m_pt.size()==m_bounds.size());

 #ifndef NDEBUG
  for(typename point_type::size_type i(0),_c(m_pt.size());i!=_c;++i)
  {
   assert(!m_bounds[i].empty());

   assert(m_pt[i]==m_bounds[i].upper);
  }//for i
 #endif

  m_state=self_type::state_ok;

  return true;
 }//if m_state==self_type::state_eof

 assert(m_state==self_type::state_ok);

 if(m_no_elements)
 {
  m_state=self_type::state_bof;

  return false;
 }//if

 assert(!m_bounds.empty());
 assert(m_pt.size()==m_bounds.size());

 {
  size_type  x=0;
  size_type _c=m_pt.size();

  while(x!=_c)
  {
   assert(!m_bounds[x].empty());
   assert(m_bounds[x].lower<=m_pt[x]);
   assert(m_pt[x]<=m_bounds[x].upper);

   if(m_pt[x]>m_bounds[x].lower)
   {
    --m_pt[x];

    break;
   }//if

   ++x;
  }//while x!=_c

  if(x==_c)
  {
   m_state=self_type::state_bof;

   return false;
  }//if x==_c

  assert(x<_c);

  while(x>0)
  {
   --x;

   m_pt[x]=m_bounds[x].upper;
  }//while
 }//local

 assert(m_state==self_type::state_ok);

 return true;
}//prev

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
t_dimension_iterator<T,Allocator>&
 t_dimension_iterator<T,Allocator>::operator ++ ()
{
 assert(!this->eof());

 this->next();

 return *this;
}//operator ++

//------------------------------------------------------------------------
template<class T,class Allocator>
t_dimension_iterator<T,Allocator>
 t_dimension_iterator<T,Allocator>::operator ++ (int)
{
 assert(!this->eof());

 self_type tmp(*this);

 this->next();

 return tmp;
}//operator ++ (int)

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
t_dimension_iterator<T,Allocator>&
 t_dimension_iterator<T,Allocator>::operator -- ()
{
 assert(!this->bof());

 this->prev();

 return *this;
}//operator -- ()

//------------------------------------------------------------------------
template<class T,class Allocator>
t_dimension_iterator<T,Allocator>
 t_dimension_iterator<T,Allocator>::operator -- (int)
{
 assert(!this->bof());

 self_type tmp(*this);

 this->prev();

 return tmp;
}//operator -- (int)

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
t_dimension_iterator<T,Allocator>::operator bool () const
{
 DEBUG_CODE(this->debug__self_check("operator bool");)

 return this->ok();
}//operator bool

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
bool t_dimension_iterator<T,Allocator>::operator ! () const
{
 DEBUG_CODE(this->debug__self_check("operator !");)

 return !this->ok();
}//operator !

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
const typename t_dimension_iterator<T,Allocator>::point_type&
t_dimension_iterator<T,Allocator>::cur()const
{
 assert(this->ok());

 DEBUG_CODE(this->debug__self_check("cur");)

 return m_pt;
}//cur

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
const typename t_dimension_iterator<T,Allocator>::value_type&
t_dimension_iterator<T,Allocator>::operator [] (size_type const i_dim)const
{
 assert(i_dim<m_pt.size());

 assert(this->ok());

 DEBUG_CODE(this->debug__self_check("operator []");)

 return m_pt[i_dim];
}//operator []

//debug methods ----------------------------------------------------------

#ifndef NDEBUG

template<class T,class Allocator>
void t_dimension_iterator<T,Allocator>::debug__self_check(const char* const trace)const
{
 assert_msg(m_pt.size()==m_bounds.size(),
            trace<<"\n"
            "pt.size=="<<m_pt.size()<<"\n"
            "bounds.size=="<<m_bounds.size());

 for(typename point_type::size_type i(0),_c(m_pt.size());i!=_c;++i)
 {
  if(m_bounds[i].empty())
  {
   assert(m_pt[i]==m_bounds[i].lower);
  }
  else
  {
   assert(m_bounds[i].lower<=m_pt[i]);
   assert(m_pt[i]<=m_bounds[i].upper);
  }//else
 }//for i
}//debug__self_check

#endif //!defined NDEBUG

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
