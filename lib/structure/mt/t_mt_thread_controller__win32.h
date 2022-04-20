////////////////////////////////////////////////////////////////////////////////
//Thread controller for WIN32 API
//                                                 Kovalenko Dmitry. 02.03.2009
#ifndef _t_mt_thread_controller__win32_H_
#define _t_mt_thread_controller__win32_H_

#include <structure/mt/t_mt_thread_controller.h>
#include <win32lib/win32_mt.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_thread_controller__win32

template<class tag_base_smem_obj>
class t_basic_thread_controller__win32:public t_basic_thread_controller<tag_base_smem_obj>
{
 private:
  typedef t_basic_thread_controller__win32<tag_base_smem_obj>     self_type;
  typedef t_basic_thread_controller<tag_base_smem_obj>            inherited;

  t_basic_thread_controller__win32(const self_type&);
  self_type& operator = (const self_type&);

 protected:
  virtual ~t_basic_thread_controller__win32();

 public:
  t_basic_thread_controller__win32();

  void wait_exit();

 private:
  virtual void start_thread_impl() COMP_W000004_OVERRIDE_FINAL;

  virtual void stop_thread_impl() COMP_W000004_OVERRIDE_FINAL;

  virtual bool thread_is_active_impl() COMP_W000004_OVERRIDE_FINAL;

  static DWORD WINAPI ThreadEntryPoint(LPVOID lpParam);

 protected:
  HANDLE get_stop_event()const;

  LONG   get_stop_signal()const;

  HANDLE get_thread_handle()const;

 private:
  win32lib::TThread      m_Thread;

 private:
  win32lib::TEvent       m_StopEvent;
  LONG                   m_StopSignal;
};//class t_basic_thread_controller__win32

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/mt/t_mt_thread_controller__win32.cc>
////////////////////////////////////////////////////////////////////////////////
#endif