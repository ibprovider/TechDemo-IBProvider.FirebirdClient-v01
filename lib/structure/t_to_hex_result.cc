////////////////////////////////////////////////////////////////////////////////
#ifndef _structure__t_to_hex_result_CC_
#define _structure__t_to_hex_result_CC_

#include <structure/t_char_traits2.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_to_hex_result

template<typename charT,typename T>
t_to_hex_result<charT,T>::t_to_hex_result()
{
 m_buffer.back()=0;
}//t_to_hex_result

//interface --------------------------------------------------------------
template<typename charT,typename T>
const charT* t_to_hex_result<charT,T>::c_str()const
{
 assert(m_buffer.back()==0);

 return m_buffer.data();
}//c_str

//------------------------------------------------------------------------
template<typename charT,typename T>
void t_to_hex_result<charT,T>::set(size_t const index,charT const ch)
{
 assert(index<self_type::c_N);

 assert(t_char_traits2<charT>::is_hex(ch));

 m_buffer[index]=ch;
}//set

//------------------------------------------------------------------------
template<typename charT,typename T>
void t_to_hex_result<charT,T>::set_term(size_t const index)
{
 assert(index<=self_type::c_N);

 m_buffer[index]=0;
}//set_term

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
