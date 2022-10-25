////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_build_message.h
//! \brief   Утилиты для формирования текста ошибки
//! \author  Kovalenko Dmitry
//! \date    03.02.2003
#ifndef _ibp_error_build_message_H_
#define _ibp_error_build_message_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/error_services/ibp_error_variant.h"
#include "source/ibp_resources.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class TIBP_MessageTextBuilder

/// <summary>
///  Утилиты для формирования текста ошибки
/// </summary>
class TIBP_MessageTextBuilder
{
 private:
  typedef TIBP_MessageTextBuilder           self_type;

 public:
  static std::wstring GetSystemErrorMsg(LCID  lcid,
                                        DWORD errorCode);

 public:
  static bool BuildSrc(std::wstring*   pResultText,
                       const VARIANT&  varSourceID);

 public:
  /// <summary>
  ///  Формирование текста ошибки [IBP_ErrorVariant version]
  /// </summary>
  //! \param[out] pResultText
  //! \param[in]  varSubSystemId
  //! \param[in]  msg_code
  //! \param[in]  lcid
  //! \param[in]  cArgs
  //! \param[in]  rgArgs
  //! \param[in]  ErrorCode
  static bool Build(std::wstring*               pResultText,
                    const VARIANT&              varSubSystemId,
                    DWORD                       msg_code,
                    LCID                        lcid,
                    size_t                      cArgs,
                    const IBP_ErrorVariant*     rgArgs,
                    HRESULT                     ErrorCode);

  /// <summary>
  ///  Формирование текста ошибки [IBP_ErrorVariant version]
  /// </summary>
  //! \param[out] pResultText
  //! \param[in]  msg_code
  //! \param[in]  lcid
  //! \param[in]  cArgs
  //! \param[in]  rgArgs
  //! \param[in]  MsgTableLoader
  static bool Build(std::wstring*               pResultText,
                    DWORD                       msg_code,
                    LCID                        lcid,
                    size_t                      cArgs,
                    const IBP_ErrorVariant*     rgArgs,
                    const TIBP_MsgTableLoader&  MsgTableLoader);

 public:
  /// <summary>
  ///  Формирование текста ошибки [IBP_ERRORVARIANT version]
  /// </summary>
  //! \param[out] pResultText
  //! \param[in]  varSubSystemId
  //! \param[in]  msg_code
  //! \param[in]  lcid
  //! \param[in]  cArgs
  //! \param[in]  rgArgs
  //! \param[in]  ErrorCode
  static bool Build(std::wstring*               pResultText,
                    const VARIANT&              varSubSystemId,
                    DWORD                       msg_code,
                    LCID                        lcid,
                    size_t                      cArgs,
                    const IBP_ERRORVARIANT*     rgArgs,
                    HRESULT                     ErrorCode);

  /// <summary>
  ///  Формирование текста ошибки [IBP_ERRORVARIANT version]
  /// </summary>
  //! \param[out] pResultText
  //! \param[in]  msg_code
  //! \param[in]  lcid
  //! \param[in]  cArgs
  //! \param[in]  rgArgs
  //! \param[in]  MsgTableLoader
  static bool Build(std::wstring*               pResultText,
                    DWORD                       msg_code,
                    LCID                        lcid,
                    size_t                      cArgs,
                    const IBP_ERRORVARIANT*     rgArgs,
                    const TIBP_MsgTableLoader&  MsgTableLoader);

 private:
  /// <summary>
  ///  Формирование основного описания ошибки
  /// </summary>
  //! \param[out] pResultText
  //! \param[in]  msg_code
  //! \param[in]  lcid
  //! \param[in]  cArgs
  //! \param[in]  rgArgs
  //! \param[in]  MsgTableLoader
  static bool Helper__BuildDescription(std::wstring*               pResultText,
                                       DWORD                       msg_code,
                                       LCID                        lcid,
                                       size_t                      cArgs,
                                       const IBP_ERRORVARIANT*     rgArgs,
                                       const TIBP_MsgTableLoader&  MsgTableLoader);

  /// <summary>
  ///  Получение имени подсистемы.
  /// </summary>
  //! \param[out] pResultText
  //! \param[in]  varSubSystemId
  //! \param[in]  lcid
  //! \return
  //!  - S_OK, если подсистема указана.
  //!  - S_FALSE, если подсистема не указана.
  //!  - E_FAIL, произошла ошибка формирования имени подсистемы.
  static HRESULT Helper__BuildSubSystemName(std::wstring*  pResultText,
                                            const VARIANT& varSubSystemId,
                                            LCID           lcid);
};//class TIBP_MessageTextBuilder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
