////////////////////////////////////////////////////////////////////////////////
//Template class for RW-Wrapper of DBVARIANT
//                                               Kovalenko Dmitry. 27.10.2008.
#ifndef _oledb_xvariant_H_
#define _oledb_xvariant_H_

#include <ole_lib/oledb/variant/oledb_variant.h>
#include <ole_lib/oledb/variant/oledb_xvariant_stream_writer.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class basic_dbnull

template<DBTYPE typeID>
struct basic_dbnull
{
};

////////////////////////////////////////////////////////////////////////////////

static const basic_dbnull<DBTYPE_I1>             DBNull_I1;
static const basic_dbnull<DBTYPE_I2>             DBNull_I2;
static const basic_dbnull<DBTYPE_I4>             DBNull_I4;
static const basic_dbnull<DBTYPE_I8>             DBNull_I8;

static const basic_dbnull<DBTYPE_UI1>            DBNull_UI1;
static const basic_dbnull<DBTYPE_UI2>            DBNull_UI2;
static const basic_dbnull<DBTYPE_UI4>            DBNull_UI4;
static const basic_dbnull<DBTYPE_UI8>            DBNull_UI8;

static const basic_dbnull<DBTYPE_R4>             DBNull_R4;
static const basic_dbnull<DBTYPE_R8>             DBNull_R8;

static const basic_dbnull<DBTYPE_NUMERIC>        DBNull_NUMERIC;
static const basic_dbnull<DBTYPE_DECIMAL>        DBNull_DECIMAL;

static const basic_dbnull<DBTYPE_BOOL>           DBNull_BOOL;

static const basic_dbnull<DBTYPE_STR>            DBNull_STR;
static const basic_dbnull<DBTYPE_WSTR>           DBNull_WSTR;

static const basic_dbnull<DBTYPE_GUID>           DBNull_GUID;

static const basic_dbnull<DBTYPE_IUNKNOWN>       DBNull_IUNKNOWN;
static const basic_dbnull<DBTYPE_IDISPATCH>      DBNull_IDISPATCH;

static const basic_dbnull<DBTYPE_DATE>           DBNull_DATE;
static const basic_dbnull<DBTYPE_DBDATE>         DBNull_DBDATE;
static const basic_dbnull<DBTYPE_DBTIME>         DBNull_DBTIME;
static const basic_dbnull<DBTYPE_DBTIMESTAMP>    DBNull_DBTIMESTAMP;

static const basic_dbnull<oledb_typeid__DBTIME2> DBNull_DBTIME2;

////////////////////////////////////////////////////////////////////////////////

static const basic_dbnull<DBTYPEFOR_DBROWCOUNT>  DBNull_DBROWCOUNT;

////////////////////////////////////////////////////////////////////////////////
//class basic_dbvariant

template<class Allocator>
class basic_dbvariant:public DBVARIANT
{
 private:
  typedef basic_dbvariant<Allocator>                          self_type;
  typedef self_type                                           dbvariant_type;

 public: //typedefs ------------------------------------------------------
  typedef Allocator                                           allocator_type;

 protected:
  typedef __STLS_ALLOCATOR_REBIND(typename Allocator,char)    str_allocator_type;
  typedef __STLS_ALLOCATOR_REBIND(typename Allocator,wchar_t) wstr_allocator_type;

  typedef const SAFEARRAY*                                    LPCSAFEARRAY;

 private: // -------------------------------------------------------------
  typedef __STLS_ALLOCATOR_REBIND(typename Allocator,void)    raw_allocator_type;

  static raw_allocator_type   sm_alloc;

 public: // constructors -------------------------------------------------
  basic_dbvariant();
  basic_dbvariant(const self_type& data);
  basic_dbvariant(const DBVARIANT& data);

  basic_dbvariant(const char*    data);
  basic_dbvariant(const wchar_t* data);

  basic_dbvariant(const structure::t_const_str_box&  data);
  basic_dbvariant(const structure::t_const_wstr_box& data);

  basic_dbvariant(const ole_lib::TBSTR&      data);

  basic_dbvariant(const value_numeric_type&  data);
  basic_dbvariant(const value_decimal_type&  data);

  basic_dbvariant(bool                  data);

  basic_dbvariant(value_i1_type         data);
  basic_dbvariant(value_ui1_type        data);

  basic_dbvariant(value_i2_type         data);
  basic_dbvariant(value_ui2_type        data);

  basic_dbvariant(value_i4_type         data);
  basic_dbvariant(value_ui4_type        data);

  basic_dbvariant(value_long_type       data);
  basic_dbvariant(value_ulong_type      data);

  basic_dbvariant(value_r4_type         data);
  basic_dbvariant(value_r8_type         data);

  basic_dbvariant(value_i8_type_s       data);
  basic_dbvariant(value_ui8_type_s      data);

  basic_dbvariant(value_i8_type         data);
  basic_dbvariant(value_ui8_type        data);

  basic_dbvariant(value_cy_type               x);

  basic_dbvariant(const value_guid_type&      x);

  basic_dbvariant(const value_dbdate_type&    x);
  basic_dbvariant(const value_dbtime_type&    x);
  basic_dbvariant(const value_dbtime2_type&   x);
  basic_dbvariant(const value_dbstamp_type&   x);
  basic_dbvariant(const value_filetime_type&  x);

  basic_dbvariant(IUnknown* data,REFIID riid);
  basic_dbvariant(IUnknown* data);

  basic_dbvariant(IDispatch* data);

  basic_dbvariant(const VARIANT* data,bool unpack=true);
  basic_dbvariant(const VARIANT& data,bool unpack=true);

  basic_dbvariant(DBTYPE wElementType,LPCSAFEARRAY lpArray);

  basic_dbvariant(const value_i1_n_type& x);
  basic_dbvariant(const value_i2_n_type& x);
  basic_dbvariant(const value_i4_n_type& x);
  basic_dbvariant(const value_i8_n_type& x);

  basic_dbvariant(const value_ui1_n_type& x);
  basic_dbvariant(const value_ui2_n_type& x);
  basic_dbvariant(const value_ui4_n_type& x);
  basic_dbvariant(const value_ui8_n_type& x);

  basic_dbvariant(const value_r4_n_type& x);
  basic_dbvariant(const value_r8_n_type& x);

  basic_dbvariant(const value_numeric_n_type& x);
  basic_dbvariant(const value_decimal_n_type& x);

  basic_dbvariant(const value_cpp_bool_n_type& x);

  basic_dbvariant(const value_guid_n_type& x);

  basic_dbvariant(const value_dbdate_n_type&  x);
  basic_dbvariant(const value_dbtime_n_type&  x);
  basic_dbvariant(const value_dbtime2_n_type& x);
  basic_dbvariant(const value_dbstamp_n_type& x);
  basic_dbvariant(const value_filetime_n_type& x);

  basic_dbvariant(const value_cpp_str_n_type& x);
  basic_dbvariant(const value_cpp_wstr_n_type& x);

  template<DBTYPE typeID>
  basic_dbvariant(basic_dbnull<typeID> x);

 ~basic_dbvariant();

  //selectors ------------------------------------------------------------
  allocator_type& get_allocator() {return sm_alloc;}

  //modificators ---------------------------------------------------------
  void swap(self_type& x);

  self_type& Clear(); //освобождение данных

  //----------------------------------------------------------------------
  self_type& SetDefault_STD();

  //modificators [assign new value] --------------------------------------
  self_type& SetDBNull();

  self_type& SetError(value_scode_type          _scode);
  self_type& SetError(const value_scode_n_type& _scode);

  //резервирует size байт и устанавливает тип DBTYPE_BYTES
  //повторно использует ранее выделенную память
  self_type& ReserveBytes(size_type cbReserve,size_type cbBytes,const void* pvBytes); //throw

 public:
  self_type& SetBSTR(const BSTR); //throw

  self_type& SetStrAsBSTR(const structure::t_const_str_box& data); //throw

  self_type& SetWStrAsBSTR(const structure::t_const_wstr_box& data); //throw

 public:
  //unpack==true разрешает распаковку данных, переданных через VARIANT
  //             это увеличивает скорость и снижает потребление памяти
  //             unpack: SetData/ =VARIANT
  //запрещение производиться в том случае, когда дальнейшая работа
  //             производиться именно с VARIANT представлением данных
  //             - assign_as/ =DBVARIANT
  self_type& SetVariant(const VARIANT* data,bool unpack); //throw

  self_type& SetVariant(const VARIANT& data,bool unpack);

  self_type& SetBytes(const void* data,size_type length);

  self_type& SetBytesAsSS(const void* data,size_type length);

  self_type& AllocBytes(size_type length);

  self_type& SetStr(const structure::t_const_str_box& data);

  self_type& AllocStr(size_type length);
  self_type& TruncStr(size_type length);

  self_type& SetWStr(const structure::t_const_wstr_box& data);

  self_type& AllocWStr(size_type length);
  self_type& TruncWStr(size_type length);

  self_type& SetNumeric(const value_numeric_type& data);

  self_type& SetDecimal(const value_decimal_type& data);

  self_type& SetDate(value_date_type          data);
  self_type& SetDate(const value_date_n_type& data);

  self_type& SetGuid(const value_guid_type& data);

  self_type& SetDBDate(const value_dbdate_type& data);

  self_type& SetDBDate(SHORT  Year,
                       USHORT Month,
                       USHORT Day);

  self_type& SetDBTime(const value_dbtime_type& data);

  self_type& SetDBTime(USHORT Hour,
                       USHORT Minute,
                       USHORT Second);

  self_type& SetDBTime2(const value_dbtime2_type& data);

  self_type& SetDBTime2(USHORT Hour,
                        USHORT Minute,
                        USHORT Second,
                        ULONG  Fraction);

  self_type& SetTimeStamp(const value_dbstamp_type& data);

  self_type& SetTimeStamp(SHORT  Year,
                          USHORT Month,
                          USHORT Day);

  self_type& SetTimeStamp(SHORT  Year,
                          USHORT Month,
                          USHORT Day,
                          USHORT Hour,
                          USHORT Minute,
                          USHORT Second,
                          ULONG  Fraction);

  self_type& SetFileTime(const value_filetime_type& data);

  self_type& SetCY(const value_cy_type& data);
  self_type& SetCY(value_i8_type        data);

 public:
  self_type& SetUnknown(IUnknown* pUnk,
                        REFIID    riid);

  self_type& SetUnknown(IUnknown* pUnk);

  self_type& SetDispatch(IDispatch* pDisp);

 public:
  self_type& operator = (const DBVARIANT& data);

  self_type& operator = (const self_type& data);

  self_type& operator = (const char* data)
   {return this->SetStr(data);}

  self_type& operator = (const structure::t_const_str_box& data)
   {return this->SetStr(data);}

  self_type& operator = (const wchar_t* data)
   {return this->SetWStr(data);}

  self_type& operator = (const structure::t_const_wstr_box& data)
   {return this->SetWStr(data);}

  self_type& operator = (const value_numeric_type& data)
   {return this->SetNumeric(data);}

  self_type& operator = (const value_decimal_type& data)
   {return this->SetDecimal(data);}

  self_type& operator = (const ole_lib::TBSTR& data)
   {return this->SetBSTR(data);}

  self_type& operator = (bool             data);

  self_type& operator = (value_i1_type    data);
  self_type& operator = (value_ui1_type   data);
  self_type& operator = (value_i2_type    data);
  self_type& operator = (value_ui2_type   data);
  self_type& operator = (value_i4_type    data);
  self_type& operator = (value_ui4_type   data);
  self_type& operator = (value_r4_type    data);
  self_type& operator = (value_r8_type    data);
  self_type& operator = (value_i8_type_s  data);
  self_type& operator = (value_ui8_type_s data);
  self_type& operator = (value_i8_type    data);
  self_type& operator = (value_ui8_type   data);

  self_type& operator = (value_cy_type    data)
   {return this->SetCY(data);}

  self_type& operator = (value_long_type        data);

  self_type& operator = (value_ulong_type       data);

  self_type& operator = (const value_guid_type& data)
   {return this->SetGuid(data);}

  self_type& operator = (const value_dbdate_type& data)
   {return this->SetDBDate(data);}

  self_type& operator = (const value_dbtime_type& data)
   {return this->SetDBTime(data);}

  self_type& operator = (const value_dbtime2_type& data)
   {return this->SetDBTime2(data);}

  self_type& operator = (const value_dbstamp_type& data)
   {return this->SetTimeStamp(data);}

  self_type& operator = (const value_filetime_type& data)
   {return this->SetFileTime(data);}

  self_type& operator = (const VARIANT* data)
   {return this->SetVariant(data,/*unpack*/true);}

  self_type& operator = (const VARIANT& data)
   {return this->SetVariant(&data,/*unpack*/true);}

  self_type& operator = (IUnknown*      data)
   {return this->SetUnknown(data);}

  self_type& operator = (IDispatch*     data)
   {return this->SetDispatch(data);}

 public: //support t_value_with_null types -------------------------------
  self_type& operator = (const value_i1_n_type&       x);
  self_type& operator = (const value_i2_n_type&       x);
  self_type& operator = (const value_i4_n_type&       x);
  self_type& operator = (const value_i8_n_type&       x);
  self_type& operator = (const value_long_n_type&     x);

  self_type& operator = (const value_ui1_n_type&      x);
  self_type& operator = (const value_ui2_n_type&      x);
  self_type& operator = (const value_ui4_n_type&      x);
  self_type& operator = (const value_ui8_n_type&      x);
  self_type& operator = (const value_ulong_n_type&    x);

  self_type& operator = (const value_r4_n_type&       x);
  self_type& operator = (const value_r8_n_type&       x);

  self_type& operator = (const value_cy_n_type&       x);
  self_type& operator = (const value_decimal_n_type&  x);
  self_type& operator = (const value_numeric_n_type&  x);

  self_type& operator = (const value_cpp_bool_n_type& x);

  self_type& operator = (const value_cpp_str_n_type&  x);
  self_type& operator = (const value_cpp_wstr_n_type& x);

  self_type& operator = (const value_dbdate_n_type&   x);
  self_type& operator = (const value_dbtime_n_type&   x);
  self_type& operator = (const value_dbtime2_n_type&  x);
  self_type& operator = (const value_dbstamp_n_type&  x);
  self_type& operator = (const value_filetime_n_type& x);

  self_type& operator = (const value_guid_n_type&     x);

  self_type& operator = (const value_unknown_n_type&  x);
  self_type& operator = (const value_dispatch_n_type& x);

 public:
  template<DBTYPE typeID>
  self_type& operator = (basic_dbnull<typeID> x);

 public: //The utilities of transformation
  HRESULT assign_as_ex(LPCCONVCONTEXT   pConvCtx,
                       const DBVARIANT& source,
                       const DBBINDING& bind);

  HRESULT assign_as_ex(LPCCONVCONTEXT   pConvCtx,
                       const DBVARIANT& source,
                       const DBTYPE     wTargetType);

  HRESULT assign_as(const DBVARIANT& source,
                    const DBBINDING& bind);

  HRESULT assign_as(const DBVARIANT& source,
                    const DBTYPE     wTargetType);

 public: //Retrive data to buffer ----------------------------------------
  HRESULT GetDataEx(LPCCONVCONTEXT   pConvCtx,
                    const DBBINDING& Binding,
                    void*            pData)const;

  HRESULT GetData(const DBBINDING& Binding,
                  void*            pData)const;

 public: //Assign data from buffer ---------------------------------------
  typedef unsigned int  setdata_flags;

 private: //internal flags
  //setdata_isclient     =0x00, //[standart assign of data]

  //analyse correct of Status data (DBPART_STATUS)
  static const setdata_flags setdata_isprovider   =0x01;

 public: //public flags
  static const setdata_flags setdata_addref__unk  =0x10;

  //after data assign, can use buffer again
  static const setdata_flags setdata_copy         =setdata_addref__unk;

 public:
  HRESULT SetData__Provider(const DBBINDING& Binding,
                            void*            pData);

  HRESULT SetData__Client(const DBBINDING& Binding,
                          void*            pData,
                          setdata_flags    SetDataFlags);

 public:
  //methods for work with arrays -----------------------------------------

  self_type& CreateArray(DBTYPE                wElementType,
                         size_t                ElementLength,
                         size_t                cDim,
                         const SAFEARRAYBOUND* rgsaBound);//throw

  self_type& SetArray(DBTYPE       wElementType,
                      LPCSAFEARRAY lpArray);

  self_type& SetArray(DBTYPE       wElementType,
                      REFIID       ElementIID,
                      LPCSAFEARRAY lpArray);

  //
  // Create array of elements of wElementType
  //
  // ElementLength - size of variable length elements
  //                 DBTYPE_STR/DBTYPE_WSTR - in symbol
  //                 DBTYPE_BYTES           - in bytes
  //                 for other types is used a known size
  // cDim          - count of dimensions
  // rgsaBound     - data for the each dimension
  //
  // for VT element types used LCPI_OS__SafeArrayCreate
  // 
  // for other element types will use two steps creation process:
  //   1 LCPI_OS__SafeArrayAllocDescriptor + set cbElements=count of bytes
  //   2 LCPI_OS__SafeArrayAllocData
  //
  HRESULT CreateArray_HR(DBTYPE                wElementType,
                         size_t                ElementLength,
                         REFIID                ElementIID,
                         size_t                cDim,
                         const SAFEARRAYBOUND* rgsaBound);

  HRESULT CreateArray_HR(DBTYPE                wElementType,
                         size_t                ElementLength,
                         size_t                cDim,
                         const SAFEARRAYBOUND* rgsaBound);

  //copy lpArray and set wElementType|DBTYPE_ARRAY as DBVARAINT::wType
  //use assert((wElementType&DBTYPE_ARRAY)==0)
  HRESULT SetArray_HR(DBTYPE       wElementType,
                      REFIID       ElementIID,
                      LPCSAFEARRAY lpArray);

  HRESULT SetArray_HR(DBTYPE       wElementType,
                      LPCSAFEARRAY lpArray);

 private: //--------------------------------------------------------------
  typedef status_type (*set_data_func_type)(dbvariant_type&  x,
                                            const DBBINDING& bind,
                                            length_type      Length,
                                            void*            pValue,
                                            setdata_flags    SetDataFlags);

  struct tag_set_func
  {
  #ifndef NDEBUG
   DBTYPE              wType;
  #endif
   set_data_func_type  func;
  };//tag_set_func

 public:
  static const tag_set_func sm_set_data_funcs[146];

  //query utility for assign single value from buffer
  //return NULL for unknown wType
  static set_data_func_type get_set_data_func(DBTYPE wType);

 public:
 #define DECLARE_DBVARIANT_SET_DATA_FUNC(type)                      \
  static status_type set_data_##type(dbvariant_type&  x,            \
                                     const DBBINDING& bind,         \
                                     length_type      Length,       \
                                     void*            pValue,       \
                                     setdata_flags    SetDataFlags)

  DECLARE_DBVARIANT_SET_DATA_FUNC(EMPTY);
  DECLARE_DBVARIANT_SET_DATA_FUNC(NULL);
  DECLARE_DBVARIANT_SET_DATA_FUNC(I2);
  DECLARE_DBVARIANT_SET_DATA_FUNC(I4);
  DECLARE_DBVARIANT_SET_DATA_FUNC(R4);
  DECLARE_DBVARIANT_SET_DATA_FUNC(R8);
  DECLARE_DBVARIANT_SET_DATA_FUNC(CY);
  DECLARE_DBVARIANT_SET_DATA_FUNC(DATE);
  DECLARE_DBVARIANT_SET_DATA_FUNC(BSTR);
  DECLARE_DBVARIANT_SET_DATA_FUNC(IDISPATCH);
  DECLARE_DBVARIANT_SET_DATA_FUNC(ERROR);
  DECLARE_DBVARIANT_SET_DATA_FUNC(BOOL);
  DECLARE_DBVARIANT_SET_DATA_FUNC(VARIANT);
  DECLARE_DBVARIANT_SET_DATA_FUNC(IUNKNOWN);
  DECLARE_DBVARIANT_SET_DATA_FUNC(DECIMAL);
  DECLARE_DBVARIANT_SET_DATA_FUNC(I1);
  DECLARE_DBVARIANT_SET_DATA_FUNC(UI1);
  DECLARE_DBVARIANT_SET_DATA_FUNC(UI2);
  DECLARE_DBVARIANT_SET_DATA_FUNC(UI4);
  DECLARE_DBVARIANT_SET_DATA_FUNC(I8);
  DECLARE_DBVARIANT_SET_DATA_FUNC(UI8);
  DECLARE_DBVARIANT_SET_DATA_FUNC(FILETIME);
  DECLARE_DBVARIANT_SET_DATA_FUNC(GUID);
  DECLARE_DBVARIANT_SET_DATA_FUNC(BYTES);
  DECLARE_DBVARIANT_SET_DATA_FUNC(STR);
  DECLARE_DBVARIANT_SET_DATA_FUNC(WSTR);
  DECLARE_DBVARIANT_SET_DATA_FUNC(NUMERIC);
  DECLARE_DBVARIANT_SET_DATA_FUNC(DBDATE);
  DECLARE_DBVARIANT_SET_DATA_FUNC(DBTIME);
  DECLARE_DBVARIANT_SET_DATA_FUNC(DBTIME2);
  DECLARE_DBVARIANT_SET_DATA_FUNC(DBTIMESTAMP);

  DECLARE_DBVARIANT_SET_DATA_FUNC(ARRAY);
  DECLARE_DBVARIANT_SET_DATA_FUNC(BADACCESSOR); //used for process of errors
 #undef DECLARE_DBVARIANT_SET_DATA_FUNC

 private: //typedefs -----------------------------------------------------
  typedef void (*copy_func_type)(dbvariant_type&  dest,
                                 const DBVARIANT& source);

 private:
  static const copy_func_type sm_copy_funcs[146];

 private:
  //Requirements:
  // 0. &dest!=&source
  // 1. not null
  // 2. correct type of source data

 #define DECLARE_DBVARIANT_COPY_FUNC(suffix)                       \
  static void copy_##suffix(dbvariant_type&  dest,                 \
                            const DBVARIANT& source)

  //copy DBVARIANT througn memcpy
  DECLARE_DBVARIANT_COPY_FUNC(EMPTY);
  DECLARE_DBVARIANT_COPY_FUNC(NULL);

  DECLARE_DBVARIANT_COPY_FUNC(I1);
  DECLARE_DBVARIANT_COPY_FUNC(I2);
  DECLARE_DBVARIANT_COPY_FUNC(I4);
  DECLARE_DBVARIANT_COPY_FUNC(I8);

  DECLARE_DBVARIANT_COPY_FUNC(UI1);
  DECLARE_DBVARIANT_COPY_FUNC(UI2);
  DECLARE_DBVARIANT_COPY_FUNC(UI4);
  DECLARE_DBVARIANT_COPY_FUNC(UI8);

  DECLARE_DBVARIANT_COPY_FUNC(R4);
  DECLARE_DBVARIANT_COPY_FUNC(R8);

  DECLARE_DBVARIANT_COPY_FUNC(CY);
  DECLARE_DBVARIANT_COPY_FUNC(DECIMAL);
  DECLARE_DBVARIANT_COPY_FUNC(NUMERIC);

  DECLARE_DBVARIANT_COPY_FUNC(DATE);
  DECLARE_DBVARIANT_COPY_FUNC(FILETIME);
  DECLARE_DBVARIANT_COPY_FUNC(DBDATE);
  DECLARE_DBVARIANT_COPY_FUNC(DBTIME);
  DECLARE_DBVARIANT_COPY_FUNC(DBTIME2);
  DECLARE_DBVARIANT_COPY_FUNC(DBTIMESTAMP);

  DECLARE_DBVARIANT_COPY_FUNC(GUID);

  DECLARE_DBVARIANT_COPY_FUNC(BOOL);

  DECLARE_DBVARIANT_COPY_FUNC(ERROR);

  DECLARE_DBVARIANT_COPY_FUNC(BSTR);
  DECLARE_DBVARIANT_COPY_FUNC(VARIANT);
  DECLARE_DBVARIANT_COPY_FUNC(IDISPATCH);
  DECLARE_DBVARIANT_COPY_FUNC(IUNKNOWN);
  DECLARE_DBVARIANT_COPY_FUNC(STR);
  DECLARE_DBVARIANT_COPY_FUNC(WSTR);
  DECLARE_DBVARIANT_COPY_FUNC(BYTES);

 #undef DECLARE_DBVARIANT_COPY_FUNC

 private: //typedefs -----------------------------------------------------
  //pointer to transformation utility
  typedef HRESULT (*assign_as_func_type)(LPCCONVCONTEXT   pConvCtx,
                                         dbvariant_type&  dest,
                                         const DBVARIANT& source,
                                         const DBBINDING& bind);

 private: //map of OLEDB types transformations
  static const assign_as_func_type sm_assign_as_funcs[146];

 private:
 #define DECLARE_DBVARIANT_ASSIGN_AS(type)                            \
  static HRESULT assign_as_##type(LPCCONVCONTEXT    pConvCtx,         \
                                  dbvariant_type&   dest,             \
                                  const DBVARIANT&  source,           \
                                  const DBBINDING&  bind)

  DECLARE_DBVARIANT_ASSIGN_AS(I2);
  DECLARE_DBVARIANT_ASSIGN_AS(I4);
  DECLARE_DBVARIANT_ASSIGN_AS(R4);
  DECLARE_DBVARIANT_ASSIGN_AS(R8);
  DECLARE_DBVARIANT_ASSIGN_AS(CY);
  DECLARE_DBVARIANT_ASSIGN_AS(DATE);
  DECLARE_DBVARIANT_ASSIGN_AS(BSTR);
  DECLARE_DBVARIANT_ASSIGN_AS(IDISPATCH);
  DECLARE_DBVARIANT_ASSIGN_AS(ERROR);
  DECLARE_DBVARIANT_ASSIGN_AS(BOOL);
  DECLARE_DBVARIANT_ASSIGN_AS(VARIANT);
  DECLARE_DBVARIANT_ASSIGN_AS(IUNKNOWN);
  DECLARE_DBVARIANT_ASSIGN_AS(DECIMAL);
  DECLARE_DBVARIANT_ASSIGN_AS(I1);
  DECLARE_DBVARIANT_ASSIGN_AS(UI1);
  DECLARE_DBVARIANT_ASSIGN_AS(UI2);
  DECLARE_DBVARIANT_ASSIGN_AS(UI4);
  DECLARE_DBVARIANT_ASSIGN_AS(I8);
  DECLARE_DBVARIANT_ASSIGN_AS(UI8);
  DECLARE_DBVARIANT_ASSIGN_AS(FILETIME);
  DECLARE_DBVARIANT_ASSIGN_AS(GUID);
  DECLARE_DBVARIANT_ASSIGN_AS(BYTES);
  DECLARE_DBVARIANT_ASSIGN_AS(STR);
  DECLARE_DBVARIANT_ASSIGN_AS(WSTR);
  DECLARE_DBVARIANT_ASSIGN_AS(NUMERIC);
  DECLARE_DBVARIANT_ASSIGN_AS(DBDATE);
  DECLARE_DBVARIANT_ASSIGN_AS(DBTIME);
  DECLARE_DBVARIANT_ASSIGN_AS(DBTIME2);
  DECLARE_DBVARIANT_ASSIGN_AS(DBTIMESTAMP);

  DECLARE_DBVARIANT_ASSIGN_AS(ARRAY);

 #undef DECLARE_DBVARIANT_ASSIGN_AS

 private:
  COMP_CONF_DECLSPEC_NORETURN
  static void helper__throw_bug_check__bad_data_status
               (const char* place,
                const char* point,
                DBSTATUS    status);
};//class basic_dbvariant

typedef basic_dbvariant<> TDBVariant;

/////////////////////////////////////////////////////////////////////////////////
//class basic_dbvariant_converter

template<class DBVariant>
class basic_dbvariant_converter
{
 private:
  typedef basic_dbvariant_converter<DBVariant>      self_type;

  basic_dbvariant_converter(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef DBVariant                                 dbvariant_type;
  typedef typename DBVARIANT::LPCCONVCONTEXT        LPCCONVCONTEXT;

 public:
  basic_dbvariant_converter()
   :m_pResult(NULL)
  {;}

  const DBVARIANT* result()const
   {return m_pResult;}

 public:
  HRESULT convert(const DBVARIANT* &dest,
                  const DBVARIANT& source,
                  DBTYPE           wType);

  HRESULT convert(const DBVARIANT& source,
                  DBTYPE           wType);

  HRESULT convert_ex(LPCCONVCONTEXT    pConvCtx,
                     const DBVARIANT*& dest,
                     const DBVARIANT&  source,
                     DBTYPE            wType);

  HRESULT convert_ex(LPCCONVCONTEXT   pConvCtx,
                     const DBVARIANT& source,
                     DBTYPE           wType);

 private:
  dbvariant_type   m_tmp;
  const DBVARIANT* m_pResult;
};//class basic_dbvariant_converter

typedef basic_dbvariant_converter<TDBVariant> TDBVariantConverter;

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib

////////////////////////////////////////////////////////////////////////////////
//std specialization

namespace std{
////////////////////////////////////////////////////////////////////////////////

template<class Allocator>
inline void swap(oledb_lib::basic_dbvariant<Allocator>& x1,
                 oledb_lib::basic_dbvariant<Allocator>& x2)
{
 x1.swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std

////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/variant/oledb_xvariant.cc>
#include <ole_lib/oledb/variant/oledb_xvariant_array.cc>
#include <ole_lib/oledb/variant/oledb_xvariant_assign.cc>
#include <ole_lib/oledb/variant/oledb_xvariant_assign_as.cc>
#include <ole_lib/oledb/variant/oledb_xvariant_copy.cc>
#include <ole_lib/oledb/variant/oledb_xvariant_set.cc>
#include <ole_lib/oledb/variant/oledb_xvariant_set_data__provider.cc>
#include <ole_lib/oledb/variant/oledb_xvariant_set_data__client.cc>
#include <ole_lib/oledb/variant/oledb_xvariant_get.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
