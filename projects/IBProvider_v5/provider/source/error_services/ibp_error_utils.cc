////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_utils.cc
//! \brief   Сервисные утилиты для работы с ошибками IBProvider'a
//! \author  Kovalenko Dmitry
//! \date    11.11.2010
#ifndef _ibp_error_utils_CC_
#define _ibp_error_utils_CC_

#include <structure/utilities/string/position_in_str.h>

#include <structure/t_str_formatter.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

template<typename TextIterator>
COMP_CONF_DECLSPEC_NORETURN /*defined for avoiding a possible problem with MSVC*/
void IBP_ThrowErrorSymbolInCommandText(TextIterator beg,
                                       TextIterator cur_pos)
{
 assert(beg!=cur_pos);

 const std::pair<size_t,size_t>
  line_col
   (structure::position_in_str
     (beg,
      cur_pos));

 IBP_ErrorUtils::Throw__Error
  (DB_E_ERRORSINCOMMAND,
   ibp_mce_cmd_incorrect_text_3,
   line_col.first,
   line_col.second,
   ibp_err_data__symbol(*cur_pos));
}//IBP_ThrowErrorSymbolInCommandText

////////////////////////////////////////////////////////////////////////////////

template<class T>
COMP_CONF_DECLSPEC_NORETURN
 void IBP_ThrowIscErr_BugCheck_BadSqlLenOfXVar
       (const wchar_t* const sqlTypeSign,
        T              const sqllen)
{
 assert(sqlTypeSign);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__bad_sqllen_of_xvar_2,
   sqlTypeSign,
   sqllen);
}//IBP_ThrowIscErr_BugCheck_BadSqlLenOfXVar

//------------------------------------------------------------------------
template<class T>
COMP_CONF_DECLSPEC_NORETURN
 void IBP_ThrowIscErr_BugCheck_BadSqlLenOfXVar
       (t_ibp_subsystem_id const subsystem_id,  
        const wchar_t*     const sqlTypeSign,
        T                  const sqllen)
{
 assert(sqlTypeSign);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_isc__bug_check__bad_sqllen_of_xvar_2,
   sqlTypeSign,
   sqllen);
}//IBP_ThrowIscErr_BugCheck_BadSqlLenOfXVar

////////////////////////////////////////////////////////////////////////////////
//class IBP_ErrorUtils

template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN /*defined for avoiding a possible problem with MSVC*/
void IBP_ErrorUtils::Throw__Error
               (const std::exception&    e,
                HRESULT            const hr,
                ibp_msg_code_type  const msg_code,
                Args&&...                args)
{
 assert(FAILED(hr));

 t_ibp_error exc(e);

 exc.add_error(hr,msg_code);

 self_type::Helper__PushArgs
  (exc,
   std::forward<Args>(args)...);

 exc.raise_me();
}//Throw__Error

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN /*defined for avoiding a possible problem with MSVC*/
void IBP_ErrorUtils::Throw__Error
               (HRESULT            const hr,
                ibp_msg_code_type  const msg_code,
                Args&&...                args)
{
 assert(FAILED(hr));

 t_ibp_error exc(hr,msg_code);

 self_type::Helper__PushArgs
  (exc,
   std::forward<Args>(args)...);

 exc.raise_me();
}//Throw__Error

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN  /*defined for avoiding a possible problem with MSVC*/
void IBP_ErrorUtils::Throw__Error
               (const std::exception&    e,
                HRESULT            const hr,
                t_ibp_subsystem_id const subsystem_id,
                ibp_msg_code_type  const msg_code,
                Args&&...                args)
{
 assert(FAILED(hr));

 t_ibp_error exc(e);

 exc.add_error(hr,subsystem_id,msg_code);

 self_type::Helper__PushArgs
  (exc,
   std::forward<Args>(args)...);

 exc.raise_me();
}//Throw__Error

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN  /*defined for avoiding a possible problem with MSVC*/
void IBP_ErrorUtils::Throw__Error
               (HRESULT            const hr,
                t_ibp_subsystem_id const subsystem_id,
                ibp_msg_code_type  const msg_code,
                Args&&...                args)
{
 assert(FAILED(hr));

 t_ibp_error exc(hr,subsystem_id,msg_code);

 self_type::Helper__PushArgs
  (exc,
   std::forward<Args>(args)...);

 exc.raise_me();
}//Throw__Error

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN  /*defined for avoiding a possible problem with MSVC*/
void IBP_ErrorUtils::Throw__ErrorWithCustomErrorObject
               (HRESULT                         const hr,
                ibp_msg_code_type               const msg_code,
                t_ibp_error::get_cerr_obj_type* const pGetCErr,
                Args&&...                             args)
{
 assert(FAILED(hr));

 t_ibp_error exc(hr,msg_code,pGetCErr);

 self_type::Helper__PushArgs
  (exc,
   std::forward<Args>(args)...);

 exc.raise_me();
}//Throw__ErrorWithCustomErrorObject

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN  /*defined for avoiding a possible problem with MSVC*/
void IBP_ErrorUtils::Throw__ErrorWithCustomErrorObject
               (HRESULT                         const hr,
                t_ibp_subsystem_id              const subsystem_id,
                ibp_msg_code_type               const msg_code,
                t_ibp_error::get_cerr_obj_type* const pGetCErr,
                Args&&...                             args)
{
 assert(FAILED(hr));

 t_ibp_error exc(hr,subsystem_id,msg_code,pGetCErr);

 self_type::Helper__PushArgs
  (exc,
   std::forward<Args>(args)...);

 exc.raise_me();
}//Throw__ErrorWithCustomErrorObject

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN /*defined for avoiding a possible problem with MSVC*/
void IBP_ErrorUtils::ReThrowWithSameHResult
               (const std::exception&    e,
                ibp_msg_code_type  const msg_code,
                Args&&...                args)
{
 t_ibp_error exc(e);

 assert(FAILED(exc.com_code()));

 exc.add_error
  (exc.com_code(),
   msg_code);

 self_type::Helper__PushArgs
  (exc,
   std::forward<Args>(args)...);

 exc.raise_me();
}//ReThrowWithSameHResult

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN /*defined for avoiding a possible problem with MSVC*/
void IBP_ErrorUtils::ReThrowWithSameHResult
               (const std::exception&    e,
                t_ibp_subsystem_id       subsystem_id,
                ibp_msg_code_type  const msg_code,
                Args&&...                args)
{
 t_ibp_error exc(e);

 assert(FAILED(exc.com_code()));

 exc.add_error
  (exc.com_code(),
   subsystem_id,
   msg_code);

 self_type::Helper__PushArgs
  (exc,
   std::forward<Args>(args)...);

 exc.raise_me();
}//ReThrowWithSameHResult

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN  /*defined for avoiding a problem (warning) with MSVC*/
void IBP_ErrorUtils::Throw__BugCheck__DEBUG
             (const std::exception& e,
              const wchar_t* const  place,
              const wchar_t* const  point,
              const wchar_t* const  reason_template,
              Args&&...             args)
{
 assert(place);
 assert(point);
 assert(reason_template);

 structure::wstr_formatter freason(reason_template);

 self_type::Helper__PushArgs
  (freason,
   std::forward<Args>(args)...);

#if defined(IBP_BUILD_TESTCODE)
#else
 assert_msg(false,structure::tstr_to_str(freason.str()));
#endif

 self_type::Throw__Error
  (e,
   E_FAIL,
   ibp_mce_common__bug_check_3,
   place,
   point,
   freason.str());
}//Throw__BugCheck__DEBUG

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN  /*defined for avoiding a problem (warning) with MSVC*/
void IBP_ErrorUtils::Throw__BugCheck__DEBUG
             (const wchar_t* const place,
              const wchar_t* const point,
              const wchar_t* const reason_template,
              Args&&...            args)
{
 assert(place);
 assert(point);
 assert(reason_template);

 structure::wstr_formatter freason(reason_template);

 self_type::Helper__PushArgs
  (freason,
   std::forward<Args>(args)...);

#if defined(IBP_BUILD_TESTCODE)
#else
 assert_msg(false,structure::tstr_to_str(freason.str()));
#endif

 self_type::Throw__Error
  (E_FAIL,
   ibp_mce_common__bug_check_3,
   place,
   point,
   freason.str());
}//Throw__BugCheck__DEBUG

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN  /*defined for avoiding a problem (warning) with MSVC*/
void IBP_ErrorUtils::Throw__BugCheck
             (const wchar_t* const place,
              const wchar_t* const point,
              const wchar_t* const reason_template,
              Args&&...            args)
{
 assert(place);
 assert(point);
 assert(reason_template);

 structure::wstr_formatter freason(reason_template);

 self_type::Helper__PushArgs
  (freason,
   std::forward<Args>(args)...);

 self_type::Throw__Error
  (E_FAIL,
   ibp_mce_common__bug_check_3,
   place,
   point,
   freason.str());
}//Throw__BugCheck

//------------------------------------------------------------------------
template<typename Container,typename Arg1,typename... Args>
void IBP_ErrorUtils::Helper__PushArgs
               (Container& container,
                Arg1&&     arg1,
                Args&&...  args)
{
 container<<std::forward<Arg1>(arg1);

 return self_type::Helper__PushArgs
          (container,
           std::forward<Args>(args)...);
}//Helper__PushArgs

//------------------------------------------------------------------------
template<typename Container>
void IBP_ErrorUtils::Helper__PushArgs(Container& UNUSED_ARG(container))
{
}//Helper__PushArgs

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
