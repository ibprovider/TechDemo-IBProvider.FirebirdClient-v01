////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_build_message.h
//! \brief   ������� ��� ������������ ������ ������
//! \author  Kovalenko Dmitry
//! \date    03.02.2003
#ifndef _ibp_error_build_message_H_
#define _ibp_error_build_message_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/error_services/ibp_error_variant.h"
#include "source/ibp_resources.h"

#include <ole_lib/ole_base.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class TIBP_MessageTextBuilder

/// <summary>
///  ������� ��� ������������ ������ ������
/// </summary>
class TIBP_MessageTextBuilder LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=TIBP_MessageTextBuilder;

 public:
  static std::wstring GetSystemErrorMsg(LCID  lcid,
                                        DWORD errorCode);

 public:
  static bool BuildSrc(std::wstring*   pResultText,
                       const VARIANT&  varSourceID);

 public:
  /// <summary>
  ///  ������������ ������ ������ [IBP_ErrorVariant version]
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
  ///  ������������ ������ ������ [IBP_ErrorVariant version]
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
  ///  ������������ ������ ������ [IBP_ERRORVARIANT version]
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
  ///  ������������ ������ ������ [IBP_ERRORVARIANT version]
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
  ///  ������������ ��������� �������� ������
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
  ///  ��������� ����� ����������.
  /// </summary>
  //! \param[out] pResultText
  //! \param[in]  varSubSystemId
  //! \param[in]  lcid
  //! \return
  //!  - S_OK, ���� ���������� �������.
  //!  - S_FALSE, ���� ���������� �� �������.
  //!  - E_FAIL, ��������� ������ ������������ ����� ����������.
  static HRESULT Helper__BuildSubSystemName(std::wstring*  pResultText,
                                            const VARIANT& varSubSystemId,
                                            LCID           lcid);

 private:
  enum class enumGetDataFlag
  {
   ok,
   no_object,
   unk_object,
  };//enum enumGetDataFlag

  //! \brief The result of getting data - {ValueHasBeenRead,ResultOfReading}
  using tagGetResult
   =std::pair<enumGetDataFlag,HRESULT>;

  using wstr_box_type
   =structure::t_const_wstr_box;

 private:
  static wstr_box_type Helper__ToText(const tagGetResult&   get_r,
                                      const ole_lib::TBSTR& bstrValue);

 private:
  /// <summary>
  ///  Getting the source of error object.
  /// </summary>
  //! \param[in]  pUnk
  //! \param[in]  lcid
  //! \param[out] pbstrValue
  //!  Not NULL.
  //! \returns
  //!  Result status.
  static tagGetResult Helper__GetErrorSource
                             (IUnknown*       pUnk,
                              LCID            lcid,
                              ole_lib::TBSTR* pbstrValue);

  /// <summary>
  ///  Getting the description of error object.
  /// </summary>
  //! \param[in]  pUnk
  //! \param[in]  lcid
  //! \param[out] pbstrValue
  //!  Not NULL.
  //! \returns
  //!  Result status.
  static tagGetResult Helper__GetErrorDescription
                             (IUnknown*       pUnk,
                              LCID            lcid,
                              ole_lib::TBSTR* pbstrValue);
};//class TIBP_MessageTextBuilder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
