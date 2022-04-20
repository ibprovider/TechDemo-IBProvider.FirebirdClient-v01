////////////////////////////////////////////////////////////////////////////////
//Реализация интерфейса ISequentialStream для публикации данных DBVARIANT через
// storage-объект
//                                        Коваленко Дмитрий. 3 июля 2002 года.

#ifndef _oledb_variant_sstream_H_
#define _oledb_variant_sstream_H_

#include <ole_lib/oledb/oledb_common.h> //TOLEDBMemoryAllocator
#include <ole_lib/ole_lib.h> //TBaseUnknown2_WithFreeThreadMarshaler
#include <structure/t_threads.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class Allocator>
class basic_dbvariant_sstream;

/////////////////////////////////////////////////////////////////////////////////
//template class basic_dbvariant_sstream

template<class Allocator>
class basic_dbvariant_sstream:public ISequentialStream
                             ,public ole_lib::TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef basic_dbvariant_sstream<Allocator>                    self_type;
  typedef ole_lib::TBaseUnknown2_WithFreeThreadMarshaler        inherited;

  basic_dbvariant_sstream(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef ole_lib::IPtr2<self_type>                             self_ptr;

  typedef size_t                                                size_type;

 private:
  basic_dbvariant_sstream(size_type   data_size,
                          const void* data);

  virtual ~basic_dbvariant_sstream();

 public:
  static self_ptr Create(size_type   data_size,
                         const void* data);

  static HRESULT FullCreate(size_type   data_size,
                            const void* data,
                            REFIID      riid,
                            void**      ppv);

  static bool IsSupportIID(REFIID riid);

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //ISequentialStream interface ------------------------------------------
  virtual HRESULT __stdcall Read  (void*       pv,
                                   ULONG       cb,
                                   ULONG*      pcbRead) COMP_W000004_OVERRIDE_FINAL;

  //E_NOTIMPL;
  virtual HRESULT __stdcall Write (const void* pv,
                                   ULONG       cb,
                                   ULONG*      pcbWritten) COMP_W000004_OVERRIDE_FINAL;

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
   //memory will be deallocated in catch in basic_dbvariant_sstream::Create
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
  BYTE         m_data[1];
};//class basic_dbvariant_sstream

typedef basic_dbvariant_sstream<TOLEDBMemoryAllocator> TDBVariantSequentialStream;

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/variant/oledb_variant_sstream.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
