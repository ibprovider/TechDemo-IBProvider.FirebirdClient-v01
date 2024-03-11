////////////////////////////////////////////////////////////////////////////////
//Test structures. Timers
//                                                 Kovalenko Dmitry. 22.07.2009.
#ifndef _t_tso_timer_H_
#define _t_tso_timer_H_

#include <lcpi/lib/.config.h>
#include <string>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//class t_tso_real_timer

class t_tso_real_timer LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_tso_real_timer;
  
  t_tso_real_timer(const self_type&)=delete;
  self_type& operator = (self_type&)=delete;
 
 public: //typedefs ------------------------------------------------------
  using value_type=__int64;
 
 public:
  t_tso_real_timer();
  
  void start();
  
  void stop();
  
  value_type value()const;
  
  std::string as_str()const;
  
 public:
  static std::string as_str(value_type t); 
  
 private:
  static value_type filetime_to_quad(const FILETIME& filetime);
  
 private:
  value_type m_filetime;
};//class t_tso_real_timer

////////////////////////////////////////////////////////////////////////////////
}/*nms tso_obj*/}/*nms structure*/
#endif
