////////////////////////////////////////////////////////////////////////////////
//Win32 library implementation.
//                                               Dmitry Kovalenko. 12.08.2004.

////////////////////////////////////////////////////////////////////////////////
//Utilities for work with "Message Table" resource

const MESSAGE_RESOURCE_ENTRY* MsgTable_FindEntry(const MESSAGE_RESOURCE_DATA* pMsgData,
                                                 UINT                         msgID)
{
 const BYTE* const pResource=reinterpret_cast<const BYTE*>(pMsgData);

 //search required block
 const MESSAGE_RESOURCE_BLOCK*       pCurBlock=pMsgData->Blocks;
 const MESSAGE_RESOURCE_BLOCK* const pEndBlock=pCurBlock+pMsgData->NumberOfBlocks;

 for(;pCurBlock!=pEndBlock;++pCurBlock)
 {
  CHECK_READ_PTR(pCurBlock,sizeof(*pCurBlock));

  if(pCurBlock->LowId<=msgID && msgID<=pCurBlock->HighId)
   break;
 }//for pCurBlock

 if(pCurBlock==pEndBlock)
  return nullptr;

 size_t OffsetToEntry=pCurBlock->OffsetToEntries;

 msgID-=pCurBlock->LowId;

 const MESSAGE_RESOURCE_ENTRY* pEntry;

 for(;;)
 {
  pEntry=reinterpret_cast<const MESSAGE_RESOURCE_ENTRY*>(pResource+OffsetToEntry);

  CHECK_READ_PTR(pEntry,sizeof(*pEntry));

  //проверка длины элемента
  if(pEntry->Length<offsetof(MESSAGE_RESOURCE_ENTRY,Text))
   return nullptr;

  if(msgID==0)
   break;

  --msgID;

  //пропускаем элемент.
  OffsetToEntry+=pEntry->Length;
 }//for[ever]

 return pEntry;
}//MsgTable_FindEntry

//------------------------------------------------------------------------
template<typename charT>
void MsgTable_MessageNormalzation(__STL_DEF_BASIC_STRING(charT)& msg)
{
 typedef __STL_DEF_BASIC_STRING(charT) string_type;

 //----------------------------------------- removing of terminal nulls
 {
  typename string_type::iterator const b(msg.begin());
  typename string_type::iterator const e(msg.end());
  typename string_type::iterator       p(e);

  while(p!=b)
  {
   --p;

   if((*p)==0)
    continue;

   ++p;
   break;
  }//while

  assert(p>=b);
  assert(p<=e);

  msg.erase(p,e);
 }//local

 const string_type::size_type _c=msg.size();

 typedef structure::t_char_traits2<charT> _ct2;

 //----------------------------------------- removing terminal "\r\n"
 if(_c>=2)
 {
  if(msg[_c-2]==_ct2::ch_return_line() && msg[_c-1]==_ct2::ch_new_line())
  {
   msg.erase(_c-2);
   return;
  }
 }//if

 //----------------------------------------- removing terminal "\n"
 if(_c>=1)
 {
  if(msg[_c-1]==_ct2::ch_new_line())
  {
   msg.erase(_c-1);
   return;
  }
 }//if
}//MsgTable_MessageNormalzation

//------------------------------------------------------------------------
std::wstring& MsgTable_GetMessage(const MESSAGE_RESOURCE_ENTRY* pEntry,
                                  std::wstring&                 wstr,
                                  bool*                         error,
                                  UINT                          cpID)
{
 assert(pEntry!=nullptr);

 wstr.clear();

 if(error)
  (*error)=true;

 if(pEntry==nullptr)
  return wstr;

 const size_t TextLength=pEntry->Length-offsetof(MESSAGE_RESOURCE_ENTRY,Text);

 CHECK_READ_PTR(pEntry->Text,TextLength);

 if((pEntry->Flags&0x0001)==0)
 {
  //ANSI text (need convert)
  structure::ansi_to_unicode
   (&wstr,
    reinterpret_cast<const char*>(pEntry->Text),
    TextLength,
    error,
    cpID);

  MsgTable_MessageNormalzation(wstr);

  return wstr;
 }//if

 //UNICODE text
 wstr.assign(reinterpret_cast<const wchar_t*>(pEntry->Text),
             TextLength/sizeof(wchar_t));

 if(error)
  (*error)=false;

 MsgTable_MessageNormalzation(wstr);

 return wstr;
}//MsgTable_GetMessage

//------------------------------------------------------------------------
std::string& MsgTable_GetMessage(const MESSAGE_RESOURCE_ENTRY* pEntry,
                                 std::string&                  str,
                                 bool*                         error,
                                 UINT                          cpID)
{
 assert(pEntry!=nullptr);

 str.clear();

 if(error)
  (*error)=true;

 if(pEntry==nullptr)
  return str;

 const size_t TextLength=pEntry->Length-offsetof(MESSAGE_RESOURCE_ENTRY,Text);

 CHECK_READ_PTR(pEntry->Text,TextLength);

 if((pEntry->Flags&0x0001)!=0)
 {
  //UNICODE text (need convert)
  structure::unicode_to_ansi
   (&str,
    reinterpret_cast<const wchar_t*>(pEntry->Text),
    TextLength/sizeof(wchar_t),
    error,
    cpID);

  MsgTable_MessageNormalzation(str);

  return str;
 }//if UNICODE message

 if(error)
  (*error)=false;

 //ANSI text (convert is not needed)
 str.assign(reinterpret_cast<const char*>(pEntry->Text),TextLength);

 MsgTable_MessageNormalzation(str);

 return str;
}//MsgTable_GetMessage

////////////////////////////////////////////////////////////////////////////////
