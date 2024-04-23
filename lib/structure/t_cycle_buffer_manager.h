////////////////////////////////////////////////////////////////////////////////
//Cycle buffer manager
//                                               Kovalenko Dmitry. 03.09.2015
#ifndef _lcpi_lib_structure__t_cycle_buffer_manager_H_
#define _lcpi_lib_structure__t_cycle_buffer_manager_H_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//contains

template<typename TSize>
class t_cycle_buffer_manager__num_traits;

template<typename TIndexTraits>
class t_cycle_buffer_manager;

////////////////////////////////////////////////////////////////////////////////
//class t_cycle_buffer_manager__num_traits

template<class TSize>
class t_cycle_buffer_manager__num_traits
{
 private:
  typedef t_cycle_buffer_manager__num_traits<TSize>           self_type;

  t_cycle_buffer_manager__num_traits(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef TSize                                               size_type;
  typedef TSize                                               index_type;

 public:
  t_cycle_buffer_manager__num_traits(index_type begin,
                                     index_type end);

  //interface ------------------------------------------------------------
  size_type capacity()const;

  size_type size()const;

  bool full()const;

  bool empty()const;

  index_type begin()const;

  index_type end()const;

  //----------------------------------------------------------------------
  void decrement_size();

  void increment_size();

  //----------------------------------------------------------------------
  index_type get_prev(index_type x)const;

  index_type get_next(index_type x)const;

 private:
  index_type   m_begin;
  index_type   m_end;
  size_type    m_size;
};//class t_cycle_buffer_manager__num_traits

////////////////////////////////////////////////////////////////////////////////
//class t_cycle_buffer_manager

template<class TIndexTraits>
class t_cycle_buffer_manager
{
 private:
  typedef t_cycle_buffer_manager<TIndexTraits>                self_type;

  t_cycle_buffer_manager(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef TIndexTraits                                        traits_type;

  typedef typename traits_type::size_type                     size_type;
  typedef typename traits_type::index_type                    index_type;

 public:
  t_cycle_buffer_manager(index_type begin,
                         index_type end);

  //selectors ------------------------------------------------------------
  size_type capacity()const;

  size_type size()const;

  bool full()const;

  bool empty()const;

  //accessors ------------------------------------------------------------
  index_type front()const;

  index_type back()const;

  //modificators ---------------------------------------------------------
  void push_back();

  void pop_back();

  void push_front();

  void pop_front();

 private:
  traits_type  m_traits;
  index_type   m_first;
  index_type   m_last;
};//class t_cycle_buffer_manager

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_cycle_buffer_manager.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
