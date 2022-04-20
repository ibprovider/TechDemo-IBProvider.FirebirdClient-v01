////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 15.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(I4,I4)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(I4,I4)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_I4);
 assert(v2.vt==VT_I4);

 const_cast<const signed long*>(&v1.lVal);

 if(v1.lVal<v2.lVal)
  return VariantCmpCode__ok__less;

 if(v2.lVal<v1.lVal)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
