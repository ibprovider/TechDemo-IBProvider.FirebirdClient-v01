////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 14.11.2022
#ifndef _cpp_public_lcpi_lib_structure__t_numeric_utils_CC_
#define _cpp_public_lcpi_lib_structure__t_numeric_utils_CC_

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_numeric_bytes_accessor

inline t_numeric_bytes_accessor::t_numeric_bytes_accessor()
 :m_first(nullptr)
 ,m_last (nullptr)
{
}

//------------------------------------------------------------------------
inline t_numeric_bytes_accessor::t_numeric_bytes_accessor(pointer const first,
                                                          pointer const last)
 :m_first(first)
 ,m_last (last)
{
 assert(m_first<=m_last);
}

//------------------------------------------------------------------------
inline t_numeric_bytes_accessor::size_type t_numeric_bytes_accessor::size()const
{
 assert(m_first<=m_last);

 return m_last-m_first;
}//size

//------------------------------------------------------------------------
inline t_numeric_bytes_accessor::reference
 t_numeric_bytes_accessor::operator [] (size_type i)const
{
 assert(i<this->size());

 return m_first[i];
}//operator []

//------------------------------------------------------------------------
inline t_numeric_bytes_accessor::iterator t_numeric_bytes_accessor::begin()const
{
 #ifndef NDEBUG
  return iterator(this,m_first);
 #else
  return iterator(m_first);
 #endif
}//begin

//------------------------------------------------------------------------
inline t_numeric_bytes_accessor::iterator t_numeric_bytes_accessor::end()const
{
 #ifndef NDEBUG
  return iterator(this,m_last);
 #else
  return iterator(m_last);
 #endif
}//end

////////////////////////////////////////////////////////////////////////////////
//class t_numeric_bytes

template<size_t N>
inline
t_numeric_bytes<N>::t_numeric_bytes()
{
 memset(m_bytes,0,sizeof(m_bytes));
}//t_numeric_bytes

//------------------------------------------------------------------------
template<size_t N>
RELEASE_CODE(inline)
typename t_numeric_bytes<N>::size_type t_numeric_bytes<N>::size()const
{
 return sizeof(m_bytes);
}//size

//------------------------------------------------------------------------
template<size_t N>
typename t_numeric_bytes<N>::accessor_type t_numeric_bytes<N>::accessor()const
{
 return accessor_type(m_bytes,_END_(m_bytes));
}//accessor

//------------------------------------------------------------------------
template<size_t N>
RELEASE_CODE(inline)
typename t_numeric_bytes<N>::reference
 t_numeric_bytes<N>::operator [] (size_type i)
{
 assert(i<sizeof(m_bytes));

 return m_bytes[i];
}//operator []

//------------------------------------------------------------------------
template<size_t N>
RELEASE_CODE(inline)
typename t_numeric_bytes<N>::const_reference
 t_numeric_bytes<N>::operator [] (size_type i)const
{
 assert(i<sizeof(m_bytes));

 return m_bytes[i];
}//operator []

//------------------------------------------------------------------------
template<size_t N>
typename t_numeric_bytes<N>::iterator t_numeric_bytes<N>::begin()
{
 #ifndef NDEBUG
  return iterator(this,m_bytes);
 #else
  return iterator(m_bytes);
 #endif
}//begin

//------------------------------------------------------------------------
template<size_t N>
typename t_numeric_bytes<N>::iterator t_numeric_bytes<N>::end()
{
 #ifndef NDEBUG
  return iterator(this,_END_(m_bytes));
 #else
  return iterator(_END_(m_bytes));
 #endif
}//end

//------------------------------------------------------------------------
template<size_t N>
typename t_numeric_bytes<N>::const_iterator t_numeric_bytes<N>::begin()const
{
 #ifndef NDEBUG
  return const_iterator(this,m_bytes);
 #else
  return const_iterator(m_bytes);
 #endif
}//begin - const

//------------------------------------------------------------------------
template<size_t N>
typename t_numeric_bytes<N>::const_iterator t_numeric_bytes<N>::end()const
{
 #ifndef NDEBUG
  return const_iterator(this,_END_(m_bytes));
 #else
  return const_iterator(_END_(m_bytes));
 #endif
}//end - const

//------------------------------------------------------------------------
template<size_t N>
typename t_numeric_bytes<N>::const_iterator t_numeric_bytes<N>::cbegin()const
{
 #ifndef NDEBUG
  return const_iterator(this,m_bytes);
 #else
  return const_iterator(m_bytes);
 #endif
}//cbegin

//------------------------------------------------------------------------
template<size_t N>
typename t_numeric_bytes<N>::const_iterator t_numeric_bytes<N>::cend()const
{
 #ifndef NDEBUG
  return const_iterator(this,_END_(m_bytes));
 #else
  return const_iterator(_END_(m_bytes));
 #endif
}//cend

////////////////////////////////////////////////////////////////////////////////
//specialisation - unsigned

template<>
inline t_numeric_bytes<sizeof(unsigned __int8)>
 get_numeric_bytes(unsigned __int8 numeric)
{
 typedef unsigned __int8 numeric_type;
 typedef unsigned __int8 byte_type;

 t_numeric_bytes<sizeof(numeric_type)> result;

 result[0]=numeric;

 return result;
}//get_numeric_bytes - UI1

//------------------------------------------------------------------------
template<>
inline t_numeric_bytes<sizeof(unsigned __int16)>
 get_numeric_bytes(unsigned __int16 numeric)
{
 typedef unsigned __int16 numeric_type;
 typedef unsigned __int8  byte_type;

 t_numeric_bytes<sizeof(numeric_type)> result;

 result[0]=byte_type(numeric&0xFF);

 numeric/=static_cast<numeric_type>(256);
 result[1]=byte_type(numeric);

 return result;
}//get_numeric_bytes - UI2

//------------------------------------------------------------------------
template<>
inline t_numeric_bytes<sizeof(unsigned __int32)>
 get_numeric_bytes(unsigned __int32 numeric)
{
 typedef unsigned __int32 numeric_type;
 typedef unsigned __int8  byte_type;

 t_numeric_bytes<sizeof(numeric_type)> result;

 result[0]=byte_type(numeric&0xFF);

 numeric/=256;
 result[1]=byte_type(numeric&0xFF);

 numeric/=256;
 result[2]=byte_type(numeric&0xFF);

 numeric/=256;
 result[3]=byte_type(numeric);

 return result;
}//get_numeric_bytes - UI4

//------------------------------------------------------------------------
template<>
inline t_numeric_bytes<sizeof(unsigned __int64)>
 get_numeric_bytes(unsigned __int64 numeric)
{
 typedef unsigned __int64 numeric_type;
 typedef unsigned __int8  byte_type;

 t_numeric_bytes<sizeof(numeric_type)> result;

 result[0]=byte_type(numeric&0xFF);

 numeric/=256;
 result[1]=byte_type(numeric&0xFF);

 numeric/=256;
 result[2]=byte_type(numeric&0xFF);

 numeric/=256;
 result[3]=byte_type(numeric&0xFF);

 numeric/=256;
 result[4]=byte_type(numeric&0xFF);

 numeric/=256;
 result[5]=byte_type(numeric&0xFF);

 numeric/=256;
 result[6]=byte_type(numeric&0xFF);

 numeric/=256;
 result[7]=byte_type(numeric);

 return result;
}//get_numeric_bytes - UI8

////////////////////////////////////////////////////////////////////////////////
//specialisation - signed

template<>
inline t_numeric_bytes<sizeof(signed __int8)>
 get_numeric_bytes(signed __int8 numeric)
{
 return get_numeric_bytes(static_cast<unsigned __int8>(numeric));
}//get_numeric_bytes - I1

//------------------------------------------------------------------------
template<>
inline t_numeric_bytes<sizeof(signed __int16)>
 get_numeric_bytes(signed __int16 numeric)
{
 return get_numeric_bytes(static_cast<unsigned __int16>(numeric));
}//get_numeric_bytes - I2

//------------------------------------------------------------------------
template<>
inline t_numeric_bytes<sizeof(signed __int32)>
 get_numeric_bytes(signed __int32 numeric)
{
 return get_numeric_bytes(static_cast<unsigned __int32>(numeric));
}//get_numeric_bytes - I4

//------------------------------------------------------------------------
template<>
inline t_numeric_bytes<sizeof(signed __int64)>
 get_numeric_bytes(signed __int64 numeric)
{
 return get_numeric_bytes(static_cast<unsigned __int64>(numeric));
}//get_numeric_bytes - I8

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
