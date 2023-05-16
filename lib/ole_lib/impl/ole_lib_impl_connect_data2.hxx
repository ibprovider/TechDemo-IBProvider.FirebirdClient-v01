////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                               Dmitry Kovalenko. 04.02.2005.

////////////////////////////////////////////////////////////////////////////////
//class TConnectData2

class TConnectData2 LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef TConnectData2          self_type;

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  //[2017-09-21] At current time implementation not exists
  self_type& operator = (self_type&& x);
 #endif

 public:
  TConnectData2();
  TConnectData2(const self_type& x);

  TConnectData2(const CONNECTDATA& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  TConnectData2(self_type&& x);
 #endif

  TConnectData2(IUnknown* const pUnk,DWORD const dwCookie);

 ~TConnectData2();

  self_type& operator = (const self_type&);

  self_type& operator = (const CONNECTDATA&);

  void swap(self_type&);

  void CopyInEnumerator(CONNECTDATA* const dest)const;

  self_type& Clear();

  //----------------------------------------------------------------------
  CONNECTDATA& ref_ptr(bool clear=true);

  //selectors ------------------------------------------------------------
  operator const CONNECTDATA& () const
   {return m_cd;}

  CONNECTDATA* operator -> ()
   {return &m_cd;}

 private:
  CONNECTDATA m_cd;
};//class TConnectData2

////////////////////////////////////////////////////////////////////////////////
//class TConnectData2

inline TConnectData2::TConnectData2()
{
 m_cd.pUnk=NULL;
 m_cd.dwCookie=0;
}//TConnectData2

//------------------------------------------------------------------------
inline TConnectData2::~TConnectData2()
{
 this->Clear();
}//~TConnectData2

//------------------------------------------------------------------------
inline TConnectData2& TConnectData2::operator = (const self_type& x)
{
 return (*this)=x.m_cd;
}//operator =

//------------------------------------------------------------------------
inline void TConnectData2::swap(self_type& x)
{
 std::swap(m_cd,x.m_cd);
}//swap

//------------------------------------------------------------------------
inline CONNECTDATA& TConnectData2::ref_ptr(bool const clear)
{
 return clear?this->Clear().m_cd:m_cd;
}//ref_ptr

////////////////////////////////////////////////////////////////////////////////
