////////////////////////////////////////////////////////////////////////////////
//BASE64 MIME. Block Decoder
//                                               Kovalenko Dmitry. 19.11.2010.
#ifndef _t_base64_mime__block_decoder_H_
#define _t_base64_mime__block_decoder_H_

#include <structure/t_char_traits2.h>

namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//class t_base64_mime__block_decoder

/// <summary>
///  ����� ��� �������������� �������-����������� ����� MIME-������
/// <summary>
template<typename charT>
class t_base64_mime__block_decoder
{
 private:
  typedef t_base64_mime__block_decoder<charT>   self_type;

  t_base64_mime__block_decoder(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef charT                                 char_type;
  typedef structure::t_char_traits2<char_type>  char_traits2;

  typedef unsigned __int8                       byte_type;

  typedef size_t                                size_type;

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  t_base64_mime__block_decoder();
  
  //interface ------------------------------------------------------------
  /// <summary>
  ///  ��������� ������������ ������������ �����
  /// </summary>
  bool complete()const;
  
  /// <summary>
  ///  ���������� ���� � �������������� �������
  /// </summary>
  //! \attention
  //!  �������� ������ ��� ��������������� �����
  size_type result_size()const;

  /// <summary>
  ///  ��������� ����� �� ��������������� �������
  /// </summary>
  //! \param[in] i
  //!  ������ �����
  //!
  //! \attention
  //!  �������� ������ ��� ��������������� �����
  byte_type result_byte(size_type i)const;

  /// <summary>
  ///  ��������� MIME-�������
  /// </summary>
  //! \return
  //!  true, ���� ������ ��� ��������� ��� ������
  bool push(char_type mime_ch);

 private:
  typedef std::pair<byte_type,bool>         decode_ch_result_type;

 private:
  /// <summary>
  ///  ����� ������ � �������
  /// </summary>
  void reset_bytes();
  
  /// <summary>
  ///  ������������� BASE64 �������
  /// </summary>
  //! \param[in] base64_ch
  static decode_ch_result_type decode_ch(char_type base64_ch);

 private:
  ///����� MIME-�������� �������� �����
  size_type m_nMimeChars;

  ///����� ������������� ��������
  size_type m_nAlignChars;

  byte_type m_Bytes[3];
};//class t_base64_mime__block_decoder

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include <structure/charsets/t_base64_mime__block_decoder.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
