////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#ifdef OLEDB_LIB_NO_ADODB_TYPES
# include <ole_lib/oledb/oledb_common.h>
#else
# include <ole_lib/oledb/variant/oledb_variant.h>
# include <ole_lib/ole_base.h>
#endif

#include <structure/t_str_formatter.h>
#include <structure/utilities/to_hex2.h>
#include <sstream>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
using namespace ole_lib;
////////////////////////////////////////////////////////////////////////////////
//Constants of NULL values

extern const t_oledb_value__DBDATE      __null_dbdate__          ={};
extern const t_oledb_value__DBTIME      __null_dbtime__          ={};
extern const t_oledb_value__DBTIME2     __null_dbtime2__         ={};
extern const t_oledb_value__DBTIMESTAMP __null_dbtimestamp__     ={};
extern const t_oledb_value__FILETIME    __null_filetime__        ={};
extern const t_oledb_value__I1          __null_i1__              =0;
extern const t_oledb_value__I2          __null_i2__              =0;
extern const t_oledb_value__I4          __null_i4__              =0;
extern const t_oledb_value__UI1         __null_ui1__             =0;
extern const t_oledb_value__UI2         __null_ui2__             =0;
extern const t_oledb_value__UI4         __null_ui4__             =0;
extern const t_oledb_value__R4          __null_r4__              =0;
extern const t_oledb_value__R8          __null_r8__              =0;
extern const t_oledb_value__UI8_s       __null_ui8__             ={};
extern const t_oledb_value__I8_s        __null_i8__              ={};
extern const t_oledb_value__NUMERIC     __null_dbnumeric__       ={};
extern const t_oledb_value__DECIMAL     __null_decimal__         ={};
extern const t_oledb_value__CY          __null_cy__              ={};
extern const VARIANT                    __empty_variant__        ={};

extern const char*     const            __null_str__             ="";
extern const wchar_t*  const            __null_wstr__            =L"";

////////////////////////////////////////////////////////////////////////////////

extern const t_oledb_value__DBDATE      __zero_dbdate__          ={1899,12,30};

extern const t_oledb_value__I2          __zero_dbdate_DayOfWeek__=6; //Saturday

////////////////////////////////////////////////////////////////////////////////

const structure::t_negative_one oledb_none_precision;

const structure::t_negative_one oledb_filetime_precision;

const structure::t_negative_one oledb_none_scale;

////////////////////////////////////////////////////////////////////////////////
//class TOLEDB_СompatibilityTest

#ifndef NDEBUG

static void OLEDB_CompatibilityTest()
{
 assert_s(sizeof(DBTYPE)<=sizeof(AdoDataTypeEnum));
 assert_s(sizeof(t_oledb_value__CY)==sizeof(t_oledb_value__I8_s));

 assert_s(sizeof(t_oledb_value__DBTIME2)==12);

 assert_s(sizeof(t_oledb_value__I4)==sizeof(t_oledb_value__LONG));
 assert_s(sizeof(t_oledb_value__UI4)==sizeof(t_oledb_value__ULONG));
}//OLEDB_CompatibilityTest

STARTUP_CODE__DEBUG(OLEDB_CompatibilityTest)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//OLEDB Interfaces Names

#define OLEDB__MAKE_WTEXT(text)    L##text

#define DEFINE_OLEDB_INAME(ComInterface)                              \
 extern const wchar_t* const g_oledb_iname_##ComInterface=            \
  (sizeof(ComInterface*),OLEDB__MAKE_WTEXT(#ComInterface))

//------------------------------------------------------------------------

DEFINE_OLEDB_INAME(IPersist)               ;
DEFINE_OLEDB_INAME(IPersistFile)           ;

//CoType TDataSource
DEFINE_OLEDB_INAME(IDBInitialize)          ;
DEFINE_OLEDB_INAME(IDBCreateSession)       ;
DEFINE_OLEDB_INAME(IDBProperties)          ;
DEFINE_OLEDB_INAME(IDBDataSourceAdmin)     ;
DEFINE_OLEDB_INAME(IDBInfo)                ;

//CoType TSession
DEFINE_OLEDB_INAME(IGetDataSource)         ;
DEFINE_OLEDB_INAME(IOpenRowset)            ;
DEFINE_OLEDB_INAME(ISessionProperties)     ;
DEFINE_OLEDB_INAME(IDBCreateCommand)       ;
DEFINE_OLEDB_INAME(IDBSchemaRowset)        ;
DEFINE_OLEDB_INAME(ITableDefinition)       ;
DEFINE_OLEDB_INAME(ITransactionJoin)       ;
DEFINE_OLEDB_INAME(ITransactionLocal)      ;
DEFINE_OLEDB_INAME(ITransaction)           ;
DEFINE_OLEDB_INAME(ITransactionObject)     ;

//CoType TCommand
DEFINE_OLEDB_INAME(IAccessor)              ;
DEFINE_OLEDB_INAME(IColumnsInfo)           ;
DEFINE_OLEDB_INAME(IColumnsInfo2)          ;
DEFINE_OLEDB_INAME(ICommand)               ;
DEFINE_OLEDB_INAME(ICommandProperties)     ;
DEFINE_OLEDB_INAME(ICommandText)           ;
DEFINE_OLEDB_INAME(IConvertType)           ;
DEFINE_OLEDB_INAME(IColumnsRowset)         ;
DEFINE_OLEDB_INAME(ICommandPrepare)        ;
DEFINE_OLEDB_INAME(ICommandWithParameters) ;

//CoType TRowset
DEFINE_OLEDB_INAME(IRowset)                ;
DEFINE_OLEDB_INAME(IRowsetInfo)            ;
DEFINE_OLEDB_INAME(IRowsetLocate)          ;
DEFINE_OLEDB_INAME(IRowsetScroll)          ;
DEFINE_OLEDB_INAME(IRowsetChange)          ;
DEFINE_OLEDB_INAME(IRowsetUpdate)          ;
DEFINE_OLEDB_INAME(IRowsetBookmark)        ;
DEFINE_OLEDB_INAME(IRowsetRefresh)         ;

//Errors
DEFINE_OLEDB_INAME(IErrorRecords)          ;
DEFINE_OLEDB_INAME(IErrorLookup)           ;
DEFINE_OLEDB_INAME(ISQLErrorInfo)          ;

#undef DEFINE_OLEDB_INAME
#undef OLEDB__MAKE_WTEXT

////////////////////////////////////////////////////////////////////////////////
//structure for define constant name

template<typename T>
struct TDBConstNameInfo
{
 typedef T const_type;

 const_type            Const;
 const t_oledb_char*   Name;
 const t_oledb_char*   ShortName;

 bool operator == (const_type const x) const
  {return Const==x;}

 bool operator != (const_type const x) const
  {return !(*this==x);}
};//struct TDBConstNameInfo

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//define DBSTATUS names

#define DEF_DBSTATUS_NAME(DBConst)                      \
 {                                                      \
  DBSTATUS_##DBConst,                                   \
  _OLEDB_LIB_T("DBSTATUS_") _OLEDB_LIB_T(#DBConst),     \
  _OLEDB_LIB_T(#DBConst)                                \
  },

static const TDBConstNameInfo<DBSTATUS> g_DBStatusInfo[]=
{
 DEF_DBSTATUS_NAME(S_OK                 )
 DEF_DBSTATUS_NAME(E_BADACCESSOR        )
 DEF_DBSTATUS_NAME(E_CANTCONVERTVALUE   )
 DEF_DBSTATUS_NAME(S_ISNULL             )
 DEF_DBSTATUS_NAME(S_TRUNCATED          )
 DEF_DBSTATUS_NAME(E_SIGNMISMATCH       )
 DEF_DBSTATUS_NAME(E_DATAOVERFLOW       )
 DEF_DBSTATUS_NAME(E_CANTCREATE         )
 DEF_DBSTATUS_NAME(E_UNAVAILABLE        )
 DEF_DBSTATUS_NAME(E_PERMISSIONDENIED   )
 DEF_DBSTATUS_NAME(E_INTEGRITYVIOLATION )
 DEF_DBSTATUS_NAME(E_SCHEMAVIOLATION    )
 DEF_DBSTATUS_NAME(E_BADSTATUS          )
 DEF_DBSTATUS_NAME(S_DEFAULT            )
 DEF_DBSTATUS_NAME(S_IGNORE             )
 DEF_DBSTATUS_NAME(E_DOESNOTEXIST       )
 DEF_DBSTATUS_NAME(E_INVALIDURL         )
 DEF_DBSTATUS_NAME(E_RESOURCELOCKED     )
 DEF_DBSTATUS_NAME(E_RESOURCEEXISTS     )
 DEF_DBSTATUS_NAME(E_CANNOTCOMPLETE     )
 DEF_DBSTATUS_NAME(E_VOLUMENOTFOUND     )
 DEF_DBSTATUS_NAME(E_OUTOFSPACE         )
 DEF_DBSTATUS_NAME(S_CANNOTDELETESOURCE )
 DEF_DBSTATUS_NAME(E_READONLY           )
 DEF_DBSTATUS_NAME(E_RESOURCEOUTOFSCOPE )
 DEF_DBSTATUS_NAME(S_ALREADYEXISTS      )
 DEF_DBSTATUS_NAME(E_CANCELED           )
 DEF_DBSTATUS_NAME(E_NOTCOLLECTION      )
};//g_DBStatusInfo

#undef DEF_DBSTATUS_NAME

////////////////////////////////////////////////////////////////////////////////
//define DBBINDSTATUS names

#define DEF_DBBINDSTATUS_NAME(DBConst)                  \
 {                                                      \
  DBBINDSTATUS_##DBConst,                               \
  _OLEDB_LIB_T("DBBINDSTATUS_") _OLEDB_LIB_T(#DBConst), \
  _OLEDB_LIB_T(#DBConst)                                \
  },

static const TDBConstNameInfo<DBBINDSTATUS> g_DBBindStatusInfo[]=
{
 DEF_DBBINDSTATUS_NAME(OK)
 DEF_DBBINDSTATUS_NAME(BADORDINAL)
 DEF_DBBINDSTATUS_NAME(UNSUPPORTEDCONVERSION)
 DEF_DBBINDSTATUS_NAME(BADBINDINFO)
 DEF_DBBINDSTATUS_NAME(BADSTORAGEFLAGS)
 DEF_DBBINDSTATUS_NAME(NOINTERFACE)
};//g_DBBindStatusInfo

#undef DEF_DBBINDSTATUS_NAME

////////////////////////////////////////////////////////////////////////////////
//define DBPROPSTATUS names

#define DEF_DBPROPSTATUS_NAME(DBConst)                  \
 {                                                      \
  DBPROPSTATUS_##DBConst,                               \
  _OLEDB_LIB_T("DBPROPSTATUS_") _OLEDB_LIB_T(#DBConst), \
  _OLEDB_LIB_T(#DBConst)                                \
  },

static const TDBConstNameInfo<DBPROPSTATUS> g_DBPropStatusInfo[]=
{
 DEF_DBPROPSTATUS_NAME(OK              )
 DEF_DBPROPSTATUS_NAME(NOTSUPPORTED    )
 DEF_DBPROPSTATUS_NAME(BADVALUE        )
 DEF_DBPROPSTATUS_NAME(BADOPTION       )
 DEF_DBPROPSTATUS_NAME(BADCOLUMN       )
 DEF_DBPROPSTATUS_NAME(NOTALLSETTABLE  )
 DEF_DBPROPSTATUS_NAME(NOTSETTABLE     )
 DEF_DBPROPSTATUS_NAME(NOTSET          )
 DEF_DBPROPSTATUS_NAME(CONFLICTING     )
 DEF_DBPROPSTATUS_NAME(NOTAVAILABLE    )
};//g_DBPropStatusInfo

#undef DEF_DBPROPSTATUS_NAME

////////////////////////////////////////////////////////////////////////////////
//define DBROWSTATUS names

#define DEF_DBROWSTATUS_NAME(DBConst)                  \
 {                                                     \
  DBROWSTATUS_##DBConst,                               \
  _OLEDB_LIB_T("DBROWSTATUS_") _OLEDB_LIB_T(#DBConst), \
  _OLEDB_LIB_T(#DBConst)                               \
  },

static const TDBConstNameInfo<DBROWSTATUS> g_DBRowStatusInfo[]=
{
 DEF_DBROWSTATUS_NAME(S_OK)
 DEF_DBROWSTATUS_NAME(S_MULTIPLECHANGES)
 DEF_DBROWSTATUS_NAME(S_PENDINGCHANGES)
// DEF_DBROWSTATUS_NAME(S_ROWSETCOLUMN)
 DEF_DBROWSTATUS_NAME(S_NOCHANGE)
 DEF_DBROWSTATUS_NAME(E_CANCELED)
 DEF_DBROWSTATUS_NAME(E_CANTRELEASE)
 DEF_DBROWSTATUS_NAME(E_CONCURRENCYVIOLATION)
 DEF_DBROWSTATUS_NAME(E_DELETED)
 DEF_DBROWSTATUS_NAME(E_PENDINGINSERT)
 DEF_DBROWSTATUS_NAME(E_NEWLYINSERTED)
 DEF_DBROWSTATUS_NAME(E_INTEGRITYVIOLATION)
 DEF_DBROWSTATUS_NAME(E_INVALID)
 DEF_DBROWSTATUS_NAME(E_MAXPENDCHANGESEXCEEDED)
 DEF_DBROWSTATUS_NAME(E_OBJECTOPEN)
 DEF_DBROWSTATUS_NAME(E_OUTOFMEMORY)
 DEF_DBROWSTATUS_NAME(E_PERMISSIONDENIED)
 DEF_DBROWSTATUS_NAME(E_LIMITREACHED)
 DEF_DBROWSTATUS_NAME(E_SCHEMAVIOLATION)
 DEF_DBROWSTATUS_NAME(E_FAIL)
};//g_DBRowStatusInfo

#undef DEF_DBROWSTATUS_NAME

////////////////////////////////////////////////////////////////////////////////
//define DBPENDINGSTATUS names

#define DEF_DBPENDINGSTATUS_NAME(DBConst)                  \
 {                                                         \
  DBPENDINGSTATUS_##DBConst,                               \
  _OLEDB_LIB_T("DBPENDINGSTATUS_") _OLEDB_LIB_T(#DBConst), \
  _OLEDB_LIB_T(#DBConst)                                   \
  },

static const TDBConstNameInfo<DBPENDINGSTATUS> g_DBPendingStatusInfo[]=
{
 DEF_DBPENDINGSTATUS_NAME(NEW)
 DEF_DBPENDINGSTATUS_NAME(CHANGED)
 DEF_DBPENDINGSTATUS_NAME(DELETED)
 DEF_DBPENDINGSTATUS_NAME(UNCHANGED)
 DEF_DBPENDINGSTATUS_NAME(INVALIDROW)
};//g_DBPendingStatusInfo

#undef DEF_DBPENDINGSTATUS_NAME

////////////////////////////////////////////////////////////////////////////////
//отображение кода ошибки на DBSTATUS

DBSTATUS MapDBErrorToDBStatus(HRESULT  const DBError,
                              DBSTATUS const DefaultErrStatus)
{
 if(SUCCEEDED(DBError))
  return DBSTATUS_S_OK;

 switch(DBError)
 {
  case DB_E_UNSUPPORTEDCONVERSION  :
  case DB_E_CANTCONVERTVALUE       :  return DBSTATUS_E_CANTCONVERTVALUE;

  case DB_E_BADSTATUSVALUE         :  return DBSTATUS_E_BADSTATUS;

  case DB_E_BADBINDINFO            :  return DBSTATUS_E_BADACCESSOR;

  case DB_E_DATAOVERFLOW           :
  case DISP_E_OVERFLOW             :  return DBSTATUS_E_DATAOVERFLOW;

  case E_NOINTERFACE               :
  case E_OUTOFMEMORY               :  return DBSTATUS_E_CANTCREATE;

  case DB_E_CANCELED               :  return DBSTATUS_E_CANCELED;
 }//switch

 return DefaultErrStatus;
}//MapDBErrorToDBStatus

////////////////////////////////////////////////////////////////////////////////

DBROWSTATUS MapDBErrorToDBRowStatus(HRESULT     const DBError,
                                    DBROWSTATUS const DefaultErrStatus)
{
 if(SUCCEEDED(DBError))
  return DBROWSTATUS_S_OK;

 switch(DBError)
 {
  case DB_E_CANCELED:
   return DBROWSTATUS_E_CANCELED;

  //DBROWSTATUS_E_CANTRELEASE

  case DB_E_DELETEDROW:
   return DBROWSTATUS_E_DELETED;

  case DB_E_NEWLYINSERTED:
   return DBROWSTATUS_E_NEWLYINSERTED;

  case DB_E_PENDINGINSERT:
   return DBROWSTATUS_E_PENDINGINSERT;

  case DB_E_CONCURRENCYVIOLATION:
   return DBROWSTATUS_E_CONCURRENCYVIOLATION;

  case DB_E_INTEGRITYVIOLATION:
   return DBROWSTATUS_E_INTEGRITYVIOLATION;

  case DB_E_BADBOOKMARK:
  case DB_E_INVALID:
   return DBROWSTATUS_E_INVALID;

  case DB_E_MAXPENDCHANGESEXCEEDED:
   return DBROWSTATUS_E_MAXPENDCHANGESEXCEEDED;

  case DB_E_OBJECTOPEN:
   return DBROWSTATUS_E_OBJECTOPEN;

  case E_OUTOFMEMORY:
   return DBROWSTATUS_E_OUTOFMEMORY;

  //DBROWSTATUS_E_PERMISSIONDENIED
  //DBROWSTATUS_E_LIMITREACHED

  case DB_E_SCHEMAVIOLATION:
   return DBROWSTATUS_E_SCHEMAVIOLATION;

  case E_FAIL:
   return DBROWSTATUS_E_FAIL;
 }//switch

 return DefaultErrStatus;
}//MapDBErrorToDBRowStatus

////////////////////////////////////////////////////////////////////////////////
//Helper function for work with TOLEDBMemoryAllocator

static wchar_t* OLEDBMemoryAllocator_AllocWStr(structure::t_const_wstr_box const s)
{
 CHECK_READ_TYPED_PTR(s.ptr,s.len);

 if(s.len==0)
  return nullptr;

 typedef __STLS_ALLOCATOR_REBIND(TOLEDBMemoryAllocator,wchar_t) alloc_type;

 if(!(s.len<alloc_type::instance.max_size()))
  throw std::bad_alloc();

 wchar_t* const ptr=alloc_type::instance.allocate(alloc_type::size_type(s.len)+1); //throw

 assert(ptr!=nullptr);

 CHECK_WRITE_PTR(ptr,alloc_type::size_type(s.len)+1);

 {
  const wchar_t*       ptr_s =s.ptr;
  const wchar_t* const ptr_se=s.ptr+s.len;

  wchar_t* ptr_d=ptr;

  for(;ptr_s!=ptr_se;++ptr_s,++ptr_d)
   (*ptr_d)=(*ptr_s);

  (*ptr_d)=0;
 }//local

 return ptr;
}//OLEDBMemoryAllocator_AllocWStr - unicode version

//------------------------------------------------------------------------
static wchar_t* OLEDBMemoryAllocator_AllocWStr(structure::t_const_str_box const s)
{
 CHECK_READ_TYPED_PTR(s.ptr,s.len);

 if(s.len==0)
  return nullptr;

 //----
 std::wstring ws;

 structure::ansi_to_unicode(&ws,s.ptr,s.len);

 return OLEDBMemoryAllocator_AllocWStr(ws);
}//OLEDBMemoryAllocator_AllocWStr - ansi version

//------------------------------------------------------------------------
static void OLEDBMemoryAllocator_FreeWStrAndSetNull(wchar_t*& rstr)
{
 wchar_t* const ptr=rstr;

 rstr=nullptr;

 typedef __STLS_ALLOCATOR_REBIND(TOLEDBMemoryAllocator,wchar_t) alloc_type;

 alloc_type::instance.deallocate(ptr,0);
}//OLEDBMemoryAllocator_FreeWStrAndSetNull

////////////////////////////////////////////////////////////////////////////////

t_oledb_string GetDBOleHResult(HRESULT hr)
{
 t_oledb_string s;

 return structure::tstr_to_tstr(&s,ole_lib::TestHResult(hr));
}//GetDBOleHResult

////////////////////////////////////////////////////////////////////////////////

template<typename T>
static t_oledb_string
 FindDBConstName(const TDBConstNameInfo<T>* const pBeg,
                 const TDBConstNameInfo<T>* const pEnd,
                 T                          const Const,
                 const t_oledb_char*        const fmsg_unk_const)
{
 const TDBConstNameInfo<T>* const i=std::find(pBeg,pEnd,Const);

 if(i!=pEnd)
  return i->Name;

 structure::t_basic_str_formatter<t_oledb_char>
  fresult(fmsg_unk_const);

 fresult<<Const;

 return fresult.str();
}//FindDBConstName

//------------------------------------------------------------------------
template<typename T>
static t_oledb_string
 FindDBConstName__short(const TDBConstNameInfo<T>* const pBeg,
                        const TDBConstNameInfo<T>* const pEnd,
                        T                          const Const,
                        const t_oledb_char*        const fmsg_unk_const)
{
 const TDBConstNameInfo<T>* const i=std::find(pBeg,pEnd,Const);

 if(i!=pEnd)
  return i->ShortName;

 structure::t_basic_str_formatter<t_oledb_char>
  fresult(fmsg_unk_const);

 fresult<<Const;

 return fresult.str();
}//FindDBConstName__short

////////////////////////////////////////////////////////////////////////////////

template<typename T>
static t_oledb_string
 BuildDBConstMaskName(const TDBConstNameInfo<T>*       pBeg,
                      const TDBConstNameInfo<T>* const pEnd,
                      T                                Const,
                      const t_oledb_char*              lpszSeparator)
{
 t_oledb_string t;

 if(lpszSeparator==NULL)
  lpszSeparator=_OLEDB_LIB_T(" ");

 for(;pBeg!=pEnd;++pBeg)
 {
  if(!(pBeg->Const&Const))
   continue;

  Const&=~pBeg->Const;

  if(!t.empty())
   t+=lpszSeparator;

  t+=pBeg->ShortName;
 }//for pInfo

 if(Const)
 {
  if(!t.empty())
   t+=lpszSeparator;

  t+=_OLEDB_LIB_T("0x");

  t+=structure::to_hex2::upper<t_oledb_char>(Const).c_str();
 }//if

 return t;
}//BuildDBConstMaskName

////////////////////////////////////////////////////////////////////////////////

t_oledb_string GetDBStatusName(DBBINDSTATUS const Status)
{
 return FindDBConstName
         (g_DBStatusInfo,
          _END_(g_DBStatusInfo),
          Status,
          _OLEDB_LIB_T("Unknown DBStatus [%1]"));
}//GetDBStatusName

//------------------------------------------------------------------------
t_oledb_string GetDBStatusName__short(DBBINDSTATUS const Status)
{
 return FindDBConstName__short
         (g_DBStatusInfo,
          _END_(g_DBStatusInfo),
          Status,
          _OLEDB_LIB_T("Unknown DBStatus [%1]"));
}//GetDBStatusName__short

////////////////////////////////////////////////////////////////////////////////

t_oledb_string GetDBBindStatusName(DBBINDSTATUS const Status)
{
 return FindDBConstName
         (g_DBBindStatusInfo,
          _END_(g_DBBindStatusInfo),
          Status,
          _OLEDB_LIB_T("Unknown DBBindStatus [%1]"));
}//GetDBBindStatusName

//------------------------------------------------------------------------
t_oledb_string GetDBBindStatusName__short(DBBINDSTATUS const Status)
{
 return FindDBConstName__short
         (g_DBBindStatusInfo,
          _END_(g_DBBindStatusInfo),
          Status,
          _OLEDB_LIB_T("Unknown DBBindStatus [%1]"));
}//GetDBBindStatusName__short

////////////////////////////////////////////////////////////////////////////////

t_oledb_string GetDBBindStatusInfo(size_t cBindings,const DBBINDSTATUS rgStatus[])
{
 assert(cBindings==0 || rgStatus!=NULL);

 t_oledb_string text;
 t_oledb_char   tmpStr[40];

 for(const DBBINDSTATUS* i=rgStatus;i!=rgStatus+cBindings;++i)
 {
  if(*i!=DBBINDSTATUS_OK)
  {
   if(!text.empty())
    text+=_OLEDB_LIB_T("\n");

   _VERIFY_EQ(_OLEDB_LIB_itot_s(LONG(i-rgStatus),tmpStr,_DIM_(tmpStr),10),0L);

   text+=tmpStr;
   text+=_OLEDB_LIB_T(": ");
   text+=GetDBBindStatusName(*i);
  }
 }//for

 return text;
}//GetDBBindStatusInfo

////////////////////////////////////////////////////////////////////////////////

t_oledb_string GetDBPropStatusName(DBPROPSTATUS Status)
{
 return FindDBConstName
         (g_DBPropStatusInfo,
          _END_(g_DBPropStatusInfo),
          Status,
          _OLEDB_LIB_T("Unknown Property Status [%1]"));
}//GetDBPropStatusName

////////////////////////////////////////////////////////////////////////////////

t_oledb_string GetDBRowStatusName(DBBINDSTATUS Status)
{
 return FindDBConstName
         (g_DBRowStatusInfo,
         _END_(g_DBRowStatusInfo),
         Status,
         _OLEDB_LIB_T("Unknown Row Status [%1]"));
}//GetDBRowStatusName

////////////////////////////////////////////////////////////////////////////////

t_oledb_string GetDBPendingStatusName(DBPENDINGSTATUS Status)
{
 return FindDBConstName
         (g_DBPendingStatusInfo,
          _END_(g_DBPendingStatusInfo),
          Status,
          _OLEDB_LIB_T("Unknown Pending Status [%1]"));
}//GetDBPendingStatusName

////////////////////////////////////////////////////////////////////////////////

t_oledb_string GetDBPendingStatusMaskName(DBPENDINGSTATUS Status)
{
 return BuildDBConstMaskName
         (g_DBPendingStatusInfo,
          _END_(g_DBPendingStatusInfo),
          Status,
          _OLEDB_LIB_T("|"));
}//GetDBPendingStatusMaskName

////////////////////////////////////////////////////////////////////////////////

#define DEF_DBCOLUMNFLAG_NAME(DBConst)                  \
 {                                                      \
  DBCOLUMNFLAGS_##DBConst,                              \
  _OLEDB_LIB_T("DBCOLUMNFLAGS_") _OLEDB_LIB_T(#DBConst),\
  _OLEDB_LIB_T(#DBConst)                                \
  },

const TDBConstNameInfo<DBCOLUMNDESCFLAGS> g_DBColumnFlagInfo[]=
{
 DEF_DBCOLUMNFLAG_NAME(CACHEDEFERRED)
 DEF_DBCOLUMNFLAG_NAME(ISBOOKMARK)
 DEF_DBCOLUMNFLAG_NAME(ISFIXEDLENGTH)
 DEF_DBCOLUMNFLAG_NAME(ISLONG)
 DEF_DBCOLUMNFLAG_NAME(ISNULLABLE)
 DEF_DBCOLUMNFLAG_NAME(ISROWID)
 DEF_DBCOLUMNFLAG_NAME(ISROWVER)
 DEF_DBCOLUMNFLAG_NAME(MAYBENULL)
 DEF_DBCOLUMNFLAG_NAME(MAYDEFER)
 DEF_DBCOLUMNFLAG_NAME(WRITE)
 DEF_DBCOLUMNFLAG_NAME(WRITEUNKNOWN)
};//g_DBColumnFlagInfo

#undef DEF_DBCOLUMNFLAG_NAME

t_oledb_string GetDBColumnFlagName(DBCOLUMNFLAGS Flags,const t_oledb_char* lpszSeparator)
{
 return BuildDBConstMaskName
         (g_DBColumnFlagInfo,
          _END_(g_DBColumnFlagInfo),
          Flags,
          lpszSeparator);
}//GetDBColumnFlagName

////////////////////////////////////////////////////////////////////////////////

#define DEF_DBPARAMFLAG_NAME(DBConst)                   \
 {                                                      \
  DBPARAMFLAGS_##DBConst,                               \
  _OLEDB_LIB_T("DBPARAMFLAGS_") _OLEDB_LIB_T(#DBConst), \
  _OLEDB_LIB_T(#DBConst)                                \
  },

const TDBConstNameInfo<DBPARAMFLAGS> g_DBParamFlagInfo[]=
{
 DEF_DBPARAMFLAG_NAME(ISLONG)
 DEF_DBPARAMFLAG_NAME(ISINPUT)
 DEF_DBPARAMFLAG_NAME(ISOUTPUT)
 DEF_DBPARAMFLAG_NAME(ISNULLABLE)
 DEF_DBPARAMFLAG_NAME(ISSIGNED)
};//g_DBParamFlagInfo

#undef DEF_DBPARAMFLAG_NAME

t_oledb_string GetDBParamFlagName(DBPARAMFLAGS Flags,const t_oledb_char* lpszSeparator)
{
 return BuildDBConstMaskName
         (g_DBParamFlagInfo,
          _END_(g_DBParamFlagInfo),
          Flags,
          lpszSeparator);
}//GetDBParamFlagName

////////////////////////////////////////////////////////////////////////////////
//получение имени изоляции транзакции

#define DEF_ISOLATIONLEVEL_NAME(DBConst)                  \
 {                                                        \
  ISOLATIONLEVEL_##DBConst,                               \
  _OLEDB_LIB_T("ISOLATIONLEVEL_") _OLEDB_LIB_T(#DBConst), \
  _OLEDB_LIB_T(#DBConst)                                  \
 },

const TDBConstNameInfo<ISOLEVEL> g_DBIsoLevelInfo[]=
{
 DEF_ISOLATIONLEVEL_NAME(UNSPECIFIED)
 DEF_ISOLATIONLEVEL_NAME(CHAOS)
 DEF_ISOLATIONLEVEL_NAME(READUNCOMMITTED)
 DEF_ISOLATIONLEVEL_NAME(READCOMMITTED)
 DEF_ISOLATIONLEVEL_NAME(REPEATABLEREAD)
 DEF_ISOLATIONLEVEL_NAME(SERIALIZABLE)
};//g_DBIsoLevelInfo

#undef DEF_ISOLATIONLEVEL_NAME

t_oledb_string GetDBIsolationLevelName(ISOLEVEL IsoLevel)
{
 return FindDBConstName__short
         (g_DBIsoLevelInfo,
          _END_(g_DBIsoLevelInfo),
          IsoLevel,
          _OLEDB_LIB_T("Unknown ISOLEVEL (%1)"));
}//GetDBIsolationLevelName

////////////////////////////////////////////////////////////////////////////////

DBCOUNTITEM CalcApproximatePos(DBCOUNTITEM RowCount,
                               DBCOUNTITEM Numerator,
                               DBCOUNTITEM Denominator)
{
 if(Denominator==0)
  return structure::t_numeric_limits<DBCOUNTITEM>::max_value();

 if(Denominator<Numerator)
  return structure::t_numeric_limits<DBCOUNTITEM>::max_value();

 //TODO: Контроль переполнения

#ifdef _WIN64
 return ((RowCount*Numerator)/Denominator);
#else
 return static_cast<DBROWOFFSET>
        (UInt32x32To64(RowCount,Numerator)/static_cast<unsigned __int64>(Denominator));
#endif
}//CalcApproximatePos

////////////////////////////////////////////////////////////////////////////////
//struct TBindingData

void TBindingData::ConstructFromData(const DBBINDING& x,
                                     bool       const is_struct)
{
 this->iOrdinal     =x.iOrdinal    ;
 this->obValue      =x.obValue     ;
 this->obLength     =x.obLength    ;
 this->obStatus     =x.obStatus    ;
 this->pTypeInfo    =NULL          ;
 this->pObject      =NULL          ;
 this->pBindExt     =NULL          ;
 this->dwPart       =x.dwPart      ;
 this->dwMemOwner   =x.dwMemOwner  ;
 this->eParamIO     =x.eParamIO    ;
 this->cbMaxLen     =x.cbMaxLen    ;
 this->dwFlags      =x.dwFlags     ;
 this->wType        =x.wType       ;
 this->bPrecision   =x.bPrecision  ;
 this->bScale       =x.bScale      ;

 if(Can_Use_DBOBJECT(x,is_struct))
 {
  this->pObject=this->Alloc_DBOBJECT();//throw

  (*(this->pObject))=(*(x.pObject));
 }

 ole_lib::CopyComInterface2(x.pTypeInfo,this->pTypeInfo);
}//ConstructFromData

//------------------------------------------------------------------------
TBindingData::TBindingData(DBORDINAL    const _iOrdinal,
                           DBBYTEOFFSET const _obStatus,
                           DBBYTEOFFSET const _obLength,
                           DBBYTEOFFSET const _obValue,
                           DBPART       const _dwPart,
                           DBLENGTH     const _cbMaxLen,
                           DBTYPE       const _wType)
{
 memset(this,0,sizeof(*this));

 this->iOrdinal = _iOrdinal;
 this->obStatus = _obStatus;
 this->obLength = _obLength;
 this->obValue  = _obValue;
 this->dwPart   = _dwPart;
 this->cbMaxLen = _cbMaxLen;
 this->wType    = _wType;
}

//------------------------------------------------------------------------
TBindingData::~TBindingData()
{
 ole_lib::OLE_CoTaskMemFreeAndSetNULL(this->pObject);

 assert(this->pObject==NULL);

 ole_lib::ReleaseComInterface(this->pTypeInfo);

 assert(this->pTypeInfo==NULL);
}//~TBindingData

//------------------------------------------------------------------------
TBindingData& TBindingData::Assign(const DBBINDING& x,
                                   bool       const is_struct)
{
 //------------------
 const bool use_dbobject=this->Can_Use_DBOBJECT(x,is_struct);

 CO_MEM_POINTER3(DBOBJECT) _spObject(use_dbobject?this->Alloc_DBOBJECT():NULL);//throw

 if(use_dbobject)
 {
  assert(x.pObject!=NULL);
  assert(_spObject!=NULL);

  (*_spObject)=(*(x.pObject));
 }//if

 //------------------
 ole_lib::ITypeInfoPtr _spTypeInfo(x.pTypeInfo);

 //------------------
 this->iOrdinal     =x.iOrdinal    ;
 this->obValue      =x.obValue     ;
 this->obLength     =x.obLength    ;
 this->obStatus     =x.obStatus    ;

 _spTypeInfo.swap(this->pTypeInfo);
 _spObject.swap(this->pObject);

 this->pBindExt     =NULL          ;
 this->dwPart       =x.dwPart      ;
 this->dwMemOwner   =x.dwMemOwner  ;
 this->eParamIO     =x.eParamIO    ;
 this->cbMaxLen     =x.cbMaxLen    ;
 this->dwFlags      =x.dwFlags     ;
 this->wType        =x.wType       ;
 this->bPrecision   =x.bPrecision  ;
 this->bScale       =x.bScale      ;

 return *this;
}//Assign

//------------------------------------------------------------------------
void TBindingData::UseObject(const bool Use)//throw
{
 if(Use)
 {
  if(this->pObject==NULL)
   this->pObject=this->Alloc_DBOBJECT();//throw

  assert(this->pObject!=NULL);

  return;
 }//if Use

 assert(!Use);

 ole_lib::OLE_CoTaskMemFreeAndSetNULL(this->pObject);

 assert(this->pObject==NULL);
}//UseObject

//------------------------------------------------------------------------
void TBindingData::SetObject(DWORD  const _dwFlags,
                             REFIID       _iid)
{
 if(this->pObject==NULL)
  this->pObject=this->Alloc_DBOBJECT();//throw

 assert(this->pObject!=NULL);

 this->pObject->dwFlags=_dwFlags;
 this->pObject->iid    =_iid;
}//SetObject

//------------------------------------------------------------------------
bool TBindingData::Equal(structure::t_explicit<const self_type&> x)const
{
 if(this->iOrdinal!=x.value.iOrdinal)
  return false;

 if(this->obStatus!=x.value.obStatus)
  return false;

 if(this->obLength!=x.value.obLength)
  return false;

 if(this->obValue!=x.value.obValue)
  return false;

 if(this->eParamIO!=x.value.eParamIO)
  return false;

 if(this->dwPart!=x.value.dwPart)
  return false;

 if(this->wType!=x.value.wType)
  return false;

 if(this->cbMaxLen!=x.value.cbMaxLen)
  return false;

 if(this->dwFlags!=x.value.dwFlags)
  return false;

 if(this->dwMemOwner!=x.value.dwMemOwner)
  return false;

 if(this->bPrecision!=x.value.bPrecision)
  return false;

 if(this->bScale!=x.value.bScale)
  return false;

 if((this->pObject==NULL)!=(x.value.pObject==NULL))
  return false;

 if(this->pObject!=NULL)
 {
  assert(x.value.pObject!=NULL);

  if(this->pObject->iid!=x.value.pObject->iid)
   return false;

  if(this->pObject->dwFlags!=x.value.pObject->dwFlags)
   return false;
 }//if

 return true;
}//Equal

//------------------------------------------------------------------------
bool TBindingData::Can_Use_DBOBJECT(const DBBINDING& x,
                                    bool       const is_struct)
{
 if(x.pObject==NULL)
  return false;

 if(is_struct)
 {
  if(!(x.dwPart&DBPART_VALUE))
   return false;

  if(OLEDB_EXTRACT_SIMPLE_DBTYPE(x.wType)!=DBTYPE_IUNKNOWN)
   return false;
 }//if

 CHECK_READ_TYPED_PTR(x.pObject,1)

 return true;
}//Can_Use_DBOBJECT

//------------------------------------------------------------------------
DBOBJECT* TBindingData::Alloc_DBOBJECT()//throw bad_alloc
{
 return reinterpret_cast<DBOBJECT*>(OLE_CoTaskMemAlloc(sizeof(DBOBJECT))); //throw
}//Alloc_DBOBJECT

////////////////////////////////////////////////////////////////////////////////
//class TBindingArray

TBindingArray::TBindingArray(void*           const pNotInitArrayMemory,
                             DBCOUNTITEM     const cBindings)
 :m_bindings(reinterpret_cast<value_type*>(pNotInitArrayMemory),
             reinterpret_cast<value_type*>(pNotInitArrayMemory)+cBindings)
 ,m_hAccessor       (DBACCESSOR_INVALID)
 ,m_dwAccessorFlags (0)
 ,m_cbRowSize       (0)
{
 assert(m_bindings.size()==cBindings);
}

//------------------------------------------------------------------------
TBindingArray::TBindingArray(void*           const pNotInitArrayMemory,
                             HACCESSOR       const hAccessor,
                             DBACCESSORFLAGS const dwAccessorFlags,
                             DBCOUNTITEM     const cBindings,
                             const DBBINDING       rgBindings[],
                             DBLENGTH        const cbRowSize)
 :m_bindings(reinterpret_cast<value_type*>(pNotInitArrayMemory),
             reinterpret_cast<value_type*>(pNotInitArrayMemory)+cBindings,
             rgBindings,
             rgBindings+cBindings)
 ,m_hAccessor(hAccessor)
 ,m_dwAccessorFlags(dwAccessorFlags)
 ,m_cbRowSize(cbRowSize)
{
}//TBindingArray

//------------------------------------------------------------------------
TBindingArray::~TBindingArray()
{;}

//------------------------------------------------------------------------
TBindingArray::self_ptr TBindingArray::Create(DBCOUNTITEM const cBindings)
{
 const size_type self_sz=sizeof(self_type);

 const size_type bindings_offset__first
  =structure::align_up(self_sz,size_type(self_type::c_items_align));

 //--- overflow test
 {
  const size_type c_max_sz=structure::t_numeric_limits<size_type>::max_value();

  const size_type c_max_val_count=((c_max_sz-bindings_offset__first)/sizeof(value_type));

  if(c_max_val_count<cBindings)
   throw std::bad_alloc();
 }//local

 //---
 const size_type bindings_offset__last =bindings_offset__first+cBindings*sizeof(value_type);

 const size_type total_sz=bindings_offset__last;

 self_type* const pX=reinterpret_cast<self_type*>(raw_allocator_type::instance.allocate(total_sz));

 assert(pX!=NULL);

 CHECK_READ_WRITE_PTR(pX,total_sz);

 try
 {
  new(pX)self_type(reinterpret_cast<char*>(pX)+bindings_offset__first,
                   cBindings);
 }
 catch(...)
 {
  assert(pX!=NULL);

  raw_allocator_type::instance.deallocate(pX,total_sz);

  throw;
 }//catch

 assert(pX);

 return structure::not_null_ptr(pX);
}//Create

//------------------------------------------------------------------------
TBindingArray::self_ptr
 TBindingArray::Create(HACCESSOR        const hAccessor,
                       DBACCESSORFLAGS  const dwAccessorFlags,
                       DBCOUNTITEM      const cBindings,
                       const DBBINDING        rgBindings[],
                       DBLENGTH         const cbRowSize)
{
 const size_type self_sz=sizeof(self_type);

 const size_type bindings_offset__first
  =structure::align_up(self_sz,size_type(self_type::c_items_align));

 //--- overflow test
 {
  const size_type c_max_sz=structure::t_numeric_limits<size_type>::max_value();

  const size_type c_max_val_count=((c_max_sz-bindings_offset__first)/sizeof(value_type));

  if(c_max_val_count<cBindings)
   throw std::bad_alloc();
 }//local

 //---
 const size_type bindings_offset__last =bindings_offset__first+cBindings*sizeof(value_type);

 const size_type total_sz=bindings_offset__last;

 self_type* const pX=reinterpret_cast<self_type*>(raw_allocator_type::instance.allocate(total_sz));

 assert(pX);

 try
 {
  new(pX)self_type(reinterpret_cast<char*>(pX)+bindings_offset__first,
                   hAccessor,
                   dwAccessorFlags,
                   cBindings,
                   rgBindings,
                   cbRowSize);
 }
 catch(...)
 {
  assert(pX!=NULL);

  raw_allocator_type::instance.deallocate(pX,total_sz);

  throw;
 }//catch

 assert(pX);

 return structure::not_null_ptr(pX);
}//Create

//------------------------------------------------------------------------
void TBindingArray::GetBindings_(DBACCESSORFLAGS* const pdwAccessorFlags,
                                 DBCOUNTITEM*     const pcBindings,
                                 DBBINDING**      const prgBindings)const
{
 if(pdwAccessorFlags!=NULL)
  (*pdwAccessorFlags)=m_dwAccessorFlags;

 if(pcBindings!=NULL)
  (*pcBindings)=0;

 if(prgBindings!=NULL)
  (*prgBindings)=NULL;

 if(pdwAccessorFlags==NULL || pcBindings==NULL || prgBindings==NULL)
  t_base_com_error::throw_error(E_INVALIDARG);

 if(this->empty())
  return;

 //DONE 5: use std::uninitialized_copy
 assert_s(sizeof(value_type)==sizeof(**prgBindings));

 //allocate return inited memory
 CO_MEM_POINTER3(DBBINDING)
  spBindings(ole_lib::CoTaskMemAllocate2<DBBINDING>(this->size()));

 structure::uninitialized_copy
   (this->begin(),
    this->end(),
    static_cast<TBindingData*>(spBindings.ptr()),
    static_cast<TBindingData*>(spBindings.ptr())+this->size()); //throw

 (*pcBindings)  =this->size();
 (*prgBindings) =spBindings.release();
}//GetBindings_

//------------------------------------------------------------------------
void* TBindingArray::operator new (size_t const /*sz*/,void* const pv)
{
 return pv;
}//operator new

//------------------------------------------------------------------------
void TBindingArray::operator delete (void* const pv)
{
 raw_allocator_type::instance.deallocate(pv,0);
}//operator delete

////////////////////////////////////////////////////////////////////////////////
//class TParamBindingData::THelper

#ifndef OLEDB_LIB_NO_ADODB_TYPES

class TParamBindingData::THelper
{
 public:
  static DBLENGTH SelectLength(DBVARIANT::LPCPARAMINFO const pParamInfo,
                               DBLENGTH                const UserSize)
  {
   assert(pParamInfo!=NULL);

   if((pParamInfo->wType&DBTYPE_ARRAY) ||
      (pParamInfo->wType&DBTYPE_VECTOR) ||
      (pParamInfo->VariableLen()))
    return UserSize;

   return pParamInfo->Size;
  }//SelectLength
};//class TParamBindingData::THelper

#endif // ndef OLEDB_LIB_NO_ADODB_TYPES

////////////////////////////////////////////////////////////////////////////////
//class TParamBindingData

TParamBindingData::TParamBindingData(const self_type& x)
{
 //TODO: проверить
 this->pwszDataSourceType =NULL;
 this->pwszName           =NULL;
 this->ulParamSize        =x.ulParamSize;
 this->dwFlags            =x.dwFlags;
 this->bPrecision         =x.bPrecision;
 this->bScale             =x.bScale;

 try
 {
  this->pwszName           =OLEDBMemoryAllocator_AllocWStr(x.pwszName); //throw
  this->pwszDataSourceType =OLEDBMemoryAllocator_AllocWStr(x.pwszDataSourceType); //throw
 }
 catch(...)
 {
  OLEDBMemoryAllocator_FreeWStrAndSetNull(this->pwszDataSourceType);
  OLEDBMemoryAllocator_FreeWStrAndSetNull(this->pwszName);

  throw;
 }
}//copy TParamBindingData

//------------------------------------------------------------------------
TParamBindingData::~TParamBindingData()
{
 OLEDBMemoryAllocator_FreeWStrAndSetNull(this->pwszDataSourceType);
 OLEDBMemoryAllocator_FreeWStrAndSetNull(this->pwszName);
}//~TParamBindingData

//------------------------------------------------------------------------
TParamBindingData& TParamBindingData::operator = (const self_type& x)
{
 self_type tmp(x);

 this->Swap(tmp);

 return *this;
}//operator =

//------------------------------------------------------------------------
void TParamBindingData::Swap(TParamBindingData& x)
{
 std::swap(this->pwszDataSourceType ,x.pwszDataSourceType );
 std::swap(this->pwszName           ,x.pwszName           );
 std::swap(this->ulParamSize        ,x.ulParamSize        );
 std::swap(this->dwFlags            ,x.dwFlags            );
 std::swap(this->bPrecision         ,x.bPrecision         );
 std::swap(this->bScale             ,x.bScale             );
}//Swap

//------------------------------------------------------------------------
void TParamBindingData::SetName(const str_box_type& Name)
{
 wchar_t* const t=OLEDBMemoryAllocator_AllocWStr(Name); //throw

 OLEDBMemoryAllocator_FreeWStrAndSetNull(this->pwszName); //no throw

 this->pwszName=t;
}//SetName

//------------------------------------------------------------------------
void TParamBindingData::SetName(const wstr_box_type& Name)
{
 wchar_t* const t=OLEDBMemoryAllocator_AllocWStr(Name); //throw

 OLEDBMemoryAllocator_FreeWStrAndSetNull(this->pwszName); //no throw

 this->pwszName=t;
}//SetName

//------------------------------------------------------------------------
#ifndef OLEDB_LIB_NO_ADODB_TYPES

void TParamBindingData::SetAdoType_(AdoDataTypeEnum const adType,DBLENGTH const Size)
{
 DBVARIANT::LPCPARAMINFO const pParamInfo=DBVARIANT::GetAdoParamInfo(adType);

 assert(pParamInfo!=NULL);

 wchar_t* const t=OLEDBMemoryAllocator_AllocWStr(pParamInfo->Name);//throw

 OLEDBMemoryAllocator_FreeWStrAndSetNull(this->pwszDataSourceType);

 this->pwszDataSourceType = t;
 this->ulParamSize        = THelper::SelectLength(pParamInfo,Size);

 if(pParamInfo->IsLong())
  this->dwFlags|=DBPARAMFLAGS_ISLONG;
 else
  this->dwFlags&=~DBPARAMFLAGS_ISLONG;
}//SetAdoType_

//------------------------------------------------------------------------
void TParamBindingData::SetType_(DBTYPE const wType,DBLENGTH const Size)
{
 DBVARIANT::LPCPARAMINFO const pParamInfo=DBVARIANT::GetParamInfo(wType,DBCOLUMNFLAGS_ISFIXEDLENGTH);

 assert(pParamInfo!=NULL);

 wchar_t* const t=OLEDBMemoryAllocator_AllocWStr(pParamInfo->Name);//throw

 OLEDBMemoryAllocator_FreeWStrAndSetNull(this->pwszDataSourceType);

 this->pwszDataSourceType = t;
 this->ulParamSize        = THelper::SelectLength(pParamInfo,Size);

 this->dwFlags&=~DBPARAMFLAGS_ISLONG;
}//SetType

#endif //OLEDB_LIB_NO_ADODB_TYPES

////////////////////////////////////////////////////////////////////////////////
//class TDBID - static members

const TDBID::size_type TDBID::npos=TDBID::size_type(-1);

const DBKIND TDBID::sm_eKings[]=
{
 DBKIND_GUID_NAME,
 DBKIND_GUID_PROPID,
 DBKIND_NAME,
 DBKIND_PGUID_NAME,
 DBKIND_PGUID_PROPID,
 DBKIND_PROPID,
 DBKIND_GUID,
};//sm_eKings

//------------------------------------------------------------------------
//проверка корректности dbid
bool TDBID::CheckDBID(const DBID& dbid)
{
 return std::find(sm_eKings,_END_(sm_eKings),dbid.eKind)!=_END_(sm_eKings);
}//CheckDBID

//------------------------------------------------------------------------
//формирование текстового представления идентификатора
std::wstring TDBID::PrintUnicode(const DBID& dbid)
{
 std::wostringstream text;

 text<<L"{";

 switch(dbid.eKind)
 {
  case DBKIND_GUID_NAME:
   text<<clsid_to_wstring(dbid.uGuid.guid)
       <<L","
         L"\""
       <<(dbid.uName.pwszName?dbid.uName.pwszName:L"")
       <<L"\"";
   break;

  case DBKIND_GUID_PROPID:
   text<<clsid_to_wstring(dbid.uGuid.guid)
       <<L","
       <<dbid.uName.ulPropid;
   break;

  case DBKIND_NAME:
   text<<L"\""
       <<(dbid.uName.pwszName?dbid.uName.pwszName:L"")
       <<L"\"";
   break;

  case DBKIND_PGUID_NAME:
   text<<clsid_to_wstring(dbid.uGuid.pguid?*dbid.uGuid.pguid:CLSID_NULL)
       <<L","
         L"\""
       <<(dbid.uName.pwszName?dbid.uName.pwszName:L"")
       <<L"\"";
   break;

  case DBKIND_PGUID_PROPID:
   text<<clsid_to_wstring(dbid.uGuid.pguid?*dbid.uGuid.pguid:CLSID_NULL)
       <<L","
       <<dbid.uName.ulPropid;
   break;

  case DBKIND_PROPID:
   text<<dbid.uName.ulPropid;
   break;

  case DBKIND_GUID:
   text<<clsid_to_wstring(dbid.uGuid.guid);
   break;
 }//switch dbid

 text<<L"}";

 return text.str();
}//PrintUnicode

//------------------------------------------------------------------------
std::string TDBID::Print(const DBID& dbid)
{
 std::string s;

 return structure::unicode_to_ansi(&s,self_type::PrintUnicode(dbid));
}//Print

//------------------------------------------------------------------------
//получение имени

t_oledb_string TDBID::GetName(const DBID& dbid)
{
 t_oledb_string s;

 return self_type::HasName(dbid)?structure::tstr_to_tstr(&s,dbid.uName.pwszName):s;
}//GetName

//------------------------------------------------------------------------
std::string TDBID::GetAnsiName(const DBID& dbid)
{
 std::string s;

 return self_type::HasName(dbid)?structure::unicode_to_ansi(&s,dbid.uName.pwszName):s;
}//GetAnsiName

//------------------------------------------------------------------------
std::wstring TDBID::GetUnicodeName(const DBID& dbid)
{
 return std::wstring(self_type::GetUnicodeNamePtr(dbid,/*NotNULL*/true));
}//GetUnicodeName

//------------------------------------------------------------------------
const wchar_t* TDBID::GetUnicodeNamePtr(const DBID& dbid,bool const NotNull)
{
 if(!self_type::HasName(dbid))
 {
  if(NotNull)
   return L"";

  return nullptr;
 }//if no name

 if(NotNull)
 {
  if(!dbid.uName.pwszName)
   return L"";

  assert_hint(dbid.uName.pwszName);
 }//if NotNull

 return dbid.uName.pwszName;
}//GetUnicodeNamePtr

//------------------------------------------------------------------------
GUID TDBID::GetGUID(const DBID& dbid)
{
 switch(dbid.eKind)
 {
  //прямое хранение идентификатора
  case DBKIND_GUID         :
  case DBKIND_GUID_NAME    :
  case DBKIND_GUID_PROPID  : return dbid.uGuid.guid;

  //косвенное хранение идентификатора
  case DBKIND_PGUID_NAME   :
  case DBKIND_PGUID_PROPID : if(dbid.uGuid.pguid)
                              return *dbid.uGuid.pguid;
                             break;
 }//switch

 return CLSID_NULL;
}//GetGUID

//------------------------------------------------------------------------
void TDBID::ConvertToDirectGUID(DBID& dbid)
{
 if(!self_type::HasPointedGUID(dbid))
  return;

 //dbid однозначно содержит указатель на GUID

 if(dbid.uGuid.pguid==NULL)
 {
  dbid.uGuid.guid=CLSID_NULL;
 }
 else
 {
  const GUID* const pGUID=dbid.uGuid.pguid;//все-таки union - лучше перестраховаться

  dbid.uGuid.guid=*pGUID;
 }//else

 //изменяем тип
 if(dbid.eKind==DBKIND_PGUID_NAME)
 {
  dbid.eKind=DBKIND_GUID_NAME;
 }
 else
 {
  assert(dbid.eKind==DBKIND_PGUID_PROPID);

  dbid.eKind=DBKIND_GUID_PROPID;
 }//else
}//ConvertToDirectGUID

//------------------------------------------------------------------------
bool TDBID::IsFiltered(const DBID& dbid,const DBID& mask_dbid)
{
 //определяем содержимое mask_dbid
 const bool has_guid=HasGUID(mask_dbid);
 const bool has_id  =HasID(mask_dbid);
 const bool has_name=HasName(mask_dbid);

 //сравнение GUID
 if(has_guid && !self_type::IsGUID(dbid,self_type::GetGUID(mask_dbid)))
  return false;

 if(has_id && !self_type::IsID(dbid,self_type::GetID(mask_dbid)))
  return false;

 if(has_name)
 {
  if(!self_type::HasName(dbid))
   return false;

  LPCWSTR lpszName=dbid.uName.pwszName?dbid.uName.pwszName:L"";
  LPCWSTR lpszMask=mask_dbid.uName.pwszName?mask_dbid.uName.pwszName:L"";

  while(*lpszName && *lpszMask && *lpszName==*lpszMask)
  {
   ++lpszName;
   ++lpszMask;
  }

  if((*lpszMask)!=0)
   return false; //маска просмотрена не полностью
 }//if - has_name

 return has_guid || has_id || has_name;
}//TDBID::IsFiltered

//------------------------------------------------------------------------
bool TDBID::IsEqual(const DBID& id1,const DBID& id2)
{
 //указатели на сравниваемые объекты
 const DBID* pid1=&id1;
 const DBID* pid2=&id2;

 //временные объекты, устраняющие косвенность GUID
 DBID tmp_id1;
 DBID tmp_id2;

 //устранение косвенности
 if(self_type::HasPointedGUID(*pid1))
 {
  tmp_id1=*pid1; //NOTE: direct copy!!!

  self_type::ConvertToDirectGUID(tmp_id1);

  pid1=&tmp_id1;
 }//if

 if(self_type::HasPointedGUID(*pid2))
 {
  tmp_id2=*pid2; //NOTE: direct copy!!!

  self_type::ConvertToDirectGUID(tmp_id2);

  pid2=&tmp_id2;
 }//if

 assert(pid1);
 assert(pid2);

 //сравнение объектов
 if(pid1->eKind!=pid2->eKind)
  return false;

 switch(pid1->eKind)
 {
  case DBKIND_GUID_NAME:
  {
   if(!ole_lib::GuidEqual(pid1->uGuid.guid,pid2->uGuid.guid))
    return false;

   if(wcscmp(self_type::GetUnicodeNamePtr(*pid1,/*NotNULL*/true),
             self_type::GetUnicodeNamePtr(*pid2,/*NotNULL*/true))!=0)
   {
    return false;
   }

   return true;
  }//DBKIND_GUID_NAME

  case DBKIND_GUID_PROPID:
  {
   if(!ole_lib::GuidEqual(pid1->uGuid.guid,pid2->uGuid.guid))
    return false;

   if(pid1->uName.ulPropid != pid2->uName.ulPropid)
    return false;

   return true;
  }//DBKIND_GUID_PROPID

  case DBKIND_NAME:
  {
   return wcscmp(self_type::GetUnicodeNamePtr(*pid1,/*NotNULL*/true),
                 self_type::GetUnicodeNamePtr(*pid2,/*NotNULL*/true))==0;
  }//DBKIND_NAME

  case DBKIND_PROPID:
  {
   return pid1->uName.ulPropid == pid2->uName.ulPropid;
  }//DBKIND_PROPID

  case DBKIND_GUID:
  {
   return ole_lib::GuidEqual(pid1->uGuid.guid,pid2->uGuid.guid);
  }//DBKIND_GUID
 }//switch

 return false;
}//IsEqual

//------------------------------------------------------------------------
void TDBID::FillDBID(const DBID&       SourceDBID,
                     DBID*       const pDBID,
                     OLECHAR*&         pBufferPos,
                     OLECHAR*    const pBufferEnd)
{
 assert(pDBID!=NULL);

 CHECK_WRITE_PTR(pDBID,sizeof(*pDBID));

 assert(pBufferPos<=pBufferEnd);

 //прямое копирование DBID. Указатели обрабатываются дальше
 (*pDBID)=SourceDBID;

 //устраняем косвенность на GUID колонки
 TDBID::ConvertToDirectGUID(*pDBID);

 if(!TDBID::HasName(*pDBID))
  return;

 //сохраняем имя
 size_t const NameLength=TDBID::GetNameLen(*pDBID);

 if(NameLength==0)
 {
  pDBID->uName.pwszName=NULL;
 }
 else
 {
  assert((pBufferPos+NameLength+1)<=pBufferEnd);

  CHECK_READ_TYPED_PTR(pDBID->uName.pwszName,(NameLength+1));

  const wchar_t* const x=pDBID->uName.pwszName;

  pDBID->uName.pwszName=pBufferPos;

  pBufferPos=structure::copy(x,
                             x+NameLength+1, //копирование вместе с терминальным нулем
                             pBufferPos,
                             pBufferEnd).second;

  assert(pBufferPos<=pBufferEnd);
 }//else - копирование имени
}//FillDBID

////////////////////////////////////////////////////////////////////////////////
//class TDBID

//------------------------------------------------------------------------
TDBID::TDBID(astr_box_type const Name)
{
 this->uName.pwszName=OLEDBMemoryAllocator_AllocWStr(Name);
 this->eKind         =DBKIND_NAME;
}

//------------------------------------------------------------------------
TDBID::TDBID(wstr_box_type const Name)
{
 this->uName.pwszName=OLEDBMemoryAllocator_AllocWStr(Name);
 this->eKind         =DBKIND_NAME;
}

//------------------------------------------------------------------------
TDBID::TDBID(ULONG const PropID)
{
 this->uName.ulPropid =PropID;
 this->eKind          =DBKIND_GUID;
}//TDBID - PropID

//------------------------------------------------------------------------
TDBID::TDBID(REFGUID rGuid)
{
 this->uGuid.guid     =rGuid;
 this->eKind          =DBKIND_GUID;
}//TDBID - guid

//------------------------------------------------------------------------
TDBID::TDBID(REFGUID rGuid,astr_box_type const Name)
{
 this->uGuid.guid     =rGuid;
 this->uName.pwszName =OLEDBMemoryAllocator_AllocWStr(Name);
 this->eKind          =DBKIND_GUID_NAME;
}//TDBID

//------------------------------------------------------------------------
TDBID::TDBID(REFGUID rGuid,wstr_box_type const Name)
{
 this->uGuid.guid     =rGuid;
 this->uName.pwszName =OLEDBMemoryAllocator_AllocWStr(Name.ptr);
 this->eKind          =DBKIND_GUID_NAME;
}//TDBID

//------------------------------------------------------------------------
TDBID::TDBID(REFGUID rGuid,ULONG const PropID)
{
 this->uGuid.guid     =rGuid;
 this->uName.ulPropid =PropID;
 this->eKind          =DBKIND_GUID_PROPID;
}//TDBID - guid+prop_id

//------------------------------------------------------------------------
void TDBID::InitFromDBID(const DBID& dbid) //throw
{
 memcpy(this,&dbid,sizeof(dbid));

 this->ConvertToDirectGUID();

 //creating a string copy
 if(self_type::HasName(dbid) && dbid.uName.pwszName!=NULL)
 {
  assert(this->HasName());

  _VERIFY(this->uName.pwszName=OLEDBMemoryAllocator_AllocWStr(dbid.uName.pwszName)); //throw
 }//if
}//InitFromDBID

//------------------------------------------------------------------------
void TDBID::flush()
{
 if(this->HasName() && this->uName.pwszName!=NULL)
 {
  OLEDBMemoryAllocator_FreeWStrAndSetNull(this->uName.pwszName);
 }
}//flush

//------------------------------------------------------------------------
TDBID& TDBID::operator = (const self_type& x)
{
 self_type tmp(x);

 this->swap(tmp);

 return *this;
}//operator = (const self_type&)

//------------------------------------------------------------------------
TDBID& TDBID::operator = (const DBID& x)
{
 self_type tmp(x);

 this->swap(tmp);

 return *this;
}//operator = (const DBID&)

//------------------------------------------------------------------------
TDBID& TDBID::swap(self_type& x)
{
 const DBID tmp(*this);

 (*static_cast<DBID*>(this))=x;

 (*static_cast<DBID*>(&x))=tmp;

 return *this;
}//swap

//------------------------------------------------------------------------
TDBID& TDBID::SetName(astr_box_type const Name)
{
 self_type tmp(Name);

 this->swap(tmp);

 return *this;
}//SetName

//------------------------------------------------------------------------
TDBID& TDBID::SetName(wstr_box_type const Name)
{
 self_type tmp(Name);

 this->swap(tmp);

 return *this;
}//SetName

//------------------------------------------------------------------------
TDBID& TDBID::Set(REFCLSID rguid,astr_box_type const Name)
{
 self_type tmp(rguid,Name);

 this->swap(tmp);

 return *this;
}//Set

//------------------------------------------------------------------------
TDBID& TDBID::Set(REFCLSID rguid,wstr_box_type const Name)
{
 self_type tmp(rguid,Name);

 this->swap(tmp);

 return *this;
}//Set

//------------------------------------------------------------------------
TDBID& TDBID::Set(REFGUID rguid,ULONG const PropID)
{
 self_type tmp(rguid,PropID);

 this->swap(tmp);

 return *this;
}//Set clsid+id

//------------------------------------------------------------------------
TDBID& TDBID::Set(REFGUID rguid)
{
 self_type tmp(rguid);

 this->swap(tmp);

 return *this;
}//Set clsid

//------------------------------------------------------------------------
TDBID& TDBID::Set(ULONG const PropID)
{
 self_type tmp(PropID);

 this->swap(tmp);

 return *this;
}//Set id

//------------------------------------------------------------------------
bool TDBID::operator == (const DBID& dbid)const
{
 return self_type::IsEqual(*this,dbid);
}//operator ==

////////////////////////////////////////////////////////////////////////////////
//class TDBPROP

TDBPROP& TDBPROP::operator = (const VARIANT& var)
{
 HRESULT const hr=ole_lib::Variant_Copy(&this->vValue,&var);

 if(FAILED(hr))
  ole_lib::t_base_ole_error::throw_error(hr,"Failed to install a value into TDBPROP");

 return *this;
}//operator =

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

TDBPROP& TDBPROP::operator = (VARIANT&& var)
{
 VARIANT copyVar(var);

 var.vt=VT_EMPTY;

 std::swap(this->vValue,copyVar);

 HRESULT const hr=ole_lib::Variant_Clear(&copyVar);

 if(FAILED(hr))
 {
  assert_msg(false,"vt="<<copyVar.vt);

  ole_lib::t_base_ole_error::throw_error(hr,"Failed to clear a value of TDBPROP");
 }//if

 assert(hr==S_OK);

 return *this;
}//operator = VARIANT&&

#endif

////////////////////////////////////////////////////////////////////////////////
//class TDBPropertySetBuffer

TDBPropertySetBuffer::TDBPropertySetBuffer()
 :m_pPropSets(NULL)
 ,m_cPropSets(0)
{;}

//------------------------------------------------------------------------
TDBPropertySetBuffer::TDBPropertySetBuffer(size_t     const cPropSets,
                                           DBPROPSET* const pPropSets)
 :m_cPropSets(cPropSets)
 ,m_pPropSets(pPropSets)
{
 assert((m_cPropSets==0)==(m_pPropSets==NULL));
}//TDBPropertySetBuffer

//------------------------------------------------------------------------
TDBPropertySetBuffer::~TDBPropertySetBuffer()
{
 this->Clear();
}//~TDBPropertySetBuffer

//------------------------------------------------------------------------
TDBPropertySetBuffer& TDBPropertySetBuffer::Clear()
{
 assert((m_cPropSets==0)==(m_pPropSets==NULL));

 if(m_pPropSets!=NULL)
 {
  CHECK_READ_TYPED_PTR(m_pPropSets,m_cPropSets);

  for(DBPROPSET *pSet=m_pPropSets,*_eSet(m_pPropSets+m_cPropSets);pSet!=_eSet;++pSet)
  {
   assert((pSet->cProperties==0)==(pSet->rgProperties==NULL));

   for(DBPROP *pProp=pSet->rgProperties,*_eProp=pSet->rgProperties+pSet->cProperties;
      pProp!=_eProp;
      ++pProp)
   {
    CHECK_WRITE_PTR(pProp,sizeof(*pProp));

    _VERIFY_EQ(ole_lib::Variant_Clear(&pProp->vValue),S_OK);
   }

   ::CoTaskMemFree(pSet->rgProperties);

   pSet->rgProperties=NULL;
   pSet->cProperties=0;
  }//for pSet

  ::CoTaskMemFree(m_pPropSets);
 }//if m_pPropSets!=NULL

 m_pPropSets=NULL;
 m_cPropSets=0;

 return *this;
}//Clear

//------------------------------------------------------------------------
const DBPROP* TDBPropertySetBuffer::Get(const TDBPropID& PropID,bool OkOnly)const
{
 assert((m_cPropSets==0)==(m_pPropSets==NULL));

 const DBPROPSET*       pSet=m_pPropSets;
 const DBPROPSET* const eSet=m_pPropSets+m_cPropSets;

 CHECK_READ_TYPED_PTR(m_pPropSets,m_cPropSets);

 for(;pSet!=eSet;++pSet)
 {
  if(pSet->guidPropertySet==PropID.guid)
   break;
 }//for

 if(pSet==eSet)
  return nullptr;

 const DBPROP*       pProp=pSet->rgProperties;
 const DBPROP* const eProp=pSet->rgProperties+pSet->cProperties;

 CHECK_READ_TYPED_PTR(pSet->rgProperties,pSet->cProperties);

 for(;pProp!=eProp;++pProp)
 {
  if(pProp->dwPropertyID==PropID.id)
   break;
 }//for

 if(pProp==eProp)
  return nullptr;

 if(OkOnly && pProp->dwStatus!=DBPROPSTATUS_OK)
  return nullptr;

 return pProp;
}//Get

////////////////////////////////////////////////////////////////////////////////
//class TDBPropertyInfoSetBuffer

TDBPropertyInfoSetBuffer::TDBPropertyInfoSetBuffer()
 :m_cPropInfoSets(0)
 ,m_pPropInfoSets(nullptr)
 ,m_pStringBuffer(nullptr)
{;}

//------------------------------------------------------------------------
TDBPropertyInfoSetBuffer::TDBPropertyInfoSetBuffer(size_t         const cPropInfoSets,
                                                   DBPROPINFOSET* const pPropInfoSets,
                                                   OLECHAR*       const pStringBuffer)
 :m_cPropInfoSets(cPropInfoSets)
 ,m_pPropInfoSets(pPropInfoSets)
 ,m_pStringBuffer(pStringBuffer)
{
 assert((m_cPropInfoSets==0)==(m_pPropInfoSets==NULL));
}//TDBPropertyInfoSetBuffer

//------------------------------------------------------------------------
TDBPropertyInfoSetBuffer::~TDBPropertyInfoSetBuffer()
{
 this->Clear();
}//~TDBPropertyInfoSetBuffer

//------------------------------------------------------------------------
TDBPropertyInfoSetBuffer& TDBPropertyInfoSetBuffer::Clear()
{
 if(m_pStringBuffer!=NULL)
 {
  ::CoTaskMemFree(m_pStringBuffer);

  m_pStringBuffer=NULL;
 }

 //----------
 assert(m_cPropInfoSets==0 || m_pPropInfoSets!=NULL);

 CHECK_READ_TYPED_PTR(m_pPropInfoSets,m_cPropInfoSets);

 if(m_pPropInfoSets!=NULL)
 {
  typedef DBPROPINFOSET* LPDBPROPINFOSET;

  for(LPDBPROPINFOSET iSet=m_pPropInfoSets,_eSet(m_pPropInfoSets+m_cPropInfoSets);
      iSet!=_eSet;
      ++iSet)
  {
   assert((iSet->cPropertyInfos==0)==(iSet->rgPropertyInfos==NULL));

   CHECK_READ_TYPED_PTR(iSet->rgPropertyInfos,iSet->cPropertyInfos);

   for(DBPROPINFO *iProp=iSet->rgPropertyInfos,*_eProp(iSet->rgPropertyInfos+iSet->cPropertyInfos);
       iProp!=_eProp;
       ++iProp)
   {
    CHECK_WRITE_PTR(iProp,sizeof(*iProp));

    _VERIFY_EQ(ole_lib::Variant_Clear(&iProp->vValues),S_OK);
   }//for iProp

   ::CoTaskMemFree(iSet->rgPropertyInfos);

   iSet->rgPropertyInfos=NULL;
   iSet->cPropertyInfos =0;
  }//for iSet

  ::CoTaskMemFree(m_pPropInfoSets);
 }//if m_pPropInfoSets!=NULL

 m_cPropInfoSets=NULL;
 m_pPropInfoSets=NULL;

 return *this;
}//Clear

////////////////////////////////////////////////////////////////////////////////
//class TDBDataBufferUtils

HRESULT TDBDataBufferUtils::FreeDataEx(DBTYPE      const wType,
                                       DBLENGTH    const cData,
                                       void*       const rgData,
                                       DWORD       const Flags)
{
 //no-op
 if(!rgData)
  return S_OK;

 //Loop over all elements of the array
 for(DBLENGTH i=0;i<cData;++i)
 {
  //Free any "out-of-line" memory
  switch(wType)
  {
   case DBTYPE_BSTR:
   {
    BSTR* const pbstr=&(reinterpret_cast<BSTR*>(rgData)[i]);

    if((*pbstr)!=NULL && (Flags&free_flag__bstr)!=0)
    {
     ole_lib::FreeBStr(*pbstr);

     assert((*pbstr)==NULL);
    }//if

    break;
   }//BSTR

   case DBTYPE_VARIANT:
   {
    VARIANT* const pVariant=&(reinterpret_cast<VARIANT*>(rgData)[i]);

    if((Flags&free_flag__variant)!=0)
    {
     _VERIFY_EQ(ole_lib::Variant_Clear(pVariant),S_OK);
    }

    break;
   }//VARIANT

   case DBTYPE_IDISPATCH:
   {
    if((Flags&free_flag__release_disp)!=0)
     ole_lib::ReleaseComInterface((reinterpret_cast<IDispatch**>(rgData))[i]);

    break;
   }//IDISPATCH

   case DBTYPE_IUNKNOWN:
   {
    if((Flags&free_flag__release_unk)!=0)
     ole_lib::ReleaseComInterface((reinterpret_cast<IUnknown**>(rgData))[i]);

    break;
   }//IUNKNOWN

   case DBTYPE_VARNUMERIC:
   case DBTYPE_PROPVARIANT:
   {
    //TODO -oDima: not implemented
    break;
   }

   default:
   {
    //NOTE: All the modifiers are mutually exclusive.

    //DBTYPE_BYREF
    if(wType & DBTYPE_BYREF)
    {
     void** const ppByRef=&(reinterpret_cast<void**>(rgData)[i]);

     //Free any outofline sub elements, (recursive)
     self_type::FreeDataEx
      (DBTYPE(wType&~DBTYPE_BYREF),
       1,
       *ppByRef,
       Flags);

     //Free the allocated block
     if((*ppByRef)!=NULL && (Flags&free_flag__byref)!=0)
     {
      ::CoTaskMemFree(*ppByRef);

      (*ppByRef)=NULL;
     }

     break;
    }//BYREF

    //DBTYPE_VECTOR
    if(wType & DBTYPE_VECTOR)
    {
     DBVECTOR* const pVector=&(reinterpret_cast<DBVECTOR*>(rgData)[i]);

     //Free any outofline sub elements, (recursive)
     if((Flags&free_flag__vector)!=0)
     {
      self_type::FreeDataEx
       (DBTYPE(wType&~DBTYPE_VECTOR),
        pVector->size,
        pVector->ptr,
        free_flag__all);

      //Free the block of memory
      if(pVector->ptr!=NULL)
      {
       ::CoTaskMemFree(pVector->ptr);
       pVector->ptr=NULL;
      }
     }//if dbfree_vector

     break;
    }//VECTOR

    //DBTYPE_ARRAY
    if(wType & DBTYPE_ARRAY)
    {
     SAFEARRAY** const ppSafeArray = &(reinterpret_cast<SAFEARRAY**>(rgData)[i]);

     if((*ppSafeArray)!=NULL && (Flags&free_flag__array)!=0)
     {
      _VERIFY_EQ(ole_lib::SafeArray_Destroy(*ppSafeArray),S_OK);

      (*ppSafeArray)=NULL;
     }

     //ppSafeArray = NULL;
     break;
    }//ARRAY

    break;
   }//default

  }//switch wType

 }//for i

 return S_OK;
}//FreeDataEx

//------------------------------------------------------------------------
void TDBDataBufferUtils::Client_FreeData(const DBBINDING& Binding,
                                         void*      const pData,
                                         DWORD      const Flags)
{
 if(Binding.dwMemOwner!=DBMEMOWNER_CLIENTOWNED)
  return;

 //-----------------------------------------
 if(!OLEDB_VALUE_IS_BOUND(Binding)) //в секции нет данных
  return;

 assert(OLEDB_STATUS_IS_BOUND(Binding));

 if(!OLEDB_STATUS_IS_BOUND(Binding))
  return;

 //-----------------------------------------
 CHECK_READ_PTR(&OLEDB_BINDING_STATUS(Binding,pData),sizeof(DBSTATUS));

 const DBSTATUS BindingStatus=OLEDB_BINDING_STATUS(Binding,pData);

 switch(BindingStatus)
 {
  case DBSTATUS_S_OK           :
  case DBSTATUS_S_TRUNCATED    :
  case DBSTATUS_S_ALREADYEXISTS:
   {
    //Always free in successful status (either Getting or Setting).
    self_type::FreeDataEx
     (Binding.wType,
      1,
      &OLEDB_BINDING_VALUE(Binding,pData),
      Flags);

    break;
   }

  case DBSTATUS_S_ISNULL:
  case DBSTATUS_S_DEFAULT:
  case DBSTATUS_S_IGNORE:
   {
    //Nothing to do in either case Getting or Setting.
    //In Getting data in undefined, in Setting the value was never setup...
    break;
   }

  default:
   {
    //Otherwise data is undefined for retrieval from the provider (GetData, GetColumns, etc)
    //But for Setting (SetData, InsertRow, SetColumns, etc), we created the data
    //which has to be free'd even if the provider failed.

    if((Flags&free_flag__is_param)!=0)
    {
     assert(Binding.eParamIO==DBPARAMIO_INPUT  ||
            Binding.eParamIO==DBPARAMIO_OUTPUT ||
            Binding.eParamIO==0);

     if(Binding.eParamIO==DBPARAMIO_INPUT)
     {
      self_type::FreeDataEx
       (Binding.wType,
        1,
        &OLEDB_BINDING_VALUE(Binding,pData),
        Flags);
     }//if
    }
    else
    if((Flags&free_flag__is_set_data)!=0)
    {
     self_type::FreeDataEx
      (Binding.wType,
       1,
       &OLEDB_BINDING_VALUE(Binding,pData),
       Flags);
    }//if

    break;
   }//default
 }//switch BindingStatus
}//Client_FreeData - single element

//------------------------------------------------------------------------
void TDBDataBufferUtils::Provider_FreeClientData(const DBBINDING& Binding,
                                                 void*      const pData)
{
 if(!OLEDB_VALUE_IS_BOUND(Binding))
  return;

 //-----------------------------------------
 DBSTATUS BindingStatus(DBSTATUS_S_OK);

 if(OLEDB_STATUS_IS_BOUND(Binding))
 {
  CHECK_READ_PTR(&OLEDB_BINDING_STATUS(Binding,pData),sizeof(DBSTATUS));

  BindingStatus=OLEDB_BINDING_STATUS(Binding,pData);
 }//if

 //-----------------------------------------
 if(BindingStatus==DBSTATUS_S_OK)
 {
  self_type::FreeDataEx
   (Binding.wType,
    1,
    &OLEDB_BINDING_VALUE(Binding,pData),
    free_flag__release_unk);
 }//if
}//Provider_FreeClientData

//------------------------------------------------------------------------
HRESULT TDBDataBufferUtils::InitDataEx(const DBBINDING& Binding,
                                       void*     const  pData,
                                       DBSTATUS  const  Status,
                                       DWORD     const  Flags)
{
 if(pData==NULL)
  return (Binding.dwPart&(DBPART_STATUS|DBPART_VALUE|DBPART_LENGTH))?E_FAIL:S_OK;

 int cnErrors=0;

 if(OLEDB_STATUS_IS_BOUND(Binding))
 {
  CHECK_WRITE_PTR(&OLEDB_BINDING_STATUS(Binding,pData),sizeof(DBSTATUS));

  try{OLEDB_BINDING_STATUS(Binding,pData)=Status;}catch(...){++cnErrors;}
 }

 if(OLEDB_LENGTH_IS_BOUND(Binding) && (Flags&init_flag__length)!=0)
 {
  CHECK_WRITE_PTR(&OLEDB_BINDING_LENGTH(Binding,pData),sizeof(DBLENGTH));

  try{OLEDB_BINDING_LENGTH(Binding,pData)=0;}catch(...){++cnErrors;}
 }

 if(OLEDB_VALUE_IS_BOUND(Binding) && (Flags&init_flag__value)!=0)
 {
  CHECK_WRITE_PTR_MSG
   (&OLEDB_BINDING_VALUE(Binding,pData),
    Binding.cbMaxLen,
    "iOrdinal="<<Binding.iOrdinal<<"\n"
    "dwPart="<<Binding.dwPart<<"\n"
    "dwMemOwner="<<Binding.dwMemOwner<<"\n"
    "eParamIO="<<Binding.eParamIO<<"\n"
    "wType="<<Binding.wType);

  //инициализация значения
  try{memset(&OLEDB_BINDING_VALUE(Binding,pData),0,Binding.cbMaxLen);}catch(...){++cnErrors;}
 }//if

 return cnErrors?E_FAIL:S_OK;
}//InitDataEx

////////////////////////////////////////////////////////////////////////////////
//class TestDBPropSetID

const GUID* const TestDBPropSetID::sm_SpecialGUIDs[]=
{
 &DBPROPSET_COLUMNALL,
 &DBPROPSET_CONSTRAINTALL,
 &DBPROPSET_DATASOURCEALL,
 &DBPROPSET_DATASOURCEINFOALL,
 &DBPROPSET_DBINITALL,
 &DBPROPSET_INDEXALL,
 &DBPROPSET_ROWSETALL,
 &DBPROPSET_SESSIONALL,
 &DBPROPSET_STREAMALL,
 &DBPROPSET_TABLEALL,
 &DBPROPSET_TRUSTEEALL,
 &DBPROPSET_VIEWALL,
};//sm_SpecialGUIDs

//------------------------------------------------------------------------
bool TestDBPropSetID::IsSpecialGuid(REFGUID guid)
{
 for(size_t i=0;i!=_DIM_(sm_SpecialGUIDs);++i)
 {
  assert(sm_SpecialGUIDs[i]);

  if((*(sm_SpecialGUIDs[i]))==guid)
   return true;
 }//for i

 return false;
}//IsSpecialGuid

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
