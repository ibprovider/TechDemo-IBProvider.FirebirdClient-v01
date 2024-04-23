////////////////////////////////////////////////////////////////////////////////
//Реализация шаблона t_basic_str_formatter
//                                        Коваленко Дмитрий. 8 января 2002 года.
#ifndef _lcpi_lib_structure__t_str_formatter_CC_
#define _lcpi_lib_structure__t_str_formatter_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//template class t_basic_str_formatter__fpart

template<class TString>
RELEASE_CODE(inline)
t_basic_str_formatter__fpart<TString>::t_basic_str_formatter__fpart()
 :is_arg(false)
{
}

//------------------------------------------------------------------------
template<class TString>
RELEASE_CODE(inline)
t_basic_str_formatter__fpart<TString>::t_basic_str_formatter__fpart
                                           (bool             const _is_arg,
                                            const char_type* const beg,
                                            const char_type* const end)
 :is_arg(_is_arg)
 ,value(beg,end)
{
}

//------------------------------------------------------------------------
template<class TString>
RELEASE_CODE(inline)
t_basic_str_formatter__fpart<TString>::t_basic_str_formatter__fpart
                                           (const self_type& x)
 :is_arg(x.is_arg)
 ,value (x.value)
{
}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class TString>
RELEASE_CODE(inline)
t_basic_str_formatter__fpart<TString>::t_basic_str_formatter__fpart
                                           (self_type&& x)
 :is_arg(LCPI_STL_MOVE_VALUE(x.is_arg))
 ,value (LCPI_STL_MOVE_VALUE(x.value))
{
}

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class TString>
t_basic_str_formatter__fpart<TString>&
 t_basic_str_formatter__fpart<TString>::operator = (const self_type& x)
{
 self_type tmp(x);

 this->swap(tmp);

 return *this;
}//copy operator

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class TString>
t_basic_str_formatter__fpart<TString>&
 t_basic_str_formatter__fpart<TString>::operator = (self_type&& x)
{
 self_type tmp(LCPI_STL_MOVE_VALUE(x));

 this->swap(tmp);

 return *this;
}//move operator

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class TString>
void t_basic_str_formatter__fpart<TString>::swap(self_type& x)
{
 std::swap(this->is_arg ,x.is_arg);
 std::swap(this->value  ,x.value);
}//swap

////////////////////////////////////////////////////////////////////////////////
//template class t_basic_str_formatter__arg_value

template<class TString>
t_basic_str_formatter__arg_value<TString>::t_basic_str_formatter__arg_value()
 :m_assign(false)
{
}

//------------------------------------------------------------------------
template<class TString>
t_basic_str_formatter__arg_value<TString>::t_basic_str_formatter__arg_value
                                           (const self_type& x)
 :m_value(x.m_value)
 ,m_assign(x.m_assign)
{
}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class TString>
t_basic_str_formatter__arg_value<TString>::t_basic_str_formatter__arg_value
                                           (self_type&& x)
 :m_value   (LCPI_STL_MOVE_VALUE(x.m_value))
 ,m_assign  (LCPI_STL_MOVE_VALUE(x.m_assign))
{
}

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class TString>
t_basic_str_formatter__arg_value<TString>&
 t_basic_str_formatter__arg_value<TString>::operator = (const self_type& x)
{
 self_type tmp(x);

 this->swap(tmp);

 return *this;
}//copy operator

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class TString>
t_basic_str_formatter__arg_value<TString>&
 t_basic_str_formatter__arg_value<TString>::operator = (self_type&& x)
{
 self_type tmp(LCPI_STL_MOVE_VALUE(x));

 this->swap(tmp);

 return *this;
}//move operator

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class TString>
RELEASE_CODE(inline)
void t_basic_str_formatter__arg_value<TString>::swap(self_type& x)
{
 std::swap(m_value   ,x.m_value);
 std::swap(m_assign  ,x.m_assign);
}//swap

//------------------------------------------------------------------------
template<class TString>
RELEASE_CODE(inline)
bool t_basic_str_formatter__arg_value<TString>::is_assigned()const
{
 return m_assign;
}//is_assigned

//------------------------------------------------------------------------
template<class TString>
RELEASE_CODE(inline)
const typename t_basic_str_formatter__arg_value<TString>::string_type&
 t_basic_str_formatter__arg_value<TString>::get_value()const
{
 return m_value;
}//get_value

//------------------------------------------------------------------------
template<class TString>
RELEASE_CODE(inline)
void t_basic_str_formatter__arg_value<TString>::set_value(const string_type& v)
{
 m_value =v;
 m_assign=true;
}//set_value

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class TString>
RELEASE_CODE(inline)
void t_basic_str_formatter__arg_value<TString>::set_value(string_type&& v)
{
 m_value =LCPI_STL_MOVE_VALUE(v);
 m_assign=true;
}//set_value

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class TString>
RELEASE_CODE(inline)
void t_basic_str_formatter__arg_value<TString>::reset()
{
 m_value.erase();
 m_assign=false;
}//reset

////////////////////////////////////////////////////////////////////////////////
//template class t_basic_str_formatter

//constructors -----------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>::t_basic_str_formatter()
 :m_modes        (self_type::fl_defaults)
 ,m_next_num_arg (first_num_arg_idx)
{
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>::t_basic_str_formatter
                                           (str_box_type const fstr)
 :m_modes        (self_type::fl_defaults)
 ,m_next_num_arg (first_num_arg_idx)
{
 this->init(fstr);
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>::t_basic_str_formatter
                                           (const char_type* const fstr,
                                            size_type        const n)
 :m_modes         (self_type::fl_defaults)
 ,m_next_num_arg  (first_num_arg_idx)
{
 this->init(fstr,n);
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>::t_basic_str_formatter
                                           (const self_type& x)
 :m_traits       (x.m_traits)
 ,m_modes        (x.m_modes)
 ,m_fparts       (x.m_fparts)
 ,m_args         (x.m_args)
 ,m_next_num_arg (x.m_next_num_arg)
 ,m_result       (x.m_result)
{
}

//------------------------------------------------------------------------
 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>::t_basic_str_formatter
                                           (self_type&& x)
 :m_traits       (LCPI_STL_MOVE_VALUE(x.m_traits))
 ,m_modes        (LCPI_STL_MOVE_VALUE(x.m_modes))
 ,m_fparts       (LCPI_STL_MOVE_VALUE(x.m_fparts))
 ,m_args         (LCPI_STL_MOVE_VALUE(x.m_args))
 ,m_next_num_arg (LCPI_STL_MOVE_VALUE(x.m_next_num_arg))
 ,m_result       (LCPI_STL_MOVE_VALUE(x.m_result))
{
}

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
#if !defined( __BCPLUSPLUS__) || (__BCPLUSPLUS__>0x0530)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>::~t_basic_str_formatter()
{
}

#endif //!defined( __BCPLUSPLUS__) || (__BCPLUSPLUS__>0x0530

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator = (const self_type& x)
{
 self_type tmp(x);

 this->swap(tmp);

 return *this;
}//copy operator

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator = (self_type&& x)
{
 self_type tmp(LCPI_STL_MOVE_VALUE(x));

 this->swap(tmp);

 return *this;
}//move operator

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
void t_basic_str_formatter<charT,traits,allocator>::swap(self_type& x)
{
 std::swap(m_traits       ,x.m_traits);
 std::swap(m_modes        ,x.m_modes);
 std::swap(m_fparts       ,x.m_fparts);
 std::swap(m_args         ,x.m_args);
 std::swap(m_next_num_arg ,x.m_next_num_arg);
 std::swap(m_result       ,x.m_result);
}//swap

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
t_basic_str_formatter<charT,traits,allocator>::flush()
{
 for(typename args_type::iterator i(m_args.begin()),_e(m_args.end());i!=_e;++i)
  (*i).second.reset();

 m_next_num_arg=self_type::first_num_arg_idx;

 return *this;
}//flush

//prepare string ---------------------------------------------------------
template<class charT,class traits,class allocator>
RELEASE_CODE(inline)
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::init(const str_box_type fstr)
{
 return this->init(fstr.data(),fstr.size());
}//init

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::init(const char_type* const fstr,
                                                     size_type              n)
{
 //[2011-09-10]
 assert(!structure::is_negative_one(n));

 if(fstr==nullptr)
  n=0;
 else
 if(structure::is_negative_one(n))
  n=m_traits.length(fstr);

 m_fparts.clear();
 m_args.clear();
 m_next_num_arg=first_num_arg_idx;

 //не инициализируем m_result, поскольку может быть
 //использована конструкция *this(*this) !

 const char_type*       cur(fstr);
 const char_type* const end(fstr+n);
 const char_type*       beg;

 while(cur!=end)
 {
  beg=cur;

  //search parameter prefix (%1)
  //BCB3 bug: use const_cast
  cur=std::find(cur,const_cast<const char_type*>(end),m_traits.arg_prefix());

  //добавляем пропущенный участок текста
  this->append_fpart(false,beg,cur);

  if(cur==end)
   break;

  //save position of prefix argument
  const char_type* const prefix=cur;

  ++cur;//miss arg prefix

  if(cur==end)
   break;

  if(*cur==m_traits.arg_prefix()) //double arg prefix
  {
   this->append_fpart(false,cur,cur+1);
   ++cur;
  }
  else
  {
   beg=cur;

   if((m_modes&fl_support_number_arg) && m_traits.is_digit(*cur))
   {
    for(++cur;cur!=end && m_traits.is_digit(*cur);++cur);

    m_fparts.push_back(fpart_type(true,beg,cur));

    //registry arg name
    m_args[string_type(beg,cur)];
   }
   else
   if((m_modes&fl_support_named_arg) && m_traits.is_first_named_arg_char(*cur))
   {
    //param1="a"
    //param2="b"
    //
    //%param1 other_text     ->"a other_text"
    //%param1%other_text     ->"aother_text"
    //%param1%%param2        ->"ab"
    //%param1%%param2%       ->"ab"
    //%param1%%param2%%%     ->"ab%"

    for(++cur;cur!=end && m_traits.is_second_named_param_char(*cur);++cur);

    m_fparts.push_back(fpart_type(true,beg,cur));

    //registry arg name
    m_args[string_type(beg,cur)];

    if(cur!=end && (*cur)==m_traits.arg_prefix()) //skip end arg prefix
     ++cur;
   }//elif - named param
   else
   if((m_modes&fl_support_mult_arg) && m_traits.is_mult_arg_char(*cur))
   {
    //special argument of template - %*
    ++cur;

    m_fparts.push_back(fpart_type(true,beg,cur));

    //registry arg name
    m_args[string_type(beg,cur)];
   }
   else
   if(m_modes&fl_save_prefix_of_unknown_arg)
   {
    this->append_fpart(false,prefix,prefix+1);
   }
  }//else
 }//while

 return *this;
}//init

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator () (str_box_type const fstr)
{
 return this->init(fstr);
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator () (const char_type* const fstr,
                                                             size_type        const n)
{
 return this->init(fstr,n);
}

//append simple text -----------------------------------------------------
template<class charT,class traits,class allocator>
inline
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::add_text(str_box_type const text)
{
 return this->add_text(text.ptr,text.len);
}//add_text

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
t_basic_str_formatter<charT,traits,allocator>::add_text(const char_type* const text,
                                                        size_type              n)
{
 //[2011-09-10]
 assert(!structure::is_negative_one(n));

 if(text==nullptr)
  n=0;
 else
 if(structure::is_negative_one(n))
  n=m_traits.length(text);

 this->append_fpart(false,text,text+n);

 return *this;
}//add_text

//append template part ---------------------------------------------------
template<class charT,class traits,class allocator>
void
t_basic_str_formatter<charT,traits,allocator>::append_fpart(const bool       is_arg,
                                                            const char_type* beg,
                                                            const char_type* end)
{
 assert(beg<=end);
 assert(!is_arg || beg<end);

 if(beg==end)
  return;

 if(!is_arg && !m_fparts.empty() && !m_fparts.back().is_arg)
  m_fparts.back().value.append(beg,end);
 else
  m_fparts.push_back(fpart_type(is_arg,beg,end));
}//append_fpart

//generate format string -------------------------------------------------
template<class charT,class traits,class allocator>
const typename t_basic_str_formatter<charT,traits,allocator>::string_type&
t_basic_str_formatter<charT,traits,allocator>::str()const
{
 m_result.erase();

 typename args_type::const_iterator       i_arg;
 typename args_type::const_iterator const e_arg(m_args.end());

 for(typename fparts_type::const_iterator i_fpart(m_fparts.begin()),
                                          e_fpart(m_fparts.end());
     i_fpart!=e_fpart;
     ++i_fpart)
 {
  if(!(*i_fpart).is_arg)
  {
   m_result.append((*i_fpart).value);
   continue;
  }

  if((i_arg=m_args.find((*i_fpart).value))!=e_arg && (*i_arg).second.is_assigned())
   m_result.append((*i_arg).second.get_value());
  else
   m_result.append(m_traits.no_defined((*i_fpart).value));
 }//for i_fpart

 return m_result;
}//str

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
t_basic_str_formatter<charT,traits,allocator>::push_next_num_arg(const string_type& value)
{
 m_args[m_traits.arg_uint64(m_next_num_arg)].set_value(value);

 ++m_next_num_arg;

 return *this;
}//push_next_num_arg

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
t_basic_str_formatter<charT,traits,allocator>::push_next_num_arg(string_type&& value)
{
 m_args[m_traits.arg_uint64(m_next_num_arg)].set_value(LCPI_STL_MOVE_VALUE(value));

 ++m_next_num_arg;

 return *this;
}//push_next_num_arg

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//append arguments -------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (bool const value)
{
 return this->push_next_num_arg(m_traits.arg_bool(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (signed char const value)
{
 return this->push_next_num_arg(m_traits.arg_int(value)); // WAS ARG_LONG
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (unsigned char const value)
{
 return this->push_next_num_arg(m_traits.arg_uint(value));  // WAS ARG_ULONG
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (std::int16_t const value)
{
 return this->push_next_num_arg(m_traits.arg_int(value)); // WAS ARG_LONG
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (std::uint16_t const value)
{
 return this->push_next_num_arg(m_traits.arg_uint(value)); // WAS ARG_ULONG
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (std::int32_t const value)
{
 return this->push_next_num_arg(m_traits.arg_int(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (std::uint32_t const value)
{
 return this->push_next_num_arg(m_traits.arg_uint(value));
}

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (signed long const value)
{
 return this->push_next_num_arg(m_traits.arg_long(value));
}

#endif

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (unsigned long const value)
{
 return this->push_next_num_arg(m_traits.arg_ulong(value));
}

#endif

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (std::int64_t const value)
{
 return this->push_next_num_arg(m_traits.arg_int64(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (std::uint64_t const value)
{
 return this->push_next_num_arg(m_traits.arg_uint64(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (float const value)
{
 return this->push_next_num_arg(m_traits.arg_float(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (double const value)
{
 return this->push_next_num_arg(m_traits.arg_double(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (long double const value)
{
 return this->push_next_num_arg(m_traits.arg_long_double(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (const char* const value)
{
 return this->push_next_num_arg(m_traits.arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (const std::string& value)
{
 return this->push_next_num_arg(m_traits.arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (const wchar_t* const value)
{
 return this->push_next_num_arg(m_traits.arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (const std::wstring& value)
{
 return this->push_next_num_arg(m_traits.arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (const asymbol_type& value)
{
 return this->push_next_num_arg(m_traits.arg_str2(&value.symbol,1));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (const wsymbol_type& value)
{
 return this->push_next_num_arg(m_traits.arg_str2(&value.symbol,1));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (const astr_box_type& value)
{
 return this->push_next_num_arg(traits_type::arg_str2(value.data(),value.size()));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (const wstr_box_type& value)
{
 return this->push_next_num_arg(traits_type::arg_str2(value.data(),value.size()));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (const astr_param_type& value)
{
 return this->push_next_num_arg(m_traits.arg_str(value.c_str()));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (const wstr_param_type& value)
{
 return this->push_next_num_arg(m_traits.arg_str(value.c_str()));
}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (std::string&& value)
{
 return this->push_next_num_arg(m_traits.arg_str(LCPI_STL_MOVE_VALUE(value)));
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (std::wstring&& value)
{
 return this->push_next_num_arg(m_traits.arg_str(LCPI_STL_MOVE_VALUE(value)));
}

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
RELEASE_CODE(inline)
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::operator << (t_fmsg_manip const f)
{
 return f(*this);
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
RELEASE_CODE(inline)
const typename t_basic_str_formatter<charT,traits,allocator>::char_type*
 t_basic_str_formatter<charT,traits,allocator>::operator << (t_fmsg_getter1 const g)
{
 return g(*this);
}

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
RELEASE_CODE(inline)
const typename t_basic_str_formatter<charT,traits,allocator>::string_type&
 t_basic_str_formatter<charT,traits,allocator>::operator << (t_fmsg_getter2 const g)
{
 return g(*this);
}

//direct assign args values [by index] -----------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_num_arg
                                                (const num_arg_index_type idx,
                                                 const string_type&       value)
{
 m_args[m_traits.arg_uint64(idx)].set_value(value);

 return *this;
}//set_num_arg

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_num_arg
                                                (const num_arg_index_type idx,
                                                 string_type&&            value)
{
 m_args[m_traits.arg_uint64(idx)].set_value(LCPI_STL_MOVE_VALUE(value));

 return *this;
}//set_num_arg

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    bool               const value)
{
 return this->set_num_arg(idx,m_traits.arg_bool(value));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    signed char        const value)
{
 return this->set_num_arg(idx,m_traits.arg_int(value)); // WAS ARG_LONG
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    unsigned char      const value)
{
 return this->set_num_arg(idx,m_traits.arg_uint(value)); // WAS ARG_ULONG
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    std::int16_t       const value)
{
 return this->set_num_arg(idx,m_traits.arg_int(value)); // WAS ARG_LONG
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    std::uint16_t      const value)
{
 return this->set_num_arg(idx,m_traits.arg_uint(value)); // WAS ARG_ULONG
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    std::int32_t       const value)
{
 return this->set_num_arg(idx,m_traits.arg_int(value));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    std::uint32_t      const value)
{
 return this->set_num_arg(idx,m_traits.arg_uint(value));
}//set

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    signed long        const value)
{
 return this->set_num_arg(idx,m_traits.arg_long(value));
}//set

#endif

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    unsigned long      const value)
{
 return this->set_num_arg(idx,m_traits.arg_ulong(value));
}//set

#endif

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    std::int64_t       const value)
{
 return this->set_num_arg(idx,m_traits.arg_int64(value));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    std::uint64_t      const value)
{
 return this->set_num_arg(idx,m_traits.arg_uint64(value));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    float              const value)
{
 return this->set_num_arg(idx,m_traits.arg_float(value));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    double             const value)
{
 return this->set_num_arg(idx,m_traits.arg_double(value));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    long double        const value)
{
 return this->set_num_arg(idx,m_traits.arg_long_double(value));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    const char*        const str)
{
 return this->set_num_arg(idx,m_traits.arg_str(str));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    const std::string&       str)
{
 return this->set_num_arg(idx,m_traits.arg_str(str));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    const wchar_t*     const str)
{
 return this->set_num_arg(idx,m_traits.arg_str(str));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    const std::wstring&      wstr)
{
 return this->set_num_arg(idx,m_traits.arg_str(wstr));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    const asymbol_type&      value)
{
 return this->set_num_arg(idx,m_traits.arg_str2(&value.symbol,1));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    const wsymbol_type&      value)
{
 return this->set_num_arg(idx,m_traits.arg_str2(&value.symbol,1));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    const astr_param_type&   str)
{
 return this->set_num_arg(idx,m_traits.arg_str(str.c_str()));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    const wstr_param_type&   str)
{
 return this->set_num_arg(idx,m_traits.arg_str(str.c_str()));
}//set

//------------------------------------------------------------------------

#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    std::string&&            str)
{
 return this->set_num_arg(idx,m_traits.arg_str(LCPI_STL_MOVE_VALUE(str)));
}//set

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set(num_arg_index_type const idx,
                                                    std::wstring&&           str)
{
 return this->set_num_arg(idx,m_traits.arg_str(LCPI_STL_MOVE_VALUE(str)));
}//set

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//direct assign args values [by name] ------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            bool          const value)
{
 return this->set_named_arg(name,m_traits.arg_bool(value));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            signed char   const value)
{
 return this->set_named_arg(name,m_traits.arg_int(value)); // WAS ARG_LONG
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            unsigned char const value)
{
 return this->set_named_arg(name,m_traits.arg_uint(value)); // WAS ARG_ULONG
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            std::int16_t  const value)
{
 return this->set_named_arg(name,m_traits.arg_int(value)); // WAS ARG_LONG
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type  const name,
                                                            unsigned short const value)
{
 return this->set_named_arg(name,m_traits.arg_uint(value)); // WAS ARG_ULONG
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            std::int32_t  const value)
{
 return this->set_named_arg(name,m_traits.arg_int(value));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            std::uint32_t const value)
{
 return this->set_named_arg(name,m_traits.arg_uint(value));
}//set_by_name

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            signed long   const value)
{
 return this->set_named_arg(name,m_traits.arg_long(value));
}//set_by_name

#endif

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            unsigned long const value)
{
 return this->set_named_arg(name,m_traits.arg_ulong(value));
}//set_by_name

#endif

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            std::int64_t  const value)
{
 return this->set_named_arg(name,m_traits.arg_int64(value));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            std::uint64_t const value)
{
 return this->set_named_arg(name,m_traits.arg_uint64(value));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            float         const value)
{
 return this->set_named_arg(name,m_traits.arg_float(value));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            double        const value)
{
 return this->set_named_arg(name,m_traits.arg_double(value));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            long double   const value)
{
 return this->set_named_arg(name,m_traits.arg_long_double(value));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            const char*   const str)
{
 return this->set_named_arg(name,m_traits.arg_str(str));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            const std::string&  str)
{
 return this->set_named_arg(name,m_traits.arg_str(str));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type  const name,
                                                            const wchar_t* const wstr)
{
 return this->set_named_arg(name,m_traits.arg_str(wstr));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            const std::wstring& wstr)
{
 return this->set_named_arg(name,m_traits.arg_str(wstr));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            const asymbol_type& value)
{
 return this->set_named_arg(name,m_traits.arg_str2(&value.symbol,1));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            const wsymbol_type& value)
{
 return this->set_named_arg(name,m_traits.arg_str2(&value.symbol,1));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const    name,
                                                            const astr_param_type& str)
{
 return this->set_named_arg(name,m_traits.arg_str(str.c_str()));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type    const name,
                                                            const wstr_param_type& wstr)
{
 return this->set_named_arg(name,m_traits.arg_str(wstr.c_str()));
}//set_by_name

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            std::string&&       str)
{
 return this->set_named_arg(name,m_traits.arg_str(LCPI_STL_MOVE_VALUE(str)));
}//set_by_name

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_by_name(name_arg_type const name,
                                                            std::wstring&&      wstr)
{
 return this->set_named_arg(name,m_traits.arg_str(LCPI_STL_MOVE_VALUE(wstr)));
}//set_by_name

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_named_arg(name_arg_type      name,
                                                              const string_type& value)
{
 assert(name.c_str());

 m_args[name.c_str()].set_value(value);

 return *this;
}//set_named_arg - copy value

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 t_basic_str_formatter<charT,traits,allocator>::set_named_arg(name_arg_type name,
                                                              string_type&& value)
{
 assert(name.c_str());

 m_args[name.c_str()].set_value(LCPI_STL_MOVE_VALUE(value));

 return *this;
}//set_named_arg - move value

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
