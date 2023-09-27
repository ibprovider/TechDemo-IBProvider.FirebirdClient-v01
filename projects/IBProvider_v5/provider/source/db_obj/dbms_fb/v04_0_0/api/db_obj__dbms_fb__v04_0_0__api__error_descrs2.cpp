////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v04_0_0__api
//! \file    db_obj__dbms_fb__v04_0_0__api__error_descrs2.cpp
//! \brief   Firebird 4.0 Error Descriptions.
//! \author  Kovalenko Dmitry
//! \date    22.03.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/v04_0_0/api/db_obj__dbms_fb__v04_0_0__api__error_descrs2.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include "rc/ibp_msg_fb40_err_ids.rh"
#include "rc/ibp_msg_fb40.rh"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v04_0_0{namespace api{
////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG

#define CHECK_AND_RETURN_ISC_CODE(_hard_code,_isc_code)  _isc_code

#else

static isc_api::isc_status
 debug__check_and_return_isc_code(isc_api::isc_status const _hard_code,
                                  isc_api::isc_status const _isc_code)
{
 assert(_hard_code==_isc_code);

 return _isc_code;
}//debug__check_and_return_isc_code

#define CHECK_AND_RETURN_ISC_CODE(_hard_code,_isc_code)  \
 debug__check_and_return_isc_code(_hard_code,_isc_code)

#endif

////////////////////////////////////////////////////////////////////////////////

#define MAKE_SQLSTATE(text)                                               \
 text

#define NO_OLEDB_ERR_CODE                                                 \
 isc_base::t_isc_error_code_descr2::c_not_def_oledb_code

#define ADD_CODE(hard_code,                                               \
                 isc_code,                                                \
                 isc_code_symbol,                                         \
                 message_id,                                              \
                 sqlstate,                                                \
                 oledb_code)                                              \
 isc_base::t_isc_error_code_descr2                                        \
  (CHECK_AND_RETURN_ISC_CODE(hard_code,ibp_fb_v40_err__##isc_code),       \
   isc_code_symbol,                                                       \
   MAKE_SQLSTATE(sqlstate),                                               \
   oledb_code,                                                            \
   IBP_MSG_TABLE_FB40_ERR,                                                \
   message_id),

#define ADD_CODE__NONAME(hard_code,                                       \
                         message_id,                                      \
                         sqlstate,                                        \
                         oledb_code)                                      \
 isc_base::t_isc_error_code_descr2                                        \
  (hard_code,                                                             \
   nullptr,                                                               \
   MAKE_SQLSTATE(sqlstate),                                               \
   oledb_code,                                                            \
   IBP_MSG_TABLE_FB40_ERR,                                                \
   message_id),

////////////////////////////////////////////////////////////////////////////////
//Firebird 4.0 Error Descriptions

const isc_base::t_isc_error_code_descr2 g_fb_v04_0_0__error_descrs2[ibp_fb_v40_err__count_of_all_errors]=
{
 // Machine generated code [26.09.2023 20:47:14]

 ADD_CODE         /*1*/
   (335544321L,
    arith_except,
    "arith_except",
    IBP_MCE_FB40__ARITH_EXCEPT,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*2*/
   (335544322L,
    bad_dbkey,
    "bad_dbkey",
    IBP_MCE_FB40__BAD_DBKEY,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*3*/
   (335544323L,
    bad_db_format,
    "bad_db_format",
    IBP_MCE_FB40__BAD_DB_FORMAT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*4*/
   (335544324L,
    bad_db_handle,
    "bad_db_handle",
    IBP_MCE_FB40__BAD_DB_HANDLE,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*5*/
   (335544325L,
    bad_dpb_content,
    "bad_dpb_content",
    IBP_MCE_FB40__BAD_DPB_CONTENT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*6*/
   (335544326L,
    bad_dpb_form,
    "bad_dpb_form",
    IBP_MCE_FB40__BAD_DPB_FORM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*7*/
   (335544327L,
    bad_req_handle,
    "bad_req_handle",
    IBP_MCE_FB40__BAD_REQ_HANDLE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*8*/
   (335544328L,
    bad_segstr_handle,
    "bad_segstr_handle",
    IBP_MCE_FB40__BAD_SEGSTR_HANDLE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*9*/
   (335544329L,
    bad_segstr_id,
    "bad_segstr_id",
    IBP_MCE_FB40__BAD_SEGSTR_ID,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*10*/
   (335544330L,
    bad_tpb_content,
    "bad_tpb_content",
    IBP_MCE_FB40__BAD_TPB_CONTENT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*11*/
   (335544331L,
    bad_tpb_form,
    "bad_tpb_form",
    IBP_MCE_FB40__BAD_TPB_FORM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*12*/
   (335544332L,
    bad_trans_handle,
    "bad_trans_handle",
    IBP_MCE_FB40__BAD_TRANS_HANDLE,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*13*/
   (335544333L,
    bug_check,
    "bug_check",
    IBP_MCE_FB40__BUG_CHECK,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*14*/
   (335544334L,
    convert_error,
    "convert_error",
    IBP_MCE_FB40__CONVERT_ERROR,
    IBP_SQLSTATE__22018__DATA_EXCEPTION_INVALID_CHARACTER_VALUE_FOR_CAST,
    DB_E_CANTCONVERTVALUE)
 ADD_CODE         /*15*/
   (335544335L,
    db_corrupt,
    "db_corrupt",
    IBP_MCE_FB40__DB_CORRUPT,
    IBP_SQLSTATE__XX001__DATA_CORRUPTED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*16*/
   (335544336L,
    deadlock,
    "deadlock",
    IBP_MCE_FB40__DEADLOCK,
    IBP_SQLSTATE__40001__TRANSACTION_ROLLBACK_SERIALIZATION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*17*/
   (335544337L,
    excess_trans,
    "excess_trans",
    IBP_MCE_FB40__EXCESS_TRANS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*18*/
   (335544338L,
    from_no_match,
    "from_no_match",
    IBP_MCE_FB40__FROM_NO_MATCH,
    IBP_SQLSTATE__01000__WARNING_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*19*/
   (335544339L,
    infinap,
    "infinap",
    IBP_MCE_FB40__INFINAP,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*20*/
   (335544340L,
    infona,
    "infona",
    IBP_MCE_FB40__INFONA,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*21*/
   (335544341L,
    infunk,
    "infunk",
    IBP_MCE_FB40__INFUNK,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*22*/
   (335544342L,
    integ_fail,
    "integ_fail",
    IBP_MCE_FB40__INTEG_FAIL,
    IBP_SQLSTATE__27000__TRIGGERED_DATA_CHANGE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*23*/
   (335544343L,
    invalid_blr,
    "invalid_blr",
    IBP_MCE_FB40__INVALID_BLR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*24*/
   (335544344L,
    io_error,
    "io_error",
    IBP_MCE_FB40__IO_ERROR,
    IBP_SQLSTATE__08001__CONNECTION_EXCEPTION_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*25*/
   (335544345L,
    lock_conflict,
    "lock_conflict",
    IBP_MCE_FB40__LOCK_CONFLICT,
    IBP_SQLSTATE__40001__TRANSACTION_ROLLBACK_SERIALIZATION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*26*/
   (335544346L,
    metadata_corrupt,
    "metadata_corrupt",
    IBP_MCE_FB40__METADATA_CORRUPT,
    IBP_SQLSTATE__XX001__DATA_CORRUPTED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*27*/
   (335544347L,
    not_valid,
    "not_valid",
    IBP_MCE_FB40__NOT_VALID,
    IBP_SQLSTATE__23000__INTEGRITY_CONSTRAINT_VIOLATION_NO_SUBCLASS,
    DB_E_INTEGRITYVIOLATION)
 ADD_CODE         /*28*/
   (335544348L,
    no_cur_rec,
    "no_cur_rec",
    IBP_MCE_FB40__NO_CUR_REC,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*29*/
   (335544349L,
    no_dup,
    "no_dup",
    IBP_MCE_FB40__NO_DUP,
    IBP_SQLSTATE__23000__INTEGRITY_CONSTRAINT_VIOLATION_NO_SUBCLASS,
    DB_E_INTEGRITYVIOLATION)
 ADD_CODE         /*30*/
   (335544350L,
    no_finish,
    "no_finish",
    IBP_MCE_FB40__NO_FINISH,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*31*/
   (335544351L,
    no_meta_update,
    "no_meta_update",
    IBP_MCE_FB40__NO_META_UPDATE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*32*/
   (335544352L,
    no_priv,
    "no_priv",
    IBP_MCE_FB40__NO_PRIV,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*33*/
   (335544353L,
    no_recon,
    "no_recon",
    IBP_MCE_FB40__NO_RECON,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*34*/
   (335544354L,
    no_record,
    "no_record",
    IBP_MCE_FB40__NO_RECORD,
    IBP_SQLSTATE__01000__WARNING_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*35*/
   (335544355L,
    no_segstr_close,
    "no_segstr_close",
    IBP_MCE_FB40__NO_SEGSTR_CLOSE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*36*/
   (335544356L,
    obsolete_metadata,
    "obsolete_metadata",
    IBP_MCE_FB40__OBSOLETE_METADATA,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*37*/
   (335544357L,
    open_trans,
    "open_trans",
    IBP_MCE_FB40__OPEN_TRANS,
    IBP_SQLSTATE__01002__WARNING_DISCONNECT_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*38*/
   (335544358L,
    port_len,
    "port_len",
    IBP_MCE_FB40__PORT_LEN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*39*/
   (335544359L,
    read_only_field,
    "read_only_field",
    IBP_MCE_FB40__READ_ONLY_FIELD,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*40*/
   (335544360L,
    read_only_rel,
    "read_only_rel",
    IBP_MCE_FB40__READ_ONLY_REL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*41*/
   (335544361L,
    read_only_trans,
    "read_only_trans",
    IBP_MCE_FB40__READ_ONLY_TRANS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*42*/
   (335544362L,
    read_only_view,
    "read_only_view",
    IBP_MCE_FB40__READ_ONLY_VIEW,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*43*/
   (335544363L,
    req_no_trans,
    "req_no_trans",
    IBP_MCE_FB40__REQ_NO_TRANS,
    IBP_SQLSTATE__25000__INVALID_TRANSACTION_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*44*/
   (335544364L,
    req_sync,
    "req_sync",
    IBP_MCE_FB40__REQ_SYNC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*45*/
   (335544365L,
    req_wrong_db,
    "req_wrong_db",
    IBP_MCE_FB40__REQ_WRONG_DB,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*46*/
   (335544366L,
    segment,
    "segment",
    IBP_MCE_FB40__SEGMENT,
    IBP_SQLSTATE__01000__WARNING_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*47*/
   (335544367L,
    segstr_eof,
    "segstr_eof",
    IBP_MCE_FB40__SEGSTR_EOF,
    IBP_SQLSTATE__01000__WARNING_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*48*/
   (335544368L,
    segstr_no_op,
    "segstr_no_op",
    IBP_MCE_FB40__SEGSTR_NO_OP,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*49*/
   (335544369L,
    segstr_no_read,
    "segstr_no_read",
    IBP_MCE_FB40__SEGSTR_NO_READ,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*50*/
   (335544370L,
    segstr_no_trans,
    "segstr_no_trans",
    IBP_MCE_FB40__SEGSTR_NO_TRANS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*51*/
   (335544371L,
    segstr_no_write,
    "segstr_no_write",
    IBP_MCE_FB40__SEGSTR_NO_WRITE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*52*/
   (335544372L,
    segstr_wrong_db,
    "segstr_wrong_db",
    IBP_MCE_FB40__SEGSTR_WRONG_DB,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*53*/
   (335544373L,
    sys_request,
    "sys_request",
    IBP_MCE_FB40__SYS_REQUEST,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*54*/
   (335544374L,
    stream_eof,
    "stream_eof",
    IBP_MCE_FB40__STREAM_EOF,
    IBP_SQLSTATE__HY109__ODBC__INVALID_CURSOR_POSITION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*55*/
   (335544375L,
    unavailable,
    "unavailable",
    IBP_MCE_FB40__UNAVAILABLE,
    IBP_SQLSTATE__08001__CONNECTION_EXCEPTION_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*56*/
   (335544376L,
    unres_rel,
    "unres_rel",
    IBP_MCE_FB40__UNRES_REL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*57*/
   (335544377L,
    uns_ext,
    "uns_ext",
    IBP_MCE_FB40__UNS_EXT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*58*/
   (335544378L,
    wish_list,
    "wish_list",
    IBP_MCE_FB40__WISH_LIST,
    IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*59*/
   (335544379L,
    wrong_ods,
    "wrong_ods",
    IBP_MCE_FB40__WRONG_ODS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*60*/
   (335544380L,
    wronumarg,
    "wronumarg",
    IBP_MCE_FB40__WRONUMARG,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*61*/
   (335544381L,
    imp_exc,
    "imp_exc",
    IBP_MCE_FB40__IMP_EXC,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*62*/
   (335544382L,
    random,
    "random",
    IBP_MCE_FB40__RANDOM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*63*/
   (335544383L,
    fatal_conflict,
    "fatal_conflict",
    IBP_MCE_FB40__FATAL_CONFLICT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*64*/
   (335544384L,
    badblk,
    "badblk",
    IBP_MCE_FB40__BADBLK,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*65*/
   (335544385L,
    invpoolcl,
    "invpoolcl",
    IBP_MCE_FB40__INVPOOLCL,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*66*/
   (335544386L,
    nopoolids,
    "nopoolids",
    IBP_MCE_FB40__NOPOOLIDS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*67*/
   (335544387L,
    relbadblk,
    "relbadblk",
    IBP_MCE_FB40__RELBADBLK,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*68*/
   (335544388L,
    blktoobig,
    "blktoobig",
    IBP_MCE_FB40__BLKTOOBIG,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*69*/
   (335544389L,
    bufexh,
    "bufexh",
    IBP_MCE_FB40__BUFEXH,
    IBP_SQLSTATE__HY001__ODBC__MEMORY_ALLOCATION_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*70*/
   (335544390L,
    syntaxerr,
    "syntaxerr",
    IBP_MCE_FB40__SYNTAXERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*71*/
   (335544391L,
    bufinuse,
    "bufinuse",
    IBP_MCE_FB40__BUFINUSE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*72*/
   (335544392L,
    bdbincon,
    "bdbincon",
    IBP_MCE_FB40__BDBINCON,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*73*/
   (335544393L,
    reqinuse,
    "reqinuse",
    IBP_MCE_FB40__REQINUSE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*74*/
   (335544394L,
    badodsver,
    "badodsver",
    IBP_MCE_FB40__BADODSVER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*75*/
   (335544395L,
    relnotdef,
    "relnotdef",
    IBP_MCE_FB40__RELNOTDEF,
    IBP_SQLSTATE__42S02__ODBC__BASE_TABLE_OR_VIEW_NOT_FOUND,
    DB_E_NOTABLE)
 ADD_CODE         /*76*/
   (335544396L,
    fldnotdef,
    "fldnotdef",
    IBP_MCE_FB40__FLDNOTDEF,
    IBP_SQLSTATE__42S22__ODBC__COLUMN_NOT_FOUND,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*77*/
   (335544397L,
    dirtypage,
    "dirtypage",
    IBP_MCE_FB40__DIRTYPAGE,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*78*/
   (335544398L,
    waifortra,
    "waifortra",
    IBP_MCE_FB40__WAIFORTRA,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*79*/
   (335544399L,
    doubleloc,
    "doubleloc",
    IBP_MCE_FB40__DOUBLELOC,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*80*/
   (335544400L,
    nodnotfnd,
    "nodnotfnd",
    IBP_MCE_FB40__NODNOTFND,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*81*/
   (335544401L,
    dupnodfnd,
    "dupnodfnd",
    IBP_MCE_FB40__DUPNODFND,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*82*/
   (335544402L,
    locnotmar,
    "locnotmar",
    IBP_MCE_FB40__LOCNOTMAR,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*83*/
   (335544403L,
    badpagtyp,
    "badpagtyp",
    IBP_MCE_FB40__BADPAGTYP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*84*/
   (335544404L,
    corrupt,
    "corrupt",
    IBP_MCE_FB40__CORRUPT,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*85*/
   (335544405L,
    badpage,
    "badpage",
    IBP_MCE_FB40__BADPAGE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*86*/
   (335544406L,
    badindex,
    "badindex",
    IBP_MCE_FB40__BADINDEX,
    IBP_SQLSTATE__XX002__INDEX_CORRUPTED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*87*/
   (335544407L,
    dbbnotzer,
    "dbbnotzer",
    IBP_MCE_FB40__DBBNOTZER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*88*/
   (335544408L,
    tranotzer,
    "tranotzer",
    IBP_MCE_FB40__TRANOTZER,
    IBP_SQLSTATE__25000__INVALID_TRANSACTION_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*89*/
   (335544409L,
    trareqmis,
    "trareqmis",
    IBP_MCE_FB40__TRAREQMIS,
    IBP_SQLSTATE__25000__INVALID_TRANSACTION_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*90*/
   (335544410L,
    badhndcnt,
    "badhndcnt",
    IBP_MCE_FB40__BADHNDCNT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*91*/
   (335544411L,
    wrotpbver,
    "wrotpbver",
    IBP_MCE_FB40__WROTPBVER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*92*/
   (335544412L,
    wroblrver,
    "wroblrver",
    IBP_MCE_FB40__WROBLRVER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*93*/
   (335544413L,
    wrodpbver,
    "wrodpbver",
    IBP_MCE_FB40__WRODPBVER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*94*/
   (335544414L,
    blobnotsup,
    "blobnotsup",
    IBP_MCE_FB40__BLOBNOTSUP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*95*/
   (335544415L,
    badrelation,
    "badrelation",
    IBP_MCE_FB40__BADRELATION,
    IBP_SQLSTATE__XX001__DATA_CORRUPTED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*96*/
   (335544416L,
    nodetach,
    "nodetach",
    IBP_MCE_FB40__NODETACH,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*97*/
   (335544417L,
    notremote,
    "notremote",
    IBP_MCE_FB40__NOTREMOTE,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*98*/
   (335544418L,
    trainlim,
    "trainlim",
    IBP_MCE_FB40__TRAINLIM,
    IBP_SQLSTATE__25000__INVALID_TRANSACTION_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*99*/
   (335544419L,
    notinlim,
    "notinlim",
    IBP_MCE_FB40__NOTINLIM,
    IBP_SQLSTATE__25000__INVALID_TRANSACTION_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*100*/
   (335544420L,
    traoutsta,
    "traoutsta",
    IBP_MCE_FB40__TRAOUTSTA,
    IBP_SQLSTATE__25000__INVALID_TRANSACTION_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*101*/
   (335544421L,
    connect_reject,
    "connect_reject",
    IBP_MCE_FB40__CONNECT_REJECT,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*102*/
   (335544422L,
    dbfile,
    "dbfile",
    IBP_MCE_FB40__DBFILE,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*103*/
   (335544423L,
    orphan,
    "orphan",
    IBP_MCE_FB40__ORPHAN,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*104*/
   (335544424L,
    no_lock_mgr,
    "no_lock_mgr",
    IBP_MCE_FB40__NO_LOCK_MGR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*105*/
   (335544425L,
    ctxinuse,
    "ctxinuse",
    IBP_MCE_FB40__CTXINUSE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*106*/
   (335544426L,
    ctxnotdef,
    "ctxnotdef",
    IBP_MCE_FB40__CTXNOTDEF,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*107*/
   (335544427L,
    datnotsup,
    "datnotsup",
    IBP_MCE_FB40__DATNOTSUP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*108*/
   (335544428L,
    badmsgnum,
    "badmsgnum",
    IBP_MCE_FB40__BADMSGNUM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*109*/
   (335544429L,
    badparnum,
    "badparnum",
    IBP_MCE_FB40__BADPARNUM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*110*/
   (335544430L,
    virmemexh,
    "virmemexh",
    IBP_MCE_FB40__VIRMEMEXH,
    IBP_SQLSTATE__HY001__ODBC__MEMORY_ALLOCATION_ERROR,
    E_OUTOFMEMORY)
 ADD_CODE         /*111*/
   (335544431L,
    blocking_signal,
    "blocking_signal",
    IBP_MCE_FB40__BLOCKING_SIGNAL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*112*/
   (335544432L,
    lockmanerr,
    "lockmanerr",
    IBP_MCE_FB40__LOCKMANERR,
    IBP_SQLSTATE__40001__TRANSACTION_ROLLBACK_SERIALIZATION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*113*/
   (335544433L,
    journerr,
    "journerr",
    IBP_MCE_FB40__JOURNERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*114*/
   (335544434L,
    keytoobig,
    "keytoobig",
    IBP_MCE_FB40__KEYTOOBIG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*115*/
   (335544435L,
    nullsegkey,
    "nullsegkey",
    IBP_MCE_FB40__NULLSEGKEY,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*116*/
   (335544436L,
    sqlerr,
    "sqlerr",
    IBP_MCE_FB40__SQLERR,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*117*/
   (335544437L,
    wrodynver,
    "wrodynver",
    IBP_MCE_FB40__WRODYNVER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*118*/
   (335544438L,
    funnotdef,
    "funnotdef",
    IBP_MCE_FB40__FUNNOTDEF,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*119*/
   (335544439L,
    funmismat,
    "funmismat",
    IBP_MCE_FB40__FUNMISMAT,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*120*/
   (335544440L,
    bad_msg_vec,
    "bad_msg_vec",
    IBP_MCE_FB40__BAD_MSG_VEC,
    IBP_SQLSTATE__22001__DATA_EXCEPTION_STRING_DATA_RIGHT_TRUNCATION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*121*/
   (335544441L,
    bad_detach,
    "bad_detach",
    IBP_MCE_FB40__BAD_DETACH,
    IBP_SQLSTATE__08007__CONNECTION_EXCEPTION_TRANSACTION_RESOLUTION_UNKNOWN,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*122*/
   (335544442L,
    noargacc_read,
    "noargacc_read",
    IBP_MCE_FB40__NOARGACC_READ,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*123*/
   (335544443L,
    noargacc_write,
    "noargacc_write",
    IBP_MCE_FB40__NOARGACC_WRITE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*124*/
   (335544444L,
    read_only,
    "read_only",
    IBP_MCE_FB40__READ_ONLY,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*125*/
   (335544445L,
    ext_err,
    "ext_err",
    IBP_MCE_FB40__EXT_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*126*/
   (335544446L,
    non_updatable,
    "non_updatable",
    IBP_MCE_FB40__NON_UPDATABLE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*127*/
   (335544447L,
    no_rollback,
    "no_rollback",
    IBP_MCE_FB40__NO_ROLLBACK,
    IBP_SQLSTATE__25S02__ODBC__TRANSACTION_IS_STILL_ACTIVE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*128*/
   (335544448L,
    bad_sec_info,
    "bad_sec_info",
    IBP_MCE_FB40__BAD_SEC_INFO,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*129*/
   (335544449L,
    invalid_sec_info,
    "invalid_sec_info",
    IBP_MCE_FB40__INVALID_SEC_INFO,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*130*/
   (335544450L,
    misc_interpreted,
    "misc_interpreted",
    IBP_MCE_FB40__MISC_INTERPRETED,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*131*/
   (335544451L,
    update_conflict,
    "update_conflict",
    IBP_MCE_FB40__UPDATE_CONFLICT,
    IBP_SQLSTATE__40001__TRANSACTION_ROLLBACK_SERIALIZATION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*132*/
   (335544452L,
    unlicensed,
    "unlicensed",
    IBP_MCE_FB40__UNLICENSED,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*133*/
   (335544453L,
    obj_in_use,
    "obj_in_use",
    IBP_MCE_FB40__OBJ_IN_USE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*134*/
   (335544454L,
    nofilter,
    "nofilter",
    IBP_MCE_FB40__NOFILTER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*135*/
   (335544455L,
    shadow_accessed,
    "shadow_accessed",
    IBP_MCE_FB40__SHADOW_ACCESSED,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*136*/
   (335544456L,
    invalid_sdl,
    "invalid_sdl",
    IBP_MCE_FB40__INVALID_SDL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*137*/
   (335544457L,
    out_of_bounds,
    "out_of_bounds",
    IBP_MCE_FB40__OUT_OF_BOUNDS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*138*/
   (335544458L,
    invalid_dimension,
    "invalid_dimension",
    IBP_MCE_FB40__INVALID_DIMENSION,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*139*/
   (335544459L,
    rec_in_limbo,
    "rec_in_limbo",
    IBP_MCE_FB40__REC_IN_LIMBO,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*140*/
   (335544460L,
    shadow_missing,
    "shadow_missing",
    IBP_MCE_FB40__SHADOW_MISSING,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*141*/
   (335544461L,
    cant_validate,
    "cant_validate",
    IBP_MCE_FB40__CANT_VALIDATE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*142*/
   (335544462L,
    cant_start_journal,
    "cant_start_journal",
    IBP_MCE_FB40__CANT_START_JOURNAL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*143*/
   (335544463L,
    gennotdef,
    "gennotdef",
    IBP_MCE_FB40__GENNOTDEF,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*144*/
   (335544464L,
    cant_start_logging,
    "cant_start_logging",
    IBP_MCE_FB40__CANT_START_LOGGING,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*145*/
   (335544465L,
    bad_segstr_type,
    "bad_segstr_type",
    IBP_MCE_FB40__BAD_SEGSTR_TYPE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*146*/
   (335544466L,
    foreign_key,
    "foreign_key",
    IBP_MCE_FB40__FOREIGN_KEY,
    IBP_SQLSTATE__23000__INTEGRITY_CONSTRAINT_VIOLATION_NO_SUBCLASS,
    DB_E_INTEGRITYVIOLATION)
 ADD_CODE         /*147*/
   (335544467L,
    high_minor,
    "high_minor",
    IBP_MCE_FB40__HIGH_MINOR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*148*/
   (335544468L,
    tra_state,
    "tra_state",
    IBP_MCE_FB40__TRA_STATE,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*149*/
   (335544469L,
    trans_invalid,
    "trans_invalid",
    IBP_MCE_FB40__TRANS_INVALID,
    IBP_SQLSTATE__25000__INVALID_TRANSACTION_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*150*/
   (335544470L,
    buf_invalid,
    "buf_invalid",
    IBP_MCE_FB40__BUF_INVALID,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*151*/
   (335544471L,
    indexnotdefined,
    "indexnotdefined",
    IBP_MCE_FB40__INDEXNOTDEFINED,
    IBP_SQLSTATE__42S12__ODBC__INDEX_NOT_FOUND,
    DB_E_NOINDEX)
 ADD_CODE         /*152*/
   (335544472L,
    login,
    "login",
    IBP_MCE_FB40__LOGIN,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    DB_SEC_E_AUTH_FAILED)
 ADD_CODE         /*153*/
   (335544473L,
    invalid_bookmark,
    "invalid_bookmark",
    IBP_MCE_FB40__INVALID_BOOKMARK,
    IBP_SQLSTATE__HY111__ODBC__INVALID_BOOKMARK_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*154*/
   (335544474L,
    bad_lock_level,
    "bad_lock_level",
    IBP_MCE_FB40__BAD_LOCK_LEVEL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*155*/
   (335544475L,
    relation_lock,
    "relation_lock",
    IBP_MCE_FB40__RELATION_LOCK,
    IBP_SQLSTATE__40001__TRANSACTION_ROLLBACK_SERIALIZATION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*156*/
   (335544476L,
    record_lock,
    "record_lock",
    IBP_MCE_FB40__RECORD_LOCK,
    IBP_SQLSTATE__40001__TRANSACTION_ROLLBACK_SERIALIZATION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*157*/
   (335544477L,
    max_idx,
    "max_idx",
    IBP_MCE_FB40__MAX_IDX,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*158*/
   (335544478L,
    jrn_enable,
    "jrn_enable",
    IBP_MCE_FB40__JRN_ENABLE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*159*/
   (335544479L,
    old_failure,
    "old_failure",
    IBP_MCE_FB40__OLD_FAILURE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*160*/
   (335544480L,
    old_in_progress,
    "old_in_progress",
    IBP_MCE_FB40__OLD_IN_PROGRESS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*161*/
   (335544481L,
    old_no_space,
    "old_no_space",
    IBP_MCE_FB40__OLD_NO_SPACE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*162*/
   (335544482L,
    no_wal_no_jrn,
    "no_wal_no_jrn",
    IBP_MCE_FB40__NO_WAL_NO_JRN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*163*/
   (335544483L,
    num_old_files,
    "num_old_files",
    IBP_MCE_FB40__NUM_OLD_FILES,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*164*/
   (335544484L,
    wal_file_open,
    "wal_file_open",
    IBP_MCE_FB40__WAL_FILE_OPEN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*165*/
   (335544485L,
    bad_stmt_handle,
    "bad_stmt_handle",
    IBP_MCE_FB40__BAD_STMT_HANDLE,
    IBP_SQLSTATE__26000__INVALID_SQL_STATEMENT_NAME_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*166*/
   (335544486L,
    wal_failure,
    "wal_failure",
    IBP_MCE_FB40__WAL_FAILURE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*167*/
   (335544487L,
    walw_err,
    "walw_err",
    IBP_MCE_FB40__WALW_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*168*/
   (335544488L,
    logh_small,
    "logh_small",
    IBP_MCE_FB40__LOGH_SMALL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*169*/
   (335544489L,
    logh_inv_version,
    "logh_inv_version",
    IBP_MCE_FB40__LOGH_INV_VERSION,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*170*/
   (335544490L,
    logh_open_flag,
    "logh_open_flag",
    IBP_MCE_FB40__LOGH_OPEN_FLAG,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*171*/
   (335544491L,
    logh_open_flag2,
    "logh_open_flag2",
    IBP_MCE_FB40__LOGH_OPEN_FLAG2,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*172*/
   (335544492L,
    logh_diff_dbname,
    "logh_diff_dbname",
    IBP_MCE_FB40__LOGH_DIFF_DBNAME,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*173*/
   (335544493L,
    logf_unexpected_eof,
    "logf_unexpected_eof",
    IBP_MCE_FB40__LOGF_UNEXPECTED_EOF,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*174*/
   (335544494L,
    logr_incomplete,
    "logr_incomplete",
    IBP_MCE_FB40__LOGR_INCOMPLETE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*175*/
   (335544495L,
    logr_header_small,
    "logr_header_small",
    IBP_MCE_FB40__LOGR_HEADER_SMALL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*176*/
   (335544496L,
    logb_small,
    "logb_small",
    IBP_MCE_FB40__LOGB_SMALL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*177*/
   (335544497L,
    wal_illegal_attach,
    "wal_illegal_attach",
    IBP_MCE_FB40__WAL_ILLEGAL_ATTACH,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*178*/
   (335544498L,
    wal_invalid_wpb,
    "wal_invalid_wpb",
    IBP_MCE_FB40__WAL_INVALID_WPB,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*179*/
   (335544499L,
    wal_err_rollover,
    "wal_err_rollover",
    IBP_MCE_FB40__WAL_ERR_ROLLOVER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*180*/
   (335544500L,
    no_wal,
    "no_wal",
    IBP_MCE_FB40__NO_WAL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*181*/
   (335544501L,
    drop_wal,
    "drop_wal",
    IBP_MCE_FB40__DROP_WAL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*182*/
   (335544502L,
    stream_not_defined,
    "stream_not_defined",
    IBP_MCE_FB40__STREAM_NOT_DEFINED,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*183*/
   (335544503L,
    wal_subsys_error,
    "wal_subsys_error",
    IBP_MCE_FB40__WAL_SUBSYS_ERROR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*184*/
   (335544504L,
    wal_subsys_corrupt,
    "wal_subsys_corrupt",
    IBP_MCE_FB40__WAL_SUBSYS_CORRUPT,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*185*/
   (335544505L,
    no_archive,
    "no_archive",
    IBP_MCE_FB40__NO_ARCHIVE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*186*/
   (335544506L,
    shutinprog,
    "shutinprog",
    IBP_MCE_FB40__SHUTINPROG,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*187*/
   (335544507L,
    range_in_use,
    "range_in_use",
    IBP_MCE_FB40__RANGE_IN_USE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*188*/
   (335544508L,
    range_not_found,
    "range_not_found",
    IBP_MCE_FB40__RANGE_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*189*/
   (335544509L,
    charset_not_found,
    "charset_not_found",
    IBP_MCE_FB40__CHARSET_NOT_FOUND,
    IBP_SQLSTATE__2C000__INVALID_CHARACTER_SET_NAME_NO_SUBCLASS,
    DB_E_NOTSUPPORTED)
 ADD_CODE         /*190*/
   (335544510L,
    lock_timeout,
    "lock_timeout",
    IBP_MCE_FB40__LOCK_TIMEOUT,
    IBP_SQLSTATE__40001__TRANSACTION_ROLLBACK_SERIALIZATION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*191*/
   (335544511L,
    prcnotdef,
    "prcnotdef",
    IBP_MCE_FB40__PRCNOTDEF,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*192*/
   (335544512L,
    prcmismat,
    "prcmismat",
    IBP_MCE_FB40__PRCMISMAT,
    IBP_SQLSTATE__07001__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_DYNAMIC_PARAMETER_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*193*/
   (335544513L,
    wal_bugcheck,
    "wal_bugcheck",
    IBP_MCE_FB40__WAL_BUGCHECK,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*194*/
   (335544514L,
    wal_cant_expand,
    "wal_cant_expand",
    IBP_MCE_FB40__WAL_CANT_EXPAND,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*195*/
   (335544515L,
    codnotdef,
    "codnotdef",
    IBP_MCE_FB40__CODNOTDEF,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*196*/
   (335544516L,
    xcpnotdef,
    "xcpnotdef",
    IBP_MCE_FB40__XCPNOTDEF,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*197*/
   (335544517L,
    except,
    "except",
    IBP_MCE_FB40__EXCEPT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    E_FAIL)
 ADD_CODE         /*198*/
   (335544518L,
    cache_restart,
    "cache_restart",
    IBP_MCE_FB40__CACHE_RESTART,
    IBP_SQLSTATE__HY013__ODBC__MEMORY_MANAGEMENT_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*199*/
   (335544519L,
    bad_lock_handle,
    "bad_lock_handle",
    IBP_MCE_FB40__BAD_LOCK_HANDLE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*200*/
   (335544520L,
    jrn_present,
    "jrn_present",
    IBP_MCE_FB40__JRN_PRESENT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*201*/
   (335544521L,
    wal_err_rollover2,
    "wal_err_rollover2",
    IBP_MCE_FB40__WAL_ERR_ROLLOVER2,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*202*/
   (335544522L,
    wal_err_logwrite,
    "wal_err_logwrite",
    IBP_MCE_FB40__WAL_ERR_LOGWRITE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*203*/
   (335544523L,
    wal_err_jrn_comm,
    "wal_err_jrn_comm",
    IBP_MCE_FB40__WAL_ERR_JRN_COMM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*204*/
   (335544524L,
    wal_err_expansion,
    "wal_err_expansion",
    IBP_MCE_FB40__WAL_ERR_EXPANSION,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*205*/
   (335544525L,
    wal_err_setup,
    "wal_err_setup",
    IBP_MCE_FB40__WAL_ERR_SETUP,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*206*/
   (335544526L,
    wal_err_ww_sync,
    "wal_err_ww_sync",
    IBP_MCE_FB40__WAL_ERR_WW_SYNC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*207*/
   (335544527L,
    wal_err_ww_start,
    "wal_err_ww_start",
    IBP_MCE_FB40__WAL_ERR_WW_START,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*208*/
   (335544528L,
    shutdown,
    "shutdown",
    IBP_MCE_FB40__SHUTDOWN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*209*/
   (335544529L,
    existing_priv_mod,
    "existing_priv_mod",
    IBP_MCE_FB40__EXISTING_PRIV_MOD,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*210*/
   (335544530L,
    primary_key_ref,
    "primary_key_ref",
    IBP_MCE_FB40__PRIMARY_KEY_REF,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*211*/
   (335544531L,
    primary_key_notnull,
    "primary_key_notnull",
    IBP_MCE_FB40__PRIMARY_KEY_NOTNULL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*212*/
   (335544532L,
    ref_cnstrnt_notfound,
    "ref_cnstrnt_notfound",
    IBP_MCE_FB40__REF_CNSTRNT_NOTFOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*213*/
   (335544533L,
    foreign_key_notfound,
    "foreign_key_notfound",
    IBP_MCE_FB40__FOREIGN_KEY_NOTFOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*214*/
   (335544534L,
    ref_cnstrnt_update,
    "ref_cnstrnt_update",
    IBP_MCE_FB40__REF_CNSTRNT_UPDATE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*215*/
   (335544535L,
    check_cnstrnt_update,
    "check_cnstrnt_update",
    IBP_MCE_FB40__CHECK_CNSTRNT_UPDATE,
    IBP_SQLSTATE__44000__WITH_CHECK_OPTION_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*216*/
   (335544536L,
    check_cnstrnt_del,
    "check_cnstrnt_del",
    IBP_MCE_FB40__CHECK_CNSTRNT_DEL,
    IBP_SQLSTATE__44000__WITH_CHECK_OPTION_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*217*/
   (335544537L,
    integ_index_seg_del,
    "integ_index_seg_del",
    IBP_MCE_FB40__INTEG_INDEX_SEG_DEL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*218*/
   (335544538L,
    integ_index_seg_mod,
    "integ_index_seg_mod",
    IBP_MCE_FB40__INTEG_INDEX_SEG_MOD,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*219*/
   (335544539L,
    integ_index_del,
    "integ_index_del",
    IBP_MCE_FB40__INTEG_INDEX_DEL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*220*/
   (335544540L,
    integ_index_mod,
    "integ_index_mod",
    IBP_MCE_FB40__INTEG_INDEX_MOD,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*221*/
   (335544541L,
    check_trig_del,
    "check_trig_del",
    IBP_MCE_FB40__CHECK_TRIG_DEL,
    IBP_SQLSTATE__44000__WITH_CHECK_OPTION_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*222*/
   (335544542L,
    check_trig_update,
    "check_trig_update",
    IBP_MCE_FB40__CHECK_TRIG_UPDATE,
    IBP_SQLSTATE__44000__WITH_CHECK_OPTION_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*223*/
   (335544543L,
    cnstrnt_fld_del,
    "cnstrnt_fld_del",
    IBP_MCE_FB40__CNSTRNT_FLD_DEL,
    IBP_SQLSTATE__23000__INTEGRITY_CONSTRAINT_VIOLATION_NO_SUBCLASS,
    DB_E_INTEGRITYVIOLATION)
 ADD_CODE         /*224*/
   (335544544L,
    cnstrnt_fld_rename,
    "cnstrnt_fld_rename",
    IBP_MCE_FB40__CNSTRNT_FLD_RENAME,
    IBP_SQLSTATE__23000__INTEGRITY_CONSTRAINT_VIOLATION_NO_SUBCLASS,
    DB_E_INTEGRITYVIOLATION)
 ADD_CODE         /*225*/
   (335544545L,
    rel_cnstrnt_update,
    "rel_cnstrnt_update",
    IBP_MCE_FB40__REL_CNSTRNT_UPDATE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*226*/
   (335544546L,
    constaint_on_view,
    "constaint_on_view",
    IBP_MCE_FB40__CONSTAINT_ON_VIEW,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*227*/
   (335544547L,
    invld_cnstrnt_type,
    "invld_cnstrnt_type",
    IBP_MCE_FB40__INVLD_CNSTRNT_TYPE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*228*/
   (335544548L,
    primary_key_exists,
    "primary_key_exists",
    IBP_MCE_FB40__PRIMARY_KEY_EXISTS,
    IBP_SQLSTATE__42S11__ODBC__INDEX_ALREADY_EXISTS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*229*/
   (335544549L,
    systrig_update,
    "systrig_update",
    IBP_MCE_FB40__SYSTRIG_UPDATE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*230*/
   (335544550L,
    not_rel_owner,
    "not_rel_owner",
    IBP_MCE_FB40__NOT_REL_OWNER,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*231*/
   (335544551L,
    grant_obj_notfound,
    "grant_obj_notfound",
    IBP_MCE_FB40__GRANT_OBJ_NOTFOUND,
    IBP_SQLSTATE__01007__WARNING_PRIVILEGE_NOT_GRANTED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*232*/
   (335544552L,
    grant_fld_notfound,
    "grant_fld_notfound",
    IBP_MCE_FB40__GRANT_FLD_NOTFOUND,
    IBP_SQLSTATE__01007__WARNING_PRIVILEGE_NOT_GRANTED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*233*/
   (335544553L,
    grant_nopriv,
    "grant_nopriv",
    IBP_MCE_FB40__GRANT_NOPRIV,
    IBP_SQLSTATE__01007__WARNING_PRIVILEGE_NOT_GRANTED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*234*/
   (335544554L,
    nonsql_security_rel,
    "nonsql_security_rel",
    IBP_MCE_FB40__NONSQL_SECURITY_REL,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*235*/
   (335544555L,
    nonsql_security_fld,
    "nonsql_security_fld",
    IBP_MCE_FB40__NONSQL_SECURITY_FLD,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*236*/
   (335544556L,
    wal_cache_err,
    "wal_cache_err",
    IBP_MCE_FB40__WAL_CACHE_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*237*/
   (335544557L,
    shutfail,
    "shutfail",
    IBP_MCE_FB40__SHUTFAIL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*238*/
   (335544558L,
    check_constraint,
    "check_constraint",
    IBP_MCE_FB40__CHECK_CONSTRAINT,
    IBP_SQLSTATE__23000__INTEGRITY_CONSTRAINT_VIOLATION_NO_SUBCLASS,
    DB_E_INTEGRITYVIOLATION)
 ADD_CODE         /*239*/
   (335544559L,
    bad_svc_handle,
    "bad_svc_handle",
    IBP_MCE_FB40__BAD_SVC_HANDLE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*240*/
   (335544560L,
    shutwarn,
    "shutwarn",
    IBP_MCE_FB40__SHUTWARN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*241*/
   (335544561L,
    wrospbver,
    "wrospbver",
    IBP_MCE_FB40__WROSPBVER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*242*/
   (335544562L,
    bad_spb_form,
    "bad_spb_form",
    IBP_MCE_FB40__BAD_SPB_FORM,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*243*/
   (335544563L,
    svcnotdef,
    "svcnotdef",
    IBP_MCE_FB40__SVCNOTDEF,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*244*/
   (335544564L,
    no_jrn,
    "no_jrn",
    IBP_MCE_FB40__NO_JRN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*245*/
   (335544565L,
    transliteration_failed,
    "transliteration_failed",
    IBP_MCE_FB40__TRANSLITERATION_FAILED,
    IBP_SQLSTATE__22018__DATA_EXCEPTION_INVALID_CHARACTER_VALUE_FOR_CAST,
    DB_E_CANTCONVERTVALUE)
 ADD_CODE         /*246*/
   (335544566L,
    start_cm_for_wal,
    "start_cm_for_wal",
    IBP_MCE_FB40__START_CM_FOR_WAL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*247*/
   (335544567L,
    wal_ovflow_log_required,
    "wal_ovflow_log_required",
    IBP_MCE_FB40__WAL_OVFLOW_LOG_REQUIRED,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*248*/
   (335544568L,
    text_subtype,
    "text_subtype",
    IBP_MCE_FB40__TEXT_SUBTYPE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*249*/
   (335544569L,
    dsql_error,
    "dsql_error",
    IBP_MCE_FB40__DSQL_ERROR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*250*/
   (335544570L,
    dsql_command_err,
    "dsql_command_err",
    IBP_MCE_FB40__DSQL_COMMAND_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*251*/
   (335544571L,
    dsql_constant_err,
    "dsql_constant_err",
    IBP_MCE_FB40__DSQL_CONSTANT_ERR,
    IBP_SQLSTATE__HY004__ODBC__INVALID_SQL_DATA_TYPE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*252*/
   (335544572L,
    dsql_cursor_err,
    "dsql_cursor_err",
    IBP_MCE_FB40__DSQL_CURSOR_ERR,
    IBP_SQLSTATE__HY015__ODBC__NO_CURSOR_NAME_AVAILABLE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*253*/
   (335544573L,
    dsql_datatype_err,
    "dsql_datatype_err",
    IBP_MCE_FB40__DSQL_DATATYPE_ERR,
    IBP_SQLSTATE__HY004__ODBC__INVALID_SQL_DATA_TYPE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*254*/
   (335544574L,
    dsql_decl_err,
    "dsql_decl_err",
    IBP_MCE_FB40__DSQL_DECL_ERR,
    IBP_SQLSTATE__34000__INVALID_CURSOR_NAME_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*255*/
   (335544575L,
    dsql_cursor_update_err,
    "dsql_cursor_update_err",
    IBP_MCE_FB40__DSQL_CURSOR_UPDATE_ERR,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*256*/
   (335544576L,
    dsql_cursor_open_err,
    "dsql_cursor_open_err",
    IBP_MCE_FB40__DSQL_CURSOR_OPEN_ERR,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*257*/
   (335544577L,
    dsql_cursor_close_err,
    "dsql_cursor_close_err",
    IBP_MCE_FB40__DSQL_CURSOR_CLOSE_ERR,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*258*/
   (335544578L,
    dsql_field_err,
    "dsql_field_err",
    IBP_MCE_FB40__DSQL_FIELD_ERR,
    IBP_SQLSTATE__42S22__ODBC__COLUMN_NOT_FOUND,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*259*/
   (335544579L,
    dsql_internal_err,
    "dsql_internal_err",
    IBP_MCE_FB40__DSQL_INTERNAL_ERR,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*260*/
   (335544580L,
    dsql_relation_err,
    "dsql_relation_err",
    IBP_MCE_FB40__DSQL_RELATION_ERR,
    IBP_SQLSTATE__42S02__ODBC__BASE_TABLE_OR_VIEW_NOT_FOUND,
    DB_E_NOTABLE)
 ADD_CODE         /*261*/
   (335544581L,
    dsql_procedure_err,
    "dsql_procedure_err",
    IBP_MCE_FB40__DSQL_PROCEDURE_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*262*/
   (335544582L,
    dsql_request_err,
    "dsql_request_err",
    IBP_MCE_FB40__DSQL_REQUEST_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*263*/
   (335544583L,
    dsql_sqlda_err,
    "dsql_sqlda_err",
    IBP_MCE_FB40__DSQL_SQLDA_ERR,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*264*/
   (335544584L,
    dsql_var_count_err,
    "dsql_var_count_err",
    IBP_MCE_FB40__DSQL_VAR_COUNT_ERR,
    IBP_SQLSTATE__21S01__ODBC__INSERT_VALUE_LIST_DOES_NOT_MATCH_COLUMN_LIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*265*/
   (335544585L,
    dsql_stmt_handle,
    "dsql_stmt_handle",
    IBP_MCE_FB40__DSQL_STMT_HANDLE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*266*/
   (335544586L,
    dsql_function_err,
    "dsql_function_err",
    IBP_MCE_FB40__DSQL_FUNCTION_ERR,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*267*/
   (335544587L,
    dsql_blob_err,
    "dsql_blob_err",
    IBP_MCE_FB40__DSQL_BLOB_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*268*/
   (335544588L,
    collation_not_found,
    "collation_not_found",
    IBP_MCE_FB40__COLLATION_NOT_FOUND,
    IBP_SQLSTATE__22021__DATA_EXCEPTION_CHARACTER_NOT_IN_REPERTOIRE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*269*/
   (335544589L,
    collation_not_for_charset,
    "collation_not_for_charset",
    IBP_MCE_FB40__COLLATION_NOT_FOR_CHARSET,
    IBP_SQLSTATE__22021__DATA_EXCEPTION_CHARACTER_NOT_IN_REPERTOIRE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*270*/
   (335544590L,
    dsql_dup_option,
    "dsql_dup_option",
    IBP_MCE_FB40__DSQL_DUP_OPTION,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*271*/
   (335544591L,
    dsql_tran_err,
    "dsql_tran_err",
    IBP_MCE_FB40__DSQL_TRAN_ERR,
    IBP_SQLSTATE__25000__INVALID_TRANSACTION_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*272*/
   (335544592L,
    dsql_invalid_array,
    "dsql_invalid_array",
    IBP_MCE_FB40__DSQL_INVALID_ARRAY,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*273*/
   (335544593L,
    dsql_max_arr_dim_exceeded,
    "dsql_max_arr_dim_exceeded",
    IBP_MCE_FB40__DSQL_MAX_ARR_DIM_EXCEEDED,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*274*/
   (335544594L,
    dsql_arr_range_error,
    "dsql_arr_range_error",
    IBP_MCE_FB40__DSQL_ARR_RANGE_ERROR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*275*/
   (335544595L,
    dsql_trigger_err,
    "dsql_trigger_err",
    IBP_MCE_FB40__DSQL_TRIGGER_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*276*/
   (335544596L,
    dsql_subselect_err,
    "dsql_subselect_err",
    IBP_MCE_FB40__DSQL_SUBSELECT_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*277*/
   (335544597L,
    dsql_crdb_prepare_err,
    "dsql_crdb_prepare_err",
    IBP_MCE_FB40__DSQL_CRDB_PREPARE_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*278*/
   (335544598L,
    specify_field_err,
    "specify_field_err",
    IBP_MCE_FB40__SPECIFY_FIELD_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*279*/
   (335544599L,
    num_field_err,
    "num_field_err",
    IBP_MCE_FB40__NUM_FIELD_ERR,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*280*/
   (335544600L,
    col_name_err,
    "col_name_err",
    IBP_MCE_FB40__COL_NAME_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*281*/
   (335544601L,
    where_err,
    "where_err",
    IBP_MCE_FB40__WHERE_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*282*/
   (335544602L,
    table_view_err,
    "table_view_err",
    IBP_MCE_FB40__TABLE_VIEW_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*283*/
   (335544603L,
    distinct_err,
    "distinct_err",
    IBP_MCE_FB40__DISTINCT_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*284*/
   (335544604L,
    key_field_count_err,
    "key_field_count_err",
    IBP_MCE_FB40__KEY_FIELD_COUNT_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*285*/
   (335544605L,
    subquery_err,
    "subquery_err",
    IBP_MCE_FB40__SUBQUERY_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*286*/
   (335544606L,
    expression_eval_err,
    "expression_eval_err",
    IBP_MCE_FB40__EXPRESSION_EVAL_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*287*/
   (335544607L,
    node_err,
    "node_err",
    IBP_MCE_FB40__NODE_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*288*/
   (335544608L,
    command_end_err,
    "command_end_err",
    IBP_MCE_FB40__COMMAND_END_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*289*/
   (335544609L,
    index_name,
    "index_name",
    IBP_MCE_FB40__INDEX_NAME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*290*/
   (335544610L,
    exception_name,
    "exception_name",
    IBP_MCE_FB40__EXCEPTION_NAME,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*291*/
   (335544611L,
    field_name,
    "field_name",
    IBP_MCE_FB40__FIELD_NAME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*292*/
   (335544612L,
    token_err,
    "token_err",
    IBP_MCE_FB40__TOKEN_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*293*/
   (335544613L,
    union_err,
    "union_err",
    IBP_MCE_FB40__UNION_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*294*/
   (335544614L,
    dsql_construct_err,
    "dsql_construct_err",
    IBP_MCE_FB40__DSQL_CONSTRUCT_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*295*/
   (335544615L,
    field_aggregate_err,
    "field_aggregate_err",
    IBP_MCE_FB40__FIELD_AGGREGATE_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*296*/
   (335544616L,
    field_ref_err,
    "field_ref_err",
    IBP_MCE_FB40__FIELD_REF_ERR,
    IBP_SQLSTATE__42S22__ODBC__COLUMN_NOT_FOUND,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*297*/
   (335544617L,
    order_by_err,
    "order_by_err",
    IBP_MCE_FB40__ORDER_BY_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*298*/
   (335544618L,
    return_mode_err,
    "return_mode_err",
    IBP_MCE_FB40__RETURN_MODE_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*299*/
   (335544619L,
    extern_func_err,
    "extern_func_err",
    IBP_MCE_FB40__EXTERN_FUNC_ERR,
    IBP_SQLSTATE__38000__EXTERNAL_ROUTINE_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*300*/
   (335544620L,
    alias_conflict_err,
    "alias_conflict_err",
    IBP_MCE_FB40__ALIAS_CONFLICT_ERR,
    IBP_SQLSTATE__08001__CONNECTION_EXCEPTION_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*301*/
   (335544621L,
    procedure_conflict_error,
    "procedure_conflict_error",
    IBP_MCE_FB40__PROCEDURE_CONFLICT_ERROR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*302*/
   (335544622L,
    relation_conflict_err,
    "relation_conflict_err",
    IBP_MCE_FB40__RELATION_CONFLICT_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*303*/
   (335544623L,
    dsql_domain_err,
    "dsql_domain_err",
    IBP_MCE_FB40__DSQL_DOMAIN_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*304*/
   (335544624L,
    idx_seg_err,
    "idx_seg_err",
    IBP_MCE_FB40__IDX_SEG_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*305*/
   (335544625L,
    node_name_err,
    "node_name_err",
    IBP_MCE_FB40__NODE_NAME_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*306*/
   (335544626L,
    table_name,
    "table_name",
    IBP_MCE_FB40__TABLE_NAME,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*307*/
   (335544627L,
    proc_name,
    "proc_name",
    IBP_MCE_FB40__PROC_NAME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*308*/
   (335544628L,
    idx_create_err,
    "idx_create_err",
    IBP_MCE_FB40__IDX_CREATE_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*309*/
   (335544629L,
    wal_shadow_err,
    "wal_shadow_err",
    IBP_MCE_FB40__WAL_SHADOW_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*310*/
   (335544630L,
    dependency,
    "dependency",
    IBP_MCE_FB40__DEPENDENCY,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*311*/
   (335544631L,
    idx_key_err,
    "idx_key_err",
    IBP_MCE_FB40__IDX_KEY_ERR,
    IBP_SQLSTATE__54011__TOO_MANY_COLUMNS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*312*/
   (335544632L,
    dsql_file_length_err,
    "dsql_file_length_err",
    IBP_MCE_FB40__DSQL_FILE_LENGTH_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*313*/
   (335544633L,
    dsql_shadow_number_err,
    "dsql_shadow_number_err",
    IBP_MCE_FB40__DSQL_SHADOW_NUMBER_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*314*/
   (335544634L,
    dsql_token_unk_err,
    "dsql_token_unk_err",
    IBP_MCE_FB40__DSQL_TOKEN_UNK_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*315*/
   (335544635L,
    dsql_no_relation_alias,
    "dsql_no_relation_alias",
    IBP_MCE_FB40__DSQL_NO_RELATION_ALIAS,
    IBP_SQLSTATE__42S02__ODBC__BASE_TABLE_OR_VIEW_NOT_FOUND,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*316*/
   (335544636L,
    indexname,
    "indexname",
    IBP_MCE_FB40__INDEXNAME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*317*/
   (335544637L,
    no_stream_plan,
    "no_stream_plan",
    IBP_MCE_FB40__NO_STREAM_PLAN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*318*/
   (335544638L,
    stream_twice,
    "stream_twice",
    IBP_MCE_FB40__STREAM_TWICE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*319*/
   (335544639L,
    stream_not_found,
    "stream_not_found",
    IBP_MCE_FB40__STREAM_NOT_FOUND,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*320*/
   (335544640L,
    collation_requires_text,
    "collation_requires_text",
    IBP_MCE_FB40__COLLATION_REQUIRES_TEXT,
    IBP_SQLSTATE__22021__DATA_EXCEPTION_CHARACTER_NOT_IN_REPERTOIRE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*321*/
   (335544641L,
    dsql_domain_not_found,
    "dsql_domain_not_found",
    IBP_MCE_FB40__DSQL_DOMAIN_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*322*/
   (335544642L,
    index_unused,
    "index_unused",
    IBP_MCE_FB40__INDEX_UNUSED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*323*/
   (335544643L,
    dsql_self_join,
    "dsql_self_join",
    IBP_MCE_FB40__DSQL_SELF_JOIN,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*324*/
   (335544644L,
    stream_bof,
    "stream_bof",
    IBP_MCE_FB40__STREAM_BOF,
    IBP_SQLSTATE__HY109__ODBC__INVALID_CURSOR_POSITION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*325*/
   (335544645L,
    stream_crack,
    "stream_crack",
    IBP_MCE_FB40__STREAM_CRACK,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*326*/
   (335544646L,
    db_or_file_exists,
    "db_or_file_exists",
    IBP_MCE_FB40__DB_OR_FILE_EXISTS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*327*/
   (335544647L,
    invalid_operator,
    "invalid_operator",
    IBP_MCE_FB40__INVALID_OPERATOR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*328*/
   (335544648L,
    conn_lost,
    "conn_lost",
    IBP_MCE_FB40__CONN_LOST,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*329*/
   (335544649L,
    bad_checksum,
    "bad_checksum",
    IBP_MCE_FB40__BAD_CHECKSUM,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*330*/
   (335544650L,
    page_type_err,
    "page_type_err",
    IBP_MCE_FB40__PAGE_TYPE_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*331*/
   (335544651L,
    ext_readonly_err,
    "ext_readonly_err",
    IBP_MCE_FB40__EXT_READONLY_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*332*/
   (335544652L,
    sing_select_err,
    "sing_select_err",
    IBP_MCE_FB40__SING_SELECT_ERR,
    IBP_SQLSTATE__21000__CARDINALITY_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*333*/
   (335544653L,
    psw_attach,
    "psw_attach",
    IBP_MCE_FB40__PSW_ATTACH,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*334*/
   (335544654L,
    psw_start_trans,
    "psw_start_trans",
    IBP_MCE_FB40__PSW_START_TRANS,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*335*/
   (335544655L,
    invalid_direction,
    "invalid_direction",
    IBP_MCE_FB40__INVALID_DIRECTION,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*336*/
   (335544656L,
    dsql_var_conflict,
    "dsql_var_conflict",
    IBP_MCE_FB40__DSQL_VAR_CONFLICT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*337*/
   (335544657L,
    dsql_no_blob_array,
    "dsql_no_blob_array",
    IBP_MCE_FB40__DSQL_NO_BLOB_ARRAY,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*338*/
   (335544658L,
    dsql_base_table,
    "dsql_base_table",
    IBP_MCE_FB40__DSQL_BASE_TABLE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*339*/
   (335544659L,
    duplicate_base_table,
    "duplicate_base_table",
    IBP_MCE_FB40__DUPLICATE_BASE_TABLE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*340*/
   (335544660L,
    view_alias,
    "view_alias",
    IBP_MCE_FB40__VIEW_ALIAS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*341*/
   (335544661L,
    index_root_page_full,
    "index_root_page_full",
    IBP_MCE_FB40__INDEX_ROOT_PAGE_FULL,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*342*/
   (335544662L,
    dsql_blob_type_unknown,
    "dsql_blob_type_unknown",
    IBP_MCE_FB40__DSQL_BLOB_TYPE_UNKNOWN,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*343*/
   (335544663L,
    req_max_clones_exceeded,
    "req_max_clones_exceeded",
    IBP_MCE_FB40__REQ_MAX_CLONES_EXCEEDED,
    IBP_SQLSTATE__54001__STATEMENT_TOO_COMPLEX,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*344*/
   (335544664L,
    dsql_duplicate_spec,
    "dsql_duplicate_spec",
    IBP_MCE_FB40__DSQL_DUPLICATE_SPEC,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*345*/
   (335544665L,
    unique_key_violation,
    "unique_key_violation",
    IBP_MCE_FB40__UNIQUE_KEY_VIOLATION,
    IBP_SQLSTATE__23000__INTEGRITY_CONSTRAINT_VIOLATION_NO_SUBCLASS,
    DB_E_INTEGRITYVIOLATION)
 ADD_CODE         /*346*/
   (335544666L,
    srvr_version_too_old,
    "srvr_version_too_old",
    IBP_MCE_FB40__SRVR_VERSION_TOO_OLD,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*347*/
   (335544667L,
    drdb_completed_with_errs,
    "drdb_completed_with_errs",
    IBP_MCE_FB40__DRDB_COMPLETED_WITH_ERRS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*348*/
   (335544668L,
    dsql_procedure_use_err,
    "dsql_procedure_use_err",
    IBP_MCE_FB40__DSQL_PROCEDURE_USE_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*349*/
   (335544669L,
    dsql_count_mismatch,
    "dsql_count_mismatch",
    IBP_MCE_FB40__DSQL_COUNT_MISMATCH,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*350*/
   (335544670L,
    blob_idx_err,
    "blob_idx_err",
    IBP_MCE_FB40__BLOB_IDX_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*351*/
   (335544671L,
    array_idx_err,
    "array_idx_err",
    IBP_MCE_FB40__ARRAY_IDX_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*352*/
   (335544672L,
    key_field_err,
    "key_field_err",
    IBP_MCE_FB40__KEY_FIELD_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*353*/
   (335544673L,
    no_delete,
    "no_delete",
    IBP_MCE_FB40__NO_DELETE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*354*/
   (335544674L,
    del_last_field,
    "del_last_field",
    IBP_MCE_FB40__DEL_LAST_FIELD,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*355*/
   (335544675L,
    sort_err,
    "sort_err",
    IBP_MCE_FB40__SORT_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*356*/
   (335544676L,
    sort_mem_err,
    "sort_mem_err",
    IBP_MCE_FB40__SORT_MEM_ERR,
    IBP_SQLSTATE__HY001__ODBC__MEMORY_ALLOCATION_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*357*/
   (335544677L,
    version_err,
    "version_err",
    IBP_MCE_FB40__VERSION_ERR,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*358*/
   (335544678L,
    inval_key_posn,
    "inval_key_posn",
    IBP_MCE_FB40__INVAL_KEY_POSN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*359*/
   (335544679L,
    no_segments_err,
    "no_segments_err",
    IBP_MCE_FB40__NO_SEGMENTS_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*360*/
   (335544680L,
    crrp_data_err,
    "crrp_data_err",
    IBP_MCE_FB40__CRRP_DATA_ERR,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*361*/
   (335544681L,
    rec_size_err,
    "rec_size_err",
    IBP_MCE_FB40__REC_SIZE_ERR,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*362*/
   (335544682L,
    dsql_field_ref,
    "dsql_field_ref",
    IBP_MCE_FB40__DSQL_FIELD_REF,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*363*/
   (335544683L,
    req_depth_exceeded,
    "req_depth_exceeded",
    IBP_MCE_FB40__REQ_DEPTH_EXCEEDED,
    IBP_SQLSTATE__54001__STATEMENT_TOO_COMPLEX,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*364*/
   (335544684L,
    no_field_access,
    "no_field_access",
    IBP_MCE_FB40__NO_FIELD_ACCESS,
    IBP_SQLSTATE__42S22__ODBC__COLUMN_NOT_FOUND,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*365*/
   (335544685L,
    no_dbkey,
    "no_dbkey",
    IBP_MCE_FB40__NO_DBKEY,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*366*/
   (335544686L,
    jrn_format_err,
    "jrn_format_err",
    IBP_MCE_FB40__JRN_FORMAT_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*367*/
   (335544687L,
    jrn_file_full,
    "jrn_file_full",
    IBP_MCE_FB40__JRN_FILE_FULL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*368*/
   (335544688L,
    dsql_open_cursor_request,
    "dsql_open_cursor_request",
    IBP_MCE_FB40__DSQL_OPEN_CURSOR_REQUEST,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*369*/
   (335544689L,
    ib_error,
    "ib_error",
    IBP_MCE_FB40__IB_ERROR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*370*/
   (335544690L,
    cache_redef,
    "cache_redef",
    IBP_MCE_FB40__CACHE_REDEF,
    IBP_SQLSTATE__HY013__ODBC__MEMORY_MANAGEMENT_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*371*/
   (335544691L,
    cache_too_small,
    "cache_too_small",
    IBP_MCE_FB40__CACHE_TOO_SMALL,
    IBP_SQLSTATE__HY013__ODBC__MEMORY_MANAGEMENT_ERROR,
    E_OUTOFMEMORY)
 ADD_CODE         /*372*/
   (335544692L,
    log_redef,
    "log_redef",
    IBP_MCE_FB40__LOG_REDEF,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*373*/
   (335544693L,
    log_too_small,
    "log_too_small",
    IBP_MCE_FB40__LOG_TOO_SMALL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*374*/
   (335544694L,
    partition_too_small,
    "partition_too_small",
    IBP_MCE_FB40__PARTITION_TOO_SMALL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*375*/
   (335544695L,
    partition_not_supp,
    "partition_not_supp",
    IBP_MCE_FB40__PARTITION_NOT_SUPP,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*376*/
   (335544696L,
    log_length_spec,
    "log_length_spec",
    IBP_MCE_FB40__LOG_LENGTH_SPEC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*377*/
   (335544697L,
    precision_err,
    "precision_err",
    IBP_MCE_FB40__PRECISION_ERR,
    IBP_SQLSTATE__HY104__ODBC__INVALID_PRECISION_OR_SCALE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*378*/
   (335544698L,
    scale_nogt,
    "scale_nogt",
    IBP_MCE_FB40__SCALE_NOGT,
    IBP_SQLSTATE__HY104__ODBC__INVALID_PRECISION_OR_SCALE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*379*/
   (335544699L,
    expec_short,
    "expec_short",
    IBP_MCE_FB40__EXPEC_SHORT,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*380*/
   (335544700L,
    expec_long,
    "expec_long",
    IBP_MCE_FB40__EXPEC_LONG,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*381*/
   (335544701L,
    expec_ushort,
    "expec_ushort",
    IBP_MCE_FB40__EXPEC_USHORT,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*382*/
   (335544702L,
    escape_invalid,
    "escape_invalid",
    IBP_MCE_FB40__ESCAPE_INVALID,
    IBP_SQLSTATE__22025__DATA_EXCEPTION_INVALID_ESCAPE_SEQUENCE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*383*/
   (335544703L,
    svcnoexe,
    "svcnoexe",
    IBP_MCE_FB40__SVCNOEXE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*384*/
   (335544704L,
    net_lookup_err,
    "net_lookup_err",
    IBP_MCE_FB40__NET_LOOKUP_ERR,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*385*/
   (335544705L,
    service_unknown,
    "service_unknown",
    IBP_MCE_FB40__SERVICE_UNKNOWN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*386*/
   (335544706L,
    host_unknown,
    "host_unknown",
    IBP_MCE_FB40__HOST_UNKNOWN,
    IBP_SQLSTATE__08001__CONNECTION_EXCEPTION_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*387*/
   (335544707L,
    grant_nopriv_on_base,
    "grant_nopriv_on_base",
    IBP_MCE_FB40__GRANT_NOPRIV_ON_BASE,
    IBP_SQLSTATE__01007__WARNING_PRIVILEGE_NOT_GRANTED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*388*/
   (335544708L,
    dyn_fld_ambiguous,
    "dyn_fld_ambiguous",
    IBP_MCE_FB40__DYN_FLD_AMBIGUOUS,
    IBP_SQLSTATE__42702__AMBIGUOUS_COLUMN,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*389*/
   (335544709L,
    dsql_agg_ref_err,
    "dsql_agg_ref_err",
    IBP_MCE_FB40__DSQL_AGG_REF_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*390*/
   (335544710L,
    complex_view,
    "complex_view",
    IBP_MCE_FB40__COMPLEX_VIEW,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*391*/
   (335544711L,
    unprepared_stmt,
    "unprepared_stmt",
    IBP_MCE_FB40__UNPREPARED_STMT,
    IBP_SQLSTATE__HY007__ODBC__ASSOCIATED_STATEMENT_IS_NOT_PREPARED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*392*/
   (335544712L,
    expec_positive,
    "expec_positive",
    IBP_MCE_FB40__EXPEC_POSITIVE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*393*/
   (335544713L,
    dsql_sqlda_value_err,
    "dsql_sqlda_value_err",
    IBP_MCE_FB40__DSQL_SQLDA_VALUE_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*394*/
   (335544714L,
    invalid_array_id,
    "invalid_array_id",
    IBP_MCE_FB40__INVALID_ARRAY_ID,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*395*/
   (335544715L,
    extfile_uns_op,
    "extfile_uns_op",
    IBP_MCE_FB40__EXTFILE_UNS_OP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*396*/
   (335544716L,
    svc_in_use,
    "svc_in_use",
    IBP_MCE_FB40__SVC_IN_USE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*397*/
   (335544717L,
    err_stack_limit,
    "err_stack_limit",
    IBP_MCE_FB40__ERR_STACK_LIMIT,
    IBP_SQLSTATE__HY013__ODBC__MEMORY_MANAGEMENT_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*398*/
   (335544718L,
    invalid_key,
    "invalid_key",
    IBP_MCE_FB40__INVALID_KEY,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*399*/
   (335544719L,
    net_init_error,
    "net_init_error",
    IBP_MCE_FB40__NET_INIT_ERROR,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*400*/
   (335544720L,
    loadlib_failure,
    "loadlib_failure",
    IBP_MCE_FB40__LOADLIB_FAILURE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*401*/
   (335544721L,
    network_error,
    "network_error",
    IBP_MCE_FB40__NETWORK_ERROR,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*402*/
   (335544722L,
    net_connect_err,
    "net_connect_err",
    IBP_MCE_FB40__NET_CONNECT_ERR,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*403*/
   (335544723L,
    net_connect_listen_err,
    "net_connect_listen_err",
    IBP_MCE_FB40__NET_CONNECT_LISTEN_ERR,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*404*/
   (335544724L,
    net_event_connect_err,
    "net_event_connect_err",
    IBP_MCE_FB40__NET_EVENT_CONNECT_ERR,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*405*/
   (335544725L,
    net_event_listen_err,
    "net_event_listen_err",
    IBP_MCE_FB40__NET_EVENT_LISTEN_ERR,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*406*/
   (335544726L,
    net_read_err,
    "net_read_err",
    IBP_MCE_FB40__NET_READ_ERR,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*407*/
   (335544727L,
    net_write_err,
    "net_write_err",
    IBP_MCE_FB40__NET_WRITE_ERR,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*408*/
   (335544728L,
    integ_index_deactivate,
    "integ_index_deactivate",
    IBP_MCE_FB40__INTEG_INDEX_DEACTIVATE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*409*/
   (335544729L,
    integ_deactivate_primary,
    "integ_deactivate_primary",
    IBP_MCE_FB40__INTEG_DEACTIVATE_PRIMARY,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*410*/
   (335544730L,
    cse_not_supported,
    "cse_not_supported",
    IBP_MCE_FB40__CSE_NOT_SUPPORTED,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*411*/
   (335544731L,
    tra_must_sweep,
    "tra_must_sweep",
    IBP_MCE_FB40__TRA_MUST_SWEEP,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*412*/
   (335544732L,
    unsupported_network_drive,
    "unsupported_network_drive",
    IBP_MCE_FB40__UNSUPPORTED_NETWORK_DRIVE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*413*/
   (335544733L,
    io_create_err,
    "io_create_err",
    IBP_MCE_FB40__IO_CREATE_ERR,
    IBP_SQLSTATE__08001__CONNECTION_EXCEPTION_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*414*/
   (335544734L,
    io_open_err,
    "io_open_err",
    IBP_MCE_FB40__IO_OPEN_ERR,
    IBP_SQLSTATE__08001__CONNECTION_EXCEPTION_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*415*/
   (335544735L,
    io_close_err,
    "io_close_err",
    IBP_MCE_FB40__IO_CLOSE_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*416*/
   (335544736L,
    io_read_err,
    "io_read_err",
    IBP_MCE_FB40__IO_READ_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*417*/
   (335544737L,
    io_write_err,
    "io_write_err",
    IBP_MCE_FB40__IO_WRITE_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*418*/
   (335544738L,
    io_delete_err,
    "io_delete_err",
    IBP_MCE_FB40__IO_DELETE_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*419*/
   (335544739L,
    io_access_err,
    "io_access_err",
    IBP_MCE_FB40__IO_ACCESS_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*420*/
   (335544740L,
    udf_exception,
    "udf_exception",
    IBP_MCE_FB40__UDF_EXCEPTION,
    IBP_SQLSTATE__38000__EXTERNAL_ROUTINE_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*421*/
   (335544741L,
    lost_db_connection,
    "lost_db_connection",
    IBP_MCE_FB40__LOST_DB_CONNECTION,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*422*/
   (335544742L,
    no_write_user_priv,
    "no_write_user_priv",
    IBP_MCE_FB40__NO_WRITE_USER_PRIV,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*423*/
   (335544743L,
    token_too_long,
    "token_too_long",
    IBP_MCE_FB40__TOKEN_TOO_LONG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*424*/
   (335544744L,
    max_att_exceeded,
    "max_att_exceeded",
    IBP_MCE_FB40__MAX_ATT_EXCEEDED,
    IBP_SQLSTATE__08001__CONNECTION_EXCEPTION_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*425*/
   (335544745L,
    login_same_as_role_name,
    "login_same_as_role_name",
    IBP_MCE_FB40__LOGIN_SAME_AS_ROLE_NAME,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*426*/
   (335544746L,
    reftable_requires_pk,
    "reftable_requires_pk",
    IBP_MCE_FB40__REFTABLE_REQUIRES_PK,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*427*/
   (335544747L,
    usrname_too_long,
    "usrname_too_long",
    IBP_MCE_FB40__USRNAME_TOO_LONG,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*428*/
   (335544748L,
    password_too_long,
    "password_too_long",
    IBP_MCE_FB40__PASSWORD_TOO_LONG,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*429*/
   (335544749L,
    usrname_required,
    "usrname_required",
    IBP_MCE_FB40__USRNAME_REQUIRED,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*430*/
   (335544750L,
    password_required,
    "password_required",
    IBP_MCE_FB40__PASSWORD_REQUIRED,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*431*/
   (335544751L,
    bad_protocol,
    "bad_protocol",
    IBP_MCE_FB40__BAD_PROTOCOL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*432*/
   (335544752L,
    dup_usrname_found,
    "dup_usrname_found",
    IBP_MCE_FB40__DUP_USRNAME_FOUND,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*433*/
   (335544753L,
    usrname_not_found,
    "usrname_not_found",
    IBP_MCE_FB40__USRNAME_NOT_FOUND,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*434*/
   (335544754L,
    error_adding_sec_record,
    "error_adding_sec_record",
    IBP_MCE_FB40__ERROR_ADDING_SEC_RECORD,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*435*/
   (335544755L,
    error_modifying_sec_record,
    "error_modifying_sec_record",
    IBP_MCE_FB40__ERROR_MODIFYING_SEC_RECORD,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*436*/
   (335544756L,
    error_deleting_sec_record,
    "error_deleting_sec_record",
    IBP_MCE_FB40__ERROR_DELETING_SEC_RECORD,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*437*/
   (335544757L,
    error_updating_sec_db,
    "error_updating_sec_db",
    IBP_MCE_FB40__ERROR_UPDATING_SEC_DB,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*438*/
   (335544758L,
    sort_rec_size_err,
    "sort_rec_size_err",
    IBP_MCE_FB40__SORT_REC_SIZE_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*439*/
   (335544759L,
    bad_default_value,
    "bad_default_value",
    IBP_MCE_FB40__BAD_DEFAULT_VALUE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*440*/
   (335544760L,
    invalid_clause,
    "invalid_clause",
    IBP_MCE_FB40__INVALID_CLAUSE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*441*/
   (335544761L,
    too_many_handles,
    "too_many_handles",
    IBP_MCE_FB40__TOO_MANY_HANDLES,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*442*/
   (335544762L,
    optimizer_blk_exc,
    "optimizer_blk_exc",
    IBP_MCE_FB40__OPTIMIZER_BLK_EXC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*443*/
   (335544763L,
    invalid_string_constant,
    "invalid_string_constant",
    IBP_MCE_FB40__INVALID_STRING_CONSTANT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*444*/
   (335544764L,
    transitional_date,
    "transitional_date",
    IBP_MCE_FB40__TRANSITIONAL_DATE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*445*/
   (335544765L,
    read_only_database,
    "read_only_database",
    IBP_MCE_FB40__READ_ONLY_DATABASE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*446*/
   (335544766L,
    must_be_dialect_2_and_up,
    "must_be_dialect_2_and_up",
    IBP_MCE_FB40__MUST_BE_DIALECT_2_AND_UP,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*447*/
   (335544767L,
    blob_filter_exception,
    "blob_filter_exception",
    IBP_MCE_FB40__BLOB_FILTER_EXCEPTION,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*448*/
   (335544768L,
    exception_access_violation,
    "exception_access_violation",
    IBP_MCE_FB40__EXCEPTION_ACCESS_VIOLATION,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*449*/
   (335544769L,
    exception_datatype_missalignment,
    "exception_datatype_missalignment",
    IBP_MCE_FB40__EXCEPTION_DATATYPE_MISSALIGNMENT,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*450*/
   (335544770L,
    exception_array_bounds_exceeded,
    "exception_array_bounds_exceeded",
    IBP_MCE_FB40__EXCEPTION_ARRAY_BOUNDS_EXCEEDED,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*451*/
   (335544771L,
    exception_float_denormal_operand,
    "exception_float_denormal_operand",
    IBP_MCE_FB40__EXCEPTION_FLOAT_DENORMAL_OPERAND,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*452*/
   (335544772L,
    exception_float_divide_by_zero,
    "exception_float_divide_by_zero",
    IBP_MCE_FB40__EXCEPTION_FLOAT_DIVIDE_BY_ZERO,
    IBP_SQLSTATE__22012__DATA_EXCEPTION_DIVISION_BY_ZERO,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*453*/
   (335544773L,
    exception_float_inexact_result,
    "exception_float_inexact_result",
    IBP_MCE_FB40__EXCEPTION_FLOAT_INEXACT_RESULT,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*454*/
   (335544774L,
    exception_float_invalid_operand,
    "exception_float_invalid_operand",
    IBP_MCE_FB40__EXCEPTION_FLOAT_INVALID_OPERAND,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*455*/
   (335544775L,
    exception_float_overflow,
    "exception_float_overflow",
    IBP_MCE_FB40__EXCEPTION_FLOAT_OVERFLOW,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*456*/
   (335544776L,
    exception_float_stack_check,
    "exception_float_stack_check",
    IBP_MCE_FB40__EXCEPTION_FLOAT_STACK_CHECK,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*457*/
   (335544777L,
    exception_float_underflow,
    "exception_float_underflow",
    IBP_MCE_FB40__EXCEPTION_FLOAT_UNDERFLOW,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*458*/
   (335544778L,
    exception_integer_divide_by_zero,
    "exception_integer_divide_by_zero",
    IBP_MCE_FB40__EXCEPTION_INTEGER_DIVIDE_BY_ZERO,
    IBP_SQLSTATE__22012__DATA_EXCEPTION_DIVISION_BY_ZERO,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*459*/
   (335544779L,
    exception_integer_overflow,
    "exception_integer_overflow",
    IBP_MCE_FB40__EXCEPTION_INTEGER_OVERFLOW,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*460*/
   (335544780L,
    exception_unknown,
    "exception_unknown",
    IBP_MCE_FB40__EXCEPTION_UNKNOWN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*461*/
   (335544781L,
    exception_stack_overflow,
    "exception_stack_overflow",
    IBP_MCE_FB40__EXCEPTION_STACK_OVERFLOW,
    IBP_SQLSTATE__HY001__ODBC__MEMORY_ALLOCATION_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*462*/
   (335544782L,
    exception_sigsegv,
    "exception_sigsegv",
    IBP_MCE_FB40__EXCEPTION_SIGSEGV,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*463*/
   (335544783L,
    exception_sigill,
    "exception_sigill",
    IBP_MCE_FB40__EXCEPTION_SIGILL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*464*/
   (335544784L,
    exception_sigbus,
    "exception_sigbus",
    IBP_MCE_FB40__EXCEPTION_SIGBUS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*465*/
   (335544785L,
    exception_sigfpe,
    "exception_sigfpe",
    IBP_MCE_FB40__EXCEPTION_SIGFPE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*466*/
   (335544786L,
    ext_file_delete,
    "ext_file_delete",
    IBP_MCE_FB40__EXT_FILE_DELETE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*467*/
   (335544787L,
    ext_file_modify,
    "ext_file_modify",
    IBP_MCE_FB40__EXT_FILE_MODIFY,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*468*/
   (335544788L,
    adm_task_denied,
    "adm_task_denied",
    IBP_MCE_FB40__ADM_TASK_DENIED,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*469*/
   (335544789L,
    extract_input_mismatch,
    "extract_input_mismatch",
    IBP_MCE_FB40__EXTRACT_INPUT_MISMATCH,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*470*/
   (335544790L,
    insufficient_svc_privileges,
    "insufficient_svc_privileges",
    IBP_MCE_FB40__INSUFFICIENT_SVC_PRIVILEGES,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*471*/
   (335544791L,
    file_in_use,
    "file_in_use",
    IBP_MCE_FB40__FILE_IN_USE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*472*/
   (335544792L,
    service_att_err,
    "service_att_err",
    IBP_MCE_FB40__SERVICE_ATT_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*473*/
   (335544793L,
    ddl_not_allowed_by_db_sql_dial,
    "ddl_not_allowed_by_db_sql_dial",
    IBP_MCE_FB40__DDL_NOT_ALLOWED_BY_DB_SQL_DIAL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*474*/
   (335544794L,
    cancelled,
    "cancelled",
    IBP_MCE_FB40__CANCELLED,
    IBP_SQLSTATE__HY008__ODBC__OPERATION_CANCELED,
    DB_E_CANCELED)
 ADD_CODE         /*475*/
   (335544795L,
    unexp_spb_form,
    "unexp_spb_form",
    IBP_MCE_FB40__UNEXP_SPB_FORM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*476*/
   (335544796L,
    sql_dialect_datatype_unsupport,
    "sql_dialect_datatype_unsupport",
    IBP_MCE_FB40__SQL_DIALECT_DATATYPE_UNSUPPORT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    DB_E_NOTSUPPORTED)
 ADD_CODE         /*477*/
   (335544797L,
    svcnouser,
    "svcnouser",
    IBP_MCE_FB40__SVCNOUSER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*478*/
   (335544798L,
    depend_on_uncommitted_rel,
    "depend_on_uncommitted_rel",
    IBP_MCE_FB40__DEPEND_ON_UNCOMMITTED_REL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*479*/
   (335544799L,
    svc_name_missing,
    "svc_name_missing",
    IBP_MCE_FB40__SVC_NAME_MISSING,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*480*/
   (335544800L,
    too_many_contexts,
    "too_many_contexts",
    IBP_MCE_FB40__TOO_MANY_CONTEXTS,
    IBP_SQLSTATE__54001__STATEMENT_TOO_COMPLEX,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*481*/
   (335544801L,
    datype_notsup,
    "datype_notsup",
    IBP_MCE_FB40__DATYPE_NOTSUP,
    IBP_SQLSTATE__22008__DATA_EXCEPTION_DATETIME_FIELD_OVERFLOW,
    DB_E_NOTSUPPORTED)
 ADD_CODE         /*482*/
   (335544802L,
    dialect_reset_warning,
    "dialect_reset_warning",
    IBP_MCE_FB40__DIALECT_RESET_WARNING,
    IBP_SQLSTATE__01000__WARNING_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*483*/
   (335544803L,
    dialect_not_changed,
    "dialect_not_changed",
    IBP_MCE_FB40__DIALECT_NOT_CHANGED,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*484*/
   (335544804L,
    database_create_failed,
    "database_create_failed",
    IBP_MCE_FB40__DATABASE_CREATE_FAILED,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*485*/
   (335544805L,
    inv_dialect_specified,
    "inv_dialect_specified",
    IBP_MCE_FB40__INV_DIALECT_SPECIFIED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*486*/
   (335544806L,
    valid_db_dialects,
    "valid_db_dialects",
    IBP_MCE_FB40__VALID_DB_DIALECTS,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*487*/
   (335544807L,
    sqlwarn,
    "sqlwarn",
    IBP_MCE_FB40__SQLWARN,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*488*/
   (335544808L,
    dtype_renamed,
    "dtype_renamed",
    IBP_MCE_FB40__DTYPE_RENAMED,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*489*/
   (335544809L,
    extern_func_dir_error,
    "extern_func_dir_error",
    IBP_MCE_FB40__EXTERN_FUNC_DIR_ERROR,
    IBP_SQLSTATE__38000__EXTERNAL_ROUTINE_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*490*/
   (335544810L,
    date_range_exceeded,
    "date_range_exceeded",
    IBP_MCE_FB40__DATE_RANGE_EXCEEDED,
    IBP_SQLSTATE__22008__DATA_EXCEPTION_DATETIME_FIELD_OVERFLOW,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*491*/
   (335544811L,
    inv_client_dialect_specified,
    "inv_client_dialect_specified",
    IBP_MCE_FB40__INV_CLIENT_DIALECT_SPECIFIED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*492*/
   (335544812L,
    valid_client_dialects,
    "valid_client_dialects",
    IBP_MCE_FB40__VALID_CLIENT_DIALECTS,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*493*/
   (335544813L,
    optimizer_between_err,
    "optimizer_between_err",
    IBP_MCE_FB40__OPTIMIZER_BETWEEN_ERR,
    IBP_SQLSTATE__HY004__ODBC__INVALID_SQL_DATA_TYPE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*494*/
   (335544814L,
    service_not_supported,
    "service_not_supported",
    IBP_MCE_FB40__SERVICE_NOT_SUPPORTED,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*495*/
   (335544815L,
    generator_name,
    "generator_name",
    IBP_MCE_FB40__GENERATOR_NAME,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*496*/
   (335544816L,
    udf_name,
    "udf_name",
    IBP_MCE_FB40__UDF_NAME,
    IBP_SQLSTATE__38000__EXTERNAL_ROUTINE_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*497*/
   (335544817L,
    bad_limit_param,
    "bad_limit_param",
    IBP_MCE_FB40__BAD_LIMIT_PARAM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*498*/
   (335544818L,
    bad_skip_param,
    "bad_skip_param",
    IBP_MCE_FB40__BAD_SKIP_PARAM,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*499*/
   (335544819L,
    io_32bit_exceeded_err,
    "io_32bit_exceeded_err",
    IBP_MCE_FB40__IO_32BIT_EXCEEDED_ERR,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*500*/
   (335544820L,
    invalid_savepoint,
    "invalid_savepoint",
    IBP_MCE_FB40__INVALID_SAVEPOINT,
    IBP_SQLSTATE__3B000__SAVEPOINT_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*501*/
   (335544821L,
    dsql_column_pos_err,
    "dsql_column_pos_err",
    IBP_MCE_FB40__DSQL_COLUMN_POS_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*502*/
   (335544822L,
    dsql_agg_where_err,
    "dsql_agg_where_err",
    IBP_MCE_FB40__DSQL_AGG_WHERE_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*503*/
   (335544823L,
    dsql_agg_group_err,
    "dsql_agg_group_err",
    IBP_MCE_FB40__DSQL_AGG_GROUP_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*504*/
   (335544824L,
    dsql_agg_column_err,
    "dsql_agg_column_err",
    IBP_MCE_FB40__DSQL_AGG_COLUMN_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*505*/
   (335544825L,
    dsql_agg_having_err,
    "dsql_agg_having_err",
    IBP_MCE_FB40__DSQL_AGG_HAVING_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*506*/
   (335544826L,
    dsql_agg_nested_err,
    "dsql_agg_nested_err",
    IBP_MCE_FB40__DSQL_AGG_NESTED_ERR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*507*/
   (335544827L,
    exec_sql_invalid_arg,
    "exec_sql_invalid_arg",
    IBP_MCE_FB40__EXEC_SQL_INVALID_ARG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*508*/
   (335544828L,
    exec_sql_invalid_req,
    "exec_sql_invalid_req",
    IBP_MCE_FB40__EXEC_SQL_INVALID_REQ,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*509*/
   (335544829L,
    exec_sql_invalid_var,
    "exec_sql_invalid_var",
    IBP_MCE_FB40__EXEC_SQL_INVALID_VAR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*510*/
   (335544830L,
    exec_sql_max_call_exceeded,
    "exec_sql_max_call_exceeded",
    IBP_MCE_FB40__EXEC_SQL_MAX_CALL_EXCEEDED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*511*/
   (335544831L,
    conf_access_denied,
    "conf_access_denied",
    IBP_MCE_FB40__CONF_ACCESS_DENIED,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*512*/
   (335544832L,
    wrong_backup_state,
    "wrong_backup_state",
    IBP_MCE_FB40__WRONG_BACKUP_STATE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*513*/
   (335544833L,
    wal_backup_err,
    "wal_backup_err",
    IBP_MCE_FB40__WAL_BACKUP_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*514*/
   (335544834L,
    cursor_not_open,
    "cursor_not_open",
    IBP_MCE_FB40__CURSOR_NOT_OPEN,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*515*/
   (335544835L,
    bad_shutdown_mode,
    "bad_shutdown_mode",
    IBP_MCE_FB40__BAD_SHUTDOWN_MODE,
    IBP_SQLSTATE__08007__CONNECTION_EXCEPTION_TRANSACTION_RESOLUTION_UNKNOWN,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*516*/
   (335544836L,
    concat_overflow,
    "concat_overflow",
    IBP_MCE_FB40__CONCAT_OVERFLOW,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*517*/
   (335544837L,
    bad_substring_offset,
    "bad_substring_offset",
    IBP_MCE_FB40__BAD_SUBSTRING_OFFSET,
    IBP_SQLSTATE__22011__DATA_EXCEPTION_SUBSTRING_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*518*/
   (335544838L,
    foreign_key_target_doesnt_exist,
    "foreign_key_target_doesnt_exist",
    IBP_MCE_FB40__FOREIGN_KEY_TARGET_DOESNT_EXIST,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*519*/
   (335544839L,
    foreign_key_references_present,
    "foreign_key_references_present",
    IBP_MCE_FB40__FOREIGN_KEY_REFERENCES_PRESENT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*520*/
   (335544840L,
    no_update,
    "no_update",
    IBP_MCE_FB40__NO_UPDATE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*521*/
   (335544841L,
    cursor_already_open,
    "cursor_already_open",
    IBP_MCE_FB40__CURSOR_ALREADY_OPEN,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*522*/
   (335544842L,
    stack_trace,
    "stack_trace",
    IBP_MCE_FB40__STACK_TRACE,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*523*/
   (335544843L,
    ctx_var_not_found,
    "ctx_var_not_found",
    IBP_MCE_FB40__CTX_VAR_NOT_FOUND,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*524*/
   (335544844L,
    ctx_namespace_invalid,
    "ctx_namespace_invalid",
    IBP_MCE_FB40__CTX_NAMESPACE_INVALID,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*525*/
   (335544845L,
    ctx_too_big,
    "ctx_too_big",
    IBP_MCE_FB40__CTX_TOO_BIG,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*526*/
   (335544846L,
    ctx_bad_argument,
    "ctx_bad_argument",
    IBP_MCE_FB40__CTX_BAD_ARGUMENT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*527*/
   (335544847L,
    identifier_too_long,
    "identifier_too_long",
    IBP_MCE_FB40__IDENTIFIER_TOO_LONG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*528*/
   (335544848L,
    except2,
    "except2",
    IBP_MCE_FB40__EXCEPT2,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*529*/
   (335544849L,
    malformed_string,
    "malformed_string",
    IBP_MCE_FB40__MALFORMED_STRING,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*530*/
   (335544850L,
    prc_out_param_mismatch,
    "prc_out_param_mismatch",
    IBP_MCE_FB40__PRC_OUT_PARAM_MISMATCH,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*531*/
   (335544851L,
    command_end_err2,
    "command_end_err2",
    IBP_MCE_FB40__COMMAND_END_ERR2,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*532*/
   (335544852L,
    partner_idx_incompat_type,
    "partner_idx_incompat_type",
    IBP_MCE_FB40__PARTNER_IDX_INCOMPAT_TYPE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*533*/
   (335544853L,
    bad_substring_length,
    "bad_substring_length",
    IBP_MCE_FB40__BAD_SUBSTRING_LENGTH,
    IBP_SQLSTATE__22011__DATA_EXCEPTION_SUBSTRING_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*534*/
   (335544854L,
    charset_not_installed,
    "charset_not_installed",
    IBP_MCE_FB40__CHARSET_NOT_INSTALLED,
    IBP_SQLSTATE__2C000__INVALID_CHARACTER_SET_NAME_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*535*/
   (335544855L,
    collation_not_installed,
    "collation_not_installed",
    IBP_MCE_FB40__COLLATION_NOT_INSTALLED,
    IBP_SQLSTATE__22021__DATA_EXCEPTION_CHARACTER_NOT_IN_REPERTOIRE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*536*/
   (335544856L,
    att_shutdown,
    "att_shutdown",
    IBP_MCE_FB40__ATT_SHUTDOWN,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*537*/
   (335544857L,
    blobtoobig,
    "blobtoobig",
    IBP_MCE_FB40__BLOBTOOBIG,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*538*/
   (335544858L,
    must_have_phys_field,
    "must_have_phys_field",
    IBP_MCE_FB40__MUST_HAVE_PHYS_FIELD,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*539*/
   (335544859L,
    invalid_time_precision,
    "invalid_time_precision",
    IBP_MCE_FB40__INVALID_TIME_PRECISION,
    IBP_SQLSTATE__22007__DATA_EXCEPTION_INVALID_DATETIME_FORMAT,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*540*/
   (335544860L,
    blob_convert_error,
    "blob_convert_error",
    IBP_MCE_FB40__BLOB_CONVERT_ERROR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*541*/
   (335544861L,
    array_convert_error,
    "array_convert_error",
    IBP_MCE_FB40__ARRAY_CONVERT_ERROR,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*542*/
   (335544862L,
    record_lock_not_supp,
    "record_lock_not_supp",
    IBP_MCE_FB40__RECORD_LOCK_NOT_SUPP,
    IBP_SQLSTATE__40001__TRANSACTION_ROLLBACK_SERIALIZATION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*543*/
   (335544863L,
    partner_idx_not_found,
    "partner_idx_not_found",
    IBP_MCE_FB40__PARTNER_IDX_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*544*/
   (335544864L,
    tra_num_exc,
    "tra_num_exc",
    IBP_MCE_FB40__TRA_NUM_EXC,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*545*/
   (335544865L,
    field_disappeared,
    "field_disappeared",
    IBP_MCE_FB40__FIELD_DISAPPEARED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*546*/
   (335544866L,
    met_wrong_gtt_scope,
    "met_wrong_gtt_scope",
    IBP_MCE_FB40__MET_WRONG_GTT_SCOPE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*547*/
   (335544867L,
    subtype_for_internal_use,
    "subtype_for_internal_use",
    IBP_MCE_FB40__SUBTYPE_FOR_INTERNAL_USE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*548*/
   (335544868L,
    illegal_prc_type,
    "illegal_prc_type",
    IBP_MCE_FB40__ILLEGAL_PRC_TYPE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*549*/
   (335544869L,
    invalid_sort_datatype,
    "invalid_sort_datatype",
    IBP_MCE_FB40__INVALID_SORT_DATATYPE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*550*/
   (335544870L,
    collation_name,
    "collation_name",
    IBP_MCE_FB40__COLLATION_NAME,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*551*/
   (335544871L,
    domain_name,
    "domain_name",
    IBP_MCE_FB40__DOMAIN_NAME,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*552*/
   (335544872L,
    domnotdef,
    "domnotdef",
    IBP_MCE_FB40__DOMNOTDEF,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*553*/
   (335544873L,
    array_max_dimensions,
    "array_max_dimensions",
    IBP_MCE_FB40__ARRAY_MAX_DIMENSIONS,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*554*/
   (335544874L,
    max_db_per_trans_allowed,
    "max_db_per_trans_allowed",
    IBP_MCE_FB40__MAX_DB_PER_TRANS_ALLOWED,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*555*/
   (335544875L,
    bad_debug_format,
    "bad_debug_format",
    IBP_MCE_FB40__BAD_DEBUG_FORMAT,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*556*/
   (335544876L,
    bad_proc_BLR,
    "bad_proc_BLR",
    IBP_MCE_FB40__BAD_PROC_BLR,
    IBP_SQLSTATE__2F000__SQL_ROUTINE_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*557*/
   (335544877L,
    key_too_big,
    "key_too_big",
    IBP_MCE_FB40__KEY_TOO_BIG,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*558*/
   (335544878L,
    concurrent_transaction,
    "concurrent_transaction",
    IBP_MCE_FB40__CONCURRENT_TRANSACTION,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*559*/
   (335544879L,
    not_valid_for_var,
    "not_valid_for_var",
    IBP_MCE_FB40__NOT_VALID_FOR_VAR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*560*/
   (335544880L,
    not_valid_for,
    "not_valid_for",
    IBP_MCE_FB40__NOT_VALID_FOR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*561*/
   (335544881L,
    need_difference,
    "need_difference",
    IBP_MCE_FB40__NEED_DIFFERENCE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*562*/
   (335544882L,
    long_login,
    "long_login",
    IBP_MCE_FB40__LONG_LOGIN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*563*/
   (335544883L,
    fldnotdef2,
    "fldnotdef2",
    IBP_MCE_FB40__FLDNOTDEF2,
    IBP_SQLSTATE__42S22__ODBC__COLUMN_NOT_FOUND,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*564*/
   (335544884L,
    invalid_similar_pattern,
    "invalid_similar_pattern",
    IBP_MCE_FB40__INVALID_SIMILAR_PATTERN,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*565*/
   (335544885L,
    bad_teb_form,
    "bad_teb_form",
    IBP_MCE_FB40__BAD_TEB_FORM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*566*/
   (335544886L,
    tpb_multiple_txn_isolation,
    "tpb_multiple_txn_isolation",
    IBP_MCE_FB40__TPB_MULTIPLE_TXN_ISOLATION,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*567*/
   (335544887L,
    tpb_reserv_before_table,
    "tpb_reserv_before_table",
    IBP_MCE_FB40__TPB_RESERV_BEFORE_TABLE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*568*/
   (335544888L,
    tpb_multiple_spec,
    "tpb_multiple_spec",
    IBP_MCE_FB40__TPB_MULTIPLE_SPEC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*569*/
   (335544889L,
    tpb_option_without_rc,
    "tpb_option_without_rc",
    IBP_MCE_FB40__TPB_OPTION_WITHOUT_RC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*570*/
   (335544890L,
    tpb_conflicting_options,
    "tpb_conflicting_options",
    IBP_MCE_FB40__TPB_CONFLICTING_OPTIONS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*571*/
   (335544891L,
    tpb_reserv_missing_tlen,
    "tpb_reserv_missing_tlen",
    IBP_MCE_FB40__TPB_RESERV_MISSING_TLEN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*572*/
   (335544892L,
    tpb_reserv_long_tlen,
    "tpb_reserv_long_tlen",
    IBP_MCE_FB40__TPB_RESERV_LONG_TLEN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*573*/
   (335544893L,
    tpb_reserv_missing_tname,
    "tpb_reserv_missing_tname",
    IBP_MCE_FB40__TPB_RESERV_MISSING_TNAME,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*574*/
   (335544894L,
    tpb_reserv_corrup_tlen,
    "tpb_reserv_corrup_tlen",
    IBP_MCE_FB40__TPB_RESERV_CORRUP_TLEN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*575*/
   (335544895L,
    tpb_reserv_null_tlen,
    "tpb_reserv_null_tlen",
    IBP_MCE_FB40__TPB_RESERV_NULL_TLEN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*576*/
   (335544896L,
    tpb_reserv_relnotfound,
    "tpb_reserv_relnotfound",
    IBP_MCE_FB40__TPB_RESERV_RELNOTFOUND,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*577*/
   (335544897L,
    tpb_reserv_baserelnotfound,
    "tpb_reserv_baserelnotfound",
    IBP_MCE_FB40__TPB_RESERV_BASERELNOTFOUND,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*578*/
   (335544898L,
    tpb_missing_len,
    "tpb_missing_len",
    IBP_MCE_FB40__TPB_MISSING_LEN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*579*/
   (335544899L,
    tpb_missing_value,
    "tpb_missing_value",
    IBP_MCE_FB40__TPB_MISSING_VALUE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*580*/
   (335544900L,
    tpb_corrupt_len,
    "tpb_corrupt_len",
    IBP_MCE_FB40__TPB_CORRUPT_LEN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*581*/
   (335544901L,
    tpb_null_len,
    "tpb_null_len",
    IBP_MCE_FB40__TPB_NULL_LEN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*582*/
   (335544902L,
    tpb_overflow_len,
    "tpb_overflow_len",
    IBP_MCE_FB40__TPB_OVERFLOW_LEN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*583*/
   (335544903L,
    tpb_invalid_value,
    "tpb_invalid_value",
    IBP_MCE_FB40__TPB_INVALID_VALUE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*584*/
   (335544904L,
    tpb_reserv_stronger_wng,
    "tpb_reserv_stronger_wng",
    IBP_MCE_FB40__TPB_RESERV_STRONGER_WNG,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*585*/
   (335544905L,
    tpb_reserv_stronger,
    "tpb_reserv_stronger",
    IBP_MCE_FB40__TPB_RESERV_STRONGER,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*586*/
   (335544906L,
    tpb_reserv_max_recursion,
    "tpb_reserv_max_recursion",
    IBP_MCE_FB40__TPB_RESERV_MAX_RECURSION,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*587*/
   (335544907L,
    tpb_reserv_virtualtbl,
    "tpb_reserv_virtualtbl",
    IBP_MCE_FB40__TPB_RESERV_VIRTUALTBL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*588*/
   (335544908L,
    tpb_reserv_systbl,
    "tpb_reserv_systbl",
    IBP_MCE_FB40__TPB_RESERV_SYSTBL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*589*/
   (335544909L,
    tpb_reserv_temptbl,
    "tpb_reserv_temptbl",
    IBP_MCE_FB40__TPB_RESERV_TEMPTBL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*590*/
   (335544910L,
    tpb_readtxn_after_writelock,
    "tpb_readtxn_after_writelock",
    IBP_MCE_FB40__TPB_READTXN_AFTER_WRITELOCK,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*591*/
   (335544911L,
    tpb_writelock_after_readtxn,
    "tpb_writelock_after_readtxn",
    IBP_MCE_FB40__TPB_WRITELOCK_AFTER_READTXN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*592*/
   (335544912L,
    time_range_exceeded,
    "time_range_exceeded",
    IBP_MCE_FB40__TIME_RANGE_EXCEEDED,
    IBP_SQLSTATE__22008__DATA_EXCEPTION_DATETIME_FIELD_OVERFLOW,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*593*/
   (335544913L,
    datetime_range_exceeded,
    "datetime_range_exceeded",
    IBP_MCE_FB40__DATETIME_RANGE_EXCEEDED,
    IBP_SQLSTATE__22008__DATA_EXCEPTION_DATETIME_FIELD_OVERFLOW,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*594*/
   (335544914L,
    string_truncation,
    "string_truncation",
    IBP_MCE_FB40__STRING_TRUNCATION,
    IBP_SQLSTATE__22001__DATA_EXCEPTION_STRING_DATA_RIGHT_TRUNCATION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*595*/
   (335544915L,
    blob_truncation,
    "blob_truncation",
    IBP_MCE_FB40__BLOB_TRUNCATION,
    IBP_SQLSTATE__22001__DATA_EXCEPTION_STRING_DATA_RIGHT_TRUNCATION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*596*/
   (335544916L,
    numeric_out_of_range,
    "numeric_out_of_range",
    IBP_MCE_FB40__NUMERIC_OUT_OF_RANGE,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*597*/
   (335544917L,
    shutdown_timeout,
    "shutdown_timeout",
    IBP_MCE_FB40__SHUTDOWN_TIMEOUT,
    IBP_SQLSTATE__HYT00__ODBC__TIMEOUT_EXPIRED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*598*/
   (335544918L,
    att_handle_busy,
    "att_handle_busy",
    IBP_MCE_FB40__ATT_HANDLE_BUSY,
    IBP_SQLSTATE__HY010__ODBC__FUNCTION_SEQUENCE_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*599*/
   (335544919L,
    bad_udf_freeit,
    "bad_udf_freeit",
    IBP_MCE_FB40__BAD_UDF_FREEIT,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*600*/
   (335544920L,
    eds_provider_not_found,
    "eds_provider_not_found",
    IBP_MCE_FB40__EDS_PROVIDER_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*601*/
   (335544921L,
    eds_connection,
    "eds_connection",
    IBP_MCE_FB40__EDS_CONNECTION,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*602*/
   (335544922L,
    eds_preprocess,
    "eds_preprocess",
    IBP_MCE_FB40__EDS_PREPROCESS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*603*/
   (335544923L,
    eds_stmt_expected,
    "eds_stmt_expected",
    IBP_MCE_FB40__EDS_STMT_EXPECTED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*604*/
   (335544924L,
    eds_prm_name_expected,
    "eds_prm_name_expected",
    IBP_MCE_FB40__EDS_PRM_NAME_EXPECTED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*605*/
   (335544925L,
    eds_unclosed_comment,
    "eds_unclosed_comment",
    IBP_MCE_FB40__EDS_UNCLOSED_COMMENT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*606*/
   (335544926L,
    eds_statement,
    "eds_statement",
    IBP_MCE_FB40__EDS_STATEMENT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*607*/
   (335544927L,
    eds_input_prm_mismatch,
    "eds_input_prm_mismatch",
    IBP_MCE_FB40__EDS_INPUT_PRM_MISMATCH,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*608*/
   (335544928L,
    eds_output_prm_mismatch,
    "eds_output_prm_mismatch",
    IBP_MCE_FB40__EDS_OUTPUT_PRM_MISMATCH,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*609*/
   (335544929L,
    eds_input_prm_not_set,
    "eds_input_prm_not_set",
    IBP_MCE_FB40__EDS_INPUT_PRM_NOT_SET,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*610*/
   (335544930L,
    too_big_blr,
    "too_big_blr",
    IBP_MCE_FB40__TOO_BIG_BLR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*611*/
   (335544931L,
    montabexh,
    "montabexh",
    IBP_MCE_FB40__MONTABEXH,
    IBP_SQLSTATE__HY001__ODBC__MEMORY_ALLOCATION_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*612*/
   (335544932L,
    modnotfound,
    "modnotfound",
    IBP_MCE_FB40__MODNOTFOUND,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*613*/
   (335544933L,
    nothing_to_cancel,
    "nothing_to_cancel",
    IBP_MCE_FB40__NOTHING_TO_CANCEL,
    IBP_SQLSTATE__HY018__ODBC__SERVER_DECLINED_CANCEL_REQUEST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*614*/
   (335544934L,
    ibutil_not_loaded,
    "ibutil_not_loaded",
    IBP_MCE_FB40__IBUTIL_NOT_LOADED,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*615*/
   (335544935L,
    circular_computed,
    "circular_computed",
    IBP_MCE_FB40__CIRCULAR_COMPUTED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*616*/
   (335544936L,
    psw_db_error,
    "psw_db_error",
    IBP_MCE_FB40__PSW_DB_ERROR,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*617*/
   (335544937L,
    invalid_type_datetime_op,
    "invalid_type_datetime_op",
    IBP_MCE_FB40__INVALID_TYPE_DATETIME_OP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*618*/
   (335544938L,
    onlycan_add_timetodate,
    "onlycan_add_timetodate",
    IBP_MCE_FB40__ONLYCAN_ADD_TIMETODATE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*619*/
   (335544939L,
    onlycan_add_datetotime,
    "onlycan_add_datetotime",
    IBP_MCE_FB40__ONLYCAN_ADD_DATETOTIME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*620*/
   (335544940L,
    onlycansub_tstampfromtstamp,
    "onlycansub_tstampfromtstamp",
    IBP_MCE_FB40__ONLYCANSUB_TSTAMPFROMTSTAMP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*621*/
   (335544941L,
    onlyoneop_mustbe_tstamp,
    "onlyoneop_mustbe_tstamp",
    IBP_MCE_FB40__ONLYONEOP_MUSTBE_TSTAMP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*622*/
   (335544942L,
    invalid_extractpart_time,
    "invalid_extractpart_time",
    IBP_MCE_FB40__INVALID_EXTRACTPART_TIME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*623*/
   (335544943L,
    invalid_extractpart_date,
    "invalid_extractpart_date",
    IBP_MCE_FB40__INVALID_EXTRACTPART_DATE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*624*/
   (335544944L,
    invalidarg_extract,
    "invalidarg_extract",
    IBP_MCE_FB40__INVALIDARG_EXTRACT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*625*/
   (335544945L,
    sysf_argmustbe_exact,
    "sysf_argmustbe_exact",
    IBP_MCE_FB40__SYSF_ARGMUSTBE_EXACT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*626*/
   (335544946L,
    sysf_argmustbe_exact_or_fp,
    "sysf_argmustbe_exact_or_fp",
    IBP_MCE_FB40__SYSF_ARGMUSTBE_EXACT_OR_FP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*627*/
   (335544947L,
    sysf_argviolates_uuidtype,
    "sysf_argviolates_uuidtype",
    IBP_MCE_FB40__SYSF_ARGVIOLATES_UUIDTYPE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*628*/
   (335544948L,
    sysf_argviolates_uuidlen,
    "sysf_argviolates_uuidlen",
    IBP_MCE_FB40__SYSF_ARGVIOLATES_UUIDLEN,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*629*/
   (335544949L,
    sysf_argviolates_uuidfmt,
    "sysf_argviolates_uuidfmt",
    IBP_MCE_FB40__SYSF_ARGVIOLATES_UUIDFMT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*630*/
   (335544950L,
    sysf_argviolates_guidigits,
    "sysf_argviolates_guidigits",
    IBP_MCE_FB40__SYSF_ARGVIOLATES_GUIDIGITS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*631*/
   (335544951L,
    sysf_invalid_addpart_time,
    "sysf_invalid_addpart_time",
    IBP_MCE_FB40__SYSF_INVALID_ADDPART_TIME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*632*/
   (335544952L,
    sysf_invalid_add_datetime,
    "sysf_invalid_add_datetime",
    IBP_MCE_FB40__SYSF_INVALID_ADD_DATETIME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*633*/
   (335544953L,
    sysf_invalid_addpart_dtime,
    "sysf_invalid_addpart_dtime",
    IBP_MCE_FB40__SYSF_INVALID_ADDPART_DTIME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*634*/
   (335544954L,
    sysf_invalid_add_dtime_rc,
    "sysf_invalid_add_dtime_rc",
    IBP_MCE_FB40__SYSF_INVALID_ADD_DTIME_RC,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*635*/
   (335544955L,
    sysf_invalid_diff_dtime,
    "sysf_invalid_diff_dtime",
    IBP_MCE_FB40__SYSF_INVALID_DIFF_DTIME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*636*/
   (335544956L,
    sysf_invalid_timediff,
    "sysf_invalid_timediff",
    IBP_MCE_FB40__SYSF_INVALID_TIMEDIFF,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*637*/
   (335544957L,
    sysf_invalid_tstamptimediff,
    "sysf_invalid_tstamptimediff",
    IBP_MCE_FB40__SYSF_INVALID_TSTAMPTIMEDIFF,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*638*/
   (335544958L,
    sysf_invalid_datetimediff,
    "sysf_invalid_datetimediff",
    IBP_MCE_FB40__SYSF_INVALID_DATETIMEDIFF,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*639*/
   (335544959L,
    sysf_invalid_diffpart,
    "sysf_invalid_diffpart",
    IBP_MCE_FB40__SYSF_INVALID_DIFFPART,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*640*/
   (335544960L,
    sysf_argmustbe_positive,
    "sysf_argmustbe_positive",
    IBP_MCE_FB40__SYSF_ARGMUSTBE_POSITIVE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*641*/
   (335544961L,
    sysf_basemustbe_positive,
    "sysf_basemustbe_positive",
    IBP_MCE_FB40__SYSF_BASEMUSTBE_POSITIVE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*642*/
   (335544962L,
    sysf_argnmustbe_nonneg,
    "sysf_argnmustbe_nonneg",
    IBP_MCE_FB40__SYSF_ARGNMUSTBE_NONNEG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*643*/
   (335544963L,
    sysf_argnmustbe_positive,
    "sysf_argnmustbe_positive",
    IBP_MCE_FB40__SYSF_ARGNMUSTBE_POSITIVE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*644*/
   (335544964L,
    sysf_invalid_zeropowneg,
    "sysf_invalid_zeropowneg",
    IBP_MCE_FB40__SYSF_INVALID_ZEROPOWNEG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*645*/
   (335544965L,
    sysf_invalid_negpowfp,
    "sysf_invalid_negpowfp",
    IBP_MCE_FB40__SYSF_INVALID_NEGPOWFP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*646*/
   (335544966L,
    sysf_invalid_scale,
    "sysf_invalid_scale",
    IBP_MCE_FB40__SYSF_INVALID_SCALE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*647*/
   (335544967L,
    sysf_argmustbe_nonneg,
    "sysf_argmustbe_nonneg",
    IBP_MCE_FB40__SYSF_ARGMUSTBE_NONNEG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*648*/
   (335544968L,
    sysf_binuuid_mustbe_str,
    "sysf_binuuid_mustbe_str",
    IBP_MCE_FB40__SYSF_BINUUID_MUSTBE_STR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*649*/
   (335544969L,
    sysf_binuuid_wrongsize,
    "sysf_binuuid_wrongsize",
    IBP_MCE_FB40__SYSF_BINUUID_WRONGSIZE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*650*/
   (335544970L,
    missing_required_spb,
    "missing_required_spb",
    IBP_MCE_FB40__MISSING_REQUIRED_SPB,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*651*/
   (335544971L,
    net_server_shutdown,
    "net_server_shutdown",
    IBP_MCE_FB40__NET_SERVER_SHUTDOWN,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*652*/
   (335544972L,
    bad_conn_str,
    "bad_conn_str",
    IBP_MCE_FB40__BAD_CONN_STR,
    IBP_SQLSTATE__08001__CONNECTION_EXCEPTION_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*653*/
   (335544973L,
    bad_epb_form,
    "bad_epb_form",
    IBP_MCE_FB40__BAD_EPB_FORM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*654*/
   (335544974L,
    no_threads,
    "no_threads",
    IBP_MCE_FB40__NO_THREADS,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*655*/
   (335544975L,
    net_event_connect_timeout,
    "net_event_connect_timeout",
    IBP_MCE_FB40__NET_EVENT_CONNECT_TIMEOUT,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*656*/
   (335544976L,
    sysf_argmustbe_nonzero,
    "sysf_argmustbe_nonzero",
    IBP_MCE_FB40__SYSF_ARGMUSTBE_NONZERO,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*657*/
   (335544977L,
    sysf_argmustbe_range_inc1_1,
    "sysf_argmustbe_range_inc1_1",
    IBP_MCE_FB40__SYSF_ARGMUSTBE_RANGE_INC1_1,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*658*/
   (335544978L,
    sysf_argmustbe_gteq_one,
    "sysf_argmustbe_gteq_one",
    IBP_MCE_FB40__SYSF_ARGMUSTBE_GTEQ_ONE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*659*/
   (335544979L,
    sysf_argmustbe_range_exc1_1,
    "sysf_argmustbe_range_exc1_1",
    IBP_MCE_FB40__SYSF_ARGMUSTBE_RANGE_EXC1_1,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*660*/
   (335544980L,
    internal_rejected_params,
    "internal_rejected_params",
    IBP_MCE_FB40__INTERNAL_REJECTED_PARAMS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*661*/
   (335544981L,
    sysf_fp_overflow,
    "sysf_fp_overflow",
    IBP_MCE_FB40__SYSF_FP_OVERFLOW,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*662*/
   (335544982L,
    udf_fp_overflow,
    "udf_fp_overflow",
    IBP_MCE_FB40__UDF_FP_OVERFLOW,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*663*/
   (335544983L,
    udf_fp_nan,
    "udf_fp_nan",
    IBP_MCE_FB40__UDF_FP_NAN,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*664*/
   (335544984L,
    instance_conflict,
    "instance_conflict",
    IBP_MCE_FB40__INSTANCE_CONFLICT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*665*/
   (335544985L,
    out_of_temp_space,
    "out_of_temp_space",
    IBP_MCE_FB40__OUT_OF_TEMP_SPACE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*666*/
   (335544986L,
    eds_expl_tran_ctrl,
    "eds_expl_tran_ctrl",
    IBP_MCE_FB40__EDS_EXPL_TRAN_CTRL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*667*/
   (335544987L,
    no_trusted_spb,
    "no_trusted_spb",
    IBP_MCE_FB40__NO_TRUSTED_SPB,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*668*/
   (335544988L,
    package_name,
    "package_name",
    IBP_MCE_FB40__PACKAGE_NAME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*669*/
   (335544989L,
    cannot_make_not_null,
    "cannot_make_not_null",
    IBP_MCE_FB40__CANNOT_MAKE_NOT_NULL,
    IBP_SQLSTATE__22006__DATA_EXCEPTION_INVALID_INTERVAL_FORMAT,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*670*/
   (335544990L,
    feature_removed,
    "feature_removed",
    IBP_MCE_FB40__FEATURE_REMOVED,
    IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*671*/
   (335544991L,
    view_name,
    "view_name",
    IBP_MCE_FB40__VIEW_NAME,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*672*/
   (335544992L,
    lock_dir_access,
    "lock_dir_access",
    IBP_MCE_FB40__LOCK_DIR_ACCESS,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*673*/
   (335544993L,
    invalid_fetch_option,
    "invalid_fetch_option",
    IBP_MCE_FB40__INVALID_FETCH_OPTION,
    IBP_SQLSTATE__HY106__ODBC__FETCH_TYPE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*674*/
   (335544994L,
    bad_fun_BLR,
    "bad_fun_BLR",
    IBP_MCE_FB40__BAD_FUN_BLR,
    IBP_SQLSTATE__2F000__SQL_ROUTINE_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*675*/
   (335544995L,
    func_pack_not_implemented,
    "func_pack_not_implemented",
    IBP_MCE_FB40__FUNC_PACK_NOT_IMPLEMENTED,
    IBP_SQLSTATE__2F000__SQL_ROUTINE_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*676*/
   (335544996L,
    proc_pack_not_implemented,
    "proc_pack_not_implemented",
    IBP_MCE_FB40__PROC_PACK_NOT_IMPLEMENTED,
    IBP_SQLSTATE__2F000__SQL_ROUTINE_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*677*/
   (335544997L,
    eem_func_not_returned,
    "eem_func_not_returned",
    IBP_MCE_FB40__EEM_FUNC_NOT_RETURNED,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*678*/
   (335544998L,
    eem_proc_not_returned,
    "eem_proc_not_returned",
    IBP_MCE_FB40__EEM_PROC_NOT_RETURNED,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*679*/
   (335544999L,
    eem_trig_not_returned,
    "eem_trig_not_returned",
    IBP_MCE_FB40__EEM_TRIG_NOT_RETURNED,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*680*/
   (335545000L,
    eem_bad_plugin_ver,
    "eem_bad_plugin_ver",
    IBP_MCE_FB40__EEM_BAD_PLUGIN_VER,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*681*/
   (335545001L,
    eem_engine_notfound,
    "eem_engine_notfound",
    IBP_MCE_FB40__EEM_ENGINE_NOTFOUND,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*682*/
   (335545002L,
    attachment_in_use,
    "attachment_in_use",
    IBP_MCE_FB40__ATTACHMENT_IN_USE,
    IBP_SQLSTATE__08002__CONNECTION_EXCEPTION_CONNECTION_NAME_IN_USE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*683*/
   (335545003L,
    transaction_in_use,
    "transaction_in_use",
    IBP_MCE_FB40__TRANSACTION_IN_USE,
    IBP_SQLSTATE__25S02__ODBC__TRANSACTION_IS_STILL_ACTIVE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*684*/
   (335545004L,
    pman_cannot_load_plugin,
    "pman_cannot_load_plugin",
    IBP_MCE_FB40__PMAN_CANNOT_LOAD_PLUGIN,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*685*/
   (335545005L,
    pman_module_notfound,
    "pman_module_notfound",
    IBP_MCE_FB40__PMAN_MODULE_NOTFOUND,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*686*/
   (335545006L,
    pman_entrypoint_notfound,
    "pman_entrypoint_notfound",
    IBP_MCE_FB40__PMAN_ENTRYPOINT_NOTFOUND,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*687*/
   (335545007L,
    pman_module_bad,
    "pman_module_bad",
    IBP_MCE_FB40__PMAN_MODULE_BAD,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*688*/
   (335545008L,
    pman_plugin_notfound,
    "pman_plugin_notfound",
    IBP_MCE_FB40__PMAN_PLUGIN_NOTFOUND,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*689*/
   (335545009L,
    sysf_invalid_trig_namespace,
    "sysf_invalid_trig_namespace",
    IBP_MCE_FB40__SYSF_INVALID_TRIG_NAMESPACE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*690*/
   (335545010L,
    unexpected_null,
    "unexpected_null",
    IBP_MCE_FB40__UNEXPECTED_NULL,
    IBP_SQLSTATE__22002__DATA_EXCEPTION_MOST_SPECIFIC_TYPE_MISMATCH,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*691*/
   (335545011L,
    type_notcompat_blob,
    "type_notcompat_blob",
    IBP_MCE_FB40__TYPE_NOTCOMPAT_BLOB,
    IBP_SQLSTATE__2200G__DATA_EXCEPTION_NULL_VALUE_NO_INDICATOR_PARAMETER,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*692*/
   (335545012L,
    invalid_date_val,
    "invalid_date_val",
    IBP_MCE_FB40__INVALID_DATE_VAL,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*693*/
   (335545013L,
    invalid_time_val,
    "invalid_time_val",
    IBP_MCE_FB40__INVALID_TIME_VAL,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*694*/
   (335545014L,
    invalid_timestamp_val,
    "invalid_timestamp_val",
    IBP_MCE_FB40__INVALID_TIMESTAMP_VAL,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*695*/
   (335545015L,
    invalid_index_val,
    "invalid_index_val",
    IBP_MCE_FB40__INVALID_INDEX_VAL,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*696*/
   (335545016L,
    formatted_exception,
    "formatted_exception",
    IBP_MCE_FB40__FORMATTED_EXCEPTION,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*697*/
   (335545017L,
    async_active,
    "async_active",
    IBP_MCE_FB40__ASYNC_ACTIVE,
    IBP_SQLSTATE__HY018__ODBC__SERVER_DECLINED_CANCEL_REQUEST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*698*/
   (335545018L,
    private_function,
    "private_function",
    IBP_MCE_FB40__PRIVATE_FUNCTION,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*699*/
   (335545019L,
    private_procedure,
    "private_procedure",
    IBP_MCE_FB40__PRIVATE_PROCEDURE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*700*/
   (335545020L,
    request_outdated,
    "request_outdated",
    IBP_MCE_FB40__REQUEST_OUTDATED,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*701*/
   (335545021L,
    bad_events_handle,
    "bad_events_handle",
    IBP_MCE_FB40__BAD_EVENTS_HANDLE,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*702*/
   (335545022L,
    cannot_copy_stmt,
    "cannot_copy_stmt",
    IBP_MCE_FB40__CANNOT_COPY_STMT,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*703*/
   (335545023L,
    invalid_boolean_usage,
    "invalid_boolean_usage",
    IBP_MCE_FB40__INVALID_BOOLEAN_USAGE,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*704*/
   (335545024L,
    sysf_argscant_both_be_zero,
    "sysf_argscant_both_be_zero",
    IBP_MCE_FB40__SYSF_ARGSCANT_BOTH_BE_ZERO,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*705*/
   (335545025L,
    spb_no_id,
    "spb_no_id",
    IBP_MCE_FB40__SPB_NO_ID,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*706*/
   (335545026L,
    ee_blr_mismatch_null,
    "ee_blr_mismatch_null",
    IBP_MCE_FB40__EE_BLR_MISMATCH_NULL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*707*/
   (335545027L,
    ee_blr_mismatch_length,
    "ee_blr_mismatch_length",
    IBP_MCE_FB40__EE_BLR_MISMATCH_LENGTH,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*708*/
   (335545028L,
    ss_out_of_bounds,
    "ss_out_of_bounds",
    IBP_MCE_FB40__SS_OUT_OF_BOUNDS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*709*/
   (335545029L,
    missing_data_structures,
    "missing_data_structures",
    IBP_MCE_FB40__MISSING_DATA_STRUCTURES,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*710*/
   (335545030L,
    protect_sys_tab,
    "protect_sys_tab",
    IBP_MCE_FB40__PROTECT_SYS_TAB,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*711*/
   (335545031L,
    libtommath_generic,
    "libtommath_generic",
    IBP_MCE_FB40__LIBTOMMATH_GENERIC,
    IBP_SQLSTATE__2F000__SQL_ROUTINE_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*712*/
   (335545032L,
    wroblrver2,
    "wroblrver2",
    IBP_MCE_FB40__WROBLRVER2,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*713*/
   (335545033L,
    trunc_limits,
    "trunc_limits",
    IBP_MCE_FB40__TRUNC_LIMITS,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*714*/
   (335545034L,
    info_access,
    "info_access",
    IBP_MCE_FB40__INFO_ACCESS,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*715*/
   (335545035L,
    svc_no_stdin,
    "svc_no_stdin",
    IBP_MCE_FB40__SVC_NO_STDIN,
    IBP_SQLSTATE__HY024__ODBC__INVALID_ATTRIBUTE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*716*/
   (335545036L,
    svc_start_failed,
    "svc_start_failed",
    IBP_MCE_FB40__SVC_START_FAILED,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*717*/
   (335545037L,
    svc_no_switches,
    "svc_no_switches",
    IBP_MCE_FB40__SVC_NO_SWITCHES,
    IBP_SQLSTATE__HY024__ODBC__INVALID_ATTRIBUTE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*718*/
   (335545038L,
    svc_bad_size,
    "svc_bad_size",
    IBP_MCE_FB40__SVC_BAD_SIZE,
    IBP_SQLSTATE__HY109__ODBC__INVALID_CURSOR_POSITION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*719*/
   (335545039L,
    no_crypt_plugin,
    "no_crypt_plugin",
    IBP_MCE_FB40__NO_CRYPT_PLUGIN,
    IBP_SQLSTATE__HY024__ODBC__INVALID_ATTRIBUTE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*720*/
   (335545040L,
    cp_name_too_long,
    "cp_name_too_long",
    IBP_MCE_FB40__CP_NAME_TOO_LONG,
    IBP_SQLSTATE__22001__DATA_EXCEPTION_STRING_DATA_RIGHT_TRUNCATION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*721*/
   (335545041L,
    cp_process_active,
    "cp_process_active",
    IBP_MCE_FB40__CP_PROCESS_ACTIVE,
    IBP_SQLSTATE__42818__THE_OPERANDS_OF_AN_ARITHMETIC_OR_COMPARISON_OPERATION_ARE_NOT_COMPARABLE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*722*/
   (335545042L,
    cp_already_crypted,
    "cp_already_crypted",
    IBP_MCE_FB40__CP_ALREADY_CRYPTED,
    IBP_SQLSTATE__42818__THE_OPERANDS_OF_AN_ARITHMETIC_OR_COMPARISON_OPERATION_ARE_NOT_COMPARABLE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*723*/
   (335545043L,
    decrypt_error,
    "decrypt_error",
    IBP_MCE_FB40__DECRYPT_ERROR,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*724*/
   (335545044L,
    no_providers,
    "no_providers",
    IBP_MCE_FB40__NO_PROVIDERS,
    IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*725*/
   (335545045L,
    null_spb,
    "null_spb",
    IBP_MCE_FB40__NULL_SPB,
    IBP_SQLSTATE__42818__THE_OPERANDS_OF_AN_ARITHMETIC_OR_COMPARISON_OPERATION_ARE_NOT_COMPARABLE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*726*/
   (335545046L,
    max_args_exceeded,
    "max_args_exceeded",
    IBP_MCE_FB40__MAX_ARGS_EXCEEDED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*727*/
   (335545047L,
    ee_blr_mismatch_names_count,
    "ee_blr_mismatch_names_count",
    IBP_MCE_FB40__EE_BLR_MISMATCH_NAMES_COUNT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*728*/
   (335545048L,
    ee_blr_mismatch_name_not_found,
    "ee_blr_mismatch_name_not_found",
    IBP_MCE_FB40__EE_BLR_MISMATCH_NAME_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*729*/
   (335545049L,
    bad_result_set,
    "bad_result_set",
    IBP_MCE_FB40__BAD_RESULT_SET,
    IBP_SQLSTATE__26000__INVALID_SQL_STATEMENT_NAME_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*730*/
   (335545050L,
    wrong_message_length,
    "wrong_message_length",
    IBP_MCE_FB40__WRONG_MESSAGE_LENGTH,
    IBP_SQLSTATE__07000__DYNAMIC_SQL_ERROR_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*731*/
   (335545051L,
    no_output_format,
    "no_output_format",
    IBP_MCE_FB40__NO_OUTPUT_FORMAT,
    IBP_SQLSTATE__07000__DYNAMIC_SQL_ERROR_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*732*/
   (335545052L,
    item_finish,
    "item_finish",
    IBP_MCE_FB40__ITEM_FINISH,
    IBP_SQLSTATE__HY021__ODBC__INCONSISTENT_DESCRIPTOR_INFORMATION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*733*/
   (335545053L,
    miss_config,
    "miss_config",
    IBP_MCE_FB40__MISS_CONFIG,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*734*/
   (335545054L,
    conf_line,
    "conf_line",
    IBP_MCE_FB40__CONF_LINE,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*735*/
   (335545055L,
    conf_include,
    "conf_include",
    IBP_MCE_FB40__CONF_INCLUDE,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*736*/
   (335545056L,
    include_depth,
    "include_depth",
    IBP_MCE_FB40__INCLUDE_DEPTH,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*737*/
   (335545057L,
    include_miss,
    "include_miss",
    IBP_MCE_FB40__INCLUDE_MISS,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*738*/
   (335545058L,
    protect_ownership,
    "protect_ownership",
    IBP_MCE_FB40__PROTECT_OWNERSHIP,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*739*/
   (335545059L,
    badvarnum,
    "badvarnum",
    IBP_MCE_FB40__BADVARNUM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*740*/
   (335545060L,
    sec_context,
    "sec_context",
    IBP_MCE_FB40__SEC_CONTEXT,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*741*/
   (335545061L,
    multi_segment,
    "multi_segment",
    IBP_MCE_FB40__MULTI_SEGMENT,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*742*/
   (335545062L,
    login_changed,
    "login_changed",
    IBP_MCE_FB40__LOGIN_CHANGED,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*743*/
   (335545063L,
    auth_handshake_limit,
    "auth_handshake_limit",
    IBP_MCE_FB40__AUTH_HANDSHAKE_LIMIT,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*744*/
   (335545064L,
    wirecrypt_incompatible,
    "wirecrypt_incompatible",
    IBP_MCE_FB40__WIRECRYPT_INCOMPATIBLE,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*745*/
   (335545065L,
    miss_wirecrypt,
    "miss_wirecrypt",
    IBP_MCE_FB40__MISS_WIRECRYPT,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*746*/
   (335545066L,
    wirecrypt_key,
    "wirecrypt_key",
    IBP_MCE_FB40__WIRECRYPT_KEY,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*747*/
   (335545067L,
    wirecrypt_plugin,
    "wirecrypt_plugin",
    IBP_MCE_FB40__WIRECRYPT_PLUGIN,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*748*/
   (335545068L,
    secdb_name,
    "secdb_name",
    IBP_MCE_FB40__SECDB_NAME,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*749*/
   (335545069L,
    auth_data,
    "auth_data",
    IBP_MCE_FB40__AUTH_DATA,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*750*/
   (335545070L,
    auth_datalength,
    "auth_datalength",
    IBP_MCE_FB40__AUTH_DATALENGTH,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*751*/
   (335545071L,
    info_unprepared_stmt,
    "info_unprepared_stmt",
    IBP_MCE_FB40__INFO_UNPREPARED_STMT,
    IBP_SQLSTATE__HY007__ODBC__ASSOCIATED_STATEMENT_IS_NOT_PREPARED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*752*/
   (335545072L,
    idx_key_value,
    "idx_key_value",
    IBP_MCE_FB40__IDX_KEY_VALUE,
    IBP_SQLSTATE__HY007__ODBC__ASSOCIATED_STATEMENT_IS_NOT_PREPARED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*753*/
   (335545073L,
    forupdate_virtualtbl,
    "forupdate_virtualtbl",
    IBP_MCE_FB40__FORUPDATE_VIRTUALTBL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*754*/
   (335545074L,
    forupdate_systbl,
    "forupdate_systbl",
    IBP_MCE_FB40__FORUPDATE_SYSTBL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*755*/
   (335545075L,
    forupdate_temptbl,
    "forupdate_temptbl",
    IBP_MCE_FB40__FORUPDATE_TEMPTBL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*756*/
   (335545076L,
    cant_modify_sysobj,
    "cant_modify_sysobj",
    IBP_MCE_FB40__CANT_MODIFY_SYSOBJ,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*757*/
   (335545077L,
    server_misconfigured,
    "server_misconfigured",
    IBP_MCE_FB40__SERVER_MISCONFIGURED,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*758*/
   (335545078L,
    alter_role,
    "alter_role",
    IBP_MCE_FB40__ALTER_ROLE,
    IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*759*/
   (335545079L,
    map_already_exists,
    "map_already_exists",
    IBP_MCE_FB40__MAP_ALREADY_EXISTS,
    IBP_SQLSTATE__42S01__ODBC__BASE_TABLE_OR_VIEW_ALREADY_EXISTS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*760*/
   (335545080L,
    map_not_exists,
    "map_not_exists",
    IBP_MCE_FB40__MAP_NOT_EXISTS,
    IBP_SQLSTATE__42S02__ODBC__BASE_TABLE_OR_VIEW_NOT_FOUND,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*761*/
   (335545081L,
    map_load,
    "map_load",
    IBP_MCE_FB40__MAP_LOAD,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*762*/
   (335545082L,
    map_aster,
    "map_aster",
    IBP_MCE_FB40__MAP_ASTER,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*763*/
   (335545083L,
    map_multi,
    "map_multi",
    IBP_MCE_FB40__MAP_MULTI,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*764*/
   (335545084L,
    map_undefined,
    "map_undefined",
    IBP_MCE_FB40__MAP_UNDEFINED,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*765*/
   (335545085L,
    baddpb_damaged_mode,
    "baddpb_damaged_mode",
    IBP_MCE_FB40__BADDPB_DAMAGED_MODE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*766*/
   (335545086L,
    baddpb_buffers_range,
    "baddpb_buffers_range",
    IBP_MCE_FB40__BADDPB_BUFFERS_RANGE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*767*/
   (335545087L,
    baddpb_temp_buffers,
    "baddpb_temp_buffers",
    IBP_MCE_FB40__BADDPB_TEMP_BUFFERS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*768*/
   (335545088L,
    map_nodb,
    "map_nodb",
    IBP_MCE_FB40__MAP_NODB,
    IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*769*/
   (335545089L,
    map_notable,
    "map_notable",
    IBP_MCE_FB40__MAP_NOTABLE,
    IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*770*/
   (335545090L,
    miss_trusted_role,
    "miss_trusted_role",
    IBP_MCE_FB40__MISS_TRUSTED_ROLE,
    IBP_SQLSTATE__0P000__INVALID_ROLE_SPECIFICATION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*771*/
   (335545091L,
    set_invalid_role,
    "set_invalid_role",
    IBP_MCE_FB40__SET_INVALID_ROLE,
    IBP_SQLSTATE__0P000__INVALID_ROLE_SPECIFICATION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*772*/
   (335545092L,
    cursor_not_positioned,
    "cursor_not_positioned",
    IBP_MCE_FB40__CURSOR_NOT_POSITIONED,
    IBP_SQLSTATE__HY109__ODBC__INVALID_CURSOR_POSITION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*773*/
   (335545093L,
    dup_attribute,
    "dup_attribute",
    IBP_MCE_FB40__DUP_ATTRIBUTE,
    IBP_SQLSTATE__42702__AMBIGUOUS_COLUMN,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*774*/
   (335545094L,
    dyn_no_priv,
    "dyn_no_priv",
    IBP_MCE_FB40__DYN_NO_PRIV,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*775*/
   (335545095L,
    dsql_cant_grant_option,
    "dsql_cant_grant_option",
    IBP_MCE_FB40__DSQL_CANT_GRANT_OPTION,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*776*/
   (335545096L,
    read_conflict,
    "read_conflict",
    IBP_MCE_FB40__READ_CONFLICT,
    IBP_SQLSTATE__40001__TRANSACTION_ROLLBACK_SERIALIZATION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*777*/
   (335545097L,
    crdb_load,
    "crdb_load",
    IBP_MCE_FB40__CRDB_LOAD,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*778*/
   (335545098L,
    crdb_nodb,
    "crdb_nodb",
    IBP_MCE_FB40__CRDB_NODB,
    IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*779*/
   (335545099L,
    crdb_notable,
    "crdb_notable",
    IBP_MCE_FB40__CRDB_NOTABLE,
    IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*780*/
   (335545100L,
    interface_version_too_old,
    "interface_version_too_old",
    IBP_MCE_FB40__INTERFACE_VERSION_TOO_OLD,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*781*/
   (335545101L,
    fun_param_mismatch,
    "fun_param_mismatch",
    IBP_MCE_FB40__FUN_PARAM_MISMATCH,
    IBP_SQLSTATE__07001__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_DYNAMIC_PARAMETER_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*782*/
   (335545102L,
    savepoint_backout_err,
    "savepoint_backout_err",
    IBP_MCE_FB40__SAVEPOINT_BACKOUT_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*783*/
   (335545103L,
    domain_primary_key_notnull,
    "domain_primary_key_notnull",
    IBP_MCE_FB40__DOMAIN_PRIMARY_KEY_NOTNULL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*784*/
   (335545104L,
    invalid_attachment_charset,
    "invalid_attachment_charset",
    IBP_MCE_FB40__INVALID_ATTACHMENT_CHARSET,
    IBP_SQLSTATE__2C000__INVALID_CHARACTER_SET_NAME_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*785*/
   (335545105L,
    map_down,
    "map_down",
    IBP_MCE_FB40__MAP_DOWN,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*786*/
   (335545106L,
    login_error,
    "login_error",
    IBP_MCE_FB40__LOGIN_ERROR,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*787*/
   (335545107L,
    already_opened,
    "already_opened",
    IBP_MCE_FB40__ALREADY_OPENED,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*788*/
   (335545108L,
    bad_crypt_key,
    "bad_crypt_key",
    IBP_MCE_FB40__BAD_CRYPT_KEY,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*789*/
   (335545109L,
    encrypt_error,
    "encrypt_error",
    IBP_MCE_FB40__ENCRYPT_ERROR,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*790*/
   (335545110L,
    max_idx_depth,
    "max_idx_depth",
    IBP_MCE_FB40__MAX_IDX_DEPTH,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*791*/
   (335545111L,
    wrong_prvlg,
    "wrong_prvlg",
    IBP_MCE_FB40__WRONG_PRVLG,
    IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*792*/
   (335545112L,
    miss_prvlg,
    "miss_prvlg",
    IBP_MCE_FB40__MISS_PRVLG,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*793*/
   (335545113L,
    crypt_checksum,
    "crypt_checksum",
    IBP_MCE_FB40__CRYPT_CHECKSUM,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*794*/
   (335545114L,
    not_dba,
    "not_dba",
    IBP_MCE_FB40__NOT_DBA,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*795*/
   (335545115L,
    no_cursor,
    "no_cursor",
    IBP_MCE_FB40__NO_CURSOR,
    IBP_SQLSTATE__07005__DYNAMIC_SQL_ERROR_PREPARED_STATEMENT_NOT_A_CURSOR_SPECIFICATION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*796*/
   (335545116L,
    dsql_window_incompat_frames,
    "dsql_window_incompat_frames",
    IBP_MCE_FB40__DSQL_WINDOW_INCOMPAT_FRAMES,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*797*/
   (335545117L,
    dsql_window_range_multi_key,
    "dsql_window_range_multi_key",
    IBP_MCE_FB40__DSQL_WINDOW_RANGE_MULTI_KEY,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*798*/
   (335545118L,
    dsql_window_range_inv_key_type,
    "dsql_window_range_inv_key_type",
    IBP_MCE_FB40__DSQL_WINDOW_RANGE_INV_KEY_TYPE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*799*/
   (335545119L,
    dsql_window_frame_value_inv_type,
    "dsql_window_frame_value_inv_type",
    IBP_MCE_FB40__DSQL_WINDOW_FRAME_VALUE_INV_TYPE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*800*/
   (335545120L,
    window_frame_value_invalid,
    "window_frame_value_invalid",
    IBP_MCE_FB40__WINDOW_FRAME_VALUE_INVALID,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*801*/
   (335545121L,
    dsql_window_not_found,
    "dsql_window_not_found",
    IBP_MCE_FB40__DSQL_WINDOW_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*802*/
   (335545122L,
    dsql_window_cant_overr_part,
    "dsql_window_cant_overr_part",
    IBP_MCE_FB40__DSQL_WINDOW_CANT_OVERR_PART,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*803*/
   (335545123L,
    dsql_window_cant_overr_order,
    "dsql_window_cant_overr_order",
    IBP_MCE_FB40__DSQL_WINDOW_CANT_OVERR_ORDER,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*804*/
   (335545124L,
    dsql_window_cant_overr_frame,
    "dsql_window_cant_overr_frame",
    IBP_MCE_FB40__DSQL_WINDOW_CANT_OVERR_FRAME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*805*/
   (335545125L,
    dsql_window_duplicate,
    "dsql_window_duplicate",
    IBP_MCE_FB40__DSQL_WINDOW_DUPLICATE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*806*/
   (335545126L,
    sql_too_long,
    "sql_too_long",
    IBP_MCE_FB40__SQL_TOO_LONG,
    IBP_SQLSTATE__54001__STATEMENT_TOO_COMPLEX,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*807*/
   (335545127L,
    cfg_stmt_timeout,
    "cfg_stmt_timeout",
    IBP_MCE_FB40__CFG_STMT_TIMEOUT,
    IBP_SQLSTATE__HY008__ODBC__OPERATION_CANCELED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*808*/
   (335545128L,
    att_stmt_timeout,
    "att_stmt_timeout",
    IBP_MCE_FB40__ATT_STMT_TIMEOUT,
    IBP_SQLSTATE__HY008__ODBC__OPERATION_CANCELED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*809*/
   (335545129L,
    req_stmt_timeout,
    "req_stmt_timeout",
    IBP_MCE_FB40__REQ_STMT_TIMEOUT,
    IBP_SQLSTATE__HY008__ODBC__OPERATION_CANCELED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*810*/
   (335545130L,
    att_shut_killed,
    "att_shut_killed",
    IBP_MCE_FB40__ATT_SHUT_KILLED,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*811*/
   (335545131L,
    att_shut_idle,
    "att_shut_idle",
    IBP_MCE_FB40__ATT_SHUT_IDLE,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*812*/
   (335545132L,
    att_shut_db_down,
    "att_shut_db_down",
    IBP_MCE_FB40__ATT_SHUT_DB_DOWN,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*813*/
   (335545133L,
    att_shut_engine,
    "att_shut_engine",
    IBP_MCE_FB40__ATT_SHUT_ENGINE,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*814*/
   (335545134L,
    overriding_without_identity,
    "overriding_without_identity",
    IBP_MCE_FB40__OVERRIDING_WITHOUT_IDENTITY,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*815*/
   (335545135L,
    overriding_system_invalid,
    "overriding_system_invalid",
    IBP_MCE_FB40__OVERRIDING_SYSTEM_INVALID,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*816*/
   (335545136L,
    overriding_user_invalid,
    "overriding_user_invalid",
    IBP_MCE_FB40__OVERRIDING_USER_INVALID,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*817*/
   (335545137L,
    overriding_system_missing,
    "overriding_system_missing",
    IBP_MCE_FB40__OVERRIDING_SYSTEM_MISSING,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*818*/
   (335545138L,
    decprecision_err,
    "decprecision_err",
    IBP_MCE_FB40__DECPRECISION_ERR,
    IBP_SQLSTATE__HY104__ODBC__INVALID_PRECISION_OR_SCALE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*819*/
   (335545139L,
    decfloat_divide_by_zero,
    "decfloat_divide_by_zero",
    IBP_MCE_FB40__DECFLOAT_DIVIDE_BY_ZERO,
    IBP_SQLSTATE__22012__DATA_EXCEPTION_DIVISION_BY_ZERO,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*820*/
   (335545140L,
    decfloat_inexact_result,
    "decfloat_inexact_result",
    IBP_MCE_FB40__DECFLOAT_INEXACT_RESULT,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*821*/
   (335545141L,
    decfloat_invalid_operation,
    "decfloat_invalid_operation",
    IBP_MCE_FB40__DECFLOAT_INVALID_OPERATION,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*822*/
   (335545142L,
    decfloat_overflow,
    "decfloat_overflow",
    IBP_MCE_FB40__DECFLOAT_OVERFLOW,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    DB_E_DATAOVERFLOW)
 ADD_CODE         /*823*/
   (335545143L,
    decfloat_underflow,
    "decfloat_underflow",
    IBP_MCE_FB40__DECFLOAT_UNDERFLOW,
    IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*824*/
   (335545144L,
    subfunc_notdef,
    "subfunc_notdef",
    IBP_MCE_FB40__SUBFUNC_NOTDEF,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*825*/
   (335545145L,
    subproc_notdef,
    "subproc_notdef",
    IBP_MCE_FB40__SUBPROC_NOTDEF,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*826*/
   (335545146L,
    subfunc_signat,
    "subfunc_signat",
    IBP_MCE_FB40__SUBFUNC_SIGNAT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*827*/
   (335545147L,
    subproc_signat,
    "subproc_signat",
    IBP_MCE_FB40__SUBPROC_SIGNAT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*828*/
   (335545148L,
    subfunc_defvaldecl,
    "subfunc_defvaldecl",
    IBP_MCE_FB40__SUBFUNC_DEFVALDECL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*829*/
   (335545149L,
    subproc_defvaldecl,
    "subproc_defvaldecl",
    IBP_MCE_FB40__SUBPROC_DEFVALDECL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*830*/
   (335545150L,
    subfunc_not_impl,
    "subfunc_not_impl",
    IBP_MCE_FB40__SUBFUNC_NOT_IMPL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*831*/
   (335545151L,
    subproc_not_impl,
    "subproc_not_impl",
    IBP_MCE_FB40__SUBPROC_NOT_IMPL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*832*/
   (335545152L,
    sysf_invalid_hash_algorithm,
    "sysf_invalid_hash_algorithm",
    IBP_MCE_FB40__SYSF_INVALID_HASH_ALGORITHM,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*833*/
   (335545153L,
    expression_eval_index,
    "expression_eval_index",
    IBP_MCE_FB40__EXPRESSION_EVAL_INDEX,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*834*/
   (335545154L,
    invalid_decfloat_trap,
    "invalid_decfloat_trap",
    IBP_MCE_FB40__INVALID_DECFLOAT_TRAP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*835*/
   (335545155L,
    invalid_decfloat_round,
    "invalid_decfloat_round",
    IBP_MCE_FB40__INVALID_DECFLOAT_ROUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*836*/
   (335545156L,
    sysf_invalid_first_last_part,
    "sysf_invalid_first_last_part",
    IBP_MCE_FB40__SYSF_INVALID_FIRST_LAST_PART,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*837*/
   (335545157L,
    sysf_invalid_date_timestamp,
    "sysf_invalid_date_timestamp",
    IBP_MCE_FB40__SYSF_INVALID_DATE_TIMESTAMP,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*838*/
   (335545158L,
    precision_err2,
    "precision_err2",
    IBP_MCE_FB40__PRECISION_ERR2,
    IBP_SQLSTATE__HY104__ODBC__INVALID_PRECISION_OR_SCALE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*839*/
   (335545159L,
    bad_batch_handle,
    "bad_batch_handle",
    IBP_MCE_FB40__BAD_BATCH_HANDLE,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*840*/
   (335545160L,
    intl_char,
    "intl_char",
    IBP_MCE_FB40__INTL_CHAR,
    IBP_SQLSTATE__22021__DATA_EXCEPTION_CHARACTER_NOT_IN_REPERTOIRE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*841*/
   (335545161L,
    null_block,
    "null_block",
    IBP_MCE_FB40__NULL_BLOCK,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*842*/
   (335545162L,
    mixed_info,
    "mixed_info",
    IBP_MCE_FB40__MIXED_INFO,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*843*/
   (335545163L,
    unknown_info,
    "unknown_info",
    IBP_MCE_FB40__UNKNOWN_INFO,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*844*/
   (335545164L,
    bpb_version,
    "bpb_version",
    IBP_MCE_FB40__BPB_VERSION,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*845*/
   (335545165L,
    user_manager,
    "user_manager",
    IBP_MCE_FB40__USER_MANAGER,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*846*/
   (335545166L,
    icu_entrypoint,
    "icu_entrypoint",
    IBP_MCE_FB40__ICU_ENTRYPOINT,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*847*/
   (335545167L,
    icu_library,
    "icu_library",
    IBP_MCE_FB40__ICU_LIBRARY,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*848*/
   (335545168L,
    metadata_name,
    "metadata_name",
    IBP_MCE_FB40__METADATA_NAME,
    IBP_SQLSTATE__02000__NO_DATA_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*849*/
   (335545169L,
    tokens_parse,
    "tokens_parse",
    IBP_MCE_FB40__TOKENS_PARSE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*850*/
   (335545170L,
    iconv_open,
    "iconv_open",
    IBP_MCE_FB40__ICONV_OPEN,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*851*/
   (335545171L,
    batch_compl_range,
    "batch_compl_range",
    IBP_MCE_FB40__BATCH_COMPL_RANGE,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*852*/
   (335545172L,
    batch_compl_detail,
    "batch_compl_detail",
    IBP_MCE_FB40__BATCH_COMPL_DETAIL,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*853*/
   (335545173L,
    deflate_init,
    "deflate_init",
    IBP_MCE_FB40__DEFLATE_INIT,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*854*/
   (335545174L,
    inflate_init,
    "inflate_init",
    IBP_MCE_FB40__INFLATE_INIT,
    IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*855*/
   (335545175L,
    big_segment,
    "big_segment",
    IBP_MCE_FB40__BIG_SEGMENT,
    IBP_SQLSTATE__22026__DATA_EXCEPTION_STRING_DATA_LENGTH_MISMATCH,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*856*/
   (335545176L,
    batch_policy,
    "batch_policy",
    IBP_MCE_FB40__BATCH_POLICY,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*857*/
   (335545177L,
    batch_defbpb,
    "batch_defbpb",
    IBP_MCE_FB40__BATCH_DEFBPB,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*858*/
   (335545178L,
    batch_align,
    "batch_align",
    IBP_MCE_FB40__BATCH_ALIGN,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*859*/
   (335545179L,
    multi_segment_dup,
    "multi_segment_dup",
    IBP_MCE_FB40__MULTI_SEGMENT_DUP,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*860*/
   (335545180L,
    non_plugin_protocol,
    "non_plugin_protocol",
    IBP_MCE_FB40__NON_PLUGIN_PROTOCOL,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*861*/
   (335545181L,
    message_format,
    "message_format",
    IBP_MCE_FB40__MESSAGE_FORMAT,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*862*/
   (335545182L,
    batch_param_version,
    "batch_param_version",
    IBP_MCE_FB40__BATCH_PARAM_VERSION,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*863*/
   (335545183L,
    batch_msg_long,
    "batch_msg_long",
    IBP_MCE_FB40__BATCH_MSG_LONG,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*864*/
   (335545184L,
    batch_open,
    "batch_open",
    IBP_MCE_FB40__BATCH_OPEN,
    IBP_SQLSTATE__08002__CONNECTION_EXCEPTION_CONNECTION_NAME_IN_USE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*865*/
   (335545185L,
    batch_type,
    "batch_type",
    IBP_MCE_FB40__BATCH_TYPE,
    IBP_SQLSTATE__07003__DYNAMIC_SQL_ERROR_CURSOR_SPECIFICATION_CANNOT_BE_EXECUTED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*866*/
   (335545186L,
    batch_param,
    "batch_param",
    IBP_MCE_FB40__BATCH_PARAM,
    IBP_SQLSTATE__07001__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_DYNAMIC_PARAMETER_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*867*/
   (335545187L,
    batch_blobs,
    "batch_blobs",
    IBP_MCE_FB40__BATCH_BLOBS,
    IBP_SQLSTATE__07001__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_DYNAMIC_PARAMETER_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*868*/
   (335545188L,
    batch_blob_append,
    "batch_blob_append",
    IBP_MCE_FB40__BATCH_BLOB_APPEND,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*869*/
   (335545189L,
    batch_stream_align,
    "batch_stream_align",
    IBP_MCE_FB40__BATCH_STREAM_ALIGN,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*870*/
   (335545190L,
    batch_rpt_blob,
    "batch_rpt_blob",
    IBP_MCE_FB40__BATCH_RPT_BLOB,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*871*/
   (335545191L,
    batch_blob_buf,
    "batch_blob_buf",
    IBP_MCE_FB40__BATCH_BLOB_BUF,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*872*/
   (335545192L,
    batch_small_data,
    "batch_small_data",
    IBP_MCE_FB40__BATCH_SMALL_DATA,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*873*/
   (335545193L,
    batch_cont_bpb,
    "batch_cont_bpb",
    IBP_MCE_FB40__BATCH_CONT_BPB,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*874*/
   (335545194L,
    batch_big_bpb,
    "batch_big_bpb",
    IBP_MCE_FB40__BATCH_BIG_BPB,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*875*/
   (335545195L,
    batch_big_segment,
    "batch_big_segment",
    IBP_MCE_FB40__BATCH_BIG_SEGMENT,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*876*/
   (335545196L,
    batch_big_seg2,
    "batch_big_seg2",
    IBP_MCE_FB40__BATCH_BIG_SEG2,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*877*/
   (335545197L,
    batch_blob_id,
    "batch_blob_id",
    IBP_MCE_FB40__BATCH_BLOB_ID,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*878*/
   (335545198L,
    batch_too_big,
    "batch_too_big",
    IBP_MCE_FB40__BATCH_TOO_BIG,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*879*/
   (335545199L,
    num_literal,
    "num_literal",
    IBP_MCE_FB40__NUM_LITERAL,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*880*/
   (335545200L,
    map_event,
    "map_event",
    IBP_MCE_FB40__MAP_EVENT,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*881*/
   (335545201L,
    map_overflow,
    "map_overflow",
    IBP_MCE_FB40__MAP_OVERFLOW,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*882*/
   (335545202L,
    hdr_overflow,
    "hdr_overflow",
    IBP_MCE_FB40__HDR_OVERFLOW,
    IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*883*/
   (335545203L,
    vld_plugins,
    "vld_plugins",
    IBP_MCE_FB40__VLD_PLUGINS,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*884*/
   (335545204L,
    db_crypt_key,
    "db_crypt_key",
    IBP_MCE_FB40__DB_CRYPT_KEY,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*885*/
   (335545205L,
    no_keyholder_plugin,
    "no_keyholder_plugin",
    IBP_MCE_FB40__NO_KEYHOLDER_PLUGIN,
    IBP_SQLSTATE__HY024__ODBC__INVALID_ATTRIBUTE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*886*/
   (335545206L,
    ses_reset_err,
    "ses_reset_err",
    IBP_MCE_FB40__SES_RESET_ERR,
    IBP_SQLSTATE__01002__WARNING_DISCONNECT_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*887*/
   (335545207L,
    ses_reset_open_trans,
    "ses_reset_open_trans",
    IBP_MCE_FB40__SES_RESET_OPEN_TRANS,
    IBP_SQLSTATE__25S02__ODBC__TRANSACTION_IS_STILL_ACTIVE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*888*/
   (335545208L,
    ses_reset_warn,
    "ses_reset_warn",
    IBP_MCE_FB40__SES_RESET_WARN,
    IBP_SQLSTATE__01000__WARNING_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*889*/
   (335545209L,
    ses_reset_tran_rollback,
    "ses_reset_tran_rollback",
    IBP_MCE_FB40__SES_RESET_TRAN_ROLLBACK,
    IBP_SQLSTATE__01102__FIREBIRD__ONGOING_TRANSACTION_HAS_BEEN_ROLLED_BACK,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*890*/
   (335545210L,
    plugin_name,
    "plugin_name",
    IBP_MCE_FB40__PLUGIN_NAME,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*891*/
   (335545211L,
    parameter_name,
    "parameter_name",
    IBP_MCE_FB40__PARAMETER_NAME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*892*/
   (335545212L,
    file_starting_page_err,
    "file_starting_page_err",
    IBP_MCE_FB40__FILE_STARTING_PAGE_ERR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*893*/
   (335545213L,
    invalid_timezone_offset,
    "invalid_timezone_offset",
    IBP_MCE_FB40__INVALID_TIMEZONE_OFFSET,
    IBP_SQLSTATE__22009__DATA_EXCEPTION_INVALID_TIME_ZONE_DISPLACEMENT_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*894*/
   (335545214L,
    invalid_timezone_region,
    "invalid_timezone_region",
    IBP_MCE_FB40__INVALID_TIMEZONE_REGION,
    IBP_SQLSTATE__22009__DATA_EXCEPTION_INVALID_TIME_ZONE_DISPLACEMENT_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*895*/
   (335545215L,
    invalid_timezone_id,
    "invalid_timezone_id",
    IBP_MCE_FB40__INVALID_TIMEZONE_ID,
    IBP_SQLSTATE__22009__DATA_EXCEPTION_INVALID_TIME_ZONE_DISPLACEMENT_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*896*/
   (335545216L,
    tom_decode64len,
    "tom_decode64len",
    IBP_MCE_FB40__TOM_DECODE64LEN,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*897*/
   (335545217L,
    tom_strblob,
    "tom_strblob",
    IBP_MCE_FB40__TOM_STRBLOB,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*898*/
   (335545218L,
    tom_reg,
    "tom_reg",
    IBP_MCE_FB40__TOM_REG,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*899*/
   (335545219L,
    tom_algorithm,
    "tom_algorithm",
    IBP_MCE_FB40__TOM_ALGORITHM,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*900*/
   (335545220L,
    tom_mode_miss,
    "tom_mode_miss",
    IBP_MCE_FB40__TOM_MODE_MISS,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*901*/
   (335545221L,
    tom_mode_bad,
    "tom_mode_bad",
    IBP_MCE_FB40__TOM_MODE_BAD,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*902*/
   (335545222L,
    tom_no_mode,
    "tom_no_mode",
    IBP_MCE_FB40__TOM_NO_MODE,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*903*/
   (335545223L,
    tom_iv_miss,
    "tom_iv_miss",
    IBP_MCE_FB40__TOM_IV_MISS,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*904*/
   (335545224L,
    tom_no_iv,
    "tom_no_iv",
    IBP_MCE_FB40__TOM_NO_IV,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*905*/
   (335545225L,
    tom_ctrtype_bad,
    "tom_ctrtype_bad",
    IBP_MCE_FB40__TOM_CTRTYPE_BAD,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*906*/
   (335545226L,
    tom_no_ctrtype,
    "tom_no_ctrtype",
    IBP_MCE_FB40__TOM_NO_CTRTYPE,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*907*/
   (335545227L,
    tom_ctr_big,
    "tom_ctr_big",
    IBP_MCE_FB40__TOM_CTR_BIG,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*908*/
   (335545228L,
    tom_no_ctr,
    "tom_no_ctr",
    IBP_MCE_FB40__TOM_NO_CTR,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*909*/
   (335545229L,
    tom_iv_length,
    "tom_iv_length",
    IBP_MCE_FB40__TOM_IV_LENGTH,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*910*/
   (335545230L,
    tom_error,
    "tom_error",
    IBP_MCE_FB40__TOM_ERROR,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*911*/
   (335545231L,
    tom_yarrow_start,
    "tom_yarrow_start",
    IBP_MCE_FB40__TOM_YARROW_START,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*912*/
   (335545232L,
    tom_yarrow_setup,
    "tom_yarrow_setup",
    IBP_MCE_FB40__TOM_YARROW_SETUP,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*913*/
   (335545233L,
    tom_init_mode,
    "tom_init_mode",
    IBP_MCE_FB40__TOM_INIT_MODE,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*914*/
   (335545234L,
    tom_crypt_mode,
    "tom_crypt_mode",
    IBP_MCE_FB40__TOM_CRYPT_MODE,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*915*/
   (335545235L,
    tom_decrypt_mode,
    "tom_decrypt_mode",
    IBP_MCE_FB40__TOM_DECRYPT_MODE,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*916*/
   (335545236L,
    tom_init_cip,
    "tom_init_cip",
    IBP_MCE_FB40__TOM_INIT_CIP,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*917*/
   (335545237L,
    tom_crypt_cip,
    "tom_crypt_cip",
    IBP_MCE_FB40__TOM_CRYPT_CIP,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*918*/
   (335545238L,
    tom_decrypt_cip,
    "tom_decrypt_cip",
    IBP_MCE_FB40__TOM_DECRYPT_CIP,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*919*/
   (335545239L,
    tom_setup_cip,
    "tom_setup_cip",
    IBP_MCE_FB40__TOM_SETUP_CIP,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*920*/
   (335545240L,
    tom_setup_chacha,
    "tom_setup_chacha",
    IBP_MCE_FB40__TOM_SETUP_CHACHA,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*921*/
   (335545241L,
    tom_encode,
    "tom_encode",
    IBP_MCE_FB40__TOM_ENCODE,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*922*/
   (335545242L,
    tom_decode,
    "tom_decode",
    IBP_MCE_FB40__TOM_DECODE,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*923*/
   (335545243L,
    tom_rsa_import,
    "tom_rsa_import",
    IBP_MCE_FB40__TOM_RSA_IMPORT,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*924*/
   (335545244L,
    tom_oaep,
    "tom_oaep",
    IBP_MCE_FB40__TOM_OAEP,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*925*/
   (335545245L,
    tom_hash_bad,
    "tom_hash_bad",
    IBP_MCE_FB40__TOM_HASH_BAD,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*926*/
   (335545246L,
    tom_rsa_make,
    "tom_rsa_make",
    IBP_MCE_FB40__TOM_RSA_MAKE,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*927*/
   (335545247L,
    tom_rsa_export,
    "tom_rsa_export",
    IBP_MCE_FB40__TOM_RSA_EXPORT,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*928*/
   (335545248L,
    tom_rsa_sign,
    "tom_rsa_sign",
    IBP_MCE_FB40__TOM_RSA_SIGN,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*929*/
   (335545249L,
    tom_rsa_verify,
    "tom_rsa_verify",
    IBP_MCE_FB40__TOM_RSA_VERIFY,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*930*/
   (335545250L,
    tom_chacha_key,
    "tom_chacha_key",
    IBP_MCE_FB40__TOM_CHACHA_KEY,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*931*/
   (335545251L,
    bad_repl_handle,
    "bad_repl_handle",
    IBP_MCE_FB40__BAD_REPL_HANDLE,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*932*/
   (335545252L,
    tra_snapshot_does_not_exist,
    "tra_snapshot_does_not_exist",
    IBP_MCE_FB40__TRA_SNAPSHOT_DOES_NOT_EXIST,
    IBP_SQLSTATE__0B000__INVALID_TRANSACTION_INITIATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*933*/
   (335545253L,
    eds_input_prm_not_used,
    "eds_input_prm_not_used",
    IBP_MCE_FB40__EDS_INPUT_PRM_NOT_USED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*934*/
   (335545254L,
    effective_user,
    "effective_user",
    IBP_MCE_FB40__EFFECTIVE_USER,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*935*/
   (335545255L,
    invalid_time_zone_bind,
    "invalid_time_zone_bind",
    IBP_MCE_FB40__INVALID_TIME_ZONE_BIND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*936*/
   (335545256L,
    invalid_decfloat_bind,
    "invalid_decfloat_bind",
    IBP_MCE_FB40__INVALID_DECFLOAT_BIND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*937*/
   (335545257L,
    odd_hex_len,
    "odd_hex_len",
    IBP_MCE_FB40__ODD_HEX_LEN,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*938*/
   (335545258L,
    invalid_hex_digit,
    "invalid_hex_digit",
    IBP_MCE_FB40__INVALID_HEX_DIGIT,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*939*/
   (335545259L,
    bind_err,
    "bind_err",
    IBP_MCE_FB40__BIND_ERR,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*940*/
   (335545260L,
    bind_statement,
    "bind_statement",
    IBP_MCE_FB40__BIND_STATEMENT,
    IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*941*/
   (335545261L,
    bind_convert,
    "bind_convert",
    IBP_MCE_FB40__BIND_CONVERT,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*942*/
   (335545262L,
    cannot_update_old_blob,
    "cannot_update_old_blob",
    IBP_MCE_FB40__CANNOT_UPDATE_OLD_BLOB,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*943*/
   (335545263L,
    cannot_read_new_blob,
    "cannot_read_new_blob",
    IBP_MCE_FB40__CANNOT_READ_NEW_BLOB,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*944*/
   (335545264L,
    dyn_no_create_priv,
    "dyn_no_create_priv",
    IBP_MCE_FB40__DYN_NO_CREATE_PRIV,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*945*/
   (335545265L,
    suspend_without_returns,
    "suspend_without_returns",
    IBP_MCE_FB40__SUSPEND_WITHOUT_RETURNS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*946*/
   (335545266L,
    truncate_warn,
    "truncate_warn",
    IBP_MCE_FB40__TRUNCATE_WARN,
    IBP_SQLSTATE__01004__WARNING_STRING_DATA_RIGHT_TRUNCATION_WARNING,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*947*/
   (335545267L,
    truncate_monitor,
    "truncate_monitor",
    IBP_MCE_FB40__TRUNCATE_MONITOR,
    IBP_SQLSTATE__01004__WARNING_STRING_DATA_RIGHT_TRUNCATION_WARNING,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*948*/
   (335545268L,
    truncate_context,
    "truncate_context",
    IBP_MCE_FB40__TRUNCATE_CONTEXT,
    IBP_SQLSTATE__01004__WARNING_STRING_DATA_RIGHT_TRUNCATION_WARNING,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*949*/
   (335545269L,
    merge_dup_update,
    "merge_dup_update",
    IBP_MCE_FB40__MERGE_DUP_UPDATE,
    IBP_SQLSTATE__21000__CARDINALITY_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*950*/
   (335545270L,
    wrong_page,
    "wrong_page",
    IBP_MCE_FB40__WRONG_PAGE,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*951*/
   (335545271L,
    repl_error,
    "repl_error",
    IBP_MCE_FB40__REPL_ERROR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*952*/
   (335545272L,
    ses_reset_failed,
    "ses_reset_failed",
    IBP_MCE_FB40__SES_RESET_FAILED,
    IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*953*/
   (335545273L,
    block_size,
    "block_size",
    IBP_MCE_FB40__BLOCK_SIZE,
    IBP_SQLSTATE__XX000__INTERNAL_ERROR,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*954*/
   (335545274L,
    tom_key_length,
    "tom_key_length",
    IBP_MCE_FB40__TOM_KEY_LENGTH,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*955*/
   (335545275L,
    inf_invalid_args,
    "inf_invalid_args",
    IBP_MCE_FB40__INF_INVALID_ARGS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*956*/
   (335545276L,
    sysf_invalid_null_empty,
    "sysf_invalid_null_empty",
    IBP_MCE_FB40__SYSF_INVALID_NULL_EMPTY,
    IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*957*/
   (336003074L,
    dsql_dbkey_from_non_table,
    "dsql_dbkey_from_non_table",
    IBP_MCE_FB40__DSQL_DBKEY_FROM_NON_TABLE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*958*/
   (336003075L,
    dsql_transitional_numeric,
    "dsql_transitional_numeric",
    IBP_MCE_FB40__DSQL_TRANSITIONAL_NUMERIC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*959*/
   (336003076L,
    dsql_dialect_warning_expr,
    "dsql_dialect_warning_expr",
    IBP_MCE_FB40__DSQL_DIALECT_WARNING_EXPR,
    IBP_SQLSTATE__01000__WARNING_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*960*/
   (336003077L,
    sql_db_dialect_dtype_unsupport,
    "sql_db_dialect_dtype_unsupport",
    IBP_MCE_FB40__SQL_DB_DIALECT_DTYPE_UNSUPPORT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    DB_E_NOTSUPPORTED)
 ADD_CODE__NONAME /*961*/
   (336003078L,
    IBP_MCE_FB40__INTERNAL_MSG_336003078,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*962*/
   (336003079L,
    sql_dialect_conflict_num,
    "sql_dialect_conflict_num",
    IBP_MCE_FB40__SQL_DIALECT_CONFLICT_NUM,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*963*/
   (336003080L,
    dsql_warning_number_ambiguous,
    "dsql_warning_number_ambiguous",
    IBP_MCE_FB40__DSQL_WARNING_NUMBER_AMBIGUOUS,
    IBP_SQLSTATE__HY104__ODBC__INVALID_PRECISION_OR_SCALE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*964*/
   (336003081L,
    dsql_warning_number_ambiguous1,
    "dsql_warning_number_ambiguous1",
    IBP_MCE_FB40__DSQL_WARNING_NUMBER_AMBIGUOUS1,
    IBP_SQLSTATE__HY104__ODBC__INVALID_PRECISION_OR_SCALE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*965*/
   (336003082L,
    dsql_warn_precision_ambiguous,
    "dsql_warn_precision_ambiguous",
    IBP_MCE_FB40__DSQL_WARN_PRECISION_AMBIGUOUS,
    IBP_SQLSTATE__HY104__ODBC__INVALID_PRECISION_OR_SCALE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*966*/
   (336003083L,
    dsql_warn_precision_ambiguous1,
    "dsql_warn_precision_ambiguous1",
    IBP_MCE_FB40__DSQL_WARN_PRECISION_AMBIGUOUS1,
    IBP_SQLSTATE__HY104__ODBC__INVALID_PRECISION_OR_SCALE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*967*/
   (336003084L,
    dsql_warn_precision_ambiguous2,
    "dsql_warn_precision_ambiguous2",
    IBP_MCE_FB40__DSQL_WARN_PRECISION_AMBIGUOUS2,
    IBP_SQLSTATE__HY104__ODBC__INVALID_PRECISION_OR_SCALE_VALUE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*968*/
   (336003085L,
    dsql_ambiguous_field_name,
    "dsql_ambiguous_field_name",
    IBP_MCE_FB40__DSQL_AMBIGUOUS_FIELD_NAME,
    IBP_SQLSTATE__42702__AMBIGUOUS_COLUMN,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*969*/
   (336003086L,
    dsql_udf_return_pos_err,
    "dsql_udf_return_pos_err",
    IBP_MCE_FB40__DSQL_UDF_RETURN_POS_ERR,
    IBP_SQLSTATE__38000__EXTERNAL_ROUTINE_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*970*/
   (336003087L,
    dsql_invalid_label,
    "dsql_invalid_label",
    IBP_MCE_FB40__DSQL_INVALID_LABEL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*971*/
   (336003088L,
    dsql_datatypes_not_comparable,
    "dsql_datatypes_not_comparable",
    IBP_MCE_FB40__DSQL_DATATYPES_NOT_COMPARABLE,
    IBP_SQLSTATE__HY004__ODBC__INVALID_SQL_DATA_TYPE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*972*/
   (336003089L,
    dsql_cursor_invalid,
    "dsql_cursor_invalid",
    IBP_MCE_FB40__DSQL_CURSOR_INVALID,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*973*/
   (336003090L,
    dsql_cursor_redefined,
    "dsql_cursor_redefined",
    IBP_MCE_FB40__DSQL_CURSOR_REDEFINED,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*974*/
   (336003091L,
    dsql_cursor_not_found,
    "dsql_cursor_not_found",
    IBP_MCE_FB40__DSQL_CURSOR_NOT_FOUND,
    IBP_SQLSTATE__34000__INVALID_CURSOR_NAME_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*975*/
   (336003092L,
    dsql_cursor_exists,
    "dsql_cursor_exists",
    IBP_MCE_FB40__DSQL_CURSOR_EXISTS,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*976*/
   (336003093L,
    dsql_cursor_rel_ambiguous,
    "dsql_cursor_rel_ambiguous",
    IBP_MCE_FB40__DSQL_CURSOR_REL_AMBIGUOUS,
    IBP_SQLSTATE__34000__INVALID_CURSOR_NAME_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*977*/
   (336003094L,
    dsql_cursor_rel_not_found,
    "dsql_cursor_rel_not_found",
    IBP_MCE_FB40__DSQL_CURSOR_REL_NOT_FOUND,
    IBP_SQLSTATE__34000__INVALID_CURSOR_NAME_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*978*/
   (336003095L,
    dsql_cursor_not_open,
    "dsql_cursor_not_open",
    IBP_MCE_FB40__DSQL_CURSOR_NOT_OPEN,
    IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*979*/
   (336003096L,
    dsql_type_not_supp_ext_tab,
    "dsql_type_not_supp_ext_tab",
    IBP_MCE_FB40__DSQL_TYPE_NOT_SUPP_EXT_TAB,
    IBP_SQLSTATE__HY004__ODBC__INVALID_SQL_DATA_TYPE,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*980*/
   (336003097L,
    dsql_feature_not_supported_ods,
    "dsql_feature_not_supported_ods",
    IBP_MCE_FB40__DSQL_FEATURE_NOT_SUPPORTED_ODS,
    IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*981*/
   (336003098L,
    primary_key_required,
    "primary_key_required",
    IBP_MCE_FB40__PRIMARY_KEY_REQUIRED,
    IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*982*/
   (336003099L,
    upd_ins_doesnt_match_pk,
    "upd_ins_doesnt_match_pk",
    IBP_MCE_FB40__UPD_INS_DOESNT_MATCH_PK,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*983*/
   (336003100L,
    upd_ins_doesnt_match_matching,
    "upd_ins_doesnt_match_matching",
    IBP_MCE_FB40__UPD_INS_DOESNT_MATCH_MATCHING,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*984*/
   (336003101L,
    upd_ins_with_complex_view,
    "upd_ins_with_complex_view",
    IBP_MCE_FB40__UPD_INS_WITH_COMPLEX_VIEW,
    IBP_SQLSTATE__54001__STATEMENT_TOO_COMPLEX,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*985*/
   (336003102L,
    dsql_incompatible_trigger_type,
    "dsql_incompatible_trigger_type",
    IBP_MCE_FB40__DSQL_INCOMPATIBLE_TRIGGER_TYPE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*986*/
   (336003103L,
    dsql_db_trigger_type_cant_change,
    "dsql_db_trigger_type_cant_change",
    IBP_MCE_FB40__DSQL_DB_TRIGGER_TYPE_CANT_CHANGE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*987*/
   (336003104L,
    dsql_record_version_table,
    "dsql_record_version_table",
    IBP_MCE_FB40__DSQL_RECORD_VERSION_TABLE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*988*/
   (336003105L,
    dsql_invalid_sqlda_version,
    "dsql_invalid_sqlda_version",
    IBP_MCE_FB40__DSQL_INVALID_SQLDA_VERSION,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*989*/
   (336003106L,
    dsql_sqlvar_index,
    "dsql_sqlvar_index",
    IBP_MCE_FB40__DSQL_SQLVAR_INDEX,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*990*/
   (336003107L,
    dsql_no_sqlind,
    "dsql_no_sqlind",
    IBP_MCE_FB40__DSQL_NO_SQLIND,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*991*/
   (336003108L,
    dsql_no_sqldata,
    "dsql_no_sqldata",
    IBP_MCE_FB40__DSQL_NO_SQLDATA,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*992*/
   (336003109L,
    dsql_no_input_sqlda,
    "dsql_no_input_sqlda",
    IBP_MCE_FB40__DSQL_NO_INPUT_SQLDA,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*993*/
   (336003110L,
    dsql_no_output_sqlda,
    "dsql_no_output_sqlda",
    IBP_MCE_FB40__DSQL_NO_OUTPUT_SQLDA,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*994*/
   (336003111L,
    dsql_wrong_param_num,
    "dsql_wrong_param_num",
    IBP_MCE_FB40__DSQL_WRONG_PARAM_NUM,
    IBP_SQLSTATE__07001__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_DYNAMIC_PARAMETER_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*995*/
   (336003112L,
    dsql_invalid_drop_ss_clause,
    "dsql_invalid_drop_ss_clause",
    IBP_MCE_FB40__DSQL_INVALID_DROP_SS_CLAUSE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*996*/
   (336003113L,
    upd_ins_cannot_default,
    "upd_ins_cannot_default",
    IBP_MCE_FB40__UPD_INS_CANNOT_DEFAULT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*997*/
   (336068609L,
    IBP_MCE_FB40__INTERNAL_MSG_336068609,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*998*/
   (336068610L,
    IBP_MCE_FB40__INTERNAL_MSG_336068610,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*999*/
   (336068611L,
    IBP_MCE_FB40__INTERNAL_MSG_336068611,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1000*/
   (336068612L,
    IBP_MCE_FB40__INTERNAL_MSG_336068612,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1001*/
   (336068613L,
    IBP_MCE_FB40__INTERNAL_MSG_336068613,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1002*/
   (336068614L,
    IBP_MCE_FB40__INTERNAL_MSG_336068614,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1003*/
   (336068615L,
    IBP_MCE_FB40__INTERNAL_MSG_336068615,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1004*/
   (336068616L,
    IBP_MCE_FB40__INTERNAL_MSG_336068616,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1005*/
   (336068617L,
    IBP_MCE_FB40__INTERNAL_MSG_336068617,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1006*/
   (336068618L,
    IBP_MCE_FB40__INTERNAL_MSG_336068618,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1007*/
   (336068619L,
    IBP_MCE_FB40__INTERNAL_MSG_336068619,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1008*/
   (336068620L,
    IBP_MCE_FB40__INTERNAL_MSG_336068620,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1009*/
   (336068621L,
    IBP_MCE_FB40__INTERNAL_MSG_336068621,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1010*/
   (336068622L,
    IBP_MCE_FB40__INTERNAL_MSG_336068622,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1011*/
   (336068623L,
    IBP_MCE_FB40__INTERNAL_MSG_336068623,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1012*/
   (336068624L,
    IBP_MCE_FB40__INTERNAL_MSG_336068624,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1013*/
   (336068625L,
    IBP_MCE_FB40__INTERNAL_MSG_336068625,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1014*/
   (336068626L,
    IBP_MCE_FB40__INTERNAL_MSG_336068626,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1015*/
   (336068627L,
    IBP_MCE_FB40__INTERNAL_MSG_336068627,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1016*/
   (336068628L,
    IBP_MCE_FB40__INTERNAL_MSG_336068628,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1017*/
   (336068629L,
    IBP_MCE_FB40__INTERNAL_MSG_336068629,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1018*/
   (336068630L,
    IBP_MCE_FB40__INTERNAL_MSG_336068630,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1019*/
   (336068631L,
    IBP_MCE_FB40__INTERNAL_MSG_336068631,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1020*/
   (336068632L,
    IBP_MCE_FB40__INTERNAL_MSG_336068632,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1021*/
   (336068633L,
    IBP_MCE_FB40__INTERNAL_MSG_336068633,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1022*/
   (336068634L,
    IBP_MCE_FB40__INTERNAL_MSG_336068634,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1023*/
   (336068635L,
    IBP_MCE_FB40__INTERNAL_MSG_336068635,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1024*/
   (336068636L,
    IBP_MCE_FB40__INTERNAL_MSG_336068636,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1025*/
   (336068637L,
    IBP_MCE_FB40__INTERNAL_MSG_336068637,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1026*/
   (336068638L,
    IBP_MCE_FB40__INTERNAL_MSG_336068638,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1027*/
   (336068639L,
    IBP_MCE_FB40__INTERNAL_MSG_336068639,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1028*/
   (336068640L,
    IBP_MCE_FB40__INTERNAL_MSG_336068640,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1029*/
   (336068641L,
    IBP_MCE_FB40__INTERNAL_MSG_336068641,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1030*/
   (336068642L,
    IBP_MCE_FB40__INTERNAL_MSG_336068642,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1031*/
   (336068643L,
    IBP_MCE_FB40__INTERNAL_MSG_336068643,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1032*/
   (336068644L,
    IBP_MCE_FB40__INTERNAL_MSG_336068644,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1033*/
   (336068645L,
    dyn_filter_not_found,
    "dyn_filter_not_found",
    IBP_MCE_FB40__DYN_FILTER_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1034*/
   (336068646L,
    IBP_MCE_FB40__INTERNAL_MSG_336068646,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1035*/
   (336068647L,
    IBP_MCE_FB40__INTERNAL_MSG_336068647,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1036*/
   (336068648L,
    IBP_MCE_FB40__INTERNAL_MSG_336068648,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1037*/
   (336068649L,
    dyn_func_not_found,
    "dyn_func_not_found",
    IBP_MCE_FB40__DYN_FUNC_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1038*/
   (336068650L,
    IBP_MCE_FB40__INTERNAL_MSG_336068650,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1039*/
   (336068651L,
    IBP_MCE_FB40__INTERNAL_MSG_336068651,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1040*/
   (336068652L,
    IBP_MCE_FB40__INTERNAL_MSG_336068652,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1041*/
   (336068653L,
    IBP_MCE_FB40__INTERNAL_MSG_336068653,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1042*/
   (336068654L,
    IBP_MCE_FB40__INTERNAL_MSG_336068654,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1043*/
   (336068655L,
    IBP_MCE_FB40__INTERNAL_MSG_336068655,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1044*/
   (336068656L,
    dyn_index_not_found,
    "dyn_index_not_found",
    IBP_MCE_FB40__DYN_INDEX_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1045*/
   (336068657L,
    IBP_MCE_FB40__INTERNAL_MSG_336068657,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1046*/
   (336068658L,
    IBP_MCE_FB40__INTERNAL_MSG_336068658,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1047*/
   (336068659L,
    IBP_MCE_FB40__INTERNAL_MSG_336068659,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1048*/
   (336068660L,
    IBP_MCE_FB40__INTERNAL_MSG_336068660,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1049*/
   (336068661L,
    IBP_MCE_FB40__INTERNAL_MSG_336068661,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1050*/
   (336068662L,
    dyn_view_not_found,
    "dyn_view_not_found",
    IBP_MCE_FB40__DYN_VIEW_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1051*/
   (336068663L,
    IBP_MCE_FB40__INTERNAL_MSG_336068663,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1052*/
   (336068664L,
    IBP_MCE_FB40__INTERNAL_MSG_336068664,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1053*/
   (336068665L,
    IBP_MCE_FB40__INTERNAL_MSG_336068665,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1054*/
   (336068666L,
    IBP_MCE_FB40__INTERNAL_MSG_336068666,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1055*/
   (336068667L,
    IBP_MCE_FB40__INTERNAL_MSG_336068667,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1056*/
   (336068668L,
    IBP_MCE_FB40__INTERNAL_MSG_336068668,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1057*/
   (336068669L,
    IBP_MCE_FB40__INTERNAL_MSG_336068669,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1058*/
   (336068670L,
    IBP_MCE_FB40__INTERNAL_MSG_336068670,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1059*/
   (336068671L,
    IBP_MCE_FB40__INTERNAL_MSG_336068671,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1060*/
   (336068672L,
    IBP_MCE_FB40__INTERNAL_MSG_336068672,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1061*/
   (336068673L,
    IBP_MCE_FB40__INTERNAL_MSG_336068673,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1062*/
   (336068674L,
    IBP_MCE_FB40__INTERNAL_MSG_336068674,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1063*/
   (336068675L,
    IBP_MCE_FB40__INTERNAL_MSG_336068675,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1064*/
   (336068676L,
    IBP_MCE_FB40__INTERNAL_MSG_336068676,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1065*/
   (336068677L,
    IBP_MCE_FB40__INTERNAL_MSG_336068677,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1066*/
   (336068678L,
    IBP_MCE_FB40__INTERNAL_MSG_336068678,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1067*/
   (336068679L,
    IBP_MCE_FB40__INTERNAL_MSG_336068679,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1068*/
   (336068680L,
    IBP_MCE_FB40__INTERNAL_MSG_336068680,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1069*/
   (336068681L,
    IBP_MCE_FB40__INTERNAL_MSG_336068681,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1070*/
   (336068682L,
    IBP_MCE_FB40__INTERNAL_MSG_336068682,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1071*/
   (336068683L,
    IBP_MCE_FB40__INTERNAL_MSG_336068683,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1072*/
   (336068684L,
    IBP_MCE_FB40__INTERNAL_MSG_336068684,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1073*/
   (336068685L,
    IBP_MCE_FB40__INTERNAL_MSG_336068685,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1074*/
   (336068686L,
    IBP_MCE_FB40__INTERNAL_MSG_336068686,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1075*/
   (336068687L,
    IBP_MCE_FB40__INTERNAL_MSG_336068687,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1076*/
   (336068688L,
    IBP_MCE_FB40__INTERNAL_MSG_336068688,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1077*/
   (336068689L,
    IBP_MCE_FB40__INTERNAL_MSG_336068689,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1078*/
   (336068690L,
    IBP_MCE_FB40__INTERNAL_MSG_336068690,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1079*/
   (336068691L,
    IBP_MCE_FB40__INTERNAL_MSG_336068691,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1080*/
   (336068692L,
    IBP_MCE_FB40__INTERNAL_MSG_336068692,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1081*/
   (336068693L,
    IBP_MCE_FB40__INTERNAL_MSG_336068693,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1082*/
   (336068694L,
    IBP_MCE_FB40__INTERNAL_MSG_336068694,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1083*/
   (336068695L,
    IBP_MCE_FB40__INTERNAL_MSG_336068695,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1084*/
   (336068696L,
    IBP_MCE_FB40__INTERNAL_MSG_336068696,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1085*/
   (336068697L,
    dyn_domain_not_found,
    "dyn_domain_not_found",
    IBP_MCE_FB40__DYN_DOMAIN_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1086*/
   (336068698L,
    IBP_MCE_FB40__INTERNAL_MSG_336068698,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1087*/
   (336068699L,
    IBP_MCE_FB40__INTERNAL_MSG_336068699,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1088*/
   (336068700L,
    IBP_MCE_FB40__INTERNAL_MSG_336068700,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1089*/
   (336068701L,
    IBP_MCE_FB40__INTERNAL_MSG_336068701,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1090*/
   (336068702L,
    IBP_MCE_FB40__INTERNAL_MSG_336068702,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1091*/
   (336068703L,
    IBP_MCE_FB40__INTERNAL_MSG_336068703,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1092*/
   (336068704L,
    IBP_MCE_FB40__INTERNAL_MSG_336068704,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1093*/
   (336068705L,
    IBP_MCE_FB40__INTERNAL_MSG_336068705,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1094*/
   (336068706L,
    IBP_MCE_FB40__INTERNAL_MSG_336068706,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1095*/
   (336068707L,
    IBP_MCE_FB40__INTERNAL_MSG_336068707,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1096*/
   (336068708L,
    IBP_MCE_FB40__INTERNAL_MSG_336068708,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1097*/
   (336068709L,
    IBP_MCE_FB40__INTERNAL_MSG_336068709,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1098*/
   (336068710L,
    IBP_MCE_FB40__INTERNAL_MSG_336068710,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1099*/
   (336068711L,
    IBP_MCE_FB40__INTERNAL_MSG_336068711,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1100*/
   (336068712L,
    IBP_MCE_FB40__INTERNAL_MSG_336068712,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1101*/
   (336068713L,
    IBP_MCE_FB40__INTERNAL_MSG_336068713,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1102*/
   (336068714L,
    IBP_MCE_FB40__INTERNAL_MSG_336068714,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1103*/
   (336068715L,
    IBP_MCE_FB40__INTERNAL_MSG_336068715,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1104*/
   (336068716L,
    IBP_MCE_FB40__INTERNAL_MSG_336068716,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1105*/
   (336068717L,
    dyn_cant_modify_auto_trig,
    "dyn_cant_modify_auto_trig",
    IBP_MCE_FB40__DYN_CANT_MODIFY_AUTO_TRIG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1106*/
   (336068718L,
    IBP_MCE_FB40__INTERNAL_MSG_336068718,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1107*/
   (336068719L,
    IBP_MCE_FB40__INTERNAL_MSG_336068719,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1108*/
   (336068720L,
    IBP_MCE_FB40__INTERNAL_MSG_336068720,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1109*/
   (336068721L,
    IBP_MCE_FB40__INTERNAL_MSG_336068721,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1110*/
   (336068722L,
    IBP_MCE_FB40__INTERNAL_MSG_336068722,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1111*/
   (336068723L,
    IBP_MCE_FB40__INTERNAL_MSG_336068723,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1112*/
   (336068724L,
    IBP_MCE_FB40__INTERNAL_MSG_336068724,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1113*/
   (336068725L,
    IBP_MCE_FB40__INTERNAL_MSG_336068725,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1114*/
   (336068726L,
    IBP_MCE_FB40__INTERNAL_MSG_336068726,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1115*/
   (336068727L,
    IBP_MCE_FB40__INTERNAL_MSG_336068727,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1116*/
   (336068728L,
    IBP_MCE_FB40__INTERNAL_MSG_336068728,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1117*/
   (336068729L,
    IBP_MCE_FB40__INTERNAL_MSG_336068729,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1118*/
   (336068730L,
    IBP_MCE_FB40__INTERNAL_MSG_336068730,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1119*/
   (336068731L,
    IBP_MCE_FB40__INTERNAL_MSG_336068731,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1120*/
   (336068732L,
    IBP_MCE_FB40__INTERNAL_MSG_336068732,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1121*/
   (336068733L,
    IBP_MCE_FB40__INTERNAL_MSG_336068733,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1122*/
   (336068734L,
    IBP_MCE_FB40__INTERNAL_MSG_336068734,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1123*/
   (336068735L,
    IBP_MCE_FB40__INTERNAL_MSG_336068735,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1124*/
   (336068736L,
    IBP_MCE_FB40__INTERNAL_MSG_336068736,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1125*/
   (336068737L,
    IBP_MCE_FB40__INTERNAL_MSG_336068737,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1126*/
   (336068738L,
    IBP_MCE_FB40__INTERNAL_MSG_336068738,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1127*/
   (336068739L,
    IBP_MCE_FB40__INTERNAL_MSG_336068739,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1128*/
   (336068740L,
    dyn_dup_table,
    "dyn_dup_table",
    IBP_MCE_FB40__DYN_DUP_TABLE,
    IBP_SQLSTATE__42S01__ODBC__BASE_TABLE_OR_VIEW_ALREADY_EXISTS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1129*/
   (336068741L,
    IBP_MCE_FB40__INTERNAL_MSG_336068741,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1130*/
   (336068742L,
    IBP_MCE_FB40__INTERNAL_MSG_336068742,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1131*/
   (336068743L,
    dyn_dup_procedure,
    "dyn_dup_procedure",
    IBP_MCE_FB40__DYN_DUP_PROCEDURE,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1132*/
   (336068744L,
    IBP_MCE_FB40__INTERNAL_MSG_336068744,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1133*/
   (336068745L,
    IBP_MCE_FB40__INTERNAL_MSG_336068745,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1134*/
   (336068746L,
    IBP_MCE_FB40__INTERNAL_MSG_336068746,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1135*/
   (336068747L,
    IBP_MCE_FB40__INTERNAL_MSG_336068747,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1136*/
   (336068748L,
    dyn_proc_not_found,
    "dyn_proc_not_found",
    IBP_MCE_FB40__DYN_PROC_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1137*/
   (336068749L,
    IBP_MCE_FB40__INTERNAL_MSG_336068749,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1138*/
   (336068750L,
    IBP_MCE_FB40__INTERNAL_MSG_336068750,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1139*/
   (336068751L,
    IBP_MCE_FB40__INTERNAL_MSG_336068751,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1140*/
   (336068752L,
    dyn_exception_not_found,
    "dyn_exception_not_found",
    IBP_MCE_FB40__DYN_EXCEPTION_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1141*/
   (336068753L,
    IBP_MCE_FB40__INTERNAL_MSG_336068753,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1142*/
   (336068754L,
    dyn_proc_param_not_found,
    "dyn_proc_param_not_found",
    IBP_MCE_FB40__DYN_PROC_PARAM_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1143*/
   (336068755L,
    dyn_trig_not_found,
    "dyn_trig_not_found",
    IBP_MCE_FB40__DYN_TRIG_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1144*/
   (336068756L,
    IBP_MCE_FB40__INTERNAL_MSG_336068756,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1145*/
   (336068757L,
    IBP_MCE_FB40__INTERNAL_MSG_336068757,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1146*/
   (336068758L,
    IBP_MCE_FB40__INTERNAL_MSG_336068758,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1147*/
   (336068759L,
    dyn_charset_not_found,
    "dyn_charset_not_found",
    IBP_MCE_FB40__DYN_CHARSET_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1148*/
   (336068760L,
    dyn_collation_not_found,
    "dyn_collation_not_found",
    IBP_MCE_FB40__DYN_COLLATION_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1149*/
   (336068761L,
    IBP_MCE_FB40__INTERNAL_MSG_336068761,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1150*/
   (336068762L,
    IBP_MCE_FB40__INTERNAL_MSG_336068762,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1151*/
   (336068763L,
    dyn_role_not_found,
    "dyn_role_not_found",
    IBP_MCE_FB40__DYN_ROLE_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1152*/
   (336068764L,
    IBP_MCE_FB40__INTERNAL_MSG_336068764,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1153*/
   (336068765L,
    IBP_MCE_FB40__INTERNAL_MSG_336068765,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1154*/
   (336068766L,
    IBP_MCE_FB40__INTERNAL_MSG_336068766,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1155*/
   (336068767L,
    dyn_name_longer,
    "dyn_name_longer",
    IBP_MCE_FB40__DYN_NAME_LONGER,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1156*/
   (336068768L,
    IBP_MCE_FB40__INTERNAL_MSG_336068768,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1157*/
   (336068770L,
    IBP_MCE_FB40__INTERNAL_MSG_336068770,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1158*/
   (336068771L,
    IBP_MCE_FB40__INTERNAL_MSG_336068771,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1159*/
   (336068772L,
    IBP_MCE_FB40__INTERNAL_MSG_336068772,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1160*/
   (336068773L,
    IBP_MCE_FB40__INTERNAL_MSG_336068773,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1161*/
   (336068774L,
    IBP_MCE_FB40__INTERNAL_MSG_336068774,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1162*/
   (336068775L,
    IBP_MCE_FB40__INTERNAL_MSG_336068775,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1163*/
   (336068776L,
    IBP_MCE_FB40__INTERNAL_MSG_336068776,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1164*/
   (336068777L,
    IBP_MCE_FB40__INTERNAL_MSG_336068777,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1165*/
   (336068778L,
    IBP_MCE_FB40__INTERNAL_MSG_336068778,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1166*/
   (336068779L,
    IBP_MCE_FB40__INTERNAL_MSG_336068779,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1167*/
   (336068780L,
    IBP_MCE_FB40__INTERNAL_MSG_336068780,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1168*/
   (336068781L,
    IBP_MCE_FB40__INTERNAL_MSG_336068781,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1169*/
   (336068782L,
    IBP_MCE_FB40__INTERNAL_MSG_336068782,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1170*/
   (336068783L,
    IBP_MCE_FB40__INTERNAL_MSG_336068783,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1171*/
   (336068784L,
    dyn_column_does_not_exist,
    "dyn_column_does_not_exist",
    IBP_MCE_FB40__DYN_COLUMN_DOES_NOT_EXIST,
    IBP_SQLSTATE__42S22__ODBC__COLUMN_NOT_FOUND,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1172*/
   (336068785L,
    IBP_MCE_FB40__INTERNAL_MSG_336068785,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1173*/
   (336068786L,
    IBP_MCE_FB40__INTERNAL_MSG_336068786,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1174*/
   (336068787L,
    IBP_MCE_FB40__INTERNAL_MSG_336068787,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1175*/
   (336068788L,
    IBP_MCE_FB40__INTERNAL_MSG_336068788,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1176*/
   (336068789L,
    IBP_MCE_FB40__INTERNAL_MSG_336068789,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1177*/
   (336068790L,
    IBP_MCE_FB40__INTERNAL_MSG_336068790,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1178*/
   (336068791L,
    IBP_MCE_FB40__INTERNAL_MSG_336068791,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1179*/
   (336068792L,
    IBP_MCE_FB40__INTERNAL_MSG_336068792,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1180*/
   (336068793L,
    IBP_MCE_FB40__INTERNAL_MSG_336068793,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1181*/
   (336068794L,
    IBP_MCE_FB40__INTERNAL_MSG_336068794,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1182*/
   (336068795L,
    IBP_MCE_FB40__INTERNAL_MSG_336068795,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1183*/
   (336068796L,
    dyn_role_does_not_exist,
    "dyn_role_does_not_exist",
    IBP_MCE_FB40__DYN_ROLE_DOES_NOT_EXIST,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1184*/
   (336068797L,
    dyn_no_grant_admin_opt,
    "dyn_no_grant_admin_opt",
    IBP_MCE_FB40__DYN_NO_GRANT_ADMIN_OPT,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1185*/
   (336068798L,
    dyn_user_not_role_member,
    "dyn_user_not_role_member",
    IBP_MCE_FB40__DYN_USER_NOT_ROLE_MEMBER,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1186*/
   (336068799L,
    dyn_delete_role_failed,
    "dyn_delete_role_failed",
    IBP_MCE_FB40__DYN_DELETE_ROLE_FAILED,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1187*/
   (336068800L,
    dyn_grant_role_to_user,
    "dyn_grant_role_to_user",
    IBP_MCE_FB40__DYN_GRANT_ROLE_TO_USER,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1188*/
   (336068801L,
    dyn_inv_sql_role_name,
    "dyn_inv_sql_role_name",
    IBP_MCE_FB40__DYN_INV_SQL_ROLE_NAME,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1189*/
   (336068802L,
    dyn_dup_sql_role,
    "dyn_dup_sql_role",
    IBP_MCE_FB40__DYN_DUP_SQL_ROLE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1190*/
   (336068803L,
    dyn_kywd_spec_for_role,
    "dyn_kywd_spec_for_role",
    IBP_MCE_FB40__DYN_KYWD_SPEC_FOR_ROLE,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1191*/
   (336068804L,
    dyn_roles_not_supported,
    "dyn_roles_not_supported",
    IBP_MCE_FB40__DYN_ROLES_NOT_SUPPORTED,
    IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1192*/
   (336068812L,
    dyn_domain_name_exists,
    "dyn_domain_name_exists",
    IBP_MCE_FB40__DYN_DOMAIN_NAME_EXISTS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1193*/
   (336068813L,
    dyn_field_name_exists,
    "dyn_field_name_exists",
    IBP_MCE_FB40__DYN_FIELD_NAME_EXISTS,
    IBP_SQLSTATE__42S21__ODBC__COLUMN_ALREADY_EXISTS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1194*/
   (336068814L,
    dyn_dependency_exists,
    "dyn_dependency_exists",
    IBP_MCE_FB40__DYN_DEPENDENCY_EXISTS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1195*/
   (336068815L,
    dyn_dtype_invalid,
    "dyn_dtype_invalid",
    IBP_MCE_FB40__DYN_DTYPE_INVALID,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1196*/
   (336068816L,
    dyn_char_fld_too_small,
    "dyn_char_fld_too_small",
    IBP_MCE_FB40__DYN_CHAR_FLD_TOO_SMALL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1197*/
   (336068817L,
    dyn_invalid_dtype_conversion,
    "dyn_invalid_dtype_conversion",
    IBP_MCE_FB40__DYN_INVALID_DTYPE_CONVERSION,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1198*/
   (336068818L,
    dyn_dtype_conv_invalid,
    "dyn_dtype_conv_invalid",
    IBP_MCE_FB40__DYN_DTYPE_CONV_INVALID,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1199*/
   (336068819L,
    dyn_virmemexh,
    "dyn_virmemexh",
    IBP_MCE_FB40__DYN_VIRMEMEXH,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1200*/
   (336068820L,
    dyn_zero_len_id,
    "dyn_zero_len_id",
    IBP_MCE_FB40__DYN_ZERO_LEN_ID,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1201*/
   (336068821L,
    del_gen_fail,
    "del_gen_fail",
    IBP_MCE_FB40__DEL_GEN_FAIL,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1202*/
   (336068822L,
    dyn_gen_not_found,
    "dyn_gen_not_found",
    IBP_MCE_FB40__DYN_GEN_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1203*/
   (336068823L,
    IBP_MCE_FB40__INTERNAL_MSG_336068823,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1204*/
   (336068824L,
    IBP_MCE_FB40__INTERNAL_MSG_336068824,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1205*/
   (336068825L,
    IBP_MCE_FB40__INTERNAL_MSG_336068825,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1206*/
   (336068826L,
    IBP_MCE_FB40__INTERNAL_MSG_336068826,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1207*/
   (336068827L,
    IBP_MCE_FB40__INTERNAL_MSG_336068827,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1208*/
   (336068828L,
    IBP_MCE_FB40__INTERNAL_MSG_336068828,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1209*/
   (336068829L,
    max_coll_per_charset,
    "max_coll_per_charset",
    IBP_MCE_FB40__MAX_COLL_PER_CHARSET,
    IBP_SQLSTATE__2C000__INVALID_CHARACTER_SET_NAME_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1210*/
   (336068830L,
    invalid_coll_attr,
    "invalid_coll_attr",
    IBP_MCE_FB40__INVALID_COLL_ATTR,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1211*/
   (336068831L,
    IBP_MCE_FB40__INTERNAL_MSG_336068831,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1212*/
   (336068832L,
    IBP_MCE_FB40__INTERNAL_MSG_336068832,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1213*/
   (336068833L,
    IBP_MCE_FB40__INTERNAL_MSG_336068833,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1214*/
   (336068834L,
    IBP_MCE_FB40__INTERNAL_MSG_336068834,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1215*/
   (336068835L,
    IBP_MCE_FB40__INTERNAL_MSG_336068835,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1216*/
   (336068836L,
    IBP_MCE_FB40__INTERNAL_MSG_336068836,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1217*/
   (336068837L,
    IBP_MCE_FB40__INTERNAL_MSG_336068837,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1218*/
   (336068838L,
    IBP_MCE_FB40__INTERNAL_MSG_336068838,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1219*/
   (336068839L,
    IBP_MCE_FB40__INTERNAL_MSG_336068839,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1220*/
   (336068840L,
    dyn_wrong_gtt_scope,
    "dyn_wrong_gtt_scope",
    IBP_MCE_FB40__DYN_WRONG_GTT_SCOPE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1221*/
   (336068841L,
    IBP_MCE_FB40__INTERNAL_MSG_336068841,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1222*/
   (336068842L,
    del_coll_fail,
    "del_coll_fail",
    IBP_MCE_FB40__DEL_COLL_FAIL,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1223*/
   (336068843L,
    dyn_coll_used_table,
    "dyn_coll_used_table",
    IBP_MCE_FB40__DYN_COLL_USED_TABLE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1224*/
   (336068844L,
    dyn_coll_used_domain,
    "dyn_coll_used_domain",
    IBP_MCE_FB40__DYN_COLL_USED_DOMAIN,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1225*/
   (336068845L,
    dyn_cannot_del_syscoll,
    "dyn_cannot_del_syscoll",
    IBP_MCE_FB40__DYN_CANNOT_DEL_SYSCOLL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1226*/
   (336068846L,
    dyn_cannot_del_def_coll,
    "dyn_cannot_del_def_coll",
    IBP_MCE_FB40__DYN_CANNOT_DEL_DEF_COLL,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1227*/
   (336068847L,
    IBP_MCE_FB40__INTERNAL_MSG_336068847,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1228*/
   (336068848L,
    IBP_MCE_FB40__INTERNAL_MSG_336068848,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1229*/
   (336068849L,
    dyn_table_not_found,
    "dyn_table_not_found",
    IBP_MCE_FB40__DYN_TABLE_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1230*/
   (336068850L,
    IBP_MCE_FB40__INTERNAL_MSG_336068850,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1231*/
   (336068851L,
    dyn_coll_used_procedure,
    "dyn_coll_used_procedure",
    IBP_MCE_FB40__DYN_COLL_USED_PROCEDURE,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1232*/
   (336068852L,
    dyn_scale_too_big,
    "dyn_scale_too_big",
    IBP_MCE_FB40__DYN_SCALE_TOO_BIG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1233*/
   (336068853L,
    dyn_precision_too_small,
    "dyn_precision_too_small",
    IBP_MCE_FB40__DYN_PRECISION_TOO_SMALL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1234*/
   (336068854L,
    IBP_MCE_FB40__INTERNAL_MSG_336068854,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1235*/
   (336068855L,
    dyn_miss_priv_warning,
    "dyn_miss_priv_warning",
    IBP_MCE_FB40__DYN_MISS_PRIV_WARNING,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1236*/
   (336068856L,
    dyn_ods_not_supp_feature,
    "dyn_ods_not_supp_feature",
    IBP_MCE_FB40__DYN_ODS_NOT_SUPP_FEATURE,
    IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1237*/
   (336068857L,
    dyn_cannot_addrem_computed,
    "dyn_cannot_addrem_computed",
    IBP_MCE_FB40__DYN_CANNOT_ADDREM_COMPUTED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1238*/
   (336068858L,
    dyn_no_empty_pw,
    "dyn_no_empty_pw",
    IBP_MCE_FB40__DYN_NO_EMPTY_PW,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1239*/
   (336068859L,
    dyn_dup_index,
    "dyn_dup_index",
    IBP_MCE_FB40__DYN_DUP_INDEX,
    IBP_SQLSTATE__42S11__ODBC__INDEX_ALREADY_EXISTS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1240*/
   (336068860L,
    dyn_locksmith_use_granted,
    "dyn_locksmith_use_granted",
    IBP_MCE_FB40__DYN_LOCKSMITH_USE_GRANTED,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1241*/
   (336068861L,
    dyn_dup_exception,
    "dyn_dup_exception",
    IBP_MCE_FB40__DYN_DUP_EXCEPTION,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1242*/
   (336068862L,
    dyn_dup_generator,
    "dyn_dup_generator",
    IBP_MCE_FB40__DYN_DUP_GENERATOR,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1243*/
   (336068863L,
    IBP_MCE_FB40__INTERNAL_MSG_336068863,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1244*/
   (336068864L,
    dyn_package_not_found,
    "dyn_package_not_found",
    IBP_MCE_FB40__DYN_PACKAGE_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1245*/
   (336068865L,
    dyn_schema_not_found,
    "dyn_schema_not_found",
    IBP_MCE_FB40__DYN_SCHEMA_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1246*/
   (336068866L,
    dyn_cannot_mod_sysproc,
    "dyn_cannot_mod_sysproc",
    IBP_MCE_FB40__DYN_CANNOT_MOD_SYSPROC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1247*/
   (336068867L,
    dyn_cannot_mod_systrig,
    "dyn_cannot_mod_systrig",
    IBP_MCE_FB40__DYN_CANNOT_MOD_SYSTRIG,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1248*/
   (336068868L,
    dyn_cannot_mod_sysfunc,
    "dyn_cannot_mod_sysfunc",
    IBP_MCE_FB40__DYN_CANNOT_MOD_SYSFUNC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1249*/
   (336068869L,
    dyn_invalid_ddl_proc,
    "dyn_invalid_ddl_proc",
    IBP_MCE_FB40__DYN_INVALID_DDL_PROC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1250*/
   (336068870L,
    dyn_invalid_ddl_trig,
    "dyn_invalid_ddl_trig",
    IBP_MCE_FB40__DYN_INVALID_DDL_TRIG,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1251*/
   (336068871L,
    dyn_funcnotdef_package,
    "dyn_funcnotdef_package",
    IBP_MCE_FB40__DYN_FUNCNOTDEF_PACKAGE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1252*/
   (336068872L,
    dyn_procnotdef_package,
    "dyn_procnotdef_package",
    IBP_MCE_FB40__DYN_PROCNOTDEF_PACKAGE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1253*/
   (336068873L,
    dyn_funcsignat_package,
    "dyn_funcsignat_package",
    IBP_MCE_FB40__DYN_FUNCSIGNAT_PACKAGE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1254*/
   (336068874L,
    dyn_procsignat_package,
    "dyn_procsignat_package",
    IBP_MCE_FB40__DYN_PROCSIGNAT_PACKAGE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1255*/
   (336068875L,
    dyn_defvaldecl_package_proc,
    "dyn_defvaldecl_package_proc",
    IBP_MCE_FB40__DYN_DEFVALDECL_PACKAGE_PROC,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1256*/
   (336068876L,
    dyn_dup_function,
    "dyn_dup_function",
    IBP_MCE_FB40__DYN_DUP_FUNCTION,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1257*/
   (336068877L,
    dyn_package_body_exists,
    "dyn_package_body_exists",
    IBP_MCE_FB40__DYN_PACKAGE_BODY_EXISTS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1258*/
   (336068878L,
    dyn_invalid_ddl_func,
    "dyn_invalid_ddl_func",
    IBP_MCE_FB40__DYN_INVALID_DDL_FUNC,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1259*/
   (336068879L,
    dyn_newfc_oldsyntax,
    "dyn_newfc_oldsyntax",
    IBP_MCE_FB40__DYN_NEWFC_OLDSYNTAX,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1260*/
   (336068880L,
    IBP_MCE_FB40__INTERNAL_MSG_336068880,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1261*/
   (336068881L,
    IBP_MCE_FB40__INTERNAL_MSG_336068881,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1262*/
   (336068882L,
    IBP_MCE_FB40__INTERNAL_MSG_336068882,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1263*/
   (336068883L,
    IBP_MCE_FB40__INTERNAL_MSG_336068883,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1264*/
   (336068884L,
    IBP_MCE_FB40__INTERNAL_MSG_336068884,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1265*/
   (336068885L,
    IBP_MCE_FB40__INTERNAL_MSG_336068885,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1266*/
   (336068886L,
    dyn_func_param_not_found,
    "dyn_func_param_not_found",
    IBP_MCE_FB40__DYN_FUNC_PARAM_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1267*/
   (336068887L,
    dyn_routine_param_not_found,
    "dyn_routine_param_not_found",
    IBP_MCE_FB40__DYN_ROUTINE_PARAM_NOT_FOUND,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1268*/
   (336068888L,
    dyn_routine_param_ambiguous,
    "dyn_routine_param_ambiguous",
    IBP_MCE_FB40__DYN_ROUTINE_PARAM_AMBIGUOUS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1269*/
   (336068889L,
    dyn_coll_used_function,
    "dyn_coll_used_function",
    IBP_MCE_FB40__DYN_COLL_USED_FUNCTION,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1270*/
   (336068890L,
    dyn_domain_used_function,
    "dyn_domain_used_function",
    IBP_MCE_FB40__DYN_DOMAIN_USED_FUNCTION,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1271*/
   (336068891L,
    dyn_alter_user_no_clause,
    "dyn_alter_user_no_clause",
    IBP_MCE_FB40__DYN_ALTER_USER_NO_CLAUSE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1272*/
   (336068892L,
    IBP_MCE_FB40__INTERNAL_MSG_336068892,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1273*/
   (336068893L,
    IBP_MCE_FB40__INTERNAL_MSG_336068893,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1274*/
   (336068894L,
    dyn_duplicate_package_item,
    "dyn_duplicate_package_item",
    IBP_MCE_FB40__DYN_DUPLICATE_PACKAGE_ITEM,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1275*/
   (336068895L,
    dyn_cant_modify_sysobj,
    "dyn_cant_modify_sysobj",
    IBP_MCE_FB40__DYN_CANT_MODIFY_SYSOBJ,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1276*/
   (336068896L,
    dyn_cant_use_zero_increment,
    "dyn_cant_use_zero_increment",
    IBP_MCE_FB40__DYN_CANT_USE_ZERO_INCREMENT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1277*/
   (336068897L,
    dyn_cant_use_in_foreignkey,
    "dyn_cant_use_in_foreignkey",
    IBP_MCE_FB40__DYN_CANT_USE_IN_FOREIGNKEY,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1278*/
   (336068898L,
    dyn_defvaldecl_package_func,
    "dyn_defvaldecl_package_func",
    IBP_MCE_FB40__DYN_DEFVALDECL_PACKAGE_FUNC,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1279*/
   (336068899L,
    dyn_create_user_no_password,
    "dyn_create_user_no_password",
    IBP_MCE_FB40__DYN_CREATE_USER_NO_PASSWORD,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1280*/
   (336068900L,
    dyn_cyclic_role,
    "dyn_cyclic_role",
    IBP_MCE_FB40__DYN_CYCLIC_ROLE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1281*/
   (336068901L,
    IBP_MCE_FB40__INTERNAL_MSG_336068901,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1282*/
   (336068902L,
    IBP_MCE_FB40__INTERNAL_MSG_336068902,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1283*/
   (336068903L,
    IBP_MCE_FB40__INTERNAL_MSG_336068903,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1284*/
   (336068904L,
    dyn_cant_use_zero_inc_ident,
    "dyn_cant_use_zero_inc_ident",
    IBP_MCE_FB40__DYN_CANT_USE_ZERO_INC_IDENT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1285*/
   (336068905L,
    dyn_concur_alter_database,
    "dyn_concur_alter_database",
    IBP_MCE_FB40__DYN_CONCUR_ALTER_DATABASE,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1286*/
   (336068906L,
    dyn_incompat_alter_database,
    "dyn_incompat_alter_database",
    IBP_MCE_FB40__DYN_INCOMPAT_ALTER_DATABASE,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1287*/
   (336068907L,
    dyn_no_ddl_grant_opt_priv,
    "dyn_no_ddl_grant_opt_priv",
    IBP_MCE_FB40__DYN_NO_DDL_GRANT_OPT_PRIV,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1288*/
   (336068908L,
    dyn_no_grant_opt_priv,
    "dyn_no_grant_opt_priv",
    IBP_MCE_FB40__DYN_NO_GRANT_OPT_PRIV,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1289*/
   (336068909L,
    dyn_func_not_exist,
    "dyn_func_not_exist",
    IBP_MCE_FB40__DYN_FUNC_NOT_EXIST,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1290*/
   (336068910L,
    dyn_proc_not_exist,
    "dyn_proc_not_exist",
    IBP_MCE_FB40__DYN_PROC_NOT_EXIST,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1291*/
   (336068911L,
    dyn_pack_not_exist,
    "dyn_pack_not_exist",
    IBP_MCE_FB40__DYN_PACK_NOT_EXIST,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1292*/
   (336068912L,
    dyn_trig_not_exist,
    "dyn_trig_not_exist",
    IBP_MCE_FB40__DYN_TRIG_NOT_EXIST,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1293*/
   (336068913L,
    dyn_view_not_exist,
    "dyn_view_not_exist",
    IBP_MCE_FB40__DYN_VIEW_NOT_EXIST,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1294*/
   (336068914L,
    dyn_rel_not_exist,
    "dyn_rel_not_exist",
    IBP_MCE_FB40__DYN_REL_NOT_EXIST,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1295*/
   (336068915L,
    dyn_exc_not_exist,
    "dyn_exc_not_exist",
    IBP_MCE_FB40__DYN_EXC_NOT_EXIST,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1296*/
   (336068916L,
    dyn_gen_not_exist,
    "dyn_gen_not_exist",
    IBP_MCE_FB40__DYN_GEN_NOT_EXIST,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1297*/
   (336068917L,
    dyn_fld_not_exist,
    "dyn_fld_not_exist",
    IBP_MCE_FB40__DYN_FLD_NOT_EXIST,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1298*/
   (336396289L,
    IBP_MCE_FB40__INTERNAL_MSG_336396289,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1299*/
   (336396362L,
    IBP_MCE_FB40__INTERNAL_MSG_336396362,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1300*/
   (336396364L,
    IBP_MCE_FB40__INTERNAL_MSG_336396364,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1301*/
   (336396365L,
    IBP_MCE_FB40__INTERNAL_MSG_336396365,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1302*/
   (336396366L,
    IBP_MCE_FB40__INTERNAL_MSG_336396366,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1303*/
   (336396375L,
    IBP_MCE_FB40__INTERNAL_MSG_336396375,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1304*/
   (336396376L,
    IBP_MCE_FB40__INTERNAL_MSG_336396376,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1305*/
   (336396377L,
    IBP_MCE_FB40__INTERNAL_MSG_336396377,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1306*/
   (336396379L,
    IBP_MCE_FB40__INTERNAL_MSG_336396379,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1307*/
   (336396382L,
    IBP_MCE_FB40__INTERNAL_MSG_336396382,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1308*/
   (336396384L,
    IBP_MCE_FB40__INTERNAL_MSG_336396384,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1309*/
   (336396386L,
    IBP_MCE_FB40__INTERNAL_MSG_336396386,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1310*/
   (336396387L,
    IBP_MCE_FB40__INTERNAL_MSG_336396387,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1311*/
   (336396446L,
    IBP_MCE_FB40__INTERNAL_MSG_336396446,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1312*/
   (336396447L,
    IBP_MCE_FB40__INTERNAL_MSG_336396447,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1313*/
   (336396448L,
    IBP_MCE_FB40__INTERNAL_MSG_336396448,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1314*/
   (336396449L,
    IBP_MCE_FB40__INTERNAL_MSG_336396449,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1315*/
   (336396450L,
    IBP_MCE_FB40__INTERNAL_MSG_336396450,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1316*/
   (336396451L,
    IBP_MCE_FB40__INTERNAL_MSG_336396451,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1317*/
   (336396452L,
    IBP_MCE_FB40__INTERNAL_MSG_336396452,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1318*/
   (336396453L,
    IBP_MCE_FB40__INTERNAL_MSG_336396453,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1319*/
   (336396454L,
    IBP_MCE_FB40__INTERNAL_MSG_336396454,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1320*/
   (336396455L,
    IBP_MCE_FB40__INTERNAL_MSG_336396455,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1321*/
   (336396456L,
    IBP_MCE_FB40__INTERNAL_MSG_336396456,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1322*/
   (336396457L,
    IBP_MCE_FB40__INTERNAL_MSG_336396457,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1323*/
   (336396458L,
    IBP_MCE_FB40__INTERNAL_MSG_336396458,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1324*/
   (336396459L,
    IBP_MCE_FB40__INTERNAL_MSG_336396459,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1325*/
   (336396460L,
    IBP_MCE_FB40__INTERNAL_MSG_336396460,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1326*/
   (336396461L,
    IBP_MCE_FB40__INTERNAL_MSG_336396461,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1327*/
   (336396462L,
    IBP_MCE_FB40__INTERNAL_MSG_336396462,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1328*/
   (336396463L,
    IBP_MCE_FB40__INTERNAL_MSG_336396463,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1329*/
   (336396464L,
    IBP_MCE_FB40__INTERNAL_MSG_336396464,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1330*/
   (336396465L,
    IBP_MCE_FB40__INTERNAL_MSG_336396465,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1331*/
   (336396468L,
    IBP_MCE_FB40__INTERNAL_MSG_336396468,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1332*/
   (336396471L,
    IBP_MCE_FB40__INTERNAL_MSG_336396471,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1333*/
   (336396472L,
    IBP_MCE_FB40__INTERNAL_MSG_336396472,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1334*/
   (336396477L,
    IBP_MCE_FB40__INTERNAL_MSG_336396477,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1335*/
   (336396478L,
    IBP_MCE_FB40__INTERNAL_MSG_336396478,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1336*/
   (336396479L,
    IBP_MCE_FB40__INTERNAL_MSG_336396479,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1337*/
   (336396480L,
    IBP_MCE_FB40__INTERNAL_MSG_336396480,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1338*/
   (336396481L,
    IBP_MCE_FB40__INTERNAL_MSG_336396481,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1339*/
   (336396482L,
    IBP_MCE_FB40__INTERNAL_MSG_336396482,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1340*/
   (336396484L,
    IBP_MCE_FB40__INTERNAL_MSG_336396484,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1341*/
   (336396485L,
    IBP_MCE_FB40__INTERNAL_MSG_336396485,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1342*/
   (336396486L,
    IBP_MCE_FB40__INTERNAL_MSG_336396486,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1343*/
   (336396594L,
    IBP_MCE_FB40__INTERNAL_MSG_336396594,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1344*/
   (336396595L,
    IBP_MCE_FB40__INTERNAL_MSG_336396595,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1345*/
   (336396596L,
    IBP_MCE_FB40__INTERNAL_MSG_336396596,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1346*/
   (336396597L,
    IBP_MCE_FB40__INTERNAL_MSG_336396597,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1347*/
   (336396598L,
    IBP_MCE_FB40__INTERNAL_MSG_336396598,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1348*/
   (336396599L,
    IBP_MCE_FB40__INTERNAL_MSG_336396599,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1349*/
   (336396603L,
    IBP_MCE_FB40__INTERNAL_MSG_336396603,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1350*/
   (336396611L,
    IBP_MCE_FB40__INTERNAL_MSG_336396611,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1351*/
   (336396624L,
    IBP_MCE_FB40__INTERNAL_MSG_336396624,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1352*/
   (336396625L,
    IBP_MCE_FB40__INTERNAL_MSG_336396625,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1353*/
   (336396628L,
    IBP_MCE_FB40__INTERNAL_MSG_336396628,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1354*/
   (336396651L,
    IBP_MCE_FB40__INTERNAL_MSG_336396651,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1355*/
   (336396663L,
    IBP_MCE_FB40__INTERNAL_MSG_336396663,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1356*/
   (336396670L,
    IBP_MCE_FB40__INTERNAL_MSG_336396670,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1357*/
   (336396671L,
    IBP_MCE_FB40__INTERNAL_MSG_336396671,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1358*/
   (336396672L,
    IBP_MCE_FB40__INTERNAL_MSG_336396672,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1359*/
   (336396673L,
    IBP_MCE_FB40__INTERNAL_MSG_336396673,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1360*/
   (336396681L,
    IBP_MCE_FB40__INTERNAL_MSG_336396681,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1361*/
   (336396683L,
    IBP_MCE_FB40__INTERNAL_MSG_336396683,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1362*/
   (336396684L,
    IBP_MCE_FB40__INTERNAL_MSG_336396684,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1363*/
   (336396687L,
    IBP_MCE_FB40__INTERNAL_MSG_336396687,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1364*/
   (336396688L,
    IBP_MCE_FB40__INTERNAL_MSG_336396688,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1365*/
   (336396689L,
    IBP_MCE_FB40__INTERNAL_MSG_336396689,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1366*/
   (336396690L,
    IBP_MCE_FB40__INTERNAL_MSG_336396690,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1367*/
   (336396691L,
    IBP_MCE_FB40__INTERNAL_MSG_336396691,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1368*/
   (336396692L,
    IBP_MCE_FB40__INTERNAL_MSG_336396692,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1369*/
   (336396693L,
    IBP_MCE_FB40__INTERNAL_MSG_336396693,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1370*/
   (336396735L,
    IBP_MCE_FB40__INTERNAL_MSG_336396735,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1371*/
   (336396736L,
    IBP_MCE_FB40__INTERNAL_MSG_336396736,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1372*/
   (336396737L,
    IBP_MCE_FB40__INTERNAL_MSG_336396737,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1373*/
   (336396756L,
    IBP_MCE_FB40__INTERNAL_MSG_336396756,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1374*/
   (336396757L,
    IBP_MCE_FB40__INTERNAL_MSG_336396757,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1375*/
   (336396758L,
    IBP_MCE_FB40__INTERNAL_MSG_336396758,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1376*/
   (336396769L,
    IBP_MCE_FB40__INTERNAL_MSG_336396769,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1377*/
   (336396770L,
    IBP_MCE_FB40__INTERNAL_MSG_336396770,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1378*/
   (336396778L,
    IBP_MCE_FB40__INTERNAL_MSG_336396778,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1379*/
   (336396780L,
    IBP_MCE_FB40__INTERNAL_MSG_336396780,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1380*/
   (336396784L,
    IBP_MCE_FB40__INTERNAL_MSG_336396784,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1381*/
   (336396786L,
    IBP_MCE_FB40__INTERNAL_MSG_336396786,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1382*/
   (336396787L,
    IBP_MCE_FB40__INTERNAL_MSG_336396787,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1383*/
   (336396875L,
    IBP_MCE_FB40__INTERNAL_MSG_336396875,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1384*/
   (336396881L,
    IBP_MCE_FB40__INTERNAL_MSG_336396881,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1385*/
   (336396882L,
    IBP_MCE_FB40__INTERNAL_MSG_336396882,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1386*/
   (336396886L,
    IBP_MCE_FB40__INTERNAL_MSG_336396886,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1387*/
   (336396887L,
    IBP_MCE_FB40__INTERNAL_MSG_336396887,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1388*/
   (336396974L,
    IBP_MCE_FB40__INTERNAL_MSG_336396974,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1389*/
   (336396975L,
    IBP_MCE_FB40__INTERNAL_MSG_336396975,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1390*/
   (336396985L,
    IBP_MCE_FB40__INTERNAL_MSG_336396985,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1391*/
   (336396991L,
    IBP_MCE_FB40__INTERNAL_MSG_336396991,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1392*/
   (336396992L,
    IBP_MCE_FB40__INTERNAL_MSG_336396992,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1393*/
   (336396993L,
    IBP_MCE_FB40__INTERNAL_MSG_336396993,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1394*/
   (336396994L,
    IBP_MCE_FB40__INTERNAL_MSG_336396994,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1395*/
   (336396995L,
    IBP_MCE_FB40__INTERNAL_MSG_336396995,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1396*/
   (336396996L,
    IBP_MCE_FB40__INTERNAL_MSG_336396996,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1397*/
   (336396997L,
    IBP_MCE_FB40__INTERNAL_MSG_336396997,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1398*/
   (336397004L,
    IBP_MCE_FB40__INTERNAL_MSG_336397004,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1399*/
   (336397005L,
    IBP_MCE_FB40__INTERNAL_MSG_336397005,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1400*/
   (336397006L,
    IBP_MCE_FB40__INTERNAL_MSG_336397006,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1401*/
   (336397007L,
    IBP_MCE_FB40__INTERNAL_MSG_336397007,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1402*/
   (336397027L,
    IBP_MCE_FB40__INTERNAL_MSG_336397027,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1403*/
   (336397028L,
    IBP_MCE_FB40__INTERNAL_MSG_336397028,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1404*/
   (336397029L,
    IBP_MCE_FB40__INTERNAL_MSG_336397029,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1405*/
   (336397030L,
    IBP_MCE_FB40__INTERNAL_MSG_336397030,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1406*/
   (336397031L,
    IBP_MCE_FB40__INTERNAL_MSG_336397031,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1407*/
   (336397033L,
    IBP_MCE_FB40__INTERNAL_MSG_336397033,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1408*/
   (336397034L,
    IBP_MCE_FB40__INTERNAL_MSG_336397034,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1409*/
   (336397035L,
    IBP_MCE_FB40__INTERNAL_MSG_336397035,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1410*/
   (336397036L,
    IBP_MCE_FB40__INTERNAL_MSG_336397036,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1411*/
   (336397037L,
    IBP_MCE_FB40__INTERNAL_MSG_336397037,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1412*/
   (336397038L,
    IBP_MCE_FB40__INTERNAL_MSG_336397038,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1413*/
   (336397039L,
    IBP_MCE_FB40__INTERNAL_MSG_336397039,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1414*/
   (336397040L,
    IBP_MCE_FB40__INTERNAL_MSG_336397040,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1415*/
   (336397041L,
    IBP_MCE_FB40__INTERNAL_MSG_336397041,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1416*/
   (336397042L,
    IBP_MCE_FB40__INTERNAL_MSG_336397042,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1417*/
   (336397043L,
    IBP_MCE_FB40__INTERNAL_MSG_336397043,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1418*/
   (336397044L,
    IBP_MCE_FB40__INTERNAL_MSG_336397044,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1419*/
   (336397045L,
    IBP_MCE_FB40__INTERNAL_MSG_336397045,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1420*/
   (336397046L,
    IBP_MCE_FB40__INTERNAL_MSG_336397046,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1421*/
   (336397047L,
    IBP_MCE_FB40__INTERNAL_MSG_336397047,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1422*/
   (336397048L,
    IBP_MCE_FB40__INTERNAL_MSG_336397048,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1423*/
   (336397049L,
    IBP_MCE_FB40__INTERNAL_MSG_336397049,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1424*/
   (336397050L,
    IBP_MCE_FB40__INTERNAL_MSG_336397050,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1425*/
   (336397051L,
    IBP_MCE_FB40__INTERNAL_MSG_336397051,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1426*/
   (336397052L,
    IBP_MCE_FB40__INTERNAL_MSG_336397052,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1427*/
   (336397053L,
    IBP_MCE_FB40__INTERNAL_MSG_336397053,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1428*/
   (336397054L,
    IBP_MCE_FB40__INTERNAL_MSG_336397054,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1429*/
   (336397055L,
    IBP_MCE_FB40__INTERNAL_MSG_336397055,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1430*/
   (336397056L,
    IBP_MCE_FB40__INTERNAL_MSG_336397056,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1431*/
   (336397057L,
    IBP_MCE_FB40__INTERNAL_MSG_336397057,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1432*/
   (336397058L,
    IBP_MCE_FB40__INTERNAL_MSG_336397058,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1433*/
   (336397069L,
    IBP_MCE_FB40__INTERNAL_MSG_336397069,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1434*/
   (336397080L,
    IBP_MCE_FB40__INTERNAL_MSG_336397080,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1435*/
   (336397082L,
    IBP_MCE_FB40__INTERNAL_MSG_336397082,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1436*/
   (336397083L,
    IBP_MCE_FB40__INTERNAL_MSG_336397083,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1437*/
   (336397084L,
    IBP_MCE_FB40__INTERNAL_MSG_336397084,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1438*/
   (336397085L,
    IBP_MCE_FB40__INTERNAL_MSG_336397085,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1439*/
   (336397116L,
    IBP_MCE_FB40__INTERNAL_MSG_336397116,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1440*/
   (336397117L,
    IBP_MCE_FB40__INTERNAL_MSG_336397117,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1441*/
   (336397118L,
    IBP_MCE_FB40__INTERNAL_MSG_336397118,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1442*/
   (336397126L,
    IBP_MCE_FB40__INTERNAL_MSG_336397126,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1443*/
   (336397130L,
    IBP_MCE_FB40__INTERNAL_MSG_336397130,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1444*/
   (336397131L,
    IBP_MCE_FB40__INTERNAL_MSG_336397131,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1445*/
   (336397133L,
    IBP_MCE_FB40__INTERNAL_MSG_336397133,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1446*/
   (336397137L,
    IBP_MCE_FB40__INTERNAL_MSG_336397137,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1447*/
   (336397138L,
    IBP_MCE_FB40__INTERNAL_MSG_336397138,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1448*/
   (336397183L,
    IBP_MCE_FB40__INTERNAL_MSG_336397183,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1449*/
   (336397184L,
    IBP_MCE_FB40__INTERNAL_MSG_336397184,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1450*/
   (336397185L,
    IBP_MCE_FB40__INTERNAL_MSG_336397185,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1451*/
   (336397203L,
    IBP_MCE_FB40__INTERNAL_MSG_336397203,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1452*/
   (336397204L,
    IBP_MCE_FB40__INTERNAL_MSG_336397204,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1453*/
   (336397205L,
    dsql_too_old_ods,
    "dsql_too_old_ods",
    IBP_MCE_FB40__DSQL_TOO_OLD_ODS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1454*/
   (336397206L,
    dsql_table_not_found,
    "dsql_table_not_found",
    IBP_MCE_FB40__DSQL_TABLE_NOT_FOUND,
    IBP_SQLSTATE__42S02__ODBC__BASE_TABLE_OR_VIEW_NOT_FOUND,
    DB_E_NOTABLE)
 ADD_CODE         /*1455*/
   (336397207L,
    dsql_view_not_found,
    "dsql_view_not_found",
    IBP_MCE_FB40__DSQL_VIEW_NOT_FOUND,
    IBP_SQLSTATE__42S02__ODBC__BASE_TABLE_OR_VIEW_NOT_FOUND,
    DB_E_NOTABLE)
 ADD_CODE         /*1456*/
   (336397208L,
    dsql_line_col_error,
    "dsql_line_col_error",
    IBP_MCE_FB40__DSQL_LINE_COL_ERROR,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1457*/
   (336397209L,
    dsql_unknown_pos,
    "dsql_unknown_pos",
    IBP_MCE_FB40__DSQL_UNKNOWN_POS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1458*/
   (336397210L,
    dsql_no_dup_name,
    "dsql_no_dup_name",
    IBP_MCE_FB40__DSQL_NO_DUP_NAME,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1459*/
   (336397211L,
    dsql_too_many_values,
    "dsql_too_many_values",
    IBP_MCE_FB40__DSQL_TOO_MANY_VALUES,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1460*/
   (336397212L,
    dsql_no_array_computed,
    "dsql_no_array_computed",
    IBP_MCE_FB40__DSQL_NO_ARRAY_COMPUTED,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1461*/
   (336397213L,
    dsql_implicit_domain_name,
    "dsql_implicit_domain_name",
    IBP_MCE_FB40__DSQL_IMPLICIT_DOMAIN_NAME,
    IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1462*/
   (336397214L,
    dsql_only_can_subscript_array,
    "dsql_only_can_subscript_array",
    IBP_MCE_FB40__DSQL_ONLY_CAN_SUBSCRIPT_ARRAY,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1463*/
   (336397215L,
    dsql_max_sort_items,
    "dsql_max_sort_items",
    IBP_MCE_FB40__DSQL_MAX_SORT_ITEMS,
    IBP_SQLSTATE__54011__TOO_MANY_COLUMNS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1464*/
   (336397216L,
    dsql_max_group_items,
    "dsql_max_group_items",
    IBP_MCE_FB40__DSQL_MAX_GROUP_ITEMS,
    IBP_SQLSTATE__54011__TOO_MANY_COLUMNS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1465*/
   (336397217L,
    dsql_conflicting_sort_field,
    "dsql_conflicting_sort_field",
    IBP_MCE_FB40__DSQL_CONFLICTING_SORT_FIELD,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1466*/
   (336397218L,
    dsql_derived_table_more_columns,
    "dsql_derived_table_more_columns",
    IBP_MCE_FB40__DSQL_DERIVED_TABLE_MORE_COLUMNS,
    IBP_SQLSTATE__54001__STATEMENT_TOO_COMPLEX,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1467*/
   (336397219L,
    dsql_derived_table_less_columns,
    "dsql_derived_table_less_columns",
    IBP_MCE_FB40__DSQL_DERIVED_TABLE_LESS_COLUMNS,
    IBP_SQLSTATE__54001__STATEMENT_TOO_COMPLEX,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1468*/
   (336397220L,
    dsql_derived_field_unnamed,
    "dsql_derived_field_unnamed",
    IBP_MCE_FB40__DSQL_DERIVED_FIELD_UNNAMED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1469*/
   (336397221L,
    dsql_derived_field_dup_name,
    "dsql_derived_field_dup_name",
    IBP_MCE_FB40__DSQL_DERIVED_FIELD_DUP_NAME,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1470*/
   (336397222L,
    dsql_derived_alias_select,
    "dsql_derived_alias_select",
    IBP_MCE_FB40__DSQL_DERIVED_ALIAS_SELECT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1471*/
   (336397223L,
    dsql_derived_alias_field,
    "dsql_derived_alias_field",
    IBP_MCE_FB40__DSQL_DERIVED_ALIAS_FIELD,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1472*/
   (336397224L,
    dsql_auto_field_bad_pos,
    "dsql_auto_field_bad_pos",
    IBP_MCE_FB40__DSQL_AUTO_FIELD_BAD_POS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1473*/
   (336397225L,
    dsql_cte_wrong_reference,
    "dsql_cte_wrong_reference",
    IBP_MCE_FB40__DSQL_CTE_WRONG_REFERENCE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1474*/
   (336397226L,
    dsql_cte_cycle,
    "dsql_cte_cycle",
    IBP_MCE_FB40__DSQL_CTE_CYCLE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1475*/
   (336397227L,
    dsql_cte_outer_join,
    "dsql_cte_outer_join",
    IBP_MCE_FB40__DSQL_CTE_OUTER_JOIN,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1476*/
   (336397228L,
    dsql_cte_mult_references,
    "dsql_cte_mult_references",
    IBP_MCE_FB40__DSQL_CTE_MULT_REFERENCES,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1477*/
   (336397229L,
    dsql_cte_not_a_union,
    "dsql_cte_not_a_union",
    IBP_MCE_FB40__DSQL_CTE_NOT_A_UNION,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1478*/
   (336397230L,
    dsql_cte_nonrecurs_after_recurs,
    "dsql_cte_nonrecurs_after_recurs",
    IBP_MCE_FB40__DSQL_CTE_NONRECURS_AFTER_RECURS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1479*/
   (336397231L,
    dsql_cte_wrong_clause,
    "dsql_cte_wrong_clause",
    IBP_MCE_FB40__DSQL_CTE_WRONG_CLAUSE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1480*/
   (336397232L,
    dsql_cte_union_all,
    "dsql_cte_union_all",
    IBP_MCE_FB40__DSQL_CTE_UNION_ALL,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1481*/
   (336397233L,
    dsql_cte_miss_nonrecursive,
    "dsql_cte_miss_nonrecursive",
    IBP_MCE_FB40__DSQL_CTE_MISS_NONRECURSIVE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1482*/
   (336397234L,
    dsql_cte_nested_with,
    "dsql_cte_nested_with",
    IBP_MCE_FB40__DSQL_CTE_NESTED_WITH,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1483*/
   (336397235L,
    dsql_col_more_than_once_using,
    "dsql_col_more_than_once_using",
    IBP_MCE_FB40__DSQL_COL_MORE_THAN_ONCE_USING,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1484*/
   (336397236L,
    dsql_unsupp_feature_dialect,
    "dsql_unsupp_feature_dialect",
    IBP_MCE_FB40__DSQL_UNSUPP_FEATURE_DIALECT,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1485*/
   (336397237L,
    dsql_cte_not_used,
    "dsql_cte_not_used",
    IBP_MCE_FB40__DSQL_CTE_NOT_USED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1486*/
   (336397238L,
    dsql_col_more_than_once_view,
    "dsql_col_more_than_once_view",
    IBP_MCE_FB40__DSQL_COL_MORE_THAN_ONCE_VIEW,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1487*/
   (336397239L,
    dsql_unsupported_in_auto_trans,
    "dsql_unsupported_in_auto_trans",
    IBP_MCE_FB40__DSQL_UNSUPPORTED_IN_AUTO_TRANS,
    IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1488*/
   (336397240L,
    dsql_eval_unknode,
    "dsql_eval_unknode",
    IBP_MCE_FB40__DSQL_EVAL_UNKNODE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1489*/
   (336397241L,
    dsql_agg_wrongarg,
    "dsql_agg_wrongarg",
    IBP_MCE_FB40__DSQL_AGG_WRONGARG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1490*/
   (336397242L,
    dsql_agg2_wrongarg,
    "dsql_agg2_wrongarg",
    IBP_MCE_FB40__DSQL_AGG2_WRONGARG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1491*/
   (336397243L,
    dsql_nodateortime_pm_string,
    "dsql_nodateortime_pm_string",
    IBP_MCE_FB40__DSQL_NODATEORTIME_PM_STRING,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1492*/
   (336397244L,
    dsql_invalid_datetime_subtract,
    "dsql_invalid_datetime_subtract",
    IBP_MCE_FB40__DSQL_INVALID_DATETIME_SUBTRACT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1493*/
   (336397245L,
    dsql_invalid_dateortime_add,
    "dsql_invalid_dateortime_add",
    IBP_MCE_FB40__DSQL_INVALID_DATEORTIME_ADD,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1494*/
   (336397246L,
    dsql_invalid_type_minus_date,
    "dsql_invalid_type_minus_date",
    IBP_MCE_FB40__DSQL_INVALID_TYPE_MINUS_DATE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1495*/
   (336397247L,
    dsql_nostring_addsub_dial3,
    "dsql_nostring_addsub_dial3",
    IBP_MCE_FB40__DSQL_NOSTRING_ADDSUB_DIAL3,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1496*/
   (336397248L,
    dsql_invalid_type_addsub_dial3,
    "dsql_invalid_type_addsub_dial3",
    IBP_MCE_FB40__DSQL_INVALID_TYPE_ADDSUB_DIAL3,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1497*/
   (336397249L,
    dsql_invalid_type_multip_dial1,
    "dsql_invalid_type_multip_dial1",
    IBP_MCE_FB40__DSQL_INVALID_TYPE_MULTIP_DIAL1,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1498*/
   (336397250L,
    dsql_nostring_multip_dial3,
    "dsql_nostring_multip_dial3",
    IBP_MCE_FB40__DSQL_NOSTRING_MULTIP_DIAL3,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1499*/
   (336397251L,
    dsql_invalid_type_multip_dial3,
    "dsql_invalid_type_multip_dial3",
    IBP_MCE_FB40__DSQL_INVALID_TYPE_MULTIP_DIAL3,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1500*/
   (336397252L,
    dsql_mustuse_numeric_div_dial1,
    "dsql_mustuse_numeric_div_dial1",
    IBP_MCE_FB40__DSQL_MUSTUSE_NUMERIC_DIV_DIAL1,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1501*/
   (336397253L,
    dsql_nostring_div_dial3,
    "dsql_nostring_div_dial3",
    IBP_MCE_FB40__DSQL_NOSTRING_DIV_DIAL3,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1502*/
   (336397254L,
    dsql_invalid_type_div_dial3,
    "dsql_invalid_type_div_dial3",
    IBP_MCE_FB40__DSQL_INVALID_TYPE_DIV_DIAL3,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1503*/
   (336397255L,
    dsql_nostring_neg_dial3,
    "dsql_nostring_neg_dial3",
    IBP_MCE_FB40__DSQL_NOSTRING_NEG_DIAL3,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1504*/
   (336397256L,
    dsql_invalid_type_neg,
    "dsql_invalid_type_neg",
    IBP_MCE_FB40__DSQL_INVALID_TYPE_NEG,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1505*/
   (336397257L,
    dsql_max_distinct_items,
    "dsql_max_distinct_items",
    IBP_MCE_FB40__DSQL_MAX_DISTINCT_ITEMS,
    IBP_SQLSTATE__54011__TOO_MANY_COLUMNS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1506*/
   (336397258L,
    dsql_alter_charset_failed,
    "dsql_alter_charset_failed",
    IBP_MCE_FB40__DSQL_ALTER_CHARSET_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1507*/
   (336397259L,
    dsql_comment_on_failed,
    "dsql_comment_on_failed",
    IBP_MCE_FB40__DSQL_COMMENT_ON_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1508*/
   (336397260L,
    dsql_create_func_failed,
    "dsql_create_func_failed",
    IBP_MCE_FB40__DSQL_CREATE_FUNC_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1509*/
   (336397261L,
    dsql_alter_func_failed,
    "dsql_alter_func_failed",
    IBP_MCE_FB40__DSQL_ALTER_FUNC_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1510*/
   (336397262L,
    dsql_create_alter_func_failed,
    "dsql_create_alter_func_failed",
    IBP_MCE_FB40__DSQL_CREATE_ALTER_FUNC_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1511*/
   (336397263L,
    dsql_drop_func_failed,
    "dsql_drop_func_failed",
    IBP_MCE_FB40__DSQL_DROP_FUNC_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1512*/
   (336397264L,
    dsql_recreate_func_failed,
    "dsql_recreate_func_failed",
    IBP_MCE_FB40__DSQL_RECREATE_FUNC_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1513*/
   (336397265L,
    dsql_create_proc_failed,
    "dsql_create_proc_failed",
    IBP_MCE_FB40__DSQL_CREATE_PROC_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1514*/
   (336397266L,
    dsql_alter_proc_failed,
    "dsql_alter_proc_failed",
    IBP_MCE_FB40__DSQL_ALTER_PROC_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1515*/
   (336397267L,
    dsql_create_alter_proc_failed,
    "dsql_create_alter_proc_failed",
    IBP_MCE_FB40__DSQL_CREATE_ALTER_PROC_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1516*/
   (336397268L,
    dsql_drop_proc_failed,
    "dsql_drop_proc_failed",
    IBP_MCE_FB40__DSQL_DROP_PROC_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1517*/
   (336397269L,
    dsql_recreate_proc_failed,
    "dsql_recreate_proc_failed",
    IBP_MCE_FB40__DSQL_RECREATE_PROC_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1518*/
   (336397270L,
    dsql_create_trigger_failed,
    "dsql_create_trigger_failed",
    IBP_MCE_FB40__DSQL_CREATE_TRIGGER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1519*/
   (336397271L,
    dsql_alter_trigger_failed,
    "dsql_alter_trigger_failed",
    IBP_MCE_FB40__DSQL_ALTER_TRIGGER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1520*/
   (336397272L,
    dsql_create_alter_trigger_failed,
    "dsql_create_alter_trigger_failed",
    IBP_MCE_FB40__DSQL_CREATE_ALTER_TRIGGER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1521*/
   (336397273L,
    dsql_drop_trigger_failed,
    "dsql_drop_trigger_failed",
    IBP_MCE_FB40__DSQL_DROP_TRIGGER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1522*/
   (336397274L,
    dsql_recreate_trigger_failed,
    "dsql_recreate_trigger_failed",
    IBP_MCE_FB40__DSQL_RECREATE_TRIGGER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1523*/
   (336397275L,
    dsql_create_collation_failed,
    "dsql_create_collation_failed",
    IBP_MCE_FB40__DSQL_CREATE_COLLATION_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1524*/
   (336397276L,
    dsql_drop_collation_failed,
    "dsql_drop_collation_failed",
    IBP_MCE_FB40__DSQL_DROP_COLLATION_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1525*/
   (336397277L,
    dsql_create_domain_failed,
    "dsql_create_domain_failed",
    IBP_MCE_FB40__DSQL_CREATE_DOMAIN_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1526*/
   (336397278L,
    dsql_alter_domain_failed,
    "dsql_alter_domain_failed",
    IBP_MCE_FB40__DSQL_ALTER_DOMAIN_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1527*/
   (336397279L,
    dsql_drop_domain_failed,
    "dsql_drop_domain_failed",
    IBP_MCE_FB40__DSQL_DROP_DOMAIN_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1528*/
   (336397280L,
    dsql_create_except_failed,
    "dsql_create_except_failed",
    IBP_MCE_FB40__DSQL_CREATE_EXCEPT_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1529*/
   (336397281L,
    dsql_alter_except_failed,
    "dsql_alter_except_failed",
    IBP_MCE_FB40__DSQL_ALTER_EXCEPT_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1530*/
   (336397282L,
    dsql_create_alter_except_failed,
    "dsql_create_alter_except_failed",
    IBP_MCE_FB40__DSQL_CREATE_ALTER_EXCEPT_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1531*/
   (336397283L,
    dsql_recreate_except_failed,
    "dsql_recreate_except_failed",
    IBP_MCE_FB40__DSQL_RECREATE_EXCEPT_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1532*/
   (336397284L,
    dsql_drop_except_failed,
    "dsql_drop_except_failed",
    IBP_MCE_FB40__DSQL_DROP_EXCEPT_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1533*/
   (336397285L,
    dsql_create_sequence_failed,
    "dsql_create_sequence_failed",
    IBP_MCE_FB40__DSQL_CREATE_SEQUENCE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1534*/
   (336397286L,
    dsql_create_table_failed,
    "dsql_create_table_failed",
    IBP_MCE_FB40__DSQL_CREATE_TABLE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1535*/
   (336397287L,
    dsql_alter_table_failed,
    "dsql_alter_table_failed",
    IBP_MCE_FB40__DSQL_ALTER_TABLE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1536*/
   (336397288L,
    dsql_drop_table_failed,
    "dsql_drop_table_failed",
    IBP_MCE_FB40__DSQL_DROP_TABLE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1537*/
   (336397289L,
    dsql_recreate_table_failed,
    "dsql_recreate_table_failed",
    IBP_MCE_FB40__DSQL_RECREATE_TABLE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1538*/
   (336397290L,
    dsql_create_pack_failed,
    "dsql_create_pack_failed",
    IBP_MCE_FB40__DSQL_CREATE_PACK_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1539*/
   (336397291L,
    dsql_alter_pack_failed,
    "dsql_alter_pack_failed",
    IBP_MCE_FB40__DSQL_ALTER_PACK_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1540*/
   (336397292L,
    dsql_create_alter_pack_failed,
    "dsql_create_alter_pack_failed",
    IBP_MCE_FB40__DSQL_CREATE_ALTER_PACK_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1541*/
   (336397293L,
    dsql_drop_pack_failed,
    "dsql_drop_pack_failed",
    IBP_MCE_FB40__DSQL_DROP_PACK_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1542*/
   (336397294L,
    dsql_recreate_pack_failed,
    "dsql_recreate_pack_failed",
    IBP_MCE_FB40__DSQL_RECREATE_PACK_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1543*/
   (336397295L,
    dsql_create_pack_body_failed,
    "dsql_create_pack_body_failed",
    IBP_MCE_FB40__DSQL_CREATE_PACK_BODY_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1544*/
   (336397296L,
    dsql_drop_pack_body_failed,
    "dsql_drop_pack_body_failed",
    IBP_MCE_FB40__DSQL_DROP_PACK_BODY_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1545*/
   (336397297L,
    dsql_recreate_pack_body_failed,
    "dsql_recreate_pack_body_failed",
    IBP_MCE_FB40__DSQL_RECREATE_PACK_BODY_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1546*/
   (336397298L,
    dsql_create_view_failed,
    "dsql_create_view_failed",
    IBP_MCE_FB40__DSQL_CREATE_VIEW_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1547*/
   (336397299L,
    dsql_alter_view_failed,
    "dsql_alter_view_failed",
    IBP_MCE_FB40__DSQL_ALTER_VIEW_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1548*/
   (336397300L,
    dsql_create_alter_view_failed,
    "dsql_create_alter_view_failed",
    IBP_MCE_FB40__DSQL_CREATE_ALTER_VIEW_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1549*/
   (336397301L,
    dsql_recreate_view_failed,
    "dsql_recreate_view_failed",
    IBP_MCE_FB40__DSQL_RECREATE_VIEW_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1550*/
   (336397302L,
    dsql_drop_view_failed,
    "dsql_drop_view_failed",
    IBP_MCE_FB40__DSQL_DROP_VIEW_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1551*/
   (336397303L,
    dsql_drop_sequence_failed,
    "dsql_drop_sequence_failed",
    IBP_MCE_FB40__DSQL_DROP_SEQUENCE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1552*/
   (336397304L,
    dsql_recreate_sequence_failed,
    "dsql_recreate_sequence_failed",
    IBP_MCE_FB40__DSQL_RECREATE_SEQUENCE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1553*/
   (336397305L,
    dsql_drop_index_failed,
    "dsql_drop_index_failed",
    IBP_MCE_FB40__DSQL_DROP_INDEX_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1554*/
   (336397306L,
    dsql_drop_filter_failed,
    "dsql_drop_filter_failed",
    IBP_MCE_FB40__DSQL_DROP_FILTER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1555*/
   (336397307L,
    dsql_drop_shadow_failed,
    "dsql_drop_shadow_failed",
    IBP_MCE_FB40__DSQL_DROP_SHADOW_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1556*/
   (336397308L,
    dsql_drop_role_failed,
    "dsql_drop_role_failed",
    IBP_MCE_FB40__DSQL_DROP_ROLE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1557*/
   (336397309L,
    dsql_drop_user_failed,
    "dsql_drop_user_failed",
    IBP_MCE_FB40__DSQL_DROP_USER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1558*/
   (336397310L,
    dsql_create_role_failed,
    "dsql_create_role_failed",
    IBP_MCE_FB40__DSQL_CREATE_ROLE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1559*/
   (336397311L,
    dsql_alter_role_failed,
    "dsql_alter_role_failed",
    IBP_MCE_FB40__DSQL_ALTER_ROLE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1560*/
   (336397312L,
    dsql_alter_index_failed,
    "dsql_alter_index_failed",
    IBP_MCE_FB40__DSQL_ALTER_INDEX_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1561*/
   (336397313L,
    dsql_alter_database_failed,
    "dsql_alter_database_failed",
    IBP_MCE_FB40__DSQL_ALTER_DATABASE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1562*/
   (336397314L,
    dsql_create_shadow_failed,
    "dsql_create_shadow_failed",
    IBP_MCE_FB40__DSQL_CREATE_SHADOW_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1563*/
   (336397315L,
    dsql_create_filter_failed,
    "dsql_create_filter_failed",
    IBP_MCE_FB40__DSQL_CREATE_FILTER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1564*/
   (336397316L,
    dsql_create_index_failed,
    "dsql_create_index_failed",
    IBP_MCE_FB40__DSQL_CREATE_INDEX_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1565*/
   (336397317L,
    dsql_create_user_failed,
    "dsql_create_user_failed",
    IBP_MCE_FB40__DSQL_CREATE_USER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1566*/
   (336397318L,
    dsql_alter_user_failed,
    "dsql_alter_user_failed",
    IBP_MCE_FB40__DSQL_ALTER_USER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1567*/
   (336397319L,
    dsql_grant_failed,
    "dsql_grant_failed",
    IBP_MCE_FB40__DSQL_GRANT_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1568*/
   (336397320L,
    dsql_revoke_failed,
    "dsql_revoke_failed",
    IBP_MCE_FB40__DSQL_REVOKE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1569*/
   (336397321L,
    dsql_cte_recursive_aggregate,
    "dsql_cte_recursive_aggregate",
    IBP_MCE_FB40__DSQL_CTE_RECURSIVE_AGGREGATE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1570*/
   (336397322L,
    dsql_mapping_failed,
    "dsql_mapping_failed",
    IBP_MCE_FB40__DSQL_MAPPING_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1571*/
   (336397323L,
    dsql_alter_sequence_failed,
    "dsql_alter_sequence_failed",
    IBP_MCE_FB40__DSQL_ALTER_SEQUENCE_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1572*/
   (336397324L,
    dsql_create_generator_failed,
    "dsql_create_generator_failed",
    IBP_MCE_FB40__DSQL_CREATE_GENERATOR_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1573*/
   (336397325L,
    dsql_set_generator_failed,
    "dsql_set_generator_failed",
    IBP_MCE_FB40__DSQL_SET_GENERATOR_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1574*/
   (336397326L,
    dsql_wlock_simple,
    "dsql_wlock_simple",
    IBP_MCE_FB40__DSQL_WLOCK_SIMPLE,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1575*/
   (336397327L,
    dsql_firstskip_rows,
    "dsql_firstskip_rows",
    IBP_MCE_FB40__DSQL_FIRSTSKIP_ROWS,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1576*/
   (336397328L,
    dsql_wlock_aggregates,
    "dsql_wlock_aggregates",
    IBP_MCE_FB40__DSQL_WLOCK_AGGREGATES,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1577*/
   (336397329L,
    dsql_wlock_conflict,
    "dsql_wlock_conflict",
    IBP_MCE_FB40__DSQL_WLOCK_CONFLICT,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1578*/
   (336397330L,
    dsql_max_exception_arguments,
    "dsql_max_exception_arguments",
    IBP_MCE_FB40__DSQL_MAX_EXCEPTION_ARGUMENTS,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1579*/
   (336397331L,
    dsql_string_byte_length,
    "dsql_string_byte_length",
    IBP_MCE_FB40__DSQL_STRING_BYTE_LENGTH,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1580*/
   (336397332L,
    dsql_string_char_length,
    "dsql_string_char_length",
    IBP_MCE_FB40__DSQL_STRING_CHAR_LENGTH,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1581*/
   (336397333L,
    dsql_max_nesting,
    "dsql_max_nesting",
    IBP_MCE_FB40__DSQL_MAX_NESTING,
    IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1582*/
   (336397334L,
    dsql_recreate_user_failed,
    "dsql_recreate_user_failed",
    IBP_MCE_FB40__DSQL_RECREATE_USER_FAILED,
    IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1583*/
   (336461924L,
    IBP_MCE_FB40__INTERNAL_MSG_336461924,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1584*/
   (336461925L,
    IBP_MCE_FB40__INTERNAL_MSG_336461925,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1585*/
   (336462125L,
    IBP_MCE_FB40__INTERNAL_MSG_336462125,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1586*/
   (336462436L,
    IBP_MCE_FB40__INTERNAL_MSG_336462436,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1587*/
   (336527507L,
    IBP_MCE_FB40__INTERNAL_MSG_336527507,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1588*/
   (336527508L,
    IBP_MCE_FB40__INTERNAL_MSG_336527508,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1589*/
   (336527509L,
    IBP_MCE_FB40__INTERNAL_MSG_336527509,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1590*/
   (336527510L,
    IBP_MCE_FB40__INTERNAL_MSG_336527510,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1591*/
   (336527511L,
    IBP_MCE_FB40__INTERNAL_MSG_336527511,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1592*/
   (336527512L,
    IBP_MCE_FB40__INTERNAL_MSG_336527512,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1593*/
   (336527513L,
    IBP_MCE_FB40__INTERNAL_MSG_336527513,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1594*/
   (336527514L,
    IBP_MCE_FB40__INTERNAL_MSG_336527514,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1595*/
   (336527515L,
    IBP_MCE_FB40__INTERNAL_MSG_336527515,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1596*/
   (336527516L,
    IBP_MCE_FB40__INTERNAL_MSG_336527516,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1597*/
   (336527517L,
    IBP_MCE_FB40__INTERNAL_MSG_336527517,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1598*/
   (336527518L,
    IBP_MCE_FB40__INTERNAL_MSG_336527518,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1599*/
   (336527519L,
    IBP_MCE_FB40__INTERNAL_MSG_336527519,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1600*/
   (336527520L,
    IBP_MCE_FB40__INTERNAL_MSG_336527520,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1601*/
   (336527521L,
    IBP_MCE_FB40__INTERNAL_MSG_336527521,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1602*/
   (336527522L,
    IBP_MCE_FB40__INTERNAL_MSG_336527522,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1603*/
   (336527523L,
    IBP_MCE_FB40__INTERNAL_MSG_336527523,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1604*/
   (336527524L,
    IBP_MCE_FB40__INTERNAL_MSG_336527524,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1605*/
   (336527525L,
    IBP_MCE_FB40__INTERNAL_MSG_336527525,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1606*/
   (336527526L,
    IBP_MCE_FB40__INTERNAL_MSG_336527526,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1607*/
   (336527527L,
    IBP_MCE_FB40__INTERNAL_MSG_336527527,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1608*/
   (336527528L,
    IBP_MCE_FB40__INTERNAL_MSG_336527528,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1609*/
   (336527529L,
    IBP_MCE_FB40__INTERNAL_MSG_336527529,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1610*/
   (336527530L,
    IBP_MCE_FB40__INTERNAL_MSG_336527530,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1611*/
   (336527531L,
    IBP_MCE_FB40__INTERNAL_MSG_336527531,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1612*/
   (336527532L,
    IBP_MCE_FB40__INTERNAL_MSG_336527532,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1613*/
   (336527533L,
    IBP_MCE_FB40__INTERNAL_MSG_336527533,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1614*/
   (336527534L,
    IBP_MCE_FB40__INTERNAL_MSG_336527534,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1615*/
   (336527535L,
    IBP_MCE_FB40__INTERNAL_MSG_336527535,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1616*/
   (336527536L,
    IBP_MCE_FB40__INTERNAL_MSG_336527536,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1617*/
   (336527537L,
    IBP_MCE_FB40__INTERNAL_MSG_336527537,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1618*/
   (336527538L,
    IBP_MCE_FB40__INTERNAL_MSG_336527538,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1619*/
   (336527539L,
    IBP_MCE_FB40__INTERNAL_MSG_336527539,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1620*/
   (336527540L,
    IBP_MCE_FB40__INTERNAL_MSG_336527540,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1621*/
   (336527541L,
    IBP_MCE_FB40__INTERNAL_MSG_336527541,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1622*/
   (336527542L,
    IBP_MCE_FB40__INTERNAL_MSG_336527542,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1623*/
   (336527543L,
    IBP_MCE_FB40__INTERNAL_MSG_336527543,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1624*/
   (336527544L,
    IBP_MCE_FB40__INTERNAL_MSG_336527544,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1625*/
   (336527545L,
    IBP_MCE_FB40__INTERNAL_MSG_336527545,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1626*/
   (336527546L,
    IBP_MCE_FB40__INTERNAL_MSG_336527546,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1627*/
   (336527547L,
    IBP_MCE_FB40__INTERNAL_MSG_336527547,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1628*/
   (336527548L,
    IBP_MCE_FB40__INTERNAL_MSG_336527548,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1629*/
   (336527549L,
    IBP_MCE_FB40__INTERNAL_MSG_336527549,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1630*/
   (336527550L,
    IBP_MCE_FB40__INTERNAL_MSG_336527550,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1631*/
   (336527551L,
    IBP_MCE_FB40__INTERNAL_MSG_336527551,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1632*/
   (336527552L,
    IBP_MCE_FB40__INTERNAL_MSG_336527552,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1633*/
   (336527553L,
    IBP_MCE_FB40__INTERNAL_MSG_336527553,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1634*/
   (336527554L,
    IBP_MCE_FB40__INTERNAL_MSG_336527554,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1635*/
   (336527555L,
    IBP_MCE_FB40__INTERNAL_MSG_336527555,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1636*/
   (336527556L,
    IBP_MCE_FB40__INTERNAL_MSG_336527556,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1637*/
   (336527557L,
    IBP_MCE_FB40__INTERNAL_MSG_336527557,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1638*/
   (336527558L,
    IBP_MCE_FB40__INTERNAL_MSG_336527558,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1639*/
   (336527559L,
    IBP_MCE_FB40__INTERNAL_MSG_336527559,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1640*/
   (336527560L,
    IBP_MCE_FB40__INTERNAL_MSG_336527560,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1641*/
   (336527561L,
    IBP_MCE_FB40__INTERNAL_MSG_336527561,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1642*/
   (336527562L,
    IBP_MCE_FB40__INTERNAL_MSG_336527562,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1643*/
   (336527563L,
    IBP_MCE_FB40__INTERNAL_MSG_336527563,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1644*/
   (336527564L,
    IBP_MCE_FB40__INTERNAL_MSG_336527564,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1645*/
   (336527565L,
    IBP_MCE_FB40__INTERNAL_MSG_336527565,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1646*/
   (336527566L,
    IBP_MCE_FB40__INTERNAL_MSG_336527566,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1647*/
   (336527567L,
    IBP_MCE_FB40__INTERNAL_MSG_336527567,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1648*/
   (336527568L,
    IBP_MCE_FB40__INTERNAL_MSG_336527568,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1649*/
   (336527569L,
    IBP_MCE_FB40__INTERNAL_MSG_336527569,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1650*/
   (336527570L,
    IBP_MCE_FB40__INTERNAL_MSG_336527570,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1651*/
   (336527571L,
    IBP_MCE_FB40__INTERNAL_MSG_336527571,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1652*/
   (336527572L,
    IBP_MCE_FB40__INTERNAL_MSG_336527572,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1653*/
   (336527573L,
    IBP_MCE_FB40__INTERNAL_MSG_336527573,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1654*/
   (336527574L,
    IBP_MCE_FB40__INTERNAL_MSG_336527574,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1655*/
   (336527575L,
    IBP_MCE_FB40__INTERNAL_MSG_336527575,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1656*/
   (336527576L,
    IBP_MCE_FB40__INTERNAL_MSG_336527576,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1657*/
   (336527577L,
    IBP_MCE_FB40__INTERNAL_MSG_336527577,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1658*/
   (336527578L,
    IBP_MCE_FB40__INTERNAL_MSG_336527578,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1659*/
   (336527579L,
    IBP_MCE_FB40__INTERNAL_MSG_336527579,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1660*/
   (336527580L,
    IBP_MCE_FB40__INTERNAL_MSG_336527580,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1661*/
   (336527581L,
    IBP_MCE_FB40__INTERNAL_MSG_336527581,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1662*/
   (336527582L,
    IBP_MCE_FB40__INTERNAL_MSG_336527582,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1663*/
   (336527583L,
    IBP_MCE_FB40__INTERNAL_MSG_336527583,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1664*/
   (336527584L,
    IBP_MCE_FB40__INTERNAL_MSG_336527584,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1665*/
   (336527585L,
    IBP_MCE_FB40__INTERNAL_MSG_336527585,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1666*/
   (336527586L,
    IBP_MCE_FB40__INTERNAL_MSG_336527586,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1667*/
   (336527587L,
    IBP_MCE_FB40__INTERNAL_MSG_336527587,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1668*/
   (336527588L,
    IBP_MCE_FB40__INTERNAL_MSG_336527588,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1669*/
   (336527589L,
    IBP_MCE_FB40__INTERNAL_MSG_336527589,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1670*/
   (336527590L,
    IBP_MCE_FB40__INTERNAL_MSG_336527590,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1671*/
   (336527591L,
    IBP_MCE_FB40__INTERNAL_MSG_336527591,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1672*/
   (336527592L,
    IBP_MCE_FB40__INTERNAL_MSG_336527592,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1673*/
   (336527593L,
    IBP_MCE_FB40__INTERNAL_MSG_336527593,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1674*/
   (336527594L,
    IBP_MCE_FB40__INTERNAL_MSG_336527594,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1675*/
   (336527595L,
    IBP_MCE_FB40__INTERNAL_MSG_336527595,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1676*/
   (336527596L,
    IBP_MCE_FB40__INTERNAL_MSG_336527596,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1677*/
   (336527597L,
    IBP_MCE_FB40__INTERNAL_MSG_336527597,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1678*/
   (336527598L,
    IBP_MCE_FB40__INTERNAL_MSG_336527598,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1679*/
   (336527599L,
    IBP_MCE_FB40__INTERNAL_MSG_336527599,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1680*/
   (336527600L,
    IBP_MCE_FB40__INTERNAL_MSG_336527600,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1681*/
   (336527601L,
    IBP_MCE_FB40__INTERNAL_MSG_336527601,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1682*/
   (336527602L,
    IBP_MCE_FB40__INTERNAL_MSG_336527602,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1683*/
   (336527603L,
    IBP_MCE_FB40__INTERNAL_MSG_336527603,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1684*/
   (336527604L,
    IBP_MCE_FB40__INTERNAL_MSG_336527604,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1685*/
   (336527605L,
    IBP_MCE_FB40__INTERNAL_MSG_336527605,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1686*/
   (336527606L,
    IBP_MCE_FB40__INTERNAL_MSG_336527606,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1687*/
   (336527607L,
    IBP_MCE_FB40__INTERNAL_MSG_336527607,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1688*/
   (336527608L,
    IBP_MCE_FB40__INTERNAL_MSG_336527608,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1689*/
   (336527609L,
    IBP_MCE_FB40__INTERNAL_MSG_336527609,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1690*/
   (336527610L,
    IBP_MCE_FB40__INTERNAL_MSG_336527610,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1691*/
   (336527611L,
    IBP_MCE_FB40__INTERNAL_MSG_336527611,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1692*/
   (336527612L,
    IBP_MCE_FB40__INTERNAL_MSG_336527612,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1693*/
   (336527613L,
    IBP_MCE_FB40__INTERNAL_MSG_336527613,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1694*/
   (336527614L,
    IBP_MCE_FB40__INTERNAL_MSG_336527614,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1695*/
   (336527615L,
    IBP_MCE_FB40__INTERNAL_MSG_336527615,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1696*/
   (336527616L,
    IBP_MCE_FB40__INTERNAL_MSG_336527616,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1697*/
   (336527617L,
    IBP_MCE_FB40__INTERNAL_MSG_336527617,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1698*/
   (336527618L,
    IBP_MCE_FB40__INTERNAL_MSG_336527618,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1699*/
   (336527619L,
    IBP_MCE_FB40__INTERNAL_MSG_336527619,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1700*/
   (336527620L,
    IBP_MCE_FB40__INTERNAL_MSG_336527620,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1701*/
   (336527621L,
    IBP_MCE_FB40__INTERNAL_MSG_336527621,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1702*/
   (336527622L,
    IBP_MCE_FB40__INTERNAL_MSG_336527622,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1703*/
   (336527623L,
    IBP_MCE_FB40__INTERNAL_MSG_336527623,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1704*/
   (336527624L,
    IBP_MCE_FB40__INTERNAL_MSG_336527624,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1705*/
   (336527625L,
    IBP_MCE_FB40__INTERNAL_MSG_336527625,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1706*/
   (336527626L,
    IBP_MCE_FB40__INTERNAL_MSG_336527626,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1707*/
   (336527627L,
    IBP_MCE_FB40__INTERNAL_MSG_336527627,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1708*/
   (336527628L,
    IBP_MCE_FB40__INTERNAL_MSG_336527628,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1709*/
   (336527629L,
    IBP_MCE_FB40__INTERNAL_MSG_336527629,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1710*/
   (336527630L,
    IBP_MCE_FB40__INTERNAL_MSG_336527630,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1711*/
   (336527631L,
    IBP_MCE_FB40__INTERNAL_MSG_336527631,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1712*/
   (336527632L,
    IBP_MCE_FB40__INTERNAL_MSG_336527632,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1713*/
   (336527633L,
    IBP_MCE_FB40__INTERNAL_MSG_336527633,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1714*/
   (336527634L,
    IBP_MCE_FB40__INTERNAL_MSG_336527634,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1715*/
   (336527635L,
    IBP_MCE_FB40__INTERNAL_MSG_336527635,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1716*/
   (336527636L,
    IBP_MCE_FB40__INTERNAL_MSG_336527636,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1717*/
   (336527637L,
    IBP_MCE_FB40__INTERNAL_MSG_336527637,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1718*/
   (336527638L,
    IBP_MCE_FB40__INTERNAL_MSG_336527638,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1719*/
   (336527639L,
    IBP_MCE_FB40__INTERNAL_MSG_336527639,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1720*/
   (336527640L,
    IBP_MCE_FB40__INTERNAL_MSG_336527640,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1721*/
   (336527641L,
    IBP_MCE_FB40__INTERNAL_MSG_336527641,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1722*/
   (336527642L,
    IBP_MCE_FB40__INTERNAL_MSG_336527642,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1723*/
   (336527643L,
    IBP_MCE_FB40__INTERNAL_MSG_336527643,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1724*/
   (336527644L,
    IBP_MCE_FB40__INTERNAL_MSG_336527644,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1725*/
   (336527645L,
    IBP_MCE_FB40__INTERNAL_MSG_336527645,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1726*/
   (336527646L,
    IBP_MCE_FB40__INTERNAL_MSG_336527646,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1727*/
   (336527647L,
    IBP_MCE_FB40__INTERNAL_MSG_336527647,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1728*/
   (336527648L,
    IBP_MCE_FB40__INTERNAL_MSG_336527648,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1729*/
   (336527649L,
    IBP_MCE_FB40__INTERNAL_MSG_336527649,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1730*/
   (336527650L,
    savepoint_error,
    "savepoint_error",
    IBP_MCE_FB40__SAVEPOINT_ERROR,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1731*/
   (336527651L,
    IBP_MCE_FB40__INTERNAL_MSG_336527651,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1732*/
   (336527652L,
    IBP_MCE_FB40__INTERNAL_MSG_336527652,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1733*/
   (336527653L,
    IBP_MCE_FB40__INTERNAL_MSG_336527653,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1734*/
   (336527654L,
    IBP_MCE_FB40__INTERNAL_MSG_336527654,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1735*/
   (336527655L,
    IBP_MCE_FB40__INTERNAL_MSG_336527655,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1736*/
   (336527656L,
    IBP_MCE_FB40__INTERNAL_MSG_336527656,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1737*/
   (336527657L,
    IBP_MCE_FB40__INTERNAL_MSG_336527657,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1738*/
   (336527658L,
    IBP_MCE_FB40__INTERNAL_MSG_336527658,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1739*/
   (336527659L,
    IBP_MCE_FB40__INTERNAL_MSG_336527659,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1740*/
   (336527660L,
    IBP_MCE_FB40__INTERNAL_MSG_336527660,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1741*/
   (336527661L,
    cache_non_zero_use_count,
    "cache_non_zero_use_count",
    IBP_MCE_FB40__CACHE_NON_ZERO_USE_COUNT,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1742*/
   (336527662L,
    unexpected_page_change,
    "unexpected_page_change",
    IBP_MCE_FB40__UNEXPECTED_PAGE_CHANGE,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1743*/
   (336527663L,
    IBP_MCE_FB40__INTERNAL_MSG_336527663,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE         /*1744*/
   (336527664L,
    rdb_triggers_rdb_flags_corrupt,
    "rdb$triggers_rdb$flags_corrupt",
    IBP_MCE_FB40__RDB_TRIGGERS_RDB_FLAGS_CORRUPT,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1745*/
   (336527665L,
    IBP_MCE_FB40__INTERNAL_MSG_336527665,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
 ADD_CODE__NONAME /*1746*/
   (336527666L,
    IBP_MCE_FB40__INTERNAL_MSG_336527666,
    nullptr /*no sqlstate*/,
    NO_OLEDB_ERR_CODE)
};//g_fb_v04_0_0__error_descrs2

////////////////////////////////////////////////////////////////////////////////

#undef ADD_CODE
#undef NO_OLEDB_ERR_CODE
#undef MAKE_SQLSTATE

#undef CHECK_AND_RETURN_ISC_CODE

////////////////////////////////////////////////////////////////////////////////
#ifndef NDEBUG
////////////////////////////////////////////////////////////////////////////////

static void check__g_fb_err_codes()
{
 isc_base::debug__check_isc_error_code_descr2_array
  ("g_fb_v04_0_0__error_descrs2",
   _DIM_(g_fb_v04_0_0__error_descrs2),
   g_fb_v04_0_0__error_descrs2);

 for(size_t i=0;i!=_DIM_(g_fb_v04_0_0__error_descrs2);++i)
 {
  assert(g_fb_v04_0_0__error_descrs2[i].message_id!=IDENTIFIER_SDK_ERROR);
 }
}//check__g_fb_err_codes

STARTUP_CODE__DEBUG(check__g_fb_err_codes)

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms v04_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
