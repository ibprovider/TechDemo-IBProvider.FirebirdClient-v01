////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_BSTR.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3__BEG(bstr,bool)
 private:
  static const wchar_t sm_tmpl__true[];
  static const wchar_t sm_tmpl__false[];
DECLARE_OLEDB_TYPE_CONVERTER_V3__END()

DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,guid)

DECLARE_OLEDB_TYPE_CONVERTER_V3(bstr,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(bstr)

DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(bstr,array_ui1)

////////////////////////////////////////////////////////////////////////////////
