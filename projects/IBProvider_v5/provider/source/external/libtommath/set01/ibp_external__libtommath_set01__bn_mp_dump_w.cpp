////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/libtommath/set01/ibp_external__libtommath_set01__tommath_private.h"
#include <sstream>

namespace lcpi{namespace ibp{namespace external{namespace libtommath{namespace set01{
////////////////////////////////////////////////////////////////////////////////

std::wstring mp_dump_w(const mp_int* const x)
{
 DEBUG_CODE(mp_debug__check_int__light(x);)

 if(x==nullptr)
  return L"NULL";

 std::wostringstream s;

 //public:
 // size_type used;
 //
 // size_type alloc;
 //
 // sign_type sign;
 //
 // mp_digit* dp;

 s<<L"{used="<<x->used
  <<L"; alloc="<<x->alloc;

 switch(x->sign)
 {
  case MP_ZPOS:
   s<<L"; sign=MP_ZPOS";
   break;

  case MP_NEG:
   s<<L"; sign=MP_NEG";
   break;

  default:
   s<<L"; sign="<<int(x->sign);
   break;
 }//switch

 if(x->dp==nullptr)
 {
  s<<L"; dp=NULL}";
 }
 else
 if(x->used<=x->alloc)
 {
  s<<L"; dp={";

  size_t i=0;

  for(;i!=x->used;++i)
  {
   if(i>0)
    s<<L", ";

   s<<x->dp[i];
  }//for i

  s<<L"}{";

  //data from reserved space
  for(const size_t start_i=i;i!=x->alloc;++i)
  {
   if(i>start_i)
    s<<L", ";

   s<<x->dp[i];
  }//for i

  s<<L"}}";
 }
 else
 {
  assert_hint(x->alloc<x->used); //incorrect state!

  s<<L"; dp={";

  size_t i=0;

  for(;i!=x->alloc;++i)
  {
   if(i>0)
    s<<L", ";

   s<<x->dp[i];
  }//for i

  s<<L"}}";
 }//else

 return s.str();
}//mp_dump_w

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
