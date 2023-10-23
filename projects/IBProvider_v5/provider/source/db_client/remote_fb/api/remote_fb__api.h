////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api.h
//! \brief   Forward-объ€влени€ интерфейсов API.
//! \author  Kovalenko Dmitry
//! \date    24.02.2015
#ifndef _remote_fb__api_H_
#define _remote_fb__api_H_

#include "source/db_obj/db_svc.h"
#include <structure/t_smart_object.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////

#define IBP_REMOTE_FB__DEF_API_INTERFACE(name)                   \
 class name;                                                     \
                                                                 \
 using name##_Ptr=lib::structure::t_smart_object_ptr<name>;

//------------------------------------------------------------------------

#define IBP_REMOTE_FB__DEF_API_SVC_INTERFACE(name)               \
 class name;                                                     \
                                                                 \
 using name##_Ptr=lib::structure::t_smart_object_ptr<name>;      \
                                                                 \
 extern const GUID name##_Id;

////////////////////////////////////////////////////////////////////////////////

//макрос дл€ использовани€ в глобальном пространстве имен
#define IBP_REMOTE_FB__DEF_API_SVC_ID(interface_type)                           \
template<>                                                                      \
inline REFGUID LCPI_IBP_NMS::db_obj::__db_guid<LCPI_IBP_NMS::interface_type>()  \
{                                                                               \
 return LCPI_IBP_NMS::interface_type##_Id;                                      \
}

////////////////////////////////////////////////////////////////////////////////
//forward declarations

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__Commit)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__CommitRetaining)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__DetachDatabase)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__DropDatabase)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__GetDatabaseInfo)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__PrepareTransaction)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__Rollback)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__RollbackRetaining)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__StartTransaction)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__AllocateStatement)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__DropStatement)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__CloseStatement)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__PrepareStatement)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__GetStatementInfo)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__GetColumns)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__GetParameters)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__ExecuteStatement)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__ExecuteStatement_M)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__FetchStatement)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__FetchStatement_M)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__OpenBlob)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__CreateBlob)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__CloseBlob)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__CancelBlob)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__ReadBlob)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__WriteBlob)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__PutArraySlice)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__GetArraySlice)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__ExecuteImmediate)

IBP_REMOTE_FB__DEF_API_INTERFACE(RemoteFB__API__ExecuteImmediate_M)

////////////////////////////////////////////////////////////////////////////////
//Services for API

IBP_REMOTE_FB__DEF_API_SVC_INTERFACE(RemoteFB__SVC__CancelDbOperation)

////////////////////////////////////////////////////////////////////////////////

#undef IBP_REMOTE_FB__DEF_API_INTERFACE

#undef IBP_REMOTE_FB__DEF_API_SVC_INTERFACE

////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////

IBP_REMOTE_FB__DEF_API_SVC_ID(db_client::remote_fb::api::RemoteFB__SVC__CancelDbOperation)

////////////////////////////////////////////////////////////////////////////////
#endif
