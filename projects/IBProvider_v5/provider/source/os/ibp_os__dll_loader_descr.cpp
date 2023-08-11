////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dll_loader_descr.cpp
//! \brief   The descriptor with DLL Loader data
//! \author  Kovalenko Dmitry
//! \date    26.06.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/os/ibp_os__dll_loader_descr.h"

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os__dll_loader_descr_less_operator

bool t_ibp_os__dll_loader_descr_less_operator::operator ()
                             (const t_ibp_os__dll* const p1,
                              const t_ibp_os__dll* const p2)const
{
 assert(p1);
 assert(p2);

 return p1->get_dll_handle()<p2->get_dll_handle();
}//operator p1<p2

//----------------------------------------------------------------------
bool t_ibp_os__dll_loader_descr_less_operator::operator ()
                             (const t_ibp_os__dll_loader_descr& d1,
                              const t_ibp_os__dll*        const p2)const
{
 assert(d1.GetDllLoader());
 assert(p2);

 return d1.GetDllLoader()->get_dll_handle()<p2->get_dll_handle();
}//operator d1<p2

//----------------------------------------------------------------------
bool t_ibp_os__dll_loader_descr_less_operator::operator ()
                             (const t_ibp_os__dll*        const p1,
                              const t_ibp_os__dll_loader_descr& d2)const
{
 assert(p1);
 assert(d2.GetDllLoader());

 return p1->get_dll_handle()<d2.GetDllLoader()->get_dll_handle();
}//operator p1<d2

//----------------------------------------------------------------------
bool t_ibp_os__dll_loader_descr_less_operator::operator ()
                             (const t_ibp_os__dll_loader_descr& d1,
                              const t_ibp_os__dll_loader_descr& d2)const
{
 assert(d1.GetDllLoader());
 assert(d2.GetDllLoader());

 return d1.GetDllLoader()->get_dll_handle()<d2.GetDllLoader()->get_dll_handle();
}//operator d1<d2

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
