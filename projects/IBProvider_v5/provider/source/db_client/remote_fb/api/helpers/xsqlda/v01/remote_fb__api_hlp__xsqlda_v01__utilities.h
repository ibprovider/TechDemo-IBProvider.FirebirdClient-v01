////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda_set01__utilities.h
//! \brief   ������� ��� ��������� XSQLDA / XSQLVAR (V1).
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#ifndef _remote_fb__api_hlp__xsqlda_v01__utilities_H_
#define _remote_fb__api_hlp__xsqlda_v01__utilities_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle_data__statement.h"
#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_V01__Utilities

/// <summary>
///  ������� ��� ��������� XSQLDA / XSQLVAR (V1).
/// </summary>
class RemoteFB__API_HLP__XSQLDA_V01__Utilities
{
 private:
  typedef RemoteFB__API_HLP__XSQLDA_V01__Utilities         self_type;

 public: //typedefs ------------------------------------------------------
  typedef unsigned char                                    byte_type;

  typedef std::pair<protocol::P_USHORT,bool>               parse_result_type;

  typedef handles::RemoteFB__HandleData_Statement          stmt_data_type;

  typedef stmt_data_type::msg_blr_buffer_type              msg_blr_buffer_type;

  typedef stmt_data_type::msg_nulls_buffer_type            msg_nulls_buffer_type;

  typedef stmt_data_type::msg_data_buffer_type             msg_data_buffer_type;

  typedef stmt_data_type::msg_data_descrs_type             msg_data_descrs_type;

  typedef msg_data_descrs_type::value_type                 msg_data_descr_type;

 public:
  /// <summary>
  ///  ��������� �������� XSQLDA.
  /// </summary>
  //! \param[in]     buffer_size
  //! \param[in]     buffer
  //! \param[in]     is_first_info_block
  //! \param[in]     start_index
  //! \param[in,out] pXSQLDA
  //!  Not NULL. ������ ��������� ����� 1.
  //! \return
  //!  ������ ��������� ������ ������. ����, ���� ��������� ���������.
  static parse_result_type Parse_XSQLDA
                             (size_t              buffer_size,
                              const byte_type*    buffer,
                              bool                is_first_info_block,
                              protocol::P_USHORT  start_index,
                              isc_api::XSQLDA_V1* pXSQLDA);

  /// <summary>
  ///  ���������� ������������� ������� ����� ������ ��� �������� ������ � XDR �������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \attention
  //!  ��������������, ��� ����������� ���������� pXSQLDA ���������.
  //!  ��� ����������� ���������.
  static size_t Calc_XSQLDA_MAX_XDR_SIZE
                             (const isc_api::XSQLDA_V1* pXSQLDA);

  /// <summary>
  ///  ������������ MSG-������ � BLR-��������� XSQLDA ���������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[in,out] BlrBuffer
  static void Build_XSQLDA_MSG_BLR
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_blr_buffer_type&      BlrBuffer);

  /// <summary>
  ///  ������������ MSG-������ � ������� XSQLDA ���������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[in,out] DataBuffer
  static void Build_XSQLDA_MSG_DATA
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_data_buffer_type&     DataBuffer);

  /// <summary>
  ///  Building descriptions with information about placing the data od XSQLDA-structure in a MSG-buffer.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[out] MsgDescrs
  //! \param[out] pResult_DataSize
  //!  The common size of a buffer for data. Not NULL.
  //! \param[out] pResult_DataAlign
  //!  The alignment of elements in the memory. Not null.
  //! \return
  static void Build_XSQLDA_MSG_DATA_DESCRS
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_data_descrs_type&     MsgDescrs,
                              size_t*                   pResult_DataSize,
                              size_t*                   pResult_DataAlign);

  /// <summary>
  ///  �������� ����������� ������ MSG-������ � XSQLDA ���������.
  /// </summary>
  //! \param[in]     MsgDescrs
  //! \param[in]     cbMsgData
  //! \param[in]     pMsgData
  //! \param[in,out] pXSQLDA
  //!  ��������� �� ���������� ��������� ��� ��������� ������. ����� ���� NULL ��� ������.
  //!
  //!  ���� ��������� pXSQLDA �� ��������. �������� ������ ������, �� ������� ��������� XSQLVAR-��������.
  //!
  //! \attention
  //!  ��������� MSG-������ ������ ���� ����������� � pXSQLDA.
  static void Parse_XSQLDA_MSG_DATA
                             (const msg_data_descrs_type& MsgDescrs,
                              size_t                      cbMsgData,
                              const byte_type*            pMsgData,
                              const isc_api::XSQLDA_V1*   pXSQLDA);

 public:
  /// <summary>
  ///  ��������� ������ ��� ����� � ������� NULL-��������� ������ XSQLDA ���������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[in,out] Nulls
  static void Alloc_XSQLDA_MSG_NULLS
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_nulls_buffer_type&    Nulls);

  /// <summary>
  ///  ������������ ������ � ������� NULL-��������� ������ XSQLDA ���������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[in,out] Nulls
  static void Build_XSQLDA_MSG_NULLS
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_nulls_buffer_type&    Nulls);

 private:
  static size_t Helper__Calc_XSQLDA_MAX_XDR_SIZE
                             (const isc_api::XSQLVAR_V1* pXSQLVAR);

 private:
  static size_t Helper__Build_XSQLDA_MSG_BLR__CalcBufSize
                             (const isc_api::XSQLDA_V1* pXSQLDA);

  static void Helper__Build_XSQLDA_MSG_BLR__FillBuf
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_blr_buffer_type&      MsgBlrBuffer);

 private:
  static size_t Helper__Build_XSQLDA_MSG_DATA__CalcBufSize
                             (const isc_api::XSQLDA_V1* pXSQLDA);

  static size_t Helper__Build_XSQLDA_MSG_DATA__CalcBufSize
                             (const isc_api::XSQLVAR_V1* pXSQLVAR,
                              size_t                     szMsg);

  static void Helper__Build_XSQLDA_MSG_DATA__FillBuf
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_data_buffer_type&     DataBuffer);

  static size_t Helper__Build_XSQLDA_MSG_DATA__FillBuf
                             (const isc_api::XSQLVAR_V1* pXSQLVAR,
                              msg_data_buffer_type&      DataBuffer,
                              size_t                     offset);
 private:
  static size_t Helper__Build_XSQLDA_MSG_DATA_DESCRS
                             (const isc_api::XSQLVAR_V1* pXSQLVAR,
                              size_t                     szMsg,
                              msg_data_descr_type&       MsgDescr,
                              size_t*                    pcbResultAlign);

 private:
  static void Helper__Parse_XSQLDA_MSG_DATA
                             (const msg_data_descr_type& MsgDescr,
                              size_t                     cbMsgData,
                              const byte_type*           pMsgData,
                              const isc_api::XSQLVAR_V1* pXSQLVAR);

 private:
  /// <summary>
  ///  ������ ������������� ������.
  /// </summary>
  //! \param[in]  beg
  //! \param[in]  end
  //! \param[out] pNumber
  //! \param[in]  tagSign
  //! \return
  //!  ��������� �� ����� ����� ������
  template<typename T>
  static const byte_type* Helper__ReadNumber
                             (const byte_type* beg,
                              const byte_type* end,
                              T*               pNumber,
                              const wchar_t*   tagSign);

  /// <summary>
  ///  ������ ��������� ������.
  /// </summary>
  //! \param[in]  beg
  //! \param[in]  end
  //! \param[in]  BufferLength
  //! \param[out] pBuffer
  //! \param[out] pActualLength
  //! \param[in]  tagSign
  //! \return
  //!  ��������� �� ����� ����� ������
  static const byte_type* Helper__ReadString
                             (const byte_type* beg,
                              const byte_type* end,
                              size_t           BufferLength,
                              char*            pBuffer,
                              short*           pActualLength,
                              const wchar_t*   tagSign);
 private:
  /// <summary>
  ///  ������������ � ���������� � ����� MSG-������
  /// </summary>
  //! \param[in] cbMsg
  //!  ������� ������ ������.
  //! \param[in] cbElement
  //!  ������ ������
  //! \param[in] cbAlign
  //!  ������� ������������ ������
  //! \param[in,out] pcbResultAlign
  //!  �������������� �������� ������������. Can be null.
  //! \return
  //!  ����������� ������ ������
  static size_t Helper__AddMsgLength
                             (size_t   cbMsg,
                              size_t   cbElement,
                              size_t   cbAlign,
                              size_t*  pcbResultAlign);

  static size_t Helper__AddMsgLength
                             (size_t cbMsg,
                              size_t cbElement);

  static size_t Helper__AlignMsgLength
                             (size_t   cbMsg,
                              size_t   cbAlign,
                              size_t*  pcbResultAlign);

 private:
  COMP_CONF_DECLSPEC_NORETURN
  static void Helper__ThrowBugCheck__UnexpectedTruncation
                             (const wchar_t* place,
                              const wchar_t* point,
                              size_t         sqld);

  COMP_CONF_DECLSPEC_NORETURN
  static void Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue
                             (const wchar_t* fieldName);

  COMP_CONF_DECLSPEC_NORETURN
  static void Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
                             (const wchar_t* fieldName);
};//class RemoteFB__API_HLP__XSQLDA_V01__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
