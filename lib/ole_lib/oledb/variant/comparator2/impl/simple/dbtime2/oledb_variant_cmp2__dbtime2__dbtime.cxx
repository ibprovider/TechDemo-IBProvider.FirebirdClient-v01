////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DBTIME2,DBTIME)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DBTIME2,DBTIME)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==oledb_typeid__DBTIME2);
 assert(v2.wType==oledb_typeid__DBTIME);

 const_cast<const oledb_lib::t_oledb_value__DBTIME2*>(&v1.dbtime2Val);
 const_cast<const oledb_lib::t_oledb_value__DBTIME*> (&v2.dbtimeVal);

 //-----------
 if(v1.dbtime2Val.hour<v2.dbtimeVal.hour)
  return DBVariantCmpCode__ok__less;

 if(v2.dbtimeVal.hour<v1.dbtime2Val.hour)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbtime2Val.hour==v2.dbtimeVal.hour);

 //-----------
 if(v1.dbtime2Val.minute<v2.dbtimeVal.minute)
  return DBVariantCmpCode__ok__less;

 if(v2.dbtimeVal.minute<v1.dbtime2Val.minute)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbtime2Val.minute==v2.dbtimeVal.minute);

 //-----------
 if(v1.dbtime2Val.second<v2.dbtimeVal.second)
  return DBVariantCmpCode__ok__less;

 if(v2.dbtimeVal.second<v1.dbtime2Val.second)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbtime2Val.second==v2.dbtimeVal.second);

 //-----------
 if(v1.dbtime2Val.fraction==0)
  return DBVariantCmpCode__ok__equal;

 assert(v1.dbtime2Val.fraction>0);

 return DBVariantCmpCode__ok__great;
}//compare_values

////////////////////////////////////////////////////////////////////////////////
