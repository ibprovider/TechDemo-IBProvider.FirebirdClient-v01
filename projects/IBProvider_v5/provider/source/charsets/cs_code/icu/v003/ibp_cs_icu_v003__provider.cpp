////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v003
//! \file    ibp_cs_icu_v003__provider.cpp
//! \brief   Провайдер к ICU API v3
//! \author  Kovalenko Dmitry
//! \date    07.10.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/icu/v003/ibp_cs_icu_v003.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v003{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_icu_provider

const GUID t_ibp_icu_provider::sm_DllInitSvcObjID
 {0x1D9FB5DF,0xD560,0x42A2,{0xB9,0x88,0x68,0x30,0xA1,0xE8,0x6E,0xB3}};

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_icu_provider

#define INIT_ICU_POINT(func_name)  \
 m_##func_name(pDLL,#func_name"_3_0")

t_ibp_icu_provider::t_ibp_icu_provider(dll_type* const pDLL)
 :INIT_ICU_POINT(u_init)
 ,INIT_ICU_POINT(u_cleanup)
 ,INIT_ICU_POINT(ucnv_open)
 ,INIT_ICU_POINT(ucnv_close)
 ,INIT_ICU_POINT(ucnv_setToUCallBack)
 ,INIT_ICU_POINT(ucnv_setFromUCallBack)
 ,INIT_ICU_POINT(UCNV_TO_U_CALLBACK_STOP)
 ,INIT_ICU_POINT(UCNV_FROM_U_CALLBACK_STOP)
 ,INIT_ICU_POINT(ucnv_fromUnicode)
 ,INIT_ICU_POINT(ucnv_toUnicode)
 ,INIT_ICU_POINT(ucnv_fromUChars)
 ,INIT_ICU_POINT(ucnv_toUChars)
 ,INIT_ICU_POINT(ucnv_getMinCharSize)
 ,INIT_ICU_POINT(ucnv_getMaxCharSize)
 ,INIT_ICU_POINT(ucnv_getType)
 ,m_spDLL(structure::not_null_ptr(pDLL))
 ,m_spDllInitMutex(helper__get_dll_init_mutex(pDLL))
{
 assert(m_spDLL);
 assert(m_spDllInitMutex);

 //---------------------------
 //
 // Initialization of pointers to primary functions.
 //

 m_u_init.point();
 m_u_cleanup.point();

 //---------------------------
 m_spDllInitMutex->do_initialize
  (structure::make_closure_r(this,&self_type::helper__init_op)); //throw
}//t_ibp_icu_provider

#undef INIT_ICU_POINT

//------------------------------------------------------------------------
t_ibp_icu_provider::~t_ibp_icu_provider()
{
 assert(m_spDllInitMutex);

 try
 {
  m_spDllInitMutex->do_uninitialize
   (structure::make_closure_r(this,&self_type::helper__uninit_op));
 }
 catch(...)
 {
  assert(false);
 }
}//~t_ibp_icu_provider

//t_ibp_charset_provider interface ---------------------------------------
db_obj::t_db_charset_const_ptr
 t_ibp_icu_provider::load_cs(const cs_name_box_type& cs_name)
{
 return t_ibp_cs_icu::create(this,cs_name,/*must_be_created*/false);
}//load_cs

//helper methods ---------------------------------------------------------
t_ibp_icu_provider::dll_init_mutex_ptr
 t_ibp_icu_provider::helper__get_dll_init_mutex(dll_type* const pDLL)
{
 assert(pDLL);

 const wchar_t* const c_bugcheck_src
  =L"icu::v003::t_ibp_icu_provider::helper__get_dll_init_mutex";

 IBP_SmartObjectPtr
  spSvcObj
   (pDLL->get_service_obj
     (sm_DllInitSvcObjID,
      helper__create_dll_init_mutex));

 assert(spSvcObj);

 dll_init_mutex_ptr
  spSvc
   (dynamic_cast<dll_init_mutex_type*>(spSvcObj.ptr()));

 IBP_BUG_CHECK__DETECT_BAD_OBJECT_NULL_PTR
  (spSvc,
   c_bugcheck_src,
   L"#001");

 return spSvc;
}//helper__get_dll_init_mutex

//------------------------------------------------------------------------
IBP_SmartObjectPtr t_ibp_icu_provider::helper__create_dll_init_mutex()
{
 return structure::not_null_ptr
         (new dll_init_mutex_type());
}//helper__create_dll_init_mutex

//------------------------------------------------------------------------
void t_ibp_icu_provider::helper__init_op()
{
 api::UErrorCode icu_status=api::U_ZERO_ERROR;

 m_u_init.point()(&icu_status);

 if(icu_status!=api::U_ZERO_ERROR)
 {
  t_ibp_error exc(E_FAIL,ibp_mce_icu__failed_to_initialize_2);

  exc<<this->id()
     <<icu_status;

  exc.raise_me();
 }//if
}//helper__init_op

//------------------------------------------------------------------------
void t_ibp_icu_provider::helper__uninit_op()
{
 m_u_cleanup.point()();
}//helper__uninit_op

////////////////////////////////////////////////////////////////////////////////
}/*nms v003*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
