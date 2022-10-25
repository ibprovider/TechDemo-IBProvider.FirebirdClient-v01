////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_utils.cpp
//! \brief   ”тилиты дл€ работы с OLEDB-ошибками
//! \author  Kovalenko Dmitry
//! \date    03.06.2010
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/error/ibp_oledb__error_utils.h"
#include "source/oledb/error/ibp_oledb__error_param_idxs.h"
#include "source/oledb/error/ibp_oledb__custom_error_object.h"
#include "source/oledb/error/ibp_oledb__error_element_wrapper.h"
#include "source/oledb/ibp_oledb__error_variant_utils.h"

#include "source/error_services/ibp_error_utils.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

#include <structure/t_numeric_cast.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorUtils

HRESULT IBP_OLEDB__ErrorUtils::add_oledb_error
                                    (REFCLSID                            providerClassID,
                                     IErrorRecords*                const pErrorRecords,
                                     REFIID                              exc_riid,
                                     const base_error_record_type* const pError)
{
 assert(pErrorRecords);
 assert(pError);

 //---------------------
#ifdef _DEBUG_LEVEL_3_
 {
  base_error_record_type::string_type source;
  base_error_record_type::string_type description;

  _VERIFY(pError->get_description(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),
                                  &source,
                                  &description));

  const HRESULT err_code=IBP_MapErrorRecordToHRESULT(pError);

  LPCSTR const msg_pref=FAILED(err_code)?"ERR":((err_code!=S_OK)?"WAR":"");

  ODS_LEVEL_3(msg_pref<<":[OLEDB] "
              "hr="<<structure::tstr_to_str(oledb_lib::GetDBOleHResult(err_code))
              <<" - "
              <<"["<<structure::tstr_to_str(source)<<"] "
              <<structure::tstr_to_str(description));
 }
#endif

 //---------------------
 if(const error_record_type* const x=dynamic_cast<const error_record_type*>(pError))
 {
  return self_type::helper__add_oledb_error
          (providerClassID,
           pErrorRecords,
           exc_riid,
           x,
           x->m_err_code,
           x->m_varSourceID,
           x->m_varSubSystemID,
           x->m_msg_code,
           x->m_params.size(),
           x->m_params.data());
 }//if

 //----
 const HRESULT err_code=IBP_MapErrorRecordToHRESULT(pError);

 const ole_lib::IUnknownPtr spElement(IBP_OLEDB__ErrorElementWrapper::Create(pError));

 assert(spElement);

 const IBP_ErrorVariant var(spElement);

 assert(var.Data().vt==IBP_EVT::V_IUNKNOWN);

 return self_type::helper__add_oledb_error
         (providerClassID,
          pErrorRecords,
          exc_riid,
          pError,
          err_code,
          /*varSourceID*/ole_lib::TVariant::empty_variant,
          /*varSubSystemID*/ole_lib::TVariant::empty_variant,
          ibp_mce_unknown_error_1,
          1,
          &var);
}//add_oledb_error

//------------------------------------------------------------------------
HRESULT IBP_OLEDB__ErrorUtils::helper__add_oledb_error
                                    (REFCLSID                            providerClassID,
                                     IErrorRecords*                const pErrorRecords,
                                     REFIID                              exc_riid,
                                     const base_error_record_type* const pError,
                                     HRESULT                       const err_code,
                                     const VARIANT&                      varSourceID,
                                     const VARIANT&                      varSubSystemID,
                                     mc_type                       const msg_code,
                                     size_t                        const cArgs,
                                     const IBP_ErrorVariant*       const rgArgs)
{
 assert(providerClassID==_Module.Get_CLSID_IBProvider() ||
        providerClassID==_Module.Get_CLSID_IBProvider__private());

 assert(pErrorRecords);
 assert(pError);

 CHECK_READ_TYPED_PTR(rgArgs,cArgs);

 //----------------------------------------- перегружаем аргументы в VARIANT
 typedef structure::t_stl_vector<ole_lib::TVariant,IBP_MemoryAllocator> TVarArgs;

 //! \todo
 //!   онтролировать переполнение сложени€?

 TVarArgs VarArgs(ibp_oledb_err_param_idx__arg0+cArgs);

 //--------
 VarArgs[ibp_oledb_err_param_idx__source_id]   =varSourceID;
 VarArgs[ibp_oledb_err_param_idx__subsystem_id]=varSubSystemID;

 //--------
 for(size_t iArg(0);iArg!=cArgs;++iArg)
 {
  ole_lib::TVariant* const pDestArg=&VarArgs[ibp_oledb_err_param_idx__arg0+iArg];

  const bool cvt_r=IBP_OLEDB__ERRORVARIANT_UTILS::PackIntoVARIANT(rgArgs[iArg].Data(),pDestArg);

  assert(cvt_r);

  if(!cvt_r)
   (*pDestArg)=L"<error>";
 }//for iArg

 //-----------------------------------------
 ERRORINFO ei={};

 ei.hrError = err_code;
 ei.dwMinor = msg_code;
 ei.clsid   = providerClassID;
 ei.iid     = exc_riid;

 DISPPARAMS params={};

 params.rgvarg=const_cast<ole_lib::TVariant*>(VarArgs.data());

 //очень маловеро€тно, что у нас будет больше 4GB параметров
 structure::static_numeric_cast(&params.cArgs,VarArgs.size());

 assert(params.cArgs==VarArgs.size());

 //-----------------------------------------
 const ole_lib::IPtr2<IBP_OLEDB__CustomErrorObject>
  spCustomErrorObject
   (lib::structure::not_null_ptr
     (new IBP_OLEDB__CustomErrorObject
       (/*pUnkOuter*/nullptr,
        pError)));

 {
  const HRESULT init_hr=spCustomErrorObject->Init();

  if(FAILED(init_hr))
   ole_lib::t_base_com_error::throw_error(init_hr);

  assert(init_hr==S_OK);
 }//local

 return pErrorRecords->AddErrorRecord
         (&ei,
          msg_code,
          &params,
          spCustomErrorObject,
          0);
}//helper__add_oledb_error

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
