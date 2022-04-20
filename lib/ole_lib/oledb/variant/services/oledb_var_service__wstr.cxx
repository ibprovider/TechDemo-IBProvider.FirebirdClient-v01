////////////////////////////////////////////////////////////////////////////////
//DBTYPE_WSTR Service
//                                                  Kovalenko Dmitry 04.11.2008

////////////////////////////////////////////////////////////////////////////////
//WSTR

DEFINE_OLEDB_TYPE_SERVICE_OBJ(WSTR)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_CONVERTOR(WSTR)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_SERVICE_GET_ALIGN(WSTR)

//------------------------------------------------------------------------
t_oledb_type_service_WSTR::length_type
 t_oledb_type_service_WSTR::internal__get_length__ok(const DBVARIANT& dbvar)const
{
 assert(this->get_type()==DBTYPE_WSTR);
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 assert_s(sizeof(length_type)==sizeof(DBVARIANT::size_type));
 assert(structure::t_numeric_limits<length_type>::min_value()==0);

 CHECK_READ_TYPED_PTR(dbvar.wstrVal.ptr,dbvar.wstrVal.len);

 return static_cast<length_type>(dbvar.wstrVal.len);
}//WSTR::internal__get_length__ok

//------------------------------------------------------------------------
t_oledb_type_service_WSTR::length_type
 t_oledb_type_service_WSTR::get_binary_length(length_type DataLength)const
{
 assert(this->get_type()==DBTYPE_WSTR);

 return DataLength*sizeof(value_type);
}//WSTR::get_binary_length

//------------------------------------------------------------------------
void t_oledb_type_service_WSTR::internal__get_size__ok
                                           (const DBVARIANT&  dbvar,
                                            length_type&      cbSize,
                                            length_type&      cbMemSize,
                                            length_type&      cbMinSize)const
{
 assert(this->get_type()==DBTYPE_WSTR);
 assert(dbvar.wType==this->get_type());
 assert(dbvar.TestDataStatus__IsOK());

 cbMinSize =0;
 cbSize    =dbvar.wstrVal.byte_count();                                   /*!*/
 cbMemSize =cbSize+sizeof(value_type);
}//WSTR::internal__get_size__oks

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_WSTR::internal__get_data__ok
                                           (const DBVARIANT& dbvar,
                                            const DBBINDING& Binding,
                                            length_type      cbMemSize,
                                            status_type&     Binding_Status,
                                            length_type&     Binding_Length,
                                            void*            pBuffer)const
{
 assert(dbvar.wType==this->get_type());
 assert(dbvar.wType==(Binding.wType&~DBTYPE_BYREF));
 assert(dbvar.TestDataStatus__IsOK());

 CHECK_WRITE_PTR(pBuffer,cbMemSize);

 //-----------------------------------------
 Binding_Status=DBSTATUS_S_OK;
 Binding_Length=dbvar.wstrVal.byte_count();                                /*!*/

 if((Binding.wType&DBTYPE_BYREF) && Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED)
 {
  assert(cbMemSize>=sizeof(void*));

  //возвращаем указатель на собственные данные
  (*reinterpret_cast<const value_type**>(pBuffer))=dbvar.wstrVal.ptr;     /*!*/
 }
 else
 {
  //уменьшение cbMemSize проводиться для завершающего L'\0'
  if(length_type const x=cbMemSize%sizeof(value_type))
   cbMemSize-=x;

  //кратность размеру value_type
  assert((cbMemSize%sizeof(value_type))==0);

  const BYTE* const pEndBuffer=reinterpret_cast<const BYTE*>(pBuffer)+cbMemSize;

  //условие когда строка будет обрезана
  if(Binding_Length!=0 && (cbMemSize==0 || Binding_Length>cbMemSize-sizeof(value_type)))
  {
   ODS_LEVEL_3("WAR: GetData(iOrd="<<Binding.iOrdinal<<",Len:"<<Binding_Length<<","
                            "cbMemSize:"<<cbMemSize<<") - trunc WSTR");

   Binding_Status=DBSTATUS_S_TRUNCATED;

   if(cbMemSize!=0)
    cbMemSize-=sizeof(value_type); //место под завершающий символ
  }

  const length_type copy_cnt=min(cbMemSize,Binding_Length);

  CHECK_READ_PTR(dbvar.wstrVal.ptr,copy_cnt);

  memcpy(pBuffer,dbvar.wstrVal.ptr,copy_cnt);

  pBuffer=reinterpret_cast<BYTE*>(pBuffer)+copy_cnt;

  if(pEndBuffer-reinterpret_cast<BYTE*>(pBuffer)>=sizeof(value_type))
   (*reinterpret_cast<value_type*>(pBuffer))=0;
 }//else - возвращаем копию данных

 return S_OK;
}//WSTR::internal__get_data__ok

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_WSTR::get_element                            //!!!
                                            (DBVARIANT*   const dest,
                                             REFIID             /*ElementIID*/,
                                             length_type        cbElement,
                                             const void*  const pElement)const
{
 assert(dest);

 CHECK_READ_PTR(pElement,cbElement);

 assert(this->get_type()==DBTYPE_WSTR);                                   //!!!

 assert_s(sizeof(*dest->wstrVal.ptr)==sizeof(value_type));                //!!!

 //--------
 if((cbElement%sizeof(value_type))!=0)
  return E_FAIL;

 if(pElement==NULL && cbElement!=0)
  return E_FAIL;

 //--------
 cbElement=cbElement/sizeof(value_type);

 const value_type* const pStr=reinterpret_cast<const value_type*>(pElement);

 for(;cbElement!=0;--cbElement)
 {
  if(pStr[cbElement-1]!=0)
   break;
 }//for

 dest->wstrVal.ptr=const_cast<value_type*>(pStr);                         //!!!
 dest->wstrVal.len=cbElement;                                             //!!!

 dest->wType=this->get_type();

 dest->SetDataStatus__OK();

 return S_OK;
}//WSTR::get_element                                                      //!!!

//------------------------------------------------------------------------
static HRESULT oledb_type_service_WSTR_set_element__CANT_CVT(DBSTATUS* const pBinding_Status)
{
 assert(pBinding_Status);

 (*pBinding_Status)=DBSTATUS_E_CANTCONVERTVALUE;

 return DB_E_CANTCONVERTVALUE;
}//oledb_type_service_WSTR_set_element__CANT_CVT

//------------------------------------------------------------------------
static HRESULT oledb_type_service_WSTR_set_element(size_t          cWStr,
                                                   const wchar_t*  pWStr,
                                                   DBLENGTH  const cbElement,
                                                   void*     const pElement,
                                                   DBSTATUS* const pBinding_Status)
{
 typedef wchar_t char_type;

 assert(pBinding_Status);
 assert_s(sizeof(*pWStr)==sizeof(char_type));

 CHECK_READ_TYPED_PTR(pWStr,cWStr);
 CHECK_WRITE_PTR(pElement,cbElement);

 const DBLENGTH cDest=cbElement/sizeof(char_type);

 //ignore terminate symbols
 while(cDest<cWStr)
 {
  --cWStr;

  if(pWStr[cWStr]==0)
   continue;

  return oledb_type_service_STR_set_element__DATA_OVERFLOW(pBinding_Status);
 }//while

 assert(cWStr<=cDest);

 char_type* pDestData=reinterpret_cast<char_type*>(pElement);

#ifndef NDEBUG
 const char_type* const eDestData=pDestData+cDest;
#endif

 const char_type* const eWStr=pWStr+cWStr;

 for(;pWStr!=eWStr;++pWStr,++pDestData)
 {
  assert(pDestData!=eDestData);

  (*pDestData)=(*pWStr);
 }//for

 std::fill(reinterpret_cast<char*>(pDestData),
           reinterpret_cast<char*>(pElement)+cbElement,
           structure::zero);

 (*pBinding_Status)=DBSTATUS_S_OK;

 return S_OK;
}//oledb_type_service_WSTR_set_element

//------------------------------------------------------------------------
HRESULT t_oledb_type_service_WSTR::set_element                            //!!!
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     source,
                                             REFIID               /*ElementIID*/,
                                             length_type    const cbElement,
                                             void*          const pElement,
                                             status_type*   const pBinding_Status)const
{
 assert(this->get_type()==DBTYPE_WSTR);                                   //!!!
 assert(pBinding_Status);

 CHECK_WRITE_PTR(pElement,cbElement);

 assert_s(sizeof(*source.wstrVal.ptr)==sizeof(value_type));               //!!!

 if(!source.TestDataStatus__IsOK())
  return oledb_type_service_WSTR_set_element__CANT_CVT(pBinding_Status);

 if(source.wType==DBTYPE_WSTR)
 {
  CHECK_READ_TYPED_PTR(source.wstrVal.ptr,source.wstrVal.len)

  return oledb_type_service_WSTR_set_element
          (source.wstrVal.len,
           source.wstrVal.ptr,
           cbElement,
           pElement,
           pBinding_Status);
 }//if

 //-----------------------------------------------------------------------
 DBVARIANT::value_cpp_wstr_n_type elementValue;

 const HRESULT cvt_hr=DBVariant__to_WSTR_ex(pConvCtx,source,&elementValue);

 if(FAILED(cvt_hr))
 {
  (*pBinding_Status)=oledb_lib::MapDBErrorToDBStatus(cvt_hr);

  return cvt_hr;
 }//if

 assert(cvt_hr==S_OK);

 if(elementValue.null())
  return oledb_type_service_WSTR_set_element__CANT_CVT(pBinding_Status);

 return oledb_type_service_WSTR_set_element
         (elementValue.value().size(),
          elementValue.value().c_str(),
          cbElement,
          pElement,
          pBinding_Status);
}//WSTR::set_element                                                      //!!!

//------------------------------------------------------------------------
std::wstring t_oledb_type_service_WSTR::get_print_wstr(const DBVARIANT& dbvar)const
{
 assert(dbvar.wType==this->get_type());

 //-------
 std::wstring result(L"WSTR[");

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

 CHECK_READ_TYPED_PTR(dbvar.wstrVal.ptr,dbvar.wstrVal.len);               //!!!

 result+=L"[len:";

 result+=structure::t_str_args_traits<wchar_t>::arg(dbvar.wstrVal.len);

 result+=L"][";

 //-------
 if(!dbvar.wstrVal.ptr)                                                   //!!!
 {
  result.append(L"#NULL_PTR");
 }
 else
 {
  result.append(dbvar.wstrVal.ptr,dbvar.wstrVal.len);
 }//else

 result+=L"]";

 //-------
 return result;
}//WSTR::get_print_wstr                                                   //!!!

////////////////////////////////////////////////////////////////////////////////
