////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle_data__transaction.h
//! \brief   ����������� ��� ������������� ������ ����������� ����������.
//! \author  Kovalenko Dmitry
//! \date    16.02.2015
#ifndef _remote_fb__handle_data__transaction_H_
#define _remote_fb__handle_data__transaction_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle_data__statement.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle_data__blob.h"
//#include "source/db_client/remote_fb/remote_fb__srv_resource_id.h"
//#include "source/db_client/remote_fb/remote_fb__memory.h"
//#include "source/db_client/remote_fb/remote_fb__forward.h"
#include <lcpi/lib/structure/t_list_external.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__handles
//! @{
////////////////////////////////////////////////////////////////////////////////
//the content

class RemoteFB__HandleData_Transaction;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Transaction

/// <summary>
///  ������ ����������.
/// </summary>
class RemoteFB__HandleData_Transaction LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__SmartMemoryObject
{
 private:
  using self_type=RemoteFB__HandleData_Transaction;

  RemoteFB__HandleData_Transaction(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  using id_type=RemoteFB__SrvResourceID;

  using stmt_data_type=RemoteFB__HandleData_Statement;

  using blob_data_type=RemoteFB__HandleData_Blob;

  class tag_list_adapter;

 private:
  /// <summary>
  ///  ����������� ��-���������.
  /// </summary>
  RemoteFB__HandleData_Transaction();

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~RemoteFB__HandleData_Transaction();

 public:
  /// ������������ ������ �����������
  RemoteFB__Port* m_pParentPort;

 public: //��������������� ������ ���������� �����������
  self_type*  m_pPrevTr;
  self_type*  m_pNextTr;

 public:
  /// ��������� ������������� ����������
  id_type     m_ID;

 public:
  /// <summary>
  ///  ������� ������
  /// </summary>
  static self_ptr Create();

 public:
  /// <summary>
  ///  ���������� � m_Statements. No Throw.
  /// </summary>
  //! \param[in] phStmtData
  //!  Not null.
  void StmtList__Add(stmt_data_type* phStmtData);

  /// <summary>
  ///  �������� �� m_Statements. No Throw.
  /// </summary>
  //! \param[in] phStmtData
  //!  Not null.
  void StmtList__Remove(stmt_data_type* phStmtData);

 public:
  /// <summary>
  ///  ���������� � m_NotClosedStatements. No Throw.
  /// </summary>
  //! \param[in] phStmtData
  //!  Not null.
  void NotClosedStmtList__Add(stmt_data_type* phStmtData);

  /// <summary>
  ///  �������� �� m_NotClosedStatements. No Throw.
  /// </summary>
  //! \param[in] phStmtData
  //!  Not null.
  void NotClosedStmtList__Remove(stmt_data_type* phStmtData);

 public:
  /// <summary>
  ///  ���������� � m_Blobs. No Throw.
  /// </summary>
  //! \param[in] phBlobData
  //!  Not null.
  void BlobList__Add(blob_data_type* phBlobData);

  /// <summary>
  ///  �������� �� m_Blobs. No Throw.
  /// </summary>
  //! \param[in] phBlobData
  //!  Not null.
  void BlobList__Remove(blob_data_type* phBlobData);

 public:
  /// <summary>
  ///  ������� � ���������� ��������� �������� ����������
  /// </summary>
  void CleanupTrResources();

 private:
  /// <summary>
  ///  ������������ ���� ��������, ����������� � ����������
  /// </summary>
  void Helper__ReleaseAllResources();

 private: //typedefs -----------------------------------------------------
  using stmt_list_traits
   =stmt_data_type::tag_tr_list_adapter;

  using stmt_list_type
   =lib::structure::t_list_external<stmt_list_traits>;

  using nclosed_stmt_list_traits
   =stmt_data_type::tag_nclosed_stmt_list_adapter;

  using nclosed_stmt_list_type
   =lib::structure::t_list_external<nclosed_stmt_list_traits>;

  using blob_list_traits
   =blob_data_type::tag_tr_list_adapter;

  using blob_list_type
   =lib::structure::t_list_external<blob_list_traits>;

#ifdef IBP_BUILD_TESTCODE
 public:
#else
 private:
#endif
  /// <summary>
  ///  ������ ��������, ����������� � ����������.
  /// </summary>
  //! \note
  //!  �������� ������ ����������� � ������.
  stmt_list_type m_Statements;

  /// <summary>
  ///  ������ ���������� ��������, ����������� � ����������.
  /// </summary>
  //! \note
  //!  �������� ������ ����������� � ������.
  nclosed_stmt_list_type m_NotClosedStatements;

  /// <summary>
  ///  ������ ������, ����������� � ����������.
  /// </summary>
  //! \note
  //!  �������� ������ ����������� � ������.
  //! \note
  //!  � ������ ����� ��������� �������, ����������� �������� ������� ���� ��������.
  blob_list_type m_Blobs;
};//class RemoteFB__HandleData_Transaction

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Transaction::tag_list_adapter

/// <summary>
///  ������� ������ ���������� �����������.
/// </summary>
class RemoteFB__HandleData_Transaction::tag_list_adapter LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_list_adapter;

 public:
  using node_type    =RemoteFB__HandleData_Transaction;
  using node_ptr_type=node_type*;

 public:
  tag_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Transaction::tag_list_adapter

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms handles*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
