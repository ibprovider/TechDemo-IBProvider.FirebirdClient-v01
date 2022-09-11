////////////////////////////////////////////////////////////////////////////////
//Вспомогательные утилиты для работы с COM-объектами
//                     Коваленко Дмитрий. файл сформирован 24 января 2002 года. 
#ifndef _ole_base_H_
#define _ole_base_H_

#include <ole_lib/ole_lib_cfg.h>

#include <structure/error/t_err_record.h>
#include <structure/t_char_converter.h>
#include <structure/t_str_parameter.h>
#include <structure/t_const_str_box.h>
#include <structure/t_exception.h>

#include <lcpi/infrastructure/os/windows-ole32.h>
#include <lcpi/infrastructure/os/windows-oleaut32.h>

#include <olectl.h>
//#include <oleidl.h>

////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/impl/ole_lib_impl_std_guids.hxx>
////////////////////////////////////////////////////////////////////////////////

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//Containing

class TGuidLess;
class TOleInitialize2;
class TComInitialize2;
class TBSTR;
class TOleStatus;
class t_base_com_error;
class t_base_ole_error;
class t_ole_error;

////////////////////////////////////////////////////////////////////////////////
using structure::t_char;
using structure::t_string;

////////////////////////////////////////////////////////////////////////////////
//Declare local variable 'hr'

#ifndef NDEBUG
# define OLE_LIB__DECLARE_HR(init_value)                         \
  HRESULT const hr_274B68E9B0254F1C97BBDEC1A205324D(init_value); \
                                                                 \
  HRESULT hr(hr_274B68E9B0254F1C97BBDEC1A205324D);hr;
#else
# define OLE_LIB__DECLARE_HR(init_value)                         \
  HRESULT hr(init_value);hr;
#endif

////////////////////////////////////////////////////////////////////////////////
//deprecated

#define OLE_DECLARE_HR(init_value)                               \
 OLE_LIB__DECLARE_HR(init_value)

////////////////////////////////////////////////////////////////////////////////
//Include declarations files

#include <ole_lib/impl/ole_lib_impl_co_task_memory.hxx>

#include <ole_lib/impl/ole_lib_impl_clipboard_formats.hxx>

#include <ole_lib/impl/ole_lib_impl_test_utils.hxx>
#include <ole_lib/impl/ole_lib_impl_guid_utils.hxx>

#include <ole_lib/impl/ole_lib_impl_bstr_utils.hxx>
#include <ole_lib/impl/ole_lib_impl_bstr.hxx>

#include <ole_lib/impl/ole_lib_impl_create_instance.hxx>

#include <ole_lib/impl/ole_lib_impl_error_helper_mac.hxx>
#include <ole_lib/impl/ole_lib_impl_error_utils.hxx>

#include <ole_lib/impl/ole_lib_impl_ole_status.hxx>
#include <ole_lib/impl/ole_lib_impl_base_com_error.hxx>
#include <ole_lib/impl/ole_lib_impl_base_ole_error.hxx>
#include <ole_lib/impl/ole_lib_impl_ole_error.hxx>

#include <ole_lib/impl/ole_lib_impl_connect_data2.hxx>

////////////////////////////////////////////////////////////////////////////////
//Helper macroses for exception throw

#define _THROW_OLE_FAILED(obj,func)                                          \
{                                                                            \
 if(FAILED((obj).func))                                                      \
  t_ole_error::throw_error((obj).m_last_result,(obj).get_text());            \
}

#define _THROW_OLE_FAILED_MSG(obj,func,msg)                                  \
{                                                                            \
 if(FAILED((obj).func))                                                      \
 {                                                                           \
  t_ole_error::throw_error((obj).m_last_result,(msg),(obj).get_text());      \
 }                                                                           \
}

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
////////////////////////////////////////////////////////////////////////////////
//STL specialization

namespace std{
////////////////////////////////////////////////////////////////////////////////

inline void swap(ole_lib::TConnectData2& x1,ole_lib::TConnectData2& x2)
{
 x1.swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std
#endif
