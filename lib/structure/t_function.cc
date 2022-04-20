////////////////////////////////////////////////////////////////////////////////
//Implementation of templates from <t_function.h>
//                                                 Dmitry Kovalenko. 03.09.2003.
#ifndef _t_function_CC_
#define _t_function_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_auto_mem_fun

template<class S,class T>
t_auto_mem_fun<S,T>::~t_auto_mem_fun()
{
 assert(m_pmf!=NULL);

 try
 {
  (m_obj.*m_pmf)();
 }
 catch(...){;}
}//~t_auto_mem_fun

////////////////////////////////////////////////////////////////////////////////
//class t_auto_mem_fun_1

template<class S,class Arg1,class T>
t_auto_mem_fun_1<S,Arg1,T>::~t_auto_mem_fun_1()
{
 assert(m_pmf!=NULL);

 try
 {
  (m_obj.*m_pmf)(m_arg1);
 }
 catch(...){;}
}//~t_auto_mem_fun_1

////////////////////////////////////////////////////////////////////////////////
//class t_auto_fun

template<class TFunc>
t_auto_fun<TFunc>::~t_auto_fun()
{
 try
 {
  m_func();
 }
 catch(...){;}
}//~t_auto_fun

////////////////////////////////////////////////////////////////////////////////
//class t_auto_fun_1

template<class TFunc,class TArg1>
t_auto_fun_1<TFunc,TArg1>::~t_auto_fun_1()
{
 try
 {
  m_func(m_arg1);
 }
 catch(...){;}
}//~t_auto_fun_1

////////////////////////////////////////////////////////////////////////////////
//class t_binary_op_caller_ex

#if 0 // [2020-08-05] Bye

template<class TBinaryOp,class TFirstArgUnaryOp,class TSecondArgUnaryOp>
inline
 t_binary_op_caller_ex<TBinaryOp,TFirstArgUnaryOp,TSecondArgUnaryOp>::t_binary_op_caller_ex
                       (const binary_op_type&            binary_op,
                        const first_arg_unary_op_type&   first_arg_op,
                        const second_arg_unary_op_type&  second_arg_op)
 :m_binary_op     (binary_op),
  m_first_arg_op  (first_arg_op),
  m_second_arg_op (second_arg_op)
{;}

//------------------------------------------------------------------------
template<class TBinaryOp,class TFirstArgUnaryOp,class TSecondArgUnaryOp>
inline
typename t_binary_op_caller_ex<TBinaryOp,TFirstArgUnaryOp,TSecondArgUnaryOp>::result_type
 t_binary_op_caller_ex<TBinaryOp,TFirstArgUnaryOp,TSecondArgUnaryOp>::operator ()
                                           (first_argument_type  a,
                                            second_argument_type b)
{
 return m_binary_op(m_first_arg_op(a),m_second_arg_op(b));
}

////////////////////////////////////////////////////////////////////////////////

template<class TBinaryOp,class TFirstArgUnaryOp,class TSecondArgUnaryOp>
t_binary_op_caller_ex<TBinaryOp,TFirstArgUnaryOp,TSecondArgUnaryOp>
 binary_op_caller_ex(const TBinaryOp&         binary_op,
                     const TFirstArgUnaryOp&  first_arg_unary_op,
                     const TSecondArgUnaryOp& second_arg_unary_op)
{
 return t_binary_op_caller_ex<TBinaryOp,TFirstArgUnaryOp,TSecondArgUnaryOp>
         (binary_op,first_arg_unary_op,second_arg_unary_op);
}//binary_op_caller_ex

////////////////////////////////////////////////////////////////////////////////
//class t_binary_op_cref_wrapper

template<class TBinaryOp>
t_binary_op_cref_wrapper<TBinaryOp>::t_binary_op_cref_wrapper(const binary_op_type& op)
 :m_op(op)
{;}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE!=0)

template<class TBinaryOp>
template<typename TArg1,typename TArg2>
RELEASE_CODE(inline)
typename t_binary_op_cref_wrapper<TBinaryOp>::result_type
 t_binary_op_cref_wrapper<TBinaryOp>::operator () (const TArg1& a1,const TArg2& a2)const
{
 return m_op(a1,a2);
}//operator () (a1,a2)

#endif // COMP_CONF_SUPPORT_MEMBER_TEMPLATE!=0

////////////////////////////////////////////////////////////////////////////////

template<class TBinaryOp>
t_binary_op_cref_wrapper<TBinaryOp> binary_op_cref_wrapper(const TBinaryOp& op)
{
 return t_binary_op_cref_wrapper<TBinaryOp>(op);
}//binary_op_cref_wrapper

#endif // [2020-08-05] Bye

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
