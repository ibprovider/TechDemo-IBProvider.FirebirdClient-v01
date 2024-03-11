////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_text_stream__mbc.h
//! \brief   Интерфейс потока мультибайтных символов
//! \author  Kovalenko Dmitry
//! \date    06.12.2008
#ifndef _db_text_stream__mbc_H_
#define _db_text_stream__mbc_H_

#include "source/db_obj/db_charset_result.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_db_text_stream__mbc

/// <summary>
///  Интерфейс потока мультибайтных символов
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_db_text_stream__mbc:public t_db_smart_interface
{
 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

 public:
  //interface ------------------------------------------------------------
  /// <summary>
  ///  Чтение символов
  /// </summary>
  //! \param[in]  op_ctx
  //! \param[in]  mbc_buffer_size
  //! \param[out] mbc_buffer
  //! \param[out] cch_readed
  //!  Not NULL
  //! \return
  //! - db_cs_result__ok
  //! - db_cs_result__fail
  //!
  //! \note
  //!  Если буфер заполнился не до конца, то считается что достигнут EOF
  virtual t_db_cs_result read_mbc(t_db_operation_context& op_ctx,
                                  size_type               mbc_buffer_size,
                                  char*                   mbc_buffer,
                                  size_type*              cch_readed)=0;
};//class t_db_text_stream__mbc

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
