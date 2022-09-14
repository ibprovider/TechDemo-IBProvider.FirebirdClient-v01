////////////////////////////////////////////////////////////////////////////////
//! \ingroup ole_lib
//! \file    ole_auto_safe_array.cc
//! \brief   Wrappers for work with SAFEARRAY structure
//! \author  Kovalenko Dmitry
//! \date    14.12.2007
#ifndef _ole_auto_safe_array_CC_
#define _ole_auto_safe_array_CC_

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//class TBaseSafeArray

inline TBaseSafeArray::TBaseSafeArray()
 :m_psa(NULL)
{;}

//------------------------------------------------------------------------
inline TBaseSafeArray::operator TBaseSafeArray::LPSAFEARRAY ()
{
 return m_psa;
}//operator

//------------------------------------------------------------------------
inline TBaseSafeArray::operator TBaseSafeArray::LPCSAFEARRAY ()const
{
 return m_psa;
}//operator

//------------------------------------------------------------------------
inline TBaseSafeArray::LPSAFEARRAY TBaseSafeArray::sa()
{
 return m_psa;
}//sa

//------------------------------------------------------------------------
inline TBaseSafeArray::LPCSAFEARRAY TBaseSafeArray::sa()const
{
 return m_psa;
}//sa

////////////////////////////////////////////////////////////////////////////////
//class TSafeArray

inline TSafeArray::TSafeArray()
{;}

//------------------------------------------------------------------------
inline TSafeArray::TSafeArray(VARTYPE const vt,
                              LONG    const lower,
                              ULONG   const count)// throw(bad_alloc)
{
 this->Create(vt,lower,count);
}//TSafeArray

//-------------------------------------------------------------------------
inline TSafeArray::TSafeArray(VARTYPE               const vt,
                              UINT                  const cDim,
                              const SAFEARRAYBOUND* const rgsaBound)// throw(bad_alloc)
{
 this->Create(vt,cDim,rgsaBound);
}//TSafeArray

////////////////////////////////////////////////////////////////////////////////
//template class TemplateSafeArray

template<class T,VARTYPE VT>
inline TemplateSafeArray<T,VT>::TemplateSafeArray()
{;}

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
inline TemplateSafeArray<T,VT>::TemplateSafeArray(ULONG const count) //throw(bad_alloc)
{
 this->Create(0L,count);
}

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
inline TemplateSafeArray<T,VT>::TemplateSafeArray(LONG const lower,ULONG const count) //throw(bad_alloc)
{
 this->Create(lower,count);
}

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
inline TemplateSafeArray<T,VT>::TemplateSafeArray(UINT                  const cDim,
                                                  const SAFEARRAYBOUND* const rgsaBound) //throw(bad_alloc)
{
 this->Create(cDim,rgsaBound);
}

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
inline void TemplateSafeArray<T,VT>::Create(ULONG const count) //throw(bad_alloc)
{
 this->Create(0L,count);
}//Create

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
void TemplateSafeArray<T,VT>::Create(LONG  const lower,
                                     ULONG const count) //throw(bad_alloc)
{
 TSafeArrayBound const Bound(lower,count);

 this->Create(1,&Bound);
}//Create

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
void TemplateSafeArray<T,VT>::Create(UINT                  const Dim,
                                     const SAFEARRAYBOUND* const rgsaBound) //throw(bad_alloc)
{
 inherited::Create(VT,Dim,rgsaBound);

 assert(m_psa!=NULL);
 assert(m_psa->cbElements==sizeof(T));
}//Create

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
inline TemplateSafeArray<T,VT>::operator LPSAFEARRAY ()
{
 return m_psa;
}//operator

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
inline TemplateSafeArray<T,VT>::operator LPCSAFEARRAY ()const
{
 return m_psa;
}//operator

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
RELEASE_CODE(inline)
void TemplateSafeArray<T,VT>::Get(LONG const i1,T* const data)
{
 assert(m_psa!=NULL);
 assert_msg(this->GetDim()==1,"cDim=="<<this->GetDim());
 assert_msg(m_psa->cbElements==sizeof(T),
            "vt=="<<VT<<"\n"
            "cb=="<<m_psa->cbElements<<"\n"
            "size=="<<sizeof(T));

 this->GetElement(&i1,data);
}//Get

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
RELEASE_CODE(inline)
void TemplateSafeArray<T,VT>::Put(LONG const i1,const T* const data)
{
 assert(m_psa!=NULL);
 assert_msg(this->GetDim()==1,"cDim=="<<this->GetDim());
 assert_msg(m_psa->cbElements==sizeof(T),
            "vt=="<<VT<<"\n"
            "cb=="<<m_psa->cbElements<<"\n"
            "size=="<<sizeof(T));

 this->PutElement(&i1,data);
}//Put

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
RELEASE_CODE(inline)
void TemplateSafeArray<T,VT>::GetN(size_t      const cPoints,
                                   const LONG* const pPoints,
                                   T*          const data)
{
 assert(m_psa!=NULL);
 assert_msg(this->GetDim()==cPoints,"cDim=="<<this->GetDim()<<"\n"
                                    "cPoints=="<<cPoints);

 assert_msg(m_psa->cbElements==sizeof(T),
            "vt=="<<VT<<"\n"
            "cb=="<<m_psa->cbElements<<"\n"
            "size=="<<sizeof(T));

 this->GetElement(pPoints,data);
}//GetN

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
RELEASE_CODE(inline)
void TemplateSafeArray<T,VT>::PutN(size_t      const cPoints,
                                   const LONG* const pPoints,
                                   const T*    const data)
{
 assert(m_psa!=NULL);
 assert_msg(this->GetDim()==cPoints,"cDim=="<<this->GetDim()<<"\n"
                                    "cPoints=="<<cPoints);

assert_msg(m_psa->cbElements==sizeof(T),
            "vt=="<<VT<<"\n"
            "cb=="<<m_psa->cbElements<<"\n"
            "size=="<<sizeof(T));

 this->PutElement(pPoints,data);
}//PutN

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
RELEASE_CODE(inline)
void TemplateSafeArray<T,VT>::GetN(const std::vector<LONG>& x,T* const data)
{
 this->GetN(x.size(),
            x.data(),
            data);
}//GetN

//------------------------------------------------------------------------
template<class T,VARTYPE VT>
RELEASE_CODE(inline)
void TemplateSafeArray<T,VT>::PutN(const std::vector<LONG>& x,const T* const data)
{
 this->PutN(x.size(),
            x.data(),
            data);
}//PutN

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
