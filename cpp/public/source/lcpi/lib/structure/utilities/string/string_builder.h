////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__string_builder_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__string_builder_H_

#include <lcpi/lib/structure/t_negative_one.h>
#include <string>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//template class basic_string_builder

template<class TStr>
class basic_string_builder
{
 public: //typedefs
  typedef TStr                                        string_type;
  typedef typename string_type::value_type            char_type;
  typedef typename string_type::size_type             size_type;

 public:
  static string_type& build(string_type* result,const char_type* p,size_type sz=-1);

  static string_type build(const char_type* p,size_type sz=-1);
};//class basic_string_builder

////////////////////////////////////////////////////////////////////////////////
//template class basic_string_builder

template<class TStr>
typename basic_string_builder<TStr>::string_type&
basic_string_builder<TStr>::build(string_type*     const result,
                                  const char_type* const p,
                                  size_type        const sz)
{
 assert(result);

 if(p==nullptr || sz==0)
  return result->erase();

 if(structure::is_negative_one(sz))
  return result->assign(p,std::char_traits<char_type>::length(p));

 return result->assign(p,sz);
}//build

//------------------------------------------------------------------------
template<class TStr>
typename basic_string_builder<TStr>::string_type
basic_string_builder<TStr>::build(const char_type* const p,
                                  size_type        const sz)
{
 if(p==NULL || sz==0)
  return string_type();

 if(structure::is_negative_one(sz))
  return string_type(p,std::char_traits<char_type>::length(p));

 return string_type(p,sz);
}//build

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
