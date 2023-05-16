////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__read.h
//! \brief   Чтение данных блоба.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#ifndef _remote_fb__api_p13__blob__read_H_
#define _remote_fb__api_p13__blob__read_H_

#include "source/db_client/remote_fb/api/remote_fb__api__blob__read.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ReadBlob

/// <summary>
///  Чтение данных блоба.
/// </summary>
class RemoteFB__API_P13__ReadBlob LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__ReadBlob)
{
 private:
  typedef RemoteFB__API_P13__ReadBlob       self_type;

  RemoteFB__API_P13__ReadBlob(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef blob_handle_type::item_type       blob_data_type;

 private:
  RemoteFB__API_P13__ReadBlob();

  virtual ~RemoteFB__API_P13__ReadBlob();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  Чтение данных блоба.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pBlobHandle
  //!  Not null. На входе должен указывать на дескриптор открытого блоба.
  //! \param[in] cbBuffer
  //!  Размер буфера
  //! \param[out] pvBuffer
  //!  Указатель на приемник
  //! \param[out] pcbActualReaded
  //!  Количество записанных байт в буфер. Not null.
  //! \return
  //!  - false, если был достигут конец блоба.
  //!
  //! \note
  //!  При достижении конца буфера с данными мы можем вернуть данные.
  virtual bool exec(RemoteFB__ConnectorData* pData,
                    blob_handle_type*        pBlobHandle,
                    size_t                   cbBuffer,
                    void*                    pvBuffer,
                    size_t*                  pcbActualReaded)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  class tagOpMemoryBuffer;

 private:
  /// <summary>
  ///  Загрузка данных в буфер дескриптора блоба.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pBlobData
  //!  Not null.
  static void helper__read_to_buffer(RemoteFB__ConnectorData* pData,
                                     blob_data_type*          pBlobData);
};//class RemoteFB__API_P13__ReadBlob

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
