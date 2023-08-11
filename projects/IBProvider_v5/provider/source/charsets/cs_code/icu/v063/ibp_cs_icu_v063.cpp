////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v063
//! \file    ibp_cs_icu_v063.cpp
//! \brief   Внешняя кодовая страница из ICU v063
//! \author  Kovalenko Dmitry
//! \date    15.06.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/icu/v063/ibp_cs_icu_v063__text_stream__mbc_to_ucs2.h"
#include "source/charsets/cs_code/icu/v063/ibp_cs_icu_v063__text_stream__mbc_buffer_to_ucs2.h"
#include "source/charsets/cs_code/icu/v063/ibp_cs_icu_v063__text_stream__ucs2_to_mbc.h"
#include "source/db_obj/db_blob_writer_buf.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/ibp_numeric_cast.h"
//#include "source/ibp_limits.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v063{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_icu::tag_conv_holder

t_ibp_cs_icu::tag_conv_holder::tag_conv_holder
                                (t_ibp_icu_provider* const pICU)
 :m_spICU (structure::not_null_ptr(pICU))
 ,m_ptr   (NULL)
{
 assert(m_spICU);
}//tag_conv_holder

//------------------------------------------------------------------------
t_ibp_cs_icu::tag_conv_holder::tag_conv_holder
                                (const t_ibp_cs_icu*       const charset,
                                 conv_direction_flags_type const direction_flags)
 :m_spICU (charset->m_spICU.not_null_ptr())
 ,m_ptr   (NULL)
{
 assert(m_spICU);

 _VERIFY(this->create(charset->m_icu_cs_name,direction_flags,true));
}//tag_conv_holder

//------------------------------------------------------------------------
t_ibp_cs_icu::tag_conv_holder::tag_conv_holder
                                (t_ibp_icu_provider*       const pICU,
                                 const std::string&              icu_cs_name,
                                 conv_direction_flags_type const direction_flags)
 :m_spICU (structure::not_null_ptr(pICU))
 ,m_ptr   (NULL)
{
 assert(m_spICU);

 _VERIFY(this->create(icu_cs_name,direction_flags,true));
}//tag_conv_holder

//------------------------------------------------------------------------
t_ibp_cs_icu::tag_conv_holder::~tag_conv_holder()
{
 try
 {
  this->free();

  assert(m_ptr==NULL);
 }
 catch(...)
 {
  assert(false);
 }
}//~tag_conv_holder

//------------------------------------------------------------------------
bool t_ibp_cs_icu::tag_conv_holder::create
                                (const std::string&              icu_cs_name,
                                 conv_direction_flags_type const direction_flags,
                                 bool                      const must_be_created)
{
 assert(m_spICU);

 ///0. Проверяем наличие экспорта API-функции разрушения конвертора
 m_spICU->m_ucnv_close.point(); //throw

 ///0.1 Освобождение предыдущего ICU-конвертора
 this->free();

 assert(m_ptr==NULL);

 ///1. Создание конвертора
 api::UErrorCode icu_status=api::U_ZERO_ERROR;

 m_ptr=m_spICU->m_ucnv_open.point()(icu_cs_name.c_str(),&icu_status);

 if(icu_status!=api::U_ZERO_ERROR)
 {
  assert(m_ptr==NULL);

  if(icu_status==api::U_FILE_ACCESS_ERROR && !must_be_created)
   return false;

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_icu__create_cs_conv_3,
    m_spICU->id(),
    icu_cs_name,
    icu_status);
 }//if - error

 //! \todo ICU BUG-CHECK
 assert(m_ptr!=NULL);

 ///2. Установка call-back функций
 if((direction_flags&conv_direction__to_unicode)==conv_direction__to_unicode)
 {
  const void*                oldContext=NULL;
  api::UConverterToUCallback oldToAction=NULL;

  m_spICU->m_ucnv_setToUCallBack.point()
   (m_ptr,
    m_spICU->m_UCNV_TO_U_CALLBACK_STOP.point(),
    NULL,
    &oldToAction,
    &oldContext,
    &icu_status);

  if(icu_status!=api::U_ZERO_ERROR)
  {
   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mcs_icu__call_func_4,
     m_spICU->id(),
     icu_cs_name,
     m_spICU->m_ucnv_setToUCallBack.point_name(),
     icu_status);
  }//if
 }//if conv_direction__to_unicode

 //------
 if((direction_flags&conv_direction__from_unicode)==conv_direction__from_unicode)
 {
  const void*                  oldContext=NULL;
  api::UConverterFromUCallback oldFromAction=NULL;

  m_spICU->m_ucnv_setFromUCallBack.point()
   (m_ptr,
    m_spICU->m_UCNV_FROM_U_CALLBACK_STOP.point(),
    NULL,
    &oldFromAction,
    &oldContext,
    &icu_status);

  if(icu_status!=api::U_ZERO_ERROR)
  {
   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mcs_icu__call_func_4,
     m_spICU->id(),
     icu_cs_name,
     m_spICU->m_ucnv_setFromUCallBack.point_name(),
     icu_status);
  }//if
 }//conv_direction__from_unicode

 return true;
}//create

//------------------------------------------------------------------------
void t_ibp_cs_icu::tag_conv_holder::free()
{
 assert(m_spICU);

 if(m_ptr!=NULL)
 {
  m_spICU->m_ucnv_close.point()(m_ptr);

  m_ptr=NULL;
 }//if
}//free

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_icu

t_ibp_cs_icu::t_ibp_cs_icu(t_ibp_icu_provider* const        pICU,
                           const db_obj::t_db_charset_info& cs_info,
                           const std::string&               icu_cs_name)
 :m_cs_info     (cs_info)
 ,m_spICU       (structure::not_null_ptr(pICU))
 ,m_icu_cs_name (icu_cs_name)
{
 assert(m_spICU);
}

//------------------------------------------------------------------------
t_ibp_cs_icu::~t_ibp_cs_icu()
{
}

//------------------------------------------------------------------------
t_ibp_cs_icu::self_ptr
 t_ibp_cs_icu::create(t_ibp_icu_provider* const pICU,
                      const cs_name_box_type&   cs_name,
                      bool                const must_be_created)
{
 assert(pICU);

 const std::string icu_cs_name(structure::tstr_to_str(cs_name));

 tag_conv_holder conv(pICU);

 if(!conv.create(icu_cs_name,0,must_be_created))
  return nullptr;

 ///Запрашиваем информацию о кодовой странице
 const api::int8_t min_char_sz=pICU->m_ucnv_getMinCharSize.point()(conv.ptr());
 const api::int8_t max_char_sz=pICU->m_ucnv_getMaxCharSize.point()(conv.ptr());

 ///Проверка полученной информации
 if((min_char_sz<=0) || (max_char_sz<=0) || (max_char_sz<min_char_sz))
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_icu__bad_min_max_char_size_4,
    pICU->id(),
    cs_name,
    int(min_char_sz),
    int(max_char_sz));
 }//if

 ///Проверяем возможность работы с символьным набором
 if(ibp_limc_MaxByteOfOneMultiByteSymbol<size_t(max_char_sz))
 {
  IBP_ErrorUtils::Throw__Error
   (DB_E_NOTSUPPORTED,
    ibp_mce_icu__large_max_char_size_4,
    pICU->id(),
    cs_name,
    int(max_char_sz),
    ibp_limc_MaxByteOfOneMultiByteSymbol);
 }//if

 //----
 db_obj::t_db_charset_info cs_info;

 assert(structure::can_numeric_cast(&cs_info.bytes_per_char,max_char_sz));
 assert(structure::can_numeric_cast(&cs_info.min_bytes_per_char,min_char_sz));

 structure::static_numeric_cast(&cs_info.bytes_per_char     ,max_char_sz);
 structure::static_numeric_cast(&cs_info.min_bytes_per_char ,min_char_sz);

 cs_info.ucs2_for_char=1;

 cs_info.name=cs_name.make_str();

 //----
 return structure::not_null_ptr(new self_type(pICU,cs_info,icu_cs_name));
}//create

//t_db_charset interface -------------------------------------------------
const db_obj::t_db_charset_info& t_ibp_cs_icu::get_info()const
{
 return m_cs_info;
}//get_info

//------------------------------------------------------------------------
bool t_ibp_cs_icu::to_unicode_v2(std::wstring*              const pws,
                                 structure::t_const_str_box const s)const
{
 assert(m_spICU);
 assert(pws);

 CHECK_READ_TYPED_PTR(s.ptr,s.len)

 //--------
 const wchar_t* const c_bugcheck_src
  =L"v063::t_ibp_cs_icu::to_unicode_v2";

 //--------
 pws->clear();

 if(s.empty())
  return true;

 //--------
 const api::int32_t isz
  =ibp_size_cast<api::int32_t>
    (s.len,
     c_bugcheck_src,
     L"isz");

 //--------
 typedef structure::t_typed_simple_buffer<api::UChar,IBP_MemoryAllocator> buf_type;

 //резервируем место под терминальные нули.
 //два UCS2 символа на один Ascii символ

 //! \todo
 //!  Добавить контроль переполнения

 buf_type
  result_buf
   (ibp_size_cast<api::int32_t>
     (2*(s.len+m_cs_info.bytes_per_char),
      c_bugcheck_src,
      L"result_buf_sz"));

 //--------
 tag_conv_holder
  conv
   (m_spICU,
    m_icu_cs_name,
    tag_conv_holder::conv_direction__to_unicode);

 //--------
 api::UErrorCode icu_status=api::U_ZERO_ERROR;

 const api::int32_t
  actual_sz
   =m_spICU->m_ucnv_toUChars.point()
     (conv.ptr(),
      result_buf.buffer(),
      static_cast<api::int32_t>(result_buf.size()),
      s.ptr,
      isz,
      &icu_status);

 if(icu_status!=api::U_ZERO_ERROR)
  return false;

 if(!structure::can_numeric_cast<size_t>(actual_sz) || size_t(actual_sz)>result_buf.size())
 {
  this->Throw_BugCheck
   (m_spICU->m_ucnv_toUChars.point_name(),
    L"to_unicode_v2 #001");
 }//if

 pws->assign(result_buf.buffer(),result_buf.buffer()+actual_sz);

 return true;
}//to_unicode_v2

//------------------------------------------------------------------------
bool t_ibp_cs_icu::from_unicode_v2(std::string*                const ps,
                                   structure::t_const_wstr_box const ws)const
{
 assert(ps);

 CHECK_READ_TYPED_PTR(ws.ptr,ws.len);

 //--------
 const wchar_t* const c_bugcheck_src
  =L"v063::t_ibp_cs_icu::from_unicode_v2";

 //--------
 ps->clear();

 if(ws.empty())
  return true;

 //--------
 const api::int32_t iwsz
  =ibp_size_cast<api::int32_t>
    (ws.len,
     c_bugcheck_src,
     L"iwsz");

 //--------
 typedef structure::t_typed_simple_buffer<char,IBP_MemoryAllocator> buf_type;

 //резервируем место под терминальные нули.
 buf_type
  result_buf
   (ibp_size_cast<api::int32_t>
     (m_cs_info.bytes_per_char*(ws.len+1),
      c_bugcheck_src,
      L"result_buf_sz"));

 //--------
 tag_conv_holder
  conv
   (m_spICU,
    m_icu_cs_name,
    tag_conv_holder::conv_direction__from_unicode);

 //--------
 api::UErrorCode icu_status=api::U_ZERO_ERROR;

 const api::int32_t
  actual_sz
   =m_spICU->m_ucnv_fromUChars.point()
     (conv.ptr(),
      result_buf.buffer(),
      static_cast<api::int32_t>(result_buf.size()),
      ws.ptr,
      iwsz,
      &icu_status);

 if(icu_status!=api::U_ZERO_ERROR)
  return false;

 if(!structure::can_numeric_cast<size_t>(actual_sz) || size_t(actual_sz)>result_buf.size())
 {
  this->Throw_BugCheck
   (m_spICU->m_ucnv_fromUChars.point_name(),
    L"from_unicode_v2 #001");
 }//if

 ps->assign(result_buf.buffer(),result_buf.buffer()+actual_sz);

 return true;
}//from_unicode_v2

//------------------------------------------------------------------------
db_obj::t_db_text_stream__ucs2_ptr
 t_ibp_cs_icu::mbc_stream_to_ucs2_stream(db_obj::t_db_text_stream__mbc* const mbc_stream)const
{
 if(mbc_stream==NULL)
  return nullptr;

 return structure::not_null_ptr
         (new tag_text_stream__mbc_to_ucs2
           (this,
            mbc_stream));
}//mbc_stream_to_ucs2_stream

//------------------------------------------------------------------------
db_obj::t_db_text_stream__ucs2_ptr
 t_ibp_cs_icu::mbc_buffer_to_ucs2_stream(const char* const mbc_buffer,
                                         size_type   const mbc_buffer_size)const
{
 CHECK_READ_TYPED_PTR(mbc_buffer,mbc_buffer_size);

 return structure::not_null_ptr
         (new tag_text_stream__mbc_buffer_to_ucs2
           (this,
            mbc_buffer,
            mbc_buffer_size));
}//mbc_buffer_to_ucs2_stream

//------------------------------------------------------------------------
db_obj::t_db_text_stream__mbc_ptr
 t_ibp_cs_icu::ucs2_stream_to_mbc_stream(db_obj::t_db_text_stream__ucs2* const ucs2_stream)const
{
 if(ucs2_stream==NULL)
  return nullptr;

 return structure::not_null_ptr(new tag_text_stream__ucs2_to_mbc(this,ucs2_stream));
}//ucs2_stream_to_mbc_stream

//------------------------------------------------------------------------
db_obj::t_db_cs_result
 t_ibp_cs_icu::sb_to_unicode(ansi_streambuf_type& in_buf,
                             wchar_t*             ws,
                             size_type&           wsz)const
{
 CHECK_WRITE_TYPED_PTR(ws,wsz);

 const size_type original_wsz=wsz;

 wsz=0;

 //--------
 tag_conv_holder
  conv
   (m_spICU,
    m_icu_cs_name,
    tag_conv_holder::conv_direction__to_unicode);

 //--------
 const wchar_t* const beg_ws=ws;
 const wchar_t* const end_ws=ws+original_wsz;

 while(ws!=end_ws)
 {
  ansi_streambuf_type::value_type c;

  if(!in_buf.get(&c))
   break;

  const char* source_ptr=&c;

  //загоняем в конвертор один Ascii символ
  api::UErrorCode icu_status=api::U_ZERO_ERROR;

  this->call__ucnv_toUnicode
   (conv.ptr(),
    &ws,
    end_ws,
    &source_ptr,
    source_ptr+1,
    /*flush*/0,
    &icu_status);

  //------
  if(icu_status==api::U_BUFFER_OVERFLOW_ERROR)
  {
   //Игнорируем OUT-данные предыдущего вызова. wsz не обновляется не будет.

   return db_obj::db_cs_result__trunc;
  }//if

  if(icu_status!=api::U_ZERO_ERROR)
   return db_obj::db_cs_result__fail;

  //должны были сдвинутся
  if(source_ptr==&c)
  {
   //обнаружено потенциальное зацикливание
   this->Throw_BugCheck
    (m_spICU->m_ucnv_toUnicode.point_name(),
     L"sb_to_unicode #001");
  }//if

  //обновляем размер OUT-данных
  wsz=ws-beg_ws;
 }//while(ws!=end_ws)

 //сюда мы можем попасть по двум причинам
 // - достигли EOF
 // - заполнен весь OUT-буфер

 const bool get_eof=in_buf.eof();

 if(get_eof)
 {
  const char  c=0;
  const char* source_ptr=&c;

  api::UErrorCode icu_status=api::U_ZERO_ERROR;

  //формально, здесь мы можем получить либо ok либо error.
  // ok - в случае пустых внутренних буферов conv
  // error - конвертор содержит часть ascii символа

  // переполнение мы не должны здесь получить, потому что такая ситуция
  // должны была случится в предыдущем цикле. вряд ли конвертор будет удерживать
  // готовые Wide-символы, когда их можно выгрузить наружу.

  this->call__ucnv_toUnicode
   (conv.ptr(),
    &ws,
    end_ws,
    &source_ptr,
    source_ptr,
    /*flush*/1,
    &icu_status);

  //------
  //обновляем размер OUT-данных
  wsz=ws-beg_ws;

  if(icu_status==api::U_BUFFER_OVERFLOW_ERROR)
   return db_obj::db_cs_result__trunc;

  if(icu_status!=api::U_ZERO_ERROR)
   return db_obj::db_cs_result__fail;

  return db_obj::db_cs_result__ok;
 }//if get_eof

 assert(!get_eof);

 //раз мы не достигли EOF входящего потока, значит мы забили OUT-буфер

 assert(ws==end_ws);

 return db_obj::db_cs_result__trunc;
}//sb_to_unicode

//------------------------------------------------------------------------
bool t_ibp_cs_icu::sb_len_as_unicode(ansi_streambuf_type& in_buf,
                                     size_type&           wsz)const
{
 wsz=0;

 //--------
 tag_conv_holder
  conv
   (m_spICU,
    m_icu_cs_name,
    tag_conv_holder::conv_direction__to_unicode);

 //-------- перекодируем блоками по 1K
 char source_buffer[1024];

 api::UChar target_buffer[_DIM_(source_buffer)*ibp_limc_MaxUnicodeSymbolsForOneMultiByteSymbol];

 api::UChar*       const beg_ws=target_buffer;
 const api::UChar* const end_ws=_END_(target_buffer);

 for(;;)
 {
  ansi_streambuf_type::size_type source_sz=0;

  in_buf.getn(source_buffer,_DIM_(source_buffer),&source_sz);

  assert(source_sz<=_DIM_(source_buffer));

  const char*       source_ptr=source_buffer;
  const char* const source_end=source_ptr+source_sz;

  assert(source_ptr<=source_end);

  for(;;)
  {
   const char* const start_source_ptr=source_ptr;

   //запоминаем текущее начало OUT-буфера. используем для контроля
   wchar_t* ws=beg_ws;

   //конвертируем source_buffer
   api::UErrorCode icu_status=api::U_ZERO_ERROR;

   this->call__ucnv_toUnicode
    (conv.ptr(),
     &ws,
     end_ws,
     &source_ptr,
     source_end,
     /*flush*/(source_ptr==source_end),
     &icu_status);

   //------ проверяем код возврата
   if(icu_status!=api::U_ZERO_ERROR && icu_status!=api::U_BUFFER_OVERFLOW_ERROR)
    return false;

   //выявляем зацикливание
   if(start_source_ptr!=source_end)
   {
    //должны были сдвинуться
    if(ws==beg_ws && source_ptr==start_source_ptr)
    {
     //обнаружено потенциальное зацикливание
     this->Throw_BugCheck
      (m_spICU->m_ucnv_toUnicode.point_name(),
       L"sb_len_as_unicode #001");
    }//if
   }//if

   //обновляем размер OUT-данных
   assert(beg_ws<=ws);

   const size_t x=static_cast<size_t>(ws-beg_ws);

   //контроль переполнения
   if(!ibp::ibp_can_numeric_add(wsz,x))
   {
    //ERROR - переполнение при вычислении размера UNICODE-представления данных
    IBP_ErrorUtils::Throw__Error
     (DB_E_DATAOVERFLOW,
      ibp_mce_cs__calc_length_in_ucs2_chars__overflow_1,
      this->get_info().name);
   }//if

   wsz+=x;

   if(source_ptr==source_end)
    break; //достигли конца IN-буфера
  }//for - цикл конвертирования

  if(source_sz==0)
  {
   //пустой набор внешних данных

   //то есть это EOF
   assert(in_buf.eof());

   break;
  }//if
 }//for - цикл загрузки исходных данных

 return true;
}//sb_len_as_unicode

//------------------------------------------------------------------------
bool t_ibp_cs_icu::unicode_to_blob(const wchar_t*                  const source,
                                   size_type                       const source_size,
                                   db_obj::t_db_seq_stream_writer* const writer)const
{
 assert(writer);

 CHECK_READ_TYPED_PTR(source,source_size);

 //-----
 if(source_size==0)
  return true;

 //---- создаем ICU-конвертор
 tag_conv_holder
  conv
   (m_spICU,
    m_icu_cs_name,
    tag_conv_holder::conv_direction__from_unicode); //throw

 //---- подключаем объект записи к буферу потока
 char out_buf[8*1024];

 db_obj::t_db_blob_writer_buf writer_buf(out_buf,_DIM_(out_buf),writer);

 //---- выгружем блоками по 8K
 char target_buffer[8*1024];

 char*       const target_beg=target_buffer;
 const char* const target_end=_END_(target_buffer);

 //----
 const wchar_t*       source_ptr=source;
 const wchar_t* const source_end=source_ptr+source_size;

 for(;;)
 {
  //запоминаем указатель на начало IN-данных
  const wchar_t* const start_source_ptr=source_ptr;

  char* target_ptr=target_beg;

  api::UErrorCode icu_status=api::U_ZERO_ERROR;

  this->call__ucnv_fromUnicode
   (conv.ptr(),
    &target_ptr,
    target_end,
    &source_ptr,
    source_end,
    /*flush*/source_ptr==source_end,
    &icu_status);

  //-------- проверяем код возврата
  if(icu_status!=api::U_ZERO_ERROR && icu_status!=api::U_BUFFER_OVERFLOW_ERROR)
   return false;

  //-------- выгружаем полученные данные
  if(target_ptr!=target_beg)
  {
   db_obj::t_db_blob_writer_buf::size_type actual_writed=0;

   writer_buf.putn(target_beg,target_ptr-target_beg,&actual_writed);

   assert(actual_writed==static_cast<size_t>(target_ptr-target_beg));

   continue;
  }//if

  //-------- анализ завершения работы
  if(source_ptr==source_end)
  {
   //обработаны все исходые данные и выгружены все OUT-символы
   break;
  }//if

  //-------- выявляем зацикливание
  assert(target_ptr==target_beg);

  //мы должны были либо прочитать/выгрузить хотя бы один символ, либо вернуть ошибку
  if(start_source_ptr==source_ptr)
  {
   //обнаружено потенциальное зацикливание
   this->Throw_BugCheck
    (m_spICU->m_ucnv_fromUnicode.point_name(),
     L"unicode_to_blob #001");
  }//if
 }//for - цикл перекодирования и выгрузки Ascii-символов

 //это условие выхода из цикла
 assert(source_ptr==source_end);

 //выгружаем забуферизированные данные
 writer_buf.flush();

 return true;
}//unicode_to_blob

//------------------------------------------------------------------------
void t_ibp_cs_icu::call__ucnv_toUnicode(api::UConverter*  const conv,
                                        api::UChar**      const target_pptr,
                                        const api::UChar* const target_end,
                                        const char**      const source_pptr,
                                        const char*       const source_end,
                                        bool              const flush,
                                        api::UErrorCode*  const err)const
{
 assert(m_spICU);
 assert(target_pptr);
 assert(source_pptr);
 assert(err);

 assert((*target_pptr)<=target_end);
 assert((*source_pptr)<=source_end);

 const api::UChar* const target_beg=(*target_pptr);
 const char*       const source_beg=(*source_pptr);

 m_spICU->m_ucnv_toUnicode.point()
  (conv,
   target_pptr,
   target_end,
   source_pptr,
   source_end,
   /*offsets*/NULL,
   /*flush*/flush,
   err);

 //------ проверка работы внешней функции
 if((*source_pptr)<source_beg || source_end<(*source_pptr))
 {
  //ERROR - Некорректная работа ICU-конвертора
  this->Throw_BugCheck
   (m_spICU->m_ucnv_toUnicode.point_name(),
    L"call__ucnv_toUnicode #001");
 }//if

 if((*target_pptr)<target_beg || target_end<(*target_pptr))
 {
  //ERROR - Некорректная работа ICU-конвертора
  this->Throw_BugCheck
   (m_spICU->m_ucnv_toUnicode.point_name(),
    L"call__ucnv_toUnicode #002");
 }//if
}//call__ucnv_toUnicode

//------------------------------------------------------------------------
void t_ibp_cs_icu::call__ucnv_fromUnicode(api::UConverter*   const conv,
                                          char**             const target_pptr,
                                          const char*        const target_end,
                                          const api::UChar** const source_pptr,
                                          const api::UChar*  const source_end,
                                          bool               const flush,
                                          api::UErrorCode*   const err)const
{
 assert(m_spICU);
 assert(target_pptr);
 assert(source_pptr);
 assert(err);

 assert((*target_pptr)<=target_end);
 assert((*source_pptr)<=source_end);

 const char*       const target_beg=(*target_pptr);
 const api::UChar* const source_beg=(*source_pptr);

 m_spICU->m_ucnv_fromUnicode.point()
  (conv,
   target_pptr,
   target_end,
   source_pptr,
   source_end,
   /*offsets*/NULL,
   /*flush*/flush,
   err);

 //------ проверка работы внешней функции
 if((*source_pptr)<source_beg || source_end<(*source_pptr))
 {
  //ERROR - Некорректная работа ICU-конвертора
  this->Throw_BugCheck
   (m_spICU->m_ucnv_fromUnicode.point_name(),
    L"call__ucnv_fromUnicode #001");
 }//if

 if((*target_pptr)<target_beg || target_end<(*target_pptr))
 {
  //ERROR - Некорректная работа ICU-конвертора
  this->Throw_BugCheck
   (m_spICU->m_ucnv_fromUnicode.point_name(),
    L"call__ucnv_fromUnicode #002");
 }//if
}//call__ucnv_fromUnicode

//------------------------------------------------------------------------
void t_ibp_cs_icu::Throw_BugCheck(const char*    const func_name,
                                  const wchar_t* const check_point)const
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_icu__bug_check_4,
   m_spICU->id(),
   m_icu_cs_name,
   func_name,
   check_point);
}//Throw_BugCheck

////////////////////////////////////////////////////////////////////////////////
}/*nms v063*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
