////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__enc_crypt.h
//! \brief   Утилита для шифрования.
//! \author  Kovalenko Dmitry
//! \date    09.02.2015.
#ifndef _remote_fb__enc_crypt_H_
#define _remote_fb__enc_crypt_H_

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ENC_crypt

/// <summary>
///  Утилита для шифрования.
/// </summary>
/// - Реализация алгоритмов позаимствована из исходников Firebird 2.5.
/// - Используются сгенерированные таблицы шифрования.
class RemoteFB__ENC_crypt LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  using TEXT=char;

 public:
  static const size_t c_RESULT_SIZE = (1 + 4 + 4 + 11 + 1);

 public:
  static void ENC_crypt(TEXT*       buf,
                        size_t      bufSize,
                        const TEXT* key,
                        const TEXT* setting);
 private:
  using SLONG=long;

  union  C_block;
  struct C_block2;

  struct tag_ctx;

  class tag_data;

 private:
  static int helper__des_setkey(tag_ctx&       ctx,
                                unsigned char* key);

  static int helper__des_cipher(tag_ctx&       ctx,
                                const C_block* in,
                                C_block*       out,
                                SLONG          salt,
                                int            num_iter);

  static void helper__permute(const unsigned char* cp,
                              C_block*             out,
                              const C_block*       p,
                              int                  chars_in);
};//class RemoteFB__ENC_crypt

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
