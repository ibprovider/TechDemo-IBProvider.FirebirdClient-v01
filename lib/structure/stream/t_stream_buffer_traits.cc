////////////////////////////////////////////////////////////////////////////////
#ifndef _t_stream_buffer_traits_CC_
#define _t_stream_buffer_traits_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//t_stream_buffer_traits__binary

template<class T>
void t_stream_buffer_traits__binary<T>::copy(pointer*         dest,
                                             const_pointer*   source,
                                             size_type  const n,
                                             size_type* const actual_readed_accum)
{
 assert(dest);
 assert(source);
 assert(actual_readed_accum);
 
 CHECK_WRITE_TYPED_PTR(*dest,n);
 CHECK_READ_TYPED_PTR (*source,n);

 memcpy(*dest,*source,n*sizeof(value_type));

 (*actual_readed_accum)+=n;

 (*dest)   +=n;
 (*source) +=n;
}//copy

////////////////////////////////////////////////////////////////////////////////
//t_stream_buffer_traits__generic

template<class T>
void t_stream_buffer_traits__generic<T>::copy(pointer*       const dest,
                                              const_pointer* const source,
                                              size_type            n,
                                              size_type*     const actual_readed_accum)
{
 assert(dest);
 assert(source);
 assert(actual_readed_accum);
 
 CHECK_WRITE_TYPED_PTR(*dest,n);
 CHECK_READ_TYPED_PTR (*source,n);

 for(;n!=0;--n)
 {
  (**dest)=(**source);

  ++(*actual_readed_accum);

  ++(*source);
  ++(*dest);
 }//for
}//copy

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
