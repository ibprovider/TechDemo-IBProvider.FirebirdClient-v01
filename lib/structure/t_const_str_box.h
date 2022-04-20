////////////////////////////////////////////////////////////////////////////////
//String box
//                                                 Kovalenko Dmitry. 16.11.2008
#ifndef _lcpi_lib_structure__t_const_str_box_H_
#define _lcpi_lib_structure__t_const_str_box_H_

#include <structure/utilities/string/equal_to_string.h>
#include <structure/utilities/string/create_strings2.h>

#include <structure/t_not_null_ptr.h>
#include <structure/t_vector_debug_iterator.h>
#include <structure/forwards.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_str_box

/// <summary>
///  Generic structure for store the pointer to RO-string and it length
/// </summary>
template<typename charT>
class t_basic_const_str_box COMP_W000006_CLASS_FINAL
{
 private:
  typedef t_basic_const_str_box<charT>                      self_type;

 public: //typedefs ------------------------------------------------------
  typedef charT                                             char_type;
  typedef size_t                                            size_type;

  typedef ptrdiff_t                                         difference_type;

  typedef char_type                                         value_type;

  typedef const value_type*                                 pointer;
  typedef const value_type&                                 reference;

  typedef structure::t_not_null_ptr<const value_type>       pointer_nn;

 #ifndef NDEBUG
  typedef structure::t_vector_debug_iterator<const self_type> iterator;
 #else
  typedef const value_type*                                   iterator;
 #endif

  typedef __STL_DEF_BASIC_STRING(charT)                     string_type;

 public:
  ///��������� �� ������ ��������
  pointer      ptr;

  ///���������� �������� � ������
  size_type    len;

 public:
  /// <summary>
  ///  ����������� ��-���������
  /// </summary>
  t_basic_const_str_box();

  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] x
  t_basic_const_str_box(std::nullptr_t x);

  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] str
  t_basic_const_str_box(const string_type& str);

  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] range
  t_basic_const_str_box(const t_first_last<iterator>& range);

  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] first
  //! \param[in] last
  t_basic_const_str_box(iterator first,iterator last);

  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] _ptr
  t_basic_const_str_box(pointer _ptr);
 
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] _ptr_nn
  t_basic_const_str_box(pointer_nn _ptr_nn);

  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] _ptr
  //! \param[in] _len
  t_basic_const_str_box(pointer _ptr,size_type _len);

  pointer data()const;

  /// <summary>
  ///  ������������ ���������� ��������
  /// </summary>
  bool empty()const;

  /// <summary>
  ///  Getting a element count
  /// </summary>
  size_t size()const;

  /// <summary>
  ///  ��������� ����� � ������
  /// </summary>
  size_type byte_count()const;

  /// <summary>
  ///  ��������� ������ � ���� ������
  /// </summary>
  string_type make_str()const;

 public:
  reference front()const;

  reference back()const;

 public:
  iterator begin()const;

  iterator end()const;

 public:
  reference operator [] (size_t index)const;

 public:
  /// <summary>
  ///  ��������� ����������� �����������.
  /// </summary>
  //! \param[in] x
  bool equal(const self_type& x)const;

  bool equal(pointer str,size_t size)const;
};//class t_basic_const_str_box

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef t_basic_const_str_box<char>    t_const_str_box;

typedef t_basic_const_str_box<wchar_t> t_const_wstr_box;

////////////////////////////////////////////////////////////////////////////////
//factory

template<typename charT>
t_basic_const_str_box<charT> make_str_box(const charT* const s,size_t const n);

//------------------------------------------------------------------------
template<typename charT>
t_basic_const_str_box<charT> make_str_box(const charT* const s);

//------------------------------------------------------------------------
template<typename charT,typename Traits,typename Allocator>
t_basic_const_str_box<charT> make_str_box(const std::basic_string<charT,Traits,Allocator>& s);

////////////////////////////////////////////////////////////////////////////////

template<class charT>
bool equal_to_string(const t_basic_const_str_box<charT>& strBox,
                     const charT*                const   sz_s)
{
 return equal_to_string(strBox.begin(),strBox.end(),sz_s);
}//equal_to_string

//------------------------------------------------------------------------
template<class charT,class EqBinaryOp>
bool equal_to_string(const t_basic_const_str_box<charT>& strBox,
                     const charT*                const   sz_s,
                     EqBinaryOp                          eq_op)
{
 return equal_to_string(strBox.begin(),strBox.end(),sz_s,eq_op);
}//equal_to_string

////////////////////////////////////////////////////////////////////////////////

template<class charT>
t_basic_const_str_box<charT>
 trim(const t_basic_const_str_box<charT>& str);

////////////////////////////////////////////////////////////////////////////////

//GENERIC
template<class TContainer,class charT>
size_t create_strings2(TContainer&                  container,
                       t_basic_const_str_box<charT> t)
{
 return __create_strings2(container,t.begin(),t.end());
}//create_strings2

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_const_str_box.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
