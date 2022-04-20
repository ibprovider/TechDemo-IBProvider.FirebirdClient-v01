////////////////////////////////////////////////////////////////////////////////
//Base classes for resource managements.
//                                                   Dmitry Kovalenko. 98 year.
#ifndef _t_handle_H_
#define _t_handle_H_

#include <structure/t_smart_object.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup lib_structure
//! @{
////////////////////////////////////////////////////////////////////////////////
//containing classes

//Handling of description with explicit referencing count
//Counter is not checked
template<class T,
         class tag_thread_traits=t_def_thread_traits>
class t_handle_counter;

//auto set and reset of flag
template<class TFlag,class TSetValue,class TResetValue>
class t_auto_switch;

//construct of read-only data holder
template<class TData,class THolderBaseClass>
class t_data_holder_ro;

//construct of read-write data holder (inherites a t_data_holder_ro)
template<class TData,class THolderBaseClass>
class t_data_holder_rw;

//construct thread-safe read-only data holder
template<class TData,class THolderBaseClass,class ThreadTraits=t_multi_thread_traits>
class t_mt_data_holder_ro;

//construct thread-safe read-write data holder
template<class TData,class THolderBaseClass,class ThreadTraits=t_multi_thread_traits>
class t_mt_data_holder_rw;

//counter increment-decrement
template<class ThreadTraits>
class t_counter_inc_dec;

////////////////////////////////////////////////////////////////////////////////
//class t_handle_counter

template<class T,class tag_thread_traits>
class t_handle_counter
{
 private:
  typedef t_handle_counter<T,tag_thread_traits>        self_type;

 public: //typedefs ------------------------------------------------------
  typedef T                                            value_type;
  typedef tag_thread_traits                            thread_traits;
  typedef typename thread_traits::int_type             counter_type;

  enum
  {
   initial_counter_value=1
  };

 public:
  value_type   m_Data;
  counter_type m_cntRef;

 public:
  t_handle_counter()
   :m_cntRef(0)
   ,m_Data()
  {;}

  t_handle_counter(const self_type& x)
   :m_cntRef(x.m_cntRef)
   ,m_Data(x.m_Data)
  {;}

  t_handle_counter(const value_type& Data)
   :m_cntRef(initial_counter_value)
   ,m_Data(Data)
  {;}

 self_type& operator = (const self_type& x)
  {
   m_Data   =x.m_Data;
   m_cntRef =x.m_cntRef;

   return *this;
  }

 self_type& operator = (const value_type& Data)
  {
   m_Data   =Data;
   m_cntRef =initial_counter_value;

   return *this;
  }

 counter_type AddRef()
  {return thread_traits::increment(&m_cntRef);}

 counter_type Release()
  {return (m_cntRef<=0)?0:thread_traits::decrement(&m_cntRef);}

 counter_type GetCntRef()const
  {return m_cntRef;}
};//class t_handle_counter

////////////////////////////////////////////////////////////////////////////////
//class t_auto_switch

template<class TFlag,class TSetValue=TFlag,class TResetValue=TFlag>
class t_auto_switch
{
 private:
  typedef t_auto_switch<TFlag,TSetValue,TResetValue>              self_type;

  t_auto_switch(const self_type&);
  t_auto_switch& operator = (const self_type&);

  TFlag&            m_flag;
  const TResetValue m_reset_value;

 public:
  t_auto_switch(TFlag& flag,TSetValue set_value,TResetValue reset_value);

  t_auto_switch(TFlag& flag,TSetValue set_value);

  t_auto_switch(TFlag& flag);

 ~t_auto_switch();

  TFlag& data();

  const TResetValue& restored()const;
};//class t_auto_switch

////////////////////////////////////////////////////////////////////////////////
//class t_data_holder_ro

template<class TData,class THolderBaseClass>
class t_data_holder_ro:public THolderBaseClass
{
 private:
  friend class t_data_holder_rw<TData,THolderBaseClass>;

 private:
  typedef t_data_holder_ro<TData,THolderBaseClass>               self_type;
  typedef THolderBaseClass                                       inherited;

  t_data_holder_ro(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~t_data_holder_ro();

 public: //typedefs ------------------------------------------------------
  typedef TData                                                  data_type;

 public:
  t_data_holder_ro();

  explicit t_data_holder_ro(const data_type&);

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<typename TA1,typename TA2>
  t_data_holder_ro(TA1 a1,TA2 a2);

  template<typename TA1,typename TA2,typename TA3>
  t_data_holder_ro(TA1 a1,TA2 a2,TA3 a3);
 #endif

  //selectors ------------------------------------------------------------
  const data_type& data()const;

 private:
  data_type m_data;
};//class t_data_holder_ro

////////////////////////////////////////////////////////////////////////////////
//class class t_data_holder_rw

template<class TData,class THolderBaseClass>
class t_data_holder_rw:public t_data_holder_ro<TData,THolderBaseClass>
{
 private:
  typedef t_data_holder_rw<TData,THolderBaseClass>               self_type;
  typedef t_data_holder_ro<TData,THolderBaseClass>               inherited;

  t_data_holder_rw(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~t_data_holder_rw();

 public: //typedefs ------------------------------------------------------
  typedef typename inherited::data_type                          data_type;

 public:
  t_data_holder_rw();

  explicit t_data_holder_rw(const data_type&);

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<typename TA1,typename TA2>
  t_data_holder_rw(TA1 a1,TA2 a2);

  template<typename TA1,typename TA2,typename TA3>
  t_data_holder_rw(TA1 a1,TA2 a2,TA3 a3);
 #endif

  //read-write accessor --------------------------------------------------
  data_type& data();
};//class t_data_holder_rw

////////////////////////////////////////////////////////////////////////////////
//class t_mt_data_holder_ro - construct thread-safe read-only data holder

template<class TData,class THolderBaseClass,class ThreadTraits>
class t_mt_data_holder_ro:public THolderBaseClass
{
 private:
  typedef t_mt_data_holder_ro<TData,THolderBaseClass,ThreadTraits>   self_type;
  typedef THolderBaseClass                                           inherited;

  t_mt_data_holder_ro(const self_type&);
  self_type& operator = (const self_type&);

 private:
  friend class t_mt_data_holder_rw<TData,THolderBaseClass,ThreadTraits>;

 public: //typedefs ------------------------------------------------------
  typedef TData                                                      data_type;
  typedef ThreadTraits                                               thread_traits;

  typedef typename thread_traits::guard_type                         guard_type;
  typedef typename thread_traits::lock_guard_type                    lock_guard_type;

 public:
  t_mt_data_holder_ro();

  explicit t_mt_data_holder_ro(const data_type& data);

  //selector -------------------------------------------------------------
  TData data()const;

 private:
  mutable guard_type m_guard;
  data_type          m_data;
};//class t_mt_data_holder_ro

////////////////////////////////////////////////////////////////////////////////
//class t_mt_data_holder_rw - construct thread-safe read-write data holder

template<class TData,class THolderBaseClass,class ThreadTraits>
class t_mt_data_holder_rw:public t_mt_data_holder_ro<TData,
                                                     THolderBaseClass,
                                                     ThreadTraits>
{
 private:
  typedef t_mt_data_holder_rw<TData,THolderBaseClass,ThreadTraits>   self_type;
  typedef t_mt_data_holder_ro<TData,THolderBaseClass,ThreadTraits>   inherited;

  t_mt_data_holder_rw(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef typename inherited::data_type                               data_type;
  typedef typename inherited::lock_guard_type                         lock_guard_type;

 public:
  t_mt_data_holder_rw();

  explicit t_mt_data_holder_rw(const data_type& data);

  //assign operator ------------------------------------------------------
  self_type& operator = (const data_type&);
};//class t_mt_data_holder_rw

////////////////////////////////////////////////////////////////////////////////
//template class t_counter_inc_dec

template<class ThreadTraits>
class t_counter_inc_dec
{
 private:
  typedef t_counter_inc_dec<ThreadTraits>      self_type;

  t_counter_inc_dec(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef ThreadTraits                         thread_traits;

  typedef typename thread_traits::int_type     value_type;

 public:
  /// <summary>
  ///  Constructor. Increment.
  /// </summary>
  //! \param[in,out] counter
  explicit t_counter_inc_dec(value_type& counter);

  /// <summary>
  ///  Constructor. Initialize.
  /// </summary>
  //! \param[in,out] counter
  t_counter_inc_dec(value_type& counter,value_type init_value);

  /// <summary>
  ///  Destructor. Decrement.
  /// </summary>
 ~t_counter_inc_dec();

 private:
  value_type* m_counter;
};//class t_counter_inc_dec

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_handle.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
