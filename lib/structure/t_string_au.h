////////////////////////////////////////////////////////////////////////////////
#ifndef _t_string_au_H_
#define _t_string_au_H_

#include <structure/t_char_converter.h>
#include <structure/t_char_traits2.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class stringT>
class t_string_au;

////////////////////////////////////////////////////////////////////////////////
//class t_string_au

template<class stringT>
class t_string_au
{
 private:
  typedef t_string_au<stringT>                   self_type;

 public: //typedefs ------------------------------------------------------
  typedef stringT                                string_type;
  typedef typename string_type::value_type       char_type;
  typedef typename string_type::traits_type      traits_type;
  typedef typename string_type::size_type        size_type;

  typedef typename string_type::iterator         iterator;
  typedef typename string_type::const_iterator   const_iterator;

  typedef t_char_traits2<char_type>              traits2_type;

  typedef typename traits2_type::other_char_type other_char_type;
  typedef std::char_traits<other_char_type>      other_traits_type;

  typedef std::basic_string
   <other_char_type,other_traits_type,
    std::allocator<other_char_type> >            other_string_type;

 public:
  t_string_au()
   {;}

  t_string_au(const self_type& x)
   :m_str(x.m_str)
   {;}

  t_string_au(const string_type& s)
   :m_str(s)
   {;}

  t_string_au(const char_type* const s,size_type const n=-1)
   :m_str((s?s:traits2_type::str_empty()),s?((n==-1)?traits_type::length(s):n):0)
   {;}

  t_string_au(const other_string_type& s)
   {tstr_to_tstr(&m_str,s);}

  t_string_au(const other_char_type* const s,size_type const n=-1)
   {tstr_to_tstr(&m_str,s,n);}

  //assign operators ------------------------------------------------------
  self_type& operator = (const self_type& x)
   {m_str=x.m_str;return *this;}

  self_type& operator = (const string_type& s)
   {m_str=s;return *this;}

  self_type& operator = (const char_type* const s)
   {m_str=s?s:traits2_type::empty_str();return *this;}

  self_type& operator = (const other_string_type& s)
   {tstr_to_tstr(m_str,s);return *this;}

  self_type& operator = (const other_char_type* const s)
   {tstr_to_tstr(m_str,s);return *this;}

  //modificators ----------------------------------------------------------
  self_type& erase()
   {m_str.erase();return *this;}

  self_type& append(const self_type& x);

  self_type& append(const string_type& s);

  self_type& append(const char_type* const s,size_type const n=-1);

  self_type& append(const other_string_type& s);

  self_type& append(const other_char_type* const s,size_type const n=-1);

  self_type& operator += (const self_type&);

  self_type& operator += (const string_type&);

  self_type& operator += (const char_type* const);

  self_type& operator += (const other_string_type&);

  self_type& operator += (const other_char_type* const);

  //selectors ------------------------------------------------------------
  const string_type& str()const
   {return m_str;}

  string_type& str()
   {return m_str;}

  operator const string_type& () const
   {return m_str;}

  operator string_type& ()
   {return m_str;}

  //navigation -----------------------------------------------------------
  iterator begin()
   {return m_str.begin();}

  iterator end()
   {return m_str.end();}

  const_iterator begin()const
   {return m_str.begin();}

  const_iterator end()const
   {return m_str.end();}

 private:
  string_type m_str;
};//t_string_au

////////////////////////////////////////////////////////////////////////////////
//stream operator

template<class stringT>
std::basic_ostream<typename stringT::value_type,typename stringT::traits_type>&
 operator << (std::basic_ostream<typename stringT::value_type,typename stringT::traits_type>& os,
              const t_string_au<stringT>&                                                     s)
{
 return os<<s.str();
}//operator <<

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_string_au.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
