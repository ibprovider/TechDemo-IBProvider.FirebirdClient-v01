////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_buffer_view.h
//! \brief   The view of buffer data
//! \author  Kovalenko Dmitry
//! \date    29.03.2023
#ifndef _ibp_buffer_view_H_
#define _ibp_buffer_view_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class IBP_BufferView

template<typename T>
class IBP_BufferView LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=IBP_BufferView;

 public:
  IBP_BufferView();

  IBP_BufferView(const self_type&)=default;

  IBP_BufferView(std::nullptr_t);

  template<class TSource>
  IBP_BufferView(TSource& source);

  IBP_BufferView(size_t n,T* ptr);

  self_type& operator = (const self_type&)=default;

  size_t size()const;

  bool empty()const;

  T* data()const;

  T& operator [] (size_t index)const;

 private:
  T* m_pData;

  size_t m_Size;
};//class IBP_BufferView

////////////////////////////////////////////////////////////////////////////////
//class IBP_BufferView - const

template<typename T>
class IBP_BufferView<const T> LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=IBP_BufferView;

 public:
  IBP_BufferView();

  IBP_BufferView(const self_type&)=default;

  IBP_BufferView(std::nullptr_t);

  template<class TSource>
  IBP_BufferView(const TSource& source);

  IBP_BufferView(size_t n,const T* ptr);

  self_type& operator = (const self_type&)=default;

  size_t size()const;

  bool empty()const;

  const T* data()const;

  const T& operator [] (size_t index)const;

 private:
  const T* m_pData;

  size_t m_Size;
};//class IBP_BufferView<const T>

////////////////////////////////////////////////////////////////////////////////
//class IBP_BufferView

template<>
class IBP_BufferView<void> LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=IBP_BufferView;

 public:
  IBP_BufferView();

  IBP_BufferView(const self_type&)=default;

  IBP_BufferView(std::nullptr_t);

  IBP_BufferView(size_t n,void* ptr);

  self_type& operator = (const self_type&)=default;

  size_t size()const;

  bool empty()const;

  void* data()const;

 private:
  void* m_pData;

  size_t m_Size;
};//class IBP_BufferView<void>

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/structure/ibp_buffer_view.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
