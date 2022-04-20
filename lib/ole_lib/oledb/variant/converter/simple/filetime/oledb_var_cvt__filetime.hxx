////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_FILETIME.
//                                                 Kovalenko Dmitry, 25.04.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(filetime,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(filetime,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(filetime,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(filetime,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(filetime,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(filetime,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(filetime,str)

DECLARE_OLEDB_TYPE_CONVERTER_V3(filetime,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(filetime,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(filetime)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(filetime,array_ui1)

////////////////////////////////////////////////////////////////////////////////
