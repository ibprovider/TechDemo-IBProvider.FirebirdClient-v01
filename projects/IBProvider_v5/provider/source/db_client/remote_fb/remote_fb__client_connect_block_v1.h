////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__client_connect_block_v1.h
//! \brief   Класс для управления данными подключения.
//! \author  Kovalenko Dmitry
//! \date    11.07.2016
#ifndef _remote_fb__client_connect_block_v1_H_
#define _remote_fb__client_connect_block_v1_H_

#include "source/oledb/props2/values/datasource/ibp_oledb__props2__values__datasource.h"

#include <structure/t_value_with_null.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ClientConnectBlock_v1

/// <summary>
///  Класс для управления данными подключения
/// </summary>
class RemoteFB__ClientConnectBlock_v1 LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__ClientConnectBlock_v1;

  RemoteFB__ClientConnectBlock_v1(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  /// <summary>
  ///  Описание ожидаемого типа протокола подключения.
  /// </summary>
  struct tag_expected_ptype_descr LCPI_CPP_CFG__CLASS__FINAL
  {
   //! \note
   //!  Конструктор и оператор копирования генерируются компилятором.

   public:
    using ptype_id_type=unsigned;

    using ptype_id_type_N=structure::t_value_with_null<ptype_id_type>;

   public:
    /// Идентификатор ожидаемого типа (может быть не определен).
    ptype_id_type_N  ptypeID;

    /// Сигнатура ожидаемого типа
    std::wstring     ptypeSign;

   public:
    tag_expected_ptype_descr();

    tag_expected_ptype_descr
     (ptype_id_type                    _ptypeID,
      lib::structure::t_const_wstr_box _ptypeSign);

    explicit tag_expected_ptype_descr(structure::t_const_wstr_box _ptypeSign);

   ~tag_expected_ptype_descr();

    bool operator == (ptype_id_type id)const;

    bool operator != (ptype_id_type id)const;
  };//struct tag_expected_ptype_descr

  using expected_ptype_descr_type
   =tag_expected_ptype_descr;

  using expected_ptype_descr_type_N
   =structure::t_value_with_null<expected_ptype_descr_type>;

 public:
  const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE::self_ptr m_spDsPropValues;

 public:
  /// Описание ожидаемого типа протокола соединения
  expected_ptype_descr_type_N m_expectedPTypeDescr;

 public:
  enum tag_auth_kind
  {
   auth_kind__none=0,

   auth_kind__legacy=1,

   auth_kind__sspi=2,
  };

  /// Идентификатор типа аутентификации
  tag_auth_kind m_AuthKind;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pDsPropValues
  //!  Not null
  explicit RemoteFB__ClientConnectBlock_v1(oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

  /// <summary>
  ///  Десктруктор
  /// </summary>
 ~RemoteFB__ClientConnectBlock_v1();
};//class RemoteFB__ClientConnectBlock_v1

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
