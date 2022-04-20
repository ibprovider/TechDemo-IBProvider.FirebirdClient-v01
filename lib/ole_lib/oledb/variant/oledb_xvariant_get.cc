////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_xvariant_get_CC_
#define _oledb_xvariant_get_CC_

#include <ole_lib/oledb/variant/oledb_variant_cvt_context_std.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class base_dbvariant_get_data_utils

template<class Allocator>
HRESULT basic_dbvariant<Allocator>::GetDataEx(LPCCONVCONTEXT const pConvCtx,
                                              const DBBINDING&     Binding,
                                              void*          const pData)const
{
 assert(pConvCtx);

 //-----------------------------------------------------------------------
 const char c_bugcheck_src[]
  ="basic_dbvariant<Allocator>::GetDataEx";

 //-----------------------------------------------------------------------
 if(Binding.dwPart==0)
  return NOERROR;

 if(pData==NULL)
  return E_INVALIDARG;

 //binding variables -----------------------------------------------------
 status_type LocalBinding_Status;
 length_type LocalBinding_Length;

 status_type& Binding_Status=OLEDB_STATUS_IS_BOUND(Binding)
                             ?OLEDB_BINDING_STATUS(Binding,pData)
                             :LocalBinding_Status;

 //размер данных в байтах!
 length_type& Binding_Length=OLEDB_LENGTH_IS_BOUND(Binding)
                             ?OLEDB_BINDING_LENGTH(Binding,pData)
                             :LocalBinding_Length;

 void* const Binding_pValue =OLEDB_VALUE_IS_BOUND(Binding)
                            ?&OLEDB_BINDING_VALUE(Binding,pData)
                            :NULL;

 //инициализаци€ ---------------------------------------------------------
 CHECK_WRITE_PTR(&Binding_Status,sizeof(Binding_Status));
 CHECK_WRITE_PTR(&Binding_Length,sizeof(Binding_Length));

 Binding_Status=DBSTATUS_E_CANTCREATE;

 Binding_Length=0;

 if(Binding_pValue!=NULL)
 {
  CHECK_WRITE_PTR(Binding_pValue,Binding.cbMaxLen);

  memset(Binding_pValue,0,Binding.cbMaxLen);
 }//if

 //проверка корректности определени€ владельца пам€ти --------------------
 if(DBVARIANT::IsPointedDataType2(Binding.wType) &&
    Binding.dwMemOwner!=DBMEMOWNER_PROVIDEROWNED &&
    Binding.dwMemOwner!=DBMEMOWNER_CLIENTOWNED)
 {
  //провер€ем, флаги владени€ пам€тью

  ODS_LEVEL_3("ERR: dbvariant::GetDataEx"
                "(iOrd="<<Binding.iOrdinal<<","
                 "BindType=0x"<<std::hex<<Binding.wType<<","
                 "BadMemOwner="<<std::dec<<Binding.dwMemOwner<<")");

  Binding_Status=DBSTATUS_E_BADACCESSOR;

  return DB_E_BADBINDINFO;
 }//if

 //проверка статуса данных -----------------------------------------------
 switch(this->GetDataStatus())
 {
  case DBSTATUS_S_OK:
  case DBSTATUS_S_ISNULL:
  {
   break;
  }//if OK, ISNULL

  case DBSTATUS_S_IGNORE:
  {
   Binding_Status=DBSTATUS_S_IGNORE;
   return NOERROR;
  }//case DBSTATUS_S_IGNORE

  case DBSTATUS_S_DEFAULT:
  {
   //Check the type of default value. Must be corrected.

   if(!pConvCtx->GetTypeConverter(this->wType,OLEDB_EXTRACT_DBTYPE(Binding.wType)))
   {
    assert_msg
     (false,
      "source dbtype: "<<int(this->wType)<<". "
      "target dbtype: "<<int(Binding.wType));

    Binding_Status=DBSTATUS_E_CANTCONVERTVALUE;

    return DB_E_UNSUPPORTEDCONVERSION;
   }//if

   Binding_Status=DBSTATUS_S_DEFAULT;

   return NOERROR;
  }//case DBSTATUS_S_DEFAULT

  default:
  {
   self_type::helper__throw_bug_check__bad_data_status
    (c_bugcheck_src,
     "#001",
     this->GetDataStatus());

   assert_hint(false);
  }//default
 }//switch this->GetDataStatus()

 //-----------------------------------------------------------------------
 assert(this->TestDataStatus__IsOK() || this->TestDataStatus__IsNull());

 self_type ConvertData;

 const DBVARIANT* pSource=this;

 if(!pConvCtx->EqualType(pSource->wType,OLEDB_EXTRACT_DBTYPE(Binding.wType)))
 {
  //запрет конвертировани€ при передаче указател€ на внутренний буфер
  if(Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED && DBVARIANT::IsPointedDataType2(Binding.wType))
  {
   ODS_LEVEL_3("ERR: dbvariant::GetDataEx"
                "(iOrd="<<Binding.iOrdinal<<", "
                 "wType=0x"<<std::hex<<pSource->wType<<", "
                 "BindType=0x"<<std::hex<<Binding.wType<<", "
                 "BadMemOwner="<<std::dec<<Binding.dwMemOwner<<") "
               "- can't convert");

   Binding_Status=DBSTATUS_E_CANTCONVERTVALUE;

   return DB_E_CANTCONVERTVALUE;
  }//if

  //проводим конвертирование
  HRESULT const cvt_hr=ConvertData.assign_as_ex(pConvCtx,*pSource,Binding);

  if(FAILED(cvt_hr))
  {
   ODS_LEVEL_3("ERR: dbvariant::GetDataEx"
                "(iOrd="<<Binding.iOrdinal<<", "
                  "wType=0x"<<std::hex<<pSource->wType<<", "
                  "BindType=0x"<<std::hex<<Binding.wType<<") "
               "- can't convert");

   Binding_Status=oledb_lib::MapDBErrorToDBStatus(cvt_hr);

   return cvt_hr;
  }//if

  assert_msg(cvt_hr==S_OK,"cvt_hr=0x"<<std::hex<<cvt_hr);

  pSource=&ConvertData;

  assert(pSource->TestDataStatus__IsOK() || pSource->TestDataStatus__IsNull());
 }//if - конвертирование

 assert(pSource!=NULL);

 assert_msg(OLEDB_EXTRACT_DBTYPE(Binding.wType)==pSource->wType,
             "Target=="<<OLEDB_EXTRACT_DBTYPE(Binding.wType)<<"\n"
             "Source=="<<pSource->wType);

 //¬озвращаем NULL -------------------------------------------------------
 if(pSource->TestDataStatus__IsNull())
 {
  Binding_Status=DBSTATUS_S_ISNULL;

  return NOERROR;
 }//if

 if(!pSource->TestDataStatus__IsOK())
 {
  self_type::helper__throw_bug_check__bad_data_status
   (c_bugcheck_src,
    "#002",
    this->GetDataStatus());

  assert(false);
 }//if

 //ѕолучаем сервисный объект работы с wTargetType ------------------------
 LPCTYPESERVICE const lpcTypeService=pSource->GetTypeService();

 if(lpcTypeService==NULL)
 {
  Binding_Status=DBSTATUS_E_UNAVAILABLE;

  return E_NOTIMPL;
 }//if

 //определ€ем размер данных ----------------------------------------------
 length_type  cbMemSize;
 length_type  cbMinMemSize;//минимальный размер пам€ти

 lpcTypeService->get_size2
  (*pSource,
   Binding_Length,
   cbMemSize,
   cbMinMemSize); //throw

 //данные не надо возвращать ---------------------------------------------
 if((Binding.dwPart&DBPART_VALUE)==0)
 {
  Binding_Status=DBSTATUS_S_OK;

  return NOERROR;
 }//if

 //определ€ем буфер записи данных ----------------------------------------
 void* pBuffer=NULL;

 CO_MEM_POINTER3(char) SeparateBuffer;

 if((Binding.wType&DBTYPE_BYREF)==0)
 {
  if(Binding.cbMaxLen<cbMinMemSize)
  {
   Binding_Status=DBSTATUS_E_BADACCESSOR; //accessor не должен такое пропускать !!!

   return DB_E_BADBINDINFO;
  }

  pBuffer=Binding_pValue;

  cbMemSize=Binding.cbMaxLen; //размеры определ€ет клиент
 }
 else //-----------------------------------------------  DBTYPE_BYREF
 if(Binding.cbMaxLen<sizeof(void*))
 {
  Binding_Status=DBSTATUS_E_BADACCESSOR;

  return DB_E_BADBINDINFO;
 }
 else
 if(Binding.dwMemOwner==DBMEMOWNER_PROVIDEROWNED)
 {
  //помещаем в буфер указатель на собственные данные

  assert(this->wType==OLEDB_EXTRACT_DBTYPE(Binding.wType));//еще раз - типы должны совпадать
  assert(pSource==this);

  cbMemSize=Binding.cbMaxLen; //size of buffer defined by user

  pBuffer=Binding_pValue;
 }
 else  //DONE 5: ѕроверить освобождение пам€ти в случае ошибки
 {
  if(cbMemSize!=0)
  {
   SeparateBuffer=reinterpret_cast<char*>(::CoTaskMemAlloc(cbMemSize));

   if(!SeparateBuffer)
   {
    Binding_Status=DBSTATUS_E_CANTCREATE;

    return E_OUTOFMEMORY;
   }//if

   pBuffer=SeparateBuffer;

   memset(pBuffer,0,cbMemSize);
  }//if
 }//else - возвращаем указатель

 //провер€м полученный указатель на буфер -------------------------------
 CHECK_WRITE_PTR(pBuffer,cbMemSize);

 //копирование данных ---------------------------------------------------
 const HRESULT hr
   =lpcTypeService->get_data2
      (*pSource,
       Binding,
       cbMemSize,
       Binding_Status,
       Binding_Length,
       pBuffer); //throw

 assert_msg(hr==S_OK || FAILED(hr),
            "hr="<<structure::tstr_to_str(ole_lib::TestHResult(hr)));

 if(hr==S_OK && SeparateBuffer!=NULL)
 {
  CHECK_WRITE_PTR(Binding_pValue,sizeof(void*));

  (*reinterpret_cast<void**>(Binding_pValue))=SeparateBuffer.release();
 }//if

 return hr;
}//GetDataEx

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::GetData(const DBBINDING& Binding,
                                            void*   const    pData)const
{
 const TDBVariant_TypeCvtContext_Std ConvCtx;

 return this->GetDataEx(&ConvCtx,Binding,pData);
}//GetData

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
