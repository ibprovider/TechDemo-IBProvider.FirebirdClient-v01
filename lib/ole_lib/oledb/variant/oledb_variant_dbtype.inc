////////////////////////////////////////////////////////////////////////////////
//OLEDDB TYPE INFORMATIONS
//This file included in <oledb_variant.cpp>
//                                     Kovalenko Dmitry. December 14, 2002 year.

////////////////////////////////////////////////////////////////////////////////
#define DEF_DBTYPE(Type,Size,Precision,Flags,StrPresent,VType)                \
const DBVARIANT::TTypeInfo g_DBType_##Type=                                   \
 {                                                                            \
  oledb_lib::oledb_typeid__##Type,                                            \
  _OLEDB_LIB_T("DBTYPE_") _OLEDB_LIB_T(#Type),                                \
  Size,                                                                       \
  DBVARIANT::TTypeInfo::precision_type(Precision),                            \
  Flags,                                                                      \
  &oledb_lib_utils::g_service_##Type,                                         \
  StrPresent,                                                                 \
  VType                                                                       \
 };

#define DEF_DBTYPE_ARRAY(Type,Precision,VType)                                \
const DBVARIANT::TTypeInfo g_DBType_Array_##Type=                             \
 {                                                                            \
  oledb_lib::oledb_typeid__ARRAY|oledb_lib::oledb_typeid__##Type,             \
  _OLEDB_LIB_T("DBTYPE_") _OLEDB_LIB_T(#Type) _OLEDB_LIB_T(" | DBTYPE_ARRAY"),\
  sizeof(SAFEARRAY*),                                                         \
  DBVARIANT::TTypeInfo::precision_type(Precision),                            \
  DBVARIANT::DBTypeFlag_FixedLen,                                             \
  &oledb_lib_utils::g_service_ARRAY_##Type,                                   \
  0,                                                                          \
  VType                                                                       \
 };

////////////////////////////////////////////////////////////////////////////////
//define dbtype informations

/*0*/   DEF_DBTYPE(EMPTY,
                   0,oledb_none_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen,
                   0,VT_EMPTY)

/*1*/   DEF_DBTYPE(NULL,
                   0,oledb_none_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen,
                   0,VT_NULL)

/*2*/   DEF_DBTYPE(I2,
                   sizeof(t_oledb_value__I2),oledb_i2_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   6/*-12345*/,VT_I2)

/*3*/   DEF_DBTYPE(I4,
                   sizeof(t_oledb_value__I4),oledb_i4_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   11/*-2147483646*/,VT_I4)

/*4*/   DEF_DBTYPE(R4,
                   sizeof(t_oledb_value__R4),oledb_r4_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   40/*???*/,VT_R4)

/*5*/   DEF_DBTYPE(R8,
                   sizeof(t_oledb_value__R8),oledb_r8_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   40/*???*/,VT_R8)

/*6*/   DEF_DBTYPE(CY,
                   sizeof(t_oledb_value__CY),oledb_cy_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   21/*-922337203685477.5806*/,VT_CY)
                     /*123456789012345678901*/

/*7*/   DEF_DBTYPE(DATE,
                   sizeof(t_oledb_value__DATE),oledb_none_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen,
                   40,VT_DATE)

/*8*/   DEF_DBTYPE(BSTR,
                   sizeof(BSTR),oledb_none_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen,
                   0,VT_BSTR)

/*9*/   DEF_DBTYPE(IDISPATCH,
                   sizeof(IDispatch*),oledb_none_precision,
                   DBVARIANT::DBTypeFlag_FixedLen,
                   0,VT_DISPATCH)

/*10*/  DEF_DBTYPE(ERROR,
                   sizeof(t_oledb_value__SCODE),oledb_none_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen,
                   32,VT_ERROR)

/*11*/  DEF_DBTYPE(BOOL,
                   sizeof(VARIANT_BOOL),oledb_none_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen,
                   5/*true or false*/,VT_BOOL)

//данные могут содержать указатель на COM-объект
/*12*/  DEF_DBTYPE(VARIANT,
                   sizeof(VARIANT),oledb_none_precision,
                   DBVARIANT::DBTypeFlag_FixedLen,
                   0,VT_VARIANT)

/*13*/  DEF_DBTYPE(IUNKNOWN,
                   sizeof(IUnknown*),oledb_none_precision,
                   DBVARIANT::DBTypeFlag_FixedLen,
                   0,VT_UNKNOWN)

/*14*/  DEF_DBTYPE(DECIMAL,
                   sizeof(t_oledb_value__DECIMAL),oledb_decimal_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision|
                   DBVARIANT::DBTypeFlag_ICR_Scale,
                   64,VT_DECIMAL)

/*16*/  DEF_DBTYPE(I1,
                   sizeof(t_oledb_value__I1),oledb_i1_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   4/*-127*/,VT_I2)

/*17*/  DEF_DBTYPE(UI1,
                   sizeof(t_oledb_value__UI1),oledb_ui1_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   3/*255*/,VT_UI1)

/*18*/  DEF_DBTYPE(UI2,
                   sizeof(t_oledb_value__UI2),oledb_ui2_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   5/*65535*/,VT_I4)

/*19*/  DEF_DBTYPE(UI4,
                   sizeof(t_oledb_value__UI4),oledb_ui4_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   10/*4294967295*/,VT_DECIMAL)

/*20*/  DEF_DBTYPE(I8,
                   sizeof(t_oledb_value__I8_s),oledb_i8_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   20/*-9223372036854775806*/,VT_DECIMAL)

/*21*/  DEF_DBTYPE(UI8,
                   sizeof(t_oledb_value__UI8_s),oledb_ui8_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsFixedPrecisionDigit|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision,
                   20/*18446744073709551615*/,VT_DECIMAL)

/*64*/  DEF_DBTYPE(FILETIME,
                   sizeof(t_oledb_value__FILETIME),oledb_filetime_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen,
                   40,VT_DATE)

                   //1        10        20        30      38
                   //01234567890123456789012345678901234567
                   //{00000000-0000-0000-0000-000000000000}
/*72*/  DEF_DBTYPE(GUID,
                   sizeof(t_oledb_value__GUID),oledb_none_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen,
                   38,VT_BSTR)

        //Size - минимальный размер буфера (BINDINGS.cbMaxLen)
        //для строк нужен под завершающий символ
/*128*/ DEF_DBTYPE(BYTES,
                   0,oledb_none_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_VariableLen,
                   0,VT_ARRAY|VT_UI1)

/*129*/ DEF_DBTYPE(STR,
                   sizeof(t_oledb_value__CHAR),oledb_none_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_VariableLen,
                   0,VT_BSTR)

/*130*/ DEF_DBTYPE(WSTR,
                   sizeof(t_oledb_value__WCHAR),oledb_none_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_VariableLen,
                   0,VT_BSTR)

/*131*/ DEF_DBTYPE(NUMERIC,
                   sizeof(t_oledb_value__NUMERIC),oledb_numeric_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_IsDigit|
                   DBVARIANT::DBTypeFlag_ICR_Precision|
                   DBVARIANT::DBTypeFlag_ICR_Scale,
                   64,VT_DECIMAL)

/*133*/ DEF_DBTYPE(DBDATE,
                   sizeof(t_oledb_value__DBDATE),oledb_dbdate_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_ICR_Precision|  //IBP specific
                   DBVARIANT::DBTypeFlag_ICR_Scale|      //IBP specific
                   DBVARIANT::DBTypeFlag_ICR_DateTimePrecision,
                   40,VT_DATE)

/*134*/ DEF_DBTYPE(DBTIME,
                   sizeof(t_oledb_value__DBTIME),oledb_dbtime_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_ICR_Precision|  //IBP specific
                   DBVARIANT::DBTypeFlag_ICR_Scale|      //IBP specific
                   DBVARIANT::DBTypeFlag_ICR_DateTimePrecision,
                   40,VT_BSTR)

/*135*/ DEF_DBTYPE(DBTIMESTAMP,
                   sizeof(t_oledb_value__DBTIMESTAMP),oledb_timestamp_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_ICR_Precision| //as SQLNCLI
                   DBVARIANT::DBTypeFlag_ICR_Scale|     //as SQLNCLI
                   DBVARIANT::DBTypeFlag_ICR_DateTimePrecision,
                   40,VT_DATE)

/*145*/ DEF_DBTYPE(DBTIME2,
                   sizeof(t_oledb_value__DBTIME2),oledb_dbtime2_precision,
                   DBVARIANT::DBTypeFlag_IsNoComObject|
                   DBVARIANT::DBTypeFlag_FixedLen|
                   DBVARIANT::DBTypeFlag_ICR_Precision| //as SQLNCLI
                   DBVARIANT::DBTypeFlag_ICR_Scale|     //as SQLNCLI
                   DBVARIANT::DBTypeFlag_ICR_DateTimePrecision,
                   40,VT_BSTR)

// VT_ARRAY --------------------------------------------------------------------
//DEF_DBTYPE_ARRAY(EMPTY        ,oledb_none_precision  )
//DEF_DBTYPE_ARRAY(NULL         ,oledb_none_precision  )
DEF_DBTYPE_ARRAY(I2             ,oledb_i2_precision    ,VT_ARRAY|VT_I2)
DEF_DBTYPE_ARRAY(I4             ,oledb_i4_precision    ,VT_ARRAY|VT_I4)
DEF_DBTYPE_ARRAY(R4             ,oledb_r4_precision    ,VT_ARRAY|VT_R4)
DEF_DBTYPE_ARRAY(R8             ,oledb_r8_precision    ,VT_ARRAY|VT_R8)
DEF_DBTYPE_ARRAY(CY             ,oledb_cy_precision    ,VT_ARRAY|VT_CY)
DEF_DBTYPE_ARRAY(DATE           ,oledb_none_precision  ,VT_ARRAY|VT_DATE)

DEF_DBTYPE_ARRAY(BSTR           ,oledb_none_precision  ,VT_ARRAY|VT_BSTR)

DEF_DBTYPE_ARRAY(IDISPATCH      ,oledb_none_precision    ,VT_ARRAY|VT_DISPATCH)
DEF_DBTYPE_ARRAY(ERROR          ,oledb_none_precision    ,VT_ARRAY|VT_ERROR)
DEF_DBTYPE_ARRAY(BOOL           ,oledb_none_precision    ,VT_ARRAY|VT_BOOL)
DEF_DBTYPE_ARRAY(VARIANT        ,oledb_none_precision    ,VT_ARRAY|VT_VARIANT)
DEF_DBTYPE_ARRAY(IUNKNOWN       ,oledb_none_precision    ,VT_ARRAY|VT_UNKNOWN)
DEF_DBTYPE_ARRAY(DECIMAL        ,oledb_decimal_precision ,VT_ARRAY|VT_DECIMAL)
DEF_DBTYPE_ARRAY(I1             ,oledb_i1_precision      ,VT_ARRAY|VT_I2)
DEF_DBTYPE_ARRAY(UI1            ,oledb_ui1_precision     ,VT_ARRAY|VT_UI1)
DEF_DBTYPE_ARRAY(UI2            ,oledb_ui2_precision     ,VT_ARRAY|VT_I4)
DEF_DBTYPE_ARRAY(UI4            ,oledb_ui4_precision     ,VT_ARRAY|VT_DECIMAL)
DEF_DBTYPE_ARRAY(I8             ,oledb_i8_precision      ,VT_ARRAY|VT_DECIMAL)
DEF_DBTYPE_ARRAY(UI8            ,oledb_ui8_precision     ,VT_ARRAY|VT_DECIMAL)
DEF_DBTYPE_ARRAY(FILETIME       ,oledb_filetime_precision,VT_ARRAY|VT_DATE)
DEF_DBTYPE_ARRAY(GUID           ,oledb_none_precision    ,VT_ARRAY|VT_BSTR)

DEF_DBTYPE_ARRAY(BYTES          ,oledb_none_precision    ,VT_ARRAY|VT_VARIANT)
DEF_DBTYPE_ARRAY(STR            ,oledb_none_precision    ,VT_ARRAY|VT_BSTR)
DEF_DBTYPE_ARRAY(WSTR           ,oledb_none_precision    ,VT_ARRAY|VT_BSTR)

DEF_DBTYPE_ARRAY(NUMERIC        ,oledb_numeric_precision ,VT_ARRAY|VT_DECIMAL)

DEF_DBTYPE_ARRAY(DBDATE         ,oledb_dbdate_precision    ,VT_ARRAY|VT_DATE)
DEF_DBTYPE_ARRAY(DBTIME         ,oledb_dbtime_precision    ,VT_ARRAY|VT_BSTR)
DEF_DBTYPE_ARRAY(DBTIMESTAMP    ,oledb_timestamp_precision ,VT_ARRAY|VT_DATE)

DEF_DBTYPE_ARRAY(DBTIME2        ,oledb_dbtime2_precision   ,VT_ARRAY|VT_BSTR)

////////////////////////////////////////////////////////////////////////////////
#undef DEF_DBTYPE
#undef DEF_DBTYPE_ARRAY

////////////////////////////////////////////////////////////////////////////////
#define MAKE_DBTYPE(type)         &g_DBType_##type
#define MAKE_DBTYPE_A(type)       &g_DBType_Array_##type

struct
{
 DBVARIANT::LPCTYPEINFO pSimpleTypeInfo;
 DBVARIANT::LPCTYPEINFO pArrayTypeInfo;
} const g_DBTypes[]=
{
/*  0*/ {MAKE_DBTYPE(EMPTY)       ,NULL                          },
/*  1*/ {MAKE_DBTYPE(NULL)        ,NULL                          },
/*  2*/ {MAKE_DBTYPE(I2)          ,MAKE_DBTYPE_A(I2)             },
/*  3*/ {MAKE_DBTYPE(I4)          ,MAKE_DBTYPE_A(I4)             },
/*  4*/ {MAKE_DBTYPE(R4)          ,MAKE_DBTYPE_A(R4)             },
/*  5*/ {MAKE_DBTYPE(R8)          ,MAKE_DBTYPE_A(R8)             },
/*  6*/ {MAKE_DBTYPE(CY)          ,MAKE_DBTYPE_A(CY)             },
/*  7*/ {MAKE_DBTYPE(DATE)        ,MAKE_DBTYPE_A(DATE)           },
/*  8*/ {MAKE_DBTYPE(BSTR)        ,MAKE_DBTYPE_A(BSTR)           },
/*  9*/ {MAKE_DBTYPE(IDISPATCH)   ,MAKE_DBTYPE_A(IDISPATCH)      },
/* 10*/ {MAKE_DBTYPE(ERROR)       ,MAKE_DBTYPE_A(ERROR)          },
/* 11*/ {MAKE_DBTYPE(BOOL)        ,MAKE_DBTYPE_A(BOOL)           },
/* 12*/ {MAKE_DBTYPE(VARIANT)     ,MAKE_DBTYPE_A(VARIANT)        },
/* 13*/ {MAKE_DBTYPE(IUNKNOWN)    ,MAKE_DBTYPE_A(IUNKNOWN)       },
/* 14*/ {MAKE_DBTYPE(DECIMAL)     ,MAKE_DBTYPE_A(DECIMAL)        },
/* 15*/ {NULL                     ,NULL                          },
/* 16*/ {MAKE_DBTYPE(I1)          ,MAKE_DBTYPE_A(I1)             },
/* 17*/ {MAKE_DBTYPE(UI1)         ,MAKE_DBTYPE_A(UI1)            },
/* 18*/ {MAKE_DBTYPE(UI2)         ,MAKE_DBTYPE_A(UI2)            },
/* 19*/ {MAKE_DBTYPE(UI4)         ,MAKE_DBTYPE_A(UI4)            },
/* 20*/ {MAKE_DBTYPE(I8)          ,MAKE_DBTYPE_A(I8)             },
/* 21*/ {MAKE_DBTYPE(UI8)         ,MAKE_DBTYPE_A(UI8)            },
/* 22*/ {NULL                     ,NULL                          },
/* 23*/ {NULL                     ,NULL                          },
/* 24*/ {NULL                     ,NULL                          },
/* 25*/ {NULL                     ,NULL                          },
/* 26*/ {NULL                     ,NULL                          },
/* 27*/ {NULL                     ,NULL                          },
/* 28*/ {NULL                     ,NULL                          },
/* 29*/ {NULL                     ,NULL                          },
/* 30*/ {NULL                     ,NULL                          },
/* 31*/ {NULL                     ,NULL                          },
/* 32*/ {NULL                     ,NULL                          },
/* 33*/ {NULL                     ,NULL                          },
/* 34*/ {NULL                     ,NULL                          },
/* 35*/ {NULL                     ,NULL                          },
/* 36*/ {NULL                     ,NULL                          },
/* 37*/ {NULL                     ,NULL                          },
/* 38*/ {NULL                     ,NULL                          },
/* 39*/ {NULL                     ,NULL                          },
/* 40*/ {NULL                     ,NULL                          },
/* 41*/ {NULL                     ,NULL                          },
/* 42*/ {NULL                     ,NULL                          },
/* 43*/ {NULL                     ,NULL                          },
/* 44*/ {NULL                     ,NULL                          },
/* 45*/ {NULL                     ,NULL                          },
/* 46*/ {NULL                     ,NULL                          },
/* 47*/ {NULL                     ,NULL                          },
/* 48*/ {NULL                     ,NULL                          },
/* 49*/ {NULL                     ,NULL                          },
/* 50*/ {NULL                     ,NULL                          },
/* 51*/ {NULL                     ,NULL                          },
/* 52*/ {NULL                     ,NULL                          },
/* 53*/ {NULL                     ,NULL                          },
/* 54*/ {NULL                     ,NULL                          },
/* 55*/ {NULL                     ,NULL                          },
/* 56*/ {NULL                     ,NULL                          },
/* 57*/ {NULL                     ,NULL                          },
/* 58*/ {NULL                     ,NULL                          },
/* 59*/ {NULL                     ,NULL                          },
/* 60*/ {NULL                     ,NULL                          },
/* 61*/ {NULL                     ,NULL                          },
/* 62*/ {NULL                     ,NULL                          },
/* 63*/ {NULL                     ,NULL                          },
/* 64*/ {MAKE_DBTYPE(FILETIME)    ,MAKE_DBTYPE_A(FILETIME)       },
/* 65*/ {NULL                     ,NULL                          },
/* 66*/ {NULL                     ,NULL                          },
/* 67*/ {NULL                     ,NULL                          },
/* 68*/ {NULL                     ,NULL                          },
/* 69*/ {NULL                     ,NULL                          },
/* 70*/ {NULL                     ,NULL                          },
/* 71*/ {NULL                     ,NULL                          },
/* 72*/ {MAKE_DBTYPE(GUID)        ,MAKE_DBTYPE_A(GUID)           },
/* 73*/ {NULL                     ,NULL                          },
/* 74*/ {NULL                     ,NULL                          },
/* 75*/ {NULL                     ,NULL                          },
/* 76*/ {NULL                     ,NULL                          },
/* 77*/ {NULL                     ,NULL                          },
/* 78*/ {NULL                     ,NULL                          },
/* 79*/ {NULL                     ,NULL                          },
/* 80*/ {NULL                     ,NULL                          },
/* 81*/ {NULL                     ,NULL                          },
/* 82*/ {NULL                     ,NULL                          },
/* 83*/ {NULL                     ,NULL                          },
/* 84*/ {NULL                     ,NULL                          },
/* 85*/ {NULL                     ,NULL                          },
/* 86*/ {NULL                     ,NULL                          },
/* 87*/ {NULL                     ,NULL                          },
/* 88*/ {NULL                     ,NULL                          },
/* 89*/ {NULL                     ,NULL                          },
/* 90*/ {NULL                     ,NULL                          },
/* 91*/ {NULL                     ,NULL                          },
/* 92*/ {NULL                     ,NULL                          },
/* 93*/ {NULL                     ,NULL                          },
/* 94*/ {NULL                     ,NULL                          },
/* 95*/ {NULL                     ,NULL                          },
/* 96*/ {NULL                     ,NULL                          },
/* 97*/ {NULL                     ,NULL                          },
/* 98*/ {NULL                     ,NULL                          },
/* 99*/ {NULL                     ,NULL                          },
/*100*/ {NULL                     ,NULL                          },
/*101*/ {NULL                     ,NULL                          },
/*102*/ {NULL                     ,NULL                          },
/*103*/ {NULL                     ,NULL                          },
/*104*/ {NULL                     ,NULL                          },
/*105*/ {NULL                     ,NULL                          },
/*106*/ {NULL                     ,NULL                          },
/*107*/ {NULL                     ,NULL                          },
/*108*/ {NULL                     ,NULL                          },
/*109*/ {NULL                     ,NULL                          },
/*110*/ {NULL                     ,NULL                          },
/*111*/ {NULL                     ,NULL                          },
/*112*/ {NULL                     ,NULL                          },
/*113*/ {NULL                     ,NULL                          },
/*114*/ {NULL                     ,NULL                          },
/*115*/ {NULL                     ,NULL                          },
/*116*/ {NULL                     ,NULL                          },
/*117*/ {NULL                     ,NULL                          },
/*118*/ {NULL                     ,NULL                          },
/*119*/ {NULL                     ,NULL                          },
/*120*/ {NULL                     ,NULL                          },
/*121*/ {NULL                     ,NULL                          },
/*122*/ {NULL                     ,NULL                          },
/*123*/ {NULL                     ,NULL                          },
/*124*/ {NULL                     ,NULL                          },
/*125*/ {NULL                     ,NULL                          },
/*126*/ {NULL                     ,NULL                          },
/*127*/ {NULL                     ,NULL                          },
/*128*/ {MAKE_DBTYPE(BYTES)       ,MAKE_DBTYPE_A(BYTES)          },
/*129*/ {MAKE_DBTYPE(STR)         ,MAKE_DBTYPE_A(STR)            },
/*130*/ {MAKE_DBTYPE(WSTR)        ,MAKE_DBTYPE_A(WSTR)           },
/*131*/ {MAKE_DBTYPE(NUMERIC)     ,MAKE_DBTYPE_A(NUMERIC)        },
/*132*/ {NULL                     ,NULL                          },
/*133*/ {MAKE_DBTYPE(DBDATE)      ,MAKE_DBTYPE_A(DBDATE)         },
/*134*/ {MAKE_DBTYPE(DBTIME)      ,MAKE_DBTYPE_A(DBTIME)         },
/*135*/ {MAKE_DBTYPE(DBTIMESTAMP) ,MAKE_DBTYPE_A(DBTIMESTAMP)    },
/*136*/ {NULL                     ,NULL                          },
/*137*/ {NULL                     ,NULL                          },
/*138*/ {NULL                     ,NULL                          },
/*139*/ {NULL                     ,NULL                          },
/*140*/ {NULL                     ,NULL                          },
/*141*/ {NULL                     ,NULL                          },
/*142*/ {NULL                     ,NULL                          },
/*143*/ {NULL                     ,NULL                          },
/*144*/ {NULL                     ,NULL                          },
/*145*/ {MAKE_DBTYPE(DBTIME2)     ,MAKE_DBTYPE_A(DBTIME2)        },
};//g_DBTypes

////////////////////////////////////////////////////////////////////////////////
#undef MAKE_DBTYPE
#undef MAKE_DBTYPE_A

////////////////////////////////////////////////////////////////////////////////
//проверяем упорядоченность данных в sm_TypeInfo

#ifndef NDEBUG
void __check_sorted_of_g_DBTypes__()
{
 for(UINT i=0,_count=_DIM_(g_DBTypes);i!=_count;++i)
 {
  if(g_DBTypes[i].pSimpleTypeInfo!=NULL)
  {
   assert_msg(UINT(g_DBTypes[i].pSimpleTypeInfo->Type)==i,
              "type="<<g_DBTypes[i].pSimpleTypeInfo->Type<<"\n"
              "i="<<i);
  }

  if(g_DBTypes[i].pArrayTypeInfo!=NULL)
  {
   assert_msg(g_DBTypes[i].pArrayTypeInfo->Type&DBTYPE_ARRAY,
              "i="<<i);

   assert_msg(UINT(g_DBTypes[i].pArrayTypeInfo->Type)==(i|DBTYPE_ARRAY),
              "i="<<i);
  }
 }//for
}//__check_sorted_of_g_DBTypes__

#if(COMP_CONF_SUPPORT_PRAGMA_STARTUP)
# pragma startup __check_sorted_of_g_DBTypes__ 64
#endif

#endif//NDEBUG
////////////////////////////////////////////////////////////////////////////////

