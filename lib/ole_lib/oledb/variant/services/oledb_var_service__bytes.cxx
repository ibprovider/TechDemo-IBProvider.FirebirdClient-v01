////////////////////////////////////////////////////////////////////////////////
//DBTYPE_BYTES Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//BYTES

DEFINE_OLEDB_TYPE_SERVICE_OBJ(BYTES)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(BYTES)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_ALIGN(BYTES)

//------------------------------------------------------------------------
t_oledb_type_service_BYTES::length_type
 t_oledb_type_service_BYTES::get_binary_length(length_type DataLength)const
{
 assert(this->get_type()==DBTYPE_BYTES);

 return DataLength*sizeof(value_type);
}//BYTES::get_binary_length

//------------------------------------------------------------------------
t_oledb_type_service_BYTES::length_type
 t_oledb_type_service_BYTES::internal__get_length__ok(const DBVARIANT& dbvar)const
{
 assert(this->get_type()==DBTYPE_BYTES);
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 assert_s(sizeof(length_type)==sizeof(DBVARIANT::size_type));
 assert(structure::t_numeric_limits<length_type>::min_value()==0);

 CHECK_READ_PTR(dbvar.bytesVal.ptr,dbvar.bytesVal.len);

 return static_cast<length_type>(dbvar.bytesVal.len);
}//BYTES::internal__get_length__ok

//------------------------------------------------------------------------
void t_oledb_type_service_BYTES::internal__get_size__ok
                                           (const DBVARIANT&  dbvar,
                                            length_type&      cbSize,
                                            length_type&      cbMemSize,
                                            length_type&      cbMinSize)const
{
 assert(this->get_type()==DBTYPE_BYTES);
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 cbMinSize =0;
 cbSize    =
 cbMemSize =dbvar.bytesVal.byte_count();                                  /*!*/
}//BYTES::internal__get_size__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_BYTES::internal__get_data__ok
                                           (const DBVARIANT&  dbvar,
                                            const DBBINDING&  Binding,
                                            length_type const cbMemSize,
                                            status_type&      Binding_Status,
                                            length_type&      Binding_Length,
                                            void*       const pBuffer)const
{
 assert(dbvar.wType==this->get_type());
 assert(dbvar.wType==(Binding.wType&~DBTYPE_BYREF));
 assert(dbvar.TestDataStatus__IsOK());

 CHECK_WRITE_PTR(pBuffer,cbMemSize);

 //-----------------------------------------
 Binding_Length=dbvar.bytesVal.byte_count();                              /*!*/
 Binding_Status=DBSTATUS_S_OK;

 if((Binding.wType&DBTYPE_BYREF) && Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED)
 {
  assert(cbMemSize>=sizeof(void*));

  *reinterpret_cast<void**>(pBuffer)=dbvar.bytesVal.ptr;
 }
 else
 {
  if(Binding_Length>cbMemSize)
  {
   ODS_LEVEL_3("WAR: dbvariant::GetData(iOrd="<<Binding.iOrdinal<<","
                                       "Len:"<<Binding_Length<<","
                                       "cbMemSize:"<<cbMemSize<<") "
               "- trunc BYTES");

   Binding_Status=DBSTATUS_S_TRUNCATED;
  }

  CHECK_READ_PTR(dbvar.bytesVal.ptr,min(cbMemSize,Binding_Length));       /*!*/

  memcpy(pBuffer,dbvar.bytesVal.ptr,min(cbMemSize,Binding_Length));       /*!*/
 }//else - возвращаем копию данных

 return S_OK;
}//BYTES::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_BYTES::get_element                           //!!!
                                            (DBVARIANT*   const dest,
                                             REFIID             /*ElementIID*/,
                                             length_type        cbElement,
                                             const void*  const pElement)const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 assert(this->get_type()==DBTYPE_BYTES);                                  //!!!

 assert_s(sizeof(value_type)==1);                                         //!!!

 //--------
 //if((cbElement%sizeof(value_type))!=0)
 // return E_FAIL;

 if(pElement==NULL && cbElement!=0)
  return E_FAIL;

 //--------
 dest->bytesVal.ptr=const_cast<void*>(pElement);                          //!!!
 dest->bytesVal.len=cbElement;                                            //!!!

 dest->wType=this->get_type();

 dest->SetDataStatus__OK();

 return S_OK;
}//BYTES::get_element                                                     //!!!

//------------------------------------------------------------------------
static HRESULT oledb_type_service_BYTES_set_element__CANT_CVT(DBSTATUS* const pBinding_Status)
{
 assert(pBinding_Status);

 (*pBinding_Status)=DBSTATUS_E_CANTCONVERTVALUE;

 return DB_E_CANTCONVERTVALUE;
}//oledb_type_service_BYTES_set_element__CANT_CVT

//------------------------------------------------------------------------
static HRESULT oledb_type_service_BYTES_set_element__DATA_OVERFLOW(DBSTATUS* const pBinding_Status)
{
 assert(pBinding_Status);

 (*pBinding_Status)=DBSTATUS_E_DATAOVERFLOW;

 return DB_E_DATAOVERFLOW;
}//oledb_type_service_BYTES_set_element__DATA_OVERFLOW

//------------------------------------------------------------------------
static HRESULT oledb_type_service_BYTES_set_element(size_t      const cbSource,
                                                    const void* const pSource,
                                                    DBLENGTH    const cbElement,
                                                    void*       const pElement,
                                                    DBSTATUS*   const pBinding_Status)
{
 assert(pBinding_Status);

 CHECK_READ_PTR  (pSource,cbSource);
 CHECK_WRITE_PTR (pElement,cbElement);

 if(cbElement<cbSource)
  return oledb_type_service_BYTES_set_element__DATA_OVERFLOW(pBinding_Status);

 memcpy(pElement,pSource,cbSource);

 std::fill(reinterpret_cast<char*>(pElement)+cbSource,
           reinterpret_cast<char*>(pElement)+cbElement,
           structure::zero);

 (*pBinding_Status)=DBSTATUS_S_OK;

 return S_OK;
}//oledb_type_service_BYTES_set_element

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_BYTES::set_element                           //!!!
                                            (LPCCONVCONTEXT      pConvCtx,
                                             const DBVARIANT&    source,
                                             REFIID              /*ElementIID*/,
                                             length_type   const cbElement,
                                             void*         const pElement,
                                             status_type*  const pBinding_Status)const
{
 assert(this->get_type()==DBTYPE_BYTES);                                  //!!!
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 assert_s(sizeof(value_type)==1);                                         //!!!

 if(!source.TestDataStatus__IsOK())
  return oledb_type_service_BYTES_set_element__CANT_CVT(pBinding_Status);

 assert(source.TestDataStatus__IsOK());

 if(source.wType==DBTYPE_BYTES)
 {
  CHECK_READ_PTR(source.bytesVal.ptr,source.bytesVal.len);

  DBVARIANT::size_type src_length=source.bytesVal.len;

  while(cbElement<src_length)
  {
   --src_length;

   if(reinterpret_cast<const char*>(source.bytesVal.ptr)[src_length]==0)
    continue;

   return oledb_type_service_BYTES_set_element__DATA_OVERFLOW(pBinding_Status);
  }//while

  assert(src_length<=source.bytesVal.len);

  assert(src_length<=cbElement);

  return oledb_type_service_BYTES_set_element
          (src_length,
           source.bytesVal.ptr,
           cbElement,
           pElement,
           pBinding_Status);
 }//if - source has BYTES

 if(source.wType==DBTYPE_STR)
 {
  CHECK_READ_TYPED_PTR(source.strVal.ptr,source.strVal.len);

  DBVARIANT::size_type str_length=source.strVal.len;

  const size_t m=cbElement/sizeof(*source.strVal.ptr);

  while(m<str_length)
  {
   --str_length;

   if(source.strVal.ptr[str_length]==0)
    continue;

   return oledb_type_service_BYTES_set_element__DATA_OVERFLOW(pBinding_Status);
  }//while

  assert(str_length<=m);

  assert(str_length<=source.strVal.len);

  return oledb_type_service_BYTES_set_element
          (str_length*sizeof(*source.strVal.ptr),
           source.strVal.ptr,
           cbElement,
           pElement,
           pBinding_Status);
 }//if - source has STR

 if(source.wType==DBTYPE_WSTR)
 {
  CHECK_READ_TYPED_PTR(source.wstrVal.ptr,source.wstrVal.len);

  DBVARIANT::size_type wstr_length=source.wstrVal.len;

  const size_t m=cbElement/sizeof(*source.wstrVal.ptr);

  while(m<wstr_length)
  {
   --wstr_length;

   if(source.wstrVal.ptr[wstr_length]==0)
    continue;

   return oledb_type_service_BYTES_set_element__DATA_OVERFLOW(pBinding_Status);
  }//while

  assert(wstr_length<=m);

  assert(wstr_length<=source.wstrVal.len);

  return oledb_type_service_BYTES_set_element
          (wstr_length*sizeof(*source.wstrVal.ptr),
           source.wstrVal.ptr,
           cbElement,
           pElement,
           pBinding_Status);
 }//if - source has WSTR

 if(source.wType==DBTYPE_BSTR)
 {
  DBVARIANT::size_type bstr_length=(source.bstrVal?::SysStringLen(source.bstrVal):0);

  DEBUG_CODE(size_t const debug__bstr_length__copy=bstr_length;)

  CHECK_READ_TYPED_PTR(source.bstrVal,bstr_length);

  const size_t m=cbElement/sizeof(*source.bstrVal);

  while(m<bstr_length)
  {
   --bstr_length;

   if(source.bstrVal[bstr_length]==0)
    continue;

   return oledb_type_service_BYTES_set_element__DATA_OVERFLOW(pBinding_Status);
  }//while

  assert(bstr_length<=m);

  assert(bstr_length<=debug__bstr_length__copy);

  return oledb_type_service_BYTES_set_element
          (bstr_length*sizeof(*source.bstrVal),
           source.bstrVal,
           cbElement,
           pElement,
           pBinding_Status);
 }//if - source has BSTR

 typedef TDBVariantBytesWriter writer_type;

 writer_type writer;

 const HRESULT cvt_hr=DBVariant__to_BYTES_ex(pConvCtx,source,&writer);

 if(FAILED(cvt_hr))
 {
  (*pBinding_Status)=oledb_lib::MapDBErrorToDBStatus(cvt_hr);

  return cvt_hr;
 }//if

 if(cvt_hr==S_FALSE) //NULL
  return oledb_type_service_BYTES_set_element__CANT_CVT(pBinding_Status);

 assert(cvt_hr==S_OK);

 {
  //scan from tail to head.

  typedef writer_type::buffer_type::seg_header_type seg_header_type;

  size_t src_length=writer.m_buffer.size();

  if(cbElement<src_length)
  {
   for(const seg_header_type* tail=writer.m_buffer.tail();;tail=tail->prev)
   {
    assert(src_length>0);

    //! \todo
    //!  Throw bug-check error?
    assert_msg(tail,"src_length: "<<src_length);

    assert(tail->size!=0);
    assert(tail->used<=tail->size);

    assert(tail->used<=src_length);

    size_t n=tail->used;

    while(n!=0)
    {
     --n;

     if(reinterpret_cast<const char*>(tail->data())[n]==0)
      continue;

     ++n;
     break;
    }//while n!=0

    assert(n<=tail->used);

    src_length-=(tail->used-n);

    if(src_length<=cbElement)
     break;

    assert_hint(cbElement<src_length);

    assert_hint(src_length>0); //unsigned

    if(n!=0)
     return oledb_type_service_BYTES_set_element__DATA_OVERFLOW(pBinding_Status);
   }//for tail
  }//if cbElement<src_length

  assert(src_length<=cbElement);

  const seg_header_type* seg=writer.m_buffer.head();

  char*       p_dest=reinterpret_cast<char*>(pElement);
  char* const e_dest=reinterpret_cast<char*>(pElement)+src_length;
  char* const z_dest=reinterpret_cast<char*>(pElement)+cbElement;

  while(p_dest!=e_dest)
  {
   assert(p_dest<e_dest);

   //! \todo
   //!  Throw bug-check error?
   assert(seg);

   assert(seg->size!=0);
   assert(seg->used<=seg->size);

   size_t const seg_cb=min(seg->used,size_t(e_dest-p_dest));

   memcpy(p_dest,seg->data(),seg_cb);

   p_dest+=seg_cb;

   seg=seg->next;
  }//while p_dest!=e_dest

  (*pBinding_Status)=DBSTATUS_S_OK;

  std::fill(p_dest,z_dest,structure::zero);
 }//local

 return S_OK;
}//BYTES::set_element

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_BYTES::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"BYTES[");

 result+=structure::tstr_to_wstr(oledb_lib::GetDBStatusName__short(dbvar.GetDataStatus()));

 result+=L"]";

 switch(dbvar.GetDataStatus())
 {
  case DBSTATUS_S_OK:
  case DBSTATUS_S_TRUNCATED:
   break;

  default:
   return result;
 }//switch

 CHECK_READ_PTR(dbvar.bytesVal.ptr,dbvar.bytesVal.len);                   //!!!

 result+=L"[len:";

 result+=structure::t_str_args_traits<wchar_t>::arg(dbvar.bytesVal.len);

 result+=L"]";

 //------
 return result;
}//BYTES::get_print_wstr                                                  //!!!

////////////////////////////////////////////////////////////////////////////////
