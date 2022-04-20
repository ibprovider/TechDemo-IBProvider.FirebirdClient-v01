////////////////////////////////////////////////////////////////////////////////
//OLEDB Library. Define structures for OLEDB Types convertors implementations
//                                                 Kovalenko Dmitry. 09.05.2008
#ifndef _oledb_var_cvt_impl_mac_H_
#define _oledb_var_cvt_impl_mac_H_

#include <ole_lib/oledb/variant/converter/oledb_var_cvt_interfaces.h>

////////////////////////////////////////////////////////////////////////////////

#define DECLARE_OLEDB_TYPE_CONVERTER_OBJ(ft,tt)                        \
extern const OLEDB_TYPE_CONVERTER_NAME(ft,tt) OLEDB_TYPE_CONVERTER_OBJ_NAME(ft,tt);

////////////////////////////////////////////////////////////////////////////////
//Template for converter definition

#define DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V2(ft,tt)                \
struct OLEDB_TYPE_CONVERTER_NAME(ft,tt):                               \
 public OLEDB_TYPE_CONVERTER_INTERFACE(array)                          \
{                                                                      \
 private:                                                              \
  typedef OLEDB_TYPE_CONVERTER_NAME(ft,tt)                self_type;   \
                                                                       \
  OLEDB_TYPE_CONVERTER_NAME(ft,tt)(const self_type&);                  \
  self_type& operator = (const self_type&);                            \
                                                                       \
 public:                                                               \
  OLEDB_TYPE_CONVERTER_NAME(ft,tt)(){;}                                \
                                                                       \
 private:                                                              \
  virtual HRESULT internal__convert_value_to_array                     \
                   (LPCCONVCONTEXT   pConvCtx,                         \
                    const DBVARIANT& dbvar,                            \
                    REFIID           result_iid,                       \
                    result_type*     result)const COMP_W000004_OVERRIDE_FINAL; \
};                                                                     \
                                                                       \
DECLARE_OLEDB_TYPE_CONVERTER_OBJ(ft,tt)

////////////////////////////////////////////////////////////////////////////////
//Template for converter definition

#define DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V3(ft,tt)                \
struct OLEDB_TYPE_CONVERTER_NAME(ft,tt):                               \
 public OLEDB_TYPE_CONVERTER_INTERFACE(array)                          \
{                                                                      \
 private:                                                              \
  typedef OLEDB_TYPE_CONVERTER_NAME(ft,tt)                self_type;   \
                                                                       \
  OLEDB_TYPE_CONVERTER_NAME(ft,tt)(const self_type&);                  \
  self_type& operator = (const self_type&);                            \
                                                                       \
 public:                                                               \
  OLEDB_TYPE_CONVERTER_NAME(ft,tt)(DBTYPE const wFromType,             \
                                   DBTYPE const wToType)               \
   :m_wFromType(wFromType)                                             \
   ,m_wToType(wToType)                                                 \
  {;}                                                                  \
                                                                       \
 private:                                                              \
  virtual HRESULT internal__convert_value_to_array                     \
                   (LPCCONVCONTEXT   pConvCtx,                         \
                    const DBVARIANT& dbvar,                            \
                    REFIID           result_iid,                       \
                    result_type*     result)const COMP_W000004_OVERRIDE_FINAL; \
                                                                       \
 private:                                                              \
  const DBTYPE m_wFromType;                                            \
  const DBTYPE m_wToType;                                              \
};

//------------------------------------------------------------------------
#define DECLARE_OLEDB_TYPE_CONVERTER_TO_ARRAY_V3_EXT(ft,tt)            \
struct OLEDB_TYPE_CONVERTER_NAME(ft,tt)                                \
 :public OLEDB_TYPE_CONVERTER_INTERFACE(array)                         \
 ,public TDBTypeConverter_BindingTest                                  \
{                                                                      \
 private:                                                              \
  typedef OLEDB_TYPE_CONVERTER_NAME(ft,tt)                self_type;   \
                                                                       \
  OLEDB_TYPE_CONVERTER_NAME(ft,tt)(const self_type&);                  \
  self_type& operator = (const self_type&);                            \
                                                                       \
 public:                                                               \
  OLEDB_TYPE_CONVERTER_NAME(ft,tt)(DBTYPE const wFromType,             \
                                   DBTYPE const wToType)               \
   :m_wFromType(wFromType)                                             \
   ,m_wToType(wToType)                                                 \
  {;}                                                                  \
                                                                       \
  virtual bool CanConvertTo                                            \
                  (LPCCONVCONTEXT   pConvCtx,                          \
                   const DBBINDING& Bind)const COMP_W000004_OVERRIDE_FINAL;  \
                                                                       \
 private:                                                              \
  virtual HRESULT internal__convert_value_to_array                     \
                   (LPCCONVCONTEXT   pConvCtx,                         \
                    const DBVARIANT& dbvar,                            \
                    REFIID           result_iid,                       \
                    result_type*     result)const COMP_W000004_OVERRIDE_FINAL; \
                                                                       \
 private:                                                              \
  const DBTYPE m_wFromType;                                            \
  const DBTYPE m_wToType;                                              \
};

//------------------------------------------------------------------------
#define DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(class_ft,          \
                                                    class_tt,          \
                                                    obj_ft,            \
                                                    obj_tt,            \
                                                    wFromType,         \
                                                    wToType)           \
const OLEDB_TYPE_CONVERTER_NAME(class_ft,class_tt)                     \
 OLEDB_TYPE_CONVERTER_OBJ_NAME(obj_ft,obj_tt)(wFromType,wToType);

////////////////////////////////////////////////////////////////////////////////
//Template for converter definition

#define DECLARE_OLEDB_TYPE_CONVERTER_V3__TO_IUNKNOWN(ft)               \
struct OLEDB_TYPE_CONVERTER_NAME(ft,iunknown)                          \
 :public OLEDB_TYPE_CONVERTER_INTERFACE(iunknown)                      \
 ,public TDBTypeConverter_BindingTest                                  \
{                                                                      \
 private:                                                              \
  typedef OLEDB_TYPE_CONVERTER_NAME(ft,iunknown)    self_type;         \
                                                                       \
  OLEDB_TYPE_CONVERTER_NAME(ft,iunknown)(const self_type&);            \
  self_type& operator = (const self_type&);                            \
                                                                       \
 public:                                                               \
  OLEDB_TYPE_CONVERTER_NAME(ft,iunknown)(){;}                          \
                                                                       \
  virtual bool CanConvertTo                                            \
                   (LPCCONVCONTEXT   pConvContext,                     \
                    const DBBINDING& Bind)const COMP_W000004_OVERRIDE_FINAL;\
                                                                       \
 private:                                                              \
  virtual HRESULT internal__convert_value_to_iunknown                  \
                   (LPCCONVCONTEXT   pConvContext,                     \
                    const DBVARIANT& dbvar,                            \
                    REFIID           result_iid,                       \
                    result_type*     result)const COMP_W000004_OVERRIDE_FINAL;\
};                                                                     \
                                                                       \
DECLARE_OLEDB_TYPE_CONVERTER_OBJ(ft,iunknown)

////////////////////////////////////////////////////////////////////////////////
//Template for converter definition

#define DECLARE_OLEDB_TYPE_CONVERTER_V3__BEG(ft,tt)                    \
struct OLEDB_TYPE_CONVERTER_NAME(ft,tt);                               \
                                                                       \
DECLARE_OLEDB_TYPE_CONVERTER_OBJ(ft,tt)                                \
                                                                       \
struct OLEDB_TYPE_CONVERTER_NAME(ft,tt):                               \
 public OLEDB_TYPE_CONVERTER_INTERFACE(tt)                             \
{                                                                      \
 private:                                                              \
  typedef OLEDB_TYPE_CONVERTER_NAME(ft,tt)          self_type;         \
                                                                       \
  OLEDB_TYPE_CONVERTER_NAME(ft,tt)(const self_type&);                  \
  self_type& operator = (const self_type&);                            \
                                                                       \
 public:                                                               \
  OLEDB_TYPE_CONVERTER_NAME(ft,tt)(){;}                                \
                                                                       \
 private:                                                              \
  virtual HRESULT internal__convert_value_to_##tt                      \
                   (LPCCONVCONTEXT   pConvContext,                     \
                    const DBVARIANT& dbvar,                            \
                    result_type*     result)const COMP_W000004_OVERRIDE_FINAL;

//------------------------------------------------------------------------
#define DECLARE_OLEDB_TYPE_CONVERTER_V3__END()                         \
};

//------------------------------------------------------------------------
#define DECLARE_OLEDB_TYPE_CONVERTER_V3(ft,tt)                         \
 DECLARE_OLEDB_TYPE_CONVERTER_V3__BEG(ft,tt)                           \
 DECLARE_OLEDB_TYPE_CONVERTER_V3__END();

////////////////////////////////////////////////////////////////////////////////

#define DEFINE_OLEDB_TYPE_CONVERTERS_MAP_ST(ft,simple_cvts)            \
extern const DBVARIANT::TTypeConverterMap                              \
 g_oledb_cvt_maps_for_##ft(simple_cvts,                                \
                           _DIM_(simple_cvts),                         \
                           NULL,                                       \
                           0);

#define DEFINE_OLEDB_TYPE_CONVERTERS_MAP_ST_AT(ft,simple_cvts,array_cvts) \
extern const DBVARIANT::TTypeConverterMap                                 \
 g_oledb_cvt_maps_for_##ft(simple_cvts,                                   \
                           _DIM_(simple_cvts),                            \
                           array_cvts,                                    \
                           _DIM_(array_cvts));

#define DEFINE_OLEDB_TYPE_CONVERTERS_MAP_AT(ft,array_cvts)             \
extern const DBVARIANT::TTypeConverterMap                              \
 g_oledb_cvt_maps_for_##ft(NULL,                                       \
                           0,                                          \
                           array_cvts,                                 \
                           _DIM_(array_cvts));

//------------------------------------------------------------------------
#define DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ft,tt)      \
const OLEDB_TYPE_CONVERTER_NAME(ft,tt) OLEDB_TYPE_CONVERTER_OBJ_NAME(ft,tt);

//------------------------------------------------------------------------
#define DEFINE_OLEDB_TYPE_CONVERTER_REF(ft,tt)      \
{&OLEDB_TYPE_CONVERTER_OBJ_NAME(ft,tt)},

//------------------------------------------------------------------------
#define DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(num)    \
{NULL},

////////////////////////////////////////////////////////////////////////////////
#endif
