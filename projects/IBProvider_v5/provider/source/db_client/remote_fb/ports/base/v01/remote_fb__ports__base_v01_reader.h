////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01_reader.h
//! \brief   Реализация интерфейса читателя из стандартного порта.
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#ifndef _remote_fb__ports__base_v01_reader_H_
#define _remote_fb__ports__base_v01_reader_H_

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__ports__base_v01
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01::tag_reader

/// <summary>
///  Реализация интерфейса читателя из стандартного порта.
/// </summary>
class RemoteFB__Port_BASE_v01::tag_reader
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__PortReader)
{
 private:
  typedef tag_reader                        self_type;

  tag_reader(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  Конструктор инициализации.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  tag_reader(RemoteFB__Port_BASE_v01* pPort);

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~tag_reader();

  //reader interface -----------------------------------------------------

 #ifndef NDEBUG
  virtual protocol::P_ARCH debug__get_protocol_architecture()const COMP_W000004_OVERRIDE_FINAL;
 #endif

  /// <summary>
  ///  Уведомление о начале операции чтения.
  /// </summary>
  virtual void begin_read() COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Уведомление об окончании операции чтения.
  /// </summary>
  //! \param[in] success
  //!  true, если операция завершается без ошибок
  virtual void end_read(bool success) COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Чтение данных с типом P_LONG.
  /// </summary>
  //! \param[out] pv
  virtual void read__long(protocol::P_LONG* pv) COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Чтение массива байт.
  /// </summary>
  //! \param[in]  n
  //! \param[out] pb
  virtual void read__bytes(size_type          n,
                           protocol::P_UCHAR* pb) COMP_W000004_OVERRIDE_FINAL;

 private:
  /// <summary>
  ///  Чтение указанного количества байт.
  /// </summary>
  //! \param[in]  cb
  //! \param[out] pv
  void helper__read(size_type cb,
                    void*     pv)const;

  /// <summary>
  ///  Генерация исключения "чтение невозможно, потому что произошли критические ошибки."
  /// </summary>
  COMP_CONF_DECLSPEC_NORETURN
  void helper__throw_error__port_has_failed_state()const;

 private:
  /// Указатель на обслуживаемый порт подключения. Not null.
  RemoteFB__Port_BASE_v01::self_ptr const m_spPort;
};//class RemoteFB__Port_BASE_v01::tag_reader

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#endif
