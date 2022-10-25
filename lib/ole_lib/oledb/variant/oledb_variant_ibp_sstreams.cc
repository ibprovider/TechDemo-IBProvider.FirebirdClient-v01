////////////////////////////////////////////////////////////////////////////////
//Implementation of IBProvider-specific storage objects
//                                                 Kovalenko Dmitry. 04.09.2012.
#ifndef _basic_dbvariant_ibp_sstream_CC_
#define _basic_dbvariant_ibp_sstream_CC_

#include <structure/t_algorithm.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//template class basic_dbvariant_sstream

template<class IInterface,const IID* PIID,class TChar,class Allocator>
basic_dbvariant_ibp_sstream<IInterface,PIID,TChar,Allocator>::basic_dbvariant_ibp_sstream
                                           (size_type        const data_size,
                                            const char_type* const data)
 :inherited(nullptr)
 ,m_guard()
 ,m_size(data_size)
 ,m_pos(0)
{
 structure::copy(data,
                 data+data_size,
                 m_data,
                 m_data+data_size);
}//basic_dbvariant_ibp_sstream

//------------------------------------------------------------------------
template<class IInterface,const IID* PIID,class TChar,class Allocator>
basic_dbvariant_ibp_sstream<IInterface,PIID,TChar,Allocator>::~basic_dbvariant_ibp_sstream()
{;}

//------------------------------------------------------------------------
template<class IInterface,const IID* PIID,class TChar,class Allocator>
typename basic_dbvariant_ibp_sstream<IInterface,PIID,TChar,Allocator>::self_ptr
 basic_dbvariant_ibp_sstream<IInterface,PIID,TChar,Allocator>::Create
                                           (size_type        const data_size,
                                            const char_type* const data)
{
 CHECK_READ_TYPED_PTR(data,data_size);

 assert_s(sizeof(char_type)==_MEMBER_SIZE_(self_type,m_data));

 size_t sz=offsetof(self_type,m_data);

 if(!structure::append_array_memory_size(sz,sizeof(char_type),data_size))
  throw std::bad_alloc();

 //----
 void* const pv=raw_allocator_type::instance.allocate(sz); //throw

 assert(pv);

 self_type* obj;

 try
 {
  obj=new(pv) self_type(data_size,data); //throw?
 }
 catch(...)
 {
  //trap exception from constructor for deallocate memory
  raw_allocator_type::instance.deallocate(pv,0);
  throw;
 }//catch
 //local

 assert(obj);

 return structure::not_null_ptr(obj);
}//Create

//------------------------------------------------------------------------
template<class IInterface,const IID* PIID,class TChar,class Allocator>
typename basic_dbvariant_ibp_sstream<IInterface,PIID,TChar,Allocator>::self_ptr
 basic_dbvariant_ibp_sstream<IInterface,PIID,TChar,Allocator>::Create
                                           (str_box_type const data)
{
 return self_type::Create(data.len,data.ptr);
}//Create from text

//------------------------------------------------------------------------
template<class IInterface,const IID* PIID,class TChar,class Allocator>
HRESULT basic_dbvariant_ibp_sstream<IInterface,PIID,TChar,Allocator>::FullCreate
                                           (size_type        const data_size,
                                            const char_type* const data,
                                            REFIID                 riid,
                                            void**           const ppv)
{
 assert(ppv!=NULL);

 return self_type::Create(data_size,data).QueryInterface(riid,ppv);
}//FullCreate

//Root interface ---------------------------------------------------------
template<class IInterface,const IID* PIID,class TChar,class Allocator>
OLE_LIB__DEFINE_ROOT_INTERFACE(basic_dbvariant_ibp_sstream<IInterface _LITER_COMMA_
                                                           PIID       _LITER_COMMA_
                                                           TChar      _LITER_COMMA_
                                                           Allocator>)
 assert(PIID);

 if(riid==(*PIID))
  return self_type::FinishQI_Static(static_cast<IInterface*>(this),ppv);
OLE_LIB__END_ROOT_INTERFACE(inherited)

//Stream interface -------------------------------------------------------
template<class IInterface,const IID* PIID,class TChar,class Allocator>
HRESULT __stdcall basic_dbvariant_ibp_sstream<IInterface,PIID,TChar,Allocator>::Read
                                           (char_type* const pchars,
                                            SIZE_T           cch,
                                            SIZE_T*    const pcchRead)
{
 OLE_LIB__IMETHOD_PROLOG

 LCPI_OS__SetErrorInfo(0,nullptr);

 if(pcchRead!=NULL)
  (*pcchRead)=0;

 if(cch!=0)
 {
  assert_hint(cch>0);

  if(pchars==NULL)
   return E_INVALIDARG;
 }//if

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  const lock_guard_type __lock__(m_guard);

  assert(m_pos<=m_size);

  const size_type cch_tail=size_type(m_size-m_pos);

  if(cch_tail==0)
  {
   hr=S_FALSE;
  }
  else
  if(cch==0)
  {
   //none
   assert_hint(hr==S_OK);
  }
  else
  {
   assert_hint(cch_tail>0);
   assert_hint(cch>0);

   if(cch_tail<cch)
    structure::static_numeric_cast(&cch,cch_tail);

   assert(cch<=cch_tail);
   assert(cch>0);

   assert(pchars);

   const char_type* const src_ptr=m_data+m_pos;

   structure::copy(src_ptr,
                   src_ptr+cch,
                   pchars,
                   pchars+cch);

   m_pos+=cch;

   if(pcchRead)
    (*pcchRead)=cch;

   assert_hint(hr==S_OK);
  }//else
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || hr==S_FALSE || FAILED(hr));

 return hr;
}//Read

//------------------------------------------------------------------------
template<class IInterface,const IID* PIID,class TChar,class Allocator>
HRESULT __stdcall basic_dbvariant_ibp_sstream<IInterface,PIID,TChar,Allocator>::Write
                                           (const char_type* const pchars,
                                            SIZE_T           const cch,
                                            SIZE_T*          const pcchWritten)
{
 OLE_LIB__IMETHOD_PROLOG

 LCPI_OS__SetErrorInfo(0,nullptr);

 if(pcchWritten)
  (*pcchWritten)=0;

 if(pchars==NULL && cch!=0)
  return E_INVALIDARG;

 return E_NOTIMPL;
}//Write

////////////////////////////////////////////////////////////////////////////////
}//namepace oledb_lib
#endif
