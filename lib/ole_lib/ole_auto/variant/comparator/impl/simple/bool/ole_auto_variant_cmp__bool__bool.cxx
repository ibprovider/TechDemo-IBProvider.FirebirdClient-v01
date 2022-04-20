////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(BOOL,BOOL)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(BOOL,BOOL)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_BOOL);
 assert(v2.vt==VT_BOOL);

 const_cast<const VARIANT_BOOL*>(&v1.boolVal);

 const bool xv1=(v1.boolVal!=VARIANT_FALSE);
 const bool xv2=(v2.boolVal!=VARIANT_FALSE);

 if(xv1)
 {
  if(xv2)
    return VariantCmpCode__ok__equal;

  return VariantCmpCode__ok__great;
 }//if

 assert(!xv1);

 if(!xv2)
  return VariantCmpCode__ok__equal;

 assert(xv2);

 return VariantCmpCode__ok__less;
}//exec

////////////////////////////////////////////////////////////////////////////////
