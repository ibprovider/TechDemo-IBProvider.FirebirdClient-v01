////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. Helper for work with tracers
//                                             Kovalenko Dmitry. 14.09.2011.
#ifndef _test_tracer_utils_H_
#define _test_tracer_utils_H_

#include <structure/test_obj/fw/set01/test_fw_set01__tracer_utils.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class tag_tso_tracer_data_or_na

template<class TData>
using tag_tso_tracer_data_or_na
 =structure::test_fw::set01::TestFW__Basic_TraceDataOrNA<TData>;

////////////////////////////////////////////////////////////////////////////////

template<class TData>
tag_tso_tracer_data_or_na<TData>
 ibp_tso_trace_data_or_na(bool ok,const TData& data)
{
 return tag_tso_tracer_data_or_na<TData>(ok,data);
}//ibp_tso_trace_data_or_na

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
