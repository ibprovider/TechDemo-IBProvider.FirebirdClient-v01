////////////////////////////////////////////////////////////////////////////////
//Набор утилит и классов для работы с большими числами
//                                                  Kovalenko Dmitry. 24.23.2001
#ifndef _digit_lib_H_
#define _digit_lib_H_

#include <structure/t_common.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containing

//представление числа
//template<unsigned int N>
//class t_fixed_precision_digit;

//сложение двух чисел
//return false - for any errors (OVERFLOW)
template<class TLeftDigit,class TRightDigit,class TResultDigit>
bool add_fixed_precision_digit(const TLeftDigit&    left,
                               const TRightDigit&   right,
                               TResultDigit&        result);

//сравнение двух чисел
template<class TLeftDigit,class TRightDigit>
int cmp_fixed_precision_digit(const TLeftDigit&  left,
                              const TRightDigit& right);

//вычитание двух чисел result=abs(left-right)
// return
//   -1 left<right
//    0 left==right
//    1 left>right
template<class TLeftDigit,class TRightDigit,class TResultDigit>
int sub_fixed_precision_digit(const TLeftDigit&   left,
                              const TRightDigit&  right,
                              TResultDigit&       result);

////////////////////////////////////////////////////////////////////////////////
//template class t_fixed_precision_digit - представление числа

template<size_t N>
class t_fixed_precision_digit
{
 public: //typedefs
  typedef size_t                         size_type;
  typedef t_fixed_precision_digit<N>     digit_type;

  typedef unsigned char                  byte_type;

  typedef byte_type                      element_type;

 #pragma pack(push,1)
  class t_accessor
  {
   private:
    byte_type value;

   public:
    operator byte_type () const {return value;}

    t_accessor& operator = (byte_type v)
    {
     assert(v<=9);
     value=v;
     return *this;
    }
  };//class t_accessor
 #pragma pack(pop)

 private:
  static const size_type sm_N;

  size_type  m_size;
  byte_type  m_digits[N];

 public:
  t_fixed_precision_digit();

  //modificators ---------------------------------------------------------
  void init();

  //remove forward 0s
  void pack();

  //return false for OVERFLOW
  bool inc();

  // *10^N
  //return false for OVERFLOW
  bool shift_on_positive_scale(size_type n);

  // /10^N - use round
  //return false for OVERFLOW
  bool shift_on_negative_scale(size_type n,bool round);

  //selectors ------------------------------------------------------------
  size_type size() const
  {
   return m_size;
  }

  bool empty() const
  {
   return m_size==0;
  }

  bool zero()const;

  static size_type max_size()
  {
   return sm_N;
  }

  static size_type capacity()
  {
   return sm_N;
  }

  //accessors ------------------------------------------------------------
  //can't expanded as inline
  t_accessor& at(size_type index);

  const t_accessor& at(size_type index)const
  {
   assert(index<this->max_size());

   return *reinterpret_cast<const t_accessor*>(&m_digits[index]);
  }

  t_accessor& operator [] (size_type index)
  {
   return this->at(index);
  }

  const t_accessor& operator [] (size_type index)const
  {
   return this->at(index);
  }
};//class t_fixed_precision_digit

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_digit_lib.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
