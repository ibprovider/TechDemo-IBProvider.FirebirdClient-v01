////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                  Dmitry Kovalenko. 04.09.2016
#ifndef _cpp_public_lcpi_lib_structure__t_first_last_CC_
#define _cpp_public_lcpi_lib_structure__t_first_last_CC_

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_first_last

template<class T>
t_first_last<T>::t_first_last()
 :first (value_type())
 ,last  (value_type())
{;}

//------------------------------------------------------------------------
template<class T>
t_first_last<T>::t_first_last(const self_type& x)
 :first (x.first)
 ,last  (x.last)
{;}

//------------------------------------------------------------------------
template<class T>
t_first_last<T>::t_first_last(const value_type& f,const value_type& l)
 :first (f)
 ,last  (l)
{;}

//------------------------------------------------------------------------
template<class T>
t_first_last<T>::~t_first_last()
{;}

//------------------------------------------------------------------------
template<class T>
t_first_last<T>& t_first_last<T>::operator = (const self_type& x)
{
 first =x.first;
 last  =x.last;

 return *this;
}//operator =

//------------------------------------------------------------------------
template<class T>
bool t_first_last<T>::empty()const
{
 return this->first==this->last;
}//empty

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
