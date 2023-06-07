////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 26.05.2023.
#ifndef _cpp_public_lcpi_lib_structure_debug__t_debug__range_ptr_H_
#define _cpp_public_lcpi_lib_structure_debug__t_debug__range_ptr_H_

#include <lcpi/lib/structure/debug/assert.h>
#include <iterator>
#include <type_traits>
#include <limits>

namespace lcpi{namespace lib{namespace structure{namespace debug{
////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG
#error "Incorect usage"
#endif

////////////////////////////////////////////////////////////////////////////////
//content

template<class T>
class t_debug__range_ptr;

////////////////////////////////////////////////////////////////////////////////
//class t_debug__range_ptr

template<typename T>
class t_debug__range_ptr
{
 private:
  using self_type=t_debug__range_ptr<T>;

  using uint32_t=unsigned __int32;
  using uint64_t=unsigned __int64;

 public: //typedefs ------------------------------------------------------
  typedef std::random_access_iterator_tag                 iterator_category;
  typedef T                                               value_type;
  typedef ptrdiff_t                                       difference_type;
  typedef T*                                              pointer;
  typedef T&                                              reference;

 public:
  t_debug__range_ptr()
   :m_ptr(nullptr)
   ,m_begin(nullptr)
   ,m_end(nullptr)
  {
  }

  //----------------------------------------------------------------------
  t_debug__range_ptr(std::nullptr_t)
   :m_ptr(nullptr)
   ,m_begin(nullptr)
   ,m_end(nullptr)
  {
  }

  //----------------------------------------------------------------------
  t_debug__range_ptr(T*       const ptr,
                     const T* const begin,
                     const T* const end);

  //----------------------------------------------------------------------
  T* get()const;

  self_type& operator ++ ();

  self_type& operator -- ();

  //--------------------------------------------------
  self_type& operator += (uint32_t const x);

  self_type& operator -= (uint32_t const x);

  self_type operator + (uint32_t const x)const;

  self_type operator - (uint32_t const x)const;

  //--------------------------------------------------
  self_type& operator += (uint64_t const x);

  self_type& operator -= (uint64_t const x);

  self_type operator + (uint64_t const x)const;

  self_type operator - (uint64_t const x)const;

  //--------------------------------------------------
  self_type& operator += (__int32 const x);

  self_type& operator -= (__int32 const x);

  self_type operator + (__int32 const x)const;

  self_type operator - (__int32 const x)const;

  //--------------------------------------------------
  self_type& operator += (__int64 const x);

  self_type& operator -= (__int64 const x);

  self_type operator + (__int64 const x)const;

  self_type operator - (__int64 const x)const;

  //--------------------------------------------------
  ptrdiff_t operator - (const self_type& x)const;

  T& operator * () const;

  T& operator [] (size_t const i) const;

 private:
  T*       m_ptr;
  const T* m_begin;
  const T* m_end;
};//class t_debug__range_ptr

////////////////////////////////////////////////////////////////////////////////
//operators for t_debug__range_ptr

template<typename T>
bool operator == (const t_debug__range_ptr<T>& p1,const t_debug__range_ptr<T>& p2)
{
 return p1.get()==p2.get();
}

//----------------------------------------------------------------------
template<typename T>
bool operator != (const t_debug__range_ptr<T>& p1,const t_debug__range_ptr<T>& p2)
{
 return p1.get()!=p2.get();
}

//----------------------------------------------------------------------
template<typename T>
bool operator < (const t_debug__range_ptr<T>& p1,const t_debug__range_ptr<T>& p2)
{
 return p1.get()<p2.get();
}

//----------------------------------------------------------------------
template<typename T>
bool operator <= (const t_debug__range_ptr<T>& p1,const t_debug__range_ptr<T>& p2)
{
 return p1.get()<=p2.get();
}

//----------------------------------------------------------------------
template<typename T>
bool operator >= (const t_debug__range_ptr<T>& p1,const t_debug__range_ptr<T>& p2)
{
 return p1.get()>=p2.get();
}

//----------------------------------------------------------------------
template<typename T>
bool operator == (const t_debug__range_ptr<T>& p1,std::nullptr_t)
{
 return p1.get()==nullptr;
}

//----------------------------------------------------------------------
template<typename T>
bool operator != (const t_debug__range_ptr<T>& p1,std::nullptr_t)
{
 return p1.get()!=nullptr;
}

////////////////////////////////////////////////////////////////////////////////

template<typename T>
bool operator == (const t_debug__range_ptr<T>& p1,typename std::add_const<T>::type* const p2)
{
 return p1.get()==p2;
}

//----------------------------------------------------------------------
template<typename T>
bool operator != (const t_debug__range_ptr<T>& p1,typename std::add_const<T>::type* const p2)
{
 return p1.get()!=p2;
}

//----------------------------------------------------------------------
template<typename T>
bool operator < (const t_debug__range_ptr<T>& p1,typename std::add_const<T>::type* const p2)
{
 return p1.get()<p2;
}

//----------------------------------------------------------------------
template<typename T>
bool operator > (const t_debug__range_ptr<T>& p1,typename std::add_const<T>::type* const p2)
{
 return p1.get()>p2;
}

//----------------------------------------------------------------------
template<typename T>
bool operator <= (const t_debug__range_ptr<T>& p1,typename std::add_const<T>::type* const p2)
{
 return p1.get()<=p2;
}

//----------------------------------------------------------------------
template<typename T>
bool operator >= (const t_debug__range_ptr<T>& p1,typename std::add_const<T>::type* const p2)
{
 return p1.get()>=p2;
}

////////////////////////////////////////////////////////////////////////////////

template<typename T>
bool operator == (const t_debug__range_ptr<T>& p1,typename std::remove_const<T>::type* const p2)
{
 return p1.get()==p2;
}

//----------------------------------------------------------------------
template<typename T>
bool operator != (const t_debug__range_ptr<T>& p1,typename std::remove_const<T>::type* const p2)
{
 return p1.get()!=p2;
}

//----------------------------------------------------------------------
template<typename T>
bool operator < (const t_debug__range_ptr<T>& p1,typename std::remove_const<T>::type* const p2)
{
 return p1.get()<p2;
}

//----------------------------------------------------------------------
template<typename T>
bool operator > (const t_debug__range_ptr<T>& p1,typename std::remove_const<T>::type* const p2)
{
 return p1.get()>p2;
}

//----------------------------------------------------------------------
template<typename T>
bool operator <= (const t_debug__range_ptr<T>& p1,typename std::remove_const<T>::type* const p2)
{
 return p1.get()<=p2;
}

//----------------------------------------------------------------------
template<typename T>
bool operator >= (const t_debug__range_ptr<T>& p1,typename std::remove_const<T>::type* const p2)
{
 return p1.get()>=p2;
}

////////////////////////////////////////////////////////////////////////////////
}/*nms debug*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/debug/t_debug__range_ptr.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
