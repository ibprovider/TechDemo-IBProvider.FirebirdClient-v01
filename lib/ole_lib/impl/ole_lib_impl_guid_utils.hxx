////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//CLSID<-->TEXT conversions

#if 0 // [2022-09-22] Temporary removed. They must have a different meaning.

std::wstring   clsid_to_wstring(REFCLSID);

std::string    clsid_to_string(REFCLSID);

t_string       clsid_to_tstr(REFCLSID);

#endif // if 0

//------------------------------------------------------------------------
HRESULT string_to_clsid(structure::wstr_parameter const str_clsid,GUID* const pclsid);

HRESULT string_to_clsid(structure::str_parameter const str_clsid,GUID* const pclsid);

////////////////////////////////////////////////////////////////////////////////
//GUID to TEXT

using lcpi::lib::com::base::guid_to_wstring;

using lcpi::lib::com::base::guid_to_string;

structure::t_string guid_to_tstr(REFGUID guid);

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
