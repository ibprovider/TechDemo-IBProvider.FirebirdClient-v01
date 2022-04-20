////////////////////////////////////////////////////////////////////////////////
//DBVARIANT_CVT_UTILS implementation. NUMERIC services
//                                                 Dmitry Kovalenko. 05.02.2010

////////////////////////////////////////////////////////////////////////////////
//DBVARIANT - members for working with DBTYPE_NUMERIC

HRESULT DBVARIANT_CVT_UTILS::Int64ToNumeric(signed __int64 const value,
                                            DB_NUMERIC*    const pDBNum,
                                            BYTE           const value_precision,
                                            int            const scale)
{
 assert(pDBNum);

 const HRESULT cvt_hr
  =self_type::UInt64ToNumeric
    (structure::remove_numeric_sign(value),
     pDBNum,
     value_precision,
     scale);

 if(FAILED(cvt_hr))
  return cvt_hr;

 assert(cvt_hr==S_OK);

 assert(pDBNum->sign==1);

 if(value<0)
 {
  pDBNum->sign=0;
 }//if

 return S_OK;
}//Int64ToNumeric - generic

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::UInt64ToNumeric(unsigned __int64 const value,
                                             DB_NUMERIC*      const pDBNum,
                                             BYTE             const value_precision,
                                             int                    scale)
{
 assert(pDBNum);

 (*pDBNum)=__null_dbnumeric__;

 //--------
 DB_NUMERIC dbnum(__null_dbnumeric__);

 //TODO: Incorrect assign code (BigEndial/LowEndian)

 //value
 (*reinterpret_cast<unsigned __int64*>(dbnum.val))=value;

 //precision
 if(scale==0)
 {
  dbnum.precision=value_precision;
 }
 else
 if(scale<0)
 {
  scale=-scale;

  if(scale<=oledb_numeric_max_scale)
  {
   dbnum.scale=(BYTE)scale;
  }
  else
  {
   assert_hint(oledb_numeric_max_scale<scale);

   //divide value on 10^(scale-oledb_numeric_max_scale)
   TNumericDigit digit;

   {
    const HRESULT unpack_hr=self_type::UnpackNumericDigit(dbnum,&digit);

    if(FAILED(unpack_hr))
     return unpack_hr;

    assert(unpack_hr==S_OK);
   }//local

   _VERIFY(digit.shift_on_negative_scale(scale-oledb_numeric_max_scale,true));

   {
    const HRESULT pack_hr=self_type::PackNumericDigit(digit,&dbnum);

    if(FAILED(pack_hr))
     return pack_hr;

    assert(pack_hr==S_OK);
   }//local

   dbnum.scale=oledb_numeric_max_scale;
  }//else

  dbnum.precision=max(dbnum.scale,value_precision);
 }
 else //scale>0 - emulation of scale up
 {
  assert_hint(scale>0);

  TNumericDigit digit;

  {
   const HRESULT unpack_hr=self_type::UnpackNumericDigit(dbnum,&digit);

   if(FAILED(unpack_hr))
    return unpack_hr;

   assert(unpack_hr==S_OK);
  }//local

  if(!digit.shift_on_positive_scale(scale))
   return TDBTypeConverterCode::numeric_overflow;

  {
   const HRESULT pack_hr=self_type::PackNumericDigit(digit,&dbnum);

   if(FAILED(pack_hr))
    return pack_hr;

   assert(pack_hr==S_OK);
  }//local

  dbnum.precision=(BYTE)max(digit.size(),TNumericDigit::size_type(value_precision));
 }//else

 //sign
 dbnum.sign=1;

 //----
 (*pDBNum)=dbnum;

 return S_OK;
}//UInt64ToNumeric - generic

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::R8ToNumeric(double            value,
                                         DB_NUMERIC* const pDBNum)
{
 assert(pDBNum);
 assert(TNumericDigit::max_size()>=oledb_lib::oledb_numeric_precision);
 assert(TNumericDigit::max_size()>=oledb_lib::oledb_r8_precision);

 enum
 {
  c_max_source_precision=oledb_lib::oledb_r8_precision,

  c_max_result_scale=oledb_lib::oledb_numeric_max_scale
 };//enum

 //---------------------------
 (*pDBNum)=oledb_lib::__null_dbnumeric__;

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

 //упаковываем в DB_NUMERIC
 DB_NUMERIC dbnum(oledb_lib::__null_dbnumeric__);

 // здесь контролируется возможное переполнение
 {
  const HRESULT pack_hr=self_type::PackNumericDigit(digit,&dbnum);

  if(FAILED(pack_hr))
   return pack_hr;

  assert(pack_hr==S_OK);
 }//local

 //----
 assert(digit.size()<=oledb_lib::oledb_numeric_precision);
 assert(scale<=oledb_lib::oledb_numeric_max_scale);

 assert(structure::can_numeric_cast(&dbnum.precision,digit.size()));
 assert(structure::can_numeric_cast(&dbnum.scale,scale));

 //----
 dbnum.sign=(positive?1:0);

 structure::static_numeric_cast(&dbnum.precision,digit.size());

 structure::static_numeric_cast(&dbnum.scale,scale);

 //----
 (*pDBNum)=dbnum;

 return S_OK;
}//R8ToNumeric

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::R4ToNumeric(float             value,
                                         DB_NUMERIC* const pDBNum)
{
 assert(pDBNum);
 assert(TNumericDigit::max_size()>=oledb_lib::oledb_numeric_precision);
 assert(TNumericDigit::max_size()>=oledb_lib::oledb_r4_precision);

 enum
 {
  c_max_source_precision=oledb_lib::oledb_r4_precision,

  c_max_result_scale=oledb_lib::oledb_numeric_max_scale
 };//enum

 //---------------------------
 (*pDBNum)=oledb_lib::__null_dbnumeric__;

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

  const double c_m7=tag_data::sm_FltPow10[c_max_source_precision];

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

 //упаковываем в DB_NUMERIC
 DB_NUMERIC dbnum(oledb_lib::__null_dbnumeric__);

 // здесь контролируется возможное переполнение
 {
  const HRESULT pack_hr=self_type::PackNumericDigit(digit,&dbnum);

  if(FAILED(pack_hr))
   return pack_hr;

  assert(pack_hr==S_OK);
 }//local

 //----
 assert(digit.size()<=oledb_lib::oledb_numeric_precision);
 assert(scale<=oledb_lib::oledb_numeric_max_scale);

 assert(structure::can_numeric_cast(&dbnum.precision,digit.size()));
 assert(structure::can_numeric_cast(&dbnum.scale,scale));

 //----
 dbnum.sign=(positive?1:0);

 structure::static_numeric_cast(&dbnum.precision,digit.size());

 structure::static_numeric_cast(&dbnum.scale,scale);

 //----
 (*pDBNum)=dbnum;

 return S_OK;
}//R4ToNumeric

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::DecimalToNumeric(const tagDEC&     decimal,
                                              DB_NUMERIC* const pDBNum)
{
 assert(pDBNum);

 (*pDBNum)=__null_dbnumeric__;

 pDBNum->precision=oledb_decimal_precision;
 pDBNum->scale    =OLEDB_DECIMAL_SCALE(decimal);
 pDBNum->sign     =BYTE((OLEDB_DECIMAL_SIGN(decimal)==0)?1:0);

 assert_s(CHAR_BIT==8);
 assert_s(sizeof(decimal.Lo32 )==4);
 assert_s(sizeof(decimal.Mid32)==4);
 assert_s(sizeof(decimal.Hi32 )==4);

 assert_s(_DIM_(pDBNum->val)>=12);

 assert_s(sizeof(pDBNum->val[0])==1);

 pDBNum->val[ 0]=static_cast<BYTE>((decimal.Lo32     )&0xFF);
 pDBNum->val[ 1]=static_cast<BYTE>((decimal.Lo32>>8  )&0xFF);
 pDBNum->val[ 2]=static_cast<BYTE>((decimal.Lo32>>16 )&0xFF);
 pDBNum->val[ 3]=static_cast<BYTE>((decimal.Lo32>>24 )&0xFF);

 pDBNum->val[ 4]=static_cast<BYTE>((decimal.Mid32    )&0xFF);
 pDBNum->val[ 5]=static_cast<BYTE>((decimal.Mid32>>8 )&0xFF);
 pDBNum->val[ 6]=static_cast<BYTE>((decimal.Mid32>>16)&0xFF);
 pDBNum->val[ 7]=static_cast<BYTE>((decimal.Mid32>>24)&0xFF);

 pDBNum->val[ 8]=static_cast<BYTE>((decimal.Hi32     )&0xFF);
 pDBNum->val[ 9]=static_cast<BYTE>((decimal.Hi32>>8  )&0xFF);
 pDBNum->val[10]=static_cast<BYTE>((decimal.Hi32>>16 )&0xFF);
 pDBNum->val[11]=static_cast<BYTE>((decimal.Hi32>>24 )&0xFF);

 return S_OK;
}//DecimalToNumeric

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::StrToNumeric(const char* const str,
                                          size_type   const str_size,
                                          DB_NUMERIC* const pDBNum)
{
 return self_type::TextToNumeric(str,str_size,pDBNum);
}//StrToNumeric

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::WStrToNumeric(const wchar_t*       str,
                                           size_type            str_size,
                                           DB_NUMERIC*    const pDBNum)
{
 return self_type::TextToNumeric(str,str_size,pDBNum);
}//WStrToNumeric

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::BoolToNumeric(VARIANT_BOOL const value,
                                           DB_NUMERIC*  const pDBNum)
{
 assert(pDBNum);

 (*pDBNum)=__null_dbnumeric__;

 pDBNum->sign=1;
 pDBNum->val[0]=BYTE(value?1:0);

 pDBNum->precision=oledb_i2_precision;

 return S_OK;
}//BoolToNumeric

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::UnpackNumericDigit(const DB_NUMERIC&    dbnum,
                                                TNumericDigit* const pDigit)
{
 assert(pDigit);

 pDigit->init();

 UINT i_power_2=0;

 for(UINT iVal=0;iVal!=_DIM_(dbnum.val);++iVal)
 {
  if(!dbnum.val[iVal])
  {
   i_power_2+=8;//пропускаем 8 бит
   continue;
  }

  for(BYTE mask=0x01;mask!=0;mask=BYTE(mask<<1),++i_power_2)
  {
   if(dbnum.val[iVal]&mask)
   {
    assert(i_power_2<_DIM_(tag_data::sm_power_2_map));

    if(!structure::add_fixed_precision_digit(*pDigit,tag_data::sm_power_2_map[i_power_2],*pDigit))
     return TDBTypeConverterCode::numeric_overflow;
   }
  }//for mask
 }//for iVal

 return S_OK;
}//UnpackNumericDigit

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::PackNumericDigit(const TNumericDigit& digit,
                                              DB_NUMERIC* const    pDBNum)
{
 assert(pDBNum);

 (*pDBNum)=__null_dbnumeric__;

 TNumericDigit _digit(digit);

 _digit.pack();

 if(_digit.empty()) //нулевое число
  return S_OK;

 //результат сравнения
 int cmp=-1;

 for(size_t i_power_2=_DIM_(tag_data::sm_power_2_map);i_power_2!=0;)
 {
  --i_power_2;

  cmp=structure::cmp_fixed_precision_digit(_digit,tag_data::sm_power_2_map[i_power_2]);

  if(cmp<0)
   continue;

  const size_t i_byte=i_power_2/CHAR_BIT; //делим на 8

  const BYTE mask=BYTE(1<<(i_power_2-i_byte*CHAR_BIT));

  if(i_byte>=_DIM_(pDBNum->val))
   return TDBTypeConverterCode::numeric_overflow;

  pDBNum->val[i_byte]|=mask;

  if(cmp==0)
   break;

  //уменьшаем digit
  BYTE carrying=0;

  for(TNumericDigit::size_type i_digit=0;i_digit!=_digit.size();++i_digit)
  {
   //используются в вычитании
   BYTE r=carrying;

   if(i_digit<tag_data::sm_power_2_map[i_power_2].size())
    r+=tag_data::sm_power_2_map[i_power_2][i_digit];

   if(_digit[i_digit]<r)
   {
    //заимствуем из старшей части
    _digit[i_digit]=BYTE(_digit[i_digit]+10-r);

    carrying=1;
   }
   else
   {
    _digit[i_digit]=BYTE(_digit[i_digit]-r);

    carrying=0;
   }//else
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

 return S_OK;
}//PackNumericDigit

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::ScaleNumeric(const DB_NUMERIC& dbnum,
                                          BYTE        const scale,
                                          DB_NUMERIC* const result_dbnum)
{
 assert(result_dbnum);

 if(dbnum.scale==scale)
 {
  (*result_dbnum)=dbnum;

  return S_OK;
 }//if

 //распаковываем число
 TNumericDigit digit;

 {
  const HRESULT unpack_hr=self_type::UnpackNumericDigit(dbnum,&digit);

  if(FAILED(unpack_hr))
   return unpack_hr;

  assert(unpack_hr==S_OK);
 }//local

 if(digit.empty())
 {
  (*result_dbnum)=dbnum;

  result_dbnum->scale=scale;

  return S_OK;
 }//if

 //масштабируем число -----------------------------------------------
 if(dbnum.scale<scale)
 {
  //масштаб исходного числа меньше требуемого
  //значит число нужно умножать на 10^(scale-dbnum.scale)
  if(!digit.shift_on_positive_scale(scale-dbnum.scale))
   return TDBTypeConverterCode::numeric_overflow;
 }
 else
 {
  //масштаб больше требуемого
  //значит число нужно принудительно разделить на 10^(dbnum.scale-scale)
  if(!digit.shift_on_negative_scale(dbnum.scale-scale,/*round*/true))
   return TDBTypeConverterCode::numeric_overflow;
 }//else dbnum.scale>scale

 //запаковываем число обратно
 DB_NUMERIC new_dbnum;

 {
  const HRESULT pack_hr=self_type::PackNumericDigit(digit,&new_dbnum);

  if(FAILED(pack_hr))
   return pack_hr;

  assert(pack_hr==S_OK);
 }//local

 new_dbnum.precision  =dbnum.precision;
 new_dbnum.scale      =scale;
 new_dbnum.sign       =dbnum.sign;

 (*result_dbnum)=new_dbnum;

 return S_OK;
}//ScaleNumeric

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::NumericToInt(const DB_NUMERIC&     dbnum,
                                          signed __int64* const pValue)
{
 assert(pValue);

 (*pValue)=0;

 TNumericDigit digit;

 {
  const HRESULT unpack_hr=self_type::UnpackNumericDigit(dbnum,&digit);

  if(FAILED(unpack_hr))
   return unpack_hr;

  assert(unpack_hr==S_OK);
 }//local

 digit.pack();

 if(digit.empty())
  return S_OK;

 {
  auto scale=dbnum.scale;

  if(digit.size()<scale) //все уходит в дробную часть
   return S_OK;

  if(oledb_i8_precision<(digit.size()-scale)) /*POINT_A*/
   return TDBTypeConverterCode::numeric_overflow; //переполнение

  //сдвиг в дробную часть
  digit.shift_on_negative_scale(scale,/*round=*/true);
 }//local

 if(digit.empty())
  return S_OK;

 unsigned __int64 v1=0;

 {
  const unsigned __int64 ui8_max_div10=(_UI64_MAX)/10;

  for(TNumericDigit::size_type i=digit.size();i!=0;)
  {
   --i;

   if(v1>ui8_max_div10)
    return TDBTypeConverterCode::numeric_overflow;

   v1=(10*v1);

   if(((_UI64_MAX)-digit[i])<v1)
   {
    //
    // Это ситуация обрабатывается в POINT_A
    //
    // [2021-03-04] Потому что в max_ui8 20 цифр, в max_i8 - 19 цифр.
    //
    assert(false);

    return TDBTypeConverterCode::numeric_overflow;
   }//if

   v1=v1+digit[i];
  }//for i
 }//local

 if(dbnum.sign==0)
 {
  if(v1>(static_cast<unsigned __int64>(_I64_MAX)+1))
   return TDBTypeConverterCode::numeric_overflow;

  if(v1==(static_cast<unsigned __int64>(_I64_MAX)+1))
   (*pValue)=_I64_MIN;
  else
   (*pValue)=-static_cast<__int64>(v1);
 }
 else
 {
  if(v1>_I64_MAX)
   return TDBTypeConverterCode::numeric_overflow;

  (*pValue)=v1;
 }//else

 return S_OK;
}//DBNumericToInt (__int64)

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::NumericToInt(const DB_NUMERIC&       dbnum,
                                          unsigned __int64* const pValue)
{
 assert(pValue);

 (*pValue)=0;

 TNumericDigit digit;

 {
  const HRESULT unpack_hr=UnpackNumericDigit(dbnum,&digit);

  if(FAILED(unpack_hr))
   return unpack_hr;

  assert(unpack_hr==S_OK);
 }//local

 digit.pack();

 if(digit.empty())
  return S_OK;

 {
  auto scale=dbnum.scale;

  if(digit.size()<scale) //все уходит в дробную часть
   return S_OK;

  if(oledb_ui8_precision<(digit.size()-scale))
   return TDBTypeConverterCode::numeric_overflow; //переполнение

  //сдвиг в дробную часть
  digit.shift_on_negative_scale(scale,/*round=*/true);
 }//local

 if(digit.empty())
  return S_OK;

 unsigned __int64 v1=0;

 {
  const unsigned __int64 ui8_max_div10=(_UI64_MAX)/10;

  for(TNumericDigit::size_type i=digit.size();i!=0;)
  {
   --i;

   if(v1>ui8_max_div10)
    return TDBTypeConverterCode::numeric_overflow;

   v1=(10*v1);

   if(((_UI64_MAX)-digit[i])<v1)
    return TDBTypeConverterCode::numeric_overflow;

   v1=v1+digit[i];
  }//for i
 }//local

 if(dbnum.sign==0 && v1>0)
  return TDBTypeConverterCode::numeric_overflow;

 (*pValue)=v1;

 return S_OK;
}//DBNumericToInt (unsigned __int64)

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::NumericToR4(const DB_NUMERIC& dbnum,
                                         float* const      pValue)
{
 assert(pValue);

 (*pValue)=0;

 double dbl=0;

 const HRESULT cvt_hr=self_type::NumericToR8(dbnum,&dbl);

 if(FAILED(cvt_hr))
  return cvt_hr;

 assert(cvt_hr==S_OK);

 if(dbl<-FLT_MAX || dbl>FLT_MAX)
  return TDBTypeConverterCode::numeric_overflow;

 (*pValue)=static_cast<float>(dbl);

 return S_OK;
}//NumericToR4

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::NumericToR8(const DB_NUMERIC& dbnum,
                                         double* const     pValue)
{
 assert(pValue);

 (*pValue)=0;

 //распаковываем NUMERIC
 TNumericDigit digit;

 {
  const HRESULT unpack_hr=self_type::UnpackNumericDigit(dbnum,&digit);

  if(FAILED(unpack_hr))
   return unpack_hr; //TDBTypeConverterCode::numeric_overflow?

  assert(unpack_hr==S_OK);
 }//local

 cvt_r8_middle_int_type ui8(0);

 int scale;

 {
  TNumericDigit::size_type s(0);

  for(;s!=digit.size();++s)
  {
   if(digit[s]!=0)
    break;
  }//for

  TNumericDigit::size_type nPos(digit.size());

  assert(oledb_r8_precision<c_cvt_r8_middle_int_precision);

  for(;nPos!=s && size_t(digit.size()-nPos)<c_cvt_r8_middle_int_precision;)
  {
   --nPos;

   const TNumericDigit::element_type x=digit[nPos];

   ui8=ui8*10+x;
  }//for

  scale =static_cast<int>(nPos);
  scale-=int(dbnum.scale);
 }//local

 double r8(static_cast<double>(ui8));

 {
  //масштабируем число
  const bool negative_scale=scale<0;

  if(negative_scale)
   scale=-scale;

  HRESULT const scale_hr=self_type::ScaleDoubleValue(r8,scale,!negative_scale);

  if(FAILED(scale_hr))
   return scale_hr;

  assert(scale_hr==S_OK);
 }//local

 if(dbnum.sign==0)
  (*pValue)=-r8;
 else
  (*pValue)=r8;

 return S_OK;
}//NumericToR8

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::NumericToCY(const DB_NUMERIC&     dbnum,
                                         signed __int64* const pValue)
{
 assert(pValue);

 (*pValue)=0;

 DB_NUMERIC scaled_dbnum;

 //масштабируем число
 const HRESULT scale_hr=self_type::ScaleNumeric(dbnum,oledb_cy_fraction_part_scale,&scaled_dbnum);

 if(FAILED(scale_hr))
  return scale_hr;

 assert(scale_hr==S_OK);

 //проверяем результат масштабирования
 assert_msg(scaled_dbnum.scale==oledb_cy_fraction_part_scale,"scale="<<scaled_dbnum.scale);

 //отменяем масштаб
 scaled_dbnum.scale=0;

 //конвертируем в int64
 return self_type::NumericToInt(scaled_dbnum,pValue);
}//NumericToCY

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::NumericToString(const DB_NUMERIC&  dbnum,
                                             std::string* const pStr)
{
 return self_type::NumericToText(dbnum,pStr);
}//NumericToString - string

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::NumericToString(const DB_NUMERIC&   dbnum,
                                             std::wstring* const pWStr)
{
 return self_type::NumericToText(dbnum,pWStr);
}//NumericToString - wstring

//------------------------------------------------------------------------------
std::string DBVARIANT_CVT_UTILS::NumericToStr(const DB_NUMERIC& x,
                                              bool* const       error)
{
 std::string s;

 if(FAILED(self_type::NumericToString(x,&s)))
 {
  if(error!=NULL)
   *error=true;
 }
 else
 {
  if(error!=NULL)
   *error=false;
 }//else

 return s;
}//NumericToStr

//------------------------------------------------------------------------------
std::wstring DBVARIANT_CVT_UTILS::NumericToWStr(const DB_NUMERIC& x,
                                                bool* const       error)
{
 std::string s;

 if(FAILED(self_type::NumericToString(x,&s)))
 {
  if(error!=NULL)
   *error=true;
 }
 else
 {
  if(error!=NULL)
   *error=false;
 }//else

 return structure::ansi_to_unicode(s);
}//NumericToWStr

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::NumericToVariant(const DB_NUMERIC& dbnum,
                                              VARIANT* const    pVar)
{
 assert(pVar);

 tagDEC dec;

 const HRESULT hr=self_type::NumericToDecimal(dbnum,&dec);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 return self_type::DecimalToVariant(dec,pVar);
}//NumericToVariant

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::NumericToBool(const DB_NUMERIC& dbnum,
                                           bool* const       pValue)
{
 assert(pValue);

 size_t i;

 //ищем ненулевой байт
 for(i=0;i!=_DIM_(dbnum.val) && !dbnum.val[i];++i);

 (*pValue)=(i!=_DIM_(dbnum.val));

 return S_OK;
}//NumericToBool

//------------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::NumericToDecimal(const DB_NUMERIC& dbnum,
                                              tagDEC* const     pValue)
{
 assert(pValue);

 //--------------------------------------
 (*pValue)=__null_decimal__;

 //try direct store numeric to decimal format
 if(dbnum.scale<=oledb_decimal_max_scale)
 {
  UINT n_used_bytes=_DIM_(dbnum.val);

  for(;n_used_bytes!=0;)
  {
   --n_used_bytes;

   if(dbnum.val[n_used_bytes]==0)
    continue;

   ++n_used_bytes;
   break;
  }//for

  assert(n_used_bytes<=_DIM_(dbnum.val));

  if(n_used_bytes<=12)
  {
   assert_s(sizeof(pValue->Lo32)  ==4);
   assert_s(sizeof(pValue->Mid32) ==4);
   assert_s(sizeof(pValue->Hi32)  ==4);

   pValue->Lo32 =  (ULONG(dbnum.val[ 0]))
                  |(ULONG(dbnum.val[ 1])<<8)
                  |(ULONG(dbnum.val[ 2])<<16)
                  |(ULONG(dbnum.val[ 3])<<24);

   pValue->Mid32=  (ULONG(dbnum.val[ 4]))
                  |(ULONG(dbnum.val[ 5])<<8)
                  |(ULONG(dbnum.val[ 6])<<16)
                  |(ULONG(dbnum.val[ 7])<<24);

   pValue->Hi32 =  (ULONG(dbnum.val[ 8]))
                  |(ULONG(dbnum.val[ 9])<<8)
                  |(ULONG(dbnum.val[10])<<16)
                  |(ULONG(dbnum.val[11])<<24);

   OLEDB_DECIMAL_SCALE((*pValue))=(BYTE)(dbnum.scale);

   OLEDB_DECIMAL_SIGN ((*pValue))=(BYTE)(dbnum.sign?0:DECIMAL_NEG);

   return S_OK;
  }//if n_used_bytes<=12
 }//if

 //transform numeric to decimal
 self_type::TNumericDigit digit;

 {
  const HRESULT unpack_hr=self_type::UnpackNumericDigit(dbnum,&digit);

  if(FAILED(unpack_hr))
   return unpack_hr;

  assert(unpack_hr==S_OK);
 }//local

 size_t scale=dbnum.scale;

 //целая часть не поместится в DECIMAL представление
 if(digit.size()>oledb_decimal_precision+scale)
  return TDBTypeConverterCode::numeric_overflow;

 if(digit.size()>oledb_decimal_precision)
 {
  const size_t n_shift_down=digit.size()-oledb_decimal_precision;

  _VERIFY(digit.shift_on_negative_scale(n_shift_down,true));

  assert(scale>=n_shift_down);

  scale-=n_shift_down;
 }//if

 //ограничиваем максимальное значение масштаба
 if(scale>oledb_decimal_max_scale)
 {
  const size_t n_shift_down=scale-oledb_decimal_max_scale;

  _VERIFY(digit.shift_on_negative_scale(n_shift_down,true));

  scale-=n_shift_down;
 }//if

 assert(digit.size()<=oledb_decimal_precision);
 assert(scale<=oledb_decimal_max_scale);

 {
  const HRESULT pack_hr=self_type::PackDecimalDigit(digit,pValue);

  if(FAILED(pack_hr))
  {
   (*pValue)=__null_decimal__;

   return pack_hr;
  }//if

  assert(pack_hr==S_OK);
 }//local

 OLEDB_DECIMAL_SCALE((*pValue))=(BYTE)(scale);
 OLEDB_DECIMAL_SIGN ((*pValue))=(BYTE)(dbnum.sign?0:DECIMAL_NEG);

 return S_OK;
}//NumericToDecimal

////////////////////////////////////////////////////////////////////////////////

template<class charT>
HRESULT DBVARIANT_CVT_UTILS::TextToNumeric(const charT*      str,
                                           size_type         str_size,
                                           DB_NUMERIC* const pDBNum)
{
 assert(pDBNum);

 //-----------------------------------------
 typedef charT                                           char_type;
 typedef structure::t_char_traits2<char_type>            char_traits2;

 //-----------------------------------------
 (*pDBNum)=__null_dbnumeric__;

 enum
 {
  c_max_precision  =oledb_numeric_precision,
  c_max_scale      =oledb_numeric_max_scale,
 };

 DB_NUMERIC dbnum(__null_dbnumeric__);

 dbnum.sign=1;

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
  ++str;//skeep sign symbol

 if(str==end_str)
  return DB_E_CANTCONVERTVALUE;

 switch(const HRESULT hr=self_type::TextWithHexNumberToByteArray3
                                            (str,
                                             end_str,
                                             dbnum.val,
                                             _DIM_(dbnum.val)))
 {
  case DB_E_CANTCONVERTVALUE: //str not has hex number
   {
    break;
   }

  case S_OK: //str has hex number
   {
    dbnum.sign=(sign!=2);
    dbnum.precision=c_max_precision;

    (*pDBNum)=dbnum;

    return hr;
   }

  default: //fail convert str to number
   {
    assert(FAILED(hr));

    return hr;
   }
 }//switch try convert to hex

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
  const HRESULT pack_hr=self_type::PackNumericDigit(digit,&dbnum);

  if(FAILED(pack_hr))
   return pack_hr;

  assert(pack_hr==S_OK);
 }//local

 assert(digit.size()<=c_max_precision);
 assert(scale<=c_max_scale);

 assert(structure::can_numeric_cast<BYTE>(digit.size()));
 assert(structure::can_numeric_cast<BYTE>(scale));

 dbnum.sign      =(sign!=2); //неотрицательное число
 dbnum.precision =static_cast<BYTE>(digit.size());
 dbnum.scale     =static_cast<BYTE>(scale);

 //----
 (*pDBNum)=dbnum;

 return S_OK;
}//TextToNumeric

//------------------------------------------------------------------------
template<class stringT>
HRESULT DBVARIANT_CVT_UTILS::NumericToText(const DB_NUMERIC& dbnum,
                                           stringT*  const   pStr)
{
 assert(pStr);

 //-----------------------------------------
 typedef stringT                                string_type;
 typedef string_type::value_type                char_type;
 typedef structure::t_char_traits2<char_type>   char_traits2;

 //----
 const char_type c_ch_0      =char_traits2::ch_0();
 const char_type c_ch_point  =char_traits2::ch_point();
 const char_type c_ch_minus  =char_traits2::ch_minus();

 //-----------------------------------------
 TNumericDigit digit;

 pStr->erase();

 {
  const HRESULT unpack_hr=self_type::UnpackNumericDigit(dbnum,&digit);

  if(FAILED(unpack_hr))
   return unpack_hr;

  assert(unpack_hr==S_OK);
 }//local

 string_type str;

 for(TNumericDigit::size_type i=digit.size()-1;i!=-1;--i)
  str+=static_cast<char_type>(c_ch_0+digit[i]);

 if(UINT(dbnum.scale)>=str.size())
  str.insert(string_type::size_type(0),UINT(dbnum.scale)-str.size()+1,c_ch_0);

 if(dbnum.scale!=0)
  str.insert(str.end()-UINT(dbnum.scale),c_ch_point);

 if(dbnum.sign==0)
  str.insert(str.begin(),c_ch_minus);

 pStr->swap(str);

 return S_OK;
}//NumericToText

////////////////////////////////////////////////////////////////////////////////
