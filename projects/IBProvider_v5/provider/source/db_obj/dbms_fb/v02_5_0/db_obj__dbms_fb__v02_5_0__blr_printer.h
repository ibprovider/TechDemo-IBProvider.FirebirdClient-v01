////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v02_5_0
//! \file    db_obj__dbms_fb__v02_5_0__blr_printer.h
//! \brief   Принтер BLR-кода Firebird 2.5.
//! \author  Kovalenko Dmitry
//! \date    20.11.2015
#ifndef _db_obj__dbms_fb__v02_5_0__blr_printer_H_
#define _db_obj__dbms_fb__v02_5_0__blr_printer_H_

#include "source/db_obj/dbms_fb/v02_5_0/api/db_obj__dbms_fb__v02_5_0__api__blr_codes.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v02_5_0{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__dbms_fb__v02_5_0
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class fb_v02_5_0__blr_printer

/// <summary>
///  Принтер BLR-кода Firebird 2.5.
/// </summary>
class fb_v02_5_0__blr_printer
{
 private:
  typedef fb_v02_5_0__blr_printer              self_type;

 public: //typedefs ------------------------------------------------------
  typedef char                              FB_TEXT;

  typedef unsigned char                     FB_UCHAR;
  typedef char                              FB_SCHAR;

  typedef signed short                      FB_SSHORT;
  typedef unsigned short                    FB_USHORT;

  typedef unsigned __int32                  FB_ULONG;
  typedef signed __int32                    FB_SLONG;

  typedef void (*FB_FPTR_PRINT_CALLBACK) (void*          arg,
                                          size_t         offset,
                                          const FB_TEXT* line);

 public:
  /// <summary>
  ///  Обработка BLR кода.
  /// </summary>
  //! \attention
  //!  В случае проблем с BLR, генерируется исключение t_ibp_error
  //!  с номинальным описанием ошибки.
  static void exec(const UCHAR*           blr,
                   size_t                 blr_length,
                   FB_FPTR_PRINT_CALLBACK routine,
                   void*                  user_arg,
                   FB_SSHORT              language); //throw

 private:
  typedef api::fb_v02_5_0__blr_code  blr_code_type;

  class tag_blr_reader;
  class tag_context;

  typedef tag_blr_reader                    blr_reader_type;
  typedef tag_context                       context_type;

 private:
  static void helper__print_verb(context_type& ctx, size_t level);

  static size_t helper__print_line(context_type& ctx, size_t offset);

  static void helper__print_blr(context_type& ctx, FB_UCHAR blr_operator);

  //orifinal return: SCHAR.
  static FB_UCHAR helper__print_byte(context_type& ctx);

  static FB_USHORT helper__print_word(context_type& ctx);

  static void helper__print_char(context_type& ctx);

  static void helper__print_join(context_type& ctx);

  static void helper__print_cond(context_type& ctx);

  static unsigned helper__print_dtype(context_type& ctx);

 private:
  static bool helper__is_printable(const FB_SCHAR ch);

 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__error(context_type& ctx, const FB_TEXT* string);

  static void helper__format(context_type& ctx, const FB_TEXT* string);

  static void helper__indent(context_type& ctx, size_t level);

 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error__unk_blr_version(context_type& ctx,
                                                   unsigned      blr_version);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error__unk_blr_code(context_type& ctx,
                                                unsigned      blr_code);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error__unk_join_type(context_type& ctx,
                                                 unsigned      join_type);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error__unk_conditional_type(context_type& ctx,
                                                        unsigned      conditional_type);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error__unk_data_type(context_type& ctx,
                                                 unsigned      data_type);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error__unk_relation_type(context_type& ctx,
                                                     unsigned      relation_type);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error__unk_command_end(context_type& ctx,
                                                   unsigned      end_code);

 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error(context_type&   ctx,
                                  const FB_SCHAR* errTempl_1,
                                  unsigned        v1);

 private:
  enum
  {
   op_line           = 1,
   op_verb           = 2,
   op_byte           = 3,
   op_word           = 4,
   op_pad            = 5,
   op_dtype          = 6,
   op_message        = 7,
   op_literal        = 8,
   op_begin          = 9,
   op_map            = 10,
   op_args           = 11,
   op_union          = 12,
   op_indent         = 13,
   op_join           = 14,
   op_parameters     = 15,
   op_error_handler  = 16,
   op_set_error      = 17,
   op_literals       = 18,
   op_relation       = 20,
   op_exec_into      = 21,
   op_cursor_stmt    = 22,
   op_byte_opt_verb  = 23,
   op_exec_stmt      = 24,
   op_derived_expr   = 25,
  };//enum

 private: //generic print formats
  static const FB_UCHAR sm_pfm_zero[];
  static const FB_UCHAR sm_pfm_one[];
  static const FB_UCHAR sm_pfm_two[];
  static const FB_UCHAR sm_pfm_three[];
  static const FB_UCHAR sm_pfm_field[];
  static const FB_UCHAR sm_pfm_byte_line[];
  static const FB_UCHAR sm_pfm_byte_args[];
  static const FB_UCHAR sm_pfm_byte_verb[];
  static const FB_UCHAR sm_pfm_byte_verb_verb[];
  static const FB_UCHAR sm_pfm_byte_literal[];
  static const FB_UCHAR sm_pfm_byte_byte_verb[];
  static const FB_UCHAR sm_pfm_parm[];

  static const FB_UCHAR sm_pfm_parm2[];
  static const FB_UCHAR sm_pfm_parm3[];

	/* formats specific to a verb */
  static const FB_UCHAR sm_pfm_begin[];
  static const FB_UCHAR sm_pfm_literal[];
  static const FB_UCHAR sm_pfm_message[];
  static const FB_UCHAR sm_pfm_rse[];
  static const FB_UCHAR sm_pfm_relation[];
  static const FB_UCHAR sm_pfm_relation2[];
  static const FB_UCHAR sm_pfm_aggregate[];
  static const FB_UCHAR sm_pfm_rid[];
  static const FB_UCHAR sm_pfm_rid2[];
  static const FB_UCHAR sm_pfm_union_ops[];
  static const FB_UCHAR sm_pfm_map[];
  static const FB_UCHAR sm_pfm_function[];
  static const FB_UCHAR sm_pfm_gen_id[];
  static const FB_UCHAR sm_pfm_declare[];
  static const FB_UCHAR sm_pfm_variable[];
  static const FB_UCHAR sm_pfm_indx[];
  static const FB_UCHAR sm_pfm_seek[];
  static const FB_UCHAR sm_pfm_join[];
  static const FB_UCHAR sm_pfm_exec_proc[];
  static const FB_UCHAR sm_pfm_procedure[];
  static const FB_UCHAR sm_pfm_pid[];
  static const FB_UCHAR sm_pfm_error_handler[];
  static const FB_UCHAR sm_pfm_set_error[];
  static const FB_UCHAR sm_pfm_cast[];
  static const FB_UCHAR sm_pfm_indices[];
  static const FB_UCHAR sm_pfm_extract[];
  static const FB_UCHAR sm_pfm_user_savepoint[];
  static const FB_UCHAR sm_pfm_exec_into[];
  static const FB_UCHAR sm_pfm_dcl_cursor[];
  static const FB_UCHAR sm_pfm_cursor_stmt[];
  static const FB_UCHAR sm_pfm_strlength[];
  static const FB_UCHAR sm_pfm_trim[];
  static const FB_UCHAR sm_pfm_modify2[];
  static const FB_UCHAR sm_pfm_similar[];
  static const FB_UCHAR sm_pfm_exec_stmt[];
  static const FB_UCHAR sm_pfm_derived_expr[];

 private:
  struct tag_blr_code_descr
  {
#ifndef NDEBUG
   unsigned        blr_code;
#endif
   const FB_TEXT*  blr_string2;
   const FB_UCHAR* blr_operators;
  };//class tag_blr_code_descr

  typedef tag_blr_code_descr blr_code_descr_type;

  static const blr_code_descr_type sm_blr_table[];

 private:
  static const FB_TEXT* const sm_sub_codes[];
};//class fb_v02_5_0__blr_printer

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v02_5_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
