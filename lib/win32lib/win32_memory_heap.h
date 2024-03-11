////////////////////////////////////////////////////////////////////////////////
//Win32 memory heap
//                                                 Dmitry Kovalenko. 24.01.2004.
#ifndef _win32_memory_heap_H_
#define _win32_memory_heap_H_

#include <structure/mt/interlocked.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//Define custom class for Win32 heap

#define WIN32LIB__DECLARE_HEAP_CLASS(Name)                                \
class __T##Name##Win32__ LCPI_CPP_CFG__CLASS__FINAL                       \
{                                                                         \
 private:                                                                 \
  using self_type=__T##Name##Win32__;                                     \
                                                                          \
 private:                                                                 \
  static HANDLE       sm_hHeap;                                           \
  static size_t       sm_cAllocs;                                         \
  static LPCSTR const sm_HeapName;                                        \
                                                                          \
 public:                                                                  \
  static LPCSTR GetName()                                                 \
         {                                                                \
          return sm_HeapName;                                             \
         }                                                                \
                                                                          \
                                                                          \
  static BOOL  Create(DWORD dwOptions,                                    \
                      DWORD dwInitialSize,                                \
                      DWORD dwMaximumSize);                               \
                                                                          \
  static BOOL  Destroy();                                                 \
                                                                          \
  static bool  Created()                                                  \
         {                                                                \
          return sm_hHeap!=NULL;                                          \
         }                                                                \
                                                                          \
  static size_t GetAllocCount()                                           \
         {                                                                \
          return sm_cAllocs;                                              \
         }                                                                \
                                                                          \
  static BOOL Validate(DWORD const dwFlags)                               \
         {                                                                \
          assert(self_type::Created());                                   \
                                                                          \
          return ::HeapValidate(sm_hHeap,dwFlags,nullptr);                \
         }                                                                \
                                                                          \
  static void* vAlloc(size_t sz);                                         \
                                                                          \
  static char* chAlloc(size_t const sz)                                   \
         {                                                                \
          return reinterpret_cast<char*>(self_type::vAlloc(sz));          \
         }                                                                \
                                                                          \
  static BOOL bFree(void* pv);                                            \
                                                                          \
  static void vFree(void* const pv)                                       \
         {                                                                \
          _VERIFY(self_type::bFree(pv));                                  \
         }                                                                \
};

#define WIN32LIB__DECLARE_HEAP(Name)                                      \
WIN32LIB__DECLARE_HEAP_CLASS(Name)                                        \
static __T##Name##Win32__ Name;

#define WIN32LIB__DECLARE_HEAP_EXTERN(Name)                               \
WIN32LIB__DECLARE_HEAP_CLASS(Name)                                        \
extern __T##Name##Win32__ Name;

#define _ODS_WIN32_HEAP_BAD_ALLOC_                                        \
{                                                                         \
  DebugMessage("ERROR: Heap can't allocate "<<sz<<" bytes "               \
               "in \""<<sm_HeapName<<"\"");                               \
}

//if heap declared as nested class then owner is "external_class::"
//
//_THROW_BAD_ALLOC_ - throw bad_alloc() or _WIN32_HEAP_BAD_ALLOCATE_ODS_

#define WIN32LIB__DEFINE_HEAP(Owner,Name,_THROW_BAD_ALLOC_)               \
                                                                          \
HANDLE Owner##__T##Name##Win32__::sm_hHeap=NULL;                          \
                                                                          \
size_t Owner##__T##Name##Win32__::sm_cAllocs=0;                           \
                                                                          \
LPCSTR const Owner##__T##Name##Win32__::sm_HeapName                       \
 =#Owner "__T" #Name "Win32__";                                           \
                                                                          \
BOOL Owner##__T##Name##Win32__::Create(DWORD const dwOptions,             \
                                       DWORD const dwInitialSize,         \
                                       DWORD const dwMaximumSize)         \
{                                                                         \
 assert_msg(sm_hHeap==NULL,                                               \
            "Heap already created ["<<sm_HeapName<<"]");                  \
                                                                          \
 sm_hHeap=::HeapCreate(dwOptions,dwInitialSize,dwMaximumSize);            \
                                                                          \
 DebugMessage3                                                            \
  (sm_hHeap==NULL,                                                        \
   "ERROR: Failed to create a memory heap \""<<sm_HeapName<<"\"");        \
                                                                          \
 return sm_hHeap!=NULL;                                                   \
}                                                                         \
                                                                          \
BOOL Owner##__T##Name##Win32__::Destroy()                                 \
{                                                                         \
 DebugMessage3                                                            \
  ((sm_cAllocs>0 && sm_hHeap!=NULL),                                      \
    "ERROR: Destroy memory heap \""<<sm_HeapName<<"\" "                   \
    "with "<<sm_cAllocs<<" block(s)");                                    \
                                                                          \
 const BOOL res=(sm_hHeap!=NULL)?::HeapDestroy(sm_hHeap):true;            \
                                                                          \
 if(res)                                                                  \
 {                                                                        \
  sm_hHeap=NULL;                                                          \
 }                                                                        \
 else                                                                     \
 {                                                                        \
  DebugMessage("ERROR: Failed to destroy a heap \""<<sm_HeapName<<"\"");  \
 }                                                                        \
                                                                          \
 return res;                                                              \
}                                                                         \
                                                                          \
void* Owner##__T##Name##Win32__::vAlloc(size_t const sz)                  \
{                                                                         \
 assert_msg(sm_hHeap!=NULL,                                               \
            "Heap \""<<sm_HeapName<<"\" not created");                    \
                                                                          \
 void* const pv=::HeapAlloc(sm_hHeap,HEAP_ZERO_MEMORY,sz);                \
                                                                          \
 if(pv!=nullptr)                                                          \
 {                                                                        \
  ::lcpi::lib::structure::mt::interlocked::increment(&sm_cAllocs);        \
 }                                                                        \
 else                                                                     \
 {                                                                        \
  _THROW_BAD_ALLOC_;                                                      \
 }                                                                        \
                                                                          \
 return pv;                                                               \
}                                                                         \
                                                                          \
BOOL Owner##__T##Name##Win32__::bFree(void* const pv)                     \
{                                                                         \
 assert_msg(sm_hHeap!=NULL,                                               \
            "Heap \""<<sm_HeapName<<"\" not created");                    \
                                                                          \
 if(pv==nullptr) return true;                                             \
                                                                          \
 assert(sm_cAllocs>0);                                                    \
                                                                          \
 BOOL const res=::HeapFree(sm_hHeap,0,pv);                                \
                                                                          \
 if(res)                                                                  \
 {                                                                        \
  ::lcpi::lib::structure::mt::interlocked::decrement(&sm_cAllocs);        \
 }                                                                        \
 else                                                                     \
 {                                                                        \
  DebugMessage                                                            \
   ("ERROR: freeing the block 0x"<<std::hex<<std::uppercase<<pv           \
    <<std::dec<<std::nouppercase                                          \
    <<" in heap \""<<sm_HeapName<<"\" has finished with the error code: " \
    <<GetLastError());                                                    \
 }                                                                        \
                                                                          \
 return res;                                                              \
}

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
