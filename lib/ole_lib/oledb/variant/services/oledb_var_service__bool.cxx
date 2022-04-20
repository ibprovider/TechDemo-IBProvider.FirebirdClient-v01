////////////////////////////////////////////////////////////////////////////////
//DBTYPE_BOOL Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//BOOL

DEFINE_OLEDB_TYPE_SERVICE_OBJ(BOOL)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_ALIGN(BOOL)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_LENGTH(BOOL)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_BINARY_LENGTH(BOOL)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_SIZE(BOOL)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(BOOL)

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_BOOL::internal__get_data__ok
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
  *reinterpret_cast<const value_type**>(pBuffer)=&dbvar.boolVal;          /*!*/
 }
 else
 {
  assert_s(sizeof(value_type)==sizeof(dbvar.boolVal));                    /*!*/
  assert(cbMemSize>=sizeof(value_type));

  *reinterpret_cast<value_type*>(pBuffer)=dbvar.boolVal;                  /*!*/
 }

 return S_OK;
}//BOOL::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_BOOL::get_element                            //!!!
                                            (DBVARIANT*   const dest,
                                             REFIID             /*ElementIID*/,
                                             length_type  const cbElement,
                                             const void*  const pElement)const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 assert_s(sizeof(value_type)==sizeof(dest->boolVal));                     //!!!

 assert(this->get_type()==DBTYPE_BOOL);                                   //!!!

 //--------
 if(cbElement!=sizeof(value_type))
  return E_FAIL;

 if(pElement==NULL)
  return E_FAIL;

 //--------
 memcpy(&dest->boolVal,pElement,sizeof(value_type));                      //!!!

 if(dest->boolVal!=VARIANT_FALSE)                                         //!!!
  dest->boolVal=VARIANT_TRUE;                                             //!!!

 dest->wType=this->get_type();

 dest->SetDataStatus__OK();

 return S_OK;
}//BOOL::get_element                                                      //!!!

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_BOOL::set_element                            //!!!
                                            (LPCCONVCONTEXT      pConvCtx,
                                             const DBVARIANT&    source,
                                             REFIID              /*ElementIID*/,
                                             length_type   const cbElement,
                                             void*         const pElement,
                                             status_type*  const pBinding_Status)const
{
 assert(this->get_type()==DBTYPE_BOOL);                                   //!!!
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 assert_s(sizeof(source.boolVal)==sizeof(value_type));                    //!!!

 if(cbElement!=sizeof(value_type))
 {
  (*pBinding_Status)=DBSTATUS_E_BADACCESSOR;

  //memset(pElement,0,cbElement);

  return DB_E_BADBINDINFO;
 }//if

 DBVARIANT::value_cpp_bool_n_type elementValue;                           //!!!

 const HRESULT cvt_hr=DBVariant__to_BOOL_ex(pConvCtx,source,&elementValue); //!!!

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

 assert(!elementValue.null());

 (*pBinding_Status)=DBSTATUS_S_OK;

 (*reinterpret_cast<value_type*>(pElement))
  =(elementValue.value()?VARIANT_TRUE:VARIANT_FALSE);                     //!!!

 return S_OK;
}//BOOL::set_element                                                      //!!!

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_BOOL::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"BOOL[");

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
 assert_s(VARIANT_FALSE==0);
 assert_s(VARIANT_TRUE==-1);

 if(dbvar.boolVal==VARIANT_FALSE)
  result+=L" VARIANT_FALSE(";
 else
  result+=L" VARIANT_TRUE(";

 result+=structure::t_str_args_traits<wchar_t>::arg(dbvar.boolVal);

 result+=L")";

 return result;
}//BOOL::get_print_wstr                                                   //!!!

////////////////////////////////////////////////////////////////////////////////
