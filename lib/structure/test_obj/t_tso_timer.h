////////////////////////////////////////////////////////////////////////////////
//Test structures. Timers
//                                                 Kovalenko Dmitry. 22.07.2009.
#ifndef _t_tso_timer_H_
#define _t_tso_timer_H_

#include <structure/t_common.h>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//class t_tso_real_timer

class t_tso_real_timer
{
 private:
  typedef t_tso_real_timer                  self_type;
  
  t_tso_real_timer(const self_type&);
  self_type& operator = (self_type&);
 
 public: //typedefs ------------------------------------------------------
  typedef __int64                           value_type;
 
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
