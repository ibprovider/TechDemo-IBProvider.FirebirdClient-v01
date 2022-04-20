////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_BYTES.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,error)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,guid)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bytes,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(bytes)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(bytes,array_ui1)

////////////////////////////////////////////////////////////////////////////////
