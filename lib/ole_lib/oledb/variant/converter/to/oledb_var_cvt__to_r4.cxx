////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. convert to R4
//                                                 Dmitry Kovalenko. 20.07.2003

////////////////////////////////////////////////////////////////////////////////
// to float

HRESULT DBVARIANT::to_R4(value_r4_n_type* const value)const
{
 assert(value);

 const TDBVariant_TypeCvtContext_Std ctx;

 return DBVariant__to_R4_ex(&ctx,*this,value);
}//to_R4

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to(value_r4_n_type* const value)const
{
 assert(value);

 return this->to_R4(value);
}//to

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to_nn(value_r4_type* const value)const
{
 assert(value);

 (*value)=0;

 value_r4_n_type tmp;

 const HRESULT hr=this->to(&tmp);

 if(FAILED(hr))
  return hr;

 if(tmp.null())
  return DB_E_CANTCONVERTVALUE;

 (*value)=tmp.value();

 return hr;
}//to_nn - value_r4_type

////////////////////////////////////////////////////////////////////////////////
