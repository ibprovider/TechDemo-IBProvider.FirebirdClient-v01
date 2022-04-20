////////////////////////////////////////////////////////////////////////////////
//Wrapper for resource identificator
//                                                 Dmitry Kovalenko. 19.04.2004

////////////////////////////////////////////////////////////////////////////////
//class TProgReg_Ex

TResID_Ex::TResID_Ex(const char_type* const resStr)
{
 if(resStr==NULL || IS_INTRESOURCE(resStr))
 {
  m_Str=const_cast<char_type*>(resStr);
 }
 else
 {
  const size_t len=std::char_traits<char_type>::length(resStr)+1;

  m_Str=new char_type[len];

  //copy with terminate null
  structure::copy(resStr,resStr+len,m_Str,m_Str+len);
 }
}//TResID_Ex

//------------------------------------------------------------------------
TResID_Ex::TResID_Ex(const self_type& x)
{
 if(x.m_Str==NULL || IS_INTRESOURCE(x.m_Str))
 {
  m_Str=x.m_Str;
 }
 else
 {
  //add terminate symbol
  const size_t len=std::char_traits<char_type>::length(x.m_Str)+1;

  m_Str=new char_type[len];

  //copy with terminate null
  structure::copy(x.m_Str,x.m_Str+len,m_Str,m_Str+len);
 }
}//TResID_Ex

//------------------------------------------------------------------------
TResID_Ex::~TResID_Ex()
{
 if(m_Str!=NULL && !IS_INTRESOURCE(m_Str))
 {
  delete [] m_Str;
  
  m_Str=NULL;
 }
}//~TResID_Ex

//------------------------------------------------------------------------
TResID_Ex& TResID_Ex::operator = (const self_type& x)
{
 self_type t(x);
 
 return this->swap(t);
}//copy operator

//------------------------------------------------------------------------
TResID_Ex& TResID_Ex::operator = (const char_type* const resStr)
{
 self_type t(resStr);
 
 return this->swap(t);
}//assign operator

//------------------------------------------------------------------------
TResID_Ex& TResID_Ex::operator = (const id_type resNum)
{
 self_type t(resNum);
 
 return this->swap(t);
}//assign operator

//------------------------------------------------------------------------
TResID_Ex& TResID_Ex::swap(self_type& x)
{
 std::swap(m_Str,x.m_Str);

 return *this;
}//swap

////////////////////////////////////////////////////////////////////////////////
