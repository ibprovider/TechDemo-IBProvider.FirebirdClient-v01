////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Configuration.
//                                               Dmitry Kovalenko. 30.09.2020.
#ifndef _cpp_public_lcpi_config__config_compiler_H_
#define _cpp_public_lcpi_config__config_compiler_H_

////////////////////////////////////////////////////////////////////////////////
//Definitions
//
// LCPI_CPP_CFG__METHOD__OVERRIDE
//
// LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL
//
// LCPI_CPP_CFG__CLASS__FINAL
//
// LCPI_CPP_CFG__DECLSPEC__NORETURN
//
////////////////////////////////////////////////////////////////////////////////
//Known compiler IDs

#define LCPI_CPP_COMP_ID__VISUALC_V120         0x400000C0
#define LCPI_CPP_COMP_ID__VISUALC_V140         0x400000D0

////////////////////////////////////////////////////////////////////////////////
//Detect compiler ID

#if !defined(LCPI_CPP_COMP_ID__CURRENT)

# if defined(_MSC_VER)

#  if   (_MSC_VER>=1900)
#    define LCPI_CPP_COMP_ID__CURRENT                   LCPI_CPP_COMP_ID__VISUALC_V140
#  elif (_MSC_VER>=1800)
#    define LCPI_CPP_COMP_ID__CURRENT                   LCPI_CPP_COMP_ID__VISUALC_V120
#  else (_MSC_VER>=1700)
#    error Unsupported VC++ compiler
#  endif

# endif

# if !defined(LCPI_CPP_COMP_ID__CURRENT)
#  error Unknown Compiler
# endif

#endif //!defined(LCPI_CPP_COMP_ID__CURRENT)

////////////////////////////////////////////////////////////////////////////////
//Config for current compiler

//VC140 ------------------------------------------------------------------
#if (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V140)

# include <lcpi/config/compiler/.config_compiler__vc14.h>

#endif //LCPI_CPP_COMP_ID__VISUALC_V140

//VC120 ------------------------------------------------------------------
#if (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V120)

# include <lcpi/config/compiler/.config_compiler__vc12.h>

#endif //LCPI_CPP_COMP_ID__VISUALC_V120

////////////////////////////////////////////////////////////////////////////////
//Verifications

#ifndef LCPI_CPP_CFG__METHOD__OVERRIDE
# error LCPI_CPP_CFG__METHOD__OVERRIDE not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL
# error LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_CPP_CFG__CLASS__FINAL
# error LCPI_CPP_CFG__CLASS__FINAL not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_CPP_CFG__DECLSPEC__NORETURN
# error LCPI_CPP_CFG__DECLSPEC__NORETURN not defined
#endif

////////////////////////////////////////////////////////////////////////////////
#endif
