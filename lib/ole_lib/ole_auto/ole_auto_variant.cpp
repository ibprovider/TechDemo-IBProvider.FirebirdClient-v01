////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/ole_auto/ole_auto_variant.h>
#include <ole_lib/ole_ptr.h>

#include <sstream>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////

static const char* const g_err_msg__fail_copy_VARIANT=
 "[TVariant] Copying is failed.";

static const char* const g_err_msg__fail_create_BSTR_from_ANSI=
 "[TVariant] Creating BSTR from ANSI string is failed.";

static const char* const g_err_msg__fail_create_BSTR_from_UNICODE=
 "[TVariant] Creating BSTR from UNICODE string is failed.";

////////////////////////////////////////////////////////////////////////////////
//class TVariant

const VARIANT TVariant::empty_variant
 ={};

const VARIANT TVariant::null_variant
 ={VT_NULL,0};

const VARIANT TVariant::missing_arg_variant
 =TVariant::build_variant_with_scode(DISP_E_PARAMNOTFOUND);

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
TVariant::TVariant(self_type&& x)
{
 assert(this!=&x);

 (*reinterpret_cast<VARIANT*>(this))=x;

 x.vt=VT_EMPTY;
}
#endif

//------------------------------------------------------------------------
TVariant::TVariant(const self_type& x)
{
 HRESULT hr;

 if(FAILED(hr=ole_lib::Variant_Copy(this,&x)))
  t_base_ole_error::throw_error(hr,g_err_msg__fail_copy_VARIANT);
}//TVariant - copy

//------------------------------------------------------------------------
TVariant::TVariant(const VARIANT& x)
{
 HRESULT hr;

 if(FAILED(hr=ole_lib::Variant_Copy(this,&x)))
  t_base_ole_error::throw_error(hr,g_err_msg__fail_copy_VARIANT);
}//TVariant - copy

//------------------------------------------------------------------------
TVariant::TVariant(const char* const s)
{
 this->SetStr_v2(s);
}//TVariant - str

//------------------------------------------------------------------------
#if 0 // [2020-04-04] Bye. Use str_box-version.

TVariant::TVariant(const char* const s,size_t const n)
{
 assert(!structure::is_negative_one(n));

 this->SetStr_v2(structure::make_str_box(s,n));
}//TVariant - str

#endif

//------------------------------------------------------------------------
TVariant::TVariant(const std::string& data)
{
 this->SetStr_v2(data);
}//TVariant - str

//------------------------------------------------------------------------
TVariant::TVariant(structure::str_parameter const data)
{
 this->SetStr_v2(structure::make_str_box(data.c_str(),data.length()));
}//TVariant - str_parameter

//------------------------------------------------------------------------
TVariant::TVariant(const structure::t_const_str_box& data)
{
 this->SetStr_v2(data);
}//TVariant - str_box

//------------------------------------------------------------------------
TVariant::TVariant(const wchar_t* const s)
{
 this->SetWStr_v2(s); //throw
}//TVariant - wstr

//------------------------------------------------------------------------
#if 0 // [2020-04-04] Bye. Use str_box-version.

TVariant::TVariant(const wchar_t* const s,size_t const n)
{
 assert(!structure::is_negative_one(n));

 this->SetWStr_v2(structure::make_str_box(s,n)); //throw
}//TVariant - wstr

#endif

//------------------------------------------------------------------------
TVariant::TVariant(const std::wstring& data)
{
 this->SetWStr_v2(data); //throw
}//TVariant - wstr

//------------------------------------------------------------------------
TVariant::TVariant(structure::wstr_parameter const data)
{
 this->SetWStr_v2(structure::make_str_box(data.c_str(),data.length())); //throw
}//TVariant - wstr_parameter

//------------------------------------------------------------------------
TVariant::TVariant(const structure::t_const_wstr_box& data)
{
 this->SetWStr_v2(data); //throw
}//TVariant - wstr_box

//------------------------------------------------------------------------
TVariant::TVariant(const value_str_n_type& x)//throw
{
 if(x.null())
 {
  this->vt=VT_NULL;
 }
 else
 {
  this->SetStr_v2(x.value());
 }//else
}//TVariant

//------------------------------------------------------------------------
TVariant::TVariant(const value_wstr_n_type& x)//throw
{
 if(x.null())
 {
  this->vt=VT_NULL;
 }
 else
 {
  this->SetWStr_v2(x.value()); //throw
 }//else
}//TVariant

//------------------------------------------------------------------------
void TVariant::CopyInEnumerator(VARIANT* const pVariant)const
{
 assert(pVariant);
 assert(pVariant->vt==VT_EMPTY);

 LCPI_OS__VariantInit(pVariant);

 ole_lib::Variant_Copy_Throw(/*pDest*/pVariant,/*pSource*/this);//throw
}//CopyInEnumerator

//------------------------------------------------------------------------
long TVariant::as_long()const
{
 long tmp=0;

 self_type::to_long(this,&tmp);

 return tmp;
}//as_long

//------------------------------------------------------------------------
short TVariant::as_short()const
{
 short tmp=0;

 self_type::to_short(this,&tmp);

 return tmp;
}//as_short

//------------------------------------------------------------------------
std::string TVariant::as_str()const
{
 std::string tmp;

 self_type::to_string(this,&tmp);

 return tmp;
}//as_str

//------------------------------------------------------------------------
std::wstring TVariant::as_wstr()const
{
 std::wstring tmp;

 self_type::to_string(this,&tmp);

 return tmp;
}//as_wstr

//------------------------------------------------------------------------
t_string TVariant::as_tstr()const
{
 t_string tmp;

 self_type::to_string(this,&tmp);

 return tmp;
}//as_tstr

//------------------------------------------------------------------------
double TVariant::as_double()const
{
 double tmp=0;

 self_type::to_double(this,&tmp);

 return tmp;
}//as_double

//------------------------------------------------------------------------
float TVariant::as_float()const
{
 float tmp=0;

 self_type::to_float(this,&tmp);

 return tmp;
}//as_float

//------------------------------------------------------------------------
bool TVariant::as_bool()const
{
 bool tmp=false;

 self_type::to_bool(this,&tmp);

 return tmp;
}//as_bool

////////////////////////////////////////////////////////////////////////////////
//assign operations

#define COPY_SIMPLE_TYPE(type,memberVal,value)  \
{                                               \
 if(this->vt!=(type))                           \
 {                                              \
  _VERIFY_EQ(this->Clear(),S_OK);               \
                                                \
  assert(this->vt==VT_EMPTY);                   \
                                                \
  this->vt=(type);                              \
 }                                              \
                                                \
 this->memberVal=(value);                       \
                                                \
 return *this;                                  \
}

//------------------------------------------------------------------------
TVariant& TVariant::SetStr_v2(const structure::t_const_str_box& str) //throw
{
 CHECK_READ_TYPED_PTR(str.data(),str.size());

 BSTR _bstrVal=NULL;

 HRESULT const hr=StringToBStr(&_bstrVal,
                               str.data(),
                               str.size(),
                               /*create_empty*/true);

 if(FAILED(hr))
 {
  t_base_ole_error::throw_error(hr,g_err_msg__fail_create_BSTR_from_ANSI);
 }

 assert(hr==S_OK);

 assert(_bstrVal); //[2018-12-23] create_empty=true

 _VERIFY_EQ(this->Clear(),S_OK);

 assert(this->vt==VT_EMPTY);

 this->vt      =VT_BSTR;
 this->bstrVal =_bstrVal;

 return *this;
}//SetStr_v2

//------------------------------------------------------------------------
TVariant& TVariant::SetWStr_v2(const structure::t_const_wstr_box& wstr) //throw
{
 CHECK_READ_TYPED_PTR(wstr.data(),wstr.size());

 BSTR _bstrVal=NULL;

 HRESULT const hr=WStrToBStr(&_bstrVal,
                             wstr.data(),
                             wstr.size(),
                             /*create_empty*/true);

 if(FAILED(hr))
 {
  t_base_ole_error::throw_error(hr,g_err_msg__fail_create_BSTR_from_UNICODE);
 }

 assert(hr==S_OK);

 assert(_bstrVal); //[2018-12-23] create_empty=true

 _VERIFY_EQ(this->Clear(),S_OK);

 assert(this->vt==VT_EMPTY);

 this->vt      =VT_BSTR;
 this->bstrVal =_bstrVal;

 return *this;
}//SetWStr_v2

//------------------------------------------------------------------------
TVariant& TVariant::SetBStr_v2(const BSTR bstr)
{
 const UINT length=bstr?LCPI_OS__SysStringLen(bstr):0;

 return this->SetWStr_v2(structure::make_str_box(bstr,length));
}//SetBStr_v2

//------------------------------------------------------------------------
TVariant& TVariant::SetDate(DATE const Date)
{
 COPY_SIMPLE_TYPE(VT_DATE,date,Date)
}

//------------------------------------------------------------------------
TVariant& TVariant::swap(self_type& x)
{
 const VARIANT tmp(*this);

 (*static_cast<VARIANT*>(this))=x;

 (*static_cast<VARIANT*>(&x))=tmp;

 return *this;
}//swap - TVariant

//------------------------------------------------------------------------
TVariant& TVariant::swap(VARIANT& x)
{
 const VARIANT tmp(*this);

 (*static_cast<VARIANT*>(this))=x;

 (*static_cast<VARIANT*>(&x))=tmp;

 return *this;
}//swap - VARIANT

//------------------------------------------------------------------------
TVariant& TVariant::operator = (const self_type& x)
{
 self_type tmp(x); //throw

 return this->swap(tmp);
}//operator = self_type

//------------------------------------------------------------------------
TVariant& TVariant::operator = (const VARIANT& x)
{
 self_type tmp(x); //throw

 return this->swap(tmp);
}//operator = VARIANT

//------------------------------------------------------------------------
TVariant& TVariant::operator = (LONG const Long)
{
 COPY_SIMPLE_TYPE(VT_I4,lVal,Long)
}

//------------------------------------------------------------------------
TVariant& TVariant::operator = (short const Short)
{
 COPY_SIMPLE_TYPE(VT_I2,iVal,Short);
}

//------------------------------------------------------------------------
TVariant& TVariant::operator = (double const Double)
{
 COPY_SIMPLE_TYPE(VT_R8,dblVal,Double);
}

//------------------------------------------------------------------------
TVariant& TVariant::operator = (float const Float)
{
 COPY_SIMPLE_TYPE(VT_R4,fltVal,Float);
}

//------------------------------------------------------------------------
TVariant& TVariant::operator = (bool const Bool)
{
 COPY_SIMPLE_TYPE(VT_BOOL,boolVal,Bool?VARIANT_TRUE:VARIANT_FALSE);
}

//------------------------------------------------------------------------
TVariant& TVariant::operator = (const tagCY& cy)
{
 tagCY const tmp(cy);

 COPY_SIMPLE_TYPE(VT_CY,cyVal,tmp);
}

#undef COPY_SIMPLE_TYPE

//------------------------------------------------------------------------
TVariant& TVariant::operator = (const tagDEC& x)
{
 const tagDEC tmp(x);

 if(this->vt!=VT_DECIMAL)
 {
  this->Clear();
 }

 this->decVal =tmp;
 this->vt     =VT_DECIMAL;

 return *this;
}

//------------------------------------------------------------------------
TVariant& TVariant::operator = (IDispatch* const pDispatch)
{
 DECLARE_IPTR_TYPE(IDispatch);

 IPtr2<IDispatch> spDisp(pDispatch);//блокируем интерфейс в памяти

 this->Clear();

 spDisp.MoveTo_Fast(&this->pdispVal);

 this->vt=VT_DISPATCH;

 return *this;
}

//------------------------------------------------------------------------
TVariant& TVariant::operator = (IUnknown* const pUnknown)
{
 IUnknownPtr spUnk(pUnknown); //блокировка интерфейса

 this->Clear();

 spUnk.MoveTo_Fast(&this->punkVal);

 this->vt=VT_UNKNOWN;

 return *this;
}

//------------------------------------------------------------------------
HRESULT TVariant::to_string(const VARIANT* const pVariant,
                            std::string*   const pStr)
{
 assert(pVariant);
 assert(pStr);

 pStr->erase();

 if(pVariant==NULL)
  return E_POINTER;

 char tmp[128];

 switch(pVariant->vt)
 {
  case VT_EMPTY:
   return S_OK;

  case VT_EMPTY|VT_BYREF:
   return DISP_E_BADVARTYPE;

  case VT_NULL:
   return S_OK;

  case VT_NULL|VT_BYREF:
   return DISP_E_BADVARTYPE;

  //DATE -----------------------------------------------------------------
  case VT_DATE:
   {
    SYSTEMTIME sys;

    if(LCPI_OS__VariantTimeToSystemTime(pVariant->date,&sys)==FALSE)
     return E_FAIL;

    _GCRT_sprintf_s_n3(tmp,_DIM_(tmp),"%02d.%02d.%04d",sys.wDay,sys.wMonth,sys.wYear);

    break;
   }//VT_DATE

  case VT_DATE|VT_BYREF:
   {
    if(pVariant->pdate==NULL)
     return E_POINTER;

    SYSTEMTIME sys;

    if(LCPI_OS__VariantTimeToSystemTime(*pVariant->pdate,&sys)==FALSE)
     return E_FAIL;

    _GCRT_sprintf_s_n3(tmp,_DIM_(tmp),"%02d.%02d.%04d",sys.wDay,sys.wMonth,sys.wYear);

    break;
   }//VT_DATE|VT_BYREF

  //BOOL -----------------------------------------------------------------
  case VT_BOOL:
   {
    (*pStr)=(pVariant->boolVal)?"true":"false";

    return NOERROR;
   }//VT_BOOL

  case VT_BOOL|VT_BYREF:
   {
    if(pVariant->pboolVal==NULL)
     return E_POINTER;

    (*pStr)=(*(pVariant->pboolVal))?"true":"false";

    return NOERROR;
   }//VT_BOOL|VT_BYREF

  //BSTR -----------------------------------------------------------------
  case VT_BSTR:
   {
    (*pStr)=BStrToString(pVariant->bstrVal);

    return NOERROR;
   }//VT_BSTR

  case VT_BSTR|VT_BYREF:
   {
    if(pVariant->pbstrVal==NULL)
     return E_POINTER;

    (*pStr)=BStrToString(*pVariant->pbstrVal);

    return NOERROR;
   }//VT_BSTR|VT_BYREF

  //DOUBLE ---------------------------------------------------------------
  case VT_R8:
   {
    _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%.16lg",(double)pVariant->dblVal);

    break;
   }//VT_R8

  case VT_R8|VT_BYREF:
   {
    if(pVariant->pdblVal==NULL)
     return E_POINTER;

    _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%.16lg",(double)*pVariant->pdblVal);

    break;
   }//VT_R8|VT_BYREF

  //FLOAT ----------------------------------------------------------------
  case VT_R4:
   {
    _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%.9lg",(double)pVariant->fltVal);

    break;
   }//VT_R4

  case VT_R4|VT_BYREF:
   {
    if(pVariant->pfltVal==NULL)
     return E_POINTER;

    _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%.9lg",(double)*pVariant->pfltVal);

    break;
   }//VT_R4|VT_BYREF

  //DEFAULT --------------------------------------------------------------
  default:
   {
    TBaseVariant var;

    const HRESULT hr=LCPI_OS__VariantChangeType(&var,const_cast<VARIANT*>(pVariant),0,VT_BSTR);

    if(hr==S_OK)
     (*pStr)=BStrToString(var.bstrVal);

    return hr;
   }
 }//switch

 (*pStr)=tmp;

 return NOERROR;
}//to_string

//------------------------------------------------------------------------
HRESULT TVariant::to_string(const VARIANT* const pVariant,
                            std::wstring*  const pStr)
{
 assert(pVariant);
 assert(pStr);

 pStr->erase();

 if(pVariant==NULL)
  return E_POINTER;

 wchar_t tmp[128];

 switch(pVariant->vt)
 {
  case VT_EMPTY:
   return S_OK;

  case VT_EMPTY|VT_BYREF:
   return DISP_E_BADVARTYPE;

  case VT_NULL:
   return S_OK;

  case VT_NULL|VT_BYREF:
   return DISP_E_BADVARTYPE;

  //DATE -----------------------------------------------------------------
  case VT_DATE:
   {
    SYSTEMTIME sys;

    if(LCPI_OS__VariantTimeToSystemTime(pVariant->date,&sys)==FALSE)
     return E_FAIL;

    _GCRT_swprintf_s_n3(tmp,_DIM_(tmp),L"%02d.%02d.%04d",sys.wDay,sys.wMonth,sys.wYear);

    break;
   }//VT_DATE

  case VT_DATE|VT_BYREF:
   {
    if(pVariant->pdate==NULL)
     return E_POINTER;

    SYSTEMTIME sys;

    if(LCPI_OS__VariantTimeToSystemTime(*(pVariant->pdate),&sys)==FALSE)
     return E_FAIL;

    _GCRT_swprintf_s_n3(tmp,_DIM_(tmp),L"%02d.%02d.%04d",sys.wDay,sys.wMonth,sys.wYear);

    break;
   }//VT_DATE|VT_BYREF

  //BOOL -----------------------------------------------------------------
  case VT_BOOL:
   {
    (*pStr)=(pVariant->boolVal)?L"true":L"false";

    return NOERROR;
   }//VT_BOOL

  case VT_BOOL|VT_BYREF:
   {
    if(pVariant->pboolVal==NULL)
     return E_POINTER;

    (*pStr)=(*(pVariant->pboolVal))?L"true":L"false";

    return NOERROR;
   }//VT_BOOL|VT_BYREF

  //BSTR -----------------------------------------------------------------
  case VT_BSTR:
   {
    if(pVariant->bstrVal!=NULL)
     pStr->assign(pVariant->bstrVal,LCPI_OS__SysStringLen(pVariant->bstrVal));

    return NOERROR;
   }//VT_BSTR

  case VT_BSTR|VT_BYREF:
   {
    if(pVariant->pbstrVal==NULL)
     return E_POINTER;

    if((*pVariant->pbstrVal)!=NULL)
     pStr->assign(*pVariant->pbstrVal,LCPI_OS__SysStringLen(*pVariant->pbstrVal));

    return NOERROR;
   }//VT_BSTR|VT_BYREF

  //DOUBLE ---------------------------------------------------------------
  case VT_R8:
   {
    _GCRT_swprintf_s_n1(tmp,_DIM_(tmp),L"%.16lg",(double)pVariant->dblVal);

    break;
   }//VT_R8

  case VT_R8|VT_BYREF:
   {
    if(pVariant->pdblVal==NULL)
     return E_POINTER;

    _GCRT_swprintf_s_n1(tmp,_DIM_(tmp),L"%.16lg",(double)*pVariant->pdblVal);

    break;
   }//VT_R8|VT_BYREF

  //FLOAT ----------------------------------------------------------------
  case VT_R4:
   {
    _GCRT_swprintf_s_n1(tmp,_DIM_(tmp),L"%.9lg",(double)pVariant->fltVal);

    break;
   }//VT_R4

  case VT_R4|VT_BYREF:
   {
    if(pVariant->pfltVal==NULL)
     return E_POINTER;

    _GCRT_swprintf_s_n1(tmp,_DIM_(tmp),L"%.9lg",(double)*pVariant->pfltVal);

    break;
   }//VT_R4|VT_BYREF

  //DEFAULT --------------------------------------------------------------
  default:
   {
    TBaseVariant var;

    const HRESULT hr=LCPI_OS__VariantChangeType(&var,const_cast<VARIANT*>(pVariant),0,VT_BSTR);

    if(hr==S_OK && var.bstrVal!=NULL)
     pStr->assign(var.bstrVal,LCPI_OS__SysStringLen(var.bstrVal));

    return hr;
   }
 }//switch

 (*pStr)=tmp;

 return NOERROR;
}//to_string

//------------------------------------------------------------------------
HRESULT TVariant::to_bstr(const VARIANT* pVariant,BSTR* pBSTR)
{
 assert(pBSTR!=NULL);
 assert(pVariant!=NULL);

 if(pVariant== NULL || pBSTR==NULL)
  return E_POINTER;

 *pBSTR=NULL;

 switch(pVariant->vt)
 {
  //BSTR ------------------------------------------------------------
  case VT_BSTR:
   {
    if(pVariant->bstrVal==NULL)
     return S_OK;

    (*pBSTR)=LCPI_OS__SysAllocStringLen(pVariant->bstrVal,LCPI_OS__SysStringLen(pVariant->bstrVal));

    if((*pBSTR)==NULL)
     return E_OUTOFMEMORY;

    return S_OK;
   } //VT_BSTR

  //VT_BYRER|VT_BSTR ------------------------------------------------
  case VT_BSTR|VT_BYREF:
   {
    if(pVariant->pbstrVal==NULL)
     return E_POINTER;

    if((*(pVariant->pbstrVal))==NULL)
     return S_OK;

    (*pBSTR)=LCPI_OS__SysAllocStringLen(*pVariant->pbstrVal,LCPI_OS__SysStringLen(*pVariant->pbstrVal));

    if((*pBSTR)==NULL)
     return E_OUTOFMEMORY;

    return S_OK;
   } //VT_BSTR|VT_BYREF
 }//switch

 //DEFAULT ----------------------------------------------------------
 std::wstring str;

 HRESULT hr=self_type::to_string(pVariant,&str);

 if(hr==NOERROR)
  hr=WStrToBStr(pBSTR,str);

 return hr;
}//to_bstr

//------------------------------------------------------------------------
#define CONVERT_SIMPLE_VT_TYPE(VT_DEST_TYPE,CONVERT_OPERATOR,DEST_MEMBER)     \
{                                                                             \
 assert(pVariant!=NULL);                                                      \
 assert(pValue!=NULL);                                                        \
                                                                              \
 if(pVariant==NULL || pValue==NULL)                                           \
  return E_POINTER;                                                           \
                                                                              \
 VARIANT Dest={};                                                             \
                                                                              \
 assert(Dest.vt==VT_EMPTY);                                                   \
                                                                              \
 HRESULT const hr=                                                            \
  LCPI_OS__VariantChangeType                                                  \
    (&Dest,                                                                   \
     const_cast<VARIANT*>(pVariant),                                          \
     0,                                                                       \
     (VT_DEST_TYPE));                                                         \
                                                                              \
 if(hr==S_OK)                                                                 \
 {                                                                            \
  assert_msg(Dest.vt==(VT_DEST_TYPE),"Dest.vt="<<int(Dest.vt));               \
                                                                              \
  (*pValue)=CONVERT_OPERATOR(Dest.DEST_MEMBER);                               \
 }                                                                            \
                                                                              \
 return hr;                                                                   \
}

//------------------------------------------------------------------------
HRESULT TVariant::to_long(const VARIANT* pVariant,LONG* pValue)
{
 CONVERT_SIMPLE_VT_TYPE(VT_I4,,lVal)
}

//------------------------------------------------------------------------
HRESULT TVariant::to_short(const VARIANT* pVariant,short* pValue)
{
 CONVERT_SIMPLE_VT_TYPE(VT_I2,,iVal)
}

//------------------------------------------------------------------------
HRESULT TVariant::to_double(const VARIANT* pVariant,double* pValue)
{
 CONVERT_SIMPLE_VT_TYPE(VT_R8,,dblVal)
}

//------------------------------------------------------------------------
HRESULT TVariant::to_float(const VARIANT* pVariant,float* pValue)
{
 CONVERT_SIMPLE_VT_TYPE(VT_R4,,fltVal)
}

//------------------------------------------------------------------------
HRESULT TVariant::to_bool(const VARIANT* pVariant,bool* pValue)
{
 CONVERT_SIMPLE_VT_TYPE(VT_BOOL,!!,boolVal)
}

//------------------------------------------------------------------------
HRESULT TVariant::to_date(const VARIANT* pVariant,DATE* pValue)
{
 CONVERT_SIMPLE_VT_TYPE(VT_DATE,,date)
}

//------------------------------------------------------------------------
HRESULT TVariant::to_int64(const VARIANT* pVariant,__int64* pInt64)
{
 assert(pVariant!=NULL);
 assert(pInt64!=NULL);

 *pInt64=0;

 switch(pVariant->vt)
 {
  case VT_EMPTY:
  case  VT_NULL: break;
  //BYTE ------------------------------------------------------------
  case   VT_UI1:*pInt64=pVariant->bVal;
                 break;
  case VT_BYREF|
         VT_UI1: if(pVariant->pbVal!=NULL)
                  *pInt64=*pVariant->pbVal;
                 break;
  //CHAR ------------------------------------------------------------
  case    VT_I1:*pInt64=pVariant->cVal;
                 break;

  case VT_BYREF|
          VT_I1: if(pVariant->pcVal!=NULL)
                  *pInt64=*pVariant->pcVal;
                 break;
  //USHORT ----------------------------------------------------------
  case   VT_UI2:*pInt64=pVariant->uiVal;
                 break;
  case VT_BYREF|
         VT_UI2: if(pVariant->puiVal!=NULL)
                  *pInt64=*pVariant->puiVal;
                 break;
  //SHORT -----------------------------------------------------------
  case    VT_I2:*pInt64=pVariant->iVal;
                 break;
  case VT_BYREF|
          VT_I2: if(pVariant->piVal!=NULL)
                  *pInt64=*pVariant->piVal;
                 break;
  //ULONG -----------------------------------------------------------
  case   VT_UI4:*pInt64=pVariant->ulVal;
                 break;
  case VT_BYREF|
         VT_UI4: if(pVariant->pulVal!=NULL)
                  *pInt64=*pVariant->pulVal;
                 break;
  //LONG ------------------------------------------------------------
  case    VT_I4:*pInt64=pVariant->lVal;
                 break;
  case VT_BYREF|
          VT_I4: if(pVariant->plVal!=NULL)
                  *pInt64=*pVariant->plVal;
                 break;
  //UINT ------------------------------------------------------------
  case  VT_UINT:*pInt64=pVariant->uintVal;
                 break;
  case VT_BYREF|
        VT_UINT: if(pVariant->puintVal!=NULL)
                  *pInt64=*pVariant->puintVal;
                 break;
  //INT -------------------------------------------------------------
  case   VT_INT:*pInt64=pVariant->intVal;
                 break;
  case VT_BYREF|
         VT_INT: if(pVariant->pintVal!=NULL)
                  *pInt64=*pVariant->pintVal;
                 break;
  //FLOAT -----------------------------------------------------------
  case    VT_R4: if(pVariant->fltVal<_I64_MIN || pVariant->fltVal>_I64_MAX)
                  return DISP_E_OVERFLOW;

                *pInt64=static_cast<__int64>(pVariant->fltVal);
                 break;
  case VT_BYREF|
          VT_R4: if(pVariant->pfltVal==NULL)
                  break;

                 if((*pVariant->pfltVal)<_I64_MIN || (*pVariant->pfltVal)>_I64_MAX)
                  return DISP_E_OVERFLOW;

                *pInt64=static_cast<__int64>(*pVariant->pfltVal);
                 break;
  //DOUBLE ----------------------------------------------------------
  case    VT_R8: if(pVariant->dblVal<_I64_MIN || pVariant->dblVal>_I64_MAX)
                  return DISP_E_OVERFLOW;

                *pInt64=static_cast<__int64>(pVariant->dblVal);
                 break;
  case VT_BYREF|
          VT_R8: if(pVariant->pdblVal==NULL)
                  break;

                 if((*pVariant->pdblVal)<_I64_MIN || (*pVariant->pdblVal)>_I64_MAX)
                  return DISP_E_OVERFLOW;

                *pInt64=static_cast<__int64>(*pVariant->pdblVal);
                 break;
  //CURRENCY --------------------------------------------------------
  case    VT_CY:*pInt64=pVariant->cyVal.int64/10000;
                 break;
  case VT_BYREF|
          VT_CY: if(pVariant->pcyVal!=NULL)
                  *pInt64=pVariant->pcyVal->int64/10000;
                 break;
  //BSTR ------------------------------------------------------------
  case  VT_BSTR: if(pVariant->bstrVal!=NULL)
                  *pInt64=_wtoi64(pVariant->bstrVal);
                 break;
  case VT_BYREF|
        VT_BSTR: if(pVariant->pbstrVal!=NULL && *pVariant->pbstrVal!=NULL)
                  *pInt64=_wtoi64(*pVariant->pbstrVal);
                 break;
  //DEFAULT ---------------------------------------------------------
  default      : return DISP_E_TYPEMISMATCH;
 }//switch

 return NOERROR;
}//to_int64

//------------------------------------------------------------------------
HRESULT TVariant::to_uint64(const VARIANT* pVariant,unsigned __int64* pUInt64)
{
 assert(pVariant!=NULL);
 assert(pUInt64!=NULL);

*pUInt64=0;

 switch(pVariant->vt)
 {
  case VT_EMPTY:
  case  VT_NULL: break;
  //BYTE ------------------------------------------------------------
  case   VT_UI1:*pUInt64=pVariant->bVal;
                 break;
  case VT_BYREF|
         VT_UI1: if(pVariant->pbVal!=NULL)
                  *pUInt64=*pVariant->pbVal;
                 break;
  //CHAR ------------------------------------------------------------
  case    VT_I1: if(pVariant->cVal<0)
                  return DISP_E_OVERFLOW;

                 *pUInt64=pVariant->cVal;
                 break;
  case VT_BYREF|
          VT_I1: if(pVariant->pcVal==NULL)
                  break;

                 if((*pVariant->pcVal)<0)
                  return DISP_E_OVERFLOW;

                *pUInt64=*pVariant->pcVal;
                 break;
  //USHORT ----------------------------------------------------------
  case   VT_UI2:*pUInt64=pVariant->uiVal;
                 break;

  case VT_BYREF|
         VT_UI2: if(pVariant->puiVal==NULL)
                  break;

                *pUInt64=*pVariant->puiVal;
                 break;
  //SHORT -----------------------------------------------------------
  case    VT_I2: if(pVariant->iVal<0)
                  return DISP_E_OVERFLOW;

                *pUInt64=pVariant->iVal;
                 break;
  case VT_BYREF|
          VT_I2: if(pVariant->piVal==NULL)
                  break;

                 if((*pVariant->piVal)<0)
                  return DISP_E_OVERFLOW;

                *pUInt64=*pVariant->piVal;
                 break;
  //ULONG -----------------------------------------------------------
  case   VT_UI4:*pUInt64=pVariant->ulVal;
                 break;

  case VT_BYREF|
         VT_UI4: if(pVariant->pulVal!=NULL)
                  *pUInt64=*pVariant->pulVal;
                 break;
  //LONG ------------------------------------------------------------
  case    VT_I4: if(pVariant->lVal<0)
                  return DISP_E_OVERFLOW;

                *pUInt64=pVariant->lVal;
                 break;
  case VT_BYREF|
          VT_I4: if(pVariant->plVal==NULL)
                  break;

                 if((*pVariant->plVal)<0)
                  return DISP_E_OVERFLOW;

                *pUInt64=*pVariant->plVal;
                 break;
  //UINT ------------------------------------------------------------
  case  VT_UINT:*pUInt64=pVariant->uintVal;
                 break;

  case VT_BYREF|
        VT_UINT: if(pVariant->puintVal!=NULL)
                  *pUInt64=*pVariant->puintVal;
                 break;
  //INT -------------------------------------------------------------
  case   VT_INT: if(pVariant->intVal<0)
                  return DISP_E_OVERFLOW;

                *pUInt64=pVariant->intVal;
                 break;

  case VT_BYREF|
         VT_INT: if(pVariant->pintVal==NULL)
                  break;

                 if((*pVariant->pintVal)<0)
                  return DISP_E_OVERFLOW;

                *pUInt64=pVariant->intVal;
                 break;
  //FLOAT -----------------------------------------------------------
  case    VT_R4: if(pVariant->fltVal<0 || pVariant->fltVal>_UI64_MAX)
                  return DISP_E_OVERFLOW;

                *pUInt64=static_cast<unsigned __int64>(pVariant->fltVal);
                 break;
  case VT_BYREF|
          VT_R4: if(pVariant->pfltVal==NULL)
                  break;

                 if((*pVariant->pfltVal)<0 || (*pVariant->pfltVal)>_UI64_MAX)
                  return DISP_E_OVERFLOW;

                *pUInt64=static_cast<unsigned __int64>(*pVariant->pfltVal);
                 break;
  //DOUBLE ----------------------------------------------------------
  case    VT_R8: if(pVariant->dblVal<0 || pVariant->dblVal>_UI64_MAX)
                  return DISP_E_OVERFLOW;

                *pUInt64=static_cast<unsigned __int64>(pVariant->dblVal);
                 break;
  case VT_BYREF|
          VT_R8: if(pVariant->pdblVal==NULL)
                  break;

                 if((*pVariant->pdblVal)<0 || (*pVariant->pdblVal)>_UI64_MAX)
                  return DISP_E_OVERFLOW;

                *pUInt64=static_cast<unsigned __int64>(*pVariant->pdblVal);
                 break;
  //CURRENCY --------------------------------------------------------
  case    VT_CY: if(pVariant->cyVal.int64<0)
                  return DISP_E_OVERFLOW;

                *pUInt64=pVariant->cyVal.int64/10000;
                 break;
  case VT_BYREF|
          VT_CY: if(pVariant->pcyVal==NULL)
                  break;

                 if(pVariant->pcyVal->int64<0)
                  return DISP_E_OVERFLOW;

                *pUInt64=pVariant->pcyVal->int64/10000;
                 break;
  //BSTR ------------------------------------------------------------
  case  VT_BSTR: if(pVariant->bstrVal!=NULL)
                  *pUInt64=_wtoi64(pVariant->bstrVal);
                 break;
  case VT_BYREF|
        VT_BSTR: if(pVariant->pbstrVal!=NULL && (*pVariant->pbstrVal)!=NULL)
                  *pUInt64=_wtoi64(*pVariant->pbstrVal);
                 break;
  //DEFAULT ---------------------------------------------------------
  default      : return DISP_E_TYPEMISMATCH;
 }//switch

 return NOERROR;
}//to_uint64

//------------------------------------------------------------------------
HRESULT TVariant::to_unknown(const VARIANT* pVariant,IUnknown** ppUnk)
{
 assert(pVariant!=NULL);
 assert(ppUnk!=NULL);

 if(ppUnk==NULL)
  return E_INVALIDARG;

 *ppUnk=NULL;

 switch(pVariant->vt)
 {
  case VT_UNKNOWN:
   return ole_lib::CopyComInterface(pVariant->punkVal,ppUnk);

  case VT_DISPATCH:
   return ole_lib::CopyComInterface(pVariant->pdispVal,ppUnk);
 }//switch

 return DISP_E_TYPEMISMATCH;
}//to_unknown

//------------------------------------------------------------------------
HRESULT TVariant::to_dispatch(const VARIANT* pVariant,IDispatch** ppDisp)
{
 assert(pVariant!=NULL);
 assert(ppDisp!=NULL);

 if(ppDisp==NULL)
  return E_INVALIDARG;

 *ppDisp=NULL;

 switch(pVariant->vt)
 {
  case VT_UNKNOWN:
   {
    if(pVariant->punkVal==NULL)
     return NOERROR;

    return pVariant->punkVal->QueryInterface(IID_IDispatch,(void**)ppDisp);
   }//VT_UNKNOWN

  case VT_DISPATCH:
   return ole_lib::CopyComInterface(pVariant->pdispVal,ppDisp);
 }//switch

 return DISP_E_TYPEMISMATCH;
}//to_dispatch

//------------------------------------------------------------------------
std::string TVariant::variant_date_to_str(DATE date,bool WithTime)
{
 SYSTEMTIME sys;

 if(LCPI_OS__VariantTimeToSystemTime(date,&sys)==FALSE)
  return std::string();

 char tmp[256];

 int c;

 if(!WithTime)
 {
  c=_GCRT_sprintf_s_n3(tmp,_DIM_(tmp),"%02d.%02d.%04d",
                       sys.wDay,sys.wMonth,sys.wYear);
 }
 else
 {
  c=_GCRT_sprintf_s_n6(tmp,_DIM_(tmp),"%02d.%02d.%04d %02d:%02d:%02d",
                       sys.wDay,sys.wMonth,sys.wYear,
                       sys.wHour,sys.wMinute,sys.wSecond);
 }//else

 return std::string(tmp,(c==EOF)?0:c);
}//variant_date_to_str

//------------------------------------------------------------------------
std::wstring TVariant::variant_date_to_wstr(DATE date,bool WithTime)
{
 SYSTEMTIME sys;

 if(LCPI_OS__VariantTimeToSystemTime(date,&sys)==FALSE)
  return std::wstring();

 wchar_t tmp[256];

 int c;

 if(!WithTime)
 {
  c=_GCRT_swprintf_s_n3(tmp,_DIM_(tmp),L"%02d.%02d.%04d",
                       sys.wDay,sys.wMonth,sys.wYear);
 }
 else
 {
  c=_GCRT_swprintf_s_n6(tmp,_DIM_(tmp),L"%02d.%02d.%04d %02d:%02d:%02d",
                       sys.wDay,sys.wMonth,sys.wYear,
                       sys.wHour,sys.wMinute,sys.wSecond);
 }//else

 return std::wstring(tmp,(c==EOF)?0:c);
}//variant_date_to_wstr

//------------------------------------------------------------------------
VARIANT TVariant::build_variant_with_scode(SCODE const x)
{
 VARIANT var;

 var.vt    =VT_ERROR;
 var.scode =x;

 return var;
}//build_variant_with_scode

////////////////////////////////////////////////////////////////////////////////
//inner class TVariant::tag_print_variant

std::wstring TVariant::tag_print_variant::str()const
{
 std::wstringstream os;

 switch(m_data.vt)
 {
  case VT_I1:
   os<<(LONG)m_data.cVal;
   break;

  case VT_I2:
   os<<m_data.iVal;
   break;

  case VT_I4:
   os<<m_data.lVal<<L"L";
   break;

  case VT_UI1:
   os<<(ULONG)m_data.bVal;
   break;

  case VT_UI2:
   os<<m_data.uiVal;
   break;

  case VT_UI4:
   os<<m_data.ulVal<<L"UL";
   break;

  case VT_BOOL:
   os<<((m_data.boolVal==VARIANT_FALSE)?L"FALSE":L"TRUE")<<L" ["<<m_data.boolVal<<"]";
   break;

  case VT_DATE:
   os<<L"TIME";
   break;

  case VT_R8:
   os<<m_data.dblVal;
   break;

  case VT_R4:
   os<<m_data.fltVal;
   break;

  case VT_NULL:
   os<<L"NULL";
   break;

  case VT_EMPTY:
   os<<L"EMPTY";
   break;

  case VT_ERROR:
   os<<L"ERROR";
   break;

  case VT_BSTR:
   if(m_data.bstrVal==NULL)
    return L"bstr\"\"";

   os<<L"bstr\"";
   os.write(m_data.bstrVal,LCPI_OS__SysStringLen(m_data.bstrVal));
   os<<L"\"";
   break;

  default:
   os<<L"[vt:0x"<<std::hex<<m_data.vt<<L"]";
   break;
 }//switch

 return os.str();
}//str

//------------------------------------------------------------------------
std::ostream& operator << (std::ostream& os,const TVariant::tag_print_variant& data)
{
 return os<<structure::tstr_to_str(data.str());
}//operator << (print_variant)

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
