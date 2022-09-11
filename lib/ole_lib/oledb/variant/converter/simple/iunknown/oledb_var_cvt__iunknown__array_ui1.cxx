////////////////////////////////////////////////////////////////////////////////
//OLEDB Type converter: IUNKNOWN to ARRAY_UI1
//                                                Kovalenko Dmitry. 20.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,array_ui1)::internal__convert_value_to_array
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             REFIID               /*result_iid*/,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_IUNKNOWN);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=NULL;

 typedef TDBVariantBytesWriter  bytes_type;

 bytes_type Bytes;

 {
  const HRESULT hr=DBVariant__to_BYTES_ex(pConvCtx,
                                          dbvar,
                                          &Bytes);
  if(FAILED(hr))
   return hr;

  assert(hr==S_OK);
 }//local

 typedef unsigned char  byte_type;

 assert(sizeof(byte_type)==1);

 //-----------------------------------------------------------------------
 if(!structure::can_numeric_cast<ULONG>(Bytes.m_buffer.size()))
  return TDBTypeConverterCode::data_overflow;

 SAFEARRAYBOUND bound;

 bound.cElements=static_cast<ULONG>(Bytes.m_buffer.size());
 bound.lLbound  =0;

 ole_lib::TBaseSafeArray sa;

 sa.ref_sa()=LCPI_OS__SafeArrayCreate(VT_UI1,1,&bound);

 if(sa.sa()==NULL)
  return E_FAIL;

 if(Bytes.m_buffer.size()!=0)
 {
  void* pvData=NULL;

  HRESULT const hr
   =LCPI_OS__SafeArrayAccessData(sa,&pvData);

  if(FAILED(hr))
   return E_FAIL;

  assert(hr==S_OK);

  const ole_lib::TSafeArrayAutoUnAccessData sa_auto_unaccess(sa);

  if(pvData==NULL)
   return E_FAIL;

  const bytes_type::buffer_type::size_type
   copy_sz=Bytes.m_buffer.copy_binary(pvData,Bytes.m_buffer.size());

  assert(copy_sz==Bytes.m_buffer.size());

  if(copy_sz!=Bytes.m_buffer.size()) //release code BUG CHECK
   return E_UNEXPECTED;
 }//if

 (*result)=sa.Release();

 return S_OK;
}//internal__convert_value_to_array

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(iunknown,array_ui1)

////////////////////////////////////////////////////////////////////////////////
