////////////////////////////////////////////////////////////////////////////////
//Helper for implementation of OLEDB data type converters
//                                                 Kovalenko Dmitry. 05.09.2012.
#ifndef _oledb_var_cvt_impl_helper_CC_
#define _oledb_var_cvt_impl_helper_CC_

#include <ole_lib/oledb/variant/oledb_xvariant_stream_writer.h>

namespace oledb_lib{namespace oledb_lib_utils{
////////////////////////////////////////////////////////////////////////////////
//class t_oledb_type_cvt_impl_helper

template<typename TConvFuncs>
HRESULT t_oledb_type_cvt_impl_helper::IUnknownToValue__CompleteImpl
                                     (LPCCONVCONTEXT                    const pConvCtx,
                                      const DBVARIANT::tagUnkVal&             unkVal,
                                      typename TConvFuncs::result_type* const pResult)
{
 assert(pConvCtx);
 assert(pResult!=NULL);

 //-----------------------------------------------------------------------
 typedef self_type impl_helper;

 //-----------------------------------------------------------------------
 if(unkVal.iid==lcpi::sdk::ibprovider::v05::IID_IBP_ISequentialStream_WideChar)
 {
  OLE_LIB__BUILD_IPTR_TYPE_NS(lcpi::sdk::ibprovider::v05::,IBP_ISequentialStream_WideChar) spSS;

  if(unkVal.ptr!=NULL)
  {
   spSS=unkVal.ptr;

   if(!spSS)
    return DB_E_CANTCONVERTVALUE;
  }//if

  return TConvFuncs::From_IBP_SS_WC
          (pConvCtx,
           spSS,
           pResult);
 }//if IBP_SS_WC

 //-----------------------------------------
 if(unkVal.iid==lcpi::sdk::ibprovider::v05::IID_IBP_ISequentialStream_MultiByteChar)
 {
  OLE_LIB__BUILD_IPTR_TYPE_NS(lcpi::sdk::ibprovider::v05::,IBP_ISequentialStream_MultiByteChar) spSS;

  if(unkVal.ptr!=NULL)
  {
   spSS=unkVal.ptr;

   if(!spSS)
    return DB_E_CANTCONVERTVALUE;
  }//if

  return TConvFuncs::From_IBP_SS_MBC
          (pConvCtx,
           spSS,
           pResult);
 }//if IBP_SS_MBC

 //-----------------------------------------
 if(unkVal.iid==IID_ISequentialStream)
 {
  OLE_LIB__BUILD_IPTR_TYPE(ISequentialStream) spSS;

  if(unkVal.ptr!=NULL)
  {
   spSS=unkVal.ptr;

   if(!spSS)
    return DB_E_CANTCONVERTVALUE;
  }//if

  return TConvFuncs::From_STD_SS
          (pConvCtx,
           spSS,
           pResult);
 }//if STD_SS

 //-----------------------------------------------------------------------
 if(!impl_helper::CanHimselfDetectStorageObjectInterface(unkVal.iid))
  return DB_E_CANTCONVERTVALUE;

 //-----------------------------------------------------------------------
 if(unkVal.ptr==NULL)
 {
  return TConvFuncs::From_NULL_PTR
          (pConvCtx,
           pResult);
 }//if

 //------------------------------------------
 assert(unkVal.ptr);

 if(OLE_LIB__BUILD_IPTR_TYPE_NS(lcpi::sdk::ibprovider::v05::,IBP_ISequentialStream_WideChar)
     const spSS=structure::not_null_ptr(unkVal.ptr))
 {
  return TConvFuncs::From_IBP_SS_WC
          (pConvCtx,
           spSS,
           pResult);
 }//if IBP_SS_WC

 //-----------------------------------------
 assert(unkVal.ptr);

 if(OLE_LIB__BUILD_IPTR_TYPE_NS(lcpi::sdk::ibprovider::v05::,IBP_ISequentialStream_MultiByteChar)
     const spSS=structure::not_null_ptr(unkVal.ptr))
 {
  return TConvFuncs::From_IBP_SS_MBC
          (pConvCtx,
           spSS,
           pResult);
 }//if IBP_SS_MBC

 //-----------------------------------------
 assert(unkVal.ptr);

 if(ole_lib::ISequentialStreamPtr const spSS=structure::not_null_ptr(unkVal.ptr))
 {
  return TConvFuncs::From_STD_SS
          (pConvCtx,
           spSS,
           pResult);
 }//if STD_SS

 //-----------------------------------------------------------------------
 return DB_E_CANTCONVERTVALUE;
}//IUnknownToValue__CompleteImpl

//------------------------------------------------------------------------
template<typename TConvRouter,typename TResult>
HRESULT t_oledb_type_cvt_impl_helper::StorageObjectToValue
         (LPCCONVCONTEXT                                              const pConvCtx,
          TConvRouter                                                 const ConvRouter,
          lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_WideChar* const pSS,
          TResult*                                                    const pResult)
{
 assert(pConvCtx);
 assert(pSS);
 assert(pResult);

 TDBVariantWCharsWriter WChars;

 {
  const HRESULT hr=DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2(pSS,&WChars);

  if(FAILED(hr))
   return hr;

  assert(hr==S_OK);
 }//local

 DBVARIANT tmp;

 tmp.wType=DBTYPE_WSTR;

 tmp.wstrVal.len=WChars.m_buffer.size();

 tmp.wstrVal.ptr=WChars.m_buffer.make_flat(/*final*/true);

 assert(tmp.wstrVal.len==WChars.m_buffer.size());

 return ConvRouter(pConvCtx,tmp,pResult);
}//StorageObjectToValue - IBP_SS_WC

//------------------------------------------------------------------------
template<typename TConvRouter,typename TResult>
HRESULT t_oledb_type_cvt_impl_helper::StorageObjectToValue
         (LPCCONVCONTEXT                                                   const pConvCtx,
          TConvRouter                                                      const ConvRouter,
          lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_MultiByteChar* const pSS,
          TResult*                                                         const pResult)
{
 assert(pConvCtx);
 assert(pSS);
 assert(pResult);

 TDBVariantCharsWriter Chars;

 {
  const HRESULT hr=DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2(pSS,&Chars);

  if(FAILED(hr))
   return hr;

  assert(hr==S_OK);
 }//local

 DBVARIANT tmp;

 tmp.wType=DBTYPE_STR;

 tmp.strVal.len=Chars.m_buffer.size();

 tmp.strVal.ptr=Chars.m_buffer.make_flat(/*final*/true);

 assert(tmp.strVal.len==Chars.m_buffer.size());

 return ConvRouter(pConvCtx,tmp,pResult);
}//StorageObjectToValue - IBP_SS_MBC

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb_lib_utils*/}/*nms oledb_lib*/
#endif
