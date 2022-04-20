////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_DBDATE.
//                                                     Roman Piminov, 11.04.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbdate,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbdate,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbdate,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbdate,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbdate,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbdate,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbdate,wstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbdate,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbdate,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(dbdate)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(dbdate,array_ui1)

////////////////////////////////////////////////////////////////////////////////
