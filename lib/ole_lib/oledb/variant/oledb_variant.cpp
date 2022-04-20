////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/oledb_variant_services.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt_context_std.h>
#include <ole_lib/ole_auto/ole_auto_variant.h>
#include <ole_lib/ole_auto/ole_auto_variant_type_info.h>
#include <structure/t_str_formatter.h>
#include <structure/utilities/to_hex.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT

bool DBVARIANT::GetIID(IID* const piid)const
{
 assert(piid);

 if(this->wType==DBTYPE_IUNKNOWN)
 {
  (*piid)=this->unkVal.iid;

  return true;
 }//if

 if((this->wType&DBTYPE_ARRAY)==DBTYPE_ARRAY)
 {
  (*piid)=this->arrayVal2.element_iid;

  return true;
 }//if

 (*piid)=IID_NULL;

 return false;
}//GetIID

//------------------------------------------------------------------------
bool DBVARIANT::SetIID(REFIID riid)
{
 if(this->wType==DBTYPE_IUNKNOWN)
  this->unkVal.iid=riid;
 else
 if((this->wType&DBTYPE_ARRAY)==DBTYPE_ARRAY)
  this->arrayVal2.element_iid=riid;
 else
  return false;

 return true;
}//SetIID

//------------------------------------------------------------------------
bool DBVARIANT::IsNull()const
{
 const char c_bugcheck_src[]
  ="DBVARIANT::IsNull";

 switch(DBSTATUS const _s=this->GetDataStatus())
 {
  case DBSTATUS_S_OK:
  case DBSTATUS_S_TRUNCATED:
   return false;

  case DBSTATUS_S_ISNULL:
   return true;

  default:
  {
   assert_msg(false,"value status: "<<_s);

   structure::str_formatter
    fmsg("[BUG CHECK] Can't test NULL state of dbvalue with status [%2]. Check point [%1].");

   fmsg
    <<c_bugcheck_src
    <<oledb_lib::GetDBStatusName(_s);

   throw std::runtime_error(fmsg);
  }//default
 }//switch _s
}//IsNull

//------------------------------------------------------------------------
bool DBVARIANT::IsNull_Ext()const
{
 const char c_bugcheck_src[]
  ="DBVARIANT::IsNull_Ext";

 switch(DBSTATUS const _s=this->GetDataStatus())
 {
  case DBSTATUS_S_OK:
  {
   if(this->wType==DBTYPE_NULL)
    return true;

   if(this->wType==DBTYPE_VARIANT)
    return this->varVal.vt==VT_NULL;

   return false;
  }//case IsOK

  case DBSTATUS_S_TRUNCATED: //BYTES, STR, WSTR
  {
   return false;
  }//case TRUNCATED

  case DBSTATUS_S_ISNULL:
  {
   return true;
  }//case ISNULL

  default:
  {
   assert_msg(false,"value status: "<<_s);

   structure::str_formatter
    fmsg("[BUG CHECK] Can't test NULL state of dbvalue with status [%2]. Check point [%1].");

   fmsg
    <<c_bugcheck_src
    <<oledb_lib::GetDBStatusName(_s);

   throw std::runtime_error(fmsg);
  }//default
 }//switch _s
}//IsNull_Ext

//------------------------------------------------------------------------
void DBVARIANT::IsNull(bool const Null)
{
 if(Null)
  this->SetDataStatus__IsNull();
 else
  this->SetDataStatus__OK();
}//IsNull(bool)

////////////////////////////////////////////////////////////////////////////////

namespace oledb_lib_utils{
////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/variant/oledb_variant_dbtype.inc>
////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib_utils

////////////////////////////////////////////////////////////////////////////////

DBVARIANT::LPCTYPEINFO DBVARIANT::GetInfo(DBTYPE const wType)
{
 //[2018-03-02] ƒа будет так.
 assert(OLEDB_EXTRACT_DBTYPE(wType)==wType);

 using oledb_lib_utils::g_DBTypes;

 UINT iType=wType;

 if(iType<_DIM_(g_DBTypes))
  return g_DBTypes[iType].pSimpleTypeInfo;

 if(iType&DBTYPE_ARRAY)
 {
  iType&=~DBTYPE_ARRAY;

  if(iType<_DIM_(g_DBTypes))
   return g_DBTypes[iType].pArrayTypeInfo;
 }//if Array

 return nullptr;
}//GetInfo

////////////////////////////////////////////////////////////////////////////////

DBVARIANT::length_type DBVARIANT::GetAlign2(DBTYPE const wType)
{
 const char c_bugcheck_src[]
  ="DBVARIANT::GetAlign2(wType)";

 if((wType&DBTYPE_BYREF)==DBTYPE_BYREF)
  return __alignof(void*);

 if((wType&DBTYPE_ARRAY)==DBTYPE_ARRAY)
  return __alignof(LPSAFEARRAY);

 if((wType&DBTYPE_VECTOR)==DBTYPE_VECTOR)
  return __alignof(DBVECTOR);

 if(DBVARIANT::LPCTYPESERVICE const pTypeSvc=DBVARIANT::GetTypeService(wType))
  return pTypeSvc->get_align();

 self_type::helper__throw_bug_check__unexpected_dbtype
  (c_bugcheck_src,
   "#001",
   wType);

#if(COMP_BUILD_UNUSED_CODE)
 return 1;
#endif
}//GetAlign2

//------------------------------------------------------------------------
bool DBVARIANT::IsVariableLen2(DBTYPE const wType)
{
 const char c_bugcheck_src[]
  ="DBVARIANT::IsVariableLen2(wType)";

 if(wType&DBTYPE_BYREF)
  return false;

 if(LPCTYPEINFO const pInfo=self_type::GetInfo(wType)) 
  return pInfo->VariableLen();

 self_type::helper__throw_bug_check__unexpected_dbtype
  (c_bugcheck_src,
   "#001",
   wType);

#if(COMP_BUILD_UNUSED_CODE)
 return false;
#endif
}//IsVariableLen2

//------------------------------------------------------------------------
bool DBVARIANT::IsPointedDataType2(DBTYPE const wType)
{
 if(wType==DBTYPE_BSTR)
  return true;

 if(wType==DBTYPE_VARIANT)
  return true;

 if(wType==DBTYPE_IUNKNOWN)
  return true;

 if(wType==DBTYPE_IDISPATCH)
  return true;

 if(wType&(DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_VECTOR))
  return true;

 return false;
}//IsPointedDataType2

////////////////////////////////////////////////////////////////////////////////
//¬озможность конвертировани€ между типами (на уровне библиотеки)

bool DBVARIANT::CanConvert(DBTYPE const _wFromType,const DBBINDING& ToBinding)
{
 DBTYPE const wFromType =OLEDB_EXTRACT_DBTYPE(_wFromType);
 DBTYPE const wToType   =OLEDB_EXTRACT_DBTYPE(ToBinding.wType);

 const TDBVariant_TypeCvtContext_Std ConvCtx;

 LPCTYPECONVERTER const pCvt=ConvCtx.GetTypeConverter(wFromType,wToType);

 if(pCvt==NULL)
  return false;

 LPCTYPECONVERTER_DBBINDING_TEST const pDbBindingTest
  =dynamic_cast<LPCTYPECONVERTER_DBBINDING_TEST>(pCvt);

 if(pDbBindingTest!=NULL)
  return pDbBindingTest->CanConvertTo(&ConvCtx,ToBinding);

 //by default
 return true;
}//CanConvert

//------------------------------------------------------------------------
static bool DBVARIANT_CanConvert_Impl(DBTYPE wFromType,DBTYPE wToType)
{
 wFromType =OLEDB_EXTRACT_DBTYPE(wFromType);
 wToType   =OLEDB_EXTRACT_DBTYPE(wToType);

 return DBVARIANT::GetTypeConverter(wFromType,wToType)!=NULL;
}//DBVARIANT_CanConvert_Impl

//------------------------------------------------------------------------
bool DBVARIANT::CanConvert(DBTYPE const wFromType,DBTYPE const wToType)
{
 if(DBVARIANT_CanConvert_Impl(wFromType,wToType))
  return true;

 ODS_LEVEL_2("FAIL: [DBVARIANT::CanConvert] "
             "FROM "<<structure::tstr_to_str(self_type::GetTypeName(wFromType,0))
             <<" "
             "TO "<<structure::tstr_to_str(self_type::GetTypeName(wToType,0)));

 return false;
}//CanConvert

////////////////////////////////////////////////////////////////////////////////
//OLEDB Data Types helper functions

t_oledb_string DBVARIANT::GetTypeName(DBTYPE        const wType,
                                      DBCOLUMNFLAGS const flags)
{
 DBTYPE const wClearType=OLEDB_EXTRACT_DBTYPE(wType);

 LPCTYPEINFO const pInfo=self_type::GetInfo(wClearType);

 t_oledb_string resultStr;

 if(pInfo!=NULL && pInfo->Name)
 {
  resultStr=pInfo->Name;
 }
 else
 {
  t_oledb_char tmpStr[80];

  _VERIFY_EQ(_OLEDB_LIB_ltot_s(wClearType,tmpStr,_DIM_(tmpStr),10),0L);

  resultStr=tmpStr;
 }//else

 //---------
 if((wType&DBTYPE_BYREF)==DBTYPE_BYREF)
 {
  resultStr+=_OLEDB_LIB_T(" [DBTYPE_BYREF]");
 }//if

 //---------
 DBCOLUMNFLAGS const type_flags
  =(flags&(DBCOLUMNFLAGS_ISFIXEDLENGTH|DBCOLUMNFLAGS_ISLONG));

 if(type_flags!=0)
 {
  const t_oledb_string text_with_flags
   =oledb_lib::GetDBColumnFlagName(type_flags,_OLEDB_LIB_T(" "));

  assert(!text_with_flags.empty());

  resultStr+=_OLEDB_LIB_T(" ");

  resultStr+=text_with_flags;
 }//if type_flags

 return resultStr;
}//GetTypeName

//------------------------------------------------------------------------
t_oledb_string DBVARIANT::GetParamTypeName(DBTYPE const wType,DBPARAMFLAGS const flags)
{
 t_oledb_string t(self_type::GetTypeName(wType,0));

 t+=flags?_OLEDB_LIB_T(" "):_OLEDB_LIB_T("");

 return t.append(oledb_lib::GetDBParamFlagName(flags,_OLEDB_LIB_T(" ")));
}//GetParamTypeName

////////////////////////////////////////////////////////////////////////////////
#ifndef OLEDB_LIB_NO_ADODB_TYPES
////////////////////////////////////////////////////////////////////////////////

namespace oledb_lib_utils{
#include <ole_lib/oledb/variant/oledb_variant_adotype.inc>
}//namespace oledb_lib_utils

////////////////////////////////////////////////////////////////////////////////

t_oledb_string DBVARIANT::GetAdoParamTypeName(AdoDataTypeEnum const adType)
{
 const LPCPARAMINFO lpcParamInfo(self_type::GetAdoParamInfo(adType));

 if(lpcParamInfo)
  return lpcParamInfo->adTypeName;

 t_oledb_char tmpStr[80];

 _VERIFY_EQ(_OLEDB_LIB_ltot_s(adType,tmpStr,_DIM_(tmpStr),10),0L);

 return t_oledb_string(tmpStr);
}//GetAdoParamTypeName

//------------------------------------------------------------------------
DBVARIANT::LPCPARAMINFO DBVARIANT::GetAdoParamInfo(AdoDataTypeEnum const adType)
{
 using oledb_lib_utils::g_ADOTypes;

 UINT _adType=UINT(adType)&~DBTYPE_BYREF;

 if(_adType<_DIM_(g_ADOTypes))
  return g_ADOTypes[_adType].pSimpleTypeInfo;

 if(_adType&DBTYPE_ARRAY)
 {
  _adType&=~DBTYPE_ARRAY;

  if(_adType<_DIM_(g_ADOTypes))
   return g_ADOTypes[_adType].pArrayTypeInfo;
 }//if

 return nullptr;
}//GetAdoParamInfo

//------------------------------------------------------------------------
DBVARIANT::LPCPARAMINFO DBVARIANT::GetParamInfo(DBTYPE wType,DBCOLUMNFLAGS dwColumnFlags)
{
 using oledb_lib_utils::g_DBTypeToADOTypeMap;

 //нас интересуют только флаги размера
 dwColumnFlags&=(DBCOLUMNFLAGS_ISLONG|DBCOLUMNFLAGS_ISFIXEDLENGTH);

 wType=OLEDB_EXTRACT_DBTYPE(wType);

 const UINT iType=OLEDB_EXTRACT_SIMPLE_DBTYPE(wType);

 if(iType>=_DIM_(g_DBTypeToADOTypeMap) || !g_DBTypeToADOTypeMap[iType])
  return nullptr;

 assert(UINT(g_DBTypeToADOTypeMap[iType]->wType)==iType);

 //ищем описание параметра по wType+ColumnFlags
 for(const DBVARIANT::LPCPARAMINFO* param(g_DBTypeToADOTypeMap[iType]->map);(*param)!=NULL;++param)
 {
  if((*param)->wType==wType && (*param)->dwColumnFlags==dwColumnFlags)
   return *param;
 }//for

 return nullptr;
}//GetParamInfo

////////////////////////////////////////////////////////////////////////////////
#endif //ifndef OLEDB_LIB_NO_ADODB_TYPES

////////////////////////////////////////////////////////////////////////////////

DBVARIANT::length_type
 DBVARIANT::GetStringSizeOfTypePresentation(DBTYPE            wType,
                                            length_type const Size)
{
 wType=OLEDB_EXTRACT_DBTYPE(wType);

 if(wType==DBTYPE_STR || wType==DBTYPE_WSTR)
  return Size;

 if(wType==DBTYPE_BYTES)
  return 2*Size;//present in HEX

 //TODO: Need use information about precision and scale of NUMERIC
 if(wType==DBTYPE_NUMERIC)
  return 64;

 if(LPCTYPEINFO const lpcTypeInfo=self_type::GetInfo(wType))
  return lpcTypeInfo->StringPresentation;

 return 0;
}//GetStringSizeOfTypePresentation

////////////////////////////////////////////////////////////////////////////////

DBVARIANT::length_type
 DBVARIANT::GetBinarySizeOfTypePresentation(DBTYPE      const wType,
                                            length_type const Size)
{
 if(LPCTYPESERVICE const lpcTypeService=self_type::GetTypeService(OLEDB_EXTRACT_DBTYPE(wType)))
  return lpcTypeService->get_binary_length(Size);

 return 0;
}//GetStringSizeOfTypePresentation

////////////////////////////////////////////////////////////////////////////////
//DBVARIANT::EqualBindingStatus

bool DBVARIANT::EqualBindingStatus(const DBBINDING& Binding,
                                   void*    const   pData,
                                   DBSTATUS const   Status)
{
 if(!OLEDB_STATUS_IS_BOUND(Binding))
  return false;

 CHECK_READ_PTR(&OLEDB_BINDING_STATUS(Binding,pData),sizeof(DBSTATUS));

 return OLEDB_BINDING_STATUS(Binding,pData)==Status;
}//EqualBindingStatus

////////////////////////////////////////////////////////////////////////////////

DBVARIANT::length_type DBVARIANT::GetAlign2()const
{
 const char c_bugcheck_src[]
  ="DBVARIANT::GetAlign2";

 if(LPCTYPESERVICE const lpcTypeService=self_type::GetTypeService(this->wType))
  return lpcTypeService->get_align();

 self_type::helper__throw_bug_check__unexpected_dbtype
  (c_bugcheck_src,
   "#001",
   this->wType);
}//GetAlign2

//------------------------------------------------------------------------
//Length and MemSize - are measured in bytes
void DBVARIANT::GetSize2(length_type& cbSize,
                         length_type& cbMemSize) const
{
 const char c_bugcheck_src[]
  ="DBVARIANT::GetSize2";

 if(LPCTYPESERVICE const lpcTypeService=self_type::GetTypeService(this->wType))
 {
  length_type cbMinMemSize;

  lpcTypeService->get_size2
   (*this,
    cbSize,
    cbMemSize,
    cbMinMemSize); //throw

  return;
 }//if

 self_type::helper__throw_bug_check__unexpected_dbtype
  (c_bugcheck_src,
   "#001",
   this->wType);
}//GetSize2

//------------------------------------------------------------------------
DBVARIANT::length_type DBVARIANT::GetSize2() const
{
 length_type cbSize,cbMemSize;

 this->GetSize2(cbSize,cbMemSize); //throw

 return cbSize;
}//GetSize2

//------------------------------------------------------------------------
DBVARIANT::length_type DBVARIANT::GetMemSize2() const
{
 length_type cbSize,cbMemSize;

 this->GetSize2(cbSize,cbMemSize); //throw

 return cbMemSize;
}//GetMemSize2

//------------------------------------------------------------------------
DBVARIANT::length_type DBVARIANT::GetLength2()const
{
 if(LPCTYPESERVICE const lpcTypeService=GetTypeService(wType))
  return lpcTypeService->get_length2(*this);

 return 0;
}//GetLength2

//------------------------------------------------------------------------
std::wstring DBVARIANT::get_print_wstr()const
{
 if(LPCTYPESERVICE const pService=this->GetTypeService())
  return pService->get_print_wstr(*this);

 return L"???";
}//get_print_wstr

//------------------------------------------------------------------------
std::string DBVARIANT::get_print_str()const
{
 return structure::tstr_to_str(this->get_print_wstr());
}//get_print_str

//------------------------------------------------------------------------
structure::t_string DBVARIANT::get_print_tstr()const
{
 return structure::tstr_to_tstr(this->get_print_wstr());
}//get_print_tstr

//------------------------------------------------------------------------
void DBVARIANT::helper__throw_bug_check__unexpected_dbtype
                                           (const char* const place,
                                            const char* const point,
                                            DBTYPE      const dbtype)
{
 assert_msg(false,"unexpected dbtype: "<<dbtype);

 structure::str_formatter
  fmsg("[BUG CHECK] Unexpected dbvariant type: 0x%3. Check point [%1][%2].");

 fmsg<<place
     <<point
     <<structure::to_hex::upper<char>(dbtype).c_str();

 throw std::runtime_error(fmsg.str());
}//helper__throw_bug_check__unexpected_dbtype

////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT::TCvtAdapter

HRESULT DBVARIANT::TCvtAdapter::Unpack_Variant(const DBVARIANT& source)
{
 assert(source.wType==DBTYPE_VARIANT);

 const DBSTATUS sourceStatus=source.GetDataStatus();

 switch(sourceStatus)
 {
  case DBSTATUS_S_OK:
  case DBSTATUS_S_ISNULL:
   break;

  default:
   return DB_E_BADSTATUSVALUE;
 }//switch

 const HRESULT hr=this->Unpack_Variant(source.varVal);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 m_dbvar.SetDataStatus(sourceStatus);

 return S_OK;
}//Unpack_Variant - DBVARIANT

//------------------------------------------------------------------------
HRESULT DBVARIANT::TCvtAdapter::Unpack_Variant(const VARIANT& source)
{
 return UnpackVariantToDBVariant(source,&m_dbvar);
}//Unpack_Variant - VARIANT

////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT::TCvtAdapter_Array

DBVARIANT::TCvtAdapter_Array::TCvtAdapter_Array()
 :m_lpsa(NULL)
{;}

//------------------------------------------------------------------------
DBVARIANT::TCvtAdapter_Array::~TCvtAdapter_Array()
{
 _VERIFY_EQ(this->Detach(),S_OK);
}//~TCvtAdapter_Array

//------------------------------------------------------------------------
HRESULT DBVARIANT::TCvtAdapter_Array::Detach()
{
 if(m_lpsa==NULL)
  return S_OK;

 const HRESULT hr=::SafeArrayUnaccessData(m_lpsa);

 if(SUCCEEDED(hr))
  m_lpsa=NULL;

 return hr;
}//Detach

//------------------------------------------------------------------------
HRESULT DBVARIANT::TCvtAdapter_Array::Unpack_VectorUI1_To_Bytes(const DBVARIANT& source)
{
 assert(source.wType==(DBTYPE_ARRAY|DBTYPE_UI1));

 _VERIFY_EQ(this->Detach(),S_OK);

 DBSTATUS const sourceStatus=source.GetDataStatus();

 switch(sourceStatus)
 {
  case DBSTATUS_S_OK:
  case DBSTATUS_S_ISNULL:
   break;

  default:
   return DB_E_BADSTATUSVALUE;
 }//switch

 if(source.TestDataStatus__IsNull() || source.arrayVal2.ptr==NULL)
 {
  m_dbvar.bytesVal.len=0;
  m_dbvar.bytesVal.ptr=NULL;
 }
 else
 {
  assert(source.TestDataStatus__IsOK());

  assert(source.arrayVal2.ptr!=NULL);

  if(::SafeArrayGetDim(source.arrayVal2.ptr)!=1)
   return DB_E_CANTCONVERTVALUE;

  if(::SafeArrayGetElemsize(source.arrayVal2.ptr)!=sizeof(unsigned char))
   return DB_E_CANTCONVERTVALUE;

  {
   VARTYPE vt=VT_EMPTY;

   if(::SafeArrayGetVartype(source.arrayVal2.ptr,&vt)==S_OK)
   {
    if(vt!=VT_UI1)
     return DB_E_CANTCONVERTVALUE;
   }
  }//local

  LONG lb=0;
  LONG ub=0;

  if(FAILED(::SafeArrayGetLBound(source.arrayVal2.ptr,1,&lb)))
   return E_FAIL;

  if(FAILED(::SafeArrayGetUBound(source.arrayVal2.ptr,1,&ub)))
   return E_FAIL;

  if(lb!=0 || ub<-1)
   return DB_E_CANTCONVERTVALUE;

  size_t cbByte=ub<0?size_t(0):(size_t(ub)+1);

  void* lpData=NULL;

  if(FAILED(::SafeArrayAccessData(source.arrayVal2.ptr,&lpData)))
   return E_FAIL;

  if(cbByte!=0 && lpData==NULL)
  {
   _VERIFY_EQ(::SafeArrayUnaccessData(source.arrayVal2.ptr),S_OK);

   return E_FAIL;
  }

  //-----------
  m_dbvar.bytesVal.ptr=lpData;
  m_dbvar.bytesVal.len=cbByte;

  assert(m_lpsa==NULL);

  //data for self::Detach
  m_lpsa=source.arrayVal2.ptr;
 }//else

 m_dbvar.wType=DBTYPE_BYTES;

 m_dbvar.SetDataStatus(sourceStatus);

 return S_OK;
}//Unpack_VectorUI1_To_Bytes

////////////////////////////////////////////////////////////////////////////////

HRESULT UnpackVariantToDBVariant(const VARIANT& var,DBVARIANT* const dbvar)
{
 assert(dbvar);

 const VARIANT* pVariant=NULL;

 if(FAILED(ole_lib::Variant_Unpack(&pVariant,&var,&ole_lib::TVariant::empty_variant)))
  return E_FAIL;

 assert(pVariant);

 if(V_ISARRAY(pVariant))
 {
  SAFEARRAY* psa;

  if(V_ISBYREF(pVariant))
   psa=V_ARRAYREF(pVariant)?*V_ARRAYREF(pVariant):NULL;
  else
   psa=V_ARRAY(pVariant);

  VARTYPE const array_element_vt=VARTYPE(pVariant->vt&~VARTYPE(VT_ARRAY|VT_BYREF));

  const ole_lib::TVariantTypeInfo*
   pArrayElementVarTypeInfo=ole_lib::GetVariantTypeInfo(array_element_vt);

  if(pArrayElementVarTypeInfo==NULL)
   return DB_E_CANTCONVERTVALUE;

  assert(pArrayElementVarTypeInfo->vt==array_element_vt);

  if(psa!=NULL)
  {
   VARTYPE sa_vt;

   if(ole_lib::SafeArray_GetVarType(psa,&sa_vt)==S_OK)
   {
    if(sa_vt!=array_element_vt)
     return E_FAIL;
   }

   const UINT cbElement=::SafeArrayGetElemsize(psa);

   if(cbElement!=pArrayElementVarTypeInfo->size)
    return E_FAIL;
  }//if

  if(pArrayElementVarTypeInfo->oledb_type_id==DBTYPE_EMPTY)
   return DB_E_CANTCONVERTVALUE;

  dbvar->wType         =DBTYPE(DBTYPE_ARRAY|pArrayElementVarTypeInfo->oledb_type_id);
  dbvar->arrayVal2.ptr =psa;

  if(OLEDB_EXTRACT_SIMPLE_DBTYPE(pArrayElementVarTypeInfo->oledb_type_id)==DBTYPE_IUNKNOWN)
   dbvar->arrayVal2.element_iid=IID_IUnknown;

  dbvar->SetDataStatus__OK();

  return S_OK;
 }//if variant has array

 switch(pVariant->vt)
 {
  case VT_EMPTY:
  //case VT_EMPTY|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_EMPTY;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_NULL:
  //case VT_NULL|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_NULL;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_I1:
   {
    dbvar->wType   =DBTYPE_I1;
    dbvar->valI1   =pVariant->cVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_I1|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_I1;
    dbvar->valI1   =DBVARIANT::value_i1_type(pVariant->pcVal?*pVariant->pcVal:0);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_I2:
   {
    dbvar->wType   =DBTYPE_I2;
    dbvar->valI2   =pVariant->iVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_I2|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_I2;
    dbvar->valI2   =DBVARIANT::value_i2_type(pVariant->piVal?*pVariant->piVal:0);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_I4:
   {
    dbvar->wType   =DBTYPE_I4;
    dbvar->valI4   =pVariant->lVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_I4|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_I4;
    dbvar->valI4   =DBVARIANT::value_i4_type(pVariant->plVal?*pVariant->plVal:0);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_I8:
   {
    dbvar->wType          =DBTYPE_I8;
    dbvar->valI8.QuadPart =pVariant->llVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_I8|VT_BYREF:
   {
    dbvar->wType          =DBTYPE_I8;
    dbvar->valI8.QuadPart =DBVARIANT::value_i8_type(pVariant->pllVal?*pVariant->pllVal:0i64);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UI1:
   {
    dbvar->wType   =DBTYPE_UI1;
    dbvar->valUI1  =pVariant->bVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UI1|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_UI1;
    dbvar->valUI1  =DBVARIANT::value_ui1_type(pVariant->pbVal?*pVariant->pbVal:0);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UI2:
   {
    dbvar->wType   =DBTYPE_UI2;
    dbvar->valUI2  =pVariant->uiVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UI2|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_UI2;
    dbvar->valUI2  =DBVARIANT::value_ui2_type(pVariant->puiVal?*pVariant->puiVal:0);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UI4:
   {
    dbvar->wType   =DBTYPE_UI4;
    dbvar->valUI4  =pVariant->ulVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UI4|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_UI4;
    dbvar->valUI4  =DBVARIANT::value_ui4_type(pVariant->pulVal?*pVariant->pulVal:0);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UI8:
   {
    dbvar->wType           =DBTYPE_UI8;
    dbvar->valUI8.QuadPart =pVariant->ullVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UI8|VT_BYREF:
   {
    dbvar->wType           =DBTYPE_UI8;
    dbvar->valUI8.QuadPart =DBVARIANT::value_ui8_type(pVariant->pullVal?*pVariant->pullVal:0ui64);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_INT:
   {
    dbvar->wType   =DBTYPE_I4;
    dbvar->valI4   =V_INT(pVariant);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_INT|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_I4;
    dbvar->valI4   =DBVARIANT::value_i4_type(V_INTREF(pVariant)?*V_INTREF(pVariant):((int)0));

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UINT:
   {
    dbvar->wType   =DBTYPE_UI4;
    dbvar->valUI4  =V_UINT(pVariant);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UINT|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_UI4;
    dbvar->valUI4  =DBVARIANT::value_ui4_type(V_UINTREF(pVariant)?*V_UINTREF(pVariant):((unsigned int)0));

    break;
   }

  //-----------------------------------------------------------------------
  case VT_R4:
   {
    dbvar->wType   =DBTYPE_R4;
    dbvar->valR4   =pVariant->fltVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_R4|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_R4;
    dbvar->valR4   =DBVARIANT::value_r4_type(pVariant->pfltVal?*pVariant->pfltVal:0.0F);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_R8:
   {
    dbvar->wType   =DBTYPE_R8;
    dbvar->valR8   =pVariant->dblVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_R8|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_R8;
    dbvar->valR8   =DBVARIANT::value_r8_type(pVariant->pdblVal?*pVariant->pdblVal:0.0);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_CY:
   {
    dbvar->wType   =DBTYPE_CY;
    dbvar->valCY   =pVariant->cyVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_CY|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_CY;
    dbvar->valCY   =pVariant->pcyVal?*pVariant->pcyVal:__null_cy__;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_DECIMAL:
   {
    dbvar->wType   =DBTYPE_DECIMAL;
    dbvar->decVal  =pVariant->decVal;

    dbvar->decVal.wReserved=0;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_DECIMAL|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_DECIMAL;
    dbvar->decVal  =pVariant->pdecVal?*pVariant->pdecVal:__null_decimal__;

    dbvar->decVal.wReserved=0;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_BOOL:
   {
    dbvar->wType   =DBTYPE_BOOL;
    dbvar->boolVal =pVariant->boolVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_BOOL|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_BOOL;
    dbvar->boolVal =VARIANT_BOOL(pVariant->pboolVal?*pVariant->pboolVal:0);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_BSTR:
   {
    dbvar->wType   =DBTYPE_BSTR;
    dbvar->bstrVal =pVariant->bstrVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_BSTR|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_BSTR;
    dbvar->bstrVal =pVariant->pbstrVal?*pVariant->pbstrVal:NULL;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_DATE:
   {
    dbvar->wType   =DBTYPE_DATE;
    dbvar->dateVal =pVariant->date;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_DATE|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_DATE;
    dbvar->dateVal =DBVARIANT::value_date_type(pVariant->pdate?*pVariant->pdate:0.0);

    break;
   }

  //-----------------------------------------------------------------------
  case VT_ERROR:
   {
    dbvar->wType   =DBTYPE_ERROR;
    dbvar->scodeVal=pVariant->scode;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_ERROR|VT_BYREF:
   {
    dbvar->wType   =DBTYPE_ERROR;
    dbvar->scodeVal=pVariant->pscode?*pVariant->pscode:0;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UNKNOWN:
   {
    dbvar->wType      =DBTYPE_IUNKNOWN;
    dbvar->unkVal.ptr =pVariant->punkVal;
    dbvar->unkVal.iid =IID_IUnknown;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_UNKNOWN|VT_BYREF:
   {
    dbvar->wType      =DBTYPE_IUNKNOWN;
    dbvar->unkVal.ptr =(pVariant->ppunkVal?(*pVariant->ppunkVal):NULL);
    dbvar->unkVal.iid =IID_IUnknown;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_DISPATCH:
   {
    dbvar->wType       =DBTYPE_IDISPATCH;
    dbvar->dispVal.ptr =pVariant->pdispVal;

    break;
   }

  //-----------------------------------------------------------------------
  case VT_DISPATCH|VT_BYREF:
   {
    dbvar->wType       =DBTYPE_IDISPATCH;
    dbvar->dispVal.ptr =(pVariant->ppdispVal?(*pVariant->ppdispVal):NULL);

    break;
   }

  //-----------------------------------------------------------------------
  default:
   {
    return DB_E_CANTCONVERTVALUE;
   }
 }//switch

 dbvar->SetDataStatus__OK();

 return S_OK;
}//UnpackVariantToDBVariant

////////////////////////////////////////////////////////////////////////////////

//1 Check format of Array
//2 find information of type of array element
//3 calculate Offset of bytes of data in Array
//
//returns:
//  E_FAIL       - Array is not array variable
//  E_UNEXPECTED - bad format of Array
//  E_INVALIDARG - error value in cPoints/pPoints
//  S_OK         - all is OK
HRESULT DBVariant_MakeArrayOffset(const DBVARIANT&              Array,
                                  size_t                  const cPoints,
                                  const LONG*             const pPoints,
                                  DBBYTEOFFSET*           const pcbOffset,
                                  DBLENGTH*               const pcbElementSize,
                                  DBVARIANT::LPCTYPEINFO* const ppTypeInfo)
{
 assert(pcbOffset);
 assert(pcbElementSize);
 assert_msg((Array.wType&DBTYPE_ARRAY)!=0,"wType==0x"<<std::hex<<Array.wType);
 assert(Array.arrayVal2.ptr!=NULL);

 if(ppTypeInfo!=NULL)
  (*ppTypeInfo)=NULL;

 if((Array.wType&DBTYPE_ARRAY)==0 || Array.arrayVal2.ptr==NULL)
  return E_FAIL;

 DBTYPE wElementType=DBTYPE(Array.wType&~DBTYPE_ARRAY);//type of array element

 assert((wElementType&DBTYPE_BYREF)  ==0);
 assert((wElementType&DBTYPE_VECTOR) ==0);
 assert(wElementType!=DBTYPE_EMPTY);
 assert(wElementType!=DBTYPE_NULL);

 if((wElementType&DBTYPE_BYREF)==DBTYPE_BYREF ||
    (wElementType&DBTYPE_VECTOR)==DBTYPE_VECTOR ||
    (wElementType==DBTYPE_EMPTY) ||
    (wElementType==DBTYPE_NULL))
 {
  return E_UNEXPECTED;
 }

 (*pcbElementSize)=::SafeArrayGetElemsize(Array.arrayVal2.ptr);

 DBVARIANT::LPCTYPEINFO const pTypeInfo=DBVARIANT::GetInfo(wElementType);

 assert_msg(pTypeInfo!=NULL,"wElementType==0x"<<std::hex<<wElementType);

 if(pTypeInfo==NULL)
  return E_UNEXPECTED;

 if(pTypeInfo->FixedLen())
 {
  assert_msg(pTypeInfo->Size==(*pcbElementSize),
             "source.wType==0x"<<std::hex<<Array.wType<<"\n"
             "cbElementSize=="<<std::dec<<(*pcbElementSize));

  if(pTypeInfo->Size!=(*pcbElementSize))
   return E_UNEXPECTED;
 }//if

 //create offset and check bounds ----------------------------------------
 {
  const UINT cSafeArrayDim=::SafeArrayGetDim(Array.arrayVal2.ptr);

  assert(cPoints==cSafeArrayDim);

  if(cPoints!=cSafeArrayDim)
   return E_INVALIDARG;
 }//local

 (*pcbOffset)=0;

 size_t m=1;

 LONG  lbound;
 LONG  ubound;

 HRESULT hr;

 for(UINT x=0;x!=cPoints;++x)
 {
  assert_s(sizeof(x)==sizeof(::SafeArrayGetDim(Array.arrayVal2.ptr)));

  hr=::SafeArrayGetLBound(Array.arrayVal2.ptr,x+1,&lbound);

  assert_msg(hr==S_OK,"hr==0x"<<std::hex<<hr);

  if(FAILED(hr))
   return hr;

  hr=::SafeArrayGetUBound(Array.arrayVal2.ptr,x+1,&ubound);

  assert_msg(hr==S_OK,"hr==0x"<<std::hex<<hr);

  if(FAILED(hr))
   return hr;

  assert_msg(lbound<=ubound,
             "lbound=="<<lbound<<"\n"
             "ubound=="<<ubound);

  if(lbound>ubound)
   return E_UNEXPECTED;

  assert_msg(pPoints[x]>=lbound && pPoints[x]<=ubound,
             "pPoints["<<x<<"]=="<<pPoints[x]<<"\n"
             "lbound=="<<lbound<<"\n"
             "ubound=="<<ubound);

  if(pPoints[x]<lbound || pPoints[x]>ubound)
   return E_INVALIDARG;

  //calculate element offset
  (*pcbOffset)+=m*(pPoints[x]-lbound);

  m=m*(ubound-lbound+1);
 }//for x

 (*pcbOffset)=(*pcbOffset)*(*pcbElementSize);

 if(ppTypeInfo)
  (*ppTypeInfo)=pTypeInfo;

 return S_OK;
}//DBVariant_MakeArrayOffset

////////////////////////////////////////////////////////////////////////////////

HRESULT DBVariant_CreateArray(DBTYPE                const wElementType,
                              size_t                      ElementSize,
                              size_t                const cDim,
                              const SAFEARRAYBOUND* const rgsaBound,
                              SAFEARRAY**           const ppArray)
{
 assert(ppArray!=NULL);
 assert(cDim==0 || rgsaBound!=NULL);

 CHECK_READ_TYPED_PTR(rgsaBound,cDim);

 assert((wElementType&DBTYPE_BYREF)==0);
 assert((wElementType&DBTYPE_ARRAY)==0);
 assert((wElementType&DBTYPE_VECTOR)==0);

 (*ppArray)=NULL;

 if(wElementType&(DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_VECTOR))
  return E_FAIL;

 DBVARIANT::LPCTYPEINFO const lpTypeInfo=DBVARIANT::GetInfo(wElementType);

 assert(lpTypeInfo!=0);

 if(lpTypeInfo==NULL)
  return E_FAIL;

 if(cDim==0)//возвращаем NULL
  return S_OK;

 assert_hint(cDim>0);

 typedef USHORT safearray_cdims_type;

 assert_s(sizeof(safearray_cdims_type)==_MEMBER_SIZE_(SAFEARRAY,cDims));
 assert_s(sizeof(safearray_cdims_type)<=sizeof(size_t));

 if(cDim>size_t(structure::t_numeric_limits<safearray_cdims_type>::max_value()))
  return E_INVALIDARG;

 ole_lib::TBaseSafeArray sa;

 VARTYPE _vt(0);

 switch(wElementType)
 {
  case DBTYPE_NULL:
  case DBTYPE_EMPTY:
   return E_INVALIDARG;

  //At Win9x can be problem with UI2, UI4, I1
  case DBTYPE_UI1:
  {
   _vt=VT_UI1;
   break;
  }

  //case        DBTYPE_UI2:_vt=VT_UI2       ;           break;
  //case        DBTYPE_UI4:_vt=VT_UI4       ;           break;
  //case         DBTYPE_I1:_vt=VT_I1        ;           break;

  case DBTYPE_I2:
  {
   _vt=VT_I2;
   break;
  }

  case DBTYPE_I4:
  {
  _vt=VT_I4;
  break;
  }

  case DBTYPE_R4:
  {
   _vt=VT_R4;
   break;
  }

  case DBTYPE_R8:
  {
   _vt=VT_R8;
   break;
  }

  case DBTYPE_CY:
  {
   _vt=VT_CY;
   break;
  }

  case DBTYPE_DECIMAL:
  {
   _vt=VT_DECIMAL;
   break;
  }

  case DBTYPE_BOOL:
  {
   _vt=VT_BOOL;
   break;
  }

  case DBTYPE_ERROR:
  {
   _vt=VT_ERROR;
   break;
  }

  case DBTYPE_IUNKNOWN:
  {
   _vt=VT_UNKNOWN;
   break;
  }

  case DBTYPE_IDISPATCH:
  {
   _vt=VT_DISPATCH;
   break;
  }

  case DBTYPE_DATE:
  {
   _vt=VT_DATE;
   break;
  }

  case DBTYPE_BSTR:
  {
   _vt=VT_BSTR;
   break;
  }

  case DBTYPE_VARIANT:
  {
   _vt=VT_VARIANT;
   break;
  }

  default://определ€ем размер элемента массива
  {
   switch(wElementType)
   {
    case DBTYPE_BYTES:
    {
     ElementSize*=sizeof(BYTE);
     break;
    }//case

    case DBTYPE_STR:
    {
     ElementSize*=sizeof(char);
     break;
    }

    case DBTYPE_WSTR:
    {
     ElementSize*=sizeof(wchar_t);
     break;
    }

    default:
    {
     ElementSize=lpTypeInfo->Size;
     break;
    }
   }//switch

   if(ElementSize==0)
    return E_INVALIDARG;

   if(ElementSize>structure::t_numeric_limits<ULONG>::max_value())
    return E_INVALIDARG;

   //создаем массив, исход€ из размера элемента
   HRESULT hr;

   if((hr=::SafeArrayAllocDescriptor(static_cast<safearray_cdims_type>(cDim),&sa.ref_sa()))!=S_OK)
    return hr;

   assert(sa.sa()!=NULL);

   assert_s(sizeof(sa.sa()->cbElements)==sizeof(ULONG));

   sa.sa()->cbElements=static_cast<ULONG>(ElementSize);

   //заполн€ем размерности массива
   for(size_t i=0;i!=cDim;++i)
    sa.sa()->rgsabound[cDim-i-1]=rgsaBound[i];

   //выдел€ем пам€ть под данные
   if(FAILED(hr=::SafeArrayAllocData(sa)))
   {
    _VERIFY_EQ(::SafeArrayDestroyDescriptor(sa.Release()),S_OK);

    return hr;
   }

   break;
  }//default
 }//switch

 if(sa.sa()==NULL)
 {
  sa.ref_sa()=::SafeArrayCreate(_vt,
                                static_cast<safearray_cdims_type>(cDim),
                                const_cast<SAFEARRAYBOUND*>(rgsaBound));
  if(sa.sa()==NULL)
   return E_OUTOFMEMORY;
 }//if

 assert(sa.sa()->cDims==static_cast<safearray_cdims_type>(cDim));

 //init array data
 {
  assert_hint(cDim>0);

  size_t cElements=1;

  for(size_t i=0;i!=cDim;++i)
   cElements*=rgsaBound[i].cElements;

  const ole_lib::TSafeArrayAccessor sa_accessor(sa,/*throw_error*/false);

  if(!sa_accessor)
   return E_FAIL;

  assert(sa.sa()->cbElements!=0);

  CHECK_WRITE_PTR(sa_accessor.Data(),sa.sa()->cbElements*cElements);

  std::memset(sa_accessor.Data(),0,sa.sa()->cbElements*cElements);
 }//local

 (*ppArray)=sa.Release();

 return S_OK;
}//DBVariant_CreateArray

////////////////////////////////////////////////////////////////////////////////
//Access Array Element - set element

//E_FAIL                   - dest is not array
//E_UNEXPECTED             - bad format of dest
//E_OUTOFMEMORY            - out of memory
//DB_E_CANTCONVERTVALUE    - error of data conversion
//DISP_E_OVERFLOW          - error of data overflow
//DB_E_DATAOVERFLOW        - error of data overflow

//return in Status
// DBSTATUS_S_TRUNCATED
//

HRESULT DBVariant_SetArrayElement(DBVARIANT&        ArrayVariant,
                                  size_t      const cPoints,
                                  const LONG* const pPoints,
                                  const DBVARIANT&  Value,
                                  DBSTATUS*   const pStatus)
{
 assert((ArrayVariant.wType&DBTYPE_ARRAY)==DBTYPE_ARRAY);

 if((ArrayVariant.wType&DBTYPE_ARRAY)!=DBTYPE_ARRAY)
  return E_FAIL;

 DBBYTEOFFSET Offset=0;
 DBLENGTH     cbElementSize=0;

 DBSTATUS     Local_Status;

 DBSTATUS&    Binding_Status=(pStatus?(*pStatus):Local_Status);

 DBVARIANT::LPCTYPEINFO pTypeInfo=NULL;

 //------------
 Binding_Status=DBSTATUS_E_CANTCREATE;

 //------------
 {
  const HRESULT make_hr=DBVariant_MakeArrayOffset(ArrayVariant,
                                                  cPoints,
                                                  pPoints,
                                                  &Offset,
                                                  &cbElementSize,
                                                  &pTypeInfo);

  if(FAILED(make_hr))
  {
   Binding_Status=MapDBErrorToDBStatus(make_hr);

   return make_hr;
  }//if

  assert(make_hr==S_OK);
 }//local

 assert(pTypeInfo!=NULL);
 assert((pTypeInfo->Type&DBTYPE_ARRAY)==0);

 if(pTypeInfo->pTypeService==NULL)
  return DB_E_NOTSUPPORTED;

 //Lock the target SAFEARRAY
 const ole_lib::TSafeArrayAccessor sa_accessor(ArrayVariant.arrayVal2.ptr,/*throw_error*/false);

 if(!sa_accessor)
  return E_FAIL;

 void* const pData=reinterpret_cast<BYTE*>(sa_accessor.Data())+Offset;

 CHECK_WRITE_PTR(pData,cbElementSize);

 //Install element value
 Binding_Status=DBSTATUS_S_OK;

 TDBVariant_TypeCvtContext_Std ConvCtx;

 return pTypeInfo->pTypeService->set_element(&ConvCtx,
                                             Value,
                                             IID_IUnknown,
                                             cbElementSize,
                                             pData,
                                             &Binding_Status);
}//DBVariant_SetArrayElement

//------------------------------------------------------------------------
HRESULT DBVariant_SetArrayElement_1(DBVARIANT&       ArrayVariant,
                                    LONG       const pt1,
                                    const DBVARIANT& Value,
                                    DBSTATUS*  const pStatus)
{
 return DBVariant_SetArrayElement(ArrayVariant,
                                  1,
                                  &pt1,
                                  Value,
                                  pStatus);
}//DBVariant_SetArrayElement_1

////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT::TTypeService

DBVARIANT::length_type
 DBVARIANT::TTypeService::get_length2(const DBVARIANT& dbvar)const
{
 const char c_bugcheck_src[]
  ="DBVARIANT::TTypeService::get_length2";

 switch(DBSTATUS const _s=dbvar.GetDataStatus())
 {
  case DBSTATUS_S_OK:
   return this->internal__get_length__ok(dbvar);

  case DBSTATUS_S_ISNULL:
   return 0;

  default:
  {
   this->helper__throw_bug_check__unexpected_data_status
    (c_bugcheck_src,
     "#001",
     _s); //throw!
  }//default
 }//switch _s
}//get_length2

//------------------------------------------------------------------------
void DBVARIANT::TTypeService::get_size2(const DBVARIANT& dbvar,
                                        length_type&     cbSize,
                                        length_type&     cbMemSize,
                                        length_type&     cbMinSize)const
{
 const char c_bugcheck_src[]
  ="DBVARIANT::TTypeService::get_data2";

 switch(DBSTATUS const _s=dbvar.GetDataStatus())
 {
  case DBSTATUS_S_OK:
  {
   return this->internal__get_size__ok
           (dbvar,
            cbSize,
            cbMemSize,
            cbMinSize);
  }//case OK

  case DBSTATUS_S_ISNULL:
  {
   cbSize=0;
   cbMemSize=0;
   cbMinSize=0;

   return;
  }//case ISNULL, DEFAULT

  default:
  {
   this->helper__throw_bug_check__unexpected_data_status
    (c_bugcheck_src,
     "#001",
     _s); //throw!
  }//default
 }//switch _s
}//get_size2

//------------------------------------------------------------------------
HRESULT DBVARIANT::TTypeService::get_data2(const DBVARIANT&  dbvar,
                                           const DBBINDING&  Binding,
                                           length_type const cbMemSize,
                                           status_type&      Binding_Status,
                                           length_type&      Binding_Length,
                                           void*       const pBuffer)const
{
 const char c_bugcheck_src[]
  ="DBVARIANT::TTypeService::get_data2";

 switch(DBSTATUS const _s=dbvar.GetDataStatus())
 {
  case DBSTATUS_S_OK:
  {
   return this->internal__get_data__ok
          (dbvar,
           Binding,
           cbMemSize,
           Binding_Status,
           Binding_Length,
           pBuffer);
  }//case OK

  case DBSTATUS_S_ISNULL:
  {
   Binding_Status=_s;
   Binding_Length=0;

   return S_OK;
  }//case ISNULL, DEFAULT

  default:
  {
   this->helper__throw_bug_check__unexpected_data_status
    (c_bugcheck_src,
     "#001",
     _s); //throw!
  }//default
 }//switch _s
}//get_data2

//helper methods ---------------------------------------------------------
void DBVARIANT::TTypeService::helper__throw_bug_check__unexpected_data_status
                                           (const char* const place,
                                            const char* const point,
                                            DBSTATUS    const status)const
{
 assert(place);
 assert(point);

 assert_msg(false,"status: "<<status<<". dbtype: "<<this->get_type());

 structure::str_formatter
  fmsg("[BUG CHECK] Unexpected value status: %4. Service of type [%3]. Check point [%1][%2].");

 fmsg<<place
     <<point
     <<DBVARIANT::GetTypeName(this->get_type(),0)
     <<oledb_lib::GetDBStatusName(status);

 throw std::runtime_error(fmsg.str());
}//helper__throw_bug_check__unexpected_data_status

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
