////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(UI8,UI8)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(UI8,UI8)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_UI8);
 assert(v2.vt==VT_UI8);

 const_cast<const unsigned __int64*>(&v1.ullVal);

 if(v1.ullVal<v2.ullVal)
  return VariantCmpCode__ok__less;

 if(v2.ullVal<v1.ullVal)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
