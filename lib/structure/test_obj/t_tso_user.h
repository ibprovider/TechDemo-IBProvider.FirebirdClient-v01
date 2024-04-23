////////////////////////////////////////////////////////////////////////////////
//Standart services for create tests systems
//                                                Dmitry Kovalenko. 31.01.2005.
#ifndef _t_tso_user_H_
#define _t_tso_user_H_

#include <lcpi/lib/.config.h>

#include <iostream>
#include <sstream>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//process exceptions

std::string console_out_str(const char* const s);

int process_exception(const char* const source,const std::exception* exc);

int route_exception(const char* const source);

//------------------------------------------------------------------------
#define _TSO_CHECK(cond)                                                 \
{                                                                        \
 bool _cond_result=(cond)?true:false;                                    \
                                                                         \
 if(!_cond_result)                                                       \
  throw std::runtime_error(std::string("fail ").append(#cond));          \
}

//------------------------------------------------------------------------
#define _TSO_CHECK_MSG(cond,msg)                                         \
{                                                                        \
 bool _cond_result=(cond)?true:false;                                    \
                                                                         \
 if(!_cond_result)                                                       \
 {                                                                       \
  std::ostringstream msg_stream;                                         \
                                                                         \
  msg_stream<<"fail "<<#cond<<std::endl                                  \
            <<msg;                                                       \
                                                                         \
  throw std::runtime_error(msg_stream.str());                            \
 }                                                                       \
}

//------------------------------------------------------------------------
#define _TSO_EXEC_TRACER(tracer,x)                                       \
{                                                                        \
 (tracer)<<#x<<structure::tso_obj::send;                                 \
                                                                         \
 x;                                                                      \
}

//------------------------------------------------------------------------
#define _TSO_CHECK_TRACER_EX(tracer,cond,comment)                        \
{                                                                        \
 (tracer)<<#cond<<L" "<<comment<<structure::tso_obj::send;               \
                                                                         \
 _TSO_CHECK(cond);                                                       \
}

//------------------------------------------------------------------------
#define _TSO_EXEC_COUT(x)                                                \
{                                                                        \
 std::cout<<#x<<std::endl;                                               \
                                                                         \
 x;                                                                      \
}

//------------------------------------------------------------------------
#define _TSO_EXEC_COUT_EX(x,comment)                                     \
{                                                                        \
 std::cout<<#x<<" "<<comment<<std::endl;                                 \
                                                                         \
 x;                                                                      \
}

//------------------------------------------------------------------------
#define _TSO_CHECK_COUT_EX(cond,comment)                                 \
{                                                                        \
 std::cout<<#cond<<" "<<comment<<std::endl;                              \
                                                                         \
 _TSO_CHECK(cond)                                                        \
}

//------------------------------------------------------------------------
#define _TSO_CHECK_COUT(cond)                                            \
 _TSO_CHECK_COUT_EX(cond,"")

//------------------------------------------------------------------------
#define _TSO_TRY_                                                        \
 try

//------------------------------------------------------------------------
#define _TSO_CATCHES_(source,error_count)                                \
 catch(...)                                                              \
 {                                                                       \
  error_count+=structure::tso_obj::route_exception(source);              \
 }

////////////////////////////////////////////////////////////////////////////////
//struct TestMemAllocatorFunc

struct TestMemAllocatorFunc
{
 public:
  using cnt_type=size_t;

 public:
  static void* Alloc(size_t sz);

  static void  Free(void* pv);

  static cnt_type GetBlockCount()
   {return sm_BlockCount;}

  static void CheckNoBlock();

 private:
  static cnt_type sm_BlockCount;
};//struct TestMemAllocatorFunc

////////////////////////////////////////////////////////////////////////////////

#define _TSO_DEF_TEST_DESCR_EX(name,func)   \
 {(name),(func)}

#define _TSO_DEF_TEST_DESCR(func)           \
 _TSO_DEF_TEST_DESCR_EX(#func,(func))

////////////////////////////////////////////////////////////////////////////////
//struct t_test_descr

template<typename t_func>
struct t_test_descr
{
 public:
  using func_type=t_func;

 public:
  const char* name;
  func_type*  func;
};//class t_test_descr

////////////////////////////////////////////////////////////////////////////////
//struct t_test_func_0

typedef void (t_tso_test_func_0)();

typedef t_test_descr<t_tso_test_func_0> t_test_descr_0;

////////////////////////////////////////////////////////////////////////////////
//struct t_test_func_0_r

//return: error count
typedef int (t_tso_test_func_0_r)();

typedef t_test_descr<t_tso_test_func_0_r> t_test_descr_0_r;

////////////////////////////////////////////////////////////////////////////////
//run tests

//last element has func==NULL
//return: error count

int run_tests(const t_test_descr_0* pTests,const char* TestsMask="");

int run_tests(const t_test_descr_0_r* pTests);

template<class tag_test_descr,class tag_test_arg>
int run_tests(const tag_test_descr* pTests,const tag_test_arg& Arg);

////////////////////////////////////////////////////////////////////////////////
//class t_auto_endl

class t_auto_endl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_auto_endl;

  t_auto_endl(const self_type&)=delete;
  self_type* operator = (const self_type&)=delete;

 public:
  t_auto_endl()
  {
  }

 ~t_auto_endl()
  {
   std::cout<<std::endl;
  }
};//class t_auto_endl

////////////////////////////////////////////////////////////////////////////////
}/*nms tso_obj*/}/*nms structure*/

////////////////////////////////////////////////////////////////////////////////
#include <structure/test_obj/t_tso_user.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
