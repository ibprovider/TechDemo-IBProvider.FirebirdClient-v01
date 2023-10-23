////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__initialize_compressor.h
//! \brief   Утилиты подключения. Инициализация компрессора подключения.
//! \author  Kovalenko Dmitry
//! \date    07.01.2020
#ifndef _remote_fb__p13__initialize_compressor_H_
#define _remote_fb__p13__initialize_compressor_H_

#include "source/external/zlib1/ibp_external__zlib1__api_provider.h"

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////

using ZLIB1__ApiProviderPtr
 =ibp::external::zlib1::ZLIB1__ApiProviderPtr;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__InitializeCompressor

/// <summary>
///  Утилиты подключения. Инициализация компрессора подключения.
/// </summary>
class RemoteFB__P13__InitializeCompressor LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__P13__InitializeCompressor;

 public: //typedefs ------------------------------------------------------
  using port_type=ports::base_v01::RemoteFB__Port_BASE_v01;

 private:
  static const t_ibp_str_box c_default__ZLIB1_DLL;
 
 public:
  /// <summary>
  ///  Инициализация компрессора подключения. THROW.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] clientConnectBlock
  static void exec(port_type*                             pPort,
                   const RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

 private:
  static ZLIB1__ApiProviderPtr
           helper__create_zprovider
            (const RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

  static ZLIB1__ApiProviderPtr
           helper__create_zprovider__builtin
            ();

  static ZLIB1__ApiProviderPtr
           helper__create_zprovider__dll
            (const RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

  static ZLIB1__ApiProviderPtr
           helper__create_zprovider__dll
            (t_ibp_str_box DLL_Name);
};//class RemoteFB__P13__InitializeCompressor

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
