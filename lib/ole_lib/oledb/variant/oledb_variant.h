////////////////////////////////////////////////////////////////////////////////
//Wrapper for OLEDB Variant data type
//                                              Dmitry Kovalenko. January 2000.
#ifndef _oledb_variant_H_
#define _oledb_variant_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/oledb/variant/oledb_variant_fwrd.h>  //forward declarations
#include <ole_lib/oledb/variant/oledb_variant_tag.h>   //tagDBVARIANT
#include <ole_lib/oledb/variant/oledb_variant_cvt_fwrd.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//using namespace ole_lib;

////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT

struct DBVARIANT:public tagDBVARIANT
{
 private:
  typedef DBVARIANT                                           self_type;

 public:  //data typedefs -------------------------------------------------
  typedef DBVARIANT_BYTES_WRITER                              bytes_writer_type;

  typedef t_oledb_value__CPP_BOOL                             value_cpp_bool_type;

  typedef t_oledb_value__CPP_STR                              value_cpp_str_type;
  typedef t_oledb_value__CPP_WSTR                             value_cpp_wstr_type;
  typedef t_oledb_value__CPP_BSTR                             value_cpp_bstr_type;

  typedef t_oledb_value__SCODE_n                              value_scode_n_type;

  typedef t_oledb_value__I1_n                                 value_i1_n_type;
  typedef t_oledb_value__I2_n                                 value_i2_n_type;
  typedef t_oledb_value__I4_n                                 value_i4_n_type;
  typedef t_oledb_value__I8_n                                 value_i8_n_type;
  typedef t_oledb_value__I8_s_n                               value_i8_n_type_s;
  typedef t_oledb_value__LONG_n                               value_long_n_type;

  typedef t_oledb_value__UI1_n                                value_ui1_n_type;
  typedef t_oledb_value__UI2_n                                value_ui2_n_type;
  typedef t_oledb_value__UI4_n                                value_ui4_n_type;
  typedef t_oledb_value__UI8_n                                value_ui8_n_type;
  typedef t_oledb_value__UI8_s_n                              value_ui8_n_type_s;
  typedef t_oledb_value__ULONG_n                              value_ulong_n_type;

  typedef t_oledb_value__R4_n                                 value_r4_n_type;
  typedef t_oledb_value__R8_n                                 value_r8_n_type;

  typedef t_oledb_value__CY_n                                 value_cy_n_type;
  typedef t_oledb_value__DECIMAL_n                            value_decimal_n_type;
  typedef t_oledb_value__NUMERIC_n                            value_numeric_n_type;

  typedef t_oledb_value__DATE_n                               value_date_n_type;
  typedef t_oledb_value__DBDATE_n                             value_dbdate_n_type;
  typedef t_oledb_value__DBTIME_n                             value_dbtime_n_type;
  typedef t_oledb_value__DBTIME2_n                            value_dbtime2_n_type;
  typedef t_oledb_value__DBTIMESTAMP_n                        value_dbstamp_n_type;
  typedef t_oledb_value__DBTIMESTAMPOFFSET_n                  value_dbstampoffset_n_type;
  typedef t_oledb_value__FILETIME_n                           value_filetime_n_type;

  typedef t_oledb_value__GUID_n                               value_guid_n_type;

  typedef t_oledb_value__CPP_IUNKNOWN_n                       value_unknown_n_type;
  typedef t_oledb_value__CPP_IDISPATCH_n                      value_dispatch_n_type;

  typedef t_oledb_value__CPP_BOOL_n                           value_cpp_bool_n_type;

  typedef t_oledb_value__CPP_STR_n                            value_cpp_str_n_type;
  typedef t_oledb_value__CPP_WSTR_n                           value_cpp_wstr_n_type;
  typedef t_oledb_value__CPP_BSTR_n                           value_cpp_bstr_n_type;

 public:
  inline DBVARIANT();

  inline ~DBVARIANT();

 public:
  bool GetIID(IID* piid)const;

  bool SetIID(REFIID iid);

 public:
  void SetDataStatus(DBSTATUS s);

  void SetDataStatus__OK();

  void SetDataStatus__IsNull();

  void SetDataStatus__Default();

 public:
  inline DBSTATUS GetDataStatus()const;

  inline bool TestDataStatus__IsOK()const;

  inline bool TestDataStatus__IsTruncated()const;

 #ifndef NDEBUG
  inline bool TestDataStatus__IsOK_or_IsTruncated()const;

  inline bool TestDataStatus__IsOK_or_IsNull()const;
 #endif

  inline bool TestDataStatus__IsNull()const;

  inline bool TestDataStatus__IsDefault()const;

 public:
  bool IsNull()const;

  void IsNull(bool Null);

  inline bool IsEmpty()const;

  inline bool IsArray()const;

  //Test the IsNull, VARIANT::VT_NULL, DBTYPE_NULL
  bool IsNull_Ext()const;

 protected:
  inline void Init(DBTYPE _wType=DBTYPE_EMPTY);

 public: //---------------------------------------------------------------
  enum EnumTypeFlags
  {
   //данные фиксированной длины
   DBTypeFlag_FixedLen                 =0x00,

   //данные с переменной длиной
   DBTypeFlag_VariableLen              =0x01,

   //Value is NOT COM-object
   DBTypeFlag_IsNoComObject            =0x08,

   //Numeric with fixed precision
   DBTypeFlag_IsFixedPrecisionDigit    =0x10,

   DBTypeFlag_IsDigit                  =0x20,

   //Show type precision through ColumnsRowset
   DBTypeFlag_ICR_Precision            =0x40,

   //Show type scale through ColumnsRowset
   DBTypeFlag_ICR_Scale                =0x80,

   //Show datetimeprecision through ColumnsRowset
   DBTypeFlag_ICR_DateTimePrecision    =0x0100,
  };//EnumTypeFlags

 public: //forward type declarations -------------------------------------
  class  TTypeConverterMap;            //Map of converters for single OLEDB-type

  struct TTypeService;                 //OLEDB type service interface
  struct TTypeInfo;                    //OLEDB type description
  struct TParamInfo;                   //Parameter [ADODB] type description

  class  TCvtAdapter;                  //Adapter for other VARIANT-structures
  class  TCvtAdapter_Array;

  class TPrinter;

 public: //helper typedefs -----------------------------------------------
  typedef const TTypeService*                    LPCTYPESERVICE;
  typedef const TTypeInfo*                       LPCTYPEINFO;
  typedef const TParamInfo*                      LPCPARAMINFO;

  typedef const TDBTypeConverter*                LPCTYPECONVERTER;
  typedef const TDBTypeConverter_BindingTest*    LPCTYPECONVERTER_DBBINDING_TEST;
  typedef const TDBTypeConverterContext*         LPCCONVCONTEXT;

 public:  //--------------------------------------------------------------
  static LPCTYPEINFO             GetInfo(DBTYPE wType);

  static inline LPCTYPESERVICE   GetTypeService(DBTYPE wType);

  static length_type             GetAlign2(DBTYPE wType);

  static bool                    IsVariableLen2(DBTYPE wType);

  //возвращает true, если данные содержат указатели
  //DBTYPE_BSTR || &(DBTYPE_BYREF |DBTYPE_ARRAY|DBTYPE_VECTOR)
  static bool                    IsPointedDataType2(DBTYPE wType);

 public:
  static t_oledb_string GetTypeName         (DBTYPE wType,DBCOLUMNFLAGS flags);
  static t_oledb_string GetParamTypeName    (DBTYPE wType,DBPARAMFLAGS Flags);

  static t_oledb_string GetAdoParamTypeName (AdoDataTypeEnum adType);

  static LPCPARAMINFO GetAdoParamInfo (AdoDataTypeEnum adType);
  static LPCPARAMINFO GetParamInfo    (DBTYPE wType,DBCOLUMNFLAGS dwColumnFlags);
  static LPCPARAMINFO GetParamInfo    (LPCSTR TypeName);
  static LPCPARAMINFO GetParamInfo    (LPCWSTR TypeName);

 public:
  inline LPCTYPEINFO      GetInfo()        const;
  inline LPCTYPESERVICE   GetTypeService() const;
  inline t_oledb_string   GetTypeName()    const;

 public:
  static bool CanConvert(DBTYPE wFromType,const DBBINDING& ToBinding);
  static bool CanConvert(DBTYPE wFromType,DBTYPE wToType);

 public:
  static inline LPCTYPECONVERTER GetTypeConverter(DBTYPE wFromType,DBTYPE wToType);

 public:
  //Size - used only for variable length oledb-types (STR/WSTR/BYTES)
  //       for outer types this argument is ignored
  //return 0 for unknown type or type cannot presended as fixed length string
  static length_type GetStringSizeOfTypePresentation(DBTYPE wType,length_type Size);

  //Size - used only for variable length oledb-types (STR/WSTR/BYTES)
  //       for outer types this argument is ignored
  //return 0 for unknown type or type cannot presended as fixed length string
  static length_type GetBinarySizeOfTypePresentation(DBTYPE wType,length_type Size);

 public:
  //сравнение состояния данных в буфере с указанным значением
  //return: true for equal
  static bool EqualBindingStatus(const DBBINDING& Binding,void* pData,DBSTATUS Status);

 public: //определение размеров данных -----------------------------------
  length_type  GetAlign2  () const;

  void GetSize2(length_type& cbSize,
                length_type& cbMemSize)const; //throw

  length_type GetSize2()const; //throw

  length_type GetMemSize2()const; //throw

  //get size in bytes/chars
  //for array - return  length of element
  length_type GetLength2()const; //throw

 public: //conversion operations ------------------------------------------
#ifndef OLEDB_LIB_NO_TYPE_CVT_CONTEXT_STD

  HRESULT  to_I1          (value_i1_n_type*         value) const;
  HRESULT  to_I2          (value_i2_n_type*         value) const;
  HRESULT  to_I4          (value_i4_n_type*         value) const;
  HRESULT  to_I8          (value_i8_n_type*         value) const;
  HRESULT  to_I8          (value_i8_n_type_s*       value) const;

  HRESULT  to_UI1         (value_ui1_n_type*        value) const;
  HRESULT  to_UI2         (value_ui2_n_type*        value) const;
  HRESULT  to_UI4         (value_ui4_n_type*        value) const;
  HRESULT  to_UI8         (value_ui8_n_type*        value) const;
  HRESULT  to_UI8         (value_ui8_n_type_s*      value) const;

  HRESULT  to_R4          (value_r4_n_type*         value) const;
  HRESULT  to_R8          (value_r8_n_type*         value) const;

  HRESULT  to_cy          (value_cy_n_type*         value) const;
  HRESULT  to_numeric     (value_numeric_n_type*    value) const;
  HRESULT  to_decimal     (value_decimal_n_type*    value) const;

  HRESULT  to_error       (value_scode_n_type*      value) const;

  HRESULT  to_bool        (value_cpp_bool_n_type*   value) const;

  HRESULT  to_str         (value_cpp_str_n_type*    value) const;
  HRESULT  to_wstr        (value_cpp_wstr_n_type*   value) const;

  HRESULT  to_bstr        (value_cpp_bstr_n_type*   value) const;

  HRESULT  to_variant     (VARIANT*                 value) const;

  HRESULT  to_guid        (value_guid_n_type*       value) const;

  HRESULT  to_unknown     (value_unknown_n_type*    value) const;
  HRESULT  to_dispatch    (value_dispatch_n_type*   value) const;

  HRESULT  to_date              (value_date_n_type*          value) const;
  HRESULT  to_dbdate            (value_dbdate_n_type*        value) const;
  HRESULT  to_dbtime            (value_dbtime_n_type*        value) const;
  HRESULT  to_dbtimestamp       (value_dbstamp_n_type*       value) const;
  HRESULT  to_dbtimestampoffset (value_dbstampoffset_n_type* value) const;
  HRESULT  to_filetime          (value_filetime_n_type*      value) const;

  //return the S_FALSE for NULL-state
  HRESULT  to_bytes       (bytes_writer_type*       pWriter) const;

  //! \param[in]  ArrayType
  //!  Has DBTYPE_ARRAY flag
  //! \param[out] ppSafeArray
  //!  Not NULL
  //! \return
  //!  - S_FALSE for NULL-state
  HRESULT  to_array       (DBTYPE ArrayType,SAFEARRAY** ppSafeArray) const;

 public:
  HRESULT  to_nn(value_i1_type*       pvalue)const;
  HRESULT  to_nn(value_i2_type*       pvalue)const;
  HRESULT  to_nn(value_i4_type*       pvalue)const;
  HRESULT  to_nn(value_i8_type*       pvalue)const;
  HRESULT  to_nn(value_i8_type_s*     pvalue)const;

  HRESULT  to_nn(value_ui1_type*      pvalue)const;
  HRESULT  to_nn(value_ui2_type*      pvalue)const;
  HRESULT  to_nn(value_ui4_type*      pvalue)const;
  HRESULT  to_nn(value_ui8_type*      pvalue)const;
  HRESULT  to_nn(value_ui8_type_s*    pvalue)const;

  HRESULT  to_nn(value_r4_type*       pvalue)const;
  HRESULT  to_nn(value_r8_type*       pvalue)const;

  HRESULT  to_nn(value_long_type*     pvalue)const;
  HRESULT  to_nn(value_ulong_type*    pvalue)const;

  HRESULT  to_nn(value_cpp_bool_type* pvalue)const;

 public:
  HRESULT  to(value_i1_n_type*        pvalue)const;
  HRESULT  to(value_i2_n_type*        pvalue)const;
  HRESULT  to(value_i4_n_type*        pvalue)const;
  HRESULT  to(value_i8_n_type*        pvalue)const;
  HRESULT  to(value_i8_n_type_s*      pvalue)const;

  HRESULT  to(value_ui1_n_type*       pvalue)const;
  HRESULT  to(value_ui2_n_type*       pvalue)const;
  HRESULT  to(value_ui4_n_type*       pvalue)const;
  HRESULT  to(value_ui8_n_type*       pvalue)const;
  HRESULT  to(value_ui8_n_type_s*     pvalue)const;

  HRESULT  to(value_r4_n_type*        pvalue)const;
  HRESULT  to(value_r8_n_type*        pvalue)const;

  HRESULT  to(value_long_n_type*      pvalue)const;
  HRESULT  to(value_ulong_n_type*     pvalue)const;

  HRESULT  to(value_cpp_bool_n_type*  pvalue)const;

#endif

 public:
  std::string get_print_str()const;

  std::wstring get_print_wstr()const;

  structure::t_string get_print_tstr()const;

 private:
  COMP_CONF_DECLSPEC_NORETURN
  static void helper__throw_bug_check__unexpected_dbtype
               (const char* place,
                const char* point,
                DBTYPE      dbtype);
};//struct DBVARIANT

////////////////////////////////////////////////////////////////////////////////

inline DBVARIANT::TPrinter print(const DBVARIANT& dbvar);

////////////////////////////////////////////////////////////////////////////////

inline std::ostream& operator << (std::ostream& os,const DBVARIANT::TPrinter& printer);

inline std::wostream& operator << (std::wostream& os,const DBVARIANT::TPrinter& printer);

////////////////////////////////////////////////////////////////////////////////
//Unpack VARIANT to DBVARIANT

HRESULT UnpackVariantToDBVariant(const VARIANT& var,DBVARIANT* dbvar);

////////////////////////////////////////////////////////////////////////////////
//Access Array Element
// implementation in "oledb_variant_array.h"

//1 Check format of Array
//2 find information of type of array element
//3 calculate Offset of bytes of data in Array
//
//returns:
//  E_FAIL       - Array is not array variable
//  E_UNEXPECTED - bad format of Array
//  E_INVALIDARG - error value in cPoints/pPoints
//  S_OK         - all is OK
HRESULT DBVariant_MakeArrayOffset(const DBVARIANT&        Array,
                                  size_t                  cPoints,
                                  const LONG*             pPoints,
                                  DBBYTEOFFSET*           pcbOffset,
                                  DBLENGTH*               pcbElementSize,
                                  DBVARIANT::LPCTYPEINFO* ppTypeInfo);

//------------------------------------------------------------------------

// ElementLength is length of element in bytes or in chars (for CHAR/WCHAR)
HRESULT DBVariant_CreateArray(DBTYPE                wElementType,
                              size_t                ElementLength,
                              size_t                cDim,
                              const SAFEARRAYBOUND* rgsaBound,
                              SAFEARRAY**           ppArray);

//------------------------------------------------------------------------
//source            - array variable
//cPoints/pPoints   - coordinate of array element
//dest              - value of specified element
template<class DestVariant>
HRESULT DBVariant_GetArrayElement(const DBVARIANT&   source,
                                  size_t       const cPoints,
                                  const LONG*  const pPoints,
                                  DestVariant&       dest);

//------------------------------------------------------------------------
//dest              - array variable
//cPoints/pPoints   - coordinate of array element
//source            - new value
HRESULT DBVariant_SetArrayElement(DBVARIANT&             ArrayVariant,
                                  size_t           const cPoints,
                                  const LONG*      const pPoints,
                                  const DBVARIANT&       Value,
                                  DBSTATUS*        const pStatus=0);

HRESULT DBVariant_SetArrayElement_1(DBVARIANT&             ArrayVariant,
                                    LONG             const pt1,
                                    const DBVARIANT&       Value,
                                    DBSTATUS*        const pStatus=0);

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib

////////////////////////////////////////////////////////////////////////////////
//inner struct definitions

#include <ole_lib/oledb/variant/oledb_variant_struct.h>

////////////////////////////////////////////////////////////////////////////////
//inline implementations

#include <ole_lib/oledb/variant/oledb_variant.cc>

////////////////////////////////////////////////////////////////////////////////
#endif
