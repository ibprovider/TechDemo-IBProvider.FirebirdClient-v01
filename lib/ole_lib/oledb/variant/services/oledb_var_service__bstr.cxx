////////////////////////////////////////////////////////////////////////////////
//DBTYPE_BSTR Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//BSTR

DEFINE_OLEDB_TYPE_SERVICE_OBJ(BSTR)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_ALIGN(BSTR)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_LENGTH(BSTR)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(BSTR)

//------------------------------------------------------------------------
t_oledb_type_service_BSTR::length_type
 t_oledb_type_service_BSTR::get_binary_length(length_type)const
{
 assert(this->get_type()==DBTYPE_BSTR);

 return 0;
}//get_binary_length

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_SIZE(BSTR)

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_BSTR::internal__get_data__ok
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
 Binding_Status=DBSTATUS_S_OK;
 Binding_Length=sizeof(value_type);

 if((Binding.wType&DBTYPE_BYREF) && Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED)
 {
  assert(cbMemSize>=sizeof(void*));

  //возвращаем указатель на собственные данные
  *reinterpret_cast<const value_type**>(pBuffer)=&dbvar.bstrVal;          /*!*/
 }
 else
 if(Binding.dwMemOwner==DBMEMOWNER_CLIENTOWNED)
 {
  assert(cbMemSize>=sizeof(value_type));

  const UINT           wstr_len =dbvar.bstrVal?LCPI_OS__SysStringLen(dbvar.bstrVal):0;
  const wchar_t* const wstr     =dbvar.bstrVal?dbvar.bstrVal:L"";

  (*reinterpret_cast<BSTR*>(pBuffer))=LCPI_OS__SysAllocStringLen(wstr,wstr_len); /*!*/

  if((*reinterpret_cast<BSTR*>(pBuffer))==NULL) //ошибка выделения памяти
  {
   Binding_Status=DBSTATUS_E_CANTCREATE;

   return E_OUTOFMEMORY;
  }
 }
 else
 {
  assert(cbMemSize>=sizeof(value_type));
  assert(Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED);

  *reinterpret_cast<BSTR*>(pBuffer)=dbvar.bstrVal;//на внутренний буфер   /*!*/
 }

 return S_OK;
}//BSTR::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_BSTR::get_element                            //!!!
                                            (DBVARIANT*   const dest,
                                             REFIID             /*ElementIID*/,
                                             length_type  const cbElement,
                                             const void*  const pElement)const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 assert_s(sizeof(value_type)==sizeof(dest->bstrVal));                     //!!!

 assert(this->get_type()==DBTYPE_BSTR);                                   //!!!

 //--------
 if(cbElement!=sizeof(value_type))
  return E_FAIL;

 if(pElement==NULL)
  return E_FAIL;

 //--------
 memcpy(&dest->bstrVal,pElement,sizeof(value_type));                      //!!!

 dest->wType=this->get_type();

 dest->SetDataStatus__OK();

 return S_OK;
}//BSTR::get_element                                                      //!!!

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_BSTR::set_element                            //!!!
                                            (LPCCONVCONTEXT      pConvCtx,
                                             const DBVARIANT&    source,
                                             REFIID              /*ElementIID*/,
                                             length_type   const cbElement,
                                             void*         const pElement,
                                             status_type*  const pBinding_Status)const
{
 assert(this->get_type()==DBTYPE_BSTR);                                   //!!!
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 assert_s(sizeof(source.bstrVal)==sizeof(value_type));                    //!!!

 if(cbElement!=sizeof(value_type))
 {
  (*pBinding_Status)=DBSTATUS_E_BADACCESSOR;

  return DB_E_BADBINDINFO;
 }//if

 DBVARIANT::value_cpp_bstr_n_type elementValue;                           //!!!

 const HRESULT cvt_hr=DBVariant__to_BSTR_ex(pConvCtx,source,&elementValue); //!!!

 if(FAILED(cvt_hr))
 {
  (*pBinding_Status)=oledb_lib::MapDBErrorToDBStatus(cvt_hr);

  return cvt_hr;
 }//if

 assert(cvt_hr==S_OK);

 if(elementValue.null())
 {
  (*pBinding_Status)=DBSTATUS_E_CANTCONVERTVALUE;

  return DB_E_CANTCONVERTVALUE;
 }//if

 //-----------------------------------------------------------------------

 //clear current element value
 ole_lib::FreeBStr(*reinterpret_cast<value_type*>(pElement));

 assert((*reinterpret_cast<value_type*>(pElement))==NULL);

 //-----------------------------------------------------------------------
 (*pBinding_Status)=DBSTATUS_S_OK;

 (*reinterpret_cast<value_type*>(pElement))
  =elementValue.value().Release();                                        //!!!
 
 assert(elementValue.value().bstr()==NULL);

 return S_OK;
}//BSTR::set_element                                                      //!!!

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_BSTR::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"BSTR[");

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
 if(!dbvar.bstrVal)
 {
  result+=L"[#NULL_PTR]";
 }
 else
 {
  const UINT lenBStr=LCPI_OS__SysStringLen(dbvar.bstrVal);

  CHECK_READ_TYPED_PTR(dbvar.bstrVal,lenBStr);

  result+=L"[len:";
  result+=structure::t_str_args_traits<wchar_t>::arg(lenBStr);
  result+=L"][";
  result.append(dbvar.bstrVal,lenBStr);
  result+=L"]";
 }//else

 return result;
}//BSTR::get_print_wstr                                                   //!!!

////////////////////////////////////////////////////////////////////////////////
