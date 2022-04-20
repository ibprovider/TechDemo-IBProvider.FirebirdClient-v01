////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 23.04.2020.
#ifndef _cpp_public_lcpi_lib_structure__t_smart_object_CC_
#define _cpp_public_lcpi_lib_structure__t_smart_object_CC_

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_smart_interface_impl__static_v2

template<class TSmartInterface>
template<typename... TArgs>
t_basic_smart_interface_impl__static_v2<TSmartInterface>::t_basic_smart_interface_impl__static_v2(TArgs&&... args)
 :inherited(std::forward<TArgs>(args)...)
 ,m_cntRef(0)
{
}//t_basic_smart_interface_impl__static_v2

//------------------------------------------------------------------------
template<class TSmartInterface>
t_basic_smart_interface_impl__static_v2<TSmartInterface>::~t_basic_smart_interface_impl__static_v2()
{
 assert(m_cntRef==0);
}//~t_basic_smart_interface_impl__static_v2

//------------------------------------------------------------------------
template<class TSmartInterface>
void t_basic_smart_interface_impl__static_v2<TSmartInterface>::add_ref()
{
 cnt_ref_traits::increment(&m_cntRef);
}//add_ref

//------------------------------------------------------------------------
template<class TSmartInterface>
void t_basic_smart_interface_impl__static_v2<TSmartInterface>::release()
{
 cnt_ref_traits::decrement(&m_cntRef);
}//release

//------------------------------------------------------------------------
template<class TSmartInterface>
inline
typename t_basic_smart_interface_impl__static_v2<TSmartInterface>::cnt_ref_type
 t_basic_smart_interface_impl__static_v2<TSmartInterface>::get_cntRef()const
{
 return m_cntRef;
}//get_cntRef

////////////////////////////////////////////////////////////////////////////////
//class t_basic_smart_interface_impl__dynamic

template<class TSmartInterface,class Allocator>
template<typename... TArgs>
t_basic_smart_interface_impl__dynamic<TSmartInterface,Allocator>::t_basic_smart_interface_impl__dynamic(TArgs&&... args)
 :inherited(std::forward<TArgs>(args)...)
 ,m_cntRef(0)
{
#ifndef NDEBUG
 m_sobj_is_destroyed=false;
#endif
}//t_basic_smart_interface_impl__dynamic

//------------------------------------------------------------------------
template<class TSmartInterface,class Allocator>
t_basic_smart_interface_impl__dynamic<TSmartInterface,Allocator>::~t_basic_smart_interface_impl__dynamic()
{
 assert(m_cntRef==0);
}//~t_basic_smart_interface_impl__dynamic

//------------------------------------------------------------------------
template<class TSmartInterface,class Allocator>
void t_basic_smart_interface_impl__dynamic<TSmartInterface,Allocator>::add_ref()
{
 assert(!this->sobj_is_destroyed());

 cnt_ref_traits::increment(&m_cntRef);
}//add_ref

//------------------------------------------------------------------------
template<class TSmartInterface,class Allocator>
void t_basic_smart_interface_impl__dynamic<TSmartInterface,Allocator>::release()
{
 assert(!this->sobj_is_destroyed());

 if(cnt_ref_traits::decrement(&m_cntRef))
  return;

 assert(m_cntRef==0);

 try
 {
  this->final_release();
 }
 catch(...)
 {
  assert(false);
 }//catch

 assert(m_cntRef==0);

#ifndef NDEBUG
 m_sobj_is_destroyed=true;
#endif

 delete this;

 return;
}//release

//------------------------------------------------------------------------
template<class TSmartInterface,class Allocator>
void t_basic_smart_interface_impl__dynamic<TSmartInterface,Allocator>::final_release()
{
}//final_release

//------------------------------------------------------------------------
template<class TSmartInterface,class Allocator>
inline
typename t_basic_smart_interface_impl__dynamic<TSmartInterface,Allocator>::cnt_ref_type
 t_basic_smart_interface_impl__dynamic<TSmartInterface,Allocator>::get_cntRef()const
{
 return m_cntRef;
}//get_cntRef

//------------------------------------------------------------------------
template<class TSmartInterface,class Allocator>
inline
 void* t_basic_smart_interface_impl__dynamic<TSmartInterface,Allocator>
                          ::operator new (size_t const sz)
{
 return raw_alloc_type::instance.allocate(sz);
}//operator new

//------------------------------------------------------------------------
template<class TSmartInterface,class Allocator>
inline
 void t_basic_smart_interface_impl__dynamic<TSmartInterface,Allocator>
                         ::operator delete (void* const pv)
{
 raw_alloc_type::instance.deallocate(pv,0);
}//operator delete

////////////////////////////////////////////////////////////////////////////////
//class t_basic_smart_object_base2

#if defined(_MSC_VER)
# pragma warning (push)
# pragma warning (disable:4355)
#endif

//------------------------------------------------------------------------
template<class Allocator>
t_basic_smart_object_base2<Allocator>::t_basic_smart_object_base2()
 :m_pOuterSmart(this->get_nondelegating())
 ,m_cntRef(0)
{
#ifndef NDEBUG
 m_sobj_is_destroyed=false;
#endif

 //---
 assert(m_pOuterSmart);
}//t_basic_smart_object_base2

//------------------------------------------------------------------------
#if defined(_MSC_VER)
# pragma warning (pop)
#endif

//------------------------------------------------------------------------
template<class Allocator>
t_basic_smart_object_base2<Allocator>::~t_basic_smart_object_base2()
{
 assert(m_cntRef==0);
}//~t_basic_smart_object_base2

//------------------------------------------------------------------------
template<class Allocator>
void t_basic_smart_object_base2<Allocator>::nondelegating__add_ref()
{
 assert(!this->sobj_is_destroyed());

 cnt_ref_traits::increment(&m_cntRef);
}//nondelegating__add_ref

//------------------------------------------------------------------------
template<class Allocator>
void t_basic_smart_object_base2<Allocator>::nondelegating__release()
{
 assert(!this->sobj_is_destroyed());

 if(cnt_ref_traits::decrement(&m_cntRef))
  return;

 assert(m_cntRef==0);

 try
 {
  this->final_release();
 }
 catch(...)
 {
  assert(false);
 }

 assert(m_cntRef==0);

#ifndef NDEBUG
 m_sobj_is_destroyed=true;
#endif

 delete this;

 return;
}//nondelegating__release

//------------------------------------------------------------------------
template<class Allocator>
void t_basic_smart_object_base2<Allocator>::final_release()
{
}//final_release

//------------------------------------------------------------------------
template<class Allocator>
inline
typename t_basic_smart_object_base2<Allocator>::cnt_ref_type
 t_basic_smart_object_base2<Allocator>::get_cntRef()const
{
 return m_cntRef;
}//get_cntRef

//------------------------------------------------------------------------
template<class Allocator>
inline
typename t_basic_smart_object_base2<Allocator>::smart_interface_type*
 t_basic_smart_object_base2<Allocator>::get_outer_smart()const
{
 assert(m_pOuterSmart);

 return m_pOuterSmart;
}//get_outer_smart

//------------------------------------------------------------------------
template<class Allocator>
inline
typename t_basic_smart_object_base2<Allocator>::smart_interface_type*
 t_basic_smart_object_base2<Allocator>::get_nondelegating()
{
 return reinterpret_cast<smart_interface_type*>(static_cast<nondelegating_smart_interface_type*>(this));
}//get_nondelegating

//------------------------------------------------------------------------
template<class Allocator>
inline
 void* t_basic_smart_object_base2<Allocator>::operator new (size_t const sz)
{
 return raw_alloc_type::instance.allocate(sz);
}//operator new

//------------------------------------------------------------------------
template<class Allocator>
inline
 void t_basic_smart_object_base2<Allocator>::operator delete (void* const pv)
{
 raw_alloc_type::instance.deallocate(pv,0);
}//operator delete

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
