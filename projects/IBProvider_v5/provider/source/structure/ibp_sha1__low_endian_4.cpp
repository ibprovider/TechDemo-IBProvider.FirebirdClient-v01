////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_sha1__low_endian_4.cpp
//! \brief   Класс для работы с SHA1
//! \author  Kovalenko Dmitry
//! \date    01.06.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/structure/ibp_sha1.h"

namespace lcpi{namespace ibp{namespace sha1{
////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha1

void IBP_Sha1::helper__sha_transform__build_W(W_TYPE& W)const
{
#if(IBP_BYTE_ORDER!=IBP_BYTE_ORDER__LOW_ENDIAN)
# error Incorrect Byte Order!
#endif

 assert_s(sizeof(SHA_ULONG)==4);

 assert_s(sizeof(m_handle.data)==64);

 const unsigned char* dp=m_handle.data;

 for(unsigned i=0;i!=16;++i)
 {
  assert(dp!=_END_(m_handle.data));

  SHA_ULONG T=(*dp);

  ++dp;

  T<<=8;

  //-----------
  assert(dp!=_END_(m_handle.data));

  T|=(*dp);

  ++dp;

  T<<=8;

  //-----------
  assert(dp!=_END_(m_handle.data));

  T|=(*dp);

  ++dp;

  T<<=8;

  //-----------
  assert(dp!=_END_(m_handle.data));

  T|=(*dp);

  ++dp;

  //-----------
  W[i]=T;
 }//for i

 assert(dp==_END_(m_handle.data));
}//helper__sha_transform__build_W

////////////////////////////////////////////////////////////////////////////////
}/*nms sha1*/}/*nms ibp*/}/*nms lcpi*/
