////////////////////////////////////////////////////////////////////////////////
//DBTYPE_IUNKNOWN Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//IUNKNOWN

DEFINE_OLEDB_TYPE_SERVICE_OBJ(IUNKNOWN)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_ALIGN(IUNKNOWN)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_LENGTH(IUNKNOWN)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(IUNKNOWN)

//------------------------------------------------------------------------
t_oledb_type_service_IUNKNOWN::length_type
 t_oledb_type_service_IUNKNOWN::get_binary_length(length_type)const
{
 assert(this->get_type()==DBTYPE_IUNKNOWN);

 return 0;
}//IUNKNOWN::get_binary_length

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_SIZE(IUNKNOWN)

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_IUNKNOWN::internal__get_data__ok
                                           (const DBVARIANT&  dbvar,
                                            const DBBINDING&  Binding,
                                            length_type const DEBUG_CODE(cbMemSize),
                                            status_type&      Binding_Status,
                                            length_type&      Binding_Length,
                                            void*       const pBuffer)const
{
 assert(dbvar.wType==this->get_type());
 assert(dbvar.wType==(Binding.wType&~DBTYPE_BYREF));
 assert(dbvar.TestDataStatus__IsOK());

 CHECK_WRITE_PTR(pBuffer,cbMemSize);

 //-----------------------------------------
 //получаем указатель на интерфейс затребованный клиентом

 ole_lib::IUnknownPtr spTargetUnk;

 if(dbvar.unkVal.ptr==NULL)
 {
 }
 else
 if(Binding.pObject==NULL)
 {
  spTargetUnk=dbvar.unkVal.ptr;
 }
 else
 {
  const HRESULT query_hr=
   dbvar.unkVal.ptr->QueryInterface(Binding.pObject->iid,
                                    reinterpret_cast<void**>(&spTargetUnk.ref_ptr()));

  if(query_hr!=NOERROR)
  {
   assert(FAILED(query_hr));

   Binding_Status=DBSTATUS_E_CANTCREATE;

   return DB_E_CANTCONVERTVALUE;
  }//if
 }//else

 if(Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED &&
    reinterpret_cast<void*>(spTargetUnk.ptr())!=reinterpret_cast<void*>(dbvar.unkVal.ptr))   /*!*/
 {
  //если указатели не идентичны - то мы не можем вернуть указатель на внутренний буфер

  Binding_Status=DBSTATUS_E_UNAVAILABLE;

  return DB_E_CANTCONVERTVALUE;
 }//if

 //------------------------------------------------------
 Binding_Status=DBSTATUS_S_OK;
 Binding_Length=sizeof(value_type);

 if((Binding.wType&DBTYPE_BYREF) && Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED)
 {
  assert(cbMemSize>=sizeof(void*));

  //возвращаем указатель на собственные данные

  (*reinterpret_cast<const value_type**>(pBuffer))=&dbvar.unkVal.ptr;
 }
 else
 {
  assert(cbMemSize>=sizeof(value_type));

  (*reinterpret_cast<value_type*>(pBuffer))=spTargetUnk.ptr();
 }//else

 if(Binding.dwMemOwner!=DBMEMOWNER_PROVIDEROWNED && spTargetUnk)
  spTargetUnk->AddRef();

 return S_OK;
}//IUNKNOWN::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_IUNKNOWN::get_element                        //!!!
                                            (DBVARIANT*   const dest,
                                             REFIID             ElementIID,
                                             length_type  const cbElement,
                                             const void*  const pElement)const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 assert_s(sizeof(value_type)==sizeof(dest->unkVal.ptr));                  //!!!

 assert(this->get_type()==DBTYPE_IUNKNOWN);                               //!!!

 //--------
 if(cbElement!=sizeof(value_type))
  return E_FAIL;

 if(pElement==NULL)
  return E_FAIL;

 //--------
 memcpy(&dest->unkVal.ptr,pElement,sizeof(value_type));                   //!!!

 dest->unkVal.iid=ElementIID;

 dest->wType=this->get_type();

 dest->SetDataStatus__OK();

 return S_OK;
}//IUNKNOWN::get_element                                                  //!!!

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_IUNKNOWN::set_element                        //!!!
                                            (LPCCONVCONTEXT      pConvCtx,
                                             const DBVARIANT&    source,
                                             REFIID              ElementIID,
                                             length_type   const cbElement,
                                             void*         const pElement,
                                             status_type*  const pBinding_Status)const
{
 assert(this->get_type()==DBTYPE_IUNKNOWN);                               //!!!
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 assert_s(sizeof(source.unkVal.ptr)==sizeof(value_type));                 //!!!

 if(cbElement!=sizeof(value_type))
 {
  (*pBinding_Status)=DBSTATUS_E_BADACCESSOR;

  return DB_E_BADBINDINFO;
 }//if

 DBVARIANT::value_unknown_n_type elementValue;                            //!!!

 const HRESULT cvt_hr=DBVariant__to_IUNKNOWN_ex(pConvCtx,
                                                source,
                                                ElementIID,
                                                &elementValue);           //!!!

 if(FAILED(cvt_hr))
 {
  (*pBinding_Status)=oledb_lib::MapDBErrorToDBStatus(cvt_hr);

  return cvt_hr;
 }//if

 assert(cvt_hr==S_OK);

 //-----------------------------------------------------------------------

 //clear current element value

 ole_lib::ReleaseComInterface(*reinterpret_cast<value_type*>(pElement));

 //-----------------------------------------------------------------------
 if(elementValue.null())
 {
  (*pBinding_Status)=DBSTATUS_E_CANTCONVERTVALUE;

  return DB_E_CANTCONVERTVALUE;
 }//if

 (*pBinding_Status)=DBSTATUS_S_OK;

 elementValue
  .value()
  .MoveTo_Fast(reinterpret_cast<value_type*>(pElement));                  //!!!

 return S_OK;
}//IUNKNOWN::set_element                                                  //!!!

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_IUNKNOWN::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"IUNKNOWN[");

 result+=structure::tstr_to_wstr(oledb_lib::GetDBStatusName__short(dbvar.GetDataStatus()));

 result+=L"]";

 switch(dbvar.GetDataStatus())
 {
  case DBSTATUS_S_OK:
   break;

  default:
   return result;
 }//switch

 //-------
 result+=L"[0x";
 result+=structure::to_hex::upper<wchar_t>((INT_PTR)dbvar.unkVal.ptr).c_str();
 result+=L", ";
 result+=ole_lib::guid_to_wstring(dbvar.unkVal.iid);
 result+=L"]";

 //-------
 return result;
}//IUNKNOWN::get_print_wstr                                               //!!!

////////////////////////////////////////////////////////////////////////////////
