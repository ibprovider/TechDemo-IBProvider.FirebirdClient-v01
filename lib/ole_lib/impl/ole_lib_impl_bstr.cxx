////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//class TBSTR

TBSTR& TBSTR::AllocStringLenEx(LPCWSTR const str,size_type const sz)
{
 if(!structure::can_numeric_cast<sys_size_type>(sz))
  throw std::bad_alloc();

 BSTR tmp_bstr=::SysAllocStringLen(str,static_cast<sys_size_type>(sz));

 if(tmp_bstr==NULL)
  throw std::bad_alloc();

 return this->AssignBStr(tmp_bstr);
}//AllocStringLenEx

//------------------------------------------------------------------------
TBSTR& TBSTR::Free()
{
 ole_lib::FreeBStr(m_bstr);

 assert(m_bstr==NULL);

 return *this;
}//Free

//------------------------------------------------------------------------
TBSTR& TBSTR::AssignBStr(BSTR& bstr)
{
 if(bstr!=m_bstr)
 {
  assert((&bstr)!=(&m_bstr));

  this->Free();

  m_bstr=bstr;

  bstr=NULL;
 }
 else
 if((&bstr)!=(&m_bstr))
 {
  bstr=NULL;
 }//if

 return *this;
}//AssignBStr

//------------------------------------------------------------------------
BSTR TBSTR::Release()
{
 BSTR const tmp=m_bstr;

 m_bstr=NULL;

 return tmp;
}//Release

//------------------------------------------------------------------------
TBSTR& TBSTR::SetBStrEx(const BSTR bstr)
{
 if(bstr==m_bstr)
  return *this;

 TBSTR tmp{is_bstr(bstr)};

 return this->swap(tmp);
}//SetBStr

//------------------------------------------------------------------------
TBSTR& TBSTR::SetStr(const structure::t_const_str_box& str)
{
 TBSTR tmp(str);

 return this->swap(tmp);
}//SetStr

//------------------------------------------------------------------------
TBSTR& TBSTR::SetWStr(const structure::t_const_wstr_box& str)
{
 TBSTR tmp(str);

 return this->swap(tmp);
}//SetWStr

////////////////////////////////////////////////////////////////////////////////
