////////////////////////////////////////////////////////////////////////////////
//Builder of linear vector from separated blocks
//                                                Kovalenko Dmitry. 14.02.2010
#ifndef _t_deque_adapter_H_
#define _t_deque_adapter_H_

#include <structure/t_common.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_deque_adapter

//
// TBlockIterator
//  iterator to structure with {first,last} members
//
template<class TBlockIterator,class TValue>
class t_deque_adapter
{
 private:
  typedef t_deque_adapter<TBlockIterator,TValue>         self_type;

  t_deque_adapter(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef TBlockIterator                                 block_iterator;
  typedef TValue                                         value_type;

  typedef size_t                                         size_type;

  typedef value_type&                                    reference;
  typedef const value_type&                              const_reference;

 public:
  t_deque_adapter(block_iterator first_block,
                  block_iterator last_block);

 ~t_deque_adapter();

  //selectors ------------------------------------------------------------
  size_type size()const;

  bool empty()const;

  //accessors ------------------------------------------------------------
  const_reference operator [] (size_type i)const;

 private:
  block_iterator navigate(size_type& i)const;

 private:
  block_iterator m_first_block;
  block_iterator m_last_block;

  size_type m_size;
};//class t_deque_adapter

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_deque_adapter.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
