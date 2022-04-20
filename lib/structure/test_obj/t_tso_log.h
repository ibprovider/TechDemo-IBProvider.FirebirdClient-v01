////////////////////////////////////////////////////////////////////////////////
//logger of test messages
//                                                Dmitry Kovalenko.  29.01.2005
#ifndef _t_tso_log_H_
#define _t_tso_log_H_

#include <structure/t_handle.h>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//containings

class t_simple_log;
class t_log_stream;

//forward declarations
class t_message;

////////////////////////////////////////////////////////////////////////////////
//class t_simple_log

class t_simple_log:public t_smart_interface
{
 private:
  typedef t_simple_log                      self_type;

 public: //typedefs ------------------------------------------------------
  typedef t_smart_object_ptr<self_type>     self_ptr;

  typedef t_message                         message_type;

 public: //interface -----------------------------------------------------
  virtual void trace(message_type* msg)=0;
};//class t_simple_log

////////////////////////////////////////////////////////////////////////////////
//class t_log_stream

class t_log_stream:public t_smart_interface
{
 private:
  typedef t_log_stream                      self_type;

 public: //typedefs ------------------------------------------------------
  typedef t_smart_object_ptr<self_type>     self_ptr;

  typedef wchar_t                           char_type;

 public: //interface -----------------------------------------------------
  virtual void out(const char_type* s)=0;
};//class t_log_stream

typedef t_log_stream::self_ptr              t_log_stream_ptr;

////////////////////////////////////////////////////////////////////////////////
}/*nms tso_obj*/}/*nms structure*/
#endif
