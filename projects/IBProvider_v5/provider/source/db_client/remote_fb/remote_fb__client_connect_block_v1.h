////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__client_connect_block_v1.h
//! \brief   ����� ��� ���������� ������� �����������.
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
///  ����� ��� ���������� ������� �����������
/// </summary>
class RemoteFB__ClientConnectBlock_v1
{
 private:
  typedef RemoteFB__ClientConnectBlock_v1      self_type;

  RemoteFB__ClientConnectBlock_v1(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  /// <summary>
  ///  �������� ���������� ���� ��������� �����������.
  /// </summary>
  struct tag_expected_ptype_descr
  {
   //! \note
   //!  ����������� � �������� ����������� ������������ ������������.

   public:
    typedef unsigned                                 ptype_id_type;
    typedef structure::t_value_with_null<unsigned>   ptype_id_type_N;

   public:
    /// ������������� ���������� ���� (����� ���� �� ���������).
    ptype_id_type_N  ptypeID;

    /// ��������� ���������� ����
    std::wstring     ptypeSign;

   public:
    tag_expected_ptype_descr();

    tag_expected_ptype_descr(ptype_id_type               _ptypeID,
                             structure::t_const_wstr_box _ptypeSign);

    explicit tag_expected_ptype_descr(structure::t_const_wstr_box _ptypeSign);

   ~tag_expected_ptype_descr();

    bool operator == (ptype_id_type id)const;

    bool operator != (ptype_id_type id)const;
  };//struct tag_expected_ptype_descr

  typedef tag_expected_ptype_descr             expected_ptype_descr_type;

  typedef structure::t_value_with_null
           <expected_ptype_descr_type>         expected_ptype_descr_type_N;

 public:
  const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE::self_ptr m_spDsPropValues;

 public:
  /// �������� ���������� ���� ��������� ����������
  expected_ptype_descr_type_N m_expectedPTypeDescr;

 public:
  enum tag_auth_kind
  {
   auth_kind__none=0,

   auth_kind__legacy=1,

   auth_kind__sspi=2,
  };

  /// ������������� ���� ��������������
  tag_auth_kind m_AuthKind;

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] pDsPropValues
  //!  Not null
  explicit RemoteFB__ClientConnectBlock_v1(oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

  /// <summary>
  ///  �����������
  /// </summary>
 ~RemoteFB__ClientConnectBlock_v1();
};//class RemoteFB__ClientConnectBlock_v1

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
