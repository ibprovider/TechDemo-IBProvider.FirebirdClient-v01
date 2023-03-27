////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_debug
//! \file    ibp_debug.h
//! \brief   ����������� ��� ������� ����������
//! \author  Kovalenko Dmitry
//! \date    12.11.2008
#ifndef _ibp_debug_
#define _ibp_debug_

#include <lcpi/lib/structure/mt/t_lock_guard.h>

#include <ostream>
#include <sstream>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_debug
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

struct t_ibp_debug__file_and_line;

#ifndef NDEBUG
class  t_ibp_debug__mt_guard;
//class t_ibp_debug__mt_guard_lock;

class  t_ibp_debug__mt_guard2;
//class t_ibp_debug__mt_guard2_lock;
class  t_ibp_debug__mt_guard2_lock_first;
#endif

////////////////////////////////////////////////////////////////////////////////
//struct t_ibp_debug__file_and_line

struct t_ibp_debug__file_and_line
{
 public:
  const char* m_file;
  long        m_line;

 public:
  t_ibp_debug__file_and_line(const char* file,long line)
   :m_file(file)
   ,m_line(line)
  {;}
};//struct t_ibp_debug__file_and_line

////////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& os,const t_ibp_debug__file_and_line& x);

////////////////////////////////////////////////////////////////////////////////

#define IBP_DEBUG_FILE_AND_LINE                              \
 LCPI_IBP_NMS::t_ibp_debug__file_and_line(__FILE__,__LINE__)

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_debug__mt_guard

#ifndef NDEBUG

/// <summary>
///  ���������� ����� ��� �������� ������������ ������� � ��������
/// </summary>
//! \attention
//!  �� ����������� ��������� ���������� � ������ ������ ������
class t_ibp_debug__mt_guard
{
 private:
  typedef t_ibp_debug__mt_guard    self_type;

  t_ibp_debug__mt_guard(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  t_ibp_debug__mt_guard()
   :m_dwOwnerThreadID(0)
  {}

  /// <summary>
  ///  ����������
  /// </summary>
 ~t_ibp_debug__mt_guard()
  {
   ///��������� ������������ ����������
   assert(m_dwOwnerThreadID==0);
  }//~t_ibp_debug__mt_guard

  /// <summary>
  ///  �������� ���������� ����������
  /// </summary>
  bool is_active()const
  {
   return m_dwOwnerThreadID!=0;
  }//is_active

  /// <summary>
  ///  �������� ������� ���������� ������� �������.
  /// </summary>
  bool current_thread_is_owner()const
  {
   return m_dwOwnerThreadID==::GetCurrentThreadId();
  }//current_thread_is_owner

  /// <summary>
  ///  ������ ���������� �������
  /// </summary>
  void lock()
  {
   const DWORD dwCurrentThreadID=::GetCurrentThreadId();

   const DWORD dwPrevThreadID=::InterlockedCompareExchange(&m_dwOwnerThreadID,dwCurrentThreadID,0);

   assert_msg(dwPrevThreadID==0,
               "dwPrevThreadID="<<dwPrevThreadID<<"\n"
               "dwCurrentThreadID="<<dwCurrentThreadID);
  }//lock

  /// <summary>
  ///  ������������ ���������� �������
  /// </summary>
  void unlock()
  {
   const DWORD dwCurrentThreadID=::GetCurrentThreadId();

   const DWORD dwPrevThreadID=::InterlockedCompareExchange(&m_dwOwnerThreadID,0,dwCurrentThreadID);

   assert_msg(dwPrevThreadID==dwCurrentThreadID,
               "dwPrevThreadID="<<dwPrevThreadID<<"\n"
               "dwCurrentThreadID="<<dwCurrentThreadID);
  }//unlock

 private:
  ///������������� ��������� ����������
  DWORD m_dwOwnerThreadID;
};//class t_ibp_debug__mt_guard

#endif // ndef NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_debug__mt_guard_lock

#ifndef NDEBUG

/// <summary>
///  ���������� ����� ��� ������������� ������ � t_ibp_debug__mt_guard
/// <summary>
using t_ibp_debug__mt_guard_lock
 =lcpi::lib::structure::mt::t_lock_guard<t_ibp_debug__mt_guard>;

#endif // ndef NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_debug__mt_guard2

#ifndef NDEBUG

/// <summary>
///  ���������� ����� ��� �������� ������������ ������� � ��������
/// </summary>
//! \attention
//!  ������������� ��������� ���������� � ������ ������ ������
class t_ibp_debug__mt_guard2
{
 private:
  typedef t_ibp_debug__mt_guard2            self_type;

  t_ibp_debug__mt_guard2(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  t_ibp_debug__mt_guard2()
   :m_dwOwnerThreadID(0)
   ,m_cntLocks(0)
  {}

  /// <summary>
  ///  ����������
  /// </summary>
 ~t_ibp_debug__mt_guard2()
  {
   ///��������� ������������ ����������
   assert(m_dwOwnerThreadID==0);

   assert(m_cntLocks==0);
  }//~t_ibp_debug__mt_guard2

  /// <summary>
  ///  �������� ���������� ����������
  /// </summary>
  bool is_active()const
  {
   return m_dwOwnerThreadID!=0;
  }//is_active

  /// <summary>
  ///  �������� ������� ���������� ������� �������.
  /// </summary>
  bool current_thread_is_owner()const
  {
   return m_dwOwnerThreadID==::GetCurrentThreadId();
  }//current_thread_is_owner

  /// <summary>
  ///  ������ ���������� �������
  /// </summary>
  void lock()
  {
   const DWORD dwCurrentThreadID=::GetCurrentThreadId();

   const DWORD dwPrevThreadID=::InterlockedCompareExchange(&m_dwOwnerThreadID,dwCurrentThreadID,0);

   if(dwPrevThreadID==0)
   {
    assert(m_cntLocks==0);
   }
   else
   if(dwPrevThreadID==dwCurrentThreadID)
   {
    assert(m_cntLocks>0);
   }
   else
   {
    assert_msg(false,
               "dwPrevThreadID="<<dwPrevThreadID<<"\n"
               "dwCurrentThreadID="<<dwCurrentThreadID);
   }//else

   ::InterlockedIncrement(&m_cntLocks);

   assert(m_cntLocks>0);
  }//lock

  /// <summary>
  ///  ��������� ������ ���������� �������
  /// </summary>
  void lock_first()
  {
   const DWORD dwCurrentThreadID=::GetCurrentThreadId();

   const DWORD dwPrevThreadID=::InterlockedCompareExchange(&m_dwOwnerThreadID,dwCurrentThreadID,0);

   assert_msg(dwPrevThreadID==0,
              "dwPrevThreadID="<<dwPrevThreadID<<"\n"
              "dwCurrentThreadID="<<dwCurrentThreadID);

   assert(m_cntLocks==0);

   ::InterlockedIncrement(&m_cntLocks);

   assert(m_cntLocks>0);
  }//lock_first

  /// <summary>
  ///  ������������ ���������� �������
  /// </summary>
  void unlock()
  {
   assert(m_cntLocks>0);

   const DWORD dwCurrentThreadID=::GetCurrentThreadId();

   assert_msg(m_dwOwnerThreadID==dwCurrentThreadID,
              "m_dwOwnerThreadID="<<m_dwOwnerThreadID<<"\n"
              "dwCurrentThreadID="<<dwCurrentThreadID);

   if(::InterlockedDecrement(&m_cntLocks)==0)
   {
    const DWORD dwPrevThreadID=::InterlockedCompareExchange(&m_dwOwnerThreadID,0,dwCurrentThreadID);

    assert_msg(dwPrevThreadID==dwCurrentThreadID,
               "dwPrevThreadID="<<dwPrevThreadID<<"\n"
               "dwCurrentThreadID="<<dwCurrentThreadID);
   }//if
  }//unlock

 private:
  ///������������� ��������� ����������
  DWORD m_dwOwnerThreadID;

  ///������� ����������� ����������
  LONG m_cntLocks;
};//class t_ibp_debug__mt_guard2

#endif // ndef NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_debug__mt_guard2_lock

#ifndef NDEBUG

/// <summary>
///  ���������� ����� ��� ������������� ������ � t_ibp_debug__mt_guard2
/// </summary>
using t_ibp_debug__mt_guard2_lock
 =lcpi::lib::structure::mt::t_lock_guard<t_ibp_debug__mt_guard2>;

#endif // ndef NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_debug__mt_guard2_lock_first

#ifndef NDEBUG

/// <summary>
///  ���������� ����� ��� ������������� ������ � t_ibp_debug__mt_guard2
/// <summary>
class t_ibp_debug__mt_guard2_lock_first
{
 private:
  typedef t_ibp_debug__mt_guard2_lock_first self_type;

  t_ibp_debug__mt_guard2_lock_first(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] guard
  explicit t_ibp_debug__mt_guard2_lock_first(t_ibp_debug__mt_guard2& guard)
   :m_guard(guard)
  {
   m_guard.lock_first();
  }//t_ibp_debug__mt_guard2_lock_first

  /// <summary>
  ///  ����������
  /// </summary>
 ~t_ibp_debug__mt_guard2_lock_first()
  {
   m_guard.unlock();
  }//~t_ibp_debug__mt_guard2_lock_first

 private:
  ///����������
  t_ibp_debug__mt_guard2& m_guard;
};//class t_ibp_debug__mt_guard2_lock_first

#endif // ndef NDEBUG

////////////////////////////////////////////////////////////////////////////////

#define IBP_OUTPUT_DEBUG_STRING(msg)                                       \
 {                                                                         \
  std::basic_ostringstream<TCHAR> ods_buf;                                 \
                                                                           \
  ods_buf<<msg;                                                            \
                                                                           \
  ::lcpi::ibp::IBP_OutputDebugString(ods_buf.str().c_str());               \
 }

////////////////////////////////////////////////////////////////////////////////

void IBP_OutputDebugString(LPCTSTR msg);

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
