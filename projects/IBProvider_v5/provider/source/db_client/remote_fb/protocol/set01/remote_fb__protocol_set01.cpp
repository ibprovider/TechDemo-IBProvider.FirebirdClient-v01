////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__protocol_set01
//! \file    remote_fb__protocol_set01.cpp
//! \brief   Конструкции протокола взаимодействия с FireBird.
//! \author  Kovalenko Dmitry
//! \date    27.04.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace protocol{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//struct P_OP_CNCT::P_OP_CNCT_REPEAT

void P_OP_CNCT::P_OP_CNCT_REPEAT::set(P_USHORT const version,
                                      P_ARCH   const architecture,
                                      P_USHORT const min_type,
                                      P_USHORT const max_type,
                                      P_USHORT const weight)
{
 this->p_cnct__version       =version;
 this->p_cnct__architecture  =architecture;
 this->p_cnct__min_type      =min_type;
 this->p_cnct__max_type      =max_type;
 this->p_cnct__weight        =weight;
}//set

////////////////////////////////////////////////////////////////////////////////
//struct P_OP_CNCT

void P_OP_CNCT::add_cntr_version(P_USHORT const version,
                                 P_ARCH   const architecture,
                                 P_USHORT const min_type,
                                 P_USHORT const max_type,
                                 P_USHORT const weight)
{
 assert(this->p_cnct__count<_DIM_(this->p_cnct__versions));

 this->p_cnct__versions[this->p_cnct__count].set
  (version,
   architecture,
   min_type,
   max_type,
   weight);

 ++this->p_cnct__count;
};//add_cntr_version

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms protocol*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
