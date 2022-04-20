////////////////////////////////////////////////////////////////////////////////
//Service class for parse parameters list "param1=value1;param2=value2"
//                                              Dmitry Kovalenko. 29.02.2004
#ifndef _t_basic_parameter_list_H_
#define _t_basic_parameter_list_H_

#include <structure/t_search_result.h>
#include <structure/t_memory.h>
#include <structure/t_const_str_box.h>
#include <structure/tree/t_tree_avl.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
#ifndef COMP_CONF_SUPPORT_RVALUE_REFERENCE
# error "COMP_CONF_SUPPORT_RVALUE_REFERENCE not defined"
#endif
////////////////////////////////////////////////////////////////////////////////
//containings

template<class charT,class Allocator=t_void_allocator>
class t_basic_parameter_list;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_parameter_list

template<class charT,class Allocator>
class t_basic_parameter_list
{
 private:
  typedef t_basic_parameter_list<charT,Allocator>       self_type;

  t_basic_parameter_list(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef charT                                         char_type;
  typedef Allocator                                     allocator_type;
  typedef std::char_traits<char_type>                   traits_type;
  typedef __STL_DEF_BASIC_STRING(char_type)             string_type;

  typedef t_basic_const_str_box<char_type>              str_box_type;

 public:
  class tag_item
  {
   private:
    typedef tag_item                                    self_type;

   public: //---------------------------------------------------------------
    explicit tag_item(str_box_type n);

    tag_item(str_box_type n,str_box_type v);

   #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
    tag_item(string_type&& n,string_type&& v);
   #endif

    tag_item(const self_type& x);

   #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
    tag_item(self_type&& x);
   #endif

   ~tag_item();

    self_type& operator = (const self_type& x);

   #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
    self_type& operator = (self_type&& x);
   #endif

    void swap(self_type& x);

   public:
    const string_type& name()const;
    const string_type& value()const;

    string_type& value();

   private:
    string_type m_name;
    string_type m_value;
  };//class tag_item

  typedef tag_item                                      item_type;

 private:
  class tag_less
  {
   public:
    bool operator () (str_box_type name1,str_box_type name2)const;

    bool operator () (const item_type& prop,str_box_type name)const;

    bool operator () (str_box_type name,const item_type& prop)const;

    bool operator () (const item_type& prop1,const item_type& prop2)const;

   private:
    static bool helper__is_less(str_box_type s1,str_box_type s2);
  };//class tag_less

  typedef t_tree_avl<item_type,
                     tag_less,
                     allocator_type>                      items_type;

 public:
  typedef typename items_type::iterator                   iterator;
  typedef typename items_type::const_iterator             const_iterator;
  typedef typename items_type::size_type                  size_type;

  typedef t_search_result<iterator>                       search_result_type;
  typedef t_search_result<const_iterator>                 const_search_result_type;

  typedef typename items_type::pair_type                  pair_type;

 public:
  t_basic_parameter_list();

  t_basic_parameter_list(str_box_type str);

 ~t_basic_parameter_list();

 public:
  void swap(self_type& x);

 public:
  self_type& parse(str_box_type str);

  template<typename Iterator>
  void parse(Iterator source_begin,Iterator source_end);

  //accessor -------------------------------------------------------------
  iterator begin()  {return m_items.begin();}
  iterator end()    {return m_items.end();}

  const_iterator begin() const {return m_items.begin();}
  const_iterator end()   const {return m_items.end();}

  const_iterator cbegin() const {return m_items.cbegin();}
  const_iterator cend()   const {return m_items.cend();}

  //selectors ------------------------------------------------------------
  size_type size()const  {return m_items.size();}
  bool      empty()const {return m_items.empty();}

  string_type to_string()const;

  //return end() for unknown parameter 'name'
  iterator       find(str_box_type name);
  const_iterator find(str_box_type name)const;

  search_result_type       search(str_box_type name);
  const_search_result_type search(str_box_type name)const;

  //modificator ----------------------------------------------------------
  self_type& overwrite(str_box_type str);

  bool erase(str_box_type name);

  void erase(iterator pos);

  void clear();

  pair_type insert(str_box_type name,
                   str_box_type value);

  pair_type insert(const item_type& param);

  self_type& set(str_box_type name,
                 str_box_type value);

  self_type& set(const item_type& param);

 private:
  typedef t_char_traits2<char_type>                     traits2_type;

 private:
  template<class Iterator>
  static void helper__parse_name(Iterator& pos,Iterator end,string_type* pName);

  template<class Iterator>
  static void helper__parse_value(Iterator& pos,Iterator end,string_type* pValue);

  template<class Iterator>
  static bool helper__parse_quoted_string(Iterator& pos,Iterator end,string_type* pString);

 private:
  static bool helper__test_name_for_pack(str_box_type name);

  static bool helper__test_value_for_pack(str_box_type value);

  static string_type helper__pack_str(str_box_type str);

 private:
  static bool helper__is_space_char(char_type ch);

 private:
  items_type           m_items;
};//class t_basic_parameter_list

typedef t_basic_parameter_list<char>                    t_parameter_list;
typedef t_basic_parameter_list<wchar_t>                 t_wparameter_list;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

namespace std{
////////////////////////////////////////////////////////////////////////////////
//swap specialization

template<class charT,class Allocator>
void swap(typename structure::t_basic_parameter_list<charT,Allocator>::item_type& a,
          typename structure::t_basic_parameter_list<charT,Allocator>::item_type& b)
{
 a.swap(b);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_parameter_list.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
