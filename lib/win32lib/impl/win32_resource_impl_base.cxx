////////////////////////////////////////////////////////////////////////////////
//Win32 library implementation.
//                                               Dmitry Kovalenko. 13.08.2004.

////////////////////////////////////////////////////////////////////////////////

HGLOBAL Resource_LoadByLangEx(HINSTANCE         const hInstance,
                              LPCTSTR           const resType,
                              TResID            const resID,
                              DWORD*            const pcbResource,
                              structure::t_lcid const lcid)
{
 const LANGID c_lang_neutral=MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL);

 if(pcbResource!=nullptr)
  (*pcbResource)=0;

 LANGID lang_id=c_lang_neutral;

 if(lcid.get_kind()==structure::t_lcid::kind__number)
  lang_id=LANGIDFROMLCID(lcid.get_number());
 
 HRSRC hrRes=FindResourceEx(hInstance,resType,resID,lang_id);

 if(!hrRes && lang_id!=c_lang_neutral)
  hrRes=FindResourceEx(hInstance,resType,resID,c_lang_neutral);

 if(!hrRes)
  return NULL;

 if(pcbResource!=nullptr)
  (*pcbResource)=::SizeofResource(hInstance,hrRes);

 return LoadResource(hInstance,hrRes);
}//Resource_LoadByLang

////////////////////////////////////////////////////////////////////////////////
