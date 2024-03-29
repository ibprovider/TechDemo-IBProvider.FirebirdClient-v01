////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 17.08.2015.
#ifndef _cpp_public_lcpi_lib_structure__t_numeric_initializator_H_
#define _cpp_public_lcpi_lib_structure__t_numeric_initializator_H_

#include <lcpi/lib/.config.h>

#include <cstdint>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_numeric_initializator

//
// Generic numeric initializator.
//

template<int initializeValue>
class t_numeric_initializator LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static const t_numeric_initializator<initializeValue> instance;

  t_numeric_initializator()=default;

  operator char             () const        {return static_cast<char>            (initializeValue);}

#if (LCPI_CPP_CFG__CAN_USE__wchar_t!=0)
  operator wchar_t          () const        {return static_cast<wchar_t>         (initializeValue);}
#endif

  operator unsigned char    () const        {return static_cast<unsigned char>   (initializeValue);}
  operator std::uint16_t    () const        {return static_cast<std::uint16_t>   (initializeValue);}
  operator std::uint32_t    () const        {return static_cast<std::uint32_t>   (initializeValue);}
  operator std::uint64_t    () const        {return static_cast<std::uint64_t>   (initializeValue);}

  operator signed char      () const        {return static_cast<signed char>     (initializeValue);}
  operator std::int16_t     () const        {return static_cast<std::int16_t>    (initializeValue);}
  operator std::int32_t     () const        {return static_cast<std::int32_t>    (initializeValue);}
  operator std::int64_t     () const        {return static_cast<std::int64_t>    (initializeValue);}

#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  operator signed long      () const        {return static_cast<signed long>     (initializeValue);}
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  operator unsigned long    () const        {return static_cast<unsigned long>   (initializeValue);}
#endif

  operator float            () const        {return static_cast<float>           (initializeValue);}
  operator double           () const        {return static_cast<double>          (initializeValue);}

  bool eq(char             const x)const    {return x==static_cast<char>             (initializeValue);}
  bool eq(wchar_t          const x)const    {return x==static_cast<wchar_t>          (initializeValue);}

  bool eq(unsigned char    const x)const    {return x==static_cast<unsigned char>    (initializeValue);}
  bool eq(std::uint16_t    const x)const    {return x==static_cast<std::uint16_t>    (initializeValue);}
  bool eq(std::uint32_t    const x)const    {return x==static_cast<std::uint32_t>    (initializeValue);}
  bool eq(std::uint64_t    const x)const    {return x==static_cast<std::uint64_t>    (initializeValue);}

  bool eq(signed char      const x)const    {return x==static_cast<signed char>      (initializeValue);}
  bool eq(std::int16_t     const x)const    {return x==static_cast<std::int16_t>     (initializeValue);}
  bool eq(std::int32_t     const x)const    {return x==static_cast<std::int32_t>     (initializeValue);}
  bool eq(std::int64_t     const x)const    {return x==static_cast<std::int64_t>     (initializeValue);}

#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  bool eq(signed long      const x)const    {return x==static_cast<signed long>      (initializeValue);}
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  bool eq(unsigned long    const x)const    {return x==static_cast<unsigned long>    (initializeValue);}
#endif

  bool eq(float            const x)const    {return x==static_cast<float>            (initializeValue);}
  bool eq(double           const x)const    {return x==static_cast<double>           (initializeValue);}
};//class t_numeric_initializator

////////////////////////////////////////////////////////////////////////////////

template<int initializeValue>
const t_numeric_initializator<initializeValue> t_numeric_initializator<initializeValue>::instance;

////////////////////////////////////////////////////////////////////////////////

template<int initializeValue>
bool operator != (const t_numeric_initializator<initializeValue>& n,unsigned char v)
{
 return !n.eq(v);
}//operator != unsigned char

////////////////////////////////////////////////////////////////////////////////

template<int initializeValue>
bool operator != (unsigned char const v,const t_numeric_initializator<initializeValue>& n)
{
 return !n.eq(v);
}//operator != unsigned char

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
