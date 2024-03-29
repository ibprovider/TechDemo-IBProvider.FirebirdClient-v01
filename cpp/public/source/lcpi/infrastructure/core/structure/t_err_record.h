////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 17.07.2019.
#ifndef _lcpi_infrastructure_core_structure__t_err_record_H_
#define _lcpi_infrastructure_core_structure__t_err_record_H_

#include <lcpi/infrastructure/core/structure/t_smart_interface.h>
#include <lcpi/infrastructure/core/structure/t_smart_object_ptr.h>
#include <lcpi/infrastructure/core/structure/t_lcid.h>

#include <string>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_err_record

class LCPI_INFRASTRUCTURE_CORE__CFG__IFACE_STG LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_err_record
 :public t_smart_interface
{
 private:
  using self_type=t_err_record;

 public: //typedefs ------------------------------------------------------
  using self_ptr           =t_smart_object_ptr<self_type>;
  using self_cptr          =t_smart_object_ptr<const self_type>;

  using error_code_type    =std::int32_t;
  using string_type        =std::wstring;
  using subsystem_id_type  =std::int32_t;
  using lcid_type          =t_lcid;
  using help_ctx_id_type   =std::int32_t;

  enum system_id_type
  {
   system_user    =0,

   //Error from WIN32 System
   system_win32   =1,

   //Error from Component Objects services
   system_com     =2,

   //first free index
   system_free    =0x00010000,
  };//enum system_id_type

  enum
  {
   user_subsystem_unk =0,

   //user subsystems [1...0xFFFF] reserved for this library
   user_subsystem_free=0x00010000
  };//enum

 public: //error_record interface -----------------------------------------

  //return simple string with error description -----------
  virtual const char*        what()const throw()=0;

  //extended error informations ---------------------------
  virtual system_id_type     get_system_id()    const=0;

  virtual subsystem_id_type  get_subsystem_id() const=0;

  virtual error_code_type    get_error_code()   const=0;

  virtual bool get_description(lcid_type       lcid,
                               string_type*    source,
                               string_type*    description)const=0;

  virtual bool get_help_info(lcid_type         lcid,
                             string_type*      help_file,
                             help_ctx_id_type* help_context_id)const=0;
};//class t_err_record

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
