////////////////////////////////////////////////////////////////////////////////
//Перечисление вариантов порядка байтов и определение текущего порядка
//                                                Kovalenko Dmitry. 01.06.2016
#ifndef _ibp_cfg_compile__byte_order_H_
#define _ibp_cfg_compile__byte_order_H_

////////////////////////////////////////////////////////////////////////////////

#define IBP_BYTE_ORDER__LOW_ENDIAN          1
#define IBP_BYTE_ORDER__BIG_ENDIAN          2

////////////////////////////////////////////////////////////////////////////////

#ifndef IBP_PLATFORM_ID
# error IBP_PLATFORM_ID not defined!
#endif

////////////////////////////////////////////////////////////////////////////////

#if   (IBP_PLATFORM_ID == IBP_PLATFORM_ID__WINNT_AMD64)
# define IBP_BYTE_ORDER IBP_BYTE_ORDER__LOW_ENDIAN
#elif (IBP_PLATFORM_ID == IBP_PLATFORM_ID__WINNT_X86)
# define IBP_BYTE_ORDER IBP_BYTE_ORDER__LOW_ENDIAN
#else
# error Unknown IBP_PLATFORM_ID!
#endif

////////////////////////////////////////////////////////////////////////////////
#endif
