////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_BOOL.
//                                                     Roman Piminov, 11.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,str)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bool,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(bool)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(bool,array_ui1)

////////////////////////////////////////////////////////////////////////////////
