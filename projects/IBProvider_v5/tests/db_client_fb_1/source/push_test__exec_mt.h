////////////////////////////////////////////////////////////////////////////////
//IBProvider tests. Structures for multithreaded test execution
//                                                Kovalenko Dmitry. 02.03.2009
#ifndef _push_test__exec_mt_H_
#define _push_test__exec_mt_H_

#include "source/test_base.h"
#include "source/test_state2_storage.h"
#include <structure/mt/t_mt_thread_controller__win32.h>
#include <structure/stl/t_stl_list.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//contatinings

class TTSO_TestQueueMT;
class TTSO_TestRunnerMT;
class TTSO_PushTest__ExecutorMT;

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef structure::t_smart_vector<TTSO_TestRunnerMT,
                                  TTSO_MemoryAllocator>  TTSO_TestRunnerMT_Vector;

////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestQueueMT

class TTSO_TestQueueMT:public TTSO_SmartMemoryObject
{
 private:
  typedef TTSO_TestQueueMT                                  self_type;

  TTSO_TestQueueMT(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>          self_ptr;

  typedef TTSO_MemoryAllocator                              allocator_type;

  typedef TTSO_Test                                         test_type;
  typedef TTSO_TestCPtr                                     test_cptr;

  typedef TSYS_RootLog                                      log_ex_type;
  typedef log_ex_type::self_ptr                             log_ex_ptr;

  class tag_test_data
  {
   private:
    typedef tag_test_data                   self_type;

   public:
    unsigned m_exec_count;
    test_cptr m_test;

   public:
    tag_test_data(const test_type* test);

    tag_test_data(const self_type& x);

    self_type& operator = (const self_type&);
  };//class tag_test_data

  typedef structure::t_stl_list
           <tag_test_data,
            allocator_type>                                 test_queue_type;

  typedef test_queue_type::size_type                        size_type;

  typedef structure::t_multi_thread_traits                  thread_traits;
  typedef thread_traits::guard_type                         guard_type;
  typedef thread_traits::lock_guard_type                    lock_guard_type;

  typedef TTSO_TestRunnerMT                                 runner_type;
  typedef TTSO_TestRunnerMT_Vector                          runners_type;

 public:
  /// <summary>
  ///  Initialize constructor
  /// </summary>
  //! \param[in] pLog
  //!  Log of primary thread
  //! \param[in] ExecMultplicator
  explicit TTSO_TestQueueMT(log_ex_type* pLog,
                            unsigned     ExecMultplicator);

  virtual ~TTSO_TestQueueMT();

  //interface ------------------------------------------------------------
  size_type size()const;

  void push_test(const test_type* pTest);

  void no_new_test__no_throw(bool clear);

  test_cptr pop_test(const wchar_t* ThreadName,
                     HANDLE         hCancelEvent);

  DWORD wait_pop_event(DWORD dwMilliSeconds);

  //----------------------------------------------------------------------
  void add_result(const wchar_t*         ThreadName,
                  const TTSO_TestState2& TestResult);

  //----------------------------------------------------------------------
  long get_total_err_count()const;

  long get_total_warning_count()const;

  /// <summary>
  ///  Build summary information
  /// </summary>
  //! \return
  //!  Total Error Count
  long build_summary(const runners_type& Runners)const;

 private:
  test_cptr pop_test_impl(HANDLE hCancelEvent);

 private:
  typedef TTSO_MemoryAllocator              allocator_type;

  typedef TTSO_TestState2_Storage           test_results_type;

 private:
  const unsigned     m_ExecMultiplicator;

  mutable guard_type m_TestQueueGuard;
  test_queue_type    m_TestQueue;
  win32lib::TEvent   m_TestQueue_PushEvent;
  win32lib::TEvent   m_TestQueue_PopEvent;

  long               m_TestQueue_NoNewTest;

  log_ex_ptr  const  m_spLog;

 private:
  mutable guard_type m_ResultGuard;
  test_results_type  m_Results;

 private:
  typedef unsigned __int64    test_num_type;

  guard_type     m_test_num_guard;
  test_num_type  m_test_num_gen;
};//class TTSO_TestQueueMT

////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestRunnerMT

class TTSO_TestRunnerMT:public structure::t_basic_thread_controller__win32<TTSO_SmartMemoryObject>
{
 public:
  typedef TTSO_TestRunnerMT                                                    self_type;
  typedef structure::t_basic_thread_controller__win32<TTSO_SmartMemoryObject>  inherited;

  TTSO_TestRunnerMT(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>                  self_ptr;

  typedef TTSO_TestQueueMT                                          test_queue_type;
  typedef test_queue_type::self_ptr                                 test_queue_ptr;

  typedef tso_obj::t_simple_log                                     log_type;
  typedef log_type::self_ptr                                        log_ptr;

  typedef TTSO_RootLog                                              log_ex_type;
  typedef log_ex_type::self_ptr                                     log_ex_ptr;

 private:
  TTSO_TestRunnerMT(const TTSO_GlobalContext* pSD,
                    size_t                    thread_idx,
                    const std::wstring&       thread_name,
                    TTSO_TestQueueMT*         pTestQueue,
                    log_ex_type*              pLog);

  virtual ~TTSO_TestRunnerMT();

 public:
  static self_ptr create(const TTSO_GlobalContext* pSD,
                         size_t                    ThreadIdx,
                         TTSO_TestQueueMT*         pTestQueue,
                         const std::string&        BaseLogFilePath);

 public:
  const log_ex_ptr& thread_log()const
   {return m_log;}

 public:
  virtual const wchar_t* thread_name_impl()const COMP_W000004_OVERRIDE;

 private:
  virtual void thread_worker_impl() COMP_W000004_OVERRIDE;

 private:
  const TTSO_GlobalContext::self_cptr m_spSD;
  const size_t                        m_thread_idx;
  const std::wstring                  m_thread_name;
  const test_queue_ptr                m_test_queue;
  const log_ex_ptr                    m_log;
};//class TTSO_TestRunnerMT

////////////////////////////////////////////////////////////////////////////////
//class TTSO_PushTest__ExecutorMT

class TTSO_PushTest__ExecutorMT
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_PushTest,TTSO_MemoryAllocator>
{
 private:
  typedef TTSO_PushTest__ExecutorMT                   self_type;

  TTSO_PushTest__ExecutorMT(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>    self_ptr;

  typedef TSYS_RootLog                                log_ex_type;
  typedef log_ex_type::self_ptr                       log_ex_ptr;

 private:
  TTSO_PushTest__ExecutorMT(const TTSO_GlobalContext* pSD,
                            const std::string&        BaseLogFilePath,
                            log_ex_type*              pLog,
                            size_t                    nThread);

  virtual ~TTSO_PushTest__ExecutorMT();

 public:
  static self_ptr create(const TTSO_GlobalContext* pSD,
                         const std::string&        BaseLogFilePath,
                         log_ex_type*              pRootLog);

  //TTSO_PushTest interface ----------------------------------------------
  virtual void PushTest(const TTSO_Test* pTest)COMP_W000004_OVERRIDE_FINAL;

  //----------------------------------------------------------------------
  void cancel();

  void stop__no_throw();

  /// <summary>
  ///  Build summary information
  /// </summary>
  //! \return
  //!  Total Error Count
  long build_summary();

 private:
  TTSO_GlobalContext::self_cptr const  m_spSD;
  std::string                   const  m_BaseLogFilePath;
  log_ex_ptr                    const  m_spLog;
  size_t                        const  m_nThread;

 private: //internal typedefs --------------------------------------------
  typedef TTSO_TestRunnerMT                      runner_type;
  typedef TTSO_TestRunnerMT_Vector               runners_type;

  typedef TTSO_TestQueueMT                       test_queue_type;
  typedef test_queue_type::self_ptr              test_queue_ptr;

 private: //executor data ------------------------------------------------
  runners_type           m_TestRunners;

  test_queue_ptr const   m_spTestQueue;

 private:
#ifndef NDEBUG
  unsigned m_debug__IsStopped;
#endif
};//class TTSO_PushTest__ExecutorMT

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
