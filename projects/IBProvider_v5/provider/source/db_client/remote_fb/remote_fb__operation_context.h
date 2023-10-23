////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__operation_context.h
//! \brief   Реализация контекста операции.
//! \author  Kovalenko Dmitry
//! \date    17.05.2015.
#ifndef _remote_fb__operation_context_H_
#define _remote_fb__operation_context_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include <structure/t_fix_vector.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__OperationContext

/// <summary>
///  Стандартная реализация контекста операции с портом.
/// </summary>
class RemoteFB__OperationContext LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__PortOperationContext
{
 private:
  using self_type=RemoteFB__OperationContext;

  RemoteFB__OperationContext(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  /// <summary>
  ///  Конструктор по умолчанию.
  /// </summary>
  RemoteFB__OperationContext();

  /// <summary>
  ///  Конструктор инициализации.
  /// </summary>
  //! \param[in] pMem
  //!  Указатель на сервис распределения памяти. Not null.
  RemoteFB__OperationContext(RemoteFB__PacketMemory* pMem);

  /// <summary>
  ///  Деструктор.
  /// </summary>
 ~RemoteFB__OperationContext();

  //modifications --------------------------------------------------------

  /// <summary>
  ///  Регистрация сервиса операции. NO THROW.
  /// </summary>
  //! \param[in] pSvc
  //!  Not null.
  template<class T>
  void reg_svc(T* pSvc);

  //interface ------------------------------------------------------------
  virtual RemoteFB__SmartObjectPtr query_service(REFGUID serviceID)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  using svc_data_type=std::pair<GUID,RemoteFB__SmartObjectPtr>;

  using services_type=lib::structure::t_fix_vector<svc_data_type,8>;

 private:
  services_type m_services;
};//class RemoteFB__OperationContext

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__OperationContext

template<class T>
void RemoteFB__OperationContext::reg_svc(T* const pSvc)
{
 assert(pSvc);
 assert(!this->query_service(T::svcID));
 assert(!m_services.full());

 m_services.push_back(svc_data_type(T::svcID,structure::not_null_ptr(pSvc)));
}//reg_svc

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
