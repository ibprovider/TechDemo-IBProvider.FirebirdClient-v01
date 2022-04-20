////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_debug
//! \file    ibp_debug.cpp
//! \brief   Конструкции для отладки провайдера
//! \author  Kovalenko Dmitry
//! \date    12.11.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_debug.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& os,const t_ibp_debug__file_and_line& x)
{
 const char* file=x.m_file+(x.m_file?strlen(x.m_file):0);

 for(;x.m_file!=file;--file)
 {
  const char c=*(file-1);

  if(c=='\\' || c=='/')
   break;
 }//if

 if(file==NULL || (*file)==0)
 {
  os<<"#UNK_FILE";
 }
 else
 {
  os<<file;
 }//else

 return os<<":"<<x.m_line;
}//operator <<

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/

