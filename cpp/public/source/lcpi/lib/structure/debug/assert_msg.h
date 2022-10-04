////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 30.09.2020.
#ifndef _cpp_public_lcpi_lib_structure_debug__assert_msg_H_
#define _cpp_public_lcpi_lib_structure_debug__assert_msg_H_

#include <lcpi/lib/structure/debug/assert.h>

#ifndef NDEBUG
# include <sstream>
#endif

////////////////////////////////////////////////////////////////////////////////
//define extended test condition  - assert_msg

#ifndef LCPI_GCRT_run_assert
# error LCPI_GCRT_run_assert not defined!
#endif

#if defined(NDEBUG_MSG) || defined(NDEBUG)

# define LCPI__assert_msg(p,msg)   LCPI__assert(p)

#else

# define LCPI__assert_msg(p,msg)                                          \
 {                                                                        \
  bool _assert_msg_cond_=(!!(p))?false:true;                              \
                                                                          \
  if(_assert_msg_cond_)                                                   \
  {                                                                       \
   ::std::ostringstream __assert_str__;                                   \
                                                                          \
   __assert_str__<<std::endl<<msg<<std::endl<<#p;                         \
                                                                          \
   LCPI_GCRT_run_assert                                                   \
    (p,                                                                   \
     __assert_str__.str().c_str());                                       \
  }                                                                       \
 }
#endif //define assert_msg

////////////////////////////////////////////////////////////////////////////////
#endif
