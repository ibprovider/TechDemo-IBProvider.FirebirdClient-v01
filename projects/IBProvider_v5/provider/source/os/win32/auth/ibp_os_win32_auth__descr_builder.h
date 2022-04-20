////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32_auth__descr_builder.h
//! \brief   Провайдер Windows Authentication API
//! \author  Kovalenko Dmitry
//! \date    25.11.2014
#ifndef _ibp_os_win32_auth__descr_builder_H_
#define _ibp_os_win32_auth__descr_builder_H_

#include "source/os/win32/auth/ibp_os_win32_auth__provider.h"
#include <structure/t_simple_buffer.h>
#include <structure/t_value_with_null.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{namespace auth{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_auth__descr_builder

class t_auth__descr_builder
{
 private:
  typedef t_auth__descr_builder             self_type;

  t_auth__descr_builder(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef IBP_MemoryAllocator               allocator_type;

  typedef structure::t_void_simple_buffer
           <allocator_type>                 output_type;

 public:
  t_auth__descr_builder();

 ~t_auth__descr_builder();

  //interface ------------------------------------------------------------
  bool is_completed()const;

  void request(t_auth__provider* pProvider,
               size_t            cbInput,
               const void*       pvInput,
               output_type&      Output);

 private:
  void helper__free();

  static void helper__makeDesc(API::AUTH__SecBufferDesc& d,
                               API::AUTH__SecBuffer&     b,
                               size_t                    len,
                               void*                     p);
 private:
  typedef API::AUTH__SECURITY_STATUS                        auth_err_code_type;
  typedef structure::t_value_with_null<auth_err_code_type>  auth_err_code_type_N;

 private:
  auth_err_code_type_N m_LastResultCode;

  t_auth__provider::self_ptr m_spProvider;

  API::AUTH__CtxtHandle m_hCtxt;
};//class t_auth__descr_builder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms auth*/}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif

