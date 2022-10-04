////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_entry_point.h
//! \brief   ����������� ��� ����������� � ������ ����� DLL.
//! \author  Kovalenko Dmitry
//! \date    26.04.2003
#ifndef _ibp_os_win32__dll_entry_point_H_
#define _ibp_os_win32__dll_entry_point_H_

#include "source/os/ibp_os__dll.h"

#include <lcpi/lib/structure/debug/debug_code.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//contanings

template<class TFunc>
class t_ibp_os_win32__dll_entry_point;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__dll_entry_point

/// <summary>
///  ������ ����������� � ����� ����� DLL
/// </summary>
template<class TFunc>
class t_ibp_os_win32__dll_entry_point
{
 private:
  typedef t_ibp_os_win32__dll_entry_point<TFunc>         self_type;

  t_ibp_os_win32__dll_entry_point(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef TFunc                                          func_type;

  typedef t_ibp_os__dll                                  dll_type;

  typedef t_ibp_os__dll_ptr                              dll_ptr;

 public: //---------------------------------------------------------------
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] pDLL
  //! \param[in] point_name
  t_ibp_os_win32__dll_entry_point(dll_type* const pDLL,
                                  LPCSTR    const point_name)
   :m_spDLL(structure::not_null_ptr(pDLL))
   ,m_point_name(point_name)
   ,m_point(nullptr)
  {
   assert(m_spDLL);
   assert(m_point_name!=nullptr);
   assert(m_point==nullptr); // :)
  }

  /// <summary>
  ///  ����������
  /// </summary>
 ~t_ibp_os_win32__dll_entry_point()
  {
  }

  /// <summary>
  ///  ���������� ��� �������
  /// </summary>
  LPCSTR point_name() const
  {
   return m_point_name;
  }//point_name

  /// <summary>
  ///  ��������� ��������� �� �������������� �������. THROW
  /// </summary>
  //! \return
  //!  Function's pointer
  //!
  //! ���� ����� ����� �����������, �� ������������ ����������
  const func_type point() const
  {
   if(m_point!=nullptr)
    return m_point;

   auto const point=(func_type)m_spDLL->get_proc_address(m_point_name);

   assert(point!=nullptr);

   LCPI__DEBUG_CODE(auto const prevPoint=)
    lcpi::lib::structure::mt::interlocked::compare_exchange
     (&m_point,
      point,
      nullptr);

   assert(prevPoint==nullptr || prevPoint==point);

   assert(m_point==point);

   return m_point;
  }//point

  /// <summary>
  ///  ������������ ������� � DLL �������������� �������
  /// </summary>
  bool test_point() const
  {
   if(m_point!=nullptr)
    return true;

   auto const point=(func_type)m_spDLL->get_proc_address(m_point_name);

   if(point==nullptr)
    return false;

   LCPI__DEBUG_CODE(auto const prevPoint=)
    lcpi::lib::structure::mt::interlocked::compare_exchange
     (&m_point,
      point,
      nullptr);

   assert(prevPoint==nullptr || prevPoint==point);

   assert(m_point==point);

   return true;
  }//test_point

 private:
  ///��������� �� ��������� DLL
  dll_ptr const m_spDLL;

  ///��� ����� �����
  LPCSTR  const m_point_name;

  ///��������� �� ����� �����
  mutable func_type volatile m_point;
};//class t_ibp_os_win32__dll_entry_point

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
