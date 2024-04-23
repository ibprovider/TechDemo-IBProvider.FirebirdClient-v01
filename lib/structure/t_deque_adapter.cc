////////////////////////////////////////////////////////////////////////////////
#ifndef _lcpi_lib_structure__t_deque_adapter_CC_
#define _lcpi_lib_structure__t_deque_adapter_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_deque_adapter

template<class TBlockIterator,class TValue>
t_deque_adapter<TBlockIterator,TValue>::t_deque_adapter
                                           (block_iterator const first_block,
                                            block_iterator const last_block)
 :m_first_block(first_block),
  m_last_block(last_block),
  m_size(0)
{
 assert(m_first_block<=m_last_block);

 for(block_iterator block(m_first_block);block!=m_last_block;++block)
 {
  assert((*block).first<=(*block).last);

  m_size+=static_cast<size_type>((*block).last-(*block).first);
 }//for
}//t_deque_adapter

//------------------------------------------------------------------------
template<class TBlockIterator,class TValue>
t_deque_adapter<TBlockIterator,TValue>::~t_deque_adapter()
{;}

//selectors --------------------------------------------------------------
template<class TBlockIterator,class TValue>
typename t_deque_adapter<TBlockIterator,TValue>::size_type
 t_deque_adapter<TBlockIterator,TValue>::size()const
{
 return m_size;
}//size

//------------------------------------------------------------------------
template<class TBlockIterator,class TValue>
bool t_deque_adapter<TBlockIterator,TValue>::empty()const
{
 return m_size==0;
}//empty

//accessors --------------------------------------------------------------
template<class TBlockIterator,class TValue>
typename t_deque_adapter<TBlockIterator,TValue>::const_reference
 t_deque_adapter<TBlockIterator,TValue>::operator [] (size_t i) const
{
 assert(i<this->size());

 const block_iterator block(this->navigate(/*IN-OUT*/i));

 return *((*block).first+i);
}//operator []

//------------------------------------------------------------------------
template<class TBlockIterator,class TValue>
typename t_deque_adapter<TBlockIterator,TValue>::block_iterator
 t_deque_adapter<TBlockIterator,TValue>::navigate(size_type& i)const
{
 assert(i<this->size());

 block_iterator block(m_first_block);

 for(;block!=m_last_block;++block)
 {
  assert((*block).first<=(*block).last);

  if((*block).first==(*block).last)
   continue;

  const size_type s=static_cast<size_type>((*block).last-(*block).first);

  if(i<s)
   break;

  i-=s;
 }//for

 assert(block!=m_last_block);

 return block;
}//navigate

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
