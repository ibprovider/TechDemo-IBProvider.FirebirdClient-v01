////////////////////////////////////////////////////////////////////////////////
//logger of test messages
//                                                Dmitry Kovalenko.  29.01.2005
#ifndef _t_tso_log_H_
#define _t_tso_log_H_

#include <structure/t_smart_interface.h>
#include <structure/t_smart_object_ptr.h>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//content

class t_simple_log;
class t_log_stream;

//forward declarations
class t_message;

////////////////////////////////////////////////////////////////////////////////
//class t_simple_log

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_simple_log
 :public t_smart_interface
{
 private:
  using self_type=t_simple_log;

 public: //typedefs ------------------------------------------------------
  using self_ptr
   =t_smart_object_ptr<self_type>;

  using message_type
   =t_message;

 public: //interface -----------------------------------------------------
  virtual void trace(message_type* msg)=0;
};//class t_simple_log

////////////////////////////////////////////////////////////////////////////////
//class t_simple_log

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_log
 :public t_simple_log
{
 public: //interface -----------------------------------------------------
  virtual void inc_child_error_count()=0;

  virtual void inc_child_warning_count()=0;
};//class t_log

////////////////////////////////////////////////////////////////////////////////
//class t_log_stream

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_log_stream
 :public t_smart_interface
{
 private:
  using self_type=t_log_stream;

 public: //typedefs ------------------------------------------------------
  using self_ptr
   =t_smart_object_ptr<self_type>;

  using char_type
   =wchar_t;

 public: //interface -----------------------------------------------------
  virtual void out(const char_type* s)=0;
};//class t_log_stream

using t_log_stream_ptr=t_log_stream::self_ptr;

////////////////////////////////////////////////////////////////////////////////
}/*nms tso_obj*/}/*nms structure*/
#endif
