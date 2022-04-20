////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_UI2.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui2,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(ui2)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(ui2,array_ui1)

////////////////////////////////////////////////////////////////////////////////
