////////////////////////////////////////////////////////////////////////////////
//Common classes for write OLEDB providers and OLEDB clients
//                                               Dmitry Kovalenko. xx.03.2000.
#ifndef _oledb_common_H_
#define _oledb_common_H_

//#include <ole_lib/oledb/oledb_guids.h>
//#include <ole_lib/oledb/oledb_std.h>
#include <ole_lib/oledb/oledb_char.h>
#include <ole_lib/oledb/oledb_datatypes.h>
#include <ole_lib/oledb/oledb_ado_datatype_ids.h>
#include <ole_lib/oledb/oledb_memory.h>
//#include <ole_lib/ole_lib.h>
#include <structure/t_smart_object.h>
#include <structure/t_const_str_box.h>
#include <structure/t_explicit.h>
#include <structure/t_built_in_array.h>
#include <structure/t_negative_one.h>

////////////////////////////////////////////////////////////////////////////////

#define FAILED_DBSTATUS(s) ((s)!=DBSTATUS_S_OK     &&  \
                            (s)!=DBSTATUS_S_ISNULL &&  \
                            (s)!=DBSTATUS_S_TRUNCATED)

#define OLEDB_EXTRACT_DBTYPE(wType)                                       \
 (DBTYPE((wType)&(~DBTYPE_BYREF)))

#define OLEDB_EXTRACT_SIMPLE_DBTYPE(wType)                                \
 (DBTYPE((wType)&(~(DBTYPE_BYREF|DBTYPE_VECTOR|DBTYPE_ARRAY))))

#define OLEDB_EXTRACT_DBTYPE_INDICATOR(wType)                             \
 (DBTYPE(OLEDB_EXTRACT_DBTYPE(wType)&DBTYPE(DBTYPE_VECTOR|DBTYPE_ARRAY)))

//STATUS helpers, for locating obStatus offsets in the bindings
#define OLEDB_STATUS_IS_BOUND(Binding)    ( (Binding).dwPart & DBPART_STATUS )
#define OLEDB_BINDING_STATUS(Binding, p)  (*(DBSTATUS*)((BYTE*)(p) + (Binding).obStatus))

//LENGTH helpers, for locating obLength offsets in the bindings
#define OLEDB_LENGTH_IS_BOUND(Binding)    ( (Binding).dwPart & DBPART_LENGTH )
#define OLEDB_BINDING_LENGTH(Binding, p)  (*(DBLENGTH*)((BYTE*)(p) + (Binding).obLength))

//VALUE helpers, for locating obValue offsets in the bindings
#define OLEDB_VALUE_IS_BOUND(Binding)     ( (Binding).dwPart & DBPART_VALUE )
#define OLEDB_BINDING_VALUE(Binding, p)   (*(void**)((BYTE*)(p) + (Binding).obValue))

//////////////////////////////////////////////////////////////////////////

#define SUCCEEDED_DBROWSTATUS(x)            \
 oledb_lib::oledb_succeeded_dbrowstatus(x)

#define FAILED_DBROWSTATUS(x)               \
 oledb_lib::oledb_failed_dbrowstatus(x)

//////////////////////////////////////////////////////////////////////////

//проверка допустимости дальнейшей обработки данных
#define OLEDB_SUCCEEDED(hr)                 \
 oledb_lib::oledb_succeeded(hr)

#define OLEDB_FAILED(hr)                    \
 oledb_lib::oledb_failed(hr)

#define OLEDB_ERRORSOCCURRED(hr)            \
 oledb_lib::oledb_errorsoccurred(hr)

////////////////////////////////////////////////////////////////////////////////

#define OLEDB_DECIMAL_SCALE(decimal) (*(BYTE*)(&((decimal).signscale)))

#define OLEDB_DECIMAL_SIGN(decimal)  (*(((BYTE*)(&((decimal).signscale)))+1))

////////////////////////////////////////////////////////////////////////////////

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//the block alignment at data buffer

const size_t OLEDB_MEM_SIZE_ALIGN     =8;

////////////////////////////////////////////////////////////////////////////////
//Smart pointers

//CoType TDataSource
DECLARE_IPTR_TYPE(IDBInitialize)          ;
DECLARE_IPTR_TYPE(IDBCreateSession)       ;
DECLARE_IPTR_TYPE(IDBProperties)          ;
DECLARE_IPTR_TYPE(IDBDataSourceAdmin)     ;
DECLARE_IPTR_TYPE(IDBInfo)                ;

//CoType TSession
DECLARE_IPTR_TYPE(IGetDataSource)         ;
DECLARE_IPTR_TYPE(IOpenRowset)            ;
DECLARE_IPTR_TYPE(ISessionProperties)     ;
DECLARE_IPTR_TYPE(IDBCreateCommand)       ;
DECLARE_IPTR_TYPE(IDBSchemaRowset)        ;
DECLARE_IPTR_TYPE(ITableDefinition)       ;
DECLARE_IPTR_TYPE(ITransactionJoin)       ;
DECLARE_IPTR_TYPE(ITransactionLocal)      ;
DECLARE_IPTR_TYPE_NS(,ITransaction)       ;
DECLARE_IPTR_TYPE_NS(,ITransactionObject) ;
DECLARE_IPTR_TYPE_NS(,ITransactionOutcomeEvents);

//CoType TCommand
DECLARE_IPTR_TYPE(IAccessor)              ;
DECLARE_IPTR_TYPE(IColumnsInfo)           ;
DECLARE_IPTR_TYPE(IColumnsInfo2)          ;
DECLARE_IPTR_TYPE(ICommand)               ;
DECLARE_IPTR_TYPE(ICommandProperties)     ;
DECLARE_IPTR_TYPE(ICommandText)           ;
DECLARE_IPTR_TYPE(IConvertType)           ;
DECLARE_IPTR_TYPE(IColumnsRowset)         ;
DECLARE_IPTR_TYPE(ICommandPrepare)        ;
DECLARE_IPTR_TYPE(ICommandWithParameters) ;

//CoType TRowset
DECLARE_IPTR_TYPE(IRowset)                ;
DECLARE_IPTR_TYPE(IRowsetInfo)            ;
DECLARE_IPTR_TYPE(IRowsetLocate)          ;
DECLARE_IPTR_TYPE(IRowsetScroll)          ;
DECLARE_IPTR_TYPE(IRowsetChange)          ;
DECLARE_IPTR_TYPE(IRowsetUpdate)          ;
DECLARE_IPTR_TYPE(IRowsetBookmark)        ;
DECLARE_IPTR_TYPE(IRowsetRefresh)         ;

//Errors
DECLARE_IPTR_TYPE(IErrorRecords)          ;
DECLARE_IPTR_TYPE(IErrorLookup)           ;
DECLARE_IPTR_TYPE(ISQLErrorInfo)          ;

DECLARE_IPTR_TYPE(IMultipleResults)       ;
DECLARE_IPTR_TYPE(IDBAsynchStatus)        ;

////////////////////////////////////////////////////////////////////////////////
//OLEDB Interfaces Names

#define OLEDB_LIB_INAME(OledbInterface)                                  \
 oledb_lib::g_oledb_iname_##OledbInterface

//------------------------------------------------------------------------
#define DECLARE_OLEDB_INAME(OledbInterface)                              \
 extern const wchar_t* const g_oledb_iname_##OledbInterface

DECLARE_OLEDB_INAME(IPersist)               ;
DECLARE_OLEDB_INAME(IPersistFile)           ;

//CoType TDataSource
DECLARE_OLEDB_INAME(IDBInitialize)          ;
DECLARE_OLEDB_INAME(IDBCreateSession)       ;
DECLARE_OLEDB_INAME(IDBProperties)          ;
DECLARE_OLEDB_INAME(IDBDataSourceAdmin)     ;
DECLARE_OLEDB_INAME(IDBInfo)                ;

//CoType TSession
DECLARE_OLEDB_INAME(IGetDataSource)         ;
DECLARE_OLEDB_INAME(IOpenRowset)            ;
DECLARE_OLEDB_INAME(ISessionProperties)     ;
DECLARE_OLEDB_INAME(IDBCreateCommand)       ;
DECLARE_OLEDB_INAME(IDBSchemaRowset)        ;
DECLARE_OLEDB_INAME(ITableDefinition)       ;
DECLARE_OLEDB_INAME(ITransactionJoin)       ;
DECLARE_OLEDB_INAME(ITransactionLocal)      ;
DECLARE_OLEDB_INAME(ITransaction)           ;
DECLARE_OLEDB_INAME(ITransactionObject)     ;

//CoType TCommand
DECLARE_OLEDB_INAME(IAccessor)              ;
DECLARE_OLEDB_INAME(IColumnsInfo)           ;
DECLARE_OLEDB_INAME(IColumnsInfo2)          ;
DECLARE_OLEDB_INAME(ICommand)               ;
DECLARE_OLEDB_INAME(ICommandProperties)     ;
DECLARE_OLEDB_INAME(ICommandText)           ;
DECLARE_OLEDB_INAME(IConvertType)           ;
DECLARE_OLEDB_INAME(IColumnsRowset)         ;
DECLARE_OLEDB_INAME(ICommandPrepare)        ;
DECLARE_OLEDB_INAME(ICommandWithParameters) ;

//CoType TRowset
DECLARE_OLEDB_INAME(IRowset)                ;
DECLARE_OLEDB_INAME(IRowsetInfo)            ;
DECLARE_OLEDB_INAME(IRowsetLocate)          ;
DECLARE_OLEDB_INAME(IRowsetScroll)          ;
DECLARE_OLEDB_INAME(IRowsetChange)          ;
DECLARE_OLEDB_INAME(IRowsetUpdate)          ;
DECLARE_OLEDB_INAME(IRowsetBookmark)        ;
DECLARE_OLEDB_INAME(IRowsetRefresh)         ;

//Errors
DECLARE_OLEDB_INAME(IErrorRecords)          ;
DECLARE_OLEDB_INAME(IErrorLookup)           ;
DECLARE_OLEDB_INAME(ISQLErrorInfo)          ;

#undef DECLARE_OLEDB_INAME

////////////////////////////////////////////////////////////////////////////////
//content

struct TBindingData;
class  TBindingArray;
struct TParamBindingData;
class  TDBID;
class  TDBPropID;
class  TDBPROP;
class  TDBPropertySetBuffer;

////////////////////////////////////////////////////////////////////////////////
//Constants of NULL values

extern const t_oledb_value__DBDATE              __null_dbdate__             ;
extern const t_oledb_value__DBTIME              __null_dbtime__             ;
extern const t_oledb_value__DBTIME2             __null_dbtime2__            ;
extern const t_oledb_value__DBTIMESTAMP         __null_dbtimestamp__        ;
extern const t_oledb_value__DBTIMESTAMPOFFSET   __null_dbtimestampoffset__  ;
extern const t_oledb_value__FILETIME            __null_filetime__           ;
extern const t_oledb_value__I1                  __null_i1__                 ;
extern const t_oledb_value__I2                  __null_i2__                 ;
extern const t_oledb_value__I4                  __null_i4__                 ;
extern const t_oledb_value__UI1                 __null_ui1__                ;
extern const t_oledb_value__UI2                 __null_ui2__                ;
extern const t_oledb_value__UI4                 __null_ui4__                ;
extern const t_oledb_value__R4                  __null_r4__                 ;
extern const t_oledb_value__R8                  __null_r8__                 ;
extern const t_oledb_value__UI8_s               __null_ui8__                ;
extern const t_oledb_value__I8_s                __null_i8__                 ;
extern const t_oledb_value__NUMERIC             __null_dbnumeric__          ;
extern const t_oledb_value__DECIMAL             __null_decimal__            ;
extern const t_oledb_value__CY                  __null_cy__                 ;
extern const VARIANT                            __empty_variant__           ;

extern const char* const                        __null_str__                ;
extern const wchar_t* const                     __null_wstr__               ;

////////////////////////////////////////////////////////////////////////////////
//Zero date for conversions from DBTIME to types with date fields.

extern const t_oledb_value__DBDATE              __zero_dbdate__;

//Sunday    = 0
//Monday    = 1
//Tuesday   = 2
//Wednesday = 3
//Thursday  = 4
//Friday    = 5
//Saturday  = 6
extern const t_oledb_value__I2                  __zero_dbdate_DayOfWeek__;

////////////////////////////////////////////////////////////////////////////////

inline bool oledb_succeeded(HRESULT hr);

inline bool oledb_failed(HRESULT hr);

inline bool oledb_errorsoccurred(HRESULT hr);

inline bool oledb_succeeded_dbrowstatus(DBROWSTATUS x);

inline bool oledb_failed_dbrowstatus(DBROWSTATUS x);

////////////////////////////////////////////////////////////////////////////////
//вспомогательные функции

//возвращает имя кода ощибки DBOLE
t_oledb_string GetDBOleHResult(HRESULT hr);

//Map DBSTATUS To User Name
t_oledb_string GetDBStatusName(DBSTATUS Status);

t_oledb_string GetDBStatusName__short(DBSTATUS Status);

//возвращает имя кода статуса привязки
t_oledb_string GetDBBindStatusName(DBBINDSTATUS Status);

t_oledb_string GetDBBindStatusName__short(DBBINDSTATUS Status);

//просматривает массив кодов привязки и формирует строку состояния ('\n')
t_oledb_string GetDBBindStatusInfo(size_t cBindings,const DBBINDSTATUS rsStatus[]);

//DBPROPSTATUS names
t_oledb_string GetDBPropStatusName(DBPROPSTATUS Status);

//возвращает имя состояния ряда
t_oledb_string GetDBRowStatusName(DBROWSTATUS Status);

t_oledb_string GetDBPendingStatusName(DBPENDINGSTATUS Status);

t_oledb_string GetDBPendingStatusMaskName(DBPENDINGSTATUS Status);

t_oledb_string GetDBColumnFlagName(DBCOLUMNFLAGS Flags,const t_oledb_char* lpszSeparator/*=" "*/);
t_oledb_string GetDBParamFlagName(DBPARAMFLAGS Flags,const t_oledb_char* lpszSeparator/*=" "*/);

//map error code to DBSTATUS
DBSTATUS MapDBErrorToDBStatus(HRESULT  DBError,
                              DBSTATUS DefaultErrStatus=DBSTATUS_E_UNAVAILABLE);

//map error code to DBROWSTATUS
DBROWSTATUS MapDBErrorToDBRowStatus(HRESULT     DBError,
                                    DBROWSTATUS DefaultErrStatus=DBROWSTATUS_E_FAIL);

//get name of transaction isolation level
t_oledb_string GetDBIsolationLevelName(ISOLEVEL IsoLevel);

////////////////////////////////////////////////////////////////////////////////

DBCOUNTITEM CalcApproximatePos(DBCOUNTITEM RowCount,
                               DBCOUNTITEM Numerator,
                               DBCOUNTITEM ulDenominator); //throw

////////////////////////////////////////////////////////////////////////////////
//struct TBindingData (wrapper for DBBINDING)

struct TBindingData:public DBBINDING
{
 private:
  typedef TBindingData                      self_type;

 private:
  void ConstructFromData(const DBBINDING&,bool is_struct); //throw

 public:
  TBindingData();

  TBindingData(const self_type& data); //throw

  TBindingData(const DBBINDING& data); //throw

  TBindingData(DBORDINAL     _iOrdinal,
               DBBYTEOFFSET  _obStatus,
               DBBYTEOFFSET  _obLength,
               DBBYTEOFFSET  _obValue,
               DBPART        _dwPart,
               DBLENGTH      _cbMaxLen,
               DBTYPE        _wType);

 ~TBindingData();

 public:
  self_type& operator = (const self_type& x);

  self_type& operator = (const DBBINDING& x);

 public:
  bool ParamIO__HasInput()const;
  bool ParamIO__HasOutput()const;

 public:
  //true - allocate memory, false - free memory
  void UseObject(bool Use); //throw (bad_alloc)

  void SetObject(DWORD  _dwFlags,
                 REFIID _iid);

 public:
  bool Equal(structure::t_explicit<const self_type&> x)const;

 private:
  TBindingData& Assign(const DBBINDING& x,bool is_struct);

  static bool Can_Use_DBOBJECT(const DBBINDING& x,bool is_struct);

  static DBOBJECT* Alloc_DBOBJECT();//throw bad_alloc
};//struct TBindingData

////////////////////////////////////////////////////////////////////////////////
//class TBindingArray

class TBindingArray:public t_oledb_smart_memory_object
{
 private:
  typedef TBindingArray                                    self_type;

  TBindingArray(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>         self_ptr;
  typedef structure::t_smart_object_ptr<const self_type>   self_cptr;

  typedef structure::t_built_in_array<TBindingData>        bindings_type;

  typedef bindings_type::size_type                         size_type;

  typedef bindings_type::value_type                        value_type;

  typedef bindings_type::iterator                          iterator;
  typedef bindings_type::const_iterator                    const_iterator;

  typedef bindings_type::reference                         reference;
  typedef bindings_type::const_reference                   const_reference;

  typedef bindings_type::pointer                           pointer;
  typedef bindings_type::const_pointer                     const_pointer;

 private:
  enum{c_items_align=sizeof(void*)};

 private:
  TBindingArray(void*            const pNotInitArrayMemory,
                DBCOUNTITEM      const cBindings);

  TBindingArray(void*            const pNotInitArrayMemory,
                HACCESSOR        const hAccessor,
                DBACCESSORFLAGS  const dwAccessorFlags,
                DBCOUNTITEM      const cBindings,
                const DBBINDING        rgBindings[],
                DBLENGTH         const cbRowSize);

  virtual ~TBindingArray();

 public:
  HACCESSOR       m_hAccessor;
  DBACCESSORFLAGS m_dwAccessorFlags;
  DBLENGTH        m_cbRowSize;

 public:
  static self_ptr Create(DBCOUNTITEM      const cBindings);

  static self_ptr Create(HACCESSOR        const hAccessor,
                         DBACCESSORFLAGS  const dwAccessorFlags,
                         DBCOUNTITEM      const cBindings,
                         const DBBINDING        rgBindings[],
                         DBLENGTH         const cbRowSize);

  void GetBindings_(DBACCESSORFLAGS* const pdwAccessorFlags,
                    DBCOUNTITEM*     const pcBindings,
                    DBBINDING**      const prgBindings)const;//throw

  //array interface ------------------------------------------------------
  bool empty()const
   {return m_bindings.empty();}

  size_type size()const
   {return m_bindings.size();}

  reference operator [] (size_type i)
   {return m_bindings[i];}

  const_reference operator [] (size_type i)const
   {return m_bindings[i];}

  reference at(size_type i)
   {return m_bindings[i];}

  const_reference at(size_type i)const
   {return m_bindings[i];}

  iterator begin()
   {return m_bindings.begin();}

  iterator end()
   {return m_bindings.end();}

  const_iterator begin()const
   {return m_bindings.begin();}

  const_iterator end()const
   {return m_bindings.end();}

  pointer data()
   {return m_bindings.data();}

 private:
  typedef TOLEDBMemoryAllocator raw_allocator_type;

  static void* operator new (size_t); //not impl

  static void* operator new (size_t,void* pv);

 public:
  static void operator delete (void* pv);

 #if(COMP_CONF_SUPPORT_OPERATOR_DELETE_EX)
  //memory will be deallocated in catch of self_type::Create
  static void operator delete(void* /*pv*/,void* /*pv2*/){;}
 #endif

 private:
  bindings_type m_bindings;
};//struct TBindingArray

typedef TBindingArray::self_cptr            TBindingArrayPtr;

////////////////////////////////////////////////////////////////////////////////
//class TParamBindingData (wrapper for DBPARAMBINDINFO)

//don't direct use string pointer in DBPARAMBINDINFO !!!
//use SetName/SetType

struct TParamBindingData:public DBPARAMBINDINFO
{
 private:
  typedef TParamBindingData                 self_type;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_str_box        str_box_type;
  typedef structure::t_const_wstr_box       wstr_box_type;

 public:
  using DBPARAMBINDINFO::dwFlags;
  using DBPARAMBINDINFO::bPrecision;
  using DBPARAMBINDINFO::bScale;

 public:
  TParamBindingData();

  TParamBindingData(const self_type& ParamData);

 ~TParamBindingData();

  self_type& operator = (const self_type& ParamData);

  void Swap(TParamBindingData& ParamData);

  //assign new parameter name
  void SetName(const str_box_type& Name);

  void SetName(const wstr_box_type& Name);

 #ifndef OLEDB_LIB_NO_ADODB_TYPES
  void SetAdoType_(AdoDataTypeEnum adType,DBLENGTH Size);

  //wType combined with DBCOLUMNFLAGS_ISFIXEDLENGTH
  void SetType_(DBTYPE wType,DBLENGTH Size);
 #endif

 private:
  class THelper;
};//struct TParamBindingData

////////////////////////////////////////////////////////////////////////////////
//class TDBID

class TBaseDBID:public DBID
{
 protected:
  TBaseDBID(){memset(this,0,sizeof(*this));}
};//class TBaseDBID

// Класс отслеживает только указатель на строку. Не надо использовать указатель
// на GUID, созданный в куче - он может потеряться (и отомстить :))
// (см ConvertToDirectGUID)
class TDBID:public TBaseDBID
{
 private:
  typedef TDBID                                       self_type;

 public://typedefs
  typedef size_t                                      size_type;

  typedef structure::t_const_str_box                  astr_box_type;
  typedef structure::t_const_wstr_box                 wstr_box_type;

  static const size_type npos;//-1

 public://static utilite -------------------------------------------------
  static const DBKIND sm_eKings[];

  //validaty dbid
  static bool CheckDBID(const DBID& dbid);

  //build text description of dbid
  static std::wstring PrintUnicode(const DBID& dbid);
  static std::string  Print(const DBID& dbid);

  //GUID ----------------------------------------
  static bool HasPointedGUID(const DBID& dbid);

  static bool HasGUID(const DBID& dbid);

  static GUID GetGUID(const DBID& dbid);

  static bool IsGUID(const DBID& dbid,REFGUID guid);

  //Name ----------------------------------------
  static bool HasName(const DBID& dbid);

  static size_t GetNameLen(const DBID& dbid);

  static t_oledb_string GetName(const DBID& dbid);
  static std::string    GetAnsiName(const DBID& dbid);
  static std::wstring   GetUnicodeName(const DBID& dbid);

  static const wchar_t* GetUnicodeNamePtr(const DBID& dbid,bool NotNULL);

  //ID ------------------------------------------
  static bool HasID(const DBID& dbid);

  static ULONG GetID(const DBID& dbid);

  static bool IsID(const DBID& dbid,ULONG id);

  //transform pointed data to direct
  static void ConvertToDirectGUID(DBID& dbid);

  //проверка на маскируемость идентификатора dbid ограничением mask_dbid
  //Используется в IColumnsInfo2::GetRestrictedColumnInfo
  static bool IsFiltered(const DBID& dbid,const DBID& mask_dbid);

  static bool IsEqual(const DBID& id1,const DBID& id2);

  static void FillDBID(const DBID& SourceDBID,
                       DBID*       pDBID,
                       OLECHAR*&   BufferPos,
                       OLECHAR*    pBufferEnd);

 private:
  void InitFromDBID(const DBID& dbid); //throw

 public://constructors ----------------------------------------------
  TDBID();
  TDBID(const self_type& dbid);
  TDBID(const DBID&      dbid);

  TDBID(astr_box_type Name);

  TDBID(wstr_box_type  Name);

  TDBID(ULONG PropID);

  TDBID(REFGUID rGuid);

  TDBID(REFGUID rGuid,astr_box_type Name);

  TDBID(REFGUID rGuid,wstr_box_type   Name);

  TDBID(REFGUID rGuid,ULONG PropID);

 ~TDBID();

 public: //SetName --------------------------------------------------
  self_type& SetName(astr_box_type Name);
  self_type& SetName(wstr_box_type Name);

 public: //Set ------------------------------------------------------
  self_type& Set(REFCLSID rguid,const char*    Name,size_type NameLen);
  self_type& Set(REFCLSID rguid,const wchar_t* Name,size_type NameLen);

  self_type& Set(REFCLSID rguid,astr_box_type Name);
  self_type& Set(REFCLSID rguid,wstr_box_type Name);

  self_type& Set(REFGUID rguid,ULONG PropID);
  self_type& Set(REFGUID rguid);
  self_type& Set(ULONG   PropID);

 public: //modificators ---------------------------------------------
  //Removing a pointer guid
  void ConvertToDirectGUID();

 public: //assign operators -----------------------------------------
  self_type& operator = (const self_type& x);

  self_type& operator = (const DBID& x);

  self_type& operator = (astr_box_type Name);

  self_type& operator = (wstr_box_type Name);

 public:
  self_type& swap(self_type& x);

 public: //selectors ------------------------------------------------
  operator const DBID* ()  const   {return this;}

  //build text description of dbid
  std::wstring PrintUnicode()   const   {return self_type::PrintUnicode(*this);}
  std::string  Print()          const   {return self_type::Print(*this);}

  bool    HasPointedGUID()      const   {return HasPointedGUID(*this);}
  bool    HasGUID()             const   {return HasGUID(*this);}
  GUID    GetGUID()             const   {return GetGUID(*this);}
  bool    IsGUID(REFGUID guid)  const   {return IsGUID(*this,guid);}

  bool            HasName()        const   {return HasName(*this);}
  size_t          GetNameLen()     const   {return GetNameLen(*this);}
  t_oledb_string  GetName()        const   {return GetName(*this);}
  std::string     GetAnsiName()    const   {return GetAnsiName(*this);}
  std::wstring    GetUnicodeName() const   {return GetUnicodeName(*this);}

  bool    HasID()          const   {return HasID(*this);}
  ULONG   GetID()          const   {return GetID(*this);}
  bool    IsID(ULONG id)   const   {return IsID(*this,id);}

  bool operator == (const DBID& dbid)const;

  bool operator != (const DBID& dbid)const
   {return !(*this==dbid);}

  void FillDBID(DBID*     pDBID,
                OLECHAR*& BufferPos,
                OLECHAR*  pBufferEnd)const;

 private:
  //resource releasing
  void flush();
};//class TDBID

////////////////////////////////////////////////////////////////////////////////
//class TDBPropID

class TDBPropID
{
 private:
  typedef TDBPropID             self_type;

 public:
  GUID     guid;
  DBPROPID id;

 public:
  TDBPropID();

  TDBPropID(REFGUID _guid,DBPROPID _id);

  bool operator == (const self_type& x)const;

  bool operator != (const self_type& x)const;

  bool operator < (const self_type& x)const;
};//class TDBPropID

////////////////////////////////////////////////////////////////////////////////
//class TBaseDBPROP

class TBaseDBPROP:public DBPROP
{
 private:
  typedef TBaseDBPROP                  self_type;

  TBaseDBPROP(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TBaseDBPROP();

 ~TBaseDBPROP();
};//class TBaseDBPROP

////////////////////////////////////////////////////////////////////////////////
//class TDBPROP

class TDBPROP:public TBaseDBPROP
{
 private:
  typedef TDBPROP                       self_type;

  TDBPROP(const self_type&);
  self_type& operator = (const self_type& prop);

 public:
  TDBPROP();

  //assigment ------------------------------------------------------------
  TDBPROP& operator = (const VARIANT& var); //throw

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  TDBPROP& operator = (VARIANT&& var);
 #endif
};//class TDBPROP

////////////////////////////////////////////////////////////////////////////////
//class TDBPropertySetBuffer

class TDBPropertySetBuffer
{
 private:
  typedef TDBPropertySetBuffer             self_type;

  TDBPropertySetBuffer(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  Default constructor
  /// </summary>
  TDBPropertySetBuffer();

  /// <summary>
  ///  Initialize constructor
  /// </summary>
  //! \param[in] cPropSets
  //! \param[in] pPropSets
  TDBPropertySetBuffer(size_t cPropSets,DBPROPSET* pPropSets);

  /// <summary>
  ///  Destructor
  /// </summary>
 ~TDBPropertySetBuffer();

  //interface ------------------------------------------------------------
  /// <summary>
  ///  Resources releasing
  /// </summary>
  self_type& Clear();

  /// <summary>
  ///  Getting property by ID
  /// </summary>
  //! \param[in] PropID
  //! \param[in] OkOnly
  //!   Property should have OK status
  //! \return
  //!   NULL for unknown PropID or property with status is not OK
  const DBPROP* Get(const TDBPropID& PropID,bool OkOnly)const;

  /// <summary>
  ///  Getting a pointer to PropSets
  /// </summary>
  const DBPROPSET* GetSetBuffer()const;

  /// <summary>
  ///  Getting a count of PropInfoSets
  /// </summary>
  size_t GetSetCount()const;

 private:
  DBPROPSET* m_pPropSets;
  size_t     m_cPropSets;
};//class TDBPropertySetBuffer

////////////////////////////////////////////////////////////////////////////////
//class TDBPropertyInfoSetBuffer

class TDBPropertyInfoSetBuffer
{
 private:
  typedef TDBPropertyInfoSetBuffer                self_type;

  TDBPropertyInfoSetBuffer(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  Default constructor
  /// </summary>
  TDBPropertyInfoSetBuffer();

  /// <summary>
  ///  Initialize constructor
  /// </summary>
  //! \param[in] cPropInfoSets
  //! \param[in] pPropInfoSets
  //! \param[in] pStringBuffer
  TDBPropertyInfoSetBuffer(size_t         cPropInfoSets,
                           DBPROPINFOSET* pPropInfoSets,
                           OLECHAR*       pStringBuffer);

  /// <summary>
  ///  Destructor
  /// </summary>
 ~TDBPropertyInfoSetBuffer();

  /// <summary>
  ///  Resources releasing
  /// </summary>
  self_type& Clear();

  //----------------------------------------------------------------------

  /// <summary>
  ///  Getting a pointer to PropInfoSets
  /// </summary>
  const DBPROPINFOSET* GetSetBuffer()const;

  /// <summary>
  ///  Getting a count of PropInfoSets
  /// </summary>
  size_t GetSetCount()const;

 private:
  DBPROPINFOSET* m_pPropInfoSets;
  size_t         m_cPropInfoSets;
  OLECHAR*       m_pStringBuffer;
};//class TDBPropertyInfoSetBuffer

////////////////////////////////////////////////////////////////////////////////
//class TDBDataBufferUtils

class TDBDataBufferUtils
{
 private:
  typedef TDBDataBufferUtils                              self_type;

 public: //typedefs ------------------------------------------------------

  enum
  {
   free_flag__release_unk =0x0001, //IUnknown::Release
   free_flag__variant     =0x0002, //::VariantClear
   free_flag__bstr        =0x0004, //::SysFreeString - free DBTYPE_BSTR
   free_flag__array       =0x0008, //::DestroySafeArray - free of DBTYPE_ARRAY
   free_flag__vector      =0x0010, //::CoTaskMemFree
   free_flag__byref       =0x0020, //::CoTaskMemFree
   free_flag__release_disp=0x0040, //IDispatch::Release

   free_flag__is_set_data =0x1000, //Ignore bad status (SetData)
   free_flag__is_param    =0x2000, //Ignore bad status for in-parameters
                               //for in-out/out parameters we check status of data

   free_flag__all         =free_flag__release_unk |
                           free_flag__variant     |
                           free_flag__bstr        |
                           free_flag__array       |
                           free_flag__vector      |
                           free_flag__byref       |
                           free_flag__release_disp,

   //освобождение буфера с данными для параметров
   //IUnknown - ВСЕГДА должен освобождать провайдер
   free_flag__param       =(free_flag__all|
                            free_flag__is_param)&~free_flag__release_unk,

   //освобождение буфера с данными для колонок
   //IUnknown - ВСЕГДА освобождает провайдер
   free_flag__set_data    =(free_flag__all|
                            free_flag__is_set_data)&~free_flag__release_unk,

   free_flag__get_data    =free_flag__all,
  };//enum free_flag__xxx

 public:
  enum
  {
   init_flag__value       =0x01, //инициализация данных
   init_flag__length      =0x02, //инициализация длины

   init_flag__all         =init_flag__value|
                           init_flag__length,
  };//enum init_flag__xxx

 public: //---------------------------------------------------------------
  // функция освобождения буферов с данными
  static HRESULT FreeDataEx(DBTYPE      wType,
                            DBLENGTH    cData,
                            void*       rgData,
                            DWORD       Flags);

 public: //---------------------------------------------------------------
  static void Client_FreeData(const DBBINDING& Binding,
                              void*            pData,
                              DWORD            Flags);

  template<class TBindingIterator>
  static void Client_FreeData(TBindingIterator FirstBinding,
                              TBindingIterator LastBinding,
                              void*            pData,
                              DWORD            Flags);

 public: //---------------------------------------------------------------
  static void Provider_FreeClientData(const DBBINDING& Binding,
                                      void*            pData);

  template<class TBindingIterator>
  static void Provider_FreeClientData(TBindingIterator FirstBinding,
                                      TBindingIterator LastBinding,
                                      void*            pData);

 public:
  static HRESULT InitDataEx(const DBBINDING& Binding,
                            void*            pData,
                            DBSTATUS         Status,
                            DWORD            Flags=init_flag__all);

  template<class TBindingIterator>
  static void InitDataEx(TBindingIterator FirstBinding,
                         TBindingIterator LastBinding,
                         void*            pData,
                         DBSTATUS         Status,
                         DWORD            Flags=init_flag__all);
};//class TDBDataBufferUtils

////////////////////////////////////////////////////////////////////////////////
//class TestDBPropSetID

class TestDBPropSetID
{
 public:
  static bool IsSpecialGuid(REFGUID guid);

 private:
  static const GUID* const sm_SpecialGUIDs[];
};//TestDBPropSetID

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib

namespace std{
////////////////////////////////////////////////////////////////////////////////
template<>
inline void swap(oledb_lib::TDBID& x1,oledb_lib::TDBID& x2)
{
 x1.swap(x2);
}//swap
////////////////////////////////////////////////////////////////////////////////
}//namespace std

////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/oledb_common.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
