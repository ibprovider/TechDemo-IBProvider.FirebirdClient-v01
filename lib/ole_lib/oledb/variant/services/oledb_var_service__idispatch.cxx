////////////////////////////////////////////////////////////////////////////////
//DBTYPE_IDISPATCH Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//IDISPATCH

DEFINE_OLEDB_TYPE_SERVICE_OBJ(IDISPATCH)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_ALIGN(IDISPATCH)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_LENGTH(IDISPATCH)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(IDISPATCH)

//------------------------------------------------------------------------
t_oledb_type_service_IDISPATCH::length_type
 t_oledb_type_service_IDISPATCH::get_binary_length(length_type)const
{
 assert(this->get_type()==DBTYPE_IDISPATCH);

 return 0;
}//IDISPATCH::get_binary_length

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_SIZE(IDISPATCH)

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_IDISPATCH::internal__get_data__ok
                                           (const DBVARIANT&  dbvar,
                                            const DBBINDING&  Binding,
                                            length_type const DEBUG_CODE(cbMemSize),
                                            status_type&      Binding_Status,
                                            length_type&      Binding_Length,
                                            void*       const pBuffer)const
{
 assert(dbvar.wType==get_type());
 assert(dbvar.wType==(Binding.wType&~DBTYPE_BYREF));
 assert(dbvar.TestDataStatus__IsOK());

 CHECK_WRITE_PTR(pBuffer,cbMemSize);

 //-----------------------------------------
 Binding_Status=DBSTATUS_S_OK;
 Binding_Length=sizeof(value_type);

 if((Binding.wType&DBTYPE_BYREF) && Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED)
 {
  assert(cbMemSize>=sizeof(void*));

  //возвращаем указатель на собственные данные
  (*reinterpret_cast<const value_type**>(pBuffer))=&dbvar.dispVal.ptr;    /*!*/
 }
 else
 {
  assert(cbMemSize>=sizeof(value_type));

  (*reinterpret_cast<value_type*>(pBuffer))=dbvar.dispVal.ptr;            /*!*/
 }

 if(Binding.dwMemOwner!=DBMEMOWNER_PROVIDEROWNED && dbvar.dispVal.ptr!=NULL) /*!*/
  dbvar.dispVal.ptr->AddRef();                                            /*!*/

 return S_OK;
}//IDISPATCH::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_IDISPATCH::get_element                       //!!!
                                            (DBVARIANT*   const dest,
                                             REFIID             /*ElementIID*/,
                                             length_type  const cbElement,
                                             const void*  const pElement)const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 assert_s(sizeof(value_type)==sizeof(dest->dispVal.ptr));                 //!!!

 assert(this->get_type()==DBTYPE_IDISPATCH);                              //!!!

 //--------
 if(cbElement!=sizeof(value_type))
  return E_FAIL;

 if(pElement==NULL)
  return E_FAIL;

 //--------
 memcpy(&dest->dispVal.ptr,pElement,sizeof(value_type));                  //!!!

 dest->wType=this->get_type();

 dest->SetDataStatus__OK();

 return S_OK;
}//IDISPATCH::get_element                                                 //!!!

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_IDISPATCH::set_element                        //!!!
                                            (LPCCONVCONTEXT      pConvCtx,
                                             const DBVARIANT&    source,
                                             REFIID              /*ElementIID*/,
                                             length_type   const cbElement,
                                             void*         const pElement,
                                             status_type*  const pBinding_Status)const
{
 assert(this->get_type()==DBTYPE_IDISPATCH);                              //!!!
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 assert_s(sizeof(source.dispVal.ptr)==sizeof(value_type));                //!!!

 if(cbElement!=sizeof(value_type))
 {
  (*pBinding_Status)=DBSTATUS_E_BADACCESSOR;

  return DB_E_BADBINDINFO;
 }//if

 DBVARIANT::value_dispatch_n_type elementValue;                           //!!!

 const HRESULT cvt_hr=DBVariant__to_IDISPATCH_ex(pConvCtx,source,&elementValue);//!!!

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
}//IDISPATCH::set_element                                                 //!!!

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_IDISPATCH::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"IDISPATCH[");

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
 result+=structure::to_hex::upper<wchar_t>((INT_PTR)dbvar.dispVal.ptr).c_str();
 result+=L"]";

 //-------
 return result;
}//IDISPATCH::get_print_wstr                                              //!!!

////////////////////////////////////////////////////////////////////////////////
