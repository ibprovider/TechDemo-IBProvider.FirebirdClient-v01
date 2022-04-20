////////////////////////////////////////////////////////////////////////////////
//DBTYPE_DBTIME2 Service
//                                                  Kovalenko Dmitry 08.09.2010

////////////////////////////////////////////////////////////////////////////////
//DBTIME2

DEFINE_OLEDB_TYPE_SERVICE_OBJ(DBTIME2)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_ALIGN(DBTIME2)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_LENGTH(DBTIME2)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_BINARY_LENGTH(DBTIME2)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_SIZE(DBTIME2)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(DBTIME2)

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_DBTIME2::internal__get_data__ok
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
  (*reinterpret_cast<const value_type**>(pBuffer))=&dbvar.dbtime2Val;     /*!*/
 }
 else
 {
  assert_s(sizeof(value_type)==sizeof(dbvar.dbtime2Val));                 /*!*/
  assert(cbMemSize>=sizeof(value_type));

  (*reinterpret_cast<value_type*>(pBuffer))=dbvar.dbtime2Val;             /*!*/
 }

 return S_OK;
}//DBTIME2::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_DBTIME2::get_element                         //!!!
                                            (DBVARIANT*   const dest,
                                             REFIID             /*ElementIID*/,
                                             length_type  const cbElement,
                                             const void*  const pElement)const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 assert_s(sizeof(value_type)==sizeof(dest->dbtime2Val));                  //!!!

 assert(this->get_type()==oledb_typeid__DBTIME2);                         //!!!

 //--------
 if(cbElement!=sizeof(value_type))
  return E_FAIL;

 if(pElement==NULL)
  return E_FAIL;

 //--------
 memcpy(&dest->dbtime2Val,pElement,sizeof(value_type));                   //!!!

 dest->wType=this->get_type();

 dest->SetDataStatus__OK();

 return S_OK;
}//DBTIME2::get_element                                                   //!!!

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_DBTIME2::set_element                         //!!!
                                            (LPCCONVCONTEXT      pConvCtx,
                                             const DBVARIANT&    source,
                                             REFIID              /*ElementIID*/,
                                             length_type   const cbElement,
                                             void*         const pElement,
                                             status_type*  const pBinding_Status)const
{
 assert(this->get_type()==oledb_typeid__DBTIME2);                         //!!!
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 assert_s(sizeof(source.dbtime2Val)==sizeof(value_type));                 //!!!

 if(cbElement!=sizeof(value_type))
 {
  (*pBinding_Status)=DBSTATUS_E_BADACCESSOR;

  //memset(pElement,0,cbElement);

  return DB_E_BADBINDINFO;
 }//if

 DBVARIANT::value_dbtime2_n_type elementValue;                            //!!!

 const HRESULT cvt_hr=DBVariant__to_DBTIME2_ex(pConvCtx,source,&elementValue); //!!!

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
}//DBTIME2::set_element                                                   //!!!

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_DBTIME2::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"DBTIME2[");

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
 result+=dbtime2_to_wstr(dbvar.dbtime2Val);
 result+=L"]";

 //-------
 return result;
}//DBTIME2::get_print_wstr                                                //!!!

////////////////////////////////////////////////////////////////////////////////
