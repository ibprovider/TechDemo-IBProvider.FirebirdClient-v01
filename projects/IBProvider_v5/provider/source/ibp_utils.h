////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_utils.h
//! \brief   ������� ������ ����������
//! \author  Kovalenko Dmitry
//! \date    28.11.2012
#ifndef _ibp_utils_H_
#define _ibp_utils_H_

#include <structure/t_const_str_box.h>
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
class IBP_Utils
{
 private:
  typedef IBP_Utils                         self_type;

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
  static std::wstring GetStmtSign(structure::t_const_wstr_box stmt);

 public:
  /// <summary>
  ///  ����������� ����� SSPI-��������������
  /// </summary>
  //! \param[in] authName
  //!  ��������������� ��� ������ ��������������.
  static bool IsSSPI(structure::t_const_wstr_box authName);

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
               (const structure::t_basic_const_str_box<char>& Utf8Str,
                std::wstring*                                 pWStr);
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
               (const structure::t_const_wstr_box& WStr,
                std::string*                       pUtf8Str);

 public:
  /// <summary>
  ///  ������������ ������ � ��������������� ���������.
  /// </summary>
  //! \param[in] text
  static std::wstring EscapingText(structure::t_const_wstr_box text);

 public:
  /// <summary>
  ///  ��������� ����� � ���������� ������� ��� ����� ��������
  /// </summary>
  //! \param[in] s1
  //! \param[in] s2
  static bool EqualAsciiStr_i(const structure::t_const_wstr_box& s1,
                              const structure::t_const_wstr_box& s2);

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
  static bool TestChar_IsLatin(TChar ch);

  template<typename TChar>
  static bool TestChar_IsDigit(TChar ch);

 public:
  template<>
  static bool TestChar_IsLatin<wchar_t>(wchar_t ch);

  template<>
  static bool TestChar_IsDigit<wchar_t>(wchar_t ch);

 public:
  static bool IsValidCharsetName
               (const structure::t_const_wstr_box& name);

  static bool IsValidCharsetCollationName
               (const structure::t_const_wstr_box& name);

 public:
  static bool IsValidSimpleString(const structure::t_const_wstr_box& name);
};//class IBP_Utils

////////////////////////////////////////////////////////////////////////////////
//class IBP_Utils

template<class Allocator>
std::wstring IBP_Utils::MakePointStr(const std::vector<long,Allocator>& pt)
{
 std::wstring result;

 wchar_t buf[64];

 //������������ � ������ �������.
 for(size_t x=0,_c=pt.size();x!=_c;++x)
 {
  if(x!=0)
   result+=L',';

  _VERIFY_EQ(_GCRT_itow_s(pt[x],buf,_DIM_(buf),10),0L);

  assert(std::find(buf,_END_(buf),0)!=_END_(buf));

  result+=buf;
 }//for x

 return result;
}//MakePointStr

//------------------------------------------------------------------------
template<class Allocator>
std::wstring IBP_Utils::MakePointStr__revert(const std::vector<long,Allocator>& pt)
{
 std::wstring result;

 wchar_t buf[64];

 //������������ � �������� �������.
 for(size_t x=pt.size(),_c=pt.size();x>0;)
 {
  if(x!=_c)
   result+=L',';

  --x;

  _VERIFY_EQ(_GCRT_itow_s(pt[x],buf,_DIM_(buf),10),0L);

  assert(std::find(buf,_END_(buf),0)!=_END_(buf));

  result+=buf;
 }//for x

 return result;
}//MakePointStr__revert

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
