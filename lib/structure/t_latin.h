////////////////////////////////////////////////////////////////////////////////
//Utilities for latin symbols
//                                                 Kovalenko Dmitry. 25.01.2011.
#ifndef _lcpi_lib_structure__t_latin_H_
#define _lcpi_lib_structure__t_latin_H_

#include <structure/t_latin_upper.h>
#include <structure/t_latin_lower.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//comparasion functions - UNICODE

inline bool equal_latin_wchar_i(const wchar_t c1,const wchar_t c2)
{
 return latin_upper(c1)==latin_upper(c2);
}//equal_latin_wchar_i

//------------------------------------------------------------------------
inline bool not_equal_latin_wchar_i(const wchar_t c1,const wchar_t c2)
{
 return latin_upper(c1)!=latin_upper(c2);
}//not_equal_latin_wchar_i

////////////////////////////////////////////////////////////////////////////////
//comparasion functions - ANSI

////////////////////////////////////////////////////////////////////////////////
//class t_latin_equal_i

template<typename TChar>
class t_latin_equal_i
{
 public: //typedefs ------------------------------------------------------
  using char_type=TChar;

 public:
  t_latin_equal_i()
  {
  }

  bool operator () (char_type const c1,
                    char_type const c2)const
  {
   return latin_upper(c1)==latin_upper(c2);
  }//
};//class t_latin_equal_i

////////////////////////////////////////////////////////////////////////////////
//class t_latin_less_i

template<typename TChar>
class t_latin_less_i
{
 public: //typedefs ------------------------------------------------------
  using char_type=TChar;

 public:
  t_latin_less_i()
  {
  }

  bool operator () (char_type const c1,
                    char_type const c2)const
  {
   return latin_upper(c1)<latin_upper(c2);
  }//
};//class t_latin_less_i

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
