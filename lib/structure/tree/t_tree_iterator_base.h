////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tree_iterator_base_H_
#define _t_tree_iterator_base_H_

#include <lcpi/lib/.config.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

#if 0

template<class PNode>
void tree_iterator_forward(const PNode& start_node,PNode& cur_node)
{
 assert(cur_node);
 assert(start_node);
 assert(cur_node != start_node->m_parent);

 if(cur_node->m_left)
 {
  cur_node=cur_node->m_left;

  return;
 }

 if(cur_node->m_right)
 {
  cur_node=cur_node->m_right;

  return;
 }

 //раскрутка вверх
 for(;;)
 {
  PNode const old_cur_node(cur_node);

  assert(cur_node);

  cur_node=cur_node->m_parent;

  assert(start_node);

  if(cur_node == start_node->m_parent)
   break;//типа выскочили за начальный элемент просматриваемого дерева

  assert(cur_node);

  //пришли слева                        и   есть правый элемент
  if(old_cur_node == cur_node->m_left && cur_node->m_right)
  {
   //переходим на правый элемент
   cur_node=cur_node->m_right;

   break;
  }

  //пришли справа
 }//for[ever]
}//tree_iterator_forward

#endif

//------------------------------------------------------------------------

template<class PNode>
PNode tree_iterator_forward3(PNode const head_node,PNode cur_node)
{
 //   2
 // 1   3

 assert(cur_node);
 assert(head_node);
 assert(cur_node != head_node->m_parent);

 if(cur_node->m_right)
 {
  cur_node=cur_node->m_right;

  while(cur_node->m_left)
   cur_node=cur_node->m_left;
 }//if cur_node->m_right
 else
 {
  assert(!cur_node->m_right);

  //раскрутка вверх
  for(;;)
  {
   PNode const old_cur_node(cur_node);

   assert(cur_node);

   cur_node=cur_node->m_parent;

   assert(head_node);

   if(cur_node == head_node->m_parent)
    break;//типа выскочили за начальный элемент просматриваемого дерева

   assert(cur_node);

   //пришли слева?
   if(old_cur_node == cur_node->m_left)
    break;

   //пришли справа
   assert(cur_node->m_right==old_cur_node);
  }//for[ever]
 }//else

 return cur_node;
}//tree_iterator_forward3

////////////////////////////////////////////////////////////////////////////////

#if 0

template<class PNode>
void tree_iterator_back(const PNode& start_node,PNode& cur_node)
{
 //   1
 // 2   3
 assert(start_node != cur_node);
 assert(start_node);

 if(cur_node == start_node->m_parent)
 {
  //exit from end

  cur_node = start_node;

  for(;;)
  {
   if(cur_node->m_right)
   {
    cur_node = cur_node->m_right;
    continue;
   }

   if(cur_node->m_left)
   {
    cur_node = cur_node->m_left;
    continue;
   }
   break;
  }//for[ever]

  assert(cur_node);
  return;
 }//if

 assert(cur_node);
 assert(cur_node != start_node -> m_parent);

 PNode old_cur_node = cur_node->m_parent;

 if(old_cur_node!=start_node->m_parent && old_cur_node->m_right==cur_node)
 {
  //from right
  while(old_cur_node->m_left!=NULL)
  {
   old_cur_node=old_cur_node->m_left;

   while(old_cur_node->m_right!=NULL)
    old_cur_node = old_cur_node->m_right;
  }//while
 }//if

 cur_node=old_cur_node;
}//tree_iterator_back

#endif

//------------------------------------------------------------------------
template<class PNode>
PNode tree_iterator_back3(PNode const head_node,PNode cur_node)
{
 //   2
 // 1   3
 assert(head_node);

 if(cur_node == head_node->m_parent)
 {
  //exit from end
  cur_node = head_node;

  for(;;)
  {
   if(!cur_node->m_right)
    break;

   cur_node = cur_node->m_right;
  }//for[ever]

  return cur_node;
 }//if

 assert(cur_node);
 assert(cur_node != head_node->m_parent);

 if(cur_node->m_left)
 {
  cur_node=cur_node->m_left;

  while(cur_node->m_right)
   cur_node=cur_node->m_right;

  return cur_node;
 }//if

 assert(!cur_node->m_left);

 for(;;)
 {
  PNode const new_cur_node = cur_node->m_parent;

  assert(new_cur_node!=head_node->m_parent);

  if(new_cur_node->m_right==cur_node)
   return new_cur_node;

  //from left
  assert(cur_node==new_cur_node->m_left);

  cur_node=new_cur_node;
 }//for[ever]
}//tree_iterator_back3

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
