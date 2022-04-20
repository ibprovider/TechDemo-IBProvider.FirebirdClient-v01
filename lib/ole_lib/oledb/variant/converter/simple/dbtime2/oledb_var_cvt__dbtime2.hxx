////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_DBTIME2.
//                                                 Kovalenko Dmitry. 08.09.2010
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime2,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime2,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime2,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime2,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime2,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime2,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime2,wstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtime2,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(dbtime2)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(dbtime2,array_ui1)

////////////////////////////////////////////////////////////////////////////////
