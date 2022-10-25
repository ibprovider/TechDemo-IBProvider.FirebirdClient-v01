////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__common
//! \file    db_obj__dbms_fb__common__oledb_error_text.h
//! \brief   COM объект для представления теста ошибки FB/IB
//! \author  Kovalenko Dmitry
//! \date    08.08.2016
#ifndef _db_obj__dbms_fb__common__oledb_error_text_H_
#define _db_obj__dbms_fb__common__oledb_error_text_H_

#include "source/db_obj/dbms_fb/common/db_obj__dbms_fb__common__svc__status_vector_utils.h"
#include <ole_lib/ole_lib.h>

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace common{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__dbms_fb__common
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

class FB_OleDbErrorText;

////////////////////////////////////////////////////////////////////////////////
//class FB_OleDbErrorText

/// <summary>
///  COM объект для представления теста ошибки FB/IB
/// </summary>
//! \attention
//!  Класс не предназначен для наследования.
//! \note
//!  Исходные данные для текста ошибки хранятся в статус векторе, который
//!  (вместе с косвенными данными) размещается непосредственно за последним
//!  "официальным" байтом объекта.
class FB_OleDbErrorText
 :public ibprovider::IBP_IText
 ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler

{
 private:
  typedef FB_OleDbErrorText                                       self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler          inherited;

  FB_OleDbErrorText(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef OLE_LIB__BUILD_IPTR_TYPE_NS(ibprovider::,IBP_IText)     IBP_ITextPtr;

  typedef isc_api::t_ibp_isc_status                               status_type;

  typedef fb_common__svc__status_vector_utils                     sv_utils_type;

  typedef fb_common__svc__status_vector_utils_ptr                 sv_utils_ptr;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pStatusVectorUtils
  //!  Not null.
  //! \param[in] szStatusVector
  //! \param[in] pStatusVector
  FB_OleDbErrorText(sv_utils_type*     pStatusVectorUtils,
                    size_t             szStatusVector,
                    const status_type* pStatusVector);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~FB_OleDbErrorText();

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  //! \param[in] pStatusVectorUtils
  //!  Not null.
  //! \param[in] sv_beg
  //! \param[in] sv_end
  //! \return
  //!  Not null.
  static IBP_ITextPtr Create(sv_utils_type*     pStatusVectorUtils,
                             const status_type* sv_beg,
                             const status_type* sv_end);

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //IBP_IText interface --------------------------------------------------
  /// <summary>
  ///  Получение текста
  /// </summary>
  //! \param[in]  lcid
  //! \param[out] pbstrText
  //!  Not NULL
  virtual HRESULT __stdcall GetText(LCID  lcid,
                                    BSTR* pbstrText)COMP_W000004_OVERRIDE_FINAL;

 private:
  typedef ole_lib::TComObjectMemoryAllocator      raw_allocator_type;

  static void* operator new (size_t); //not impl

  static void* operator new (size_t,void* pv);

 public:
  static void operator delete (void* pv);

 #if(COMP_CONF_SUPPORT_OPERATOR_DELETE_EX)
  //memory will be deallocated in catch of self_type::Create
  static void operator delete(void* /*pv*/,void* /*pv2*/){;}
 #endif

 private:
  ///Указатель на сервис для работы со статус вектором
  sv_utils_ptr const m_spStatusVectorUtils;

  ///Количество элементов в статус векторе
  size_t const m_szStatusVector;

  ///Указатель на первый элемент статус вектора
  const status_type* const m_pStatusVector;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(FB_OleDbErrorText);

  /*Далее в памяти будет размещен статус вектор и его косвенные данные*/
};//class FB_OleDbErrorText

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms common*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
