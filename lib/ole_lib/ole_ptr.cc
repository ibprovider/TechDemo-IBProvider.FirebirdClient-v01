////////////////////////////////////////////////////////////////////////////////
//implementaion of templates from <ole_lib/ptr.h>
//                                     Dmitry Kovalenko. december 28, 2001 year.
#ifndef _ole_ptr_CC_
#define _ole_ptr_CC_

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//struct TEnumIPtr2Traits

template<class TEnumItemInterface,class Allocator>
RELEASE_CODE(inline)
void TEnumIPtr2Traits<TEnumItemInterface,Allocator>::CopyInEnumerator
                                           (ole_item_type* const ppDestUnk,
                                            ole_item_type  const _source)
{
 assert(ppDestUnk!=NULL);

 ole_lib::CopyComInterface2(_source,*ppDestUnk);
}//CopyInEnumerator

//------------------------------------------------------------------------
template<class TEnumItemInterface,class Allocator>
RELEASE_CODE(inline)
typename TEnumIPtr2Traits<TEnumItemInterface,Allocator>::size_type
 TEnumIPtr2Traits<TEnumItemInterface,Allocator>::Size
                                           (const storage_type& storage)
{
 return storage.size();
}//Size

//------------------------------------------------------------------------
template<class TEnumItemInterface,class Allocator>
RELEASE_CODE(inline)
typename TEnumIPtr2Traits<TEnumItemInterface,Allocator>::const_reference
 TEnumIPtr2Traits<TEnumItemInterface,Allocator>::Item
                                           (const storage_type& storage,
                                            size_type           Index)
{
 return storage[Index];
}//Item

//------------------------------------------------------------------------
template<class TEnumItemInterface,class Allocator>
RELEASE_CODE(inline)
void TEnumIPtr2Traits<TEnumItemInterface,Allocator>::Reserve
                                           (storage_type&   storage,
                                            size_type const n)
{
 storage.reserve(n);
}//Reserve

//------------------------------------------------------------------------
template<class TEnumItemInterface,class Allocator>
RELEASE_CODE(inline)
void TEnumIPtr2Traits<TEnumItemInterface,Allocator>::Add
                                           (storage_type& storage,
                                            ole_item_type item)
{
 storage.push_back(item);
}//Add

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class TEnumItemInterface,class Allocator>
RELEASE_CODE(inline)
void TEnumIPtr2Traits<TEnumItemInterface,Allocator>::Add
                                           (storage_type&    storage,
                                            user_item_type&& item)
{
 storage.push_back(__STL_MOVE_VALUE(item));
}//Add

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class TEnumItemInterface,class Allocator>
RELEASE_CODE(inline)
void TEnumIPtr2Traits<TEnumItemInterface,Allocator>::Clear
                                           (ole_item_type* const ppUnk)
{
 assert(ppUnk!=NULL);

 ole_lib::ReleaseComInterface(*ppUnk);

 assert((*ppUnk)==NULL);
}//Clear

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
