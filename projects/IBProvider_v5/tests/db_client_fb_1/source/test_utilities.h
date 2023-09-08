////////////////////////////////////////////////////////////////////////////////
#ifndef _test_utilities_H_
#define _test_utilities_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////

std::string TSO_GenerateTimeStampString();

//------------------------------------------------------------------------
std::wstring TSO_GenerateNewDatabaseFileName();

//------------------------------------------------------------------------
std::string TSO_BuildFilePath(const std::string& Path,
                              const std::string& FileName);

//------------------------------------------------------------------------
void TSO_PrintException(TTSO_Tracer&          tracer,
                        const std::exception& exc);

//------------------------------------------------------------------------
std::string TSO_TimeToStr(__int64 t);

//------------------------------------------------------------------------
std::string TSO_TimeToStrEx(__int64 t);

//------------------------------------------------------------------------
std::string TSO_MemSizeToStrEx_KB(unsigned __int64 sz);

//------------------------------------------------------------------------
std::string TSO_MemSizeToStrEx2_KB(bool ok,unsigned __int64 sz);

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
