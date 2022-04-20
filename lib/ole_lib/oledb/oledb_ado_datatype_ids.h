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

 adVarChar           = 200     ,
 adLongVarChar       = 201     ,
 adVarWChar          = 202     ,
 adLongVarWChar      = 203     ,
 adVarBinary         = 204     ,
 adLongVarBinary     = 205     ,
 adArray             = 0x2000  ,
};//enum AdoDataTypeEnum

////////////////////////////////////////////////////////////////////////////////

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

const AdoDataTypeEnum adodb_typeid__adVarChar           = adVarChar;          //200
const AdoDataTypeEnum adodb_typeid__adLongVarChar       = adLongVarChar;      //201
const AdoDataTypeEnum adodb_typeid__adVarWChar          = adVarWChar;         //202
const AdoDataTypeEnum adodb_typeid__adLongVarWChar      = adLongVarWChar;     //203
const AdoDataTypeEnum adodb_typeid__adVarBinary         = adVarBinary;        //204
const AdoDataTypeEnum adodb_typeid__adLongVarBinary     = adLongVarBinary;    //205
const AdoDataTypeEnum adodb_typeid__adArray             = adArray;            //0x2000

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
