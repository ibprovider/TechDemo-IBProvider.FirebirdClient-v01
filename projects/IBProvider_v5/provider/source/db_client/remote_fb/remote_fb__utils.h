////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__utils.h
//! \brief   Набор вспомогательных утилит.
//! \author  Kovalenko Dmitry
//! \date    06.11.2014.
#ifndef _remote_fb__utils_H_
#define _remote_fb__utils_H_

#include "source/ibp_char.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Utils

class RemoteFB__Utils LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__Utils;

 public:
  using wstr_box_type=lib::structure::t_const_wstr_box;

 public:
  static bool EqualPluginNames(const wstr_box_type& name1,
                               const wstr_box_type& name2);

  static t_ibp_string GetSystemUserName();

  static t_ibp_string GetComputerName();

  static t_ibp_string GetComputerName_U();

  static t_ibp_string GetCurrentProcessName();

  static void System_CharLowerBuff
               (TCHAR*         p,
                size_t         n,
                const wchar_t* sourceSign); //throw

  static void System_CharUpperBuff
               (CHAR*          p,
                size_t         n,
                const wchar_t* sourceSign); //throw

  static void System_CharUpperBuff
               (WCHAR*         p,
                size_t         n,
                const wchar_t* sourceSign); //throw

  static void System_CharUpperBStr
               (BSTR           bstr,
                const wchar_t* sourceSign); //throw

  static const wchar_t* BuildFbClientSign();

  static t_ibp_string BuildWinSspiUserName();
};//class RemoteFB__Utils

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
