////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__common
//! \file    db_obj__dbms_fb__common__error_text_obj.cpp
//! \brief   Object for providing Firebird error text.
//! \author  Kovalenko Dmitry
//! \date    08.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/dbms_fb/common/db_obj__dbms_fb__common__error_text_obj.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace common{
////////////////////////////////////////////////////////////////////////////////
//class FB_ErrorTextObj

FB_ErrorTextObj::FB_ErrorTextObj(sv_utils_type*     const pStatusVectorUtils,
                                 size_t             const szStatusVector,
                                 const status_type* const pStatusVector)
 :m_spStatusVectorUtils(structure::not_null_ptr(pStatusVectorUtils))
 ,m_szStatusVector(szStatusVector)
 ,m_pStatusVector(pStatusVector)
{
 assert(m_spStatusVectorUtils);

 CHECK_READ_TYPED_PTR(m_pStatusVector,szStatusVector);
}//FB_ErrorTextObj

//------------------------------------------------------------------------
FB_ErrorTextObj::~FB_ErrorTextObj()
{
}//~FB_ErrorTextObj

//------------------------------------------------------------------------
FB_ErrorTextObj::self_ptr
 FB_ErrorTextObj::Create(sv_utils_type*     const pStatusVectorUtils,
                         const status_type* const sv_beg,
                         const status_type* const sv_end)
{
 assert(pStatusVectorUtils);
 assert(sv_beg<sv_end);

 CHECK_READ_TYPED_PTR(sv_beg,sv_end-sv_beg);

 //-----------------------------------------
 size_t sv_info__num_of_elements=0;
 size_t sv_info__indirect_data_size=0;

 {
  const sv_utils_type::gresult_data_type
   gresult
    =pStatusVectorUtils->get_sv_info
      (sv_beg,
       sv_end,
       &sv_info__num_of_elements,
       &sv_info__indirect_data_size);

  if(gresult!=sv_utils_type::gresult__ok)
  {
   //ERROR - ошибка обработки статус-вектора

   IBP_ThrowIscStatusVectorProcessingError
    (gresult.check_place,
     gresult.check_point);
  }//if

  assert(sv_info__num_of_elements>0);
  assert(sv_info__num_of_elements<=static_cast<size_t>(sv_end-sv_beg));
 }//local

 //-----------------------------------------
 //вычисляем параметры нашего объекта

 const size_t c_max_sz=structure::t_numeric_limits<size_t>::max_value();

 size_t total_sz=sizeof(self_type);

 if(!structure::align_memory_size(total_sz,sizeof(size_t)))
  throw std::bad_alloc();

 const size_t offset_of_sv=total_sz;

 if(((c_max_sz-offset_of_sv)/sizeof(status_type))<sv_info__num_of_elements)
  throw std::bad_alloc();

 const size_t
  c_bytes_in_actual_sv_elements=(sizeof(status_type)*sv_info__num_of_elements);

 total_sz+=c_bytes_in_actual_sv_elements;

 const size_t offset_of_idata=total_sz;

 if((c_max_sz-offset_of_idata)<sv_info__indirect_data_size)
  throw std::bad_alloc();

 total_sz+=sv_info__indirect_data_size;

 //-----------------------------------------
 void* pv=raw_allocator_type::instance.allocate(total_sz); //throw

 try
 {
  status_type* const new_sv_beg
   =reinterpret_cast<status_type*>(reinterpret_cast<char*>(pv)+offset_of_sv);

  //копируем данные статус вектора в дополнительную область
  memcpy(new_sv_beg,
         sv_beg,
         c_bytes_in_actual_sv_elements);

  //перемещаем косвенные данные статус вектора
  unsigned char* const idata_buf=reinterpret_cast<unsigned char*>(pv)+offset_of_idata;

  const sv_utils_type::gresult_data_type
   gresult
    =pStatusVectorUtils->move_indirect_data_to_buf
      (new_sv_beg,
       new_sv_beg+sv_info__num_of_elements,
       idata_buf,
       idata_buf+sv_info__indirect_data_size);

  if(gresult!=sv_utils_type::gresult__ok)
  {
   //ERROR - ошибка обработки статус-вектора

   //весьма странно - ошибки должны были быть выловлены на уровне error_utils::get_sv_info

   IBP_ThrowIscStatusVectorProcessingError
    (gresult.check_place,
     gresult.check_point);
  }//if

  //----------------------------------------

  //все, теперь можно конструировать собственно наш объект
  new(pv)self_type(pStatusVectorUtils,
                   sv_info__num_of_elements,
                   new_sv_beg); //throw?
 }
 catch(...)
 {
  raw_allocator_type::instance.deallocate(pv,total_sz);

  throw;
 }//catch

 assert(pv);

 //-----------------------------------------
 return structure::not_null_ptr(reinterpret_cast<self_type*>(pv));
}//Create

//interface --------------------------------------------------------------
bool FB_ErrorTextObj::get_text(lcid_type    const lcid,
                                 string_type* const text)const
{
 assert(text);

 text->clear();

 assert(m_spStatusVectorUtils);

 std::wstring wstr;

 const sv_utils_type::gresult_data_type
  gresult
   =m_spStatusVectorUtils->get_message
      (m_pStatusVector,
       m_pStatusVector+m_szStatusVector,
       &wstr,
       lcid.get_number());

 if(gresult!=sv_utils_type::gresult__ok)
 {
  //! \todo
  //!  Формировать локализованное сообщение о проблеме?

  structure::wstr_formatter fmsg(L"<Bad status vector. Check point [%1][%2]>");

  fmsg<<gresult.check_place
      <<gresult.check_point;

  wstr=fmsg.str();
 }//if

 text->swap(wstr);

 return true;
}//get_text

//------------------------------------------------------------------------
void* FB_ErrorTextObj::operator new (size_t const /*sz*/,void* const pv)
{
 return pv;
}//operator new

//------------------------------------------------------------------------
void FB_ErrorTextObj::operator delete (void* const pv)
{
 raw_allocator_type::instance.deallocate(pv,0);
}//operator delete

////////////////////////////////////////////////////////////////////////////////
}/*nms common*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
