////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <win32lib/win32_library.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//class TLibrary

bool TLibrary::Free()
{
 if(m_hInstance!=NULL)
 {
  if(!::FreeLibrary(m_hInstance))
  {
   assert_msg(false,"Fail free library hInst=0x"<<std::hex<<m_hInstance);

   return false;
  }//if

  m_hInstance=NULL;   
 }//if

 return true;
}//Free

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
