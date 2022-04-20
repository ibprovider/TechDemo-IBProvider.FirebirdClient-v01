////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_sha2.cc
//! \brief   Класс для работы с SHA2
//! \author  Kovalenko Dmitry
//! \date    29.05.2019
#ifndef _ibp_sha2_CC_
#define _ibp_sha2_CC_

namespace lcpi{namespace ibp{namespace sha2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha2_Base

template<class SHA_TRAITS>
IBP_Sha2_Base<SHA_TRAITS>::IBP_Sha2_Base()
{
 this->reset();
}//IBP_Sha2_Base

//------------------------------------------------------------------------
template<class SHA_TRAITS>
IBP_Sha2_Base<SHA_TRAITS>::~IBP_Sha2_Base()
{
}//~IBP_Sha2_Base

//------------------------------------------------------------------------
template<class SHA_TRAITS>
void IBP_Sha2_Base<SHA_TRAITS>::reset()
{
 m_state=self_type::state__active;

 return SHA_TRAITS::sha_init(&m_ctx);
}//reset

//------------------------------------------------------------------------
template<class SHA_TRAITS>
void IBP_Sha2_Base<SHA_TRAITS>::process(size_t const length,const void* const bytes)
{
 assert(m_state==self_type::state__active);

 return SHA_TRAITS::sha_update(&m_ctx,length, static_cast<const unsigned char*>(bytes));
}//process

//------------------------------------------------------------------------
template<class SHA_TRAITS>
void IBP_Sha2_Base<SHA_TRAITS>::process_str(structure::t_const_str_box const str)
{
 assert(m_state==self_type::state__active);

 return SHA_TRAITS::sha_update(&m_ctx,str.byte_count(),reinterpret_cast<const unsigned char*>(str.data()));
}//process_str

//------------------------------------------------------------------------
template<class SHA_TRAITS>
void IBP_Sha2_Base<SHA_TRAITS>::get_hash(SHA_RESULT* const hash)
{
 assert(hash);

 assert(m_state==self_type::state__active);

 m_state=self_type::state__finished;

 SHA_TRAITS::sha_final(&m_ctx,hash);

 SHA_TRAITS::sha_clear(&m_ctx);
}//get_hash

////////////////////////////////////////////////////////////////////////////////
}/*nms sha2*/}/*nms ibp*/}/*nms lcpi*/
#endif
