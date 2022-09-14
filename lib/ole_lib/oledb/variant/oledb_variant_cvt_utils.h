////////////////////////////////////////////////////////////////////////////////
//OLEDB Library. OLEDB Data Types Convertion Utilities
//                                                Kovalenko Dmitry. 05.02.2010.
#ifndef _oledb_variant_cvt_utils_H_
#define _oledb_variant_cvt_utils_H_

#include <ole_lib/oledb/variant/oledb_variant_bytes_writer.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt_fwrd.h>
#include <ole_lib/oledb/oledb_data_types.h>
#include <ole_lib/oledb/oledb_common.h>
#include <structure/t_digit_lib.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT_CVT_UTILS

class DBVARIANT_CVT_UTILS
{
 private:
  typedef DBVARIANT_CVT_UTILS               self_type;

 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

  typedef TDBTypeConverterContext           cvt_ctx_type;

  typedef DBVARIANT_BYTES_WRITER            bytes_writer_type;

  struct tag_power_2;
  struct tag_data;

 public:
  typedef t_oledb_value__CPP_BSTR                             value_cpp_bstr_type;
  typedef structure::t_value_with_null<value_cpp_bstr_type>   value_cpp_bstr_n_type;

 private:
  //clear precision==19 (c_cvt_r8_middle_int_precision)
  typedef unsigned __int64                  cvt_r8_middle_int_type;

  enum
  {
   //we uses a cvt_r8_middle_int_type for builds a r8 value
   c_cvt_r8_middle_int_precision =19
  };//enum

 public: //---------------------------------------------------------------
  //! \todo
  //!  Remove!
  static const size_type npos;

  static const size_t c_min_buffer_size_for_cvt_from_guid_to_text=64;

 public:
  template<typename TPlainOldData>
  static HRESULT StorageObjectToSimpleType_v2
                         (ISequentialStream*                           pSS,
                          structure::t_value_with_null<TPlainOldData>* result);

  static HRESULT StorageObjectToSimpleType_v2(ISequentialStream* pSS,
                                              void*              buffer,
                                              size_type          buffer_size);

  template<class TComSeqStream,class T>
  static HRESULT StorageObjectToBuffer_v2
                          (TComSeqStream*              pSourceStream,
                           DBVARIANT_STREAM_WRITER<T>* pDestStream);

 public:
  static HRESULT BytesToArrayUI1(const void* pvBuffer,
                                 size_type   cbBuffer,
                                 SAFEARRAY** ppArray);

 public: //service for DBTYPE_NUMERIC ------------------------------------
  typedef structure::t_fixed_precision_digit<128> TNumericDigit;

 private:
  static HRESULT Int64ToNumeric(__int64          value,
                                DB_NUMERIC*      dbnum,
                                BYTE             value_precision,
                                int              scale);

  static HRESULT UInt64ToNumeric(unsigned __int64 value,
                                 DB_NUMERIC*      dbnum,
                                 BYTE             value_precision,
                                 int              scale);
 public:
  //установка числа в DB_NUMERIC
  // scale: <0 - value/10^scale
  //        >0 - value*10^scale
  static inline HRESULT IntToNumeric(signed char      ,DB_NUMERIC*,int scale=0);
  static inline HRESULT IntToNumeric(signed short     ,DB_NUMERIC*,int scale=0);
  static inline HRESULT IntToNumeric(signed long      ,DB_NUMERIC*,int scale=0);
  static inline HRESULT IntToNumeric(signed int       ,DB_NUMERIC*,int scale=0);
  static inline HRESULT IntToNumeric(signed __int64   ,DB_NUMERIC*,int scale=0);
  static inline HRESULT IntToNumeric(unsigned char    ,DB_NUMERIC*,int scale=0);
  static inline HRESULT IntToNumeric(unsigned short   ,DB_NUMERIC*,int scale=0);
  static inline HRESULT IntToNumeric(unsigned long    ,DB_NUMERIC*,int scale=0);
  static inline HRESULT IntToNumeric(unsigned int     ,DB_NUMERIC*,int scale=0);
  static inline HRESULT IntToNumeric(unsigned __int64 ,DB_NUMERIC*,int scale=0);
  static inline HRESULT CYToNumeric (const tagCY&     ,DB_NUMERIC*);
  static inline HRESULT CYToNumeric (signed __int64   ,DB_NUMERIC*);

  static HRESULT R8ToNumeric        (double           ,DB_NUMERIC* dbnum);
  static HRESULT R4ToNumeric        (float            ,DB_NUMERIC* dbnum);
  static HRESULT DecimalToNumeric   (const tagDEC&    ,DB_NUMERIC* dbnum);

  //string to DB_NUMERIC
  static HRESULT StrToNumeric       (const char*    str,
                                     size_type      str_size,
                                     DB_NUMERIC*    dbnum);

  static HRESULT WStrToNumeric      (const wchar_t* str,
                                     size_type      str_size,
                                     DB_NUMERIC*    dbnum);

  //VARIANT to DB_NUMERIC
  static HRESULT BoolToNumeric      (VARIANT_BOOL   value,
                                     DB_NUMERIC*    digit);

  //паковка/распаковка DB_NUMERIC
  static HRESULT UnpackNumericDigit (const DB_NUMERIC&    dbnum,
                                     TNumericDigit*       pDigits);

  static HRESULT PackNumericDigit   (const TNumericDigit& digits,
                                     DB_NUMERIC*          pDBNum);

  //приведение DB_NUMERIC к нужному масштабу
  static HRESULT ScaleNumeric    (const DB_NUMERIC& dbnum,BYTE scale,DB_NUMERIC* result_dbnum);

  static HRESULT NumericToInt    (const DB_NUMERIC& dbnum,signed __int64*   pValue);
  static HRESULT NumericToInt    (const DB_NUMERIC& dbnum,unsigned __int64* pValue);

  static HRESULT NumericToR4     (const DB_NUMERIC& dbnum,float*   pValue);
  static HRESULT NumericToR8     (const DB_NUMERIC& dbnum,double*  pValue);

  static HRESULT NumericToCY     (const DB_NUMERIC& dbnum,signed __int64* pValue);
  static inline
         HRESULT NumericToCY     (const DB_NUMERIC& dbnum,tagCY*   pValue);

  static HRESULT NumericToDecimal(const DB_NUMERIC& dbnum,tagDEC*  pValue);

  static HRESULT NumericToString (const DB_NUMERIC& dbnum,std::string*  pStr);
  static HRESULT NumericToString (const DB_NUMERIC& dbnum,std::wstring* pWStr);

  static std::string  NumericToStr    (const DB_NUMERIC& dbnum,bool* error=NULL);
  static std::wstring NumericToWStr   (const DB_NUMERIC& dbnum,bool* error=NULL);

  static HRESULT NumericToBool   (const DB_NUMERIC& dbnum,bool* pValue);

  static HRESULT NumericToVariant(const DB_NUMERIC& dbnum,VARIANT* pVar);

 public: //Service for DBTYPE_DECIMAL ------------------------------------

  //установка числа в tagDEC
  // scale: <0 - value/10^scale
  //        >0 - value*10^scale
  static HRESULT Int64ToDecimal (signed   __int64 value,tagDEC*,int scale);
  static HRESULT UInt64ToDecimal(unsigned __int64 value,tagDEC*,int scale);

  static HRESULT R8ToDecimal    (double value,tagDEC* dec);
  static HRESULT R4ToDecimal    (float  value,tagDEC* dec);

  static inline HRESULT IntToDecimal(signed char      value,tagDEC*,int scale=0);
  static inline HRESULT IntToDecimal(signed short     value,tagDEC*,int scale=0);
  static inline HRESULT IntToDecimal(signed long      value,tagDEC*,int scale=0);
  static inline HRESULT IntToDecimal(signed int       value,tagDEC*,int scale=0);
  static inline HRESULT IntToDecimal(signed __int64   value,tagDEC*,int scale=0);

  static inline HRESULT IntToDecimal(unsigned char    value,tagDEC*,int scale=0);
  static inline HRESULT IntToDecimal(unsigned short   value,tagDEC*,int scale=0);
  static inline HRESULT IntToDecimal(unsigned long    value,tagDEC*,int scale=0);
  static inline HRESULT IntToDecimal(unsigned int     value,tagDEC*,int scale=0);
  static inline HRESULT IntToDecimal(unsigned __int64 value,tagDEC*,int scale=0);

  static inline HRESULT CYToDecimal (const tagCY&     value,tagDEC*);
  static inline HRESULT CYToDecimal (signed __int64   value,tagDEC*);

  static HRESULT StrToDecimal  (const char*    str,size_type str_size,tagDEC*);
  static HRESULT WStrToDecimal (const wchar_t* str,size_type str_size,tagDEC*);

  static HRESULT BoolToDecimal (VARIANT_BOOL value,tagDEC*);

 public:
  //-------------------------
  //приведение DECIMAL к нужному масштабу
  static HRESULT ScaleDecimal    (const tagDEC& decimal,BYTE scale,tagDEC* result_decimal);

  static HRESULT DecimalToInt    (const tagDEC& decimal,signed __int64*   pValue);
  static HRESULT DecimalToInt    (const tagDEC& decimal,unsigned __int64* pValue);

  static HRESULT DecimalToR4     (const tagDEC& decimal,float*   pValue);
  static HRESULT DecimalToR8     (const tagDEC& decimal,double*  pValue);

  static HRESULT DecimalToCY     (const tagDEC& decimal,signed __int64* pValue);
  static inline
         HRESULT DecimalToCY     (const tagDEC& decimal,tagCY* pValue);

  static HRESULT DecimalToStr    (const tagDEC& decimal,std::string*  pStr);
  static HRESULT DecimalToWStr   (const tagDEC& decimal,std::wstring* pWStr);
  static std::string  DecimalToStr    (const tagDEC& decimal,bool* error=NULL);
  static std::wstring DecimalToWStr   (const tagDEC& decimal,bool* error=NULL);

  static HRESULT DecimalToBool   (const tagDEC& decimal,bool* pValue);

  static HRESULT DecimalToVariant(const tagDEC& decimal,VARIANT* pVar);

  //паковка/распаковка tagDEC
  static HRESULT UnpackDecimalDigit(const tagDEC& decimal,TNumericDigit* pDigit);
  static HRESULT PackDecimalDigit  (const TNumericDigit& digits,tagDEC* pDecimal);

 public: //Service for DBTYPE_CY -----------------------------------------
  static inline HRESULT IntToCY (signed char      value,tagCY& cy);
  static inline HRESULT IntToCY (signed short     value,tagCY& cy);
  static inline HRESULT IntToCY (signed long      value,tagCY& cy);
  static inline HRESULT IntToCY (signed int       value,tagCY& cy);

  static inline HRESULT IntToCY (unsigned char    value,tagCY& cy);
  static inline HRESULT IntToCY (unsigned short   value,tagCY& cy);
  static inline HRESULT IntToCY (unsigned long    value,tagCY& cy);
  static inline HRESULT IntToCY (unsigned int     value,tagCY& cy);

  static HRESULT IntToCY  (signed __int64   value,tagCY& cy);
  static HRESULT IntToCY  (unsigned __int64 value,tagCY& cy);

  static HRESULT R8ToCY   (double           value,tagCY& cy);

  static HRESULT BoolToCY (VARIANT_BOOL     value,tagCY& cy);

  static HRESULT StrToCY  (const char*    str,size_type str_size,tagCY* pValue);
  static HRESULT WStrToCY (const wchar_t* str,size_type str_size,tagCY* pValue);

  //---------------------------------------------
  static HRESULT CYToStr  (const tagCY& cy,std::string&  str);
  static HRESULT CYToWStr (const tagCY& cy,std::wstring& str);

  static std::string  CYToStr  (const tagCY& cy,bool*    error=NULL);
  static std::wstring CYToWStr (const tagCY& cy,bool*    error=NULL);

  static HRESULT CYToInt  (const tagCY& cy,signed   __int64& value);
  static HRESULT CYToInt  (const tagCY& cy,unsigned __int64& value);

  static HRESULT CYToR4   (const tagCY& cy,float&  value);
  static HRESULT CYToR8   (const tagCY& cy,double& value);

 public:
  static HRESULT StrToR8  (const char* str,size_type str_size,double* pValue);
  static HRESULT WStrToR8 (const wchar_t* str,size_type str_size,double* pValue);

 public:
  static size_t GuidToStr(const cvt_ctx_type* pCvtCtx,
                          const GUID&         guid,
                          size_t              buffer_size,
                          char                buffer[]);

  static size_t GuidToWStr(const cvt_ctx_type* pCvtCtx,
                           const GUID&         guid,
                           size_t              buffer_size,
                           wchar_t             buffer[]);

 public:
  static HRESULT StrToGUID(const char* const str,size_type length,GUID* pguid);

  static HRESULT WStrToGUID(const wchar_t* const str,size_type length,GUID* pguid);

 public:
  static HRESULT TStrToGUID(const char* const str,size_type length,GUID* pguid);

  static HRESULT TStrToGUID(const wchar_t* const str,size_type length,GUID* pguid);

 public: //Service for DBTYPE_BSTR ---------------------------------------
  static HRESULT EmptyBStr(value_cpp_bstr_n_type* result);

  static HRESULT WStrToBStr(value_cpp_bstr_n_type* result,
                            const wchar_t*         str,
                            size_type              length);

 private:
  template<class charT>
  static HRESULT TextToNumeric(const charT*   str,
                               size_type      str_size,
                               DB_NUMERIC*    dbnum);

  template<class stringT>
  static HRESULT NumericToText(const DB_NUMERIC& dbnum,
                               stringT*          pStr);

 private:
  template<class charT>
  static HRESULT TextToDecimal(const charT*   str,
                               size_type      str_size,
                               tagDEC*        decimal);

  template<class charT>
  static HRESULT TextWithHexNumberToByteArray3(const charT* const  str,
                                               const charT* const  end_str,
                                               BYTE*               value,
                                               size_t       const  value_size);

  template<class charT>
  static HRESULT TextToUnsignedNumericDigit2(const charT*           str,
                                             const charT*    const  end_str,
                                             TNumericDigit&         digit,
                                             size_type&             scale,
                                             size_type       const  c_max_precision,
                                             size_type       const  c_max_scale);

 private:
  template<class charT>
  static HRESULT TextToR8(const charT* str,
                          size_t       length,
                          double*      pDouble);

  static HRESULT ScaleDoubleValue(double& Value,
                                  size_t  Scale,
                                  bool    Scale_IsPositive);

 private:
  static const char sm_hex_chars_u[16];
  static const char sm_hex_chars_l[16];

  //returns: chars in result buffer
  template<class charT>
  static size_t Helper__GuidToText(const cvt_ctx_type* pCvtCtx,
                                   const GUID&         guid,
                                   size_t              buffer_size,
                                   charT               buffer[]);

  template<class charT>
  static HRESULT Helper__TextToGUID(const charT* str,size_t length,GUID* result);

  //Transformation of "xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX" (36 chars) to GUID
  // attention: (end-beg)==36 !
  template<class charT>
  static HRESULT Helper__TextToGUID__HEX(const charT* beg,
                                         const charT* end,
                                         GUID*        result);
 private:
  enum
  {
   gnfp_flag__no_mantisse_sign=0x1
  };//enum

  typedef unsigned                                        gnfp_flags_type;

  template<class charT>
  class tag_float_parts_in_str
  {
   private:
    typedef tag_float_parts_in_str<charT>                 self_type;

   public: //typedefs ------------------------------------------------------
    typedef charT                                         char_type;
    typedef const char_type*                              const_pointer;

    enum enum_sign_kind
    {
     sign_kind__undefined  =0,
     sign_kind__positive   =1,
     sign_kind__negative   =2,
    };//enum enum_sign_kind

    typedef enum_sign_kind                                sign_kind_type;

   public:
    sign_kind_type mantisse_sign;

    const_pointer  int_part_beg;
    const_pointer  int_part_end;

    const_pointer  float_part_beg;
    const_pointer  float_part_end;

    sign_kind_type scale_sign;

    const_pointer  scale_part_beg;
    const_pointer  scale_part_end;

   public:
    tag_float_parts_in_str();

    void init();
  };//class tag_float_parts_in_str

  template<class charT>
  static HRESULT GetFloatNumberParts(const charT*                   str,
                                     const charT*                   end_str,
                                     gnfp_flags_type                gnfp_flags,
                                     const charT**                  pos_str,
                                     tag_float_parts_in_str<charT>* parts);

 private:
  static bool Helper__UnpackDecimalDigit__ProcessPart
               (TNumericDigit* pResult,
                DWORD          dwPart,
                unsigned       pow2);
};//class DBVARIANT_CVT_UTILS

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/variant/converter_utils/oledb_var_cvt_utils.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
