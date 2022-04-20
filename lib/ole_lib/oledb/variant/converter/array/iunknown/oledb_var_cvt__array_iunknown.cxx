////////////////////////////////////////////////////////////////////////////////
//Include implementation DBTYPE_ARRAY|DBTYPE_IUNKNOWN type converters.
//                                                  Dmitry Kovalenko, 28.05.2008
////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/oledb/variant/converter/array/iunknown/oledb_var_cvt__array_iunknown.hxx>

////////////////////////////////////////////////////////////////////////////////

static const DBVARIANT::LPCTYPECONVERTER g_converters__array_iunknown_to_simple[/*136*/]=
{
/*  0*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(0)                    //EMPTY
/*  1*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(1)                    //NULL
/*  2*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(2)                    //I2
/*  3*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(3)                    //I4
/*  4*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(4)                    //R4
/*  5*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(5)                    //R8
/*  6*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(6)                    //CY
/*  7*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(7)                    //DATE
/*  8*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(8)                    //BSTR
/*  9*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(9)                    //IDISPATCH
/* 10*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(10)                   //ERROR
/* 11*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(11)                   //BOOL
/* 12*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_common,variant)     //VARIANT
#if 0
/* 13*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(13)                   //IUNKNOWN
/* 14*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(14)                   //DECIMAL
/* 15*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(15)
/* 16*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(16)                   //I1
/* 17*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(17)                   //UI1
/* 18*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(18)                   //UI2
/* 19*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(19)                   //UI4
/* 20*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(20)                   //I8
/* 21*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(21)                   //UI8
/* 22*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(22)
/* 23*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(23)
/* 24*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(24)
/* 25*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(25)
/* 26*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(26)
/* 27*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(27)
/* 28*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(28)
/* 29*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(29)
/* 30*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(30)
/* 31*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(31)
/* 32*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(32)
/* 33*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(33)
/* 34*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(34)
/* 35*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(35)
/* 36*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(36)
/* 37*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(37)
/* 38*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(38)
/* 39*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(39)
/* 40*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(40)
/* 41*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(41)
/* 42*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(42)
/* 43*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(43)
/* 44*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(44)
/* 45*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(45)
/* 46*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(46)
/* 47*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(47)
/* 48*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(48)
/* 49*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(49)
/* 50*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(50)
/* 51*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(51)
/* 52*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(52)
/* 53*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(53)
/* 54*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(54)
/* 55*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(55)
/* 56*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(56)
/* 57*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(57)
/* 58*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(58)
/* 59*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(59)
/* 60*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(60)
/* 61*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(61)
/* 62*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(62)
/* 63*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(63)
/* 64*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(64)                   //FILETIME
/* 65*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(65)
/* 66*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(66)
/* 67*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(67)
/* 68*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(68)
/* 69*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(69)
/* 70*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(70)
/* 71*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(71)
/* 72*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(72)                   //GUID
/* 73*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(73)
/* 74*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(74)
/* 75*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(75)
/* 76*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(76)
/* 77*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(77)
/* 78*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(78)
/* 79*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(79)
/* 80*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(80)
/* 81*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(81)
/* 82*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(82)
/* 83*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(83)
/* 84*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(84)
/* 85*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(85)
/* 86*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(86)
/* 87*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(87)
/* 88*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(88)
/* 89*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(89)
/* 90*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(90)
/* 91*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(91)
/* 92*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(92)
/* 93*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(93)
/* 94*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(94)
/* 95*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(95)
/* 96*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(96)
/* 97*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(97)
/* 98*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(98)
/* 99*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(99)
/*100*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(100)
/*101*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(101)
/*102*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(102)
/*103*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(103)
/*104*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(104)
/*105*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(105)
/*106*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(106)
/*107*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(107)
/*108*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(108)
/*109*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(109)
/*110*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(110)
/*111*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(111)
/*112*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(112)
/*113*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(113)
/*114*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(114)
/*115*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(115)
/*116*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(116)
/*117*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(117)
/*118*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(118)
/*119*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(119)
/*120*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(120)
/*121*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(121)
/*122*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(122)
/*123*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(123)
/*124*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(124)
/*125*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(125)
/*126*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(126)
/*127*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(127)
/*128*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(128)                  //BYTES
/*129*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(129)                  //STR
/*130*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(130)                  //WSTR
/*131*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(131)                  //NUMERIC
/*132*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(132)                  //UDT
/*133*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(133)                  //DBDATE
/*134*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(134)                  //DBTIME
/*135*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(135)                  //DBTIMESTAMP
#endif
};//g_converters__array_iunknown_to_simple

////////////////////////////////////////////////////////////////////////////////
//TO ARRAYS

DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_i2,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__I2)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_i4,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__I4)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_r4,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__R4)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_r8,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__R8)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_cy,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__CY)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_date,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__DATE)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_bstr,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__BSTR)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_idispatch,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__IDISPATCH)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_error,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__ERROR)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_bool,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__BOOL)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_variant,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__VARIANT)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_iunknown,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_decimal,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__DECIMAL)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_i1,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__I1)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_ui1,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__UI1)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_ui2,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__UI2)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_ui4,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__UI4)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_i8,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__I8)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_ui8,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__UI8)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_filetime,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__FILETIME)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_guid,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__GUID)

//------------------------------------------------------------------------ [spec]
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_bytes,
                                            array_iunknown,
                                            array_bytes,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__BYTES)

//------------------------------------------------------------------------ [spec]
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_str,
                                            array_iunknown,
                                            array_str,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__STR)

//------------------------------------------------------------------------ [spec]
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_wstr,
                                            array_iunknown,
                                            array_wstr,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__WSTR)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_numeric,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__NUMERIC)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_dbdate,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__DBDATE)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_dbtime,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__DBTIME)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_dbtimestamp,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__DBTIMESTAMP)

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ_TO_ARRAY_V3(array_common,
                                            array_vt,
                                            array_iunknown,
                                            array_dbtime2,
                                            DBTYPE_ARRAY|oledb_typeid__IUNKNOWN,
                                            DBTYPE_ARRAY|oledb_typeid__DBTIME2)

//------------------------------------------------------------------------
static const DBVARIANT::LPCTYPECONVERTER g_converters__array_iunknown_to_array[146]=
{
/*  0*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(0)                            //EMPTY
/*  1*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(1)                            //NULL
/*  2*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_i2)          //I2
/*  3*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_i4)          //I4
/*  4*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_r4)          //R4
/*  5*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_r8)          //R8
/*  6*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_cy)          //CY
/*  7*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_date)        //DATE
/*  8*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_bstr)        //BSTR
/*  9*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_idispatch)   //IDISPATCH
/* 10*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_error)       //ERROR
/* 11*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_bool)        //BOOL
/* 12*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_variant)     //VARIANT
/* 13*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_iunknown)    //IUNKNOWN [use result_iid]
/* 14*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_decimal)     //DECIMAL
/* 15*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(15)
/* 16*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_i1)          //I1
/* 17*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_ui1)         //UI1
/* 18*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_ui2)         //UI2
/* 19*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_ui4)         //UI4
/* 20*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_i8)          //I8
/* 21*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_ui8)         //UI8
/* 22*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(22)
/* 23*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(23)
/* 24*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(24)
/* 25*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(25)
/* 26*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(26)
/* 27*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(27)
/* 28*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(28)
/* 29*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(29)
/* 30*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(30)
/* 31*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(31)
/* 32*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(32)
/* 33*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(33)
/* 34*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(34)
/* 35*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(35)
/* 36*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(36)
/* 37*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(37)
/* 38*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(38)
/* 39*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(39)
/* 40*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(40)
/* 41*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(41)
/* 42*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(42)
/* 43*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(43)
/* 44*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(44)
/* 45*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(45)
/* 46*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(46)
/* 47*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(47)
/* 48*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(48)
/* 49*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(49)
/* 50*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(50)
/* 51*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(51)
/* 52*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(52)
/* 53*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(53)
/* 54*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(54)
/* 55*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(55)
/* 56*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(56)
/* 57*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(57)
/* 58*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(58)
/* 59*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(59)
/* 60*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(60)
/* 61*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(61)
/* 62*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(62)
/* 63*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(63)
/* 64*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_filetime)    //FILETIME
/* 65*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(65)
/* 66*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(66)
/* 67*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(67)
/* 68*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(68)
/* 69*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(69)
/* 70*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(70)
/* 71*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(71)
/* 72*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_guid)        //GUID
/* 73*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(73)
/* 74*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(74)
/* 75*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(75)
/* 76*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(76)
/* 77*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(77)
/* 78*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(78)
/* 79*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(79)
/* 80*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(80)
/* 81*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(81)
/* 82*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(82)
/* 83*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(83)
/* 84*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(84)
/* 85*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(85)
/* 86*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(86)
/* 87*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(87)
/* 88*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(88)
/* 89*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(89)
/* 90*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(90)
/* 91*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(91)
/* 92*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(92)
/* 93*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(93)
/* 94*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(94)
/* 95*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(95)
/* 96*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(96)
/* 97*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(97)
/* 98*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(98)
/* 99*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(99)
/*100*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(100)
/*101*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(101)
/*102*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(102)
/*103*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(103)
/*104*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(104)
/*105*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(105)
/*106*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(106)
/*107*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(107)
/*108*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(108)
/*109*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(109)
/*110*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(110)
/*111*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(111)
/*112*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(112)
/*113*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(113)
/*114*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(114)
/*115*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(115)
/*116*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(116)
/*117*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(117)
/*118*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(118)
/*119*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(119)
/*120*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(120)
/*121*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(121)
/*122*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(122)
/*123*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(123)
/*124*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(124)
/*125*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(125)
/*126*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(126)
/*127*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(127)
/*128*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_bytes)       //BYTES [spec]
/*129*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_str)         //STR [spec]
/*130*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_wstr)        //WSTR [spec]
/*131*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_numeric)     //NUMERIC
/*132*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(132)                          //UDT
/*133*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_dbdate)      //DBDATE
/*134*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_dbtime)      //DBTIME
/*135*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_dbtimestamp) //DBTIMESTAMP
/*136*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(136)
/*137*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(137)
/*138*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(138)
/*139*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(139)
/*140*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(140)
/*141*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(141)
/*142*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(142)
/*143*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(143)
/*144*/ DEFINE_OLEDB_TYPE_CONVERTER_NOTHING(144)
/*145*/ DEFINE_OLEDB_TYPE_CONVERTER_REF(array_iunknown,array_dbtime2)     //DBTIME2
};//g_converters__array_iunknown_to_array

////////////////////////////////////////////////////////////////////////////////

DEFINE_OLEDB_TYPE_CONVERTERS_MAP_ST_AT
 (ARRAY_IUNKNOWN,
  g_converters__array_iunknown_to_simple,
  g_converters__array_iunknown_to_array)

////////////////////////////////////////////////////////////////////////////////
