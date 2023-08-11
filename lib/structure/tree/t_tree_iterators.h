////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tree_iterators_H_
#define _t_tree_iterators_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/tree/t_tree_iterator_base.h>
#include <iterator>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class TTree>
class t_tree_iterator;

template<class TNode>
class t_tree_const_iterator;

////////////////////////////////////////////////////////////////////////////////
//class t_tree_iterator

template<class TTree>
class t_tree_iterator
{
 private:
  typedef t_tree_iterator<TTree>                              self_type;

 public: //typedefs ------------------------------------------------------
  typedef std::bidirectional_iterator_tag                     iterator_category;
  typedef typename TTree::value_type                          value_type;
  typedef ptrdiff_t                                           difference_type;
  typedef typename TTree::value_type*                         pointer;
  typedef typename TTree::value_type&                         reference;

 public:
  typedef TTree                                               tree_type;
  typedef tree_type*                                          ptree_type;
  typedef typename tree_type::node_type                       node_type;
  typedef node_type*                                          pnode_type;
  typedef typename node_type::value_type                      item_type;

 private:
  typedef t_tree_const_iterator<TTree>                        r_iterator_type;

 public:
  t_tree_iterator();
  t_tree_iterator(ptree_type tree,pnode_type cur_node);
  t_tree_iterator(const self_type& it);

  self_type& operator = (const self_type&);

  //---------------------------------------------------------------------
  //операторы
  bool             operator == (const self_type&)const;
  bool             operator != (const self_type&)const;

  bool             operator == (const r_iterator_type&)const;
  bool             operator != (const r_iterator_type&)const;

  reference        operator *  ()const;          //получение ключа

  //navigations on tree
  self_type        operator ++ (int);            //вперед(постфикс)
  self_type&       operator ++ ();               //вперед(префикс)
  self_type        operator -- (int);            //назад(постфикс)
  self_type&       operator -- ();               //назад(префикс)

  //взятие узлов
  ptree_type get_tree()const;
  pnode_type get_current()const; //текущий узел итератора

 private:
  ptree_type m_tree;
  pnode_type m_cur_node;
};//class t_tree_iterator

////////////////////////////////////////////////////////////////////////////////
//class t_tree_const_iterator

template<class TTree>
class t_tree_const_iterator
{
 private:
  typedef t_tree_const_iterator<TTree>                         self_type;

 public: //typedefs ------------------------------------------------------
  typedef std::bidirectional_iterator_tag                      iterator_category;
  typedef typename TTree::value_type                           value_type;
  typedef ptrdiff_t                                            difference_type;
  typedef typename const TTree::value_type*                    pointer;
  typedef typename const TTree::value_type&                    reference;

 public:
  typedef TTree                                                tree_type;
  typedef const tree_type*                                     ptree_type;
  typedef typename tree_type::node_type                        node_type;
  typedef const node_type*                                     pnode_type;
  typedef typename node_type::value_type                       item_type;

 private:
  typedef t_tree_iterator<TTree>                               rw_iterator_type;

 public:
  t_tree_const_iterator();
  t_tree_const_iterator(ptree_type tree,pnode_type cur_node);
  t_tree_const_iterator(const self_type& it);

  t_tree_const_iterator(const rw_iterator_type& it);

  self_type& operator = (const self_type&);
  self_type& operator = (const rw_iterator_type& rw);

  //---------------------------------------------------------------------
  //операторы
  bool             operator == (const self_type&)const;
  bool             operator != (const self_type&)const;

  bool             operator == (const rw_iterator_type&)const;
  bool             operator != (const rw_iterator_type&)const;

  reference        operator *  ()const;//взятие ключа

  //navigations on tree
  self_type        operator ++ (int); //вперед(постфикс)
  self_type&       operator ++ ();    //вперед(префикс)
  self_type        operator -- (int); //назад(постфикс)
  self_type&       operator -- ();    //назад(префикс)

  //взятие узлов
  ptree_type get_tree()const;
  pnode_type get_current()const;//текущий узел итератора

 private:
  ptree_type m_tree;
  pnode_type m_cur_node;
};//class t_tree_const_iterator

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/tree/t_tree_iterators.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
