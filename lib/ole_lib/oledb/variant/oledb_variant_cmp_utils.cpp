////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/oledb_variant_cmp_utils.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt_utils.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT_CMP_UTILS

EnumDBVariantCmpCode
 DBVARIANT_CMP_UTILS::NumericCompare(const DB_NUMERIC& dbnum1,
                                     const DB_NUMERIC& dbnum2)
{
 const EnumDBVariantCmpCode c_rcode__err
  =DBVariantCmpCode__err__generic;

 const EnumDBVariantCmpCode c_rcode__eq
  =DBVariantCmpCode__ok__equal;

 const EnumDBVariantCmpCode c_rcode__less
  =DBVariantCmpCode__ok__less;

 const EnumDBVariantCmpCode c_rcode__great
  =DBVariantCmpCode__ok__great;

 //-----------------------------------------------------------------------
 //unpack numeric digit
 DBVARIANT_CVT_UTILS::TNumericDigit digit1;
 DBVARIANT_CVT_UTILS::TNumericDigit digit2;

 {
  const HRESULT unpack_hr1=DBVARIANT_CVT_UTILS::UnpackNumericDigit(dbnum1,&digit1);

  if(FAILED(unpack_hr1))
   return c_rcode__err;

  assert(unpack_hr1==S_OK);
 }//local

 {
  const HRESULT unpack_hr2=DBVARIANT_CVT_UTILS::UnpackNumericDigit(dbnum2,&digit2);

  if(FAILED(unpack_hr2))
   return c_rcode__err;

  assert(unpack_hr2==S_OK);
 }//local

 if(digit1.zero() && digit2.zero())
  return c_rcode__eq;

 //DB_NUMERIC::sign Ч The sign: 1 for positive numbers, 0 for negative numbers
 const bool sign1=(digit1.zero() || dbnum1.sign);
 const bool sign2=(digit2.zero() || dbnum2.sign);

 //разные знаки
 if(sign1^sign2)
  return sign1?c_rcode__great:c_rcode__less;

 //----------------------------
 typedef DBVARIANT_CVT_UTILS::TNumericDigit::size_type digit_size_type;

 //----------------------------
 const digit_size_type original_dbnum1_scale=dbnum1.scale;
 const digit_size_type original_dbnum2_scale=dbnum2.scale;

 //adjust scale 1 -------------
 digit_size_type as1;

 for(as1=0;as1<digit1.size() && as1<original_dbnum1_scale && digit1[as1]==0;++as1);

 const digit_size_type scale1_=original_dbnum1_scale-as1;

 //устран€ем фиктивные младшие нули, убиваемые при масштабировании
 _VERIFY(digit1.shift_on_negative_scale(as1,false));

 //adjust scale 2 -------------
 digit_size_type as2;

 for(as2=0;as2<digit2.size() && as2<original_dbnum2_scale && digit2[as2]==0;++as2);

 const digit_size_type scale2_=original_dbnum2_scale-as2;

 //устран€ем фиктивные младшие нули, убиваемые при масштабировании
 _VERIFY(digit2.shift_on_negative_scale(as2,false));

 //----------------------------
 const bool size1_neg=(digit1.size()<=scale1_);
 const bool size2_neg=(digit2.size()<=scale2_);

 //----------------------------
 if(size1_neg^size2_neg) // size1_neg!=size2_neg
 {
  //size1_neg            sign1        result
  // false (||>=1)       false (-)     -1  digit1<digit2
  // false (||>=1)       true  (+)     +1  digit1>digit2
  // true  (||<1)        false (-)     +1  digit1>digit2
  // true  (||<1)        true  (+)     -1  digit1<digit2

  return (size1_neg^sign1)?c_rcode__great:c_rcode__less;
 }//if

 //----------------------------
 digit_size_type size1;
 digit_size_type size2;

 if(size1_neg)
 {
  //|digit1|<1 and |digit2|<1

  //sizeX будут содержать количество знаков перед точкой (длину целой части)

  size1=(scale1_-digit1.size());
  size2=(scale2_-digit2.size());
 }
 else
 {
  //|digit1|>=1 and |digit2|>=1

  //sizeX будут содержать рассто€ние от точки до первой ненулевой цифры после точки
  // - формально, это количество нулей после точки

  size1=(digit1.size()-scale1_);
  size2=(digit2.size()-scale2_);
 }//else

 if(size1<size2)
 {
  //size1_neg          sign1         result       samples
  // false (||>=1)     false (-)     +1            -1<-12  -1.00001<-12
  // false (||>=1)     true  (+)     -1             1<12    1.00001<12
  // true  (||<1)      false (-)     -1            -0.1<-0.0123
  // true  (||<1)      true  (+)     +1             0.1>0.0123

  return (size1_neg^sign1)?c_rcode__less:c_rcode__great;
 }//if

 if(size2<size1)
 {
  return (size1_neg^sign1)?c_rcode__great:c_rcode__less;
 }//if

 //числа с одинаковым знаком и масштабом -------
 assert(size1==size2);

 //добавл€ем младшие нули к меньшему по длине числу
 if(digit1.size()<digit2.size())
 {
  _VERIFY(digit1.shift_on_positive_scale(digit2.size()-digit1.size()));

  assert(digit1.empty() || digit1.size()==digit2.size());
 }
 else
 if(digit2.size()<digit1.size())
 {
  _VERIFY(digit2.shift_on_positive_scale(digit1.size()-digit2.size()));

  assert(digit2.empty() || digit2.size()==digit1.size());
 }

 // [2021-03-01]
 //assert(digit1.size()==digit2.size());

 int cmp_result=structure::cmp_fixed_precision_digit(digit1,digit2);

 if(!sign1)
  cmp_result=-cmp_result;

 if(cmp_result<0)
  return c_rcode__less;

 if(cmp_result>0)
  return c_rcode__great;

 return c_rcode__eq;
}//NumericCompare

//------------------------------------------------------------------------
EnumDBVariantCmpCode
 DBVARIANT_CMP_UTILS::DecimalCompare(const tagDEC& dec1,
                                     const tagDEC& dec2)
{
 DB_NUMERIC dbnum1;

 {
  const HRESULT hr1=DBVARIANT_CVT_UTILS::DecimalToNumeric(dec1,&dbnum1);

  if(FAILED(hr1))
   return DBVariantCmpCode__err__generic;

  assert(hr1==S_OK);
 }//local

 //-----------------------------------------
 DB_NUMERIC dbnum2;

 {
  const HRESULT hr2=DBVARIANT_CVT_UTILS::DecimalToNumeric(dec2,&dbnum2);

  if(FAILED(hr2))
   return DBVariantCmpCode__err__generic;

  assert(hr2==S_OK);
 }//local

 //-----------------------------------------
 return self_type::NumericCompare(dbnum1,dbnum2);
}//DecimalCompare

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
