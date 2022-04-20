////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_WSTR.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3__BEG(wstr,bool)
 private:
  static const wchar_t sm_tmpl__true[];
  static const wchar_t sm_tmpl__false[];
DECLARE_OLEDB_TYPE_CONVERTER_V3__END()

DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,guid)

DECLARE_OLEDB_TYPE_CONVERTER_V3(wstr,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(wstr)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(wstr,array_ui1)

////////////////////////////////////////////////////////////////////////////////
