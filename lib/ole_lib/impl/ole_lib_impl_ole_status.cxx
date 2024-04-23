////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//class TOleStatus

TOleStatus::TOleStatus()
 :m_last_result(NOERROR)
{;}

//------------------------------------------------------------------------
TOleStatus::TOleStatus(const self_type& x)
 :m_text(x.m_text)
 ,m_last_result(x.m_last_result)
{;}

//------------------------------------------------------------------------
HRESULT TOleStatus::set_msg(EXCEPINFO* pExcepInfo)
{
 if(m_last_result==DISP_E_EXCEPTION && pExcepInfo!=NULL)
  m_text=BStrToString(pExcepInfo->bstrDescription);
 else
  m_text.erase();

 return m_last_result;
}//set_msg

//------------------------------------------------------------------------
HRESULT TOleStatus::set_disp_error(HRESULT hr,bool use_error_info,const std::string& verb)
{
 m_last_result=hr;

 m_text=verb;

 if(!m_text.empty())
  m_text+='\n';

 if(hr==NOERROR)
 {
  m_text+="no error";
 }
 else
 if(use_error_info)
 {
  OLE_LIB__DECLARE_IPTR_TYPE(IErrorInfo);

  IErrorInfoPtr spErrorInfo;

  if(LCPI_OS__GetErrorInfo(0,&spErrorInfo.ref_ptr())==NOERROR && spErrorInfo)
  {
   TBSTR bstr;

   spErrorInfo->GetDescription(&bstr.ref_bstr());

   m_text+='\n';
   m_text+=bstr.str();
  }
 }//else-if

 return m_last_result;
}//set_disp_error

//------------------------------------------------------------------------
HRESULT TOleStatus::set_disp_error(HRESULT hr)
{
 return set_disp_error(hr,true,std::string());
}//set_disp_error

//------------------------------------------------------------------------
HRESULT TOleStatus::set_error(HRESULT hr,const std::string& verb)
{
 m_text=verb;
 return m_last_result=hr;
}//set_error

//------------------------------------------------------------------------
HRESULT TOleStatus::set_error(HRESULT hr)
{
 m_text.erase();

 return m_last_result=hr;
}//set_error

//------------------------------------------------------------------------
std::string TOleStatus::get_msg()const
{
 t_string msg(structure::tstr_to_tstr(this->get_text()));

 if(msg.empty())
  msg=win32lib::GetErrorMsg(DWORD(m_last_result),false);

 if(!msg.empty())
  msg+=_T("\n\n");

 msg.append(_T("COM Error Code: ")).append(ole_lib::TestHResult(m_last_result));

 return structure::tstr_to_str(msg);
}//get_msg

//------------------------------------------------------------------------
const std::string& TOleStatus::add_msg(const std::string& msg)
{
 if(!m_text.empty())
  m_text+='\n';

 return m_text+=msg;
}//add_msg

//------------------------------------------------------------------------
std::string TOleStatus::TestHResult(HRESULT hr) const
{
 return structure::tstr_to_str(ole_lib::TestHResult(hr));
}//TestHResult

////////////////////////////////////////////////////////////////////////////////

