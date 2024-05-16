////////////////////////////////////////////////////////////////////////////////
//ICU API [V063].
//                                                 Kovalenko Dmitry. 26.06.2023.
#ifndef _ibp_cs_icu_v063__api_H_
#define _ibp_cs_icu_v063__api_H_

#include <lcpi/lib/.config.h>
#include <stdint.h>

namespace lcpi{namespace ibp{namespace external{namespace icu{namespace v063{namespace api{
////////////////////////////////////////////////////////////////////////////////
//Исключаем из зоны видимости doxygen-а
//! \cond DOXYGEN_PROCESS_ALL
////////////////////////////////////////////////////////////////////////////////
//ICU typedefs

using ::int8_t;
using ::int16_t;
using ::int32_t;
using ::int64_t;

using ::uint8_t;
using ::uint16_t;
using ::uint32_t;
using ::uint64_t;

typedef int8_t UBool;

//original: typedef char16_t UChar;
typedef wchar_t UChar;

static_assert(sizeof(wchar_t)==sizeof(char16_t),"Bad wchar_t!");

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

typedef struct UEnumeration UEnumeration;

////////////////////////////////////////////////////////////////////////////////
//enum UErrorCode

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
typedef enum UErrorCode
{
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

    U_PLUGIN_CHANGED_LEVEL_WARNING = -120, /**< A plugin caused a level change. May not be an error, but later plugins may not load. */

#ifndef U_HIDE_DEPRECATED_API
    /**
     * One more than the highest normal UErrorCode warning value.
     * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
     */
    U_ERROR_WARNING_LIMIT,
#endif  // U_HIDE_DEPRECATED_API

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
    U_ILLEGAL_CHAR_FOUND      = 12,     /**< Character conversion: Illegal input sequence/combination of input units. */
    U_INVALID_TABLE_FORMAT    = 13,     /**< Conversion table file found, but corrupted */
    U_INVALID_TABLE_FILE      = 14,     /**< Conversion table file not found */
    U_BUFFER_OVERFLOW_ERROR   = 15,     /**< A result would not fit in the supplied buffer */
    U_UNSUPPORTED_ERROR       = 16,     /**< Requested operation not supported in current context */
    U_RESOURCE_TYPE_MISMATCH  = 17,     /**< an operation is requested over a resource that does not support it */
    U_ILLEGAL_ESCAPE_SEQUENCE = 18,     /**< ISO-2022 illegal escape sequence */
    U_UNSUPPORTED_ESCAPE_SEQUENCE = 19, /**< ISO-2022 unsupported escape sequence */
    U_NO_SPACE_AVAILABLE      = 20,     /**< No space available for in-buffer expansion for Arabic shaping */
    U_CE_NOT_FOUND_ERROR      = 21,     /**< Currently used only while setting variable top, but can be used generally */
    U_PRIMARY_TOO_LONG_ERROR  = 22,     /**< User tried to set variable top to a primary that is longer than two bytes */
    U_STATE_TOO_OLD_ERROR     = 23,     /**< ICU cannot construct a service from this state, as it is no longer supported */
    U_TOO_MANY_ALIASES_ERROR  = 24,     /**< There are too many aliases in the path to the requested resource.
                                             It is very possible that a circular alias definition has occurred */
    U_ENUM_OUT_OF_SYNC_ERROR  = 25,     /**< UEnumeration out of sync with underlying collection */
    U_INVARIANT_CONVERSION_ERROR = 26,  /**< Unable to convert a UChar* string to char* with the invariant converter. */
    U_INVALID_STATE_ERROR     = 27,     /**< Requested operation can not be completed with ICU in its current state */
    U_COLLATOR_VERSION_MISMATCH = 28,   /**< Collator version is not compatible with the base version */
    U_USELESS_COLLATOR_ERROR  = 29,     /**< Collator is options only and no base is specified */
    U_NO_WRITE_PERMISSION     = 30,     /**< Attempt to modify read-only or constant data. */

#ifndef U_HIDE_DEPRECATED_API
    /**
     * One more than the highest standard error code.
     * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
     */
    U_STANDARD_ERROR_LIMIT,
#endif  // U_HIDE_DEPRECATED_API

    /*
     * Error codes in the range 0x10000 0x10100 are reserved for Transliterator.
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
    U_MALFORMED_PRAGMA,               /**< A 'use' pragma is invalid */
    U_UNCLOSED_SEGMENT,               /**< A closing ')' is missing */
    U_ILLEGAL_CHAR_IN_SEGMENT,        /**< UNUSED as of ICU 2.4 */
    U_VARIABLE_RANGE_EXHAUSTED,       /**< Too many stand-ins generated for the given variable range */
    U_VARIABLE_RANGE_OVERLAP,         /**< The variable range overlaps characters used in rules */
    U_ILLEGAL_CHARACTER,              /**< A special character is outside its allowed context */
    U_INTERNAL_TRANSLITERATOR_ERROR,  /**< Internal transliterator system error */
    U_INVALID_ID,                     /**< A "::id" rule specifies an unknown transliterator */
    U_INVALID_FUNCTION,               /**< A "&fn()" rule specifies an unknown transliterator */
#ifndef U_HIDE_DEPRECATED_API
    /**
     * One more than the highest normal Transliterator error code.
     * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
     */
    U_PARSE_ERROR_LIMIT,
#endif  // U_HIDE_DEPRECATED_API

    /*
     * Error codes in the range 0x10100 0x10200 are reserved for the formatting API.
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
    U_ARGUMENT_TYPE_MISMATCH,         /**< Argument name and argument index mismatch in MessageFormat functions */
    U_DUPLICATE_KEYWORD,              /**< Duplicate keyword in PluralFormat */
    U_UNDEFINED_KEYWORD,              /**< Undefined Plural keyword */
    U_DEFAULT_KEYWORD_MISSING,        /**< Missing DEFAULT rule in plural rules */
    U_DECIMAL_NUMBER_SYNTAX_ERROR,    /**< Decimal number syntax error */
    U_FORMAT_INEXACT_ERROR,           /**< Cannot format a number exactly and rounding mode is ROUND_UNNECESSARY @stable ICU 4.8 */
#ifndef U_HIDE_DRAFT_API
    U_NUMBER_ARG_OUTOFBOUNDS_ERROR,   /**< The argument to a NumberFormatter helper method was out of bounds; the bounds are usually 0 to 999. @draft ICU 61 */
#endif  // U_HIDE_DRAFT_API
#ifndef U_HIDE_DRAFT_API
    U_NUMBER_SKELETON_SYNTAX_ERROR,   /**< The number skeleton passed to C++ NumberFormatter or C UNumberFormatter was invalid or contained a syntax error. @draft ICU 62 */
#endif  // U_HIDE_DRAFT_API
#ifndef U_HIDE_DEPRECATED_API
    /**
     * One more than the highest normal formatting API error code.
     * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
     */
    U_FMT_PARSE_ERROR_LIMIT = 0x10114,
#endif  // U_HIDE_DEPRECATED_API

    /*
     * Error codes in the range 0x10200 0x102ff are reserved for BreakIterator.
     */
    U_BRK_INTERNAL_ERROR=0x10200,          /**< An internal error (bug) was detected.             */
    U_BRK_ERROR_START=0x10200,             /**< Start of codes indicating Break Iterator failures */
    U_BRK_HEX_DIGITS_EXPECTED,             /**< Hex digits expected as part of a escaped char in a rule. */
    U_BRK_SEMICOLON_EXPECTED,              /**< Missing ';' at the end of a RBBI rule.            */
    U_BRK_RULE_SYNTAX,                     /**< Syntax error in RBBI rule.                        */
    U_BRK_UNCLOSED_SET,                    /**< UnicodeSet writing an RBBI rule missing a closing ']'. */
    U_BRK_ASSIGN_ERROR,                    /**< Syntax error in RBBI rule assignment statement.   */
    U_BRK_VARIABLE_REDFINITION,            /**< RBBI rule $Variable redefined.                    */
    U_BRK_MISMATCHED_PAREN,                /**< Mis-matched parentheses in an RBBI rule.          */
    U_BRK_NEW_LINE_IN_QUOTED_STRING,       /**< Missing closing quote in an RBBI rule.            */
    U_BRK_UNDEFINED_VARIABLE,              /**< Use of an undefined $Variable in an RBBI rule.    */
    U_BRK_INIT_ERROR,                      /**< Initialization failure.  Probable missing ICU Data. */
    U_BRK_RULE_EMPTY_SET,                  /**< Rule contains an empty Unicode Set.               */
    U_BRK_UNRECOGNIZED_OPTION,             /**< !!option in RBBI rules not recognized.            */
    U_BRK_MALFORMED_RULE_TAG,              /**< The {nnn} tag on a rule is malformed              */
#ifndef U_HIDE_DEPRECATED_API
    /**
     * One more than the highest normal BreakIterator error code.
     * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
     */
    U_BRK_ERROR_LIMIT,
#endif  // U_HIDE_DEPRECATED_API

    /*
     * Error codes in the range 0x10300-0x103ff are reserved for regular expression related errors.
     */
    U_REGEX_INTERNAL_ERROR=0x10300,       /**< An internal error (bug) was detected.              */
    U_REGEX_ERROR_START=0x10300,          /**< Start of codes indicating Regexp failures          */
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
#ifndef U_HIDE_DEPRECATED_API
    U_REGEX_OCTAL_TOO_BIG,                /**< Octal character constants must be <= 0377. @deprecated ICU 54. This error cannot occur. */
#endif  /* U_HIDE_DEPRECATED_API */
    U_REGEX_MISSING_CLOSE_BRACKET=U_REGEX_SET_CONTAINS_STRING+2, /**< Missing closing bracket on a bracket expression. */
    U_REGEX_INVALID_RANGE,                /**< In a character range [x-y], x is greater than y.   */
    U_REGEX_STACK_OVERFLOW,               /**< Regular expression backtrack stack overflow.       */
    U_REGEX_TIME_OUT,                     /**< Maximum allowed match time exceeded                */
    U_REGEX_STOPPED_BY_CALLER,            /**< Matching operation aborted by user callback fn.    */
    U_REGEX_PATTERN_TOO_BIG,              /**< Pattern exceeds limits on size or complexity. @stable ICU 55 */
    U_REGEX_INVALID_CAPTURE_GROUP_NAME,   /**< Invalid capture group name. @stable ICU 55 */
#ifndef U_HIDE_DEPRECATED_API
    /**
     * One more than the highest normal regular expression error code.
     * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
     */
    U_REGEX_ERROR_LIMIT=U_REGEX_STOPPED_BY_CALLER+3,
#endif  // U_HIDE_DEPRECATED_API

    /*
     * Error codes in the range 0x10400-0x104ff are reserved for IDNA related error codes.
     */
    U_IDNA_PROHIBITED_ERROR=0x10400,
    U_IDNA_ERROR_START=0x10400,
    U_IDNA_UNASSIGNED_ERROR,
    U_IDNA_CHECK_BIDI_ERROR,
    U_IDNA_STD3_ASCII_RULES_ERROR,
    U_IDNA_ACE_PREFIX_ERROR,
    U_IDNA_VERIFICATION_ERROR,
    U_IDNA_LABEL_TOO_LONG_ERROR,
    U_IDNA_ZERO_LENGTH_LABEL_ERROR,
    U_IDNA_DOMAIN_NAME_TOO_LONG_ERROR,
#ifndef U_HIDE_DEPRECATED_API
    /**
     * One more than the highest normal IDNA error code.
     * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
     */
    U_IDNA_ERROR_LIMIT,
#endif  // U_HIDE_DEPRECATED_API
    /*
     * Aliases for StringPrep
     */
    U_STRINGPREP_PROHIBITED_ERROR = U_IDNA_PROHIBITED_ERROR,
    U_STRINGPREP_UNASSIGNED_ERROR = U_IDNA_UNASSIGNED_ERROR,
    U_STRINGPREP_CHECK_BIDI_ERROR = U_IDNA_CHECK_BIDI_ERROR,

    /*
     * Error codes in the range 0x10500-0x105ff are reserved for Plugin related error codes.
     */
    U_PLUGIN_ERROR_START=0x10500,         /**< Start of codes indicating plugin failures */
    U_PLUGIN_TOO_HIGH=0x10500,            /**< The plugin's level is too high to be loaded right now. */
    U_PLUGIN_DIDNT_SET_LEVEL,             /**< The plugin didn't call uplug_setPlugLevel in response to a QUERY */
#ifndef U_HIDE_DEPRECATED_API
    /**
     * One more than the highest normal plug-in error code.
     * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
     */
    U_PLUGIN_ERROR_LIMIT,
#endif  // U_HIDE_DEPRECATED_API

#ifndef U_HIDE_DEPRECATED_API
    /**
     * One more than the highest normal error code.
     * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
     */
    U_ERROR_LIMIT=U_PLUGIN_ERROR_LIMIT
#endif  // U_HIDE_DEPRECATED_API
} UErrorCode;

////////////////////////////////////////////////////////////////////////////////

/**
 * Does the error code indicate success?
 * @stable ICU 2.0
 */
inline UBool U_SUCCESS(UErrorCode code) { return (UBool)(code<=U_ZERO_ERROR); }

/**
 * Does the error code indicate a failure?
 * @stable ICU 2.0
 */
inline UBool U_FAILURE(UErrorCode code) { return (UBool)(code>U_ZERO_ERROR); }

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
                             'reset' has occurred. Callback should reset all
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
typedef enum
{
    /** @stable ICU 2.0 */
    UCNV_UNSUPPORTED_CONVERTER = -1,
    /** @stable ICU 2.0 */
    UCNV_SBCS = 0,
    /** @stable ICU 2.0 */
    UCNV_DBCS = 1,
    /** @stable ICU 2.0 */
    UCNV_MBCS = 2,
    /** @stable ICU 2.0 */
    UCNV_LATIN_1 = 3,
    /** @stable ICU 2.0 */
    UCNV_UTF8 = 4,
    /** @stable ICU 2.0 */
    UCNV_UTF16_BigEndian = 5,
    /** @stable ICU 2.0 */
    UCNV_UTF16_LittleEndian = 6,
    /** @stable ICU 2.0 */
    UCNV_UTF32_BigEndian = 7,
    /** @stable ICU 2.0 */
    UCNV_UTF32_LittleEndian = 8,
    /** @stable ICU 2.0 */
    UCNV_EBCDIC_STATEFUL = 9,
    /** @stable ICU 2.0 */
    UCNV_ISO_2022 = 10,

    /** @stable ICU 2.0 */
    UCNV_LMBCS_1 = 11,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_2,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_3,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_4,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_5,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_6,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_8,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_11,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_16,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_17,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_18,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_19,
    /** @stable ICU 2.0 */
    UCNV_LMBCS_LAST = UCNV_LMBCS_19,
    /** @stable ICU 2.0 */
    UCNV_HZ,
    /** @stable ICU 2.0 */
    UCNV_SCSU,
    /** @stable ICU 2.0 */
    UCNV_ISCII,
    /** @stable ICU 2.0 */
    UCNV_US_ASCII,
    /** @stable ICU 2.0 */
    UCNV_UTF7,
    /** @stable ICU 2.2 */
    UCNV_BOCU1,
    /** @stable ICU 2.2 */
    UCNV_UTF16,
    /** @stable ICU 2.2 */
    UCNV_UTF32,
    /** @stable ICU 2.2 */
    UCNV_CESU8,
    /** @stable ICU 2.4 */
    UCNV_IMAP_MAILBOX,
    /** @stable ICU 4.8 */
    UCNV_COMPOUND_TEXT,

    /* Number of converter types for which we have conversion routines. */
    UCNV_NUMBER_OF_SUPPORTED_CONVERTER_TYPES
} UConverterType;

////////////////////////////////////////////////////////////////////////////////
//struct UConverterToUnicodeArgs

/**
 * The structure for the toUnicode callback function parameter.
 * @stable ICU 2.0
 */
typedef struct
{
    uint16_t     size;          /**< The size of this struct   @stable ICU 2.0 */
    UBool        flush;         /**< The internal state of converter will be reset and data flushed if set to TRUE. @stable ICU 2.0   */
    UConverter*  converter;     /**< Pointer to the converter that is opened and to which this struct is passed as an argument. @stable ICU 2.0 */
    const char*  source;        /**< Pointer to the source source buffer. @stable ICU 2.0    */
    const char*  sourceLimit;   /**< Pointer to the limit (end + 1) of source buffer. @stable ICU 2.0    */
    UChar*       target;        /**< Pointer to the target buffer. @stable ICU 2.0    */
    const UChar* targetLimit;   /**< Pointer to the limit (end + 1) of target buffer. @stable ICU 2.0     */
    int32_t*     offsets;       /**< Pointer to the buffer that receives the offsets. *offset = blah ; offset++;. @stable ICU 2.0  */
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
    int32_t*       offsets;        /**< Pointer to the buffer that receives the offsets. *offset = blah ; offset++;. @stable ICU 2.0  */
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
 * Called when an error has occurred in conversion to unicode, or on open/close of the callback (see reason).
 * @param context Pointer to the callback's private data
 * @param args Information about the conversion in progress
 * @param codeUnits Points to 'length' bytes of the concerned codepage sequence
 * @param length Size (in bytes) of the concerned codepage sequence
 * @param reason Defines the reason the callback was invoked
 * @param pErrorCode    ICU error code in/out parameter.
 *                      For converter callback functions, set to a conversion error
 *                      before the call, and the callback may reset it to U_ZERO_ERROR.
 * @see ucnv_setToUCallBack
 * @see UConverterToUnicodeArgs
 * @stable ICU 2.0
 */
typedef void (ICU_EXPORT2* UConverterToUCallback)
 (const void*              context,
  UConverterToUnicodeArgs* args,
  const char*              codeUnits,
  int32_t                  length,
  UConverterCallbackReason reason,
  UErrorCode*              pErrorCode);

//------------------------------------------------------------------------

/**
 * Function pointer for error callback in the unicode to codepage direction.
 * Called when an error has occurred in conversion from unicode, or on open/close of the callback (see reason).
 * @param context Pointer to the callback's private data
 * @param args Information about the conversion in progress
 * @param codeUnits Points to 'length' UChars of the concerned Unicode sequence
 * @param length Size (in bytes) of the concerned codepage sequence
 * @param codePoint Single UChar32 (UTF-32) containing the concerend Unicode codepoint.
 * @param reason Defines the reason the callback was invoked
 * @param pErrorCode    ICU error code in/out parameter.
 *                      For converter callback functions, set to a conversion error
 *                      before the call, and the callback may reset it to U_ZERO_ERROR.
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
  UErrorCode*                pErrorCode);

////////////////////////////////////////////////////////////////////////////////
/**
 * Creates a UConverter object with the name of a coded character set specified as a C string.
 * The actual name will be resolved with the alias file
 * using a case-insensitive string comparison that ignores
 * leading zeroes and all non-alphanumeric characters.
 * E.g., the names "UTF8", "utf-8", "u*T@f08" and "Utf 8" are all equivalent.
 * (See also ucnv_compareNames().)
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
 * are in the <a href="http://icu-project.org/userguide/conversion.html">User's
 * Guide</a>. Aliases starting with a "cp" prefix have no specific meaning
 * other than its an alias starting with the letters "cp". Please do not
 * associate any meaning to these aliases.</p>
 *
 * \snippet samples/ucnv/convsamp.cpp ucnv_open
 *
 * @param converterName Name of the coded character set table.
 *          This may have options appended to the string.
 *          IANA alias character set names, IBM CCSIDs starting with "ibm-",
 *          Windows codepage numbers starting with "windows-" are frequently
 *          used for this parameter. See ucnv_getAvailableName and
 *          ucnv_getAlias for a complete list that is available.
 *          If this parameter is NULL, the default converter will be used.
 * @param err outgoing error status <TT>U_MEMORY_ALLOCATION_ERROR, U_FILE_ACCESS_ERROR</TT>
 * @return the created Unicode converter object, or <TT>NULL</TT> if an error occurred
 * @see ucnv_openU
 * @see ucnv_openCCSID
 * @see ucnv_getAvailableName
 * @see ucnv_getAlias
 * @see ucnv_getDefaultName
 * @see ucnv_close
 * @see ucnv_compareNames
 * @stable ICU 2.0
 */

typedef UConverter* (ICU_EXPORT2 ICU_FN(ucnv_open))
 (const char* converterName,
  UErrorCode* err);

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
 (UConverter*   converter,
  char**        target,
  const char*   targetLimit,
  const UChar** source,
  const UChar*  sourceLimit,
  int32_t*      offsets,
  UBool         flush,
  UErrorCode*   err);

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
 * Returns the minimum byte length (per codepoint) for characters in this codepage.
 * This is usually either 1 or 2.
 * @param converter the Unicode converter
 * @return the minimum number of bytes per codepoint allowed by this particular converter
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
 * @return The maximum number of bytes per UChar (16 bit code unit)
 *    that are output by ucnv_fromUnicode(),
 *    to be used together with UCNV_GET_MAX_BYTES_FOR_STRING
 *    for buffer allocation.
 *
 * @see UCNV_GET_MAX_BYTES_FOR_STRING
 * @see ucnv_getMinCharSize
 * @stable ICU 2.0
 */

typedef int8_t (ICU_EXPORT2 ICU_FN(ucnv_getMaxCharSize))
 (const UConverter* converter);

////////////////////////////////////////////////////////////////////////////////

/**
 *  Initialize ICU.
 *
 *  Use of this function is optional.  It is OK to simply use ICU
 *  services and functions without first having initialized
 *  ICU by calling u_init().
 *
 *  u_init() will attempt to load some part of ICU's data, and is
 *  useful as a test for configuration or installation problems that
 *  leave the ICU data inaccessible.  A successful invocation of u_init()
 *  does not, however, guarantee that all ICU data is accessible.
 *
 *  Multiple calls to u_init() cause no harm, aside from the small amount
 *  of time required.
 *
 *  In old versions of ICU, u_init() was required in multi-threaded applications
 *  to ensure the thread safety of ICU.  u_init() is no longer needed for this purpose.
 *
 * @param status An ICU UErrorCode parameter. It must not be <code>NULL</code>.
 *    An Error will be returned if some required part of ICU data can not
 *    be loaded or initialized.
 *    The function returns immediately if the input error code indicates a
 *    failure, as usual.
 *
 * @stable ICU 2.6
 */

typedef void (ICU_EXPORT2 ICU_FN(u_init))
 (UErrorCode* status);

////////////////////////////////////////////////////////////////////////////////

/**
 * Clean up the system resources, such as allocated memory or open files,
 * used in all ICU libraries. This will free/delete all memory owned by the
 * ICU libraries, and return them to their original load state. All open ICU
 * items (collators, resource bundles, converters, etc.) must be closed before
 * calling this function, otherwise ICU may not free its allocated memory
 * (e.g. close your converters and resource bundles before calling this
 * function). Generally, this function should be called once just before
 * an application exits. For applications that dynamically load and unload
 * the ICU libraries (relatively uncommon), u_cleanup() should be called
 * just before the library unload.
 * <p>
 * u_cleanup() also clears any ICU heap functions, mutex functions or
 * trace functions that may have been set for the process.
 * This has the effect of restoring ICU to its initial condition, before
 * any of these override functions were installed.  Refer to
 * u_setMemoryFunctions(), u_setMutexFunctions and
 * utrace_setFunctions().  If ICU is to be reinitialized after
 * calling u_cleanup(), these runtime override functions will need to
 * be set up again if they are still required.
 * <p>
 * u_cleanup() is not thread safe.  All other threads should stop using ICU
 * before calling this function.
 * <p>
 * Any open ICU items will be left in an undefined state by u_cleanup(),
 * and any subsequent attempt to use such an item will give unpredictable
 * results.
 * <p>
 * After calling u_cleanup(), an application may continue to use ICU by
 * calling u_init().  An application must invoke u_init() first from one single
 * thread before allowing other threads call u_init().  All threads existing
 * at the time of the first thread's call to u_init() must also call
 * u_init() themselves before continuing with other ICU operations.
 * <p>
 * The use of u_cleanup() just before an application terminates is optional,
 * but it should be called only once for performance reasons. The primary
 * benefit is to eliminate reports of memory or resource leaks originating
 * in ICU code from the results generated by heap analysis tools.
 * <p>
 * <strong>Use this function with great care!</strong>
 * </p>
 *
 * @stable ICU 2.0
 * @system
 */

typedef void (ICU_EXPORT2 ICU_FN(u_cleanup))
 (void);

////////////////////////////////////////////////////////////////////////////////

/**
 * Set the ICU data directory.
 * The data directory is where common format ICU data files (.dat files)
 *   are loaded from.  Note that normal use of the built-in ICU
 *   facilities does not require loading of an external data file;
 *   unless you are adding custom data to ICU, the data directory
 *   does not need to be set.
 *
 * This function should be called at most once in a process, before the
 * first ICU operation (e.g., u_init()) that will require the loading of an
 * ICU data file.
 * This function is not thread-safe. Use it before calling ICU APIs from
 * multiple threads.
 *
 * @param directory The directory to be set.
 *
 * @see u_init
 * @stable ICU 2.0
 */

typedef void (ICU_EXPORT2 ICU_FN(u_setDataDirectory))
 (const char* directory);

////////////////////////////////////////////////////////////////////////////////

/**
 * Disposes of resources in use by the iterator.  If en is NULL,
 * does nothing.  After this call, any char* or UChar* pointer
 * returned by uenum_unext() or uenum_next() is invalid.
 * @param en UEnumeration structure pointer
 * @stable ICU 2.2
 */
typedef void (ICU_EXPORT2 ICU_FN(uenum_close))
 (UEnumeration* en);

////////////////////////////////////////////////////////////////////////////////

/**
 * Returns the next element in the iterator's list.  If there are
 * no more elements, returns NULL.  If the iterator is out-of-sync
 * with its service, status is set to U_ENUM_OUT_OF_SYNC_ERROR and
 * NULL is returned.  If the native service string is a char* string,
 * it is converted to UChar* with the invariant converter.
 * The result is terminated by (UChar)0.
 * @param en the iterator object
 * @param resultLength pointer to receive the length of the result
 *                     (not including the terminating \\0).
 *                     If the pointer is NULL it is ignored.
 * @param status the error code, set to U_ENUM_OUT_OF_SYNC_ERROR if
 *               the iterator is out of sync with its service.
 * @return a pointer to the string.  The string will be
 *         zero-terminated.  The return pointer is owned by this iterator
 *         and must not be deleted by the caller.  The pointer is valid
 *         until the next call to any uenum_... method, including
 *         uenum_next() or uenum_unext().  When all strings have been
 *         traversed, returns NULL.
 * @stable ICU 2.2
 */
typedef const UChar* (ICU_EXPORT2 ICU_FN(uenum_unext))
 (UEnumeration* en,
  int32_t*      resultLength,
  UErrorCode*   status);

////////////////////////////////////////////////////////////////////////////////

/**
 * The time zone ID reserved for unknown time zone.
 * @stable ICU 4.8
 */
extern const UChar* const UCAL_UNKNOWN_ZONE_ID; // L"Etc/Unknown"

////////////////////////////////////////////////////////////////////////////////

/**
 * Date and Time data type.
 * This is a primitive data type that holds the date and time
 * as the number of milliseconds since 1970-jan-01, 00:00 UTC.
 * UTC leap seconds are ignored.
 * @stable ICU 2.0
 */
typedef double UDate;

////////////////////////////////////////////////////////////////////////////////

/**
 * \file
 * \brief C API: Calendar
 *
 * <h2>Calendar C API</h2>
 *
 * UCalendar C API is used  for converting between a <code>UDate</code> object
 * and a set of integer fields such as <code>UCAL_YEAR</code>, <code>UCAL_MONTH</code>,
 * <code>UCAL_DAY</code>, <code>UCAL_HOUR</code>, and so on.
 * (A <code>UDate</code> object represents a specific instant in
 * time with millisecond precision. See UDate
 * for information about the <code>UDate</code> .)
 *
 * <p>
 * Types of <code>UCalendar</code> interpret a <code>UDate</code>
 * according to the rules of a specific calendar system. The U_STABLE
 * provides the enum UCalendarType with UCAL_TRADITIONAL and
 * UCAL_GREGORIAN.
 * <p>
 * Like other locale-sensitive C API, calendar API  provides a
 * function, <code>ucal_open()</code>, which returns a pointer to
 * <code>UCalendar</code> whose time fields have been initialized
 * with the current date and time. We need to specify the type of
 * calendar to be opened and the  timezoneId.
 * \htmlonly<blockquote>\endhtmlonly
 * <pre>
 * \code
 * UCalendar *caldef;
 * UChar *tzId;
 * UErrorCode status;
 * tzId=(UChar*)malloc(sizeof(UChar) * (strlen("PST") +1) );
 * u_uastrcpy(tzId, "PST");
 * caldef=ucal_open(tzID, u_strlen(tzID), NULL, UCAL_TRADITIONAL, &status);
 * \endcode
 * </pre>
 * \htmlonly</blockquote>\endhtmlonly
 *
 * <p>
 * A <code>UCalendar</code> object can produce all the time field values
 * needed to implement the date-time formatting for a particular language
 * and calendar style (for example, Japanese-Gregorian, Japanese-Traditional).
 *
 * <p>
 * When computing a <code>UDate</code> from time fields, two special circumstances
 * may arise: there may be insufficient information to compute the
 * <code>UDate</code> (such as only year and month but no day in the month),
 * or there may be inconsistent information (such as "Tuesday, July 15, 1996"
 * -- July 15, 1996 is actually a Monday).
 *
 * <p>
 * <strong>Insufficient information.</strong> The calendar will use default
 * information to specify the missing fields. This may vary by calendar; for
 * the Gregorian calendar, the default for a field is the same as that of the
 * start of the epoch: i.e., UCAL_YEAR = 1970, UCAL_MONTH = JANUARY, UCAL_DATE = 1, etc.
 *
 * <p>
 * <strong>Inconsistent information.</strong> If fields conflict, the calendar
 * will give preference to fields set more recently. For example, when
 * determining the day, the calendar will look for one of the following
 * combinations of fields.  The most recent combination, as determined by the
 * most recently set single field, will be used.
 *
 * \htmlonly<blockquote>\endhtmlonly
 * <pre>
 * \code
 * UCAL_MONTH + UCAL_DAY_OF_MONTH
 * UCAL_MONTH + UCAL_WEEK_OF_MONTH + UCAL_DAY_OF_WEEK
 * UCAL_MONTH + UCAL_DAY_OF_WEEK_IN_MONTH + UCAL_DAY_OF_WEEK
 * UCAL_DAY_OF_YEAR
 * UCAL_DAY_OF_WEEK + UCAL_WEEK_OF_YEAR
 * \endcode
 * </pre>
 * \htmlonly</blockquote>\endhtmlonly
 *
 * For the time of day:
 *
 * \htmlonly<blockquote>\endhtmlonly
 * <pre>
 * \code
 * UCAL_HOUR_OF_DAY
 * UCAL_AM_PM + UCAL_HOUR
 * \endcode
 * </pre>
 * \htmlonly</blockquote>\endhtmlonly
 *
 * <p>
 * <strong>Note:</strong> for some non-Gregorian calendars, different
 * fields may be necessary for complete disambiguation. For example, a full
 * specification of the historial Arabic astronomical calendar requires year,
 * month, day-of-month <em>and</em> day-of-week in some cases.
 *
 * <p>
 * <strong>Note:</strong> There are certain possible ambiguities in
 * interpretation of certain singular times, which are resolved in the
 * following ways:
 * <ol>
 *     <li> 24:00:00 "belongs" to the following day. That is,
 *          23:59 on Dec 31, 1969 &lt; 24:00 on Jan 1, 1970 &lt; 24:01:00 on Jan 1, 1970
 *
 *     <li> Although historically not precise, midnight also belongs to "am",
 *          and noon belongs to "pm", so on the same day,
 *          12:00 am (midnight) &lt; 12:01 am, and 12:00 pm (noon) &lt; 12:01 pm
 * </ol>
 *
 * <p>
 * The date or time format strings are not part of the definition of a
 * calendar, as those must be modifiable or overridable by the user at
 * runtime. Use {@link icu::DateFormat}
 * to format dates.
 *
 * <p>
 * <code>Calendar</code> provides an API for field "rolling", where fields
 * can be incremented or decremented, but wrap around. For example, rolling the
 * month up in the date <code>December 12, <b>1996</b></code> results in
 * <code>January 12, <b>1996</b></code>.
 *
 * <p>
 * <code>Calendar</code> also provides a date arithmetic function for
 * adding the specified (signed) amount of time to a particular time field.
 * For example, subtracting 5 days from the date <code>September 12, 1996</code>
 * results in <code>September 7, 1996</code>.
 *
 * <p>
 * The Japanese calendar uses a combination of era name and year number.
 * When an emperor of Japan abdicates and a new emperor ascends the throne,
 * a new era is declared and year number is reset to 1. Even if the date of
 * abdication is scheduled ahead of time, the new era name might not be
 * announced until just before the date. In such case, ICU4C may include
 * a start date of future era without actual era name, but not enabled
 * by default. ICU4C users who want to test the behavior of the future era
 * can enable the tentative era by:
 * <ul>
 * <li>Environment variable <code>ICU_ENABLE_TENTATIVE_ERA=true</code>.</li>
 * </ul>
 *
 * @stable ICU 2.0
 */

/** A calendar.
 *  For usage in C programs.
 * @stable ICU 2.0
 */
typedef void* UCalendar;

////////////////////////////////////////////////////////////////////////////////
//enum UCalendarType

/** Possible types of UCalendars
 * @stable ICU 2.0
 */
enum UCalendarType
{
  /**
   * Despite the name, UCAL_TRADITIONAL designates the locale's default calendar,
   * which may be the Gregorian calendar or some other calendar.
   * @stable ICU 2.0
   */
  UCAL_TRADITIONAL,
  /**
   * A better name for UCAL_TRADITIONAL.
   * @stable ICU 4.2
   */
  UCAL_DEFAULT = UCAL_TRADITIONAL,
  /**
   * Unambiguously designates the Gregorian calendar for the locale.
   * @stable ICU 2.0
   */
  UCAL_GREGORIAN
};

/** @stable ICU 2.0 */
typedef enum UCalendarType UCalendarType;

////////////////////////////////////////////////////////////////////////////////
//enum UCalendarDateFields

/** Possible fields in a UCalendar
 * @stable ICU 2.0
 */
enum UCalendarDateFields
{
  /**
   * Field number indicating the era, e.g., AD or BC in the Gregorian (Julian) calendar.
   * This is a calendar-specific value.
   * @stable ICU 2.6
   */
  UCAL_ERA,

  /**
   * Field number indicating the year. This is a calendar-specific value.
   * @stable ICU 2.6
   */
  UCAL_YEAR,

  /**
   * Field number indicating the month. This is a calendar-specific value.
   * The first month of the year is
   * <code>JANUARY</code>; the last depends on the number of months in a year.
   * @see #UCAL_JANUARY
   * @see #UCAL_FEBRUARY
   * @see #UCAL_MARCH
   * @see #UCAL_APRIL
   * @see #UCAL_MAY
   * @see #UCAL_JUNE
   * @see #UCAL_JULY
   * @see #UCAL_AUGUST
   * @see #UCAL_SEPTEMBER
   * @see #UCAL_OCTOBER
   * @see #UCAL_NOVEMBER
   * @see #UCAL_DECEMBER
   * @see #UCAL_UNDECIMBER
   * @stable ICU 2.6
   */
  UCAL_MONTH,

  /**
   * Field number indicating the
   * week number within the current year.  The first week of the year, as
   * defined by <code>UCAL_FIRST_DAY_OF_WEEK</code> and <code>UCAL_MINIMAL_DAYS_IN_FIRST_WEEK</code>
   * attributes, has value 1.  Subclasses define
   * the value of <code>UCAL_WEEK_OF_YEAR</code> for days before the first week of
   * the year.
   * @see ucal_getAttribute
   * @see ucal_setAttribute
   * @stable ICU 2.6
   */
  UCAL_WEEK_OF_YEAR,

 /**
   * Field number indicating the
   * week number within the current month.  The first week of the month, as
   * defined by <code>UCAL_FIRST_DAY_OF_WEEK</code> and <code>UCAL_MINIMAL_DAYS_IN_FIRST_WEEK</code>
   * attributes, has value 1.  Subclasses define
   * the value of <code>WEEK_OF_MONTH</code> for days before the first week of
   * the month.
   * @see ucal_getAttribute
   * @see ucal_setAttribute
   * @see #UCAL_FIRST_DAY_OF_WEEK
   * @see #UCAL_MINIMAL_DAYS_IN_FIRST_WEEK
   * @stable ICU 2.6
   */
  UCAL_WEEK_OF_MONTH,

 /**
   * Field number indicating the
   * day of the month. This is a synonym for <code>DAY_OF_MONTH</code>.
   * The first day of the month has value 1.
   * @see #UCAL_DAY_OF_MONTH
   * @stable ICU 2.6
   */
  UCAL_DATE,

 /**
   * Field number indicating the day
   * number within the current year.  The first day of the year has value 1.
   * @stable ICU 2.6
   */
  UCAL_DAY_OF_YEAR,

 /**
   * Field number indicating the day
   * of the week.  This field takes values <code>SUNDAY</code>,
   * <code>MONDAY</code>, <code>TUESDAY</code>, <code>WEDNESDAY</code>,
   * <code>THURSDAY</code>, <code>FRIDAY</code>, and <code>SATURDAY</code>.
   * @see #UCAL_SUNDAY
   * @see #UCAL_MONDAY
   * @see #UCAL_TUESDAY
   * @see #UCAL_WEDNESDAY
   * @see #UCAL_THURSDAY
   * @see #UCAL_FRIDAY
   * @see #UCAL_SATURDAY
   * @stable ICU 2.6
   */
  UCAL_DAY_OF_WEEK,

 /**
   * Field number indicating the
   * ordinal number of the day of the week within the current month. Together
   * with the <code>DAY_OF_WEEK</code> field, this uniquely specifies a day
   * within a month.  Unlike <code>WEEK_OF_MONTH</code> and
   * <code>WEEK_OF_YEAR</code>, this field's value does <em>not</em> depend on
   * <code>getFirstDayOfWeek()</code> or
   * <code>getMinimalDaysInFirstWeek()</code>.  <code>DAY_OF_MONTH 1</code>
   * through <code>7</code> always correspond to <code>DAY_OF_WEEK_IN_MONTH
   * 1</code>; <code>8</code> through <code>15</code> correspond to
   * <code>DAY_OF_WEEK_IN_MONTH 2</code>, and so on.
   * <code>DAY_OF_WEEK_IN_MONTH 0</code> indicates the week before
   * <code>DAY_OF_WEEK_IN_MONTH 1</code>.  Negative values count back from the
   * end of the month, so the last Sunday of a month is specified as
   * <code>DAY_OF_WEEK = SUNDAY, DAY_OF_WEEK_IN_MONTH = -1</code>.  Because
   * negative values count backward they will usually be aligned differently
   * within the month than positive values.  For example, if a month has 31
   * days, <code>DAY_OF_WEEK_IN_MONTH -1</code> will overlap
   * <code>DAY_OF_WEEK_IN_MONTH 5</code> and the end of <code>4</code>.
   * @see #UCAL_DAY_OF_WEEK
   * @see #UCAL_WEEK_OF_MONTH
   * @stable ICU 2.6
   */
  UCAL_DAY_OF_WEEK_IN_MONTH,

 /**
   * Field number indicating
   * whether the <code>HOUR</code> is before or after noon.
   * E.g., at 10:04:15.250 PM the <code>AM_PM</code> is <code>PM</code>.
   * @see #UCAL_AM
   * @see #UCAL_PM
   * @see #UCAL_HOUR
   * @stable ICU 2.6
   */
  UCAL_AM_PM,

 /**
   * Field number indicating the
   * hour of the morning or afternoon. <code>HOUR</code> is used for the 12-hour
   * clock.
   * E.g., at 10:04:15.250 PM the <code>HOUR</code> is 10.
   * @see #UCAL_AM_PM
   * @see #UCAL_HOUR_OF_DAY
   * @stable ICU 2.6
   */
  UCAL_HOUR,

 /**
   * Field number indicating the
   * hour of the day. <code>HOUR_OF_DAY</code> is used for the 24-hour clock.
   * E.g., at 10:04:15.250 PM the <code>HOUR_OF_DAY</code> is 22.
   * @see #UCAL_HOUR
   * @stable ICU 2.6
   */
  UCAL_HOUR_OF_DAY,

 /**
   * Field number indicating the
   * minute within the hour.
   * E.g., at 10:04:15.250 PM the <code>UCAL_MINUTE</code> is 4.
   * @stable ICU 2.6
   */
  UCAL_MINUTE,

 /**
   * Field number indicating the
   * second within the minute.
   * E.g., at 10:04:15.250 PM the <code>UCAL_SECOND</code> is 15.
   * @stable ICU 2.6
   */
  UCAL_SECOND,

 /**
   * Field number indicating the
   * millisecond within the second.
   * E.g., at 10:04:15.250 PM the <code>UCAL_MILLISECOND</code> is 250.
   * @stable ICU 2.6
   */
  UCAL_MILLISECOND,

 /**
   * Field number indicating the
   * raw offset from GMT in milliseconds.
   * @stable ICU 2.6
   */
  UCAL_ZONE_OFFSET,

 /**
   * Field number indicating the
   * daylight savings offset in milliseconds.
   * @stable ICU 2.6
   */
  UCAL_DST_OFFSET,

 /**
   * Field number
   * indicating the extended year corresponding to the
   * <code>UCAL_WEEK_OF_YEAR</code> field.  This may be one greater or less
   * than the value of <code>UCAL_EXTENDED_YEAR</code>.
   * @stable ICU 2.6
   */
  UCAL_YEAR_WOY,

 /**
   * Field number
   * indicating the localized day of week.  This will be a value from 1
   * to 7 inclusive, with 1 being the localized first day of the week.
   * @stable ICU 2.6
   */
  UCAL_DOW_LOCAL,

  /**
   * Year of this calendar system, encompassing all supra-year fields. For example,
   * in Gregorian/Julian calendars, positive Extended Year values indicate years AD,
   *  1 BC = 0 extended, 2 BC = -1 extended, and so on.
   * @stable ICU 2.8
   */
  UCAL_EXTENDED_YEAR,

 /**
   * Field number
   * indicating the modified Julian day number.  This is different from
   * the conventional Julian day number in two regards.  First, it
   * demarcates days at local zone midnight, rather than noon GMT.
   * Second, it is a local number; that is, it depends on the local time
   * zone.  It can be thought of as a single number that encompasses all
   * the date-related fields.
   * @stable ICU 2.8
   */
  UCAL_JULIAN_DAY,

  /**
   * Ranges from 0 to 23:59:59.999 (regardless of DST).  This field behaves <em>exactly</em>
   * like a composite of all time-related fields, not including the zone fields.  As such,
   * it also reflects discontinuities of those fields on DST transition days.  On a day
   * of DST onset, it will jump forward.  On a day of DST cessation, it will jump
   * backward.  This reflects the fact that it must be combined with the DST_OFFSET field
   * to obtain a unique local time value.
   * @stable ICU 2.8
   */
  UCAL_MILLISECONDS_IN_DAY,

  /**
   * Whether or not the current month is a leap month (0 or 1). See the Chinese calendar for
   * an example of this.
   */
  UCAL_IS_LEAP_MONTH,

    /* Do not conditionalize the following with #ifndef U_HIDE_DEPRECATED_API,
     * it is needed for layout of Calendar, DateFormat, and other objects */
    /**
     * One more than the highest normal UCalendarDateFields value.
     * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
     */
  UCAL_FIELD_COUNT,

 /**
   * Field number indicating the
   * day of the month. This is a synonym for <code>UCAL_DATE</code>.
   * The first day of the month has value 1.
   * @see #UCAL_DATE
   * Synonym for UCAL_DATE
   * @stable ICU 2.8
   **/
  UCAL_DAY_OF_MONTH=UCAL_DATE
};

/** @stable ICU 2.0 */
typedef enum UCalendarDateFields UCalendarDateFields;

////////////////////////////////////////////////////////////////////////////////

/**
 * Types of UCalendar attributes 
 * @stable ICU 2.0
 */
enum UCalendarAttribute
{
  /**
   * Lenient parsing
   * @stable ICU 2.0
   */
  UCAL_LENIENT,
  /**
   * First day of week
   * @stable ICU 2.0
   */
  UCAL_FIRST_DAY_OF_WEEK,
  /**
   * Minimum number of days in first week
   * @stable ICU 2.0
   */
  UCAL_MINIMAL_DAYS_IN_FIRST_WEEK,
  /**
   * The behavior for handling wall time repeating multiple times
   * at negative time zone offset transitions
   * @stable ICU 49
   */
  UCAL_REPEATED_WALL_TIME,
  /**
   * The behavior for handling skipped wall time at positive time
   * zone offset transitions.
   * @stable ICU 49
   */
  UCAL_SKIPPED_WALL_TIME
};

/** @stable ICU 2.0 */
typedef enum UCalendarAttribute UCalendarAttribute;

////////////////////////////////////////////////////////////////////////////////

/**
 * Options for handling ambiguous wall time at time zone
 * offset transitions.
 * @stable ICU 49
 */
enum UCalendarWallTimeOption
{
  /**
   * An ambiguous wall time to be interpreted as the latest.
   * This option is valid for UCAL_REPEATED_WALL_TIME and
   * UCAL_SKIPPED_WALL_TIME.
   * @stable ICU 49
   */
  UCAL_WALLTIME_LAST,
  /**
   * An ambiguous wall time to be interpreted as the earliest.
   * This option is valid for UCAL_REPEATED_WALL_TIME and
   * UCAL_SKIPPED_WALL_TIME.
   * @stable ICU 49
   */
  UCAL_WALLTIME_FIRST,
  /**
   * An ambiguous wall time to be interpreted as the next valid
   * wall time. This option is valid for UCAL_SKIPPED_WALL_TIME.
   * @stable ICU 49
   */
  UCAL_WALLTIME_NEXT_VALID
};
/** @stable ICU 49 */
typedef enum UCalendarWallTimeOption UCalendarWallTimeOption;

////////////////////////////////////////////////////////////////////////////////

/**
 * Set the time zone files override directory.
 * This function is not thread safe; it must not be called concurrently with
 *   u_getTimeZoneFilesDirectory() or any other use of ICU time zone functions.
 * This function should only be called before using any ICU service that
 *   will access the time zone data.
 * @internal
 */
typedef void (ICU_EXPORT2 ICU_FN(u_setTimeZoneFilesDirectory))
 (const char* path,
  UErrorCode* status);

////////////////////////////////////////////////////////////////////////////////

/**
 * Open a UCalendar.
 * A UCalendar may be used to convert a millisecond value to a year,
 * month, and day.
 * <p>
 * Note: When unknown TimeZone ID is specified or if the TimeZone ID specified is "Etc/Unknown",
 * the UCalendar returned by the function is initialized with GMT zone with TimeZone ID
 * <code>UCAL_UNKNOWN_ZONE_ID</code> ("Etc/Unknown") without any errors/warnings.  If you want
 * to check if a TimeZone ID is valid prior to this function, use <code>ucal_getCanonicalTimeZoneID</code>.
 *
 * @param zoneID The desired TimeZone ID.  If 0, use the default time zone.
 * @param len The length of zoneID, or -1 if null-terminated.
 * @param locale The desired locale
 * @param type The type of UCalendar to open. This can be UCAL_GREGORIAN to open the Gregorian
 * calendar for the locale, or UCAL_DEFAULT to open the default calendar for the locale (the
 * default calendar may also be Gregorian). To open a specific non-Gregorian calendar for the
 * locale, use uloc_setKeywordValue to set the value of the calendar keyword for the locale
 * and then pass the locale to ucal_open with UCAL_DEFAULT as the type.
 * @param status A pointer to an UErrorCode to receive any errors
 * @return A pointer to a UCalendar, or 0 if an error occurred.
 * @see #UCAL_UNKNOWN_ZONE_ID
 * @stable ICU 2.0
 */
typedef UCalendar* (ICU_EXPORT2  ICU_FN(ucal_open))
 (const UChar*   zoneID,
  int32_t        len,
  const char*    locale,
  UCalendarType  type,
  UErrorCode*    status);

////////////////////////////////////////////////////////////////////////////////

/**
 * Close a UCalendar.
 * Once closed, a UCalendar may no longer be used.
 * @param cal The UCalendar to close.
 * @stable ICU 2.0
 */
typedef void (ICU_EXPORT2 ICU_FN(ucal_close))
 (UCalendar* cal);

////////////////////////////////////////////////////////////////////////////////

/**
 * Set a numeric attribute associated with a UCalendar.
 * Numeric attributes include the first day of the week, or the minimal numbers
 * of days in the first week of the month.
 * @param cal The UCalendar to set.
 * @param attr The desired attribute; one of UCAL_LENIENT, UCAL_FIRST_DAY_OF_WEEK,
 * UCAL_MINIMAL_DAYS_IN_FIRST_WEEK, UCAL_REPEATED_WALL_TIME or UCAL_SKIPPED_WALL_TIME
 * @param newValue The new value of attr.
 * @see ucal_getAttribute
 * @stable ICU 2.0
 */
typedef void (ICU_EXPORT2 ICU_FN(ucal_setAttribute))
 (UCalendar*          cal,
  UCalendarAttribute  attr,
  int32_t             newValue);

////////////////////////////////////////////////////////////////////////////////

/**
 * Set a UCalendar's current time in millis.
 * The time is represented as UTC milliseconds from the epoch.
 * @param cal The UCalendar to set.
 * @param dateTime The desired date and time.
 * @param status A pointer to an UErrorCode to receive any errors
 * @see ucal_getMillis
 * @see ucal_setDate
 * @see ucal_setDateTime
 * @stable ICU 2.0
 */
typedef void (ICU_EXPORT2 ICU_FN(ucal_setMillis))
 (UCalendar*   cal,
  UDate        dateTime,
  UErrorCode*  status);

////////////////////////////////////////////////////////////////////////////////

/**
 * Set a UCalendar's current date.
 * The date is represented as a series of 32-bit integers.
 * @param cal The UCalendar to set.
 * @param year The desired year.
 * @param month The desired month; one of UCAL_JANUARY, UCAL_FEBRUARY, UCAL_MARCH, UCAL_APRIL, UCAL_MAY,
 * UCAL_JUNE, UCAL_JULY, UCAL_AUGUST, UCAL_SEPTEMBER, UCAL_OCTOBER, UCAL_NOVEMBER, UCAL_DECEMBER, UCAL_UNDECIMBER
 * @param date The desired day of the month.
 * @param hour The desired hour of day.
 * @param minute The desired minute.
 * @param second The desirec second.
 * @param status A pointer to an UErrorCode to receive any errors
 * @see ucal_getMillis
 * @see ucal_setMillis
 * @see ucal_setDate
 * @stable ICU 2.0
 */
typedef void (ICU_EXPORT2 ICU_FN(ucal_setDateTime))
 (UCalendar*   cal,
  int32_t      year,
  int32_t      month,
  int32_t      date,
  int32_t      hour,
  int32_t      minute,
  int32_t      second,
  UErrorCode*  status);

////////////////////////////////////////////////////////////////////////////////

/**
 * Get the current value of a field from a UCalendar.
 * All fields are represented as 32-bit integers.
 * @param cal The UCalendar to query.
 * @param field The desired field; one of UCAL_ERA, UCAL_YEAR, UCAL_MONTH,
 * UCAL_WEEK_OF_YEAR, UCAL_WEEK_OF_MONTH, UCAL_DATE, UCAL_DAY_OF_YEAR, UCAL_DAY_OF_WEEK,
 * UCAL_DAY_OF_WEEK_IN_MONTH, UCAL_AM_PM, UCAL_HOUR, UCAL_HOUR_OF_DAY, UCAL_MINUTE, UCAL_SECOND,
 * UCAL_MILLISECOND, UCAL_ZONE_OFFSET, UCAL_DST_OFFSET.
 * @param status A pointer to an UErrorCode to receive any errors
 * @return The value of the desired field.
 * @see ucal_set
 * @see ucal_isSet
 * @see ucal_clearField
 * @see ucal_clear
 * @stable ICU 2.0
 */
typedef int32_t (ICU_EXPORT2 ICU_FN(ucal_get))
 (const UCalendar*     cal,
  UCalendarDateFields  field,
  UErrorCode*          status);

////////////////////////////////////////////////////////////////////////////////

/**
 * Get the ID of the UCalendar's time zone.
 *
 * @param cal           The UCalendar to query.
 * @param result        Receives the UCalendar's time zone ID.
 * @param resultLength  The maximum size of result.
 * @param status        Receives the status.
 * @return              The total buffer size needed; if greater than resultLength, the output was truncated.
 * @stable ICU 51
 */
typedef int32_t (ICU_EXPORT2 ICU_FN(ucal_getTimeZoneID))
 (const UCalendar* cal,
  UChar*           result,
  int32_t          resultLength,
  UErrorCode*      status);

////////////////////////////////////////////////////////////////////////////////

/**
 * Create an enumeration over all time zones.
 *
 * @param ec input/output error code
 *
 * @return an enumeration object that the caller must dispose of using
 * uenum_close(), or NULL upon failure. In case of failure *ec will
 * indicate the error.
 *
 * @stable ICU 2.6
 */
typedef UEnumeration* (ICU_EXPORT2 ICU_FN(ucal_openTimeZones))
 (UErrorCode* ec);

////////////////////////////////////////////////////////////////////////////////

#undef ICU_FN
#undef ICU_EXPORT2

////////////////////////////////////////////////////////////////////////////////
//! \endcond
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms v063*/}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
#endif
