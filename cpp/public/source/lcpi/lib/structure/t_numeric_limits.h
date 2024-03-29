////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 12.04.2003.
#ifndef _cpp_public_lcpi_lib_structure__t_numeric_limits_H_
#define _cpp_public_lcpi_lib_structure__t_numeric_limits_H_

#include <lcpi/lib/.config.h>

#include <cstdint>
#include <limits>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class T>
class t_numeric_limits;

template<>
class t_numeric_limits<signed char>;

template<>
class t_numeric_limits<unsigned char>;

template<>
class t_numeric_limits<std::int16_t>;

template<>
class t_numeric_limits<std::uint16_t>;

template<>
class t_numeric_limits<std::int32_t>;

template<>
class t_numeric_limits<std::uint32_t>;

template<>
class t_numeric_limits<std::int64_t>;

template<>
class t_numeric_limits<std::uint64_t>;

#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
template<>
class t_numeric_limits<signed long>;
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
template<>
class t_numeric_limits<unsigned long>;
#endif

template<>
class t_numeric_limits<float>;

template<>
class t_numeric_limits<double>;

#if (LCPI_CPP_CFG__CAN_USE__wchar_t!=0)
template<>
class t_numeric_limits<wchar_t>;
#endif

////////////////////////////////////////////////////////////////////////////////
//generic t_numeric_limits

template<class T>
class t_numeric_limits LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  using numeric_type=T;
};//class t_numeric_limits<T>

////////////////////////////////////////////////////////////////////////////////
//Helper class t_numeric_limits_consts

class t_numeric_limits_consts LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static const std::int64_t      sm_i8_min=INT64_MIN;
  static const std::int64_t      sm_i8_max=INT64_MAX;

  static const std::uint64_t     sm_ui8_min=0;
  static const std::uint64_t     sm_ui8_max=UINT64_MAX;
};//class t_numeric_limits_consts

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<signed char>

template<>
class t_numeric_limits<signed char> LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  typedef signed char              numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed char              signed_numeric_type;
  typedef unsigned char            unsigned_numeric_type;

  typedef signed int               print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){LCPI__assert_s(SCHAR_MIN==-128); return SCHAR_MIN;}
  static inline const_numeric_type max_value(){LCPI__assert_s(SCHAR_MAX==127);  return SCHAR_MAX;}

  static const bool is_signed      =true;
  static const bool is_integer     =true;
};//class t_numeric_limits<signed char>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<unsigned shar>

template<>
class t_numeric_limits<unsigned char> LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned char            numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef signed char              signed_numeric_type;
  typedef unsigned char            unsigned_numeric_type;

  typedef unsigned int             print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return 0;}
  static inline const_numeric_type max_value(){LCPI__assert_s(UCHAR_MAX==255); return UCHAR_MAX;}

  static const bool is_signed      =false;
  static const bool is_integer     =true;
};//class t_numeric_limits<unsigned char>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<signed short>

template<>
class t_numeric_limits<std::int16_t> LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  typedef std::int16_t             numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef std::int16_t             signed_numeric_type;
  typedef std::uint16_t            unsigned_numeric_type;

  typedef signed int               print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){LCPI__assert_s(INT16_MIN==-32768); return INT16_MIN;}
  static inline const_numeric_type max_value(){LCPI__assert_s(INT16_MAX==+32767); return INT16_MAX;}

  static const bool is_signed      =true;
  static const bool is_integer     =true;
};//class t_numeric_limits<std::int16_t>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<std::uint16_t>

template<>
class t_numeric_limits<std::uint16_t> LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  typedef std::uint16_t            numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef std::int16_t             signed_numeric_type;
  typedef std::uint16_t            unsigned_numeric_type;

  typedef unsigned int             print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return 0;}
  static inline const_numeric_type max_value(){LCPI__assert_s(UINT16_MAX==+65535); return UINT16_MAX;}

  static const bool is_signed      =false;
  static const bool is_integer     =true;
};//class t_numeric_limits<std::uint16_t>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<std::int32_t>

template<>
class t_numeric_limits<std::int32_t> LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  typedef std::int32_t             numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef std::int32_t             signed_numeric_type;
  typedef std::uint32_t            unsigned_numeric_type;

  typedef signed int               print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){LCPI__assert_s(INT32_MIN==(-2147483647-1)); return INT32_MIN;}
  static inline const_numeric_type max_value(){LCPI__assert_s(INT32_MAX==(+2147483647)); return INT32_MAX;}

  static const bool is_signed      =true;
  static const bool is_integer     =true;
};//class t_numeric_limits<std::int32_t>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<std::uint32_t>

template<>
class t_numeric_limits<std::uint32_t> LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  typedef std::uint32_t            numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef std::int32_t             signed_numeric_type;
  typedef std::uint32_t            unsigned_numeric_type;

  typedef unsigned int             print_numeric_type;

 public: //---------------------------------------------------------------
  static inline const_numeric_type min_value(){return 0;}
  static inline const_numeric_type max_value(){LCPI__assert_s(UINT32_MAX==+4294967295u); return UINT32_MAX;}

  static const bool is_signed      =false;
  static const bool is_integer     =true;
};//class t_numeric_limits<std::uint32_t>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<std::int64_t>

template<>
class t_numeric_limits<std::int64_t> LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  typedef std::int64_t             numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef std::int64_t             signed_numeric_type;
  typedef std::uint64_t            unsigned_numeric_type;

  typedef std::int64_t             print_numeric_type;

 public: //---------------------------------------------------------------
  static inline numeric_type min_value(){return INT64_MIN;}
  static inline numeric_type max_value(){return INT64_MAX;}

  static const bool is_signed      =true;
  static const bool is_integer     =true;
};//class t_numeric_limits<std::int64_t>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<std::uint64_t>

template<>
class t_numeric_limits<std::uint64_t> LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  typedef std::uint64_t            numeric_type;
  typedef const numeric_type       const_numeric_type;

  typedef std::int64_t             signed_numeric_type;
  typedef std::uint64_t            unsigned_numeric_type;

  typedef std::uint64_t            print_numeric_type;

 public: //---------------------------------------------------------------
  static inline numeric_type min_value(){return 0;}
  static inline numeric_type max_value(){return UINT64_MAX;}

  static const bool is_signed      =false;
  static const bool is_integer     =true;
};//class t_numeric_limits<std::uint64_t>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<signed long>

#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)

template<>
class t_numeric_limits<signed long> LCPI_CPP_CFG__CLASS__FINAL
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
};//class t_numeric_limits<signed long>

#endif // LCPI_CPP_CFG__CAN_USE__signed_long!=0

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<unsigned long>

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)

template<>
class t_numeric_limits<unsigned long> LCPI_CPP_CFG__CLASS__FINAL
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
};//class t_numeric_limits<unsigned long>

#endif // LCPI_CPP_CFG__CAN_USE__unsigned_long!=0

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<float>

template<>
class t_numeric_limits<float> LCPI_CPP_CFG__CLASS__FINAL
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
};//class t_numeric_limits<float>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<double>

template<>
class t_numeric_limits<double> LCPI_CPP_CFG__CLASS__FINAL
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
};//class t_numeric_limits<double>

////////////////////////////////////////////////////////////////////////////////
//specialization class t_numeric_limits<wchar_t>

#if (LCPI_CPP_CFG__CAN_USE__wchar_t!=0)

template<>
class t_numeric_limits<wchar_t> LCPI_CPP_CFG__CLASS__FINAL
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
};//class t_numeric_limits<wchar_t>

#endif // LCPI_CPP_CFG__CAN_USE__wchar_t!=0

////////////////////////////////////////////////////////////////////////////////

template<class T>
inline t_numeric_limits<T> get_numeric_limits(const T& /*x*/)
{
 //Reference of IN-parameter may be invalid. But we do not trying read it value.

 return t_numeric_limits<T>();
}//get_numeric_limits

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
