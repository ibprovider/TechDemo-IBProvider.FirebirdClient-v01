////////////////////////////////////////////////////////////////////////////////
//Service for work with localization
//                                                Kovalenko Dmitry. 21.08.2003.
#ifndef _t_locale_H_
#define _t_locale_H_

#include <structure/t_common.h>
#include <functional>

#ifndef __BORLANDC__
# include <locale>
#endif

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class charT>
class t_ctype;

template<class charT>
class t_collate;

template<class charT>
class t_char_upper;

template<class charT>
class t_char_lower;

template<class charT>
class t_char_less_i;

template<class charT>
class t_char_equal_i;

template<class charT>
class t_char_not_equal_i;

////////////////////////////////////////////////////////////////////////////////
//class t_ctype

template<class charT>
class t_ctype
{
 private:
  typedef t_ctype<charT>          self_type;

  self_type& operator = (const self_type&);

 public:
  typedef charT                   char_type;

 private:
  typedef std::locale             locale_type;
  typedef std::ctype<char_type>   ctype_type;

 public:
  t_ctype()
   :m_locale("C")
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  t_ctype(const self_type& x)
   :m_locale(x.m_locale)
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  explicit t_ctype(const locale_type& l)
   :m_locale(l)
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  explicit t_ctype(const char* locale_name)
   :m_locale(locale_name)
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

 public:
  const locale_type& get_locale()const   {return m_locale;}

  const ctype_type&  get_ctype() const   {return m_ctype;}

  bool isalnum(char_type c)const   {return m_ctype.is(ctype_type::alnum,c);}

  bool isalpha(char_type c)const   {return m_ctype.is(ctype_type::alpha,c);}

  bool iscntrl(char_type c)const   {return m_ctype.is(ctype_type::cntrl,c);}

  bool isdigit(char_type c)const   {return m_ctype.is(ctype_type::digit,c);}

  bool isgraph(char_type c)const   {return m_ctype.is(ctype_type::graph,c);}

  bool islower(char_type c)const   {return m_ctype.is(ctype_type::lower,c);}

  bool isprint(char_type c)const   {return m_ctype.is(ctype_type::print,c);}

  bool ispunct(char_type c)const   {return m_ctype.is(ctype_type::punct,c);}

  bool isspace(char_type c)const   {return m_ctype.is(ctype_type::space,c);}

  bool isupper(char_type c)const   {return m_ctype.is(ctype_type::upper,c);}

  bool isxdigit(char_type c)const  {return m_ctype.is(ctype_type::xdigit,c);}

  //-----------------------------------
  char_type  toupper(char_type c)const
   {return m_ctype.toupper(c);}

  char_type* toupper(char_type* low,char_type* high)const
   {return m_ctype.toupper(low,high);}

  char_type  tolower(char_type c)const
   {return m_ctype.tolower(c);}

  char_type* tolower(char_type* low,char_type* high)const
   {return m_ctype.tolower(low,high);}

 private:
  const locale_type m_locale;
  const ctype_type& m_ctype;
};//class t_ctype

////////////////////////////////////////////////////////////////////////////////
//class t_collate

template<class charT>
class t_collate
{
 private:
  typedef t_collate<charT>        self_type;

  self_type& operator = (const self_type&);

 public:
  typedef charT                   char_type;

 private:
  typedef std::locale             locale_type;
  typedef std::collate<char_type> collate_type;

 public:
  t_collate()
   :m_locale("C"),
    m_collate(__STL_USE_FACET(collate_type,m_locale))
  {;}

  t_collate(const self_type& x)
   :m_locale(x.m_locale),
    m_collate(__STL_USE_FACET(collate_type,m_locale))
  {;}

  explicit t_collate(const locale_type& l)
   :m_locale(l),
    m_collate(__STL_USE_FACET(collate_type,m_locale))
  {;}

  explicit t_collate(const char* locale_name)
   :m_locale(locale_name),
    m_collate(__STL_USE_FACET(collate_type,m_locale))
  {;}

 public:
  int compare(const char_type* low1, const char_type* high1,
              const char_type* low2, const char_type* high2) const
  {
   return m_collate.compare(low1,high1,low2,high2);
  }

 private:
  const locale_type   m_locale;
  const collate_type& m_collate;
};//class t_collate

////////////////////////////////////////////////////////////////////////////////
//struct t_char_upper

template<class charT>
class t_char_upper
{
 private:
  typedef t_char_upper<charT>     self_type;

  self_type& operator = (const self_type&);

 public:
  typedef charT                   char_type;

 private:
  typedef std::locale             locale_type;
  typedef std::ctype<char_type>   ctype_type;

 public:
  t_char_upper()
   :m_locale("C")
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  t_char_upper(const self_type& x)
   :m_locale(x.m_locale)
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  explicit t_char_upper(const locale_type& l)
   :m_locale(l)
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  explicit t_char_upper(const char* const locale_name)
   :m_locale(locale_name),
    m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  char_type operator () (char_type const c)const
   {return m_ctype.toupper(c);}

 private:
  const locale_type m_locale;
  const ctype_type& m_ctype;
};//t_char_upper

//------------------------------------------------------------------------
template<class charT>
t_char_upper<charT> get_char_upper_op(const charT* const /*c*/=0)
{
 return t_char_upper<charT>();
}//get_char_upper_op

//------------------------------------------------------------------------
template<class charT>
t_char_upper<charT> get_char_upper_op(const std::locale& l,const charT* const /*c*/=0)
{
 return t_char_upper<charT>(l);
}//get_char_upper_op

////////////////////////////////////////////////////////////////////////////////
//struct t_char_lower

template<class charT>
class t_char_lower
{
 private:
  typedef t_char_lower<charT>     self_type;

  self_type& operator = (const self_type&);

 public:
  typedef charT                   char_type;

 private:
  typedef std::locale             locale_type;
  typedef std::ctype<char_type>   ctype_type;

 public:
  t_char_lower()
   :m_locale("C")
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  t_char_lower(const self_type& x)
   :m_locale(x.m_locale)
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  explicit t_char_lower(const locale_type& l)
   :m_locale(l)
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  explicit t_char_lower(const char* const locale_name)
   :m_locale(locale_name)
   ,m_ctype(__STL_USE_FACET(ctype_type,m_locale))
  {;}

  char_type operator () (char_type const c)const
   {return m_ctype.tolower(c);}

 private:
  const locale_type  m_locale;
  const ctype_type&  m_ctype;
};//t_char_lower

//------------------------------------------------------------------------
template<class charT>
t_char_lower<charT> get_char_lower_op(const charT* const /*c*/=0)
{
 return t_char_lower<charT>();
}//get_char_lower_op

//------------------------------------------------------------------------
template<class charT>
t_char_lower<charT> get_char_lower_op(const std::locale& l,const charT* const /*c*/=0)
{
 return t_char_lower<charT>(l);
}//get_char_lower_op

////////////////////////////////////////////////////////////////////////////////
//class t_char_less_i

template<class charT>
class t_char_less_i
{
 private:
  typedef t_char_less_i<charT>              self_type;

 public: //typedefs ------------------------------------------------------
  typedef charT                             char_type;

 public:
  explicit t_char_less_i(const std::locale& loc)
   :m_cl(loc)
   {;}

  explicit t_char_less_i(const char* locale_name)
   :m_cl(locale_name)
   {;}

  bool operator () (char_type a,char_type b)const
   {
    return m_cl(a)<m_cl(b);
   }

 private:
  t_char_lower<char_type> m_cl;
};//class t_char_less_i

////////////////////////////////////////////////////////////////////////////////
//class t_char_equal_i

template<class charT>
class t_char_equal_i
{
 private:
  typedef t_char_equal_i<charT>             self_type;

 public: //typedefs ------------------------------------------------------
  typedef charT                             char_type;

 public:
  explicit t_char_equal_i(const std::locale& loc)
   :m_cl(loc)
   {;}

  explicit t_char_equal_i(const char* locale_name)
   :m_cl(locale_name)
   {;}

  bool operator () (char_type a,char_type b)const
   {
    return m_cl(a)==m_cl(b);
   }

 private:
  t_char_lower<char_type> m_cl;
};//class t_char_equal_i

////////////////////////////////////////////////////////////////////////////////
//class t_char_not_equal_i

template<class charT>
class t_char_not_equal_i
{
 private:
  typedef t_char_not_equal_i<charT>         self_type;

 public: //typedefs ------------------------------------------------------
  typedef charT                             char_type;

 public:
  explicit t_char_not_equal_i(const std::locale& loc)
   :m_cl(loc)
   {;}

  explicit t_char_not_equal_i(const char* locale_name)
   :m_cl(locale_name)
   {;}

  bool operator () (char_type a,char_type b)const
   {
    return m_cl(a)!=m_cl(b);
   }

 private:
  t_char_lower<char_type> m_cl;
};//class t_char_not_equal_i

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
