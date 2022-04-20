////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__array_slice_descr.cpp
//! \brief   Описание буфера со значениями элементов массива.
//! \author  Kovalenko Dmitry
//! \date    28.09.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__array_slice_descr.h"
#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ArraySliceDescr

RemoteFB__ArraySliceDescr::RemoteFB__ArraySliceDescr()
 :m_element_blr_typeid(0)
 ,m_element_sql_scale(0)
 ,m_element_sql_text_props(0)
 ,m_element_sql_length(0)
 ,m_element_total_length(0)
 ,m_bounds_number(0)
{;}

//------------------------------------------------------------------------
RemoteFB__ArraySliceDescr::~RemoteFB__ArraySliceDescr()
{;}

//interface --------------------------------------------------------------
void RemoteFB__ArraySliceDescr::Init()
{
 m_relation_name.clear();

 m_field_name.clear();

 m_element_blr_typeid=0;

 m_element_sql_scale=0;

 m_element_sql_text_props=0;

 m_element_sql_length=0;

 m_element_total_length=0;

 m_bounds_number=0;
}//Init

//------------------------------------------------------------------------
size_t RemoteFB__ArraySliceDescr::GetElementCount()const
{
 assert(m_bounds_number<=_DIM_(m_bounds));

 const size_t c_max=structure::t_numeric_limits<size_t>::max_value();

 size_t n=0;

 for(size_t iDim=0;iDim!=m_bounds_number;++iDim)
 {
  const tag_bound& curBound=m_bounds[iDim];

  assert(curBound.lower<=curBound.upper);

  const range_bound_type len0=curBound.upper-curBound.lower;

  assert(structure::can_numeric_cast<size_t>(len0));

  size_t len1=static_cast<size_t>(len0);

  if(len1==c_max)
  {
   //ERROR - count of elements is too big

   Helper__ThrowErr__CantCalcElementCount();
  }//if

  ++len1;

  if(iDim==0)
  {
   n=len1;

   continue;
  }//if

  //----- контроль переполнения
  const size_t c_max_element_count=c_max/len1;

  if(c_max_element_count<n)
  {
   //ERROR - count of elements is too big

   Helper__ThrowErr__CantCalcElementCount();
  }//if

  //можно безопасно перемножать
  n*=len1;
 }//for iDim

 return n;
}//GetElementCount

//------------------------------------------------------------------------
size_t RemoteFB__ArraySliceDescr::GetMemorySize()const
{
 assert(m_element_total_length>0);

 const size_t nElements=this->GetElementCount();

 const size_t c_max=structure::t_numeric_limits<size_t>::max_value();

 const size_t c_max_element_count=c_max/m_element_total_length;

 if(c_max_element_count<nElements)
 {
  //ERROR - слишком большое количество элементов в массиве.

  t_ibp_error exc(E_FAIL,
                  ibp_subsystem__remote_fb,
                  ibp_mce_array__calc_memory_size__overflow_4);

  exc<<m_relation_name
     <<m_field_name
     <<nElements
     <<m_element_total_length;

  exc.raise_me();
 }//if c_max_element_count<nElements

 return nElements*m_element_total_length;
}//GetMemorySize

//helper methods ---------------------------------------------------------
void RemoteFB__ArraySliceDescr::Helper__ThrowErr__CantCalcElementCount()const
{
 t_ibp_error exc(E_FAIL,
                 ibp_subsystem__remote_fb,
                 ibp_mce_array__calc_total_element_count__overflow_2);

 exc<<m_relation_name<<m_field_name;

 exc.raise_me();
}//Helper__ThrowErr__CantCalcElementCount

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
