////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(UI2,UI2)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(UI2,UI2)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_UI2);
 assert(v2.vt==VT_UI2);

 const_cast<const unsigned __int16*>(&v1.uiVal);

 if(v1.uiVal<v2.uiVal)
  return VariantCmpCode__ok__less;

 if(v2.uiVal<v1.uiVal)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
