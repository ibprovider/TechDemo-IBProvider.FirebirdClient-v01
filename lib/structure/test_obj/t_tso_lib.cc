////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tso_lib_CC_
#define _t_tso_lib_CC_

#include <structure/error/t_err_records_collection.h>
#include <structure/t_str_cvt_traits__utf8.h>

#include <lcpi/infrastructure/os/lcpi.infrastructure.os.mt-thread_api.h>

#include <iostream>
#include <sstream>
#include <iomanip>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_message

template<class Allocator,class StrCvtTraits>
t_basic_message<Allocator,StrCvtTraits>::t_basic_message(const self_type& x)
 :m_error_code (x.m_error_code)
 ,m_msg_kind   (x.m_msg_kind)
 ,m_source     (x.m_source)
 ,m_description(x.m_description)
{
}

//------------------------------------------------------------------------
template<class Allocator,class StrCvtTraits>
t_basic_message<Allocator,StrCvtTraits>::t_basic_message()
 :m_error_code(0)
 ,m_msg_kind(tso_msg_info)
{
}

//------------------------------------------------------------------------
template<class Allocator,class StrCvtTraits>
t_basic_message<Allocator,StrCvtTraits>::~t_basic_message()
{
}

//t_message interface ----------------------------------------------------
template<class Allocator,class StrCvtTraits>
typename t_basic_message<Allocator,StrCvtTraits>::error_code_type
 t_basic_message<Allocator,StrCvtTraits>::get_error_code()const
{
 return m_error_code;
}//get_error_code

//------------------------------------------------------------------------
template<class Allocator,class StrCvtTraits>
typename t_basic_message<Allocator,StrCvtTraits>::msg_kind_type
 t_basic_message<Allocator,StrCvtTraits>::get_msg_kind()const
{
 return m_msg_kind;
}//get_msg_kind

//------------------------------------------------------------------------
template<class Allocator,class StrCvtTraits>
bool t_basic_message<Allocator,StrCvtTraits>::get_description
                        (lcid_type    const /*lcid*/,
                         string_type* const source,
                         string_type* const description)const
{
 if(source!=nullptr)
  (*source)=m_source;

 if(description!=nullptr)
  (*description)=m_description;

 return true;
}//get_description

//------------------------------------------------------------------------
template<class Allocator,class StrCvtTraits>
t_message_ptr
 t_basic_message<Allocator,StrCvtTraits>::clone()const
{
 return structure::not_null_ptr(new self_type(*this));
}//clone

////////////////////////////////////////////////////////////////////////////////
//class t_basic_tracer

template<class Allocator>
t_basic_tracer<Allocator>::t_basic_tracer(const self_type& x)
 :m_log(x.log())
 ,m_message(structure::not_null_ptr(new message_type()))
{
 assert(m_log);
 assert(m_message);
}//t_basic_tracer - copy

//------------------------------------------------------------------------
template<class Allocator>
t_basic_tracer<Allocator>::t_basic_tracer(const self_type&       x,
                                          const string_au_type&  source)
 :m_log(x.log())
 ,m_message(structure::not_null_ptr(new message_type()))
{
 assert(m_log);
 assert(m_message);

 m_message->m_source=source;
}//t_basic_tracer

//------------------------------------------------------------------------
template<class Allocator>
t_basic_tracer<Allocator>::t_basic_tracer(log_type* const log)
 :m_log(structure::not_null_ptr(log))
 ,m_message(structure::not_null_ptr(new message_type()))
{
 assert(m_log);
 assert(m_message);
}//t_basic_tracer

//------------------------------------------------------------------------
template<class Allocator>
t_basic_tracer<Allocator>::t_basic_tracer(log_type*       const log,
                                          const string_au_type& source)
 :m_log(structure::not_null_ptr(log))
 ,m_message(structure::not_null_ptr(new message_type()))
{
 assert(m_log);
 assert(m_message);

 m_message->m_source=source;
}//t_basic_tracer

//------------------------------------------------------------------------
template<class Allocator>
t_basic_tracer<Allocator>::~t_basic_tracer()
{
}

//------------------------------------------------------------------------
template<class Allocator>
inline t_basic_tracer<Allocator>&
 t_basic_tracer<Allocator>::operator () (msg_kind_type   const msg_kind,
                                         error_code_type const error_code)
{
 assert(m_message);

 m_message->m_description.erase();

 m_message->m_msg_kind=msg_kind;

 m_message->m_error_code=error_code;

 return *this;
}//operator ()

//------------------------------------------------------------------------
template<class Allocator>
inline t_basic_tracer<Allocator>& t_basic_tracer<Allocator>::operator () ()
{
 return (*this)(tso_msg_info,0);
}//operator ()

//------------------------------------------------------------------------
template<class Allocator>
inline t_basic_tracer<Allocator>&
 t_basic_tracer<Allocator>::operator () (const string_au_type& source)
{
 assert(m_message);

 m_message->m_source=source;

 return (*this)(tso_msg_info,0);
}//operator ()

//------------------------------------------------------------------------
template<class Allocator>
inline t_basic_tracer<Allocator>&
 t_basic_tracer<Allocator>::change_msg_type(msg_kind_type   const msg_kind,
                                            error_code_type const error_code)
{
 assert(m_message);

 m_message->m_msg_kind=msg_kind;

 m_message->m_error_code=error_code;

 return *this;
}//change_msg_type

//------------------------------------------------------------------------
template<class Allocator>
t_basic_tracer<Allocator>& t_basic_tracer<Allocator>::send()
{
 assert(m_message);

 if(m_log)
  m_log->trace(m_message);

 return (*this)();
}//send

//------------------------------------------------------------------------
template<class Allocator>
t_basic_tracer<Allocator>& t_basic_tracer<Allocator>::add_arg(const arg_type& x)
{
 assert(m_message);

 m_message->m_description+=x;

 return *this;
}//add_arg

////////////////////////////////////////////////////////////////////////////////
//class t_basic_log_stream__console

template<class Allocator>
t_basic_log_stream__console<Allocator>::t_basic_log_stream__console()
{
#if _WIN32
 {
  const auto consoleCP=::GetConsoleOutputCP();

  if(consoleCP!=CP_UTF8)
   throw std::runtime_error("Windows console was not configured for using UTF8.");
 }
#endif
}//t_basic_log_stream__console

//------------------------------------------------------------------------
template<class Allocator>
t_basic_log_stream__console<Allocator>::~t_basic_log_stream__console()
{
}

//------------------------------------------------------------------------
template<class Allocator>
typename t_basic_log_stream__console<Allocator>::self_ptr
 t_basic_log_stream__console<Allocator>::create()
{
 return structure::not_null_ptr(new self_type());
}//create

//------------------------------------------------------------------------
template<class Allocator>
void t_basic_log_stream__console<Allocator>::out(const char_type* s)
{
 std::string utf8_str;

 t_str_cvt_traits__utf8::tstr_to_tstr
  (&utf8_str,
   s);

 std::cout<<utf8_str;
}//out

////////////////////////////////////////////////////////////////////////////////
//class t_basic_root_log__printer

template<class t_log_stream>
t_basic_root_log__printer<t_log_stream>::t_basic_root_log__printer
                                           (log_stream_type* const stream,
                                            const string_type&     line_prefix)
 :m_stream(structure::not_null_ptr(stream))
 ,m_line_prefix(line_prefix)
{
 assert(m_stream);
}//t_basic_root_log__printer

//------------------------------------------------------------------------
template<class t_log_stream>
t_basic_root_log__printer<t_log_stream>::~t_basic_root_log__printer()
{
}

//------------------------------------------------------------------------
template<class t_log_stream>
t_basic_root_log__printer<t_log_stream>&
 t_basic_root_log__printer<t_log_stream>::out(str_arg_type x)
{
 m_buffer.append(x.str());

 return *this;
}//out

//------------------------------------------------------------------------
template<class t_log_stream>
t_basic_root_log__printer<t_log_stream>&
 t_basic_root_log__printer<t_log_stream>::send()
{
 assert(m_stream);

 m_buffer+=structure::t_char_traits2<char_type>::ch_new_line();

 m_stream->out(m_line_prefix.c_str());
 m_stream->out(m_buffer.c_str());

 m_buffer.clear();

 return *this;
}//send

////////////////////////////////////////////////////////////////////////////////
//class t_basic_root_log

template<class Allocator>
t_basic_root_log<Allocator>::t_basic_root_log(t_log* const pParent,t_log_stream* const pOutputStream)
 :print_ts                (false)
 ,print_thread_id         (false)
 ,m_parent                (pParent)
 ,m_output_guard          () //For PVS-Studio
 ,m_output_stream         (structure::not_null_ptr(pOutputStream))
 ,m_unhandled_error_count (0)
 ,m_error_count           (0)
 ,m_warning_count         (0)
 ,m_child_error_count     (0)
 ,m_child_warning_count   (0)
{
 assert(m_output_stream);
}

//------------------------------------------------------------------------
template<class Allocator>
t_basic_root_log<Allocator>::~t_basic_root_log()
{
}

//------------------------------------------------------------------------
template<class Allocator>
RELEASE_CODE(inline)
typename t_basic_root_log<Allocator>::count_type
 t_basic_root_log<Allocator>::get_unhandled_error_count()const
{
 return m_unhandled_error_count;
}//get_unhandled_error_count

//------------------------------------------------------------------------
template<class Allocator>
RELEASE_CODE(inline)
typename t_basic_root_log<Allocator>::count_type
 t_basic_root_log<Allocator>::get_error_count()const
{
 return m_error_count+m_unhandled_error_count;
}//get_error_count

//------------------------------------------------------------------------
template<class Allocator>
RELEASE_CODE(inline)
typename t_basic_root_log<Allocator>::count_type
 t_basic_root_log<Allocator>::get_warning_count()const
{
 return m_warning_count;
}//get_warning_count

//------------------------------------------------------------------------
template<class Allocator>
RELEASE_CODE(inline)
typename t_basic_root_log<Allocator>::count_type
 t_basic_root_log<Allocator>::get_child_error_count()const
{
 return m_child_error_count;
}//get_child_error_count

//------------------------------------------------------------------------
template<class Allocator>
RELEASE_CODE(inline)
typename t_basic_root_log<Allocator>::count_type
 t_basic_root_log<Allocator>::get_child_warning_count()const
{
 return m_child_warning_count;
}//get_child_warning_count

//------------------------------------------------------------------------
template<class Allocator>
typename t_basic_root_log<Allocator>::count_type
 t_basic_root_log<Allocator>::get_total_error_count2()const
{
 return this->get_error_count()+this->get_child_error_count();
}//get_total_error_count2

//------------------------------------------------------------------------
template<class Allocator>
typename t_basic_root_log<Allocator>::count_type
 t_basic_root_log<Allocator>::get_total_warning_count2()const
{
 return this->get_warning_count()+this->get_child_warning_count();
}//get_total_warning_count2

//------------------------------------------------------------------------
template<class Allocator>
void t_basic_root_log<Allocator>::inc_unhandled_error_count()
{
 if(m_parent)
  m_parent->inc_child_error_count();

 structure::mt::interlocked::increment(&m_unhandled_error_count);
}//inc_unhandled_error_count

//------------------------------------------------------------------------
template<class Allocator>
void t_basic_root_log<Allocator>::inc_child_error_count()
{
 if(m_parent)
  m_parent->inc_child_error_count();

 structure::mt::interlocked::increment(&m_child_error_count);
}//inc_child_error_count

//------------------------------------------------------------------------
template<class Allocator>
void t_basic_root_log<Allocator>::inc_child_warning_count()
{
 if(m_parent)
  m_parent->inc_child_warning_count();

 structure::mt::interlocked::increment(&m_child_warning_count);
}//inc_child_error_count

//------------------------------------------------------------------------
void inc_child_warning_count();

//t_log interface --------------------------------------------------------
template<class Allocator>
void t_basic_root_log<Allocator>::trace(message_type* const msg)
{
 if(!msg)
  return;

 using string_type=message_type::string_type;

 string_type source;
 string_type descr;

 msg->get_description(message_type::lcid_type(),&source,&descr);

 const lock_guard_type __lock(m_output_guard);

 using printer_type=t_basic_root_log__printer<t_log_stream>;

 printer_type printer(m_output_stream,this->build_log_line_prefix());

 switch(msg->get_msg_kind())
 {
  case tso_msg_info: //[2018-12-23] For PVS-Studio
  {
   break;
  }

  case tso_msg_error:
  {
   if(m_parent)
    m_parent->inc_child_error_count();

   structure::mt::interlocked::increment(&m_error_count);

   printer.out(L"ERROR: ");
   break;
  }

  case tso_msg_warning:
  {
   if(m_parent)
    m_parent->inc_child_warning_count();

   structure::mt::interlocked::increment(&m_warning_count);

   printer.out(L"WARNING: ");
   break;
  }

  case tso_msg_start_test:
  {
   printer.send();
   printer.out(L"***********************************************").send();
   printer.out(L"* START TEST [").out(source).out(L"]").send();
   printer.out(L"*").send();

   return;
  }//tso_msg_start_test

  case tso_msg_stop_test:
  {
   printer.out(L"* STOP TEST [").out(source).out(L"]").send();
   return;
  }//tso_msg_stop_test
 }//switch

 if(!source.empty())
  printer.out(L"[").out(source).out(L"] ");

 printer.out(descr).send();
}//trace

//------------------------------------------------------------------------
template<class Allocator>
std::wstring t_basic_root_log<Allocator>::build_log_line_prefix()const
{
 std::wostringstream oss;

 if(this->print_thread_id)
 {
  oss<<L"[THR:"
     <<std::setfill(L'0')
     <<std::setw(6)
     <<::lcpi::infrastructure::os::mt::LCPI_OS__ThreadApi::GetCurrentThreadId()
     <<L"] ";
 }//if print_thread_id

 if(this->print_ts)
 {
  std::time_t const timer(std::time(nullptr));

  if(timer==-1)
   throw std::runtime_error("An unexpected problem - time returned -1.");

  struct tm t={0};

  if(LCPI_GCRT_localtime_s(&t,&timer)!=0)
  {
   //      2024-04-22 10:20:18
   oss<<L"[#error             ]";
  }
  else
  {
   oss<<L'['
      <<std::setfill(L'0')<<std::setw(4)<<(t.tm_year+1900)<<L'-'
      <<std::setfill(L'0')<<std::setw(2)<<(t.tm_mon+1)<<L'-'
      <<std::setfill(L'0')<<std::setw(2)<<(t.tm_mday)<<L' '
      <<std::setfill(L'0')<<std::setw(2)<<(t.tm_hour)<<L':'
      <<std::setfill(L'0')<<std::setw(2)<<(t.tm_min)<<L':'
      <<std::setfill(L'0')<<std::setw(2)<<(t.tm_sec)
      <<L"] ";
  }//else
 }//if print_ts

 return oss.str();
}//build_log_line_prefix

//------------------------------------------------------------------------
template<class Allocator>
void t_basic_root_log<Allocator>::push_empty_line()
{
 assert(m_output_stream);

 const lock_guard_type __lock(m_output_guard);

 m_output_stream->out(L"\n");
}//push_empty_line

////////////////////////////////////////////////////////////////////////////////
//class t_basic_exception_router

template<class t_tracer>
void t_basic_exception_router::route(t_tracer& tracer)
{
 try
 {
  throw;
 }
 catch(const std::exception& exc)
 {
  self_type::route(tracer,&exc);
 }
 catch(...)
 {
  self_type::route(tracer,nullptr);
 }
}//route

//------------------------------------------------------------------------
template<class t_tracer>
void t_basic_exception_router::route(t_tracer&                   tracer,
                                     const std::exception* const exc)
{
 if(exc==nullptr)
 {
  tracer(tso_msg_error,-1)<<L"Unknown program exception"<<send;

  return;
 }//if

 if(const t_err_records_r* const errs=dynamic_cast<const t_err_records_r*>(exc))
 {
  if(size_t const cErrs=errs->get_record_count())
  {
   assert_hint(cErrs>0);

   t_err_record::self_ptr    err;
   t_err_record::string_type err_source;
   t_err_record::string_type err_descr;

   for(size_t i=0;i!=cErrs;++i)
   {
    _VERIFY(err=errs->get_record(i));

    err->get_description(t_err_record::lcid_type(),&err_source,&err_descr);

    tracer(tso_msg_error,err->get_error_code())
     <<L"["<<err_source<<L"] "
     <<err_descr
     <<send;
   }//for

   return;
  }//if cErrs
 }//if errs

 tracer(tso_msg_error,-1)
  <<exc->what()
  <<send;
}//route

////////////////////////////////////////////////////////////////////////////////
}/*nms tso_obj*/}/*nms structure*/
#endif
