////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_parameter_list_parser.h
//! \brief   Класс для обработки списка параметров
//! \author  Kovalenko Dmitry
//! \date    05.12.2018
#ifndef _ibp_parameter_list_parser_H_
#define _ibp_parameter_list_parser_H_

#include "source/ibp_memory.h"
#include <structure/t_parameter_list.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

template<typename charT>
struct IBP_ParameterListParserSelector
{
 typedef structure::t_basic_parameter_list
         <charT,
          IBP_MemoryAllocator>              type;
};//struct IBP_ParameterListParserSelector

////////////////////////////////////////////////////////////////////////////////

typedef IBP_ParameterListParserSelector<wchar_t>::type
 IBP_ParameterListParser_WSTR;

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
