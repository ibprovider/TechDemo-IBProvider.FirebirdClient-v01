////////////////////////////////////////////////////////////////////////////////
#ifndef _ole_auto_variant_INL_
#define _ole_auto_variant_INL_

#include <ole_lib/ole_auto/ole_auto_utils.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//class TBaseVariant

inline TBaseVariant::TBaseVariant()
{
 this->vt=VT_EMPTY;
}

//------------------------------------------------------------------------
inline TBaseVariant::~TBaseVariant()
{
 _VERIFY_EQ(this->Clear(),S_OK);
}//~TBaseVariant

//------------------------------------------------------------------------
inline void TBaseVariant::CopyTo_Throw(VARIANT* const pVariant)const
{
 assert(pVariant);

 return ole_lib::Variant_Copy_Throw(pVariant,this);
}//CopyTo_Throw

//------------------------------------------------------------------------
inline HRESULT TBaseVariant::CopyTo(VARIANT* const pVariant)const
{
 return pVariant?ole_lib::Variant_Copy(pVariant,this):E_INVALIDARG;
}//CopyTo

//------------------------------------------------------------------------
inline HRESULT TBaseVariant::Clear()
{
 return ole_lib::Variant_Clear(this);
}//Clear

//------------------------------------------------------------------------
inline bool TBaseVariant::IsEmpty()const
{
 return this->vt==VT_EMPTY;
}//IsEmpty

//------------------------------------------------------------------------
inline bool TBaseVariant::IsError()const
{
 return this->vt==VT_ERROR;
}//IsError

//------------------------------------------------------------------------
inline bool TBaseVariant::IsNull()const
{
 return this->vt==VT_NULL;
}//IsNull

//------------------------------------------------------------------------
inline bool TBaseVariant::HasData() const
{
 return !(this->IsEmpty() || this->IsNull());
}//HasData

//------------------------------------------------------------------------
inline HRESULT TVariant::SetVariant(const VARIANT& Variant)
{
 return ole_lib::Variant_Copy(this,&Variant);
}//SetVariant

//------------------------------------------------------------------------
inline HRESULT TVariant::SetVariant(const VARIANT* pVariant)
{
 return pVariant?ole_lib::Variant_Copy(this,pVariant):this->Clear();
}//SetVariant

//------------------------------------------------------------------------
inline TBaseVariant& TBaseVariant::SetError(SCODE _scode)
{
 this->Clear();

 this->vt    =VT_ERROR;
 this->scode =_scode;

 return *this;
}//SetError

//------------------------------------------------------------------------
inline TBaseVariant& TBaseVariant::SetNull()
{
 this->Clear();

 this->vt=VT_NULL;

 return *this;
}//SetNull

////////////////////////////////////////////////////////////////////////////////
//class TVariant

inline TVariant::TVariant()
{;}

//------------------------------------------------------------------------
inline TVariant::TVariant(LONG data)
{
 this->lVal=data;
 this->vt  =VT_I4;
}

//------------------------------------------------------------------------
#if 0 // [2017-02-25]
inline TVariant::TVariant(ULONG data)
{
 //TODO: stupid
 this->lVal=(LONG)data;
 this->vt  =VT_I4;
}
#endif
//------------------------------------------------------------------------
#if 0 // [2017-02-25]
inline TVariant::TVariant(int data)
{
 //TODO: stupid
 this->lVal=(LONG)data;
 this->vt  =VT_I4;
}
#endif

//------------------------------------------------------------------------
inline TVariant::TVariant(short data)
{
 this->iVal=data;
 this->vt  =VT_I2;
}

//------------------------------------------------------------------------
inline TVariant::TVariant(double data)
{
 this->dblVal=data;
 this->vt    =VT_R8;
}

//------------------------------------------------------------------------
inline TVariant::TVariant(float data)
{
 this->fltVal=data;
 this->vt    =VT_R4;
}

//------------------------------------------------------------------------
inline TVariant::TVariant(bool data)
{
 this->boolVal=data?VARIANT_TRUE:VARIANT_FALSE;

 this->vt     =VT_BOOL;
}

//------------------------------------------------------------------------
inline TVariant::TVariant(const tagCY& data)
{
 this->cyVal=data;
 this->vt   =VT_CY;
}

//------------------------------------------------------------------------
inline TVariant::TVariant(const tagDEC& data)
{
 this->decVal=data;
 this->vt    =VT_DECIMAL;
}

//------------------------------------------------------------------------
inline TVariant::TVariant(IDispatch* data)
{
 if((this->pdispVal=data)!=NULL)
  this->pdispVal->AddRef();

 this->vt=VT_DISPATCH;
}

//------------------------------------------------------------------------
inline TVariant::TVariant(IUnknown* data)
{
 if((this->punkVal=data)!=NULL)
  this->punkVal->AddRef();

 this->vt=VT_UNKNOWN;
}

//------------------------------------------------------------------------
inline TVariant::TVariant(const value_i2_n_type& x)
{
 if(x.null())
 {
  this->vt=VT_NULL;
 }
 else
 {
  this->vt   =VT_I2;
  this->iVal =x.value();
 }
}//TVariant - i2_n

//------------------------------------------------------------------------
inline TVariant::TVariant(const value_i4_n_type& x)
{
 if(x.null())
 {
  this->vt=VT_NULL;
 }
 else
 {
  this->vt   =VT_I4;
  this->lVal =x.value();
 }
}//TVariant - i4_n

//------------------------------------------------------------------------
inline TVariant::TVariant(const tag_scode& x)
{
 this->vt    =VT_ERROR;
 this->scode =x.value;
}//TVariant - tag_scode

//------------------------------------------------------------------------
inline HRESULT TVariant::to_string(std::string* pStr)const
{
 return self_type::to_string(this,pStr);
}//to_string - ansi

//------------------------------------------------------------------------
inline HRESULT TVariant::to_string(std::wstring* pStr)const
{
 return self_type::to_string(this,pStr);
}//to_string - unicode

////////////////////////////////////////////////////////////////////////////////

inline TVariant::tag_print_variant print(const VARIANT& data)
{
 return TVariant::tag_print_variant(data);
}//print

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
