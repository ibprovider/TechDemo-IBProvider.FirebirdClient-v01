////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. convert to I2
//                                                 Dmitry Kovalenko. 20.07.2003

////////////////////////////////////////////////////////////////////////////////
// to short

HRESULT DBVARIANT::to_I2(value_i2_n_type* const value) const
{
 assert(value);

 const TDBVariant_TypeCvtContext_Std ctx;

 return DBVariant__to_I2_ex(&ctx,*this,value);
}//to_I2

//------------------------------------------------------------------------
HRESULT DBVARIANT::to(value_i2_n_type* const value) const
{
 assert(value);

 return this->to_I2(value);
}//to - value_i2_n_type

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to_nn(value_i2_type* const pvalue)const
{
 assert(pvalue);

 (*pvalue)=0;

 value_i2_n_type tmp;

 const HRESULT hr=this->to(&tmp);

 if(FAILED(hr))
  return hr;

 if(tmp.null())
  return DB_E_CANTCONVERTVALUE;

 (*pvalue)=tmp.value();

 return hr;
}//to_nn - value_i2_type

////////////////////////////////////////////////////////////////////////////////
