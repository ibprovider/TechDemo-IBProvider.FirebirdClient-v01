////////////////////////////////////////////////////////////////////////////////

//
// [2023-06-21]
//  These structures help solve a problem with C++20 and parameter with type T[].
//

template<typename T>
struct norm_closure_arg
{
 using type=T;
};//struct norm_closure_arg

template<typename T>
using norm_closure_arg_t=typename norm_closure_arg<T>::type;

////////////////////////////////////////////////////////////////////////////////
//class t_closure

template<class TResult,class...TARGS>
class t_closure COMP_W000006_CLASS_FINAL
{
 public: //typedefs
  typedef t_closure<TResult,TARGS...>   self_type;
  typedef closure_v3::__closure_data    think_type;

  //Type of pointer to caller function
  typedef TResult (*caller_type)(const think_type&,TARGS...);

 private:
  think_type    think;
  caller_type   caller;

 public:
  t_closure()
   :think()
   ,caller(nullptr)
  {;}

  t_closure(std::nullptr_t)
   :think()
   ,caller(nullptr)
  {;}

  t_closure(const think_type& _think,caller_type _caller)
   :think(_think)
   ,caller(_caller)
  {;}

  self_type& operator = (std::nullptr_t)
  {
   return *this=self_type();
  }

  template<class... TARGS2>
  TResult operator () (TARGS2&&... args)const
  {
   assert((bool)(*this));
   return caller(this->think,std::forward<TARGS2>(args)...);
  }

  operator bool () const
  {
   return this->think.valid() && this->caller;
  }

  bool operator ! () const
  {
   return !((bool)(*this));
  }
};//class t_closure

////////////////////////////////////////////////////////////////////////////////

template<class TResult,class...TARGS>
inline bool operator == (const t_closure<TResult,TARGS...>& x,std::nullptr_t /*v*/)
{
 return !x;
}//operator x==nullptr

template<class TResult,class...TARGS>
inline bool operator == (std::nullptr_t /*v*/,const t_closure<TResult,TARGS...>& x)
{
 return !x;
}//operator nullptr==x

//------------------------------------------------------------------------
template<class TResult,class...TARGS>
inline bool operator != (const t_closure<TResult,TARGS...>& x,std::nullptr_t /*v*/)
{
 return (bool)x;
}//operator x!=nullptr

template<class TResult,class...TARGS>
inline bool operator != (std::nullptr_t /*v*/,const t_closure<TResult,TARGS...>& x)
{
 return (bool)x;
}//operator nullptr!=x

////////////////////////////////////////////////////////////////////////////////
//class t_closure_caller_f

template<typename PFunc,class TResult,class ...TARGS>
class t_closure_caller_f COMP_W000006_CLASS_FINAL
{
 public: //typedefs
  typedef closure_v3::__closure_data think_type;

 public:
  static TResult call(const think_type& think,TARGS... args)
  {
   assert(think.valid());

   return reinterpret_cast<const PFunc>(think.buffer[0])(std::forward<TARGS>(args)...);
  }//call
};//class t_closure_caller_f

////////////////////////////////////////////////////////////////////////////////
//class t_closure_caller

template<class TObj,typename TMemFunc,class TResult,class ...TARGS>
class t_closure_caller COMP_W000006_CLASS_FINAL
{
 public: //typedefs
  typedef closure_v3::__closure_data think_type;

 public:
  static TResult call(const think_type& think,TARGS... args)
  {
   assert(think.valid());

   assert_msg(sizeof(TMemFunc)<=sizeof(think_type().buffer),
              "s1="<<sizeof(TMemFunc)<<" s2="<<sizeof(think_type().buffer));

   return (reinterpret_cast<TObj*>(think.object_ptr)->*
           (*reinterpret_cast<const TMemFunc*>(think.buffer)))(std::forward<TARGS>(args)...);
  }//call
};//class t_closure_caller

////////////////////////////////////////////////////////////////////////////////

#if(COMP_CONF_SUPPORT_CDECL_MEMBER)

template<class TResult,class ...TARGS>
t_closure<TResult,norm_closure_arg_t<TARGS>...> make_closure_r(TResult (__cdecl *pFunc)(TARGS...))
{
 typedef closure_v3::__closure_data                               think_type;
 typedef TResult (__cdecl *PFunc)(TARGS...);
 typedef t_closure_caller_f<PFunc,TResult,TARGS...>               caller_type;
 typedef t_closure<TResult,norm_closure_arg_t<TARGS>...>          closure_type;

 return closure_type(think_type(pFunc),caller_type::call);
}//make_closure_r

//------------------------------------------------------------------------------
template<class TObj,class TResult,class ...TARGS>
t_closure<TResult,norm_closure_arg_t<TARGS>...> make_closure_r(TObj* obj,TResult (__cdecl TObj::*MemFunc)(TARGS...))
{
 typedef closure_v3::__closure_data                               think_type;
 typedef TResult (__cdecl TObj::*mem_func_type)(TARGS...);
 typedef t_closure_caller<TObj,mem_func_type,TResult,TARGS...>    caller_type;
 typedef t_closure<TResult,norm_closure_arg_t<TARGS>...>          closure_type;

 assert_msg(sizeof(MemFunc)<=sizeof(think_type().buffer),
            "s1="<<sizeof(MemFunc)<<" s2="<<sizeof(think_type().buffer));

 return closure_type(think_type(obj,&MemFunc,sizeof(MemFunc)),caller_type::call);
}//make_closure_r

//------------------------------------------------------------------------------
template<class TObj,class TResult,class ...TARGS>
t_closure<TResult,norm_closure_arg_t<TARGS>...> make_closure_r(TObj* obj,TResult (__cdecl TObj::*MemFunc)(TARGS...)const)
{
 typedef closure_v3::__closure_data                               think_type;
 typedef TResult (__cdecl TObj::*mem_func_type)(TARGS...)const;
 typedef t_closure_caller<TObj,mem_func_type,TResult,TARGS...>    caller_type;
 typedef t_closure<TResult,norm_closure_arg_t<TARGS>...>          closure_type;

 assert_msg(sizeof(MemFunc)<=sizeof(think_type().buffer),
            "s1="<<sizeof(MemFunc)<<" s2="<<sizeof(think_type().buffer));

 return closure_type(think_type(obj,&MemFunc,sizeof(MemFunc)),caller_type::call);
}//make_closure_r - const

#endif //COMP_CONF_SUPPORT_CDECL_MEMBER

////////////////////////////////////////////////////////////////////////////////

#if(COMP_CONF_SUPPORT_STDCALL_MEMBER)

template<class TResult,class ...TARGS>
t_closure<TResult,norm_closure_arg_t<TARGS>...> make_closure_r(TResult (__stdcall *pFunc)(TARGS...))
{
 typedef closure_v3::__closure_data                               think_type;
 typedef TResult (__stdcall *PFunc)(TARGS...);
 typedef t_closure_caller_f<PFunc,TResult,TARGS...>               caller_type;
 typedef t_closure<TResult,norm_closure_arg_t<TARGS>...>          closure_type;

 return closure_type(think_type(pFunc),caller_type::call);
}//make_closure_r

//------------------------------------------------------------------------------
template<class TObj,class TResult,class ...TARGS>
t_closure<TResult,norm_closure_arg_t<TARGS>...> make_closure_r(TObj* obj,TResult (__stdcall TObj::*MemFunc)(TARGS...))
{
 typedef closure_v3::__closure_data                               think_type;
 typedef TResult (__stdcall TObj::*mem_func_type)(TARGS...);
 typedef t_closure_caller<TObj,mem_func_type,TResult,TARGS...>    caller_type;
 typedef t_closure<TResult,norm_closure_arg_t<TARGS>...>          closure_type;

 assert_msg(sizeof(MemFunc)<=sizeof(think_type().buffer),
            "s1="<<sizeof(MemFunc)<<" s2="<<sizeof(think_type().buffer));

 return closure_type(think_type(obj,&MemFunc,sizeof(MemFunc)),caller_type::call);
}//make_closure_r

//------------------------------------------------------------------------
template<class TObj,class TResult,class ...TARGS>
t_closure<TResult,norm_closure_arg_t<TARGS>...> make_closure_r(TObj* obj,TResult (__stdcall TObj::*MemFunc)(TARGS...)const)
{
 typedef closure_v3::__closure_data                               think_type;
 typedef TResult (__stdcall TObj::*mem_func_type)(TARGS...)const;
 typedef t_closure_caller<TObj,mem_func_type,TResult,TARGS...>    caller_type;
 typedef t_closure<TResult,norm_closure_arg_t<TARGS>...>          closure_type;

 assert_msg(sizeof(MemFunc)<=sizeof(think_type().buffer),
            "s1="<<sizeof(MemFunc)<<" s2="<<sizeof(think_type().buffer));

 return closure_type(think_type(obj,&MemFunc,sizeof(MemFunc)),caller_type::call);
}//make_closure_r - const

#endif //COMP_CONF_SUPPORT_STDCALL_MEMBER

////////////////////////////////////////////////////////////////////////////////

#if(COMP_CONF_SUPPORT_THISCALL_MEMBER)
template<class TObj,class TResult,class ...TARGS>
t_closure<TResult,norm_closure_arg_t<TARGS>...> make_closure_r(TObj* obj,TResult (__thiscall TObj::*MemFunc)(TARGS...))
{
 typedef closure_v3::__closure_data                               think_type;
 typedef TResult (__thiscall TObj::*mem_func_type)(TARGS...);
 typedef t_closure_caller<TObj,mem_func_type,TResult,TARGS...>    caller_type;
 typedef t_closure<TResult,norm_closure_arg_t<TARGS>...>          closure_type;

 assert_msg(sizeof(MemFunc)<=sizeof(think_type().buffer),
            "s1="<<sizeof(MemFunc)<<" s2="<<sizeof(think_type().buffer));

 return closure_type(think_type(obj,&MemFunc,sizeof(MemFunc)),caller_type::call);
}//make_closure_r

//------------------------------------------------------------------------------
template<class TObj,class TResult,class ...TARGS>
t_closure<TResult,norm_closure_arg_t<TARGS>...> make_closure_r(TObj* obj,TResult (__thiscall TObj::*MemFunc)(TARGS...)const)
{
 typedef closure_v3::__closure_data                               think_type;
 typedef TResult (__thiscall TObj::*mem_func_type)(TARGS...)const;
 typedef t_closure_caller<TObj,mem_func_type,TResult,TARGS...>    caller_type;
 typedef t_closure<TResult,norm_closure_arg_t<TARGS>...>          closure_type;

 assert_msg(sizeof(MemFunc)<=sizeof(think_type().buffer),
            "s1="<<sizeof(MemFunc)<<" s2="<<sizeof(think_type().buffer));

 return closure_type(think_type(obj,&MemFunc,sizeof(MemFunc)),caller_type::call);
}//make_closure_r - const

#endif //COMP_CONF_SUPPORT_THISCALL_MEMBER

////////////////////////////////////////////////////////////////////////////////
