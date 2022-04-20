////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_DATE.
//                                                     Roman Piminov, 03.04.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(date,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(date,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(date,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(date,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(date,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(date,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(date,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(date,str)

DECLARE_OLEDB_TYPE_CONVERTER_V3(date,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(date,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(date)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(date,array_ui1)

////////////////////////////////////////////////////////////////////////////////
