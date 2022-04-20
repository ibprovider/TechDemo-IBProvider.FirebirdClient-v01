////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(BSTR,BSTR)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(BSTR,BSTR)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_BSTR);
 assert(v2.wType==DBTYPE_BSTR);

 const size_t n1=(v1.bstrVal?::SysStringLen(v1.bstrVal):0);
 const size_t n2=(v2.bstrVal?::SysStringLen(v2.bstrVal):0);

 return DBValueComparator::compare__str
         (v1.bstrVal,
          n1,
          v2.bstrVal,
          n2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
