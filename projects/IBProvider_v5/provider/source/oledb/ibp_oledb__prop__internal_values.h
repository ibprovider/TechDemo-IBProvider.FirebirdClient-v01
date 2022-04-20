////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb
//! \file    ibp_oledb__prop__internal_values.h
//! \brief   Определение внутренних значений OLEDB-свойств провайдера
//! \author  Kovalenko Dmitry
//! \date    20.01.2020
#ifndef _ibp_oledb__prop__internal_values_H_
#define _ibp_oledb__prop__internal_values_H_

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_props
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Шифрование.
/// </summary>
enum class ibp_ipropval__remote__wire_crypt
{
 default_ = 0,

 disabled = 1,
 enabled  = 2,
 required = 3,
};//enum class ibp_ipropval__remote_wire_crypt

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Сжатие.
/// </summary>
enum class ibp_ipropval__remote__wire_compression
{
 default_ = 0,

 disabled = 1,
 enabled  = 2,
 required = 3,
};//enum class ibp_ipropval__remote__wire_compression

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
