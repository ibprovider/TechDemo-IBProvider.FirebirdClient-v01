////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__error_utils.h
//! \brief   Набор утилит для обработки ошибок.
//! \author  Kovalenko Dmitry
//! \date    15.02.2015.
#ifndef _remote_fb__error_utils_H_
#define _remote_fb__error_utils_H_

#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ErrorUtils

/// <summary>
///  Набор утилит для обработки ошибок.
/// </summary>
class RemoteFB__ErrorUtils COMP_W000006_CLASS_FINAL
{
 private:
  typedef RemoteFB__ErrorUtils                   self_type;

 public: //typedefs ------------------------------------------------------
  typedef ibp::t_ibp_subsystem_id                subsystem_id_type;

  /// Тип для представления идентификатора операции с сервером
  typedef int                                    p_operation_id_type;

  typedef structure::t_const_wstr_box            wstr_box_type;

 public:
  template<typename... Args>
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__BugCheck__DEBUG
               (const wchar_t*  place,
                const wchar_t*  point,
                const wchar_t*  reason_template,
                Args&&...       args);

  template<typename... Args>
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__Error
               (HRESULT            hr,
                t_ibp_subsystem_id subsystem_id,
                ibp_msg_code_type  msg_code,
                Args&&...          args);

 public:
  /// <summary>
  ///  Генерация исключения - запрашиваемый протокол подключения не поддерживается.
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] protocolID
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__RequestedProtocolNotSupported
               (subsystem_id_type  subsystem_id,
                wstr_box_type      protocolID);

 public:
  /// <summary>
  ///  Генерация исключения - неизвестный тип протокола подключения.
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] protocolVersionNum
  //!  Protocol version number.
  //! \param[in] protocolTypeID
  //!  Protocol type identifier.
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__UnsupportedProtocolTypeID
               (subsystem_id_type  subsystem_id,
                unsigned           protocolVersionNum,
                unsigned           protocolTypeID);

  /// <summary>
  ///  Генерация исключения - запрашиваемый тип протокола подключения не поддерживается.
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] protocolVersionNum
  //!  Protocol version number.
  //! \param[in] protocolTypeID
  //!  Protocol type identifier.
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__ReqProtocolTypeIdDoesNotSupported
               (subsystem_id_type  subsystem_id,
                unsigned           protocolVersionNum,
                wstr_box_type      protocolTypeSign);

  /// <summary>
  ///  Генерация исключения - неизвестные флаги протокола подключения.
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] protocolVersionNum
  //!  Protocol version number.
  //! \param[in] protocolFlags
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__UnsupportedProtocolFlags
               (subsystem_id_type  subsystem_id,
                unsigned           protocolVerNum,
                unsigned           protocolFlags);

 public:
  /// <summary>
  ///  Генерация исключения - сервер отклонил компрессию подключения
  /// </summary>
  //! \param[in] subsystem_id
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__ServerRejectedConnectionCompression
               (subsystem_id_type  subsystem_id);

  /// <summary>
  ///  Генерация исключения - сервер требует компрессию подключения
  /// </summary>
  //! \param[in] subsystem_id
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__ServerRequiredConnectionCompression
               (subsystem_id_type  subsystem_id);

  /// <summary>
  ///  Генерация исключения - неподдерживаемый тип сжатия данных
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] typeName
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__UnsupportedWireCompressionType
               (subsystem_id_type  subsystem_id,
                wstr_box_type      typeName);

 public:
  /// <summary>
  ///  Генерация исключения - ошибка обработки статус вектора операции
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] operationID
  //!  Идентификатор операции с сервером.
  //! \param[in] place
  //! \param[in] point
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__OpStatusVectorProcessingError
               (subsystem_id_type   subsystem_id,
                p_operation_id_type operationID,
                const wchar_t*      place,
                const wchar_t*      point);

 public:
  /// <summary>
  ///  Генерация исключения - [BUG CHECK] некорректная структура пакета.
  /// </summary>
  //! \param[in] place
  //! \param[in] point
  //! \param[in] actualProtocolSetID
  //! \param[in] expectedProtocolSetID
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_UnexpectedPacketStructure
               (const wchar_t*            place,
                const wchar_t*            point,
                protocol::PROTOCOL_SET_ID actualProtocolSetID,
                protocol::PROTOCOL_SET_ID expectedProtocolSetID);

  /// <summary>
  ///  Генерация исключения - [BUG CHECK] сервер установил неожиданную версию протокола.
  /// </summary>
  //! \param[in] place
  //! \param[in] point
  //! \param[in] protocolVersion
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_AcceptedUnexpectedProtocolVersion
               (const wchar_t*               place,
                const wchar_t*               point,
                protocol::P_PROTOCOL_VERSION protocolVersion);

  /// <summary>
  ///  Генерация исключения - [BUG CHECK] сервер установил неожиданную архитектуру протокола.
  /// </summary>
  //! \param[in] place
  //! \param[in] point
  //! \param[in] protocolArchitecture
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_AcceptedUnexpectedProtocolArchitecture
               (const wchar_t*    place,
                const wchar_t*    point,
                protocol::P_ARCH  protocolArchitecture);

 public:
  /// <summary>
  ///  Генерация исключения - [BUG CHECK] неожиданный ответ сервера
  /// </summary>
  //! \param[in] pPort
  //! \param[in] place
  //! \param[in] point
  //! \param[in] answerID
  COMP_CONF_DECLSPEC_NORETURN
  static void SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
               (RemoteFB__Port*     pPort,
                const wchar_t*      place,
                const wchar_t*      point,
                p_operation_id_type answerID);

  /// <summary>
  ///  Генерация исключения - [BUG CHECK] неожиданный ответ сервера
  /// </summary>
  //! \param[in] Errors
  //!  Коллекция ранее произошедших ошибок
  //! \param[in] pPort
  //! \param[in] place
  //! \param[in] point
  //! \param[in] answerID
  COMP_CONF_DECLSPEC_NORETURN
  static void SetInvalidPortState_And_Throw_BugCheck2_UnexpectedServerAnswer
               (t_ibp_error&        Errors,
                RemoteFB__Port*     pPort,
                const wchar_t*      place,
                const wchar_t*      point,
                p_operation_id_type answerID);

  /// <summary>
  ///  Генерация исключения - [BUG CHECK] неожиданная версия протокола
  /// </summary>
  //! \param[in] place
  //! \param[in] point
  //! \param[in] protocolVersion
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_UnexpectedProtocolVersion
               (const wchar_t*               place,
                const wchar_t*               point,
                protocol::P_PROTOCOL_VERSION protocolVersion);

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_BadCnHandle
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_BadTrHandle
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_TrHandleNotZero
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_BadStmtHandle
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_StmtHandleNotZero
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_BlobHandleNotZero
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_BadBlobHandle
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectBlobHandleMode
               (const wchar_t* place,
                const wchar_t* point,
                int            blobMode);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_UnexpectedChangeOfTransaction
               (const wchar_t*    place,
                const wchar_t*    point,
                protocol::P_OBJCT oldTrID,
                protocol::P_OBJCT newTrID);

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void ThrowBugCheck_Incorrect_XSQLDA_Version
               (const wchar_t* place,
                const wchar_t* point,
                const wchar_t* xsqlda_name,
                long           version);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_Incorrect_XSQLDA_sqld
               (subsystem_id_type subsystem_id,
                const wchar_t*    pXSQLDA_Sign,
                long              pXSQLDA_sqld);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_Incorrect_XSQLDA_sqln
               (subsystem_id_type subsystem_id,
                const wchar_t*    pXSQLDA_Sign,
                long              pXSQLDA_sqln,
                long              pXSQLDA_sqld);

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__InvalidArray__ZeroSizeOfElement
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       blrTypeID);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__InvalidArray__InvalidBufferSize
               (const wchar_t* place,
                const wchar_t* point,
                const wchar_t* relation_name,
                const wchar_t* field_name,
                size_t         DefinedSize,
                size_t         ExpectedSize);

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__no_data
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__unexpected_end_of_data
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__unk_version
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       sdlVersion);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__len_of_str_data_exceed_the_size_of_buffer_tail
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       strLength,
                size_t         bufferTailSize);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__mult_def_of_element
               (const wchar_t* place,
                const wchar_t* point,
                const wchar_t* elementTagID,
                size_t         elementTagOffset);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__wrong_count_of_struct_fields
               (const wchar_t* place,
                const wchar_t* point,
                size_t         fieldCount);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__wrong_index_of_bound
               (const wchar_t* place,
                const wchar_t* point,
                size_t         boundIndex,
                size_t         maxBoundCount);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__mult_def_of_bound_range
               (const wchar_t* place,
                const wchar_t* point,
                size_t         boundIndex);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__bad_bound_range
               (const wchar_t* place,
                const wchar_t* point,
                size_t         boundIndex,
                signed __int32 lower,
                signed __int32 upper);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__unknown_kind_of_literal
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       literalKind,
                size_t         offset);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__wrong_count_of_element_fields
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       fieldCount);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__unexpected_tag
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       tagID,
                size_t         tagOffset);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__incorrect_index_property_of_scalar_tag
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       index,
                size_t         indexOffset);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__inconsistent_sizes_of_buffer_and_data
               (const wchar_t* place,
                const wchar_t* point,
                size_t         bufferSize,
                size_t         dataSize);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__no_data_of_tag
               (const wchar_t* place,
                const wchar_t* point,
                const wchar_t* tagID);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__no_data_of_dimensions
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__no_data_of_dimension
               (const wchar_t* place,
                const wchar_t* point,
                size_t         boundIndex);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__unknown_blrtypeid
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       blrTypeID,
                size_t         offset);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__invalid_element_length
               (const wchar_t* place,
                const wchar_t* point,
                size_t         length,
                const wchar_t* blrTypeSign);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck_IncorrectSDL__failed_to_translate_str_to_unicode
               (const wchar_t* place,
                const wchar_t* point,
                wstr_box_type  cs_name);

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__AuthServiceNotSupported
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__UnknownAuthServiceName
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__IncorrectAuthServiceName
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__cant_convert_auth_service_name_from_utf8_to_wstr
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__cant_convert_auth_service_name_from_wstr_to_utf8
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__cant_convert_auth_service_names_from_wstr_to_utf8
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__auth_service_already_was_used
               (const wchar_t* place,
                const wchar_t* point,
                wstr_box_type  authServiceName);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__auth_service_factory_already_was_registered
               (const wchar_t* place,
                const wchar_t* point,
                wstr_box_type  authServiceName);

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__cant_convert_name_of_wire_crypt_key_from_utf8_to_wstr
               (const wchar_t* place,
                const wchar_t* point);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__cant_convert_name_of_wire_crypt_key_from_wstr_to_utf8
                (const wchar_t* place,
                 const wchar_t* point);

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__unknown_wire_crypt_permission
               (const wchar_t*    place,
                const wchar_t*    point,
                unsigned          permission);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_BugCheck__unknown_wire_compression_rule
               (const wchar_t*    place,
                const wchar_t*    point,
                unsigned          rule);

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__MultipleDefinitionOfServerKey
               (subsystem_id_type subsystem_id,
                wstr_box_type     keyType,
                wstr_box_type     keyPlugin);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__WireCryptImpossibled_NoKnownSrvKeys
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__WireCryptImpossibled_NoCryptKeys
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw__WireCryptImpossibled_NoSupportForKnownServerKeys
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

 public:
  /// <summary>
  ///  Генерация исключения "некорректное использование сервиса аутентификации".
  /// </summary>
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_AuthSvcErr__IncorrectUsage__NoCnParam
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName,
                const wchar_t*    cnParamName);

  /// <summary>
  ///  Генерация исключения "некорректное использование сервиса аутентификации".
  /// </summary>
  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_AuthSvcErr__IncorrectUsage__AlreadyWasCompleted
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData
               (const wchar_t* place,
                const wchar_t* point,
                size_t         cbAuthData);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData
               (const wchar_t* place,
                const wchar_t* point,
                size_t         cbAuthData,
                size_t         cbExpectedLength);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_AuthSvcBugCheck__TooLongAuthData
               (const wchar_t* place,
                const wchar_t* point,
                size_t         cbAuthData,
                size_t         cbMaxLength);

  COMP_CONF_DECLSPEC_NORETURN
  static void Throw_AuthSvcBugCheck__IncorrectServerKey
               (const wchar_t* place,
                const wchar_t* point);
};//class RemoteFB__ErrorUtils

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ErrorUtils

template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN /*defined for avoiding a possible problem with MSVC*/
void RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
             (const wchar_t* const place,
              const wchar_t* const point,
              const wchar_t* const reason_template,
              Args&&...            args)
{
 assert(place);
 assert(point);
 assert(reason_template);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   reason_template,
   std::forward<Args>(args)...); //throw!
}//Throw__BugCheck__DEBUG

//------------------------------------------------------------------------
template<typename... Args>
COMP_CONF_DECLSPEC_NORETURN /*defined for avoiding a possible problem with MSVC*/
void RemoteFB__ErrorUtils::Throw__Error
               (HRESULT            const hr,
                t_ibp_subsystem_id const subsystem_id,
                ibp_msg_code_type  const msg_code,
                Args&&...                args)
{
 assert(FAILED(hr));

 IBP_ErrorUtils::Throw__Error
  (hr,
   subsystem_id,
   msg_code,
   std::forward<Args>(args)...); //throw!
}//Throw__Error

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
