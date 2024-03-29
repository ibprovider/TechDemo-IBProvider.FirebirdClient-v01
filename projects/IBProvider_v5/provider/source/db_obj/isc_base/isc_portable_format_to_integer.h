////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_portable_format_to_integer.h
//! \brief   Функции для работы с транспортным форматом INT-значений
//! \author  Kovalenko Dmitry
//! \date    23.04.2015
#ifndef _isc_portable_format_to_integer_H_
#define _isc_portable_format_to_integer_H_

#include "source/ibp_subsystem_ids.h"
#include <lcpi/lib/structure/t_value_with_null.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////

bool isc_portable_integer__is_zero(size_t      sz,
                                   const void* pv);

////////////////////////////////////////////////////////////////////////////////
//class isc_portable_format_to_integer

class isc_portable_format_to_integer LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=isc_portable_format_to_integer;

 public: //UNSIGNED NUMERIC
  static bool exec_r(size_t            sz,
                     const void*       pv,
                     unsigned __int16* result);

  static bool exec_r(size_t            sz,
                     const void*       pv,
                     unsigned __int32* result);

  static bool exec_r(size_t            sz,
                     const void*       pv,
                     unsigned __int64* result);

  static bool exec_r(size_t            sz,
                     const void*       pv,
                     unsigned long*    result);

 public: //SIGNED NUMERIC
  static bool exec_r(size_t            sz,
                     const void*       pv,
                     signed __int16*   result);

  static bool exec_r(size_t            sz,
                     const void*       pv,
                     signed __int32*   result);

  static bool exec_r(size_t            sz,
                     const void*       pv,
                     signed __int64*   result);

  static bool exec_r(size_t            sz,
                     const void*       pv,
                     signed long*      result);

 public:
  static bool exec_r
               (size_t                                               sz,
                const void*                                          pv,
                lib::structure::t_value_with_null<unsigned __int16>* result);

  static bool exec_r
               (size_t                                               sz,
                const void*                                          pv,
                lib::structure::t_value_with_null<unsigned __int32>* result);

  static bool exec_r
               (size_t                                               sz,
                const void*                                          pv,
                lib::structure::t_value_with_null<unsigned __int64>* result);

  static bool exec_r
               (size_t                                               sz,
                const void*                                          pv,
                lib::structure::t_value_with_null<unsigned long>*    result);

 public:
  static bool exec_r
               (size_t                                               sz,
                const void*                                          pv,
                lib::structure::t_value_with_null<signed __int16>*   result);

  static bool exec_r
               (size_t                                               sz,
                const void*                                          pv,
                lib::structure::t_value_with_null<signed __int32>*   result);

  static bool exec_r
               (size_t                                               sz,
                const void*                                          pv,
                lib::structure::t_value_with_null<signed __int64>*   result);

  static bool exec_r
               (size_t                                               sz,
                const void*                                          pv,
                lib::structure::t_value_with_null<signed long>*      result);

 public: //UNSIGNED NUMERIC
  static void exec(size_t                   sz,
                   const void*              pv,
                   unsigned __int16*        result,
                   ibp::t_ibp_subsystem_id  subsystem,
                   const wchar_t*           value_sign);

  static void exec(size_t                   sz,
                   const void*              pv,
                   unsigned __int32*        result,
                   ibp::t_ibp_subsystem_id  subsystem,
                   const wchar_t*           value_sign);

  static void exec(size_t                   sz,
                   const void*              pv,
                   unsigned __int64*        result,
                   ibp::t_ibp_subsystem_id  subsystem,
                   const wchar_t*           value_sign);

  static void exec(size_t                   sz,
                   const void*              pv,
                   unsigned long*           result,
                   ibp::t_ibp_subsystem_id  subsystem,
                   const wchar_t*           value_sign);

 public: //SIGNED NUMERIC
  static void exec(size_t                   sz,
                   const void*              pv,
                   signed __int16*          result,
                   ibp::t_ibp_subsystem_id  subsystem,
                   const wchar_t*           value_sign);

  static void exec(size_t                   sz,
                   const void*              pv,
                   signed __int32*          result,
                   ibp::t_ibp_subsystem_id  subsystem,
                   const wchar_t*           value_sign);

  static void exec(size_t                   sz,
                   const void*              pv,
                   signed __int64*          result,
                   ibp::t_ibp_subsystem_id  subsystem,
                   const wchar_t*           value_sign);

  static void exec(size_t                   sz,
                   const void*              pv,
                   signed long*             result,
                   ibp::t_ibp_subsystem_id  subsystem,
                   const wchar_t*           value_sign);

 public:
  static void exec(size_t                                               sz,
                   const void*                                          pv,
                   lib::structure::t_value_with_null<unsigned __int16>* result,
                   ibp::t_ibp_subsystem_id                              subsystem,
                   const wchar_t*                                       value_sign);

  static void exec(size_t                                               sz,
                   const void*                                          pv,
                   lib::structure::t_value_with_null<unsigned __int32>* result,
                   ibp::t_ibp_subsystem_id                              subsystem,
                   const wchar_t*                                       value_sign);

  static void exec(size_t                                               sz,
                   const void*                                          pv,
                   lib::structure::t_value_with_null<unsigned __int64>* result,
                   ibp::t_ibp_subsystem_id                              subsystem,
                   const wchar_t*                                       value_sign);

  static void exec(size_t                                               sz,
                   const void*                                          pv,
                   lib::structure::t_value_with_null<unsigned long>*    result,
                   ibp::t_ibp_subsystem_id                              subsystem,
                   const wchar_t*                                       value_sign);

 public:
  static void exec(size_t                                               sz,
                   const void*                                          pv,
                   lib::structure::t_value_with_null<signed __int16>*   result,
                   ibp::t_ibp_subsystem_id                              subsystem,
                   const wchar_t*                                       value_sign);

  static void exec(size_t                                               sz,
                   const void*                                          pv,
                   lib::structure::t_value_with_null<signed __int32>*   result,
                   ibp::t_ibp_subsystem_id                              subsystem,
                   const wchar_t*                                       value_sign);

  static void exec(size_t                                               sz,
                   const void*                                          pv,
                   lib::structure::t_value_with_null<signed __int64>*   result,
                   ibp::t_ibp_subsystem_id                              subsystem,
                   const wchar_t*                                       value_sign);

  static void exec(size_t                                               sz,
                   const void*                                          pv,
                   lib::structure::t_value_with_null<signed long>*      result,
                   ibp::t_ibp_subsystem_id                              subsystem,
                   const wchar_t*                                       value_sign);

 private:
  template<typename result_type>
  static bool helper__to_integer__generic__unsigned
                (size_t       sz,
                 const void*  pv,
                 result_type* result);

  template<typename result_type>
  static bool helper__to_integerN__generic__unsigned
                (size_t                                          sz,
                 const void*                                     pv,
                 lib::structure::t_value_with_null<result_type>* result);

 private:
  template<typename result_type>
  static bool helper__to_integer__generic__signed
                (size_t       sz,
                 const void*  pv,
                 result_type* result);

  template<typename result_type>
  static bool helper__to_integerN__generic__signed
                (size_t                                          sz,
                 const void*                                     pv,
                 lib::structure::t_value_with_null<result_type>* result);

 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error__bad_format
                             (ibp::t_ibp_subsystem_id subsystem,
                              const wchar_t*          value_sign,
                              const wchar_t*          value_type_sign,
                              size_t                  buf_length);
};//class isc_portable_format_to_integer

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
