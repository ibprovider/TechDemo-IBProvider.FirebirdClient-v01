////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->bool implementation.
//                                                     Roman Piminov, 12.03.2008
////////////////////////////////////////////////////////////////////////////////

const char OLEDB_TYPE_CONVERTER_NAME(str,bool)::sm_tmpl__true[]
 ={'t','r','u','e'};

const char OLEDB_TYPE_CONVERTER_NAME(str,bool)::sm_tmpl__false[]
 ={'f','a','l','s','e'};

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,bool)::internal__convert_value_to_bool
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_STR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 CHECK_READ_PTR(dbvar.strVal.ptr,dbvar.strVal.byte_count());

 const char*        s=dbvar.strVal.ptr;
 const char* const _e=s+dbvar.strVal.length();

 s=structure::miss_space2(s,_e);

 bool res=false;

 if(structure::test_prefix
    (s,_e,sm_tmpl__true,_END_(sm_tmpl__true),structure::t_latin_equal_i<char>())==_END_(sm_tmpl__true))
 {
  s+=_DIM_(sm_tmpl__true);

  res=true;
 }
 else
 if(structure::test_prefix
    (s,_e,sm_tmpl__false,_END_(sm_tmpl__false),structure::t_latin_equal_i<char>())==_END_(sm_tmpl__false))
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
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,bool)

////////////////////////////////////////////////////////////////////////////////
