////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle_data__statement.h
//! \brief   ����������� ��� ������������� ������ ����������� �������.
//! \author  Kovalenko Dmitry
//! \date    24.02.2015
#ifndef _remote_fb__handle_data__statement_H_
#define _remote_fb__handle_data__statement_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/remote_fb__fetch_result.h"
#include "source/db_client/remote_fb/remote_fb__flags.h"
#include "source/db_client/remote_fb/remote_fb__msg_data_element_descr.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_msg_blr01_buffer.h"
#include "source/db_obj/isc_base/isc_msg_data_buffer.h"
#include "source/error_services/ibp_error.h"
#include "source/structure/ibp_buffer_view.h"
#include <structure/t_value_with_null.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__handles
//! @{
////////////////////////////////////////////////////////////////////////////////
//the content

class RemoteFB__HandleData_Statement;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement

/// <summary>
///  ������ �������.
/// </summary>
class RemoteFB__HandleData_Statement LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__SmartMemoryObject
{
 private:
  using self_type=RemoteFB__HandleData_Statement;

  RemoteFB__HandleData_Statement(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  using id_type=RemoteFB__SrvResourceID;

  using tr_data_type=handles::RemoteFB__HandleData_Transaction;

 public:
  using flag_base_type=unsigned short;
  using flags_type    =RemoteFB__Flags<flag_base_type>;

  //Values for m_Flags.

  /// ���������� �������� �������������� ������
  static const flag_base_type PFLAG__PREPARED            = 0x0001;

  /// Statement relates to blob op
  //static const flag_base_type PFLAG__BLOB                = 0x0002;

  /// op_execute can be deferred
  static const flag_base_type PFLAG__DEFER_EXECUTE       = 0x0004;

  /// ������������ �������� ������� �������
  static const flag_base_type PFLAG__CACHE_COLS_INFO     = 0x0008;

  /// ������������ �������� ���������� �������
  static const flag_base_type PFLAG__CACHE_PARAMS_INFO   = 0x0010;

 public:
  /// EOF was returned by fetch from this statement
  static const flag_base_type EFLAG__PAST_EOF               = 0x0001;

  /// ���������� ������� ���� ��������
  static const flag_base_type EFLAG__EXECUTION_WAS_DEFERRED = 0x0002;

 public:
  class tag_cn_list_adapter;
  class tag_tr_list_adapter;
  class tag_nclosed_stmt_list_adapter;

 public:
  using allocator_type=RemoteFB__MemoryAllocator;

  using xsqlvars_data_buffer_type
   =structure::t_typed_simple_buffer<unsigned char,allocator_type>;

  using msg_blr_buffer_type
   =isc_base::t_isc_msg_blr01_buffer;

  using msg_data_buffer_type
   =isc_base::t_isc_msg_data_buffer;

  using msg_data_descrs_type
   =RemoteFB__MsgDataElementDescrs;

  using msg_nulls_buffer_type
   =structure::t_typed_simple_buffer<unsigned char,allocator_type>;

 private:
  /// <summary>
  ///  ����������� ��-���������.
  /// </summary>
  RemoteFB__HandleData_Statement();

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~RemoteFB__HandleData_Statement();

 public:
  /// ������������ ������ �����������
  RemoteFB__Port* m_pParentPort;

 #ifndef NDEBUG
  /// DEBUG: ��������� �� ������������ ������ � ������ ������� �����������
  void*           m_pvOwnerCnList;
 #endif

  //��������������� ������ �������� �����������
  self_type*      m_pPrevCnStmt;
  self_type*      m_pNextCnStmt;

  /// ������� ���������� �������
  tr_data_type*   m_pParentTr;

  //��������������� ������ �������� ����������
  self_type*      m_pPrevTrStmt;
  self_type*      m_pNextTrStmt;

 public: //�������� ��� ��������� lazy_send ���������

  /// ����������, ������� ����������� ���������� ������
  tr_data_type*   m_pClosingTr;

  //��������������� ������ ���������� �������� m_pClosingTr
  self_type*      m_pPrevNotClosedStmt;
  self_type*      m_pNextNotClosedStmt;

 public:
  /// ��������� ������������� �������
  id_type     m_ID;

  /// ����� ���������� �������
  flags_type  m_PFlags;

  /// ����� ���������� �������
  flags_type  m_EFlags;

 public:
  /// PREPARE DATA: ��������� ������������� ���� �������
  structure::t_value_with_null<unsigned long> m_PData__StmtTypeID;

  /// PREPARE DATA: ���� ������������ ��������� �������� �������
  structure::t_value_with_null<bool> m_PData__BatchFetch;

  /// <summary>
  ///  PREPARE DATA: ����� � ������� �������� �������.
  /// </summary>
  /// �������� raw-������ ������� � ibp_isc_info_sql_describe_vars ����.
  /// � ����� ������ ����������� ibp_isc_info_end ��� ibp_isc_info_truncated.
  xsqlvars_data_buffer_type m_PData__ColumnsData;

  /// <summary>
  ///  PREPARE DATA: ����� � ������� �������� ����������.
  /// </summary>
  /// �������� raw-������ ������� � ibp_isc_info_sql_describe_vars ����.
  /// � ����� ������ ����������� ibp_isc_info_end ��� ibp_isc_info_truncated.
  xsqlvars_data_buffer_type m_PData__ParametersData;

 public:
  msg_blr_buffer_type    m_InParams__MSG_BLR;

  msg_data_buffer_type   m_InParams__MSG_DATA;

  //������������ ������� � 13-�� ���������.
  msg_data_descrs_type   m_InParams__MSG_DATA_DESCRS;

  msg_nulls_buffer_type  m_InParams__MSG_NULLS;

 public:
  msg_blr_buffer_type    m_OutParams__MSG_BLR;

  msg_data_descrs_type   m_OutParams__MSG_DATA_DESCRS;

  msg_data_buffer_type   m_OutParams__MSG_DATA;

  size_t                 m_OutParams__MSG_DATA_SIZE;

  size_t                 m_OutParams__MSG_DATA_ALIGN;

  //������������ ������� � 13-�� ���������.
  msg_nulls_buffer_type  m_OutParams__MSG_NULLS;

 public:
  /// ���������� ������� op_fetch
  RemoteFB__FetchResult::self_ptr m_spFetchResult;

 public:
  /// <summary>
  ///  ������� ������
  /// </summary>
  static self_ptr Create();

  //interface ------------------------------------------------------------
  void ResetPrepareState();

  void ResetExecuteState();

  void SaveInParams(const RemoteFB__OpSvc__StmtExecuteData_v1* pStmtExecData);

  void SaveInParams(const RemoteFB__OpSvc__StmtExecuteData_v2* pStmtExecData);

  /// <summary>
  ///  �������� �������, �������������� ParentTr.
  /// </summary>
  //! \attention
  //!  ���� ����� ����� ���������� ��������� ������ �� ������!
  void Dangerous__CloseCursorOfParentTr();

  /// <summary>
  ///  �������� �������, �������������� ClosingTr.
  /// </summary>
  //! \attention
  //!  ���� ����� ����� ���������� ��������� ������ �� ������!
  void Dangerous__CloseCursorOfClosingTr();

  /// <summary>
  ///  ������������ �������� �����������.
  /// </summary>
  //! \attention
  //!  ���� ����� ����� ���������� ��������� ������ �� ������!
  void Dangerous__DropHandle();

 private:
  template<typename T,class Allocator>
  static void Helper__Save
              (structure::t_typed_simple_buffer<T,Allocator>* pDest,
               const ibp::IBP_BufferView<const T>&            Source);

  template<typename T,class Allocator>
  static void Helper__Save
              (std::vector<T,Allocator>*           pDest,
               const ibp::IBP_BufferView<const T>& Source);
};//class RemoteFB__HandleData_Statement

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement::tag_cn_list_adapter

/// <summary>
///  ������� ������ �������� �����������.
/// </summary>
class RemoteFB__HandleData_Statement::tag_cn_list_adapter LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_cn_list_adapter;

 public:
  using node_type     =RemoteFB__HandleData_Statement;
  using node_ptr_type =node_type*;

 public:
  tag_cn_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Statement::tag_cn_list_adapter

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement::tag_tr_list_adapter

/// <summary>
///  ������� ������ �������� ����������.
/// </summary>
class RemoteFB__HandleData_Statement::tag_tr_list_adapter LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_tr_list_adapter;

 public:
  using node_type     =RemoteFB__HandleData_Statement;
  using node_ptr_type =node_type*;

 public:
  tag_tr_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Statement::tag_cn_list_adapter

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter

/// <summary>
///  ������� ������ ���������� �������� ����������.
/// </summary>
class RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_nclosed_stmt_list_adapter;

 public:
  using node_type     =RemoteFB__HandleData_Statement;
  using node_ptr_type =node_type*;

 public:
  tag_nclosed_stmt_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms handles*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
