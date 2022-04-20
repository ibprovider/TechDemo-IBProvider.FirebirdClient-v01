////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(EMPTY,EMPTY)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(EMPTY,EMPTY)
{
 //prevent compiler warnings 'unused argument'
 ctx;v1;v2;

 assert(v1.vt==VT_EMPTY);
 assert(v2.vt==VT_EMPTY);

 return VariantCmpCode__ok__equal;
}//exec

////////////////////////////////////////////////////////////////////////////////
