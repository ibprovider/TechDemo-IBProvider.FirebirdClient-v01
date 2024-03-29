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
#include "source/structure/ibp_buffer_view.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_V01__Utilities

/// <summary>
///  ������� ��� ��������� XSQLDA / XSQLVAR (V1).
/// </summary>
class RemoteFB__API_HLP__XSQLDA_V01__Utilities LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__API_HLP__XSQLDA_V01__Utilities;

 public: //typedefs ------------------------------------------------------
  using byte_type=unsigned char;

  using parse_result_type=std::pair<protocol::P_USHORT,bool>;

  using stmt_data_type=handles::RemoteFB__HandleData_Statement;

  using msg_nulls_buffer_type=stmt_data_type::msg_nulls_buffer_type;

  using msg_data_descrs_type=stmt_data_type::msg_data_descrs_type;

  using msg_data_descr_type=msg_data_descrs_type::value_type;

  using msg_data_buf_view_type=IBP_BufferView<const byte_type>;

  using msg_data_descrs_view_type=IBP_BufferView<const msg_data_descr_type>;

 public:
  static void Check_XSQLDA(const isc_api::XSQLDA_V1* pXSQLDA,
                           protocol::P_SHORT         minSQLD,
                           t_ibp_subsystem_id        subsystemID,
                           const wchar_t*            pXSQLDA_Sign);

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
  ///  Allocating a memory for a buffer with the flags of NULL-states.
  /// </summary>
  //! \param[in] DataDescrs
  //! \param[in,out] Nulls
  static void Alloc_XSQLDA_MSG_NULLS
                             (const msg_data_descrs_view_type& DataDescrs,
                              msg_nulls_buffer_type&           Nulls);

 public:
  /// <summary>
  ///  ������������ ������ � ������� NULL-��������� ������ XSQLDA ���������.
  /// </summary>
  //! \param[in] pXSQLDA
  //!  Can be NULL.
  //! \param[in,out] Nulls
  static void Build_XSQLDA_MSG_NULLS
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_nulls_buffer_type&    Nulls);

  /// <summary>
  ///  ������������ ������ � ������� NULL-��������� ������ XSQLDA ���������.
  /// </summary>
  //! \param[in] DataDescrs
  //! \param[in] DataBuffer
  //! \param[in,out] Nulls
  static void Build_XSQLDA_MSG_NULLS
                             (const msg_data_descrs_view_type& DataDescrs,
                              const msg_data_buf_view_type&    DataBuffer,
                              msg_nulls_buffer_type&           Nulls);

 private:
  static size_t Helper__Calc_XSQLDA_MAX_XDR_SIZE
                             (const isc_api::XSQLVAR_V1* pXSQLVAR);

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
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Helper__ThrowBugCheck__UnexpectedTruncation
                             (const wchar_t* place,
                              const wchar_t* point,
                              size_t         sqld);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue
                             (const wchar_t* fieldName);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
                             (const wchar_t* fieldName);
};//class RemoteFB__API_HLP__XSQLDA_V01__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
