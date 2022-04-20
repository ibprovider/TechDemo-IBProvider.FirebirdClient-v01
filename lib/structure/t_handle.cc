////////////////////////////////////////////////////////////////////////////////
#ifndef _t_handle_CC_
#define _t_handle_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_auto_switch

template<class TFlag,class TSetValue,class TResetValue>
t_auto_switch<TFlag,TSetValue,TResetValue>::t_auto_switch(TFlag&      flag,
                                                          TSetValue   set_value,
                                                          TResetValue reset_value)
 :m_flag(flag)
 ,m_reset_value(reset_value)
{
 m_flag=set_value;
}

//------------------------------------------------------------------------
template<class TFlag,class TSetValue,class TResetValue>
t_auto_switch<TFlag,TSetValue,TResetValue>::t_auto_switch(TFlag&    flag,
                                                          TSetValue set_value)
 :m_flag(flag)
 ,m_reset_value(flag)
{
 m_flag=set_value;
}

//------------------------------------------------------------------------
template<class TFlag,class TSetValue,class TResetValue>
inline
t_auto_switch<TFlag,TSetValue,TResetValue>::t_auto_switch(TFlag& flag)
 :m_flag(flag)
 ,m_reset_value(flag)
{;}

//------------------------------------------------------------------------
template<class TFlag,class TSetValue,class TResetValue>
t_auto_switch<TFlag,TSetValue,TResetValue>::~t_auto_switch()
{
 try
 {
  //may be it is call of operator =
  m_flag=m_reset_value;
 }
 catch(...)
  {;}
}//~t_auto_switch

//------------------------------------------------------------------------
template<class TFlag,class TSetValue,class TResetValue>
inline
TFlag& t_auto_switch<TFlag,TSetValue,TResetValue>::data()
{
 return m_flag;
}

//------------------------------------------------------------------------
template<class TFlag,class TSetValue,class TResetValue>
inline
const TResetValue& t_auto_switch<TFlag,TSetValue,TResetValue>::restored()const
{
 return m_reset_value;
}

////////////////////////////////////////////////////////////////////////////////
//class t_data_holder_ro

template<class TData,class THolderBaseClass>
inline
t_data_holder_ro<TData,THolderBaseClass>::t_data_holder_ro()
 :m_data(data_type())
{;}

//------------------------------------------------------------------------
template<class TData,class THolderBaseClass>
inline
t_data_holder_ro<TData,THolderBaseClass>::t_data_holder_ro(const data_type& x)
 :m_data(x)
{;}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)

template<class TData,class THolderBaseClass>
template<typename TA1,typename TA2>
t_data_holder_ro<TData,THolderBaseClass>::t_data_holder_ro(TA1 a1,TA2 a2)
 :m_data(a1,a2)
{;}

#endif //COMP_CONF_SUPPORT_MEMBER_TEMPLATE

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)

template<class TData,class THolderBaseClass>
template<typename TA1,typename TA2,typename TA3>
t_data_holder_ro<TData,THolderBaseClass>::t_data_holder_ro(TA1 a1,TA2 a2,TA3 a3)
 :m_data(a1,a2,a3)
{;}

#endif //COMP_CONF_SUPPORT_MEMBER_TEMPLATE

//------------------------------------------------------------------------
template<class TData,class THolderBaseClass>
t_data_holder_ro<TData,THolderBaseClass>::~t_data_holder_ro()
{;}

//------------------------------------------------------------------------
template<class TData,class THolderBaseClass>
inline
const typename t_data_holder_ro<TData,THolderBaseClass>::data_type&
 t_data_holder_ro<TData,THolderBaseClass>::data()const
{
 return m_data;
}//data

////////////////////////////////////////////////////////////////////////////////
//class t_data_holder_rw

template<class TData,class THolderBaseClass>
inline
t_data_holder_rw<TData,THolderBaseClass>::t_data_holder_rw()
{;}

//------------------------------------------------------------------------
template<class TData,class THolderBaseClass>
inline
t_data_holder_rw<TData,THolderBaseClass>::t_data_holder_rw(const data_type& x)
 :inherited(x)
{;}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class TData,class THolderBaseClass>
template<typename TA1,typename TA2>
t_data_holder_rw<TData,THolderBaseClass>::t_data_holder_rw(TA1 a1,TA2 a2)
 :inherited(a1,a2)
{;}
#endif //COMP_CONF_SUPPORT_MEMBER_TEMPLATE

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class TData,class THolderBaseClass>
template<typename TA1,typename TA2,typename TA3>
t_data_holder_rw<TData,THolderBaseClass>::t_data_holder_rw(TA1 a1,TA2 a2,TA3 a3)
 :inherited(a1,a2,a3)
{;}
#endif //COMP_CONF_SUPPORT_MEMBER_TEMPLATE

//------------------------------------------------------------------------
template<class TData,class THolderBaseClass>
t_data_holder_rw<TData,THolderBaseClass>::~t_data_holder_rw()
{;}

//------------------------------------------------------------------------
template<class TData,class THolderBaseClass>
inline
typename t_data_holder_rw<TData,THolderBaseClass>::data_type&
 t_data_holder_rw<TData,THolderBaseClass>::data()
{
 return self_type::m_data;
}//data

////////////////////////////////////////////////////////////////////////////////
//class t_mt_data_holder_ro

template<class TData,class THolderBaseClass,class ThreadTraits>
t_mt_data_holder_ro<TData,THolderBaseClass,ThreadTraits>::t_mt_data_holder_ro()
 :m_data(data_type())
{;}

//------------------------------------------------------------------------
template<class TData,class THolderBaseClass,class ThreadTraits>
t_mt_data_holder_ro<TData,THolderBaseClass,ThreadTraits>::t_mt_data_holder_ro
                                                           (const data_type& x)
 :m_data(x)
{;}

//------------------------------------------------------------------------
template<class TData,class THolderBaseClass,class ThreadTraits>
typename t_mt_data_holder_ro<TData,THolderBaseClass,ThreadTraits>::data_type
 t_mt_data_holder_ro<TData,THolderBaseClass,ThreadTraits>::data()const
{
 const lock_guard_type __lock(m_guard);

 return m_data;
}//data

////////////////////////////////////////////////////////////////////////////////
//class t_mt_data_holder_rw

template<class TData,class THolderBaseClass,class ThreadTraits>
inline
t_mt_data_holder_rw<TData,THolderBaseClass,ThreadTraits>::t_mt_data_holder_rw()
 :inherited()
{;}

//------------------------------------------------------------------------
template<class TData,class THolderBaseClass,class ThreadTraits>
inline
t_mt_data_holder_rw<TData,THolderBaseClass,ThreadTraits>::t_mt_data_holder_rw
                                                           (const data_type& x)
 :inherited(x)
{;}

//------------------------------------------------------------------------
template<class TData,class THolderBaseClass,class ThreadTraits>
t_mt_data_holder_rw<TData,THolderBaseClass,ThreadTraits>&
 t_mt_data_holder_rw<TData,THolderBaseClass,ThreadTraits>::operator = (const data_type& x)
{
 const lock_guard_type __lock(self_type::m_guard);

 self_type::m_data=x;

 return *this;
}//operator =

////////////////////////////////////////////////////////////////////////////////
//template class t_counter_inc_dec

template<class ThreadTraits>
RELEASE_CODE(inline)
t_counter_inc_dec<ThreadTraits>::t_counter_inc_dec(value_type& counter)
 :m_counter(&counter)
{
 assert(m_counter);

 thread_traits::increment(m_counter);
}//t_counter_inc_dec

//------------------------------------------------------------------------
template<class ThreadTraits>
RELEASE_CODE(inline)
t_counter_inc_dec<ThreadTraits>::t_counter_inc_dec(value_type&       counter,
                                                   value_type  const init_value)
 :m_counter(&counter)
{
 assert(m_counter);

 thread_traits::exchange(m_counter,init_value);
}//t_counter_inc_dec

//------------------------------------------------------------------------
template<class ThreadTraits>
RELEASE_CODE(inline)
t_counter_inc_dec<ThreadTraits>::~t_counter_inc_dec()
{
 assert(m_counter);

 thread_traits::decrement(m_counter);

 m_counter=NULL;
}//~t_counter_inc_dec

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif