////////////////////////////////////////////////////////////////////////////////
//! \ingroup  oledb_lib_provider
//! \file     oledb_props2__data__op_ctx.cpp
//! \brief    Контекст операций со свойствами
//! \author   Kovalenko Dmitry
//! \date     02.03.2010
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/provider/props2/oledb_props2__data__op_ctx.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__OpCtx

OLEDB_Props2__Data__OpCtx::OLEDB_Props2__Data__OpCtx()
{;}

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpCtx::~OLEDB_Props2__Data__OpCtx()
{;}

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__OpCtx::AddItem(REFGUID id,ctx_item_type* const item)
{
 assert(item);

 const ctx_items_type::value_type x(id,structure::not_null_ptr(item));

 return m_items.insert(x).second;
}//AddItem

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpCtx::ctx_item_ptr OLEDB_Props2__Data__OpCtx::GetItem(REFGUID id)const
{
 const ctx_items_type::const_iterator i(m_items.find(id));

 if(i==m_items.end())
  return nullptr;

 return (*i).second;
}//GetItem

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
