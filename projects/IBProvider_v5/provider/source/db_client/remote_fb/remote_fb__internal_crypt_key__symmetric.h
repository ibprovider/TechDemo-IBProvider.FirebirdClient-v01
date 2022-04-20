////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__internal_crypt_key__symmetric.h
//! \brief   Реализация интерфейса для симметричного ключа шифрования.
//! \author  Kovalenko Dmitry
//! \date    18.09.2016
#ifndef _remote_fb__internal_crypt_key__symmetric_H_
#define _remote_fb__internal_crypt_key__symmetric_H_

#include "source/db_client/remote_fb/remote_fb__internal_crypt_key.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__InternalCryptKey__Symmetric

/// <summary>
///  Реализация интерфейса для симметричного ключа шифрования.
/// </summary>
class RemoteFB__InternalCryptKey__Symmetric
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__InternalCryptKey)
{
 private:
  typedef RemoteFB__InternalCryptKey__Symmetric              self_type;

  RemoteFB__InternalCryptKey__Symmetric(const self_type&);
  self_type& operator  = (const self_type&);

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] cbKey
  RemoteFB__InternalCryptKey__Symmetric(size_t cbKey);

  virtual ~RemoteFB__InternalCryptKey__Symmetric();

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  //! \param[in] cbKey
  //! \param[in] pKey
  static RemoteFB__InternalCryptKeyPtr Create(size_t      cbKey,
                                              const void* pKey);

  //interface ------------------------------------------------------------
  virtual tname_type GetType()const COMP_W000004_OVERRIDE_FINAL;

  virtual const RemoteFB__CryptKeyDataView GetEncryptKey()const COMP_W000004_OVERRIDE_FINAL;

  virtual const RemoteFB__CryptKeyDataView GetDecryptKey()const COMP_W000004_OVERRIDE_FINAL;

 private:
  typedef RemoteFB__MemoryAllocator         raw_allocator_type;

  static void* operator new (size_t const sz); //not impl

  static void* operator new (size_t,void* const pv)
  {//DONE: проверить
   return pv;
  }

 public:
  static void operator delete (void* pv)
  {
   return raw_allocator_type::instance.deallocate(pv,0);
  }

  #if(COMP_CONF_SUPPORT_OPERATOR_DELETE_EX)
  static void operator delete(void* /*pv*/,void* /*pv2*/)
  {
   //memory will be deallocated in catch of self_type::create
  }
  #endif

 private:
  const void* helper__getKeyData()const;

 private:
  size_t const m_cbKey;

 private:
  static const wchar_t sm_TypeName[];

 private:
  /*далее, в памяти размещаются данные ключа*/
};//class RemoteFB__InternalCryptKey__Symmetric

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
