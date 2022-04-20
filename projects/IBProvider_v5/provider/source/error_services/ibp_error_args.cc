////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_args.cc
//! \brief   Интерфейс для формирования параметров ошибок
//! \author  Kovalenko Dmitry
//! \date    13.04.2009
#ifndef _ibp_error_args_CC_
#define _ibp_error_args_CC_

#include "source/oledb/error/ibp_oledb__error_text_factory.h"

#include <ole_lib/oledb/variant/oledb_variant_numeric_installer.h>

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
 const ole_lib::IUnknownPtr spUnk(oledb::IBP_CreateErrorText(mce_code_0));

 assert(spUnk);

 oledb_lib::DBVARIANT dbvar;

 dbvar.wType      =DBTYPE_IUNKNOWN;
 dbvar.unkVal.ptr =spUnk;
 dbvar.unkVal.iid =ibprovider::IID_IBP_IText;

 return this->add_arg(dbvar);
}//operator << mce_code_type

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (bool const x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType    =DBTYPE_BOOL;
 dbvar.boolVal  =(x?VARIANT_TRUE:VARIANT_FALSE);

 return this->add_arg(dbvar);
}//operator << bool

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (signed __int8 const x)
{
 oledb_lib::DBVARIANT dbvar;

 DBVariant__NumericInstaller(&dbvar,x);

 return this->add_arg(dbvar);
}//operator << I1

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (unsigned __int8 const x)
{
 oledb_lib::DBVARIANT dbvar;

 DBVariant__NumericInstaller(&dbvar,x);

 return this->add_arg(dbvar);
}//operator << UI1

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (signed __int16 const x)
{
 oledb_lib::DBVARIANT dbvar;

 DBVariant__NumericInstaller(&dbvar,x);

 return this->add_arg(dbvar);
}//operator << I2

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (unsigned __int16 const x)
{
 oledb_lib::DBVARIANT dbvar;

 DBVariant__NumericInstaller(&dbvar,x);

 return this->add_arg(dbvar);
}//operator << UI2

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (signed __int32 const x)
{
 oledb_lib::DBVARIANT dbvar;

 DBVariant__NumericInstaller(&dbvar,x);

 return this->add_arg(dbvar);
}//operator << I4

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (unsigned __int32 const x)
{
 oledb_lib::DBVARIANT dbvar;

 DBVariant__NumericInstaller(&dbvar,x);

 return this->add_arg(dbvar);
}//operator << UI4

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (signed __int64 const x)
{
 oledb_lib::DBVARIANT dbvar;

 DBVariant__NumericInstaller(&dbvar,x);

 return this->add_arg(dbvar);
}//operator << I8

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (unsigned __int64 const x)
{
 oledb_lib::DBVARIANT dbvar;

 DBVariant__NumericInstaller(&dbvar,x);

 return this->add_arg(dbvar);
}//operator << UI8

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (signed long const x)
{
 oledb_lib::DBVARIANT dbvar;

 DBVariant__NumericInstaller(&dbvar,x);

 return this->add_arg(dbvar);
}//operator << long

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (unsigned long const x)
{
 oledb_lib::DBVARIANT dbvar;

 DBVariant__NumericInstaller(&dbvar,x);

 return this->add_arg(dbvar);
}//operator << unsigned long

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (double const x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType=oledb_lib::oledb_typeid__R8;
 dbvar.valR8=x;

 assert(dbvar.TestDataStatus__IsOK());

 return this->add_arg(dbvar);
}//operator << double

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (REFGUID x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType   =DBTYPE_GUID;
 dbvar.guidVal =x;

 return this->add_arg(dbvar);
}//operator << GUID

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (const char* const x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType      =DBTYPE_STR;
 dbvar.strVal.len =x?strlen(x):0;
 dbvar.strVal.ptr =const_cast<char*>(x);

 return this->add_arg(dbvar);
}//operator << const char*

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (const std::string& x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType      =DBTYPE_STR;
 dbvar.strVal.len =x.size();
 dbvar.strVal.ptr =const_cast<char*>(x.c_str());

 return this->add_arg(dbvar);
}//operator << const string&

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (structure::str_parameter x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType      =DBTYPE_STR;
 dbvar.strVal.len =x.length();
 dbvar.strVal.ptr =const_cast<char*>(x.c_str());

 return this->add_arg(dbvar);
}//operator << structure::str_parameter

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (structure::t_const_str_box const x)
{
 CHECK_READ_TYPED_PTR(x.ptr,x.len)

 oledb_lib::DBVARIANT dbvar;

 dbvar.wType      =DBTYPE_STR;
 dbvar.strVal.len =x.len;
 dbvar.strVal.ptr =const_cast<char*>(x.ptr);

 return this->add_arg(dbvar);
}//operator << structure::t_const_str_box

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (const wchar_t* const x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType       =DBTYPE_WSTR;
 dbvar.wstrVal.len =x?wcslen(x):0;
 dbvar.wstrVal.ptr =const_cast<wchar_t*>(x);

 return this->add_arg(dbvar);
}//operator << const wchar_t*

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (const std::wstring& x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType       =DBTYPE_WSTR;
 dbvar.wstrVal.len =x.size();
 dbvar.wstrVal.ptr =const_cast<wchar_t*>(x.c_str());

 return this->add_arg(dbvar);
}//operator << const wstring&

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (structure::wstr_parameter const x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType       =DBTYPE_WSTR;
 dbvar.wstrVal.len =x.length();
 dbvar.wstrVal.ptr =const_cast<wchar_t*>(x.c_str());

 return this->add_arg(dbvar);
}//operator << structure::wstr_parameter

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (structure::t_const_wstr_box const x)
{
 CHECK_READ_TYPED_PTR(x.data(),x.size())

 oledb_lib::DBVARIANT dbvar;

 dbvar.wType       =DBTYPE_WSTR;
 dbvar.wstrVal.len =x.size();
 dbvar.wstrVal.ptr =const_cast<wchar_t*>(x.data());

 return this->add_arg(dbvar);
}//operator << structure::t_const_wstr_box

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (IUnknown* const pUnk)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType       =DBTYPE_IUNKNOWN;
 dbvar.unkVal.ptr  =pUnk;
 dbvar.unkVal.iid  =IID_IUnknown;

 return this->add_arg(dbvar);
}//operator << IUnknown*

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (IDispatch* const pDisp)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType       =DBTYPE_IDISPATCH;
 dbvar.dispVal.ptr =pDisp;

 return this->add_arg(dbvar);
}//operator << IDispatch*

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (ibprovider::IBP_IText* const pText)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType       =DBTYPE_IUNKNOWN;
 dbvar.unkVal.ptr  =pText;
 dbvar.unkVal.iid  =ibprovider::IID_IBP_IText;

 return this->add_arg(dbvar);
}//operator << IBP_IText*

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (const ole_lib::TBSTR& x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType       =DBTYPE_WSTR;
 dbvar.wstrVal.len =x.length();
 dbvar.wstrVal.ptr =const_cast<wchar_t*>(x.bstr());

 return this->add_arg(dbvar);
}//operator << TBSTR

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (ibp_err_data__symbol__tag<char> x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType      =DBTYPE_STR;
 dbvar.strVal.ptr =&x.symbol;
 dbvar.strVal.len =1;

 return this->add_arg(dbvar);
}//operator << t_ansi_symbol

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (ibp_err_data__symbol__tag<wchar_t> x)
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType       =DBTYPE_WSTR;
 dbvar.wstrVal.ptr =&x.symbol;
 dbvar.wstrVal.len =1;

 return this->add_arg(dbvar);
}//operator << t_unicode_symbol

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (ibp_err_data__null_sign const UNUSED_ARG(x))
{
 oledb_lib::DBVARIANT dbvar;

 dbvar.wType=DBTYPE_NULL;

 return this->add_arg(dbvar);
}//operator << t_null_sign

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::operator << (ibp_err_data__win32_error_msg const x)
{
 const ole_lib::IUnknownPtr
  spUnk(oledb::IBP_CreateErrorText_ForWin32ErrorMsg(x.errorCode));

 assert(spUnk);

 oledb_lib::DBVARIANT dbvar;

 dbvar.wType      =DBTYPE_IUNKNOWN;
 dbvar.unkVal.ptr =spUnk;
 dbvar.unkVal.iid =ibprovider::IID_IBP_IText;

 return this->add_arg(dbvar);
}//operator << win32_error_msg_type

//------------------------------------------------------------------------
template<class Traits>
typename t_ibp_error_args<Traits>::out_return_type&
 t_ibp_error_args<Traits>::push_arg(const base_variant_type& x)
{
 return this->add_arg(x);
}//push_arg

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
