////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__utils.h
//! \brief   Вспомогательные утилиты
//! \author  Kovalenko Dmitry
//! \date    14.12.2018
#ifndef _ibp_oledb__props2__utils_H_
#define _ibp_oledb__props2__utils_H_

#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Utils

class IBP_OLEDB_Props2__Utils
{
 public:
#ifndef NDEBUG
  static void
   DEBUG__CheckOrder
    (const IBP_OLEDB_Props2__DescrDataRange& DescrDataRange);

  static void
   DEBUG__CheckOrder
    (const IBP_OLEDB_Props2__DescrDataPtrRange& DescrDataPtrRange);
#endif

  static const IBP_OLEDB_Props2__DescrData*
   Find
    (const IBP_OLEDB_Props2__DescrDataRange& DescrDataRange,
     DBPROPID                                propId);

  static const IBP_OLEDB_Props2__DescrData*
   Find
    (const IBP_OLEDB_Props2__DescrDataPtrRange& DescrDataPtrRange,
     DBPROPID                                   propId);

  static bool
   ExtractValue__BSTR
    (const VARIANT& srcVariant,
     VARIANT*       pResult_Variant); //throw

  static bool
   ExtractValue__I2
    (const VARIANT& srcVariant,
     VARIANT*       pResult_Variant); //throw

  static bool
   ExtractValue__I4
    (const VARIANT& srcVariant,
     VARIANT*       pResult_Variant); //throw

 public:
  static const wchar_t*
    GetWmsItem
     (const oledb_lib::tagOLEDB_WMS& wms,
      size_t                         index);

 public:
  /// <summary>
  ///  Тестирование идентификатора набора свойств на принадлежность наборам сессии
  /// </summary>
  //! \param[in] rGuid
  //! \return
  //!  true, если набор определяет свойства сессии
  static bool TestDbPropSetGuid__IsSessionPropSet(REFGUID rGuid);

  /// <summary>
  ///  Тестирование идентификатора набора свойств на принадлежность настройкам
  ///  инициализации источника данных
  /// </summary>
  //! \param[in] rGuid
  //! \return
  //!  true, если набор определяет свойства инициализации источника данных
  static bool TestDbPropSetGuid__IsDbInitPropSet(REFGUID rGuid);  
};//class IBP_OLEDB_Props2__Utils

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
