////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////

void FreeBStr(BSTR& bstr)
{
 if(bstr==nullptr)
  return;

 BSTR tmp=bstr;

 bstr=nullptr;

 LCPI_OS__SysFreeString(tmp);
}//FreeBStr

////////////////////////////////////////////////////////////////////////////////

HRESULT CopyBStr2(BSTR Source,BSTR* const pTarget)
{
 assert(pTarget!=nullptr);

 if(pTarget==nullptr)
  return E_POINTER;

 if((*pTarget)!=nullptr)
  return E_POINTER;

 if(Source==(*pTarget))
  return S_OK;

 if(Source!=nullptr)
 {
  (*pTarget)=LCPI_OS__SysAllocStringLen(Source,LCPI_OS__SysStringLen(Source));
  
  if((*pTarget)==nullptr)
   return E_OUTOFMEMORY;
 }//if

 return S_OK;
}//CopyBStr2

////////////////////////////////////////////////////////////////////////////////
//Function for string conversion [OLE Automation]

BSTR StringToBStr(const char* source,
                  size_t      source_len,
                  bool  const create_empty)
{
 if(structure::is_negative_one(source_len))
 {
  if(source==nullptr)
   source_len=0;
  else
   source_len=strlen(source);
 }
#ifndef NDEBUG
 else
 {
  CHECK_READ_TYPED_PTR(source,source_len);
 }//else
#endif

 if(source_len==0)
 {
  if(!create_empty)
   return nullptr;  
 
  if(BSTR const result=LCPI_OS__SysAllocStringLen(nullptr,0))
   return result;

  throw std::bad_alloc();
 }//if source_len==0

 assert_hint(source_len>0);

 if(!structure::can_numeric_cast<int>(source_len))
  throw std::length_error("Length error in StringToBStr [ansi version]");

 const int int_source_len=static_cast<int>(source_len);

 assert(int_source_len>0);

 const int wlen
  =::MultiByteToWideChar(0,0,source,int_source_len,nullptr,0);

 if(wlen==0) //error
 {
  const DWORD dwLastError=::GetLastError();

  assert(dwLastError!=0);

  HRESULT hr=HRESULT_FROM_WIN32(dwLastError);

  assert(FAILED(hr));

  if(SUCCEEDED(hr))
   hr=E_FAIL;

  t_base_ole_error::throw_error
   (hr,
    "StringToBStr [ansi version]: MultiByteToWideChar is failed");
 }//if wlnel==0

 assert_hint(wlen!=0);

 if(wlen<0)
 {
  t_base_ole_error::throw_error
   (E_FAIL,
    "StringToBStr [ansi version]: MultiByteToWideChar return negative code");
 }//if wlen<0

 assert_hint(wlen>0);

 //----------------------------------------- FINISH

 //выделяем память без учета завершающего символа
 BSTR result=LCPI_OS__SysAllocStringLen(nullptr,wlen);

 if(result==nullptr)
  throw std::bad_alloc();

 const int wlen2=::MultiByteToWideChar(0,0,source,int_source_len,result,wlen);

 if(wlen2==0) //error
 {
  const DWORD dwLastError=::GetLastError();

  assert(dwLastError!=0);

  //----
  FreeBStr(result);

  //----
  HRESULT hr=HRESULT_FROM_WIN32(dwLastError);

  assert(FAILED(hr));

  if(SUCCEEDED(hr))
   hr=E_FAIL;

  t_base_ole_error::throw_error
   (hr,
    "StringToBStr [ansi version]: MultiByteToWideChar is failed");
 }//if wlen2==0

 if(wlen!=wlen2)
 {
  FreeBStr(result);

  //----
  t_base_ole_error::throw_error
   (E_FAIL,
    "[BUG CHECK] Unexpected error in StringToBStr [ansi version]. Check point: #001.");
 }//if

 assert_hint(wlen==wlen2);

 assert_hint(result!=nullptr);

 return result;
}//StringToBStr

//------------------------------------------------------------------------
HRESULT StringToBStr(BSTR*       const bstr,
                     const char* const source,
                     size_t      const source_len,
                     bool        const create_empty)
{
 if(bstr==nullptr)
  return E_POINTER;

 (*bstr)=nullptr;

 try
 {
  (*bstr)=StringToBStr(source,source_len,create_empty);
 }
 catch(const std::bad_alloc&)
 {
  return E_OUTOFMEMORY;
 }
 catch(...)
 {
  return E_FAIL;
 }

 return S_OK;
}//StringToBStr

////////////////////////////////////////////////////////////////////////////////
//преобразование UNICODE строки в BSTR (UNICODE для автоматизации)

BSTR WStrToBStr(const wchar_t* source,
                size_t         source_len,
                bool     const create_empty)//throw
{
 if(source==nullptr)
 {
  if(!create_empty)
   return nullptr;

  source_len=0;

  source=L"";
 }
 else
 if(structure::is_negative_one(source_len)) //автоматическое определение длины
 {
  assert(source!=nullptr);

  //передали пустую строку и её не требуется создавать.
  if(!create_empty)
  {
   if((*source)==L'\0')
    return nullptr;
  }//if

  source_len=structure::string_length(source);
 }
 else
 {
  assert(source!=nullptr);

  assert(!structure::is_negative_one(source_len));

  CHECK_READ_TYPED_PTR(source,source_len);

  //нам передали нулевую длину строки и не требуется создавать пустую строку
  if(!create_empty)
  {
   if(source_len==0)
    return nullptr;
  }//if
 }//else

 if(!structure::can_numeric_cast<UINT>(source_len))
  throw std::length_error("Length error in WStrToBstr");

 BSTR const result=LCPI_OS__SysAllocStringLen(source,static_cast<UINT>(source_len));

 if(result==nullptr)
  throw std::bad_alloc();

 return result;
}//WStrToBStr

//------------------------------------------------------------------------
HRESULT WStrToBStr(BSTR*          const bstr,
                   const wchar_t* const source,
                   size_t         const source_len,
                   bool           const create_empty)
{
 if(bstr==nullptr)
  return E_POINTER;

 (*bstr)=nullptr;

 try
 {
  (*bstr)=WStrToBStr(source,source_len,create_empty);
 }
 catch(const std::bad_alloc&)
 {
  return E_OUTOFMEMORY;
 }
 catch(...)
 {
  return E_FAIL;
 }

 return S_OK;
}//WStrToBStr

////////////////////////////////////////////////////////////////////////////////
