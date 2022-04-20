////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_DBTIMESTAMP.
//                                                     Roman Piminov, 11.04.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtimestamp,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtimestamp,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtimestamp,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtimestamp,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtimestamp,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtimestamp,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtimestamp,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtimestamp,wstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtimestamp,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbtimestamp,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(dbtimestamp,array_ui1)

////////////////////////////////////////////////////////////////////////////////
