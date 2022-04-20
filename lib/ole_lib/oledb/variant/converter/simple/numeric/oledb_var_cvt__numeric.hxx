////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_NUMERIC.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,wstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(numeric,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(numeric)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(numeric,array_ui1)

////////////////////////////////////////////////////////////////////////////////
