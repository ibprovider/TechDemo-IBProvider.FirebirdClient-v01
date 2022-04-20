////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. convert to R8
//                                                 Dmitry Kovalenko. 20.07.2003

////////////////////////////////////////////////////////////////////////////////
// to double

HRESULT DBVARIANT::to_R8(value_r8_n_type* const value) const
{
 assert(value);

 TDBVariant_TypeCvtContext_Std ctx;

 return DBVariant__to_R8_ex(&ctx,*this,value);
}//to_R8

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to(value_r8_n_type* const value)const
{
 assert(value);

 return this->to_R8(value);
}//to

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to_nn(value_r8_type* const value)const
{
 assert(value);

 (*value)=0;

 value_r8_n_type tmp;

 const HRESULT hr=this->to(&tmp);

 if(FAILED(hr))
  return hr;

 if(tmp.null())
  return DB_E_CANTCONVERTVALUE;

 (*value)=tmp.value();

 return hr;
}//to_nn - value_r8_type

////////////////////////////////////////////////////////////////////////////////
