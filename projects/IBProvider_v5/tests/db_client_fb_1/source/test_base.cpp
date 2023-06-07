////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_base.h"
#include "source/test_utilities.h"
#include <structure/t_parameter_list.h>

#include <lcpi/lib/structure/utilities/string/is_like_str.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////

const TCHAR* const c_prog_arg__thread_count
 =_T("thread_count");

const TCHAR* const c_prog_arg__auto
 =_T("auto");

const TCHAR* const c_prog_arg__stop
 =_T("stop");

const TCHAR* const c_prog_arg__test
 =_T("test");

const TCHAR* const c_prog_arg__log_dir
 =_T("log_dir");

const TCHAR* const c_prog_arg__log_file_prefix
 =_T("log_file_prefix");

const TCHAR* const c_prog_arg__inet_host
 =_T("inet_host");

const TCHAR* const c_prog_arg__ignore_rules
 =_T("ignore_rules");

const TCHAR* const c_prog_arg__db
 =_T("db");

const TCHAR* const c_prog_arg__db_user
 =_T("db_user");

const TCHAR* const c_prog_arg__db_password
 =_T("db_password");

extern const TCHAR* const c_prog_arg__new_db_dir
 =_T("new_db_dir");

extern const TCHAR* const c_prog_arg__isc_api_library
 =_T("isc_api_library");

extern const TCHAR* const c_prog_arg__dbms
 =_T("dbms");

extern const TCHAR* const c_prog_arg__ods
 =_T("ods");

extern const TCHAR* const c_prog_arg__dialect
 =_T("dialect");

extern const TCHAR* const c_prog_arg__cn_str
 =_T("cn_str");

////////////////////////////////////////////////////////////////////////////////
//class TSYS_RootLog

TSYS_RootLog::TSYS_RootLog(UINT const CodePage)
 :inherited(CodePage)
 ,m_other_error_count   (0)
 ,m_other_warning_count (0)
 ,m_pass_count          (0)
 ,m_total_test_count    (0)
{;}

//------------------------------------------------------------------------
TSYS_RootLog::TSYS_RootLog(tso_obj::t_log_stream* const pOutputStream)
 :inherited(pOutputStream)
 ,m_other_error_count   (0)
 ,m_other_warning_count (0)
 ,m_pass_count          (0)
 ,m_total_test_count    (0)
{;}

//------------------------------------------------------------------------
TSYS_RootLog::~TSYS_RootLog()
{;}

//interface --------------------------------------------------------------
void TSYS_RootLog::add_other_error_count(count_type const x)
{
 thread_traits::add(&m_other_error_count,x);
}//add_other_error_count

//------------------------------------------------------------------------
void TSYS_RootLog::add_other_warning_count(count_type const x)
{
 thread_traits::add(&m_other_warning_count,x);
}//add_other_warning_count

//------------------------------------------------------------------------
void TSYS_RootLog::inc_pass_count()
{
 thread_traits::increment(&m_pass_count);
}//inc_pass_count

//------------------------------------------------------------------------
void TSYS_RootLog::inc_total_test_count()
{
 thread_traits::increment(&m_total_test_count);
}//inc_total_test_count

//selectors --------------------------------------------------------------
TSYS_RootLog::count_type TSYS_RootLog::get_total_error_count()const
{
 return m_other_error_count+this->get_error_count();
}//get_total_error_count

//------------------------------------------------------------------------
TSYS_RootLog::count_type TSYS_RootLog::get_total_warning_count()const
{
 return m_other_warning_count+this->get_warning_count();
}//get_total_warning_count

//------------------------------------------------------------------------
TSYS_RootLog::count_type TSYS_RootLog::get_pass_count()const
{
 return m_pass_count;
}//get_pass_count

//------------------------------------------------------------------------
TSYS_RootLog::count_type TSYS_RootLog::get_total_test_count()const
{
 return m_total_test_count;
}//get_total_test_count

////////////////////////////////////////////////////////////////////////////////
//class TSYS_CommandLine

TSYS_CommandLine::TSYS_CommandLine()
 :m_WaitPressAnyKeyOnExit(false)
{
 m_args.reg_arg(c_prog_arg__thread_count,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__auto,
                cmd_line_parser_type::arg_without_value);

 m_args.reg_arg(c_prog_arg__stop,
                cmd_line_parser_type::arg_without_value);

 m_args.reg_arg(c_prog_arg__test,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__log_dir,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__log_file_prefix,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__inet_host,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__ignore_rules,
                cmd_line_parser_type::arg_without_value);

 m_args.reg_arg(c_prog_arg__db,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__db_user,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__db_password,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__new_db_dir,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__isc_api_library,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__dbms,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__ods,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__dialect,
                cmd_line_parser_type::arg_with_value);

 m_args.reg_arg(c_prog_arg__cn_str,
                cmd_line_parser_type::arg_with_value);

 //-----------------------------------------
 m_args.parse(::GetCommandLine());

 if(!m_args.empty())
  m_args.erase(m_args.begin());//remove first param with path to exe-file

 if(m_args.empty())
  return;

 //-----------------------------------------------------------------------
 m_WaitPressAnyKeyOnExit=!m_args.has(c_prog_arg__auto);

 //-----------------------------------------
 std::string BaseLogFileName;

 if(cmd_arg_ptr const x=m_args.get(c_prog_arg__log_file_prefix,false))
  structure::tstr_to_tstr(&BaseLogFileName,x->m_value);

 if(!BaseLogFileName.empty())
  BaseLogFileName+="_";

 BaseLogFileName+=TSO_GenerateTimeStampString();

 //-------------- Build Test Log File BasePath
 std::string LogDir;

 structure::tstr_to_tstr(&LogDir,m_args.value_or_default(c_prog_arg__log_dir,_T("")));

 m_BaseLogFilePath=TSO_BuildFilePath(LogDir,BaseLogFileName);

 //-------------- Build Test RootLog File Path
 m_RootLogFilePath.assign(m_BaseLogFilePath).append(".log");
}//TSYS_CommandLine

//------------------------------------------------------------------------
TSYS_CommandLine::~TSYS_CommandLine()
{;}

//------------------------------------------------------------------------
bool TSYS_CommandLine::CanExec(const char* const pTestName)const
{
 assert(pTestName!=nullptr);

 const structure::t_string testName(structure::tstr_to_tstr(pTestName));

 bool has_masks=false;

 for(size_t i=0,_c=this->args().size();i!=_c;++i)
 {
  if(this->args()[i]->m_name!=c_prog_arg__test)
   continue;

  has_masks=true;

  if(lcpi::lib::structure::is_like_str
      (_T('?'),
       _T('*'),
       testName,
       this->args()[i]->m_value))
  {
   return true;
  }
 }//for i

 if(has_masks)
  return false;

 return true;
}//CanExec

////////////////////////////////////////////////////////////////////////////////
//class TTSO_GlobalContext

#define DEF_NAMED_EXPRESSION(n,e) {n,e},

const TTSO_GlobalContext::tag_named_expression
 TTSO_GlobalContext::sm_named_expressions[]=
{
 //поддержка 'rpc'-протокола
 DEF_NAMED_EXPRESSION
  ("NE__PTYPE_RPC",
   "SRV<FB-3")

 //поддержка 'lazy_send'-протокола
 DEF_NAMED_EXPRESSION
  ("NE__PTYPE_LAZY_SEND",
   "SRV>=FB-2.1")

 DEF_NAMED_EXPRESSION
  ("NE__PSET01",
   "SRV>=FB")

 DEF_NAMED_EXPRESSION
  ("NE__PSET02",
   "SRV>=FB-3")

 //Firebird protocol v10
 DEF_NAMED_EXPRESSION
  ("NE__P10",
   "SRV>=FB")

 //Firebird protocol v11
 DEF_NAMED_EXPRESSION
  ("NE__P11",
   "SRV>=FB-2.1")

 //Firebird protocol v12
 DEF_NAMED_EXPRESSION
  ("NE__P12",
   "SRV>=FB-2.5")

 //Firebird protocol v13
 DEF_NAMED_EXPRESSION
  ("NE__P13",
   "SRV>=FB-3")

 DEF_NAMED_EXPRESSION
  ("NE__AUTH__WIN_SSPI",
   "SRV>=FB-2.1")

 DEF_NAMED_EXPRESSION
  ("NE__AUTH__SRP",
   "SRV>=FB-3")

 DEF_NAMED_EXPRESSION
  ("NE__BOOLEAN",
   "SRV>=FB-3")

 DEF_NAMED_EXPRESSION
  ("NE__INT128",
   "SRV>=FB-4")

 DEF_NAMED_EXPRESSION
  ("NE__DECFLOAT16",
   "SRV>=FB-4")

 DEF_NAMED_EXPRESSION
  ("NE__DECFLOAT34",
   "SRV>=FB-4")

 DEF_NAMED_EXPRESSION
  ("NE__ODS_CS__IS_UNICODE_FSS",
   "SRV<=FB-3")

 DEF_NAMED_EXPRESSION
  ("NE__ODS_CS__IS_UTF8",
   "SRV>=FB-4")
};//sm_named_expressions

#undef DEF_NAMED_EXPRESSION

//------------------------------------------------------------------------
TTSO_GlobalContext::TTSO_GlobalContext(const TSYS_CommandLine* const pSysCL)
 :m_spSysCL(structure::not_null_ptr(pSysCL))
 ,m_ExpressionParser(pSysCL)
{
 for(const auto& x : sm_named_expressions)
 {
  m_ExpressionParser.reg_macro(x.name,x.condition);
 }//for
}//TTSO_GlobalContext

//------------------------------------------------------------------------
TTSO_GlobalContext::~TTSO_GlobalContext()
{;}

//selectors --------------------------------------------------------------
const TTSO_GlobalContext::args_type& TTSO_GlobalContext::args()const
{
 assert(m_spSysCL);

 return m_spSysCL->args();
}//args

//------------------------------------------------------------------------
bool TTSO_GlobalContext::can_exec(const char* const pTestName)const
{
 assert(m_spSysCL);

 return m_spSysCL->CanExec(pTestName);
}//can_exec

//------------------------------------------------------------------------
bool TTSO_GlobalContext::calc_expression(structure::t_const_str_box const expression)const
{
 return m_ExpressionParser.calc(expression)!=m_ExpressionParser.calc_result__no;
}//calc_expression

////////////////////////////////////////////////////////////////////////////////
//class TTSO_RunContext

TTSO_RunContext::TTSO_RunContext(log_type* const pLog)
 :m_spLog(structure::not_null_ptr(pLog))
{
 assert(m_spLog);
}//TTSO_RunContext

//------------------------------------------------------------------------
TTSO_RunContext::~TTSO_RunContext()
{;}

//log interface ----------------------------------------------------------
void TTSO_RunContext::trace(message_type* const message)
{
 assert(message);

 typedef structure::t_multi_thread_traits   thread_traits;

 switch(message->get_msg_kind())
 {
  case tso_msg_error:
  {
   thread_traits::increment(&m_test_info.err_count);
   break;
  }//case - error

  case tso_msg_warning:
  {
   thread_traits::increment(&m_test_info.warning_count);
   break;
  }//case - warning
 }//switch

 assert(m_spLog);

 return m_spLog->trace(message);
}//log

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
