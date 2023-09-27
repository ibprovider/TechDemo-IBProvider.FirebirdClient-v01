////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 03.10.2016.
#ifndef _cpp_public_lcpi_lib_structure__t_const_string_H_
#define _cpp_public_lcpi_lib_structure__t_const_string_H_

#include <lcpi/lib/structure/t_const_str_box.h>
#include <lcpi/lib/structure/t_smart_object.h>
#include <lcpi/lib/structure/t_smart_object_ptr.h>
#include <lcpi/lib/structure/t_vector_debug_iterator.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

#ifndef COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001
# error COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001 not defined!
#endif

////////////////////////////////////////////////////////////////////////////////
//content

template<typename charT>
class t_basic_const_string_data;

template<typename charT,const charT* const staticSTR>
class t_basic_const_string_data__static;

template<typename charT,class Allocator>
class t_basic_const_string_data__dynamic;

template<typename charT,class charTraits>
class t_basic_const_string;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string

template<typename charT>
class t_basic_const_string_data:public t_smart_interface
{
 private:
  typedef t_basic_const_string_data                               self_type;

 public: //typedefs ------------------------------------------------------
  typedef t_smart_object_ptr<self_type>                           self_ptr;

  typedef size_t                                                  size_type;
  typedef charT                                                   char_type;

  typedef const char_type*                                        const_pointer;

 public:
  virtual size_type size()const=0;

  virtual const_pointer data()const=0;
};//class t_basic_const_string_data

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string_data__static

template<typename charT,const charT* const staticSTR>
class t_basic_const_string_data__static LCPI_CPP_CFG__CLASS__FINAL
 :public t_basic_smart_interface_impl__static_v2<t_basic_const_string_data<charT> >
{
 private:
  typedef t_basic_const_string_data__static<charT,staticSTR>           self_type;
  typedef t_basic_const_string_data<charT>                        base_type;

  t_basic_const_string_data__static(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef typename base_type::self_ptr                            self_ptr;
  typedef typename base_type::char_type                           char_type;
  typedef typename base_type::size_type                           size_type;
  typedef typename base_type::const_pointer                       const_pointer;

 private:
  typedef std::char_traits<char_type>                             char_traits_type;

 private:
  t_basic_const_string_data__static()
   :m_size(char_traits_type::length(structure::not_null_ptr(staticSTR)))
  {;}

 ~t_basic_const_string_data__static();

 public:
  static self_ptr create();

  //interface ------------------------------------------------------------
  virtual size_type size()const COMP_W000004_OVERRIDE_FINAL;

  virtual const_pointer data()const COMP_W000004_OVERRIDE_FINAL;

 private:
  const size_type m_size;

 private:
  static self_type sm_instance;
};//class t_basic_const_string_data__static

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string_data__dynamic

template<typename charT,class Allocator>
class t_basic_const_string_data__dynamic LCPI_CPP_CFG__CLASS__FINAL
 :public t_basic_smart_interface_impl__dynamic<t_basic_const_string_data<charT>,Allocator>
{
 private:
  typedef t_basic_const_string_data__dynamic<charT,Allocator>     self_type;
  typedef t_basic_const_string_data<charT>                        base_type;

  t_basic_const_string_data__dynamic(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef typename base_type::self_ptr                            self_ptr;
  typedef typename base_type::char_type                           char_type;
  typedef typename base_type::size_type                           size_type;
  typedef typename base_type::const_pointer                       const_pointer;

 private:
  t_basic_const_string_data__dynamic(size_type const sz)
   :m_size(sz)
  {;}

  virtual ~t_basic_const_string_data__dynamic();

 public:
  static self_ptr create(size_type     sz,
                         const_pointer str);

 private:
  virtual size_type size()const COMP_W000004_OVERRIDE_FINAL;

  virtual const_pointer data()const COMP_W000004_OVERRIDE_FINAL;

 private:
  typedef typename Allocator::template rebind<void>::other raw_allocator_type;

  static void* operator new (size_t const sz); //not impl

  static void* operator new (size_t,void* const pv)
  {//DONE: проверить
   return pv;
  }

 public:
  static void operator delete (void* pv)
  {
   return raw_allocator_type::instance.deallocate(pv,0);
  }

 #if(COMP_CONF_SUPPORT_OPERATOR_DELETE_EX)
  static void operator delete(void* /*pv*/,void* /*pv2*/)
  {
   //memory will be deallocated in catch of self_type::create
  }
 #endif

 private:
  const size_type m_size;

  char_type m_items[1];
};//class t_basic_const_string_data__dynamic

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string_helper

#if(COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001!=0)

template<typename charT>
class t_basic_const_string_helper
{
};//class t_basic_const_string_helper

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string_helper<char>

template<>
class t_basic_const_string_helper<char>
{
 public:
  static const char sm_emptyStr[1];
};//class t_basic_const_string_helper<char>

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string_helper<wchar_t>

template<>
class t_basic_const_string_helper<wchar_t>
{
 public:
  static const wchar_t sm_emptyStr[1];
};//class t_basic_const_string_helper<wchar_t>

#endif

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string

template<typename charT,class charTraits>
class t_basic_const_string LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef t_basic_const_string<charT,charTraits>  self_type;

 public: //typedefs ------------------------------------------------------
  typedef charTraits                              traits_type;
  
  typedef t_basic_const_string_data<charT>        data_type;

  typedef t_smart_object_ptr<data_type>           data_ptr;

  typedef ptrdiff_t                               difference_type;

  typedef typename data_type::size_type           size_type;
  typedef typename data_type::char_type           char_type;
  typedef typename data_type::const_pointer       const_pointer;

  typedef char_type                               value_type;

  typedef std::char_traits<char_type>             char_traits_type;

  typedef const_pointer                           pointer;

  typedef const value_type&                       reference;
  typedef const value_type&                       const_reference;

 #ifndef NDEBUG
  typedef structure::t_vector_debug_iterator<const self_type> const_iterator;
 #else
  typedef const char_type*                                    const_iterator;
 #endif

  typedef const_iterator                          iterator;

  typedef t_basic_const_str_box<char_type>        str_box_type;

 public:
  t_basic_const_string();

  t_basic_const_string(const self_type& x);

  explicit t_basic_const_string(data_type* data);

  t_basic_const_string(self_type&& x);

  t_basic_const_string(data_ptr&& data);

 ~t_basic_const_string();

  self_type& operator = (const self_type& x);

  self_type& operator = (self_type&& x);

  void swap(self_type& x);

  //----------------------------------------------------------------------
  template<const charT* const staticSTR>
  static self_type create();

  template<class Allocator>
  static self_type create(const str_box_type& str);

  //----------------------------------------------------------------------
  self_type& clear();

  //----------------------------------------------------------------------
  operator t_basic_const_str_box<charT> () const;

  //----------------------------------------------------------------------
  bool empty() const;

  size_type size() const;

  size_type length() const;

  const_reference operator [] (size_type index)const;

  const_pointer data()const;

  //----------------------------------------------------------------------
  const_iterator cbegin()const;

  const_iterator cend()const;

  const_iterator begin()const;

  const_iterator end()const;

  //----------------------------------------------------------------------
  bool equal(const_pointer str)const;

  bool equal(const_pointer str,size_type sz)const;

  bool equal(const self_type& x)const;

  //----------------------------------------------------------------------
  int compare(const self_type& x)const;

 private:
  static data_ptr helper__create_empty_data();

  static bool helper__equal
               (const char_type* s1,
                size_t           l1,
                const char_type* s2,
                size_t           l2);

  static int helper__compare
              (const char_type* s1,
               size_t           l1,
               const char_type* s2,
               size_t           l2);

 private:
  data_ptr m_data;

 private:
 #if(COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001==0)
  static const typename char_type sm_emptyStr[];
 #endif
};//class t_basic_const_string

////////////////////////////////////////////////////////////////////////////////

typedef t_basic_const_string<char>          t_const_string;

typedef t_basic_const_string<wchar_t>       t_const_wstring;

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType>
std::basic_ostream<charT,traitsType>&
 operator << (std::basic_ostream<charT,traitsType>&                    s,
              const structure::t_basic_const_string<charT,traitsType>& str);

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType>
bool operator == (const structure::t_basic_const_string<charT,traitsType>& s1,
                  const structure::t_basic_const_string<charT,traitsType>& s2);

template<typename charT,typename traitsType>
bool operator != (const structure::t_basic_const_string<charT,traitsType>& s1,
                  const structure::t_basic_const_string<charT,traitsType>& s2);

template<typename charT,typename traitsType>
bool operator < (const structure::t_basic_const_string<charT,traitsType>& s1,
                 const structure::t_basic_const_string<charT,traitsType>& s2);

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType,typename Allocator>
bool operator == (const std::basic_string<charT,traitsType,Allocator>&      s1,
                  const structure::t_basic_const_string<charT,traitsType>&  s2);

template<typename charT,typename traitsType,typename Allocator>
bool operator != (const std::basic_string<charT,traitsType,Allocator>&      s1,
                  const structure::t_basic_const_string<charT,traitsType>&  s2);

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType,typename Allocator>
bool operator == (const structure::t_basic_const_string<charT,traitsType>&  s1,
                  const std::basic_string<charT,traitsType,Allocator>&      s2);

template<typename charT,typename traitsType,typename Allocator>
bool operator != (const structure::t_basic_const_string<charT,traitsType>&  s1,
                  const std::basic_string<charT,traitsType,Allocator>&      s2);

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType>
bool operator == (const charT*                                              s1,
                  const structure::t_basic_const_string<charT,traitsType>&  s2);

template<typename charT,typename traitsType>
bool operator != (const charT*                                              s1,
                  const structure::t_basic_const_string<charT,traitsType>&  s2);

////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename traitsType>
bool operator == (const structure::t_basic_const_string<charT,traitsType>&  s1,
                  const charT*                                              s2);

template<typename charT,typename traitsType>
bool operator != (const structure::t_basic_const_string<charT,traitsType>&  s1,
                  const charT*                                              s2);

////////////////////////////////////////////////////////////////////////////////

template<typename charT>
t_basic_const_str_box<charT> make_str_box(const t_basic_const_string<charT>& s);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/t_const_string.cc>
////////////////////////////////////////////////////////////////////////////////

namespace std{
////////////////////////////////////////////////////////////////////////////////

template<typename charT,class traitsType>
void swap(lcpi::lib::structure::t_basic_const_string<charT,traitsType>& x1,
          lcpi::lib::structure::t_basic_const_string<charT,traitsType>& x2)
{
 x1.swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std
#endif
