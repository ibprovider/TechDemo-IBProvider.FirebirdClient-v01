////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//class TComInitialize2

class TComInitialize2
{
 private:
  typedef TComInitialize2                   self_type;

  TComInitialize2(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TComInitialize2(); //throw

  TComInitialize2(DWORD const dwCoInit); //throw

 ~TComInitialize2(); //no throw

 private:
#ifndef NDEBUG
  bool m_is_initialized;
#endif
};//class TComInitialize2

////////////////////////////////////////////////////////////////////////////////
