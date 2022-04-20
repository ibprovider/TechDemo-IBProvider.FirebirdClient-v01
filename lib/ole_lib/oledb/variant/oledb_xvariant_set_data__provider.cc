////////////////////////////////////////////////////////////////////////////////
//Implementation of basic_dbvariant::SetData__Provider
//                                                 Dmitry Kovalenko. 03.03.2018.
#ifndef _oledb_xvariant_set_data__provider_CC_
#define _oledb_xvariant_set_data__provider_CC_

#include <iomanip>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class basic_dbvariant

// ��������� ������ �� �������� �� ����� ������������ (��� ���������� � �����)
// �� ����������� ��������, ��� ������� �� �������� Release()
//
// IsProvider == true, ���� ��� ��������� ������������� ������,
// � ���� ������ Status ����� ���� S_OK,S_ISNULL,S_DEFAULT

template<class Allocator>
HRESULT basic_dbvariant<Allocator>::SetData__Provider
                                           (const DBBINDING& Binding,
                                            void*      const pData)
{
 if(pData==NULL)
  return E_INVALIDARG;

 status_type  LocalStatus=DBSTATUS_S_OK;

 status_type& Binding_Status=OLEDB_STATUS_IS_BOUND(Binding)
                             ?OLEDB_BINDING_STATUS(Binding,pData)
                             :LocalStatus;

 //���� is_null ���������� ����� � ��������
 const DBTYPE SourceType=OLEDB_EXTRACT_DBTYPE(Binding.wType);

 //-----------------------------------------------------------------------
 if(Binding_Status==DBSTATUS_S_ISNULL)
 {
  this->Clear();

  this->dwDataStatus=Binding_Status;

  if(SourceType==DBTYPE_VARIANT)
   this->wType=DBTYPE_NULL; //unpack as in set_data_VARIANT
  else
   this->wType=SourceType;

  return NOERROR;
 }//if S_ISNULL

 assert(Binding_Status!=DBSTATUS_S_ISNULL);

 //-----------------------------------------------------------------------
 if(Binding_Status==DBSTATUS_S_DEFAULT)
 {
  this->Clear();

  this->dwDataStatus=Binding_Status;

  return NOERROR;
 }//if S_DEFAULT

 assert(Binding_Status!=DBSTATUS_S_DEFAULT);

 //----------------------------------------
 if(Binding_Status==DBSTATUS_S_OK && OLEDB_VALUE_IS_BOUND(Binding))
 {
  /*ok*/
 }
 else
 {
  ODS_LEVEL_3("ERR: dbvariant::SetData "
              "[iOrd="<<Binding.iOrdinal<<", "
               "dwPart="<<Binding.dwPart<<", "
               "BadStatus:"<<Binding_Status<<"]");

  Binding_Status=DBSTATUS_E_BADSTATUS;

  return DB_E_ERRORSOCCURRED;
 }//else

 /*status is ok*/
 assert(Binding_Status==DBSTATUS_S_OK);

 assert(OLEDB_VALUE_IS_BOUND(Binding));

 status_type ResultStatus=DBSTATUS_S_OK;

 {
  //��� �� ��������� ������ ���������� ����� �������� ��������� � cbMaxLen
  //� ������ ����������� ����� (��� ����������� 0)
  //��������� ������ ������ ������������ �������:
  // ��� � ������������ ������, ��� � ������ ����������

  length_type Length=OLEDB_LENGTH_IS_BOUND(Binding)?OLEDB_BINDING_LENGTH(Binding,pData):0;

  LPCTYPEINFO const pInfo=self_type::GetInfo(SourceType);

  if(pInfo==NULL) //����������� ��� ������
  {
   ODS_LEVEL_3("ERR: dbvariant::SetData [iOrd="<<Binding.iOrdinal<<","
                                        "Unk type:0x"<<std::hex<<SourceType<<"]");
   ResultStatus=DBSTATUS_E_BADACCESSOR;
  }
  else
  if(Binding.wType&DBTYPE_BYREF)//��������� ������
  {
   if(pInfo->FixedLen() && pInfo->Size!=Length)
   {
    ODS_LEVEL_3("ERR: dbvariant::SetData [iOrd="<<Binding.iOrdinal<<","
                                         "type:0x"<<std::hex<<SourceType<<","
                                         "bad length:"<<Length<<"]");

    //������������ ����� ������ ������������� �����
    ResultStatus=DBSTATUS_E_BADACCESSOR;
   }
  }
  else //������ ������
  {
   if(pInfo->FixedLen())
   {
    //������ � ������������� ������ �� ����������� � ����� ������
    if(pInfo->Size>Binding.cbMaxLen)
    {
     ODS_LEVEL_3("ERR: dbvariant::SetData [iOrd="<<Binding.iOrdinal<<","
                                          "type:0x"<<std::hex<<SourceType<<","
                                          "bad cbMaxLen:"<<Binding.cbMaxLen<<"]");
     ResultStatus=DBSTATUS_E_BADACCESSOR;
    }

    //���� ��������� ����� ����� ����� ������
    //ADODB, ��������, ��� ������������� ����� �������� � Length ������ ������
    //      � ���������, ��� DBTYPE_BSTR - Length==8
    Length=pInfo->Size;
   }//FixedLen
   else
   {
    //VariableLen - Length - ��� �������� �����, ������� ����� ���� ������ Binding.cbMaxLen

    //���� ��� ��������� �������� ������, �� ������ ������ ������ ���� ������ OK
    assert(Binding_Status==DBSTATUS_S_OK);

    //! \todo
    //!  ������������ BUG-CHECK ������, ���� Binding.cbMaxLen<Length

    if(Length>Binding.cbMaxLen) //����� ��������� ������ ������
    {
     //������ ����� ��������
     Length=Binding.cbMaxLen;
    }
   }//else var_len+isprovider

   //���������, ��� ������ ���������� � ������
   assert(Length<=Binding.cbMaxLen);
  }//else - !DBTYPE_BYREF

  //�������� ����������� ����� ������ - Length

  if(ResultStatus==DBSTATUS_S_OK)
  {
   assert(pData);

   void* pValue=&OLEDB_BINDING_VALUE(Binding,pData);

   assert(pValue);

   if((Binding.wType&DBTYPE_BYREF))
   {
    CHECK_READ_PTR(pValue,sizeof(void*));

    pValue=*reinterpret_cast<void* const*>(pValue); //�������� ��������� �� ������

    //! \todo
    //!  Check Length==0 || pValue!=NULL
   }//if BYREF

   CHECK_READ_PTR(pValue,Length);

   //���������� ������� ��������� ������ ---------------------------------
   typename self_type::set_data_func_type set_data_func=NULL;

   if(size_t(SourceType)<_DIM_(self_type::sm_set_data_funcs))
   {
    //in debug version each element has own ID (wType)
    assert(SourceType==self_type::sm_set_data_funcs[SourceType].wType);
    set_data_func=self_type::sm_set_data_funcs[SourceType].func;
   }
   else
   if(SourceType&DBTYPE_ARRAY)
   {
    set_data_func=self_type::set_data_ARRAY;
   }

   if(set_data_func==NULL)
    set_data_func=self_type::set_data_BADACCESSOR; //return DBSTATUS_E_BADACCESSOR

   assert(set_data_func!=NULL);

   ResultStatus=set_data_func(*this,
                              Binding,
                              Length,
                              pValue,
                              self_type::setdata_isprovider);
  }//if ResultStatus==DBSTATUS_S_OK

  assert(ResultStatus!=DBSTATUS_S_ISNULL);
  assert(ResultStatus!=DBSTATUS_S_IGNORE);
  assert(ResultStatus!=DBSTATUS_S_DEFAULT);
  assert(ResultStatus!=DBSTATUS_S_TRUNCATED);

  if(ResultStatus==DBSTATUS_S_OK)
  {
   this->SetDataStatus(Binding_Status);
  }
  else
  {
   this->Clear();

   this->SetDataStatus(ResultStatus);
  }
 }//else - ��������� ������

 assert(ResultStatus!=DBSTATUS_S_ISNULL);
 assert(ResultStatus!=DBSTATUS_S_IGNORE);
 assert(ResultStatus!=DBSTATUS_S_DEFAULT);
 assert(ResultStatus!=DBSTATUS_S_TRUNCATED);

 //-----------------------------------------
 if(ResultStatus!=DBSTATUS_S_OK)
  Binding_Status=ResultStatus;

 //-----------------------------------------
 if(ResultStatus==DBSTATUS_S_OK)
  return NOERROR;

 ODS_LEVEL_3("ERR: dbvariant::SetData "
            "[iOrd="<<Binding.iOrdinal<<", "
             "ResultStatus="<<ResultStatus<<"]");

 return DB_E_ERRORSOCCURRED;
}//SetData__Provider

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
