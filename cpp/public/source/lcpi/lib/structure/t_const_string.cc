////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 03.10.2016.
#ifndef _cpp_public_lcpi_lib_structure__t_const_string_CC_
#define _cpp_public_lcpi_lib_structure__t_const_string_CC_

#include <structure/t_memory.h>  // [2022-10-25] temporary decision.
#include <limits>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

#ifndef COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001
# error COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001 not defined!
#endif

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string_data__static

template<typename charT,const charT* const staticSTR>
t_basic_const_string_data__static<charT,staticSTR>
 t_basic_const_string_data__static<charT,staticSTR>::sm_instance;

//------------------------------------------------------------------------
template<typename charT,const charT* const staticSTR>
t_basic_const_string_data__static<charT,staticSTR>::~t_basic_const_string_data__static()
{;}

//------------------------------------------------------------------------
template<typename charT,const charT* const staticSTR>
typename t_basic_const_string_data__static<charT,staticSTR>::self_ptr
 t_basic_const_string_data__static<charT,staticSTR>::create()
{
 return structure::not_null_ptr(&sm_instance);
}

//interface --------------------------------------------------------------
template<typename charT,const charT* const staticSTR>
typename t_basic_const_string_data__static<charT,staticSTR>::size_type
 t_basic_const_string_data__static<charT,staticSTR>::size()const
{
 return m_size;
}//size

//------------------------------------------------------------------------
template<typename charT,const charT* const staticSTR>
typename t_basic_const_string_data__static<charT,staticSTR>::const_pointer
 t_basic_const_string_data__static<charT,staticSTR>::data()const
{
 return staticSTR;
}//data

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string_data__dynamic

template<typename charT,class Allocator>
t_basic_const_string_data__dynamic<charT,Allocator>::~t_basic_const_string_data__dynamic()
{;}

//------------------------------------------------------------------------
template<typename charT,class Allocator>
typename t_basic_const_string_data__dynamic<charT,Allocator>::self_ptr
 typename t_basic_const_string_data__dynamic<charT,Allocator>::create
                                           (size_type     const sz,
                                            const_pointer const str)
{
 CHECK_READ_TYPED_PTR(str,sz);

 assert(sz<=(std::numeric_limits<size_t>::max)()/sizeof(char_type));

 size_t total_sz=offsetof(self_type,m_items[1]);

 if(!::structure::append_memory_size(total_sz,sz*sizeof(char_type)))
  throw std::bad_alloc();

 if(total_sz<sizeof(self_type))
  total_sz=sizeof(self_type);

 void* pv=raw_allocator_type::instance.allocate(total_sz);

 try
 {
  new(pv) self_type(sz);
 }
 catch(...)
 {
  raw_allocator_type::instance.deallocate(pv,total_sz);

  throw;
 }//catch

 memcpy(reinterpret_cast<self_type*>(pv)->m_items,
        str,
        sizeof(char_type)*sz);

 reinterpret_cast<self_type*>(pv)->m_items[sz]=0;

 return structure::not_null_ptr(reinterpret_cast<self_type*>(pv));
}//create

//interface --------------------------------------------------------------
template<typename charT,class Allocator>
typename t_basic_const_string_data__dynamic<charT,Allocator>::size_type
 t_basic_const_string_data__dynamic<charT,Allocator>::size()const
{
 return m_size;
}//m_size

//------------------------------------------------------------------------
template<typename charT,class Allocator>
typename t_basic_const_string_data__dynamic<charT,Allocator>::const_pointer
 t_basic_const_string_data__dynamic<charT,Allocator>::data()const
{
 return m_items;
}//data

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string

#if(COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001==0)

template<typename charT,class charTraits>
const typename t_basic_const_string<charT,charTraits>::char_type
t_basic_const_string<charT,charTraits>::sm_emptyStr[]={0};

#endif

//------------------------------------------------------------------------
template<typename charT,class charTraits>
t_basic_const_string<charT,charTraits>::t_basic_const_string()
 :m_data(self_type::helper__create_empty_data())
{
 assert(m_data);
}

//------------------------------------------------------------------------
template<typename charT,class charTraits>
t_basic_const_string<charT,charTraits>::t_basic_const_string(const self_type& x)
 :m_data(x.m_data)
{
 assert(m_data);
}

//------------------------------------------------------------------------
template<typename charT,class charTraits>
t_basic_const_string<charT,charTraits>::t_basic_const_string(self_type&& x)
 :m_data(__STL_MOVE_VALUE(x.m_data))
{
 assert(m_data);

 x.m_data=self_type::helper__create_empty_data();

 assert(x.m_data);
}//t_basic_const_string

//------------------------------------------------------------------------
template<typename charT,class charTraits>
t_basic_const_string<charT,charTraits>::t_basic_const_string(data_ptr&& x)
 :m_data(__STL_MOVE_VALUE(x))
{
 assert(m_data);
}//t_basic_const_string

//------------------------------------------------------------------------
template<typename charT,class charTraits>
t_basic_const_string<charT,charTraits>::t_basic_const_string(data_type* const data)
 :m_data(structure::not_null_ptr(data))
{
 assert(m_data);
}

//------------------------------------------------------------------------
template<typename charT,class charTraits>
t_basic_const_string<charT,charTraits>::~t_basic_const_string()
{}

//------------------------------------------------------------------------
template<typename charT,class charTraits>
t_basic_const_string<charT,charTraits>& t_basic_const_string<charT,charTraits>::operator = (const self_type& x)
{
 assert(x.m_data);

 m_data=x.m_data;

 assert(m_data);

 return *this;
}//operator =

//------------------------------------------------------------------------
template<typename charT,class charTraits>
t_basic_const_string<charT,charTraits>&
 t_basic_const_string<charT,charTraits>::operator = (self_type&& x)
{
 assert(x.m_data);

 if(&x==this)
  return *this;

 m_data=__STL_MOVE_VALUE(x.m_data);

 assert(m_data);

 x.m_data=helper__create_empty_data();

 assert(x.m_data);

 return *this;
}//operator - move operator

//------------------------------------------------------------------------
template<typename charT,class charTraits>
void t_basic_const_string<charT,charTraits>::swap(self_type& x)
{
 assert(m_data);
 assert(x.m_data);

 m_data.swap(x.m_data);

 assert(m_data);
 assert(x.m_data);
}//swap

//------------------------------------------------------------------------
template<typename charT,class charTraits>
template<const charT* const staticSTR>
t_basic_const_string<charT,charTraits> t_basic_const_string<charT,charTraits>::create()
{
 assert(staticSTR);

 if((*staticSTR)==0)
  return self_type();

 data_ptr data(t_basic_const_string_data__static<char_type,staticSTR>::create());

 assert(data);

 return self_type(__STL_MOVE_VALUE(data));
}//create

//------------------------------------------------------------------------
template<typename charT,class charTraits>
t_basic_const_string<charT,charTraits>& t_basic_const_string<charT,charTraits>::clear()
{
 m_data=self_type::helper__create_empty_data();

 assert(m_data);

 return *this;
}//clear

//------------------------------------------------------------------------
template<typename charT,class charTraits>
t_basic_const_string<charT,charTraits>::operator t_basic_const_str_box<charT> () const
{
 return t_basic_const_str_box<charT>(this->data(),this->size());
}//operator t_basic_const_str_box<charT>

//------------------------------------------------------------------------
template<typename charT,class charTraits>
template<class Allocator>
t_basic_const_string<charT,charTraits> t_basic_const_string<charT,charTraits>::create(const str_box_type& str)
{
 CHECK_READ_TYPED_PTR(str.ptr,str.len);

 if(str.empty())
  return self_type();

 data_ptr data(t_basic_const_string_data__dynamic<charT,Allocator>::create
                 (str.len,
                  str.ptr));

 assert(data);

 return self_type(__STL_MOVE_VALUE(data));
}//create

//interface --------------------------------------------------------------
template<typename charT,class charTraits>
bool t_basic_const_string<charT,charTraits>::empty()const
{
 assert(m_data);

 return m_data->size()==0;
}//size

//------------------------------------------------------------------------
template<typename charT,class charTraits>
typename t_basic_const_string<charT,charTraits>::size_type
 t_basic_const_string<charT,charTraits>::size()const
{
 assert(m_data);

 return m_data->size();
}//size

//------------------------------------------------------------------------
template<typename charT,class charTraits>
typename t_basic_const_string<charT,charTraits>::size_type
 t_basic_const_string<charT,charTraits>::length()const
{
 assert(m_data);

 return m_data->size();
}//length

//------------------------------------------------------------------------
template<typename charT,class charTraits>
typename t_basic_const_string<charT,charTraits>::const_reference
 t_basic_const_string<charT,charTraits>::operator [] (size_type const index)const
{
 assert(m_data);

 assert(index<m_data->size());

 return m_data->data()[index];
}//operator []

//------------------------------------------------------------------------
template<typename charT,class charTraits>
typename t_basic_const_string<charT,charTraits>::const_pointer
 t_basic_const_string<charT,charTraits>::data()const
{
 assert(m_data);

 return m_data->data();
}//data

//------------------------------------------------------------------------
template<typename charT,class charTraits>
typename t_basic_const_string<charT,charTraits>::const_iterator
 t_basic_const_string<charT,charTraits>::cbegin()const
{
 assert(m_data);

#ifdef NDEBUG
 return m_data->data();
#else
 return const_iterator(this,m_data->data());
#endif
}//cbegin

//------------------------------------------------------------------------
template<typename charT,class charTraits>
typename t_basic_const_string<charT,charTraits>::const_iterator
 t_basic_const_string<charT,charTraits>::cend()const
{
 assert(m_data);

#ifdef NDEBUG
 return m_data->data()+m_data->size();
#else
 return const_iterator(this,m_data->data()+m_data->size());
#endif
}//cend

//------------------------------------------------------------------------
template<typename charT,class charTraits>
typename t_basic_const_string<charT,charTraits>::const_iterator
 t_basic_const_string<charT,charTraits>::begin()const
{
 return this->cbegin();
}//begin

//------------------------------------------------------------------------
template<typename charT,class charTraits>
typename t_basic_const_string<charT,charTraits>::const_iterator
 t_basic_const_string<charT,charTraits>::end()const
{
 return this->cend();
}//end

//------------------------------------------------------------------------
template<typename charT,class charTraits>
bool t_basic_const_string<charT,charTraits>::equal(const_pointer const str)const
{
 assert(m_data);
 assert(str);

 return self_type::helper__equal
         (this->data(),
          this->size(),
          str,
          traits_type::length(str));
}//equal

//------------------------------------------------------------------------
template<typename charT,class charTraits>
bool t_basic_const_string<charT,charTraits>::equal(const_pointer const str,
                                                   size_type     const sz)const
{
 assert(m_data);

 CHECK_READ_TYPED_PTR(str,sz);

 return self_type::helper__equal
         (this->data(),
          this->size(),
          str,
          sz);
}//equal

//------------------------------------------------------------------------
template<typename charT,class charTraits>
bool t_basic_const_string<charT,charTraits>::equal(const self_type& x)const
{
 return self_type::helper__equal
         (this->data(),
          this->size(),
          x.data(),
          x.size());
}//equal

//------------------------------------------------------------------------
template<typename charT,class charTraits>
int t_basic_const_string<charT,charTraits>::compare(const self_type& x)const
{
 return self_type::helper__compare
         (this->data(),
          this->size(),
          x.data(),
          x.size());
}//compare

//helper methods ---------------------------------------------------------
template<typename charT,class charTraits>
typename t_basic_const_string<charT,charTraits>::data_ptr
 t_basic_const_string<charT,charTraits>::helper__create_empty_data()
{
#if(COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001==0)
 return t_basic_const_string_data__static<char_type,self_type::sm_emptyStr>::create();
#else
 typedef t_basic_const_string_helper<charT> helper_type;

 return t_basic_const_string_data__static<char_type,helper_type::sm_emptyStr>::create();
#endif
}//helper__create_empty_data

//------------------------------------------------------------------------
template<typename charT,class charTraits>
bool t_basic_const_string<charT,charTraits>::helper__equal
                                           (const char_type* const s1,
                                            size_t           const l1,
                                            const char_type* const s2,
                                            size_t           const l2)
{
 // [2020-02-26] I know ...

 if(l1!=l2)
  return false;

 if(traits_type::compare(s1,s2,l1)!=0)
  return false;

 return true;
}//helper__equal

//------------------------------------------------------------------------
template<typename charT,class charTraits>
int t_basic_const_string<charT,charTraits>::helper__compare
                                           (const char_type* const s1,
                                            size_t           const l1,
                                            const char_type* const s2,
                                            size_t           const l2)
{
 const auto l=((l1<l2)?l1:l2);

 const auto r=traits_type::compare(s1,s2,l);

 if(r!=0)
  return r;

 if(l1==l2)
  return 0;

 if(l1<l2)
  return -1;

 return 1;
}//helper__compare

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType>
std::basic_ostream<charT,traitsType>&
 operator << (std::basic_ostream<charT,traitsType>&                    s,
              const structure::t_basic_const_string<charT,traitsType>& str)
{
 return s.write(str.data(),str.size());
}//operator <<

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType>
bool operator == (const t_basic_const_string<charT,traitsType>& s1,
                  const t_basic_const_string<charT,traitsType>& s2)
{
 return s1.equal(s2);
}//operator ==

//------------------------------------------------------------------------
template<typename charT,typename traitsType>
bool operator != (const t_basic_const_string<charT,traitsType>& s1,
                  const t_basic_const_string<charT,traitsType>& s2)
{
 return !(s1==s2);
}//operator !=

//------------------------------------------------------------------------
template<typename charT,typename traitsType>
bool operator < (const t_basic_const_string<charT,traitsType>& s1,
                 const t_basic_const_string<charT,traitsType>& s2)
{
 return s1.compare(s2)<0;
}//operator <

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType,typename Allocator>
bool operator == (const std::basic_string<charT,traitsType,Allocator>&      s1,
                  const structure::t_basic_const_string<charT,traitsType>&  s2)
{
 return s2.equal(s1.c_str(),s1.size());
}//operator ==

//------------------------------------------------------------------------
template<typename charT,typename traitsType,typename Allocator>
bool operator != (const std::basic_string<charT,traitsType,Allocator>&      s1,
                  const structure::t_basic_const_string<charT,traitsType>&  s2)
{
 return !(s1==s2);
}//operator !=

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType,typename Allocator>
bool operator == (const structure::t_basic_const_string<charT,traitsType>&  s1,
                  const std::basic_string<charT,traitsType,Allocator>&      s2)
{
 return s2==s1;
}//operator ==

//------------------------------------------------------------------------
template<typename charT,typename traitsType,typename Allocator>
bool operator != (const structure::t_basic_const_string<charT,traitsType>&  s1,
                  const std::basic_string<charT,traitsType,Allocator>&      s2)
{
 return !(s1==s2);
}//operator !=

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType>
bool operator == (const charT*                                       const s1,
                  const structure::t_basic_const_string<charT,traitsType>& s2)
{
 assert(s1);

 return s2.equal(s1);
}//operator ==

//------------------------------------------------------------------------
template<typename charT,typename traitsType>
bool operator != (const charT*                                       const s1,
                  const structure::t_basic_const_string<charT,traitsType>& s2)
{
 assert(s1);

 return !(s1==s2);
}//operator !=

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType>
bool operator == (const structure::t_basic_const_string<charT,traitsType>& s1,
                  const charT*                                       const s2)
{
 assert(s2);

 return s2==s1;
}//operator ==

//------------------------------------------------------------------------
template<typename charT,typename traitsType>
bool operator != (const structure::t_basic_const_string<charT,traitsType>& s1,
                  const charT*                                       const s2)
{
 assert(s2);

 return !(s1==s2);
}//operator !=

////////////////////////////////////////////////////////////////////////////////

template<typename charT>
t_basic_const_str_box<charT> make_str_box(const t_basic_const_string<charT>& s)
{
 return s;
}//make_str_box

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
