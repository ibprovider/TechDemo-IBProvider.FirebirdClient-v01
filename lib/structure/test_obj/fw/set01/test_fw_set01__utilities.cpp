////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <structure/test_obj/fw/set01/test_fw_set01__utilities.h>
#include <sstream>
#include <iomanip>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////

std::string TestFW__GenerateTimeStampString()
{
 SYSTEMTIME systime;

 ::GetLocalTime(&systime);

 std::stringstream oss;

 oss<<std::setfill('0')<<std::setw(4)<<systime.wYear
    <<std::setfill('0')<<std::setw(2)<<systime.wMonth
    <<std::setfill('0')<<std::setw(2)<<systime.wDay
    <<"_"
    <<std::setfill('0')<<std::setw(2)<<systime.wHour
    <<std::setfill('0')<<std::setw(2)<<systime.wMinute
    <<std::setfill('0')<<std::setw(2)<<systime.wSecond;

 return oss.str();
}//TestFW__GenerateTimeStampString

////////////////////////////////////////////////////////////////////////////////

std::string TestFW__TimeToStr(std::int64_t t)
{
 const std::int64_t c_sec  =1000*1000*10;
 const std::int64_t c_min  =c_sec*60;
 const std::int64_t c_hour =c_min*60;
 const std::int64_t c_day  =c_hour*24;

 //---
 std::int64_t day=(t/c_day);

 t-=(day*c_day);

 //---
 std::int64_t hour=(t/c_hour);

 t-=(hour*c_hour);

 //---
 std::int64_t min=(t/c_min);

 t-=(min*c_min);

 //---
 std::int64_t sec=(t/c_sec);

 t-=(sec*c_sec);

 //---
 std::ostringstream os;

 if(day)
 {
  os<<day<<" day(s)";
 }

 os.fill('0');

 os<<std::setw(2)<<hour<<':'
   <<std::setw(2)<<min<<':'
   <<std::setw(2)<<sec;

 if(t)
 {
  os<<"."<<std::right<<std::setw(7)<<t;
 }

 return os.str();
}//TestFW__TimeToStr

//------------------------------------------------------------------------
std::string TestFW__TimeToStrEx(std::int64_t t)
{
 std::ostringstream os;

 os<<std::setw(13)<<std::left<<t<<" ["<<TestFW__TimeToStr(t)<<"]";

 return os.str();
}//TestFW__TimeToStrEx

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
