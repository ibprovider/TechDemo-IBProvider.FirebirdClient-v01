////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(GUID,GUID)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(GUID,GUID)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_GUID);
 assert(v2.wType==DBTYPE_GUID);

 const_cast<const oledb_lib::t_oledb_value__GUID*>(&v1.guidVal);
 const_cast<const oledb_lib::t_oledb_value__GUID*>(&v2.guidVal);

 // typedef struct _GUID {
 //     unsigned long  Data1;
 //     unsigned short Data2;
 //     unsigned short Data3;
 //     unsigned char  Data4[ 8 ];
 // } GUID;

 if(v1.guidVal.Data1<v2.guidVal.Data1)
  return DBVariantCmpCode__ok__less;

 if(v2.guidVal.Data1<v1.guidVal.Data1)
  return DBVariantCmpCode__ok__great;

 assert(v1.guidVal.Data1==v2.guidVal.Data1);

 //---------------
 if(v1.guidVal.Data2<v2.guidVal.Data2)
  return DBVariantCmpCode__ok__less;

 if(v2.guidVal.Data2<v1.guidVal.Data2)
  return DBVariantCmpCode__ok__great;

 assert(v1.guidVal.Data2==v2.guidVal.Data2);

 //---------------
 if(v1.guidVal.Data3<v2.guidVal.Data3)
  return DBVariantCmpCode__ok__less;

 if(v2.guidVal.Data3<v1.guidVal.Data3)
  return DBVariantCmpCode__ok__great;

 assert(v1.guidVal.Data3==v2.guidVal.Data3);

 //---------------
 auto p1=std::begin(v1.guidVal.Data4);
 auto e1=std::end(v1.guidVal.Data4);

 auto p2=std::begin(v2.guidVal.Data4);

 for(;p1!=e1;++p1,++p2)
 {
  if((*p1)<(*p2))
   return DBVariantCmpCode__ok__less;

  if((*p2)<(*p1))
   return DBVariantCmpCode__ok__great;

  assert((*p1)==(*p2));
 }//for

 return DBVariantCmpCode__ok__equal;
}//compare_values

////////////////////////////////////////////////////////////////////////////////
