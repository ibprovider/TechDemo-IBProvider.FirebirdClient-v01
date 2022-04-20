////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__xsqlda_utilities.h
//! \brief   ������� ��� ��������� XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#ifndef _remote_fb__p13__xsqlda_utilities_H_
#define _remote_fb__p13__xsqlda_utilities_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle_data__statement.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__XSQLDA_Utilities

/// <summary>
///  ������� ��� ��������� XSQLDA / XSQLVAR.
/// </summary>
class RemoteFB__P13__XSQLDA_Utilities LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P13__XSQLDA_Utilities                  self_type;

 public: //typedefs ------------------------------------------------------
  typedef unsigned char                                    byte_type;

  typedef handles::RemoteFB__HandleData_Statement          stmt_data_type;

  typedef stmt_data_type::msg_blr_buffer_type              msg_blr_buffer_type;

  typedef stmt_data_type::msg_nulls_buffer_type            msg_nulls_buffer_type;

  typedef stmt_data_type::msg_data_buffer_type             msg_data_buffer_type;

  typedef stmt_data_type::msg_data_descrs_type             msg_data_descrs_type;

  typedef msg_data_descrs_type::value_type                 msg_data_descr_type;

 public:
  /// <summary>
  ///  ���������� ������������� ������� ����� ������ ��� �������� ������ � XDR �������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \attention
  //!  ��������������, ��� ����������� ���������� pXSQLDA ���������.
  //!  ��� ����������� ���������.
  static size_t Calc_XSQLDA_MAX_XDR_SIZE(const isc_api::XSQLDA_V1* pXSQLDA);

  /// <summary>
  ///  ������������ MSG-������ � BLR-��������� XSQLDA ���������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[in,out] BlrBuffer
  static void Build_XSQLDA_MSG_BLR(const isc_api::XSQLDA_V1* pXSQLDA,
                                   msg_blr_buffer_type&      BlrBuffer);

  /// <summary>
  ///  ������������ MSG-������ � ������� XSQLDA ���������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[in,out] DataBuffer
  static void Build_XSQLDA_MSG_DATA(const isc_api::XSQLDA_V1* pXSQLDA,
                                    msg_data_buffer_type&     DataBuffer);

  /// <summary>
  ///  ��������� ������ ��� ����� � ������� NULL-��������� ������ XSQLDA ���������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[in,out] Nulls
  static void Alloc_XSQLDA_MSG_NULLS(const isc_api::XSQLDA_V1* pXSQLDA,
                                     msg_nulls_buffer_type&    Nulls);

  /// <summary>
  ///  ������������ ������ � ������� NULL-��������� ������ XSQLDA ���������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[in,out] Nulls
  static void Build_XSQLDA_MSG_NULLS(const isc_api::XSQLDA_V1* pXSQLDA,
                                     msg_nulls_buffer_type&    Nulls);

  /// <summary>
  ///  ������������ �������� ���������� ������ XSQLDA ��������� � MSG-������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[out] MsgDescrs
  //! \param[out] pResult_DataSize
  //!  ����� ������ ������ ��� ������. Not NULL.
  //! \param[out] pResult_DataAlign
  //!  ������������ ��������� � ������. Not null.
  //! \return
  static void Build_XSQLDA_MSG_DATA_DESCRS(const isc_api::XSQLDA_V1* pXSQLDA,
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
  static void Parse_XSQLDA_MSG_DATA(const msg_data_descrs_type& MsgDescrs,
                                    size_t                      cbMsgData,
                                    const byte_type*            pMsgData,
                                    const isc_api::XSQLDA_V1*   pXSQLDA);

 private:
  static size_t Helper__Build_XSQLDA_MSG_BLR__CalcBufSize(const isc_api::XSQLDA_V1* pXSQLDA);

  static void Helper__Build_XSQLDA_MSG_BLR__FillBuf(const isc_api::XSQLDA_V1* pXSQLDA,
                                                    msg_blr_buffer_type&      MsgBlrBuffer);

 private:
  static size_t Helper__Build_XSQLDA_MSG_DATA__CalcBufSize(const isc_api::XSQLDA_V1* pXSQLDA);

  static size_t Helper__Build_XSQLDA_MSG_DATA__CalcBufSize(const isc_api::XSQLVAR_V1* pXSQLVAR,
                                                           size_t                     szMsg);

  static void Helper__Build_XSQLDA_MSG_DATA__FillBuf(const isc_api::XSQLDA_V1* pXSQLDA,
                                                     msg_data_buffer_type&     DataBuffer);

  static size_t Helper__Build_XSQLDA_MSG_DATA__FillBuf(const isc_api::XSQLVAR_V1* pXSQLVAR,
                                                       msg_data_buffer_type&      DataBuffer,
                                                       size_t                     offset);
 private:
  static size_t Helper__Build_XSQLDA_MSG_DATA_DESCRS(const isc_api::XSQLVAR_V1* pXSQLVAR,
                                                     size_t                     szMsg,
                                                     msg_data_descr_type&       MsgDescr,
                                                     size_t*                    pcbResultAlign);

 private:
  static void Helper__Parse_XSQLDA_MSG_DATA(const msg_data_descr_type& MsgDescr,
                                            size_t                     cbMsgData,
                                            const byte_type*           pMsgData,
                                            const isc_api::XSQLVAR_V1* pXSQLVAR);

 private:
  static size_t Helper__Calc_XSQLDA_MAX_XDR_SIZE(const isc_api::XSQLVAR_V1* pXSQLVAR);

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
  static size_t Helper__AddMsgLength(size_t   cbMsg,
                                     size_t   cbElement,
                                     size_t   cbAlign,
                                     size_t*  pcbResultAlign);

  static size_t Helper__AddMsgLength(size_t cbMsg,
                                     size_t cbElement);

  static size_t Helper__AlignMsgLength(size_t   cbMsg,
                                       size_t   cbAlign,
                                       size_t*  pcbResultAlign);
};//class RemoteFB__P13__XSQLDA_Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
