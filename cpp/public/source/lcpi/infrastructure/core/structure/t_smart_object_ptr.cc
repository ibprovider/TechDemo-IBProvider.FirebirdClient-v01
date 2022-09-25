////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 17.07.2019.
#ifndef _lcpi_infrastructure_core_structure__t_smart_object_ptr_CC_
#define _lcpi_infrastructure_core_structure__t_smart_object_ptr_CC_

#include <utility>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//struct t_sptr_traits

template<class T>
inline void sobj_add_ref(T* const ptr)
{
 assert(ptr);
 ptr->add_ref();
}//sobj_add_ref

//------------------------------------------------------------------------
template<class T>
inline void sobj_release(T* const ptr)
{
 assert(ptr);
 ptr->release();
}//sobj_release

//------------------------------------------------------------------------
template<class T>
inline void sobj_add_ref(const T* const ptr)
{
 assert(ptr);
 const_cast<T*>(ptr)->add_ref();
}//sobj_add_ref

//------------------------------------------------------------------------
template<class T>
inline void sobj_release(const T* const ptr)
{
 assert(ptr);
 const_cast<T*>(ptr)->release();
}//sobj_release

//------------------------------------------------------------------------
template<class T>
inline void t_sptr_traits<T>::increment_cntRef(item_type* const ptr)
{
 assert(ptr);

 //ptr->add_ref();
 sobj_add_ref(ptr);
}//increment_cntRef

//------------------------------------------------------------------------
template<class T>
inline void t_sptr_traits<T>::decrement_cntRef(item_type* const ptr)
{
 assert(ptr);

 //ptr->release();
 sobj_release(ptr);
}//decrement_cntRef

////////////////////////////////////////////////////////////////////////////////
//class t_smart_object_ptr

template<class T,class traits_data>
t_smart_object_ptr<T,traits_data>::t_smart_object_ptr()
 :m_ptr(nullptr)
{
}

//------------------------------------------------------------------------
template<class T,class traits_data>
t_smart_object_ptr<T,traits_data>::t_smart_object_ptr(std::nullptr_t ptr)
 :m_ptr(ptr)
{
}

//------------------------------------------------------------------------
template<class T,class traits_data>
inline
t_smart_object_ptr<T,traits_data>::t_smart_object_ptr(const self_type& ptr)
 :m_ptr(ptr.ptr())
{
 if(m_ptr)
  traits_data::increment_cntRef(m_ptr);//->add_ref();
}

//------------------------------------------------------------------------------
template<class T,class traits_data>
inline
t_smart_object_ptr<T,traits_data>::t_smart_object_ptr(pointer const ptr)
 :m_ptr(ptr)
{
 if(m_ptr)
  traits_data::increment_cntRef(m_ptr);//->add_ref();
}

//------------------------------------------------------------------------------
template<class T,class traits_data>
template<class U>
inline
t_smart_object_ptr<T,traits_data>::t_smart_object_ptr(const t_not_null_ptr<U>& nn_ptr)
 :m_ptr(nn_ptr)
{
 assert(m_ptr);

 traits_data::increment_cntRef(m_ptr);//->add_ref();
}

//------------------------------------------------------------------------------
template<class T,class traits_data>
template<class U>
inline
 t_smart_object_ptr<T,traits_data>::t_smart_object_ptr(const t_smart_object_ptr<U>& ptr)
  :m_ptr(ptr.ptr())
{
 if(m_ptr)
  traits_data::increment_cntRef(m_ptr);//->add_ref();
}

//------------------------------------------------------------------------------
template<class T,class traits_data>
inline
 t_smart_object_ptr<T,traits_data>::t_smart_object_ptr(self_type&& ptr)
  :m_ptr(std::move(ptr.m_ptr))
{
 ptr.m_ptr=nullptr;
}//t_smart_object_ptr - move constructor

//------------------------------------------------------------------------------
template<class T,class traits_data>
inline t_smart_object_ptr<T,traits_data>::~t_smart_object_ptr()
{
 this->Release();
}//~t_smart_object_ptr

//------------------------------------------------------------------------------
template<class T,class traits_data>
t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::set(std::nullptr_t const /*ptr*/)
{
 return this->Release();
}//set

//------------------------------------------------------------------------------
template<class T,class traits_data>
t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::set(pointer const ptr)
{
 //note. this->set(NULL) is equal to this->Release()

 internal_pointer const old_ptr(std::move(m_ptr));

 m_ptr=ptr;

 if(m_ptr)
  traits_data::increment_cntRef(m_ptr);//->add_ref();

 if(old_ptr)
  traits_data::decrement_cntRef(old_ptr);//->release();

 return *this;
}//set

//------------------------------------------------------------------------------
template<class T,class traits_data>
template<class U>
t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::set(const structure::t_not_null_ptr<U>& nn_ptr)
{
 //note. this->set(NULL) is equal to this->Release()

 internal_pointer const old_ptr(__STL_MOVE_VALUE(m_ptr));

 m_ptr=nn_ptr;

 assert(m_ptr);

 traits_data::increment_cntRef(m_ptr);//->add_ref();

 if(old_ptr)
  traits_data::decrement_cntRef(old_ptr);//->release();

 return *this;
}//set

//------------------------------------------------------------------------
#if 0 //24.09.2006
template<class T,class traits_data>
inline t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::set(const self_type& ptr)
{
 return this->set(ptr.ptr());
}//set
#endif

//------------------------------------------------------------------------
template<class T,class traits_data>
t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::Release()
{
 if(m_ptr)
 {
  internal_pointer const old_ptr(__STL_MOVE_VALUE(m_ptr));

  m_ptr=nullptr;

  traits_data::decrement_cntRef(old_ptr);//->release();
 }//if

 return *this;
}//Release

//------------------------------------------------------------------------
template<class T,class traits_data>
inline t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::operator = (std::nullptr_t const ptr)
{
 return this->set(ptr);                           // assign operator
}//operator =

//------------------------------------------------------------------------
template<class T,class traits_data>
inline t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::operator = (pointer const ptr)
{
 return this->set(ptr);                           // assign operator
}//operator =

//------------------------------------------------------------------------
template<class T,class traits_data>
template<class U>
inline t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::operator = (const structure::t_not_null_ptr<U>& nn_ptr)
{
 return this->set(nn_ptr);                        // assign operator
}//operator =

//------------------------------------------------------------------------
template<class T,class traits_data>
inline t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::operator = (const self_type& ptr)
{
 return this->set(ptr.ptr());                     // copy operator
}//operator =

//------------------------------------------------------------------------
template<class T,class traits_data>
template<class U>
inline t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::operator = (const t_smart_object_ptr <U>& ptr)
{
 return this->set(ptr.ptr());
}//operator =

//------------------------------------------------------------------------
template<class T,class traits_data>
t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::operator = (self_type&& ptr)
{
 if(this==&ptr)
  return *this;

 this->swap(ptr);

 ptr.Release();

 return *this;
}//operator =                                      //move operator

//------------------------------------------------------------------------
template<class T,class traits_data>
inline t_smart_object_ptr<T,traits_data>&
 t_smart_object_ptr<T,traits_data>::swap(self_type& ptr)
{
 std::swap(m_ptr,ptr.m_ptr);

 return *this;
}//swap

//------------------------------------------------------------------------
template<class T,class traits_data>
inline typename t_smart_object_ptr<T,traits_data>::internal_pointer
 t_smart_object_ptr<T,traits_data>::detach()
{
 internal_pointer tmp=internal_pointer();

 std::swap(tmp,m_ptr);

 assert(!m_ptr);

 return tmp;
}//detach

//------------------------------------------------------------------------
template<class T,class traits_data>
inline typename t_smart_object_ptr<T,traits_data>::internal_pointer&
 t_smart_object_ptr<T,traits_data>::ref_ptr()
{
 this->Release();

 assert(!m_ptr);

 return m_ptr;
}//ref_ptr

//selectors --------------------------------------------------------------
template<class T,class traits_data>
inline typename t_smart_object_ptr<T,traits_data>::pointer
 t_smart_object_ptr<T,traits_data>::ptr() const
{
 return m_ptr;
}//ptr

//------------------------------------------------------------------------
template<class T,class traits_data>
structure::t_not_null_ptr<typename t_smart_object_ptr<T,traits_data>::item_type>
 t_smart_object_ptr<T,traits_data>::not_null_ptr() const
{
 return structure::not_null_ptr(m_ptr);
}//not_null_ptr

//------------------------------------------------------------------------
template<class T,class traits_data>
inline typename t_smart_object_ptr<T,traits_data>::pointer
 t_smart_object_ptr<T,traits_data>::operator -> () const
{
 assert(m_ptr);

 return m_ptr;
}//operator ->

//------------------------------------------------------------------------
template<class T,class traits_data>
inline typename t_smart_object_ptr<T,traits_data>::reference
 t_smart_object_ptr<T,traits_data>::operator * () const
{
 assert(m_ptr);

 return *m_ptr;
}//operator *

//------------------------------------------------------------------------
template<class T,class traits_data>
inline t_smart_object_ptr<T,traits_data>::operator
 typename t_smart_object_ptr<T,traits_data>::pointer () const
{
 return m_ptr;
}

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
