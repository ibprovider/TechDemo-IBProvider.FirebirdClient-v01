////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                               Dmitry Kovalenko. 28.02.2003
#ifndef _t_search_result_H_
#define _t_search_result_H_

#include <structure/t_common.h>

////////////////////////////////////////////////////////////////////////////////
#ifndef COMP_CONF_SUPPORT_MEMBER_TEMPLATE
# error "COMP_CONF_SUPPORT_MEMBER_TEMPLATE not defiled"
#endif

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_search_result

template<class TIterator>
class t_search_result
{
 private:
  typedef t_search_result<TIterator>                self_type;

 public:
  typedef TIterator  iterator;

 public:
  iterator position;
  bool     result;

  t_search_result();

  t_search_result(const iterator& _p,bool _r);

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class TOtherIterator>
  t_search_result(const t_search_result<TOtherIterator>& x);
 #endif

 ~t_search_result();

  //operators ------------------------------------------------------------
  operator bool    () const {return result;}
  bool operator !  () const {return !result;}
};//class t_search_result

////////////////////////////////////////////////////////////////////////////////
//class t_search_result

template<class TIterator>
inline t_search_result<TIterator>::t_search_result()
 :position(iterator())
 ,result(false)
{
}

//------------------------------------------------------------------------
template<class TIterator>
inline t_search_result<TIterator>::t_search_result(const iterator& _p,bool _r)
 :position(_p)
 ,result(_r)
{
}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class TIterator>
template<class TOtherIterator>
inline t_search_result<TIterator>::t_search_result(const t_search_result<TOtherIterator>& x)
 :position(x.position)
 ,result(x.result)
{
}
#endif

//------------------------------------------------------------------------
template<class TIterator>
inline t_search_result<TIterator>::~t_search_result()
{
}

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/
#endif
