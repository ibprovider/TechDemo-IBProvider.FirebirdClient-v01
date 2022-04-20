////////////////////////////////////////////////////////////////////////////////
//inline implementation of classes from <oledb_variant.h>
//                                         Kovalenko Dmitry. 3 july, 2002 year

#ifndef _oledb_variant_INL_
#define _oledb_variant_INL_

#include <ole_lib/ole_auto/ole_auto_safe_array.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT::TTypeConverterMap

inline DBVARIANT::TTypeConverterMap::TTypeConverterMap
                                  (const LPCTYPECONVERTER* const pSimpleCvts,
                                   size_t                  const cSimpleCvts,
                                   const LPCTYPECONVERTER* const pArrayCvts,
                                   size_t                  const cArrayCvts)
 :m_pSimpleCvts(pSimpleCvts)
 ,m_cSimpleCvts(cSimpleCvts)
 ,m_pArrayCvts(pArrayCvts)
 ,m_cArrayCvts(cArrayCvts)
{
 CHECK_READ_PTR(m_pSimpleCvts,m_cSimpleCvts*sizeof(m_pSimpleCvts));

 CHECK_READ_PTR(m_pArrayCvts,m_cArrayCvts*sizeof(m_pArrayCvts));
}

//------------------------------------------------------------------------
inline DBVARIANT::LPCTYPECONVERTER
 DBVARIANT::TTypeConverterMap::get_convertor(DBTYPE TargetType)const
{
 TargetType=OLEDB_EXTRACT_DBTYPE(TargetType);

 if((TargetType&DBTYPE_ARRAY)==DBTYPE_ARRAY)
 {
  return self_type::get_converter
          (DBTYPE(TargetType&DBTYPE(~DBTYPE_ARRAY)),
           m_pArrayCvts,
           m_cArrayCvts);
 }//if

 return self_type::get_converter
        (TargetType,
         m_pSimpleCvts,
         m_cSimpleCvts);
}//get_convertor

//------------------------------------------------------------------------
inline DBVARIANT::LPCTYPECONVERTER
 DBVARIANT::TTypeConverterMap::get_converter(DBTYPE                  TargetType,
                                             const LPCTYPECONVERTER* pCvts,
                                             size_t                  cCvts)
{
 if(UINT(TargetType)<cCvts)
  return pCvts[UINT(TargetType)];

 return NULL;
}//get_converter

////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT::TTypeInfo

inline bool DBVARIANT::TTypeInfo::VariableLen()const
{
 return (this->Flags&DBVARIANT::DBTypeFlag_VariableLen)!=0;
}//VariableLen

//------------------------------------------------------------------------
inline bool DBVARIANT::TTypeInfo::FixedLen()const
{
 return !this->VariableLen();
}//FixedLen

//------------------------------------------------------------------------
inline bool DBVARIANT::TTypeInfo::FixedPrecisionDigit()const
{
 bool const res=((this->Flags&DBTypeFlag_IsFixedPrecisionDigit)!=0);

 assert_msg(!res || this->FixedLen(),"Type=="<<structure::tstr_to_str(this->Name));

 return res;
}//FixedPrecisionDigit

//------------------------------------------------------------------------
inline bool DBVARIANT::TTypeInfo::IsDigit()const
{
 bool const res=((this->Flags&DBTypeFlag_IsDigit)!=0);

 return res;
}//IsDigit

//------------------------------------------------------------------------
inline bool DBVARIANT::TTypeInfo::ICR_Precision()const
{
 bool const res=((this->Flags&DBTypeFlag_ICR_Precision)!=0);

 return res;
}//ICR_Precision

//------------------------------------------------------------------------
inline bool DBVARIANT::TTypeInfo::ICR_Scale()const
{
 bool const res=((this->Flags&DBTypeFlag_ICR_Scale)!=0);

 return res;
}//ICR_Scale

//------------------------------------------------------------------------
inline bool DBVARIANT::TTypeInfo::ICR_DateTimePrecision()const
{
 bool const res=((this->Flags&DBTypeFlag_ICR_DateTimePrecision)!=0);

 return res;
}//ICR_DateTimePrecision

////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT::TParamInfo

inline bool DBVARIANT::TParamInfo::VariableLen()const
{
 return this->Flags&DBVARIANT::DBTypeFlag_VariableLen;
}

//------------------------------------------------------------------------
inline bool DBVARIANT::TParamInfo::FixedLen()const
{
 return !this->VariableLen();
}

//------------------------------------------------------------------------
inline bool DBVARIANT::TParamInfo::IsLong()const
{
 return (this->dwColumnFlags&DBCOLUMNFLAGS_ISLONG)!=0;
}

//------------------------------------------------------------------------
inline void DBVARIANT::TParamInfo::GetParameterFlags(DBPARAMFLAGS& _Flags) const
{
 if(this->IsLong())
  _Flags|=DBPARAMFLAGS_ISLONG;
 else
  _Flags&=~DBPARAMFLAGS_ISLONG;
}//GetParameterFlags

//------------------------------------------------------------------------
inline bool DBVARIANT::TParamInfo::operator == (AdoDataTypeEnum const _adType)const
{
 return this->adType==_adType;
}//operator == _adType

//------------------------------------------------------------------------
inline bool DBVARIANT::TParamInfo::operator == (const t_oledb_char* const _TypeName) const
{
 return _TypeName!=NULL && _OLEDB_LIB_lstrcmpi(_TypeName,this->Name)==0;
}//operator == _TypeName

////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT - static member

inline DBVARIANT::LPCTYPESERVICE DBVARIANT::GetTypeService(DBTYPE const _wType)
{
 if(LPCTYPEINFO const pInfo=self_type::GetInfo(_wType))
  return pInfo->pTypeService;

 return nullptr;
}//GetTypeService

////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT - class member

inline void DBVARIANT::Init(DBTYPE const _wType)
{
 memset(this,0,sizeof(*this));

 this->wType=_wType;
}//Init

//------------------------------------------------------------------------
inline DBVARIANT::DBVARIANT()
{
 this->Init();
}//DBVARIANT

//------------------------------------------------------------------------
inline DBVARIANT::~DBVARIANT()
{
 this->Init();
}//~DBVARIANT

//------------------------------------------------------------------------
inline void DBVARIANT::SetDataStatus(DBSTATUS const s)
{
 this->dwDataStatus=s;
}//SetDataStatus

//------------------------------------------------------------------------
inline void DBVARIANT::SetDataStatus__OK()
{
 this->SetDataStatus(DBSTATUS_S_OK);
}//SetDataStatus__OK

//------------------------------------------------------------------------
inline void DBVARIANT::SetDataStatus__IsNull()
{
 this->SetDataStatus(DBSTATUS_S_ISNULL);
}//SetDataStatus__IsNull

//------------------------------------------------------------------------
inline void DBVARIANT::SetDataStatus__Default()
{
 this->SetDataStatus(DBSTATUS_S_DEFAULT);
}//SetDataStatus__Default

//------------------------------------------------------------------------
inline DBSTATUS DBVARIANT::GetDataStatus()const
{
 return this->tagDBVARIANT::dwDataStatus;
}//GetDataStatus

//------------------------------------------------------------------------
inline bool DBVARIANT::TestDataStatus__IsOK()const
{
 return this->GetDataStatus()==DBSTATUS_S_OK;
}//TestDataStatus__IsOK

//------------------------------------------------------------------------
inline bool DBVARIANT::TestDataStatus__IsTruncated()const
{
 return this->GetDataStatus()==DBSTATUS_S_TRUNCATED;
}//TestDataStatus__IsTruncated

//------------------------------------------------------------------------
#ifndef NDEBUG

inline bool DBVARIANT::TestDataStatus__IsOK_or_IsTruncated()const
{
 if(this->TestDataStatus__IsOK())
  return true;

 if(this->TestDataStatus__IsTruncated())
  return true;

 return false;
}//TestDataStatus__IsOK_or_IsTruncated

#endif

//------------------------------------------------------------------------
#ifndef NDEBUG

inline bool DBVARIANT::TestDataStatus__IsOK_or_IsNull()const
{
 if(this->TestDataStatus__IsOK())
  return true;

 if(this->TestDataStatus__IsNull())
  return true;

 return false;
}//TestDataStatus__IsOK_or_IsNull

#endif

//------------------------------------------------------------------------
inline bool DBVARIANT::TestDataStatus__IsNull()const
{
 return this->GetDataStatus()==DBSTATUS_S_ISNULL;
}//TestDataStatus__IsNull

//------------------------------------------------------------------------
inline bool DBVARIANT::TestDataStatus__IsDefault()const
{
 return this->GetDataStatus()==DBSTATUS_S_DEFAULT;
}//TestDataStatus__IsNull

//------------------------------------------------------------------------
inline bool DBVARIANT::IsEmpty()const
{
 return this->wType==DBTYPE_EMPTY;
}

//------------------------------------------------------------------------
inline bool DBVARIANT::IsArray() const
{
 return (this->wType&DBTYPE_ARRAY)!=0;
}

//------------------------------------------------------------------------
inline DBVARIANT::LPCTYPEINFO DBVARIANT::GetInfo()const
{
 return self_type::GetInfo(this->wType);
}

//------------------------------------------------------------------------
inline DBVARIANT::LPCTYPESERVICE DBVARIANT::GetTypeService()const
{
 return self_type::GetTypeService(this->wType);
}

//------------------------------------------------------------------------
inline t_oledb_string DBVARIANT::GetTypeName()const
{
 return self_type::GetTypeName(this->wType,0);
}

////////////////////////////////////////////////////////////////////////////////

inline DBVARIANT::LPCTYPECONVERTER
 DBVARIANT::GetTypeConverter(DBTYPE const wFromType,
                             DBTYPE const wToType)
{
 LPCTYPESERVICE const pService(self_type::GetTypeService(wFromType));

 return pService?pService->get_convertor(wToType):NULL;
}//GetTypeConverter

////////////////////////////////////////////////////////////////////////////////

inline DBVARIANT::TPrinter print(const DBVARIANT& dbvar)
{
 return DBVARIANT::TPrinter(dbvar);
}//print

////////////////////////////////////////////////////////////////////////////////

inline std::ostream& operator << (std::ostream& os,const DBVARIANT::TPrinter& printer)
{
 return os<<printer.m_dbvar.get_print_str();
}//operator << str

//------------------------------------------------------------------------
inline std::wostream& operator << (std::wostream& os,const DBVARIANT::TPrinter& printer)
{
 return os<<printer.m_dbvar.get_print_wstr();
}//operator << wstr

/////////////////////////////////////////////////////////////////////////////////
//Access Array Element - retrive element

//return:
// E_INVALIDARG   - error value of cPoints/pPoints
// DB_E_BADTYPE   - source is not array
// DB_E_BADVALUES - source is NULL or arrayVal==NULL
// E_UNEXPECTED   - bad format of source?
// S_OK           - all is OK

template<class DestVariant>
HRESULT DBVariant_GetArrayElement(const DBVARIANT&   source,
                                  size_t       const cPoints,
                                  const LONG*  const pPoints,
                                  DestVariant&       dest)
{
 assert(cPoints==0 || pPoints!=NULL);

 CHECK_READ_TYPED_PTR(pPoints,cPoints);

 if(cPoints==0 || pPoints==NULL)
  return E_INVALIDARG;

 assert(source.wType&DBTYPE_ARRAY);

 if((source.wType&DBTYPE_ARRAY)==0)
  return DB_E_BADTYPE;

 if(source.TestDataStatus__IsNull())
  return DB_E_BADVALUES;

 if(!source.TestDataStatus__IsOK())
  return DB_E_BADSTATUSVALUE;

 if(!source.arrayVal2.ptr)
  return DB_E_BADVALUES;

 assert(source.arrayVal2.ptr);

 //retrive element size --------------------------------------------------
 DBBYTEOFFSET cbElementOffset=0;
 DBLENGTH     cbLength=0;

 {
  const HRESULT
   make_hr
    =DBVariant_MakeArrayOffset
      (source,
       cPoints,
       pPoints,
       &cbElementOffset,
       &cbLength,
       /*ppTypeInfo*/nullptr);

  if(FAILED(make_hr))
   return make_hr;

  assert(make_hr==S_OK);
 }//local

 const ole_lib::TSafeArrayAccessor
  sa_accessor
   (source.arrayVal2.ptr,
    /*throw_error*/false);

 if(!sa_accessor)
  return E_FAIL;

 const void* const
  pElementData
   =reinterpret_cast<const char*>(sa_accessor.Data())+cbElementOffset;

 DBVARIANT::LPCTYPESERVICE const
  pService
   =DBVARIANT::GetTypeService(DBTYPE(source.wType&DBTYPE(~DBTYPE_ARRAY)));

 if(pService==NULL)
  return DB_E_NOTSUPPORTED;

 //--------------------------
 DBVARIANT tmpElementData;

 {
  const HRESULT
   get_element_hr
    =pService->get_element
      (&tmpElementData,
       source.arrayVal2.element_iid,
       cbLength,
       pElementData);

  if(FAILED(get_element_hr))
   return get_element_hr;

  assert(get_element_hr==S_OK); 
 }//local

 dest=tmpElementData;

 //--------------------------
 return S_OK;
}//DBVariant_GetArrayElement

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
