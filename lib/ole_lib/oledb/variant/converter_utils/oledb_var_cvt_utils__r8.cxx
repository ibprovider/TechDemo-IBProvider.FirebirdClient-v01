////////////////////////////////////////////////////////////////////////////////
//DBVARIANT_CVT_UTILS Implementation.
//                                                 Kovalenko Dmitry. 13.02.2010.

////////////////////////////////////////////////////////////////////////////////

HRESULT DBVARIANT_CVT_UTILS::StrToR8(const char* const str,
                                     size_type   const str_size,
                                     double*     const pValue)
{
 return self_type::TextToR8(str,str_size,pValue);
}//StrToR8

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::WStrToR8(const wchar_t* const str,
                                      size_type      const str_size,
                                      double*        const pValue)
{
 return self_type::TextToR8(str,str_size,pValue);
}//WStrToR8

//------------------------------------------------------------------------
template<class charT>
HRESULT DBVARIANT_CVT_UTILS::TextToR8(const charT*  str,
                                      size_type     str_size,
                                      double* const pDouble)
{
 assert(pDouble);

 //-----------------------------------------
 typedef charT                                           char_type;
 typedef structure::t_char_traits2<char_type>            char_traits2;
 typedef tag_float_parts_in_str<char_type>               parts_type;

 const char_type c_ch_0=char_traits2::ch_0();
#ifndef NDEBUG
 const char_type c_ch_9=char_traits2::ch_9();
#endif

 //-----------------------------------------
 (*pDouble)=0;

 if(str==NULL)
  return DB_E_CANTCONVERTVALUE;

 if(str_size==self_type::npos)
  str_size=std::char_traits<char_type>::length(str);

 const char_type* const end_str=str+str_size;

 CHECK_READ_PTR(str,str_size*sizeof(*str));

 //-----------------------------------------
 parts_type parts;

 {
  HRESULT const get_hr=self_type::GetFloatNumberParts(str,end_str,0,&str,&parts);

  if(FAILED(get_hr))
   return get_hr;

  assert(get_hr==S_OK);
 }//local

 //-----------------------------------------
 typedef structure::t_first_last<typename parts_type::const_pointer> deque_block_type;

 typedef structure::t_deque_adapter<const deque_block_type*,
                                    char_type>                       digits_type;

 //-----
 const deque_block_type deque_blocks[2]=
 {
  deque_block_type(parts.int_part_beg,
                   parts.int_part_end),
  deque_block_type(parts.float_part_beg,
                   parts.float_part_end),
 };//deque_blocks

 const digits_type digits(deque_blocks,_END_(deque_blocks));

 //-----------------------------------------
 const typename digits_type::size_type point_position
  =static_cast<size_t>(parts.int_part_end-parts.int_part_beg);

 assert(point_position<=digits.size());

 //-----------------------------------------
 typename digits_type::size_type iStart(0);
 typename digits_type::size_type iStop(digits.size());

 for(;iStart!=iStop && digits[iStart]==c_ch_0;++iStart);

 for(;iStop!=iStart && digits[iStop-1]==c_ch_0;--iStop);

 //-----------------------------------------
 cvt_r8_middle_int_type Result_UI64(0);

 typename digits_type::size_type nPos(iStart);

 for(;nPos!=iStop && nPos<c_cvt_r8_middle_int_precision;++nPos)
 {
  const char_type c=digits[nPos];

  assert(c>=c_ch_0 && c<=c_ch_9);

  const BYTE d=static_cast<BYTE>(c-c_ch_0);

  Result_UI64=Result_UI64*10+d;
 }//if

 if(Result_UI64==0)
 {
  if(parts.mantisse_sign==parts_type::sign_kind__negative)
   (*pDouble)=-0.0;
  else
   (*pDouble)=0.0;

  return S_OK;
 }//if

 //----------------------------------------- SCALE PART
 typedef size_t scale_type;

 scale_type Result_Scale(0);

 {
  const scale_type
   max_scale=structure::t_numeric_limits<scale_type>().max_value();

  const scale_type
   max_scale_div10=max_scale/10;

  for(typename parts_type::const_pointer pos=parts.scale_part_beg;pos!=parts.scale_part_end;++pos)
  {
   assert((*pos)>=c_ch_0 && (*pos)<=c_ch_9);

   if((*pos)==c_ch_0 && Result_Scale==0)
    continue;

   if(Result_Scale>max_scale_div10)
    return TDBTypeConverterCode::numeric_overflow;

   Result_Scale*=10;

   assert(Result_Scale<=max_scale);

   const BYTE d=static_cast<BYTE>((*pos)-c_ch_0);

   if(static_cast<scale_type>(max_scale-Result_Scale)<scale_type(d))
    return TDBTypeConverterCode::numeric_overflow;

   Result_Scale+=d;
  }//for pos
 }//local

 //-----------------------------------------
 if(parts.scale_sign==parts_type::sign_kind__negative)
 {
  if(nPos<point_position)
  {
   //  |<--iStart nPos-->|
   //  xxxxxxxxxxxxxxxxxxxignore.ignore

   const size_t x=point_position-nPos;

   if(x>Result_Scale)
   {
    Result_Scale=x-Result_Scale;
    parts.scale_sign=parts_type::sign_kind__undefined;
   }
   else
   {
    Result_Scale-=x;
   }
  }
  else
  {
   //  |<--iStart nPos-->|
   //  xxxxxxxxxxxxxx.xxxxignore

   const size_t x=nPos-point_position;

   if(structure::get_numeric_limits(Result_Scale).max_value()-Result_Scale<x)
   {
    if(parts.mantisse_sign==parts_type::sign_kind__negative)
     (*pDouble)=-1/HUGE_VAL;
    else
     (*pDouble)=1/HUGE_VAL;

    return S_OK;
   }//if

   Result_Scale+=x;
  }
 }
 else
 {
  assert(parts.scale_sign!=parts_type::sign_kind__negative);

  if(nPos<point_position)
  {
   //  |<--iStart nPos-->|
   //  xxxxxxxxxxxxxxxxxxxignore.ignore

   const size_t x=point_position-nPos;

   if(structure::get_numeric_limits(Result_Scale).max_value()-Result_Scale<x)
   {
    if(parts.mantisse_sign==parts_type::sign_kind__negative)
     (*pDouble)=-HUGE_VAL;
    else
     (*pDouble)=HUGE_VAL;

    return TDBTypeConverterCode::numeric_overflow;
   }//if

   Result_Scale+=x;
  }
  else
  {
   //  |<--iStart nPos-->|
   //  xxxxxxxxxxxxxx.xxxxignore

   const size_t x=nPos-point_position;

   if(x>Result_Scale)
   {
    Result_Scale=x-Result_Scale;
    parts.scale_sign=parts_type::sign_kind__negative;
   }
   else
   {
    Result_Scale-=x;
   }
  }
 }//else

 double Result(static_cast<double>(Result_UI64));

 {
  const HRESULT
   scale_hr
    =self_type::ScaleDoubleValue
      (Result,
       Result_Scale,
       parts.scale_sign!=parts_type::sign_kind__negative);

  if(FAILED(scale_hr))
   return scale_hr;

  assert(scale_hr==S_OK);
 }//local

 //-----------------------------------------
 if(!_finite(Result))
  return TDBTypeConverterCode::numeric_overflow;

 if(parts.mantisse_sign==parts_type::sign_kind__negative)
  (*pDouble)=-Result;
 else
  (*pDouble)=Result;

 return S_OK;
}//TextToR8

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::ScaleDoubleValue(double&    Result_Part,
                                              size_t     Result_Scale,
                                              bool const Result_Scale_IsPositive)
{
 typedef size_type scale_type;

 if(Result_Part==0)
  return S_OK;

 //-----------------------------------------
 if(Result_Scale_IsPositive)
 {
  assert(_DIM_(tag_data::sm_DblPow10)>1);

  while(Result_Scale!=0)
  {
   scale_type x=Result_Scale;

   if(x>=_DIM_(tag_data::sm_DblPow10))
    x=_DIM_(tag_data::sm_DblPow10)-1;

   assert(tag_data::sm_DblPow10[x]!=0);

   if(DBL_MAX/tag_data::sm_DblPow10[x]<Result_Part)
    return TDBTypeConverterCode::numeric_overflow;

   Result_Part=Result_Part*tag_data::sm_DblPow10[x];

   if(!_finite(Result_Part))
    return TDBTypeConverterCode::numeric_overflow;

   Result_Scale-=x;
  }//while
 }
 else
 {
  assert(_DIM_(tag_data::sm_DblPow10_Neg)>1);

  while(Result_Scale!=0)
  {
   scale_type x=Result_Scale;

   if(x>=_DIM_(tag_data::sm_DblPow10_Neg))
    x=_DIM_(tag_data::sm_DblPow10_Neg)-1;

   Result_Part=Result_Part*tag_data::sm_DblPow10_Neg[x];

   Result_Scale-=x;
  }//while
 }//else

 return S_OK;
}//ScaleDoubleValue

////////////////////////////////////////////////////////////////////////////////
