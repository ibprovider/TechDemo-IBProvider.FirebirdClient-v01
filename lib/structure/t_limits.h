////////////////////////////////////////////////////////////////////////////////
//alternative for std::numeric_limits
//                                           Dmitry Kovalenko. 12 april, 2003.
#ifndef _t_limits_H_
#define _t_limits_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

//#include <structure/t_common.h>  //BUG FIX: recursive include ...
#include <limits>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class T>
class t_numeric_limits;

template<>
class t_numeric_limits<signed char>;

template<>
class t_numeric_limits<unsigned char>;

template<>
class t_numeric_limits<signed short>;

template<>
class t_numeric_limits<unsigned short>;

template<>
class t_numeric_limits<signed long>;

template<>
class t_numeric_limits<unsigned long>;

template<>
class t_numeric_limits<signed int>;

template<>
class t_numeric_limits<unsigned int>;

template<>
class t_numeric_limits<signed __int64>;

template<>
class t_numeric_limits<unsigned __int64>;

template<>
class t_numeric_limits<float>;

template<>
class t_numeric_limits<double>;

template<>
class t_numeric_limits<wchar_t>;

////////////////////////////////////////////////////////////////////////////////
//generic t_numeric_limits

template<class T>
class t_numeric_limits
{
 public: //typedefs ------------------------------------------------------
  typedef T                        numeric_type;
};//class t_numeric_limits<T>

////////////////////////////////////////////////////////////////////////////////
//Helper class t_numeric_limits_consts

template<class TDummy=void*>
class t_numeric_limits_consts
{
 public:
  static const signed __int64      sm_i8_min;
  static const signed __int64      sm_i8_max;

  static const unsigned __int64    sm_ui8_min;
  static const unsigned __int64    sm_ui8_max;
};//class t_numeric_limits_consts

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<signed char>

template<>
class t_numeric_limits<signed char>
{
 public: //typedefs ------------------------------------------------------
  typedef signed char              numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed char              signed_numeric_type;
  typedef unsigned char            unsigned_numeric_type;

  typedef signed int               print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return SCHAR_MIN;}
  static inline const_numeric_type max_value(){return SCHAR_MAX;}

  static const bool is_signed      =true;
  static const bool is_integer     =true;
};//t_numeric_limits<signed char>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<unsigned shar>

template<>
class t_numeric_limits<unsigned char>
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned char            numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed char              signed_numeric_type;
  typedef unsigned char            unsigned_numeric_type;

  typedef unsigned int             print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return 0;}
  static inline const_numeric_type max_value(){return UCHAR_MAX;}

  static const bool is_signed      =false;
  static const bool is_integer     =true;
};//t_numeric_limits<unsigned char>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<signed short>

template<>
class t_numeric_limits<signed short>
{
 public: //typedefs ------------------------------------------------------
  typedef signed short             numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed short             signed_numeric_type;
  typedef unsigned short           unsigned_numeric_type;

  typedef signed int               print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return SHRT_MIN;}
  static inline const_numeric_type max_value(){return SHRT_MAX;}

  static const bool is_signed      =true;
  static const bool is_integer     =true;
};//t_numeric_limits<signed short>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<unsigned short>

template<>
class t_numeric_limits<unsigned short>
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned short           numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed short             signed_numeric_type;
  typedef unsigned short           unsigned_numeric_type;

  typedef unsigned int             print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return 0;}
  static inline const_numeric_type max_value(){return USHRT_MAX;}

  static const bool is_signed      =false;
  static const bool is_integer     =true;
};//t_numeric_limits<unsigned short>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<signed long>

template<>
class t_numeric_limits<signed long>
{
 public: //typedefs ------------------------------------------------------
  typedef signed long              numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed long              signed_numeric_type;
  typedef unsigned long            unsigned_numeric_type;

  typedef signed long              print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return LONG_MIN;}
  static inline const_numeric_type max_value(){return LONG_MAX;}

  static const bool is_signed      =true;
  static const bool is_integer     =true;
};//t_numeric_limits<signed long>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<unsigned long>

template<>
class t_numeric_limits<unsigned long>
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned long            numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed long              signed_numeric_type;
  typedef unsigned long            unsigned_numeric_type;

  typedef unsigned long            print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return 0;}
  static inline const_numeric_type max_value(){return ULONG_MAX;}

  static const bool is_signed      =false;
  static const bool is_integer     =true;
};//t_numeric_limits<unsigned long>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<signed int>

template<>
class t_numeric_limits<signed int>
{
 public: //typedefs ------------------------------------------------------
  typedef signed int               numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed int               signed_numeric_type;
  typedef unsigned int             unsigned_numeric_type;

  typedef signed int               print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return INT_MIN;}
  static inline const_numeric_type max_value(){return INT_MAX;}

  static const bool is_signed      =true;
  static const bool is_integer     =true;
};//t_numeric_limits<signed int>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<unsigned int>

template<>
class t_numeric_limits<unsigned int>
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned int             numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed int               signed_numeric_type;
  typedef unsigned int             unsigned_numeric_type;

  typedef unsigned int             print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return 0;}
  static inline const_numeric_type max_value(){return UINT_MAX;}

  static const bool is_signed      =false;
  static const bool is_integer     =true;
};//t_numeric_limits<unsigned int>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<signed __int64>

template<>
class t_numeric_limits<signed __int64>
{
 public: //typedefs ------------------------------------------------------
  typedef signed __int64           numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed __int64           signed_numeric_type;
  typedef unsigned __int64         unsigned_numeric_type;

  typedef signed __int64           print_numeric_type;

 public: //---------------------------------------------------------------
  static inline numeric_type min_value(){return t_numeric_limits_consts<>::sm_i8_min;}
  static inline numeric_type max_value(){return t_numeric_limits_consts<>::sm_i8_max;}

  static const bool is_signed      =true;
  static const bool is_integer     =true;
};//t_numeric_limits<signed __int64>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<unsigned __int64>

template<>
class t_numeric_limits<unsigned __int64>
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned __int64         numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed __int64           signed_numeric_type;
  typedef unsigned __int64         unsigned_numeric_type;

  typedef unsigned __int64         print_numeric_type;

 public: //---------------------------------------------------------------
  static inline numeric_type min_value(){return t_numeric_limits_consts<>::sm_ui8_min;}
  static inline numeric_type max_value(){return t_numeric_limits_consts<>::sm_ui8_max;;}

  static const bool is_signed      =false;
  static const bool is_integer     =true;
};//t_numeric_limits<unsigned __int64>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<float>

template<>
class t_numeric_limits<float>
{
 public: //typedefs ------------------------------------------------------
  typedef float                    numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef float                    signed_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return -FLT_MAX;}
  static inline const_numeric_type max_value(){return FLT_MAX;}

  static const bool is_signed      =true;
  static const bool is_integer     =false;
};//t_numeric_limits<float>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<double>

template<>
class t_numeric_limits<double>
{
 public: //typedefs ------------------------------------------------------
  typedef double                   numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef double                   signed_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return -DBL_MAX;}
  static inline const_numeric_type max_value(){return DBL_MAX;}

  static const bool is_signed      =true;
  static const bool is_integer     =false;
};//t_numeric_limits<double>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<wchar_t>

template<>
class t_numeric_limits<wchar_t>
{
 public: //typedefs ------------------------------------------------------
  typedef wchar_t                  numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef wchar_t                  unsigned_numeric_type;

  typedef unsigned int             print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return 0;}
  static inline const_numeric_type max_value(){return USHRT_MAX;}

  static const bool is_signed      =false;
  static const bool is_integer     =true;
};//t_numeric_limits<wchar_t>

////////////////////////////////////////////////////////////////////////////////
//class t_numeric_limits_consts - implementations

template<class TDummy>
const signed __int64  t_numeric_limits_consts<TDummy>::sm_i8_min=_I64_MIN;

template<class TDummy>
const signed __int64  t_numeric_limits_consts<TDummy>::sm_i8_max=_I64_MAX;

template<class TDummy>
const unsigned __int64  t_numeric_limits_consts<TDummy>::sm_ui8_min=0;

template<class TDummy>
const unsigned __int64  t_numeric_limits_consts<TDummy>::sm_ui8_max=_UI64_MAX;

////////////////////////////////////////////////////////////////////////////////

template<class T>
inline t_numeric_limits<T> get_numeric_limits(const T& /*x*/)
{
 //Reference of IN-parameter may be invalid. But we do not trying read it value.

 return t_numeric_limits<T>();
}//get_numeric_limits

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
