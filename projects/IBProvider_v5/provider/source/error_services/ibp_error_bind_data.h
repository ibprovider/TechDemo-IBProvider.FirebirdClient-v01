////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_bind_data.h
//! \brief   Описание ошибки привязки данных
//! \author  Kovalenko Dmitry
//! \date    11.02.2003
#ifndef _ibp_bind_error_data_H_
#define _ibp_bind_error_data_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/error_services/ibp_error_args.h"
#include "source/error_services/ibp_error_codes.h"
#include "source/ibp_memory.h"
#include "source/ibp_limits.h"

#include <lcpi/lib/structure/t_fix_vector.h>

#include <lcpi/lib/structure/error/t_err_text.h>

#include <lcpi/lib/structure/mt/t_guard.h>
#include <lcpi/lib/structure/mt/t_lock_guard.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

class IBP_BindErrorDataTraits;
class IBP_BindErrorData;
class IBP_BindErrorDataSet;

////////////////////////////////////////////////////////////////////////////////
//class IBP_BindErrorDataTraits

class IBP_BindErrorDataTraits LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=IBP_BindErrorDataTraits;

 public: //typedefs ------------------------------------------------------
  using args_type=t_ibp_error_args<self_type>;

  using out_return_type=IBP_BindErrorData;
};//class IBP_BindErrorDataTraits

////////////////////////////////////////////////////////////////////////////////
//class IBP_BindErrorData

/// <summary>
///  Класс для представления ошибки привязки данных
/// </summary>
class IBP_BindErrorData LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_INTERFACE_IMPL_DYNAMIC(lib::structure::t_err_text)
 ,public IBP_BindErrorDataTraits::args_type
{
 private:
  using self_type=IBP_BindErrorData;

  IBP_BindErrorData(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~IBP_BindErrorData();

 public: //typedefs ------------------------------------------------------
  using ordinal_type=DBORDINAL;

  using msg_code_type=ibp_msg_code_type;

  using params_type
   =structure::t_fix_vector<IBP_ErrorVariant,ibp_limc_MaxErrorArgsCount>;

 public: //---------------------------------------------------------------
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] index
  //! \param[in] err_code
  //! \param[in] msg_code
  IBP_BindErrorData(ordinal_type  index,
                    HRESULT       err_code,
                    msg_code_type msg_code);

  ordinal_type Index()const
   {return m_index;}

  HRESULT ErrorCode()const
   {return m_err_code;}

  //interface ------------------------------------------------------------
  virtual bool get_text(lcid_type lcid,string_type* text)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  virtual self_type& add_arg(const base_variant_type& x) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  using guard_type
   =lib::structure::mt::t_guard;

  using lock_guard_type
   =lib::structure::mt::t_lock_guard<guard_type>;

 private:
  mutable guard_type           m_guard;

  const ordinal_type           m_index;
  const HRESULT                m_err_code;
  const msg_code_type          m_msg_code;
  params_type                  m_params;

 private:
  friend class IBP_BindErrorDataSet;

 #ifndef NDEBUG
  /// A debugging pointer to the parent list.
  void* m_DEBUG__pOwnerList;
 #endif

  ///Указатель на следующий элемент однонаправленного списка.
  self_type* m_pNext;
};//class IBP_BindErrorData

using IBP_BindErrorDataPtr=lib::structure::t_smart_object_ptr<IBP_BindErrorData>;

////////////////////////////////////////////////////////////////////////////////
//class IBP_BindErrorDataSet

/// <summary>
///  Класс для накопления объектов IBP_BindErrorData
/// </summary>
//!  Формирует однонаправленный список объектов
class IBP_BindErrorDataSet LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=IBP_BindErrorDataSet;

  IBP_BindErrorDataSet(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using size_type=size_t;

 public:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  IBP_BindErrorDataSet();

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~IBP_BindErrorDataSet();

  /// <summary>
  ///  Проверка наличия элементов в списке
  /// </summary>
  bool IsEmpty()const;

  /// <summary>
  ///  Добавление нового объекта в конец списка. [NO THROW].
  /// </summary>
  //! \param[in] pData
  //!  Not NULL.
  void Add(IBP_BindErrorData* pData);

  /// <summary>
  ///  Генерация исключения с описанием ошибки
  /// </summary>
  //! \param[in] ErrMsgID_1
  //!  Основной код ошибки. В качестве аргумента будет установлено
  //!  общее число зарегистрированных ошибок.
  //! \param[in] ErrCode
  //!  Шаблон сообщения об ошибке
  void ThrowError(HRESULT           ErrCode,
                  ibp_msg_code_type ErrMsgID_1)const;

 private:
 #ifndef NDEBUG
  /// <summary>
  ///  Проверка состояния списка
  /// </summary>
  void DEBUG__CheckState()const;
 #endif

 private:
  /// Указатель на начало списка
  IBP_BindErrorData* m_pHead;

  /// Указатель на последний элемент списка
  IBP_BindErrorData* m_pTail;

  /// Количество элементов в списке
  size_type m_Size;
};//class IBP_BindErrorDataSet

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
