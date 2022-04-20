////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_UI1.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui1,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(ui1)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(ui1,array_ui1)

////////////////////////////////////////////////////////////////////////////////
