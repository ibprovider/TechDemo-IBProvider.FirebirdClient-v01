////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_var_cvt_utils_CC_
#define _oledb_var_cvt_utils_CC_

#include <ole_lib/oledb/oledb_seq_stream_traits.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT_CVT_UTILS

template<typename TPlainOldData>
HRESULT DBVARIANT_CVT_UTILS::StorageObjectToSimpleType_v2
                         (ISequentialStream*                           const pSS,
                          structure::t_value_with_null<TPlainOldData>* const result)
{
 assert(pSS);
 assert(result);

 //TODO: we can add the code for verification of TPlainOldData - is it really POD?

 TPlainOldData tmp;

 assert(sizeof(tmp)==sizeof(result->value()));

 const HRESULT hr(self_type::StorageObjectToSimpleType_v2(pSS,
                                                          &tmp,
                                                          sizeof(tmp)));
 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 (*result)=tmp;
 
 return S_OK;
}//StorageObjectToSimpleType_v2

//------------------------------------------------------------------------
template<class TComSeqStream,class T>
HRESULT DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2
          (TComSeqStream*              const pSourceStream,
           DBVARIANT_STREAM_WRITER<T>* const pDestStream)
{
 assert(pSourceStream);
 assert(pDestStream);

 //-----------------------------------------
 typedef t_oledb_seq_stream_traits<TComSeqStream>::block_size_type block_size_type;

 typedef DBVARIANT_STREAM_WRITER__ITEM_TYPE_SELECTOR<T>::result_type item_type;

 item_type buffer[(4*1024)/sizeof(item_type)];

 for(;;)
 {
  block_size_type cReaded=0;

  const HRESULT read_hr=pSourceStream->Read(buffer,_DIM_(buffer),&cReaded);

  if(FAILED(read_hr))
   return read_hr;

  //paranoia
  //if(read_hr!=S_OK && read_hr!=S_FALSE)
  // return E_UNEXPECTED;

  if(cReaded>_DIM_(buffer))
   return E_UNEXPECTED; //after such must be :crash:

  if(cReaded==0)
   break;

  pDestStream->write(buffer,cReaded);

  if(read_hr==S_FALSE)
   break;
 }//for[ever]

 return S_OK;
}//StorageObjectToBuffer_v2

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToNumeric(signed char const value,
                                                 DB_NUMERIC* const dbnum,
                                                 int         const scale)
{
 return self_type::Int64ToNumeric(value,dbnum,oledb_i1_precision,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToNumeric(signed short const value,
                                                 DB_NUMERIC*  const dbnum,
                                                 int          const scale)
{
 return self_type::Int64ToNumeric(value,dbnum,oledb_i2_precision,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToNumeric(signed long const value,
                                                 DB_NUMERIC* const dbnum,
                                                 int         const scale)
{
 return self_type::Int64ToNumeric(value,dbnum,oledb_i4_precision,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToNumeric(signed int  const value,
                                                 DB_NUMERIC* const dbnum,
                                                 int         const scale)
{
 return self_type::Int64ToNumeric(value,dbnum,oledb_i4_precision,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToNumeric(signed __int64 const value,
                                                 DB_NUMERIC*    const dbnum,
                                                 int            const scale)
{
 return self_type::Int64ToNumeric(value,dbnum,oledb_i8_precision,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToNumeric(unsigned char const value,
                                                 DB_NUMERIC*   const dbnum,
                                                 int           const scale)
{
 return self_type::UInt64ToNumeric(value,dbnum,oledb_ui1_precision,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToNumeric(unsigned short const value,
                                                 DB_NUMERIC*    const dbnum,
                                                 int            const scale)
{
 return self_type::UInt64ToNumeric(value,dbnum,oledb_ui2_precision,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToNumeric(unsigned long const value,
                                                 DB_NUMERIC*   const dbnum,
                                                 int           const scale)
{
 return self_type::UInt64ToNumeric(value,dbnum,oledb_ui4_precision,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToNumeric(unsigned int const value,
                                                 DB_NUMERIC*  const dbnum,
                                                 int          const scale)
{
 return self_type::UInt64ToNumeric(value,dbnum,oledb_ui4_precision,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToNumeric(unsigned __int64 const value,
                                                 DB_NUMERIC*      const dbnum,
                                                 int              const scale)
{
 return self_type::UInt64ToNumeric(value,dbnum,oledb_ui8_precision,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::CYToNumeric(const tagCY&       value,
                                                DB_NUMERIC*  const dbnum)
{
 return self_type::Int64ToNumeric(value.int64,
                                  dbnum,
                                  oledb_cy_precision,
                                  -oledb_cy_fraction_part_scale);
}//CYToNumeric - tagCY

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::CYToNumeric(signed __int64 const value,
                                                DB_NUMERIC*    const dbnum)
{
 return self_type::Int64ToNumeric(value,
                                  dbnum,
                                  oledb_cy_precision,
                                  -oledb_cy_fraction_part_scale);
}//CYToNumeric - signed __int64

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::NumericToCY(const DB_NUMERIC& dbnum,
                                                tagCY*      const pValue)
{
 assert(pValue);

 return self_type::NumericToCY(dbnum,&pValue->int64);
}//NumericToCY

////////////////////////////////////////////////////////////////////////////////

inline HRESULT DBVARIANT_CVT_UTILS::IntToDecimal(signed char const value,
                                                 tagDEC*     const decimal,
                                                 int         const scale)
{
 return self_type::Int64ToDecimal(value,decimal,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToDecimal(signed short const value,
                                                 tagDEC*      const decimal,
                                                 int                scale)
{
 return self_type::Int64ToDecimal(value,decimal,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToDecimal(signed long const value,
                                                 tagDEC*     const decimal,
                                                 int         const scale)
{
 return self_type::Int64ToDecimal(value,decimal,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToDecimal(signed int const value,
                                                 tagDEC*    const decimal,
                                                 int        const scale)
{
 return self_type::Int64ToDecimal(value,decimal,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToDecimal(signed __int64 const value,
                                                 tagDEC*        const decimal,
                                                 int            const scale)
{
 return self_type::Int64ToDecimal(value,decimal,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToDecimal(unsigned char const value,
                                                 tagDEC*       const decimal,
                                                 int           const scale)
{
 return self_type::UInt64ToDecimal(value,decimal,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToDecimal(unsigned short const value,
                                                 tagDEC*        const decimal,
                                                 int                  scale)
{
 return self_type::UInt64ToDecimal(value,decimal,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToDecimal(unsigned long const value,
                                                 tagDEC*       const decimal,
                                                 int           const scale)
{
 return self_type::UInt64ToDecimal(value,decimal,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToDecimal(unsigned int const value,
                                                 tagDEC*      const decimal,
                                                 int          const scale)
{
 return self_type::UInt64ToDecimal(value,decimal,scale);
}

//-------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToDecimal(unsigned __int64 const value,
                                                 tagDEC*          const decimal,
                                                 int              const scale)
{
 return self_type::UInt64ToDecimal(value,decimal,scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::CYToDecimal(const tagCY&  value,
                                                tagDEC* const decimal)
{
 return self_type::Int64ToDecimal(value.int64,decimal,-oledb_cy_fraction_part_scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::CYToDecimal(signed __int64 const value,
                                                tagDEC*        const decimal)
{
 return self_type::Int64ToDecimal(value,decimal,-oledb_cy_fraction_part_scale);
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::DecimalToCY(const tagDEC& decimal,
                                                tagCY*  const pValue)
{
 assert(pValue);

 return self_type::DecimalToCY(decimal,&pValue->int64);
}//DecimalToCY

////////////////////////////////////////////////////////////////////////////////

inline HRESULT DBVARIANT_CVT_UTILS::IntToCY(signed char const value,tagCY& cy)
{
 (cy.int64=value)*=oledb_cy_fraction_part_mult;
 return S_OK;
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToCY(signed short const value,tagCY& cy)
{
 (cy.int64=value)*=oledb_cy_fraction_part_mult;
 return S_OK;
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToCY(signed long const value,tagCY& cy)
{
 (cy.int64=value)*=oledb_cy_fraction_part_mult;
 return S_OK;
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToCY(signed int const value,tagCY& cy)
{
 (cy.int64=value)*=oledb_cy_fraction_part_mult;
 return S_OK;
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToCY(unsigned char const value,tagCY& cy)
{
 (cy.int64=value)*=oledb_cy_fraction_part_mult;
 return S_OK;
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToCY(unsigned short const value,tagCY& cy)
{
 (cy.int64=value)*=oledb_cy_fraction_part_mult;
 return S_OK;
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToCY(unsigned long const value,tagCY& cy)
{
 (cy.int64=value)*=oledb_cy_fraction_part_mult;
 return S_OK;
}

//------------------------------------------------------------------------
inline HRESULT DBVARIANT_CVT_UTILS::IntToCY(unsigned int const value,tagCY& cy)
{
 (cy.int64=value)*=oledb_cy_fraction_part_mult;
 return S_OK;
}

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
