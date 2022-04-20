////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_utilities.h"
#include <win32lib/win32_error.h>
#include <sstream>
#include <iomanip>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////

std::string TSO_GenerateTimeStampString()
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
}//TSO_GenerateTimeStampString

////////////////////////////////////////////////////////////////////////////////

std::wstring TSO_GenerateNewDatabaseFileName()
{
 GUID guid;

 if(::UuidCreate(&guid)!=RPC_S_OK)
  throw std::runtime_error("Can't generate uuid");

 std::basic_stringstream<wchar_t> oss;

 oss<<L"IBP_TEST_";

 const BYTE* const pb=reinterpret_cast<const BYTE*>(&guid);
 const BYTE* const pe=pb+sizeof(guid);

 for(const BYTE* p=pb;p!=pe;++p)
 {
  oss<<std::setfill(L'0')<<std::setw(2)<<std::hex<<std::uppercase<<long(*p);
 }//for

 oss<<L".GDB";

 return oss.str();
}//IBP_TSO_GenerateNewDatabaseFileName

////////////////////////////////////////////////////////////////////////////////

std::string TSO_BuildFilePath(const std::string& Path,
                              const std::string& FileName)
{
 std::string x;

 x.reserve(Path.size()+FileName.size()+1);

 x+=Path;

 structure::self_trim(x);

 if(x.empty())
  return FileName;

 switch(x.back())
 {
  case '\\':
  case '/':
   break;

  default:
   x+="\\";
   break;
 }//switch

 return x.append(FileName);
}//IBP_TSO_BuildFilePath

////////////////////////////////////////////////////////////////////////////////

void TSO_PrintException(TTSO_Tracer&          tracer,
                        const std::exception& exc)
{
 if(const structure::t_err_records_r* const errs=dynamic_cast<const structure::t_err_records_r*>(&exc))
 {
  structure::t_err_record::string_type err_source;
  structure::t_err_record::string_type err_descr;

  structure::t_err_record::lcid_type lcid(::GetUserDefaultLCID());

  for(size_t i(0),_c(errs->get_record_count());i!=_c;++i)
  {
   const structure::t_err_record::self_ptr err(errs->get_record(i));

   err->get_description(lcid,&err_source,&err_descr);

   tracer<<(i+1)<<L". ["<<err_source<<L"] "<<err_descr<<send;
  }//for
 }//if
 else
 {
  tracer<<exc.what()<<send;
 }
}//TSO_PrintException

////////////////////////////////////////////////////////////////////////////////

std::string TSO_TimeToStr(__int64 t)
{
 const __int64 c_sec  =1000*1000*10;
 const __int64 c_min  =c_sec*60;
 const __int64 c_hour =c_min*60;
 const __int64 c_day  =c_hour*24;

 //---
 __int64 day=(t/c_day);

 t-=(day*c_day);

 //---
 __int64 hour=(t/c_hour);

 t-=(hour*c_hour);

 //---
 __int64 min=(t/c_min);

 t-=(min*c_min);

 //---
 __int64 sec=(t/c_sec);

 t-=(sec*c_sec);

 //---
 std::ostringstream os;

 if(day)
 {
  os<<day<<" day(s)";
 }

 os.fill('0');

 os<<std::setw(2)<<hour<<":"
   <<std::setw(2)<<min<<":"
   <<std::setw(2)<<sec;

 if(t)
 {
  os<<"."<<std::right<<std::setw(7)<<t;
 }

 return os.str();
}//IBP_TSO_TimeToStr

//------------------------------------------------------------------------
std::string TSO_TimeToStrEx(__int64 t)
{
 std::ostringstream os;

 os<<std::setw(13)<<std::left<<t<<" ["<<TSO_TimeToStr(t)<<"]";

 return os.str();
}//IBP_TSO_TimeToStrEx

////////////////////////////////////////////////////////////////////////////////

std::string TSO_MemSizeToStr(unsigned __int64 sz)
{
 typedef unsigned __int64  mem_size_type;

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
}//IBP_TSO_MemSizeToStr

//------------------------------------------------------------------------
std::string TSO_MemSizeToStrEx_KB(unsigned __int64 const sz)
{
 std::ostringstream os1;

 os1<<(sz/1024)<<" KB";

 std::ostringstream os2;

 os2<<std::setw(14)<<std::left<<os1.str()<<" ["<<TSO_MemSizeToStr(sz)<<"]";

 return os2.str();
}//IBP_TSO_MemSizeToStrEx_KB

//------------------------------------------------------------------------
std::string TSO_MemSizeToStrEx2_KB(bool const ok,unsigned __int64 const sz)
{
 if(!ok)
  return "???";

 return TSO_MemSizeToStrEx_KB(sz);
}//IBP_TSO_MemSizeToStrEx2_KB

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
