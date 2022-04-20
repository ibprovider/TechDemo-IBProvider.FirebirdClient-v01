////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_xvariant_assign_CC_
#define _oledb_xvariant_assign_CC_

#include <ole_lib/oledb/variant/oledb_variant_sstream.h>

#include <structure/utilities/string/string_length.h>
#include <structure/t_str_formatter.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//template class basic_dbvariant

template<class Allocator>
RELEASE_CODE(inline)
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetDBNull()
{
 this->Clear();

 this->wType=DBTYPE_NULL;

 return *this;
}//SetDBNull

////////////////////////////////////////////////////////////////////////////////
//helper macros for assign operations

#define SET_SIMPLE_DBTYPE_EX(dbtype_id,assign_op)         \
 if(this->wType!=dbtype_id)                               \
 {                                                        \
  this->Clear();                                          \
  this->wType=dbtype_id;                                  \
 }                                                        \
                                                          \
 this->SetDataStatus__OK();                               \
                                                          \
 {                                                        \
  assign_op;                                              \
 }                                                        \
                                                          \
 return *this;

#define SET_SIMPLE_DBTYPE(dbtype_id,member_data,value)    \
 SET_SIMPLE_DBTYPE_EX(dbtype_id,this->member_data=(value))

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetError(value_scode_type _scode)
{
 SET_SIMPLE_DBTYPE(DBTYPE_ERROR,scodeVal,_scode)
}//SetError

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetError(const value_scode_n_type& _scode)
{
 if(!_scode.null())
  return this->SetError(_scode.value());

 this->SetError(0).SetDataStatus__IsNull();

 return *this;
}//SetError

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetBSTR(const BSTR data)
{
 if( !(this->wType==DBTYPE_BSTR && this->bstrVal!=nullptr && this->bstrVal==data) )
 {
  //first - make copy
  ole_lib::TBSTR _bstr(ole_lib::BStrToBox(data)); //throw

  assert(_bstr.bstr()!=nullptr);

  //two - clear current date
  this->Clear(); //throw?

  //third - set pointer of copy
  this->bstrVal=_bstr.Release();

  assert(_bstr.bstr()==NULL);

  this->wType=DBTYPE_BSTR;
 }//if - install new data

 this->SetDataStatus__OK();

 return *this;
}//SetBSTR

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetStrAsBSTR(const structure::t_const_str_box& data)
{
 ole_lib::TBSTR _bstr(data); //throw

 assert(_bstr.bstr()!=nullptr);

 this->Clear(); //throw?

 this->bstrVal=_bstr.Release();

 assert(this->bstrVal);

 assert(_bstr.bstr()==NULL);

 this->wType=DBTYPE_BSTR;

 this->SetDataStatus__OK();

 return *this;
}//SetStrAsBSTR

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetWStrAsBSTR(const structure::t_const_wstr_box& data)
{
 ole_lib::TBSTR _bstr(data); //throw

 assert(_bstr.bstr()!=nullptr);

 this->Clear(); //throw?

 this->bstrVal=_bstr.Release();

 assert(this->bstrVal);

 assert(_bstr.bstr()==NULL);

 this->wType=DBTYPE_BSTR;

 this->SetDataStatus__OK();

 return *this;
}//SetWStrAsBSTR

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetVariant(const VARIANT* data,bool const unpack)
{
 //! \todo
 //!  assert(data!=nullptr);

 if(wType==DBTYPE_VARIANT && &this->varVal==data)
 {
  //! \todo
  //!  we ignore unpack ....

  this->SetDataStatus__OK();

  return *this;
 }//if

 if(data==NULL)
  data=&__empty_variant__;

 if(unpack)
 {
  //unpack VARIANT data
  TCvtAdapter CvtAdapter;

  if(CvtAdapter.Unpack_Variant(*data)==S_OK)
  {
   return (*this)=CvtAdapter.dbvar();
  }
 }//if unpack

 //assign VARIANT copy
 VARIANT copyVarVal={0};

 ole_lib::Variant_CopyInd_Throw(&copyVarVal,data); //throw

 try
 {
  this->Clear(); //throw ?

  //direct copy !!!
  this->varVal=copyVarVal;

  this->wType=DBTYPE_VARIANT;
 }
 catch(...)
 {
  _VERIFY_EQ(ole_lib::Variant_Clear(&copyVarVal),S_OK);

  throw;
 }//catch

 assert(this->wType==DBTYPE_VARIANT);

 this->SetDataStatus__OK();

 return *this;
}//SetVariant

//------------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetVariant(const VARIANT& data,bool unpack)
{
 return this->SetVariant(&data,unpack);
}//SetVariant

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetDate(value_date_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_DATE,dateVal,data)
}//SetDate

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetDate(const value_date_n_type& data)
{
 if(!data.null())
  return this->SetDate(data.value());

 this->SetDate(0).SetDataStatus__IsNull();

 return *this;
}//SetDate

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetCY(const value_cy_type& data)
{
 const tagCY _copy(data);

 SET_SIMPLE_DBTYPE(DBTYPE_CY,valCY,_copy)
}//SetCY

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetCY(value_i8_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_CY,valCY.int64,data)
}//SetCY

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetNumeric(const value_numeric_type& data)
{
 const value_numeric_type _copy(data);

 SET_SIMPLE_DBTYPE(DBTYPE_NUMERIC,dbnumVal,_copy)
}//SetNumeric

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetDecimal(const value_decimal_type& data)
{
 const value_decimal_type _copy(data);

 SET_SIMPLE_DBTYPE(DBTYPE_DECIMAL,decVal,_copy)
}//SetDecimal

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetGuid(const value_guid_type& value)
{
 const value_guid_type _copy(value);

 SET_SIMPLE_DBTYPE(DBTYPE_GUID,guidVal,_copy)
}//SetGuid

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::SetTimeStamp(const value_dbstamp_type& value)
{
 const value_dbstamp_type _copy(value);

 SET_SIMPLE_DBTYPE(DBTYPE_DBTIMESTAMP,dbstampVal,_copy)
}//SetTimeStamp

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetTimeStamp(SHORT  const Year,
                                                                     USHORT const Month,
                                                                     USHORT const Day)
{
 SET_SIMPLE_DBTYPE_EX(DBTYPE_DBTIMESTAMP,
                      this->dbstampVal.year     =Year;
                      this->dbstampVal.month    =Month;
                      this->dbstampVal.day      =Day;
                      this->dbstampVal.hour     =0;
                      this->dbstampVal.minute   =0;
                      this->dbstampVal.second   =0;
                      this->dbstampVal.fraction =0;)
}//SetTimeStamp

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetTimeStamp(SHORT  const Year,
                                                                     USHORT const Month,
                                                                     USHORT const Day,
                                                                     USHORT const Hour,
                                                                     USHORT const Minute,
                                                                     USHORT const Second,
                                                                     ULONG  const Fraction)
{
 SET_SIMPLE_DBTYPE_EX(DBTYPE_DBTIMESTAMP,
                      this->dbstampVal.year     =Year;
                      this->dbstampVal.month    =Month;
                      this->dbstampVal.day      =Day;
                      this->dbstampVal.hour     =Hour;
                      this->dbstampVal.minute   =Minute;
                      this->dbstampVal.second   =Second;
                      this->dbstampVal.fraction =Fraction;)
}//SetTimeStamp

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetBytes(const void* const data,
                                      size_type   const length)
{
 //проверка источника
 CHECK_READ_PTR(data,length);

#ifndef NDEBUG
 if(this->wType==DBTYPE_BYTES && this->bytesVal.len>0)
 {
  CHECK_READ_PTR(this->bytesVal.ptr,this->bytesVal.len);

  //data может быть частью bytesVal
  if(data>=this->bytesVal.ptr && data<(reinterpret_cast<BYTE*>(this->bytesVal.ptr)+this->bytesVal.len))
   assert((reinterpret_cast<const BYTE*>(data)+length)<=(reinterpret_cast<const BYTE*>(this->bytesVal.ptr)+this->bytesVal.len));
 }//if
#endif

 this->ReserveBytes(length,length,data);

 assert(this->wType==DBTYPE_BYTES);

 assert(this->bytesVal.len==length);

 CHECK_READ_PTR(this->bytesVal.ptr,this->bytesVal.len)

 this->SetDataStatus__OK();

 return *this;
}//SetBytes

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetBytesAsSS(const void* const data,
                                          size_type   const length)
{
 //проверка источника
 CHECK_READ_PTR(data,length);

 typedef basic_dbvariant_sstream<allocator_type> ss_type;

 ole_lib::ISequentialStreamPtr spSS(ss_type::Create(length,data));

 assert(spSS);

 this->SetUnknown(spSS,IID_ISequentialStream);

 return *this;
}//SetBytesAsSS

//------------------------------------------------------------------------------
template<class Allocator>
RELEASE_CODE(inline)
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::AllocBytes(size_type const length)
{
 return this->ReserveBytes(length,0,NULL);
}//AllocBytes

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetStr(const structure::t_const_str_box& data)
{
 const auto _data=data.data();
 const auto _dataLen=data.size();

 //проверка источника
 CHECK_READ_TYPED_PTR(_data,_dataLen);

 if(sm_alloc.max_size(sizeof(*_data))<=_dataLen)
  throw std::bad_alloc();

#ifndef NDEBUG
 if(this->wType==DBTYPE_STR && this->strVal.ptr!=NULL)
 {
  //data может являться подстрокой
  if(_data>=this->strVal.ptr && _data<(this->strVal.ptr+this->strVal.len))
   assert((_data+_dataLen)<=(this->strVal.ptr+this->strVal.len));
 }//if
#endif

 //allocate memory for string (as DBTYPE_BYTES)
 this->ReserveBytes(sizeof(*_data)*(_dataLen+1),sizeof(*_data)*_dataLen,_data);

 assert(this->wType==DBTYPE_BYTES);
 assert(reinterpret_cast<void**>(&this->strVal.ptr)==reinterpret_cast<void**>(&this->bytesVal.ptr));
 assert(this->strVal.ptr!=nullptr);

 this->strVal.ptr[_dataLen]=0;

 //installation of length in symbols
 this->strVal.len =_dataLen;
 this->wType      =DBTYPE_STR;

 this->SetDataStatus__OK();

 return *this;
}//SetStr

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::AllocStr(size_type const _dataLen)
{
 typedef char data_type;

 if(sm_alloc.max_size(sizeof(data_type))<=_dataLen)
  throw std::bad_alloc();

 const size_type cchAlloc=(_dataLen+1);

 //выделяем память под строку (DBTYPE_BYTES)
 this->ReserveBytes(sizeof(data_type)*cchAlloc,0,NULL);

 this->strVal.ptr[_dataLen]=0;

 //installation of length in symbols
 this->strVal.len =_dataLen;
 this->wType      =DBTYPE_STR;

 this->SetDataStatus__OK();

 return *this;
}//AllocStr

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetWStr(const structure::t_const_wstr_box& data)
{
 const auto _data=data.data();
 const auto _dataLen=data.size();

 //проверка источника
 CHECK_READ_TYPED_PTR(_data,_dataLen);

 if(sm_alloc.max_size(sizeof(*_data))<=_dataLen)
  throw std::bad_alloc();

#ifndef NDEBUG
 if(this->wType==DBTYPE_WSTR && this->wstrVal.ptr!=NULL)
 {
  //data может являться подстрокой
  if(_data>=this->wstrVal.ptr && _data<(this->wstrVal.ptr+this->wstrVal.len))
   assert((_data+_dataLen)<=(this->wstrVal.ptr+this->wstrVal.len));
 }//if
#endif

 //allocate memory for string (as DBTYPE_BYTES)
 this->ReserveBytes(sizeof(*_data)*(_dataLen+1),sizeof(*_data)*_dataLen,_data);

 assert(this->wType==DBTYPE_BYTES);
 assert(reinterpret_cast<void**>(&this->wstrVal.ptr)==reinterpret_cast<void**>(&this->bytesVal.ptr));
 assert(this->wstrVal.ptr!=nullptr);

 this->wstrVal.ptr[_dataLen]=0;

 //installation of length in symbols
 this->wstrVal.len =_dataLen;
 this->wType       =DBTYPE_WSTR;

 this->SetDataStatus__OK();

 return *this;
}//SetWStr

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::AllocWStr(size_type const _dataLen)
{
 typedef wchar_t data_type;

 if(sm_alloc.max_size(sizeof(data_type))<=_dataLen)
  throw std::bad_alloc();

 const size_type cchAlloc=(_dataLen+1);

 //выделяем память под строку (DBTYPE_BYTES)
 this->ReserveBytes(sizeof(data_type)*cchAlloc,0,NULL);

 this->strVal.ptr[_dataLen]=0;

 //установка длины в символах
 this->strVal.len =_dataLen;
 this->wType      =DBTYPE_WSTR;

 this->SetDataStatus__OK();

 return *this;
}//AllocWStr

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::TruncWStr(size_type const _dataLen)
{
 assert(this->wType==DBTYPE_WSTR);
 assert(!structure::is_negative_one(_dataLen));

 size_type const curLen=this->wstrVal.ptr?this->wstrVal.len:0;

 CHECK_READ_WRITE_TYPED_PTR(this->wstrVal.ptr,curLen);

 assert_msg(_dataLen<=curLen,
            "[TruncWStr] curLen:"<<curLen<<" _dataLen:"<<_dataLen);

 if(curLen==_dataLen)
  return *this;

 assert_msg(curLen>0,"[TruncWStr] curLen:"<<curLen);

 assert(this->wstrVal.ptr!=NULL);

 CHECK_WRITE_TYPED_PTR(this->wstrVal.ptr,(_dataLen+1))

 this->wstrVal.ptr[_dataLen]=0;

 this->wstrVal.len=_dataLen;

 return *this;
}//TruncWStr

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::TruncStr(size_type const _dataLen)
{
 assert(this->wType==DBTYPE_STR);
 assert(!structure::is_negative_one(_dataLen));

 size_type const curLen=this->strVal.ptr?this->strVal.len:0;

 CHECK_READ_WRITE_TYPED_PTR(this->strVal.ptr,curLen);

 assert_msg(_dataLen<=curLen,
            "[TruncWStr] curLen:"<<curLen<<" _dataLen:"<<_dataLen);

 if(curLen==_dataLen)
  return *this;

 assert_msg(curLen>0,"[TruncStr] curLen:"<<curLen);

 assert(this->strVal.ptr!=NULL);

 CHECK_WRITE_TYPED_PTR(this->strVal.ptr,(_dataLen+1))

 this->strVal.ptr[_dataLen]=0;

 this->strVal.len=_dataLen;

 return *this;
}//TruncStr

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (bool const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_BOOL,boolVal,data?VARIANT_TRUE:VARIANT_FALSE)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_i1_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_I1,valI1,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_ui1_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_UI1,valUI1,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_i2_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_I2,valI2,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_ui2_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_UI2,valUI2,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_i4_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_I4,valI4,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_ui4_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_UI4,valUI4,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_r4_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_R4,valR4,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_r8_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_R8,valR8,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_i8_type_s const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_I8,valI8,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_ui8_type_s const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_UI8,valUI8,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_i8_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_I8,valI8.QuadPart,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_ui8_type const data)
{
 SET_SIMPLE_DBTYPE(DBTYPE_UI8,valUI8.QuadPart,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_long_type const data)
{
 assert(sizeof(data)==sizeof(this->valI4));
 assert(structure::can_numeric_cast(&this->valI4,data));

 SET_SIMPLE_DBTYPE(DBTYPE_I4,valI4,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (value_ulong_type const data)
{
 assert(sizeof(data)==sizeof(this->valUI4));
 assert(structure::can_numeric_cast(&this->valUI4,data));

 SET_SIMPLE_DBTYPE(DBTYPE_UI4,valUI4,data)
}

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetDBDate(const value_dbdate_type& data)
{
 const value_dbdate_type _copy(data);

 SET_SIMPLE_DBTYPE(DBTYPE_DBDATE,dbdateVal,_copy)
}//SetDBDate

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetDBDate(SHORT  const Year,
                                       USHORT const Month,
                                       USHORT const Day)
{
 SET_SIMPLE_DBTYPE_EX(DBTYPE_DBDATE,
                      this->dbdateVal.year  =Year;
                      this->dbdateVal.month =Month;
                      this->dbdateVal.day   =Day;)
}//SetDBDate

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetDBTime(const value_dbtime_type& data)
{
 const value_dbtime_type _copy(data);

 SET_SIMPLE_DBTYPE(DBTYPE_DBTIME,dbtimeVal,_copy)
}//SetDBTime

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetDBTime(USHORT const Hour,
                                       USHORT const Minute,
                                       USHORT const Second)
{
 SET_SIMPLE_DBTYPE_EX(DBTYPE_DBTIME,
                      this->dbtimeVal.hour   =Hour;
                      this->dbtimeVal.minute =Minute;
                      this->dbtimeVal.second =Second;)
}//SetDBTime

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetDBTime2(const value_dbtime2_type& data)
{
 const value_dbtime2_type _copy(data);

 SET_SIMPLE_DBTYPE(oledb_typeid__DBTIME2,dbtime2Val,_copy)
}//SetDBTime2

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetDBTime2(USHORT const Hour,
                                        USHORT const Minute,
                                        USHORT const Second,
                                        ULONG  const Fraction)
{
 SET_SIMPLE_DBTYPE_EX(oledb_typeid__DBTIME2,
                      this->dbtime2Val.hour     =Hour;
                      this->dbtime2Val.minute   =Minute;
                      this->dbtime2Val.second   =Second;
                      this->dbtime2Val.fraction =Fraction;)
}//SetDBTime2

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetFileTime(const value_filetime_type& data)
{
 const FILETIME _copy(data);

 SET_SIMPLE_DBTYPE(DBTYPE_FILETIME,filetimeVal,_copy)
}//SetFileTime

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetUnknown(IUnknown* const pUnk,
                                        REFIID          riid)
{
 ole_lib::IUnknownPtr spLock(pUnk);//блокируем интерфейс

 const IID iid_copy(riid);

 //---------
 this->Clear();

 assert(this->unkVal.ptr==NULL);

 spLock.MoveTo_Fast(&this->unkVal.ptr);

 this->wType=DBTYPE_IUNKNOWN;

 this->unkVal.iid=iid_copy;

 this->SetDataStatus__OK();

 return *this;
}//SetUnknown

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetUnknown(IUnknown* const pUnk)
{
 return this->SetUnknown(pUnk,IID_IUnknown);
}//SetUnknown

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetDispatch(IDispatch* const pDisp)
{
 ole_lib::IDispatchPtr spLock(pDisp);//блокируем интерфейс

 this->Clear();

 assert(this->dispVal.ptr==NULL);

 spLock.MoveTo_Fast(&this->dispVal.ptr);

 this->wType=DBTYPE_IDISPATCH;

 this->SetDataStatus__OK();

 return *this;
}//SetDispatch

////////////////////////////////////////////////////////////////////////////////
#undef SET_SIMPLE_DBTYPE
#undef SET_SIMPLE_DBTYPE_EX

////////////////////////////////////////////////////////////////////////////////
//Assign value_with_null

#define SET_SIMPLE_DBTYPE_N(type,                                  \
                            member_data,                           \
                            is_null,                               \
                            assign_value,                          \
                            reset_value)                           \
 if(this->wType!=DBTYPE_##type)                                    \
 {                                                                 \
  this->Clear();                                                   \
  this->wType=DBTYPE_##type;                                       \
 }                                                                 \
                                                                   \
 if(is_null)                                                       \
 {                                                                 \
  this->member_data=(reset_value);                                 \
  this->SetDataStatus__IsNull();                                   \
 }                                                                 \
 else                                                              \
 {                                                                 \
  this->member_data=(assign_value);                                \
  this->SetDataStatus__OK();                                       \
 }                                                                 \
                                                                   \
 return *this;

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_i1_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(I1,valI1,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_i2_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(I2,valI2,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_i4_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(I4,valI4,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_i8_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(I8,valI8.QuadPart,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (const value_long_n_type& data)
{
 assert(sizeof(data.value_or_default(0))==sizeof(this->valI4));
 assert(structure::can_numeric_cast(&this->valI4,data.value_or_default(0)));

 SET_SIMPLE_DBTYPE_N(I4,valI4,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_ui1_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(UI1,valUI1,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_ui2_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(UI2,valUI2,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_ui4_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(UI4,valUI4,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::operator = (const value_ulong_n_type& data)
{
 assert(sizeof(data.value_or_default(0))==sizeof(this->valUI4));
 assert(structure::can_numeric_cast(&this->valUI4,data.value_or_default(0)));

 SET_SIMPLE_DBTYPE_N(UI4,valUI4,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_ui8_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(UI8,valUI8.QuadPart,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_r4_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(R4,valR4,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_r8_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(R8,valR8,data.null(),data.value(),0)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_cy_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(CY,valCY,data.null(),data.value(),__null_cy__)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_decimal_n_type& data)
{
 if(!data.null())
  return this->SetDecimal(data.value());

 this->SetDecimal(__null_decimal__).SetDataStatus__IsNull();

 return *this;
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_numeric_n_type& data)
{
 if(!data.null())
  return this->SetNumeric(data.value());

 this->SetNumeric(__null_dbnumeric__).SetDataStatus__IsNull();

 return *this;
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_cpp_bool_n_type& data)
{
 SET_SIMPLE_DBTYPE_N(BOOL,
                     boolVal,
                     data.null(),
                     data.value()?VARIANT_TRUE:VARIANT_FALSE,
                     VARIANT_FALSE)
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_dbdate_n_type& x)
{
 if(!x.null())
  return this->SetDBDate(x.value());

 this->SetDBDate(__null_dbdate__).SetDataStatus__IsNull();

 return *this;
}//assign dbdate_n

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_dbtime_n_type& x)
{
 if(!x.null())
  return this->SetDBTime(x.value());

 this->SetDBTime(__null_dbtime__).SetDataStatus__IsNull();

 return *this;
}//assign dbtime_n

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_dbtime2_n_type& x)
{
 if(!x.null())
  return this->SetDBTime2(x.value());

 this->SetDBTime2(__null_dbtime2__).SetDataStatus__IsNull();

 return *this;
}//assign dbtime2_n

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_dbstamp_n_type& x)
{
 if(!x.null())
  return this->SetTimeStamp(x.value());

 this->SetTimeStamp(__null_dbtimestamp__).SetDataStatus__IsNull();

 return *this;
}//assign dbtimestamp_n

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_filetime_n_type& x)
{
 if(!x.null())
  return this->SetFileTime(x.value());

 this->SetFileTime(__null_filetime__).SetDataStatus__IsNull();

 return *this;
}//assign filetime_n

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_guid_n_type& data)
{
 if(!data.null())
  return this->SetGuid(data.value());

 this->SetGuid(GUID_NULL).SetDataStatus__IsNull();

 return *this;
}//assign guid_n

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_unknown_n_type& data)
{
 if(!data.null())
  return this->SetUnknown(data.value());

 this->SetUnknown(NULL).SetDataStatus__IsNull();

 return *this;
}//assign unknown_n

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_dispatch_n_type& data)
{
 if(!data.null())
  return this->SetDispatch(data.value());

 this->SetDispatch(NULL).SetDataStatus__IsNull();

 return *this;
}//assign dispatch_n

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_cpp_str_n_type& x)
{
 if(!x.null())
  return (*this)=x.value();

 return (*this)=DBNull_STR;
}//assign str_n

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (const value_cpp_wstr_n_type& x)
{
 if(!x.null())
  return (*this)=x.value();

 return (*this)=DBNull_WSTR;
}//assign wstr_n

//------------------------------------------------------------------------
template<class Allocator>
template<DBTYPE typeID>
basic_dbvariant<Allocator>&
basic_dbvariant<Allocator>::operator = (basic_dbnull<typeID> UNUSED_ARG(x))
{
 this->Clear();

 //---------------------------
 assert(this->wType==DBTYPE_EMPTY);

 assert(this->bytesVal.ptr==nullptr);
 assert(this->bytesVal.len==0);

 assert(this->wstrVal.ptr==nullptr);
 assert(this->wstrVal.len==0);

 assert(this->strVal.ptr==nullptr);
 assert(this->strVal.len==0);

 assert(this->reserveMemSize==0);

 //---------------------------
 this->wType=typeID;

 this->SetDataStatus__IsNull();

 return *this;
}//assign basic_dbnull<typeID>

//------------------------------------------------------------------------
#undef SET_SIMPLE_DBTYPE_N

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
