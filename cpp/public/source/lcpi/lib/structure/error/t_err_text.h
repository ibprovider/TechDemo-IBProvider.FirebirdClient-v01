////////////////////////////////////////////////////////////////////////////////
//Instrumental library for C++.
//                                                Dmitry Kovalenko. 26.10.2022.
#ifndef _lcpi_infrastructure_core_structure__t_err_text_H_
#define _lcpi_infrastructure_core_structure__t_err_text_H_

#include <lcpi/lib/structure/t_smart_interface.h>
#include <lcpi/lib/structure/t_smart_object_ptr.h>
#include <lcpi/lib/structure/t_lcid.h>

#include <string>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_err_record

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_err_text:public t_smart_interface
{
 private:
  using self_type=t_err_text;

 public: //typedefs -------------------------------------------------------
  using self_ptr    =t_smart_object_ptr<self_type>;
  using self_cptr   =t_smart_object_ptr<const self_type>;

  using string_type =std::wstring;
  using lcid_type   =t_lcid;

 public: //error_record interface -----------------------------------------

  virtual bool get_text(lcid_type       lcid,
                        string_type*    text)const=0;
};//class t_err_text

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
