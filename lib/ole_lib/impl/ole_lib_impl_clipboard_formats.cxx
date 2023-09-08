////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//Standard clipboard formats

const CLIPFORMAT CF_IDLIST                =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_SHELLIDLIST);
const CLIPFORMAT CF_OBJECTPOSITIONS       =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_SHELLIDLISTOFFSET);
const CLIPFORMAT CF_NETRESOURCE           =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_NETRESOURCES);
const CLIPFORMAT CF_FILEGROUPDESCRIPTORA  =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_FILEDESCRIPTORA);
const CLIPFORMAT CF_FILEGROUPDESCRIPTORW  =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_FILEDESCRIPTORW);
const CLIPFORMAT CF_FILECONTENTS          =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_FILECONTENTS);
const CLIPFORMAT CF_FILENAMEA             =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_FILENAMEA);
const CLIPFORMAT CF_FILENAMEW             =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_FILENAMEW);
const CLIPFORMAT CF_PRINTERS              =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_PRINTERGROUP);
const CLIPFORMAT CF_FILENAMEMAPA          =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_FILENAMEMAPA);
const CLIPFORMAT CF_FILENAMEMAPW          =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_FILENAMEMAPW);

const CLIPFORMAT CF_SHELLURL              =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_SHELLURL);
const CLIPFORMAT CF_PREFERREDDROPEFFECT   =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_PREFERREDDROPEFFECT);
const CLIPFORMAT CF_PERFORMEDDROPEFFECT   =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_PERFORMEDDROPEFFECT);
const CLIPFORMAT CF_PASTESUCCEEDED        =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_PASTESUCCEEDED);
const CLIPFORMAT CF_INDRAGLOOP            =(CLIPFORMAT)::RegisterClipboardFormat(CFSTR_INDRAGLOOP);

//[2018-02-17]
// #ifndef _NO_ODS_
// void TRACE_FORMATETC(LPCTSTR msg,LPFORMATETC pFormatetc)
// {
// 
//  if(pFormatetc==NULL)
//   return;
// 
//  TCHAR format_name[256];
// 
//  memset(format_name,0,sizeof(format_name));
// 
//  const int len=::GetClipboardFormatName(pFormatetc->cfFormat,
//                                         format_name,
//                                         _DIM_(format_name));
// 
//  assert(len>=0);
//  assert(len<=_DIM_(format_name));
// 
//  DebugMessage(msg<<": "<<pFormatetc->cfFormat
//               <<": \""<<tstr_to_str(format_name,len)<<"\", "
//               "tymed=="<<pFormatetc->tymed
//               <<" Aspect=="<<pFormatetc->dwAspect);
// }
// #endif //ifndef _NO_ODS_

////////////////////////////////////////////////////////////////////////////////
