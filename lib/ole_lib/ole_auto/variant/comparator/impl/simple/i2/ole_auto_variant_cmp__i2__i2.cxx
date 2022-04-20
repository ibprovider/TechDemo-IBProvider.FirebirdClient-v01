////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(I2,I2)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(I2,I2)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_I2);
 assert(v2.vt==VT_I2);

 const_cast<const signed __int16*>(&v1.iVal);

 if(v1.iVal<v2.iVal)
  return VariantCmpCode__ok__less;

 if(v2.iVal<v1.iVal)
  return VariantCmpCode__ok__great;

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
