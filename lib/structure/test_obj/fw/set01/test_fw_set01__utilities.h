////////////////////////////////////////////////////////////////////////////////
//Test FrameWork. SET01.
//                                                Kovalenko Dmitry. 07.12.2017.
#ifndef _test_fw_set01__utilities_H_
#define _test_fw_set01__utilities_H_

#include <structure/test_obj/t_tso_lib.h>
#include <structure/error/t_err_records.h>

#include <structure/utilities/string/trim.h>

namespace structure{namespace test_fw{namespace set01{
////////////////////////////////////////////////////////////////////////////////

std::string TestFW__GenerateTimeStampString();

//------------------------------------------------------------------------
template<typename charT>
LCPI_STL_DEF_BASIC_STRING(charT)
 TestFW__BuildFilePath(const LCPI_STL_DEF_BASIC_STRING(charT)& Path,
                       const LCPI_STL_DEF_BASIC_STRING(charT)& FileName);

//------------------------------------------------------------------------
std::string TestFW__TimeToStr(std::int64_t t);

//------------------------------------------------------------------------
std::string TestFW__TimeToStrEx(std::int64_t t);

//------------------------------------------------------------------------
std::string TestFW__MemSizeToStrEx_KB(std::uint64_t sz);

//------------------------------------------------------------------------
std::string TestFW__MemSizeToStrEx2_KB(bool ok,std::uint64_t sz);

////////////////////////////////////////////////////////////////////////////////

template<class TTracer>
void TestFW__PrintException(TTracer&              tracer,
                            const std::exception& exc);

////////////////////////////////////////////////////////////////////////////////

template<typename charT>
LCPI_STL_DEF_BASIC_STRING(charT)
 TestFW__BuildFilePath(const LCPI_STL_DEF_BASIC_STRING(charT)& Path,
                       const LCPI_STL_DEF_BASIC_STRING(charT)& FileName)
{
 LCPI_STL_DEF_BASIC_STRING(charT) x;

 x.reserve(Path.size()+FileName.size()+1);

 x+=Path;

 structure::self_trim(x);

 if(x.empty())
  return FileName;

 switch(x.back())
 {
  case '\\':
  case '/':
   break;

  default:
   x+=charT('\\');
   break;
 }//switch

 return x.append(FileName);
}//TestFW__BuildFilePath

////////////////////////////////////////////////////////////////////////////////

template<class TTracer>
void TestFW__PrintException(TTracer&              tracer,
                            const std::exception& exc)
{
 if(const structure::t_err_records_r* const errs=dynamic_cast<const structure::t_err_records_r*>(&exc))
 {
  structure::t_err_record::string_type err_source;
  structure::t_err_record::string_type err_descr;

  structure::t_err_record::lcid_type lcid(::GetUserDefaultLCID());

  for(size_t i(0),_c(errs->get_record_count());i!=_c;++i)
  {
   const structure::t_err_record::self_ptr err(errs->get_record(i));

   err->get_description(lcid,&err_source,&err_descr);

   tracer<<(i+1)<<L". ["<<err_source<<L"] "<<err_descr<<tso_obj::send;
  }//for
 }//if
 else
 {
  tracer<<exc.what()<<tso_obj::send;
 }//else
}//TestFW__PrintException

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms test_fw*/}/*nms structure*/
#endif
