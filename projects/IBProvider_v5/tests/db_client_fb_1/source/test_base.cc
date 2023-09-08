////////////////////////////////////////////////////////////////////////////////
#ifndef _test_base_CC_
#define _test_base_CC_

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TTSO_Basic_TracerAutoSend

template<class TTracer>
TTSO_Basic_TracerAutoSend<TTracer>::TTSO_Basic_TracerAutoSend(tracer_type& tracer)
 :m_tracer(tracer)
{;}

//------------------------------------------------------------------------
template<class TTracer>
TTSO_Basic_TracerAutoSend<TTracer>::~TTSO_Basic_TracerAutoSend()
{
 m_tracer.send();
}//~TTSO_Basic_TracerAutoSend

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
