////////////////////////////////////////////////////////////////////////////////
//Helper macroses
//                                                 Dmitry Kovalenko. 13.12.2001.

#ifndef __util_mac_H_
#define __util_mac_H_

////////////////////////////////////////////////////////////////////////////////

#define UNUSED_ARG(name)

////////////////////////////////////////////////////////////////////////////////

#define _LITER_COMMA_ ,

#define _DIM_(__Array__) (sizeof(__Array__)/sizeof((__Array__)[0]))
#define _END_(__Array__) ((__Array__)+_DIM_(__Array__))

#define _BEG_END_(__Array__) (__Array__),_END_(__Array__)

#define _MEMBER_SIZE_(s_name,m_name) (sizeof(((s_name*)0)->m_name))
#define _MEMBER_DIM_(s_name,m_name)  _DIM_(((s_name*)0)->m_name)

#define _ARRAY_DIM_(__ArrayType__) (sizeof(__ArrayType__)/sizeof((**reinterpret_cast<__ArrayType__*>(0))))

//------------------------------------------------------------------------

#define _MAKELONG(a,b) \
 ((LONG) (((WORD) (a)) | (((DWORD) ((WORD) (b))) << 16)))

#define _MAKELPARAM(l,h) ((LPARAM) _MAKELONG(l, h))

////////////////////////////////////////////////////////////////////////////////
#endif
