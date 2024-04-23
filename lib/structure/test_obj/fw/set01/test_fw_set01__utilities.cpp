////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
//#pragma hdrstop

#include <structure/test_obj/fw/set01/test_fw_set01__utilities.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////

std::string TestFW__GenerateTimeStampString()
{
  std::time_t const timer(std::time(nullptr));

  if(timer==-1)
   throw std::runtime_error("An unexpected problem - time returned -1.");

  struct tm t={0};

  if(LCPI_GCRT_localtime_s(&t,&timer)!=0)
   throw std::runtime_error("An unexpected problem with localtime.");

  std::stringstream oss;

  oss<<std::setfill('0')<<std::setw(4)<<(t.tm_year+1900)
     <<std::setfill('0')<<std::setw(2)<<(t.tm_mon+1)
     <<std::setfill('0')<<std::setw(2)<<(t.tm_mday)<<'_' 
     <<std::setfill('0')<<std::setw(2)<<(t.tm_hour)
     <<std::setfill('0')<<std::setw(2)<<(t.tm_min)
     <<std::setfill('0')<<std::setw(2)<<(t.tm_sec);

 return oss.str();
}//TestFW__GenerateTimeStampString

////////////////////////////////////////////////////////////////////////////////

std::string TestFW__MemSizeToStr(std::uint64_t sz)
{
 using mem_size_type=std::uint64_t;

 if(sz==0)
  return "0 Bytes";

 const mem_size_type c_kb=1024;
 const mem_size_type c_mb=c_kb*1024;
 const mem_size_type c_gb=c_mb*1024;

 const mem_size_type gb=sz/c_gb;

 sz-=gb*c_gb;

 const mem_size_type mb=sz/c_mb;

 sz-=mb*c_mb;

 const mem_size_type kb=sz/c_kb;

 sz-=kb*c_kb;

 //-----------------------------------------
 std::ostringstream os;

 if(gb)
  os<<gb<<"GB ";

 if(mb)
  os<<mb<<"MB ";

 if(kb)
  os<<kb<<"KB ";

 if(sz)
  os<<sz<<" Bytes";

 std::string s(os.str());

 return structure::trimr(s);
}//TestFW__MemSizeToStr

//------------------------------------------------------------------------
std::string TestFW__MemSizeToStrEx_KB(std::uint64_t const sz)
{
 std::ostringstream os1;

 os1<<(sz/1024)<<" KB";

 std::ostringstream os2;

 os2<<std::setw(14)<<std::left<<os1.str()<<" ["<<TestFW__MemSizeToStr(sz)<<"]";

 return os2.str();
}//TestFW__MemSizeToStrEx_KB

//------------------------------------------------------------------------
std::string TestFW__MemSizeToStrEx2_KB(bool const ok,std::uint64_t const sz)
{
 if(!ok)
  return "???";

 return TestFW__MemSizeToStrEx_KB(sz);
}//TestFW__MemSizeToStrEx2_KB

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
