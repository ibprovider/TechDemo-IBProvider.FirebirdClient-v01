////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_flags.h
//! \brief   Вспомогательный класс для управления флагами.
//! \author  Kovalenko Dmitry
//! \date    22.04.2015.
#ifndef _ibp_flags_H_
#define _ibp_flags_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_Flags

/// <summary>
///  Вспомогательный класс для управления флагами.
/// </summary>
///  Класс позаимствован из исходных текстов Firebird 2.5.
template <typename T>
class IBP_Flags
{
 public:
  IBP_Flags()
   :m_flags()
  {
   assert_s(T()==T(0));

   // Require base flags field to be unsigned.
   // This is a compile-time assertion; it won't build if you use a signed flags field.
   typedef int dummy[T(-1) > 0];
  }//IBP_Flags

  explicit IBP_Flags(const T flags)
   :m_flags(flags)
  {
   // Require base flags field to be unsigned.
   // This is a compile-time assertion; it won't build if you use a signed flags field.
   typedef int dummy[T(-1)>0];
  }//IBP_Flags

  // At least one bit in the parameter is 1 in the object.
  bool test(const T flags)const
  {
   return (m_flags&flags)!=0;
  }//test

  // All bits received as parameter are 1 in the object.
  bool testAll(const T flags)const
  {
   return (m_flags&flags)==flags;
  }//testAll

  bool empty()const
  {
   assert_s(T()==T(0));

   return m_flags==T();
  }//empty

  bool equal(const T flags)const
  {
   return m_flags==flags;
  }//value

  void set(const T flags)
  {
   m_flags|=flags;
  }//set

  void clear(const T flags)
  {
   m_flags&=~flags;
  }//clear

  void reset()
  {
   assert_s(T()==T(0));

   m_flags=T();
  }//reset

 private:
  template<typename T,bool S=std::is_enum<T>::value >
  struct storage_type{using type=T;};

  template<typename T>
  struct storage_type<T,true>{using type=typename std::underlying_type<T>::type;};

  using storage_type_t=typename storage_type<T>::type;

 private:
  storage_type_t m_flags;
};//class IBP_Flags

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
