////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__msg_data_element_descr.h
//! \brief   ��������� �������� MSG-������ � �������.
//! \author  Kovalenko Dmitry
//! \date    18.05.2015.
#ifndef _remote_fb__msg_data_element_descr_H_
#define _remote_fb__msg_data_element_descr_H_

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__MsgDataElementDescr

/// <summary>
///  ��������� �������� MSG-������ � �������.
/// </summary>
class RemoteFB__MsgDataElementDescr
{
 public:
  /// ������ ����� � �������
  size_t m_msg_value_block_size;

  /// �������� ����� � �������
  size_t m_msg_value_block_offset;

  /// �������� ���������� ��������� ������
  size_t m_msg_sqlind_offset;

  /// BLR-��� �������� ������
  unsigned m_msg_blrtype;

 public:
  /// ������������� SQL-���� ������, ��� �������� ��������� ������ ����
  short m_xvar_sqltype;

  /// ������� ��������
  short m_xvar_sqlscale;

 public:
  /// <summary>
  ///  ����������� �� ���������.
  /// </summary>
  RemoteFB__MsgDataElementDescr();
};//class RemoteFB__MsgDataElementDescr

////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

// it is used only in debug code
inline bool operator == (const RemoteFB__MsgDataElementDescr& x1,const RemoteFB__MsgDataElementDescr& x2)
{
 if(x1.m_msg_value_block_size!=x2.m_msg_value_block_size)
  return false;

 if(x1.m_msg_value_block_offset!=x2.m_msg_value_block_offset)
  return false;

 if(x1.m_msg_sqlind_offset!=x2.m_msg_sqlind_offset)
  return false;

 if(x1.m_msg_blrtype!=x2.m_msg_blrtype)
  return false;

 if(x1.m_xvar_sqltype!= x2.m_xvar_sqltype)
  return false;

 if(x1.m_xvar_sqlscale!=x2.m_xvar_sqlscale)
  return false;

 return true;
}//operator ==

#endif // NDEBUG

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
