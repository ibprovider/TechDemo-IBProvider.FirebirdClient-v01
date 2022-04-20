////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. convert to I8
//                                                 Dmitry Kovalenko. 20.07.2003

////////////////////////////////////////////////////////////////////////////////
// to __int64

HRESULT DBVARIANT::to_I8(value_i8_n_type* const value)const
{
 assert(value);

 const TDBVariant_TypeCvtContext_Std ctx;

 return DBVariant__to_I8_ex(&ctx,*this,value);
}//to_I8

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to_I8(value_i8_n_type_s* const value)const
{
 assert(value);

 value_i8_n_type tmp;

 const HRESULT hr=this->to_I8(&tmp);

 if(SUCCEEDED(hr))
 {
  if(tmp.null())
   value->reset();
  else
   value->set_not_null().value().QuadPart=tmp.value();
 }//if

 return hr;
}//to_I8

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to(value_i8_n_type* const value)const
{
 assert(value);

 return this->to_I8(value);
}//to - value_i8_n_type

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to(value_i8_n_type_s* const value)const
{
 assert(value);

 return this->to_I8(value);
}//to - value_i8_n_type_s

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to_nn(value_i8_type* const pvalue)const
{
 assert(pvalue);

 (*pvalue)=0;

 value_i8_n_type tmp;

 const HRESULT hr=this->to(&tmp);

 if(FAILED(hr))
  return hr;

 if(tmp.null())
  return DB_E_CANTCONVERTVALUE;

 (*pvalue)=tmp.value();

 return hr;
}//to_nn - value_i8_type

////////////////////////////////////////////////////////////////////////////////
