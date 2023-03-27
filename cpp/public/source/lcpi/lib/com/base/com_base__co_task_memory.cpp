////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 16.12.2022.
#include <_pch_.h>
#pragma hdrstop

#include <lcpi/lib/com/base/com_base__co_task_memory.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////

void* OLE_CoTaskMemAlloc(SIZE_T const sz,bool const alloc_empty)
{
 if(sz==0)
 {
  if(!alloc_empty)
   return nullptr;
 }//if

 if(void* const pv=LCPI_OS__CoTaskMemAlloc(sz))
 {
  CHECK_READ_WRITE_PTR(pv,sz);

  memset(pv,0,sz);

  return pv;
 }//if

 throw std::bad_alloc();
}//OLE_CoTaskMemAlloc

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
