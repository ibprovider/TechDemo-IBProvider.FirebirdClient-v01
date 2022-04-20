////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. convert to UI1
//                                                 Dmitry Kovalenko. 20.07.2003

////////////////////////////////////////////////////////////////////////////////
// to byte

HRESULT DBVARIANT::to_UI1(value_ui1_n_type* const value)const
{
 assert(value);

 const TDBVariant_TypeCvtContext_Std ctx;

 return DBVariant__to_UI1_ex(&ctx,*this,value);
}//to_UI1

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to(value_ui1_n_type* const value)const
{
 assert(value);

 return this->to_UI1(value);
}//to - value_ui1_n_type

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to_nn(value_ui1_type* const pvalue)const
{
 assert(pvalue);

 (*pvalue)=0;

 value_ui1_n_type tmp;

 const HRESULT hr=this->to(&tmp);

 if(FAILED(hr))
  return hr;

 if(tmp.null())
  return DB_E_CANTCONVERTVALUE;

 (*pvalue)=tmp.value();

 return hr;
}//to_nn - value_ui1_type

////////////////////////////////////////////////////////////////////////////////
