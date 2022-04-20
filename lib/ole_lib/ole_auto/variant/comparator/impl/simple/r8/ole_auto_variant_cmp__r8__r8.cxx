////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(R8,R8)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(R8,R8)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_R8);
 assert(v2.vt==VT_R8);

 const_cast<const double*>(&v1.dblVal);

 if(v1.dblVal<v2.dblVal)
  return VariantCmpCode__ok__less;

 if(v2.dblVal<v1.dblVal)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
