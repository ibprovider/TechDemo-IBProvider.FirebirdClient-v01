////////////////////////////////////////////////////////////////////////////////
//class TBaseMsgTableLoader

const TBaseMsgTableLoader::err_msg_entry_type TBaseMsgTableLoader::sm_msgs[3]=
{
 {err_invalid_res_id,
  "Invalid message table resource ID [%1]. Lang ID [%2]."},

 {err_invalid_msg_id,
  "Invalid message table entry ID [%3]. Resource ID [%1]. Lang ID [%2]."},

 {err_fail_convert,
  "Fail convert message. Resource ID [%1]. Lang ID [%2]. Entry ID [%3]."}
};//sm_msgs

//------------------------------------------------------------------------
std::string TBaseMsgTableLoader::BuildErrorMsg(error_code_type const error_code,
                                               res_id_type     const resID,
                                               lcid_type       const lcid,
                                               UINT            const msgID)const
{
 structure::str_formatter fmsg;

 if(const err_msg_entry_type* const p=std::find(sm_msgs,_END_(sm_msgs),error_code))
 {
  fmsg.init(p->msg);
 }
 else
 {
  fmsg.init("Unknown error with message table resource [%4].\n"
            "Resource ID [%1]. Lang ID [%2]. Entry ID [%3].");
 }//else

 fmsg<<resID.Wrap()<<lcid.get_number()<<msgID<<size_t(error_code);

 return fmsg.str();
}//BuildErrorMsg

//------------------------------------------------------------------------
void TBaseMsgTableLoader::ThrowError(error_code_type const error_code,
                                     res_id_type     const resID,
                                     lcid_type       const lcid,
                                     UINT            const msgID)const//throw
{
 throw std::runtime_error(BuildErrorMsg(error_code,resID,lcid,msgID));
}//ThrowError

////////////////////////////////////////////////////////////////////////////////

