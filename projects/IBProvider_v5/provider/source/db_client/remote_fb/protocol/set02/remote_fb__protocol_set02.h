////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__protocol_set02
//! \file    remote_fb__protocol_set02.h
//! \brief   Конструкции протокола взаимодействия с FireBird v3+.
//! \author  Kovalenko Dmitry
//! \date    09.07.2016
#ifndef _remote_fb__protocol_set02_H_
#define _remote_fb__protocol_set02_H_

#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"
#include <structure/t_const_str_box.h>
#include <structure/t_zero.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace protocol{namespace set02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__protocol_set02
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

struct PACKET_V02;

struct P_CSTRING_CONST_V1;
struct P_CSTRING_CONST_V2;
struct P_LSTRING_CONST;

struct P_OP_CNCT;
struct P_OP_ACPT;
struct P_OP_ATCH;
struct P_OP_ACPD;
struct P_OP_AUTH_CONT;
struct P_OP_RESP;
struct P_OP_CRYPT;
struct P_OP_INFO;
struct P_OP_STTR;
struct P_OP_RLSE;
struct P_OP_PREP;
struct P_OP_SQLFREE;
struct P_OP_SQLST;
struct P_OP_SQLDATA;
struct P_OP_BLOB;
struct P_OP_SGMT;
struct P_OP_PUT_SLC;
struct P_OP_GET_SLC;
struct P_OP_SLC_DATA;
struct P_OP_CANCEL;

struct PACKET_V02;

////////////////////////////////////////////////////////////////////////////////
//Protocol Types
//p_acpt_type

//const P_USHORT ptype_page                 = 1;    // Page server protocol
//const P_USHORT ptype_rpc                  = 2;    // [deprecated] Simple remote procedure call
const P_USHORT ptype_batch_send             = 3;    // Batch sends, no asynchrony
const P_USHORT ptype_out_of_band            = 4;    // Batch sends w/ out of band notification
const P_USHORT ptype_lazy_send              = 5;    // Deferred packets delivery

const P_USHORT ptype_MASK                   = 0xFF;  // Mask - up to 255 types of protocol

// upper byte is used for protocol flags
const P_USHORT pflag_compress               = 0x100; // Turn on compression if possible

////////////////////////////////////////////////////////////////////////////////
//enum P_OP

/// <summary>
///  Operation IDs
/// </summary>
enum P_OP
{
 op_void                          = 0,    // Packet has been voided
 op_connect                       = 1,    // Connect to remote server
 //op_exit                        = 2,    // Remote end has exitted
 //op_accept                      = 3,    // Server accepts connection
 op_reject                        = 4,    // Server rejects connection
 //op_protocol                    = 5,    // Protocol selection
 //op_disconnect                  = 6,    // Connect is going away
 //op_credit                      = 7,    // Grant (buffer) credits
 //op_continuation                = 8,    // Continuation packet
 op_response                      = 9,    // Generic response block

 // Page server operations

 //op_open_file                   = 10,   // Open file for page service
 //op_create_file                 = 11,   // Create file for page service
 //op_close_file                  = 12,   // Close file for page service
 //op_read_page                   = 13,   // optionally lock and read page
 //op_write_page                  = 14,   // write page and optionally release lock
 //op_lock                        = 15,   // seize lock
 //op_convert_lock                = 16,   // convert existing lock
 //op_release_lock                = 17,   // release existing lock
 //op_blocking                    = 18,   // blocking lock message

 // Full context server operations

 op_attach                        = 19,   // Attach database
 op_create                        = 20,   // Create database
 op_detach                        = 21,   // Detach database
 //op_compile                     = 22,   // Request based operations
 //op_start                       = 23,
 //op_start_and_send              = 24,
 //op_send                        = 25,
 //op_receive                     = 26,
 //op_unwind                      = 27,   // apparently unused, see protocol.cpp's case op_unwind
 //op_release                     = 28,

 // Transaction operations

 op_transaction                   = 29,   // Start transaction
 op_commit                        = 30,   // Commit transaction
 op_rollback                      = 31,   // Rollback transdaction
 //op_prepare                     = 32,   // Prepare transaction
 //op_reconnect                   = 33,   // Reconnect transaction

 // Blob operations

 //op_create_blob                 = 34,
 //op_open_blob                   = 35,
 op_get_segment                   = 36,
 op_put_segment                   = 37,
 op_cancel_blob                   = 38,
 op_close_blob                    = 39,

 // Information services

 op_info_database                 = 40,
 //op_info_request                = 41,
 //op_info_transaction            = 42,
 op_info_blob                     = 43,

 //op_batch_segments              = 44,   // Put a bunch of blob segments

 //op_mgr_set_affinity            = 45,   // Establish server affinity
 //op_mgr_clear_affinity          = 46,   // Break server affinity
 //op_mgr_report                  = 47,   // Report on server

 //op_que_events                  = 48,   // Que event notification request
 //op_cancel_events               = 49,   // Cancel event notification request

 //-----------------------------------------------------------------------
 //! \brief
 //!  Коммит транзакции с сохранением контекста (commit retaining).
 //! \note
 //!  Операция доступна начиная с 4-го протокола.
 op_commit_retaining              = 50,   // Commit retaining (what else)

 //-----------------------------------------------------------------------
 op_prepare2                      = 51,   // Message form of prepare
 //op_event                       = 52,   // Completed event request (asynchronous)
 //op_connect_request             = 53,   // Request to establish connection
 //op_aux_connect                 = 54,   // Establish auxiliary connection
 //op_ddl                         = 55,   // DDL call
 op_open_blob2                    = 56,
 op_create_blob2                  = 57,
 op_get_slice                     = 58,
 op_put_slice                     = 59,
 op_slice                         = 60,   // Successful response to op_get_slice
 //op_seek_blob                   = 61,   // Blob seek operation

 // DSQL operations

 op_allocate_statement            = 62,   // allocate a statment handle
 op_execute                       = 63,   // execute a prepared statement
 op_exec_immediate                = 64,   // execute a statement
 op_fetch                         = 65,   // fetch a record
 op_fetch_response                = 66,   // response for record fetch
 op_free_statement                = 67,   // free a statement
 op_prepare_statement             = 68,   // prepare a statement
 //op_set_cursor                  = 69,   // set a cursor name
 op_info_sql                      = 70,

 op_dummy                         = 71,   // dummy packet to detect loss of client

 //op_response_piggyback          = 72,   // response block for piggybacked messages
 //op_start_and_receive           = 73,
 //op_start_send_and_receive      = 74,

 op_exec_immediate2               = 75,   // execute an immediate statement with msgs
 op_execute2                      = 76,   // execute a statement with msgs
 //op_insert                      = 77,
 op_sql_response                  = 78,   // response from execute, exec immed, insert

 //op_transact                    = 79,
 //op_transact_response           = 80,
 op_drop_database                 = 81,

 //op_service_attach              = 82,
 //op_service_detach              = 83,
 //op_service_info                = 84,
 //op_service_start               = 85,

 //-----------------------------------------------------------------------
 //! \brief
 //!  Откат транзакции с сохранением контекста (rollback retaining).
 //! \note
 //!  Операция доступна начиная с 10-го протокола (IB6).
 op_rollback_retaining            = 86,

 //-----------------------------------------------------------------------
 // Two following opcode are used in vulcan.
 // No plans to implement them completely for a while, but to
 // support protocol 11, where they are used, have them here.
 //op_update_account_info         = 87,
 //op_authenticate_user           = 88,

 //op_partial                     = 89,   // packet is not complete - delay processing
 //op_trusted_auth                = 90,

 op_cancel                        = 91,

 op_cont_auth                     = 92,

 //op_ping                        = 93,

 op_accept_data                   = 94,   // Server accepts connection and returns some data to client

 //op_abort_aux_connection        = 95,   // Async operation - stop waiting for async connection to arrive

 op_crypt                         = 96,
 //op_crypt_key_callback          = 97,

 // Server accepts connection, returns some data to client
 // and asks client to continue authentication before attach call
 op_cond_accept                   = 98,

 op_max
};//enum P_OP

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  It is a maximum length of CSTRING_V1.
/// </summary>
static const P_USHORT C_CSTRING_V1_MAX_LENGTH=0xFFFF;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  It is a maximum length that can be passed through ULONG-length.
/// </summary>
/// 
///  This limitation is linked with a defect in FB implementation.
///  See fixup fixupLength in protocol.cpp of FB3 source code.
/// 
static const P_ULONG C_CSTRING_V2_MAX_LENGTH_P13=0xFFFF0000-1;

////////////////////////////////////////////////////////////////////////////////

static const P_ULONG C_INFO_BUF_SIZE_P13=USHRT_MAX;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Максимальное количество элементов в статус векторе.
/// </summary>
///  По идее, у нас здесь должен быть unlimited. Но пока мы перестрахуемся.
static const size_t C_STATUS_VECTOR_MAX_SIZE=8196;

////////////////////////////////////////////////////////////////////////////////
//struct P_CSTRING_CONST_V1

/// <summary>
///  Count Const String Structure
/// </summary>
struct P_CSTRING_CONST_V1
{
 P_USHORT        cstr_length;
 const P_UCHAR*  cstr_address;
};//struct P_CSTRING_CONST_V1

////////////////////////////////////////////////////////////////////////////////
//struct P_CSTRING_CONST_V2

/// <summary>
///  Count Const String Structure
/// </summary>
struct P_CSTRING_CONST_V2
{
 P_ULONG         cstr_length;
 const P_UCHAR*  cstr_address;
};//struct P_CSTRING_CONST_V2

////////////////////////////////////////////////////////////////////////////////
//struct P_LSTRING_CONST

struct P_LSTRING_CONST
{
 P_ULONG        lstr_length;
 const P_UCHAR* lstr_address;
};//struct P_LSTRING_CONST

////////////////////////////////////////////////////////////////////////////////

//! \brief User name [UTF8]
const P_UCHAR P_CNCT_user                = 1;

//Password [not used]
//const P_UCHAR P_CNCT_passwd            = 2;

// Apollo person, project, organization. OBSOLETE.
//const P_UCHAR P_CNCT_ppo               = 3;

//! \brief Host name [UTF8]
const P_UCHAR P_CNCT_host                = 4;

//Effective Unix group id [not used]
//const P_UCHAR P_CNCT_group             = 5;

//! \brief Attach/create using this connection will use user verification
const P_UCHAR P_CNCT_user_verification   = 6;

//------------------------------------------ introduced in FB3

//! \brief Some data, needed for user verification on server
const P_UCHAR P_CNCT_specific_data       = 7;

//! \brief Name of plugin, which generated that data
const P_UCHAR P_CNCT_plugin_name         = 8;

//! \brief Same data as isc_dpb_user_name
const P_UCHAR P_CNCT_login               = 9;

//! \brief List of plugins, available on client
const P_UCHAR P_CNCT_plugin_list         = 10;

//! \brief Client encryption level (DISABLED/ENABLED/REQUIRED)
const P_UCHAR P_CNCT_client_crypt        = 11;

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_CNCT

/// <summary>
///  Connection Block (Client to Server)
/// </summary>
struct P_OP_CNCT
{
 public:
  /// <summary>
  ///  Protocol Information
  /// </summary>
  struct P_OP_CNCT_REPEAT
  {
   public:
    /// Protocol version number
    P_USHORT  p_cnct__version;

    /// Architecture of client
    P_ARCH    p_cnct__architecture;

    /// Minimum type
    P_USHORT  p_cnct__min_type;

    /// Maximum type
    P_USHORT  p_cnct__max_type;

    /// Preference weight
    P_USHORT  p_cnct__weight;

   public:
    /// <summary>
    ///  Установка данных.
    /// </summary>
    //! \param[in] version
    //! \param[in] architecture
    //! \param[in] min_type
    //! \param[in] max_type
    //! \param[in] weight
    void set(P_USHORT version,
             P_ARCH   architecture,
             P_USHORT min_type,
             P_USHORT max_type,
             P_USHORT weight);
  };//struct P_OP_CNCT_REPEAT

 public:
  /// Connect operation: op_create or op_attach
  P_OP                 p_cnct__operation;

  /// Version of connect protocol
  P_USHORT             p_cnct__cversion;

  /// Architecture of client
  P_ARCH               p_cnct__client;

  /// File name
  P_CSTRING_CONST_V1   p_cnct__file;

  /// Protocol versions understood
  P_USHORT             p_cnct__count;

  /// User identification stuff
  P_CSTRING_CONST_V1   p_cnct__user_id;

  P_OP_CNCT_REPEAT     p_cnct__versions[10];

 public:
  void add_cntr_version(P_USHORT version,
                        P_ARCH   architecture,
                        P_USHORT min_type,
                        P_USHORT max_type,
                        P_USHORT weight);
};//struct P_OP_CNCT

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_ACPT

/// <summary>
///  Accept Block (Server response to connect block)
/// </summary>
struct P_OP_ACPT
{
 public:
  //! \brief Protocol version number
  P_USHORT p_acpt__version;

  //! \brief Architecture for protocol
  P_ARCH p_acpt__architecture;

  //! \brief Minimum type
  P_USHORT p_acpt__type;
};//struct P_OP_ACPT

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_ACPD

/// <summary>
///  Accept Block with Data (Server response to connect block, start with P.13)
/// </summary>
struct P_OP_ACPD:public P_OP_ACPT
{
 public:
  //! \brief Returned auth data
  P_CSTRING_CONST_V2 p_acpd__data;

  //! \brief Plugin to continue with
  P_CSTRING_CONST_V2 p_acpd__plugin;

  //! \brief Auth complete in single step (few! strange...)
  P_USHORT p_acpd__authenticated;

  //! \brief Keys known to the server
  P_CSTRING_CONST_V2 p_acpd__keys;
};//struct P_OP_ACPD

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_AUTH_CONT

struct P_OP_AUTH_CONT
{
 public:
  //! \brief Specific data
  P_CSTRING_CONST_V2 p_auth_cont__data;

  //! \brief Plugin name
  P_CSTRING_CONST_V2 p_auth_cont__name;

  //! \brief Plugin list
  P_CSTRING_CONST_V2 p_auth_cont__list;

  //! \brief Keys available on server
  P_CSTRING_CONST_V2 p_auth_cont__keys;
};//struct P_OP_AUTH_CONT

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_ATCH

/// <summary>
///  Attach and create database
/// </summary>
struct P_OP_ATCH
{
 public:
  //! \brief Database object id
  P_OBJCT p_atch__database;

  //! \brief File name
  P_CSTRING_CONST_V2 p_atch__file;

  //! \brief Database parameter block
  P_CSTRING_CONST_V2 p_atch__dpb;
};//struct P_OP_ATCH

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_RESP

/// <summary>
///  Generic response block
/// </summary>
struct P_OP_RESP
{
 //! \brief Object id
 P_OBJCT p_resp__object;

 //! \brief Blob id
 P_BID p_resp__blob_id;

 //! \brief Data
 P_CSTRING_CONST_V2 p_resp__data;

 //! \brief Status vector
 P_ISC_STATUS_VECTOR p_resp__status_vector;
};//struct P_OP_RESP

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_CRYPT

/// <summary>
///  Пакет для настройки шифрования соединения
/// </summary>
struct P_OP_CRYPT
{
 //! \brief Crypt plugin name
 P_CSTRING_CONST_V2 p_crypt__plugin;

 //! \brief Key name / keys available on server
 P_CSTRING_CONST_V2 p_crypt__key;
};//struct P_OP_CRYPT

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_INFO

/// <summary>
///  Information request blocks
/// </summary>
struct P_OP_INFO
{
 //! \brief Object of information
 P_OBJCT             p_info__object;

 //! \brief Incarnation of object
 P_USHORT            p_info__incarnation;

 //! \brief Information
 P_CSTRING_CONST_V2  p_info__items;

 //! \brief Target buffer length
 P_ULONG             p_info__buffer_length;
};//struct P_OP_INFO

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_STTR

/// <summary>
///  Start Transaction
/// <summary>
struct P_OP_STTR
{
 //! \brief Database object id
 P_OBJCT            p_sttr__database;

 //! \brief Transaction parameter block
 P_CSTRING_CONST_V2 p_sttr__tpb;
};//struct P_OP_STTR

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_RLSE

/// <summary>
///  Generic release block
/// </summary>
struct P_OP_RLSE
{
 //! \brief Object to be released
 P_OBJCT p_rlse__object;
};//struct P_OP_RLSE

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_PREP

/// <summary>
///  Transaction prepare block
/// <summary>
struct P_OP_PREP
{
 //! \brief Transaction id
 P_OBJCT             p_prep__transaction;

 //! \brief Message
 P_CSTRING_CONST_V2  p_prep__data;
};//struct P_OP_PREP

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_SQLFREE

/// <summary>
///  Stmt free block
/// </summary>
struct P_OP_SQLFREE
{
 //! \brief Statement object
 P_OBJCT  p_sqlfree__statement;

 //! \brief Option
 P_USHORT p_sqlfree__option;
};//struct P_OP_SQLFREE

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_SQLST

/// <summary>
///  DSQL structure definitions
/// <summary>
struct P_OP_SQLST
{
 //! \brief Transaction object
 P_OBJCT            p_sqlst__transaction;

 //! \brief Statement object
 P_OBJCT            p_sqlst__statement;

 //! \brief The SQL dialect
 P_USHORT           p_sqlst__SQL_dialect;

 //! \brief Statement to be prepared
 P_CSTRING_CONST_V2 p_sqlst__SQL_str;

 //! \brief Target buffer length
 P_ULONG            p_sqlst__buffer_length;

 //! \brief Information
 P_CSTRING_CONST_V2 p_sqlst__items;

 //! \brief blr describing message
 P_CSTRING_CONST_V2 p_sqlst__blr;

 P_USHORT           p_sqlst__message_number;

 //! \brief Number of messages
 P_USHORT           p_sqlst__messages;

 //! \brief blr describing output message
 P_CSTRING_CONST_V2 p_sqlst__out_blr;

 P_USHORT           p_sqlst__out_message_number;
};//struct P_OP_SQLST

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_SQLDATA

struct P_OP_SQLDATA
{
 //! \brief statement object
 P_OBJCT             p_sqldata__statement;

 //! \brief transaction object
 P_OBJCT             p_sqldata__transaction;

 //! \brief blr describing message
 P_CSTRING_CONST_V2  p_sqldata__blr;

 P_USHORT            p_sqldata__message_number;

 //! \brief Number of messages
 P_USHORT            p_sqldata__messages;

 //! \brief blr describing output message
 P_CSTRING_CONST_V2  p_sqldata__out_blr;

 P_USHORT            p_sqldata__out_message_number;

 //! \brief final eof status
 P_ULONG             p_sqldata__status;
};//struct P_OP_SQLDATA

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_BLOB

struct P_OP_BLOB
{
 //! \brief Transaction
 P_OBJCT             p_blob__transaction;

 //! \brief Blob id for open
 P_BID               p_blob__id;

 //! \brief Blob parameter block
 P_CSTRING_CONST_V2  p_blob__bpb;
};//struct P_OP_BLOB

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_SGMT

struct P_OP_SGMT
{
 //! \brief Blob handle id
 P_OBJCT             p_sgmt__blob;

 //! \brief Length of segment
 P_USHORT            p_sgmt__length;

 //! \brief Data segment
 P_CSTRING_CONST_V2  p_sgmt__segment;
};//struct P_OP_SGMT

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_PUT_SLC

/// <summary>
///  Put Slice Operation
/// </summary>
struct P_OP_PUT_SLC
{
 //! \brief Transaction
 P_OBJCT            p_put_slc__transaction;

 //! \brief Slice id
 P_BID              p_put_slc__id;

 //Equal to p_put_slc__slice.lstr_length
 //P_ULONG          p_put_slc__length;

 //! \brief Slice description language
 P_CSTRING_CONST_V2 p_put_slc__sdl;

 //! \brief Slice parameters (array of P_LONGS)
 P_CSTRING_CONST_V2 p_put_slc__parameters;

 //! \brief Slice data
 P_LSTRING_CONST    p_put_slc__slice;
};//struct P_OP_PUT_SLC

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_GET_SLC

/// <summary>
///  Get Slice Operation
/// </summary>
struct P_OP_GET_SLC
{
 //! \brief Transaction
 P_OBJCT            p_get_slc__transaction;

 //! \brief Slice id
 P_BID              p_get_slc__id;

 //! \brief Length of slice
 P_ULONG            p_get_slc__length;

 //! \brief Slice description language
 P_CSTRING_CONST_V2 p_get_slc__sdl;

 //! \brief Slice parameters (array of P_LONGS)
 P_CSTRING_CONST_V2 p_get_slc__parameters;

 //P_LSTRING_CONST  p_get_slc__slice;
};//class P_OP_GET_SLC

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_SLC_DATA

/// <summary>
///  Slice Data
/// </summary>
struct P_OP_SLC_DATA
{
 //! \brief Total length of slice
 P_ULONG         p_slc_data__length;

 //! \brief Slice
 P_LSTRING_CONST p_slc_data__slice;
};//struct P_OP_SLC_DATA

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_CANCEL

struct P_OP_CANCEL
{
 //! \brief Kind of cancelation
 P_USHORT p_cancel__kind;
};//struct P_OP_CANCEL

////////////////////////////////////////////////////////////////////////////////
//struct PACKET_V02

/// <summary>
///  Универсальная структура для представления данных пакета
///  для группы протоколов PROTOCOL_SET_ID__02
/// </summary>
//! \attention
//!  Запрещено прямое копирование структры. Содержит внутренние указатели на саму себя.
struct PACKET_V02 LCPI_CPP_CFG__CLASS__FINAL:public PACKET
{
 private:
  typedef PACKET_V02                        self_type;
  typedef PACKET                            inherited;

  PACKET_V02(const self_type&);
  self_type& operator = (const self_type&);

 public:
  //! \brief Operation/packet type
  P_OP                operation;

  union
  {
   P_OP_CNCT          p_cnct;               // Connect block
   P_OP_ATCH          p_atch;               // Attach or create database
   P_OP_ACPD          p_acpd;               // Accept connection with data
   P_OP_AUTH_CONT     p_auth_cont;          // Request more auth data
   P_OP_RESP          p_resp;               // Generic response to a call
   P_OP_CRYPT         p_crypt;              // Start wire crypt
   P_OP_INFO          p_info;               // Information request blocks
   P_OP_STTR          p_sttr;               // Start transaction
   P_OP_RLSE          p_rlse;               // Generic release block
   P_OP_PREP          p_prep;               // Transaction prepare block
   P_OP_SQLFREE       p_sqlfree;            // Stmt free block
   P_OP_SQLST         p_sqlst;              // DSQL Prepare & Execute immediate
   P_OP_SQLDATA       p_sqldata;            // DSQL Open Cursor, Execute, Fetch
   P_OP_BLOB          p_blob;               // Create/Open blob
   P_OP_SGMT          p_sgmt;               // Segment operations
   P_OP_PUT_SLC       p_put_slc;            // Put slice operation
   P_OP_GET_SLC       p_get_slc;            // Get slice operation
   P_OP_SLC_DATA      p_slc_data;           // Slice data
   P_OP_CANCEL        p_cancel;             // Cancel operation
  };//union

 public:
  /// <summary>
  ///  Конструктор по-умолчанию.
  /// </summary>
  PACKET_V02()
   :inherited(PROTOCOL_SET_ID__02)
  {
   this->init();
  }//PACKET_V02

  /// <summary>
  ///  Инициализация структуры.
  /// </summary>
  self_type& init()
  {
   std::fill(reinterpret_cast<char*>(&this->operation),
             reinterpret_cast<char*>(this+1),
             structure::zero);

   return *this;
  }//init
};//struct PACKET_V02

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms set02*/}/*nms protocol*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/

namespace structure{
////////////////////////////////////////////////////////////////////////////////

inline structure::t_const_str_box
 make_str_box(const LCPI_IBP_NMS::db_client::remote_fb::protocol::set02::P_CSTRING_CONST_V2& cstr)
{
 assert_s(sizeof(*cstr.cstr_address)==sizeof(char));

 return structure::make_str_box
         (reinterpret_cast<const char*>(cstr.cstr_address),
          cstr.cstr_length);
}//make_str_box

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
