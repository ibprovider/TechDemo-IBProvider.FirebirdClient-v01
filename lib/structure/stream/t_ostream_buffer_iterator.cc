////////////////////////////////////////////////////////////////////////////////
#ifndef _t_ostream_buffer_iterator_CC_
#define _t_ostream_buffer_iterator_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_ostream_buffer_iterator

template<class T,class Traits>
t_basic_ostream_buffer_iterator<T,Traits>::t_basic_ostream_buffer_iterator
                                           (buffer_type& buf)
 :m_buf(&buf),
  m_failed(false)
{;}

//------------------------------------------------------------------------
template<class T,class Traits>
t_basic_ostream_buffer_iterator<T,Traits>&
 t_basic_ostream_buffer_iterator<T,Traits>::operator = (const_reference x)
{
 assert(m_buf!=nullptr);

 if(!m_buf->put(x))
  m_failed=true;

 return *this;
}//operator =

//------------------------------------------------------------------------
template<class T,class Traits>
t_basic_ostream_buffer_iterator<T,Traits>&
 t_basic_ostream_buffer_iterator<T,Traits>::operator * ()
{
 return *this;
}//operator *

//------------------------------------------------------------------------
template<class T,class Traits>
t_basic_ostream_buffer_iterator<T,Traits>&
 t_basic_ostream_buffer_iterator<T,Traits>::operator ++ ()
{
 return *this;
}//operator ++

//------------------------------------------------------------------------
template<class T,class Traits>
bool t_basic_ostream_buffer_iterator<T,Traits>::failed()const
{
 return m_failed;
}//failed

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
