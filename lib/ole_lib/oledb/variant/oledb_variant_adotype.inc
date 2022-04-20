////////////////////////////////////////////////////////////////////////////////
//ADO TYPES INFORMATIONS
//This file includes in <oledb_variant.cpp>
//                                     Dmirty Kovalenko. 21 december 2002 year.

////////////////////////////////////////////////////////////////////////////////

#define _DEF_ADO_TYPE_DESCR(adTypeID,                                         \
                            wTypeID,                                          \
                            dwColumnFlags,                                    \
                            Name,                                             \
                            Size,                                             \
                            Flags,                                            \
                            adTypeName)                                       \
{                                                                             \
 adTypeID,                                                                    \
 wTypeID,                                                                     \
 dwColumnFlags,                                                               \
 Name,                                                                        \
 Size,                                                                        \
 Flags,                                                                       \
 adTypeName                                                                   \
};

//------------------------------------------------------------------------

#define DEF_ADO_TYPE(adType,wType,Size,Flags)                                 \
static const DBVARIANT::TParamInfo g_ADOType_##adType=                        \
 _DEF_ADO_TYPE_DESCR                                                          \
  (oledb_lib::adodb_typeid__##adType,                                         \
   oledb_lib::oledb_typeid__##wType,                                          \
   DBCOLUMNFLAGS_ISFIXEDLENGTH,                                               \
   _OLEDB_LIB_T("DBTYPE_") _OLEDB_LIB_T(#wType),                              \
   DBVARIANT::TParamInfo::length_type(Size),                                  \
   Flags,                                                                     \
   _OLEDB_LIB_T(#adType))

//------------------------------------------------------------------------

#define DEF_ADO_TYPE_EX(adType,wType,ColFlags,TypeName,Size,Flags)            \
static const DBVARIANT::TParamInfo g_ADOType_##adType=                        \
 _DEF_ADO_TYPE_DESCR                                                          \
  (oledb_lib::adodb_typeid__##adType,                                         \
   oledb_lib::oledb_typeid__####wType,                                        \
   ColFlags,                                                                  \
   TypeName,                                                                  \
   DBVARIANT::TParamInfo::length_type(Size),                                  \
   Flags,                                                                     \
   _OLEDB_LIB_T(#adType))

//------------------------------------------------------------------------

#define DEF_ADO_ARRAY_TYPE(adType,wType)                                      \
static const DBVARIANT::TParamInfo g_ADOType_Array_##adType=                  \
 _DEF_ADO_TYPE_DESCR                                                          \
  (AdoDataTypeEnum(oledb_lib::adodb_typeid__adArray|                          \
                   oledb_lib::adodb_typeid__##adType),                        \
   DBTYPE(oledb_lib::oledb_typeid__ARRAY|                                     \
          oledb_lib::oledb_typeid__##wType),                                  \
   DBCOLUMNFLAGS_ISFIXEDLENGTH,                                               \
   _OLEDB_LIB_T("DBTYPE_") _OLEDB_LIB_T(#wType) _OLEDB_LIB_T(" | DBTYPE_ARRAY"),\
   sizeof(SAFEARRAY*),                                                        \
   DBVARIANT::DBTypeFlag_FixedLen,                                            \
   _OLEDB_LIB_T("adArray+") _OLEDB_LIB_T(#adType))                            \

//------------------------------------------------------------------------

#define DEF_ADO_ARRAY_TYPE_EX(adType,wType,ColFlags,TypeName)                 \
static const DBVARIANT::TParamInfo g_ADOType_Array_##adType=                  \
 _DEF_ADO_TYPE_DESCR                                                          \
  (AdoDataTypeEnum(oledb_lib::adodb_typeid__adArray|                          \
                   oledb_lib::adodb_typeid__##adType),                        \
   DBTYPE(oledb_lib::oledb_typeid__ARRAY|                                     \
          oledb_lib::oledb_typeid__##wType),                                  \
   ColFlags,                                                                  \
   TypeName _OLEDB_LIB_T(" | DBTYPE_ARRAY"),                                  \
   sizeof(SAFEARRAY*),                                                        \
   DBVARIANT::DBTypeFlag_FixedLen,                                            \
   _OLEDB_LIB_T("adArray+") _OLEDB_LIB_T(#adType))

////////////////////////////////////////////////////////////////////////////////

/*  0*/ DEF_ADO_TYPE(adEmpty           ,EMPTY      ,0                     ,DBVARIANT::DBTypeFlag_FixedLen)
/*  2*/ DEF_ADO_TYPE(adSmallInt        ,I2         ,sizeof(short)         ,DBVARIANT::DBTypeFlag_FixedLen)
/*  3*/ DEF_ADO_TYPE(adInteger         ,I4         ,sizeof(LONG)          ,DBVARIANT::DBTypeFlag_FixedLen)
/*  4*/ DEF_ADO_TYPE(adSingle          ,R4         ,sizeof(float)         ,DBVARIANT::DBTypeFlag_FixedLen)
/*  5*/ DEF_ADO_TYPE(adDouble          ,R8         ,sizeof(double)        ,DBVARIANT::DBTypeFlag_FixedLen)
/*  6*/ DEF_ADO_TYPE(adCurrency        ,CY         ,sizeof(tagCY)         ,DBVARIANT::DBTypeFlag_FixedLen)
/*  7*/ DEF_ADO_TYPE(adDate            ,DATE       ,sizeof(DATE)          ,DBVARIANT::DBTypeFlag_FixedLen)
/*  8*/ DEF_ADO_TYPE(adBSTR            ,BSTR       ,sizeof(BSTR)          ,DBVARIANT::DBTypeFlag_FixedLen)
/*  9*/ DEF_ADO_TYPE(adIDispatch       ,IDISPATCH  ,sizeof(IDispatch*)    ,DBVARIANT::DBTypeFlag_FixedLen)
/* 10*/ DEF_ADO_TYPE(adError           ,ERROR      ,sizeof(SCODE)         ,DBVARIANT::DBTypeFlag_FixedLen)
/* 11*/ DEF_ADO_TYPE(adBoolean         ,BOOL       ,sizeof(VARIANT_BOOL)  ,DBVARIANT::DBTypeFlag_FixedLen)
/* 12*/ DEF_ADO_TYPE(adVariant         ,VARIANT    ,sizeof(VARIANT)       ,DBVARIANT::DBTypeFlag_FixedLen)
/* 13*/ DEF_ADO_TYPE(adIUnknown        ,IUNKNOWN   ,sizeof(IUnknown*)     ,DBVARIANT::DBTypeFlag_FixedLen)
/* 14*/ DEF_ADO_TYPE(adDecimal         ,DECIMAL    ,sizeof(tagDEC)        ,DBVARIANT::DBTypeFlag_FixedLen)

/* 16*/ DEF_ADO_TYPE(adTinyInt         ,I1         ,sizeof(signed char)   ,DBVARIANT::DBTypeFlag_FixedLen)
/* 17*/ DEF_ADO_TYPE(adUnsignedTinyInt ,UI1        ,sizeof(BYTE)          ,DBVARIANT::DBTypeFlag_FixedLen)
/* 18*/ DEF_ADO_TYPE(adUnsignedSmallInt,UI2        ,sizeof(unsigned short),DBVARIANT::DBTypeFlag_FixedLen)
/* 19*/ DEF_ADO_TYPE(adUnsignedInt     ,UI4        ,sizeof(ULONG)         ,DBVARIANT::DBTypeFlag_FixedLen)
/* 20*/ DEF_ADO_TYPE(adBigInt          ,I8         ,sizeof(LARGE_INTEGER) ,DBVARIANT::DBTypeFlag_FixedLen)
/* 21*/ DEF_ADO_TYPE(adUnsignedBigInt  ,UI8        ,sizeof(ULARGE_INTEGER),DBVARIANT::DBTypeFlag_FixedLen)

/* 64*/ DEF_ADO_TYPE(adFileTime        ,FILETIME   ,sizeof(FILETIME)      ,DBVARIANT::DBTypeFlag_FixedLen)

/* 72*/ DEF_ADO_TYPE(adGUID            ,GUID       ,sizeof(GUID)          ,DBVARIANT::DBTypeFlag_FixedLen)

//DBCOLUMNFLAGS_ISFIXEDLENGTH --------------------------------------------
/*128*/ DEF_ADO_TYPE_EX(adBinary       ,BYTES ,DBCOLUMNFLAGS_ISFIXEDLENGTH,
                        _OLEDB_LIB_T("DBTYPE_BINARY"),
                        0,
                        DBVARIANT::DBTypeFlag_VariableLen)

/*129*/ DEF_ADO_TYPE_EX(adChar         ,STR   ,DBCOLUMNFLAGS_ISFIXEDLENGTH,
                        _OLEDB_LIB_T("DBTYPE_CHAR"),
                        0,
                        DBVARIANT::DBTypeFlag_VariableLen)

/*130*/ DEF_ADO_TYPE_EX(adWChar        ,WSTR  ,DBCOLUMNFLAGS_ISFIXEDLENGTH,
                        _OLEDB_LIB_T("DBTYPE_WCHAR"),
                        0,
                        DBVARIANT::DBTypeFlag_VariableLen)

/*131*/ DEF_ADO_TYPE(adNumeric         ,NUMERIC    ,sizeof(DB_NUMERIC)    ,DBVARIANT::DBTypeFlag_FixedLen)
/*132*/ DEF_ADO_TYPE(adUserDefined     ,UDT        ,0                     ,DBVARIANT::DBTypeFlag_VariableLen)

/*133*/ DEF_ADO_TYPE(adDBDate          ,DBDATE     ,sizeof(DBDATE)        ,DBVARIANT::DBTypeFlag_FixedLen)
/*134*/ DEF_ADO_TYPE(adDBTime          ,DBTIME     ,sizeof(DBTIME)        ,DBVARIANT::DBTypeFlag_FixedLen)
/*135*/ DEF_ADO_TYPE(adDBTimeStamp     ,DBTIMESTAMP,sizeof(DBTIMESTAMP)   ,DBVARIANT::DBTypeFlag_FixedLen)

/*145*/ DEF_ADO_TYPE(adDBTime2,
                     DBTIME2,
                     sizeof(t_oledb_value__DBTIME2),
                     DBVARIANT::DBTypeFlag_FixedLen)

//VARIABLE_LENGTH AND DBCOLUMNFLAGS_ISLONG -------------------------------
/*200*/ DEF_ADO_TYPE_EX(adVarChar      ,STR   , 0,
                        _OLEDB_LIB_T("DBTYPE_VARCHAR"),
                        0,DBVARIANT::DBTypeFlag_VariableLen)

/*201*/ DEF_ADO_TYPE_EX(adLongVarChar  ,STR   ,DBCOLUMNFLAGS_ISLONG,
                        _OLEDB_LIB_T("DBTYPE_LONGVARCHAR"),
                        -1,
                        DBVARIANT::DBTypeFlag_VariableLen)

/*202*/ DEF_ADO_TYPE_EX(adVarWChar     ,WSTR  , 0,
                        _OLEDB_LIB_T("DBTYPE_WVARCHAR"),
                        0,
                        DBVARIANT::DBTypeFlag_VariableLen)

/*203*/ DEF_ADO_TYPE_EX(adLongVarWChar ,WSTR  ,DBCOLUMNFLAGS_ISLONG,
                        _OLEDB_LIB_T("DBTYPE_WLONGVARCHAR"),
                        -1,
                        DBVARIANT::DBTypeFlag_VariableLen)

/*204*/ DEF_ADO_TYPE_EX(adVarBinary    ,BYTES , 0,
                        _OLEDB_LIB_T("DBTYPE_VARBINARY"),
                        0,DBVARIANT::DBTypeFlag_VariableLen)

/*205*/ DEF_ADO_TYPE_EX(adLongVarBinary,BYTES,DBCOLUMNFLAGS_ISLONG,
                        _OLEDB_LIB_T("DBTYPE_LONGVARBINARY"),
                        -1,DBVARIANT::DBTypeFlag_VariableLen)

//Array Types ------------------------------------------------------------
//DEF_ADO_ARRAY_TYPE(adEmpty           ,EMPTY            )
DEF_ADO_ARRAY_TYPE(adSmallInt        ,I2               )
DEF_ADO_ARRAY_TYPE(adInteger         ,I4               )
DEF_ADO_ARRAY_TYPE(adSingle          ,R4               )
DEF_ADO_ARRAY_TYPE(adDouble          ,R8               )
DEF_ADO_ARRAY_TYPE(adCurrency        ,CY               )
DEF_ADO_ARRAY_TYPE(adDate            ,DATE             )
DEF_ADO_ARRAY_TYPE(adBSTR            ,BSTR             )
DEF_ADO_ARRAY_TYPE(adIDispatch       ,IDISPATCH        )
DEF_ADO_ARRAY_TYPE(adError           ,ERROR            )
DEF_ADO_ARRAY_TYPE(adBoolean         ,BOOL             )
DEF_ADO_ARRAY_TYPE(adVariant         ,VARIANT          )
DEF_ADO_ARRAY_TYPE(adIUnknown        ,IUNKNOWN         )
DEF_ADO_ARRAY_TYPE(adDecimal         ,DECIMAL          )

DEF_ADO_ARRAY_TYPE(adTinyInt         ,I1               )
DEF_ADO_ARRAY_TYPE(adUnsignedTinyInt ,UI1              )
DEF_ADO_ARRAY_TYPE(adUnsignedSmallInt,UI2              )
DEF_ADO_ARRAY_TYPE(adUnsignedInt     ,UI4              )
DEF_ADO_ARRAY_TYPE(adBigInt          ,I8               )
DEF_ADO_ARRAY_TYPE(adUnsignedBigInt  ,UI8              )

DEF_ADO_ARRAY_TYPE(adGUID            ,GUID             )

DEF_ADO_ARRAY_TYPE_EX(adBinary ,BYTES  ,DBCOLUMNFLAGS_ISFIXEDLENGTH,
                      _OLEDB_LIB_T("DBTYPE_BINARY"))

DEF_ADO_ARRAY_TYPE_EX(adChar   ,STR    ,DBCOLUMNFLAGS_ISFIXEDLENGTH,
                      _OLEDB_LIB_T("DBTYPE_CHAR"))

DEF_ADO_ARRAY_TYPE_EX(adWChar  ,WSTR   ,DBCOLUMNFLAGS_ISFIXEDLENGTH,
                      _OLEDB_LIB_T("DBTYPE_WCHAR"))

DEF_ADO_ARRAY_TYPE(adNumeric         ,NUMERIC          )
DEF_ADO_ARRAY_TYPE(adUserDefined     ,UDT              )

DEF_ADO_ARRAY_TYPE(adDBDate          ,DBDATE           )
DEF_ADO_ARRAY_TYPE(adDBTime          ,DBTIME           )
DEF_ADO_ARRAY_TYPE(adDBTimeStamp     ,DBTIMESTAMP      )
DEF_ADO_ARRAY_TYPE(adFileTime        ,FILETIME         )

DEF_ADO_ARRAY_TYPE(adDBTime2         ,DBTIME2          )

DEF_ADO_ARRAY_TYPE_EX(adVarChar  ,STR   ,0,
                      _OLEDB_LIB_T("DBTYPE_VARCHAR"))

DEF_ADO_ARRAY_TYPE_EX(adLongVarChar  ,STR  ,DBCOLUMNFLAGS_ISLONG,
                      _OLEDB_LIB_T("DBTYPE_LONGVARCHAR"))

DEF_ADO_ARRAY_TYPE_EX(adVarWChar ,WSTR  ,0,
                      _OLEDB_LIB_T("DBTYPE_WVARCHAR"))

DEF_ADO_ARRAY_TYPE_EX(adLongVarWChar ,WSTR ,DBCOLUMNFLAGS_ISLONG,
                      _OLEDB_LIB_T("DBTYPE_WLONGVARCHAR"))

DEF_ADO_ARRAY_TYPE_EX(adVarBinary,BYTES ,0,
                      _OLEDB_LIB_T("DBTYPE_VARBINARY"))

DEF_ADO_ARRAY_TYPE_EX(adLongVarBinary,BYTES,DBCOLUMNFLAGS_ISLONG,
                      _OLEDB_LIB_T("DBTYPE_LONGVARBINARY"))

////////////////////////////////////////////////////////////////////////////////
#undef DEF_ADO_TYPE
#undef DEF_ADO_TYPE_EX
#undef DEF_ADO_ARRAY_TYPE
#undef DEF_ADO_ARRAY_TYPE_EX

////////////////////////////////////////////////////////////////////////////////
#define MAKE_ADO_TYPE(adType)     &g_ADOType_##adType
#define MAKE_ADO_TYPE_A(adType)   &g_ADOType_Array_##adType

////////////////////////////////////////////////////////////////////////////////

struct
{
 DBVARIANT::LPCPARAMINFO pSimpleTypeInfo;
 DBVARIANT::LPCPARAMINFO pArrayTypeInfo;
}
 static const g_ADOTypes[]=
{
/*  0*/ {MAKE_ADO_TYPE(adEmpty)         ,NULL                          },
/*  1*/ {NULL                           ,NULL                          },
/*  2*/ {MAKE_ADO_TYPE(adSmallInt)      ,MAKE_ADO_TYPE_A(adSmallInt)   },
/*  3*/ {MAKE_ADO_TYPE(adInteger)       ,MAKE_ADO_TYPE_A(adInteger)    },
/*  4*/ {MAKE_ADO_TYPE(adSingle)        ,MAKE_ADO_TYPE_A(adSingle)     },
/*  5*/ {MAKE_ADO_TYPE(adDouble)        ,MAKE_ADO_TYPE_A(adDouble)     },
/*  6*/ {MAKE_ADO_TYPE(adCurrency)      ,MAKE_ADO_TYPE_A(adCurrency)   },
/*  7*/ {MAKE_ADO_TYPE(adDate)          ,MAKE_ADO_TYPE_A(adDate)       },
/*  8*/ {MAKE_ADO_TYPE(adBSTR)          ,MAKE_ADO_TYPE_A(adBSTR)       },
/*  9*/ {MAKE_ADO_TYPE(adIDispatch)     ,MAKE_ADO_TYPE_A(adIDispatch)  },
/* 10*/ {MAKE_ADO_TYPE(adError)         ,MAKE_ADO_TYPE_A(adError)      },
/* 11*/ {MAKE_ADO_TYPE(adBoolean)       ,MAKE_ADO_TYPE_A(adBoolean)    },
/* 12*/ {MAKE_ADO_TYPE(adVariant)       ,MAKE_ADO_TYPE_A(adVariant)    },
/* 13*/ {MAKE_ADO_TYPE(adIUnknown)      ,MAKE_ADO_TYPE_A(adIUnknown)   },
/* 14*/ {MAKE_ADO_TYPE(adDecimal)       ,MAKE_ADO_TYPE_A(adDecimal)    },
/* 15*/ {NULL                           ,NULL                          },
/* 16*/ {MAKE_ADO_TYPE(adTinyInt)          ,MAKE_ADO_TYPE_A(adTinyInt)         },
/* 17*/ {MAKE_ADO_TYPE(adUnsignedTinyInt)  ,MAKE_ADO_TYPE_A(adUnsignedTinyInt) },
/* 18*/ {MAKE_ADO_TYPE(adUnsignedSmallInt) ,MAKE_ADO_TYPE_A(adUnsignedSmallInt)},
/* 19*/ {MAKE_ADO_TYPE(adUnsignedInt)      ,MAKE_ADO_TYPE_A(adUnsignedInt)     },
/* 20*/ {MAKE_ADO_TYPE(adBigInt)           ,MAKE_ADO_TYPE_A(adBigInt)          },
/* 21*/ {MAKE_ADO_TYPE(adUnsignedBigInt)   ,MAKE_ADO_TYPE_A(adUnsignedBigInt)  },
/* 22*/ {NULL,NULL},
/* 23*/ {NULL,NULL},
/* 24*/ {NULL,NULL},
/* 25*/ {NULL,NULL},
/* 26*/ {NULL,NULL},
/* 27*/ {NULL,NULL},
/* 28*/ {NULL,NULL},
/* 29*/ {NULL,NULL},
/* 30*/ {NULL,NULL},
/* 31*/ {NULL,NULL},
/* 32*/ {NULL,NULL},
/* 33*/ {NULL,NULL},
/* 34*/ {NULL,NULL},
/* 35*/ {NULL,NULL},
/* 36*/ {NULL,NULL},
/* 37*/ {NULL,NULL},
/* 38*/ {NULL,NULL},
/* 39*/ {NULL,NULL},
/* 40*/ {NULL,NULL},
/* 41*/ {NULL,NULL},
/* 42*/ {NULL,NULL},
/* 43*/ {NULL,NULL},
/* 44*/ {NULL,NULL},
/* 45*/ {NULL,NULL},
/* 46*/ {NULL,NULL},
/* 47*/ {NULL,NULL},
/* 48*/ {NULL,NULL},
/* 49*/ {NULL,NULL},
/* 50*/ {NULL,NULL},
/* 51*/ {NULL,NULL},
/* 52*/ {NULL,NULL},
/* 53*/ {NULL,NULL},
/* 54*/ {NULL,NULL},
/* 55*/ {NULL,NULL},
/* 56*/ {NULL,NULL},
/* 57*/ {NULL,NULL},
/* 58*/ {NULL,NULL},
/* 59*/ {NULL,NULL},
/* 60*/ {NULL,NULL},
/* 61*/ {NULL,NULL},
/* 62*/ {NULL,NULL},
/* 63*/ {NULL,NULL},
/* 64*/ {MAKE_ADO_TYPE(adFileTime)    ,MAKE_ADO_TYPE_A(adFileTime)},
/* 65*/ {NULL,NULL},
/* 66*/ {NULL,NULL},
/* 67*/ {NULL,NULL},
/* 68*/ {NULL,NULL},
/* 69*/ {NULL,NULL},
/* 70*/ {NULL,NULL},
/* 71*/ {NULL,NULL},
/* 72*/ {MAKE_ADO_TYPE(adGUID)        ,MAKE_ADO_TYPE_A(adGUID)},
/* 73*/ {NULL,NULL},
/* 74*/ {NULL,NULL},
/* 75*/ {NULL,NULL},
/* 76*/ {NULL,NULL},
/* 77*/ {NULL,NULL},
/* 78*/ {NULL,NULL},
/* 79*/ {NULL,NULL},
/* 80*/ {NULL,NULL},
/* 81*/ {NULL,NULL},
/* 82*/ {NULL,NULL},
/* 83*/ {NULL,NULL},
/* 84*/ {NULL,NULL},
/* 85*/ {NULL,NULL},
/* 86*/ {NULL,NULL},
/* 87*/ {NULL,NULL},
/* 88*/ {NULL,NULL},
/* 89*/ {NULL,NULL},
/* 90*/ {NULL,NULL},
/* 91*/ {NULL,NULL},
/* 92*/ {NULL,NULL},
/* 93*/ {NULL,NULL},
/* 94*/ {NULL,NULL},
/* 95*/ {NULL,NULL},
/* 96*/ {NULL,NULL},
/* 97*/ {NULL,NULL},
/* 98*/ {NULL,NULL},
/* 99*/ {NULL,NULL},
/*100*/ {NULL,NULL},
/*101*/ {NULL,NULL},
/*102*/ {NULL,NULL},
/*103*/ {NULL,NULL},
/*104*/ {NULL,NULL},
/*105*/ {NULL,NULL},
/*106*/ {NULL,NULL},
/*107*/ {NULL,NULL},
/*108*/ {NULL,NULL},
/*109*/ {NULL,NULL},
/*110*/ {NULL,NULL},
/*111*/ {NULL,NULL},
/*112*/ {NULL,NULL},
/*113*/ {NULL,NULL},
/*114*/ {NULL,NULL},
/*115*/ {NULL,NULL},
/*116*/ {NULL,NULL},
/*117*/ {NULL,NULL},
/*118*/ {NULL,NULL},
/*119*/ {NULL,NULL},
/*120*/ {NULL,NULL},
/*121*/ {NULL,NULL},
/*122*/ {NULL,NULL},
/*123*/ {NULL,NULL},
/*124*/ {NULL,NULL},
/*125*/ {NULL,NULL},
/*126*/ {NULL,NULL},
/*127*/ {NULL,NULL},
/*128*/ {MAKE_ADO_TYPE(adBinary)      ,MAKE_ADO_TYPE_A(adBinary)      },
/*129*/ {MAKE_ADO_TYPE(adChar)        ,MAKE_ADO_TYPE_A(adChar)        },
/*130*/ {MAKE_ADO_TYPE(adWChar)       ,MAKE_ADO_TYPE_A(adWChar)       },
/*131*/ {MAKE_ADO_TYPE(adNumeric)     ,MAKE_ADO_TYPE_A(adNumeric)     },
/*132*/ {MAKE_ADO_TYPE(adUserDefined) ,MAKE_ADO_TYPE_A(adUserDefined) },
/*133*/ {MAKE_ADO_TYPE(adDBDate)      ,MAKE_ADO_TYPE_A(adDBDate)      },
/*134*/ {MAKE_ADO_TYPE(adDBTime)      ,MAKE_ADO_TYPE_A(adDBTime)      },
/*135*/ {MAKE_ADO_TYPE(adDBTimeStamp) ,MAKE_ADO_TYPE_A(adDBTimeStamp) },
/*136*/ {NULL,NULL},
/*137*/ {NULL,NULL},
/*138*/ {NULL,NULL},
/*139*/ {NULL,NULL},
/*140*/ {NULL,NULL},
/*141*/ {NULL,NULL},
/*142*/ {NULL,NULL},
/*143*/ {NULL,NULL},
/*144*/ {NULL,NULL},
/*145*/ {MAKE_ADO_TYPE(adDBTime2)     ,MAKE_ADO_TYPE_A(adDBTime2)     },
/*146*/ {NULL,NULL},
/*147*/ {NULL,NULL},
/*148*/ {NULL,NULL},
/*149*/ {NULL,NULL},
/*150*/ {NULL,NULL},
/*151*/ {NULL,NULL},
/*152*/ {NULL,NULL},
/*153*/ {NULL,NULL},
/*154*/ {NULL,NULL},
/*155*/ {NULL,NULL},
/*156*/ {NULL,NULL},
/*157*/ {NULL,NULL},
/*158*/ {NULL,NULL},
/*159*/ {NULL,NULL},
/*160*/ {NULL,NULL},
/*161*/ {NULL,NULL},
/*162*/ {NULL,NULL},
/*163*/ {NULL,NULL},
/*164*/ {NULL,NULL},
/*165*/ {NULL,NULL},
/*166*/ {NULL,NULL},
/*167*/ {NULL,NULL},
/*168*/ {NULL,NULL},
/*169*/ {NULL,NULL},
/*170*/ {NULL,NULL},
/*171*/ {NULL,NULL},
/*172*/ {NULL,NULL},
/*173*/ {NULL,NULL},
/*174*/ {NULL,NULL},
/*175*/ {NULL,NULL},
/*176*/ {NULL,NULL},
/*177*/ {NULL,NULL},
/*178*/ {NULL,NULL},
/*179*/ {NULL,NULL},
/*180*/ {NULL,NULL},
/*181*/ {NULL,NULL},
/*182*/ {NULL,NULL},
/*183*/ {NULL,NULL},
/*184*/ {NULL,NULL},
/*185*/ {NULL,NULL},
/*186*/ {NULL,NULL},
/*187*/ {NULL,NULL},
/*188*/ {NULL,NULL},
/*189*/ {NULL,NULL},
/*190*/ {NULL,NULL},
/*191*/ {NULL,NULL},
/*192*/ {NULL,NULL},
/*193*/ {NULL,NULL},
/*194*/ {NULL,NULL},
/*195*/ {NULL,NULL},
/*196*/ {NULL,NULL},
/*197*/ {NULL,NULL},
/*198*/ {NULL,NULL},
/*199*/ {NULL,NULL},
/*200*/ {MAKE_ADO_TYPE(adVarChar)       ,MAKE_ADO_TYPE_A(adVarChar)       },
/*201*/ {MAKE_ADO_TYPE(adLongVarChar)   ,MAKE_ADO_TYPE_A(adLongVarChar)   },
/*202*/ {MAKE_ADO_TYPE(adVarWChar)      ,MAKE_ADO_TYPE_A(adVarWChar)      },
/*203*/ {MAKE_ADO_TYPE(adLongVarWChar)  ,MAKE_ADO_TYPE_A(adLongVarWChar)  },
/*204*/ {MAKE_ADO_TYPE(adVarBinary)     ,MAKE_ADO_TYPE_A(adVarBinary)     },
/*205*/ {MAKE_ADO_TYPE(adLongVarBinary) ,MAKE_ADO_TYPE_A(adLongVarBinary) },
};//g_ADOTypes

////////////////////////////////////////////////////////////////////////////////
//проверка корректности таблицы g_ADOTypes

#ifndef NDEBUG

static void __check_sorted_of_g_ADOTypes__()
{
 for(UINT i=0,_count=_DIM_(g_ADOTypes);i!=_count;++i)
 {
  if(g_ADOTypes[i].pSimpleTypeInfo!=NULL)
  {
   assert_msg(UINT(g_ADOTypes[i].pSimpleTypeInfo->adType)==i,
              "type="<<g_ADOTypes[i].pSimpleTypeInfo->adType<<"\n"
              "i="<<i);
  }

  if(g_ADOTypes[i].pArrayTypeInfo!=NULL)
  {
   assert_msg(g_ADOTypes[i].pArrayTypeInfo->wType&DBTYPE_ARRAY,
              "i="<<i);

   assert_msg(g_ADOTypes[i].pArrayTypeInfo->adType&DBTYPE_ARRAY,
              "i="<<i);

   assert_msg(UINT(g_ADOTypes[i].pArrayTypeInfo->adType)==(i|DBTYPE_ARRAY),
              "i="<<i);
  }
 }//for
}//__check_sorted_of_g_ADOTypes__

STARTUP_CODE__DEBUG(__check_sorted_of_g_ADOTypes__)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//Map OLEDB types to ADO types

struct TMapDBTypeToADOType
{
#ifndef NDEBUG
 DBTYPE  wType;
#endif
 DBVARIANT::LPCPARAMINFO* map;
};

#ifndef NDEBUG

# define BEG_DBTYPE_ADO_MAP(dbtype)                                       \
  extern DBVARIANT::LPCPARAMINFO g_DBType_##dbtype##_ADO_map__items[];    \
                                                                          \
  static const TMapDBTypeToADOType g_DBType_##dbtype##_ADO_map=           \
  {                                                                       \
   oledb_lib::oledb_typeid__##dbtype,                                     \
   g_DBType_##dbtype##_ADO_map__items                                     \
  };                                                                      \
                                                                          \
  DBVARIANT::LPCPARAMINFO g_DBType_##dbtype##_ADO_map__items[]=           \
  {

#else

# define BEG_DBTYPE_ADO_MAP(dbtype)                                       \
  extern DBVARIANT::LPCPARAMINFO g_DBType_##dbtype##_ADO_map__items[];    \
                                                                          \
  static const TMapDBTypeToADOType g_DBType_##dbtype##_ADO_map=           \
  {                                                                       \
   g_DBType_##dbtype##_ADO_map__items                                     \
  };                                                                      \
                                                                          \
  DBVARIANT::LPCPARAMINFO g_DBType_##dbtype##_ADO_map__items[]=           \
  {

#endif

#define END_DBTYPE_ADO_MAP()                                              \
 NULL};

////////////////////////////////////////////////////////////////////////////////
BEG_DBTYPE_ADO_MAP(EMPTY)
 MAKE_ADO_TYPE(adEmpty),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(I2)
 MAKE_ADO_TYPE(adSmallInt),MAKE_ADO_TYPE_A(adSmallInt),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(I4)
 MAKE_ADO_TYPE(adInteger),MAKE_ADO_TYPE_A(adInteger),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(R4)
 MAKE_ADO_TYPE(adSingle),MAKE_ADO_TYPE_A(adSingle),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(R8)
 MAKE_ADO_TYPE(adDouble),MAKE_ADO_TYPE_A(adDouble),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(CY)
 MAKE_ADO_TYPE(adCurrency),MAKE_ADO_TYPE_A(adCurrency),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(DATE)
 MAKE_ADO_TYPE(adDate),MAKE_ADO_TYPE_A(adDate),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(BSTR)
 MAKE_ADO_TYPE(adBSTR),MAKE_ADO_TYPE_A(adBSTR),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(IDISPATCH)
 MAKE_ADO_TYPE(adIDispatch),MAKE_ADO_TYPE_A(adIDispatch),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(ERROR)
 MAKE_ADO_TYPE(adError),MAKE_ADO_TYPE_A(adError),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(BOOL)
 MAKE_ADO_TYPE(adBoolean),MAKE_ADO_TYPE_A(adBoolean),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(VARIANT)
 MAKE_ADO_TYPE(adVariant),MAKE_ADO_TYPE_A(adVariant),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(IUNKNOWN)
 MAKE_ADO_TYPE(adIUnknown),MAKE_ADO_TYPE_A(adIUnknown),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(DECIMAL)
 MAKE_ADO_TYPE(adDecimal),MAKE_ADO_TYPE_A(adDecimal),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(I1)
 MAKE_ADO_TYPE(adTinyInt),MAKE_ADO_TYPE_A(adTinyInt),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(UI1)
 MAKE_ADO_TYPE(adUnsignedTinyInt),MAKE_ADO_TYPE_A(adUnsignedTinyInt),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(UI2)
 MAKE_ADO_TYPE(adUnsignedSmallInt),MAKE_ADO_TYPE_A(adUnsignedSmallInt),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(UI4)
 MAKE_ADO_TYPE(adUnsignedInt),MAKE_ADO_TYPE_A(adUnsignedInt),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(I8)
 MAKE_ADO_TYPE(adBigInt),MAKE_ADO_TYPE_A(adBigInt),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(UI8)
 MAKE_ADO_TYPE(adUnsignedBigInt),MAKE_ADO_TYPE_A(adUnsignedBigInt),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(GUID)
 MAKE_ADO_TYPE(adGUID),MAKE_ADO_TYPE_A(adGUID),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(FILETIME)
 MAKE_ADO_TYPE(adFileTime),MAKE_ADO_TYPE_A(adFileTime),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(BYTES)
 MAKE_ADO_TYPE(adBinary)         ,MAKE_ADO_TYPE_A(adBinary),
 MAKE_ADO_TYPE(adVarBinary)      ,MAKE_ADO_TYPE_A(adVarBinary),
 MAKE_ADO_TYPE(adLongVarBinary)  ,MAKE_ADO_TYPE_A(adLongVarBinary),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(STR)
 MAKE_ADO_TYPE(adChar)          ,MAKE_ADO_TYPE_A(adChar),
 MAKE_ADO_TYPE(adVarChar)       ,MAKE_ADO_TYPE_A(adVarChar),
 MAKE_ADO_TYPE(adLongVarChar)   ,MAKE_ADO_TYPE_A(adLongVarChar),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(WSTR)
 MAKE_ADO_TYPE(adWChar)         ,MAKE_ADO_TYPE_A(adWChar),
 MAKE_ADO_TYPE(adVarWChar)      ,MAKE_ADO_TYPE_A(adVarWChar),
 MAKE_ADO_TYPE(adLongVarWChar)  ,MAKE_ADO_TYPE_A(adLongVarWChar),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(NUMERIC)
 MAKE_ADO_TYPE(adNumeric),MAKE_ADO_TYPE_A(adNumeric),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(DBDATE)
 MAKE_ADO_TYPE(adDBDate),MAKE_ADO_TYPE_A(adDBDate),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(DBTIME)
 MAKE_ADO_TYPE(adDBTime),MAKE_ADO_TYPE_A(adDBTime),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(DBTIME2)
 MAKE_ADO_TYPE(adDBTime2),MAKE_ADO_TYPE_A(adDBTime2),
END_DBTYPE_ADO_MAP()

BEG_DBTYPE_ADO_MAP(DBTIMESTAMP)
 MAKE_ADO_TYPE(adDBTimeStamp),MAKE_ADO_TYPE_A(adDBTimeStamp),
END_DBTYPE_ADO_MAP()

////////////////////////////////////////////////////////////////////////////////
#define DEF_DBTYPE_ADO_MAP(dbtype) &g_DBType_##dbtype##_ADO_map

////////////////////////////////////////////////////////////////////////////////
const TMapDBTypeToADOType* g_DBTypeToADOTypeMap[]=
{
/*  0*/ DEF_DBTYPE_ADO_MAP(EMPTY),
/*  1*/ NULL,
/*  2*/ DEF_DBTYPE_ADO_MAP(I2),
/*  3*/ DEF_DBTYPE_ADO_MAP(I4),
/*  4*/ DEF_DBTYPE_ADO_MAP(R4),
/*  5*/ DEF_DBTYPE_ADO_MAP(R8),
/*  6*/ DEF_DBTYPE_ADO_MAP(CY),
/*  7*/ DEF_DBTYPE_ADO_MAP(DATE),
/*  8*/ DEF_DBTYPE_ADO_MAP(BSTR),
/*  9*/ DEF_DBTYPE_ADO_MAP(IDISPATCH),
/* 10*/ DEF_DBTYPE_ADO_MAP(ERROR),
/* 11*/ DEF_DBTYPE_ADO_MAP(BOOL),
/* 12*/ DEF_DBTYPE_ADO_MAP(VARIANT),
/* 13*/ DEF_DBTYPE_ADO_MAP(IUNKNOWN),
/* 14*/ DEF_DBTYPE_ADO_MAP(DECIMAL),
/* 15*/ NULL,
/* 16*/ DEF_DBTYPE_ADO_MAP(I1),
/* 17*/ DEF_DBTYPE_ADO_MAP(UI1),
/* 18*/ DEF_DBTYPE_ADO_MAP(UI2),
/* 19*/ DEF_DBTYPE_ADO_MAP(UI4),
/* 20*/ DEF_DBTYPE_ADO_MAP(I8),
/* 21*/ DEF_DBTYPE_ADO_MAP(UI8),
/* 22*/ NULL,
/* 23*/ NULL,
/* 24*/ NULL,
/* 25*/ NULL,
/* 26*/ NULL,
/* 27*/ NULL,
/* 28*/ NULL,
/* 29*/ NULL,
/* 30*/ NULL,
/* 31*/ NULL,
/* 32*/ NULL,
/* 33*/ NULL,
/* 34*/ NULL,
/* 35*/ NULL,
/* 36*/ NULL,
/* 37*/ NULL,
/* 38*/ NULL,
/* 39*/ NULL,
/* 40*/ NULL,
/* 41*/ NULL,
/* 42*/ NULL,
/* 43*/ NULL,
/* 44*/ NULL,
/* 45*/ NULL,
/* 46*/ NULL,
/* 47*/ NULL,
/* 48*/ NULL,
/* 49*/ NULL,
/* 50*/ NULL,
/* 51*/ NULL,
/* 52*/ NULL,
/* 53*/ NULL,
/* 54*/ NULL,
/* 55*/ NULL,
/* 56*/ NULL,
/* 57*/ NULL,
/* 58*/ NULL,
/* 59*/ NULL,
/* 60*/ NULL,
/* 61*/ NULL,
/* 62*/ NULL,
/* 63*/ NULL,
/* 64*/ DEF_DBTYPE_ADO_MAP(FILETIME),
/* 65*/ NULL,
/* 66*/ NULL,
/* 67*/ NULL,
/* 68*/ NULL,
/* 69*/ NULL,
/* 70*/ NULL,
/* 71*/ NULL,
/* 72*/ DEF_DBTYPE_ADO_MAP(GUID),
/* 73*/ NULL,
/* 74*/ NULL,
/* 75*/ NULL,
/* 76*/ NULL,
/* 77*/ NULL,
/* 78*/ NULL,
/* 79*/ NULL,
/* 80*/ NULL,
/* 81*/ NULL,
/* 82*/ NULL,
/* 83*/ NULL,
/* 84*/ NULL,
/* 85*/ NULL,
/* 86*/ NULL,
/* 87*/ NULL,
/* 88*/ NULL,
/* 89*/ NULL,
/* 90*/ NULL,
/* 91*/ NULL,
/* 92*/ NULL,
/* 93*/ NULL,
/* 94*/ NULL,
/* 95*/ NULL,
/* 96*/ NULL,
/* 97*/ NULL,
/* 98*/ NULL,
/* 99*/ NULL,
/*100*/ NULL,
/*101*/ NULL,
/*102*/ NULL,
/*103*/ NULL,
/*104*/ NULL,
/*105*/ NULL,
/*106*/ NULL,
/*107*/ NULL,
/*108*/ NULL,
/*109*/ NULL,
/*110*/ NULL,
/*111*/ NULL,
/*112*/ NULL,
/*113*/ NULL,
/*114*/ NULL,
/*115*/ NULL,
/*116*/ NULL,
/*117*/ NULL,
/*118*/ NULL,
/*119*/ NULL,
/*120*/ NULL,
/*121*/ NULL,
/*122*/ NULL,
/*123*/ NULL,
/*124*/ NULL,
/*125*/ NULL,
/*126*/ NULL,
/*127*/ NULL,
/*128*/ DEF_DBTYPE_ADO_MAP(BYTES),
/*129*/ DEF_DBTYPE_ADO_MAP(STR),
/*130*/ DEF_DBTYPE_ADO_MAP(WSTR),
/*131*/ DEF_DBTYPE_ADO_MAP(NUMERIC),
/*132*/ NULL,
/*133*/ DEF_DBTYPE_ADO_MAP(DBDATE),
/*134*/ DEF_DBTYPE_ADO_MAP(DBTIME),
/*135*/ DEF_DBTYPE_ADO_MAP(DBTIMESTAMP),
/*136*/ NULL,
/*137*/ NULL,
/*138*/ NULL,
/*139*/ NULL,
/*140*/ NULL,
/*141*/ NULL,
/*142*/ NULL,
/*143*/ NULL,
/*144*/ NULL,
/*145*/ DEF_DBTYPE_ADO_MAP(DBTIME2),
};//g_DBTypeToADOTypeMap

////////////////////////////////////////////////////////////////////////////////
//Check g_DBTypeToADOTypeMap containings

#ifndef NDEBUG

static void __check_sorted_of_g_DBTypeToADOTypeMap__()
{
 for(const TMapDBTypeToADOType **i=g_DBTypeToADOTypeMap,**_end=_END_(g_DBTypeToADOTypeMap);i!=_end;++i)
 {
  if(!(*i))
   continue;

  //check list of ADO Types
  for(const DBVARIANT::LPCPARAMINFO* param((*i)->map);(*param)!=NULL;++param)
  {
   //unique
   for(const DBVARIANT::LPCPARAMINFO* x(param+1);(*x)!=NULL;++x)
   {
    assert_msg((*param)->adType!=(*x)->adType,"dbtype="<<(*i)->wType);
   }

   assert_msg((*i)->wType==((*param)->wType&~(DBTYPE_ARRAY)),
              "dbtype="<<(*i)->wType);
  }//for param
 }//for i
}//__check_sorted_of_g_DBTypeToADOTypeMap__

STARTUP_CODE__DEBUG(__check_sorted_of_g_DBTypeToADOTypeMap__)

#endif//NDEBUG

////////////////////////////////////////////////////////////////////////////////
#undef DEF_DBTYPE_ADO_MAP
#undef MAKE_ADO_TYPE
#undef MAKE_ADO_TYPE_A

////////////////////////////////////////////////////////////////////////////////

