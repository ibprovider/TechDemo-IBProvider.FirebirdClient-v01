////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 12.06.2001
#ifndef _cpp_public_lcpi_lib_structure__t_algorithm_CC_
#define _cpp_public_lcpi_lib_structure__t_algorithm_CC_

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//Align UP and DOWN

template<class TSize,class TAmount>
inline TSize align_up(TSize s,TAmount a)
{
 LCPI__assert(a>0);

 const TAmount mod=TAmount(s%a);

 LCPI__assert(mod<a);

 if(mod==0)
  return s;

 LCPI__assert(0<mod);

 return TSize(s+(a-mod));
}//align_up

//------------------------------------------------------------------------
template<class TSize,class TAmount>
inline TSize align_down(TSize s,TAmount a)
{
 LCPI__assert(a>0);

 const TAmount mod=TAmount(s%a);

 LCPI__assert(mod<a);

 return TSize(s-mod);
}//align_down

////////////////////////////////////////////////////////////////////////////////
//erase element from continer

template<class Container>
typename Container::iterator
 erase_element(Container& x,typename Container::const_reference value)
{
 const typename Container::iterator i=std::find(x.begin(),x.end(),value);

 return (i==x.end())?i:x.erase(i);
}//erase_element

//------------------------------------------------------------------------
template<class Container,class T>
typename Container::iterator
 remove_element(Container& x,const T& value)
{
 const typename Container::iterator i=std::find(x.begin(),x.end(),value);

 return (i==x.end())?i:x.erase(i);
}

////////////////////////////////////////////////////////////////////////////////
//calculate element count

template<class Container,class T>
typename Container::size_type count_element(const Container& x,const T& value)
{
 typename Container::size_type n=0;

 for(typename Container::const_iterator first=x.begin(),last=x.end();first!=last;++first)
  if(*first==value)++n;

 return n;
}//count_element

////////////////////////////////////////////////////////////////////////////////

template<class ForwardIterator1,class ForwardIterator2,class EqualOp>
ForwardIterator2 test_prefix(ForwardIterator1 beg,
                             ForwardIterator1 end,
                             ForwardIterator2 prefix_beg,
                             ForwardIterator2 prefix_end,
                             EqualOp          equal_op)
{
 while(beg!=end &&  prefix_beg!=prefix_end && equal_op(*beg,*prefix_beg))
 {
  ++beg;
  ++prefix_beg;
 }

 return prefix_beg;
}//test_prefix

//------------------------------------------------------------------------

template<class ForwardIterator1,class ForwardIterator2>
ForwardIterator2 test_prefix(ForwardIterator1 beg,
                             ForwardIterator1 end,
                             ForwardIterator2 prefix_beg,
                             ForwardIterator2 prefix_end)
{
 while(beg!=end &&  prefix_beg!=prefix_end && (*beg)==(*prefix_beg))
 {
  ++beg;
  ++prefix_beg;
 }

 return prefix_beg;
}//test_prefix

////////////////////////////////////////////////////////////////////////////////
//Extended lexicographical_compare (code from STLPort)

template<class ForwardIterator1,class ForwardIterator2>
int lexicographical_compare_3way(ForwardIterator1 first1,
                                 ForwardIterator1 last1,
                                 ForwardIterator2 first2,
                                 ForwardIterator2 last2)
{
 for(;;++first1,++first2)
 {
  if(first2==last2)
  {
   if(first1==last1)
    return 0;

   return 1;
  }//if

  LCPI__assert(first2!=last2);

  if(first1==last1)
  {
   return -1;
  }

  LCPI__assert(first1!=last1);

  if((*first1)<(*first2))
   return -1;

  if((*first2)<(*first1))
   return 1;
 }//for[ever]
}//lexicographical_compare_3way

//------------------------------------------------------------------------
//TLess
// implement operator () (a,b)
//  - return: true  for (a<b)
//            false for !(a<b)

template<class ForwardIterator1,class ForwardIterator2,class TLess>
int lexicographical_compare_3way(ForwardIterator1 first1,
                                 ForwardIterator1 last1,
                                 ForwardIterator2 first2,
                                 ForwardIterator2 last2,
                                 TLess            less_op)
{
 for(;first1!=last1 && first2!=last2;++first1,++first2)
 {
  if(less_op((*first1),(*first2)))
   return -1;

  if(less_op((*first2),(*first1)))
   return 1;
 }//for

 if(first2==last2)
 {
  //if (first1==last1) -> return (!true) -> return 0 -> equal sequentials
  //else return !(false) -> return 1 -> seq1>seq2

  return !(first1==last1);
 }//if

 //seq1<seq2
 return -1;
}//lexicographical_compare_3way

////////////////////////////////////////////////////////////////////////////////
//Compare pair members

template<class T1,class T2>
inline bool pair_less(const T1& a_first,const T2& a_second,
                      const T1& b_first,const T2& b_second)
{
 return a_first<b_first || (!(b_first<a_first) && a_second<b_second);
}//pair_less

////////////////////////////////////////////////////////////////////////////////
//Compare three-tuple members

template<class T1,class T2,class T3>
bool three_tuple_less(const T1& a_first,const T2& a_second,const T3& a_third,
                      const T1& b_first,const T2& b_second,const T3& b_third)
{
 if(a_first<b_first)
  return true;

 if(b_first<a_first)
  return false;

 if(a_second<b_second)
  return true;

 if(b_second<a_second)
  return false;

 if(a_third<b_third)
  return true;

 //b_third<=a_third)
 return false;
}//three_tuple_less

////////////////////////////////////////////////////////////////////////////////
//Copy element

template<class InputIterator,class OutputIterator>
std::pair<InputIterator,OutputIterator>
 copy(InputIterator  first,
      InputIterator  last,
      OutputIterator result_beg,
      OutputIterator result_end)
{
 for(;first!=last && result_beg!=result_end;++first,++result_beg)
  (*result_beg)=(*first);

 return std::make_pair(first,result_beg);
}//copy

////////////////////////////////////////////////////////////////////////////////
//Equal

#if(!__STL_HAS_ITERATOR_CATEGORY)

template<class InputIterator1,class InputIterator2>
bool equal(InputIterator1 first1,
           InputIterator1 last1,
           InputIterator2 first2,
           InputIterator2 last2)
{
 for(;;++first1,++first2)
 {
  if(first1==last1)
   return first2==last2;

  if(first2==last2)
   return false;

  if(!((*first1)==(*first2)))
   return false;
 }//for[ever]
}//equal

#else //__STL_HAS_ITERATOR_CATEGORY!=0 -----------------------------------

template<class RandomIterator1,class RandomIterator2>
bool equal_it_spec(RandomIterator1 first1,
                   RandomIterator1 last1,
                   RandomIterator2 first2,
                   RandomIterator2 last2,
                   std::random_access_iterator_tag /*cat1*/,
                   std::random_access_iterator_tag /*cat2*/)
{
 if((last1-first1)!=(last2-first2))
  return false;

 for(;first1!=last1;++first1,++first2)
 {
  LCPI__assert(first2!=last2);

  if(!((*first1)==(*first2)))
   return false;
 }//for

 LCPI__assert(first1==last1);
 LCPI__assert(first2==last2);

 return true;
}//equal_it_spec

//------------------------------------------------------------------------
template<class InputIterator1,class InputIterator2,class IteratorCat1,class IteratorCat2>
bool equal_it_spec(InputIterator1 first1,
                   InputIterator1 last1,
                   InputIterator2 first2,
                   InputIterator2 last2,
                   IteratorCat1   /*cat1*/,
                   IteratorCat2   /*cat2*/)
{
 for(;;++first1,++first2)
 {
  if(first1==last1)
   return first2==last2;

  if(first2==last2)
   return false;

  if(!((*first1)==(*first2)))
   return false;
 }//for[ever]
}//equal_it_spec

//------------------------------------------------------------------------
template<class Iterator1,class Iterator2>
inline bool equal(Iterator1 first1,
                  Iterator1 last1,
                  Iterator2 first2,
                  Iterator2 last2)
{
 return equal_it_spec(first1,
                      last1,
                      first2,
                      last2,
                      __STL_ITERATOR_CATEGORY(Iterator1),
                      __STL_ITERATOR_CATEGORY(Iterator2));
}//equal
#endif //__STL_HAS_ITERATOR_CATEGORY!=0

////////////////////////////////////////////////////////////////////////////////
//Equal

#if(!__STL_HAS_ITERATOR_CATEGORY)

template<class InputIterator1,class InputIterator2,class EqualOp>
bool equal(InputIterator1 first1,
           InputIterator1 last1,
           InputIterator2 first2,
           InputIterator2 last2,
           EqualOp        equal_op)
{
 for(;;++first1,++first2)
 {
  if(first1==last1)
   return first2==last2;

  if(first2==last2)
   return false;

  if(!equal_op((*first1),(*first2)))
   return false;
 }//for[ever]
}//equal

#else //__STL_HAS_ITERATOR_CATEGORY!=0 -----------------------------------

template<class RandomIterator1,class RandomIterator2,class EqualOp>
bool equal_it_spec(RandomIterator1 first1,
                   RandomIterator1 last1,
                   RandomIterator2 first2,
                   RandomIterator2 last2,
                   EqualOp         equal_op,
                   std::random_access_iterator_tag /*cat1*/,
                   std::random_access_iterator_tag /*cat2*/)
{
 if((last1-first1)!=(last2-first2))
  return false;

 for(;first1!=last1;++first1,++first2)
 {
  LCPI__assert(first2!=last2);

  if(!equal_op((*first1),(*first2)))
   return false;
 }//for

 LCPI__assert(first1==last1);
 LCPI__assert(first2==last2);

 return true;
}//equal_it_spec

//------------------------------------------------------------------------
template<class InputIterator1,class InputIterator2,class EqualOp,class IteratorCat1,class IteratorCat2>
bool equal_it_spec(InputIterator1 first1,
                   InputIterator1 last1,
                   InputIterator2 first2,
                   InputIterator2 last2,
                   EqualOp        equal_op,
                   IteratorCat1   /*cat1*/,
                   IteratorCat2   /*cat2*/)
{
 for(;;++first1,++first2)
 {
  if(first1==last1)
   return first2==last2;

  if(first2==last2)
   return false;

  if(!equal_op((*first1),(*first2)))
   return false;
 }//for[ever]
}//equal_it_spec

//------------------------------------------------------------------------
template<class Iterator1,class Iterator2,class EqualOp>
inline bool equal(Iterator1 first1,
                  Iterator1 last1,
                  Iterator2 first2,
                  Iterator2 last2,
                  EqualOp   equal_op)
{
 return equal_it_spec(first1,
                      last1,
                      first2,
                      last2,
                      equal_op,
                      __STL_ITERATOR_CATEGORY(Iterator1),
                      __STL_ITERATOR_CATEGORY(Iterator2));
}//equal
#endif //__STL_HAS_ITERATOR_CATEGORY!=0

////////////////////////////////////////////////////////////////////////////////
//Test the sorting of range

template<class Iterator,class LessOp>
bool is_sort(Iterator       first,
             Iterator const last,
             LessOp   const less_op)
{
 while(first!=last)
 {
  const Iterator prev(first);

  ++first;

  if(first==last)
   break;

  if(less_op(*first,*prev))
   return false;
 }//while

 return true;
}//is_sort

////////////////////////////////////////////////////////////////////////////////

template<class C1, class C2>
void append(C1* const target,const C2& source)
{
 LCPI__assert(target);

 target->append(source.begin(),source.end());
}//append

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
