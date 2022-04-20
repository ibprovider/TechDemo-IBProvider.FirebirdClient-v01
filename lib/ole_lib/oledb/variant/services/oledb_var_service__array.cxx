////////////////////////////////////////////////////////////////////////////////
//DBTYPE_ARRAY Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//ARRAY

t_oledb_type_service_ARRAY::length_type t_oledb_type_service_ARRAY::get_align()const
{
 return __alignof(value_type);
}//get_align

//------------------------------------------------------------------------
void t_oledb_type_service_ARRAY::internal__get_size__ok
                                           (const DBVARIANT&  DEBUG_CODE(dbvar),
                                            length_type&      cbSize,
                                            length_type&      cbMemSize,
                                            length_type&      cbMinSize)const
{
 assert(this->get_type()&DBTYPE_ARRAY);
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 cbSize=cbMemSize=cbMinSize=sizeof(value_type);
}//ARRAY::internal__get_size__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_ARRAY::internal__get_data__ok
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
  (*reinterpret_cast<const value_type**>(pBuffer))=&dbvar.arrayVal2.ptr;  /*!*/
 }
 else
 {
  assert(cbMemSize>=sizeof(value_type));

  if(Binding.dwMemOwner==DBMEMOWNER_CLIENTOWNED)
  {
   //хотят получить копию данных

   if(dbvar.arrayVal2.ptr==NULL)
   {
    (*reinterpret_cast<value_type*>(pBuffer))=NULL;
   }
   else //return copy of array                                            /*!*/
   {
    const HRESULT hr=ole_lib::SafeArray_Copy(dbvar.arrayVal2.ptr,
                                             reinterpret_cast<value_type*>(pBuffer));
    if(FAILED(hr))
    {
     Binding_Status=DBSTATUS_E_CANTCREATE;
     return hr;
    }

    assert(hr==S_OK);
   }//if
  }
  else
  {
   //! \todo
   //!  Реализовать нормальное ветвление clientowned/providerowned/error

   //хотят получить указатель на собственные данные
   assert(Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED);

   (*reinterpret_cast<value_type*>(pBuffer))=dbvar.arrayVal2.ptr;         /*!*/
  }//else
 }//else !(BYREF && PROVIDEROWNED)

 return S_OK;
}//ARRAY::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_ARRAY::get_element(DBVARIANT*   const DEBUG_CODE(dest),
                                                REFIID             /*ElementIID*/,
                                                length_type  const DEBUG_CODE(cbElement),
                                                const void*  const DEBUG_CODE(pElement))const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 return DB_E_NOTSUPPORTED;
}//ARRAY::get_element

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_ARRAY::set_element(LPCCONVCONTEXT      /*pConvCtx*/,
                                                const DBVARIANT&    /*source*/,
                                                REFIID              /*ElementIID*/,
                                                length_type   const DEBUG_CODE(cbElement),
                                                void*         const DEBUG_CODE(pElement),
                                                status_type*  const pBinding_Status)const
{
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 (*pBinding_Status)=DBSTATUS_E_CANTCONVERTVALUE;

 return DB_E_NOTSUPPORTED;
}//ARRAY::set_element

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_ARRAY::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"ARRAY[");

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
 result+=structure::to_hex::upper<wchar_t>((INT_PTR)dbvar.arrayVal2.ptr).c_str();
 result+=L", ";
 result+=ole_lib::guid_to_wstring(dbvar.arrayVal2.element_iid);
 result+=L"]";

 //-------
 return result;
}//get_print_wstr

////////////////////////////////////////////////////////////////////////////////
