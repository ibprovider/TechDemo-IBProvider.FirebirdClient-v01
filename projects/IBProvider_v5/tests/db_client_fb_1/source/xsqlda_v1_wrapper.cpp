////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/xsqlda_v1_wrapper.h"
#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class XSQLDA_V1_Wrapper

XSQLDA_V1_Wrapper::XSQLDA_V1_Wrapper(size_t const n)
 :m_pv(nullptr)
{
 this->alloc(n);
}//XSQLDA_V1_Wrapper

//------------------------------------------------------------------------
XSQLDA_V1_Wrapper::~XSQLDA_V1_Wrapper()
{
 TTSO_MemoryAllocator().deallocate(m_pv,0);
}//~XSQLDA_V1_Wrapper

//------------------------------------------------------------------------
XSQLDA_V1_Wrapper::pointer XSQLDA_V1_Wrapper::operator -> () const
{
 assert(m_pv!=nullptr);

 return this->ptr();
}//operator ->

//------------------------------------------------------------------------
XSQLDA_V1_Wrapper::operator XSQLDA_V1_Wrapper::pointer () const
{
 return this->ptr();
}//operator pointer

//------------------------------------------------------------------------
XSQLDA_V1_Wrapper::pointer XSQLDA_V1_Wrapper::ptr() const
{
 return reinterpret_cast<pointer>(m_pv);
}//ptr

//------------------------------------------------------------------------
void XSQLDA_V1_Wrapper::alloc(size_t const n)
{
 if(!structure::can_numeric_cast<short>(n))
 {
  assert_msg(false,"incorrect n="<<n);

  structure::str_formatter
   fmsg("incorrect number of XSQLVAR elements: %1.");

  fmsg<<n;

  throw std::runtime_error(fmsg.str());
 }//if

 size_t sz=sizeof(isc_api::XSQLDA_V1)-sizeof(isc_api::XSQLVAR_V1);

 sz+=n*sizeof(isc_api::XSQLVAR_V1);

 void* const pv=TTSO_MemoryAllocator().allocate(sz);

 assert(pv);

 delete m_pv;

 m_pv=pv;

 memset(m_pv,0,sz);

 this->ptr()->version=1;

 this->ptr()->sqln=static_cast<short>(n);
}//alloc

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
