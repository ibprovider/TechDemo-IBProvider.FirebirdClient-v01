////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. convert to IDISPATCH
//                                                 Dmitry Kovalenko. 20.07.2003

////////////////////////////////////////////////////////////////////////////////
//to IDipatch*

HRESULT DBVARIANT::to_dispatch(DBVARIANT::value_dispatch_n_type* const value) const
{
 assert(value);

 const TDBVariant_TypeCvtContext_Std ctx;

 return DBVariant__to_IDISPATCH_ex(&ctx,*this,value);
}//to_dispatch

////////////////////////////////////////////////////////////////////////////////
