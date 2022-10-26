////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_args.cc
//! \brief   Интерфейс для формирования параметров ошибок
//! \author  Kovalenko Dmitry
//! \date    13.04.2009
#ifndef _ibp_error_args_CC_
#define _ibp_error_args_CC_

#include <ole_lib/oledb/variant/oledb_variant.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_args

template<class Traits>
t_ibp_error_args<Traits>::t_ibp_error_args()
{;}

//------------------------------------------------------------------------
template<class Traits>
t_ibp_error_args<Traits>::~t_ibp_error_args()
{;}

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (mce_code_type const mce_code_0)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,mce_code_0);

 assert(errVar.vt==IBP_EVT::V_IBP_MSG_CODE);
 assert(errVar.value.valueIBProviderMsgCode==mce_code_0);

 return this->add_arg(errVar);
}//operator << mce_code_type

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (bool const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_BOOL);
 assert(errVar.value.valueBool==x);

 return this->add_arg(errVar);
}//operator << bool

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (signed __int8 const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_I1);

 return this->add_arg(errVar);
}//operator << I1

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (unsigned __int8 const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_UI1);

 return this->add_arg(errVar);
}//operator << UI1

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (signed __int16 const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_I2);

 return this->add_arg(errVar);
}//operator << I2

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (unsigned __int16 const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_UI2);

 return this->add_arg(errVar);
}//operator << UI2

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (signed __int32 const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_I4);

 return this->add_arg(errVar);
}//operator << I4

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (unsigned __int32 const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_UI4);

 return this->add_arg(errVar);
}//operator << UI4

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (signed __int64 const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_I8);

 return this->add_arg(errVar);
}//operator << I8

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (unsigned __int64 const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_UI8);

 return this->add_arg(errVar);
}//operator << UI8

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (signed long const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_LONG);

 return this->add_arg(errVar);
}//operator << signed long

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (unsigned long const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_ULONG);

 return this->add_arg(errVar);
}//operator << unsigned long

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (double const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_R8);

 return this->add_arg(errVar);
}//operator << double

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (REFGUID x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_GUID);

 return this->add_arg(errVar);
}//operator << GUID

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (const char* const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_STR);
 assert(errVar.value.valueStr.ptr==x);
 assert(errVar.value.valueStr.len==(x?strlen(x):0));

 return this->add_arg(errVar);
}//operator << const char*

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (const std::string& x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_STR);

 return this->add_arg(errVar);
}//operator << const string&

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (structure::str_parameter const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x.c_str());

 assert(errVar.vt==IBP_EVT::V_STR);

 return this->add_arg(errVar);
}//operator << structure::str_parameter

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (structure::t_const_str_box const x)
{
 CHECK_READ_TYPED_PTR(x.data(),x.size())

 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_STR);
 assert(errVar.value.valueStr.ptr==x.ptr);
 assert(errVar.value.valueStr.len==x.len);

 return this->add_arg(errVar);
}//operator << structure::t_const_str_box

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (const wchar_t* const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_WSTR);
 assert(errVar.value.valueWStr.ptr==x);
 assert(errVar.value.valueWStr.len==(x?wcslen(x):0));

 return this->add_arg(errVar);
}//operator << const wchar_t*

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (const std::wstring& x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_WSTR);

 return this->add_arg(errVar);
}//operator << const wstring&

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (structure::wstr_parameter const x)
{
 // [2022-10-21] Not used in IBProvider code.

 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x.c_str());

 assert(errVar.vt==IBP_EVT::V_WSTR);

 return this->add_arg(errVar);
}//operator << structure::wstr_parameter

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (structure::t_const_wstr_box const x)
{
 CHECK_READ_TYPED_PTR(x.data(),x.size())

 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,x);

 assert(errVar.vt==IBP_EVT::V_WSTR);
 assert(errVar.value.valueWStr.ptr==x.ptr);
 assert(errVar.value.valueWStr.len==x.len);

 return this->add_arg(errVar);
}//operator << structure::t_const_wstr_box

//------------------------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE

// [2022-10-26] Tested but not used

template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (IUnknown* const pUnk)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,pUnk);

 assert(errVar.vt==IBP_EVT::V_IUNKNOWN);

 return this->add_arg(errVar);
}//operator << IUnknown*

#endif // defined IBP_BUILD_TESTCODE

// //------------------------------------------------------------------------
// template<class Traits>
// typename t_ibp_error_args<Traits>::out_return_type&
//  t_ibp_error_args<Traits>::operator << (IDispatch* const pDisp)
// {
//  oledb_lib::DBVARIANT dbvar;
// 
//  dbvar.wType       =DBTYPE_IDISPATCH;
//  dbvar.dispVal.ptr =pDisp;
// 
//  return this->add_arg(dbvar);
// }//operator << IDispatch*

//------------------------------------------------------------------------
//template<class Traits>
//typename t_ibp_error_args<Traits>::out_return_type&
// t_ibp_error_args<Traits>::operator << (ibprovider::IBP_IText* const pText)
//{
// IBP_ERRORVARIANT errVar;
//
// IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,pText);
//
// assert(errVar.vt==IBP_EVT::V_IUNKNOWN);
//
// return this->add_arg(errVar);
//}//operator << IBP_IText*

//------------------------------------------------------------------------
// template<class Traits>
// typename t_ibp_error_args<Traits>::out_return_type&
//  t_ibp_error_args<Traits>::operator << (const ole_lib::TBSTR& x)
// {
//  oledb_lib::DBVARIANT dbvar;
// 
//  dbvar.wType       =DBTYPE_WSTR;
//  dbvar.wstrVal.len =x.length();
//  dbvar.wstrVal.ptr =const_cast<wchar_t*>(x.bstr());
// 
//  return this->add_arg(dbvar);
// }//operator << TBSTR

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (lib::structure::t_err_record* const pErrRec)
{
 assert(pErrRec);

 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith__CPP_ERR_RECORD(&errVar,pErrRec);

 assert(errVar.vt==IBP_EVT::V_CPP_ERR_RECORD);
 assert(errVar.value.pCppErrRecord==pErrRec);

 return this->add_arg(errVar);
}//operator << lib::structure::t_err_record*

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (lib::structure::t_err_text* const pErrText)
{
 assert(pErrText);

 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith__CPP_ERR_TEXT(&errVar,pErrText);

 assert(errVar.vt==IBP_EVT::V_CPP_ERR_TEXT);
 assert(errVar.value.pCppErrText==pErrText);

 return this->add_arg(errVar);
}//operator << lib::structure::t_err_text*

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (ibp_err_data__symbol__tag<char> x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,structure::make_str_box(&x.symbol,1));

 assert(errVar.vt==IBP_EVT::V_STR);
 assert(errVar.value.valueStr.ptr==&x.symbol);
 assert(errVar.value.valueStr.len==1);

 return this->add_arg(errVar);
}//operator << ibp_err_data__symbol__tag<char>

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (ibp_err_data__symbol__tag<wchar_t> x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith(&errVar,structure::make_str_box(&x.symbol,1));

 assert(errVar.vt==IBP_EVT::V_WSTR);
 assert(errVar.value.valueWStr.ptr==&x.symbol);
 assert(errVar.value.valueWStr.len==1);

 return this->add_arg(errVar);
}//operator << ibp_err_data__symbol__tag<wchar_t>

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (ibp_err_data__null_sign const UNUSED_ARG(x))
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith__NULL(&errVar);

 assert(errVar.vt==IBP_EVT::V_NULL);

 return this->add_arg(errVar);
}//operator << ibp_err_data__null_sign

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (ibp_err_data__win32_error_msg const x)
{
 IBP_ERRORVARIANT errVar;

 IBP_ERRORVARIANT_UTILS::LinkWith__WIN32_ERR(&errVar,x.errorCode);

 assert(errVar.vt==IBP_EVT::V_WIN32_ERR);
 assert(errVar.value.valueWin32Err==x.errorCode);

 return this->add_arg(errVar);
}//operator << win32_error_msg_type

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::push_arg__as_wstr(const oledb_lib::DBVARIANT& x)
{
 assert(x.wType==oledb_lib::oledb_typeid__WSTR);

 assert(x.TestDataStatus__IsOK_or_IsNull());

 if(x.wType!=oledb_lib::oledb_typeid__WSTR)
 {
  assert_msg(false,"wType: "<<x.wType);

  return (*this)<<L"<bad arg value type>";
 }//if

 if(x.TestDataStatus__IsOK())
 {
  return (*this)<<structure::make_str_box(x.wstrVal.ptr,x.wstrVal.len);
 }//if

 if(x.TestDataStatus__IsNull())
 {
  return (*this)<<ibp_err_data__null_sign();
 }//if

 assert_msg(false,"bad status: "<<x.GetDataStatus());

 return (*this)<<L"<bad arg value status>";
}//push_arg__as_wstr

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
