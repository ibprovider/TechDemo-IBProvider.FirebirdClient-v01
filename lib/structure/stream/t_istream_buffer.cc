////////////////////////////////////////////////////////////////////////////////
#ifndef _t_istream_buffer_CC_
#define _t_istream_buffer_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_istream_buffer

template<typename T,class Traits>
t_basic_istream_buffer<T,Traits>::t_basic_istream_buffer()
{
 this->set_ptrs(nullptr,nullptr);
}//t_basic_istream_buffer

//------------------------------------------------------------------------
template<typename T,class Traits>
t_basic_istream_buffer<T,Traits>::t_basic_istream_buffer
                                           (const_pointer const buffer_beg,
                                            const_pointer const buffer_end)
{
 this->set_ptrs(buffer_beg,buffer_end);
}//t_basic_istream_buffer

//------------------------------------------------------------------------
template<typename T,class Traits>
t_basic_istream_buffer<T,Traits>::~t_basic_istream_buffer()
{;}

//public interface -------------------------------------------------------
template<typename T,class Traits>
bool t_basic_istream_buffer<T,Traits>::eof()
{
 if(m_buffer_pos!=m_buffer_end)
  return false;
 
 this->underflow(); //throw

 DEBUG_CODE(this->debug__check_state();)

 return m_buffer_pos==m_buffer_end;
}//eof

//------------------------------------------------------------------------
template<typename T,class Traits>
bool t_basic_istream_buffer<T,Traits>::get(pointer const value)
{
 assert(value!=nullptr);

 DEBUG_CODE(this->debug__check_state();)

 if(m_buffer_pos==m_buffer_end)
 {
  this->underflow(); //throw

  DEBUG_CODE(this->debug__check_state();)

  if(m_buffer_pos==m_buffer_end)
   return false;
 }//if

 (*value)=(*m_buffer_pos);

 ++m_buffer_pos;

 return true;
}//get

//------------------------------------------------------------------------
template<typename T,class Traits>
bool t_basic_istream_buffer<T,Traits>::cur(pointer const value)
{
 assert(value!=nullptr);

 DEBUG_CODE(this->debug__check_state();)

 if(m_buffer_pos==m_buffer_end)
 {
  this->underflow(); //throw

  DEBUG_CODE(this->debug__check_state();)

  if(m_buffer_pos==m_buffer_end)
   return false;
 }//if

 (*value)=*m_buffer_pos;

 return true;
}//cur

//------------------------------------------------------------------------
template<typename T,class Traits>
void t_basic_istream_buffer<T,Traits>::getn(pointer    const p,
                                            size_type  const n,
                                            size_type* const actual_readed)
{
 assert(actual_readed!=nullptr);

 DEBUG_CODE(this->debug__check_state();)

 (*actual_readed)=0;

 //-----------------------------------------
 size_type     target_sz =n;
 pointer       target_pos=p;
#ifndef NDEBUG
 pointer const target_end=p+n;
#endif
 
 while(target_sz>0)
 {
  if(m_buffer_pos==m_buffer_end)
  {
   this->underflow();
  
   DEBUG_CODE(this->debug__check_state();)

   if(m_buffer_pos==m_buffer_end)
    break;
  }//if
  
  size_type block_sz=static_cast<size_type>(m_buffer_end-m_buffer_pos);

  assert(block_sz>0);

  if(target_sz<block_sz)
   block_sz=target_sz;

  //----------------------------------------
  {
  #ifndef NDEBUG
   const_pointer const copy__m_buffer_pos  =m_buffer_pos;
   pointer       const copy__target_pos    =target_pos;
   size_type     const copy__actual_readed =*actual_readed;
  #endif //NDEBUG
 
   traits_type::copy(&target_pos,&m_buffer_pos,block_sz,actual_readed);

  #ifndef NDEBUG
   assert(copy__actual_readed<(*actual_readed));
   assert(((*actual_readed)-copy__actual_readed)==block_sz);
   
   assert(target_pos>copy__target_pos);
   assert(static_cast<size_type>(target_pos-copy__target_pos)==block_sz);
   assert(target_pos<=target_end);

   assert(m_buffer_pos>copy__m_buffer_pos);
   assert(static_cast<size_type>(m_buffer_pos-copy__m_buffer_pos)==block_sz);
   assert(m_buffer_pos<=m_buffer_end);
  #endif //NDEBUG
  }//local

  //----------------------------------------
  assert(block_sz<=target_sz);

  target_sz-=block_sz;
 }//for[ever]
}//getn

//------------------------------------------------------------------------
template<typename T,class Traits>
bool t_basic_istream_buffer<T,Traits>::skip()
{
 DEBUG_CODE(this->debug__check_state();)

 if(m_buffer_pos==m_buffer_end)
 {
  this->underflow(); //throw

  DEBUG_CODE(this->debug__check_state();)

  if(m_buffer_pos==m_buffer_end)
   return false;
 }//if

 ++m_buffer_pos;

 return true;
}//skip

//------------------------------------------------------------------------
template<typename T,class Traits>
void t_basic_istream_buffer<T,Traits>::skipn(stream_size_type        n,
                                             stream_size_type* const actual_skiped)
{
 assert(actual_skiped!=nullptr);

 DEBUG_CODE(this->debug__check_state();)

 (*actual_skiped)=0;

 if(n==0)
  return;

 //-----------------------------------------
 stream_size_type skip_n=n;
 
 for(;;)
 {
  assert(skip_n>0);

  if(m_buffer_pos==m_buffer_end)
  {
   this->underflow();
  
   DEBUG_CODE(this->debug__check_state();)

   if(m_buffer_pos==m_buffer_end)
    break;
  }//if
  
  size_type block_sz=static_cast<size_type>(m_buffer_end-m_buffer_pos);

  assert(block_sz>0);

  if(block_sz<skip_n)
  {
   (*actual_skiped)+=block_sz;

   m_buffer_pos+=block_sz;
   
   skip_n-=block_sz;

   continue;
  }//if

  assert_hint(skip_n<=block_sz);

  (*actual_skiped)+=skip_n;

  m_buffer_pos+=static_cast<size_type>(skip_n);

  break;
 }//for[ever]
}//skipn

//protected interface ----------------------------------------------------
template<typename T,class Traits>
void t_basic_istream_buffer<T,Traits>::set_ptrs(const_pointer const buffer_beg,
                                                const_pointer const buffer_end)
{
 assert(buffer_beg<=buffer_end);

 this->m_buffer_pos=buffer_beg;
 this->m_buffer_end=buffer_end;

 DEBUG_CODE(this->debug__check_state();)
}//set_ptrs

//------------------------------------------------------------------------
#ifndef NDEBUG

template<typename T,class Traits>
void t_basic_istream_buffer<T,Traits>::debug__check_state()const
{
 assert(m_buffer_pos<=m_buffer_end);
}//debug__check_state

#endif

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
