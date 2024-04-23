////////////////////////////////////////////////////////////////////////////////
#ifndef _lcpi_lib_structure__t_cmd_line_parser_CC_
#define _lcpi_lib_structure__t_cmd_line_parser_CC_

#include <structure/utilities/string/trim.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_cmd_line_part

template<class ForwardIterator>
inline
t_cmd_line_part<ForwardIterator>::t_cmd_line_part()
 :m_start     (iterator_type())
 ,m_finish    (iterator_type())
 ,m_value_beg (iterator_type())
 ,m_value_end (iterator_type())
{
}

//------------------------------------------------------------------------
template<class ForwardIterator>
inline
t_cmd_line_part<ForwardIterator>::t_cmd_line_part(const self_type& x)
 :m_start     (x.m_start)
 ,m_finish    (x.m_finish)
 ,m_value_beg (x.m_value_beg)
 ,m_value_end (x.m_value_end)
{
}

//------------------------------------------------------------------------
template<class ForwardIterator>
inline
t_cmd_line_part<ForwardIterator>::t_cmd_line_part(ForwardIterator start,
                                                  ForwardIterator finish,
                                                  ForwardIterator value_beg,
                                                  ForwardIterator value_end)
 :m_start     (start)
 ,m_finish    (finish)
 ,m_value_beg (value_beg)
 ,m_value_end (value_end)
{
}

//------------------------------------------------------------------------
template<class ForwardIterator>
inline
t_cmd_line_part<ForwardIterator>::~t_cmd_line_part()
{
}

//------------------------------------------------------------------------
template<class ForwardIterator>
inline t_cmd_line_part<ForwardIterator>&
 t_cmd_line_part<ForwardIterator>::operator = (const self_type& x)
{
 m_start     = x.m_start;
 m_finish    = x.m_finish;
 m_value_beg = x.m_value_beg;
 m_value_end = x.m_value_end;

 return *this;
}//operator =

////////////////////////////////////////////////////////////////////////////////
//class t_cmd_line_parser_error_traits

template<class t_dummy>
const typename t_cmd_line_parser_error_traits<t_dummy>::msg_type
 t_cmd_line_parser_error_traits<t_dummy>::sm_msgs[4]=
{
 {err_id_empty_arg_name,
  L"empty command line argument name."},

 {err_id_bad_arg_name,
  L"bad command line argument name."},

 {err_id_unk_arg_1,
  L"unknown command line argument [%1]."},

 {err_id_bad_format_0,
  L"bad command line format."},
};//sm_msgs

//------------------------------------------------------------------------
template<class t_dummy>
bool t_cmd_line_parser_error_traits<t_dummy>::get_msg(lcid_type,
                                                      msg_id_type const msg_id,
                                                      string_type&      msg)
{
 const msg_type* const entry(std::find(sm_msgs,_END_(sm_msgs),msg_id));

 if(entry==_END_(sm_msgs))
  return false;

 msg=entry->msg;

 return true;
}//get_msg

//------------------------------------------------------------------------
template<class t_dummy>
void t_cmd_line_parser_error_traits<t_dummy>::get_unknown_msg(lcid_type,
                                                              string_type& msg)
{
 msg=L"[cmd line parser] unknown error message [%1]";
}//get_unknown_msg

//------------------------------------------------------------------------
template<class t_dummy>
const char* t_cmd_line_parser_error_traits<t_dummy>::get_critical_error_msg(lcid_type)
{
 return "[cmd line parser] critical error";
}//get_critical_error_msg

//------------------------------------------------------------------------
template<class t_dummy>
bool t_cmd_line_parser_error_traits<t_dummy>::get_source_name(lcid_type,
                                                              source_id_type,
                                                              string_type& source)
{
 source=L"t_cmd_line_parser";

 return true;
}//get_source_name

//------------------------------------------------------------------------
template<class t_dummy>
bool t_cmd_line_parser_error_traits<t_dummy>::get_help_file(lcid_type,
                                                            help_file_id_type,
                                                            string_type& help_file)
{
 help_file.erase();

 return false;
}//get_help_file

////////////////////////////////////////////////////////////////////////////////
//class t_basic_cmd_line_arg

template<class charT,class Allocator>
t_basic_cmd_line_arg<charT,Allocator>::t_basic_cmd_line_arg()
{;}

//------------------------------------------------------------------------
template<class charT,class Allocator>
t_basic_cmd_line_arg<charT,Allocator>::~t_basic_cmd_line_arg()
{;}

////////////////////////////////////////////////////////////////////////////////
//class t_basic_cmd_line_parser_base

template<class charT>
t_basic_cmd_line_parser_base<charT>::t_basic_cmd_line_parser_base()
 :m_ctype("C")
{;}

//------------------------------------------------------------------------
template<class charT>
t_basic_cmd_line_parser_base<charT>::~t_basic_cmd_line_parser_base()
{;}

//------------------------------------------------------------------------
template<class charT>
inline
bool t_basic_cmd_line_parser_base<charT>::is_name_char_1(const char_type c)const
{
 return m_ctype.isalpha(c);
}

//------------------------------------------------------------------------
template<class charT>
inline
bool t_basic_cmd_line_parser_base<charT>::is_name_char_2(const char_type c)const
{
 typedef t_char_traits2<char_type> _t2;

 return m_ctype.isalnum(c) || c==_t2::ch_underscore();
}
////////////////////////////////////////////////////////////////////////////////
//class t_basic_cmd_line_parser

template<class charT,class Allocator>
t_basic_cmd_line_parser<charT,Allocator>::t_basic_cmd_line_parser()
{;}

//------------------------------------------------------------------------
template<class charT,class Allocator>
t_basic_cmd_line_parser<charT,Allocator>::t_basic_cmd_line_parser(str_box_type const s)
{
 this->parse(s);
}

//------------------------------------------------------------------------
template<class charT,class Allocator>
t_basic_cmd_line_parser<charT,Allocator>::~t_basic_cmd_line_parser()
{;}

//set parameters description ---------------------------------------------
template<class charT,class Allocator>
t_basic_cmd_line_parser<charT,Allocator>&
 t_basic_cmd_line_parser<charT,Allocator>::reg_arg(str_box_type         _arg_name,
                                                   const arg_flags_type _arg_flag)
{
 string_type const arg_name(_arg_name.make_str());

 assert(arg_name==trim(arg_name));

 assert(!arg_name.empty());
 assert(m_args_flags.find(arg_name)==m_args_flags.end());

 m_args_flags[arg_name]=_arg_flag;

 return *this;
}//reg_arg

//------------------------------------------------------------------------
template<class charT,class Allocator>
RELEASE_CODE(inline)
t_basic_cmd_line_parser<charT,Allocator>&
 t_basic_cmd_line_parser<charT,Allocator>::clear(bool all)
{
 m_args.clear();

 if(all)
  m_args_flags.clear();

 return *this;
}//clear

//parser -----------------------------------------------------------------
template<class charT,class Allocator>
t_basic_cmd_line_parser<charT,Allocator>&
 t_basic_cmd_line_parser<charT,Allocator>::parse(str_box_type const s)
{
 typedef t_char_traits2<char_type>        _t2;

 CHECK_READ_TYPED_PTR(s.ptr,s.len);

 auto cur(s.begin());
 auto const end(s.end());

 tag_is_trim_char2<char_type> is_space_pred;

 typename arg_type::self_ptr arg;

 for(;;)
 {
  cur=std::find_if_not(cur,end,is_space_pred);

  if(cur==end)
   break;

  if((*cur)==_t2::ch_double_quote())
  {
   //start quoted value
   ++cur;

   const auto start=cur;

   cur=std::find(cur,end,_t2::ch_double_quote());

   if(cur==end)
    error_type(err_id_bad_format_0).raise();

   //[start,cur) - argument value
   this->helper__install_arg_value(arg,start,cur);

   //skip '"'
   assert(cur!=end);

   ++cur;

   continue;
  }//quoted value

  //---------------------------------------------
  if((*cur)=='/' || (*cur)=='-')
  {
   //start named argument
   const char_type x=*cur;

   if((++cur)==end)
   {
    //DONE 5: error - empty argument name
    error_type(err_id_empty_arg_name).raise();
   }

   if((*cur)!=x) // '//' '--' interpret as '/' or '-'
   {
    if(!self_type::is_name_char_1(*cur))
    {
     //DONE 5: error - incorrect argument name
     error_type(err_id_bad_arg_name).raise();
    }//if

    const auto start=cur;

    for(++cur;cur!=end && self_type::is_name_char_2(*cur);++cur);

    arg=structure::not_null_ptr(new arg_type());

    arg->m_name.assign(start,cur);

    m_args.push_back(arg);

    if(!helper__arg_has_value(arg->m_name))
     arg.Release();

    continue;
   }//if
  }//if

  //start value ---------------------------------
  const auto start=cur;

  // [2020-01-29]
  //
  // old code:
  //  cur=find_if(++cur,end,std::bind2nd(std::less_equal<_t2::char_comp_type>(),_t2::ch_space()));
  //

  cur=std::find_if(++cur,end,is_space_pred);

  //[start,cur) - argument value
  this->helper__install_arg_value(arg,start,cur);
 }//for[ever]

 return *this;
}//parse

//service methods --------------------------------------------------------
template<class charT,class Allocator>
bool t_basic_cmd_line_parser<charT,Allocator>::helper__arg_has_value(const string_type& arg_name)const
{
 typename args_flags_map::const_iterator const x(m_args_flags.find(arg_name));

 if(x==m_args_flags.end())
  return false;

 return (*x).second==arg_with_value;
}//helper__arg_has_value

//------------------------------------------------------------------------
template<class charT,class Allocator>
void t_basic_cmd_line_parser<charT,Allocator>::helper__install_arg_value
                                        (typename arg_type::self_ptr&          arg,
                                         typename str_box_type::iterator const beg,
                                         typename str_box_type::iterator const end)
{
 if(!arg)
 {
  arg=structure::not_null_ptr(new arg_type());

  arg->m_value.assign(beg,end);

  m_args.emplace_back(arg.not_null_ptr());

  assert(!m_args.empty());
  assert(m_args.back());
 }
 else
 {
  arg->m_value.assign(beg,end);
 }//else

 arg.Release();
}//helper__install_arg_value

//selectors --------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_cmd_line_parser<charT,Allocator>::size_type
 t_basic_cmd_line_parser<charT,Allocator>::size()const
{
 return m_args.size();
}//size

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool t_basic_cmd_line_parser<charT,Allocator>::empty()const
{
 return m_args.empty();
}//empty

//------------------------------------------------------------------------
template<class charT,class Allocator>
RELEASE_CODE(inline)
const typename t_basic_cmd_line_parser<charT,Allocator>::arg_ptr&
 t_basic_cmd_line_parser<charT,Allocator>::operator [] (size_type i)const
{
 assert_msg(i<m_args.size(),"i=="<<i<<" size="<<m_args.size());

 return m_args[i];
}//operator []

//------------------------------------------------------------------------
template<class charT,class Allocator>
const typename t_basic_cmd_line_parser<charT,Allocator>::arg_ptr
 t_basic_cmd_line_parser<charT,Allocator>::get(str_box_type const name,
                                               bool         const must_exists)const//throw
{
 assert(name.ptr!=nullptr);
 assert(name.len>0);

 typename args_type::const_iterator i(m_args.begin());
 typename args_type::const_iterator const _e(m_args.end());

 for(;i!=_e;++i)
 {
  assert(*i);

  if(name.equal((*i)->m_name))
   return *i;
 }//for

 if(must_exists)
 {
  error_type exc(err_id_unk_arg_1);

  exc<<name;

  exc.raise();
 }//if

 assert_hint(!must_exists);

 return nullptr;
}//get

//------------------------------------------------------------------------
template<class charT,class Allocator>
const typename t_basic_cmd_line_parser<charT,Allocator>::string_type&
 t_basic_cmd_line_parser<charT,Allocator>::value_or_default
                                           (str_box_type const name,
                                            const string_type& default_value)const
{
 if(const arg_ptr x=this->get(name,false))
  return x->m_value;

 return default_value;
}//value_or_default

//------------------------------------------------------------------------
template<class charT,class Allocator>
RELEASE_CODE(inline)
 bool t_basic_cmd_line_parser<charT,Allocator>::has(str_box_type const name)const
{
 return this->get(name,false)!=nullptr;
}//has

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_cmd_line_parser<charT,Allocator>::iterator
 t_basic_cmd_line_parser<charT,Allocator>::begin()
{
 return m_args.begin();
}//begin

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_cmd_line_parser<charT,Allocator>::iterator
 t_basic_cmd_line_parser<charT,Allocator>::end()
{
 return m_args.end();
}//end

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_cmd_line_parser<charT,Allocator>::const_iterator
 t_basic_cmd_line_parser<charT,Allocator>::begin()const
{
 return m_args.begin();
}//begin

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_cmd_line_parser<charT,Allocator>::const_iterator
 t_basic_cmd_line_parser<charT,Allocator>::end()const
{
 return m_args.end();
}//end

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_cmd_line_parser<charT,Allocator>::const_iterator
 t_basic_cmd_line_parser<charT,Allocator>::cbegin()const
{
 return m_args.cbegin();
}//cbegin

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_cmd_line_parser<charT,Allocator>::const_iterator
 t_basic_cmd_line_parser<charT,Allocator>::cend()const
{
 return m_args.cend();
}//cend

//modificators -----------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_cmd_line_parser<charT,Allocator>::iterator
 t_basic_cmd_line_parser<charT,Allocator>::erase(iterator const x)
{
 return m_args.erase(x);
}//erase

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_cmd_line_parser<charT,Allocator>::iterator
 t_basic_cmd_line_parser<charT,Allocator>::erase(iterator const first,iterator const last)
{
 return m_args.erase(first,last);
}//erase

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
