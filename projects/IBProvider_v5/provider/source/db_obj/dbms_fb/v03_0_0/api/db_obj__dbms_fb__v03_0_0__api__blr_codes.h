////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v03_0_0__api
//! \file    db_obj__dbms_fb__v03_0_0__api__blr_codes.h
//! \brief   Список BLR-кодов Firebird 3.0.
//! \author  Kovalenko Dmitry
//! \date    12.10.2016
#ifndef _db_obj__dbms_fb__v03_0_0__api__blr_codes_H_
#define _db_obj__dbms_fb__v03_0_0__api__blr_codes_H_

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v03_0_0{namespace api{
////////////////////////////////////////////////////////////////////////////////
//struct fb_v03_0_0__blr_code

struct fb_v03_0_0__blr_code
{
 public:
  typedef unsigned char     code1_type;
  typedef unsigned short    code2_type;

 public:
  static const code1_type c_text                                = 14;
  static const code1_type c_text2                               = 15;  /* added in 3.2 JPN */
  static const code1_type c_short                               = 7;
  static const code1_type c_long                                = 8;
  static const code1_type c_quad                                = 9;
  static const code1_type c_float                               = 10;
  static const code1_type c_double                              = 27;
  static const code1_type c_d_float                             = 11;
  static const code1_type c_timestamp                           = 35;
  static const code1_type c_varying                             = 37;
  static const code1_type c_varying2                            = 38;  /* added in 3.2 JPN */
  static const code2_type c_blob                                = 261;
  static const code1_type c_cstring                             = 40;
  static const code1_type c_cstring2                            = 41;  /* added in 3.2 JPN */
  static const code1_type c_blob_id                             = 45;  /* added from gds.h */
  static const code1_type c_sql_date                            = 12;
  static const code1_type c_sql_time                            = 13;
  static const code1_type c_int64                               = 16;
  static const code1_type c_blob2                               = 17;
  static const code1_type c_domain_name                         = 18;
  static const code1_type c_domain_name2                        = 19;
  static const code1_type c_not_nullable                        = 20;
  static const code1_type c_column_name                         = 21;
  static const code1_type c_column_name2                        = 22;
  static const code1_type c_bool                                = 23;

  // first sub parameter for blr_domain_name[2]
  static const code1_type c_domain_type_of                      = 0;
  static const code1_type c_domain_full                         = 1;

  /* Historical alias for pre V6 applications */
  static const code1_type c_date                                = c_timestamp

  static const code1_type c_inner                               = 0;
  static const code1_type c_left                                = 1;
  static const code1_type c_right                               = 2;
  static const code1_type c_full                                = 3;

  static const code1_type c_gds_code                            = 0;
  static const code1_type c_sql_code                            = 1;
  static const code1_type c_exception                           = 2;
  static const code1_type c_trigger_code                        = 3;
  static const code1_type c_default_code                        = 4;
  static const code1_type c_raise                               = 5;
  static const code1_type c_exception_msg                       = 6;
  static const code1_type c_exception_params                    = 7;
  static const code1_type c_sql_state                           = 8;

  static const code1_type c_version4                            = 4;
  static const code1_type c_version5                            = 5;
  //  static const code1_type c_version6                        = 6;
  static const code1_type c_eoc                                 = 76;
  static const code1_type c_end                                 = 255;

  static const code1_type c_assignment                          = 1;
  static const code1_type c_begin                               = 2;
  static const code1_type c_dcl_variable                        = 3;  /* added from gds.h */
  static const code1_type c_message                             = 4;
  static const code1_type c_erase                               = 5;
  static const code1_type c_fetch                               = 6;
  static const code1_type c_for                                 = 7;
  static const code1_type c_if                                  = 8;
  static const code1_type c_loop                                = 9;
  static const code1_type c_modify                              = 10;
  static const code1_type c_handler                             = 11;
  static const code1_type c_receive                             = 12;
  static const code1_type c_select                              = 13;
  static const code1_type c_send                                = 14;
  static const code1_type c_store                               = 15;
  static const code1_type c_label                               = 17;
  static const code1_type c_leave                               = 18;
  static const code1_type c_store2                              = 19;
  static const code1_type c_post                                = 20;
  static const code1_type c_literal                             = 21;
  static const code1_type c_dbkey                               = 22;
  static const code1_type c_field                               = 23;
  static const code1_type c_fid                                 = 24;
  static const code1_type c_parameter                           = 25;
  static const code1_type c_variable                            = 26;
  static const code1_type c_average                             = 27;
  static const code1_type c_count                               = 28;
  static const code1_type c_maximum                             = 29;
  static const code1_type c_minimum                             = 30;
  static const code1_type c_total                               = 31;

  // unused codes: 32..33

  static const code1_type c_add                                 = 34;
  static const code1_type c_subtract                            = 35;
  static const code1_type c_multiply                            = 36;
  static const code1_type c_divide                              = 37;
  static const code1_type c_negate                              = 38;
  static const code1_type c_concatenate                         = 39;
  static const code1_type c_substring                           = 40;
  static const code1_type c_parameter2                          = 41;
  static const code1_type c_from                                = 42;
  static const code1_type c_via                                 = 43;
  static const code1_type c_user_name                           = 44; /* added from gds.h */
  static const code1_type c_null                                = 45;

  static const code1_type c_equiv                               = 46;
  static const code1_type c_eql                                 = 47;
  static const code1_type c_neq                                 = 48;
  static const code1_type c_gtr                                 = 49;
  static const code1_type c_geq                                 = 50;
  static const code1_type c_lss                                 = 51;
  static const code1_type c_leq                                 = 52;
  static const code1_type c_containing                          = 53;
  static const code1_type c_matching                            = 54;
  static const code1_type c_starting                            = 55;
  static const code1_type c_between                             = 56;
  static const code1_type c_or                                  = 57;
  static const code1_type c_and                                 = 58;
  static const code1_type c_not                                 = 59;
  static const code1_type c_any                                 = 60;
  static const code1_type c_missing                             = 61;
  static const code1_type c_unique                              = 62;
  static const code1_type c_like                                = 63;

  // unused codes: 64..66

  static const code1_type c_rse                                 = 67;
  static const code1_type c_first                               = 68;
  static const code1_type c_project                             = 69;
  static const code1_type c_sort                                = 70;
  static const code1_type c_boolean                             = 71;
  static const code1_type c_ascending                           = 72;
  static const code1_type c_descending                          = 73;
  static const code1_type c_relation                            = 74;
  static const code1_type c_rid                                 = 75;
  static const code1_type c_union                               = 76;
  static const code1_type c_map                                 = 77;
  static const code1_type c_group_by                            = 78;
  static const code1_type c_aggregate                           = 79;
  static const code1_type c_join_type                           = 80;

  // unused codes: 81..82

  static const code1_type c_agg_count                           = 83;
  static const code1_type c_agg_max                             = 84;
  static const code1_type c_agg_min                             = 85;
  static const code1_type c_agg_total                           = 86;
  static const code1_type c_agg_average                         = 87;
  static const code1_type c_parameter3                          = 88; /* same as Rdb definition */
  //unsupported
  //static const code1_type c_run_max                           = 89;
  //static const code1_type c_run_min                           = 90;
  //static const code1_type c_run_total                         = 91;
  //static const code1_type c_run_average                       = 92;
  static const code1_type c_agg_count2                          = 93;
  static const code1_type c_agg_count_distinct                  = 94;
  static const code1_type c_agg_total_distinct                  = 95;
  static const code1_type c_agg_average_distinct                = 96;

  // unused codes: 97..99

  static const code1_type c_function                            = 100;
  static const code1_type c_gen_id                              = 101;
  //static const code_type c_prot_mask                          = 102;
  static const code1_type c_upcase                              = 103;
  //static const code1_type c_lock_state                        = 104;
  static const code1_type c_value_if                            = 105;
  static const code1_type c_matching2                           = 106;
  static const code1_type c_index                               = 107;
  static const code1_type c_ansi_like                           = 108;
  static const code1_type c_scrollable                          = 109;

  // unused codes: 110..117

  static const code1_type c_run_count                           = 118;  /* changed from 88 to avoid conflict with blr_parameter3 */
  static const code1_type c_rs_stream                           = 119;
  static const code1_type c_exec_proc                           = 120;

  // unused codes: 121..123

  static const code1_type c_procedure                           = 124;
  static const code1_type c_pid                                 = 125;
  static const code1_type c_exec_pid                            = 126;
  static const code1_type c_singular                            = 127;
  static const code1_type c_abort                               = 128;
  static const code1_type c_block                               = 129;
  static const code1_type c_error_handler                       = 130;

  static const code1_type c_cast                                = 131;

  static const code1_type c_pid2                                = 132;
  static const code1_type c_procedure2                          = 133;

  static const code1_type c_start_savepoint                     = 134;
  static const code1_type c_end_savepoint                       = 135;

  // unused codes: 136..138

  static const code1_type c_plan                                = 139;  /* access plan items */
  static const code1_type c_merge                               = 140;
  static const code1_type c_join                                = 141;
  static const code1_type c_sequential                          = 142;
  static const code1_type c_navigational                        = 143;
  static const code1_type c_indices                             = 144;
  static const code1_type c_retrieve                            = 145;

  static const code1_type c_relation2                           = 146;
  static const code1_type c_rid2                                = 147;

  // unused codes: 148..149

  static const code1_type c_set_generator                       = 150;

  static const code1_type c_ansi_any                            = 151;  /* required for NULL handling */
  static const code1_type c_exists                              = 152;  /* required for NULL handling */

  // unused codes: 153

  static const code1_type c_record_version                      = 154;  /* get tid of record */
  static const code1_type c_stall                               = 155;  /* fake server stall */

  // unused codes: 156..157

  static const code1_type c_ansi_all                            = 158;  /* required for NULL handling */

  static const code1_type c_extract                             = 159;

  /* sub parameters for blr_extract */

  static const code1_type c_extract_year                        = 0;
  static const code1_type c_extract_month                       = 1;
  static const code1_type c_extract_day                         = 2;
  static const code1_type c_extract_hour                        = 3;
  static const code1_type c_extract_minute                      = 4;
  static const code1_type c_extract_second                      = 5;
  static const code1_type c_extract_weekday                     = 6;
  static const code1_type c_extract_yearday                     = 7;
  static const code1_type c_extract_millisecond                 = 8;
  static const code1_type c_extract_week                        = 9;

  static const code1_type c_current_date                        = 160;
  static const code1_type c_current_timestamp                   = 161;
  static const code1_type c_current_time                        = 162;

  /* These codes reuse BLR code space */

  static const code1_type c_post_arg                            = 163;
  static const code1_type c_exec_into                           = 164;
  static const code1_type c_user_savepoint                      = 165;
  static const code1_type c_dcl_cursor                          = 166;
  static const code1_type c_cursor_stmt                         = 167;
  static const code1_type c_current_timestamp2                  = 168;
  static const code1_type c_current_time2                       = 169;
  static const code1_type c_agg_list                            = 170;
  static const code1_type c_agg_list_distinct                   = 171;
  static const code1_type c_modify2                             = 172;

  // unused codes: 173

  /* FB 1.0 specific BLR */

  static const code1_type c_current_role                        = 174;
  static const code1_type c_skip                                = 175;

  /* FB 1.5 specific BLR */

  static const code1_type c_exec_sql                            = 176;
  static const code1_type c_internal_info                       = 177;
  static const code1_type c_nullsfirst                          = 178;
  static const code1_type c_writelock                           = 179;
  static const code1_type c_nullslast                           = 180;

  /* FB 2.0 specific BLR */

  static const code1_type c_lowcase                             = 181;
  static const code1_type c_strlen                              = 182;

  /* sub parameter for blr_strlen */
  static const code1_type c_strlen_bit                          = 0;
  static const code1_type c_strlen_char                         = 1;
  static const code1_type c_strlen_octet                        = 2;

  static const code1_type c_trim                                = 183;

  /* first sub parameter for blr_trim */
  static const code1_type c_trim_both                           = 0;
  static const code1_type c_trim_leading                        = 1;
  static const code1_type c_trim_trailing                       = 2;

  /* second sub parameter for blr_trim */
  static const code1_type c_trim_spaces                         = 0;
  static const code1_type c_trim_characters                     = 1;

  /* These codes are actions for user-defined savepoints */

  static const code1_type c_savepoint_set                       = 0;
  static const code1_type c_savepoint_release                   = 1;
  static const code1_type c_savepoint_undo                      = 2;
  static const code1_type c_savepoint_release_single            = 3;

  /* These codes are actions for cursors */

  static const code1_type c_cursor_open                         = 0;
  static const code1_type c_cursor_close                        = 1;
  static const code1_type c_cursor_fetch                        = 2;
  static const code1_type c_cursor_fetch_scroll                 = 3;

  /* scroll options */

  static const code1_type c_scroll_forward                      = 0;
  static const code1_type c_scroll_backward                     = 1;
  static const code1_type c_scroll_bof                          = 2;
  static const code1_type c_scroll_eof                          = 3;
  static const code1_type c_scroll_absolute                     = 4;
  static const code1_type c_scroll_relative                     = 5;

  /* FB 2.1 specific BLR */

  static const code1_type c_init_variable                       = 184;
  static const code1_type c_recurse                             = 185;
  static const code1_type c_sys_function                        = 186;

  // FB 2.5 specific BLR

  static const code1_type c_auto_trans                          = 187;
  static const code1_type c_similar                             = 188;
  static const code1_type c_exec_stmt                           = 189;

// subcodes of blr_exec_stmt
  static const code1_type c_exec_stmt_inputs                    = 1;  // input parameters count
  static const code1_type c_exec_stmt_outputs                   = 2;  // output parameters count
  static const code1_type c_exec_stmt_sql                       = 3;
  static const code1_type c_exec_stmt_proc_block                = 4;
  static const code1_type c_exec_stmt_data_src                  = 5;
  static const code1_type c_exec_stmt_user                      = 6;
  static const code1_type c_exec_stmt_pwd                       = 7;
  static const code1_type c_exec_stmt_tran                      = 8;  // not implemented yet
  static const code1_type c_exec_stmt_tran_clone                = 9;  // make transaction parameters equal to current transaction
  static const code1_type c_exec_stmt_privs                     = 10;
  static const code1_type c_exec_stmt_in_params                 = 11; // not named input parameters
  static const code1_type c_exec_stmt_in_params2                = 12; // named input parameters
  static const code1_type c_exec_stmt_out_params                = 13; // output parameters
  static const code1_type c_exec_stmt_role                      = 14;

  static const code1_type c_stmt_expr                           = 190;
  static const code1_type c_derived_expr                        = 191;

  // FB 3.0 specific BLR

  static const code1_type c_procedure3                          = 192;
  static const code1_type c_exec_proc2                          = 193;
  static const code1_type c_function2                           = 194;
  static const code1_type c_window                              = 195;
  static const code1_type c_partition_by                        = 196;
  static const code1_type c_continue_loop                       = 197;
  static const code1_type c_procedure4                          = 198;
  static const code1_type c_agg_function                        = 199;
  static const code1_type c_substring_similar                   = 200;
  static const code1_type c_bool_as_value                       = 201;
  static const code1_type c_coalesce                            = 202;
  static const code1_type c_decode                              = 203;
  static const code1_type c_exec_subproc                        = 204;
  static const code1_type c_subproc_decl                        = 205;
  static const code1_type c_subproc                             = 206;
  static const code1_type c_subfunc_decl                        = 207;
  static const code1_type c_subfunc                             = 208;
  static const code1_type c_record_version2                     = 209;
  static const code1_type c_gen_id2                             = 210; // NEXT VALUE FOR generator
};//struct fb_v03_0_0__blr_code

////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms v03_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif