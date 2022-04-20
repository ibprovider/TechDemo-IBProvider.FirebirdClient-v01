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

#if   (!defined(_GCRT_run_assert))
 #error ("The definition of _GCRT_run_assert is required")
#elif (!defined(__ODS_IMPLEMENTATION__))
 #error ("The definition of __ODS_IMPLEMENTATION__ is required")
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

#ifndef COMP_CONF_SUPPORT_STATIC_ASSERT
# error COMP_CONF_SUPPORT_STATIC_ASSERT not defined!
#endif

#if(COMP_CONF_SUPPORT_STATIC_ASSERT)
# define assert_s(cond)        static_assert(cond,#cond)
#else
# define assert_s(cond)        assert(cond)
#endif

////////////////////////////////////////////////////////////////////////////////

//-V:assert_hint:779, 547
#define assert_hint(cond) assert(cond)

////////////////////////////////////////////////////////////////////////////////
//define extended test condition  - assert_msg

#if defined(NDEBUG_MSG) || defined(NDEBUG)
# define assert_msg(p,msg)   assert(p)
#else
# define assert_msg(p,msg)                                                \
 {                                                                        \
  bool _assert_msg_cond_=(!!(p))?false:true;                              \
                                                                          \
  if(_assert_msg_cond_)                                                   \
  {                                                                       \
    std::ostringstream __assert_str__;                                    \
                                                                          \
    __assert_str__<<std::endl<<msg<<std::endl<<#p;                        \
                                                                          \
    _GCRT_run_assert(p,__assert_str__.str().c_str());                     \
  }                                                                       \
 }
#endif //define assert_msg

////////////////////////////////////////////////////////////////////////////////
//check of range

#define assert_range(begin,end,index)                                  \
 assert_msg                                                            \
 ((begin)<=(index) && (index)<(end),                                   \
   "begin="<<(begin)<<"\n"                                             \
   "end=="<<(end)<<"\n"                                                \
   "index=="<<(index))

//check iterator
#define CHECK_VALID_ITERATOR(container,iterator)                       \
 {                                                                     \
  assert(!((iterator)< (container).begin()));                          \
  assert((iterator)< (container).end());                               \
 }

////////////////////////////////////////////////////////////////////////////////
//Define macros for debug and release build's

#if(!defined(NDEBUG)) //debug --------------------------------------------
 #define RELEASE_CODE(release_code)
 #define DEBUG_CODE(debug_code) debug_code  //code for debug build

 //use !=0 instead !!, because
 //[BCB5] W8060: Possibly incorrect assignment
 #define _VERIFY(code)                    assert(((code)!=0))  //assert not convert argument to bool
 #define _VERIFY_MSG(code,msg)            assert_msg(code,msg)

 #define _VERIFY_EQ(code,result)          assert((code)==(result))
 #define _VERIFY_EQ_MSG(code,result,msg)  assert_msg((code)==(result),msg)

 #define _DEBUG_ARG(arg)                  ,arg

#else //defined(NDEBUG) - release ----------------------------------------

 #define RELEASE_CODE(release_code) release_code //code for release build
 #define DEBUG_CODE(debug_code)

 #define _VERIFY(code)                    code
 #define _VERIFY_MSG(code,msg)            code

 #define _VERIFY_EQ(code,result)          code
 #define _VERIFY_EQ_MSG(code,result,msg)  code

 #define _DEBUG_ARG(arg)

#endif //defined(NDEBUG)

//check pointers
#if(!defined(NDEBUG) && defined(__WIN32__))
 #define CHECK_WRITE_PTR_MSG(ptr,size,msg) \
  assert_msg(!IsBadWritePtr((ptr),(size)),msg<<"\nptr==0x"<<std::hex<<((void*)(ptr))<<"\nsize=="<<std::dec<<(size))

 #define CHECK_WRITE_PTR(ptr,size) \
  assert_msg(!IsBadWritePtr((ptr),(size)),"ptr==0x"<<std::hex<<((void*)(ptr))<<"\nsize=="<<std::dec<<(size))

 #define CHECK_READ_PTR_MSG(ptr,size,msg) \
  assert_msg(!IsBadReadPtr((ptr),(size)),msg<<"\nptr==0x"<<std::hex<<((void*)(ptr))<<"\nsize=="<<std::dec<<(size))

 #define CHECK_READ_PTR(ptr,size) \
  assert_msg(!IsBadReadPtr((ptr),(size)),"ptr==0x"<<std::hex<<((void*)(ptr))<<"\nsize=="<<std::dec<<(size))

#else
 #define CHECK_WRITE_PTR_MSG(ptr,size,msg) {;}
 #define CHECK_WRITE_PTR(ptr,size) {;}
 #define CHECK_READ_PTR_MSG(ptr,size,msg) {;}
 #define CHECK_READ_PTR(ptr,size) {;}
#endif //no check pointer

#define CHECK_READ_WRITE_PTR(ptr,size)                                    \
 {                                                                        \
  CHECK_READ_PTR((ptr),(size))                                            \
  CHECK_WRITE_PTR((ptr),(size))                                           \
 }

#define CHECK_WRITE_TYPED_PTR(ptr,count)                                  \
 CHECK_WRITE_PTR((ptr),(count)*sizeof(*(ptr)))

#define CHECK_READ_TYPED_PTR(ptr,count)                                   \
 CHECK_READ_PTR((ptr),(count)*sizeof(*(ptr)))  
 
#define CHECK_READ_WRITE_TYPED_PTR(ptr,count)                             \
 CHECK_READ_WRITE_PTR((ptr),(count)*sizeof(*(ptr)))

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
