////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_xvariant_copy_CC_
#define _oledb_xvariant_copy_CC_

#include <structure/t_str_formatter.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

#define DEF_DBVARIANT_COPY_FUNC(type) \
 {copy_##type},

#define DEF_DBVARIANT_COPY_NOTHING(num) \
 {NULL},

////////////////////////////////////////////////////////////////////////////////
//Map of OLEDB types transformations

template<class Allocator>
const typename basic_dbvariant<Allocator>::copy_func_type
 basic_dbvariant<Allocator>::sm_copy_funcs[146]=
{
/*  0*/ DEF_DBVARIANT_COPY_FUNC(EMPTY)
/*  1*/ DEF_DBVARIANT_COPY_FUNC(NULL)
/*  2*/ DEF_DBVARIANT_COPY_FUNC(I2)
/*  3*/ DEF_DBVARIANT_COPY_FUNC(I4)
/*  4*/ DEF_DBVARIANT_COPY_FUNC(R4)
/*  5*/ DEF_DBVARIANT_COPY_FUNC(R8)
/*  6*/ DEF_DBVARIANT_COPY_FUNC(CY)
/*  7*/ DEF_DBVARIANT_COPY_FUNC(DATE)
/*  8*/ DEF_DBVARIANT_COPY_FUNC(BSTR)
/*  9*/ DEF_DBVARIANT_COPY_FUNC(IDISPATCH)
/* 10*/ DEF_DBVARIANT_COPY_FUNC(ERROR)
/* 11*/ DEF_DBVARIANT_COPY_FUNC(BOOL)
/* 12*/ DEF_DBVARIANT_COPY_FUNC(VARIANT)
/* 13*/ DEF_DBVARIANT_COPY_FUNC(IUNKNOWN)
/* 14*/ DEF_DBVARIANT_COPY_FUNC(DECIMAL)
/* 15*/ DEF_DBVARIANT_COPY_NOTHING(15)
/* 16*/ DEF_DBVARIANT_COPY_FUNC(I1)
/* 17*/ DEF_DBVARIANT_COPY_FUNC(UI1)
/* 18*/ DEF_DBVARIANT_COPY_FUNC(UI2)
/* 19*/ DEF_DBVARIANT_COPY_FUNC(UI4)
/* 20*/ DEF_DBVARIANT_COPY_FUNC(I8)
/* 21*/ DEF_DBVARIANT_COPY_FUNC(UI8)
/* 22*/ DEF_DBVARIANT_COPY_NOTHING(22)
/* 23*/ DEF_DBVARIANT_COPY_NOTHING(23)
/* 24*/ DEF_DBVARIANT_COPY_NOTHING(24)
/* 25*/ DEF_DBVARIANT_COPY_NOTHING(25)
/* 26*/ DEF_DBVARIANT_COPY_NOTHING(26)
/* 27*/ DEF_DBVARIANT_COPY_NOTHING(27)
/* 28*/ DEF_DBVARIANT_COPY_NOTHING(28)
/* 29*/ DEF_DBVARIANT_COPY_NOTHING(29)
/* 30*/ DEF_DBVARIANT_COPY_NOTHING(30)
/* 31*/ DEF_DBVARIANT_COPY_NOTHING(31)
/* 32*/ DEF_DBVARIANT_COPY_NOTHING(32)
/* 33*/ DEF_DBVARIANT_COPY_NOTHING(33)
/* 34*/ DEF_DBVARIANT_COPY_NOTHING(34)
/* 35*/ DEF_DBVARIANT_COPY_NOTHING(35)
/* 36*/ DEF_DBVARIANT_COPY_NOTHING(36)
/* 37*/ DEF_DBVARIANT_COPY_NOTHING(37)
/* 38*/ DEF_DBVARIANT_COPY_NOTHING(38)
/* 39*/ DEF_DBVARIANT_COPY_NOTHING(39)
/* 40*/ DEF_DBVARIANT_COPY_NOTHING(40)
/* 41*/ DEF_DBVARIANT_COPY_NOTHING(41)
/* 42*/ DEF_DBVARIANT_COPY_NOTHING(42)
/* 43*/ DEF_DBVARIANT_COPY_NOTHING(43)
/* 44*/ DEF_DBVARIANT_COPY_NOTHING(44)
/* 45*/ DEF_DBVARIANT_COPY_NOTHING(45)
/* 46*/ DEF_DBVARIANT_COPY_NOTHING(46)
/* 47*/ DEF_DBVARIANT_COPY_NOTHING(47)
/* 48*/ DEF_DBVARIANT_COPY_NOTHING(48)
/* 49*/ DEF_DBVARIANT_COPY_NOTHING(49)
/* 50*/ DEF_DBVARIANT_COPY_NOTHING(50)
/* 51*/ DEF_DBVARIANT_COPY_NOTHING(51)
/* 52*/ DEF_DBVARIANT_COPY_NOTHING(52)
/* 53*/ DEF_DBVARIANT_COPY_NOTHING(53)
/* 54*/ DEF_DBVARIANT_COPY_NOTHING(54)
/* 55*/ DEF_DBVARIANT_COPY_NOTHING(55)
/* 56*/ DEF_DBVARIANT_COPY_NOTHING(56)
/* 57*/ DEF_DBVARIANT_COPY_NOTHING(57)
/* 58*/ DEF_DBVARIANT_COPY_NOTHING(58)
/* 59*/ DEF_DBVARIANT_COPY_NOTHING(59)
/* 60*/ DEF_DBVARIANT_COPY_NOTHING(60)
/* 61*/ DEF_DBVARIANT_COPY_NOTHING(61)
/* 62*/ DEF_DBVARIANT_COPY_NOTHING(62)
/* 63*/ DEF_DBVARIANT_COPY_NOTHING(63)
/* 64*/ DEF_DBVARIANT_COPY_FUNC(FILETIME)
/* 65*/ DEF_DBVARIANT_COPY_NOTHING(65)
/* 66*/ DEF_DBVARIANT_COPY_NOTHING(66)
/* 67*/ DEF_DBVARIANT_COPY_NOTHING(67)
/* 68*/ DEF_DBVARIANT_COPY_NOTHING(68)
/* 69*/ DEF_DBVARIANT_COPY_NOTHING(69)
/* 70*/ DEF_DBVARIANT_COPY_NOTHING(70)
/* 71*/ DEF_DBVARIANT_COPY_NOTHING(71)
/* 72*/ DEF_DBVARIANT_COPY_FUNC(GUID)
/* 73*/ DEF_DBVARIANT_COPY_NOTHING(73)
/* 74*/ DEF_DBVARIANT_COPY_NOTHING(74)
/* 75*/ DEF_DBVARIANT_COPY_NOTHING(75)
/* 76*/ DEF_DBVARIANT_COPY_NOTHING(76)
/* 77*/ DEF_DBVARIANT_COPY_NOTHING(77)
/* 78*/ DEF_DBVARIANT_COPY_NOTHING(78)
/* 79*/ DEF_DBVARIANT_COPY_NOTHING(79)
/* 80*/ DEF_DBVARIANT_COPY_NOTHING(80)
/* 81*/ DEF_DBVARIANT_COPY_NOTHING(81)
/* 82*/ DEF_DBVARIANT_COPY_NOTHING(82)
/* 83*/ DEF_DBVARIANT_COPY_NOTHING(83)
/* 84*/ DEF_DBVARIANT_COPY_NOTHING(84)
/* 85*/ DEF_DBVARIANT_COPY_NOTHING(85)
/* 86*/ DEF_DBVARIANT_COPY_NOTHING(86)
/* 87*/ DEF_DBVARIANT_COPY_NOTHING(87)
/* 88*/ DEF_DBVARIANT_COPY_NOTHING(88)
/* 89*/ DEF_DBVARIANT_COPY_NOTHING(89)
/* 90*/ DEF_DBVARIANT_COPY_NOTHING(90)
/* 91*/ DEF_DBVARIANT_COPY_NOTHING(91)
/* 92*/ DEF_DBVARIANT_COPY_NOTHING(92)
/* 93*/ DEF_DBVARIANT_COPY_NOTHING(93)
/* 94*/ DEF_DBVARIANT_COPY_NOTHING(94)
/* 95*/ DEF_DBVARIANT_COPY_NOTHING(95)
/* 96*/ DEF_DBVARIANT_COPY_NOTHING(96)
/* 97*/ DEF_DBVARIANT_COPY_NOTHING(97)
/* 98*/ DEF_DBVARIANT_COPY_NOTHING(98)
/* 99*/ DEF_DBVARIANT_COPY_NOTHING(99)
/*100*/ DEF_DBVARIANT_COPY_NOTHING(100)
/*101*/ DEF_DBVARIANT_COPY_NOTHING(101)
/*102*/ DEF_DBVARIANT_COPY_NOTHING(102)
/*103*/ DEF_DBVARIANT_COPY_NOTHING(103)
/*104*/ DEF_DBVARIANT_COPY_NOTHING(104)
/*105*/ DEF_DBVARIANT_COPY_NOTHING(105)
/*106*/ DEF_DBVARIANT_COPY_NOTHING(106)
/*107*/ DEF_DBVARIANT_COPY_NOTHING(107)
/*108*/ DEF_DBVARIANT_COPY_NOTHING(108)
/*109*/ DEF_DBVARIANT_COPY_NOTHING(109)
/*110*/ DEF_DBVARIANT_COPY_NOTHING(110)
/*111*/ DEF_DBVARIANT_COPY_NOTHING(111)
/*112*/ DEF_DBVARIANT_COPY_NOTHING(112)
/*113*/ DEF_DBVARIANT_COPY_NOTHING(113)
/*114*/ DEF_DBVARIANT_COPY_NOTHING(114)
/*115*/ DEF_DBVARIANT_COPY_NOTHING(115)
/*116*/ DEF_DBVARIANT_COPY_NOTHING(116)
/*117*/ DEF_DBVARIANT_COPY_NOTHING(117)
/*118*/ DEF_DBVARIANT_COPY_NOTHING(118)
/*119*/ DEF_DBVARIANT_COPY_NOTHING(119)
/*120*/ DEF_DBVARIANT_COPY_NOTHING(120)
/*121*/ DEF_DBVARIANT_COPY_NOTHING(121)
/*122*/ DEF_DBVARIANT_COPY_NOTHING(122)
/*123*/ DEF_DBVARIANT_COPY_NOTHING(123)
/*124*/ DEF_DBVARIANT_COPY_NOTHING(124)
/*125*/ DEF_DBVARIANT_COPY_NOTHING(125)
/*126*/ DEF_DBVARIANT_COPY_NOTHING(126)
/*127*/ DEF_DBVARIANT_COPY_NOTHING(127)
/*128*/ DEF_DBVARIANT_COPY_FUNC(BYTES)
/*129*/ DEF_DBVARIANT_COPY_FUNC(STR)
/*130*/ DEF_DBVARIANT_COPY_FUNC(WSTR)
/*131*/ DEF_DBVARIANT_COPY_FUNC(NUMERIC)
/*132*/ DEF_DBVARIANT_COPY_NOTHING(132)
/*133*/ DEF_DBVARIANT_COPY_FUNC(DBDATE)
/*134*/ DEF_DBVARIANT_COPY_FUNC(DBTIME)
/*135*/ DEF_DBVARIANT_COPY_FUNC(DBTIMESTAMP)
/*136*/ DEF_DBVARIANT_COPY_NOTHING(136)
/*137*/ DEF_DBVARIANT_COPY_NOTHING(137)
/*138*/ DEF_DBVARIANT_COPY_NOTHING(138)
/*139*/ DEF_DBVARIANT_COPY_NOTHING(139)
/*140*/ DEF_DBVARIANT_COPY_NOTHING(140)
/*141*/ DEF_DBVARIANT_COPY_NOTHING(141)
/*142*/ DEF_DBVARIANT_COPY_NOTHING(142)
/*143*/ DEF_DBVARIANT_COPY_NOTHING(143)
/*144*/ DEF_DBVARIANT_COPY_NOTHING(144)
/*145*/ DEF_DBVARIANT_COPY_FUNC(DBTIME2)
};//sm_copy_funcs

////////////////////////////////////////////////////////////////////////////////
#undef DEF_DBVARIANT_COPY_FUNC
#undef DEF_DBVARIANT_COPY_NOTHING

////////////////////////////////////////////////////////////////////////////////
//struct basic_dbvariant_copy_utils

template<class Allocator>
void basic_dbvariant<Allocator>::copy_EMPTY(dbvariant_type&  dest,
                                            const DBVARIANT& DEBUG_CODE(source))
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_EMPTY,"wType==0x"<<std::hex<<source.wType);

 dest.Clear();

 assert(dest.wType==DBTYPE_EMPTY);
 assert(dest.TestDataStatus__IsOK());
}//copy_EMPTY

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_NULL(dbvariant_type&  dest,
                                           const DBVARIANT& DEBUG_CODE(source))
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_NULL,"wType==0x"<<std::hex<<source.wType);

 dest.SetDBNull();

 assert(dest.wType==DBTYPE_NULL);
 assert(dest.TestDataStatus__IsOK());
}//copy_NULL

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_I1(dbvariant_type&  dest,
                                         const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_I1,"wType==0x"<<std::hex<<source.wType);

 dest=source.valI1;

 assert(dest.wType==DBTYPE_I1);
 assert(dest.TestDataStatus__IsOK());
}//copy_I1

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_I2(dbvariant_type&  dest,
                                         const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_I2,"wType==0x"<<std::hex<<source.wType);

 dest=source.valI2;

 assert(dest.wType==DBTYPE_I2);
 assert(dest.TestDataStatus__IsOK());
}//copy_I2

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_I4(dbvariant_type&  dest,
                                         const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_I4,"wType==0x"<<std::hex<<source.wType);

 dest=source.valI4;

 assert(dest.wType==DBTYPE_I4);
 assert(dest.TestDataStatus__IsOK());
}//copy_I4

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_I8(dbvariant_type&  dest,
                                         const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_I8,"wType==0x"<<std::hex<<source.wType);

 dest=source.valI8;

 assert(dest.wType==DBTYPE_I8);
 assert(dest.TestDataStatus__IsOK());
}//copy_I8

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_UI1(dbvariant_type&  dest,
                                          const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_UI1,"wType==0x"<<std::hex<<source.wType);

 dest=source.valUI1;

 assert(dest.wType==DBTYPE_UI1);
 assert(dest.TestDataStatus__IsOK());
}//copy_UI1

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_UI2(dbvariant_type&  dest,
                                          const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_UI2,"wType==0x"<<std::hex<<source.wType);

 dest=source.valUI2;

 assert(dest.wType==DBTYPE_UI2);
 assert(dest.TestDataStatus__IsOK());
}//copy_UI2

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_UI4(dbvariant_type&  dest,
                                          const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_UI4,"wType==0x"<<std::hex<<source.wType);

 dest=source.valUI4;

 assert(dest.wType==DBTYPE_UI4);
 assert(dest.TestDataStatus__IsOK());
}//copy_UI4

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_UI8(dbvariant_type&  dest,
                                          const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_UI8,"wType==0x"<<std::hex<<source.wType);

 dest=source.valUI8;

 assert(dest.wType==DBTYPE_UI8);
 assert(dest.TestDataStatus__IsOK());
}//copy_UI8

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_R4(dbvariant_type&  dest,
                                         const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_R4,"wType==0x"<<std::hex<<source.wType);

 dest=source.valR4;

 assert(dest.wType==DBTYPE_R4);
 assert(dest.TestDataStatus__IsOK());
}//copy_R4

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_R8(dbvariant_type&  dest,
                                         const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_R8,"wType==0x"<<std::hex<<source.wType);

 dest=source.valR8;

 assert(dest.wType==DBTYPE_R8);
 assert(dest.TestDataStatus__IsOK());
}//copy_R8

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_CY(dbvariant_type&  dest,
                                         const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_CY,"wType==0x"<<std::hex<<source.wType);

 dest.SetCY(source.valCY);

 assert(dest.wType==DBTYPE_CY);
 assert(dest.TestDataStatus__IsOK());
}//copy_CY

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_DECIMAL(dbvariant_type&  dest,
                                              const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_DECIMAL,"wType==0x"<<std::hex<<source.wType);

 dest=source.decVal;

 assert(dest.wType==DBTYPE_DECIMAL);
 assert(dest.TestDataStatus__IsOK());
}//copy_DECIMAL

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_NUMERIC(dbvariant_type&  dest,
                                              const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_NUMERIC,"wType==0x"<<std::hex<<source.wType);

 dest=source.dbnumVal;

 assert(dest.wType==DBTYPE_NUMERIC);
 assert(dest.TestDataStatus__IsOK());
}//copy_NUMERIC

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_DATE(dbvariant_type&  dest,
                                           const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_DATE,"wType==0x"<<std::hex<<source.wType);

 dest.SetDate(source.dateVal);

 assert(dest.wType==DBTYPE_DATE);
 assert(dest.TestDataStatus__IsOK());
}//copy_DATE

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_FILETIME(dbvariant_type&  dest,
                                               const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_FILETIME,"wType==0x"<<std::hex<<source.wType);

 dest=source.filetimeVal;

 assert(dest.wType==DBTYPE_FILETIME);
 assert(dest.TestDataStatus__IsOK());
}//copy_FILETIME

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_DBDATE(dbvariant_type&  dest,
                                               const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_DBDATE,"wType==0x"<<std::hex<<source.wType);

 dest=source.dbdateVal;

 assert(dest.wType==DBTYPE_DBDATE);
 assert(dest.TestDataStatus__IsOK());
}//copy_DBDATE

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_DBTIME(dbvariant_type&  dest,
                                             const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_DBTIME,"wType==0x"<<std::hex<<source.wType);

 dest=source.dbtimeVal;

 assert(dest.wType==DBTYPE_DBTIME);
 assert(dest.TestDataStatus__IsOK());
}//copy_DBTIME

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_DBTIME2(dbvariant_type&  dest,
                                              const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==oledb_typeid__DBTIME2,"wType==0x"<<std::hex<<source.wType);

 dest=source.dbtime2Val;

 assert(dest.wType==oledb_typeid__DBTIME2);
 assert(dest.TestDataStatus__IsOK());
}//copy_DBTIME2

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_DBTIMESTAMP(dbvariant_type&  dest,
                                                  const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_DBTIMESTAMP,"wType==0x"<<std::hex<<source.wType);

 dest=source.dbstampVal;

 assert(dest.wType==DBTYPE_DBTIMESTAMP);
 assert(dest.TestDataStatus__IsOK());
}//copy_DBTIMESTAMP

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_GUID(dbvariant_type&  dest,
                                           const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_GUID,"wType==0x"<<std::hex<<source.wType);

 dest=source.guidVal;

 assert(dest.wType==DBTYPE_GUID);
 assert(dest.TestDataStatus__IsOK());
}//copy_GUID

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_BOOL(dbvariant_type&  dest,
                                           const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_BOOL,"wType==0x"<<std::hex<<source.wType);

 assert(source.boolVal==VARIANT_TRUE || source.boolVal==VARIANT_FALSE);

 dest=(source.boolVal!=VARIANT_FALSE);

 assert(dest.wType==DBTYPE_BOOL);
 assert(dest.TestDataStatus__IsOK());
}//copy_BOOL

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_ERROR(dbvariant_type&  dest,
                                            const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_ERROR,"wType==0x"<<std::hex<<source.wType);

 dest.SetError(source.scodeVal);

 assert(dest.wType==DBTYPE_ERROR);
 assert(dest.TestDataStatus__IsOK());
}//copy_ERROR

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_BSTR(dbvariant_type&  dest,
                                           const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_BSTR,"wType==0x"<<std::hex<<source.wType);

 dest.SetBSTR(source.bstrVal);

 assert(dest.wType==DBTYPE_BSTR);
 assert(dest.TestDataStatus__IsOK());
}//copy_BSTR

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_VARIANT(dbvariant_type&  dest,
                                              const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_VARIANT,"wType==0x"<<std::hex<<source.wType);

 /*at copying needed to save structure of data*/
 dest.SetVariant(&source.varVal,/*unpack=*/false);

 assert(dest.wType==DBTYPE_VARIANT);
 assert(dest.TestDataStatus__IsOK());
}//copy_VARIANT

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_IDISPATCH(dbvariant_type&  dest,
                                                const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_IDISPATCH,"wType==0x"<<std::hex<<source.wType);

 dest.SetDispatch(source.dispVal.ptr);

 assert(dest.wType==DBTYPE_IDISPATCH);
 assert(dest.TestDataStatus__IsOK());
}//copy_IDISPATCH

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_IUNKNOWN(dbvariant_type&  dest,
                                               const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK());
 assert_msg(source.wType==DBTYPE_IUNKNOWN,"wType==0x"<<std::hex<<source.wType);

 dest.SetUnknown
  (source.unkVal.ptr,
   source.unkVal.iid);

 assert(dest.wType==DBTYPE_IUNKNOWN);
 assert(dest.TestDataStatus__IsOK());
}//copy_IUNKNOWN

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_STR(dbvariant_type&  dest,
                                          const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK_or_IsTruncated());
 assert_msg(source.wType==DBTYPE_STR,"wType==0x"<<std::hex<<source.wType);

 dest.SetStr(structure::make_str_box(source.strVal.ptr,source.strVal.len));

 assert(dest.wType==DBTYPE_STR);
 assert(dest.TestDataStatus__IsOK());
}//copy_STR

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_WSTR(dbvariant_type&  dest,
                                           const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK_or_IsTruncated());
 assert_msg(source.wType==DBTYPE_WSTR,"wType==0x"<<std::hex<<source.wType);

 dest.SetWStr(structure::make_str_box(source.wstrVal.ptr,source.wstrVal.len));

 assert(dest.wType==DBTYPE_WSTR);
 assert(dest.TestDataStatus__IsOK());
}//copy_WSTR

//------------------------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::copy_BYTES(dbvariant_type&  dest,
                                            const DBVARIANT& source)
{
 assert(&dest!=&source);
 assert(source.TestDataStatus__IsOK_or_IsTruncated());
 assert_msg(source.wType==DBTYPE_BYTES,"wType==0x"<<std::hex<<source.wType);

 dest.SetBytes
  (source.bytesVal.ptr,
   source.bytesVal.len);

 assert(dest.wType==DBTYPE_BYTES);
 assert(dest.TestDataStatus__IsOK());
}//copy_BYTES

////////////////////////////////////////////////////////////////////////////////
//copy operator

template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (const DBVARIANT& source)
{
 if(this==&source)
  return *this;

 DBSTATUS const dwSourceStatus=source.GetDataStatus();

 switch(dwSourceStatus)
 {
  case DBSTATUS_S_OK:
  case DBSTATUS_S_TRUNCATED:
   break;

  default:
  {
   const DBTYPE wSourceType=source.wType;

   IID SourceIID(IID_NULL);

   DEBUG_CODE(bool get_iid_result=)source.GetIID(&SourceIID);

   //------
   this->Clear();

   this->SetDataStatus(dwSourceStatus);

   this->wType=wSourceType;

   _VERIFY_EQ(this->SetIID(SourceIID),get_iid_result);

   return *this;
  }//default
 }//switch

 if(source.wType&DBTYPE_ARRAY)
 {
  this->SetArray
   (DBTYPE(source.wType&~DBTYPE_ARRAY),
    source.arrayVal2.element_iid,
    source.arrayVal2.ptr);//throw
 }//if
 else
 {
  assert((source.wType&DBTYPE_ARRAY)==0);

  //copy simple data
  assert(size_t(source.wType)<_DIM_(self_type::sm_copy_funcs));
  assert(self_type::sm_copy_funcs[source.wType]!=NULL);

  if(size_t(source.wType)<_DIM_(self_type::sm_copy_funcs) &&
     self_type::sm_copy_funcs[source.wType]!=NULL)
  {
   self_type::sm_copy_funcs[source.wType](*this,source);
  }
  else
  {
   structure::str_formatter
    fmsg("[basic_dbvariant::copy operator] Unknown source type: %1");

   fmsg<<static_cast<ULONG>(source.wType);

   ole_lib::t_base_ole_error::throw_error(E_FAIL,fmsg.str());
  }//else
 }//else

 assert(this->TestDataStatus__IsOK());

 this->SetDataStatus(dwSourceStatus);

 assert(this->GetDataStatus()==dwSourceStatus);

 assert(this->TestDataStatus__IsOK_or_IsTruncated());

 return *this;
}//operator =

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (const self_type& data)
{
 return (*this)=(*static_cast<const DBVARIANT*>(&data));
}//operator =

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
