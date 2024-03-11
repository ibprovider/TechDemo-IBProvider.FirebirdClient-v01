////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_buffer_view.cc
//! \brief   The proxy to buffer data
//! \author  Kovalenko Dmitry
//! \date    29.03.2023
#ifndef _ibp_buffer_view_CC_
#define _ibp_buffer_view_CC_

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class IBP_BufferView

template<typename T>
IBP_BufferView<T>::IBP_BufferView()
 :m_pData(nullptr)
 ,m_Size(0)
{
}

//------------------------------------------------------------------------
template<typename T>
IBP_BufferView<T>::IBP_BufferView(std::nullptr_t)
 :m_pData(nullptr)
 ,m_Size(0)
{
}

//------------------------------------------------------------------------
template<typename T>
template<class TSource>
IBP_BufferView<T>::IBP_BufferView(TSource& source)
 :m_pData(source.data())
 ,m_Size(source.size())
{
}

//------------------------------------------------------------------------
template<typename T>
IBP_BufferView<T>::IBP_BufferView(size_t n,T* ptr)
 :m_pData(ptr)
 ,m_Size(n)
{
 CHECK_READ_WRITE_TYPED_PTR(m_pData,m_Size)
}

//------------------------------------------------------------------------
template<typename T>
size_t IBP_BufferView<T>::size()const
{
 return m_Size;
}//size

//------------------------------------------------------------------------
template<typename T>
bool IBP_BufferView<T>::empty()const
{
 return m_Size==0;
}//empty

//------------------------------------------------------------------------
template<typename T>
T* IBP_BufferView<T>::data()const
{
 return m_pData;
}//data

//------------------------------------------------------------------------
template<typename T>
T& IBP_BufferView<T>::operator [] (size_t const index)const
{
 assert(index<m_Size);

 return m_pData[index];
}//operator []

////////////////////////////////////////////////////////////////////////////////
//class IBP_BufferView - const

template<typename T>
IBP_BufferView<const T>::IBP_BufferView()
 :m_pData(nullptr)
 ,m_Size(0)
{
}

//------------------------------------------------------------------------
template<typename T>
IBP_BufferView<const T>::IBP_BufferView(std::nullptr_t)
 :m_pData(nullptr)
 ,m_Size(0)
{
}

//------------------------------------------------------------------------
template<typename T>
template<class TSource>
IBP_BufferView<const T>::IBP_BufferView(const TSource& source)
 :m_pData(source.data())
 ,m_Size(source.size())
{
}

//------------------------------------------------------------------------
template<typename T>
IBP_BufferView<const T>::IBP_BufferView(size_t n,const T* ptr)
 :m_pData(ptr)
 ,m_Size(n)
{
 CHECK_READ_TYPED_PTR(m_pData,m_Size)
}

//------------------------------------------------------------------------
template<typename T>
size_t IBP_BufferView<const T>::size()const
{
 return m_Size;
}//size

//------------------------------------------------------------------------
template<typename T>
bool IBP_BufferView<const T>::empty()const
{
 return m_Size==0;
}//empty

//------------------------------------------------------------------------
template<typename T>
const T* IBP_BufferView<const T>::data()const
{
 return m_pData;
}//data

//------------------------------------------------------------------------
template<typename T>
const T& IBP_BufferView<const T>::operator [] (size_t const index)const
{
 assert(index<m_Size);

 return m_pData[index];
}//operator [] - const

////////////////////////////////////////////////////////////////////////////////
//class IBP_BufferView<void>

inline IBP_BufferView<void>::IBP_BufferView()
 :m_pData(nullptr)
 ,m_Size(0)
{
}

//------------------------------------------------------------------------
inline IBP_BufferView<void>::IBP_BufferView(std::nullptr_t)
 :m_pData(nullptr)
 ,m_Size(0)
{
}

//------------------------------------------------------------------------
inline IBP_BufferView<void>::IBP_BufferView(size_t const n,void* const ptr)
 :m_pData(ptr)
 ,m_Size(n)
{
 CHECK_READ_WRITE_PTR(m_pData,m_Size)
}

//------------------------------------------------------------------------
inline size_t IBP_BufferView<void>::size()const
{
 return m_Size;
}//size

//------------------------------------------------------------------------
inline bool IBP_BufferView<void>::empty()const
{
 return m_Size==0;
}//empty

//------------------------------------------------------------------------
inline void* IBP_BufferView<void>::data()const
{
 return m_pData;
}//data

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
