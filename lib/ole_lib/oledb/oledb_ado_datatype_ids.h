////////////////////////////////////////////////////////////////////////////////
//ADODB Data Type IDs
//                                                 Kovalenko Dmitry. 11.09.2010
#ifndef _oledb_ado_datatype_ids_H_
#define _oledb_ado_datatype_ids_H_

#include <structure/t_common.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//enum AdoDataTypeEnum

enum AdoDataTypeEnum
{
 adEmpty             = 0       ,
 adSmallInt          = 2       ,
 adInteger           = 3       ,
 adSingle            = 4       ,
 adDouble            = 5       ,
 adCurrency          = 6       ,
 adDate              = 7       ,
 adBSTR              = 8       ,
 adIDispatch         = 9       ,
 adError             = 10      ,
 adBoolean           = 11      ,
 adVariant           = 12      ,
 adIUnknown          = 13      ,
 adDecimal           = 14      ,
 adTinyInt           = 16      ,
 adUnsignedTinyInt   = 17      ,
 adUnsignedSmallInt  = 18      ,
 adUnsignedInt       = 19      ,
 adBigInt            = 20      ,
 adUnsignedBigInt    = 21      ,
 adFileTime          = 64      ,
 adGUID              = 72      ,
 adBinary            = 128     ,
 adChar              = 129     ,
 adWChar             = 130     ,
 adNumeric           = 131     ,
 adUserDefined       = 132     ,
 adDBDate            = 133     ,
 adDBTime            = 134     ,
 adDBTimeStamp       = 135     ,
 adChapter           = 136     ,
 adPropVariant       = 138     ,
 adVarNumeric        = 139     ,

 adDBTime2           = 145     ,
 adDBTimeStampOffset = 146     ,

 adVarChar           = 200     ,
 adLongVarChar       = 201     ,
 adVarWChar          = 202     ,
 adLongVarWChar      = 203     ,
 adVarBinary         = 204     ,
 adLongVarBinary     = 205     ,
 adArray             = 0x2000  ,
};//enum AdoDataTypeEnum

////////////////////////////////////////////////////////////////////////////////

#if 0 // [2023-08-05] Bye

const AdoDataTypeEnum adodb_typeid__adEmpty             = adEmpty;            //0
const AdoDataTypeEnum adodb_typeid__adSmallInt          = adSmallInt;         //2
const AdoDataTypeEnum adodb_typeid__adInteger           = adInteger;          //3
const AdoDataTypeEnum adodb_typeid__adSingle            = adSingle;           //4
const AdoDataTypeEnum adodb_typeid__adDouble            = adDouble;           //5
const AdoDataTypeEnum adodb_typeid__adCurrency          = adCurrency;         //6
const AdoDataTypeEnum adodb_typeid__adDate              = adDate;             //7
const AdoDataTypeEnum adodb_typeid__adBSTR              = adBSTR;             //8
const AdoDataTypeEnum adodb_typeid__adIDispatch         = adIDispatch;        //9
const AdoDataTypeEnum adodb_typeid__adError             = adError;            //10
const AdoDataTypeEnum adodb_typeid__adBoolean           = adBoolean;          //11
const AdoDataTypeEnum adodb_typeid__adVariant           = adVariant;          //12
const AdoDataTypeEnum adodb_typeid__adIUnknown          = adIUnknown;         //13
const AdoDataTypeEnum adodb_typeid__adDecimal           = adDecimal;          //14
const AdoDataTypeEnum adodb_typeid__adTinyInt           = adTinyInt;          //16
const AdoDataTypeEnum adodb_typeid__adUnsignedTinyInt   = adUnsignedTinyInt;  //17
const AdoDataTypeEnum adodb_typeid__adUnsignedSmallInt  = adUnsignedSmallInt; //18
const AdoDataTypeEnum adodb_typeid__adUnsignedInt       = adUnsignedInt;      //19
const AdoDataTypeEnum adodb_typeid__adBigInt            = adBigInt;           //20
const AdoDataTypeEnum adodb_typeid__adUnsignedBigInt    = adUnsignedBigInt;   //21
const AdoDataTypeEnum adodb_typeid__adFileTime          = adFileTime;         //64
const AdoDataTypeEnum adodb_typeid__adGUID              = adGUID;             //72
const AdoDataTypeEnum adodb_typeid__adBinary            = adBinary;           //128
const AdoDataTypeEnum adodb_typeid__adChar              = adChar;             //129
const AdoDataTypeEnum adodb_typeid__adWChar             = adWChar;            //130
const AdoDataTypeEnum adodb_typeid__adNumeric           = adNumeric;          //131
const AdoDataTypeEnum adodb_typeid__adUserDefined       = adUserDefined;      //132
const AdoDataTypeEnum adodb_typeid__adDBDate            = adDBDate;           //133
const AdoDataTypeEnum adodb_typeid__adDBTime            = adDBTime;           //134
const AdoDataTypeEnum adodb_typeid__adDBTimeStamp       = adDBTimeStamp;      //135
const AdoDataTypeEnum adodb_typeid__adChapter           = adChapter;          //136
const AdoDataTypeEnum adodb_typeid__adPropVariant       = adPropVariant;      //138
const AdoDataTypeEnum adodb_typeid__adVarNumeric        = adVarNumeric;       //139

const AdoDataTypeEnum adodb_typeid__adDBTime2           = adDBTime2;          //145
const AdoDataTypeEnum adodb_typeid__adDBTimeStampOffset = adDBTimeStampOffset;//146

const AdoDataTypeEnum adodb_typeid__adVarChar           = adVarChar;          //200
const AdoDataTypeEnum adodb_typeid__adLongVarChar       = adLongVarChar;      //201
const AdoDataTypeEnum adodb_typeid__adVarWChar          = adVarWChar;         //202
const AdoDataTypeEnum adodb_typeid__adLongVarWChar      = adLongVarWChar;     //203
const AdoDataTypeEnum adodb_typeid__adVarBinary         = adVarBinary;        //204
const AdoDataTypeEnum adodb_typeid__adLongVarBinary     = adLongVarBinary;    //205
const AdoDataTypeEnum adodb_typeid__adArray             = adArray;            //0x2000

#endif

////////////////////////////////////////////////////////////////////////////////

const AdoDataTypeEnum adodb_typeid__Empty             = adEmpty;            //0
const AdoDataTypeEnum adodb_typeid__SmallInt          = adSmallInt;         //2
const AdoDataTypeEnum adodb_typeid__Integer           = adInteger;          //3
const AdoDataTypeEnum adodb_typeid__Single            = adSingle;           //4
const AdoDataTypeEnum adodb_typeid__Double            = adDouble;           //5
const AdoDataTypeEnum adodb_typeid__Currency          = adCurrency;         //6
const AdoDataTypeEnum adodb_typeid__Date              = adDate;             //7
const AdoDataTypeEnum adodb_typeid__BSTR              = adBSTR;             //8
const AdoDataTypeEnum adodb_typeid__IDispatch         = adIDispatch;        //9
const AdoDataTypeEnum adodb_typeid__Error             = adError;            //10
const AdoDataTypeEnum adodb_typeid__Boolean           = adBoolean;          //11
const AdoDataTypeEnum adodb_typeid__Variant           = adVariant;          //12
const AdoDataTypeEnum adodb_typeid__IUnknown          = adIUnknown;         //13
const AdoDataTypeEnum adodb_typeid__Decimal           = adDecimal;          //14
const AdoDataTypeEnum adodb_typeid__TinyInt           = adTinyInt;          //16
const AdoDataTypeEnum adodb_typeid__UnsignedTinyInt   = adUnsignedTinyInt;  //17
const AdoDataTypeEnum adodb_typeid__UnsignedSmallInt  = adUnsignedSmallInt; //18
const AdoDataTypeEnum adodb_typeid__UnsignedInt       = adUnsignedInt;      //19
const AdoDataTypeEnum adodb_typeid__BigInt            = adBigInt;           //20
const AdoDataTypeEnum adodb_typeid__UnsignedBigInt    = adUnsignedBigInt;   //21
const AdoDataTypeEnum adodb_typeid__FileTime          = adFileTime;         //64
const AdoDataTypeEnum adodb_typeid__GUID              = adGUID;             //72
const AdoDataTypeEnum adodb_typeid__Binary            = adBinary;           //128
const AdoDataTypeEnum adodb_typeid__Char              = adChar;             //129
const AdoDataTypeEnum adodb_typeid__WChar             = adWChar;            //130
const AdoDataTypeEnum adodb_typeid__Numeric           = adNumeric;          //131
const AdoDataTypeEnum adodb_typeid__UserDefined       = adUserDefined;      //132
const AdoDataTypeEnum adodb_typeid__DBDate            = adDBDate;           //133
const AdoDataTypeEnum adodb_typeid__DBTime            = adDBTime;           //134
const AdoDataTypeEnum adodb_typeid__DBTimeStamp       = adDBTimeStamp;      //135
const AdoDataTypeEnum adodb_typeid__Chapter           = adChapter;          //136
const AdoDataTypeEnum adodb_typeid__PropVariant       = adPropVariant;      //138
const AdoDataTypeEnum adodb_typeid__VarNumeric        = adVarNumeric;       //139

const AdoDataTypeEnum adodb_typeid__DBTime2           = adDBTime2;          //145
const AdoDataTypeEnum adodb_typeid__DBTimeStampOffset = adDBTimeStampOffset;//146

const AdoDataTypeEnum adodb_typeid__VarChar           = adVarChar;          //200
const AdoDataTypeEnum adodb_typeid__LongVarChar       = adLongVarChar;      //201
const AdoDataTypeEnum adodb_typeid__VarWChar          = adVarWChar;         //202
const AdoDataTypeEnum adodb_typeid__LongVarWChar      = adLongVarWChar;     //203
const AdoDataTypeEnum adodb_typeid__VarBinary         = adVarBinary;        //204
const AdoDataTypeEnum adodb_typeid__LongVarBinary     = adLongVarBinary;    //205
const AdoDataTypeEnum adodb_typeid__Array             = adArray;            //0x2000

////////////////////////////////////////////////////////////////////////////////

const AdoDataTypeEnum adodb_typeid__Array_Empty             = AdoDataTypeEnum(adArray|adEmpty);
const AdoDataTypeEnum adodb_typeid__Array_SmallInt          = AdoDataTypeEnum(adArray|adSmallInt);
const AdoDataTypeEnum adodb_typeid__Array_Integer           = AdoDataTypeEnum(adArray|adInteger);
const AdoDataTypeEnum adodb_typeid__Array_Single            = AdoDataTypeEnum(adArray|adSingle);
const AdoDataTypeEnum adodb_typeid__Array_Double            = AdoDataTypeEnum(adArray|adDouble);
const AdoDataTypeEnum adodb_typeid__Array_Currency          = AdoDataTypeEnum(adArray|adCurrency);
const AdoDataTypeEnum adodb_typeid__Array_Date              = AdoDataTypeEnum(adArray|adDate);
const AdoDataTypeEnum adodb_typeid__Array_BSTR              = AdoDataTypeEnum(adArray|adBSTR);
const AdoDataTypeEnum adodb_typeid__Array_IDispatch         = AdoDataTypeEnum(adArray|adIDispatch);
const AdoDataTypeEnum adodb_typeid__Array_Error             = AdoDataTypeEnum(adArray|adError);
const AdoDataTypeEnum adodb_typeid__Array_Boolean           = AdoDataTypeEnum(adArray|adBoolean);
const AdoDataTypeEnum adodb_typeid__Array_Variant           = AdoDataTypeEnum(adArray|adVariant);
const AdoDataTypeEnum adodb_typeid__Array_IUnknown          = AdoDataTypeEnum(adArray|adIUnknown);
const AdoDataTypeEnum adodb_typeid__Array_Decimal           = AdoDataTypeEnum(adArray|adDecimal);
const AdoDataTypeEnum adodb_typeid__Array_TinyInt           = AdoDataTypeEnum(adArray|adTinyInt);
const AdoDataTypeEnum adodb_typeid__Array_UnsignedTinyInt   = AdoDataTypeEnum(adArray|adUnsignedTinyInt);
const AdoDataTypeEnum adodb_typeid__Array_UnsignedSmallInt  = AdoDataTypeEnum(adArray|adUnsignedSmallInt);
const AdoDataTypeEnum adodb_typeid__Array_UnsignedInt       = AdoDataTypeEnum(adArray|adUnsignedInt);
const AdoDataTypeEnum adodb_typeid__Array_BigInt            = AdoDataTypeEnum(adArray|adBigInt);
const AdoDataTypeEnum adodb_typeid__Array_UnsignedBigInt    = AdoDataTypeEnum(adArray|adUnsignedBigInt);
const AdoDataTypeEnum adodb_typeid__Array_FileTime          = AdoDataTypeEnum(adArray|adFileTime);
const AdoDataTypeEnum adodb_typeid__Array_GUID              = AdoDataTypeEnum(adArray|adGUID);
const AdoDataTypeEnum adodb_typeid__Array_Binary            = AdoDataTypeEnum(adArray|adBinary);
const AdoDataTypeEnum adodb_typeid__Array_Char              = AdoDataTypeEnum(adArray|adChar);
const AdoDataTypeEnum adodb_typeid__Array_WChar             = AdoDataTypeEnum(adArray|adWChar);
const AdoDataTypeEnum adodb_typeid__Array_Numeric           = AdoDataTypeEnum(adArray|adNumeric);
const AdoDataTypeEnum adodb_typeid__Array_UserDefined       = AdoDataTypeEnum(adArray|adUserDefined);
const AdoDataTypeEnum adodb_typeid__Array_DBDate            = AdoDataTypeEnum(adArray|adDBDate);
const AdoDataTypeEnum adodb_typeid__Array_DBTime            = AdoDataTypeEnum(adArray|adDBTime);
const AdoDataTypeEnum adodb_typeid__Array_DBTimeStamp       = AdoDataTypeEnum(adArray|adDBTimeStamp);
const AdoDataTypeEnum adodb_typeid__Array_Chapter           = AdoDataTypeEnum(adArray|adChapter);
const AdoDataTypeEnum adodb_typeid__Array_PropVariant       = AdoDataTypeEnum(adArray|adPropVariant);
const AdoDataTypeEnum adodb_typeid__Array_VarNumeric        = AdoDataTypeEnum(adArray|adVarNumeric);

const AdoDataTypeEnum adodb_typeid__Array_DBTime2           = AdoDataTypeEnum(adArray|adDBTime2);
const AdoDataTypeEnum adodb_typeid__Array_DBTimeStampOffset = AdoDataTypeEnum(adArray|adDBTimeStampOffset);

const AdoDataTypeEnum adodb_typeid__Array_VarChar           = AdoDataTypeEnum(adArray|adVarChar);
const AdoDataTypeEnum adodb_typeid__Array_LongVarChar       = AdoDataTypeEnum(adArray|adLongVarChar);
const AdoDataTypeEnum adodb_typeid__Array_VarWChar          = AdoDataTypeEnum(adArray|adVarWChar);
const AdoDataTypeEnum adodb_typeid__Array_LongVarWChar      = AdoDataTypeEnum(adArray|adLongVarWChar);
const AdoDataTypeEnum adodb_typeid__Array_VarBinary         = AdoDataTypeEnum(adArray|adVarBinary);
const AdoDataTypeEnum adodb_typeid__Array_LongVarBinary     = AdoDataTypeEnum(adArray|adLongVarBinary);

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
