////////////////////////////////////////////////////////////////////////////////
//Utility classes
//                                               Dmitry Kovalenko. 02.10.2019
#ifndef _t_message_entry_H_
#define _t_message_entry_H_

#include <structure/t_common.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//contents

template<typename codeT,typename msgT>
class t_message_entry;

////////////////////////////////////////////////////////////////////////////////
//class t_message_entry

template<typename codeT,typename msgT>
class t_message_entry
{
 public: //typedefs ------------------------------------------------------
  typedef typename codeT       code_type;
  typedef typename msgT        msg_type;

 public: //---------------------------------------------------------------
  code_type code;
  msg_type  msg;
};//class t_message_entry

////////////////////////////////////////////////////////////////////////////////
//non members operators

template<typename codeT,typename msgT>
inline bool operator != (const t_message_entry<codeT,msgT>& entry,const codeT x)
{
 return entry.code!=x;
}//operator !=

//------------------------------------------------------------------------
template<typename codeT,typename msgT>
inline bool operator == (const t_message_entry<codeT,msgT>& entry,const codeT x)
{
 return entry.code==x;
}//operator ==

//------------------------------------------------------------------------
template<typename codeT,typename msgT>
inline bool operator < (const t_message_entry<codeT,msgT>& entry,const codeT x)
{
 return entry.code<x;
}//operator <

//------------------------------------------------------------------------
template<typename codeT,typename msgT>
inline bool operator != (const codeT x,const t_message_entry<codeT,msgT>& entry)
{
 return x!=entry.code;
}//operator !=

//------------------------------------------------------------------------
template<typename codeT,typename msgT>
inline bool operator == (const codeT x,const t_message_entry<codeT,msgT>& entry)
{
 return x==entry.code;
}//oerator ==

//------------------------------------------------------------------------
template<typename codeT,typename msgT>
inline bool operator < (const codeT x,const t_message_entry<codeT,msgT>& entry)
{
 return x<entry.code;
}//operator <

//------------------------------------------------------------------------
template<typename codeT,typename msgT>
inline bool operator < (const t_message_entry<codeT,msgT>& entry1,
                        const t_message_entry<codeT,msgT>& entry2)
{
 return entry1.code<entry2.code;
}//operator <

////////////////////////////////////////////////////////////////////////////////
}//class structure
#endif
