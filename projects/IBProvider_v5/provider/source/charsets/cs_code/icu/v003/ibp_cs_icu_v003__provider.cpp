////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v003
//! \file    ibp_cs_icu_v003__provider.cpp
//! \brief   Провайдер к ICU API v3
//! \author  Kovalenko Dmitry
//! \date    07.10.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/icu/v003/ibp_cs_icu_v003.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v003{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_icu_provider

#define INIT_ICU_POINT(func_name)  \
 m_##func_name(pDLL,#func_name"_3_0")

t_ibp_icu_provider::t_ibp_icu_provider(dll_type* const pDLL)
 :INIT_ICU_POINT(ucnv_open)
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
 ,m_spDLL(lib::structure::not_null_ptr(pDLL))
{
 assert(m_spDLL);
}//t_ibp_icu_provider

#undef INIT_ICU_POINT

//------------------------------------------------------------------------
t_ibp_icu_provider::~t_ibp_icu_provider()
{
}//~t_ibp_icu_provider

//t_ibp_charset_provider interface ---------------------------------------
db_obj::t_db_charset_const_ptr
 t_ibp_icu_provider::load_cs(const cs_name_box_type& cs_name)
{
 return t_ibp_cs_icu::create(this,cs_name,/*must_be_created*/false);
}//load_cs

////////////////////////////////////////////////////////////////////////////////
}/*nms v003*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
