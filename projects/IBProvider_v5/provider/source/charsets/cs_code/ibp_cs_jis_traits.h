////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_jis_traits.h
//! \brief   Алгоритмы преобразования кодовых страниц SJIS_0208 и EUCJ_0208
//! \author  Kovalenko Dmitry
//! \date    30.09.2008
#ifndef _ibp_cs_jis_traits_H_
#define _ibp_cs_jis_traits_H_

#include "source/db_obj/db_charset.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

class t_ibp_cs_jis_0208_traits_base;

class t_ibp_cs_sjis_0208_traits;

class t_ibp_cs_eucj_0208_traits;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_jis_0208_traits_base

/// <summary>
///  Класс с таблицами преобразования кодовой страницы JIS-0208
/// </summary>
class t_ibp_cs_jis_0208_traits_base
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned short                    ushort_type;
  typedef unsigned char                     uchar_type;
  typedef size_t                            size_type;

 protected:
  ///Массив секций с отображениями JIS на UCS2
  static const ushort_type* const sm_jis__to_unicode_mapping_array;

  ///Количество элементов в from_unicode_mapping_array
  static const size_type          sm_jis__to_unicode_mapping_array_size;

  ///Индекс секций to_unicode_mapping_array
  static const ushort_type* const sm_jis__to_unicode_map;

  ///Количество элементов в to_unicode_map
  static const size_type          sm_jis__to_unicode_map_size;

  ///Массив секций с отображениями UCS2 на JIS
  static const ushort_type* const sm_jis__from_unicode_mapping_array;

  ///Количество элементов в from_unicode_mapping_array
  static const size_type          sm_jis__from_unicode_mapping_array_size;

  ///Индекс секций from_unicode_mapping_array
  static const ushort_type* const sm_jis__from_unicode_map;

  ///Количество элементов в from_unicode_map
  static const size_type          sm_jis__from_unicode_map_size;
};//t_ibp_cs_jis_0208_traits_base

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_sjis_0208_traits

/// <summary>
///  Алгоритмы преобразования кодовой страницы SJIS_0208
/// </summary>
//! \note Из-за проблем с BCB5 публичные методы этого класса были
//!       переделаны из статических в собственные константные.
class t_ibp_cs_sjis_0208_traits:public t_ibp_cs_jis_0208_traits_base
{
 private:
  typedef t_ibp_cs_sjis_0208_traits                  self_type;

 public: //consts --------------------------------------------------------
  ///минимальный размер символа кодовой страницы
  static const size_t c_char_size__min=sizeof(uchar_type);

  ///максимальный размер символа кодовой страницы
  static const size_t c_char_size__max=sizeof(ushort_type);

  ///максимальное количество UCS2 (wchar_t) символов для представления одного UNICODE символа
  static const size_t c_max_ucs2_in_one_char=1;

 public:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  t_ibp_cs_sjis_0208_traits(){;}

  /// <summary>
  ///  Conversion of single OWN symbol into UNICODE symbol
  /// </summary>
  //! \param[in,out] source
  //! \param[in]     source_end
  //! \param[out]    result_buffer
  //! \param[in,out] result_size
  //! \return
  //!  - db_cs_result__ok
  //!  - db_cs_result__fail
  //!  - db_cs_result__input_trunc
  //!  - db_cs_result__trunc
  template<typename InputIterator>
  db_obj::t_db_cs_result
   convert_single_own_to_unicode_v3
    (InputIterator& source,
     InputIterator  source_end,
     wchar_t*       result_buffer,
     size_t&        result_size)const;

  /// <summary>
  ///  Conversion of single UNICODE symbol to OWN symbol
  /// </summary>
  //! \param[in,out] source
  //! \param[in]     source_end
  //! \param[out]    result_buffer
  //! \param[in,out] result_size
  //! \return
  //!  - db_cs_result__ok
  //!  - db_cs_result__fail
  //!  - db_cs_result__trunc
  template<typename InputIterator>
  db_obj::t_db_cs_result
   convert_single_unicode_to_own_v3
    (InputIterator& source,
     InputIterator  source_end,
     char*          result_buffer,
     size_t&        result_size)const;

  /// <summary>
  ///  Generic algorithm for translation of UNICODE chars into own codepage
  /// </summary>
  //! \param[in,out] source
  //! \param[in]     source_end
  //! \param[in]     dest
  template<typename InputIterator,typename OutputIterator>
  db_obj::t_db_cs_result
   ucs2_to_own
    (InputIterator&  source,
     InputIterator   source_end,
     OutputIterator  dest)const;

 private:
  static bool IsAsciiCh(uchar_type x)
   {return (x&0x80)==0;}

  static bool IsSjisSingleCh(uchar_type x)
   {return 0xa0<=x && x<=0xdf;}

  static bool IsValidCh_1(uchar_type x)
   {return (0x80<=x && x<=0x9f) || (0xe0<=x && x<=0xef);}

  static bool IsValidCh_2(uchar_type x)
   {return 0x40<=x && x<=0xfc;}

  //! \brief FB Algorithm
  //! \param[in]  s1
  //! \param[in]  s2
  //! \param[out] j1
  //! \param[out] j2
  static void S2E(uchar_type s1,uchar_type s2,uchar_type* j1,uchar_type* j2);

  //----
  static bool IsODD(ushort_type x)
   {return (x%2)!=0;}

  //! \brief FB Algorithm
  //! \param[in,out] s1
  //! \param[in,out] s2
  static void Seven2Eight(uchar_type* s1,uchar_type* s2);

 private:
  ///Массив секций с отображениями UCS2 на SJIS
  static const ushort_type* const sm_sjis__to_unicode_mapping_array;

  ///Количество элементов в from_unicode_mapping_array
  static const size_type          sm_sjis__to_unicode_mapping_array_size;

  ///Индекс секций to_unicode_mapping_array
  static const ushort_type* const sm_sjis__to_unicode_map;

  ///Количество элементов в to_unicode_map
  static const size_type          sm_sjis__to_unicode_map_size;

  ///Массив секций с отображениями UCS2 на SJIS
  static const ushort_type* const sm_sjis__from_unicode_mapping_array;

  ///Количество элементов в from_unicode_mapping_array
  static const size_type          sm_sjis__from_unicode_mapping_array_size;

  ///Индекс секций from_unicode_mapping_array
  static const ushort_type* const sm_sjis__from_unicode_map;

  ///Количество элементов в from_unicode_map
  static const size_type          sm_sjis__from_unicode_map_size;
};//class t_ibp_cs_sjis_0208_traits

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_eucj_0208_traits

/// <summary>
///  Алгоритмы преобразования кодовой страницы EUCJ_0208
/// </summary>
//! \note Из-за проблем с BCB5 публичные методы этого класса были
//!       переделаны из статических в собственные константные.
class t_ibp_cs_eucj_0208_traits:public t_ibp_cs_jis_0208_traits_base
{
 private:
  typedef t_ibp_cs_eucj_0208_traits                  self_type;

 public: //consts --------------------------------------------------------
  ///минимальный размер символа кодовой страницы
  static const size_t c_char_size__min=sizeof(uchar_type);

  ///максимальный размер символа кодовой страницы
  static const size_t c_char_size__max=sizeof(ushort_type);

  ///максимальное количество UCS2 (wchar_t) символов для представления одного UNICODE символа
  static const size_t c_max_ucs2_in_one_char=1;

 public:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  t_ibp_cs_eucj_0208_traits(){;}

  /// <summary>
  ///  Conversion of single OWN symbol into UNICODE symbol
  /// </summary>
  //! \param[in,out] source
  //! \param[in]     source_end
  //! \param[out]    result_buffer
  //! \param[in,out] result_size
  //! \return
  //!  - db_cs_result__ok
  //!  - db_cs_result__fail
  //!  - db_cs_result__input_tranc
  //!  - db_cs_result__tranc
  template<typename InputIterator>
  db_obj::t_db_cs_result
   convert_single_own_to_unicode_v3
    (InputIterator& source,
     InputIterator  source_end,
     wchar_t*       result_buffer,
     size_t&        result_size)const;

  /// <summary>
  ///  Conversion of single UNICODE symbol to OWN symbol
  /// </summary>
  //! \param[in,out] source
  //! \param[in]     source_end
  //! \param[out]    result_buffer
  //! \param[in,out] result_size
  //! \return
  //!  - db_cs_result__ok
  //!  - db_cs_result__fail
  //!  - db_cs_result__trunc
  template<typename InputIterator>
  db_obj::t_db_cs_result
   convert_single_unicode_to_own_v3
    (InputIterator& source,
     InputIterator  source_end,
     char*          result_buffer,
     size_t&        result_size)const;

  /// <summary>
  ///  Generic algorithm for translation of UNICODE chars into own codepage
  /// </summary>
  //! \param[in,out] source
  //! \param[in]     source_end
  //! \param[in]     dest
  template<typename InputIterator,typename OutputIterator>
  db_obj::t_db_cs_result
   ucs2_to_own
    (InputIterator&  source,
     InputIterator   source_end,
     OutputIterator  dest)const;

 private:
  static bool IsSingleCh(uchar_type x)
   {return (x&0x80)==0;}

  static bool IsValidCh_1(uchar_type x)
   {return (x&0x80)!=0;}

  static bool IsValidCh_2(uchar_type x)
   {return (x&0x80)!=0;}
};//class t_ibp_cs_eucj_0208_traits

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/cs_code/ibp_cs_jis_traits.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
