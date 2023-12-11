////////////////////////////////////////////////////////////////////////////////
#ifndef _t_basic_parameter_list_CC_
#define _t_basic_parameter_list_CC_

#include <structure/t_latin_lower.h>
#include <structure/internal/throw_error.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_parameter_list::tag_item

template<class charT,class Allocator>
inline t_basic_parameter_list<charT,Allocator>::tag_item::tag_item
                                                   (str_box_type const n)
 :m_name(n.begin(),n.end())
{;}

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline t_basic_parameter_list<charT,Allocator>::tag_item::tag_item
                                                   (str_box_type const n,
                                                    str_box_type const v)
 :m_name   (n.begin(),n.end())
 ,m_value  (v.begin(),v.end())
{;}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class Allocator>
inline t_basic_parameter_list<charT,Allocator>::tag_item::tag_item
                                                   (string_type&& n,
                                                    string_type&& v)
 :m_name   (__STL_MOVE_VALUE(n))
 ,m_value  (__STL_MOVE_VALUE(v))
{;}

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline t_basic_parameter_list<charT,Allocator>::tag_item::tag_item
                                                   (const self_type& x)
 :m_name(x.m_name)
 ,m_value(x.m_value)
{;}

//------------------------------------------------------------------------

#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class Allocator>
inline t_basic_parameter_list<charT,Allocator>::tag_item::tag_item
                                                   (self_type&& x)
 :m_name  (__STL_MOVE_VALUE(x.m_name))
 ,m_value (__STL_MOVE_VALUE(x.m_value))
{;}

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline t_basic_parameter_list<charT,Allocator>::tag_item::~tag_item()
{;}

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_parameter_list<charT,Allocator>::tag_item&
 t_basic_parameter_list<charT,Allocator>::tag_item::operator = (const self_type& x)
{
 self_type tmp(x);

 this->swap(tmp);

 return *this;
}//operator =

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class charT,class Allocator>
inline typename t_basic_parameter_list<charT,Allocator>::tag_item&
 t_basic_parameter_list<charT,Allocator>::tag_item::operator = (self_type&& x)
{
 self_type tmp(__STL_MOVE_VALUE(x));

 this->swap(tmp);

 return *this;
}//operator =

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE

//------------------------------------------------------------------------
template<class charT,class Allocator>
void t_basic_parameter_list<charT,Allocator>::tag_item::swap(self_type& x)
{
 std::swap(x.m_name  ,m_name);
 std::swap(x.m_value ,m_value);
}//swap

//selectors --------------------------------------------------------------
template<class charT,class Allocator>
inline const typename t_basic_parameter_list<charT,Allocator>::string_type&
 t_basic_parameter_list<charT,Allocator>::tag_item::name()const
{
 return m_name;
}//name - const

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline const typename t_basic_parameter_list<charT,Allocator>::string_type&
 t_basic_parameter_list<charT,Allocator>::tag_item::value()const
{
 return m_value;
}//value - const

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline typename t_basic_parameter_list<charT,Allocator>::string_type&
 t_basic_parameter_list<charT,Allocator>::tag_item::value()
{
 return m_value;
}//value

////////////////////////////////////////////////////////////////////////////////
//class class t_basic_parameter_list::tag_less

template<class charT,class Allocator>
bool t_basic_parameter_list<charT,Allocator>::tag_less::operator ()
                                           (str_box_type const name1,
                                            str_box_type const name2)const
{
 return this->helper__is_less(name1,name2);
}//name1<name2

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool t_basic_parameter_list<charT,Allocator>::tag_less::operator ()
                                           (const item_type&   prop,
                                            str_box_type const name)const
{
 return this->helper__is_less(prop.name(),name);
}//prop<name

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool t_basic_parameter_list<charT,Allocator>::tag_less::operator ()
                                           (str_box_type const name,
                                            const item_type&   prop)const
{
 return this->helper__is_less(name,prop.name());
}//name<prop

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool t_basic_parameter_list<charT,Allocator>::tag_less::operator ()
                                           (const item_type& prop1,
                                            const item_type& prop2)const
{
 return this->helper__is_less(prop1.name(),prop2.name());
}//prop1<prop2

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool t_basic_parameter_list<charT,Allocator>::tag_less::helper__is_less
                                           (str_box_type const s1,
                                            str_box_type const s2)
{
 typename str_box_type::iterator       i1=s1.begin();
 typename str_box_type::iterator const e1=s1.end();
 typename str_box_type::iterator       i2=s2.begin();
 typename str_box_type::iterator const e2=s2.end();

 t_latin_lower<char_type> lower;

 for(;i1!=e1 && i2!=e2;++i1,++i2)
 {
  const char_type c1=lower(*i1);
  const char_type c2=lower(*i2);

  if(c1<c2)
   return true;

  if(c2<c1)
   return false;
 }//for i1,i2

 if(i1==e1)
 {
  if(i2==e2)
   return false;

  return true;
 }//if i1==e1

 assert(i1!=e1);
 assert(i2==e2);

 return false;
}//helper__is_less

////////////////////////////////////////////////////////////////////////////////
//class t_basic_parameter_list

template<class charT,class Allocator>
t_basic_parameter_list<charT,Allocator>::t_basic_parameter_list()
{;}

//------------------------------------------------------------------------
template<class charT,class Allocator>
t_basic_parameter_list<charT,Allocator>::t_basic_parameter_list
                                           (str_box_type str)
{
 this->parse(str);
}//t_basic_parameter_list

//------------------------------------------------------------------------
template<class charT,class Allocator>
t_basic_parameter_list<charT,Allocator>::~t_basic_parameter_list()
{;}

//------------------------------------------------------------------------
template<class charT,class Allocator>
void t_basic_parameter_list<charT,Allocator>::swap(self_type& x)
{
 m_items.swap(x.m_items);
}//swap

//------------------------------------------------------------------------
template<class charT,class Allocator>
t_basic_parameter_list<charT,Allocator>&
 t_basic_parameter_list<charT,Allocator>::parse(str_box_type const str)
{
 this->parse(str.begin(),str.end());

 return *this;
}//parse

//------------------------------------------------------------------------
template<class charT,class Allocator>
template<typename Iterator>
void
 t_basic_parameter_list<charT,Allocator>::parse(Iterator const source_begin,
                                                Iterator const source_end)
{
 const char_type ch_comma_with_point   =traits2_type::ch_comma_with_point();
#ifndef NDEBUG
 const char_type ch_equal              =traits2_type::ch_equal();
#endif

 //-----------------------------------------
 items_type items;

 //-----------------------------------------
 string_type name;
 string_type value;

 Iterator pos=source_begin;

 while(pos!=source_end)
 {
  self_type::helper__parse_name(pos,source_end,&name);

  if(pos==source_end)
   continue;

  if((*pos)==ch_comma_with_point)
  {
   ++pos;
   continue;
  }//if

  assert((*pos)==ch_equal);

  ++pos; //skip '='

  self_type::helper__parse_value(pos,source_end,&value);

  if(pos!=source_end)
  {
   assert((*pos)==ch_comma_with_point);

   ++pos;
  }//if

  item_type newItem(__STL_MOVE_VALUE(name),__STL_MOVE_VALUE(value));

  if(!items.insert(__STL_MOVE_VALUE(newItem)).second)
   internal::throw_error::parameter_list__duplicate_param(newItem.name());
 }//while pos

 m_items.swap(items);

 return;
}//parse

//------------------------------------------------------------------------
template<class charT,class Allocator>
template<class Iterator>
void t_basic_parameter_list<charT,Allocator>::helper__parse_name
                                           (Iterator&          pos,
                                            Iterator     const end,
                                            string_type* const pName)
{
 assert(pName!=NULL);

 pName->erase();

 //-----------------------------------------
 const char_type c_ch_quote              =traits2_type::ch_apos();
 const char_type c_ch_double_quote       =traits2_type::ch_double_quote();
 const char_type c_ch_comma_with_point   =traits2_type::ch_comma_with_point();
 const char_type c_ch_equal              =traits2_type::ch_equal();
 const char_type c_ch_space              =traits2_type::ch_space();

 //----------------------------------------
 while(pos!=end)
 {
  char_type cur_char=*pos;

  if(cur_char==c_ch_double_quote || cur_char==c_ch_quote)
  {
   if(!self_type::helper__parse_quoted_string(pos,end,pName))
    internal::throw_error::parameter_list__bad_format_of_quoted_item_name();

   continue;
  }//if quoted text

  if(cur_char==c_ch_comma_with_point)
   break;

  if(cur_char==c_ch_equal)
   break;

  if(helper__is_space_char(cur_char))
   cur_char=c_ch_space;

  ++pos;

  if(cur_char==c_ch_space)
  {
   if(pName->empty())
    continue; //skip forward spaces

   if(pName->back()==c_ch_space)
    continue; //prev symbol is space

   //Skeep multiple spaces in name
   for(;pos!=end;++pos)
   {
    if(!helper__is_space_char(*pos))
     break;
   }//for

   if(pos==end)
    break; //no back spaces

   const char_type cur_char2=*pos;

   if(cur_char2==c_ch_comma_with_point)
    break; //no back spaces

   if(cur_char2==c_ch_equal)
    break; //no back spaces
  }//if cur_char==c_ch_space

  (*pName)+=cur_char;
 }//while
}//helper__parse_name

//------------------------------------------------------------------------
template<class charT,class Allocator>
template<class Iterator>
void t_basic_parameter_list<charT,Allocator>::helper__parse_value
                                           (Iterator&          pos,
                                            Iterator           end,
                                            string_type* const pValue)
{
 //[ a ]      => [a]
 //[ a  b ]   => [a  b]
 //[" a "]    => [ a ]
 //[" a"" "]  => [ a" ]
 //[" a "]    => [ a ]
 //[" a  b "] => [ a  b ]

 //[' a'' ']  => [ a' ]
 //[' a ']    => [ a ]
 //[' a  b '] => [ a  b ]

 // '\0','\r',\n','\t' replaced to ' '

 //----------------------------------------
 assert(pValue!=NULL);

 pValue->erase();

 //----------------------------------------
 const char_type c_ch_quote            =traits2_type::ch_apos();
 const char_type c_ch_double_quote     =traits2_type::ch_double_quote();
 const char_type c_ch_comma_with_point =traits2_type::ch_comma_with_point();
 const char_type c_ch_space            =traits2_type::ch_space();

 //----------------------------------------
 while(pos!=end)
 {
  char_type cur_char=*pos;

  if(cur_char==c_ch_double_quote || cur_char==c_ch_quote)
  {
   if(!self_type::helper__parse_quoted_string(pos,end,pValue))
    internal::throw_error::parameter_list__bad_format_of_quoted_item_value();

   continue;
  }//if quoted text

  if(cur_char==c_ch_comma_with_point)
   break;

  if(helper__is_space_char(cur_char))
   cur_char=c_ch_space;

  //skip forward space
  if(cur_char==c_ch_space)
  {
   if(pValue->empty())
   {
    ++pos;

    continue;
   }//if

   size_t n_spaces=1;

   ++pos;

   for(;pos!=end;++pos,++n_spaces)
   {
    if(!helper__is_space_char(*pos))
     break;
   }//for

   if(pos==end)
    break;

   if((*pos)==c_ch_comma_with_point)
    break;

   assert_hint(n_spaces>0);

   pValue->append(n_spaces,c_ch_space);

   continue;
  }//if cur_char==c_ch_space

  ++pos;

  (*pValue)+=cur_char;
 }//while
}//helper__parse_value

//------------------------------------------------------------------------
template<class charT,class Allocator>
template<class Iterator>
bool t_basic_parameter_list<charT,Allocator>::helper__parse_quoted_string
                                           (Iterator&          pos,
                                            Iterator     const end,
                                            string_type* const pString)
{
 assert(pos!=end);
 assert(pString!=NULL);

 //-----------------------------------------
 const char_type c_ch_space=traits2_type::ch_space();

 //-----------------------------------------
 const char_type scan_quote_ch=*pos;

 ++pos; //skip first quote ch

 while(pos!=end)
 {
  char_type cur_char=*pos;

  if(cur_char==scan_quote_ch)
  {
   ++pos;

   if(pos==end)
    return true;

   if((*pos)!=scan_quote_ch)
    return true;

   assert((*pos)==scan_quote_ch);
  }
  else
  if(helper__is_space_char(cur_char))
  {
   cur_char=c_ch_space;
  }

  (*pString)+=cur_char;

  ++pos;
 }//while

 return false;
}//helper__parse_quoted_string

//------------------------------------------------------------------------
template<class charT,class Allocator>
typename t_basic_parameter_list<charT,Allocator>::string_type
 t_basic_parameter_list<charT,Allocator>::to_string()const
{
 string_type s;

 for(const_iterator i(m_items.begin()),_e(m_items.end());i!=_e;++i)
 {
  if(!s.empty())
   s+=traits2_type::ch_comma_with_point()/*';'*/;

  if(self_type::helper__test_name_for_pack((*i).name()))
   s+=self_type::helper__pack_str((*i).name());
  else
   s+=(*i).name();

  s+=traits2_type::ch_equal()/*'='*/;

  if(self_type::helper__test_value_for_pack((*i).value()))
   s+=self_type::helper__pack_str((*i).value());
  else
   s+=(*i).value();
 }//for i

 return s;
}//to_string

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool t_basic_parameter_list<charT,Allocator>::helper__test_name_for_pack
                                           (str_box_type const name)
{
 if(name.empty())
  return true;

 if(helper__is_space_char(name.front()))
  return true;

 if(helper__is_space_char(name.back()))
  return true;

 auto const name_beg(name.begin());
 auto const name_end(name.end());

 bool prev_char_is_space=false;

 for(auto i(name_beg);i!=name_end;++i)
 {
  const char_type cur_char=(*i);

  if(cur_char==traits2_type::ch_apos())
   return true;

  if(cur_char==traits2_type::ch_double_quote())
   return true;

  if(cur_char==traits2_type::ch_comma_with_point())
   return true;

  if(cur_char==traits2_type::ch_equal())
   return true;

  if(!helper__is_space_char(cur_char))
  {
   prev_char_is_space=false;
  }
  else
  {
   assert(i!=name.begin());

   if(prev_char_is_space)
    return true;

   prev_char_is_space=true;
  }//else
 }//for i

 return false;
}//helper__test_name_for_pack

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool t_basic_parameter_list<charT,Allocator>::helper__test_value_for_pack
                                           (str_box_type const value)
{
 if(value.empty())
  return true;

 if(helper__is_space_char(value.front()))
  return true;

 if(helper__is_space_char(value.back()))
  return true;

 auto const value_beg(value.begin());
 auto const value_end(value.end());

 for(auto i(value_beg);i!=value_end;++i)
 {
  const char_type cur_char=(*i);

  if(cur_char==traits2_type::ch_apos())
   return true;

  if(cur_char==traits2_type::ch_double_quote())
   return true;

  if(cur_char==traits2_type::ch_comma_with_point())
   return true;

  if(cur_char==traits2_type::ch_equal())
   return true;
 }//for i

 return false;
}//helper__test_value_for_pack

//------------------------------------------------------------------------
template<class charT,class Allocator>
typename t_basic_parameter_list<charT,Allocator>::string_type
 t_basic_parameter_list<charT,Allocator>::helper__pack_str
                                           (str_box_type const s)
{
 CHECK_READ_TYPED_PTR(s.ptr,s.len);

 const char_type ch_double_quote=traits2_type::ch_double_quote();

 const string_type::size_type
  dq_count=std::count(s.begin(),s.end(),ch_double_quote);

 string_type result;

 //! \todo [2019-10-18] check overflow!
 result.reserve(s.len+2+dq_count);

 result+=ch_double_quote;

 for(typename str_box_type::iterator i(s.begin()),_e(s.end());i!=_e;++i)
 {
  if((*i)==ch_double_quote)
   result+=*i;

  result+=*i;
 }//for i

 result+=ch_double_quote;

 return result;
}//helper__pack_str

//------------------------------------------------------------------------
template<class charT,class Allocator>
typename t_basic_parameter_list<charT,Allocator>::iterator
 t_basic_parameter_list<charT,Allocator>::find(str_box_type const name)
{
 return m_items.find(name);
}//find

//------------------------------------------------------------------------
template<class charT,class Allocator>
typename t_basic_parameter_list<charT,Allocator>::const_iterator
 t_basic_parameter_list<charT,Allocator>::find(str_box_type const name)const
{
 return m_items.find(name);
}//find - const

//------------------------------------------------------------------------
template<class charT,class Allocator>
typename t_basic_parameter_list<charT,Allocator>::search_result_type
 t_basic_parameter_list<charT,Allocator>::search(str_box_type const name)
{
 iterator const x=this->find(name);

 return search_result_type(x,x!=this->end());
}//search

//------------------------------------------------------------------------
template<class charT,class Allocator>
typename t_basic_parameter_list<charT,Allocator>::const_search_result_type
 t_basic_parameter_list<charT,Allocator>::search(str_box_type const name)const
{
 const_iterator const x=this->find(name);

 return const_search_result_type(x,x!=this->end());
}//search - const

//------------------------------------------------------------------------
template<class charT,class Allocator>
t_basic_parameter_list<charT,Allocator>&
 t_basic_parameter_list<charT,Allocator>::overwrite(str_box_type const str)
{
 self_type list(str);

 for(const_iterator i(list.begin()),_e(list.end());i!=_e;++i)
 {
  this->set(*i);
 }

 return *this;
}//overwrite

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool t_basic_parameter_list<charT,Allocator>::erase(str_box_type const name)
{
 return m_items.erase(name);
}//erase

//------------------------------------------------------------------------
template<class charT,class Allocator>
void t_basic_parameter_list<charT,Allocator>::erase(iterator pos)
{
 return m_items.erase(pos);
}//erase

//------------------------------------------------------------------------
template<class charT,class Allocator>
void t_basic_parameter_list<charT,Allocator>::clear()
{
 return m_items.clear();
}//clear

//------------------------------------------------------------------------
template<class charT,class Allocator>
typename t_basic_parameter_list<charT,Allocator>::pair_type
 t_basic_parameter_list<charT,Allocator>::insert(str_box_type const name,
                                                 str_box_type const value)
{
 return m_items.insert(tag_item(name,value)); //throw
}//insert

//------------------------------------------------------------------------
template<class charT,class Allocator>
typename t_basic_parameter_list<charT,Allocator>::pair_type
 t_basic_parameter_list<charT,Allocator>::insert(const item_type& param)
{
 return m_items.insert(param); //throw
}//insert

//------------------------------------------------------------------------
template<class charT,class Allocator>
t_basic_parameter_list<charT,Allocator>&
 t_basic_parameter_list<charT,Allocator>::set(str_box_type const name,
                                              str_box_type const value)
{
 string_type v(value.begin(),value.end());

 auto const i=m_items.insert(name); //throw

 (*i.first).value().swap(v);

 return *this;
}//set

//------------------------------------------------------------------------
template<class charT,class Allocator>
RELEASE_CODE(inline)
t_basic_parameter_list<charT,Allocator>&
 t_basic_parameter_list<charT,Allocator>::set(const item_type& param)
{
 return this->set(param.name(),param.value());
}//set

//------------------------------------------------------------------------
template<class charT,class Allocator>
RELEASE_CODE(inline)
bool t_basic_parameter_list<charT,Allocator>::helper__is_space_char(char_type const ch)
{
 return is_trim_char2(ch);
}//helper__is_space_char

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
