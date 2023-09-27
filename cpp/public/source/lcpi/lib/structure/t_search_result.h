////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 28.02.2003.
#ifndef _cpp_public_lcpi_lib_structure__t_search_result_H_
#define _cpp_public_lcpi_lib_structure__t_search_result_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_search_result

template<typename TIterator,typename TResult=bool>
class t_search_result
{
 private:
  using self_type       =t_search_result<TIterator,TResult>;

 public: //typedefs ------------------------------------------------------
  using iterator        =TIterator;
  using result_type     =TResult;

 public:
  iterator     position;
  result_type  result;

 public:
  t_search_result();

  t_search_result(const iterator& _p,result_type _r);

  template<typename TOtherIterator>
  t_search_result(const t_search_result<TOtherIterator,TResult>& x);

 ~t_search_result();

  //operators ------------------------------------------------------------
  operator result_type () const {return result;}
};//class t_search_result

////////////////////////////////////////////////////////////////////////////////
//class t_search_result

template<typename TIterator,typename TResult>
inline t_search_result<TIterator,TResult>::t_search_result()
 :position(iterator())
 ,result()
{
}

//------------------------------------------------------------------------
template<typename TIterator,typename TResult>
inline t_search_result<TIterator,TResult>::t_search_result(const iterator& _p,result_type _r)
 :position(_p)
 ,result(_r)
{
}

//------------------------------------------------------------------------
template<typename TIterator,typename TResult>
template<class TOtherIterator>
inline t_search_result<TIterator,TResult>::t_search_result(const t_search_result<TOtherIterator,TResult>& x)
 :position(x.position)
 ,result(x.result)
{
}

//------------------------------------------------------------------------
template<typename TIterator,typename TResult>
inline t_search_result<TIterator,TResult>::~t_search_result()
{
}

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
