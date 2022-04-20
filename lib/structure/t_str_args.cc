////////////////////////////////////////////////////////////////////////////////
#ifndef _t_str_args_CC_
#define _t_str_args_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_str_args

template<class charT,class t_return>
t_basic_str_args<charT,t_return>::t_basic_str_args()
{;}

//------------------------------------------------------------------------
template<class charT,class t_return>
t_basic_str_args<charT,t_return>::~t_basic_str_args()
{;}

//append arguments -------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (bool value)
{
 return this->add_arg(traits_type::arg_bool(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (signed char value)
{
 return this->add_arg(traits_type::arg_long(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (unsigned char value)
{
 return this->add_arg(traits_type::arg_ulong(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (signed short value)
{
 return this->add_arg(traits_type::arg_long(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (unsigned short value)
{
 return this->add_arg(traits_type::arg_ulong(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (signed int value)
{
 return this->add_arg(traits_type::arg_int(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (unsigned int value)
{
 return this->add_arg(traits_type::arg_uint(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (signed long value)
{
 return this->add_arg(traits_type::arg_long(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (unsigned long value)
{
 return this->add_arg(traits_type::arg_ulong(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (signed __int64 value)
{
 return this->add_arg(traits_type::arg_int64(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (unsigned __int64 value)
{
 return this->add_arg(traits_type::arg_uint64(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator<<(float value)
{
 return this->add_arg(traits_type::arg_float(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator<<(double value)
{
 return this->add_arg(traits_type::arg_double(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator<<(long double value)
{
 return this->add_arg(traits_type::arg_long_double(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const char* value)
{
 return this->add_arg(traits_type::arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const std::string& value)
{
 return this->add_arg(traits_type::arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const wchar_t* value)
{
 return this->add_arg(traits_type::arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const std::wstring& value)
{
 return this->add_arg(traits_type::arg_str(value));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const t_symbol& value)
{
 return this->add_arg(string_type(1,value.symbol));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const t_char_str& value)
{
 return this->add_arg(traits_type::arg_str(value.s,value.n));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const t_wchar_str& value)
{
 return this->add_arg(traits_type::arg_str(value.s,value.n));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const astr_param_type& value)
{
 return this->add_arg(traits_type::arg_str(value.c_str()));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const wstr_param_type& value)
{
 return this->add_arg(traits_type::arg_str(value.c_str()));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const astr_box_type& value)
{
 return this->add_arg(traits_type::arg_str(value.data(),value.size()));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const wstr_box_type& value)
{
 return this->add_arg(traits_type::arg_str(value.data(),value.size()));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (const std::exception& exc)
{
 return this->add_arg__exc(exc);
}

//------------------------------------------------------------------------
template<class charT,class t_return>
typename t_basic_str_args<charT,t_return>::outer_type&
t_basic_str_args<charT,t_return>::operator << (manip1_type x)
{
 assert(x!=NULL);

 return x(outer_type::build_outer_type(*this));
}

//------------------------------------------------------------------------
template<class charT,class t_return>
void t_basic_str_args<charT,t_return>::operator << (manip2_type x)
{
 assert(x!=NULL);

 x(outer_type::build_outer_type(*this));
}

//------------------------------------------------------------------------
#if (!COMP_CONF_STABLE_PURE_METHOD_IN_TEMPLATE)
template<class charT,class t_outer>
typename t_basic_str_args<charT,t_outer>::outer_type&
 t_basic_str_args<charT,t_outer>::add_arg(const string_type& /*x*/)
{
 assert(false);

 return outer_type::build_outer_type(*this);
}//add_arg
#endif

//------------------------------------------------------------------------
template<class charT,class t_outer>
typename t_basic_str_args<charT,t_outer>::outer_type&
 t_basic_str_args<charT,t_outer>::add_arg__exc(const std::exception& exc)
{
 return this->add_arg(traits_type::arg_str(exc.what()));
}//add_arg__exc

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif