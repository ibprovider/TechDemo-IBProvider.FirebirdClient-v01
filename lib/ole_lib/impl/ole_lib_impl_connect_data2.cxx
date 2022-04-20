////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                               Dmitry Kovalenko. 04.02.2005.

////////////////////////////////////////////////////////////////////////////////
//class TConnectData2

TConnectData2::TConnectData2(const self_type& x)
{
 ole_lib::CopyComInterface2(x.m_cd.pUnk,/*out*/m_cd.pUnk);

 m_cd.dwCookie=x.m_cd.dwCookie;
}//TConnectData2

//------------------------------------------------------------------------
TConnectData2::TConnectData2(const CONNECTDATA& x)
{
 ole_lib::CopyComInterface2(x.pUnk,m_cd.pUnk);

 m_cd.dwCookie=x.dwCookie;
}//TConnectData2

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

TConnectData2::TConnectData2(self_type&& x)
 :m_cd(__STL_MOVE_VALUE(x.m_cd))
{
 assert(&m_cd!=&x.m_cd);

 x.m_cd.pUnk     =nullptr;
 x.m_cd.dwCookie =0;
}//TConnectData2

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
TConnectData2::TConnectData2(IUnknown* const pUnk,DWORD const dwCookie)
{
 ole_lib::CopyComInterface2(pUnk,m_cd.pUnk);

 m_cd.dwCookie=dwCookie;
}//TConnectData2

//------------------------------------------------------------------------
void TConnectData2::CopyInEnumerator(CONNECTDATA* const pDest)const
{
 assert(pDest);

 ole_lib::CopyComInterface2(m_cd.pUnk,/*out*/pDest->pUnk);

 pDest->dwCookie=m_cd.dwCookie;
}//CopyInEnumerator

//------------------------------------------------------------------------
TConnectData2& TConnectData2::Clear()
{
 m_cd.dwCookie=0;

 ole_lib::ReleaseComInterface(m_cd.pUnk);

 assert(m_cd.pUnk==NULL);

 return *this;
}//Clear

//------------------------------------------------------------------------
TConnectData2& TConnectData2::operator = (const CONNECTDATA& x)
{
 IUnknown* const pOldUnk=m_cd.pUnk;

 //-----
 if(x.pUnk!=NULL)
  x.pUnk->AddRef();

 m_cd.pUnk     =x.pUnk;
 m_cd.dwCookie =x.dwCookie;

 //-----
 if(pOldUnk!=NULL)
  pOldUnk->Release();

 return *this;
}//operator =

////////////////////////////////////////////////////////////////////////////////
