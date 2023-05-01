////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__error_utils.cpp
//! \brief   Набор вспомогательных утилит для обработки ошибок.
//! \author  Kovalenko Dmitry
//! \date    15.02.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_client/remote_fb/ports/remote_fb__port.h"

#include "source/oledb/ibp_oledb__prop__names.h"

#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error_messages.h"
#include "source/ibp_utils.h"

#include <structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ErrorUtils

void RemoteFB__ErrorUtils::Throw__RequestedProtocolNotSupported
                                       (subsystem_id_type  const subsystem_id,
                                        wstr_box_type      const protocolID)
{
 self_type::Throw__Error
  (DB_E_NOTSUPPORTED,
   subsystem_id,
   ibp_mce_remote__requested_protocol_not_supported_1,
   protocolID);
}//Throw__RequestedProtocolNotSupported

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__UnsupportedProtocolTypeID
                                       (subsystem_id_type const subsystem_id,
                                        unsigned          const protocolVersionNum,
                                        unsigned          const protocolTypeID)
{
 self_type::Throw__Error
  (DB_E_NOTSUPPORTED,
   subsystem_id,
   ibp_mce_remote__unsupported_protocol_type_2,
   protocolTypeID,
   protocolVersionNum);
}//Throw__UnsupportedProtocolTypeID

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__ReqProtocolTypeIdDoesNotSupported
                                       (subsystem_id_type  const subsystem_id,
                                        unsigned           const protocolVersionNum,
                                        wstr_box_type      const protocolTypeSign)
{
 self_type::Throw__Error
  (DB_E_NOTSUPPORTED,
   subsystem_id,
   ibp_mce_remote__requested_protocol_type_not_supported_2,
   protocolTypeSign,
   protocolVersionNum);
}//Throw__ReqProtocolTypeIdDoesNotSupported

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__UnsupportedProtocolFlags
                                       (subsystem_id_type const subsystem_id,
                                        unsigned          const protocolVerNum,
                                        unsigned          const protocolFlags)
{
 self_type::Throw__Error
  (DB_E_NOTSUPPORTED,
   subsystem_id,
   ibp_mce_remote__unsupported_protocol_flags_2,
   protocolFlags,
   protocolVerNum);
}//Throw__UnsupportedProtocolFlags

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__ServerRejectedConnectionCompression
                                       (subsystem_id_type const subsystem_id)
{
 self_type::Throw__Error
  (DB_E_NOTSUPPORTED,
   subsystem_id,
   ibp_mce_remote__server_rejected_cn_compression_0);
}//Throw__ServerRejectedConnectionCompression

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__ServerRequiredConnectionCompression
                                       (subsystem_id_type const subsystem_id)
{
 self_type::Throw__Error
  (DB_E_NOTSUPPORTED,
   subsystem_id,
   ibp_mce_remote__server_required_cn_compression_0);
}//Throw__ServerRequiredConnectionCompression

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__UnsupportedWireCompressionType
                                       (subsystem_id_type const subsystem_id,
                                        wstr_box_type     const typeName)
{
 self_type::Throw__Error
  (DB_E_NOTSUPPORTED,
   subsystem_id,
   ibp_mce_remote__unsupported_wire_compression_type_1,
   typeName);
}//Throw__UnsupportedWireCompressionType

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__OpStatusVectorProcessingError
                                       (subsystem_id_type    const subsystem_id,
                                        p_operation_id_type  const operationID,
                                        const wchar_t*       const place,
                                        const wchar_t*       const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_isc__op_status_vector_processing_error_3,
   operationID,
   place,
   point);
}//Throw__OpStatusVectorProcessingError

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedPacketStructure
                                           (const wchar_t*            const place,
                                            const wchar_t*            const point,
                                            protocol::PROTOCOL_SET_ID const actualProtocolSetID,
                                            protocol::PROTOCOL_SET_ID const expectedProtocolSetID)
{
 assert(place);
 assert(point);
 assert(actualProtocolSetID!=expectedProtocolSetID);

 assert_msg(false,
            "actualProtocolSetID: "<<actualProtocolSetID<<". "
            "expectedProtocolSetID: "<<expectedProtocolSetID);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_remote__bug_check__unexpected_packet_structure_4,
   place,
   point,
   structure::to_underlying(actualProtocolSetID),
   structure::to_underlying(expectedProtocolSetID));
}//Throw_BugCheck_UnexpectedPacketStructure

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_AcceptedUnexpectedProtocolVersion
                                           (const wchar_t*               const place,
                                            const wchar_t*               const point,
                                            protocol::P_PROTOCOL_VERSION const protocolVersion)
{
 assert(place);
 assert(point);

 assert_msg(false,"protocolVersion: "<<protocolVersion);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_remote__bug_check__accepted_unexpected_protocol_version_3,
   place,
   point,
   protocolVersion);
}//Throw_BugCheck_AcceptedUnexpectedProtocolVersion

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_AcceptedUnexpectedProtocolArchitecture
                                           (const wchar_t*   const place,
                                            const wchar_t*   const point,
                                            protocol::P_ARCH const protocolArchitecture)
{
 assert(place);
 assert(point);

 assert_msg(false,"protocolArchitecture: "<<protocolArchitecture);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_remote__bug_check__accepted_unexpected_protocol_arhitecture_3,
   place,
   point,
   protocolArchitecture);
}//Throw_BugCheck_AcceptedUnexpectedProtocolArchitecture

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
                                           (RemoteFB__Port*      const pPort,
                                            const wchar_t*       const place,
                                            const wchar_t*       const point,
                                            p_operation_id_type  const answerID)
{
 assert(pPort);
 assert(place);
 assert(point);

 assert_msg(false,"answerID: "<<answerID);

 try // перехват исключения и перевод порта в недействительное состояние
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_remote__bug_check__unexpected_answer_from_server_3,
    place,
    point,
    answerID);
 }
 catch(...)
 {
  RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pPort);

#if(COMP_BUILD_UNUSED_CODE)
  assert_hint(false);
#endif
 }//catch
}//SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck2_UnexpectedServerAnswer
                                           (t_ibp_error&               Errors,
                                            RemoteFB__Port*      const pPort,
                                            const wchar_t*       const place,
                                            const wchar_t*       const point,
                                            p_operation_id_type  const answerID)
{
 assert(pPort);
 assert(place);
 assert(point);

 assert_msg(false,"answerID: "<<answerID);

 try // перехват исключения и перевод порта в недействительное состояние
 {
  const t_ibp_error_element::self_ptr
   spErrRec
    (structure::not_null_ptr
      (new t_ibp_error_element
        (E_FAIL,
         ibp_mce_remote__bug_check__unexpected_answer_from_server_3)));

  assert(spErrRec);

  (*spErrRec)
     <<place
     <<point
     <<answerID;

  Errors.add_error(spErrRec); //throw

  Errors.set_last_error_as_primary();

  Errors.raise_me(E_FAIL);
 }
 catch(...)
 {
  RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pPort);

#if(COMP_BUILD_UNUSED_CODE)
  assert_hint(false);
#endif
 }//catch
}//SetInvalidPortState_And_Throw_BugCheck2_UnexpectedServerAnswer

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedProtocolVersion
                                           (const wchar_t*               const place,
                                            const wchar_t*               const point,
                                            protocol::P_PROTOCOL_VERSION const protocolVersion)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__unexpected_protocol_version_1,
   protocolVersion);
}//Throw_BugCheck_UnexpectedProtocolVersion

////////////////////////////////////////////////////////////////////////////////

void RemoteFB__ErrorUtils::Throw_BugCheck_BadCnHandle(const wchar_t* const place,
                                                      const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__bad_cn_handle_0);
}//Throw_BugCheck_BadCnHandle

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle(const wchar_t* const place,
                                                      const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__bad_tr_handle_0);
}//Throw_BugCheck_BadTrHandle

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_TrHandleNotZero(const wchar_t* const place,
                                                          const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__tr_handle_not_zero_0);
}//Throw_BugCheck_TrHandleNotZero

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle(const wchar_t* const place,
                                                        const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__bad_stmt_handle_0);
}//Throw_BugCheck_BadStmtHandle

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_StmtHandleNotZero(const wchar_t* const place,
                                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__stmt_handle_not_zero_0);
}//Throw_BugCheck_StmtHandleNotZero

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_BlobHandleNotZero(const wchar_t* const place,
                                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__blob_handle_not_zero_0);
}//Throw_BugCheck_BlobHandleNotZero

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_BadBlobHandle(const wchar_t* const place,
                                                        const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__bad_blob_handle_0);
}//Throw_BugCheck_BadBlobHandle

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectBlobHandleMode
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            int            const blobMode)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__incorect_blob_handle_mode_1,
   blobMode);
}//Throw_BugCheck_IncorrectBlobHandleMode

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedChangeOfTransaction
                                           (const wchar_t*    const place,
                                            const wchar_t*    const point,
                                            protocol::P_OBJCT const oldTrID,
                                            protocol::P_OBJCT const newTrID)
{
 assert(place);
 assert(point);
 assert(oldTrID!=newTrID);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   L"unexpected change of transaction. oldTrID: %1. newTrID: %2",
   oldTrID,
   newTrID);
}//Throw_BugCheck_UnexpectedChangeOfTransaction

////////////////////////////////////////////////////////////////////////////////

void RemoteFB__ErrorUtils::ThrowBugCheck_Incorrect_XSQLDA_Version
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            const wchar_t* const xsqlda_name,
                                            long           const version)
{
 assert(place);
 assert(point);
 assert(xsqlda_name);

 assert_msg(false,"version: "<<version);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_xsqlda_version_4,
   place,
   point,
   xsqlda_name,
   version);
}//ThrowBugCheck_Incorrect_XSQLDA_Version

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqln
                                           (subsystem_id_type const subsystem_id,
                                            const wchar_t*    const pXSQLDA_Sign,
                                            long              const pXSQLDA_sqln,
                                            long              const pXSQLDA_sqld)
{
 assert(pXSQLDA_Sign!=nullptr);

 assert_msg(false,"["<<structure::tstr_to_str(pXSQLDA_Sign)<<"] sqln: "<<pXSQLDA_sqln<<", sqld: "<<pXSQLDA_sqld);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_isc__bug_check__incorrect_sqln_of_xsqlda_3,
   pXSQLDA_Sign,
   pXSQLDA_sqln,
   pXSQLDA_sqld);
}//Throw_BugCheck_Incorrect_XSQLDA_sqln

////////////////////////////////////////////////////////////////////////////////

void RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedUserRowDataBufferSize
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const actualSize,
                                            size_t         const expectedSize)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   L"the uexpected size of a buffer for the row data [%1]. The internal size of the row data is [%2]",
   actualSize,
   expectedSize);
}//Throw_BugCheck_UnexpectedUserRowDataBufferSize

////////////////////////////////////////////////////////////////////////////////

void RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__ZeroSizeOfElement
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            unsigned       const blrTypeID)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__zero_array_element_size_3,
   place,
   point,
   blrTypeID);
}//Throw_BugCheck__InvalidArray__ZeroSizeOfElement

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__InvalidBufferSize
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            const wchar_t* const relation_name,
                                            const wchar_t* const field_name,
                                            size_t         const DefinedSize,
                                            size_t         const ExpectedSize)
{
 assert(place);
 assert(point);
 assert(relation_name);
 assert(field_name);
 assert(DefinedSize!=ExpectedSize);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__invalid_array_buffer_size_6,
   place,
   point,
   relation_name,
   field_name,
   DefinedSize,
   ExpectedSize);
}//Throw_BugCheck__InvalidArray__InvalidBufferSize

////////////////////////////////////////////////////////////////////////////////

void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__no_data
                                           (const wchar_t* const place,
                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 assert(false);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__no_data_2,
   place,
   point);
}//Throw_BugCheck_IncorrectSDL__no_data

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_end_of_data
                                           (const wchar_t* const place,
                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 assert(false);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__unexpected_end_of_data_2,
   place,
   point);
}//Throw_BugCheck_IncorrectSDL__unexpected_end_of_data

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unk_version
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            unsigned       const sdlVersion)
{
 assert(place);
 assert(point);

 assert(false);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__unk_version_3,
   place,
   point,
   sdlVersion);
}//Throw_BugCheck_IncorrectSDL__unk_version

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__len_of_str_data_exceed_the_size_of_buffer_tail
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            unsigned       const strLength,
                                            size_t         const bufferTailSize)
{
 assert(place);
 assert(point);
 assert(bufferTailSize<strLength);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__str_len_exceeed_the_size_of_buffer_tail_4,
   place,
   point,
   strLength,
   bufferTailSize);
}//Throw_BugCheck_IncorrectSDL__len_of_str_data_exceed_the_size_of_buffer_tail

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__mult_def_of_element
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            const wchar_t* const elementTagID,
                                            size_t         const elementTagOffset)
{
 assert(place);
 assert(point);
 assert(elementTagID);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__mult_def_of_element_4,
   place,
   point,
   elementTagID,
   elementTagOffset);
}//Throw_BugCheck_IncorrectSDL__mult_def_of_element

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__wrong_count_of_struct_fields
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const fieldCount)
{
 assert(place);
 assert(point);
 assert(fieldCount!=1);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__wrong_number_of_struct_fields_3,
   place,
   point,
   fieldCount);
}//Throw_BugCheck_IncorrectSDL__wrong_count_of_struct_fields

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__wrong_index_of_bound
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const boundIndex,
                                            size_t         const maxBoundNumber)
{
 assert(place);
 assert(point);
 assert(maxBoundNumber<=boundIndex);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__wrong_bound_index_4,
   place,
   point,
   boundIndex,
   maxBoundNumber);
}//Throw_BugCheck_IncorrectSDL__wrong_index_of_bound

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__mult_def_of_bound_range
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const boundIndex)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__mult_def_of_bound_range_3,
   place,
   point,
   boundIndex);
}//Throw_BugCheck_IncorrectSDL__mult_def_of_bound_range

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__bad_bound_range
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const boundIndex,
                                            signed __int32 const lower,
                                            signed __int32 const upper)
{
 assert(place);
 assert(point);
 assert(upper<lower);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__bad_bound_range_5,
   place,
   point,
   boundIndex,
   lower,
   upper);
}//Throw_BugCheck_IncorrectSDL__bad_bound_range

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unknown_kind_of_literal
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            unsigned       const literalKind,
                                            size_t         const offset)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__unknown_kind_of_literal_4,
   place,
   point,
   literalKind,
   offset);
}//Throw_BugCheck_IncorrectSDL__unknown_kind_of_literal

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__wrong_count_of_element_fields
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            unsigned       const fieldCount)
{
 assert(place);
 assert(point);
 assert(fieldCount!=1);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__wrong_number_of_element_fields_3,
   place,
   point,
   fieldCount);
}//Throw_BugCheck_IncorrectSDL__wrong_count_of_element_fields

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_tag
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            unsigned       const tagID,
                                            size_t         const offset)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__unexpected_tag_4,
   place,
   point,
   tagID,
   offset);
}//Throw_BugCheck_IncorrectSDL__unexpected_tag

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__incorrect_index_property_of_scalar_tag
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            unsigned       const index,
                                            size_t         const indexOffset)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__incorrect_index_of_scalar_tag_4,
   place,
   point,
   index,
   indexOffset);
}//Throw_BugCheck_IncorrectSDL__incorrect_index_property_of_scalar_tag

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__inconsistent_sizes_of_buffer_and_data
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const bufferSize,
                                            size_t         const dataSize)
{
 assert(place);
 assert(point);

 assert(bufferSize!=dataSize);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__inconsistent_sizes_of_buffer_and_data_4,
   place,
   point,
   bufferSize,
   dataSize);
}//Throw_BugCheck_IncorrectSDL__inconsistent_sizes_of_buffer_and_data

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__no_data_of_tag
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            const wchar_t* const tagID)
{
 assert(place);
 assert(point);
 assert(tagID);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__no_data_of_tag_3,
   place,
   point,
   tagID);
}//Throw_BugCheck_IncorrectSDL__no_data_of_tag

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__no_data_of_dimensions
                                           (const wchar_t* const place,
                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__no_data_of_dimensions_2,
   place,
   point);
}//Throw_BugCheck_IncorrectSDL__no_data_of_dimensions

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__no_data_of_dimension
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const boundIndex)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__no_data_of_dimension_3,
   place,
   point,
   boundIndex);
}//Throw_BugCheck_IncorrectSDL__no_data_of_dimension

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unknown_blrtypeid
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            unsigned       const blrTypeID,
                                            size_t         const offset)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__unk_blr_data_type_4,
   place,
   point,
   blrTypeID,
   offset);
}//Throw_BugCheck_IncorrectSDL__unknown_blrtypeid

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__invalid_element_length
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const length,
                                            const wchar_t* const blrTypeSign)
{
 assert(place);
 assert(point);
 assert(blrTypeSign);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__invalid_element_length_4,
   place,
   point,
   length,
   blrTypeSign);
}//Throw_BugCheck_IncorrectSDL__invalid_element_length

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__failed_to_translate_str_to_unicode
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            wstr_box_type  const cs_name)
{
 assert(place);
 assert(point);

 CHECK_READ_TYPED_PTR(cs_name.ptr,cs_name.len);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sdl__failed_to_translate_str_to_unicode_3,
   place,
   point,
   cs_name);
}//Throw_BugCheck_IncorrectSDL__failed_to_translate_str_to_unicode

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__AuthServiceNotSupported
                                           (subsystem_id_type const subsystem_id,
                                            wstr_box_type     const authServiceName)
{
  IBP_ErrorUtils::Throw__ErrorWithCustomErrorObject
   (DB_SEC_E_AUTH_FAILED,
    subsystem_id,
    ibp_mce_remote__auth_service_not_supported_1,
    IBP_CreateCustomErrorFor_AuthFailed(),
    authServiceName);
}//Throw__AuthServiceNotSupported

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__UnknownAuthServiceName
                                           (subsystem_id_type const subsystem_id,
                                            wstr_box_type     const authServiceName)
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_remote__unk_auth_service_name_1,
   authServiceName);
}//Throw__UnknownAuthServiceName

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__IncorrectAuthServiceName
                                           (subsystem_id_type const subsystem_id,
                                            wstr_box_type     const authServiceName)
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_remote__incorrect_auth_service_name_1,
   IBP_Utils::EscapingText(authServiceName));
}//Throw__IncorrectAuthServiceName

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_auth_service_name_from_utf8_to_wstr
                                           (const wchar_t* const place,
                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_remote__bug_check__cant_translate_auth_service_name_4,
   place,
   point,
   L"UTF8",
   L"WSTR");
}//Throw_BugCheck__cant_convert_auth_service_name_from_utf8_to_wstr

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_auth_service_name_from_wstr_to_utf8
                                           (const wchar_t* const place,
                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_remote__bug_check__cant_translate_auth_service_name_4,
   place,
   point,
   L"WSTR",
   L"UTF8");
}//Throw_BugCheck__cant_convert_auth_service_name_from_wstr_to_utf8

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_auth_service_names_from_wstr_to_utf8
                                           (const wchar_t* const place,
                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_remote__bug_check__cant_translate_auth_service_names_4,
   place,
   point,
   L"WSTR",
   L"UTF8");
}//Throw_BugCheck__cant_convert_auth_service_names_from_wstr_to_utf8

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck__auth_service_already_was_used
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            wstr_box_type  const authServiceName)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_remote__bug_check__auth_service_already_was_used_3,
   place,
   point,
   authServiceName);
}//Throw_BugCheck__auth_service_already_was_used

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck__auth_service_factory_already_was_registered
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            wstr_box_type  const authServiceName)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_remote__bug_check__auth_service_factory_already_was_registered_3,
   place,
   point,
   authServiceName);
}//Throw_BugCheck__auth_service_factory_already_was_registered

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_name_of_wire_crypt_key_from_utf8_to_wstr
                                           (const wchar_t* const place,
                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error 
  (E_FAIL,
   ibp_mce_remote__bug_check__cant_translate_wire_crypt_key_type_name_4,
   place,
   point,
   L"UTF8",
   L"WSTR");
}//Throw_BugCheck__cant_convert_name_of_wire_crypt_key_from_utf8_to_wstr

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_name_of_wire_crypt_key_from_wstr_to_utf8
                                           (const wchar_t* const place,
                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_remote__bug_check__cant_translate_wire_crypt_key_type_name_4,
   place,
   point,
   L"WSTR",
   L"UTF8");
}//Throw_BugCheck__cant_convert_name_of_wire_crypt_key_from_wstr_to_utf8

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_crypt_permission
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            unsigned       const mode)
{
 assert(place);
 assert(point);

 self_type::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__unknown_wire_crypt_permission_1,
   mode);
}//Throw_BugCheck__unknown_wire_crypt_permission

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_compression_rule
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            unsigned       const rule)
{
 assert(place);
 assert(point);

 self_type::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__unknown_wire_compression_rule_1,
   rule);
}//Throw_BugCheck__unknown_wire_compression_rule

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__MultipleDefinitionOfServerKey
                                           (subsystem_id_type const subsystem_id,
                                            wstr_box_type     const keyType,
                                            wstr_box_type     const keyPlugin)
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_remote__multiple_definition_of_known_server_key_2,
   keyType,
   keyPlugin);
}//Throw__MultipleDefinitionOfServerKey

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__WireCryptImpossibled_NoKnownSrvKeys
                                           (subsystem_id_type const subsystem_id,
                                            wstr_box_type     const authServiceName)
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_remote__wire_crypt_not_possible__no_known_server_keys_1,
   authServiceName);
}//Throw__WireCryptImpossibled_NoKnownSrvKeys

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__WireCryptImpossibled_NoCryptKeys
                                           (subsystem_id_type const subsystem_id,
                                            wstr_box_type     const authServiceName)
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_remote__wire_crypt_not_possible__no_crypt_keys_1,
   authServiceName);
}//Throw__WireCryptImpossibled_NoCryptKeys

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw__WireCryptImpossibled_NoSupportForKnownServerKeys
                                           (subsystem_id_type const subsystem_id,
                                            wstr_box_type     const authServiceName)
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_remote__wire_crypt_not_possible__no_support_for_known_server_keys_1,
   authServiceName);
}//Throw__WireCryptImpossibled_NoSupportForKnownServerKeys

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_AuthSvcErr__IncorrectUsage__NoCnParam
                                           (subsystem_id_type const subsystem_id,
                                            wstr_box_type     const authServiceName,
                                            const wchar_t*    const cnParamName)
{
 assert(!authServiceName.empty());
 assert(cnParamName);

 t_ibp_error exc(E_FAIL,
                 subsystem_id,
                 ibp_mce_remote__incorrect_usage_of_auth_service_1);

 exc<<authServiceName;

 //----------------
 exc.add_error
  (E_FAIL,
   subsystem_id,
   ibp_mce_no_def_req_init_prop_1);

 exc<<cnParamName;

 //----------------
 exc.raise_me();
}//Throw_AuthSvcErr__IncorrectUsage__NoCnParam

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_AuthSvcErr__IncorrectUsage__AlreadyWasCompleted
                                           (subsystem_id_type const subsystem_id,
                                            wstr_box_type     const authServiceName)
{
 assert(!authServiceName.empty());

 t_ibp_error exc(E_FAIL,
                 subsystem_id,
                 ibp_mce_remote__incorrect_usage_of_auth_service_1);

 exc<<authServiceName;

 //----------------
 exc.add_error
  (E_FAIL,
   subsystem_id,
   ibp_mce_remote__auth_seq_already_completed_0);

 //----------------
 exc.raise_me();
}//Throw_AuthSvcErr__IncorrectUsage__AlreadyWasCompleted

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const cbAuthData)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__auth_err__incorrect_length_of_auth_data_1,
   cbAuthData);
}//Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const cbAuthData,
                                            size_t         const cbExpectedLength)
{
 assert(place);
 assert(point);

 assert(cbAuthData!=cbExpectedLength);

 IBP_ErrorUtils::Throw__BugCheck
  (place,
   point,
   me_bug_check__auth_err__incorrect_length_of_auth_data_2,
   cbAuthData,
   cbExpectedLength);
}//Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_AuthSvcBugCheck__TooLongAuthData
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const cbAuthData,
                                            size_t         const cbMaxLength)
{
 assert(place);
 assert(point);

 assert(cbMaxLength<cbAuthData);

 IBP_ErrorUtils::Throw__BugCheck
  (place,
   point,
   me_bug_check__auth_err__too_long_auth_data_2,
   cbAuthData,
   cbMaxLength);
}//Throw_AuthSvcBugCheck__TooLongAuthData

//------------------------------------------------------------------------
void RemoteFB__ErrorUtils::Throw_AuthSvcBugCheck__IncorrectServerKey
                                           (const wchar_t* const place,
                                            const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck
  (place,
   point,
   me_bug_check__auth_err__incorrect_server_key_0);
}//Throw_AuthSvcBugCheck__IncorrectServerKey

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
