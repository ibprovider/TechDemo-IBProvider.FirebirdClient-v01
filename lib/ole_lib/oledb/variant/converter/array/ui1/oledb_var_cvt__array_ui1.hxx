////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_ARRAY|DBTYPE_UI1.
//                                                  Dmitry Kovalenko, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,error)

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,guid)

DECLARE_OLEDB_TYPE_CONVERTER_V3(array_ui1,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(array_ui1)

////////////////////////////////////////////////////////////////////////////////
