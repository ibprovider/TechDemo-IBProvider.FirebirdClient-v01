////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_forward.h
//! \brief   Forward declarations of IBProvider components
//! \author  Kovalenko Dmitry
//! \date    14.11.2003
#ifndef _ibp_forward_H_
#define _ibp_forward_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/oledb/props2/ibp_oledb__props2__forward.h"

#include <structure/storage/t_ss_data_page_manager__forward.h>
#include <structure/t_smart_object.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
#ifndef IBP_ENGINE_UPDATE_ROWSET
# error "IBP_ENGINE_UPDATE_ROWSET not defined"
#endif
////////////////////////////////////////////////////////////////////////////////
using structure::t_smart_object_ptr;

////////////////////////////////////////////////////////////////////////////////
//connection settings

class t_ibp_data_settings;

////////////////////////////////////////////////////////////////////////////////
//operation context

class t_ibp_operation_context;
class t_ibp_operation_context_std;

////////////////////////////////////////////////////////////////////////////////
//errors

class t_ibp_error_adapter;

class t_ibp_error_element;

class t_ibp_error_records_r;

class t_ibp_error;

////////////////////////////////////////////////////////////////////////////////

class IBP_GlobalObjectsData__Meta;

////////////////////////////////////////////////////////////////////////////////

class IBP_SqlParameterName;

////////////////////////////////////////////////////////////////////////////////
//column object

class IBP_ColumnData;

class IBP_ColumnCvtData;

class IBP_ColumnAggregatorDescr;

////////////////////////////////////////////////////////////////////////////////
//field data

class TIBP_FieldData;

////////////////////////////////////////////////////////////////////////////////

class TIBPParamMarkerData;

////////////////////////////////////////////////////////////////////////////////

class TIBP_ValueData;

////////////////////////////////////////////////////////////////////////////////

namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//connection objects

class IBP_OLEDB__DataSource;

class IBP_OLEDB__ConnectData;

class IBP_OLEDB__ConnectionResource;

class IBP_DataSourceState__Opened;

////////////////////////////////////////////////////////////////////////////////
//transaction objects

class IBP_OLEDB__Session;

////////////////////////////////////////////////////////////////////////////////
//command objects

class IBP_OLEDB__Command;

class IBP_OLEDB__ParametersData;

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb

////////////////////////////////////////////////////////////////////////////////

class t_ibp_transaction;
typedef t_smart_object_ptr<t_ibp_transaction>        t_ibp_transaction_ptr;

class t_ibp_command;
typedef t_smart_object_ptr<t_ibp_command>            t_ibp_command_ptr;

class t_ibp_command_pobj;
typedef t_smart_object_ptr<t_ibp_command_pobj>         t_ibp_command_pobj_ptr;
typedef t_smart_object_ptr<const t_ibp_command_pobj>   t_ibp_command_pobj_const_ptr;

class t_ibp_command_ptext;
typedef t_smart_object_ptr<t_ibp_command_ptext>        t_ibp_command_ptext_ptr;
typedef t_smart_object_ptr<const t_ibp_command_ptext>  t_ibp_command_ptext_const_ptr;

class t_ibp_command_pstmt;
typedef t_smart_object_ptr<t_ibp_command_pstmt>      t_ibp_command_pstmt_ptr;

class t_ibp_command_pobjs;
typedef t_smart_object_ptr<t_ibp_command_pobjs>      t_ibp_command_pobjs_ptr;

class t_ibp_command_pstmt_params_info__proxy;

class t_ibp_command_pstmt_params_data;

////////////////////////////////////////////////////////////////////////////////
//SQL

class t_ibp_sql_keyword;

class t_ibp_sql_parser_settings_sign;

////////////////////////////////////////////////////////////////////////////////
//Structured Storage. Data Page Manager

class TIBP_SS_DataPageManagerTraits;

typedef structure::t_ss_data_page_manager<TIBP_SS_DataPageManagerTraits>
 TIBP_SS_DataPageManager;

////////////////////////////////////////////////////////////////////////////////

class TIBP_SS_Storage;

////////////////////////////////////////////////////////////////////////////////

class IBP_OleDbPropQueryParams;

////////////////////////////////////////////////////////////////////////////////
//Updatable Rowsets

namespace oledb{namespace rowset{namespace rw{
////////////////////////////////////////////////////////////////////////////////

class TIBP_RW_FieldCollection;

class TIBP_RW_ColumnDescrContainer;

#if(IBP_ENGINE_UPDATE_ROWSET!=0)

class TIBP_RW_AutoGenKeyRules;

#endif //IBP_ENGINE_UPDATE_ROWSET!=0

////////////////////////////////////////////////////////////////////////////////
}/*nms rw*/}/*nms rowset*/}/*nms oledb*/

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
