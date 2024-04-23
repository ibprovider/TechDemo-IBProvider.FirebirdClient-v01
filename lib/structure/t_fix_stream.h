////////////////////////////////////////////////////////////////////////////////
//Классы для работы с буферами фиксированных размеров через потоки
//класс strstream, istrstream, ostrstream считаются устаревшими
//и более того, в BCB3 вылазят за границы буфера
//     (устанавливая 0 за последним символом)
//                                    Коваленко Дмитрий. 3 марта 2001 года
#ifndef _lcpi_lib_structure__t_fix_stream_H_
#define _lcpi_lib_structure__t_fix_stream_H_

#include <lcpi/lib/.config.h>
#include <ostream>
#include <istream>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//using namespace std;

////////////////////////////////////////////////////////////////////////////////
//Содержимое

template<class charT,class traits=std::char_traits<charT> >
class t_basic_fix_streambuf;

template<class charT,class traits=std::char_traits<charT> >
class t_basic_fix_ostream;

template<class charT,class traits=std::char_traits<charT> >
class t_basic_fix_istream;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_fix_streambuf

template<class charT,class traits>
class t_basic_fix_streambuf:public std::basic_streambuf<charT,traits>
{
 private: //private copy constructor and operator ---------------
  typedef t_basic_fix_streambuf<charT,traits>         self_type;
  typedef std::basic_streambuf<charT,traits>          inherited;

  t_basic_fix_streambuf(const self_type&);
  self_type& operator = (const self_type&);

 public: //public typedefs --------------------------------------
  typedef self_type                                   type_fix_streambuf;

  typedef std::streamsize                             streamsize_type;
  typedef std::ios_base                               ios_base_type;

 private: //private typedefs ------------------------------------
  typedef inherited                                   type_basic_streambuf;

  typedef typename traits::char_type                  char_type;
  typedef typename traits::int_type                   int_type;
  typedef typename traits::pos_type                   pos_type;
  typedef typename traits::off_type                   off_type;
  typedef traits                                      traits_type;

 public:
  t_basic_fix_streambuf();

  t_basic_fix_streambuf(char_type* buf,streamsize_type size);

  //установка буфера (чтение запись)
  type_basic_streambuf* setbuf(char_type* s,streamsize_type n);

  const char_type* write_buffer()const;

  size_t writed()const;

 protected: //behavior methods ----------------------------------
  //относительное позиционирование
  pos_type seekoff(off_type                off,
                   ios_base_type::seekdir  way,
                   ios_base_type::openmode which=ios_base_type::in|ios_base_type::out);

  //абсолютное позиционирование
  pos_type seekpos(pos_type                sp,
                   ios_base_type::openmode which=ios_base_type::in|ios_base_type::out);
};//class t_basic_fix_streambuf

typedef t_basic_fix_streambuf<char>                   fix_streambuf;
typedef t_basic_fix_streambuf<wchar_t>                fix_wstreambuf;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_fix_stream_data

template<class charT,class traits>
class t_basic_fix_stream_data
{
 private:
  typedef t_basic_fix_stream_data<charT,traits>       self_type;

  t_basic_fix_stream_data(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef t_basic_fix_streambuf<charT,traits>         fix_buf_type;

  typedef typename fix_buf_type::streamsize_type      streamsize_type;

 public:
  t_basic_fix_stream_data(charT*          s,
                          streamsize_type n);

 ~t_basic_fix_stream_data();

  //interface ------------------------------
  fix_buf_type* get_fix_buf();

  const fix_buf_type* get_fix_buf()const;

 private:
  fix_buf_type m_buf;
};//class t_basic_fix_stream_data

////////////////////////////////////////////////////////////////////////////////
//class t_basic_fix_ostream

template<class charT,class traits>
class t_basic_fix_ostream:private t_basic_fix_stream_data<charT,traits>,
                          public  std::basic_ostream<charT,traits>
{
 private:
  typedef t_basic_fix_ostream<charT,traits>              self_type;
  typedef t_basic_fix_stream_data<charT,traits>          base_data;
  typedef std::basic_ostream<charT,traits>               inherited;

  t_basic_fix_ostream(const self_type&);
  self_type& operator = (const self_type&);

 public: //public typedefs -----------------------------------------------
  typedef charT                                          char_type;

  typedef typename base_data::streamsize_type            streamsize_type;

 public://user interface -------------------------------------------------
  t_basic_fix_ostream(char_type*      s,
                      streamsize_type n);

  virtual ~t_basic_fix_ostream();

  const char_type* buffer()const;

  size_t writed()const;
};//class t_basic_fix_ostream

typedef t_basic_fix_ostream<char>                     fix_ostream;
typedef t_basic_fix_ostream<wchar_t>                  fix_wostream;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_fix_istream

template<class charT,class traits>
class t_basic_fix_istream:private t_basic_fix_stream_data<charT,traits>,
                          public  std::basic_istream<charT,traits>
{
 private:
  typedef t_basic_fix_istream<charT,traits>              self_type;
  typedef t_basic_fix_stream_data<charT,traits>          base_data;
  typedef std::basic_istream<charT,traits>               inherited;

  t_basic_fix_istream(const self_type&);
  self_type& operator = (const self_type&);

 public: //public typedefs -----------------------------------------------
  typedef charT                                          char_type;

  typedef typename base_data::streamsize_type            streamsize_type;

 public://user interface -------------------------------------------------
  t_basic_fix_istream(const char_type* s,streamsize_type n);

  virtual ~t_basic_fix_istream();
};//class t_basic_fix_istream

typedef t_basic_fix_istream<char>                     fix_istream;
typedef t_basic_fix_istream<wchar_t>                  fix_wistream;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_fix_stream.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
