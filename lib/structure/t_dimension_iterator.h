////////////////////////////////////////////////////////////////////////////////
//Dimension iterator.
//                                                 Kovalenko Dmitry. 03.02.2011.
#ifndef _t_dimension_iterator_H_
#define _t_dimension_iterator_H_

#include <structure/t_memory.h>
#include <structure/stl/t_stl_vector.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class T,class Allocator=t_void_allocator>
class t_dimension_iterator;

////////////////////////////////////////////////////////////////////////////////
//class t_dimension_iterator

template<class T,class Allocator>
class t_dimension_iterator
{
 private:
  typedef t_dimension_iterator<T,Allocator>            self_type;

 public: //typedefs
  typedef T                                            value_type;
  typedef Allocator                                    allocator_type;
  typedef typename allocator_type::size_type           size_type;
  typedef typename allocator_type::difference_type     difference_type;
  typedef t_stl_vector<T,allocator_type>               point_type;

  enum test_range_result
  {
   range_is_bad       =0,
   range_is_empty     =1,
   range_is_not_empty =2,
  };//enum test_range_result

 public:
  t_dimension_iterator();

  t_dimension_iterator(const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_dimension_iterator(self_type&& x);
 #endif

 ~t_dimension_iterator();

  self_type& operator = (const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (self_type&& x);
 #endif

  self_type& swap(self_type& x);

  //test range -----------------------------------------------------------
  static test_range_result test_range(value_type lower,value_type upper);

  //dimensions definition ------------------------------------------------
  self_type& clear();

  self_type& add(value_type lower,value_type upper);

  size_type dim()const;

  const value_type& get_lower_bound(size_type i_dim)const;
  const value_type& get_upper_bound(size_type i_dim)const;

  bool empty()const;

  //dimension navigation -------------------------------------------------
  bool ok()const;

  bool bof()const;

  bool eof()const;

  void restart();//move to first valid element

  void restart_from_end();//move to end valid element

  bool prev();
  bool next();

  self_type& operator ++ ();
  self_type  operator ++ (int);
  self_type& operator -- ();
  self_type  operator -- (int);

  operator bool   () const;

  bool operator ! () const;

  const point_type& cur()const;

  const value_type& operator [] (size_type i_dim)const;

 private:
 #ifndef NDEBUG
  void debug__self_check(const char* const trace)const;
 #endif

 private: //private typedefs ---------------------------------------------
  enum tag_state
  {
   state_ok  =0,
   state_bof =1,
   state_eof =2,
  };//enum tag_state

  struct tag_range
  {
   public:
    value_type lower;
    value_type upper;

   public:
    tag_range(value_type _lower,
              value_type _upper);

    bool empty()const;
  };//struct tag_range

  typedef tag_range range_type;

  typedef t_stl_vector<range_type,allocator_type> bounds_type;

 private:
  bounds_type m_bounds;   //dimension bounds
  point_type  m_pt;       //current point

  tag_state   m_state;
  bool        m_no_elements;
};//class t_dimension_iterator

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_dimension_iterator.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
