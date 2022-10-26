////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 18.10.2022.
#ifndef _cpp_public_lcpi_lib_structure_debug__t_debug__unique_instance_id_H_
#define _cpp_public_lcpi_lib_structure_debug__t_debug__unique_instance_id_H_

#include <lcpi/lib/structure/mt/interlocked.h>

namespace lcpi{namespace lib{namespace structure{namespace debug{
////////////////////////////////////////////////////////////////////////////////
//class t_debug__unique_instance_id

template<class TInstanceGroup,typename TID,TID InitialValue=TID()>
class t_debug__unique_instance_id
{
 public:
  t_debug__unique_instance_id()
   :m_value(mt::interlocked::increment(&sm_generator))
  {
  }

  //interface ------------------------------------------------------------
  TID get_value()const
  {
   return m_value;
  }//get_value

  static TID get_generator_value()
  {
   return sm_generator;
  }//get_generator_value

 private:
  TID const m_value;

 private:
  static TID volatile sm_generator;
};//class t_debug__unique_instance_id

template<class TInstanceGroup,typename TID,TID InitialValue=TID()>
TID volatile t_debug__unique_instance_id<TInstanceGroup,TID,InitialValue>::sm_generator=InitialValue;

////////////////////////////////////////////////////////////////////////////////
}/*nms debug*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#endif
