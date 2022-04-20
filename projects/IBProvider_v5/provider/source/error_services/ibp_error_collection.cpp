////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_collection.cpp
//! \brief   Класс для создания коллекции ошибок
//! \author  Kovalenko Dmitry
//! \date    18.02.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error_collection.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_collection

t_ibp_error_collection::t_ibp_error_collection()
{;}

//------------------------------------------------------------------------
t_ibp_error_collection::~t_ibp_error_collection()
{;}

//t_err_records_r interface ----------------------------------------------
size_t t_ibp_error_collection::get_record_count()const
{
 return m_items.size();
}//get_record_count

//------------------------------------------------------------------------
structure::t_err_record::self_ptr t_ibp_error_collection::get_record(size_t const record_num)const
{
 assert(record_num<m_items.size());

 return m_items[record_num];
}//get_record

//t_ibp_error_records_r interface ----------------------------------------
t_ibp_error_collection::size_type_N t_ibp_error_collection::get_primary_err_idx()const
{
 return m_primary_err_idx;
}//get_primary_err_idx

//t_ibp_error_adapter interface ------------------------------------------
void t_ibp_error_collection::push_error(base_error_record_type* const pError)
{
 assert(pError);

 return m_items.push_back(pError);
}//push_error

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
