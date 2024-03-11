////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda_set01__utilities.h
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#ifndef _remote_fb__api_hlp__xsqlda_set01__utilities_H_
#define _remote_fb__api_hlp__xsqlda_set01__utilities_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle_data__statement.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_SET01__Utilities

class RemoteFB__API_HLP__XSQLDA_SET01__Utilities LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__API_HLP__XSQLDA_SET01__Utilities;

 public: //typedefs ------------------------------------------------------
  using byte_type=unsigned char;

  using stmt_data_type=handles::RemoteFB__HandleData_Statement;

 public:
  /// <summary>
  ///  Теги запрашиваемых информационных данных подготавливаемого запроса.
  /// </summary>
  static const byte_type sm_sql_info__prepare[26];

  /// <summary>
  ///  Теги запрашиваемых информационных данных колонок запроса.
  /// </summary>
  static const byte_type sm_sql_info__describe[12];

  /// <summary>
  ///  Теги запрашиваемых информационных данных параметров запроса.
  /// </summary>
  static const byte_type sm_sql_info__describe_bind[12];

 public:
/// <summary>
  ///  Обработка сведений о запросе
  /// </summary>
  //! \param[in] pStmt
  //!  Not null.
  //! \param[in] szBuf
  //! \param[in] pBuf
  static void Process_PrepareInfoBuf(stmt_data_type*  pStmt,
                                     size_t           szBuf,
                                     const byte_type* pBuf);

 private:
  template<class TBuffer>
  static void Helper__SaveElementData(const byte_type* data_beg,
                                      const byte_type* data_end,
                                      bool             data_is_truncated,
                                      TBuffer&         buffer);
 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Helper__ThrowError__GetStmtInfo__NoData(const wchar_t* propSign);
};//class RemoteFB__API_HLP__XSQLDA_SET01__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
