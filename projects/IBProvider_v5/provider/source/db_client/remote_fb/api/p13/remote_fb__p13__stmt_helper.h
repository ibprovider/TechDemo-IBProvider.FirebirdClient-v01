////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__stmt_helper.h
//! \brief   Вспомогательный класс с кодом для работы с запросами.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#ifndef _remote_fb__p13__stmt_helper_H_
#define _remote_fb__p13__stmt_helper_H_

#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle__statement.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__StmtHelper

/// <summary>
///  Вспомогательный класс с кодом для работы с запросами.
/// </summary>
class RemoteFB__P13__StmtHelper LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P13__StmtHelper             self_type;

 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__TrHandle           tr_handle_type;
  typedef handles::RemoteFB__StmtHandle         stmt_handle_type;

  typedef tr_handle_type::item_type             tr_data_type;
  typedef stmt_handle_type::item_type           stmt_data_type;

  typedef structure::t_const_str_box            sql_str_box_type;

 public:
  /// <summary>
  ///  Подготовка пакета для op_prepare_statement
  /// </summary>
  //! \param[out] pPacket
  //!  Not null
  //! \param[in]  pTrHandle
  //! \param[in]  stmtID
  //! \param[in]  SQL_dialect
  //! \param[in]  SQL_str
  static void BuildPacket__op_prepare_statement
               (protocol::set02::PACKET_V02*  pPacket,
                tr_handle_type*               pTrHandle,
                protocol::P_OBJCT             stmtID,
                protocol::P_USHORT            SQL_dialect,
                sql_str_box_type              SQL_str);

  /// <summary>
  ///  Подготовка пакета для op_execute
  /// </summary>
  //! \param[out] pPacket
  //!  Not null
  //! \param[in]  pTr
  //! \param[in]  pStmt
  //!  Not null
  static void BuildPacket__op_execute
               (protocol::set02::PACKET_V02*  pPacket,
                tr_data_type*                 pTr,
                stmt_data_type*               pStmt);

  /// <summary>
  ///  Вычисляем оптимальное количество записей для групповой загрузки
  /// </summary>
  //! \param[in] szMsgData
  static protocol::P_USHORT ComputeBatchSize(size_t szMsgData);

 private:
  static size_t Helper__ComputePacketNumber(size_t cRows,
                                            size_t cbPacket,
                                            size_t cbPacket0);
};//class RemoteFB__P13__StmtHelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
