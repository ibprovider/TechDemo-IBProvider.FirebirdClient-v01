////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 14.07.2009.
#ifndef _cpp_public_lcpi_lib_structure__t_simple_buffer_CC_
#define _cpp_public_lcpi_lib_structure__t_simple_buffer_CC_

#include <lcpi/lib/structure/t_algorithm.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//template class t_simple_buffer - void specialization

template<class Allocator>
inline t_simple_buffer<void,Allocator>::t_simple_buffer()
 :m_buffer   (nullptr)
 ,m_size     (0)
 ,m_capacity (0)
{
}

//------------------------------------------------------------------------
template<class Allocator>
inline t_simple_buffer<void,Allocator>::t_simple_buffer(size_type const sz)
 :m_buffer   (nullptr)
 ,m_size     (0)
 ,m_capacity (0)
{
 this->alloc(sz);
}

//------------------------------------------------------------------------
template<class Allocator>
inline t_simple_buffer<void,Allocator>::~t_simple_buffer()
{
 this->free();
}

//------------------------------------------------------------------------
template<class Allocator>
RELEASE_CODE(inline)
typename t_simple_buffer<void,Allocator>::pointer
 t_simple_buffer<void,Allocator>::ptr_at(size_type const i)const
{
 assert(m_size<=m_capacity);
 assert(i<m_size);

 assert_s(sizeof(char)==1);

 return reinterpret_cast<char*>(m_buffer)+i;
}//ptr_at

//------------------------------------------------------------------------
template<class Allocator>
typename t_simple_buffer<void,Allocator>::pointer
 t_simple_buffer<void,Allocator>::alloc(size_type const sz)
{
 assert(m_size<=m_capacity);

 if(sz>m_capacity)
 {
  pointer const p=m_alloc.allocate(sz);

  this->free();

  m_buffer   =p;
  m_capacity =sz;
 }//if

 m_size=sz;

 assert(m_size<=m_capacity);

 CHECK_READ_WRITE_PTR(this->buffer(),this->memory_size());

 return m_buffer;
}//alloc

//------------------------------------------------------------------------
template<class Allocator>
void t_simple_buffer<void,Allocator>::free()
{
 pointer const p=m_buffer;

 m_buffer   =nullptr;
 m_size     =0;
 m_capacity =0;

 if(p)
  m_alloc.deallocate(static_cast<typename __value_alloc_type::value_type*>(p),0);
}//free

//------------------------------------------------------------------------
template<class Allocator>
void t_simple_buffer<void,Allocator>::swap(self_type& x)
{
 std::swap(m_alloc    ,x.m_alloc);

 std::swap(m_buffer   ,x.m_buffer);
 std::swap(m_size     ,x.m_size);
 std::swap(m_capacity ,x.m_capacity);
}//swap

//------------------------------------------------------------------------
template<class Allocator>
void t_simple_buffer<void,Allocator>::truncate(size_type const sz)
{
 assert(sz<=m_size);

 m_size=sz;
}//truncate

////////////////////////////////////////////////////////////////////////////////
//template class t_simple_buffer

template<class T,class Allocator>
inline t_simple_buffer<T,Allocator>::t_simple_buffer()
 :m_buffer   (nullptr)
 ,m_size     (0)
 ,m_capacity (0)
{
}

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
t_simple_buffer<T,Allocator>::t_simple_buffer(self_type&& x)
 :m_alloc    (std::move(x.m_alloc))
 ,m_buffer   (std::move(x.m_buffer))
 ,m_size     (std::move(x.m_size))
 ,m_capacity (std::move(x.m_capacity))
{
 x.m_buffer   =nullptr;
 x.m_size     =0;
 x.m_capacity =0;

 assert(m_size<=m_capacity);

 CHECK_READ_WRITE_TYPED_PTR(m_buffer,m_capacity);
}

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
t_simple_buffer<T,Allocator>::t_simple_buffer(size_type const sz)
 :m_buffer   (m_alloc.allocate(sz))  //throw
 ,m_size     (sz)
 ,m_capacity (sz)
{
 CHECK_READ_WRITE_TYPED_PTR(m_buffer,m_capacity);
}//t_simple_buffer

//------------------------------------------------------------------------
template<class T,class Allocator>
t_simple_buffer<T,Allocator>::t_simple_buffer(const value_type* const s,
                                              size_type         const n)
 :m_buffer   (m_alloc.allocate(n)) //throw
 ,m_size     (n)
 ,m_capacity (n)
{
 CHECK_READ_WRITE_TYPED_PTR(m_buffer,m_capacity);

 try
 {
  structure::copy(s,s+n,this->buffer(),this->buffer_end());
 }
 catch(...)
 {
  m_alloc.deallocate(m_buffer,0);
  throw;
 }
}//t_simple_buffer

//------------------------------------------------------------------------
template<class T,class Allocator>
inline t_simple_buffer<T,Allocator>::~t_simple_buffer()
{
 this->free();
}//~t_simple_buffer

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_simple_buffer<T,Allocator>::reference
 t_simple_buffer<T,Allocator>::operator [] (size_type const i)
{
 assert(i<this->size());
 return m_buffer[i];
}

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_simple_buffer<T,Allocator>::const_reference
 t_simple_buffer<T,Allocator>::operator [] (size_type const i)const
{
 assert(i<this->size());
 return m_buffer[i];
}

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_simple_buffer<T,Allocator>::pointer
 t_simple_buffer<T,Allocator>::ptr_at(size_type const i)
{
 assert(i<this->size());
 return m_buffer+i;
}//ptr_at

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
typename t_simple_buffer<T,Allocator>::const_pointer
 t_simple_buffer<T,Allocator>::ptr_at(size_type const i)const
{
 assert(i<this->size());
 return m_buffer+i;
}//ptr_at

//------------------------------------------------------------------------
template<class T,class Allocator>
typename t_simple_buffer<T,Allocator>::reference
 t_simple_buffer<T,Allocator>::front()
{
 assert(!this->empty());

 return *m_buffer;
}//front

//------------------------------------------------------------------------
template<class T,class Allocator>
typename t_simple_buffer<T,Allocator>::reference
 t_simple_buffer<T,Allocator>::back()
{
 assert(!this->empty());

 return m_buffer[m_size-1];
}//back

//------------------------------------------------------------------------
template<class T,class Allocator>
typename t_simple_buffer<T,Allocator>::const_reference
 t_simple_buffer<T,Allocator>::front()const
{
 assert(!this->empty());

 return *m_buffer;
}//front - const

//------------------------------------------------------------------------
template<class T,class Allocator>
typename t_simple_buffer<T,Allocator>::const_reference
 t_simple_buffer<T,Allocator>::back()const
{
 assert(!this->empty());

 return m_buffer[m_size-1];
}//back - const

//------------------------------------------------------------------------
template<class T,class Allocator>
void t_simple_buffer<T,Allocator>::clear()
{
 m_size=0;
}//clear

//------------------------------------------------------------------------
template<class T,class Allocator>
typename t_simple_buffer<T,Allocator>::pointer
 t_simple_buffer<T,Allocator>::alloc(size_type const sz)
{
 assert(m_size<=m_capacity);

 if(sz>m_capacity)
 {
  pointer const p=m_alloc.allocate(sz);

  this->free();

  m_buffer   =p;
  m_capacity =sz;
 }//if

 m_size=sz;

 assert(m_size<=m_capacity);

 CHECK_READ_WRITE_PTR (this->buffer(),this->memory_size());

 return m_buffer;
}//alloc

//------------------------------------------------------------------------
template<class T,class Allocator>
typename t_simple_buffer<T,Allocator>::pointer
 t_simple_buffer<T,Allocator>::realloc(size_type const sz)
{
 assert(m_size<=m_capacity);

 this->reserve(sz);

 assert(sz<=m_capacity);

 m_size=sz;

 return this->buffer();
}//realloc

//------------------------------------------------------------------------
template<class T,class Allocator>
typename t_simple_buffer<T,Allocator>::pointer
 t_simple_buffer<T,Allocator>::reserve(size_type const new_capacity)
{
 assert(m_size<=m_capacity);

 if(new_capacity<=m_capacity)
 {
  //OK
 }
 else
 {
  assert(m_capacity<new_capacity);

  pointer new_buffer=m_alloc.allocate(new_capacity); //throw

  CHECK_READ_WRITE_PTR (this->buffer(),this->memory_size());

  try
  {
   _VERIFY_EQ(structure::copy(m_buffer,
                              m_buffer+m_size,
                              new_buffer,
                              new_buffer+new_capacity).first,
              m_buffer+m_size);
  }
  catch(...)
  {
   m_alloc.deallocate(new_buffer,new_capacity);
   throw;
  }

  this->free();

  m_buffer   =new_buffer;
  m_capacity =new_capacity;
 }//if

 CHECK_READ_WRITE_PTR (this->buffer(),this->memory_size());

 return this->buffer();
}//reserve

//------------------------------------------------------------------------
template<class T,class Allocator>
void t_simple_buffer<T,Allocator>::free()
{
 pointer const p=m_buffer;

 m_buffer   =nullptr;
 m_size     =0;
 m_capacity =0;

 if(p)
  m_alloc.deallocate(p,0);
}//free

//------------------------------------------------------------------------
template<class T,class Allocator>
void t_simple_buffer<T,Allocator>::swap(self_type& x)
{
 std::swap(m_alloc     ,x.m_alloc);

 std::swap(m_buffer    ,x.m_buffer);
 std::swap(m_size      ,x.m_size);
 std::swap(m_capacity  ,x.m_capacity);
}//swap

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
