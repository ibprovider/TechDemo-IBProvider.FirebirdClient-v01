////////////////////////////////////////////////////////////////////////////////
//macro for debugging designs
//                                                Dmitry Kovalenko. 1998 year.
#ifndef _lcpi_lib__debug_mac_H_
#define _lcpi_lib__debug_mac_H_

#if !defined(NDEBUG_MSG) && !defined(NDEBUG)
#include <sstream>
#endif

////////////////////////////////////////////////////////////////////////////////
//Required:
//
//2 define  _GCRT_run_assert(expr,const char* message) -
//   used for run inhternal implementation of 'assert'
//
//3 define __ODS_IMPLEMENTATION__(const char*) -
//   standard implementation for output debug informations
//

////////////////////////////////////////////////////////////////////////////////
//Verify required

#if !defined(__ODS_IMPLEMENTATION__)
# error ("The definition of __ODS_IMPLEMENTATION__ is required")
#endif

////////////////////////////////////////////////////////////////////////////////
//Configurations
//
//NDEBUG      - standard macro for disable debug code
//NDEBUG_MSG  - use assert instead of assert_msg
//
//_NO_ODS_                 - disable output debug informations
//_PROCESS_DEBUG_MESSAGE_  - use external function
//                           __ProcessDebugMessageFunc__(const char*)
//                           for process debug informations
//_ODS_FILE_LINE_          - include  file name and line in each debug message
//_DEBUG_LEVEL_X_          - output debug informations for concrete level
//                           X - [0,1,2,3]

////////////////////////////////////////////////////////////////////////////////

#ifdef _ODS_TIMESTAMP_
# include <iomanip>
# include <time.h>
#endif

////////////////////////////////////////////////////////////////////////////////
//macro for output debug informations

#if(defined(_NO_ODS_)) //NO output debug informations

  #define DEBUGMESSAGE_CODE(x)

  #define DebugMessage(msg)
  #define DebugMessage3(cond,msg)

#else //ndef _NO_ODS_

  #define DEBUGMESSAGE_CODE(x) x

  #ifdef _PROCESS_DEBUG_MESSAGE_
    extern void __ProcessDebugMessageFunc__(const char*);
    #define PrintDebugMessage(msg) __ProcessDebugMessageFunc__(msg)
  #else
    #define PrintDebugMessage(msg) __ODS_IMPLEMENTATION__(msg)
  #endif

  #ifdef _ODS_FILE_LINE_
    #define __ODS_FILE_LINE_OUTPUT__                                       \
     {                                                                     \
      __debug_os__<<"F:\""<<__FILE__<<"\" L:"<<__LINE__;                   \
     }
  #else
    #define __ODS_FILE_LINE_OUTPUT__
  #endif

  #define DebugMessage(__debug_msg__)                                      \
  {                                                                        \
   std::ostringstream __debug_os__;                                        \
                                                                           \
   __debug_os__<<__debug_msg__;                                            \
                                                                           \
   __ODS_FILE_LINE_OUTPUT__                                                \
                                                                           \
   __debug_os__<<std::endl;                                                \
                                                                           \
   PrintDebugMessage(__debug_os__.str().c_str());                          \
  }

  #define DebugMessage3(condition,msg)                                     \
   {if(condition){DebugMessage(msg);}}

#endif //macro for output debug informations

////////////////////////////////////////////////////////////////////////////////
//define macro for output debug informations for concrete level
 
#ifdef _DEBUG_LEVEL_0_
# define ODS_LEVEL_0(msg)              DebugMessage(msg)
#else
# define ODS_LEVEL_0(msg)
#endif

#ifdef _DEBUG_LEVEL_1_
# define ODS_LEVEL_1(msg)              DebugMessage(msg)
#else
# define ODS_LEVEL_1(msg)
#endif

#ifdef _DEBUG_LEVEL_2_
# define ODS_LEVEL_2(msg)              DebugMessage(msg)
#else
# define ODS_LEVEL_2(msg)
#endif

#ifdef _DEBUG_LEVEL_3_
# define ODS_LEVEL_3(msg)              DebugMessage(msg)
# define ODS_LEVEL_3__CODE(code)       DEBUGMESSAGE_CODE(code)
#else
# define ODS_LEVEL_3(msg)
# define ODS_LEVEL_3__CODE(code)
#endif

////////////////////////////////////////////////////////////////////////////////
//Run debug function

#ifdef NDEBUG
# define STARTUP_CODE_EX__DEBUG(name,func)
#else
# define STARTUP_CODE_EX__DEBUG(name,func)               \
class t_debug_run_##name                                 \
{                                                        \
 public:                                                 \
  t_debug_run_##name() {func();}                         \
}                                                        \
static debug_run_##name;                                       

#endif

#define STARTUP_CODE__DEBUG(func)                        \
 STARTUP_CODE_EX__DEBUG(func,func)

////////////////////////////////////////////////////////////////////////////////
#endif//debug_services
