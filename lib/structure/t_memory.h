////////////////////////////////////////////////////////////////////////////////
//! \ingroup lib_structure
//! \file    t_memory.h
//! \brief   Structures for work with memory
//! \author  Kovalenko Dmitry
//! \date    06.02.2000.
#ifndef _t_memory_H_
#define _t_memory_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/t_threads.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

#if(!COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
# error "Compiler not support required features"
#endif

#if(!COMP_CONF_SUPPORT_RVALUE_REFERENCE)
# error "Compiler not support required features"
#endif

#if(!COMP_CONF_SUPPORT_VARIADIC_TEMPLATES)
# error "Compiler not support required features"
#endif

////////////////////////////////////////////////////////////////////////////////
//support rebind

#define __STLS_ALLOCATOR_REBIND(Allocator,U)                           \
 Allocator::template rebind<U>::other

////////////////////////////////////////////////////////////////////////////////
//define wrap allocator

//макрос для определения обертки вокруг функций распределения памяти
//DECLARE_WRAP_ALLOCATOR(AllocatorClassName)

//declare wrap allocator
#define DECLARE_WRAP_ALLOCATOR(AllocatorClassName)                            \
                                                                              \
class AllocatorClassName##_Adapter                                            \
{                                                                             \
 public:                                                                      \
  typedef size_t                           size_type;                         \
  typedef void*                            pointer;                           \
                                                                              \
  typedef pointer (*AllocFunc)(size_type);                                    \
  typedef void    (*FreeFunc)(pointer pv);                                    \
                                                                              \
 public:                                                                      \
  static void SetMemoryManager(AllocFunc const pfAllocMemory,                 \
                               FreeFunc  const pfFreeMemory)                  \
  {                                                                           \
   assert(sm_used==0);                                                        \
                                                                              \
   sm_pfAllocMemory=pfAllocMemory;                                            \
   sm_pfFreeMemory =pfFreeMemory;                                             \
  }                                                                           \
                                                                              \
  static pointer raw_allocate(size_type const n)                              \
  {                                                                           \
   assert(sm_pfAllocMemory!=nullptr);                                         \
                                                                              \
   DEBUG_CODE(thread_traits::exchange(&sm_used,1));                           \
                                                                              \
   return sm_pfAllocMemory(n);                                                \
  }                                                                           \
                                                                              \
  static void raw_deallocate(pointer const pv)                                \
  {                                                                           \
   assert(sm_pfFreeMemory!=nullptr);                                          \
                                                                              \
   return sm_pfFreeMemory(pv);                                                \
  }                                                                           \
                                                                              \
 private:                                                                     \
  typedef structure::t_multi_thread_traits  thread_traits;                    \
                                                                              \
 private:                                                                     \
  DEBUG_CODE(static thread_traits::int_type sm_used;)                         \
                                                                              \
  static AllocFunc sm_pfAllocMemory;                                          \
  static FreeFunc  sm_pfFreeMemory;                                           \
};                                                                            \
                                                                              \
typedef structure::t_raw_allocator<AllocatorClassName##_Adapter>              \
  AllocatorClassName;

//------------------------------------------------------------------------
//wrap allocator implementations

#define DEFINE_WRAP_ALLOCATOR(AllocatorClassName)                             \
                                                                              \
DEBUG_CODE(AllocatorClassName##_Adapter::thread_traits::int_type              \
            AllocatorClassName##_Adapter::sm_used=0;)                         \
                                                                              \
AllocatorClassName##_Adapter::AllocFunc                                       \
 AllocatorClassName##_Adapter::sm_pfAllocMemory=                              \
  structure::t_void_allocator_adapter::raw_allocate;                          \
                                                                              \
AllocatorClassName##_Adapter::FreeFunc                                        \
 AllocatorClassName##_Adapter::sm_pfFreeMemory=                               \
  structure::t_void_allocator_adapter::raw_deallocate;

////////////////////////////////////////////////////////////////////////////////
//containings

template<class RawMemManager>
class t_raw_allocator;

template<class Allocator,class T>
class t_allocator_interface;

class t_void_allocator_adapter;

typedef t_raw_allocator<t_void_allocator_adapter> t_void_allocator;

////////////////////////////////////////////////////////////////////////////////
//class t_raw_allocator

// RawMemManager:
// - static void* raw_allocate(size_t n);
// - static void raw_deallocate(void* p);

template<class RawMemManager>
class t_raw_allocator
{
 private:
  typedef t_raw_allocator<RawMemManager>    self_type;

 public: //typedefs
  typedef RawMemManager                     adapter;
                                            
  typedef size_t                            size_type;
  typedef ptrdiff_t                         difference_type;
  typedef void*                             pointer;
  typedef const void*                       const_pointer;
  typedef void                              value_type;
                                            
  template<class U>
  struct rebind
  {
   typedef structure::t_allocator_interface<self_type,U> other;
  };

  template<>
  struct rebind<void>
  {
   typedef self_type                                     other;
  };

 public:
  static self_type instance;

  t_raw_allocator();

  t_raw_allocator(const self_type& x);

  template<class U>
  t_raw_allocator(const structure::t_allocator_interface<self_type,U>&);

  self_type& operator = (const self_type& x);

  bool operator == (const self_type& x)const;

  bool operator != (const self_type& x)const;

  pointer allocate(size_type n,pointer ptr=nullptr);

  void deallocate(pointer p, size_type size);

  size_type max_size()const;

  size_type max_size(size_type size)const;

  void swap(self_type& x);
};//class t_raw_allocator

////////////////////////////////////////////////////////////////////////////////
//class t_allocator_interface (from BCB3)

template<class T>
class t_allocator_interface__base
{
 public:
  typedef T                                            value_type;
};//class t_allocator_interface__base

//------------------------------------------------------------------------
template<class T>
class t_allocator_interface__base<const T>
{
 public:
  typedef T                                            value_type;
};//class t_allocator_interface__base - const

//------------------------------------------------------------------------
//trap for incorrect use of t_allocator_interface 

template<>
class t_allocator_interface__base<void>;

//------------------------------------------------------------------------
template<class Allocator,class T>
class t_allocator_interface:private t_allocator_interface__base<T>
{
 private:
  typedef t_allocator_interface<Allocator,T>               self_type;
  typedef t_allocator_interface__base<T>                   base_type;

 public: //typedefs ------------------------------------------------------
  typedef typename Allocator::template rebind<void>::other raw_allocator_type;

  typedef typename base_type::value_type                   value_type;

  typedef value_type*                                      pointer;
  typedef const value_type*                                const_pointer;
  typedef value_type&                                      reference;
  typedef const value_type&                                const_reference;
  typedef typename raw_allocator_type::size_type           size_type;
  typedef typename raw_allocator_type::difference_type     difference_type;
  typedef void*                                            void_pointer;
  typedef const void*                                      const_void_pointer;

  template<class U>
  struct rebind
  {
   typedef typename Allocator::template rebind<U>::other   other;
  };

 public:
  static self_type instance;

 public:
  t_allocator_interface();

  //C++ Standart: compiler always use NOT-template copy constructor
  t_allocator_interface(const self_type& x);

  template<class U>
  t_allocator_interface(const t_allocator_interface<Allocator,U>& x);

  t_allocator_interface(const Allocator& a);

  self_type& operator = (const self_type& x);

  bool operator == (const self_type& UNUSED_ARG(x))const
  {
   return true;
  }

  bool operator != (const self_type& UNUSED_ARG(x))const
  {
   return false;
  }

 public:
  typename pointer address(reference x)const;

  typename size_type max_size()const;

  typename pointer allocate(size_type n,pointer p=nullptr);

  void deallocate(pointer p,size_type n);

  // one for all
  template<class... Args>
  void construct(pointer p,Args&&... args);

  void destroy(pointer p);

  void swap(self_type& x);
};//class t_allocator_interface

////////////////////////////////////////////////////////////////////////////////
//class t_void_allocator

class t_void_allocator_adapter
{
 public:
  static void* raw_allocate(size_t n);

  static void raw_deallocate(void* pv);
};//class t_void_allocator_adapter

////////////////////////////////////////////////////////////////////////////////
//memory management utilities

// one for all
template<class T,class... Args>
inline void __generic_construct(T* p,Args&&... args);

template<class T>
inline void __generic_destroy(T* p);

template<class ForwardIterator>
void __generic_destroyer_range(ForwardIterator first,ForwardIterator last);

template<class ForwardIterator>
ForwardIterator uninitialize_init(ForwardIterator first,ForwardIterator last);

template<class InputIterator,class ForwardIterator>
std::pair<InputIterator,ForwardIterator>
 uninitialized_copy(InputIterator   first,
                    InputIterator   last,
                    ForwardIterator dest_first,
                    ForwardIterator dest_last);

////////////////////////////////////////////////////////////////////////////////

inline bool append_memory_size(size_t& s,size_t const delta);

inline bool append_array_memory_size(size_t& s,size_t element_size,size_t element_count);

inline bool align_memory_size(size_t& s,size_t a);

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

namespace std{
////////////////////////////////////////////////////////////////////////////////
//std::swap specialize

template<class RawMemManager>
inline void swap(structure::t_raw_allocator<RawMemManager>& a,
                 structure::t_raw_allocator<RawMemManager>& b)
{
 a.swap(b);
}//swap - t_raw_allocator

//------------------------------------------------------------------------
template<class Allocator,class T>
inline void swap(structure::t_allocator_interface<Allocator,T>& a,
                 structure::t_allocator_interface<Allocator,T>& b)
{
 a.swap(b);
}//swap - t_allocator_interface

////////////////////////////////////////////////////////////////////////////////
}//namespace std

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_memory.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
