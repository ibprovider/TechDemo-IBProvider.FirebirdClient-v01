////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descr_data__helpers.h
//! \brief   Вспомогательные конструкции для работы с IBP_OLEDB_Props2__DescrData
//! \author  Kovalenko Dmitry
//! \date    13.12.2018
#ifndef _ibp_oledb__props2__descr_data__helpers2_H_
#define _ibp_oledb__props2__descr_data__helpers2_H_

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////

//#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
//                                     PropId,                              \
//                                     PropDescr,                           \
//                                     PropFlags,                           \
//                                     PropRules,                           \
//                                     ListOfAdditionalParams,              \
//                                     POST_INIT_CALLS)                     \
//IBP_OLEDB_Props2__DescrData                                               \
// (InitTag,                                                                \
//  PropDescr,                                                              \
//  PropFlags,                                                              \
//  PropRules,                                                              \
//  ListOfAdditionalParams) POST_INIT_CALLS,

////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_PARAM__I2(PropId,                         \
                                          PropDescr,                      \
                                          PropFlags,                      \
                                          DefaultOpt,                     \
                                          DefaultValue,                   \
                                          POST_INIT_CALLS)                \
 IBP_OLEDB_PROPS2__DESCR_DATA                                             \
  (IBP_OLEDB_Props2__DescrData::tag_init__i2(),                           \
   PropId,                                                                \
   PropDescr,                                                             \
   PropFlags,                                                             \
   0,                                                                     \
   DefaultOpt _LITER_COMMA_                                               \
   DefaultValue,                                                          \
   POST_INIT_CALLS)

////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_PARAM__I2__EMPTY(PropId,                  \
                                                 PropDescr,               \
                                                 PropFlags,               \
                                                 DefaultOpt,              \
                                                 POST_INIT_CALLS)         \
 IBP_OLEDB_PROPS2__DESCR_DATA                                             \
  (IBP_OLEDB_Props2__DescrData::tag_init__empty(),                        \
   PropId,                                                                \
   PropDescr,                                                             \
   PropFlags,                                                             \
   0,                                                                     \
   VT_I2 _LITER_COMMA_                                                    \
   DefaultOpt,                                                            \
   POST_INIT_CALLS)

////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_PARAM__I4(PropId,                         \
                                          PropDescr,                      \
                                          PropFlags,                      \
                                          DefaultOpt,                     \
                                          DefaultValue,                   \
                                          POST_INIT_CALLS)                \
 IBP_OLEDB_PROPS2__DESCR_DATA                                             \
  (IBP_OLEDB_Props2__DescrData::tag_init__i4(),                           \
   PropId,                                                                \
   PropDescr,                                                             \
   PropFlags,                                                             \
   0,                                                                     \
   DefaultOpt _LITER_COMMA_                                               \
   DefaultValue,                                                          \
   POST_INIT_CALLS)

////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_PARAM__I4__EMPTY(PropId,                  \
                                                 PropDescr,               \
                                                 PropFlags,               \
                                                 DefaultOpt,              \
                                                 POST_INIT_CALLS)         \
 IBP_OLEDB_PROPS2__DESCR_DATA                                             \
  (IBP_OLEDB_Props2__DescrData::tag_init__empty(),                        \
   PropId,                                                                \
   PropDescr,                                                             \
   PropFlags,                                                             \
   0,                                                                     \
   VT_I4 _LITER_COMMA_                                                    \
   DefaultOpt,                                                            \
   POST_INIT_CALLS)

////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR(PropId,                       \
                                            PropDescr,                    \
                                            PropFlags,                    \
                                            DefaultOpt,                   \
                                            DefaultValue,                 \
                                            POST_INIT_CALLS)              \
 IBP_OLEDB_PROPS2__DESCR_DATA                                             \
  (IBP_OLEDB_Props2__DescrData::tag_init__wstr(),                         \
   PropId,                                                                \
   PropDescr,                                                             \
   PropFlags,                                                             \
   0,                                                                     \
   DefaultOpt _LITER_COMMA_                                               \
   DefaultValue,                                                          \
   POST_INIT_CALLS)

////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY(PropId,                \
                                                   PropDescr,             \
                                                   PropFlags,             \
                                                   DefaultOpt,            \
                                                   POST_INIT_CALLS)       \
 IBP_OLEDB_PROPS2__DESCR_DATA                                             \
  (IBP_OLEDB_Props2__DescrData::tag_init__empty(),                        \
   PropId,                                                                \
   PropDescr,                                                             \
   PropFlags,                                                             \
   0,                                                                     \
   VT_BSTR _LITER_COMMA_                                                  \
   DefaultOpt,                                                            \
   POST_INIT_CALLS)

////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL(PropId,                       \
                                            PropDescr,                    \
                                            PropFlags,                    \
                                            DefaultOpt,                   \
                                            DefaultValue,                 \
                                            POST_INIT_CALLS)              \
 IBP_OLEDB_PROPS2__DESCR_DATA                                             \
  (IBP_OLEDB_Props2__DescrData::tag_init__bool(),                         \
   PropId,                                                                \
   PropDescr,                                                             \
   PropFlags,                                                             \
   0,                                                                     \
   DefaultOpt _LITER_COMMA_                                               \
   DefaultValue,                                                          \
   POST_INIT_CALLS)

////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL__EMPTY(PropId,                \
                                                   PropDescr,             \
                                                   PropFlags,             \
                                                   DefaultOpt,            \
                                                   POST_INIT_CALLS)       \
 IBP_OLEDB_PROPS2__DESCR_DATA                                             \
  (IBP_OLEDB_Props2__DescrData::tag_init__empty(),                        \
   PropId,                                                                \
   PropDescr,                                                             \
   PropFlags,                                                             \
   0,                                                                     \
   VT_BOOL _LITER_COMMA_                                                  \
   DefaultOpt,                                                            \
   POST_INIT_CALLS)

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
