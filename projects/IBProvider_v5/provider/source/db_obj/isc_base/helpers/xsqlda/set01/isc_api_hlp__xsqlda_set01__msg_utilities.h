////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_api_hlp__xsqlda_set01__msg_utilities.h
//! \brief   M-утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    07.02.2023
#ifndef _isc_api_hlp__xsqlda_set01__utilities_H_
#define _isc_api_hlp__xsqlda_set01__utilities_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle_data__statement.h"

namespace lcpi{namespace ibp{namespace isc_base{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class ISC_API_HLP__XSQLDA_SET01__MsgUtilities

class ISC_API_HLP__XSQLDA_SET01__MsgUtilities
{
 private:
  typedef ISC_API_HLP__XSQLDA_SET01__MsgUtilities          self_type;

 public: //typedefs ------------------------------------------------------
  typedef unsigned char                                    byte_type;

 public:
  struct tag_skip_result LCPI_CPP_CFG__CLASS__FINAL
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
                    bool             const _data_is_truncated)
     :position          (_position)
     ,data_beg          (_data_beg)
     ,data_end          (_data_end)
     ,data_is_truncated (_data_is_truncated)
    {
    }
  };//struct tag_skip_result

 public:
  /// <summary>
  ///  Skipping a block with column/parameter description.
  /// </summary>
  //! \param[in] beg
  //! \param[in] end
  //! \param[in] block_id
  //! \return
  //!  A block with the work result.
  static tag_skip_result Skip_XSQLVARS_Info
                             (const byte_type* beg,
                              const byte_type* end);
};//class ISC_API_HLP__XSQLDA_SET01__MsgUtilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
