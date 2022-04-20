////////////////////////////////////////////////////////////////////////////////
//Реализация шаблона из <oledb_variant_sstream.h>
//                                         Коваленко Дмитрий. 3 июня 2002 года.
#ifndef _oledb_variant_sstream_CC_
#define _oledb_variant_sstream_CC_

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//template class basic_dbvariant_sstream

template<class Allocator>
basic_dbvariant_sstream<Allocator>::basic_dbvariant_sstream(size_type   const data_size,
                                                            const void* const data)
 :inherited(nullptr)
 ,m_guard()
 ,m_size(data_size)
 ,m_pos(0)
{
 CHECK_READ_PTR(data,data_size);
 CHECK_READ_WRITE_PTR(m_data,data_size);

 memcpy(m_data,data,data_size);

 //throw std::runtime_error("test");
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant_sstream<Allocator>::~basic_dbvariant_sstream()
{;}

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant_sstream<Allocator>::self_ptr
basic_dbvariant_sstream<Allocator>::Create(size_type   const data_size,
                                           const void* const data)
{
 CHECK_READ_PTR(data,data_size);

 assert_s(1==_MEMBER_SIZE_(self_type,m_data));

 size_t sz=offsetof(self_type,m_data);

 if(!structure::append_memory_size(sz,data_size))
  throw std::bad_alloc();

 //----
 void* const pv=raw_allocator_type::instance.allocate(sz); //throw

 assert(pv);

 self_type* obj;

 try
 {
  obj=new(pv) self_type(data_size,data); // throw?
 }
 catch(...)
 {
  //trap exception from constructor for deallocate memory
  raw_allocator_type::instance.deallocate(pv,0);
  throw;
 }//catch

 assert(obj);

 return structure::not_null_ptr(obj);
}//Create

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant_sstream<Allocator>::FullCreate(size_type   const data_size,
                                                       const void* const data,
                                                       REFIID            riid,
                                                       void**      const ppv)
{
 assert(ppv!=NULL);

 return self_type::Create(data_size,data).QueryInterface(riid,ppv);
}//FullCreate

//------------------------------------------------------------------------
template<class Allocator>
bool basic_dbvariant_sstream<Allocator>::IsSupportIID(REFIID riid)
{
 if(riid==IID_ISequentialStream)
  return true;

 if(riid==IID_IUnknown)
  return true;

 return false;
}//IsSupportIID

//Root interface ---------------------------------------------------------
template<class Allocator>
OLE_LIB__DEFINE_ROOT_INTERFACE(basic_dbvariant_sstream<Allocator>)
 OLE_LIB__ROOT_STATIC_INTERFACE(ISequentialStream)
OLE_LIB__END_ROOT_INTERFACE(inherited)

//ISequentialStream interface --------------------------------------------
template<class Allocator>
HRESULT __stdcall basic_dbvariant_sstream<Allocator>::Read(void*  const pv,
                                                           ULONG        cb,
                                                           ULONG* const pcbRead)
{
 OLE_LIB_IMETHOD_PROLOG

 ::SetErrorInfo(0,nullptr);

 if(pcbRead!=NULL)
  (*pcbRead)=0;

 if(cb!=0)
 {
  assert_hint(cb>0);

  if(pv==NULL)
   return E_INVALIDARG;
 }//if cb!=0

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  const lock_guard_type __lock__(m_guard);

  assert(m_pos<=m_size);

  const size_type cb_tail=size_type(m_size-m_pos);

  if(cb_tail==0)
  {
   hr=S_FALSE;
  }
  else
  if(cb==0)
  {
   //none
   assert_hint(hr==S_OK);
  }
  else
  {
   assert_hint(cb_tail>0);
   assert_hint(cb>0);

   if(cb_tail<cb)
    structure::static_numeric_cast(&cb,cb_tail);

   assert(cb<=cb_tail);
   assert(cb>0);

   assert(pv);

   memcpy(pv,&m_data[m_pos],cb);

   m_pos+=cb;

   if(pcbRead)
    (*pcbRead)=cb;

   assert_hint(hr==S_OK);
  }//else
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || hr==S_FALSE || FAILED(hr));

 return hr;
}//Read

//------------------------------------------------------------------------
template<class Allocator>
HRESULT __stdcall basic_dbvariant_sstream<Allocator>::Write(const void* const pv,
                                                            ULONG       const cb,
                                                            ULONG*      const pcbWritten)
{
 OLE_LIB_IMETHOD_PROLOG

 ::SetErrorInfo(0,nullptr);

 if(pcbWritten)
  (*pcbWritten)=0;

 if(pv==NULL && cb!=0)
  return E_INVALIDARG;

 return E_NOTIMPL;
}//Write

////////////////////////////////////////////////////////////////////////////////
}//namepace oledb_lib
#endif
