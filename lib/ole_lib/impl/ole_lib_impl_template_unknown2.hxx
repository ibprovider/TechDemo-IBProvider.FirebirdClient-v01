////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 13.08.2004

////////////////////////////////////////////////////////////////////////////////
//template class TemplateUnknown2

template<class TOwnerClass,const IID* PIID>
class TemplateUnknown2:public TOwnerClass,
                       public TBaseUnknown2
{
 private:
  typedef TemplateUnknown2<TOwnerClass,PIID>         self_type;
  typedef TBaseUnknown2                              inherited;

  TemplateUnknown2(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TemplateUnknown2(IUnknown* const pUnkOuter)
   :inherited(pUnkOuter)
  {;}

  virtual ~TemplateUnknown2();

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE
};//template class TemplateUnknown2

////////////////////////////////////////////////////////////////////////////////
//template class TemplateUnknown2

template<class TOwnerClass,const IID* PIID>
TemplateUnknown2<TOwnerClass,PIID>::~TemplateUnknown2()
{;}

//------------------------------------------------------------------------
template<class TOwnerClass,const IID* PIID>
HRESULT __stdcall TemplateUnknown2<TOwnerClass,PIID>::NondelegatingQueryInterface
                                                       (REFIID       riid,
                                                        void** const ppv)
{
 OLE_LIB_IMETHOD_PROLOG

 if(riid==*PIID)
 {
  OLE_LIB_TRACE_QUERY_INTERFACE("iid="<<structure::tstr_to_str(TestIID(*PIID)))

  return FinishQI_Static(static_cast<TOwnerClass*>(this),ppv);
 }//if

 return inherited::NondelegatingQueryInterface(riid,ppv);
}//NondelegatingQueryInterface

////////////////////////////////////////////////////////////////////////////////
