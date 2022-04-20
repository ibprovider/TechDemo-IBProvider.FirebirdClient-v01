////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_EMPTY.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,error)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,wstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,guid)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3(empty,idispatch)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(empty)

////////////////////////////////////////////////////////////////////////////////
//To Array

struct OLEDB_TYPE_CONVERTER_NAME(empty,array):
 public OLEDB_TYPE_CONVERTER_INTERFACE(array)
{
 private:
  typedef OLEDB_TYPE_CONVERTER_NAME(empty,array)                self_type;

  OLEDB_TYPE_CONVERTER_NAME(empty,array)(const self_type&);
  self_type& operator = (const self_type&);

 public:
  OLEDB_TYPE_CONVERTER_NAME(empty,array)(DBTYPE const wToType)
   :m_wToType(wToType)
  {;}

 private:
  virtual HRESULT internal__convert_value_to_array
                          (LPCCONVCONTEXT   pConvCtx,
                           const DBVARIANT& dbvar,
                           REFIID           result_iid,
                           result_type*     result)const COMP_W000004_OVERRIDE_FINAL;
 private:
  const DBTYPE m_wToType;
};

////////////////////////////////////////////////////////////////////////////////
