////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_text_stream__ucs2.h
//! \brief   Интерфейс потока UCS2-символов
//! \author  Kovalenko Dmitry
//! \date    06.12.2008
#ifndef _db_text_stream__ucs2_H_
#define _db_text_stream__ucs2_H_

#include "source/db_obj/db_charset_result.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_db_text_stream__ucs2

/// <summary>
///  Интерфейс потока UCS2-символов
/// </summary>
//! \todo
//!  Перевести интерфейс на t_db_smart_interface
class t_db_text_stream__ucs2:public t_db_smart_interface
{
 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

 public:
  //interface ------------------------------------------------------------
  /// <summary>
  ///  Чтение UCS2-символов
  /// </summary>
  //! \param[in]  ucs2_buffer_size
  //! \param[out] ucs2_buffer
  //! \param[out] cch_readed
  //!  Not NULL
  //! \return
  //! - db_cs_result__ok
  //! - db_cs_result__fail
  //!
  //! \note
  //!  Если буфер заполнился не до конца, то считается что достигнут EOF
  virtual t_db_cs_result read_ucs2(size_type  ucs2_buffer_size,
                                   wchar_t*   ucs2_buffer,
                                   size_type* cch_readed)=0;
};//class t_db_text_stream__ucs2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
