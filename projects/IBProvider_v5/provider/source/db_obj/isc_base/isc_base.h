////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_base.h
//! \brief   Forward-����������� �����������, ��������� � ISC-������������ ��
//! \author  Kovalenko Dmitry
//! \date    18.06.2008
#ifndef _isc_base_H_
#define _isc_base_H_

#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////

class t_isc_info_buffer_v1_builder;

class t_isc_param_buffer_v1_builder;
class t_isc_param_buffer_v2_builder;

class t_isc_ods_id;

class t_isc_error_code_descr;
class t_isc_error_code_descr2;

class t_isc_status_vector;
class t_isc_dbms_info;
class t_isc_max_obj_name_len;
class t_isc_connection_settings;

struct t_isc_ods_data__database;

struct t_isc_msg_data_element_descr;

//���������� �������� ��� ������ xrow ------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_isc_meta_svc__xsqlvar_v1);
IBP_DEF_FWRD_DB_INTERFACE(t_isc_meta_svc__xsqlvar_v2);

IBP_DEF_FWRD_DB_INTERFACE(t_isc_meta_svc__sqlvalue_v1);

//��������� ��� �������������� ������ SQL ������� ------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_stmt_text_translator);

//��������� ��� �������� �������� ----------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_api_svc__array_reader);

//��������� ��� �������� �������� ----------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_api_svc__array_writer);

//��������� ��� �������� ���������� BLOB ---------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_api_svc__blob_reader_factory);

//��������� ��� �������� �������� BLOB -----------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_api_svc__blob_writer_factory);

//��������� ������� ��� ������ �������� ----------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_api_svc__cancel_statement);

//��������� ��� ��������� �������� ����������� ---------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_svc__get_connection_settings);

//��������� ������ ��� ������������ SUSPEND � ���������� �������� ���������

IBP_DEF_FWRD_DB_INTERFACE(t_isc_meta_svc__sp_suspend_detecter);

//������������� ������� ��� ������ SUSPEND � BLR �������� ���������
extern const db_obj::t_db_svc_descr
 isc_meta_svc_descr__sp_suspend_detecter__blr;

//������������� ������� ��� ������ SUSPEND � SRC �������� ���������
extern const db_obj::t_db_svc_descr
 isc_meta_svc_descr__sp_suspend_detecter__src;

////////////////////////////////////////////////////////////////////////////////

IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_xsqlda_v1_svc__msg_blr01_builder);

IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_xsqlda_v1_svc__msg_data_descrs_builder);

IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_xsqlda_v1_svc__msg_data);

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/

////////////////////////////////////////////////////////////////////////////////

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_stmt_text_translator)

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_api_svc__array_reader)
IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_api_svc__array_writer)

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_api_svc__blob_reader_factory)
IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_api_svc__blob_writer_factory)

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_api_svc__cancel_statement)

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_svc__get_connection_settings)

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_xsqlda_v1_svc__msg_blr01_builder)
IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_xsqlda_v1_svc__msg_data_descrs_builder)
IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_xsqlda_v1_svc__msg_data)

////////////////////////////////////////////////////////////////////////////////
#endif
