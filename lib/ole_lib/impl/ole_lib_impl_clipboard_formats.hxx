////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

///////////////////////////////////////////////////////////////////////////////
//Standart clipboard formats

#define CFSTR_SHELLIDLIST         TEXT("Shell IDList Array")      //CF_IDLIST
#define CFSTR_SHELLIDLISTOFFSET   TEXT("Shell Object Offsets")    //CF_OBJECTPOSITIONS
#define CFSTR_NETRESOURCES        TEXT("Net Resource")            //CF_NETRESOURCE
#define CFSTR_FILEDESCRIPTORA     TEXT("FileGroupDescriptor")     //CF_FILEGROUPDESCRIPTORA
#define CFSTR_FILEDESCRIPTORW     TEXT("FileGroupDescriptorW")    //CF_FILEGROUPDESCRIPTORW
#define CFSTR_FILECONTENTS        TEXT("FileContents")            //CF_FILECONTENTS
#define CFSTR_FILENAMEA           TEXT("FileName")                //CF_FILENAMEA
#define CFSTR_FILENAMEW           TEXT("FileNameW")               //CF_FILENAMEW
#define CFSTR_PRINTERGROUP        TEXT("PrinterFriendlyName")     //CF_PRINTERS
#define CFSTR_FILENAMEMAPA        TEXT("FileNameMap")             //CF_FILENAMEMAPA
#define CFSTR_FILENAMEMAPW        TEXT("FileNameMapW")            //CF_FILENAMEMAPW
#define CFSTR_SHELLURL            TEXT("UniformResourceLocator")
#define CFSTR_PREFERREDDROPEFFECT TEXT("Preferred DropEffect")
#define CFSTR_PERFORMEDDROPEFFECT TEXT("Performed DropEffect")
#define CFSTR_PASTESUCCEEDED      TEXT("Paste Succeeded")
#define CFSTR_INDRAGLOOP          TEXT("InShellDragLoop")

extern const CLIPFORMAT CF_IDLIST                   ;
extern const CLIPFORMAT CF_OBJECTPOSITIONS          ;
extern const CLIPFORMAT CF_NETRESOURCE              ;
extern const CLIPFORMAT CF_FILEGROUPDESCRIPTORA     ;
extern const CLIPFORMAT CF_FILEGROUPDESCRIPTORW     ;
extern const CLIPFORMAT CF_FILECONTENTS             ;
extern const CLIPFORMAT CF_FILENAMEA                ;
extern const CLIPFORMAT CF_FILENAMEW                ;
extern const CLIPFORMAT CF_PRINTERS                 ;
extern const CLIPFORMAT CF_FILENAMEMAPA             ;
extern const CLIPFORMAT CF_FILENAMEMAPW             ;

extern const CLIPFORMAT CF_SHELLURL                 ;
extern const CLIPFORMAT CF_PREFERREDDROPEFFECT      ;
extern const CLIPFORMAT CF_PERFORMEDDROPEFFECT      ;
extern const CLIPFORMAT CF_PASTESUCCEEDED           ;
extern const CLIPFORMAT CF_INDRAGLOOP               ;

//[2018-02-17]
// #ifndef _NO_ODS_
// void TRACE_FORMATETC(LPCSTR msg,LPFORMATETC pFormatetc);
// #else
// #define TRACE_FORMATETC(msg,pFormamtetc)
// #endif

////////////////////////////////////////////////////////////////////////////////
