////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(BSTR,BSTR)

//------------------------------------------------------------------------
OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(BSTR,BSTR)
{
 //prevent compiler warnings 'unused argument'
 ctx;

 assert(v1.vt==VT_BSTR);
 assert(v2.vt==VT_BSTR);

 const UINT l1=(v1.bstrVal?::SysStringLen(v1.bstrVal):0);
 const UINT l2=(v2.bstrVal?::SysStringLen(v2.bstrVal):0);

 const OLECHAR*       p1=v1.bstrVal;
 const OLECHAR* const e1=p1+l1;

 const OLECHAR*       p2=v2.bstrVal;
 const OLECHAR* const e2=p2+l2;

 for(;;++p1,++p2)
 {
  if(p1==e1)
  {
   if(p2==e2)
    return VariantCmpCode__ok__equal;

   return VariantCmpCode__ok__less;
  }//if

  assert_hint(p1!=e1);

  if(p2==e2)
   return VariantCmpCode__ok__great;

  if(UINT(*p1)<UINT(*p2))
   return VariantCmpCode__ok__less;

  if(UINT(*p2)<UINT(*p1))
   return VariantCmpCode__ok__great;
 }//for[ever]
}//exec

////////////////////////////////////////////////////////////////////////////////
