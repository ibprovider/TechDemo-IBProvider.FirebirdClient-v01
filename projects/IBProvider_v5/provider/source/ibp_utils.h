////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_utils.h
//! \brief   ������� ������ ����������
//! \author  Kovalenko Dmitry
//! \date    28.11.2012
#ifndef _ibp_utils_H_
#define _ibp_utils_H_

#include <lcpi/lib/structure/t_const_str_box.h>
#include <sstream>
#include <vector>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_Utils

/// <summary>
///  ������� ������ ����������
/// </summary>
class IBP_Utils LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=IBP_Utils;

 public:
  using wstr_box_type
   =lib::structure::t_const_wstr_box;

  using str_box_type
   =lib::structure::t_const_str_box;

 public:
  static HRESULT GetAsynchRowsetOpStatus__Complete
                                   (DBCOUNTITEM*   pulProgress,
                                    DBCOUNTITEM*   pulProgressMax,
                                    DBASYNCHPHASE* peAsynchPhase);

  static HRESULT GetAsynchRowsetOpStatus__Canceled
                                   (DBCOUNTITEM*   pulProgress,
                                    DBCOUNTITEM*   pulProgressMax,
                                    DBASYNCHPHASE* peAsynchPhase);

  static HRESULT GetAsynchRowsetOpStatus__Population
                                   (DBASYNCHOP     eOperation,
                                    DBCOUNTITEM*   pulProgress,
                                    DBCOUNTITEM*   pulProgressMax,
                                    DBASYNCHPHASE* peAsynchPhase);

 public:
  /// <summary>
  ///  ������������ ��������� �������
  /// </summary>
  //! \param[in] stmt
  static std::wstring GetStmtSign(wstr_box_type stmt);

 public:
  /// <summary>
  ///  ����������� ����� SSPI-��������������
  /// </summary>
  //! \param[in] authName
  //!  ��������������� ��� ������ ��������������.
  static bool IsSSPI(wstr_box_type authName);

 public:
  /// <summary>
  ///  �������������� UTF8-������ � WSTR-������. CHAR-������.
  /// </summary>
  //! \param[in]  Utf8Str
  //! \param[out] pWStr
  //!  Not null.
  //! \return
  //!  true, ���� �������������� ������ ��� ������
  //!
  //! \attention
  //!  1. (*pWStr) �� ��������� ����� ������� ������.
  //!  2. (*pWStr) �� ��������� � ������ ������ ��������������.
  static bool Utf8ToWStr__Fast
               (const str_box_type& Utf8Str,
                std::wstring*       pWStr);
 public:
  /// <summary>
  ///  �������������� WSTR-������ � UTF8-������.
  /// </summary>
  //! \param[in]  WStr
  //! \param[out] pUtf8Str
  //!  Not null.
  //! \return
  //!  true, ���� �������������� ������ ��� ������
  //!
  //! \attention
  //!  1. (*pUtf8Str) �� ��������� ����� ������� ������.
  //!  2. (*pUtf8Str) �� ��������� � ������ ������ ��������������.
  static bool WStrToUtf8__Fast
               (const wstr_box_type& WStr,
                std::string*         pUtf8Str);

 public:
  /// <summary>
  ///  ������������ ������ � ��������������� ���������.
  /// </summary>
  //! \param[in] text
  static std::wstring EscapingText(wstr_box_type text);

 public:
  /// <summary>
  ///  ��������� ����� � ���������� ������� ��� ����� ��������
  /// </summary>
  //! \param[in] s1
  //! \param[in] s2
  static bool EqualAsciiStr_i(const wstr_box_type& s1,
                              const wstr_box_type& s2);

 public:
  static bool TestProviderErrorRules__explain_dbms_error(long rules);

  static bool TestProviderErrorRules__append_additional_records(long rules);

  static bool TestProviderErrorRules__append_summary_info(long rules);

 public:
  template<class Allocator>
  static std::wstring MakePointStr(const std::vector<long,Allocator>& pt);

  template<class Allocator>
  static std::wstring MakePointStr__revert(const std::vector<long,Allocator>& pt);

 public:
  template<typename TChar>
  static bool TestChar_IsLatin(TChar ch)=delete;

  template<typename TChar>
  static bool TestChar_IsDigit(TChar ch)=delete;

 public:
  static bool TestChar_IsLatin(wchar_t ch);

  static bool TestChar_IsDigit(wchar_t ch);

 public:
  static bool IsValidCharsetName
               (const wstr_box_type& name);

  static bool IsValidCharsetCollationName
               (const wstr_box_type& name);

 public:
  static bool IsValidSimpleString(const wstr_box_type& name);
};//class IBP_Utils

////////////////////////////////////////////////////////////////////////////////
//class IBP_Utils

template<class Allocator>
std::wstring IBP_Utils::MakePointStr(const std::vector<long,Allocator>& pt)
{
 std::wstringstream result_wss;

 const wchar_t* sep=L"";

 //������������ � ������ �������.
 for(size_t x=0,_c=pt.size();x!=_c;++x)
 {
  result_wss<<sep;

  sep=L",";

  result_wss<<pt[x];
 }//for x

 assert(!result_wss.fail());

 return result_wss.str();
}//MakePointStr

//------------------------------------------------------------------------
template<class Allocator>
std::wstring IBP_Utils::MakePointStr__revert(const std::vector<long,Allocator>& pt)
{
 std::wstringstream result_wss;

 const wchar_t* sep=L"";

 //������������ � �������� �������.
 for(size_t x=pt.size();x!=0;)
 {
  --x;

  result_wss<<sep;

  sep=L",";

  result_wss<<pt[x];
 }//for x

 assert(!result_wss.fail());

 return result_wss.str();
}//MakePointStr__revert

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
