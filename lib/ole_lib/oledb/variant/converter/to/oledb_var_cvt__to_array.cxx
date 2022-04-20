////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. convert to VARIANT
//                                                 Dmitry Kovalenko. 20.07.2003

////////////////////////////////////////////////////////////////////////////////
// to variant

HRESULT DBVARIANT::to_array(DBTYPE      const ArrayType,
                            SAFEARRAY** const ppSafeArray)const
{
 assert(ppSafeArray);

 const TDBVariant_TypeCvtContext_Std ctx;

 return DBVariant__to_ARRAY_ex(&ctx,*this,ArrayType,IID_IUnknown,ppSafeArray);
}//to_array

////////////////////////////////////////////////////////////////////////////////
