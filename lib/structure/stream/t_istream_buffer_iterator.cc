////////////////////////////////////////////////////////////////////////////////
#ifndef _t_istream_buffer_iterator_CC_
#define _t_istream_buffer_iterator_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_istream_buffer_iterator

template<typename T,class Traits>
t_basic_istream_buffer_iterator<T,Traits>::t_basic_istream_buffer_iterator()
 :m_buf    (nullptr)
 ,m_value  (value_type())
 ,m_ok     (true)
{;}

//------------------------------------------------------------------------
template<typename T,class Traits>
t_basic_istream_buffer_iterator<T,Traits>::t_basic_istream_buffer_iterator
                                           (buffer_type* const buf)
 :m_buf    (buf)
 ,m_value  (value_type())
 ,m_ok     (buf==nullptr)
{;}

//------------------------------------------------------------------------
template<typename T,class Traits>
t_basic_istream_buffer_iterator<T,Traits>::t_basic_istream_buffer_iterator
                                           (buffer_type& buf)
 :m_buf    (&buf)
 ,m_value  (value_type())
 ,m_ok     (false)
{;}

//------------------------------------------------------------------------
template<typename T,class Traits>
typename t_basic_istream_buffer_iterator<T,Traits>::reference
 t_basic_istream_buffer_iterator<T,Traits>::operator * () const
{
 assert(m_buf);

 this->make_ok();

 assert(m_buf);

 return m_value;
}//operator *

//------------------------------------------------------------------------
template<typename T,class Traits>
t_basic_istream_buffer_iterator<T,Traits>&
 t_basic_istream_buffer_iterator<T,Traits>::operator ++ ()
{
 assert(m_buf);

 _VERIFY(m_buf->skip());
 
 m_ok=false;

 return *this;
}//operator ++

//------------------------------------------------------------------------
template<typename T,class Traits>
bool t_basic_istream_buffer_iterator<T,Traits>::equal(const self_type& x)const
{
#ifndef NDEBUG
 if(m_buf!=nullptr && x.m_buf!=nullptr)
 {
  assert(m_buf==x.m_buf);
 }
#endif
 
 this->make_ok();
 
 x.make_ok();

 return m_buf==x.m_buf;
}//equal

//------------------------------------------------------------------------
template<typename T,class Traits>
void t_basic_istream_buffer_iterator<T,Traits>::make_ok()const
{
 if(m_ok)
  return;

 assert(m_buf!=nullptr);

 if(!m_buf->cur(&m_value))
  m_buf=nullptr;

 m_ok=true;
}//make_ok

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif