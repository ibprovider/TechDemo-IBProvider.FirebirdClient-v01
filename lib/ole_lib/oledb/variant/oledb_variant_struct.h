////////////////////////////////////////////////////////////////////////////////
//Definition of inner structures of DBVARIANT
//                                            Dmitry Kovalenko. 17 juli, 2002.
#ifndef _oledb_variant_struct_H_
#define _oledb_variant_struct_H_

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT::TTypeConverterMap

class DBVARIANT::TTypeConverterMap
{
 private:
  typedef TTypeConverterMap                               self_type;

  TTypeConverterMap(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TTypeConverterMap(const LPCTYPECONVERTER* pSimpleCvts,
                    size_t                  cSimpleCvts,
                    const LPCTYPECONVERTER* pArrayCvts,
                    size_t                  cArrayCvts);

  LPCTYPECONVERTER get_convertor(DBTYPE TargetType)const;

 private:
  static LPCTYPECONVERTER get_converter(DBTYPE                  TargetType,
                                        const LPCTYPECONVERTER* pCvts,
                                        size_t                  cCvts);

 private:
  const LPCTYPECONVERTER* const m_pSimpleCvts;
  const size_t                  m_cSimpleCvts;
  const LPCTYPECONVERTER* const m_pArrayCvts;
  const size_t                  m_cArrayCvts;
};//class TTypeConverterMap

////////////////////////////////////////////////////////////////////////////////
//inner struct DBVARIANT::TTypeService

struct COMP_CONF_DECLSPEC_NOVTABLE DBVARIANT::TTypeService
{
 private:
  typedef TTypeService                      self_type;

  TTypeService(const self_type&);
  self_type& operator = (const self_type&);

 private:
  const DBTYPE m_wType;

 public: //typedefs
  typedef DBVARIANT::length_type            length_type;
  typedef DBVARIANT::status_type            status_type;
  typedef DBVARIANT::LPCCONVCONTEXT         LPCCONVCONTEXT;

 public:
  TTypeService(DBTYPE const wType)
   :m_wType(wType)
  {;}

  DBTYPE get_type()const
  {
   return m_wType;
  }

 public:
  //! \brief
  //!  getting align of data
  virtual length_type get_align()const=0;

  //get data size (bytes/symbols)
  //array: return element size
  length_type get_length2(const DBVARIANT& dbvar)const;

  //! \brief
  //!  getting binary data presentation length
  //! \param[in] DataLength
  //!  Valid only for STR, WSTR, BYTES data types.
  //!  For other types - 0.
  //! \return
  //!  Bytes count
  virtual length_type get_binary_length(length_type DataLength)const=0;

  //! \brief
  //!  getting data and buffer sizes in bytes
  //! \param[in]  dbvar
  //! \param[out] cbSize
  //!  Length of data in bytes
  //! \param[out] cbMemSize
  //!  Length of data buffer
  //! \param[out] cbMinSize
  //!  Minimal length of data
  void get_size2(const DBVARIANT& dbvar,
                 length_type&     cbSize,
                 length_type&     cbMemSize,
                 length_type&     cbMinSize)const;

  //! \brief
  //!  Get dbvariant data into buffer
  //! \param[in]  dbvar
  //!  source data
  //! \param[in]  Binding
  //!  format
  //! \param[in]  cbMemSize
  //!  buffer size
  //! \param[out] Binding_Status
  //! \param[out] Binding_Length
  //! \param[out] pBuffer
  HRESULT get_data2(const DBVARIANT& dbvar,
                    const DBBINDING& Binding,
                    length_type      cbMemSize,
                    status_type&     Binding_Status,
                    length_type&     Binding_Length,
                    void*            pBuffer)const;

  //Change wType and direct copy an element data
  //Remark: No memory allocation, no AddRef call
  virtual HRESULT get_element(DBVARIANT*   dest,
                              REFIID       ElementIID,
                              length_type  cbElement,
                              const void*  pElement)const=0;

  //Install element data
  virtual HRESULT set_element(LPCCONVCONTEXT   pConvCtx,
                              const DBVARIANT& source,
                              REFIID           ElementIID,
                              length_type      cbElement,
                              void*            pElement,
                              status_type*     pBinding_Status)const=0;

  //get type converter to type
  virtual LPCTYPECONVERTER get_convertor(DBTYPE TargetType)const=0;

  //buiding a print string
  virtual std::wstring get_print_wstr(const DBVARIANT& dbvar)const=0;

 private:
  virtual length_type internal__get_length__ok
   (const DBVARIANT& dbvar)const=0;

  virtual void internal__get_size__ok
   (const DBVARIANT&  dbvar,
    length_type&      cbSize,
    length_type&      cbMemSize,
    length_type&      cbMinSize)const=0;

  virtual HRESULT internal__get_data__ok
   (const DBVARIANT& dbvar,          //source data
    const DBBINDING& Binding,        //format
    length_type      cbMemSize,      //buffer size
    status_type&     Binding_Status, //out
    length_type&     Binding_Length, //out
    void*            pBuffer)const=0;//out

 private:
  COMP_CONF_DECLSPEC_NORETURN
  void helper__throw_bug_check__unexpected_data_status
               (const char* place,
                const char* point,
                DBSTATUS    status)const;
};//DBVARIANT::TTypeService

////////////////////////////////////////////////////////////////////////////////
//inner struct DBVARIANT::TTypeInfo

struct DBVARIANT::TTypeInfo
{
 public: //typedefs
  typedef DBVARIANT::length_type                        length_type;
  typedef BYTE                                          precision_type;
  typedef structure::t_value_with_null<precision_type>  precision_type_N;
  typedef unsigned int                                  flags_type;

 public:
  DBTYPE                 Type;
  const t_oledb_char*    Name;
  length_type            Size;
  precision_type_N       Precision2;
  flags_type             Flags;     //EnumTypeFlags
  const TTypeService*    pTypeService;

  //String presentation info of OLEDB type
  length_type            StringPresentation;

  //Compatibility variant type.
  // VT_EMPTY - for types without equal var-type
  VARTYPE                varType;

 public:
  inline bool VariableLen()         const;
  inline bool FixedLen()            const;
  inline bool FixedPrecisionDigit() const;
  inline bool IsDigit()             const;

  inline bool ICR_Precision()const;
  inline bool ICR_Scale()const;
  inline bool ICR_DateTimePrecision()const;
};//DBVARIANT::TTypeInfo

////////////////////////////////////////////////////////////////////////////////
//inner struct DBVARIANT::TParamInfo

struct DBVARIANT::TParamInfo
{
 public: //typedefs
  typedef DBVARIANT::length_type    length_type;

 public:
  AdoDataTypeEnum      adType;         //ADO type <--> (OLEDB type + dwColumnsFlags)
  DBTYPE               wType;          //OLEDB type
  DBCOLUMNFLAGS        dwColumnFlags;  //additional flags for OLEDB type
  const t_oledb_char*  Name;
  length_type          Size;           //ulParamSize
  EnumTypeFlags        Flags;          //Principle of a memory allocation for value

  const t_oledb_char*  adTypeName;

  inline bool VariableLen() const;
  inline bool FixedLen()    const;
  inline bool IsLong()      const;

  inline void GetParameterFlags(DBPARAMFLAGS& _Flags) const;

  inline bool operator == (AdoDataTypeEnum _adType)const;

  inline bool operator == (const t_oledb_char* _TypeName) const;

  inline bool operator != (AdoDataTypeEnum _adType)const
   {return !(*this==_adType);}

  inline bool operator != (const t_oledb_char* _TypeName) const
   {return !(*this==_TypeName);}
};//struct DBVARIANT::TParamInfo

////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT::TCvtAdapter

class DBVARIANT::TCvtAdapter
{
 private:
  typedef TCvtAdapter                              self_type;

  TCvtAdapter(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TCvtAdapter(){;}
 ~TCvtAdapter(){;}

  const DBVARIANT& dbvar()const
   {return m_dbvar;}

  HRESULT Unpack_Variant(const DBVARIANT& source);

  HRESULT Unpack_Variant(const VARIANT& source);

 private:
  DBVARIANT m_dbvar;
};//class DBVARIANT::TCvtAdapter

////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT::TCvtAdapter_Array

class DBVARIANT::TCvtAdapter_Array
{
 private:
  typedef TCvtAdapter_Array                          self_type;

  TCvtAdapter_Array(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TCvtAdapter_Array();
 ~TCvtAdapter_Array();

  const DBVARIANT& dbvar()const
   {return m_dbvar;}

  HRESULT Detach();

  HRESULT Unpack_VectorUI1_To_Bytes(const DBVARIANT& source);

 private:
  SAFEARRAY*  m_lpsa;
  DBVARIANT   m_dbvar;
};//class DBVARIANT::TCvtAdapter_Array

////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT::TPrinter

class DBVARIANT::TPrinter
{
 private:
  typedef TPrinter                          self_type;

  self_type& operator = (const self_type&);

 public:
  const DBVARIANT& m_dbvar;

  TPrinter(const self_type& x)
   :m_dbvar(x.m_dbvar)
  {;}

  explicit TPrinter(const DBVARIANT& x)
   :m_dbvar(x)
  {;}
};//class DBVARIANT::TPrinter

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
