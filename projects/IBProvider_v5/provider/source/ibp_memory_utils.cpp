////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_memory_utils.cpp
//! \brief   Utilities for work with memory.
//! \author  Kovalenko Dmitry
//! \date    18.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_memory_utils.h"

#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class IBP_Memory_Utils

size_t IBP_Memory_Utils::AddMemLength
                             (size_t        cbMem,
                              size_t  const cbElement,
                              size_t  const cbAlign,
                              size_t* const pcbResultAlign)
{
 cbMem=self_type::AlignMemLength(cbMem,cbAlign,pcbResultAlign); //throw

 return self_type::AddMemLength(cbMem,cbElement); //throw
}//AddMemLength

//------------------------------------------------------------------------
size_t IBP_Memory_Utils::AddMemLength
                             (size_t       cbMem,
                              size_t const cbElement)
{
 const wchar_t* const c_bugcheck_src
  =L"IBP_Memory_Utils::AddMemLength";

 if((structure::t_numeric_limits<size_t>::max_value()-cbMem)<cbElement)
  IBP_ThrowOverflowInMemSizeCalculation(c_bugcheck_src,L"#001");

 return cbMem+cbElement;
}//AddMemLength

//------------------------------------------------------------------------
size_t IBP_Memory_Utils::AlignMemLength
                             (size_t        cbMem,
                              size_t  const cbAlign,
                              size_t* const pcbResultAlign)
{
 assert(cbAlign==1 ||
        cbAlign==2 ||
        cbAlign==4 ||
        cbAlign==8 ||
        cbAlign==16);

 const wchar_t* const c_bugcheck_src
  =L"IBP_Memory_Utils::AlignMemLength";

 if(!structure::align_memory_size(/*ref*/cbMem,cbAlign))
  IBP_ThrowOverflowInMemSizeCalculation(c_bugcheck_src,L"#001");

 if(pcbResultAlign!=nullptr)
 {
  if((*pcbResultAlign)<cbAlign)
   (*pcbResultAlign)=cbAlign;
 }//if

 return cbMem;
}//Helper__AlignMemLength

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
