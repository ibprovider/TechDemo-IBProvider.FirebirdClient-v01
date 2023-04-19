////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_check_errors.h"
#include "source/test_utilities.h"
#include "source/error_services/ibp_error_element.h"
#include "source/Version/ibp_v05_info_data.h"

#include <structure/charsets/t_cs_utf8.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestCheckErrors

const char TestCheckErrors::sm_srcID__IBProvider[]
 ="LCPI.IBProvider.5";

//------------------------------------------------------------------------
const char TestCheckErrors::sm_srcID__UnknownDBMS[]
 ="Unknown DBMS";

//------------------------------------------------------------------------
const wchar_t TestCheckErrors::sm_subsysID__remote_fb[]
 =L"remote_fb";

//------------------------------------------------------------------------
const wchar_t TestCheckErrors::sm_subsysID__remote_fb_inet[]
 =L"remote_fb.inet";

//------------------------------------------------------------------------
const wchar_t TestCheckErrors::sm_subsysID__remote_fb_p10[]
 =L"remote_fb.p10";

//------------------------------------------------------------------------
const wchar_t TestCheckErrors::sm_subsysID__remote_fb_p11[]
 =L"remote_fb.p11";

//------------------------------------------------------------------------
const wchar_t TestCheckErrors::sm_subsysID__remote_fb_p12[]
 =L"remote_fb.p12";

//------------------------------------------------------------------------
const wchar_t TestCheckErrors::sm_subsysID__remote_fb_p13[]
 =L"remote_fb.p13";

//------------------------------------------------------------------------
const wchar_t TestCheckErrors::sm_subsysID__remote_fb_pset01[]
 =L"remote_fb.pset01";

//------------------------------------------------------------------------
const wchar_t TestCheckErrors::sm_subsysID__remote_fb_pset02[]
 =L"remote_fb.pset02";

////////////////////////////////////////////////////////////////////////////////

void TestCheckErrors::print_exception_ok(TTSO_Tracer&          tracer,
                                            const std::exception& exc)
{
 tracer<<"OK. We got the error."<<send;

 TSO_PrintException(tracer,exc);
}//print_exception_ok

////////////////////////////////////////////////////////////////////////////////

void TestCheckErrors::check_err_count(const structure::t_err_records_r& errs,
                                      size_t                    const   reqCount)
{
 const size_t actualCount=errs.get_record_count();

 if(actualCount==reqCount)
  return;

 structure::str_formatter fmsg("Incorrect error record count: %1. Expected: %2.");

 fmsg<<actualCount<<reqCount;

 throw std::runtime_error(fmsg.str());
}//check_err_count

////////////////////////////////////////////////////////////////////////////////

void TestCheckErrors::check_err_code(HRESULT actualHResult,
                                     HRESULT expectedHResult)
{
 if(actualHResult!=expectedHResult)
 {
  structure::str_formatter fmsg("actual HResult: %1. expected HResult: %2.");

  fmsg<<ole_lib::TestHResult(actualHResult)
      <<ole_lib::TestHResult(expectedHResult);

  throw std::runtime_error(fmsg.str());
 }//if
}//check_err_code

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__source(TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2Source)
{
 assert(pErrorRec);

 bool resultValue=true;

 //-----------------------------------------
 if(!self_type::error_rec__check_source
      (tracer,
       pErrorRec,
       self_type::lcid__RUS,
       ucs2Source))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 if(!self_type::error_rec__check_source
      (tracer,
       pErrorRec,
       self_type::lcid__ENG,
       ucs2Source))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 return resultValue;
}//check_err_rec__partially

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__partially(TTSO_Tracer&                         tracer,
                                               const structure::t_err_record* const pErrorRec,
                                               wstr_box_type                  const ucs2Source,
                                               wstr_box_type                  const ucs2MsgPart)
{
 assert(pErrorRec);

 bool resultValue=true;

 //-----------------------------------------
 if(!self_type::error_rec__check_partial_data
      (tracer,
       pErrorRec,
       self_type::lcid__RUS,
       ucs2Source,
       ucs2MsgPart))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 if(!self_type::error_rec__check_partial_data
      (tracer,
       pErrorRec,
       self_type::lcid__ENG,
       ucs2Source,
       ucs2MsgPart))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 return resultValue;
}//check_err_rec__partially

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec(TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2Source,
                                    wstr_box_type                  const ucs2Msg)
{
 assert(pErrorRec);

 bool resultValue=true;

 //-----------------------------------------
 if(!self_type::error_rec__check_data
      (tracer,
       pErrorRec,
       self_type::lcid__RUS,
       ucs2Source,
       ucs2Msg))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 if(!self_type::error_rec__check_data
      (tracer,
       pErrorRec,
       self_type::lcid__ENG,
       ucs2Source,
       ucs2Msg))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 return resultValue;
}//check_err_rec

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__bug_check
                                   (TTSO_Tracer&                   tracer,
                                    const structure::t_err_record* pErrorRec,
                                    wstr_box_type                  ucs2Place,
                                    wstr_box_type                  ucs2Point,
                                    wstr_box_type                  ucs2Reason)
{
 return helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          ucs2Reason);
}//check_err_rec__bug_check

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__common_err__formed_buf_is_too_large
                                   (TTSO_Tracer&                   tracer,
                                    const structure::t_err_record* pErrorRec,
                                    wstr_box_type                  ucs2_SubSystemID,
                                    wstr_box_type                  ucs2_BufName,
                                    size_t                         buf_size,
                                    size_t                         max_size)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Сформированный буфер с параметрами [%2] слишком велик: %3. Максимально допустимая длина равна [%4].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<ucs2_BufName<<buf_size<<max_size;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Formed buffer with parameters [%2] is too large: %3. Max allowed length equal to [%4].");

  msgEng<<ucs2_SubSystemID<<ucs2_BufName<<buf_size<<max_size;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__common_err__formed_buf_is_too_large

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__bug_check__unknown_property_value
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const place,
                                    wstr_box_type                  const point,
                                    wstr_box_type                  const propName,
                                    wstr_box_type                  const propValue)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter freason(L"unknown value [%2] in [%1] setting");

 freason<<propName<<propValue;

 return helper__bug_check
          (tracer,
           pErrorRec,
           place,
           point,
           freason.str());
}//check_err_rec__bug_check__unknown_property_value

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__direct_fb__bad_format_of_str_for_inet_cn_to_db
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Некорректный формат строки INET-подключения к базе данных.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Incorrect format of string for INET-connection to database.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__direct_fb__bad_format_of_str_for_inet_cn_to_db

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__direct_fb__bad_format_of_str_for_inet_cn_to_db__no_port
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2_SubSystemID,
                                    wstr_box_type                  const ucs2_host_sign)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Некорректный формат строки INET-подключения к базе данных на хосте [%2]. Не определен порт подключения.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<ucs2_host_sign;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Incorrect format of string for INET-connection to database on host [%2]. Connection port not defined.");

  msgEng<<ucs2_SubSystemID<<ucs2_host_sign;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__direct_fb__bad_format_of_str_for_inet_cn_to_db__no_port

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__bug_check__mistake_in_parch_list
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const place,
                                            wstr_box_type                  const point)
{
 return helper__bug_check
          (tracer,
           pErrorRec,
           place,
           point,
           L"mistake in list with protocol architectures");
}//check_err_rec__bug_check__mistake_in_parch_list

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__bug_check__mult_enum_of_parch
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const place,
                                            wstr_box_type                  const point,
                                            wstr_box_type                  const parch_name)
{
 structure::wstr_formatter
  freason(L"multiple enumerations of protocol architecture [%1]");

 freason<<parch_name;

 return helper__bug_check
          (tracer,
           pErrorRec,
           place,
           point,
           freason.str());
}//check_err_rec__bug_check__mult_enum_of_parch

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__bug_check__empty_list_of_parchs
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const place,
                                            wstr_box_type                  const point)
{
 return helper__bug_check
          (tracer,
           pErrorRec,
           place,
           point,
           L"empty list of valid architectures for connection protocol");
}//check_err_rec__bug_check__empty_list_of_parchs

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__unsupported_protocol
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2_SubSystemID,
                                    wstr_box_type                  const ucs2_PName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Запрашиваемый протокол соединения с сервером [%2] не поддерживается.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<ucs2_PName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] The requested connection protocol [%2] not supported.");

  msgEng<<ucs2_SubSystemID<<ucs2_PName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__unsupported_protocol

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__unsupported_protocol_architecture
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2_SubSystemID,
                                    wstr_box_type                  const ucs2_PArchName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Неподдерживаемая архитектура протокола соединения с сервером: %2.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<ucs2_PArchName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Unsupported architecture of server connection protocol: %2.");

  msgEng<<ucs2_SubSystemID<<ucs2_PArchName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__unsupported_protocol_architecture

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec___ibp_mce_remote__requested_protocol_type_not_supported_2
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2_SubSystemID,
                                    wstr_box_type                  const ucs2_PTypehName,
                                    unsigned                       const EstablishedProtocolVersion)
{
 assert(pErrorRec!=nullptr);

 //-----------------------------------------
 const char* const c_templ_EN
  ="[Subsystem: %1] The requested type of server connection protocol [%2] not supported. "
   "Protocol version of established connection: %3.";

 structure::wstr_formatter msgEng
  (utf8_to_wstring(c_templ_EN));

 msgEng<<ucs2_SubSystemID<<ucs2_PTypehName<<EstablishedProtocolVersion;

 //-----------------------------------------
 const char* const c_templ_RU
  ="[Подсистема: %1] Запрашиваемый тип протокола соединения с сервером [%2] не поддерживается. "
   "Версия протокола установленного соединения: %3.";

 structure::wstr_formatter msgRus
  (utf8_to_wstring(c_templ_RU));

 msgRus<<ucs2_SubSystemID<<ucs2_PTypehName<<EstablishedProtocolVersion;

 //-----------------------------------------
 return self_type::TestCheckErrors::error_rec__check_data__EN_RU
         (tracer,
          pErrorRec,
          utf8_to_wstring(self_type::sm_srcID__IBProvider),
          msgEng.str(),
          msgRus.str());
}//check_err_rec___ibp_mce_remote__requested_protocol_type_not_supported_2

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec___ibp_mce_remote__unsupported_protocol_type_2
                                  (TTSO_Tracer&                         tracer,
                                   const structure::t_err_record* const pErrorRec,
                                   wstr_box_type                  const ucs2_SubSystemID,
                                   unsigned                       const EstablishedProtocolVersion,
                                   unsigned                       const ProtocolTypeID)
{
 assert(pErrorRec!=nullptr);

 //-----------------------------------------
 const char* const c_templ_EN
   ="[Subsystem: %1] Unsupported type of server connection protocol: %2. "
    "Protocol version of established connection: %3.";

 structure::wstr_formatter msgEng
  (utf8_to_wstring(c_templ_EN));

 msgEng<<ucs2_SubSystemID<<ProtocolTypeID<<EstablishedProtocolVersion;

 //-----------------------------------------
 const char* const c_templ_RU
  ="[Подсистема: %1] Неподдерживаемый тип протокола соединения с сервером: %2. "
   "Версия протокола установленного соединения: %3.";

 structure::wstr_formatter msgRus
  (utf8_to_wstring(c_templ_RU));

 msgRus<<ucs2_SubSystemID<<ProtocolTypeID<<EstablishedProtocolVersion;

 //-----------------------------------------
 return self_type::TestCheckErrors::error_rec__check_data__EN_RU
         (tracer,
          pErrorRec,
          utf8_to_wstring(self_type::sm_srcID__IBProvider),
          msgEng.str(),
          msgRus.str());
}//check_err_rec___ibp_mce_remote__unsupported_protocol_type_2

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec___ibp_mce_remote__unsupported_protocol_flags_2
                                  (TTSO_Tracer&                         tracer,
                                   const structure::t_err_record* const pErrorRec,
                                   wstr_box_type                  const ucs2_SubSystemID,
                                   unsigned                       const EstablishedProtocolVersion,
                                   unsigned                       const ProtocolFlags)
{
 assert(pErrorRec!=nullptr);

 //-----------------------------------------
 const char* const c_templ_EN
  ="[Subsystem: %1] Unsupported flags of server connection protocol: %2. "
   "Protocol version of established connection: %3.";

 structure::wstr_formatter msgEng
  (utf8_to_wstring(c_templ_EN));

 msgEng<<ucs2_SubSystemID<<ProtocolFlags<<EstablishedProtocolVersion;

 //-----------------------------------------
 const char* const c_templ_RU
  ="[Подсистема: %1] Неподдерживаемые флаги протокола соединения с сервером: %2. "
   "Версия протокола установленного соединения: %3.";

 structure::wstr_formatter msgRus
  (utf8_to_wstring(c_templ_RU));

 msgRus<<ucs2_SubSystemID<<ProtocolFlags<<EstablishedProtocolVersion;

 //-----------------------------------------
 return self_type::TestCheckErrors::error_rec__check_data__EN_RU
         (tracer,
          pErrorRec,
          utf8_to_wstring(self_type::sm_srcID__IBProvider),
          msgEng.str(),
          msgRus.str());
}//check_err_rec___ibp_mce_remote__unsupported_protocol_flags_2

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec___ibp_mce_remote__server_rejected_cn_compression_0
                                  (TTSO_Tracer&                         tracer,
                                   const structure::t_err_record* const pErrorRec,
                                   wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 //-----------------------------------------
 const char* const c_templ_EN
  ="[Subsystem: %1] Server rejected connection data compression.";

 structure::wstr_formatter msgEng
  (utf8_to_wstring(c_templ_EN));

  msgEng<<ucs2_SubSystemID;

 //-----------------------------------------
 const char* const c_templ_RU
  ="[Подсистема: %1] Сервер отклонил сжатие данных подключения.";

 structure::wstr_formatter msgRus
  (utf8_to_wstring(c_templ_RU));

 msgRus<<ucs2_SubSystemID;

 //-----------------------------------------
 return self_type::TestCheckErrors::error_rec__check_data__EN_RU
         (tracer,
          pErrorRec,
          utf8_to_wstring(self_type::sm_srcID__IBProvider),
          msgEng.str(),
          msgRus.str());
}//check_err_rec___ibp_mce_remote__server_rejected_cn_compression_0

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec___ibp_mce_remote__server_required_cn_compression_0
                                  (TTSO_Tracer&                         tracer,
                                   const structure::t_err_record* const pErrorRec,
                                   wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 //-----------------------------------------
 const char* const c_templ_EN
  ="[Subsystem: %1] Server required connection data compression.";

 structure::wstr_formatter msgEng
  (utf8_to_wstring(c_templ_EN));

  msgEng<<ucs2_SubSystemID;

 //-----------------------------------------
 const char* const c_templ_RU
  ="[Подсистема: %1] Сервер требует сжатие данных подключения.";

 structure::wstr_formatter msgRus
  (utf8_to_wstring(c_templ_RU));

 msgRus<<ucs2_SubSystemID;

 //-----------------------------------------
 return self_type::TestCheckErrors::error_rec__check_data__EN_RU
         (tracer,
          pErrorRec,
          utf8_to_wstring(self_type::sm_srcID__IBProvider),
          msgEng.str(),
          msgRus.str());
}//check_err_rec___ibp_mce_remote__server_required_cn_compression_0

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec___ibp_mce_remote__unsupported_wire_compression_type_1
                                  (TTSO_Tracer&                         tracer,
                                   const structure::t_err_record* const pErrorRec,
                                   wstr_box_type                  const ucs2_SubSystemID,
                                   wstr_box_type                  const ucs2_TypeName)
{
 assert(pErrorRec!=nullptr);

 //-----------------------------------------
 const char* const c_templ_EN
  ="[Subsystem: %1] Unsupported connection data compression type: %2.";

 structure::wstr_formatter msgEng
  (utf8_to_wstring(c_templ_EN));

  msgEng<<ucs2_SubSystemID<<ucs2_TypeName;

 //-----------------------------------------
 const char* const c_templ_RU
  ="[Подсистема: %1] Неподдерживаемый тип сжатия данных подключения: %2.";

 structure::wstr_formatter msgRus
  (utf8_to_wstring(c_templ_RU));

 msgRus<<ucs2_SubSystemID<<ucs2_TypeName;

 //-----------------------------------------
 return self_type::TestCheckErrors::error_rec__check_data__EN_RU
         (tracer,
          pErrorRec,
          utf8_to_wstring(self_type::sm_srcID__IBProvider),
          msgEng.str(),
          msgRus.str());
}//check_err_rec___ibp_mce_remote__unsupported_wire_compression_type_1

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec___ibp_mce_remote__wire_compression_not_supported_0
                                  (TTSO_Tracer&                         tracer,
                                   const structure::t_err_record* const pErrorRec,
                                   wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 //-----------------------------------------
 const char* const c_templ_EN
  ="[Subsystem: %1] Compression of connection data not supported.";

 structure::wstr_formatter msgEng
  (utf8_to_wstring(c_templ_EN));

  msgEng<<ucs2_SubSystemID;

 //-----------------------------------------
 const char* const c_templ_RU
  ="[Подсистема: %1] Сжатие данных подключения не поддерживается.";

 structure::wstr_formatter msgRus
  (utf8_to_wstring(c_templ_RU));

 msgRus<<ucs2_SubSystemID;

 //-----------------------------------------
 return self_type::TestCheckErrors::error_rec__check_data__EN_RU
         (tracer,
          pErrorRec,
          self_type::utf8_to_wstring(self_type::sm_srcID__IBProvider),
          msgEng.str(),
          msgRus.str());
}//check_err_rec___ibp_mce_remote__wire_compression_not_supported_0

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__bug_check__cant_convert_auth_service_name_from_utf8_to_wstr
                                  (TTSO_Tracer&                         tracer,
                                   const structure::t_err_record* const pErrorRec,
                                   wstr_box_type                  const place,
                                   wstr_box_type                  const point)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Ошибка конвертирования имени сервиса аутентификации из UTF8 в WSTR. "
    "Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<place<<point;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Failed to convert the name of authentication service from UTF8 to WSTR. "
    L"Check point [%1][%2].");

  msgEng<<place<<point;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__bug_check__cant_convert_auth_service_name_from_utf8_to_wstr

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__bug_check__auth_service_already_was_used
                                  (TTSO_Tracer&                         tracer,
                                   const structure::t_err_record* const pErrorRec,
                                   wstr_box_type                  const place,
                                   wstr_box_type                  const point,
                                   wstr_box_type                  const authServiceName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Повторная установка сервиса аутентификации [%3]. Возможно произошло зацикливание."
    "Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<place<<point<<authServiceName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Authentication service [%3] already was used. We stop the connection for avoid an infinite loop. "
    L"Check point [%1][%2].");

  msgEng<<place<<point<<authServiceName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__bug_check__auth_service_already_was_used

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__bug_check__auth_service_factory_already_was_registered
                                  (TTSO_Tracer&                         tracer,
                                   const structure::t_err_record* const pErrorRec,
                                   wstr_box_type                  const place,
                                   wstr_box_type                  const point,
                                   wstr_box_type                  const authServiceName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Повторная регистрация фабрики сервиса аутентификации [%3]."
    "Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<place<<point<<authServiceName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] The factory of authentication service [%3] already was registered. "
    L"Check point [%1][%2].");

  msgEng<<place<<point<<authServiceName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__bug_check__auth_service_factory_already_was_registered

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__winsock__cant_detect_host_address
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    int                            const winsockError,
                                    wstr_box_type                  const ucs2_host_name,
                                    wstr_box_type                  const ucs2_port_name)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //----------------------------------------
 {
  const char* const c_templ
   ="[winsock] Ошибка определения сетевого адреса хоста [%1][порт: %2]. Ошибка WinSock: %3.";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ));

  msgRus<<ucs2_host_name<<ucs2_port_name<<winsockError;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter
   msgEng(L"[winsock] Failed to detect the network address of the host [%1][port: %2]. WinSock error: %3.");

  msgEng<<ucs2_host_name<<ucs2_port_name<<winsockError;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__winsock__cant_detect_host_address

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__winsock__failed_to_connect_to_server
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    int                            const winsockError,
                                    wstr_box_type                  const ucs2_host,
                                    wstr_box_type                  const ucs2_port,
                                    wstr_box_type                  const ucs2_address,
                                    int                            const socket__family,
                                    int                            const socket__type,
                                    int                            const socket__protocol)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const msgRus
   ("[winsock] Ошибка подключения к серверу [%2][порт: %3]. Адрес: [%4]. "
    "Socket family: %5. Socket type: %6. Socket protocol: %7. "
	"Ошибка WinSock: %1.");

  structure::str_formatter fmsg(msgRus);

  fmsg<<winsockError
      <<ucs2_host
      <<ucs2_port
      <<ucs2_address
      <<socket__family
      <<socket__type
      <<socket__protocol;

  if(!self_type::error_rec__check_data__utf8(tracer,
                                             pErrorRec,
                                             self_type::lcid__RUS,
                                             self_type::sm_srcID__IBProvider,
                                             fmsg.str()))
  {
   resultValue=false;
  }//if
 }

 //-----------------------------------------
 {
  const char* const msgEng
   ("[winsock] Failed to connect to server [%2][port: %3]. Address: [%4]. "
    "Socket family: %5. Socket type: %6. Socket protocol: %7. "
	"WinSock error: %1.");

  structure::str_formatter fmsg(msgEng);

  fmsg<<winsockError
      <<ucs2_host
      <<ucs2_port
      <<ucs2_address
      <<socket__family
      <<socket__type
      <<socket__protocol;

  if(!self_type::error_rec__check_data__utf8(tracer,
                                             pErrorRec,
                                             self_type::lcid__ENG,
                                             self_type::sm_srcID__IBProvider,
                                             fmsg.str()))
  {
   resultValue=false;
  }//if
 }

 //-----------------------------------------
 return resultValue;
}//check_err_rec__winsock__failed_to_connect_to_server

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__winsock__failed_to_write_into_port
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    int                            const winsockErrorCode)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const msgRus
   ("[winsock] Сбой записи данных в порт подключения. Ошибка WinSock: %1.");

  structure::str_formatter fmsg(msgRus);

  fmsg<<winsockErrorCode;

  if(!self_type::error_rec__check_data__utf8(tracer,
                                             pErrorRec,
                                             self_type::lcid__RUS,
                                             self_type::sm_srcID__IBProvider,
                                             fmsg.str()))
  {
   resultValue=false;
  }//if
 }

 //-----------------------------------------
 {
  const char* const msgEng
   ("[winsock] Failed to write data to the connection port. WinSock error: %1.");

  structure::str_formatter fmsg(msgEng);

  fmsg<<winsockErrorCode;

  if(!self_type::error_rec__check_data__utf8(tracer,
                                             pErrorRec,
                                             self_type::lcid__ENG,
                                             self_type::sm_srcID__IBProvider,
                                             fmsg.str()))
  {
   resultValue=false;
  }//if
 }

 //-----------------------------------------
 return resultValue;
}//check_err_rec__winsock__failed_to_write_into_port

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__cn_err__cant_detect_auth_method
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Подсистема: %1] Не удалось определить сервис аутентификации. Укажите его явно или определите в строке подключения логин и пароль пользователя.";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<pSubSystemID;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               ucs2ErrSrc,
                                               msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Subsystem: %1] Can't determine the authentication service. Define it explicitly or define in the connection string the login and password of user.";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<pSubSystemID;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               ucs2ErrSrc,
                                               msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__cant_detect_auth_method

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__unk_auth_service_name
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID,
                                    wstr_box_type                  const ucs2_AuthServiceName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Подсистема: %1] Неизвестное имя сервиса аутентификации [%2].";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<pSubSystemID<<ucs2_AuthServiceName;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Subsystem: %1] Unknown name of authentication service [%2].";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<pSubSystemID<<ucs2_AuthServiceName;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__cant_detect_auth_method

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__incorrect_auth_service_name
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID,
                                    wstr_box_type                  const ucs2_AuthServiceName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Подсистема: %1] Некорректное имя сервиса аутентификации [%2].";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<pSubSystemID<<IBP_EscapingText(ucs2_AuthServiceName);

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Subsystem: %1] Incorrect name of authentication service [%2].";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<pSubSystemID<<IBP_EscapingText(ucs2_AuthServiceName);

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__cant_detect_auth_method

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__auth_service_not_supported
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID,
                                    wstr_box_type                  const ucs2_AuthServiceName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Подсистема: %1] Сервис аутентификации [%2] не поддерживается.";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<pSubSystemID<<ucs2_AuthServiceName;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Subsystem: %1] Authentication service [%2] not supported.";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<pSubSystemID<<ucs2_AuthServiceName;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__auth_service_not_supported

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__incompatible_auth_settings
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID,
                                    wstr_box_type                  const ucs2_AuthServiceName,
                                    wstr_box_type                  const ucs2_IntegratedSecurityValue)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Подсистема: %1] Несовместимые сервисы аутентификации в \"remote:auth\" [%2] и \"Integrated Security\" [%3].";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<pSubSystemID<<ucs2_AuthServiceName<<ucs2_IntegratedSecurityValue;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Subsystem: %1] Incompatible authentication services in \"remote:auth\" [%2] and \"Integrated Security\" [%3].";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<pSubSystemID<<ucs2_AuthServiceName<<ucs2_IntegratedSecurityValue;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__incompatible_auth_settings

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__integ_sec_not_supported
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Подсистема: %1] Интегрированная аутентификация не поддерживается. Клиент: %2. Версия: %3.";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<pSubSystemID<<IBP_SUBSYSTEM_SIGN__REMOTE_FB<<IBP_VI_PRODUCT_VER_STRING1;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Subsystem: %1] Integrated authentication is not supported. Client: %2. Version: %3.";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<pSubSystemID<<IBP_SUBSYSTEM_SIGN__REMOTE_FB<<IBP_VI_PRODUCT_VER_STRING1;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__integ_sec_not_supported

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__cn_err__bug_check__cant_translate_wire_crypt_key_type
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2Place,
                                    wstr_box_type                  const ucs2Point,
                                    wstr_box_type                  const ucs2FromCS,
                                    wstr_box_type                  const ucs2ToCS)
{
 assert(pErrorRec!=nullptr);

 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[BUG CHECK] Ошибка конвертирования имени типа ключа шифрования соединения из %3 в %4. Точка проверки [%1][%2].";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<ucs2Place<<ucs2Point<<ucs2FromCS<<ucs2ToCS;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[BUG CHECK] Failed to convert the name of wire encryption key type from %3 to %4. Check point [%1][%2].";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<ucs2Place<<ucs2Point<<ucs2FromCS<<ucs2ToCS;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__bug_check__cant_translate_wire_crypt_key_type

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__cn_err__bug_check__cant_translate_wire_crypt_svc_names
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2Place,
                                    wstr_box_type                  const ucs2Point,
                                    wstr_box_type                  const ucs2FromCS,
                                    wstr_box_type                  const ucs2ToCS)
{
 assert(pErrorRec!=nullptr);

 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[BUG CHECK] Ошибка конвертирования списка имен сервисов шифрования соединения из %3 в %4. Точка проверки [%1][%2].";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<ucs2Place<<ucs2Point<<ucs2FromCS<<ucs2ToCS;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[BUG CHECK] Failed to convert the list with names of wire encryption services from %3 to %4. Check point [%1][%2].";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<ucs2Place<<ucs2Point<<ucs2FromCS<<ucs2ToCS;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__bug_check__cant_translate_wire_crypt_svc_names

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__cn_err__mult_def_known_server_key
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID,
                                    wstr_box_type                  const ucs2_keyType,
                                    wstr_box_type                  const ucs2_keyPlugin)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Подсистема: %1] Многократное определение типа серверного ключа [%2].[%3].";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<pSubSystemID<<ucs2_keyType<<ucs2_keyPlugin;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Subsystem: %1] Multiple definition of server key type [%2].[%3].";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<pSubSystemID<<ucs2_keyType<<ucs2_keyPlugin;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__mult_def_known_server_key

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__cn_err__wire_crypt_not_possible__no_known_srv_keys
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID,
                                    wstr_box_type                  const ucs2_authServiceName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Подсистема: %1] Шифрование соединения невозможно. Сервер не предоставил поддерживаемые типы ключей. "
    "Текущий сервис аутентификации: [%2].";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<pSubSystemID<<ucs2_authServiceName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Subsystem: %1] The encryption of connection impossible. Server does not return the supported types of keys. "
    "Current authentication service: [%2].";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<pSubSystemID<<ucs2_authServiceName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__wire_crypt_not_possible__no_known_srv_keys

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__cn_err__wire_crypt_not_possible__no_crypt_keys
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID,
                                    wstr_box_type                  const ucs2_authServiceName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Подсистема: %1] Шифрование соединения невозможно. Сервис аутентификации [%2] не определил ключи.";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<pSubSystemID<<ucs2_authServiceName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Subsystem: %1] The encryption of connection impossible. Authentication service [%2] does not define the keys.";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<pSubSystemID<<ucs2_authServiceName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__wire_crypt_not_possible__no_crypt_keys

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__cn_err__wire_crypt_not_supported
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Подсистема: %1] Шифрование подключения не поддерживается.";

  structure::wstr_formatter
   msgRus(utf8_to_wstring(c_templ_utf8));

  msgRus<<pSubSystemID;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ_utf8
   ="[Subsystem: %1] Encryption of connection not supported.";

  structure::wstr_formatter
   msgEng(utf8_to_wstring(c_templ_utf8));

  msgEng<<pSubSystemID;

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               utf8_to_wstring(sm_srcID__IBProvider),
                                               msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__wire_crypt_not_supported

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__srv_err__bad_login
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="Ваши имя пользователя и пароль не определены. Попросите администратора базы данных предоставить логин к Firebird.";

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               ucs2ErrSrc,
                                               utf8_to_wstring(c_templ)))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ
   ="Your user name and password are not defined. Ask your database administrator to set up a Firebird login.";

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               ucs2ErrSrc,
                                               utf8_to_wstring(c_templ)))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__bad_login

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__unk_db_name
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2ErrSrc,
                                            wstr_box_type                  const pwszDbName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const std::wstring templ=self_type::utf8_to_wstring
  ("I/O ошибка в процессе выполнения операции \"%1\" для файла \"%2\".\n"
   "В процессе открытия файла произошла ошибка.\n");

  structure::wstr_formatter msgRus(templ);

  msgRus<<L"CreateFile (open)"<<pwszDbName;

  if(!self_type::error_rec__check_partial_data
        (tracer,
         pErrorRec,
         self_type::lcid__RUS,
         ucs2ErrSrc,
         msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 tracer<<send;

 {
  structure::wstr_formatter msgEng
   (L"I/O error during \"%1\" operation for file \"%2\".\n"
    L"Error while trying to open file.\n");

  msgEng<<L"CreateFile (open)"<<pwszDbName;

  if(!self_type::error_rec__check_partial_data
        (tracer,
         pErrorRec,
         self_type::lcid__ENG,
         ucs2ErrSrc,
         msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__unk_db_name

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__db_name_is_too_long
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID,
                                    size_t                         const szDbName,
                                    size_t                         const max_szDbName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="[Подсистема: %1] Длина имени базы данных [%2] превышает максимально допустимую [%3].";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  msgRus<<pSubSystemID<<szDbName<<max_szDbName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="[Subsystem: %1] Database name length [%2] exceeds the maximum [%3].";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  msgEng<<pSubSystemID<<szDbName<<max_szDbName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__db_name_is_too_long

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__translate_db_name_to_utf8
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="[Подсистема: %1] Ошибка преобразования имени базы данных в кодовую страницу UTF8.";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  msgRus<<pSubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="[Subsystem: %1] Failed to convert the database name in the code page UTF8.";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  msgEng<<pSubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__translate_db_name_to_utf8

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__translate_cn_param_to_utf8
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID,
                                    wstr_box_type                  const pParamName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="[Подсистема: %1] Ошибка преобразования параметра подключения [%2] в кодовую страницу UTF8.";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  msgRus<<pSubSystemID<<pParamName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="[Subsystem: %1] Failed to convert the connection parameter [%2] in the code page UTF8.";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  msgEng<<pSubSystemID<<pParamName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__translate_cn_param_to_utf8

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__cant_detect_cn_type
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="[Подсистема: %1] Не удалось определить тип подключения к базе данных.";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  msgRus<<pSubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="[Subsystem: %1] Failed to define the type of connection to database.";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  msgEng<<pSubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__cant_detect_cn_type

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__not_defined_req_init_prop
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const pSubSystemID,
                                    wstr_box_type                  const pPropName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="[Подсистема: %1] Не определено обязательное свойство инициализации \"%2\".";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  msgRus<<pSubSystemID<<pPropName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="[Subsystem: %1] Required initialization property \"%2\" not defined.";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  msgEng<<pSubSystemID<<pPropName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__cn_err__cant_detect_cn_type

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__incorrect_params_to_internal_func_INF_database_info
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Incorrect parameters provided to internal function INF_database_info";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Incorrect parameters provided to internal function INF_database_info";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__incorrect_params_to_internal_func_INF_database_info

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__cn_err__bug_check__bad_cn_handle
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2Place,
                                    wstr_box_type                  const ucs2Point)
{
 assert(pErrorRec!=nullptr);

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          L"bad connection handle");
}//check_err_rec__cn_err__bug_check__bad_cn_handle

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__failed_to_detach__has_active_tr
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    size_t                         const nTrs)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Нельзя отключать базу данных с незавершенными транзакциями (количество: %1).";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  msgRus<<nTrs;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Cannot disconnect database with open transactions (%1 active).";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  msgEng<<nTrs;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__failed_to_detach__has_active_tr

////////////////////////////////////////////////////////////////////////////////
//Transaction errors

bool TestCheckErrors::check_err_rec__srv_err__bad_tpb
                                   (TTSO_Tracer&                          tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Некорректная структура блока с параметрами транзакции";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="invalid format for transaction parameter block";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__bad_tpb

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__bad_tpb_ver
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Некорректная структура блока с параметрами транзакции\n"
    "Недействительная версия структуры блока с параметрами транзакции";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="invalid format for transaction parameter block\n"
    "wrong version of transaction parameter block";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__bad_tpb_ver

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__bad_cn_handle
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Недействительный дескриптор базы данных (нет активного подключения).";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Invalid database handle (no active connection).";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__bad_cn_handle

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__tr_err__bug_check__bad_tr_handle
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2Place,
                                    wstr_box_type                  const ucs2Point)
{
 assert(pErrorRec!=nullptr);

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          L"bad transaction handle");
}//check_err_rec__tr_err__bug_check__bad_tr_handle

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__tr_err__bug_check__tr_handle_not_zero
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2Place,
                                    wstr_box_type                  const ucs2Point)
{
 assert(pErrorRec!=nullptr);

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          L"transaction handle not zero");
}//check_err_rec__tr_err__bug_check__tr_handle_not_zero

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__tr_err__prep_data_is_too_large
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID,
                                       size_t                         const buf_size,
                                       size_t                         const max_size)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Размер описания подготавливаемой транзакции [%2] превышает максимально допустимое значение [%3].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<buf_size<<max_size;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] The description length of transaction, that you want to prepare, is too large: %2. Max allowed length equal to %3.");

  msgEng<<ucs2_SubSystemID<<buf_size<<max_size;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__tr_err__prep_data_is_too_large

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__bad_tr_handle
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Недействительный дескриптор транзакции (ожидается явный старт транзакции).";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               ucs2ErrSrc,
                                               msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Invalid transaction handle (expecting explicit transaction start).";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               ucs2ErrSrc,
                                               msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__bad_tr_handle

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__stmt_err__bug_check__stmt_handle_not_zero
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2Place,
                                    wstr_box_type                  const ucs2Point)
{
 assert(pErrorRec!=nullptr);

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          L"statement handle not zero");
}//check_err_rec__stmt_err__bug_check__stmt_handle_not_zero

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__bug_check__bad_stmt_handle
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    wstr_box_type                  const ucs2Place,
                                    wstr_box_type                  const ucs2Point)
{
 assert(pErrorRec!=nullptr);

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          L"bad statement handle");
}//check_err_rec__stmt_err__bug_check__bad_stmt_handle

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__failed_to_close_stmt
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Ошибка закрытия курсора результирующего множества.";

  if(!self_type::error_rec__check_partial_data__utf8
                                      (tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       self_type::sm_srcID__IBProvider,
                                       templ_utf8))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Failed to close the cursor.";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_partial_data__utf8
                                      (tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       self_type::sm_srcID__IBProvider,
                                       templ_utf8))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__failed_to_close_stmt

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__invalid_req_handle
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Недействительный дескриптор запроса.";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Invalid request handle.";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__invalid_req_handle

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__failed_to_close_stmt__reclose
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Dynamic SQL Error\n"
    "SQL error code = -501\n"
    "Attempt to reclose a closed cursor";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Dynamic SQL Error\n"
    "SQL error code = -501\n"
    "Attempt to reclose a closed cursor";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__failed_to_close_stmt__reclose

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__failed_to_close_stmt__reclose__fb3
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Attempt to reclose a closed cursor";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Attempt to reclose a closed cursor";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__failed_to_close_stmt__reclose__fb3

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__failed_to_prepare
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Ошибка подготовки SQL выражения.";

  if(!self_type::error_rec__check_partial_data__utf8
                                      (tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       self_type::sm_srcID__IBProvider,
                                       templ_utf8))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Failed to prepare the SQL statement.";

  if(!self_type::error_rec__check_partial_data__utf8
                                      (tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       self_type::sm_srcID__IBProvider,
                                       templ_utf8))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__failed_to_prepare

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__attempt_to_execute_unprepared_sql_stmt
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Dynamic SQL Error\n"
    "SQL error code = -504\n"
    "Попытка выполнить неподготовленное динамическое SQL выражение.";

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       utf8_to_wstring(templ_utf8)))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Dynamic SQL Error\n"
    "SQL error code = -504\n"
    "Attempt to execute an unprepared dynamic SQL statement.";

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       utf8_to_wstring(templ_utf8)))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__attempt_to_execute_unprepared_sql_stmt

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__attempt_to_execute_unprepared_sql_stmt__fb3
                                   (TTSO_Tracer&                         tracer,
                                    wstr_box_type                  const ucs2ErrSrc,
                                    const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Попытка выполнить неподготовленное динамическое SQL выражение.";

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       utf8_to_wstring(templ_utf8)))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Attempt to execute an unprepared dynamic SQL statement.";

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       utf8_to_wstring(templ_utf8)))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__attempt_to_execute_unprepared_sql_stmt__fb3

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__not_prepared
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Команда не подготовлена.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Command not prepared.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__not_prepared

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__errors_in_get_columns_operation
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="В процессе формирования описания результата запроса произошли ошибки.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"Failed to build the definition of statement result.");

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__errors_in_get_columns_operation

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__errors_in_get_parameters_operation
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="В процессе формирования описаний параметров запроса произошли ошибки.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"Failed to build the definitions of statement parameters.");

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__errors_in_get_parameters_operation

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_srv_err__execute_fail
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ__utf8
   ="Ошибка выполнения SQL выражения.";

  if(!self_type::error_rec__check_partial_data__utf8
                                      (tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       self_type::sm_srcID__IBProvider,
                                       c_templ__utf8))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const c_templ__utf8
   ="Failed to execute the SQL statement.";

  if(!self_type::error_rec__check_partial_data__utf8
                                      (tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       self_type::sm_srcID__IBProvider,
                                       c_templ__utf8))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_srv_err__execute_fail

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__op_was_cancelled
                                      (TTSO_Tracer&                         tracer,
                                       wstr_box_type                  const ucs2ErrSrc,
                                       const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="Операция была отменена.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const wchar_t* const c_msg
   =L"Operation was cancelled.";

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       c_msg))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_srv_err__execute_fail__op_was_cancelled

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__defer_exec_stmt_requires_tr_context
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Запрос с отложенным выполнением требует контекст транзакции.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Statement with deferred execution requires the transaction context.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__defer_exec_stmt_requires_tr_context

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__attempt_to_reexecute_stmt_with_open_cursor
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Попытка повторно выполнить запрос с незакрытым курсором.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Attempt to reexecute a statement with an open cursor.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__attempt_to_reexecute_stmt_with_open_cursor

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__attempt_to_reopen_cursor
                                      (TTSO_Tracer&                         tracer,
                                       wstr_box_type                  const ucs2ErrSrc,
                                       const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="Dynamic SQL Error\n"
    "SQL error code = -502\n"
    "Attempt to reopen an open cursor";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const wchar_t* const c_msg
   =L"Dynamic SQL Error\n"
    L"SQL error code = -502\n"
    L"Attempt to reopen an open cursor";

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       c_msg))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__attempt_to_reopen_cursor

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__attempt_to_reopen_cursor__fb3
                                      (TTSO_Tracer&                         tracer,
                                       wstr_box_type                  const ucs2ErrSrc,
                                       const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="Attempt to reopen an open cursor";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__RUS,
                                               ucs2ErrSrc,
                                               msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const wchar_t* const c_msg
   =L"Attempt to reopen an open cursor";

  if(!self_type::error_rec__check_partial_data(tracer,
                                               pErrorRec,
                                               self_type::lcid__ENG,
                                               ucs2ErrSrc,
                                               c_msg))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__attempt_to_reopen_cursor__fb3

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__prepare_stmt_with_open_cursor
                                      (TTSO_Tracer&                         tracer,
                                       wstr_box_type                  const ucs2ErrSrc,
                                       const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="Dynamic SQL Error\n"
    "SQL error code = -519\n"
    "The prepare statement identifies a prepare statement with an open cursor";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const wchar_t* const c_msg
   =L"Dynamic SQL Error\n"
    L"SQL error code = -519\n"
    L"The prepare statement identifies a prepare statement with an open cursor";

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       c_msg))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__prepare_stmt_with_open_cursor

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__attempt_to_prepare_stmt_with_open_cursor
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Попытка подготовить запрос с незакрытым курсором.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Attempt to prepare a statement with an open cursor.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__attempt_to_prepare_stmt_with_open_cursor

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__attempt_to_close_a_closed_cursor
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Попытка закрытия закрытого курсора.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Attempt to close a closed cursor.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__attempt_to_close_a_closed_cursor

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__fetch_from_closed_cursor
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Выборка записей из закрытого курсора.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Fetch of records from closed cursor.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__fetch_from_closed_cursor

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__fetch_after_eof
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Выборка из курсора после EOF.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Fetch from cursor after EOF.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__fetch_after_eof

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__stmt_err__fetch_fail
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 if(!self_type::error_rec__check_data
      (tracer,
       pErrorRec,
       self_type::lcid__RUS,
       utf8_to_wstring(self_type::sm_srcID__IBProvider),
       utf8_to_wstring("Ошибка выборки данных результирующего множества.")))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 if(!self_type::error_rec__check_data
      (tracer,
       pErrorRec,
       self_type::lcid__ENG,
       utf8_to_wstring(self_type::sm_srcID__IBProvider),
       L"Failed to fetch a row from cursor."))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 return resultValue;
}//check_err_rec__stmt_err__fetch_fail

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__cursor_is_not_open
                                      (TTSO_Tracer&                         tracer,
                                       wstr_box_type                  const ucs2ErrSrc,
                                       const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 if(!self_type::error_rec__check_data
      (tracer,
       pErrorRec,
       self_type::lcid__RUS,
       ucs2ErrSrc,
       L"Dynamic SQL Error\n"
       L"SQL error code = -504\n"
       L"Invalid cursor reference\n"
       L"Cursor is not open"))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 if(!self_type::error_rec__check_data
      (tracer,
       pErrorRec,
       self_type::lcid__ENG,
       ucs2ErrSrc,
       L"Dynamic SQL Error\n"
       L"SQL error code = -504\n"
       L"Invalid cursor reference\n"
       L"Cursor is not open"))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__cursor_is_not_open

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__cursor_is_not_open__fb3
                                      (TTSO_Tracer&                         tracer,
                                       wstr_box_type                  const ucs2ErrSrc,
                                       const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 if(!self_type::error_rec__check_data
      (tracer,
       pErrorRec,
       self_type::lcid__RUS,
       ucs2ErrSrc,
       L"Cursor is not open"))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 if(!self_type::error_rec__check_data
      (tracer,
       pErrorRec,
       self_type::lcid__ENG,
       ucs2ErrSrc,
       L"Cursor is not open"))
 {
  resultValue=false;
 }//if

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__cursor_is_not_open__fb3

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__blob_err__bug_check__bad_blob_handle
                                          (TTSO_Tracer&                         tracer,
                                           const structure::t_err_record* const pErrorRec,
                                           wstr_box_type                  const ucs2Place,
                                           wstr_box_type                  const ucs2Point)
{
 assert(pErrorRec);

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          L"bad blob handle");
}//check_err_rec__blob_err__bug_check__bad_blob_handle

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__blob_err__bug_check__blob_handle_not_zero
                                          (TTSO_Tracer&                         tracer,
                                           const structure::t_err_record* const pErrorRec,
                                           wstr_box_type                  const ucs2Place,
                                           wstr_box_type                  const ucs2Point)
{
 assert(pErrorRec);

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          L"blob handle not zero");
}//check_err_rec__blob_err__bug_check__blob_handle_not_zero

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__blob_err__bug_check__wrong_blob_handle_mode
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2Place,
                                            wstr_box_type                  const ucs2Point,
                                            int                            const blobHandleMode)
{
 assert(pErrorRec);

 structure::wstr_formatter freason(L"incorrect blob handle mode: %1");

 freason<<blobHandleMode;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__blob_err__bug_check__wrong_blob_handle_mode

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__blob_err__close_closed_blob
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Попытка закрытия закрытого блоба.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Attempt to close a closed blob.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__blob_err__close_closed_blob

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__blob_err__cancel_closed_blob
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Попытка отмены создания закрытого блоба.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Attempt to cancel a creation of closed blob.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__blob_err__cancel_closed_blob

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__blob_err__read_from_closed_blob
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Чтение данных из закрытого блоба.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Data reading from closed blob.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__blob_err__read_from_closed_blob

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__blob_err__write_into_closed_blob
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Запись данных в закрытый блоб.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Data writing into closed blob.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__blob_err__write_into_closed_blob

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__blob_err__work_with_closed_blob
                                      (TTSO_Tracer&                         tracer,
                                       const structure::t_err_record* const pErrorRec,
                                       wstr_box_type                  const ucs2_SubSystemID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Работа с закрытым блобом.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Work with closed blob.");

  msgEng<<ucs2_SubSystemID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__blob_err__work_with_closed_blob

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__srv_err__invalid_blob_handle
                                          (TTSO_Tracer&                         tracer,
                                           wstr_box_type                  const ucs2ErrSrc,
                                           const structure::t_err_record* const pErrorRec)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="Недействительный дескриптор блоба.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       ucs2ErrSrc,
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"Invalid BLOB handle.");

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       ucs2ErrSrc,
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__srv_err__invalid_blob_handle

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__slice_err__get_fail__invalid_array_buffer_size
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2Place,
                                            wstr_box_type                  const ucs2Point,
                                            wstr_box_type                  const ucs2RelationName,
                                            wstr_box_type                  const ucs2FieldName,
                                            size_t                         const DefinedSize,
                                            size_t                         const ExpectedSize)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный размер буфера для массива из [%3].[%4]: %5. Ожидается размер: %6. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2Place<<ucs2Point<<ucs2RelationName<<ucs2FieldName<<DefinedSize<<ExpectedSize;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const wchar_t* const c_msg
   =L"[BUG CHECK] Invalid size of buffer for array from [%3].[%4]: %5. Expected size: %6. Check point [%1][%2].";

  structure::wstr_formatter msgEng(c_msg);

  msgEng<<ucs2Place<<ucs2Point<<ucs2RelationName<<ucs2FieldName<<DefinedSize<<ExpectedSize;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__slice_err__get_fail__invalid_array_buffer_size

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__xsqlda_err__incorrect_version
                           (TTSO_Tracer&                         tracer,
                            const structure::t_err_record* const pErrorRec,
                            wstr_box_type                  const ucs2Place,
                            wstr_box_type                  const ucs2Point,
                            wstr_box_type                  const ucs2xsqldaName,
                            long                           const version)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректная версия XSQLDA [%3]: %4. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2Place<<ucs2Point<<ucs2xsqldaName<<version;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect XSQLDA [%3] version: %4. Check point [%1][%2].");

  msgEng<<ucs2Place<<ucs2Point<<ucs2xsqldaName<<version;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__incorrect_version

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__too_many_vars
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const pSubSystemID,
                 size_t                         const actualValue,
                 size_t                         const maxValue)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Слишком большое число элементов для XSQLDA: %2. Максимум: %3.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<pSubSystemID<<actualValue<<maxValue;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Too many vars for XSQLDA: %2. Max: %3.");

  msgEng<<pSubSystemID<<actualValue<<maxValue;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__too_many_vars

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__incorrect_sqllen
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const sqlTypeSign,
                 long                           const sqlType)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректное значение XSQLVAR::sqllen: %2. XSQLVAR::sqltype содержит идентификатор типа [%1].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<sqlTypeSign<<sqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect value of XSQLVAR::sqllen: %2. XSQLVAR::sqltype contains a datatype identifier [%1].");

  msgEng<<sqlTypeSign<<sqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__incorrect_sqllen

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__incorrect_sqlscale
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const sqlBaseTypeSign,
                 long                           const sqlScale)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректное значение XSQLVAR::sqlscale: %2. XSQLVAR::sqltype содержит идентификатор типа [%1].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<sqlBaseTypeSign<<sqlScale;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect value of XSQLVAR::sqlscale: %2. XSQLVAR::sqltype contains a datatype identifier [%1].");

  msgEng<<sqlBaseTypeSign<<sqlScale;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__incorrect_sqlscale

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__unknown_sqltype
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 long                           const sqlType)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] XSQLVAR::sqltype содержит идентификатор неизвестного sql-типа данных: %1.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<sqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] XSQLVAR::sqltype contains an unknown identifier of sql-type: %1.");

  msgEng<<sqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__unknown_sqltype

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__incorrect_sqlind_ptr
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 long                           const sqlType)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный нулевой указатель в XSQLVAR::sqlind. XSQLVAR::sqltype содержит идентификатор типа [%1].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<sqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect null pointer in XSQLVAR::sqlind. XSQLVAR::sqltype contains a datatype identifier [%1].");

  msgEng<<sqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__incorrect_sqlind_ptr

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__incorrect_sqlind_value
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const place,
                 wstr_box_type                  const point,
                 short                          const sqlindValue)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Неизвестное значение индикатора XSQLVAR: %3. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<place<<point<<sqlindValue;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Unknown value of XSQLVAR indicator: %3. Check point [%1][%2].");

  msgEng<<place<<point<<sqlindValue;;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__incorrect_sqlind_value

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__xsqlvar_not_supports_null_state
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 long                           const sqlType)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] XSQLVAR не поддерживает хранение NULL-состояния значения. XSQLVAR::sqltype содержит идентификатор типа [%1].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<sqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] XSQLVAR not supports a storing of null state of value. XSQLVAR::sqltype contains a datatype identifier [%1].");

  msgEng<<sqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__xsqlvar_not_supports_null_state

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__incorrect_varchar_data_length
                           (TTSO_Tracer&                         tracer,
                            const structure::t_err_record* const pErrorRec,
                            long                           const varcharLength)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректное значение длины VARCHAR-данных: %1.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<varcharLength;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect length of VARCHAR-data: %1.");

  msgEng<<varcharLength;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__incorrect_varchar_data_length

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__varchar_data_length_is_greater_than_buffer_size
                           (TTSO_Tracer&                         tracer,
                            const structure::t_err_record* const pErrorRec,
                            long                           const varcharLength,
                            size_t                         const bufferSize)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Длина VARCHAR-данных [%1] превышает размер собственного буфера [%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<varcharLength<<bufferSize;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Length of VARCHAR-data [%1] is greater than the length of own buffer [%2].");

  msgEng<<varcharLength<<bufferSize;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__varchar_data_length_is_greater_than_buffer_size

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const pSubSystemID,
                                            size_t                         const index)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Ошибка обработки информационных raw-данных XSQLVAR структуры. Индекс: %2.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<pSubSystemID<<index;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] XSQLVAR information raw-data processing error. Index: %2.");

  msgEng<<pSubSystemID<<index;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const pSubSystemID,
                                            size_t                         const index)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Ошибка обработки данных XSQLVAR структуры. Индекс: %2.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<pSubSystemID<<index;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] XSQLVAR data processing error. Index: %2.");

  msgEng<<pSubSystemID<<index;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__bug_check__other_count_of_xvars
                                           (TTSO_Tracer&                   tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_SubSystemID,
                                            size_t                         const actualCount,
                                            size_t                         const expectedCount)
{
 assert(pErrorRec!=nullptr);
 assert(actualCount!=expectedCount);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] [BUG CHECK] Изменилось количество xvar-элементов: %2. Ожидаемое количество: %3.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<actualCount<<expectedCount;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] [BUG CHECK] A changed count of xvar-elements: %2. Expected count: %3.");

  msgEng<<ucs2_SubSystemID<<actualCount<<expectedCount;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__bug_check__other_count_of_xvars

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__bug_check__other_sqltype_of_xvar
                                           (TTSO_Tracer&                   tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            long                           const actualSqlType,
                                            long                           const expectedSqlType)
{
 assert(pErrorRec!=nullptr);
 assert(actualSqlType!=expectedSqlType);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Изменился идентификатор SQL-типа xvar: %1. Ожидаемый идентификатор: %2.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<actualSqlType<<expectedSqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] A changed SQL-type identifier of xvar: %1. Expected identifier: %2.");

  msgEng<<actualSqlType<<expectedSqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__bug_check__other_sqltype_of_xvar

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__bug_check__other_sqlscale_of_xvar
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const sqlBaseTypeSign,
                                            long                           const actualSqlScale,
                                            long                           const expectedSqlScale)
{
 assert(pErrorRec!=nullptr);
 assert(actualSqlScale!=expectedSqlScale);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Изменился масштаб xvar: %2. Ожидаемый масштаб: %3. XSQLVAR::sqltype содержит идентификатор типа [%1].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<sqlBaseTypeSign<<actualSqlScale<<expectedSqlScale;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] A changed scale of xvar: %2. Expected scale: %3. XSQLVAR::sqltype contains a datatype identifier [%1].");

  msgEng<<sqlBaseTypeSign<<actualSqlScale<<expectedSqlScale;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__bug_check__other_sqltype_of_xvar

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__bug_check__other_sqllen_of_xvar
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const sqlTypeSign,
                                            long                           const actualSqlLen,
                                            long                           const expectedSqlLen)
{
 assert(pErrorRec!=nullptr);
 assert(actualSqlLen!=expectedSqlLen);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Изменилась длина xvar: %2. Ожидаемая длина: %3. XSQLVAR::sqltype содержит идентификатор типа [%1].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<sqlTypeSign<<actualSqlLen<<expectedSqlLen;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] A changed length of xvar: %2. Expected length: %3. XSQLVAR::sqltype contains a datatype identifier [%1].");

  msgEng<<sqlTypeSign<<actualSqlLen<<expectedSqlLen;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__bug_check__other_sqllen_of_xvar

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__bug_check__incorrect_sqld
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_SubSystemID,
                                            wstr_box_type                  const ucs2_XSQLDA_Sign,
                                            long                           const sqld)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] [BUG CHECK] Некорректное значение sqld в [%2]: %3.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<ucs2_XSQLDA_Sign<<sqld;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] [BUG CHECK] Incorrect value of sqld in [%2]: %3.");

  msgEng<<ucs2_SubSystemID<<ucs2_XSQLDA_Sign<<sqld;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__bug_check__incorrect_sqld

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__bug_check__incorrect_sqln
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_SubSystemID,
                                            wstr_box_type                  const ucs2_XSQLDA_Sign,
                                            long                           const sqln,
                                            long                           const sqld)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] [BUG CHECK] Некорректное значение sqln в [%2]: %3. Значение sqld: %4.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<ucs2_XSQLDA_Sign<<sqln<<sqld;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] [BUG CHECK] Incorrect value of sqln in [%2]: %3. Value of sqld: %4.");

  msgEng<<ucs2_SubSystemID<<ucs2_XSQLDA_Sign<<sqln<<sqld;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__bug_check__incorrect_sqln

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_err__blr_data_is_too_long
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_SubSystemID,
                                            wstr_box_type                  const ucs2_XSQLDA_Sign,
                                            size_t                         const actualLen,
                                            size_t                         const maxLen)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Размер [%3] BLR-описания XSQLDA [%2] превышает максимально допустимое значение [%4].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<ucs2_XSQLDA_Sign<<actualLen<<maxLen;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Size [%3] BLR-description of XSQLDA [%2] exceeds the maximum [%4].");

  msgEng<<ucs2_SubSystemID<<ucs2_XSQLDA_Sign<<actualLen<<maxLen;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_err__blr_data_is_too_long

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__sdl_err__no_data
                           (TTSO_Tracer&                         tracer,
                            const structure::t_err_record* const pErrorRec,
                            wstr_box_type                  const ucs2_CheckPlace,
                            wstr_box_type                  const ucs2_CheckPoint)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - пустой буфер. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - empty buffer. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__no_data

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__unk_version
                           (TTSO_Tracer&                         tracer,
                            const structure::t_err_record* const pErrorRec,
                            wstr_box_type                  const ucs2_CheckPlace,
                            wstr_box_type                  const ucs2_CheckPoint,
                            unsigned                       const sdlVersion)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - неизвестная версия [%3]. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<sdlVersion;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - unknown version [%3]. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<sdlVersion;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__unk_version

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__unexpected_end_of_data
                           (TTSO_Tracer&                         tracer,
                            const structure::t_err_record* const pErrorRec,
                            wstr_box_type                  const ucs2_CheckPlace,
                            wstr_box_type                  const ucs2_CheckPoint)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - неожиданный конец буфера. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - unexpected end of buffer. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__unexpected_end_of_data

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__str_len_exceed_size_of_buffer_tail
                           (TTSO_Tracer&                         tracer,
                            const structure::t_err_record* const pErrorRec,
                            wstr_box_type                  const ucs2_CheckPlace,
                            wstr_box_type                  const ucs2_CheckPoint,
                            unsigned                       const strLen,
                            size_t                         const bufferTailSize)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - длина строковых данных [%3] превышает количество байт до конца буфера [%4]. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<strLen<<bufferTailSize;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - length of string data [%3] exceed the size of buffer tail [%4]. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<strLen<<bufferTailSize;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__str_len_exceed_size_of_buffer_tail

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__mult_def_of_element_value
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            wstr_box_type                  const ucs2_ElementTagID,
                                            size_t                         const ElementTagOffset)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - многократное определение значения элемента [%3]. Смещение: %4. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<ucs2_ElementTagID<<ElementTagOffset;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - multiple definition of element value [%3]. Offset: %4. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<ucs2_ElementTagID<<ElementTagOffset;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__mult_def_of_element_value

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__wrong_count_of_struct_fields
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            size_t                         const fieldCount)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - недопустимое количество полей в структуре: %3. Поддерживается только одно поле. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<fieldCount;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - wrong count of struct fields: %3. Supported only one field. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<fieldCount;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__wrong_count_of_struct_fields

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__wrong_index_of_bound
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            size_t                         const boundIndex,
                                            size_t                         const maxBoundCount)
{
 assert(pErrorRec!=nullptr);

 assert(maxBoundCount<=boundIndex);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - недопустимый индекс размерности массива: %3. "
    "Размерности индексируются с нуля. Максимальное количество размерностей: %4. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<boundIndex<<maxBoundCount;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - wrong index of array bound: %3. Boundaries are indexed from zero. "
    L"Max number of bounds: %4. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<boundIndex<<maxBoundCount;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__wrong_index_of_bound

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__mult_def_of_bound_range
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            size_t                         const boundIndex)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - повторное определение размерности с индексом %3. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<boundIndex;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - redefinition of dimension with index %3. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<boundIndex;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__mult_def_of_bound_range

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__bad_bound_range
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            size_t                         const boundIndex,
                                            signed __int32                 const lower,
                                            signed __int32                 const upper)
{
 assert(pErrorRec!=nullptr);

 assert(upper<lower);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - некорректные границы размерности с индексом %3: [%4..%5]. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<boundIndex<<lower<<upper;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - bad range of dimension with index %3: [%4..%5]. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<boundIndex<<lower<<upper;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__bad_bound_range

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__unknown_kind_of_literal
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            unsigned                       const literalKind,
                                            size_t                         const offset)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - неизвестный идентификатор типа литеры: %3. Смещение: %4. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<literalKind<<offset;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - unknown kind of literal: %3. Offset: %4. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<literalKind<<offset;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__unknown_kind_of_literal

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__wrong_count_of_element_fields
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            unsigned                       const fieldCount)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - недопустимое количество полей в элементе: %3. Поддерживается только одно поле. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<fieldCount;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - wrong count of element fields: %3. Supported only one field. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<fieldCount;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__wrong_count_of_element_fields

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__unexpected_tag
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            unsigned                       const tagID,
                                            size_t                         const offset)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - неожиданный тэг: %3. Смещение: %4. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<tagID<<offset;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - unexpected tag: %3. Offset: %4. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<tagID<<offset;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__unexpected_tag

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__incorrect_index_property_of_scalar_tag
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            unsigned                       const index,
                                            size_t                         const offset)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - некорректное значение свойства 'index' тега 'scalar': %3. Смещение: %4. Ожидалось нулевое значение. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<index<<offset;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - incorrect value of 'index' property of 'scalar' tag: %3. Offset: %4. Expected a zero value. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<index<<offset;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__incorrect_index_property_of_scalar_tag

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__inconsistent_sizes_of_buffer_and_data
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            size_t                         const bufferSize,
                                            size_t                         const dataSize)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - несогласованные размеры буфера [%3] и данных [%4]. Значения должны быть идентичны. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<bufferSize<<dataSize;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - inconsistent sizes of buffer [%3] and data [%4]. Values should be equal. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<bufferSize<<dataSize;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__inconsistent_sizes_of_buffer_and_data

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__no_data_of_tag
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            wstr_box_type                  const ucs2_TagID)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - отсутствуют данные для тега [%3]. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<ucs2_TagID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - no data of tag [%3]. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<ucs2_TagID;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__no_data_of_tag

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__no_data_of_dimensions
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - отсутствуют определения размерностей. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - no data of dimensions. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__no_data_of_dimensions

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__no_data_of_dimension
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            size_t                         const boundIndex)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - нет данных о размерности с индексом [%3]. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<boundIndex;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - no data of dimension with index [%3]. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<boundIndex;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__no_data_of_dimensions

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__unknown_blr_type_id
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            unsigned                       const blrTypeID,
                                            size_t                         const offset)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - неизвестный идентификатор BLR типа данных: %3. Смещение: %4. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<blrTypeID<<offset;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - unknown identifier of BLR data type: %3. Offset: %4. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<blrTypeID<<offset;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__unknown_blr_type_id

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__sdl_err__invalid_element_length
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_CheckPlace,
                                            wstr_box_type                  const ucs2_CheckPoint,
                                            size_t                         const length,
                                            wstr_box_type                  const blrTypeSign)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректный SDL - недопустимая длина элемента: %3. BLR тип данных: %4. Точка проверки [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_CheckPlace<<ucs2_CheckPoint<<length<<blrTypeSign;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect SDL - invalid length of element: %3. BLR data type: %4. Check point [%1][%2].");

  msgEng<<ucs2_CheckPlace<<ucs2_CheckPoint<<length<<blrTypeSign;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__sdl_err__invalid_element_length

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__xsqlda_info_data_bug_check__unexpected_buffer_end
                           (TTSO_Tracer&                         tracer,
                            const structure::t_err_record* const pErrorRec,
                            wstr_box_type                  const ucs2Place,
                            wstr_box_type                  const ucs2Point)
{
 assert(pErrorRec!=nullptr);

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          L"unexpected end of buffer");
}//check_err_rec__xsqlda_info_data_bug_check__unexpected_buffer_end

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_info_data_bug_check__unexpected_buffer_truncation
                           (TTSO_Tracer&                         tracer,
                            const structure::t_err_record* const pErrorRec,
                            wstr_box_type                  const ucs2Place,
                            wstr_box_type                  const ucs2Point,
                            size_t                         const sqld)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter freason(L"unexpected truncation of buffer. sqld: %1");

 freason<<sqld;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__xsqlda_info_data_bug_check__unexpected_buffer_end

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_info_data_bug_check__incorrect_xsqlda_in_secondary_block
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2Place,
                                            wstr_box_type                  const ucs2Point,
                                            long                           const actualSQLD,
                                            long                           const expectedSQLD,
                                            size_t                         const startIndex)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Некорректное значение sqld во вторичном блоке с XSQLDA данными: %3. Ожидался sqld: %4. StartIndex: %5. "
    "Точка проверки: [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2Place<<ucs2Point<<actualSQLD<<expectedSQLD<<startIndex;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Incorrect value of sqld in secondary block with XSQLDA data: %3. Expected sqld: %4. StartIndex: %5. "
    L"Check point: [%1][%2].");

  msgEng<<ucs2Place<<ucs2Point<<actualSQLD<<expectedSQLD<<startIndex;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_info_data_bug_check__incorrect_xsqlda_in_secondary_block

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_info_data_bug_check__xvar_seq_number_is_out_of_range
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2Place,
                                            wstr_box_type                  const ucs2Point,
                                            long                           const seqNumber,
                                            long                           const sqld,
                                            size_t                         const index)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Порядковый номер XSQLVAR данных [%3] выходит за пределы допустимого диапазона [1..%4]. Индекс данных: %5. "
    "Точка проверки: [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2Place<<ucs2Point<<seqNumber<<sqld<<index;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] XSQLVAR data sequential number [%3] is out of range [1..%4]. Data index: %5. "
    L"Check point: [%1][%2].");

  msgEng<<ucs2Place<<ucs2Point<<seqNumber<<sqld<<index;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_info_data_bug_check__incorrect_xsqlda_in_secondary_block

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_info_data_bug_check__unexpected_xvars_for_xsqlda
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2Place,
                                            wstr_box_type                  const ucs2Point,
                                            size_t                         const sqld)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Неожиданные описания XSQLVARs для XSQLDA структуры [sqld: %3]. "
    "Точка проверки: [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2Place<<ucs2Point<<sqld;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Unexpected defintitions of XSQLVARs for XSQLDA structure [sqld: %3]. "
    L"Check point: [%1][%2].");

  msgEng<<ucs2Place<<ucs2Point<<sqld;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_info_data_bug_check__unexpected_xvars_for_xsqlda

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_info_data_bug_check__unexpected_seq_number_of_xvar
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2Place,
                                            wstr_box_type                  const ucs2Point,
                                            long                           const actualSeqNumber,
                                            long                           const expectedSeqNumber)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[BUG CHECK] Неожиданный порядковый номер XSQLVAR данных: %3. Ожидался номер: %4. "
    "Точка проверки: [%1][%2].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2Place<<ucs2Point<<actualSeqNumber<<expectedSeqNumber;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[BUG CHECK] Unexpected sequential number of XSQLVAR data: %3. Expected number: %4. "
    L"Check point: [%1][%2].");

  msgEng<<ucs2Place<<ucs2Point<<actualSeqNumber<<expectedSeqNumber;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_info_data_bug_check__unexpected_seq_number_of_xvar

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_SubSystemID,
                                            wstr_box_type                  const fieldName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] [BUG CHECK] Повторное определение значения поля [%2] XSQLVAR структуры.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<fieldName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] [BUG CHECK] Multiple definitions of XSQLVAR field value [%2].");

  msgEng<<ucs2_SubSystemID<<fieldName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_SubSystemID,
                                            wstr_box_type                  const fieldName)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] [BUG CHECK] Не определено значение поля [%2] XSQLVAR структуры.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<fieldName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] [BUG CHECK] No definition of XSQLVAR field value [%2].");

  msgEng<<ucs2_SubSystemID<<fieldName;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_info_data_bug_check__negative_sqllen
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_SubSystemID,
                                            long                           const actualLength)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] [BUG CHECK] XSQLVAR определяет отрицательную длину sql-данных: %2.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<actualLength;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] [BUG CHECK] XSQLVAR defines negative length of sql data: %2.");

  msgEng<<ucs2_SubSystemID<<actualLength;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_info_data_bug_check__negative_sqllen

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__xsqlda_info_data_bug_check__incompleted_def_of_xvars
                                           (TTSO_Tracer&                   tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_SubSystemID,
                                            size_t                         const actualCount,
                                            size_t                         const expectedCount)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] [BUG CHECK] Незавершенное определение XSQLVAR структур. Определено: %2. Ожидается: %3.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<actualCount<<expectedCount;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] [BUG CHECK] Incompleted definition of XSQLVAR structures. Define: %2. Expected: %3.");

  msgEng<<ucs2_SubSystemID<<actualCount<<expectedCount;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__xsqlda_info_data_bug_check__incompleted_def_of_xvars

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
                                           (TTSO_Tracer&                         tracer,
                                            const structure::t_err_record* const pErrorRec,
                                            wstr_box_type                  const ucs2_SubSystemID,
                                            size_t                         const elementIndex)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Ошибка обработки элемента [%2] MSG-буфера с данными.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<ucs2_SubSystemID<<elementIndex;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Processing error of element [%2] of MSG-buffer with data.");

  msgEng<<ucs2_SubSystemID<<elementIndex;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__isc__parse_msg_buf_data__failed_to_process_element

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__info_buf_bug_check__unexpected_element
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 long                           elementID)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter freason(L"the unexpected element [tag: %1] in the information buffer");

 freason<<elementID;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__info_buf_bug_check__unexpected_element

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__info_buf_bug_check__unexpected_buffer_end
                           (TTSO_Tracer&                         tracer,
                            const structure::t_err_record* const pErrorRec,
                            wstr_box_type                  const ucs2Place,
                            wstr_box_type                  const ucs2Point)
{
 assert(pErrorRec!=nullptr);

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          L"unexpected end of buffer");
}//check_err_rec__info_buf_bug_check__unexpected_buffer_end

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__info_buf_bug_check__bad_format
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const ucs2Place,
                 wstr_box_type                  const ucs2Point,
                 wstr_box_type                  const elementSign)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter freason(L"incorrect format of element [tag: %1]");

 freason<<elementSign;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__info_buf_bug_check__bad_format

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__info_buf_bug_check__too_large_value
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const ucs2Place,
                 wstr_box_type                  const ucs2Point,
                 wstr_box_type                  const elementSign,
                 size_t                         const actualSize,
                 size_t                         const maxSize)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter
  freason(L"the size [%2] of the resulting data [tag: %1] is larger than the buffer size [%3]");

 freason<<elementSign<<actualSize<<maxSize;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__info_buf_bug_check__too_large_value

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__info_buf_err__transport_data_to_integer__size_t
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const pSubSystemID,
                 wstr_box_type                  const elementSign,
                 size_t                         const bufferSize)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Ошибка пребразования транспортных данных [%2] в целое число [%3]. Размер буфера: %4.";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<pSubSystemID<<elementSign<<get_unsigned_int_sign<sizeof(size_t)>()<<bufferSize;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Failed to transform a transport data [%2] to integer value [%3]. Buffer size: %4.");

  msgEng<<pSubSystemID<<elementSign<<get_unsigned_int_sign<sizeof(size_t)>()<<bufferSize;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__info_buf_err__transport_data_to_integer__size_t

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__test_msg_bug_check__nullptr_to_descrs
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const ucs2Place,
                 wstr_box_type                  const ucs2Point,
                 wstr_box_type                  const msgSign,
                 size_t                         const cDescrs)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter
  freason(L"[%1] has a null ptr to descrs. The number of descrs is [%2]");

 freason<<msgSign<<cDescrs;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__test_msg_bug_check__nullptr_to_descrs

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__test_msg_bug_check__nullptr_to_blr
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const ucs2Place,
                 wstr_box_type                  const ucs2Point,
                 wstr_box_type                  const msgSign,
                 size_t                         const szBlr)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter
  freason(L"[%1] has a null ptr to blr. The size of blr is [%2]");

 freason<<msgSign<<szBlr;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__test_msg_bug_check__nullptr_to_blr

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__test_msg_bug_check__nullptr_to_data
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const ucs2Place,
                 wstr_box_type                  const ucs2Point,
                 wstr_box_type                  const msgSign,
                 size_t                         const szData)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter
  freason(L"[%1] has a null ptr to data. The size of data is [%2]");

 freason<<msgSign<<szData;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__test_msg_bug_check__nullptr_to_data

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__test_msg_bug_check__unexpected_blr
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const ucs2Place,
                 wstr_box_type                  const ucs2Point,
                 wstr_box_type                  const msgSign,
                 size_t                         const szBlr)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter
  freason(L"[%1] has an unexpected blr [size: %2]");

 freason<<msgSign<<szBlr;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__test_msg_bug_check__unexpected_blr

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__test_msg_bug_check__unexpected_data
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const ucs2Place,
                 wstr_box_type                  const ucs2Point,
                 wstr_box_type                  const msgSign,
                 size_t                         const szData)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter
  freason(L"[%1] has an unexpected data [size: %2]");

 freason<<msgSign<<szData;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__test_msg_bug_check__unexpected_data

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__test_msg_bug_check__no_blr
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const ucs2Place,
                 wstr_box_type                  const ucs2Point,
                 wstr_box_type                  const msgSign,
                 size_t                         const cDescrs)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter
  freason(L"[%1] has no blr. The number of descrs is: %2");

 freason<<msgSign<<cDescrs;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__test_msg_bug_check__no_blr

//------------------------------------------------------------------------
bool TestCheckErrors::check_err_rec__test_msg_bug_check__no_data
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const ucs2Place,
                 wstr_box_type                  const ucs2Point,
                 wstr_box_type                  const msgSign,
                 size_t                         const cDescrs)
{
 assert(pErrorRec!=nullptr);

 structure::wstr_formatter
  freason(L"[%1] has no data. The number of descrs is: %2");

 freason<<msgSign<<cDescrs;

 return self_type::helper__bug_check
         (tracer,
          pErrorRec,
          ucs2Place,
          ucs2Point,
          freason.str());
}//check_err_rec__test_msg_bug_check__no_data

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::check_err_rec__common__internal_err__unk_sql_type
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec,
                 wstr_box_type                  const pSubSystemID,
                 size_t                         const index,
                 long                           const sqlType)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const c_templ
   ="[Подсистема: %1] Внутренняя ошибка. Данные [индекс: %2] с неизвестным серверным sql-типом [%3].";

  structure::wstr_formatter msgRus
   (utf8_to_wstring(c_templ));

  msgRus<<pSubSystemID<<index<<sqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  structure::wstr_formatter msgEng
   (L"[Subsystem: %1] Internal error. Data [index: %2] with unknown server's sql-type [%3].");

  msgEng<<pSubSystemID<<index<<sqlType;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//check_err_rec__common__internal_err__unk_sql_type

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::error_rec__check_source
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    LCID                           const lcid,
                                    wstr_box_type                  const wstrErrSrc)
{
 assert(pErrorRec);

 //-----------------------------------------------------------------------
 bool result=true;

 std::wstring err_src;

 //-----------------------------------------------------------------------
 if(!pErrorRec->get_description(structure::t_lcid(lcid),&err_src,NULL))
 {
  result=false;

  tracer(tso_msg_error,-1)<<L"Error Source not available!"<<send;
 }
 else
 if(!structure::equal(err_src.cbegin(),
                      err_src.cend(),
                      wstrErrSrc.begin(),
                      wstrErrSrc.end()))
 {
  result=false;

  tracer(tso_msg_error,-1)
   <<L"Wrong Error Source: \""<<err_src<<L"\".\n"
   <<L"We expected: \""<<wstrErrSrc<<L"\""
   <<send;
 }
 else
 {
  tracer<<L"OK. Error Source: \""<<err_src<<L"\""<<send;
 }//else

 return result;
}//error_rec__check_source

//------------------------------------------------------------------------
bool TestCheckErrors::error_rec__check_data
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    LCID                           const lcid,
                                    wstr_box_type                  const wstrErrSrc,
                                    wstr_box_type                  const wstrErrDescr)
{
 assert(pErrorRec);

 //-----------------------------------------------------------------------
 bool result=true;

 std::wstring err_descr;

 //-----------------------------------------------------------------------
 if(!error_rec__check_source(tracer,
                             pErrorRec,
                             lcid,
                             wstrErrSrc))
 {
  result=false;
 }

 //-----------------------------------------------------------------------
 for(;;)
 {
  if(!pErrorRec->get_description(structure::t_lcid(lcid),NULL,&err_descr))
  {
   result=false;

   tracer(tso_msg_error,-1)<<L"Error Description not available!"<<send;

   break;
  }//if

  //replace "\r\n" to "\n"
  helper__replace_rn_to_n(&err_descr);

  if(!structure::equal(err_descr.cbegin(),
                       err_descr.cend(),
                       wstrErrDescr.begin(),
                       wstrErrDescr.end()))
  {
   result=false;

   tracer(tso_msg_error,-1)
    <<L"Wrong Error Descr: \""<<err_descr<<L"\".\n"
    <<L"We expected: \""<<wstrErrDescr<<L"\""
    <<send;

   break;
  }//if

  tracer<<L"OK. Error Description: \""<<err_descr<<L"\""<<send;

  break;
 }//for[ever]

 return result;
}//error_rec__check_data

//------------------------------------------------------------------------
bool TestCheckErrors::error_rec__check_data__utf8
                        (TTSO_Tracer&                         tracer,
                         const structure::t_err_record* const pErrorRec,
                         LCID                           const lcid,
                         str_box_type                   const strUtf8_ErrSrc,
                         str_box_type                   const strUtf8_pszErrDescr)
{
 assert(pErrorRec);

 std::wstring err_src;
 std::wstring err_descr;

 namespace utf8=structure::charsets::cs_utf8;

 //-----------------------------------------
 utf8::t_cs_cvt_result cvt_result=utf8::cs_cvt_result__ok;

 utf8::utf8_to_ucs2(strUtf8_ErrSrc.begin(),
                    strUtf8_ErrSrc.end(),
                    std::back_inserter(err_src),
                    &cvt_result);

 assert(cvt_result==utf8::cs_cvt_result__ok);

 //-----------------------------------------
 utf8::utf8_to_ucs2(strUtf8_pszErrDescr.begin(),
                    strUtf8_pszErrDescr.end(),
                    std::back_inserter(err_descr),
                    &cvt_result);

 assert(cvt_result==utf8::cs_cvt_result__ok);

 //-----------------------------------------

 return self_type::error_rec__check_data(tracer,
                                         pErrorRec,
                                         lcid,
                                         err_src,
                                         err_descr);
}//error_rec__check_data__utf8

//------------------------------------------------------------------------
bool TestCheckErrors::error_rec__check_data__EN_RU
                        (TTSO_Tracer&                         tracer,
                         const structure::t_err_record* const pErrorRec,
                         wstr_box_type                  const wstrErrSrc,
                         wstr_box_type                  const wstrErrDescr__EN,
                         wstr_box_type                  const wstrErrDescr__RU)
{
 assert(pErrorRec);

 bool r=true;

 if(!self_type::error_rec__check_data
       (tracer,
        pErrorRec,
        self_type::lcid__ENG,
        wstrErrSrc,
        wstrErrDescr__EN))
 {
  r=false;
 }//if

 if(!self_type::error_rec__check_data
       (tracer,
        pErrorRec,
        self_type::lcid__RUS,
        wstrErrSrc,
        wstrErrDescr__RU))
 {
  r=false;
 }//if

 return r;
}//error_rec__check_data__EN_RU

////////////////////////////////////////////////////////////////////////////////

bool TestCheckErrors::error_rec__check_partial_data
                                   (TTSO_Tracer&                         tracer,
                                    const structure::t_err_record* const pErrorRec,
                                    LCID                           const lcid,
                                    wstr_box_type                  const wstrErrSrc,
                                    wstr_box_type                  const wstrErrDescr)
{
 assert(pErrorRec);

 //-----------------------------------------------------------------------
 bool result=true;

 std::wstring err_descr;

 //-----------------------------------------------------------------------
 if(!error_rec__check_source(tracer,
                              pErrorRec,
                              lcid,
                              wstrErrSrc))
 {
  result=false;
 }//if

 //-----------------------------------------------------------------------
 for(;;)
 {
  if(!pErrorRec->get_description(structure::t_lcid(lcid),NULL,&err_descr))
  {
   result=false;

   tracer(tso_msg_error,-1)<<L"Error Description not available!"<<send;

   break;
  }//if

  //replace "\r\n" to "\n"
  helper__replace_rn_to_n(&err_descr);

  if(std::search(err_descr.cbegin(),
                 err_descr.cend(),
                 wstrErrDescr.begin(),
                 wstrErrDescr.end())==err_descr.end())
  {
   result=false;

   tracer(tso_msg_error,-1)
    <<L"Wrong Error Descr: \""<<err_descr<<L"\".\n"
    <<L"We expected: \""<<wstrErrDescr<<L"\""
    <<send;

   break;
  }//if

  tracer<<L"OK. Error Description: \""<<err_descr<<L"\""<<send;

  break;
 }//for[ever]

 return result;
}//error_rec__check_partial_data

//------------------------------------------------------------------------
bool TestCheckErrors::error_rec__check_partial_data__utf8
                        (TTSO_Tracer&                         tracer,
                         const structure::t_err_record* const pErrorRec,
                         LCID                           const lcid,
                         str_box_type                   const strUtf8_ErrSrc,
                         str_box_type                   const strUtf8_pszErrDescr)
{
 assert(pErrorRec);

 std::wstring err_src;
 std::wstring err_descr;

 namespace utf8=structure::charsets::cs_utf8;

 //-----------------------------------------
 utf8::t_cs_cvt_result cvt_result=utf8::cs_cvt_result__ok;

 utf8::utf8_to_ucs2(strUtf8_ErrSrc.begin(),
                    strUtf8_ErrSrc.end(),
                    std::back_inserter(err_src),
                    &cvt_result);

 assert(cvt_result==utf8::cs_cvt_result__ok);

 //-----------------------------------------
 utf8::utf8_to_ucs2(strUtf8_pszErrDescr.begin(),
                    strUtf8_pszErrDescr.end(),
                    std::back_inserter(err_descr),
                    &cvt_result);

 assert(cvt_result==utf8::cs_cvt_result__ok);

 //-----------------------------------------

 return self_type::error_rec__check_partial_data(tracer,
                                                 pErrorRec,
                                                 lcid,
                                                 err_src,
                                                 err_descr);
}//error_rec__check_partial_data__utf8

//------------------------------------------------------------------------
bool TestCheckErrors::error_rec__check_sqlstate_and_native_code
                                        (TTSO_Tracer&                         tracer,
                                         const structure::t_err_record* const pErrorRec,
                                         wstr_box_type                  const lpwszSqlState,
                                         LONG                           const lNativeErrorCode)
{
 assert(pErrorRec!=nullptr);

 tracer<<L"Check sqlstate and native error code ... "<<send;

 const ibp::t_ibp_error_element*
  const pErrElement=dynamic_cast<const ibp::t_ibp_error_element*>(pErrorRec);

 if(pErrElement==nullptr)
 {
  tracer(tso_msg_error,-1)<<L"Unexpected error record type. We wait the ibp::t_ibp_error_element."<<send;

  return false;
 }//if

 if(!pErrElement->m_spGetCustomError)
 {
  tracer(tso_msg_error,-1)<<L"No CustomError object."<<send;

  return false;
 }//if

 DECLARE_IPTR_TYPE(ISQLErrorInfo);

 const ISQLErrorInfoPtr
  spSQLErrorInfo
   (pErrElement->m_spGetCustomError->get_custom_error_object
     (nullptr,
      ole_lib::TBaseUnknown2__SERVER_LINK::Create_REAL()));

 if(!spSQLErrorInfo)
 {
  assert(FAILED(spSQLErrorInfo.m_hr));

  tracer(tso_msg_error,-1)<<L"Failed to query ISQLErrorInfo interface. hr: "<<ole_lib::TestHResult(spSQLErrorInfo.m_hr)<<send;

  return false;
 }//if

 bool resultValue=true;

 {
  ole_lib::TBSTR err_bstrSqlState;

  LONG err_lNativeErrorCode=0;

  HRESULT const hr=spSQLErrorInfo->GetSQLInfo(&err_bstrSqlState.ref_bstr(),
                                              &err_lNativeErrorCode);

  if(hr!=S_OK)
  {
   tracer(tso_msg_error,-1)<<L"Failed to get the SQLInfo: "<<ole_lib::TestHResult(hr)<<send;

   return false;
  }//if

  if(err_bstrSqlState.bstr()==nullptr)
  {
   resultValue=false;

   tracer(tso_msg_error,-1)<<L"GetSQLInfo return a NULL pointer to SqlState"<<send;
  }
  else
  if(!lpwszSqlState.equal(err_bstrSqlState.bstr(),
                          err_bstrSqlState.length()))
  {
   resultValue=false;

   tracer(tso_msg_error,-1)
    <<L"Bad SQLSTATE: \""<<err_bstrSqlState.bstr()<<L"\". We wait the: \""<<lpwszSqlState<<L"\"."
    <<send;
  }
  else
  {
   tracer<<L"OK. SQLSTATE: \""<<err_bstrSqlState.bstr()<<L"\"."
    <<send;
  }//else

  if(err_lNativeErrorCode!=lNativeErrorCode)
  {
   resultValue=false;

   tracer(tso_msg_error,-1)
    <<L"Bad NativeErrCode: "<<err_lNativeErrorCode<<L". We wait the: "<<lNativeErrorCode<<L"."
    <<send;
  }
  else
  {
   tracer<<L"OK. NativeErrCode: "<<err_lNativeErrorCode<<L"."
    <<send;
  }//else
 }//local

 return resultValue;
}//error_rec__check_sqlstate_and_native_code

//------------------------------------------------------------------------
bool TestCheckErrors::check_text(TTSO_Tracer&                 tracer,
                                 ibprovider::IBP_IText* const pText,
                                 LCID                   const lcid,
                                 wstr_box_type          const pwszText)
{
 assert(pText!=nullptr);

 tracer<<L"Check text ..."<<send;

 ole_lib::TBSTR bstrText;

 const HRESULT get_hr=pText->GetText(lcid,&bstrText.ref_bstr());

 if(FAILED(get_hr))
 {
  tracer(tso_msg_error,-1)
   <<L"Failed to get the text"
   <<send;

  return false;
 }//if

 std::wstring wstrText(bstrText.wstr());

 helper__replace_rn_to_n(&wstrText);

 bool result=true;

 if(!pwszText.equal(wstrText))
 {
  result=false;

  tracer(tso_msg_error,-1)
   <<L"Wrong Text : \""<<wstrText<<L"\".\n"
   <<L"We expected: \""<<pwszText<<L"\""
   <<send;
 }//if
 else
 {
  tracer
   <<L"OK. Text: \""<<wstrText<<L"\""
   <<send;
 }//else

 return result;
}//check_text

//------------------------------------------------------------------------
bool TestCheckErrors::check_text__utf8(TTSO_Tracer&                 tracer,
                                       ibprovider::IBP_IText* const pText,
                                       LCID                   const lcid,
                                       const char*            const pszUtf8)
{
 assert(pText!=nullptr);

 return self_type::check_text(tracer,
                              pText,
                              lcid,
                              utf8_to_wstring(pszUtf8));
}//check_text__utf8

//------------------------------------------------------------------------
std::wstring TestCheckErrors::utf8_to_wstring(structure::t_const_str_box const strboxUtf8)
{
 std::wstring wstr;

 namespace utf8=structure::charsets::cs_utf8;

 utf8::t_cs_cvt_result cvt_result=utf8::cs_cvt_result__ok;

 utf8::utf8_to_ucs2(strboxUtf8.begin(),
                    strboxUtf8.end(),
                    back_inserter(wstr),
                    &cvt_result);

 assert(cvt_result==utf8::cs_cvt_result__ok);

 return wstr;
}//utf8_to_wstring

//------------------------------------------------------------------------
void TestCheckErrors::helper__replace_rn_to_n(std::wstring* const pwstr)
{
 assert(pwstr);

 for(std::wstring::size_type x=0;x<pwstr->size();)
 {
  x=pwstr->find(L"\r\n",x);

  if(x==std::wstring::npos)
   break;

  pwstr->replace(x,2,L"\n");

  x+=1;
 }//for x
}//helper__replace_rn_to_n

//------------------------------------------------------------------------
bool TestCheckErrors::helper__bug_check(TTSO_Tracer&                         tracer,
                                        const structure::t_err_record* const pErrorRec,
                                        wstr_box_type                  const ucs2Place,
                                        wstr_box_type                  const ucs2Point,
                                        wstr_box_type                  const ucs2Reason)
{
 assert(pErrorRec!=nullptr);

 bool resultValue=true;

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="BUG-CHECK в [%1] [%2]: %3.";

  structure::wstr_formatter msgRus(utf8_to_wstring(templ_utf8));

  msgRus<<ucs2Place<<ucs2Point<<ucs2Reason;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__RUS,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgRus.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 {
  const char* const templ_utf8
   ="Bug check at [%1] [%2]: %3.";

  structure::wstr_formatter msgEng(utf8_to_wstring(templ_utf8));

  msgEng<<ucs2Place<<ucs2Point<<ucs2Reason;

  if(!self_type::error_rec__check_data(tracer,
                                       pErrorRec,
                                       self_type::lcid__ENG,
                                       utf8_to_wstring(self_type::sm_srcID__IBProvider),
                                       msgEng.str()))
  {
   resultValue=false;
  }//if
 }//local

 //-----------------------------------------
 return resultValue;
}//helper__bug_check

//------------------------------------------------------------------------
std::wstring TestCheckErrors::IBP_EscapingText(structure::t_const_wstr_box const text)
{
 std::wstring result;

 for(structure::t_const_wstr_box::iterator i(text.begin()),
                                          _e(text.end());
     i!=_e;
     ++i)
 {
  switch(*i)
  {
   case L'\\':
    result+=L"\\\\";
    break;

   case L'\0':
    result+=L"\\0";
    break;

   case L'\t':
    result+=L"\\t";
    break;

   case L'\r':
    result+=L"\\r";
    break;

   case L'\n':
    result+=L"\\n";
    break;
  
   default:
    result+=*i;
    break;
  }//switch *i
 }//for[ever]

 return result;
}//IBP_EscapingText

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_test*/
