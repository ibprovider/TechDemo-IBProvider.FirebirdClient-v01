////////////////////////////////////////////////////////////////////////////////
#ifndef _cpp_public_lcpi_lib_structure_mt__t_mt_thread_controller__std_CC_
#define _cpp_public_lcpi_lib_structure_mt__t_mt_thread_controller__std_CC_

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_thread_controller__std

template<class tag_base_smem_obj>
t_basic_thread_controller__std<tag_base_smem_obj>::t_basic_thread_controller__std()
 :m_StopEvent(/*manual_reset*/true,/*init_state*/false)
 ,m_aStopSignal(0)
 ,m_hThread()
{
}//t_basic_thread_controller__std

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
t_basic_thread_controller__std<tag_base_smem_obj>::~t_basic_thread_controller__std()
{
 if(m_hThread!=THREAD_HANDLE())
 {
  thread_api::WaitAndCloseThread(m_hThread);

  m_hThread=THREAD_HANDLE();
 }//if
}//~t_basic_thread_controller__std

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
void t_basic_thread_controller__std<tag_base_smem_obj>::wait_exit()
{
 if(m_hThread==THREAD_HANDLE())
  return;

 thread_api::WaitForSingleThread(m_hThread,thread_api::Infinite);
}//wait_exit

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
void t_basic_thread_controller__std<tag_base_smem_obj>::start_thread_impl()
{
 assert(m_hThread==THREAD_HANDLE());
 assert(m_aStopSignal==0);

 m_hThread=thread_api::CreateThread(self_type::ThreadEntryPoint,this);

 assert(m_hThread!=THREAD_HANDLE());
}//start_thread_impl

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
void t_basic_thread_controller__std<tag_base_smem_obj>::stop_thread_impl()
{
 if(m_hThread==THREAD_HANDLE())
  return;

 m_aStopSignal.store(1);

 m_StopEvent.Set__Throw();

 thread_api::WaitForSingleThread(m_hThread,thread_api::Infinite);
}//stop_thread_impl

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
bool t_basic_thread_controller__std<tag_base_smem_obj>::thread_is_active_impl()
{
 if(m_hThread==THREAD_HANDLE())
  return false;

 return thread_api::WaitForSingleThread(m_hThread,0)==thread_api::WaitResultCode::Timeout;
}//thread_is_active_impl

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
RELEASE_CODE(inline)
typename t_basic_thread_controller__std<tag_base_smem_obj>::THREAD_HANDLE
 t_basic_thread_controller__std<tag_base_smem_obj>::get_thread_handle()
{
 return m_hThread;
}//get_thread_handle

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
RELEASE_CODE(inline)
typename t_basic_thread_controller__std<tag_base_smem_obj>::EVENT_HANDLE
 t_basic_thread_controller__std<tag_base_smem_obj>::get_stop_event()const
{
 return m_StopEvent.GetNativeHandle();
}//get_stop_event

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
RELEASE_CODE(inline)
typename t_basic_thread_controller__std<tag_base_smem_obj>::STOP_SIGNAL_TYPE
 t_basic_thread_controller__std<tag_base_smem_obj>::get_stop_signal()const
{
 return m_aStopSignal.load();
}//get_stop_signal

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
