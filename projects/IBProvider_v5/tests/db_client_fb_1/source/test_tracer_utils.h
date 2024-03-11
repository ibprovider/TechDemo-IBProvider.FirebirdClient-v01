////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. Helper for work with tracers
//                                             Kovalenko Dmitry. 14.09.2011.
#ifndef _test_tracer_utils_H_
#define _test_tracer_utils_H_

#include <ole_lib/oledb/variant/oledb_variant.h>
#include <structure/test_obj/t_tso_lib.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class tag_tso_tracer_data_or_na

template<class TData>
class tag_tso_tracer_data_or_na LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_tso_tracer_data_or_na<TData>;

  self_type& operator = (const self_type&)=delete;

 public:
  tag_tso_tracer_data_or_na(bool ok,const TData& data)
   :m_data(data),
    m_ok  (ok)
  {;}

  tag_tso_tracer_data_or_na(const self_type& x)
   :m_data (x.m_data),
    m_ok   (x.m_ok)
  {;}

  //selectors ------------------------------
  const TData& data()const
  {
   return m_data;
  }

  bool ok()const
  {
   return m_ok;
  }

 private:
  TData m_data;
  bool  m_ok;
};//class tag_tso_tracer_data_or_na

////////////////////////////////////////////////////////////////////////////////

template<class Allocator,class TData>
structure::tso_obj::t_basic_tracer<Allocator>&
 operator << (structure::tso_obj::t_basic_tracer<Allocator>& tracer,
              const tag_tso_tracer_data_or_na<TData>&    x)
{
 if(x.ok())
  return tracer<<x.data();

 return tracer<<L"n/a";
}//operator <<

////////////////////////////////////////////////////////////////////////////////

template<class TData>
tag_tso_tracer_data_or_na<TData>
 ibp_tso_trace_data_or_na(bool ok,const TData& data)
{
 return tag_tso_tracer_data_or_na<TData>(ok,data);
}//ibp_tso_trace_data_or_na

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/test_tracer_utils.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
