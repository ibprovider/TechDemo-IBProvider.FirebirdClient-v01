////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_value_box.h
//! \brief   Контейнер для хранения значения или ошибки его формирования.
//! \author  Kovalenko Dmitry
//! \date    05.04.2020
#ifndef _ibp_value_box_H_
#define _ibp_value_box_H_

#include "source/error_services/ibp_error_utils.h"

#include <exception>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_ValueBox

/// <summary>
///  Контейнер для хранения значения или ошибки его формирования.
/// </summary>
template<class T>
class IBP_ValueBox COMP_W000006_CLASS_FINAL
{
 private:
  typedef IBP_ValueBox<T>     self_type;

  IBP_ValueBox(const self_type& x)=delete;
  self_type& operator = (const self_type& x)=delete;

 public:
  typedef T                   value_type;

 public:
  IBP_ValueBox();

  IBP_ValueBox(self_type&& x);

 private:
  struct tag_create_with_value{};

  template<typename... Args>
  IBP_ValueBox(tag_create_with_value, Args&&... args);

 private:
  struct tag_create_with_error{};

  IBP_ValueBox(tag_create_with_error, std::exception_ptr spExc);

 public:
 ~IBP_ValueBox()=default;

 public:
  template<typename... Args>
  static self_type CreateBoxWithValue(Args&&... args);

  static self_type CreateBoxWithError(std::exception_ptr spExc);

 public:
  self_type& operator = (self_type&& x);

  //interface --------------------------------------------------
  bool TestState__IsNone()const;

  bool TestState__IsOk()const;

  bool TestState__IsError()const;

  const value_type& Get()const; //throw

  void Swap(self_type& x);

  void Reset();

  //
  // [2020-04-07]
  //  Другие варианты SetValue пока поддерживать не будем.
  //  Только перемещение значения.
  //
  void SetValue(value_type&& x);

  void SetError(std::exception_ptr spExc);

 private:
  enum class StateCode
  {
   None       =0,
   Ok         =1,
   Error      =2,
  };//enum class StateCode

 private:
  StateCode m_State;

  value_type m_Value;

  std::exception_ptr m_spExc;
};//class IBP_ValueBox

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/

namespace std{
////////////////////////////////////////////////////////////////////////////////

template<typename T>
void swap(LCPI_IBP_NMS::IBP_ValueBox<T>& x1,
          LCPI_IBP_NMS::IBP_ValueBox<T>& x2)
{
 x1.Swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
#include "source/structure/ibp_value_box.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
