////////////////////////////////////////////////////////////////////////////////
#ifndef _t_smart_vector_CC_
#define _t_smart_vector_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_smart_vector

#if(COMP_CONF_SUPPORT_TEMPLATE_USING==0)

template<class T,class Allocator>
RELEASE_CODE(inline)
t_smart_vector<T,Allocator>::t_smart_vector(const Allocator& alloc)
 :inherited(alloc)
{
}

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
t_smart_vector<T,Allocator>::t_smart_vector(size_type        n,
                                            const Allocator& alloc)
 :inherited(n,alloc)
{
}

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
t_smart_vector<T,Allocator>::t_smart_vector(const self_type& x)
 :inherited(x)
{
}

//------------------------------------------------------------------------
template<class T,class Allocator>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class InputIterator>
RELEASE_CODE(inline)
t_smart_vector<T,Allocator>::t_smart_vector(InputIterator    first,
                                            InputIterator    last,
                                            const Allocator& alloc)
#else
RELEASE_CODE(inline)
t_smart_vector<T,Allocator>::t_smart_vector(const_iterator   first,
                                            const_iterator   last,
                                            const Allocator& alloc)
#endif
 :inherited(first,last,alloc)
{
}

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
t_smart_vector<T,Allocator>::t_smart_vector(size_type         n,
                                            const value_type& x,
                                            const Allocator&  alloc)
 :inherited(n,x,alloc)
{
}

//------------------------------------------------------------------------
template<class T,class Allocator>
RELEASE_CODE(inline)
t_smart_vector<T,Allocator>&
 t_smart_vector<T,Allocator>::operator = (const self_type& x)
{
 inherited::operator = (x);

 return *this;
}// copy operator

//------------------------------------------------------------------------
#endif

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
