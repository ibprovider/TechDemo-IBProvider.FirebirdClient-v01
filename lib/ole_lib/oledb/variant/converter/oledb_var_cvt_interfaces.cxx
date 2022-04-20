////////////////////////////////////////////////////////////////////////////////

#define DEFINE_OLEDB_TYPE_CONVERTER__TO(TT)                                    \
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(TT)::to_##TT                            \
                                           (LPCCONVCONTEXT const pConvCtx,     \
                                            const DBVARIANT&     dbvar,        \
                                            result_type*   const result)const  \
{                                                                              \
 switch(dbvar.GetDataStatus())                                                 \
 {                                                                             \
  case DBSTATUS_S_OK:                                                          \
   return this->internal__convert_value_to_##TT(pConvCtx,dbvar,result);        \
                                                                               \
  case DBSTATUS_S_ISNULL:                                                      \
   return this->helper__convert_null_to_##TT(result);                          \
 }                                                                             \
                                                                               \
 return DB_E_BADSTATUSVALUE;                                                   \
}

////////////////////////////////////////////////////////////////////////////////
//to I1

DEFINE_OLEDB_TYPE_CONVERTER__TO(i1)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(i1)::helper__convert_null_to_i1
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_i1

////////////////////////////////////////////////////////////////////////////////
//to I2

DEFINE_OLEDB_TYPE_CONVERTER__TO(i2)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(i2)::helper__convert_null_to_i2
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_i2

////////////////////////////////////////////////////////////////////////////////
//to I4

DEFINE_OLEDB_TYPE_CONVERTER__TO(i4)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(i4)::helper__convert_null_to_i4
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_i4

////////////////////////////////////////////////////////////////////////////////
//to I8

DEFINE_OLEDB_TYPE_CONVERTER__TO(i8)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(i8)::helper__convert_null_to_i8
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_i8

////////////////////////////////////////////////////////////////////////////////
//to UI1

DEFINE_OLEDB_TYPE_CONVERTER__TO(ui1)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(ui1)::helper__convert_null_to_ui1
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_ui1

////////////////////////////////////////////////////////////////////////////////
//to UI2

DEFINE_OLEDB_TYPE_CONVERTER__TO(ui2)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(ui2)::helper__convert_null_to_ui2
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_ui2

////////////////////////////////////////////////////////////////////////////////
//to UI4

DEFINE_OLEDB_TYPE_CONVERTER__TO(ui4)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(ui4)::helper__convert_null_to_ui4
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_ui4

////////////////////////////////////////////////////////////////////////////////
//to UI8

DEFINE_OLEDB_TYPE_CONVERTER__TO(ui8)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(ui8)::helper__convert_null_to_ui8
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_ui8

////////////////////////////////////////////////////////////////////////////////
//to R4

DEFINE_OLEDB_TYPE_CONVERTER__TO(r4)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(r4)::helper__convert_null_to_r4
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_r4

////////////////////////////////////////////////////////////////////////////////
//to R8

DEFINE_OLEDB_TYPE_CONVERTER__TO(r8)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(r8)::helper__convert_null_to_r8
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_r8

////////////////////////////////////////////////////////////////////////////////
//to CY

DEFINE_OLEDB_TYPE_CONVERTER__TO(cy)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(cy)::helper__convert_null_to_cy
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_cy

////////////////////////////////////////////////////////////////////////////////
//to DECIMAL

DEFINE_OLEDB_TYPE_CONVERTER__TO(decimal)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(decimal)::helper__convert_null_to_decimal
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_decimal

////////////////////////////////////////////////////////////////////////////////
//to NUMERIC

DEFINE_OLEDB_TYPE_CONVERTER__TO(numeric)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(numeric)::helper__convert_null_to_numeric
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_numeric

////////////////////////////////////////////////////////////////////////////////
//to DATE

DEFINE_OLEDB_TYPE_CONVERTER__TO(date)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(date)::helper__convert_null_to_date
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_date

////////////////////////////////////////////////////////////////////////////////
//to FILETIME

DEFINE_OLEDB_TYPE_CONVERTER__TO(filetime)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(filetime)::helper__convert_null_to_filetime
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_filetime

////////////////////////////////////////////////////////////////////////////////
//to DBDATE

DEFINE_OLEDB_TYPE_CONVERTER__TO(dbdate)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(dbdate)::helper__convert_null_to_dbdate
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_dbdate

////////////////////////////////////////////////////////////////////////////////
//to DBTIME

DEFINE_OLEDB_TYPE_CONVERTER__TO(dbtime)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(dbtime)::helper__convert_null_to_dbtime
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_dbtime

////////////////////////////////////////////////////////////////////////////////
//to DBTIME2

DEFINE_OLEDB_TYPE_CONVERTER__TO(dbtime2)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(dbtime2)::helper__convert_null_to_dbtime2
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_dbtime2

////////////////////////////////////////////////////////////////////////////////
//to DBTIMESTAMP

DEFINE_OLEDB_TYPE_CONVERTER__TO(dbtimestamp)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(dbtimestamp)::helper__convert_null_to_dbtimestamp
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_dbtimestamp

////////////////////////////////////////////////////////////////////////////////
//to STR

DEFINE_OLEDB_TYPE_CONVERTER__TO(str)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(str)::helper__convert_null_to_str
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_str

////////////////////////////////////////////////////////////////////////////////
//to WSTR

DEFINE_OLEDB_TYPE_CONVERTER__TO(wstr)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(wstr)::helper__convert_null_to_wstr
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_wstr

////////////////////////////////////////////////////////////////////////////////
//to BSTR

DEFINE_OLEDB_TYPE_CONVERTER__TO(bstr)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(bstr)::helper__convert_null_to_bstr
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_bstr

////////////////////////////////////////////////////////////////////////////////
//to ERROR

DEFINE_OLEDB_TYPE_CONVERTER__TO(error)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(error)::helper__convert_null_to_error
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_error

////////////////////////////////////////////////////////////////////////////////
//to BOOL

DEFINE_OLEDB_TYPE_CONVERTER__TO(bool)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(bool)::helper__convert_null_to_bool
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_bool

////////////////////////////////////////////////////////////////////////////////
//to GUID

DEFINE_OLEDB_TYPE_CONVERTER__TO(guid)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(guid)::helper__convert_null_to_guid
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_guid

////////////////////////////////////////////////////////////////////////////////
//to BYTES

DEFINE_OLEDB_TYPE_CONVERTER__TO(bytes)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(bytes)::helper__convert_null_to_bytes
                                           (result_type* const DEBUG_CODE(result))
{
 assert(result);

 return S_FALSE;
}//helper__convert_null_to_bytes

////////////////////////////////////////////////////////////////////////////////
//to VARIANT

DEFINE_OLEDB_TYPE_CONVERTER__TO(variant)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(variant)::helper__convert_null_to_variant
                                           (result_type* const result)
{
 assert(result);

 const HRESULT clear_hr=ole_lib::Variant_Clear(result);

 if(FAILED(clear_hr))
  return E_FAIL;

 assert(clear_hr==S_OK);

 assert(result->vt==VT_EMPTY);

 result->vt=VT_NULL;

 return S_FALSE;
}//helper__convert_null_to_variant

////////////////////////////////////////////////////////////////////////////////
//to IDISPATCH

DEFINE_OLEDB_TYPE_CONVERTER__TO(idispatch)

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(idispatch)::helper__convert_null_to_idispatch
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_idispatch

////////////////////////////////////////////////////////////////////////////////
//to IUNKNOWN

HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(iunknown)::to_iunknown
                                           (LPCCONVCONTEXT const pConvCtx,
                                            const DBVARIANT&     dbvar,
                                            REFIID               result_iid,
                                            result_type*   const result)const
{
 switch(dbvar.GetDataStatus())
 {
  case DBSTATUS_S_OK:
  {
   return this->internal__convert_value_to_iunknown
           (pConvCtx,
            dbvar,
            result_iid,
            result);
  }//case DBSTATUS_S_OK

  case DBSTATUS_S_ISNULL:
  {
   return this->helper__convert_null_to_iunknown(result);
  }//case DBSTATUS_S_ISNULL
 }//switch

 return DB_E_BADSTATUSVALUE;
}//to_iunknown

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(iunknown)::helper__convert_null_to_iunknown
                                           (result_type* const result)
{
 assert(result);

 result->reset();

 return S_OK;
}//helper__convert_null_to_iunknown

////////////////////////////////////////////////////////////////////////////////
//to ARRAY

HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(array)::to_array
                                           (LPCCONVCONTEXT const pConvCtx,
                                            const DBVARIANT&     dbvar,
                                            REFIID               result_iid,
                                            result_type*   const result)const
{
 switch(dbvar.GetDataStatus())
 {
  case DBSTATUS_S_OK:
  {
   return this->internal__convert_value_to_array
           (pConvCtx,
            dbvar,
            result_iid,
            result);
  }//case DBSTATUS_S_OK

  case DBSTATUS_S_ISNULL:
  {
   return this->helper__convert_null_to_array(result);
  }//case DBSTATUS_S_ISNULL
 }//switch

 return DB_E_BADSTATUSVALUE;
}//to_array

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_INTERFACE(array)::helper__convert_null_to_array
                                           (result_type* const result)
{
 assert(result);

 (*result)=nullptr;

 return S_FALSE;
}//helper__convert_null_to_array

////////////////////////////////////////////////////////////////////////////////

#undef DEFINE_OLEDB_TYPE_CONVERTER__TO

////////////////////////////////////////////////////////////////////////////////
