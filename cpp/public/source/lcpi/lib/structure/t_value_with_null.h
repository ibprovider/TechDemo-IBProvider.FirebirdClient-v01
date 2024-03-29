////////////////////////////////////////////////////////////////////////////////
//Template class for build "values with null state"
//                                                Dmitry Kovalenko. 18.06.2006.
#ifndef _cpp_public_lcpi_lib_structure__t_value_with_null_H_
#define _cpp_public_lcpi_lib_structure__t_value_with_null_H_

#include <lcpi/lib/structure/t_numeric_cast.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

#ifndef COMP_CONF_SUPPORT_MEMBER_TEMPLATE
# error "COMP_CONF_SUPPORT_MEMBER_TEMPLATE is not defined"
#endif

//------------------------------------------------------------------------
#ifndef COMP_CONF_SUPPORT_RVALUE_REFERENCE
# error "COMP_CONF_SUPPORT_RVALUE_REFERENCE is not defined"
#endif

////////////////////////////////////////////////////////////////////////////////
//content

template<class T>
class t_value_with_null;

////////////////////////////////////////////////////////////////////////////////
//class t_value_with_null

template<class T>
class t_value_with_null LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_value_with_null<T>;

 public: //typedefs ------------------------------------------------------
  using value_type=T;

  class tag_less LCPI_CPP_CFG__CLASS__FINAL
  {
   public:
    tag_less(bool null_is_less)
     :m_null_is_less(null_is_less)
    {
    }

    bool operator () (const t_value_with_null<T>& x1,
                      const t_value_with_null<T>& x2)const;

   private:
    bool m_null_is_less;
  };//class tag_less

 public:
  t_value_with_null();

  t_value_with_null(const self_type&);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_value_with_null(self_type&&);
 #endif

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  explicit t_value_with_null(const U& x);
 #else
  explicit t_value_with_null(const value_type& x);
 #endif

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  explicit t_value_with_null(value_type&& x);
 #endif

 ~t_value_with_null();

  //selectors ------------------------------------------------------------
  bool null() const
   {return m_null;}

  const value_type& value_or_default(const value_type& default_value)const;

  const value_type& value() const;

  value_type& value();

  //assign operators -----------------------------------------------------
  self_type& operator = (const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (self_type&& x);
 #endif

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  self_type& operator = (const U& x);
 #else
  self_type& operator = (const value_type& x);
 #endif

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (value_type&& x);
 #endif

  //----------------------------------------
  self_type& set(const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& set(self_type&& x);
 #endif

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  self_type& set(const U& x);
 #else
  self_type& set(const value_type& x);
 #endif

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& set(value_type&& x);
 #endif

  self_type& set_t(const value_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& set_t(value_type&& x);
 #endif

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class Iter>
  self_type& assign(Iter first,Iter last);
 #endif

  //----------------------------------------------------------------------
  self_type& reset();

  self_type& set_not_null();

  self_type& swap(self_type& x);

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  bool assign_once(const U& x);
 #else
  bool assign_once(const value_type& x);
 #endif

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  bool assign_once(value_type&& x);
 #endif

 private:
  value_type m_value;
  bool       m_null;
};//class t_value_with_null

////////////////////////////////////////////////////////////////////////////////
//non-members operators

template<class T>
inline bool operator == (const t_value_with_null<T>& x1,
                         const t_value_with_null<T>& x2)
{
 if(x1.null())
  return x2.null();

 if(x2.null())
  return false;

 return x1.value()==x2.value();
}//operator ==

//------------------------------------------------------------------------
template<class T>
inline bool operator != (const t_value_with_null<T>& x1,
                         const t_value_with_null<T>& x2)
{
 return !(x1==x2);
}//operator !=

//------------------------------------------------------------------------
template<class T>
inline bool operator == (const t_value_with_null<T>& x,const T& v)
{
 return !x.null() && x.value()==v;
}//operator ==

//------------------------------------------------------------------------
template<class T>
inline bool operator == (const T& v,const t_value_with_null<T>& x)
{
 return (x==v);
}//operator ==

//------------------------------------------------------------------------
template<class T>
inline bool operator != (const t_value_with_null<T>& x,const T& v)
{
 return !(x==v);
}//operator !=

//------------------------------------------------------------------------
template<class T>
inline bool operator != (const T& v,const t_value_with_null<T>& x)
{
 return !(x==v);
}//operator !=

////////////////////////////////////////////////////////////////////////////////

template<typename ToBaseType,typename FromType>
LCPI__RELEASE_CODE(inline)
bool can_numeric_cast(t_value_with_null<ToBaseType>*,FromType x)
{
 return can_numeric_cast<ToBaseType>(x);
}//can_numeric_cast

//------------------------------------------------------------------------
template<typename ToBaseType,typename FromType>
LCPI__RELEASE_CODE(inline)
void static_numeric_cast(t_value_with_null<ToBaseType>* pdest,FromType x)
{
 assert(pdest);

 (*pdest)=static_numeric_cast<ToBaseType,FromType>(x);
}//can_numeric_cast

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/

namespace std{
////////////////////////////////////////////////////////////////////////////////

template<class T>
void swap(::lcpi::lib::structure::t_value_with_null<T>& x1,::lcpi::lib::structure::t_value_with_null<T>& x2)
{
 x1.swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//std

////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/t_value_with_null.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
