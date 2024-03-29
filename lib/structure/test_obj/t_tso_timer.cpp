////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <structure/test_obj/t_tso_timer.h>
#include <win32lib/win32_time.h>
#include <sstream>
#include <iomanip>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//class t_tso_real_timer

t_tso_real_timer::t_tso_real_timer()
{
 this->start();
}//t_tso_real_timer

//------------------------------------------------------------------------
void t_tso_real_timer::start()
{
 FILETIME cur_filetime;
 
 ::GetSystemTimeAsFileTime(&cur_filetime);

 m_filetime=self_type::filetime_to_quad(cur_filetime);
}//start

//------------------------------------------------------------------------
void t_tso_real_timer::stop()
{
 FILETIME cur_filetime;
 
 ::GetSystemTimeAsFileTime(&cur_filetime);
 
 m_filetime=self_type::filetime_to_quad(cur_filetime)-m_filetime; 
}//stop

//------------------------------------------------------------------------
t_tso_real_timer::value_type t_tso_real_timer::value()const
{
 return m_filetime;
}//value

//------------------------------------------------------------------------
std::string t_tso_real_timer::as_str()const
{
 return self_type::as_str(m_filetime);
}//as_str

//------------------------------------------------------------------------
std::string t_tso_real_timer::as_str(value_type t)
{
 const std::int64_t c_sec  =1000*1000*10;
 const std::int64_t c_min  =c_sec*60;
 const std::int64_t c_hour =c_min*60;
 const std::int64_t c_day  =c_hour*24;
 
 //---
 std::int64_t day=t/c_day;
 
 t-=day*c_day;
 
 //---
 std::int64_t hour=t/c_hour;
 
 t-=hour*c_hour;

 //---
 std::int64_t min=t/c_min;
 
 t-=min*c_min;

 //---
 std::int64_t sec=t/c_sec;
 
 t-=sec*c_sec;
 
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
}//as_str - static

//------------------------------------------------------------------------
t_tso_real_timer::value_type t_tso_real_timer::filetime_to_quad(const FILETIME& filetime)
{
 return win32lib::FileTimeToQuad(filetime);
}//filetime_to_quad

////////////////////////////////////////////////////////////////////////////////
}/*nms tso_obj*/}/*nms structure*/
