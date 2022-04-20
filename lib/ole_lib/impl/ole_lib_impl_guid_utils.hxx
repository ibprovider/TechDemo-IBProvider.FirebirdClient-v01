////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//CLSID<-->TEXT conversions

std::wstring   clsid_to_wstring(REFCLSID);

std::string    clsid_to_string(REFCLSID);

t_string       clsid_to_tstr(REFCLSID);

//------------------------------------------------------------------------
HRESULT string_to_clsid(structure::wstr_parameter const str_clsid,GUID* const pguid);

HRESULT string_to_clsid(structure::str_parameter const str_clsid,GUID* const pguid);

////////////////////////////////////////////////////////////////////////////////
//GUID to TEXT

std::wstring   guid_to_wstring(REFGUID guid);

std::string    guid_to_string(REFGUID guid);

t_string       guid_to_tstr(REFGUID guid);

////////////////////////////////////////////////////////////////////////////////
//compare guids

inline int GuidCompare_3Way(REFGUID guid1,REFGUID guid2)
 {return memcmp(&guid1,&guid2,sizeof(GUID));}

inline bool GuidEqual(REFGUID guid1,REFGUID guid2)
 {return GuidCompare_3Way(guid1,guid2)==0;}

inline bool GuidLess(REFGUID guid1,REFGUID guid2)
 {return GuidCompare_3Way(guid1,guid2)<0;}

////////////////////////////////////////////////////////////////////////////////
//class TGuidLess

class TGuidLess
{
 public:
  TGuidLess()
  {
  }//TGuidLess

  bool operator () (REFGUID guid1,REFGUID guid2)const
  {
   return GuidLess(guid1,guid2);
  }
};//class TGuidLess

////////////////////////////////////////////////////////////////////////////////
