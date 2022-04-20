////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Kovalenko Dmitry. 25.06.2009

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2_WithFreeThreadMarshaler

class TBaseUnknown2_WithFreeThreadMarshaler:public TBaseUnknown2
{
 private:
  typedef TBaseUnknown2_WithFreeThreadMarshaler         self_type;
  typedef TBaseUnknown2                                 inherited;

  TBaseUnknown2_WithFreeThreadMarshaler(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  explicit TBaseUnknown2_WithFreeThreadMarshaler(IUnknown* pUnkOuter);

  virtual ~TBaseUnknown2_WithFreeThreadMarshaler();

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

 protected:
  bool BaseUnknown__IsSupportedInterface(REFIID riid);

 private:
  HRESULT Helper__Create_IMarshal();

 private:
  IUnknown* m_pFreeThreadMarshaller;
};//class TBaseUnknown2_WithFreeThreadMarshaler

////////////////////////////////////////////////////////////////////////////////
