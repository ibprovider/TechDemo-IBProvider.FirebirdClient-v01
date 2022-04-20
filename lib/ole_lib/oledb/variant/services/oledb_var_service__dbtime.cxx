////////////////////////////////////////////////////////////////////////////////
//DBTYPE_DBTIME Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//DBTIME

DEFINE_OLEDB_TYPE_SERVICE_OBJ(DBTIME)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_ALIGN(DBTIME)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_LENGTH(DBTIME)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_BINARY_LENGTH(DBTIME)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_SIZE(DBTIME)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(DBTIME)

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_DBTIME::internal__get_data__ok
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
  *reinterpret_cast<const value_type**>(pBuffer)=&dbvar.dbtimeVal;        /*!*/
 }
 else
 {
  assert_s(sizeof(value_type)==sizeof(dbvar.dbtimeVal));                  /*!*/
  assert(cbMemSize>=sizeof(value_type));

  *reinterpret_cast<value_type*>(pBuffer)=dbvar.dbtimeVal;                /*!*/
 }

 return S_OK;
}//dbtime::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_DBTIME::get_element                          //!!!
                                            (DBVARIANT*   const dest,
                                             REFIID             /*ElementIID*/,
                                             length_type  const cbElement,
                                             const void*  const pElement)const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 assert_s(sizeof(value_type)==sizeof(dest->dbtimeVal));                   //!!!

 assert(this->get_type()==DBTYPE_DBTIME);                                 //!!!

 //--------
 if(cbElement!=sizeof(value_type))
  return E_FAIL;

 if(pElement==NULL)
  return E_FAIL;

 //--------
 memcpy(&dest->dbtimeVal,pElement,sizeof(value_type));                    //!!!

 dest->wType=this->get_type();

 dest->SetDataStatus__OK();

 return S_OK;
}//DBTIME::get_element                                                    //!!!

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_DBTIME::set_element                          //!!!
                                            (LPCCONVCONTEXT      pConvCtx,
                                             const DBVARIANT&    source,
                                             REFIID              /*ElementIID*/,
                                             length_type   const cbElement,
                                             void*         const pElement,
                                             status_type*  const pBinding_Status)const
{
 assert(this->get_type()==DBTYPE_DBTIME);                                 //!!!
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 assert_s(sizeof(source.dbtimeVal)==sizeof(value_type));                  //!!!

 if(cbElement!=sizeof(value_type))
 {
  (*pBinding_Status)=DBSTATUS_E_BADACCESSOR;

  //memset(pElement,0,cbElement);

  return DB_E_BADBINDINFO;
 }//if

 DBVARIANT::value_dbtime_n_type elementValue;                             //!!!

 const HRESULT cvt_hr=DBVariant__to_DBTIME_ex(pConvCtx,source,&elementValue); //!!!

 if(FAILED(cvt_hr))
 {
  (*pBinding_Status)=oledb_lib::MapDBErrorToDBStatus(cvt_hr);

  //memset(pElement,0,cbElement);

  return cvt_hr;
 }//if

 assert(cvt_hr==S_OK);

 if(elementValue.null())
 {
  (*pBinding_Status)=DBSTATUS_E_CANTCONVERTVALUE;

  return DB_E_CANTCONVERTVALUE;
 }//if

 (*pBinding_Status)=DBSTATUS_S_OK;

 (*reinterpret_cast<value_type*>(pElement))=elementValue.value();         //!!!

 return S_OK;
}//DBTIME::set_element                                                    //!!!

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_DBTIME::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"DBTIME[");

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
 result+=L"[";
 result+=dbtime_to_wstr(dbvar.dbtimeVal);
 result+=L"]";

 //-------
 return result;
}//DBTIME::get_print_wstr                                                 //!!!

////////////////////////////////////////////////////////////////////////////////
