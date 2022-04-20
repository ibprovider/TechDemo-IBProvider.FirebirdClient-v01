////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_jis_traits.h
//! \brief   Алгоритмы преобразования кодовых страниц SJIS_0208 и EUCJ_0208
//! \author  Kovalenko Dmitry
//! \date    30.09.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_jis_traits.h"
#include <structure/t_numeric_cast.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////

namespace cs_data_JIS_0208{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_jis_0208_1990.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_JIS_0208

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_jis_0208_traits_base

const t_ibp_cs_jis_0208_traits_base::ushort_type* const
 t_ibp_cs_jis_0208_traits_base::sm_jis__to_unicode_mapping_array
  =cs_data_JIS_0208::to_unicode_mapping_array;

const t_ibp_cs_jis_0208_traits_base::size_type
 t_ibp_cs_jis_0208_traits_base::sm_jis__to_unicode_mapping_array_size
  =_DIM_(cs_data_JIS_0208::to_unicode_mapping_array);

const t_ibp_cs_jis_0208_traits_base::ushort_type* const
 t_ibp_cs_jis_0208_traits_base::sm_jis__to_unicode_map
  =cs_data_JIS_0208::to_unicode_map;

const t_ibp_cs_jis_0208_traits_base::size_type
 t_ibp_cs_jis_0208_traits_base::sm_jis__to_unicode_map_size
  =_DIM_(cs_data_JIS_0208::to_unicode_map);

const t_ibp_cs_jis_0208_traits_base::ushort_type* const
 t_ibp_cs_jis_0208_traits_base::sm_jis__from_unicode_mapping_array
  =cs_data_JIS_0208::from_unicode_mapping_array;

const t_ibp_cs_jis_0208_traits_base::size_type
 t_ibp_cs_jis_0208_traits_base::sm_jis__from_unicode_mapping_array_size
  =_DIM_(cs_data_JIS_0208::from_unicode_mapping_array);

const t_ibp_cs_jis_0208_traits_base::ushort_type* const
 t_ibp_cs_jis_0208_traits_base::sm_jis__from_unicode_map
  =cs_data_JIS_0208::from_unicode_map;

const t_ibp_cs_jis_0208_traits_base::size_type
 t_ibp_cs_jis_0208_traits_base::sm_jis__from_unicode_map_size
  =_DIM_(cs_data_JIS_0208::from_unicode_map);

namespace cs_data_SJIS_0208{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_sjis.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_SJIS_0208

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_sjis_0208_traits

const t_ibp_cs_sjis_0208_traits::ushort_type* const
 t_ibp_cs_sjis_0208_traits::sm_sjis__to_unicode_mapping_array
  =cs_data_SJIS_0208::sjis_to_unicode_mapping_array;

const t_ibp_cs_sjis_0208_traits::size_type
 t_ibp_cs_sjis_0208_traits::sm_sjis__to_unicode_mapping_array_size
  =_DIM_(cs_data_SJIS_0208::sjis_to_unicode_mapping_array);

const t_ibp_cs_sjis_0208_traits::ushort_type* const
 t_ibp_cs_sjis_0208_traits::sm_sjis__to_unicode_map
  =cs_data_SJIS_0208::sjis_to_unicode_map;

const t_ibp_cs_sjis_0208_traits::size_type
 t_ibp_cs_sjis_0208_traits::sm_sjis__to_unicode_map_size
  =_DIM_(cs_data_SJIS_0208::sjis_to_unicode_map);

const t_ibp_cs_sjis_0208_traits::ushort_type* const
 t_ibp_cs_sjis_0208_traits::sm_sjis__from_unicode_mapping_array
  =cs_data_SJIS_0208::sjis_from_unicode_mapping_array;

const t_ibp_cs_sjis_0208_traits::size_type
 t_ibp_cs_sjis_0208_traits::sm_sjis__from_unicode_mapping_array_size
  =_DIM_(cs_data_SJIS_0208::sjis_from_unicode_mapping_array);

const t_ibp_cs_sjis_0208_traits::ushort_type* const
 t_ibp_cs_sjis_0208_traits::sm_sjis__from_unicode_map
  =cs_data_SJIS_0208::sjis_from_unicode_map;

const t_ibp_cs_sjis_0208_traits::size_type
 t_ibp_cs_sjis_0208_traits::sm_sjis__from_unicode_map_size
  =_DIM_(cs_data_SJIS_0208::sjis_from_unicode_map);

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_sjis_0208_traits

void t_ibp_cs_sjis_0208_traits::S2E(const uchar_type  s1,
                                    const uchar_type  s2,
                                    uchar_type* const j1,
                                    uchar_type* const j2)
{
 assert(j1);
 assert(j2);

 if(s2>=0x9f)
 {
  if(s1>=0xe0)
   (*j1)=uchar_type(s1*2-0xe0);
  else
  {
   (*j1)=uchar_type(s1*2-0x60);
  }

  (*j2)=uchar_type(s2+2);
 }
 else
 {
  if(s1>=0xe0)
   (*j1)=uchar_type(s1*2-0xe1);
  else
   (*j1)=uchar_type(s1*2-0x61);

  if(s2>=0x7f)
   (*j2)=uchar_type(s2+0x60);
  else
   (*j2)=uchar_type(s2+0x61);
 }//else
}//S2E

//------------------------------------------------------------------------
void t_ibp_cs_sjis_0208_traits::Seven2Eight(uchar_type* s1,uchar_type* s2)
{
 assert(s1);
 assert(s2);

 ushort_type p1=*s1;
 ushort_type p2=*s2;

 if(IsODD(p1))
  p2=ushort_type(p2+31);
 else
  p2=ushort_type(p2+126);

 if((p2>=127) && (p2<158))
   ++p2;

 if((p1>=33) && (p1<=94))
 {
  if(IsODD(p1))
  {
   p1=ushort_type(((p1-1)/2)+113);
  }
  else
  {
   //! \note IBP Specific. FB has this assert as IF(!IsODD(p1))
   assert(!IsODD(p1));

   p1=ushort_type((p1/2)+112);
  }//else
 }
 else
 if((p1>=95) && (p1<=126))
 {
  if(IsODD(p1))
  {
   p1=ushort_type(((p1-1)/2)+177);
  }
  else
  {
   //! \note IBP Specific. FB has this assert as IF(!IsODD(p1))
   assert(!IsODD(p1));

   p1=ushort_type((p1/2)+176);
  }//else
 }//if

 structure::static_numeric_cast(s1,p1);
 structure::static_numeric_cast(s2,p2);
}//Seven2Eight

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
