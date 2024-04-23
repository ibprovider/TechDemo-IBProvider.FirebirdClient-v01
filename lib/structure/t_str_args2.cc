////////////////////////////////////////////////////////////////////////////////
//Base class for string arguments/parameters managements
//                                                 Dmitry Kovalenko. 09.04.2024
#ifndef _lcpi_lib_structure__t_str_args2_CC_
#define _lcpi_lib_structure__t_str_args2_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_str_args2

template<class charT,class t_outer,class str_args_traits>
t_basic_str_args2<charT,t_outer,str_args_traits>::t_basic_str_args2()
{;}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
t_basic_str_args2<charT,t_outer,str_args_traits>::~t_basic_str_args2()
{;}

//append arguments -------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (bool value)
{
 return this->add_arg(traits_type::arg_bool(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (signed char value)
{
 return this->add_arg(traits_type::arg_long(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (unsigned char value)
{
 return this->add_arg(traits_type::arg_ulong(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (std::int16_t value)
{
 return this->add_arg(traits_type::arg_int(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (std::uint16_t value)
{
 return this->add_arg(traits_type::arg_uint(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (std::int32_t value)
{
 return this->add_arg(traits_type::arg_int(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (std::uint32_t value)
{
 return this->add_arg(traits_type::arg_uint(value));
}

//------------------------------------------------------------------------
#if(LCPI_CPP_CFG__CAN_USE__signed_long!=0)

template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (signed long value)
{
 return this->add_arg(traits_type::arg_long(value));
}

#endif

//------------------------------------------------------------------------
#if(LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)

template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (unsigned long value)
{
 return this->add_arg(traits_type::arg_ulong(value));
}

#endif

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (std::int64_t value)
{
 return this->add_arg(traits_type::arg_int64(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (std::uint64_t value)
{
 return this->add_arg(traits_type::arg_uint64(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (float value)
{
 return this->add_arg(traits_type::arg_float(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (double value)
{
 return this->add_arg(traits_type::arg_double(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (long double value)
{
 return this->add_arg(traits_type::arg_long_double(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (const char* value)
{
 return this->add_arg(traits_type::arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (const std::string& value)
{
 return this->add_arg(traits_type::arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (const wchar_t* value)
{
 return this->add_arg(traits_type::arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (const std::wstring& value)
{
 return this->add_arg(traits_type::arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (const t_symbol& value)
{
 return this->add_arg(string_type(1,value.symbol));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (const astr_param_type& value)
{
 return this->add_arg(traits_type::arg_str(value.c_str()));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (const wstr_param_type& value)
{
 return this->add_arg(traits_type::arg_str(value.c_str()));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (const astr_box_type& value)
{
 return this->add_arg(traits_type::arg_str2(value.data(),value.size()));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (const wstr_box_type& value)
{
 return this->add_arg(traits_type::arg_str2(value.data(),value.size()));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (const std::exception& exc)
{
 return this->add_arg__exc(exc);
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (manip1_type x)
{
 assert(x!=nullptr);

 return x(outer_type::build_outer_type(*this));
}

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
void t_basic_str_args2<charT,t_outer,str_args_traits>::operator << (manip2_type x)
{
 assert(x!=nullptr);

 x(outer_type::build_outer_type(*this));
}

//------------------------------------------------------------------------
#if (!COMP_CONF_STABLE_PURE_METHOD_IN_TEMPLATE)
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
 t_basic_str_args2<charT,t_outer,str_args_traits>::add_arg(const string_type& /*x*/)
{
 assert(false);

 return outer_type::build_outer_type(*this);
}//add_arg
#endif

//------------------------------------------------------------------------
template<class charT,class t_outer,class str_args_traits>
typename t_basic_str_args2<charT,t_outer,str_args_traits>::outer_type&
 t_basic_str_args2<charT,t_outer,str_args_traits>::add_arg__exc(const std::exception& exc)
{
 return this->add_arg(traits_type::arg_str(exc.what()));
}//add_arg__exc

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif