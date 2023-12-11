////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_base.h"
#include <structure/t_str_formatter.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_ExpressionComparer

TIBP_TSO_ExpressionComparer::TIBP_TSO_ExpressionComparer()
{;}

//------------------------------------------------------------------------
TIBP_TSO_ExpressionComparer::~TIBP_TSO_ExpressionComparer()
{;}

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionComparer::operator == (const expression_type& /*str*/) const
{
 throw std::runtime_error("The definition of operator == is required");
}//operator ==

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionComparer::operator >  (const expression_type& /*str*/) const
{
 throw std::runtime_error("The definition of operator > is required");
}////operator >

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionComparer::operator <  (const expression_type& /*str*/) const
{
 throw std::runtime_error("The definition of operator < is required");
}//operator <

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionComparer::operator >= (const expression_type& /*str*/) const
{
 throw std::runtime_error("The definition of operator >= is required");
}//operator >=

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionComparer::operator <= (const expression_type& /*str*/) const
{
 throw std::runtime_error("The definition of operator <= is required");
}//operator <=

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionComparer::operator != (const expression_type& /*str*/) const
{
 throw std::runtime_error("The definition of operator != is required");
}//operator !=

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_VersionComparer

TIBP_TSO_EqualComparer::TIBP_TSO_EqualComparer(const expression_type& value)
 :m_value(value)
{;}

//------------------------------------------------------------------------
TIBP_TSO_EqualComparer::~TIBP_TSO_EqualComparer()
{;}

//------------------------------------------------------------------------
TIBP_TSO_EqualComparer::self_cptr
 TIBP_TSO_EqualComparer::create(const expression_type& value)
{
 return structure::not_null_ptr(new self_type(value));
}//create

//------------------------------------------------------------------------
bool TIBP_TSO_EqualComparer::operator == (const expression_type& str)const
{
 return m_value==str;
}//operator ==

//------------------------------------------------------------------------
bool TIBP_TSO_EqualComparer::operator != (const expression_type& str)const
{
 return m_value!=str;
}//operator !=

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_VersionComparer

TIBP_TSO_VersionComparer::TIBP_TSO_VersionComparer(const expression_type& version_str)
 :m_version(version_str)
{;}

//------------------------------------------------------------------------
TIBP_TSO_VersionComparer::~TIBP_TSO_VersionComparer()
{;}

//------------------------------------------------------------------------
TIBP_TSO_VersionComparer::self_cptr
 TIBP_TSO_VersionComparer::create(const expression_type& version_str)
{
 return structure::not_null_ptr(new self_type(version_str));
}//create

//------------------------------------------------------------------------
bool TIBP_TSO_VersionComparer::operator == (const expression_type& str)const
{
 return structure::cmp_str_version_prefix(m_version,str.c_str())==0;
}

//------------------------------------------------------------------------
bool TIBP_TSO_VersionComparer::operator > (const expression_type& str)const
{
 return structure::cmp_str_version_prefix(m_version,str.c_str())>0;
}

//------------------------------------------------------------------------
bool TIBP_TSO_VersionComparer::operator < (const expression_type& str)const
{
 return structure::cmp_str_version_prefix(m_version,str.c_str())<0;
}

//------------------------------------------------------------------------
bool TIBP_TSO_VersionComparer::operator >= (const expression_type& str)const
{
 return structure::cmp_str_version_prefix(m_version,str.c_str())>=0;
}

//------------------------------------------------------------------------
bool TIBP_TSO_VersionComparer::operator <= (const expression_type& str)const
{
 return structure::cmp_str_version_prefix(m_version,str.c_str())<=0;
}

//------------------------------------------------------------------------
bool TIBP_TSO_VersionComparer::operator != (const expression_type& str)const
{
 return structure::cmp_str_version_prefix(m_version,str.c_str())!=0;
}

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_ServerComparer

TIBP_TSO_ServerComparer::TIBP_TSO_ServerComparer(const expression_type& server_str,
                                                 const expression_type& version_str)
 :m_server_id(server_str)
 ,m_version(version_str)
{
 assert(!m_server_id.empty());
}//TIBP_TSO_ServerComparer

//------------------------------------------------------------------------
TIBP_TSO_ServerComparer::~TIBP_TSO_ServerComparer()
{;}

//------------------------------------------------------------------------
TIBP_TSO_ServerComparer::self_cptr
 TIBP_TSO_ServerComparer::create(const expression_type& server_str,
                                 const expression_type& version_str)
{
 return structure::not_null_ptr(new self_type(server_str,
                                              version_str));
}//create

//------------------------------------------------------------------------
bool TIBP_TSO_ServerComparer::operator == (const expression_type& str)const
{
 const expression_type::size_type pos=str.find('-');

 if(pos==expression_type::npos)
  return m_server_id==str;

 assert(pos<str.size());

 if(str.compare(0,pos,m_server_id)!=0)
  return false;

 return structure::cmp_str_version_prefix(m_version,str.c_str()+(pos+1))==0;
}//operator ==

//------------------------------------------------------------------------
bool TIBP_TSO_ServerComparer::operator > (const expression_type& str)const
{
 const expression_type::size_type pos=str.find('-');

 if(pos==expression_type::npos)
  return false;

 assert(pos<str.size());

 if(str.compare(0,pos,m_server_id)!=0)
  return false;

 return structure::cmp_str_version_prefix(m_version,str.c_str()+(pos+1))>0;
}//operator >

//------------------------------------------------------------------------
bool TIBP_TSO_ServerComparer::operator < (const expression_type& str)const
{
 const expression_type::size_type pos=str.find('-');

 if(pos==expression_type::npos)
  return false;

 assert(pos<str.size());

 if(str.compare(0,pos,m_server_id)!=0)
  return false;

 return structure::cmp_str_version_prefix(m_version,str.c_str()+(pos+1))<0;
}//operator <

//------------------------------------------------------------------------
bool TIBP_TSO_ServerComparer::operator >= (const expression_type& str)const
{
 const expression_type::size_type pos=str.find('-');

 if(pos==expression_type::npos)
  return m_server_id==str;

 assert(pos<str.length());

 if(str.compare(0,pos,m_server_id)!=0)
  return false;

 return structure::cmp_str_version_prefix(m_version,str.c_str()+(pos+1))>=0;
}//operator >=

//------------------------------------------------------------------------
bool TIBP_TSO_ServerComparer::operator <= (const expression_type& str)const
{
 const expression_type::size_type pos=str.find('-');

 if(pos==expression_type::npos)
  return m_server_id==str;

 assert(pos<str.length());

 if(str.compare(0,pos,m_server_id)!=0)
  return false;

 return structure::cmp_str_version_prefix(m_version,str.c_str()+(pos+1))<=0;
}//operator <=

//------------------------------------------------------------------------
bool TIBP_TSO_ServerComparer::operator != (const expression_type& str)const
{
 return !((*this)==str);
}//operator !=

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_ExpressionParser::tag_ctx

class TIBP_TSO_ExpressionParser::tag_ctx
{
 private:
  typedef tag_ctx                           ctx_type;

  tag_ctx(const tag_ctx&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef expression_box_type::iterator     expression_iterator;

 public:
  expression_iterator const m_exp_beg;
  expression_iterator const m_exp_end;
  expression_iterator       m_exp_pos;

 public:
  expression_str_type  m_last_token;
  token_type           m_last_token_type;

 public:
  tag_ctx(const expression_box_type* exp_str);

 ~tag_ctx();
};//class TIBP_TSO_ExpressionParser::tag_ctx

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_ExpressionParser::tag_ctx

TIBP_TSO_ExpressionParser::tag_ctx::tag_ctx(const expression_box_type* const exp_str)
 :m_exp_beg(exp_str->begin())
 ,m_exp_end(exp_str->end())
 ,m_exp_pos(exp_str->begin())
 ,m_last_token_type(type_none)
{;}

//------------------------------------------------------------------------
TIBP_TSO_ExpressionParser::tag_ctx::~tag_ctx()
{;}

////////////////////////////////////////////////////////////////////////////////
//class TIBP_TSO_ExpressionParser

TIBP_TSO_ExpressionParser::TIBP_TSO_ExpressionParser
                                  (const TSYS_CommandLine* const pCL)
 :m_spSrvComparer
  (helper__createSrvComparer(pCL))
 ,m_spOdsComparer
  (helper__createOdsComparer(pCL))
 ,m_spDBDialectComparer
  (helper__createDBDialectComparer(pCL))
{;}

//------------------------------------------------------------------------
TIBP_TSO_ExpressionParser::~TIBP_TSO_ExpressionParser()
{;}

//------------------------------------------------------------------------
void TIBP_TSO_ExpressionParser::reg_macro(const char* const name,
                                          const char* const expression)
{
 assert(name);
 assert(expression);

 const size_t l_name=strlen(name);
 const size_t l_expression=strlen(expression);

 assert(l_name>0);
 assert(l_expression>0);

 const char* const n1=lib::structure::skip_spaces(name,name+l_name);
 const char* const n2=lib::structure::skip_spaces_back(n1,name+l_name);

 assert(n1!=n2);

 assert(lib::structure::skip_spaces(expression,expression+l_expression)!=(expression+l_expression));

 //-----------------------------------------
 if(!m_macroses.insert(macroses_type::value_type(std::string(n1,n2),expression)).second)
 {
  structure::str_formatter fmsg("[BUG FIX] expression macros \"%1\" already defined");

  fmsg<<lib::structure::t_const_str_box(n1,n2-n1);

  throw std::runtime_error(fmsg.str());
 }//if
}//reg_macro

//------------------------------------------------------------------------
TIBP_TSO_ExpressionParser::calc_result_type
 TIBP_TSO_ExpressionParser::calc(expression_box_type const exp_str)const
{
 CHECK_READ_TYPED_PTR(exp_str.ptr,exp_str.len);

 ctx_type ctx(&exp_str);

 this->get_token(ctx);

 if(ctx.m_last_token.empty())
  return calc_result__empty_cond;

 const bool result=this->process_1_or(ctx);

 //TODO: syntax error
 if(!ctx.m_last_token.empty())
  this->helper__throw_error(ctx,"Syntax error");

 if(result)
  return calc_result__yes;

 return calc_result__no;
}//calc

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionParser::process_1_or(ctx_type& ctx)const
{
 bool result=this->process_2_and(ctx);

 while(ctx.m_last_token == "||")
 {
  this->get_token(ctx);

  bool const temp=this->process_2_and(ctx);

  result = (result || temp);
 }//while

 return result;
}//process_1_or

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionParser::process_2_and(ctx_type& ctx)const
{
 bool result=this->process_3_not(ctx);

 while(ctx.m_last_token == "&&")
 {
  this->get_token(ctx);

  bool const temp=this->process_3_not(ctx);

  result = (result && temp);
 }

 return result;
}//process_2_and

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionParser::process_3_not(ctx_type& ctx)const
{
 if(ctx.m_last_token == "!")
 {
  this->get_token(ctx);

  return !this->process_4_bracket(ctx);
 }//if

 return this->process_4_bracket(ctx);
}//process_3_not

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionParser::process_4_bracket(ctx_type& ctx)const
{
 if(ctx.m_last_token=="(")
 {
  this->get_token(ctx);

  const bool result=this->process_1_or(ctx);

  if(ctx.m_last_token!=")")
   this->helper__throw_error(ctx,"No close bracket");

  this->get_token(ctx);

  return result;
 }//if

 return this->process_term(ctx);
}//process_4_bracket

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionParser::process_term(ctx_type& ctx)const
{
 if(ctx.m_last_token_type != type_ident)
  this->helper__throw_error(ctx,"Syntax error");

 //-----------------------------------------
 for(;;)
 {
  const macroses_type::const_iterator im=m_macroses.find(ctx.m_last_token);

  if(im==m_macroses.end())
   break;

  this->get_token(ctx);

  //! \todo
  //!  –еализовать контроль зацикливани€ вычислений (задействовать трассу вызовов).

  //! \todo
  //!  ¬ случае вычислени€ значени€ макроса, добавл€ть сведени€ об его имени.

  switch(const auto r=this->calc((*im).second))
  {
   case calc_result__no:
    return false;

   case calc_result__yes:
    return true;

   default:
   {
    structure::str_formatter
     fmsg("unknown expression result of macros [%1]: %2.");

    fmsg<<(*im).first<<r;

    throw std::runtime_error(fmsg.str());
   }//default
  }//switch

  //мы не должны попадать в эту точку
  assert(false);
 }//for[ever]

 //-----------------------------------------
 const comparer_cptr
  spComparer(this->helper__get_comparer(ctx.m_last_token));

 if(!spComparer)
  this->helper__throw_error(ctx,"Unknown identificator");

 this->get_token(ctx);

 if(ctx.m_last_token_type!=type_delimiter)
  this->helper__throw_error(ctx,"Syntax error");

 const expression_str_type statement_token(ctx.m_last_token);

 this->get_token(ctx);

 if(ctx.m_last_token_type!=type_ident)
  this->helper__throw_error(ctx,"Syntax error");

 bool result=false;

 if(statement_token=="==")
  result=((*spComparer) == ctx.m_last_token);
 else
 if(statement_token==">")
  result=((*spComparer) > ctx.m_last_token);
 else
 if(statement_token=="<")
  result=((*spComparer) < ctx.m_last_token);
 else
 if(statement_token==">=")
  result=((*spComparer) >= ctx.m_last_token);
 else
 if(statement_token=="<=")
  result=((*spComparer) <= ctx.m_last_token);
 else
 if(statement_token=="!=")
  result=((*spComparer) != ctx.m_last_token);
 else
  this->helper__throw_error(ctx,"Unknown operator");

 this->get_token(ctx);

 return result;
}//process_term

//------------------------------------------------------------------------
void TIBP_TSO_ExpressionParser::get_token(ctx_type& ctx)const
{
 ctx.m_last_token.clear();

 ctx.m_last_token_type = type_none;

 for(;;)
 {
  //end expression
  if(ctx.m_exp_pos==ctx.m_exp_end)
   return;

  //skip space
  if(!helper__is_space(*ctx.m_exp_pos))
   break;

  ++ctx.m_exp_pos;
 }//for[ever]

 assert(ctx.m_exp_pos!=ctx.m_exp_end);

 //if operator
 if(helper__is_operator(*ctx.m_exp_pos))
 {
  for(;;)
  {
   ctx.m_last_token+=(*ctx.m_exp_pos);

   ++ctx.m_exp_pos;

   if(!helper__is_operator(*ctx.m_exp_pos))
    break;
  }//for[ever]

  ctx.m_last_token_type=type_delimiter;
 }
 else //if bracket
 if(helper__is_bracket(*ctx.m_exp_pos))
 {
  ctx.m_last_token+=(*ctx.m_exp_pos);

  ++ctx.m_exp_pos;

  ctx.m_last_token_type=type_delimiter;
 }
 else//if identificator
 {
  while(ctx.m_exp_pos!=ctx.m_exp_end && !helper__is_delimiter(*ctx.m_exp_pos))
  {
   ctx.m_last_token+=(*ctx.m_exp_pos);

   ++ctx.m_exp_pos;
  }//while

  ctx.m_last_token_type=type_ident;
 }//else

}//get_token

//------------------------------------------------------------------------
const TIBP_TSO_ExpressionParser::expression_element
 TIBP_TSO_ExpressionParser::sm_space_symbols[]
  ={' ','\t','\r','\n'};

bool TIBP_TSO_ExpressionParser::helper__is_space(const expression_element c)
{
 return std::find(sm_space_symbols,_END_(sm_space_symbols),c)!=_END_(sm_space_symbols);
}//helper__is_space

//------------------------------------------------------------------------
const TIBP_TSO_ExpressionParser::expression_element
 TIBP_TSO_ExpressionParser::sm_bracket_symbols[]
  ={'(',')'};

bool TIBP_TSO_ExpressionParser::helper__is_bracket(const expression_element c)
{
 return std::find(sm_bracket_symbols,_END_(sm_bracket_symbols),c)!=_END_(sm_bracket_symbols);
}//helper__is_bracket

//------------------------------------------------------------------------
const TIBP_TSO_ExpressionParser::expression_element
 TIBP_TSO_ExpressionParser::sm_operator_symbols[]
  ={'<','>','!','=','|','&'};

bool TIBP_TSO_ExpressionParser::helper__is_operator(const expression_element c)
{
 return std::find(sm_operator_symbols,_END_(sm_operator_symbols),c)!=_END_(sm_operator_symbols);
}//helper__is_operator

//------------------------------------------------------------------------
bool TIBP_TSO_ExpressionParser::helper__is_delimiter(const expression_element c)
{
 if(helper__is_space(c))
  return true;

 if(helper__is_bracket(c))
  return true;

 if(helper__is_operator(c))
  return true;

 return false;
}//helper__is_delimiter

//------------------------------------------------------------------------
void TIBP_TSO_ExpressionParser::helper__throw_error(ctx_type&         ctx,
                                                    const char* const str)
{
 structure::str_formatter
  err_text("%1. Current position \"%2\". Last token \"%3\"");

 const expression_str_type
  current_pos(ctx.m_exp_beg, ctx.m_exp_pos);

 err_text<<str
         <<current_pos
         <<ctx.m_last_token;

 throw std::runtime_error(err_text.c_str());
}//helper__throw_error

//------------------------------------------------------------------------
TIBP_TSO_ExpressionParser::comparer_cptr
 TIBP_TSO_ExpressionParser::helper__get_comparer(const std::string& id)const
{
 if(id=="SRV")
 {
  if(!m_spSrvComparer)
   throw std::runtime_error("please define 'dbms' command line parameter");

  return m_spSrvComparer;
 }//if

 if(id=="ODS")
 {
  if(m_spOdsComparer)
   throw std::runtime_error("please define 'ods' command line parameter");

  return m_spOdsComparer;
 }//if


 if(id=="DBDIALECT")
 {
  if(m_spDBDialectComparer)
   throw std::runtime_error("please define 'dialect' command line parameter");

  return m_spDBDialectComparer;
 }//if

 structure::str_formatter fmsg("unknown expression parameter: '%1'");

 fmsg<<id;

 throw std::runtime_error(fmsg.str());
}//helper__get_comparer

//helper methods ---------------------------------------------------------
TIBP_TSO_ExpressionParser::comparer_cptr
 TIBP_TSO_ExpressionParser::helper__createSrvComparer
                                           (const TSYS_CommandLine* const pCL)
{
 assert(pCL);

 if(auto const v=pCL->args().get(c_prog_arg__dbms,false))
 {
  const auto pos=v->m_value.find('-');

  if(pos==v->m_value.npos)
   throw std::runtime_error("Incorrect format of 'dbms' parameter");

  assert(pos<v->m_value.size());

  const auto name=v->m_value.substr(0,pos);

  const auto version=v->m_value.substr(pos+1);

  if(name.empty() || version.empty())
   throw std::runtime_error("Incorrect format of 'dbms' parameter");

  return TIBP_TSO_ServerComparer::create
          (structure::tstr_to_str(name),
           structure::tstr_to_str(version));
 }//if

 return nullptr;
}//helper__createSrvComparer

//------------------------------------------------------------------------
TIBP_TSO_ExpressionParser::comparer_cptr
 TIBP_TSO_ExpressionParser::helper__createOdsComparer
                                           (const TSYS_CommandLine* const pCL)
{
 assert(pCL);

 if(auto const v=pCL->args().get(c_prog_arg__ods,false))
  return TIBP_TSO_VersionComparer::create(structure::tstr_to_str(v->m_value));

 return nullptr;
}//helper__createOdsComparer

//------------------------------------------------------------------------
TIBP_TSO_ExpressionParser::comparer_cptr
 TIBP_TSO_ExpressionParser::helper__createDBDialectComparer
                                           (const TSYS_CommandLine* const pCL)
{
 assert(pCL);

 if(auto const v=pCL->args().get(c_prog_arg__dialect,false))
  return TIBP_TSO_EqualComparer::create(structure::tstr_to_str(v->m_value));

 return nullptr;
}//helper__createDBDialectComparer

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
