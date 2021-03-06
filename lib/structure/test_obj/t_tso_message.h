////////////////////////////////////////////////////////////////////////////////
//interface of test message
//                                                Dmitry Kovalenko. 27.01.2005
#ifndef _t_tso_message_H_
#define _t_tso_message_H_

#include <structure/t_smart_interface.h>
#include <structure/t_smart_object_ptr.h>
#include <structure/t_lcid.h>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//containings

class t_message;

////////////////////////////////////////////////////////////////////////////////
//enum t_msg_kind 

enum t_msg_kind
{
 tso_msg_info             =0,
 tso_msg_warning          =1,
 tso_msg_error            =2,
 tso_msg_start_test       =3,
 tso_msg_stop_test        =4,
};//enum msg_kind_type

////////////////////////////////////////////////////////////////////////////////
//class t_message

class t_message:public t_smart_interface
{
 public:
  typedef t_message                             self_type;

 public: //typedefs ------------------------------------------------------
  typedef t_smart_object_ptr<self_type>         self_ptr;

  typedef t_lcid                                lcid_type;
  typedef std::wstring                          string_type;
  typedef long                                  error_code_type;
  typedef t_msg_kind                            msg_kind_type;

 public: //interface -----------------------------------------------------
  virtual error_code_type get_error_code()const=0;

  virtual msg_kind_type get_msg_kind()const=0;

  virtual bool get_description(lcid_type        lcid,
                               string_type*     source,
                               string_type*     description)const=0;

  virtual self_ptr clone()const=0;                         
};//class t_message

typedef t_message::self_ptr t_message_ptr;

////////////////////////////////////////////////////////////////////////////////
}/*nms tso_obj*/}/*nms structure*/
#endif
