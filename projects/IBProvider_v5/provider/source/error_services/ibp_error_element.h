////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_element.h
//! \brief   ??????? ????????? ??????
//! \author  Kovalenko Dmitry
//! \date    21.02.2003
#ifndef _ibp_error_element_H_
#define _ibp_error_element_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/error_services/ibp_error_args.h"
#include "source/error_services/ibp_get_custom_error_object.h"
//#include "source/error_services/ibp_error_codes.h"
#include "source/db_obj/db_memory.h"
#include "source/ibp_memory.h"
#include "source/ibp_subsystem_ids.h"
#include "source/ibp_limits.h"
#include <ole_lib/oledb/variant/oledb_xvariant.h>
#include <ole_lib/ole_auto/ole_auto_variant.h>
#include <structure/error/t_err_record.h>
#include <structure/t_fix_vector.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

class t_ibp_error_element;

////////////////////////////////////////////////////////////////////////////////
//struct t_ibp_error_element_traits

struct t_ibp_error_element_traits
{
 typedef t_ibp_error_element_traits                 self_type;

 typedef t_ibp_error_args<self_type>                args_type;

 typedef t_ibp_error_element                        out_return_type;

 static out_return_type& out_ret(args_type& x);
};//struct t_ibp_error_element_traits

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_element

/// <summary>
///  ??????? ????????? ??????
/// </summary>
class t_ibp_error_element
 :public t_ibp_get_custom_error_object
 ,public structure::t_err_record
 ,public t_ibp_error_element_traits::args_type
 ,public db_obj::t_db_smart_object_base2
{
 private:
  typedef t_ibp_error_element                       self_type;
  typedef structure::t_err_record                   inherited_record;

  t_ibp_error_element(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  ??????????
  /// </summary>
  virtual ~t_ibp_error_element();

 public: //typedefs ------------------------------------------------------
  ///?????-????????? ?? ??????
  typedef structure::t_smart_object_ptr<self_type>  self_ptr;

  typedef inherited_record::string_type             string_type;
  typedef inherited_record::system_id_type          system_id_type;
  typedef inherited_record::subsystem_id_type       subsystem_id_type;
  typedef inherited_record::lcid_type               lcid_type;
  typedef inherited_record::help_ctx_id_type        help_ctx_id_type;

  DECLARE_IPTR_TYPE(IErrorInfo);
  DECLARE_IPTR_TYPE(IErrorRecords);

  typedef ibp_msg_code_type                         mc_type;

  typedef structure::t_fix_vector
           <ibp_limc_MaxErrorArgsCount,
            oledb_lib::TDBVariant>                  params_type;

 public:
  ///????????????? ????????? ??????
  ole_lib::TVariant m_varSourceID;

  ///????????????? ??????????
  ole_lib::TVariant m_varSubSystemID;

  ///????????????? ?????????
  mc_type m_msg_code;

  ///??? ??????
  HRESULT m_err_code;

  ///????????? ??????
  params_type m_params;

  ///Custom error object
  ole_lib::IPtr2<ibprovider::IBP_IClone> m_spCustomError;

 public:
  /// <summary>
  ///  ??????????? ?????????????
  /// </summary>
  //! \param[in] err_code
  //! \param[in] msg_code
  t_ibp_error_element(HRESULT err_code,
                      mc_type msg_code);

  /// <summary>
  ///  ??????????? ?????????????
  /// </summary>
  //! \param[in] err_code
  //! \param[in] msg_code
  //! \param[in] pCErr
  t_ibp_error_element(HRESULT                 err_code,
                      mc_type                 msg_code,
                      ibprovider::IBP_IClone* pCErr);

  /// <summary>
  ///  ??????????? ?????????????
  /// </summary>
  //! \param[in] err_code
  //! \param[in] subsys_id
  //! \param[in] msg_code
  t_ibp_error_element(HRESULT            err_code,
                      t_ibp_subsystem_id subsys_id,
                      mc_type            msg_code);

  /// <summary>
  ///  ??????????? ?????????????
  /// </summary>
  //! \param[in] err_code
  //! \param[in] subsys_id
  //! \param[in] msg_code
  //! \param[in] pCErr
  t_ibp_error_element(HRESULT                 err_code,
                      t_ibp_subsystem_id      subsys_id,
                      mc_type                 msg_code,
                      ibprovider::IBP_IClone* pCErr);

  //smart interface ------------------------------------------------------
  SLIB__DECLARE_SMART_OBJ_MANAGEMENT_METHODS__FINAL

  //interface ------------------------------------------------------------
  virtual ole_lib::IUnknownPtr get_custom_error_object(IUnknown* pUnkOuter)const COMP_W000004_OVERRIDE_FINAL;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  ???????? ?????????? ??????
  /// </summary>
  //! \param[in] subsys_id
  void set_subsystem_id(t_ibp_subsystem_id subsys_id);

  /// <summary>
  ///  ????????? SQLSTATE ??????. THROW.
  /// </summary>
  std::wstring get_sqlstate()const;

  //t_err_record interface -----------------------------------------------
  /// <summary>
  ///  Build simple error message text
  /// </summary>
  virtual const char* what()const throw() COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Get an error system ID
  /// </summary>
  virtual system_id_type get_system_id()const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Get an error subsystem ID
  /// </summary>
  virtual subsystem_id_type get_subsystem_id()const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Get an error code
  /// </summary>
  virtual error_code_type get_error_code()const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Get an error description
  /// </summary>
  virtual bool get_description(lcid_type    lcid,
                               string_type* source,
                               string_type* description)const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Get an error help info
  /// </summary>
  virtual bool get_help_info(lcid_type         lcid,
                             string_type*      help_file,
                             help_ctx_id_type* help_context_id)const COMP_W000004_OVERRIDE_FINAL;

 public: //??????????????? ??????? --------------------------------------
  virtual self_type& add_arg(const base_variant_type& x) COMP_W000004_OVERRIDE_FINAL;//virtual
};//class t_ibp_error_element

////////////////////////////////////////////////////////////////////////////////
//struct t_ibp_error_element_traits

inline t_ibp_error_element_traits::out_return_type&
 t_ibp_error_element_traits::out_ret(args_type& x)
{
 return *static_cast<out_return_type*>(&x);
}//out_ret

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
