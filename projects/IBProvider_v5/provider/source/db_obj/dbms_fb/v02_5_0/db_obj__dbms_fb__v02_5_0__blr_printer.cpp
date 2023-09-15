////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v02_5_0
//! \file    db_obj__dbms_fb__v02_5_0__blr_printer.cpp
//! \brief   Принтер BLR-кода Firebird 2.5.
//! \author  Kovalenko Dmitry
//! \date    20.11.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/v02_5_0/db_obj__dbms_fb__v02_5_0__blr_printer.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error.h"

#include <structure/utilities/string/trim.h>
#include <structure/utilities/string/string_length.h>
#include <structure/t_value_with_null.h>

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v02_5_0{
////////////////////////////////////////////////////////////////////////////////
//PRINT FORMATS

const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_zero[]
  = { op_line, 0 };

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_one[]
  = { op_line, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_two[]
  = { op_line, op_verb, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_three[]
  = { op_line, op_verb, op_verb, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_field[]
  = { op_byte, op_byte, op_literal, op_pad, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_byte_line[]
  = { op_byte, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_byte_args[]
  = { op_byte, op_line, op_args, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_byte_verb[]
  = { op_byte, op_line, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_byte_verb_verb[]
  = { op_byte, op_line, op_verb, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_byte_literal[]
  = { op_byte, op_literal, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_byte_byte_verb[]
  = { op_byte, op_byte, op_line, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_parm[]
  = { op_byte, op_word, op_line, 0};  /* also field id */

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_parm2[]
  = { op_byte, op_word, op_word, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_parm3[]
  = { op_byte, op_word, op_word, op_word, op_line, 0};

//------------------------------------------------------------------------
/* formats specific to a verb */

const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_begin[]
  = { op_line, op_begin, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_literal[]
  = { op_dtype, op_literal, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_message[]
  = { op_byte, op_word, op_line, op_message, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_rse[]
  = { op_byte, op_line, op_begin, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_relation[]
  = { op_byte, op_literal, op_pad, op_byte, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_relation2[]
  = { op_byte, op_literal, op_line, op_indent, op_byte, op_literal, op_pad, op_byte, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_aggregate[]
  = { op_byte, op_line, op_verb, op_verb, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_rid[]
  = { op_word, op_byte, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_rid2[]
  = { op_word, op_byte, op_literal, op_pad, op_byte, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_union_ops[]
  = { op_byte, op_byte, op_line, op_union, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_map[]
  = { op_word, op_line, op_map, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_function[]
  = { op_byte, op_literal, op_byte, op_line, op_args, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_gen_id[]
  = { op_byte, op_literal, op_line, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_declare[]
  = { op_word, op_dtype, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_variable[]
  = { op_word, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_indx[]
  = { op_line, op_verb, op_indent, op_byte, op_line, op_args, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_seek[]
  = { op_line, op_verb, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_join[]
  = { op_join, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_exec_proc[]
  = { op_byte, op_literal, op_line, op_indent, op_word, op_line, op_parameters, op_indent, op_word, op_line, op_parameters, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_procedure[]
  = { op_byte, op_literal, op_pad, op_byte, op_line, op_indent, op_word, op_line, op_parameters, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_pid[]
  = { op_word, op_pad, op_byte, op_line, op_indent, op_word, op_line, op_parameters, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_error_handler[]
  = { op_word, op_line, op_error_handler, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_set_error[]
  = { op_set_error, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_cast[]
  = { op_dtype, op_line, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_indices[]
  = { op_byte, op_line, op_literals, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_extract[]
  = { op_line, op_byte, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_user_savepoint[]
  = { op_byte, op_byte, op_literal, op_line, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_exec_into[]
  = { op_word, op_line, op_indent, op_exec_into, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_dcl_cursor[]
  = { op_word, op_line, op_verb, op_indent, op_word, op_line, op_args, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_cursor_stmt[]
  = { op_cursor_stmt, 0 };

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_strlength[]
  = { op_byte, op_line, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_trim[]
  = { op_byte, op_byte_opt_verb, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_modify2[]
  = { op_byte, op_byte, op_line, op_verb, op_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_similar[]
  = { op_line, op_verb, op_verb, op_indent, op_byte_opt_verb, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_exec_stmt[]
  = { op_exec_stmt, 0};

//------------------------------------------------------------------------
const fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::sm_pfm_derived_expr[]
  = { op_derived_expr, 0};

////////////////////////////////////////////////////////////////////////////////
//BLR TABLE

#ifndef NDEBUG
#define ADD_BLR_CODE_NONE()                            \
 {                                                     \
  0,                                                   \
  nullptr,                                             \
  nullptr,                                             \
 },

#define ADD_BLR_CODE_DESCR1(code_sign,pfm_sign)        \
 {                                                     \
  blr_code_type::c_##code_sign,                        \
  "blr_" #code_sign ", ",                              \
  sm_pfm_##pfm_sign                                    \
 },

#define ADD_BLR_CODE_DESCR2(code_sign,str,pfm_sign)    \
 {                                                     \
  blr_code_type::c_##code_sign,                        \
  "blr_" str ", ",                                     \
  sm_pfm_##pfm_sign                                    \
 },
#else
#define ADD_BLR_CODE_NONE()                            \
 {                                                     \
  nullptr,                                             \
  nullptr,                                             \
 },

#define ADD_BLR_CODE_DESCR1(code_sign,pfm_sign)        \
 {                                                     \
  "blr_" #code_sign ", ",                              \
  sm_pfm_##pfm_sign                                    \
 },

#define ADD_BLR_CODE_DESCR2(code_sign,str,pfm_sign)    \
 {                                                     \
  "blr_" str ", ",                                     \
  sm_pfm_##pfm_sign                                    \
 },
#endif

const fb_v02_5_0__blr_printer::blr_code_descr_type
 fb_v02_5_0__blr_printer::sm_blr_table[]=
{
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(assignment           , two)
 ADD_BLR_CODE_DESCR1(begin                , begin)
 ADD_BLR_CODE_DESCR2(dcl_variable         , "declare"     , declare)
 ADD_BLR_CODE_DESCR1(message              , message)
 ADD_BLR_CODE_DESCR1(erase                , byte_line)
 ADD_BLR_CODE_DESCR1(fetch                , two)
 ADD_BLR_CODE_DESCR1(for                  , two)
 ADD_BLR_CODE_DESCR1(if                   , three)
 ADD_BLR_CODE_DESCR1(loop                 , one)
 ADD_BLR_CODE_DESCR1(modify               , byte_byte_verb) // 10
 ADD_BLR_CODE_DESCR1(handler              , one)
 ADD_BLR_CODE_DESCR1(receive              , byte_verb)
 ADD_BLR_CODE_DESCR1(select               , begin)
 ADD_BLR_CODE_DESCR1(send                 , byte_verb)
 ADD_BLR_CODE_DESCR1(store                , two)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(label                , byte_verb)
 ADD_BLR_CODE_DESCR1(leave                , byte_line)
 ADD_BLR_CODE_DESCR1(store2               , three)
 ADD_BLR_CODE_DESCR1(post                 , one)    // 20
 ADD_BLR_CODE_DESCR1(literal              , literal)
 ADD_BLR_CODE_DESCR1(dbkey                , byte_line)
 ADD_BLR_CODE_DESCR1(field                , field)
 ADD_BLR_CODE_DESCR1(fid                  , parm)
 ADD_BLR_CODE_DESCR1(parameter            , parm)
 ADD_BLR_CODE_DESCR1(variable             , variable)
 ADD_BLR_CODE_DESCR1(average              , two)
 ADD_BLR_CODE_DESCR1(count                , one)
 ADD_BLR_CODE_DESCR1(maximum              , two)
 ADD_BLR_CODE_DESCR1(minimum              , two)    // 30
 ADD_BLR_CODE_DESCR1(total                , two)
 ADD_BLR_CODE_NONE() // {"count2", two},
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(add                  , two)
 ADD_BLR_CODE_DESCR1(subtract             , two)
 ADD_BLR_CODE_DESCR1(multiply             , two)
 ADD_BLR_CODE_DESCR1(divide               , two)
 ADD_BLR_CODE_DESCR1(negate               , one)
 ADD_BLR_CODE_DESCR1(concatenate          , two)
 ADD_BLR_CODE_DESCR1(substring            , three)  // 40
 ADD_BLR_CODE_DESCR1(parameter2           , parm2)
 ADD_BLR_CODE_DESCR1(from                 , two)
 ADD_BLR_CODE_DESCR1(via                  , three)
 ADD_BLR_CODE_DESCR1(user_name            , zero)
 ADD_BLR_CODE_DESCR1(null                 , zero)
 ADD_BLR_CODE_DESCR1(equiv                , two)
 ADD_BLR_CODE_DESCR1(eql                  , two)
 ADD_BLR_CODE_DESCR1(neq                  , two)
 ADD_BLR_CODE_DESCR1(gtr                  , two)
 ADD_BLR_CODE_DESCR1(geq                  , two)    // 50
 ADD_BLR_CODE_DESCR1(lss                  , two)
 ADD_BLR_CODE_DESCR1(leq                  , two)
 ADD_BLR_CODE_DESCR1(containing           , two)
 ADD_BLR_CODE_DESCR1(matching             , two)
 ADD_BLR_CODE_DESCR1(starting             , two)
 ADD_BLR_CODE_DESCR1(between              , three)
 ADD_BLR_CODE_DESCR1(or                   , two)
 ADD_BLR_CODE_DESCR1(and                  , two)
 ADD_BLR_CODE_DESCR1(not                  , one)
 ADD_BLR_CODE_DESCR1(any                  , one)    // 60
 ADD_BLR_CODE_DESCR1(missing              , one)
 ADD_BLR_CODE_DESCR1(unique               , one)
 ADD_BLR_CODE_DESCR1(like                 , two)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(rse                  , rse)
 ADD_BLR_CODE_DESCR1(first                , one)
 ADD_BLR_CODE_DESCR1(project              , byte_args)
 ADD_BLR_CODE_DESCR1(sort                 , byte_args)  // 70
 ADD_BLR_CODE_DESCR1(boolean              , one)
 ADD_BLR_CODE_DESCR1(ascending            , one)
 ADD_BLR_CODE_DESCR1(descending           , one)
 ADD_BLR_CODE_DESCR1(relation             , relation)
 ADD_BLR_CODE_DESCR1(rid                  , rid)
 ADD_BLR_CODE_DESCR1(union                , union_ops)
 ADD_BLR_CODE_DESCR1(map                  , map)
 ADD_BLR_CODE_DESCR1(group_by             , byte_args)
 ADD_BLR_CODE_DESCR1(aggregate            , aggregate)
 ADD_BLR_CODE_DESCR1(join_type            , join)   // 80
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(agg_count            , zero)
 ADD_BLR_CODE_DESCR1(agg_max              , one)
 ADD_BLR_CODE_DESCR1(agg_min              , one)
 ADD_BLR_CODE_DESCR1(agg_total            , one)
 ADD_BLR_CODE_DESCR1(agg_average          , one)
 ADD_BLR_CODE_DESCR1(parameter3           , parm3)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()    // 90
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(agg_count2           , one)
 ADD_BLR_CODE_DESCR1(agg_count_distinct   , one)
 ADD_BLR_CODE_DESCR1(agg_total_distinct   , one)
 ADD_BLR_CODE_DESCR1(agg_average_distinct , one)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(function             , function)   // 100
 ADD_BLR_CODE_DESCR1(gen_id               , gen_id)
 ADD_BLR_CODE_DESCR1(prot_mask            , two)
 ADD_BLR_CODE_DESCR1(upcase               , one)
 ADD_BLR_CODE_DESCR1(lock_state           , one)
 ADD_BLR_CODE_DESCR1(value_if             , three)
 ADD_BLR_CODE_DESCR1(matching2            , three)
 ADD_BLR_CODE_DESCR1(index                , indx)
 ADD_BLR_CODE_DESCR1(ansi_like            , three)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()    // 110
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(seek                 , seek)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(rs_stream            , rse)
 ADD_BLR_CODE_DESCR1(exec_proc            , exec_proc)  // 120
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(procedure            , procedure)
 ADD_BLR_CODE_DESCR1(pid, pid)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(singular             , one)
 ADD_BLR_CODE_DESCR1(abort                , set_error)
 ADD_BLR_CODE_DESCR1(block                , begin)
 ADD_BLR_CODE_DESCR1(error_handler        , error_handler)  // 130
 ADD_BLR_CODE_DESCR1(cast                 , cast)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(start_savepoint      , zero)
 ADD_BLR_CODE_DESCR1(end_savepoint        , zero)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(plan                 , one)
 ADD_BLR_CODE_DESCR1(merge                , byte_args)  // 140
 ADD_BLR_CODE_DESCR1(join                 , byte_args)
 ADD_BLR_CODE_DESCR1(sequential           , zero)
 ADD_BLR_CODE_DESCR1(navigational         , byte_literal)
 ADD_BLR_CODE_DESCR1(indices              , indices)
 ADD_BLR_CODE_DESCR1(retrieve             , two)
 ADD_BLR_CODE_DESCR1(relation2            , relation2)
 ADD_BLR_CODE_DESCR1(rid2                 , rid2)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(set_generator        , gen_id) // 150
 ADD_BLR_CODE_DESCR1(ansi_any             , one)
 ADD_BLR_CODE_DESCR1(exists               , one)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(record_version       , byte_line)
 ADD_BLR_CODE_DESCR1(stall                , zero)
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_NONE()
 ADD_BLR_CODE_DESCR1(ansi_all             , one)

    // New BLR in 6.0
 ADD_BLR_CODE_DESCR1(extract              , extract)
 ADD_BLR_CODE_DESCR1(current_date         , zero)   // 160
 ADD_BLR_CODE_DESCR1(current_timestamp    , zero)
 ADD_BLR_CODE_DESCR1(current_time         , zero)
 ADD_BLR_CODE_DESCR1(post_arg             , two)
 ADD_BLR_CODE_DESCR1(exec_into            , exec_into)
 ADD_BLR_CODE_DESCR1(user_savepoint       , user_savepoint)
 ADD_BLR_CODE_DESCR1(dcl_cursor           , dcl_cursor)
 ADD_BLR_CODE_DESCR1(cursor_stmt          , cursor_stmt)
 ADD_BLR_CODE_DESCR1(current_timestamp2   , byte_line)
 ADD_BLR_CODE_DESCR1(current_time2        , byte_line)
 ADD_BLR_CODE_DESCR1(agg_list             , two) // 170
 ADD_BLR_CODE_DESCR1(agg_list_distinct    , two)
 /***
 // These verbs were added in 6.0, primarily to support 64-bit integers, now obsolete
 {"gen_id2", gen_id},
 {"set_generator2", gen_id},
 ***/
 ADD_BLR_CODE_DESCR1(modify2              , modify2)
 ADD_BLR_CODE_NONE()

 // New BLR in FB1
 ADD_BLR_CODE_DESCR1(current_role         , zero)
 ADD_BLR_CODE_DESCR1(skip                 , one)

 // New BLR in FB2
 ADD_BLR_CODE_DESCR1(exec_sql             , one)
 ADD_BLR_CODE_DESCR1(internal_info        , one)
 ADD_BLR_CODE_DESCR1(nullsfirst           , zero)
 ADD_BLR_CODE_DESCR1(writelock            , zero)
 ADD_BLR_CODE_DESCR1(nullslast            , zero) // 180
 ADD_BLR_CODE_DESCR1(lowcase              , one)
 ADD_BLR_CODE_DESCR1(strlen               , strlength)
 ADD_BLR_CODE_DESCR1(trim                 , trim)

 // New BLR in FB2.1
 ADD_BLR_CODE_DESCR1(init_variable        , variable)
 ADD_BLR_CODE_DESCR1(recurse              , union_ops)
 ADD_BLR_CODE_DESCR1(sys_function         , function)

 // New BLR in FB2.5
 ADD_BLR_CODE_DESCR1(auto_trans           , byte_verb)
 ADD_BLR_CODE_DESCR1(similar              , similar)
 ADD_BLR_CODE_DESCR1(exec_stmt            , exec_stmt)
 ADD_BLR_CODE_DESCR1(stmt_expr            , two)
 ADD_BLR_CODE_DESCR1(derived_expr         , derived_expr)
 ADD_BLR_CODE_NONE()
};//sm_blr_table

////////////////////////////////////////////////////////////////////////////////
//SUB CODES

const fb_v02_5_0__blr_printer::FB_TEXT* const fb_v02_5_0__blr_printer::sm_sub_codes[]=
{
 NULL,
 "blr_exec_stmt_inputs, ",
 "blr_exec_stmt_outputs, ",
 "blr_exec_stmt_sql, ",
 "blr_exec_stmt_proc_block, ",
 "blr_exec_stmt_data_src, ",
 "blr_exec_stmt_user, ",
 "blr_exec_stmt_pwd, ",
 "blr_exec_stmt_tran, ",
 "blr_exec_stmt_tran_clone, ",
 "blr_exec_stmt_privs, ",
 "blr_exec_stmt_in_params, ",
 "blr_exec_stmt_in_params2, ",
 "blr_exec_stmt_out_params, "
};//sm_sub_codes

////////////////////////////////////////////////////////////////////////////////
//class fb_v02_5_0__blr_printer::tag_blr_reader

class fb_v02_5_0__blr_printer::tag_blr_reader
{
 private:
  typedef tag_blr_reader                    self_type;

  tag_blr_reader(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tag_blr_reader(size_t          szBlr,
                 const FB_UCHAR* pBlr);

 ~tag_blr_reader();

 public:
  //const FB_UCHAR* getPos()const;

  //void setPos(const FB_UCHAR* newPos);

  void seekBackward(size_t n);

  //void seekForward(size_t n);

  size_t getOffset()const;

  FB_UCHAR peekByte()const;

  FB_USHORT peekWord()const;

  FB_UCHAR getByte();

  FB_USHORT getWord();

 private:
 #ifndef NDEBUG
  void debug_CheckState()const;
 #endif

  void helper__throw_error__unexpected_end_of_buffer
                                           (const wchar_t* place,
                                            const wchar_t* point)const;

 private:
  const FB_UCHAR* const m_pBeg;
  const FB_UCHAR* const m_pEnd;

 private:
  const FB_UCHAR* m_pPos;
};//class fb_v02_5_0__blr_printer::tag_blr_reader

////////////////////////////////////////////////////////////////////////////////
//class fb_v02_5_0__blr_printer::tag_blr_reader

fb_v02_5_0__blr_printer::tag_blr_reader::tag_blr_reader
                                           (size_t          const szBlr,
                                            const FB_UCHAR* const pBlr)
 :m_pBeg(pBlr)
 ,m_pEnd(pBlr+szBlr)
 ,m_pPos(pBlr)
{
 assert(m_pBeg<=m_pEnd);

 CHECK_READ_TYPED_PTR(m_pBeg,szBlr);
}//tag_blr_reader

//------------------------------------------------------------------------
fb_v02_5_0__blr_printer::tag_blr_reader::~tag_blr_reader()
{;}

//interface --------------------------------------------------------------
void fb_v02_5_0__blr_printer::tag_blr_reader::seekBackward(size_t const n)
{
 DEBUG_CODE(this->debug_CheckState());

 const wchar_t* const c_bugcheck_src=
  L"fb_v02_5_0__blr_printer::tag_blr_reader::seekBackward";

 if(size_t(m_pPos-m_pBeg)<n)
 {
  //ERROR - INCORRECT offset

  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#001",
    L"incorrect offset: %1. max value: %2",
    n,
    size_t(m_pPos-m_pBeg));
 }//if

 m_pPos-=n;
}//seekBackward

//------------------------------------------------------------------------
size_t fb_v02_5_0__blr_printer::tag_blr_reader::getOffset()const
{
 DEBUG_CODE(this->debug_CheckState());

 return static_cast<size_t>(m_pPos-m_pBeg);
}//getOffset

//------------------------------------------------------------------------
fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::tag_blr_reader::peekByte()const
{
 DEBUG_CODE(this->debug_CheckState());

 const wchar_t* const c_bugcheck_src=
  L"fb_v02_5_0__blr_printer::tag_blr_reader::peekByte";

 if(size_t(m_pEnd-m_pPos)<sizeof(FB_UCHAR))
 {
  //ERROR - [BUG CHECK] buffer too small

  helper__throw_error__unexpected_end_of_buffer(c_bugcheck_src,
                                                L"#001");
 }//if

 return *m_pPos;
}//peekByte

//------------------------------------------------------------------------
fb_v02_5_0__blr_printer::FB_USHORT
 fb_v02_5_0__blr_printer::tag_blr_reader::peekWord()const
{
 DEBUG_CODE(this->debug_CheckState());

 const wchar_t* const c_bugcheck_src=
  L"fb_v02_5_0__blr_printer::tag_blr_reader::peekWord";

 if(size_t(m_pEnd-m_pPos)<sizeof(FB_USHORT))
 {
  //ERROR - [BUG CHECK] buffer too small

  helper__throw_error__unexpected_end_of_buffer(c_bugcheck_src,
                                                L"#001");
 }//if

 assert_s(sizeof(FB_USHORT)==2);
 assert_s(sizeof(FB_UCHAR)==1);

 const FB_UCHAR lowByte =m_pPos[0];
 const FB_UCHAR highByte=m_pPos[1];

 return (FB_USHORT(highByte)*256)+lowByte;
}//peekWord

//------------------------------------------------------------------------
fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::tag_blr_reader::getByte()
{
 DEBUG_CODE(this->debug_CheckState());

 const wchar_t* const c_bugcheck_src=
  L"fb_v02_5_0__blr_printer::tag_blr_reader::getByte";

 if(size_t(m_pEnd-m_pPos)<sizeof(FB_UCHAR))
 {
  //ERROR - [BUG CHECK] buffer too small

  helper__throw_error__unexpected_end_of_buffer(c_bugcheck_src,
                                                L"#001");
 }//if

 const FB_UCHAR byte=m_pPos[0];

 m_pPos+=1;

 return byte;
}//getByte

//------------------------------------------------------------------------
fb_v02_5_0__blr_printer::FB_USHORT
 fb_v02_5_0__blr_printer::tag_blr_reader::getWord()
{
 DEBUG_CODE(this->debug_CheckState());

 const wchar_t* const c_bugcheck_src=
  L"fb_v02_5_0__blr_printer::tag_blr_reader::getWord";

 if(size_t(m_pEnd-m_pPos)<sizeof(FB_USHORT))
 {
  //ERROR - [BUG CHECK] buffer too small

  helper__throw_error__unexpected_end_of_buffer(c_bugcheck_src,
                                                L"#001");
 }//if

 assert_s(sizeof(FB_USHORT)==2);
 assert_s(sizeof(FB_UCHAR)==1);

 const FB_UCHAR lowByte =m_pPos[0];
 const FB_UCHAR highByte=m_pPos[1];

 m_pPos+=2;

 return (FB_USHORT(highByte)*256)+lowByte;
}//getWord

//------------------------------------------------------------------------
#ifndef NDEBUG

void fb_v02_5_0__blr_printer::tag_blr_reader::debug_CheckState()const
{
 assert(m_pBeg<=m_pPos);
 assert(m_pPos<=m_pEnd);
}//debug_CheckState

#endif

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::tag_blr_reader::helper__throw_error__unexpected_end_of_buffer
                                           (const wchar_t* const place,
                                            const wchar_t* const point)const
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   L"unexpected end of buffer. tail size: %1",
   size_t(m_pEnd-m_pPos));
}//helper__throw_error__unexpected_end_of_buffer

////////////////////////////////////////////////////////////////////////////////
//class fb_v02_5_0__blr_printer::tag_context

class fb_v02_5_0__blr_printer::tag_context
{
 private:
  typedef tag_context                       self_type;

  tag_context(const self_type&);
  self_type& operator = (const self_type&);

 public:
  blr_reader_type&             m_blr_reader;
  FB_FPTR_PRINT_CALLBACK const m_routine;  // Call back
  void*                  const m_user_arg; // User argument
  FB_SSHORT              const m_language;

 public:
  std::string m_string;

 public:
  tag_context(blr_reader_type&       blr_reader,
              FB_FPTR_PRINT_CALLBACK routine,
              void*                  user_arg,
              FB_SSHORT              language);

 ~tag_context();
};//struct fb_v02_5_0__blr_printer::tag_context

////////////////////////////////////////////////////////////////////////////////
//class tag_context::tag_context

fb_v02_5_0__blr_printer::tag_context::tag_context
                                           (blr_reader_type&             blr_reader,
                                            FB_FPTR_PRINT_CALLBACK const routine,
                                            void*                  const user_arg,
                                            FB_SSHORT              const language)
 :m_blr_reader (blr_reader)
 ,m_routine    (routine)
 ,m_user_arg   (user_arg)
 ,m_language   (language)
{
}//tag_context

//------------------------------------------------------------------------
fb_v02_5_0__blr_printer::tag_context::~tag_context()
{;}

////////////////////////////////////////////////////////////////////////////////
//class fb_v02_5_0__blr_printer

void fb_v02_5_0__blr_printer::exec(const FB_UCHAR*        const blr,
                                   size_t                 const blr_length,
                                   FB_FPTR_PRINT_CALLBACK const routine,
                                   void*                  const user_arg,
                                   FB_SSHORT              const language)
{
 CHECK_READ_TYPED_PTR(blr,blr_length);

 blr_reader_type blr_reader(blr_length,
                            blr);

 context_type ctx(blr_reader,
                  routine,
                  user_arg,
                  language);

 switch(const FB_UCHAR version=ctx.m_blr_reader.getByte())
 {
  case blr_code_type::c_version4:
   helper__format(ctx, "blr_version4,");
   break;

  case blr_code_type::c_version5:
   helper__format(ctx, "blr_version5,");
   break;

  default:
   helper__throw_error__unk_blr_version(ctx, version);
 }//switch version

 helper__print_line(ctx, /*offset*/0);

 helper__print_verb(ctx, /*level*/0);

 const size_t offset=ctx.m_blr_reader.getOffset();

 switch(const FB_UCHAR eoc = ctx.m_blr_reader.getByte())
 {
  case blr_code_type::c_eoc:
  {
   helper__format(ctx, "blr_eoc");
   helper__print_line(ctx, offset);
   break;
  }//case

  default:
  {
   helper__throw_error__unk_command_end(ctx, eoc);
  }//default
 }//switch
}//exec

//helper methods ---------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__print_verb(context_type& ctx,
                                                 size_t        level)
{
 size_t offset=ctx.m_blr_reader.getOffset();

 helper__indent(ctx, level);

 const FB_UCHAR blr_operator1=ctx.m_blr_reader.getByte();

 if(blr_operator1==blr_code_type::c_end)
 {
  helper__format(ctx, "blr_end, ");

  helper__print_line(ctx, offset);

  return;
 }//if

 helper__print_blr(ctx, blr_operator1);

 ++level;

 assert(blr_operator1<_DIM_(sm_blr_table));

 const FB_UCHAR* blrOps=sm_blr_table[blr_operator1].blr_operators;

 assert(blrOps!=nullptr);

#ifdef NDEBUG
 unsigned nn1=0;
#else
 structure::t_value_with_null<unsigned> nn1;
#endif

 for(;*blrOps;++blrOps)
 {
  switch (*blrOps)
  {
   //---------------------------------------------------------------------
   case op_verb:
   {
    helper__print_verb(ctx, level);
    break;
   }//op_verb

   //---------------------------------------------------------------------
   case op_line:
   {
    offset=helper__print_line(ctx, offset);
    break;
   }//op_line

   //---------------------------------------------------------------------
   case op_byte:
   {
    //assert(nn1.null());

    nn1=helper__print_byte(ctx);

    break;
   }//op_byte

   //---------------------------------------------------------------------
   case op_byte_opt_verb:
   {
    //assert(nn1.null());

    nn1=helper__print_byte(ctx);

    helper__print_line(ctx, offset);

    if(nn1 DEBUG_CODE(.value()) !=0)
     helper__print_verb(ctx, level);

    break;
   }//op_byte_opt_verb

   //---------------------------------------------------------------------
   case op_word:
   {
    //assert(nn1.null());

    nn1=helper__print_word(ctx);

    break;
   }//op_word

   //---------------------------------------------------------------------
   case op_pad:
   {
    ctx.m_string+=' ';
    break;
   }//op_pad

   //---------------------------------------------------------------------
   case op_dtype:
   {
    //assert(nn1.null());

    nn1=helper__print_dtype(ctx);

    break;
   }//op_dtype

   //---------------------------------------------------------------------
   case op_literal:
   {
    assert(!nn1.null());

    for(;nn1 DEBUG_CODE(.value())>0;--nn1 DEBUG_CODE(.value()))
    {
     helper__print_char(ctx);
    }//for

    DEBUG_CODE(nn1.reset();)

    break;
   }//op_literal

   //---------------------------------------------------------------------
   case op_join:
   {
    helper__print_join(ctx);
    break;
   }//op_join

   //---------------------------------------------------------------------
   case op_message:
   {
    assert(!nn1.null());

    for(;nn1 DEBUG_CODE(.value())>0;--nn1 DEBUG_CODE(.value()))
    {
     helper__indent(ctx, level);

     helper__print_dtype(ctx);

     offset=helper__print_line(ctx, offset);
    }//for

    DEBUG_CODE(nn1.reset();)

    break;
   }//op_message

   //---------------------------------------------------------------------
   case op_parameters:
   {
    assert(!nn1.null());

    for(;nn1 DEBUG_CODE(.value())>0;--nn1 DEBUG_CODE(.value()))
    {
     helper__print_verb(ctx, level+1);
    }//for

    DEBUG_CODE(nn1.reset();)

    break;
   }//op_parameters

   //---------------------------------------------------------------------
   case op_error_handler:
   {
    assert(!nn1.null());

    for(;nn1 DEBUG_CODE(.value())>0;--nn1 DEBUG_CODE(.value()))
    {
     helper__indent(ctx, level);

     helper__print_cond(ctx);

     offset=helper__print_line(ctx, offset);
    }//for

    DEBUG_CODE(nn1.reset();)

    break;
   }//op_error_handler

   //---------------------------------------------------------------------
   case op_set_error:
   {
    helper__print_cond(ctx);
    break;
   }//op_set_error

   //---------------------------------------------------------------------
   case op_indent:
   {
    helper__indent(ctx, level);
    break;
   }//op_indent

   //---------------------------------------------------------------------
   case op_begin:
   {
    while(ctx.m_blr_reader.peekByte()!=blr_code_type::c_end)
    {
     helper__print_verb(ctx, level);
    }//while

    break;
   }//op_begin

   //---------------------------------------------------------------------
   case op_map:
   {
    assert(!nn1.null());

    for(;nn1 DEBUG_CODE(.value())>0;--nn1 DEBUG_CODE(.value()))
    {
     helper__indent(ctx, level);

     helper__print_word(ctx);

     offset=helper__print_line(ctx, offset);

     helper__print_verb(ctx, level);
    }//for

    DEBUG_CODE(nn1.reset();)

    break;
   }//op_map

   //---------------------------------------------------------------------
   case op_args:
   {
    assert(!nn1.null());

    for(;nn1 DEBUG_CODE(.value())>0;--nn1 DEBUG_CODE(.value()))
    {
     helper__print_verb(ctx, level);
    }

    DEBUG_CODE(nn1.reset();)

    break;
   }//op_args

   //---------------------------------------------------------------------
   case op_literals:
   {
    assert(!nn1.null());

    for(;nn1 DEBUG_CODE(.value())>0;--nn1 DEBUG_CODE(.value()))
    {
     helper__indent(ctx, level);

     for(unsigned n2=helper__print_byte(ctx);n2>0;--n2)
     {
      helper__print_char(ctx);
     }

     offset=helper__print_line(ctx,offset);
    }//for

    DEBUG_CODE(nn1.reset();)

    break;
   }//op_literals

   //---------------------------------------------------------------------
   case op_union:
   {
    assert(!nn1.null());

    for(;nn1 DEBUG_CODE(.value())>0;--nn1 DEBUG_CODE(.value()))
    {
     helper__print_verb(ctx, level);

     helper__print_verb(ctx, level);
    }//for

    DEBUG_CODE(nn1.reset();)

    break;
   }//op_union

   //---------------------------------------------------------------------
   case op_relation:
   {
    const FB_UCHAR blr_operator2 = ctx.m_blr_reader.getByte();

    helper__print_blr(ctx, blr_operator2);

    // Strange message. Notice that blr_lock_relation was part of PC_ENGINE.

    switch(blr_operator2)
    {
     case blr_code_type::c_relation:
     {
      for(unsigned n2=helper__print_byte(ctx);n2>0;--n2)
      {
       helper__print_char(ctx);
      }

      break;
     }//case - relation

     case blr_code_type::c_rid:
     {
      helper__print_word(ctx);

      break;
     }//case - rid

     default:
     {
      helper__throw_error__unk_relation_type(ctx,blr_operator2);
     }//default
    }//switch

    break;
   }//op_relation

   //---------------------------------------------------------------------
   case op_exec_into:
   {
    helper__print_verb(ctx, level);

    if(!helper__print_byte(ctx))
    {
     helper__print_verb(ctx, level);
    }

    assert(!nn1.null());

    for(;nn1 DEBUG_CODE(.value())>0;--nn1 DEBUG_CODE(.value()))
    {
     helper__print_verb(ctx, level);
    }//for

    DEBUG_CODE(nn1.reset();)

    break;
   }//op_exec_into

   //---------------------------------------------------------------------
   case op_exec_stmt:
   {
    offset=helper__print_line(ctx, offset);

#ifdef NDEBUG
    unsigned inputs1  = 0;
    unsigned outputs1 = 0;
#else
    structure::t_value_with_null<unsigned> inputs1;
    structure::t_value_with_null<unsigned> outputs1;
#endif

    for(;;)
    {
     const FB_UCHAR blr_operator2=ctx.m_blr_reader.getByte();

     if(blr_operator2==blr_code_type::c_end)
      break;

     helper__indent(ctx, level);

     if(!(blr_operator2<_DIM_(sm_sub_codes)))
      helper__throw_error__unk_blr_code(ctx,blr_operator2);

     assert(blr_operator2<_DIM_(sm_sub_codes));

     if(sm_sub_codes[blr_operator2]==nullptr)
      helper__throw_error__unk_blr_code(ctx,blr_operator2);

     helper__format(ctx, sm_sub_codes[blr_operator2]);

     switch (blr_operator2)
     {
      case blr_code_type::c_exec_stmt_inputs:
      {
       assert(inputs1.null());

       inputs1 = helper__print_word(ctx);
       offset  = helper__print_line(ctx, offset);

       break;
      }//case

      case blr_code_type::c_exec_stmt_outputs:
      {
       assert(outputs1.null());

       outputs1 = helper__print_word(ctx);
       offset   = helper__print_line(ctx, offset);

       break;
      }//case

      case blr_code_type::c_exec_stmt_sql:
      case blr_code_type::c_exec_stmt_proc_block:
      case blr_code_type::c_exec_stmt_data_src:
      case blr_code_type::c_exec_stmt_user:
      case blr_code_type::c_exec_stmt_pwd:
      case blr_code_type::c_exec_stmt_role:
      {
       offset = helper__print_line(ctx, offset);

       helper__print_verb(ctx, level+1);

       break;
      }//case

      // case blr_exec_stmt_tran:
      case blr_code_type::c_exec_stmt_tran_clone:
      {
       helper__print_byte(ctx);

       offset = helper__print_line(ctx, offset);

       break;
      }//case

      case blr_code_type::c_exec_stmt_privs:
      {
       offset = helper__print_line(ctx, offset);

       break;
      }//case

      case blr_code_type::c_exec_stmt_in_params:
      {
       offset=helper__print_line(ctx, offset);

       //! \todo
       //!  MAKE AS BUG CHECK?
       assert(!inputs1.null());

       for(;inputs1 DEBUG_CODE(.value())>0;--inputs1 DEBUG_CODE(.value()))
       {
        helper__print_verb(ctx, level+1);     // param expression

        offset=helper__print_line(ctx, offset);
       }//for

       DEBUG_CODE(inputs1.reset();)

       break;
      }//case c_exec_stmt_in_params

      case blr_code_type::c_exec_stmt_in_params2:
      {
       offset = helper__print_line(ctx, offset);

       //! \todo
       //!  MAKE AS BUG CHECK?
       assert(!inputs1.null());

       for(;inputs1 DEBUG_CODE(.value())>0;--inputs1 DEBUG_CODE(.value()))
       {
        // input param name
        helper__indent(ctx, level+1);

        for(FB_UCHAR len=helper__print_byte(ctx);len>0;--len)
        {
         helper__print_char(ctx);
        }

        offset=helper__print_line(ctx, offset);

        helper__print_verb(ctx, level+1);     // param expression

        offset=helper__print_line(ctx, offset);
       }//for

       DEBUG_CODE(inputs1.reset();)

       break;
      }//c_exec_stmt_in_params2

      case blr_code_type::c_exec_stmt_out_params:
      {
       offset=helper__print_line(ctx, offset);

       //! \todo
       //!  MAKE AS BUG CHECK?
       assert(!outputs1.null());

       for(;outputs1 DEBUG_CODE(.value())>0;--outputs1 DEBUG_CODE(.value()))
       {
        helper__print_verb(ctx, level+1);     // param expression

        offset=helper__print_line(ctx, offset);
       }//for

       break;
      }//c_exec_stmt_out_params

      default:
      {
       //ERROR - WRONG BLR CODE

       helper__throw_error__unk_blr_code(ctx,blr_operator2);
      }//default
     }//switch blr_operation2
    }//for[ever]

    // print blr_end
    ctx.m_blr_reader.seekBackward(1);

    helper__print_verb(ctx, level);

    break;
   }//op_exec_stmt

   //---------------------------------------------------------------------
   case op_derived_expr:
   {
    //original code:
    //n=helper__print_byte(ctx);
    //for(FB_UCHAR i = 0; i < (FB_UCHAR) n; ++i)

    for(unsigned n2=helper__print_byte(ctx);n2>0;--n2)
    {
     helper__print_byte(ctx);
    }//for

    offset=helper__print_line(ctx, offset);

    helper__print_verb(ctx, level);

    break;
   }//op_derived_expr

   //---------------------------------------------------------------------
   case op_cursor_stmt:
   {
#ifdef SCROLLABLE_CURSORS
    const FB_UCHAR blr_operator2=
#endif
     helper__print_byte(ctx);

    helper__print_word(ctx);

#ifdef SCROLLABLE_CURSORS
    if (blr_operator2 == blr_cursor_fetch)
    {
     if (ctx.m_blr_reader.peekByte() == blr_seek)
     {
      helper__print_verb(ctx, level);
     }
    }
#endif

    offset = helper__print_line(ctx, offset);
    break;
   }//op_cursor_stmt

   //---------------------------------------------------------------------
   default:
   {
    //ERROR - WRONG OPERATION CODE OF BLR CODE!
    structure::str_formatter fmsg("*** wrong op code [%1] of blr code [%2] ***");

    fmsg<<*blrOps<<blr_operator1;

    helper__error(ctx,fmsg.c_str());
   }//default
  }//switch
 }//while (*ops)
}//helper__print_verb

//------------------------------------------------------------------------
size_t fb_v02_5_0__blr_printer::helper__print_line(context_type& ctx,
                                                   size_t  const offset)
{
 if(ctx.m_routine)
 {
  structure::self_trimr(ctx.m_string);

  ctx.m_routine(ctx.m_user_arg,
                offset,
                ctx.m_string.c_str());
 }//if

 ctx.m_string.erase();

 return ctx.m_blr_reader.getOffset();
}//helper__print_line

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__print_blr(context_type&  ctx,
                                                FB_UCHAR const blr_operator)
{
 if(!(blr_operator<_DIM_(sm_blr_table)))
  helper__throw_error__unk_blr_code(ctx,blr_operator);

 if(sm_blr_table[blr_operator].blr_string2==nullptr)
  helper__throw_error__unk_blr_code(ctx,blr_operator);

 helper__format(ctx,sm_blr_table[blr_operator].blr_string2);
}//helper__print_blr

//------------------------------------------------------------------------
fb_v02_5_0__blr_printer::FB_UCHAR
 fb_v02_5_0__blr_printer::helper__print_byte(context_type& ctx)
{
 const FB_UCHAR b=ctx.m_blr_reader.getByte();

 if(ctx.m_language)
 {
  FB_TEXT tmp[128];

  _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"chr(%d), ",(int)b);

  helper__format(ctx, tmp);
 }
 else
 {
  FB_TEXT tmp[128];

  _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%d, ",(int)b);

  helper__format(ctx, tmp);
 }//else

 return b;
}//helper__print_byte

//------------------------------------------------------------------------
fb_v02_5_0__blr_printer::FB_USHORT
 fb_v02_5_0__blr_printer::helper__print_word(context_type& ctx)
{
 const FB_USHORT resultValue=ctx.m_blr_reader.getWord();

 assert_s(sizeof(FB_USHORT)==2);
 assert_s(sizeof(FB_UCHAR)==1);
 assert_s(CHAR_BIT==8);

 const FB_UCHAR v1 = static_cast<FB_UCHAR>(resultValue%256);
 const FB_UCHAR v2 = static_cast<FB_UCHAR>(resultValue/256);

 assert(((256*v2)+v1)==resultValue);

 if(ctx.m_language)
 {
  FB_TEXT tmp[128];

  _GCRT_sprintf_s_n2(tmp,_DIM_(tmp),"chr(%d),chr(%d), ",(int)v1,(int)v2);

  helper__format(ctx, tmp);
 }
 else
 {
  FB_TEXT tmp[128];

  _GCRT_sprintf_s_n2(tmp,_DIM_(tmp),"%d,%d, ",(int)v1,(int)v2);

  helper__format(ctx, tmp);
 }//else

 return resultValue;
}//helper__print_word

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__print_char(context_type& ctx)
{
 const FB_UCHAR b=ctx.m_blr_reader.getByte();

 if(helper__is_printable(b))
 {
  const FB_TEXT str[]={'\'',static_cast<FB_SCHAR>(b),'\'',',',0};

  helper__format(ctx, str);
 }
 else
 if(ctx.m_language)
 {
  FB_TEXT tmp[128];

  _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"chr(%d),",(int)b);

  helper__format(ctx, tmp);
 }
 else
 {
  FB_TEXT tmp[128];

  _GCRT_sprintf_s_n1(tmp,_DIM_(tmp),"%d,",(int)static_cast<FB_SCHAR>(b));

  helper__format(ctx, tmp);
 }//else
}//helper__print_char

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__print_join(context_type& ctx)
{
 switch(const FB_UCHAR join_type=ctx.m_blr_reader.getByte())
 {
  case blr_code_type::c_inner:
   return helper__format(ctx,"blr_inner, ");

  case blr_code_type::c_left:
   return helper__format(ctx,"blr_left, ");

  case blr_code_type::c_right:
   return helper__format(ctx, "blr_right, ");

  case blr_code_type::c_full:
   return helper__format(ctx, "blr_full, ");

  default:
   helper__throw_error__unk_join_type(ctx,join_type);
 }//switch join_type
}//helper__print_join

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__print_cond(context_type& ctx)
{
 switch(const FB_UCHAR conditional_type=ctx.m_blr_reader.getByte())
 {
  case blr_code_type::c_gds_code:
  {
   helper__format(ctx, "blr_gds_code, ");

   for(unsigned n=helper__print_byte(ctx);n>0;--n)
   {
    helper__print_char(ctx);
   }

   break;
  }//c_gds_code

  case blr_code_type::c_exception:
  {
   helper__format(ctx, "blr_exception, ");

   for(unsigned n=helper__print_byte(ctx);n>0;--n)
   {
    helper__print_char(ctx);
   }

   break;
  }//c_exception

  case blr_code_type::c_exception_msg:
  {
   helper__format(ctx, "blr_exception_msg, ");

   for(unsigned n=helper__print_byte(ctx);n>0;--n)
   {
    helper__print_char(ctx);
   }

   helper__print_verb(ctx, /*level*/0);

   break;
  }//c_exception_msg

  case blr_code_type::c_sql_code:
  {
   helper__format(ctx, "blr_sql_code, ");

   helper__print_word(ctx);

   break;
  }//c_sql_code

  case blr_code_type::c_default_code:
  {
   helper__format(ctx, "blr_default_code, ");

   break;
  }//c_default_code

  case blr_code_type::c_raise:
  {
   helper__format(ctx, "blr_raise, ");

   break;
  }//c_raise

  default:
  {
   helper__throw_error__unk_conditional_type(ctx,conditional_type);
  }//default
 }//switch
}//helper__print_cond

//------------------------------------------------------------------------
unsigned fb_v02_5_0__blr_printer::helper__print_dtype(context_type& ctx)
{
 const FB_UCHAR dtype=ctx.m_blr_reader.getByte();

 /* Special case blob (261) to keep down the size of the jump table */
 const FB_TEXT* string2=nullptr;

 unsigned length=0;

 switch(dtype)
 {
  case blr_code_type::c_short:
   string2 = "blr_short, ";
   length  = 2;
   break;

  case blr_code_type::c_long:
   string2 = "blr_long, ";
   length  = 4;
   break;

  case blr_code_type::c_int64:
   string2 = "blr_int64, ";
   length  = 8;
   break;

  case blr_code_type::c_quad:
   string2 = "blr_quad, ";
   length  = 8;
   break;

  case blr_code_type::c_timestamp:
   string2 = "blr_timestamp, ";
   length  = 8;
   break;

  case blr_code_type::c_sql_time:
   string2 = "blr_sql_time, ";
   length  = 4;
   break;

  case blr_code_type::c_sql_date:
   string2 = "blr_sql_date, ";
   length  = 4;
   break;

  case blr_code_type::c_float:
   string2 = "blr_float, ";
   length  = 4;
   break;

  case blr_code_type::c_double:
   string2 = "blr_double, ";

   /* for double literal, return the length of the numeric string */
   length =ctx.m_blr_reader.peekWord();
   length+=2;
   break;

  case blr_code_type::c_d_float:
   string2 = "blr_d_float, ";
   length  = 8;
   break;

  case blr_code_type::c_text:
   string2 = "blr_text, ";
   break;

  case blr_code_type::c_cstring:
   string2 = "blr_cstring, ";
   break;

  case blr_code_type::c_varying:
   string2 = "blr_varying, ";
   break;

  case blr_code_type::c_text2:
   string2 = "blr_text2, ";
   break;

  case blr_code_type::c_cstring2:
   string2 = "blr_cstring2, ";
   break;

  case blr_code_type::c_varying2:
   string2 = "blr_varying2, ";
   break;

  case blr_code_type::c_blob2:
   string2 = "blr_blob2, ";
   length  = 8;
   break;

  case blr_code_type::c_domain_name:
   string2 = "blr_domain_name, ";
   // Don't bother with this length.
   // It will not be used for blr_domain_name.
   assert(length == 0);
   break;

  case blr_code_type::c_domain_name2:
   string2 = "blr_domain_name2, ";
   // Don't bother with this length.
   // It will not be used for blr_domain_name2.
   length = 0;
   break;

  case blr_code_type::c_column_name:
   string2 = "blr_column_name, ";
   // Don't bother with this length.
   // It will not be used for blr_column_name.
   length = 0;
   break;

  case blr_code_type::c_column_name2:
   string2 = "blr_column_name2, ";
   // Don't bother with this length.
   // It will not be used for blr_column_name2.
   length = 0;
   break;

  case blr_code_type::c_not_nullable:
   string2 = "blr_not_nullable, ";
   break;

  default:
   helper__throw_error__unk_data_type(ctx, dtype);
 }//switch ctype

 helper__format(ctx, string2);

 switch (dtype)
 {
  case blr_code_type::c_not_nullable:
   length =helper__print_dtype(ctx);
   break;

  case blr_code_type::c_text:
   length =helper__print_word(ctx);
   break;

  case blr_code_type::c_varying:
   length =helper__print_word(ctx);
   length+=2;
   break;

  case blr_code_type::c_cstring:
   length =helper__print_word(ctx);
   break;

  case blr_code_type::c_short:
  case blr_code_type::c_long:
  case blr_code_type::c_quad:
  case blr_code_type::c_int64:
   helper__print_byte(ctx);
   break;

  case blr_code_type::c_text2:
   helper__print_word(ctx);
   length =helper__print_word(ctx);
   break;

  case blr_code_type::c_varying2:
   helper__print_word(ctx);
   length =helper__print_word(ctx);
   length+=2;
   break;

  case blr_code_type::c_cstring2:
   helper__print_word(ctx);
   length =helper__print_word(ctx);
   break;

  case blr_code_type::c_blob2:
   helper__print_word(ctx);
   helper__print_word(ctx);
   break;

  case blr_code_type::c_domain_name:
  {
   // 0 = blr_domain_type_of; 1 = blr_domain_full
   helper__print_byte(ctx);

   for(FB_UCHAR n = helper__print_byte(ctx); n > 0; --n)
    helper__print_char(ctx);

   break;
  }//case c_domain_name

  case blr_code_type::c_domain_name2:
  {
   // 0 = blr_domain_type_of; 1 = blr_domain_full
   helper__print_byte(ctx);

   for(FB_UCHAR n = helper__print_byte(ctx); n > 0; --n)
    helper__print_char(ctx);

   helper__print_word(ctx);

   break;
  }//case c_domain_name2

  case blr_code_type::c_column_name:
  {
   // 0 = blr_domain_type_of; 1 = blr_domain_full
   helper__print_byte(ctx);

   for(FB_UCHAR n = helper__print_byte(ctx); n > 0; --n)
    helper__print_char(ctx);

   helper__format(ctx, " ");

   for(FB_UCHAR n = helper__print_byte(ctx); n > 0; --n)
    helper__print_char(ctx);

   break;
  }//case c_column_name

  case blr_code_type::c_column_name2:
  {
   // 0 = blr_domain_type_of; 1 = blr_domain_full
   helper__print_byte(ctx);

   for(FB_UCHAR n = helper__print_byte(ctx); n > 0; --n)
    helper__print_char(ctx);

   helper__format(ctx, " ");

   for(FB_UCHAR n = helper__print_byte(ctx); n > 0; --n)
    helper__print_char(ctx);

   helper__print_word(ctx);

   break;
  }//case c_column_name2
 }//switch dtype

 return length;
}//helper__print_dtype

//------------------------------------------------------------------------
bool fb_v02_5_0__blr_printer::helper__is_printable(const FB_SCHAR ch)
{
 if(ch>='a' && ch<='z')
  return true;

 if(ch>='A' && ch<='Z')
  return true;

 if(ch>='0' && ch<='9')
  return true;

 if(ch=='$')
  return true;

 if(ch=='_')
  return true;

 return false;
}//helper__is_printable

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__error(context_type&        ctx,
                                            const FB_TEXT* const string)
{
 assert(string);
 assert(structure::string_length(string)>0);

 helper__format(ctx, string);

 helper__print_line(ctx, /*offset*/0);

 //[2015-11-21] Тормозим и изучаем проблему с BLR
 assert_msg(false,string);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_subsystem__isc_api__fb2_5,
   ibp_mce_isc__failed_to_process_blr_code_1,
   string);
}//helper__error

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__format(context_type&        ctx,
                                             const FB_TEXT* const string)
{
 assert(string);
 assert(structure::string_length(string)>0);

 ctx.m_string+=string;
}//helper__format

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__indent(context_type& ctx,
                                             size_t const  level)
{
 if(structure::t_numeric_limits<size_t>::max_value()/3<level)
  throw std::bad_alloc();

 ctx.m_string.append(level*3,' ');
}//helper__indent

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__throw_error__unk_blr_version
                                           (context_type&  ctx,
                                            unsigned const blr_version)
{
 helper__throw_error(ctx,
                     "*** blr version %1 is not supported ***",
                     blr_version);
}//helper__throw_error__unk_blr_version

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__throw_error__unk_blr_code
                                           (context_type&  ctx,
                                            unsigned const blr_code)
{
 helper__throw_error(ctx,
                     "*** blr operator %1 is undefined ***",
                     blr_code);
}//helper__throw_error__blr_code_undefined

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__throw_error__unk_join_type
                                           (context_type&  ctx,
                                            unsigned const join_type)
{
 helper__throw_error(ctx,
                     "*** invalid join type [%1] ***",
                     join_type);
}//helper__throw_error__unk_join_type

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__throw_error__unk_conditional_type
                                           (context_type&  ctx,
                                            unsigned const conditional_type)
{
 helper__throw_error(ctx,
                     "*** invalid condition type [%1] ***",
                     conditional_type);
}//helper__throw_error__unk_conditional_type

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__throw_error__unk_data_type
                                           (context_type&  ctx,
                                            unsigned const data_type)
{
 helper__throw_error(ctx,
                     "*** invalid data type [%1] ***",
                     data_type);
}//helper__throw_error__unk_data_type

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__throw_error__unk_relation_type
                                           (context_type&  ctx,
                                            unsigned const relation_type)
{
 helper__throw_error(ctx,
                     "*** invalid relation type [%1] ***",
                     relation_type);
}//helper__throw_error__unk_relation_type

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__throw_error__unk_command_end
                                           (context_type&  ctx,
                                            unsigned const end_code)
{
 helper__throw_error(ctx,
                     "*** expected end of command, encounted %1 ***",
                     end_code);
}//helper__throw_error__unk_command_end

//------------------------------------------------------------------------
void fb_v02_5_0__blr_printer::helper__throw_error(context_type&         ctx,
                                               const FB_SCHAR* const errTempl_1,
                                               unsigned        const v1)
{
 assert(errTempl_1);

 structure::str_formatter fmsg(errTempl_1);

 fmsg<<v1;

 helper__error(ctx,fmsg.c_str());
}//helper__throw_error

////////////////////////////////////////////////////////////////////////////////
}/*nms v02_5_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
