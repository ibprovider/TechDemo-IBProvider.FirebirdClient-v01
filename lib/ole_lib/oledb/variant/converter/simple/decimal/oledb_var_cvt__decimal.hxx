////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_DECIMAL.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,wstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(decimal,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(decimal)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(decimal,array_ui1)

////////////////////////////////////////////////////////////////////////////////
