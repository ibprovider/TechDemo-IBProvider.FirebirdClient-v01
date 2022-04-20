////////////////////////////////////////////////////////////////////////////////
//WIN32 HANDLE Wrapper
//                                               Dmitry Kovalenko. 12.04.2004.
#ifndef _win32_handle_H_
#define _win32_handle_H_

#include <win32lib/win32_base.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//class THandleWin32 - base class for WIN32 HANDLE

class THandleWin32
{
 private:
  typedef THandleWin32                      self_type;

  THandleWin32(const self_type&);
  self_type& operator = (const self_type&);

 public:
  HANDLE handle;

  THandleWin32()
   :handle(NULL)
  {;}

  virtual ~THandleWin32()
   {
    _VERIFY(this->Close());
   }

  operator HANDLE () const
   {
    return this->handle;
   }

  virtual BOOL Close()
   {
    const HANDLE tmp_handle(this->handle);

    this->handle=NULL;

    const BOOL bResult=(tmp_handle?::CloseHandle(tmp_handle):TRUE);

    return bResult;
   }//Close
};//class THandleWin32

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
