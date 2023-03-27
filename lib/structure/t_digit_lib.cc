////////////////////////////////////////////////////////////////////////////////
//Реализация шаблонов <structure/t_digit_lib.h>
//                                     Коваленко Дмитрий. 22 декабря 2001 года.

#ifndef _t_digit_lib_CC_
#define _t_digit_lib_CC_

#include <structure/t_zero.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//template class t_fixed_precision_digit

template<size_t N>
const typename t_fixed_precision_digit<N>::size_type
 t_fixed_precision_digit<N>::sm_N=N;

//------------------------------------------------------------------------------
template<size_t N>
t_fixed_precision_digit<N>::t_fixed_precision_digit()
 :m_size(0)
{
 assert_s(sizeof(t_accessor)==sizeof(m_digits[0]));

 std::fill(std::begin(m_digits),std::end(m_digits),structure::zero);
}//t_fixed_precision_digit

//------------------------------------------------------------------------------
template<size_t N>
void t_fixed_precision_digit<N>::init()
{
 m_size=0;

 std::fill(std::begin(m_digits),std::end(m_digits),structure::zero);
}//init

//------------------------------------------------------------------------------
template<size_t N>
void t_fixed_precision_digit<N>::pack()
{
 while(!this->empty() && this->at(this->size()-1)==0)
  --m_size;
}//pack

//------------------------------------------------------------------------------
template<size_t N>
bool t_fixed_precision_digit<N>::inc()
{
 byte_type carrying=1;
 byte_type sum;

 for(size_type i=0;i!=max_size() && carrying;++i)
 {
  sum=byte_type(this->at(i)+carrying);

  carrying=(sum>=10);

  assert(carrying==0 || carrying==1);

  this->at(i)=carrying?byte_type(0):sum;
 }//for i

 return !carrying;
}//inc

//------------------------------------------------------------------------------
template<size_t N>
bool t_fixed_precision_digit<N>::shift_on_positive_scale(size_type const n)
{
 //упаковываем число
 this->pack();

 if(n==0)
  return true;

 if(this->empty())
  return true;

 assert(this->size()<=this->max_size());

 if((this->max_size()-this->size())<n)
  return false;//OVERFLOW

 for(size_type i=this->size();i!=0;)
 {
  --i;

  this->at(i+n)=this->at(i);
 }//for

 for(size_type i=0;i!=n;++i)
  this->at(i)=0;

 return true;
}//shift_on_positive_scale

//------------------------------------------------------------------------------
template<size_t N>
bool t_fixed_precision_digit<N>::shift_on_negative_scale(size_type const n,bool const round)
{
 //упаковываем число
 this->pack();

 if(n==0)
  return true;

 if(this->empty())
  return true;

 if(n>this->size())
 {
  this->init();
 }
 else
 {
  const bool make_inc=round && this->at(n-1)>=5;

  const size_type c=this->size()-n;

  for(size_type i=0;i!=c;++i)
   this->at(i)=this->at(i+n);

  for(size_type i=c;i!=this->size();++i)
   at(i)=0;

  m_size-=n;

  //формально, в этой точке у нас не должно быть переполнения
  //потому что мы только что освободили место под старшими разрядами числа
  if(make_inc && !this->inc())
   return false;//OVERFLOW
 }//else

 return true;
}//shift_on_negative_scale

//------------------------------------------------------------------------------
template<size_t N>
bool t_fixed_precision_digit<N>::zero()const
{
 for(size_type i=this->size();i!=0;)
 {
  --i;

  if(this->at(i)!=0)
   return false;
 }//for

 return true;
}//zero

//------------------------------------------------------------------------------
template<size_t N>
typename t_fixed_precision_digit<N>::t_accessor&
t_fixed_precision_digit<N>::at(size_type const index)
{
 assert(index<this->max_size());
 assert(this->size()<=this->max_size());

 //инициализация возникающего пропуска
 for(;m_size<=index;++m_size)
 {
  m_digits[m_size]=0;
 }

 return *reinterpret_cast<t_accessor*>(&m_digits[index]);
}//at

////////////////////////////////////////////////////////////////////////////////
//template functon add_fixed_precision_digit

template<class TLeftDigit,class TRightDigit,class TResultDigit>
bool add_fixed_precision_digit(const TLeftDigit&    left,
                               const TRightDigit&   right,
                               TResultDigit&        result)
{
 assert(result.max_size()>=left.size()+1);
 assert(result.max_size()>=right.size()+1);

 typedef unsigned char byte_type;

 typename TResultDigit::size_type i=0;

 byte_type carrying=0;
 byte_type summa;

 if(result.max_size()<left.size() || result.max_size()<right.size())
  return false;

 for(;i<left.size() && i<right.size();++i)
 {
  summa=byte_type(left[i]+right[i]+carrying);

  carrying=(summa>=10);

  assert(carrying==0 || carrying==1);

  result[i]=byte_type(carrying?(summa-10):summa);
 }//for

 if(i<left.size())
 {
  for(;i!=left.size();++i)
  {
   summa=byte_type(left[i]+carrying);

   carrying=(summa>=10);

   assert(carrying==0 || carrying==1);

   result[i]=byte_type(carrying?(summa-10):summa);
  }
 }
 else
 if(i<right.size())
 {
  for(;i!=right.size();++i)
  {
   summa=byte_type(right[i]+carrying);

   carrying=(summa>=10);

   assert(carrying==0 || carrying==1);

   result[i]=byte_type(carrying?(summa-10):summa);
  }
 }//else-if

 //учитываем оставшийся перенос
 if(carrying!=0)
 {
  if(i==result.max_size())
   return false;

  result[i]=1;
 }//if

 return true;
}//add_fixed_precision_digit

////////////////////////////////////////////////////////////////////////////////
//сравнение двух чисел

template<class TLeftDigit,class TRightDigit>
int cmp_fixed_precision_digit(const TLeftDigit& left,const TRightDigit& right)
{
 //ищем первые не нулевые числа
 typename TLeftDigit::size_type  n_l=left.size();
 typename TRightDigit::size_type n_r=right.size();

 while(n_l!=0 && left[n_l-1]==0)
  --n_l;

 while(n_r!=0 && right[n_r-1]==0)
  --n_r;

 if(n_l<n_r)
  return -1;

 if(n_l>n_r)
  return 1;

 assert(n_l==n_r);

 while(n_l!=0)
 {
  --n_l;

  if(left[n_l]==right[n_l])
   continue;

  if(left[n_l]<right[n_l])
   return -1;

  return 1;
 }//while

 return 0;
}//cmp_fixed_precision_digit

////////////////////////////////////////////////////////////////////////////////
//вычитание двух чисел result=abs(left-right)
// return
//   -1 left<right
//    0 left==right
//    1 left>right

template<class TLeftDigit,class TRightDigit,class TResultDigit>
int sub_fixed_precision_digit(const TLeftDigit&   left,
                              const TRightDigit&  right,
                              TResultDigit&       result)
{
 typedef unsigned char byte_type;

 const int cmp=cmp_fixed_precision_digit(left,right);

 if(cmp==0)
 {
  result.init();
 }
 else
 if(cmp>0) //left>right
 {
  byte_type carrying=0;
  byte_type r;

  for(typename TLeftDigit::size_type i=0;i!=left.size();--i)
  {
   if(i<right.size())
    r=right[i]+carrying;
   else
    r=carrying;

   if(bool(carrying=(left[i]<r)))
   {//заимствуем из старшей части
    result[i]=byte_type(left[i]+10-r);
   }
   else
   {
    result[i]=byte_type(left[i]-r);
   }
  }//for i

  //не должно оставаться переносов
  assert(carrying==0);
 }
 else //left<right
 {
  TLeftDigit   _right(left);
  TRightDigit  _left(right);

  byte_type carrying=0;
  byte_type r;

  for(typename TLeftDigit::size_type i=0;i!=_left.size();--i)
  {
   if(i<_right.size())
    r=_right[i]+carrying;
   else
    r=carrying;

   if(bool(carrying=(_left[i]<r)))
   {//заимствуем из старшей части
    result[i]=byte_type(_left[i]+10-r);
   }
   else
   {
    result[i]=byte_type(_left[i]-r);
   }
  }//for i

  //не должно оставаться переносов
  assert(carrying==0);
 }//else

 return cmp;
}//sub_fixed_precision_digit

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
