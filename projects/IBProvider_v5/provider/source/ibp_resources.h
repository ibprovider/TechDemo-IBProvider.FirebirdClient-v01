////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_resources.h
//! \brief   Конструкции для работы с ресурсами модуля
//! \author  Kovalenko Dmitry
//! \date    03.12.2014
#ifndef _ibp_resources_H_
#define _ibp_resources_H_

#include <win32lib/win32_resource.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

class TIBP_ResourceLoader;
class TIBP_MessageLoader;

////////////////////////////////////////////////////////////////////////////////

inline LANGID IBP_GetUserDefaultLangID()
{
 return MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL);
}//IBP_GetUserDefaultLangID

//------------------------------------------------------------------------
inline LCID IBP_GetUserDefaultLCID()
{
 return MAKELCID(IBP_GetUserDefaultLangID(), SORT_DEFAULT);
}//IBP_GetUserDefaultLCID

////////////////////////////////////////////////////////////////////////////////
//class TIBP_ResourceLoader

class TIBP_ResourceLoader LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef TIBP_ResourceLoader               self_type;

 public:
  typedef win32lib::TResID                  res_id_type;
  typedef structure::t_lcid                 lcid_type;

  typedef const self_type*                  self_ptr;

 public:
  static HGLOBAL LoadResourceLangEx(LPCTSTR     const resType,
                                    res_id_type const resID,
                                    DWORD*      const pcbResource,
                                    lcid_type   const lcid)
  {
   assert(_Module.GetModuleInstance()!=NULL);

   return win32lib::Resource_LoadByLangEx
            (_Module.GetModuleInstance(),
             resType,
             resID,
             pcbResource,
             lcid);
  }//LoadResourceLangEx

  //----------------------------------------------------------------------
  HGLOBAL LoadResourceLangEx(LPCTSTR     const resType,
                             res_id_type const resID,
                             DWORD*      const pcbResource=nullptr)
  {
   assert(_Module.GetModuleInstance()!=NULL);

   return this->LoadResourceLangEx
            (resType,
             resID,
             pcbResource,
             MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL));
  }//LoadResourceLangEx
};//class TIBP_ResourceLoader

////////////////////////////////////////////////////////////////////////////////
//class TIBP_MsgTableLoader

class TIBP_MsgTableLoader LCPI_CPP_CFG__CLASS__FINAL
 :private win32lib::TMsgTableLoader<TIBP_ResourceLoader>
{
 private:
  typedef TIBP_MsgTableLoader                              self_type;
  typedef win32lib::TMsgTableLoader<TIBP_ResourceLoader>   inherited;

  TIBP_MsgTableLoader(const self_type&);
  self_type& operator = (const self_type);

 public:
  using inherited::error_code_type;

  using inherited::err_none;
  using inherited::err_invalid_res_id;
  using inherited::err_invalid_msg_id;
  using inherited::err_fail_convert;

 public:
  TIBP_MsgTableLoader(module_type* pModule,res_id_type resID);

 ~TIBP_MsgTableLoader();

  //interface ------------------------------------------------------------
  error_code_type GetMessage(const UINT      msgID,
                             const lcid_type lcid,
                             std::wstring&   str)const;

  std::wstring& GetMessage_Throw(const UINT      msgID,
                                 const lcid_type lcid,
                                 std::wstring&   str)const; //throw
};//class TIBP_MsgTableLoader

////////////////////////////////////////////////////////////////////////////////
//class TIBP_MessageLoader

class TIBP_MessageLoader LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef TIBP_MessageLoader                    self_type;

  TIBP_MessageLoader(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef win32lib::TResID                      res_id_type;

  typedef win32lib::t_string                    string_type;

 public:
  TIBP_MessageLoader(const TIBP_MsgTableLoader* pMsgTableLoader,
                     LANGID                     wLanguage);

 public:
  string_type& throw_load_str(UINT         msgID,
                              string_type& str)const;//throw

  string_type throw_load_str(UINT msgID)const;//throw

 private:
  const TIBP_MsgTableLoader* const m_pMsgTableLoader;

  const LCID m_LocaleID;
};//class TIBPMessageLoader

////////////////////////////////////////////////////////////////////////////////
//Loaders

extern TIBP_ResourceLoader _ResourceLoader;

extern TIBP_MsgTableLoader _ErrMsgTableLoader;
extern TIBP_MsgTableLoader _UiMsgTableLoader;
extern TIBP_MsgTableLoader _SubSystemNameTableLoader;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
