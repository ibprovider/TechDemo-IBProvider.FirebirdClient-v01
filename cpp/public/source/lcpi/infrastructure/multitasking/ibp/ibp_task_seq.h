///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Multitasking [IBP].
//                                               Dmitry Kovalenko. 26.08.2019.
#ifndef _lcpi_infrastructure_multitasking_ibp__ibp_task_seq_H_
#define _lcpi_infrastructure_multitasking_ibp__ibp_task_seq_H_

#include <lcpi/infrastructure/multitasking/ibp/ibp_task_pll.h>

namespace lcpi{namespace infrastructure{namespace multitasking{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_task
//! @{
////////////////////////////////////////////////////////////////////////////////
//class ibp_task_seq__controller

class LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__IFACE_STG __declspec(novtable) ibp_task_seq__controller
 :public core::structure::t_smart_interface
{
 private:
  typedef ibp_task_seq__controller                         self_type;

 public: //typedefs ------------------------------------------------------
  typedef core::structure::t_smart_object_ptr<self_type>   self_ptr;

 public:
  /// <summary>
  ///  Ожидание завершения задания
  /// </summary>
  virtual void wait()=0;

  /// <summary>
  ///  Завершение работы задания
  /// </summary>
  //! \param[in] forced
  //!  Форсировать отключение задания
  //!
  //! - Если forced равен true, то метод вернет управление после отключения
  //!   задания от менеджера.
  //! - Если forced равен false, то метод пометит задание для завершения и вернет
  //!   управление. Фактическое отключение задания произойдет когда менеджер
  //!   доберется до него в цикле запуска заданий.
  virtual void stop(bool forced)=0;

  /// <summary>
  ///  Отмена задания
  /// </summary>
  //! \param[in] forced
  //!  Форсировать отмену задания
  //!
  //! - Если forced равен true, то метод вернет управление после завершения
  //!   отмены задания.
  //! - Если forced равен false, то метод возведет сигналы отмены и вернет
  //!   управление. Фактическая отмена задания произойдет когда менеджер
  //!   доберется до него в цикле запуска заданий.
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
  ///  Повторная генерация исключения последнего запуска задания
  /// </summary>
  virtual void rethrow_task_error()const=0;
};//class ibp_task_seq__controller

////////////////////////////////////////////////////////////////////////////////
//class ibp_task_seq__manager

class LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__IFACE_STG __declspec(novtable) ibp_task_seq__manager
 :public core::structure::t_smart_interface
{
 private:
  typedef ibp_task_seq__manager                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef core::structure::t_smart_object_ptr<self_type> self_ptr;

  typedef ibp_task_seq__controller                       task_controller_type;
  typedef task_controller_type::self_ptr                 task_controller_ptr;

 public:
  /// <summary>
  ///  Регистрация задания
  /// </summary>
  //! \param[in] task
  //!  Not NULL
  //! \param[in] task_flags
  virtual task_controller_ptr add_task(ibp_task*        task,
                                       ibp_task_flags   task_flags)=0;
};//class ibp_task_seq__manager

////////////////////////////////////////////////////////////////////////////////
//class ibp_task_seq__manager_connector2

/// <summary>
///  Интерфейс доступа к менеджеру задач.
/// </summary>
class LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__IFACE_STG __declspec(novtable) ibp_task_seq__manager_connector2
 :public core::structure::t_smart_interface
{
 public: //typedefs ------------------------------------------------------
  typedef ibp_task_seq__manager                     task_manager_type;
  typedef task_manager_type::self_ptr               task_manager_ptr;

 public:
  /// <summary>
  ///  Получение указателя на менеджер задач
  /// </summary>
  //! \return
  //!  Указатель на менеджер задач
  virtual task_manager_ptr get_task_manager()=0;
};//class ibp_task_seq__manager_connector2

////////////////////////////////////////////////////////////////////////////////
//class ibp_task_seq__factory

#if(LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__NONE)
#else

class LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__CLASS_STG ibp_task_seq__factory
{
 public:
  typedef ibp_task_seq__manager                     task_manager_type;
  typedef task_manager_type::self_ptr               task_manager_ptr;

 public:
  ibp_task_seq__factory()=delete;

  ibp_task_seq__factory(const ibp_task_seq__factory&)=delete;
  ibp_task_seq__factory(ibp_task_seq__factory&&)=delete;

 ~ibp_task_seq__factory()=delete;

  ibp_task_seq__factory& operator = (const ibp_task_seq__factory&)=delete;
  ibp_task_seq__factory& operator = (ibp_task_seq__factory&&)=delete;

 public:
  static task_manager_ptr create_manager(ibp_task_pll__manager_connector2* connector);
};//class ibp_task_seq__factory 

#endif

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms multitasking*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
