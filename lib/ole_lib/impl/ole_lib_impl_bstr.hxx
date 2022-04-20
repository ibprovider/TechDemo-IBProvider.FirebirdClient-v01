////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//class TBSTR - класс для работы со строками OLE-автоматизации

class TBSTR
{
 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

  typedef UINT                              sys_size_type;

 public:
  class is_bstr
  {
   public:
    BSTR value;

   public:
    explicit is_bstr(BSTR const v)
     :value(v)
    {;}

    size_type length()const;
  };//struct is_bstr

 public: //---------------------------------------------------------------
  TBSTR()
   :m_bstr(NULL)
  {;}

  TBSTR(const TBSTR& bstr) //throw
   :m_bstr(WStrToBStr(bstr.m_bstr,bstr.length(),bstr.m_bstr!=NULL))
  {;}

  TBSTR(is_bstr const bstr)
   :m_bstr(WStrToBStr(bstr.value,bstr.length(),bstr.value!=NULL))
  {;}

  TBSTR(const structure::t_const_str_box& str) //throw
   :m_bstr(StringToBStr(str.data(),str.size(),/*create_empty*/true))
  {;}

  TBSTR(const structure::t_const_wstr_box& str) //throw
   :m_bstr(WStrToBStr(str.data(),str.size(),/*create_empty*/true))
  {;}

 ~TBSTR()
   {this->Free();}

 public: //modificators --------------------------------------------------
  TBSTR& Free();

  TBSTR& swap(TBSTR& x);

  //1. alloc new buffer
  //2. release old buffer
  //3. assign new buffer
  TBSTR& AllocStringLenEx(LPCWSTR str,size_type sz);//throw

  //assign and make bstr=NULL
  TBSTR& AssignBStr(BSTR& bstr);

  //return own BSTR and assign it to NULL
  BSTR   Release();

  TBSTR& SetBStrEx(BSTR bstr); //throw

  TBSTR& SetStr(const structure::t_const_str_box& str); //throw

  TBSTR& SetWStr(const structure::t_const_wstr_box& str); //throw

  TBSTR& operator = (const TBSTR& bstr) //throw
   {return this->SetBStrEx(bstr.m_bstr);}

  TBSTR& operator = (is_bstr bstr) //throw
   {return this->SetBStrEx(bstr.value);}

  TBSTR& operator = (const structure::t_const_str_box& str) //throw
   {return this->SetStr(str);}

  TBSTR& operator = (const structure::t_const_wstr_box& str) //throw
   {return this->SetWStr(str);}

 public://selectors ------------------------------------------------------
  HRESULT GetBStr(BSTR* const bstr)const
   {return CopyBSTR(m_bstr,bstr);}

  std::string    str() const {return ole_lib::BStrToString(m_bstr);}
  std::wstring  wstr() const {return ole_lib::BStrToWStr(m_bstr);}
  t_string      tstr() const {return ole_lib::BStrToTStr(m_bstr);}
  const BSTR&   bstr() const {return m_bstr;}

  BSTR& ref_bstr(bool free=true);

#if 0 //[2020-05-28] Bye
  operator BSTR () const
   {return m_bstr;}

  operator std::string () const
   {return this->str();}

  operator std::wstring () const
   {return this->wstr();}

  bool operator ! () const
   {return m_bstr==NULL;}
#endif

  void copy_to(std::string* const result)const
   {ole_lib::BStrToString(result,m_bstr);}

  void copy_to(std::wstring* const result)const
   {ole_lib::BStrToWStr(result,m_bstr);}

 public:
  size_type length()const;

  bool empty()const;

 private:
  BSTR m_bstr;
};//class TBSTR

////////////////////////////////////////////////////////////////////////////////
//class TBSTR::is_bstr

inline TBSTR::size_type TBSTR::is_bstr::length()const
{
 return this->value?::SysStringLen(this->value):0;
}//length

////////////////////////////////////////////////////////////////////////////////
//class TBSTR

inline TBSTR& TBSTR::swap(TBSTR& x)
{
 std::swap(m_bstr,x.m_bstr);

 return *this;
}//swap

//------------------------------------------------------------------------
inline BSTR& TBSTR::ref_bstr(bool free)
{
 if(free)
  this->Free();

 return m_bstr;
}//ref_bstr

//------------------------------------------------------------------------
inline TBSTR::size_type TBSTR::length()const
{
 return m_bstr?::SysStringLen(m_bstr):0;
}//length

//------------------------------------------------------------------------
inline bool TBSTR::empty()const
{
 return this->length()==0;
}//empty

////////////////////////////////////////////////////////////////////////////////
