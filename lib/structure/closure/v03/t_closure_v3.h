////////////////////////////////////////////////////////////////////////////////
//Классы для хранения указателей на объектные обработчики событий
//Аналог объектных указателей на функции из Builder C++
//                                           Kovalenko Dmitry. 12.12.2018.
#ifndef _t_closure_v3_H_
#define _t_closure_v3_H_

#include <lcpi/lib/.config.h>

//способ использования:
// 1 определяете тип указателя на объектный обработчик
//    typedef t_closure_r1<void,int> t_on_change;
// 2 определяете переменную
//    t_on_change on_change;
// 3 устанавливаете обработчик
//    on_change=make_closure_r(&x,TX::handle_change);
//   где:
//   x - объект класса TX
//   TX::handle_change - метод с сигнатурой void handle_change(int);
//
// Вся специфика способа вызова (__stdcall/__fastcall) находиться
// в t_closure_xxx_caller. Поэтому t_closure_xxx зависит только от
// набора аргументов и возвращаемого типа.

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

#include <structure/closure/v03/t_closure_v3__data.hxx>

#include <structure/closure/v03/t_closure_v3__code.hxx>

#include <structure/closure/v03/t_closure_v3__r00.hxx>
#include <structure/closure/v03/t_closure_v3__r01.hxx>
#include <structure/closure/v03/t_closure_v3__r02.hxx>
#include <structure/closure/v03/t_closure_v3__r03.hxx>
#include <structure/closure/v03/t_closure_v3__r04.hxx>
#include <structure/closure/v03/t_closure_v3__r05.hxx>
#include <structure/closure/v03/t_closure_v3__r06.hxx>
#include <structure/closure/v03/t_closure_v3__r07.hxx>
#include <structure/closure/v03/t_closure_v3__r08.hxx>

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
