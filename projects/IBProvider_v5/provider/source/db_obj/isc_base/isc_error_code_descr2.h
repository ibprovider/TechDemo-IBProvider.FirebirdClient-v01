////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_error_code_descr2.h
//! \brief   ����������� ��� ������������ �������� ���� isc-������
//! \author  Kovalenko Dmitry
//! \date    29.12.2014
#ifndef _isc_error_code_descr2_H_
#define _isc_error_code_descr2_H_

#include "source/db_obj/isc_base/isc_api.h"

#include <lcpi/lib/structure/utilities/string/string_compare.h>
#include <lcpi/lib/structure/utilities/string/string_length.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_error_code_descr2

/// <summary>
///  ����������� ��� ������������ �������� ���� isc-������
/// </summary>
class t_isc_error_code_descr2
{
 private:
  typedef t_isc_error_code_descr2           self_type;

 public: //typedefs ------------------------------------------------------
  class tag_less;

 public:
  static const HRESULT c_not_def_oledb_code=HRESULT(-1);

 public:
  /// ��� ISC-������
  isc_api::t_ibp_isc_status isc_code;

  /// ��������� ��������� isc-������
  const char*      isc_code_sign2;

  /// SQLSTATE
  const char*      sqlstate2;

  /// ��� OLEDB ������. ����� c_not_def_oledb_code, ���� ��� �� ���������.
  HRESULT          oledb_code;

  /// ������������� �������, ��������� ������� � ��������� ���������.
  UINT             resource_id;

  /// ������������� ������� ���������
  UINT             message_id;

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] _isc_code
  //! \param[in] _isc_code_sign
  //! \param[in] _sqlstate
  //! \param[in] _oledb_code
  //! \param[in] _resource_id
  //! \param[in] _message_id
  t_isc_error_code_descr2(isc_api::t_ibp_isc_status _isc_code,
                          const char*               _isc_code_sign,
                          const char*               _sqlstate,
                          HRESULT                   _oledb_code,
                          UINT                      _resource_id,
                          UINT                      _message_id);

  //----------------------------------------------------------------------

  /// <summary>
  ///  ������������ ������� ����������� �� ��� OLEDB ������
  /// </summary>
  bool oledb_code_is_def()const;

  /// <summary>
  ///  ��������� � SQLSTATE
  /// </summary>
  //! \param[in] s
  //!  Not NULL
  bool eq_sqlstate2(const char* s)const;
};//class t_isc_error_code_descr2

////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

void debug__check_isc_error_code_descr2_array
                    (const char*                    pArrayName,
                     size_t                         cErrDescrs,
                     const t_isc_error_code_descr2* rgErrDescrs);

#endif

////////////////////////////////////////////////////////////////////////////////
//class t_isc_error_code_descr2::tag_less

/// <summary>
///  ������� ��� �������� �������� t_isc_error_code_descr2
/// </summary>
class t_isc_error_code_descr2::tag_less
{
 public:
  tag_less(){;}

  bool operator () (const t_isc_error_code_descr2& x1,const t_isc_error_code_descr2& x2)const
  {
   return x1.isc_code<x2.isc_code;
  }

  bool operator () (const t_isc_error_code_descr2& x,isc_api::t_ibp_isc_status const isc_code)const
  {
   return x.isc_code<isc_code;
  }

  bool operator () (isc_api::t_ibp_isc_status const isc_code,const t_isc_error_code_descr2& x)const
  {
   return isc_code<x.isc_code;
  }
};//class t_isc_error_code_descr2::tag_less

////////////////////////////////////////////////////////////////////////////////
//class t_isc_error_code_descr2

inline t_isc_error_code_descr2::t_isc_error_code_descr2
                                   (isc_api::t_ibp_isc_status const _isc_code,
                                    const char*               const _isc_code_sign,
                                    const char*               const _sqlstate,
                                    HRESULT                   const _oledb_code,
                                    UINT                      const _resource_id,
                                    UINT                      const _message_id)
 :isc_code       (_isc_code)
 ,isc_code_sign2 (_isc_code_sign)
 ,sqlstate2      (_sqlstate)
 ,oledb_code     (_oledb_code)
 ,resource_id    (_resource_id)
 ,message_id     (_message_id)
{
 assert(this->sqlstate2==nullptr || lib::structure::string_length(this->sqlstate2)==5);
}//t_isc_error_code_descr2

//------------------------------------------------------------------------
inline bool t_isc_error_code_descr2::oledb_code_is_def()const
{
 return this->oledb_code!=self_type::c_not_def_oledb_code;
}//oledb_code_is_def

//------------------------------------------------------------------------
inline bool t_isc_error_code_descr2::eq_sqlstate2(const char* const s)const
{
 assert(s!=nullptr);

 if(this->sqlstate2==nullptr)
  return false;

 if(s==nullptr)
  return false;

 return lib::structure::string_compare(s,this->sqlstate2)==0;
}//eq_sqlstate2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
