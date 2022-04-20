////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_GUID.
//                                                     Roman Piminov, 09.04.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(guid,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(guid,wstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(guid,guid)

DECLARE_OLEDB_TYPE_CONVERTER_V3(guid,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(guid)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(guid,array_ui1)

////////////////////////////////////////////////////////////////////////////////
