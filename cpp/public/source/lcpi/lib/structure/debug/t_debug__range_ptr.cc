////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 26.05.2023.
#ifndef _cpp_public_lcpi_lib_structure_debug__t_debug__range_ptr_CC_
#define _cpp_public_lcpi_lib_structure_debug__t_debug__range_ptr_CC_

namespace lcpi{namespace lib{namespace structure{namespace debug{
////////////////////////////////////////////////////////////////////////////////
//class t_debug__range_ptr

template<typename T>
t_debug__range_ptr<T>::t_debug__range_ptr(T*       const ptr,
                                          const T* const begin,
                                          const T* const end)
 :m_ptr(ptr)
 ,m_begin(begin)
 ,m_end(end)
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);
}

//------------------------------------------------------------------------
template<typename T>
T* t_debug__range_ptr<T>::get()const
{
 return m_ptr;
}

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T>& t_debug__range_ptr<T>::operator ++ ()
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<m_end);

 ++m_ptr;

 return *this;
}//operator ++

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T>& t_debug__range_ptr<T>::operator -- ()
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<m_ptr);
 LCPI__assert(m_ptr<=m_end);

 --m_ptr;

 return *this;
}//operator --

//------------------------------------------------------------------------  UINT32_T
template<typename T>
t_debug__range_ptr<T>& t_debug__range_ptr<T>::operator += (uint32_t const x)
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 LCPI__assert(x<=size_t(m_end-m_ptr));

 m_ptr+=x;

 return *this;
}// operator += uint32_t

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T>& t_debug__range_ptr<T>::operator -= (uint32_t const x)
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 LCPI__assert(x<=size_t(m_ptr-m_begin));

 m_ptr-=x;

 return *this;
}// operator -= uint32_t

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T> t_debug__range_ptr<T>::operator + (uint32_t const x)const
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 LCPI__assert(x<=size_t(m_end-m_ptr));

 return self_type(m_ptr+x,m_begin,m_end);
}// operator + uint32_t

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T> t_debug__range_ptr<T>::operator - (uint32_t const x)const
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 LCPI__assert(x<=size_t(m_ptr-m_begin));

 return self_type(m_ptr-x,m_begin,m_end);
}// operator - uint32_t

//------------------------------------------------------------------------  UINT64_T
template<typename T>
t_debug__range_ptr<T>& t_debug__range_ptr<T>::operator += (uint64_t const x)
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 LCPI__assert(x<=size_t(m_end-m_ptr));

 m_ptr+=x;

 return *this;
}// operator += uint64_t

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T>& t_debug__range_ptr<T>::operator -= (uint64_t const x)
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 LCPI__assert(x<=size_t(m_ptr-m_begin));

 m_ptr-=x;

 return *this;
}// operator -= uint64_t

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T> t_debug__range_ptr<T>::operator + (uint64_t const x)const
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 LCPI__assert(x<=size_t(m_end-m_ptr));

 return self_type(m_ptr+x,m_begin,m_end);
}// operator + uint64_t

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T> t_debug__range_ptr<T>::operator - (uint64_t const x)const
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 LCPI__assert(x<=size_t(m_ptr-m_begin));

 return self_type(m_ptr-x,m_begin,m_end);
}// operator - uint64_t

//------------------------------------------------------------------------ __INT32
template<typename T>
t_debug__range_ptr<T>& t_debug__range_ptr<T>::operator += (__int32 const x)
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 if(x<0)
 {
  const auto d=size_t(m_ptr-m_begin);

  if(d<=(size_t)(std::numeric_limits<__int32>::max)())
  {
   LCPI__assert(x<=-__int32(d));
  }
 }
 else
 {
  LCPI__assert(x<=(m_end-m_ptr));
 }//else

 m_ptr+=x;

 return *this;
}// operator += __int32

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T>& t_debug__range_ptr<T>::operator -= (__int32 const x)
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 if(x<0)
 {
  const auto d=size_t(m_end-m_ptr);

  if(d<=(size_t)(std::numeric_limits<__int32>::max)())
  {
   LCPI__assert(x<=-__int32(d));
  }
 }
 else
 {
  LCPI__assert(size_t(x)<=size_t(m_ptr-m_begin));
 }//else

 m_ptr-=x;

 return *this;
}// operator -= __int32

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T> t_debug__range_ptr<T>::operator + (__int32 const x)const
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 if(x<0)
 {
  const auto d=size_t(m_ptr-m_begin);

  if(d<=(size_t)(std::numeric_limits<__int32>::max)())
  {
   LCPI__assert(x<=-__int32(d));
  }
 }
 else
 {
  LCPI__assert(size_t(x)<=size_t(m_end-m_ptr));
 }

 return self_type(m_ptr+x,m_begin,m_end);
}// operator + __int32

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T> t_debug__range_ptr<T>::operator - (__int32 const x)const
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 if(x<0)
 {
  const auto d=size_t(m_end-m_ptr);

  if(d<=(size_t)(std::numeric_limits<__int32>::max)())
  {
   LCPI__assert(x<=-__int32(d));
  }
 }
 else
 {
  LCPI__assert(size_t(x)<=size_t(m_ptr-m_begin));
 }//else

 return self_type(m_ptr-x,m_begin,m_end);
}// operator - __int32

//------------------------------------------------------------------------ __INT64
template<typename T>
t_debug__range_ptr<T>& t_debug__range_ptr<T>::operator += (__int64 const x)
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 if(x<0)
 {
  const auto d=size_t(m_ptr-m_begin);

  if(d<=(size_t)(std::numeric_limits<__int64>::max)())
  {
   LCPI__assert(x<=-__int64(d));
  }
 }
 else
 {
  LCPI__assert(x<=(m_end-m_ptr));
 }//else

 m_ptr+=x;

 return *this;
}// operator += __int64

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T>& t_debug__range_ptr<T>::operator -= (__int64 const x)
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 if(x<0)
 {
  const auto d=size_t(m_end-m_ptr);

  if(d<=(size_t)(std::numeric_limits<__int64>::max)())
  {
   LCPI__assert(x<=-__int64(d));
  }
 }
 else
 {
  LCPI__assert(size_t(x)<=size_t(m_ptr-m_begin));
 }//else

 m_ptr-=x;

 return *this;
}// operator -= __int64

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T> t_debug__range_ptr<T>::operator + (__int64 const x)const
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 if(x<0)
 {
  const auto d=size_t(m_ptr-m_begin);

  if(d<=(size_t)(std::numeric_limits<__int64>::max)())
  {
   LCPI__assert(x<=-__int64(d));
  }
 }
 else
 {
  LCPI__assert(size_t(x)<=size_t(m_end-m_ptr));
 }

 return self_type(m_ptr+x,m_begin,m_end);
}// operator + __int64

//------------------------------------------------------------------------
template<typename T>
t_debug__range_ptr<T> t_debug__range_ptr<T>::operator - (__int64 const x)const
{
 LCPI__assert(m_begin<=m_end);
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<=m_end);

 if(x<0)
 {
  const auto d=size_t(m_end-m_ptr);

  if(d<=(size_t)(std::numeric_limits<__int64>::max)())
  {
   LCPI__assert(x<=-__int64(d));
  }
 }
 else
 {
  LCPI__assert(size_t(x)<=size_t(m_ptr-m_begin));
 }//else

 return self_type(m_ptr-x,m_begin,m_end);
}// operator - __int64

//------------------------------------------------------------------------
template<typename T>
ptrdiff_t t_debug__range_ptr<T>::operator - (const self_type& x)const
{
 return m_ptr-x.m_ptr;
}// operator -

//------------------------------------------------------------------------
template<typename T>
T& t_debug__range_ptr<T>::operator * () const
{
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<m_end);

 return *m_ptr;
}// operator *

//------------------------------------------------------------------------
template<typename T>
T& t_debug__range_ptr<T>::operator [] (size_t const i) const
{
 LCPI__assert(m_begin<=m_ptr);
 LCPI__assert(m_ptr<m_end);

 LCPI__assert(i<size_t(m_end-m_ptr));

 return m_ptr[i];
}// operator []

////////////////////////////////////////////////////////////////////////////////
}/*nms debug*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#endif
