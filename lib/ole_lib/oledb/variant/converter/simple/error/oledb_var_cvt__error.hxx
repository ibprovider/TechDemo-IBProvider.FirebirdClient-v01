////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_ERROR.
//                                                     Roman Piminov, 09.04.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(error,error)

DECLARE_OLEDB_TYPE_CONVERTER_V3(error,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(error,ui4)

DECLARE_OLEDB_TYPE_CONVERTER_V3(error,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(error,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(error)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(error,array_ui1)

////////////////////////////////////////////////////////////////////////////////
