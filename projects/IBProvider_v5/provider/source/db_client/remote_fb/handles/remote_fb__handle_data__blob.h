////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle_data__blob.h
//! \brief   ����������� ��� ������������� ������ ����������� �����.
//! \author  Kovalenko Dmitry
//! \date    11.09.2015
#ifndef _remote_fb__handle_data__blob_H_
#define _remote_fb__handle_data__blob_H_

#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_client/remote_fb/remote_fb__srv_resource_id.h"
#include "source/error_services/ibp_error.h"
#include <structure/t_simple_buffer.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__handles
//! @{
////////////////////////////////////////////////////////////////////////////////
//the content

class RemoteFB__HandleData_Blob;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Blob

/// <summary>
///  ������ �����.
/// </summary>
class RemoteFB__HandleData_Blob:public RemoteFB__SmartMemoryObject
{
 private:
  typedef RemoteFB__HandleData_Blob                         self_type;

  RemoteFB__HandleData_Blob(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>          self_ptr;

  typedef RemoteFB__SrvResourceID                           id_type;

  typedef handles::RemoteFB__HandleData_Transaction         tr_data_type;

  typedef RemoteFB__MemoryAllocator                         allocator_type;

  typedef structure::t_void_simple_buffer<allocator_type>   buffer_type;

  enum enumBlobMode
  {
   BlobMode__Open=1,
   BlobMode__Create=2,
  };

  enum enumReadState
  {
   ReadState__None        =0, //������������ ��� ��������� ������� ������
   ReadState__Ok          =1,
   ReadState__Segment     =2,
   ReadState__EofPending  =3,
   ReadState__Failed      =4,
  };

  enum enumWriteState
  {
   WriteState__None        =0,
   WriteState__Failed      =4,
  };

 public:
  class tag_tr_list_adapter;
  class tag_nclosed_blob_list_adapter;

 private:
  /// <summary>
  ///  ����������� �� ���������
  /// </summary>
  //! \param[in] BlobMode
  RemoteFB__HandleData_Blob(enumBlobMode BlobMode);

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~RemoteFB__HandleData_Blob();

 public:
  /// ����� ������������� ����������� �����. ������������ ��� ��������������� �������.
  const enumBlobMode m_BlobMode;

  /// ������������ ���������� �����
  tr_data_type*   m_pParentTr;

  //��������������� ������ ������ ����������
  self_type*      m_pPrevTrBlob;
  self_type*      m_pNextTrBlob;

 public:
  /// DEBUG: ��������� �� ��������� ������ (���������) ���������� ������ �����������.
  RemoteFB__ConnectorData* m_pOwnerCnNClosedBlobList;

  //��������������� ������ ���������� ������ �����������
  self_type*      m_pPrevCnNClosedBlob;
  self_type*      m_pNextCnNClosedBlob;

 public:
  /// ��������� ������������� �����
  id_type         m_ID;

  /// ����� ��� ������/������ ������ �����
  buffer_type     m_Buffer;

 public:
  /// ������ ������. ���������� ���������� ������ � m_Buffer.
  buffer_type::size_type m_ReadMode__BufferActualSize;

  /// ������ ������. ������� ������� � ������ � ������� �����.
  buffer_type::size_type m_ReadMode__BufferPos;

  /// ������ ������. ���������� ������ �� ����� ����� (��������) ������
  buffer_type::size_type m_ReadMode__FragmentTailSize;

  /// ������ ������. ��������� �������� �������� ������.
  enumReadState m_ReadMode__State;

 public:
  /// ������ ������. ������� ������� � ������ � ������� �����.
  buffer_type::size_type m_WriteMode__BufferPos;

  /// ������ ������. ��������� �������� ������ ������.
  enumWriteState m_WriteMode__State;

 public:
  /// ������� ������ �������� � ������.
  t_ibp_error m_Err;

 public:
  /// <summary>
  ///  ������� ������
  /// </summary>
  //! \param[in] BlobMode
  static self_ptr Create(enumBlobMode BlobMode);

  /// <summary>
  ///  ������������ �������� �����������.
  /// </summary>
  //! \attention
  //!  ���� ����� ����� ���������� ��������� ������ �� ������!
  void Dangerous__DropHandle();
};//class RemoteFB__HandleData_Blob

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Blob::tag_tr_list_adapter

/// <summary>
///  ������� ������ ������ ����������.
/// </summary>
class RemoteFB__HandleData_Blob::tag_tr_list_adapter
{
 private:
  typedef tag_tr_list_adapter                             self_type;

 public:
  typedef RemoteFB__HandleData_Blob                  node_type;
  typedef node_type*                                      node_ptr_type;

 public:
  tag_tr_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Blob::tag_tr_list_adapter

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter

/// <summary>
///  ������� ������ ���������� ������ �����������.
/// </summary>
class RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter
{
 private:
  typedef tag_nclosed_blob_list_adapter              self_type;

 public:
  typedef RemoteFB__HandleData_Blob                  node_type;
  typedef node_type*                                 node_ptr_type;

 public:
  tag_nclosed_blob_list_adapter();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms handles*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif