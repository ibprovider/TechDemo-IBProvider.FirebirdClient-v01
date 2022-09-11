////////////////////////////////////////////////////////////////////////////////
//DBTYPE_VARIANT Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//VARIANT

DEFINE_OLEDB_TYPE_SERVICE_OBJ(VARIANT)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_ALIGN(VARIANT)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_LENGTH(VARIANT)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(VARIANT)

//------------------------------------------------------------------------
t_oledb_type_service_VARIANT::length_type
 t_oledb_type_service_VARIANT::get_binary_length(length_type)const
{
 assert(this->get_type()==DBTYPE_VARIANT);

 return 0;
}//get_binary_length

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_SIZE(VARIANT)

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_VARIANT::internal__get_data__ok
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
  *reinterpret_cast<const value_type**>(pBuffer)=&dbvar.varVal;           /*!*/
 }
 else
 if(Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED)
 {
  assert(cbMemSize>=sizeof(value_type));

  *reinterpret_cast<value_type*>(pBuffer)=dbvar.varVal;
 }
 else
 {
  assert(cbMemSize>=sizeof(value_type));

  LCPI_OS__VariantInit(reinterpret_cast<value_type*>(pBuffer));

  HRESULT const hr
   =ole_lib::Variant_CopyInd(reinterpret_cast<value_type*>(pBuffer),
                             &dbvar.varVal);

  if(FAILED(hr))
  {
   Binding_Status=DBSTATUS_E_CANTCREATE;
   Binding_Length=0;

   return hr;
  }
 }//else

 return S_OK;
}//VARIANT::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_VARIANT::get_element                         //!!!
                                            (DBVARIANT*   const dest,
                                             REFIID             /*ElementIID*/,
                                             length_type  const cbElement,
                                             const void*  const pElement)const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 assert_s(sizeof(value_type)==sizeof(dest->varVal));                      //!!!

 assert(this->get_type()==DBTYPE_VARIANT);                                //!!!

 //--------
 if(cbElement!=sizeof(value_type))
  return E_FAIL;

 if(pElement==NULL)
  return E_FAIL;

 //--------
 memcpy(&dest->varVal,pElement,sizeof(value_type));                       //!!!

 dest->wType=this->get_type();

 dest->SetDataStatus__OK();

 return S_OK;
}//VARIANT::get_element                                                   //!!!

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_VARIANT::set_element                         //!!!
                                            (LPCCONVCONTEXT      pConvCtx,
                                             const DBVARIANT&    source,
                                             REFIID              /*ElementIID*/,
                                             length_type   const cbElement,
                                             void*         const pElement,
                                             status_type*  const pBinding_Status)const
{
 assert(this->get_type()==DBTYPE_VARIANT);                                //!!!
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 assert_s(sizeof(source.varVal)==sizeof(value_type));                     //!!!

 if(cbElement!=sizeof(value_type))
 {
  (*pBinding_Status)=DBSTATUS_E_BADACCESSOR;

  return DB_E_BADBINDINFO;
 }//if

 ole_lib::TBaseVariant elementValue1;                                     //!!!

 const HRESULT cvt_hr=DBVariant__to_VARIANT_ex(pConvCtx,source,&elementValue1);//!!!

 if(FAILED(cvt_hr))
 {
  (*pBinding_Status)=oledb_lib::MapDBErrorToDBStatus(cvt_hr);

  return cvt_hr;
 }//if

 assert(cvt_hr==S_OK || cvt_hr==S_FALSE);

 //-----------------------------------------------------------------------
 ole_lib::TBaseVariant elementValue2;

 VARIANT* pAssignVariant;

 if((elementValue1.vt&VT_BYREF)==0)
 {
  pAssignVariant=&elementValue1;
 }
 else
 {
  if(FAILED(ole_lib::Variant_CopyInd(&elementValue2,&elementValue1)))
  {
   (*pBinding_Status)=DBSTATUS_E_CANTCREATE;

   return E_FAIL;
  }

  pAssignVariant=&elementValue2;
 }//if

 //-----------------------------------------------------------------------

 //clear current element value

 if(FAILED(ole_lib::Variant_Clear(reinterpret_cast<value_type*>(pElement))))
 {
  (*pBinding_Status)=DBSTATUS_E_CANTCREATE;

  return E_FAIL;
 }//if

 assert(reinterpret_cast<value_type*>(pElement)->vt==VT_EMPTY);

 //-----------------------------------------------------------------------
 (*pBinding_Status)=DBSTATUS_S_OK;

 //DIRECT COPY

 (*reinterpret_cast<value_type*>(pElement))=(*pAssignVariant);            //!!!

 //DETACH
 pAssignVariant->vt=VT_EMPTY;

 return S_OK;
}//VARIANT::set_element                                                   //!!!

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_VARIANT::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"VARIANT[");

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
 result.append(L"[vt:");

 result.append(structure::t_str_args_traits<wchar_t>::arg(dbvar.varVal.vt));

 result.append(L"]");

 //-------
 DBVARIANT::TCvtAdapter unpack;

 const HRESULT hr=unpack.Unpack_Variant(dbvar.varVal);

 assert(hr==S_OK || FAILED(hr));

 //-------
 if(hr==S_OK)
 {
  result.append(L" ");

  result.append(unpack.dbvar().get_print_wstr());
 }
 else
 {
  result+=L"[#CANT_UNPACK hr=0x";

  result+=structure::to_hex::upper<wchar_t>(hr).c_str();

  result+=L"]";
 }//else

 //------
 return result;
}//VARIANT::get_print_wstr                                                //!!!

////////////////////////////////////////////////////////////////////////////////
