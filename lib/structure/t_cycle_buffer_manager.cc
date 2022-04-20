////////////////////////////////////////////////////////////////////////////////
//Cycle buffer manager
//                                               Kovalenko Dmitry. 03.09.2015
#ifndef _t_cycle_buffer_manager_CC_
#define _t_cycle_buffer_manager_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_cycle_buffer_manager__num_traits

template<typename TSize>
t_cycle_buffer_manager__num_traits<TSize>::t_cycle_buffer_manager__num_traits
                                           (index_type begin,
                                            index_type end)
 :m_begin(begin)
 ,m_end(end)
 ,m_size(0)
{
 assert(m_begin<=m_end);
}//t_cycle_buffer_manager__num_traits

//interface --------------------------------------------------------------
template<typename TSize>
typename t_cycle_buffer_manager__num_traits<TSize>::size_type
 t_cycle_buffer_manager__num_traits<TSize>::capacity()const
{
 assert(m_begin<=m_end);

 return m_end-m_begin;
}//capacity

//------------------------------------------------------------------------
template<typename TSize>
typename t_cycle_buffer_manager__num_traits<TSize>::size_type
 t_cycle_buffer_manager__num_traits<TSize>::size()const
{
 return m_size;
}//size

//------------------------------------------------------------------------
template<typename TSize>
bool t_cycle_buffer_manager__num_traits<TSize>::full()const
{
 return m_size==this->capacity();
}//full

//------------------------------------------------------------------------
template<typename TSize>
bool t_cycle_buffer_manager__num_traits<TSize>::empty()const
{
 return m_size==0;
}//empty

//------------------------------------------------------------------------
template<typename TSize>
typename t_cycle_buffer_manager__num_traits<TSize>::index_type
 t_cycle_buffer_manager__num_traits<TSize>::begin()const
{
 return m_begin;
}//begin

//------------------------------------------------------------------------
template<typename TSize>
typename t_cycle_buffer_manager__num_traits<TSize>::index_type
 t_cycle_buffer_manager__num_traits<TSize>::end()const
{
 return m_end;
}//end

//------------------------------------------------------------------------
template<typename TSize>
void t_cycle_buffer_manager__num_traits<TSize>::decrement_size()
{
 assert(m_size>=0);

 --m_size;
}//decrement_size

//------------------------------------------------------------------------
template<typename TSize>
void t_cycle_buffer_manager__num_traits<TSize>::increment_size()
{
 assert(m_size<this->capacity());

 ++m_size;
}//increment_size

//------------------------------------------------------------------------
template<typename TSize>
typename t_cycle_buffer_manager__num_traits<TSize>::index_type
 t_cycle_buffer_manager__num_traits<TSize>::get_prev(index_type x)const
{
 assert(x>m_begin);
 assert(x<=m_end);

 return --x;
}//get_prev

//------------------------------------------------------------------------
template<typename TSize>
typename t_cycle_buffer_manager__num_traits<TSize>::index_type
 t_cycle_buffer_manager__num_traits<TSize>::get_next(index_type x)const
{
 assert(x>=m_begin);
 assert(x<m_end);

 return ++x;
}//get_next

////////////////////////////////////////////////////////////////////////////////
//class t_cycle_buffer_manager

template<class TIndexTraits>
t_cycle_buffer_manager<TIndexTraits>::t_cycle_buffer_manager(index_type begin,
                                                             index_type end)
 :m_traits(begin,end)
 ,m_first (m_traits.begin())
 ,m_last  (m_traits.begin())
{;}

//interface --------------------------------------------------------------
template<class TIndexTraits>
typename t_cycle_buffer_manager<TIndexTraits>::size_type
 t_cycle_buffer_manager<TIndexTraits>::capacity()const
{
 return m_traits.capacity();
}//capacity

//------------------------------------------------------------------------
template<class TIndexTraits>
typename t_cycle_buffer_manager<TIndexTraits>::size_type
 t_cycle_buffer_manager<TIndexTraits>::size()const
{
 return m_traits.size();
}//size

//------------------------------------------------------------------------
template<class TIndexTraits>
bool t_cycle_buffer_manager<TIndexTraits>::full()const
{
 return m_traits.full();
}//full

//------------------------------------------------------------------------
template<class TIndexTraits>
bool t_cycle_buffer_manager<TIndexTraits>::empty()const
{
 return m_traits.empty();
}//empty

//------------------------------------------------------------------------
template<class TIndexTraits>
typename t_cycle_buffer_manager<TIndexTraits>::index_type
 t_cycle_buffer_manager<TIndexTraits>::front()const
{
 assert(!this->empty());

 return m_first;
}//front

//------------------------------------------------------------------------
template<class TIndexTraits>
typename t_cycle_buffer_manager<TIndexTraits>::index_type
 t_cycle_buffer_manager<TIndexTraits>::back()const
{
 assert(!this->empty());

 if(m_last!=m_traits.begin())
  return m_traits.get_prev(m_last);

 return m_traits.get_prev(m_traits.end());
}//back

//------------------------------------------------------------------------
template<class TIndexTraits>
void t_cycle_buffer_manager<TIndexTraits>::push_back()
{
 if(this->full())
 {
  assert(false);

  throw std::bad_alloc();
 }//if

 m_traits.increment_size();

 m_last=m_traits.get_next(m_last);

 if(m_last==m_traits.end())
  m_last=m_traits.begin();
}//push_back

//------------------------------------------------------------------------
template<class TIndexTraits>
void t_cycle_buffer_manager<TIndexTraits>::pop_back()
{
 assert(!this->empty());

 if(m_last==m_traits.begin())
  m_last=m_traits.end();

 m_last=m_traits.get_prev(m_last);

 m_traits.decrement_size();
}//pop_back

//------------------------------------------------------------------------
template<class TIndexTraits>
void t_cycle_buffer_manager<TIndexTraits>::push_front()
{
 if(this->full())
 {
  assert(false);

  throw std::bad_alloc();
 }//if

 if(m_first==m_traits.begin())
  m_first=m_traits.end();

 m_first=m_traits.get_prev(m_first);

 m_traits.increment_size();
}//push_front

//------------------------------------------------------------------------
template<class TIndexTraits>
void t_cycle_buffer_manager<TIndexTraits>::pop_front()
{
 assert(!this->empty());

 m_first=m_traits.get_next(m_first);

 if(m_first==m_traits.end())
  m_first=m_traits.begin();

 m_traits.decrement_size();
}//pop_front

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
