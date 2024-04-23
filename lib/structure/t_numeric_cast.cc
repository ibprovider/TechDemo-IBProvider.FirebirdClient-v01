////////////////////////////////////////////////////////////////////////////////
#ifndef _lcpi_lib_structure__t_numeric_cast_CC_
#define _lcpi_lib_structure__t_numeric_cast_CC_

#include <sstream>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
#if(!COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
# error "Compiler not support template members!"
#endif

namespace detail{
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
class tag_can_numeric_cast<false,true> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename /*unsigned*/ToType,typename FromType>
  static LCPI__RELEASE_CODE(inline) bool test(/*signed*/FromType x)
  {
   using from_limits =t_numeric_limits<FromType>;
   using to_limits   =t_numeric_limits<ToType>;

   LCPI__assert_s(from_limits::is_signed);
   LCPI__assert_s(!to_limits::is_signed);

   using from_unsigned_t=typename from_limits::unsigned_numeric_type;

   return x>=0 && static_cast<from_unsigned_t>(x)<=to_limits::max_value();
  }//test
};//class tag_can_numeric_cast<false,true>

////////////////////////////////////////////////////////////////////////////////
//Unsigned to Signed

template<>
class tag_can_numeric_cast<true,false> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename /*signed*/ToType,typename FromType>
  static LCPI__RELEASE_CODE(inline) bool test(/*unsigned*/FromType x)
  {
   using from_limits =t_numeric_limits<FromType>;
   using to_limits   =t_numeric_limits<ToType>;

   LCPI__assert_s(!from_limits::is_signed);
   LCPI__assert_s(to_limits::is_signed);

   using to_unsigned_t=typename to_limits::unsigned_numeric_type;

   return x<=static_cast<to_unsigned_t>(to_limits::max_value());
  }//test
};//class tag_can_numeric_cast<true,false>

////////////////////////////////////////////////////////////////////////////////
//Unsigned to Unsigned

template<>
class tag_can_numeric_cast<false,false> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename /*unsigned*/ToType,typename FromType>
  static LCPI__RELEASE_CODE(inline) bool test(/*unsigned*/FromType x)
  {
   using from_limits =t_numeric_limits<FromType>;
   using to_limits   =t_numeric_limits<ToType>;

   LCPI__assert_s(!from_limits::is_signed);
   LCPI__assert_s(!to_limits::is_signed);

   return x<=to_limits::max_value();
  }//test
};//class tag_can_numeric_cast<false,false>

#if(defined(COMP_CONF_BORLAND__HAS_BUG_IN_W8012_FOR_TWO_UNSIGNED))
# if(COMP_CONF_BORLAND__HAS_BUG_IN_W8012_FOR_TWO_UNSIGNED)
#  pragma option pop
# endif
#endif

////////////////////////////////////////////////////////////////////////////////
//Signed to Signed

template<>
class tag_can_numeric_cast<true,true> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename /*signed*/ToType,typename FromType>
  static LCPI__RELEASE_CODE(inline) bool test(/*signed*/FromType x)
  {
   using from_limits =t_numeric_limits<FromType>;
   using to_limits   =t_numeric_limits<ToType>;

   LCPI__assert_s(from_limits::is_signed);
   LCPI__assert_s(to_limits::is_signed);

   return to_limits::min_value()<=x && x<=to_limits::max_value();
  }//test
};//class tag_can_numeric_cast<true,true>

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
inline bool can_numeric_cast(FromType x)
{
 using tag
  =detail::tag_can_numeric_cast
    <t_numeric_limits<ToType>::is_signed,
     t_numeric_limits<FromType>::is_signed>;

 return tag::template test<ToType>(x);
}//can_numeric_cast

//------------------------------------------------------------------------
template<typename ToType,typename FromType>
inline bool can_numeric_cast(ToType*,FromType x)
{
 using tag
  =detail::tag_can_numeric_cast
    <t_numeric_limits<ToType>::is_signed,
     t_numeric_limits<FromType>::is_signed>;

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
 LCPI__assert(pdest);

 (*pdest)=static_numeric_cast<ToType,FromType>(x);
}//static_numeric_cast

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
void raise_numeric_cast_error(FromType x,const char* err_source)
{
 using from_limits =structure::t_numeric_limits<FromType>;
 using to_limits   =structure::t_numeric_limits<ToType>;

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
 LCPI__assert(pdest);

 (*pdest)=verified_numeric_cast<ToType>(x,err_source);
}//verified_numeric_cast

////////////////////////////////////////////////////////////////////////////////

template<typename ToType,typename FromType>
void raise_length_cast_error(FromType x,const char* err_source)
{
 using from_limits =structure::t_numeric_limits<FromType>;
 using to_limits   =structure::t_numeric_limits<ToType>;

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
 LCPI__assert(pdest);

 (*pdest)=verified_length_cast<ToType>(x,err_source);
}//verified_length_cast

////////////////////////////////////////////////////////////////////////////////

template<bool FromTypeIsSigned>
class tag_remove_numeric_sign;

////////////////////////////////////////////////////////////////////////////////
//From unsigned

template<>
class tag_remove_numeric_sign<false> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename FromType>
  static LCPI__RELEASE_CODE(inline)
   FromType exec(/*unsigned*/FromType x)
  {
   using from_limits=t_numeric_limits<FromType>;

   LCPI__assert_s(!from_limits::is_signed);

   return x;
  }//exec
};//class tag_remove_numeric_sign<false>

////////////////////////////////////////////////////////////////////////////////
//From signed

template<>
class tag_remove_numeric_sign<true> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename FromType>
  static LCPI__RELEASE_CODE(inline)
   typename structure::t_numeric_limits<FromType>::unsigned_numeric_type exec(/*signed*/FromType const x)
  {
   using from_limits=t_numeric_limits<FromType>;

   using result_type=typename from_limits::unsigned_numeric_type;

   LCPI__assert_s(from_limits::is_signed);
   LCPI__assert((-from_limits::max_value()-1)==from_limits::min_value());

   if(x>0)
    return static_cast<result_type>(x);

   if(x==from_limits::min_value())
    return static_cast<result_type>(static_cast<result_type>(from_limits::max_value())+1);

   return static_cast<result_type>(-x);
  }//exec
};//class tag_remove_numeric_sign<true>

////////////////////////////////////////////////////////////////////////////////

template<typename FromType>
typename structure::t_numeric_limits<FromType>::unsigned_numeric_type
 remove_numeric_sign(FromType const x)
{
 using tag=tag_remove_numeric_sign<t_numeric_limits<FromType>::is_signed>;

 return tag::exec(x);
}//remove_numeric_sign

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
