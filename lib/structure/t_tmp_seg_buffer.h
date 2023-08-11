////////////////////////////////////////////////////////////////////////////////
//Temporary segment-based buffer
//                                                 Kovalenko Dmitry. 07.05.2008
#ifndef _t_tmp_seg_buffer_H_
#define _t_tmp_seg_buffer_H_

#include <structure/t_memory.h>
#include <structure/t_list_external.h>
#include <structure/t_meta_prog.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<typename T>
class t_tmp_seg_buffer_traits;

template<typename T>
struct t_tmp_seg_buffer__header;

template<typename T>
class t_tmp_seg_buffer__iterator;

template<typename T>
class t_tmp_seg_buffer__const_iterator;

template<typename T,size_t FixBufSize,class Allocator, class Traits=t_tmp_seg_buffer_traits<T> >
class t_tmp_seg_buffer;

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer_traits

template<typename T>
class t_tmp_seg_buffer_traits
{
 public: //typedefs ------------------------------------------------------
  typedef T                                 value_type;

  typedef value_type*                       pointer;

  typedef const value_type*                 const_pointer;

  typedef size_t                            size_type;

 public:
  static void copy(pointer       dest,
                   const_pointer src,
                   size_type     cnt);

  static size_type copy_binary(void*         dest,
                               size_type     dest_size,
                               const_pointer src,
                               size_type     src_cnt);
};//class t_tmp_seg_buffer_traits

////////////////////////////////////////////////////////////////////////////////
//struct t_tmp_seg_buffer__header

template<typename T>
struct t_tmp_seg_buffer__header
{
 private:
  typedef t_tmp_seg_buffer__header<T>       self_type;

 public: //typedefs ------------------------------------------------------
  typedef T                                 value_type;
  typedef value_type*                       pointer;
  typedef const value_type*                 const_pointer;

  typedef size_t                            size_type;

 public:
  size_type      size;
  size_type      used;
  self_type*     prev;
  self_type*     next;

 public:
  pointer data();

  const_pointer data()const;
};//struct t_tmp_seg_buffer__header

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer__iterator

template<typename T>
class t_tmp_seg_buffer__iterator
{
 private:
  typedef t_tmp_seg_buffer__iterator<T>                       self_type;

 public: //typedefs ------------------------------------------------------
  typedef std::bidirectional_iterator_tag                     iterator_category;
  typedef T                                                   value_type;
  typedef ptrdiff_t                                           difference_type;
  typedef T*                                                  pointer;
  typedef T&                                                  reference;

  typedef T                                                   item_type;

  typedef t_tmp_seg_buffer__header<T>                         segment_type;
  typedef segment_type*                                       segment_ptr;

  typedef typename segment_type::size_type                    pos_type;

  typedef t_tmp_seg_buffer__const_iterator<T>                 r_iterator_type;

  friend class r_iterator_type;

 public:
  t_tmp_seg_buffer__iterator();

  t_tmp_seg_buffer__iterator(segment_ptr segment,pos_type pos);

  t_tmp_seg_buffer__iterator(const self_type&);

 ~t_tmp_seg_buffer__iterator();

  self_type& operator = (const self_type&);

  //iterator interface ---------------------------------------------------
  reference        operator *  () const;

  //navigations on tree
  self_type        operator ++ (int);
  self_type&       operator ++ ();
  self_type        operator -- (int);
  self_type&       operator -- ();

 public:
  bool eq(const self_type& x1)const;

 private:
 #ifndef NDEBUG
  void check_state()const;

  void check_other_it(const self_type& x)const;
 #endif

 private:
  segment_ptr   m_segment;
  pos_type      m_pos;
};//t_tmp_seg_buffer__iterator

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer__const_iterator

template<typename T>
class t_tmp_seg_buffer__const_iterator
{
 private:
  typedef t_tmp_seg_buffer__const_iterator<T>                 self_type;

 public: //typedefs ------------------------------------------------------
  typedef std::bidirectional_iterator_tag                     iterator_category;
  typedef T                                                   value_type;
  typedef ptrdiff_t                                           difference_type;
  typedef const T*                                            pointer;
  typedef const T&                                            reference;

  typedef T                                                   item_type;

  typedef t_tmp_seg_buffer__header<T>                         segment_type;
  typedef const segment_type*                                 segment_ptr;

  typedef typename segment_type::size_type                    pos_type;

  typedef t_tmp_seg_buffer__iterator<T>                       rw_iterator_type;

 public:
  t_tmp_seg_buffer__const_iterator();

  t_tmp_seg_buffer__const_iterator(segment_ptr segment,pos_type pos);

  t_tmp_seg_buffer__const_iterator(const self_type&);

  t_tmp_seg_buffer__const_iterator(const rw_iterator_type&);

 ~t_tmp_seg_buffer__const_iterator();

  self_type& operator = (const self_type&);

  //iterator interface ---------------------------------------------------
  reference        operator *  () const;

  //navigations on tree
  self_type        operator ++ (int);
  self_type&       operator ++ ();
  self_type        operator -- (int);
  self_type&       operator -- ();

 public:
  bool eq(const self_type& x)const;

 private:
 #ifndef NDEBUG
  void check_state()const;

  void check_other_it(const self_type& x)const;
 #endif

 private:
  segment_ptr   m_segment;
  pos_type      m_pos;
};//t_tmp_seg_buffer__const_iterator

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer

template<typename T,size_t FixBufSize,class Allocator,class Traits>
class t_tmp_seg_buffer
{
 private:
  typedef t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>    self_type;

  t_tmp_seg_buffer(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef Allocator                                          allocator_type;

  typedef Traits                                             traits_type;

  typedef size_t                                             size_type;

  typedef T                                                  value_type;

  typedef t_tmp_seg_buffer__header<value_type>               seg_header_type;
  typedef seg_header_type*                                   seg_header_ptr;
  typedef const seg_header_type*                             seg_header_cptr;

  typedef value_type*                                        pointer;
  typedef const value_type*                                  const_pointer;

  typedef value_type&                                        reference;
  typedef const value_type&                                  const_reference;

  typedef t_tmp_seg_buffer__iterator<value_type>             iterator;
  typedef t_tmp_seg_buffer__const_iterator<value_type>       const_iterator;

 public:
  static const size_type c_def_min_seg_size=16*1024;

 public:
  t_tmp_seg_buffer();

  explicit t_tmp_seg_buffer(size_type min_seg_size);

 ~t_tmp_seg_buffer();

  //selectors ------------------------------------------------------------
  size_type fix_seg_size()const;

  size_type min_seg_size()const;

  bool empty()const;

  size_type size()const;

  const seg_header_type* head()const;

  const seg_header_type* tail()const;

  /// <summary>
  ///  Copy data to untyped buffer
  /// </summary>
  //! \param[in,out] dest
  //! \param[in] dest_size
  //! \return
  //!  number of copied bytes
  size_type copy_binary(void* dest,size_type dest_size)const;

  /// <summary>
  ///  Copy data to flat buffer
  /// </summary>
  //! \param[in,out] dest
  //! \param[in] dest_size
  //! \return
  //!  number of copied bytes
  size_type copy(pointer dest,size_type dest_size)const;

  template<class TContainer>
  void append_to(TContainer& dest);

  //accessors ------------------------------------------------------------
  reference front();
  reference back();

  const_reference front()const;
  const_reference back()const;

  //navigation -----------------------------------------------------------
  iterator       begin();
  iterator       end();

  const_iterator begin()const;
  const_iterator end()const;

  const_iterator cbegin()const;
  const_iterator cend()const;

  //modificators ---------------------------------------------------------
  void clear();

  void push_back(const value_type& x);

  void pop_back();

  void write(const_pointer ptr,size_type cnt);

  pointer lock(size_type req_cnt);

  void  unlock(size_type used_cnt);

  /// <summary>
  ///  Transformation to flat buffer
  /// </summary>
  //! \param[in] final
  //!  - true, allocate m_size byte only
  //!  - false, adjust size to min_seg_size
  pointer make_flat(bool final=true);

 private:
  seg_header_type* allocate_new_seg(size_type cnt);

  void append_new_seg(size_type alloc_cnt,const_pointer ptr,size_type cnt);

  void remove_segment(seg_header_type* seg);

 private:
  struct tag_fix_seg_N:public seg_header_type
  {
   public:
    value_type m_data[FixBufSize];

   public:
    tag_fix_seg_N();

    void init();
  };//struct tag_fix_seg_N

  struct tag_fix_seg_0:public seg_header_type
  {
   public:
    tag_fix_seg_0();

    void init();
  };//struct tag_fix_seg_0

  typedef t_mp_select<(FixBufSize>0),tag_fix_seg_N,tag_fix_seg_0>  __fix_seg_type_selector;

  typedef typename __fix_seg_type_selector::result    fix_seg_type;

  typedef typename __STLS_ALLOCATOR_REBIND(allocator_type,char)  seg_alloc_type;

 private:
  class tag_seg_list_traits
  {
   public: //typedefs ----------------------------------------------------
    typedef seg_header_type*                node_ptr_type;

   public:
    static node_ptr_type null_ptr();

    node_ptr_type get_prev(node_ptr_type node)const;

    node_ptr_type get_next(node_ptr_type node)const;

    void set_prev(node_ptr_type node,node_ptr_type x)const;

    void set_next(node_ptr_type node,node_ptr_type x)const;
  };//class tag_seg_list_traits

  typedef t_list_external<tag_seg_list_traits>              seg_list_type;

 private:
  seg_alloc_type     m_alloc;

  seg_list_type      m_seg_list;

  size_type          m_size;

  size_type          m_lock_cnt;

  size_type          m_min_seg_size;

  fix_seg_type       m_fix_segment;
};//class t_tmp_seg_buffer

////////////////////////////////////////////////////////////////////////////////
//non-member iterators [t_tmp_seg_buffer__iterator]

template<typename T>
inline
bool operator == (const t_tmp_seg_buffer__iterator<T>& x1,
                  const t_tmp_seg_buffer__iterator<T>& x2)
{
 return x1.eq(x2);
}//operator ==

//------------------------------------------------------------------------
template<typename T>
inline
bool operator != (const t_tmp_seg_buffer__iterator<T>& x1,
                  const t_tmp_seg_buffer__iterator<T>& x2)
{
 return !(x1==x2);
}//operator !=

////////////////////////////////////////////////////////////////////////////////
//non-member iterators [t_tmp_seg_buffer__const_iterator]

template<typename T>
inline
bool operator == (const t_tmp_seg_buffer__const_iterator<T>& x1,
                  const t_tmp_seg_buffer__const_iterator<T>& x2)
{
 return x1.eq(x2);
}//operator ==

//------------------------------------------------------------------------
template<typename T>
inline
bool operator != (const t_tmp_seg_buffer__const_iterator<T>& x1,
                  const t_tmp_seg_buffer__const_iterator<T>& x2)
{
 return !(x1==x2);
}//operator !=

////////////////////////////////////////////////////////////////////////////////
//non-member iterators [t_tmp_seg_buffer__iterator t_tmp_seg_buffer__const_iterator]

template<typename T>
inline
bool operator == (const t_tmp_seg_buffer__iterator<T>&       x1,
                  const t_tmp_seg_buffer__const_iterator<T>& x2)
{
 typedef t_tmp_seg_buffer__const_iterator<T> const_iterator;

 return const_iterator(x1).eq(x2);
}//operator ==

//------------------------------------------------------------------------
template<typename T>
inline
bool operator != (const t_tmp_seg_buffer__iterator<T>&       x1,
                  const t_tmp_seg_buffer__const_iterator<T>& x2)
{
 return !(x1==x2);
}//operator !=

////////////////////////////////////////////////////////////////////////////////
//non-member iterators [t_tmp_seg_buffer__const_iterator t_tmp_seg_buffer__iterator]

template<typename T>
inline
bool operator == (const t_tmp_seg_buffer__const_iterator<T>& x1,
                  const t_tmp_seg_buffer__iterator<T>&       x2)
{
 return x1.eq(x2);
}//operator ==

//------------------------------------------------------------------------
template<typename T>
inline
bool operator != (const t_tmp_seg_buffer__const_iterator<T>& x1,
                  const t_tmp_seg_buffer__iterator<T>&       x2)
{
 return !(x1==x2);
}//operator !=

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_tmp_seg_buffer.cc>
////////////////////////////////////////////////////////////////////////////////
#endif