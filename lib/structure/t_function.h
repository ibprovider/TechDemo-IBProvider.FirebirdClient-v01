////////////////////////////////////////////////////////////////////////////////
//Set of template utilities
//                                                Dmitry Kovalenko. 15.01.2000.
#ifndef _lcpi_lib_structure__t_function_H_
#define _lcpi_lib_structure__t_function_H_

#include <functional>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containing class

//class for call member-function -----------------------------------------
//all t_mem_proc_xxx has own template function for create

#if 0 // [2019-08-29] Good bye

template<class T>
 class t_mem_proc;

template<class T>
 class t_mem_proc_ref;

//call member-function of object -----------------------------------------
//function: mem_fun_call(T& obj,S (T::*pmf)(Arg))
template<class S,class T,class Arg>
 class t_mem_fun_call;

//const version
//function: mem_fun_call_const(const T& obj,S (T::*pmf)(Arg)const);
template<class S,class Arg1,class T>
 class t_mem_fun_call_const;

#endif // [2019-08-29] Good bye

//auto-call member-function of object ------------------------------------
template<class S,class T>
 class t_auto_mem_fun;

template<class S,class Arg1,class T>
 class t_auto_mem_fun_1;

//function auto-caller ---------------------------------------------------
template<class TFunc>
 class t_auto_fun;

template<class TFunc,class TArg1>
 class t_auto_fun_1;

//------------------------------------------------------------------------

#if 0 // [2020-08-05] Bye

//return BinaryOp(FirstArgUnaryOp(a),SecondArgUnaryOp(b))
template<class TBinaryOp,class TFirstArgUnaryOp,class TSecondArgUnaryOp>
 class t_binary_op_caller_ex;

//------------------------------------------------------------------------
template<class TBinaryOp>
class t_binary_op_cref_wrapper;

#endif // [2020-08-05] Bye

////////////////////////////////////////////////////////////////////////////////
//class t_mem_proc

#if 0 // [2019-08-29] Good bye

template<class T>
class t_mem_proc:public std::unary_function<T*,void>
{
 public:
  t_mem_proc(void (T::*pmf)())
   :m_pmf(pmf)
  {
  }

  void operator () (T* p)
  {
   assert(p!=NULL);

   (p->*m_pmf)();
  }

 private:
  void (T::*m_pmf)();
};//class t_mem_proc

//------------------------------------------------------------------------
template<class T>
inline t_mem_proc<T> mem_proc(void (T::*pmf)())
{
 return t_mem_proc<T>(pmf);
}//mem_proc

////////////////////////////////////////////////////////////////////////////////
//class t_mem_proc_ref

template<class T>
class t_mem_proc_ref:public std::unary_function<T*,void>
{
 public:
  t_mem_proc_ref(void (T::*pmf)())
   :m_pmf(pmf)
  {
  }

  void operator () (T& ref)
  {
   assert(m_pmf);

   (ref.*m_pmf)();
  }

 private:
  void (T::*m_pmf)();
};//class t_mem_proc_ref

//------------------------------------------------------------------------
template<class T>
inline t_mem_proc_ref<T> mem_proc_ref(void (T::*pmf)())
{
 return t_mem_proc_ref<T>(pmf);
}//mem_proc_ref

////////////////////////////////////////////////////////////////////////////////
//class t_mem_fun_call

template<class S,class T,class Arg>
class t_mem_fun_call:public std::unary_function<Arg,S>
{
 public:
  t_mem_fun_call(T& obj,S (T::*pmf)(Arg))
   :m_obj(obj)
   ,m_pmf(pmf)
  {
  }

  S operator () (Arg a)
  {
   assert(m_pmf!=NULL);

   return (m_obj.*m_pmf)(a);
  }

 private:
  T& m_obj;

  S (T::*m_pmf)(Arg);
};//class t_mem_fun_call

////////////////////////////////////////////////////////////////////////////////
//template func mem_fun_call

template<class S,class T,class Arg>
inline t_mem_fun_call<S,T,Arg> mem_fun_call(T& obj,S (T::*pmf)(Arg))
{
 return t_mem_fun_call<S,T,Arg>(obj,pmf);
}//mem_fun_call

////////////////////////////////////////////////////////////////////////////////
//class t_mem_fun_call_const

template<class S,class T,class Arg>
class t_mem_fun_call_const:public std::unary_function<Arg,S>
{
 public:
  t_mem_fun_call_const(const T& obj,S (T::*pmf)(Arg)const)
   :m_obj(obj)
   ,m_pmf(pmf)
  {
  }

  S operator () (Arg a)
  {
   assert(m_pmf!=NULL);

   return (m_obj.*m_pmf)(a);
  }

 private:
  const T& m_obj;

  S (T::*m_pmf)(Arg)const;
};//class t_mem_fun_call_const

////////////////////////////////////////////////////////////////////////////////
//template func mem_fun_call_const

template<class S,class T,class Arg>
inline t_mem_fun_call_const<S,T,Arg> mem_fun_call_const(const T& obj,S (T::*pmf)(Arg) const)
{
 return t_mem_fun_call_const<S,T,Arg>(obj,pmf);
}//mem_fun_call_const

#endif // [2019-08-29] Good bye

////////////////////////////////////////////////////////////////////////////////
//class t_auto_mem_fun

template<class S,class T>
class t_auto_mem_fun
{
 private:
  typedef t_auto_mem_fun<S,T> self_type;

  t_auto_mem_fun(const self_type&);
  self_type& operator = (const self_type&);

 public:
  t_auto_mem_fun(T& obj,S (T::*pmf)())
   :m_obj(obj)
   ,m_pmf(pmf)
  {
  }

 ~t_auto_mem_fun();

 private:
  T& m_obj;

  S (T::*m_pmf)();
};//class t_auto_mem_fun

////////////////////////////////////////////////////////////////////////////////
//class t_auto_mem_fun_1

template<class S,class Arg1,class T>
class t_auto_mem_fun_1
{
 private:
  typedef t_auto_mem_fun_1<S,Arg1,T> self_type;

  t_auto_mem_fun_1(const self_type&);
  self_type& operator = (const self_type&);

 public:
  t_auto_mem_fun_1(T& obj,const Arg1& arg1,S (T::*pmf)(Arg1))
   :m_obj (obj)
   ,m_arg1(arg1)
   ,m_pmf (pmf)
  {
  }

 ~t_auto_mem_fun_1();

 private:
  T&    m_obj;

  Arg1  m_arg1;

  S (T::*m_pmf)(Arg1);
};//class t_auto_mem_fun_1

////////////////////////////////////////////////////////////////////////////////
//class t_auto_fun

template<class TFunc>
class t_auto_fun
{
 private:
  typedef t_auto_fun<TFunc> self_type;

  t_auto_fun(const self_type&);
  self_type& operator = (const self_type&);

  TFunc  m_func;

 public:
  t_auto_fun(TFunc func)
   :m_func(func)
  {
  }

 ~t_auto_fun();
};//class t_auto_fun

////////////////////////////////////////////////////////////////////////////////
//class t_auto_fun_1

template<class TFunc,class TArg1>
class t_auto_fun_1
{
 private:
  typedef t_auto_fun_1<TFunc,TArg1> self_type;

  t_auto_fun_1(const self_type&);
  self_type& operator = (const self_type&);

  TFunc  m_func;
  TArg1  m_arg1;

 public:
  t_auto_fun_1(TFunc func,TArg1 arg1)
   :m_func(func),
    m_arg1(arg1)
   {
   }

 ~t_auto_fun_1();
};//class t_auto_fun_1

////////////////////////////////////////////////////////////////////////////////
//class t_binary_op_caller_ex

#if 0 // [2020-08-05] Bye

template<class TBinaryOp,class TFirstArgUnaryOp,class TSecondArgUnaryOp>
class t_binary_op_caller_ex
{
 public: //typedefs ------------------------------------------------------
  typedef TBinaryOp                              binary_op_type;
  typedef TFirstArgUnaryOp                       first_arg_unary_op_type;
  typedef TSecondArgUnaryOp                      second_arg_unary_op_type;

  typedef typename binary_op_type::first_argument_type  first_argument_type;
  typedef typename binary_op_type::second_argument_type second_argument_type;
  typedef typename binary_op_type::result_type          result_type;

 public:
  t_binary_op_caller_ex(const binary_op_type&           binary_op,
                        const first_arg_unary_op_type&  first_arg_op,
                        const second_arg_unary_op_type& second_arg_op);

  result_type operator () (first_argument_type  a,
                           second_argument_type b);

 private:
  binary_op_type           m_binary_op;
  first_arg_unary_op_type  m_first_arg_op;
  second_arg_unary_op_type m_second_arg_op;
};//t_binary_op_caller_ex

//------------------------------------------------------------------------
template<class TBinaryOp,class TFirstArgUnaryOp,class TSecondArgUnaryOp>
t_binary_op_caller_ex<TBinaryOp,TFirstArgUnaryOp,TSecondArgUnaryOp>
 binary_op_caller_ex(const TBinaryOp&         binary_op,
                     const TFirstArgUnaryOp&  first_arg_unary_op,
                     const TSecondArgUnaryOp& second_arg_unary_op);

////////////////////////////////////////////////////////////////////////////////
//class t_binary_op_ref_wrapper

template<class TBinaryOp>
class t_binary_op_cref_wrapper
{
 private:
  typedef t_binary_op_cref_wrapper<TBinaryOp>            self_type;

  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef TBinaryOp                                      binary_op_type;

  typedef typename TBinaryOp::result_type                result_type;

 public:
  t_binary_op_cref_wrapper(const binary_op_type& x);

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<typename TArg1,typename TArg2>
  result_type operator () (const TArg1& a1,const TArg2& a2)const;
 #endif // COMP_CONF_SUPPORT_MEMBER_TEMPLATE

 public:
  const binary_op_type& m_op;
};//class t_binary_op_cref_wrapper

//------------------------------------------------------------------------
template<class TBinaryOp>
t_binary_op_cref_wrapper<TBinaryOp> binary_op_cref_wrapper(const TBinaryOp& op);

#endif // [2020-08-05] Bye

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_function.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
