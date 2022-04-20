////////////////////////////////////////////////////////////////////////////////
//Классы для хранения указателей на объектные обработчики событий
//Структура классов зависит от возможностей компилятора, поэтому
//будет создано несколько наборов реализаций.
//                                      Коваленко Дмитрий. 5 мая 2001 года.

#ifndef _t_closure_H_
#define _t_closure_H_

////////////////////////////////////////////////////////////////////////////////
#if !defined(__COMP_ID_CURRENT)
# error "Unknown compiler"
#endif

#if   (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V70)
# include <structure/closure/v01/t_closure_v1.h>
#elif (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V80)
# include <structure/closure/v01/t_closure_v1.h>
#elif (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V90)
# include <structure/closure/v01/t_closure_v1.h>
#elif (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V100)
# include <structure/closure/v02/t_closure_v2.h>
#elif (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V110)
# include <structure/closure/v02/t_closure_v2.h>
#elif (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V120)
# include <structure/closure/v03/t_closure_v3.h>
#elif (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V140)
# include <structure/closure/v03/t_closure_v3.h>
#elif (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER7)
# include <structure/closure/v01/t_closure_v1.h>
#elif (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER6)
# include <structure/closure/v01/t_closure_v1.h>
#elif (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER5)
# include <structure/closure/v01/t_closure_v1.h>
#elif (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER3)
# include <structure/closure/v01/t_closure_v1.h>
#else
# error "Unknown compiler"
#endif

////////////////////////////////////////////////////////////////////////////////
#endif
