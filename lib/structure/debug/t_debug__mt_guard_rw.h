////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                Dmitry Kovalenko. 30.09.2019.
#ifndef _t_debug__mt_guard_rw_H_
#define _t_debug__mt_guard_rw_H_

#include <lcpi/lib/structure/debug/t_debug__mt_guard_rw.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG
#error "Incorect usage"
#endif

////////////////////////////////////////////////////////////////////////////////

using lcpi::lib::structure::debug::t_debug__mt_guard_rw;
using lcpi::lib::structure::debug::t_debug__mt_guard_rw_lock_r;
using lcpi::lib::structure::debug::t_debug__mt_guard_rw_lock_w;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
