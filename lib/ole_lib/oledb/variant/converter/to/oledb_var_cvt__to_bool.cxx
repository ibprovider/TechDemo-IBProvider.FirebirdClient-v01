////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. convert to bool
//                                                 Dmitry Kovalenko. 20.07.2003
////////////////////////////////////////////////////////////////////////////////
//to bool

HRESULT DBVARIANT::to_bool(value_cpp_bool_n_type* const value)const
{
 assert(value);

 const TDBVariant_TypeCvtContext_Std ctx;

 return DBVariant__to_BOOL_ex(&ctx,*this,value);
}//to_bool

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to(value_cpp_bool_n_type* const value)const
{
 assert(value);

 return this->to_bool(value);
}//to - value_cpp_bool_n_type

//-------------------------------------------------------------------------
HRESULT DBVARIANT::to_nn(value_cpp_bool_type* const value)const
{
 assert(value);

 (*value)=false;

 value_cpp_bool_n_type tmp;

 const HRESULT hr=this->to(&tmp);

 if(FAILED(hr))
  return hr;

 if(tmp.null())
  return DB_E_CANTCONVERTVALUE;

 (*value)=tmp.value();

 return hr;
}//to_nn - value_cpp_bool_type

////////////////////////////////////////////////////////////////////////////////
