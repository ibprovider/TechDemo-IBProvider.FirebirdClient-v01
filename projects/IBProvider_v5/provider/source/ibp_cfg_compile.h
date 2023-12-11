////////////////////////////////////////////////////////////////////////////////
//Конфигурация компиляции модуля
//                                              Коваленко Дмитрий. 05.06.2006.
#ifndef _ibp_cfg_compile_H_
#define _ibp_cfg_compile_H_

#include "source/ibp_cfg_compile__platform_ids.h"
#include "source/ibp_cfg_compile__byte_order.h"
#include "source/ibp_cfg_compile__edition_ids.h"

////////////////////////////////////////////////////////////////////////////////
//Настройки компиляции
//
// IBP_BUILD_TESTCODE
//  - если определен, то исходные тексты провайдера используются для
//    компиляции внешнего теста
//
// IBP_EDITION_ID
//  - идентификатор редакции провайдера
//
// _IBP_BUILD__CREATE_TRACE_CODE
//  - если определен, то идет генерация трассировочной сборки провайдера
//
// _IBP_BUILD__TRACE_ISC_API_CALL
//  - если определен, то будет генерироваться код для трассировки вызовов ISC API

////////////////////////////////////////////////////////////////////////////////
//IBProvider Platform ID

#ifndef IBP_PLATFORM_ID
# error "IBP_PLATFORM_ID not defined"
#endif

////////////////////////////////////////////////////////////////////////////////
//IBProvider Edition ID

#ifndef IBP_EDITION_ID
# error "IBP_EDITION_ID not defined"
#endif

////////////////////////////////////////////////////////////////////////////////

#ifndef IBP_BINARY_COMPILER_SIGN
# error "IBP_BINARY_COMPILER_SIGN is not defined"
#endif

////////////////////////////////////////////////////////////////////////////////

#ifndef IBP_BINARY_CONFIGURATION_SIGN
# error "IBP_BINARY_CONFIGURATION_SIGN is not defined"
#endif

////////////////////////////////////////////////////////////////////////////////
//IBP_CFG_HAS_MODULE_CONFIG
//  - модуль имеет ресурс с конфигурацией
//
//IBP_CFG_GUARD_FPU_CW
//  - компиляция защиты состояния управляющего слова FPU
//
//IBP_ENGINE_UPDATE_ROWSET
//  - включить поддержку обновляемых множеств
//
//IBP_ENGINE_META_DATA_READER
//  - [0,1] include metadata reader
//
//IBP_ENGINE_PREPARE_SERVICES
//  - [0,1] include prepare services
//
//IBP_ENGINE_DB_INFO_SERVICES
//  - [0,1] include db info services
//
//IBP_ENGINE_BLOB_SERVICES
//  - [0,1] include blob services
//
//IBP_ENGINE_GLOBAL_OBJECTS
//  - [0,1] build a global objects manager.
//

// определение типа компилятора
# define IBP_COMP_ID_VISUALC             0x00020000

# if defined(_MSC_VER)
#  define IBP_COMP_ID_CURRENT            IBP_COMP_ID_VISUALC
# endif

# if !defined(IBP_COMP_ID_CURRENT)
#  error "Unknown compiler"
# endif

# if(IBP_COMP_ID_CURRENT==IBP_COMP_ID_VISUALC)
#  define IBP_CFG_HAS_MODULE_CONFIG                        0
#  define IBP_CFG_GUARD_FPU_CW                             0
# else
#  error "Unexpected compiler"
# endif

////////////////////////////////////////////////////////////////////////////////
//Engine properties

#if   (IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)
# define IBP_BINARY_PLATFORM_SIGN                          w32
#elif (IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)
# define IBP_BINARY_PLATFORM_SIGN                          w64
#else
# error Unknown IBP_PLATFORM_ID
#endif

#ifndef IBP_ENGINE_PREPARE_SERVICES
# define IBP_ENGINE_PREPARE_SERVICES                       1
#endif

#ifndef IBP_ENGINE_DB_INFO_SERVICES
# define IBP_ENGINE_DB_INFO_SERVICES                       1
#endif

#ifndef IBP_ENGINE_BLOB_SERVICES
# define IBP_ENGINE_BLOB_SERVICES                          1
#endif

#ifndef IBP_ENGINE_GLOBAL_OBJECTS
# define IBP_ENGINE_GLOBAL_OBJECTS                         1
#endif

//------------------------------------------------------------------------

#if   (IBP_EDITION_ID==IBP_EDITION_ID__PROF) //-------------------- PROF

# define IBP_BINARY_EDITION_SIGN                           prof

#ifndef IBP_ENGINE_UPDATE_ROWSET
# define IBP_ENGINE_UPDATE_ROWSET                          1
#endif

# define IBP_ENGINE_BMK_SIZE                               8
# define IBP_ENGINE_DIRECT_FB                              1

#ifndef IBP_ENGINE_META_DATA_READER
# define IBP_ENGINE_META_DATA_READER                       1
#endif

#elif (IBP_EDITION_ID==IBP_EDITION_ID__FREE) //-------------------- FREE

# define IBP_BINARY_EDITION_SIGN                           free

#ifndef IBP_ENGINE_UPDATE_ROWSET
# define IBP_ENGINE_UPDATE_ROWSET                          0
#endif

# define IBP_ENGINE_BMK_SIZE                               8
# define IBP_ENGINE_DIRECT_FB                              1

#ifndef IBP_ENGINE_META_DATA_READER
# define IBP_ENGINE_META_DATA_READER                       0
#endif

#elif (IBP_EDITION_ID==IBP_EDITION_ID__LITE) //-------------------- LITE

# define IBP_BINARY_EDITION_SIGN                           lite

#ifndef IBP_ENGINE_UPDATE_ROWSET
# define IBP_ENGINE_UPDATE_ROWSET                          0
#endif

# define IBP_ENGINE_BMK_SIZE                               sizeof(HROW)
# define IBP_ENGINE_DIRECT_FB                              1

#ifndef IBP_ENGINE_META_DATA_READER
# define IBP_ENGINE_META_DATA_READER                       1
#endif

#else //----------------------------------------------------------- UNEXTECTED

# error "Unknown IBP_EDITION_ID"

#endif

//------------------------------------------------------------------------

#define IBP_ENGINE_EXECUTE_MULTIPLE_STMTS                  1

//------------------------------------------------------------------------
//Поддержка набора специфических свойств на уровне схем метаданных

#define IBP_SCHEMA_ROWSET__HAS_EXT_PROPS                   0

//------------------------------------------------------------------------
//Поддержка набора специфических свойств в наборе с описаниями колонок

#define IBP_COLUMNS_ROWSET__HAS_EXT_PROPS                  0

////////////////////////////////////////////////////////////////////////////////
//Определение макросов, используемых для защиты состояния FPU

#if(IBP_CFG_GUARD_FPU_CW)
# include "source/ibp_fpu_cw_guard.h"

# define IBP_FPU_GUARG_IN_PROLOG()                                           \
  ibp::t_fpu_cw_guard const __ole_lib_imethod_guard_fpcw

# define IBP_FPU_GUARG_IN_EXTERNAL_CALL()                                    \
  ibp::t_fpu_cw_guard_external_call const __fpucw_restore

# define IBP_FPU_GUARD_IN_ENTRY_POINT_PROLOG(dwReason)                       \
  ibp::t_fpu_cw_guard const                                                  \
   __ole_lib_imethod_guard_fpcw(dwReason==DLL_PROCESS_ATTACH)

#else

# define IBP_FPU_GUARG_IN_PROLOG()

# define IBP_FPU_GUARG_IN_EXTERNAL_CALL()

# define IBP_FPU_GUARD_IN_ENTRY_POINT_PROLOG(dwReason)

#endif //!IBP_CFG_GUARD_FPU_CW

////////////////////////////////////////////////////////////////////////////////
#endif
