////////////////////////////////////////////////////////////////////////////////
//Implementation of IBProvider-specific storage objects
//                                                 Kovalenko Dmitry. 04.09.2012.
#ifndef _oledb_variant_ibp_sstreams_H_
#define _oledb_variant_ibp_sstreams_H_

#include <lcpi/sdk/ibprovider/v05/lcpi_sdk__ibprovider__v05.h>

#include <ole_lib/oledb/oledb_common.h> //TOLEDBMemoryAllocator
#include <structure/t_threads.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class IInterface,const IID* PIID,class TChar,class Allocator>
class basic_dbvariant_ibp_sstream;

/////////////////////////////////////////////////////////////////////////////////
//template class basic_dbvariant_sstream

template<class IInterface,const IID* PIID,class TChar,class Allocator>
class basic_dbvariant_ibp_sstream:public IInterface
                                 ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef basic_dbvariant_ibp_sstream<IInterface,PIID,TChar,Allocator> self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler               inherited;

  basic_dbvariant_ibp_sstream(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef TChar                                        char_type;

  typedef size_t                                       size_type;

  typedef ole_lib::IPtr2<self_type>                    self_ptr;

  typedef structure::t_basic_const_str_box<char_type>  str_box_type;

 private:
  basic_dbvariant_ibp_sstream(size_type        size,
                              const char_type* data);

  virtual ~basic_dbvariant_ibp_sstream();

 public:
  static self_ptr Create(size_type        size,
                         const char_type* data);

  static self_ptr Create(str_box_type data);

  static HRESULT FullCreate(size_type        size,
                            const char_type* data,
                            REFIID           riid,
                            void**           ppv);

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //Stream interface -----------------------------------------------------
  virtual HRESULT __stdcall Read  (char_type*  pchars,
                                   SIZE_T      cch,
                                   SIZE_T*    pcchRead) COMP_W000004_OVERRIDE_FINAL;

  //E_NOTIMPL;
  virtual HRESULT __stdcall Write (const char_type* pchars,
                                   SIZE_T           cch,
                                   SIZE_T*          pcchWritten) COMP_W000004_OVERRIDE_FINAL;

 private:
  typedef __STLS_ALLOCATOR_REBIND(typename Allocator,void)    raw_allocator_type;

  //pv - pointer to memory allocated through allocator_type()::allocate
  static void* operator new (size_t const /*sz*/,void* const pv)
  {
   return pv;
  }

  static void operator delete(void* const pv)
  {
   raw_allocator_type::instance.deallocate(pv,0);
  }

  #if(COMP_CONF_SUPPORT_OPERATOR_DELETE_EX)
  static void operator delete(void* const /*pv*/,void* const /*pv2*/)
  {
   //memory will be deallocated in catch in basic_dbvariant_ibp_sstream::Create
  }
  #endif

 private: //internal typedefs --------------------------------------------
  typedef structure::t_multi_thread_traits             thread_traits;
  typedef thread_traits::guard_type                    guard_type;
  typedef thread_traits::lock_guard_type               lock_guard_type;

 private:
  guard_type   m_guard;
  size_type    m_size;
  size_type    m_pos;

 private:
  //last object element
  char_type    m_data[1];
};//class basic_dbvariant_ibp_sstream

////////////////////////////////////////////////////////////////////////////////
//helper for define an implementation for IBP_ISequentialStream_WideChar

#define OLEDB_LIB__DEF_IBP_SequentialStream_WideChar(Allocator)           \
 oledb_lib::basic_dbvariant_ibp_sstream                                   \
  <lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_WideChar,            \
   &lcpi::sdk::ibprovider::v05::IID_IBP_ISequentialStream_WideChar,       \
   WCHAR,                                                                 \
   Allocator>

////////////////////////////////////////////////////////////////////////////////
//helper for define an implementation for IBP_ISequentialStream_MultiByteChar

#define OLEDB_LIB__DEF_IBP_SequentialStream_MultiByteChar(Allocator)      \
 oledb_lib::basic_dbvariant_ibp_sstream                                   \
  <lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_MultiByteChar,       \
   &lcpi::sdk::ibprovider::v05::IID_IBP_ISequentialStream_MultiByteChar,  \
   CHAR,                                                                  \
   Allocator>

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef OLEDB_LIB__DEF_IBP_SequentialStream_WideChar(TOLEDBMemoryAllocator)
 TDBVariant_IBP_SequentialStream_WideChar;

typedef OLEDB_LIB__DEF_IBP_SequentialStream_MultiByteChar(TOLEDBMemoryAllocator)
 TDBVariant_IBP_SequentialStream_MultiByteChar;

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/variant/oledb_variant_ibp_sstreams.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
