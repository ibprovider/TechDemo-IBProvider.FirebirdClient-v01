////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(UI1,UI1)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(UI1,UI1)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_UI1);
 assert(v2.vt==VT_UI1);

 const_cast<const unsigned __int8*>(&v1.bVal);

 if(v1.bVal<v2.bVal)
  return VariantCmpCode__ok__less;

 if(v2.bVal<v1.bVal)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
