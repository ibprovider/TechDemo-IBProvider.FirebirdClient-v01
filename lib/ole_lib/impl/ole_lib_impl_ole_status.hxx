////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//TOLEStatus - класс контроля выполнения операции

class TOleStatus
{
 private:
  typedef TOleStatus                          self_type;

  self_type& operator = (const self_type&);

 private:
  std::string m_text;

 public:
  HRESULT m_last_result;

  TOleStatus();

  TOleStatus(const self_type& x);

  HRESULT set_msg(EXCEPINFO* pExcepInfo);

  HRESULT set_msg(EXCEPINFO* pExcepInfo,HRESULT hr)
  {
   m_last_result=hr;
   return set_msg(pExcepInfo);
  }

  HRESULT set_disp_error(HRESULT hr,bool use_error_info,const std::string& verb);

  HRESULT set_disp_error(HRESULT hr); //use_error_info=true

  HRESULT set_error(HRESULT hr,const std::string& verb);

  HRESULT set_error(HRESULT hr);

  const std::string& get_text()const
   {return m_text;}

  std::string get_msg()const; //build string with error_code and error messages

  const std::string& add_msg(const std::string& msg);

 protected:
  virtual std::string TestHResult(HRESULT hr) const;
};//class TOleStatus

////////////////////////////////////////////////////////////////////////////////

