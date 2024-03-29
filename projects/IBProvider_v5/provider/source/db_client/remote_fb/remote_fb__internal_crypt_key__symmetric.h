////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__internal_crypt_key__symmetric.h
//! \brief   ���������� ���������� ��� ������������� ����� ����������.
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
///  ���������� ���������� ��� ������������� ����� ����������.
/// </summary>
class RemoteFB__InternalCryptKey__Symmetric LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__InternalCryptKey)
{
 private:
  using self_type=RemoteFB__InternalCryptKey__Symmetric;

  RemoteFB__InternalCryptKey__Symmetric(const self_type&)=delete;
  self_type& operator  = (const self_type&)=delete;

 private:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] cbKey
  explicit RemoteFB__InternalCryptKey__Symmetric(size_t cbKey);

  virtual ~RemoteFB__InternalCryptKey__Symmetric();

 public:
  /// <summary>
  ///  ������� ������
  /// </summary>
  //! \param[in] cbKey
  //! \param[in] pKey
  static RemoteFB__InternalCryptKeyPtr Create(size_t      cbKey,
                                              const void* pKey);

  //interface ------------------------------------------------------------
  virtual tname_type GetType()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual const RemoteFB__CryptKeyDataView GetEncryptKey()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual const RemoteFB__CryptKeyDataView GetDecryptKey()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  using raw_allocator_type=RemoteFB__MemoryAllocator;

  static void* operator new (size_t const sz); //not impl

  static void* operator new (size_t,void* const pv)
  {//DONE: ���������
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
  /*�����, � ������ ����������� ������ �����*/
};//class RemoteFB__InternalCryptKey__Symmetric

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
