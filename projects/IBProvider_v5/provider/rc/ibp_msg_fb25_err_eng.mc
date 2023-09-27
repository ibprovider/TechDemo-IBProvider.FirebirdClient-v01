////////////////////////////////////////////////////////////////////////////////
//IBProvider resources. Firebird 2.5 Error Messages. English.
//Machine generated file [26.09.2023 11:37:06]
//                                                             Dmitry Kovalenko.
#include "ibp_msg_fb25_err_ids.rh"

////////////////////////////////////////////////////////////////////////////////
LanguageNames=(Eng=0x0000:IBP_MSG_FB25_ERR_ENG)

////////////////////////////////////////////////////////////////////////////////

/*1*/
MessageId       =IBP_MCE_FB25__ARITH_EXCEPT
Language        =Eng
_MC("arithmetic exception, numeric overflow, or string truncation")
.

//------------------------------------------------------------------------
/*2*/
MessageId       =IBP_MCE_FB25__BAD_DBKEY
Language        =Eng
_MC("invalid database key")
.

//------------------------------------------------------------------------
/*3*/
MessageId       =IBP_MCE_FB25__BAD_DB_FORMAT
Language        =Eng
_MC("file %1 is not a valid database")
.

//------------------------------------------------------------------------
/*4*/
MessageId       =IBP_MCE_FB25__BAD_DB_HANDLE
Language        =Eng
_MC("Invalid database handle (no active connection).")
.

//------------------------------------------------------------------------
/*5*/
MessageId       =IBP_MCE_FB25__BAD_DPB_CONTENT
Language        =Eng
_MC("bad parameters on attach or create database")
.

//------------------------------------------------------------------------
/*6*/
MessageId       =IBP_MCE_FB25__BAD_DPB_FORM
Language        =Eng
_MC("unrecognized database parameter block")
.

//------------------------------------------------------------------------
/*7*/
MessageId       =IBP_MCE_FB25__BAD_REQ_HANDLE
Language        =Eng
_MC("Invalid request handle.")
.

//------------------------------------------------------------------------
/*8*/
MessageId       =IBP_MCE_FB25__BAD_SEGSTR_HANDLE
Language        =Eng
_MC("Invalid BLOB handle.")
.

//------------------------------------------------------------------------
/*9*/
MessageId       =IBP_MCE_FB25__BAD_SEGSTR_ID
Language        =Eng
_MC("Invalid BLOB ID.")
.

//------------------------------------------------------------------------
/*10*/
MessageId       =IBP_MCE_FB25__BAD_TPB_CONTENT
Language        =Eng
_MC("invalid parameter in transaction parameter block")
.

//------------------------------------------------------------------------
/*11*/
MessageId       =IBP_MCE_FB25__BAD_TPB_FORM
Language        =Eng
_MC("invalid format for transaction parameter block")
.

//------------------------------------------------------------------------
/*12*/
MessageId       =IBP_MCE_FB25__BAD_TRANS_HANDLE
Language        =Eng
_MC("Invalid transaction handle (expecting explicit transaction start).")
.

//------------------------------------------------------------------------
/*13*/
MessageId       =IBP_MCE_FB25__BUG_CHECK
Language        =Eng
_MC("internal Firebird consistency check (%1)")
.

//------------------------------------------------------------------------
/*14*/
MessageId       =IBP_MCE_FB25__CONVERT_ERROR
Language        =Eng
_MC("conversion error from string \"%1\"")
.

//------------------------------------------------------------------------
/*15*/
MessageId       =IBP_MCE_FB25__DB_CORRUPT
Language        =Eng
_MC("database file appears corrupt (%1)")
.

//------------------------------------------------------------------------
/*16*/
MessageId       =IBP_MCE_FB25__DEADLOCK
Language        =Eng
_MC("deadlock")
.

//------------------------------------------------------------------------
/*17*/
MessageId       =IBP_MCE_FB25__EXCESS_TRANS
Language        =Eng
_MC("attempt to start more than %1 transactions")
.

//------------------------------------------------------------------------
/*18*/
MessageId       =IBP_MCE_FB25__FROM_NO_MATCH
Language        =Eng
_MC("no match for first value expression")
.

//------------------------------------------------------------------------
/*19*/
MessageId       =IBP_MCE_FB25__INFINAP
Language        =Eng
_MC("information type inappropriate for object specified")
.

//------------------------------------------------------------------------
/*20*/
MessageId       =IBP_MCE_FB25__INFONA
Language        =Eng
_MC("no information of this type available for object specified")
.

//------------------------------------------------------------------------
/*21*/
MessageId       =IBP_MCE_FB25__INFUNK
Language        =Eng
_MC("unknown information item")
.

//------------------------------------------------------------------------
/*22*/
MessageId       =IBP_MCE_FB25__INTEG_FAIL
Language        =Eng
_MC("action cancelled by trigger (%1) to preserve data integrity")
.

//------------------------------------------------------------------------
/*23*/
MessageId       =IBP_MCE_FB25__INVALID_BLR
Language        =Eng
_MC("invalid request BLR at offset %1")
.

//------------------------------------------------------------------------
/*24*/
MessageId       =IBP_MCE_FB25__IO_ERROR
Language        =Eng
_MC("I/O error during \"%1\" operation for file \"%2\".")
.

//------------------------------------------------------------------------
/*25*/
MessageId       =IBP_MCE_FB25__LOCK_CONFLICT
Language        =Eng
_MC("lock conflict on no wait transaction")
.

//------------------------------------------------------------------------
/*26*/
MessageId       =IBP_MCE_FB25__METADATA_CORRUPT
Language        =Eng
_MC("corrupt system table")
.

//------------------------------------------------------------------------
/*27*/
MessageId       =IBP_MCE_FB25__NOT_VALID
Language        =Eng
_MC("validation error for column %1, value \"%2\"")
.

//------------------------------------------------------------------------
/*28*/
MessageId       =IBP_MCE_FB25__NO_CUR_REC
Language        =Eng
_MC("no current record for fetch operation")
.

//------------------------------------------------------------------------
/*29*/
MessageId       =IBP_MCE_FB25__NO_DUP
Language        =Eng
_MC("attempt to store duplicate value (visible to active transactions) in unique index \"%1\"")
.

//------------------------------------------------------------------------
/*30*/
MessageId       =IBP_MCE_FB25__NO_FINISH
Language        =Eng
_MC("program attempted to exit without finishing database")
.

//------------------------------------------------------------------------
/*31*/
MessageId       =IBP_MCE_FB25__NO_META_UPDATE
Language        =Eng
_MC("unsuccessful metadata update")
.

//------------------------------------------------------------------------
/*32*/
MessageId       =IBP_MCE_FB25__NO_PRIV
Language        =Eng
_MC("no permission for %1 access to %2 %3")
.

//------------------------------------------------------------------------
/*33*/
MessageId       =IBP_MCE_FB25__NO_RECON
Language        =Eng
_MC("transaction is not in limbo")
.

//------------------------------------------------------------------------
/*34*/
MessageId       =IBP_MCE_FB25__NO_RECORD
Language        =Eng
_MC("invalid database key")
.

//------------------------------------------------------------------------
/*35*/
MessageId       =IBP_MCE_FB25__NO_SEGSTR_CLOSE
Language        =Eng
_MC("BLOB was not closed")
.

//------------------------------------------------------------------------
/*36*/
MessageId       =IBP_MCE_FB25__OBSOLETE_METADATA
Language        =Eng
_MC("metadata is obsolete")
.

//------------------------------------------------------------------------
/*37*/
MessageId       =IBP_MCE_FB25__OPEN_TRANS
Language        =Eng
_MC("Cannot disconnect database with open transactions (%1 active).")
.

//------------------------------------------------------------------------
/*38*/
MessageId       =IBP_MCE_FB25__PORT_LEN
Language        =Eng
_MC("message length error (encountered %1, expected %2)")
.

//------------------------------------------------------------------------
/*39*/
MessageId       =IBP_MCE_FB25__READ_ONLY_FIELD
Language        =Eng
_MC("attempted update of read-only column")
.

//------------------------------------------------------------------------
/*40*/
MessageId       =IBP_MCE_FB25__READ_ONLY_REL
Language        =Eng
_MC("attempted update of read-only table")
.

//------------------------------------------------------------------------
/*41*/
MessageId       =IBP_MCE_FB25__READ_ONLY_TRANS
Language        =Eng
_MC("attempted update during read-only transaction")
.

//------------------------------------------------------------------------
/*42*/
MessageId       =IBP_MCE_FB25__READ_ONLY_VIEW
Language        =Eng
_MC("cannot update read-only view %1")
.

//------------------------------------------------------------------------
/*43*/
MessageId       =IBP_MCE_FB25__REQ_NO_TRANS
Language        =Eng
_MC("no transaction for request")
.

//------------------------------------------------------------------------
/*44*/
MessageId       =IBP_MCE_FB25__REQ_SYNC
Language        =Eng
_MC("request synchronization error")
.

//------------------------------------------------------------------------
/*45*/
MessageId       =IBP_MCE_FB25__REQ_WRONG_DB
Language        =Eng
_MC("request referenced an unavailable database")
.

//------------------------------------------------------------------------
/*46*/
MessageId       =IBP_MCE_FB25__SEGMENT
Language        =Eng
_MC("segment buffer length shorter than expected")
.

//------------------------------------------------------------------------
/*47*/
MessageId       =IBP_MCE_FB25__SEGSTR_EOF
Language        =Eng
_MC("attempted retrieval of more segments than exist")
.

//------------------------------------------------------------------------
/*48*/
MessageId       =IBP_MCE_FB25__SEGSTR_NO_OP
Language        =Eng
_MC("attempted invalid operation on a BLOB")
.

//------------------------------------------------------------------------
/*49*/
MessageId       =IBP_MCE_FB25__SEGSTR_NO_READ
Language        =Eng
_MC("attempted read of a new, open BLOB")
.

//------------------------------------------------------------------------
/*50*/
MessageId       =IBP_MCE_FB25__SEGSTR_NO_TRANS
Language        =Eng
_MC("attempted action on BLOB outside transaction")
.

//------------------------------------------------------------------------
/*51*/
MessageId       =IBP_MCE_FB25__SEGSTR_NO_WRITE
Language        =Eng
_MC("attempted write to read-only BLOB")
.

//------------------------------------------------------------------------
/*52*/
MessageId       =IBP_MCE_FB25__SEGSTR_WRONG_DB
Language        =Eng
_MC("attempted reference to BLOB in unavailable database")
.

//------------------------------------------------------------------------
/*53*/
MessageId       =IBP_MCE_FB25__SYS_REQUEST
Language        =Eng
_MC("operating system directive %1 failed")
.

//------------------------------------------------------------------------
/*54*/
MessageId       =IBP_MCE_FB25__STREAM_EOF
Language        =Eng
_MC("attempt to fetch past the last record in a record stream")
.

//------------------------------------------------------------------------
/*55*/
MessageId       =IBP_MCE_FB25__UNAVAILABLE
Language        =Eng
_MC("unavailable database")
.

//------------------------------------------------------------------------
/*56*/
MessageId       =IBP_MCE_FB25__UNRES_REL
Language        =Eng
_MC("table %1 was omitted from the transaction reserving list")
.

//------------------------------------------------------------------------
/*57*/
MessageId       =IBP_MCE_FB25__UNS_EXT
Language        =Eng
_MC("request includes a DSRI extension not supported in this implementation")
.

//------------------------------------------------------------------------
/*58*/
MessageId       =IBP_MCE_FB25__WISH_LIST
Language        =Eng
_MC("feature is not supported")
.

//------------------------------------------------------------------------
/*59*/
MessageId       =IBP_MCE_FB25__WRONG_ODS
Language        =Eng
_MC("unsupported on-disk structure for file %1; found %2.%3, support %4.%5")
.

//------------------------------------------------------------------------
/*60*/
MessageId       =IBP_MCE_FB25__WRONUMARG
Language        =Eng
_MC("wrong number of arguments on call")
.

//------------------------------------------------------------------------
/*61*/
MessageId       =IBP_MCE_FB25__IMP_EXC
Language        =Eng
_MC("Implementation limit exceeded")
.

//------------------------------------------------------------------------
/*62*/
MessageId       =IBP_MCE_FB25__RANDOM
Language        =Eng
_MC("%1")
.

//------------------------------------------------------------------------
/*63*/
MessageId       =IBP_MCE_FB25__FATAL_CONFLICT
Language        =Eng
_MC("unrecoverable conflict with limbo transaction %1")
.

//------------------------------------------------------------------------
/*64*/
MessageId       =IBP_MCE_FB25__BADBLK
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*65*/
MessageId       =IBP_MCE_FB25__INVPOOLCL
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*66*/
MessageId       =IBP_MCE_FB25__NOPOOLIDS
Language        =Eng
_MC("too many requests")
.

//------------------------------------------------------------------------
/*67*/
MessageId       =IBP_MCE_FB25__RELBADBLK
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*68*/
MessageId       =IBP_MCE_FB25__BLKTOOBIG
Language        =Eng
_MC("block size exceeds implementation restriction")
.

//------------------------------------------------------------------------
/*69*/
MessageId       =IBP_MCE_FB25__BUFEXH
Language        =Eng
_MC("buffer exhausted")
.

//------------------------------------------------------------------------
/*70*/
MessageId       =IBP_MCE_FB25__SYNTAXERR
Language        =Eng
_MC("BLR syntax error: expected %1 at offset %2, encountered %3")
.

//------------------------------------------------------------------------
/*71*/
MessageId       =IBP_MCE_FB25__BUFINUSE
Language        =Eng
_MC("buffer in use")
.

//------------------------------------------------------------------------
/*72*/
MessageId       =IBP_MCE_FB25__BDBINCON
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*73*/
MessageId       =IBP_MCE_FB25__REQINUSE
Language        =Eng
_MC("request in use")
.

//------------------------------------------------------------------------
/*74*/
MessageId       =IBP_MCE_FB25__BADODSVER
Language        =Eng
_MC("incompatible version of on-disk structure")
.

//------------------------------------------------------------------------
/*75*/
MessageId       =IBP_MCE_FB25__RELNOTDEF
Language        =Eng
_MC("table %1 is not defined")
.

//------------------------------------------------------------------------
/*76*/
MessageId       =IBP_MCE_FB25__FLDNOTDEF
Language        =Eng
_MC("column %1 is not defined in table %2")
.

//------------------------------------------------------------------------
/*77*/
MessageId       =IBP_MCE_FB25__DIRTYPAGE
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*78*/
MessageId       =IBP_MCE_FB25__WAIFORTRA
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*79*/
MessageId       =IBP_MCE_FB25__DOUBLELOC
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*80*/
MessageId       =IBP_MCE_FB25__NODNOTFND
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*81*/
MessageId       =IBP_MCE_FB25__DUPNODFND
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*82*/
MessageId       =IBP_MCE_FB25__LOCNOTMAR
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*83*/
MessageId       =IBP_MCE_FB25__BADPAGTYP
Language        =Eng
_MC("page %1 is of wrong type (expected %2, found %3)")
.

//------------------------------------------------------------------------
/*84*/
MessageId       =IBP_MCE_FB25__CORRUPT
Language        =Eng
_MC("database corrupted")
.

//------------------------------------------------------------------------
/*85*/
MessageId       =IBP_MCE_FB25__BADPAGE
Language        =Eng
_MC("checksum error on database page %1")
.

//------------------------------------------------------------------------
/*86*/
MessageId       =IBP_MCE_FB25__BADINDEX
Language        =Eng
_MC("index is broken")
.

//------------------------------------------------------------------------
/*87*/
MessageId       =IBP_MCE_FB25__DBBNOTZER
Language        =Eng
_MC("database handle not zero")
.

//------------------------------------------------------------------------
/*88*/
MessageId       =IBP_MCE_FB25__TRANOTZER
Language        =Eng
_MC("transaction handle not zero")
.

//------------------------------------------------------------------------
/*89*/
MessageId       =IBP_MCE_FB25__TRAREQMIS
Language        =Eng
_MC("transaction--request mismatch (synchronization error)")
.

//------------------------------------------------------------------------
/*90*/
MessageId       =IBP_MCE_FB25__BADHNDCNT
Language        =Eng
_MC("bad handle count")
.

//------------------------------------------------------------------------
/*91*/
MessageId       =IBP_MCE_FB25__WROTPBVER
Language        =Eng
_MC("wrong version of transaction parameter block")
.

//------------------------------------------------------------------------
/*92*/
MessageId       =IBP_MCE_FB25__WROBLRVER
Language        =Eng
_MC("unsupported BLR version (expected %1, encountered %2)")
.

//------------------------------------------------------------------------
/*93*/
MessageId       =IBP_MCE_FB25__WRODPBVER
Language        =Eng
_MC("wrong version of database parameter block")
.

//------------------------------------------------------------------------
/*94*/
MessageId       =IBP_MCE_FB25__BLOBNOTSUP
Language        =Eng
_MC("BLOB and array data types are not supported for %1 operation")
.

//------------------------------------------------------------------------
/*95*/
MessageId       =IBP_MCE_FB25__BADRELATION
Language        =Eng
_MC("database corrupted")
.

//------------------------------------------------------------------------
/*96*/
MessageId       =IBP_MCE_FB25__NODETACH
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*97*/
MessageId       =IBP_MCE_FB25__NOTREMOTE
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*98*/
MessageId       =IBP_MCE_FB25__TRAINLIM
Language        =Eng
_MC("transaction in limbo")
.

//------------------------------------------------------------------------
/*99*/
MessageId       =IBP_MCE_FB25__NOTINLIM
Language        =Eng
_MC("transaction not in limbo")
.

//------------------------------------------------------------------------
/*100*/
MessageId       =IBP_MCE_FB25__TRAOUTSTA
Language        =Eng
_MC("transaction outstanding")
.

//------------------------------------------------------------------------
/*101*/
MessageId       =IBP_MCE_FB25__CONNECT_REJECT
Language        =Eng
_MC("connection rejected by remote interface")
.

//------------------------------------------------------------------------
/*102*/
MessageId       =IBP_MCE_FB25__DBFILE
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*103*/
MessageId       =IBP_MCE_FB25__ORPHAN
Language        =Eng
_MC("internal error")
.

//------------------------------------------------------------------------
/*104*/
MessageId       =IBP_MCE_FB25__NO_LOCK_MGR
Language        =Eng
_MC("no lock manager available")
.

//------------------------------------------------------------------------
/*105*/
MessageId       =IBP_MCE_FB25__CTXINUSE
Language        =Eng
_MC("context already in use (BLR error)")
.

//------------------------------------------------------------------------
/*106*/
MessageId       =IBP_MCE_FB25__CTXNOTDEF
Language        =Eng
_MC("context not defined (BLR error)")
.

//------------------------------------------------------------------------
/*107*/
MessageId       =IBP_MCE_FB25__DATNOTSUP
Language        =Eng
_MC("data operation not supported")
.

//------------------------------------------------------------------------
/*108*/
MessageId       =IBP_MCE_FB25__BADMSGNUM
Language        =Eng
_MC("undefined message number")
.

//------------------------------------------------------------------------
/*109*/
MessageId       =IBP_MCE_FB25__BADPARNUM
Language        =Eng
_MC("bad parameter number")
.

//------------------------------------------------------------------------
/*110*/
MessageId       =IBP_MCE_FB25__VIRMEMEXH
Language        =Eng
_MC("unable to allocate memory from operating system")
.

//------------------------------------------------------------------------
/*111*/
MessageId       =IBP_MCE_FB25__BLOCKING_SIGNAL
Language        =Eng
_MC("blocking signal has been received")
.

//------------------------------------------------------------------------
/*112*/
MessageId       =IBP_MCE_FB25__LOCKMANERR
Language        =Eng
_MC("lock manager error")
.

//------------------------------------------------------------------------
/*113*/
MessageId       =IBP_MCE_FB25__JOURNERR
Language        =Eng
_MC("communication error with journal \"%1\"")
.

//------------------------------------------------------------------------
/*114*/
MessageId       =IBP_MCE_FB25__KEYTOOBIG
Language        =Eng
_MC("key size exceeds implementation restriction for index \"%1\"")
.

//------------------------------------------------------------------------
/*115*/
MessageId       =IBP_MCE_FB25__NULLSEGKEY
Language        =Eng
_MC("null segment of UNIQUE KEY")
.

//------------------------------------------------------------------------
/*116*/
MessageId       =IBP_MCE_FB25__SQLERR
Language        =Eng
_MC("SQL error code = %1")
.

//------------------------------------------------------------------------
/*117*/
MessageId       =IBP_MCE_FB25__WRODYNVER
Language        =Eng
_MC("wrong DYN version")
.

//------------------------------------------------------------------------
/*118*/
MessageId       =IBP_MCE_FB25__FUNNOTDEF
Language        =Eng
_MC("function %1 is not defined")
.

//------------------------------------------------------------------------
/*119*/
MessageId       =IBP_MCE_FB25__FUNMISMAT
Language        =Eng
_MC("function %1 could not be matched")
.

//------------------------------------------------------------------------
/*120*/
MessageId       =IBP_MCE_FB25__BAD_MSG_VEC
Language        =Eng
_MC("")
.

//------------------------------------------------------------------------
/*121*/
MessageId       =IBP_MCE_FB25__BAD_DETACH
Language        =Eng
_MC("database detach completed with errors")
.

//------------------------------------------------------------------------
/*122*/
MessageId       =IBP_MCE_FB25__NOARGACC_READ
Language        =Eng
_MC("database system cannot read argument %1")
.

//------------------------------------------------------------------------
/*123*/
MessageId       =IBP_MCE_FB25__NOARGACC_WRITE
Language        =Eng
_MC("database system cannot write argument %1")
.

//------------------------------------------------------------------------
/*124*/
MessageId       =IBP_MCE_FB25__READ_ONLY
Language        =Eng
_MC("operation not supported")
.

//------------------------------------------------------------------------
/*125*/
MessageId       =IBP_MCE_FB25__EXT_ERR
Language        =Eng
_MC("%1 extension error")
.

//------------------------------------------------------------------------
/*126*/
MessageId       =IBP_MCE_FB25__NON_UPDATABLE
Language        =Eng
_MC("not updatable")
.

//------------------------------------------------------------------------
/*127*/
MessageId       =IBP_MCE_FB25__NO_ROLLBACK
Language        =Eng
_MC("no rollback performed")
.

//------------------------------------------------------------------------
/*128*/
MessageId       =IBP_MCE_FB25__BAD_SEC_INFO
Language        =Eng
_MC("")
.

//------------------------------------------------------------------------
/*129*/
MessageId       =IBP_MCE_FB25__INVALID_SEC_INFO
Language        =Eng
_MC("")
.

//------------------------------------------------------------------------
/*130*/
MessageId       =IBP_MCE_FB25__MISC_INTERPRETED
Language        =Eng
_MC("%1")
.

//------------------------------------------------------------------------
/*131*/
MessageId       =IBP_MCE_FB25__UPDATE_CONFLICT
Language        =Eng
_MC("update conflicts with concurrent update")
.

//------------------------------------------------------------------------
/*132*/
MessageId       =IBP_MCE_FB25__UNLICENSED
Language        =Eng
_MC("product %1 is not licensed")
.

//------------------------------------------------------------------------
/*133*/
MessageId       =IBP_MCE_FB25__OBJ_IN_USE
Language        =Eng
_MC("object %1 is in use")
.

//------------------------------------------------------------------------
/*134*/
MessageId       =IBP_MCE_FB25__NOFILTER
Language        =Eng
_MC("filter not found to convert type %1 to type %2")
.

//------------------------------------------------------------------------
/*135*/
MessageId       =IBP_MCE_FB25__SHADOW_ACCESSED
Language        =Eng
_MC("cannot attach active shadow file")
.

//------------------------------------------------------------------------
/*136*/
MessageId       =IBP_MCE_FB25__INVALID_SDL
Language        =Eng
_MC("invalid slice description language at offset %1")
.

//------------------------------------------------------------------------
/*137*/
MessageId       =IBP_MCE_FB25__OUT_OF_BOUNDS
Language        =Eng
_MC("subscript out of bounds")
.

//------------------------------------------------------------------------
/*138*/
MessageId       =IBP_MCE_FB25__INVALID_DIMENSION
Language        =Eng
_MC("column not array or invalid dimensions (expected %1, encountered %2)")
.

//------------------------------------------------------------------------
/*139*/
MessageId       =IBP_MCE_FB25__REC_IN_LIMBO
Language        =Eng
_MC("record from transaction %1 is stuck in limbo")
.

//------------------------------------------------------------------------
/*140*/
MessageId       =IBP_MCE_FB25__SHADOW_MISSING
Language        =Eng
_MC("a file in manual shadow %1 is unavailable")
.

//------------------------------------------------------------------------
/*141*/
MessageId       =IBP_MCE_FB25__CANT_VALIDATE
Language        =Eng
_MC("secondary server attachments cannot validate databases")
.

//------------------------------------------------------------------------
/*142*/
MessageId       =IBP_MCE_FB25__CANT_START_JOURNAL
Language        =Eng
_MC("secondary server attachments cannot start journaling")
.

//------------------------------------------------------------------------
/*143*/
MessageId       =IBP_MCE_FB25__GENNOTDEF
Language        =Eng
_MC("generator %1 is not defined")
.

//------------------------------------------------------------------------
/*144*/
MessageId       =IBP_MCE_FB25__CANT_START_LOGGING
Language        =Eng
_MC("secondary server attachments cannot start logging")
.

//------------------------------------------------------------------------
/*145*/
MessageId       =IBP_MCE_FB25__BAD_SEGSTR_TYPE
Language        =Eng
_MC("invalid BLOB type for operation")
.

//------------------------------------------------------------------------
/*146*/
MessageId       =IBP_MCE_FB25__FOREIGN_KEY
Language        =Eng
_MC("violation of FOREIGN KEY constraint \"%1\" on table \"%2\"")
.

//------------------------------------------------------------------------
/*147*/
MessageId       =IBP_MCE_FB25__HIGH_MINOR
Language        =Eng
_MC("minor version too high found %1 expected %2")
.

//------------------------------------------------------------------------
/*148*/
MessageId       =IBP_MCE_FB25__TRA_STATE
Language        =Eng
_MC("transaction %1 is %2")
.

//------------------------------------------------------------------------
/*149*/
MessageId       =IBP_MCE_FB25__TRANS_INVALID
Language        =Eng
_MC("transaction marked invalid by I/O error")
.

//------------------------------------------------------------------------
/*150*/
MessageId       =IBP_MCE_FB25__BUF_INVALID
Language        =Eng
_MC("cache buffer for page %1 invalid")
.

//------------------------------------------------------------------------
/*151*/
MessageId       =IBP_MCE_FB25__INDEXNOTDEFINED
Language        =Eng
_MC("there is no index in table %1 with id %2")
.

//------------------------------------------------------------------------
/*152*/
MessageId       =IBP_MCE_FB25__LOGIN
Language        =Eng
_MC("Your user name and password are not defined. Ask your database administrator to set up a Firebird login.")
.

//------------------------------------------------------------------------
/*153*/
MessageId       =IBP_MCE_FB25__INVALID_BOOKMARK
Language        =Eng
_MC("invalid bookmark handle")
.

//------------------------------------------------------------------------
/*154*/
MessageId       =IBP_MCE_FB25__BAD_LOCK_LEVEL
Language        =Eng
_MC("invalid lock level %1")
.

//------------------------------------------------------------------------
/*155*/
MessageId       =IBP_MCE_FB25__RELATION_LOCK
Language        =Eng
_MC("lock on table %1 conflicts with existing lock")
.

//------------------------------------------------------------------------
/*156*/
MessageId       =IBP_MCE_FB25__RECORD_LOCK
Language        =Eng
_MC("requested record lock conflicts with existing lock")
.

//------------------------------------------------------------------------
/*157*/
MessageId       =IBP_MCE_FB25__MAX_IDX
Language        =Eng
_MC("maximum indexes per table (%1) exceeded")
.

//------------------------------------------------------------------------
/*158*/
MessageId       =IBP_MCE_FB25__JRN_ENABLE
Language        =Eng
_MC("enable journal for database before starting online dump")
.

//------------------------------------------------------------------------
/*159*/
MessageId       =IBP_MCE_FB25__OLD_FAILURE
Language        =Eng
_MC("online dump failure. Retry dump")
.

//------------------------------------------------------------------------
/*160*/
MessageId       =IBP_MCE_FB25__OLD_IN_PROGRESS
Language        =Eng
_MC("an online dump is already in progress")
.

//------------------------------------------------------------------------
/*161*/
MessageId       =IBP_MCE_FB25__OLD_NO_SPACE
Language        =Eng
_MC("no more disk/tape space. Cannot continue online dump")
.

//------------------------------------------------------------------------
/*162*/
MessageId       =IBP_MCE_FB25__NO_WAL_NO_JRN
Language        =Eng
_MC("journaling allowed only if database has Write-ahead Log")
.

//------------------------------------------------------------------------
/*163*/
MessageId       =IBP_MCE_FB25__NUM_OLD_FILES
Language        =Eng
_MC("maximum number of online dump files that can be specified is 16")
.

//------------------------------------------------------------------------
/*164*/
MessageId       =IBP_MCE_FB25__WAL_FILE_OPEN
Language        =Eng
_MC("error in opening Write-ahead Log file during recovery")
.

//------------------------------------------------------------------------
/*165*/
MessageId       =IBP_MCE_FB25__BAD_STMT_HANDLE
Language        =Eng
_MC("invalid statement handle")
.

//------------------------------------------------------------------------
/*166*/
MessageId       =IBP_MCE_FB25__WAL_FAILURE
Language        =Eng
_MC("Write-ahead log subsystem failure")
.

//------------------------------------------------------------------------
/*167*/
MessageId       =IBP_MCE_FB25__WALW_ERR
Language        =Eng
_MC("WAL Writer error")
.

//------------------------------------------------------------------------
/*168*/
MessageId       =IBP_MCE_FB25__LOGH_SMALL
Language        =Eng
_MC("Log file header of %1 too small")
.

//------------------------------------------------------------------------
/*169*/
MessageId       =IBP_MCE_FB25__LOGH_INV_VERSION
Language        =Eng
_MC("Invalid version of log file %1")
.

//------------------------------------------------------------------------
/*170*/
MessageId       =IBP_MCE_FB25__LOGH_OPEN_FLAG
Language        =Eng
_MC("Log file %1 not latest in the chain but open flag still set")
.

//------------------------------------------------------------------------
/*171*/
MessageId       =IBP_MCE_FB25__LOGH_OPEN_FLAG2
Language        =Eng
_MC("Log file %1 not closed properly; database recovery may be required")
.

//------------------------------------------------------------------------
/*172*/
MessageId       =IBP_MCE_FB25__LOGH_DIFF_DBNAME
Language        =Eng
_MC("Database name in the log file %1 is different")
.

//------------------------------------------------------------------------
/*173*/
MessageId       =IBP_MCE_FB25__LOGF_UNEXPECTED_EOF
Language        =Eng
_MC("Unexpected end of log file %1 at offset %2")
.

//------------------------------------------------------------------------
/*174*/
MessageId       =IBP_MCE_FB25__LOGR_INCOMPLETE
Language        =Eng
_MC("Incomplete log record at offset %1 in log file %2")
.

//------------------------------------------------------------------------
/*175*/
MessageId       =IBP_MCE_FB25__LOGR_HEADER_SMALL
Language        =Eng
_MC("Log record header too small at offset %1 in log file %2")
.

//------------------------------------------------------------------------
/*176*/
MessageId       =IBP_MCE_FB25__LOGB_SMALL
Language        =Eng
_MC("Log block too small at offset %1 in log file %2")
.

//------------------------------------------------------------------------
/*177*/
MessageId       =IBP_MCE_FB25__WAL_ILLEGAL_ATTACH
Language        =Eng
_MC("Illegal attempt to attach to an uninitialized WAL segment for %1")
.

//------------------------------------------------------------------------
/*178*/
MessageId       =IBP_MCE_FB25__WAL_INVALID_WPB
Language        =Eng
_MC("Invalid WAL parameter block option %1")
.

//------------------------------------------------------------------------
/*179*/
MessageId       =IBP_MCE_FB25__WAL_ERR_ROLLOVER
Language        =Eng
_MC("Cannot roll over to the next log file %1")
.

//------------------------------------------------------------------------
/*180*/
MessageId       =IBP_MCE_FB25__NO_WAL
Language        =Eng
_MC("database does not use Write-ahead Log")
.

//------------------------------------------------------------------------
/*181*/
MessageId       =IBP_MCE_FB25__DROP_WAL
Language        =Eng
_MC("cannot drop log file when journaling is enabled")
.

//------------------------------------------------------------------------
/*182*/
MessageId       =IBP_MCE_FB25__STREAM_NOT_DEFINED
Language        =Eng
_MC("reference to invalid stream number")
.

//------------------------------------------------------------------------
/*183*/
MessageId       =IBP_MCE_FB25__WAL_SUBSYS_ERROR
Language        =Eng
_MC("WAL subsystem encountered error")
.

//------------------------------------------------------------------------
/*184*/
MessageId       =IBP_MCE_FB25__WAL_SUBSYS_CORRUPT
Language        =Eng
_MC("WAL subsystem corrupted")
.

//------------------------------------------------------------------------
/*185*/
MessageId       =IBP_MCE_FB25__NO_ARCHIVE
Language        =Eng
_MC("must specify archive file when enabling long term journal for databases with round-robin log files")
.

//------------------------------------------------------------------------
/*186*/
MessageId       =IBP_MCE_FB25__SHUTINPROG
Language        =Eng
_MC("database %1 shutdown in progress")
.

//------------------------------------------------------------------------
/*187*/
MessageId       =IBP_MCE_FB25__RANGE_IN_USE
Language        =Eng
_MC("refresh range number %1 already in use")
.

//------------------------------------------------------------------------
/*188*/
MessageId       =IBP_MCE_FB25__RANGE_NOT_FOUND
Language        =Eng
_MC("refresh range number %1 not found")
.

//------------------------------------------------------------------------
/*189*/
MessageId       =IBP_MCE_FB25__CHARSET_NOT_FOUND
Language        =Eng
_MC("CHARACTER SET %1 is not defined")
.

//------------------------------------------------------------------------
/*190*/
MessageId       =IBP_MCE_FB25__LOCK_TIMEOUT
Language        =Eng
_MC("lock time-out on wait transaction")
.

//------------------------------------------------------------------------
/*191*/
MessageId       =IBP_MCE_FB25__PRCNOTDEF
Language        =Eng
_MC("procedure %1 is not defined")
.

//------------------------------------------------------------------------
/*192*/
MessageId       =IBP_MCE_FB25__PRCMISMAT
Language        =Eng
_MC("Input parameter mismatch for procedure %1")
.

//------------------------------------------------------------------------
/*193*/
MessageId       =IBP_MCE_FB25__WAL_BUGCHECK
Language        =Eng
_MC("Database %1: WAL subsystem bug for pid %2\n"
    "%3")
.

//------------------------------------------------------------------------
/*194*/
MessageId       =IBP_MCE_FB25__WAL_CANT_EXPAND
Language        =Eng
_MC("Could not expand the WAL segment for database %1")
.

//------------------------------------------------------------------------
/*195*/
MessageId       =IBP_MCE_FB25__CODNOTDEF
Language        =Eng
_MC("status code %1 unknown")
.

//------------------------------------------------------------------------
/*196*/
MessageId       =IBP_MCE_FB25__XCPNOTDEF
Language        =Eng
_MC("exception %1 not defined")
.

//------------------------------------------------------------------------
/*197*/
MessageId       =IBP_MCE_FB25__EXCEPT
Language        =Eng
_MC("exception %1")
.

//------------------------------------------------------------------------
/*198*/
MessageId       =IBP_MCE_FB25__CACHE_RESTART
Language        =Eng
_MC("restart shared cache manager")
.

//------------------------------------------------------------------------
/*199*/
MessageId       =IBP_MCE_FB25__BAD_LOCK_HANDLE
Language        =Eng
_MC("invalid lock handle")
.

//------------------------------------------------------------------------
/*200*/
MessageId       =IBP_MCE_FB25__JRN_PRESENT
Language        =Eng
_MC("long-term journaling already enabled")
.

//------------------------------------------------------------------------
/*201*/
MessageId       =IBP_MCE_FB25__WAL_ERR_ROLLOVER2
Language        =Eng
_MC("Unable to roll over please see Firebird log.")
.

//------------------------------------------------------------------------
/*202*/
MessageId       =IBP_MCE_FB25__WAL_ERR_LOGWRITE
Language        =Eng
_MC("WAL I/O error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*203*/
MessageId       =IBP_MCE_FB25__WAL_ERR_JRN_COMM
Language        =Eng
_MC("WAL writer - Journal server communication error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*204*/
MessageId       =IBP_MCE_FB25__WAL_ERR_EXPANSION
Language        =Eng
_MC("WAL buffers cannot be increased. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*205*/
MessageId       =IBP_MCE_FB25__WAL_ERR_SETUP
Language        =Eng
_MC("WAL setup error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*206*/
MessageId       =IBP_MCE_FB25__WAL_ERR_WW_SYNC
Language        =Eng
_MC("obsolete")
.

//------------------------------------------------------------------------
/*207*/
MessageId       =IBP_MCE_FB25__WAL_ERR_WW_START
Language        =Eng
_MC("Cannot start WAL writer for the database %1")
.

//------------------------------------------------------------------------
/*208*/
MessageId       =IBP_MCE_FB25__SHUTDOWN
Language        =Eng
_MC("database %1 shutdown")
.

//------------------------------------------------------------------------
/*209*/
MessageId       =IBP_MCE_FB25__EXISTING_PRIV_MOD
Language        =Eng
_MC("cannot modify an existing user privilege")
.

//------------------------------------------------------------------------
/*210*/
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_REF
Language        =Eng
_MC("Cannot delete PRIMARY KEY being used in FOREIGN KEY definition.")
.

//------------------------------------------------------------------------
/*211*/
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_NOTNULL
Language        =Eng
_MC("Column used in a PRIMARY constraint must be NOT NULL.")
.

//------------------------------------------------------------------------
/*212*/
MessageId       =IBP_MCE_FB25__REF_CNSTRNT_NOTFOUND
Language        =Eng
_MC("Name of Referential Constraint not defined in constraints table.")
.

//------------------------------------------------------------------------
/*213*/
MessageId       =IBP_MCE_FB25__FOREIGN_KEY_NOTFOUND
Language        =Eng
_MC("Non-existent PRIMARY or UNIQUE KEY specified for FOREIGN KEY.")
.

//------------------------------------------------------------------------
/*214*/
MessageId       =IBP_MCE_FB25__REF_CNSTRNT_UPDATE
Language        =Eng
_MC("Cannot update constraints (RDB$REF_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*215*/
MessageId       =IBP_MCE_FB25__CHECK_CNSTRNT_UPDATE
Language        =Eng
_MC("Cannot update constraints (RDB$CHECK_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*216*/
MessageId       =IBP_MCE_FB25__CHECK_CNSTRNT_DEL
Language        =Eng
_MC("Cannot delete CHECK constraint entry (RDB$CHECK_CONSTRAINTS)")
.

//------------------------------------------------------------------------
/*217*/
MessageId       =IBP_MCE_FB25__INTEG_INDEX_SEG_DEL
Language        =Eng
_MC("Cannot delete index segment used by an Integrity Constraint")
.

//------------------------------------------------------------------------
/*218*/
MessageId       =IBP_MCE_FB25__INTEG_INDEX_SEG_MOD
Language        =Eng
_MC("Cannot update index segment used by an Integrity Constraint")
.

//------------------------------------------------------------------------
/*219*/
MessageId       =IBP_MCE_FB25__INTEG_INDEX_DEL
Language        =Eng
_MC("Cannot delete index used by an Integrity Constraint")
.

//------------------------------------------------------------------------
/*220*/
MessageId       =IBP_MCE_FB25__INTEG_INDEX_MOD
Language        =Eng
_MC("Cannot modify index used by an Integrity Constraint")
.

//------------------------------------------------------------------------
/*221*/
MessageId       =IBP_MCE_FB25__CHECK_TRIG_DEL
Language        =Eng
_MC("Cannot delete trigger used by a CHECK Constraint")
.

//------------------------------------------------------------------------
/*222*/
MessageId       =IBP_MCE_FB25__CHECK_TRIG_UPDATE
Language        =Eng
_MC("Cannot update trigger used by a CHECK Constraint")
.

//------------------------------------------------------------------------
/*223*/
MessageId       =IBP_MCE_FB25__CNSTRNT_FLD_DEL
Language        =Eng
_MC("Cannot delete column being used in an Integrity Constraint.")
.

//------------------------------------------------------------------------
/*224*/
MessageId       =IBP_MCE_FB25__CNSTRNT_FLD_RENAME
Language        =Eng
_MC("Cannot rename column being used in an Integrity Constraint.")
.

//------------------------------------------------------------------------
/*225*/
MessageId       =IBP_MCE_FB25__REL_CNSTRNT_UPDATE
Language        =Eng
_MC("Cannot update constraints (RDB$RELATION_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*226*/
MessageId       =IBP_MCE_FB25__CONSTAINT_ON_VIEW
Language        =Eng
_MC("Cannot define constraints on views")
.

//------------------------------------------------------------------------
/*227*/
MessageId       =IBP_MCE_FB25__INVLD_CNSTRNT_TYPE
Language        =Eng
_MC("internal Firebird consistency check (invalid RDB$CONSTRAINT_TYPE)")
.

//------------------------------------------------------------------------
/*228*/
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_EXISTS
Language        =Eng
_MC("Attempt to define a second PRIMARY KEY for the same table")
.

//------------------------------------------------------------------------
/*229*/
MessageId       =IBP_MCE_FB25__SYSTRIG_UPDATE
Language        =Eng
_MC("cannot modify or erase a system trigger")
.

//------------------------------------------------------------------------
/*230*/
MessageId       =IBP_MCE_FB25__NOT_REL_OWNER
Language        =Eng
_MC("only the owner of a table may reassign ownership")
.

//------------------------------------------------------------------------
/*231*/
MessageId       =IBP_MCE_FB25__GRANT_OBJ_NOTFOUND
Language        =Eng
_MC("could not find table/procedure for GRANT")
.

//------------------------------------------------------------------------
/*232*/
MessageId       =IBP_MCE_FB25__GRANT_FLD_NOTFOUND
Language        =Eng
_MC("could not find column for GRANT")
.

//------------------------------------------------------------------------
/*233*/
MessageId       =IBP_MCE_FB25__GRANT_NOPRIV
Language        =Eng
_MC("user does not have GRANT privileges for operation")
.

//------------------------------------------------------------------------
/*234*/
MessageId       =IBP_MCE_FB25__NONSQL_SECURITY_REL
Language        =Eng
_MC("table/procedure has non-SQL security class defined")
.

//------------------------------------------------------------------------
/*235*/
MessageId       =IBP_MCE_FB25__NONSQL_SECURITY_FLD
Language        =Eng
_MC("column has non-SQL security class defined")
.

//------------------------------------------------------------------------
/*236*/
MessageId       =IBP_MCE_FB25__WAL_CACHE_ERR
Language        =Eng
_MC("Write-ahead Log without shared cache configuration not allowed")
.

//------------------------------------------------------------------------
/*237*/
MessageId       =IBP_MCE_FB25__SHUTFAIL
Language        =Eng
_MC("database shutdown unsuccessful")
.

//------------------------------------------------------------------------
/*238*/
MessageId       =IBP_MCE_FB25__CHECK_CONSTRAINT
Language        =Eng
_MC("Operation violates CHECK constraint %1 on view or table %2")
.

//------------------------------------------------------------------------
/*239*/
MessageId       =IBP_MCE_FB25__BAD_SVC_HANDLE
Language        =Eng
_MC("invalid service handle")
.

//------------------------------------------------------------------------
/*240*/
MessageId       =IBP_MCE_FB25__SHUTWARN
Language        =Eng
_MC("database %1 shutdown in %2 seconds")
.

//------------------------------------------------------------------------
/*241*/
MessageId       =IBP_MCE_FB25__WROSPBVER
Language        =Eng
_MC("wrong version of service parameter block")
.

//------------------------------------------------------------------------
/*242*/
MessageId       =IBP_MCE_FB25__BAD_SPB_FORM
Language        =Eng
_MC("unrecognized service parameter block")
.

//------------------------------------------------------------------------
/*243*/
MessageId       =IBP_MCE_FB25__SVCNOTDEF
Language        =Eng
_MC("service %1 is not defined")
.

//------------------------------------------------------------------------
/*244*/
MessageId       =IBP_MCE_FB25__NO_JRN
Language        =Eng
_MC("long-term journaling not enabled")
.

//------------------------------------------------------------------------
/*245*/
MessageId       =IBP_MCE_FB25__TRANSLITERATION_FAILED
Language        =Eng
_MC("Cannot transliterate character between character sets")
.

//------------------------------------------------------------------------
/*246*/
MessageId       =IBP_MCE_FB25__START_CM_FOR_WAL
Language        =Eng
_MC("WAL defined; Cache Manager must be started first")
.

//------------------------------------------------------------------------
/*247*/
MessageId       =IBP_MCE_FB25__WAL_OVFLOW_LOG_REQUIRED
Language        =Eng
_MC("Overflow log specification required for round-robin log")
.

//------------------------------------------------------------------------
/*248*/
MessageId       =IBP_MCE_FB25__TEXT_SUBTYPE
Language        =Eng
_MC("Implementation of text subtype %1 not located.")
.

//------------------------------------------------------------------------
/*249*/
MessageId       =IBP_MCE_FB25__DSQL_ERROR
Language        =Eng
_MC("Dynamic SQL Error")
.

//------------------------------------------------------------------------
/*250*/
MessageId       =IBP_MCE_FB25__DSQL_COMMAND_ERR
Language        =Eng
_MC("Invalid command")
.

//------------------------------------------------------------------------
/*251*/
MessageId       =IBP_MCE_FB25__DSQL_CONSTANT_ERR
Language        =Eng
_MC("Data type for constant unknown")
.

//------------------------------------------------------------------------
/*252*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_ERR
Language        =Eng
_MC("Invalid cursor reference")
.

//------------------------------------------------------------------------
/*253*/
MessageId       =IBP_MCE_FB25__DSQL_DATATYPE_ERR
Language        =Eng
_MC("Data type unknown")
.

//------------------------------------------------------------------------
/*254*/
MessageId       =IBP_MCE_FB25__DSQL_DECL_ERR
Language        =Eng
_MC("Invalid cursor declaration")
.

//------------------------------------------------------------------------
/*255*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_UPDATE_ERR
Language        =Eng
_MC("Cursor %1 is not updatable")
.

//------------------------------------------------------------------------
/*256*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_OPEN_ERR
Language        =Eng
_MC("Attempt to reopen an open cursor")
.

//------------------------------------------------------------------------
/*257*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_CLOSE_ERR
Language        =Eng
_MC("Attempt to reclose a closed cursor")
.

//------------------------------------------------------------------------
/*258*/
MessageId       =IBP_MCE_FB25__DSQL_FIELD_ERR
Language        =Eng
_MC("Column unknown")
.

//------------------------------------------------------------------------
/*259*/
MessageId       =IBP_MCE_FB25__DSQL_INTERNAL_ERR
Language        =Eng
_MC("Internal error")
.

//------------------------------------------------------------------------
/*260*/
MessageId       =IBP_MCE_FB25__DSQL_RELATION_ERR
Language        =Eng
_MC("Table unknown")
.

//------------------------------------------------------------------------
/*261*/
MessageId       =IBP_MCE_FB25__DSQL_PROCEDURE_ERR
Language        =Eng
_MC("Procedure unknown")
.

//------------------------------------------------------------------------
/*262*/
MessageId       =IBP_MCE_FB25__DSQL_REQUEST_ERR
Language        =Eng
_MC("Request unknown")
.

//------------------------------------------------------------------------
/*263*/
MessageId       =IBP_MCE_FB25__DSQL_SQLDA_ERR
Language        =Eng
_MC("SQLDA missing or incorrect version, or incorrect number/type of variables")
.

//------------------------------------------------------------------------
/*264*/
MessageId       =IBP_MCE_FB25__DSQL_VAR_COUNT_ERR
Language        =Eng
_MC("Count of read-write columns does not equal count of values")
.

//------------------------------------------------------------------------
/*265*/
MessageId       =IBP_MCE_FB25__DSQL_STMT_HANDLE
Language        =Eng
_MC("Invalid statement handle")
.

//------------------------------------------------------------------------
/*266*/
MessageId       =IBP_MCE_FB25__DSQL_FUNCTION_ERR
Language        =Eng
_MC("Function unknown")
.

//------------------------------------------------------------------------
/*267*/
MessageId       =IBP_MCE_FB25__DSQL_BLOB_ERR
Language        =Eng
_MC("Column is not a BLOB")
.

//------------------------------------------------------------------------
/*268*/
MessageId       =IBP_MCE_FB25__COLLATION_NOT_FOUND
Language        =Eng
_MC("COLLATION %1 for CHARACTER SET %2 is not defined")
.

//------------------------------------------------------------------------
/*269*/
MessageId       =IBP_MCE_FB25__COLLATION_NOT_FOR_CHARSET
Language        =Eng
_MC("COLLATION %1 is not valid for specified CHARACTER SET")
.

//------------------------------------------------------------------------
/*270*/
MessageId       =IBP_MCE_FB25__DSQL_DUP_OPTION
Language        =Eng
_MC("Option specified more than once")
.

//------------------------------------------------------------------------
/*271*/
MessageId       =IBP_MCE_FB25__DSQL_TRAN_ERR
Language        =Eng
_MC("Unknown transaction option")
.

//------------------------------------------------------------------------
/*272*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_ARRAY
Language        =Eng
_MC("Invalid array reference")
.

//------------------------------------------------------------------------
/*273*/
MessageId       =IBP_MCE_FB25__DSQL_MAX_ARR_DIM_EXCEEDED
Language        =Eng
_MC("Array declared with too many dimensions")
.

//------------------------------------------------------------------------
/*274*/
MessageId       =IBP_MCE_FB25__DSQL_ARR_RANGE_ERROR
Language        =Eng
_MC("Illegal array dimension range")
.

//------------------------------------------------------------------------
/*275*/
MessageId       =IBP_MCE_FB25__DSQL_TRIGGER_ERR
Language        =Eng
_MC("Trigger unknown")
.

//------------------------------------------------------------------------
/*276*/
MessageId       =IBP_MCE_FB25__DSQL_SUBSELECT_ERR
Language        =Eng
_MC("Subselect illegal in this context")
.

//------------------------------------------------------------------------
/*277*/
MessageId       =IBP_MCE_FB25__DSQL_CRDB_PREPARE_ERR
Language        =Eng
_MC("Cannot prepare a CREATE DATABASE/SCHEMA statement")
.

//------------------------------------------------------------------------
/*278*/
MessageId       =IBP_MCE_FB25__SPECIFY_FIELD_ERR
Language        =Eng
_MC("must specify column name for view select expression")
.

//------------------------------------------------------------------------
/*279*/
MessageId       =IBP_MCE_FB25__NUM_FIELD_ERR
Language        =Eng
_MC("number of columns does not match select list")
.

//------------------------------------------------------------------------
/*280*/
MessageId       =IBP_MCE_FB25__COL_NAME_ERR
Language        =Eng
_MC("Only simple column names permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*281*/
MessageId       =IBP_MCE_FB25__WHERE_ERR
Language        =Eng
_MC("No WHERE clause for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*282*/
MessageId       =IBP_MCE_FB25__TABLE_VIEW_ERR
Language        =Eng
_MC("Only one table allowed for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*283*/
MessageId       =IBP_MCE_FB25__DISTINCT_ERR
Language        =Eng
_MC("DISTINCT, GROUP or HAVING not permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*284*/
MessageId       =IBP_MCE_FB25__KEY_FIELD_COUNT_ERR
Language        =Eng
_MC("FOREIGN KEY column count does not match PRIMARY KEY")
.

//------------------------------------------------------------------------
/*285*/
MessageId       =IBP_MCE_FB25__SUBQUERY_ERR
Language        =Eng
_MC("No subqueries permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*286*/
MessageId       =IBP_MCE_FB25__EXPRESSION_EVAL_ERR
Language        =Eng
_MC("expression evaluation not supported")
.

//------------------------------------------------------------------------
/*287*/
MessageId       =IBP_MCE_FB25__NODE_ERR
Language        =Eng
_MC("gen.c: node not supported")
.

//------------------------------------------------------------------------
/*288*/
MessageId       =IBP_MCE_FB25__COMMAND_END_ERR
Language        =Eng
_MC("Unexpected end of command")
.

//------------------------------------------------------------------------
/*289*/
MessageId       =IBP_MCE_FB25__INDEX_NAME
Language        =Eng
_MC("INDEX %1")
.

//------------------------------------------------------------------------
/*290*/
MessageId       =IBP_MCE_FB25__EXCEPTION_NAME
Language        =Eng
_MC("EXCEPTION %1")
.

//------------------------------------------------------------------------
/*291*/
MessageId       =IBP_MCE_FB25__FIELD_NAME
Language        =Eng
_MC("COLUMN %1")
.

//------------------------------------------------------------------------
/*292*/
MessageId       =IBP_MCE_FB25__TOKEN_ERR
Language        =Eng
_MC("Token unknown")
.

//------------------------------------------------------------------------
/*293*/
MessageId       =IBP_MCE_FB25__UNION_ERR
Language        =Eng
_MC("union not supported")
.

//------------------------------------------------------------------------
/*294*/
MessageId       =IBP_MCE_FB25__DSQL_CONSTRUCT_ERR
Language        =Eng
_MC("Unsupported DSQL construct")
.

//------------------------------------------------------------------------
/*295*/
MessageId       =IBP_MCE_FB25__FIELD_AGGREGATE_ERR
Language        =Eng
_MC("column used with aggregate")
.

//------------------------------------------------------------------------
/*296*/
MessageId       =IBP_MCE_FB25__FIELD_REF_ERR
Language        =Eng
_MC("invalid column reference")
.

//------------------------------------------------------------------------
/*297*/
MessageId       =IBP_MCE_FB25__ORDER_BY_ERR
Language        =Eng
_MC("invalid ORDER BY clause")
.

//------------------------------------------------------------------------
/*298*/
MessageId       =IBP_MCE_FB25__RETURN_MODE_ERR
Language        =Eng
_MC("Return mode by value not allowed for this data type")
.

//------------------------------------------------------------------------
/*299*/
MessageId       =IBP_MCE_FB25__EXTERN_FUNC_ERR
Language        =Eng
_MC("External functions cannot have more than 10 parameters")
.

//------------------------------------------------------------------------
/*300*/
MessageId       =IBP_MCE_FB25__ALIAS_CONFLICT_ERR
Language        =Eng
_MC("alias %1 conflicts with an alias in the same statement")
.

//------------------------------------------------------------------------
/*301*/
MessageId       =IBP_MCE_FB25__PROCEDURE_CONFLICT_ERROR
Language        =Eng
_MC("alias %1 conflicts with a procedure in the same statement")
.

//------------------------------------------------------------------------
/*302*/
MessageId       =IBP_MCE_FB25__RELATION_CONFLICT_ERR
Language        =Eng
_MC("alias %1 conflicts with a table in the same statement")
.

//------------------------------------------------------------------------
/*303*/
MessageId       =IBP_MCE_FB25__DSQL_DOMAIN_ERR
Language        =Eng
_MC("Illegal use of keyword VALUE")
.

//------------------------------------------------------------------------
/*304*/
MessageId       =IBP_MCE_FB25__IDX_SEG_ERR
Language        =Eng
_MC("segment count of 0 defined for index %1")
.

//------------------------------------------------------------------------
/*305*/
MessageId       =IBP_MCE_FB25__NODE_NAME_ERR
Language        =Eng
_MC("A node name is not permitted in a secondary, shadow, cache or log file name")
.

//------------------------------------------------------------------------
/*306*/
MessageId       =IBP_MCE_FB25__TABLE_NAME
Language        =Eng
_MC("TABLE %1")
.

//------------------------------------------------------------------------
/*307*/
MessageId       =IBP_MCE_FB25__PROC_NAME
Language        =Eng
_MC("PROCEDURE %1")
.

//------------------------------------------------------------------------
/*308*/
MessageId       =IBP_MCE_FB25__IDX_CREATE_ERR
Language        =Eng
_MC("cannot create index %1")
.

//------------------------------------------------------------------------
/*309*/
MessageId       =IBP_MCE_FB25__WAL_SHADOW_ERR
Language        =Eng
_MC("Write-ahead Log with shadowing configuration not allowed")
.

//------------------------------------------------------------------------
/*310*/
MessageId       =IBP_MCE_FB25__DEPENDENCY
Language        =Eng
_MC("there are %1 dependencies")
.

//------------------------------------------------------------------------
/*311*/
MessageId       =IBP_MCE_FB25__IDX_KEY_ERR
Language        =Eng
_MC("too many keys defined for index %1")
.

//------------------------------------------------------------------------
/*312*/
MessageId       =IBP_MCE_FB25__DSQL_FILE_LENGTH_ERR
Language        =Eng
_MC("Preceding file did not specify length, so %1 must include starting page number")
.

//------------------------------------------------------------------------
/*313*/
MessageId       =IBP_MCE_FB25__DSQL_SHADOW_NUMBER_ERR
Language        =Eng
_MC("Shadow number must be a positive integer")
.

//------------------------------------------------------------------------
/*314*/
MessageId       =IBP_MCE_FB25__DSQL_TOKEN_UNK_ERR
Language        =Eng
_MC("Token unknown - line %1, column %2")
.

//------------------------------------------------------------------------
/*315*/
MessageId       =IBP_MCE_FB25__DSQL_NO_RELATION_ALIAS
Language        =Eng
_MC("there is no alias or table named %1 at this scope level")
.

//------------------------------------------------------------------------
/*316*/
MessageId       =IBP_MCE_FB25__INDEXNAME
Language        =Eng
_MC("there is no index %1 for table %2")
.

//------------------------------------------------------------------------
/*317*/
MessageId       =IBP_MCE_FB25__NO_STREAM_PLAN
Language        =Eng
_MC("table %1 is not referenced in plan")
.

//------------------------------------------------------------------------
/*318*/
MessageId       =IBP_MCE_FB25__STREAM_TWICE
Language        =Eng
_MC("table %1 is referenced more than once in plan; use aliases to distinguish")
.

//------------------------------------------------------------------------
/*319*/
MessageId       =IBP_MCE_FB25__STREAM_NOT_FOUND
Language        =Eng
_MC("table %1 is referenced in the plan but not the from list")
.

//------------------------------------------------------------------------
/*320*/
MessageId       =IBP_MCE_FB25__COLLATION_REQUIRES_TEXT
Language        =Eng
_MC("Invalid use of CHARACTER SET or COLLATE")
.

//------------------------------------------------------------------------
/*321*/
MessageId       =IBP_MCE_FB25__DSQL_DOMAIN_NOT_FOUND
Language        =Eng
_MC("Specified domain or source column %1 does not exist")
.

//------------------------------------------------------------------------
/*322*/
MessageId       =IBP_MCE_FB25__INDEX_UNUSED
Language        =Eng
_MC("index %1 cannot be used in the specified plan")
.

//------------------------------------------------------------------------
/*323*/
MessageId       =IBP_MCE_FB25__DSQL_SELF_JOIN
Language        =Eng
_MC("the table %1 is referenced twice; use aliases to differentiate")
.

//------------------------------------------------------------------------
/*324*/
MessageId       =IBP_MCE_FB25__STREAM_BOF
Language        =Eng
_MC("illegal operation when at beginning of stream")
.

//------------------------------------------------------------------------
/*325*/
MessageId       =IBP_MCE_FB25__STREAM_CRACK
Language        =Eng
_MC("the current position is on a crack")
.

//------------------------------------------------------------------------
/*326*/
MessageId       =IBP_MCE_FB25__DB_OR_FILE_EXISTS
Language        =Eng
_MC("database or file exists")
.

//------------------------------------------------------------------------
/*327*/
MessageId       =IBP_MCE_FB25__INVALID_OPERATOR
Language        =Eng
_MC("invalid comparison operator for find operation")
.

//------------------------------------------------------------------------
/*328*/
MessageId       =IBP_MCE_FB25__CONN_LOST
Language        =Eng
_MC("Connection lost to pipe server")
.

//------------------------------------------------------------------------
/*329*/
MessageId       =IBP_MCE_FB25__BAD_CHECKSUM
Language        =Eng
_MC("bad checksum")
.

//------------------------------------------------------------------------
/*330*/
MessageId       =IBP_MCE_FB25__PAGE_TYPE_ERR
Language        =Eng
_MC("wrong page type")
.

//------------------------------------------------------------------------
/*331*/
MessageId       =IBP_MCE_FB25__EXT_READONLY_ERR
Language        =Eng
_MC("Cannot insert because the file is readonly or is on a read only medium.")
.

//------------------------------------------------------------------------
/*332*/
MessageId       =IBP_MCE_FB25__SING_SELECT_ERR
Language        =Eng
_MC("multiple rows in singleton select")
.

//------------------------------------------------------------------------
/*333*/
MessageId       =IBP_MCE_FB25__PSW_ATTACH
Language        =Eng
_MC("cannot attach to password database")
.

//------------------------------------------------------------------------
/*334*/
MessageId       =IBP_MCE_FB25__PSW_START_TRANS
Language        =Eng
_MC("cannot start transaction for password database")
.

//------------------------------------------------------------------------
/*335*/
MessageId       =IBP_MCE_FB25__INVALID_DIRECTION
Language        =Eng
_MC("invalid direction for find operation")
.

//------------------------------------------------------------------------
/*336*/
MessageId       =IBP_MCE_FB25__DSQL_VAR_CONFLICT
Language        =Eng
_MC("variable %1 conflicts with parameter in same procedure")
.

//------------------------------------------------------------------------
/*337*/
MessageId       =IBP_MCE_FB25__DSQL_NO_BLOB_ARRAY
Language        =Eng
_MC("Array/BLOB/DATE data types not allowed in arithmetic")
.

//------------------------------------------------------------------------
/*338*/
MessageId       =IBP_MCE_FB25__DSQL_BASE_TABLE
Language        =Eng
_MC("%1 is not a valid base table of the specified view")
.

//------------------------------------------------------------------------
/*339*/
MessageId       =IBP_MCE_FB25__DUPLICATE_BASE_TABLE
Language        =Eng
_MC("table %1 is referenced twice in view; use an alias to distinguish")
.

//------------------------------------------------------------------------
/*340*/
MessageId       =IBP_MCE_FB25__VIEW_ALIAS
Language        =Eng
_MC("view %1 has more than one base table; use aliases to distinguish")
.

//------------------------------------------------------------------------
/*341*/
MessageId       =IBP_MCE_FB25__INDEX_ROOT_PAGE_FULL
Language        =Eng
_MC("cannot add index, index root page is full.")
.

//------------------------------------------------------------------------
/*342*/
MessageId       =IBP_MCE_FB25__DSQL_BLOB_TYPE_UNKNOWN
Language        =Eng
_MC("BLOB SUB_TYPE %1 is not defined")
.

//------------------------------------------------------------------------
/*343*/
MessageId       =IBP_MCE_FB25__REQ_MAX_CLONES_EXCEEDED
Language        =Eng
_MC("Too many concurrent executions of the same request")
.

//------------------------------------------------------------------------
/*344*/
MessageId       =IBP_MCE_FB25__DSQL_DUPLICATE_SPEC
Language        =Eng
_MC("duplicate specification of %1 - not supported")
.

//------------------------------------------------------------------------
/*345*/
MessageId       =IBP_MCE_FB25__UNIQUE_KEY_VIOLATION
Language        =Eng
_MC("violation of PRIMARY or UNIQUE KEY constraint \"%1\" on table \"%2\"")
.

//------------------------------------------------------------------------
/*346*/
MessageId       =IBP_MCE_FB25__SRVR_VERSION_TOO_OLD
Language        =Eng
_MC("server version too old to support all CREATE DATABASE options")
.

//------------------------------------------------------------------------
/*347*/
MessageId       =IBP_MCE_FB25__DRDB_COMPLETED_WITH_ERRS
Language        =Eng
_MC("drop database completed with errors")
.

//------------------------------------------------------------------------
/*348*/
MessageId       =IBP_MCE_FB25__DSQL_PROCEDURE_USE_ERR
Language        =Eng
_MC("procedure %1 does not return any values")
.

//------------------------------------------------------------------------
/*349*/
MessageId       =IBP_MCE_FB25__DSQL_COUNT_MISMATCH
Language        =Eng
_MC("count of column list and variable list do not match")
.

//------------------------------------------------------------------------
/*350*/
MessageId       =IBP_MCE_FB25__BLOB_IDX_ERR
Language        =Eng
_MC("attempt to index BLOB column in index %1")
.

//------------------------------------------------------------------------
/*351*/
MessageId       =IBP_MCE_FB25__ARRAY_IDX_ERR
Language        =Eng
_MC("attempt to index array column in index %1")
.

//------------------------------------------------------------------------
/*352*/
MessageId       =IBP_MCE_FB25__KEY_FIELD_ERR
Language        =Eng
_MC("too few key columns found for index %1 (incorrect column name?)")
.

//------------------------------------------------------------------------
/*353*/
MessageId       =IBP_MCE_FB25__NO_DELETE
Language        =Eng
_MC("cannot delete")
.

//------------------------------------------------------------------------
/*354*/
MessageId       =IBP_MCE_FB25__DEL_LAST_FIELD
Language        =Eng
_MC("last column in a table cannot be deleted")
.

//------------------------------------------------------------------------
/*355*/
MessageId       =IBP_MCE_FB25__SORT_ERR
Language        =Eng
_MC("sort error")
.

//------------------------------------------------------------------------
/*356*/
MessageId       =IBP_MCE_FB25__SORT_MEM_ERR
Language        =Eng
_MC("sort error: not enough memory")
.

//------------------------------------------------------------------------
/*357*/
MessageId       =IBP_MCE_FB25__VERSION_ERR
Language        =Eng
_MC("too many versions")
.

//------------------------------------------------------------------------
/*358*/
MessageId       =IBP_MCE_FB25__INVAL_KEY_POSN
Language        =Eng
_MC("invalid key position")
.

//------------------------------------------------------------------------
/*359*/
MessageId       =IBP_MCE_FB25__NO_SEGMENTS_ERR
Language        =Eng
_MC("segments not allowed in expression index %1")
.

//------------------------------------------------------------------------
/*360*/
MessageId       =IBP_MCE_FB25__CRRP_DATA_ERR
Language        =Eng
_MC("sort error: corruption in data structure")
.

//------------------------------------------------------------------------
/*361*/
MessageId       =IBP_MCE_FB25__REC_SIZE_ERR
Language        =Eng
_MC("new record size of %1 bytes is too big")
.

//------------------------------------------------------------------------
/*362*/
MessageId       =IBP_MCE_FB25__DSQL_FIELD_REF
Language        =Eng
_MC("Inappropriate self-reference of column")
.

//------------------------------------------------------------------------
/*363*/
MessageId       =IBP_MCE_FB25__REQ_DEPTH_EXCEEDED
Language        =Eng
_MC("request depth exceeded. (Recursive definition?)")
.

//------------------------------------------------------------------------
/*364*/
MessageId       =IBP_MCE_FB25__NO_FIELD_ACCESS
Language        =Eng
_MC("cannot access column %1 in view %2")
.

//------------------------------------------------------------------------
/*365*/
MessageId       =IBP_MCE_FB25__NO_DBKEY
Language        =Eng
_MC("dbkey not available for multi-table views")
.

//------------------------------------------------------------------------
/*366*/
MessageId       =IBP_MCE_FB25__JRN_FORMAT_ERR
Language        =Eng
_MC("journal file wrong format")
.

//------------------------------------------------------------------------
/*367*/
MessageId       =IBP_MCE_FB25__JRN_FILE_FULL
Language        =Eng
_MC("intermediate journal file full")
.

//------------------------------------------------------------------------
/*368*/
MessageId       =IBP_MCE_FB25__DSQL_OPEN_CURSOR_REQUEST
Language        =Eng
_MC("The prepare statement identifies a prepare statement with an open cursor")
.

//------------------------------------------------------------------------
/*369*/
MessageId       =IBP_MCE_FB25__IB_ERROR
Language        =Eng
_MC("Firebird error")
.

//------------------------------------------------------------------------
/*370*/
MessageId       =IBP_MCE_FB25__CACHE_REDEF
Language        =Eng
_MC("Cache redefined")
.

//------------------------------------------------------------------------
/*371*/
MessageId       =IBP_MCE_FB25__CACHE_TOO_SMALL
Language        =Eng
_MC("Insufficient memory to allocate page buffer cache.")
.

//------------------------------------------------------------------------
/*372*/
MessageId       =IBP_MCE_FB25__LOG_REDEF
Language        =Eng
_MC("Log redefined")
.

//------------------------------------------------------------------------
/*373*/
MessageId       =IBP_MCE_FB25__LOG_TOO_SMALL
Language        =Eng
_MC("Log size too small")
.

//------------------------------------------------------------------------
/*374*/
MessageId       =IBP_MCE_FB25__PARTITION_TOO_SMALL
Language        =Eng
_MC("Log partition size too small")
.

//------------------------------------------------------------------------
/*375*/
MessageId       =IBP_MCE_FB25__PARTITION_NOT_SUPP
Language        =Eng
_MC("Partitions not supported in series of log file specification")
.

//------------------------------------------------------------------------
/*376*/
MessageId       =IBP_MCE_FB25__LOG_LENGTH_SPEC
Language        =Eng
_MC("Total length of a partitioned log must be specified")
.

//------------------------------------------------------------------------
/*377*/
MessageId       =IBP_MCE_FB25__PRECISION_ERR
Language        =Eng
_MC("Precision must be from 1 to 18")
.

//------------------------------------------------------------------------
/*378*/
MessageId       =IBP_MCE_FB25__SCALE_NOGT
Language        =Eng
_MC("Scale must be between zero and precision")
.

//------------------------------------------------------------------------
/*379*/
MessageId       =IBP_MCE_FB25__EXPEC_SHORT
Language        =Eng
_MC("Short integer expected")
.

//------------------------------------------------------------------------
/*380*/
MessageId       =IBP_MCE_FB25__EXPEC_LONG
Language        =Eng
_MC("Long integer expected")
.

//------------------------------------------------------------------------
/*381*/
MessageId       =IBP_MCE_FB25__EXPEC_USHORT
Language        =Eng
_MC("Unsigned short integer expected")
.

//------------------------------------------------------------------------
/*382*/
MessageId       =IBP_MCE_FB25__ESCAPE_INVALID
Language        =Eng
_MC("Invalid ESCAPE sequence")
.

//------------------------------------------------------------------------
/*383*/
MessageId       =IBP_MCE_FB25__SVCNOEXE
Language        =Eng
_MC("service %1 does not have an associated executable")
.

//------------------------------------------------------------------------
/*384*/
MessageId       =IBP_MCE_FB25__NET_LOOKUP_ERR
Language        =Eng
_MC("Failed to locate host machine.")
.

//------------------------------------------------------------------------
/*385*/
MessageId       =IBP_MCE_FB25__SERVICE_UNKNOWN
Language        =Eng
_MC("Undefined service %1/%2.")
.

//------------------------------------------------------------------------
/*386*/
MessageId       =IBP_MCE_FB25__HOST_UNKNOWN
Language        =Eng
_MC("The specified name was not found in the hosts file or Domain Name Services.")
.

//------------------------------------------------------------------------
/*387*/
MessageId       =IBP_MCE_FB25__GRANT_NOPRIV_ON_BASE
Language        =Eng
_MC("user does not have GRANT privileges on base table/view for operation")
.

//------------------------------------------------------------------------
/*388*/
MessageId       =IBP_MCE_FB25__DYN_FLD_AMBIGUOUS
Language        =Eng
_MC("Ambiguous column reference.")
.

//------------------------------------------------------------------------
/*389*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_REF_ERR
Language        =Eng
_MC("Invalid aggregate reference")
.

//------------------------------------------------------------------------
/*390*/
MessageId       =IBP_MCE_FB25__COMPLEX_VIEW
Language        =Eng
_MC("navigational stream %1 references a view with more than one base table")
.

//------------------------------------------------------------------------
/*391*/
MessageId       =IBP_MCE_FB25__UNPREPARED_STMT
Language        =Eng
_MC("Attempt to execute an unprepared dynamic SQL statement.")
.

//------------------------------------------------------------------------
/*392*/
MessageId       =IBP_MCE_FB25__EXPEC_POSITIVE
Language        =Eng
_MC("Positive value expected")
.

//------------------------------------------------------------------------
/*393*/
MessageId       =IBP_MCE_FB25__DSQL_SQLDA_VALUE_ERR
Language        =Eng
_MC("Incorrect values within SQLDA structure")
.

//------------------------------------------------------------------------
/*394*/
MessageId       =IBP_MCE_FB25__INVALID_ARRAY_ID
Language        =Eng
_MC("invalid blob id")
.

//------------------------------------------------------------------------
/*395*/
MessageId       =IBP_MCE_FB25__EXTFILE_UNS_OP
Language        =Eng
_MC("Operation not supported for EXTERNAL FILE table %1")
.

//------------------------------------------------------------------------
/*396*/
MessageId       =IBP_MCE_FB25__SVC_IN_USE
Language        =Eng
_MC("Service is currently busy: %1")
.

//------------------------------------------------------------------------
/*397*/
MessageId       =IBP_MCE_FB25__ERR_STACK_LIMIT
Language        =Eng
_MC("stack size insufficent to execute current request")
.

//------------------------------------------------------------------------
/*398*/
MessageId       =IBP_MCE_FB25__INVALID_KEY
Language        =Eng
_MC("Invalid key for find operation")
.

//------------------------------------------------------------------------
/*399*/
MessageId       =IBP_MCE_FB25__NET_INIT_ERROR
Language        =Eng
_MC("Error initializing the network software.")
.

//------------------------------------------------------------------------
/*400*/
MessageId       =IBP_MCE_FB25__LOADLIB_FAILURE
Language        =Eng
_MC("Unable to load required library %1.")
.

//------------------------------------------------------------------------
/*401*/
MessageId       =IBP_MCE_FB25__NETWORK_ERROR
Language        =Eng
_MC("Unable to complete network request to host \"%1\".")
.

//------------------------------------------------------------------------
/*402*/
MessageId       =IBP_MCE_FB25__NET_CONNECT_ERR
Language        =Eng
_MC("Failed to establish a connection.")
.

//------------------------------------------------------------------------
/*403*/
MessageId       =IBP_MCE_FB25__NET_CONNECT_LISTEN_ERR
Language        =Eng
_MC("Error while listening for an incoming connection.")
.

//------------------------------------------------------------------------
/*404*/
MessageId       =IBP_MCE_FB25__NET_EVENT_CONNECT_ERR
Language        =Eng
_MC("Failed to establish a secondary connection for event processing.")
.

//------------------------------------------------------------------------
/*405*/
MessageId       =IBP_MCE_FB25__NET_EVENT_LISTEN_ERR
Language        =Eng
_MC("Error while listening for an incoming event connection request.")
.

//------------------------------------------------------------------------
/*406*/
MessageId       =IBP_MCE_FB25__NET_READ_ERR
Language        =Eng
_MC("Error reading data from the connection.")
.

//------------------------------------------------------------------------
/*407*/
MessageId       =IBP_MCE_FB25__NET_WRITE_ERR
Language        =Eng
_MC("Error writing data to the connection.")
.

//------------------------------------------------------------------------
/*408*/
MessageId       =IBP_MCE_FB25__INTEG_INDEX_DEACTIVATE
Language        =Eng
_MC("Cannot deactivate index used by an integrity constraint")
.

//------------------------------------------------------------------------
/*409*/
MessageId       =IBP_MCE_FB25__INTEG_DEACTIVATE_PRIMARY
Language        =Eng
_MC("Cannot deactivate index used by a PRIMARY/UNIQUE constraint")
.

//------------------------------------------------------------------------
/*410*/
MessageId       =IBP_MCE_FB25__CSE_NOT_SUPPORTED
Language        =Eng
_MC("Client/Server Express not supported in this release")
.

//------------------------------------------------------------------------
/*411*/
MessageId       =IBP_MCE_FB25__TRA_MUST_SWEEP
Language        =Eng
_MC("")
.

//------------------------------------------------------------------------
/*412*/
MessageId       =IBP_MCE_FB25__UNSUPPORTED_NETWORK_DRIVE
Language        =Eng
_MC("Access to databases on file servers is not supported.")
.

//------------------------------------------------------------------------
/*413*/
MessageId       =IBP_MCE_FB25__IO_CREATE_ERR
Language        =Eng
_MC("Error while trying to create file.")
.

//------------------------------------------------------------------------
/*414*/
MessageId       =IBP_MCE_FB25__IO_OPEN_ERR
Language        =Eng
_MC("Error while trying to open file.")
.

//------------------------------------------------------------------------
/*415*/
MessageId       =IBP_MCE_FB25__IO_CLOSE_ERR
Language        =Eng
_MC("Error while trying to close file.")
.

//------------------------------------------------------------------------
/*416*/
MessageId       =IBP_MCE_FB25__IO_READ_ERR
Language        =Eng
_MC("Error while trying to read from file.")
.

//------------------------------------------------------------------------
/*417*/
MessageId       =IBP_MCE_FB25__IO_WRITE_ERR
Language        =Eng
_MC("Error while trying to write to file.")
.

//------------------------------------------------------------------------
/*418*/
MessageId       =IBP_MCE_FB25__IO_DELETE_ERR
Language        =Eng
_MC("Error while trying to delete file.")
.

//------------------------------------------------------------------------
/*419*/
MessageId       =IBP_MCE_FB25__IO_ACCESS_ERR
Language        =Eng
_MC("Error while trying to access file.")
.

//------------------------------------------------------------------------
/*420*/
MessageId       =IBP_MCE_FB25__UDF_EXCEPTION
Language        =Eng
_MC("A fatal exception occurred during the execution of a user defined function.")
.

//------------------------------------------------------------------------
/*421*/
MessageId       =IBP_MCE_FB25__LOST_DB_CONNECTION
Language        =Eng
_MC("connection lost to database")
.

//------------------------------------------------------------------------
/*422*/
MessageId       =IBP_MCE_FB25__NO_WRITE_USER_PRIV
Language        =Eng
_MC("User cannot write to RDB$USER_PRIVILEGES")
.

//------------------------------------------------------------------------
/*423*/
MessageId       =IBP_MCE_FB25__TOKEN_TOO_LONG
Language        =Eng
_MC("token size exceeds limit")
.

//------------------------------------------------------------------------
/*424*/
MessageId       =IBP_MCE_FB25__MAX_ATT_EXCEEDED
Language        =Eng
_MC("Maximum user count exceeded. Contact your database administrator.")
.

//------------------------------------------------------------------------
/*425*/
MessageId       =IBP_MCE_FB25__LOGIN_SAME_AS_ROLE_NAME
Language        =Eng
_MC("Your login %1 is same as one of the SQL role name. Ask your database administrator to set up a valid Firebird login.")
.

//------------------------------------------------------------------------
/*426*/
MessageId       =IBP_MCE_FB25__REFTABLE_REQUIRES_PK
Language        =Eng
_MC("\"REFERENCES table\" without \"(column)\" requires PRIMARY KEY on referenced table")
.

//------------------------------------------------------------------------
/*427*/
MessageId       =IBP_MCE_FB25__USRNAME_TOO_LONG
Language        =Eng
_MC("The username entered is too long. Maximum length is 31 bytes.")
.

//------------------------------------------------------------------------
/*428*/
MessageId       =IBP_MCE_FB25__PASSWORD_TOO_LONG
Language        =Eng
_MC("The password specified is too long. Maximum length is 8 bytes.")
.

//------------------------------------------------------------------------
/*429*/
MessageId       =IBP_MCE_FB25__USRNAME_REQUIRED
Language        =Eng
_MC("A username is required for this operation.")
.

//------------------------------------------------------------------------
/*430*/
MessageId       =IBP_MCE_FB25__PASSWORD_REQUIRED
Language        =Eng
_MC("A password is required for this operation")
.

//------------------------------------------------------------------------
/*431*/
MessageId       =IBP_MCE_FB25__BAD_PROTOCOL
Language        =Eng
_MC("The network protocol specified is invalid")
.

//------------------------------------------------------------------------
/*432*/
MessageId       =IBP_MCE_FB25__DUP_USRNAME_FOUND
Language        =Eng
_MC("A duplicate user name was found in the security database")
.

//------------------------------------------------------------------------
/*433*/
MessageId       =IBP_MCE_FB25__USRNAME_NOT_FOUND
Language        =Eng
_MC("The user name specified was not found in the security database")
.

//------------------------------------------------------------------------
/*434*/
MessageId       =IBP_MCE_FB25__ERROR_ADDING_SEC_RECORD
Language        =Eng
_MC("An error occurred while attempting to add the user.")
.

//------------------------------------------------------------------------
/*435*/
MessageId       =IBP_MCE_FB25__ERROR_MODIFYING_SEC_RECORD
Language        =Eng
_MC("An error occurred while attempting to modify the user record.")
.

//------------------------------------------------------------------------
/*436*/
MessageId       =IBP_MCE_FB25__ERROR_DELETING_SEC_RECORD
Language        =Eng
_MC("An error occurred while attempting to delete the user record.")
.

//------------------------------------------------------------------------
/*437*/
MessageId       =IBP_MCE_FB25__ERROR_UPDATING_SEC_DB
Language        =Eng
_MC("An error occurred while updating the security database.")
.

//------------------------------------------------------------------------
/*438*/
MessageId       =IBP_MCE_FB25__SORT_REC_SIZE_ERR
Language        =Eng
_MC("sort record size of %1 bytes is too big")
.

//------------------------------------------------------------------------
/*439*/
MessageId       =IBP_MCE_FB25__BAD_DEFAULT_VALUE
Language        =Eng
_MC("can not define a not null column with NULL as default value")
.

//------------------------------------------------------------------------
/*440*/
MessageId       =IBP_MCE_FB25__INVALID_CLAUSE
Language        =Eng
_MC("invalid clause --- '%1'")
.

//------------------------------------------------------------------------
/*441*/
MessageId       =IBP_MCE_FB25__TOO_MANY_HANDLES
Language        =Eng
_MC("too many open handles to database")
.

//------------------------------------------------------------------------
/*442*/
MessageId       =IBP_MCE_FB25__OPTIMIZER_BLK_EXC
Language        =Eng
_MC("size of optimizer block exceeded")
.

//------------------------------------------------------------------------
/*443*/
MessageId       =IBP_MCE_FB25__INVALID_STRING_CONSTANT
Language        =Eng
_MC("a string constant is delimited by double quotes")
.

//------------------------------------------------------------------------
/*444*/
MessageId       =IBP_MCE_FB25__TRANSITIONAL_DATE
Language        =Eng
_MC("DATE must be changed to TIMESTAMP")
.

//------------------------------------------------------------------------
/*445*/
MessageId       =IBP_MCE_FB25__READ_ONLY_DATABASE
Language        =Eng
_MC("attempted update on read-only database")
.

//------------------------------------------------------------------------
/*446*/
MessageId       =IBP_MCE_FB25__MUST_BE_DIALECT_2_AND_UP
Language        =Eng
_MC("SQL dialect %1 is not supported in this database")
.

//------------------------------------------------------------------------
/*447*/
MessageId       =IBP_MCE_FB25__BLOB_FILTER_EXCEPTION
Language        =Eng
_MC("A fatal exception occurred during the execution of a blob filter.")
.

//------------------------------------------------------------------------
/*448*/
MessageId       =IBP_MCE_FB25__EXCEPTION_ACCESS_VIOLATION
Language        =Eng
_MC("Access violation. The code attempted to access a virtual address without privilege to do so.")
.

//------------------------------------------------------------------------
/*449*/
MessageId       =IBP_MCE_FB25__EXCEPTION_DATATYPE_MISSALIGNMENT
Language        =Eng
_MC("Datatype misalignment. The attempted to read or write a value that was not stored on a memory boundary.")
.

//------------------------------------------------------------------------
/*450*/
MessageId       =IBP_MCE_FB25__EXCEPTION_ARRAY_BOUNDS_EXCEEDED
Language        =Eng
_MC("Array bounds exceeded. The code attempted to access an array element that is out of bounds.")
.

//------------------------------------------------------------------------
/*451*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_DENORMAL_OPERAND
Language        =Eng
_MC("Float denormal operand. One of the floating-point operands is too small to represent a standard float value.")
.

//------------------------------------------------------------------------
/*452*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_DIVIDE_BY_ZERO
Language        =Eng
_MC("Floating-point divide by zero. The code attempted to divide a floating-point value by zero.")
.

//------------------------------------------------------------------------
/*453*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_INEXACT_RESULT
Language        =Eng
_MC("Floating-point inexact result. The result of a floating-point operation cannot be represented as a decimal fraction.")
.

//------------------------------------------------------------------------
/*454*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_INVALID_OPERAND
Language        =Eng
_MC("Floating-point invalid operand. An indeterminant error occurred during a floating-point operation.")
.

//------------------------------------------------------------------------
/*455*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_OVERFLOW
Language        =Eng
_MC("Floating-point overflow. The exponent of a floating-point operation is greater than the magnitude allowed.")
.

//------------------------------------------------------------------------
/*456*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_STACK_CHECK
Language        =Eng
_MC("Floating-point stack check. The stack overflowed or underflowed as the result of a floating-point operation.")
.

//------------------------------------------------------------------------
/*457*/
MessageId       =IBP_MCE_FB25__EXCEPTION_FLOAT_UNDERFLOW
Language        =Eng
_MC("Floating-point underflow. The exponent of a floating-point operation is less than the magnitude allowed.")
.

//------------------------------------------------------------------------
/*458*/
MessageId       =IBP_MCE_FB25__EXCEPTION_INTEGER_DIVIDE_BY_ZERO
Language        =Eng
_MC("Integer divide by zero. The code attempted to divide an integer value by an integer divisor of zero.")
.

//------------------------------------------------------------------------
/*459*/
MessageId       =IBP_MCE_FB25__EXCEPTION_INTEGER_OVERFLOW
Language        =Eng
_MC("Integer overflow. The result of an integer operation caused the most significant bit of the result to carry.")
.

//------------------------------------------------------------------------
/*460*/
MessageId       =IBP_MCE_FB25__EXCEPTION_UNKNOWN
Language        =Eng
_MC("An exception occurred that does not have a description. Exception number %1.")
.

//------------------------------------------------------------------------
/*461*/
MessageId       =IBP_MCE_FB25__EXCEPTION_STACK_OVERFLOW
Language        =Eng
_MC("Stack overflow. The resource requirements of the runtime stack have exceeded the memory available to it.")
.

//------------------------------------------------------------------------
/*462*/
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGSEGV
Language        =Eng
_MC("Segmentation Fault. The code attempted to access memory without privileges.")
.

//------------------------------------------------------------------------
/*463*/
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGILL
Language        =Eng
_MC("Illegal Instruction. The Code attempted to perform an illegal operation.")
.

//------------------------------------------------------------------------
/*464*/
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGBUS
Language        =Eng
_MC("Bus Error. The Code caused a system bus error.")
.

//------------------------------------------------------------------------
/*465*/
MessageId       =IBP_MCE_FB25__EXCEPTION_SIGFPE
Language        =Eng
_MC("Floating Point Error. The Code caused an Arithmetic Exception or a floating point exception.")
.

//------------------------------------------------------------------------
/*466*/
MessageId       =IBP_MCE_FB25__EXT_FILE_DELETE
Language        =Eng
_MC("Cannot delete rows from external files.")
.

//------------------------------------------------------------------------
/*467*/
MessageId       =IBP_MCE_FB25__EXT_FILE_MODIFY
Language        =Eng
_MC("Cannot update rows in external files.")
.

//------------------------------------------------------------------------
/*468*/
MessageId       =IBP_MCE_FB25__ADM_TASK_DENIED
Language        =Eng
_MC("Unable to perform operation. You must be either SYSDBA or owner of the database")
.

//------------------------------------------------------------------------
/*469*/
MessageId       =IBP_MCE_FB25__EXTRACT_INPUT_MISMATCH
Language        =Eng
_MC("Specified EXTRACT part does not exist in input datatype")
.

//------------------------------------------------------------------------
/*470*/
MessageId       =IBP_MCE_FB25__INSUFFICIENT_SVC_PRIVILEGES
Language        =Eng
_MC("Service %1 requires SYSDBA permissions. Reattach to the Service Manager using the SYSDBA account.")
.

//------------------------------------------------------------------------
/*471*/
MessageId       =IBP_MCE_FB25__FILE_IN_USE
Language        =Eng
_MC("The file %1 is currently in use by another process. Try again later.")
.

//------------------------------------------------------------------------
/*472*/
MessageId       =IBP_MCE_FB25__SERVICE_ATT_ERR
Language        =Eng
_MC("Cannot attach to services manager")
.

//------------------------------------------------------------------------
/*473*/
MessageId       =IBP_MCE_FB25__DDL_NOT_ALLOWED_BY_DB_SQL_DIAL
Language        =Eng
_MC("Metadata update statement is not allowed by the current database SQL dialect %1")
.

//------------------------------------------------------------------------
/*474*/
MessageId       =IBP_MCE_FB25__CANCELLED
Language        =Eng
_MC("Operation was cancelled.")
.

//------------------------------------------------------------------------
/*475*/
MessageId       =IBP_MCE_FB25__UNEXP_SPB_FORM
Language        =Eng
_MC("unexpected item in service parameter block, expected %1")
.

//------------------------------------------------------------------------
/*476*/
MessageId       =IBP_MCE_FB25__SQL_DIALECT_DATATYPE_UNSUPPORT
Language        =Eng
_MC("Client SQL dialect %1 does not support reference to %2 datatype")
.

//------------------------------------------------------------------------
/*477*/
MessageId       =IBP_MCE_FB25__SVCNOUSER
Language        =Eng
_MC("user name and password are required while attaching to the services manager")
.

//------------------------------------------------------------------------
/*478*/
MessageId       =IBP_MCE_FB25__DEPEND_ON_UNCOMMITTED_REL
Language        =Eng
_MC("You created an indirect dependency on uncommitted metadata. You must roll back the current transaction.")
.

//------------------------------------------------------------------------
/*479*/
MessageId       =IBP_MCE_FB25__SVC_NAME_MISSING
Language        =Eng
_MC("The service name was not specified.")
.

//------------------------------------------------------------------------
/*480*/
MessageId       =IBP_MCE_FB25__TOO_MANY_CONTEXTS
Language        =Eng
_MC("Too many Contexts of Relation/Procedure/Views. Maximum allowed is 255")
.

//------------------------------------------------------------------------
/*481*/
MessageId       =IBP_MCE_FB25__DATYPE_NOTSUP
Language        =Eng
_MC("data type not supported for arithmetic")
.

//------------------------------------------------------------------------
/*482*/
MessageId       =IBP_MCE_FB25__DIALECT_RESET_WARNING
Language        =Eng
_MC("Database dialect being changed from 3 to 1")
.

//------------------------------------------------------------------------
/*483*/
MessageId       =IBP_MCE_FB25__DIALECT_NOT_CHANGED
Language        =Eng
_MC("Database dialect not changed.")
.

//------------------------------------------------------------------------
/*484*/
MessageId       =IBP_MCE_FB25__DATABASE_CREATE_FAILED
Language        =Eng
_MC("Unable to create database %1")
.

//------------------------------------------------------------------------
/*485*/
MessageId       =IBP_MCE_FB25__INV_DIALECT_SPECIFIED
Language        =Eng
_MC("Database dialect %1 is not a valid dialect.")
.

//------------------------------------------------------------------------
/*486*/
MessageId       =IBP_MCE_FB25__VALID_DB_DIALECTS
Language        =Eng
_MC("Valid database dialects are %1.")
.

//------------------------------------------------------------------------
/*487*/
MessageId       =IBP_MCE_FB25__SQLWARN
Language        =Eng
_MC("SQL warning code = %1")
.

//------------------------------------------------------------------------
/*488*/
MessageId       =IBP_MCE_FB25__DTYPE_RENAMED
Language        =Eng
_MC("DATE data type is now called TIMESTAMP")
.

//------------------------------------------------------------------------
/*489*/
MessageId       =IBP_MCE_FB25__EXTERN_FUNC_DIR_ERROR
Language        =Eng
_MC("Function %1 is in %2, which is not in a permitted directory for external functions.")
.

//------------------------------------------------------------------------
/*490*/
MessageId       =IBP_MCE_FB25__DATE_RANGE_EXCEEDED
Language        =Eng
_MC("value exceeds the range for valid dates")
.

//------------------------------------------------------------------------
/*491*/
MessageId       =IBP_MCE_FB25__INV_CLIENT_DIALECT_SPECIFIED
Language        =Eng
_MC("passed client dialect %1 is not a valid dialect.")
.

//------------------------------------------------------------------------
/*492*/
MessageId       =IBP_MCE_FB25__VALID_CLIENT_DIALECTS
Language        =Eng
_MC("Valid client dialects are %1.")
.

//------------------------------------------------------------------------
/*493*/
MessageId       =IBP_MCE_FB25__OPTIMIZER_BETWEEN_ERR
Language        =Eng
_MC("Unsupported field type specified in BETWEEN predicate.")
.

//------------------------------------------------------------------------
/*494*/
MessageId       =IBP_MCE_FB25__SERVICE_NOT_SUPPORTED
Language        =Eng
_MC("Services functionality will be supported in a later version  of the product")
.

//------------------------------------------------------------------------
/*495*/
MessageId       =IBP_MCE_FB25__GENERATOR_NAME
Language        =Eng
_MC("GENERATOR %1")
.

//------------------------------------------------------------------------
/*496*/
MessageId       =IBP_MCE_FB25__UDF_NAME
Language        =Eng
_MC("UDF %1")
.

//------------------------------------------------------------------------
/*497*/
MessageId       =IBP_MCE_FB25__BAD_LIMIT_PARAM
Language        =Eng
_MC("Invalid parameter to FIRST. Only integers >= 0 are allowed.")
.

//------------------------------------------------------------------------
/*498*/
MessageId       =IBP_MCE_FB25__BAD_SKIP_PARAM
Language        =Eng
_MC("Invalid parameter to SKIP. Only integers >= 0 are allowed.")
.

//------------------------------------------------------------------------
/*499*/
MessageId       =IBP_MCE_FB25__IO_32BIT_EXCEEDED_ERR
Language        =Eng
_MC("File exceeded maximum size of 2GB. Add another database file or use a 64 bit I/O version of Firebird.")
.

//------------------------------------------------------------------------
/*500*/
MessageId       =IBP_MCE_FB25__INVALID_SAVEPOINT
Language        =Eng
_MC("Unable to find savepoint with name %1 in transaction context")
.

//------------------------------------------------------------------------
/*501*/
MessageId       =IBP_MCE_FB25__DSQL_COLUMN_POS_ERR
Language        =Eng
_MC("Invalid column position used in the %1 clause")
.

//------------------------------------------------------------------------
/*502*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_WHERE_ERR
Language        =Eng
_MC("Cannot use an aggregate function in a WHERE clause, use HAVING instead")
.

//------------------------------------------------------------------------
/*503*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_GROUP_ERR
Language        =Eng
_MC("Cannot use an aggregate function in a GROUP BY clause")
.

//------------------------------------------------------------------------
/*504*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_COLUMN_ERR
Language        =Eng
_MC("Invalid expression in the %1 (not contained in either an aggregate function or the GROUP BY clause)")
.

//------------------------------------------------------------------------
/*505*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_HAVING_ERR
Language        =Eng
_MC("Invalid expression in the %1 (neither an aggregate function nor a part of the GROUP BY clause)")
.

//------------------------------------------------------------------------
/*506*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_NESTED_ERR
Language        =Eng
_MC("Nested aggregate functions are not allowed")
.

//------------------------------------------------------------------------
/*507*/
MessageId       =IBP_MCE_FB25__EXEC_SQL_INVALID_ARG
Language        =Eng
_MC("Invalid argument in EXECUTE STATEMENT - cannot convert to string")
.

//------------------------------------------------------------------------
/*508*/
MessageId       =IBP_MCE_FB25__EXEC_SQL_INVALID_REQ
Language        =Eng
_MC("Wrong request type in EXECUTE STATEMENT '%1'")
.

//------------------------------------------------------------------------
/*509*/
MessageId       =IBP_MCE_FB25__EXEC_SQL_INVALID_VAR
Language        =Eng
_MC("Variable type (position %1) in EXECUTE STATEMENT '%2' INTO does not match returned column type")
.

//------------------------------------------------------------------------
/*510*/
MessageId       =IBP_MCE_FB25__EXEC_SQL_MAX_CALL_EXCEEDED
Language        =Eng
_MC("Too many recursion levels of EXECUTE STATEMENT")
.

//------------------------------------------------------------------------
/*511*/
MessageId       =IBP_MCE_FB25__CONF_ACCESS_DENIED
Language        =Eng
_MC("Use of %1 at location %2 is not allowed by server configuration")
.

//------------------------------------------------------------------------
/*512*/
MessageId       =IBP_MCE_FB25__WRONG_BACKUP_STATE
Language        =Eng
_MC("Cannot change difference file name while database is in backup mode")
.

//------------------------------------------------------------------------
/*513*/
MessageId       =IBP_MCE_FB25__WAL_BACKUP_ERR
Language        =Eng
_MC("Physical backup is not allowed while Write-Ahead Log is in use")
.

//------------------------------------------------------------------------
/*514*/
MessageId       =IBP_MCE_FB25__CURSOR_NOT_OPEN
Language        =Eng
_MC("Cursor is not open")
.

//------------------------------------------------------------------------
/*515*/
MessageId       =IBP_MCE_FB25__BAD_SHUTDOWN_MODE
Language        =Eng
_MC("Target shutdown mode is invalid for database \"%1\"")
.

//------------------------------------------------------------------------
/*516*/
MessageId       =IBP_MCE_FB25__CONCAT_OVERFLOW
Language        =Eng
_MC("Concatenation overflow. Resulting string cannot exceed 32765 bytes in length.")
.

//------------------------------------------------------------------------
/*517*/
MessageId       =IBP_MCE_FB25__BAD_SUBSTRING_OFFSET
Language        =Eng
_MC("Invalid offset parameter %1 to SUBSTRING. Only positive integers are allowed.")
.

//------------------------------------------------------------------------
/*518*/
MessageId       =IBP_MCE_FB25__FOREIGN_KEY_TARGET_DOESNT_EXIST
Language        =Eng
_MC("Foreign key reference target does not exist")
.

//------------------------------------------------------------------------
/*519*/
MessageId       =IBP_MCE_FB25__FOREIGN_KEY_REFERENCES_PRESENT
Language        =Eng
_MC("Foreign key references are present for the record")
.

//------------------------------------------------------------------------
/*520*/
MessageId       =IBP_MCE_FB25__NO_UPDATE
Language        =Eng
_MC("cannot update")
.

//------------------------------------------------------------------------
/*521*/
MessageId       =IBP_MCE_FB25__CURSOR_ALREADY_OPEN
Language        =Eng
_MC("Cursor is already open")
.

//------------------------------------------------------------------------
/*522*/
MessageId       =IBP_MCE_FB25__STACK_TRACE
Language        =Eng
_MC("%1")
.

//------------------------------------------------------------------------
/*523*/
MessageId       =IBP_MCE_FB25__CTX_VAR_NOT_FOUND
Language        =Eng
_MC("Context variable %1 is not found in namespace %2")
.

//------------------------------------------------------------------------
/*524*/
MessageId       =IBP_MCE_FB25__CTX_NAMESPACE_INVALID
Language        =Eng
_MC("Invalid namespace name %1 passed to %2")
.

//------------------------------------------------------------------------
/*525*/
MessageId       =IBP_MCE_FB25__CTX_TOO_BIG
Language        =Eng
_MC("Too many context variables")
.

//------------------------------------------------------------------------
/*526*/
MessageId       =IBP_MCE_FB25__CTX_BAD_ARGUMENT
Language        =Eng
_MC("Invalid argument passed to %1")
.

//------------------------------------------------------------------------
/*527*/
MessageId       =IBP_MCE_FB25__IDENTIFIER_TOO_LONG
Language        =Eng
_MC("BLR syntax error. Identifier %1... is too long")
.

//------------------------------------------------------------------------
/*528*/
MessageId       =IBP_MCE_FB25__EXCEPT2
Language        =Eng
_MC("exception %1")
.

//------------------------------------------------------------------------
/*529*/
MessageId       =IBP_MCE_FB25__MALFORMED_STRING
Language        =Eng
_MC("Malformed string")
.

//------------------------------------------------------------------------
/*530*/
MessageId       =IBP_MCE_FB25__PRC_OUT_PARAM_MISMATCH
Language        =Eng
_MC("Output parameter mismatch for procedure %1")
.

//------------------------------------------------------------------------
/*531*/
MessageId       =IBP_MCE_FB25__COMMAND_END_ERR2
Language        =Eng
_MC("Unexpected end of command - line %1, column %2")
.

//------------------------------------------------------------------------
/*532*/
MessageId       =IBP_MCE_FB25__PARTNER_IDX_INCOMPAT_TYPE
Language        =Eng
_MC("partner index segment no %1 has incompatible data type")
.

//------------------------------------------------------------------------
/*533*/
MessageId       =IBP_MCE_FB25__BAD_SUBSTRING_LENGTH
Language        =Eng
_MC("Invalid length parameter %1 to SUBSTRING. Negative integers are not allowed.")
.

//------------------------------------------------------------------------
/*534*/
MessageId       =IBP_MCE_FB25__CHARSET_NOT_INSTALLED
Language        =Eng
_MC("CHARACTER SET %1 is not installed")
.

//------------------------------------------------------------------------
/*535*/
MessageId       =IBP_MCE_FB25__COLLATION_NOT_INSTALLED
Language        =Eng
_MC("COLLATION %1 for CHARACTER SET %2 is not installed")
.

//------------------------------------------------------------------------
/*536*/
MessageId       =IBP_MCE_FB25__ATT_SHUTDOWN
Language        =Eng
_MC("connection shutdown")
.

//------------------------------------------------------------------------
/*537*/
MessageId       =IBP_MCE_FB25__BLOBTOOBIG
Language        =Eng
_MC("Maximum BLOB size exceeded")
.

//------------------------------------------------------------------------
/*538*/
MessageId       =IBP_MCE_FB25__MUST_HAVE_PHYS_FIELD
Language        =Eng
_MC("Can't have relation with only computed fields or constraints")
.

//------------------------------------------------------------------------
/*539*/
MessageId       =IBP_MCE_FB25__INVALID_TIME_PRECISION
Language        =Eng
_MC("Time precision exceeds allowed range (0-%1)")
.

//------------------------------------------------------------------------
/*540*/
MessageId       =IBP_MCE_FB25__BLOB_CONVERT_ERROR
Language        =Eng
_MC("Unsupported conversion to target type BLOB (subtype %1)")
.

//------------------------------------------------------------------------
/*541*/
MessageId       =IBP_MCE_FB25__ARRAY_CONVERT_ERROR
Language        =Eng
_MC("Unsupported conversion to target type ARRAY")
.

//------------------------------------------------------------------------
/*542*/
MessageId       =IBP_MCE_FB25__RECORD_LOCK_NOT_SUPP
Language        =Eng
_MC("Stream does not support record locking")
.

//------------------------------------------------------------------------
/*543*/
MessageId       =IBP_MCE_FB25__PARTNER_IDX_NOT_FOUND
Language        =Eng
_MC("Cannot create foreign key constraint %1. Partner index does not exist or is inactive.")
.

//------------------------------------------------------------------------
/*544*/
MessageId       =IBP_MCE_FB25__TRA_NUM_EXC
Language        =Eng
_MC("Transactions count exceeded. Perform backup and restore to make database operable again")
.

//------------------------------------------------------------------------
/*545*/
MessageId       =IBP_MCE_FB25__FIELD_DISAPPEARED
Language        =Eng
_MC("Column has been unexpectedly deleted")
.

//------------------------------------------------------------------------
/*546*/
MessageId       =IBP_MCE_FB25__MET_WRONG_GTT_SCOPE
Language        =Eng
_MC("%1 cannot depend on %2")
.

//------------------------------------------------------------------------
/*547*/
MessageId       =IBP_MCE_FB25__SUBTYPE_FOR_INTERNAL_USE
Language        =Eng
_MC("Blob sub_types bigger than 1 (text) are for internal use only")
.

//------------------------------------------------------------------------
/*548*/
MessageId       =IBP_MCE_FB25__ILLEGAL_PRC_TYPE
Language        =Eng
_MC("Procedure %1 is not selectable (it does not contain a SUSPEND statement)")
.

//------------------------------------------------------------------------
/*549*/
MessageId       =IBP_MCE_FB25__INVALID_SORT_DATATYPE
Language        =Eng
_MC("Datatype %1 is not supported for sorting operation")
.

//------------------------------------------------------------------------
/*550*/
MessageId       =IBP_MCE_FB25__COLLATION_NAME
Language        =Eng
_MC("COLLATION %1")
.

//------------------------------------------------------------------------
/*551*/
MessageId       =IBP_MCE_FB25__DOMAIN_NAME
Language        =Eng
_MC("DOMAIN %1")
.

//------------------------------------------------------------------------
/*552*/
MessageId       =IBP_MCE_FB25__DOMNOTDEF
Language        =Eng
_MC("domain %1 is not defined")
.

//------------------------------------------------------------------------
/*553*/
MessageId       =IBP_MCE_FB25__ARRAY_MAX_DIMENSIONS
Language        =Eng
_MC("Array data type can use up to %1 dimensions")
.

//------------------------------------------------------------------------
/*554*/
MessageId       =IBP_MCE_FB25__MAX_DB_PER_TRANS_ALLOWED
Language        =Eng
_MC("A multi database transaction cannot span more than %1 databases")
.

//------------------------------------------------------------------------
/*555*/
MessageId       =IBP_MCE_FB25__BAD_DEBUG_FORMAT
Language        =Eng
_MC("Bad debug info format")
.

//------------------------------------------------------------------------
/*556*/
MessageId       =IBP_MCE_FB25__BAD_PROC_BLR
Language        =Eng
_MC("Error while parsing procedure %1's BLR")
.

//------------------------------------------------------------------------
/*557*/
MessageId       =IBP_MCE_FB25__KEY_TOO_BIG
Language        =Eng
_MC("index key too big")
.

//------------------------------------------------------------------------
/*558*/
MessageId       =IBP_MCE_FB25__CONCURRENT_TRANSACTION
Language        =Eng
_MC("concurrent transaction number is %1")
.

//------------------------------------------------------------------------
/*559*/
MessageId       =IBP_MCE_FB25__NOT_VALID_FOR_VAR
Language        =Eng
_MC("validation error for variable %1, value \"%2\"")
.

//------------------------------------------------------------------------
/*560*/
MessageId       =IBP_MCE_FB25__NOT_VALID_FOR
Language        =Eng
_MC("validation error for %1, value \"%2\"")
.

//------------------------------------------------------------------------
/*561*/
MessageId       =IBP_MCE_FB25__NEED_DIFFERENCE
Language        =Eng
_MC("Difference file name should be set explicitly for database on raw device")
.

//------------------------------------------------------------------------
/*562*/
MessageId       =IBP_MCE_FB25__LONG_LOGIN
Language        =Eng
_MC("Login name too long (%1 characters, maximum allowed %2)")
.

//------------------------------------------------------------------------
/*563*/
MessageId       =IBP_MCE_FB25__FLDNOTDEF2
Language        =Eng
_MC("column %1 is not defined in procedure %2")
.

//------------------------------------------------------------------------
/*564*/
MessageId       =IBP_MCE_FB25__INVALID_SIMILAR_PATTERN
Language        =Eng
_MC("Invalid SIMILAR TO pattern")
.

//------------------------------------------------------------------------
/*565*/
MessageId       =IBP_MCE_FB25__BAD_TEB_FORM
Language        =Eng
_MC("Invalid TEB format")
.

//------------------------------------------------------------------------
/*566*/
MessageId       =IBP_MCE_FB25__TPB_MULTIPLE_TXN_ISOLATION
Language        =Eng
_MC("Found more than one transaction isolation in TPB")
.

//------------------------------------------------------------------------
/*567*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_BEFORE_TABLE
Language        =Eng
_MC("Table reservation lock type %1 requires table name before in TPB")
.

//------------------------------------------------------------------------
/*568*/
MessageId       =IBP_MCE_FB25__TPB_MULTIPLE_SPEC
Language        =Eng
_MC("Found more than one %1 specification in TPB")
.

//------------------------------------------------------------------------
/*569*/
MessageId       =IBP_MCE_FB25__TPB_OPTION_WITHOUT_RC
Language        =Eng
_MC("Option %1 requires READ COMMITTED isolation in TPB")
.

//------------------------------------------------------------------------
/*570*/
MessageId       =IBP_MCE_FB25__TPB_CONFLICTING_OPTIONS
Language        =Eng
_MC("Option %1 is not valid if %2 was used previously in TPB")
.

//------------------------------------------------------------------------
/*571*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_MISSING_TLEN
Language        =Eng
_MC("Table name length missing after table reservation %1 in TPB")
.

//------------------------------------------------------------------------
/*572*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_LONG_TLEN
Language        =Eng
_MC("Table name length %1 is too long after table reservation %2 in TPB")
.

//------------------------------------------------------------------------
/*573*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_MISSING_TNAME
Language        =Eng
_MC("Table name length %1 without table name after table reservation %2 in TPB")
.

//------------------------------------------------------------------------
/*574*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_CORRUP_TLEN
Language        =Eng
_MC("Table name length %1 goes beyond the remaining TPB size after table reservation %2")
.

//------------------------------------------------------------------------
/*575*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_NULL_TLEN
Language        =Eng
_MC("Table name length is zero after table reservation %1 in TPB")
.

//------------------------------------------------------------------------
/*576*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_RELNOTFOUND
Language        =Eng
_MC("Table or view %1 not defined in system tables after table reservation %2 in TPB")
.

//------------------------------------------------------------------------
/*577*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_BASERELNOTFOUND
Language        =Eng
_MC("Base table or view %1 for view %2 not defined in system tables after table reservation %3 in TPB")
.

//------------------------------------------------------------------------
/*578*/
MessageId       =IBP_MCE_FB25__TPB_MISSING_LEN
Language        =Eng
_MC("Option length missing after option %1 in TPB")
.

//------------------------------------------------------------------------
/*579*/
MessageId       =IBP_MCE_FB25__TPB_MISSING_VALUE
Language        =Eng
_MC("Option length %1 without value after option %2 in TPB")
.

//------------------------------------------------------------------------
/*580*/
MessageId       =IBP_MCE_FB25__TPB_CORRUPT_LEN
Language        =Eng
_MC("Option length %1 goes beyond the remaining TPB size after option %2")
.

//------------------------------------------------------------------------
/*581*/
MessageId       =IBP_MCE_FB25__TPB_NULL_LEN
Language        =Eng
_MC("Option length is zero after table reservation %1 in TPB")
.

//------------------------------------------------------------------------
/*582*/
MessageId       =IBP_MCE_FB25__TPB_OVERFLOW_LEN
Language        =Eng
_MC("Option length %1 exceeds the range for option %2 in TPB")
.

//------------------------------------------------------------------------
/*583*/
MessageId       =IBP_MCE_FB25__TPB_INVALID_VALUE
Language        =Eng
_MC("Option value %1 is invalid for the option %2 in TPB")
.

//------------------------------------------------------------------------
/*584*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_STRONGER_WNG
Language        =Eng
_MC("Preserving previous table reservation %1 for table %2, stronger than new %3 in TPB")
.

//------------------------------------------------------------------------
/*585*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_STRONGER
Language        =Eng
_MC("Table reservation %1 for table %2 already specified and is stronger than new %3 in TPB")
.

//------------------------------------------------------------------------
/*586*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_MAX_RECURSION
Language        =Eng
_MC("Table reservation reached maximum recursion of %1 when expanding views in TPB")
.

//------------------------------------------------------------------------
/*587*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_VIRTUALTBL
Language        =Eng
_MC("Table reservation in TPB cannot be applied to %1 because it's a virtual table")
.

//------------------------------------------------------------------------
/*588*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_SYSTBL
Language        =Eng
_MC("Table reservation in TPB cannot be applied to %1 because it's a system table")
.

//------------------------------------------------------------------------
/*589*/
MessageId       =IBP_MCE_FB25__TPB_RESERV_TEMPTBL
Language        =Eng
_MC("Table reservation %1 or %2 in TPB cannot be applied to %3 because it's a temporary table")
.

//------------------------------------------------------------------------
/*590*/
MessageId       =IBP_MCE_FB25__TPB_READTXN_AFTER_WRITELOCK
Language        =Eng
_MC("Cannot set the transaction in read only mode after a table reservation isc_tpb_lock_write in TPB")
.

//------------------------------------------------------------------------
/*591*/
MessageId       =IBP_MCE_FB25__TPB_WRITELOCK_AFTER_READTXN
Language        =Eng
_MC("Cannot take a table reservation isc_tpb_lock_write in TPB because the transaction is in read only mode")
.

//------------------------------------------------------------------------
/*592*/
MessageId       =IBP_MCE_FB25__TIME_RANGE_EXCEEDED
Language        =Eng
_MC("value exceeds the range for a valid time")
.

//------------------------------------------------------------------------
/*593*/
MessageId       =IBP_MCE_FB25__DATETIME_RANGE_EXCEEDED
Language        =Eng
_MC("value exceeds the range for valid timestamps")
.

//------------------------------------------------------------------------
/*594*/
MessageId       =IBP_MCE_FB25__STRING_TRUNCATION
Language        =Eng
_MC("string right truncation")
.

//------------------------------------------------------------------------
/*595*/
MessageId       =IBP_MCE_FB25__BLOB_TRUNCATION
Language        =Eng
_MC("blob truncation when converting to a string: length limit exceeded")
.

//------------------------------------------------------------------------
/*596*/
MessageId       =IBP_MCE_FB25__NUMERIC_OUT_OF_RANGE
Language        =Eng
_MC("numeric value is out of range")
.

//------------------------------------------------------------------------
/*597*/
MessageId       =IBP_MCE_FB25__SHUTDOWN_TIMEOUT
Language        =Eng
_MC("Firebird shutdown is still in progress after the specified timeout")
.

//------------------------------------------------------------------------
/*598*/
MessageId       =IBP_MCE_FB25__ATT_HANDLE_BUSY
Language        =Eng
_MC("Attachment handle is busy")
.

//------------------------------------------------------------------------
/*599*/
MessageId       =IBP_MCE_FB25__BAD_UDF_FREEIT
Language        =Eng
_MC("Bad written UDF detected: pointer returned in FREE_IT function was not allocated by ib_util_malloc")
.

//------------------------------------------------------------------------
/*600*/
MessageId       =IBP_MCE_FB25__EDS_PROVIDER_NOT_FOUND
Language        =Eng
_MC("External Data Source provider '%1' not found")
.

//------------------------------------------------------------------------
/*601*/
MessageId       =IBP_MCE_FB25__EDS_CONNECTION
Language        =Eng
_MC("Execute statement error at %1 :\n"
    "%2Data source : %3")
.

//------------------------------------------------------------------------
/*602*/
MessageId       =IBP_MCE_FB25__EDS_PREPROCESS
Language        =Eng
_MC("Execute statement preprocess SQL error")
.

//------------------------------------------------------------------------
/*603*/
MessageId       =IBP_MCE_FB25__EDS_STMT_EXPECTED
Language        =Eng
_MC("Statement expected")
.

//------------------------------------------------------------------------
/*604*/
MessageId       =IBP_MCE_FB25__EDS_PRM_NAME_EXPECTED
Language        =Eng
_MC("Parameter name expected")
.

//------------------------------------------------------------------------
/*605*/
MessageId       =IBP_MCE_FB25__EDS_UNCLOSED_COMMENT
Language        =Eng
_MC("Unclosed comment found near '%1'")
.

//------------------------------------------------------------------------
/*606*/
MessageId       =IBP_MCE_FB25__EDS_STATEMENT
Language        =Eng
_MC("Execute statement error at %1 :\n"
    "%2Statement : %3\n"
    "Data source : %4")
.

//------------------------------------------------------------------------
/*607*/
MessageId       =IBP_MCE_FB25__EDS_INPUT_PRM_MISMATCH
Language        =Eng
_MC("Input parameters mismatch")
.

//------------------------------------------------------------------------
/*608*/
MessageId       =IBP_MCE_FB25__EDS_OUTPUT_PRM_MISMATCH
Language        =Eng
_MC("Output parameters mismatch")
.

//------------------------------------------------------------------------
/*609*/
MessageId       =IBP_MCE_FB25__EDS_INPUT_PRM_NOT_SET
Language        =Eng
_MC("Input parameter '%1' have no value set")
.

//------------------------------------------------------------------------
/*610*/
MessageId       =IBP_MCE_FB25__TOO_BIG_BLR
Language        =Eng
_MC("BLR stream length %1 exceeds implementation limit %2")
.

//------------------------------------------------------------------------
/*611*/
MessageId       =IBP_MCE_FB25__MONTABEXH
Language        =Eng
_MC("Monitoring table space exhausted")
.

//------------------------------------------------------------------------
/*612*/
MessageId       =IBP_MCE_FB25__MODNOTFOUND
Language        =Eng
_MC("module name or entrypoint could not be found")
.

//------------------------------------------------------------------------
/*613*/
MessageId       =IBP_MCE_FB25__NOTHING_TO_CANCEL
Language        =Eng
_MC("nothing to cancel")
.

//------------------------------------------------------------------------
/*614*/
MessageId       =IBP_MCE_FB25__IBUTIL_NOT_LOADED
Language        =Eng
_MC("ib_util library has not been loaded to deallocate memory returned by FREE_IT function")
.

//------------------------------------------------------------------------
/*615*/
MessageId       =IBP_MCE_FB25__CIRCULAR_COMPUTED
Language        =Eng
_MC("Cannot have circular dependencies with computed fields")
.

//------------------------------------------------------------------------
/*616*/
MessageId       =IBP_MCE_FB25__PSW_DB_ERROR
Language        =Eng
_MC("Security database error")
.

//------------------------------------------------------------------------
/*617*/
MessageId       =IBP_MCE_FB25__INVALID_TYPE_DATETIME_OP
Language        =Eng
_MC("Invalid data type in DATE/TIME/TIMESTAMP addition or subtraction in add_datettime()")
.

//------------------------------------------------------------------------
/*618*/
MessageId       =IBP_MCE_FB25__ONLYCAN_ADD_TIMETODATE
Language        =Eng
_MC("Only a TIME value can be added to a DATE value")
.

//------------------------------------------------------------------------
/*619*/
MessageId       =IBP_MCE_FB25__ONLYCAN_ADD_DATETOTIME
Language        =Eng
_MC("Only a DATE value can be added to a TIME value")
.

//------------------------------------------------------------------------
/*620*/
MessageId       =IBP_MCE_FB25__ONLYCANSUB_TSTAMPFROMTSTAMP
Language        =Eng
_MC("TIMESTAMP values can be subtracted only from another TIMESTAMP value")
.

//------------------------------------------------------------------------
/*621*/
MessageId       =IBP_MCE_FB25__ONLYONEOP_MUSTBE_TSTAMP
Language        =Eng
_MC("Only one operand can be of type TIMESTAMP")
.

//------------------------------------------------------------------------
/*622*/
MessageId       =IBP_MCE_FB25__INVALID_EXTRACTPART_TIME
Language        =Eng
_MC("Only HOUR, MINUTE, SECOND and MILLISECOND can be extracted from TIME values")
.

//------------------------------------------------------------------------
/*623*/
MessageId       =IBP_MCE_FB25__INVALID_EXTRACTPART_DATE
Language        =Eng
_MC("HOUR, MINUTE, SECOND and MILLISECOND cannot be extracted from DATE values")
.

//------------------------------------------------------------------------
/*624*/
MessageId       =IBP_MCE_FB25__INVALIDARG_EXTRACT
Language        =Eng
_MC("Invalid argument for EXTRACT() not being of DATE/TIME/TIMESTAMP type")
.

//------------------------------------------------------------------------
/*625*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_EXACT
Language        =Eng
_MC("Arguments for %1 must be integral types or NUMERIC/DECIMAL without scale")
.

//------------------------------------------------------------------------
/*626*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_EXACT_OR_FP
Language        =Eng
_MC("First argument for %1 must be integral type or floating point type")
.

//------------------------------------------------------------------------
/*627*/
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_UUIDTYPE
Language        =Eng
_MC("Human readable UUID argument for %1 must be of string type")
.

//------------------------------------------------------------------------
/*628*/
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_UUIDLEN
Language        =Eng
_MC("Human readable UUID argument for %2 must be of exact length %1")
.

//------------------------------------------------------------------------
/*629*/
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_UUIDFMT
Language        =Eng
_MC("Human readable UUID argument for %3 must have \"-\" at position %2 instead of \"%1\"")
.

//------------------------------------------------------------------------
/*630*/
MessageId       =IBP_MCE_FB25__SYSF_ARGVIOLATES_GUIDIGITS
Language        =Eng
_MC("Human readable UUID argument for %3 must have hex digit at position %2 instead of \"%1\"")
.

//------------------------------------------------------------------------
/*631*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADDPART_TIME
Language        =Eng
_MC("Only HOUR, MINUTE, SECOND and MILLISECOND can be added to TIME values in %1")
.

//------------------------------------------------------------------------
/*632*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADD_DATETIME
Language        =Eng
_MC("Invalid data type in addition of part to DATE/TIME/TIMESTAMP in %1")
.

//------------------------------------------------------------------------
/*633*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADDPART_DTIME
Language        =Eng
_MC("Invalid part %1 to be added to a DATE/TIME/TIMESTAMP value in %2")
.

//------------------------------------------------------------------------
/*634*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ADD_DTIME_RC
Language        =Eng
_MC("Expected DATE/TIME/TIMESTAMP type in evlDateAdd() result")
.

//------------------------------------------------------------------------
/*635*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_DIFF_DTIME
Language        =Eng
_MC("Expected DATE/TIME/TIMESTAMP type as first and second argument to %1")
.

//------------------------------------------------------------------------
/*636*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_TIMEDIFF
Language        =Eng
_MC("The result of TIME-<value> in %1 cannot be expressed in YEAR, MONTH, DAY or WEEK")
.

//------------------------------------------------------------------------
/*637*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_TSTAMPTIMEDIFF
Language        =Eng
_MC("The result of TIME-TIMESTAMP or TIMESTAMP-TIME in %1 cannot be expressed in HOUR, MINUTE, SECOND or MILLISECOND")
.

//------------------------------------------------------------------------
/*638*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_DATETIMEDIFF
Language        =Eng
_MC("The result of DATE-TIME or TIME-DATE in %1 cannot be expressed in HOUR, MINUTE, SECOND and MILLISECOND")
.

//------------------------------------------------------------------------
/*639*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_DIFFPART
Language        =Eng
_MC("Invalid part %1 to express the difference between two DATE/TIME/TIMESTAMP values in %2")
.

//------------------------------------------------------------------------
/*640*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_POSITIVE
Language        =Eng
_MC("Argument for %1 must be positive")
.

//------------------------------------------------------------------------
/*641*/
MessageId       =IBP_MCE_FB25__SYSF_BASEMUSTBE_POSITIVE
Language        =Eng
_MC("Base for %1 must be positive")
.

//------------------------------------------------------------------------
/*642*/
MessageId       =IBP_MCE_FB25__SYSF_ARGNMUSTBE_NONNEG
Language        =Eng
_MC("Argument #%1 for %2 must be zero or positive")
.

//------------------------------------------------------------------------
/*643*/
MessageId       =IBP_MCE_FB25__SYSF_ARGNMUSTBE_POSITIVE
Language        =Eng
_MC("Argument #%1 for %2 must be positive")
.

//------------------------------------------------------------------------
/*644*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_ZEROPOWNEG
Language        =Eng
_MC("Base for %1 cannot be zero if exponent is negative")
.

//------------------------------------------------------------------------
/*645*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_NEGPOWFP
Language        =Eng
_MC("Base for %1 cannot be negative if exponent is not an integral value")
.

//------------------------------------------------------------------------
/*646*/
MessageId       =IBP_MCE_FB25__SYSF_INVALID_SCALE
Language        =Eng
_MC("The numeric scale must be between -128 and 127 in %1")
.

//------------------------------------------------------------------------
/*647*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_NONNEG
Language        =Eng
_MC("Argument for %1 must be zero or positive")
.

//------------------------------------------------------------------------
/*648*/
MessageId       =IBP_MCE_FB25__SYSF_BINUUID_MUSTBE_STR
Language        =Eng
_MC("Binary UUID argument for %1 must be of string type")
.

//------------------------------------------------------------------------
/*649*/
MessageId       =IBP_MCE_FB25__SYSF_BINUUID_WRONGSIZE
Language        =Eng
_MC("Binary UUID argument for %2 must use %1 bytes")
.

//------------------------------------------------------------------------
/*650*/
MessageId       =IBP_MCE_FB25__MISSING_REQUIRED_SPB
Language        =Eng
_MC("Missing required item %1 in service parameter block")
.

//------------------------------------------------------------------------
/*651*/
MessageId       =IBP_MCE_FB25__NET_SERVER_SHUTDOWN
Language        =Eng
_MC("%1 server is shutdown")
.

//------------------------------------------------------------------------
/*652*/
MessageId       =IBP_MCE_FB25__BAD_CONN_STR
Language        =Eng
_MC("Invalid connection string")
.

//------------------------------------------------------------------------
/*653*/
MessageId       =IBP_MCE_FB25__BAD_EPB_FORM
Language        =Eng
_MC("Unrecognized events block")
.

//------------------------------------------------------------------------
/*654*/
MessageId       =IBP_MCE_FB25__NO_THREADS
Language        =Eng
_MC("Could not start first worker thread - shutdown server")
.

//------------------------------------------------------------------------
/*655*/
MessageId       =IBP_MCE_FB25__NET_EVENT_CONNECT_TIMEOUT
Language        =Eng
_MC("Timeout occurred while waiting for a secondary connection for event processing")
.

//------------------------------------------------------------------------
/*656*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_NONZERO
Language        =Eng
_MC("Argument for %1 must be different than zero")
.

//------------------------------------------------------------------------
/*657*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_RANGE_INC1_1
Language        =Eng
_MC("Argument for %1 must be in the range [-1, 1]")
.

//------------------------------------------------------------------------
/*658*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_GTEQ_ONE
Language        =Eng
_MC("Argument for %1 must be greater or equal than one")
.

//------------------------------------------------------------------------
/*659*/
MessageId       =IBP_MCE_FB25__SYSF_ARGMUSTBE_RANGE_EXC1_1
Language        =Eng
_MC("Argument for %1 must be in the range ]-1, 1[")
.

//------------------------------------------------------------------------
/*660*/
MessageId       =IBP_MCE_FB25__INTERNAL_REJECTED_PARAMS
Language        =Eng
_MC("Incorrect parameters provided to internal function %1")
.

//------------------------------------------------------------------------
/*661*/
MessageId       =IBP_MCE_FB25__SYSF_FP_OVERFLOW
Language        =Eng
_MC("Floating point overflow in built-in function %1")
.

//------------------------------------------------------------------------
/*662*/
MessageId       =IBP_MCE_FB25__UDF_FP_OVERFLOW
Language        =Eng
_MC("Floating point overflow in result from UDF %1")
.

//------------------------------------------------------------------------
/*663*/
MessageId       =IBP_MCE_FB25__UDF_FP_NAN
Language        =Eng
_MC("Invalid floating point value returned by UDF %1")
.

//------------------------------------------------------------------------
/*664*/
MessageId       =IBP_MCE_FB25__INSTANCE_CONFLICT
Language        =Eng
_MC("Database is probably already opened by another engine instance in another Windows session")
.

//------------------------------------------------------------------------
/*665*/
MessageId       =IBP_MCE_FB25__OUT_OF_TEMP_SPACE
Language        =Eng
_MC("No free space found in temporary directories")
.

//------------------------------------------------------------------------
/*666*/
MessageId       =IBP_MCE_FB25__EDS_EXPL_TRAN_CTRL
Language        =Eng
_MC("Explicit transaction control is not allowed")
.

//------------------------------------------------------------------------
/*667*/
MessageId       =IBP_MCE_FB25__NO_TRUSTED_SPB
Language        =Eng
_MC("Use of TRUSTED switches in spb_command_line is prohibited")
.

//------------------------------------------------------------------------
/*668*/
MessageId       =IBP_MCE_FB25__ASYNC_ACTIVE
Language        =Eng
_MC("Asynchronous call is already running for this attachment")
.

//------------------------------------------------------------------------
/*669*/
MessageId       =IBP_MCE_FB25__DSQL_DBKEY_FROM_NON_TABLE
Language        =Eng
_MC("Cannot SELECT RDB$DB_KEY from a stored procedure.")
.

//------------------------------------------------------------------------
/*670*/
MessageId       =IBP_MCE_FB25__DSQL_TRANSITIONAL_NUMERIC
Language        =Eng
_MC("Precision 10 to 18 changed from DOUBLE PRECISION in SQL dialect 1 to 64-bit scaled integer in SQL dialect 3")
.

//------------------------------------------------------------------------
/*671*/
MessageId       =IBP_MCE_FB25__DSQL_DIALECT_WARNING_EXPR
Language        =Eng
_MC("Use of %1 expression that returns different results in dialect 1 and dialect 3")
.

//------------------------------------------------------------------------
/*672*/
MessageId       =IBP_MCE_FB25__SQL_DB_DIALECT_DTYPE_UNSUPPORT
Language        =Eng
_MC("Database SQL dialect %1 does not support reference to %2 datatype")
.

//------------------------------------------------------------------------
/*673*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336003078
Language        =Eng
_MC("")
.

//------------------------------------------------------------------------
/*674*/
MessageId       =IBP_MCE_FB25__SQL_DIALECT_CONFLICT_NUM
Language        =Eng
_MC("DB dialect %1 and client dialect %2 conflict with respect to numeric precision %3.")
.

//------------------------------------------------------------------------
/*675*/
MessageId       =IBP_MCE_FB25__DSQL_WARNING_NUMBER_AMBIGUOUS
Language        =Eng
_MC("WARNING: Numeric literal %1 is interpreted as a floating-point")
.

//------------------------------------------------------------------------
/*676*/
MessageId       =IBP_MCE_FB25__DSQL_WARNING_NUMBER_AMBIGUOUS1
Language        =Eng
_MC("value in SQL dialect 1, but as an exact numeric value in SQL dialect 3.")
.

//------------------------------------------------------------------------
/*677*/
MessageId       =IBP_MCE_FB25__DSQL_WARN_PRECISION_AMBIGUOUS
Language        =Eng
_MC("WARNING: NUMERIC and DECIMAL fields with precision 10 or greater are stored")
.

//------------------------------------------------------------------------
/*678*/
MessageId       =IBP_MCE_FB25__DSQL_WARN_PRECISION_AMBIGUOUS1
Language        =Eng
_MC("as approximate floating-point values in SQL dialect 1, but as 64-bit")
.

//------------------------------------------------------------------------
/*679*/
MessageId       =IBP_MCE_FB25__DSQL_WARN_PRECISION_AMBIGUOUS2
Language        =Eng
_MC("integers in SQL dialect 3.")
.

//------------------------------------------------------------------------
/*680*/
MessageId       =IBP_MCE_FB25__DSQL_AMBIGUOUS_FIELD_NAME
Language        =Eng
_MC("Ambiguous field name between %1 and %2")
.

//------------------------------------------------------------------------
/*681*/
MessageId       =IBP_MCE_FB25__DSQL_UDF_RETURN_POS_ERR
Language        =Eng
_MC("External function should have return position between 1 and %1")
.

//------------------------------------------------------------------------
/*682*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_LABEL
Language        =Eng
_MC("Label %1 %2 in the current scope")
.

//------------------------------------------------------------------------
/*683*/
MessageId       =IBP_MCE_FB25__DSQL_DATATYPES_NOT_COMPARABLE
Language        =Eng
_MC("Datatypes %1are not comparable in expression %2")
.

//------------------------------------------------------------------------
/*684*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_INVALID
Language        =Eng
_MC("Empty cursor name is not allowed")
.

//------------------------------------------------------------------------
/*685*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_REDEFINED
Language        =Eng
_MC("Statement already has a cursor %1 assigned")
.

//------------------------------------------------------------------------
/*686*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_NOT_FOUND
Language        =Eng
_MC("Cursor %1 is not found in the current context")
.

//------------------------------------------------------------------------
/*687*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_EXISTS
Language        =Eng
_MC("Cursor %1 already exists in the current context")
.

//------------------------------------------------------------------------
/*688*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_REL_AMBIGUOUS
Language        =Eng
_MC("Relation %1 is ambiguous in cursor %2")
.

//------------------------------------------------------------------------
/*689*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_REL_NOT_FOUND
Language        =Eng
_MC("Relation %1 is not found in cursor %2")
.

//------------------------------------------------------------------------
/*690*/
MessageId       =IBP_MCE_FB25__DSQL_CURSOR_NOT_OPEN
Language        =Eng
_MC("Cursor is not open")
.

//------------------------------------------------------------------------
/*691*/
MessageId       =IBP_MCE_FB25__DSQL_TYPE_NOT_SUPP_EXT_TAB
Language        =Eng
_MC("Data type %1 is not supported for EXTERNAL TABLES. Relation '%2', field '%3'")
.

//------------------------------------------------------------------------
/*692*/
MessageId       =IBP_MCE_FB25__DSQL_FEATURE_NOT_SUPPORTED_ODS
Language        =Eng
_MC("Feature not supported on ODS version older than %1.%2")
.

//------------------------------------------------------------------------
/*693*/
MessageId       =IBP_MCE_FB25__PRIMARY_KEY_REQUIRED
Language        =Eng
_MC("Primary key required on table %1")
.

//------------------------------------------------------------------------
/*694*/
MessageId       =IBP_MCE_FB25__UPD_INS_DOESNT_MATCH_PK
Language        =Eng
_MC("UPDATE OR INSERT field list does not match primary key of table %1")
.

//------------------------------------------------------------------------
/*695*/
MessageId       =IBP_MCE_FB25__UPD_INS_DOESNT_MATCH_MATCHING
Language        =Eng
_MC("UPDATE OR INSERT field list does not match MATCHING clause")
.

//------------------------------------------------------------------------
/*696*/
MessageId       =IBP_MCE_FB25__UPD_INS_WITH_COMPLEX_VIEW
Language        =Eng
_MC("UPDATE OR INSERT without MATCHING could not be used with views based on more than one table")
.

//------------------------------------------------------------------------
/*697*/
MessageId       =IBP_MCE_FB25__DSQL_INCOMPATIBLE_TRIGGER_TYPE
Language        =Eng
_MC("Incompatible trigger type")
.

//------------------------------------------------------------------------
/*698*/
MessageId       =IBP_MCE_FB25__DSQL_DB_TRIGGER_TYPE_CANT_CHANGE
Language        =Eng
_MC("Database trigger type can't be changed")
.

//------------------------------------------------------------------------
/*699*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068609
Language        =Eng
_MC("ODS version not supported by DYN")
.

//------------------------------------------------------------------------
/*700*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068610
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*701*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068611
Language        =Eng
_MC("STORE RDB$FIELD_DIMENSIONS failed")
.

//------------------------------------------------------------------------
/*702*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068612
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*703*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068613
Language        =Eng
_MC("%1")
.

//------------------------------------------------------------------------
/*704*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068614
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*705*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068615
Language        =Eng
_MC("DEFINE BLOB FILTER failed")
.

//------------------------------------------------------------------------
/*706*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068616
Language        =Eng
_MC("DEFINE GENERATOR failed")
.

//------------------------------------------------------------------------
/*707*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068617
Language        =Eng
_MC("DEFINE GENERATOR unexpected DYN verb")
.

//------------------------------------------------------------------------
/*708*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068618
Language        =Eng
_MC("DEFINE FUNCTION failed")
.

//------------------------------------------------------------------------
/*709*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068619
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*710*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068620
Language        =Eng
_MC("DEFINE FUNCTION ARGUMENT failed")
.

//------------------------------------------------------------------------
/*711*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068621
Language        =Eng
_MC("STORE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*712*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068622
Language        =Eng
_MC("No table specified for index")
.

//------------------------------------------------------------------------
/*713*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068623
Language        =Eng
_MC("STORE RDB$INDEX_SEGMENTS failed")
.

//------------------------------------------------------------------------
/*714*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068624
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*715*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068625
Language        =Eng
_MC("PRIMARY KEY column lookup failed")
.

//------------------------------------------------------------------------
/*716*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068626
Language        =Eng
_MC("could not find UNIQUE or PRIMARY KEY constraint in table %1 with specified columns")
.

//------------------------------------------------------------------------
/*717*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068627
Language        =Eng
_MC("PRIMARY KEY lookup failed")
.

//------------------------------------------------------------------------
/*718*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068628
Language        =Eng
_MC("could not find PRIMARY KEY index in specified table %1")
.

//------------------------------------------------------------------------
/*719*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068629
Language        =Eng
_MC("STORE RDB$INDICES failed")
.

//------------------------------------------------------------------------
/*720*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068630
Language        =Eng
_MC("STORE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*721*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068631
Language        =Eng
_MC("STORE RDB$RELATION_FIELDS failed")
.

//------------------------------------------------------------------------
/*722*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068632
Language        =Eng
_MC("STORE RDB$RELATIONS failed")
.

//------------------------------------------------------------------------
/*723*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068633
Language        =Eng
_MC("STORE RDB$USER_PRIVILEGES failed defining a table")
.

//------------------------------------------------------------------------
/*724*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068634
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*725*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068635
Language        =Eng
_MC("STORE RDB$RELATIONS failed")
.

//------------------------------------------------------------------------
/*726*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068636
Language        =Eng
_MC("STORE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*727*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068637
Language        =Eng
_MC("STORE RDB$RELATION_FIELDS failed")
.

//------------------------------------------------------------------------
/*728*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068638
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*729*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068639
Language        =Eng
_MC("DEFINE TRIGGER failed")
.

//------------------------------------------------------------------------
/*730*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068640
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*731*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068641
Language        =Eng
_MC("DEFINE TRIGGER MESSAGE failed")
.

//------------------------------------------------------------------------
/*732*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068642
Language        =Eng
_MC("STORE RDB$VIEW_RELATIONS failed")
.

//------------------------------------------------------------------------
/*733*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068643
Language        =Eng
_MC("ERASE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*734*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068644
Language        =Eng
_MC("ERASE BLOB FILTER failed")
.

//------------------------------------------------------------------------
/*735*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068645
Language        =Eng
_MC("BLOB Filter %1 not found")
.

//------------------------------------------------------------------------
/*736*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068646
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*737*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068647
Language        =Eng
_MC("ERASE RDB$FUNCTION_ARGUMENTS failed")
.

//------------------------------------------------------------------------
/*738*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068648
Language        =Eng
_MC("ERASE RDB$FUNCTIONS failed")
.

//------------------------------------------------------------------------
/*739*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068649
Language        =Eng
_MC("Function %1 not found")
.

//------------------------------------------------------------------------
/*740*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068650
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*741*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068651
Language        =Eng
_MC("Domain %1 is used in table %2 (local name %3) and cannot be dropped")
.

//------------------------------------------------------------------------
/*742*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068652
Language        =Eng
_MC("ERASE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*743*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068653
Language        =Eng
_MC("ERASE RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*744*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068654
Language        =Eng
_MC("Column not found")
.

//------------------------------------------------------------------------
/*745*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068655
Language        =Eng
_MC("ERASE RDB$INDICES failed")
.

//------------------------------------------------------------------------
/*746*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068656
Language        =Eng
_MC("Index not found")
.

//------------------------------------------------------------------------
/*747*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068657
Language        =Eng
_MC("ERASE RDB$INDEX_SEGMENTS failed")
.

//------------------------------------------------------------------------
/*748*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068658
Language        =Eng
_MC("No segments found for index")
.

//------------------------------------------------------------------------
/*749*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068659
Language        =Eng
_MC("No table specified in ERASE RFR")
.

//------------------------------------------------------------------------
/*750*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068660
Language        =Eng
_MC("Column %1 from table %2 is referenced in view %3")
.

//------------------------------------------------------------------------
/*751*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068661
Language        =Eng
_MC("ERASE RDB$RELATION_FIELDS failed")
.

//------------------------------------------------------------------------
/*752*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068662
Language        =Eng
_MC("View %1 not found")
.

//------------------------------------------------------------------------
/*753*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068663
Language        =Eng
_MC("Column not found for table")
.

//------------------------------------------------------------------------
/*754*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068664
Language        =Eng
_MC("ERASE RDB$INDEX_SEGMENTS failed")
.

//------------------------------------------------------------------------
/*755*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068665
Language        =Eng
_MC("ERASE RDB$INDICES failed")
.

//------------------------------------------------------------------------
/*756*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068666
Language        =Eng
_MC("ERASE RDB$RELATION_FIELDS failed")
.

//------------------------------------------------------------------------
/*757*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068667
Language        =Eng
_MC("ERASE RDB$VIEW_RELATIONS failed")
.

//------------------------------------------------------------------------
/*758*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068668
Language        =Eng
_MC("ERASE RDB$RELATIONS failed")
.

//------------------------------------------------------------------------
/*759*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068669
Language        =Eng
_MC("Table not found")
.

//------------------------------------------------------------------------
/*760*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068670
Language        =Eng
_MC("ERASE RDB$USER_PRIVILEGES failed")
.

//------------------------------------------------------------------------
/*761*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068671
Language        =Eng
_MC("ERASE RDB$FILES failed")
.

//------------------------------------------------------------------------
/*762*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068672
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*763*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068673
Language        =Eng
_MC("ERASE RDB$TRIGGER_MESSAGES failed")
.

//------------------------------------------------------------------------
/*764*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068674
Language        =Eng
_MC("ERASE RDB$TRIGGERS failed")
.

//------------------------------------------------------------------------
/*765*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068675
Language        =Eng
_MC("Trigger not found")
.

//------------------------------------------------------------------------
/*766*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068676
Language        =Eng
_MC("MODIFY RDB$VIEW_RELATIONS failed")
.

//------------------------------------------------------------------------
/*767*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068677
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*768*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068678
Language        =Eng
_MC("TRIGGER NAME expected")
.

//------------------------------------------------------------------------
/*769*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068679
Language        =Eng
_MC("ERASE TRIGGER MESSAGE failed")
.

//------------------------------------------------------------------------
/*770*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068680
Language        =Eng
_MC("Trigger Message not found")
.

//------------------------------------------------------------------------
/*771*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068681
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*772*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068682
Language        =Eng
_MC("ERASE RDB$SECURITY_CLASSES failed")
.

//------------------------------------------------------------------------
/*773*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068683
Language        =Eng
_MC("Security class not found")
.

//------------------------------------------------------------------------
/*774*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068684
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*775*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068685
Language        =Eng
_MC("SELECT RDB$USER_PRIVILEGES failed in grant")
.

//------------------------------------------------------------------------
/*776*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068686
Language        =Eng
_MC("SELECT RDB$USER_PRIVILEGES failed in grant")
.

//------------------------------------------------------------------------
/*777*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068687
Language        =Eng
_MC("STORE RDB$USER_PRIVILEGES failed in grant")
.

//------------------------------------------------------------------------
/*778*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068688
Language        =Eng
_MC("Specified domain or source column does not exist")
.

//------------------------------------------------------------------------
/*779*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068689
Language        =Eng
_MC("Generation of column name failed")
.

//------------------------------------------------------------------------
/*780*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068690
Language        =Eng
_MC("Generation of index name failed")
.

//------------------------------------------------------------------------
/*781*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068691
Language        =Eng
_MC("Generation of trigger name failed")
.

//------------------------------------------------------------------------
/*782*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068692
Language        =Eng
_MC("MODIFY DATABASE failed")
.

//------------------------------------------------------------------------
/*783*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068693
Language        =Eng
_MC("MODIFY RDB$CHARACTER_SETS failed")
.

//------------------------------------------------------------------------
/*784*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068694
Language        =Eng
_MC("MODIFY RDB$COLLATIONS failed")
.

//------------------------------------------------------------------------
/*785*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068695
Language        =Eng
_MC("MODIFY RDB$FIELDS failed")
.

//------------------------------------------------------------------------
/*786*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068696
Language        =Eng
_MC("MODIFY RDB$BLOB_FILTERS failed")
.

//------------------------------------------------------------------------
/*787*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068697
Language        =Eng
_MC("Domain not found")
.

//------------------------------------------------------------------------
/*788*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068698
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*789*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068699
Language        =Eng
_MC("MODIFY RDB$INDICES failed")
.

//------------------------------------------------------------------------
/*790*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068700
Language        =Eng
_MC("MODIFY RDB$FUNCTIONS failed")
.

//------------------------------------------------------------------------
/*791*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068701
Language        =Eng
_MC("Index column not found")
.

//------------------------------------------------------------------------
/*792*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068702
Language        =Eng
_MC("MODIFY RDB$GENERATORS failed")
.

//------------------------------------------------------------------------
/*793*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068703
Language        =Eng
_MC("MODIFY RDB$RELATION_FIELDS failed")
.

//------------------------------------------------------------------------
/*794*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068704
Language        =Eng
_MC("Local column %1 not found")
.

//------------------------------------------------------------------------
/*795*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068705
Language        =Eng
_MC("add EXTERNAL FILE not allowed")
.

//------------------------------------------------------------------------
/*796*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068706
Language        =Eng
_MC("drop EXTERNAL FILE not allowed")
.

//------------------------------------------------------------------------
/*797*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068707
Language        =Eng
_MC("MODIFY RDB$RELATIONS failed")
.

//------------------------------------------------------------------------
/*798*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068708
Language        =Eng
_MC("MODIFY RDB$PROCEDURE_PARAMETERS failed")
.

//------------------------------------------------------------------------
/*799*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068709
Language        =Eng
_MC("Table column not found")
.

//------------------------------------------------------------------------
/*800*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068710
Language        =Eng
_MC("MODIFY TRIGGER failed")
.

//------------------------------------------------------------------------
/*801*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068711
Language        =Eng
_MC("TRIGGER NAME expected")
.

//------------------------------------------------------------------------
/*802*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068712
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*803*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068713
Language        =Eng
_MC("MODIFY TRIGGER MESSAGE failed")
.

//------------------------------------------------------------------------
/*804*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068714
Language        =Eng
_MC("Create metadata BLOB failed")
.

//------------------------------------------------------------------------
/*805*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068715
Language        =Eng
_MC("Write metadata BLOB failed")
.

//------------------------------------------------------------------------
/*806*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068716
Language        =Eng
_MC("Close metadata BLOB failed")
.

//------------------------------------------------------------------------
/*807*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068717
Language        =Eng
_MC("Triggers created automatically cannot be modified")
.

//------------------------------------------------------------------------
/*808*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068718
Language        =Eng
_MC("unsupported DYN verb")
.

//------------------------------------------------------------------------
/*809*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068719
Language        =Eng
_MC("ERASE RDB$USER_PRIVILEGES failed in revoke(1)")
.

//------------------------------------------------------------------------
/*810*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068720
Language        =Eng
_MC("Access to RDB$USER_PRIVILEGES failed in revoke(2)")
.

//------------------------------------------------------------------------
/*811*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068721
Language        =Eng
_MC("ERASE RDB$USER_PRIVILEGES failed in revoke (3)")
.

//------------------------------------------------------------------------
/*812*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068722
Language        =Eng
_MC("Access to RDB$USER_PRIVILEGES failed in revoke (4)")
.

//------------------------------------------------------------------------
/*813*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068723
Language        =Eng
_MC("CREATE VIEW failed")
.

//------------------------------------------------------------------------
/*814*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068724
Language        =Eng
_MC("attempt to index BLOB column in INDEX %1")
.

//------------------------------------------------------------------------
/*815*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068725
Language        =Eng
_MC("attempt to index array column in index %1")
.

//------------------------------------------------------------------------
/*816*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068726
Language        =Eng
_MC("key size too big for index %1")
.

//------------------------------------------------------------------------
/*817*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068727
Language        =Eng
_MC("no keys for index %1")
.

//------------------------------------------------------------------------
/*818*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068728
Language        =Eng
_MC("Unknown columns in index %1")
.

//------------------------------------------------------------------------
/*819*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068729
Language        =Eng
_MC("STORE RDB$RELATION_CONSTRAINTS failed")
.

//------------------------------------------------------------------------
/*820*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068730
Language        =Eng
_MC("STORE RDB$CHECK_CONSTRAINTS failed")
.

//------------------------------------------------------------------------
/*821*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068731
Language        =Eng
_MC("Column: %1 not defined as NOT NULL - cannot be used in PRIMARY KEY constraint definition")
.

//------------------------------------------------------------------------
/*822*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068732
Language        =Eng
_MC("A column name is repeated in the definition of constraint: %1")
.

//------------------------------------------------------------------------
/*823*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068733
Language        =Eng
_MC("Integrity Constraint lookup failed")
.

//------------------------------------------------------------------------
/*824*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068734
Language        =Eng
_MC("Same set of columns cannot be used in more than one PRIMARY KEY and/or UNIQUE constraint definition")
.

//------------------------------------------------------------------------
/*825*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068735
Language        =Eng
_MC("STORE RDB$REF_CONSTRAINTS failed")
.

//------------------------------------------------------------------------
/*826*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068736
Language        =Eng
_MC("No table specified in delete_constraint")
.

//------------------------------------------------------------------------
/*827*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068737
Language        =Eng
_MC("ERASE RDB$RELATION_CONSTRAINTS failed")
.

//------------------------------------------------------------------------
/*828*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068738
Language        =Eng
_MC("CONSTRAINT %1 does not exist.")
.

//------------------------------------------------------------------------
/*829*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068739
Language        =Eng
_MC("Generation of constraint name failed")
.

//------------------------------------------------------------------------
/*830*/
MessageId       =IBP_MCE_FB25__DYN_DUP_TABLE
Language        =Eng
_MC("Table %1 already exists")
.

//------------------------------------------------------------------------
/*831*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068741
Language        =Eng
_MC("Number of referencing columns do not equal number of referenced columns")
.

//------------------------------------------------------------------------
/*832*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068742
Language        =Eng
_MC("STORE RDB$PROCEDURES failed")
.

//------------------------------------------------------------------------
/*833*/
MessageId       =IBP_MCE_FB25__DYN_DUP_PROCEDURE
Language        =Eng
_MC("Procedure %1 already exists")
.

//------------------------------------------------------------------------
/*834*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068744
Language        =Eng
_MC("STORE RDB$PROCEDURE_PARAMETERS failed")
.

//------------------------------------------------------------------------
/*835*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068745
Language        =Eng
_MC("Store into system table %1 failed")
.

//------------------------------------------------------------------------
/*836*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068746
Language        =Eng
_MC("ERASE RDB$PROCEDURE_PARAMETERS failed")
.

//------------------------------------------------------------------------
/*837*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068747
Language        =Eng
_MC("ERASE RDB$PROCEDURES failed")
.

//------------------------------------------------------------------------
/*838*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068748
Language        =Eng
_MC("Procedure %1 not found")
.

//------------------------------------------------------------------------
/*839*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068749
Language        =Eng
_MC("MODIFY RDB$PROCEDURES failed")
.

//------------------------------------------------------------------------
/*840*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068750
Language        =Eng
_MC("DEFINE EXCEPTION failed")
.

//------------------------------------------------------------------------
/*841*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068751
Language        =Eng
_MC("ERASE EXCEPTION failed")
.

//------------------------------------------------------------------------
/*842*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068752
Language        =Eng
_MC("Exception not found")
.

//------------------------------------------------------------------------
/*843*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068753
Language        =Eng
_MC("MODIFY EXCEPTION failed")
.

//------------------------------------------------------------------------
/*844*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068754
Language        =Eng
_MC("Parameter %1 in procedure %2 not found")
.

//------------------------------------------------------------------------
/*845*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068755
Language        =Eng
_MC("Trigger %1 not found")
.

//------------------------------------------------------------------------
/*846*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068756
Language        =Eng
_MC("Only one data type change to the domain %1 allowed at a time")
.

//------------------------------------------------------------------------
/*847*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068757
Language        =Eng
_MC("Only one data type change to the field %1 allowed at a time")
.

//------------------------------------------------------------------------
/*848*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068758
Language        =Eng
_MC("STORE RDB$FILES failed")
.

//------------------------------------------------------------------------
/*849*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068759
Language        =Eng
_MC("Character set %1 not found")
.

//------------------------------------------------------------------------
/*850*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068760
Language        =Eng
_MC("Collation %1 not found")
.

//------------------------------------------------------------------------
/*851*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068761
Language        =Eng
_MC("ERASE RDB$LOG_FILES failed")
.

//------------------------------------------------------------------------
/*852*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068762
Language        =Eng
_MC("STORE RDB$LOG_FILES failed")
.

//------------------------------------------------------------------------
/*853*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068763
Language        =Eng
_MC("Role %1 not found")
.

//------------------------------------------------------------------------
/*854*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068764
Language        =Eng
_MC("Difference file lookup failed")
.

//------------------------------------------------------------------------
/*855*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068765
Language        =Eng
_MC("DEFINE SHADOW failed")
.

//------------------------------------------------------------------------
/*856*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068766
Language        =Eng
_MC("MODIFY RDB$ROLES failed")
.

//------------------------------------------------------------------------
/*857*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068767
Language        =Eng
_MC("Name longer than database column size")
.

//------------------------------------------------------------------------
/*858*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068768
Language        =Eng
_MC("\"Only one constraint allowed for a domain\"")
.

//------------------------------------------------------------------------
/*859*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068770
Language        =Eng
_MC("Looking up column position failed")
.

//------------------------------------------------------------------------
/*860*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068771
Language        =Eng
_MC("A node name is not permitted in a table with external file definition")
.

//------------------------------------------------------------------------
/*861*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068772
Language        =Eng
_MC("Shadow lookup failed")
.

//------------------------------------------------------------------------
/*862*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068773
Language        =Eng
_MC("Shadow %1 already exists")
.

//------------------------------------------------------------------------
/*863*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068774
Language        =Eng
_MC("Cannot add file with the same name as the database or added files")
.

//------------------------------------------------------------------------
/*864*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068775
Language        =Eng
_MC("no grant option for privilege %1 on column %2 of table/view %3")
.

//------------------------------------------------------------------------
/*865*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068776
Language        =Eng
_MC("no grant option for privilege %1 on column %2 of base table/view %3")
.

//------------------------------------------------------------------------
/*866*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068777
Language        =Eng
_MC("no grant option for privilege %1 on table/view %2 (for column %3)")
.

//------------------------------------------------------------------------
/*867*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068778
Language        =Eng
_MC("no grant option for privilege %1 on base table/view %2 (for column %3)")
.

//------------------------------------------------------------------------
/*868*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068779
Language        =Eng
_MC("no %1 privilege with grant option on table/view %2 (for column %3)")
.

//------------------------------------------------------------------------
/*869*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068780
Language        =Eng
_MC("no %1 privilege with grant option on base table/view %2 (for column %3)")
.

//------------------------------------------------------------------------
/*870*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068781
Language        =Eng
_MC("no grant option for privilege %1 on table/view %2")
.

//------------------------------------------------------------------------
/*871*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068782
Language        =Eng
_MC("no %1 privilege with grant option on table/view %2")
.

//------------------------------------------------------------------------
/*872*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068783
Language        =Eng
_MC("table/view %1 does not exist")
.

//------------------------------------------------------------------------
/*873*/
MessageId       =IBP_MCE_FB25__DYN_COLUMN_DOES_NOT_EXIST
Language        =Eng
_MC("column %1 does not exist in table/view %2")
.

//------------------------------------------------------------------------
/*874*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068785
Language        =Eng
_MC("Can not alter a view")
.

//------------------------------------------------------------------------
/*875*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068786
Language        =Eng
_MC("EXTERNAL FILE table not supported in this context")
.

//------------------------------------------------------------------------
/*876*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068787
Language        =Eng
_MC("attempt to index COMPUTED BY column in INDEX %1")
.

//------------------------------------------------------------------------
/*877*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068788
Language        =Eng
_MC("Table Name lookup failed")
.

//------------------------------------------------------------------------
/*878*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068789
Language        =Eng
_MC("attempt to index a view")
.

//------------------------------------------------------------------------
/*879*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068790
Language        =Eng
_MC("SELECT RDB$RELATIONS failed in grant")
.

//------------------------------------------------------------------------
/*880*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068791
Language        =Eng
_MC("SELECT RDB$RELATION_FIELDS failed in grant")
.

//------------------------------------------------------------------------
/*881*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068792
Language        =Eng
_MC("SELECT RDB$RELATIONS/RDB$OWNER_NAME failed in grant")
.

//------------------------------------------------------------------------
/*882*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068793
Language        =Eng
_MC("SELECT RDB$USER_PRIVILEGES failed in grant")
.

//------------------------------------------------------------------------
/*883*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068794
Language        =Eng
_MC("SELECT RDB$VIEW_RELATIONS/RDB$RELATION_FIELDS/... failed in grant")
.

//------------------------------------------------------------------------
/*884*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068795
Language        =Eng
_MC("column %1 from table %2 is referenced in index %3")
.

//------------------------------------------------------------------------
/*885*/
MessageId       =IBP_MCE_FB25__DYN_ROLE_DOES_NOT_EXIST
Language        =Eng
_MC("SQL role %1 does not exist")
.

//------------------------------------------------------------------------
/*886*/
MessageId       =IBP_MCE_FB25__DYN_NO_GRANT_ADMIN_OPT
Language        =Eng
_MC("user %1 has no grant admin option on SQL role %2")
.

//------------------------------------------------------------------------
/*887*/
MessageId       =IBP_MCE_FB25__DYN_USER_NOT_ROLE_MEMBER
Language        =Eng
_MC("user %1 is not a member of SQL role %2")
.

//------------------------------------------------------------------------
/*888*/
MessageId       =IBP_MCE_FB25__DYN_DELETE_ROLE_FAILED
Language        =Eng
_MC("%1 is not the owner of SQL role %2")
.

//------------------------------------------------------------------------
/*889*/
MessageId       =IBP_MCE_FB25__DYN_GRANT_ROLE_TO_USER
Language        =Eng
_MC("%1 is a SQL role and not a user")
.

//------------------------------------------------------------------------
/*890*/
MessageId       =IBP_MCE_FB25__DYN_INV_SQL_ROLE_NAME
Language        =Eng
_MC("user name %1 could not be used for SQL role")
.

//------------------------------------------------------------------------
/*891*/
MessageId       =IBP_MCE_FB25__DYN_DUP_SQL_ROLE
Language        =Eng
_MC("SQL role %1 already exists")
.

//------------------------------------------------------------------------
/*892*/
MessageId       =IBP_MCE_FB25__DYN_KYWD_SPEC_FOR_ROLE
Language        =Eng
_MC("keyword %1 can not be used as a SQL role name")
.

//------------------------------------------------------------------------
/*893*/
MessageId       =IBP_MCE_FB25__DYN_ROLES_NOT_SUPPORTED
Language        =Eng
_MC("SQL roles are not supported in on older versions of the database. A backup and restore of the database is required.")
.

//------------------------------------------------------------------------
/*894*/
MessageId       =IBP_MCE_FB25__DYN_DOMAIN_NAME_EXISTS
Language        =Eng
_MC("Cannot rename domain %1 to %2. A domain with that name already exists.")
.

//------------------------------------------------------------------------
/*895*/
MessageId       =IBP_MCE_FB25__DYN_FIELD_NAME_EXISTS
Language        =Eng
_MC("Cannot rename column %1 to %2. A column with that name already exists in table %3.")
.

//------------------------------------------------------------------------
/*896*/
MessageId       =IBP_MCE_FB25__DYN_DEPENDENCY_EXISTS
Language        =Eng
_MC("Column %1 from table %2 is referenced in %3")
.

//------------------------------------------------------------------------
/*897*/
MessageId       =IBP_MCE_FB25__DYN_DTYPE_INVALID
Language        =Eng
_MC("Cannot change datatype for column %1. Changing datatype is not supported for BLOB or ARRAY columns.")
.

//------------------------------------------------------------------------
/*898*/
MessageId       =IBP_MCE_FB25__DYN_CHAR_FLD_TOO_SMALL
Language        =Eng
_MC("New size specified for column %1 must be at least %2 characters.")
.

//------------------------------------------------------------------------
/*899*/
MessageId       =IBP_MCE_FB25__DYN_INVALID_DTYPE_CONVERSION
Language        =Eng
_MC("Cannot change datatype for %1. Conversion from base type %2 to %3 is not supported.")
.

//------------------------------------------------------------------------
/*900*/
MessageId       =IBP_MCE_FB25__DYN_DTYPE_CONV_INVALID
Language        =Eng
_MC("Cannot change datatype for column %1 from a character type to a non-character type.")
.

//------------------------------------------------------------------------
/*901*/
MessageId       =IBP_MCE_FB25__DYN_VIRMEMEXH
Language        =Eng
_MC("unable to allocate memory from the operating system")
.

//------------------------------------------------------------------------
/*902*/
MessageId       =IBP_MCE_FB25__DYN_ZERO_LEN_ID
Language        =Eng
_MC("Zero length identifiers are not allowed")
.

//------------------------------------------------------------------------
/*903*/
MessageId       =IBP_MCE_FB25__DEL_GEN_FAIL
Language        =Eng
_MC("ERASE RDB$GENERATORS failed")
.

//------------------------------------------------------------------------
/*904*/
MessageId       =IBP_MCE_FB25__DYN_GEN_NOT_FOUND
Language        =Eng
_MC("Generator %1 not found")
.

//------------------------------------------------------------------------
/*905*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068823
Language        =Eng
_MC("Difference file is not defined")
.

//------------------------------------------------------------------------
/*906*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068824
Language        =Eng
_MC("Difference file is already defined")
.

//------------------------------------------------------------------------
/*907*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068825
Language        =Eng
_MC("Database is already in the physical backup mode")
.

//------------------------------------------------------------------------
/*908*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068826
Language        =Eng
_MC("Database is not in the physical backup mode")
.

//------------------------------------------------------------------------
/*909*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068827
Language        =Eng
_MC("DEFINE COLLATION failed")
.

//------------------------------------------------------------------------
/*910*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068828
Language        =Eng
_MC("CREATE COLLATION statement is not supported in older versions of the database. A backup and restore is required.")
.

//------------------------------------------------------------------------
/*911*/
MessageId       =IBP_MCE_FB25__MAX_COLL_PER_CHARSET
Language        =Eng
_MC("Maximum number of collations per character set exceeded")
.

//------------------------------------------------------------------------
/*912*/
MessageId       =IBP_MCE_FB25__INVALID_COLL_ATTR
Language        =Eng
_MC("Invalid collation attributes")
.

//------------------------------------------------------------------------
/*913*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068831
Language        =Eng
_MC("Collation %1 not installed for character set %2")
.

//------------------------------------------------------------------------
/*914*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068832
Language        =Eng
_MC("Cannot use the internal domain %1 as new type for field %2")
.

//------------------------------------------------------------------------
/*915*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068833
Language        =Eng
_MC("Default value is not allowed for array type in field %1")
.

//------------------------------------------------------------------------
/*916*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068834
Language        =Eng
_MC("Default value is not allowed for array type in domain %1")
.

//------------------------------------------------------------------------
/*917*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068835
Language        =Eng
_MC("DYN_UTIL_is_array failed for domain %1")
.

//------------------------------------------------------------------------
/*918*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068836
Language        =Eng
_MC("DYN_UTIL_copy_domain failed for domain %1")
.

//------------------------------------------------------------------------
/*919*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068837
Language        =Eng
_MC("Local column %1 doesn't have a default")
.

//------------------------------------------------------------------------
/*920*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068838
Language        =Eng
_MC("Local column %1 default belongs to domain %2")
.

//------------------------------------------------------------------------
/*921*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068839
Language        =Eng
_MC("File name is invalid")
.

//------------------------------------------------------------------------
/*922*/
MessageId       =IBP_MCE_FB25__DYN_WRONG_GTT_SCOPE
Language        =Eng
_MC("%1 cannot reference %2")
.

//------------------------------------------------------------------------
/*923*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068841
Language        =Eng
_MC("Local column %1 is computed, cannot set a default value")
.

//------------------------------------------------------------------------
/*924*/
MessageId       =IBP_MCE_FB25__DEL_COLL_FAIL
Language        =Eng
_MC("ERASE RDB$COLLATIONS failed")
.

//------------------------------------------------------------------------
/*925*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068843
Language        =Eng
_MC("Collation %1 is used in table %2 (field name %3) and cannot be dropped")
.

//------------------------------------------------------------------------
/*926*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068844
Language        =Eng
_MC("Collation %1 is used in domain %2 and cannot be dropped")
.

//------------------------------------------------------------------------
/*927*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068845
Language        =Eng
_MC("Cannot delete system collation")
.

//------------------------------------------------------------------------
/*928*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068846
Language        =Eng
_MC("Cannot delete default collation of CHARACTER SET %1")
.

//------------------------------------------------------------------------
/*929*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068847
Language        =Eng
_MC("Domain %1 is used in procedure %2 (parameter name %3) and cannot be dropped")
.

//------------------------------------------------------------------------
/*930*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068848
Language        =Eng
_MC("Field %1 cannot be used twice in index %2")
.

//------------------------------------------------------------------------
/*931*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068849
Language        =Eng
_MC("Table %1 not found")
.

//------------------------------------------------------------------------
/*932*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068850
Language        =Eng
_MC("attempt to reference a view (%1) in a foreign key")
.

//------------------------------------------------------------------------
/*933*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068851
Language        =Eng
_MC("Collation %1 is used in procedure %2 (parameter name %3) and cannot be dropped")
.

//------------------------------------------------------------------------
/*934*/
MessageId       =IBP_MCE_FB25__DYN_SCALE_TOO_BIG
Language        =Eng
_MC("New scale specified for column %1 must be at most %2.")
.

//------------------------------------------------------------------------
/*935*/
MessageId       =IBP_MCE_FB25__DYN_PRECISION_TOO_SMALL
Language        =Eng
_MC("New precision specified for column %1 must be at least %2.")
.

//------------------------------------------------------------------------
/*936*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068854
Language        =Eng
_MC("%1 is not grantor of %2 on %3 to %4.")
.

//------------------------------------------------------------------------
/*937*/
MessageId       =IBP_MCE_FB25__DYN_MISS_PRIV_WARNING
Language        =Eng
_MC("Warning: %1 on %2 is not granted to %3.")
.

//------------------------------------------------------------------------
/*938*/
MessageId       =IBP_MCE_FB25__DYN_ODS_NOT_SUPP_FEATURE
Language        =Eng
_MC("Feature '%1' is not supported in ODS %2.%3")
.

//------------------------------------------------------------------------
/*939*/
MessageId       =IBP_MCE_FB25__DYN_CANNOT_ADDREM_COMPUTED
Language        =Eng
_MC("Cannot add or remove COMPUTED from column %1")
.

//------------------------------------------------------------------------
/*940*/
MessageId       =IBP_MCE_FB25__DYN_NO_EMPTY_PW
Language        =Eng
_MC("Password should not be empty string")
.

//------------------------------------------------------------------------
/*941*/
MessageId       =IBP_MCE_FB25__DYN_DUP_INDEX
Language        =Eng
_MC("Index %1 already exists")
.

//------------------------------------------------------------------------
/*942*/
MessageId       =IBP_MCE_FB25__DYN_LOCKSMITH_USE_GRANTED
Language        =Eng
_MC("Only %1 or database owner can use GRANTED BY clause")
.

//------------------------------------------------------------------------
/*943*/
MessageId       =IBP_MCE_FB25__DYN_DUP_EXCEPTION
Language        =Eng
_MC("Exception %1 already exists")
.

//------------------------------------------------------------------------
/*944*/
MessageId       =IBP_MCE_FB25__DYN_DUP_GENERATOR
Language        =Eng
_MC("Generator %1 already exists")
.

//------------------------------------------------------------------------
/*945*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068863
Language        =Eng
_MC("ERASE RDB$USER_PRIVILEGES failed in REVOKE ALL ON ALL")
.

//------------------------------------------------------------------------
/*946*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336068892
Language        =Eng
_MC("Cannot delete system SQL role %1")
.

//------------------------------------------------------------------------
/*947*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396289
Language        =Eng
_MC("Firebird error")
.

//------------------------------------------------------------------------
/*948*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396362
Language        =Eng
_MC("Rollback not performed")
.

//------------------------------------------------------------------------
/*949*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396364
Language        =Eng
_MC("Connection error")
.

//------------------------------------------------------------------------
/*950*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396365
Language        =Eng
_MC("Connection not established")
.

//------------------------------------------------------------------------
/*951*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396366
Language        =Eng
_MC("Connection authorization failure.")
.

//------------------------------------------------------------------------
/*952*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396375
Language        =Eng
_MC("deadlock")
.

//------------------------------------------------------------------------
/*953*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396376
Language        =Eng
_MC("Unsuccessful execution caused by deadlock.")
.

//------------------------------------------------------------------------
/*954*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396377
Language        =Eng
_MC("record from transaction %1 is stuck in limbo")
.

//------------------------------------------------------------------------
/*955*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396379
Language        =Eng
_MC("operation completed with errors")
.

//------------------------------------------------------------------------
/*956*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396382
Language        =Eng
_MC("the SQL statement cannot be executed")
.

//------------------------------------------------------------------------
/*957*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396384
Language        =Eng
_MC("Unsuccessful execution caused by an unavailable resource.")
.

//------------------------------------------------------------------------
/*958*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396386
Language        =Eng
_MC("Unsuccessful execution caused by a system error that precludes successful execution of subsequent statements")
.

//------------------------------------------------------------------------
/*959*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396387
Language        =Eng
_MC("Unsuccessful execution caused by system error that does not preclude successful execution of subsequent statements")
.

//------------------------------------------------------------------------
/*960*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396446
Language        =Eng
_MC("Wrong numeric type")
.

//------------------------------------------------------------------------
/*961*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396447
Language        =Eng
_MC("too many versions")
.

//------------------------------------------------------------------------
/*962*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396448
Language        =Eng
_MC("intermediate journal file full")
.

//------------------------------------------------------------------------
/*963*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396449
Language        =Eng
_MC("journal file wrong format")
.

//------------------------------------------------------------------------
/*964*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396450
Language        =Eng
_MC("database %1 shutdown in %2 seconds")
.

//------------------------------------------------------------------------
/*965*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396451
Language        =Eng
_MC("restart shared cache manager")
.

//------------------------------------------------------------------------
/*966*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396452
Language        =Eng
_MC("exception %1")
.

//------------------------------------------------------------------------
/*967*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396453
Language        =Eng
_MC("bad checksum")
.

//------------------------------------------------------------------------
/*968*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396454
Language        =Eng
_MC("refresh range number %1 not found")
.

//------------------------------------------------------------------------
/*969*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396455
Language        =Eng
_MC("expression evaluation not supported")
.

//------------------------------------------------------------------------
/*970*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396456
Language        =Eng
_MC("FOREIGN KEY column count does not match PRIMARY KEY")
.

//------------------------------------------------------------------------
/*971*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396457
Language        =Eng
_MC("Attempt to define a second PRIMARY KEY for the same table")
.

//------------------------------------------------------------------------
/*972*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396458
Language        =Eng
_MC("column used with aggregate")
.

//------------------------------------------------------------------------
/*973*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396459
Language        =Eng
_MC("invalid column reference")
.

//------------------------------------------------------------------------
/*974*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396460
Language        =Eng
_MC("invalid key position")
.

//------------------------------------------------------------------------
/*975*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396461
Language        =Eng
_MC("invalid direction for find operation")
.

//------------------------------------------------------------------------
/*976*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396462
Language        =Eng
_MC("Invalid statement handle")
.

//------------------------------------------------------------------------
/*977*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396463
Language        =Eng
_MC("invalid lock handle")
.

//------------------------------------------------------------------------
/*978*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396464
Language        =Eng
_MC("invalid lock level %1")
.

//------------------------------------------------------------------------
/*979*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396465
Language        =Eng
_MC("invalid bookmark handle")
.

//------------------------------------------------------------------------
/*980*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396468
Language        =Eng
_MC("wrong or obsolete version")
.

//------------------------------------------------------------------------
/*981*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396471
Language        =Eng
_MC("The INSERT, UPDATE, DELETE, DDL or authorization statement cannot be executed because the transaction is inquiry only")
.

//------------------------------------------------------------------------
/*982*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396472
Language        =Eng
_MC("external file could not be opened for output")
.

//------------------------------------------------------------------------
/*983*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396477
Language        =Eng
_MC("multiple rows in singleton select")
.

//------------------------------------------------------------------------
/*984*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396478
Language        =Eng
_MC("No subqueries permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*985*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396479
Language        =Eng
_MC("DISTINCT, GROUP or HAVING not permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*986*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396480
Language        =Eng
_MC("Only one table allowed for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*987*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396481
Language        =Eng
_MC("No WHERE clause for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*988*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396482
Language        =Eng
_MC("Only simple column names permitted for VIEW WITH CHECK OPTION")
.

//------------------------------------------------------------------------
/*989*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396484
Language        =Eng
_MC("An error was found in the application program input parameters for the SQL statement.")
.

//------------------------------------------------------------------------
/*990*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396485
Language        =Eng
_MC("Invalid insert or update value(s): object columns are constrained - no 2 table rows can have duplicate column values")
.

//------------------------------------------------------------------------
/*991*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396486
Language        =Eng
_MC("Arithmetic overflow or division by zero has occurred.")
.

//------------------------------------------------------------------------
/*992*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396594
Language        =Eng
_MC("cannot access column %1 in view %2")
.

//------------------------------------------------------------------------
/*993*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396595
Language        =Eng
_MC("Too many concurrent executions of the same request")
.

//------------------------------------------------------------------------
/*994*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396596
Language        =Eng
_MC("maximum indexes per table (%1) exceeded")
.

//------------------------------------------------------------------------
/*995*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396597
Language        =Eng
_MC("new record size of %1 bytes is too big")
.

//------------------------------------------------------------------------
/*996*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396598
Language        =Eng
_MC("segments not allowed in expression index %1")
.

//------------------------------------------------------------------------
/*997*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396599
Language        =Eng
_MC("wrong page type")
.

//------------------------------------------------------------------------
/*998*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396603
Language        =Eng
_MC("invalid ARRAY or BLOB operation")
.

//------------------------------------------------------------------------
/*999*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396611
Language        =Eng
_MC("%1 extension error")
.

//------------------------------------------------------------------------
/*1000*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396624
Language        =Eng
_MC("key size exceeds implementation restriction for index \"%1\"")
.

//------------------------------------------------------------------------
/*1001*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396625
Language        =Eng
_MC("definition error for index %1")
.

//------------------------------------------------------------------------
/*1002*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396628
Language        =Eng
_MC("cannot create index")
.

//------------------------------------------------------------------------
/*1003*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396651
Language        =Eng
_MC("duplicate specification of %1 - not supported")
.

//------------------------------------------------------------------------
/*1004*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396663
Language        =Eng
_MC("The insert failed because a column definition includes validation constraints.")
.

//------------------------------------------------------------------------
/*1005*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396670
Language        =Eng
_MC("Cannot delete object referenced by another object")
.

//------------------------------------------------------------------------
/*1006*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396671
Language        =Eng
_MC("Cannot modify object referenced by another object")
.

//------------------------------------------------------------------------
/*1007*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396672
Language        =Eng
_MC("Object is referenced by another object")
.

//------------------------------------------------------------------------
/*1008*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396673
Language        =Eng
_MC("lock on conflicts with existing lock")
.

//------------------------------------------------------------------------
/*1009*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396681
Language        =Eng
_MC("This operation is not defined for system tables.")
.

//------------------------------------------------------------------------
/*1010*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396683
Language        =Eng
_MC("Inappropriate self-reference of column")
.

//------------------------------------------------------------------------
/*1011*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396684
Language        =Eng
_MC("Illegal array dimension range")
.

//------------------------------------------------------------------------
/*1012*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396687
Language        =Eng
_MC("database or file exists")
.

//------------------------------------------------------------------------
/*1013*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396688
Language        =Eng
_MC("sort error: corruption in data structure")
.

//------------------------------------------------------------------------
/*1014*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396689
Language        =Eng
_MC("node not supported")
.

//------------------------------------------------------------------------
/*1015*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396690
Language        =Eng
_MC("Shadow number must be a positive integer")
.

//------------------------------------------------------------------------
/*1016*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396691
Language        =Eng
_MC("Preceding file did not specify length, so %1 must include starting page number")
.

//------------------------------------------------------------------------
/*1017*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396692
Language        =Eng
_MC("illegal operation when at beginning of stream")
.

//------------------------------------------------------------------------
/*1018*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396693
Language        =Eng
_MC("the current position is on a crack")
.

//------------------------------------------------------------------------
/*1019*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396735
Language        =Eng
_MC("cannot modify an existing user privilege")
.

//------------------------------------------------------------------------
/*1020*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396736
Language        =Eng
_MC("user does not have the privilege to perform operation")
.

//------------------------------------------------------------------------
/*1021*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396737
Language        =Eng
_MC("This user does not have privilege to perform this operation on this object.")
.

//------------------------------------------------------------------------
/*1022*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396756
Language        =Eng
_MC("transaction marked invalid by I/O error")
.

//------------------------------------------------------------------------
/*1023*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396757
Language        =Eng
_MC("Cannot prepare a CREATE DATABASE/SCHEMA statement")
.

//------------------------------------------------------------------------
/*1024*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396758
Language        =Eng
_MC("violation of FOREIGN KEY constraint \"%1\"")
.

//------------------------------------------------------------------------
/*1025*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396769
Language        =Eng
_MC("The prepare statement identifies a prepare statement with an open cursor")
.

//------------------------------------------------------------------------
/*1026*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396770
Language        =Eng
_MC("Unknown statement or request")
.

//------------------------------------------------------------------------
/*1027*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396778
Language        =Eng
_MC("Attempt to update non-updatable cursor")
.

//------------------------------------------------------------------------
/*1028*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396780
Language        =Eng
_MC("The cursor identified in the UPDATE or DELETE statement is not positioned on a row.")
.

//------------------------------------------------------------------------
/*1029*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396784
Language        =Eng
_MC("Unknown cursor")
.

//------------------------------------------------------------------------
/*1030*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396786
Language        =Eng
_MC("The cursor identified in an OPEN statement is already open.")
.

//------------------------------------------------------------------------
/*1031*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396787
Language        =Eng
_MC("The cursor identified in a FETCH or CLOSE statement is not open.")
.

//------------------------------------------------------------------------
/*1032*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396875
Language        =Eng
_MC("Overflow occurred during data type conversion.")
.

//------------------------------------------------------------------------
/*1033*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396881
Language        =Eng
_MC("null segment of UNIQUE KEY")
.

//------------------------------------------------------------------------
/*1034*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396882
Language        =Eng
_MC("subscript out of bounds")
.

//------------------------------------------------------------------------
/*1035*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396886
Language        =Eng
_MC("data operation not supported")
.

//------------------------------------------------------------------------
/*1036*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396887
Language        =Eng
_MC("invalid comparison operator for find operation")
.

//------------------------------------------------------------------------
/*1037*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396974
Language        =Eng
_MC("Cannot transliterate character between character sets")
.

//------------------------------------------------------------------------
/*1038*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396975
Language        =Eng
_MC("count of column list and variable list do not match")
.

//------------------------------------------------------------------------
/*1039*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396985
Language        =Eng
_MC("Incompatible column/host variable data type")
.

//------------------------------------------------------------------------
/*1040*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396991
Language        =Eng
_MC("Operation violates CHECK constraint %1 on view or table")
.

//------------------------------------------------------------------------
/*1041*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396992
Language        =Eng
_MC("internal Firebird consistency check (invalid RDB$CONSTRAINT_TYPE)")
.

//------------------------------------------------------------------------
/*1042*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396993
Language        =Eng
_MC("Cannot update constraints (RDB$RELATION_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*1043*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396994
Language        =Eng
_MC("Cannot delete CHECK constraint entry (RDB$CHECK_CONSTRAINTS)")
.

//------------------------------------------------------------------------
/*1044*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396995
Language        =Eng
_MC("Cannot update constraints (RDB$CHECK_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*1045*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396996
Language        =Eng
_MC("Cannot update constraints (RDB$REF_CONSTRAINTS).")
.

//------------------------------------------------------------------------
/*1046*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336396997
Language        =Eng
_MC("Column used in a PRIMARY constraint must be NOT NULL.")
.

//------------------------------------------------------------------------
/*1047*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397004
Language        =Eng
_MC("index %1 cannot be used in the specified plan")
.

//------------------------------------------------------------------------
/*1048*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397005
Language        =Eng
_MC("table %1 is referenced in the plan but not the from list")
.

//------------------------------------------------------------------------
/*1049*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397006
Language        =Eng
_MC("the table %1 is referenced twice; use aliases to differentiate")
.

//------------------------------------------------------------------------
/*1050*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397007
Language        =Eng
_MC("table %1 is not referenced in plan")
.

//------------------------------------------------------------------------
/*1051*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397027
Language        =Eng
_MC("Log file specification partition error")
.

//------------------------------------------------------------------------
/*1052*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397028
Language        =Eng
_MC("Cache or Log redefined")
.

//------------------------------------------------------------------------
/*1053*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397029
Language        =Eng
_MC("Write-ahead Log with shadowing configuration not allowed")
.

//------------------------------------------------------------------------
/*1054*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397030
Language        =Eng
_MC("Overflow log specification required for round-robin log")
.

//------------------------------------------------------------------------
/*1055*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397031
Language        =Eng
_MC("WAL defined; Cache Manager must be started first")
.

//------------------------------------------------------------------------
/*1056*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397033
Language        =Eng
_MC("Write-ahead Log without shared cache configuration not allowed")
.

//------------------------------------------------------------------------
/*1057*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397034
Language        =Eng
_MC("Cannot start WAL writer for the database %1")
.

//------------------------------------------------------------------------
/*1058*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397035
Language        =Eng
_MC("WAL writer synchronization error for the database %1")
.

//------------------------------------------------------------------------
/*1059*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397036
Language        =Eng
_MC("WAL setup error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*1060*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397037
Language        =Eng
_MC("WAL buffers cannot be increased. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*1061*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397038
Language        =Eng
_MC("WAL writer - Journal server communication error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*1062*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397039
Language        =Eng
_MC("WAL I/O error. Please see Firebird log.")
.

//------------------------------------------------------------------------
/*1063*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397040
Language        =Eng
_MC("Unable to roll over; please see Firebird log.")
.

//------------------------------------------------------------------------
/*1064*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397041
Language        =Eng
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1065*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397042
Language        =Eng
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1066*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397043
Language        =Eng
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1067*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397044
Language        =Eng
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1068*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397045
Language        =Eng
_MC("database does not use Write-ahead Log")
.

//------------------------------------------------------------------------
/*1069*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397046
Language        =Eng
_MC("Cannot roll over to the next log file %1")
.

//------------------------------------------------------------------------
/*1070*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397047
Language        =Eng
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1071*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397048
Language        =Eng
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1072*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397049
Language        =Eng
_MC("Cache or Log size too small")
.

//------------------------------------------------------------------------
/*1073*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397050
Language        =Eng
_MC("Log record header too small at offset %1 in log file %2")
.

//------------------------------------------------------------------------
/*1074*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397051
Language        =Eng
_MC("Incomplete log record at offset %1 in log file %2")
.

//------------------------------------------------------------------------
/*1075*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397052
Language        =Eng
_MC("Unexpected end of log file %1 at offset %2")
.

//------------------------------------------------------------------------
/*1076*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397053
Language        =Eng
_MC("Database name in the log file %1 is different")
.

//------------------------------------------------------------------------
/*1077*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397054
Language        =Eng
_MC("Log file %1 not closed properly; database recovery may be required")
.

//------------------------------------------------------------------------
/*1078*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397055
Language        =Eng
_MC("Log file %1 not latest in the chain but open flag still set")
.

//------------------------------------------------------------------------
/*1079*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397056
Language        =Eng
_MC("Invalid version of log file %1")
.

//------------------------------------------------------------------------
/*1080*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397057
Language        =Eng
_MC("Log file header of %1 too small")
.

//------------------------------------------------------------------------
/*1081*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397058
Language        =Eng
_MC("obsolete")
.

//------------------------------------------------------------------------
/*1082*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397069
Language        =Eng
_MC("table %1 is not defined")
.

//------------------------------------------------------------------------
/*1083*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397080
Language        =Eng
_MC("invalid ORDER BY clause")
.

//------------------------------------------------------------------------
/*1084*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397082
Language        =Eng
_MC("Column does not belong to referenced table")
.

//------------------------------------------------------------------------
/*1085*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397083
Language        =Eng
_MC("column %1 is not defined in table %2")
.

//------------------------------------------------------------------------
/*1086*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397084
Language        =Eng
_MC("Undefined name")
.

//------------------------------------------------------------------------
/*1087*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397085
Language        =Eng
_MC("Ambiguous column reference.")
.

//------------------------------------------------------------------------
/*1088*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397116
Language        =Eng
_MC("function %1 is not defined")
.

//------------------------------------------------------------------------
/*1089*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397117
Language        =Eng
_MC("Invalid data type, length, or value")
.

//------------------------------------------------------------------------
/*1090*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397118
Language        =Eng
_MC("Invalid number of arguments")
.

//------------------------------------------------------------------------
/*1091*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397126
Language        =Eng
_MC("dbkey not available for multi-table views")
.

//------------------------------------------------------------------------
/*1092*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397130
Language        =Eng
_MC("number of columns does not match select list")
.

//------------------------------------------------------------------------
/*1093*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397131
Language        =Eng
_MC("must specify column name for view select expression")
.

//------------------------------------------------------------------------
/*1094*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397133
Language        =Eng
_MC("%1 is not a valid base table of the specified view")
.

//------------------------------------------------------------------------
/*1095*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397137
Language        =Eng
_MC("This column cannot be updated because it is derived from an SQL function or expression.")
.

//------------------------------------------------------------------------
/*1096*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397138
Language        =Eng
_MC("The object of the INSERT, DELETE or UPDATE statement is a view for which the requested operation is not permitted.")
.

//------------------------------------------------------------------------
/*1097*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397183
Language        =Eng
_MC("Invalid String")
.

//------------------------------------------------------------------------
/*1098*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397184
Language        =Eng
_MC("Invalid token")
.

//------------------------------------------------------------------------
/*1099*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397185
Language        =Eng
_MC("Invalid numeric literal")
.

//------------------------------------------------------------------------
/*1100*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397203
Language        =Eng
_MC("An error occurred while trying to update the security database")
.

//------------------------------------------------------------------------
/*1101*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336397204
Language        =Eng
_MC("non-SQL security class defined")
.

//------------------------------------------------------------------------
/*1102*/
MessageId       =IBP_MCE_FB25__DSQL_TOO_OLD_ODS
Language        =Eng
_MC("ODS versions before ODS%1 are not supported")
.

//------------------------------------------------------------------------
/*1103*/
MessageId       =IBP_MCE_FB25__DSQL_TABLE_NOT_FOUND
Language        =Eng
_MC("Table %1 does not exist")
.

//------------------------------------------------------------------------
/*1104*/
MessageId       =IBP_MCE_FB25__DSQL_VIEW_NOT_FOUND
Language        =Eng
_MC("View %1 does not exist")
.

//------------------------------------------------------------------------
/*1105*/
MessageId       =IBP_MCE_FB25__DSQL_LINE_COL_ERROR
Language        =Eng
_MC("At line %1, column %2")
.

//------------------------------------------------------------------------
/*1106*/
MessageId       =IBP_MCE_FB25__DSQL_UNKNOWN_POS
Language        =Eng
_MC("At unknown line and column")
.

//------------------------------------------------------------------------
/*1107*/
MessageId       =IBP_MCE_FB25__DSQL_NO_DUP_NAME
Language        =Eng
_MC("Column %1 cannot be repeated in %2 statement")
.

//------------------------------------------------------------------------
/*1108*/
MessageId       =IBP_MCE_FB25__DSQL_TOO_MANY_VALUES
Language        =Eng
_MC("Too many values (more than %1) in member list to match against")
.

//------------------------------------------------------------------------
/*1109*/
MessageId       =IBP_MCE_FB25__DSQL_NO_ARRAY_COMPUTED
Language        =Eng
_MC("Array and BLOB data types not allowed in computed field")
.

//------------------------------------------------------------------------
/*1110*/
MessageId       =IBP_MCE_FB25__DSQL_IMPLICIT_DOMAIN_NAME
Language        =Eng
_MC("Implicit domain name %1 not allowed in user created domain")
.

//------------------------------------------------------------------------
/*1111*/
MessageId       =IBP_MCE_FB25__DSQL_ONLY_CAN_SUBSCRIPT_ARRAY
Language        =Eng
_MC("scalar operator used on field %1 which is not an array")
.

//------------------------------------------------------------------------
/*1112*/
MessageId       =IBP_MCE_FB25__DSQL_MAX_SORT_ITEMS
Language        =Eng
_MC("cannot sort on more than 255 items")
.

//------------------------------------------------------------------------
/*1113*/
MessageId       =IBP_MCE_FB25__DSQL_MAX_GROUP_ITEMS
Language        =Eng
_MC("cannot group on more than 255 items")
.

//------------------------------------------------------------------------
/*1114*/
MessageId       =IBP_MCE_FB25__DSQL_CONFLICTING_SORT_FIELD
Language        =Eng
_MC("Cannot include the same field (%1.%2) twice in the ORDER BY clause with conflicting sorting options")
.

//------------------------------------------------------------------------
/*1115*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_TABLE_MORE_COLUMNS
Language        =Eng
_MC("column list from derived table %1 has more columns than the number of items in its SELECT statement")
.

//------------------------------------------------------------------------
/*1116*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_TABLE_LESS_COLUMNS
Language        =Eng
_MC("column list from derived table %1 has less columns than the number of items in its SELECT statement")
.

//------------------------------------------------------------------------
/*1117*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_FIELD_UNNAMED
Language        =Eng
_MC("no column name specified for column number %1 in derived table %2")
.

//------------------------------------------------------------------------
/*1118*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_FIELD_DUP_NAME
Language        =Eng
_MC("column %1 was specified multiple times for derived table %2")
.

//------------------------------------------------------------------------
/*1119*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_ALIAS_SELECT
Language        =Eng
_MC("Internal dsql error: alias type expected by pass1_expand_select_node")
.

//------------------------------------------------------------------------
/*1120*/
MessageId       =IBP_MCE_FB25__DSQL_DERIVED_ALIAS_FIELD
Language        =Eng
_MC("Internal dsql error: alias type expected by pass1_field")
.

//------------------------------------------------------------------------
/*1121*/
MessageId       =IBP_MCE_FB25__DSQL_AUTO_FIELD_BAD_POS
Language        =Eng
_MC("Internal dsql error: column position out of range in pass1_union_auto_cast")
.

//------------------------------------------------------------------------
/*1122*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_WRONG_REFERENCE
Language        =Eng
_MC("Recursive CTE member (%1) can refer itself only in FROM clause")
.

//------------------------------------------------------------------------
/*1123*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_CYCLE
Language        =Eng
_MC("CTE '%1' has cyclic dependencies")
.

//------------------------------------------------------------------------
/*1124*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_OUTER_JOIN
Language        =Eng
_MC("Recursive member of CTE can't be member of an outer join")
.

//------------------------------------------------------------------------
/*1125*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_MULT_REFERENCES
Language        =Eng
_MC("Recursive member of CTE can't reference itself more than once")
.

//------------------------------------------------------------------------
/*1126*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_NOT_A_UNION
Language        =Eng
_MC("Recursive CTE (%1) must be an UNION")
.

//------------------------------------------------------------------------
/*1127*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_NONRECURS_AFTER_RECURS
Language        =Eng
_MC("CTE '%1' defined non-recursive member after recursive")
.

//------------------------------------------------------------------------
/*1128*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_WRONG_CLAUSE
Language        =Eng
_MC("Recursive member of CTE '%1' has %2 clause")
.

//------------------------------------------------------------------------
/*1129*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_UNION_ALL
Language        =Eng
_MC("Recursive members of CTE (%1) must be linked with another members via UNION ALL")
.

//------------------------------------------------------------------------
/*1130*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_MISS_NONRECURSIVE
Language        =Eng
_MC("Non-recursive member is missing in CTE '%1'")
.

//------------------------------------------------------------------------
/*1131*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_NESTED_WITH
Language        =Eng
_MC("WITH clause can't be nested")
.

//------------------------------------------------------------------------
/*1132*/
MessageId       =IBP_MCE_FB25__DSQL_COL_MORE_THAN_ONCE_USING
Language        =Eng
_MC("column %1 appears more than once in USING clause")
.

//------------------------------------------------------------------------
/*1133*/
MessageId       =IBP_MCE_FB25__DSQL_UNSUPP_FEATURE_DIALECT
Language        =Eng
_MC("feature is not supported in dialect %1")
.

//------------------------------------------------------------------------
/*1134*/
MessageId       =IBP_MCE_FB25__DSQL_CTE_NOT_USED
Language        =Eng
_MC("CTE \"%1\" is not used in query")
.

//------------------------------------------------------------------------
/*1135*/
MessageId       =IBP_MCE_FB25__DSQL_COL_MORE_THAN_ONCE_VIEW
Language        =Eng
_MC("column %1 appears more than once in ALTER VIEW")
.

//------------------------------------------------------------------------
/*1136*/
MessageId       =IBP_MCE_FB25__DSQL_UNSUPPORTED_IN_AUTO_TRANS
Language        =Eng
_MC("%1 is not supported inside IN AUTONOMOUS TRANSACTION block")
.

//------------------------------------------------------------------------
/*1137*/
MessageId       =IBP_MCE_FB25__DSQL_EVAL_UNKNODE
Language        =Eng
_MC("Unknown node type %1 in dsql/GEN_expr")
.

//------------------------------------------------------------------------
/*1138*/
MessageId       =IBP_MCE_FB25__DSQL_AGG_WRONGARG
Language        =Eng
_MC("Argument for %1 in dialect 1 must be string or numeric")
.

//------------------------------------------------------------------------
/*1139*/
MessageId       =IBP_MCE_FB25__DSQL_AGG2_WRONGARG
Language        =Eng
_MC("Argument for %1 in dialect 3 must be numeric")
.

//------------------------------------------------------------------------
/*1140*/
MessageId       =IBP_MCE_FB25__DSQL_NODATEORTIME_PM_STRING
Language        =Eng
_MC("Strings cannot be added to or subtracted from DATE or TIME types")
.

//------------------------------------------------------------------------
/*1141*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_DATETIME_SUBTRACT
Language        =Eng
_MC("Invalid data type for subtraction involving DATE, TIME or TIMESTAMP types")
.

//------------------------------------------------------------------------
/*1142*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_DATEORTIME_ADD
Language        =Eng
_MC("Adding two DATE values or two TIME values is not allowed")
.

//------------------------------------------------------------------------
/*1143*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_MINUS_DATE
Language        =Eng
_MC("DATE value cannot be subtracted from the provided data type")
.

//------------------------------------------------------------------------
/*1144*/
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_ADDSUB_DIAL3
Language        =Eng
_MC("Strings cannot be added or subtracted in dialect 3")
.

//------------------------------------------------------------------------
/*1145*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_ADDSUB_DIAL3
Language        =Eng
_MC("Invalid data type for addition or subtraction in dialect 3")
.

//------------------------------------------------------------------------
/*1146*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_MULTIP_DIAL1
Language        =Eng
_MC("Invalid data type for multiplication in dialect 1")
.

//------------------------------------------------------------------------
/*1147*/
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_MULTIP_DIAL3
Language        =Eng
_MC("Strings cannot be multiplied in dialect 3")
.

//------------------------------------------------------------------------
/*1148*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_MULTIP_DIAL3
Language        =Eng
_MC("Invalid data type for multiplication in dialect 3")
.

//------------------------------------------------------------------------
/*1149*/
MessageId       =IBP_MCE_FB25__DSQL_MUSTUSE_NUMERIC_DIV_DIAL1
Language        =Eng
_MC("Division in dialect 1 must be between numeric data types")
.

//------------------------------------------------------------------------
/*1150*/
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_DIV_DIAL3
Language        =Eng
_MC("Strings cannot be divided in dialect 3")
.

//------------------------------------------------------------------------
/*1151*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_DIV_DIAL3
Language        =Eng
_MC("Invalid data type for division in dialect 3")
.

//------------------------------------------------------------------------
/*1152*/
MessageId       =IBP_MCE_FB25__DSQL_NOSTRING_NEG_DIAL3
Language        =Eng
_MC("Strings cannot be negated (applied the minus operator) in dialect 3")
.

//------------------------------------------------------------------------
/*1153*/
MessageId       =IBP_MCE_FB25__DSQL_INVALID_TYPE_NEG
Language        =Eng
_MC("Invalid data type for negation (minus operator)")
.

//------------------------------------------------------------------------
/*1154*/
MessageId       =IBP_MCE_FB25__DSQL_MAX_DISTINCT_ITEMS
Language        =Eng
_MC("Cannot have more than 255 items in DISTINCT list")
.

//------------------------------------------------------------------------
/*1155*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336461924
Language        =Eng
_MC("Row not found for fetch, update or delete, or the result of a query is an empty table.")
.

//------------------------------------------------------------------------
/*1156*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336461925
Language        =Eng
_MC("segment buffer length shorter than expected")
.

//------------------------------------------------------------------------
/*1157*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336462125
Language        =Eng
_MC("Datatype needs modification")
.

//------------------------------------------------------------------------
/*1158*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336462436
Language        =Eng
_MC("Duplicate column or domain name found.")
.

//------------------------------------------------------------------------
/*1159*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527507
Language        =Eng
_MC("invalid block type encountered")
.

//------------------------------------------------------------------------
/*1160*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527508
Language        =Eng
_MC("wrong packet type")
.

//------------------------------------------------------------------------
/*1161*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527509
Language        =Eng
_MC("cannot map page")
.

//------------------------------------------------------------------------
/*1162*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527510
Language        =Eng
_MC("request to allocate invalid block type")
.

//------------------------------------------------------------------------
/*1163*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527511
Language        =Eng
_MC("request to allocate block type larger than maximum size")
.

//------------------------------------------------------------------------
/*1164*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527512
Language        =Eng
_MC("memory pool free list is invalid")
.

//------------------------------------------------------------------------
/*1165*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527513
Language        =Eng
_MC("invalid pool id encountered")
.

//------------------------------------------------------------------------
/*1166*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527514
Language        =Eng
_MC("attempt to release free block")
.

//------------------------------------------------------------------------
/*1167*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527515
Language        =Eng
_MC("attempt to release block overlapping following free block")
.

//------------------------------------------------------------------------
/*1168*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527516
Language        =Eng
_MC("attempt to release block overlapping prior free block")
.

//------------------------------------------------------------------------
/*1169*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527517
Language        =Eng
_MC("cannot sort on a field that does not exist")
.

//------------------------------------------------------------------------
/*1170*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527518
Language        =Eng
_MC("database file not available")
.

//------------------------------------------------------------------------
/*1171*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527519
Language        =Eng
_MC("cannot assert logical lock")
.

//------------------------------------------------------------------------
/*1172*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527520
Language        =Eng
_MC("wrong ACL version")
.

//------------------------------------------------------------------------
/*1173*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527521
Language        =Eng
_MC("shadow block not found")
.

//------------------------------------------------------------------------
/*1174*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527522
Language        =Eng
_MC("shadow lock not synchronized properly")
.

//------------------------------------------------------------------------
/*1175*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527523
Language        =Eng
_MC("root file name not listed for shadow")
.

//------------------------------------------------------------------------
/*1176*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527524
Language        =Eng
_MC("failed to remove symbol from hash table")
.

//------------------------------------------------------------------------
/*1177*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527525
Language        =Eng
_MC("cannot find tip page")
.

//------------------------------------------------------------------------
/*1178*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527526
Language        =Eng
_MC("invalid rsb type")
.

//------------------------------------------------------------------------
/*1179*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527527
Language        =Eng
_MC("invalid SEND request")
.

//------------------------------------------------------------------------
/*1180*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527528
Language        =Eng
_MC("looper: action not yet implemented")
.

//------------------------------------------------------------------------
/*1181*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527529
Language        =Eng
_MC("return data type not supported")
.

//------------------------------------------------------------------------
/*1182*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527530
Language        =Eng
_MC("unexpected reply from journal server")
.

//------------------------------------------------------------------------
/*1183*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527531
Language        =Eng
_MC("journal server is incompatible version")
.

//------------------------------------------------------------------------
/*1184*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527532
Language        =Eng
_MC("journal server refused connection")
.

//------------------------------------------------------------------------
/*1185*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527533
Language        =Eng
_MC("referenced index description not found")
.

//------------------------------------------------------------------------
/*1186*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527534
Language        =Eng
_MC("index key too big")
.

//------------------------------------------------------------------------
/*1187*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527535
Language        =Eng
_MC("partner index description not found")
.

//------------------------------------------------------------------------
/*1188*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527536
Language        =Eng
_MC("bad difference record")
.

//------------------------------------------------------------------------
/*1189*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527537
Language        =Eng
_MC("applied differences will not fit in record")
.

//------------------------------------------------------------------------
/*1190*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527538
Language        =Eng
_MC("record length inconsistent")
.

//------------------------------------------------------------------------
/*1191*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527539
Language        =Eng
_MC("decompression overran buffer")
.

//------------------------------------------------------------------------
/*1192*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527540
Language        =Eng
_MC("cannot reposition for update after sort for RMS")
.

//------------------------------------------------------------------------
/*1193*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527541
Language        =Eng
_MC("external access type not implemented")
.

//------------------------------------------------------------------------
/*1194*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527542
Language        =Eng
_MC("differences record too long")
.

//------------------------------------------------------------------------
/*1195*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527543
Language        =Eng
_MC("wrong record length")
.

//------------------------------------------------------------------------
/*1196*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527544
Language        =Eng
_MC("limbo impossible")
.

//------------------------------------------------------------------------
/*1197*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527545
Language        =Eng
_MC("wrong record version")
.

//------------------------------------------------------------------------
/*1198*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527546
Language        =Eng
_MC("record disappeared")
.

//------------------------------------------------------------------------
/*1199*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527547
Language        =Eng
_MC("cannot delete system tables")
.

//------------------------------------------------------------------------
/*1200*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527548
Language        =Eng
_MC("cannot update erased record")
.

//------------------------------------------------------------------------
/*1201*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527549
Language        =Eng
_MC("comparison not supported for specified data types")
.

//------------------------------------------------------------------------
/*1202*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527550
Language        =Eng
_MC("conversion not supported for specified data types")
.

//------------------------------------------------------------------------
/*1203*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527551
Language        =Eng
_MC("conversion error")
.

//------------------------------------------------------------------------
/*1204*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527552
Language        =Eng
_MC("overflow during conversion")
.

//------------------------------------------------------------------------
/*1205*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527553
Language        =Eng
_MC("null or invalid array")
.

//------------------------------------------------------------------------
/*1206*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527554
Language        =Eng
_MC("BLOB not found")
.

//------------------------------------------------------------------------
/*1207*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527555
Language        =Eng
_MC("cannot update old BLOB")
.

//------------------------------------------------------------------------
/*1208*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527556
Language        =Eng
_MC("relation for array not known")
.

//------------------------------------------------------------------------
/*1209*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527557
Language        =Eng
_MC("field for array not known")
.

//------------------------------------------------------------------------
/*1210*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527558
Language        =Eng
_MC("array subscript computation error")
.

//------------------------------------------------------------------------
/*1211*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527559
Language        =Eng
_MC("expected field node")
.

//------------------------------------------------------------------------
/*1212*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527560
Language        =Eng
_MC("invalid BLOB ID")
.

//------------------------------------------------------------------------
/*1213*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527561
Language        =Eng
_MC("cannot find BLOB page")
.

//------------------------------------------------------------------------
/*1214*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527562
Language        =Eng
_MC("unknown data type")
.

//------------------------------------------------------------------------
/*1215*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527563
Language        =Eng
_MC("shadow block not found for extend file")
.

//------------------------------------------------------------------------
/*1216*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527564
Language        =Eng
_MC("index inconsistent")
.

//------------------------------------------------------------------------
/*1217*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527565
Language        =Eng
_MC("index bucket overfilled")
.

//------------------------------------------------------------------------
/*1218*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527566
Language        =Eng
_MC("exceeded index level")
.

//------------------------------------------------------------------------
/*1219*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527567
Language        =Eng
_MC("page already in use")
.

//------------------------------------------------------------------------
/*1220*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527568
Language        =Eng
_MC("page not accessed for write")
.

//------------------------------------------------------------------------
/*1221*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527569
Language        =Eng
_MC("attempt to release page not acquired")
.

//------------------------------------------------------------------------
/*1222*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527570
Language        =Eng
_MC("page in use during flush")
.

//------------------------------------------------------------------------
/*1223*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527571
Language        =Eng
_MC("attempt to remove page from dirty page list when not there")
.

//------------------------------------------------------------------------
/*1224*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527572
Language        =Eng
_MC("CCH_precedence: block marked")
.

//------------------------------------------------------------------------
/*1225*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527573
Language        =Eng
_MC("insufficient cache size")
.

//------------------------------------------------------------------------
/*1226*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527574
Language        =Eng
_MC("no cache buffers available for reuse")
.

//------------------------------------------------------------------------
/*1227*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527575
Language        =Eng
_MC("page %1, page type %2 lock conversion denied")
.

//------------------------------------------------------------------------
/*1228*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527576
Language        =Eng
_MC("page %1, page type %2 lock denied")
.

//------------------------------------------------------------------------
/*1229*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527577
Language        =Eng
_MC("buffer marked for update")
.

//------------------------------------------------------------------------
/*1230*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527578
Language        =Eng
_MC("CCH: %1, status = %2 (218)")
.

//------------------------------------------------------------------------
/*1231*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527579
Language        =Eng
_MC("request of unknown resource")
.

//------------------------------------------------------------------------
/*1232*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527580
Language        =Eng
_MC("release of unknown resource")
.

//------------------------------------------------------------------------
/*1233*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527581
Language        =Eng
_MC("(CMP) copy: cannot remap")
.

//------------------------------------------------------------------------
/*1234*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527582
Language        =Eng
_MC("bad BLR -- invalid stream")
.

//------------------------------------------------------------------------
/*1235*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527583
Language        =Eng
_MC("argument of scalar operation must be an array")
.

//------------------------------------------------------------------------
/*1236*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527584
Language        =Eng
_MC("quad word arithmetic not supported")
.

//------------------------------------------------------------------------
/*1237*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527585
Language        =Eng
_MC("data type not supported for arithmetic")
.

//------------------------------------------------------------------------
/*1238*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527586
Language        =Eng
_MC("request size limit exceeded")
.

//------------------------------------------------------------------------
/*1239*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527587
Language        =Eng
_MC("cannot access field %1 in view %2")
.

//------------------------------------------------------------------------
/*1240*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527588
Language        =Eng
_MC("cannot access field in view %1")
.

//------------------------------------------------------------------------
/*1241*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527589
Language        =Eng
_MC("EVL_assign_to: invalid operation")
.

//------------------------------------------------------------------------
/*1242*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527590
Language        =Eng
_MC("EVL_bitmap: invalid operation")
.

//------------------------------------------------------------------------
/*1243*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527591
Language        =Eng
_MC("EVL_boolean: invalid operation")
.

//------------------------------------------------------------------------
/*1244*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527592
Language        =Eng
_MC("EVL_expr: invalid operation")
.

//------------------------------------------------------------------------
/*1245*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527593
Language        =Eng
_MC("eval_statistical: invalid operation")
.

//------------------------------------------------------------------------
/*1246*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527594
Language        =Eng
_MC("Unimplemented conversion, FAO directive O,Z,S")
.

//------------------------------------------------------------------------
/*1247*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527595
Language        =Eng
_MC("Unimplemented conversion, FAO directive X,U")
.

//------------------------------------------------------------------------
/*1248*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527596
Language        =Eng
_MC("Error parsing RDB FAO msg string")
.

//------------------------------------------------------------------------
/*1249*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527597
Language        =Eng
_MC("Error parsing RDB FAO msg str")
.

//------------------------------------------------------------------------
/*1250*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527598
Language        =Eng
_MC("unknown parameter in RdB status vector")
.

//------------------------------------------------------------------------
/*1251*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527599
Language        =Eng
_MC("Firebird status vector inconsistent")
.

//------------------------------------------------------------------------
/*1252*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527600
Language        =Eng
_MC("Firebird/RdB message parameter inconsistency")
.

//------------------------------------------------------------------------
/*1253*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527601
Language        =Eng
_MC("error parsing RDB FAO message string")
.

//------------------------------------------------------------------------
/*1254*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527602
Language        =Eng
_MC("unimplemented FAO directive")
.

//------------------------------------------------------------------------
/*1255*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527603
Language        =Eng
_MC("missing pointer page in DPM_data_pages")
.

//------------------------------------------------------------------------
/*1256*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527604
Language        =Eng
_MC("Fragment does not exist")
.

//------------------------------------------------------------------------
/*1257*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527605
Language        =Eng
_MC("pointer page disappeared in DPM_delete")
.

//------------------------------------------------------------------------
/*1258*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527606
Language        =Eng
_MC("pointer page lost from DPM_delete_relation")
.

//------------------------------------------------------------------------
/*1259*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527607
Language        =Eng
_MC("missing pointer page in DPM_dump")
.

//------------------------------------------------------------------------
/*1260*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527608
Language        =Eng
_MC("cannot find record fragment")
.

//------------------------------------------------------------------------
/*1261*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527609
Language        =Eng
_MC("pointer page vanished from DPM_next")
.

//------------------------------------------------------------------------
/*1262*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527610
Language        =Eng
_MC("temporary page buffer too small")
.

//------------------------------------------------------------------------
/*1263*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527611
Language        =Eng
_MC("damaged data page")
.

//------------------------------------------------------------------------
/*1264*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527612
Language        =Eng
_MC("header fragment length changed")
.

//------------------------------------------------------------------------
/*1265*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527613
Language        =Eng
_MC("pointer page vanished from extend_relation")
.

//------------------------------------------------------------------------
/*1266*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527614
Language        =Eng
_MC("pointer page vanished from relation list in locate_space")
.

//------------------------------------------------------------------------
/*1267*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527615
Language        =Eng
_MC("cannot find free space")
.

//------------------------------------------------------------------------
/*1268*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527616
Language        =Eng
_MC("pointer page vanished from mark_full")
.

//------------------------------------------------------------------------
/*1269*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527617
Language        =Eng
_MC("bad record in RDB$PAGES")
.

//------------------------------------------------------------------------
/*1270*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527618
Language        =Eng
_MC("page slot not empty")
.

//------------------------------------------------------------------------
/*1271*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527619
Language        =Eng
_MC("bad pointer page")
.

//------------------------------------------------------------------------
/*1272*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527620
Language        =Eng
_MC("index unexpectedly deleted")
.

//------------------------------------------------------------------------
/*1273*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527621
Language        =Eng
_MC("scalar operator used on field which is not an array")
.

//------------------------------------------------------------------------
/*1274*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527622
Language        =Eng
_MC("active")
.

//------------------------------------------------------------------------
/*1275*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527623
Language        =Eng
_MC("committed")
.

//------------------------------------------------------------------------
/*1276*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527624
Language        =Eng
_MC("rolled back")
.

//------------------------------------------------------------------------
/*1277*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527625
Language        =Eng
_MC("in an ill-defined state")
.

//------------------------------------------------------------------------
/*1278*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527626
Language        =Eng
_MC("next transaction older than oldest active transaction")
.

//------------------------------------------------------------------------
/*1279*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527627
Language        =Eng
_MC("next transaction older than oldest transaction")
.

//------------------------------------------------------------------------
/*1280*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527628
Language        =Eng
_MC("buffer marked during cache unwind")
.

//------------------------------------------------------------------------
/*1281*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527629
Language        =Eng
_MC("error in recovery! database corrupted")
.

//------------------------------------------------------------------------
/*1282*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527630
Language        =Eng
_MC("error in recovery! wrong data page record")
.

//------------------------------------------------------------------------
/*1283*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527631
Language        =Eng
_MC("error in recovery! no space on data page")
.

//------------------------------------------------------------------------
/*1284*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527632
Language        =Eng
_MC("error in recovery! wrong header page record")
.

//------------------------------------------------------------------------
/*1285*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527633
Language        =Eng
_MC("error in recovery! wrong generator page record")
.

//------------------------------------------------------------------------
/*1286*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527634
Language        =Eng
_MC("error in recovery! wrong b-tree page record")
.

//------------------------------------------------------------------------
/*1287*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527635
Language        =Eng
_MC("error in recovery! wrong page inventory page record")
.

//------------------------------------------------------------------------
/*1288*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527636
Language        =Eng
_MC("error in recovery! wrong pointer page record")
.

//------------------------------------------------------------------------
/*1289*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527637
Language        =Eng
_MC("error in recovery! wrong index root page record")
.

//------------------------------------------------------------------------
/*1290*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527638
Language        =Eng
_MC("error in recovery! wrong transaction page record")
.

//------------------------------------------------------------------------
/*1291*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527639
Language        =Eng
_MC("error in recovery! out of sequence log record encountered")
.

//------------------------------------------------------------------------
/*1292*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527640
Language        =Eng
_MC("error in recovery! unknown page type")
.

//------------------------------------------------------------------------
/*1293*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527641
Language        =Eng
_MC("error in recovery! unknown record type")
.

//------------------------------------------------------------------------
/*1294*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527642
Language        =Eng
_MC("journal server cannot archive to specified archive directory")
.

//------------------------------------------------------------------------
/*1295*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527643
Language        =Eng
_MC("checksum error in log record when reading from log file")
.

//------------------------------------------------------------------------
/*1296*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527644
Language        =Eng
_MC("cannot restore singleton select data")
.

//------------------------------------------------------------------------
/*1297*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527645
Language        =Eng
_MC("lock not found in internal lock manager")
.

//------------------------------------------------------------------------
/*1298*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527646
Language        =Eng
_MC("size of opt block exceeded")
.

//------------------------------------------------------------------------
/*1299*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527647
Language        =Eng
_MC("Too many savepoints")
.

//------------------------------------------------------------------------
/*1300*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527648
Language        =Eng
_MC("garbage collect record disappeared")
.

//------------------------------------------------------------------------
/*1301*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527649
Language        =Eng
_MC("Unknown BLOB FILTER ACTION_")
.

//------------------------------------------------------------------------
/*1302*/
MessageId       =IBP_MCE_FB25__SAVEPOINT_ERROR
Language        =Eng
_MC("error during savepoint backout")
.

//------------------------------------------------------------------------
/*1303*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527651
Language        =Eng
_MC("cannot find record back version")
.

//------------------------------------------------------------------------
/*1304*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527652
Language        =Eng
_MC("Illegal user_type.")
.

//------------------------------------------------------------------------
/*1305*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527653
Language        =Eng
_MC("bad ACL")
.

//------------------------------------------------------------------------
/*1306*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527654
Language        =Eng
_MC("inconsistent LATCH_mark release")
.

//------------------------------------------------------------------------
/*1307*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527655
Language        =Eng
_MC("inconsistent LATCH_mark call")
.

//------------------------------------------------------------------------
/*1308*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527656
Language        =Eng
_MC("inconsistent latch downgrade call")
.

//------------------------------------------------------------------------
/*1309*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527657
Language        =Eng
_MC("bdb is unexpectedly marked")
.

//------------------------------------------------------------------------
/*1310*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527658
Language        =Eng
_MC("missing exclusive latch")
.

//------------------------------------------------------------------------
/*1311*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527659
Language        =Eng
_MC("exceeded maximum number of shared latches on a bdb")
.

//------------------------------------------------------------------------
/*1312*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527660
Language        =Eng
_MC("can't find shared latch")
.

//------------------------------------------------------------------------
/*1313*/
MessageId       =IBP_MCE_FB25__CACHE_NON_ZERO_USE_COUNT
Language        =Eng
_MC("Non-zero use_count of a buffer in the empty que")
.

//------------------------------------------------------------------------
/*1314*/
MessageId       =IBP_MCE_FB25__UNEXPECTED_PAGE_CHANGE
Language        =Eng
_MC("Unexpected page change from latching")
.

//------------------------------------------------------------------------
/*1315*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527663
Language        =Eng
_MC("Invalid expression for evaluation")
.

//------------------------------------------------------------------------
/*1316*/
MessageId       =IBP_MCE_FB25__RDB_TRIGGERS_RDB_FLAGS_CORRUPT
Language        =Eng
_MC("RDB$FLAGS for trigger %1 in RDB$TRIGGERS is corrupted")
.

//------------------------------------------------------------------------
/*1317*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527665
Language        =Eng
_MC("Blobs accounting is inconsistent")
.

//------------------------------------------------------------------------
/*1318*/
MessageId       =IBP_MCE_FB25__INTERNAL_MSG_336527666
Language        =Eng
_MC("Found array data type with more than 16 dimensions")
.

////////////////////////////////////////////////////////////////////////////////
