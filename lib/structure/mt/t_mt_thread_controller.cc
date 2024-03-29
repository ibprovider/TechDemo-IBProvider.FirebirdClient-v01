////////////////////////////////////////////////////////////////////////////////
#ifndef _t_mt_thread_controller_CC_
#define _t_mt_thread_controller_CC_

#include <structure/t_str_formatter.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_thread_controller

template<class tag_base_smem_obj>
t_basic_thread_controller<tag_base_smem_obj>::t_basic_thread_controller()
 :m_result_exc(nullptr)
 ,m_result_normal_exit(true)
{
}

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
t_basic_thread_controller<tag_base_smem_obj>::~t_basic_thread_controller()
{
}

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
void t_basic_thread_controller<tag_base_smem_obj>::final_release()
{
 try
 {
  this->stop_thread();
 }
 catch(...)
 {
  assert(false);
 }//catch

 inherited::final_release();
}//final_release

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
RELEASE_CODE(inline)
const wchar_t* t_basic_thread_controller<tag_base_smem_obj>::thread_name()const
{
 return this->thread_name_impl();
}//thread_name

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
RELEASE_CODE(inline)
void t_basic_thread_controller<tag_base_smem_obj>::start_thread()
{
 {
  //reset result data

#ifndef NDEBUG
  const t_debug__mt_guard_rw_lock_r __lock(m_result_guard___debug);
#endif

  m_result_normal_exit=false;

  m_result_exc=nullptr;
 }//local

 return this->start_thread_impl();
}//start_thread

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
RELEASE_CODE(inline)
void t_basic_thread_controller<tag_base_smem_obj>::stop_thread()
{
 return this->stop_thread_impl();
}//stop_thread

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
RELEASE_CODE(inline)
bool t_basic_thread_controller<tag_base_smem_obj>::thread_is_active()
{
 return this->thread_is_active_impl();
}//thread_is_active

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
void t_basic_thread_controller<tag_base_smem_obj>::rethrow_thread_error()
{
 if(this->thread_is_active())
 {
  assert(false); //DEBUG BUG-CHECK

  str_formatter fmsg("[BUG CHECK] Can't process the errors of active thread [%1].");

  fmsg<<this->thread_name();

  throw std::runtime_error(fmsg);
 }//if

 //-----------------------------------------------------------------------
#ifndef NDEBUG
 const t_debug__mt_guard_rw_lock_r __lock(m_result_guard___debug);
#endif

 if(m_result_exc)
 {
  std::rethrow_exception(m_result_exc);
 }//if

 assert_hint(!m_result_exc);

 if(!m_result_normal_exit)
 {
  str_formatter fmsg("Thread [%1] was terminated by unexpected reason");

  fmsg<<this->thread_name();

  throw std::runtime_error(fmsg);
 }//if
}//rethrow_thread_error

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
void t_basic_thread_controller<tag_base_smem_obj>::thread_member()
{
 try
 {
  this->thread_worker_impl();

#ifndef NDEBUG
  const t_debug__mt_guard_rw_lock_w __lock(m_result_guard___debug);
#endif

  m_result_normal_exit=true;
 }
 catch(...)
 {
#ifndef NDEBUG
  const t_debug__mt_guard_rw_lock_w __lock(m_result_guard___debug);
#endif

  m_result_exc=std::current_exception(); //no throw

  assert(m_result_exc);
 }//catch
}//thread_member

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
