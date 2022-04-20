////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->bool implementation.
//                                                     Roman Piminov, 12.03.2008
////////////////////////////////////////////////////////////////////////////////

const wchar_t OLEDB_TYPE_CONVERTER_NAME(wstr,bool)::sm_tmpl__true[]
 ={L't',L'r',L'u',L'e'};

const wchar_t OLEDB_TYPE_CONVERTER_NAME(wstr,bool)::sm_tmpl__false[]
 ={L'f',L'a',L'l',L's',L'e'};

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,bool)::internal__convert_value_to_bool
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_WSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 CHECK_READ_PTR(dbvar.wstrVal.ptr,dbvar.wstrVal.byte_count());

 const wchar_t*        s=dbvar.wstrVal.ptr;
 const wchar_t* const _e=s+dbvar.wstrVal.length();

 s=structure::miss_space2(s,_e);

 bool res=false;

 if(structure::test_prefix
    (s,_e,sm_tmpl__true,_END_(sm_tmpl__true),structure::t_latin_equal_i<wchar_t>())==_END_(sm_tmpl__true))
 {
  s+=_DIM_(sm_tmpl__true);

  res=true;
 }
 else
 if(structure::test_prefix
    (s,_e,sm_tmpl__false,_END_(sm_tmpl__false),structure::t_latin_equal_i<wchar_t>())==_END_(sm_tmpl__false))
 {
  s+=_DIM_(sm_tmpl__false);

  res=false;
 }
 else
 {
  return DB_E_CANTCONVERTVALUE;
 }

 s=structure::miss_space2(s,_e);

 if(s!=_e)
  return DB_E_CANTCONVERTVALUE;

 (*result)=res;

 return S_OK;
}//internal__convert_value_to_bool

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,bool)

////////////////////////////////////////////////////////////////////////////////
