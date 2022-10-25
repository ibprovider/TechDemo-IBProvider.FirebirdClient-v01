////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 06.10.2016
#ifndef _cpp_public_lcpi_lib_structure__t_const_str_box_CC_
#define _cpp_public_lcpi_lib_structure__t_const_str_box_CC_

#include <lcpi/lib/structure/t_algorithm.h>

#include <lcpi/lib/structure/utilities/string/miss_space.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//factory

template<typename charT>
t_basic_const_str_box<charT> make_str_box(const charT* const s,size_t const n)
{
 CHECK_READ_TYPED_PTR(s,n);

 return t_basic_const_str_box<charT>(s,n);
}//make_str_box

//------------------------------------------------------------------------
template<typename charT>
t_basic_const_str_box<charT> make_str_box(const charT* const s)
{
 return t_basic_const_str_box<charT>(s);
}//make_str_box

//------------------------------------------------------------------------
template<typename charT,typename Traits,typename Allocator>
t_basic_const_str_box<charT> make_str_box(const std::basic_string<charT,Traits,Allocator>& s)
{
 return t_basic_const_str_box<charT>(s);
}//make_str_box

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_str_box

template<typename charT>
inline t_basic_const_str_box<charT>::t_basic_const_str_box()
 :ptr(nullptr)
 ,len(0)
{
}

//------------------------------------------------------------------------
template<typename charT>
inline t_basic_const_str_box<charT>::t_basic_const_str_box
                                            (std::nullptr_t const x)
 :ptr(x)
 ,len(0)
{
}

//------------------------------------------------------------------------
template<typename charT>
inline t_basic_const_str_box<charT>::t_basic_const_str_box
                                            (const string_type& str)
 :ptr(str.c_str())
 ,len(str.size())
{
}

//------------------------------------------------------------------------
template<typename charT>
inline t_basic_const_str_box<charT>::t_basic_const_str_box
                                           (const t_first_last<iterator>& range)
#ifndef NDEBUG
 :ptr(range.first.get_ptr())
#else
 :ptr(range.first)
#endif
 ,len(range.last-range.first)
{
}

//------------------------------------------------------------------------
template<typename charT>
inline t_basic_const_str_box<charT>::t_basic_const_str_box
                                           (iterator const first,
                                            iterator const last)
#ifndef NDEBUG
 :ptr(first.get_ptr())
#else
 :ptr(first)
#endif
 ,len(last-first)
{
 assert(first<=last);
}

//------------------------------------------------------------------------
template<typename charT>
inline t_basic_const_str_box<charT>::t_basic_const_str_box
                                            (pointer   const _ptr,
                                             size_type const _len)
 :ptr(_ptr)
 ,len(_len)
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);
}

//------------------------------------------------------------------------
template<typename charT>
inline t_basic_const_str_box<charT>::t_basic_const_str_box
                                            (pointer const _ptr)
 :ptr(_ptr)
 ,len(_ptr?std::char_traits<charT>::length(_ptr):0)
{
}

//------------------------------------------------------------------------
template<typename charT>
inline t_basic_const_str_box<charT>::t_basic_const_str_box
                                            (pointer_nn const _ptr_nn)
 :ptr(_ptr_nn.ptr())
 ,len(std::char_traits<charT>::length(_ptr_nn.ptr()))
{
}

//------------------------------------------------------------------------
template<typename charT>
inline typename t_basic_const_str_box<charT>::pointer
 t_basic_const_str_box<charT>::data()const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);

 return this->ptr;
}//data

//------------------------------------------------------------------------
template<typename charT>
inline bool
 t_basic_const_str_box<charT>::empty()const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);

 return this->len==0;
}//empty

//------------------------------------------------------------------------
template<typename charT>
inline size_t
 t_basic_const_str_box<charT>::size()const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);

 return this->len;
}//size

//------------------------------------------------------------------------
template<typename charT>
inline typename t_basic_const_str_box<charT>::size_type
 t_basic_const_str_box<charT>::byte_count()const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);

 return this->len*sizeof(*this->ptr);
}//byte_count

//------------------------------------------------------------------------
template<typename charT>
typename t_basic_const_str_box<charT>::string_type
 t_basic_const_str_box<charT>::make_str()const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);

 return string_type(this->begin(),this->end());
}//make_str

//------------------------------------------------------------------------
template<typename charT>
typename t_basic_const_str_box<charT>::self_type
 t_basic_const_str_box<charT>::substr(size_t const offset,
                                      size_t const length)const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);

 assert(offset<=this->len);

 const size_t resultLength=(std::min)(length,this->len-offset);

 return self_type(this->ptr+offset,resultLength);
}//substr

//------------------------------------------------------------------------
template<typename charT>
typename t_basic_const_str_box<charT>::reference
 t_basic_const_str_box<charT>::front()const
{
 assert(!this->empty());

 CHECK_READ_TYPED_PTR(this->ptr,this->len);

 return *this->ptr;
}//front

//------------------------------------------------------------------------
template<typename charT>
typename t_basic_const_str_box<charT>::reference
 t_basic_const_str_box<charT>::back()const
{
 assert(!this->empty());

 CHECK_READ_TYPED_PTR(this->ptr,this->len);

 return this->ptr[this->len-1];
}//back

//------------------------------------------------------------------------
template<typename charT>
typename t_basic_const_str_box<charT>::iterator
 t_basic_const_str_box<charT>::begin()const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);

#ifndef NDEBUG
 return iterator(this,this->ptr);
#else
 return this->ptr;
#endif
}//begin

//------------------------------------------------------------------------
template<typename charT>
typename t_basic_const_str_box<charT>::iterator
 t_basic_const_str_box<charT>::end()const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);

#ifndef NDEBUG
 return iterator(this,this->ptr+this->len);
#else
 return this->ptr+this->len;
#endif
}//end

//------------------------------------------------------------------------
template<typename charT>
typename t_basic_const_str_box<charT>::reference
 t_basic_const_str_box<charT>::operator [] (size_t const index)const
{
 assert_msg(index<this->len,"index: "<<index<<". len: "<<this->len);

 return this->ptr[index];
}//operator []

//------------------------------------------------------------------------
template<typename charT>
bool t_basic_const_str_box<charT>::equal(const self_type& x)const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);

 return structure::equal
         (x.begin(),
          x.end(),
          this->begin(),
          this->end());
}//equal

//------------------------------------------------------------------------
template<typename charT>
bool t_basic_const_str_box<charT>::equal(pointer const str,
                                         size_t  const size)const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->len);

 CHECK_READ_TYPED_PTR(str,size);

 return structure::equal
         (str,
          str+size,
          this->begin(),
          this->end());
}//equal

////////////////////////////////////////////////////////////////////////////////

template<class charT>
t_basic_const_str_box<charT>
 trim(const t_basic_const_str_box<charT>& str)
{
 const charT*
  e(__miss_space_back(str.ptr,str.ptr+str.len,tag_is_trim_char<charT>()));

 const charT*
  b(__miss_space(str.ptr,e,tag_is_trim_char<charT>()));

 assert(str.ptr<=b);
 assert(e<=(str.ptr+str.len));

 assert(b<=e);

 return t_basic_const_str_box<charT>(b,size_t(e-b));
}//trim

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
