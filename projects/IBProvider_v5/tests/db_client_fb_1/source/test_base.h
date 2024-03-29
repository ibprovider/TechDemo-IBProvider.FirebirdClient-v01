////////////////////////////////////////////////////////////////////////////////
#ifndef _test_base_H_
#define _test_base_H_

#include "source/test_expression_parser.h"

#include "source/db_obj/db_base.h"

#include "source/oledb/props2/ibp_oledb__props2__forward.h"

#include <structure/test_obj/fw/set01/test_fw_set01__sys_log.h>
#include <structure/test_obj/fw/set01/test_fw_set01__run_context.h>
#include <structure/test_obj/fw/set01/test_fw_set01__tracer_utils.h>
#include <structure/t_cmd_line_parser.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////

namespace tso_obj=structure::tso_obj;

using tso_obj::send;
using tso_obj::tso_msg_error;
using tso_obj::tso_msg_warning;

////////////////////////////////////////////////////////////////////////////////
//containings

class TTSO_GlobalContext;
class TTSO_Test;

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

using TTSO_RootLog
 =tso_obj::t_basic_root_log<TTSO_MemoryAllocator>;

using TTSO_Tracer
 =tso_obj::t_basic_tracer<TTSO_MemoryAllocator>;

using TTSO_ExceptionRouter
 =tso_obj::t_basic_exception_router;

////////////////////////////////////////////////////////////////////////////////
//typedefs

using TTSO_TracerAutoSend
 =structure::test_fw::set01::TestFW__Basic_TracerAutoSend<TTSO_Tracer>;

////////////////////////////////////////////////////////////////////////////////
//class TSYS_RootLog

using TSYS_RootLog
 =structure::test_fw::set01::TestFW__SysLog;

////////////////////////////////////////////////////////////////////////////////

using TSYS_Tracer
 =tso_obj::t_basic_tracer<TSYS_MemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////
//class TSYS_CommandLine

class TSYS_CommandLine LCPI_CPP_CFG__CLASS__FINAL
 :public TSYS_SmartMemoryObject
{
 private:
  using self_type=TSYS_CommandLine;

  TSYS_CommandLine(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~TSYS_CommandLine();

 public: //typedefs ------------------------------------------------------
  using self_cptr=lib::structure::t_smart_object_ptr<const self_type>;

  using allocator_type=TSYS_MemoryAllocator;

  using string_type=structure::t_string;

  using char_type=structure::t_char;

  using cmd_line_parser_type
   =structure::t_basic_cmd_line_parser<char_type,allocator_type>;

  using cmd_arg_type
   =cmd_line_parser_type::arg_type;

  using cmd_arg_ptr
   =cmd_line_parser_type::arg_cptr;

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

class TTSO_GlobalContext LCPI_CPP_CFG__CLASS__FINAL
 :public TSYS_SmartMemoryObject
{
 private:
  using self_type=TTSO_GlobalContext;

  TTSO_GlobalContext(const TTSO_GlobalContext&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~TTSO_GlobalContext();

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  using self_cptr=lib::structure::t_smart_object_ptr<const self_type>;

  using args_type=TSYS_CommandLine::cmd_line_parser_type;

 public:
  explicit TTSO_GlobalContext(const TSYS_CommandLine* pSysCL);

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

using TTSO_RunContext
 =structure::test_fw::set01::TestFW__RunContext;

////////////////////////////////////////////////////////////////////////////////
//class TTSO_Test_base

using TTSO_Test_base
 =structure::test_fw::set01::TestFW__Test;

////////////////////////////////////////////////////////////////////////////////
//class TTSO_Test

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE TTSO_Test
 :public TTSO_Test_base
{
 public:
  virtual bool can_exec()const=0;
};//class TTSO_Test

using TTSO_TestPtr
 =lib::structure::t_smart_object_ptr<TTSO_Test>;

using TTSO_TestCPtr
 =lib::structure::t_smart_object_ptr<const TTSO_Test>;

////////////////////////////////////////////////////////////////////////////////
//class TTSO_PushTest

using TTSO_PushTest
 =structure::test_fw::set01::TestFW__PushTest;

using TTSO_PushTestPtr
 =lib::structure::t_smart_object_ptr<TTSO_PushTest>;

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
