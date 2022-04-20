////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__array_slice_utilities.h
//! \brief   Набор утилит для работы с массивами базы данных.
//! \author  Kovalenko Dmitry
//! \date    24.09.2016
#ifndef _remote_fb__p13__array_slice_utilities_H_
#define _remote_fb__p13__array_slice_utilities_H_

#include "source/db_client/remote_fb/remote_fb__array_slice_descr.h"
#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__ArraySlice_Utilities

class RemoteFB__P13__ArraySlice_Utilities LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P13__ArraySlice_Utilities              self_type;

 public: //typedefs ------------------------------------------------------
  typedef unsigned char                                    byte_type;

 public:
  /// <summary>
  ///  Загрузка SDL-описания в структуру RemoteFB__ArraySliceDescr
  /// <summary>
  //! \param[in]  opCtx
  //! \param[in]  szSDL
  //! \param[in]  pSDL
  //! \param[out] pDescr
  //!  Not null.
  static void ParseSDL(db_obj::t_db_operation_context&  opCtx,
                       size_t                           szSDL,
                       const byte_type*                 pSDL,
                       RemoteFB__ArraySliceDescr*       pDescr);

 private:
  typedef signed __int32                                 value_i4_type;

  typedef helpers::RemoteFB__API_HLP__ArraySdlReader     tag_sdl_reader;

 private:
  /// <summary>
  ///  Загрузка сведений о типе элемента массива
  /// </summary>
  //! \param[in]     sdlReader
  //! \param[in,out] pDescr
  static void Helper__ParseSDL__ReadElementType
                                           (tag_sdl_reader&            sdlReader,
                                            RemoteFB__ArraySliceDescr* pDescr);

  static value_i4_type Helper__ParseSDL__ReadLiteral
                                           (tag_sdl_reader& sdlReader);

  /// <summary>
  ///  Обработка данных тега ibp_isc_sdl_element
  /// </summary>
  static void Helper__ParseSDL__ReadElement(tag_sdl_reader&            sdlReader,
                                            RemoteFB__ArraySliceDescr* pDescr);
};//class RemoteFB__P13__ArraySlice_Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif