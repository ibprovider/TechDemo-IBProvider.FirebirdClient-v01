////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__path_utils.cpp
//! \brief   Utilities for work with paths
//! \author  Kovalenko Dmitry
//! \date    25.09.2022
#include <_pch_.h>
#pragma hdrstop

#include "source/os/win32/ibp_os_win32__path_utils.h"

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__path_utils

t_ibp_str_box t_ibp_os_win32__path_utils::GetParentDir(const t_ibp_str_box& path)
{
 const t_ibp_str_box path2
  =self_type::Helper__NormalizationPath
    (path);

 for(size_t pathSize=path2.size();pathSize!=0;)
 {
  --pathSize;

  switch(path2[pathSize])
  {
   case IBP_T('\\'):
   case IBP_T('/'):
    return self_type::Helper__NormalizationPath(path2.substr(0,pathSize));

   case IBP_T(':'):
    return path2.substr(0,pathSize+1);

   default:
    continue;
  }//switch

  assert(false);
 }//for[ever]

 return path2.substr(0,0);
}//GetParentDir

//------------------------------------------------------------------------
t_ibp_string t_ibp_os_win32__path_utils::Concat
                             (const t_ibp_str_box& path1,
                              const t_ibp_str_box& path2)
{
 const t_ibp_str_box path1n
  =self_type::Helper__NormalizationPath
    (path1);

 if(path1n.empty())
  return path2.make_str();

 if(path2.empty())
  return path1n.make_str();

 t_ibp_string r;

 r.reserve(path1.size()+1+path2.size());

 r.append(path1n.begin(),path1n.end());
 r+=IBP_T('\\');
 r.append(path2.begin(),path2.end());

 return r;
}//Concat

//Helper members ---------------------------------------------------------
t_ibp_str_box t_ibp_os_win32__path_utils::Helper__NormalizationPath(const t_ibp_str_box& path)
{
 for(size_t n=path.size();n!=0;)
 {
  --n;

  switch(path[n])
  {
   case IBP_T('\\'):
   case IBP_T('/'):
    continue;

   default:
    return path.substr(0,n+1);
  }//switch
 }//for[ever]

 return path.substr(0,0);
}//Helper__NormalizationPath

////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
