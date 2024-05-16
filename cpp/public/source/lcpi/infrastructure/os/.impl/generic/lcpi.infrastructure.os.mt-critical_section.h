////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Critical Section.
//                                                 Kovalenko Dmitry. 18.03.2024.
#ifndef _lcpi_infrastructure_os_mt_impl_generic__critical_section_H_
#define _lcpi_infrastructure_os_mt_impl_generic__critical_section_H_

#include <lcpi/.config.h>

#include <mutex>

namespace lcpi{namespace infrastructure{namespace os{namespace mt{
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
  }

 ~LCPI_OS__CriticalSection()
  {
  }

  //interface ------------------------------------------------------------
  void lock()
  {
   m_cs.lock();
  }//lock

  bool try_lock()
  {
   return m_cs.try_lock();
  }

  void unlock()
  {
   m_cs.unlock();
  }//unlock

 private:
  ::std::recursive_mutex m_cs;
};//class LCPI_OS__CriticalSection

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
