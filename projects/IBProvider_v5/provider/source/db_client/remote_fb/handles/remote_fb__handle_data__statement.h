////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle_data__statement.h
//! \brief   ����������� ��� ������������� ������ ����������� �������.
//! \author  Kovalenko Dmitry
//! \date    24.02.2015
#ifndef _remote_fb__handle_data__statement_H_
#define _remote_fb__handle_data__statement_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/remote_fb__msg_data_element_descr.h"
//#include "source/db_client/remote_fb/remote_fb__srv_resource_id.h"
//#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/db_client/remote_fb/remote_fb__flags.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/error_services/ibp_error.h"
#include <structure/t_simple_buffer.h>
#include <structure/t_cycle_buffer_manager.h>
#include <structure/t_value_with_null.h>
#include <structure/stl/t_stl_vector.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__handles
//! @{
////////////////////////////////////////////////////////////////////////////////
//the content

class RemoteFB__FetchResult;
class RemoteFB__HandleData_Statement;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__FetchResult

/// <summary>
///  ������ ��� ������������ ����������� �������� op_fetch
/// </summary>
//! \todo
//!  ���������� ����� ��� �������� ���� ������� ��������������� � ����� �������
class RemoteFB__FetchResult:public RemoteFB__SmartMemoryObject
{
 private:
  typedef RemoteFB__FetchResult                               self_type;

  RemoteFB__FetchResult(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>            self_ptr;

  typedef unsigned char                                       byte_type;
  typedef size_t                                              size_type;

  typedef RemoteFB__MemoryAllocator                           allocator_type;

  typedef structure::t_typed_simple_buffer
            <byte_type,
             allocator_type>                                  msg_data_buffer_type;

  /// <summary>
  ///  ������������ ��������� �������� ��������� ������� � ��������
  /// </summary>
  enum tag_state
  {
   /// ������� �����������
   state__active    =0,

   /// ������� ���������. ���������� ��� ������ � ������� �������.
   state__completed =1,

   /// ������� ���������. ��������� ����� ��������������� ���������.
   state__eof       =2,

   /// ������� ��������� �� ������.
   state__failed    =3,
  };//enum tag_state

 public:
  /// ���������� �����, ����������� ��� �������� (op_fetch).
  const size_type m_RequestedFetchCount;

  /// ���������� ������������ ����� (op_fetch_response).
  size_type m_ProcessedFetchCount;

  /// ��������� ��������
  tag_state m_State;

  /// �������� ������ ������� ������
  t_ibp_error m_FetchErr;

 private:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] RequestedFetchCount
  //!  ��������� ���������� �����. ������ ���� ������ ����.
  //! \param[in] cbRowData
  //!  ������ ������ ����
  //! \param[in] cbRowDataAlign
  //!  ������������� ������� ��� ������ � ������� ����
  RemoteFB__FetchResult(size_type RequestedFetchCount,
                        size_type cbRowData,
                        size_type cbRowDataAlign);

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~RemoteFB__FetchResult();

 public:
  /// <summary>
  ///  ������� ������
  /// </summary>
  static self_ptr Create(size_type RequestedFetchCount,
                         size_type cbRowData,
                         size_type cbRowDataAlign);

  //interface ------------------------------------------------------------
  /// <summary>
  ///  ��������� ��������� (�����������) ����� � ������
  /// </summary>
  size_type ROWS__GetCount()const;

  /// <summary>
  ///  ��������� ������� ������ ���� � ������
  /// </summary>
  //! \note
  //!  ������ \b ����� ��� ������ ���� ����� ���� ������, ������ ��� � ����
  //!  �������� ������������� �����.
  size_type ROWS__GetDataSize()const;

  byte_type* ROWS__AllocBlock();

  const byte_type* ROWS__GetFirstBlock()const;

  void ROWS__FreeFirstBlock();

  void ROWS__FreeLastBlock();

  //----------------------------------------------------------------------
  /// <summary>
  ///  ����������������� ��� ������� ��������� ������ �������
  /// </summary>
  void Reactivate();

 private:
  /// ������ ������ ����
  size_type const m_cbRowData;

  /// ������ ����� ��� ������ ���� (m_cbRowData + ������������� ��������)
  size_type m_cbRowBlock;

 private:
  typedef structure::t_cycle_buffer_manager__num_traits<size_type>
   msg_data_buf_mng_traits_type;

  typedef structure::t_cycle_buffer_manager<msg_data_buf_mng_traits_type>
   msg_data_buf_mng_type;

 private:
  msg_data_buf_mng_type  m_RowsDataBufferManager;

  msg_data_buffer_type   m_RowsDataBuffer;
};//class RemoteFB__FetchResult

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement

/// <summary>
///  ������ �������.
/// </summary>
class RemoteFB__HandleData_Statement:public RemoteFB__SmartMemoryObject
{
 private:
  typedef RemoteFB__HandleData_Statement                      self_type;

  RemoteFB__HandleData_Statement(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  ������������� �������.
  /// </summary>
  static const GUID svcID;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>            self_ptr;

  typedef RemoteFB__SrvResourceID                             id_type;

  typedef handles::RemoteFB__HandleData_Transaction           tr_data_type;

 public:
  typedef unsigned short                                      flag_base_type;
  typedef RemoteFB__Flags<flag_base_type>                     flags_type;

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
  typedef RemoteFB__MemoryAllocator                        allocator_type;

  typedef structure::t_typed_simple_buffer
            <unsigned char,
             allocator_type>                               xsqlvars_data_buffer_type;

  typedef structure::t_typed_simple_buffer
            <unsigned char,
             allocator_type>                               msg_blr_buffer_type;

  typedef structure::t_typed_simple_buffer
            <unsigned char,
             allocator_type>                               msg_data_buffer_type;

  typedef structure::t_stl_vector
            <RemoteFB__MsgDataElementDescr,
             allocator_type>                               msg_data_descrs_type;

  typedef structure::t_typed_simple_buffer
            <unsigned char,
             allocator_type>                               msg_nulls_buffer_type;

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
};//class RemoteFB__HandleData_Statement

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement::tag_cn_list_adapter

/// <summary>
///  ������� ������ �������� �����������.
/// </summary>
class RemoteFB__HandleData_Statement::tag_cn_list_adapter
{
 private:
  typedef tag_cn_list_adapter                             self_type;

 public:
  typedef RemoteFB__HandleData_Statement                  node_type;
  typedef node_type*                                      node_ptr_type;

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
class RemoteFB__HandleData_Statement::tag_tr_list_adapter
{
 private:
  typedef tag_tr_list_adapter                             self_type;

 public:
  typedef RemoteFB__HandleData_Statement                  node_type;
  typedef node_type*                                      node_ptr_type;

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
class RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter
{
 private:
  typedef tag_nclosed_stmt_list_adapter                   self_type;

 public:
  typedef RemoteFB__HandleData_Statement                  node_type;
  typedef node_type*                                      node_ptr_type;

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
