////////////////////////////////////////////////////////////////////////////////
//Wrapper for load-unload DLL/EXE modules
//                                                Dmitry Kovalenko. 08.02.2005.
#ifndef _win32_library_H_
#define _win32_library_H_

#include <win32lib/win32_base.h>
#include <structure/t_str_parameter.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//class

class TLibrary;

////////////////////////////////////////////////////////////////////////////////
//class TLibrary

class TLibrary
{
 private:
  typedef TLibrary                                     self_type;

  TLibrary(const self_type&);
  self_type& operator = (const self_type&);
 
 public: //typedefs ------------------------------------------------------
  typedef structure::t_str_parameter<t_char>           tstr_arg_type;

 public:
  TLibrary();

 ~TLibrary();

  //----------------------------------------------------------------------
  //hFile - reserved (==NULL)
  bool Load2(tstr_arg_type LibFileName,HANDLE hFile,DWORD dwFlags);

  bool Free();

  //selectors ------------------------------------------------------------
  operator HINSTANCE () const {return m_hInstance;}

  FARPROC GetProcAddress(const char* const lpProcName)const;

 private:
  HINSTANCE m_hInstance;
};//class TLibrary

////////////////////////////////////////////////////////////////////////////////
//class TLibrary - inline methods

inline TLibrary::TLibrary()
 :m_hInstance(NULL)
{;}

//------------------------------------------------------------------------
inline TLibrary::~TLibrary()
{
 this->Free();
}//~TLibrary

//------------------------------------------------------------------------
inline bool TLibrary::Load2(tstr_arg_type const LibFileName,
                            HANDLE        const hFile,
                            DWORD         const dwFlags)
{
 _VERIFY(this->Free());

 m_hInstance=::LoadLibraryEx(LibFileName.c_str(),hFile,dwFlags);

 return m_hInstance!=NULL;
}//Load2

//------------------------------------------------------------------------
inline FARPROC TLibrary::GetProcAddress(const char* const lpProcName)const
{
 assert(m_hInstance);
 assert(lpProcName);
 
 return ::GetProcAddress(m_hInstance,lpProcName);
}//GetProcAddress

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
