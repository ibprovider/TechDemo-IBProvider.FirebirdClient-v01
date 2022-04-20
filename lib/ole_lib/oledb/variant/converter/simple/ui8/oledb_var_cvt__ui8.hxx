////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_UI8.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(ui8,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(ui8)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(ui8,array_ui1)

////////////////////////////////////////////////////////////////////////////////
