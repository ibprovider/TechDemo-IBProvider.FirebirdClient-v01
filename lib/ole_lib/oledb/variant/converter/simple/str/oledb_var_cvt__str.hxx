////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_STR.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(str,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(str,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(str,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(str,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(str,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(str,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(str,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3__BEG(str,bool)
 private:
  static const char sm_tmpl__true[];
  static const char sm_tmpl__false[];
DECLARE_OLEDB_TYPE_CONVERTER_V3__END()

DECLARE_OLEDB_TYPE_CONVERTER_V3(str,guid)

DECLARE_OLEDB_TYPE_CONVERTER_V3(str,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(str)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(str,array_ui1)

////////////////////////////////////////////////////////////////////////////////
