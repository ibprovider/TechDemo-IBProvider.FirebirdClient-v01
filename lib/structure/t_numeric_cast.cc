////////////////////////////////////////////////////////////////////////////////
#ifndef _t_numeric_cast_CC_
#define _t_numeric_cast_CC_

#include <sstream>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
#if(!COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
# error "Compiler not support template members!"
#endif

////////////////////////////////////////////////////////////////////////////////

template<bool ToTypeIsSigned,bool FromTypeIsSigned>
class tag_can_numeric_cast;

////////////////////////////////////////////////////////////////////////////////
//Signed to Unsigned

#if(defined(COMP_CONF_BORLAND__HAS_BUG_IN_W8012_FOR_TWO_UNSIGNED))
# if(COMP_CONF_BORLAND__HAS_BUG_IN_W8012_FOR_TWO_UNSIGNED)
#  pragma option push -w-8012
# endif
#endif

template<>
class tag_can_numeric_cast<false,true>
{
 public:
  template<typename /*unsigned*/ToType,typename FromType>
  static RELEASE_CODE(inline) bool test(/*signed*/FromType x)
  {
   typedef t_numeric_limits<FromType> from_limits;
   typedef t_numeric_limits<ToType>   to_limits;

   assert(from_limits::is_signed);
   assert(!to_limits::is_signed);

   return x>=0 && from_limits::unsigned_numeric_type(x)<=to_limits::max_value();
  }
};//tag_can_numeric_cast

////////////////////////////////////////////////////////////////////////////////
//Unsigned to Signed

template<>
class tag_can_numeric_cast<true,false>
{
 public:
  template<typename /*signed*/ToType,typename FromType>
  static RELEASE_CODE(inline) bool test(/*unsigned*/FromType x)
  {
   typedef t_numeric_limits<FromType> from_limits;
   typedef t_numeric_limits<ToType>   to_limits;

   assert(!from_limits::is_signed);
   assert(to_limits::is_signed);

   return x<=to_limits::unsigned_numeric_type(to_limits::max_value());
  }
};//tag_can_numeric_cast

////////////////////////////////////////////////////////////////////////////////
//Unsigned to Unsigned

template<>
class tag_can_numeric_cast<false,false>
{
 public:
  template<typename /*unsigned*/ToType,typename FromType>
  static RELEASE_CODE(inline) bool test(/*unsigned*/FromType x)
  {
   typedef t_numeric_limits<FromType> from_limits;
   typedef t_numeric_limits<ToType>   to_limits;

   assert(!from_limits::is_signed);
   assert(!to_limits::is_signed);

   return x<=to_limits::max_value();
  }
};//tag_can_numeric_cast

#if(defined(COMP_CONF_BORLAND__HAS_BUG_IN_W8012_FOR_TWO_UNSIGNED))
# if(COMP_CONF_BORLAND__HAS_BUG_IN_W8012_FOR_TWO_UNSIGNED)
#  pragma option pop
# endif
#endif

////////////////////////////////////////////////////////////////////////////////
//Signed to Signed

template<>
class tag_can_numeric_cast<true,true>
{
 public:
  template<typename /*signed*/ToType,typename FromType>
  static RELEASE_CODE(inline) bool test(/*signed*/FromType x)
  {
   typedef t_numeric_limits<FromType> from_limits;
   typedef t_numeric_limits<ToType>   to_limits;

   assert(from_limits::is_signed);
   assert(to_limits::is_signed);

   return to_limits::min_value()<=x && x<=to_limits::max_value();
  }
};//tag_can_numeric_cast

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
inline bool can_numeric_cast(FromType x)
{
 typedef tag_can_numeric_cast<t_numeric_limits<ToType>::is_signed,
                              t_numeric_limits<FromType>::is_signed> tag;

 return tag::template test<ToType>(x);
}//can_numeric_cast

//------------------------------------------------------------------------
template<typename ToType,typename FromType>
inline bool can_numeric_cast(ToType*,FromType x)
{
 typedef tag_can_numeric_cast<t_numeric_limits<ToType>::is_signed,
                              t_numeric_limits<FromType>::is_signed> tag;

 return tag::template test<ToType>(x);
}//can_numeric_cast

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
inline ToType static_numeric_cast(FromType x)
{
 return static_cast<ToType>(x);
}//static_numeric_cast

//------------------------------------------------------------------------
template<typename ToType,typename FromType>
inline void static_numeric_cast(ToType* pdest,FromType x)
{
 assert(pdest);

 (*pdest)=static_numeric_cast<ToType,FromType>(x);
}//static_numeric_cast

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
void raise_numeric_cast_error(FromType x,const char* err_source)
{
 typedef structure::t_numeric_limits<FromType> from_limits;
 typedef structure::t_numeric_limits<ToType>   to_limits;

 std::ostringstream fmsg;

 fmsg<<err_source
     <<": can't convert '"
     <<typeid(FromType).name()
     <<"' [value: "
     <<from_limits::print_numeric_type(x)
     <<"] to '"
     <<typeid(ToType).name()
     <<"' [range: "
     <<to_limits::print_numeric_type(to_limits::min_value())
     <<".."
     <<to_limits::print_numeric_type(to_limits::max_value())
     <<"].";

 throw std::overflow_error(fmsg.str());
}//raise_numeric_cast_error

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
ToType verified_numeric_cast(FromType x,const char* err_source)
{
 if(!can_numeric_cast<ToType>(x))
  raise_numeric_cast_error<ToType>(x,err_source?err_source:"verified_numeric_cast");

 return static_cast<ToType>(x);
}//verified_numeric_cast

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
void verified_numeric_cast(ToType* pdest,FromType x,const char* err_source)
{
 assert(pdest);

 (*pdest)=verified_numeric_cast<ToType>(x,err_source);
}//verified_numeric_cast

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
void raise_length_cast_error(FromType x,const char* err_source)
{
 typedef structure::t_numeric_limits<FromType> from_limits;
 typedef structure::t_numeric_limits<ToType>   to_limits;

 std::ostringstream fmsg;

 fmsg<<err_source
     <<": bad length ["
     <<from_limits::print_numeric_type(x)
     <<"]. Support length range ["
     <<to_limits::print_numeric_type(to_limits::min_value())
     <<".."
     <<to_limits::print_numeric_type(to_limits::max_value())
     <<"].";

 throw std::length_error(fmsg.str());
}//raise_length_cast_error

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
ToType verified_length_cast(FromType x,const char* err_source)
{
 if(!can_numeric_cast<ToType>(x))
  raise_length_cast_error<ToType>(x,err_source?err_source:"verified_length_cast");

 return static_cast<ToType>(x);
}//verified_length_cast

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
void verified_length_cast(ToType* pdest,FromType x,const char* err_source)
{
 assert(pdest);

 (*pdest)=verified_length_cast<ToType>(x,err_source);
}//verified_length_cast

////////////////////////////////////////////////////////////////////////////////

template<bool FromTypeIsSigned>
class tag_remove_numeric_sign;

////////////////////////////////////////////////////////////////////////////////
//From unsigned

template<>
class tag_remove_numeric_sign<false>
{
 public:
  template<typename FromType>
  static RELEASE_CODE(inline)
   FromType exec(/*unsigned*/FromType x)
  {
   typedef t_numeric_limits<FromType> from_limits;

   assert_s(!from_limits::is_signed);

   return x;
  }//exec
};//tag_remove_numeric_sign<false>

////////////////////////////////////////////////////////////////////////////////
//From signed

template<>
class tag_remove_numeric_sign<true>
{
 public:
  template<typename FromType>
  static RELEASE_CODE(inline)
   typename structure::t_numeric_limits<FromType>::unsigned_numeric_type exec(/*signed*/FromType const x)
  {
   typedef t_numeric_limits<FromType>             from_limits;
   typedef from_limits::unsigned_numeric_type     result_type;

   assert_s(from_limits::is_signed);
   assert((-from_limits::max_value()-1)==from_limits::min_value());

   if(x>0)
    return static_cast<result_type>(x);

   if(x==from_limits::min_value())
    return static_cast<result_type>(static_cast<result_type>(from_limits::max_value())+1);

   return static_cast<result_type>(-x);
  }//exec
};//tag_remove_numeric_sign<true>

////////////////////////////////////////////////////////////////////////////////

template<typename FromType>
typename structure::t_numeric_limits<FromType>::unsigned_numeric_type
 remove_numeric_sign(FromType const x)
{
 typedef tag_remove_numeric_sign<t_numeric_limits<FromType>::is_signed> tag;

 return tag::exec(x);
}//remove_numeric_sign

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
