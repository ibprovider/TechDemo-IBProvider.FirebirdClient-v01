////////////////////////////////////////////////////////////////////////////////
//Declare type converters from DBTYPE_VARIANT.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,error)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,i1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,i2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,i4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,i8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,ui1)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,ui2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,ui4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,ui8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,r4)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,r8)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,cy)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,decimal)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,numeric)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,date)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,filetime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,dbdate)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,dbtime)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,dbtime2)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,dbtimestamp)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,str)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,wstr)
DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,bstr)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,bool)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,guid)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,bytes)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,variant)

DECLARE_OLEDB_TYPE_CONVERTER_V3(variant,idispatch)

DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(variant)

////////////////////////////////////////////////////////////////////////////////
//To Array

struct OLEDB_TYPE_CONVERTER_NAME(variant,array):
 public OLEDB_TYPE_CONVERTER_INTERFACE(array)
{
 private:
  typedef OLEDB_TYPE_CONVERTER_NAME(variant,array)                self_type;

  OLEDB_TYPE_CONVERTER_NAME(variant,array)(const self_type&);
  self_type& operator = (const self_type&);

 public:
  OLEDB_TYPE_CONVERTER_NAME(variant,array)(DBTYPE const wToType)
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
