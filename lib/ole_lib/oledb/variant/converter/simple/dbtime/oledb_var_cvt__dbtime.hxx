////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_DBTIME.
//                                                     Roman Piminov, 11.04.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime,wstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(dbtime)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(dbtime,array_ui1)

////////////////////////////////////////////////////////////////////////////////
