////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_args.h
//! \brief   Интерфейс для формирования параметров ошибок
//! \author  Kovalenko Dmitry
//! \date    13.04.2009
#ifndef _ibp_error_args_H_
#define _ibp_error_args_H_

#include "source/error_services/ibp_error_codes.h"
#include <ole_lib/oledb/variant/oledb_variant.h>
#include <structure/t_str_parameter.h>
#include <structure/t_const_str_box.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//struct ibp_err_data__symbol

template<typename charT>
struct ibp_err_data__symbol__tag
{
 charT symbol;

 explicit ibp_err_data__symbol__tag(charT const c)
  :symbol(c) {;}
};//struct ibp_err_data__symbol__tag

////////////////////////////////////////////////////////////////////////////////

template<typename charT>
ibp_err_data__symbol__tag<charT> ibp_err_data__symbol(charT const c)
{
 return ibp_err_data__symbol__tag<charT>(c);
}//ibp_err_data__symbol

////////////////////////////////////////////////////////////////////////////////
//struct ibp_err_data__null_sign

struct ibp_err_data__null_sign
{
 ibp_err_data__null_sign(){;}
};//struct ibp_err_data__null_sign

////////////////////////////////////////////////////////////////////////////////
//struct ibp_err_data__win32_error_msg

struct ibp_err_data__win32_error_msg
{
 DWORD errorCode;

 explicit ibp_err_data__win32_error_msg(DWORD const x)
  :errorCode(x) {;}
};//struct ibp_err_data__win32_error_msg

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_args

/// <summary>
///  Интерфейс для регистрации параметров сообщений
/// </summary>
template<class Traits>
class t_ibp_error_args
{
 private:
  typedef t_ibp_error_args<Traits>                      self_type;

  t_ibp_error_args(const self_type&) COMP_W000002_COPY_CTOR_IMPL
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef Traits                                        traits_type;
  typedef typename traits_type::out_return_type         out_return_type;

  typedef oledb_lib::DBVARIANT                          base_variant_type;

  typedef ibp_msg_code_type                             mce_code_type;

 protected:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  t_ibp_error_args();

  /// <summary>
  ///  Деструктор
  /// </summary>
  ~t_ibp_error_args();

 public:
  out_return_type& operator << (mce_code_type      mce_code_0);

  out_return_type& operator << (bool               x);

  out_return_type& operator << (signed __int8      x);
  out_return_type& operator << (unsigned __int8    x);

  out_return_type& operator << (signed __int16     x);
  out_return_type& operator << (unsigned __int16   x);

  out_return_type& operator << (signed __int32     x);
  out_return_type& operator << (unsigned __int32   x);

  out_return_type& operator << (signed __int64     x);
  out_return_type& operator << (unsigned __int64   x);

  out_return_type& operator << (signed long        x);
  out_return_type& operator << (unsigned long      x);

  out_return_type& operator << (float              x);
  out_return_type& operator << (double             x);

  out_return_type& operator << (REFGUID            x);

  out_return_type& operator << (const char*                 x);
  out_return_type& operator << (const std::string&          x);
  out_return_type& operator << (structure::str_parameter    x);
  out_return_type& operator << (structure::t_const_str_box  x);

  out_return_type& operator << (const wchar_t*              x);
  out_return_type& operator << (const std::wstring&         x);
  out_return_type& operator << (structure::wstr_parameter   x);
  out_return_type& operator << (structure::t_const_wstr_box x);

  out_return_type& operator << (IUnknown*  pUnk);
  out_return_type& operator << (IDispatch* pDisp);

  out_return_type& operator << (ibprovider::IBP_IText* pText);

  out_return_type& operator << (const ole_lib::TBSTR& x);   //as WSTR

 public:
  out_return_type& operator << (ibp_err_data__symbol__tag<char>    x);
  out_return_type& operator << (ibp_err_data__symbol__tag<wchar_t> x);
  out_return_type& operator << (ibp_err_data__null_sign            x);

  out_return_type& operator << (ibp_err_data__win32_error_msg      x);

 public:
  out_return_type& push_arg(const base_variant_type& x);

 public:
  virtual out_return_type& add_arg(const base_variant_type& x)=0;
};//class t_ibp_error_args

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_args_data__value_with_null

template<class TValue>
class t_ibp_error_args_data__value_with_null
{
 private:
  typedef t_ibp_error_args_data__value_with_null<TValue>   self_type;

  self_type& operator = (const self_type&);

 public:
  typedef TValue                                    value_type;
  typedef structure::t_value_with_null<TValue>      value_type_n;

 public:
  t_ibp_error_args_data__value_with_null(const value_type_n* const pData)
   :m_pData(pData)
   ,m_pNullSign(L"NULL")
  {
   assert(m_pData!=nullptr);
  }//t_ibp_error_args_data__value_with_null

  t_ibp_error_args_data__value_with_null(const value_type_n* const pData,
                                         const wchar_t*      const pNullSign)
   :m_pData(pData)
   ,m_pNullSign(pNullSign)
  {
   assert(m_pData!=nullptr);
   assert(m_pNullSign!=nullptr);
  }//t_ibp_error_args_data__value_with_null

  //----------------------------------------------------------------------
  const value_type_n* data()const
  {
   return m_pData;
  }

  const wchar_t* null_sign()const
  {
   return m_pNullSign;
  }

 private:
  const value_type_n* const m_pData;
  const wchar_t*      const m_pNullSign;
};//class t_ibp_error_args_data__value_with_null

////////////////////////////////////////////////////////////////////////////////

template<class TValue>
t_ibp_error_args_data__value_with_null<TValue>
 push_value(const structure::t_value_with_null<TValue>& x)
{
 return t_ibp_error_args_data__value_with_null<TValue>(&x);
}//push_value

//------------------------------------------------------------------------
template<class TValue>
t_ibp_error_args_data__value_with_null<TValue>
 push_value(const structure::t_value_with_null<TValue>& x,
            const wchar_t* const                        pNullSign)
{
 assert(pNullSign!=nullptr);

 return t_ibp_error_args_data__value_with_null<TValue>(&x,pNullSign);
}//push_value

////////////////////////////////////////////////////////////////////////////////

template<class TErr,class TValue>
TErr& operator << (TErr& err,const t_ibp_error_args_data__value_with_null<TValue>& x)
{
 assert(x.data());

 if(x.data()->null())
  err<<x.null_sign();
 else
  err<<x.data()->value();

 return err;
}//operator <<

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/error_services/ibp_error_args.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
