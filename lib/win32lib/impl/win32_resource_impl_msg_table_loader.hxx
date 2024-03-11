////////////////////////////////////////////////////////////////////////////////
//Win32 Library implementation.
//                                                Dmitry Kovalenko. 05.09.2004.

////////////////////////////////////////////////////////////////////////////////
//containings

class TBaseMsgTableLoader;

template<class TResourceModule>
class TMsgTableLoader;

////////////////////////////////////////////////////////////////////////////////
//class TBaseMsgTableLoader

class TBaseMsgTableLoader
{
 private:
  using self_type=TBaseMsgTableLoader;

 public: //typedefs ------------------------------------------------------
  using res_id_type=TResID;

  using lcid_type=structure::t_lcid;

  enum enum_error_code
  {
   err_none             = 0,
   err_invalid_res_id   = 1,
   err_invalid_msg_id   = 2,
   err_fail_convert     = 3,
  };//enum_error_code

  using error_code_type=enum_error_code;

 protected:
  TBaseMsgTableLoader(){;}

  //----------------------------------------------------------------------
  std::string BuildErrorMsg(error_code_type,
                            res_id_type    ,
                            lcid_type      lcid,
                            UINT           msgID)const;

  //----------------------------------------------------------------------
  //throw runtime_error
  void ThrowError(error_code_type,
                  res_id_type    ,
                  lcid_type      lcid,
                  UINT           msgID)const;//throw

 private:
  typedef structure::t_message_entry<error_code_type,const char*>  err_msg_entry_type;

  static const err_msg_entry_type sm_msgs[3];
};//class TBaseMsgTableLoader

////////////////////////////////////////////////////////////////////////////////
//class TMsgTableLoader

template<class TResourceModule>
class TMsgTableLoader
 :public TBaseMsgTableLoader
{
 private:
  using self_type=TMsgTableLoader<TResourceModule>;
  using inherited=TBaseMsgTableLoader;

  TMsgTableLoader(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using module_type=TResourceModule;

  using module_ptr=typename module_type::self_ptr;

  using res_id_type=inherited::res_id_type;

  using lcid_type=inherited::lcid_type;

  using error_code_type=inherited::error_code_type;

 public:
  TMsgTableLoader();

  TMsgTableLoader(module_type* pModule,res_id_type resID,UINT cpID);

 ~TMsgTableLoader();

  //---------------------------------------------------------------------
  void Init(module_type* pModule,res_id_type resID,UINT cpID);

  res_id_type GetResID()const;

  //---------------------------------------------------------------------
  error_code_type GetMessage(const UINT      msgID,
                             const lcid_type lcid,
                             std::wstring&   str)const;

  error_code_type GetMessage(const UINT      msgID,
                             const lcid_type lcid,
                             std::string&    str)const;

  //---------------------------------------------------------------------
  std::wstring& GetMessage_Always(const UINT      msgID,
                                  const lcid_type lcid,
                                  std::wstring&   str)const;

  std::string&  GetMessage_Always(const UINT      msgID,
                                  const lcid_type lcid,
                                  std::string&    str)const;

  //---------------------------------------------------------------------
  std::wstring& GetMessage_Throw(const UINT      msgID,
                                 const lcid_type lcid,
                                 std::wstring&   str)const; //throw

  std::string&  GetMessage_Throw(const UINT      msgID,
                                 const lcid_type lcid,
                                 std::string&    str)const; //throw

 private:
  module_ptr   m_spModule;
  res_id_type  m_resID;
  UINT         m_cpID;
};//class TMsgTableLoader

////////////////////////////////////////////////////////////////////////////////
//class TMsgTableLoader

template<class TResourceModule>
TMsgTableLoader<TResourceModule>::TMsgTableLoader()
 :m_spModule()
 ,m_resID()
 ,m_cpID(CP_ACP)
{
}

//------------------------------------------------------------------------
template<class TResourceModule>
TMsgTableLoader<TResourceModule>::TMsgTableLoader(module_type* pModule,
                                                  res_id_type  resID,
                                                  UINT         cpID)
 :m_spModule(pModule)
 ,m_resID(resID)
 ,m_cpID(cpID)
{
}

//------------------------------------------------------------------------
template<class TResourceModule>
TMsgTableLoader<TResourceModule>::~TMsgTableLoader()
{
}

//------------------------------------------------------------------------
template<class TResourceModule>
void TMsgTableLoader<TResourceModule>::Init(module_type* pModule,
                                            res_id_type  resID,
                                            UINT         cpID)
{
 m_spModule =pModule;
 m_resID    =resID;
 m_cpID     =cpID;
}//Init

//------------------------------------------------------------------------
template<class TResourceModule>
typename TMsgTableLoader<TResourceModule>::res_id_type
 TMsgTableLoader<TResourceModule>::GetResID()const
{
 return m_resID;
}//GetResID

//------------------------------------------------------------------------
template<class TResourceModule>
typename TMsgTableLoader<TResourceModule>::error_code_type
 TMsgTableLoader<TResourceModule>::GetMessage(const UINT      msgID,
                                              const lcid_type lcid,
                                              std::wstring&   wstr)const
{
 assert(m_spModule);

 //open resource with messages tables
 const BYTE* const pResource
  =(const BYTE*)m_spModule->LoadResourceLangEx(RT_MESSAGETABLE,
                                               m_resID,
                                               nullptr,
                                               lcid);

 if(pResource==nullptr)
  return err_invalid_res_id;

 const MESSAGE_RESOURCE_DATA* const pMsgData=
  reinterpret_cast<const MESSAGE_RESOURCE_DATA*>(pResource);

 //find message entry
 const MESSAGE_RESOURCE_ENTRY* const pEntry=MsgTable_FindEntry(pMsgData,msgID);

 if(pEntry==nullptr)
  return err_invalid_msg_id;

 bool conv_error=true;

 //extract message text
 MsgTable_GetMessage(pEntry,wstr,&conv_error,m_cpID);

 if(conv_error)
  return err_fail_convert;

 return err_none;
}//GetMessage

//------------------------------------------------------------------------
template<class TResourceModule>
typename TMsgTableLoader<TResourceModule>::error_code_type
 TMsgTableLoader<TResourceModule>::GetMessage(const UINT      msgID,
                                              const lcid_type lcid,
                                              std::string&    str)const
{
 assert(m_spModule);

 //open resource with messages tables
 const BYTE* const pResource
  =(const BYTE*)m_spModule->LoadResourceLangEx(RT_MESSAGETABLE,
                                               m_resID,
                                               nullptr,
                                               lcid);

 if(pResource==nullptr)
  return err_invalid_res_id;

 const MESSAGE_RESOURCE_DATA* const pMsgData=
  reinterpret_cast<const MESSAGE_RESOURCE_DATA*>(pResource);

 //find message entry
 const MESSAGE_RESOURCE_ENTRY* const pEntry=MsgTable_FindEntry(pMsgData,msgID);

 if(pEntry==nullptr)
  return err_invalid_msg_id;

 bool conv_error=true;

 //extract message text
 MsgTable_GetMessage(pEntry,str,&conv_error,m_cpID);

 if(conv_error)
  return err_fail_convert;

 return err_none;
}//GetMessage

//------------------------------------------------------------------------
template<class TResourceModule>
std::wstring& TMsgTableLoader<TResourceModule>::GetMessage_Always
                                           (const UINT      msgID,
                                            const lcid_type lcid,
                                            std::wstring&   str)const //throw
{
 const error_code_type err(this->GetMessage(msgID,lcid,str));

 if(err!=err_none)
  structure::tstr_to_tstr(str,this->BuildErrorMsg(err,m_resID,lcid,msgID));

 return str;
}//GetMessage_Always - unicode

//------------------------------------------------------------------------
template<class TResourceModule>
std::string& TMsgTableLoader<TResourceModule>::GetMessage_Always
                                           (const UINT      msgID,
                                            const lcid_type lcid,
                                            std::string&    str)const //throw
{
 const error_code_type err(this->GetMessage(msgID,lcid,str));

 if(err!=err_none)
  structure::tstr_to_tstr(&str,this->BuildErrorMsg(err,m_resID,lcid,msgID));

 return str;
}//GetMessage_Always - ascii

//------------------------------------------------------------------------
template<class TResourceModule>
std::wstring& TMsgTableLoader<TResourceModule>::GetMessage_Throw
                                           (const UINT      msgID,
                                            const lcid_type lcid,
                                            std::wstring&   str)const //throw
{
 const error_code_type err(this->GetMessage(msgID,lcid,str));

 if(err!=err_none)
  this->ThrowError(err,m_resID,lcid,msgID);

 return str;
}//GetMessage_Throw

//------------------------------------------------------------------------
template<class TResourceModule>
std::string& TMsgTableLoader<TResourceModule>::GetMessage_Throw
                                          (const UINT      msgID,
                                           const lcid_type lcid,
                                           std::string&    str)const //throw
{
 const error_code_type err(this->GetMessage(msgID,lcid,str));

 if(err!=err_none)
  this->ThrowError(err,m_resID,lcid,msgID);

 return str;
}//GetMessage_Throw

////////////////////////////////////////////////////////////////////////////////
