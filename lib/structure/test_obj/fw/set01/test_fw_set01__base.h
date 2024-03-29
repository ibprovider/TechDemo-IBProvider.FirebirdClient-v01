////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__base_H_
#define _test_fw_set01__base_H_

#include <structure/test_obj/fw/set01/test_fw_set01__log_stream.h>
#include <structure/test_obj/t_tso_lib.h>
#include <structure/t_memory.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_LIB__DECLARE_WRAP_ALLOCATOR(TestFW__StdMemoryAllocator)

LCPI_CPP_LIB__DECLARE_WRAP_ALLOCATOR(TestFW__SysMemoryAllocator)

////////////////////////////////////////////////////////////////////////////////

using TestFW__SysSmartInterface
 =structure::t_smart_interface;

using TestFW__SysSmartMemoryObject
 =structure::t_basic_smart_interface_impl__dynamic
    <TestFW__SysSmartInterface,
     TestFW__SysMemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////

using TestFW__ExceptionRouter
 =tso_obj::t_basic_exception_router;

////////////////////////////////////////////////////////////////////////////////

using TestFW__SysTracer
 =structure::tso_obj::t_basic_tracer<TestFW__SysMemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////

using TestFW__WorkerLog
 =tso_obj::t_basic_root_log<TestFW__SysMemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////

using TestFW__SysLogStream_ToFile
 =structure::test_fw::set01::Basic_LogStream_ToFile<TestFW__SysMemoryAllocator>;

using TestFW__SysLogStream
 =structure::test_fw::set01::Basic_LogStream<TestFW__SysMemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////
//class TestFW__Test

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE TestFW__Test
 :public TestFW__SysSmartInterface
{
 public: //typedefs ------------------------------------------------------
  using context_type=tso_obj::t_simple_log;

 public:
  virtual const char* get_id()const=0;

  virtual void run(context_type* pCtx)const=0;
};//class TestFW__Test

using TestFW__TestCPtr
 =structure::t_smart_object_ptr<const TestFW__Test>;

////////////////////////////////////////////////////////////////////////////////
//class TestFW__PushTest

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE TestFW__PushTest
 :public TestFW__SysSmartInterface
{
 public:
  using test_type=TestFW__Test;

 public:
  virtual void PushTest(const test_type* pTest)=0;
};//TestFW__PushTest

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif