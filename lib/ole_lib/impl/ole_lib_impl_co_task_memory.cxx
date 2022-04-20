////////////////////////////////////////////////////////////////////////////////
//OLE Library Implementation. Wrappers for CoTask Memory Allocation Functions
//                                             Kovalenko Dmitry. 22.02.2010.

////////////////////////////////////////////////////////////////////////////////

void* OLE_CoTaskMemAlloc(SIZE_T const sz,bool const alloc_empty)
{
 if(sz==0)
 {
  if(!alloc_empty)
   return nullptr;
 }//if

 if(void* const pv=::CoTaskMemAlloc(sz))
 {
  CHECK_READ_WRITE_PTR(pv,sz);

  memset(pv,0,sz);

  return pv;
 }//if

 throw std::bad_alloc();
}//OLE_CoTaskMemAlloc

//------------------------------------------------------------------------
void OLE_CoTaskMemFree(void* const pv)
{
 return ::CoTaskMemFree(pv);
}//OLE_CoTaskMemFree

////////////////////////////////////////////////////////////////////////////////
