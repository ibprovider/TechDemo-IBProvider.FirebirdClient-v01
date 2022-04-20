////////////////////////////////////////////////////////////////////////////////
//Set of generic algorithms
//                                               Dmitry Kovalenko. 21.03.2001.
#ifndef _t_algorithm_H_
#define _t_algorithm_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/t_search_result.h>
#include <algorithm>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//Align UP and DOWN

template<class TSize,class TAmount>
inline TSize align_up(TSize s,TAmount a);

template<class TSize,class TAmount>
inline TSize align_down(TSize s,TAmount a);

////////////////////////////////////////////////////////////////////////////////
//STL-like search algorithms

template<class ForwardIterator,class T>
t_search_result<ForwardIterator> lower_search(ForwardIterator first,
                                              ForwardIterator last,
                                              const T&        value)
{
 ForwardIterator x(std::lower_bound(first,last,value));

 return t_search_result<ForwardIterator>(x,x!=last && !(value<(*x)));
}//lower_search

//------------------------------------------------------------------------
template<class ForwardIterator,class T,class Compare>
t_search_result<ForwardIterator> lower_search(ForwardIterator first,
                                              ForwardIterator last,
                                              const T&        value,
                                              Compare         comp)
{
 ForwardIterator x(std::lower_bound(first,last,value,comp));

 return t_search_result<ForwardIterator>(x,x!=last && !comp(value,*x));
}//lower_search

////////////////////////////////////////////////////////////////////////////////
//erase element from continer

template<class Container>
typename Container::iterator
 erase_element(Container& x,typename Container::const_reference value);

template<class Container,class T>
typename Container::iterator
 remove_element(Container& x,const T& value);

////////////////////////////////////////////////////////////////////////////////
//определение наличия элемента в контейнере

template<class Container,class T>
inline bool has_element(const Container& x,const T& value)
{
 return find(x.begin(),x.end(),value)!=x.end();
}

////////////////////////////////////////////////////////////////////////////////
//подсчет числа элементов в контейнере

template<class Container,class T>
typename Container::size_type count_element(const Container& x,const T& value);

////////////////////////////////////////////////////////////////////////////////
//проверка наличия префикса [prefix_beg,prefix_end) у последовательности [beg,end)

//return prefix_end if [beg,end) starting with [prefix_beg,prefix_end)

template<class ForwardIterator1,class ForwardIterator2,class EqualOp>
ForwardIterator2 test_prefix(ForwardIterator1 beg,
                             ForwardIterator1 end,
                             ForwardIterator2 prefix_beg,
                             ForwardIterator2 prefix_end,
                             EqualOp          equal_op);

template<class ForwardIterator1,class ForwardIterator2>
ForwardIterator2 test_prefix(ForwardIterator1 beg,
                             ForwardIterator1 end,
                             ForwardIterator2 prefix_beg,
                             ForwardIterator2 prefix_end);

////////////////////////////////////////////////////////////////////////////////
//Extended lexicographical_compare (code from STLPort)

template<class ForwardIterator1,class ForwardIterator2>
int lexicographical_compare_3way(ForwardIterator1 first1,
                                 ForwardIterator1 last1,
                                 ForwardIterator2 first2,
                                 ForwardIterator2 last2);

template<class ForwardIterator1,class ForwardIterator2,class TLess>
int lexicographical_compare_3way(ForwardIterator1 first1,
                                 ForwardIterator1 last1,
                                 ForwardIterator2 first2,
                                 ForwardIterator2 last2,
                                 TLess            less_op);

////////////////////////////////////////////////////////////////////////////////
//Compare pair members

template<class T1,class T2>
inline bool pair_less(const T1& a_first,const T2& a_second,
                      const T1& b_first,const T2& b_second);

////////////////////////////////////////////////////////////////////////////////
//Compare three-tuple members

template<class T1,class T2,class T3>
bool three_tuple_less(const T1& a_first,const T2& a_second,const T3& a_third,
                      const T1& b_first,const T2& b_second,const T3& b_third);

////////////////////////////////////////////////////////////////////////////////
//Copy element

template<class InputIterator,class OutputIterator>
std::pair<InputIterator,OutputIterator>
 copy(InputIterator  first,
      InputIterator  last,
      OutputIterator result_beg,
      OutputIterator result_end);

////////////////////////////////////////////////////////////////////////////////
//Equal

template<class Iterator1,class Iterator2>
bool equal(Iterator1 first1,
           Iterator1 last1,
           Iterator2 first2,
           Iterator2 last2);

template<class Iterator1,class Iterator2,class EqualOp>
bool equal(Iterator1 first1,
           Iterator1 last1,
           Iterator2 first2,
           Iterator2 last2,
           EqualOp   equal_op);

////////////////////////////////////////////////////////////////////////////////
//Test the sorting of range

template<class Iterator,class LessOp>
bool is_sort(Iterator first,
             Iterator last,
             LessOp   less_op);

////////////////////////////////////////////////////////////////////////////////

template<class C1, class C2>
void append(C1* target,const C2& source);

////////////////////////////////////////////////////////////////////////////////
//class t_comparer_3way

#if 0 //deprecated [2016-10-04]

template<class Arg1,class Arg2>
class t_comparer_3way:public std::binary_function<Arg1,Arg2,int>
{
 public:
  int operator () (const Arg1& a,const Arg2& b)const;
};//class t_comparer_3way

////////////////////////////////////////////////////////////////////////////////
//3way compare

template<class Arg1,class Arg2>
inline int compare_3way(const Arg1& a,const Arg2& b);

//------------------------------------------------------------------------
template<class Arg1,class Arg2,class TLess>
inline int compare_3way(const Arg1& a,const Arg2& b,const TLess& less);

#endif

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_algorithm.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
