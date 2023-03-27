////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_value_box.cc
//! \brief   Контейнер для хранения значения или ошибки его формирования.
//! \author  Kovalenko Dmitry
//! \date    05.04.2020
#include <_pch_.h>
#pragma hdrstop

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class IBP_ValueBox

template<class T>
IBP_ValueBox<T>::IBP_ValueBox()
 :m_State(StateCode::None)
 ,m_Value()
 ,m_spExc(nullptr)
{
}//IBP_ValueBox

//------------------------------------------------------------------------
template<class T>
IBP_ValueBox<T>::IBP_ValueBox(self_type&& x)
 :m_State(x.m_State)
 ,m_Value(std::move(x.m_Value))
 ,m_spExc(std::move(x.m_spExc))
{
 //reset source
 x.m_State=StateCode::None;
}//IBP_ValueBox - move

//------------------------------------------------------------------------
template<class T>
template<typename... Args>
IBP_ValueBox<T>::IBP_ValueBox(tag_create_with_value UNUSED_ARG(tag),
                              Args&&...             args)
 :m_State(StateCode::Ok)
 ,m_Value(std::forward<Args>(args)...)
 ,m_spExc(nullptr)
{
}//IBP_ValueBox - tag_create_with_value

//------------------------------------------------------------------------
template<class T>
IBP_ValueBox<T>::IBP_ValueBox(tag_create_with_error UNUSED_ARG(tag),
                              std::exception_ptr    spExc)
 :m_State(StateCode::Error)
 ,m_Value()
 ,m_spExc(spExc)
{
 assert(m_spExc);
}//IBP_ValueBox - tag_create_with_value

//------------------------------------------------------------------------
template<class T>
template<typename... Args>
IBP_ValueBox<T> IBP_ValueBox<T>::CreateBoxWithValue(Args&&... args)
{
 return self_type(tag_create_with_value(),std::forward<Args>(args)...);
}//CreateBoxWithValue

//------------------------------------------------------------------------
template<class T>
IBP_ValueBox<T> IBP_ValueBox<T>::CreateBoxWithError(std::exception_ptr spExc)
{
 assert(spExc);

 return self_type(tag_create_with_error(),spExc);
}//CreateBoxWithError

//------------------------------------------------------------------------
template<class T>
IBP_ValueBox<T>&  IBP_ValueBox<T>::operator = (self_type&& x)
{
 if(this==&x)
  return *this;

 self_type tmp(std::move(x));

 this->Swap(tmp);

 return *this;
}//operator =

//------------------------------------------------------------------------
template<class T>
bool IBP_ValueBox<T>::TestState__IsNone()const
{
 return m_State==StateCode::None;
}//TestState__IsNone

//------------------------------------------------------------------------
template<class T>
bool IBP_ValueBox<T>::TestState__IsOk()const
{
 return m_State==StateCode::Ok;
}//TestState__IsOk

//------------------------------------------------------------------------
template<class T>
bool IBP_ValueBox<T>::TestState__IsError()const
{
 return m_State==StateCode::Error;
}//TestState__IsError

//------------------------------------------------------------------------
template<class T>
const typename IBP_ValueBox<T>::value_type& IBP_ValueBox<T>::Get()const
{
 const wchar_t* const c_bugcheck_src
  =L"IBP_ValueBox<T>::Get";

 if(this->TestState__IsOk())
 {
  return m_Value;
 }//if

 if(this->TestState__IsError())
 {
  assert(m_spExc);

  std::rethrow_exception(m_spExc);
 }//if

 assert(this->TestState__IsNone());

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (c_bugcheck_src,
   L"#001",
   L"no data");

 assert_hint(false);

#if(COMP_BUILD_UNUSED_CODE!=0)
 return m_Value;
#endif
}//Get

//------------------------------------------------------------------------
template<class T>
void IBP_ValueBox<T>::Swap(self_type& x)
{
 std::swap(this->m_Value,x.m_Value);
 std::swap(this->m_spExc,x.m_spExc);
 std::swap(this->m_State,x.m_State);
}//Swap

//------------------------------------------------------------------------
template<class T>
void IBP_ValueBox<T>::Reset()
{
 m_State=StateCode::None;

 m_spExc=nullptr;

 m_Value=value_type();
}//Reset

//------------------------------------------------------------------------
template<class T>
void IBP_ValueBox<T>::SetValue(value_type&& x)
{
 m_Value=std::move(x);

 m_State=StateCode::Ok;

 m_spExc=nullptr;
}//SetValue - value_type&&

//------------------------------------------------------------------------
template<class T>
void IBP_ValueBox<T>::SetError(std::exception_ptr spExc)
{
 assert(spExc);

 m_spExc=std::move(spExc);

 m_State=StateCode::Error;

 m_Value=value_type();
}//SetError

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
