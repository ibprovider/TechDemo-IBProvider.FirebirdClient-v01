////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 30.09.2019.
#ifndef _cpp_public_lcpi_lib_structure_debug__t_debug__mt_guard_rw_H_
#define _cpp_public_lcpi_lib_structure_debug__t_debug__mt_guard_rw_H_

#include <lcpi/lib/structure/mt/interlocked.h>

namespace lcpi{namespace lib{namespace structure{namespace debug{
////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG
#error "Incorect usage"
#endif

////////////////////////////////////////////////////////////////////////////////
//contents

class t_debug__mt_guard_rw;
class t_debug__mt_guard_rw_lock_r;
class t_debug__mt_guard_rw_lock_w;

////////////////////////////////////////////////////////////////////////////////
//class t_debug__mt_guard_rw

/// <summary>
///  Debugging class for the control of resource RW-access
/// </summary>
//! \attention
//!  Does not track recursive locks within thread borders
class t_debug__mt_guard_rw
{
 private:
  typedef t_debug__mt_guard_rw    self_type;

  t_debug__mt_guard_rw(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  Initialization constructor
  /// </summary>
  t_debug__mt_guard_rw()
   :m_cLocks(0)
  {
  }

  /// <summary>
  ///  Destructor
  /// </summary>
 ~t_debug__mt_guard_rw()
  {
   ///Проверяем освобождение блокировки
   assert(m_cLocks==0);
  }//~t_debug__mt_guard_rw

  /// <summary>
  ///  Тестирование отсутствия блокировок
  /// </summary>
  bool is_unlocked()const
  {
   return m_cLocks==0;
  }//is_unlocked

  /// <summary>
  ///  Блокировка на чтение
  /// </summary>
  void lock_r()
  {
   const auto cLocks=mt::interlocked::increment(&m_cLocks);

   assert_msg(cLocks>0,"cLocks="<<cLocks);
  }//lock_r

  /// <summary>
  ///  Разблокировка чтения
  /// </summary>
  void unlock_r()
  {
   const auto cLocks=mt::interlocked::decrement(&m_cLocks);

   assert_msg(cLocks>=0,"cLocks="<<cLocks);
  }//unlock_r

  /// <summary>
  ///  Блокировка на запись
  /// </summary>
  void lock_w()
  {
   const auto cLocks=mt::interlocked::compare_exchange(&m_cLocks,-1,0);

   assert_msg(cLocks==0,"cLocks="<<cLocks);
  }//lock_w

  /// <summary>
  ///  Разблокировка записи
  /// </summary>
  void unlock_w()
  {
   const auto cLocks=mt::interlocked::compare_exchange(&m_cLocks,0,-1);

   assert_msg(cLocks==-1,"cLocks="<<cLocks);
  }//unlock_w

 private:
  /// Счетчик блокировок.
  ///  ==0  - ресурс не заблокирован
  ///  >0   - ресурс заблокирован на чтение
  ///  ==-1 - ресурс заблокирован на запись
  LONG m_cLocks;
};//class t_debug__mt_guard_rw

////////////////////////////////////////////////////////////////////////////////
//class t_debug__mt_guard_rw_lock_r

/// <summary>
///  Отладочный класс для автоматизации работы с t_debug__mt_guard_rw
/// <summary>
class t_debug__mt_guard_rw_lock_r
{
 private:
  typedef t_debug__mt_guard_rw_lock_r        self_type;

  t_debug__mt_guard_rw_lock_r(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] guard
  explicit t_debug__mt_guard_rw_lock_r(t_debug__mt_guard_rw& guard)
   :m_guard(guard)
  {
   m_guard.lock_r();
  }//t_debug__mt_guard_rw_lock_r

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~t_debug__mt_guard_rw_lock_r()
  {
   m_guard.unlock_r();
  }//~t_debug__mt_guard_rw_lock_r

 private:
  ///Блокировка
  t_debug__mt_guard_rw& m_guard;
};//class t_debug__mt_guard_rw_lock_r

////////////////////////////////////////////////////////////////////////////////
//class t_debug__mt_guard_rw_lock_w

/// <summary>
///  Отладочный класс для автоматизации работы с t_debug__mt_guard_rw
/// <summary>
class t_debug__mt_guard_rw_lock_w
{
 private:
  typedef t_debug__mt_guard_rw_lock_w        self_type;

  t_debug__mt_guard_rw_lock_w(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] guard
  explicit t_debug__mt_guard_rw_lock_w(t_debug__mt_guard_rw& guard)
   :m_guard(guard)
  {
   m_guard.lock_w();
  }//t_debug__mt_guard_rw_lock_w

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~t_debug__mt_guard_rw_lock_w()
  {
   m_guard.unlock_w();
  }//~t_debug__mt_guard_rw_lock_w

 private:
  ///Блокировка
  t_debug__mt_guard_rw& m_guard;
};//class t_debug__mt_guard_rw_lock_w

////////////////////////////////////////////////////////////////////////////////
}/*nms debug*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#endif
