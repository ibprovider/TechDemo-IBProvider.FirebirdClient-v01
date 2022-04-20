////////////////////////////////////////////////////////////////////////////////
//STL configurations. Using Rogue Wave STL implementation.
//                                               Dmitry Kovalenko. 01.08.2003.
#ifndef _config_stl__rw_bcb_H_
#define _config_stl__rw_bcb_H_

////////////////////////////////////////////////////////////////////////////////
//define methods of object destroy in STL-containers

#define _RWSTD_NO_DESTROY_BUILTIN

//_RWSTD_EXPLICIT_SCOPE_DESTROY
//   - pointer->T::~T - simple types not has classes
//_RWSTD_NO_DESTROY_NONBUILTIN
//   - destroy through wrapped class
//_RWSTD_NO_DESTROY_BUILTIN
//   - pointer->~T()
//     [warning for simple types - argument 'pointer' not used]

////////////////////////////////////////////////////////////////////////////////
#include <memory>  //standart implemenation of __destroy and __construct

//add to PCH
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////
//redefine manipulators

#define imanip smanip
#define omanip smanip

////////////////////////////////////////////////////////////////////////////////
#define  __STL_CONSTRUCTOR_FUNC             __construct
#define  __STL_DESTROYER_FUNC               __destroy

#ifndef __RWSTD_NO_NAMESPACE
using __rwstd::__STL_CONSTRUCTOR_FUNC;
using __rwstd::__STL_DESTROYER_FUNC;
#endif

////////////////////////////////////////////////////////////////////////////////
#endif