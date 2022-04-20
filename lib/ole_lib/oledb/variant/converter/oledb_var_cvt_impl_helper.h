////////////////////////////////////////////////////////////////////////////////
//Helper for implementation of OLEDB data type converters
//                                                 Kovalenko Dmitry. 05.09.2012.
#ifndef _oledb_var_cvt_impl_helper_H_
#define _oledb_var_cvt_impl_helper_H_

#include <ole_lib/oledb/variant/oledb_variant.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt_utils.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt_routers.h>

namespace oledb_lib{namespace oledb_lib_utils{
////////////////////////////////////////////////////////////////////////////////
//class t_oledb_type_cvt_impl_helper

class t_oledb_type_cvt_impl_helper
{
 private:
  typedef t_oledb_type_cvt_impl_helper      self_type;

 public: //typedefs ------------------------------------------------------
  typedef DBVARIANT::LPCCONVCONTEXT         LPCCONVCONTEXT;

 public:
  static bool CanHimselfDetectStorageObjectInterface(REFIID dbvar_unkVal_iid);

 public:
  static bool IsRequestOf_DEFAULT_SEQ_STREAM(REFIID riid);

  static HRESULT Create_DEFAULT_SEQ_STREAM(size_t                         cb,
                                           const void*                    pv,
                                           REFIID                         result_iid,
                                           t_oledb_value__CPP_IUNKNOWN_n* result);

 public:
  static bool IsRequestOf_IBP_SEQ_STREAM_MBC(REFIID riid);

  static HRESULT Create_IBP_SEQ_STREAM_MBC(size_t                         cch,
                                           const char*                    pchars,
                                           t_oledb_value__CPP_IUNKNOWN_n* result);

  static HRESULT Create_IBP_SEQ_STREAM_MBC(LPCCONVCONTEXT                 pConvCtx,
                                           const DBVARIANT&               dbvar,
                                           t_oledb_value__CPP_IUNKNOWN_n* result);

 public:
  static bool IsRequestOf_IBP_SEQ_STREAM_WC(REFIID riid);

  static HRESULT Create_IBP_SEQ_STREAM_WC(size_t                         cch,
                                          const wchar_t*                 pchars,
                                          t_oledb_value__CPP_IUNKNOWN_n* result);

  static HRESULT Create_IBP_SEQ_STREAM_WC(LPCCONVCONTEXT                 pConvCtx,
                                          const DBVARIANT&               dbvar,
                                          t_oledb_value__CPP_IUNKNOWN_n* result);

 public:
  template<typename TConvFuncs>
  static HRESULT IUnknownToValue__CompleteImpl(LPCCONVCONTEXT                    pConvCtx,
                                               const DBVARIANT::tagUnkVal&       unkVal,
                                               typename TConvFuncs::result_type* pResult);

 public:
  template<typename TConvRouter,typename TResult>
  static HRESULT StorageObjectToValue
                  (LPCCONVCONTEXT                                              pConvCtx,
                   TConvRouter                                                 ConvRouter,
                   lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_WideChar* pSS,
                   TResult*                                                    pResult);

  template<typename TConvRouter,typename TResult>
  static HRESULT StorageObjectToValue
                  (LPCCONVCONTEXT                                                   pConvCtx,
                   TConvRouter                                                      ConvRouter,
                   lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_MultiByteChar* pSS,
                   TResult*                                                         pResult);
};//class t_oledb_type_cvt_impl_helper

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb_lib_utils*/}/*nms oledb_lib*/
////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/variant/converter/oledb_var_cvt_impl_helper.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
