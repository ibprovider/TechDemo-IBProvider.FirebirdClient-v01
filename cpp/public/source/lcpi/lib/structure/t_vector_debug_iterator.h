////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 25.10.2022
#ifndef _cpp_public_lcpi_lib_structure__t_vector_debug_iterator_H_
#define _cpp_public_lcpi_lib_structure__t_vector_debug_iterator_H_

#include <lcpi/lib/structure/t_debug.h>
#include <iterator>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class t_vector>
class t_vector_debug_iterator;

template<class t_vector>
class t_vector_debug_const_iterator;

////////////////////////////////////////////////////////////////////////////////
#ifndef __STL_RANDOM_ITERATOR_BASE_CLASS
# error "ERROR!"
#endif

////////////////////////////////////////////////////////////////////////////////
//class t_vector_debug_iterator

template<class t_vector>
class t_vector_debug_iterator
{
 private:
  typedef t_vector_debug_iterator<t_vector>               self_type;

 public:
  typedef std::random_access_iterator_tag                 iterator_category;
  typedef typename t_vector::value_type                   value_type;
  typedef typename t_vector::difference_type              difference_type;
  typedef typename t_vector::pointer                      pointer;
  typedef typename t_vector::reference                    reference;

  typedef t_vector                                        vector_type;

 public://constructors -------------------------------------------------
  t_vector_debug_iterator()
   :m_v(NULL),m_p(NULL){;}

  t_vector_debug_iterator(vector_type* const v,pointer const p)
   :m_v(v),m_p(p){;}

  t_vector_debug_iterator(const self_type& x)
   :m_v(x.m_v),m_p(x.m_p){;}

 public://selectors ----------------------------------------------------
  pointer get_ptr() const
  {
   return m_p;
  }//get_ptr

  reference operator * () const
   {
    assert(m_v!=NULL);
    //assert(m_p!=NULL);
    assert(m_v->begin().m_p<=m_p);
    assert(m_p<m_v->end().m_p);

    //[2018-07-20] Too slow ...
    //__STLS_CHECK_VALID_POINTER(m_p,sizeof(*m_p));

    return *m_p;
   }//operator *

 public: //modificators ------------------------------------------------
  self_type& operator ++ ()    {assert(m_v!=NULL);++m_p;return *this;}
  self_type& operator -- ()    {assert(m_v!=NULL);--m_p;return *this;}

  const self_type  operator ++ (int) {assert(m_v!=NULL);const self_type c(*this);++m_p;return c;}
  const self_type  operator -- (int) {assert(m_v!=NULL);const self_type c(*this);--m_p;return c;}

  self_type& operator += (difference_type x)
   {
    assert(m_v!=NULL);
    m_p+=x;
    return *this;
   }

  self_type& operator -= (difference_type x)
   {
    assert(m_v!=NULL);
    m_p-=x;
    return *this;
   }

  const self_type operator + (difference_type x)const
   {
    assert(m_v!=NULL);
    self_type tmp(*this);
    tmp.m_p+=x;
    return tmp;
   }

  const self_type operator - (difference_type x)const
   {
    assert(m_v!=NULL);
    self_type tmp(*this);
    tmp.m_p-=x;
    return tmp;
   }

 public: //pointer arithmetic operators --------------------------------
  const difference_type operator - (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p-x.m_p;
  }

 public: //compare -----------------------------------------------------
  bool operator == (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p==x.m_p;
  }

  bool operator != (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p!=x.m_p;
  }

  bool operator < (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p<x.m_p;
  }

  bool operator > (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p>x.m_p;
  }

  bool operator <= (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p<=x.m_p;
  }

  bool operator >= (const self_type& x)const
  {
   return !((*this)<x);
  }

 public:
  vector_type*       m_v;
  pointer            m_p;
};//class t_vector_debug_iterator

////////////////////////////////////////////////////////////////////////////////
//class t_vector_debug_const_iterator

template<class t_vector>
class t_vector_debug_const_iterator
{
 private:
  typedef t_vector_debug_const_iterator<t_vector>         self_type;

 public:
  typedef std::random_access_iterator_tag                 iterator_category;
  typedef typename t_vector::value_type                   value_type;
  typedef typename t_vector::difference_type              difference_type;
  typedef typename t_vector::const_pointer                pointer;
  typedef typename t_vector::const_reference              reference;

  typedef t_vector                                        vector_type;
  typedef typename vector_type::iterator                  iterator;

 public://constructors -------------------------------------------------
  t_vector_debug_const_iterator()
   :m_v(NULL),m_p(NULL){;}

  t_vector_debug_const_iterator(const vector_type* const v,pointer const p)
   :m_v(v),m_p(p){;}

  t_vector_debug_const_iterator(const self_type& x)
   :m_v(x.m_v),m_p(x.m_p){;}

  t_vector_debug_const_iterator(const iterator& x)
   :m_v(x.m_v),m_p(x.m_p){;}

 public://selectors ----------------------------------------------------
  pointer get_ptr() const
  {
   return m_p;
  }//get_ptr

  reference operator * () const
   {
    assert(m_v!=NULL);
    //assert(m_p!=NULL);
    assert(m_v->begin().m_p<=m_p);
    assert(m_p<m_v->end().m_p);

    //[2018-07-20] Too slow ...
    //__STLS_CHECK_VALID_POINTER(m_p,sizeof(*m_p));

    return *m_p;
   }//operator *

 public: //modificators ------------------------------------------------
  self_type& operator ++ ()    {assert(m_v!=NULL);++m_p;return *this;}
  self_type& operator -- ()    {assert(m_v!=NULL);--m_p;return *this;}

  const self_type  operator ++ (int) {assert(m_v!=NULL);const self_type c(*this);++m_p;return c;}
  const self_type  operator -- (int) {assert(m_v!=NULL);const self_type c(*this);--m_p;return c;}

  self_type& operator += (difference_type x)
   {
    assert(m_v!=NULL);
    m_p+=x;
    return *this;
   }

  self_type& operator -= (difference_type x)
   {
    assert(m_v!=NULL);
    m_p-=x;
    return *this;
   }

  const self_type operator + (difference_type x)const
   {
    assert(m_v!=NULL);
    self_type tmp(*this);
    tmp.m_p+=x;
    return tmp;
   }

  const self_type operator - (difference_type x)const
   {
    assert(m_v!=NULL);
    self_type tmp(*this);
    tmp.m_p-=x;
    return tmp;
   }

 public: //pointer arithmetic operators --------------------------------
  const difference_type operator - (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p-x.m_p;
  }

 public: //compare -----------------------------------------------------
  bool operator == (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p==x.m_p;
  }

  bool operator != (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p!=x.m_p;
  }

  bool operator < (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p<x.m_p;
  }

  bool operator > (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p>x.m_p;
  }

  bool operator <= (const self_type& x)const
  {
   assert(m_v==x.m_v);
   return m_p<=x.m_p;
  }

  bool operator >= (const self_type& x)const
  {
   return !((*this)<x);
  }

 public:
  const vector_type* m_v;
  pointer            m_p;
};//class t_vector_debug_const_iterator

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
