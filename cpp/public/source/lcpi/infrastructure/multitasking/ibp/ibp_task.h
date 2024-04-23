///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Multitasking [IBP].
//                                               Dmitry Kovalenko. 26.08.2019.
#ifndef _lcpi_infrastructure_multitasking_ibp__ibp_task_H_
#define _lcpi_infrastructure_multitasking_ibp__ibp_task_H_

#include <lcpi/infrastructure/multitasking/ibp/.config.h>
#include <lcpi/infrastructure/core/structure/t_smart_interface.h>
#include <lcpi/infrastructure/core/structure/t_smart_object_ptr.h>

namespace lcpi{namespace infrastructure{namespace multitasking{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_task
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������� ����������� ������
/// </summary>
using ibp_task_controller_id=size_t;

/// <summary>
///  ������ (����) ������
/// </summary>
using ibp_task_signal_value=std::int32_t;

////////////////////////////////////////////////////////////////////////////////
//class ibp_task_signals

/// <summary>
///  ��������� ��� ������� � ����������� �������� ������
/// </summary>
class LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__IFACE_STG LCPI_CPP_CFG__DECLSPEC__NOVTABLE ibp_task_signals
{
 public:
  ibp_task_signals()=default;

  ibp_task_signals(const ibp_task_signals&)=delete;
  ibp_task_signals(ibp_task_signals&&)=delete;

 ~ibp_task_signals()=default;

  ibp_task_signals& operator = (const ibp_task_signals&)=delete;
  ibp_task_signals& operator = (ibp_task_signals&&)=delete;

 public:
  //! \brief ��������� �������������� ����������� ������
  virtual ibp_task_controller_id get_task_controller_id()const=0;

  //! \brief ��������� ��������� ������� ������ �������
  virtual ibp_task_signal_value get_cancel_signal()const=0;

  //! \brief ��������� ����������� ������� ������ �������
  virtual HANDLE get_cancel_event()const=0;

  //! \brief ������������� COM
  virtual void initialize_COM()=0;

  //! \brief
  //!  ����� ���������������� ������
  //!
  //! This method will reset ErrorInfo object.
  virtual void reset_user_data()=0;
};//class ibp_task_signals

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Enumeration of task completion codes
/// </summary>
enum class ibp_task_result_code
{
 //! \brief Exit code: ok
 ok            =0x01,

 //! \brief Exit code: canceled
 cancelled     =0x02,
};//enum class ibp_task_result_code

////////////////////////////////////////////////////////////////////////////////

enum
{
 //! \brief Mask of exit code section
 ibp_task_result_code__mask=0x0F,
};//enum

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Enumeration of task completion flags
/// </summary>
struct ibp_task_result_flag
{
 enum
 {
  //! \brief
  //!  Flag of request to task reexecution
  //! \note
  //!  Required a support on the manager layer
  exec_again     =0x10,
 };//enum
};//struct ibp_task_result_flag

////////////////////////////////////////////////////////////////////////////////
//enum class ibp_task_result

enum class ibp_task_result
{
 none           =0,

 ok             =(int)ibp_task_result_code::ok,

 ok__exec_again =(int)ibp_task_result_code::ok|
                 (int)ibp_task_result_flag::exec_again,

 cancelled      =(int)ibp_task_result_code::cancelled,
};//enum class ibp_task_result

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ������ �������
/// </summary>
enum
{
 ///������������ ����������� ������
 ibp_task_flag__periodic        =0x01,

 ///������������ ������ ������
 ibp_task_flag__ignore_error    =0x02,

 ///���������� ������
 ibp_task_flag__background_exec =0x04,
};//enum

///��� ��� �������� ������ �������.
using ibp_task_flags=unsigned;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ��������� �������
/// <summary>
enum class ibp_task_state
{
 /// \brief �� ����������
 none                        =0,

 /// \brief ������� ��������� � ������� �� ������
 wait                        =1,

 /// \brief ������� ��������
 cancelled                   =2,

 /// \brief ������� ���������������� � �������
 prepare_for_run             =3,

 /// \brief ������� �������� �� ���������
 active                      =4,

 /// \brief ������� ����������
 done                        =5,
};//enum class ibp_task_state

////////////////////////////////////////////////////////////////////////////////
//class ibp_task

/// <summary>
///  ������� ��������� ������
/// </summary>
class LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__IFACE_STG LCPI_CPP_CFG__DECLSPEC__NOVTABLE ibp_task
 :public core::structure::t_smart_interface
{
 public: //typedefs ------------------------------------------------------
  /// �����-���������.
  using self_ptr
   =core::structure::t_smart_object_ptr<ibp_task>;

  /// ��������� ������� � �������� ������ [ALIASE]
  using task_signals_type
   =ibp_task_signals;

  /// <summary>
  ///  ���������� ���������� �������.
  /// </summary>
  //!  �������� �����, ������������� � tag_ibp_task_result
  using execute_result_type
   =ibp_task_result;

 public:
  /// <summary>
  ///  ��������� ����� �������
  /// </summary>
  virtual const wchar_t* get_task_name()const=0;

  /// <summary>
  ///  ���������� �������
  /// </summary>
  //! \param[in] task_signals
  //!  ������ ����� � ������������ �������
  virtual execute_result_type execute(task_signals_type& task_signals)=0;

  /// <summary>
  ///  ������ �������
  /// </summary>
  //!  ���� ����� ������������ ��� ���������� ������� ��������, ���������� ��
  //!  ������ execute.
  //! \note
  //!  �� ������������� ������������ ���� ����� ��� ���������� ����������� ������
  //!  �������. ��� ���� ����� ������� ������������ ������� � ������� task_signals,
  //!  ������� ���������� � ����� execute. � ��������� ������ ����� ����������
  //!  �������� � �������� ������������ ��������� - �������� ������������ ��
  //!  ����������� ������ ������, ������� ������� ����� ����������� ������.
  virtual void cancel()=0;
};//class ibp_task

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms multitasking*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
