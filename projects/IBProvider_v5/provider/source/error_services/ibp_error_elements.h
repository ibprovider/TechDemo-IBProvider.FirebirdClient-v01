////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_elements.h
//! \brief    онтейнер дл€ хранени€ описани€ ошибок
//! \author  Kovalenko Dmitry
//! \date    12.04.2018
#ifndef _ibp_error_elements_H_
#define _ibp_error_elements_H_

#include "source/error_services/ibp_error_element.h"
#include <structure/stl/t_stl_vector.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_elements

/// <summary>
///   онтейнер дл€ хранени€ описани€ ошибок
/// </summary>
class t_ibp_error_elements COMP_W000006_CLASS_FINAL
{
 private:
  typedef t_ibp_error_elements              self_type;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_err_record           error_record_type;
  typedef error_record_type::self_ptr       error_record_ptr;

 public:
  t_ibp_error_elements();

  t_ibp_error_elements(const self_type& x);

  t_ibp_error_elements(self_type&& x);

 ~t_ibp_error_elements();

  self_type& operator = (const self_type& x);

  self_type& operator = (self_type&& x);

  //interface ------------------------------------------------------------
  size_t size()const;

  bool empty()const;

  const error_record_ptr& back()const;

  const error_record_ptr& operator [] (size_t index)const;

  void push_back(error_record_type* error_record);

  void add_limit_event();

  //----------------------------------------------------------------------
  void swap(self_type& x);

 private:
  typedef structure::t_stl_vector
           <error_record_ptr,
            IBP_MemoryAllocator>            items_type;

 private:
  items_type m_items;
};//class t_ibp_error_elements

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/

namespace std{
////////////////////////////////////////////////////////////////////////////////

template<>
inline void swap(LCPI_IBP_NMS::t_ibp_error_elements& x1,
                 LCPI_IBP_NMS::t_ibp_error_elements& x2)
{
 return x1.swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std
#endif
