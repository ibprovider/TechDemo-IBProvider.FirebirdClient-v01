////////////////////////////////////////////////////////////////////////////////
//Manager for external bidirectional sequential (list)
//                                                Kovalenko Dmitry. 12.03.2009
#ifndef _t_list_external_H_
#define _t_list_external_H_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

class t_list_external_base__with_size;

template<class t_traits,class t_base=t_list_external_base__with_size>
class t_list_external;

template<class t_node>
class t_list_external__traits_std;

////////////////////////////////////////////////////////////////////////////////
//class t_list_external_base__with_size

class t_list_external_base__with_size
{
 public: //typedefs ------------------------------------------------------
  typedef size_t                                         size_type;

 public:
  size_type size()const;

 protected:
  void set_size(size_type x);

  void dec_size();

  void inc_size();

 #ifndef NDEBUG
  void verify_size__eq(size_type x)const;

  void verify_size__eq_or_large(size_type x)const;
 #endif

 private:
  size_type m_size;
};//t_list_external_base__with_size

////////////////////////////////////////////////////////////////////////////////
//class t_list_external

//t_traits specification
// - typedef node_ptr_type
// - node_ptr_type null_ptr()const;
// - node_ptr_type get_prev(node_ptr_type node)const;
// - node_ptr_type get_next(node_ptr_type node)const;
// - void set_prev(node_ptr_type node,node_ptr_type new_prev)const;
// - void set_next(node_ptr_type node,node_ptr_type new_next)const;
template<class t_traits,class t_base>
class t_list_external LCPI_CPP_CFG__CLASS__FINAL
 :public t_base
{
 public: //typedefs ------------------------------------------------------
  typedef t_traits                                       traits_type;

  typedef typename traits_type::node_ptr_type            node_ptr_type;

 public:
  t_list_external();

  //interface ------------------------------------------------------------
  bool empty()const;

  node_ptr_type head()const;

  node_ptr_type tail()const;

  /// <summary>
  ///  Clear list
  /// </summary>
  void clear();

  /// <summary>
  ///  Remove node from list
  /// </summary>
  //! \param[in] traits
  //! \param[in] x
  //!  Pointer of list item
  void remove(const traits_type& traits,
              node_ptr_type      x);

  /// <summary>
  ///  Insert node into list
  /// </summary>
  //! \param[in] traits
  //! \param[in] position
  //!  Pointer to insert position. New item will insert before pointed item.
  //! \param[in] x
  //!  Pointer of list item
  void insert(const traits_type& traits,
              node_ptr_type      position,
              node_ptr_type      x);

  /// <summary>
  ///  Insert new node into list header
  /// </summary>
  //! \param[in] traits
  //! \param[in] x
  //!  Pointer to new list item
  void push_front(const traits_type& traits,
                  node_ptr_type      x);

  /// <summary>
  ///  Insert new node into list tail
  /// </summary>
  //! \param[in] traits
  //! \param[in] x
  //!  Pointer to new list item
  void push_back(const traits_type& traits,
                 node_ptr_type      x);

  /// <summary>
  ///  Move node to head
  /// </summary>
  //! \param[in] traits
  //! \param[in] x
  //!  Pointer to list item
  void bring_to_front(const traits_type& traits,
                      node_ptr_type      x);

  /// <summary>
  ///  Перемещение хвостовых элементов (по start_tail включительно) в начало списка.
  ///  Элемент start_tail станет началом списка.
  /// </summary>
  void move_tail_to_head(const traits_type& traits,node_ptr_type start_tail);

 private:
 #ifndef NDEBUG
  void verify(const traits_type& traits)const;

  void verify_item(const traits_type& traits,
                   node_ptr_type      x)const;
 #endif

 private:
  node_ptr_type  m_head;
  node_ptr_type  m_tail;
};//class t_list_external

////////////////////////////////////////////////////////////////////////////////
//class t_list_external__traits_std

template<class t_node>
class t_list_external__traits_std LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef t_list_external__traits_std<t_node>             self_type;

 public:
  typedef t_node                                          node_type;
  typedef node_type*                                      node_ptr_type;

 public:
  t_list_external__traits_std();

  static node_ptr_type null_ptr();

  node_ptr_type get_prev(node_ptr_type node)const;

  node_ptr_type get_next(node_ptr_type node)const;

  void set_prev(node_ptr_type node,node_ptr_type x)const;

  void set_next(node_ptr_type node,node_ptr_type x)const;
};//class t_list_external__traits_std

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_list_external.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
