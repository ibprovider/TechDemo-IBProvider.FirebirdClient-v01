////////////////////////////////////////////////////////////////////////////////
//LCPI OLEDB Provider for InterBase/Firebird SDK.
//                                                 Kovalenko Dmitry. 25.01.2019
#ifndef _lcpi_sdk__ibprovider__v05__props_ids_H_
#define _lcpi_sdk__ibprovider__v05__props_ids_H_

#include <oledb.h>

namespace lcpi{namespace sdk{namespace ibprovider{namespace v05{
////////////////////////////////////////////////////////////////////////////////
//Идентификаторы специфических наборов свойств

//! \ingroup ibp_oledb__props_init
/// <summary>
///  Идентификатор набора свойств инициализации подключения.
/// <summary>
extern const GUID IBP_DBPROPSET_INIT;

//! \ingroup ibp_oledb__props_info
/// <summary>
///  Идентификатор набора информационных свойств подключения.
/// </summary>
extern const GUID IBP_DBPROPSET_DATASOURCEINFO;

//! \ingroup ibp_oledb__props_session
/// <summary>
///  Идентификатор набора свойств сессии.
/// </summary>
extern const GUID IBP_DBPROPSET_SESSION;

//! \ingroup ibp_oledb__props_rowset
/// <summary>
///  Идентификатор набора специфических свойств множества и команды.
/// </summary>
extern const GUID IBP_DBPROPSET_ROWSET;

//! \ingroup ibp_oledb__props_rowset
/// <summary>
///  Идентификатор набора информационных свойств множества.
/// </summary>
extern const GUID IBP_DBPROPSET_ROWSETINFO;

//! \ingroup ibp_oledb__props_rowset
/// <summary>
///  Идентификатор набора информационных свойств запроса.
/// </summary>
extern const GUID IBP_DBPROPSET_STATEMENTINFO;

//! \ingroup ibp_oledb__props_ds_create
/// <summary>
///  Идентификатор набора свойств новой базы данных.
/// </summary>
extern const GUID IBP_DBPROPSET_DATASOURCECREATE;

////////////////////////////////////////////////////////////////////////////////
//data source init properties

//! \addtogroup ibp_oledb__props_init
//! @{
//------------------------------------------------------------------------

/// <summary>
///  Символьный идентификатор кодовой страницы подключения к базе данных.
///  Default="".
/// </summary>
const DBPROPID IBP_DBPROP__INIT__CTYPE                          =0x0001;

//------------------------------------------------------------------------
//const DBPROPID IBP_DBPROP__INIT__CMESSAGE                     =0x0002;

//------------------------------------------------------------------------
/// <summary>
///  Роль пользователя.
///  Default:Empty.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__ROLENAME                       =0x0003;

//------------------------------------------------------------------------
/// <summary>
///  Размер буфера в страницах под кэш базы данных.
///  Default:Empty.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__NUM_BUFFERS                    =0x0004;

//------------------------------------------------------------------------

/// <summary>
///  System Encryption Password. Required for encrypted database.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SYS_ENCRYPT_PASSWORD           =0x0005;

//------------------------------------------------------------------------
/// <summary>
///  Разрешение на сборку мусора в рамках подключения.
///  Default:true.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__GARBAGE_COLLECT                =0x0006;

//------------------------------------------------------------------------
/// <summary>
///  Диалект подключения к базе данных.
///  Default:Empty.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SQL_DIALECT                    =0x0007;

//------------------------------------------------------------------------
/// <summary>
///  Разрешение автоматического старта и подтверждения транзакций.
///  Default:false.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__AUTOCOMMIT                     =0x0008;

//------------------------------------------------------------------------
/// <summary>
///  Уровень изоляции автоматических транзакций.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__AUTOCOMMITLEVEL                =0x0009;

//------------------------------------------------------------------------
/// <summary>
///  Произвольный доступ к результирующему множеству по-умолчанию.
///  Default:false.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__BICURSOR                       =0x000A;

//------------------------------------------------------------------------
//Deleted [2017-01-26]

// /// <summary>
// ///  "Включение" поддержки многопоточного доступа.
// ///  Default:true.
// /// </summary>
// //! Имя свойства: "Data Source Object Threading". Интерпретация значений:
// //!  - false - DBPROPVAL_RT_APTMTTHREAD
// //!  - true  - DBPROPVAL_RT_FREETHREAD|DBPROPVAL_RT_APTMTTHREAD
// const DBPROPID IBP_DBPROP__INIT__FREE_THREADING              =0x000B;

//------------------------------------------------------------------------
//const DBPROPID IBP_DBPROP__INIT__ARRAY_VT_TYPE                =0x000C;

//------------------------------------------------------------------------
/// <summary>
///  Разрешение внутренних транзакций для получения метаданных.
///  Default:true.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__INNER_TRANS                    =0x000D;

//------------------------------------------------------------------------
/// <summary>
///  Обрезание завершающих пробелов в строках типа CHAR.
///  Default:true.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__TRUNCATE_CHAR                  =0x000E;

//------------------------------------------------------------------------
/// <summary>
///  Режим кеширования метаданных.
///  Default: ibp::ibp_propval_schema_cache_data_source.
/// </summary>
/// <seealso cref="ibp::t_ibp_propval_schema_cache"/>
const DBPROPID IBP_DBPROP__INIT__SCHEMA_CACHE                   =0x000F;

//------------------------------------------------------------------------
/// <summary>
///  Поддержка ODBC-представления символов в тексте запроса.
///  Default:false.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SUPPORT_ODBC_QUERY             =0x0010;

//------------------------------------------------------------------------
/// <summary>
///  Подготовка и определение параметров запроса при установке текста команды.
///  Default:false.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__FORCE_PREPARE_STMT             =0x0011;

//------------------------------------------------------------------------
/// <summary>
///  Разрешение на представление текстовых данных в виде UNICODE-строк.
///  Default:true.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__UNICODE_MODE                   =0x0012;

//------------------------------------------------------------------------
//const DBPROPID IBP_DBPROP__INIT__UNICODE_STMT                 =0x0013;

//------------------------------------------------------------------------
//const DBPROPID IBP_DBPROP__INIT__STD_EXEC_SP                  =0x0014;

//------------------------------------------------------------------------
/// <summary>
///  Разрешение на очистку списка параметров при установке текста запроса.
///  Default:false.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__CLEAR_PARAM_INFO               =0x0015;

//------------------------------------------------------------------------
/// <summary>
///  Разрешение на автоматическое формирование списка параметров.
///  Default:true.
/// </summary>
/// Применяется только при пустом списке описаний.
const DBPROPID IBP_DBPROP__INIT__AUTO_PARAM_DESCRIBE            =0x0016;

//------------------------------------------------------------------------
//const DBPROPID IBP_DBPROP__INIT__FORCE_PARAM_DESCRIBE         =0x0017;

//------------------------------------------------------------------------
/// <summary>
///  Префикс именованных параметров.
///  Default=':'.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__NAMED_PARAM_PREFIX             =0x0018;

//------------------------------------------------------------------------
/// <summary>
///  Игнорирование команды на Unprepare запроса.
///  Default:true.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__IGNORE_UNPREPARE               =0x0019;

//------------------------------------------------------------------------
/// <summary>
///  Транслирование запроса "exec SP" в запрос с именованными параметрами.
///  Default:false.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__EXEC_SP_NAMED_PARAM            =0x001A;

//------------------------------------------------------------------------
// /// <summary>
// ///  Режим транслирования запроса "{call SP(...)}".
// ///  Default: ibp::ibp_propval_odbc_call_sp_detect.
// /// </summary>
// /// <seealso cref="ibp::t_ibp_propval_odbc_call_sp"/>
// const DBPROPID IBP_DBPROP__INIT__ODBC_CALL_SP                =0x001B;

//------------------------------------------------------------------------
/// <summary>
///  Режимы выполнения DDL запросов.
///  Default: ibp::ibp_propval_auto_commit_ddl_none.
/// </summary>
/// <seealso cref="ibp::t_ibp_propval_auto_commit_ddl"/>
const DBPROPID IBP_DBPROP__INIT__AUTO_COMMIT_DDL                =0x001C;

//------------------------------------------------------------------------
/// <summary>
///  Уровень изоляции для выделенной транзации DDL запросов.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__AUTO_COMMIT_DDL_LEVEL          =0x001D;

//------------------------------------------------------------------------
/// <summary>
///  Порог (в KB) включения менеджера виртуальной памяти, для
///  выделения памяти под кэш результирующих множеств.
/// </summary>
/// <list>
///  <item> если равен 0, то всегда будет использоваться VM.</item>
///  <item> если меньше 0, то всегда будет использоваться память из кучи.</item>
/// </list>
const DBPROPID IBP_DBPROP__INIT__ROWSET_VM_USING                =0x001E;

//------------------------------------------------------------------------
/// <summary>
///  Разрешение на включение поддержки вложенных транзакций.
///  Default: false.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__NESTED_TRANS                   =0x001F;

//------------------------------------------------------------------------
// /// <summary>
// ///  Режим транслирования запроса "exec sp".
// ///  Default: ibp::ibp_propval_ado_exec_sp_detect.
// /// </summary>
// /// <seealso cref="ibp::t_ibp_propval_ado_exec_sp"/>
// const DBPROPID IBP_DBPROP__INIT__ADO_EXEC_SP                 =0x0020;

//------------------------------------------------------------------------
// [2019-03-11] IBProvider v5.2
// /// <summary>
// ///  Режим публикации схем PROCEDURE_PARAMETERS, PROCEDURE_COLUMNS.
// ///  Default: ibp::ibp_propval_schema_sp_params__detect.
// /// </summary>
// /// <seealso cref="t_ibp_propval_schema_sp_params"/>
// const DBPROPID IBP_DBPROP__INIT__SCHEMA_SP_PARAMS            =0x0021;

//------------------------------------------------------------------------
/// <summary>
///  Флаги игнорирования ошибок в параметрах команды.
///  Default: 0.
/// </summary>
/// Поддерживаемые флаги перечислены в ibp::t_ibp_propval_ignore_err_param
const DBPROPID IBP_DBPROP__INIT__IGNORE_ERR_PARAM               =0x0022;

//------------------------------------------------------------------------
/// <summary>
///  Правила управления вложенными транзакциями
/// </summary>
const DBPROPID IBP_DBPROP__INIT__NESTED_TRANS_RULES             =0x0023;

//настройки клиента к серверу --------------------------------------------
/// <summary>
///  Файловый путь к DLL с серверным клиентом.
/// </summary>
/// \sa IBP_DBPROP__INIT__DBCLIENT_LIBRARY_64
const DBPROPID IBP_DBPROP__INIT__DBCLIENT_LIBRARY               =0x0030;

//------------------------------------------------------------------------
/// <summary>
///  Тип сервера базы данных.
/// </summary>
/// На текущий момент используется для автоматического формирования
/// значения свойства ibp::IBP_DBPROP__INIT__DBCLIENT_LIBRARY
const DBPROPID IBP_DBPROP__INIT__DBCLIENT_TYPE                  =0x0031;

//------------------------------------------------------------------------
/// <summary>
///  Обработка имен объектов базы данных, заключенных в квадратные скобки.
///  Default: 0
/// </summary>
//! <seealso cref="ibp::t_ibp_propval_support_square_delim_name"/>
const DBPROPID IBP_DBPROP__INIT__SUPPORT_SQUARE_DELIM_NAME      =0x0032;

//------------------------------------------------------------------------
/// <summary>
///  Режимы публикации ключевых слов через IDBInfo::GetKeywords.
///  Default: 0
/// </summary>
/// <seealso cref="ibp::t_ibp_propval_keywords_list"/>
const DBPROPID IBP_DBPROP__INIT__KEYWORDS_LIST                  =0x0033;

//------------------------------------------------------------------------
/// <summary>
///  Номер первого дня недели [1..7]. Допускается установка символьного имени.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__FIRST_WEEK_DAY                 =0x0034;

//------------------------------------------------------------------------
/// <summary>
///  Флаги отката транзакции
/// </summary>
const DBPROPID IBP_DBPROP__INIT__TR_ABORT_FLAGS                 =0x0035;

//------------------------------------------------------------------------
/// <summary>
///  Разрешение выполнять триггеры уровня базы данных
/// </summary>
const DBPROPID IBP_DBPROP__INIT__ENABLE_DB_TRIGGERS             =0x0036;

//------------------------------------------------------------------------
/// <summary>
///  Правила формирования описания колонок и параметров с массивами
/// </summary>
const DBPROPID IBP_DBPROP__INIT__ARRAY_TYPE                     =0x0037;

//------------------------------------------------------------------------
/// <summary>
///  Правила сброса источника данных при наличии активных транзакций
/// </summary>
const DBPROPID IBP_DBPROP__INIT__RESET_DS_TR_RULE               =0x0038;

//------------------------------------------------------------------------
/// <summary>
///  Правила обработки NUMERIC_I2
/// </summary>
const DBPROPID IBP_DBPROP__INIT__NUMERIC_I2_RULES               =0x0039;

//------------------------------------------------------------------------
/// <summary>
///  Правила обработки NUMERIC_I4
/// </summary>
const DBPROPID IBP_DBPROP__INIT__NUMERIC_I4_RULES               =0x003A;

//------------------------------------------------------------------------
/// <summary>
///  Правила обработки NUMERIC_I8
/// </summary>
const DBPROPID IBP_DBPROP__INIT__NUMERIC_I8_RULES               =0x003B;

//------------------------------------------------------------------------
/// <summary>
///  Файловый путь к внешней библиотеке ICU
/// </summary>
/// \sa IBP_DBPROP__INIT__ICU_LIBRARY_64
const DBPROPID IBP_DBPROP__INIT__ICU_LIBRARY                    =0x003C;

//------------------------------------------------------------------------
/// <summary>
///  Правила блокирования DLL с серверным клиентом
/// </summary>
const DBPROPID IBP_DBPROP__INIT__DBCLIENT_LOCK_RULES            =0x003D;

//------------------------------------------------------------------------
/// <summary>
///  Имя кодовой страницы пользователя
/// </summary>
const DBPROPID IBP_DBPROP__INIT__CTYPE_USER                     =0x003E;

//------------------------------------------------------------------------
/// <summary>
///  Имя кодовой страницы для интерпретации NONE
/// </summary>
const DBPROPID IBP_DBPROP__INIT__CTYPE_NONE                     =0x003F;

//------------------------------------------------------------------------
/// <summary>
///  Имя домена эмулирующего тип BOOLEAN
/// </summary>
const DBPROPID IBP_DBPROP__INIT__USER_TYPE_BOOLEAN              =0x0040;

//------------------------------------------------------------------------
/// <summary>
///  Имя домена эмулирующего тип GUID
/// </summary>
const DBPROPID IBP_DBPROP__INIT__USER_TYPE_GUID                 =0x0041;

//------------------------------------------------------------------------
/// <summary>
///  Время жизни ресурса в пуле запросов.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__STMT_CACHE__TIME               =0x0042;

//------------------------------------------------------------------------
/// <summary>
///  Максимальное число ресурсов в пуле запросов
/// </summary>
const DBPROPID IBP_DBPROP__INIT__STMT_CACHE__SIZE               =0x0043;

//------------------------------------------------------------------------
/// <summary>
///  Время жизни подготовленного запроса в пуле запросов.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__STMT_CACHE__REQ_LIFE_TIME      =0x0044;

//------------------------------------------------------------------------
/// <summary>
///  Настройка режима работы системы с временными файлами наборов рядов
/// </summary>
const DBPROPID IBP_DBPROP__INIT__ROWSET_FILE__SYS_FLAGS         =0x0045;

//------------------------------------------------------------------------
/// <summary>
///  Максимальный размер блока в KB, который может быть использован при выгрузке в файл.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__ROWSET_FILE__WRITE_BLOCK_SIZE  =0x0046;

//------------------------------------------------------------------------
/// <summary>
///  Значение по-умолчаниб для свойства набора рядов "Memory Usage"
/// </summary>
const DBPROPID IBP_DBPROP__INIT__ROWSET__MEMORY_USAGE           =0x0047;

//------------------------------------------------------------------------
/// <summary>
///  Каталог для размещения временных файлов
/// </summary>
const DBPROPID IBP_DBPROP__INIT__TEMP_FILE_DIR                  =0x0048;

//------------------------------------------------------------------------
/// <summary>
///  Правила работы с отложенными данными в результирующих наборах
/// </summary>
/// \sa ibp::t_ibp_propval__deferred_data_rule
const DBPROPID IBP_DBPROP__INIT__DEFERRED_DATA                  =0x0049;

//------------------------------------------------------------------------
/// <summary>
///  Настройка OLEDB-типа для представления TIME-данных
/// </summary>
/// \sa t_ibp_propval_dbtime_rules
const DBPROPID IBP_DBPROP__INIT__DBTIME_RULES                   =0x004A;

//------------------------------------------------------------------------
/// <summary>
///  Настройка OLEDB-типа для представления TIMESTAMP-данных
/// </summary>
/// \sa t_ibp_propval_dbtimestamp_rules
const DBPROPID IBP_DBPROP__INIT__DBTIMESTAMP_RULES              =0x004B;

//------------------------------------------------------------------------
/// <summary>
///  Правила выполнения скриптов
/// </summary>
//! \sa t_ibp_propval__multi_stmts_exec_rules
const DBPROPID IBP_DBPROP__INIT__MULTI_STMTS_EXEC_RULES         =0x004C;

//------------------------------------------------------------------------
/// <summary>
///  Правила работы с отложенными данными OUT-параметров
/// </summary>
/// \sa ibp::t_ibp_propval__deferred_data_rule
const DBPROPID IBP_DBPROP__INIT__DEFERRED_OUT_PARAM             =0x004D;

//------------------------------------------------------------------------
/// <summary>
///  Настройка памяти под кэш хранилища временных данных
/// </summary>
//! - 0. Размер по умолчанию
//! - [1..99]. Процент от доступной оперативной памяти
//! - >=100. Размер в килобайтах.
const DBPROPID IBP_DBPROP__INIT__TEMP_STG__MEMORY_USAGE         =0x004E;

//------------------------------------------------------------------------
/// <summary>
///  Параметры уровня изоляции "read committed"
/// </summary>
const DBPROPID IBP_DBPROP__INIT__IB_TR_PARAMS__READ_COMMITTED   =0x004F;

//------------------------------------------------------------------------
/// <summary>
///  Параметры уровня изоляции "repeatable read"
/// </summary>
const DBPROPID IBP_DBPROP__INIT__IB_TR_PARAMS__REPEATABLE_READ  =0x0050;

//------------------------------------------------------------------------
/// <summary>
///  Параметры уровня изоляции "serializable"
/// </summary>
const DBPROPID IBP_DBPROP__INIT__IB_TR_PARAMS__SERIALIZABLE     =0x0051;

//------------------------------------------------------------------------
/// <summary>
///  Поддержка выполнения запросов через IOpenRowset::OpenRowset
/// </summary>
const DBPROPID IBP_DBPROP__INIT__OPEN_ROWSET__SQL               =0x0052;

//------------------------------------------------------------------------
/// <summary>
///  Правила для именованных параметров в тексте запроса
/// </summary>
/// <seealso cref="t_ibp_propval__named_param_rules"/>
const DBPROPID IBP_DBPROP__INIT__NAMED_PARAM_RULES              =0x0053;

//------------------------------------------------------------------------
/// <summary>
///  Асинхронный фетч результирующих множеств.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__ASYNCH_FETCH                   =0x0054;

//------------------------------------------------------------------------
/// <summary>
///  Правила сброса источника данных при наличии подписчиков у сессии
/// </summary>
const DBPROPID IBP_DBPROP__INIT__RESET_DS_SESSION_SINKS_RULE    =0x0055;

//------------------------------------------------------------------------
/// <summary>
///  Файловый путь к DLL с 64-битным серверным клиентом.
/// </summary>
/// \sa IBP_DBPROP__INIT__DBCLIENT_LIBRARY
const DBPROPID IBP_DBPROP__INIT__DBCLIENT_LIBRARY_64            =0x0056;

//------------------------------------------------------------------------
/// <summary>
///  Файловый путь к внешней 64-битной библиотеке ICU
/// </summary>
/// \sa IBP_DBPROP__INIT__ICU_LIBRARY
const DBPROPID IBP_DBPROP__INIT__ICU_LIBRARY_64                 =0x0057;

//------------------------------------------------------------------------
/// <summary>
///  Конфигурация загрузчика схем метаданных. Публикация CHECK.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SCHEMA_LDR_CFG__CHECK_CONSTRAINTS   =0x0058;

//------------------------------------------------------------------------
#if !defined(IBP_ENGINE_DIRECT_FB) || (IBP_ENGINE_DIRECT_FB!=0)

/// <summary>
///  RemoteConnection: имя типа протокола соединения
/// </summary>
const DBPROPID IBP_DBPROP__INIT__REMOTE__PROTOCOL_TYPE          =0x0059;

//------------------------------------------------------------------------
/// <summary>
///  RemoteConnection: идентификатор протокола соединения
/// </summary>
const DBPROPID IBP_DBPROP__INIT__REMOTE__PROTOCOL               =0x005A;

//------------------------------------------------------------------------
/// <summary>
///  RemoteConnection: шифрование соединения с сервером базы данных
/// </summary>
const DBPROPID IBP_DBPROP__INIT__REMOTE__WIRE_CRYPT             =0x005B;

//------------------------------------------------------------------------
/// <summary>
///  RemoteConnection: имя сервиса аутентификации
/// </summary>
const DBPROPID IBP_DBPROP__INIT__REMOTE__AUTH                   =0x005C;

//------------------------------------------------------------------------
/// <summary>
///  RemoteConnection: сжатие данных
/// </summary>
const DBPROPID IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION       =0x005D;

//------------------------------------------------------------------------
/// <summary>
///  RemoteConnection: DLL с компрессором данных
/// </summary>
const DBPROPID IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY    =0x005E;

//------------------------------------------------------------------------
/// <summary>
///  RemoteConnection: 64-битная DLL с компрессором данных
/// </summary>
const DBPROPID IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY_64 =0x005F;

//------------------------------------------------------------------------
/// <summary>
///  RemoteConnection: имя архитектуры протокола соединения
/// </summary>
//!  Допускается несколько значений, перечисленных через запятую.
//!  Приоритет получают значения определенные в начале списка.
const DBPROPID IBP_DBPROP__INIT__REMOTE__PROTOCOL_ARCHITECTURE  =0x0060;

#endif //IBP_ENGINE_DIRECT_FB!=0

//------------------------------------------------------------------------
/// <summary>
///  Режим чтения/записи массивов базы данных
/// </summary>
const DBPROPID IBP_DBPROP__INIT__ARRAY_RW_MODE                  =0x0061;

//------------------------------------------------------------------------
/// <summary>
///  Настройка OLEDB-типа для представления DATE-данных
/// </summary>
/// \sa t_ibp_propval_dbdate_rules
const DBPROPID IBP_DBPROP__INIT__DBDATE_RULES                   =0x0062;

//------------------------------------------------------------------------
// /// <summary>
// ///  Режим проверки состояния подключения к базе данных
// /// </summary>
// const DBPROPID IBP_DBPROP__INIT__CHECK_CN_STATUS             =0x0063;

//------------------------------------------------------------------------
/// <summary>
///  Правила формирования ошибок провайдера
/// </summary>
const DBPROPID IBP_DBPROP__INIT__PROVIDER_ERROR_RULES           =0x0064;

//------------------------------------------------------------------------
/// <summary>
///  Number of WCHAR symbols in one UTF8 symbol (1 or 2)
/// </summary>
const DBPROPID IBP_DBPROP__INIT__WCHARS_IN_UTF8_SYMBOL          =0x0065;

//------------------------------------------------------------------------
/// <summary>
///  Rules for schema restrictions processing
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SCHEMA_RESTRICTIONS            =0x0066;

//------------------------------------------------------------------------
/// <summary>
///  Rules for GUID data type processing
/// </summary>
const DBPROPID IBP_DBPROP__INIT__GUID_RULES                     =0x0067;

//------------------------------------------------------------------------
/// <summary>
///  Конфигурация загрузчика схем метаданных. Публикация описаний объектов
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SCHEMA_LDR_CFG__DESCRIPTIONS   =0x0068;

//------------------------------------------------------------------------
/// <summary>
///  Кэш парсера SQL-запросов. Максимальное количество элементов.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SQL_CACHE__SIZE                =0x0069;

//------------------------------------------------------------------------
/// <summary>
///  Кэш парсера SQL-запросов. Время жизни элемента.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SQL_CACHE__TIME                =0x006A;

//------------------------------------------------------------------------
/// <summary>
///  Кэш парсера SQL-запросов. Максимальная длина кэшируемого запроса в символах.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SQL_CACHE__MAX_LEN             =0x006B;

//------------------------------------------------------------------------
/// <summary>
///  Кэш парсера SQL-запросов. Область действия кэша запросов.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SQL_CACHE__SCOPE               =0x006C;

//------------------------------------------------------------------------
/// <summary>
///  Кэш парсера SQL-запросов. Идентификатор экземпляра.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__SQL_CACHE__INSTANCE_ID         =0x006D;

//------------------------------------------------------------------------
/// <summary>
///  Настройка OLEDB-типа для представления TIMESTAMP_WITH_TZ-данных
/// </summary>
/// \sa t_ibp_propval_dbtimestamp_with_tz_rules
const DBPROPID IBP_DBPROP__INIT__DBTIMESTAMP_WITH_TZ_RULES      =0x006E;

//------------------------------------------------------------------------
/// <summary>
///  Настройка OLEDB-типа для представления TIME_WITH_TZ-данных
/// </summary>
/// \sa t_ibp_propval_dbtime_with_tz_rules
const DBPROPID IBP_DBPROP__INIT__DBTIME_WITH_TZ_RULES           =0x006F;

//------------------------------------------------------------------------
/// <summary>
///  Настройка OLEDB-типа для представления INT128-данных
/// </summary>
/// \sa t_ibp_propval_int128_rules
const DBPROPID IBP_DBPROP__INIT__INT128_RULES                   =0x0070;

//------------------------------------------------------------------------
/// <summary>
///  Правила обработки NUMERIC_I16
/// </summary>
const DBPROPID IBP_DBPROP__INIT__NUMERIC_I16_RULES              =0x0071;

//------------------------------------------------------------------------
/// <summary>
///  Настройка OLEDB-типа для представления DECFLOAT(16)-данных
/// </summary>
/// \sa t_ibp_propval_decfloat_rules
const DBPROPID IBP_DBPROP__INIT__DECFLOAT16_RULES               =0x0072;

//------------------------------------------------------------------------
/// <summary>
///  Настройка OLEDB-типа для представления DECFLOAT(34)-данных
/// </summary>
/// \sa t_ibp_propval_decfloat_rules
const DBPROPID IBP_DBPROP__INIT__DECFLOAT34_RULES               =0x0073;

//------------------------------------------------------------------------
#if !defined(IBP_ENGINE_DIRECT_FB) || (IBP_ENGINE_DIRECT_FB!=0)

/// <summary>
///  RemoteConnection: тип компрессора данных подключения
/// </summary>
const DBPROPID IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_TYPE  =0x0080;

#endif //IBP_ENGINE_DIRECT_FB

//------------------------------------------------------------------------

/// <summary>
///  It allows to get null values for not null column/parameter.
/// </summary>
const DBPROPID IBP_DBPROP__INIT__FORCE_NULLS                    =0x0081;

//------------------------------------------------------------------------
//настройки хранилища обновляемого множества

#if !defined(IBP_ENGINE_UPDATE_ROWSET) || (IBP_ENGINE_UPDATE_ROWSET!=0)

//const DBPROPID IBP_DBPROP__INIT__QUERY_POOL_SIZE              =0x0100;
const DBPROPID IBP_DBPROP__INIT__AUTO_INSERT_FIELD_RULE         =0x0101;
const DBPROPID IBP_DBPROP__INIT__AUTO_UPDATE_FIELD_RULE         =0x0102;

/// <summary>
///  Настройка обратного чтения для запросов обновляемых множеств
/// </summary>
///  См. ibp_propval__server_data_back_read__xxxx
const DBPROPID IBP_DBPROP__INIT__SERVER_DATA_BACK_READ          =0x0103;

/// <summary>
///  Тип транзакции для модификации данных
/// </summary>
///  См. ibp_modify_trans_xxx
const DBPROPID IBP_DBPROP__INIT__MODIFY_TRANS_TYPE              =0x0110;

/// <summary>
///  Уровень изоляции выделенной транзакции для модификации данных
/// </summary>
const DBPROPID IBP_DBPROP__INIT__MODIFY_TRANS_LEVEL             =0x0111;

/// <summary>
///  Тип транзакции для перечитывания данных
/// </summary>
/// См. t_ibp_refresh_trans_type
const DBPROPID IBP_DBPROP__INIT__REFRESH_TRANS_TYPE             =0x0112;

/// <summary>
///  Уровень изоляции выделенной транзакции для перечитывания данных
/// </summary>
const DBPROPID IBP_DBPROP__INIT__REFRESH_TRANS_LEVEL            =0x0113;

/// <summary>
///  Включение поддержки обновляемых множеств
/// </summary>
const DBPROPID IBP_DBPROP__INIT__ENABLE_UPDATABLE_ROWSET        =0x0120;

#endif //IBP_ENGINE_UPDATE_ROWSET!=0

//------------------------------------------------------------------------
//! @}

////////////////////////////////////////////////////////////////////////////////
//command-rowset properties

//! \addtogroup ibp_oledb__props_rowset
//! @{
//------------------------------------------------------------------------

///Текст подготовленного запроса
const DBPROPID IBP_DBPROP__ROWSET__PREPARE_STMT                 =0x0001;

//const DBPROPID IBP_DBPROP__ROWSET__ARRAY_VT_TYPE              =0x0002;

///Локальный вариант свойства IBP_DBPROP__INIT__TRUNCATE_CHAR
const DBPROPID IBP_DBPROP__ROWSET__TRUNCATE_CHAR                =0x0003;

///Локальный вариант свойства IBP_DBPROP__INIT__ROWSET_VM_USING
const DBPROPID IBP_DBPROP__ROWSET__VM_USING                     =0x0004;

///Локальный вариант свойства IBP_DBPROP__INIT__ARRAY_TYPE
const DBPROPID IBP_DBPROP__ROWSET__ARRAY_TYPE                   =0x0005;

//-----------
///Настройка режима работы системы с временными файлами наборов рядов
const DBPROPID IBP_DBPROP__ROWSET__ROWSET_FILE__SYS_FLAGS       =0x0006;

///Максимальный размер блока в KB, который может быть использован при выгрузке в файл.
const DBPROPID IBP_DBPROP__ROWSET__ROWSET_FILE__WRITE_BLOCK_SIZE=0x0007;

//-----------
/// <summary>
///  Правила работы с отложенными данными в результирующих наборах
/// </summary>
/// \sa ibp::t_ibp_propval__deferred_data_rule
const DBPROPID IBP_DBPROP__ROWSET__DEFERRED_DATA                =0x0008;

#if !defined(IBP_ENGINE_UPDATE_ROWSET) || (IBP_ENGINE_UPDATE_ROWSET!=0)
//свойства установки запросов для управления обновляемым множеством
const DBPROPID IBP_DBPROP__ROWSET__DELETE_SQL                   =0x0010;
const DBPROPID IBP_DBPROP__ROWSET__INSERT_SQL                   =0x0011;
const DBPROPID IBP_DBPROP__ROWSET__UPDATE_SQL                   =0x0012;
const DBPROPID IBP_DBPROP__ROWSET__DISCONNECTED                 =0x0013;//набор отключенный от базы данных
//const DBPROPID IBP_DBPROP__ROWSET__QUERY_POOL_SIZE            =0x0014;//максимальное число закэшированных запросов

/// Запросы для загрузки текущего состояния рядов в БД
const DBPROPID IBP_DBPROP__ROWSET__REFRESH_SQL                  =0x0015;

//настройки автоматического режима обновления множества
const DBPROPID IBP_DBPROP__ROWSET__AUTO_GEN_KEY_RULE            =0x0030; //правила генерации первичных ключей
const DBPROPID IBP_DBPROP__ROWSET__AUTO_INSERT_FIELD_RULE       =0x0040; //ibp_auto_insert_rule_xxx
const DBPROPID IBP_DBPROP__ROWSET__AUTO_UPDATE_FIELD_RULE       =0x0050; //ibp_auto_update_rule_xxx

/// Локальный вариант для IBP_DBPROP__INIT__MODIFY_TRANS_TYPE
const DBPROPID IBP_DBPROP__ROWSET__MODIFY_TRANS_TYPE            =0x0060;

/// Локальный вариант для IBP_DBPROP__INIT__MODIFY_TRANS_LEVEL
const DBPROPID IBP_DBPROP__ROWSET__MODIFY_TRANS_LEVEL           =0x0061;

/// Локальный вариант для IBP_DBPROP__INIT__REFRESH_TRANS_TYPE
const DBPROPID IBP_DBPROP__ROWSET__REFRESH_TRANS_TYPE           =0x0062;

/// Локальный вариант для IBP_DBPROP__INIT__REFRESH_TRANS_LEVEL
const DBPROPID IBP_DBPROP__ROWSET__REFRESH_TRANS_LEVEL          =0x0063;

#endif //IBP_ENGINE_UPDATE_ROWSET!=0

////////////////////////////////////////////////////////////////////////////////
//command properties

/// Локальный вариант IBP_DBPROP__INIT__SUPPORT_ODBC_QUERY
const DBPROPID IBP_DBPROP__ROWSET__SUPPORT_ODBC_QUERY           =0x0100;

/// Локальный вариант IBP_DBPROP__INIT__FORCE_PREPARE_STMT
const DBPROPID IBP_DBPROP__ROWSET__FORCE_PREPARE_STMT           =0x0101;

//const DBPROPID IBP_DBPROP__ROWSET__STD_EXEC_SP                =0x0102;

/// Локальный вариант IBP_DBPROP__INIT__CLEAR_PARAM_INFO
const DBPROPID IBP_DBPROP__ROWSET__CLEAR_PARAM_INFO             =0x0103;

/// Локальный вариант IBP_DBPROP__INIT__AUTO_PARAM_DESCRIBE
const DBPROPID IBP_DBPROP__ROWSET__AUTO_PARAM_DESCRIBE          =0x0104;

//const DBPROPID IBP_DBPROP__ROWSET__FORCE_PARAM_DESCRIBE       =0x0105;

/// Локальный вариант IBP_DBPROP__INIT__NAMED_PARAM_PREFIX
const DBPROPID IBP_DBPROP__ROWSET__NAMED_PARAM_PREFIX           =0x0106;

/// Локальный вариант IBP_DBPROP__INIT__IGNORE_UNPREPARE
const DBPROPID IBP_DBPROP__ROWSET__IGNORE_UNPREPARE             =0x0107;

/// Локальный вариант IBP_DBPROP__INIT__EXEC_SP_NAMED_PARAM
const DBPROPID IBP_DBPROP__ROWSET__EXEC_SP_NAMED_PARAM          =0x0108;

// /// Локальный вариант IBP_DBPROP__INIT__ODBC_CALL_SP
// const DBPROPID IBP_DBPROP__ROWSET__ODBC_CALL_SP              =0x0109;

// /// Локальный вариант IBP_DBPROP__INIT__ADO_EXEC_SP
// const DBPROPID IBP_DBPROP__ROWSET__ADO_EXEC_SP               =0x010A;

/// Локальный вариант IBP_DBPROP__INIT__IGNORE_ERR_PARAM
const DBPROPID IBP_DBPROP__ROWSET__IGNORE_ERR_PARAM             =0x010B;

/// Локальный вариант IBP_DBPROP__INIT__SUPPORT_SQUARE_DELIM_NAME
const DBPROPID IBP_DBPROP__ROWSET__SUPPORT_SQUARE_DELIM_NAME    =0x010C;

const DBPROPID IBP_DBPROP__ROWSET__FIRST_WEEK_DAY               =0x010D;

/// Локальный вариант IBP_DBPROP__INIT__MULTI_STMTS_EXEC_RULES
const DBPROPID IBP_DBPROP__ROWSET__MULTI_STMTS_EXEC_RULES       =0x010E;

/// <summary>
///  Правила работы с отложенными данными OUT-параметров
/// </summary>
/// \sa ibp::t_ibp_propval__deferred_data_rule
const DBPROPID IBP_DBPROP__ROWSET__DEFERRED_OUT_PARAM           =0x010F;

/// Локальный вариант IBP_DBPROP__INIT__NAMED_PARAM_RULES
const DBPROPID IBP_DBPROP__ROWSET__NAMED_PARAM_RULES            =0x0110;

/// Локальный вариант IBP_DBPROP__INIT__ASYNCH_FETCH
const DBPROPID IBP_DBPROP__ROWSET__ASYNCH_FETCH                 =0x0111;

////////////////////////////////////////////////////////////////////////////////
//rowset information properties [separate properties set]

/// Размер хранилища результирующего множества в байтах
const DBPROPID IBP_DBPROP__ROWSET_INFO__RESULT_STG_SIZE         =0x0001;

/// Используется внешний файл для хранения данных результирующего множества
const DBPROPID IBP_DBPROP__ROWSET_INFO__USING_FILE_STG          =0x0002;

////////////////////////////////////////////////////////////////////////////////
//statement information properties [separate properties set]

/// Statement plan
const DBPROPID IBP_DBPROP__STMT_INFO__PLAN                      =0x0001;

//------------------------------------------------------------------------
//! @}

////////////////////////////////////////////////////////////////////////////////
//data source information properties

//! \addtogroup ibp_oledb__props_info
//! @{
//------------------------------------------------------------------------

//const DBPROPID IBP_DBPROP__INFO__IB_BASE_LEVEL                =0xFFC1;

//const DBPROPID IBP_DBPROP__INFO__IB_CLIENT_LEVEL              =0xFFC2;

/// Native string with DBMS description
const DBPROPID IBP_DBPROP__INFO__IB_BASE                        =0xFFC3;

/// Database dialect
const DBPROPID IBP_DBPROP__INFO__IB_DATABASE_DIALECT            =0xFFC6;

//const DBPROPID IBP_DBPROP__INFO__IB_ODS_VERSION               =0xFFC7;

//const DBPROPID IBP_DBPROP__INFO__IB_ODS_MINOR_VERSION         =0xFFC8;

// [2016-01-05] Какое то несуразное свойство. Удалено.
// Тип соединения с сервером базы данных (удаленное, локальное)
//const DBPROPID IBP_DBPROP__INFO__IB_REMOTE_CONNECTION         =0xFFC9;

/// Number of pages per page of the attached database
const DBPROPID IBP_DBPROP__INFO__IB_DATABASE_PAGE_SIZE          =0xFFCA;

//deprecated
//const DBPROPID DBPROP_IB_RELEASE_SVP_AFTER_ROLLBACK           =0xFFCB;

/// Creation date of database
const DBPROPID IBP_DBPROP__INFO__IB_DATABASE_CREATION_DATE      =0xFFCC;

/// <summary>
///  Флаги поддержки сервером точек сохранения
/// </summary>
/// <seealso cref="ib_base::tag_ib_svp_flags"/>
const DBPROPID IBP_DBPROP__INFO__IB_SAVEPOINT_SUPPORT           =0xFFCD;

/// Строка с описанием клиентской библиотеки
const DBPROPID IBP_DBPROP__INFO__IB_CLIENT                      =0xFFCE;

/// Строка с версией клиентской библиотеки
const DBPROPID IBP_DBPROP__INFO__IB_CLIENT_VERSION              =0xFFCF;

/// Имя сервера клиентской библиотеки
const DBPROPID IBP_DBPROP__INFO__IB_CLIENT_NAME                 =0xFFD0;

/// Диалект подключения к базе данных
const DBPROPID IBP_DBPROP__INFO__IB_CONNECTION_DIALECT          =0xFFD1;

/// Database ODS version string
const DBPROPID IBP_DBPROP__INFO__IB_DATABASE_ODS_VERSION        =0xFFD2;

//------------------------------------------------------------------------
//! @}

////////////////////////////////////////////////////////////////////////////////
//session properties

//! \addtogroup ibp_oledb__props_session
//! @{
//------------------------------------------------------------------------

/// Разрешение/запрещение автоподтверждения операций в контексте сессии
const DBPROPID IBP_DBPROP__SESSION__AUTO_COMMIT                 =0xFFD1;

/// Разрешение запрешение внутренних транзакций в контексте сессии
const DBPROPID IBP_DBPROP__SESSION__INNER_TRANS                 =0xFFD2;

/// Режим кэширования метаданных
const DBPROPID IBP_DBPROP__SESSION__SCHEMA_CACHE                =0xFFD3;

/// Режим выполнения DDL запросов
const DBPROPID IBP_DBPROP__SESSION__AUTO_COMMIT_DDL             =0xFFD4;

/// Уровень изоляции для выделенной транзации DDL запросов
const DBPROPID IBP_DBPROP__SESSION__AUTO_COMMIT_DDL_LEVEL       =0xFFD5;

/// Флаги отката транзакции
const DBPROPID IBP_DBPROP__SESSION__TR_ABORT_FLAGS              =0xFFD6;

//------------------------------------------------------------------------
//! @}

////////////////////////////////////////////////////////////////////////////////
//new database properties

//! \addtogroup ibp_oledb__props_ds_create
//! @{
//------------------------------------------------------------------------

/// Кодовая страница по-умолчанию
const DBPROPID IBP_DBPROP__DSCREATE__DEFAULT_CHARSET            =0x0001;

/// Размер страницы базы данных
const DBPROPID IBP_DBPROP__DSCREATE__DATABASE_PAGE_SIZE         =0x0002;

/// Диалект базы данных
const DBPROPID IBP_DBPROP__DSCREATE__DATABASE_DIALECT           =0x0003;

/// Collation кодовой страницы по-умолчанию
const DBPROPID IBP_DBPROP__DSCREATE__DEFAULT_CHARSET_COLLATION  =0x0004;

/// <summary>
///  Тип пользователей базы данных
/// </summary>
/// \sa ibp::t_ibp_propval__newdb__type_of_db_users
const DBPROPID IBP_DBPROP__DSCREATE__TYPE_OF_DATABASE_USERS     =0x0005;

//------------------------------------------------------------------------
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v05*/}/*nms ibprovider*/}/*nms sdk*/}/*nms lcpi*/
#endif
