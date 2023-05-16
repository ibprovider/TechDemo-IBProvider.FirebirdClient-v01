////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_biginteger.h
//! \brief   Класс для представления безразмерного целого числа
//! \author  Kovalenko Dmitry.
//! \date    11.05.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/structure/ibp_biginteger.h"
#include "source/error_services/ibp_error_utils.h"
#include <sstream>
#include <wincrypt.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//namespace aliases

namespace libtommath=ibp::external::libtommath::set01;

////////////////////////////////////////////////////////////////////////////////

#define CHECK_MP_OP(func,args,trace_args)                                 \
switch(const int op_result=libtommath::func args)                         \
{                                                                         \
 case libtommath::MP_OKAY:                                                \
  break;                                                                  \
                                                                          \
 case libtommath::MP_MEM:                                                 \
  throw std::bad_alloc();                                                 \
                                                                          \
 default:                                                                 \
 {                                                                        \
  std::wostringstream args_dump;                                          \
                                                                          \
  args_dump<<trace_args;                                                  \
                                                                          \
  helper__throw_error(#func,op_result,args_dump.str());                   \
 }                                                                        \
}

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
static void helper__throw_error(const char*                 const op_sign,
                                int                         const op_result,
                                structure::t_const_wstr_box const arguments)
{
 assert(op_sign);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_common__failed_to_call_libtommath_set01_func_3,
   op_sign,
   op_result,
   arguments);
}//helper__throw_error

////////////////////////////////////////////////////////////////////////////////
//class IBP_BigInteger::tag_crypt_prov

class IBP_BigInteger::tag_crypt_prov
{
 private:
  typedef tag_crypt_prov                    self_type;

  tag_crypt_prov(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tag_crypt_prov();

 ~tag_crypt_prov();

  void gen_crypt_random(size_t cb,unsigned char* buf)const;

 private:
  HCRYPTPROV m_hProv;
};//class tag_crypt_prov

////////////////////////////////////////////////////////////////////////////////
//class IBP_BigInteger::tag_crypt_prov

IBP_BigInteger::tag_crypt_prov::tag_crypt_prov()
 :m_hProv(0)
{
 if(CryptAcquireContext(&m_hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
 {
  assert(m_hProv!=0);

  return;
 }//if

 if(CryptAcquireContext(&m_hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_NEWKEYSET))
 {
  assert(m_hProv!=0);

  return;
 }//if

 //-----------------------------------------

 //ERROR - failed to create crypt context

 const DWORD win32error=::GetLastError();

 assert(win32error!=0);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_win32__crypt__failed_to_create_crypt_context_1,
   win32error);
}//tag_crypt_prov

//------------------------------------------------------------------------
IBP_BigInteger::tag_crypt_prov::~tag_crypt_prov()
{
 _VERIFY(::CryptReleaseContext(m_hProv,0));
}//~tag_crypt_prov

//interface --------------------------------------------------------------
void IBP_BigInteger::tag_crypt_prov::gen_crypt_random(size_t         const cb,
                                                      unsigned char* const buf)const
{
 CHECK_READ_TYPED_PTR(buf,cb);

 assert(m_hProv!=0);

 size_t tail=cb;

 unsigned char* ptr=buf;

 while(tail>0)
 {
  DWORD part=structure::t_numeric_limits<DWORD>::max_value();

  if(tail<part)
   part=static_cast<DWORD>(tail);

  if(!CryptGenRandom(m_hProv,part,ptr))
  {
   //ERROR - failed to generate random bytes

   const DWORD win32error=::GetLastError();

   assert(win32error!=0);

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_win32__crypt__failed_to_generate_random_bytes_2,
     win32error,
     part);
  }//if

  tail-=part;

  ptr+=part;
 }//while
}//gen_crypt_random

////////////////////////////////////////////////////////////////////////////////
//class IBP_BigInteger::tag_data

IBP_BigInteger::tag_data::tag_data()
{
 libtommath::mp_init_v3(this->ptr());
}//tag_data

//------------------------------------------------------------------------
IBP_BigInteger::tag_data::~tag_data()
{
 libtommath::mp_clear_v3(this->ptr());
}//~IBP_BigInteger

//------------------------------------------------------------------------
IBP_BigInteger::tag_data::pointer
 IBP_BigInteger::tag_data::ptr()
{
 return &m_value;
}//ptr

//------------------------------------------------------------------------
IBP_BigInteger::tag_data::const_pointer
 IBP_BigInteger::tag_data::ptr()const
{
 return &m_value;
}//ptr - const

//------------------------------------------------------------------------
std::wstring IBP_BigInteger::tag_data::dump_w()const
{
 return libtommath::mp_dump_w(&m_value);
}//dump_w

//------------------------------------------------------------------------
void IBP_BigInteger::tag_data::swap(self_type& x)
{
 std::swap(*this->ptr(),*x.ptr());
}//swap

////////////////////////////////////////////////////////////////////////////////
//class IBP_BigInteger

IBP_BigInteger::IBP_BigInteger()
{;}

//------------------------------------------------------------------------
IBP_BigInteger::IBP_BigInteger(const self_type& x)
{
 CHECK_MP_OP
  (mp_copy, (x.m_data.ptr(),m_data.ptr()),
   L"\n"
   L"a="<<x.m_data.dump_w());
}//IBP_BigInteger

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

IBP_BigInteger::IBP_BigInteger(self_type&& x)
{
 m_data.swap(x.m_data);
}//IBP_BigInteger

#endif

//------------------------------------------------------------------------
IBP_BigInteger::IBP_BigInteger(const char* const text, unsigned int const radix)
{
 assert(text);
 assert(radix==10 || radix==16);

 CHECK_MP_OP
  (mp_read_radix, (m_data.ptr(),text,radix),
   L"\n"
   L"str=\""<<structure::tstr_to_wstr(text)<<L"\",\n"
   L"radix="<<radix);
}//IBP_BigInteger

//------------------------------------------------------------------------
IBP_BigInteger::IBP_BigInteger(size_t const count, const unsigned char* const bytes)
{
 this->set_unsigned_bin(count,bytes);
}//IBP_BigInteger

//------------------------------------------------------------------------
IBP_BigInteger::~IBP_BigInteger()
{;}

//------------------------------------------------------------------------
IBP_BigInteger& IBP_BigInteger::operator = (const self_type& x)
{
 self_type tmp(x);

 this->swap(tmp);

 return *this;
}//operator =

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

IBP_BigInteger& IBP_BigInteger::operator = (self_type&& x)
{
 self_type tmp(__STL_MOVE_VALUE(x));

 this->swap(tmp);

 return *this;
}//move operator

#endif

//------------------------------------------------------------------------
void IBP_BigInteger::swap(self_type& x)
{
 m_data.swap(x.m_data);
}//swap

//------------------------------------------------------------------------
IBP_BigInteger& IBP_BigInteger::set_unsigned_bin(size_t count, const unsigned char* bytes)
{
 CHECK_READ_TYPED_PTR(bytes,count);

 CHECK_MP_OP
  (mp_read_unsigned_bin_v2, (m_data.ptr(), bytes, count),
   L"\n"
   L"size="<<count);

 return *this;
}//set_unsigned_bin

//------------------------------------------------------------------------
IBP_BigInteger& IBP_BigInteger::random(size_t const numBytes)
{
 tag_crypt_prov crypt_prov; //throw

 bytes_type bytes(numBytes); //throw

 crypt_prov.gen_crypt_random(bytes.size(),bytes.buffer()); //throw

 return this->set_unsigned_bin(bytes.size(),bytes.buffer());
}//random

//operators --------------------------------------------------------------
IBP_BigInteger IBP_BigInteger::operator + (const self_type& val)const
{
 IBP_BigInteger rc;

 CHECK_MP_OP
  (mp_add, (m_data.ptr(), val.m_data.ptr(), rc.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<val.m_data.dump_w());

 return rc;
}//operator +

//------------------------------------------------------------------------
IBP_BigInteger IBP_BigInteger::operator - (const self_type& val)const
{
 IBP_BigInteger rc;

 CHECK_MP_OP
  (mp_sub, (m_data.ptr(), val.m_data.ptr(), rc.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<val.m_data.dump_w());

 return rc;
}//operator -

//------------------------------------------------------------------------
IBP_BigInteger IBP_BigInteger::operator * (const self_type& val)const
{
 IBP_BigInteger rc;

 CHECK_MP_OP
  (mp_mul, (m_data.ptr(), val.m_data.ptr(), rc.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<val.m_data.dump_w());

 return rc;
}//operator *

//------------------------------------------------------------------------
IBP_BigInteger IBP_BigInteger::operator / (const self_type& val)const
{
 IBP_BigInteger rc;
 IBP_BigInteger tmp;

 CHECK_MP_OP
  (mp_div, (m_data.ptr(), val.m_data.ptr(), rc.m_data.ptr(), tmp.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<val.m_data.dump_w());

 return rc;
}//operator /

//------------------------------------------------------------------------
IBP_BigInteger IBP_BigInteger::operator % (const self_type& val)const
{
 IBP_BigInteger rc;

 CHECK_MP_OP
  (mp_mod, (m_data.ptr(), val.m_data.ptr(), rc.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<val.m_data.dump_w());

 return rc;
}//operator %

//------------------------------------------------------------------------
IBP_BigInteger& IBP_BigInteger::operator += (const self_type& val)
{
 IBP_BigInteger rc;

 CHECK_MP_OP
  (mp_add, (m_data.ptr(), val.m_data.ptr(), rc.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<val.m_data.dump_w());

 this->swap(rc);

 return *this;
}//operator +=

//------------------------------------------------------------------------
IBP_BigInteger& IBP_BigInteger::operator -= (const self_type& val)
{
 IBP_BigInteger rc;

 CHECK_MP_OP
  (mp_sub, (m_data.ptr(), val.m_data.ptr(), rc.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<val.m_data.dump_w());

 this->swap(rc);

 return *this;
}//operator -=

//------------------------------------------------------------------------
IBP_BigInteger& IBP_BigInteger::operator *= (const self_type& val)
{
 IBP_BigInteger rc;

 CHECK_MP_OP
  (mp_mul, (m_data.ptr(), val.m_data.ptr(), rc.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<val.m_data.dump_w());

 this->swap(rc);

 return *this;
}//operator *=

//------------------------------------------------------------------------
IBP_BigInteger& IBP_BigInteger::operator /= (const self_type& val)
{
 IBP_BigInteger rc;
 IBP_BigInteger tmp;

 CHECK_MP_OP
  (mp_div, (m_data.ptr(), val.m_data.ptr(),rc.m_data.ptr(), tmp.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<val.m_data.dump_w());

 this->swap(rc);

 return *this;
}//operator /=

//------------------------------------------------------------------------
IBP_BigInteger& IBP_BigInteger::operator %= (const self_type& val)
{
 IBP_BigInteger rc;

 CHECK_MP_OP
  (mp_mod, (m_data.ptr(), val.m_data.ptr(), rc.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<val.m_data.dump_w());

 this->swap(rc);

 return *this;
}//operator %=

//------------------------------------------------------------------------
bool IBP_BigInteger::operator == (const self_type& val)const
{
 return libtommath::mp_cmp(m_data.ptr(),val.m_data.ptr())==libtommath::MP_EQ;
}//operator ==

//------------------------------------------------------------------------
bool IBP_BigInteger::operator != (const self_type& val)const
{
 return !((*this)==val);
}//operator !=

//------------------------------------------------------------------------
IBP_BigInteger IBP_BigInteger::modPow(const self_type& pow, const self_type& mod)const
{
 self_type rc;

 CHECK_MP_OP
  (mp_exptmod, (m_data.ptr(), pow.m_data.ptr(), mod.m_data.ptr(), rc.m_data.ptr()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"b="<<pow.m_data.dump_w()<<L",\n"
   L"c="<<mod.m_data.dump_w());

 return rc;
}//modPow

//------------------------------------------------------------------------
size_t IBP_BigInteger::length()const
{
 return libtommath::mp_unsigned_bin_size_v2(m_data.ptr());
}//length

//------------------------------------------------------------------------
std::string IBP_BigInteger::get_text(unsigned int const radix)const
{
 size_t size;

 CHECK_MP_OP
  (mp_radix_size, (m_data.ptr(), radix, &size),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"radix="<<radix);

 assert(size>0);

 structure::t_typed_simple_buffer<char,IBP_MemoryAllocator> buf(size);

 CHECK_MP_OP
  (mp_toradix_n, (m_data.ptr(), buf.buffer(), radix, size),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"radix="<<radix<<L",\n"
   L"maxlen="<<size);

 return std::string(buf.buffer(),buf.buffer_end()-1);
}//get_text

//------------------------------------------------------------------------
void IBP_BigInteger::get_unsigned_bin(bytes_type& bytes)const
{
 const size_t l=this->length();

 bytes.alloc(l);

 CHECK_MP_OP
  (mp_to_unsigned_bin, (m_data.ptr(), bytes.buffer()),
   L"\n"
   L"a="<<m_data.dump_w()<<L",\n"
   L"length="<<l);
}//get_unsigned_bin

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
