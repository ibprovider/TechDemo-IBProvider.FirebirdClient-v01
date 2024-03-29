///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Multitasking [IBP].
//                                               Dmitry Kovalenko. 26.08.2019.
#ifndef _lcpi_infrastructure_multitasking_ibp__ibp_task_pll_H_
#define _lcpi_infrastructure_multitasking_ibp__ibp_task_pll_H_

#include <lcpi/infrastructure/multitasking/ibp/ibp_task.h>

namespace lcpi{namespace infrastructure{namespace multitasking{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_task
//! @{
////////////////////////////////////////////////////////////////////////////////
//class ibp_task_pll__controller

class LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__IFACE_STG LCPI_CPP_CFG__DECLSPEC__NOVTABLE ibp_task_pll__controller
 :public core::structure::t_smart_interface
{
 private:
  using self_type=ibp_task_pll__controller;

 public:
  using self_ptr
   =core::structure::t_smart_object_ptr<self_type>;

 public:
  /// <summary>
  ///  Ожидание завершения задания
  /// </summary>
  //! \param[in] dwTimeout
  //   Timeout ожидания в миллисекундах. INFINITE в случае бесконечного ожидания.
  //! \return
  //!  - true, дождались завершения задания.
  //!  - false, истекло время ожидания завершения задания.
  virtual bool wait(DWORD dwTimeout=INFINITE)=0;

  /// <summary>
  ///  Возведение сигналов прерывания работы задания
  /// </summary>
  //! \param[in] forced
  //!  Дождаться фактического завершения задания
  virtual void cancel(bool forced)=0;

  /// <summary>
  ///  Получение идентификатора контроллера задачи
  /// </summary>
  virtual ibp_task_controller_id get_id()const=0;

  /// <summary>
  ///  Получение доступа к объекту задачи
  /// </summary>
  virtual ibp_task::self_ptr get_task()const=0;

  /// <summary>
  ///  Получение состояния задачи
  /// </summary>
  virtual ibp_task_state get_task_state()const=0;

  /// <summary>
  ///  Определение завершенности задания
  /// <summary>
  virtual bool task_is_completed()const=0;

  /// <summary>
  ///  Получение дескриптора события завершения задания
  /// <summary>
  virtual HANDLE get_done_event()const=0;

  /// <summary>
  ///  Повторная генерация исключения задачи или потока
  /// </summary>
  //! \note
  //!  Задание дожно быть завершено (task_is_completed)
  virtual void rethrow_task_error()const=0;
};//class ibp_task_pll__controller

////////////////////////////////////////////////////////////////////////////////
//class ibp_task_pll__manager

class LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__IFACE_STG LCPI_CPP_CFG__DECLSPEC__NOVTABLE ibp_task_pll__manager
 :public core::structure::t_smart_interface
{
 private:
  using self_type=ibp_task_pll__manager;

 public: //typedefs ------------------------------------------------------
  using self_ptr
   =core::structure::t_smart_object_ptr<self_type>;

  using task_controller_type
   =ibp_task_pll__controller;

  using task_controller_ptr
   =task_controller_type::self_ptr;

 public:
  /// <summary>
  ///  Добавление задания
  /// </summary>
  //! \param[in] task
  //! \param[in] task_flags
  virtual task_controller_ptr add_task(ibp_task*        task,
                                       ibp_task_flags   task_flags)=0;
};//class ibp_task_pll__manager

////////////////////////////////////////////////////////////////////////////////
//class ibp_task_pll__manager_connector2

/// <summary>
///  Интерфейс доступа к менеджеру задач.
/// </summary>
class LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__IFACE_STG LCPI_CPP_CFG__DECLSPEC__NOVTABLE ibp_task_pll__manager_connector2
 :public core::structure::t_smart_interface
{
 public:
  using task_manager_type
   =ibp_task_pll__manager;

  using task_manager_ptr
   =task_manager_type::self_ptr;

 public:
  /// <summary>
  ///  Получение указателя на менеджер задач
  /// </summary>
  //! \return
  //!  Указатель на менеджер задач
  virtual task_manager_ptr get_task_manager()=0;
};//class ibp_task_pll__manager_connector2

////////////////////////////////////////////////////////////////////////////////
//class ibp_task_pll__factory

#if(LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__NONE)
#else

class LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__CLASS_STG ibp_task_pll__factory
{
 public:
  using task_manager_type
   =ibp_task_pll__manager;

  using task_manager_ptr
   =task_manager_type::self_ptr;

 public:
  ibp_task_pll__factory()=delete;

  ibp_task_pll__factory(const ibp_task_pll__factory&)=delete;
  ibp_task_pll__factory(ibp_task_pll__factory&&)=delete;

 ~ibp_task_pll__factory()=delete;

  ibp_task_pll__factory& operator = (const ibp_task_pll__factory&)=delete;
  ibp_task_pll__factory& operator = (ibp_task_pll__factory&&)=delete;

 public:
  static task_manager_ptr create_manager();

  static task_manager_ptr get_manager();
};//class ibp_task_pll__factory 

#endif

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms multitasking*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
