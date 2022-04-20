////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_element_wrapper.h
//! \brief   COM-������� ��� structure::t_err_record
//! \author  Kovalenko Dmitry
//! \date    18.02.2003
#ifndef _ibp_oledb__error_element_wrapper_H_
#define _ibp_oledb__error_element_wrapper_H_

#include <ole_lib/ole_lib.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__err
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

class IBP_OLEDB__ErrorElementWrapper;

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorElementWrapper

/// <summary>
///  COM-������� ��� structure::t_err_record
/// </summary>
class IBP_OLEDB__ErrorElementWrapper LCPI_CPP_CFG__CLASS__FINAL
 :public ibprovider::IBP_IErrorExtendedParameter
 ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef IBP_OLEDB__ErrorElementWrapper                  self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler  inherited;

  IBP_OLEDB__ErrorElementWrapper(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_err_record                     err_record_type;
  typedef err_record_type::self_cptr                  err_record_cptr;

 private:
  /// <summary>
  ///  �����������
  /// </summary>
  //! \param[in] pErrorRecord
  explicit IBP_OLEDB__ErrorElementWrapper(const err_record_type* pErrorRecord);

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~IBP_OLEDB__ErrorElementWrapper();

 public:
  /// <summary>
  ///  ������� ������
  /// </summary>
  //! \param[in] pErrorRecord
  //!  Not NULL
  //! \return
  //!  ��������� ������������������ ���������
  static ole_lib::IUnknownPtr Create(const err_record_type* pErrorRecord);

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //IBP_IErrorExtendedParameter interface --------------------------------
  virtual HRESULT __stdcall GetErrorDescription(LCID  lcid,
                                                BSTR* pbstrSource,
                                                BSTR* pbstrDescription) COMP_W000004_OVERRIDE_FINAL;

 private:
  /// ��������� �� ����������� �������� ������
  const err_record_cptr m_spErrorRecord;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(IBP_OLEDB__ErrorElementWrapper)
};//class IBP_OLEDB__ErrorElementWrapper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
