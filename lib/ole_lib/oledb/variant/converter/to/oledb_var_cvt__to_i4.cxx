////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. convert to I4
//                                                 Dmitry Kovalenko. 20.07.2003

////////////////////////////////////////////////////////////////////////////////
// to long

HRESULT DBVARIANT::to_I4(value_i4_n_type* const value) const
{
 assert(value);

 const TDBVariant_TypeCvtContext_Std ctx;

 return DBVariant__to_I4_ex(&ctx,*this,value);
}//to_I4

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to(value_i4_n_type* const value) const
{
 assert(value);

 return this->to_I4(value);
}//to - value_i4_n_type

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to_nn(value_i4_type* const pvalue)const
{
 assert(pvalue);

 (*pvalue)=0;

 value_i4_n_type tmp;

 const HRESULT hr=this->to(&tmp);

 if(FAILED(hr))
  return hr;

 if(tmp.null())
  return DB_E_CANTCONVERTVALUE;

 (*pvalue)=tmp.value();

 return hr;
}//to_nn - value_i4_type

////////////////////////////////////////////////////////////////////////////////
