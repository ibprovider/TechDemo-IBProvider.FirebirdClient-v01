////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(I8,I8)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(I8,I8)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_I8);
 assert(v2.vt==VT_I8);

 const_cast<const signed __int64*>(&v1.llVal);

 if(v1.llVal<v2.llVal)
  return VariantCmpCode__ok__less;

 if(v2.llVal<v1.llVal)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
