////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__common
//! \file    db_obj__dbms_fb__common__error_text_obj.h
//! \brief   Object for providing Firebird error text.
//! \author  Kovalenko Dmitry
//! \date    08.08.2016
#ifndef _db_obj__dbms_fb__common__error_text_obj_H_
#define _db_obj__dbms_fb__common__error_text_obj_H_

#include "source/db_obj/dbms_fb/common/db_obj__dbms_fb__common__svc__status_vector_utils.h"
#include "source/db_obj/db_memory.h"

#include <lcpi/lib/structure/error/t_err_text.h>

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace common{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__dbms_fb__common
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

class FB_ErrorTextObj;

////////////////////////////////////////////////////////////////////////////////
//class FB_ErrorTextObj

/// <summary>
///  Object for providing Firebird error text.
/// </summary>
//! \attention
//!  ����� �� ������������ ��� ������������.
//! \note
//!  �������� ������ ��� ������ ������ �������� � ������ �������, �������
//!  (������ � ���������� �������) ����������� ��������������� �� ���������
//!  "�����������" ������ �������.
class FB_ErrorTextObj LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(lib::structure::t_err_text)
{
 private:
  typedef FB_ErrorTextObj                                         self_type;

  FB_ErrorTextObj(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef isc_api::t_ibp_isc_status                               status_type;

  typedef fb_common__svc__status_vector_utils                     sv_utils_type;

  typedef fb_common__svc__status_vector_utils_ptr                 sv_utils_ptr;

 private:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] pStatusVectorUtils
  //!  Not null.
  //! \param[in] szStatusVector
  //! \param[in] pStatusVector
  FB_ErrorTextObj(sv_utils_type*     pStatusVectorUtils,
                  size_t             szStatusVector,
                  const status_type* pStatusVector);

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~FB_ErrorTextObj();

 public:
  /// <summary>
  ///  ������� ������
  /// </summary>
  //! \param[in] pStatusVectorUtils
  //!  Not null.
  //! \param[in] sv_beg
  //! \param[in] sv_end
  //! \return
  //!  Not null.
  static self_ptr Create(sv_utils_type*     pStatusVectorUtils,
                         const status_type* sv_beg,
                         const status_type* sv_end);

  //interface ------------------------------------------------------------
  virtual bool get_text(lcid_type lcid,string_type* text)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef db_obj::t_db_memory_allocator     raw_allocator_type;

  static void* operator new (size_t); //not impl

  static void* operator new (size_t,void* pv);

 public:
  static void operator delete (void* pv);

 #if(COMP_CONF_SUPPORT_OPERATOR_DELETE_EX)
  //memory will be deallocated in catch of self_type::Create
  static void operator delete(void* /*pv*/,void* /*pv2*/){;}
 #endif

 private:
  ///��������� �� ������ ��� ������ �� ������ ��������
  sv_utils_ptr const m_spStatusVectorUtils;

  ///���������� ��������� � ������ �������
  size_t const m_szStatusVector;

  ///��������� �� ������ ������� ������ �������
  const status_type* const m_pStatusVector;

 private:

  /*����� � ������ ����� �������� ������ ������ � ��� ��������� ������*/
};//class FB_ErrorTextObj

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms common*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
