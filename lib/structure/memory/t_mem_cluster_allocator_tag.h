////////////////////////////////////////////////////////////////////////////////
//base class of optimized cluster memory allocators
//                                          Dmitry Kovalenko. 09.04.2005 00:34
#ifndef _t_mem_cluster_allocator_tag_H_
#define _t_mem_cluster_allocator_tag_H_

#include <lcpi/lib/.config.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class tag_mem_cluster_allocator

class tag_mem_cluster_allocator
{
 public:
  tag_mem_cluster_allocator(){;}
};//class tag_mem_cluster_allocator

////////////////////////////////////////////////////////////////////////////////
//class tag_mem_cluster_allocator_mt

class tag_mem_cluster_allocator_mt:public tag_mem_cluster_allocator
{
 public:
  tag_mem_cluster_allocator_mt(){;}
};//class tag_mem_cluster_allocator_mt

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
