////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//class t_base_ole_error

t_base_ole_error::t_base_ole_error(HRESULT const code)
 :inherited(code)
{;}

//------------------------------------------------------------------------
t_base_ole_error::t_base_ole_error(HRESULT      const code,
                                   str_box_type const text)
 :inherited(code)
 ,m_text(text.begin(),text.end())
{;}

//------------------------------------------------------------------------
t_base_ole_error::t_base_ole_error(const self_type& exc)
 :inherited(exc)
 ,m_text(exc.m_text)
{;}

//------------------------------------------------------------------------
t_base_ole_error::~t_base_ole_error() __STL_EXCEPTION_DCR_THROW_SPEC
{;}

//------------------------------------------------------------------------
void t_base_ole_error::throw_error(HRESULT const code)
{
 throw self_type(code);
}//throw_error

//------------------------------------------------------------------------
void t_base_ole_error::throw_error(HRESULT      const code,
                                   str_box_type const text)
{
 throw self_type(code,text);
}//throw_error

//------------------------------------------------------------------------
const char* t_base_ole_error::what()const __STL_EXCEPTION_WHAT_THROW_SPEC
{
 return m_text.c_str();
}//what

//------------------------------------------------------------------------
void t_base_ole_error::raise()const //throw
{
 throw *this;
}//raise

//------------------------------------------------------------------------
#if(OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO!=0)

HRESULT t_base_ole_error::set_error_info(REFIID exc_riid)const
{
 DECLARE_IPTR_TYPE(ICreateErrorInfo);
 DECLARE_IPTR_TYPE(IErrorInfo);

 ICreateErrorInfoPtr spCreateErrorInfo;

 {
  const HRESULT hr=::CreateErrorInfo(&spCreateErrorInfo.ref_ptr());

  if(FAILED(hr))
   return hr;
 }//local

 if(!spCreateErrorInfo)
  return E_OUTOFMEMORY;

 if(spCreateErrorInfo->SetGUID(exc_riid)!=S_OK)
  return E_FAIL;

 //
 // [2020-05-28]
 //  ICreateErrorInfo::SetDescription принимает строку в виде LPOLESTR!
 //  ј мы тут 20 лет создавали и передавали BSTR.
 //
 //  ATTENTION: NOT TESTED!
 //
 // [2020-09-02]
 //  «адействуем const_cast дл€ решени€ проблем с VS2013
 //
 std::wstring
  wstrDescription
   =structure::tstr_to_wstr(this->text());

 if(spCreateErrorInfo->SetDescription(const_cast<LPOLESTR>(wstrDescription.c_str()))!=S_OK)
  return E_FAIL;

 assert(spCreateErrorInfo.unk_ptr());

 const IErrorInfoPtr
  spErrorInfo(structure::not_null_ptr(spCreateErrorInfo.unk_ptr()));

 if(FAILED(spErrorInfo.m_hr))
  return spErrorInfo.m_hr;

 assert(spErrorInfo);

 return ::SetErrorInfo(0L,spErrorInfo);
}//set_error_info

#endif

////////////////////////////////////////////////////////////////////////////////
