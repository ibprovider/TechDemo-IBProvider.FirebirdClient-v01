////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 27.09.2022.
#ifndef _cpp_public_lcpi_lib_structure_debug__debug_code_H_
#define _cpp_public_lcpi_lib_structure_debug__debug_code_H_

#include <lcpi/lib/structure/debug/assert_msg.h>

///////////////////////////////////////////////////////////////////////////////

#if(!defined(NDEBUG)) //debug --------------------------------------------
 #define LCPI__RELEASE_CODE(release_code)
 #define LCPI__DEBUG_CODE(debug_code)           debug_code  //code for debug build

 //use !=0 instead !!, because
 //[BCB5] W8060: Possibly incorrect assignment
 #define LCPI__VERIFY(code)                    LCPI__assert(((code)!=0))  //assert not convert argument to bool
 #define LCPI__VERIFY_MSG(code,msg)            LCPI__assert_msg(code,msg)

 #define LCPI__VERIFY_EQ(code,result)          LCPI__assert((code)==(result))
 #define LCPI__VERIFY_EQ_MSG(code,result,msg)  LCPI__assert_msg((code)==(result),msg)

 #define LCPI__DEBUG_ARG(arg)                  ,arg

#else //defined(NDEBUG) - release ----------------------------------------

 #define LCPI__RELEASE_CODE(release_code)       release_code //code for release build
 #define LCPI__DEBUG_CODE(debug_code)

 #define LCPI__VERIFY(code)                    code
 #define LCPI__VERIFY_MSG(code,msg)            code

 #define LCPI__VERIFY_EQ(code,result)          code
 #define LCPI__VERIFY_EQ_MSG(code,result,msg)  code

 #define LCPI__DEBUG_ARG(arg)

#endif //defined(NDEBUG)

///////////////////////////////////////////////////////////////////////////////
#endif
