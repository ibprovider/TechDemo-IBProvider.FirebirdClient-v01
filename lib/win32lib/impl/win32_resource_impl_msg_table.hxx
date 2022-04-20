////////////////////////////////////////////////////////////////////////////////
//Win32 library implementation.
//                                               Dmitry Kovalenko. 12.08.2004.

////////////////////////////////////////////////////////////////////////////////
//Utilities for work with "Message Table" resource

//Search Message Entry

const MESSAGE_RESOURCE_ENTRY* MsgTable_FindEntry(const MESSAGE_RESOURCE_DATA* pMsgData,
                                                 UINT                         msgID);

//------------------------------------------------------------------------
//get message as UNICODE string

//error=true - fail convert from ansi to unicode

std::wstring& MsgTable_GetMessage(const MESSAGE_RESOURCE_ENTRY*,
                                  std::wstring& wstr,
                                  bool*         error,
                                  UINT          cpID);

//------------------------------------------------------------------------
//get message as ANSI string

//error=true - fail convert from unicode to ansi

std::string& MsgTable_GetMessage(const MESSAGE_RESOURCE_ENTRY*,
                                 std::string&   str,
                                 bool*          error,
                                 UINT           cpID);

////////////////////////////////////////////////////////////////////////////////

