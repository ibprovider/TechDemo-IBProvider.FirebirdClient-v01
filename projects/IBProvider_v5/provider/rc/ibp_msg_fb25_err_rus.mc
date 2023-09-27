////////////////////////////////////////////////////////////////////////////////
//IBProvider resources. Firebird 2.5 Error Messages. Russian.
//Machine generated file [26.09.2023 11:37:06]
//                                                             Dmitry Kovalenko.
#include "ibp_msg_fb25_err_ids.rh"

////////////////////////////////////////////////////////////////////////////////
LanguageNames=(Rus=0x0419:IBP_MSG_FB25_ERR_RUS)

////////////////////////////////////////////////////////////////////////////////

/*1*/
MessageId       =IBP_MCE_FB25__ARITH_EXCEPT
Language        =Rus
_MC("arithmetic exception, numeric overflow, or string truncation")
.

//------------------------------------------------------------------------
/*2*/
MessageId       =IBP_MCE_FB25__BAD_DBKEY
Language        =Rus
_MC("invalid database key")
.

//------------------------------------------------------------------------
/*3*/
MessageId       =IBP_MCE_FB25__BAD_DB_FORMAT
Language        =Rus
_MC("file %1 is not a valid database")
.

//------------------------------------------------------------------------
/*4*/
MessageId       =IBP_MCE_FB25__BAD_DB_HANDLE
Language        =Rus
_MC("Недействительный дескриптор базы данных (нет активного подключения).")
.

//------------------------------------------------------------------------
/*5*/
MessageId       =IBP_MCE_FB25__BAD_DPB_CONTENT
Language        =Rus
_MC("bad parameters on attach or create database")
.

//------------------------------------------------------------------------
/*6*/
MessageId       =IBP_MCE_FB25__BAD_DPB_FORM
Language        =Rus
_MC("unrecognized database parameter block")
.

//------------------------------------------------------------------------
/*7*/
MessageId       =IBP_MCE_FB25__BAD_REQ_HANDLE
Language        =Rus
_MC("Недействительный дескриптор запроса.")
.

//------------------------------------------------------------------------
/*8*/
MessageId       =IBP_MCE_FB25__BAD_SEGSTR_HANDLE
Language        =Rus
_MC("Недействительный дескриптор блоба.")
.

//------------------------------------------------------------------------
/*9*/
MessageId       =IBP_MCE_FB25__BAD_SEGSTR_ID
Language        =Rus
_MC("Недействительный BLOB ID.")
.

//------------------------------------------------------------------------
/*10*/
MessageId       =IBP_MCE_FB25__BAD_TPB_CONTENT
Language        =Rus
_MC("invalid parameter in transaction parameter block")
.

//------------------------------------------------------------------------
/*11*/
MessageId       =IBP_MCE_FB25__BAD_TPB_FORM
Language        =Rus
_MC("Некорректная структура блока с параметрами транзакции")
.

//------------------------------------------------------------------------
/*12*/
MessageId       =IBP_MCE_FB25__BAD_TRANS_HANDLE
Language        =Rus
_MC("Недействительный дескриптор транзакции (ожидается явный старт транзакции).")
.

//------------------------------------------------------------------------
/*13*/
MessageId       =IBP_MCE_FB25__BUG_CHECK
Language        =Rus
_MC("internal Firebird consistency check (%1)")
.

//------------------------------------------------------------------------
/*14*/
MessageId       =IBP_MCE_FB25__CONVERT_ERROR
Language        =Rus
_MC("conversion error from string \"%1\"")
.

//------------------------------------------------------------------------
/*15*/
MessageId       =IBP_MCE_FB25__DB_CORRUPT
Language        =Rus
_MC("database file appears corrupt (%1)")
.

//------------------------------------------------------------------------
/*16*/
MessageId       =IBP_MCE_FB25__DEADLOCK
Language        =Rus
_MC("deadlock")
.

//------------------------------------------------------------------------
/*17*/
MessageId       =IBP_MCE_FB25__EXCESS_TRANS
Language        =Rus
_MC("attempt to start more than %1 transactions")
.

//------------------------------------------------------------------------
/*18*/
MessageId       =IBP_MCE_FB25__FROM_NO_MATCH
Language        =Rus
_MC("no match for first value expression")
.

//------------------------------------------------------------------------
/*19*/
MessageId       =IBP_MCE_FB25__INFINAP
Language        =Rus
_MC("information type inappropriate for object specified")
.

//------------------------------------------------------------------------
/*20*/
MessageId       =IBP_MCE_FB25__INFONA
Language        =Rus
_MC("no information of this type available for object specified")
.

//------------------------------------------------------------------------
/*21*/
MessageId       =IBP_MCE_FB25__INFUNK
Language        =Rus
_MC("unknown information item")
.

//------------------------------------------------------------------------
/*22*/
MessageId       =IBP_MCE_FB25__INTEG_FAIL
Language        =Rus
_MC("action cancelled by trigger (%1) to preserve data integrity")
.

//------------------------------------------------------------------------
/*23*/
MessageId       =IBP_MCE_FB25__INVALID_BLR
Language        =Rus
_MC("invalid request BLR at offset %1")
.

//------------------------------------------------------------------------
/*24*/
MessageId       =IBP_MCE_FB25__IO_ERROR
Language        =Rus
_MC("I/O ошибка в процессе выполнения операции \"%1\" для файла \"%2\".")
.

//------------------------------------------------------------------------
/*25*/
MessageId       =IBP_MCE_FB25__LOCK_CONFLICT
Language        =Rus
_MC("lock conflict on no wait transaction")
.

//------------------------------------------------------------------------
/*26*/
MessageId       =IBP_MCE_FB25__METADATA_CORRUPT
Language        =Rus
_MC("corrupt system table")
.

//------------------------------------------------------------------------
/*27*/
MessageId       =IBP_MCE_FB25__NOT_VALID
Language        =Rus
_MC("validation error for column %1, value \"%2\"")
.

//------------------------------------------------------------------------
/*28*/
MessageId       =IBP_MCE_FB25__NO_CUR_REC
Language        =Rus
_MC("no current record for fetch operation")
.

//------------------------------------------------------------------------
/*29*/
MessageId       =IBP_MCE_FB25__NO_DUP
Language        =Rus
_MC("attempt to store duplicate value (visible to active transactions) in unique index \"%1\"")
.

//------------------------------------------------------------------------
/*30*/
MessageId       =IBP_MCE_FB25__NO_FINISH
Language        =Rus
_MC("program attempted to exit without finishing database")
.

//------------------------------------------------------------------------
/*31*/
MessageId       =IBP_MCE_FB25__NO_META_UPDATE
Language        =Rus
_MC("unsuccessful metadata update")
.

//------------------------------------------------------------------------
/*32*/
MessageId       =IBP_MCE_FB25__NO_PRIV
Language        =Rus
_MC("no permission for %1 access to %2 %3")
.

//------------------------------------------------------------------------
/*33*/
MessageId       =IBP_MCE_FB25__NO_RECON
Language        =Rus
_MC("transaction is not in limbo")
.

//------------------------------------------------------------------------
/*34*/
MessageId       =IBP_MCE_FB25__NO_RECORD
Language        =Rus
_MC("invalid database key")
.

//------------------------------------------------------------------------
/*35*/
MessageId       =IBP_MCE_FB25__NO_SEGSTR_CLOSE
Language        =Rus
_MC("BLOB was not closed")
.

//------------------------------------------------------------------------
/*36*/
MessageId       =IBP_MCE_FB25__OBSOLETE_METADATA
Language        =Rus
_MC("metadata is obsolete")
.

//------------------------------------------------------------------------
/*37*/
MessageId       =IBP_MCE_FB25__OPEN_TRANS
Language        =Rus
_MC("Нельзя отключать базу данных с незавершенными транзакциями (количество: %1).")
.

//------------------------------------------------------------------------
/*38*/
MessageId       =IBP_MCE_FB25__PORT_LEN
Language        =Rus
_MC("message length error (encountered %1, expected %2)")
.

//------------------------------------------------------------------------
/*39*/
MessageId       =IBP_MCE_FB25__READ_ONLY_FIELD
Language        =Rus
_MC("attempted update of read-only column")
.

//------------------------------------------------------------------------
/*40*/
MessageId       =IBP_MCE_FB25__READ_ONLY_REL
Language        =Rus
_MC("attempted update of read-only table")
.

//------------------------------------------------------------------------
/*41*/
MessageId       =IBP_MCE_FB25__READ_ONLY_TRANS
Language        =Rus
_MC("attempted update during read-only transaction")
.

//------------------------------------------------------------------------
/*42*/
MessageId       =IBP_MCE_FB25__READ_ONLY_VIEW
Language        =Rus
_MC("cannot update read-only view %1")
.

//------------------------------------------------------------------------
/*43*/
MessageId       =IBP_MCE_FB25__REQ_NO_TRANS
Language        =Rus
_MC("no transaction for request")
.

//------------------------------------------------------------------------
/*44*/
MessageId       =IBP_MCE_FB25__REQ_SYNC
Language        =Rus
_MC("request synchronization error")
.

//------------------------------------------------------------------------
/*45*/
MessageId       =IBP_MCE_FB25__REQ_WRONG_DB
Language        =Rus
_MC("request referenced an unavailable database")
.

//------------------------------------------------------------------------
/*46*/
MessageId       =IBP_MCE_FB25__SEGMENT
Language        =Rus
_MC("segment buffer length shorter than expected")
.

//------------------------------------------------------------------------
/*47*/
MessageId       =IBP_MCE_FB25__SEGSTR_EOF
Language        =Rus
_MC("attempted retrieval of more segments than exist")
.

//------------------------------------------------------------------------
/*48*/
MessageId       =IBP_MCE_FB25__SEGSTR_NO_OP
Language        =Rus
_MC("attempted invalid operation on a BLOB")
.

//------------------------------------------------------------------------
/*49*/
MessageId       =IBP_MCE_FB25__SEGSTR_NO_READ
Language        =Rus
_MC("attempted read of a new, open BLOB")
.

//------------------------------------------------------------------------
/*50*/
MessageId       =IBP_MCE_FB25__SEGSTR_NO_TRANS
Language        =Rus
_MC("attempted action on BLOB outside transaction")
.

//------------------------------------------------------------------------
/*51*/
MessageId       =IBP_MCE_FB25__SEGSTR_NO_WRITE
Language        =Rus
_MC("attempted write to read-only BLOB")
.

//------------------------------------------------------------------------
/*52*/
MessageId       =IBP_MCE_FB25__SEGSTR_WRONG_DB
Language        =Rus
_MC("attempted reference to BLOB in unavailable database")
.

//------------------------------------------------------------------------
/*53*/
MessageId       =IBP_MCE_FB25__SYS_REQUEST
Language        =Rus
_MC("operating system directive %1 failed")
.

//------------------------------------------------------------------------
/*54*/
MessageId       =IBP_MCE_FB25__STREAM_EOF
Language        =Rus
_MC("attempt to fetch past the last record in a record stream")
.

//------------------------------------------------------------------------
/*55*/
MessageId       =IBP_MCE_FB25__UNAVAILABLE
Language        =Rus
_MC("unavailable database")
.

//------------------------------------------------------------------------
/*56*/
MessageId       =IBP_MCE_FB25__UNRES_REL
Language        =Rus
_MC("table %1 was omitted from the transaction reserving list")
.

//------------------------------------------------------------------------
/*57*/
MessageId       =IBP_MCE_FB25__UNS_EXT
Language        =Rus
_MC("request includes a DSRI extension not supported in this implementation")
.

//------------------------------------------------------------------------
/*58*/
MessageId       =IBP_MCE_FB25__WISH_LIST
Language        =Rus
_MC("feature is not supported")
.

//------------------------------------------------------------------------
/*59*/
MessageId       =IBP_MCE_FB25__WRONG_ODS
Language        =Rus
_MC("unsupported on-disk structure for file %1; found %2.%3, support %4.%5")
.

//------------------------------------------------------------------------
/*60*/
MessageId       =IBP_MCE_FB25__WRONUMARG
Language        =Rus
_MC("wrong number of arguments on call")
.

//------------------------------------------------------------------------
/*61*/
MessageId       =IBP_MCE_FB25__IMP_EXC
Language        =Rus
_MC("Implementation limit exceeded")
.

//------------------------------------------------------------------------
/*62*/
MessageId       =IBP_MCE_FB25__RANDOM
Language        =Rus
_MC("%1")
.

//------------------------------------------------------------------------
/*63*/
MessageId       =IBP_MCE_FB25__FATAL_CONFLICT
Language        =Rus
_MC("unrecoverable conflict with limbo transaction %1")
.

//------------------------------------------------------------------------
/*64*/
MessageId       =IBP_MCE_FB25__BADBLK
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*65*/
MessageId       =IBP_MCE_FB25__INVPOOLCL
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*66*/
MessageId       =IBP_MCE_FB25__NOPOOLIDS
Language        =Rus
_MC("too many requests")
.

//------------------------------------------------------------------------
/*67*/
MessageId       =IBP_MCE_FB25__RELBADBLK
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*68*/
MessageId       =IBP_MCE_FB25__BLKTOOBIG
Language        =Rus
_MC("block size exceeds implementation restriction")
.

//------------------------------------------------------------------------
/*69*/
MessageId       =IBP_MCE_FB25__BUFEXH
Language        =Rus
_MC("buffer exhausted")
.

//------------------------------------------------------------------------
/*70*/
MessageId       =IBP_MCE_FB25__SYNTAXERR
Language        =Rus
_MC("BLR syntax error: expected %1 at offset %2, encountered %3")
.

//------------------------------------------------------------------------
/*71*/
MessageId       =IBP_MCE_FB25__BUFINUSE
Language        =Rus
_MC("buffer in use")
.

//------------------------------------------------------------------------
/*72*/
MessageId       =IBP_MCE_FB25__BDBINCON
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*73*/
MessageId       =IBP_MCE_FB25__REQINUSE
Language        =Rus
_MC("request in use")
.

//------------------------------------------------------------------------
/*74*/
MessageId       =IBP_MCE_FB25__BADODSVER
Language        =Rus
_MC("incompatible version of on-disk structure")
.

//------------------------------------------------------------------------
/*75*/
MessageId       =IBP_MCE_FB25__RELNOTDEF
Language        =Rus
_MC("таблица %1 не определена")
.

//------------------------------------------------------------------------
/*76*/
MessageId       =IBP_MCE_FB25__FLDNOTDEF
Language        =Rus
_MC("колонка %1 не определена в таблице %2")
.

//------------------------------------------------------------------------
/*77*/
MessageId       =IBP_MCE_FB25__DIRTYPAGE
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*78*/
MessageId       =IBP_MCE_FB25__WAIFORTRA
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*79*/
MessageId       =IBP_MCE_FB25__DOUBLELOC
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*80*/
MessageId       =IBP_MCE_FB25__NODNOTFND
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*81*/
MessageId       =IBP_MCE_FB25__DUPNODFND
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*82*/
MessageId       =IBP_MCE_FB25__LOCNOTMAR
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*83*/
MessageId       =IBP_MCE_FB25__BADPAGTYP
Language        =Rus
_MC("page %1 is of wrong type (expected %2, found %3)")
.

//------------------------------------------------------------------------
/*84*/
MessageId       =IBP_MCE_FB25__CORRUPT
Language        =Rus
_MC("database corrupted")
.

//------------------------------------------------------------------------
/*85*/
MessageId       =IBP_MCE_FB25__BADPAGE
Language        =Rus
_MC("checksum error on database page %1")
.

//------------------------------------------------------------------------
/*86*/
MessageId       =IBP_MCE_FB25__BADINDEX
Language        =Rus
_MC("index is broken")
.

//------------------------------------------------------------------------
/*87*/
MessageId       =IBP_MCE_FB25__DBBNOTZER
Language        =Rus
_MC("Ненулевой дескриптор базы данных")
.

//------------------------------------------------------------------------
/*88*/
MessageId       =IBP_MCE_FB25__TRANOTZER
Language        =Rus
_MC("Ненулевой дескриптор транзакции")
.

//------------------------------------------------------------------------
/*89*/
MessageId       =IBP_MCE_FB25__TRAREQMIS
Language        =Rus
_MC("transaction--request mismatch (synchronization error)")
.

//------------------------------------------------------------------------
/*90*/
MessageId       =IBP_MCE_FB25__BADHNDCNT
Language        =Rus
_MC("bad handle count")
.

//------------------------------------------------------------------------
/*91*/
MessageId       =IBP_MCE_FB25__WROTPBVER
Language        =Rus
_MC("Недействительная версия структуры блока с параметрами транзакции")
.

//------------------------------------------------------------------------
/*92*/
MessageId       =IBP_MCE_FB25__WROBLRVER
Language        =Rus
_MC("unsupported BLR version (expected %1, encountered %2)")
.

//------------------------------------------------------------------------
/*93*/
MessageId       =IBP_MCE_FB25__WRODPBVER
Language        =Rus
_MC("wrong version of database parameter block")
.

//------------------------------------------------------------------------
/*94*/
MessageId       =IBP_MCE_FB25__BLOBNOTSUP
Language        =Rus
_MC("BLOB and array data types are not supported for %1 operation")
.

//------------------------------------------------------------------------
/*95*/
MessageId       =IBP_MCE_FB25__BADRELATION
Language        =Rus
_MC("database corrupted")
.

//------------------------------------------------------------------------
/*96*/
MessageId       =IBP_MCE_FB25__NODETACH
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*97*/
MessageId       =IBP_MCE_FB25__NOTREMOTE
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*98*/
MessageId       =IBP_MCE_FB25__TRAINLIM
Language        =Rus
_MC("transaction in limbo")
.

//------------------------------------------------------------------------
/*99*/
MessageId       =IBP_MCE_FB25__NOTINLIM
Language        =Rus
_MC("transaction not in limbo")
.

//------------------------------------------------------------------------
/*100*/
MessageId       =IBP_MCE_FB25__TRAOUTSTA
Language        =Rus
_MC("transaction outstanding")
.

//------------------------------------------------------------------------
/*101*/
MessageId       =IBP_MCE_FB25__CONNECT_REJECT
Language        =Rus
_MC("connection rejected by remote interface")
.

//------------------------------------------------------------------------
/*102*/
MessageId       =IBP_MCE_FB25__DBFILE
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*103*/
MessageId       =IBP_MCE_FB25__ORPHAN
Language        =Rus
_MC("internal error")
.

//------------------------------------------------------------------------
/*104*/
MessageId       =IBP_MCE_FB25__NO_LOCK_MGR
Language        =Rus
_MC("no lock manager available")
.

//------------------------------------------------------------------------
/*105*/
MessageId       =IBP_MCE_FB25__CTXINUSE
Language        =Rus
_MC("context already in use (BLR error)")
.

//------------------------------------------------------------------------
/*106*/
MessageId       =IBP_MCE_FB25__CTXNOTDEF
Language        =Rus
_MC("context not defined (BLR error)")
.

//------------------------------------------------------------------------
/*107*/
MessageId       =IBP_MCE_FB25__DATNOTSUP
Language        =Rus
_MC("data operation not supported")
.

//------------------------------------------------------------------------
/*108*/
MessageId       =IBP_MCE_FB25__BADMSGNUM
Language        =Rus
_MC("undefined message number")
.

//------------------------------------------------------------------------
/*109*/
MessageId       =IBP_MCE_FB25__BADPARNUM
Language        =Rus
_MC("bad parameter number")
.

//------------------------------------------------------------------------
/*110*/
MessageId       =IBP_MCE_FB25__VIRMEMEXH
Language        =Rus
_MC("unable to allocate memory from operating system")
.

//------------------------------------------------------------------------
/*111*/
MessageId       =IBP_MCE_FB25__BLOCKING_SIGNAL
Language        =Rus
_MC("blocking signal has been received")
.

//------------------------------------------------------------------------
/*112*/
MessageId       =IBP_MCE_FB25__LOCKMANERR
Language        =Rus
_MC("lock manager error")
.

//------------------------------------------------------------------------
/*113*/
MessageId       =IBP_MCE_FB25__JOURNERR
Language        =Rus
_MC("communication error with journal \"%1\"")
.

//------------------------------------------------------------------------
/*114*/
MessageId       =IBP_MCE_FB25__KEYTOOBIG
Language        =Rus
_MC("key size exceeds implementation restriction for index \"%1\"")
.

//------------------------------------------------------------------------
/*115*/
MessageId       =IBP_MCE_FB25__NULLSEGKEY
Language        =Rus
_MC("null segment of UNIQUE KEY")
.

//------------------------------------------------------------------------
/*116*/
MessageId       =IBP_MCE_FB25__SQLERR
Language        =Rus
_MC("SQL error code = %1")
.

//------------------------------------------------------------------------
/*117*/
MessageId       =IBP_MCE_FB25__WRODYNVER
Language        =Rus
_MC("wrong DYN version")
.

//------------------------------------------------------------------------
/*118*/
MessageId       =IBP_MCE_FB25__FUNNOTDEF
Language        =Rus
_MC("function %1 is not defined")
.

//------------------------------------------------------------------------
/*119*/
MessageId       =IBP_MCE_FB25__FUNMISMAT
Language        =Rus
_MC("function %1 could not be matched")
.

//------------------------------------------------------------------------
/*120*/
MessageId       =IBP_MCE_FB25__BAD_MSG_VEC
Language        =Rus
_MC("")
.

//------------------------------------------------------------------------
/*121*/
MessageId       =IBP_MCE_FB25__BAD_DETACH
Language        =Rus
_MC("database detach completed with errors")
.

//------------------------------------------------------------------------
/*122*/
MessageId       =IBP_MCE_FB25__NOARGACC_READ
Language        =Rus
_MC("database system cannot read argument %1")
.

//------------------------------------------------------------------------
/*123*/
MessageId       =IBP_MCE_FB25__NOARGACC_WRITE
Language        =Rus
_MC("database system cannot write argument %1")
.

//------------------------------------------------------------------------
/*124*/
MessageId       =IBP_MCE_FB25__READ_ONLY
Language        =Rus
_MC("operation not supported")
.

//------------------------------------------------------------------------
/*125*/
MessageId       =IBP_MCE_FB25__EXT_ERR
Language        =Rus
_MC("%1 extension error")
.

//------------------------------------------------------------------------
/*126*/
MessageId       =IBP_MCE_FB25__NON_UPDATABLE
Language        =Rus
_MC("not updatable")
.

//------------------------------------------------------------------------
/*127*/
MessageId       =IBP_MCE_FB25__NO_ROLLBACK
Language        =Rus
_MC("no rollback performed")
.

//------------------------------------------------------------------------
/*128*/
MessageId       =IBP_MCE_FB25__BAD_SEC_INFO
Language        =Rus
_MC("")
.

//------------------------------------------------------------------------
/*129*/
MessageId       =IBP_MCE_FB25__INVALID_SEC_INFO
Language        =Rus
_MC("")
.

//------------------------------------------------------------------------
/*130*/
MessageId       =IBP_MCE_FB25__MISC_INTERPRETED
Language        =Rus
_MC("%1")
.

//------------------------------------------------------------------------
/*131*/
MessageId       =IBP_MCE_FB25__UPDATE_CONFLICT
Language        =Rus
_MC("update conflicts with concurrent update")
.

//------------------------------------------------------------------------
/*132*/
MessageId       =IBP_MCE_FB25__UNLICENSED
Language        =Rus
_MC("product %1 is not licensed")
.

//------------------------------------------------------------------------
/*133*/
MessageId       =IBP_MCE_FB25__OBJ_IN_USE
Language        =Rus
_MC("object %1 is in use")
.

//------------------------------------------------------------------------
/*134*/
MessageId       =IBP_MCE_FB25__NOFILTER
Language        =Rus
_MC("filter not found to convert type %1 to type %2")
.

//------------------------------------------------------------------------
/*135*/
MessageId       =IBP_MCE_FB25__SHADOW_ACCESSED
Language        =Rus
_MC("cannot attach active shadow file")
.

//------------------------------------------------------------------------
/*136*/
MessageId       =IBP_MCE_FB25__INVALID_SDL
Language        =Rus
_MC("invalid slice description language at offset %1")
.

//------------------------------------------------------------------------
/*137*/
MessageId       =IBP_MCE_FB25__OUT_OF_BOUNDS
Language        =Rus
_MC("subscript out of bounds")
.

//------------------------------------------------------------------------
/*138*/
MessageId       =IBP_MCE_FB25__INVALID_DIMENSION
Language        =Rus
_MC("column not array or invalid dimensions (expected %1, encountered %2)")
.

//------------------------------------------------------------------------
/*139*/
MessageId       =IBP_MCE_FB25__REC_IN_LIMBO
Language        =Rus
_MC("record from transaction %1 is stuck in limbo")
.

//------------------------------------------------------------------------
/*140*/
MessageId       =IBP_MCE_FB25__SHADOW_MISSING
Language        =Rus
_MC("a file in manual shadow %1 is unavailable")
.

//------------------------------------------------------------------------
/*141*/
MessageId       =IBP_MCE_FB25__CANT_VALIDATE
Language        =Rus
_MC("secondary server attachments cannot validate databases")
.

//------------------------------------------------------------------------
/*142*/
MessageId       =IBP_MCE_FB25__CANT_START_JOURNAL
Language        =Rus
_MC("secondary server attachments cannot start journaling")
.

//------------------------------------------------------------------------
/*143*/
MessageId       =IBP_MCE_FB25__GENNOTDEF
Language        =Rus
_MC("generator %1 is not defined")
.

//------------------------------------------------------------------------
/*144*/
MessageId       =IBP_MCE_FB25__CANT_START_LOGGING
Language        =Rus
_MC("secondary server attachments cannot start logging")
.

//------------------------------------------------------------------------
/*145*/
MessageId       =IBP_MCE_FB25__BAD_SEGSTR_TYPE
Language        =Rus
_MC("invalid BLOB type for operation")
.

//------------------------------------------------------------------------
/*146*/
MessageId       =IBP_MCE_FB25__FOREIGN_KEY
Language        =Rus
_MC("violation of FOREIGN KEY constraint \"%1\" on table \"%2\"")
.

//------------------------------------------------------------------------
/*147*/
MessageId       =IBP_MCE_FB25__HIGH_MINOR
Language        =Rus
_MC("minor version too high found %1 expected %2")
.

//------------------------------------------------------------------------
/*148*/
MessageId       =IBP_MCE_FB25__TRA_STATE
Language        =Rus
_MC("transaction %1 is %2")
.

//------------------------------------------------------------------------
/*149*/
MessageId       =IBP_MCE_FB25__TRANS_INVALID
Language        =Rus
_MC("transaction marked invalid by I/O error")
.

//------------------------------------------------------------------------
/*150*/
MessageId       =IBP_MCE_FB25__BUF_INVALID
Language        =Rus
_MC("cache buffer for page %1 invalid")
.

//------------------------------------------------------------------------
/*151*/
MessageId       =IBP_MCE_FB25__INDEXNOTDEFINED
Language        =Rus
_MC("there is no index in table %1 with id %2")
.

//------------------------------------------------------------------------
/*152*/
MessageId       =IBP_MCE_FB25__LOGIN
Language        =Rus
_MC("Ваши имя пользователя и пароль не определены. Попросите администратора базы данных предоставить логин к Firebird.")
.

//------------------------------------------------------------------------
/*153*/
MessageId       =IBP_MCE_FB25__INVALID_BOOKMARK
Language        =Rus
_MC("invalid bookmark handle")
.

//------------------------------------------------------------------------
/*154*/
MessageId       =IBP_MCE_FB25__BAD_LOCK_LEVEL
Language        =Rus
_MC("invalid lock level %1")
.

//------------------------------------------------------------------------
/*155*/
MessageId       =IBP_MCE_FB25__RELATION_LOCK
Language        =Rus
_MC("lock on table %1 conflicts with existing lock")
.

//------------------------------------------------------------------------
/*156*/
MessageId       =IBP_MCE_FB25__RECORD_LOCK
Language        =Rus
_MC("requested record lock conflicts with existing lock")
.

//------------------------------------------------------------------------
/*157*/
MessageId       =IBP_MCE_FB25__MAX_IDX
Language        =Rus
_MC("maximum indexes per table (%1) exceeded")
.

//------------------------------------------------------------------------
/*158*/
MessageId       =IBP_MCE_FB25__JRN_ENABLE
Language        =Rus
_MC("enable journal for database before starting online dump")
.

//------------------------------------------------------------------------
/*159*/
MessageId       =IBP_MCE_FB25__OLD_FAILURE
Language        =Rus
_MC("online dump failure. Retry dump")
.

//------------------------------------------------------------------------
/*160*/
MessageId       =IBP_MCE_FB25__OLD_IN_PROGRESS
Language        =Rus
_MC("an online dump is already in progress")
.

//------------------------------------------------------------------------
/*161*/
MessageId       =IBP_MCE_FB25__OLD_NO_SPACE
Language        =Rus
_MC("no more disk/tape space. Cannot continue online dump")
.

//------------------------------------------------------------------------
/*162*/
MessageId       =IBP_MCE_FB25__NO_WAL_NO_JRN
Language        =Rus
_MC("journaling allowed only if database has Write-ahead Log")
.

//------------------------------------------------------------------------
/*163*/
MessageId       =IBP_MCE_FB25__NUM_OLD_FILES
Language        =Rus
_MC("maximum number of online dump files that can be specified is 16")
.

//------------------------------------------------------------------------
/*164*/
MessageId       =IBP_MCE_FB25__WAL_FILE_OPEN
Language        =Rus
_MC("error in opening Write-ahead Log file during recovery")
.

//------------------------------------------------------------------------
/*165*/
MessageId       =IBP_MCE_FB25__BAD_STMT_HANDLE
Language        =Rus
_MC("invalid statement handle")
.

//------------------------------------------------------------------------
/*166*/
MessageId       =IBP_MCE_FB25__WAL_FAILURE
Language        =Rus
_MC("Write-ahead log subsystem failure")
.

//------------------------------------------------------------------------
/*167*/
MessageId       =IBP_MCE_FB25__WALW_ERR
Language        =Rus
_MC("WAL Writer error")
.

//------------------------------------------------------------------------
/*168*/
MessageId       =IBP_MCE_FB25__LOGH_SMALL
Language        =Rus
_MC("Log file header of %1 too small")
.

//------------------------------------------------------------------------
/*169*/
MessageId       =IBP_MCE_FB25__LOGH_INV_VERSION
Language        =Rus
_MC("Invalid version of log file %1")
.

//------------------------------------------------------------------------
/*170*/
MessageId       =IBP_MCE_FB25__LOGH_OPEN_FLAG
Language        =Rus
_MC("Log file %1 not latest in the chain but open flag still set")
.

//------------------------------------------------------------------------
/*171*/
MessageId       =IBP_MCE_FB25__LOGH_OPEN_FLAG2
Language        =Rus
_MC("Log file %1 not closed properly; database recovery may be required")
.

//------------------------------------------------------------------------
/*172*/
MessageId       =IBP_MCE_FB25__LOGH_DIFF_DBNAME
Language        =Rus
_MC("Database name in the log file %1 is different")
.

//------------------------------------------------------------------------
/*173*/
MessageId       =IBP_MCE_FB25__LOGF_UNEXPECTED_EOF
Language        =Rus
_MC("Unexpected end of log file %1 at offset %2")
.

//------------------------------------------------------------------------
/*174*/
MessageId       =IBP_MCE_FB25__LOGR_INCOMPLETE
Language        =Rus
_MC("Incomplete log record at offset %1 in log file %2")
.

//------------------------------------------------------------------------
/*175*/
MessageId       =IBP_MCE_FB25__LOGR_HEADER_SMALL
Language        =Rus
_MC("Log record header too small at offset %1 in log file %2")
.

//------------------------------------------------------------------------
/*176*/
MessageId       =IBP_MCE_FB25__LOGB_SMALL
Language        =Rus
_MC("Log block too small at offset %1 in log file %2")
.

//------------------------------------------------------------------------
/*177*/
MessageId       =IBP_MCE_FB25__WAL_ILLEGAL_ATTACH
Language        =Rus
_MC("Illegal attempt to attach to an uninitialized WAL segment for %1")
.

//------------------------------------------------------------------------
/*178*/
MessageId       =IBP_MCE_FB25__WAL_INVALID_WPB
Language        =Rus
_MC("Invalid WAL parameter block option %1")
.

//------------------------------------------------------------------------
/*179*/
MessageId       =IBP_MCE_FB25__WAL_ERR_ROLLOVER
Language        =Rus
_MC("Cannot roll over to the next log file %1")
.

//------------------------------------------------------------------------
/*180*/
MessageId       =IBP_MCE_FB25__NO_WAL
Language        =Rus
_MC("database does not use Write-ahead Log")
.

//------------------------------------------------------------------------
/*181*/
MessageId       =IBP_MCE_FB25__DROP_WAL
Language        =Rus
_MC("cannot drop log file when journaling is enabled")
.

//------------------------------------------------------------------------
/*182*/
MessageId       =IBP_MCE_FB25__STREAM_NOT_DEFINED
Language        =Rus
_MC("reference to invalid stream number")
.

//------------------------------------------------------------------------
/*183*/
MessageId       =IBP_MCE_FB25__WAL_SUBSYS_ERROR
Language        =Rus
_MC("WAL subsystem encountered error")
.

//------------------------------------------------------------------------
/*184*/
MessageId       =IBP_MCE_FB25__WAL_SUBSYS_CORRUPT
Language        =Rus
_MC("WAL subsystem corrupted")
.

//------------------------------------------------------------------------
/*185*/
MessageId       =IBP_MCE_FB25__NO_ARCHIVE
Language        =Rus
_MC("must specify archive file when enabling long term journal for databases with round-robin log files")
.

//------------------------------------------------------------------------
/*186*/
MessageId       =IBP_MCE_FB25__SHUTINPROG
Language        =Rus
_MC("database %1 shutdown in progress")
.

//------------------------------------------------------------------------
/*187*/
MessageId       =IBP_MCE_FB25__RANGE_IN_USE
Language        =Rus
_MC("refresh range number %1 already in use")
.

//------------------------------------------------------------------------
/*188*/
MessageId       =IBP_MCE_FB25__RANGE_NOT_FOUND
Language        =Rus
_MC("refresh range number %1 not found")
.

//------------------------------------------------------------------------
/*189*/
MessageId       =IBP_MCE_FB25__CHARSET_NOT_FOUND
Language        =Rus
_MC("CHARACTER SET %1 is not defined")
.

//------------------------------------------------------------------------
/*190*/
MessageId       =IBP_MCE_FB25__LOCK_TIMEOUT
Language        =Rus
_MC("lock time-out on wait transaction")
.

//------------------------------------------------------------------------
/*191*/
MessageId       =IBP_MCE_FB25__PRCNOTDEF
Language        =Rus
_MC("procedure %1 is not defined")
.

//------------------------------------------------------------------------
/*192*/
MessageId       =IBP_MCE_FB25__PRCMISMAT
Language        =Rus
_MC("Input parameter mismatch for procedure %1")
.

//------------------------------------------------------------------------
/*193*/
MessageId       =IBP_MCE_FB25__WAL_BUGCHECK
Language        =Rus
_MC("Database %1: WAL subsystem bug for pid %2\n"
    "%3")
.

//------------------------------------------------------------------------
/*194*/
MessageId       =IBP_MCE_FB25__WAL_CANT_EXPAND
Language        =Rus
_MC("Could not expand the WAL segment for database %1")
.

//------------------------------------------------------------------------
/*195*/
MessageId       =IBP_MCE_FB25__CODNOTDEF
Language        =Rus
_MC("status code %1 unknown")
.

//------------------------------------------------------------------------
/*196*/
MessageId       =IBP_MCE_FB25__XCPNOTDEF
Language        =Rus
_MC("exception %1 not defined")
.

//------------------------------------------------------------------------
/*197*/
MessageId       =IBP_MCE_FB25__EXCEPT
Language        =Rus
_MC("exception %1")
.

//------------------------------------------------------------------------
/*198*/
MessageId       =IBP_MCE_FB25__CACHE_RESTART
Language        =Rus
_MC("restart shared cache manager")
.

//------------------------------------------------------------------------
/*199*/
MessageId       =IBP_MCE_FB25__BAD_LOCK_HANDLE
Language        =Rus
_MC("invalid lock handle")
.

//------------------------------------------------------------------------
/*200*/
MessageId       =IBP_MCE_FB25__JRN_PRESENT
Language        =Rus
_MC("long-term journaling already enabled")
.

//------------------------------------------------------------------------
/*201*/
MessageId       =IBP_MCE_FB25__WAL_ERR_ROLLOVER2
Language        =Rus
_MC("Unable to roll over please see Firebird log.")
.

//------------------------------------------------------------------------
/*202*/
MessageId       =IBP_MCE_FB25__WAL_ERR_LOGWRITE
Language        =Rus
_MC("WAL I/O error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*203*/
MessageId       =IBP_MCE_FB25__WAL_ERR_JRN_COMM
Language        =Rus
_MC("WAL writer - Journal server communication error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*204*/
MessageId       =IBP_MCE_FB25__WAL_ERR_EXPANSION
Language        =Rus
_MC("WAL buffers cannot be increased. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*205*/
MessageId       =IBP_MCE_FB25__WAL_ERR_SETUP
Language        =Rus
_MC("WAL setup error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*206*/
MessageId       =IBP_MCE_FB25__WAL_ERR_WW_SYNC
Language        =Rus
_MC("obsolete")
.

//------------------------------------------------------------------------
/*207*/
MessageId       =IBP_MCE_FB25__WAL_ERR_WW_START
Language        =Rus
_MC("Cannot start WAL writer for the database %1")
.

//------------------------------------------------------------------------
/*208*/
MessageId       =IBP_MCE_FB25__SHUTDOWN
Language        =Rus
_MC("database %1 shutdown")
.

//------------------------------------------------------------------------
/*209*/
MessageId       =IBP_MCE_FB25__EXISTING_PRIV_MOD
Language        =Rus
_MC("cannot modify an existing user privilege")
.

//------------------------------------------------------------------------
/*210*/
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_REF
Language        =Rus
_MC("Cannot delete PRIMARY KEY being used in FOREIGN KEY definition.")
.

//------------------------------------------------------------------------
/*211*/
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_NOTNULL
Language        =Rus
_MC("Column used in a PRIMARY constraint must be NOT NULL.")
.

//------------------------------------------------------------------------
/*212*/
MessageId       =IBP_MCE_FB25__REF_CNSTRNT_NOTFOUND
Language        =Rus
_MC("Name of Referential Constraint not defined in constraints table.")
.

//------------------------------------------------------------------------
/*213*/
MessageId       =IBP_MCE_FB25__FOREIGN_KEY_NOTFOUND
Language        =Rus
_MC("Non-existent PRIMARY or UNIQUE KEY specified for FOREIGN KEY.")
.

//------------------------------------------------------------------------
/*214*/
MessageId       =IBP_MCE_FB25__REF_CNSTRNT_UPDATE
Language        =Rus
_MC("Cannot update constraints (RDB$REF_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*215*/
MessageId       =IBP_MCE_FB25__CHECK_CNSTRNT_UPDATE
Language        =Rus
_MC("Cannot update constraints (RDB$CHECK_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*216*/
MessageId       =IBP_MCE_FB25__CHECK_CNSTRNT_DEL
Language        =Rus
_MC("Cannot delete CHECK constraint entry (RDB$CHECK_CONSTRAINTS)")
.

//------------------------------------------------------------------------
/*217*/
MessageId       =IBP_MCE_FB25__INTEG_INDEX_SEG_DEL
Language        =Rus
_MC("Cannot delete index segment used by an Integrity Constraint")
.

//------------------------------------------------------------------------
/*218*/
MessageId       =IBP_MCE_FB25__INTEG_INDEX_SEG_MOD
Language        =Rus
_MC("Cannot update index segment used by an Integrity Constraint")
.

//------------------------------------------------------------------------
/*219*/
MessageId       =IBP_MCE_FB25__INTEG_INDEX_DEL
Language        =Rus
_MC("Cannot delete index used by an Integrity Constraint")
.

//------------------------------------------------------------------------
/*220*/
MessageId       =IBP_MCE_FB25__INTEG_INDEX_MOD
Language        =Rus
_MC("Cannot modify index used by an Integrity Constraint")
.

//------------------------------------------------------------------------
/*221*/
MessageId       =IBP_MCE_FB25__CHECK_TRIG_DEL
Language        =Rus
_MC("Cannot delete trigger used by a CHECK Constraint")
.

//------------------------------------------------------------------------
/*222*/
MessageId       =IBP_MCE_FB25__CHECK_TRIG_UPDATE
Language        =Rus
_MC("Cannot update trigger used by a CHECK Constraint")
.

//------------------------------------------------------------------------
/*223*/
MessageId       =IBP_MCE_FB25__CNSTRNT_FLD_DEL
Language        =Rus
_MC("Cannot delete column being used in an Integrity Constraint.")
.

//------------------------------------------------------------------------
/*224*/
MessageId       =IBP_MCE_FB25__CNSTRNT_FLD_RENAME
Language        =Rus
_MC("Cannot rename column being used in an Integrity Constraint.")
.

//------------------------------------------------------------------------
/*225*/
MessageId       =IBP_MCE_FB25__REL_CNSTRNT_UPDATE
Language        =Rus
_MC("Cannot update constraints (RDB$RELATION_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*226*/
MessageId       =IBP_MCE_FB25__CONSTAINT_ON_VIEW
Language        =Rus
_MC("Cannot define constraints on views")
.

//------------------------------------------------------------------------
/*227*/
MessageId       =IBP_MCE_FB25__INVLD_CNSTRNT_TYPE
Language        =Rus
_MC("internal Firebird consistency check (invalid RDB$CONSTRAINT_TYPE)")
.

//------------------------------------------------------------------------
/*228*/
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_EXISTS
Language        =Rus
_MC("Attempt to define a second PRIMARY KEY for the same table")
.

//------------------------------------------------------------------------
/*229*/
MessageId       =IBP_MCE_FB25__SYSTRIG_UPDATE
Language        =Rus
_MC("cannot modify or erase a system trigger")
.

//------------------------------------------------------------------------
/*230*/
MessageId       =IBP_MCE_FB25__NOT_REL_OWNER
Language        =Rus
_MC("only the owner of a table may reassign ownership")
.

//------------------------------------------------------------------------
/*231*/
MessageId       =IBP_MCE_FB25__GRANT_OBJ_NOTFOUND
Language        =Rus
_MC("could not find table/procedure for GRANT")
.

//------------------------------------------------------------------------
/*232*/
MessageId       =IBP_MCE_FB25__GRANT_FLD_NOTFOUND
Language        =Rus
_MC("could not find column for GRANT")
.

//------------------------------------------------------------------------
/*233*/
MessageId       =IBP_MCE_FB25__GRANT_NOPRIV
Language        =Rus
_MC("user does not have GRANT privileges for operation")
.

//------------------------------------------------------------------------
/*234*/
MessageId       =IBP_MCE_FB25__NONSQL_SECURITY_REL
Language        =Rus
_MC("table/procedure has non-SQL security class defined")
.

//------------------------------------------------------------------------
/*235*/
MessageId       =IBP_MCE_FB25__NONSQL_SECURITY_FLD
Language        =Rus
_MC("column has non-SQL security class defined")
.

//------------------------------------------------------------------------
/*236*/
MessageId       =IBP_MCE_FB25__WAL_CACHE_ERR
Language        =Rus
_MC("Write-ahead Log without shared cache configuration not allowed")
.

//------------------------------------------------------------------------
/*237*/
MessageId       =IBP_MCE_FB25__SHUTFAIL
Language        =Rus
_MC("database shutdown unsuccessful")
.

//------------------------------------------------------------------------
/*238*/
MessageId       =IBP_MCE_FB25__CHECK_CONSTRAINT
Language        =Rus
_MC("Operation violates CHECK constraint %1 on view or table %2")
.

//------------------------------------------------------------------------
/*239*/
MessageId       =IBP_MCE_FB25__BAD_SVC_HANDLE
Language        =Rus
_MC("invalid service handle")
.

//------------------------------------------------------------------------
/*240*/
MessageId       =IBP_MCE_FB25__SHUTWARN
Language        =Rus
_MC("database %1 shutdown in %2 seconds")
.

//------------------------------------------------------------------------
/*241*/
MessageId       =IBP_MCE_FB25__WROSPBVER
Language        =Rus
_MC("wrong version of service parameter block")
.

//------------------------------------------------------------------------
/*242*/
MessageId       =IBP_MCE_FB25__BAD_SPB_FORM
Language        =Rus
_MC("unrecognized service parameter block")
.

//------------------------------------------------------------------------
/*243*/
MessageId       =IBP_MCE_FB25__SVCNOTDEF
Language        =Rus
_MC("service %1 is not defined")
.

//------------------------------------------------------------------------
/*244*/
MessageId       =IBP_MCE_FB25__NO_JRN
Language        =Rus
_MC("long-term journaling not enabled")
.

//------------------------------------------------------------------------
/*245*/
MessageId       =IBP_MCE_FB25__TRANSLITERATION_FAILED
Language        =Rus
_MC("Cannot transliterate character between character sets")
.

//------------------------------------------------------------------------
/*246*/
MessageId       =IBP_MCE_FB25__START_CM_FOR_WAL
Language        =Rus
_MC("WAL defined; Cache Manager must be started first")
.

//------------------------------------------------------------------------
/*247*/
MessageId       =IBP_MCE_FB25__WAL_OVFLOW_LOG_REQUIRED
Language        =Rus
_MC("Overflow log specification required for round-robin log")
.

//------------------------------------------------------------------------
/*248*/
MessageId       =IBP_MCE_FB25__TEXT_SUBTYPE
Language        =Rus
_MC("Implementation of text subtype %1 not located.")
.

//------------------------------------------------------------------------
/*249*/
MessageId       =IBP_MCE_FB25__DSQL_ERROR
Language        =Rus
_MC("Dynamic SQL Error")
.

//------------------------------------------------------------------------
/*250*/
MessageId       =IBP_MCE_FB25__DSQL_COMMAND_ERR
Language        =Rus
_MC("Invalid command")
.

//------------------------------------------------------------------------
/*251*/
MessageId       =IBP_MCE_FB25__DSQL_CONSTANT_ERR
Language        =Rus
_MC("Data type for constant unknown")
.

//------------------------------------------------------------------------
/*252*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_ERR
Language        =Rus
_MC("Invalid cursor reference")
.

//------------------------------------------------------------------------
/*253*/
MessageId       =IBP_MCE_FB25__DSQL_DATATYPE_ERR
Language        =Rus
_MC("Data type unknown")
.

//------------------------------------------------------------------------
/*254*/
MessageId       =IBP_MCE_FB25__DSQL_DECL_ERR
Language        =Rus
_MC("Invalid cursor declaration")
.

//------------------------------------------------------------------------
/*255*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_UPDATE_ERR
Language        =Rus
_MC("Cursor %1 is not updatable")
.

//------------------------------------------------------------------------
/*256*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_OPEN_ERR
Language        =Rus
_MC("Attempt to reopen an open cursor")
.

//------------------------------------------------------------------------
/*257*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_CLOSE_ERR
Language        =Rus
_MC("Attempt to reclose a closed cursor")
.

//------------------------------------------------------------------------
/*258*/
MessageId       =IBP_MCE_FB25__DSQL_FIELD_ERR
Language        =Rus
_MC("Column unknown")
.

//------------------------------------------------------------------------
/*259*/
MessageId       =IBP_MCE_FB25__DSQL_INTERNAL_ERR
Language        =Rus
_MC("Internal error")
.

//------------------------------------------------------------------------
/*260*/
MessageId       =IBP_MCE_FB25__DSQL_RELATION_ERR
Language        =Rus
_MC("Table unknown")
.

//------------------------------------------------------------------------
/*261*/
MessageId       =IBP_MCE_FB25__DSQL_PROCEDURE_ERR
Language        =Rus
_MC("Procedure unknown")
.

//------------------------------------------------------------------------
/*262*/
MessageId       =IBP_MCE_FB25__DSQL_REQUEST_ERR
Language        =Rus
_MC("Request unknown")
.

//------------------------------------------------------------------------
/*263*/
MessageId       =IBP_MCE_FB25__DSQL_SQLDA_ERR
Language        =Rus
_MC("SQLDA missing or incorrect version, or incorrect number/type of variables")
.

//------------------------------------------------------------------------
/*264*/
MessageId       =IBP_MCE_FB25__DSQL_VAR_COUNT_ERR
Language        =Rus
_MC("Count of read-write columns does not equal count of values")
.

//------------------------------------------------------------------------
/*265*/
MessageId       =IBP_MCE_FB25__DSQL_STMT_HANDLE
Language        =Rus
_MC("Invalid statement handle")
.

//------------------------------------------------------------------------
/*266*/
MessageId       =IBP_MCE_FB25__DSQL_FUNCTION_ERR
Language        =Rus
_MC("Function unknown")
.

//------------------------------------------------------------------------
/*267*/
MessageId       =IBP_MCE_FB25__DSQL_BLOB_ERR
Language        =Rus
_MC("Column is not a BLOB")
.

//------------------------------------------------------------------------
/*268*/
MessageId       =IBP_MCE_FB25__COLLATION_NOT_FOUND
Language        =Rus
_MC("COLLATION %1 for CHARACTER SET %2 is not defined")
.

//------------------------------------------------------------------------
/*269*/
MessageId       =IBP_MCE_FB25__COLLATION_NOT_FOR_CHARSET
Language        =Rus
_MC("COLLATION %1 is not valid for specified CHARACTER SET")
.

//------------------------------------------------------------------------
/*270*/
MessageId       =IBP_MCE_FB25__DSQL_DUP_OPTION
Language        =Rus
_MC("Option specified more than once")
.

//------------------------------------------------------------------------
/*271*/
MessageId       =IBP_MCE_FB25__DSQL_TRAN_ERR
Language        =Rus
_MC("Unknown transaction option")
.

//------------------------------------------------------------------------
/*272*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_ARRAY
Language        =Rus
_MC("Invalid array reference")
.

//------------------------------------------------------------------------
/*273*/
MessageId       =IBP_MCE_FB25__DSQL_MAX_ARR_DIM_EXCEEDED
Language        =Rus
_MC("Array declared with too many dimensions")
.

//------------------------------------------------------------------------
/*274*/
MessageId       =IBP_MCE_FB25__DSQL_ARR_RANGE_ERROR
Language        =Rus
_MC("Illegal array dimension range")
.

//------------------------------------------------------------------------
/*275*/
MessageId       =IBP_MCE_FB25__DSQL_TRIGGER_ERR
Language        =Rus
_MC("Trigger unknown")
.

//------------------------------------------------------------------------
/*276*/
MessageId       =IBP_MCE_FB25__DSQL_SUBSELECT_ERR
Language        =Rus
_MC("Subselect illegal in this context")
.

//------------------------------------------------------------------------
/*277*/
MessageId       =IBP_MCE_FB25__DSQL_CRDB_PREPARE_ERR
Language        =Rus
_MC("Cannot prepare a CREATE DATABASE/SCHEMA statement")
.

//------------------------------------------------------------------------
/*278*/
MessageId       =IBP_MCE_FB25__SPECIFY_FIELD_ERR
Language        =Rus
_MC("must specify column name for view select expression")
.

//------------------------------------------------------------------------
/*279*/
MessageId       =IBP_MCE_FB25__NUM_FIELD_ERR
Language        =Rus
_MC("number of columns does not match select list")
.

//------------------------------------------------------------------------
/*280*/
MessageId       =IBP_MCE_FB25__COL_NAME_ERR
Language        =Rus
_MC("Only simple column names permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*281*/
MessageId       =IBP_MCE_FB25__WHERE_ERR
Language        =Rus
_MC("No WHERE clause for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*282*/
MessageId       =IBP_MCE_FB25__TABLE_VIEW_ERR
Language        =Rus
_MC("Only one table allowed for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*283*/
MessageId       =IBP_MCE_FB25__DISTINCT_ERR
Language        =Rus
_MC("DISTINCT, GROUP or HAVING not permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*284*/
MessageId       =IBP_MCE_FB25__KEY_FIELD_COUNT_ERR
Language        =Rus
_MC("FOREIGN KEY column count does not match PRIMARY KEY")
.

//------------------------------------------------------------------------
/*285*/
MessageId       =IBP_MCE_FB25__SUBQUERY_ERR
Language        =Rus
_MC("No subqueries permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*286*/
MessageId       =IBP_MCE_FB25__EXPRESSION_EVAL_ERR
Language        =Rus
_MC("expression evaluation not supported")
.

//------------------------------------------------------------------------
/*287*/
MessageId       =IBP_MCE_FB25__NODE_ERR
Language        =Rus
_MC("gen.c: node not supported")
.

//------------------------------------------------------------------------
/*288*/
MessageId       =IBP_MCE_FB25__COMMAND_END_ERR
Language        =Rus
_MC("Unexpected end of command")
.

//------------------------------------------------------------------------
/*289*/
MessageId       =IBP_MCE_FB25__INDEX_NAME
Language        =Rus
_MC("INDEX %1")
.

//------------------------------------------------------------------------
/*290*/
MessageId       =IBP_MCE_FB25__EXCEPTION_NAME
Language        =Rus
_MC("EXCEPTION %1")
.

//------------------------------------------------------------------------
/*291*/
MessageId       =IBP_MCE_FB25__FIELD_NAME
Language        =Rus
_MC("COLUMN %1")
.

//------------------------------------------------------------------------
/*292*/
MessageId       =IBP_MCE_FB25__TOKEN_ERR
Language        =Rus
_MC("Token unknown")
.

//------------------------------------------------------------------------
/*293*/
MessageId       =IBP_MCE_FB25__UNION_ERR
Language        =Rus
_MC("union not supported")
.

//------------------------------------------------------------------------
/*294*/
MessageId       =IBP_MCE_FB25__DSQL_CONSTRUCT_ERR
Language        =Rus
_MC("Unsupported DSQL construct")
.

//------------------------------------------------------------------------
/*295*/
MessageId       =IBP_MCE_FB25__FIELD_AGGREGATE_ERR
Language        =Rus
_MC("column used with aggregate")
.

//------------------------------------------------------------------------
/*296*/
MessageId       =IBP_MCE_FB25__FIELD_REF_ERR
Language        =Rus
_MC("invalid column reference")
.

//------------------------------------------------------------------------
/*297*/
MessageId       =IBP_MCE_FB25__ORDER_BY_ERR
Language        =Rus
_MC("invalid ORDER BY clause")
.

//------------------------------------------------------------------------
/*298*/
MessageId       =IBP_MCE_FB25__RETURN_MODE_ERR
Language        =Rus
_MC("Return mode by value not allowed for this data type")
.

//------------------------------------------------------------------------
/*299*/
MessageId       =IBP_MCE_FB25__EXTERN_FUNC_ERR
Language        =Rus
_MC("External functions cannot have more than 10 parameters")
.

//------------------------------------------------------------------------
/*300*/
MessageId       =IBP_MCE_FB25__ALIAS_CONFLICT_ERR
Language        =Rus
_MC("alias %1 conflicts with an alias in the same statement")
.

//------------------------------------------------------------------------
/*301*/
MessageId       =IBP_MCE_FB25__PROCEDURE_CONFLICT_ERROR
Language        =Rus
_MC("alias %1 conflicts with a procedure in the same statement")
.

//------------------------------------------------------------------------
/*302*/
MessageId       =IBP_MCE_FB25__RELATION_CONFLICT_ERR
Language        =Rus
_MC("alias %1 conflicts with a table in the same statement")
.

//------------------------------------------------------------------------
/*303*/
MessageId       =IBP_MCE_FB25__DSQL_DOMAIN_ERR
Language        =Rus
_MC("Illegal use of keyword VALUE")
.

//------------------------------------------------------------------------
/*304*/
MessageId       =IBP_MCE_FB25__IDX_SEG_ERR
Language        =Rus
_MC("segment count of 0 defined for index %1")
.

//------------------------------------------------------------------------
/*305*/
MessageId       =IBP_MCE_FB25__NODE_NAME_ERR
Language        =Rus
_MC("A node name is not permitted in a secondary, shadow, cache or log file name")
.

//------------------------------------------------------------------------
/*306*/
MessageId       =IBP_MCE_FB25__TABLE_NAME
Language        =Rus
_MC("TABLE %1")
.

//------------------------------------------------------------------------
/*307*/
MessageId       =IBP_MCE_FB25__PROC_NAME
Language        =Rus
_MC("PROCEDURE %1")
.

//------------------------------------------------------------------------
/*308*/
MessageId       =IBP_MCE_FB25__IDX_CREATE_ERR
Language        =Rus
_MC("cannot create index %1")
.

//------------------------------------------------------------------------
/*309*/
MessageId       =IBP_MCE_FB25__WAL_SHADOW_ERR
Language        =Rus
_MC("Write-ahead Log with shadowing configuration not allowed")
.

//------------------------------------------------------------------------
/*310*/
MessageId       =IBP_MCE_FB25__DEPENDENCY
Language        =Rus
_MC("there are %1 dependencies")
.

//------------------------------------------------------------------------
/*311*/
MessageId       =IBP_MCE_FB25__IDX_KEY_ERR
Language        =Rus
_MC("too many keys defined for index %1")
.

//------------------------------------------------------------------------
/*312*/
MessageId       =IBP_MCE_FB25__DSQL_FILE_LENGTH_ERR
Language        =Rus
_MC("Preceding file did not specify length, so %1 must include starting page number")
.

//------------------------------------------------------------------------
/*313*/
MessageId       =IBP_MCE_FB25__DSQL_SHADOW_NUMBER_ERR
Language        =Rus
_MC("Shadow number must be a positive integer")
.

//------------------------------------------------------------------------
/*314*/
MessageId       =IBP_MCE_FB25__DSQL_TOKEN_UNK_ERR
Language        =Rus
_MC("Token unknown - line %1, column %2")
.

//------------------------------------------------------------------------
/*315*/
MessageId       =IBP_MCE_FB25__DSQL_NO_RELATION_ALIAS
Language        =Rus
_MC("there is no alias or table named %1 at this scope level")
.

//------------------------------------------------------------------------
/*316*/
MessageId       =IBP_MCE_FB25__INDEXNAME
Language        =Rus
_MC("there is no index %1 for table %2")
.

//------------------------------------------------------------------------
/*317*/
MessageId       =IBP_MCE_FB25__NO_STREAM_PLAN
Language        =Rus
_MC("table %1 is not referenced in plan")
.

//------------------------------------------------------------------------
/*318*/
MessageId       =IBP_MCE_FB25__STREAM_TWICE
Language        =Rus
_MC("table %1 is referenced more than once in plan; use aliases to distinguish")
.

//------------------------------------------------------------------------
/*319*/
MessageId       =IBP_MCE_FB25__STREAM_NOT_FOUND
Language        =Rus
_MC("table %1 is referenced in the plan but not the from list")
.

//------------------------------------------------------------------------
/*320*/
MessageId       =IBP_MCE_FB25__COLLATION_REQUIRES_TEXT
Language        =Rus
_MC("Invalid use of CHARACTER SET or COLLATE")
.

//------------------------------------------------------------------------
/*321*/
MessageId       =IBP_MCE_FB25__DSQL_DOMAIN_NOT_FOUND
Language        =Rus
_MC("Specified domain or source column %1 does not exist")
.

//------------------------------------------------------------------------
/*322*/
MessageId       =IBP_MCE_FB25__INDEX_UNUSED
Language        =Rus
_MC("index %1 cannot be used in the specified plan")
.

//------------------------------------------------------------------------
/*323*/
MessageId       =IBP_MCE_FB25__DSQL_SELF_JOIN
Language        =Rus
_MC("the table %1 is referenced twice; use aliases to differentiate")
.

//------------------------------------------------------------------------
/*324*/
MessageId       =IBP_MCE_FB25__STREAM_BOF
Language        =Rus
_MC("illegal operation when at beginning of stream")
.

//------------------------------------------------------------------------
/*325*/
MessageId       =IBP_MCE_FB25__STREAM_CRACK
Language        =Rus
_MC("the current position is on a crack")
.

//------------------------------------------------------------------------
/*326*/
MessageId       =IBP_MCE_FB25__DB_OR_FILE_EXISTS
Language        =Rus
_MC("database or file exists")
.

//------------------------------------------------------------------------
/*327*/
MessageId       =IBP_MCE_FB25__INVALID_OPERATOR
Language        =Rus
_MC("invalid comparison operator for find operation")
.

//------------------------------------------------------------------------
/*328*/
MessageId       =IBP_MCE_FB25__CONN_LOST
Language        =Rus
_MC("Connection lost to pipe server")
.

//------------------------------------------------------------------------
/*329*/
MessageId       =IBP_MCE_FB25__BAD_CHECKSUM
Language        =Rus
_MC("bad checksum")
.

//------------------------------------------------------------------------
/*330*/
MessageId       =IBP_MCE_FB25__PAGE_TYPE_ERR
Language        =Rus
_MC("wrong page type")
.

//------------------------------------------------------------------------
/*331*/
MessageId       =IBP_MCE_FB25__EXT_READONLY_ERR
Language        =Rus
_MC("Cannot insert because the file is readonly or is on a read only medium.")
.

//------------------------------------------------------------------------
/*332*/
MessageId       =IBP_MCE_FB25__SING_SELECT_ERR
Language        =Rus
_MC("несколько рядов в одиночном селекте")
.

//------------------------------------------------------------------------
/*333*/
MessageId       =IBP_MCE_FB25__PSW_ATTACH
Language        =Rus
_MC("cannot attach to password database")
.

//------------------------------------------------------------------------
/*334*/
MessageId       =IBP_MCE_FB25__PSW_START_TRANS
Language        =Rus
_MC("cannot start transaction for password database")
.

//------------------------------------------------------------------------
/*335*/
MessageId       =IBP_MCE_FB25__INVALID_DIRECTION
Language        =Rus
_MC("invalid direction for find operation")
.

//------------------------------------------------------------------------
/*336*/
MessageId       =IBP_MCE_FB25__DSQL_VAR_CONFLICT
Language        =Rus
_MC("variable %1 conflicts with parameter in same procedure")
.

//------------------------------------------------------------------------
/*337*/
MessageId       =IBP_MCE_FB25__DSQL_NO_BLOB_ARRAY
Language        =Rus
_MC("Array/BLOB/DATE data types not allowed in arithmetic")
.

//------------------------------------------------------------------------
/*338*/
MessageId       =IBP_MCE_FB25__DSQL_BASE_TABLE
Language        =Rus
_MC("%1 is not a valid base table of the specified view")
.

//------------------------------------------------------------------------
/*339*/
MessageId       =IBP_MCE_FB25__DUPLICATE_BASE_TABLE
Language        =Rus
_MC("table %1 is referenced twice in view; use an alias to distinguish")
.

//------------------------------------------------------------------------
/*340*/
MessageId       =IBP_MCE_FB25__VIEW_ALIAS
Language        =Rus
_MC("view %1 has more than one base table; use aliases to distinguish")
.

//------------------------------------------------------------------------
/*341*/
MessageId       =IBP_MCE_FB25__INDEX_ROOT_PAGE_FULL
Language        =Rus
_MC("cannot add index, index root page is full.")
.

//------------------------------------------------------------------------
/*342*/
MessageId       =IBP_MCE_FB25__DSQL_BLOB_TYPE_UNKNOWN
Language        =Rus
_MC("BLOB SUB_TYPE %1 is not defined")
.

//------------------------------------------------------------------------
/*343*/
MessageId       =IBP_MCE_FB25__REQ_MAX_CLONES_EXCEEDED
Language        =Rus
_MC("Too many concurrent executions of the same request")
.

//------------------------------------------------------------------------
/*344*/
MessageId       =IBP_MCE_FB25__DSQL_DUPLICATE_SPEC
Language        =Rus
_MC("duplicate specification of %1 - not supported")
.

//------------------------------------------------------------------------
/*345*/
MessageId       =IBP_MCE_FB25__UNIQUE_KEY_VIOLATION
Language        =Rus
_MC("violation of PRIMARY or UNIQUE KEY constraint \"%1\" on table \"%2\"")
.

//------------------------------------------------------------------------
/*346*/
MessageId       =IBP_MCE_FB25__SRVR_VERSION_TOO_OLD
Language        =Rus
_MC("server version too old to support all CREATE DATABASE options")
.

//------------------------------------------------------------------------
/*347*/
MessageId       =IBP_MCE_FB25__DRDB_COMPLETED_WITH_ERRS
Language        =Rus
_MC("drop database completed with errors")
.

//------------------------------------------------------------------------
/*348*/
MessageId       =IBP_MCE_FB25__DSQL_PROCEDURE_USE_ERR
Language        =Rus
_MC("procedure %1 does not return any values")
.

//------------------------------------------------------------------------
/*349*/
MessageId       =IBP_MCE_FB25__DSQL_COUNT_MISMATCH
Language        =Rus
_MC("count of column list and variable list do not match")
.

//------------------------------------------------------------------------
/*350*/
MessageId       =IBP_MCE_FB25__BLOB_IDX_ERR
Language        =Rus
_MC("attempt to index BLOB column in index %1")
.

//------------------------------------------------------------------------
/*351*/
MessageId       =IBP_MCE_FB25__ARRAY_IDX_ERR
Language        =Rus
_MC("attempt to index array column in index %1")
.

//------------------------------------------------------------------------
/*352*/
MessageId       =IBP_MCE_FB25__KEY_FIELD_ERR
Language        =Rus
_MC("too few key columns found for index %1 (incorrect column name?)")
.

//------------------------------------------------------------------------
/*353*/
MessageId       =IBP_MCE_FB25__NO_DELETE
Language        =Rus
_MC("cannot delete")
.

//------------------------------------------------------------------------
/*354*/
MessageId       =IBP_MCE_FB25__DEL_LAST_FIELD
Language        =Rus
_MC("last column in a table cannot be deleted")
.

//------------------------------------------------------------------------
/*355*/
MessageId       =IBP_MCE_FB25__SORT_ERR
Language        =Rus
_MC("sort error")
.

//------------------------------------------------------------------------
/*356*/
MessageId       =IBP_MCE_FB25__SORT_MEM_ERR
Language        =Rus
_MC("sort error: not enough memory")
.

//------------------------------------------------------------------------
/*357*/
MessageId       =IBP_MCE_FB25__VERSION_ERR
Language        =Rus
_MC("too many versions")
.

//------------------------------------------------------------------------
/*358*/
MessageId       =IBP_MCE_FB25__INVAL_KEY_POSN
Language        =Rus
_MC("invalid key position")
.

//------------------------------------------------------------------------
/*359*/
MessageId       =IBP_MCE_FB25__NO_SEGMENTS_ERR
Language        =Rus
_MC("segments not allowed in expression index %1")
.

//------------------------------------------------------------------------
/*360*/
MessageId       =IBP_MCE_FB25__CRRP_DATA_ERR
Language        =Rus
_MC("sort error: corruption in data structure")
.

//------------------------------------------------------------------------
/*361*/
MessageId       =IBP_MCE_FB25__REC_SIZE_ERR
Language        =Rus
_MC("new record size of %1 bytes is too big")
.

//------------------------------------------------------------------------
/*362*/
MessageId       =IBP_MCE_FB25__DSQL_FIELD_REF
Language        =Rus
_MC("Inappropriate self-reference of column")
.

//------------------------------------------------------------------------
/*363*/
MessageId       =IBP_MCE_FB25__REQ_DEPTH_EXCEEDED
Language        =Rus
_MC("request depth exceeded. (Recursive definition?)")
.

//------------------------------------------------------------------------
/*364*/
MessageId       =IBP_MCE_FB25__NO_FIELD_ACCESS
Language        =Rus
_MC("cannot access column %1 in view %2")
.

//------------------------------------------------------------------------
/*365*/
MessageId       =IBP_MCE_FB25__NO_DBKEY
Language        =Rus
_MC("dbkey not available for multi-table views")
.

//------------------------------------------------------------------------
/*366*/
MessageId       =IBP_MCE_FB25__JRN_FORMAT_ERR
Language        =Rus
_MC("journal file wrong format")
.

//------------------------------------------------------------------------
/*367*/
MessageId       =IBP_MCE_FB25__JRN_FILE_FULL
Language        =Rus
_MC("intermediate journal file full")
.

//------------------------------------------------------------------------
/*368*/
MessageId       =IBP_MCE_FB25__DSQL_OPEN_CURSOR_REQUEST
Language        =Rus
_MC("The prepare statement identifies a prepare statement with an open cursor")
.

//------------------------------------------------------------------------
/*369*/
MessageId       =IBP_MCE_FB25__IB_ERROR
Language        =Rus
_MC("Firebird error")
.

//------------------------------------------------------------------------
/*370*/
MessageId       =IBP_MCE_FB25__CACHE_REDEF
Language        =Rus
_MC("Cache redefined")
.

//------------------------------------------------------------------------
/*371*/
MessageId       =IBP_MCE_FB25__CACHE_TOO_SMALL
Language        =Rus
_MC("Недостаточно памяти для размещения буфера страничного кэша.")
.

//------------------------------------------------------------------------
/*372*/
MessageId       =IBP_MCE_FB25__LOG_REDEF
Language        =Rus
_MC("Log redefined")
.

//------------------------------------------------------------------------
/*373*/
MessageId       =IBP_MCE_FB25__LOG_TOO_SMALL
Language        =Rus
_MC("Log size too small")
.

//------------------------------------------------------------------------
/*374*/
MessageId       =IBP_MCE_FB25__PARTITION_TOO_SMALL
Language        =Rus
_MC("Log partition size too small")
.

//------------------------------------------------------------------------
/*375*/
MessageId       =IBP_MCE_FB25__PARTITION_NOT_SUPP
Language        =Rus
_MC("Partitions not supported in series of log file specification")
.

//------------------------------------------------------------------------
/*376*/
MessageId       =IBP_MCE_FB25__LOG_LENGTH_SPEC
Language        =Rus
_MC("Total length of a partitioned log must be specified")
.

//------------------------------------------------------------------------
/*377*/
MessageId       =IBP_MCE_FB25__PRECISION_ERR
Language        =Rus
_MC("Precision must be from 1 to 18")
.

//------------------------------------------------------------------------
/*378*/
MessageId       =IBP_MCE_FB25__SCALE_NOGT
Language        =Rus
_MC("Scale must be between zero and precision")
.

//------------------------------------------------------------------------
/*379*/
MessageId       =IBP_MCE_FB25__EXPEC_SHORT
Language        =Rus
_MC("Short integer expected")
.

//------------------------------------------------------------------------
/*380*/
MessageId       =IBP_MCE_FB25__EXPEC_LONG
Language        =Rus
_MC("Long integer expected")
.

//------------------------------------------------------------------------
/*381*/
MessageId       =IBP_MCE_FB25__EXPEC_USHORT
Language        =Rus
_MC("Unsigned short integer expected")
.

//------------------------------------------------------------------------
/*382*/
MessageId       =IBP_MCE_FB25__ESCAPE_INVALID
Language        =Rus
_MC("Invalid ESCAPE sequence")
.

//------------------------------------------------------------------------
/*383*/
MessageId       =IBP_MCE_FB25__SVCNOEXE
Language        =Rus
_MC("service %1 does not have an associated executable")
.

//------------------------------------------------------------------------
/*384*/
MessageId       =IBP_MCE_FB25__NET_LOOKUP_ERR
Language        =Rus
_MC("Failed to locate host machine.")
.

//------------------------------------------------------------------------
/*385*/
MessageId       =IBP_MCE_FB25__SERVICE_UNKNOWN
Language        =Rus
_MC("Undefined service %1/%2.")
.

//------------------------------------------------------------------------
/*386*/
MessageId       =IBP_MCE_FB25__HOST_UNKNOWN
Language        =Rus
_MC("The specified name was not found in the hosts file or Domain Name Services.")
.

//------------------------------------------------------------------------
/*387*/
MessageId       =IBP_MCE_FB25__GRANT_NOPRIV_ON_BASE
Language        =Rus
_MC("user does not have GRANT privileges on base table/view for operation")
.

//------------------------------------------------------------------------
/*388*/
MessageId       =IBP_MCE_FB25__DYN_FLD_AMBIGUOUS
Language        =Rus
_MC("Ambiguous column reference.")
.

//------------------------------------------------------------------------
/*389*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_REF_ERR
Language        =Rus
_MC("Invalid aggregate reference")
.

//------------------------------------------------------------------------
/*390*/
MessageId       =IBP_MCE_FB25__COMPLEX_VIEW
Language        =Rus
_MC("navigational stream %1 references a view with more than one base table")
.

//------------------------------------------------------------------------
/*391*/
MessageId       =IBP_MCE_FB25__UNPREPARED_STMT
Language        =Rus
_MC("Попытка выполнить неподготовленное динамическое SQL выражение.")
.

//------------------------------------------------------------------------
/*392*/
MessageId       =IBP_MCE_FB25__EXPEC_POSITIVE
Language        =Rus
_MC("Positive value expected")
.

//------------------------------------------------------------------------
/*393*/
MessageId       =IBP_MCE_FB25__DSQL_SQLDA_VALUE_ERR
Language        =Rus
_MC("Incorrect values within SQLDA structure")
.

//------------------------------------------------------------------------
/*394*/
MessageId       =IBP_MCE_FB25__INVALID_ARRAY_ID
Language        =Rus
_MC("invalid blob id")
.

//------------------------------------------------------------------------
/*395*/
MessageId       =IBP_MCE_FB25__EXTFILE_UNS_OP
Language        =Rus
_MC("Operation not supported for EXTERNAL FILE table %1")
.

//------------------------------------------------------------------------
/*396*/
MessageId       =IBP_MCE_FB25__SVC_IN_USE
Language        =Rus
_MC("Service is currently busy: %1")
.

//------------------------------------------------------------------------
/*397*/
MessageId       =IBP_MCE_FB25__ERR_STACK_LIMIT
Language        =Rus
_MC("stack size insufficent to execute current request")
.

//------------------------------------------------------------------------
/*398*/
MessageId       =IBP_MCE_FB25__INVALID_KEY
Language        =Rus
_MC("Invalid key for find operation")
.

//------------------------------------------------------------------------
/*399*/
MessageId       =IBP_MCE_FB25__NET_INIT_ERROR
Language        =Rus
_MC("Error initializing the network software.")
.

//------------------------------------------------------------------------
/*400*/
MessageId       =IBP_MCE_FB25__LOADLIB_FAILURE
Language        =Rus
_MC("Unable to load required library %1.")
.

//------------------------------------------------------------------------
/*401*/
MessageId       =IBP_MCE_FB25__NETWORK_ERROR
Language        =Rus
_MC("Unable to complete network request to host \"%1\".")
.

//------------------------------------------------------------------------
/*402*/
MessageId       =IBP_MCE_FB25__NET_CONNECT_ERR
Language        =Rus
_MC("Failed to establish a connection.")
.

//------------------------------------------------------------------------
/*403*/
MessageId       =IBP_MCE_FB25__NET_CONNECT_LISTEN_ERR
Language        =Rus
_MC("Error while listening for an incoming connection.")
.

//------------------------------------------------------------------------
/*404*/
MessageId       =IBP_MCE_FB25__NET_EVENT_CONNECT_ERR
Language        =Rus
_MC("Failed to establish a secondary connection for event processing.")
.

//------------------------------------------------------------------------
/*405*/
MessageId       =IBP_MCE_FB25__NET_EVENT_LISTEN_ERR
Language        =Rus
_MC("Error while listening for an incoming event connection request.")
.

//------------------------------------------------------------------------
/*406*/
MessageId       =IBP_MCE_FB25__NET_READ_ERR
Language        =Rus
_MC("Error reading data from the connection.")
.

//------------------------------------------------------------------------
/*407*/
MessageId       =IBP_MCE_FB25__NET_WRITE_ERR
Language        =Rus
_MC("Error writing data to the connection.")
.

//------------------------------------------------------------------------
/*408*/
MessageId       =IBP_MCE_FB25__INTEG_INDEX_DEACTIVATE
Language        =Rus
_MC("Cannot deactivate index used by an integrity constraint")
.

//------------------------------------------------------------------------
/*409*/
MessageId       =IBP_MCE_FB25__INTEG_DEACTIVATE_PRIMARY
Language        =Rus
_MC("Cannot deactivate index used by a PRIMARY/UNIQUE constraint")
.

//------------------------------------------------------------------------
/*410*/
MessageId       =IBP_MCE_FB25__CSE_NOT_SUPPORTED
Language        =Rus
_MC("Client/Server Express not supported in this release")
.

//------------------------------------------------------------------------
/*411*/
MessageId       =IBP_MCE_FB25__TRA_MUST_SWEEP
Language        =Rus
_MC("")
.

//------------------------------------------------------------------------
/*412*/
MessageId       =IBP_MCE_FB25__UNSUPPORTED_NETWORK_DRIVE
Language        =Rus
_MC("Access to databases on file servers is not supported.")
.

//------------------------------------------------------------------------
/*413*/
MessageId       =IBP_MCE_FB25__IO_CREATE_ERR
Language        =Rus
_MC("В процессе создания файла произошла ошибка.")
.

//------------------------------------------------------------------------
/*414*/
MessageId       =IBP_MCE_FB25__IO_OPEN_ERR
Language        =Rus
_MC("В процессе открытия файла произошла ошибка.")
.

//------------------------------------------------------------------------
/*415*/
MessageId       =IBP_MCE_FB25__IO_CLOSE_ERR
Language        =Rus
_MC("В процессе закрытия файла произошла ошибка.")
.

//------------------------------------------------------------------------
/*416*/
MessageId       =IBP_MCE_FB25__IO_READ_ERR
Language        =Rus
_MC("В процессе чтения из файла произошла ошибка.")
.

//------------------------------------------------------------------------
/*417*/
MessageId       =IBP_MCE_FB25__IO_WRITE_ERR
Language        =Rus
_MC("В процессе записи в файл произошла ошибка.")
.

//------------------------------------------------------------------------
/*418*/
MessageId       =IBP_MCE_FB25__IO_DELETE_ERR
Language        =Rus
_MC("В процессе удаления файла произошла ошибка.")
.

//------------------------------------------------------------------------
/*419*/
MessageId       =IBP_MCE_FB25__IO_ACCESS_ERR
Language        =Rus
_MC("В процессе доступа к файлу произошла ошибка.")
.

//------------------------------------------------------------------------
/*420*/
MessageId       =IBP_MCE_FB25__UDF_EXCEPTION
Language        =Rus
_MC("A fatal exception occurred during the execution of a user defined function.")
.

//------------------------------------------------------------------------
/*421*/
MessageId       =IBP_MCE_FB25__LOST_DB_CONNECTION
Language        =Rus
_MC("connection lost to database")
.

//------------------------------------------------------------------------
/*422*/
MessageId       =IBP_MCE_FB25__NO_WRITE_USER_PRIV
Language        =Rus
_MC("User cannot write to RDB$USER_PRIVILEGES")
.

//------------------------------------------------------------------------
/*423*/
MessageId       =IBP_MCE_FB25__TOKEN_TOO_LONG
Language        =Rus
_MC("token size exceeds limit")
.

//------------------------------------------------------------------------
/*424*/
MessageId       =IBP_MCE_FB25__MAX_ATT_EXCEEDED
Language        =Rus
_MC("Maximum user count exceeded. Contact your database administrator.")
.

//------------------------------------------------------------------------
/*425*/
MessageId       =IBP_MCE_FB25__LOGIN_SAME_AS_ROLE_NAME
Language        =Rus
_MC("Your login %1 is same as one of the SQL role name. Ask your database administrator to set up a valid Firebird login.")
.

//------------------------------------------------------------------------
/*426*/
MessageId       =IBP_MCE_FB25__REFTABLE_REQUIRES_PK
Language        =Rus
_MC("\"REFERENCES table\" without \"(column)\" requires PRIMARY KEY on referenced table")
.

//------------------------------------------------------------------------
/*427*/
MessageId       =IBP_MCE_FB25__USRNAME_TOO_LONG
Language        =Rus
_MC("The username entered is too long. Maximum length is 31 bytes.")
.

//------------------------------------------------------------------------
/*428*/
MessageId       =IBP_MCE_FB25__PASSWORD_TOO_LONG
Language        =Rus
_MC("The password specified is too long. Maximum length is 8 bytes.")
.

//------------------------------------------------------------------------
/*429*/
MessageId       =IBP_MCE_FB25__USRNAME_REQUIRED
Language        =Rus
_MC("A username is required for this operation.")
.

//------------------------------------------------------------------------
/*430*/
MessageId       =IBP_MCE_FB25__PASSWORD_REQUIRED
Language        =Rus
_MC("A password is required for this operation")
.

//------------------------------------------------------------------------
/*431*/
MessageId       =IBP_MCE_FB25__BAD_PROTOCOL
Language        =Rus
_MC("The network protocol specified is invalid")
.

//------------------------------------------------------------------------
/*432*/
MessageId       =IBP_MCE_FB25__DUP_USRNAME_FOUND
Language        =Rus
_MC("A duplicate user name was found in the security database")
.

//------------------------------------------------------------------------
/*433*/
MessageId       =IBP_MCE_FB25__USRNAME_NOT_FOUND
Language        =Rus
_MC("The user name specified was not found in the security database")
.

//------------------------------------------------------------------------
/*434*/
MessageId       =IBP_MCE_FB25__ERROR_ADDING_SEC_RECORD
Language        =Rus
_MC("An error occurred while attempting to add the user.")
.

//------------------------------------------------------------------------
/*435*/
MessageId       =IBP_MCE_FB25__ERROR_MODIFYING_SEC_RECORD
Language        =Rus
_MC("An error occurred while attempting to modify the user record.")
.

//------------------------------------------------------------------------
/*436*/
MessageId       =IBP_MCE_FB25__ERROR_DELETING_SEC_RECORD
Language        =Rus
_MC("An error occurred while attempting to delete the user record.")
.

//------------------------------------------------------------------------
/*437*/
MessageId       =IBP_MCE_FB25__ERROR_UPDATING_SEC_DB
Language        =Rus
_MC("An error occurred while updating the security database.")
.

//------------------------------------------------------------------------
/*438*/
MessageId       =IBP_MCE_FB25__SORT_REC_SIZE_ERR
Language        =Rus
_MC("sort record size of %1 bytes is too big")
.

//------------------------------------------------------------------------
/*439*/
MessageId       =IBP_MCE_FB25__BAD_DEFAULT_VALUE
Language        =Rus
_MC("can not define a not null column with NULL as default value")
.

//------------------------------------------------------------------------
/*440*/
MessageId       =IBP_MCE_FB25__INVALID_CLAUSE
Language        =Rus
_MC("invalid clause --- '%1'")
.

//------------------------------------------------------------------------
/*441*/
MessageId       =IBP_MCE_FB25__TOO_MANY_HANDLES
Language        =Rus
_MC("too many open handles to database")
.

//------------------------------------------------------------------------
/*442*/
MessageId       =IBP_MCE_FB25__OPTIMIZER_BLK_EXC
Language        =Rus
_MC("size of optimizer block exceeded")
.

//------------------------------------------------------------------------
/*443*/
MessageId       =IBP_MCE_FB25__INVALID_STRING_CONSTANT
Language        =Rus
_MC("a string constant is delimited by double quotes")
.

//------------------------------------------------------------------------
/*444*/
MessageId       =IBP_MCE_FB25__TRANSITIONAL_DATE
Language        =Rus
_MC("DATE must be changed to TIMESTAMP")
.

//------------------------------------------------------------------------
/*445*/
MessageId       =IBP_MCE_FB25__READ_ONLY_DATABASE
Language        =Rus
_MC("attempted update on read-only database")
.

//------------------------------------------------------------------------
/*446*/
MessageId       =IBP_MCE_FB25__MUST_BE_DIALECT_2_AND_UP
Language        =Rus
_MC("SQL dialect %1 is not supported in this database")
.

//------------------------------------------------------------------------
/*447*/
MessageId       =IBP_MCE_FB25__BLOB_FILTER_EXCEPTION
Language        =Rus
_MC("A fatal exception occurred during the execution of a blob filter.")
.

//------------------------------------------------------------------------
/*448*/
MessageId       =IBP_MCE_FB25__EXCEPTION_ACCESS_VIOLATION
Language        =Rus
_MC("Access violation. The code attempted to access a virtual address without privilege to do so.")
.

//------------------------------------------------------------------------
/*449*/
MessageId       =IBP_MCE_FB25__EXCEPTION_DATATYPE_MISSALIGNMENT
Language        =Rus
_MC("Datatype misalignment. The attempted to read or write a value that was not stored on a memory boundary.")
.

//------------------------------------------------------------------------
/*450*/
MessageId       =IBP_MCE_FB25__EXCEPTION_ARRAY_BOUNDS_EXCEEDED
Language        =Rus
_MC("Array bounds exceeded. The code attempted to access an array element that is out of bounds.")
.

//------------------------------------------------------------------------
/*451*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_DENORMAL_OPERAND
Language        =Rus
_MC("Float denormal operand. One of the floating-point operands is too small to represent a standard float value.")
.

//------------------------------------------------------------------------
/*452*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_DIVIDE_BY_ZERO
Language        =Rus
_MC("Floating-point divide by zero. The code attempted to divide a floating-point value by zero.")
.

//------------------------------------------------------------------------
/*453*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_INEXACT_RESULT
Language        =Rus
_MC("Floating-point inexact result. The result of a floating-point operation cannot be represented as a decimal fraction.")
.

//------------------------------------------------------------------------
/*454*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_INVALID_OPERAND
Language        =Rus
_MC("Floating-point invalid operand. An indeterminant error occurred during a floating-point operation.")
.

//------------------------------------------------------------------------
/*455*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_OVERFLOW
Language        =Rus
_MC("Floating-point overflow. The exponent of a floating-point operation is greater than the magnitude allowed.")
.

//------------------------------------------------------------------------
/*456*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_STACK_CHECK
Language        =Rus
_MC("Floating-point stack check. The stack overflowed or underflowed as the result of a floating-point operation.")
.

//------------------------------------------------------------------------
/*457*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_UNDERFLOW
Language        =Rus
_MC("Floating-point underflow. The exponent of a floating-point operation is less than the magnitude allowed.")
.

//------------------------------------------------------------------------
/*458*/
MessageId       =IBP_MCE_FB25__EXCEPTION_INTEGER_DIVIDE_BY_ZERO
Language        =Rus
_MC("Integer divide by zero. The code attempted to divide an integer value by an integer divisor of zero.")
.

//------------------------------------------------------------------------
/*459*/
MessageId       =IBP_MCE_FB25__EXCEPTION_INTEGER_OVERFLOW
Language        =Rus
_MC("Integer overflow. The result of an integer operation caused the most significant bit of the result to carry.")
.

//------------------------------------------------------------------------
/*460*/
MessageId       =IBP_MCE_FB25__EXCEPTION_UNKNOWN
Language        =Rus
_MC("An exception occurred that does not have a description. Exception number %1.")
.

//------------------------------------------------------------------------
/*461*/
MessageId       =IBP_MCE_FB25__EXCEPTION_STACK_OVERFLOW
Language        =Rus
_MC("Stack overflow. The resource requirements of the runtime stack have exceeded the memory available to it.")
.

//------------------------------------------------------------------------
/*462*/
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGSEGV
Language        =Rus
_MC("Segmentation Fault. The code attempted to access memory without privileges.")
.

//------------------------------------------------------------------------
/*463*/
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGILL
Language        =Rus
_MC("Illegal Instruction. The Code attempted to perform an illegal operation.")
.

//------------------------------------------------------------------------
/*464*/
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGBUS
Language        =Rus
_MC("Bus Error. The Code caused a system bus error.")
.

//------------------------------------------------------------------------
/*465*/
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGFPE
Language        =Rus
_MC("Floating Point Error. The Code caused an Arithmetic Exception or a floating point exception.")
.

//------------------------------------------------------------------------
/*466*/
MessageId       =IBP_MCE_FB25__EXT_FILE_DELETE
Language        =Rus
_MC("Cannot delete rows from external files.")
.

//------------------------------------------------------------------------
/*467*/
MessageId       =IBP_MCE_FB25__EXT_FILE_MODIFY
Language        =Rus
_MC("Cannot update rows in external files.")
.

//------------------------------------------------------------------------
/*468*/
MessageId       =IBP_MCE_FB25__ADM_TASK_DENIED
Language        =Rus
_MC("Unable to perform operation. You must be either SYSDBA or owner of the database")
.

//------------------------------------------------------------------------
/*469*/
MessageId       =IBP_MCE_FB25__EXTRACT_INPUT_MISMATCH
Language        =Rus
_MC("Specified EXTRACT part does not exist in input datatype")
.

//------------------------------------------------------------------------
/*470*/
MessageId       =IBP_MCE_FB25__INSUFFICIENT_SVC_PRIVILEGES
Language        =Rus
_MC("Service %1 requires SYSDBA permissions. Reattach to the Service Manager using the SYSDBA account.")
.

//------------------------------------------------------------------------
/*471*/
MessageId       =IBP_MCE_FB25__FILE_IN_USE
Language        =Rus
_MC("The file %1 is currently in use by another process. Try again later.")
.

//------------------------------------------------------------------------
/*472*/
MessageId       =IBP_MCE_FB25__SERVICE_ATT_ERR
Language        =Rus
_MC("Cannot attach to services manager")
.

//------------------------------------------------------------------------
/*473*/
MessageId       =IBP_MCE_FB25__DDL_NOT_ALLOWED_BY_DB_SQL_DIAL
Language        =Rus
_MC("Metadata update statement is not allowed by the current database SQL dialect %1")
.

//------------------------------------------------------------------------
/*474*/
MessageId       =IBP_MCE_FB25__CANCELLED
Language        =Rus
_MC("Операция была отменена.")
.

//------------------------------------------------------------------------
/*475*/
MessageId       =IBP_MCE_FB25__UNEXP_SPB_FORM
Language        =Rus
_MC("unexpected item in service parameter block, expected %1")
.

//------------------------------------------------------------------------
/*476*/
MessageId       =IBP_MCE_FB25__SQL_DIALECT_DATATYPE_UNSUPPORT
Language        =Rus
_MC("Client SQL dialect %1 does not support reference to %2 datatype")
.

//------------------------------------------------------------------------
/*477*/
MessageId       =IBP_MCE_FB25__SVCNOUSER
Language        =Rus
_MC("user name and password are required while attaching to the services manager")
.

//------------------------------------------------------------------------
/*478*/
MessageId       =IBP_MCE_FB25__DEPEND_ON_UNCOMMITTED_REL
Language        =Rus
_MC("You created an indirect dependency on uncommitted metadata. You must roll back the current transaction.")
.

//------------------------------------------------------------------------
/*479*/
MessageId       =IBP_MCE_FB25__SVC_NAME_MISSING
Language        =Rus
_MC("The service name was not specified.")
.

//------------------------------------------------------------------------
/*480*/
MessageId       =IBP_MCE_FB25__TOO_MANY_CONTEXTS
Language        =Rus
_MC("Too many Contexts of Relation/Procedure/Views. Maximum allowed is 255")
.

//------------------------------------------------------------------------
/*481*/
MessageId       =IBP_MCE_FB25__DATYPE_NOTSUP
Language        =Rus
_MC("data type not supported for arithmetic")
.

//------------------------------------------------------------------------
/*482*/
MessageId       =IBP_MCE_FB25__DIALECT_RESET_WARNING
Language        =Rus
_MC("Database dialect being changed from 3 to 1")
.

//------------------------------------------------------------------------
/*483*/
MessageId       =IBP_MCE_FB25__DIALECT_NOT_CHANGED
Language        =Rus
_MC("Database dialect not changed.")
.

//------------------------------------------------------------------------
/*484*/
MessageId       =IBP_MCE_FB25__DATABASE_CREATE_FAILED
Language        =Rus
_MC("Unable to create database %1")
.

//------------------------------------------------------------------------
/*485*/
MessageId       =IBP_MCE_FB25__INV_DIALECT_SPECIFIED
Language        =Rus
_MC("Database dialect %1 is not a valid dialect.")
.

//------------------------------------------------------------------------
/*486*/
MessageId       =IBP_MCE_FB25__VALID_DB_DIALECTS
Language        =Rus
_MC("Valid database dialects are %1.")
.

//------------------------------------------------------------------------
/*487*/
MessageId       =IBP_MCE_FB25__SQLWARN
Language        =Rus
_MC("SQL warning code = %1")
.

//------------------------------------------------------------------------
/*488*/
MessageId       =IBP_MCE_FB25__DTYPE_RENAMED
Language        =Rus
_MC("DATE data type is now called TIMESTAMP")
.

//------------------------------------------------------------------------
/*489*/
MessageId       =IBP_MCE_FB25__EXTERN_FUNC_DIR_ERROR
Language        =Rus
_MC("Function %1 is in %2, which is not in a permitted directory for external functions.")
.

//------------------------------------------------------------------------
/*490*/
MessageId       =IBP_MCE_FB25__DATE_RANGE_EXCEEDED
Language        =Rus
_MC("value exceeds the range for valid dates")
.

//------------------------------------------------------------------------
/*491*/
MessageId       =IBP_MCE_FB25__INV_CLIENT_DIALECT_SPECIFIED
Language        =Rus
_MC("passed client dialect %1 is not a valid dialect.")
.

//------------------------------------------------------------------------
/*492*/
MessageId       =IBP_MCE_FB25__VALID_CLIENT_DIALECTS
Language        =Rus
_MC("Valid client dialects are %1.")
.

//------------------------------------------------------------------------
/*493*/
MessageId       =IBP_MCE_FB25__OPTIMIZER_BETWEEN_ERR
Language        =Rus
_MC("Unsupported field type specified in BETWEEN predicate.")
.

//------------------------------------------------------------------------
/*494*/
MessageId       =IBP_MCE_FB25__SERVICE_NOT_SUPPORTED
Language        =Rus
_MC("Services functionality will be supported in a later version  of the product")
.

//------------------------------------------------------------------------
/*495*/
MessageId       =IBP_MCE_FB25__GENERATOR_NAME
Language        =Rus
_MC("GENERATOR %1")
.

//------------------------------------------------------------------------
/*496*/
MessageId       =IBP_MCE_FB25__UDF_NAME
Language        =Rus
_MC("UDF %1")
.

//------------------------------------------------------------------------
/*497*/
MessageId       =IBP_MCE_FB25__BAD_LIMIT_PARAM
Language        =Rus
_MC("Invalid parameter to FIRST. Only integers >= 0 are allowed.")
.

//------------------------------------------------------------------------
/*498*/
MessageId       =IBP_MCE_FB25__BAD_SKIP_PARAM
Language        =Rus
_MC("Invalid parameter to SKIP. Only integers >= 0 are allowed.")
.

//------------------------------------------------------------------------
/*499*/
MessageId       =IBP_MCE_FB25__IO_32BIT_EXCEEDED_ERR
Language        =Rus
_MC("File exceeded maximum size of 2GB. Add another database file or use a 64 bit I/O version of Firebird.")
.

//------------------------------------------------------------------------
/*500*/
MessageId       =IBP_MCE_FB25__INVALID_SAVEPOINT
Language        =Rus
_MC("Unable to find savepoint with name %1 in transaction context")
.

//------------------------------------------------------------------------
/*501*/
MessageId       =IBP_MCE_FB25__DSQL_COLUMN_POS_ERR
Language        =Rus
_MC("Invalid column position used in the %1 clause")
.

//------------------------------------------------------------------------
/*502*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_WHERE_ERR
Language        =Rus
_MC("Cannot use an aggregate function in a WHERE clause, use HAVING instead")
.

//------------------------------------------------------------------------
/*503*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_GROUP_ERR
Language        =Rus
_MC("Cannot use an aggregate function in a GROUP BY clause")
.

//------------------------------------------------------------------------
/*504*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_COLUMN_ERR
Language        =Rus
_MC("Invalid expression in the %1 (not contained in either an aggregate function or the GROUP BY clause)")
.

//------------------------------------------------------------------------
/*505*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_HAVING_ERR
Language        =Rus
_MC("Invalid expression in the %1 (neither an aggregate function nor a part of the GROUP BY clause)")
.

//------------------------------------------------------------------------
/*506*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_NESTED_ERR
Language        =Rus
_MC("Nested aggregate functions are not allowed")
.

//------------------------------------------------------------------------
/*507*/
MessageId       =IBP_MCE_FB25__EXEC_SQL_INVALID_ARG
Language        =Rus
_MC("Invalid argument in EXECUTE STATEMENT - cannot convert to string")
.

//------------------------------------------------------------------------
/*508*/
MessageId       =IBP_MCE_FB25__EXEC_SQL_INVALID_REQ
Language        =Rus
_MC("Wrong request type in EXECUTE STATEMENT '%1'")
.

//------------------------------------------------------------------------
/*509*/
MessageId       =IBP_MCE_FB25__EXEC_SQL_INVALID_VAR
Language        =Rus
_MC("Variable type (position %1) in EXECUTE STATEMENT '%2' INTO does not match returned column type")
.

//------------------------------------------------------------------------
/*510*/
MessageId       =IBP_MCE_FB25__EXEC_SQL_MAX_CALL_EXCEEDED
Language        =Rus
_MC("Too many recursion levels of EXECUTE STATEMENT")
.

//------------------------------------------------------------------------
/*511*/
MessageId       =IBP_MCE_FB25__CONF_ACCESS_DENIED
Language        =Rus
_MC("Use of %1 at location %2 is not allowed by server configuration")
.

//------------------------------------------------------------------------
/*512*/
MessageId       =IBP_MCE_FB25__WRONG_BACKUP_STATE
Language        =Rus
_MC("Cannot change difference file name while database is in backup mode")
.

//------------------------------------------------------------------------
/*513*/
MessageId       =IBP_MCE_FB25__WAL_BACKUP_ERR
Language        =Rus
_MC("Physical backup is not allowed while Write-Ahead Log is in use")
.

//------------------------------------------------------------------------
/*514*/
MessageId       =IBP_MCE_FB25__CURSOR_NOT_OPEN
Language        =Rus
_MC("Cursor is not open")
.

//------------------------------------------------------------------------
/*515*/
MessageId       =IBP_MCE_FB25__BAD_SHUTDOWN_MODE
Language        =Rus
_MC("Target shutdown mode is invalid for database \"%1\"")
.

//------------------------------------------------------------------------
/*516*/
MessageId       =IBP_MCE_FB25__CONCAT_OVERFLOW
Language        =Rus
_MC("Concatenation overflow. Resulting string cannot exceed 32765 bytes in length.")
.

//------------------------------------------------------------------------
/*517*/
MessageId       =IBP_MCE_FB25__BAD_SUBSTRING_OFFSET
Language        =Rus
_MC("Invalid offset parameter %1 to SUBSTRING. Only positive integers are allowed.")
.

//------------------------------------------------------------------------
/*518*/
MessageId       =IBP_MCE_FB25__FOREIGN_KEY_TARGET_DOESNT_EXIST
Language        =Rus
_MC("Foreign key reference target does not exist")
.

//------------------------------------------------------------------------
/*519*/
MessageId       =IBP_MCE_FB25__FOREIGN_KEY_REFERENCES_PRESENT
Language        =Rus
_MC("Foreign key references are present for the record")
.

//------------------------------------------------------------------------
/*520*/
MessageId       =IBP_MCE_FB25__NO_UPDATE
Language        =Rus
_MC("cannot update")
.

//------------------------------------------------------------------------
/*521*/
MessageId       =IBP_MCE_FB25__CURSOR_ALREADY_OPEN
Language        =Rus
_MC("Cursor is already open")
.

//------------------------------------------------------------------------
/*522*/
MessageId       =IBP_MCE_FB25__STACK_TRACE
Language        =Rus
_MC("%1")
.

//------------------------------------------------------------------------
/*523*/
MessageId       =IBP_MCE_FB25__CTX_VAR_NOT_FOUND
Language        =Rus
_MC("Context variable %1 is not found in namespace %2")
.

//------------------------------------------------------------------------
/*524*/
MessageId       =IBP_MCE_FB25__CTX_NAMESPACE_INVALID
Language        =Rus
_MC("Invalid namespace name %1 passed to %2")
.

//------------------------------------------------------------------------
/*525*/
MessageId       =IBP_MCE_FB25__CTX_TOO_BIG
Language        =Rus
_MC("Too many context variables")
.

//------------------------------------------------------------------------
/*526*/
MessageId       =IBP_MCE_FB25__CTX_BAD_ARGUMENT
Language        =Rus
_MC("Invalid argument passed to %1")
.

//------------------------------------------------------------------------
/*527*/
MessageId       =IBP_MCE_FB25__IDENTIFIER_TOO_LONG
Language        =Rus
_MC("BLR syntax error. Identifier %1... is too long")
.

//------------------------------------------------------------------------
/*528*/
MessageId       =IBP_MCE_FB25__EXCEPT2
Language        =Rus
_MC("exception %1")
.

//------------------------------------------------------------------------
/*529*/
MessageId       =IBP_MCE_FB25__MALFORMED_STRING
Language        =Rus
_MC("Malformed string")
.

//------------------------------------------------------------------------
/*530*/
MessageId       =IBP_MCE_FB25__PRC_OUT_PARAM_MISMATCH
Language        =Rus
_MC("Output parameter mismatch for procedure %1")
.

//------------------------------------------------------------------------
/*531*/
MessageId       =IBP_MCE_FB25__COMMAND_END_ERR2
Language        =Rus
_MC("Unexpected end of command - line %1, column %2")
.

//------------------------------------------------------------------------
/*532*/
MessageId       =IBP_MCE_FB25__PARTNER_IDX_INCOMPAT_TYPE
Language        =Rus
_MC("partner index segment no %1 has incompatible data type")
.

//------------------------------------------------------------------------
/*533*/
MessageId       =IBP_MCE_FB25__BAD_SUBSTRING_LENGTH
Language        =Rus
_MC("Invalid length parameter %1 to SUBSTRING. Negative integers are not allowed.")
.

//------------------------------------------------------------------------
/*534*/
MessageId       =IBP_MCE_FB25__CHARSET_NOT_INSTALLED
Language        =Rus
_MC("CHARACTER SET %1 is not installed")
.

//------------------------------------------------------------------------
/*535*/
MessageId       =IBP_MCE_FB25__COLLATION_NOT_INSTALLED
Language        =Rus
_MC("COLLATION %1 for CHARACTER SET %2 is not installed")
.

//------------------------------------------------------------------------
/*536*/
MessageId       =IBP_MCE_FB25__ATT_SHUTDOWN
Language        =Rus
_MC("connection shutdown")
.

//------------------------------------------------------------------------
/*537*/
MessageId       =IBP_MCE_FB25__BLOBTOOBIG
Language        =Rus
_MC("Maximum BLOB size exceeded")
.

//------------------------------------------------------------------------
/*538*/
MessageId       =IBP_MCE_FB25__MUST_HAVE_PHYS_FIELD
Language        =Rus
_MC("Can't have relation with only computed fields or constraints")
.

//------------------------------------------------------------------------
/*539*/
MessageId       =IBP_MCE_FB25__INVALID_TIME_PRECISION
Language        =Rus
_MC("Time precision exceeds allowed range (0-%1)")
.

//------------------------------------------------------------------------
/*540*/
MessageId       =IBP_MCE_FB25__BLOB_CONVERT_ERROR
Language        =Rus
_MC("Unsupported conversion to target type BLOB (subtype %1)")
.

//------------------------------------------------------------------------
/*541*/
MessageId       =IBP_MCE_FB25__ARRAY_CONVERT_ERROR
Language        =Rus
_MC("Unsupported conversion to target type ARRAY")
.

//------------------------------------------------------------------------
/*542*/
MessageId       =IBP_MCE_FB25__RECORD_LOCK_NOT_SUPP
Language        =Rus
_MC("Stream does not support record locking")
.

//------------------------------------------------------------------------
/*543*/
MessageId       =IBP_MCE_FB25__PARTNER_IDX_NOT_FOUND
Language        =Rus
_MC("Cannot create foreign key constraint %1. Partner index does not exist or is inactive.")
.

//------------------------------------------------------------------------
/*544*/
MessageId       =IBP_MCE_FB25__TRA_NUM_EXC
Language        =Rus
_MC("Transactions count exceeded. Perform backup and restore to make database operable again")
.

//------------------------------------------------------------------------
/*545*/
MessageId       =IBP_MCE_FB25__FIELD_DISAPPEARED
Language        =Rus
_MC("Column has been unexpectedly deleted")
.

//------------------------------------------------------------------------
/*546*/
MessageId       =IBP_MCE_FB25__MET_WRONG_GTT_SCOPE
Language        =Rus
_MC("%1 cannot depend on %2")
.

//------------------------------------------------------------------------
/*547*/
MessageId       =IBP_MCE_FB25__SUBTYPE_FOR_INTERNAL_USE
Language        =Rus
_MC("Blob sub_types bigger than 1 (text) are for internal use only")
.

//------------------------------------------------------------------------
/*548*/
MessageId       =IBP_MCE_FB25__ILLEGAL_PRC_TYPE
Language        =Rus
_MC("Procedure %1 is not selectable (it does not contain a SUSPEND statement)")
.

//------------------------------------------------------------------------
/*549*/
MessageId       =IBP_MCE_FB25__INVALID_SORT_DATATYPE
Language        =Rus
_MC("Datatype %1 is not supported for sorting operation")
.

//------------------------------------------------------------------------
/*550*/
MessageId       =IBP_MCE_FB25__COLLATION_NAME
Language        =Rus
_MC("COLLATION %1")
.

//------------------------------------------------------------------------
/*551*/
MessageId       =IBP_MCE_FB25__DOMAIN_NAME
Language        =Rus
_MC("DOMAIN %1")
.

//------------------------------------------------------------------------
/*552*/
MessageId       =IBP_MCE_FB25__DOMNOTDEF
Language        =Rus
_MC("domain %1 is not defined")
.

//------------------------------------------------------------------------
/*553*/
MessageId       =IBP_MCE_FB25__ARRAY_MAX_DIMENSIONS
Language        =Rus
_MC("Array data type can use up to %1 dimensions")
.

//------------------------------------------------------------------------
/*554*/
MessageId       =IBP_MCE_FB25__MAX_DB_PER_TRANS_ALLOWED
Language        =Rus
_MC("A multi database transaction cannot span more than %1 databases")
.

//------------------------------------------------------------------------
/*555*/
MessageId       =IBP_MCE_FB25__BAD_DEBUG_FORMAT
Language        =Rus
_MC("Bad debug info format")
.

//------------------------------------------------------------------------
/*556*/
MessageId       =IBP_MCE_FB25__BAD_PROC_BLR
Language        =Rus
_MC("Error while parsing procedure %1's BLR")
.

//------------------------------------------------------------------------
/*557*/
MessageId       =IBP_MCE_FB25__KEY_TOO_BIG
Language        =Rus
_MC("index key too big")
.

//------------------------------------------------------------------------
/*558*/
MessageId       =IBP_MCE_FB25__CONCURRENT_TRANSACTION
Language        =Rus
_MC("concurrent transaction number is %1")
.

//------------------------------------------------------------------------
/*559*/
MessageId       =IBP_MCE_FB25__NOT_VALID_FOR_VAR
Language        =Rus
_MC("validation error for variable %1, value \"%2\"")
.

//------------------------------------------------------------------------
/*560*/
MessageId       =IBP_MCE_FB25__NOT_VALID_FOR
Language        =Rus
_MC("validation error for %1, value \"%2\"")
.

//------------------------------------------------------------------------
/*561*/
MessageId       =IBP_MCE_FB25__NEED_DIFFERENCE
Language        =Rus
_MC("Difference file name should be set explicitly for database on raw device")
.

//------------------------------------------------------------------------
/*562*/
MessageId       =IBP_MCE_FB25__LONG_LOGIN
Language        =Rus
_MC("Login name too long (%1 characters, maximum allowed %2)")
.

//------------------------------------------------------------------------
/*563*/
MessageId       =IBP_MCE_FB25__FLDNOTDEF2
Language        =Rus
_MC("column %1 is not defined in procedure %2")
.

//------------------------------------------------------------------------
/*564*/
MessageId       =IBP_MCE_FB25__INVALID_SIMILAR_PATTERN
Language        =Rus
_MC("Invalid SIMILAR TO pattern")
.

//------------------------------------------------------------------------
/*565*/
MessageId       =IBP_MCE_FB25__BAD_TEB_FORM
Language        =Rus
_MC("Invalid TEB format")
.

//------------------------------------------------------------------------
/*566*/
MessageId       =IBP_MCE_FB25__TPB_MULTIPLE_TXN_ISOLATION
Language        =Rus
_MC("Found more than one transaction isolation in TPB")
.

//------------------------------------------------------------------------
/*567*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_BEFORE_TABLE
Language        =Rus
_MC("Table reservation lock type %1 requires table name before in TPB")
.

//------------------------------------------------------------------------
/*568*/
MessageId       =IBP_MCE_FB25__TPB_MULTIPLE_SPEC
Language        =Rus
_MC("Found more than one %1 specification in TPB")
.

//------------------------------------------------------------------------
/*569*/
MessageId       =IBP_MCE_FB25__TPB_OPTION_WITHOUT_RC
Language        =Rus
_MC("Option %1 requires READ COMMITTED isolation in TPB")
.

//------------------------------------------------------------------------
/*570*/
MessageId       =IBP_MCE_FB25__TPB_CONFLICTING_OPTIONS
Language        =Rus
_MC("Option %1 is not valid if %2 was used previously in TPB")
.

//------------------------------------------------------------------------
/*571*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_MISSING_TLEN
Language        =Rus
_MC("Table name length missing after table reservation %1 in TPB")
.

//------------------------------------------------------------------------
/*572*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_LONG_TLEN
Language        =Rus
_MC("Table name length %1 is too long after table reservation %2 in TPB")
.

//------------------------------------------------------------------------
/*573*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_MISSING_TNAME
Language        =Rus
_MC("Table name length %1 without table name after table reservation %2 in TPB")
.

//------------------------------------------------------------------------
/*574*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_CORRUP_TLEN
Language        =Rus
_MC("Table name length %1 goes beyond the remaining TPB size after table reservation %2")
.

//------------------------------------------------------------------------
/*575*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_NULL_TLEN
Language        =Rus
_MC("Table name length is zero after table reservation %1 in TPB")
.

//------------------------------------------------------------------------
/*576*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_RELNOTFOUND
Language        =Rus
_MC("Table or view %1 not defined in system tables after table reservation %2 in TPB")
.

//------------------------------------------------------------------------
/*577*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_BASERELNOTFOUND
Language        =Rus
_MC("Base table or view %1 for view %2 not defined in system tables after table reservation %3 in TPB")
.

//------------------------------------------------------------------------
/*578*/
MessageId       =IBP_MCE_FB25__TPB_MISSING_LEN
Language        =Rus
_MC("Option length missing after option %1 in TPB")
.

//------------------------------------------------------------------------
/*579*/
MessageId       =IBP_MCE_FB25__TPB_MISSING_VALUE
Language        =Rus
_MC("Option length %1 without value after option %2 in TPB")
.

//------------------------------------------------------------------------
/*580*/
MessageId       =IBP_MCE_FB25__TPB_CORRUPT_LEN
Language        =Rus
_MC("Option length %1 goes beyond the remaining TPB size after option %2")
.

//------------------------------------------------------------------------
/*581*/
MessageId       =IBP_MCE_FB25__TPB_NULL_LEN
Language        =Rus
_MC("Option length is zero after table reservation %1 in TPB")
.

//------------------------------------------------------------------------
/*582*/
MessageId       =IBP_MCE_FB25__TPB_OVERFLOW_LEN
Language        =Rus
_MC("Option length %1 exceeds the range for option %2 in TPB")
.

//------------------------------------------------------------------------
/*583*/
MessageId       =IBP_MCE_FB25__TPB_INVALID_VALUE
Language        =Rus
_MC("Option value %1 is invalid for the option %2 in TPB")
.

//------------------------------------------------------------------------
/*584*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_STRONGER_WNG
Language        =Rus
_MC("Preserving previous table reservation %1 for table %2, stronger than new %3 in TPB")
.

//------------------------------------------------------------------------
/*585*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_STRONGER
Language        =Rus
_MC("Table reservation %1 for table %2 already specified and is stronger than new %3 in TPB")
.

//------------------------------------------------------------------------
/*586*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_MAX_RECURSION
Language        =Rus
_MC("Table reservation reached maximum recursion of %1 when expanding views in TPB")
.

//------------------------------------------------------------------------
/*587*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_VIRTUALTBL
Language        =Rus
_MC("Table reservation in TPB cannot be applied to %1 because it's a virtual table")
.

//------------------------------------------------------------------------
/*588*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_SYSTBL
Language        =Rus
_MC("Table reservation in TPB cannot be applied to %1 because it's a system table")
.

//------------------------------------------------------------------------
/*589*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_TEMPTBL
Language        =Rus
_MC("Table reservation %1 or %2 in TPB cannot be applied to %3 because it's a temporary table")
.

//------------------------------------------------------------------------
/*590*/
MessageId       =IBP_MCE_FB25__TPB_READTXN_AFTER_WRITELOCK
Language        =Rus
_MC("Cannot set the transaction in read only mode after a table reservation isc_tpb_lock_write in TPB")
.

//------------------------------------------------------------------------
/*591*/
MessageId       =IBP_MCE_FB25__TPB_WRITELOCK_AFTER_READTXN
Language        =Rus
_MC("Cannot take a table reservation isc_tpb_lock_write in TPB because the transaction is in read only mode")
.

//------------------------------------------------------------------------
/*592*/
MessageId       =IBP_MCE_FB25__TIME_RANGE_EXCEEDED
Language        =Rus
_MC("value exceeds the range for a valid time")
.

//------------------------------------------------------------------------
/*593*/
MessageId       =IBP_MCE_FB25__DATETIME_RANGE_EXCEEDED
Language        =Rus
_MC("value exceeds the range for valid timestamps")
.

//------------------------------------------------------------------------
/*594*/
MessageId       =IBP_MCE_FB25__STRING_TRUNCATION
Language        =Rus
_MC("string right truncation")
.

//------------------------------------------------------------------------
/*595*/
MessageId       =IBP_MCE_FB25__BLOB_TRUNCATION
Language        =Rus
_MC("blob truncation when converting to a string: length limit exceeded")
.

//------------------------------------------------------------------------
/*596*/
MessageId       =IBP_MCE_FB25__NUMERIC_OUT_OF_RANGE
Language        =Rus
_MC("numeric value is out of range")
.

//------------------------------------------------------------------------
/*597*/
MessageId       =IBP_MCE_FB25__SHUTDOWN_TIMEOUT
Language        =Rus
_MC("Firebird shutdown is still in progress after the specified timeout")
.

//------------------------------------------------------------------------
/*598*/
MessageId       =IBP_MCE_FB25__ATT_HANDLE_BUSY
Language        =Rus
_MC("Attachment handle is busy")
.

//------------------------------------------------------------------------
/*599*/
MessageId       =IBP_MCE_FB25__BAD_UDF_FREEIT
Language        =Rus
_MC("Bad written UDF detected: pointer returned in FREE_IT function was not allocated by ib_util_malloc")
.

//------------------------------------------------------------------------
/*600*/
MessageId       =IBP_MCE_FB25__EDS_PROVIDER_NOT_FOUND
Language        =Rus
_MC("External Data Source provider '%1' not found")
.

//------------------------------------------------------------------------
/*601*/
MessageId       =IBP_MCE_FB25__EDS_CONNECTION
Language        =Rus
_MC("Execute statement error at %1 :\n"
    "%2Data source : %3")
.

//------------------------------------------------------------------------
/*602*/
MessageId       =IBP_MCE_FB25__EDS_PREPROCESS
Language        =Rus
_MC("Execute statement preprocess SQL error")
.

//------------------------------------------------------------------------
/*603*/
MessageId       =IBP_MCE_FB25__EDS_STMT_EXPECTED
Language        =Rus
_MC("Statement expected")
.

//------------------------------------------------------------------------
/*604*/
MessageId       =IBP_MCE_FB25__EDS_PRM_NAME_EXPECTED
Language        =Rus
_MC("Parameter name expected")
.

//------------------------------------------------------------------------
/*605*/
MessageId       =IBP_MCE_FB25__EDS_UNCLOSED_COMMENT
Language        =Rus
_MC("Unclosed comment found near '%1'")
.

//------------------------------------------------------------------------
/*606*/
MessageId       =IBP_MCE_FB25__EDS_STATEMENT
Language        =Rus
_MC("Execute statement error at %1 :\n"
    "%2Statement : %3\n"
    "Data source : %4")
.

//------------------------------------------------------------------------
/*607*/
MessageId       =IBP_MCE_FB25__EDS_INPUT_PRM_MISMATCH
Language        =Rus
_MC("Input parameters mismatch")
.

//------------------------------------------------------------------------
/*608*/
MessageId       =IBP_MCE_FB25__EDS_OUTPUT_PRM_MISMATCH
Language        =Rus
_MC("Output parameters mismatch")
.

//------------------------------------------------------------------------
/*609*/
MessageId       =IBP_MCE_FB25__EDS_INPUT_PRM_NOT_SET
Language        =Rus
_MC("Input parameter '%1' have no value set")
.

//------------------------------------------------------------------------
/*610*/
MessageId       =IBP_MCE_FB25__TOO_BIG_BLR
Language        =Rus
_MC("BLR stream length %1 exceeds implementation limit %2")
.

//------------------------------------------------------------------------
/*611*/
MessageId       =IBP_MCE_FB25__MONTABEXH
Language        =Rus
_MC("Monitoring table space exhausted")
.

//------------------------------------------------------------------------
/*612*/
MessageId       =IBP_MCE_FB25__MODNOTFOUND
Language        =Rus
_MC("module name or entrypoint could not be found")
.

//------------------------------------------------------------------------
/*613*/
MessageId       =IBP_MCE_FB25__NOTHING_TO_CANCEL
Language        =Rus
_MC("nothing to cancel")
.

//------------------------------------------------------------------------
/*614*/
MessageId       =IBP_MCE_FB25__IBUTIL_NOT_LOADED
Language        =Rus
_MC("ib_util library has not been loaded to deallocate memory returned by FREE_IT function")
.

//------------------------------------------------------------------------
/*615*/
MessageId       =IBP_MCE_FB25__CIRCULAR_COMPUTED
Language        =Rus
_MC("Cannot have circular dependencies with computed fields")
.

//------------------------------------------------------------------------
/*616*/
MessageId       =IBP_MCE_FB25__PSW_DB_ERROR
Language        =Rus
_MC("Security database error")
.

//------------------------------------------------------------------------
/*617*/
MessageId       =IBP_MCE_FB25__INVALID_TYPE_DATETIME_OP
Language        =Rus
_MC("Invalid data type in DATE/TIME/TIMESTAMP addition or subtraction in add_datettime()")
.

//------------------------------------------------------------------------
/*618*/
MessageId       =IBP_MCE_FB25__ONLYCAN_ADD_TIMETODATE
Language        =Rus
_MC("Only a TIME value can be added to a DATE value")
.

//------------------------------------------------------------------------
/*619*/
MessageId       =IBP_MCE_FB25__ONLYCAN_ADD_DATETOTIME
Language        =Rus
_MC("Only a DATE value can be added to a TIME value")
.

//------------------------------------------------------------------------
/*620*/
MessageId       =IBP_MCE_FB25__ONLYCANSUB_TSTAMPFROMTSTAMP
Language        =Rus
_MC("TIMESTAMP values can be subtracted only from another TIMESTAMP value")
.

//------------------------------------------------------------------------
/*621*/
MessageId       =IBP_MCE_FB25__ONLYONEOP_MUSTBE_TSTAMP
Language        =Rus
_MC("Only one operand can be of type TIMESTAMP")
.

//------------------------------------------------------------------------
/*622*/
MessageId       =IBP_MCE_FB25__INVALID_EXTRACTPART_TIME
Language        =Rus
_MC("Only HOUR, MINUTE, SECOND and MILLISECOND can be extracted from TIME values")
.

//------------------------------------------------------------------------
/*623*/
MessageId       =IBP_MCE_FB25__INVALID_EXTRACTPART_DATE
Language        =Rus
_MC("HOUR, MINUTE, SECOND and MILLISECOND cannot be extracted from DATE values")
.

//------------------------------------------------------------------------
/*624*/
MessageId       =IBP_MCE_FB25__INVALIDARG_EXTRACT
Language        =Rus
_MC("Invalid argument for EXTRACT() not being of DATE/TIME/TIMESTAMP type")
.

//------------------------------------------------------------------------
/*625*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_EXACT
Language        =Rus
_MC("Arguments for %1 must be integral types or NUMERIC/DECIMAL without scale")
.

//------------------------------------------------------------------------
/*626*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_EXACT_OR_FP
Language        =Rus
_MC("First argument for %1 must be integral type or floating point type")
.

//------------------------------------------------------------------------
/*627*/
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_UUIDTYPE
Language        =Rus
_MC("Human readable UUID argument for %1 must be of string type")
.

//------------------------------------------------------------------------
/*628*/
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_UUIDLEN
Language        =Rus
_MC("Human readable UUID argument for %2 must be of exact length %1")
.

//------------------------------------------------------------------------
/*629*/
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_UUIDFMT
Language        =Rus
_MC("Human readable UUID argument for %3 must have \"-\" at position %2 instead of \"%1\"")
.

//------------------------------------------------------------------------
/*630*/
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_GUIDIGITS
Language        =Rus
_MC("Human readable UUID argument for %3 must have hex digit at position %2 instead of \"%1\"")
.

//------------------------------------------------------------------------
/*631*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADDPART_TIME
Language        =Rus
_MC("Only HOUR, MINUTE, SECOND and MILLISECOND can be added to TIME values in %1")
.

//------------------------------------------------------------------------
/*632*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADD_DATETIME
Language        =Rus
_MC("Invalid data type in addition of part to DATE/TIME/TIMESTAMP in %1")
.

//------------------------------------------------------------------------
/*633*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADDPART_DTIME
Language        =Rus
_MC("Invalid part %1 to be added to a DATE/TIME/TIMESTAMP value in %2")
.

//------------------------------------------------------------------------
/*634*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADD_DTIME_RC
Language        =Rus
_MC("Expected DATE/TIME/TIMESTAMP type in evlDateAdd() result")
.

//------------------------------------------------------------------------
/*635*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_DIFF_DTIME
Language        =Rus
_MC("Expected DATE/TIME/TIMESTAMP type as first and second argument to %1")
.

//------------------------------------------------------------------------
/*636*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_TIMEDIFF
Language        =Rus
_MC("The result of TIME-<value> in %1 cannot be expressed in YEAR, MONTH, DAY or WEEK")
.

//------------------------------------------------------------------------
/*637*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_TSTAMPTIMEDIFF
Language        =Rus
_MC("The result of TIME-TIMESTAMP or TIMESTAMP-TIME in %1 cannot be expressed in HOUR, MINUTE, SECOND or MILLISECOND")
.

//------------------------------------------------------------------------
/*638*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_DATETIMEDIFF
Language        =Rus
_MC("The result of DATE-TIME or TIME-DATE in %1 cannot be expressed in HOUR, MINUTE, SECOND and MILLISECOND")
.

//------------------------------------------------------------------------
/*639*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_DIFFPART
Language        =Rus
_MC("Invalid part %1 to express the difference between two DATE/TIME/TIMESTAMP values in %2")
.

//------------------------------------------------------------------------
/*640*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_POSITIVE
Language        =Rus
_MC("Argument for %1 must be positive")
.

//------------------------------------------------------------------------
/*641*/
MessageId       =IBP_MCE_FB25__SYSF_BASEMUSTBE_POSITIVE
Language        =Rus
_MC("Base for %1 must be positive")
.

//------------------------------------------------------------------------
/*642*/
MessageId       =IBP_MCE_FB25__SYSF_ARGNMUSTBE_NONNEG
Language        =Rus
_MC("Argument #%1 for %2 must be zero or positive")
.

//------------------------------------------------------------------------
/*643*/
MessageId       =IBP_MCE_FB25__SYSF_ARGNMUSTBE_POSITIVE
Language        =Rus
_MC("Argument #%1 for %2 must be positive")
.

//------------------------------------------------------------------------
/*644*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ZEROPOWNEG
Language        =Rus
_MC("Base for %1 cannot be zero if exponent is negative")
.

//------------------------------------------------------------------------
/*645*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_NEGPOWFP
Language        =Rus
_MC("Base for %1 cannot be negative if exponent is not an integral value")
.

//------------------------------------------------------------------------
/*646*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_SCALE
Language        =Rus
_MC("The numeric scale must be between -128 and 127 in %1")
.

//------------------------------------------------------------------------
/*647*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_NONNEG
Language        =Rus
_MC("Argument for %1 must be zero or positive")
.

//------------------------------------------------------------------------
/*648*/
MessageId       =IBP_MCE_FB25__SYSF_BINUUID_MUSTBE_STR
Language        =Rus
_MC("Binary UUID argument for %1 must be of string type")
.

//------------------------------------------------------------------------
/*649*/
MessageId       =IBP_MCE_FB25__SYSF_BINUUID_WRONGSIZE
Language        =Rus
_MC("Binary UUID argument for %2 must use %1 bytes")
.

//------------------------------------------------------------------------
/*650*/
MessageId       =IBP_MCE_FB25__MISSING_REQUIRED_SPB
Language        =Rus
_MC("Missing required item %1 in service parameter block")
.

//------------------------------------------------------------------------
/*651*/
MessageId       =IBP_MCE_FB25__NET_SERVER_SHUTDOWN
Language        =Rus
_MC("%1 server is shutdown")
.

//------------------------------------------------------------------------
/*652*/
MessageId       =IBP_MCE_FB25__BAD_CONN_STR
Language        =Rus
_MC("Invalid connection string")
.

//------------------------------------------------------------------------
/*653*/
MessageId       =IBP_MCE_FB25__BAD_EPB_FORM
Language        =Rus
_MC("Unrecognized events block")
.

//------------------------------------------------------------------------
/*654*/
MessageId       =IBP_MCE_FB25__NO_THREADS
Language        =Rus
_MC("Could not start first worker thread - shutdown server")
.

//------------------------------------------------------------------------
/*655*/
MessageId       =IBP_MCE_FB25__NET_EVENT_CONNECT_TIMEOUT
Language        =Rus
_MC("Timeout occurred while waiting for a secondary connection for event processing")
.

//------------------------------------------------------------------------
/*656*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_NONZERO
Language        =Rus
_MC("Argument for %1 must be different than zero")
.

//------------------------------------------------------------------------
/*657*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_RANGE_INC1_1
Language        =Rus
_MC("Argument for %1 must be in the range [-1, 1]")
.

//------------------------------------------------------------------------
/*658*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_GTEQ_ONE
Language        =Rus
_MC("Argument for %1 must be greater or equal than one")
.

//------------------------------------------------------------------------
/*659*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_RANGE_EXC1_1
Language        =Rus
_MC("Argument for %1 must be in the range ]-1, 1[")
.

//------------------------------------------------------------------------
/*660*/
MessageId       =IBP_MCE_FB25__INTERNAL_REJECTED_PARAMS
Language        =Rus
_MC("Incorrect parameters provided to internal function %1")
.

//------------------------------------------------------------------------
/*661*/
MessageId       =IBP_MCE_FB25__SYSF_FP_OVERFLOW
Language        =Rus
_MC("Floating point overflow in built-in function %1")
.

//------------------------------------------------------------------------
/*662*/
MessageId       =IBP_MCE_FB25__UDF_FP_OVERFLOW
Language        =Rus
_MC("Floating point overflow in result from UDF %1")
.

//------------------------------------------------------------------------
/*663*/
MessageId       =IBP_MCE_FB25__UDF_FP_NAN
Language        =Rus
_MC("Invalid floating point value returned by UDF %1")
.

//------------------------------------------------------------------------
/*664*/
MessageId       =IBP_MCE_FB25__INSTANCE_CONFLICT
Language        =Rus
_MC("Database is probably already opened by another engine instance in another Windows session")
.

//------------------------------------------------------------------------
/*665*/
MessageId       =IBP_MCE_FB25__OUT_OF_TEMP_SPACE
Language        =Rus
_MC("No free space found in temporary directories")
.

//------------------------------------------------------------------------
/*666*/
MessageId       =IBP_MCE_FB25__EDS_EXPL_TRAN_CTRL
Language        =Rus
_MC("Explicit transaction control is not allowed")
.

//------------------------------------------------------------------------
/*667*/
MessageId       =IBP_MCE_FB25__NO_TRUSTED_SPB
Language        =Rus
_MC("Use of TRUSTED switches in spb_command_line is prohibited")
.

//------------------------------------------------------------------------
/*668*/
MessageId       =IBP_MCE_FB25__ASYNC_ACTIVE
Language        =Rus
_MC("Asynchronous call is already running for this attachment")
.

//------------------------------------------------------------------------
/*669*/
MessageId       =IBP_MCE_FB25__DSQL_DBKEY_FROM_NON_TABLE
Language        =Rus
_MC("Cannot SELECT RDB$DB_KEY from a stored procedure.")
.

//------------------------------------------------------------------------
/*670*/
MessageId       =IBP_MCE_FB25__DSQL_TRANSITIONAL_NUMERIC
Language        =Rus
_MC("Precision 10 to 18 changed from DOUBLE PRECISION in SQL dialect 1 to 64-bit scaled integer in SQL dialect 3")
.

//------------------------------------------------------------------------
/*671*/
MessageId       =IBP_MCE_FB25__DSQL_DIALECT_WARNING_EXPR
Language        =Rus
_MC("Use of %1 expression that returns different results in dialect 1 and dialect 3")
.

//------------------------------------------------------------------------
/*672*/
MessageId       =IBP_MCE_FB25__SQL_DB_DIALECT_DTYPE_UNSUPPORT
Language        =Rus
_MC("Database SQL dialect %1 does not support reference to %2 datatype")
.

//------------------------------------------------------------------------
/*673*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336003078
Language        =Rus
_MC("")
.

//------------------------------------------------------------------------
/*674*/
MessageId       =IBP_MCE_FB25__SQL_DIALECT_CONFLICT_NUM
Language        =Rus
_MC("DB dialect %1 and client dialect %2 conflict with respect to numeric precision %3.")
.

//------------------------------------------------------------------------
/*675*/
MessageId       =IBP_MCE_FB25__DSQL_WARNING_NUMBER_AMBIGUOUS
Language        =Rus
_MC("WARNING: Numeric literal %1 is interpreted as a floating-point")
.

//------------------------------------------------------------------------
/*676*/
MessageId       =IBP_MCE_FB25__DSQL_WARNING_NUMBER_AMBIGUOUS1
Language        =Rus
_MC("value in SQL dialect 1, but as an exact numeric value in SQL dialect 3.")
.

//------------------------------------------------------------------------
/*677*/
MessageId       =IBP_MCE_FB25__DSQL_WARN_PRECISION_AMBIGUOUS
Language        =Rus
_MC("WARNING: NUMERIC and DECIMAL fields with precision 10 or greater are stored")
.

//------------------------------------------------------------------------
/*678*/
MessageId       =IBP_MCE_FB25__DSQL_WARN_PRECISION_AMBIGUOUS1
Language        =Rus
_MC("as approximate floating-point values in SQL dialect 1, but as 64-bit")
.

//------------------------------------------------------------------------
/*679*/
MessageId       =IBP_MCE_FB25__DSQL_WARN_PRECISION_AMBIGUOUS2
Language        =Rus
_MC("integers in SQL dialect 3.")
.

//------------------------------------------------------------------------
/*680*/
MessageId       =IBP_MCE_FB25__DSQL_AMBIGUOUS_FIELD_NAME
Language        =Rus
_MC("Ambiguous field name between %1 and %2")
.

//------------------------------------------------------------------------
/*681*/
MessageId       =IBP_MCE_FB25__DSQL_UDF_RETURN_POS_ERR
Language        =Rus
_MC("External function should have return position between 1 and %1")
.

//------------------------------------------------------------------------
/*682*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_LABEL
Language        =Rus
_MC("Label %1 %2 in the current scope")
.

//------------------------------------------------------------------------
/*683*/
MessageId       =IBP_MCE_FB25__DSQL_DATATYPES_NOT_COMPARABLE
Language        =Rus
_MC("Datatypes %1are not comparable in expression %2")
.

//------------------------------------------------------------------------
/*684*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_INVALID
Language        =Rus
_MC("Empty cursor name is not allowed")
.

//------------------------------------------------------------------------
/*685*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_REDEFINED
Language        =Rus
_MC("Statement already has a cursor %1 assigned")
.

//------------------------------------------------------------------------
/*686*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_NOT_FOUND
Language        =Rus
_MC("Cursor %1 is not found in the current context")
.

//------------------------------------------------------------------------
/*687*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_EXISTS
Language        =Rus
_MC("Cursor %1 already exists in the current context")
.

//------------------------------------------------------------------------
/*688*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_REL_AMBIGUOUS
Language        =Rus
_MC("Relation %1 is ambiguous in cursor %2")
.

//------------------------------------------------------------------------
/*689*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_REL_NOT_FOUND
Language        =Rus
_MC("Relation %1 is not found in cursor %2")
.

//------------------------------------------------------------------------
/*690*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_NOT_OPEN
Language        =Rus
_MC("Cursor is not open")
.

//------------------------------------------------------------------------
/*691*/
MessageId       =IBP_MCE_FB25__DSQL_TYPE_NOT_SUPP_EXT_TAB
Language        =Rus
_MC("Data type %1 is not supported for EXTERNAL TABLES. Relation '%2', field '%3'")
.

//------------------------------------------------------------------------
/*692*/
MessageId       =IBP_MCE_FB25__DSQL_FEATURE_NOT_SUPPORTED_ODS
Language        =Rus
_MC("Feature not supported on ODS version older than %1.%2")
.

//------------------------------------------------------------------------
/*693*/
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_REQUIRED
Language        =Rus
_MC("Primary key required on table %1")
.

//------------------------------------------------------------------------
/*694*/
MessageId       =IBP_MCE_FB25__UPD_INS_DOESNT_MATCH_PK
Language        =Rus
_MC("UPDATE OR INSERT field list does not match primary key of table %1")
.

//------------------------------------------------------------------------
/*695*/
MessageId       =IBP_MCE_FB25__UPD_INS_DOESNT_MATCH_MATCHING
Language        =Rus
_MC("UPDATE OR INSERT field list does not match MATCHING clause")
.

//------------------------------------------------------------------------
/*696*/
MessageId       =IBP_MCE_FB25__UPD_INS_WITH_COMPLEX_VIEW
Language        =Rus
_MC("UPDATE OR INSERT without MATCHING could not be used with views based on more than one table")
.

//------------------------------------------------------------------------
/*697*/
MessageId       =IBP_MCE_FB25__DSQL_INCOMPATIBLE_TRIGGER_TYPE
Language        =Rus
_MC("Incompatible trigger type")
.

//------------------------------------------------------------------------
/*698*/
MessageId       =IBP_MCE_FB25__DSQL_DB_TRIGGER_TYPE_CANT_CHANGE
Language        =Rus
_MC("Database trigger type can't be changed")
.

//------------------------------------------------------------------------
/*699*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068609
Language        =Rus
_MC("ODS version not supported by DYN")
.

//------------------------------------------------------------------------
/*700*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068610
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*701*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068611
Language        =Rus
_MC("STORE RDB$FIELD_DIMENSIONS failed")
.

//------------------------------------------------------------------------
/*702*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068612
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*703*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068613
Language        =Rus
_MC("%1")
.

//------------------------------------------------------------------------
/*704*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068614
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*705*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068615
Language        =Rus
_MC("DEFINE BLOB FILTER failed")
.

//------------------------------------------------------------------------
/*706*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068616
Language        =Rus
_MC("DEFINE GENERATOR failed")
.

//------------------------------------------------------------------------
/*707*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068617
Language        =Rus
_MC("DEFINE GENERATOR unexpected DYN verb")
.

//------------------------------------------------------------------------
/*708*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068618
Language        =Rus
_MC("DEFINE FUNCTION failed")
.

//------------------------------------------------------------------------
/*709*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068619
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*710*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068620
Language        =Rus
_MC("DEFINE FUNCTION ARGUMENT failed")
.

//------------------------------------------------------------------------
/*711*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068621
Language        =Rus
_MC("STORE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*712*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068622
Language        =Rus
_MC("No table specified for index")
.

//------------------------------------------------------------------------
/*713*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068623
Language        =Rus
_MC("STORE RDB$INDEX_SEGMENTS failed")
.

//------------------------------------------------------------------------
/*714*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068624
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*715*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068625
Language        =Rus
_MC("PRIMARY KEY column lookup failed")
.

//------------------------------------------------------------------------
/*716*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068626
Language        =Rus
_MC("could not find UNIQUE or PRIMARY KEY constraint in table %1 with specified columns")
.

//------------------------------------------------------------------------
/*717*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068627
Language        =Rus
_MC("PRIMARY KEY lookup failed")
.

//------------------------------------------------------------------------
/*718*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068628
Language        =Rus
_MC("could not find PRIMARY KEY index in specified table %1")
.

//------------------------------------------------------------------------
/*719*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068629
Language        =Rus
_MC("STORE RDB$INDICES failed")
.

//------------------------------------------------------------------------
/*720*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068630
Language        =Rus
_MC("STORE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*721*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068631
Language        =Rus
_MC("STORE RDB$RELATION_FIELDS failed")
.

//------------------------------------------------------------------------
/*722*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068632
Language        =Rus
_MC("STORE RDB$RELATIONS failed")
.

//------------------------------------------------------------------------
/*723*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068633
Language        =Rus
_MC("STORE RDB$USER_PRIVILEGES failed defining a table")
.

//------------------------------------------------------------------------
/*724*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068634
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*725*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068635
Language        =Rus
_MC("STORE RDB$RELATIONS failed")
.

//------------------------------------------------------------------------
/*726*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068636
Language        =Rus
_MC("STORE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*727*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068637
Language        =Rus
_MC("STORE RDB$RELATION_FIELDS failed")
.

//------------------------------------------------------------------------
/*728*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068638
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*729*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068639
Language        =Rus
_MC("DEFINE TRIGGER failed")
.

//------------------------------------------------------------------------
/*730*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068640
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*731*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068641
Language        =Rus
_MC("DEFINE TRIGGER MESSAGE failed")
.

//------------------------------------------------------------------------
/*732*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068642
Language        =Rus
_MC("STORE RDB$VIEW_RELATIONS failed")
.

//------------------------------------------------------------------------
/*733*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068643
Language        =Rus
_MC("ERASE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*734*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068644
Language        =Rus
_MC("ERASE BLOB FILTER failed")
.

//------------------------------------------------------------------------
/*735*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068645
Language        =Rus
_MC("BLOB Filter %1 not found")
.

//------------------------------------------------------------------------
/*736*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068646
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*737*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068647
Language        =Rus
_MC("ERASE RDB$FUNCTION_ARGUMENTS failed")
.

//------------------------------------------------------------------------
/*738*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068648
Language        =Rus
_MC("ERASE RDB$FUNCTIONS failed")
.

//------------------------------------------------------------------------
/*739*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068649
Language        =Rus
_MC("Function %1 not found")
.

//------------------------------------------------------------------------
/*740*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068650
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*741*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068651
Language        =Rus
_MC("Domain %1 is used in table %2 (local name %3) and cannot be dropped")
.

//------------------------------------------------------------------------
/*742*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068652
Language        =Rus
_MC("ERASE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*743*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068653
Language        =Rus
_MC("ERASE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*744*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068654
Language        =Rus
_MC("Column not found")
.

//------------------------------------------------------------------------
/*745*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068655
Language        =Rus
_MC("ERASE RDB$INDICES failed")
.

//------------------------------------------------------------------------
/*746*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068656
Language        =Rus
_MC("Index not found")
.

//------------------------------------------------------------------------
/*747*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068657
Language        =Rus
_MC("ERASE RDB$INDEX_SEGMENTS failed")
.

//------------------------------------------------------------------------
/*748*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068658
Language        =Rus
_MC("No segments found for index")
.

//------------------------------------------------------------------------
/*749*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068659
Language        =Rus
_MC("No table specified in ERASE RFR")
.

//------------------------------------------------------------------------
/*750*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068660
Language        =Rus
_MC("Column %1 from table %2 is referenced in view %3")
.

//------------------------------------------------------------------------
/*751*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068661
Language        =Rus
_MC("ERASE RDB$RELATION_FIELDS failed")
.

//------------------------------------------------------------------------
/*752*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068662
Language        =Rus
_MC("View %1 not found")
.

//------------------------------------------------------------------------
/*753*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068663
Language        =Rus
_MC("Column not found for table")
.

//------------------------------------------------------------------------
/*754*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068664
Language        =Rus
_MC("ERASE RDB$INDEX_SEGMENTS failed")
.

//------------------------------------------------------------------------
/*755*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068665
Language        =Rus
_MC("ERASE RDB$INDICES failed")
.

//------------------------------------------------------------------------
/*756*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068666
Language        =Rus
_MC("ERASE RDB$RELATION_FIELDS failed")
.

//------------------------------------------------------------------------
/*757*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068667
Language        =Rus
_MC("ERASE RDB$VIEW_RELATIONS failed")
.

//------------------------------------------------------------------------
/*758*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068668
Language        =Rus
_MC("ERASE RDB$RELATIONS failed")
.

//------------------------------------------------------------------------
/*759*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068669
Language        =Rus
_MC("Table not found")
.

//------------------------------------------------------------------------
/*760*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068670
Language        =Rus
_MC("ERASE RDB$USER_PRIVILEGES failed")
.

//------------------------------------------------------------------------
/*761*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068671
Language        =Rus
_MC("ERASE RDB$FILES failed")
.

//------------------------------------------------------------------------
/*762*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068672
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*763*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068673
Language        =Rus
_MC("ERASE RDB$TRIGGER_MESSAGES failed")
.

//------------------------------------------------------------------------
/*764*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068674
Language        =Rus
_MC("ERASE RDB$TRIGGERS failed")
.

//------------------------------------------------------------------------
/*765*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068675
Language        =Rus
_MC("Trigger not found")
.

//------------------------------------------------------------------------
/*766*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068676
Language        =Rus
_MC("MODIFY RDB$VIEW_RELATIONS failed")
.

//------------------------------------------------------------------------
/*767*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068677
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*768*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068678
Language        =Rus
_MC("TRIGGER NAME expected")
.

//------------------------------------------------------------------------
/*769*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068679
Language        =Rus
_MC("ERASE TRIGGER MESSAGE failed")
.

//------------------------------------------------------------------------
/*770*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068680
Language        =Rus
_MC("Trigger Message not found")
.

//------------------------------------------------------------------------
/*771*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068681
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*772*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068682
Language        =Rus
_MC("ERASE RDB$SECURITY_CLASSES failed")
.

//------------------------------------------------------------------------
/*773*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068683
Language        =Rus
_MC("Security class not found")
.

//------------------------------------------------------------------------
/*774*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068684
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*775*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068685
Language        =Rus
_MC("SELECT RDB$USER_PRIVILEGES failed in grant")
.

//------------------------------------------------------------------------
/*776*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068686
Language        =Rus
_MC("SELECT RDB$USER_PRIVILEGES failed in grant")
.

//------------------------------------------------------------------------
/*777*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068687
Language        =Rus
_MC("STORE RDB$USER_PRIVILEGES failed in grant")
.

//------------------------------------------------------------------------
/*778*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068688
Language        =Rus
_MC("Specified domain or source column does not exist")
.

//------------------------------------------------------------------------
/*779*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068689
Language        =Rus
_MC("Generation of column name failed")
.

//------------------------------------------------------------------------
/*780*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068690
Language        =Rus
_MC("Generation of index name failed")
.

//------------------------------------------------------------------------
/*781*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068691
Language        =Rus
_MC("Generation of trigger name failed")
.

//------------------------------------------------------------------------
/*782*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068692
Language        =Rus
_MC("MODIFY DATABASE failed")
.

//------------------------------------------------------------------------
/*783*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068693
Language        =Rus
_MC("MODIFY RDB$CHARACTER_SETS failed")
.

//------------------------------------------------------------------------
/*784*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068694
Language        =Rus
_MC("MODIFY RDB$COLLATIONS failed")
.

//------------------------------------------------------------------------
/*785*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068695
Language        =Rus
_MC("MODIFY RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*786*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068696
Language        =Rus
_MC("MODIFY RDB$BLOB_FILTERS failed")
.

//------------------------------------------------------------------------
/*787*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068697
Language        =Rus
_MC("Domain not found")
.

//------------------------------------------------------------------------
/*788*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068698
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*789*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068699
Language        =Rus
_MC("MODIFY RDB$INDICES failed")
.

//------------------------------------------------------------------------
/*790*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068700
Language        =Rus
_MC("MODIFY RDB$FUNCTIONS failed")
.

//------------------------------------------------------------------------
/*791*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068701
Language        =Rus
_MC("Index column not found")
.

//------------------------------------------------------------------------
/*792*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068702
Language        =Rus
_MC("MODIFY RDB$GENERATORS failed")
.

//------------------------------------------------------------------------
/*793*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068703
Language        =Rus
_MC("MODIFY RDB$RELATION_FIELDS failed")
.

//------------------------------------------------------------------------
/*794*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068704
Language        =Rus
_MC("Local column %1 not found")
.

//------------------------------------------------------------------------
/*795*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068705
Language        =Rus
_MC("add EXTERNAL FILE not allowed")
.

//------------------------------------------------------------------------
/*796*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068706
Language        =Rus
_MC("drop EXTERNAL FILE not allowed")
.

//------------------------------------------------------------------------
/*797*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068707
Language        =Rus
_MC("MODIFY RDB$RELATIONS failed")
.

//------------------------------------------------------------------------
/*798*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068708
Language        =Rus
_MC("MODIFY RDB$PROCEDURE_PARAMETERS failed")
.

//------------------------------------------------------------------------
/*799*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068709
Language        =Rus
_MC("Table column not found")
.

//------------------------------------------------------------------------
/*800*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068710
Language        =Rus
_MC("MODIFY TRIGGER failed")
.

//------------------------------------------------------------------------
/*801*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068711
Language        =Rus
_MC("TRIGGER NAME expected")
.

//------------------------------------------------------------------------
/*802*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068712
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*803*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068713
Language        =Rus
_MC("MODIFY TRIGGER MESSAGE failed")
.

//------------------------------------------------------------------------
/*804*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068714
Language        =Rus
_MC("Create metadata BLOB failed")
.

//------------------------------------------------------------------------
/*805*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068715
Language        =Rus
_MC("Write metadata BLOB failed")
.

//------------------------------------------------------------------------
/*806*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068716
Language        =Rus
_MC("Close metadata BLOB failed")
.

//------------------------------------------------------------------------
/*807*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068717
Language        =Rus
_MC("Triggers created automatically cannot be modified")
.

//------------------------------------------------------------------------
/*808*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068718
Language        =Rus
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*809*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068719
Language        =Rus
_MC("ERASE RDB$USER_PRIVILEGES failed in revoke(1)")
.

//------------------------------------------------------------------------
/*810*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068720
Language        =Rus
_MC("Access to RDB$USER_PRIVILEGES failed in revoke(2)")
.

//------------------------------------------------------------------------
/*811*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068721
Language        =Rus
_MC("ERASE RDB$USER_PRIVILEGES failed in revoke (3)")
.

//------------------------------------------------------------------------
/*812*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068722
Language        =Rus
_MC("Access to RDB$USER_PRIVILEGES failed in revoke (4)")
.

//------------------------------------------------------------------------
/*813*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068723
Language        =Rus
_MC("CREATE VIEW failed")
.

//------------------------------------------------------------------------
/*814*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068724
Language        =Rus
_MC("attempt to index BLOB column in INDEX %1")
.

//------------------------------------------------------------------------
/*815*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068725
Language        =Rus
_MC("attempt to index array column in index %1")
.

//------------------------------------------------------------------------
/*816*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068726
Language        =Rus
_MC("key size too big for index %1")
.

//------------------------------------------------------------------------
/*817*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068727
Language        =Rus
_MC("no keys for index %1")
.

//------------------------------------------------------------------------
/*818*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068728
Language        =Rus
_MC("Unknown columns in index %1")
.

//------------------------------------------------------------------------
/*819*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068729
Language        =Rus
_MC("STORE RDB$RELATION_CONSTRAINTS failed")
.

//------------------------------------------------------------------------
/*820*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068730
Language        =Rus
_MC("STORE RDB$CHECK_CONSTRAINTS failed")
.

//------------------------------------------------------------------------
/*821*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068731
Language        =Rus
_MC("Column: %1 not defined as NOT NULL - cannot be used in PRIMARY KEY constraint definition")
.

//------------------------------------------------------------------------
/*822*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068732
Language        =Rus
_MC("A column name is repeated in the definition of constraint: %1")
.

//------------------------------------------------------------------------
/*823*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068733
Language        =Rus
_MC("Integrity Constraint lookup failed")
.

//------------------------------------------------------------------------
/*824*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068734
Language        =Rus
_MC("Same set of columns cannot be used in more than one PRIMARY KEY and/or UNIQUE constraint definition")
.

//------------------------------------------------------------------------
/*825*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068735
Language        =Rus
_MC("STORE RDB$REF_CONSTRAINTS failed")
.

//------------------------------------------------------------------------
/*826*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068736
Language        =Rus
_MC("No table specified in delete_constraint")
.

//------------------------------------------------------------------------
/*827*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068737
Language        =Rus
_MC("ERASE RDB$RELATION_CONSTRAINTS failed")
.

//------------------------------------------------------------------------
/*828*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068738
Language        =Rus
_MC("CONSTRAINT %1 does not exist.")
.

//------------------------------------------------------------------------
/*829*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068739
Language        =Rus
_MC("Generation of constraint name failed")
.

//------------------------------------------------------------------------
/*830*/
MessageId       =IBP_MCE_FB25__DYN_DUP_TABLE
Language        =Rus
_MC("Table %1 already exists")
.

//------------------------------------------------------------------------
/*831*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068741
Language        =Rus
_MC("Number of referencing columns do not equal number of referenced columns")
.

//------------------------------------------------------------------------
/*832*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068742
Language        =Rus
_MC("STORE RDB$PROCEDURES failed")
.

//------------------------------------------------------------------------
/*833*/
MessageId       =IBP_MCE_FB25__DYN_DUP_PROCEDURE
Language        =Rus
_MC("Procedure %1 already exists")
.

//------------------------------------------------------------------------
/*834*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068744
Language        =Rus
_MC("STORE RDB$PROCEDURE_PARAMETERS failed")
.

//------------------------------------------------------------------------
/*835*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068745
Language        =Rus
_MC("Store into system table %1 failed")
.

//------------------------------------------------------------------------
/*836*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068746
Language        =Rus
_MC("ERASE RDB$PROCEDURE_PARAMETERS failed")
.

//------------------------------------------------------------------------
/*837*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068747
Language        =Rus
_MC("ERASE RDB$PROCEDURES failed")
.

//------------------------------------------------------------------------
/*838*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068748
Language        =Rus
_MC("Procedure %1 not found")
.

//------------------------------------------------------------------------
/*839*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068749
Language        =Rus
_MC("MODIFY RDB$PROCEDURES failed")
.

//------------------------------------------------------------------------
/*840*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068750
Language        =Rus
_MC("DEFINE EXCEPTION failed")
.

//------------------------------------------------------------------------
/*841*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068751
Language        =Rus
_MC("ERASE EXCEPTION failed")
.

//------------------------------------------------------------------------
/*842*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068752
Language        =Rus
_MC("Exception not found")
.

//------------------------------------------------------------------------
/*843*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068753
Language        =Rus
_MC("MODIFY EXCEPTION failed")
.

//------------------------------------------------------------------------
/*844*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068754
Language        =Rus
_MC("Parameter %1 in procedure %2 not found")
.

//------------------------------------------------------------------------
/*845*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068755
Language        =Rus
_MC("Trigger %1 not found")
.

//------------------------------------------------------------------------
/*846*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068756
Language        =Rus
_MC("Only one data type change to the domain %1 allowed at a time")
.

//------------------------------------------------------------------------
/*847*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068757
Language        =Rus
_MC("Only one data type change to the field %1 allowed at a time")
.

//------------------------------------------------------------------------
/*848*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068758
Language        =Rus
_MC("STORE RDB$FILES failed")
.

//------------------------------------------------------------------------
/*849*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068759
Language        =Rus
_MC("Character set %1 not found")
.

//------------------------------------------------------------------------
/*850*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068760
Language        =Rus
_MC("Collation %1 not found")
.

//------------------------------------------------------------------------
/*851*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068761
Language        =Rus
_MC("ERASE RDB$LOG_FILES failed")
.

//------------------------------------------------------------------------
/*852*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068762
Language        =Rus
_MC("STORE RDB$LOG_FILES failed")
.

//------------------------------------------------------------------------
/*853*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068763
Language        =Rus
_MC("Role %1 not found")
.

//------------------------------------------------------------------------
/*854*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068764
Language        =Rus
_MC("Difference file lookup failed")
.

//------------------------------------------------------------------------
/*855*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068765
Language        =Rus
_MC("DEFINE SHADOW failed")
.

//------------------------------------------------------------------------
/*856*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068766
Language        =Rus
_MC("MODIFY RDB$ROLES failed")
.

//------------------------------------------------------------------------
/*857*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068767
Language        =Rus
_MC("Name longer than database column size")
.

//------------------------------------------------------------------------
/*858*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068768
Language        =Rus
_MC("\"Only one constraint allowed for a domain\"")
.

//------------------------------------------------------------------------
/*859*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068770
Language        =Rus
_MC("Looking up column position failed")
.

//------------------------------------------------------------------------
/*860*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068771
Language        =Rus
_MC("A node name is not permitted in a table with external file definition")
.

//------------------------------------------------------------------------
/*861*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068772
Language        =Rus
_MC("Shadow lookup failed")
.

//------------------------------------------------------------------------
/*862*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068773
Language        =Rus
_MC("Shadow %1 already exists")
.

//------------------------------------------------------------------------
/*863*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068774
Language        =Rus
_MC("Cannot add file with the same name as the database or added files")
.

//------------------------------------------------------------------------
/*864*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068775
Language        =Rus
_MC("no grant option for privilege %1 on column %2 of table/view %3")
.

//------------------------------------------------------------------------
/*865*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068776
Language        =Rus
_MC("no grant option for privilege %1 on column %2 of base table/view %3")
.

//------------------------------------------------------------------------
/*866*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068777
Language        =Rus
_MC("no grant option for privilege %1 on table/view %2 (for column %3)")
.

//------------------------------------------------------------------------
/*867*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068778
Language        =Rus
_MC("no grant option for privilege %1 on base table/view %2 (for column %3)")
.

//------------------------------------------------------------------------
/*868*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068779
Language        =Rus
_MC("no %1 privilege with grant option on table/view %2 (for column %3)")
.

//------------------------------------------------------------------------
/*869*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068780
Language        =Rus
_MC("no %1 privilege with grant option on base table/view %2 (for column %3)")
.

//------------------------------------------------------------------------
/*870*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068781
Language        =Rus
_MC("no grant option for privilege %1 on table/view %2")
.

//------------------------------------------------------------------------
/*871*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068782
Language        =Rus
_MC("no %1 privilege with grant option on table/view %2")
.

//------------------------------------------------------------------------
/*872*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068783
Language        =Rus
_MC("table/view %1 does not exist")
.

//------------------------------------------------------------------------
/*873*/
MessageId       =IBP_MCE_FB25__DYN_COLUMN_DOES_NOT_EXIST
Language        =Rus
_MC("column %1 does not exist in table/view %2")
.

//------------------------------------------------------------------------
/*874*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068785
Language        =Rus
_MC("Can not alter a view")
.

//------------------------------------------------------------------------
/*875*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068786
Language        =Rus
_MC("EXTERNAL FILE table not supported in this context")
.

//------------------------------------------------------------------------
/*876*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068787
Language        =Rus
_MC("attempt to index COMPUTED BY column in INDEX %1")
.

//------------------------------------------------------------------------
/*877*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068788
Language        =Rus
_MC("Table Name lookup failed")
.

//------------------------------------------------------------------------
/*878*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068789
Language        =Rus
_MC("attempt to index a view")
.

//------------------------------------------------------------------------
/*879*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068790
Language        =Rus
_MC("SELECT RDB$RELATIONS failed in grant")
.

//------------------------------------------------------------------------
/*880*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068791
Language        =Rus
_MC("SELECT RDB$RELATION_FIELDS failed in grant")
.

//------------------------------------------------------------------------
/*881*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068792
Language        =Rus
_MC("SELECT RDB$RELATIONS/RDB$OWNER_NAME failed in grant")
.

//------------------------------------------------------------------------
/*882*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068793
Language        =Rus
_MC("SELECT RDB$USER_PRIVILEGES failed in grant")
.

//------------------------------------------------------------------------
/*883*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068794
Language        =Rus
_MC("SELECT RDB$VIEW_RELATIONS/RDB$RELATION_FIELDS/... failed in grant")
.

//------------------------------------------------------------------------
/*884*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068795
Language        =Rus
_MC("column %1 from table %2 is referenced in index %3")
.

//------------------------------------------------------------------------
/*885*/
MessageId       =IBP_MCE_FB25__DYN_ROLE_DOES_NOT_EXIST
Language        =Rus
_MC("SQL role %1 does not exist")
.

//------------------------------------------------------------------------
/*886*/
MessageId       =IBP_MCE_FB25__DYN_NO_GRANT_ADMIN_OPT
Language        =Rus
_MC("user %1 has no grant admin option on SQL role %2")
.

//------------------------------------------------------------------------
/*887*/
MessageId       =IBP_MCE_FB25__DYN_USER_NOT_ROLE_MEMBER
Language        =Rus
_MC("user %1 is not a member of SQL role %2")
.

//------------------------------------------------------------------------
/*888*/
MessageId       =IBP_MCE_FB25__DYN_DELETE_ROLE_FAILED
Language        =Rus
_MC("%1 is not the owner of SQL role %2")
.

//------------------------------------------------------------------------
/*889*/
MessageId       =IBP_MCE_FB25__DYN_GRANT_ROLE_TO_USER
Language        =Rus
_MC("%1 is a SQL role and not a user")
.

//------------------------------------------------------------------------
/*890*/
MessageId       =IBP_MCE_FB25__DYN_INV_SQL_ROLE_NAME
Language        =Rus
_MC("user name %1 could not be used for SQL role")
.

//------------------------------------------------------------------------
/*891*/
MessageId       =IBP_MCE_FB25__DYN_DUP_SQL_ROLE
Language        =Rus
_MC("SQL role %1 already exists")
.

//------------------------------------------------------------------------
/*892*/
MessageId       =IBP_MCE_FB25__DYN_KYWD_SPEC_FOR_ROLE
Language        =Rus
_MC("keyword %1 can not be used as a SQL role name")
.

//------------------------------------------------------------------------
/*893*/
MessageId       =IBP_MCE_FB25__DYN_ROLES_NOT_SUPPORTED
Language        =Rus
_MC("SQL roles are not supported in on older versions of the database. A backup and restore of the database is required.")
.

//------------------------------------------------------------------------
/*894*/
MessageId       =IBP_MCE_FB25__DYN_DOMAIN_NAME_EXISTS
Language        =Rus
_MC("Cannot rename domain %1 to %2. A domain with that name already exists.")
.

//------------------------------------------------------------------------
/*895*/
MessageId       =IBP_MCE_FB25__DYN_FIELD_NAME_EXISTS
Language        =Rus
_MC("Cannot rename column %1 to %2. A column with that name already exists in table %3.")
.

//------------------------------------------------------------------------
/*896*/
MessageId       =IBP_MCE_FB25__DYN_DEPENDENCY_EXISTS
Language        =Rus
_MC("Column %1 from table %2 is referenced in %3")
.

//------------------------------------------------------------------------
/*897*/
MessageId       =IBP_MCE_FB25__DYN_DTYPE_INVALID
Language        =Rus
_MC("Cannot change datatype for column %1. Changing datatype is not supported for BLOB or ARRAY columns.")
.

//------------------------------------------------------------------------
/*898*/
MessageId       =IBP_MCE_FB25__DYN_CHAR_FLD_TOO_SMALL
Language        =Rus
_MC("New size specified for column %1 must be at least %2 characters.")
.

//------------------------------------------------------------------------
/*899*/
MessageId       =IBP_MCE_FB25__DYN_INVALID_DTYPE_CONVERSION
Language        =Rus
_MC("Cannot change datatype for %1. Conversion from base type %2 to %3 is not supported.")
.

//------------------------------------------------------------------------
/*900*/
MessageId       =IBP_MCE_FB25__DYN_DTYPE_CONV_INVALID
Language        =Rus
_MC("Cannot change datatype for column %1 from a character type to a non-character type.")
.

//------------------------------------------------------------------------
/*901*/
MessageId       =IBP_MCE_FB25__DYN_VIRMEMEXH
Language        =Rus
_MC("unable to allocate memory from the operating system")
.

//------------------------------------------------------------------------
/*902*/
MessageId       =IBP_MCE_FB25__DYN_ZERO_LEN_ID
Language        =Rus
_MC("Zero length identifiers are not allowed")
.

//------------------------------------------------------------------------
/*903*/
MessageId       =IBP_MCE_FB25__DEL_GEN_FAIL
Language        =Rus
_MC("ERASE RDB$GENERATORS failed")
.

//------------------------------------------------------------------------
/*904*/
MessageId       =IBP_MCE_FB25__DYN_GEN_NOT_FOUND
Language        =Rus
_MC("Generator %1 not found")
.

//------------------------------------------------------------------------
/*905*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068823
Language        =Rus
_MC("Difference file is not defined")
.

//------------------------------------------------------------------------
/*906*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068824
Language        =Rus
_MC("Difference file is already defined")
.

//------------------------------------------------------------------------
/*907*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068825
Language        =Rus
_MC("Database is already in the physical backup mode")
.

//------------------------------------------------------------------------
/*908*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068826
Language        =Rus
_MC("Database is not in the physical backup mode")
.

//------------------------------------------------------------------------
/*909*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068827
Language        =Rus
_MC("DEFINE COLLATION failed")
.

//------------------------------------------------------------------------
/*910*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068828
Language        =Rus
_MC("CREATE COLLATION statement is not supported in older versions of the database. A backup and restore is required.")
.

//------------------------------------------------------------------------
/*911*/
MessageId       =IBP_MCE_FB25__MAX_COLL_PER_CHARSET
Language        =Rus
_MC("Maximum number of collations per character set exceeded")
.

//------------------------------------------------------------------------
/*912*/
MessageId       =IBP_MCE_FB25__INVALID_COLL_ATTR
Language        =Rus
_MC("Invalid collation attributes")
.

//------------------------------------------------------------------------
/*913*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068831
Language        =Rus
_MC("Collation %1 not installed for character set %2")
.

//------------------------------------------------------------------------
/*914*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068832
Language        =Rus
_MC("Cannot use the internal domain %1 as new type for field %2")
.

//------------------------------------------------------------------------
/*915*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068833
Language        =Rus
_MC("Default value is not allowed for array type in field %1")
.

//------------------------------------------------------------------------
/*916*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068834
Language        =Rus
_MC("Default value is not allowed for array type in domain %1")
.

//------------------------------------------------------------------------
/*917*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068835
Language        =Rus
_MC("DYN_UTIL_is_array failed for domain %1")
.

//------------------------------------------------------------------------
/*918*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068836
Language        =Rus
_MC("DYN_UTIL_copy_domain failed for domain %1")
.

//------------------------------------------------------------------------
/*919*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068837
Language        =Rus
_MC("Local column %1 doesn't have a default")
.

//------------------------------------------------------------------------
/*920*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068838
Language        =Rus
_MC("Local column %1 default belongs to domain %2")
.

//------------------------------------------------------------------------
/*921*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068839
Language        =Rus
_MC("File name is invalid")
.

//------------------------------------------------------------------------
/*922*/
MessageId       =IBP_MCE_FB25__DYN_WRONG_GTT_SCOPE
Language        =Rus
_MC("%1 cannot reference %2")
.

//------------------------------------------------------------------------
/*923*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068841
Language        =Rus
_MC("Local column %1 is computed, cannot set a default value")
.

//------------------------------------------------------------------------
/*924*/
MessageId       =IBP_MCE_FB25__DEL_COLL_FAIL
Language        =Rus
_MC("ERASE RDB$COLLATIONS failed")
.

//------------------------------------------------------------------------
/*925*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068843
Language        =Rus
_MC("Collation %1 is used in table %2 (field name %3) and cannot be dropped")
.

//------------------------------------------------------------------------
/*926*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068844
Language        =Rus
_MC("Collation %1 is used in domain %2 and cannot be dropped")
.

//------------------------------------------------------------------------
/*927*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068845
Language        =Rus
_MC("Cannot delete system collation")
.

//------------------------------------------------------------------------
/*928*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068846
Language        =Rus
_MC("Cannot delete default collation of CHARACTER SET %1")
.

//------------------------------------------------------------------------
/*929*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068847
Language        =Rus
_MC("Domain %1 is used in procedure %2 (parameter name %3) and cannot be dropped")
.

//------------------------------------------------------------------------
/*930*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068848
Language        =Rus
_MC("Field %1 cannot be used twice in index %2")
.

//------------------------------------------------------------------------
/*931*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068849
Language        =Rus
_MC("Table %1 not found")
.

//------------------------------------------------------------------------
/*932*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068850
Language        =Rus
_MC("attempt to reference a view (%1) in a foreign key")
.

//------------------------------------------------------------------------
/*933*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068851
Language        =Rus
_MC("Collation %1 is used in procedure %2 (parameter name %3) and cannot be dropped")
.

//------------------------------------------------------------------------
/*934*/
MessageId       =IBP_MCE_FB25__DYN_SCALE_TOO_BIG
Language        =Rus
_MC("New scale specified for column %1 must be at most %2.")
.

//------------------------------------------------------------------------
/*935*/
MessageId       =IBP_MCE_FB25__DYN_PRECISION_TOO_SMALL
Language        =Rus
_MC("New precision specified for column %1 must be at least %2.")
.

//------------------------------------------------------------------------
/*936*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068854
Language        =Rus
_MC("%1 is not grantor of %2 on %3 to %4.")
.

//------------------------------------------------------------------------
/*937*/
MessageId       =IBP_MCE_FB25__DYN_MISS_PRIV_WARNING
Language        =Rus
_MC("Warning: %1 on %2 is not granted to %3.")
.

//------------------------------------------------------------------------
/*938*/
MessageId       =IBP_MCE_FB25__DYN_ODS_NOT_SUPP_FEATURE
Language        =Rus
_MC("Feature '%1' is not supported in ODS %2.%3")
.

//------------------------------------------------------------------------
/*939*/
MessageId       =IBP_MCE_FB25__DYN_CANNOT_ADDREM_COMPUTED
Language        =Rus
_MC("Cannot add or remove COMPUTED from column %1")
.

//------------------------------------------------------------------------
/*940*/
MessageId       =IBP_MCE_FB25__DYN_NO_EMPTY_PW
Language        =Rus
_MC("Password should not be empty string")
.

//------------------------------------------------------------------------
/*941*/
MessageId       =IBP_MCE_FB25__DYN_DUP_INDEX
Language        =Rus
_MC("Index %1 already exists")
.

//------------------------------------------------------------------------
/*942*/
MessageId       =IBP_MCE_FB25__DYN_LOCKSMITH_USE_GRANTED
Language        =Rus
_MC("Only %1 or database owner can use GRANTED BY clause")
.

//------------------------------------------------------------------------
/*943*/
MessageId       =IBP_MCE_FB25__DYN_DUP_EXCEPTION
Language        =Rus
_MC("Exception %1 already exists")
.

//------------------------------------------------------------------------
/*944*/
MessageId       =IBP_MCE_FB25__DYN_DUP_GENERATOR
Language        =Rus
_MC("Generator %1 already exists")
.

//------------------------------------------------------------------------
/*945*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068863
Language        =Rus
_MC("ERASE RDB$USER_PRIVILEGES failed in REVOKE ALL ON ALL")
.

//------------------------------------------------------------------------
/*946*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068892
Language        =Rus
_MC("Cannot delete system SQL role %1")
.

//------------------------------------------------------------------------
/*947*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396289
Language        =Rus
_MC("Firebird error")
.

//------------------------------------------------------------------------
/*948*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396362
Language        =Rus
_MC("Rollback not performed")
.

//------------------------------------------------------------------------
/*949*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396364
Language        =Rus
_MC("Connection error")
.

//------------------------------------------------------------------------
/*950*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396365
Language        =Rus
_MC("Connection not established")
.

//------------------------------------------------------------------------
/*951*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396366
Language        =Rus
_MC("Connection authorization failure.")
.

//------------------------------------------------------------------------
/*952*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396375
Language        =Rus
_MC("deadlock")
.

//------------------------------------------------------------------------
/*953*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396376
Language        =Rus
_MC("Unsuccessful execution caused by deadlock.")
.

//------------------------------------------------------------------------
/*954*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396377
Language        =Rus
_MC("record from transaction %1 is stuck in limbo")
.

//------------------------------------------------------------------------
/*955*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396379
Language        =Rus
_MC("operation completed with errors")
.

//------------------------------------------------------------------------
/*956*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396382
Language        =Rus
_MC("the SQL statement cannot be executed")
.

//------------------------------------------------------------------------
/*957*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396384
Language        =Rus
_MC("Unsuccessful execution caused by an unavailable resource.")
.

//------------------------------------------------------------------------
/*958*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396386
Language        =Rus
_MC("Unsuccessful execution caused by a system error that precludes successful execution of subsequent statements")
.

//------------------------------------------------------------------------
/*959*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396387
Language        =Rus
_MC("Unsuccessful execution caused by system error that does not preclude successful execution of subsequent statements")
.

//------------------------------------------------------------------------
/*960*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396446
Language        =Rus
_MC("Wrong numeric type")
.

//------------------------------------------------------------------------
/*961*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396447
Language        =Rus
_MC("too many versions")
.

//------------------------------------------------------------------------
/*962*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396448
Language        =Rus
_MC("intermediate journal file full")
.

//------------------------------------------------------------------------
/*963*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396449
Language        =Rus
_MC("journal file wrong format")
.

//------------------------------------------------------------------------
/*964*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396450
Language        =Rus
_MC("database %1 shutdown in %2 seconds")
.

//------------------------------------------------------------------------
/*965*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396451
Language        =Rus
_MC("restart shared cache manager")
.

//------------------------------------------------------------------------
/*966*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396452
Language        =Rus
_MC("exception %1")
.

//------------------------------------------------------------------------
/*967*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396453
Language        =Rus
_MC("bad checksum")
.

//------------------------------------------------------------------------
/*968*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396454
Language        =Rus
_MC("refresh range number %1 not found")
.

//------------------------------------------------------------------------
/*969*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396455
Language        =Rus
_MC("expression evaluation not supported")
.

//------------------------------------------------------------------------
/*970*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396456
Language        =Rus
_MC("FOREIGN KEY column count does not match PRIMARY KEY")
.

//------------------------------------------------------------------------
/*971*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396457
Language        =Rus
_MC("Attempt to define a second PRIMARY KEY for the same table")
.

//------------------------------------------------------------------------
/*972*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396458
Language        =Rus
_MC("column used with aggregate")
.

//------------------------------------------------------------------------
/*973*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396459
Language        =Rus
_MC("invalid column reference")
.

//------------------------------------------------------------------------
/*974*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396460
Language        =Rus
_MC("invalid key position")
.

//------------------------------------------------------------------------
/*975*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396461
Language        =Rus
_MC("invalid direction for find operation")
.

//------------------------------------------------------------------------
/*976*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396462
Language        =Rus
_MC("Invalid statement handle")
.

//------------------------------------------------------------------------
/*977*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396463
Language        =Rus
_MC("invalid lock handle")
.

//------------------------------------------------------------------------
/*978*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396464
Language        =Rus
_MC("invalid lock level %1")
.

//------------------------------------------------------------------------
/*979*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396465
Language        =Rus
_MC("invalid bookmark handle")
.

//------------------------------------------------------------------------
/*980*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396468
Language        =Rus
_MC("wrong or obsolete version")
.

//------------------------------------------------------------------------
/*981*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396471
Language        =Rus
_MC("The INSERT, UPDATE, DELETE, DDL or authorization statement cannot be executed because the transaction is inquiry only")
.

//------------------------------------------------------------------------
/*982*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396472
Language        =Rus
_MC("external file could not be opened for output")
.

//------------------------------------------------------------------------
/*983*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396477
Language        =Rus
_MC("multiple rows in singleton select")
.

//------------------------------------------------------------------------
/*984*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396478
Language        =Rus
_MC("No subqueries permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*985*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396479
Language        =Rus
_MC("DISTINCT, GROUP or HAVING not permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*986*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396480
Language        =Rus
_MC("Only one table allowed for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*987*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396481
Language        =Rus
_MC("No WHERE clause for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*988*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396482
Language        =Rus
_MC("Only simple column names permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*989*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396484
Language        =Rus
_MC("An error was found in the application program input parameters for the SQL statement.")
.

//------------------------------------------------------------------------
/*990*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396485
Language        =Rus
_MC("Invalid insert or update value(s): object columns are constrained - no 2 table rows can have duplicate column values")
.

//------------------------------------------------------------------------
/*991*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396486
Language        =Rus
_MC("Arithmetic overflow or division by zero has occurred.")
.

//------------------------------------------------------------------------
/*992*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396594
Language        =Rus
_MC("cannot access column %1 in view %2")
.

//------------------------------------------------------------------------
/*993*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396595
Language        =Rus
_MC("Too many concurrent executions of the same request")
.

//------------------------------------------------------------------------
/*994*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396596
Language        =Rus
_MC("maximum indexes per table (%1) exceeded")
.

//------------------------------------------------------------------------
/*995*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396597
Language        =Rus
_MC("new record size of %1 bytes is too big")
.

//------------------------------------------------------------------------
/*996*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396598
Language        =Rus
_MC("segments not allowed in expression index %1")
.

//------------------------------------------------------------------------
/*997*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396599
Language        =Rus
_MC("wrong page type")
.

//------------------------------------------------------------------------
/*998*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396603
Language        =Rus
_MC("invalid ARRAY or BLOB operation")
.

//------------------------------------------------------------------------
/*999*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396611
Language        =Rus
_MC("%1 extension error")
.

//------------------------------------------------------------------------
/*1000*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396624
Language        =Rus
_MC("key size exceeds implementation restriction for index \"%1\"")
.

//------------------------------------------------------------------------
/*1001*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396625
Language        =Rus
_MC("definition error for index %1")
.

//------------------------------------------------------------------------
/*1002*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396628
Language        =Rus
_MC("cannot create index")
.

//------------------------------------------------------------------------
/*1003*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396651
Language        =Rus
_MC("duplicate specification of %1 - not supported")
.

//------------------------------------------------------------------------
/*1004*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396663
Language        =Rus
_MC("The insert failed because a column definition includes validation constraints.")
.

//------------------------------------------------------------------------
/*1005*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396670
Language        =Rus
_MC("Cannot delete object referenced by another object")
.

//------------------------------------------------------------------------
/*1006*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396671
Language        =Rus
_MC("Cannot modify object referenced by another object")
.

//------------------------------------------------------------------------
/*1007*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396672
Language        =Rus
_MC("Object is referenced by another object")
.

//------------------------------------------------------------------------
/*1008*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396673
Language        =Rus
_MC("lock on conflicts with existing lock")
.

//------------------------------------------------------------------------
/*1009*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396681
Language        =Rus
_MC("This operation is not defined for system tables.")
.

//------------------------------------------------------------------------
/*1010*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396683
Language        =Rus
_MC("Inappropriate self-reference of column")
.

//------------------------------------------------------------------------
/*1011*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396684
Language        =Rus
_MC("Illegal array dimension range")
.

//------------------------------------------------------------------------
/*1012*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396687
Language        =Rus
_MC("database or file exists")
.

//------------------------------------------------------------------------
/*1013*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396688
Language        =Rus
_MC("sort error: corruption in data structure")
.

//------------------------------------------------------------------------
/*1014*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396689
Language        =Rus
_MC("node not supported")
.

//------------------------------------------------------------------------
/*1015*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396690
Language        =Rus
_MC("Shadow number must be a positive integer")
.

//------------------------------------------------------------------------
/*1016*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396691
Language        =Rus
_MC("Preceding file did not specify length, so %1 must include starting page number")
.

//------------------------------------------------------------------------
/*1017*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396692
Language        =Rus
_MC("illegal operation when at beginning of stream")
.

//------------------------------------------------------------------------
/*1018*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396693
Language        =Rus
_MC("the current position is on a crack")
.

//------------------------------------------------------------------------
/*1019*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396735
Language        =Rus
_MC("cannot modify an existing user privilege")
.

//------------------------------------------------------------------------
/*1020*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396736
Language        =Rus
_MC("user does not have the privilege to perform operation")
.

//------------------------------------------------------------------------
/*1021*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396737
Language        =Rus
_MC("This user does not have privilege to perform this operation on this object.")
.

//------------------------------------------------------------------------
/*1022*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396756
Language        =Rus
_MC("transaction marked invalid by I/O error")
.

//------------------------------------------------------------------------
/*1023*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396757
Language        =Rus
_MC("Cannot prepare a CREATE DATABASE/SCHEMA statement")
.

//------------------------------------------------------------------------
/*1024*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396758
Language        =Rus
_MC("violation of FOREIGN KEY constraint \"%1\"")
.

//------------------------------------------------------------------------
/*1025*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396769
Language        =Rus
_MC("The prepare statement identifies a prepare statement with an open cursor")
.

//------------------------------------------------------------------------
/*1026*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396770
Language        =Rus
_MC("Unknown statement or request")
.

//------------------------------------------------------------------------
/*1027*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396778
Language        =Rus
_MC("Attempt to update non-updatable cursor")
.

//------------------------------------------------------------------------
/*1028*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396780
Language        =Rus
_MC("The cursor identified in the UPDATE or DELETE statement is not positioned on a row.")
.

//------------------------------------------------------------------------
/*1029*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396784
Language        =Rus
_MC("Unknown cursor")
.

//------------------------------------------------------------------------
/*1030*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396786
Language        =Rus
_MC("The cursor identified in an OPEN statement is already open.")
.

//------------------------------------------------------------------------
/*1031*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396787
Language        =Rus
_MC("The cursor identified in a FETCH or CLOSE statement is not open.")
.

//------------------------------------------------------------------------
/*1032*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396875
Language        =Rus
_MC("Overflow occurred during data type conversion.")
.

//------------------------------------------------------------------------
/*1033*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396881
Language        =Rus
_MC("null segment of UNIQUE KEY")
.

//------------------------------------------------------------------------
/*1034*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396882
Language        =Rus
_MC("subscript out of bounds")
.

//------------------------------------------------------------------------
/*1035*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396886
Language        =Rus
_MC("data operation not supported")
.

//------------------------------------------------------------------------
/*1036*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396887
Language        =Rus
_MC("invalid comparison operator for find operation")
.

//------------------------------------------------------------------------
/*1037*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396974
Language        =Rus
_MC("Cannot transliterate character between character sets")
.

//------------------------------------------------------------------------
/*1038*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396975
Language        =Rus
_MC("count of column list and variable list do not match")
.

//------------------------------------------------------------------------
/*1039*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396985
Language        =Rus
_MC("Incompatible column/host variable data type")
.

//------------------------------------------------------------------------
/*1040*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396991
Language        =Rus
_MC("Operation violates CHECK constraint %1 on view or table")
.

//------------------------------------------------------------------------
/*1041*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396992
Language        =Rus
_MC("internal Firebird consistency check (invalid RDB$CONSTRAINT_TYPE)")
.

//------------------------------------------------------------------------
/*1042*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396993
Language        =Rus
_MC("Cannot update constraints (RDB$RELATION_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*1043*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396994
Language        =Rus
_MC("Cannot delete CHECK constraint entry (RDB$CHECK_CONSTRAINTS)")
.

//------------------------------------------------------------------------
/*1044*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396995
Language        =Rus
_MC("Cannot update constraints (RDB$CHECK_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*1045*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396996
Language        =Rus
_MC("Cannot update constraints (RDB$REF_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*1046*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396997
Language        =Rus
_MC("Column used in a PRIMARY constraint must be NOT NULL.")
.

//------------------------------------------------------------------------
/*1047*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397004
Language        =Rus
_MC("index %1 cannot be used in the specified plan")
.

//------------------------------------------------------------------------
/*1048*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397005
Language        =Rus
_MC("table %1 is referenced in the plan but not the from list")
.

//------------------------------------------------------------------------
/*1049*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397006
Language        =Rus
_MC("the table %1 is referenced twice; use aliases to differentiate")
.

//------------------------------------------------------------------------
/*1050*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397007
Language        =Rus
_MC("table %1 is not referenced in plan")
.

//------------------------------------------------------------------------
/*1051*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397027
Language        =Rus
_MC("Log file specification partition error")
.

//------------------------------------------------------------------------
/*1052*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397028
Language        =Rus
_MC("Cache or Log redefined")
.

//------------------------------------------------------------------------
/*1053*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397029
Language        =Rus
_MC("Write-ahead Log with shadowing configuration not allowed")
.

//------------------------------------------------------------------------
/*1054*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397030
Language        =Rus
_MC("Overflow log specification required for round-robin log")
.

//------------------------------------------------------------------------
/*1055*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397031
Language        =Rus
_MC("WAL defined; Cache Manager must be started first")
.

//------------------------------------------------------------------------
/*1056*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397033
Language        =Rus
_MC("Write-ahead Log without shared cache configuration not allowed")
.

//------------------------------------------------------------------------
/*1057*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397034
Language        =Rus
_MC("Cannot start WAL writer for the database %1")
.

//------------------------------------------------------------------------
/*1058*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397035
Language        =Rus
_MC("WAL writer synchronization error for the database %1")
.

//------------------------------------------------------------------------
/*1059*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397036
Language        =Rus
_MC("WAL setup error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*1060*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397037
Language        =Rus
_MC("WAL buffers cannot be increased. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*1061*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397038
Language        =Rus
_MC("WAL writer - Journal server communication error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*1062*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397039
Language        =Rus
_MC("WAL I/O error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*1063*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397040
Language        =Rus
_MC("Unable to roll over; please see Firebird log.")
.

//------------------------------------------------------------------------
/*1064*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397041
Language        =Rus
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1065*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397042
Language        =Rus
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1066*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397043
Language        =Rus
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1067*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397044
Language        =Rus
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1068*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397045
Language        =Rus
_MC("database does not use Write-ahead Log")
.

//------------------------------------------------------------------------
/*1069*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397046
Language        =Rus
_MC("Cannot roll over to the next log file %1")
.

//------------------------------------------------------------------------
/*1070*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397047
Language        =Rus
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1071*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397048
Language        =Rus
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1072*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397049
Language        =Rus
_MC("Cache or Log size too small")
.

//------------------------------------------------------------------------
/*1073*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397050
Language        =Rus
_MC("Log record header too small at offset %1 in log file %2")
.

//------------------------------------------------------------------------
/*1074*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397051
Language        =Rus
_MC("Incomplete log record at offset %1 in log file %2")
.

//------------------------------------------------------------------------
/*1075*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397052
Language        =Rus
_MC("Unexpected end of log file %1 at offset %2")
.

//------------------------------------------------------------------------
/*1076*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397053
Language        =Rus
_MC("Database name in the log file %1 is different")
.

//------------------------------------------------------------------------
/*1077*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397054
Language        =Rus
_MC("Log file %1 not closed properly; database recovery may be required")
.

//------------------------------------------------------------------------
/*1078*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397055
Language        =Rus
_MC("Log file %1 not latest in the chain but open flag still set")
.

//------------------------------------------------------------------------
/*1079*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397056
Language        =Rus
_MC("Invalid version of log file %1")
.

//------------------------------------------------------------------------
/*1080*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397057
Language        =Rus
_MC("Log file header of %1 too small")
.

//------------------------------------------------------------------------
/*1081*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397058
Language        =Rus
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1082*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397069
Language        =Rus
_MC("table %1 is not defined")
.

//------------------------------------------------------------------------
/*1083*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397080
Language        =Rus
_MC("invalid ORDER BY clause")
.

//------------------------------------------------------------------------
/*1084*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397082
Language        =Rus
_MC("Column does not belong to referenced table")
.

//------------------------------------------------------------------------
/*1085*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397083
Language        =Rus
_MC("column %1 is not defined in table %2")
.

//------------------------------------------------------------------------
/*1086*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397084
Language        =Rus
_MC("Undefined name")
.

//------------------------------------------------------------------------
/*1087*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397085
Language        =Rus
_MC("Ambiguous column reference.")
.

//------------------------------------------------------------------------
/*1088*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397116
Language        =Rus
_MC("function %1 is not defined")
.

//------------------------------------------------------------------------
/*1089*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397117
Language        =Rus
_MC("Invalid data type, length, or value")
.

//------------------------------------------------------------------------
/*1090*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397118
Language        =Rus
_MC("Invalid number of arguments")
.

//------------------------------------------------------------------------
/*1091*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397126
Language        =Rus
_MC("dbkey not available for multi-table views")
.

//------------------------------------------------------------------------
/*1092*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397130
Language        =Rus
_MC("number of columns does not match select list")
.

//------------------------------------------------------------------------
/*1093*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397131
Language        =Rus
_MC("must specify column name for view select expression")
.

//------------------------------------------------------------------------
/*1094*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397133
Language        =Rus
_MC("%1 is not a valid base table of the specified view")
.

//------------------------------------------------------------------------
/*1095*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397137
Language        =Rus
_MC("This column cannot be updated because it is derived from an SQL function or expression.")
.

//------------------------------------------------------------------------
/*1096*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397138
Language        =Rus
_MC("The object of the INSERT, DELETE or UPDATE statement is a view for which the requested operation is not permitted.")
.

//------------------------------------------------------------------------
/*1097*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397183
Language        =Rus
_MC("Invalid String")
.

//------------------------------------------------------------------------
/*1098*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397184
Language        =Rus
_MC("Invalid token")
.

//------------------------------------------------------------------------
/*1099*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397185
Language        =Rus
_MC("Invalid numeric literal")
.

//------------------------------------------------------------------------
/*1100*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397203
Language        =Rus
_MC("An error occurred while trying to update the security database")
.

//------------------------------------------------------------------------
/*1101*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397204
Language        =Rus
_MC("non-SQL security class defined")
.

//------------------------------------------------------------------------
/*1102*/
MessageId       =IBP_MCE_FB25__DSQL_TOO_OLD_ODS
Language        =Rus
_MC("ODS versions before ODS%1 are not supported")
.

//------------------------------------------------------------------------
/*1103*/
MessageId       =IBP_MCE_FB25__DSQL_TABLE_NOT_FOUND
Language        =Rus
_MC("Table %1 does not exist")
.

//------------------------------------------------------------------------
/*1104*/
MessageId       =IBP_MCE_FB25__DSQL_VIEW_NOT_FOUND
Language        =Rus
_MC("View %1 does not exist")
.

//------------------------------------------------------------------------
/*1105*/
MessageId       =IBP_MCE_FB25__DSQL_LINE_COL_ERROR
Language        =Rus
_MC("At line %1, column %2")
.

//------------------------------------------------------------------------
/*1106*/
MessageId       =IBP_MCE_FB25__DSQL_UNKNOWN_POS
Language        =Rus
_MC("At unknown line and column")
.

//------------------------------------------------------------------------
/*1107*/
MessageId       =IBP_MCE_FB25__DSQL_NO_DUP_NAME
Language        =Rus
_MC("Column %1 cannot be repeated in %2 statement")
.

//------------------------------------------------------------------------
/*1108*/
MessageId       =IBP_MCE_FB25__DSQL_TOO_MANY_VALUES
Language        =Rus
_MC("Too many values (more than %1) in member list to match against")
.

//------------------------------------------------------------------------
/*1109*/
MessageId       =IBP_MCE_FB25__DSQL_NO_ARRAY_COMPUTED
Language        =Rus
_MC("Array and BLOB data types not allowed in computed field")
.

//------------------------------------------------------------------------
/*1110*/
MessageId       =IBP_MCE_FB25__DSQL_IMPLICIT_DOMAIN_NAME
Language        =Rus
_MC("Implicit domain name %1 not allowed in user created domain")
.

//------------------------------------------------------------------------
/*1111*/
MessageId       =IBP_MCE_FB25__DSQL_ONLY_CAN_SUBSCRIPT_ARRAY
Language        =Rus
_MC("scalar operator used on field %1 which is not an array")
.

//------------------------------------------------------------------------
/*1112*/
MessageId       =IBP_MCE_FB25__DSQL_MAX_SORT_ITEMS
Language        =Rus
_MC("cannot sort on more than 255 items")
.

//------------------------------------------------------------------------
/*1113*/
MessageId       =IBP_MCE_FB25__DSQL_MAX_GROUP_ITEMS
Language        =Rus
_MC("cannot group on more than 255 items")
.

//------------------------------------------------------------------------
/*1114*/
MessageId       =IBP_MCE_FB25__DSQL_CONFLICTING_SORT_FIELD
Language        =Rus
_MC("Cannot include the same field (%1.%2) twice in the ORDER BY clause with conflicting sorting options")
.

//------------------------------------------------------------------------
/*1115*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_TABLE_MORE_COLUMNS
Language        =Rus
_MC("column list from derived table %1 has more columns than the number of items in its SELECT statement")
.

//------------------------------------------------------------------------
/*1116*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_TABLE_LESS_COLUMNS
Language        =Rus
_MC("column list from derived table %1 has less columns than the number of items in its SELECT statement")
.

//------------------------------------------------------------------------
/*1117*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_FIELD_UNNAMED
Language        =Rus
_MC("no column name specified for column number %1 in derived table %2")
.

//------------------------------------------------------------------------
/*1118*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_FIELD_DUP_NAME
Language        =Rus
_MC("column %1 was specified multiple times for derived table %2")
.

//------------------------------------------------------------------------
/*1119*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_ALIAS_SELECT
Language        =Rus
_MC("Internal dsql error: alias type expected by pass1_expand_select_node")
.

//------------------------------------------------------------------------
/*1120*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_ALIAS_FIELD
Language        =Rus
_MC("Internal dsql error: alias type expected by pass1_field")
.

//------------------------------------------------------------------------
/*1121*/
MessageId       =IBP_MCE_FB25__DSQL_AUTO_FIELD_BAD_POS
Language        =Rus
_MC("Internal dsql error: column position out of range in pass1_union_auto_cast")
.

//------------------------------------------------------------------------
/*1122*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_WRONG_REFERENCE
Language        =Rus
_MC("Recursive CTE member (%1) can refer itself only in FROM clause")
.

//------------------------------------------------------------------------
/*1123*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_CYCLE
Language        =Rus
_MC("CTE '%1' has cyclic dependencies")
.

//------------------------------------------------------------------------
/*1124*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_OUTER_JOIN
Language        =Rus
_MC("Recursive member of CTE can't be member of an outer join")
.

//------------------------------------------------------------------------
/*1125*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_MULT_REFERENCES
Language        =Rus
_MC("Recursive member of CTE can't reference itself more than once")
.

//------------------------------------------------------------------------
/*1126*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_NOT_A_UNION
Language        =Rus
_MC("Recursive CTE (%1) must be an UNION")
.

//------------------------------------------------------------------------
/*1127*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_NONRECURS_AFTER_RECURS
Language        =Rus
_MC("CTE '%1' defined non-recursive member after recursive")
.

//------------------------------------------------------------------------
/*1128*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_WRONG_CLAUSE
Language        =Rus
_MC("Recursive member of CTE '%1' has %2 clause")
.

//------------------------------------------------------------------------
/*1129*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_UNION_ALL
Language        =Rus
_MC("Recursive members of CTE (%1) must be linked with another members via UNION ALL")
.

//------------------------------------------------------------------------
/*1130*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_MISS_NONRECURSIVE
Language        =Rus
_MC("Non-recursive member is missing in CTE '%1'")
.

//------------------------------------------------------------------------
/*1131*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_NESTED_WITH
Language        =Rus
_MC("WITH clause can't be nested")
.

//------------------------------------------------------------------------
/*1132*/
MessageId       =IBP_MCE_FB25__DSQL_COL_MORE_THAN_ONCE_USING
Language        =Rus
_MC("column %1 appears more than once in USING clause")
.

//------------------------------------------------------------------------
/*1133*/
MessageId       =IBP_MCE_FB25__DSQL_UNSUPP_FEATURE_DIALECT
Language        =Rus
_MC("feature is not supported in dialect %1")
.

//------------------------------------------------------------------------
/*1134*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_NOT_USED
Language        =Rus
_MC("CTE \"%1\" is not used in query")
.

//------------------------------------------------------------------------
/*1135*/
MessageId       =IBP_MCE_FB25__DSQL_COL_MORE_THAN_ONCE_VIEW
Language        =Rus
_MC("column %1 appears more than once in ALTER VIEW")
.

//------------------------------------------------------------------------
/*1136*/
MessageId       =IBP_MCE_FB25__DSQL_UNSUPPORTED_IN_AUTO_TRANS
Language        =Rus
_MC("%1 is not supported inside IN AUTONOMOUS TRANSACTION block")
.

//------------------------------------------------------------------------
/*1137*/
MessageId       =IBP_MCE_FB25__DSQL_EVAL_UNKNODE
Language        =Rus
_MC("Unknown node type %1 in dsql/GEN_expr")
.

//------------------------------------------------------------------------
/*1138*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_WRONGARG
Language        =Rus
_MC("Argument for %1 in dialect 1 must be string or numeric")
.

//------------------------------------------------------------------------
/*1139*/
MessageId       =IBP_MCE_FB25__DSQL_AGG2_WRONGARG
Language        =Rus
_MC("Argument for %1 in dialect 3 must be numeric")
.

//------------------------------------------------------------------------
/*1140*/
MessageId       =IBP_MCE_FB25__DSQL_NODATEORTIME_PM_STRING
Language        =Rus
_MC("Strings cannot be added to or subtracted from DATE or TIME types")
.

//------------------------------------------------------------------------
/*1141*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_DATETIME_SUBTRACT
Language        =Rus
_MC("Invalid data type for subtraction involving DATE, TIME or TIMESTAMP types")
.

//------------------------------------------------------------------------
/*1142*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_DATEORTIME_ADD
Language        =Rus
_MC("Adding two DATE values or two TIME values is not allowed")
.

//------------------------------------------------------------------------
/*1143*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_MINUS_DATE
Language        =Rus
_MC("DATE value cannot be subtracted from the provided data type")
.

//------------------------------------------------------------------------
/*1144*/
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_ADDSUB_DIAL3
Language        =Rus
_MC("Strings cannot be added or subtracted in dialect 3")
.

//------------------------------------------------------------------------
/*1145*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_ADDSUB_DIAL3
Language        =Rus
_MC("Invalid data type for addition or subtraction in dialect 3")
.

//------------------------------------------------------------------------
/*1146*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_MULTIP_DIAL1
Language        =Rus
_MC("Invalid data type for multiplication in dialect 1")
.

//------------------------------------------------------------------------
/*1147*/
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_MULTIP_DIAL3
Language        =Rus
_MC("Strings cannot be multiplied in dialect 3")
.

//------------------------------------------------------------------------
/*1148*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_MULTIP_DIAL3
Language        =Rus
_MC("Invalid data type for multiplication in dialect 3")
.

//------------------------------------------------------------------------
/*1149*/
MessageId       =IBP_MCE_FB25__DSQL_MUSTUSE_NUMERIC_DIV_DIAL1
Language        =Rus
_MC("Division in dialect 1 must be between numeric data types")
.

//------------------------------------------------------------------------
/*1150*/
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_DIV_DIAL3
Language        =Rus
_MC("Strings cannot be divided in dialect 3")
.

//------------------------------------------------------------------------
/*1151*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_DIV_DIAL3
Language        =Rus
_MC("Invalid data type for division in dialect 3")
.

//------------------------------------------------------------------------
/*1152*/
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_NEG_DIAL3
Language        =Rus
_MC("Strings cannot be negated (applied the minus operator) in dialect 3")
.

//------------------------------------------------------------------------
/*1153*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_NEG
Language        =Rus
_MC("Invalid data type for negation (minus operator)")
.

//------------------------------------------------------------------------
/*1154*/
MessageId       =IBP_MCE_FB25__DSQL_MAX_DISTINCT_ITEMS
Language        =Rus
_MC("Cannot have more than 255 items in DISTINCT list")
.

//------------------------------------------------------------------------
/*1155*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336461924
Language        =Rus
_MC("Row not found for fetch, update or delete, or the result of a query is an empty table.")
.

//------------------------------------------------------------------------
/*1156*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336461925
Language        =Rus
_MC("segment buffer length shorter than expected")
.

//------------------------------------------------------------------------
/*1157*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336462125
Language        =Rus
_MC("Datatype needs modification")
.

//------------------------------------------------------------------------
/*1158*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336462436
Language        =Rus
_MC("Duplicate column or domain name found.")
.

//------------------------------------------------------------------------
/*1159*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527507
Language        =Rus
_MC("invalid block type encountered")
.

//------------------------------------------------------------------------
/*1160*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527508
Language        =Rus
_MC("wrong packet type")
.

//------------------------------------------------------------------------
/*1161*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527509
Language        =Rus
_MC("cannot map page")
.

//------------------------------------------------------------------------
/*1162*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527510
Language        =Rus
_MC("request to allocate invalid block type")
.

//------------------------------------------------------------------------
/*1163*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527511
Language        =Rus
_MC("request to allocate block type larger than maximum size")
.

//------------------------------------------------------------------------
/*1164*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527512
Language        =Rus
_MC("memory pool free list is invalid")
.

//------------------------------------------------------------------------
/*1165*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527513
Language        =Rus
_MC("invalid pool id encountered")
.

//------------------------------------------------------------------------
/*1166*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527514
Language        =Rus
_MC("attempt to release free block")
.

//------------------------------------------------------------------------
/*1167*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527515
Language        =Rus
_MC("attempt to release block overlapping following free block")
.

//------------------------------------------------------------------------
/*1168*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527516
Language        =Rus
_MC("attempt to release block overlapping prior free block")
.

//------------------------------------------------------------------------
/*1169*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527517
Language        =Rus
_MC("cannot sort on a field that does not exist")
.

//------------------------------------------------------------------------
/*1170*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527518
Language        =Rus
_MC("database file not available")
.

//------------------------------------------------------------------------
/*1171*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527519
Language        =Rus
_MC("cannot assert logical lock")
.

//------------------------------------------------------------------------
/*1172*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527520
Language        =Rus
_MC("wrong ACL version")
.

//------------------------------------------------------------------------
/*1173*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527521
Language        =Rus
_MC("shadow block not found")
.

//------------------------------------------------------------------------
/*1174*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527522
Language        =Rus
_MC("shadow lock not synchronized properly")
.

//------------------------------------------------------------------------
/*1175*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527523
Language        =Rus
_MC("root file name not listed for shadow")
.

//------------------------------------------------------------------------
/*1176*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527524
Language        =Rus
_MC("failed to remove symbol from hash table")
.

//------------------------------------------------------------------------
/*1177*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527525
Language        =Rus
_MC("cannot find tip page")
.

//------------------------------------------------------------------------
/*1178*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527526
Language        =Rus
_MC("invalid rsb type")
.

//------------------------------------------------------------------------
/*1179*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527527
Language        =Rus
_MC("invalid SEND request")
.

//------------------------------------------------------------------------
/*1180*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527528
Language        =Rus
_MC("looper: action not yet implemented")
.

//------------------------------------------------------------------------
/*1181*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527529
Language        =Rus
_MC("return data type not supported")
.

//------------------------------------------------------------------------
/*1182*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527530
Language        =Rus
_MC("unexpected reply from journal server")
.

//------------------------------------------------------------------------
/*1183*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527531
Language        =Rus
_MC("journal server is incompatible version")
.

//------------------------------------------------------------------------
/*1184*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527532
Language        =Rus
_MC("journal server refused connection")
.

//------------------------------------------------------------------------
/*1185*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527533
Language        =Rus
_MC("referenced index description not found")
.

//------------------------------------------------------------------------
/*1186*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527534
Language        =Rus
_MC("index key too big")
.

//------------------------------------------------------------------------
/*1187*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527535
Language        =Rus
_MC("partner index description not found")
.

//------------------------------------------------------------------------
/*1188*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527536
Language        =Rus
_MC("bad difference record")
.

//------------------------------------------------------------------------
/*1189*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527537
Language        =Rus
_MC("applied differences will not fit in record")
.

//------------------------------------------------------------------------
/*1190*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527538
Language        =Rus
_MC("record length inconsistent")
.

//------------------------------------------------------------------------
/*1191*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527539
Language        =Rus
_MC("decompression overran buffer")
.

//------------------------------------------------------------------------
/*1192*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527540
Language        =Rus
_MC("cannot reposition for update after sort for RMS")
.

//------------------------------------------------------------------------
/*1193*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527541
Language        =Rus
_MC("external access type not implemented")
.

//------------------------------------------------------------------------
/*1194*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527542
Language        =Rus
_MC("differences record too long")
.

//------------------------------------------------------------------------
/*1195*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527543
Language        =Rus
_MC("wrong record length")
.

//------------------------------------------------------------------------
/*1196*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527544
Language        =Rus
_MC("limbo impossible")
.

//------------------------------------------------------------------------
/*1197*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527545
Language        =Rus
_MC("wrong record version")
.

//------------------------------------------------------------------------
/*1198*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527546
Language        =Rus
_MC("record disappeared")
.

//------------------------------------------------------------------------
/*1199*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527547
Language        =Rus
_MC("cannot delete system tables")
.

//------------------------------------------------------------------------
/*1200*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527548
Language        =Rus
_MC("cannot update erased record")
.

//------------------------------------------------------------------------
/*1201*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527549
Language        =Rus
_MC("comparison not supported for specified data types")
.

//------------------------------------------------------------------------
/*1202*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527550
Language        =Rus
_MC("conversion not supported for specified data types")
.

//------------------------------------------------------------------------
/*1203*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527551
Language        =Rus
_MC("conversion error")
.

//------------------------------------------------------------------------
/*1204*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527552
Language        =Rus
_MC("overflow during conversion")
.

//------------------------------------------------------------------------
/*1205*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527553
Language        =Rus
_MC("null or invalid array")
.

//------------------------------------------------------------------------
/*1206*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527554
Language        =Rus
_MC("BLOB not found")
.

//------------------------------------------------------------------------
/*1207*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527555
Language        =Rus
_MC("cannot update old BLOB")
.

//------------------------------------------------------------------------
/*1208*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527556
Language        =Rus
_MC("relation for array not known")
.

//------------------------------------------------------------------------
/*1209*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527557
Language        =Rus
_MC("field for array not known")
.

//------------------------------------------------------------------------
/*1210*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527558
Language        =Rus
_MC("array subscript computation error")
.

//------------------------------------------------------------------------
/*1211*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527559
Language        =Rus
_MC("expected field node")
.

//------------------------------------------------------------------------
/*1212*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527560
Language        =Rus
_MC("invalid BLOB ID")
.

//------------------------------------------------------------------------
/*1213*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527561
Language        =Rus
_MC("cannot find BLOB page")
.

//------------------------------------------------------------------------
/*1214*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527562
Language        =Rus
_MC("unknown data type")
.

//------------------------------------------------------------------------
/*1215*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527563
Language        =Rus
_MC("shadow block not found for extend file")
.

//------------------------------------------------------------------------
/*1216*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527564
Language        =Rus
_MC("index inconsistent")
.

//------------------------------------------------------------------------
/*1217*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527565
Language        =Rus
_MC("index bucket overfilled")
.

//------------------------------------------------------------------------
/*1218*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527566
Language        =Rus
_MC("exceeded index level")
.

//------------------------------------------------------------------------
/*1219*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527567
Language        =Rus
_MC("page already in use")
.

//------------------------------------------------------------------------
/*1220*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527568
Language        =Rus
_MC("page not accessed for write")
.

//------------------------------------------------------------------------
/*1221*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527569
Language        =Rus
_MC("attempt to release page not acquired")
.

//------------------------------------------------------------------------
/*1222*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527570
Language        =Rus
_MC("page in use during flush")
.

//------------------------------------------------------------------------
/*1223*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527571
Language        =Rus
_MC("attempt to remove page from dirty page list when not there")
.

//------------------------------------------------------------------------
/*1224*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527572
Language        =Rus
_MC("CCH_precedence: block marked")
.

//------------------------------------------------------------------------
/*1225*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527573
Language        =Rus
_MC("insufficient cache size")
.

//------------------------------------------------------------------------
/*1226*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527574
Language        =Rus
_MC("no cache buffers available for reuse")
.

//------------------------------------------------------------------------
/*1227*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527575
Language        =Rus
_MC("page %1, page type %2 lock conversion denied")
.

//------------------------------------------------------------------------
/*1228*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527576
Language        =Rus
_MC("page %1, page type %2 lock denied")
.

//------------------------------------------------------------------------
/*1229*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527577
Language        =Rus
_MC("buffer marked for update")
.

//------------------------------------------------------------------------
/*1230*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527578
Language        =Rus
_MC("CCH: %1, status = %2 (218)")
.

//------------------------------------------------------------------------
/*1231*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527579
Language        =Rus
_MC("request of unknown resource")
.

//------------------------------------------------------------------------
/*1232*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527580
Language        =Rus
_MC("release of unknown resource")
.

//------------------------------------------------------------------------
/*1233*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527581
Language        =Rus
_MC("(CMP) copy: cannot remap")
.

//------------------------------------------------------------------------
/*1234*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527582
Language        =Rus
_MC("bad BLR -- invalid stream")
.

//------------------------------------------------------------------------
/*1235*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527583
Language        =Rus
_MC("argument of scalar operation must be an array")
.

//------------------------------------------------------------------------
/*1236*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527584
Language        =Rus
_MC("quad word arithmetic not supported")
.

//------------------------------------------------------------------------
/*1237*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527585
Language        =Rus
_MC("data type not supported for arithmetic")
.

//------------------------------------------------------------------------
/*1238*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527586
Language        =Rus
_MC("request size limit exceeded")
.

//------------------------------------------------------------------------
/*1239*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527587
Language        =Rus
_MC("cannot access field %1 in view %2")
.

//------------------------------------------------------------------------
/*1240*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527588
Language        =Rus
_MC("cannot access field in view %1")
.

//------------------------------------------------------------------------
/*1241*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527589
Language        =Rus
_MC("EVL_assign_to: invalid operation")
.

//------------------------------------------------------------------------
/*1242*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527590
Language        =Rus
_MC("EVL_bitmap: invalid operation")
.

//------------------------------------------------------------------------
/*1243*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527591
Language        =Rus
_MC("EVL_boolean: invalid operation")
.

//------------------------------------------------------------------------
/*1244*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527592
Language        =Rus
_MC("EVL_expr: invalid operation")
.

//------------------------------------------------------------------------
/*1245*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527593
Language        =Rus
_MC("eval_statistical: invalid operation")
.

//------------------------------------------------------------------------
/*1246*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527594
Language        =Rus
_MC("Unimplemented conversion, FAO directive O,Z,S")
.

//------------------------------------------------------------------------
/*1247*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527595
Language        =Rus
_MC("Unimplemented conversion, FAO directive X,U")
.

//------------------------------------------------------------------------
/*1248*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527596
Language        =Rus
_MC("Error parsing RDB FAO msg string")
.

//------------------------------------------------------------------------
/*1249*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527597
Language        =Rus
_MC("Error parsing RDB FAO msg str")
.

//------------------------------------------------------------------------
/*1250*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527598
Language        =Rus
_MC("unknown parameter in RdB status vector")
.

//------------------------------------------------------------------------
/*1251*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527599
Language        =Rus
_MC("Firebird status vector inconsistent")
.

//------------------------------------------------------------------------
/*1252*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527600
Language        =Rus
_MC("Firebird/RdB message parameter inconsistency")
.

//------------------------------------------------------------------------
/*1253*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527601
Language        =Rus
_MC("error parsing RDB FAO message string")
.

//------------------------------------------------------------------------
/*1254*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527602
Language        =Rus
_MC("unimplemented FAO directive")
.

//------------------------------------------------------------------------
/*1255*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527603
Language        =Rus
_MC("missing pointer page in DPM_data_pages")
.

//------------------------------------------------------------------------
/*1256*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527604
Language        =Rus
_MC("Fragment does not exist")
.

//------------------------------------------------------------------------
/*1257*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527605
Language        =Rus
_MC("pointer page disappeared in DPM_delete")
.

//------------------------------------------------------------------------
/*1258*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527606
Language        =Rus
_MC("pointer page lost from DPM_delete_relation")
.

//------------------------------------------------------------------------
/*1259*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527607
Language        =Rus
_MC("missing pointer page in DPM_dump")
.

//------------------------------------------------------------------------
/*1260*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527608
Language        =Rus
_MC("cannot find record fragment")
.

//------------------------------------------------------------------------
/*1261*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527609
Language        =Rus
_MC("pointer page vanished from DPM_next")
.

//------------------------------------------------------------------------
/*1262*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527610
Language        =Rus
_MC("temporary page buffer too small")
.

//------------------------------------------------------------------------
/*1263*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527611
Language        =Rus
_MC("damaged data page")
.

//------------------------------------------------------------------------
/*1264*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527612
Language        =Rus
_MC("header fragment length changed")
.

//------------------------------------------------------------------------
/*1265*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527613
Language        =Rus
_MC("pointer page vanished from extend_relation")
.

//------------------------------------------------------------------------
/*1266*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527614
Language        =Rus
_MC("pointer page vanished from relation list in locate_space")
.

//------------------------------------------------------------------------
/*1267*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527615
Language        =Rus
_MC("cannot find free space")
.

//------------------------------------------------------------------------
/*1268*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527616
Language        =Rus
_MC("pointer page vanished from mark_full")
.

//------------------------------------------------------------------------
/*1269*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527617
Language        =Rus
_MC("bad record in RDB$PAGES")
.

//------------------------------------------------------------------------
/*1270*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527618
Language        =Rus
_MC("page slot not empty")
.

//------------------------------------------------------------------------
/*1271*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527619
Language        =Rus
_MC("bad pointer page")
.

//------------------------------------------------------------------------
/*1272*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527620
Language        =Rus
_MC("index unexpectedly deleted")
.

//------------------------------------------------------------------------
/*1273*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527621
Language        =Rus
_MC("scalar operator used on field which is not an array")
.

//------------------------------------------------------------------------
/*1274*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527622
Language        =Rus
_MC("active")
.

//------------------------------------------------------------------------
/*1275*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527623
Language        =Rus
_MC("committed")
.

//------------------------------------------------------------------------
/*1276*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527624
Language        =Rus
_MC("rolled back")
.

//------------------------------------------------------------------------
/*1277*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527625
Language        =Rus
_MC("in an ill-defined state")
.

//------------------------------------------------------------------------
/*1278*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527626
Language        =Rus
_MC("next transaction older than oldest active transaction")
.

//------------------------------------------------------------------------
/*1279*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527627
Language        =Rus
_MC("next transaction older than oldest transaction")
.

//------------------------------------------------------------------------
/*1280*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527628
Language        =Rus
_MC("buffer marked during cache unwind")
.

//------------------------------------------------------------------------
/*1281*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527629
Language        =Rus
_MC("error in recovery! database corrupted")
.

//------------------------------------------------------------------------
/*1282*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527630
Language        =Rus
_MC("error in recovery! wrong data page record")
.

//------------------------------------------------------------------------
/*1283*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527631
Language        =Rus
_MC("error in recovery! no space on data page")
.

//------------------------------------------------------------------------
/*1284*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527632
Language        =Rus
_MC("error in recovery! wrong header page record")
.

//------------------------------------------------------------------------
/*1285*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527633
Language        =Rus
_MC("error in recovery! wrong generator page record")
.

//------------------------------------------------------------------------
/*1286*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527634
Language        =Rus
_MC("error in recovery! wrong b-tree page record")
.

//------------------------------------------------------------------------
/*1287*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527635
Language        =Rus
_MC("error in recovery! wrong page inventory page record")
.

//------------------------------------------------------------------------
/*1288*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527636
Language        =Rus
_MC("error in recovery! wrong pointer page record")
.

//------------------------------------------------------------------------
/*1289*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527637
Language        =Rus
_MC("error in recovery! wrong index root page record")
.

//------------------------------------------------------------------------
/*1290*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527638
Language        =Rus
_MC("error in recovery! wrong transaction page record")
.

//------------------------------------------------------------------------
/*1291*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527639
Language        =Rus
_MC("error in recovery! out of sequence log record encountered")
.

//------------------------------------------------------------------------
/*1292*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527640
Language        =Rus
_MC("error in recovery! unknown page type")
.

//------------------------------------------------------------------------
/*1293*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527641
Language        =Rus
_MC("error in recovery! unknown record type")
.

//------------------------------------------------------------------------
/*1294*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527642
Language        =Rus
_MC("journal server cannot archive to specified archive directory")
.

//------------------------------------------------------------------------
/*1295*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527643
Language        =Rus
_MC("checksum error in log record when reading from log file")
.

//------------------------------------------------------------------------
/*1296*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527644
Language        =Rus
_MC("cannot restore singleton select data")
.

//------------------------------------------------------------------------
/*1297*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527645
Language        =Rus
_MC("lock not found in internal lock manager")
.

//------------------------------------------------------------------------
/*1298*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527646
Language        =Rus
_MC("size of opt block exceeded")
.

//------------------------------------------------------------------------
/*1299*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527647
Language        =Rus
_MC("Too many savepoints")
.

//------------------------------------------------------------------------
/*1300*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527648
Language        =Rus
_MC("garbage collect record disappeared")
.

//------------------------------------------------------------------------
/*1301*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527649
Language        =Rus
_MC("Unknown BLOB FILTER ACTION_")
.

//------------------------------------------------------------------------
/*1302*/
MessageId       =IBP_MCE_FB25__SAVEPOINT_ERROR
Language        =Rus
_MC("error during savepoint backout")
.

//------------------------------------------------------------------------
/*1303*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527651
Language        =Rus
_MC("cannot find record back version")
.

//------------------------------------------------------------------------
/*1304*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527652
Language        =Rus
_MC("Illegal user_type.")
.

//------------------------------------------------------------------------
/*1305*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527653
Language        =Rus
_MC("bad ACL")
.

//------------------------------------------------------------------------
/*1306*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527654
Language        =Rus
_MC("inconsistent LATCH_mark release")
.

//------------------------------------------------------------------------
/*1307*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527655
Language        =Rus
_MC("inconsistent LATCH_mark call")
.

//------------------------------------------------------------------------
/*1308*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527656
Language        =Rus
_MC("inconsistent latch downgrade call")
.

//------------------------------------------------------------------------
/*1309*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527657
Language        =Rus
_MC("bdb is unexpectedly marked")
.

//------------------------------------------------------------------------
/*1310*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527658
Language        =Rus
_MC("missing exclusive latch")
.

//------------------------------------------------------------------------
/*1311*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527659
Language        =Rus
_MC("exceeded maximum number of shared latches on a bdb")
.

//------------------------------------------------------------------------
/*1312*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527660
Language        =Rus
_MC("can't find shared latch")
.

//------------------------------------------------------------------------
/*1313*/
MessageId       =IBP_MCE_FB25__CACHE_NON_ZERO_USE_COUNT
Language        =Rus
_MC("Non-zero use_count of a buffer in the empty que")
.

//------------------------------------------------------------------------
/*1314*/
MessageId       =IBP_MCE_FB25__UNEXPECTED_PAGE_CHANGE
Language        =Rus
_MC("Unexpected page change from latching")
.

//------------------------------------------------------------------------
/*1315*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527663
Language        =Rus
_MC("Invalid expression for evaluation")
.

//------------------------------------------------------------------------
/*1316*/
MessageId       =IBP_MCE_FB25__RDB_TRIGGERS_RDB_FLAGS_CORRUPT
Language        =Rus
_MC("RDB$FLAGS for trigger %1 in RDB$TRIGGERS is corrupted")
.

//------------------------------------------------------------------------
/*1317*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527665
Language        =Rus
_MC("Blobs accounting is inconsistent")
.

//------------------------------------------------------------------------
/*1318*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527666
Language        =Rus
_MC("Found array data type with more than 16 dimensions")
.

////////////////////////////////////////////////////////////////////////////////
