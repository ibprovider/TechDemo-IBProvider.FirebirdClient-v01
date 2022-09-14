////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <win32lib/win32_resource_versioninfo.h>
#include <structure/t_char_traits2.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////

static const size_t c_ver_info_align=4;

//------------------------------------------------------------------------
static size_t ver_info__get_distance(const void* const beg,const void* const end)
{
 assert(beg<=end);

 return reinterpret_cast<const char*>(end)-reinterpret_cast<const char*>(beg);
}//ver_info__get_distance

//------------------------------------------------------------------------
static const void* ver_info_align_ptr(const void* const ptr,const void* const end)
{
 assert(ptr<=end);

 assert_s(c_ver_info_align!=0);
 assert_s(sizeof(UINT_PTR)==sizeof(void*));

 UINT_PTR const x_ptr=reinterpret_cast<UINT_PTR>(ptr);
 UINT_PTR const x_end=reinterpret_cast<UINT_PTR>(end);

 const UINT_PTR x_mod=(x_ptr%c_ver_info_align);

 assert(x_mod<c_ver_info_align);

 if(x_mod==0)
  return ptr;

 assert(x_mod>0);

 const UINT_PTR x_add=(c_ver_info_align-x_mod);

 assert(0<x_add);
 assert(x_add<c_ver_info_align);
 assert((x_add+x_mod)==c_ver_info_align);

 if((x_end-x_ptr)<x_add)
  return end; //we prevent an overflow of buffer

 UINT_PTR const x_res=x_ptr+x_add;

 assert(x_ptr<x_res);
 assert(x_res<=x_end);

 return reinterpret_cast<const void*>(x_res);
}//ver_info_align_ptr

//------------------------------------------------------------------------
#ifndef NDEBUG

//
// The complete verification of the ver_info_align_ptr work.
//
static void DEBUG__check__ver_info_align_ptr()
{
 union
 {
  __int64 value;
  char    bytes[sizeof(2*c_ver_info_align)];
 } data;

 assert(ver_info_align_ptr(data.bytes,_END_(data.bytes))==data.bytes);

 assert_s(c_ver_info_align>0);

 for(const char* p=data.bytes+1;p!=data.bytes+c_ver_info_align;++p)
 {
  assert(ver_info_align_ptr(p,_END_(data.bytes))==data.bytes+c_ver_info_align);
 }//for p

 for(const char* p=data.bytes+1;p!=data.bytes+c_ver_info_align;++p)
 {
  assert(ver_info_align_ptr(p,data.bytes+c_ver_info_align)==data.bytes+c_ver_info_align);
 }//for p

 for(size_t s=c_ver_info_align;s>=2;--s)
 {
  for(const char* p=data.bytes+1;p!=data.bytes+s;++p)
  {
   assert(ver_info_align_ptr(p,data.bytes+s)==data.bytes+s);
  }//for p
 }//for s
}//DEBUG__check__ver_info_align_ptr

STARTUP_CODE__DEBUG(DEBUG__check__ver_info_align_ptr)

#endif //NDEBUG

//------------------------------------------------------------------------
static structure::t_const_wstr_box ver_info_entry__get_key
                             (t_ver_info_src_id                    const srcID,
                              const t_ver_info_element::tag_entry* const pEntry)
{
 assert(pEntry);

 const wchar_t* pv=pEntry->szKey;

 const void* const pvEnd=pEntry->end();

 for(;pv<pvEnd;++pv)
 {
  if((*pv)==0)
   return structure::t_const_wstr_box(pEntry->szKey,pv-pEntry->szKey);
 }

 t_ver_info_error(srcID,ver_info_mce__cant_detect_key_of_ver_info_block_0).raise();

//#if(COMP_BUILD_UNUSED_CODE)
 return nullptr;
//#endif
}//ver_info_entry__get_key

//------------------------------------------------------------------------
static const void* ver_info_entry__get_value
                             (t_ver_info_src_id                    const srcID,
                              const t_ver_info_element::tag_entry* const pEntry,
                              const void*                          const pData,
                              size_t                               const cbValueElement)
{
 assert(pEntry);
 assert(pEntry<pData);
 assert(pData<=pEntry->end());
 assert(cbValueElement!=0);

 const void* const eEntry=pEntry->end();

 const void* const pValue=ver_info_align_ptr(pData,eEntry);

 assert(pValue<=eEntry);

 const size_t cbValueLength=cbValueElement*pEntry->wValueLength;

 if(ver_info__get_distance(pValue,eEntry)<cbValueLength)
 {
  t_ver_info_error exc(srcID,ver_info_mce__bad_value_size_4);

  exc<<ver_info_entry__get_key(srcID,pEntry)
     <<pEntry->wLength
     <<ver_info__get_distance(pEntry,pValue)
     <<cbValueLength;

  exc.raise();
 }//if

 return pValue;
}//ver_info_entry__get_value

////////////////////////////////////////////////////////////////////////////////
//struct t_ver_info_std_entry

struct t_ver_info_std_entry
{
 public:
  typedef t_ver_info_element_ptr (creator_ptr)(const t_ver_info_element::tag_entry&);

 public:
  const wchar_t*  szKey;
  creator_ptr*    creator;

  bool operator == (const structure::t_const_wstr_box& Key)const
   {
    return structure::equal_to_string(Key,this->szKey);
   }//operator ==

  bool operator != (const structure::t_const_wstr_box& Key)const
   {
    return !((*this)==Key);
   }//operator !=
};//struct t_ver_info_std_entry

////////////////////////////////////////////////////////////////////////////////
//elements factories

template<class TVerInfoElement>
t_ver_info_element_ptr create_ver_info_element__GENERIC(const t_ver_info_element::tag_entry& entry)
{
 return TVerInfoElement::create(entry);
}//create_ver_info_element__GENERIC

////////////////////////////////////////////////////////////////////////////////

static const t_ver_info_std_entry g_std_entries[]=
{
 {L"VS_VERSION_INFO",
  create_ver_info_element__GENERIC<t_ver_info_element__VS_VERSION_INFO>},

 {L"StringFileInfo",
  create_ver_info_element__GENERIC<t_ver_info_element__StringFileInfo>},

 {L"VarFileInfo",
  create_ver_info_element__GENERIC<t_ver_info_element__VarFileInfo>},
};//g_std_entries

////////////////////////////////////////////////////////////////////////////////

const t_ver_info_element::tag_entry*
 load_ver_info_element__get_entry(t_ver_info_src_id srcID,
                                  const void*       pvBlock,
                                  size_t            cbBlock)
{
 assert(pvBlock);

 CHECK_READ_PTR(pvBlock,cbBlock);

 //--------------------------
 if(cbBlock<sizeof(t_ver_info_element::tag_entry))
 {
  t_ver_info_error exc(srcID,
                       ver_info_mce__bad_block_size_2);

  exc<<cbBlock
     <<sizeof(t_ver_info_element::tag_entry);

  exc.raise();
 }//if

 //--------------------------
 const t_ver_info_element::tag_entry* const
  pEntry
   =reinterpret_cast<const t_ver_info_element::tag_entry*>(pvBlock);

 if(cbBlock<size_t(pEntry->wLength))
 {
  t_ver_info_error exc(srcID,
                       ver_info_mce__large_element_length_2);

  exc<<pEntry->wLength
     <<cbBlock;

  exc.raise();
 }//if

 //---------------------------
 if(pEntry->wLength<sizeof(*pEntry))
 {
  t_ver_info_error exc(srcID,
                       ver_info_mce__small_element_length_2);

  exc<<pEntry->wLength
     <<sizeof(*pEntry);

  exc.raise();
 }//if

 //---------------------------
 return pEntry;
}//load_ver_info_element__get_entry

//------------------------------------------------------------------------
using t_load_ver_info_element2_result
 =std::pair<t_ver_info_element_ptr,const void*>;

//------------------------------------------------------------------------
static t_load_ver_info_element2_result load_ver_info_element2
                                           (const void* const pvBlock,
                                            size_t      const cbBlock)
{
 const t_ver_info_element::tag_entry* const
  pEntry
   =load_ver_info_element__get_entry
     (ver_info_src__load_ver_info_element,
      pvBlock,
      cbBlock);

 assert(pEntry!=nullptr);

 structure::t_const_wstr_box const
  keyName
   =ver_info_entry__get_key
     (ver_info_src__load_ver_info_element,
      pEntry);

 //--------------------------
 const t_ver_info_std_entry* const
  pEntryInfo
   =std::find(g_std_entries,_END_(g_std_entries),keyName);

 if(pEntryInfo==_END_(g_std_entries))
 {
  t_ver_info_error exc(ver_info_src__load_ver_info_element,
                       ver_info_mce__unk_element_key_1);

  exc<<keyName;

  exc.raise();
 }//if

 //--------------------------
 assert(pEntryInfo->creator!=NULL);

 t_ver_info_element_ptr
  spElement
   (pEntryInfo->creator(*pEntry));

 //--------------------------
 assert(spElement);

 return t_load_ver_info_element2_result(__STL_MOVE_VALUE(spElement),pEntry->end());
}//load_ver_info_element2

//------------------------------------------------------------------------
t_ver_info_element_ptr load_ver_info_element(const void* const pvBlock,
                                             size_t      const cbBlock)
{
 return load_ver_info_element2(pvBlock,cbBlock).first;
}//load_ver_info_element

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_error_traits

const t_ver_info_error_traits::src_entry_type
 t_ver_info_error_traits::sm_sources[]=
{
 {ver_info_src__load_ver_info_element,
  L"load_ver_info_element"},

 {ver_info_src__ver_info_element__VS_VERSION_INFO,
  L"t_ver_info_element__VS_VERSION_INFO"},

 {ver_info_src__ver_info_element__StringFileInfo,
  L"t_ver_info_element__StringFileInfo"},

 {ver_info_src__ver_info_element__StringTable,
  L"t_ver_info_element__StringTable"},

 {ver_info_src__ver_info_element__String,
  L"t_ver_info_element__String"},

 {ver_info_src__ver_info_element__VarFileInfo,
  L"t_ver_info_element__VarFileInfo"},

 {ver_info_src__ver_info_element__Var,
  L"t_ver_info_element__Var"},
};//sm_sources

//------------------------------------------------------------------------
const t_ver_info_error_traits::msg_entry_type
 t_ver_info_error_traits::sm_msgs[]=
{
 {ver_info_mce__bad_block_size_2,
  L"Bad version info block size [%1]. Min element size [%2]."},

 {ver_info_mce__cant_detect_key_of_ver_info_block_0,
  L"Can't detect version info element key"},

 {ver_info_mce__large_element_length_2,
  L"Large length of version info element: %1. Max length %2."},

 {ver_info_mce__small_element_length_2,
  L"Small length of version info element: %1. Min length %2."},

 {ver_info_mce__unk_element_key_1,
  L"Unknown version info element key [%1]."},

 {ver_info_mce__bad_size_of_structured_value_3,
  L"Bad size of structured value [%1]. Get size %2. Min size %3."},

 {ver_info_mce__VS_FIXEDFILEINFO_is_not_defined_0,
  L"VS_FIXEDFILEINFO is not defined."},

 {ver_info_mce__bad_value_size_4,
  L"Bad value size in key [%1]Entry size %2. Value offset %3. Value size %4."},

 //{ver_info_mce__bad_value_offset_3,
 // L"Bad value offset in key [%1]. Entry size %2. Value offset %3."},

 {ver_info_mce__cant_process_string_value_1,
  L"Cant process string value of key [%1]."},

 {ver_info_mce__bad_var_array_length_2,
  L"Bad length of var [%1] array length %2."},

 {ver_info_mce__unknown_type_id_2,
  L"Unknown type [%2] of version info element [%1]."},

 {ver_info_mce__bad_query_path_1,
  L"Incorrect query path [%1]."},

 {ver_info_mce__query_path_not_exists_1,
  L"Query path [%1] is not exists."}
};//sm_msgs

//------------------------------------------------------------------------
bool t_ver_info_error_traits::get_source_name(lcid_type,
                                              source_id_type code,
                                              string_type&   name)
{
 const src_entry_type* const entry(std::find(sm_sources,_END_(sm_sources),code));

 if(entry==_END_(sm_sources))
  return false;

 name=entry->msg;

 return true;
}//get_source_name

//------------------------------------------------------------------------
bool t_ver_info_error_traits::get_msg(lcid_type,
                                      msg_id_type  code,
                                      string_type& msg)
{
 const msg_entry_type* const entry(std::find(sm_msgs,_END_(sm_msgs),code));

 if(entry==_END_(sm_msgs))
  return false;

 msg=entry->msg;

 return true;
}//get_msg

//------------------------------------------------------------------------
void t_ver_info_error_traits::get_unknown_msg(lcid_type,string_type& msg)
{
 msg=L"[win_ver_info_lib] Unknown error message id: %1.";
}//get_unknown_msg

//------------------------------------------------------------------------
const char* t_ver_info_error_traits::get_critical_error_msg(lcid_type)
{
 return "[win_ver_info_lib] Critical error.";
}//get_critical_error_msg

//------------------------------------------------------------------------
bool t_ver_info_error_traits::get_help_file(lcid_type,
                                            help_file_id_type,
                                            string_type&)
{
 return false;
}//get_help_file

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element

t_ver_info_element::t_ver_info_element(t_ver_info_src_id  src_id)
 :m_src_id(src_id)
{
}

//------------------------------------------------------------------------
t_ver_info_element::~t_ver_info_element()
{;}

//------------------------------------------------------------------------
t_ver_info_src_id t_ver_info_element::src_id()const
{
 return m_src_id;
}//src_id

//------------------------------------------------------------------------
const std::wstring& t_ver_info_element::key()const
{
 return m_key;
}//key

//------------------------------------------------------------------------
const void* t_ver_info_element::internal__load(const tag_entry& entry)
{
 const structure::t_const_wstr_box
  keyName
   (ver_info_entry__get_key(this->src_id(),&entry));

 m_key=keyName.make_str();

 return keyName.ptr+keyName.len+1;
}//internal__load

//------------------------------------------------------------------------
bool t_ver_info_element::eq_key(const wchar_t* const pwszKey,
                                size_t         const cchKey)
{
 /// Default comparison is case sensitive.

 CHECK_READ_TYPED_PTR(pwszKey,cchKey);

 return structure::equal
         (pwszKey,
          pwszKey+cchKey,
          m_key.cbegin(),
          m_key.cend());
}//eq_key

//query services ---------------------------------------------------------
t_ver_info_element::self_ptr
 t_ver_info_element::query(str_arg_type const path,
                           bool         const must_exists)const
{
 typedef str_arg_type::char_type                  char_type;
 typedef structure::t_char_traits2<char_type>     ct2;

 const char_type* cur=path.str();

 self_ptr spElement;

 while((*cur)!=0)
 {
  const char_type* const beg=cur;

  for(;(*cur)!=0 && (*cur)!=ct2::ch_back_slash();++cur);

  if(beg==cur && (*cur)!=0)
  {
   if(!spElement)
    spElement=const_cast<self_type*>(this);

   ++cur;

   continue;
  }//if

  if(beg!=cur)
  {
   if(!spElement)
    break; //goto to error handler: incorrect query path

   //--------
   size_type  i(0);
   size_type _c(spElement->child_count());

   for(;i!=_c;++i)
   {
    if(spElement->child(i) && spElement->child(i)->eq_key(beg,cur-beg))
     break;
   }//for

   if(i==_c)
   {
    if(must_exists)
    {
     //PATH not found
     t_ver_info_error exc(this->src_id(),
                          ver_info_mce__query_path_not_exists_1);

     exc<<path.str();

     exc.raise();
    }

    return self_ptr();
   }//if

   _VERIFY(spElement=spElement->child(i));

   if((*cur)!=0)
    ++cur; //skeep separate slash
  }//if beg!=cur
 }//while

 if(!spElement)
 {
  //DONE 5: error - incorrect query string
  t_ver_info_error exc(this->src_id(),
                       ver_info_mce__bad_query_path_1);

  exc<<path.str();

  exc.raise();
 }//if

 return spElement;
}//query

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__VS_VERSION_INFO

t_ver_info_element__VS_VERSION_INFO::t_ver_info_element__VS_VERSION_INFO()
 :inherited(ver_info_src__ver_info_element__VS_VERSION_INFO)
{
}//t_ver_info_element__VS_VERSION_INFO

//------------------------------------------------------------------------
t_ver_info_element__VS_VERSION_INFO::~t_ver_info_element__VS_VERSION_INFO()
{;}

//------------------------------------------------------------------------
t_ver_info_element__VS_VERSION_INFO::self_ptr t_ver_info_element__VS_VERSION_INFO::create(const tag_entry& entry)
{
 self_ptr x(structure::not_null_ptr(new self_type()));

 x->internal__load(entry);

 return x;
}//create

//selectors --------------------------------------------------------------
const VS_FIXEDFILEINFO* t_ver_info_element__VS_VERSION_INFO::fixed_info(bool must_exists)const
{
 if(!m_ffi.null())
  return &m_ffi.value();

 if(must_exists)
 {
  t_ver_info_error(ver_info_src__ver_info_element__VS_VERSION_INFO,
                   ver_info_mce__VS_FIXEDFILEINFO_is_not_defined_0).raise();
 }//if

 return nullptr;
}//fixed_info

//interface --------------------------------------------------------------
const void* t_ver_info_element__VS_VERSION_INFO::internal__load(const tag_entry& entry)
{
 //! struct VS_VERSIONINFO:
 //! - WORD wLength;
 //! - WORD wValueLength; //byte
 //! - WORD wType;
 //! - WCHAR szKey[];
 //! - WORD Padding1[];
 //! - VS_FIXEDFILEINFO Value;
 //! - WORD Padding2[];
 //! - WORD Children[];

 assert(m_ffi.null());
 assert(m_childs.empty());

 //-----------
 const void* pOurData=inherited::internal__load(entry);

 if(entry.wValueLength==0)
 {
  m_ffi.reset();
 }
 else
 if(sizeof(VS_FIXEDFILEINFO)<=entry.wValueLength)
 {
  pOurData=ver_info_entry__get_value(this->src_id(),&entry,pOurData,1);

  m_ffi=*reinterpret_cast<const VS_FIXEDFILEINFO*>(pOurData);

  pOurData=reinterpret_cast<const char*>(pOurData)+entry.wValueLength;
 }
 else
 {
  t_ver_info_error exc(this->src_id(),
                       ver_info_mce__bad_size_of_structured_value_3);

  exc<<L"VS_FIXEDFILEINFO"
     <<entry.wValueLength
     <<sizeof(VS_FIXEDFILEINFO);

  exc.raise();
 }//if

 const void* const eChildren=entry.end();

 for(;;)
 {
  const void* const pChildren=ver_info_align_ptr(pOurData,eChildren);

  if(pChildren==eChildren)
   break;

  assert(pChildren<eChildren);

  const size_t cbTail=ver_info__get_distance(pChildren,eChildren);

  t_load_ver_info_element2_result
   childData
    (load_ver_info_element2(pChildren,cbTail));

  assert(childData.first);

  m_childs.push_back(__STL_MOVE_VALUE(childData.first));

  assert(pChildren<childData.second);
  assert(childData.second<=eChildren);

  pOurData=childData.second;
 }//for[ever]

 return eChildren;
}//internal__load

//------------------------------------------------------------------------
t_ver_info_element__VS_VERSION_INFO::size_type
 t_ver_info_element__VS_VERSION_INFO::child_count()const
{
 return m_childs.size();
}//child_count

//------------------------------------------------------------------------
t_ver_info_element* t_ver_info_element__VS_VERSION_INFO::child(size_type const i)const
{
 assert(i<m_childs.size());

 return m_childs[i];
}//child

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__String

t_ver_info_element__String::t_ver_info_element__String()
 :inherited(ver_info_src__ver_info_element__String)
{;}

//------------------------------------------------------------------------
t_ver_info_element__String::~t_ver_info_element__String()
{;}

//------------------------------------------------------------------------
t_ver_info_element__String::create_result_type
 t_ver_info_element__String::create(const void* const pvBlock,
                                    size_t      const cbBlock)
{
 const tag_entry* const
  pEntry
   =load_ver_info_element__get_entry
     (ver_info_src__ver_info_element__String,
      pvBlock,
      cbBlock);

 const self_ptr spString(structure::not_null_ptr(new self_type()));

 const void* const eData=spString->internal__load(*pEntry);

 assert(pvBlock<eData);
 assert(eData<=reinterpret_cast<const char*>(pvBlock)+cbBlock);

 return create_result_type(__STL_MOVE_VALUE(spString),eData);
}//create

//------------------------------------------------------------------------
const std::wstring& t_ver_info_element__String::value()const
{
 return m_value;
}//value

//interface --------------------------------------------------------------
const void* t_ver_info_element__String::internal__load(const tag_entry& entry)
{
 //! struct String:
 //! - WORD wLength;
 //! - WORD wValueLength; //length in words
 //! - WORD wType;
 //! - WCHAR szKey[];
 //! - WORD Padding[];
 //! - WORD Value[];

 assert(m_value.empty());

 //--------
 const void* const pOurData=inherited::internal__load(entry);

 //--------
 if(entry.wType==1)
 {
  if(entry.wValueLength!=0)
  {
   const wchar_t* const pwszValue=
    reinterpret_cast<const wchar_t*>(ver_info_entry__get_value(this->src_id(),&entry,pOurData,sizeof(WORD)));

   const void* const eEntry=
    reinterpret_cast<const char*>(pwszValue)+(entry.wValueLength*sizeof(WORD));

   const wchar_t* ewszValue=pwszValue;

   for(;ewszValue<eEntry && (*ewszValue)!=0;++ewszValue);

   if(!(ewszValue<eEntry))
   {
    t_ver_info_error exc(this->src_id(),
                         ver_info_mce__cant_process_string_value_1);

    exc<<this->key();

    exc.raise();
   }

   m_value.assign(pwszValue,ewszValue);
  }//if entry.wValueLength!=0
 }
 else
 {
  //Process unknown Type ID

  t_ver_info_error exc(this->src_id(),
                       ver_info_mce__unknown_type_id_2);

  exc<<this->key()<<entry.wType;

  exc.raise();
 }//else

 return entry.end();
}//load

//------------------------------------------------------------------------
t_ver_info_element__String::size_type t_ver_info_element__String::child_count()const
{
 return 0;
}//child_count

//------------------------------------------------------------------------
t_ver_info_element* t_ver_info_element__String::child(size_type /*i*/)const
{
 assert(false);

 return nullptr;
}//child

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__StringTable

t_ver_info_element__StringTable::t_ver_info_element__StringTable()
 :inherited(ver_info_src__ver_info_element__StringTable)
{;}

//------------------------------------------------------------------------
t_ver_info_element__StringTable::~t_ver_info_element__StringTable()
{;}

//------------------------------------------------------------------------
t_ver_info_element__StringTable::create_result_type
 t_ver_info_element__StringTable::create(const void* const pvBlock,
                                         size_t      const cbBlock)
{
 const tag_entry*
  const pEntry
   =load_ver_info_element__get_entry
     (ver_info_src__ver_info_element__StringTable,
      pvBlock,
      cbBlock);

 assert(pEntry);

 self_ptr spStringTable(structure::not_null_ptr(new self_type()));

 const void* const eData=spStringTable->internal__load(*pEntry);

 assert(pvBlock<eData);
 assert(eData<=reinterpret_cast<const char*>(pvBlock)+cbBlock);

 return create_result_type(__STL_MOVE_VALUE(spStringTable),eData);
}//create

//interface --------------------------------------------------------------
const void* t_ver_info_element__StringTable::internal__load(const tag_entry& entry)
{
 //! struct StringTable:
 //! - WORD wLength;
 //! - WORD wValueLength;
 //! - WORD wType;
 //! - WCHAR szKey[];
 //! - WORD Padding[];
 //! - String Children[];

 //-----------
 assert(m_childs.empty());

 //------------
 const void* pOurData=inherited::internal__load(entry);

 //------------
 const void* const eChildren=entry.end();

 for(;;)
 {
  const void* const pChildren=ver_info_align_ptr(pOurData,eChildren);

  if(pChildren==eChildren)
   break;

  assert(pChildren<eChildren);

  const size_t cbTail
   =ver_info__get_distance(pChildren,eChildren);

  auto childData
   (t_ver_info_element__String::create(pChildren,cbTail));

  assert(childData.first);

  m_childs.push_back(__STL_MOVE_VALUE(childData.first));

  assert(pChildren<childData.second);;
  assert(childData.second<=eChildren);

  pOurData=childData.second;
 }//for[ever]

 return eChildren;
}//internal__load

//------------------------------------------------------------------------
t_ver_info_element__StringTable::size_type
 t_ver_info_element__StringTable::child_count()const
{
 return m_childs.size();
}//child_count

//------------------------------------------------------------------------
t_ver_info_element__String*
 t_ver_info_element__StringTable::child(size_type const i)const
{
 assert(i<m_childs.size());

 return m_childs[i];
}//child_count

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__StringFileInfo

t_ver_info_element__StringFileInfo::t_ver_info_element__StringFileInfo()
 :inherited(ver_info_src__ver_info_element__StringFileInfo)
{;}

//------------------------------------------------------------------------
t_ver_info_element__StringFileInfo::~t_ver_info_element__StringFileInfo()
{;}

//------------------------------------------------------------------------
t_ver_info_element__StringFileInfo::self_ptr t_ver_info_element__StringFileInfo::create(const tag_entry& entry)
{
 self_ptr x(structure::not_null_ptr(new self_type()));

 x->internal__load(entry);

 return x;
}//create

//interface --------------------------------------------------------------
const void* t_ver_info_element__StringFileInfo::internal__load(const tag_entry& entry)
{
 //! struct StringFileInfo:
 //! - WORD wLength;
 //! - WORD wValueLength;
 //! - WORD wType;
 //! - WCHAR szKey[];
 //! - WORD Padding[];
 //! - StringTable Children[];

 //-----------
 assert(m_childs.empty());

 //-----------
 const void* pOurData=inherited::internal__load(entry);

 //-----------
 const void* const eChildren=entry.end();

 for(;;)
 {
  const void* const pChildren=ver_info_align_ptr(pOurData,eChildren);

  if(pChildren==eChildren)
   break;

  assert(pChildren<eChildren);

  const size_t cbTail=ver_info__get_distance(pChildren,eChildren);

  auto childData
   (t_ver_info_element__StringTable::create(pChildren,cbTail));

  assert(childData.first);

  m_childs.push_back(__STL_MOVE_VALUE(childData.first));

  assert(pChildren<childData.second);;
  assert(childData.second<=eChildren);

  pOurData=childData.second;
 }//for[ever]

 return eChildren;
}//internal__load

//------------------------------------------------------------------------
t_ver_info_element__StringFileInfo::size_type
 t_ver_info_element__StringFileInfo::child_count()const
{
 return m_childs.size();
}//child_count

//------------------------------------------------------------------------
t_ver_info_element__StringTable*
 t_ver_info_element__StringFileInfo::child(size_type const i)const
{
 assert(i<m_childs.size());

 return m_childs[i];
}//child

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__Var

t_ver_info_element__Var::t_ver_info_element__Var()
 :inherited(ver_info_src__ver_info_element__Var)
{;}

//------------------------------------------------------------------------
t_ver_info_element__Var::~t_ver_info_element__Var()
{;}

//------------------------------------------------------------------------
t_ver_info_element__Var::create_result_type
 t_ver_info_element__Var::create(const void* const pvBlock,
                                 size_t      const cbBlock)
{
 const tag_entry* const
  pEntry
   =load_ver_info_element__get_entry
     (ver_info_src__ver_info_element__Var,
      pvBlock,
      cbBlock);

 assert(pEntry);

 //---------------
 self_ptr spVar(structure::not_null_ptr(new self_type()));

 const void* const eData=spVar->internal__load(*pEntry);

 assert(pvBlock<eData);
 assert(eData<=reinterpret_cast<const char*>(pvBlock)+cbBlock);

 return create_result_type(__STL_MOVE_VALUE(spVar),eData);
}//create

//selectors --------------------------------------------------------------
t_ver_info_element__Var::size_type t_ver_info_element__Var::id_count()const
{
 return m_ids.size();
}//id_count

//------------------------------------------------------------------------
DWORD t_ver_info_element__Var::id(size_type const i)const
{
 assert(i<m_ids.size());

 return m_ids[i];
}//id

//------------------------------------------------------------------------
std::wstring t_ver_info_element__Var::id_as_str(size_type const i)const
{
 ids_type::value_type x(m_ids[i]);

 const size_t pass_count=(sizeof(x)*CHAR_BIT)/4;

 std::wstring res;

 res.resize(pass_count);

 for(size_t n=0;n!=pass_count;++n,x=x>>4)
 {
  typedef unsigned char byte_type;

  const byte_type b=byte_type(x&0x0F);

  res[pass_count-n-1]=wchar_t((b<10)?(L'0'+b):(L'A'+(b-10)));
 }//for

 return res;
}//id_as_str

//interface --------------------------------------------------------------
const void* t_ver_info_element__Var::internal__load(const tag_entry& entry)
{
 //! struct Var:
 //! - WORD wLength;
 //! - WORD wValueLength;
 //! - WORD wType;
 //! - WCHAR szKey[];
 //! - WORD Padding[];
 //! - DWORD Value[];

 //---------
 assert(m_ids.empty());

 //---------
 const void* pOurData=inherited::internal__load(entry);

 //-----------
 if(entry.wType==0)
 {
  pOurData
   =ver_info_entry__get_value
     (this->src_id(),
      &entry,
      pOurData,
      1);

  if((entry.wValueLength%sizeof(DWORD))!=0)
  {
   t_ver_info_error exc(this->src_id(),
                        ver_info_mce__bad_var_array_length_2);

   exc<<this->key()<<entry.wValueLength;

   exc.raise();
  }//if

  //-----------
  const void*       pID=pOurData;
  const void* const eID=reinterpret_cast<const char*>(pID)+entry.wValueLength;

  assert(pID<=eID);
  assert(eID<=entry.end());

  //-----------
  while(pID<eID)
  {
   m_ids.push_back(_MAKELONG(*(reinterpret_cast<const WORD*>(pID)+1),
                             *(reinterpret_cast<const WORD*>(pID))));

   pID=reinterpret_cast<const char*>(pID)+sizeof(DWORD);
  }//while
 }
 else
 {
  //Process unknown Type ID

  t_ver_info_error exc(this->src_id(),
                       ver_info_mce__unknown_type_id_2);

  exc<<this->key()<<entry.wType;

  exc.raise();
 }//else

 return entry.end();
}//internal__load

//------------------------------------------------------------------------
t_ver_info_element__Var::size_type t_ver_info_element__Var::child_count()const
{
 return 0;
}//child_count

//------------------------------------------------------------------------
t_ver_info_element* t_ver_info_element__Var::child(size_type const /*i*/)const
{
 assert(false);

 return 0;
}//child

////////////////////////////////////////////////////////////////////////////////
//class t_ver_info_element__VarFileInfo

t_ver_info_element__VarFileInfo::t_ver_info_element__VarFileInfo()
 :inherited(ver_info_src__ver_info_element__VarFileInfo)
{;}

//------------------------------------------------------------------------
t_ver_info_element__VarFileInfo::~t_ver_info_element__VarFileInfo()
{;}

//------------------------------------------------------------------------
t_ver_info_element__VarFileInfo::self_ptr t_ver_info_element__VarFileInfo::create(const tag_entry& entry)
{
 self_ptr x(structure::not_null_ptr(new self_type()));

 x->internal__load(entry);

 return x;
}//create

//interface --------------------------------------------------------------
const void* t_ver_info_element__VarFileInfo::internal__load(const tag_entry& entry)
{
 assert(m_childs.empty());

 //-----------
 const void* pOurData=inherited::internal__load(entry);

 //-----------
 const void* const eChildren=entry.end();

 for(;;)
 {
  const void* const pChildren=ver_info_align_ptr(pOurData,eChildren);

  if(pChildren==eChildren)
   break;

  assert(pChildren<eChildren);

  const size_t cbTail
   =ver_info__get_distance(pChildren,eChildren);

  auto childData
   (t_ver_info_element__Var::create(pChildren,cbTail));

  assert(childData.first);

  m_childs.push_back(__STL_MOVE_VALUE(childData.first));

  assert(pChildren<childData.second);;
  assert(childData.second<=eChildren);

  pOurData=childData.second;
 }//while

 return eChildren;
}//internal__load

//------------------------------------------------------------------------
t_ver_info_element__VarFileInfo::size_type
 t_ver_info_element__VarFileInfo::child_count()const
{
 return m_childs.size();
}//child_count

//------------------------------------------------------------------------
t_ver_info_element__Var*
 t_ver_info_element__VarFileInfo::child(size_type const i)const
{
 assert(i<m_childs.size());

 return m_childs[i];
}//child

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
