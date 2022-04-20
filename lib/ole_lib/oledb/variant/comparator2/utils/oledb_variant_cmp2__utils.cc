////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_variant_cmp2__utils_CC_
#define _oledb_variant_cmp2__utils_CC_

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////
//class DBValueComparator

template<typename T1,typename T2>
EnumDBVariantCmpCode DBValueComparator::compare__std
                                         (T1 const v1,
                                          T2 const v2)
{
 if(v1<v2)
  return DBVariantCmpCode__ok__less;

 if(v2<v1)
  return DBVariantCmpCode__ok__great;

 return DBVariantCmpCode__ok__equal;
}//compare__std

//------------------------------------------------------------------------
template<typename T1,typename T2>
EnumDBVariantCmpCode DBValueComparator::compare__signed_and_unsigned
                                         (T1 const v1,
                                          T2 const v2)
{
 typedef structure::t_numeric_limits<T1> _t1;
 typedef structure::t_numeric_limits<T2> _t2;

 assert_s(_t1::is_signed);
 assert_s(!_t2::is_signed);

 if(v1<0)
  return DBVariantCmpCode__ok__less;

 if(_t1::unsigned_numeric_type(v1)<v2)
  return DBVariantCmpCode__ok__less;

 if(v2<_t1::unsigned_numeric_type(v1))
  return DBVariantCmpCode__ok__great;

 return DBVariantCmpCode__ok__equal;
}//compare__signed_and_unsigned

//------------------------------------------------------------------------
template<typename T1,typename T2>
EnumDBVariantCmpCode DBValueComparator::compare__unsigned_and_signed
                                         (T1 const v1,
                                          T2 const v2)
{
 typedef structure::t_numeric_limits<T1> _t1;
 typedef structure::t_numeric_limits<T2> _t2;

 assert_s(!_t1::is_signed);
 assert_s(_t2::is_signed);

 if(v2<0)
  return DBVariantCmpCode__ok__great;

 if(v1<_t2::unsigned_numeric_type(v2))
  return DBVariantCmpCode__ok__less;

 if(_t2::unsigned_numeric_type(v2)<v1)
  return DBVariantCmpCode__ok__great;

 return DBVariantCmpCode__ok__equal;
}//compare__unsigned_and_signed

//------------------------------------------------------------------------
template<typename TChar>
EnumDBVariantCmpCode DBValueComparator::compare__str
                                         (const TChar* const s1,
                                          size_t       const n1,
                                          const TChar* const s2,
                                          size_t       const n2)
{
 size_t n=((n1<n2)?n1:n2);

 const TChar*       p1=s1;
 const TChar* const e1=s1+n;

 const TChar*       p2=s2;

 for(;p1!=e1;++p1,++p2)
 {
  if((*p1)==(*p2))
   continue;

  if((*p1)<(*p2))
   return DBVariantCmpCode__ok__less;

  return DBVariantCmpCode__ok__great;
 }//for[ever]

 if(n1<n2)
 {
  return DBVariantCmpCode__ok__less;
 }//if

 assert(!(n1<n2));

 if(n2<n1)
 {
  return DBVariantCmpCode__ok__great;
 }//if

 assert(n1==n2);

 return DBVariantCmpCode__ok__equal;
}//compare__str

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}//namespace oledb_lib
#endif
