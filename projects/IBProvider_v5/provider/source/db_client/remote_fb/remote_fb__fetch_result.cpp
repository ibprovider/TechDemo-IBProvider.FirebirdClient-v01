////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__fetch_result.cpp
//! \brief   The class for handling a fetch operation result.
//! \author  Kovalenko Dmitry
//! \date    30.03.2023.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__fetch_result.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__FetchResult

const GUID RemoteFB__FetchResult::svcID
 ={0xFCF27338,0x5EF6,0x4808,{0x97,0xE2,0x2C,0x7E,0x58,0x46,0x0E,0x5C}};

//------------------------------------------------------------------------
RemoteFB__FetchResult::size_type
 RemoteFB__FetchResult::Helper__CalcRowBlock(size_type cbRowData,size_type cbAlign)
{
 if(!structure::align_memory_size(cbRowData,cbAlign))
  throw std::bad_alloc();

 return cbRowData;
}//Helper__CalcRowBlock

//------------------------------------------------------------------------
RemoteFB__FetchResult::RemoteFB__FetchResult
                             (msg_blr_buffer_type&&  OutMSG_BLR,
                              msg_data_descrs_type&& OutMSG_DATA_DESCRS,
                              size_type        const RequestedFetchCount,
                              size_type        const cbRowData,
                              size_type        const cbRowDataAlign)
 :m_OutMSG_BLR(std::move(OutMSG_BLR))
 ,m_OutMSG_DATA_DESCRS(std::move(OutMSG_DATA_DESCRS))
 ,m_RequestedFetchCount(RequestedFetchCount)
 ,m_ProcessedFetchCount(0)
 ,m_State(state__active)
 ,m_FetchErr(S_OK)
 ,m_cbRowData(cbRowData)
 ,m_cbRowBlock(Helper__CalcRowBlock(cbRowData,cbRowDataAlign))
 ,m_RowsDataBufferManager(0,RequestedFetchCount)
{
 assert(m_RequestedFetchCount>0);

 assert(m_cbRowData>0); // [2023-03-30] Research
 assert(m_cbRowData<=m_cbRowBlock);

 //--------------
 if(m_cbRowBlock>0)
 {
  const size_t c_max_mem=structure::t_numeric_limits<size_t>::max_value();

  const size_t maxN=c_max_mem/m_cbRowBlock;

  if(maxN<RequestedFetchCount)
   throw std::bad_alloc();

  m_RowsDataBuffer.alloc(m_cbRowBlock*RequestedFetchCount);
 }//if
}//RemoteFB__FetchResult

//------------------------------------------------------------------------
RemoteFB__FetchResult::~RemoteFB__FetchResult()
{
}

//------------------------------------------------------------------------
RemoteFB__FetchResult::self_ptr
 RemoteFB__FetchResult::Create(msg_blr_buffer_type&&  OutMSG_BLR,
                               msg_data_descrs_type&& OutMSG_DATA_DESCRS,
                               size_type        const RequestedFetchCount,
                               size_type        const cbRowData,
                               size_type        const cbRowDataAlign)
{
 return structure::not_null_ptr
         (new self_type
           (std::move(OutMSG_BLR),
            std::move(OutMSG_DATA_DESCRS),
            RequestedFetchCount,
            cbRowData,
            cbRowDataAlign));
}//Create

//interface --------------------------------------------------------------
RemoteFB__FetchResult::size_type
 RemoteFB__FetchResult::ROWS__GetCount()const
{
 return m_RowsDataBufferManager.size();
}//ROWS__GetCount

//------------------------------------------------------------------------
RemoteFB__FetchResult::size_type
 RemoteFB__FetchResult::ROWS__GetDataSize()const
{
 return m_cbRowData;
}//ROWS__GetDataSize

//------------------------------------------------------------------------
RemoteFB__FetchResult::byte_type*
 RemoteFB__FetchResult::ROWS__AllocBlock()
{
 assert(!m_RowsDataBufferManager.full());

 m_RowsDataBufferManager.push_back();

 assert(m_RowsDataBufferManager.back()<m_RequestedFetchCount);

 byte_type* const p=m_RowsDataBuffer.ptr_at(m_RowsDataBufferManager.back()*m_cbRowBlock);

 assert(m_RowsDataBuffer.buffer()<=p);
 assert(p<m_RowsDataBuffer.buffer_end());
 assert(m_cbRowBlock<=size_t(m_RowsDataBuffer.buffer_end()-p));

 memset(p,0,m_cbRowBlock);

 return p;
}//ROWS__AllocBlock

//------------------------------------------------------------------------
const RemoteFB__FetchResult::byte_type*
 RemoteFB__FetchResult::ROWS__GetFirstBlock()const
{
 assert(!m_RowsDataBufferManager.empty());

 assert(m_RowsDataBufferManager.front()<m_RequestedFetchCount);

 const byte_type* const p=m_RowsDataBuffer.ptr_at(m_RowsDataBufferManager.front()*m_cbRowBlock);

 assert(m_RowsDataBuffer.buffer()<=p);
 assert(p<m_RowsDataBuffer.buffer_end());
 assert(m_cbRowBlock<=size_t(m_RowsDataBuffer.buffer_end()-p));

 return p;
}//ROWS__GetFirstBlock

//------------------------------------------------------------------------
void RemoteFB__FetchResult::ROWS__FreeFirstBlock()
{
 assert(!m_RowsDataBufferManager.empty());

 m_RowsDataBufferManager.pop_front();
}//ROWS__FreeFirstBlock

//------------------------------------------------------------------------
void RemoteFB__FetchResult::ROWS__FreeLastBlock()
{
 assert(!m_RowsDataBufferManager.empty());

 m_RowsDataBufferManager.pop_back();
}//ROWS__FreeLastBlock

//------------------------------------------------------------------------
void RemoteFB__FetchResult::Reactivate()
{
 m_State=state__active;

 m_ProcessedFetchCount=0;
}//Reactivate

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
