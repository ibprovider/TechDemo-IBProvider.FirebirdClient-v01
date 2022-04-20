////////////////////////////////////////////////////////////////////////////////
//DBVARIANT implementation. Services for work with DBTYPE_DECIMAL data type
//                                              Dmitry Kovalenko. 31.08.2003.

////////////////////////////////////////////////////////////////////////////////
//DBVARIANT - members for working with DBTYPE_DECIMAL

HRESULT DBVARIANT_CVT_UTILS::Int64ToDecimal(signed __int64 const value,
                                            tagDEC*        const pDecimal,
                                            int            const scale)
{
 assert(pDecimal);

 const HRESULT
  cvt_hr
   =self_type::UInt64ToDecimal
     (structure::remove_numeric_sign(value),
      pDecimal,
      scale);

 if(FAILED(cvt_hr))
  return cvt_hr;

 assert(cvt_hr==S_OK);

 assert(OLEDB_DECIMAL_SIGN(*pDecimal)==0);

 if(value<0)
 {
  OLEDB_DECIMAL_SIGN(*pDecimal)=BYTE(DECIMAL_NEG);
 }//if

 return S_OK;
}//Int64ToDecimal

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::UInt64ToDecimal(unsigned __int64 const value,
                                             tagDEC*          const _pDecimal,
                                             int              const scale)
{
 assert(_pDecimal);

 (*_pDecimal)=__null_decimal__;

 //------
 tagDEC Result(__null_decimal__);

 Result.Lo64=value;

 if(scale<0)
 {
  //decimal=value/(10^(-scale))

  const unsigned
   scale_u
    =structure::remove_numeric_sign(scale);

  if(scale_u<=oledb_decimal_max_scale)
  {
   OLEDB_DECIMAL_SCALE(Result)=(BYTE)scale_u;
  }
  else
  {
   assert_hint(oledb_decimal_max_scale<scale_u);

   //divide value on 10^(scale_u-oledb_decimal_max_scale)
   TNumericDigit digit;

   {
    const HRESULT
     unpack_hr
      =self_type::UnpackDecimalDigit
        (Result,
         &digit);

    if(FAILED(unpack_hr))
     return unpack_hr;

    assert(unpack_hr==S_OK);
   }//local

   _VERIFY(digit.shift_on_negative_scale(scale_u-oledb_decimal_max_scale,true));

   {
    const HRESULT
     pack_hr
      =self_type::PackDecimalDigit
        (digit,
         &Result);

    if(FAILED(pack_hr))
     return pack_hr;

    assert(pack_hr==S_OK);
   }//local

   OLEDB_DECIMAL_SCALE(Result)=oledb_decimal_max_scale;
  }//else
 }
 else
 if(scale>0) //emulate scale up
 {
  //decimal=value*(10^scale)

  TNumericDigit digit;

  {
   const HRESULT
    unpack_hr
     =self_type::UnpackDecimalDigit
       (Result,
        &digit);

   if(FAILED(unpack_hr))
    return unpack_hr;

   assert(unpack_hr==S_OK);
  }//local

  if(!digit.shift_on_positive_scale(scale))
  {
   return TDBTypeConverterCode::numeric_overflow;
  }//if

  {
   const HRESULT
    pack_hr
     =self_type::PackDecimalDigit
       (digit,
        &Result);

   if(FAILED(pack_hr))
    return pack_hr;

   assert(pack_hr==S_OK);
  }//local

  OLEDB_DECIMAL_SCALE(Result)=0;
 }//if

 (*_pDecimal)=Result;

 return S_OK;
}//UInt64ToDecimal

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::R8ToDecimal(double        value,
                                         tagDEC* const pDecimal)
{
 assert(pDecimal);
 assert(TNumericDigit::max_size()>=oledb_lib::oledb_decimal_precision);
 assert(TNumericDigit::max_size()>=oledb_lib::oledb_r8_precision);

 enum
 {
  c_max_source_precision=oledb_lib::oledb_r8_precision,

  c_max_result_scale=oledb_lib::oledb_decimal_max_scale
 };//enum

 //---------------------------
 (*pDecimal)=oledb_lib::__null_decimal__;

 //---------------------------
 if(std::isinf(value))
  return TDBTypeConverterCode::numeric_overflow;

 if(std::isnan(value))
  return S_OK;

 //---------------------------
 bool const positive=(value>=0);

 if(!positive)
  value=-value;

 TNumericDigit digit;

 //MSDN:
 //The floor function returns a floating-point value representing the
 //largest integer that is less than or equal to x. There is no error return.

 {
  //вычисляем целую часть value;
  double div_10=value;

  assert_s(c_max_source_precision==15);

  assert_s(c_max_source_precision<_DIM_(tag_data::sm_DblPow10));

  const double c_m15=tag_data::sm_DblPow10[c_max_source_precision];

  assert(c_m15!=0);

  while(div_10>=1 && digit.size()!=digit.max_size())
  {
   assert(digit.size()<digit.max_size());

   const double t=floor(div_10/10);

   //автоматически увеличивается
   if(div_10>=c_m15)
    digit[digit.size()]=0;
   else
    digit[digit.size()]=static_cast<BYTE>(div_10-10*t);

   assert(!digit.empty());

   div_10=t;
  }//while

  if(div_10>=1)
   return TDBTypeConverterCode::numeric_overflow; //не помещается
 }//local

 unsigned scale=0;

 {
  //вычисляем дробную часть

  for(;
      ;
      ++scale)
  {
   assert(digit.size()<=digit.max_size());

   // пока есть место,
   // пока точность и масштабирование не превышает максимально допустимые значения,
   // пока дробная часть не обнулилась.

   if(digit.size()==digit.max_size())
    break;

   if(c_max_source_precision<=digit.size())
    break;

   if(c_max_result_scale<=scale)
    break;

   //-------------------------
   double t=floor(value);

   if(value<=t)
    break;

   //-------------------------
   t*=10;

   value*=10;

   assert(t<=value);

   const int x=static_cast<int>(value-t);//целая часть

   assert(x>=0);
   assert(x<=9);

   if(!digit.empty()) //сдвиг (OVERFLOW must not occured)
   {
    _VERIFY(digit.shift_on_positive_scale(1));
   }

   if(x!=0)
   {
    digit[0]=static_cast<BYTE>(x);
   }
  }//for

  //производим округление необработанной дробной части
  if((floor(value+0.5)-floor(value))>=1)
  {
   if(!digit.inc())
    return TDBTypeConverterCode::numeric_overflow;
  }//if

  //убираем незначащие хвостовые 0 в дробной части
  unsigned empty_scale;

  for(empty_scale=0;
      empty_scale<digit.size() && empty_scale!=scale && digit[empty_scale]==0;
      ++empty_scale);

  _VERIFY(digit.shift_on_negative_scale(empty_scale,false));

  assert(empty_scale<=scale);

  scale-=empty_scale;
 }//формирование дробной части

 //упаковываем в tagDEC
 // здесь контролируется возможное переполнение
 {
  const HRESULT pack_hr=self_type::PackDecimalDigit(digit,pDecimal);

  if(FAILED(pack_hr))
   return pack_hr;

  assert(pack_hr==S_OK);
 }//local

 //----
 assert(digit.size()<=oledb_lib::oledb_decimal_precision);
 assert(scale<=oledb_lib::oledb_decimal_max_scale);

 //----
 OLEDB_DECIMAL_SIGN  (*pDecimal) =BYTE(positive?0:DECIMAL_NEG);
 OLEDB_DECIMAL_SCALE (*pDecimal) =BYTE(scale);

 return S_OK;
}//R8ToDecimal

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::R4ToDecimal(float         value,
                                         tagDEC* const pDecimal)
{
 assert(pDecimal);
 assert(TNumericDigit::max_size()>=oledb_lib::oledb_decimal_precision);
 assert(TNumericDigit::max_size()>=oledb_lib::oledb_r4_precision);

 enum
 {
  c_max_source_precision=oledb_lib::oledb_r4_precision,

  c_max_result_scale=oledb_lib::oledb_decimal_max_scale
 };//enum

 //---------------------------
 (*pDecimal)=oledb_lib::__null_decimal__;

 //---------------------------
 if(std::isinf(value))
  return TDBTypeConverterCode::numeric_overflow;

 if(std::isnan(value))
  return S_OK;

 //---------------------------
 bool const positive=(value>=0);

 if(!positive)
  value=-value;

 TNumericDigit digit;

 //MSDN:
 //The floor function returns a floating-point value representing the
 //largest integer that is less than or equal to x. There is no error return.

 {
  //вычисляем целую часть value;
  float div_10=value;

  assert_s(c_max_source_precision==7);

  assert_s(c_max_source_precision<_DIM_(tag_data::sm_FltPow10));

  const double c_m7=tag_data::sm_DblPow10[c_max_source_precision];

  assert(c_m7!=0);

  while(div_10>=1 && digit.size()!=digit.max_size())
  {
   assert(digit.size()<digit.max_size());

   const float t=floor(div_10/10);

   //автоматически увеличивается
   if(div_10>=c_m7)
    digit[digit.size()]=0;
   else
    digit[digit.size()]=static_cast<BYTE>(div_10-10*t);

   assert(!digit.empty());

   div_10=t;
  }//while

  if(div_10>=1)
   return TDBTypeConverterCode::numeric_overflow; //не помещается
 }//local

 unsigned scale=0;

 {
  //вычисляем дробную часть

  for(;
      ;
      ++scale)
  {
   assert(digit.size()<=digit.max_size());

   // пока есть место,
   // пока точность и масштабирование не превышает максимально допустимые значения,
   // пока дробная часть не обнулилась.

   if(digit.size()==digit.max_size())
    break;

   if(c_max_source_precision<=digit.size())
    break;

   if(c_max_result_scale<=scale)
    break;

   //-------------------------
   float t=floor(value);

   if(value<=t)
    break;

   //-------------------------
   t*=10;

   value*=10;

   assert(t<=value);

   const int x=static_cast<int>(value-t);//целая часть

   assert(x>=0);
   assert(x<=9);

   if(!digit.empty()) //сдвиг (OVERFLOW must not occured)
   {
    _VERIFY(digit.shift_on_positive_scale(1));
   }

   if(x!=0)
   {
    digit[0]=static_cast<BYTE>(x);
   }
  }//for

  //производим округление необработанной дробной части
  if((floor(value+0.5F)-floor(value))>=1)
  {
   if(!digit.inc())
    return TDBTypeConverterCode::numeric_overflow;
  }//if

  //убираем незначащие хвостовые 0 в дробной части
  unsigned empty_scale;

  for(empty_scale=0;
      empty_scale<digit.size() && empty_scale!=scale && digit[empty_scale]==0;
      ++empty_scale);

  _VERIFY(digit.shift_on_negative_scale(empty_scale,false));

  assert(empty_scale<=scale);

  scale-=empty_scale;
 }//формирование дробной части

 //упаковываем в tagDEC
 // здесь контролируется возможное переполнение
 {
  const HRESULT pack_hr=self_type::PackDecimalDigit(digit,pDecimal);

  if(FAILED(pack_hr))
   return pack_hr;

  assert(pack_hr==S_OK);
 }//local

 //----
 assert(digit.size()<=oledb_lib::oledb_decimal_precision);
 assert(scale<=oledb_lib::oledb_decimal_max_scale);

 //----
 OLEDB_DECIMAL_SIGN  (*pDecimal) =BYTE(positive?0:DECIMAL_NEG);
 OLEDB_DECIMAL_SCALE (*pDecimal) =BYTE(scale);

 return S_OK;
}//R4ToDecimal

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::StrToDecimal(const char* const str,
                                          size_type   const str_size,
                                          tagDEC*     const decimal)
{
 return self_type::TextToDecimal(str,str_size,decimal);
}//StrToDecimal

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::WStrToDecimal(const wchar_t* const str,
                                           size_type      const str_size,
                                           tagDEC*        const decimal)
{
 return self_type::TextToDecimal(str,str_size,decimal);
}//WStrToDecimal

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::BoolToDecimal(VARIANT_BOOL const value,
                                           tagDEC*      const decimal)
{
 assert(decimal);

 DECIMAL_SETZERO(*decimal);

 decimal->Lo64=value?1:0;

 return S_OK;
}//BoolToDecimal

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::ScaleDecimal(const tagDEC& decimal,
                                          BYTE    const scale,
                                          tagDEC* const result_decimal)
{
 assert(result_decimal);

 if(decimal.scale==scale)
 {
  (*result_decimal)=decimal;

  return S_OK;
 }

 //распаковываем число
 TNumericDigit digit;

 {
  const HRESULT unpack_hr=self_type::UnpackDecimalDigit(decimal,&digit);

  if(FAILED(unpack_hr))
   return unpack_hr;

  assert(unpack_hr==S_OK);
 }//local

 if(digit.empty())
 {
  (*result_decimal)=decimal;

  result_decimal->scale=scale;

  return S_OK;
 }

 //масштабируем число -----------------------------------------------
 if(decimal.scale<scale)
 {
  //масштаб исходного числа меньше требуемого
  //значит число нужно умножать на 10^(scale-dbnum.scale)
  if(!digit.shift_on_positive_scale(scale-decimal.scale))
   return TDBTypeConverterCode::numeric_overflow;
 }
 else
 {
  //масштаб больше требуемого
  //значит число нужно принудительно разделить на 10^(dbnum.scale-scale)
  if(!digit.shift_on_negative_scale(decimal.scale-scale,/*round*/true))
   return TDBTypeConverterCode::numeric_overflow;
 }//else dbnum.scale>scale

 //запаковываем число обратно
 const BYTE sign=decimal.sign;

 tagDEC new_decimal;

 {
  const HRESULT pack_hr=self_type::PackDecimalDigit(digit,&new_decimal);

  if(FAILED(pack_hr))
   return pack_hr;

  assert(pack_hr==S_OK);
 }//local

 new_decimal.scale =scale;
 new_decimal.sign  =sign;

 (*result_decimal)=new_decimal;

 return S_OK;
}//ScaleDecimal

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::DecimalToInt(const tagDEC&         decimal,
                                          signed __int64* const pValue)
{
 assert(pValue!=NULL);

 (*pValue)=0;

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::DecimalToNumeric(decimal,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToInt(dbnum,pValue);
}//DecimalToInt - signed

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::DecimalToInt(const tagDEC&           decimal,
                                          unsigned __int64* const pValue)
{
 assert(pValue!=NULL);

 (*pValue)=0;

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::DecimalToNumeric(decimal,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToInt(dbnum,pValue);
}//DecimalToInt - unsigned

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::DecimalToR4(const tagDEC& decimal,
                                         float* const  pValue)
{
 assert(pValue!=NULL);

 (*pValue)=0;

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::DecimalToNumeric(decimal,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToR4(dbnum,pValue);
}//DecimalToR4

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::DecimalToR8(const tagDEC& decimal,
                                         double* const pValue)
{
 assert(pValue!=NULL);

 (*pValue)=0;

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::DecimalToNumeric(decimal,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToR8(dbnum,pValue);
}//DecimalToR8

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::DecimalToCY(const tagDEC&         decimal,
                                         signed __int64* const pValue)
{
 assert(pValue!=NULL);

 (*pValue)=0;

 tagDEC scaled_decimal;

 //масштабируем число
 const HRESULT hr=self_type::ScaleDecimal(decimal,
                                          oledb_cy_fraction_part_scale,
                                          &scaled_decimal);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 //проверяем результат масштабирования
 assert_msg(scaled_decimal.scale==oledb_cy_fraction_part_scale,"scale="<<scaled_decimal.scale);

 //отменяем масштаб
 scaled_decimal.scale=0;

 //конвертируем в int64
 return self_type::DecimalToInt(scaled_decimal,pValue);
}//NumericToCY

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::DecimalToStr(const tagDEC&      decimal,
                                          std::string* const pStr)
{
 assert(pStr!=NULL);

 pStr->erase();

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::DecimalToNumeric(decimal,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToString(dbnum,pStr);
}//DecimalToStr

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::DecimalToWStr(const tagDEC&       decimal,
                                           std::wstring* const pWStr)
{
 assert(pWStr!=NULL);

 pWStr->erase();

 DB_NUMERIC dbnum;

 const HRESULT hr=self_type::DecimalToNumeric(decimal,&dbnum);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::NumericToString(dbnum,pWStr);
}//DecimalToWStr

//------------------------------------------------------------------------------
std::string DBVARIANT_CVT_UTILS::DecimalToStr(const tagDEC& decimal,
                                              bool* const   error)
{
 DB_NUMERIC   dbnum;
 std::string  str;

 if(DecimalToNumeric(decimal,&dbnum)!=S_OK || NumericToString(dbnum,&str)!=S_OK)
 {
  if(error!=NULL)
   (*error)=true;
 }
 else
 {
  if(error!=NULL)
   (*error)=false;
 }//else

 return str;
}//DecimalToStr

//------------------------------------------------------------------------------
std::wstring DBVARIANT_CVT_UTILS::DecimalToWStr(const tagDEC& decimal,
                                                bool* const   error)
{
 DB_NUMERIC    dbnum;
 std::wstring  str;

 if(DecimalToNumeric(decimal,&dbnum)!=S_OK || NumericToString(dbnum,&str)!=S_OK)
 {
  if(error!=NULL)
   (*error)=true;
 }
 else
 {
  if(error!=NULL)
   (*error)=false;
 }//else

 return str;
}//DecimalToWStr

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::DecimalToBool(const tagDEC& decimal,
                                           bool* const   pValue)
{
 assert(pValue!=NULL);

 (*pValue)=decimal.Lo64!=0 || decimal.Hi32!=0;

 return S_OK;
}//DecimalToBool

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::DecimalToVariant(const tagDEC&  decimal,
                                              VARIANT* const pVar)
{
 assert(pVar!=NULL);

 //----------------
 const HRESULT clear_hr=ole_lib::Variant_Clear(pVar);

 if(FAILED(clear_hr))
  return E_FAIL;

 assert(clear_hr==S_OK);

 assert(pVar->vt==VT_EMPTY);

 //----------------
 //Order is important here! Setting V_DECIMAL wipes out the entire VARIANT
 V_DECIMAL(pVar) =decimal;
 V_VT(pVar)      =VT_DECIMAL;

 return S_OK;
}//DecimalToVariant

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::UnpackDecimalDigit(const tagDEC&        decimal,
                                                TNumericDigit* const pDigit)
{
 assert(pDigit);

 pDigit->init();

 assert_s(CHAR_BIT==8);
 assert_s(sizeof(decimal.Lo32 )==4);
 assert_s(sizeof(decimal.Mid32)==4);
 assert_s(sizeof(decimal.Hi32 )==4);

 _VERIFY(self_type::Helper__UnpackDecimalDigit__ProcessPart(pDigit,decimal.Lo32 ,0));
 _VERIFY(self_type::Helper__UnpackDecimalDigit__ProcessPart(pDigit,decimal.Mid32,32));
 _VERIFY(self_type::Helper__UnpackDecimalDigit__ProcessPart(pDigit,decimal.Hi32 ,64));

 return S_OK;
}//UnpackDecimalDigit

//------------------------------------------------------------------------------
bool DBVARIANT_CVT_UTILS::Helper__UnpackDecimalDigit__ProcessPart
                                           (TNumericDigit* const pResult,
                                            DWORD          const dwPart,
                                            unsigned       const pow2)
{
 assert(pResult);

 assert_s(sizeof(dwPart)==4);
 assert_s(CHAR_BIT==8);

 assert_s(32<=_DIM_(tag_data::sm_power_2_map));

 assert(pow2<_DIM_(tag_data::sm_power_2_map));
 assert(pow2<=(_DIM_(tag_data::sm_power_2_map)-32));

 unsigned const epow2=pow2+32;

 DWORD mask=1;

 for(unsigned i=pow2;i!=epow2;++i,mask=mask<<1)
 {
  if((dwPart&mask)==0)
   continue;

  assert(i<_DIM_(tag_data::sm_power_2_map));

  if(!structure::add_fixed_precision_digit(*pResult,tag_data::sm_power_2_map[i],*pResult))
   return false;
 }//for i

 return true;
}//Helper__UnpackDecimalDigit__ProcessPart

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::PackDecimalDigit(const TNumericDigit& digit,
                                              tagDEC*        const pDecimal)
{
 assert(pDecimal);

 using namespace structure;

 (*pDecimal)=__null_decimal__;

 TNumericDigit _digit(digit);

 _digit.pack();

 if(!_digit.size()) //нулевое число
  return S_OK;

 //---------------------------
 BYTE decimal_bytes[12]={0};

 //используются для установки битов
 size_t i_byte;
 BYTE   mask;

 //используются в вычитании
 BYTE  carrying;
 BYTE  r;

 //результат сравнения
 int cmp=-1;

 for(size_t i_power_2=_DIM_(tag_data::sm_power_2_map);i_power_2!=0;)
 {
  --i_power_2;

  cmp=cmp_fixed_precision_digit(_digit,tag_data::sm_power_2_map[i_power_2]);

  if(cmp<0)
   continue;

  i_byte=i_power_2/CHAR_BIT; //делим на 8

  mask=BYTE(1<<(i_power_2-i_byte*CHAR_BIT));

  if(i_byte>=_DIM_(decimal_bytes))
   return TDBTypeConverterCode::numeric_overflow;

  decimal_bytes[i_byte]|=mask;

  if(cmp==0)
   break;

  //уменьшаем digit
  carrying=0;

  for(TNumericDigit::size_type i_digit=0;i_digit!=_digit.size();++i_digit)
  {
   if(i_digit<tag_data::sm_power_2_map[i_power_2].size())
    r=BYTE(tag_data::sm_power_2_map[i_power_2][i_digit]+carrying);
   else
    r=carrying;

   carrying=(_digit[i_digit]<r);

   assert(carrying==0 || carrying==1);

   if(carrying)
   {//заимствуем из старшей части
    _digit[i_digit]=BYTE(_digit[i_digit]+10-r);
   }
   else
   {
    _digit[i_digit]=BYTE(_digit[i_digit]-r);
   }
  }//for i_digit

  //не должно оставаться переносов
  assert(carrying==0);

  //устраняем начальные пробелы
  _digit.pack();
 }//for i_power_2

 //мы не можем завершить цикл результатом сравнения <=
 //поскольку производиться последовательное уменьшение, а на ноль была проверка
 //в самом начале
 // assert сработает, только при наличии ошибок в g_power_2_map
 assert(cmp>=0);

 if(cmp>0) //не смогли уменьшить число, до нуля
  return TDBTypeConverterCode::numeric_overflow;

 assert_s(sizeof(pDecimal->Lo32)  ==4);
 assert_s(sizeof(pDecimal->Mid32) ==4);
 assert_s(sizeof(pDecimal->Hi32)  ==4);

 assert_s(_DIM_(decimal_bytes)==12);

 pDecimal->Lo32 =  (ULONG(decimal_bytes[ 0]))
                  |(ULONG(decimal_bytes[ 1])<<8)
                  |(ULONG(decimal_bytes[ 2])<<16)
                  |(ULONG(decimal_bytes[ 3])<<24);

 pDecimal->Mid32=  (ULONG(decimal_bytes[ 4]))
                  |(ULONG(decimal_bytes[ 5])<<8)
                  |(ULONG(decimal_bytes[ 6])<<16)
                  |(ULONG(decimal_bytes[ 7])<<24);

 pDecimal->Hi32 =  (ULONG(decimal_bytes[ 8]))
                  |(ULONG(decimal_bytes[ 9])<<8)
                  |(ULONG(decimal_bytes[10])<<16)
                  |(ULONG(decimal_bytes[11])<<24);

 return S_OK;
}//PackDecimalDigit

////////////////////////////////////////////////////////////////////////////////

template<class charT>
HRESULT DBVARIANT_CVT_UTILS::TextToDecimal(const charT*  str,
                                           size_type     str_size,
                                           tagDEC* const pDecimal)
{
 assert(pDecimal);

 //-----------------------------------------
 typedef charT                                           char_type;
 typedef structure::t_char_traits2<char_type>            char_traits2;

 //-----------------------------------------
 enum
 {
  c_max_precision  =oledb_decimal_precision,
  c_max_scale      =oledb_decimal_max_scale,
 };

 (*pDecimal)=__null_decimal__;

 if(str==NULL)
  return DB_E_CANTCONVERTVALUE;

 if(str_size==self_type::npos)
  str_size=std::char_traits<char_type>::length(str);

 const char_type* const end_str=str+str_size;

 CHECK_READ_PTR(str,str_size*sizeof(*str));

 //пропускаем начальные пробелы
 str=structure::miss_space2(str,end_str);

 if(str==end_str)
  return DB_E_CANTCONVERTVALUE;

 //0 - default (+)
 //1 - define +
 //2 - define -
 BYTE sign=0;

 if((*str)==char_traits2::ch_plus())
  sign=1;
 else
 if((*str)==char_traits2::ch_minus())
  sign=2;

 if(sign)
  ++str;//пропускаем знак

 if(str==end_str)
  return DB_E_CANTCONVERTVALUE;

 //HEX -------------------------------------------------------------------
 BYTE decimal_bytes[12]={0};

 switch(const HRESULT hr=self_type::TextWithHexNumberToByteArray3
                                            (str,
                                             end_str,
                                             decimal_bytes,
                                             _DIM_(decimal_bytes)))
 {
  case DB_E_CANTCONVERTVALUE : //str not has hex number
   {
    break;
   }

  case S_OK: //str has hex number
   {
    assert_s(sizeof(pDecimal->Lo32)  ==4);
    assert_s(sizeof(pDecimal->Mid32) ==4);
    assert_s(sizeof(pDecimal->Hi32)  ==4);

    assert_s(_DIM_(decimal_bytes)==12);

    pDecimal->Lo32 =  (ULONG(decimal_bytes[ 0]))
                     |(ULONG(decimal_bytes[ 1])<<8)
                     |(ULONG(decimal_bytes[ 2])<<16)
                     |(ULONG(decimal_bytes[ 3])<<24);

    pDecimal->Mid32=  (ULONG(decimal_bytes[ 4]))
                     |(ULONG(decimal_bytes[ 5])<<8)
                     |(ULONG(decimal_bytes[ 6])<<16)
                     |(ULONG(decimal_bytes[ 7])<<24);

    pDecimal->Hi32 =  (ULONG(decimal_bytes[ 8]))
                     |(ULONG(decimal_bytes[ 9])<<8)
                     |(ULONG(decimal_bytes[10])<<16)
                     |(ULONG(decimal_bytes[11])<<24);

    OLEDB_DECIMAL_SIGN(*pDecimal)=BYTE((sign==2)?DECIMAL_NEG:0);

    return hr;
   }//case S_OK

  default: //fail convert str to number
   {
    assert(FAILED(hr));

    return hr;
   }
 }//switch try convert to hex

 //-----------------------------------------------------------------------
 TNumericDigit digit;
 size_type     scale;

 {
  const HRESULT cvt_hr=self_type::TextToUnsignedNumericDigit2(str,
                                                              end_str,
                                                              digit,
                                                              scale,
                                                              c_max_precision,
                                                              c_max_scale);
  if(FAILED(cvt_hr))
   return cvt_hr;

  assert(cvt_hr==S_OK);
 }//local

 {
  const HRESULT pack_hr=self_type::PackDecimalDigit(digit,pDecimal);

  if(FAILED(pack_hr))
   return pack_hr;

  assert(pack_hr==S_OK);
 }//local

 assert(digit.size()<=c_max_precision);
 assert(scale<=c_max_scale);

 OLEDB_DECIMAL_SIGN  (*pDecimal) =BYTE((sign==2)?DECIMAL_NEG:0); //не отрицательное число
 OLEDB_DECIMAL_SCALE (*pDecimal) =BYTE(scale);

 return S_OK;
}//TextToDecimal

////////////////////////////////////////////////////////////////////////////////
