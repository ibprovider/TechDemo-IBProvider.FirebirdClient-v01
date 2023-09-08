////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32_auth__descr_builder.cpp
//! \brief   Провайдер Windows Authentication API
//! \author  Kovalenko Dmitry
//! \date    25.11.2014
#include <_pch_.h>
#pragma hdrstop

#include "source/os/win32/auth/ibp_os_win32_auth__descr_builder.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace os{namespace win32{namespace auth{
////////////////////////////////////////////////////////////////////////////////
//class t_auth__descr_builder

t_auth__descr_builder::t_auth__descr_builder()
{
 SecInvalidateHandle(&m_hCtxt);
}//t_auth__descr_builder

//-------------------------------------------------------------------------
t_auth__descr_builder::~t_auth__descr_builder()
{
 try
 {
  this->helper__free(); //throw
 }
 catch(...)
 {
  assert(false);
 }//catch
}//~t_auth__descr_builder

//interface --------------------------------------------------------------
bool t_auth__descr_builder::is_completed()const
{
 if(m_LastResultCode.null())
  return false;

 if(m_LastResultCode.value()!=SEC_E_OK)
  return false;

 return true;
}//is_completed

//------------------------------------------------------------------------
void t_auth__descr_builder::request(t_auth__provider* const pProvider,
                                    size_t            const cbInput,
                                    const void*       const pvInput,
                                    output_type&            Output)
{
 assert(pProvider!=nullptr);

 CHECK_READ_PTR(pvInput,cbInput);

 assert(!m_spProvider || m_spProvider==pProvider);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"t_auth__descr_builder::request";

 //-----------------------------------------
 if(!m_LastResultCode.null())
 {
  if(m_LastResultCode.value()==SEC_E_OK)
  {
   //ERROR - [BUG CHECK] процесс аутентификации завершен

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#001",
     L"authentication process already completed");
  }//if

  assert(m_LastResultCode.value()!=SEC_E_OK);

  assert(m_spProvider);

  if(m_spProvider!=pProvider)
  {
   //ERROR - [BUG CHECK] некорректный провайдер

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#002",
     L"incorrect provider");
  }//if
 }
 else
 {
  assert(m_LastResultCode.null());

  if(SecIsValidHandle(&m_hCtxt))
  {
   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#003",
     L"incorrect state");
  }//if

  assert(!SecIsValidHandle(&m_hCtxt));

  //----------------------------------------
  pProvider->m_InitializeSecurityContext.point(); //throw
  pProvider->m_DeleteSecurityContext.point();     //throw

  //----------------------------------------
  m_spProvider=structure::not_null_ptr(pProvider);
 }//else

 assert(m_spProvider);

 //-----------------------------------------
 const size_t c_OutputBufSizeStep=4*1024;

 if(size_t const c=Output.capacity())
  Output.alloc(c);                       // throw
 else
  Output.alloc(c_OutputBufSizeStep);     // throw

 assert(!Output.empty());

 //-----------------------------------------
 API::AUTH__TimeStamp timeOut;

 API::AUTH__SecBuffer      inputBuffer;
 API::AUTH__SecBufferDesc  inputDesc;
 API::AUTH__SecBuffer      outputBuffer;
 API::AUTH__SecBufferDesc  outputDesc;

 for(;;)
 {
  self_type::helper__makeDesc
   (inputDesc,
    inputBuffer,
    cbInput,
    const_cast<void*>(pvInput) /*sorry*/);

  self_type::helper__makeDesc
   (outputDesc,
    outputBuffer,
    Output.size(),
    Output.buffer());

  ULONG fContextAttr=0;

  const bool IsFirstCall=SecIsValidHandle(&m_hCtxt);

  m_LastResultCode
   =m_spProvider->m_InitializeSecurityContext.point()
     (/*phCredential*/pProvider->GetCredHandle(),              // Cred to base context
      /*phContext*/IsFirstCall?&m_hCtxt:nullptr,   // Existing context (OPT)
      /*pszTargetName*/nullptr,                    // Name of target
      /*fContextReq*/0,                                        // Context Requirements
      /*Reserved1*/0,                                          // Reserved, MBZ
      /*TargetDataRep*/SECURITY_NATIVE_DREP,                   // Data rep of target
      /*pInput*/IsFirstCall?&inputDesc:nullptr,    // Input Buffers
      /*Reserved2*/0,                                          // Reserved, MBZ
      /*phNewContext*/&m_hCtxt,                                // (out) New Context handle
      /*pOutput*/&outputDesc,                                  // (inout) Output Buffers
      /*pfContextAttr*/&fContextAttr,                          // (out) Context attrs
      /*ptsExpiry*/&timeOut);                                  // (out) Life span (OPT)

  assert(!m_LastResultCode.null());

  switch(m_LastResultCode.value())
  {
   case SEC_E_OK:
   {
    assert(SecIsValidHandle(&m_hCtxt)); //Research

    //освобождаем ресурсы, потому что они нам больше не нужны
    this->helper__free();

    //код завершения последней операции должен сохраниться.
    assert(!m_LastResultCode.null());

    break;
   }//case - SEC_E_OK

   case SEC_I_CONTINUE_NEEDED:
   {
    assert(SecIsValidHandle(&m_hCtxt));

    assert(m_spProvider);

    break;
   }//case - SEC_I_CONTINUE_NEEDED

   case SEC_E_BUFFER_TOO_SMALL:
   {
    //увеличиваем размер буфера

    const size_t c_max_memory
     =structure::t_numeric_limits<size_t>::max_value();

    size_t newSize=Output.size();

    assert(newSize>0);

    if(newSize==c_max_memory)
     throw std::bad_alloc();

    if(newSize<=c_max_memory/2)
     newSize=2*newSize;
    else
    if(!structure::append_memory_size(newSize,c_OutputBufSizeStep))
     newSize=c_max_memory;

    assert(Output.size()<newSize);

    Output.free();

    Output.alloc(newSize); //throw

    continue;
   }//case - SEC_E_BUFFER_TOO_SMALL

   default:
   {
    // ERROR - failed to initialize security context

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_mce_win32__auth__fail_func_call_2,
      pProvider->m_InitializeSecurityContext.point_name(),
      m_LastResultCode.value());
   }//default
  }//switch m_LastResultCode.value()

  assert(!m_LastResultCode.null());

  break;
 }//for[ever]

 assert(!m_LastResultCode.null());

 //проверка корректности результирующих данных

 if(Output.size()<outputBuffer.cbBuffer)
 {
  //ERROR - [BUG CHECK] некорректный размер output-данных

  IBP_BUG_CHECK__DEBUG
   (c_bugcheck_src,
    L"#004",
    L"incorrect size of output data");
 }//if

 assert(outputBuffer.cbBuffer<=Output.size());

 Output.truncate(outputBuffer.cbBuffer);

 assert(Output.size()==outputBuffer.cbBuffer);
}//request

//helper methods ---------------------------------------------------------
void t_auth__descr_builder::helper__free()
{
 if(SecIsValidHandle(&m_hCtxt))
 {
  assert(m_spProvider);

  const auth_err_code_type
   authErr
    =m_spProvider->m_DeleteSecurityContext.point()(&m_hCtxt);

  if(authErr!=SEC_E_OK)
  {
   // ERROR - failed to destroy security context
   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_win32__auth__fail_func_call_2,
     m_spProvider->m_DeleteSecurityContext.point_name(),
     authErr);
  }//if

  assert(authErr==SEC_E_OK);

  SecInvalidateHandle(&m_hCtxt);
 }//if SecIsValidHandle(&m_hCtxt)

 assert(!SecIsValidHandle(&m_hCtxt));

 m_spProvider.Release();
}//helper__free

//------------------------------------------------------------------------
void t_auth__descr_builder::helper__makeDesc(API::AUTH__SecBufferDesc& d,
                                             API::AUTH__SecBuffer&     b,
                                             size_t       const        len,
                                             void*        const        p)
{
 b.BufferType = SECBUFFER_TOKEN;

 if(structure::can_numeric_cast(&b.cbBuffer,len))
  structure::static_numeric_cast(&b.cbBuffer,len);
 else
  b.cbBuffer=structure::get_numeric_limits(b.cbBuffer).max_value();

 assert(b.cbBuffer<=len);

 b.pvBuffer   = len?p:nullptr;

 //-----------------------------------------
 d.ulVersion  = SECBUFFER_VERSION;
 d.cBuffers   = 1;
 d.pBuffers   = &b;
}//helper__makeDesc

////////////////////////////////////////////////////////////////////////////////
}/*nms auth*/}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
