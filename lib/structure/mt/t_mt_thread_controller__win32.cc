////////////////////////////////////////////////////////////////////////////////
#ifndef _t_mt_thread_controller__win32_CC_
#define _t_mt_thread_controller__win32_CC_

#include <win32lib/win32_error.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_thread_controller__win32

template<class tag_base_smem_obj>
t_basic_thread_controller__win32<tag_base_smem_obj>::t_basic_thread_controller__win32()
 :m_aStopSignal(0)
{
 if(!m_StopEvent.Create(NULL,/*manual_reset*/true,/*init_state*/false))
  win32lib::t_win32_error::throw_error(::GetLastError(),"Create Thread StopEvent");
}//t_basic_thread_controller__win32

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
t_basic_thread_controller__win32<tag_base_smem_obj>::~t_basic_thread_controller__win32()
{
}

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
void t_basic_thread_controller__win32<tag_base_smem_obj>::wait_exit()
{
 m_Thread.Wait(INFINITE);
}//wait_exit

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
void t_basic_thread_controller__win32<tag_base_smem_obj>::start_thread_impl()
{
 assert(m_Thread.handle==NULL);
 assert(m_aStopSignal==0);
 
 if(!m_Thread.Create(NULL,8196,self_type::ThreadEntryPoint,this,0))
 {
  assert(m_Thread.handle==NULL);

  const DWORD win32_error_code=::GetLastError();

  assert(win32_error_code!=0);

  //----
  str_formatter fmsg("Start worker [%1] thread");

  fmsg<<this->thread_name();

  win32lib::t_win32_error::throw_error(win32_error_code,fmsg.c_str());
 }//if

 assert(m_Thread.handle!=NULL);
}//start_thread_impl

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
void t_basic_thread_controller__win32<tag_base_smem_obj>::stop_thread_impl()
{
 if(m_Thread.handle==NULL)
  return;
 
 m_aStopSignal.store(1);
 
 _VERIFY(m_StopEvent.Set());
 
 _VERIFY_EQ(m_Thread.Wait(INFINITE),WAIT_OBJECT_0);
}//stop_thread_impl

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
bool t_basic_thread_controller__win32<tag_base_smem_obj>::thread_is_active_impl()
{
 if(m_Thread.handle==NULL)
  return false;
  
 return m_Thread.Wait(0)==WAIT_TIMEOUT;
}//thread_is_active_impl

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
DWORD WINAPI t_basic_thread_controller__win32<tag_base_smem_obj>::ThreadEntryPoint
                                           (LPVOID const lpParam)
{
 assert(lpParam!=NULL);
 
 try
 {
  reinterpret_cast<self_type*>(lpParam)->thread_member(); //throw
 }
 catch(...)
 {;}
  
 return 0;
}//ThreadEntryPoint

//------------------------------------------------------------------------
template<class tag_base_smem_obj>
RELEASE_CODE(inline)
HANDLE t_basic_thread_controller__win32<tag_base_smem_obj>::get_thread_handle()const
{
 return m_Thread.handle;
}//get_stop_event
  
//------------------------------------------------------------------------
template<class tag_base_smem_obj>
RELEASE_CODE(inline)
HANDLE t_basic_thread_controller__win32<tag_base_smem_obj>::get_stop_event()const
{
 return m_StopEvent.handle;
}//get_stop_event
  
//------------------------------------------------------------------------
template<class tag_base_smem_obj>
RELEASE_CODE(inline)
unsigned t_basic_thread_controller__win32<tag_base_smem_obj>::get_stop_signal()const
{
 return m_aStopSignal.load();
}//get_stop_signal

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
