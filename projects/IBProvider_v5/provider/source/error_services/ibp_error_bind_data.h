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
#include <ole_lib/oledb/variant/oledb_xvariant.h>
#include <structure/t_fix_vector.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

class TIBPBindErrorDataTraits;
class TIBPBindErrorData;
class TIBPBindErrorDataSet;

////////////////////////////////////////////////////////////////////////////////
//class TIBPBindErrorDataTraits

class TIBPBindErrorDataTraits
{
 public: //typedefs ------------------------------------------------------
  typedef TIBPBindErrorDataTraits                    self_type;

  typedef t_ibp_error_args<self_type>                args_type;

  typedef TIBPBindErrorData                          out_return_type;

 public:
  static out_return_type& out_ret(args_type& x);
};//struct TIBPBindErrorDataTraits

////////////////////////////////////////////////////////////////////////////////
//class TIBPBindErrorData

/// <summary>
///  Класс для представления ошибки привязки данных
/// </summary>
class TIBPBindErrorData:public ibprovider::IBP_IText
                       ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
                       ,public TIBPBindErrorDataTraits::args_type
{
 private:
  typedef TIBPBindErrorData                               self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler  inherited;

  TIBPBindErrorData(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~TIBPBindErrorData();

 public: //typedefs ------------------------------------------------------
  typedef DBORDINAL                                        ordinal_type;
  typedef ibp_msg_code_type                                msg_code_type;

  typedef structure::t_fix_vector
            <ibp_limc_MaxErrorArgsCount,
             oledb_lib::TDBVariant>                        params_type;

 public: //---------------------------------------------------------------
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] index
  //! \param[in] err_code
  //! \param[in] msg_code
  TIBPBindErrorData(ordinal_type  index,
                    HRESULT       err_code,
                    msg_code_type msg_code);

  ordinal_type Index()const
   {return m_index;}

  HRESULT ErrorCode()const
   {return m_err_code;}

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //IBP_IText interface --------------------------------------------------
  virtual HRESULT __stdcall GetText(LCID  lcid,
                                    BSTR* pbstrText) COMP_W000004_OVERRIDE_FINAL;

 private:
  virtual self_type& add_arg(const base_variant_type& x) COMP_W000004_OVERRIDE_FINAL;//abstract

 private:
  typedef structure::t_multi_thread_traits       thread_traits;
  typedef thread_traits::guard_type              guard_type;
  typedef thread_traits::lock_guard_type         lock_guard_type;

 private:
  guard_type                   m_guard;

  const ordinal_type           m_index;
  const HRESULT                m_err_code;
  const msg_code_type          m_msg_code;
  params_type                  m_params;

 private:
  friend class TIBPBindErrorDataSet;

 #ifndef NDEBUG
  ///Признак принадлежности списку. Объект может принадлежать только одному списку.
  ///Используется в отладочных проверках.
  bool       m_InList;
 #endif

  ///Указатель на следующий элемент однонаправленного списка.
  self_type* m_pNext;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(TIBPBindErrorData)
};//class TIBPBindErrorData

typedef ole_lib::IPtr2<TIBPBindErrorData>   TIBPBindErrorDataPtr;

////////////////////////////////////////////////////////////////////////////////
//class TIBPBindErrorDataSet

/// <summary>
///  Класс для накопления объектов TIBPBindErrorData
/// </summary>
//!  Формирует однонаправленный список объектов
class TIBPBindErrorDataSet
{
 private:
  typedef TIBPBindErrorDataSet              self_type;

  TIBPBindErrorDataSet(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

 public:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  TIBPBindErrorDataSet();

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~TIBPBindErrorDataSet();

  /// <summary>
  ///  Проверка наличия элементов в списке
  /// </summary>
  bool IsEmpty()const;

  /// <summary>
  ///  Добавление нового объекта в конец списка. [NO THROW].
  /// </summary>
  //! \param[in] pData
  //!  Not NULL.
  void Add(TIBPBindErrorData* pData);

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
  void CheckState()const;
 #endif

 private:
  /// Указатель на начало списка
  TIBPBindErrorData* m_pHead;

  /// Указатель на последний элемент списка
  TIBPBindErrorData* m_pTail;

  /// Количество элементов в списке
  size_type m_Size;
};//class TIBPBindErrorDataSet

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
