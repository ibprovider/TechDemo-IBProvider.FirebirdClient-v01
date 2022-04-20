////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DBTIME,DBTIME2)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DBTIME,DBTIME2)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==oledb_typeid__DBTIME);
 assert(v2.wType==oledb_typeid__DBTIME2);

 const_cast<const oledb_lib::t_oledb_value__DBTIME*> (&v1.dbtimeVal);
 const_cast<const oledb_lib::t_oledb_value__DBTIME2*>(&v2.dbtime2Val);

 //-----------
 if(v1.dbtimeVal.hour<v2.dbtime2Val.hour)
  return DBVariantCmpCode__ok__less;

 if(v2.dbtime2Val.hour<v1.dbtimeVal.hour)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbtimeVal.hour==v2.dbtime2Val.hour);

 //-----------
 if(v1.dbtimeVal.minute<v2.dbtime2Val.minute)
  return DBVariantCmpCode__ok__less;

 if(v2.dbtime2Val.minute<v1.dbtimeVal.minute)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbtimeVal.minute==v2.dbtime2Val.minute);

 //-----------
 if(v1.dbtimeVal.second<v2.dbtime2Val.second)
  return DBVariantCmpCode__ok__less;

 if(v2.dbtime2Val.second<v1.dbtimeVal.second)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbtimeVal.second==v2.dbtime2Val.second);

 //-----------
 if(v2.dbtime2Val.fraction==0)
  return DBVariantCmpCode__ok__equal;

 assert(v2.dbtime2Val.fraction>0);

 return DBVariantCmpCode__ok__less;
}//compare_values

////////////////////////////////////////////////////////////////////////////////
