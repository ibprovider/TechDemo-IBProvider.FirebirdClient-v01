////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__known_server_key.h
//! \brief   Type of known by server key, received from it by client.
//! \author  Kovalenko Dmitry
//! \date    15.08.2016.
#ifndef _remote_fb__known_server_key_H_
#define _remote_fb__known_server_key_H_

#include "source/db_client/remote_fb/remote_fb__memory.h"
#include <structure/t_const_str_box.h>
#include <structure/t_first_last.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__KnownServerKey

/// <summary>
///  Type of known by server key, received from it by client
/// </summary>
class RemoteFB__KnownServerKey LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__SmartMemoryObject
{
 private:
  using self_type=RemoteFB__KnownServerKey;

  RemoteFB__KnownServerKey(const self_type& x)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  using self_cptr=lib::structure::t_smart_object_ptr<const self_type>;

  using wstr_box_type=lib::structure::t_const_wstr_box;

  using wstr_range_type
   =lib::structure::t_first_last<std::wstring::const_iterator>;

 public:
  const std::wstring wstrType;
  const std::wstring wstrPlugin;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] _wstrType
  //! \param[in] _wstrPlugin
  RemoteFB__KnownServerKey(const wstr_box_type&   _wstrType,
                           const wstr_range_type& _wstrPlugin);
  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~RemoteFB__KnownServerKey();

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  //! \param[in] _wstrType
  //! \param[in] _wstrPlugin
  static self_ptr Create(const wstr_box_type&   _wstrType,
                         const wstr_range_type& _wstrPlugin);
};//class RemoteFB__KnownServerKey

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
