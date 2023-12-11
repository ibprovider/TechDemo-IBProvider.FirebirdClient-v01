////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__client_connect_block_v1.cpp
//! \brief   Класс для управления данными подключения.
//! \author  Kovalenko Dmitry
//! \date    11.07.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__client_connect_block_v1.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ClientConnectBlock_v1::tag_expected_ptype_descr

RemoteFB__ClientConnectBlock_v1::tag_expected_ptype_descr::tag_expected_ptype_descr
                                           ()
{;}

//------------------------------------------------------------------------
RemoteFB__ClientConnectBlock_v1::tag_expected_ptype_descr::tag_expected_ptype_descr
    (ptype_id_type                    const _ptypeID,
     lib::structure::t_const_wstr_box const _ptypeSign)
 :ptypeID(_ptypeID)
 ,ptypeSign(_ptypeSign.begin(),_ptypeSign.end())
{;}

//------------------------------------------------------------------------
RemoteFB__ClientConnectBlock_v1::tag_expected_ptype_descr::tag_expected_ptype_descr
    (lib::structure::t_const_wstr_box const _ptypeSign)
 :ptypeSign(_ptypeSign.begin(),_ptypeSign.end())
{;}

//------------------------------------------------------------------------
RemoteFB__ClientConnectBlock_v1::tag_expected_ptype_descr::~tag_expected_ptype_descr()
{;}

//------------------------------------------------------------------------
bool RemoteFB__ClientConnectBlock_v1::tag_expected_ptype_descr::operator == (ptype_id_type const id)const
{
 return this->ptypeID==id;
}//operator ==

//------------------------------------------------------------------------
bool RemoteFB__ClientConnectBlock_v1::tag_expected_ptype_descr::operator != (ptype_id_type const id)const
{
 return !((*this)==id);
}//operator !=

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ClientConnectBlock_v1

RemoteFB__ClientConnectBlock_v1::RemoteFB__ClientConnectBlock_v1
                               (oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues)
 :m_spDsPropValues(lib::structure::not_null_ptr(pDsPropValues))
 ,m_AuthKind(auth_kind__none)
{
 assert(m_spDsPropValues);
}//RemoteFB__ClientConnectBlock_v1

//------------------------------------------------------------------------
RemoteFB__ClientConnectBlock_v1::~RemoteFB__ClientConnectBlock_v1()
{;}

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
