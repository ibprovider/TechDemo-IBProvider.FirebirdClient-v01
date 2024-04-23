////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++. Interface of thread controller.
//                                                Kovalenko Dmitry. 02.03.2009.
#ifndef _cpp_public_lcpi_lib_structure_mt__t_thread_controller_H_
#define _cpp_public_lcpi_lib_structure_mt__t_thread_controller_H_

#include <lcpi/lib/.config.h>

#ifndef NDEBUG
#include <lcpi/lib/structure/debug/t_debug__mt_guard_rw.h>
#endif

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class t_thread_controller

template<class tag_base_smem_obj>
class t_basic_thread_controller:virtual public tag_base_smem_obj
{
 private:
  using self_type=t_basic_thread_controller<tag_base_smem_obj>;
  using inherited=tag_base_smem_obj;

  t_basic_thread_controller(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------

 public:
  t_basic_thread_controller();

 protected:
  virtual ~t_basic_thread_controller();

  virtual void final_release() LCPI_CPP_CFG__METHOD__OVERRIDE;

 public:
  //interface ------------------------------------------------------------
  const char* thread_name()const;

  void start_thread();

  void stop_thread();

  bool thread_is_active();

  //----------------------------------------------------------------------
  void rethrow_thread_error();

 protected:
  void thread_member();

 protected:
  void helper__process_exception();

 private:
  virtual const char* thread_name_impl()const=0;

  virtual void start_thread_impl()=0;

  virtual void stop_thread_impl()=0;

  virtual bool thread_is_active_impl()=0;

  virtual void thread_worker_impl()=0;

 private:
#ifndef NDEBUG
  debug::t_debug__mt_guard_rw m_result_guard___debug;
#endif

  std::exception_ptr          m_result_exc;
  bool                        m_result_normal_exit;
};//class t_basic_thread_controller

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/mt/t_thread_controller.cc>
////////////////////////////////////////////////////////////////////////////////
#endif