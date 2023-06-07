////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 17.08.2015.
#ifndef _cpp_public_lcpi_lib_structure__t_numeric_initializator_H_
#define _cpp_public_lcpi_lib_structure__t_numeric_initializator_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_numeric_initializator

//
// Generic numeric initializator.
//

template<int initializeValue>
class t_numeric_initializator
{
 public:
  static const t_numeric_initializator<initializeValue> instance;

  t_numeric_initializator()
  {
  }

  operator char             () const        {return static_cast<char>            (initializeValue);}
  operator wchar_t          () const        {return static_cast<wchar_t>         (initializeValue);}

  operator unsigned char    () const        {return static_cast<unsigned char>   (initializeValue);}
  operator unsigned short   () const        {return static_cast<unsigned short>  (initializeValue);}
  operator unsigned int     () const        {return static_cast<unsigned int>    (initializeValue);}
  operator unsigned __int64 () const        {return static_cast<unsigned __int64>(initializeValue);}

  operator signed char      () const        {return static_cast<signed char>     (initializeValue);}
  operator signed short     () const        {return static_cast<signed short>    (initializeValue);}
  operator signed int       () const        {return static_cast<signed int>      (initializeValue);}
  operator signed __int64   () const        {return static_cast<signed __int64>  (initializeValue);}

  operator signed long      () const        {return static_cast<signed long>     (initializeValue);}
  operator unsigned long    () const        {return static_cast<unsigned long>   (initializeValue);}

  operator float            () const        {return static_cast<float>           (initializeValue);}
  operator double           () const        {return static_cast<double>          (initializeValue);}

  bool eq(char             const x)const    {return x==static_cast<char>             (initializeValue);}
  bool eq(wchar_t          const x)const    {return x==static_cast<wchar_t>          (initializeValue);}

  bool eq(unsigned char    const x)const    {return x==static_cast<unsigned char>    (initializeValue);}
  bool eq(unsigned short   const x)const    {return x==static_cast<unsigned short>   (initializeValue);}
  bool eq(unsigned int     const x)const    {return x==static_cast<unsigned int>     (initializeValue);}
  bool eq(unsigned __int64 const x)const    {return x==static_cast<unsigned __int64> (initializeValue);}

  bool eq(signed char      const x)const    {return x==static_cast<signed char>      (initializeValue);}
  bool eq(signed short     const x)const    {return x==static_cast<signed short>     (initializeValue);}
  bool eq(signed int       const x)const    {return x==static_cast<signed int>       (initializeValue);}
  bool eq(signed __int64   const x)const    {return x==static_cast<signed __int64>   (initializeValue);}

  bool eq(signed long      const x)const    {return x==static_cast<signed long>      (initializeValue);}
  bool eq(unsigned long    const x)const    {return x==static_cast<unsigned long>    (initializeValue);}

  bool eq(float            const x)const    {return x==static_cast<float>            (initializeValue);}
  bool eq(double           const x)const    {return x==static_cast<double>           (initializeValue);}
};//class t_numeric_initializator

////////////////////////////////////////////////////////////////////////////////

template<int initializeValue>
const t_numeric_initializator<initializeValue> t_numeric_initializator<initializeValue>::instance;

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
