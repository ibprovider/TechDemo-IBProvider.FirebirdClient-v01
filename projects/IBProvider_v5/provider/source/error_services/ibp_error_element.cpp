////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_element.cpp
//! \brief   Ёлемент коллекции ошибок
//! \author  Kovalenko Dmitry
//! \date    21.02.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error_element.h"
#include "source/error_services/ibp_error_build_message.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error::tag_error_args

t_ibp_error_element::t_ibp_error_element(HRESULT const err_code,
                                         mc_type const msg_code)
 :m_msg_code(msg_code)
 ,m_err_code(err_code)
{;}

//------------------------------------------------------------------------
t_ibp_error_element::t_ibp_error_element(HRESULT                 const err_code,
                                         mc_type                 const msg_code,
                                         ibprovider::IBP_IClone* const pCErr)
 :m_msg_code(msg_code)
 ,m_err_code(err_code)
 ,m_spCustomError(pCErr)
{;}

//------------------------------------------------------------------------
t_ibp_error_element::t_ibp_error_element(HRESULT            const err_code,
                                         t_ibp_subsystem_id const subsys_id,
                                         mc_type            const msg_code)
 :m_varSubSystemID(static_cast<LONG>(subsys_id))
 ,m_msg_code      (msg_code)
 ,m_err_code      (err_code)
{;}

//------------------------------------------------------------------------
t_ibp_error_element::t_ibp_error_element(HRESULT                 const err_code,
                                         t_ibp_subsystem_id      const subsys_id,
                                         mc_type                 const msg_code,
                                         ibprovider::IBP_IClone* const pCErr)
 :m_varSubSystemID(static_cast<LONG>(subsys_id))
 ,m_msg_code      (msg_code)
 ,m_err_code      (err_code)
 ,m_spCustomError (pCErr)
{;}

//------------------------------------------------------------------------
t_ibp_error_element::~t_ibp_error_element()
{;}

//------------------------------------------------------------------------
void t_ibp_error_element::set_subsystem_id(t_ibp_subsystem_id const subsys_id)
{
 //! \attention
 //!  ƒопускаетс€ только однократна€ установка подсистемы ошибки.
 assert(m_varSubSystemID.IsEmpty());

 m_varSubSystemID=static_cast<LONG>(subsys_id);
}//set_subsystem_id

//------------------------------------------------------------------------
std::wstring t_ibp_error_element::get_sqlstate()const
{
 if(!m_spCustomError)
  return std::wstring();

 const oledb_lib::ISQLErrorInfoPtr
  spSqlEI(structure::not_null_ptr(static_cast<IUnknown*>(m_spCustomError.ptr())));

 if(spSqlEI.m_hr==E_NOINTERFACE)
  return std::wstring();

 //! \todo
 //!  [2016-07-25] ћожет имеет смысл выкидывать исключени€ с вразумительными сообщени€ми?

 if(FAILED(spSqlEI.m_hr))
  ole_lib::t_base_com_error::throw_error(spSqlEI.m_hr);

 assert(spSqlEI.m_hr==S_OK);

 if(!spSqlEI)
 {
  assert(false);

  ole_lib::t_base_com_error::throw_error(E_UNEXPECTED);
 }//if !spSqlEI

 assert(spSqlEI);

 ole_lib::TBSTR bstrSqlState;

 LONG lNativeError=0;

 const HRESULT
  hr=spSqlEI->GetSQLInfo(&bstrSqlState.ref_bstr(),&lNativeError);

 if(FAILED(hr))
  ole_lib::t_base_com_error::throw_error(hr);

 assert(hr==S_OK);

 return bstrSqlState.wstr(); //throw
}//get_sqlstate

//t_ibp_get_custom_error_object interface --------------------------------
ole_lib::IUnknownPtr t_ibp_error_element::get_custom_error_object(IUnknown* const pUnkOuter)const
{
 if(!m_spCustomError)
  return nullptr;

 ole_lib::IUnknownPtr spClone;

 const HRESULT hr=m_spCustomError->Clone(pUnkOuter,&spClone.ref_ptr());

 if(FAILED(hr))
  ole_lib::t_base_com_error::throw_error(hr);

 assert(hr==S_OK);

 return spClone;
}//get_custom_error_object

//t_err_record interface -------------------------------------------------
const char* t_ibp_error_element::what()const throw()
{
 return "IBProvider Error";
}//what

//------------------------------------------------------------------------
t_ibp_error_element::system_id_type t_ibp_error_element::get_system_id()const
{
 return self_type::system_com;
}//get_system_id

//------------------------------------------------------------------------
t_ibp_error_element::subsystem_id_type t_ibp_error_element::get_subsystem_id()const
{
 return self_type::user_subsystem_unk;
}//get_subsystem_id

//------------------------------------------------------------------------
t_ibp_error_element::error_code_type t_ibp_error_element::get_error_code()const
{
 return m_err_code;
}//get_error_code

//------------------------------------------------------------------------
bool t_ibp_error_element::get_description(lcid_type          lcid,
                                          string_type* const source,
                                          string_type* const description)const
{
 string_type tmp_source;
 string_type tmp_description;

 bool res1=true;
 bool res2=true;

 if(lcid.get_kind()!=lcid_type::kind__number)
  lcid=MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL);

 if(source!=nullptr)
 {
  res1=TIBP_MessageTextBuilder::BuildSrc(&tmp_source,
                                         m_varSourceID);
 }//if source!=NULL

 if(description!=nullptr)
 {
  assert_s(sizeof(oledb_lib::TDBVariant)==sizeof(oledb_lib::DBVARIANT));

  res2=TIBP_MessageTextBuilder::Build(&tmp_description,
                                      m_varSubSystemID,
                                      m_msg_code,
                                      lcid.get_number(),
                                      m_params.size(),
                                      m_params.data(),
                                      m_err_code);
 }//if description!=NULL

 //----
 if(source!=nullptr)
  source->swap(tmp_source);

 if(description!=nullptr)
  description->swap(tmp_description);

 //----
 return res1 && res2;
}//get_description

//------------------------------------------------------------------------
bool t_ibp_error_element::get_help_info(lcid_type         const /*lcid*/,
                                        string_type*      const help_file,
                                        help_ctx_id_type* const help_context_id)const
{
 if(help_file!=NULL)
  help_file->clear();

 if(help_context_id!=NULL)
  (*help_context_id)=0;

 return false;
}//get_help_info

//вспомогательные утилиты ------------------------------------------------
t_ibp_error_element& t_ibp_error_element::add_arg(const base_variant_type& x)
{
 assert(!m_params.full());

 m_params.push_back(x);

 return *this;
}//add_args

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
