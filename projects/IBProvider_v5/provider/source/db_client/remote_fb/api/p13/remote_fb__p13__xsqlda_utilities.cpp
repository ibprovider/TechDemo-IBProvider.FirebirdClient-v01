////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__xsqlda_utilities.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__xsqlda_utilities.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__XSQLDA_Utilities

size_t RemoteFB__P13__XSQLDA_Utilities::Helper__AddMsgLength
                                           (size_t        cbMsg,
                                            size_t  const cbElement,
                                            size_t  const cbAlign,
                                            size_t* const pcbResultAlign)
{
 cbMsg=Helper__AlignMsgLength(cbMsg,cbAlign,pcbResultAlign); //throw

 return Helper__AddMsgLength(cbMsg,cbElement); //throw
}//Helper__AddMsgLength

//------------------------------------------------------------------------
size_t RemoteFB__P13__XSQLDA_Utilities::Helper__AddMsgLength
                                           (size_t       cbMsg,
                                            size_t const cbElement)
{
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__P13__XSQLDA_Utilities::Helper__AddMsgLength";

 if((structure::t_numeric_limits<size_t>::max_value()-cbMsg)<cbElement)
  IBP_ThrowOverflowInMemSizeCalculation(c_bugcheck_src,L"#001");

 return cbMsg+cbElement;
}//Helper__AddMsgLength

//------------------------------------------------------------------------
size_t RemoteFB__P13__XSQLDA_Utilities::Helper__AlignMsgLength
                                           (size_t        cbMsg,
                                            size_t  const cbAlign,
                                            size_t* const pcbResultAlign)
{
 assert(cbAlign==1 ||
        cbAlign==2 ||
        cbAlign==4 ||
        cbAlign==8 ||
        cbAlign==16);

 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__P13__XSQLDA_Utilities::Helper__AlignMsgLength";

 if(!structure::align_memory_size(/*ref*/cbMsg,cbAlign))
  IBP_ThrowOverflowInMemSizeCalculation(c_bugcheck_src,L"#001");

 if(pcbResultAlign!=nullptr)
 {
  if((*pcbResultAlign)<cbAlign)
   (*pcbResultAlign)=cbAlign;
 }//if

 return cbMsg;
}//Helper__AlignMsgLength

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
