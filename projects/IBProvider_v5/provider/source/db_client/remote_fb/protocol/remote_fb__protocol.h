////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__protocol
//! \file    remote_fb__protocol.h
//! \brief   Конструкции протокола взаимодействия с FireBird.
//! \author  Kovalenko Dmitry
//! \date    28.10.2014.
#ifndef _remote_fb__protocol_H_
#define _remote_fb__protocol_H_

#include "source/db_obj/db_datatypes.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace protocol{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__protocol
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

//struct P_BID;

struct PACKET;

////////////////////////////////////////////////////////////////////////////////
/// <summary>
///  Тип для кодов возврата и элементов статус вектора
/// </summary>

typedef INT_PTR                             P_ISC_STATUS;

////////////////////////////////////////////////////////////////////////////////
//struct P_ISC_STATUS_VECTOR

/// <summary>
///  Status vector with dynamic size
/// </summary>
//!  Слишком большой размер inplace_sv_buffer не имеет смысла.
//!  Мы будем ориентироваться на работу с сервером без ошибок. 
struct P_ISC_STATUS_VECTOR
{
 public:
  size_t              size;
  const P_ISC_STATUS* ptr;

 public:
  P_ISC_STATUS inplace_sv_buffer[20];

 public:
  const P_ISC_STATUS* cbegin()const;

  const P_ISC_STATUS* cend()const;

 public:
 #ifndef NDEBUG
  void debug__check_state()const;
 #endif
};//struct P_ISC_STATUS_VECTOR

////////////////////////////////////////////////////////////////////////////////

typedef db_obj::t_dbvalue__i4               P_HYPER_LONG;
typedef db_obj::t_dbvalue__ui8              P_HYPER_LONGLONG;

////////////////////////////////////////////////////////////////////////////////
//base type

//! \brief Base protocol type: unsigned char
typedef db_obj::t_dbvalue__ui1              P_UCHAR;

//! \brief Base protocol type: signed short
typedef db_obj::t_dbvalue__i2               P_SHORT;

//! \brief Base protocol type: signed long
typedef db_obj::t_dbvalue__i4               P_LONG;

//! \brief Base protocol type: signed __int64
typedef db_obj::t_dbvalue__i8               P_INT64;

//! \brief Base protocol type: unsigned short
typedef db_obj::t_dbvalue__ui2              P_USHORT;

//! \brief Base protocol type: unsigned long
typedef db_obj::t_dbvalue__ui4              P_ULONG;

//! \brief Base protocol type: float
typedef db_obj::t_dbvalue__r4               P_FLOAT;

//! \brief Base protocol type: double
typedef db_obj::t_dbvalue__r8               P_DOUBLE;

////////////////////////////////////////////////////////////////////////////////

typedef db_obj::t_dbvalue__ui8              P_UINT64;

typedef db_obj::t_dbvalue__fb040_int128     P_INT128;

typedef db_obj::t_dbvalue__fb040_decfloat16 P_DECFLOAT16;

typedef db_obj::t_dbvalue__fb040_decfloat34 P_DECFLOAT34;

////////////////////////////////////////////////////////////////////////////////

typedef P_USHORT                            P_CONNECT_VERSION;

typedef P_USHORT                            P_PROTOCOL_VERSION;

////////////////////////////////////////////////////////////////////////////////

//! \brief Generic object id
typedef P_USHORT                            P_OBJCT;

const P_OBJCT P_INVALID_OBJECT=0xFFFF;

////////////////////////////////////////////////////////////////////////////////
//SET01

// p_cnct_version
const P_CONNECT_VERSION FB_CONNECT_VERSION2 = 2;

// Protocol 10 includes support for warnings and removes the requirement for
// encoding and decoding status codes

const P_PROTOCOL_VERSION FB_PROTOCOL_VERSION10 = 10;

// Since protocol 11 we must be separated from Borland InterBase.
// Therefore always set highmost bit in protocol version to 1.
// For unsigned protocol version this does not break version's compare.

const P_PROTOCOL_VERSION FB_PROTOCOL_FLAG   = 0x8000;
const P_PROTOCOL_VERSION FB_PROTOCOL_MASK   = static_cast<P_PROTOCOL_VERSION>(~FB_PROTOCOL_FLAG);

// Protocol 11 has support for user authentication related
// operations (op_update_account_info, op_authenticate_user and
// op_trusted_auth). When specific operation is not supported,
// we say "sorry".

const P_PROTOCOL_VERSION FB_PROTOCOL_VERSION11 = (FB_PROTOCOL_FLAG | 11);

// Protocol 12 has support for asynchronous call op_cancel.
// Currently implemented asynchronously only for TCP/IP
// on superserver and superclassic.

const P_PROTOCOL_VERSION FB_PROTOCOL_VERSION12 = (FB_PROTOCOL_FLAG | 12);

////////////////////////////////////////////////////////////////////////////////
//SET02

// p_cnct_cversion
const P_CONNECT_VERSION FB_CONNECT_VERSION3 = 3;

// Protocol 13 has support for authentication plugins (op_cont_auth).
// It also transfers SQL messages in the packed (null aware) format.

const P_PROTOCOL_VERSION FB_PROTOCOL_VERSION13 = (FB_PROTOCOL_FLAG | 13);

////////////////////////////////////////////////////////////////////////////////

//! \brief
//!  Размер пакета на стороне сервера
const size_t FB_SERVER_PACKET_SIZE=8*1024;

//! \brief
//!  Выравнивание полей внутри буфера с данными пакета
const P_USHORT FB_PACKET_FIELD_ALIGN=4;

//! \brief
//!  Максимальная длина строки в элементе статус-вектора
const P_ULONG FB_MAX_STATUS_VECTOR_STR_DATA_LENGTH=65535;

//! \brief
//!  [not used] Максимальный размер блока, который может передаваться в opaque за один заход.
const P_ULONG FB_MAX_OPAQUE=32768;

////////////////////////////////////////////////////////////////////////////////
//Конфигурация пакетной загрузки данных

const P_USHORT FB_MAX_PACKETS_PER_BATCH     = 4;
const P_USHORT FB_MIN_PACKETS_PER_BATCH     = 2;
const P_USHORT FB_DESIRED_ROWS_PER_BATCH    = 20;
const P_USHORT FB_MIN_ROWS_PER_BATCH        = 10;

////////////////////////////////////////////////////////////////////////////////
//Statement flags

const P_USHORT P_STMT_BLOB                  = 1;
const P_USHORT P_STMT_NO_BATCH              = 2;
const P_USHORT P_STMT_DEFER_EXECUTE         = 4;

////////////////////////////////////////////////////////////////////////////////
//enum P_ARCH

/// <summary>
///  Architecture types
/// </summary>
enum P_ARCH
{
 arch_generic                               = 1,    // Generic -- always use canonical forms
 //arch_apollo                              = 2,
 arch_sun                                   = 3,
 //arch_vms                                 = 4,
 //arch_ultrix                              = 5,
 //arch_alliant                             = 6,
 //arch_msdos                               = 7,
 arch_sun4                                  = 8,
 arch_sunx86                                = 9,
 arch_hpux                                  = 10,
 //arch_hpmpexl                             = 11,
 //arch_mac                                 = 12,
 //arch_macaux                              = 13,
 arch_rt                                    = 14,
 //arch_mips_ultrix                         = 15,
 //arch_hpux_68k                            = 16,
 //arch_xenix                               = 17,
 //arch_aviion                              = 18,
 //arch_sgi                                 = 19,
 //arch_apollo_dn10k                        = 20,
 //arch_cray                                = 21,
 //arch_imp                                 = 22,
 //arch_delta                               = 23,
 //arch_sco                                 = 24,
 //arch_next                                = 25,
 //arch_next_386                            = 26,
 //arch_m88k                                = 27,
 //arch_unixware                            = 28,
 arch_intel_32                              = 29,   // generic Intel chip w/32-bit compilation
 //arch_epson                               = 30,
 //arch_decosf                              = 31,
 //arch_ncr3000                             = 32,
 //arch_nt_ppc                              = 33,
 //arch_dg_x86                              = 34,
 //arch_sco_ev                              = 35,
 arch_linux                                 = 36,
 arch_freebsd                               = 37,
 arch_netbsd                                = 38,
 arch_darwin_ppc                            = 39,
 arch_winnt_64                              = 40,
 arch_darwin_x64                            = 41,
 arch_darwin_ppc64                          = 42,
 arch_max                                   = 43    // Keep this at the end
};//enum P_ARCH

////////////////////////////////////////////////////////////////////////////////

#ifndef IBP_PLATFORM_ID
# error IBP_PLATFORM_ID nor defined!
#endif

//! \brief
//!  Идентификатор текущей архитектуры
#if  (IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)
const P_ARCH FB_CURRENT_ARCHITECTURE        =arch_winnt_64;
#elif(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)
const P_ARCH FB_CURRENT_ARCHITECTURE        =arch_intel_32;
#else
# error Unknown platform ID!
#endif

////////////////////////////////////////////////////////////////////////////////
//struct P_BID

/// <summary>
///  BLOB ID
/// </summary>
typedef db_obj::DB_IBQUAD P_BID;

extern const P_BID __null_bid;

////////////////////////////////////////////////////////////////////////////////
//enum PROTOCOL_SET_ID

/// <summary>
///  Идентификаторы групп протоколов
/// </summary>
enum PROTOCOL_SET_ID
{
 /// Группа протоколов V10, V11, V12
 PROTOCOL_SET_ID__01    =1,

 /// Группа протоколов V13
 PROTOCOL_SET_ID__02    =2,
};//enum PROTOCOL_SET_ID

////////////////////////////////////////////////////////////////////////////////
//struct PACKET

/// <summary>
///  Универсальная структура для представления данных пакета
/// </summary>
struct PACKET
{
 private:
  typedef PACKET                            self_type;

  PACKET(const self_type&);
  self_type& operator = (const self_type&);

 public:
  const PROTOCOL_SET_ID protocolSetID;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// <summary>
  //! \param[in] _protocolSetID
  explicit PACKET(PROTOCOL_SET_ID const _protocolSetID)
   :protocolSetID(_protocolSetID)
  {;}
};//struct PACKET

////////////////////////////////////////////////////////////////////////////////
//struct P_ISC_STATUS_VECTOR

inline const P_ISC_STATUS* P_ISC_STATUS_VECTOR::cbegin()const
{
 return this->ptr;
}//cbegin

//------------------------------------------------------------------------
inline const P_ISC_STATUS* P_ISC_STATUS_VECTOR::cend()const
{
 return this->ptr+this->size;
}//cend

//------------------------------------------------------------------------
#ifndef NDEBUG
inline void P_ISC_STATUS_VECTOR::debug__check_state()const
{
 CHECK_READ_TYPED_PTR(this->ptr,this->size);
}//debug__check_state
#endif

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms protocol*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
