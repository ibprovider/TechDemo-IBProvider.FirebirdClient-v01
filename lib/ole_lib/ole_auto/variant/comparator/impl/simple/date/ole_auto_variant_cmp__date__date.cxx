////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(DATE,DATE)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(DATE,DATE)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_DATE);
 assert(v2.vt==VT_DATE);

 const_cast<const DATE*>(&v1.date);

 if(v1.date<v2.date)
  return VariantCmpCode__ok__less;

 if(v2.date<v1.date)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
