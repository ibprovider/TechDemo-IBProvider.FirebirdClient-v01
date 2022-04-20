////////////////////////////////////////////////////////////////////////////////
//Servcies for with version strings
//                                               Dmitry Kovalenko. 29.03.2005
#ifndef _t_str_version_H_
#define _t_str_version_H_

#include <structure/t_const_str_box.h>
#include <structure/t_memory.h>
#include <structure/stl/t_stl_vector.h>
#include <algorithm>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class charT,class Allocator=t_void_allocator>
class t_str_version;

////////////////////////////////////////////////////////////////////////////////
//unpack versions parts

template<class charT,class containerT>
bool get_str_version_parts_v2(const charT* ver,
                              containerT*  ver_parts); //throw

//------------------------------------------------------------------------
template<class charT,class containerT>
bool get_str_version_parts_v2(t_basic_const_str_box<charT> ver,
                              containerT*                  ver_parts); //throw

////////////////////////////////////////////////////////////////////////////////
//class t_str_version_part

template<class charT>
class t_str_version_part
{
 private:
  typedef t_str_version_part<charT>                 self_type;

 public: //typedefs -----------------------------------------------------
  typedef charT                                     char_type;

  typedef __STL_DEF_BASIC_STRING(charT)             string_type;

 public:
  t_str_version_part(const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_str_version_part(self_type&& x);
 #endif

  t_str_version_part(const string_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_str_version_part(string_type&& x);
 #endif

  self_type& operator = (const self_type&);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (self_type&& x);
 #endif

  void swap(self_type& x);

  //selectors -----------------------------------------------------------
  const string_type& value()const;

  bool is_zero()const;

 private:
  string_type m_value;
};//class t_str_version_part

////////////////////////////////////////////////////////////////////////////////
//external operators

template<class charT>
bool operator < (const t_str_version_part<charT>& p1,
                 const t_str_version_part<charT>& p2)
{
 if(p1.value().size()<p2.value().size())
  return true; //p1 less that p2

 if(p2.value().size()<p1.value().size())
  return false; //p2 less that p1

 return p1.value()<p2.value();
}//operator <

//------------------------------------------------------------------------
template<class charT>
inline bool operator == (const t_str_version_part<charT>& p1,
                         const t_str_version_part<charT>& p2)
{
 return p1.value()==p2.value();
}//operator ==

//------------------------------------------------------------------------
template<class charT>
inline bool operator != (const t_str_version_part<charT>& p1,
                         const t_str_version_part<charT>& p2)
{
 return p1.value()!=p2.value();
}//operator !=

////////////////////////////////////////////////////////////////////////////////
//class t_str_version

template<class charT,class Allocator>
class t_str_version
{
 private:
  typedef t_str_version<charT,Allocator>            self_type;

 public: //typedefs
  typedef charT                                     char_type;
  typedef Allocator                                 allocator_type;

  typedef __STL_DEF_BASIC_STRING(charT)             string_type;

  typedef t_basic_const_str_box<charT>              str_box_type;

  typedef t_str_version_part<char_type>             part_type;

  typedef t_stl_vector
           <part_type,
            allocator_type>                         part_vector;

  typedef typename part_vector::const_iterator      const_iterator;
  typedef typename part_vector::const_reference     const_reference;

  typedef typename part_vector::size_type           size_type;

 public:
  t_str_version();

  t_str_version(const self_type& x);

  explicit t_str_version(str_box_type str);

  self_type& operator = (const self_type& x);

  self_type& operator = (str_box_type str);

  //iterators ------------------------------------------------------------
  const_iterator begin() const;
  const_iterator end()   const;

  //selectors ------------------------------------------------------------
  size_type size()const;

  const_reference operator [] (size_type i)const;

  string_type str()const;

  //----------------------------------------------------------------------
  void swap(self_type& x);

 private: //--------------------------------------------------------------
  void internal_init(const str_box_type str);//throw

 private:
  part_vector m_parts;
};//class t_str_version

typedef t_str_version<char>                      str_version;
typedef t_str_version<wchar_t>                   wstr_version;

////////////////////////////////////////////////////////////////////////////////
//external operators

template<class charT,class Allocator>
inline bool operator == (const t_str_version<charT,Allocator>& v1,
                         const t_str_version<charT,Allocator>& v2);

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool operator != (const t_str_version<charT,Allocator>& v1,
                         const t_str_version<charT,Allocator>& v2);

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool operator < (const t_str_version<charT,Allocator>& v1,
                        const t_str_version<charT,Allocator>& v2);

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool operator > (const t_str_version<charT,Allocator>& v1,
                        const t_str_version<charT,Allocator>& v2);

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool operator <= (const t_str_version<charT,Allocator>& v1,
                         const t_str_version<charT,Allocator>& v2);

//------------------------------------------------------------------------
template<class charT,class Allocator>
inline bool operator >= (const t_str_version<charT,Allocator>& v1,
                         const t_str_version<charT,Allocator>& v2);

////////////////////////////////////////////////////////////////////////////////
//test version prefix

template<class charT,class Allocator>
int cmp_str_version_prefix(const t_str_version<charT,Allocator>& ver,
                           const t_str_version<charT,Allocator>& prefix);

//------------------------------------------------------------------------
template<class charT,class Allocator>
int cmp_str_version_prefix(const t_str_version<charT,Allocator>& ver,
                           const charT* const                    prefix);

//------------------------------------------------------------------------
template<class charT>
int cmp_str_version_prefix(const charT* const ver,
                           const charT* const prefix);

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool eq_str_version_prefix(const t_str_version<charT,Allocator>& ver,
                           const t_str_version<charT,Allocator>& prefix);

//------------------------------------------------------------------------
template<class charT,class Allocator>
bool eq_str_version_prefix(const t_str_version<charT,Allocator>& ver,
                           const charT* const                    prefix);

//------------------------------------------------------------------------
template<class charT>
bool eq_str_version_prefix(const charT* const ver,
                           const charT* const prefix);

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

namespace std{
////////////////////////////////////////////////////////////////////////////////
//swap specializations

template<typename charT>
void swap(structure::t_str_version_part<charT>& x1,
          structure::t_str_version_part<charT>& x2)
{
 x1.swap(x2);
}//swap

//------------------------------------------------------------------------
template<typename charT>
void swap(structure::t_str_version<charT>& x1,
          structure::t_str_version<charT>& x2)
{
 x1.swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_str_version.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
