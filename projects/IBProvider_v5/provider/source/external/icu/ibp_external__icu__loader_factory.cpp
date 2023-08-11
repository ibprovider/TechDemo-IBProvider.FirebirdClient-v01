////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/icu/ibp_external__icu__loader_factory.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>

namespace lcpi{namespace ibp{namespace external{namespace icu{
////////////////////////////////////////////////////////////////////////////////

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)
# define DEF_ARG_NAME_IF_AMD64(x) x
#else
# define DEF_ARG_NAME_IF_AMD64(x)
#endif

static t_ibp_string helper__get_icu_library_path
 (const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues,
  REFGUID                                            propSetID,
  DBPROPID                                     const propID__icuLibrary,
  DBPROPID                                     const DEF_ARG_NAME_IF_AMD64(propID__icuLibrary64))
{
 assert(pDsPropValues);

 t_ibp_string icuLibrary;

 for(;;)
 {
  ole_lib::TBaseVariant varPropValue__IcuLibrary;

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)
  /// В случае 64-битной сборки, значение этого свойства является приоритетным.
  if(pDsPropValues->Direct__GetValue(propSetID,propID__icuLibrary64,nullptr,&varPropValue__IcuLibrary))
  {
   /*OK*/

   assert(varPropValue__IcuLibrary.vt==VT_BSTR);
  }
  else
#elif(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)
#else
# error Unknown IBP_PLATFORM_ID!
#endif
  if(pDsPropValues->Direct__GetValue(propSetID,propID__icuLibrary,nullptr,&varPropValue__IcuLibrary))
  {
   /*OK*/

   assert(varPropValue__IcuLibrary.vt==VT_BSTR);
  }//if
  else
  {
   //icu library not defined
   break;
  }//else

  assert(varPropValue__IcuLibrary.vt==VT_BSTR);

  icuLibrary=ole_lib::BStrToUnkStr<t_ibp_char>(varPropValue__IcuLibrary.bstrVal);
  break;
 }//for[ever]

 return icuLibrary;
}//helper__get_icu_library_path

#undef DEF_ARG_NAME_IF_AMD64

////////////////////////////////////////////////////////////////////////////////

ICU__Loader::self_ptr
 create_icu_loader(const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues)
{
 assert(pDsPropValues);

 const t_ibp_string
  icuuс_library_path
   =helper__get_icu_library_path
     (pDsPropValues,
      ibprovider::IBP_DBPROPSET_INIT,
      ibprovider::IBP_DBPROP__INIT__ICU_LIBRARY,
      ibprovider::IBP_DBPROP__INIT__ICU_LIBRARY_64);

 const t_ibp_string
  icuin_library_path
   =helper__get_icu_library_path
     (pDsPropValues,
      ibprovider::IBP_DBPROPSET_INIT,
      ibprovider::IBP_DBPROP__INIT__ICUIN_LIBRARY,
      ibprovider::IBP_DBPROP__INIT__ICUIN_LIBRARY_64);

 return ICU__Loader::create
         (icuuс_library_path,
          icuin_library_path);
}//create_icu_loader

////////////////////////////////////////////////////////////////////////////////
}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
