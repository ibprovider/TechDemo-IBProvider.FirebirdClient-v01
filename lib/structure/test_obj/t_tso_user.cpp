////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
//#pragma hdrstop

#include <structure/test_obj/t_tso_user.h>
#include <structure/t_negative_one.h>

#include <structure/utilities/string/is_like_str.h>
#include <structure/mt/interlocked.h>

#ifdef _WIN32
#include <structure/t_char_converter.h>
#endif

#include <vector>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//process_exception

std::string console_out_str(const char* const s)
{
#ifdef _WIN32
 if(GetConsoleOutputCP()==::GetOEMCP())
  return ansi_to_oem(s);
#endif

 return s?s:"";
}//console_out_str

//------------------------------------------------------------------------
int process_exception(const char* source,const std::exception* exc)
{
 std::cout<<std::endl;
 std::cout<<"ERROR: ["<<console_out_str(source)<<"] - ";

 if(exc==nullptr)
 {
  std::cout<<"unknown program exception"<<std::endl;

  return 1;
 }

 std::cout<<console_out_str(exc->what())<<std::endl;

 return 1;
}//process_exception

//------------------------------------------------------------------------
int route_exception(const char* const source)
{
 int c=0;

 try
 {
  throw;
 }
 catch(const std::exception& exc)
 {
  c=structure::tso_obj::process_exception(source,&exc);
 }
 catch(...)
 {
  c=structure::tso_obj::process_exception(source,nullptr);
 }

 return c;
}//route_exception

////////////////////////////////////////////////////////////////////////////////
//struct TestMemAllocatorFunc

TestMemAllocatorFunc::cnt_type TestMemAllocatorFunc::sm_BlockCount=0;

//------------------------------------------------------------------------
void* TestMemAllocatorFunc::Alloc(size_t const sz)
{
 if(sz==0)
  return nullptr;

 void* const pv=::operator new (sz);

 if(pv)
 {
  LCPI__DEBUG_CODE(const auto debug_r=)interlocked::increment(&sm_BlockCount);

  LCPI__assert(sm_BlockCount>0);

  LCPI__assert(debug_r>0);
 }//if

 return pv;
}//Alloc

//------------------------------------------------------------------------
void TestMemAllocatorFunc::Free(void* const pv)
{
 if(pv==nullptr)
  return;

 LCPI__assert(sm_BlockCount>0);

 if(sm_BlockCount==0)
  throw std::runtime_error("[TestMemAllocatorFunc::Free] No allocated block.");

 ::operator delete (pv);

 if(structure::is_negative_one(interlocked::decrement(&sm_BlockCount)))
  throw std::runtime_error("[TestMemAllocatorFunc::Free] Bad work.");
}//Free

//------------------------------------------------------------------------
void TestMemAllocatorFunc::CheckNoBlock()
{
 if(sm_BlockCount==0)
  return;

 const auto msg="[TestMemAllocatorFunc] Has allocated "+std::to_string(sm_BlockCount)+" block(s)";

 throw std::runtime_error(msg);
}//CheckNoBlock

////////////////////////////////////////////////////////////////////////////////
//process tests mask

static bool can_exec_test(const char* test_name,const char* test_mask)
{
 assert(test_name);

 if(test_mask==0 || (*test_mask)==0)
  return true;

 return is_like_str
         ('?',
          '*',
          test_name,
          test_name+strlen(test_name),
          test_mask,
          test_mask+strlen(test_mask));
}//can_exec_test

////////////////////////////////////////////////////////////////////////////////
//run tests

int run_tests(const t_test_descr_0* pTests,const char* TestsMask)
{
 using name_vector_type=std::vector<std::string>;

 //-----------------------------------------------------------------------
 if(pTests==nullptr)
  return 0;

 int error_count=0;

 size_t nTest=0;

 name_vector_type FailedTests;

 for(;pTests->func!=nullptr;++pTests)
 {
  assert(pTests->name);

  if(!can_exec_test(pTests->name,TestsMask))
   continue;

  ++nTest;

  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<"RUN: "<<nTest<<". ["<<pTests->name<<"]"<<std::endl;

  try
  {
   pTests->func();
  }
  catch(...)
  {
   error_count+=route_exception("run_tests");

   FailedTests.push_back(pTests->name);
  }//catch

  std::cout<<std::endl;
 }//for pTests

 if(!FailedTests.empty())
 {
  std::cout<<std::endl;
  std::cout<<"[FAILED TESTS] ---------------------------"<<std::endl;
  std::cout<<std::endl;

  for(name_vector_type::size_type i=0;i!=FailedTests.size();++i)
  {
   std::cout.fill('0');

   std::cout<<std::setw(4)<<std::right<<i<<". "<<FailedTests[i]<<std::endl;
  }//for
 }//if

 std::cout<<std::endl;
 std::cout<<"[SUMMARY TESTS INFORMATION] --------------"<<std::endl;
 std::cout<<std::endl;
 std::cout<<"TOTAL  :"<<nTest<<std::endl;
 std::cout<<"FAILED :"<<FailedTests.size()<<std::endl;

 return error_count;
}//run_tests

//------------------------------------------------------------------------
int run_tests(const t_test_descr_0_r* pTests)
{
 if(pTests==nullptr)
  return 0;

 int error_count=0;

 for(;pTests->func!=nullptr;++pTests)
 {
  assert(pTests->name);

  _TSO_TRY_
  {
   std::cout<<"------------------------------------------"<<std::endl;
   std::cout<<"RUN: ["<<pTests->name<<"]"<<std::endl;

   error_count+=pTests->func();

   std::cout<<std::endl;
  }
  _TSO_CATCHES_("run_tests",error_count)
 }//for pTests

 return error_count;
}//run_tests

////////////////////////////////////////////////////////////////////////////////
}/*tso_obj*/}/*structure*/
