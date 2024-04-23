////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__exec_mt_H_
#define _test_fw_set01__exec_mt_H_

#include <structure/test_obj/fw/set01/test_fw_set01__base.h>
#include <structure/test_obj/fw/set01/test_fw_set01__sys_log.h>
#include <structure/test_obj/fw/set01/test_fw_set01__test_state2_storage.h>
#include <structure/mt/t_mt_thread_controller__std.h>
#include <structure/stl/t_stl_list.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//contatinings

class TestFW__TestQueueMT;
class TestFW__TestRunnerMT;
class TestFW__ExecutorMT;

////////////////////////////////////////////////////////////////////////////////
//class TestFW__TestQueueMT

class TestFW__TestQueueMT LCPI_CPP_CFG__CLASS__FINAL
 :public TestFW__SysSmartMemoryObject
{
 private:
  using self_type=TestFW__TestQueueMT;

  TestFW__TestQueueMT(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=structure::t_smart_object_ptr<self_type>;

  using allocator_type=TestFW__SysMemoryAllocator;

  using log_ex_type=TestFW__SysLog;
  using log_ex_ptr=log_ex_type::self_ptr;

  class tag_test_data
  {
   private:
    using self_type=tag_test_data;

   public:
    unsigned         m_exec_count;
    TestFW__TestCPtr m_test;

   public:
    tag_test_data(const TestFW__Test* test);

    tag_test_data(const self_type& x);

    self_type& operator = (const self_type&);
  };//class tag_test_data

  using test_queue_type
   =structure::t_stl_list<tag_test_data,allocator_type>;

  using size_type
   =test_queue_type::size_type;

  using guard_type
   =structure::t_guard;

  using lock_guard_type
   =structure::t_lock_guard<guard_type>;

  using test_results_type
   =TestFW__TestState2_Storage;

 public:
  using LCPI_OS__Event
   =lcpi::infrastructure::os::mt::LCPI_OS__Event;

  using WaitResultCode
   =LCPI_OS__Event::WaitResultCode;

  using LCPI_OS__EVENT_HANDLE
   =LCPI_OS__Event::EVENT_HANDLE;

  using TimeOut_t
   =LCPI_OS__Event::TimeOut_t;

 public:
  mutable guard_type m_ResultGuard;
  test_results_type  m_Results;

 public:
  /// <summary>
  ///  Initialize constructor
  /// </summary>
  //! \param[in] pLog
  //!  Log of primary thread
  //! \param[in] ExecMultplicator
  explicit TestFW__TestQueueMT(log_ex_type* pLog,
                               unsigned     ExecMultplicator);

  virtual ~TestFW__TestQueueMT();

  //interface ------------------------------------------------------------
  size_type size()const;

  void push_test(const TestFW__Test* pTest);

  void clear();

  void no_new_test__no_throw(bool clear);

  TestFW__TestCPtr pop_test(str_parameter         ThreadName,
                            LCPI_OS__EVENT_HANDLE hCancelEvent);

  WaitResultCode wait_pop_event(TimeOut_t dwMilliSeconds);

  //----------------------------------------------------------------------
  void add_result(str_parameter             ThreadName,
                  const TestFW__TestState2& TestResult);

 private:
  TestFW__TestCPtr pop_test_impl(LCPI_OS__EVENT_HANDLE hCancelEvent);

 private:
  const unsigned     m_ExecMultiplicator;

  mutable guard_type m_TestQueueGuard;
  test_queue_type    m_TestQueue;
  LCPI_OS__Event     m_TestQueue_PushEvent;
  LCPI_OS__Event     m_TestQueue_PopEvent;

  long               m_TestQueue_NoNewTest;

  log_ex_ptr  const  m_spLog;

 private:
  using test_num_type=std::uint64_t;

  guard_type     m_test_num_guard;
  test_num_type  m_test_num_gen;
};//class TestFW__TestQueueMT

////////////////////////////////////////////////////////////////////////////////
//class TestFW__TestRunnerMT

class TestFW__TestRunnerMT LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_basic_thread_controller__std<TestFW__SysSmartMemoryObject>
{
 public:
  using self_type=TestFW__TestRunnerMT;
  using inherited=structure::t_basic_thread_controller__std<TestFW__SysSmartMemoryObject>;

  TestFW__TestRunnerMT(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=structure::t_smart_object_ptr<self_type>;

  using log_type    =tso_obj::t_simple_log;
  using log_ptr     =log_type::self_ptr;

  using log_ex_type =TestFW__WorkerLog;
  using log_ex_ptr  =log_ex_type::self_ptr;

 private:
  TestFW__TestRunnerMT(TestFW__ExecutorMT*  pExecutor,
                       size_t               thread_idx,
                       const std::string&   thread_name,
                       log_ex_type*         pLog);

  virtual ~TestFW__TestRunnerMT();

 public:
  static self_ptr create(TestFW__ExecutorMT*  pExecutor,
                         size_t               ThreadIdx,
                         const std::string&   BaseLogFilePath);

 public:
  EVENT_HANDLE get_stop_event()const
  {
   return inherited::get_stop_event();
  }

  STOP_SIGNAL_TYPE get_stop_signal()const
  {
   return inherited::get_stop_signal();
  }
  
  const log_ex_ptr& thread_log()const
  {
   return m_log;
  }

  size_t thread_idx()const
  {
   return m_thread_idx;
  }

 private:
  virtual const char* thread_name_impl()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void thread_worker_impl() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  TestFW__ExecutorMT* const m_pExecutor;
  const size_t              m_thread_idx;
  const std::string         m_thread_name;
  const log_ex_ptr          m_log;
};//class TestFW__TestRunnerMT

////////////////////////////////////////////////////////////////////////////////
//class TestFW__ExecutorMT

class TestFW__ExecutorMT
 :public structure::t_basic_smart_interface_impl__dynamic<TestFW__PushTest,TestFW__SysMemoryAllocator>
{
 private:
  using self_type=TestFW__ExecutorMT;
  using inherited=structure::t_basic_smart_interface_impl__dynamic<TestFW__PushTest,TestFW__SysMemoryAllocator>                       ;

  TestFW__ExecutorMT(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=structure::t_smart_object_ptr<self_type>;

 public:
  TestFW__ExecutorMT(const std::string& BaseLogFilePath,
                     TestFW__SysLog*    pLog,
                     size_t             nThreads);

 protected:
  virtual ~TestFW__ExecutorMT();

 private:
  virtual void final_release()LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 public:
  const TestFW__SysLog::self_ptr& GetLog()const
  {
   return m_spLog;
  }
 
  //TestFW__PushTest interface -------------------------------------------
  virtual void PushTest(const test_type* pTest)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //----------------------------------------------------------------------
  void cancel();

  void stop__no_throw();

 public:
  /// <summary>
  ///  Build summary information
  /// </summary>
  //! \return
  //!  Total Error Count
  void build_summary3();

 protected:
  friend class TestFW__TestRunnerMT;

  using runner_type=TestFW__TestRunnerMT;

  virtual void Internal__ThreadWorker(const runner_type* pRunner)const;

 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Helper__ThrowBugCheck__bad_thread_id
   (const char*               place,
    const char*               point,
    const TestFW__TestState2& testState);

 private:
  std::string              const m_BaseLogFilePath;
  TestFW__SysLog::self_ptr const m_spLog;
  size_t                   const m_nThreads;

 private: //internal typedefs --------------------------------------------
  using runners_type
   =structure::t_smart_vector<TestFW__TestRunnerMT,TestFW__SysMemoryAllocator>;

  using test_queue_type
   =TestFW__TestQueueMT;

  using test_queue_ptr
   =test_queue_type::self_ptr;

 private: //executor data ------------------------------------------------
  test_queue_ptr const m_spTestQueue;

  runners_type m_TestRunners;

 private:
#ifndef NDEBUG
  unsigned m_debug__IsStopped;
#endif
};//class TestFW__ExecutorMT

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
