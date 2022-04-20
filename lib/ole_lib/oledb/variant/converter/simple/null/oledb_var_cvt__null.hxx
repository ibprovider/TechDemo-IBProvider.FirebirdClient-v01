////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_NULL.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,error)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,guid)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3(dbnull,idispatch)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(dbnull)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(dbnull,array)

////////////////////////////////////////////////////////////////////////////////
