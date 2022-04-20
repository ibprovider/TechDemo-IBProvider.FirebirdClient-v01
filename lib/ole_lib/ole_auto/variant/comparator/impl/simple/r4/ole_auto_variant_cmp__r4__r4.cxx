////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(R4,R4)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(R4,R4)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_R4);
 assert(v2.vt==VT_R4);

 const_cast<const float*>(&v1.fltVal);

 if(v1.fltVal<v2.fltVal)
  return VariantCmpCode__ok__less;

 if(v2.fltVal<v1.fltVal)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
