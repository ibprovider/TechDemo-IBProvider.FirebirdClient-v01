////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__internal_crypt_key__symmetric.h
//! \brief   Реализация интерфейса для симметричного ключа шифрования.
//! \author  Kovalenko Dmitry
//! \date    18.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__internal_crypt_key__symmetric.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__InternalCryptKey__Symmetric

const wchar_t RemoteFB__InternalCryptKey__Symmetric::sm_TypeName[]
 =L"Symmetric";

//------------------------------------------------------------------------
RemoteFB__InternalCryptKey__Symmetric::RemoteFB__InternalCryptKey__Symmetric(size_t const cbKey)
 :m_cbKey(cbKey)
{;}

//------------------------------------------------------------------------
RemoteFB__InternalCryptKey__Symmetric::~RemoteFB__InternalCryptKey__Symmetric()
{;}

//factory ----------------------------------------------------------------
RemoteFB__InternalCryptKeyPtr
 RemoteFB__InternalCryptKey__Symmetric::Create(size_t      const cbKey,
                                               const void* const pKey)
{
 assert(cbKey>0);

 CHECK_READ_PTR(pKey,cbKey);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__InternalCryptKey__Symmetric::Create";

 //-----------------------------------------
 size_t sz=sizeof(self_type);

 const size_t offset_KeyData=sz;

 if(!lib::structure::append_memory_size(sz,cbKey))
 {
  IBP_ThrowOverflowInMemSizeCalculation
   (c_bugcheck_src,
    L"#001");
 }//if

 void* const pv=raw_allocator_type::instance.allocate(sz); //throw

 assert(pv);

 //сохраняем ключ в дополнительном пространстве
 memcpy(reinterpret_cast<char*>(pv)+offset_KeyData,
        pKey,
        cbKey);

 try
 {
  new(pv) self_type(cbKey); //throw
 }
 catch(...)
 {
  raw_allocator_type::instance.deallocate(pv,sz);

  throw;
 }//catch

 assert(pv);

 assert(reinterpret_cast<char*>(reinterpret_cast<self_type*>(pv)+1)==(reinterpret_cast<char*>(pv)+offset_KeyData));

 return lib::structure::not_null_ptr(reinterpret_cast<self_type*>(pv));
}//Create

//interface --------------------------------------------------------------
RemoteFB__InternalCryptKey__Symmetric::tname_type
 RemoteFB__InternalCryptKey__Symmetric::GetType()const
{
 return tname_type::create<sm_TypeName>();
}//GetType

//------------------------------------------------------------------------
const RemoteFB__CryptKeyDataView
 RemoteFB__InternalCryptKey__Symmetric::GetEncryptKey()const
{
 return RemoteFB__CryptKeyDataView(m_cbKey,this->helper__getKeyData());
}//GetEncryptKey

//------------------------------------------------------------------------
const RemoteFB__CryptKeyDataView
 RemoteFB__InternalCryptKey__Symmetric::GetDecryptKey()const
{
 return RemoteFB__CryptKeyDataView(m_cbKey,this->helper__getKeyData());
}//GetDecryptKey

//helper methods ---------------------------------------------------------
const void* RemoteFB__InternalCryptKey__Symmetric::helper__getKeyData()const
{
 return this+1;
}//helper__getKeyData

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
