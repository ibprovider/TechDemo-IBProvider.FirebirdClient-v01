////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(UI4,UI4)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(UI4,UI4)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_UI4);
 assert(v2.vt==VT_UI4);

 const_cast<const unsigned long*>(&v1.ulVal);

 if(v1.ulVal<v2.ulVal)
  return VariantCmpCode__ok__less;

 if(v2.ulVal<v1.ulVal)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
