////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++. Standard thread controller.
//                                                 Kovalenko Dmitry. 26.03.2024.
#ifndef _cpp_public_lcpi_lib_structure_mt__t_mt_thread_controller__std_H_
#define _cpp_public_lcpi_lib_structure_mt__t_mt_thread_controller__std_H_

#include <structure/mt/t_mt_thread_controller.h>

#include <lcpi/infrastructure/os/lcpi.infrastructure.os.mt-event.h>

#include <atomic>
#include <thread>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_thread_controller__std

template<class tag_base_smem_obj>
class t_basic_thread_controller__std:public t_basic_thread_controller<tag_base_smem_obj>
{
 private:
  using self_type=t_basic_thread_controller__std<tag_base_smem_obj>;
  using inherited=t_basic_thread_controller<tag_base_smem_obj>;

  t_basic_thread_controller__std(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using thread_api=lcpi::infrastructure::os::mt::LCPI_OS__ThreadApi;

  using event_type=lcpi::infrastructure::os::mt::LCPI_OS__Event;

  using EVENT_HANDLE=event_type::EVENT_HANDLE;

  using THREAD_HANDLE=thread_api::THREAD_HANDLE;

  using STOP_SIGNAL_TYPE=unsigned;

 public:
  t_basic_thread_controller__std();

 protected:
  virtual ~t_basic_thread_controller__std();

 public:
  void wait_exit();

 private:
  virtual void start_thread_impl() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void stop_thread_impl() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool thread_is_active_impl() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static LCPI_OS__DECLARE_THREAD_ROUTINE(ThreadEntryPoint)
  {
   assert(pArg!=nullptr);

   try
   {
    reinterpret_cast<self_type*>(pArg)->thread_member(); //throw
   }
   catch(...)
   {
    assert(false);
   }//catch

   return 0;
  }//ThreadEntryPoint

 protected:
  EVENT_HANDLE get_stop_event()const;

  STOP_SIGNAL_TYPE get_stop_signal()const;

  THREAD_HANDLE get_thread_handle();

 private:
  event_type m_StopEvent;

  std::atomic<STOP_SIGNAL_TYPE> m_aStopSignal;

 private:
  THREAD_HANDLE m_hThread;
};//class t_basic_thread_controller__std

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/mt/t_thread_controller__std.cc>
////////////////////////////////////////////////////////////////////////////////
#endif