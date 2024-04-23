////////////////////////////////////////////////////////////////////////////////
//LCPI instrumental C++ library.
//                                                 Dmitry Kovalenko. 28.01.2005.
#ifndef _lcpi_lib_structure__t_string_au_H_
#define _lcpi_lib_structure__t_string_au_H_

#include <lcpi/lib/.config.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class stringT,class str_cvt_traits>
class t_string_au;

////////////////////////////////////////////////////////////////////////////////
//class t_string_au

template<class stringT,class str_cvt_traits>
class t_string_au LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_string_au<stringT,str_cvt_traits>;

 public: //typedefs ------------------------------------------------------
  using string_type         = stringT;
  using str_cvt_traits_type = str_cvt_traits;

  using char_type       = typename string_type::value_type;
  using traits_type     = typename string_type::traits_type;
  using size_type       = typename string_type::size_type;

  using iterator        = typename string_type::iterator;
  using const_iterator  = typename string_type::const_iterator;

 public:
  t_string_au()
  {
  }

  t_string_au(const self_type& x)
   :m_str(x.m_str)
  {
  }

  template<class TSrc>
  t_string_au(TSrc&& s)
  {
   str_cvt_traits_type::tstr_to_tstr(&m_str,std::forward<TSrc>(s));
  }

  //assign operators ------------------------------------------------------
  self_type& operator = (const self_type& x)
  {
   m_str=x.m_str;
   return *this;
  }

  //modificators ----------------------------------------------------------
  self_type& erase()
  {
   m_str.erase();
   return *this;
  }

  self_type& append(const self_type& x)
  {
   m_str+=x.m_str;
   return *this;
  }

  self_type& operator += (const self_type& x)
  {
   return this->append(x);
  }

  //selectors ------------------------------------------------------------
  bool empty() const
  {
   return m_str.empty();
  }//empty

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

  const_iterator cbegin()const
   {return m_str.cbegin();}

  const_iterator cend()const
   {return m_str.cend();}

 private:
  string_type m_str;
};//class t_string_au

////////////////////////////////////////////////////////////////////////////////
//stream operator

template<class stringT,class str_cvt_traits>
std::basic_ostream<typename stringT::value_type,typename stringT::traits_type>&
 operator << (std::basic_ostream<typename stringT::value_type,typename stringT::traits_type>& os,
              const t_string_au<stringT,str_cvt_traits>&                                    s)
{
 return os<<s.str();
}//operator <<

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
