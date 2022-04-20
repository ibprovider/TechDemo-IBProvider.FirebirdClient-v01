////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_xvariant_assing_as_CC_
#define _oledb_xvariant_assing_as_CC_

#include <ole_lib/oledb/variant/oledb_variant_cvt_routers.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt_context_std.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class basic_dbvariant

#define DEF_DBVARIANT_ASSIGN_AS_FUNC(type)   \
 {assign_as_##type},

#define DEF_DBVARIANT_ASSIGN_AS_NOTHING(num) \
 {NULL},

////////////////////////////////////////////////////////////////////////////////
//Map of OLEDB types transformations

template<class Allocator>
const typename basic_dbvariant<Allocator>::assign_as_func_type
 basic_dbvariant<Allocator>::sm_assign_as_funcs[146]=
{
/*  0*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(0)
/*  1*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(1)
/*  2*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(I2)
/*  3*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(I4)
/*  4*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(R4)
/*  5*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(R8)
/*  6*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(CY)
/*  7*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(DATE)
/*  8*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(BSTR)
/*  9*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(IDISPATCH)
/* 10*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(ERROR)
/* 11*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(BOOL)
/* 12*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(VARIANT)
/* 13*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(IUNKNOWN)
/* 14*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(DECIMAL)
/* 15*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(15)
/* 16*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(I1)
/* 17*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(UI1)
/* 18*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(UI2)
/* 19*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(UI4)
/* 20*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(I8)
/* 21*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(UI8)
/* 22*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(22)
/* 23*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(23)
/* 24*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(24)
/* 25*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(25)
/* 26*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(26)
/* 27*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(27)
/* 28*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(28)
/* 29*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(29)
/* 30*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(30)
/* 31*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(31)
/* 32*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(32)
/* 33*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(33)
/* 34*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(34)
/* 35*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(35)
/* 36*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(36)
/* 37*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(37)
/* 38*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(38)
/* 39*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(39)
/* 40*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(40)
/* 41*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(41)
/* 42*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(42)
/* 43*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(43)
/* 44*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(44)
/* 45*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(45)
/* 46*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(46)
/* 47*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(47)
/* 48*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(48)
/* 49*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(49)
/* 50*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(50)
/* 51*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(51)
/* 52*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(52)
/* 53*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(53)
/* 54*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(54)
/* 55*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(55)
/* 56*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(56)
/* 57*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(57)
/* 58*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(58)
/* 59*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(59)
/* 60*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(60)
/* 61*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(61)
/* 62*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(62)
/* 63*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(63)
/* 64*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(FILETIME)
/* 65*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(65)
/* 66*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(66)
/* 67*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(67)
/* 68*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(68)
/* 69*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(69)
/* 70*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(70)
/* 71*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(71)
/* 72*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(GUID)
/* 73*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(73)
/* 74*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(74)
/* 75*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(75)
/* 76*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(76)
/* 77*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(77)
/* 78*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(78)
/* 79*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(79)
/* 80*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(80)
/* 81*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(81)
/* 82*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(82)
/* 83*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(83)
/* 84*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(84)
/* 85*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(85)
/* 86*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(86)
/* 87*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(87)
/* 88*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(88)
/* 89*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(89)
/* 90*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(90)
/* 91*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(91)
/* 92*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(92)
/* 93*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(93)
/* 94*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(94)
/* 95*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(95)
/* 96*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(96)
/* 97*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(97)
/* 98*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(98)
/* 99*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(99)
/*100*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(100)
/*101*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(101)
/*102*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(102)
/*103*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(103)
/*104*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(104)
/*105*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(105)
/*106*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(106)
/*107*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(107)
/*108*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(108)
/*109*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(109)
/*110*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(110)
/*111*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(111)
/*112*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(112)
/*113*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(113)
/*114*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(114)
/*115*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(115)
/*116*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(116)
/*117*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(117)
/*118*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(118)
/*119*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(119)
/*120*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(120)
/*121*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(121)
/*122*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(122)
/*123*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(123)
/*124*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(124)
/*125*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(125)
/*126*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(126)
/*127*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(127)
/*128*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(BYTES)
/*129*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(STR)
/*130*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(WSTR)
/*131*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(NUMERIC)
/*132*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(132)
/*133*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(DBDATE)
/*134*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(DBTIME)
/*135*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(DBTIMESTAMP)
/*136*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(136)
/*137*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(137)
/*138*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(138)
/*139*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(139)
/*140*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(140)
/*141*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(141)
/*142*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(142)
/*143*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(143)
/*144*/ DEF_DBVARIANT_ASSIGN_AS_NOTHING(144)
/*145*/ DEF_DBVARIANT_ASSIGN_AS_FUNC(DBTIME2)
};//sm_assign_as_funcs

////////////////////////////////////////////////////////////////////////////////
#undef DEF_DBVARIANT_ASSIGN_AS_FUNC
#undef DEF_DBVARIANT_ASSIGN_AS_NOTHING

////////////////////////////////////////////////////////////////////////////////
//basic_dbvariant::assign_as_XXX

#define DEFINE_DBVARIANT_ASSIGN_AS_N(oledb_type,                              \
                                     convert_func,                            \
                                     assign_op,                               \
                                     val_type)                                \
template<class Allocator>                                                     \
HRESULT basic_dbvariant<Allocator>::assign_as_##oledb_type                    \
                                    (LPCCONVCONTEXT    pConvCtx,              \
                                     dbvariant_type&   dest,                  \
                                     const DBVARIANT&  source,                \
                                     const DBBINDING&  DEBUG_CODE(bind))      \
{                                                                             \
 DEBUG_CODE(const DBTYPE bind_wType=oledb_lib::oledb_typeid__##oledb_type;)   \
                                                                              \
 assert_msg(OLEDB_EXTRACT_DBTYPE(bind.wType)==bind_wType,                     \
            "bind type=0x"<<std::hex<<bind.wType);                            \
                                                                              \
 val_type new_value;                                                          \
                                                                              \
 const HRESULT cvt_hr=convert_func(pConvCtx,source,&new_value);               \
                                                                              \
 if(FAILED(cvt_hr))                                                           \
  return cvt_hr;                                                              \
                                                                              \
 dest##assign_op##(new_value);                                                \
                                                                              \
 return S_OK;                                                                 \
}

////////////////////////////////////////////////////////////////////////////////

DEFINE_DBVARIANT_ASSIGN_AS_N(I2,DBVariant__to_I2_ex, = ,DBVARIANT::value_i2_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(I4,DBVariant__to_I4_ex, = ,DBVARIANT::value_i4_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(R4,DBVariant__to_R4_ex, = ,DBVARIANT::value_r4_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(R8,DBVariant__to_R8_ex, = ,DBVARIANT::value_r8_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(CY,DBVariant__to_CY_ex, = ,DBVARIANT::value_cy_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(DATE,DBVariant__to_DATE_ex, .SetDate,DBVARIANT::value_date_n_type)

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::assign_as_BSTR
                                           (LPCCONVCONTEXT   pConvCtx,
                                            dbvariant_type&  dest,
                                            const DBVARIANT& source,
                                            const DBBINDING& DEBUG_CODE(bind))
{
 assert_msg(OLEDB_EXTRACT_DBTYPE(bind.wType)==DBTYPE_BSTR,
            "bind type=0x"<<std::hex<<bind.wType);

 DBVARIANT::value_cpp_bstr_n_type x;

 {
  const HRESULT hr=DBVariant__to_BSTR_ex(pConvCtx,source,&x);

  if(FAILED(hr))
   return hr;
 }//local

 dest.Clear();

 if(x.null())
 {
  dest.bstrVal =NULL;
  dest.wType   =DBTYPE_BSTR;

  dest.SetDataStatus__IsNull();
 }
 else
 {
  dest.bstrVal =x.value().Release();
  dest.wType   =DBTYPE_BSTR;

  dest.SetDataStatus__OK();
 }

 return S_OK;
}//assign_as_BSTR

//------------------------------------------------------------------------
DEFINE_DBVARIANT_ASSIGN_AS_N(IDISPATCH,DBVariant__to_IDISPATCH_ex,=,DBVARIANT::value_dispatch_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(ERROR,DBVariant__to_ERROR_ex,.SetError,DBVARIANT::value_scode_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(BOOL,DBVariant__to_BOOL_ex,=,DBVARIANT::value_cpp_bool_n_type);

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::assign_as_VARIANT
                                           (LPCCONVCONTEXT   pConvCtx,
                                            dbvariant_type&  dest,
                                            const DBVARIANT& source,
                                            const DBBINDING& DEBUG_CODE(bind))
{
 assert_msg(OLEDB_EXTRACT_DBTYPE(bind.wType)==DBTYPE_VARIANT,
            "bind type=0x"<<std::hex<<bind.wType);

 VARIANT tmpVarVal={0};

 HRESULT cvt_hr=DBVariant__to_VARIANT_ex(pConvCtx,source,&tmpVarVal);

 if(FAILED(cvt_hr))
  return cvt_hr;

 assert(cvt_hr==S_OK || cvt_hr==S_FALSE);

 assert(cvt_hr!=S_FALSE || tmpVarVal.vt==VT_NULL);

 try
 {
  dest.Clear(); //throw ?
 }
 catch(...)
 {
  _VERIFY_EQ(ole_lib::Variant_Clear(&tmpVarVal),S_OK);

  throw;
 }//catch

 //direct copy !!!
 dest.varVal=tmpVarVal;

 dest.wType=DBTYPE_VARIANT;

 dest.IsNull(cvt_hr==S_FALSE);

 return S_OK;
}//assign_as_VARIANT

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::assign_as_IUNKNOWN
                                           (LPCCONVCONTEXT   pConvCtx,
                                            dbvariant_type&  dest,
                                            const DBVARIANT& source,
                                            const DBBINDING& bind)
{
 assert_msg(OLEDB_EXTRACT_DBTYPE(bind.wType)==DBTYPE_IUNKNOWN,
            "bind type=0x"<<std::hex<<bind.wType);

 DBVARIANT::value_unknown_n_type spUnkEx;

 {
  IID result_iid=IID_IUnknown;

  if(bind.pObject!=NULL)
   result_iid=bind.pObject->iid;   
  
  const HRESULT hr=DBVariant__to_IUNKNOWN_ex(pConvCtx,source,result_iid,&spUnkEx);

  if(FAILED(hr))
   return hr;
 }//local

 if(bind.pObject==NULL || spUnkEx.null() || !spUnkEx.value())
 {
  dest=spUnkEx;
 }
 else
 {
  assert(bind.pObject);
  assert(!spUnkEx.null());

  ole_lib::IUnknownPtr obj;

  const HRESULT hr=spUnkEx.value().QueryInterface
                    (bind.pObject->iid,
                     reinterpret_cast<void**>(&obj.ref_ptr()),
                     S_OK);

  if(FAILED(hr))
   return hr;

  if(!obj)
   return E_UNEXPECTED;

  dest=obj.ptr();
 }//else

 return S_OK;
}//assign_as_IUNKNOWN

//------------------------------------------------------------------------
DEFINE_DBVARIANT_ASSIGN_AS_N(DECIMAL,DBVariant__to_DECIMAL_ex,=,DBVARIANT::value_decimal_n_type);

DEFINE_DBVARIANT_ASSIGN_AS_N(I1,DBVariant__to_I1_ex,=,DBVARIANT::value_i1_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(UI1,DBVariant__to_UI1_ex,=,DBVARIANT::value_ui1_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(UI2,DBVariant__to_UI2_ex,=,DBVARIANT::value_ui2_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(UI4,DBVariant__to_UI4_ex,=,DBVARIANT::value_ui4_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(I8,DBVariant__to_I8_ex,=,DBVARIANT::value_i8_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(UI8,DBVariant__to_UI8_ex, = ,DBVARIANT::value_ui8_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(GUID,DBVariant__to_GUID_ex, = ,DBVARIANT::value_guid_n_type)

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::assign_as_BYTES
                                           (LPCCONVCONTEXT   pConvCtx,
                                            dbvariant_type&  dest,
                                            const DBVARIANT& source,
                                            const DBBINDING& DEBUG_CODE(bind))
{
 assert_msg(OLEDB_EXTRACT_DBTYPE(bind.wType)==DBTYPE_BYTES,
            "bind type=0x"<<std::hex<<bind.wType);

 typedef TDBVariantBytesWriter  writer_type;

 writer_type writer;

 {
  const HRESULT hr=DBVariant__to_BYTES_ex(pConvCtx,source,&writer);

  if(FAILED(hr))
   return hr;

  if(hr==S_FALSE)
  {
   dest.SetBytes(NULL,0).SetDataStatus__IsNull();

   return S_OK;
  }
 }//local

 //copy the data from write.m_buffer into dest dbvariant

 dest.ReserveBytes(writer.m_buffer.size(),0,NULL); //throw

 assert(dest.wType==DBTYPE_BYTES);
 assert(dest.bytesVal.byte_count()==writer.m_buffer.size());

 const size_type
  copy_cb=writer.m_buffer.copy_binary(dest.bytesVal.ptr,
                                      dest.bytesVal.byte_count());

 assert(copy_cb==dest.bytesVal.byte_count());

 if(copy_cb!=dest.bytesVal.byte_count()) //release code BUG CHECK
  return E_UNEXPECTED;

 return S_OK;
}//assign_as_BYTES

//------------------------------------------------------------------------
DEFINE_DBVARIANT_ASSIGN_AS_N(STR,DBVariant__to_STR_ex,=,DBVARIANT::value_cpp_str_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(WSTR,DBVariant__to_WSTR_ex,=,DBVARIANT::value_cpp_wstr_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(NUMERIC,DBVariant__to_NUMERIC_ex,=,DBVARIANT::value_numeric_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(DBDATE,DBVariant__to_DBDATE_ex,=,DBVARIANT::value_dbdate_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(DBTIME,DBVariant__to_DBTIME_ex,=,DBVARIANT::value_dbtime_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(DBTIME2,DBVariant__to_DBTIME2_ex,=,DBVARIANT::value_dbtime2_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(FILETIME,DBVariant__to_FILETIME_ex,=,DBVARIANT::value_filetime_n_type)

DEFINE_DBVARIANT_ASSIGN_AS_N(DBTIMESTAMP,DBVariant__to_DBTIMESTAMP_ex,=,DBVARIANT::value_dbstamp_n_type)

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::assign_as_ARRAY
                                           (LPCCONVCONTEXT   pConvCtx,
                                            dbvariant_type&  dest,
                                            const DBVARIANT& source,
                                            const DBBINDING& bind)
{
 assert_msg((bind.wType&DBTYPE_ARRAY)==DBTYPE_ARRAY,
            "bind type=0x"<<std::hex<<bind.wType);

 //-----------------------------------------
 const DBTYPE wDestType=OLEDB_EXTRACT_DBTYPE(bind.wType);

 //-----------------------------------------
 IID ElementIID;

 if(OLEDB_EXTRACT_SIMPLE_DBTYPE(wDestType)!=DBTYPE_IUNKNOWN)
 {
  ElementIID=IID_NULL;
 }
 else
 if(bind.pObject==NULL)
 {
  ElementIID=IID_IUnknown;
 }
 else
 {
  ElementIID=bind.pObject->iid;
 }//else

 //-----------------------------------------
 ole_lib::TBaseSafeArray sa;

 const HRESULT hr=DBVariant__to_ARRAY_ex(pConvCtx,
                                         source,
                                         wDestType,
                                         ElementIID,
                                         &sa.ref_sa());
 if(FAILED(hr))
  return hr;

 assert_msg(hr==S_OK || hr==S_FALSE,"hr=0x"<<std::hex<<hr);

 assert(hr!=S_FALSE || sa.sa()==NULL);

 dest.Clear();

 dest.arrayVal2.ptr=sa.Release();

 assert(sa.sa()==NULL); //check of detach

 dest.arrayVal2.element_iid=ElementIID;

 dest.wType=wDestType;

 dest.IsNull(hr==S_FALSE);

#ifndef NDEBUG //Verification code
 if(dest.arrayVal2.ptr)
 {
  const DBTYPE wElementType=DBTYPE(wDestType&~DBTYPE_ARRAY);

  assert(wElementType!=DBTYPE_EMPTY);
  assert(wElementType!=DBTYPE_NULL);

  const DBVARIANT::LPCTYPEINFO pElementTypeInfo(DBVARIANT::GetInfo(wElementType));

  assert_msg(pElementTypeInfo,"wElementType="<<wElementType);

  if(pElementTypeInfo->FixedLen())
  {
   const UINT cbElement=::SafeArrayGetElemsize(dest.arrayVal2.ptr);

   assert_msg(pElementTypeInfo->Size==cbElement,
              "wElementType="<<wElementType<<"\n"
              "cbElement="<<cbElement<<"\n"
              "Size="<<pElementTypeInfo->Size);
  }//if
 }//if dest.arrayVal
#endif

 return S_OK;
}//assign_as_ARRAY

////////////////////////////////////////////////////////////////////////////////
#undef DEFINE_DBVARIANT_ASSIGN_AS_N

////////////////////////////////////////////////////////////////////////////////
//root transformation methods

template<class Allocator>
HRESULT basic_dbvariant<Allocator>::assign_as_ex(LPCCONVCONTEXT   pConvCtx,
                                                 const DBVARIANT& source,
                                                 const DBBINDING& bind)
{
 assert(pConvCtx);

 const DBTYPE wTargetType=OLEDB_EXTRACT_DBTYPE(bind.wType);

 if((wTargetType&DBTYPE_ARRAY)==DBTYPE_ARRAY)
  return self_type::assign_as_ARRAY(pConvCtx,*this,source,bind);

 typename self_type::assign_as_func_type assign_as_func=NULL;

 if(wTargetType<_DIM_(self_type::sm_assign_as_funcs))
 {
  assign_as_func=self_type::sm_assign_as_funcs[wTargetType];
 }//if

 if(assign_as_func==NULL)
  return DB_E_UNSUPPORTEDCONVERSION;

 assert_hint(assign_as_func!=NULL);

 return assign_as_func(pConvCtx,*this,source,bind);
}//assign_as_ex

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::assign_as_ex(LPCCONVCONTEXT   pConvCtx,
                                                 const DBVARIANT& source,
                                                 DBTYPE           wTargetType)
{
 assert(pConvCtx);

 DBBINDING bind={};

 bind.wType=wTargetType;

 return this->assign_as_ex(pConvCtx,source,bind);
}//assign_as_ex

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::assign_as(const DBVARIANT& source,
                                              const DBBINDING& bind)
{
 const TDBVariant_TypeCvtContext_Std ConvCtx;

 return this->assign_as_ex(&ConvCtx,source,bind);
}//assign_as

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::assign_as(const DBVARIANT& source,
                                              const DBTYPE     wTargetType)
{
 DBBINDING bind={};

 bind.wType=wTargetType;

 return this->assign_as(source,bind);
}//assign_as

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
