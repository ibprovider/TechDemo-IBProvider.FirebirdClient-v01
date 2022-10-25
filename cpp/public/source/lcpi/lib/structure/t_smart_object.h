////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 23.04.2020.
#ifndef _cpp_public_lcpi_lib_structure__t_smart_object_H_
#define _cpp_public_lcpi_lib_structure__t_smart_object_H_

#include <lcpi/lib/structure/t_smart_interface.h>
#include <lcpi/lib/structure/cnt_ref_traits.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class TSmartInterface>
class t_basic_smart_interface_impl__static_v2;

template<class TSmartInterface,class Allocator>
class t_basic_smart_interface_impl__dynamic;

//------------------------------------------------------------------------
class t_nondelegating_smart_interface;

template<class Allocator>
class t_basic_smart_object_base2;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_smart_interface_impl__static_v2

/// <summary>
///  Builder of class with smart interface for global objects.
/// </summary>
template<class TSmartInterface>
class t_basic_smart_interface_impl__static_v2:public TSmartInterface
{
 private:
  typedef t_basic_smart_interface_impl__static_v2               self_type;
  typedef TSmartInterface                                       inherited;

  t_basic_smart_interface_impl__static_v2(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef cnt_ref_traits::cnt_ref_type                          cnt_ref_type;

 public:
  template<typename... TArgs>
  t_basic_smart_interface_impl__static_v2(TArgs&&... args);

  //[2020-04-23] Was virtual
 ~t_basic_smart_interface_impl__static_v2();

  //smart interface ------------------------------------------------------
  virtual void add_ref() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
  virtual void release() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 public:
  cnt_ref_type get_cntRef()const;

 private:
  static void* operator new(size_t sz);
  //static void  operator delete(void* pv);

 private:
  cnt_ref_type m_cntRef;
};//class t_basic_smart_interface_impl__static_v2

////////////////////////////////////////////////////////////////////////////////
//class t_basic_smart_interface_impl__dynamic

/// <summary>
///  Builder of class with smart interface.
///  The automated destruction after releasing last external reference.
/// </summary>
template<class TSmartInterface,class Allocator>
class t_basic_smart_interface_impl__dynamic:public TSmartInterface
{
 private:
  typedef t_basic_smart_interface_impl__dynamic                 self_type;
  typedef TSmartInterface                                       inherited;

  t_basic_smart_interface_impl__dynamic(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef cnt_ref_traits::cnt_ref_type                          cnt_ref_type;

 public:
  template<typename... TArgs>
  t_basic_smart_interface_impl__dynamic(TArgs&&... args);

  virtual ~t_basic_smart_interface_impl__dynamic();

  //smart interface ------------------------------------------------------
  virtual void add_ref() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
  virtual void release() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 protected:
  virtual void final_release();

 public:
  cnt_ref_type get_cntRef()const;

 private:
  typedef typename Allocator::template rebind<void>::other      raw_alloc_type;

 public:
  static void* operator new (size_t sz);
  static void  operator delete (void* pv);

#ifndef NDEBUG
 protected:
  bool sobj_is_destroyed()const
  {
   return m_sobj_is_destroyed;
  }
#endif

 private:
  cnt_ref_type m_cntRef;

#ifndef NDEBUG
  bool m_sobj_is_destroyed;
#endif
};//class t_basic_smart_interface_impl__dynamic

////////////////////////////////////////////////////////////////////////////////
//class t_nondelegating_smart_interface

/// <summary>
///  Base class of nondelegating smart interface.
/// </summary>
class __declspec(novtable) t_nondelegating_smart_interface
{
 public:
  virtual void nondelegating__add_ref()=0;
  virtual void nondelegating__release()=0;
};//class t_nondelegating_smart_interface

////////////////////////////////////////////////////////////////////////////////
//class t_basic_smart_object_base2

template<class Allocator>
class t_basic_smart_object_base2:public t_nondelegating_smart_interface
{
 private:
  typedef t_basic_smart_object_base2                            self_type;

  t_basic_smart_object_base2(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef cnt_ref_traits::cnt_ref_type                          cnt_ref_type;

  typedef t_nondelegating_smart_interface                       nondelegating_smart_interface_type;
  typedef infrastructure::core::structure::t_smart_interface    smart_interface_type;

 protected:
  virtual ~t_basic_smart_object_base2();

 public:
  t_basic_smart_object_base2();

  //smart interface ------------------------------------------------------
  virtual void nondelegating__add_ref() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
  virtual void nondelegating__release() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 protected:
  virtual void final_release();

 public:
  cnt_ref_type get_cntRef()const;

  smart_interface_type* get_outer_smart()const;

 private:
  smart_interface_type* get_nondelegating();

 private:
  typedef typename Allocator::template rebind<void>::other      raw_alloc_type;

 public:
  static void* operator new (size_t sz);
  static void  operator delete (void* pv);

#ifndef NDEBUG
 protected:
  bool sobj_is_destroyed()const
  {
   return m_sobj_is_destroyed;
  }
#endif

 private:
  smart_interface_type* m_pOuterSmart;

  cnt_ref_type m_cntRef;

#ifndef NDEBUG
  bool m_sobj_is_destroyed;
#endif
};//class t_basic_smart_object_base2

////////////////////////////////////////////////////////////////////////////////

#define LCPI_CPP_LIB__REDECLARE_SMART_OBJ_MANAGEMENT_METHODS                \
 virtual void add_ref() LCPI_CPP_CFG__METHOD__OVERRIDE=0;                   \
                                                                            \
 virtual void release() LCPI_CPP_CFG__METHOD__OVERRIDE=0;

//------------------------------------------------------------------------
#define LCPI_CPP_LIB__DECLARE_SMART_OBJ_MANAGEMENT_METHODS                  \
 virtual void add_ref() LCPI_CPP_CFG__METHOD__OVERRIDE                      \
 {                                                                          \
  return this->get_outer_smart()->add_ref();                                \
 }                                                                          \
                                                                            \
 virtual void release() LCPI_CPP_CFG__METHOD__OVERRIDE                      \
 {                                                                          \
  return this->get_outer_smart()->release();                                \
 }

//------------------------------------------------------------------------
#define LCPI_CPP_LIB__DECLARE_SMART_OBJ_MANAGEMENT_METHODS__FINAL           \
 virtual void add_ref() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL                \
 {                                                                          \
  return this->get_outer_smart()->add_ref();                                \
 }                                                                          \
                                                                            \
 virtual void release() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL                \
 {                                                                          \
  return this->get_outer_smart()->release();                                \
 }

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/t_smart_object.cc>
////////////////////////////////////////////////////////////////////////////////
