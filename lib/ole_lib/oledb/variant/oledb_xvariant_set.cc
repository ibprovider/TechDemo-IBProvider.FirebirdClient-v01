////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_xvariant_set_CC_
#define _oledb_xvariant_set_CC_

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//function map to set data to basic_dbvariant from memory-buffer

#ifndef NDEBUG
# define DEF_DBVARIANT_SET_DATA_FUNC(type)                                \
   {oledb_lib::oledb_typeid__##type,                                      \
    basic_dbvariant<Allocator>::set_data_##type},

# define DEF_DBVARIANT_SET_DATA_NOTHING(num)                              \
   {num,NULL},

#else
# define DEF_DBVARIANT_SET_DATA_FUNC(type)                                \
   {basic_dbvariant<Allocator>::set_data_##type},

# define DEF_DBVARIANT_SET_DATA_NOTHING(num)                              \
   {NULL},
#endif

template<class Allocator>
const typename basic_dbvariant<Allocator>::tag_set_func
 basic_dbvariant<Allocator>::sm_set_data_funcs[146]=
{
/*  0*/ DEF_DBVARIANT_SET_DATA_FUNC(EMPTY)
/*  1*/ DEF_DBVARIANT_SET_DATA_FUNC(NULL)
/*  2*/ DEF_DBVARIANT_SET_DATA_FUNC(I2)
/*  3*/ DEF_DBVARIANT_SET_DATA_FUNC(I4)
/*  4*/ DEF_DBVARIANT_SET_DATA_FUNC(R4)
/*  5*/ DEF_DBVARIANT_SET_DATA_FUNC(R8)
/*  6*/ DEF_DBVARIANT_SET_DATA_FUNC(CY)
/*  7*/ DEF_DBVARIANT_SET_DATA_FUNC(DATE)
/*  8*/ DEF_DBVARIANT_SET_DATA_FUNC(BSTR)
/*  9*/ DEF_DBVARIANT_SET_DATA_FUNC(IDISPATCH)
/* 10*/ DEF_DBVARIANT_SET_DATA_FUNC(ERROR)
/* 11*/ DEF_DBVARIANT_SET_DATA_FUNC(BOOL)
/* 12*/ DEF_DBVARIANT_SET_DATA_FUNC(VARIANT)
/* 13*/ DEF_DBVARIANT_SET_DATA_FUNC(IUNKNOWN)
/* 14*/ DEF_DBVARIANT_SET_DATA_FUNC(DECIMAL)
/* 15*/ DEF_DBVARIANT_SET_DATA_NOTHING(15)
/* 16*/ DEF_DBVARIANT_SET_DATA_FUNC(I1)
/* 17*/ DEF_DBVARIANT_SET_DATA_FUNC(UI1)
/* 18*/ DEF_DBVARIANT_SET_DATA_FUNC(UI2)
/* 19*/ DEF_DBVARIANT_SET_DATA_FUNC(UI4)
/* 20*/ DEF_DBVARIANT_SET_DATA_FUNC(I8)
/* 21*/ DEF_DBVARIANT_SET_DATA_FUNC(UI8)
/* 22*/ DEF_DBVARIANT_SET_DATA_NOTHING(22)
/* 23*/ DEF_DBVARIANT_SET_DATA_NOTHING(23)
/* 24*/ DEF_DBVARIANT_SET_DATA_NOTHING(24)
/* 25*/ DEF_DBVARIANT_SET_DATA_NOTHING(25)
/* 26*/ DEF_DBVARIANT_SET_DATA_NOTHING(26)
/* 27*/ DEF_DBVARIANT_SET_DATA_NOTHING(27)
/* 28*/ DEF_DBVARIANT_SET_DATA_NOTHING(28)
/* 29*/ DEF_DBVARIANT_SET_DATA_NOTHING(29)
/* 30*/ DEF_DBVARIANT_SET_DATA_NOTHING(30)
/* 31*/ DEF_DBVARIANT_SET_DATA_NOTHING(31)
/* 32*/ DEF_DBVARIANT_SET_DATA_NOTHING(32)
/* 33*/ DEF_DBVARIANT_SET_DATA_NOTHING(33)
/* 34*/ DEF_DBVARIANT_SET_DATA_NOTHING(34)
/* 35*/ DEF_DBVARIANT_SET_DATA_NOTHING(35)
/* 36*/ DEF_DBVARIANT_SET_DATA_NOTHING(36)
/* 37*/ DEF_DBVARIANT_SET_DATA_NOTHING(37)
/* 38*/ DEF_DBVARIANT_SET_DATA_NOTHING(38)
/* 39*/ DEF_DBVARIANT_SET_DATA_NOTHING(39)
/* 40*/ DEF_DBVARIANT_SET_DATA_NOTHING(40)
/* 41*/ DEF_DBVARIANT_SET_DATA_NOTHING(41)
/* 42*/ DEF_DBVARIANT_SET_DATA_NOTHING(42)
/* 43*/ DEF_DBVARIANT_SET_DATA_NOTHING(43)
/* 44*/ DEF_DBVARIANT_SET_DATA_NOTHING(44)
/* 45*/ DEF_DBVARIANT_SET_DATA_NOTHING(45)
/* 46*/ DEF_DBVARIANT_SET_DATA_NOTHING(46)
/* 47*/ DEF_DBVARIANT_SET_DATA_NOTHING(47)
/* 48*/ DEF_DBVARIANT_SET_DATA_NOTHING(48)
/* 49*/ DEF_DBVARIANT_SET_DATA_NOTHING(49)
/* 50*/ DEF_DBVARIANT_SET_DATA_NOTHING(50)
/* 51*/ DEF_DBVARIANT_SET_DATA_NOTHING(51)
/* 52*/ DEF_DBVARIANT_SET_DATA_NOTHING(52)
/* 53*/ DEF_DBVARIANT_SET_DATA_NOTHING(53)
/* 54*/ DEF_DBVARIANT_SET_DATA_NOTHING(54)
/* 55*/ DEF_DBVARIANT_SET_DATA_NOTHING(55)
/* 56*/ DEF_DBVARIANT_SET_DATA_NOTHING(56)
/* 57*/ DEF_DBVARIANT_SET_DATA_NOTHING(57)
/* 58*/ DEF_DBVARIANT_SET_DATA_NOTHING(58)
/* 59*/ DEF_DBVARIANT_SET_DATA_NOTHING(59)
/* 60*/ DEF_DBVARIANT_SET_DATA_NOTHING(60)
/* 61*/ DEF_DBVARIANT_SET_DATA_NOTHING(61)
/* 62*/ DEF_DBVARIANT_SET_DATA_NOTHING(62)
/* 63*/ DEF_DBVARIANT_SET_DATA_NOTHING(63)
/* 64*/ DEF_DBVARIANT_SET_DATA_FUNC(FILETIME)
/* 65*/ DEF_DBVARIANT_SET_DATA_NOTHING(65)
/* 66*/ DEF_DBVARIANT_SET_DATA_NOTHING(66)
/* 67*/ DEF_DBVARIANT_SET_DATA_NOTHING(67)
/* 68*/ DEF_DBVARIANT_SET_DATA_NOTHING(68)
/* 69*/ DEF_DBVARIANT_SET_DATA_NOTHING(69)
/* 70*/ DEF_DBVARIANT_SET_DATA_NOTHING(70)
/* 71*/ DEF_DBVARIANT_SET_DATA_NOTHING(71)
/* 72*/ DEF_DBVARIANT_SET_DATA_FUNC(GUID)
/* 73*/ DEF_DBVARIANT_SET_DATA_NOTHING(73)
/* 74*/ DEF_DBVARIANT_SET_DATA_NOTHING(74)
/* 75*/ DEF_DBVARIANT_SET_DATA_NOTHING(75)
/* 76*/ DEF_DBVARIANT_SET_DATA_NOTHING(76)
/* 77*/ DEF_DBVARIANT_SET_DATA_NOTHING(77)
/* 78*/ DEF_DBVARIANT_SET_DATA_NOTHING(78)
/* 79*/ DEF_DBVARIANT_SET_DATA_NOTHING(79)
/* 80*/ DEF_DBVARIANT_SET_DATA_NOTHING(80)
/* 81*/ DEF_DBVARIANT_SET_DATA_NOTHING(81)
/* 82*/ DEF_DBVARIANT_SET_DATA_NOTHING(82)
/* 83*/ DEF_DBVARIANT_SET_DATA_NOTHING(83)
/* 84*/ DEF_DBVARIANT_SET_DATA_NOTHING(84)
/* 85*/ DEF_DBVARIANT_SET_DATA_NOTHING(85)
/* 86*/ DEF_DBVARIANT_SET_DATA_NOTHING(86)
/* 87*/ DEF_DBVARIANT_SET_DATA_NOTHING(87)
/* 88*/ DEF_DBVARIANT_SET_DATA_NOTHING(88)
/* 89*/ DEF_DBVARIANT_SET_DATA_NOTHING(89)
/* 90*/ DEF_DBVARIANT_SET_DATA_NOTHING(90)
/* 91*/ DEF_DBVARIANT_SET_DATA_NOTHING(91)
/* 92*/ DEF_DBVARIANT_SET_DATA_NOTHING(92)
/* 93*/ DEF_DBVARIANT_SET_DATA_NOTHING(93)
/* 94*/ DEF_DBVARIANT_SET_DATA_NOTHING(94)
/* 95*/ DEF_DBVARIANT_SET_DATA_NOTHING(95)
/* 96*/ DEF_DBVARIANT_SET_DATA_NOTHING(96)
/* 97*/ DEF_DBVARIANT_SET_DATA_NOTHING(97)
/* 98*/ DEF_DBVARIANT_SET_DATA_NOTHING(98)
/* 99*/ DEF_DBVARIANT_SET_DATA_NOTHING(99)
/*100*/ DEF_DBVARIANT_SET_DATA_NOTHING(100)
/*101*/ DEF_DBVARIANT_SET_DATA_NOTHING(101)
/*102*/ DEF_DBVARIANT_SET_DATA_NOTHING(102)
/*103*/ DEF_DBVARIANT_SET_DATA_NOTHING(103)
/*104*/ DEF_DBVARIANT_SET_DATA_NOTHING(104)
/*105*/ DEF_DBVARIANT_SET_DATA_NOTHING(105)
/*106*/ DEF_DBVARIANT_SET_DATA_NOTHING(106)
/*107*/ DEF_DBVARIANT_SET_DATA_NOTHING(107)
/*108*/ DEF_DBVARIANT_SET_DATA_NOTHING(108)
/*109*/ DEF_DBVARIANT_SET_DATA_NOTHING(109)
/*110*/ DEF_DBVARIANT_SET_DATA_NOTHING(110)
/*111*/ DEF_DBVARIANT_SET_DATA_NOTHING(111)
/*112*/ DEF_DBVARIANT_SET_DATA_NOTHING(112)
/*113*/ DEF_DBVARIANT_SET_DATA_NOTHING(113)
/*114*/ DEF_DBVARIANT_SET_DATA_NOTHING(114)
/*115*/ DEF_DBVARIANT_SET_DATA_NOTHING(115)
/*116*/ DEF_DBVARIANT_SET_DATA_NOTHING(116)
/*117*/ DEF_DBVARIANT_SET_DATA_NOTHING(117)
/*118*/ DEF_DBVARIANT_SET_DATA_NOTHING(118)
/*119*/ DEF_DBVARIANT_SET_DATA_NOTHING(119)
/*120*/ DEF_DBVARIANT_SET_DATA_NOTHING(120)
/*121*/ DEF_DBVARIANT_SET_DATA_NOTHING(121)
/*122*/ DEF_DBVARIANT_SET_DATA_NOTHING(122)
/*123*/ DEF_DBVARIANT_SET_DATA_NOTHING(123)
/*124*/ DEF_DBVARIANT_SET_DATA_NOTHING(124)
/*125*/ DEF_DBVARIANT_SET_DATA_NOTHING(125)
/*126*/ DEF_DBVARIANT_SET_DATA_NOTHING(126)
/*127*/ DEF_DBVARIANT_SET_DATA_NOTHING(127)
/*128*/ DEF_DBVARIANT_SET_DATA_FUNC(BYTES)
/*129*/ DEF_DBVARIANT_SET_DATA_FUNC(STR)
/*130*/ DEF_DBVARIANT_SET_DATA_FUNC(WSTR)
/*131*/ DEF_DBVARIANT_SET_DATA_FUNC(NUMERIC)
/*132*/ DEF_DBVARIANT_SET_DATA_NOTHING(132)
/*133*/ DEF_DBVARIANT_SET_DATA_FUNC(DBDATE)
/*134*/ DEF_DBVARIANT_SET_DATA_FUNC(DBTIME)
/*135*/ DEF_DBVARIANT_SET_DATA_FUNC(DBTIMESTAMP)
/*136*/ DEF_DBVARIANT_SET_DATA_NOTHING(136)
/*137*/ DEF_DBVARIANT_SET_DATA_NOTHING(137)
/*138*/ DEF_DBVARIANT_SET_DATA_NOTHING(138)
/*139*/ DEF_DBVARIANT_SET_DATA_NOTHING(139)
/*140*/ DEF_DBVARIANT_SET_DATA_NOTHING(140)
/*141*/ DEF_DBVARIANT_SET_DATA_NOTHING(141)
/*142*/ DEF_DBVARIANT_SET_DATA_NOTHING(142)
/*143*/ DEF_DBVARIANT_SET_DATA_NOTHING(143)
/*144*/ DEF_DBVARIANT_SET_DATA_NOTHING(144)
/*145*/ DEF_DBVARIANT_SET_DATA_FUNC(DBTIME2)
};//sm_set_data_funcs

////////////////////////////////////////////////////////////////////////////////
#undef DEF_DBVARIANT_SET_DATA_FUNC
#undef DEF_DBVARIANT_SET_DATA_NOTHING

////////////////////////////////////////////////////////////////////////////////

template<typename Allocator>
typename basic_dbvariant<Allocator>::set_data_func_type
 basic_dbvariant<Allocator>::get_set_data_func(DBTYPE const wType)
{
 if(UINT(wType)<_DIM_(sm_set_data_funcs))
 {
  //in debug version each element has own ID (wType)
  assert(sm_set_data_funcs[wType].wType==wType);

  return sm_set_data_funcs[wType].func;
 }//if

 return NULL;
}//get_set_data_func

////////////////////////////////////////////////////////////////////////////////
//Utility assign data to dbvariant from memory-buffer

//! \todo Изничтожить этот макрос
#define EXTRACT_DBTYPE(bind) (DBTYPE(bind.wType&(~DBTYPE_BYREF)))

#define DEFINE_DBVARIANT_SET_DATA_FUNC(dbtype,type,member)                     \
template<class Allocator>                                                      \
typename basic_dbvariant<Allocator>::status_type                               \
 basic_dbvariant<Allocator>::set_data_##dbtype                                 \
                             (dbvariant_type&     x,                           \
                              const DBBINDING&    DEBUG_CODE(bind),            \
                              length_type   const /*Length*/,                  \
                              void*         const pValue,                      \
                              setdata_flags const /*SetDataFlags*/)            \
{                                                                              \
 const DBTYPE c_value_typeid=oledb_lib::oledb_typeid__##dbtype;                \
                                                                               \
 assert(EXTRACT_DBTYPE(bind)==c_value_typeid);                                 \
                                                                               \
 if(pValue==NULL)                                                              \
 {                                                                             \
  x.Clear();                                                                   \
 }                                                                             \
 else                                                                          \
 {                                                                             \
  const type _copy(*reinterpret_cast<const type*>(pValue));                    \
                                                                               \
  x.Clear();                                                                   \
                                                                               \
  x.member=_copy;                                                              \
 }                                                                             \
                                                                               \
 x.wType=c_value_typeid;                                                       \
                                                                               \
 return DBSTATUS_S_OK;                                                         \
}

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_EMPTY
                                 (dbvariant_type&     x,
                                  const DBBINDING&    DEBUG_CODE(bind),
                                  length_type   const /*Length*/,
                                  void*         const /*pValue*/,
                                  setdata_flags const /*SetDataFlags*/)
{
 assert(EXTRACT_DBTYPE(bind)==DBTYPE_EMPTY);

 x.Clear();

 return DBSTATUS_S_OK;
}//set_data_EMPTY

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_NULL
                                 (dbvariant_type&     x,
                                  const DBBINDING&    DEBUG_CODE(bind),
                                  length_type   const /*Length*/,
                                  void*         const /*pValue*/,
                                  setdata_flags const /*SetDataFlags*/)
{
 assert(EXTRACT_DBTYPE(bind)==DBTYPE_NULL);

 x.SetDBNull();

 return DBSTATUS_S_OK;
}//set_data_NULL

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(I2,value_i2_type,valI2)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(I4,value_i4_type,valI4)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(R4,value_r4_type,valR4)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(R8,value_r8_type,valR8)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(CY,value_cy_type,valCY)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(DATE,value_date_type,dateVal)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(ERROR,value_scode_type,scodeVal)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(I1,value_i1_type,valI1)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(UI1,value_ui1_type,valUI1)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(UI2,value_ui2_type,valUI2)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(UI4,value_ui4_type,valUI4)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(I8,value_i8_type_s,valI8)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(UI8,value_ui8_type_s,valUI8)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(FILETIME,value_filetime_type,filetimeVal)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(DBDATE,value_dbdate_type,dbdateVal)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(DBTIME,value_dbtime_type,dbtimeVal)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(DBTIME2,value_dbtime2_type,dbtime2Val)

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_BSTR(dbvariant_type&     x,
                                           const DBBINDING&    DEBUG_CODE(bind),
                                           length_type   const /*Length*/,
                                           void*         const pValue,
                                           setdata_flags const /*SetDataFlags*/)
{
 assert(EXTRACT_DBTYPE(bind)==DBTYPE_BSTR);

 x.SetBSTR(pValue?*reinterpret_cast<const BSTR*>(pValue):NULL);

 return DBSTATUS_S_OK;
}//set_data_BSTR

//------------------------------------------------------------------------
template<class Allcator>
typename basic_dbvariant<Allcator>::status_type
 basic_dbvariant<Allcator>::set_data_IDISPATCH
                                           (dbvariant_type&     x,
                                            const DBBINDING&    DEBUG_CODE(bind),
                                            length_type   const /*Length*/,
                                            void*         const pValue,
                                            setdata_flags const /*SetDataFlags*/)
{
 assert(EXTRACT_DBTYPE(bind)==DBTYPE_IDISPATCH);

 //----
 ole_lib::IDispatchPtr spDisp(pValue?*reinterpret_cast<IDispatch* const*>(pValue):NULL);

 //----
 x.Clear();

 //----
 assert(x.dispVal.ptr==NULL);

 spDisp.MoveTo_Fast(&x.dispVal.ptr);

 assert(!spDisp);

 x.wType=DBTYPE_IDISPATCH;

 //----
 return DBSTATUS_S_OK;
}//set_data_IDISPATCH

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_BOOL(dbvariant_type&     x,
                                           const DBBINDING&    DEBUG_CODE(bind),
                                           length_type   const /*Length*/,
                                           void*         const pValue,
                                           setdata_flags const /*SetDataFlags*/)
{
 assert(EXTRACT_DBTYPE(bind)==DBTYPE_BOOL);

 //----
 VARIANT_BOOL _copy;

 if(pValue==NULL)
  _copy=VARIANT_FALSE;
 else
 if((*reinterpret_cast<const VARIANT_BOOL*>(pValue))==VARIANT_FALSE)
  _copy=VARIANT_FALSE;
 else
  _copy=VARIANT_TRUE;

 //----
 x.Clear();

 //----
 x.boolVal=_copy;

 x.wType=DBTYPE_BOOL;

 //----
 return DBSTATUS_S_OK;
}//set_data_BOOL

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_VARIANT
                                           (dbvariant_type&     x,
                                            const DBBINDING&    DEBUG_CODE(bind),
                                            length_type   const /*Length*/,
                                            void*         const pValue,
                                            setdata_flags const /*SetDataFlags*/)
{
 assert(EXTRACT_DBTYPE(bind)==DBTYPE_VARIANT);

 x.SetVariant(reinterpret_cast<const VARIANT*>(pValue),/*upack=*/true);

 return DBSTATUS_S_OK;
}//set_data_VARIANT

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_IUNKNOWN
                                           (dbvariant_type&     x,
                                            const DBBINDING&    bind,
                                            length_type   const /*Length*/,
                                            void*         const pValue,
                                            setdata_flags const SetDataFlags)
{
 assert(EXTRACT_DBTYPE(bind)==DBTYPE_IUNKNOWN);

 //-----------------------------------------
 ole_lib::IUnknownPtr spCopyUnk;

 if(pValue!=NULL)
 {
  IUnknown* &rpSourceUnk=(*reinterpret_cast<IUnknown**>(pValue));

  if((SetDataFlags&dbvariant_type::setdata_addref__unk)!=0)
  {
   //call AddRef for NOT NULL pointer

   ole_lib::CopyComInterface2(rpSourceUnk,/*dest*/spCopyUnk.ref_ptr());
  }
  else
  {
   //This is enabled for OLEDB Provider code only!
   assert(SetDataFlags&self_type::setdata_isprovider);

   //source pointer will be reset to NULL
   //
   //[2016-01-26]
   // Обнуление указателя приводит к проблемам c MSSQL.
   //  - Перестает работать запрос insert <blob> from select <blob>
   //    для нескольких рядов. MSSQL многократно передаем один и тот же буфер
   //    с указателем на StorageObject. Во втором и далее случае получается
   //    что к нам приезжает (наш) нулевой указатель.
   //
   //    Так что, фанатизм с обнулением источника прийдется откатить.
   //
   //ole_lib::MoveComInterface2(rpSourceUnk,/*dest*/spCopyUnk.ref_ptr());
   //
   //assert(rpSourceUnk==NULL);

   spCopyUnk.ref_ptr()=rpSourceUnk;
  }//else
 }//if pValue!=NULL

 //----
 const IID CopyIID=((bind.pObject==NULL)?IID_IUnknown:bind.pObject->iid);

 //-----------------------------------------
 x.Clear(); //throw?

 //----
 spCopyUnk.MoveTo_Fast(&x.unkVal.ptr);

 x.wType=DBTYPE_IUNKNOWN;

 x.unkVal.iid=CopyIID;

 //----
 return DBSTATUS_S_OK;
}//set_data_IUNKNOWN

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(GUID,value_guid_type,guidVal)

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_BYTES(dbvariant_type&     x,
                                            const DBBINDING&    DEBUG_CODE(bind),
                                            length_type   const Length,
                                            void*         const pValue,
                                            setdata_flags const /*SetDataFlags*/)
{
 assert(EXTRACT_DBTYPE(bind)==DBTYPE_BYTES);

 x.SetBytes(pValue,Length);

 return DBSTATUS_S_OK;
}//set_data_BYTES

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_STR(dbvariant_type&     x,
                                          const DBBINDING&    bind,
                                          length_type   const Length,
                                          void*         const pValue,
                                          setdata_flags const /*SetDataFlags*/)
{
 assert(EXTRACT_DBTYPE(bind)==DBTYPE_STR);

 typedef char                  char_type;
 typedef const char_type*      str_type;

 //если длина не указана, то строка ограничена нулевым символом
 length_type cchValue DEBUG_CODE(=structure::negative_one);

 if(OLEDB_LENGTH_IS_BOUND(bind))
 {
  assert_s(sizeof(char_type)==1);

  assert((Length%sizeof(char_type))==0);

  cchValue=Length/sizeof(char_type);

  if(cchValue!=0 && pValue==nullptr)
   return DBSTATUS_E_BADACCESSOR;
 }
 else
 if(pValue==nullptr)
 {
  cchValue=0;
 }
 else
 if(bind.wType&DBTYPE_BYREF)
 {
  assert_hint(pValue!=nullptr);

  //нам передали указатель на строку, поэтому никакого контроля
  cchValue=strlen(reinterpret_cast<str_type>(pValue));
 }
 else
 {
  assert_hint(pValue!=nullptr);

  //строка передана непосредственно в буфере обмена.
  //поскольку длина не указана, её нужно определить самостоятельно с учетом cbMaxLen.

  assert_s(sizeof(length_type)==sizeof(size_t));
  assert(structure::t_numeric_limits<length_type>::min_value()==0);

  const size_t cchMax
   =(bind.cbMaxLen/sizeof(char_type));

  const str_type pEnd
   =std::find
     (reinterpret_cast<str_type>(pValue),
      reinterpret_cast<str_type>(pValue)+cchMax,
      '\0');

  cchValue
   =static_cast<length_type>(pEnd-reinterpret_cast<str_type>(pValue));
 }//else

 CHECK_READ_TYPED_PTR(reinterpret_cast<str_type>(pValue),cchValue);

 x.SetStr(structure::make_str_box(reinterpret_cast<str_type>(pValue),cchValue));

 assert(x.wType==DBTYPE_STR);
 assert(x.TestDataStatus__IsOK());

 return DBSTATUS_S_OK;
}//set_data_STR

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_WSTR(dbvariant_type&     x,
                                           const DBBINDING&    bind,
                                           length_type   const Length,
                                           void*         const pValue,
                                           setdata_flags const /*SetDataFlags*/)
{
 assert(EXTRACT_DBTYPE(bind)==DBTYPE_WSTR);

 typedef wchar_t              char_type;
 typedef const char_type*     str_type;

 //если длина не указана, то строка ограничена нулевым символом
 length_type cchValue DEBUG_CODE(=structure::negative_one);

 if(OLEDB_LENGTH_IS_BOUND(bind))
 {
  if((Length%sizeof(char_type))!=0)
   return DBSTATUS_E_BADACCESSOR;

  //нам явно передали длину строки
  cchValue=Length/sizeof(char_type);

  if(cchValue!=0 && pValue==nullptr)
   return DBSTATUS_E_BADACCESSOR;
 }
 else
 if(pValue==nullptr)
 {
  cchValue=0;
 }
 else
 if(bind.wType&DBTYPE_BYREF)
 {
  assert_hint(pValue!=nullptr);

  //если нам передали указатель на строку, то никакого контроля максимальной длины
  cchValue=wcslen(reinterpret_cast<str_type>(pValue));
 }
 else
 {
  assert_hint(pValue!=nullptr);

  //строка передана непосредственно в буфере обмена.
  //поскольку длина не указана, её нужно определить самостоятельно с учетом cbMaxLen.

  assert_s(sizeof(length_type)==sizeof(size_t));
  assert(structure::t_numeric_limits<length_type>::min_value()==0);

  const size_t cchMax
   =(bind.cbMaxLen/sizeof(char_type));

  const str_type pEnd
   =std::find
     (reinterpret_cast<str_type>(pValue),
      reinterpret_cast<str_type>(pValue)+cchMax,
      L'\0');

  cchValue
   =static_cast<length_type>(pEnd-reinterpret_cast<str_type>(pValue));
 }//else

 CHECK_READ_TYPED_PTR(reinterpret_cast<str_type>(pValue),cchValue);

 x.SetWStr(structure::make_str_box(reinterpret_cast<str_type>(pValue),cchValue));

 assert(x.wType==DBTYPE_WSTR);
 assert(x.TestDataStatus__IsOK());

 return DBSTATUS_S_OK;
}//set_data_WSTR

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(NUMERIC,value_numeric_type,dbnumVal)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(DECIMAL,value_decimal_type,decVal)

//------------------------------------------------------------------------
DEFINE_DBVARIANT_SET_DATA_FUNC(DBTIMESTAMP,value_dbstamp_type,dbstampVal)

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_ARRAY(dbvariant_type&     x,
                                            const DBBINDING&    bind,
                                            length_type   const /*Length*/,
                                            void*         const pValue,
                                            setdata_flags const /*SetDataFlags*/)
{
 const DBTYPE wSourceType=EXTRACT_DBTYPE(bind);

 assert_msg(wSourceType&DBTYPE_ARRAY,"wSourceType=0x"<<std::hex<<wSourceType);

 IID ElementIID;

 if(OLEDB_EXTRACT_SIMPLE_DBTYPE(wSourceType)!=DBTYPE_IUNKNOWN)
  ElementIID=IID_NULL;
 else
 if(bind.pObject!=NULL)
  ElementIID=bind.pObject->iid;
 else
  ElementIID=IID_IUnknown;

 const HRESULT
  hr=x.SetArray_HR(DBTYPE(wSourceType&~DBTYPE_ARRAY),
                   ElementIID,
                   pValue?*reinterpret_cast<const SAFEARRAY* const*>(pValue):NULL);

 return oledb_lib::MapDBErrorToDBStatus(hr,DBSTATUS_E_CANTCONVERTVALUE);
}//set_data_ARRAY

//------------------------------------------------------------------------
template<class Allocator>
typename basic_dbvariant<Allocator>::status_type
 basic_dbvariant<Allocator>::set_data_BADACCESSOR
                                           (dbvariant_type&     /*x*/,
                                            const DBBINDING&    /*bind*/,
                                            length_type   const /*Length*/,
                                            void*         const /*pValue*/,
                                            setdata_flags const /*SetDataFlags*/)
{
 return DBSTATUS_E_BADACCESSOR;
}//set_data_BADACCESSOR

////////////////////////////////////////////////////////////////////////////////
#undef DEFINE_DBVARIANT_SET_DATA_FUNC
#undef EXTRACT_DBTYPE

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
