////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__array_slice_v01__utilities.h
//! \brief   Utilities for work with database arrays.
//! \author  Kovalenko Dmitry
//! \date    11.04.2023
#ifndef _remote_fb__api_hlp__array_slice_v01__utilities_H_
#define _remote_fb__api_hlp__array_slice_v01__utilities_H_

#include "source/db_client/remote_fb/remote_fb__array_slice_descr.h"
#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__ArraySlice_v01__Utilities

class RemoteFB__API_HLP__ArraySlice_v01__Utilities LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__API_HLP__ArraySlice_v01__Utilities     self_type;

 public: //typedefs ------------------------------------------------------
  typedef unsigned char                                    byte_type;

 public:
  /// <summary>
  ///  �������� SDL-�������� � ��������� RemoteFB__ArraySliceDescr
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
  ///  �������� �������� � ���� �������� �������
  /// </summary>
  //! \param[in]     sdlReader
  //! \param[in,out] pDescr
  static void Helper__ParseSDL__ReadElementType
                             (tag_sdl_reader&            sdlReader,
                              RemoteFB__ArraySliceDescr* pDescr);

  static value_i4_type Helper__ParseSDL__ReadLiteral
                             (tag_sdl_reader&            sdlReader);

  /// <summary>
  ///  ��������� ������ ���� ibp_isc_sdl_element
  /// </summary>
  static void Helper__ParseSDL__ReadElement
                             (tag_sdl_reader&            sdlReader,
                              RemoteFB__ArraySliceDescr* pDescr);
};//class RemoteFB__API_HLP__ArraySlice_v01__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
