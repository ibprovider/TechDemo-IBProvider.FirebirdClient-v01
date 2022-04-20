////////////////////////////////////////////////////////////////////////////////
#ifndef _t_ostream_buffer_CC_
#define _t_ostream_buffer_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_ostream_buffer

template<typename T,class Traits>
t_basic_ostream_buffer<T,Traits>::t_basic_ostream_buffer()
{
 this->set_ptrs(nullptr,nullptr);
}

//------------------------------------------------------------------------
template<typename T,class Traits>
t_basic_ostream_buffer<T,Traits>::t_basic_ostream_buffer(pointer const buffer_beg,
                                                         pointer const buffer_end)
{
 this->set_ptrs(buffer_beg,buffer_end);
}//t_basic_ostream_buffer

//------------------------------------------------------------------------
template<typename T,class Traits>
t_basic_ostream_buffer<T,Traits>::~t_basic_ostream_buffer()
{;}

//------------------------------------------------------------------------
template<typename T,class Traits>
bool t_basic_ostream_buffer<T,Traits>::put(const_reference value)
{
 DEBUG_CODE(this->debug__check_state());

 if(m_buffer_pos==m_buffer_end)
 {
  this->overflow();

  DEBUG_CODE(this->debug__check_state());
 
  if(m_buffer_pos==m_buffer_end)
   return false;
 }//if

 (*m_buffer_pos)=value;

 ++m_buffer_pos;

 return true;
}//put

//------------------------------------------------------------------------
template<typename T,class Traits>
void t_basic_ostream_buffer<T,Traits>::putn(const_pointer const p,
                                            size_type     const n,
                                            size_type*    const actual_writed)
{
 assert(actual_writed);

 CHECK_READ_TYPED_PTR(p,n);

 DEBUG_CODE(this->debug__check_state());

 (*actual_writed)=0;

 //-----------------------------------------
 size_type     source_n=n;
 const_pointer source_p=p;

 while(source_n>0)
 {
  if(m_buffer_pos==m_buffer_end)
  {
   this->overflow();

   DEBUG_CODE(this->debug__check_state());

   if(m_buffer_pos==m_buffer_end)
    return;
  }//if

  //---
  size_t block_sz=static_cast<size_t>(m_buffer_end-m_buffer_pos);

  if(source_n<block_sz)
   block_sz=source_n;

  //---
  {
  #ifndef NDEBUG
   const_pointer const copy__m_buffer_pos   =m_buffer_pos;
   const_pointer const copy__source_p       =source_p;
   size_type     const copy__actual_writed  =*actual_writed;
  #endif 

   traits_type::copy(&m_buffer_pos,&source_p,block_sz,actual_writed);

  #ifndef NDEBUG
   assert((*actual_writed)>copy__actual_writed);
   assert(((*actual_writed)-copy__actual_writed)==block_sz);

   assert(m_buffer_pos==(copy__m_buffer_pos+block_sz));
   assert(source_p    ==(copy__source_p+block_sz));
  #endif
  }//local

  //---
  source_n-=block_sz;
 }//for
}//putn

//------------------------------------------------------------------------
template<typename T,class Traits>
void t_basic_ostream_buffer<T,Traits>::flush()
{
 DEBUG_CODE(this->debug__check_state());

 this->overflow();

 DEBUG_CODE(this->debug__check_state());
}//flush

//------------------------------------------------------------------------
template<typename T,class Traits>
void t_basic_ostream_buffer<T,Traits>::set_ptrs(pointer const buffer_beg,
                                                pointer const buffer_end)
{
 assert(buffer_beg<=buffer_end);

 m_buffer_pos=buffer_beg;
 m_buffer_end=buffer_end;

 DEBUG_CODE(this->debug__check_state());
}//set_ptrs

//------------------------------------------------------------------------
template<typename T,class Traits>
typename t_basic_ostream_buffer<T,Traits>::pointer
 t_basic_ostream_buffer<T,Traits>::get_buffer_pos()const
{
 return m_buffer_pos;
}//get_buffer_pos

//------------------------------------------------------------------------
template<typename T,class Traits>
typename t_basic_ostream_buffer<T,Traits>::pointer
 t_basic_ostream_buffer<T,Traits>::get_buffer_end()const
{
 return m_buffer_end;
}//get_buffer_end

//------------------------------------------------------------------------
#ifndef NDEBUG

template<typename T,class Traits>
void t_basic_ostream_buffer<T,Traits>::debug__check_state()const
{
 assert(m_buffer_pos<=m_buffer_end);
}//debug__check_state

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif