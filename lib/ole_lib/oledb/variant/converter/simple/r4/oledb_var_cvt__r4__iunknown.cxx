////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R4->IUnknown implementation.
//                                                  Kovalenko Dmitry, 24.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r4,iunknown)::internal__convert_value_to_iunknown
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             REFIID               result_iid,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_R4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 typedef t_oledb_type_cvt_impl_helper impl_helper;

 if(impl_helper::IsRequestOf_IBP_SEQ_STREAM_WC(result_iid))
 {
  return impl_helper::Create_IBP_SEQ_STREAM_WC(pConvCtx,
                                               dbvar,
                                               result);
 }//if WideChar

 if(impl_helper::IsRequestOf_IBP_SEQ_STREAM_MBC(result_iid))
 {
  return impl_helper::Create_IBP_SEQ_STREAM_MBC(pConvCtx,
                                                dbvar,
                                                result);
 }//if MBC

 //default stream
 return impl_helper::Create_DEFAULT_SEQ_STREAM(sizeof(dbvar.valR4),
                                               &dbvar.valR4,
                                               result_iid,
                                               result);
}//internal__convert_value_to_iunknown

//------------------------------------------------------------------------
bool OLEDB_TYPE_CONVERTER_NAME(r4,iunknown)::CanConvertTo
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBBINDING&     Bind)const
{
 assert(OLEDB_EXTRACT_DBTYPE(Bind.wType)==DBTYPE_IUNKNOWN);

 if(Bind.pObject==NULL)
  return true;

 if(Bind.pObject->dwFlags!=STGM_READ)
  return false;

 typedef t_oledb_type_cvt_impl_helper impl_helper;

 if(impl_helper::IsRequestOf_IBP_SEQ_STREAM_WC(Bind.pObject->iid))
  return true;

 if(impl_helper::IsRequestOf_IBP_SEQ_STREAM_MBC(Bind.pObject->iid))
  return true;

 if(impl_helper::IsRequestOf_DEFAULT_SEQ_STREAM(Bind.pObject->iid))
  return true;

 return false;
}//CanConvertTo

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r4,iunknown)

////////////////////////////////////////////////////////////////////////////////
