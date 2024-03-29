////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//class t_ole_error

t_ole_error::t_ole_error(const self_type& exc)
 :inherited(exc)
 ,m_what_arg(exc.m_what_arg)
{
}

//------------------------------------------------------------------------
t_ole_error::t_ole_error(HRESULT      const hr,
                         str_box_type const what_arg,
                         str_box_type const text)
 :inherited(hr,text)
 ,m_what_arg(what_arg.begin(),what_arg.end())
{
}

//------------------------------------------------------------------------
t_ole_error::t_ole_error(const TOleStatus& status)
 :inherited(status.m_last_result,status.get_text())
 ,m_what_arg(status.get_msg())
{
}

//------------------------------------------------------------------------
t_ole_error::~t_ole_error() LCPI_STL_EXCEPTION_DCR_THROW_SPEC
{
}

//------------------------------------------------------------------------
const char* t_ole_error::what() const LCPI_STL_EXCEPTION_WHAT_THROW_SPEC
{
 return m_what_arg.c_str();
}//what

//------------------------------------------------------------------------
void t_ole_error::raise()const
{
 throw *this;
}//raise

//------------------------------------------------------------------------
void t_ole_error::generate(HRESULT      const hr,
                           str_box_type const what_arg,
                           str_box_type const text)
{
 throw self_type(hr,what_arg,text);
}//generate

//------------------------------------------------------------------------
void t_ole_error::generate(const TOleStatus& status)
{
 throw self_type(status);
}//generate

//------------------------------------------------------------------------
void t_ole_error::throw_error(HRESULT      const hr,
                              str_box_type const verb)
{
 std::string what_arg(verb.make_str());

 const std::string err_text(structure::tstr_to_str(win32lib::GetErrorMsg(DWORD(hr),false)));

 self_type::helper__append_line(&what_arg,err_text);

 self_type::helper__append_com_error_code(&what_arg,hr);

 self_type::generate(hr,
                     structure::tstr_to_str(what_arg),
                     str_box_type());
}//throw_error

//------------------------------------------------------------------------
void t_ole_error::throw_error(HRESULT const hr)
{
 self_type::throw_error(hr,str_box_type());
}//throw_error

//------------------------------------------------------------------------
void t_ole_error::throw_disp_error(HRESULT      const hr,
                                   str_box_type const verb)
{
 //build text ------------------------------
 std::string text(verb.make_str());

 OLE_LIB__DECLARE_IPTR_TYPE(IErrorInfo);

 IErrorInfoPtr spErrorInfo;

 std::string err_text;

 if(LCPI_OS__GetErrorInfo(0,&spErrorInfo.ref_ptr())==NOERROR)
 {
  if(spErrorInfo)
  {
   TBSTR bstr;

   if(spErrorInfo->GetDescription(&bstr.ref_bstr())==S_OK)
   {
    structure::tstr_to_tstr(&err_text,structure::total_trim(bstr.tstr()));
   }
  }//if spErrorInfo
 }//if

 self_type::helper__append_line(&text,err_text);

 //build what_args -------------------------
 std::string what_arg(verb.make_str());

 if(err_text.empty())
 {
  structure::tstr_to_tstr(&err_text,win32lib::GetErrorMsg(DWORD(hr),false));
 }//if

 self_type::helper__append_line(&what_arg,err_text);

 self_type::helper__append_com_error_code(&what_arg,hr);

 self_type::generate(hr,what_arg,text);
}//throw_disp_error

//------------------------------------------------------------------------
void t_ole_error::throw_disp_error(HRESULT const hr)
{
 self_type::throw_disp_error(hr,str_box_type());
}//throw_disp_error

//------------------------------------------------------------------------
void t_ole_error::helper__append_line(std::string* const result,
                                      const std::string& line)
{
 assert(result!=nullptr);

 if(line.empty())
  return;

 if(!result->empty())
  (*result)+="\n";

 (*result)+=line; 
}//helper__append_line

//------------------------------------------------------------------------
void t_ole_error::helper__append_com_error_code(std::string* const what_arg,
                                                HRESULT      const hr)
{
 assert(what_arg!=nullptr);

 if(!what_arg->empty())
  (*what_arg)+="\n\n";

 what_arg->append("COM Error Code: ").append(structure::tstr_to_str(TestHResult(hr)));
}//helper__append_com_error_code

////////////////////////////////////////////////////////////////////////////////
