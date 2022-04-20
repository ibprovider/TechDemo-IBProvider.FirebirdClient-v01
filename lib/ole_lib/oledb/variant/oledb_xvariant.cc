////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_xvariant_CC_
#define _oledb_xvariant_CC_

#include <structure/t_str_formatter.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class basic_dbvariant

template<class Allocator>
typename basic_dbvariant<Allocator>::raw_allocator_type
 basic_dbvariant<Allocator>::sm_alloc;

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant()
{
 assert(this->wType==DBTYPE_EMPTY);
 assert(this->TestDataStatus__IsOK());
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const self_type& data)
{
 (*this)=data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const DBVARIANT& data)
{
 (*this)=data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const char* const data)
{
 this->SetStr(data);

 assert(this->TestDataStatus__IsOK());
}//basic_dbvariant

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const wchar_t* const data)
{
 this->SetWStr(data);

 assert(this->TestDataStatus__IsOK());
}//basic_dbvariant

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const structure::t_const_wstr_box& data)
{
 this->SetWStr(data);

 assert(this->TestDataStatus__IsOK());
}//basic_dbvariant

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const structure::t_const_str_box& data)
{
 this->SetStr(data);

 assert(this->TestDataStatus__IsOK());
}//basic_dbvariant

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const ole_lib::TBSTR& data)
{
 this->SetBSTR(data.bstr());

 assert(this->TestDataStatus__IsOK());
}//basic_dbvariant

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_numeric_type& data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType    =DBTYPE_NUMERIC;
 this->dbnumVal =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_decimal_type& data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType    =DBTYPE_DECIMAL;
 this->decVal   =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const bool data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_BOOL;
 this->boolVal =(data?VARIANT_TRUE:VARIANT_FALSE);
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_i1_type data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_I1;
 this->valI1   =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_ui1_type data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_UI1;
 this->valUI1  =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_i2_type data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_I2;
 this->valI2   =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_ui2_type data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_UI2;
 this->valUI2  =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_i4_type data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_I4;
 this->valI4   =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_ui4_type  data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_UI4;
 this->valUI4  =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_long_type data)
{
 assert(this->TestDataStatus__IsOK());

 assert(sizeof(data)==sizeof(this->valI4));
 assert(structure::can_numeric_cast(&this->valI4,data));

 this->wType   =DBTYPE_I4;
 this->valI4   =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_ulong_type data)
{
 assert(this->TestDataStatus__IsOK());

 assert(sizeof(data)==sizeof(this->valUI4));
 assert(structure::can_numeric_cast(&this->valUI4,data));

 this->wType   =DBTYPE_UI4;
 this->valUI4  =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_r4_type data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_R4;
 this->valR4   =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_r8_type data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_R8;
 this->valR8   =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_i8_type_s data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_I8;
 this->valI8   =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_ui8_type_s data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_UI8;
 this->valUI8  =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_i8_type data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType          =DBTYPE_I8;
 this->valI8.QuadPart =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_ui8_type data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType          =DBTYPE_UI8;
 this->valUI8.QuadPart=data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_cy_type x)
{
 assert(this->TestDataStatus__IsOK());

 this->wType =DBTYPE_CY;
 this->valCY =x;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_guid_type& x)
{
 assert(this->TestDataStatus__IsOK());

 this->wType   =DBTYPE_GUID;
 this->guidVal =x;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_dbdate_type& data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType     =DBTYPE_DBDATE;
 this->dbdateVal =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_dbtime_type& data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType     =DBTYPE_DBTIME;
 this->dbtimeVal =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_dbtime2_type& data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType      =oledb_typeid__DBTIME2;
 this->dbtime2Val =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_dbstamp_type& data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType      =DBTYPE_DBTIMESTAMP;
 this->dbstampVal =data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const value_filetime_type& data)
{
 assert(this->TestDataStatus__IsOK());

 this->wType      =DBTYPE_FILETIME;
 this->filetimeVal=data;
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(IUnknown* const data,
                                                   REFIID          riid)
{
 this->SetUnknown(data,riid);
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(IUnknown* const data)
{
 this->SetUnknown(data);
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(IDispatch* const data)
{
 this->SetDispatch(data);
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const VARIANT* const data,
                                                   const bool           unpack)
{
 this->SetVariant(data,unpack);
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const VARIANT& data,
                                                   const bool     unpack)
{
 this->SetVariant(&data,unpack);
}

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::basic_dbvariant(const DBTYPE       wElementType,
                                                   LPCSAFEARRAY const lpArray)
{
 this->SetArray(wElementType,lpArray);
}

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_i1_n_type& x)
{
 this->wType=DBTYPE_I1;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->valI1=x.value();
 }//else
}//basic_dbvariant - value_i1_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_i2_n_type& x)
{
 this->wType=DBTYPE_I2;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->valI2=x.value();
 }//else
}//basic_dbvariant - value_i2_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_i4_n_type& x)
{
 this->wType=DBTYPE_I4;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->valI4=x.value();
 }//else
}//basic_dbvariant - value_i4_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_i8_n_type& x)
{
 this->wType=DBTYPE_I8;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->valI8.QuadPart=x.value();
 }//else
}//basic_dbvariant - value_i8_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_ui1_n_type& x)
{
 this->wType=DBTYPE_UI1;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->valUI1=x.value();
 }//else
}//basic_dbvariant - value_ui1_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_ui2_n_type& x)
{
 this->wType=DBTYPE_UI2;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->valUI2=x.value();
 }//else
}//basic_dbvariant - value_ui2_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_ui4_n_type& x)
{
 this->wType=DBTYPE_UI4;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->valUI4=x.value();
 }//else
}//basic_dbvariant - value_ui4_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_ui8_n_type& x)
{
 this->wType=DBTYPE_UI8;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->valUI8.QuadPart=x.value();
 }//else
}//basic_dbvariant - value_ui8_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_r4_n_type& x)
{
 this->wType=DBTYPE_R4;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->valR4=x.value();
 }//else
}//basic_dbvariant - value_r4_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_r8_n_type& x)
{
 this->wType=DBTYPE_R8;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->valR8=x.value();
 }//else
}//basic_dbvariant - value_r8_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_numeric_n_type& x)
{
 this->wType=DBTYPE_NUMERIC;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->dbnumVal=x.value();
 }//else
}//basic_dbvariant - value_numeric_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_decimal_n_type& x)
{
 this->wType=DBTYPE_DECIMAL;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->decVal=x.value();
 }//else
}//basic_dbvariant - value_decimal_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_cpp_bool_n_type& x)
{
 this->wType=DBTYPE_BOOL;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->boolVal=(x.value()?VARIANT_TRUE:VARIANT_FALSE);
 }//else
}//basic_dbvariant - value_cpp_bool_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_guid_n_type& x)
{
 this->wType=DBTYPE_GUID;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->guidVal=x.value();
 }//else
}//basic_dbvariant - value_guid_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_dbdate_n_type& x)
{
 this->wType=DBTYPE_DBDATE;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->dbdateVal=x.value();
 }//else
}//basic_dbvariant - value_dbdate_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_dbtime_n_type& x)
{
 this->wType=DBTYPE_DBTIME;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->dbtimeVal=x.value();
 }//else
}//basic_dbvariant - value_dbtime_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_dbtime2_n_type& x)
{
 this->wType=oledb_typeid__DBTIME2;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->dbtime2Val=x.value();
 }//else
}//basic_dbvariant - value_dbtime2_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_dbstamp_n_type& x)
{
 this->wType=oledb_typeid__DBTIMESTAMP;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->dbstampVal=x.value();
 }//else
}//basic_dbvariant - value_dbstamp_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_filetime_n_type& x)
{
 this->wType=oledb_typeid__FILETIME;

 if(x.null())
 {
  this->SetDataStatus__IsNull();
 }
 else
 {
  assert(this->TestDataStatus__IsOK());

  this->filetimeVal=x.value();
 }//else
}//basic_dbvariant - value_filetime_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_cpp_str_n_type& x)
{
 assert(this->wType==DBTYPE_EMPTY);

 assert(this->reserveMemSize==0);
 assert(this->strVal.len==0);
 assert(!this->strVal.ptr);

 if(x.null())
 {
  this->wType=DBTYPE_STR;

  this->SetDataStatus__IsNull();

  assert(this->TestDataStatus__IsNull());
 }
 else
 {
  assert(!x.null());

  this->SetStr(x.value()); //throw

  assert(this->TestDataStatus__IsOK());
 }//else

 assert(this->wType==DBTYPE_STR);
}//basic_dbvariant - value_cpp_str_n_type

//------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>::basic_dbvariant(const value_cpp_wstr_n_type& x)
{
 assert(this->wType==DBTYPE_EMPTY);

 assert(this->reserveMemSize==0);
 assert(this->wstrVal.len==0);
 assert(!this->wstrVal.ptr);

 if(x.null())
 {
  this->wType=DBTYPE_WSTR;

  this->SetDataStatus__IsNull();

  assert(this->TestDataStatus__IsNull());
 }
 else
 {
  assert(!x.null());

  this->SetWStr(x.value()); //throw

  assert(this->TestDataStatus__IsOK());
 }//else

 assert(this->wType==DBTYPE_WSTR);
}//basic_dbvariant - value_cpp_wstr_n_type

//------------------------------------------------------------------------
template<class Allocator>
template<DBTYPE typeID>
basic_dbvariant<Allocator>::basic_dbvariant(basic_dbnull<typeID> x)
{
 assert(this->TestDataStatus__IsOK());

 assert(this->wType==DBTYPE_EMPTY);

 assert(this->bytesVal.ptr==nullptr);
 assert(this->bytesVal.len==0);

 assert(this->wstrVal.ptr==nullptr);
 assert(this->wstrVal.len==0);

 assert(this->strVal.ptr==nullptr);
 assert(this->strVal.len==0);

 //---------------------------
 this->wType=typeID;

 this->SetDataStatus__IsNull();
}//basic_dbvariant - basic_dbnull<typeID>

//------------------------------------------------------------------------
template<class Allocator>
inline basic_dbvariant<Allocator>::~basic_dbvariant()
{
 this->Clear();
}//~basic_dbvariant

//-------------------------------------------------------------------------
template<class Allocator>
inline void basic_dbvariant<Allocator>::swap(self_type& x)
{
 std::swap(static_cast<DBVARIANT&>(*this),static_cast<DBVARIANT&>(x));
}//swap

//-------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::Clear()
{
 switch(this->wType)
 {
  case DBTYPE_BSTR:
  {
   ole_lib::FreeBStr(this->bstrVal);

   break;
  }//DBTYPE_BSTR

  case DBTYPE_VARIANT:
  {
   _VERIFY_EQ_MSG(ole_lib::Variant_Clear(&this->varVal),S_OK,
                  "varVal.vt=="<<this->varVal.vt);

   break;
  }//DBTYPE_VARIANT

  case DBTYPE_BYTES:
  {
   sm_alloc.deallocate(this->bytesVal.ptr,this->bytesVal.len);

   break;
  }//DBTYPE_BYTES

  case DBTYPE_STR:
  {
   str_allocator_type(sm_alloc).deallocate(this->strVal.ptr,0);

   break;
  }//DBTYPE_STR

  case DBTYPE_WSTR:
  {
   wstr_allocator_type(sm_alloc).deallocate(this->wstrVal.ptr,0);

   break;
  }//DBTYPE_WSTR

  case DBTYPE_IUNKNOWN:
  {
   ole_lib::ReleaseComInterface(this->unkVal.ptr);

   break;
  }//DBTYPE_IUNKNOWN

  case DBTYPE_IDISPATCH:
  {
   ole_lib::ReleaseComInterface(this->dispVal.ptr);

   break;
  }//DBTYPE_IDISPATCH

  default:
  {
   if(this->wType&DBTYPE_ARRAY && this->arrayVal2.ptr!=NULL)
   {
    _VERIFY_EQ(ole_lib::SafeArray_Destroy(this->arrayVal2.ptr),S_OK);
   }

   break;
  }//default
 }//switch

 this->Init();

 return *this;
}//Clear

//-------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>& basic_dbvariant<Allocator>::SetDefault_STD()
{
 this->Clear();

 assert(this->wType==DBTYPE_EMPTY);

 this->SetDataStatus__Default();

 return *this;
}//SetDefault_STD

//------------------------------------------------------------------------
//функци€ резервировани€ пам€ти.
//≈сли объект содержит динамические данные (отличные от VARIANT/BSTR) и
//выделенной под них пам€ти больше чем затребовано, то ни чего не измен€етс€
//
//Ёто гарантирует возможность присваивани€ поддиапазона
//
//в противном случае производитьс€ очистка и выделение пам€ти как DBTYPE_BYTES

template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::ReserveBytes(size_type   const cbReserve,
                                          size_type   const cbBytes,
                                          const void* const pvBytes)
{
 CHECK_READ_PTR(pvBytes,cbBytes);

 assert(cbBytes<=cbReserve);

 size_type cAllocatedBytes(0);
 void*     pAllocatedBytes(NULL);

 bool      can_reuse=true;

 switch(this->wType)
 {
  case DBTYPE_BYTES:
  {
   if((pAllocatedBytes=this->bytesVal.ptr)!=NULL)
    cAllocatedBytes=this->bytesVal.len;

   break;
  }//DBTYPE_BYTES

  case DBTYPE_STR:
  {
   if((pAllocatedBytes=this->strVal.ptr)!=NULL)
    cAllocatedBytes=sizeof(*this->strVal.ptr)*(this->strVal.len+1);

   break;
  }//DBTYPE_STR

  case DBTYPE_WSTR:
  {
   if((pAllocatedBytes=this->wstrVal.ptr)!=NULL)
    cAllocatedBytes=sizeof(*this->wstrVal.ptr)*(this->wstrVal.len+1);

   break;
  }//DBTYPE_WSTR

  default:
  {
   can_reuse=false;

   break;
  }//default
 }//switch

 if(can_reuse)
 {
  assert(this->reserveMemSize==0 || cAllocatedBytes<=this->reserveMemSize);

  if(cAllocatedBytes<this->reserveMemSize)
   cAllocatedBytes=this->reserveMemSize;
 }//if can_reuse

 if(can_reuse && cbReserve<=cAllocatedBytes)
 {
  assert(cbBytes<=cAllocatedBytes);

  CHECK_WRITE_PTR(pAllocatedBytes,cbBytes);

  memcpy(pAllocatedBytes,pvBytes,cbBytes);
 }
 else
 {
  //alloc new memory block

  //New rules of memory allocations
  //1. allocate new memory block
  //2. copy data to new memory block
  //3. clear current dbvariant value
  //4. assign new dbvariant value

  /*0*/
  cAllocatedBytes=cbReserve;

  /*ignore operation result*/
  structure::align_memory_size(cAllocatedBytes,OLEDB_MEM_SIZE_ALIGN);

  assert(cbReserve<=cAllocatedBytes);

  /*1*/
  if(cAllocatedBytes==0)
  {
   pAllocatedBytes=NULL;
  }
  else
  if((pAllocatedBytes=this->sm_alloc.allocate(cAllocatedBytes))==NULL)
  {
   throw std::bad_alloc();
  }

  /*2*/
  assert(cbBytes<=cAllocatedBytes);

  CHECK_WRITE_PTR(pAllocatedBytes,cbBytes);

  memcpy(pAllocatedBytes,pvBytes,cbBytes);

  /*3*/
  this->Clear();
 }//else

 this->wType           =DBTYPE_BYTES;
 this->bytesVal.len    =cbReserve;
 this->reserveMemSize  =cAllocatedBytes;
 this->bytesVal.ptr    =pAllocatedBytes;

 //провер€ем указатель на зарезервированную пам€ть
 CHECK_WRITE_PTR(this->bytesVal.ptr,this->bytesVal.len);

 return *this;
}//ReserveBytes

//Helper methods ---------------------------------------------------------
template<class Allocator>
void basic_dbvariant<Allocator>::helper__throw_bug_check__bad_data_status
                                           (const char* const place,
                                            const char* const point,
                                            DBSTATUS    const status)
{
 assert(place);
 assert(point);

 structure::str_formatter
  fmsg("[BUG CHECK] Bad dbvalue status [%3]. Check point [%1][%2].");

 fmsg<<place
     <<point
     <<status;

 assert_msg(false,fmsg.str());

 throw std::runtime_error(fmsg.str());
}//helper__throw_bug_check__bad_data_status

////////////////////////////////////////////////////////////////////////////////
//template class basic_dbvariant_converter

template<class DBVariant>
HRESULT basic_dbvariant_converter<DBVariant>::convert
                                           (const DBVARIANT*& dest,
                                            const DBVARIANT&  source,
                                            DBTYPE    const   wType)
{
 if(source.wType==wType)
 {
  dest=&source;

  return S_OK;
 }//if

 dest=&m_tmp;

 return m_tmp.assign_as
         (source,
          wType);
}//convert

//------------------------------------------------------------------------
template<class DBVariant>
inline HRESULT basic_dbvariant_converter<DBVariant>::convert
                                           (const DBVARIANT& source,
                                            DBTYPE     const wType)
{
 return this->convert
         (m_pResult,
          source,
          wType);
}//convert

//------------------------------------------------------------------------
template<class DBVariant>
HRESULT basic_dbvariant_converter<DBVariant>::convert_ex
                                           (LPCCONVCONTEXT const pConvCtx,
                                            const DBVARIANT*&    dest,
                                            const DBVARIANT&     source,
                                            DBTYPE         const wType)
{
 if(source.wType==wType)
 {
  dest=&source;

  return S_OK;
 }//if

 dest=&m_tmp;

 return m_tmp.assign_as_ex
         (pConvCtx,
          source,
          wType);
}//convert_ex

//------------------------------------------------------------------------
template<class DBVariant>
inline HRESULT basic_dbvariant_converter<DBVariant>::convert_ex
                                           (LPCCONVCONTEXT const pConvCtx,
                                            const DBVARIANT&     source,
                                            DBTYPE         const wType)
{
 return this->convert_ex
         (pConvCtx,
          m_pResult,
          source,
          wType);
}//convert_ex

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
