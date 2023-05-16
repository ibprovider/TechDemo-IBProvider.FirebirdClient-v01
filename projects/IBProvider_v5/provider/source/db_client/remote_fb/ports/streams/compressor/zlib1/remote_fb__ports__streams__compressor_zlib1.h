////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__compressor_zlib1
//! \file    remote_fb__ports__streams__compressor_zlib1.h
//! \brief   Реализация потока со сжатием через zlib1.
//! \author  Kovalenko Dmitry
//! \date    06.01.2019
#ifndef _remote_fb__ports__streams__compressor_zlib1_H_
#define _remote_fb__ports__streams__compressor_zlib1_H_

#include "source/db_client/remote_fb/ports/remote_fb__port_stream.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

#include "source/external/zlib1/ibp_external__zlib1__api_provider.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace streams{namespace compressor{namespace zlib1{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__compressor_zlib1
//! @{
////////////////////////////////////////////////////////////////////////////////

namespace z_api
 =ibp::external::zlib1::api;

using ZLIB1__ApiProvider
 =ibp::external::zlib1::ZLIB1__ApiProvider;

using ZLIB1__ApiProviderPtr
 =ibp::external::zlib1::ZLIB1__ApiProviderPtr;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortStream__Compressor_ZLib1

/// <summary>
///  Реализация потока со сжатием через zlib1. NO THREAD-SAFE.
/// </summary>
class RemoteFB__PortStream__Compressor_ZLib1 LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__PortStream)
{
 private:
  typedef RemoteFB__PortStream__Compressor_ZLib1  self_type;

  RemoteFB__PortStream__Compressor_ZLib1(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private: //typedefs -----------------------------------------------------
  typedef unsigned char                           byte_type;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pZApiProvider
  //!  Not null.
  //! \param[in] pParentStream
  //!  Not null.
  //! \param[in] cbOpBuffer
  //! \param[in] pCommonBuffer
  RemoteFB__PortStream__Compressor_ZLib1(ZLIB1__ApiProvider*   pZApiProvider,
                                         RemoteFB__PortStream* pParentStream,
                                         z_api::zbuf_size_type cbOpBuffer,
                                         void*                 pCommonBuffer);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~RemoteFB__PortStream__Compressor_ZLib1();

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  //! \param[in] pZApiProvider
  //!  Not null.
  //! \param[in] pParentStream
  //!  Not null
  //! \param[in] cbBuffer
  //!  Размер write-буфера. Ненулевое значение.
  static RemoteFB__PortStreamPtr Create(ZLIB1__ApiProvider*   pZApiProvider,
                                        RemoteFB__PortStream* pParentStream,
                                        size_t                cbBuffer);

  //port stream interface ------------------------------------------------

  /// <summary>
  ///  Получение идентификатора категории потока
  /// </summary>
  virtual tag_stream_class GetStreamClass()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Получение указателя на родительский поток.
  /// </summary>
  //! \return
  //!  Can be null.
  virtual RemoteFB__PortStream* GetParentStream()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Замена родительского потока.
  /// </summary>
  //! \param[in] pParentStream
  //!  Not null.
  virtual void SetParentStream(RemoteFB__PortStream* pParentStream) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Получение размера буфера для записи.
  /// </summary>
  virtual size_t GetWriteBufSize()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Буферизированная запись данных в порт. THROW.
  /// </summary>
  //! \param[in] cb
  //!  Количество байт
  //! \param[in] pv
  //!  Указатель на буфер с отправляемыми данными
  virtual void Write(size_t      cb,
                     const void* pv)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Сброс write-буфера
  /// </summary>
  virtual void FlushWriteBuf()LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Буферизированное чтение данных из порта. THROW
  /// </summary>
  //! \param[in]  cb
  //!  Размер буфера под данные. Значение должно быть больше нуля.
  //! \param[out] pv
  //!  Указатель на буфер. Not null.
  //! \return
  //!  Количество загруженных данных. Больше нуля, но не больше чем cb.
  virtual size_t Read2(size_t  cb,
                       void*   pv)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef RemoteFB__MemoryAllocator         raw_allocator_type;

  static void* operator new (size_t const sz); //not impl

  static void* operator new (size_t,void* const pv)
  {
   return pv;
  }

 public:
  static void operator delete (void* pv)
  {
   return raw_allocator_type::instance.deallocate(pv,0);
  }

 #if(COMP_CONF_SUPPORT_OPERATOR_DELETE_EX)
  static void operator delete(void* /*pv*/,void* /*pv2*/)
  {
   //memory will be deallocated in catch of self_type::create
  }
 #endif

 private:
  byte_type* Helper__GetReadBuf()const
  {
   return m_pCommonBuffer;
  }//Helper__GetReadBuf

  byte_type* Helper__GetWriteBuf()const
  {
   return m_pCommonBuffer+m_cbOpBuffer;
  }//Helper__GetWriteBuf

 private:
  static HRESULT Helper__MapZLibErrCodeToHResult(int zErr);

 private:
  static z_api::voidpf Helper__ZAlloc__NoThrow
                         (z_api::voidpf opaque,
                          z_api::uInt   items,
                          z_api::uInt   size);

  static void Helper__ZFree__NoThrow
                         (z_api::voidpf opaque,
                          z_api::voidpf address);

 private:
  class tag_zstream_for_deflate LCPI_CPP_CFG__CLASS__FINAL
  {
   private:
    typedef tag_zstream_for_deflate         self_type;

    tag_zstream_for_deflate(const self_type&)=delete;
    self_type& operator = (const self_type&)=delete;

   public:
    z_api::z_stream data;

    explicit tag_zstream_for_deflate(ZLIB1__ApiProvider* pZApiProvider);

   ~tag_zstream_for_deflate();

    int deflate(int flush);

   private:
    ZLIB1__ApiProviderPtr const m_spZApiProvider;
  };//class tag_zstream_for_deflate

 private:
  class tag_zstream_for_inflate LCPI_CPP_CFG__CLASS__FINAL
  {
   private:
    typedef tag_zstream_for_inflate         self_type;

    tag_zstream_for_inflate(const self_type&)=delete;
    self_type& operator = (const self_type&)=delete;

   public:
    z_api::z_stream data;

    explicit tag_zstream_for_inflate(ZLIB1__ApiProvider* pZApiProvider);

   ~tag_zstream_for_inflate();

    int inflate(int flush);

   private:
    ZLIB1__ApiProviderPtr const m_spZApiProvider;
  };//class tag_zstream_for_inflate

 private:
  /// Нижележащий поток ввода-вывода данных.
  RemoteFB__PortStreamPtr m_spParentStream;

  /// Управляющая структура для упаковки
  tag_zstream_for_deflate m_zstream_for_deflate;

  /// Управляющая структура для распаковки
  tag_zstream_for_inflate m_zstream_for_inflate;

#ifndef NDEBUG
  /// Отладочный флаг наличия несброшенных данных в m_zstream_for_deflate
  bool m_debug__HasUnflushedData;
#endif

 private:
  /// Размер буфера для чтения/записи
  z_api::zbuf_size_type const m_cbOpBuffer;

  /// Указатель на блок с буферами для чтения/записи
  byte_type* const m_pCommonBuffer;
};//class RemoteFB__PortStream

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms zlib1*/}/*nms compressor*/}/*nms streams*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
