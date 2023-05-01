////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__fetch_result.h
//! \brief   The class for handling a fetch operation result.
//! \author  Kovalenko Dmitry
//! \date    30.03.2023.
#ifndef _remote_fb__fetch_result_H_
#define _remote_fb__fetch_result_H_

#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/db_client/remote_fb/remote_fb__msg_data_element_descr.h"

#include <structure/stl/t_stl_vector.h>
#include <structure/t_simple_buffer.h>
#include <structure/t_cycle_buffer_manager.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//the content

class RemoteFB__FetchResult;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__FetchResult

/// <summary>
///  ������ ��� ������������ ����������� �������� op_fetch
/// </summary>
//! \todo
//!  ���������� ����� ��� �������� ���� ������� ��������������� � ����� �������
class RemoteFB__FetchResult LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__SmartMemoryObject
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
            <unsigned char,
             allocator_type>                                  msg_blr_buffer_type;

  typedef structure::t_stl_vector
            <RemoteFB__MsgDataElementDescr,
             allocator_type>                                  msg_data_descrs_type;

  typedef structure::t_typed_simple_buffer
            <byte_type,
             allocator_type>                                  msg_data_buffer_type;

  typedef structure::t_typed_simple_buffer
            <unsigned char,
             allocator_type>                                  msg_nulls_buffer_type;

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
  /// <summary>
  ///  ������������� �������.
  /// </summary>
  static const GUID svcID;

 public:
  /// BLR or fetched data.
  const msg_blr_buffer_type m_OutMSG_BLR;

  /// Data descriptors.
  const msg_data_descrs_type m_OutMSG_DATA_DESCRS;

  msg_nulls_buffer_type m_OutMSG_NULLS;

  /// ���������� �����, ����������� ��� �������� (op_fetch).
  const size_type m_RequestedFetchCount;

  /// ���������� ������������ ����� (op_fetch_response).
  size_type m_ProcessedFetchCount;

  /// ��������� ��������
  tag_state m_State;

  /// �������� ������ ������� ������
  std::exception_ptr m_spFetchExc;

 private:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in,out] OutMSG_BLR
  //! \param[in,out] OutMSG_DATA_DESCRS
  //! \param[in] RequestedFetchCount
  //!  ��������� ���������� �����. ������ ���� ������ ����.
  //! \param[in] cbRowData
  //!  ������ ������ ����
  //! \param[in] cbRowDataAlign
  //!  ������������� ������� ��� ������ � ������� ����
  RemoteFB__FetchResult(msg_blr_buffer_type&&  OutMSG_BLR,
                        msg_data_descrs_type&& OutMSG_DATA_DESCRS,
                        size_type              RequestedFetchCount,
                        size_type              cbRowData,
                        size_type              cbRowDataAlign);

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~RemoteFB__FetchResult();

 public:
  /// <summary>
  ///  ������� ������
  /// </summary>
  static self_ptr Create(msg_blr_buffer_type&&  OutMSG_BLR,
                         msg_data_descrs_type&& OutMSG_DATA_DESCRS,
                         size_type              RequestedFetchCount,
                         size_type              cbRowData,
                         size_type              cbRowDataAlign);

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
  static size_type Helper__CalcRowBlock(size_type cbRowData,size_type cbAlign);

 private:
  /// ������ ������ ����
  size_type const m_cbRowData;

  /// ������ ����� ��� ������ ���� (m_cbRowData + ������������� ��������)
  size_type const m_cbRowBlock;

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
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
