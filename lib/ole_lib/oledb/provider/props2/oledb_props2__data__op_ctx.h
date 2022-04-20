////////////////////////////////////////////////////////////////////////////////
//! \ingroup  oledb_lib_provider
//! \file     oledb_props2__data__op_ctx.h
//! \brief    Контекст операций со свойствами
//! \author   Kovalenko Dmitry
//! \date     02.03.2010
#ifndef _oledb_props2__data__op_ctx_H_
#define _oledb_props2__data__op_ctx_H_

#include <ole_lib/oledb/oledb_common.h>
#include <structure/t_str_formatter.h>
#include <structure/t_smart_object.h>

#include <structure/stl/t_stl_map.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup oledb_lib_provider
//! @{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__OpCtx

/// <summary>
///  Контекст операции со свойствами. [NO-MT-SAFE].
/// </summary>
class OLEDB_Props2__Data__OpCtx
{
 private:
  typedef OLEDB_Props2__Data__OpCtx                    self_type;

  OLEDB_Props2__Data__OpCtx(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_interface                 ctx_item_type;

  typedef structure::t_smart_object_ptr<ctx_item_type> ctx_item_ptr;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  explicit OLEDB_Props2__Data__OpCtx();

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~OLEDB_Props2__Data__OpCtx();

  //interface ------------------------------------------------------------
  /// <summary>
  ///  Регистрация элемента
  /// </summary>
  //! \param[in] id
  //!  Идентификатор элемента
  //! \param[in] item
  //!  Указатель на элемент. Not NULL.
  bool AddItem(REFGUID id,ctx_item_type* item);

  /// <summary>
  ///  Получение элемента
  /// </summary>
  //! \param[in] id
  //!  Идентификатор элемента
  //! \return
  //!  NULL. Если элемент не был зарегистрирован.
  ctx_item_ptr GetItem(REFGUID id)const;

 private: //internal typedefs --------------------------------------------
  typedef structure::t_stl_map
           <GUID,
            ctx_item_ptr,
            ole_lib::TGuidLess,
            TOLEDBMemoryAllocator>                     ctx_items_type;

 private:
  ///Контейнер зарегистрированных объектов контекста
  ctx_items_type m_items;
};//class OLEDB_Props2__Data__OpCtx

////////////////////////////////////////////////////////////////////////////////
//non-member functions

template<class TOpCtxItem>
typename TOpCtxItem::self_ptr OLEDB_Prop2__GetDBPropOpCtxItem(OLEDB_Props2__Data__OpCtx& op_ctx)
{
 if(OLEDB_Props2__Data__OpCtx::ctx_item_ptr const spItem=op_ctx.GetItem(TOpCtxItem::GetID()))
 {
  TOpCtxItem* const p=dynamic_cast<TOpCtxItem*>(spItem.ptr());

  if(!p)
  {
   assert(false);

   structure::str_formatter
    fmsg("[BUG CHECK] oledb_lib::OLEDB_Prop2__GetDBPropOpCtxItem [#001].\n"
         "TOpCtxItem: %1. ID: %2.");

   fmsg<<typeid(TOpCtxItem).name()
       <<ole_lib::guid_to_string(TOpCtxItem::GetID());

   throw std::runtime_error(fmsg.str());
  }//if !p

  assert(p);

  return structure::not_null_ptr(p);
 }//if

 return nullptr;
}//OLEDB_Prop2__GetDBPropOpCtxItem

//------------------------------------------------------------------------
template<class TOpCtxItem>
bool OLEDB_Prop2__AddDBPropOpCtxItem(OLEDB_Props2__Data__OpCtx& op_ctx,
                                     TOpCtxItem*          const pOpCtxItem)
{
 assert(pOpCtxItem);

 return op_ctx.AddItem(TOpCtxItem::GetID(),pOpCtxItem);
}//OLEDB_Prop2__AddDBPropOpCtxItem

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
