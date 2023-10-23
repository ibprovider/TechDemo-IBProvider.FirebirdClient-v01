////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__known_server_key.cpp
//! \brief   Массив объектов класса RemoteFB__KnownServerKey.
//! \author  Kovalenko Dmitry
//! \date    04.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__known_server_key_array.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__KnownServerKeyArray::tag_item_less

bool RemoteFB__KnownServerKeyArray::tag_item_less::operator()
                                           (const RemoteFB__KnownServerKey* const pK1,
                                            const RemoteFB__KnownServerKey* const pK2)const
{
 assert(pK1);
 assert(pK2);

 return lib::structure::pair_less
         (pK1->wstrType,pK1->wstrPlugin,
          pK2->wstrType,pK2->wstrPlugin);
}//operator ()

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__KnownServerKeyArray

RemoteFB__KnownServerKeyArray::RemoteFB__KnownServerKeyArray()
{;}

//------------------------------------------------------------------------
RemoteFB__KnownServerKeyArray::~RemoteFB__KnownServerKeyArray()
{;}

//interface --------------------------------------------------------------
void RemoteFB__KnownServerKeyArray::add(const RemoteFB__KnownServerKey* const pKey)
{
 assert(pKey);

 std::pair<item_index_type::const_iterator,bool>
  insert_result(m_index.insert(pKey));

 if(!insert_result.second)
 {
  //ERROR - повторная регистрация ключа. выкидываем ошибку.

  RemoteFB__ErrorUtils::Throw__MultipleDefinitionOfServerKey
   (ibp_subsystem__remote_fb,
    pKey->wstrType,
    pKey->wstrPlugin);
 }//if

 try
 {
  m_items.push_back(pKey);
 }
 catch(...)
 {
  m_index.erase(insert_result.first);

  throw;
 }//catch
}//add

//------------------------------------------------------------------------
RemoteFB__KnownServerKeyArray::size_type
 RemoteFB__KnownServerKeyArray::size()const
{
 return m_items.size();
}//size

//------------------------------------------------------------------------
bool
 RemoteFB__KnownServerKeyArray::empty()const
{
 return m_items.empty();
}//empty

//------------------------------------------------------------------------
const RemoteFB__KnownServerKey*
 RemoteFB__KnownServerKeyArray::operator [] (size_type index)const
{
 assert(index<m_items.size());

 return m_items[index];
}//operator []

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
