//////////////////////////////////////////////////////////////////////////////////
//DBVARIANT_CVT_UTILS Implementation. Bytes Utilities
//                                                Kovalenko Dmitry 19.05.2008

//////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT

HRESULT DBVARIANT_CVT_UTILS::BytesToArrayUI1(const void* const pvBuffer,
                                             size_type   const cbBuffer,
                                             SAFEARRAY** const ppArray)
{
 assert(ppArray!=NULL);

 CHECK_READ_PTR(pvBuffer,cbBuffer);

 (*ppArray)=NULL;

 if(!structure::can_numeric_cast<ULONG>(cbBuffer))
  return TDBTypeConverterCode::data_overflow;

 SAFEARRAYBOUND bound;

 bound.cElements=static_cast<ULONG>(cbBuffer);
 bound.lLbound  =0;

 ole_lib::TBaseSafeArray sa;

 sa.ref_sa()=::SafeArrayCreate(VT_UI1,1,&bound);

 if(sa.sa()==NULL)
  return E_FAIL;

 if(cbBuffer!=0)
 {
  void* pvData=NULL;

  if(::SafeArrayAccessData(sa,&pvData)!=S_OK)
   return E_FAIL;

  const ole_lib::TSafeArrayAutoUnAccessData sa_auto_unaccess(sa);

  if(pvData==NULL)
   return E_FAIL;

  CHECK_WRITE_PTR(pvData,cbBuffer);

  memcpy(pvData,pvBuffer,cbBuffer);
 }//if

 (*ppArray)=sa.Release();

 return S_OK;
}//BytesToArrayUI1

//////////////////////////////////////////////////////////////////////////////////
