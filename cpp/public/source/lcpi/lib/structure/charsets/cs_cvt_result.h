////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 29.03.2024.
#ifndef _cpp_public_lcpi_lib_structure__cs_cvt_result_H_
#define _cpp_public_lcpi_lib_structure__cs_cvt_result_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//enum class cs_cvt_result_code

enum class cs_cvt_result_code
{
 ok                =0,
 bad_input         =1,
 trunc_input       =2,
 small_output      =3,
 bad_input_packing =4,
};//enum class cs_cvt_result_code

////////////////////////////////////////////////////////////////////////////////
//class t_cs_cvt_result

template<typename InputIterator,typename OutputIterator>
class cs_cvt_result LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  using code_type=cs_cvt_result_code;

  using input_type=InputIterator;
  using output_type=OutputIterator;

 public:
  code_type   code;
  input_type  input;
  output_type output;

  cs_cvt_result(code_type c,input_type i,output_type o)
   :code(c)
   ,input(i)
   ,output(o)
  {
  }
};//class cs_cvt_result

////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////

template<typename InputIterator,typename OutputIterator>
cs_cvt_result<InputIterator,OutputIterator>
 make_cs_cvt_result(cs_cvt_result_code code,InputIterator input,OutputIterator output)
{
 return cs_cvt_result<InputIterator,OutputIterator>(code,input,output);
}//make_cs_cvt_result

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
