////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(I1,I1)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(I1,I1)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_I1);
 assert(v2.vt==VT_I1);

 const_cast<const char*>(&v1.cVal);

 if(v1.cVal<v2.cVal)
  return VariantCmpCode__ok__less;

 if(v2.cVal<v1.cVal)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
