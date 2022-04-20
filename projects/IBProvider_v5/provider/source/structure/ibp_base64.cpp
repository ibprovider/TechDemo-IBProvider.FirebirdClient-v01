////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_base64.cpp
//! \brief   Класс для работы с BASE64
//! \author  Kovalenko Dmitry
//! \date    03.07.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/structure/ibp_base64.h"
#include <structure/t_limits.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

static char g_IBP_bin2ascii[64]=
{
 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
 '0','1','2','3','4','5','6','7','8','9','+','/'
};//g_IBP_bin2ascii

////////////////////////////////////////////////////////////////////////////////

static char conv_bin2ascii(unsigned __int32 const v)
{
 assert_s(_DIM_(g_IBP_bin2ascii)==64);

 const unsigned __int32 x=(v&0x3F);

 assert_hint(x<_DIM_(g_IBP_bin2ascii));

 return g_IBP_bin2ascii[x];
}//conv_bin2ascii

////////////////////////////////////////////////////////////////////////////////

void IBP_OctetsToBase64(std::string* const result,
                        size_t       const cbOctets,
                        const void*  const pOctets)
{
 assert(result);

 CHECK_READ_PTR(pOctets,cbOctets);

 result->erase();

 {
  const size_t max_np1=(structure::t_numeric_limits<size_t>::max_value()/4);

  const size_t max_np2=(max_np1*3);

  if(cbOctets>max_np2)
   throw std::bad_alloc();

  assert_hint(cbOctets<=max_np2);

  assert(cbOctets<structure::t_numeric_limits<size_t>::max_value());

  assert(2<=(structure::t_numeric_limits<size_t>::max_value()-cbOctets));

  result->reserve(((cbOctets+2)/3)*4); //throw
 }//local

 //-----------
 size_t cb=cbOctets;

 const unsigned char* p=reinterpret_cast<const unsigned char*>(pOctets);

 for(;;)
 {
  typedef unsigned __int32 v_type;

  if(cb>=3)
  {
   v_type v=(v_type(*p)<<16);
   
   ++p;
   
   v|=(v_type(*p)<<8);
   
   ++p;
   
   v|=(*p);

   ++p;

   cb-=3;

   //-------
   (*result)+=conv_bin2ascii(v>>18);
   (*result)+=conv_bin2ascii(v>>12);
   (*result)+=conv_bin2ascii(v>>6);
   (*result)+=conv_bin2ascii(v);
   
   continue;
  }//if cb>=3

  assert_hint(cb<3);

  if(cb==2)
  {
   v_type v=(v_type(*p)<<16);
   
   ++p;

   v|=(v_type(*p)<<8);

   //опускаем последние операции
   //++p;

   //cb-=2;

   //-------
   (*result)+=conv_bin2ascii(v>>18);
   (*result)+=conv_bin2ascii(v>>12);
   (*result)+=conv_bin2ascii(v>>6);
   (*result)+='=';
   
   break;
  }//if cb==2

  assert_hint(cb<2);

  if(cb==1)
  {
   v_type v=(v_type(*p)<<16);
   
   //опускаем последние операции
   //++p;

   //cb-=1;

   //-------
   (*result)+=conv_bin2ascii(v>>18);
   (*result)+=conv_bin2ascii(v>>12);
   (*result)+='=';
   (*result)+='=';
   
   break;
  }//if cb==1

  assert_hint(cb==0);

  break;
 }//for[ever]

 assert((result->size()%4)==0);
}//IBP_OctetsToBase64

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/

