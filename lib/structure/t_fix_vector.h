////////////////////////////////////////////////////////////////////////////////
//Шаблон для работы с массивами фиксированной ёмкости
//                                        Коваленко Дмитрий. 14 июля 2003 года.
#ifndef _t_fix_vector_H_
#define _t_fix_vector_H_

#ifndef NDEBUG
# include <structure/t_vector_debug_iterator.h>
#else
# include <structure/t_common.h>
# include <iterator>
#endif

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<size_t N,class T>
class t_fix_vector;

////////////////////////////////////////////////////////////////////////////////
//class t_fix_vector

template<size_t N,class T>
class t_fix_vector_base
{
 private:
  typedef t_fix_vector_base<N,T>                           self_type;

  t_fix_vector_base(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  enum{num_of_elements=N};

  typedef T                                                value_type;
  typedef size_t                                           size_type;

  typedef value_type*                                      pointer;
  typedef const value_type*                                const_pointer;

 public:
  size_type m_size;

 public:
  t_fix_vector_base();

 ~t_fix_vector_base();

  //interface ------------------------------------------------------------
  pointer buffer();

  const_pointer buffer()const;

  void clear();

 private:
  template<size_t alignN>
  struct tag_align_traits;

  template<>
  struct tag_align_traits<1>{typedef __int8 type;};

  template<>
  struct tag_align_traits<2>{typedef __int16 type;};

  template<>
  struct tag_align_traits<4>{typedef __int32 type;};

  template<>
  struct tag_align_traits<8>{typedef __int64 type;};

 private:
  union
  {
   typename tag_align_traits<__alignof(value_type)>::type m_aligner;

   char m_buffer[((num_of_elements==0)?1:num_of_elements)*sizeof(value_type)];
  };
};//class t_fix_vector_base

////////////////////////////////////////////////////////////////////////////////
//class t_fix_vector

template<size_t N,class T>
class t_fix_vector:private t_fix_vector_base<N,T>
{
 private:
  typedef t_fix_vector<N,T>                                self_type;
  typedef t_fix_vector_base<N,T>                           inherited;

 public: //typedefs ------------------------------------------------------
  enum{num_of_elements=N};

  typedef typename inherited::value_type                   value_type;
  typedef typename inherited::size_type                    size_type;
  typedef ptrdiff_t                                        difference_type;

  typedef typename inherited::pointer                      pointer;
  typedef typename inherited::const_pointer                const_pointer;

  typedef value_type&                                      reference;
  typedef const value_type&                                const_reference;

 #ifndef NDEBUG //debug code
  typedef t_vector_debug_iterator<self_type>               iterator;
  typedef t_vector_debug_const_iterator<self_type>         const_iterator;
 #else
  typedef pointer                                          iterator;
  typedef const_pointer                                    const_iterator;
 #endif

 public: //constructors/destructors --------------------------------------

  //[Kovalenko Dmitry 01.01.2008] Default constructor can be defined after
  // verification of all sources which uses a t_fix_vector

  t_fix_vector();

  explicit t_fix_vector(size_t n);

  t_fix_vector(const self_type& x);

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<typename Iterator>
  t_fix_vector(Iterator first,Iterator last);
 #else
  t_fix_vector(const_iterator first,const_iterator last);
 #endif

 ~t_fix_vector();

  self_type& operator = (const self_type& x);

  //selectors ------------------------------------------------------------
  iterator         begin();
  iterator         end();

  const_iterator   cbegin() const;
  const_iterator   cend()   const;

  const_iterator   begin() const;
  const_iterator   end()   const;

  size_type        size()const;
  bool             empty()const;
  bool             full()const;

  size_type        capacity()const;

  //accessors ------------------------------------------------------------
  pointer          data();
  const_pointer    data()const;

  reference        operator [] (size_type i);
  const_reference  operator [] (size_type i)const;

  reference        at(size_type i);
  const_reference  at(size_type i)const;

  reference        front();
  reference        back();

  const_reference  front()const;
  const_reference  back()const;

  //modificators ---------------------------------------------------------
  void assign(const_iterator first,const_iterator last);

  void push_back(const value_type& x);

#if(COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0)
  template<class... Args>
  void emplace_back(Args&&... args);
#endif

  void pop_back();

  void resize(size_t n);

  /// <summary>
  ///  Inserts x before position. The return value points to the inserted x.
  /// </summary>
  iterator insert(iterator position,const value_type& x);

  using inherited::clear;

  iterator erase(iterator first,iterator last);

  iterator erase(iterator first);

 private:
 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<typename Iterator>
  void construct(Iterator first,Iterator last,std::input_iterator_tag);

  template<typename Iterator>
  void construct(Iterator first,Iterator last,std::random_access_iterator_tag);
 #else
  void construct(const_iterator first,const_iterator last);
 #endif

 private:
  COMP_CONF_DECLSPEC_NORETURN
  static void helper__throw_bad_alloc(size_type n);

 private:
  using inherited::m_size;
};//class t_fix_vector

////////////////////////////////////////////////////////////////////////////////
//non-member operators

template<size_t N,class T>
inline bool operator == (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b);

template<size_t N,class T>
inline bool operator != (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b);

template<size_t N,class T>
inline bool operator <  (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b);

template<size_t N,class T>
inline bool operator <= (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b);

template<size_t N,class T>
inline bool operator >  (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b);

template<size_t N,class T>
inline bool operator >= (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b);

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_fix_vector.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
