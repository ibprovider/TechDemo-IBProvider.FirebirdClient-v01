////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_memory_utils.h
//! \brief   Utilities for work with memory.
//! \author  Kovalenko Dmitry
//! \date    18.04.2023
#ifndef _ibp_memory_utils_H_
#define _ibp_memory_utils_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_Memory_Utils

class IBP_Memory_Utils
{
 private:
  using self_type=IBP_Memory_Utils;

 public:
  /// <summary>
  ///  Выравнивание и добавление к длине буфера
  /// </summary>
  //! \param[in] cbMem
  //!  Текущий размер буфера.
  //! \param[in] cbElement
  //!  Размер данных
  //! \param[in] cbAlign
  //!  Граница выравнивания данных
  //! \param[in,out] pcbResultAlign
  //!  Результирующее значение выравнивания. Can be null.
  //! \return
  //!  Обновленный размер буфера
  static size_t AddMemLength
                 (size_t   cbMem,
                  size_t   cbElement,
                  size_t   cbAlign,
                  size_t*  pcbResultAlign);

  static size_t AddMemLength
                 (size_t cbMem,
                  size_t cbElement);

  static size_t AlignMemLength
                 (size_t   cbMem,
                  size_t   cbAlign,
                  size_t*  pcbResultAlign);
};//class IBP_Memory_Utils

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
