////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Library.
//                                                 Dmitry Kovalenko. 01.03.2024.
#ifndef _cpp_public_lcpi_config__config_debug_H_
#define _cpp_public_lcpi_config__config_debug_H_

#include <assert.h>

#if !defined(NDEBUG) && !defined(NDEBUG_MSG)
#include <sstream>
#endif

////////////////////////////////////////////////////////////////////////////////

#define LCPI__assert(expression) assert(expression)

////////////////////////////////////////////////////////////////////////////////

#define LCPI__assert_s(cond) static_assert(cond,#cond)

////////////////////////////////////////////////////////////////////////////////

//-V:assert_hint:779, 547
#define LCPI__assert_hint(cond) LCPI__assert(cond)

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

///////////////////////////////////////////////////////////////////////////////

#define LCPI__assert_range(begin,end,index)                               \
 LCPI__assert_msg                                                         \
  ((begin)<=(index) && (index)<(end),                                     \
    "begin="<<(begin)<<"\n"                                               \
    "end=="<<(end)<<"\n"                                                  \
    "index=="<<(index))

///////////////////////////////////////////////////////////////////////////////

#if(!defined(NDEBUG)) //debug --------------------------------------------

 #define LCPI__RELEASE_CODE(release_code)
 #define LCPI__DEBUG_CODE(debug_code)          debug_code  //code for debug build

 //use !=0 instead !!, because
 //[BCB5] W8060: Possibly incorrect assignment
 #define LCPI__VERIFY(code)                    LCPI__assert(((code)!=0))  //assert not convert argument to bool
 #define LCPI__VERIFY_MSG(code,msg)            LCPI__assert_msg(code,msg)

 #define LCPI__VERIFY_EQ(code,result)          LCPI__assert((code)==(result))
 #define LCPI__VERIFY_EQ_MSG(code,result,msg)  LCPI__assert_msg((code)==(result),msg)

 #define LCPI__DEBUG_ARG(arg)                  ,arg

#else //defined(NDEBUG) - release ----------------------------------------

 #define LCPI__RELEASE_CODE(release_code)      release_code //code for release build
 #define LCPI__DEBUG_CODE(debug_code)

 #define LCPI__VERIFY(code)                    code
 #define LCPI__VERIFY_MSG(code,msg)            code

 #define LCPI__VERIFY_EQ(code,result)          code
 #define LCPI__VERIFY_EQ_MSG(code,result,msg)  code

 #define LCPI__DEBUG_ARG(arg)

#endif //defined(NDEBUG)

////////////////////////////////////////////////////////////////////////////////
//check pointers

#if(!defined(NDEBUG) && defined(_WIN32))

#define LCPI__CHECK_WRITE_PTR_MSG(ptr,size,msg) \
 LCPI__assert_msg(!IsBadWritePtr((ptr),(size)),msg<<"\nptr==0x"<<std::hex<<((void*)(ptr))<<"\nsize=="<<std::dec<<(size))

#define LCPI__CHECK_WRITE_PTR(ptr,size) \
 LCPI__assert_msg(!IsBadWritePtr((ptr),(size)),"ptr==0x"<<std::hex<<((void*)(ptr))<<"\nsize=="<<std::dec<<(size))

#define LCPI__CHECK_READ_PTR_MSG(ptr,size,msg) \
 LCPI__assert_msg(!IsBadReadPtr((ptr),(size)),msg<<"\nptr==0x"<<std::hex<<((void*)(ptr))<<"\nsize=="<<std::dec<<(size))

#define LCPI__CHECK_READ_PTR(ptr,size) \
 LCPI__assert_msg(!IsBadReadPtr((ptr),(size)),"ptr==0x"<<std::hex<<((void*)(ptr))<<"\nsize=="<<std::dec<<(size))

#else

#define LCPI__CHECK_WRITE_PTR_MSG(ptr,size,msg) {;}
#define LCPI__CHECK_WRITE_PTR(ptr,size) {;}
#define LCPI__CHECK_READ_PTR_MSG(ptr,size,msg) {;}
#define LCPI__CHECK_READ_PTR(ptr,size) {;}

#endif //no check pointer

#define LCPI__CHECK_READ_WRITE_PTR(ptr,size)                              \
 {                                                                        \
  LCPI__CHECK_READ_PTR((ptr),(size))                                      \
  LCPI__CHECK_WRITE_PTR((ptr),(size))                                     \
 }

#define LCPI__CHECK_WRITE_TYPED_PTR(ptr,count)                            \
 LCPI__CHECK_WRITE_PTR((ptr),(count)*sizeof(*(ptr)))

#define LCPI__CHECK_READ_TYPED_PTR(ptr,count)                             \
 LCPI__CHECK_READ_PTR((ptr),(count)*sizeof(*(ptr)))

#define LCPI__CHECK_READ_WRITE_TYPED_PTR(ptr,count)                       \
 LCPI__CHECK_READ_WRITE_PTR((ptr),(count)*sizeof(*(ptr)))

////////////////////////////////////////////////////////////////////////////////
//check iterator

#define LCPI__CHECK_VALID_ITERATOR(container,iterator)                    \
 {                                                                        \
  LCPI__assert(!((iterator)< (container).begin()));                       \
  LCPI__assert((iterator)< (container).end());                            \
 }

////////////////////////////////////////////////////////////////////////////////
//backward compatible

#define assert_hint(cond) LCPI__assert_hint(cond)

#define assert_msg(cond,msg) LCPI__assert_msg(cond,msg)

#define assert_s(cond) LCPI__assert_s(cond)

//------------------------------------------------------------------------
//check of range

#define assert_range(begin,end,index) LCPI__assert_range(begin,end,index)

//------------------------------------------------------------------------
#define CHECK_WRITE_PTR_MSG(ptr,size,msg)     LCPI__CHECK_WRITE_PTR_MSG(ptr,size,msg)
#define CHECK_WRITE_PTR(ptr,size)             LCPI__CHECK_WRITE_PTR(ptr,size)
#define CHECK_READ_PTR_MSG(ptr,size,msg)      LCPI__CHECK_READ_PTR_MSG(ptr,size,msg)
#define CHECK_READ_PTR(ptr,size)              LCPI__CHECK_READ_PTR(ptr,size)

#define CHECK_READ_WRITE_PTR(ptr,size)        LCPI__CHECK_READ_WRITE_PTR(ptr,size)
#define CHECK_WRITE_TYPED_PTR(ptr,count)      LCPI__CHECK_WRITE_TYPED_PTR(ptr,count)
#define CHECK_READ_TYPED_PTR(ptr,count)       LCPI__CHECK_READ_TYPED_PTR(ptr,count)
#define CHECK_READ_WRITE_TYPED_PTR(ptr,count) LCPI__CHECK_READ_WRITE_TYPED_PTR(ptr,count)

#define CHECK_VALID_ITERATOR(container,iterator) LCPI__CHECK_VALID_ITERATOR(container,iterator)

//------------------------------------------------------------------------
#define RELEASE_CODE(release_code)            LCPI__RELEASE_CODE(release_code)
#define DEBUG_CODE(debug_code)                LCPI__DEBUG_CODE(debug_code)

#define _VERIFY(code)                         LCPI__VERIFY(code)
#define _VERIFY_MSG(code,msg)                 LCPI__VERIFY_MSG(code,msg)

#define _VERIFY_EQ(code,result)               LCPI__VERIFY_EQ(code,result)
#define _VERIFY_EQ_MSG(code,result,msg)       LCPI__VERIFY_EQ_MSG(code,result,msg)

#define _DEBUG_ARG(arg)                       LCPI__DEBUG_ARG(arg)

////////////////////////////////////////////////////////////////////////////////
#endif
