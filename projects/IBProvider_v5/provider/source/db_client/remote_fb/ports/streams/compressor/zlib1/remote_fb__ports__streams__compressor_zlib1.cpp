////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__compressor_zlib1
//! \file    remote_fb__ports__streams__compressor_zlib1.h
//! \brief   Реализация потока со сжатием через zlib1.
//! \author  Kovalenko Dmitry
//! \date    06.01.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/streams/compressor/zlib1/remote_fb__ports__streams__compressor_zlib1.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace streams{namespace compressor{namespace zlib1{
////////////////////////////////////////////////////////////////////////////////
//RemoteFB__PortStream__Compressor_ZLib1::tag_zstream_for_deflate

RemoteFB__PortStream__Compressor_ZLib1::tag_zstream_for_deflate::tag_zstream_for_deflate
                                           (ZLIB1__ApiProvider* const pZApiProvider)
 :m_spZApiProvider(structure::not_null_ptr(pZApiProvider))
{
 assert(m_spZApiProvider);

 memset(&this->data,0,sizeof(this->data));

 this->data.zalloc =Helper__ZAlloc__NoThrow;
 this->data.zfree  =Helper__ZFree__NoThrow;
 this->data.opaque =nullptr;

 const int r=m_spZApiProvider->zapi__deflateInit
              (&this->data,
               z_api::Z_DEFAULT_COMPRESSION);

 if(r!=z_api::Z_OK)
 {
  //ERROR - FAILED TO INITIALIZE ZLIB1 DEFLATE STREAM

  RemoteFB__ErrorUtils::Throw__Error
   (Helper__MapZLibErrCodeToHResult(r),
    ibp_subsystem__remote_fb,
    ibp_mce_zlib1__deflate_init_error_1,
    r);
 }//if

 //OK. EXIT.
}//tag_zstream_for_deflate

//------------------------------------------------------------------------
RemoteFB__PortStream__Compressor_ZLib1::tag_zstream_for_deflate::~tag_zstream_for_deflate()
{
 assert(m_spZApiProvider);

 DEBUG_CODE(const auto r=)
  m_spZApiProvider->zapi__deflateEnd(&this->data);

 assert_msg(r==z_api::Z_OK || r==z_api::Z_DATA_ERROR,"r: "<<r);
}//~tag_zstream_for_deflate

//interface --------------------------------------------------------------
int RemoteFB__PortStream__Compressor_ZLib1::tag_zstream_for_deflate::deflate(int const flush)
{
 assert(m_spZApiProvider);

 return m_spZApiProvider->zapi__deflate
         (&this->data,
          flush);
}//deflate

////////////////////////////////////////////////////////////////////////////////
//RemoteFB__PortStream__Compressor_ZLib1::tag_zstream_for_inflate

RemoteFB__PortStream__Compressor_ZLib1::tag_zstream_for_inflate::tag_zstream_for_inflate
                                           (ZLIB1__ApiProvider* const pZApiProvider)
 :m_spZApiProvider(structure::not_null_ptr(pZApiProvider))
{
 assert(m_spZApiProvider);

 memset(&this->data,0,sizeof(this->data));

 this->data.zalloc   =Helper__ZAlloc__NoThrow;
 this->data.zfree    =Helper__ZFree__NoThrow;
 this->data.opaque   =nullptr;
 this->data.next_in  =nullptr;
 this->data.avail_in =0;

 const int r=m_spZApiProvider->zapi__inflateInit
              (&this->data);

 if(r!=z_api::Z_OK)
 {
  //ERROR - FAILED TO INITIALIZE ZLIB1 INFLATE STREAM

  RemoteFB__ErrorUtils::Throw__Error
   (Helper__MapZLibErrCodeToHResult(r),
    ibp_subsystem__remote_fb,
    ibp_mce_zlib1__inflate_init_error_1,
    r);
 }//if

 //OK. EXIT.
}//tag_zstream_for_inflate

//------------------------------------------------------------------------
RemoteFB__PortStream__Compressor_ZLib1::tag_zstream_for_inflate::~tag_zstream_for_inflate()
{
 assert(m_spZApiProvider);

 DEBUG_CODE(const auto r=)
  m_spZApiProvider->zapi__inflateEnd(&this->data);
  
 assert_msg(r==z_api::Z_OK,"r: "<<r);
}//~tag_zstream_for_inflate

//interface --------------------------------------------------------------
int RemoteFB__PortStream__Compressor_ZLib1::tag_zstream_for_inflate::inflate(int const flush)
{
 assert(m_spZApiProvider);

 return m_spZApiProvider->zapi__inflate
         (&this->data,
          flush);
}//inflate

////////////////////////////////////////////////////////////////////////////////
//RemoteFB__PortStream__Compressor_ZLib1

RemoteFB__PortStream__Compressor_ZLib1::RemoteFB__PortStream__Compressor_ZLib1
                                           (ZLIB1__ApiProvider*   const pZApiProvider,
                                            RemoteFB__PortStream* const pParentStream,
                                            z_api::zbuf_size_type const cbOpBuffer,
                                            void*                 const pCommonBuffer)
 :m_spParentStream(structure::not_null_ptr(pParentStream))
 ,m_zstream_for_deflate(pZApiProvider)
 ,m_zstream_for_inflate(pZApiProvider)
#ifndef NDEBUG
 ,m_debug__HasUnflushedData(false)
#endif
 ,m_cbOpBuffer(cbOpBuffer)
 ,m_pCommonBuffer(reinterpret_cast<byte_type*>(pCommonBuffer))
{
 assert(m_spParentStream);

 CHECK_WRITE_TYPED_PTR(m_pCommonBuffer,m_cbOpBuffer);

 m_zstream_for_deflate.data.avail_out =m_cbOpBuffer;
 m_zstream_for_deflate.data.next_out  =this->Helper__GetWriteBuf();
}//RemoteFB__PortStream__Compressor_ZLib1

//------------------------------------------------------------------------
RemoteFB__PortStream__Compressor_ZLib1::~RemoteFB__PortStream__Compressor_ZLib1()
{
}//~RemoteFB__PortStream__Compressor_ZLib1

//------------------------------------------------------------------------
RemoteFB__PortStreamPtr
 RemoteFB__PortStream__Compressor_ZLib1::Create(ZLIB1__ApiProvider*   const pZApiProvider,
                                                RemoteFB__PortStream* const pBaseStream,
                                                size_t                      cbBuffer)
{
 assert(pZApiProvider);
 assert(pBaseStream);
 assert(cbBuffer>0);

 //-----------------------------------------
 if(!structure::can_numeric_cast<z_api::zbuf_size_type>(cbBuffer))
  cbBuffer=structure::t_numeric_limits<z_api::zbuf_size_type>::max_value();

 assert(cbBuffer>0);
 assert(structure::can_numeric_cast<z_api::zbuf_size_type>(cbBuffer));

 //-----------------------------------------
 size_t total_sz=sizeof(self_type);

 //-----------------------------------------
 const size_t offset_common_buf=total_sz;

 if(!structure::append_memory_size(total_sz,cbBuffer))
  throw std::bad_alloc();

 //-----------------------------------------
 if(!structure::append_memory_size(total_sz,cbBuffer))
  throw std::bad_alloc();

 //-----------------------------------------
 void* const pv=raw_allocator_type::instance.allocate(total_sz);

 assert(pv!=nullptr);

 byte_type* const common_buf  =reinterpret_cast<byte_type*>(pv)+offset_common_buf;

 try
 {
  new(pv)self_type
          (pZApiProvider,
           pBaseStream,
           static_cast<z_api::zbuf_size_type>(cbBuffer),
           common_buf); //throw
 }
 catch(...)
 {
  raw_allocator_type::instance.deallocate(pv,total_sz);

  throw;
 }//catch

 assert(pv);

 return structure::not_null_ptr(reinterpret_cast<self_type*>(pv));
}//Create

//port stream interface --------------------------------------------------
RemoteFB__PortStream__Compressor_ZLib1::tag_stream_class
 RemoteFB__PortStream__Compressor_ZLib1::GetStreamClass()const
{
 return stream_class__compressor;
}//GetStreamClass

//------------------------------------------------------------------------
RemoteFB__PortStream__Compressor_ZLib1::RemoteFB__PortStream*
 RemoteFB__PortStream__Compressor_ZLib1::GetParentStream()const
{
 assert(m_spParentStream);

 return m_spParentStream;
}//GetParentStream

//------------------------------------------------------------------------
void RemoteFB__PortStream__Compressor_ZLib1::SetParentStream
                                           (RemoteFB__PortStream* const pParentStream)
{
 assert(pParentStream);

 //здесь ожидается только поток шифровальщика
 assert(pParentStream->GetStreamClass()==RemoteFB__PortStream::stream_class__crypt);

 assert(m_spParentStream);

 //и заменять мы будем транспортный поток
 assert(m_spParentStream->GetStreamClass()==RemoteFB__PortStream::stream_class__transport);

 //у нас не должно быть невыгруженных данных
 assert(m_zstream_for_deflate.data.next_out==this->Helper__GetWriteBuf());
 assert(m_zstream_for_deflate.data.avail_out==m_cbOpBuffer);

 assert(!m_debug__HasUnflushedData);

 //------
 m_spParentStream=structure::not_null_ptr(pParentStream);

 assert(m_spParentStream);
}//SetParentStream

//------------------------------------------------------------------------
size_t RemoteFB__PortStream__Compressor_ZLib1::GetWriteBufSize()const
{
 return m_cbOpBuffer;
}//GetWriteBufSize

//------------------------------------------------------------------------
void RemoteFB__PortStream__Compressor_ZLib1::Write
                                           (size_t      const cb,
                                            const void* const pv)
{
 CHECK_READ_PTR(pv,cb);

 //------------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PortStream__Compressor_ZLib1::Write";

 //------------------------------------------
 auto remain_cb=cb;
 auto remain_pv=pv;

 const auto c_max_block_sz
  =structure::get_numeric_limits(m_zstream_for_deflate.data.avail_in).max_value();

 assert(c_max_block_sz>0);

 for(DEBUG_CODE(size_t debug__nPass1=0);remain_cb!=0;)
 {
  assert(remain_cb>0);

  DEBUG_CODE(++debug__nPass1;)

  DEBUG_CODE(m_debug__HasUnflushedData=true;)

  //------
  if(c_max_block_sz<remain_cb)
   m_zstream_for_deflate.data.avail_in=c_max_block_sz;
  else
   structure::static_numeric_cast(&m_zstream_for_deflate.data.avail_in,remain_cb);

  assert(m_zstream_for_deflate.data.avail_in>0);

  structure::reinterpret_ptr_cast(&m_zstream_for_deflate.data.next_in,remain_pv);

  //------ запоминаем размер текущего блока
  const z_api::zbuf_size_type cur_block_size=m_zstream_for_deflate.data.avail_in;

  //------
  assert_s(sizeof(byte_type)==1);

  assert(cur_block_size<=remain_cb);

  remain_cb-=cur_block_size;

  remain_pv =reinterpret_cast<const byte_type*>(remain_pv)+cur_block_size;

  //------
  for(DEBUG_CODE(size_t debug__nPass2=0);m_zstream_for_deflate.data.avail_in>0;)
  {
   DEBUG_CODE(++debug__nPass2;)

   //-----
   auto const c_startAvailIn  =m_zstream_for_deflate.data.avail_in;
   auto const c_startAvailOut =m_zstream_for_deflate.data.avail_out;

   assert(c_startAvailIn  <=cur_block_size);
   assert(c_startAvailOut <=m_cbOpBuffer);

   //-----
   switch(const int r=m_zstream_for_deflate.deflate(z_api::Z_NO_FLUSH))
   {
    case z_api::Z_OK:
    case z_api::Z_BUF_ERROR:
     break;

    default:
    {
     //ERROR - DEFLATE ERROR
     RemoteFB__ErrorUtils::Throw__Error
      (Helper__MapZLibErrCodeToHResult(r),
       ibp_subsystem__remote_fb,
       ibp_mce_zlib1__deflate_error_2,
       r,
       z_api::Z_NO_FLUSH);
    }//default
   }//switch r

   assert(m_zstream_for_deflate.data.avail_in  <=c_startAvailIn);
   assert(m_zstream_for_deflate.data.avail_out <=c_startAvailOut);

   for(;;)
   {
    //контроль прогресса упаковки

    if(c_startAvailIn<m_zstream_for_deflate.data.avail_in)
    {
     //ERROR - BUG CHECK - problem within zlib1

     RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
      (c_bugcheck_src,
       L"#001",
       L"problem with zlib1. c_startAvailIn: %1. avail_in: %2",
       c_startAvailIn,
       m_zstream_for_deflate.data.avail_in);
    }//if

    assert_hint(m_zstream_for_deflate.data.avail_in<=c_startAvailIn);

    if(c_startAvailOut<m_zstream_for_deflate.data.avail_out)
    {
     //ERROR - BUG CHECK - problem within zlib1

     RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
      (c_bugcheck_src,
       L"#002",
       L"problem with zlib1. c_startAvailOut: %1. avail_out: %2",
       c_startAvailOut,
       m_zstream_for_deflate.data.avail_out);
    }//if

    assert_hint(m_zstream_for_deflate.data.avail_out<=c_startAvailOut);

    if(m_zstream_for_deflate.data.avail_in<c_startAvailIn)
     break; //ok

    if(m_zstream_for_deflate.data.avail_out<c_startAvailOut)
     break; //ok

    if(m_zstream_for_deflate.data.avail_out==0)
     break; //ok. no output space

    //BUG CHECK - detect cycle in zlib1
    RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
     (c_bugcheck_src,
      L"#003",
      L"detect cycle in zlib1");
   }//for[ever]

   const z_api::zbuf_size_type
    cbOut
     =(m_cbOpBuffer-m_zstream_for_deflate.data.avail_out);

   if(cbOut==0)
    continue;

   assert(cbOut>0);

   m_spParentStream->Write(cbOut,this->Helper__GetWriteBuf()); //throw

   //reset output buffer
   m_zstream_for_deflate.data.avail_out =m_cbOpBuffer;
   m_zstream_for_deflate.data.next_out  =this->Helper__GetWriteBuf();
  }//for m_zstream_for_deflate.data.avail_in>0
 }//while
}//Write

//------------------------------------------------------------------------
void RemoteFB__PortStream__Compressor_ZLib1::FlushWriteBuf()
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PortStream__Compressor_ZLib1::FlushWriteBuf";

 //------------------------------------------
 if(m_zstream_for_deflate.data.avail_in>0)
 {
  //ERROR - BUG CHECK - input buffer has data!

  RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#000",
    L"input buffer has data [avail_in: %1]",
    m_zstream_for_deflate.data.avail_in);
 }//if

 assert_hint(m_zstream_for_deflate.data.avail_in==0);

 for(DEBUG_CODE(size_t debug__nPass1=0);;)
 {
  DEBUG_CODE(++debug__nPass1;)

  //-----
  auto const c_startAvailOut=m_zstream_for_deflate.data.avail_out;

  assert(c_startAvailOut<=m_cbOpBuffer);

  //-----
  switch(const int r=m_zstream_for_deflate.deflate(z_api::Z_SYNC_FLUSH))
  {
   case z_api::Z_OK:
   case z_api::Z_BUF_ERROR:
    break;

   default:
   {
    //ERROR - DEFLATE ERROR
     RemoteFB__ErrorUtils::Throw__Error
      (Helper__MapZLibErrCodeToHResult(r),
       ibp_subsystem__remote_fb,
       ibp_mce_zlib1__deflate_error_2,
       r,
       z_api::Z_SYNC_FLUSH);
   }//default
  }//switch r

  assert(m_zstream_for_deflate.data.avail_out <=c_startAvailOut);

  for(;;)
  {
   //контроль прогресса упаковки

   if(0!=m_zstream_for_deflate.data.avail_in)
   {
    //ERROR - BUG CHECK - problem within zlib1

    RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
     (c_bugcheck_src,
      L"#001",
      L"problem with zlib1. avail_in: %1",
      m_zstream_for_deflate.data.avail_in);
   }//if

   assert_hint(m_zstream_for_deflate.data.avail_in==0);

   if(c_startAvailOut<m_zstream_for_deflate.data.avail_out)
   {
    //ERROR - BUG CHECK - problem within zlib1

    RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
     (c_bugcheck_src,
      L"#002",
      L"problem with zlib1. c_startAvailOut: %1. avail_out: %2",
      c_startAvailOut,
      m_zstream_for_deflate.data.avail_out);
   }//if

   assert_hint(m_zstream_for_deflate.data.avail_out<=c_startAvailOut);

   break; //ok
  }//for[ever]

  const z_api::zbuf_size_type
   cbOut
    =(m_cbOpBuffer-m_zstream_for_deflate.data.avail_out);

  if(cbOut==0)
   break; //finish

  assert(cbOut>0);

  m_spParentStream->Write(cbOut,this->Helper__GetWriteBuf()); //throw

  //reset output buffer
  m_zstream_for_deflate.data.avail_out =m_cbOpBuffer;
  m_zstream_for_deflate.data.next_out  =this->Helper__GetWriteBuf();
 }//for[ever]

 DEBUG_CODE(m_debug__HasUnflushedData=false;)

 m_spParentStream->FlushWriteBuf(); //throw
}//FlushWriteBuf

//------------------------------------------------------------------------
size_t RemoteFB__PortStream__Compressor_ZLib1::Read2(size_t const cb,
                                                     void*  const pv)
{
 CHECK_WRITE_PTR(pv,cb);
 assert(cb>0);

 //------------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PortStream__Compressor_ZLib1::Read2";

 //------------------------------------------
 const auto c_max_block_sz
  =structure::get_numeric_limits(m_zstream_for_deflate.data.avail_in).max_value();

 assert(c_max_block_sz>0);

 for(DEBUG_CODE(size_t debug__nPass1=0);;)
 {
  assert(cb>0);

  DEBUG_CODE(++debug__nPass1;)

  assert(m_zstream_for_inflate.data.avail_in<=m_cbOpBuffer);

  if(m_zstream_for_inflate.data.avail_in==0)
  {
   m_zstream_for_inflate.data.next_in=this->Helper__GetReadBuf();
  }
  else
  {
   assert_hint(m_zstream_for_inflate.data.avail_in>0);
   assert_hint(m_zstream_for_inflate.data.avail_in<=m_cbOpBuffer); //again

   if(c_max_block_sz<cb)
    m_zstream_for_inflate.data.avail_out=c_max_block_sz;
   else
    structure::static_numeric_cast(&m_zstream_for_inflate.data.avail_out,cb);

   assert(m_zstream_for_inflate.data.avail_out>0);

   structure::reinterpret_ptr_cast(&m_zstream_for_inflate.data.next_out,pv);

   //------
   const auto c_startAvailIn =m_zstream_for_inflate.data.avail_in;
   const auto c_startAvailOut=m_zstream_for_inflate.data.avail_out;

   //------
   switch(const int r=m_zstream_for_inflate.inflate(z_api::Z_NO_FLUSH))
   {
    case z_api::Z_OK:
     break;

    default:
    {
     //ERROR - INFLATE ERROR!
     RemoteFB__ErrorUtils::Throw__Error
      (Helper__MapZLibErrCodeToHResult(r),
       ibp_subsystem__remote_fb,
       ibp_mce_zlib1__inflate_error_2,
       r,
       z_api::Z_NO_FLUSH);
    }//default
   }//switch r

   for(;;)
   {
    //ловим проблемы внутри zlib1

    if(c_startAvailIn<m_zstream_for_inflate.data.avail_in)
    {
     //ERROR - BUG CHECK - problem within zlib1

     RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
      (c_bugcheck_src,
       L"#001",
       L"problem with zlib1. c_startAvailIn: %1. avail_in: %2",
       c_startAvailIn,
       m_zstream_for_inflate.data.avail_in);
    }//if

    assert_hint(m_zstream_for_inflate.data.avail_in<=c_startAvailIn);

    if(c_startAvailOut<m_zstream_for_inflate.data.avail_out)
    {
     //ERROR - BUG CHECK - problem within zlib1

     RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
      (c_bugcheck_src,
       L"#002",
       L"problem with zlib1. c_startAvailOut: %1. avail_out: %2",
       c_startAvailOut,
       m_zstream_for_inflate.data.avail_out);
    }//if

    assert_hint(m_zstream_for_inflate.data.avail_out<=c_startAvailOut);

    if(m_zstream_for_inflate.data.avail_out<c_startAvailOut)
     break; //ok

    assert(m_zstream_for_inflate.data.avail_out==c_startAvailOut);

    if(m_zstream_for_inflate.data.avail_in==m_cbOpBuffer)
    {
     //ERROR - Хьюстон у нас проблемы. Полный IN-буфер, но прогресса нет.

     RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
      (c_bugcheck_src,
       L"#003",
       L"problem with zlib1. avail_in: %1. m_cbOpBuffer: %2",
       m_zstream_for_inflate.data.avail_in,
       m_cbOpBuffer);
    }//if

    assert_hint(m_zstream_for_inflate.data.avail_in<m_cbOpBuffer);

    break; //ну хорошо. попробуем еще подтащить IN-данных.
   }//for[ever]

   const auto
    cbOut
     =(c_startAvailOut-m_zstream_for_inflate.data.avail_out);

   assert(cbOut<=cb);

   if(cbOut!=0)
   {
    assert(cbOut>0);

    return cbOut;
   }//if

   assert(cbOut==0);

   assert_hint(m_zstream_for_inflate.data.avail_in<m_cbOpBuffer);

   if(this->Helper__GetReadBuf()!=m_zstream_for_inflate.data.next_in)
   {
    memmove(this->Helper__GetReadBuf(),m_zstream_for_inflate.data.next_in,m_zstream_for_inflate.data.avail_in);

    m_zstream_for_inflate.data.next_in=this->Helper__GetReadBuf();
   }//if
  }//else

  assert(m_zstream_for_inflate.data.next_in==this->Helper__GetReadBuf());
  assert(m_zstream_for_inflate.data.avail_in<m_cbOpBuffer);

  const z_api::zbuf_size_type
   cbFreeSpace
    =(m_cbOpBuffer-m_zstream_for_inflate.data.avail_in);

  const auto pFreeSpace
   =this->Helper__GetReadBuf()+m_zstream_for_inflate.data.avail_in;

  auto const cbReaded
   =m_spParentStream->Read2
     (cbFreeSpace,
      pFreeSpace); //throw

  assert(cbReaded>0);
  assert(cbReaded<=cbFreeSpace);

  assert(structure::can_numeric_cast<z_api::zbuf_size_type>(cbReaded));

  m_zstream_for_inflate.data.avail_in+=static_cast<z_api::zbuf_size_type>(cbReaded);
 }//for[ever]
}//Read2

//helper methods ---------------------------------------------------------
HRESULT RemoteFB__PortStream__Compressor_ZLib1::Helper__MapZLibErrCodeToHResult(int const zErr)
{
 assert(zErr!=z_api::Z_OK);

 switch(zErr)
 {
  case z_api::Z_MEM_ERROR:
   return E_OUTOFMEMORY;
 }//switch zErr

 return E_FAIL;
}//Helper__MapZLibErrCodeToHResult

//------------------------------------------------------------------------
z_api::voidpf RemoteFB__PortStream__Compressor_ZLib1::Helper__ZAlloc__NoThrow
                                           (z_api::voidpf const /*opaque*/,
                                            z_api::uInt   const items,
                                            z_api::uInt   const size)
{
 size_t sz=0;

 if(!structure::append_array_memory_size(sz,size,items))
  return nullptr;

 try
 {
  return IBP_MemoryWithDebugChecks::Alloc(sz); //throw
 }
 catch(const std::bad_alloc&)
 {
  return nullptr;
 }
 catch(const std::exception&)
 {
  assert(false);

  return nullptr;
 }
#ifndef NDEBUG
 catch(...)
 {
  assert(false);

  return nullptr;
 }//catch
#endif
}//Helper__ZAlloc__NoThrow

//------------------------------------------------------------------------
void RemoteFB__PortStream__Compressor_ZLib1::Helper__ZFree__NoThrow
                                           (z_api::voidpf const /*opaque*/,
                                            z_api::voidpf const address)
{
#ifndef NDEBUG
 try
#endif
 {
  return IBP_MemoryWithDebugChecks::Free(address);
 }
#ifndef NDEBUG
 catch(...)
 {
  assert(false);
 }//catch
#endif
}//Helper__ZFree__NoThrow

////////////////////////////////////////////////////////////////////////////////
}/*nms zlib1*/}/*nms compressor*/}/*nms streams*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
