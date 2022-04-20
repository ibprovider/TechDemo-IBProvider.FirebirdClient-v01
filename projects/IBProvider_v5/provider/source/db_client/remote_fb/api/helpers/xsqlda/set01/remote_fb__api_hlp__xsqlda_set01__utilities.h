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

class RemoteFB__API_HLP__XSQLDA_SET01__Utilities
{
 private:
  typedef RemoteFB__API_HLP__XSQLDA_SET01__Utilities       self_type;

 public: //typedefs ------------------------------------------------------
  typedef unsigned char                                    byte_type;

  typedef handles::RemoteFB__HandleData_Statement          stmt_data_type;

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
  struct tag_skip_result
  {
   public:
    const byte_type* position;
    const byte_type* data_beg;
    const byte_type* data_end;
    bool             data_is_truncated;

   public:
    tag_skip_result(const byte_type* const _position,
                    const byte_type* const _data_beg,
                    const byte_type* const _data_end,
                    const bool             _data_is_truncated)
    :position          (_position)
    ,data_beg          (_data_beg)
    ,data_end          (_data_end)
    ,data_is_truncated (_data_is_truncated)
   {;}
  };//struct tag_skip_result

 private:
  /// <summary>
  ///  Пропуск блока с описанием колонок/параметров
  /// </summary>
  //! \param[in] beg
  //! \param[in] end
  //! \param[in] block_id
  //! \return
  //!  Блок с результатами работы.
  static tag_skip_result Helper__Skip_XSQLVARS_Info(const byte_type* beg,
                                                    const byte_type* end);

  static const byte_type* Helper__SkipElementData(const byte_type* beg,
                                                  const byte_type* end,
                                                  long             tagID);

  template<class TBuffer>
  static void Helper__SaveElementData(const byte_type* data_beg,
                                      const byte_type* data_end,
                                      bool             data_is_truncated,
                                      TBuffer&         buffer);
 private:
  COMP_CONF_DECLSPEC_NORETURN
  static void Helper__ThrowError__GetStmtInfo__NoData(const wchar_t* propSign);
};//class RemoteFB__API_HLP__XSQLDA_SET01__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
