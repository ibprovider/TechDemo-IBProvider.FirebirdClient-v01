////////////////////////////////////////////////////////////////////////////////
#ifndef _test_base_H_
#define _test_base_H_

#include "source/test_state2.h"
#include "source/test_expression_parser.h"

#include "source/db_obj/db_base.h"

#include "source/oledb/props2/ibp_oledb__props2__forward.h"

#include <structure/test_obj/t_tso_lib.h>
#include <structure/t_cmd_line_parser.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
namespace tso_obj=structure::tso_obj;

using tso_obj::send;
using tso_obj::tso_msg_error;
using tso_obj::tso_msg_warning;

////////////////////////////////////////////////////////////////////////////////
//containings

class TSYS_RootLog;
class TTSO_GlobalContext;
class TTSO_RunContext;
class TTSO_Test;
class TTSO_PushTest;

////////////////////////////////////////////////////////////////////////////////
//forward

class TestCnParams;

////////////////////////////////////////////////////////////////////////////////
//command line arguments

extern const TCHAR* const c_prog_arg__thread_count;

extern const TCHAR* const c_prog_arg__auto;

extern const TCHAR* const c_prog_arg__stop;

extern const TCHAR* const c_prog_arg__test;

extern const TCHAR* const c_prog_arg__log_dir;

extern const TCHAR* const c_prog_arg__log_file_prefix;

extern const TCHAR* const c_prog_arg__inet_host;

extern const TCHAR* const c_prog_arg__ignore_rules;

extern const TCHAR* const c_prog_arg__db;

extern const TCHAR* const c_prog_arg__db_user;

extern const TCHAR* const c_prog_arg__db_password;

extern const TCHAR* const c_prog_arg__new_db_dir;

extern const TCHAR* const c_prog_arg__isc_api_library;

extern const TCHAR* const c_prog_arg__dbms;
extern const TCHAR* const c_prog_arg__ods;
extern const TCHAR* const c_prog_arg__dialect;

extern const TCHAR* const c_prog_arg__cn_str;

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef structure::t_smart_interface                          TTSO_SmartInterface;

typedef structure::t_basic_smart_interface_impl__dynamic
         <TTSO_SmartInterface,
          TTSO_MemoryAllocator>                               TTSO_SmartMemoryObject;

typedef tso_obj::t_basic_root_log<TTSO_MemoryAllocator>       TTSO_RootLog;

typedef tso_obj::t_basic_tracer<TTSO_MemoryAllocator>         TTSO_Tracer;

typedef tso_obj::t_basic_exception_router                     TTSO_ExceptionRouter;

////////////////////////////////////////////////////////////////////////////////
//class TTSO_Basic_TracerAutoSend

template<class TTracer>
class TTSO_Basic_TracerAutoSend
{
 private:
  typedef TTSO_Basic_TracerAutoSend<TTracer>          self_type;

  TTSO_Basic_TracerAutoSend(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef TTracer                                     tracer_type;

 public:
  TTSO_Basic_TracerAutoSend(tracer_type& tracer);

 ~TTSO_Basic_TracerAutoSend();

 private:
  tracer_type& m_tracer;
};//class TTSO_TracerAutoSend

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef TTSO_Basic_TracerAutoSend<TTSO_Tracer> TTSO_TracerAutoSend;

////////////////////////////////////////////////////////////////////////////////
//class TSYS_RootLog

class TSYS_RootLog:public tso_obj::t_basic_root_log<TSYS_MemoryAllocator>
{
 private:
  typedef TSYS_RootLog                                     self_type;
  typedef tso_obj::t_basic_root_log<TSYS_MemoryAllocator>  inherited;

  TSYS_RootLog(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~TSYS_RootLog();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>         self_ptr;

  typedef inherited::thread_traits                         thread_traits;
  typedef inherited::count_type                            count_type;

 public:
  TSYS_RootLog(UINT CodePage);

  TSYS_RootLog(tso_obj::t_log_stream* pOutputStream);

  //interface ------------------------------------------------------------
  void add_other_error_count(count_type x);

  void add_other_warning_count(count_type x);

  void inc_pass_count();

  void inc_total_test_count();

  //selectors ------------------------------------------------------------
  count_type get_total_error_count()const;

  count_type get_total_warning_count()const;

  count_type get_pass_count()const;

  count_type get_total_test_count()const;

 public:
  count_type m_other_error_count;
  count_type m_other_warning_count;
  count_type m_pass_count;
  count_type m_total_test_count;
};//class TSYS_RootLog

////////////////////////////////////////////////////////////////////////////////

typedef tso_obj::t_basic_tracer<TSYS_MemoryAllocator>        TSYS_Tracer;

////////////////////////////////////////////////////////////////////////////////
//class TSYS_CommandLine

class TSYS_CommandLine:public TSYS_SmartMemoryObject
{
 private:
  typedef TSYS_CommandLine                                   self_type;

  TSYS_CommandLine(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~TSYS_CommandLine();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<const self_type>     self_cptr;

  typedef TSYS_MemoryAllocator                               allocator_type;

  typedef structure::t_string                                string_type;
  typedef structure::t_char                                  char_type;
  typedef structure::t_basic_cmd_line_parser<char_type,
                                             allocator_type> cmd_line_parser_type;
  typedef cmd_line_parser_type::arg_type                     cmd_arg_type;
  typedef cmd_line_parser_type::arg_cptr                     cmd_arg_ptr;

 public:
  TSYS_CommandLine();

  //interface ------------------------------------------------------------
  const cmd_line_parser_type& args()const
   {return m_args;}

  bool WaitPressAnyKeyOnExit()const
   {return m_WaitPressAnyKeyOnExit;}

  const std::string& BaseLogFilePath()const
   {return m_BaseLogFilePath;}

  const std::string& RootLogFilePath()const
   {return m_RootLogFilePath;}

  //----------------------------------------------------------------------
  bool CanExec(const char* pTestName)const;

 private:
  cmd_line_parser_type m_args;

  bool m_WaitPressAnyKeyOnExit;

  std::string m_BaseLogFilePath;

  std::string m_RootLogFilePath;
};//class TSYS_CommandLine

////////////////////////////////////////////////////////////////////////////////
//class TTSO_GlobalContext

class TTSO_GlobalContext:public TSYS_SmartMemoryObject
{
 private:
  typedef TTSO_GlobalContext                                  self_type;

  TTSO_GlobalContext(const TTSO_GlobalContext&);
  self_type& operator = (const self_type&);

  virtual ~TTSO_GlobalContext();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>         self_ptr;
  typedef structure::t_smart_object_ptr<const self_type>   self_cptr;

  typedef TSYS_CommandLine::cmd_line_parser_type           args_type;

 public:
  TTSO_GlobalContext(const TSYS_CommandLine* pSysCL);

  //selectors ------------------------------------------------------------
  const args_type& args()const;

  bool can_exec(const char* pTestName)const;

  bool calc_expression(structure::t_const_str_box expression)const;

 private:
  struct tag_named_expression
  {
   const char* name;
   const char* condition;
  };//struct tag_named_expression

 private:
  const TSYS_CommandLine::self_cptr m_spSysCL;

  TIBP_TSO_ExpressionParser m_ExpressionParser;

 private:
  //таблица с именованными разрешениями на запуск тестов
  static const tag_named_expression sm_named_expressions[];
};//class TTSO_GlobalContext

////////////////////////////////////////////////////////////////////////////////
//class TTSO_RunContext

class TTSO_RunContext
 :public structure::t_basic_smart_interface_impl__dynamic<structure::tso_obj::t_simple_log,
                                                          TTSO_MemoryAllocator>
{
 private:
  typedef TTSO_RunContext                               self_type;

  TTSO_RunContext(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~TTSO_RunContext();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>      self_ptr;

  typedef tso_obj::t_simple_log                         log_type;
  typedef log_type::self_ptr                            log_ptr;

  typedef structure::t_multi_thread_traits              thread_traits;
  typedef thread_traits::int_type                       count_type;

 public:
  TTSO_TestState2 m_test_info;

 public:
  TTSO_RunContext(log_type* pLog);

  //log interface --------------------------------------------------------
  virtual void trace(message_type* msg) COMP_W000004_OVERRIDE_FINAL;

 private:
  const log_ptr m_spLog;
};//class TTSO_TestContext

////////////////////////////////////////////////////////////////////////////////
//class TTSO_Test

class TTSO_Test:public TTSO_SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef TTSO_RunContext                               context_type;

 public:
  virtual std::string get_id()const=0;

  virtual bool can_exec()const=0;

  virtual void run(context_type* pCtx)const=0;
};//class TTSO_Test

typedef structure::t_smart_object_ptr<TTSO_Test>        TTSO_TestPtr;

typedef structure::t_smart_object_ptr<const TTSO_Test>  TTSO_TestCPtr;

////////////////////////////////////////////////////////////////////////////////
//class TTSO_PushTest

class TTSO_PushTest:public TTSO_SmartInterface
{
 public:
  virtual void PushTest(const TTSO_Test* pTest)=0;
};//class TTSO_PushTest

typedef structure::t_smart_object_ptr<TTSO_PushTest> TTSO_PushTestPtr;

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
#endif

////////////////////////////////////////////////////////////////////////////////
#include "source/test_base.cc"
////////////////////////////////////////////////////////////////////////////////
