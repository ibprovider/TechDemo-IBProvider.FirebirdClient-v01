////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__add_server_keys.cpp
//! \brief   Утилиты подключения. Регистрация типов серверных ключей для шифрования.
//! \author  Kovalenko Dmitry
//! \date    12.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__add_server_keys.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_bug_check.h"

#include "source/ibp_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__AddServerKeys

void RemoteFB__P13__AddServerKeys::exec(RemoteFB__ClientConnectBlock_v2& clientConnectBlock,
                                        size_t                     const cb,
                                        const void*                const pv)
{
 CHECK_READ_PTR(pv,cb)

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__P13__AddServerKeys::exec";

 //-----------------------------------------
 //Tags for clumplets, passed from server to client
 const unsigned char TAG_KEY_TYPE      = 0;
 const unsigned char TAG_KEY_PLUGINS   = 1;
 //const unsigned char TAG_KNOWN_PLUGINS = 2;

 //-----------------------------------------
 const unsigned char* p=reinterpret_cast<const unsigned char*>(pv);

 const unsigned char* const _e_buffer=p+cb;

 while(p!=_e_buffer)
 {
  //! \todo
  //!  в fblclient.dll есть пропуск элемента с тэгом TAG_KNOWN_PLUGINS

  //--------------------------------------------------------- TAG_KEY_TYPE
  assert(p!=_e_buffer);

  std::wstring srv_key__type;

  {
   if((*p)!=TAG_KEY_TYPE)
   {
    //ERROR - некорректная структура буфера с параметрами

    IBP_ThrowBugCheck_InfoBuf__UnknownTag
     (c_bugcheck_src,
      L"#001",
      *p);
   }//if

   ++p;

   if(p==_e_buffer)
   {
    //ERROR - некорректная структура буфера с параметрами

    IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd
     (c_bugcheck_src,
      L"#002");
   }//if

   const unsigned char cluster_length=*p;

   ++p;

   if((_e_buffer-p)<cluster_length)
   {
    //ERROR - некорректный размер данных элемента

    IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
     (c_bugcheck_src,
      L"#003",
      L"TAG_KEY_TYPE",
      cluster_length,
      (_e_buffer-p));
   }//if

   //transform UTF8 string to UCS2 string

   if(!IBP_Utils::Utf8ToWStr__Fast
        (structure::make_str_box(reinterpret_cast<const char*>(p),
                                 cluster_length),
         &srv_key__type))
   {
    //ERROR - ошибка преобразования UTF8-строки с именем типа в UCS2-строку

    RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_name_of_wire_crypt_key_from_utf8_to_wstr
     (c_bugcheck_src,
      L"#004");
   }//if

   if(srv_key__type.empty())
   {
    //ERROR - пустая строка с именем типа ключа

    IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
     (c_bugcheck_src,
      L"#005",
      L"TAG_KEY_TYPE");
   }//if

   p+=cluster_length;
  }//local - TAG_KEY_TYPE

  //--------------------------------------------------------- TAG_KEY_PLUGINS
  if(p==_e_buffer)
  {
   //ERROR - некорректный структура буфера

   IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd
    (c_bugcheck_src,
     L"#006");
  }//if

  {
   if((*p)!=TAG_KEY_PLUGINS)
   {
    //ERROR - некорректная структура буфера с параметрами

    IBP_ThrowBugCheck_InfoBuf__UnknownTag
     (c_bugcheck_src,
      L"#007",
      *p);
   }//if

   ++p;

   if(p==_e_buffer)
   {
    //ERROR - некорректная структура буфера с параметрами

    IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd
     (c_bugcheck_src,
      L"#008");
   }//if

   const unsigned char cluster_length=*p;

   ++p;

   if((_e_buffer-p)<cluster_length)
   {
    //ERROR - некорректный размер данных элемента

    IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
     (c_bugcheck_src,
      L"#009",
      L"TAG_KEY_PLUGINS",
      cluster_length,
      (_e_buffer-p));
   }//if

   //! \note
   //!  В fbclient.dll зачем-то добавляют по одному пробелу в начало и конец plugins

   //transform UTF8 string to UCS2 string

   std::wstring srv_key__plugins;

   if(!IBP_Utils::Utf8ToWStr__Fast
        (structure::make_str_box(reinterpret_cast<const char*>(p),
                                 cluster_length),
         &srv_key__plugins))
   {
    //ERROR - ошибка преобразования UTF8-строки со списком имен алгоритмов в UCS2-строку

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_mce_remote__bug_check__cant_translate_wire_crypt_service_names_4,
      c_bugcheck_src,
      L"#010",
      L"UTF8",
      L"WSTR");
   }//if

   p+=cluster_length;

   //распаковка списка плагинов и регистрация описаний ключей

   //названия плагинов разделяются либо пробелами, либо запятыми

   std::wstring::const_iterator
    pp(srv_key__plugins.cbegin());

   std::wstring::const_iterator const
    ep(srv_key__plugins.cend());

   //----
   pp=structure::miss_space2(pp,ep);

   if(pp==ep)
   {
    //ERROR - пустой список с названиями плагинов

    IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
     (c_bugcheck_src,
      L"#011",
      L"TAG_KEY_PLUGINS");
   }//for

   enum sep_kind_type
   {
    sep_kind__unk   =0,
    sep_kind__space =1,
    sep_kind__comma =2,
   };//enum

   for(sep_kind_type sep_kind=sep_kind__unk;;)
   {
    assert(structure::miss_space2(pp,ep)==pp);

    const std::wstring::const_iterator
     pp1=pp;

    for(;pp!=ep && !structure::is_trim_char2(*pp) && (*pp)!=L',';++pp);

    if(pp1==pp)
    {
     //ERROR - некорректный формат списка плагинов

     IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
      (c_bugcheck_src,
       L"#012",
       L"TAG_KEY_PLUGINS");
    }//if

    assert(pp1!=pp);

    const std::wstring::const_iterator
     pp2=pp;

    pp=structure::miss_space2(pp,ep);

    const RemoteFB__KnownServerKey::self_ptr
     spSrvKey(RemoteFB__KnownServerKey::Create
               (srv_key__type,
                lib::structure::make_first_last(pp1,pp2)));

    assert(spSrvKey);

    clientConnectBlock.m_knownServerKeys.add(spSrvKey); //throw

    if(pp==ep)
     break;

    assert(pp!=ep);

    sep_kind_type cur_sep_kind DEBUG_CODE(=sep_kind__unk);

    if((*pp)==L',')
    {
     ++pp;

     pp=structure::miss_space2(pp,ep);

     cur_sep_kind=sep_kind__comma;
    }
    else
    {
     cur_sep_kind=sep_kind__space;
    }//else

    assert(cur_sep_kind!=sep_kind__unk);

    if(sep_kind==sep_kind__unk)
    {
     sep_kind=cur_sep_kind;
    }
    else
    if(sep_kind!=cur_sep_kind)
    {
     //ERROR - некорректный формат списка имен плагинов

     IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
      (c_bugcheck_src,
       L"#013",
       L"TAG_KEY_PLUGINS");
    }//if
   }//for[ever]
  }//local - TAG_KEY_PLUGINS
 }//while p!=_e_buffer
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
