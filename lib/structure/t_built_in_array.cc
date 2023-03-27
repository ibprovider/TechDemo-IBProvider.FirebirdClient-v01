////////////////////////////////////////////////////////////////////////////////
#ifndef _t_built_in_array_CC_
#define _t_built_in_array_CC_

#include <structure/t_memory.h>
#include <memory>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_built_in_array

template<class T>
RELEASE_CODE(inline)
t_built_in_array<T>::t_built_in_array(pointer not_init_first,
                                      pointer not_init_last)
 :m_first(not_init_first)
 ,m_last (not_init_last)
{
 assert(not_init_first<=not_init_last);

 structure::uninitialize_init(m_first,m_last);
}//t_built_in_array

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
t_built_in_array<T>::t_built_in_array(pointer       not_init_first,
                                      pointer       not_init_last,
                                      const_pointer source_first,
                                      const_pointer source_last)
 :m_first(not_init_first)
 ,m_last (not_init_last)
{
 assert(not_init_first<=not_init_last);

 assert(source_first<=source_last);

 assert(not_init_last-not_init_first==source_last-source_first);

 structure::uninitialized_copy
  (source_first,
   source_last,
   not_init_first,
   not_init_last);
}//t_build_in_array

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class T>
template<typename SourceIterator>
RELEASE_CODE(inline)
t_built_in_array<T>::t_built_in_array(pointer        not_init_first,
                                      pointer        not_init_last,
                                      SourceIterator source_first,
                                      SourceIterator source_last)
 :m_first(not_init_first)
 ,m_last (not_init_last)
{
 assert(not_init_first<=not_init_last);

 assert(source_first<=source_last);

 assert(not_init_last-not_init_first==source_last-source_first);

 structure::uninitialized_copy
  (source_first,
   source_last,
   not_init_first,
   not_init_last);
}//t_built_in_array
#endif

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
t_built_in_array<T>::~t_built_in_array()
{
 structure::__generic_destroyer_range(m_first,m_last);
}//~t_built_in_array

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
t_built_in_array<T>& t_built_in_array<T>::release()
{
 m_first=NULL;
 m_last =NULL;

 return *this;
}//release

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
bool t_built_in_array<T>::empty()const
{
 return m_first==m_last;
}//empty

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::size_type t_built_in_array<T>::size()const
{
 return m_last-m_first;
}//size

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::size_type t_built_in_array<T>::capacity()const
{
 return m_last-m_first;
}//capacity

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::reference t_built_in_array<T>::operator [] (size_type i)
{
 assert(i<this->size());

 return m_first[i];
}//operator []

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::const_reference t_built_in_array<T>::operator [] (size_type i)const
{
 assert(i<this->size());

 return m_first[i];
}//operator []

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::reference t_built_in_array<T>::at(size_type i)
{
 assert(i<this->size());

 return m_first[i];
}//at

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::const_reference t_built_in_array<T>::at(size_type i)const
{
 assert(i<this->size());

 return m_first[i];
}//at

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::iterator t_built_in_array<T>::begin()
{
#ifndef NDEBUG
 return iterator(this,m_first);
#else
 return m_first;
#endif
}//begin

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::iterator t_built_in_array<T>::end()
{
#ifndef NDEBUG
 return iterator(this,m_last);
#else
 return m_last;
#endif
}//end

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::const_iterator t_built_in_array<T>::begin()const
{
#ifndef NDEBUG
 return const_iterator(this,m_first);
#else
 return m_first;
#endif
}//begin - const version

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::const_iterator t_built_in_array<T>::end()const
{
#ifndef NDEBUG
 return const_iterator(this,m_last);
#else
 return m_last;
#endif
}//end - const version

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::reference t_built_in_array<T>::front()
{
 assert(!this->empty());

 return *this->begin();
}//front

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::const_reference t_built_in_array<T>::front()const
{
 assert(!this->empty());

 return *this->begin();
}//front

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::reference t_built_in_array<T>::back()
{
 assert(!this->empty());

 return *(this->end()-1);
}//back

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_built_in_array<T>::const_reference t_built_in_array<T>::back()const
{
 assert(!this->empty());

 return *(this->end()-1);
}//back

//------------------------------------------------------------------------
template<class T>
typename t_built_in_array<T>::pointer t_built_in_array<T>::data()
{
 return this->m_first;
}//data

//------------------------------------------------------------------------
template<class T>
typename t_built_in_array<T>::const_pointer t_built_in_array<T>::data()const
{
 return this->m_first;
}//data - const

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
