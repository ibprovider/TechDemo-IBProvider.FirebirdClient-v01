////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. convert to ERROR
//                                                 Dmitry Kovalenko. 20.07.2003

////////////////////////////////////////////////////////////////////////////////
// to ERROR

HRESULT DBVARIANT::to_error(value_scode_n_type* const value)const
{
 assert(value);

 const TDBVariant_TypeCvtContext_Std ctx;

 return DBVariant__to_ERROR_ex(&ctx,*this,value);
}//to_error

////////////////////////////////////////////////////////////////////////////////
