////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_resources.cpp
//! \brief   Конструкции для работы с ресурсами модуля
//! \author  Kovalenko Dmitry
//! \date    03.12.2014
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_resources.h"
#include "rc/ibp_msg.rh"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class TIBP_MsgTableLoader

TIBP_MsgTableLoader::TIBP_MsgTableLoader(module_type* const pModule,
                                         res_id_type  const resID)
 :inherited(pModule,resID,CP_UTF8)
{
}//TIBP_MsgTableLoader

//------------------------------------------------------------------------
TIBP_MsgTableLoader::~TIBP_MsgTableLoader()
{
}//~TIBP_MsgTableLoader

//interface --------------------------------------------------------------
TIBP_MsgTableLoader::error_code_type TIBP_MsgTableLoader::GetMessage
                                           (const UINT      msgID,
                                            const lcid_type lcid,
                                            std::wstring&   str)const
{
 return inherited::GetMessage(msgID,lcid,str);
}//GetMessage

//------------------------------------------------------------------------
std::wstring& TIBP_MsgTableLoader::GetMessage_Throw
                                           (const UINT      msgID,
                                            const lcid_type lcid,
                                            std::wstring&   str)const
{
 return inherited::GetMessage_Throw(msgID,lcid,str);
}//GetMessage_Throw

////////////////////////////////////////////////////////////////////////////////
//class TIBP_MessageLoader

TIBP_MessageLoader::TIBP_MessageLoader(const TIBP_MsgTableLoader* const pMsgTableLoader,
                                       LANGID                     const wLanguage)
 :m_pMsgTableLoader(pMsgTableLoader)
 ,m_LocaleID(MAKELCID(wLanguage,0))
{
 assert(m_pMsgTableLoader!=nullptr);
}//TIBP_MessageLoader

//-----------------------------------------------------------------------
TIBP_MessageLoader::string_type& TIBP_MessageLoader::throw_load_str
                                           (UINT const   msgID,
                                            string_type& str)const
{
 assert(m_pMsgTableLoader!=nullptr);

 return m_pMsgTableLoader->GetMessage_Throw
         (msgID,
          m_LocaleID,
          str);//throw
}//throw_load_str

//-----------------------------------------------------------------------
TIBP_MessageLoader::string_type TIBP_MessageLoader::throw_load_str
                                           (UINT const msgID)const
{
 assert(m_pMsgTableLoader!=nullptr);

 string_type s;

 return this->throw_load_str(msgID,s);//throw
}//throw_load_str

////////////////////////////////////////////////////////////////////////////////
//Loaders

TIBP_ResourceLoader _ResourceLoader;

TIBP_MsgTableLoader _ErrMsgTableLoader
                      (&_ResourceLoader,
                       IBP_MSG_TABLE_ERR);

TIBP_MsgTableLoader _UiMsgTableLoader
                      (&_ResourceLoader,
                       IBP_MSG_TABLE_UI);

TIBP_MsgTableLoader _SubSystemNameTableLoader
                      (&_ResourceLoader,
                       IBP_MSG_TABLE_SUBSYSTEMS);

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
