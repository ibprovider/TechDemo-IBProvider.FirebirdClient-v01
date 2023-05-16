////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__array_slice_v01__utilities.cpp
//! \brief   Utilities for work with database arrays.
//! \author  Kovalenko Dmitry
//! \date    11.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__array_slice_v01__utilities.h"
#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__array_sdl_reader.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/ib_base/ib_charset_utility.h"
#include "source/db_obj/db_charset_manager_v2.h"
#include "source/db_obj/db_service_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__ArraySlice_v01__Utilities

void RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL
                                           (db_obj::t_db_operation_context&  opCtx,
                                            size_t                     const szSDL,
                                            const byte_type*           const pSDL,
                                            RemoteFB__ArraySliceDescr* const pDescr)
{
 assert(szSDL);
 assert(pSDL);
 assert(pDescr);

 CHECK_READ_TYPED_PTR(pSDL,szSDL);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL";

 //-----------------------------------------
 pDescr->Init();

 //-----------------------------------------
 if(szSDL==0)
 {
  //ERROR - incorrect SDL - no data

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__no_data
   (c_bugcheck_src,
    L"#001");
 }//if

 assert(szSDL>0);

 //-----------------------------------------
 const db_obj::t_db_charset_manager_v2_ptr
  spCsMng
   =db_obj::query_db_service<db_obj::t_db_charset_manager_v2>(opCtx);

 assert(spCsMng);

 //-----------------------------------------
 tag_sdl_reader sdl_reader(szSDL,pSDL);

 const db_obj::t_db_charset_const_ptr
  metadata_charset(ib_base::ib_get_metadata_charset(spCsMng));

 assert(metadata_charset);

 //----------------------------------------- READ SDL VERSION NUMBER (version1)
 switch(const byte_type v=sdl_reader.read_byte(c_bugcheck_src,L"#002"))
 {
  case isc_api::ibp_isc_sdl_version1:
   break;

  default:
  {
   //ERROR - incorrect sdl - wrong version
   RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unk_version
    (c_bugcheck_src,
     L"#003",
     v);
  }//default
 }//switch

 //-----------------------------------------
 //флаги, используемые для протоколирования установки данных

 enum tag_element_id
 {
  sdl_element_id__struct                    =0x0001,
  sdl_element_id__relation                  =0x0002,
  sdl_element_id__field                     =0x0004,
  sdl_element_id__element                   =0x0008,
 };

 unsigned __int32  SdlElementIDs=0;

 //-----------------------------------------
 bool DefinedBounds[_DIM_(pDescr->m_bounds)];

 std::fill(DefinedBounds,_END_(DefinedBounds),false);

 for(bool stop=false;!stop;)
 {
  const size_t processedTagOffset=sdl_reader.current_offset();

  switch(byte_type op=sdl_reader.read_byte(c_bugcheck_src,L"#004"))
  {
   case isc_api::ibp_isc_sdl_eoc:
   {
    stop=true;
    break;
   }//case - ibp_isc_sdl_eoc

   //---------------------------------------------------------
   case isc_api::ibp_isc_sdl_struct:
   {
    //Проверка повторной обработки тэга ibp_isc_sdl_struct.

    if((SdlElementIDs&sdl_element_id__struct)!=0)
    {
     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__mult_def_of_element
      (c_bugcheck_src,
       L"#S00",
       L"isc_sdl_struct",
       processedTagOffset);
    }//if

    switch(const byte_type n=sdl_reader.read_byte(c_bugcheck_src,L"#S01"))
    {
     case 1: //одно поле
      break;

     default:
     {
      //ERROR - incorrect sdl. wrong number of structure fields

      RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__wrong_count_of_struct_fields
       (c_bugcheck_src,
        L"#S02",
        n);
     }//default
    }//switch

    Helper__ParseSDL__ReadElementType
     (sdl_reader,
      pDescr); //throw

    SdlElementIDs|=sdl_element_id__struct;

    break;
   }//case - ibp_isc_sdl_struct

   //---------------------------------------------------------
   case isc_api::ibp_isc_sdl_relation:
   {
    //Проверка повторной обработки тэга ibp_isc_sdl_relation.

    if((SdlElementIDs&sdl_element_id__relation)!=0)
    {
     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__mult_def_of_element
      (c_bugcheck_src,
       L"#R00",
       L"isc_sdl_relation",
       processedTagOffset);
    }//if

    const std::string s(sdl_reader.read_string(c_bugcheck_src,L"#R01",L"#R02"));

    if(!metadata_charset->to_unicode_v2(&pDescr->m_relation_name,s))
    {
     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__failed_to_translate_str_to_unicode
      (c_bugcheck_src,
       L"#R03",
       metadata_charset->get_info().name);
    }//if

    SdlElementIDs|=sdl_element_id__relation;

    break;
   }//case - ibp_isc_sdl_relation

   //---------------------------------------------------------
   case isc_api::ibp_isc_sdl_field:
   {
    //Проверка повторной обработки тэга ibp_isc_sdl_field.

    if((SdlElementIDs&sdl_element_id__field)!=0)
    {
     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__mult_def_of_element
      (c_bugcheck_src,
       L"#F00",
       L"isc_sdl_field",
       processedTagOffset);
    }//if

    const std::string s(sdl_reader.read_string(c_bugcheck_src,L"#F01",L"#F02"));

    if(!metadata_charset->to_unicode_v2(&pDescr->m_field_name,s))
    {
     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__failed_to_translate_str_to_unicode
      (c_bugcheck_src,
       L"#F03",
       metadata_charset->get_info().name);
    }//if

    SdlElementIDs|=sdl_element_id__field;

    break;
   }//case - ibp_isc_sdl_field

   //---------------------------------------------------------
   case isc_api::ibp_isc_sdl_do1:
   {
    //границы индексируются с нуля
    const byte_type n=sdl_reader.read_byte(c_bugcheck_src,L"#D101");

    if(_DIM_(pDescr->m_bounds)<=n)
    {
     //ERROR - Invalid SDL - incorrect index of bound

     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__wrong_index_of_bound
      (c_bugcheck_src,
       L"#D102",
       n,
       _DIM_(pDescr->m_bounds));
    }//if

    assert(n<_DIM_(pDescr->m_bounds));
    assert(n<_DIM_(DefinedBounds));

    if(DefinedBounds[n])
    {
     //ERROR - Invalid SDL. Duplication of bound description.

     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__mult_def_of_bound_range
      (c_bugcheck_src,
       L"#D103",
       n);
    }//if DefinedBounds

    const value_i4_type upper=self_type::Helper__ParseSDL__ReadLiteral(sdl_reader);

    if(upper</*lower*/1)
    {
     //ERROR - incorrect SDL. Bad bound range.

     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__bad_bound_range
      (c_bugcheck_src,
       L"#D104",
       n,
       /*lower*/1,
       upper);
    }//if

    pDescr->m_bounds[n].lower=1;
    pDescr->m_bounds[n].upper=upper;

    DefinedBounds[n]=true;

    if(pDescr->m_bounds_number<=n)
     pDescr->m_bounds_number=n+1;

    assert(n<pDescr->m_bounds_number);

    break;
   }//case ibp_isc_sdl_do1

   //---------------------------------------------------------
   case isc_api::ibp_isc_sdl_do2:
   {
    //границы индексируются с нуля
    const byte_type n=sdl_reader.read_byte(c_bugcheck_src,L"#D201");

    if(_DIM_(pDescr->m_bounds)<=n)
    {
     //ERROR - Invalid SDL - incorrect index of bound

     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__wrong_index_of_bound
      (c_bugcheck_src,
       L"#D202",
       n,
       _DIM_(pDescr->m_bounds));
    }//if

    assert(n<_DIM_(pDescr->m_bounds));
    assert(n<_DIM_(DefinedBounds));

    if(DefinedBounds[n])
    {
     //ERROR - Invalid SDL. Duplication of bound description.

     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__mult_def_of_bound_range
      (c_bugcheck_src,
       L"#D203",
       n);
    }//local

    assert(pDescr->m_bounds_number<_DIM_(pDescr->m_bounds));

    const value_i4_type lower=self_type::Helper__ParseSDL__ReadLiteral(sdl_reader);
    const value_i4_type upper=self_type::Helper__ParseSDL__ReadLiteral(sdl_reader);

    if(upper<lower)
    {
     //ERROR - incorrect SDL. Bad bound range.

     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__bad_bound_range
      (c_bugcheck_src,
       L"#D204",
       n,
       lower,
       upper);
    }//if

    pDescr->m_bounds[n].lower=lower;
    pDescr->m_bounds[n].upper=upper;

    DefinedBounds[n]=true;

    if(pDescr->m_bounds_number<=n)
     pDescr->m_bounds_number=n+1;

    assert(n<pDescr->m_bounds_number);

    break;
   }//case ibp_isc_sdl_do2

   //---------------------------------------------------------
   case isc_api::ibp_isc_sdl_element:
   {
    //Не допускаем повторное определение элемента

    if((SdlElementIDs&sdl_element_id__element)!=0)
    {
     RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__mult_def_of_element
      (c_bugcheck_src,
       L"#E00",
       L"isc_sdl_element",
       processedTagOffset);
    }//if

    self_type::Helper__ParseSDL__ReadElement(sdl_reader,pDescr);

    SdlElementIDs|=sdl_element_id__element;

    break;
   }//case ibp_isc_sdl_element

   //---------------------------------------------------------
   default:
   {
    //ERROR - incorrect SDL

    RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_tag
     (c_bugcheck_src,
      L"#X00",
      op,
      processedTagOffset);
   }//default
  }//switch op
 }//for !stop

 //-----------------------------------------
 assert(sdl_reader.current_offset()<=szSDL);


 if(sdl_reader.current_offset()!=szSDL)
 {
  //ERROR - Incorrect format of SDL. несогласованные размеры буфера и данных. должны быть идентичны.

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__inconsistent_sizes_of_buffer_and_data
   (c_bugcheck_src,
    L"#005",
    szSDL,
    sdl_reader.current_offset());
 }//if

 //-----------------------------------------
 if((SdlElementIDs&sdl_element_id__struct)==0)
 {
  //ERROR - Отсутствует описание типа элемента массива

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__no_data_of_tag
   (c_bugcheck_src,
    L"#006",
    L"isc_sdl_struct");
 }//if

 //-----------------------------------------
 if((SdlElementIDs&sdl_element_id__relation)==0)
 {
  //ERROR - Отсутствует описание таблицы массива

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__no_data_of_tag
   (c_bugcheck_src,
    L"#007",
    L"isc_sdl_relation");
 }//if

 //-----------------------------------------
 if((SdlElementIDs&sdl_element_id__field)==0)
 {
  //ERROR - Отсутствует описание колонки массива

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__no_data_of_tag
   (c_bugcheck_src,
    L"#008",
    L"isc_sdl_field");
 }//if

 //-----------------------------------------
 if(pDescr->m_bounds_number==0)
 {
  //ERROR - Отсутствует описание размерностей

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__no_data_of_dimensions
   (c_bugcheck_src,
    L"#009");
 }//if

 //-----------------------------------------
 {
  const bool* const _b=DefinedBounds;
  const bool* const _e=DefinedBounds+pDescr->m_bounds_number;

  const bool* const p=std::find(_b,_e,false);

  assert(p<=_e);

  if(p!=_e)
  {
   //ERROR - Отсутствует описание размерности с индексом xxx

   RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__no_data_of_dimension
    (c_bugcheck_src,
     L"#010",
     static_cast<size_t>(p-_b));
  }//if
 }//local

 //EXIT
}//ParseSDL

//helper methods ---------------------------------------------------------
void RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType
                                           (tag_sdl_reader&                  sdlReader,
                                            RemoteFB__ArraySliceDescr* const pDescr)
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType";

 //-----------------------------------------
 const size_t blrTypeIdOffset
  =sdlReader.current_offset();

 pDescr->m_element_blr_typeid
  =sdlReader.read_byte
    (c_bugcheck_src,
     L"#001");

 switch(pDescr->m_element_blr_typeid)
 {
  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__short:
  {
   pDescr->m_element_sql_scale
    =sdlReader.read_i1
      (c_bugcheck_src,
       L"#002");

   //проверять значение масштаба мы не будем. формально - это не наше дело.

   pDescr->m_element_sql_length=sizeof(db_obj::t_dbvalue__i2);

   pDescr->m_element_total_length=sizeof(db_obj::t_dbvalue__i2);

   break;
  }//case isc_blr_dtype__short

  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__long:
  {
   pDescr->m_element_sql_scale
    =sdlReader.read_i1
      (c_bugcheck_src,
       L"#003");

   //проверять значение масштаба мы не будем. формально - это не наше дело.

   pDescr->m_element_sql_length=sizeof(db_obj::t_dbvalue__i4);

   pDescr->m_element_total_length=sizeof(db_obj::t_dbvalue__i4);

   break;
  }//case isc_blr_dtype__long

  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__int64:
  {
   pDescr->m_element_sql_scale
    =sdlReader.read_i1
      (c_bugcheck_src,
       L"#004");

   //проверять значение масштаба мы не будем. формально - это не наше дело.

   pDescr->m_element_sql_length=sizeof(db_obj::t_dbvalue__i8);

   pDescr->m_element_total_length=sizeof(db_obj::t_dbvalue__i8);

   break;
  }//case ibp_isc_blr_dtype__int64

  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__float:
  {
   pDescr->m_element_sql_scale=0;

   pDescr->m_element_sql_length=sizeof(db_obj::t_dbvalue__r4);

   pDescr->m_element_total_length=sizeof(db_obj::t_dbvalue__r4);

   break;
  }//case ibp_isc_blr_dtype__float

  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__double:
  {
   pDescr->m_element_sql_scale=0;

   pDescr->m_element_sql_length=sizeof(db_obj::t_dbvalue__r8);

   pDescr->m_element_total_length=sizeof(db_obj::t_dbvalue__r8);

   break;
  }//case ibp_isc_blr_dtype__double

  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__sql_time:
  {
   pDescr->m_element_sql_scale=0;

   pDescr->m_element_sql_length=sizeof(isc_api::t_ibp_isc_time);

   pDescr->m_element_total_length=sizeof(isc_api::t_ibp_isc_time);

   break;
  }//case ibp_isc_blr_dtype__sql_time

  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__sql_date:
  {
   pDescr->m_element_sql_scale=0;

   pDescr->m_element_sql_length=sizeof(isc_api::t_ibp_isc_date);

   pDescr->m_element_total_length=sizeof(isc_api::t_ibp_isc_date);

   break;
  }//case ibp_isc_blr_dtype__sql_date

  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__timestamp:
  {
   pDescr->m_element_sql_scale=0;

   pDescr->m_element_sql_length=sizeof(isc_api::t_ibp_isc_timestamp);

   pDescr->m_element_total_length=sizeof(isc_api::t_ibp_isc_timestamp);

   break;
  }//case ibp_isc_blr_dtype__timestamp

  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__text2:
  {
   pDescr->m_element_sql_scale=0;

   pDescr->m_element_sql_text_props=sdlReader.read_ui2(c_bugcheck_src,L"#005");

   pDescr->m_element_sql_length=sdlReader.read_ui2(c_bugcheck_src,L"#006");

   if(!(pDescr->m_element_sql_length>0 && pDescr->m_element_sql_length<=isc_api::ibp_isc_max_char_length))
   {
    //ERROR - incorrect SDL - incorrect length of element

    RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__invalid_element_length
     (c_bugcheck_src,
      L"#L01",
      pDescr->m_element_sql_length,
      L"text2");
   }//if

   pDescr->m_element_total_length=pDescr->m_element_sql_length;

   break;
  }//case ibp_isc_blr_dtype__text2

  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__varying2:
  {
   pDescr->m_element_sql_scale=0;

   pDescr->m_element_sql_text_props=sdlReader.read_ui2(c_bugcheck_src,L"#007");

   pDescr->m_element_sql_length=sdlReader.read_ui2(c_bugcheck_src,L"#008");

   if(!(pDescr->m_element_sql_length>0 && pDescr->m_element_sql_length<=isc_api::ibp_isc_max_varchar_length))
   {
    //ERROR - incorrect SDL - incorrect length of element

    RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__invalid_element_length
     (c_bugcheck_src,
      L"#L02",
      pDescr->m_element_sql_length,
      L"varying2");
   }//if

   pDescr->m_element_total_length=sizeof(isc_api::isc_varchar_size_type)+pDescr->m_element_sql_length;

   break;
  }//case ibp_isc_blr_dtype__varying2

  //----------------------------------------------------------------------
  case isc_api::ibp_isc_blr_dtype__cstring2:
  {
   pDescr->m_element_sql_scale=0;

   pDescr->m_element_sql_text_props=sdlReader.read_ui2(c_bugcheck_src,L"#009");

   pDescr->m_element_sql_length=sdlReader.read_ui2(c_bugcheck_src,L"#010");

   if(!(pDescr->m_element_sql_length>0 && pDescr->m_element_sql_length<=isc_api::ibp_isc_max_cstring_length))
   {
    //ERROR - incorrect SDL - incorrect length of element

    RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__invalid_element_length
     (c_bugcheck_src,
      L"#L03",
      pDescr->m_element_sql_length,
      L"cstring2");
   }//if

   pDescr->m_element_total_length=pDescr->m_element_sql_length;

   break;
  }//case ibp_isc_blr_dtype__cstring2

  //----------------------------------------------------------------------
  case isc_api::ibp_fb030_blr_dtype__bool:
  {
   pDescr->m_element_sql_scale=0;

   pDescr->m_element_sql_length=sizeof(isc_api::t_ibp_fb030_bool);

   pDescr->m_element_total_length=sizeof(isc_api::t_ibp_fb030_bool);

   break;
  }//case ibp_fb030_blr_dtype__bool

  //----------------------------------------------------------------------
  case isc_api::ibp_fb040_blr_dtype__int128:
  {
   pDescr->m_element_sql_scale
    =sdlReader.read_i1
      (c_bugcheck_src,
       L"#011");

   //проверять значение масштаба мы не будем. формально - это не наше дело.

   pDescr->m_element_sql_length=sizeof(db_obj::t_dbvalue__fb040_int128);

   pDescr->m_element_total_length=sizeof(db_obj::t_dbvalue__fb040_int128);

   break;
  }//case ibp_fb040_blr_dtype__int128

  //----------------------------------------------------------------------
  default:
  {
   //ERROR - incorrect SDL - unexpected BLR data type id

   RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unknown_blrtypeid
    (c_bugcheck_src,
     L"#Z00",
     pDescr->m_element_blr_typeid,
     blrTypeIdOffset);
  }//default
 }//switch
}//Helper__ParseSDL__ReadElementType

//------------------------------------------------------------------------
RemoteFB__API_HLP__ArraySlice_v01__Utilities::value_i4_type
 RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadLiteral(tag_sdl_reader& sdlReader)
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadLiteral";

 const size_t offsetOfLiteral=sdlReader.current_offset();

 switch(const byte_type x=sdlReader.read_byte(c_bugcheck_src,L"#001"))
 {
  case isc_api::ibp_isc_sdl_tiny_integer:
   return sdlReader.read_i1(c_bugcheck_src,L"#002");

  case isc_api::ibp_isc_sdl_short_integer:
   return sdlReader.read_i2(c_bugcheck_src,L"#003");

  case isc_api::ibp_isc_sdl_long_integer:
   return sdlReader.read_i4(c_bugcheck_src,L"#004");

  default:
  {
   //ERROR - incorrect SDL - unexpected kind of literal.

   RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unknown_kind_of_literal
    (c_bugcheck_src,
     L"#005",
     x,
     offsetOfLiteral);
  }//default
 }//switch x

#if(COMP_BUILD_UNUSED_CODE!=0)
 //мы не должны попадать в эту точку.
 assert_hint(false);

 return 0;
#endif
}//Helper__ParseSDL__ReadLiteral

//------------------------------------------------------------------------
void RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement
                                           (tag_sdl_reader&                  sdlReader,
                                            RemoteFB__ArraySliceDescr* const DEBUG_CODE(pDescr))
{
 assert(pDescr);

 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement";

 //------------------------------------------------------------
 switch(const byte_type c=sdlReader.read_byte(c_bugcheck_src,L"#001"))
 {
  case 1:
   break;

  default:
  {
   //ERROR - incorrect SDL. wrong size of element.

   RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__wrong_count_of_element_fields
    (c_bugcheck_src,
     L"#002",
     c);
  }//default
 }//switch

 //------------------------------------------------------------
 {
  const size_t offsetX=sdlReader.current_offset();

  switch(const byte_type x=sdlReader.read_byte(c_bugcheck_src,L"#003"))
  {
   case isc_api::ibp_isc_sdl_scalar:
    break;

   default:
   {
    //ERROR - invalid SDL. unexpected tag.

    RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_tag
     (c_bugcheck_src,
      L"#004",
      x,
      offsetX);
   }//default
  }//switch
 }//local

 //------------------------------------------------------------
 {
  const size_t offsetI=sdlReader.current_offset();

  switch(byte_type const i=sdlReader.read_byte(c_bugcheck_src,L"#005"))
  {
   case 0:
    break;

   default:
   {
    //ERROR - invalid SDL. incorrect property (index) value of scalar tag.

    RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__incorrect_index_property_of_scalar_tag
     (c_bugcheck_src,
      L"#006",
      i,
      offsetI);
   }//default
  }//switch
 }//local

 //------------------------------------------------------------
 //просто пропускаем определение индексов переменных.

 //мы их даже не будем контролировать на корректность.

 const byte_type nVariables=sdlReader.read_byte(c_bugcheck_src,L"#007");

 //загрузка значений
 for(size_t iV=0;iV!=nVariables;++iV)
 {
  const size_t offsetX=sdlReader.current_offset();

  switch(byte_type x=sdlReader.read_byte(c_bugcheck_src,L"#008"))
  {
   case isc_api::ibp_isc_sdl_variable:
    break;

   default:
   {
    //ERROR - Incorrect SDL. Unexpected tag.

    RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectSDL__unexpected_tag
     (c_bugcheck_src,
      L"#009",
      x,
      offsetX);
   }//default
  }//switch

  sdlReader.read_byte(c_bugcheck_src,L"#010");
 }//for iV
}//Helper__ParseSDL__ReadElement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
