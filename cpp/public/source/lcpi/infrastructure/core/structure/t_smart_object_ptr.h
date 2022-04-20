////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 17.07.2019.
#ifndef _lcpi_infrastructure_core_structure__t_smart_object_ptr_H_
#define _lcpi_infrastructure_core_structure__t_smart_object_ptr_H_

#include <lcpi/infrastructure/core/structure/t_not_null_ptr.h>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//contents

template<class T>
struct t_sptr_traits;

//smart-pointer for handle objects based on t_smart_object class
template<class T,class traits_data=t_sptr_traits<T> >
class t_smart_object_ptr;

////////////////////////////////////////////////////////////////////////////////
//struct t_sptr_traits

template<class T>
struct t_sptr_traits final
{
 public:
  typedef T           item_type;
  typedef T&          reference;
  typedef T*          pointer;
  typedef T*          internal_pointer;

 public:
  static void increment_cntRef(pointer const ptr);

  static void decrement_cntRef(pointer const ptr);
};//struct t_sptr_traits

////////////////////////////////////////////////////////////////////////////////
//class of smart pointer for t_smart_object

template<class T,class traits_data>
class t_smart_object_ptr final
{
 private:
  typedef t_smart_object_ptr<T,traits_data>            self_type;

 public: //typedef -------------------------------------------------------
  typedef traits_data                                  traits_data_type;
  typedef typename traits_data::item_type              item_type;
  typedef typename traits_data::reference              reference;
  typedef typename traits_data::pointer                pointer;
  typedef typename traits_data::internal_pointer       internal_pointer;

 public: //---------------------------------------------------------------
  t_smart_object_ptr();

  t_smart_object_ptr(std::nullptr_t ptr);

  //copy constructor
  t_smart_object_ptr(const self_type& ptr);

  template<class U>
  t_smart_object_ptr(const t_smart_object_ptr<U>& ptr);

  t_smart_object_ptr(self_type&& ptr);

  //assign constructor
  t_smart_object_ptr(pointer const ptr);

  template<class U>
  t_smart_object_ptr(const t_not_null_ptr<U>& nn_ptr);

 ~t_smart_object_ptr();

  //modificators ---------------------------------------------------------
  self_type& set(std::nullptr_t ptr);

  self_type& set(pointer const ptr);

  template<class U>
  self_type& set(const t_not_null_ptr<U>& nn_ptr);

  //24.09.2006
  //self_type& set(const self_type& ptr);

  self_type& Release();

  self_type& operator = (std::nullptr_t);

  self_type& operator = (pointer const ptr);// assign operator

  template<class U>
  self_type& operator = (const t_not_null_ptr<U>& nn_ptr);

  self_type& operator = (const self_type& ptr);// copy operator

  template<class U>
  self_type& operator = (const t_smart_object_ptr<U>& ptr);

  self_type& operator = (self_type&& ptr);

  self_type& swap(self_type& ptr);

  internal_pointer detach();

 public: //selectors -----------------------------------------------------
  pointer ptr() const;

  structure::t_not_null_ptr<item_type> not_null_ptr() const;

  pointer operator -> () const;

  reference operator * () const;

  operator pointer () const;

 private:
  internal_pointer m_ptr;
};//class t_smart_object_ptr

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
//STL specialization

namespace std{
////////////////////////////////////////////////////////////////////////////////

template<class T,class traits_data>
void swap(lcpi::infrastructure::core::structure::t_smart_object_ptr<T,traits_data>& x1,
          lcpi::infrastructure::core::structure::t_smart_object_ptr<T,traits_data>& x2)
{
 x1.swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/infrastructure/core/structure/t_smart_object_ptr.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
