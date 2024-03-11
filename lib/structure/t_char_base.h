////////////////////////////////////////////////////////////////////////////////
//Base header of library for work with chars
//                                                 Dmitry Kovalenko. 19.04.2004.
#ifndef _t_char_base_H_
#define _t_char_base_H_

#include <lcpi/lib/.config.h>
#include <string>
#include <tchar.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//declare target types

#ifndef _UNICODE
 typedef std::string                t_string;
 typedef char                       t_char;
 typedef unsigned char              t_byte;
#else
 typedef std::wstring               t_string;
 typedef wchar_t                    t_char;
 typedef wchar_t                    t_byte;
#endif //UNICODE

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif