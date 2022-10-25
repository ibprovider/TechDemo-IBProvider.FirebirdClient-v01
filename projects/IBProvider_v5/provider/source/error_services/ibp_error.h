////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error.h
//! \brief   Класс исключения для обработки OLEDB-ошибок
//! \author  Kovalenko Dmitry
//! \date    03.02.2003
#ifndef _ibp_error_H_
#define _ibp_error_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/error_services/ibp_error_adapter.h"
#include "source/error_services/ibp_error_elements.h"
#include "source/error_services/ibp_error_records_r.h"

#ifndef OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO
# error OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO not defined!
#endif

#if(OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO!=0)
# error Incorrect value of OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO!
#endif

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

class  t_ibp_error_element;

struct t_ibp_error_traits;
class  t_ibp_error;

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef ole_lib::t_base_com_error           t_ibp_base_com_error;

////////////////////////////////////////////////////////////////////////////////
//Вспомогательные макросы

#define IBP_ERRORSOCCURRED(warning) ((warning)?DB_S_ERRORSOCCURRED:DB_E_ERRORSOCCURRED)

////////////////////////////////////////////////////////////////////////////////
//struct t_ibp_error_traits

struct t_ibp_error_traits
{
 typedef t_ibp_error_traits                         self_type;

 typedef t_ibp_error_args<self_type>                args_type;

 typedef t_ibp_error                                out_return_type;

 static out_return_type& out_ret(args_type& x);
};//struct t_ibp_error_traits

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error

/// <summary>
///  Класс исключений для обработки ошибок в компонентах модуля
/// </summary>
/// <seealso cref="t_ibp_error_element"/>
class t_ibp_error:public  ole_lib::t_base_com_error
                 ,public  t_ibp_error_traits::args_type
                 ,private t_ibp_error_adapter
                 ,public  t_ibp_error_records_r
{
 private:
  typedef t_ibp_error                               self_type;

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_ibp_error(self_type&& exc);
  self_type& operator = (self_type&& exc);
 #endif

  //метод без реализации.
  //нужен для проверки отсутствия виртуального set_error_info в базовом классе.
  HRESULT set_error_info(REFIID exc_iid)const;

 private:
  struct tag_ctr__swap{};

  /// <summary>
  ///  Аналог move-конструктора
  /// </summary>
  //! \param[in,out] x
  //! \param[in] tag
  t_ibp_error(self_type& x,const tag_ctr__swap& tag);

 public: //typedefs ------------------------------------------------------
  typedef t_ibp_subsystem_id                        subsys_id_type;

  typedef ibp_msg_code_type                         mc_type;

  typedef ole_lib::t_base_com_error                 base_error_type;
  typedef t_ibp_error_traits::args_type             args_type;

  typedef structure::t_err_records_r                base_records_r_type;

  typedef t_ibp_error_element                       error_record_type;
  typedef t_ibp_error_element::self_ptr             error_record_ptr;

  using get_cerr_obj_type
   =t_ibp_get_custom_error_object;

 private:
  class tag_error_adapter_with_limit;

 public: //constructors --------------------------------------------------
  /// <summary>
  ///  Конструктор копирования
  /// </summary>
  t_ibp_error(const self_type& exc);

  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] err_code
  explicit t_ibp_error(HRESULT err_code);

  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] err_code
  //! \param[in] msg_code
  t_ibp_error(HRESULT err_code,
              mc_type msg_code);

  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] err_code
  //! \param[in] msg_code
  //! \param[in] pGetCErr
  t_ibp_error(HRESULT            err_code,
              mc_type            msg_code,
              get_cerr_obj_type* pGetCErr);

  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] err_code
  //! \param[in] subsys_id
  //! \param[in] msg_code
  t_ibp_error(HRESULT        err_code,
              subsys_id_type subsys_id,
              mc_type        msg_code);

  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] err_code
  //! \param[in] subsys_id
  //! \param[in] msg_code
  //! \param[in] pGetCErr
  t_ibp_error(HRESULT            err_code,
              subsys_id_type     subsys_id,
              mc_type            msg_code,
              get_cerr_obj_type* pGetCErr);

  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] err_code
  //! \param[in] records
  t_ibp_error(HRESULT                    err_code,
              const base_records_r_type& records);

  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] err_code
  //! \param[in] records
  t_ibp_error(HRESULT                      err_code,
              const t_ibp_error_records_r& records);

  explicit t_ibp_error(const std::exception& exc);

  explicit t_ibp_error(error_record_type* const record);

  virtual ~t_ibp_error() __STL_EXCEPTION_DCR_THROW_SPEC;

  //----------------------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE
  const error_record_ptr& TESTCODE__get_cur_error_record()const
  {
   return m_cur_error;
  }//TESTCODE__get_cur_error_record
#endif

  //assign operators -----------------------------------------------------
  self_type& operator = (const self_type& exc);

  self_type& operator = (const std::exception& exc);

  /// <summary>
  ///  Установка нового основного кода ошибки. Текущая коллекция ошибок не очищается.
  /// </summary>
  //! \param[in] err_code
  //!  Новый основной код ошибки
  self_type& operator = (HRESULT err_code);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Инициализация состояния объекта
  /// </summary>
  //! \param[in] err_code
  //!  Основной код ошибки, который нужно установить
  self_type& clear_state(HRESULT err_code);

  //----------------------------------------------------------------------
  void swap(self_type& x);

  //exception interface --------------------------------------------------
  virtual const char* what()const __STL_EXCEPTION_WHAT_THROW_SPEC COMP_W000004_OVERRIDE_FINAL;//override

  //----------------------------------------------------------------------
  /// <summary>
  ///  Адаптер ошибок с ограничением на количество.
  /// </summary>
  tag_error_adapter_with_limit adapter_with_limit();

  //----------------------------------------------------------------------
  using t_ibp_error_adapter::add;
  using t_ibp_error_adapter::add__no_throw;

  void add_limit_event();

  self_type& add_error(HRESULT err_code,
                       mc_type msg_code);

  self_type& add_error(HRESULT            err_code,
                       mc_type            msg_code,
                       get_cerr_obj_type* pGetCErr);

  self_type& add_error(HRESULT            err_code,
                       subsys_id_type     subsys_id,
                       mc_type            msg_code);

  self_type& add_error(HRESULT            err_code,
                       subsys_id_type     subsys_id,
                       mc_type            msg_code,
                       get_cerr_obj_type* pGetCErr);

  self_type& add_error(base_error_record_type* pError);

  self_type& add_error__no_throw(HRESULT err_code,mc_type msg_code__0);

  //t_err_records_r interface --------------------------------------------

  /// <summary>
  ///  Получение числа ошибок
  /// </summary>
  virtual size_t get_record_count()const COMP_W000004_OVERRIDE_FINAL; //abstract

  /// <summary>
  ///  Получение описания одиночной ошибки
  /// </summary>
  //! \param[in] record_num
  virtual structure::t_err_record::self_ptr get_record(size_t record_num)const COMP_W000004_OVERRIDE_FINAL; //abstract

  //t_ibp_error_records_r interface --------------------------------------

  /// <summary>
  ///  Получение индекса главной ошибки
  /// </summary>
  virtual size_type_N get_primary_err_idx()const COMP_W000004_OVERRIDE_FINAL;

 public:
  /// <summary>
  ///  Установка последней ошибки как основной
  /// </summary>
  self_type& set_last_error_as_primary();

 public:
  /// <summary>
  ///  Генерация исключения
  /// </summary>
  COMP_CONF_DECLSPEC_NORETURN virtual void raise()const COMP_W000004_OVERRIDE_FINAL;//throw - override

 public:
  /// <summary>
  ///  Генерация исключения с указанным кодом ошибки
  /// </summary>
  //! \param[in] new_err_code
  COMP_CONF_DECLSPEC_NORETURN void raise(HRESULT new_err_code);//throw

  /// <summary>
  ///  Генерация исключения с перемещением состояния объекта
  /// </summary>
  COMP_CONF_DECLSPEC_NORETURN void raise_me();//throw

  /// <summary>
  ///  Генерация исключения с новым кодом ошибки и перемещением состояния объекта
  /// </summary>
  //! \param[in] new_err_code
  COMP_CONF_DECLSPEC_NORETURN void raise_me(HRESULT new_err_code);//throw

 private: //вспомогательные утилиты --------------------------------------
  virtual self_type& add_arg(const base_variant_type& x) COMP_W000004_OVERRIDE_FINAL;//abstract

  //максимальное число ошибок, которое можно зарегистрировать через
  //методы t_ibp_error_adapter ограничивается c_max_error_count
  virtual void push_error(base_error_record_type* pError) COMP_W000004_OVERRIDE_FINAL;//abstract (t_ibp_error_adapter)

 private:
  typedef structure::t_value_with_null<size_t>    primary_err_idx_type_N;

 private:
  ///Список ошибок
  t_ibp_error_elements m_errors;

  ///Указатель на текущую ошибку
  error_record_ptr m_cur_error;

  ///Индекс главной ошибки, которая будет выводится через интерфейс IErrorInfo
  primary_err_idx_type_N m_primary_err_idx;
};//class t_ibp_error

////////////////////////////////////////////////////////////////////////////////
//class IBP_CallContext::tag_error_adapter_with_limit

class t_ibp_error::tag_error_adapter_with_limit COMP_W000006_CLASS_FINAL
 :public t_ibp_error_adapter
{
 private:
  typedef tag_error_adapter_with_limit                 self_type;

  self_type& operator = (const self_type&);

 public:
  tag_error_adapter_with_limit(const self_type&);

  explicit tag_error_adapter_with_limit(t_ibp_error* pOwner);

 ~tag_error_adapter_with_limit();

 private:
  virtual void push_error(structure::t_err_record* err_record)COMP_W000004_OVERRIDE_FINAL;

 private:
  t_ibp_error* m_pOwner;
};//class t_ibp_error::tag_error_adapter_with_limit

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/error_services/ibp_error.inl"
////////////////////////////////////////////////////////////////////////////////
#endif
