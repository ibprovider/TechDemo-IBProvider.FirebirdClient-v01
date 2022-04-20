////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class IBP_MemoryWithDebugChecks::tag_debug_data

#ifndef NDEBUG

class IBP_MemoryWithDebugChecks::tag_debug_data
{
 public:
  static const size_t c_guard_block_size    =1024;
  static const size_t c_align_size          =32;

  static const unsigned char c_guard_byte1  =0xED;
  static const unsigned char c_guard_byte2  =0xDE;

  static const unsigned char c_init_byte    =0xCB;
  static const unsigned char c_align_byte   =0xBC;

  static const GUID c_block1_sign;
  static const GUID c_block2_sign;

 public:
  struct tag_guard_block
  {
   GUID   sign;
   size_t total_size;
   size_t user_size;
  };//struct tag_guard_block
};//class IBP_MemoryWithDebugChecks::tag_debug_data

//------------------------------------------------------------------------
const GUID IBP_MemoryWithDebugChecks::tag_debug_data::c_block1_sign=
 {0x77374134,0x56A6,0x47FB,{0xA2,0x62,0x3D,0xF8,0xBF,0x92,0x19,0xC4}};

const GUID IBP_MemoryWithDebugChecks::tag_debug_data::c_block2_sign=
 {0x9E6ABE1C,0xE954,0x4008,{0xB9,0x53,0xA6,0x3F,0x43,0xE7,0xC3,0x75}};

#endif // !NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class IBP_MemoryWithDebugChecks

#ifdef NDEBUG

void* IBP_MemoryWithDebugChecks::Alloc(size_t const sz)
{
 return self_type::Helper__AllocMemory(sz);
}//Alloc

//------------------------------------------------------------------------
void IBP_MemoryWithDebugChecks::Free(void* const pv)
{
 return self_type::Helper__FreeMemory(pv);
}//Free

#else

//------------------------------------------------------------------------
void* IBP_MemoryWithDebugChecks::Alloc(size_t const sz)
{
 assert_s(sizeof(tag_debug_data::tag_guard_block)<tag_debug_data::c_guard_block_size);

 if(sz==0)
  return NULL;

 size_t n1=0;

 //смещение первого сторожевого блока
 const size_t offset__guard1=n1;

 if(!structure::append_memory_size(n1,tag_debug_data::c_guard_block_size))
  return NULL;

 //смещение блока с пользовательскими данными
 const size_t offset__user_data=n1;

 if(!structure::append_memory_size(n1,sz))
  return NULL;

 //смещение выравнивающего блока
 const size_t offset__align=n1;

 if(!structure::align_memory_size(n1,tag_debug_data::c_align_size))
  return NULL;

 //смещение второго сторожевого блока
 const size_t offset__guard2=n1;

 if(!structure::append_memory_size(n1,tag_debug_data::c_guard_block_size))
  return NULL;

 unsigned char* const pBlock=reinterpret_cast<unsigned char*>(self_type::Helper__AllocMemory(n1));

 if(pBlock == NULL)
  return NULL;

 //----------------------------------------- инициализация
 unsigned char* ptr=pBlock+offset__guard1;

 {
  tag_debug_data::tag_guard_block* const pGuardBlock1
   =reinterpret_cast<tag_debug_data::tag_guard_block*>(ptr);

  pGuardBlock1->sign      =tag_debug_data::c_block1_sign;
  pGuardBlock1->total_size=n1;
  pGuardBlock1->user_size =sz;
 }//if

 ptr+=sizeof(tag_debug_data::tag_guard_block);

 std::fill
  (ptr,
   pBlock+offset__user_data,
   tag_debug_data::c_guard_byte1);

 //-----------------------------------------
 ptr=pBlock+offset__user_data;

 std::fill
  (ptr,
   pBlock+offset__align,
   tag_debug_data::c_init_byte);

 //-----------------------------------------
 ptr=pBlock+offset__align;

 std::fill
  (ptr,
   pBlock+offset__guard2,
   tag_debug_data::c_align_byte);

 //-----------------------------------------
 ptr=pBlock+offset__guard2;

 {
  tag_debug_data::tag_guard_block* const pGuardBlock2
   =reinterpret_cast<tag_debug_data::tag_guard_block*>(ptr);

  pGuardBlock2->sign      =tag_debug_data::c_block2_sign;
  pGuardBlock2->total_size=n1;
  pGuardBlock2->user_size =sz;
 }

 ptr+=sizeof(tag_debug_data::tag_guard_block);

 std::fill
  (ptr,
   pBlock+n1,
   tag_debug_data::c_guard_byte2);

 //-----------------------------------------
 return pBlock+offset__user_data;
}//Alloc

//------------------------------------------------------------------------
void IBP_MemoryWithDebugChecks::Free(void* const pv)
{
 if(pv==NULL)
  return;

 //-----------------------------------------
 const unsigned char*
  const pUserBlock=reinterpret_cast<const unsigned char*>(pv);

 assert(tag_debug_data::c_guard_block_size<=(size_t)(pv));

 const unsigned char*
  const pBlock=(pUserBlock-tag_debug_data::c_guard_block_size);

 //-----------------------------------------
 const tag_debug_data::tag_guard_block*
  const pGuardBlock1=reinterpret_cast<const tag_debug_data::tag_guard_block*>(pBlock);

 assert(IsEqualGUID(pGuardBlock1->sign,tag_debug_data::c_block1_sign));

 assert(pGuardBlock1->user_size<pGuardBlock1->total_size);
 assert((2*tag_debug_data::c_guard_block_size)<=(pGuardBlock1->total_size-pGuardBlock1->user_size));

 //-----------------------------------------
 for(size_t i=sizeof(tag_debug_data::tag_guard_block);i!=tag_debug_data::c_guard_block_size;++i)
 {
  assert(pBlock[i]==tag_debug_data::c_guard_byte1);
 }//for

 //-----------------------------------------
 size_t n1=tag_debug_data::c_guard_block_size;

 _VERIFY(structure::append_memory_size(n1,pGuardBlock1->user_size));

 const size_t offset__align=n1;

 _VERIFY(structure::align_memory_size(n1,tag_debug_data::c_align_size));

 for(size_t i=offset__align;i!=n1;++i)
 {
  assert(pBlock[i]==tag_debug_data::c_align_byte);
 }

 //-----------------------------------------
 const size_t offset__guard2=n1;

 const tag_debug_data::tag_guard_block*
  const pGuardBlock2=reinterpret_cast<const tag_debug_data::tag_guard_block*>(pBlock+offset__guard2);

 assert(IsEqualGUID(pGuardBlock2->sign,tag_debug_data::c_block2_sign));

 assert(pGuardBlock2->total_size==pGuardBlock1->total_size);
 assert(pGuardBlock2->user_size==pGuardBlock1->user_size);

 //----------
 _VERIFY(structure::append_memory_size(n1,tag_debug_data::c_guard_block_size));

 for(size_t i=offset__guard2+sizeof(tag_debug_data::tag_guard_block);i!=n1;++i)
 {
  assert(pBlock[i]==tag_debug_data::c_guard_byte2);
 }

 //-----------------------------------------
 assert(pGuardBlock1->total_size==n1);

 return self_type::Helper__FreeMemory(const_cast<unsigned char*>(pBlock));
}//Free

//------------------------------------------------------------------------
void IBP_MemoryWithDebugChecks::Debug__CheckBlock(const void* pv)
{
 if(pv==NULL)
  return;

 //-----------------------------------------
 const unsigned char*
  const pUserBlock=reinterpret_cast<const unsigned char*>(pv);

 assert(tag_debug_data::c_guard_block_size<=(size_t)(pv));

 const unsigned char*
  const pBlock=(pUserBlock-tag_debug_data::c_guard_block_size);

 //-----------------------------------------
 const tag_debug_data::tag_guard_block*
  const pGuardBlock1=reinterpret_cast<const tag_debug_data::tag_guard_block*>(pBlock);

 assert(IsEqualGUID(pGuardBlock1->sign,tag_debug_data::c_block1_sign));

 assert(pGuardBlock1->user_size<pGuardBlock1->total_size);
 assert((2*tag_debug_data::c_guard_block_size)<=(pGuardBlock1->total_size-pGuardBlock1->user_size));

 //-----------------------------------------
 for(size_t i=sizeof(tag_debug_data::tag_guard_block);i!=tag_debug_data::c_guard_block_size;++i)
 {
  assert(pBlock[i]==tag_debug_data::c_guard_byte1);
 }//for

 //-----------------------------------------
 size_t n1=tag_debug_data::c_guard_block_size;

 _VERIFY(structure::append_memory_size(n1,pGuardBlock1->user_size));

 const size_t offset__align=n1;

 _VERIFY(structure::align_memory_size(n1,tag_debug_data::c_align_size));

 for(size_t i=offset__align;i!=n1;++i)
 {
  assert(pBlock[i]==tag_debug_data::c_align_byte);
 }

 //-----------------------------------------
 const size_t offset__guard2=n1;

 const tag_debug_data::tag_guard_block*
  const pGuardBlock2=reinterpret_cast<const tag_debug_data::tag_guard_block*>(pBlock+offset__guard2);

 assert(IsEqualGUID(pGuardBlock2->sign,tag_debug_data::c_block2_sign));

 assert(pGuardBlock2->total_size==pGuardBlock1->total_size);
 assert(pGuardBlock2->user_size==pGuardBlock1->user_size);

 //----------
 _VERIFY(structure::append_memory_size(n1,tag_debug_data::c_guard_block_size));

 for(size_t i=offset__guard2+sizeof(tag_debug_data::tag_guard_block);i!=n1;++i)
 {
  assert(pBlock[i]==tag_debug_data::c_guard_byte2);
 }

 //-----------------------------------------
 assert(pGuardBlock1->total_size==n1);
}//Debug__CheckBlock

#endif // !NDEBUG

//Helper methods ---------------------------------------------------------
void* IBP_MemoryWithDebugChecks::Helper__AllocMemory(size_t const sz)
{
 return IBP_MemoryAllocator::instance.allocate(sz); //throw
}//Helper__AllocMemory

//------------------------------------------------------------------------
void IBP_MemoryWithDebugChecks::Helper__FreeMemory(void* const pv)
{
 return IBP_MemoryAllocator::instance.deallocate(pv,0);
}//Helper__FreeMemory

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
