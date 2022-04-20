////////////////////////////////////////////////////////////////////////////////
#ifndef _t_value_with_null_CC_
#define _t_value_with_null_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_value_with_null

template<class T>
t_value_with_null<T>::t_value_with_null()
 :m_value(value_type())
 ,m_null(true)
{
}

//------------------------------------------------------------------------
template<class T>
inline t_value_with_null<T>::t_value_with_null(const self_type& x)
 :m_value(x.m_value)
 ,m_null(x.m_null)
{
}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class T>
inline t_value_with_null<T>::t_value_with_null(self_type&& x)
 :m_value (__STL_MOVE_VALUE(x.m_value))
 ,m_null  (__STL_MOVE_VALUE(x.m_null))
{
 x.reset();
}//move constructor

#endif // COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)

template<class T>
template<class U>
inline t_value_with_null<T>::t_value_with_null(const U& x)
 :m_value(x)
 ,m_null(false)
{
}

#else

template<class T>
inline t_value_with_null<T>::t_value_with_null(const value_type& x)
 :m_value(x)
 ,m_null(false)
{
}

#endif //COMP_CONF_SUPPORT_MEMBER_TEMPLATE

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class T>
inline t_value_with_null<T>::t_value_with_null(value_type&& x)
 :m_value(__STL_FORWARD_VALUE(value_type,x))
 ,m_null(false)
{
}

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class T>
inline t_value_with_null<T>::~t_value_with_null()
{
}

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
const typename t_value_with_null<T>::value_type&
 t_value_with_null<T>::value_or_default(const value_type& default_value)const
{
 return m_null?default_value:m_value;
}//value_or_default

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
const typename t_value_with_null<T>::value_type&
 t_value_with_null<T>::value() const
{
 assert(!m_null);

 return m_value;
}//value - const

//------------------------------------------------------------------------
template<class T>
RELEASE_CODE(inline)
typename t_value_with_null<T>::value_type&
 t_value_with_null<T>::value()
{
 assert(!m_null);

 return m_value;
}//value

//assign operators -------------------------------------------------------
template<class T>
inline t_value_with_null<T>& t_value_with_null<T>::operator = (const self_type& x)
{
 this->m_value=x.m_value;
 this->m_null =x.m_null;

 return *this;
}//operator = self_type

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class T>
inline t_value_with_null<T>& t_value_with_null<T>::operator = (self_type&& x)
{
 if(&x!=this)
 {
  this->m_value =__STL_MOVE_VALUE(x.m_value);
  this->m_null  =__STL_MOVE_VALUE(x.m_null);

  x.reset();
 }//if &x!=this

 return *this;
}//operator = self_type&&

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class T>
template<class U>
inline t_value_with_null<T>& t_value_with_null<T>::operator = (const U& x)
#else
template<class T>
inline t_value_with_null<T>& t_value_with_null<T>::operator = (const value_type& x)
#endif
{
 return this->set(x);
}//operator = generic_type / value_type

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
template<class T>
inline t_value_with_null<T>& t_value_with_null<T>::operator = (value_type&& x)
{
 typedef value_type x_type;

 return this->set(__STL_FORWARD_VALUE(x_type,x));
}//operator = generic_type / value_type
#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class T>
template<class U>
inline t_value_with_null<T>& t_value_with_null<T>::set(const U& x)
#else
template<class T>
inline t_value_with_null<T>& t_value_with_null<T>::set(const value_type& x)
#endif
{
 this->m_value=x;
 this->m_null =false;

 return *this;
}//set generic_type / value_type

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
template<class T>
inline t_value_with_null<T>& t_value_with_null<T>::set(value_type&& x)
{
 typedef value_type x_type;

 this->m_value=__STL_FORWARD_VALUE(x_type,x);
 this->m_null =false;

 return *this;
}//set [move version]
#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class T>
inline t_value_with_null<T>& t_value_with_null<T>::set_t(const value_type& x)
{
 return this->set(x);
}//set_t

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
template<class T>
inline t_value_with_null<T>& t_value_with_null<T>::set_t(value_type&& x)
{
 typedef value_type x_type;

 return this->set(__STL_FORWARD_VALUE(x_type,x));
}//set_t [move version]
#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class T>
template<class Iter>
inline t_value_with_null<T>& t_value_with_null<T>::assign(Iter first,Iter last)
{
 this->m_value.assign(first,last); //throw

 this->m_null =false; //no throw

 return *this;
}//assign first,last
#endif

//------------------------------------------------------------------------
template<class T>
t_value_with_null<T>& t_value_with_null<T>::reset()
{
 m_value  =value_type();
 m_null   =true;

 return *this;
}//reset

//------------------------------------------------------------------------
template<class T>
inline t_value_with_null<T>& t_value_with_null<T>::set_not_null()
{
 m_null=false;

 return *this;
}//set_not_null

//------------------------------------------------------------------------
template<class T>
t_value_with_null<T>& t_value_with_null<T>::swap(t_value_with_null<T>& x)
{
 std::swap(m_value,x.m_value);
 std::swap(m_null ,x.m_null);

 return *this;
}//swap

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class T>
template<class U>
bool t_value_with_null<T>::assign_once(const U& x)
#else
template<class T>
bool t_value_with_null<T>::assign_once(const value_type& x)
#endif
{
 if(!this->null())
  return false;

 this->set(x);

 return true;
}//assign_once generic_type / value_type

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class T>
RELEASE_CODE(inline)
bool t_value_with_null<T>::assign_once(value_type&& x)
{
 if(!this->null())
  return false;

 this->set(__STL_FORWARD_VALUE(value_type,x));

 return true;
}//assign_once [move version]

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

////////////////////////////////////////////////////////////////////////////////
//class t_value_with_null::tag_less

template<class T>
inline bool t_value_with_null<T>::tag_less::operator ()
                                   (const value_with_null_type& x1,
                                    const value_with_null_type& x2)const
{
 if(x1.null())
 {
  if(x2.null())
   return false;

  return m_null_is_less?true:false;
 }//if (x1 is null)

 if(x2.null())
  return m_null_is_less?false:true;

 return x1.value()<x2.value();
}//tag_less::operator ()

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
