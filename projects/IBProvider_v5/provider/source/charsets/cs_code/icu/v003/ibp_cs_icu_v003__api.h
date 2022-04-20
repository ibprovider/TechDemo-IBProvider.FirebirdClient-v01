////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v003
//! \file    ibp_cs_icu_v003__api.h
//! \brief   Подмножество ICU API v3
//! \author  Kovalenko Dmitry
//! \date    07.10.2008
#ifndef _ibp_cs_icu_v003__api_H_
#define _ibp_cs_icu_v003__api_H_

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v003{namespace api{
////////////////////////////////////////////////////////////////////////////////
//Исключаем из зоны видимости doxygen-а
//! \cond DOXYGEN_PROCESS_ALL
////////////////////////////////////////////////////////////////////////////////
//ICU typedefs

typedef signed __int8      int8_t;
typedef signed __int16     int16_t;
typedef signed __int32     int32_t;
typedef signed __int64     int64_t;

typedef unsigned __int8    uint8_t;
typedef unsigned __int16   uint16_t;
typedef unsigned __int32   uint32_t;
typedef unsigned __int64   uint64_t;

typedef int8_t             UBool;

typedef wchar_t            UChar;

//------------------------------------------------------------------------

/**
 * Define UChar32 as a type for single Unicode code points.
 * UChar32 is a signed 32-bit integer (same as int32_t).
 *
 * The Unicode code point range is 0..0x10ffff.
 * All other values (negative or >=0x110000) are illegal as Unicode code points.
 * They may be used as sentinel values to indicate "done", "error"
 * or similar non-code point conditions.
 *
 * Before ICU 2.4 (Jitterbug 2146), UChar32 was defined
 * to be wchar_t if that is 32 bits wide (wchar_t may be signed or unsigned)
 * or else to be uint32_t.
 * That is, the definition of UChar32 was platform-dependent.
 *
 * @see U_SENTINEL
 * @stable ICU 2.4
 */
typedef int32_t UChar32;

//------------------------------------------------------------------------
typedef struct UConverter UConverter;

////////////////////////////////////////////////////////////////////////////////
//enum UErrorCode;

/**
 * Error code to replace exception handling, so that the code is compatible with all C++ compilers,
 * and to use the same mechanism for C and C++.
 *
 * \par
 * ICU functions that take a reference (C++) or a pointer (C) to a UErrorCode
 * first test if(U_FAILURE(errorCode)) { return immediately; }
 * so that in a chain of such functions the first one that sets an error code
 * causes the following ones to not perform any operations.
 *
 * \par
 * Error codes should be tested using U_FAILURE() and U_SUCCESS().
 * @stable ICU 2.0
 */
typedef enum UErrorCode {
    /* The ordering of U_ERROR_INFO_START Vs U_USING_FALLBACK_WARNING looks weird
     * and is that way because VC++ debugger displays first encountered constant,
     * which is not the what the code is used for
     */

    U_USING_FALLBACK_WARNING  = -128,   /**< A resource bundle lookup returned a fallback result (not an error) */

    U_ERROR_WARNING_START     = -128,   /**< Start of information results (semantically successful) */

    U_USING_DEFAULT_WARNING   = -127,   /**< A resource bundle lookup returned a result from the root locale (not an error) */

    U_SAFECLONE_ALLOCATED_WARNING = -126, /**< A SafeClone operation required allocating memory (informational only) */

    U_STATE_OLD_WARNING       = -125,   /**< ICU has to use compatibility layer to construct the service. Expect performance/memory usage degradation. Consider upgrading */

    U_STRING_NOT_TERMINATED_WARNING = -124,/**< An output string could not be NUL-terminated because output length==destCapacity. */

    U_SORT_KEY_TOO_SHORT_WARNING = -123, /**< Number of levels requested in getBound is higher than the number of levels in the sort key */

    U_AMBIGUOUS_ALIAS_WARNING = -122,   /**< This converter alias can go to different converter implementations */

    U_DIFFERENT_UCA_VERSION = -121,     /**< ucol_open encountered a mismatch between UCA version and collator image version, so the collator was constructed from rules. No impact to further function */

    U_ERROR_WARNING_LIMIT,              /**< This must always be the last warning value to indicate the limit for UErrorCode warnings (last warning code +1) */


    U_ZERO_ERROR              =  0,     /**< No error, no warning. */

    U_ILLEGAL_ARGUMENT_ERROR  =  1,     /**< Start of codes indicating failure */
    U_MISSING_RESOURCE_ERROR  =  2,     /**< The requested resource cannot be found */
    U_INVALID_FORMAT_ERROR    =  3,     /**< Data format is not what is expected */
    U_FILE_ACCESS_ERROR       =  4,     /**< The requested file cannot be found */
    U_INTERNAL_PROGRAM_ERROR  =  5,     /**< Indicates a bug in the library code */
    U_MESSAGE_PARSE_ERROR     =  6,     /**< Unable to parse a message (message format) */
    U_MEMORY_ALLOCATION_ERROR =  7,     /**< Memory allocation error */
    U_INDEX_OUTOFBOUNDS_ERROR =  8,     /**< Trying to access the index that is out of bounds */
    U_PARSE_ERROR             =  9,     /**< Equivalent to Java ParseException */
    U_INVALID_CHAR_FOUND      = 10,     /**< Character conversion: Unmappable input sequence. In other APIs: Invalid character. */
    U_TRUNCATED_CHAR_FOUND    = 11,     /**< Character conversion: Incomplete input sequence. */
    U_ILLEGAL_CHAR_FOUND      = 12,     /**< Character conversion: Illegal input sequence/combination of input units.. */
    U_INVALID_TABLE_FORMAT    = 13,     /**< Conversion table file found, but corrupted */
    U_INVALID_TABLE_FILE      = 14,     /**< Conversion table file not found */
    U_BUFFER_OVERFLOW_ERROR   = 15,     /**< A result would not fit in the supplied buffer */
    U_UNSUPPORTED_ERROR       = 16,     /**< Requested operation not supported in current context */
    U_RESOURCE_TYPE_MISMATCH  = 17,     /**< an operation is requested over a resource that does not support it */
    U_ILLEGAL_ESCAPE_SEQUENCE = 18,     /**< ISO-2022 illlegal escape sequence */
    U_UNSUPPORTED_ESCAPE_SEQUENCE = 19, /**< ISO-2022 unsupported escape sequence */
    U_NO_SPACE_AVAILABLE      = 20,     /**< No space available for in-buffer expansion for Arabic shaping */
    U_CE_NOT_FOUND_ERROR      = 21,     /**< Currently used only while setting variable top, but can be used generally */
    U_PRIMARY_TOO_LONG_ERROR  = 22,     /**< User tried to set variable top to a primary that is longer than two bytes */
    U_STATE_TOO_OLD_ERROR     = 23,     /**< ICU cannot construct a service from this state, as it is no longer supported */
    U_TOO_MANY_ALIASES_ERROR  = 24,     /**< There are too many aliases in the path to the requested resource.
                                             It is very possible that a circular alias definition has occured */
    U_ENUM_OUT_OF_SYNC_ERROR  = 25,     /**< UEnumeration out of sync with underlying collection */
    U_INVARIANT_CONVERSION_ERROR = 26,  /**< Unable to convert a UChar* string to char* with the invariant converter. */
    U_INVALID_STATE_ERROR     = 27,     /**< Requested operation can not be completed with ICU in its current state */

    U_STANDARD_ERROR_LIMIT,             /**< This must always be the last value to indicate the limit for standard errors */
    /*
     * the error code range 0x10000 0x10100 are reserved for Transliterator
     */
    U_BAD_VARIABLE_DEFINITION=0x10000,/**< Missing '$' or duplicate variable name */
    U_PARSE_ERROR_START = 0x10000,    /**< Start of Transliterator errors */
    U_MALFORMED_RULE,                 /**< Elements of a rule are misplaced */
    U_MALFORMED_SET,                  /**< A UnicodeSet pattern is invalid*/
    U_MALFORMED_SYMBOL_REFERENCE,     /**< UNUSED as of ICU 2.4 */
    U_MALFORMED_UNICODE_ESCAPE,       /**< A Unicode escape pattern is invalid*/
    U_MALFORMED_VARIABLE_DEFINITION,  /**< A variable definition is invalid */
    U_MALFORMED_VARIABLE_REFERENCE,   /**< A variable reference is invalid */
    U_MISMATCHED_SEGMENT_DELIMITERS,  /**< UNUSED as of ICU 2.4 */
    U_MISPLACED_ANCHOR_START,         /**< A start anchor appears at an illegal position */
    U_MISPLACED_CURSOR_OFFSET,        /**< A cursor offset occurs at an illegal position */
    U_MISPLACED_QUANTIFIER,           /**< A quantifier appears after a segment close delimiter */
    U_MISSING_OPERATOR,               /**< A rule contains no operator */
    U_MISSING_SEGMENT_CLOSE,          /**< UNUSED as of ICU 2.4 */
    U_MULTIPLE_ANTE_CONTEXTS,         /**< More than one ante context */
    U_MULTIPLE_CURSORS,               /**< More than one cursor */
    U_MULTIPLE_POST_CONTEXTS,         /**< More than one post context */
    U_TRAILING_BACKSLASH,             /**< A dangling backslash */
    U_UNDEFINED_SEGMENT_REFERENCE,    /**< A segment reference does not correspond to a defined segment */
    U_UNDEFINED_VARIABLE,             /**< A variable reference does not correspond to a defined variable */
    U_UNQUOTED_SPECIAL,               /**< A special character was not quoted or escaped */
    U_UNTERMINATED_QUOTE,             /**< A closing single quote is missing */
    U_RULE_MASK_ERROR,                /**< A rule is hidden by an earlier more general rule */
    U_MISPLACED_COMPOUND_FILTER,      /**< A compound filter is in an invalid location */
    U_MULTIPLE_COMPOUND_FILTERS,      /**< More than one compound filter */
    U_INVALID_RBT_SYNTAX,             /**< A "::id" rule was passed to the RuleBasedTransliterator parser */
    U_INVALID_PROPERTY_PATTERN,       /**< UNUSED as of ICU 2.4 */
    U_MALFORMED_PRAGMA,               /**< A 'use' pragma is invlalid */
    U_UNCLOSED_SEGMENT,               /**< A closing ')' is missing */
    U_ILLEGAL_CHAR_IN_SEGMENT,        /**< UNUSED as of ICU 2.4 */
    U_VARIABLE_RANGE_EXHAUSTED,       /**< Too many stand-ins generated for the given variable range */
    U_VARIABLE_RANGE_OVERLAP,         /**< The variable range overlaps characters used in rules */
    U_ILLEGAL_CHARACTER,              /**< A special character is outside its allowed context */
    U_INTERNAL_TRANSLITERATOR_ERROR,  /**< Internal transliterator system error */
    U_INVALID_ID,                     /**< A "::id" rule specifies an unknown transliterator */
    U_INVALID_FUNCTION,               /**< A "&fn()" rule specifies an unknown transliterator */
    U_PARSE_ERROR_LIMIT,              /**< The limit for Transliterator errors */

    /*
     * the error code range 0x10100 0x10200 are reserved for formatting API parsing error
     */
    U_UNEXPECTED_TOKEN=0x10100,       /**< Syntax error in format pattern */
    U_FMT_PARSE_ERROR_START=0x10100,  /**< Start of format library errors */
    U_MULTIPLE_DECIMAL_SEPARATORS,    /**< More than one decimal separator in number pattern */
    U_MULTIPLE_DECIMAL_SEPERATORS = U_MULTIPLE_DECIMAL_SEPARATORS, /**< Typo: kept for backward compatibility. Use U_MULTIPLE_DECIMAL_SEPARATORS */
    U_MULTIPLE_EXPONENTIAL_SYMBOLS,   /**< More than one exponent symbol in number pattern */
    U_MALFORMED_EXPONENTIAL_PATTERN,  /**< Grouping symbol in exponent pattern */
    U_MULTIPLE_PERCENT_SYMBOLS,       /**< More than one percent symbol in number pattern */
    U_MULTIPLE_PERMILL_SYMBOLS,       /**< More than one permill symbol in number pattern */
    U_MULTIPLE_PAD_SPECIFIERS,        /**< More than one pad symbol in number pattern */
    U_PATTERN_SYNTAX_ERROR,           /**< Syntax error in format pattern */
    U_ILLEGAL_PAD_POSITION,           /**< Pad symbol misplaced in number pattern */
    U_UNMATCHED_BRACES,               /**< Braces do not match in message pattern */
    U_UNSUPPORTED_PROPERTY,           /**< UNUSED as of ICU 2.4 */
    U_UNSUPPORTED_ATTRIBUTE,          /**< UNUSED as of ICU 2.4 */
    U_FMT_PARSE_ERROR_LIMIT,          /**< The limit for format library errors */

    /*
     * the error code range 0x10200 0x102ff are reserved for Break Iterator related error
     */
    U_BRK_ERROR_START=0x10200,             /**< Start of codes indicating Break Iterator failures */
    U_BRK_INTERNAL_ERROR,                  /**< An internal error (bug) was detected.             */
    U_BRK_HEX_DIGITS_EXPECTED,             /**< Hex digits expected as part of a escaped char in a rule. */
    U_BRK_SEMICOLON_EXPECTED,              /**< Missing ';' at the end of a RBBI rule.            */
    U_BRK_RULE_SYNTAX,                     /**< Syntax error in RBBI rule.                        */
    U_BRK_UNCLOSED_SET,                    /**< UnicodeSet witing an RBBI rule missing a closing ']'.  */
    U_BRK_ASSIGN_ERROR,                    /**< Syntax error in RBBI rule assignment statement.   */
    U_BRK_VARIABLE_REDFINITION,            /**< RBBI rule $Variable redefined.                    */
    U_BRK_MISMATCHED_PAREN,                /**< Mis-matched parentheses in an RBBI rule.          */
    U_BRK_NEW_LINE_IN_QUOTED_STRING,       /**< Missing closing quote in an RBBI rule.            */
    U_BRK_UNDEFINED_VARIABLE,              /**< Use of an undefined $Variable in an RBBI rule.    */
    U_BRK_INIT_ERROR,                      /**< Initialization failure.  Probable missing ICU Data. */
    U_BRK_RULE_EMPTY_SET,                  /**< Rule contains an empty Unicode Set.               */
    U_BRK_UNRECOGNIZED_OPTION,             /**< !!option in RBBI rules not recognized.            */
    U_BRK_MALFORMED_RULE_TAG,              /**< The {nnn} tag on a rule is mal formed             */
    U_BRK_ERROR_LIMIT,                     /**< This must always be the last value to indicate the limit for Break Iterator failures */

    /*
     * The error codes in the range 0x10300-0x103ff are reserved for regular expression related errrs
     */
     U_REGEX_ERROR_START=0x10300,          /**< Start of codes indicating Regexp failures          */
     U_REGEX_INTERNAL_ERROR,               /**< An internal error (bug) was detected.              */
     U_REGEX_RULE_SYNTAX,                  /**< Syntax error in regexp pattern.                    */
     U_REGEX_INVALID_STATE,                /**< RegexMatcher in invalid state for requested operation */
     U_REGEX_BAD_ESCAPE_SEQUENCE,          /**< Unrecognized backslash escape sequence in pattern  */
     U_REGEX_PROPERTY_SYNTAX,              /**< Incorrect Unicode property                         */
     U_REGEX_UNIMPLEMENTED,                /**< Use of regexp feature that is not yet implemented. */
     U_REGEX_MISMATCHED_PAREN,             /**< Incorrectly nested parentheses in regexp pattern.  */
     U_REGEX_NUMBER_TOO_BIG,               /**< Decimal number is too large.                       */
     U_REGEX_BAD_INTERVAL,                 /**< Error in {min,max} interval                        */
     U_REGEX_MAX_LT_MIN,                   /**< In {min,max}, max is less than min.                */
     U_REGEX_INVALID_BACK_REF,             /**< Back-reference to a non-existent capture group.    */
     U_REGEX_INVALID_FLAG,                 /**< Invalid value for match mode flags.                */
     U_REGEX_LOOK_BEHIND_LIMIT,            /**< Look-Behind pattern matches must have a bounded maximum length.    */
     U_REGEX_SET_CONTAINS_STRING,          /**< Regexps cannot have UnicodeSets containing strings.*/
     U_REGEX_ERROR_LIMIT,                  /**< This must always be the last value to indicate the limit for regexp errors */

     /*
      * The error code in the range 0x10400-0x104ff are reserved for IDNA related error codes
      */
      U_IDNA_ERROR_START=0x10400,
      U_IDNA_PROHIBITED_ERROR,
      U_IDNA_UNASSIGNED_ERROR,
      U_IDNA_CHECK_BIDI_ERROR,
      U_IDNA_STD3_ASCII_RULES_ERROR,
      U_IDNA_ACE_PREFIX_ERROR,
      U_IDNA_VERIFICATION_ERROR,
      U_IDNA_LABEL_TOO_LONG_ERROR,
      U_IDNA_ERROR_LIMIT,
      /*
       * Aliases for StringPrep
       */
      U_STRINGPREP_PROHIBITED_ERROR = U_IDNA_PROHIBITED_ERROR,
      U_STRINGPREP_UNASSIGNED_ERROR = U_IDNA_UNASSIGNED_ERROR,
      U_STRINGPREP_CHECK_BIDI_ERROR = U_IDNA_CHECK_BIDI_ERROR,


      U_ERROR_LIMIT=U_IDNA_ERROR_LIMIT      /**< This must always be the last value to indicate the limit for UErrorCode (last error code +1) */
} UErrorCode;

////////////////////////////////////////////////////////////////////////////////
//enum UConverterCallbackReason

typedef enum {
    UCNV_UNASSIGNED = 0,  /**< The code point is unassigned.
                             The error code U_INVALID_CHAR_FOUND will be set. */
    UCNV_ILLEGAL = 1,     /**< The code point is illegal. For example,
                             \\x81\\x2E is illegal in SJIS because \\x2E
                             is not a valid trail byte for the \\x81
                             lead byte.
                             Also, starting with Unicode 3.0.1, non-shortest byte sequences
                             in UTF-8 (like \\xC1\\xA1 instead of \\x61 for U+0061)
                             are also illegal, not just irregular.
                             The error code U_ILLEGAL_CHAR_FOUND will be set. */
    UCNV_IRREGULAR = 2,   /**< The codepoint is not a regular sequence in
                             the encoding. For example, \\xED\\xA0\\x80..\\xED\\xBF\\xBF
                             are irregular UTF-8 byte sequences for single surrogate
                             code points.
                             The error code U_INVALID_CHAR_FOUND will be set. */
    UCNV_RESET = 3,       /**< The callback is called with this reason when a
                             'reset' has occured. Callback should reset all
                             state. */
    UCNV_CLOSE = 4,        /**< Called when the converter is closed. The
                             callback should release any allocated memory.*/
    UCNV_CLONE = 5         /**< Called when ucnv_safeClone() is called on the
                              converter. the pointer available as the
                              'context' is an alias to the original converters'
                              context pointer. If the context must be owned
                              by the new converter, the callback must clone
                              the data and call ucnv_setFromUCallback
                              (or setToUCallback) with the correct pointer.
                              @stable ICU 2.2
                           */
} UConverterCallbackReason;

////////////////////////////////////////////////////////////////////////////////
//enum UConverterType

/**
 * Enum for specifying basic types of converters
 * @see ucnv_getType
 * @stable ICU 2.0
 */
typedef enum {
    UCNV_UNSUPPORTED_CONVERTER = -1,
    UCNV_SBCS = 0,
    UCNV_DBCS = 1,
    UCNV_MBCS = 2,
    UCNV_LATIN_1 = 3,
    UCNV_UTF8 = 4,
    UCNV_UTF16_BigEndian = 5,
    UCNV_UTF16_LittleEndian = 6,
    UCNV_UTF32_BigEndian = 7,
    UCNV_UTF32_LittleEndian = 8,
    UCNV_EBCDIC_STATEFUL = 9,
    UCNV_ISO_2022 = 10,

    UCNV_LMBCS_1 = 11,
    UCNV_LMBCS_2,
    UCNV_LMBCS_3,
    UCNV_LMBCS_4,
    UCNV_LMBCS_5,
    UCNV_LMBCS_6,
    UCNV_LMBCS_8,
    UCNV_LMBCS_11,
    UCNV_LMBCS_16,
    UCNV_LMBCS_17,
    UCNV_LMBCS_18,
    UCNV_LMBCS_19,
    UCNV_LMBCS_LAST = UCNV_LMBCS_19,
    UCNV_HZ,
    UCNV_SCSU,
    UCNV_ISCII,
    UCNV_US_ASCII,
    UCNV_UTF7,
    UCNV_BOCU1,
    UCNV_UTF16,
    UCNV_UTF32,
    UCNV_CESU8,
    UCNV_IMAP_MAILBOX,

    /* Number of converter types for which we have conversion routines. */
    UCNV_NUMBER_OF_SUPPORTED_CONVERTER_TYPES

} UConverterType;

////////////////////////////////////////////////////////////////////////////////
//struct UConverterToUnicodeArgs

typedef struct
{
    uint16_t     size;          /**< The size of this struct   @stable ICU 2.0 */
    UBool        flush;         /**< The internal state of converter will be reset and data flushed if set to TRUE. @stable ICU 2.0   */
    UConverter*  converter;     /**< Pointer to the converter that is opened and to which this struct is passed as an argument. @stable ICU 2.0 */
    const char*  source;        /**< Pointer to the source source buffer. @stable ICU 2.0    */
    const char*  sourceLimit;   /**< Pointer to the limit (end + 1) of source buffer. @stable ICU 2.0    */
    UChar*       target;        /**< Pointer to the target buffer. @stable ICU 2.0    */
    const UChar* targetLimit;   /**< Pointer to the limit (end + 1) of target buffer. @stable ICU 2.0     */
    int32_t*     offsets;       /**< Pointer to the buffer that recieves the offsets. *offset = blah ; offset++;. @stable ICU 2.0  */
} UConverterToUnicodeArgs;

////////////////////////////////////////////////////////////////////////////////
//struct UConverterFromUnicodeArgs

/**
 * The structure for the fromUnicode callback function parameter.
 * @stable ICU 2.0
 */
typedef struct
{
    uint16_t       size;           /**< The size of this struct. @stable ICU 2.0 */
    UBool          flush;          /**< The internal state of converter will be reset and data flushed if set to TRUE. @stable ICU 2.0    */
    UConverter*    converter;      /**< Pointer to the converter that is opened and to which this struct is passed as an argument. @stable ICU 2.0  */
    const UChar*   source;         /**< Pointer to the source source buffer. @stable ICU 2.0    */
    const UChar*   sourceLimit;    /**< Pointer to the limit (end + 1) of source buffer. @stable ICU 2.0    */
    char*          target;         /**< Pointer to the target buffer. @stable ICU 2.0    */
    const char*    targetLimit;    /**< Pointer to the limit (end + 1) of target buffer. @stable ICU 2.0     */
    int32_t*       offsets;        /**< Pointer to the buffer that recieves the offsets. *offset = blah ; offset++;. @stable ICU 2.0  */
} UConverterFromUnicodeArgs;

////////////////////////////////////////////////////////////////////////////////

#define ICU_EXPORT2 __cdecl

#define ICU_FN(name) t_fn_##name

////////////////////////////////////////////////////////////////////////////////

/**
 * Gets the type of the converter
 * e.g. SBCS, MBCS, DBCS, UTF8, UTF16_BE, UTF16_LE, ISO_2022,
 * EBCDIC_STATEFUL, LATIN_1
 * @param converter a valid, opened converter
 * @return the type of the converter
 * @stable ICU 2.0
 */
typedef UConverterType (ICU_EXPORT2 ICU_FN(ucnv_getType))
 (const UConverter* converter);

////////////////////////////////////////////////////////////////////////////////
//Callback functions signatures

/**
 * Function pointer for error callback in the codepage to unicode direction.
 * Called when an error has occured in conversion to unicode, or on open/close of the callback (see reason).
 * @param context Pointer to the callback's private data
 * @param args Information about the conversion in progress
 * @param codeUnits Points to 'length' bytes of the concerned codepage sequence
 * @param length Size (in bytes) of the concerned codepage sequence
 * @param reason Defines the reason the callback was invoked
 * @see ucnv_setToUCallBack
 * @see UConverterToUnicodeArgs
 * @stable ICU 2.0
 */
typedef void (ICU_EXPORT2 *UConverterToUCallback)
 (const void*              context,
  UConverterToUnicodeArgs* args,
  const char*              codeUnits,
  int32_t                  length,
  UConverterCallbackReason reason,
  UErrorCode*);

//------------------------------------------------------------------------
/**
 * Function pointer for error callback in the unicode to codepage direction.
 * Called when an error has occured in conversion from unicode, or on open/close of the callback (see reason).
 * @param context Pointer to the callback's private data
 * @param args Information about the conversion in progress
 * @param codeUnits Points to 'length' UChars of the concerned Unicode sequence
 * @param length Size (in bytes) of the concerned codepage sequence
 * @param codePoint Single UChar32 (UTF-32) containing the concerend Unicode codepoint.
 * @param reason Defines the reason the callback was invoked
 * @see ucnv_setFromUCallBack
 * @stable ICU 2.0
 */
typedef void (ICU_EXPORT2 *UConverterFromUCallback)
 (const void*                context,
  UConverterFromUnicodeArgs* args,
  const UChar*               codeUnits,
  int32_t                    length,
  UChar32                    codePoint,
  UConverterCallbackReason   reason,
  UErrorCode*);

////////////////////////////////////////////////////////////////////////////////
/**
 * Creates a UConverter object with the names specified as a C string.
 * The actual name will be resolved with the alias file
 * using a case-insensitive string comparison that ignores
 * the delimiters '-', '_', and ' ' (dash, underscore, and space).
 * E.g., the names "UTF8", "utf-8", and "Utf 8" are all equivalent.
 * If <code>NULL</code> is passed for the converter name, it will create one with the
 * getDefaultName return value.
 *
 * <p>A converter name for ICU 1.5 and above may contain options
 * like a locale specification to control the specific behavior of
 * the newly instantiated converter.
 * The meaning of the options depends on the particular converter.
 * If an option is not defined for or recognized by a given converter, then it is ignored.</p>
 *
 * <p>Options are appended to the converter name string, with a
 * <code>UCNV_OPTION_SEP_CHAR</code> between the name and the first option and
 * also between adjacent options.</p>
 *
 * <p>If the alias is ambiguous, then the preferred converter is used
 * and the status is set to U_AMBIGUOUS_ALIAS_WARNING.</p>
 *
 * <p>The conversion behavior and names can vary between platforms. ICU may
 * convert some characters differently from other platforms. Details on this topic
 * are in the <a href="http://oss.software.ibm.com/icu/userguide/conversion.html">User's
 * Guide</a>.</p>
 *
 * @param converterName Name of the uconv table, may have options appended
 * @param err outgoing error status <TT>U_MEMORY_ALLOCATION_ERROR, U_FILE_ACCESS_ERROR</TT>
 * @return the created Unicode converter object, or <TT>NULL</TT> if an error occured
 * @see ucnv_openU
 * @see ucnv_openCCSID
 * @see ucnv_close
 * @stable ICU 2.0
 */

typedef UConverter* (ICU_EXPORT2 ICU_FN(ucnv_open))
 (const char *converterName, UErrorCode *err);

////////////////////////////////////////////////////////////////////////////////
/**
 * Deletes the unicode converter and releases resources associated
 * with just this instance.
 * Does not free up shared converter tables.
 *
 * @param converter the converter object to be deleted
 * @see ucnv_open
 * @see ucnv_openU
 * @see ucnv_openCCSID
 * @stable ICU 2.0
 */

typedef void (ICU_EXPORT2 ICU_FN(ucnv_close))
 (UConverter* converter);

////////////////////////////////////////////////////////////////////////////////
/**
 * Changes the current callback function used by the converter when
 * an illegal or invalid sequence is found.
 * Context pointers are always owned by the caller.
 * Predefined actions and contexts can be found in the ucnv_err.h header.
 *
 * @param converter the unicode converter
 * @param newAction the new callback function
 * @param newContext the new fromUnicode callback context pointer. This can be NULL.
 * @param oldAction fillin: returns the old callback function pointer. This can be NULL.
 * @param oldContext fillin: returns the old callback's private void* context. This can be NULL.
 * @param err The error code status
 * @see ucnv_getFromUCallBack
 * @stable ICU 2.0
 */

typedef void (ICU_EXPORT2 ICU_FN(ucnv_setFromUCallBack))
 (UConverter*              converter,
  UConverterFromUCallback  newAction,
  const void*              newContext,
  UConverterFromUCallback* oldAction,
  const void**             oldContext,
  UErrorCode*              err);

////////////////////////////////////////////////////////////////////////////////
/**
 * Changes the callback function used by the converter when
 * an illegal or invalid sequence is found.
 * Context pointers are always owned by the caller.
 * Predefined actions and contexts can be found in the ucnv_err.h header.
 *
 * @param converter the unicode converter
 * @param newAction the new callback function
 * @param newContext the new toUnicode callback context pointer. This can be NULL.
 * @param oldAction fillin: returns the old callback function pointer. This can be NULL.
 * @param oldContext fillin: returns the old callback's private void* context. This can be NULL.
 * @param err The error code status
 * @see ucnv_getToUCallBack
 * @stable ICU 2.0
 */

typedef void (ICU_EXPORT2 ICU_FN(ucnv_setToUCallBack))
 (UConverter*            converter,
  UConverterToUCallback  newAction,
  const void*            newContext,
  UConverterToUCallback* oldAction,
  const void**           oldContext,
  UErrorCode*            err);

////////////////////////////////////////////////////////////////////////////////
/**
 * DO NOT CALL THIS FUNCTION DIRECTLY!
 * This To Unicode callback STOPS at the ILLEGAL_SEQUENCE,
 * returning the error code back to the caller immediately.
 *
 * @param context Pointer to the callback's private data
 * @param toUArgs Information about the conversion in progress
 * @param codeUnits Points to 'length' bytes of the concerned codepage sequence
 * @param length Size (in bytes) of the concerned codepage sequence
 * @param reason Defines the reason the callback was invoked
 * @param err This should always be set to a failure status prior to calling.
 * @stable ICU 2.0
 */

typedef void (ICU_EXPORT2 ICU_FN(UCNV_TO_U_CALLBACK_STOP))
 (const void*              context,
  UConverterToUnicodeArgs* toUArgs,
  const char*              codeUnits,
  int32_t                  length,
  UConverterCallbackReason reason,
  UErrorCode*              err);

////////////////////////////////////////////////////////////////////////////////
/**
 * DO NOT CALL THIS FUNCTION DIRECTLY!
 * This From Unicode callback STOPS at the ILLEGAL_SEQUENCE,
 * returning the error code back to the caller immediately.
 *
 * @param context Pointer to the callback's private data
 * @param fromUArgs Information about the conversion in progress
 * @param codeUnits Points to 'length' UChars of the concerned Unicode sequence
 * @param length Size (in bytes) of the concerned codepage sequence
 * @param codePoint Single UChar32 (UTF-32) containing the concerend Unicode codepoint.
 * @param reason Defines the reason the callback was invoked
 * @param err This should always be set to a failure status prior to calling.
 * @stable ICU 2.0
 */

typedef void (ICU_EXPORT2 ICU_FN(UCNV_FROM_U_CALLBACK_STOP))
 (const void*                context,
  UConverterFromUnicodeArgs* fromUArgs,
  const UChar*               codeUnits,
  int32_t                    length,
  UChar32                    codePoint,
  UConverterCallbackReason   reason,
  UErrorCode*                err);

////////////////////////////////////////////////////////////////////////////////
/**
 * Converts an array of unicode characters to an array of codepage
 * characters. This function is optimized for converting a continuous
 * stream of data in buffer-sized chunks, where the entire source and
 * target does not fit in available buffers.
 *
 * The source pointer is an in/out parameter. It starts out pointing where the
 * conversion is to begin, and ends up pointing after the last UChar consumed.
 *
 * Target similarly starts out pointer at the first available byte in the output
 * buffer, and ends up pointing after the last byte written to the output.
 *
 * The converter always attempts to consume the entire source buffer, unless
 * (1.) the target buffer is full, or (2.) a failing error is returned from the
 * current callback function.  When a successful error status has been
 * returned, it means that all of the source buffer has been
 *  consumed. At that point, the caller should reset the source and
 *  sourceLimit pointers to point to the next chunk.
 *
 * At the end of the stream (flush==TRUE), the input is completely consumed
 * when *source==sourceLimit and no error code is set.
 * The converter object is then automatically reset by this function.
 * (This means that a converter need not be reset explicitly between data
 * streams if it finishes the previous stream without errors.)
 *
 * This is a <I>stateful</I> conversion. Additionally, even when all source data has
 * been consumed, some data may be in the converters' internal state.
 * Call this function repeatedly, updating the target pointers with
 * the next empty chunk of target in case of a
 * <TT>U_BUFFER_OVERFLOW_ERROR</TT>, and updating the source  pointers
 *  with the next chunk of source when a successful error status is
 * returned, until there are no more chunks of source data.
 * @param converter the Unicode converter
 * @param target I/O parameter. Input : Points to the beginning of the buffer to copy
 *  codepage characters to. Output : points to after the last codepage character copied
 *  to <TT>target</TT>.
 * @param targetLimit the pointer just after last of the <TT>target</TT> buffer
 * @param source I/O parameter, pointer to pointer to the source Unicode character buffer.
 * @param sourceLimit the pointer just after the last of the source buffer
 * @param offsets if NULL is passed, nothing will happen to it, otherwise it needs to have the same number
 * of allocated cells as <TT>target</TT>. Will fill in offsets from target to source pointer
 * e.g: <TT>offsets[3]</TT> is equal to 6, it means that the <TT>target[3]</TT> was a result of transcoding <TT>source[6]</TT>
 * For output data carried across calls, and other data without a specific source character
 * (such as from escape sequences or callbacks)  -1 will be placed for offsets.
 * @param flush set to <TT>TRUE</TT> if the current source buffer is the last available
 * chunk of the source, <TT>FALSE</TT> otherwise. Note that if a failing status is returned,
 * this function may have to be called multiple times with flush set to <TT>TRUE</TT> until
 * the source buffer is consumed.
 * @param err the error status.  <TT>U_ILLEGAL_ARGUMENT_ERROR</TT> will be set if the
 * converter is <TT>NULL</TT>.
 * <code>U_BUFFER_OVERFLOW_ERROR</code> will be set if the target is full and there is
 * still data to be written to the target.
 * @see ucnv_fromUChars
 * @see ucnv_convert
 * @see ucnv_getMinCharSize
 * @see ucnv_setToUCallBack
 * @stable ICU 2.0
 */

typedef void (ICU_EXPORT2 ICU_FN(ucnv_fromUnicode))
 (UConverter*    converter,
  char**         target,
  const char*    targetLimit,
  const UChar**  source,
  const UChar*   sourceLimit,
  int32_t*       offsets,
  UBool          flush,
  UErrorCode*    err);

////////////////////////////////////////////////////////////////////////////////

/**
 * Converts a buffer of codepage bytes into an array of unicode UChars
 * characters. This function is optimized for converting a continuous
 * stream of data in buffer-sized chunks, where the entire source and
 * target does not fit in available buffers.
 *
 * The source pointer is an in/out parameter. It starts out pointing where the
 * conversion is to begin, and ends up pointing after the last byte of source consumed.
 *
 * Target similarly starts out pointer at the first available UChar in the output
 * buffer, and ends up pointing after the last UChar written to the output.
 * It does NOT necessarily keep UChar sequences together.
 *
 * The converter always attempts to consume the entire source buffer, unless
 * (1.) the target buffer is full, or (2.) a failing error is returned from the
 * current callback function.  When a successful error status has been
 * returned, it means that all of the source buffer has been
 *  consumed. At that point, the caller should reset the source and
 *  sourceLimit pointers to point to the next chunk.
 *
 * At the end of the stream (flush==TRUE), the input is completely consumed
 * when *source==sourceLimit and no error code is set
 * The converter object is then automatically reset by this function.
 * (This means that a converter need not be reset explicitly between data
 * streams if it finishes the previous stream without errors.)
 *
 * This is a <I>stateful</I> conversion. Additionally, even when all source data has
 * been consumed, some data may be in the converters' internal state.
 * Call this function repeatedly, updating the target pointers with
 * the next empty chunk of target in case of a
 * <TT>U_BUFFER_OVERFLOW_ERROR</TT>, and updating the source  pointers
 *  with the next chunk of source when a successful error status is
 * returned, until there are no more chunks of source data.
 * @param converter the Unicode converter
 * @param target I/O parameter. Input : Points to the beginning of the buffer to copy
 *  UChars into. Output : points to after the last UChar copied.
 * @param targetLimit the pointer just after the end of the <TT>target</TT> buffer
 * @param source I/O parameter, pointer to pointer to the source codepage buffer.
 * @param sourceLimit the pointer to the byte after the end of the source buffer
 * @param offsets if NULL is passed, nothing will happen to it, otherwise it needs to have the same number
 * of allocated cells as <TT>target</TT>. Will fill in offsets from target to source pointer
 * e.g: <TT>offsets[3]</TT> is equal to 6, it means that the <TT>target[3]</TT> was a result of transcoding <TT>source[6]</TT>
 * For output data carried across calls, and other data without a specific source character
 * (such as from escape sequences or callbacks)  -1 will be placed for offsets.
 * @param flush set to <TT>TRUE</TT> if the current source buffer is the last available
 * chunk of the source, <TT>FALSE</TT> otherwise. Note that if a failing status is returned,
 * this function may have to be called multiple times with flush set to <TT>TRUE</TT> until
 * the source buffer is consumed.
 * @param err the error status.  <TT>U_ILLEGAL_ARGUMENT_ERROR</TT> will be set if the
 * converter is <TT>NULL</TT>.
 * <code>U_BUFFER_OVERFLOW_ERROR</code> will be set if the target is full and there is
 * still data to be written to the target.
 * @see ucnv_fromUChars
 * @see ucnv_convert
 * @see ucnv_getMinCharSize
 * @see ucnv_setFromUCallBack
 * @see ucnv_getNextUChar
 * @stable ICU 2.0
 */

typedef void (ICU_EXPORT2 ICU_FN(ucnv_toUnicode))
 (UConverter*  converter,
  UChar**      target,
  const UChar* targetLimit,
  const char** source,
  const char*  sourceLimit,
  int32_t*     offsets,
  UBool        flush,
  UErrorCode*  err);

////////////////////////////////////////////////////////////////////////////////

/**
 * Convert the Unicode string into a codepage string using an existing UConverter.
 * The output string is NUL-terminated if possible.
 *
 * This function is a more convenient but less powerful version of ucnv_fromUnicode().
 * It is only useful for whole strings, not for streaming conversion.
 *
 * The maximum output buffer capacity required (barring output from callbacks) will be
 * UCNV_GET_MAX_BYTES_FOR_STRING(srcLength, ucnv_getMaxCharSize(cnv)).
 *
 * @param cnv the converter object to be used (ucnv_resetFromUnicode() will be called)
 * @param src the input Unicode string
 * @param srcLength the input string length, or -1 if NUL-terminated
 * @param dest destination string buffer, can be NULL if destCapacity==0
 * @param destCapacity the number of chars available at dest
 * @param pErrorCode normal ICU error code;
 *                  common error codes that may be set by this function include
 *                  U_BUFFER_OVERFLOW_ERROR, U_STRING_NOT_TERMINATED_WARNING,
 *                  U_ILLEGAL_ARGUMENT_ERROR, and conversion errors
 * @return the length of the output string, not counting the terminating NUL;
 *         if the length is greater than destCapacity, then the string will not fit
 *         and a buffer of the indicated length would need to be passed in
 * @see ucnv_fromUnicode
 * @see ucnv_convert
 * @see UCNV_GET_MAX_BYTES_FOR_STRING
 * @stable ICU 2.0
 */

typedef int32_t (ICU_EXPORT2 ICU_FN(ucnv_fromUChars))
 (UConverter*  cnv,
  char*        dest,
  int32_t      destCapacity,
  const UChar* src,
  int32_t      srcLength,
  UErrorCode*  pErrorCode);

////////////////////////////////////////////////////////////////////////////////

/**
 * Convert the codepage string into a Unicode string using an existing UConverter.
 * The output string is NUL-terminated if possible.
 *
 * This function is a more convenient but less powerful version of ucnv_toUnicode().
 * It is only useful for whole strings, not for streaming conversion.
 *
 * The maximum output buffer capacity required (barring output from callbacks) will be
 * 2*srcLength (each char may be converted into a surrogate pair).
 *
 * @param cnv the converter object to be used (ucnv_resetToUnicode() will be called)
 * @param src the input codepage string
 * @param srcLength the input string length, or -1 if NUL-terminated
 * @param dest destination string buffer, can be NULL if destCapacity==0
 * @param destCapacity the number of UChars available at dest
 * @param pErrorCode normal ICU error code;
 *                  common error codes that may be set by this function include
 *                  U_BUFFER_OVERFLOW_ERROR, U_STRING_NOT_TERMINATED_WARNING,
 *                  U_ILLEGAL_ARGUMENT_ERROR, and conversion errors
 * @return the length of the output string, not counting the terminating NUL;
 *         if the length is greater than destCapacity, then the string will not fit
 *         and a buffer of the indicated length would need to be passed in
 * @see ucnv_toUnicode
 * @see ucnv_convert
 * @stable ICU 2.0
 */

typedef int32_t (ICU_EXPORT2 ICU_FN(ucnv_toUChars))
 (UConverter* cnv,
  UChar*      dest,
  int32_t     destCapacity,
  const char* src,
  int32_t     srcLength,
  UErrorCode* pErrorCode);

////////////////////////////////////////////////////////////////////////////////

/**
 * Returns the minimum byte length for characters in this codepage.
 * This is usually either 1 or 2.
 * @param converter the Unicode converter
 * @return the minimum number of bytes allowed by this particular converter
 * @see ucnv_getMaxCharSize
 * @stable ICU 2.0
 */

typedef int8_t (ICU_EXPORT2 ICU_FN(ucnv_getMinCharSize))
 (const UConverter* converter);

////////////////////////////////////////////////////////////////////////////////

/**
 * Returns the maximum number of bytes that are output per UChar in conversion
 * from Unicode using this converter.
 * The returned number can be used with UCNV_GET_MAX_BYTES_FOR_STRING
 * to calculate the size of a target buffer for conversion from Unicode.
 *
 * Note: Before ICU 2.8, this function did not return reliable numbers for
 * some stateful converters (EBCDIC_STATEFUL, ISO-2022) and LMBCS.
 *
 * This number may not be the same as the maximum number of bytes per
 * "conversion unit". In other words, it may not be the intuitively expected
 * number of bytes per character that would be published for a charset,
 * and may not fulfill any other purpose than the allocation of an output
 * buffer of guaranteed sufficient size for a given input length and converter.
 *
 * Examples for special cases that are taken into account:
 * - Supplementary code points may convert to more bytes than BMP code points.
 *   This function returns bytes per UChar (UTF-16 code unit), not per
 *   Unicode code point, for efficient buffer allocation.
 * - State-shifting output (SI/SO, escapes, etc.) from stateful converters.
 * - When m input UChars are converted to n output bytes, then the maximum m/n
 *   is taken into account.
 *
 * The number returned here does not take into account
 * (see UCNV_GET_MAX_BYTES_FOR_STRING):
 * - callbacks which output more than one charset character sequence per call,
 *   like escape callbacks
 * - initial and final non-character bytes that are output by some converters
 *   (automatic BOMs, initial escape sequence, final SI, etc.)
 *
 * Examples for returned values:
 * - SBCS charsets: 1
 * - Shift-JIS: 2
 * - UTF-16: 2 (2 per BMP, 4 per surrogate _pair_, BOM not counted)
 * - UTF-8: 3 (3 per BMP, 4 per surrogate _pair_)
 * - EBCDIC_STATEFUL (EBCDIC mixed SBCS/DBCS): 3 (SO + DBCS)
 * - ISO-2022: 3 (always outputs UTF-8)
 * - ISO-2022-JP: 6 (4-byte escape sequences + DBCS)
 * - ISO-2022-CN: 8 (4-byte designator sequences + 2-byte SS2/SS3 + DBCS)
 *
 * @param converter The Unicode converter.
 * @return The maximum number of bytes per UChar that are output by ucnv_fromUnicode(),
 *         to be used together with UCNV_GET_MAX_BYTES_FOR_STRING for buffer allocation.
 *
 * @see UCNV_GET_MAX_BYTES_FOR_STRING
 * @see ucnv_getMinCharSize
 * @stable ICU 2.0
 */

typedef int8_t (ICU_EXPORT2 ICU_FN(ucnv_getMaxCharSize))
 (const UConverter* converter);

////////////////////////////////////////////////////////////////////////////////

#undef ICU_FN
#undef ICU_EXPORT2

////////////////////////////////////////////////////////////////////////////////
//! \endcond
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms v003*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
#endif