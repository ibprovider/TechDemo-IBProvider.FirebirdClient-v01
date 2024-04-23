////////////////////////////////////////////////////////////////////////////////
//Construction for meta-programming
//                                                 Dmitry Kovalenko. 09.04.2005
#ifndef _lcpi_lib_structure__t_meta_prog_H_
#define _lcpi_lib_structure__t_meta_prog_H_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class T1,class T2>
class t_mp_conversion;

template<bool returnT1,class T1,class T2>
struct t_mp_select;

template<class T1,class T2>
class t_mp_is_supersubclass;

////////////////////////////////////////////////////////////////////////////////
//class t_mp_boolean

typedef char                     t_mp_false; //sizeof(t_mp_false)==1
typedef struct {char dummy[2];}  t_mp_true;  //sizeof(t_mp_true)>1

////////////////////////////////////////////////////////////////////////////////
//class t_mp_select<false>

template<class T1,class T2>
struct t_mp_select<false,T1,T2>
{
 typedef T2     result;
};//class t_mp_select<false>

////////////////////////////////////////////////////////////////////////////////
//class t_mp_select

template<bool returnT1,class T1,class T2>
struct t_mp_select
{
 typedef T1   result;
};//class t_mp_select

////////////////////////////////////////////////////////////////////////////////
//class t_mp_conversion

//can convert T1 to T2

template<class T>
const t_mp_true& mp_testC(const T&);

template<class T>
const t_mp_false& mp_testC(...);

template<class T1,class T2>
class t_mp_conversion
{
 public:
  typedef t_mp_conversion<T1,T2> self_type;

 private:
  typedef T1   t1_type;
  typedef T2   t2_type;

  static const t1_type* const sm_t1;

 public:
  static const bool exists=(sizeof(mp_testC<t2_type>(*sm_t1))==sizeof(t_mp_true));
  static const bool sameType=false;
};//class t_mp_conversion

////////////////////////////////////////////////////////////////////////////////
//class t_mp_conversion

template<class T>
class t_mp_conversion<T,T>
{
 public:
  static const bool exists=true;
  static const bool sameType=true;
};//t_mp_conversion

////////////////////////////////////////////////////////////////////////////////
//class t_mp_is_supersubclass

template<class T1,class T2>
class t_mp_is_supersubclass
{
 public:
  static const bool result=
   t_mp_conversion<const T2*,const T1*>::exists && !t_mp_conversion<const T1*,const void*>::sameType;
};//class t_mp_is_supersubclass

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
