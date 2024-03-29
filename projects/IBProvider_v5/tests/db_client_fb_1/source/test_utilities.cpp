////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_utilities.h"
#include <sstream>
#include <iomanip>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////

std::wstring TSO_GenerateNewDatabaseFileName()
{
 GUID guid;

 if(::UuidCreate(&guid)!=RPC_S_OK)
  throw std::runtime_error("Can't generate uuid");

 std::basic_stringstream<wchar_t> oss;

 oss<<L"IBP_TEST_";

 const BYTE* const pb=reinterpret_cast<const BYTE*>(&guid);
 const BYTE* const pe=pb+sizeof(guid);

 for(const BYTE* p=pb;p!=pe;++p)
 {
  oss<<std::setfill(L'0')<<std::setw(2)<<std::hex<<std::uppercase<<long(*p);
 }//for

 oss<<L".GDB";

 return oss.str();
}//TSO_GenerateNewDatabaseFileName

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
