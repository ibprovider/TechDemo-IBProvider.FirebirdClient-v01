////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descr_data__index_by_name.cpp
//! \brief   Конструкции для индексирования описаний свойств по имени
//! \author  Kovalenko Dmitry
//! \date    31.01.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data__index_by_name.h"
#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data.h"

#include <structure/t_latin_lower.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__DescrData_IndexByName_Item

#ifndef NDEBUG

void IBP_OLEDB_Props2__DescrData_IndexByName_Item::DEBUG_Check_Range
                                           (const self_type* const pFirst,
                                            const self_type* const pLast)
{
 IBP_OLEDB_Props2__DescrData_IndexByName_Less op;

 for(auto x=pFirst,prevX=x,_e=pLast;x!=_e;prevX=x,++x)
 {
  assert((*x).pName);
  assert(*(*x).pName);
  assert((*x).pDescr);
  assert((*x).DEBUG__pName);

  assert(wcscmp((*x).pName,(*x).DEBUG__pName)==0);

  //assert(!op(*x,*x));
  assert(!op(*x,(*x).pName));
  assert(!op((*x).pName,*x));

  if(x==pFirst)
   continue;

  assert(prevX<x);

  //assert(!op(*x,*prevX));
  assert(!op(*x,(*prevX).pName));
  assert(!op((*x).pName,*prevX));

  //assert(op(*prevX,*x));
  assert(op(*prevX,(*x).pName));
  assert(op((*prevX).pName,*x));
 }//for x
}//DEBUG_Check_Range

#endif

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__DescrData_IndexByName_Less

bool IBP_OLEDB_Props2__DescrData_IndexByName_Less::operator ()
                                           (const IBP_OLEDB_Props2__DescrData_IndexByName_Item& x,
                                            const wstr_box_type&                                name)const
{
 assert(x.pName);

 auto       p1=x.pName;

 auto       p2=name.begin();
 auto const e2=name.end();

 for(;;++p1,++p2)
 {
  auto const ch1=*p1;

  if(ch1==0)
  {
   if(p2==e2)
    return false;

   return true;
  }//if

  assert_hint(ch1!=0);

  if(p2==e2)
  {
   return false;
  }//if

  assert_hint(p2!=e2);

  auto const lower_ch1=structure::latin_lower(ch1);
  auto const lower_ch2=structure::latin_lower(*p2);

  if(lower_ch1<lower_ch2)
   return true;

  if(lower_ch2<lower_ch1)
   return false;

  assert(lower_ch1==lower_ch2);
 }//for[ever]
}//operator x<name

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__DescrData_IndexByName_Less::operator ()
                                           (const wstr_box_type&                                name,
                                            const IBP_OLEDB_Props2__DescrData_IndexByName_Item& x)const
{
 assert(x.pName);

 auto       p1=name.begin();
 auto const e1=name.end();

 auto       p2=x.pName;

 for(;;++p1,++p2)
 {
  auto const ch2=*p2;

  if(p1==e1)
  {
   if(ch2==0)
    return false;

   return true;
  }//if

  assert_hint(p1!=e1);

  if(ch2==0)
  {
   return false;
  }//if

  assert_hint(ch2!=0);

  auto const lower_ch1=structure::latin_lower(*p1);
  auto const lower_ch2=structure::latin_lower(ch2);

  if(lower_ch1<lower_ch2)
   return true;

  if(lower_ch2<lower_ch1)
   return false;

  assert(lower_ch1==lower_ch2);
 }//for[ever]
}//operator name<x

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
