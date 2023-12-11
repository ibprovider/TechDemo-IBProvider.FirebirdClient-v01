////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v03_0_0
//! \file    db_obj__dbms_fb__v03_0_0__svc__status_vector_utils.cpp
//! \brief   ���������� ������� ��� ������ �� ������ ��������.
//! \author  Kovalenko Dmitry
//! \date    11.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__svc__status_vector_utils.h"
#include "source/db_obj/dbms_fb/v03_0_0/api/db_obj__dbms_fb__v03_0_0__api__error_descrs2.h"
#include "source/error_services/ibp_error_build_message.h"
#include "rc/ibp_msg_fb30.rh"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v03_0_0{
////////////////////////////////////////////////////////////////////////////////

db_obj::t_db_object_ptr create_svc__status_vector_utils()
{
 return fb_v03_0_0__svc__status_vector_utils::create();
}//create_svc__status_vector_utils

////////////////////////////////////////////////////////////////////////////////
//class fb_v03_0_0__svc__status_vector_utils

fb_v03_0_0__svc__status_vector_utils
 fb_v03_0_0__svc__status_vector_utils::sm_Instance;

//------------------------------------------------------------------------
fb_v03_0_0__svc__status_vector_utils::fb_v03_0_0__svc__status_vector_utils()
 :inherited(_DIM_(api::g_fb_v03_0_0__error_descrs2),
            api::g_fb_v03_0_0__error_descrs2)
 ,m_ErrMsgTableLoader(&ibp::_ResourceLoader,
                      IBP_MSG_TABLE_FB30_ERR)
{;}

//------------------------------------------------------------------------
fb_v03_0_0__svc__status_vector_utils::~fb_v03_0_0__svc__status_vector_utils()
{;}

//------------------------------------------------------------------------
common::fb_common__svc__status_vector_utils_ptr
 fb_v03_0_0__svc__status_vector_utils::create()
{
 return lib::structure::not_null_ptr(&sm_Instance);
}//create

//internal interface -----------------------------------------------------
void fb_v03_0_0__svc__status_vector_utils::internal__build_err_message
                                           (std::wstring*               const pResultText,
                                            DWORD                       const msg_code,
                                            LCID                        const lcid,
                                            size_t                      const cArgs,
                                            const IBP_ErrorVariant*     const rgArgs)const
{
 DEBUG_CODE(bool const build_result=)
  TIBP_MessageTextBuilder::Build
     (pResultText,
      msg_code,
      lcid,
      cArgs,
      rgArgs,
      m_ErrMsgTableLoader);

 assert_msg(build_result,"msg_code="<<msg_code);
}//internal__build_err_message

//------------------------------------------------------------------------
bool fb_v03_0_0__svc__status_vector_utils::internal__is_useless_error_code
                                           (status_type s)const
{
 // random is useless - it's just "%s". skip it
 // sqlerr (sqlcode) is useless for determining sqlstate. skip it

 if(s==api::ibp_fb_v30_err__random)
  return true;

 if(s==api::ibp_fb_v30_err__sqlerr)
  return true;

 return false;
}//internal__is_useless_error_code

//------------------------------------------------------------------------
fb_v03_0_0__svc__status_vector_utils::status_type
 fb_v03_0_0__svc__status_vector_utils::internal__get_unexpected_error_code()const
{
 return api::ibp_fb_v30_err__unexpected_error;
}//internal__get_unexpected_error_code

////////////////////////////////////////////////////////////////////////////////
}/*nms v03_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
