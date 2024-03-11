////////////////////////////////////////////////////////////////////////////////
//Реализация шаблонов <structure/t_fix_stream.h>
//                                          Коваленко Дмитрий. 2 мая 2002 года.
#ifndef _t_fix_stream_CC_
#define _t_fix_stream_CC_

#include <structure/t_numeric_cast.h>
#include <structure/t_negative_one.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_fix_streambuf

template<class charT,class traits>
t_basic_fix_streambuf<charT,traits>::t_basic_fix_streambuf()
{
}

//------------------------------------------------------------------------
template<class charT,class traits>
t_basic_fix_streambuf<charT,traits>::t_basic_fix_streambuf(char_type*      const buf,
                                                           streamsize_type const size)
{
 this->setbuf(buf,size);
}//t_basic_fix_streambuf

//установка буфера -------------------------------------------------------
template<class charT,class traits>
inline typename t_basic_fix_streambuf<charT,traits>::type_basic_streambuf*
 t_basic_fix_streambuf<charT,traits>::setbuf(char_type*      const buf,
                                             streamsize_type const size)
{
 this->setp(buf,buf+size);  //pbeg,pend
 this->setg(buf,buf,buf+size);//gbeg,gnext,gend

#if(__STL_STREAMBUF_HAS_MODE_MEMBER)
 this->mode_=ios_base_type::in|ios_base_type::out;
#endif

 return this;
}//setbuf

//------------------------------------------------------------------------
template<class charT,class traits>
const typename t_basic_fix_streambuf<charT,traits>::char_type*
 t_basic_fix_streambuf<charT,traits>::write_buffer()const
{
 return this->pbase();
}//write_buffer

//------------------------------------------------------------------------
template<class charT,class traits>
size_t t_basic_fix_streambuf<charT,traits>::writed()const
{
 const charT* const pbase =this->pbase();
 const charT* const pptr  =this->pptr();

 assert(pbase<=pptr);

 return static_cast<size_t>(pptr-pbase);
}//writed

//------------------------------------------------------------------------
template<class charT,class traits>
typename t_basic_fix_streambuf<charT,traits>::pos_type
 t_basic_fix_streambuf<charT,traits>::seekoff(off_type                const off,
                                              ios_base_type::seekdir  const way,
                                              ios_base_type::openmode const which)
{
 assert(which==ios_base_type::in ||
        which==ios_base_type::out);

 assert(way==ios_base_type::cur ||
        way==ios_base_type::beg ||
        way==ios_base_type::end);

 //------
 typedef structure::t_numeric_limits<off_type>::unsigned_numeric_type unsigned_off_type;

 const unsigned_off_type off_value=structure::remove_numeric_sign(off);

 //------
 size_t  _pos;
 size_t  _size;

 if(which==ios_base_type::in) //позиционирование чтения
 {
  //eback - begin of input (read) buffer
  //gptr  - next element of input (read) buffer
  //egptr - end of input (read) buffer

  assert(this->eback()<=this->gptr());
  assert(this->gptr()<=this->egptr());

  _size=static_cast<size_t>(this->egptr()-this->eback());

  if(way==ios_base_type::cur)
   _pos=static_cast<size_t>(this->gptr()-this->eback());
  else
  if(way==ios_base_type::end)
   _pos=_size;
  else
   _pos=0;
 }//if IN
 else                    //позиционирование записи
 if(which==ios_base_type::out)
 {
  //pbase - begin of output (write) buffer
  //pptr  - next element of output (write) buffer
  //epptr - end of output (write) buffer

  assert(this->pbase()<=this->pptr());
  assert(this->pptr()<=this->epptr());

  _size=static_cast<size_t>(this->epptr()-this->pbase());

  if(way==ios_base_type::cur)
   _pos=static_cast<size_t>(this->pptr()-this->pbase());
  else
  if(way==ios_base_type::end)
   _pos=_size;
  else
   _pos=0;
 }//OUT
 else
 {
  assert(false);

  throw std::runtime_error("[t_basic_fix_streambuf::seekoff] unexpected 'which' value");
 }//else

 //проверяем, что не вылетаем за границы буфера
 if(off<0)
 {
  if(_pos<off_value)//за левую границу
   return pos_type(structure::negative_one);

  assert(structure::can_numeric_cast<size_t>(off_value));

  _pos-=static_cast<size_t>(off_value);
 }
 else
 if(off>0)
 {
  assert(_pos<=structure::get_numeric_limits(_pos).max_value());

  if((structure::get_numeric_limits(_pos).max_value()-_pos)<off_value) //переполнение
   return pos_type(structure::negative_one);

  if(_size<_pos+off_value)//за правую границу
   return pos_type(structure::negative_one);

  assert(structure::can_numeric_cast<size_t>(off_value));

  _pos+=static_cast<size_t>(off_value);
 }//else if
#ifndef NDEBUG
 else
 {
  assert(off==0);
 }
#endif

 if(!structure::can_numeric_cast<int>(_pos))
 {
  throw std::out_of_range("t_basic_fix_streambuf::seekoff");
 }

 //install the new pointers to buffer
 if(which==ios_base_type::in)
 {
  assert(this->eback()<=this->eback()+_pos);
  assert(this->eback()+_pos<=this->egptr());

  this->setg(this->eback(),this->eback()+_pos,this->egptr());
 }
 else
 {
  assert(which==ios_base_type::out);

  assert(this->pbase()<=this->pbase()+_pos);
  assert(this->pbase()+_pos<=this->epptr());

  //VC
  //this->setp(this->pbase(),this->pbase()+_pos,this->epptr());

  //BCB
  //this->setp(this->pbase(),this->epptr());
  //this->pbump(static_cast<int>(_pos));

  LCPI_STL_STREAMBUF_SETP
   (*this,
    /*pFirst*/this->pbase(),
    /*pNext*/ this->pbase()+_pos,
    /*pLast*/ this->epptr());
 }//else

 return pos_type(static_cast<int>(_pos));
}//seekoff

//------------------------------------------------------------------------
template<class charT,class traits>
typename t_basic_fix_streambuf<charT,traits>::pos_type
 t_basic_fix_streambuf<charT,traits>::seekpos(pos_type                const sp,
                                              ios_base_type::openmode const which)
{
 assert(which==ios_base_type::in ||
        which==ios_base_type::out);

 return this->seekoff(sp,
                      ios_base_type::beg,
                      which);
}//seekpos

////////////////////////////////////////////////////////////////////////////////
//class t_basic_fix_stream_data

template<class charT,class traits>
t_basic_fix_stream_data<charT,traits>::t_basic_fix_stream_data
                                           (charT*          const s,
                                            streamsize_type const n)
 :m_buf(s,n)
{
}

//------------------------------------------------------------------------
template<class charT,class traits>
t_basic_fix_stream_data<charT,traits>::~t_basic_fix_stream_data()
{
}

//------------------------------------------------------------------------
template<class charT,class traits>
typename t_basic_fix_stream_data<charT,traits>::fix_buf_type*
 t_basic_fix_stream_data<charT,traits>::get_fix_buf()
{
 return &this->m_buf;
}//get_fix_buf

//------------------------------------------------------------------------
template<class charT,class traits>
const typename t_basic_fix_stream_data<charT,traits>::fix_buf_type*
 t_basic_fix_stream_data<charT,traits>::get_fix_buf()const
{
 return &this->m_buf;
}//get_fix_buf - const

////////////////////////////////////////////////////////////////////////////////
//class t_basic_fix_ostream

template<class charT,class traits>
t_basic_fix_ostream<charT,traits>::t_basic_fix_ostream(char_type*      const s,
                                                       streamsize_type const n)
 :base_data(s,n),
  inherited(base_data::get_fix_buf())
{
 assert(this->good());
}//t_basic_fix_ostream

//------------------------------------------------------------------------
template<class charT,class traits>
t_basic_fix_ostream<charT,traits>::~t_basic_fix_ostream()
{
}

//------------------------------------------------------------------------
template<class charT,class traits>
const typename t_basic_fix_ostream<charT,traits>::char_type*
 t_basic_fix_ostream<charT,traits>::buffer()const
{
 return base_data::get_fix_buf()->write_buffer();
}//buffer

//------------------------------------------------------------------------
template<class charT,class traits>
size_t t_basic_fix_ostream<charT,traits>::writed()const
{
 return base_data::get_fix_buf()->writed();
}//writed

////////////////////////////////////////////////////////////////////////////////
//class t_basic_fix_istream

template<class charT,class traits>
t_basic_fix_istream<charT,traits>::t_basic_fix_istream(const char_type* const s,
                                                       streamsize_type  const n)
 :base_data(const_cast<char_type*>(s),n),
  inherited(base_data::get_fix_buf())
{
 //! \todo
 //!  Not tested

 assert(this->good());
}//t_basic_fix_istream

//------------------------------------------------------------------------
template<class charT,class traits>
t_basic_fix_istream<charT,traits>::~t_basic_fix_istream()
{;}

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif