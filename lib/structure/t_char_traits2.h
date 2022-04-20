////////////////////////////////////////////////////////////////////////////////
//Вспомогательные конструкции для работы с символами
//                                      Коваленко Дмитрий. 21 января 2002 года.
#ifndef _t_char_traits2_
#define _t_char_traits2_

#include <structure/t_common.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containing

template<class T>
struct t_char_traits2; //empty

template<>
struct t_char_traits2<char>;

template<>
struct t_char_traits2<wchar_t>;

////////////////////////////////////////////////////////////////////////////////
//empty declarations

template<class T>
struct t_char_traits2
{
 public://typedefs
  typedef T               char_type;
};//empty

////////////////////////////////////////////////////////////////////////////////
//char specifications

template<>
struct t_char_traits2<char>
{
 private:
  typedef t_char_traits2<char>                self_type;

 public: //typedefs
  typedef char            char_type;
  typedef unsigned char   char_comp_type;
  typedef unsigned char   byte_type;

  typedef wchar_t         other_char_type;

  typedef size_t          size_type;

 #ifdef _USE_VCL_
  typedef AnsiString      vcl_string_type;
 #endif

 public: //utility
  static const char_type* str_empty()          {return "";}

  static const char_type ch_space()            {return ' ';}
  static const char_type ch_underscore()       {return '_';}
  static const char_type ch_new_line()         {return '\n';}
  static const char_type ch_return_line()      {return '\r';}
  static const char_type ch_tab()              {return '\t';}
  static const char_type ch_apos()             {return '\'';}
  static const char_type ch_double_quote()     {return '\"';}
  static const char_type ch_point()            {return '.';}
  static const char_type ch_comma()            {return ',';}
  static const char_type ch_double_point()     {return ':';}
  static const char_type ch_comma_with_point() {return ';';}
  static const char_type ch_equal()            {return '=';}
  static const char_type ch_lt()               {return '<';}
  static const char_type ch_gt()               {return '>';}
  static const char_type ch_div()              {return '/';}
  static const char_type ch_question_mark()    {return '?';}
  static const char_type ch_minus()            {return '-';}
  static const char_type ch_plus()             {return '+';}
  static const char_type ch_ampersand()        {return '&';}
  static const char_type ch_sharp()            {return '#';}
  static const char_type ch_back_slash()       {return '\\';} // [2015-02-15] old name: ch_slash

  static const char_type ch_vline()            {return '|';}

  static const char_type ch_open_fbracket()    {return '{';}
  static const char_type ch_close_fbracket()   {return '}';}

  static const char_type ch_0()                {return '0';}
  static const char_type ch_9()                {return '9';}

  static const char_type ch_letter_a()         {return 'a';}
  static const char_type ch_letter_A()         {return 'A';}

  static const char_type ch_letter_f()         {return 'f';}
  static const char_type ch_letter_F()         {return 'F';}

  static const char_type ch_letter_e()         {return 'e';}
  static const char_type ch_letter_E()         {return 'E';}

  static const char_type ch_letter_x()         {return 'x';}
  static const char_type ch_letter_X()         {return 'X';}

  static const char_type ch_letter_z()         {return 'z';}
  static const char_type ch_letter_Z()         {return 'Z';}

 public:
  inline static bool is_alpha(char_type c);

  inline static bool is_alnum(char_type c);

 public: //HEX DIGIT [0..F] ----------------------------------------------
  inline static char_type to_hex_u(byte_type x);

  inline static char_type to_hex_l(byte_type x);

  inline static char_type to_hex(byte_type x,bool upper=true);

  inline static bool is_hex(char_type c);

  //return:
  //0..15  - succeeded conversion
  //>15    - if error
  inline static byte_type from_hex(char_type c);

 public: //DEC DIGIT [0..9] ----------------------------------------------

  inline static bool is_digit(char_type c);

  //return:
  //0..9 - succeeded conversion
  //>9   - if error
  inline static byte_type from_dec(char_type c);

 public:
  static char_type* int_to_str(int value,char_type* s,size_type n,int radix)
   {
    _VERIFY_EQ(_GCRT_itoa_s(value,s,n,radix),0L);

    return s;
   }//int_to_str

  static char_type* long_to_str(long value,char_type* s,size_type n,int radix)
   {
    _VERIFY_EQ(_GCRT_ltoa_s(value,s,n,radix),0L);

    return s;
   }//long_to_str

  static char_type* ulong_to_str(unsigned long value,char_type* s,size_type n,int radix)
   {
    _VERIFY_EQ(_GCRT_ultoa_s(value,s,n,radix),0L);

    return s;
   }//ulong_to_str

  static char_type* int64_to_str(__int64 value,char_type* s,size_type n,int radix)
   {
    _VERIFY_EQ(_GCRT_i64toa_s(value,s,n,radix),0L);

    return s;
   }//int64_to_str

  static char_type* uint64_to_str(unsigned __int64 value,char_type* s,size_type n,int radix)
   {
    _VERIFY_EQ(_GCRT_ui64toa_s(value,s,n,radix),0L);

    return s;
   }//uint64_to_str

 public:
  static long str_to_long(const char_type* s,char_type** endptr,int radix)
   {return strtol(s,endptr,radix);}

  static double str_to_double(const char_type* s,char_type** endptr)
   {return strtod(s,endptr);}

 #if(__STL_HAS_STRTOLD)
  static long double str_to_long_double(const char_type* s,char_type** endptr)
   {return _strtold(s,endptr);}
 #endif
};//t_char_traits2<char>

////////////////////////////////////////////////////////////////////////////////
//wchar_t specifications

template<>
struct t_char_traits2<wchar_t>
{
 private:
  typedef t_char_traits2<wchar_t>              self_type;

 public: //typedefs
  typedef wchar_t         char_type;
  typedef wchar_t         char_comp_type;
  typedef unsigned char   byte_type;

  typedef char            other_char_type;

  typedef size_t          size_type;

 #ifdef _USE_VCL_
  typedef WideString      vcl_string_type;
 #endif

 public: //utility
  static const char_type* str_empty()          {return L"";}

  static const char_type ch_space()            {return L' ';}
  static const char_type ch_underscore()       {return L'_';}
  static const char_type ch_new_line()         {return L'\n';}
  static const char_type ch_return_line()      {return L'\r';}
  static const char_type ch_tab()              {return L'\t';}
  static const char_type ch_apos()             {return L'\'';}
  static const char_type ch_double_quote()     {return L'\"';}
  static const char_type ch_point()            {return L'.';}
  static const char_type ch_comma()            {return L',';}
  static const char_type ch_double_point()     {return L':';}
  static const char_type ch_comma_with_point() {return L';';}
  static const char_type ch_equal()            {return L'=';}
  static const char_type ch_lt()               {return L'<';}
  static const char_type ch_gt()               {return L'>';}
  static const char_type ch_div()              {return L'/';}
  static const char_type ch_question_mark()    {return L'?';}
  static const char_type ch_minus()            {return L'-';}
  static const char_type ch_plus()             {return L'+';}
  static const char_type ch_ampersand()        {return L'&';}
  static const char_type ch_sharp()            {return L'#';}
  static const char_type ch_back_slash()       {return L'\\';} // [2015-02-15] old name: ch_slash

  static const char_type ch_vline()            {return L'|';}

  static const char_type ch_open_fbracket()    {return L'{';}
  static const char_type ch_close_fbracket()   {return L'}';}

  static const char_type ch_0()                {return L'0';}
  static const char_type ch_9()                {return L'9';}

  static const char_type ch_letter_a()         {return L'a';}
  static const char_type ch_letter_A()         {return L'A';}

  static const char_type ch_letter_f()         {return L'f';}
  static const char_type ch_letter_F()         {return L'F';}

  static const char_type ch_letter_e()         {return L'e';}
  static const char_type ch_letter_E()         {return L'E';}

  static const char_type ch_letter_x()         {return L'x';}
  static const char_type ch_letter_X()         {return L'X';}

  static const char_type ch_letter_z()         {return L'z';}
  static const char_type ch_letter_Z()         {return L'Z';}

 public:
  inline static bool is_alpha(char_type c);

  inline static bool is_alnum(char_type c);

 public: //HEX DIGIT [0..F] ----------------------------------------------
  inline static char_type to_hex_u(byte_type x);

  inline static char_type to_hex_l(byte_type x);

  inline static char_type to_hex(byte_type x,bool upper=true);

  inline static bool is_hex(char_type c);

  //return:
  //0..15  - succeeded conversion
  //>15    - if error
  inline static byte_type from_hex(char_type c);

 public: //DEC DIGIT [0..9] ----------------------------------------------

  inline static bool is_digit(char_type c);

  //return:
  //0..9 - succeeded conversion
  //>9   - if error
  inline static byte_type from_dec(char_type c);

 public:
  static char_type* int_to_str(int value,char_type* s,size_type n,int radix)
   {
    _VERIFY_EQ(_GCRT_itow_s(value,s,n,radix),0L);

    return s;
   }//int_to_str

  static char_type* long_to_str(long value,char_type* s,size_type n,int radix)
   {
    _VERIFY_EQ(_GCRT_ltow_s(value,s,n,radix),0L);

    return s;
   }//long_to_str

  static char_type* ulong_to_str(unsigned long value,char_type* s,size_type n,int radix)
   {
    _VERIFY_EQ(_GCRT_ultow_s(value,s,n,radix),0L);

    return s;
   }//ulong_to_str

  static char_type* int64_to_str(__int64 value,char_type* s,size_type n,int radix)
   {
    _VERIFY_EQ(_GCRT_i64tow_s(value,s,n,radix),0L);

    return s;
   }//int64_to_str

  static char_type* uint64_to_str(unsigned __int64 value,char_type* s,size_type n,int radix)
   {
    _VERIFY_EQ(_GCRT_ui64tow_s(value,s,n,radix),0L);

    return s;
   }//uint64_to_str

 public:
  static long str_to_long(const char_type* s,char_type** endptr,int radix)
   {return wcstol(s,endptr,radix);}

  static double str_to_double(const char_type* s,char_type** endptr)
   {return wcstod(s,endptr);}

 #if(__STL_HAS_WCSTOLD)
  static long double str_to_long_double(const char_type* s,char_type** endptr)
   {return _wcstold(s,endptr);}
 #endif
};//t_char_traits2<wchar_t>

////////////////////////////////////////////////////////////////////////////////
}//structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_char_traits2.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
