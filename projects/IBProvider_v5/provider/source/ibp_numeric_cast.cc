////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_utils
//! \file    ibp_numeric_cast.cc
//! \brief   Утилиты для преобразования чисел
//! \author  Kovalenko Dmitry
//! \date    04.04.2007
#ifndef _ibp_numeric_cast_CC_
#define _ibp_numeric_cast_CC_

#include "source/error_services/ibp_error.h"
#include <structure/t_numeric_cast.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_utils
//! @{
////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
void ibp_numeric_cast__throw_error(FromType       const x,
                                   const wchar_t* const source,
                                   const wchar_t* const x_name)
{
 typedef structure::t_numeric_limits<ToType> to_lim;

 t_ibp_error exc(E_FAIL,ibp_mce_common__fail_numeric_cast_5);

 exc<<source<<x_name<<x<<to_lim::min_value()<<to_lim::max_value();

 exc.raise_me();
}//ibp_size_cast__throw_error

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Утилита безопасного преобразования числа из одного типа в другой
/// </summary>
//! \param[in]  x
//! \param[in]  source
//! \param[in]  x_name
//!  Символьное имя переменной
//!
//! В случае невозможности преобразования, генерируется исключение
template<typename ToType,typename FromType>
inline ToType ibp_numeric_cast(FromType       const x,
                               const wchar_t* const source,
                               const wchar_t* const x_name)
{
 if(!structure::can_numeric_cast<ToType>(x))
  ibp_numeric_cast__throw_error<ToType>(x,source,x_name);

 return static_cast<ToType>(x);
}//ibp_numeric_cast

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Утилита безопасного преобразования числа из одного типа в другой
/// </summary>
//! \param[out] pTarget
//! \param[in]  x
//! \param[in]  source
//! \param[in]  x_name
//!  Символьное имя переменной
//!
//! В случае невозможности преобразования, генерируется исключение
template<typename ToType,typename FromType>
inline void ibp_numeric_cast(ToType*        const pTarget,
                             FromType       const x,
                             const wchar_t* const source,
                             const wchar_t* const x_name)
{
 assert(pTarget);

 if(!structure::can_numeric_cast<ToType>(x))
  ibp_numeric_cast__throw_error<ToType>(x,source,x_name);

 (*pTarget)=static_cast<ToType>(x);
}//ibp_numeric_cast

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
void ibp_size_cast__throw_error(FromType       const x,
                                const wchar_t* const source,
                                const wchar_t* const x_name)
{
 typedef structure::t_numeric_limits<ToType> to_lim;

 t_ibp_error exc(E_FAIL,ibp_mce_common__fail_size_cast_4);

 exc<<source<<x_name<<x<<to_lim::max_value();

 exc.raise_me();
}//ibp_size_cast__throw_error

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Утилита безопасного преобразования размера из одного типа в другой
/// </summary>
//! \param[in]  x
//! \param[in]  source
//! \param[in]  x_name
//!  Символьное имя переменной
//!
//! В случае невозможности преобразования, генерируется исключение
template<typename ToType,typename FromType>
inline ToType ibp_size_cast(FromType       const x,
                            const wchar_t* const source,
                            const wchar_t* const x_name)
{
 if(!structure::can_numeric_cast<ToType>(x))
  ibp_size_cast__throw_error<ToType>(x,source,x_name);

 return static_cast<ToType>(x);
}//ibp_size_cast

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Утилита безопасного преобразования размера из одного типа в другой
/// </summary>
//! \param[out] pTarget
//! \param[in]  x
//! \param[in]  source
//! \param[in]  x_name
//!  Символьное имя переменной
//!
//! В случае невозможности преобразования, генерируется исключение
template<typename ToType,typename FromType>
inline void ibp_size_cast(ToType*        const pTarget,
                          FromType       const x,
                          const wchar_t* const source,
                          const wchar_t* const x_name)
{
 assert(pTarget);

 if(!structure::can_numeric_cast<ToType>(x))
  ibp_size_cast__throw_error<ToType>(x,source,x_name);

 (*pTarget)=static_cast<ToType>(x);
}//ibp_size_cast

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_can_numeric_add_spec

template<bool T1_IsSign,bool T2_IsSign>
class t_ibp_can_numeric_add_spec{};

//------------------------------------------------------------------------
template<>
class t_ibp_can_numeric_add_spec<false,false>
{
 public:
  template<typename T1,typename T2>
  static bool test(T1 const result,T2 const delta)
  {
   const T1 c_max_result=structure::t_numeric_limits<T1>::max_value();

   if(c_max_result<delta)
    return false;

   if(static_cast<T1>(c_max_result-delta)<result)
    return false;

   return true;
  }//test
};//class t_ibp_can_numeric_add_spec - unsigined+unsigned

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Утилита для тестирования возможности сложения двух чисел
/// </summary>
//! \param[in] result
//! \param[in] delta
template<typename T1,typename T2>
inline bool ibp_can_numeric_add(T1 const result,T2 const delta)
{
 return t_ibp_can_numeric_add_spec
         <structure::t_numeric_limits<T1>::is_signed,
          structure::t_numeric_limits<T2>::is_signed>::test(result,delta);
}//ibp_can_numeric_add

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif