////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 17.07.2019.
#ifndef _lcpi_infrastructure_core_structure__t_not_null_ptr_CC_
#define _lcpi_infrastructure_core_structure__t_not_null_ptr_CC_

#include <lcpi/infrastructure/core/.config.h>

#include <assert.h>

namespace lcpi{namespace infrastructure{namespace core{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_not_null_ptr

template<typename T>
class t_not_null_ptr final
{
 public:
  using pointer=T*;

 public:
  t_not_null_ptr(pointer const p)
   :m_ptr(p)
  {
   assert(m_ptr);
  }

  operator pointer () const
  {
   assert(m_ptr);

   return m_ptr;
  }//operator pointer

  pointer operator -> () const
  {
   assert(m_ptr);

   return m_ptr;
  }//operator ->

  pointer ptr() const
  {
   assert(m_ptr);

   return m_ptr;
  }//ptr

 private:
  pointer m_ptr;
};//class t_not_null_ptr

////////////////////////////////////////////////////////////////////////////////

template<typename T>
inline t_not_null_ptr<T> not_null_ptr(T* const p)
{
 return t_not_null_ptr<T>(p);
}//not_null_ptr

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms core*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
