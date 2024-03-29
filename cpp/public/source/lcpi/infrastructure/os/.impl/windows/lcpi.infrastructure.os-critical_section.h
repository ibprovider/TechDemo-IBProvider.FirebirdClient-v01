////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Critical Section.
//                                                 Kovalenko Dmitry. 18.03.2024.
#ifndef _lcpi_infrastructure_os_impl_windows__critical_section_H_
#define _lcpi_infrastructure_os_impl_windows__critical_section_H_

#include <lcpi/.config.h>

#include <Windows.h>

namespace lcpi{namespace infrastructure{namespace os{
////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__CriticalSection

class LCPI_OS__CriticalSection LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=LCPI_OS__CriticalSection;

  LCPI_OS__CriticalSection(const self_type&);
  self_type& operator = (const self_type&);

 public:
  LCPI_OS__CriticalSection()
  {
   ::InitializeCriticalSection(&m_cs);
  }

 ~LCPI_OS__CriticalSection()
  {
   ::DeleteCriticalSection(&m_cs);
  }

  //interface ------------------------------------------------------------
  void lock()
  {
   ::EnterCriticalSection(&m_cs);
  }//lock

  bool try_lock()
  {
   LCPI__assert_s(FALSE==0);

   return ::TryEnterCriticalSection(&m_cs)!=FALSE;
  }

  void unlock()
  {
  ::LeaveCriticalSection(&m_cs);
  }//unlock

 private:
  CRITICAL_SECTION m_cs;
};//class LCPI_OS__CriticalSection

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
#endif