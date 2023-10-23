////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__memory_pool.h
//! \brief   Класс для управления пулом памяти.
//! \author  Kovalenko Dmitry
//! \date    23.11.2014.
#ifndef _remote_fb__memory_pool_H_
#define _remote_fb__memory_pool_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__MemoryPool

/// <summary>
///  Реализация интерфейса для выделения памяти под данные сетевого пакета
/// </summary>
class RemoteFB__MemoryPool
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__PacketMemory)
{
 private:
  using self_type=RemoteFB__MemoryPool;

  RemoteFB__MemoryPool(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  RemoteFB__MemoryPool();

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~RemoteFB__MemoryPool();

  //RemoteFB__PacketMemory interface -------------------------------------
  /// <summary>
  ///  Выделение памяти. THROW.
  /// </summary>
  //! \param[in] memID
  //!  Идентификатор поля, для которого нужно выделеить память
  //! \param[in] sz
  //!  Размер блока
  //! \return
  //!  Указатель на выделенный блок.
  virtual void* allocate(enumMemoryID memID,
                         size_t       sz)COMP_W000004_OVERRIDE;

  //own interface --------------------------------------------------------
  void deallocate_all();

 private: //internal types -----------------------------------------------
  using raw_allocator_type=RemoteFB__MemoryAllocator::rebind<void>::other;

  struct tag_cluster LCPI_CPP_CFG__CLASS__FINAL
  {
   public:
    tag_cluster*  next;
    char          data[1];
  };//struct tag_cluster

 private:
  tag_cluster*   m_ptr;
};//class RemoteFB__MemoryPool

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
