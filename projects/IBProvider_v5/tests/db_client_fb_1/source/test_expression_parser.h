////////////////////////////////////////////////////////////////////////////////
//Services for tests
//                                                     Piminov Roman. 05.03.2009
#ifndef _ibp_tso_expression_parser_H_
#define _ibp_tso_expression_parser_H_

#include "source/test_memory.h"
#include <structure/t_str_version.h>
#include <map>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//forward declarations

class TSYS_CommandLine;

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_ExpressionComparer

class TIBP_TSO_ExpressionComparer:public TSYS_SmartMemoryObject
{
 private:
  typedef TIBP_TSO_ExpressionComparer                     self_type;

  TIBP_TSO_ExpressionComparer(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<const self_type>  self_cptr;

  typedef std::string                                     expression_type;

 protected:
  TIBP_TSO_ExpressionComparer();

  virtual ~TIBP_TSO_ExpressionComparer();

 public:
  virtual bool operator == (const expression_type& str) const;

  virtual bool operator >  (const expression_type& str) const;

  virtual bool operator <  (const expression_type& str) const;

  virtual bool operator >= (const expression_type& str) const;

  virtual bool operator <= (const expression_type& str) const;

  virtual bool operator != (const expression_type& str) const;
};//class TIBP_TSO_ExpressionComparer

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_EqualComparer

class TIBP_TSO_EqualComparer:public TIBP_TSO_ExpressionComparer
{
 private:
  typedef TIBP_TSO_EqualComparer   self_type;

  TIBP_TSO_EqualComparer(const self_type&);
  self_type& operator = (const self_type&);

 private:
  TIBP_TSO_EqualComparer(const expression_type& value);

  virtual ~TIBP_TSO_EqualComparer();

 public:
  static self_cptr create(const expression_type& value);

 public:
  virtual bool operator == (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator != (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;

 private:
  const expression_type  m_value;
};//class TIBP_TSO_EqualComparer

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_VersionComparer

class TIBP_TSO_VersionComparer:public TIBP_TSO_ExpressionComparer
{
 private:
  typedef TIBP_TSO_VersionComparer   self_type;

  TIBP_TSO_VersionComparer(const self_type&);
  self_type& operator = (const self_type&);

 private:
  TIBP_TSO_VersionComparer(const expression_type& version_str);

  virtual ~TIBP_TSO_VersionComparer();

 public:
  static self_cptr create(const expression_type& version_str);

 public:
  virtual bool operator == (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator >  (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator <  (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator >= (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator <= (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator != (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;

 private:
  const structure::str_version  m_version;
};//class TIBP_TSO_VersionComparer

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_ServerComparer

class TIBP_TSO_ServerComparer:public TIBP_TSO_ExpressionComparer
{
 private:
  typedef TIBP_TSO_ServerComparer   self_type;

  TIBP_TSO_ServerComparer(const self_type&);
  self_type& operator = (const self_type&);

 private:
  TIBP_TSO_ServerComparer(const expression_type& server_str,
                          const expression_type& version_str);

  virtual ~TIBP_TSO_ServerComparer();

 public:
  static self_cptr create(const expression_type& server_str,
                          const expression_type& version_str);

 public:
  virtual bool operator == (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator >  (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator <  (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator >= (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator <= (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;
  virtual bool operator != (const expression_type& str) const COMP_W000004_OVERRIDE_FINAL;

 private:
  const std::string             m_server_id;
  const structure::str_version  m_version;
};//class TIBP_TSO_ServerComparer

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_ExpressionParser

class TIBP_TSO_ExpressionParser
{
 private:
  typedef TIBP_TSO_ExpressionParser         self_type;

  TIBP_TSO_ExpressionParser(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef char                              expression_element;
  typedef structure::t_basic_const_str_box
           <expression_element>             expression_box_type;

  typedef __STL_DEF_BASIC_STRING
           (expression_element)             expression_str_type;

  enum enum_calc_result
  {
   calc_result__empty_cond =0,

   calc_result__no         =-1,

   calc_result__yes        =1,
  };//enum_calc_result

  typedef enum_calc_result                  calc_result_type;

 public:
  explicit TIBP_TSO_ExpressionParser(const TSYS_CommandLine* pCL);

 ~TIBP_TSO_ExpressionParser();

 public:
  void reg_macro(const char* name, const char* expression);

  calc_result_type calc(expression_box_type exp_str)const;

 private:
  class tag_ctx;

  typedef tag_ctx                           ctx_type;

 private:
  enum token_type
  {
   type_none = 1,
   type_delimiter = 2,
   type_ident = 3
  };

 private:
  typedef TIBP_TSO_ExpressionComparer       comparer_type;
  typedef comparer_type::self_cptr          comparer_cptr;

 private:
  bool process_1_or(ctx_type& ctx)const;

  bool process_2_and(ctx_type& ctx)const;

  bool process_3_not(ctx_type& ctx)const;

  bool process_4_bracket(ctx_type& ctx)const;

  bool process_term(ctx_type& ctx)const;

 private:
  void get_token(ctx_type& ctx)const;

 private:
  static bool helper__is_space(const expression_element c);

  static bool helper__is_bracket(const expression_element c);

  static bool helper__is_operator(const expression_element c);

  static bool helper__is_delimiter(const expression_element c);

  COMP_CONF_DECLSPEC_NORETURN
  static void helper__throw_error(ctx_type& ctx, const char* const str);

 private:
  comparer_cptr helper__get_comparer(const std::string& id)const;

 private:
  static comparer_cptr helper__createSrvComparer
                        (const TSYS_CommandLine* pCL);

  static comparer_cptr helper__createOdsComparer
                        (const TSYS_CommandLine* pCL);

  static comparer_cptr helper__createDBDialectComparer
                        (const TSYS_CommandLine* pCL);
 private:
  const comparer_cptr m_spSrvComparer;
  const comparer_cptr m_spOdsComparer;
  const comparer_cptr m_spDBDialectComparer;

 private:
  typedef std::map<std::string,std::string> macroses_type;

  macroses_type m_macroses;

 private:
  static const expression_element sm_space_symbols[];
  static const expression_element sm_operator_symbols[];
  static const expression_element sm_bracket_symbols[];
};//class TIBP_TSO_ExpressionParser

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
#endif
