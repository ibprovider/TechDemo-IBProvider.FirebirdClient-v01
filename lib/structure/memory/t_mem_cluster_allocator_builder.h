////////////////////////////////////////////////////////////////////////////////
//Конструкция для конструирования менеджера кластерного распредления памяти
//                                                Kovalenko Dmitry. 20.06.2007
#ifndef _t_mem_cluster_allocator_builder_H_
#define _t_mem_cluster_allocator_builder_H_

#include <structure/memory/t_mem_cluster_allocator.h>
#include <structure/t_meta_prog.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<class T,class Allocator>
class t_mem_cluster_allocator_builder
{
 private:
  typedef t_mp_select
   <(t_mp_is_supersubclass<tag_mem_cluster_allocator,Allocator>::result),
     Allocator,
     t_mem_cluster_allocator<T,Allocator> >                  alloc_selector;

  typedef typename alloc_selector::result                    result;

 public:
  typedef typename result::template rebind<T>::other         allocator_type;
};//class t_mem_cluster_allocator_builder

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif