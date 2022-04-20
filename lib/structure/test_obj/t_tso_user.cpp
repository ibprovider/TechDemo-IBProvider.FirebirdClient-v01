////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <structure/test_obj/t_tso_user.h>
#include <structure/t_str_formatter.h>
#include <structure/t_str_like.h>
#include <vector>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//process_exception

std::string console_out_str(const char* const s)
{
 if(GetConsoleOutputCP()==::GetOEMCP())
  return ansi_to_oem(s);

 return s?s:"";
}//console_out_str

//------------------------------------------------------------------------
int process_exception(const char* source,const std::exception* exc)
{
 std::cout<<std::endl;
 std::cout<<"ERROR: ["<<ansi_to_oem(source)<<"] - ";

 if(exc==NULL)
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
  c=structure::tso_obj::process_exception(source,NULL);
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
  return NULL;

 void* const pv=::operator new (sz);

 if(pv)
  thread_traits::increment(&sm_BlockCount);

 return pv;
}//Alloc

//------------------------------------------------------------------------
void TestMemAllocatorFunc::Free(void* const pv)
{
 if(pv==NULL)
  return;

 if(sm_BlockCount==0)
  throw std::runtime_error("[TestMemAllocatorFunc::Free] No allocated block.");

 ::operator delete (pv);

 if(structure::is_negative_one(thread_traits::decrement(&sm_BlockCount)))
  throw std::runtime_error("[TestMemAllocatorFunc::Free] Bad work.");
}//Free

//------------------------------------------------------------------------
void TestMemAllocatorFunc::CheckNoBlock()
{
 if(sm_BlockCount==0)
  return;
  
 structure::str_formatter fmsg("[TestMemAllocatorFunc] Has allocated %1 block(s)");
 
 throw std::runtime_error(fmsg<<sm_BlockCount);
}//CheckNoBlock

////////////////////////////////////////////////////////////////////////////////
//process tests mask

static bool can_exec_test(const char* test_name,const char* test_mask)
{
 assert(test_name);
 
 if(test_mask==0 || (*test_mask)==0)
  return true;
 
 typedef const char* iterator_type;
 
 const t_str_like<iterator_type,iterator_type> str_like('?','*');
 
 return str_like.run(test_name,
                     test_name+strlen(test_name),
                     test_mask,
                     test_mask+strlen(test_mask)); 
}//can_exec_test

////////////////////////////////////////////////////////////////////////////////
//run tests

int run_tests(const t_test_descr_0* pTests,const char* TestsMask)
{
 typedef std::vector<std::string> name_vector_type;
 
 //-----------------------------------------------------------------------
 if(pTests==NULL)
  return 0;
 
 int error_count=0;

 size_t nTest=0;
 
 name_vector_type FailedTests;
 
 for(;pTests->func!=NULL;++pTests)
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
 if(pTests==NULL)
  return 0;
 
 int error_count=0;

 for(;pTests->func!=NULL;++pTests)
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
 }//for i

 return error_count;
}//run_tests

////////////////////////////////////////////////////////////////////////////////
}/*tso_obj*/}/*structure*/
