////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_biginteger.h
//! \brief   Класс для представления безразмерного целого числа
//! \author  Kovalenko Dmitry.
//! \date    11.05.2016
#ifndef _ibp_biginteger_H_
#define _ibp_biginteger_H_

#include "source/external/libtommath/set01/ibp_external__libtommath_set01__tommath.h"
#include "source/ibp_memory.h"
#include <structure/t_simple_buffer.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_BigInteger

/// <source>
///  Класс для представления безразмерного целого числа.
/// </source>
class IBP_BigInteger
{
 private:
  typedef IBP_BigInteger                    self_type;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_typed_simple_buffer
           <unsigned char,
            IBP_MemoryAllocator>            bytes_type;

  struct tag_unsigned_bin{};

 public:
  /// <summary>
  ///  Конструктор инициализации.
  /// </summary>
  IBP_BigInteger();

  IBP_BigInteger(const self_type&);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  IBP_BigInteger(self_type&&);
 #endif

  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] text
  //! \param[in] radix
  IBP_BigInteger(const char* text, unsigned int radix);

  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] count
  //! \param[in] bytes
  IBP_BigInteger(size_t count, const unsigned char* bytes);

  /// <summary>
  ///  Деструктор.
  /// </summary>
 ~IBP_BigInteger();

  self_type& operator = (const self_type&);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (self_type&&);
 #endif

  //interface ------------------------------------------------------------
  void swap(self_type& x);

  self_type& set_unsigned_bin(size_t count, const unsigned char* bytes);

  self_type& random(size_t numBytes);

  //operators ------------------------------------------------------------
  self_type operator + (const self_type& val)const;

  self_type operator - (const self_type& val)const;

  self_type operator * (const self_type& val)const;

  self_type operator / (const self_type& val)const;

  self_type operator % (const self_type& val)const;

  self_type& operator += (const self_type& val);

  self_type& operator -= (const self_type& val);

  self_type& operator *= (const self_type& val);

  self_type& operator /= (const self_type& val);

  self_type& operator %= (const self_type& val);

  //----------------------------------------------------------------------

  bool operator == (const self_type& val)const;

  bool operator != (const self_type& val)const;

  //----------------------------------------------------------------------
  self_type modPow(const self_type& pow, const self_type& mod) const;

  size_t length() const;

  std::string get_text(unsigned int radix)const;

  void get_unsigned_bin(bytes_type& bytes)const;

 private:
  class tag_data;
  class tag_crypt_prov;

 private:
  class tag_data
  {
   private:
    typedef tag_data                                    self_type;

    tag_data(const self_type& x);
    self_type& operator = (const self_type&);

   public: //typedefs ------------------------------------------------------
    typedef ibp::external::libtommath::set01::mp_int    value_type;

    typedef value_type*                                 pointer;

    typedef const value_type*                           const_pointer;

   public:
    tag_data();

   ~tag_data();

    //selectors ------------------------------------------------------------
    pointer ptr();

    const_pointer ptr()const;

    std::wstring dump_w()const;

    //modificators ---------------------------------------------------------
    void swap(self_type& x);

   private:
    value_type m_value;
  };//class tag_data

 private:
  tag_data m_data;
};//class IBP_BigInteger

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
