////////////////////////////////////////////////////////////////////////////////
//DBVARIAT_CVT_UTILS implementation. CY services.
//                                              Kovalenko Dmitry. 24.08.2003.

////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT_CVT_UTILS

const signed __int64 DBVARIANT_CVT_UTILS::tag_data::sm_min_cy_int64
 =(-922337203685477i64);

const signed __int64 DBVARIANT_CVT_UTILS::tag_data::sm_max_cy_int64
 =(922337203685477i64);

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::IntToCY(signed __int64 const value,tagCY& cy)
{
 cy=__null_cy__;

 if(value<tag_data::sm_min_cy_int64 || value>tag_data::sm_max_cy_int64)
  return TDBTypeConverterCode::numeric_overflow;

 cy.int64=value*oledb_cy_fraction_part_mult;

 return S_OK;
}//IntToCY

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::IntToCY(unsigned __int64 const value,tagCY& cy)
{
 cy=__null_cy__;

 if(value>tag_data::sm_max_cy_int64)
  return TDBTypeConverterCode::numeric_overflow;

 cy.int64=value*oledb_cy_fraction_part_mult;

 return S_OK;
}//IntToCY

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::R8ToCY(double const value,tagCY& cy)
{
 cy=__null_cy__;

 if(value<tag_data::sm_min_cy_int64 || value>tag_data::sm_max_cy_int64)
  return TDBTypeConverterCode::numeric_overflow;

 cy.int64=static_cast<LONGLONG>(value*oledb_cy_fraction_part_mult);

 return S_OK;
}//R8ToCY

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::StrToCY(const char* const str,
                                     size_type   const str_size,
                                     tagCY*      const pValue)
{
 assert(pValue);

 (*pValue)=__null_cy__;

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::StrToNumeric(str,str_size,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToCY(dbnum,pValue);
}//StrToCY

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::WStrToCY(const wchar_t* const str,
                                      size_type      const str_size,
                                      tagCY*         const pValue)
{
 assert(pValue);

 (*pValue)=__null_cy__;

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::WStrToNumeric(str,str_size,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToCY(dbnum,pValue);
}//WStrToCY

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::BoolToCY(VARIANT_BOOL const value,tagCY& cy)
{
 cy.int64=value?oledb_cy_fraction_part_mult:0;

 return S_OK;
}//BoolToCY

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::CYToInt(const tagCY& cy,signed __int64& digit)
{
 digit=0;

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::CYToNumeric(cy,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToInt(dbnum,&digit);
}//CYToInt

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::CYToInt(const tagCY& cy,unsigned __int64& digit)
{
 digit=0;

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::CYToNumeric(cy,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToInt(dbnum,&digit);
}//CYToInt

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::CYToR4(const tagCY& cy,float& digit)
{
 digit=0;

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::CYToNumeric(cy,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToR4(dbnum,&digit);
}//CYToR4

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::CYToR8(const tagCY& cy,double& digit)
{
 digit=0;

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::CYToNumeric(cy,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToR8(dbnum,&digit);
}//CYToR8

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::CYToStr(const tagCY& cy,std::string& str)
{
 str.erase();

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::CYToNumeric(cy,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToString(dbnum,&str);
}//CYToStr

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::CYToWStr(const tagCY& cy,std::wstring& str)
{
 str.erase();

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::CYToNumeric(cy,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToString(dbnum,&str);
}//CYToWStr

//------------------------------------------------------------------------
std::string DBVARIANT_CVT_UTILS::CYToStr(const tagCY& cy,bool* const error)
{
 std::string s;

 if(FAILED(self_type::CYToStr(cy,s)))
 {
  if(error!=NULL)
   (*error)=true;
 }
 else
 {
  if(error!=NULL)
   (*error)=false;
 }//else

 return s;
}//CYToStr

//------------------------------------------------------------------------
std::wstring DBVARIANT_CVT_UTILS::CYToWStr(const tagCY& cy,bool* const error)
{
 std::wstring s;

 if(FAILED(self_type::CYToWStr(cy,s)))
 {
  if(error!=NULL)
   (*error)=true;
 }
 else
 {
  if(error!=NULL)
   (*error)=false;
 }//else

 return s;
}//CYToWStr

////////////////////////////////////////////////////////////////////////////////
