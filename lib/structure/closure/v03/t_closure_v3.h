////////////////////////////////////////////////////////////////////////////////
//������ ��� �������� ���������� �� ��������� ����������� �������
//������ ��������� ���������� �� ������� �� Builder C++
//                                           Kovalenko Dmitry. 12.12.2018.
#ifndef _t_closure_v3_H_
#define _t_closure_v3_H_

#include <lcpi/lib/.config.h>

//������ �������������:
// 1 ����������� ��� ��������� �� ��������� ����������
//    typedef t_closure_r1<void,int> t_on_change;
// 2 ����������� ����������
//    t_on_change on_change;
// 3 �������������� ����������
//    on_change=make_closure_r(&x,TX::handle_change);
//   ���:
//   x - ������ ������ TX
//   TX::handle_change - ����� � ���������� void handle_change(int);
//
// ��� ��������� ������� ������ (__stdcall/__fastcall) ����������
// � t_closure_xxx_caller. ������� t_closure_xxx ������� ������ ��
// ������ ���������� � ������������� ����.

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
