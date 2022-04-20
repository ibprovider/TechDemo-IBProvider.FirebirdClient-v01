////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_api__op_data__writer_buffer__external.h
//! \brief   [ISC API]  ласс буфера дл€ записи управл€ющих данных
//! \author  Kovalenko Dmitry
//! \date    26.07.2011
#ifndef _isc_api__op_data__writer_buffer__external_H_
#define _isc_api__op_data__writer_buffer__external_H_

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_api__op_data__writer_buffer__external

/// <summary>
///  [ISC API]  ласс буфера дл€ записи управл€ющих данных
/// </summary>
class t_isc_api__op_data__writer_buffer__external
{
 private:
  typedef t_isc_api__op_data__writer_buffer__external     self_type;

  t_isc_api__op_data__writer_buffer__external(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef unsigned char                                   byte_type;

  typedef size_t                                          size_type;

 public:
  t_isc_api__op_data__writer_buffer__external(void* pv,size_type sz);

  //selectors ------------------------------------------------------------
  const void* get_buffer()const;

  size_type get_capacity()const;

  size_type get_size()const;

  //modificators [buffer interface] --------------------------------------
  void put_byte(byte_type x);

  void put_bytes(const char* s,size_type n);

 private:
  COMP_CONF_DECLSPEC_NORETURN
  void helper__throw_bug_check__overflow(const wchar_t* source,
                                         const wchar_t* point,
                                         size_t         req_size)const;

 private:
  size_type const m_buffer_size;
  void*     const m_buffer;

  size_type m_used_size;
};//class t_isc_api__op_data__writer_buffer__external

////////////////////////////////////////////////////////////////////////////////
//class t_isc_api__op_data__writer_buffer__external

inline t_isc_api__op_data__writer_buffer__external::t_isc_api__op_data__writer_buffer__external
                                           (void*     const pv,
                                            size_type const sz)
 :m_buffer_size(sz)
 ,m_buffer(pv)
 ,m_used_size(0)
{
 CHECK_WRITE_PTR(m_buffer,m_buffer_size);
}//t_isc_api__op_data__writer_buffer__external

//------------------------------------------------------------------------
inline
 const void* t_isc_api__op_data__writer_buffer__external::get_buffer()const
{
 return m_buffer;
}//get_buffer

//------------------------------------------------------------------------
inline
t_isc_api__op_data__writer_buffer__external::size_type
 t_isc_api__op_data__writer_buffer__external::get_capacity()const
{
 return m_buffer_size;
}//get_capacity

//------------------------------------------------------------------------
inline
t_isc_api__op_data__writer_buffer__external::size_type
 t_isc_api__op_data__writer_buffer__external::get_size()const
{
 return m_used_size;
}//get_size

//------------------------------------------------------------------------
inline
void t_isc_api__op_data__writer_buffer__external::put_byte(byte_type const x)
{
 assert(m_used_size<=m_buffer_size);

 if(m_used_size==m_buffer_size)
 {
  this->helper__throw_bug_check__overflow
   (L"t_isc_api__op_data__writer_buffer__external::put_byte",
    L"#001",
    m_used_size+1);
 }//if

 reinterpret_cast<byte_type*>(m_buffer)[m_used_size]=x;

 ++m_used_size;
}//put_byte

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
