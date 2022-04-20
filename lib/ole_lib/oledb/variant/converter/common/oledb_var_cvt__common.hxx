////////////////////////////////////////////////////////////////////////////////
//Declare common type converters.
//                                                     Roman Piminov, 17.04.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(common,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(common,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(common,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_common,variant)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V3(array_common,array_copy)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V3_EXT(array_common,array_vt)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V3(array_common,array_str)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V3(array_common,array_wstr)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V3(array_common,array_bytes)

////////////////////////////////////////////////////////////////////////////////
