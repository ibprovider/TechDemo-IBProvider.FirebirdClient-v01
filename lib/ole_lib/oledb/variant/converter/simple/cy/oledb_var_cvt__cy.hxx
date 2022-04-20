////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_CY.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,str)

DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(cy,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(cy)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(cy,array_ui1)

////////////////////////////////////////////////////////////////////////////////
