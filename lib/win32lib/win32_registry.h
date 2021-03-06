////////////////////////////////////////////////////////////////////////////////
//Classes for work WIN32 Registry
//                                     Dmitry Kovalenko. 20 december, 2003 year
#ifndef _win32_registry_
#define _win32_registry_

#include <win32lib/win32lib.h>
#include <structure/t_str_parameter.h>
#include <structure/stl/t_stl_vector.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//class TRegistry

class TRegistry
{
 private:
  typedef TRegistry                                                 self_type;

  TRegistry(const self_type& reg);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_void_allocator                               allocator_type;
  typedef structure::t_stl_vector<t_string,allocator_type>          TNameArray;
  typedef structure::t_typed_simple_buffer<BYTE,allocator_type>     TDataBuffer;

  typedef structure::t_char                                         char_type;

  typedef structure::t_str_parameter<t_char>                        str_arg_type;

  typedef structure::t_typed_simple_buffer<t_char,allocator_type>   t_char_buffer;

  struct TRegKeyInfo
  {
   public:
    typedef DWORD                num_sub_keys_type;
    typedef DWORD                max_sub_key_name_len_type;
    typedef DWORD                num_values_type;
    typedef DWORD                max_value_name_len_type;
    typedef DWORD                max_data_len_type;
    
   public:
    num_sub_keys_type            NumSubKeys;
    max_sub_key_name_len_type    MaxSubKeyLen;
    num_values_type              NumValues;
    max_value_name_len_type      MaxValueLen;
    max_data_len_type            MaxDataLen;
    FILETIME                     FileTime;
  };//struct TRegKeyInfo

  struct TRegDataInfo
  {
   DWORD type;//??? ??????
   DWORD size;//?????? ? ??????
  };

  //????? ????????????? ????? ???????
  class TKey;

 private://----------------------------------------------------------------
  static bool test_win32_code__key_not_exists(LONG result);

 public: //static methods -------------------------------------------------

  //open key
  static LONG OpenKeyEx(HKEY         key,
                        str_arg_type key_name,
                        HKEY*        pNewKey,
                        REGSAM       samDesired,
                        bool         create);

  static HKEY  GetKeyEx(HKEY         key,
                        str_arg_type key_name,
                        REGSAM       samDesired,
                        LONG*        lResult);

  //----------------------------------------------------------------------
  static LONG GetValueInfo(HKEY          hKey,
                           str_arg_type  name,
                           TRegDataInfo& data);
  
  static LONG GetValueInfo(HKEY          hKey,
                           str_arg_type  name,
                           DWORD&        type,
                           TDataBuffer&  buffer);

  //returns 0, if any errors occurred
  //if lpResult!=NULL, then *lpResult containing code of last error
  static DWORD GetDataSize(HKEY hkey,str_arg_type name,LONG* lpResult);

  //?????????? ? ??????? ??????? -----------------------------------------
  static LONG GetKeyInfo(HKEY key,TRegKeyInfo& info);

  static void GetKeyNames(HKEY key,TNameArray& names);
  static void GetValueNames(HKEY key,TNameArray& names);

  static bool HasSubKeys(HKEY key);

  static bool KeyExists(HKEY key,str_arg_type name);
  static bool ValueExists(HKEY key,str_arg_type name);

  static LONG DeleteKey(HKEY key,str_arg_type key_name);
  
  static LONG DeleteKey(HKEY key,str_arg_type path,str_arg_type key_name);

  static LONG DeleteValue(HKEY key,str_arg_type name);
  static LONG DeleteValue(HKEY key,str_arg_type path,str_arg_type name);

  //string variables ----------------------------------------------------
  static t_string ReadString(HKEY         hkey,
                             str_arg_type name,
                             LONG*        lpResult);
  
  static bool WriteString(HKEY            hkey,
                          str_arg_type    name,
                          const t_string& value,
                          LONG*           lpResult);

  //LONG variables ------------------------------------------------------
  static LONG   ReadInteger(HKEY hkey,str_arg_type name,LONG* lpResult);
  static bool  WriteInteger(HKEY hkey,str_arg_type name,LONG value,LONG* lpResult);

  //Binary variables ----------------------------------------------------
  //return error code
  //static LONG  ReadBinary(HKEY hkey,const t_string& name,DWORD buf_size,char* buffer);
  //static LONG WriteBinary(HKEY hkey,const t_string& name,DWORD buf_size,char* buffer);

  //---------------------------------------------------------------------------
  static t_string  ReadString(HKEY            key,
                              str_arg_type    sub_key,
                              str_arg_type    name,
                              bool            create_sub_key,
                              LONG*           lpResult=NULL);

  //return true - if errors not occurred
  static bool     WriteString(HKEY            key,
                              str_arg_type    sub_key,
                              str_arg_type    name,
                              const t_string& text,
                              bool            create_sub_key,
                              LONG*           lpResult=NULL);

  static LONG     ReadInteger(HKEY            key,
                              str_arg_type    sub_key,
                              str_arg_type    name,
                              bool            create_sub_key,
                              LONG*           lpResult=NULL);

  //return true - if errors not occurred
  static bool    WriteInteger(HKEY            key,
                              str_arg_type    sub_key,
                              str_arg_type    name,
                              LONG            digit,
                              bool            create_sub_key,
                              LONG*           lpResult=NULL);//true - ?? ???? ??????

 public://----------------------------------------------------------------
  HKEY RootKey;
  HKEY CurrentKey;

 public:
  explicit TRegistry(HKEY _RootKey=HKEY_CURRENT_USER);

  //copy reg.RootKey and clone reg.CurrentKey 
  TRegistry(const TRegistry& reg,REGSAM samDesired);

 ~TRegistry();

 public: //---------------------------------------------------------------
  LONG   CloseKey();

  LONG   OpenKeyEx(str_arg_type key_name,REGSAM samDesired,bool create);
  HKEY   GetKeyEx (str_arg_type key_name,REGSAM samDesired,LONG* lResult);

  LONG   GetValueInfo(str_arg_type key_name,TRegDataInfo& data);
  
  LONG   GetKeyInfo(TRegKeyInfo& info);

  DWORD  GetDataSize(str_arg_type name,LONG* lResult);

  int    GetData(str_arg_type val_name,char* buffer,DWORD buf_size,DWORD& val_type);
  LONG   PutData(str_arg_type val_name,const char* buffer,DWORD buf_size,DWORD val_type);

  bool   KeyExists(str_arg_type name);
  bool   ValueExists(str_arg_type name);

  LONG   DeleteKey(str_arg_type key_name);
  
  LONG   DeleteKey(str_arg_type path,str_arg_type key_name);
  
  LONG   DeleteValue(str_arg_type name);

  void   GetKeyNames(TNameArray& names);
  void   GetValueNames(TNameArray& names);

  bool   HasSubKeys();

  //String variables -----------------------------------------------------
  t_string  ReadString(str_arg_type    name,
                       LONG*           lpResult);

  bool     WriteString(str_arg_type    name,
                       const t_string& text,
                       LONG*           lResult);

  t_string  ReadString(str_arg_type    sub_key,
                       str_arg_type    name,
                       bool            create_sub_key,
                       LONG*           lResult);

  bool     WriteString(str_arg_type    sub_key,
                       str_arg_type    name,
                       const t_string& text,
                       bool            create_sub_key,
                       LONG*           lResult);

  //LONG variables -------------------------------------------------------
  LONG   ReadInteger (str_arg_type    name,
                      LONG*           lpResult);

  bool   WriteInteger(str_arg_type    name,
                      LONG            digit,
                      LONG*           lResult);

  //Binary variables -----------------------------------------------------
  //void   ReadBinary(const t_string& name,DWORD buf_size,char* buffer);
  //void   WriteBinary(const t_string& name,DWORD buf_size,char* buffer);

 protected:
  HKEY GetBaseKey()const;

  void ChangeKey(HKEY newKey);
};//class TRegistry

////////////////////////////////////////////////////////////////////////////////
//class TRegistry::TKey

class TRegistry::TKey
{
 private:
  typedef TKey                                    self_type;

  TKey(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_str_parameter<t_char>      str_arg_type;

 public:
  bool call_close;

  TKey();

  TKey(HKEY hKey,bool _call_close);

 ~TKey();

 public:
  operator HKEY () const {return m_hKey;}

  self_type& close();

  LONG cloneEx(HKEY key,REGSAM samDesired);

  self_type& set(HKEY key,bool _call_close);

  LONG OpenKeyEx(HKEY hKey,str_arg_type subKey,REGSAM samDesired);
  
  LONG CreateKeyEx(HKEY hKey,str_arg_type subKey,REGSAM samDesired);

 private:
  HKEY m_hKey;
};//class TRegistry::TKey

////////////////////////////////////////////////////////////////////////////////
//class TRegistry - inline implementation

inline bool TRegistry::test_win32_code__key_not_exists(LONG result)
{
 //tests results (w2k server SP4): can use ERROR_FILE_NOT_FOUND only
 return result==ERROR_FILE_NOT_FOUND || result==ERROR_PATH_NOT_FOUND;
}//test_win32_code__key_not_exists

//------------------------------------------------------------------------
inline TRegistry::TRegistry(HKEY _RootKey)
 :RootKey(_RootKey)
 ,CurrentKey(NULL)
{
}

//------------------------------------------------------------------------
inline TRegistry::TRegistry(const TRegistry& reg,REGSAM samDesired)
 :RootKey(reg.RootKey)
 ,CurrentKey(NULL)
{
 //clone reg.CurrentKey
 if(reg.CurrentKey!=NULL)
 {
  ::RegOpenKeyEx(reg.CurrentKey,_T(""),0,samDesired,&CurrentKey);
 }//if
}//TRegistry

//------------------------------------------------------------------------
inline TRegistry::~TRegistry()
{
 this->CloseKey();
}//~TRegistry

//------------------------------------------------------------------------
inline LONG TRegistry::GetValueInfo(HKEY hkey,str_arg_type name,TRegDataInfo& data)
{
 return ::RegQueryValueEx(hkey,name.str(),NULL,&data.type,NULL,&data.size);
}

//------------------------------------------------------------------------
inline LONG TRegistry::GetKeyInfo(HKEY key,TRegKeyInfo& info)
{
 return ::RegQueryInfoKey(key,NULL,NULL,NULL,
                          &info.NumSubKeys,
                          &info.MaxSubKeyLen,
                          NULL,
                          &info.NumValues,
                          &info.MaxValueLen,
                          &info.MaxDataLen,
                          NULL,
                          &info.FileTime);
}//GetKeyInfo

//------------------------------------------------------------------------
inline LONG TRegistry::DeleteValue(HKEY key,str_arg_type name)
{
 return ::RegDeleteValue(key,name.str());
}//DeleteValue

//------------------------------------------------------------------------
inline bool TRegistry::WriteInteger(HKEY         const key,
                                    str_arg_type const name,
                                    LONG         const value,
                                    LONG*        const lpResult)
{
 const LONG lResult=::RegSetValueEx(key,
                                    name.str(),
                                    0,
                                    REG_DWORD,
                                    reinterpret_cast<const BYTE*>(&value),
                                    sizeof(value));

 if(lpResult!=NULL)
  (*lpResult)=lResult;

 return lResult==ERROR_SUCCESS;
}//WriteInteger

//------------------------------------------------------------------------
inline HKEY TRegistry::GetKeyEx(str_arg_type const key_name,
                                REGSAM       const samDesired,
                                LONG*        const lpResult)
{
 return GetKeyEx(this->GetBaseKey(),key_name,samDesired,lpResult);
}

//------------------------------------------------------------------------
inline LONG TRegistry::GetValueInfo(str_arg_type   key_name,
                                    TRegDataInfo&  data)
{
 return GetValueInfo(this->GetBaseKey(),key_name,data);
}

//------------------------------------------------------------------------
inline LONG TRegistry::GetKeyInfo(TRegKeyInfo& info)
{
 return GetKeyInfo(this->GetBaseKey(),info);
}

//------------------------------------------------------------------------
inline DWORD TRegistry::GetDataSize(str_arg_type const name,
                                    LONG*        const lResult)
{
 return GetDataSize(this->GetBaseKey(),name,lResult);
}

//------------------------------------------------------------------------
inline bool TRegistry::KeyExists(str_arg_type const name)
{
 return KeyExists(this->GetBaseKey(),name);
}

//------------------------------------------------------------------------
inline bool TRegistry::ValueExists(str_arg_type name)
{
 return ValueExists(this->GetBaseKey(),name);
}

//------------------------------------------------------------------------
inline LONG TRegistry::DeleteKey(str_arg_type key_name)
{
 return DeleteKey(this->GetBaseKey(),key_name);
}

//------------------------------------------------------------------------
inline LONG TRegistry::DeleteKey(str_arg_type path,str_arg_type key_name)
{
 return DeleteKey(this->GetBaseKey(),path,key_name);
}

//------------------------------------------------------------------------
inline LONG TRegistry::DeleteValue(str_arg_type name)
{
 return ::RegDeleteValue(this->GetBaseKey(),name.str());
}

//------------------------------------------------------------------------
inline void TRegistry::GetKeyNames(TNameArray& names)
{
 GetKeyNames(this->GetBaseKey(),names);
}

//------------------------------------------------------------------------
inline void TRegistry::GetValueNames(TNameArray& names)
{
 GetValueNames(this->GetBaseKey(),names);
}

//------------------------------------------------------------------------
inline bool TRegistry::HasSubKeys()
{
 return HasSubKeys(this->GetBaseKey());
}

//------------------------------------------------------------------------
inline HKEY TRegistry::GetBaseKey()const
{
 return (CurrentKey==NULL)?RootKey:CurrentKey;
}

//------------------------------------------------------------------------
inline void TRegistry::ChangeKey(HKEY newKey)
{
 //TODO: [BUG?] if newKey==currentKey
 this->CloseKey();

 CurrentKey=newKey;
}//ChangeKey

////////////////////////////////////////////////////////////////////////////////
//class TRegistry::TKey - inline implementation

inline TRegistry::TKey::TKey()
 :m_hKey(NULL)
 ,call_close(true)
{;}

//------------------------------------------------------------------------
inline TRegistry::TKey::TKey(HKEY hKey,bool _call_close)
 :m_hKey(hKey)
 ,call_close(_call_close)
{
}//TKey

//------------------------------------------------------------------------
inline TRegistry::TKey::~TKey()
{
 this->close();
}//~TKey

//------------------------------------------------------------------------
inline TRegistry::TKey& TRegistry::TKey::close()
{
 if(m_hKey && call_close)
  _VERIFY_EQ(::RegCloseKey(m_hKey),ERROR_SUCCESS);

 m_hKey=NULL;

 return *this;
}//close

//------------------------------------------------------------------------
inline LONG TRegistry::TKey::cloneEx(HKEY key,REGSAM samDesired)
{
 return this->OpenKeyEx(key,_T(""),samDesired);
}//cloneEx

//------------------------------------------------------------------------
inline TRegistry::TKey& TRegistry::TKey::set(HKEY key,bool _call_close)
{
 this->close();

 this->call_close=_call_close;

 m_hKey=key;

 return *this;
}//set

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
