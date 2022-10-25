////////////////////////////////////////////////////////////////////////////////
//! \ingroup ole_lib
//! \file    ole_ptr.h
//! \brief   The smart pointers and the utilities for work with the COM objects
//! \author  Kovalenko Dmitry
//! \date    1998
#ifndef _ole_ptr_H_
#define _ole_ptr_H_

#include <lcpi/lib/com/base/com_base__ptr.h>

#include <structure/stl/t_stl_vector.h>
#include <structure/t_memory.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////

using namespace lcpi::lib::com::base;

////////////////////////////////////////////////////////////////////////////////
//struct TEnumIPtr2Traits

template<class TEnumItemInterface,class Allocator=structure::t_void_allocator>
struct TEnumIPtr2Traits
{
 public: //typedefs
  typedef TEnumItemInterface*                             ole_item_type;

  typedef IPtr2<TEnumItemInterface>                       user_item_type;

  typedef structure::t_stl_vector
           <user_item_type,
            Allocator>                                    storage_type;

  typedef typename storage_type::size_type                size_type;
  typedef typename storage_type::const_reference          const_reference;

 public:
  static void CopyInEnumerator(ole_item_type* const ppDestUnk,
                               ole_item_type  const _source);

  static size_type Size(const storage_type& storage);

  static typename const_reference Item(const storage_type& storage,
                                       size_type           Index);

  static void Reserve(storage_type& storage,
                      size_type     n);

  static void Add(storage_type& storage,
                  ole_item_type item);

#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  static void Add(storage_type&    storage,
                  user_item_type&& item);
#endif

  static void Clear(ole_item_type* const ppUnk);
};//struct TEnumIPtr2Traits

typedef TEnumIPtr2Traits<IUnknown>                     TEnumUnknownTraits;

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib

////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/ole_ptr.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
