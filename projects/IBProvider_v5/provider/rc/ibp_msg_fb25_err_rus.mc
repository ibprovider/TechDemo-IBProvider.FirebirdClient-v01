////////////////////////////////////////////////////////////////////////////////
//IBProvider resources. Firebird 2.5 Error Messages. Русский.
//                                                  Dmitry Kovalenko. 29.12.2014
#include "ibp_msg_fb25_err_ids.rh"

////////////////////////////////////////////////////////////////////////////////
LanguageNames=(Rus=0x0419:IBP_MSG_FB25_ERR_RUS)

////////////////////////////////////////////////////////////////////////////////

MessageId       =IBP_MCE_FB25__ARITH_EXCEPT
Language        =Rus
_MC("arithmetic exception, numeric overflow, or string truncation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_DBKEY
Language        =Rus
_MC("invalid database key")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_DB_FORMAT
Language        =Rus
_MC("file %1 is not a valid database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_DB_HANDLE
Language        =Rus
_MC("Недействительный дескриптор базы данных (нет активного подключения).")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_DPB_CONTENT
Language        =Rus
_MC("bad parameters on attach or create database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_DPB_FORM
Language        =Rus
_MC("unrecognized database parameter block")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_REQ_HANDLE
Language        =Rus
_MC("Недействительный дескриптор запроса.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_SEGSTR_HANDLE
Language        =Rus
_MC("Недействительный дескриптор блоба.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_SEGSTR_ID
Language        =Rus
_MC("Недействительный BLOB ID.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_TPB_CONTENT
Language        =Rus
_MC("invalid parameter in transaction parameter block")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_TPB_FORM
Language        =Rus
_MC("Некорректная структура блока с параметрами транзакции")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_TRANS_HANDLE
Language        =Rus
_MC("Недействительный дескриптор транзакции (ожидается явный старт транзакции).")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BUG_CHECK
Language        =Rus
_MC("internal Firebird consistency check (%1)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CONVERT_ERROR
Language        =Rus
_MC("conversion error from string \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DB_CORRUPT
Language        =Rus
_MC("database file appears corrupt (%1)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DEADLOCK
Language        =Rus
_MC("deadlock")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCESS_TRANS
Language        =Rus
_MC("attempt to start more than %1 transactions")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FROM_NO_MATCH
Language        =Rus
_MC("no match for first value expression")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INFINAP
Language        =Rus
_MC("information type inappropriate for object specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INFONA
Language        =Rus
_MC("no information of this type available for object specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INFUNK
Language        =Rus
_MC("unknown information item")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INTEG_FAIL
Language        =Rus
_MC("action cancelled by trigger (%1) to preserve data integrity")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_BLR
Language        =Rus
_MC("invalid request BLR at offset %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IO_ERROR
Language        =Rus
_MC("I/O ошибка в процессе выполнения операции \"%1\" для файла \"%2\".")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOCK_CONFLICT
Language        =Rus
_MC("lock conflict on no wait transaction")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__METADATA_CORRUPT
Language        =Rus
_MC("corrupt system table")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOT_VALID
Language        =Rus
_MC("validation error for column %1, value \"%2\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_CUR_REC
Language        =Rus
_MC("no current record for fetch operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_DUP
Language        =Rus
_MC("attempt to store duplicate value (visible to active transactions) in unique index \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_FINISH
Language        =Rus
_MC("program attempted to exit without finishing database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_META_UPDATE
Language        =Rus
_MC("unsuccessful metadata update")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_PRIV
Language        =Rus
_MC("no permission for %1 access to %2 %3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_RECON
Language        =Rus
_MC("transaction is not in limbo")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_RECORD
Language        =Rus
_MC("invalid database key")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_SEGSTR_CLOSE
Language        =Rus
_MC("BLOB was not closed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__OBSOLETE_METADATA
Language        =Rus
_MC("metadata is obsolete")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__OPEN_TRANS
Language        =Rus
_MC("Нельзя отключать базу данных с незавершенными транзакциями (количество: %1).")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PORT_LEN
Language        =Rus
_MC("message length error (encountered %1, expected %2)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__READ_ONLY_FIELD
Language        =Rus
_MC("attempted update of read-only column")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__READ_ONLY_REL
Language        =Rus
_MC("attempted update of read-only table")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__READ_ONLY_TRANS
Language        =Rus
_MC("attempted update during read-only transaction")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__READ_ONLY_VIEW
Language        =Rus
_MC("cannot update read-only view %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REQ_NO_TRANS
Language        =Rus
_MC("no transaction for request")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REQ_SYNC
Language        =Rus
_MC("request synchronization error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REQ_WRONG_DB
Language        =Rus
_MC("request referenced an unavailable database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SEGMENT
Language        =Rus
_MC("segment buffer length shorter than expected")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SEGSTR_EOF
Language        =Rus
_MC("attempted retrieval of more segments than exist")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SEGSTR_NO_OP
Language        =Rus
_MC("attempted invalid operation on a BLOB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SEGSTR_NO_READ
Language        =Rus
_MC("attempted read of a new, open BLOB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SEGSTR_NO_TRANS
Language        =Rus
_MC("attempted action on BLOB outside transaction")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SEGSTR_NO_WRITE
Language        =Rus
_MC("attempted write to read-only BLOB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SEGSTR_WRONG_DB
Language        =Rus
_MC("attempted reference to BLOB in unavailable database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYS_REQUEST
Language        =Rus
_MC("operating system directive %1 failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__STREAM_EOF
Language        =Rus
_MC("attempt to fetch past the last record in a record stream")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UNAVAILABLE
Language        =Rus
_MC("unavailable database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UNRES_REL
Language        =Rus
_MC("table %1 was omitted from the transaction reserving list")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UNS_EXT
Language        =Rus
_MC("request includes a DSRI extension not supported in this implementation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WISH_LIST
Language        =Rus
_MC("feature is not supported")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WRONG_ODS
Language        =Rus
_MC("unsupported on-disk structure for file %1; found %2.%3, support %4.%5")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WRONUMARG
Language        =Rus
_MC("wrong number of arguments on call")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IMP_EXC
Language        =Rus
_MC("Implementation limit exceeded")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__RANDOM
Language        =Rus
_MC("%1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FATAL_CONFLICT
Language        =Rus
_MC("unrecoverable conflict with limbo transaction %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BADBLK
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVPOOLCL
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOPOOLIDS
Language        =Rus
_MC("too many requests")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__RELBADBLK
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BLKTOOBIG
Language        =Rus
_MC("block size exceeds implementation restriction")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BUFEXH
Language        =Rus
_MC("buffer exhausted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYNTAXERR
Language        =Rus
_MC("BLR syntax error: expected %1 at offset %2, encountered %3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BUFINUSE
Language        =Rus
_MC("buffer in use")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BDBINCON
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REQINUSE
Language        =Rus
_MC("request in use")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BADODSVER
Language        =Rus
_MC("incompatible version of on-disk structure")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__RELNOTDEF
Language        =Rus
_MC("таблица %1 не определена")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FLDNOTDEF
Language        =Rus
_MC("колонка %1 не определена в таблице %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DIRTYPAGE
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAIFORTRA
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DOUBLELOC
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NODNOTFND
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DUPNODFND
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOCNOTMAR
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BADPAGTYP
Language        =Rus
_MC("page %1 is of wrong type (expected %2, found %3)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CORRUPT
Language        =Rus
_MC("database corrupted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BADPAGE
Language        =Rus
_MC("checksum error on database page %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BADINDEX
Language        =Rus
_MC("index is broken")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DBBNOTZER
Language        =Rus
_MC("Ненулевой дескриптор базы данных")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TRANOTZER
Language        =Rus
_MC("Ненулевой дескриптор транзакции")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TRAREQMIS
Language        =Rus
_MC("transaction--request mismatch (synchronization error)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BADHNDCNT
Language        =Rus
_MC("bad handle count")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WROTPBVER
Language        =Rus
_MC("Недействительная версия структуры блока с параметрами транзакции")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WROBLRVER
Language        =Rus
_MC("unsupported BLR version (expected %1, encountered %2)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WRODPBVER
Language        =Rus
_MC("wrong version of database parameter block")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BLOBNOTSUP
Language        =Rus
_MC("BLOB and array data types are not supported for %1 operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BADRELATION
Language        =Rus
_MC("database corrupted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NODETACH
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOTREMOTE
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TRAINLIM
Language        =Rus
_MC("transaction in limbo")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOTINLIM
Language        =Rus
_MC("transaction not in limbo")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TRAOUTSTA
Language        =Rus
_MC("transaction outstanding")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CONNECT_REJECT
Language        =Rus
_MC("connection rejected by remote interface")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DBFILE
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ORPHAN
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_LOCK_MGR
Language        =Rus
_MC("no lock manager available")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CTXINUSE
Language        =Rus
_MC("context already in use (BLR error)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CTXNOTDEF
Language        =Rus
_MC("context not defined (BLR error)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DATNOTSUP
Language        =Rus
_MC("data operation not supported")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BADMSGNUM
Language        =Rus
_MC("undefined message number")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BADPARNUM
Language        =Rus
_MC("bad parameter number")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__VIRMEMEXH
Language        =Rus
_MC("unable to allocate memory from operating system")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BLOCKING_SIGNAL
Language        =Rus
_MC("blocking signal has been received")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOCKMANERR
Language        =Rus
_MC("lock manager error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__JOURNERR
Language        =Rus
_MC("communication error with journal \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__KEYTOOBIG
Language        =Rus
_MC("key size exceeds implementation restriction for index \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NULLSEGKEY
Language        =Rus
_MC("null segment of UNIQUE KEY")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SQLERR
Language        =Rus
_MC("SQL error code = %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WRODYNVER
Language        =Rus
_MC("wrong DYN version")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FUNNOTDEF
Language        =Rus
_MC("function %1 is not defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FUNMISMAT
Language        =Rus
_MC("function %1 could not be matched")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_MSG_VEC
Language        =Rus
_MC("")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_DETACH
Language        =Rus
_MC("database detach completed with errors")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOARGACC_READ
Language        =Rus
_MC("database system cannot read argument %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOARGACC_WRITE
Language        =Rus
_MC("database system cannot write argument %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__READ_ONLY
Language        =Rus
_MC("operation not supported")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXT_ERR
Language        =Rus
_MC("%1 extension error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NON_UPDATABLE
Language        =Rus
_MC("not updatable")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_ROLLBACK
Language        =Rus
_MC("no rollback performed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_SEC_INFO
Language        =Rus
_MC("")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_SEC_INFO
Language        =Rus
_MC("")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MISC_INTERPRETED
Language        =Rus
_MC("%1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UPDATE_CONFLICT
Language        =Rus
_MC("update conflicts with concurrent update")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UNLICENSED
Language        =Rus
_MC("product %1 is not licensed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__OBJ_IN_USE
Language        =Rus
_MC("object %1 is in use")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOFILTER
Language        =Rus
_MC("filter not found to convert type %1 to type %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SHADOW_ACCESSED
Language        =Rus
_MC("cannot attach active shadow file")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_SDL
Language        =Rus
_MC("invalid slice description language at offset %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__OUT_OF_BOUNDS
Language        =Rus
_MC("subscript out of bounds")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_DIMENSION
Language        =Rus
_MC("column not array or invalid dimensions (expected %1, encountered %2)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REC_IN_LIMBO
Language        =Rus
_MC("record from transaction %1 is stuck in limbo")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SHADOW_MISSING
Language        =Rus
_MC("a file in manual shadow %1 is unavailable")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CANT_VALIDATE
Language        =Rus
_MC("secondary server attachments cannot validate databases")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CANT_START_JOURNAL
Language        =Rus
_MC("secondary server attachments cannot start journaling")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GENNOTDEF
Language        =Rus
_MC("generator %1 is not defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CANT_START_LOGGING
Language        =Rus
_MC("secondary server attachments cannot start logging")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_SEGSTR_TYPE
Language        =Rus
_MC("invalid BLOB type for operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FOREIGN_KEY
Language        =Rus
_MC("violation of FOREIGN KEY constraint \"%1\" on table \"%2\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__HIGH_MINOR
Language        =Rus
_MC("minor version too high found %1 expected %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TRA_STATE
Language        =Rus
_MC("transaction %1 is %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TRANS_INVALID
Language        =Rus
_MC("transaction marked invalid by I/O error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BUF_INVALID
Language        =Rus
_MC("cache buffer for page %1 invalid")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INDEXNOTDEFINED
Language        =Rus
_MC("there is no index in table %1 with id %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGIN
Language        =Rus
_MC("Ваши имя пользователя и пароль не определены. Попросите администратора базы данных предоставить логин к Firebird.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_BOOKMARK
Language        =Rus
_MC("invalid bookmark handle")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_LOCK_LEVEL
Language        =Rus
_MC("invalid lock level %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__RELATION_LOCK
Language        =Rus
_MC("lock on table %1 conflicts with existing lock")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__RECORD_LOCK
Language        =Rus
_MC("requested record lock conflicts with existing lock")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MAX_IDX
Language        =Rus
_MC("maximum indexes per table (%1) exceeded")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__JRN_ENABLE
Language        =Rus
_MC("enable journal for database before starting online dump")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__OLD_FAILURE
Language        =Rus
_MC("online dump failure. Retry dump")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__OLD_IN_PROGRESS
Language        =Rus
_MC("an online dump is already in progress")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__OLD_NO_SPACE
Language        =Rus
_MC("no more disk/tape space.  Cannot continue online dump")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_WAL_NO_JRN
Language        =Rus
_MC("journaling allowed only if database has Write-ahead Log")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NUM_OLD_FILES
Language        =Rus
_MC("maximum number of online dump files that can be specified is 16")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_FILE_OPEN
Language        =Rus
_MC("error in opening Write-ahead Log file during recovery")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_STMT_HANDLE
Language        =Rus
_MC("invalid statement handle")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_FAILURE
Language        =Rus
_MC("Write-ahead log subsystem failure")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WALW_ERR
Language        =Rus
_MC("WAL Writer error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGH_SMALL
Language        =Rus
_MC("Log file header of %1 too small")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGH_INV_VERSION
Language        =Rus
_MC("Invalid version of log file %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGH_OPEN_FLAG
Language        =Rus
_MC("Log file %1 not latest in the chain but open flag still set")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGH_OPEN_FLAG2
Language        =Rus
_MC("Log file %1 not closed properly; database recovery may be required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGH_DIFF_DBNAME
Language        =Rus
_MC("Database name in the log file %1 is different")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGF_UNEXPECTED_EOF
Language        =Rus
_MC("Unexpected end of log file %1 at offset %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGR_INCOMPLETE
Language        =Rus
_MC("Incomplete log record at offset %1 in log file %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGR_HEADER_SMALL
Language        =Rus
_MC("Log record header too small at offset %1 in log file %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGB_SMALL
Language        =Rus
_MC("Log block too small at offset %1 in log file %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_ILLEGAL_ATTACH
Language        =Rus
_MC("Illegal attempt to attach to an uninitialized WAL segment for %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_INVALID_WPB
Language        =Rus
_MC("Invalid WAL parameter block option %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_ERR_ROLLOVER
Language        =Rus
_MC("Cannot roll over to the next log file %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_WAL
Language        =Rus
_MC("database does not use Write-ahead Log")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DROP_WAL
Language        =Rus
_MC("cannot drop log file when journaling is enabled")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__STREAM_NOT_DEFINED
Language        =Rus
_MC("reference to invalid stream number")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_SUBSYS_ERROR
Language        =Rus
_MC("WAL subsystem encountered error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_SUBSYS_CORRUPT
Language        =Rus
_MC("WAL subsystem corrupted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_ARCHIVE
Language        =Rus
_MC("must specify archive file when enabling long term journal for databases with round-robin log files")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SHUTINPROG
Language        =Rus
_MC("database %1 shutdown in progress")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__RANGE_IN_USE
Language        =Rus
_MC("refresh range number %1 already in use")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__RANGE_NOT_FOUND
Language        =Rus
_MC("refresh range number %1 not found")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CHARSET_NOT_FOUND
Language        =Rus
_MC("CHARACTER SET %1 is not defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOCK_TIMEOUT
Language        =Rus
_MC("lock time-out on wait transaction")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PRCNOTDEF
Language        =Rus
_MC("procedure %1 is not defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PRCMISMAT
Language        =Rus
_MC("Input parameter mismatch for procedure %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_BUGCHECK
Language        =Rus
_MC("Database %1: WAL subsystem bug for pid %2\n"
    "%3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_CANT_EXPAND
Language        =Rus
_MC("Could not expand the WAL segment for database %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CODNOTDEF
Language        =Rus
_MC("status code %1 unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__XCPNOTDEF
Language        =Rus
_MC("exception %1 not defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPT
Language        =Rus
_MC("exception %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CACHE_RESTART
Language        =Rus
_MC("restart shared cache manager")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_LOCK_HANDLE
Language        =Rus
_MC("invalid lock handle")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__JRN_PRESENT
Language        =Rus
_MC("long-term journaling already enabled")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_ERR_ROLLOVER2
Language        =Rus
_MC("Unable to roll over please see Firebird log.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_ERR_LOGWRITE
Language        =Rus
_MC("WAL I/O error.  Please see Firebird log.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_ERR_JRN_COMM
Language        =Rus
_MC("WAL writer - Journal server communication error.  Please see Firebird log.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_ERR_EXPANSION
Language        =Rus
_MC("WAL buffers cannot be increased.  Please see Firebird log.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_ERR_SETUP
Language        =Rus
_MC("WAL setup error.  Please see Firebird log.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_ERR_WW_SYNC
Language        =Rus
_MC("obsolete")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_ERR_WW_START
Language        =Rus
_MC("Cannot start WAL writer for the database %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SHUTDOWN
Language        =Rus
_MC("database %1 shutdown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXISTING_PRIV_MOD
Language        =Rus
_MC("cannot modify an existing user privilege")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_REF
Language        =Rus
_MC("Cannot delete PRIMARY KEY being used in FOREIGN KEY definition.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_NOTNULL
Language        =Rus
_MC("Column used in a PRIMARY constraint must be NOT NULL.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REF_CNSTRNT_NOTFOUND
Language        =Rus
_MC("Name of Referential Constraint not defined in constraints table.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FOREIGN_KEY_NOTFOUND
Language        =Rus
_MC("Non-existent PRIMARY or UNIQUE KEY specified for FOREIGN KEY.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REF_CNSTRNT_UPDATE
Language        =Rus
_MC("Cannot update constraints (RDB$REF_CONSTRAINTS).")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CHECK_CNSTRNT_UPDATE
Language        =Rus
_MC("Cannot update constraints (RDB$CHECK_CONSTRAINTS).")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CHECK_CNSTRNT_DEL
Language        =Rus
_MC("Cannot delete CHECK constraint entry (RDB$CHECK_CONSTRAINTS)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INTEG_INDEX_SEG_DEL
Language        =Rus
_MC("Cannot delete index segment used by an Integrity Constraint")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INTEG_INDEX_SEG_MOD
Language        =Rus
_MC("Cannot update index segment used by an Integrity Constraint")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INTEG_INDEX_DEL
Language        =Rus
_MC("Cannot delete index used by an Integrity Constraint")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INTEG_INDEX_MOD
Language        =Rus
_MC("Cannot modify index used by an Integrity Constraint")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CHECK_TRIG_DEL
Language        =Rus
_MC("Cannot delete trigger used by a CHECK Constraint")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CHECK_TRIG_UPDATE
Language        =Rus
_MC("Cannot update trigger used by a CHECK Constraint")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CNSTRNT_FLD_DEL
Language        =Rus
_MC("Cannot delete column being used in an Integrity Constraint.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CNSTRNT_FLD_RENAME
Language        =Rus
_MC("Cannot rename column being used in an Integrity Constraint.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REL_CNSTRNT_UPDATE
Language        =Rus
_MC("Cannot update constraints (RDB$RELATION_CONSTRAINTS).")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CONSTAINT_ON_VIEW
Language        =Rus
_MC("Cannot define constraints on views")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVLD_CNSTRNT_TYPE
Language        =Rus
_MC("internal Firebird consistency check (invalid RDB$CONSTRAINT_TYPE)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_EXISTS
Language        =Rus
_MC("Attempt to define a second PRIMARY KEY for the same table")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSTRIG_UPDATE
Language        =Rus
_MC("cannot modify or erase a system trigger")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOT_REL_OWNER
Language        =Rus
_MC("only the owner of a table may reassign ownership")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GRANT_OBJ_NOTFOUND
Language        =Rus
_MC("could not find table/procedure for GRANT")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GRANT_FLD_NOTFOUND
Language        =Rus
_MC("could not find column for GRANT")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GRANT_NOPRIV
Language        =Rus
_MC("user does not have GRANT privileges for operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NONSQL_SECURITY_REL
Language        =Rus
_MC("table/procedure has non-SQL security class defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NONSQL_SECURITY_FLD
Language        =Rus
_MC("column has non-SQL security class defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_CACHE_ERR
Language        =Rus
_MC("Write-ahead Log without shared cache configuration not allowed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SHUTFAIL
Language        =Rus
_MC("database shutdown unsuccessful")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CHECK_CONSTRAINT
Language        =Rus
_MC("Operation violates CHECK constraint %1 on view or table %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_SVC_HANDLE
Language        =Rus
_MC("invalid service handle")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SHUTWARN
Language        =Rus
_MC("database %1 shutdown in %2 seconds")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WROSPBVER
Language        =Rus
_MC("wrong version of service parameter block")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_SPB_FORM
Language        =Rus
_MC("unrecognized service parameter block")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SVCNOTDEF
Language        =Rus
_MC("service %1 is not defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_JRN
Language        =Rus
_MC("long-term journaling not enabled")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TRANSLITERATION_FAILED
Language        =Rus
_MC("Cannot transliterate character between character sets")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__START_CM_FOR_WAL
Language        =Rus
_MC("WAL defined; Cache Manager must be started first")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_OVFLOW_LOG_REQUIRED
Language        =Rus
_MC("Overflow log specification required for round-robin log")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TEXT_SUBTYPE
Language        =Rus
_MC("Implementation of text subtype %1 not located.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_ERROR
Language        =Rus
_MC("Dynamic SQL Error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_COMMAND_ERR
Language        =Rus
_MC("Invalid command")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CONSTANT_ERR
Language        =Rus
_MC("Data type for constant unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_ERR
Language        =Rus
_MC("Invalid cursor reference")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DATATYPE_ERR
Language        =Rus
_MC("Data type unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DECL_ERR
Language        =Rus
_MC("Invalid cursor declaration")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_UPDATE_ERR
Language        =Rus
_MC("Cursor %1 is not updatable")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_OPEN_ERR
Language        =Rus
_MC("Attempt to reopen an open cursor")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_CLOSE_ERR
Language        =Rus
_MC("Attempt to reclose a closed cursor")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_FIELD_ERR
Language        =Rus
_MC("Column unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INTERNAL_ERR
Language        =Rus
_MC("Internal error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_RELATION_ERR
Language        =Rus
_MC("Table unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_PROCEDURE_ERR
Language        =Rus
_MC("Procedure unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_REQUEST_ERR
Language        =Rus
_MC("Request unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_SQLDA_ERR
Language        =Rus
_MC("SQLDA missing or incorrect version, or incorrect number/type of variables")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_VAR_COUNT_ERR
Language        =Rus
_MC("Count of read-write columns does not equal count of values")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_STMT_HANDLE
Language        =Rus
_MC("Invalid statement handle")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_FUNCTION_ERR
Language        =Rus
_MC("Function unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_BLOB_ERR
Language        =Rus
_MC("Column is not a BLOB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__COLLATION_NOT_FOUND
Language        =Rus
_MC("COLLATION %1 for CHARACTER SET %2 is not defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__COLLATION_NOT_FOR_CHARSET
Language        =Rus
_MC("COLLATION %1 is not valid for specified CHARACTER SET")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DUP_OPTION
Language        =Rus
_MC("Option specified more than once")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_TRAN_ERR
Language        =Rus
_MC("Unknown transaction option")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INVALID_ARRAY
Language        =Rus
_MC("Invalid array reference")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_MAX_ARR_DIM_EXCEEDED
Language        =Rus
_MC("Array declared with too many dimensions")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_ARR_RANGE_ERROR
Language        =Rus
_MC("Illegal array dimension range")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_TRIGGER_ERR
Language        =Rus
_MC("Trigger unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_SUBSELECT_ERR
Language        =Rus
_MC("Subselect illegal in this context")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CRDB_PREPARE_ERR
Language        =Rus
_MC("Cannot prepare a CREATE DATABASE/SCHEMA statement")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SPECIFY_FIELD_ERR
Language        =Rus
_MC("must specify column name for view select expression")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NUM_FIELD_ERR
Language        =Rus
_MC("number of columns does not match select list")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__COL_NAME_ERR
Language        =Rus
_MC("Only simple column names permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WHERE_ERR
Language        =Rus
_MC("No WHERE clause for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TABLE_VIEW_ERR
Language        =Rus
_MC("Only one table allowed for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DISTINCT_ERR
Language        =Rus
_MC("DISTINCT, GROUP or HAVING not permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__KEY_FIELD_COUNT_ERR
Language        =Rus
_MC("FOREIGN KEY column count does not match PRIMARY KEY")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SUBQUERY_ERR
Language        =Rus
_MC("No subqueries permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXPRESSION_EVAL_ERR
Language        =Rus
_MC("expression evaluation not supported")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NODE_ERR
Language        =Rus
_MC("gen.c: node not supported")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__COMMAND_END_ERR
Language        =Rus
_MC("Unexpected end of command")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INDEX_NAME
Language        =Rus
_MC("INDEX %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_NAME
Language        =Rus
_MC("EXCEPTION %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FIELD_NAME
Language        =Rus
_MC("COLUMN %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TOKEN_ERR
Language        =Rus
_MC("Token unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UNION_ERR
Language        =Rus
_MC("union not supported")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CONSTRUCT_ERR
Language        =Rus
_MC("Unsupported DSQL construct")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FIELD_AGGREGATE_ERR
Language        =Rus
_MC("column used with aggregate")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FIELD_REF_ERR
Language        =Rus
_MC("invalid column reference")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ORDER_BY_ERR
Language        =Rus
_MC("invalid ORDER BY clause")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__RETURN_MODE_ERR
Language        =Rus
_MC("Return mode by value not allowed for this data type")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXTERN_FUNC_ERR
Language        =Rus
_MC("External functions cannot have more than 10 parameters")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ALIAS_CONFLICT_ERR
Language        =Rus
_MC("alias %1 conflicts with an alias in the same statement")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PROCEDURE_CONFLICT_ERROR
Language        =Rus
_MC("alias %1 conflicts with a procedure in the same statement")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__RELATION_CONFLICT_ERR
Language        =Rus
_MC("alias %1 conflicts with a table in the same statement")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DOMAIN_ERR
Language        =Rus
_MC("Illegal use of keyword VALUE")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IDX_SEG_ERR
Language        =Rus
_MC("segment count of 0 defined for index %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NODE_NAME_ERR
Language        =Rus
_MC("A node name is not permitted in a secondary, shadow, cache or log file name")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TABLE_NAME
Language        =Rus
_MC("TABLE %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PROC_NAME
Language        =Rus
_MC("PROCEDURE %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IDX_CREATE_ERR
Language        =Rus
_MC("cannot create index %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_SHADOW_ERR
Language        =Rus
_MC("Write-ahead Log with shadowing configuration not allowed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DEPENDENCY
Language        =Rus
_MC("there are %1 dependencies")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IDX_KEY_ERR
Language        =Rus
_MC("too many keys defined for index %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_FILE_LENGTH_ERR
Language        =Rus
_MC("Preceding file did not specify length, so %1 must include starting page number")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_SHADOW_NUMBER_ERR
Language        =Rus
_MC("Shadow number must be a positive integer")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_TOKEN_UNK_ERR
Language        =Rus
_MC("Token unknown - line %1, column %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_NO_RELATION_ALIAS
Language        =Rus
_MC("there is no alias or table named %1 at this scope level")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INDEXNAME
Language        =Rus
_MC("there is no index %1 for table %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_STREAM_PLAN
Language        =Rus
_MC("table %1 is not referenced in plan")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__STREAM_TWICE
Language        =Rus
_MC("table %1 is referenced more than once in plan; use aliases to distinguish")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__STREAM_NOT_FOUND
Language        =Rus
_MC("table %1 is referenced in the plan but not the from list")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__COLLATION_REQUIRES_TEXT
Language        =Rus
_MC("Invalid use of CHARACTER SET or COLLATE")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DOMAIN_NOT_FOUND
Language        =Rus
_MC("Specified domain or source column %1 does not exist")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INDEX_UNUSED
Language        =Rus
_MC("index %1 cannot be used in the specified plan")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_SELF_JOIN
Language        =Rus
_MC("the table %1 is referenced twice; use aliases to differentiate")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__STREAM_BOF
Language        =Rus
_MC("illegal operation when at beginning of stream")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__STREAM_CRACK
Language        =Rus
_MC("the current position is on a crack")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DB_OR_FILE_EXISTS
Language        =Rus
_MC("database or file exists")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_OPERATOR
Language        =Rus
_MC("invalid comparison operator for find operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CONN_LOST
Language        =Rus
_MC("Connection lost to pipe server")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_CHECKSUM
Language        =Rus
_MC("bad checksum")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PAGE_TYPE_ERR
Language        =Rus
_MC("wrong page type")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXT_READONLY_ERR
Language        =Rus
_MC("Cannot insert because the file is readonly or is on a read only medium.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SING_SELECT_ERR
Language        =Rus
_MC("несколько рядов в одиночном селекте")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PSW_ATTACH
Language        =Rus
_MC("cannot attach to password database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PSW_START_TRANS
Language        =Rus
_MC("cannot start transaction for password database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_DIRECTION
Language        =Rus
_MC("invalid direction for find operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_VAR_CONFLICT
Language        =Rus
_MC("variable %1 conflicts with parameter in same procedure")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_NO_BLOB_ARRAY
Language        =Rus
_MC("Array/BLOB/DATE data types not allowed in arithmetic")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_BASE_TABLE
Language        =Rus
_MC("%1 is not a valid base table of the specified view")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DUPLICATE_BASE_TABLE
Language        =Rus
_MC("table %1 is referenced twice in view; use an alias to distinguish")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__VIEW_ALIAS
Language        =Rus
_MC("view %1 has more than one base table; use aliases to distinguish")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INDEX_ROOT_PAGE_FULL
Language        =Rus
_MC("cannot add index, index root page is full.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_BLOB_TYPE_UNKNOWN
Language        =Rus
_MC("BLOB SUB_TYPE %1 is not defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REQ_MAX_CLONES_EXCEEDED
Language        =Rus
_MC("Too many concurrent executions of the same request")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DUPLICATE_SPEC
Language        =Rus
_MC("duplicate specification of %1 - not supported")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UNIQUE_KEY_VIOLATION
Language        =Rus
_MC("violation of PRIMARY or UNIQUE KEY constraint \"%1\" on table \"%2\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SRVR_VERSION_TOO_OLD
Language        =Rus
_MC("server version too old to support all CREATE DATABASE options")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DRDB_COMPLETED_WITH_ERRS
Language        =Rus
_MC("drop database completed with errors")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_PROCEDURE_USE_ERR
Language        =Rus
_MC("procedure %1 does not return any values")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_COUNT_MISMATCH
Language        =Rus
_MC("count of column list and variable list do not match")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BLOB_IDX_ERR
Language        =Rus
_MC("attempt to index BLOB column in index %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ARRAY_IDX_ERR
Language        =Rus
_MC("attempt to index array column in index %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__KEY_FIELD_ERR
Language        =Rus
_MC("too few key columns found for index %1 (incorrect column name?)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_DELETE
Language        =Rus
_MC("cannot delete")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DEL_LAST_FIELD
Language        =Rus
_MC("last column in a table cannot be deleted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SORT_ERR
Language        =Rus
_MC("sort error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SORT_MEM_ERR
Language        =Rus
_MC("sort error: not enough memory")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__VERSION_ERR
Language        =Rus
_MC("too many versions")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVAL_KEY_POSN
Language        =Rus
_MC("invalid key position")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_SEGMENTS_ERR
Language        =Rus
_MC("segments not allowed in expression index %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CRRP_DATA_ERR
Language        =Rus
_MC("sort error: corruption in data structure")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REC_SIZE_ERR
Language        =Rus
_MC("new record size of %1 bytes is too big")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_FIELD_REF
Language        =Rus
_MC("Inappropriate self-reference of column")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REQ_DEPTH_EXCEEDED
Language        =Rus
_MC("request depth exceeded. (Recursive definition?)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_FIELD_ACCESS
Language        =Rus
_MC("cannot access column %1 in view %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_DBKEY
Language        =Rus
_MC("dbkey not available for multi-table views")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__JRN_FORMAT_ERR
Language        =Rus
_MC("journal file wrong format")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__JRN_FILE_FULL
Language        =Rus
_MC("intermediate journal file full")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_OPEN_CURSOR_REQUEST
Language        =Rus
_MC("The prepare statement identifies a prepare statement with an open cursor")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IB_ERROR
Language        =Rus
_MC("Firebird error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CACHE_REDEF
Language        =Rus
_MC("Cache redefined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CACHE_TOO_SMALL
Language        =Rus
_MC("Недостаточно памяти для размещения буфера страничного кэша.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOG_REDEF
Language        =Rus
_MC("Log redefined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOG_TOO_SMALL
Language        =Rus
_MC("Log size too small")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PARTITION_TOO_SMALL
Language        =Rus
_MC("Log partition size too small")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PARTITION_NOT_SUPP
Language        =Rus
_MC("Partitions not supported in series of log file specification")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOG_LENGTH_SPEC
Language        =Rus
_MC("Total length of a partitioned log must be specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PRECISION_ERR
Language        =Rus
_MC("Precision must be from 1 to 18")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SCALE_NOGT
Language        =Rus
_MC("Scale must be between zero and precision")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXPEC_SHORT
Language        =Rus
_MC("Short integer expected")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXPEC_LONG
Language        =Rus
_MC("Long integer expected")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXPEC_USHORT
Language        =Rus
_MC("Unsigned short integer expected")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ESCAPE_INVALID
Language        =Rus
_MC("Invalid ESCAPE sequence")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SVCNOEXE
Language        =Rus
_MC("service %1 does not have an associated executable")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NET_LOOKUP_ERR
Language        =Rus
_MC("Failed to locate host machine.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SERVICE_UNKNOWN
Language        =Rus
_MC("Undefined service %1/%2.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__HOST_UNKNOWN
Language        =Rus
_MC("The specified name was not found in the hosts file or Domain Name Services.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GRANT_NOPRIV_ON_BASE
Language        =Rus
_MC("user does not have GRANT privileges on base table/view for operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_FLD_AMBIGUOUS
Language        =Rus
_MC("Ambiguous column reference.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_AGG_REF_ERR
Language        =Rus
_MC("Invalid aggregate reference")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__COMPLEX_VIEW
Language        =Rus
_MC("navigational stream %1 references a view with more than one base table")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UNPREPARED_STMT
Language        =Rus
_MC("Попытка выполнить неподготовленное динамическое SQL выражение.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXPEC_POSITIVE
Language        =Rus
_MC("Positive value expected")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_SQLDA_VALUE_ERR
Language        =Rus
_MC("Incorrect values within SQLDA structure")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_ARRAY_ID
Language        =Rus
_MC("invalid blob id")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXTFILE_UNS_OP
Language        =Rus
_MC("Operation not supported for EXTERNAL FILE table %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SVC_IN_USE
Language        =Rus
_MC("Service is currently busy: %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ERR_STACK_LIMIT
Language        =Rus
_MC("stack size insufficent to execute current request")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_KEY
Language        =Rus
_MC("Invalid key for find operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NET_INIT_ERROR
Language        =Rus
_MC("Error initializing the network software.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOADLIB_FAILURE
Language        =Rus
_MC("Unable to load required library %1.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NETWORK_ERROR
Language        =Rus
_MC("Unable to complete network request to host \"%1\".")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NET_CONNECT_ERR
Language        =Rus
_MC("Failed to establish a connection.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NET_CONNECT_LISTEN_ERR
Language        =Rus
_MC("Error while listening for an incoming connection.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NET_EVENT_CONNECT_ERR
Language        =Rus
_MC("Failed to establish a secondary connection for event processing.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NET_EVENT_LISTEN_ERR
Language        =Rus
_MC("Error while listening for an incoming event connection request.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NET_READ_ERR
Language        =Rus
_MC("Error reading data from the connection.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NET_WRITE_ERR
Language        =Rus
_MC("Error writing data to the connection.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INTEG_INDEX_DEACTIVATE
Language        =Rus
_MC("Cannot deactivate index used by an integrity constraint")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INTEG_DEACTIVATE_PRIMARY
Language        =Rus
_MC("Cannot deactivate index used by a PRIMARY/UNIQUE constraint")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CSE_NOT_SUPPORTED
Language        =Rus
_MC("Client/Server Express not supported in this release")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TRA_MUST_SWEEP
Language        =Rus
_MC("")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UNSUPPORTED_NETWORK_DRIVE
Language        =Rus
_MC("Access to databases on file servers is not supported.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IO_CREATE_ERR
Language        =Rus
_MC("В процессе создания файла произошла ошибка.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IO_OPEN_ERR
Language        =Rus
_MC("В процессе открытия файла произошла ошибка.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IO_CLOSE_ERR
Language        =Rus
_MC("В процессе закрытия файла произошла ошибка.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IO_READ_ERR
Language        =Rus
_MC("В процессе чтения из файла произошла ошибка.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IO_WRITE_ERR
Language        =Rus
_MC("В процессе записи в файл произошла ошибка.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IO_DELETE_ERR
Language        =Rus
_MC("В процессе удаления файла произошла ошибка.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IO_ACCESS_ERR
Language        =Rus
_MC("В процессе доступа к файлу произошла ошибка.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UDF_EXCEPTION
Language        =Rus
_MC("A fatal exception occurred during the execution of a user defined function.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOST_DB_CONNECTION
Language        =Rus
_MC("connection lost to database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_WRITE_USER_PRIV
Language        =Rus
_MC("User cannot write to RDB$USER_PRIVILEGES")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TOKEN_TOO_LONG
Language        =Rus
_MC("token size exceeds limit")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MAX_ATT_EXCEEDED
Language        =Rus
_MC("Maximum user count exceeded.  Contact your database administrator.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LOGIN_SAME_AS_ROLE_NAME
Language        =Rus
_MC("Your login %1 is same as one of the SQL role name. Ask your database administrator to set up a valid Firebird login.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__REFTABLE_REQUIRES_PK
Language        =Rus
_MC("\"REFERENCES table\" without \"(column)\" requires PRIMARY KEY on referenced table")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__USRNAME_TOO_LONG
Language        =Rus
_MC("The username entered is too long.  Maximum length is 31 bytes.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PASSWORD_TOO_LONG
Language        =Rus
_MC("The password specified is too long.  Maximum length is 8 bytes.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__USRNAME_REQUIRED
Language        =Rus
_MC("A username is required for this operation.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PASSWORD_REQUIRED
Language        =Rus
_MC("A password is required for this operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_PROTOCOL
Language        =Rus
_MC("The network protocol specified is invalid")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DUP_USRNAME_FOUND
Language        =Rus
_MC("A duplicate user name was found in the security database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__USRNAME_NOT_FOUND
Language        =Rus
_MC("The user name specified was not found in the security database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ERROR_ADDING_SEC_RECORD
Language        =Rus
_MC("An error occurred while attempting to add the user.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ERROR_MODIFYING_SEC_RECORD
Language        =Rus
_MC("An error occurred while attempting to modify the user record.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ERROR_DELETING_SEC_RECORD
Language        =Rus
_MC("An error occurred while attempting to delete the user record.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ERROR_UPDATING_SEC_DB
Language        =Rus
_MC("An error occurred while updating the security database.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SORT_REC_SIZE_ERR
Language        =Rus
_MC("sort record size of %1 bytes is too big")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_DEFAULT_VALUE
Language        =Rus
_MC("can not define a not null column with NULL as default value")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_CLAUSE
Language        =Rus
_MC("invalid clause --- '%1'")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TOO_MANY_HANDLES
Language        =Rus
_MC("too many open handles to database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__OPTIMIZER_BLK_EXC
Language        =Rus
_MC("size of optimizer block exceeded")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_STRING_CONSTANT
Language        =Rus
_MC("a string constant is delimited by double quotes")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TRANSITIONAL_DATE
Language        =Rus
_MC("DATE must be changed to TIMESTAMP")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__READ_ONLY_DATABASE
Language        =Rus
_MC("attempted update on read-only database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MUST_BE_DIALECT_2_AND_UP
Language        =Rus
_MC("SQL dialect %1 is not supported in this database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BLOB_FILTER_EXCEPTION
Language        =Rus
_MC("A fatal exception occurred during the execution of a blob filter.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_ACCESS_VIOLATION
Language        =Rus
_MC("Access violation.  The code attempted to access a virtual address without privilege to do so.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_DATATYPE_MISSALIGNMENT
Language        =Rus
_MC("Datatype misalignment.  The attempted to read or write a value that was not stored on a memory boundary.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_ARRAY_BOUNDS_EXCEEDED
Language        =Rus
_MC("Array bounds exceeded.  The code attempted to access an array element that is out of bounds.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_DENORMAL_OPERAND
Language        =Rus
_MC("Float denormal operand.  One of the floating-point operands is too small to represent a standard float value.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_DIVIDE_BY_ZERO
Language        =Rus
_MC("Floating-point divide by zero.  The code attempted to divide a floating-point value by zero.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_INEXACT_RESULT
Language        =Rus
_MC("Floating-point inexact result.  The result of a floating-point operation cannot be represented as a decimal fraction.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_INVALID_OPERAND
Language        =Rus
_MC("Floating-point invalid operand.  An indeterminant error occurred during a floating-point operation.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_OVERFLOW
Language        =Rus
_MC("Floating-point overflow.  The exponent of a floating-point operation is greater than the magnitude allowed.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_STACK_CHECK
Language        =Rus
_MC("Floating-point stack check.  The stack overflowed or underflowed as the result of a floating-point operation.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_UNDERFLOW
Language        =Rus
_MC("Floating-point underflow.  The exponent of a floating-point operation is less than the magnitude allowed.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_INTEGER_DIVIDE_BY_ZERO
Language        =Rus
_MC("Integer divide by zero.  The code attempted to divide an integer value by an integer divisor of zero.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_INTEGER_OVERFLOW
Language        =Rus
_MC("Integer overflow.  The result of an integer operation caused the most significant bit of the result to carry.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_UNKNOWN
Language        =Rus
_MC("An exception occurred that does not have a description.  Exception number %1.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_STACK_OVERFLOW
Language        =Rus
_MC("Stack overflow.  The resource requirements of the runtime stack have exceeded the memory available to it.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGSEGV
Language        =Rus
_MC("Segmentation Fault. The code attempted to access memory without privileges.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGILL
Language        =Rus
_MC("Illegal Instruction. The Code attempted to perform an illegal operation.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGBUS
Language        =Rus
_MC("Bus Error. The Code caused a system bus error.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGFPE
Language        =Rus
_MC("Floating Point Error. The Code caused an Arithmetic Exception or a floating point exception.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXT_FILE_DELETE
Language        =Rus
_MC("Cannot delete rows from external files.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXT_FILE_MODIFY
Language        =Rus
_MC("Cannot update rows in external files.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ADM_TASK_DENIED
Language        =Rus
_MC("Unable to perform operation.  You must be either SYSDBA or owner of the database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXTRACT_INPUT_MISMATCH
Language        =Rus
_MC("Specified EXTRACT part does not exist in input datatype")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INSUFFICIENT_SVC_PRIVILEGES
Language        =Rus
_MC("Service %1 requires SYSDBA permissions.  Reattach to the Service Manager using the SYSDBA account.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FILE_IN_USE
Language        =Rus
_MC("The file %1 is currently in use by another process.  Try again later.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SERVICE_ATT_ERR
Language        =Rus
_MC("Cannot attach to services manager")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DDL_NOT_ALLOWED_BY_DB_SQL_DIAL
Language        =Rus
_MC("Metadata update statement is not allowed by the current database SQL dialect %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CANCELLED
Language        =Rus
_MC("Операция была отменена.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UNEXP_SPB_FORM
Language        =Rus
_MC("unexpected item in service parameter block, expected %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SQL_DIALECT_DATATYPE_UNSUPPORT
Language        =Rus
_MC("Client SQL dialect %1 does not support reference to %2 datatype")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SVCNOUSER
Language        =Rus
_MC("user name and password are required while attaching to the services manager")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DEPEND_ON_UNCOMMITTED_REL
Language        =Rus
_MC("You created an indirect dependency on uncommitted metadata. You must roll back the current transaction.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SVC_NAME_MISSING
Language        =Rus
_MC("The service name was not specified.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TOO_MANY_CONTEXTS
Language        =Rus
_MC("Too many Contexts of Relation/Procedure/Views. Maximum allowed is 255")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DATYPE_NOTSUP
Language        =Rus
_MC("data type not supported for arithmetic")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DIALECT_RESET_WARNING
Language        =Rus
_MC("Database dialect being changed from 3 to 1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DIALECT_NOT_CHANGED
Language        =Rus
_MC("Database dialect not changed.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DATABASE_CREATE_FAILED
Language        =Rus
_MC("Unable to create database %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INV_DIALECT_SPECIFIED
Language        =Rus
_MC("Database dialect %1 is not a valid dialect.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__VALID_DB_DIALECTS
Language        =Rus
_MC("Valid database dialects are %1.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SQLWARN
Language        =Rus
_MC("SQL warning code = %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DTYPE_RENAMED
Language        =Rus
_MC("DATE data type is now called TIMESTAMP")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXTERN_FUNC_DIR_ERROR
Language        =Rus
_MC("Function %1 is in %2, which is not in a permitted directory for external functions.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DATE_RANGE_EXCEEDED
Language        =Rus
_MC("value exceeds the range for valid dates")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INV_CLIENT_DIALECT_SPECIFIED
Language        =Rus
_MC("passed client dialect %1 is not a valid dialect.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__VALID_CLIENT_DIALECTS
Language        =Rus
_MC("Valid client dialects are %1.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__OPTIMIZER_BETWEEN_ERR
Language        =Rus
_MC("Unsupported field type specified in BETWEEN predicate.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SERVICE_NOT_SUPPORTED
Language        =Rus
_MC("Services functionality will be supported in a later version  of the product")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GENERATOR_NAME
Language        =Rus
_MC("GENERATOR %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UDF_NAME
Language        =Rus
_MC("UDF %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_LIMIT_PARAM
Language        =Rus
_MC("Invalid parameter to FIRST. Only integers >= 0 are allowed.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_SKIP_PARAM
Language        =Rus
_MC("Invalid parameter to SKIP. Only integers >= 0 are allowed.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IO_32BIT_EXCEEDED_ERR
Language        =Rus
_MC("File exceeded maximum size of 2GB.  Add another database file or use a 64 bit I/O version of Firebird.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_SAVEPOINT
Language        =Rus
_MC("Unable to find savepoint with name %1 in transaction context")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_COLUMN_POS_ERR
Language        =Rus
_MC("Invalid column position used in the %1 clause")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_AGG_WHERE_ERR
Language        =Rus
_MC("Cannot use an aggregate function in a WHERE clause, use HAVING instead")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_AGG_GROUP_ERR
Language        =Rus
_MC("Cannot use an aggregate function in a GROUP BY clause")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_AGG_COLUMN_ERR
Language        =Rus
_MC("Invalid expression in the %1 (not contained in either an aggregate function or the GROUP BY clause)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_AGG_HAVING_ERR
Language        =Rus
_MC("Invalid expression in the %1 (neither an aggregate function nor a part of the GROUP BY clause)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_AGG_NESTED_ERR
Language        =Rus
_MC("Nested aggregate functions are not allowed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXEC_SQL_INVALID_ARG
Language        =Rus
_MC("Invalid argument in EXECUTE STATEMENT - cannot convert to string")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXEC_SQL_INVALID_REQ
Language        =Rus
_MC("Wrong request type in EXECUTE STATEMENT '%1'")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXEC_SQL_INVALID_VAR
Language        =Rus
_MC("Variable type (position %1) in EXECUTE STATEMENT '%2' INTO does not match returned column type")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXEC_SQL_MAX_CALL_EXCEEDED
Language        =Rus
_MC("Too many recursion levels of EXECUTE STATEMENT")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CONF_ACCESS_DENIED
Language        =Rus
_MC("Access to %1 \"%2\" is denied by server administrator")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WRONG_BACKUP_STATE
Language        =Rus
_MC("Cannot change difference file name while database is in backup mode")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__WAL_BACKUP_ERR
Language        =Rus
_MC("Physical backup is not allowed while Write-Ahead Log is in use")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CURSOR_NOT_OPEN
Language        =Rus
_MC("Cursor is not open")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_SHUTDOWN_MODE
Language        =Rus
_MC("Target shutdown mode is invalid for database \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CONCAT_OVERFLOW
Language        =Rus
_MC("Concatenation overflow. Resulting string cannot exceed 32765 bytes in length.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_SUBSTRING_OFFSET
Language        =Rus
_MC("Invalid offset parameter %1 to SUBSTRING. Only positive integers are allowed.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FOREIGN_KEY_TARGET_DOESNT_EXIST
Language        =Rus
_MC("Foreign key reference target does not exist")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FOREIGN_KEY_REFERENCES_PRESENT
Language        =Rus
_MC("Foreign key references are present for the record")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_UPDATE
Language        =Rus
_MC("cannot update")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CURSOR_ALREADY_OPEN
Language        =Rus
_MC("Cursor is already open")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__STACK_TRACE
Language        =Rus
_MC("%1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CTX_VAR_NOT_FOUND
Language        =Rus
_MC("Context variable %1 is not found in namespace %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CTX_NAMESPACE_INVALID
Language        =Rus
_MC("Invalid namespace name %1 passed to %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CTX_TOO_BIG
Language        =Rus
_MC("Too many context variables")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CTX_BAD_ARGUMENT
Language        =Rus
_MC("Invalid argument passed to %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IDENTIFIER_TOO_LONG
Language        =Rus
_MC("BLR syntax error. Identifier %1... is too long")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EXCEPT2
Language        =Rus
_MC("exception %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MALFORMED_STRING
Language        =Rus
_MC("Malformed string")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PRC_OUT_PARAM_MISMATCH
Language        =Rus
_MC("Output parameter mismatch for procedure %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__COMMAND_END_ERR2
Language        =Rus
_MC("Unexpected end of command - line %1, column %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PARTNER_IDX_INCOMPAT_TYPE
Language        =Rus
_MC("partner index segment no %1 has incompatible data type")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_SUBSTRING_LENGTH
Language        =Rus
_MC("Invalid length parameter %1 to SUBSTRING. Negative integers are not allowed.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CHARSET_NOT_INSTALLED
Language        =Rus
_MC("CHARACTER SET %1 is not installed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__COLLATION_NOT_INSTALLED
Language        =Rus
_MC("COLLATION %1 for CHARACTER SET %2 is not installed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ATT_SHUTDOWN
Language        =Rus
_MC("connection shutdown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BLOBTOOBIG
Language        =Rus
_MC("Maximum BLOB size exceeded")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MUST_HAVE_PHYS_FIELD
Language        =Rus
_MC("Can't have relation with only computed fields or constraints")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_TIME_PRECISION
Language        =Rus
_MC("Time precision exceeds allowed range (0-%1)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BLOB_CONVERT_ERROR
Language        =Rus
_MC("Unsupported conversion to target type BLOB (subtype %1)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ARRAY_CONVERT_ERROR
Language        =Rus
_MC("Unsupported conversion to target type ARRAY")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__RECORD_LOCK_NOT_SUPP
Language        =Rus
_MC("Stream does not support record locking")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PARTNER_IDX_NOT_FOUND
Language        =Rus
_MC("Cannot create foreign key constraint %1. Partner index does not exist or is inactive.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TRA_NUM_EXC
Language        =Rus
_MC("Transactions count exceeded. Perform backup and restore to make database operable again")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FIELD_DISAPPEARED
Language        =Rus
_MC("Column has been unexpectedly deleted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MET_WRONG_GTT_SCOPE
Language        =Rus
_MC("%1 cannot depend on %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SUBTYPE_FOR_INTERNAL_USE
Language        =Rus
_MC("Blob sub_types bigger than 1 (text) are for internal use only")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ILLEGAL_PRC_TYPE
Language        =Rus
_MC("Procedure %1 is not selectable (it does not contain a SUSPEND statement)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_SORT_DATATYPE
Language        =Rus
_MC("Datatype %1 is not supported for sorting operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__COLLATION_NAME
Language        =Rus
_MC("COLLATION %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DOMAIN_NAME
Language        =Rus
_MC("DOMAIN %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DOMNOTDEF
Language        =Rus
_MC("domain %1 is not defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ARRAY_MAX_DIMENSIONS
Language        =Rus
_MC("Array data type can use up to %1 dimensions")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MAX_DB_PER_TRANS_ALLOWED
Language        =Rus
_MC("A multi database transaction cannot span more than %1 databases")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_DEBUG_FORMAT
Language        =Rus
_MC("Bad debug info format")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_PROC_BLR
Language        =Rus
_MC("Error while parsing procedure %1's BLR")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__KEY_TOO_BIG
Language        =Rus
_MC("index key too big")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CONCURRENT_TRANSACTION
Language        =Rus
_MC("concurrent transaction number is %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOT_VALID_FOR_VAR
Language        =Rus
_MC("validation error for variable %1, value \"%2\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOT_VALID_FOR
Language        =Rus
_MC("validation error for %1, value \"%2\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NEED_DIFFERENCE
Language        =Rus
_MC("Difference file name should be set explicitly for database on raw device")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LONG_LOGIN
Language        =Rus
_MC("Login name too long (%1 characters, maximum allowed %2)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FLDNOTDEF2
Language        =Rus
_MC("column %1 is not defined in procedure %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_SIMILAR_PATTERN
Language        =Rus
_MC("Invalid SIMILAR TO pattern")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_TEB_FORM
Language        =Rus
_MC("Invalid TEB format")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_MULTIPLE_TXN_ISOLATION
Language        =Rus
_MC("Found more than one transaction isolation in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_BEFORE_TABLE
Language        =Rus
_MC("Table reservation lock type %1 requires table name before in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_MULTIPLE_SPEC
Language        =Rus
_MC("Found more than one %1 specification in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_OPTION_WITHOUT_RC
Language        =Rus
_MC("Option %1 requires READ COMMITTED isolation in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_CONFLICTING_OPTIONS
Language        =Rus
_MC("Option %1 is not valid if %2 was used previously in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_MISSING_TLEN
Language        =Rus
_MC("Table name length missing after table reservation %1 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_LONG_TLEN
Language        =Rus
_MC("Table name length %1 is too long after table reservation %2 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_MISSING_TNAME
Language        =Rus
_MC("Table name length %1 without table name after table reservation %2 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_CORRUP_TLEN
Language        =Rus
_MC("Table name length %1 goes beyond the remaining TPB size after table reservation %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_NULL_TLEN
Language        =Rus
_MC("Table name length is zero after table reservation %1 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_RELNOTFOUND
Language        =Rus
_MC("Table or view %1 not defined in system tables after table reservation %2 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_BASERELNOTFOUND
Language        =Rus
_MC("Base table or view %1 for view %2 not defined in system tables after table reservation %3 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_MISSING_LEN
Language        =Rus
_MC("Option length missing after option %1 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_MISSING_VALUE
Language        =Rus
_MC("Option length %1 without value after option %2 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_CORRUPT_LEN
Language        =Rus
_MC("Option length %1 goes beyond the remaining TPB size after option %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_NULL_LEN
Language        =Rus
_MC("Option length is zero after table reservation %1 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_OVERFLOW_LEN
Language        =Rus
_MC("Option length %1 exceeds the range for option %2 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_INVALID_VALUE
Language        =Rus
_MC("Option value %1 is invalid for the option %2 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_STRONGER_WNG
Language        =Rus
_MC("Preserving previous table reservation %1 for table %2, stronger than new %3 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_STRONGER
Language        =Rus
_MC("Table reservation %1 for table %2 already specified and is stronger than new %3 in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_MAX_RECURSION
Language        =Rus
_MC("Table reservation reached maximum recursion of %1 when expanding views in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_VIRTUALTBL
Language        =Rus
_MC("Table reservation in TPB cannot be applied to %1 because it's a virtual table")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_SYSTBL
Language        =Rus
_MC("Table reservation in TPB cannot be applied to %1 because it's a system table")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_RESERV_TEMPTBL
Language        =Rus
_MC("Table reservation %1 or %2 in TPB cannot be applied to %3 because it's a temporary table")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_READTXN_AFTER_WRITELOCK
Language        =Rus
_MC("Cannot set the transaction in read only mode after a table reservation isc_tpb_lock_write in TPB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TPB_WRITELOCK_AFTER_READTXN
Language        =Rus
_MC("Cannot take a table reservation isc_tpb_lock_write in TPB because the transaction is in read only mode")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TIME_RANGE_EXCEEDED
Language        =Rus
_MC("value exceeds the range for a valid time")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DATETIME_RANGE_EXCEEDED
Language        =Rus
_MC("value exceeds the range for valid timestamps")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__STRING_TRUNCATION
Language        =Rus
_MC("string right truncation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BLOB_TRUNCATION
Language        =Rus
_MC("blob truncation when converting to a string: length limit exceeded")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NUMERIC_OUT_OF_RANGE
Language        =Rus
_MC("numeric value is out of range")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SHUTDOWN_TIMEOUT
Language        =Rus
_MC("Firebird shutdown is still in progress after the specified timeout")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ATT_HANDLE_BUSY
Language        =Rus
_MC("Attachment handle is busy")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_UDF_FREEIT
Language        =Rus
_MC("Bad written UDF detected: pointer returned in FREE_IT function was not allocated by ib_util_malloc")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_PROVIDER_NOT_FOUND
Language        =Rus
_MC("External Data Source provider '%1' not found")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_CONNECTION
Language        =Rus
_MC("Execute statement error at %1 :\n"
    "%2Data source : %3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_PREPROCESS
Language        =Rus
_MC("Execute statement preprocess SQL error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_STMT_EXPECTED
Language        =Rus
_MC("Statement expected")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_PRM_NAME_EXPECTED
Language        =Rus
_MC("Parameter name expected")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_UNCLOSED_COMMENT
Language        =Rus
_MC("Unclosed comment found near '%1'")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_STATEMENT
Language        =Rus
_MC("Execute statement error at %1 :\n"
    "%2Statement : %3\n"
    "Data source : %4")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_INPUT_PRM_MISMATCH
Language        =Rus
_MC("Input parameters mismatch")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_OUTPUT_PRM_MISMATCH
Language        =Rus
_MC("Output parameters mismatch")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_INPUT_PRM_NOT_SET
Language        =Rus
_MC("Input parameter '%1' have no value set")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__TOO_BIG_BLR
Language        =Rus
_MC("BLR stream length %1 exceeds implementation limit %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MONTABEXH
Language        =Rus
_MC("Monitoring table space exhausted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MODNOTFOUND
Language        =Rus
_MC("module name or entrypoint could not be found")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NOTHING_TO_CANCEL
Language        =Rus
_MC("nothing to cancel")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__IBUTIL_NOT_LOADED
Language        =Rus
_MC("ib_util library has not been loaded to deallocate memory returned by FREE_IT function")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__CIRCULAR_COMPUTED
Language        =Rus
_MC("Cannot have circular dependencies with computed fields")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PSW_DB_ERROR
Language        =Rus
_MC("Security database error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_TYPE_DATETIME_OP
Language        =Rus
_MC("Invalid data type in DATE/TIME/TIMESTAMP addition or subtraction in add_datettime()")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ONLYCAN_ADD_TIMETODATE
Language        =Rus
_MC("Only a TIME value can be added to a DATE value")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ONLYCAN_ADD_DATETOTIME
Language        =Rus
_MC("Only a DATE value can be added to a TIME value")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ONLYCANSUB_TSTAMPFROMTSTAMP
Language        =Rus
_MC("TIMESTAMP values can be subtracted only from another TIMESTAMP value")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ONLYONEOP_MUSTBE_TSTAMP
Language        =Rus
_MC("Only one operand can be of type TIMESTAMP")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_EXTRACTPART_TIME
Language        =Rus
_MC("Only HOUR, MINUTE, SECOND and MILLISECOND can be extracted from TIME values")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_EXTRACTPART_DATE
Language        =Rus
_MC("HOUR, MINUTE, SECOND and MILLISECOND cannot be extracted from DATE values")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALIDARG_EXTRACT
Language        =Rus
_MC("Invalid argument for EXTRACT() not being of DATE/TIME/TIMESTAMP type")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_EXACT
Language        =Rus
_MC("Arguments for %1 must be integral types or NUMERIC/DECIMAL without scale")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_EXACT_OR_FP
Language        =Rus
_MC("First argument for %1 must be integral type or floating point type")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_UUIDTYPE
Language        =Rus
_MC("Human readable UUID argument for %1 must be of string type")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_UUIDLEN
Language        =Rus
_MC("Human readable UUID argument for %2 must be of exact length %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_UUIDFMT
Language        =Rus
_MC("Human readable UUID argument for %3 must have \"-\" at position %2 instead of \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_GUIDIGITS
Language        =Rus
_MC("Human readable UUID argument for %3 must have hex digit at position %2 instead of \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADDPART_TIME
Language        =Rus
_MC("Only HOUR, MINUTE, SECOND and MILLISECOND can be added to TIME values in %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADD_DATETIME
Language        =Rus
_MC("Invalid data type in addition of part to DATE/TIME/TIMESTAMP in %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADDPART_DTIME
Language        =Rus
_MC("Invalid part %1 to be added to a DATE/TIME/TIMESTAMP value in %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADD_DTIME_RC
Language        =Rus
_MC("Expected DATE/TIME/TIMESTAMP type in evlDateAdd() result")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_DIFF_DTIME
Language        =Rus
_MC("Expected DATE/TIME/TIMESTAMP type as first and second argument to %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_TIMEDIFF
Language        =Rus
_MC("The result of TIME-<value> in %1 cannot be expressed in YEAR, MONTH, DAY or WEEK")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_TSTAMPTIMEDIFF
Language        =Rus
_MC("The result of TIME-TIMESTAMP or TIMESTAMP-TIME in %1 cannot be expressed in HOUR, MINUTE, SECOND or MILLISECOND")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_DATETIMEDIFF
Language        =Rus
_MC("The result of DATE-TIME or TIME-DATE in %1 cannot be expressed in HOUR, MINUTE, SECOND and MILLISECOND")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_DIFFPART
Language        =Rus
_MC("Invalid part %1 to express the difference between two DATE/TIME/TIMESTAMP values in %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_POSITIVE
Language        =Rus
_MC("Argument for %1 must be positive")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_BASEMUSTBE_POSITIVE
Language        =Rus
_MC("Base for %1 must be positive")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGNMUSTBE_NONNEG
Language        =Rus
_MC("Argument #%1 for %2 must be zero or positive")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGNMUSTBE_POSITIVE
Language        =Rus
_MC("Argument #%1 for %2 must be positive")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ZEROPOWNEG
Language        =Rus
_MC("Base for %1 cannot be zero if exponent is negative")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_NEGPOWFP
Language        =Rus
_MC("Base for %1 cannot be negative if exponent is not an integral value")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_INVALID_SCALE
Language        =Rus
_MC("The numeric scale must be between -128 and 127 in %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_NONNEG
Language        =Rus
_MC("Argument for %1 must be zero or positive")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_BINUUID_MUSTBE_STR
Language        =Rus
_MC("Binary UUID argument for %1 must be of string type")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_BINUUID_WRONGSIZE
Language        =Rus
_MC("Binary UUID argument for %2 must use %1 bytes")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MISSING_REQUIRED_SPB
Language        =Rus
_MC("Missing required item %1 in service parameter block")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NET_SERVER_SHUTDOWN
Language        =Rus
_MC("%1 server is shutdown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_CONN_STR
Language        =Rus
_MC("Invalid connection string")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__BAD_EPB_FORM
Language        =Rus
_MC("Unrecognized events block")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_THREADS
Language        =Rus
_MC("Could not start first worker thread - shutdown server")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NET_EVENT_CONNECT_TIMEOUT
Language        =Rus
_MC("Timeout occurred while waiting for a secondary connection for event processing")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_NONZERO
Language        =Rus
_MC("Argument for %1 must be different than zero")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_RANGE_INC1_1
Language        =Rus
_MC("Argument for %1 must be in the range [-1, 1]")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_GTEQ_ONE
Language        =Rus
_MC("Argument for %1 must be greater or equal than one")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_RANGE_EXC1_1
Language        =Rus
_MC("Argument for %1 must be in the range ]-1, 1[")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INTERNAL_REJECTED_PARAMS
Language        =Rus
_MC("Incorrect parameters provided to internal function %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SYSF_FP_OVERFLOW
Language        =Rus
_MC("Floating point overflow in built-in function %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UDF_FP_OVERFLOW
Language        =Rus
_MC("Floating point overflow in result from UDF %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UDF_FP_NAN
Language        =Rus
_MC("Invalid floating point value returned by UDF %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INSTANCE_CONFLICT
Language        =Rus
_MC("Database is probably already opened by another engine instance in another Windows session")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__OUT_OF_TEMP_SPACE
Language        =Rus
_MC("No free space found in temporary directories")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__EDS_EXPL_TRAN_CTRL
Language        =Rus
_MC("Explicit transaction control is not allowed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__NO_TRUSTED_SPB
Language        =Rus
_MC("Use of TRUSTED switches in spb_command_line is prohibited")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__ASYNC_ACTIVE
Language        =Rus
_MC("Asynchronous call is already running for this attachment")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_DB_NAME
Language        =Rus
_MC("data base file name (%1) already given")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_INVALID_SW
Language        =Rus
_MC("invalid switch %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_INCMP_SW
Language        =Rus
_MC("incompatible switch combination")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_REPLAY_REQ
Language        =Rus
_MC("replay log pathname required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_PGBUF_REQ
Language        =Rus
_MC("number of page buffers for cache required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_VAL_REQ
Language        =Rus
_MC("numeric value required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_PVAL_REQ
Language        =Rus
_MC("positive numeric value required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_TRN_REQ
Language        =Rus
_MC("number of transactions per sweep required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_FULL_REQ
Language        =Rus
_MC("\"full\" or \"reserve\" required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_USRNAME_REQ
Language        =Rus
_MC("user name required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_PASS_REQ
Language        =Rus
_MC("password required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_SUBS_NAME
Language        =Rus
_MC("subsystem name")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_WAL_REQ
Language        =Rus
_MC("\"wal\" required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_SEC_REQ
Language        =Rus
_MC("number of seconds required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_NVAL_REQ
Language        =Rus
_MC("numeric value between 0 and 32767 inclusive required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_TYPE_SHUT
Language        =Rus
_MC("must specify type of shutdown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_RETRY
Language        =Rus
_MC("please retry, specifying an option")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_RETRY_DB
Language        =Rus
_MC("please retry, giving a database name")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_EXCEED_MAX
Language        =Rus
_MC("internal block exceeds maximum size")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_CORRUPT_POOL
Language        =Rus
_MC("corrupt pool")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_MEM_EXHAUSTED
Language        =Rus
_MC("virtual memory exhausted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_BAD_POOL
Language        =Rus
_MC("bad pool id")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_TRN_NOT_VALID
Language        =Rus
_MC("Transaction state %1 not in valid range.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_UNEXP_EOI
Language        =Rus
_MC("unexpected end of input")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_RECON_FAIL
Language        =Rus
_MC("failed to reconnect to a transaction in database %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_TRN_UNKNOWN
Language        =Rus
_MC("Transaction description item unknown")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_MODE_REQ
Language        =Rus
_MC("\"read_only\" or \"read_write\" required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GFIX_PZVAL_REQ
Language        =Rus
_MC("positive or zero numeric value required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DBKEY_FROM_NON_TABLE
Language        =Rus
_MC("Cannot SELECT RDB$DB_KEY from a stored procedure.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_TRANSITIONAL_NUMERIC
Language        =Rus
_MC("Precision 10 to 18 changed from DOUBLE PRECISION in SQL dialect 1 to 64-bit scaled integer in SQL dialect 3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DIALECT_WARNING_EXPR
Language        =Rus
_MC("Use of %1 expression that returns different results in dialect 1 and dialect 3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SQL_DB_DIALECT_DTYPE_UNSUPPORT
Language        =Rus
_MC("Database SQL dialect %1 does not support reference to %2 datatype")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__SQL_DIALECT_CONFLICT_NUM
Language        =Rus
_MC("DB dialect %1 and client dialect %2 conflict with respect to numeric precision %3.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_WARNING_NUMBER_AMBIGUOUS
Language        =Rus
_MC("WARNING: Numeric literal %1 is interpreted as a floating-point")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_WARNING_NUMBER_AMBIGUOUS1
Language        =Rus
_MC("value in SQL dialect 1, but as an exact numeric value in SQL dialect 3.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_WARN_PRECISION_AMBIGUOUS
Language        =Rus
_MC("WARNING: NUMERIC and DECIMAL fields with precision 10 or greater are stored")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_WARN_PRECISION_AMBIGUOUS1
Language        =Rus
_MC("as approximate floating-point values in SQL dialect 1, but as 64-bit")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_WARN_PRECISION_AMBIGUOUS2
Language        =Rus
_MC("integers in SQL dialect 3.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_AMBIGUOUS_FIELD_NAME
Language        =Rus
_MC("Ambiguous field name between %1 and %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_UDF_RETURN_POS_ERR
Language        =Rus
_MC("External function should have return position between 1 and %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INVALID_LABEL
Language        =Rus
_MC("Label %1 %2 in the current scope")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DATATYPES_NOT_COMPARABLE
Language        =Rus
_MC("Datatypes %1are not comparable in expression %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_INVALID
Language        =Rus
_MC("Empty cursor name is not allowed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_REDEFINED
Language        =Rus
_MC("Statement already has a cursor %1 assigned")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_NOT_FOUND
Language        =Rus
_MC("Cursor %1 is not found in the current context")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_EXISTS
Language        =Rus
_MC("Cursor %1 already exists in the current context")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_REL_AMBIGUOUS
Language        =Rus
_MC("Relation %1 is ambiguous in cursor %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_REL_NOT_FOUND
Language        =Rus
_MC("Relation %1 is not found in cursor %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_NOT_OPEN
Language        =Rus
_MC("Cursor is not open")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_TYPE_NOT_SUPP_EXT_TAB
Language        =Rus
_MC("Data type %1 is not supported for EXTERNAL TABLES. Relation '%2', field '%3'")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_FEATURE_NOT_SUPPORTED_ODS
Language        =Rus
_MC("Feature not supported on ODS version older than %1.%2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_REQUIRED
Language        =Rus
_MC("Primary key required on table %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UPD_INS_DOESNT_MATCH_PK
Language        =Rus
_MC("UPDATE OR INSERT field list does not match primary key of table %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UPD_INS_DOESNT_MATCH_MATCHING
Language        =Rus
_MC("UPDATE OR INSERT field list does not match MATCHING clause")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UPD_INS_WITH_COMPLEX_VIEW
Language        =Rus
_MC("UPDATE OR INSERT without MATCHING could not be used with views based on more than one table")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INCOMPATIBLE_TRIGGER_TYPE
Language        =Rus
_MC("Incompatible trigger type")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DB_TRIGGER_TYPE_CANT_CHANGE
Language        =Rus
_MC("Database trigger type can't be changed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_DUP_TABLE
Language        =Rus
_MC("Table %1 already exists")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_COLUMN_DOES_NOT_EXIST
Language        =Rus
_MC("column %1 does not exist in table/view %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_ROLE_DOES_NOT_EXIST
Language        =Rus
_MC("SQL role %1 does not exist")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_NO_GRANT_ADMIN_OPT
Language        =Rus
_MC("user %1 has no grant admin option on SQL role %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_USER_NOT_ROLE_MEMBER
Language        =Rus
_MC("user %1 is not a member of SQL role %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_DELETE_ROLE_FAILED
Language        =Rus
_MC("%1 is not the owner of SQL role %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_GRANT_ROLE_TO_USER
Language        =Rus
_MC("%1 is a SQL role and not a user")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_INV_SQL_ROLE_NAME
Language        =Rus
_MC("user name %1 could not be used for SQL role")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_DUP_SQL_ROLE
Language        =Rus
_MC("SQL role %1 already exists")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_KYWD_SPEC_FOR_ROLE
Language        =Rus
_MC("keyword %1 can not be used as a SQL role name")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_ROLES_NOT_SUPPORTED
Language        =Rus
_MC("SQL roles are not supported in on older versions of the database.  A backup and restore of the database is required.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_DOMAIN_NAME_EXISTS
Language        =Rus
_MC("Cannot rename domain %1 to %2.  A domain with that name already exists.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_FIELD_NAME_EXISTS
Language        =Rus
_MC("Cannot rename column %1 to %2.  A column with that name already exists in table %3.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_DEPENDENCY_EXISTS
Language        =Rus
_MC("Column %1 from table %2 is referenced in %3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_DTYPE_INVALID
Language        =Rus
_MC("Cannot change datatype for column %1.  Changing datatype is not supported for BLOB or ARRAY columns.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_CHAR_FLD_TOO_SMALL
Language        =Rus
_MC("New size specified for column %1 must be at least %2 characters.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_INVALID_DTYPE_CONVERSION
Language        =Rus
_MC("Cannot change datatype for %1.  Conversion from base type %2 to %3 is not supported.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_DTYPE_CONV_INVALID
Language        =Rus
_MC("Cannot change datatype for column %1 from a character type to a non-character type.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_ZERO_LEN_ID
Language        =Rus
_MC("Zero length identifiers are not allowed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__MAX_COLL_PER_CHARSET
Language        =Rus
_MC("Maximum number of collations per character set exceeded")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__INVALID_COLL_ATTR
Language        =Rus
_MC("Invalid collation attributes")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_WRONG_GTT_SCOPE
Language        =Rus
_MC("%1 cannot reference %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_SCALE_TOO_BIG
Language        =Rus
_MC("New scale specified for column %1 must be at most %2.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_PRECISION_TOO_SMALL
Language        =Rus
_MC("New precision specified for column %1 must be at least %2.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_MISS_PRIV_WARNING
Language        =Rus
_MC("Warning: %1 on %2 is not granted to %3.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_ODS_NOT_SUPP_FEATURE
Language        =Rus
_MC("Feature '%1' is not supported in ODS %2.%3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_CANNOT_ADDREM_COMPUTED
Language        =Rus
_MC("Cannot add or remove COMPUTED from column %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_NO_EMPTY_PW
Language        =Rus
_MC("Password should not be empty string")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DYN_DUP_INDEX
Language        =Rus
_MC("Index %1 already exists")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_UNKNOWN_SWITCH
Language        =Rus
_MC("found unknown switch")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_PAGE_SIZE_MISSING
Language        =Rus
_MC("page size parameter missing")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_PAGE_SIZE_TOOBIG
Language        =Rus
_MC("Page size specified (%1) greater than limit (16384 bytes)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_REDIR_OUPUT_MISSING
Language        =Rus
_MC("redirect location for output is not specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_SWITCHES_CONFLICT
Language        =Rus
_MC("conflicting switches for backup/restore")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_UNKNOWN_DEVICE
Language        =Rus
_MC("device type %1 not known")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_NO_PROTECTION
Language        =Rus
_MC("protection is not there yet")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_PAGE_SIZE_NOT_ALLOWED
Language        =Rus
_MC("page size is allowed only on restore or create")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_MULTI_SOURCE_DEST
Language        =Rus
_MC("multiple sources or destinations specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_FILENAME_MISSING
Language        =Rus
_MC("requires both input and output filenames")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_DUP_INOUT_NAMES
Language        =Rus
_MC("input and output have the same name.  Disallowed.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_INV_PAGE_SIZE
Language        =Rus
_MC("expected page size, encountered \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_DB_SPECIFIED
Language        =Rus
_MC("REPLACE specified, but the first file %1 is a database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_DB_EXISTS
Language        =Rus
_MC("database %1 already exists.  To replace it, use the -REP switch")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_UNK_DEVICE
Language        =Rus
_MC("device type not specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_BLOB_INFO_FAILED
Language        =Rus
_MC("gds_$blob_info failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_UNK_BLOB_ITEM
Language        =Rus
_MC("do not understand BLOB INFO item %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_GET_SEG_FAILED
Language        =Rus
_MC("gds_$get_segment failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_CLOSE_BLOB_FAILED
Language        =Rus
_MC("gds_$close_blob failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_OPEN_BLOB_FAILED
Language        =Rus
_MC("gds_$open_blob failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_PUT_BLR_GEN_ID_FAILED
Language        =Rus
_MC("Failed in put_blr_gen_id")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_UNK_TYPE
Language        =Rus
_MC("data type %1 not understood")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_COMP_REQ_FAILED
Language        =Rus
_MC("gds_$compile_request failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_START_REQ_FAILED
Language        =Rus
_MC("gds_$start_request failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_REC_FAILED
Language        =Rus
_MC("gds_$receive failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_REL_REQ_FAILED
Language        =Rus
_MC("gds_$release_request failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_DB_INFO_FAILED
Language        =Rus
_MC("gds_$database_info failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_NO_DB_DESC
Language        =Rus
_MC("Expected database description record")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_DB_CREATE_FAILED
Language        =Rus
_MC("failed to create database %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_DECOMP_LEN_ERROR
Language        =Rus
_MC("RESTORE: decompression length error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_TBL_MISSING
Language        =Rus
_MC("cannot find table %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_BLOB_COL_MISSING
Language        =Rus
_MC("Cannot find column for BLOB")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_CREATE_BLOB_FAILED
Language        =Rus
_MC("gds_$create_blob failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_PUT_SEG_FAILED
Language        =Rus
_MC("gds_$put_segment failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_REC_LEN_EXP
Language        =Rus
_MC("expected record length")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_INV_REC_LEN
Language        =Rus
_MC("wrong length record, expected %1 encountered %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_EXP_DATA_TYPE
Language        =Rus
_MC("expected data attribute")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_GEN_ID_FAILED
Language        =Rus
_MC("Failed in store_blr_gen_id")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_UNK_REC_TYPE
Language        =Rus
_MC("do not recognize record type %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_INV_BKUP_VER
Language        =Rus
_MC("Expected backup version 1..9.  Found %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_MISSING_BKUP_DESC
Language        =Rus
_MC("expected backup description record")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_STRING_TRUNC
Language        =Rus
_MC("string truncated")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_CANT_REST_RECORD
Language        =Rus
_MC("warning -- record could not be restored")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_SEND_FAILED
Language        =Rus
_MC("gds_$send failed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_NO_TBL_NAME
Language        =Rus
_MC("no table name for data")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_UNEXP_EOF
Language        =Rus
_MC("unexpected end of file on backup file")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_DB_FORMAT_TOO_OLD
Language        =Rus
_MC("database format %1 is too old to restore to")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_INV_ARRAY_DIM
Language        =Rus
_MC("array dimension for column %1 is invalid")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_XDR_LEN_EXPECTED
Language        =Rus
_MC("Expected XDR record length")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_OPEN_BKUP_ERROR
Language        =Rus
_MC("cannot open backup file %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_OPEN_ERROR
Language        =Rus
_MC("cannot open status and error output file %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_MISSING_BLOCK_FAC
Language        =Rus
_MC("blocking factor parameter missing")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_INV_BLOCK_FAC
Language        =Rus
_MC("expected blocking factor, encountered \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_BLOCK_FAC_SPECIFIED
Language        =Rus
_MC("a blocking factor may not be used in conjunction with device CT")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_MISSING_USERNAME
Language        =Rus
_MC("user name parameter missing")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_MISSING_PASSWORD
Language        =Rus
_MC("password parameter missing")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_MISSING_SKIPPED_BYTES
Language        =Rus
_MC("missing parameter for the number of bytes to be skipped")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_INV_SKIPPED_BYTES
Language        =Rus
_MC("expected number of bytes to be skipped, encountered \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_ERR_RESTORE_CHARSET
Language        =Rus
_MC("character set")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_ERR_RESTORE_COLLATION
Language        =Rus
_MC("collation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_READ_ERROR
Language        =Rus
_MC("Unexpected I/O error while reading from backup file")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_WRITE_ERROR
Language        =Rus
_MC("Unexpected I/O error while writing to backup file")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_DB_IN_USE
Language        =Rus
_MC("could not drop database %1 (database might be in use)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_SYSMEMEX
Language        =Rus
_MC("System memory exhausted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_RESTORE_ROLE_FAILED
Language        =Rus
_MC("SQL role")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_ROLE_OP_MISSING
Language        =Rus
_MC("SQL role parameter missing")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_PAGE_BUFFERS_MISSING
Language        =Rus
_MC("page buffers parameter missing")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_PAGE_BUFFERS_WRONG_PARAM
Language        =Rus
_MC("expected page buffers, encountered \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_PAGE_BUFFERS_RESTORE
Language        =Rus
_MC("page buffers is allowed only on restore or create")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_INV_SIZE
Language        =Rus
_MC("size specification either missing or incorrect for file %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_FILE_OUTOF_SEQUENCE
Language        =Rus
_MC("file %1 out of sequence")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_JOIN_FILE_MISSING
Language        =Rus
_MC("can't join -- one of the files missing")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_STDIN_NOT_SUPPTD
Language        =Rus
_MC("standard input is not supported when using join operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_STDOUT_NOT_SUPPTD
Language        =Rus
_MC("standard output is not supported when using split operation or in verbose mode")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_BKUP_CORRUPT
Language        =Rus
_MC("backup file %1 might be corrupt")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_UNK_DB_FILE_SPEC
Language        =Rus
_MC("database file specification missing")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_HDR_WRITE_FAILED
Language        =Rus
_MC("can't write a header record to file %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_DISK_SPACE_EX
Language        =Rus
_MC("free disk space exhausted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_SIZE_LT_MIN
Language        =Rus
_MC("file size given (%1) is less than minimum allowed (%2)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_SVC_NAME_MISSING
Language        =Rus
_MC("service name parameter missing")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_NOT_OWNR
Language        =Rus
_MC("Cannot restore over current database, must be SYSDBA or owner of the existing database.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_MODE_REQ
Language        =Rus
_MC("\"read_only\" or \"read_write\" required")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_JUST_DATA
Language        =Rus
_MC("just data ignore all constraints etc.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_DATA_ONLY
Language        =Rus
_MC("restoring data only ignoring foreign key, unique, not null & other constraints")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_INVALID_METADATA
Language        =Rus
_MC("Invalid metadata detected. Use -FIX_FSS_METADATA option.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GBAK_INVALID_DATA
Language        =Rus
_MC("Invalid data detected. Use -FIX_FSS_DATA option.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_TOO_OLD_ODS
Language        =Rus
_MC("ODS versions before ODS%1 are not supported")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_TABLE_NOT_FOUND
Language        =Rus
_MC("Table %1 does not exist")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_VIEW_NOT_FOUND
Language        =Rus
_MC("View %1 does not exist")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_LINE_COL_ERROR
Language        =Rus
_MC("At line %1, column %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_UNKNOWN_POS
Language        =Rus
_MC("At unknown line and column")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_NO_DUP_NAME
Language        =Rus
_MC("Column %1 cannot be repeated in %2 statement")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_TOO_MANY_VALUES
Language        =Rus
_MC("Too many values (more than %1) in member list to match against")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_NO_ARRAY_COMPUTED
Language        =Rus
_MC("Array and BLOB data types not allowed in computed field")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_IMPLICIT_DOMAIN_NAME
Language        =Rus
_MC("Implicit domain name %1 not allowed in user created domain")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_ONLY_CAN_SUBSCRIPT_ARRAY
Language        =Rus
_MC("scalar operator used on field %1 which is not an array")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_MAX_SORT_ITEMS
Language        =Rus
_MC("cannot sort on more than 255 items")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_MAX_GROUP_ITEMS
Language        =Rus
_MC("cannot group on more than 255 items")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CONFLICTING_SORT_FIELD
Language        =Rus
_MC("Cannot include the same field (%1.%2) twice in the ORDER BY clause with conflicting sorting options")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_TABLE_MORE_COLUMNS
Language        =Rus
_MC("column list from derived table %1 has more columns than the number of items in its SELECT statement")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_TABLE_LESS_COLUMNS
Language        =Rus
_MC("column list from derived table %1 has less columns than the number of items in its SELECT statement")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_FIELD_UNNAMED
Language        =Rus
_MC("no column name specified for column number %1 in derived table %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_FIELD_DUP_NAME
Language        =Rus
_MC("column %1 was specified multiple times for derived table %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_ALIAS_SELECT
Language        =Rus
_MC("Internal dsql error: alias type expected by pass1_expand_select_node")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_ALIAS_FIELD
Language        =Rus
_MC("Internal dsql error: alias type expected by pass1_field")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_AUTO_FIELD_BAD_POS
Language        =Rus
_MC("Internal dsql error: column position out of range in pass1_union_auto_cast")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_WRONG_REFERENCE
Language        =Rus
_MC("Recursive CTE member (%1) can refer itself only in FROM clause")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_CYCLE
Language        =Rus
_MC("CTE '%1' has cyclic dependencies")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_OUTER_JOIN
Language        =Rus
_MC("Recursive member of CTE can't be member of an outer join")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_MULT_REFERENCES
Language        =Rus
_MC("Recursive member of CTE can't reference itself more than once")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_NOT_A_UNION
Language        =Rus
_MC("Recursive CTE (%1) must be an UNION")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_NONRECURS_AFTER_RECURS
Language        =Rus
_MC("CTE '%1' defined non-recursive member after recursive")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_WRONG_CLAUSE
Language        =Rus
_MC("Recursive member of CTE '%1' has %2 clause")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_UNION_ALL
Language        =Rus
_MC("Recursive members of CTE (%1) must be linked with another members via UNION ALL")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_MISS_NONRECURSIVE
Language        =Rus
_MC("Non-recursive member is missing in CTE '%1'")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_NESTED_WITH
Language        =Rus
_MC("WITH clause can't be nested")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_COL_MORE_THAN_ONCE_USING
Language        =Rus
_MC("column %1 appears more than once in USING clause")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_UNSUPP_FEATURE_DIALECT
Language        =Rus
_MC("feature is not supported in dialect %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_CTE_NOT_USED
Language        =Rus
_MC("CTE \"%1\" is not used in query")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_COL_MORE_THAN_ONCE_VIEW
Language        =Rus
_MC("column %1 appears more than once in ALTER VIEW")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_UNSUPPORTED_IN_AUTO_TRANS
Language        =Rus
_MC("%1 is not supported inside IN AUTONOMOUS TRANSACTION block")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_EVAL_UNKNODE
Language        =Rus
_MC("Unknown node type %1 in dsql/GEN_expr")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_AGG_WRONGARG
Language        =Rus
_MC("Argument for %1 in dialect 1 must be string or numeric")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_AGG2_WRONGARG
Language        =Rus
_MC("Argument for %1 in dialect 3 must be numeric")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_NODATEORTIME_PM_STRING
Language        =Rus
_MC("Strings cannot be added to or subtracted from DATE or TIME types")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INVALID_DATETIME_SUBTRACT
Language        =Rus
_MC("Invalid data type for subtraction involving DATE, TIME or TIMESTAMP types")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INVALID_DATEORTIME_ADD
Language        =Rus
_MC("Adding two DATE values or two TIME values is not allowed")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_MINUS_DATE
Language        =Rus
_MC("DATE value cannot be subtracted from the provided data type")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_ADDSUB_DIAL3
Language        =Rus
_MC("Strings cannot be added or subtracted in dialect 3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_ADDSUB_DIAL3
Language        =Rus
_MC("Invalid data type for addition or subtraction in dialect 3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_MULTIP_DIAL1
Language        =Rus
_MC("Invalid data type for multiplication in dialect 1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_MULTIP_DIAL3
Language        =Rus
_MC("Strings cannot be multiplied in dialect 3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_MULTIP_DIAL3
Language        =Rus
_MC("Invalid data type for multiplication in dialect 3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_MUSTUSE_NUMERIC_DIV_DIAL1
Language        =Rus
_MC("Division in dialect 1 must be between numeric data types")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_DIV_DIAL3
Language        =Rus
_MC("Strings cannot be divided in dialect 3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_DIV_DIAL3
Language        =Rus
_MC("Invalid data type for division in dialect 3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_NEG_DIAL3
Language        =Rus
_MC("Strings cannot be negated (applied the minus operator) in dialect 3")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_NEG
Language        =Rus
_MC("Invalid data type for negation (minus operator)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__DSQL_MAX_DISTINCT_ITEMS
Language        =Rus
_MC("Cannot have more than 255 items in DISTINCT list")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_CANT_OPEN_DB
Language        =Rus
_MC("unable to open database")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_SWITCHES_ERROR
Language        =Rus
_MC("error in switch specifications")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_NO_OP_SPEC
Language        =Rus
_MC("no operation specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_NO_USR_NAME
Language        =Rus
_MC("no user name specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_ERR_ADD
Language        =Rus
_MC("add record error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_ERR_MODIFY
Language        =Rus
_MC("modify record error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_ERR_FIND_MOD
Language        =Rus
_MC("find/modify record error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_ERR_REC_NOT_FOUND
Language        =Rus
_MC("record not found for user: %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_ERR_DELETE
Language        =Rus
_MC("delete record error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_ERR_FIND_DEL
Language        =Rus
_MC("find/delete record error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_ERR_FIND_DISP
Language        =Rus
_MC("find/display record error")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_INV_PARAM
Language        =Rus
_MC("invalid parameter, no switch defined")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_OP_SPECIFIED
Language        =Rus
_MC("operation already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_PW_SPECIFIED
Language        =Rus
_MC("password already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_UID_SPECIFIED
Language        =Rus
_MC("uid already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_GID_SPECIFIED
Language        =Rus
_MC("gid already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_PROJ_SPECIFIED
Language        =Rus
_MC("project already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_ORG_SPECIFIED
Language        =Rus
_MC("organization already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_FNAME_SPECIFIED
Language        =Rus
_MC("first name already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_MNAME_SPECIFIED
Language        =Rus
_MC("middle name already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_LNAME_SPECIFIED
Language        =Rus
_MC("last name already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_INV_SWITCH
Language        =Rus
_MC("invalid switch specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_AMB_SWITCH
Language        =Rus
_MC("ambiguous switch specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_NO_OP_SPECIFIED
Language        =Rus
_MC("no operation specified for parameters")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_PARAMS_NOT_ALLOWED
Language        =Rus
_MC("no parameters allowed for this operation")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_INCOMPAT_SWITCH
Language        =Rus
_MC("incompatible switches specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_INV_USERNAME
Language        =Rus
_MC("Invalid user name (maximum 31 bytes allowed)")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_INV_PW_LENGTH
Language        =Rus
_MC("Warning - maximum 8 significant bytes of password used")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_DB_SPECIFIED
Language        =Rus
_MC("database already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_DB_ADMIN_SPECIFIED
Language        =Rus
_MC("database administrator name already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_DB_ADMIN_PW_SPECIFIED
Language        =Rus
_MC("database administrator password already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSEC_SQL_ROLE_SPECIFIED
Language        =Rus
_MC("SQL role name already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_NO_FILE
Language        =Rus
_MC("The license file does not exist or could not be opened for read")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_OP_SPECIFIED
Language        =Rus
_MC("operation already specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_OP_MISSING
Language        =Rus
_MC("no operation specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_INV_SWITCH
Language        =Rus
_MC("invalid switch")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_INV_SWITCH_COMBO
Language        =Rus
_MC("invalid switch combination")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_INV_OP_COMBO
Language        =Rus
_MC("illegal operation/switch combination")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_AMB_SWITCH
Language        =Rus
_MC("ambiguous switch")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_INV_PARAMETER
Language        =Rus
_MC("invalid parameter, no switch specified")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_PARAM_SPECIFIED
Language        =Rus
_MC("switch does not take any parameter")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_PARAM_REQ
Language        =Rus
_MC("switch requires a parameter")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_SYNTX_ERROR
Language        =Rus
_MC("syntax error in command line")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_DUP_ID
Language        =Rus
_MC("The certificate was not added.  A duplicate ID exists in the license file.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_INV_ID_KEY
Language        =Rus
_MC("The certificate was not added.  Invalid certificate ID / Key combination.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_ERR_REMOVE
Language        =Rus
_MC("The certificate was not removed.  The key does not exist or corresponds to a temporary evaluation license.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_ERR_UPDATE
Language        =Rus
_MC("An error occurred updating the license file.  Operation cancelled.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_ERR_CONVERT
Language        =Rus
_MC("The certificate could not be validated based on the information given.  Please recheck the ID and key information.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_ERR_UNK
Language        =Rus
_MC("Operation failed.  An unknown error occurred.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_SVC_ERR_ADD
Language        =Rus
_MC("Add license operation failed, KEY: %1 ID: %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_SVC_ERR_REMOVE
Language        =Rus
_MC("Remove license operation failed, KEY: %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__LICENSE_EVAL_EXISTS
Language        =Rus
_MC("The evaluation license has already been used on this server.  You need to purchase a non-evaluation license.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSTAT_UNKNOWN_SWITCH
Language        =Rus
_MC("found unknown switch")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSTAT_RETRY
Language        =Rus
_MC("please retry, giving a database name")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSTAT_WRONG_ODS
Language        =Rus
_MC("Wrong ODS version, expected %1, encountered %2")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSTAT_UNEXPECTED_EOF
Language        =Rus
_MC("Unexpected end of database file.")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSTAT_OPEN_ERR
Language        =Rus
_MC("Can't open database file %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSTAT_READ_ERR
Language        =Rus
_MC("Can't read a database page")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__GSTAT_SYSMEMEX
Language        =Rus
_MC("System memory exhausted")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_BAD_AM
Language        =Rus
_MC("Wrong value for access mode")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_BAD_WM
Language        =Rus
_MC("Wrong value for write mode")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_BAD_RS
Language        =Rus
_MC("Wrong value for reserve space")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_INFO_ERR
Language        =Rus
_MC("Unknown tag (%1) in info_svr_db_info block after isc_svc_query()")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_QUERY_ERR
Language        =Rus
_MC("Unknown tag (%1) in isc_svc_query() results")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_SWITCH_UNKNOWN
Language        =Rus
_MC("Unknown switch \"%1\"")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_BAD_SM
Language        =Rus
_MC("Wrong value for shutdown mode")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_FP_OPEN
Language        =Rus
_MC("could not open file %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_FP_READ
Language        =Rus
_MC("could not read file %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_FP_EMPTY
Language        =Rus
_MC("empty file %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__FBSVCMGR_BAD_ARG
Language        =Rus
_MC("Invalid or missing parameter for switch %1")
.

//------------------------------------------------------------------------
MessageId       =IBP_MCE_FB25__UTL_TRUSTED_SWITCH
Language        =Rus
_MC("Switches trusted_svc and trusted_role are not supported from command line")
.

////////////////////////////////////////////////////////////////////////////////
