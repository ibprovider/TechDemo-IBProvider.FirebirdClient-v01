////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__known_server_key_array.h
//! \brief   Массив объектов класса RemoteFB__KnownServerKey.
//! \author  Kovalenko Dmitry
//! \date    04.09.2016
#ifndef _remote_fb__known_server_key_array_H_
#define _remote_fb__known_server_key_array_H_

#include "source/db_client/remote_fb/remote_fb__known_server_key.h"

#include <structure/t_smart_vector.h>
#include <lcpi/lib/structure/stl/t_stl_set.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__KnownServerKeyArray

/// <summary>
///  Массив объектов класса RemoteFB__KnownServerKey.
/// </summary>
class RemoteFB__KnownServerKeyArray LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__KnownServerKeyArray;

  RemoteFB__KnownServerKeyArray(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using size_type=size_t;

 public:
  /// <summary>
  ///  Конструктор по умолчанию
  /// </summary>
  RemoteFB__KnownServerKeyArray();

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~RemoteFB__KnownServerKeyArray();

  //interface ------------------------------------------------------------

  /// <summary>
  ///  Регистрация нового ключа
  /// </summary>
  //! \param[in] pKey
  //!  Not null.
  //!
  //! \attention
  //!  В случае добавления дубля, будет выкинуто исключение.
  void add(const RemoteFB__KnownServerKey* pKey);

  //----------------------------------------------------------------------
  size_t size()const;

  bool empty()const;

  const RemoteFB__KnownServerKey* operator [] (size_type index)const;

 private:
  using items_type
   =structure::t_smart_vector
     <const RemoteFB__KnownServerKey,
      RemoteFB__MemoryAllocator>;

 private:
  class tag_item_less LCPI_CPP_CFG__CLASS__FINAL
  {
   public:
    tag_item_less()
    {;}

    bool operator () (const RemoteFB__KnownServerKey* pK1,
                      const RemoteFB__KnownServerKey* pK2)const;
  };//class tag_item_less

  using item_index_type
   =lib::structure::t_stl_set
     <RemoteFB__KnownServerKey::self_cptr,
      tag_item_less,
      RemoteFB__MemoryAllocator>;

 private:
  /// Список ключей
  items_type m_items;

  /// Индекс зарегистрированных ключей
  item_index_type m_index;
};//class RemoteFB__KnownServerKeyArray

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
