////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_common_CC_
#define _oledb_common_CC_

#include <ole_lib/ole_auto/ole_auto_utils.h>
#include <oledberr.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

inline bool oledb_succeeded(HRESULT const hr)
{
 return SUCCEEDED(hr) || hr==DB_E_ERRORSOCCURRED;
}//oledb_succeeded

//------------------------------------------------------------------------
inline bool oledb_failed(HRESULT const hr)
{
 return !oledb_lib::oledb_succeeded(hr);
}//oledb_failed

//------------------------------------------------------------------------
inline bool oledb_errorsoccurred(HRESULT const hr)
{
 return FAILED(hr) || hr==DB_S_ERRORSOCCURRED;
}//oledb_errorsoccurred

////////////////////////////////////////////////////////////////////////////////

inline bool oledb_succeeded_dbrowstatus(DBROWSTATUS const x)
{
 return x==DBROWSTATUS_S_OK              ||
        x==DBROWSTATUS_S_MULTIPLECHANGES ||
        x==DBROWSTATUS_S_PENDINGCHANGES  ||
        x==DBROWSTATUS_S_NOCHANGE;
}//oledb_succeeded_dbrowstatus

//------------------------------------------------------------------------
inline bool oledb_failed_dbrowstatus(DBROWSTATUS const x)
{
 return !oledb_lib::oledb_succeeded_dbrowstatus(x);
}//oledb_failed_dbrowstatus

////////////////////////////////////////////////////////////////////////////////
//class TBindingData

inline TBindingData::TBindingData()
{
 memset(this,0,sizeof(*this));
}

//------------------------------------------------------------------------
inline TBindingData::TBindingData(const self_type& data) //throw
{
 this->ConstructFromData(data,false);
}

//------------------------------------------------------------------------
inline TBindingData::TBindingData(const DBBINDING& data) //throw
{
 this->ConstructFromData(data,true);
}

//------------------------------------------------------------------------
inline TBindingData& TBindingData::operator = (const self_type& x)
{
 return this->Assign(x,false);
}

//------------------------------------------------------------------------
inline TBindingData& TBindingData::operator = (const DBBINDING& x)
{
 return this->Assign(x,true);
}

//------------------------------------------------------------------------
inline bool TBindingData::ParamIO__HasInput()const
{
 return (this->eParamIO&DBPARAMIO_INPUT)==DBPARAMIO_INPUT;
}//ParamIO__HasInput

//------------------------------------------------------------------------
inline bool TBindingData::ParamIO__HasOutput()const
{
 return (this->eParamIO&DBPARAMIO_OUTPUT)==DBPARAMIO_OUTPUT;
}//ParamIO__HasOutput

////////////////////////////////////////////////////////////////////////////////
//class TParamBindingData

inline TParamBindingData::TParamBindingData()
{
 memset(this,0,sizeof(*this));
}

////////////////////////////////////////////////////////////////////////////////
//class TDBID

inline bool TDBID::HasPointedGUID(const DBID& dbid)
{
 return dbid.eKind==DBKIND_PGUID_NAME ||
        dbid.eKind==DBKIND_PGUID_PROPID;
}//HasPointedGUID

//------------------------------------------------------------------------
inline bool TDBID::HasGUID(const DBID& dbid)
{
 return dbid.eKind==DBKIND_GUID_NAME    ||
        dbid.eKind==DBKIND_GUID_PROPID  ||
        dbid.eKind==DBKIND_PGUID_NAME   ||
        dbid.eKind==DBKIND_PGUID_PROPID ||
        dbid.eKind==DBKIND_GUID;
}//HasGUID

//------------------------------------------------------------------------
inline bool TDBID::IsGUID(const DBID& dbid,REFGUID guid)
{
 return HasGUID(dbid) && GetGUID(dbid)==guid;
}//IsGUID

//------------------------------------------------------------------------
inline bool TDBID::HasName(const DBID& dbid)
{
 return dbid.eKind==DBKIND_GUID_NAME ||
        dbid.eKind==DBKIND_NAME      ||
        dbid.eKind==DBKIND_PGUID_NAME;
}//HasName

//------------------------------------------------------------------------
inline size_t TDBID::GetNameLen(const DBID& dbid)
{
 return (HasName(dbid) && dbid.uName.pwszName!=NULL)
         ?wcslen(dbid.uName.pwszName)
         :0;
}//GetNameLen

//------------------------------------------------------------------------
inline bool TDBID::HasID(const DBID& dbid)
{
 return dbid.eKind==DBKIND_GUID_PROPID   ||
        dbid.eKind==DBKIND_PGUID_PROPID  ||
        dbid.eKind==DBKIND_PROPID;
}//HasID

//------------------------------------------------------------------------
inline ULONG TDBID::GetID(const DBID& dbid)
{
 return HasID(dbid)?dbid.uName.ulPropid:0;
}//GetID

//------------------------------------------------------------------------
inline bool TDBID::IsID(const DBID& dbid,ULONG id)
{
 return HasID(dbid) && GetID(dbid)==id;
}//IsID

////////////////////////////////////////////////////////////////////////////////
//class TDBPropID

inline TDBPropID::TDBPropID()
 :id(0)
 ,guid(CLSID_NULL)
{;}

//------------------------------------------------------------------------
inline TDBPropID::TDBPropID(REFGUID _guid,DBPROPID _id)
 :id(_id)
 ,guid(_guid)
{;}

//------------------------------------------------------------------------
inline bool TDBPropID::operator == (const self_type& x)const
{
 return ole_lib::GuidEqual(this->guid,x.guid) && this->id==x.id;
}//operator ==

//------------------------------------------------------------------------
inline bool TDBPropID::operator != (const self_type& x)const
{
 return !(*this==x);
}//operator !=

//------------------------------------------------------------------------
inline bool TDBPropID::operator < (const self_type& x)const
{
 const int comp_guid=ole_lib::GuidCompare_3Way(this->guid,x.guid);

 return comp_guid<0 || (comp_guid==0 && this->id<x.id);
}//operator <

////////////////////////////////////////////////////////////////////////////////
//class TBaseDBPROP

inline TBaseDBPROP::TBaseDBPROP()
{
 memset(this,0,sizeof(*this));

 assert(this->vValue.vt==VT_EMPTY);
}//TBaseDBPROP

//------------------------------------------------------------------------
inline TBaseDBPROP::~TBaseDBPROP()
{
 _VERIFY_EQ(ole_lib::Variant_Clear(&this->vValue),S_OK);
}//~TBaseDBPROP

////////////////////////////////////////////////////////////////////////////////
//class TDBPROP

inline TDBPROP::TDBPROP()
{;}

////////////////////////////////////////////////////////////////////////////////
//class TDBID - inline implementations

inline TDBID::TDBID()
{;}

//------------------------------------------------------------------------
inline TDBID::TDBID(const self_type& dbid)
{
 this->InitFromDBID(dbid);
}

//------------------------------------------------------------------------
inline TDBID::TDBID(const DBID& dbid)
{
 this->InitFromDBID(dbid);
}

//------------------------------------------------------------------------
inline TDBID::~TDBID()
{
 this->flush();
}//~TDBID

//------------------------------------------------------------------------
inline void TDBID::ConvertToDirectGUID()
{
 self_type::ConvertToDirectGUID(*this);
}//ConvertToDirectGUID

//------------------------------------------------------------------------
inline TDBID& TDBID::operator = (astr_box_type const Name)
{
 return this->SetName(Name);
}//operator =

//------------------------------------------------------------------------
inline TDBID& TDBID::operator = (wstr_box_type const Name)
{
 return this->SetName(Name);
}//operator =

//------------------------------------------------------------------------
inline void TDBID::FillDBID(DBID*       const pDBID,
                            OLECHAR*&         BufferPos,
                            OLECHAR*    const pBufferEnd)const
{
 //[BCB5 BUG] BCB5 can't compile this assert without explicit static_cast
 assert(static_cast<const DBID*>(this)!=pDBID);

 return self_type::FillDBID(*this,pDBID,BufferPos,pBufferEnd);
}//FillDBID

////////////////////////////////////////////////////////////////////////////////
//class TDBPropertySetBuffer

inline const DBPROPSET* TDBPropertySetBuffer::GetSetBuffer()const
{
 return m_pPropSets;
}//GetSetBuffer

//------------------------------------------------------------------------
inline size_t TDBPropertySetBuffer::GetSetCount()const
{
 return m_cPropSets;
}//GetSetCount

////////////////////////////////////////////////////////////////////////////////
//class TDBPropertyInfoSetBuffer

inline const DBPROPINFOSET* TDBPropertyInfoSetBuffer::GetSetBuffer()const
{
 return m_pPropInfoSets;
}//GetSetBuffer

//------------------------------------------------------------------------
inline size_t TDBPropertyInfoSetBuffer::GetSetCount()const
{
 return m_cPropInfoSets;
}//GetSetCount

////////////////////////////////////////////////////////////////////////////////
//class TDBDataBufferUtils

template<class TBindingIterator>
void TDBDataBufferUtils::Client_FreeData(TBindingIterator       FirstBinding,
                                         TBindingIterator const LastBinding,
                                         void*            const pData,
                                         DWORD            const Flags)
{
 for(;FirstBinding!=LastBinding;++FirstBinding)
 {
  self_type::Client_FreeData(*FirstBinding,pData,Flags);
 }//for FirstBinding
}//Client_FreeData - multiple elements

//------------------------------------------------------------------------
template<class TBindingIterator>
void TDBDataBufferUtils::Provider_FreeClientData(TBindingIterator       FirstBinding,
                                                 TBindingIterator const LastBinding,
                                                 void*            const pData)
{
 for(;FirstBinding!=LastBinding;++FirstBinding)
 {
  self_type::Provider_FreeClientData(*FirstBinding,pData);
 }//for FirstBinding
}//Provider_FreeClientData - multiple elements

//------------------------------------------------------------------------
template<class TBindingIterator>
void TDBDataBufferUtils::InitDataEx(TBindingIterator       FirstBinding,
                                    TBindingIterator const LastBinding,
                                    void*            const pData,
                                    DBSTATUS         const Status,
                                    DWORD            const Flags)
{
 for(;FirstBinding!=LastBinding;++FirstBinding)
 {
  self_type::InitDataEx(*FirstBinding,pData,Status,Flags);
 }//for FirstBinding
}//InitDataEx - multiple elements

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
