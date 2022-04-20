////////////////////////////////////////////////////////////////////////////////
#ifndef _t_dynamic_array_CC_
#define _t_dynamic_array_CC_

#include <structure/t_str_formatter.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_dynamic_array

template<class T,class Allocator>
inline t_dynamic_array<T,Allocator>::t_dynamic_array()
{
}

//------------------------------------------------------------------------
template<class T,class Allocator>
inline t_dynamic_array<T,Allocator>::t_dynamic_array(size_type const n)
 :m_buffer(n)
{
 structure::uninitialize_init(m_buffer.buffer(),m_buffer.buffer_end());
}//t_dynamic_array

//------------------------------------------------------------------------
template<class T,class Allocator>
t_dynamic_array<T,Allocator>::~t_dynamic_array()
{
 structure::__generic_destroyer_range(m_buffer.buffer(),m_buffer.buffer_end());
}//~t_dynamic_array

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::size_type
 t_dynamic_array<T,Allocator>::size()const
{
 return m_buffer.size();
}//size

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
bool t_dynamic_array<T,Allocator>::empty()const
{
 return m_buffer.empty();
}//empty

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::pointer
 t_dynamic_array<T,Allocator>::data()
{
 return m_buffer.buffer();
}//data

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::const_pointer
 t_dynamic_array<T,Allocator>::data()const
{
 return m_buffer.buffer();
}//data - const

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::iterator
 t_dynamic_array<T,Allocator>::begin()
{
#ifndef NDEBUG
 return iterator(this,m_buffer.buffer());
#else
 return iterator(m_buffer.buffer());
#endif
}//begin

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::iterator
 t_dynamic_array<T,Allocator>::end()
{
#ifndef NDEBUG
 return iterator(this,m_buffer.buffer_end());
#else
 return iterator(m_buffer.buffer_end());
#endif
}//end

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::const_iterator
 t_dynamic_array<T,Allocator>::begin()const
{
#ifndef NDEBUG
 return const_iterator(this,m_buffer.buffer());
#else
 return const_iterator(m_buffer.buffer());
#endif
}//begin

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::const_iterator
 t_dynamic_array<T,Allocator>::end()const
{
#ifndef NDEBUG
 return const_iterator(this,m_buffer.buffer_end());
#else
 return const_iterator(m_buffer.buffer_end());
#endif
}//end

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::const_iterator
 t_dynamic_array<T,Allocator>::cbegin()
{
#ifndef NDEBUG
 return const_iterator(this,m_buffer.buffer());
#else
 return const_iterator(m_buffer.buffer());
#endif
}//cbegin

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::const_iterator
 t_dynamic_array<T,Allocator>::cend()
{
#ifndef NDEBUG
 return const_iterator(this,m_buffer.buffer_end());
#else
 return const_iterator(m_buffer.buffer_end());
#endif
}//cend

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::reference
 t_dynamic_array<T,Allocator>::operator [] (size_type const i)
{
 assert_msg(i<this->size(),"i=="<<i<<" size=="<<this->size());

 return m_buffer[i];
}//operator []

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::const_reference
 t_dynamic_array<T,Allocator>::operator [] (size_type const i)const
{
 assert_msg(i<this->size(),"i=="<<i<<" size=="<<this->size());

 return m_buffer[i];
}//operator []

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::reference
 t_dynamic_array<T,Allocator>::at(size_type const i)
{
 if(i>=this->size())
  this->helper__throw_range_error(i);

 return m_buffer[i];
}//at

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_dynamic_array<T,Allocator>::const_reference
 t_dynamic_array<T,Allocator>::at(size_type const i)const
{
 if(i>=this->size())
  this->helper__throw_range_error(i);

 return m_buffer[i];
}//at

//------------------------------------------------------------------------
template<class T,class Allocator>
void t_dynamic_array<T,Allocator>::clear()
{
 buffer_type __tmp;

 m_buffer.swap(__tmp);

 structure::__generic_destroyer_range(__tmp.buffer(),__tmp.buffer_end());
}//clear

//------------------------------------------------------------------------
template<class T,class Allocator>
void t_dynamic_array<T,Allocator>::init(size_type const n)
{
 self_type __tmp(n);

 this->swap(__tmp);
}//init

//------------------------------------------------------------------------
template<class T,class Allocator>
inline
void t_dynamic_array<T,Allocator>::swap(self_type& x)
{
 m_buffer.swap(x.m_buffer);
}//swap

//helper members ---------------------------------------------------------
template<class T,class Allocator>
void t_dynamic_array<T,Allocator>::helper__throw_range_error(size_type const i)const
{
 assert_msg(i<this->size(),"i=="<<i<<" size=="<<this->size());

 str_formatter fmsg("range error in t_dynamic_array<%1,%2>.\n"
                    "index:%3. size:%4.");

 fmsg<<typeid(value_type).name()
     <<typeid(Allocator).name()
     <<i
     <<this->size();

 throw std::range_error(fmsg.str());
}//helper__throw_range_error

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
