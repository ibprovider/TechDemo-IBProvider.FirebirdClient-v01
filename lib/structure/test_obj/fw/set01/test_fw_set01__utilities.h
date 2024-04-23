////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__utilities_H_
#define _test_fw_set01__utilities_H_

#include <structure/test_obj/t_tso_lib.h>
#include <structure/error/t_err_records.h>

#include <structure/utilities/string/trim.h>

#include <chrono>
#include <sstream>
#include <iomanip>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////

std::string TestFW__GenerateTimeStampString();

//------------------------------------------------------------------------
template<typename charT>
LCPI_STL_DEF_BASIC_STRING(charT)
 TestFW__BuildFilePath(const LCPI_STL_DEF_BASIC_STRING(charT)& Path,
                       const LCPI_STL_DEF_BASIC_STRING(charT)& FileName);

//------------------------------------------------------------------------
template<class REP,class PERIOD>
std::string TestFW__TimeToStr(std::chrono::duration<REP,PERIOD> t)
{
 using seconds_t = std::chrono::seconds;

 const auto t2=std::chrono::duration_cast<seconds_t>(t);

 const std::int64_t c_sec  =1;
 const std::int64_t c_min  =c_sec*60;
 const std::int64_t c_hour =c_min*60;
 const std::int64_t c_day  =c_hour*24;

 //---
 auto t3=t2.count();

 const std::int64_t day=(t3/c_day);

 t3-=(day*c_day);

 //---
 const std::int64_t hour=(t3/c_hour);

 t3-=(hour*c_hour);

 //---
 const std::int64_t min=(t3/c_min);

 t3-=(min*c_min);

 //---
 const std::int64_t sec=(t3/c_sec);

 t3-=(sec*c_sec);

 assert(t3==0);

 //---
 const auto f=t-t2;

 assert(f<seconds_t(1));
 assert(f>=seconds_t(0));

 //---
 using tick2_t=std::ratio<1,10*1000*1000>; //10 microseconds

 using fraction2_t=std::chrono::duration<std::int64_t,tick2_t>;

 const auto f2=std::chrono::duration_cast<fraction2_t>(f);

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

 if(f2.count()!=0)
 {
  os<<"."<<std::right<<std::setw(7)<<f2.count();
 }

 return os.str();
}//TestFW__TimeToStr

//------------------------------------------------------------------------
template<class REP,class PERIOD>
std::string TestFW__TimeToStrEx(std::chrono::duration<REP,PERIOD> t)
{
 std::ostringstream os;

 os<<std::setw(13)<<std::left<<t.count()<<" ["<<TestFW__TimeToStr(t)<<"]";

 return os.str();
}//TestFW__TimeToStrEx

//------------------------------------------------------------------------
std::string TestFW__MemSizeToStrEx_KB(std::uint64_t sz);

//------------------------------------------------------------------------
std::string TestFW__MemSizeToStrEx2_KB(bool ok,std::uint64_t sz);

////////////////////////////////////////////////////////////////////////////////

template<class TTracer>
void TestFW__PrintException(TTracer&              tracer,
                            const std::exception& exc);

////////////////////////////////////////////////////////////////////////////////

template<typename charT>
LCPI_STL_DEF_BASIC_STRING(charT)
 TestFW__BuildFilePath(const LCPI_STL_DEF_BASIC_STRING(charT)& Path,
                       const LCPI_STL_DEF_BASIC_STRING(charT)& FileName)
{
 LCPI_STL_DEF_BASIC_STRING(charT) x;

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
   x+=charT('\\');
   break;
 }//switch

 return x.append(FileName);
}//TestFW__BuildFilePath

////////////////////////////////////////////////////////////////////////////////

template<class TTracer>
void TestFW__PrintException(TTracer&              tracer,
                            const std::exception& exc)
{
 if(const structure::t_err_records_r* const errs=dynamic_cast<const structure::t_err_records_r*>(&exc))
 {
  structure::t_err_record::string_type err_source;
  structure::t_err_record::string_type err_descr;

  using lcid_type=structure::t_err_record::lcid_type;

  structure::t_err_record::lcid_type lcid=lcid_type(); // was: GetUserDefaultLCID();

  for(size_t i(0),_c(errs->get_record_count());i!=_c;++i)
  {
   const structure::t_err_record::self_ptr err(errs->get_record(i));

   err->get_description(lcid,&err_source,&err_descr);

   tracer<<(i+1)<<L". ["<<err_source<<L"] "<<err_descr<<tso_obj::send;
  }//for
 }//if
 else
 {
  tracer<<exc.what()<<tso_obj::send;
 }//else
}//TestFW__PrintException

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
