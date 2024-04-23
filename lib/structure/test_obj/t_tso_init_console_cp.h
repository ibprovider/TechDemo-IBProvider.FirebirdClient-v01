////////////////////////////////////////////////////////////////////////////////
//Setup a console codepage
//                                                 Dmitry Kovalenko. 12.04.2024.
#ifndef _t_tso_init_console_cp_H_
#define _t_tso_init_console_cp_H_

#include <lcpi/lib/.config.h>

#include <exception>

#ifdef _WIN32
# include <Windows.h>
#endif

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//class t_tso_init_console_cp

#ifdef _WIN32

class t_tso_init_console_cp LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_tso_init_console_cp;

  t_tso_init_console_cp(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  t_tso_init_console_cp()
   :m_PrevConsoleCP(::GetConsoleOutputCP())
  {
   const BOOL r=::SetConsoleOutputCP(CP_UTF8);

   LCPI__assert_s(FALSE==0);

   if(r==FALSE)
    throw ::std::runtime_error("[t_tso_init_console_cp] SetConsoleOutputCP failed.");
  }//t_tso_init_console_cp

 ~t_tso_init_console_cp()
  {
   LCPI__DEBUG_CODE(const BOOL r=)::SetConsoleOutputCP(m_PrevConsoleCP);

   LCPI__assert_s(FALSE==0);

   LCPI__assert(r!=FALSE);
  }//~t_tso_init_console_cp

 private:
  UINT const m_PrevConsoleCP;
};//class t_tso_init_console_cp

#else

class t_tso_init_console_cp LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_tso_init_console_cp;

  t_tso_init_console_cp(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  t_tso_init_console_cp()
  {
  }

 ~t_tso_init_console_cp()
  {
  }

 private:
};//class t_tso_init_console_cp

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms tso_obj*/}/*nms structure*/
#endif
