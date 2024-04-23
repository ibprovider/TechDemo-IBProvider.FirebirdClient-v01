//LCPI Instrumental Library for C++. Interface of thread controller.
//                                                Kovalenko Dmitry. 02.03.2009.
#ifndef _cpp_public_lcpi_lib_structure_mt__t_thread_controller_CC_
#define _cpp_public_lcpi_lib_structure_mt__t_thread_controller_CC_

namespace lcpi{namespace lib{namespace structure{namespace mt{
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
  LCPI__assert(false);
 }//catch

 inherited::final_release();
}//final_release

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
LCPI__RELEASE_CODE(inline)
const char* t_basic_thread_controller<tag_base_smem_obj>::thread_name()const
{
 return this->thread_name_impl();
}//thread_name

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
LCPI__RELEASE_CODE(inline)
void t_basic_thread_controller<tag_base_smem_obj>::start_thread()
{
 {
  //reset result data

#ifndef NDEBUG
  const debug::t_debug__mt_guard_rw_lock_r __lock(m_result_guard___debug);
#endif

  m_result_normal_exit=false;

  m_result_exc=nullptr;
 }//local

 return this->start_thread_impl();
}//start_thread

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
LCPI__RELEASE_CODE(inline)
void t_basic_thread_controller<tag_base_smem_obj>::stop_thread()
{
 return this->stop_thread_impl();
}//stop_thread

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
LCPI__RELEASE_CODE(inline)
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
  LCPI__assert(false); //DEBUG BUG-CHECK

  std::string msg;

  msg+="[BUG CHECK] Can't process the errors of active thread.";
  msg+=this->thread_name();
  msg+="].";

  throw std::runtime_error(msg);
 }//if

 //-----------------------------------------------------------------------
#ifndef NDEBUG
 const debug::t_debug__mt_guard_rw_lock_r __lock(m_result_guard___debug);
#endif

 if(m_result_exc)
 {
  std::rethrow_exception(m_result_exc);
 }//if

 LCPI__assert_hint(!m_result_exc);

 if(!m_result_normal_exit)
 {
  std::string msg;

  msg+="Thread [";
  msg+=this->thread_name();
  msg+="] was terminated by unexpected reason.";

  throw std::runtime_error(msg);
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
  const debug::t_debug__mt_guard_rw_lock_w __lock(m_result_guard___debug);
#endif

  m_result_normal_exit=true;
 }
 catch(...)
 {
#ifndef NDEBUG
  const debug::t_debug__mt_guard_rw_lock_w __lock(m_result_guard___debug);
#endif

  m_result_exc=std::current_exception(); //no throw

  LCPI__assert(m_result_exc);
 }//catch
}//thread_member

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
