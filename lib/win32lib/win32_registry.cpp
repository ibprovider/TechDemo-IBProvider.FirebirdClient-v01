////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <win32lib/win32_registry.h>
#include <structure/t_function.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//class TRegistry

//static-function --------------------------------------------------------
LONG TRegistry::OpenKeyEx(HKEY         const key,
                          str_arg_type const key_name,
                          HKEY*        const pNewKey,
                          REGSAM       const samDesired,
                          bool         const create)
{
 assert(pNewKey!=nullptr);

 (*pNewKey)=NULL;

 LONG  ret;
 DWORD disposition;

 if(!create)
 {
  ret=::RegOpenKeyEx(key,
                     key_name.str(),
                     0,
                     samDesired,
                     pNewKey);
 }
 else
 {
  ret=::RegCreateKeyEx(key,
                       key_name.str(),
                       0,
                       NULL,
                       REG_OPTION_NON_VOLATILE,
                       samDesired,
                       NULL,
                       pNewKey,
                       &disposition);
 }//else
 
 if(ret!=ERROR_SUCCESS)
  (*pNewKey)=NULL;

 return ret;
}//OpenKeyEx

//------------------------------------------------------------------------
LONG TRegistry::GetValueInfo(HKEY         const hKey,
                             str_arg_type const name,
                             DWORD&             type,
                             TDataBuffer&       buffer)
{
 TRegDataInfo DataInfo;

 LONG lResult=GetValueInfo(hKey,name,DataInfo);

 if(lResult==ERROR_SUCCESS)
 {
  DWORD size=DataInfo.size;

  buffer.free();

  buffer.alloc(size);

  lResult=::RegQueryValueEx(hKey,name.str(),NULL,&type,buffer.buffer(),&size);

  //контролируем стабильность полученной информации
  if(lResult==ERROR_SUCCESS && (type!=DataInfo.type || size!=DataInfo.size))
   lResult=ERROR_CANTREAD;
 }

 if(lResult!=ERROR_SUCCESS)
 {
  type=REG_NONE;
  buffer.free();
 }

 return lResult;
}//GetValueInfo

//------------------------------------------------------------------------
DWORD TRegistry::GetDataSize(HKEY         const key,
                             str_arg_type const name,
                             LONG*        const lpResult)
{
 TRegDataInfo info;

 const LONG lResult=GetValueInfo(key,name,info);

 if(lpResult!=NULL)
  (*lpResult)=lResult;

 return (lResult==ERROR_SUCCESS)?info.size:0;
}//GetDataSize

//------------------------------------------------------------------------
HKEY TRegistry::GetKeyEx(HKEY         const key,
                         str_arg_type const key_name,
                         REGSAM       const samDesired,
                         LONG*        const lpResult)
{
 HKEY ret=NULL;

 const LONG lResult=::RegOpenKeyEx(key,key_name.str(),0,samDesired,&ret);

 if(lpResult!=NULL)
  (*lpResult)=lResult;

 return (lResult==ERROR_SUCCESS)?ret:NULL;
}//GetKeyEx

//------------------------------------------------------------------------
void TRegistry::GetKeyNames(HKEY  const key,
                            TNameArray& names)
{
 names.clear();

 TRegKeyInfo key_info;

 if(GetKeyInfo(key,key_info)==ERROR_SUCCESS && key_info.NumSubKeys!=0)
 {
  typedef TRegKeyInfo::max_sub_key_name_len_type max_sub_key_name_len_type;
  
  if(key_info.MaxSubKeyLen==structure::t_numeric_limits<max_sub_key_name_len_type>::max_value())
   throw std::overflow_error("Overflow in TRegistry::GetKeyNames");
  
  assert(static_cast<size_t>(key_info.MaxSubKeyLen)+1==(key_info.MaxSubKeyLen+1));

  names.reserve((TNameArray::size_type)key_info.NumSubKeys);
    
  t_char_buffer name(key_info.MaxSubKeyLen+1);

  for(DWORD i=0;i<key_info.NumSubKeys;++i)
  {
   DWORD len=static_cast<max_sub_key_name_len_type>(name.size());
   
   //returned len len NOT include terminating '\0'

   //TODO 2: Test result code from RegEnumKeyEx
   ::RegEnumKeyEx(key,i,name.buffer(),&len,0,0,0,0);

   assert(name.size()==(key_info.MaxSubKeyLen+1));

   names.push_back(t_string(name.buffer(),min(key_info.MaxSubKeyLen,len)));
  }
 }//if
}//GetKeyNames

//------------------------------------------------------------------------
void TRegistry::GetValueNames(HKEY  const key,
                              TNameArray& names)
{
 names.clear();

 TRegKeyInfo key_info;
 if(GetKeyInfo(key,key_info)==ERROR_SUCCESS && key_info.NumValues!=0)
 {
  typedef TRegKeyInfo::max_value_name_len_type max_value_name_len_type;
  
  if(key_info.MaxValueLen==structure::t_numeric_limits<max_value_name_len_type>::max_value())
   throw std::overflow_error("Overflow in TRegistry::GetValueNames");
  
  assert(static_cast<size_t>(key_info.MaxValueLen)+1==(key_info.MaxValueLen+1));

  names.reserve(key_info.NumValues);

  t_char_buffer name(key_info.MaxValueLen+1);

  for(DWORD i=0;i<key_info.NumValues;++i)
  {
   DWORD len=static_cast<max_value_name_len_type>(name.size());
   
   //returned len not include terminating '\0'

   //TODO 2: test result code from RegEnumValue
   ::RegEnumValue(key,i,name.buffer(),&len,0,0,0,0);

   assert(name.size()==(key_info.MaxValueLen+1));

   names.push_back(t_string(name.buffer(),min(key_info.MaxValueLen,len)));
  }//for
 }//if
}//GetValueNames

//------------------------------------------------------------------------
bool TRegistry::HasSubKeys(HKEY const key)
{
 TRegKeyInfo key_info;
 
 if(GetKeyInfo(key,key_info)==ERROR_SUCCESS)
  return key_info.NumSubKeys>0;

 return false;
}//HasSubKeys

//------------------------------------------------------------------------
bool TRegistry::KeyExists(HKEY         const key,
                          str_arg_type const name)
{
 return !test_win32_code__key_not_exists(TKey().OpenKeyEx(key,name,KEY_READ));
}//KeyExists

//------------------------------------------------------------------------
bool TRegistry::ValueExists(HKEY         const key,
                            str_arg_type const name)
{
 TRegDataInfo info;
 
 return GetValueInfo(key,name,info)==ERROR_SUCCESS;
}//ValueExists

//------------------------------------------------------------------------
LONG TRegistry::DeleteKey(HKEY         const key,
                          str_arg_type const key_name)
{
 //Open the child.
 TKey KeyChild;

 if(const LONG lResult=KeyChild.OpenKeyEx(key,key_name,KEY_READ|KEY_WRITE))
  return lResult;

 // Enumerate all of the decendents of this child.
 TRegKeyInfo info;

 if(const LONG lResult=GetKeyInfo(KeyChild,info))
  return lResult;

 typedef TRegKeyInfo::max_sub_key_name_len_type max_sub_key_name_len_type;

 if(info.NumSubKeys!=0)
 {
  if(info.MaxSubKeyLen==structure::t_numeric_limits<max_sub_key_name_len_type>::max_value())
   throw std::overflow_error("Overflow in TRegistry::DeleteKey");

  t_char_buffer name(info.MaxSubKeyLen+1);

  for(;;)
  {
   DWORD dwSize=static_cast<max_sub_key_name_len_type>(name.size());
   
   //until key has subkeys
   if(RegEnumKeyEx(KeyChild,0,name.buffer(),&dwSize,NULL,NULL,NULL,NULL)!=S_OK)
    break;

   assert(name.size()==(info.MaxSubKeyLen+1));

   name[min(info.MaxSubKeyLen,dwSize)]=0;

   if(const LONG lResult=DeleteKey(KeyChild,name.buffer()))
    return lResult;
  }//while
 }//if NumSubKeys!=0

 KeyChild.close();

 assert(KeyChild==NULL);

 return ::RegDeleteKey(key,key_name.str());//Delete this child.
}//DeleteKey

//------------------------------------------------------------------------
LONG TRegistry::DeleteKey(HKEY         const key,
                          str_arg_type const path,
                          str_arg_type const key_name)
{
 TKey tmpKey;
 
 if(LONG const lResult=tmpKey.OpenKeyEx(key,path,KEY_READ|KEY_WRITE))
  return lResult;
 
 return self_type::DeleteKey(tmpKey,key_name);
}//DeleteKey

//------------------------------------------------------------------------
LONG TRegistry::DeleteValue(HKEY         const key,
                            str_arg_type const path,
                            str_arg_type const name)
{
 TKey tmpKey;

 if(const LONG retValue=tmpKey.OpenKeyEx(key,path,KEY_WRITE))
  return retValue;

 return self_type::DeleteValue(tmpKey,name);
}//DeleteValue

////////////////////////////////////////////////////////////////////////////////
//read variables

t_string TRegistry::ReadString(HKEY         const hkey,
                               str_arg_type const name,
                               LONG*        const lpResult)
{
 DWORD       type;
 TDataBuffer buffer;
 t_string    value;

 LONG lResult=self_type::GetValueInfo(hkey,name,type,buffer);

 if(lResult==ERROR_SUCCESS)
 {
  switch(type)
  {
   case          REG_SZ:
   case    REG_MULTI_SZ:
   case   REG_EXPAND_SZ:
    {
     if(buffer.empty())
      break;

     if(buffer.size()<sizeof(t_char))
      lResult=ERROR_CANTREAD;
     else
     {
      //игнорирование завершающего нулевого символа
      const t_char* const beg=reinterpret_cast<const t_char*>(buffer.buffer());
      const t_char* const end=beg+((buffer.size()-sizeof(t_char))/sizeof(t_char));

      value.assign(beg,end);
     }
     break;
    }//XXX_SZ
    
   case       REG_DWORD:
    {
     assert(buffer.size()==sizeof(DWORD));

     if(buffer.size()!=sizeof(DWORD))
      lResult=ERROR_CANTREAD;
     else
     {
      TCHAR tmpStr[64];

      _GCRT_itot_s(*reinterpret_cast<const DWORD*>(buffer.buffer()),tmpStr,_DIM_(tmpStr),10);

      value=tmpStr;
     }
     break;
    }//DWORD
    
   default             :
    {
     lResult=ERROR_CANTREAD;
     break;
    }
    
  }//switch
 }//if ERROR_SUCCESS - чтение данных

 if(lpResult!=NULL)
  (*lpResult)=lResult;

 return value;
}//ReadString

//------------------------------------------------------------------------
bool TRegistry::WriteString(HKEY         const key,
                            str_arg_type const name,
                            const t_string&    value,
                            LONG*        const lpResult)
{
 const size_t cb_value=sizeof(t_string::value_type)*(value.size()+1);
 
 if(cb_value>size_t(structure::t_numeric_limits<DWORD>::max_value()))
  throw std::length_error("Length error in TRegistry::WriteString");

 //length included terminated symbol
 const LONG lResult=::RegSetValueEx(key,
                                    name.str(),
                                    0,
                                    REG_SZ,
                                    reinterpret_cast<const BYTE*>(value.c_str()),
                                    DWORD(cb_value));

 if(lpResult!=NULL)
  (*lpResult)=lResult;

 return lResult==ERROR_SUCCESS;
}//WriteString

//------------------------------------------------------------------------
LONG TRegistry::ReadInteger(HKEY         const hkey,
                            str_arg_type const name,
                            LONG*        const lpResult)
{
 DWORD       type;
 TDataBuffer buffer;
 LONG        value=0;

 LONG lResult=GetValueInfo(hkey,name,type,buffer);

 if(lResult==ERROR_SUCCESS)
 {
  switch(type)
  {
   case      REG_DWORD:assert(buffer.size()==sizeof(value));
   case     REG_BINARY:
    {
     if(buffer.size()!=sizeof(value))
      lResult=ERROR_CANTREAD;
     else
      value=*reinterpret_cast<const LONG*>(buffer.buffer());

     break;
    }//DWORD/BINARY

   case         REG_SZ:
   case   REG_MULTI_SZ:
   case  REG_EXPAND_SZ:
    {
     if(buffer.empty())
      break;

     if(buffer.size()<sizeof(t_char))
      lResult=ERROR_CANTREAD;
     else
     {
      //игнорирование завершающего нулевого символа
      const t_char* const beg=reinterpret_cast<const t_char*>(buffer.buffer());
      const t_char* const end=beg+((buffer.size()-sizeof(t_char))/sizeof(t_char));

      t_string str(beg,end);

      t_char* endptr=NULL;

      value=_tcstol(str.c_str(),&endptr,0);

      if(endptr!=NULL && t_byte(*endptr)>t_byte(' '))
       lResult=ERROR_CANTREAD;
     }
     break;
    }//XXX_SZ

   default            :
    {
     lResult=ERROR_CANTREAD;
     break;
    }
  }//switch
 }//if ERROR_SUCCESS - чтение данных

 if(lpResult!=NULL)
  (*lpResult)=lResult;

 return value;
}//ReadInteger

////////////////////////////////////////////////////////////////////////////////
// helper static function

t_string TRegistry::ReadString(HKEY         const hkey,
                               str_arg_type const sub_key,
                               str_arg_type const name,
                               bool         const create_sub_key,
                               LONG*        const lpResult)
{
 TRegistry Reg(hkey);

 LONG const lResult=Reg.OpenKeyEx(sub_key,KEY_QUERY_VALUE,create_sub_key);

 if(lResult==ERROR_SUCCESS)
  return Reg.ReadString(name,lpResult);

 if(lpResult!=NULL)
  (*lpResult)=lResult;

 return t_string();
}//ReadString

//------------------------------------------------------------------------
bool TRegistry::WriteString(HKEY          const hkey,
                            str_arg_type  const sub_key,
                            str_arg_type  const name,
                            const t_string&     value,
                            bool          const create_sub_key,
                            LONG*         const lpResult)
{
 TRegistry Reg(hkey);

 LONG const lResult=Reg.OpenKeyEx(sub_key,KEY_WRITE,create_sub_key);

 if(lResult==ERROR_SUCCESS)
  return Reg.WriteString(name,value,lpResult);

 assert_hint(lResult!=ERROR_SUCCESS);

 if(lpResult!=NULL)
  (*lpResult)=lResult;

 return false;
}//WriteString

//------------------------------------------------------------------------
LONG TRegistry::ReadInteger(HKEY         const hkey,
                            str_arg_type const sub_key,
                            str_arg_type const name,
                            bool         const create_sub_key,
                            LONG*        const lpResult)
{
 TRegistry Reg(hkey);

 LONG const lResult=Reg.OpenKeyEx(sub_key,KEY_QUERY_VALUE,create_sub_key);

 if(lResult==ERROR_SUCCESS)
  return Reg.ReadInteger(name,lpResult);

 if(lpResult!=NULL)
  (*lpResult)=lResult;

 return 0;
}//ReadInteger

//------------------------------------------------------------------------
bool TRegistry::WriteInteger(HKEY         const hkey,
                             str_arg_type const sub_key,
                             str_arg_type const name,
                             LONG         const value,
                             bool         const create_sub_key,
                             LONG*        const lpResult)
{
 TRegistry Reg(hkey);

 LONG const lResult=Reg.OpenKeyEx(sub_key,KEY_WRITE,create_sub_key);

 if(lResult==ERROR_SUCCESS)
  return Reg.WriteInteger(name,value,lpResult);

 assert_hint(lResult!=ERROR_SUCCESS);

 if(lpResult!=NULL)
  (*lpResult)=lResult;

 return false;
}//WriteInteger

////////////////////////////////////////////////////////////////////////////////
//member-fuction TRegistry

LONG TRegistry::CloseKey()
{
 if(!CurrentKey)
  return ERROR_SUCCESS;

 const LONG lResult=::RegCloseKey(CurrentKey);

 CurrentKey=NULL;

 return lResult;
}//CloseKey

//------------------------------------------------------------------------
LONG TRegistry::OpenKeyEx(str_arg_type const key_name,
                          REGSAM       const samDesired,
                          bool         const create)
{
 HKEY tmpKey=NULL;

 const LONG lResult=self_type::OpenKeyEx(this->GetBaseKey(),
                                         key_name,
                                         &tmpKey,
                                         samDesired,
                                         create);

 if(lResult==ERROR_SUCCESS)
 {
  assert(tmpKey!=NULL);
  
  this->ChangeKey(tmpKey);
 }//if

 return lResult;
}//OpenKeyEx

////////////////////////////////////////////////////////////////////////////////
//work with variables

t_string TRegistry::ReadString(str_arg_type const name,
                               LONG*        const lpResult)
{
 return self_type::ReadString(this->GetBaseKey(),
                              name,
                              lpResult);
}//ReadString

//------------------------------------------------------------------------
bool TRegistry::WriteString(str_arg_type const name,
                            const t_string&    text,
                            LONG*        const lpResult)
{
 return self_type::WriteString(this->GetBaseKey(),
                               name,
                               text,
                               lpResult);
}//WriteString

//------------------------------------------------------------------------
t_string TRegistry::ReadString(str_arg_type const sub_key,
                               str_arg_type const name,
                               bool         const create_sub_key,
                               LONG*        const lpResult)
{
 return self_type::ReadString(this->GetBaseKey(),
                              sub_key,
                              name,
                              create_sub_key,
                              lpResult);
}//ReadString

//------------------------------------------------------------------------
bool TRegistry::WriteString(str_arg_type const sub_key,
                            str_arg_type const name,
                            const t_string&    text,
                            bool         const create_sub_key,
                            LONG*        const lpResult)
{
 return self_type::WriteString(this->GetBaseKey(),
                               sub_key,
                               name,
                               text,
                               create_sub_key,
                               lpResult);
}//WriteString

//------------------------------------------------------------------------
LONG TRegistry::ReadInteger(str_arg_type const name,
                            LONG*        const lpResult)
{
 return self_type::ReadInteger(this->GetBaseKey(),
                               name,
                               lpResult);
}//ReadInteger

//------------------------------------------------------------------------
bool TRegistry::WriteInteger(str_arg_type const name,
                             LONG         const digit,
                             LONG*        const lpResult)
{
 return self_type::WriteInteger(this->GetBaseKey(),
                                name,
                                digit,
                                lpResult);
}//WriteInteger

////////////////////////////////////////////////////////////////////////////////
//class TRegistry::TKey

LONG TRegistry::TKey::OpenKeyEx(HKEY         const hKey,
                                str_arg_type const subKey,
                                REGSAM       const samDesired)
{
 HKEY newKey=NULL;

 const LONG lResult=::RegOpenKeyEx(hKey,subKey.str(),NULL,samDesired,&newKey);

 if(lResult==ERROR_SUCCESS)
 {
  this->close();

  this->call_close=true;

  m_hKey=newKey;
 }//if ok
 
 return lResult;
}//OpenKeyEx

//------------------------------------------------------------------------
LONG TRegistry::TKey::CreateKeyEx(HKEY         const hKey,
                                  str_arg_type const subKey,
                                  REGSAM       const samDesired)
{
 HKEY newKey=NULL;

 DWORD disposition;

 const LONG lResult=::RegCreateKeyEx(hKey,
                                     subKey.str(),
                                     0,
                                     NULL,
                                     REG_OPTION_NON_VOLATILE,
                                     samDesired,
                                     NULL,
                                     &newKey,
                                     &disposition);

 if(lResult==ERROR_SUCCESS)
 {
  this->close();

  this->call_close=true;

  m_hKey=newKey;
 }//if ok

 return lResult;
}//CreateKeyEx

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
