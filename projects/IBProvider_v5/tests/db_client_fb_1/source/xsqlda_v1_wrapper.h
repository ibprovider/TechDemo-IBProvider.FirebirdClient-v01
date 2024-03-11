////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. Вспомогательная обертка для isc_api::XSQLDA_V1
//                                                Kovalenko Dmitry. 28.04.2015.
#ifndef _xsqlda_v1_wrapper_H_
#define _xsqlda_v1_wrapper_H_

#include "source/db_obj/isc_base/isc_api.h"
#include "source/test_services.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class XSQLDA_V1_Wrapper

class XSQLDA_V1_Wrapper
{
 private:
  using self_type=XSQLDA_V1_Wrapper;

  XSQLDA_V1_Wrapper(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using pointer=isc_api::XSQLDA_V1*;

 public:
  explicit XSQLDA_V1_Wrapper(size_t n);

 ~XSQLDA_V1_Wrapper();

  //interface ------------------------------------------------------------
  pointer operator -> () const;

  operator pointer () const;

  pointer ptr() const;

  //modificators ---------------------------------------------------------
  void alloc(size_t n);

 private:
  void* m_pv;
};//class XSQLDA_V1_Wrapper

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif