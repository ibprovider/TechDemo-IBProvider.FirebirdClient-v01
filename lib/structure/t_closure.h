////////////////////////////////////////////////////////////////////////////////
//Классы для хранения указателей на объектные обработчики событий
//Структура классов зависит от возможностей компилятора, поэтому
//будет создано несколько наборов реализаций.
//                                      Коваленко Дмитрий. 5 мая 2001 года.

#ifndef _t_closure_H_
#define _t_closure_H_

#include <lcpi/lib/.config.h>

////////////////////////////////////////////////////////////////////////////////
#if !defined(LCPI_CPP_COMP_ID__CURRENT)
# error "Unknown compiler"
#endif

#if   (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V120)
# include <structure/closure/v03/t_closure_v3.h>
#elif (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V140)
# include <structure/closure/v03/t_closure_v3.h>
#elif (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V150)
# include <structure/closure/v03/t_closure_v3.h>
#else
# error "Unknown compiler"
#endif

////////////////////////////////////////////////////////////////////////////////
#endif
