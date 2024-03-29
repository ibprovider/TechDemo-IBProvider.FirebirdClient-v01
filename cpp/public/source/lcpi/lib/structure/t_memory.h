////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Library.
//                                                 Dmitry Kovalenko. 06.02.2000.
#ifndef _cpp_public_lcpi_lib_structure__t_memory_H_
#define _cpp_public_lcpi_lib_structure__t_memory_H_

#include <lcpi/lib/structure/mt/interlocked.h>
#include <lcpi/lib/code_gen.h>
#include <utility>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//support rebind

#define LCPI_CPP_LIB__STLS_ALLOCATOR_REBIND(Allocator,U)                      \
 Allocator::template rebind<U>::other

////////////////////////////////////////////////////////////////////////////////
//define wrap allocator

//declare wrap allocator
#define LCPI_CPP_LIB__DECLARE_WRAP_ALLOCATOR(AllocatorClassName)              \
                                                                              \
class AllocatorClassName##_Adapter LCPI_CPP_CFG__CLASS__FINAL                 \
{                                                                             \
 public:                                                                      \
  using size_type=size_t;                                                     \
  using pointer=void*;                                                        \
                                                                              \
  using AllocFunc=pointer(*)(size_type);                                      \
  using FreeFunc =void(*)(pointer pv);                                        \
                                                                              \
 public:                                                                      \
  static void SetMemoryManager(AllocFunc const pfAllocMemory,                 \
                               FreeFunc  const pfFreeMemory)                  \
  {                                                                           \
   LCPI__assert(sm_is_used==0);                                               \
                                                                              \
   sm_pfAllocMemory=pfAllocMemory;                                            \
   sm_pfFreeMemory =pfFreeMemory;                                             \
  }                                                                           \
                                                                              \
  static pointer raw_allocate(size_type const n)                              \
  {                                                                           \
   LCPI__assert(sm_pfAllocMemory!=nullptr);                                   \
                                                                              \
   {                                                                          \
    LCPI__DEBUG_CODE                                                          \
    (                                                                         \
     if(sm_is_used==0)                                                        \
      ::lcpi::lib::structure::mt::interlocked::exchange(&sm_is_used,1);       \
    )                                                                         \
                                                                              \
    LCPI__assert(sm_is_used==1);                                              \
   }                                                                          \
                                                                              \
   return sm_pfAllocMemory(n);                                                \
  }                                                                           \
                                                                              \
  static void raw_deallocate(pointer const pv)                                \
  {                                                                           \
   LCPI__assert(sm_pfFreeMemory!=nullptr);                                    \
                                                                              \
   return sm_pfFreeMemory(pv);                                                \
  }                                                                           \
                                                                              \
 private:                                                                     \
  LCPI__DEBUG_CODE(static unsigned sm_is_used;)                               \
                                                                              \
  static AllocFunc sm_pfAllocMemory;                                          \
  static FreeFunc  sm_pfFreeMemory;                                           \
};                                                                            \
                                                                              \
using AllocatorClassName                                                      \
 =::lcpi::lib::structure::t_raw_allocator<AllocatorClassName##_Adapter>;

//------------------------------------------------------------------------
//wrap allocator implementation

#define LCPI_CPP_LIB__DEFINE_WRAP_ALLOCATOR(AllocatorClassName)               \
                                                                              \
LCPI__DEBUG_CODE                                                              \
 (unsigned AllocatorClassName##_Adapter::sm_is_used=0;)                       \
                                                                              \
AllocatorClassName##_Adapter::AllocFunc                                       \
 AllocatorClassName##_Adapter::sm_pfAllocMemory=                              \
  ::lcpi::lib::structure::t_void_allocator_adapter::raw_allocate;             \
                                                                              \
AllocatorClassName##_Adapter::FreeFunc                                        \
 AllocatorClassName##_Adapter::sm_pfFreeMemory=                               \
  ::lcpi::lib::structure::t_void_allocator_adapter::raw_deallocate;

////////////////////////////////////////////////////////////////////////////////
//containings

template<class RawMemManager>
class t_raw_allocator;

template<class Allocator,class T>
class t_allocator_interface;

class t_void_allocator_adapter;

using t_void_allocator
 =t_raw_allocator<t_void_allocator_adapter>;

namespace detail{
////////////////////////////////////////////////////////////////////////////////

template<class RAW,class U>
struct t_raw_allocator_rebind
{
 using other=structure::t_allocator_interface<RAW,U>;
};//struct t_raw_allocator_rebind<RAW,U>

template<class RAW>
struct t_raw_allocator_rebind<RAW,void>
{
 using other=RAW;
};//struct t_raw_allocator_rebind<RAW,void>

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
//class t_raw_allocator

// RawMemManager:
// - static void* raw_allocate(size_t n);
// - static void raw_deallocate(void* p);

template<class RawMemManager>
class t_raw_allocator
{
 private:
  using self_type=t_raw_allocator<RawMemManager>;

 public: //typedefs
  typedef RawMemManager                     adapter;

  typedef size_t                            size_type;
  typedef ptrdiff_t                         difference_type;
  typedef void*                             pointer;
  typedef const void*                       const_pointer;
  typedef void                              value_type;

  //
  // [2024-03-18]
  //
  //  VS2019 has a problem with "using rebind=detail::t_raw_allocator_rebind<self_type,U>"
  //
  //  This compiler can't use t_raw_allocator with t_stl_map container.
  //
  template<class U>
  class rebind:public detail::t_raw_allocator_rebind<self_type,U>
  {
  };//class rebind

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
  using value_type=T;
};//class t_allocator_interface__base

//------------------------------------------------------------------------
template<class T>
class t_allocator_interface__base<const T>
{
 public:
  using value_type=T;
};//class t_allocator_interface__base - const

//------------------------------------------------------------------------
//trap for incorrect usage of t_allocator_interface

template<>
class t_allocator_interface__base<void>;

//------------------------------------------------------------------------
template<class Allocator,class T>
class t_allocator_interface
 :private t_allocator_interface__base<T>
{
 private:
  using self_type=t_allocator_interface<Allocator,T>;
  using base_type=t_allocator_interface__base<T>;

 public: //typedefs ------------------------------------------------------
  using raw_allocator_type
   =typename Allocator::template rebind<void>::other;

  using value_type
   =typename base_type::value_type;

  typedef value_type*                                      pointer;
  typedef const value_type*                                const_pointer;
  typedef value_type&                                      reference;
  typedef const value_type&                                const_reference;
  typedef typename raw_allocator_type::size_type           size_type;
  typedef typename raw_allocator_type::difference_type     difference_type;
  typedef void*                                            void_pointer;
  typedef const void*                                      const_void_pointer;

  template<class U>
  struct rebind LCPI_CPP_CFG__CLASS__FINAL
  {
   using other=typename Allocator::template rebind<U>::other;
  };//struct rebind

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

  bool operator == (const self_type& LCPI__UNUSED_ARG(x))const
  {
   return true;
  }

  bool operator != (const self_type& LCPI__UNUSED_ARG(x))const
  {
   return false;
  }

 public:
  pointer address(reference x)const;

  size_type max_size()const;

  pointer allocate(size_type n,pointer p=nullptr);

  void deallocate(pointer p,size_type n);

  // one for all
  template<class... Args>
  void construct(pointer p,Args&&... args);

  void destroy(pointer p);

  void swap(self_type& x);
};//class t_allocator_interface

////////////////////////////////////////////////////////////////////////////////
//class t_void_allocator

class t_void_allocator_adapter LCPI_CPP_CFG__CLASS__FINAL
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
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/

namespace std{
////////////////////////////////////////////////////////////////////////////////
//std::swap specialize

template<class RawMemManager>
inline void swap(::lcpi::lib::structure::t_raw_allocator<RawMemManager>& a,
                 ::lcpi::lib::structure::t_raw_allocator<RawMemManager>& b)
{
 a.swap(b);
}//swap - t_raw_allocator

//------------------------------------------------------------------------
template<class Allocator,class T>
inline void swap(::lcpi::lib::structure::t_allocator_interface<Allocator,T>& a,
                 ::lcpi::lib::structure::t_allocator_interface<Allocator,T>& b)
{
 a.swap(b);
}//swap - t_allocator_interface

////////////////////////////////////////////////////////////////////////////////
}//namespace std

////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/t_memory.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
