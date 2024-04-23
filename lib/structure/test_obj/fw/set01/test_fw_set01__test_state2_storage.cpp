////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
//#pragma hdrstop

#include <structure/test_obj/fw/set01/test_fw_set01__test_state2_storage.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//class TestFW__TestState2_Storage

TestFW__TestState2_Storage::TestFW__TestState2_Storage()
 :m_count(0)
 ,m_file(nullptr)
{
}

//------------------------------------------------------------------------
TestFW__TestState2_Storage::~TestFW__TestState2_Storage()
{
 if(m_file!=nullptr)
  fclose(m_file);
}//~TestFW__TestState2_Storage

//interface --------------------------------------------------------------
TestFW__TestState2_Storage::count_type
 TestFW__TestState2_Storage::get_count()
{
 const lock_guard_type __lock(m_guard);

 return m_count;
}//get_count

//------------------------------------------------------------------------
void TestFW__TestState2_Storage::append(const item_type& item)
{
 const lock_guard_type __lock(m_guard);

 //-----------------------------------------
 if(m_file==nullptr)
 {
  FILE* file=nullptr;

  if(LCPI_GCRT_tmpfile_s(&file)!=0)
   throw std::runtime_error("TestFW__TestState2_Storage did not create a temporary file.");

  assert(file!=nullptr);

  if(file==nullptr)
   throw std::runtime_error("[BUG CHECK][TestFW__TestState2_Storage::append][#001] file is nullptr.");

  m_file=file;
 }//if

 assert(m_file!=nullptr);

 const auto r=std::fwrite(&item,sizeof(item),1,m_file);

 if(r<1)
  throw std::runtime_error("TestFW__TestState2_Storage was not able to write data in file.");

 ++m_count;
}//append

//------------------------------------------------------------------------
void TestFW__TestState2_Storage::restart()
{
 const lock_guard_type __lock(m_guard);

 if(m_file==nullptr)
  return;

 const auto r=std::fseek(m_file,0,0);

 if(r!=0)
  throw std::runtime_error("TestFW__TestState2_Storage was not able to reset file position.");
}//restart

//------------------------------------------------------------------------
void TestFW__TestState2_Storage::fetch(item_type* const item)
{
 assert(item!=nullptr);

 const lock_guard_type __lock(m_guard);

 //-----------------------------------------
 if(m_file==nullptr)
  throw std::runtime_error("[BUG CHECK] TestFW__TestState2_Storage did not create a file.");
 
 //-----------------------------------------
 const auto r=std::fread(item,sizeof(*item),1,m_file);

 if(r!=1)
  throw std::runtime_error("TestFW__TestState2_Storage was not able to read data from file.");
}//fetch

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
