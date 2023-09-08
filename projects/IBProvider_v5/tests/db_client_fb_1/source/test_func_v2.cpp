////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_func_v2.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
// Копия значений, для избежания проблем с копирование значений
// статических переменных из других модулей.

static const ibp::t_ibp_char* const copy__ibp_propval__remote__ptype__rpc
 =IBP_T("rpc");

static const ibp::t_ibp_char* const copy__ibp_propval__remote__ptype__batch_send
 =IBP_T("batch_send");

static const ibp::t_ibp_char* const copy__ibp_propval__remote__ptype__out_of_band
 =IBP_T("out_of_band");

static const ibp::t_ibp_char* const copy__ibp_propval__remote__ptype__lazy_send
 =IBP_T("lazy_send");

////////////////////////////////////////////////////////////////////////////////
//Перечисление допустимых типов протокола, используемых при тестировании.

extern const ibp::t_ibp_char* const g_TestCfg__RemoteFB__ProtocolTypes[4]
{
 copy__ibp_propval__remote__ptype__rpc,
 copy__ibp_propval__remote__ptype__batch_send,
 copy__ibp_propval__remote__ptype__out_of_band,
 copy__ibp_propval__remote__ptype__lazy_send,
};//g_TestCfg__RemoteFB__ProtocolTypes

//------------------------------------------------------------------------
extern const ibp::t_ibp_char* const g_TestCfg__RemoteFB__ProtocolTypes__no_lazy[3]
{
 copy__ibp_propval__remote__ptype__rpc,
 copy__ibp_propval__remote__ptype__batch_send,
 copy__ibp_propval__remote__ptype__out_of_band,
};//g_TestCfg__RemoteFB__ProtocolTypes__no_lazy

//------------------------------------------------------------------------
extern const ibp::t_ibp_char* const g_TestCfg__RemoteFB__ProtocolTypes__lazy_send[1]
{
 copy__ibp_propval__remote__ptype__lazy_send,
};//g_TestCfg__RemoteFB__ProtocolTypes__lazy_send

////////////////////////////////////////////////////////////////////////////////

const ibp::t_ibp_string& TSO_RemoteFB_GetProtocolTypeSign(const ibp::t_ibp_string& ptype)
{
 return ptype;
}//TSO_RemoteFB_GetProtocolTypeSign

////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestData_v2

TTSO_TestData_v2::TTSO_TestData_v2()
{;}

//------------------------------------------------------------------------
bool TTSO_TestData_v2::can_exec(const TTSO_GlobalContext* const pParams)const
{
 assert(pParams);

 if(!m_RemoteFB__ProtocolType.null())
 {
  if(m_RemoteFB__ProtocolType.value()==copy__ibp_propval__remote__ptype__rpc)
  {
   //RPC устарело в FB3

   if(!pParams->calc_expression("NE__PTYPE_RPC"))
    return false;
  }//if
  else
  if(m_RemoteFB__ProtocolType.value()==copy__ibp_propval__remote__ptype__lazy_send)
  {
   //LAZY_SEND появился в FB2.1

   if(!pParams->calc_expression("NE__PTYPE_LAZY_SEND"))
    return false;
  }//if
 }//if

 return true;
}//can_exec

//------------------------------------------------------------------------
void TTSO_TestData_v2::SetParams(TestCnParams& params)const
{
 //temporary check.
 assert(!m_RemoteFB__ProtocolType.null());

 if(!m_RemoteFB__ProtocolType.null())
 {
  assert(!params.ptr()->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__PROTOCOL_TYPE,nullptr,nullptr));

  params.set_dbprop_init__remote__protocol_type(m_RemoteFB__ProtocolType.value());
 }//if
}//SetParams

////////////////////////////////////////////////////////////////////////////////
//class TTSO_TestFunc_v2

TTSO_TestFunc_v2::TTSO_TestFunc_v2(TTSO_GlobalContext* const pParams,
                                   const char*         const pTestID,
                                   TTestFunc           const Func,
                                   const TTSO_TestData_v2&   Data,
                                   const char*         const pExecRules)
 :m_spParams(structure::not_null_ptr(pParams))
 ,m_TestID(structure::not_null_ptr(pTestID))
 ,m_Func(structure::not_null_ptr(Func))
 ,m_Data(Data)
 ,m_ExecRules(pExecRules?pExecRules:"")
{
 assert(m_spParams);
 assert(!m_TestID.empty());
 assert(m_Func);
}//TTSO_TestFunc_v2

//------------------------------------------------------------------------
TTSO_TestFunc_v2::~TTSO_TestFunc_v2()
{;}

//test interface ---------------------------------------------------------
std::string TTSO_TestFunc_v2::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool TTSO_TestFunc_v2::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return m_spParams->calc_expression(m_ExecRules);
}//can_exec

//------------------------------------------------------------------------
void TTSO_TestFunc_v2::run(context_type* const pCtx)const
{
 assert(pCtx);
 assert(m_spParams);
 assert(m_Func);

 return m_Func(m_spParams,
               pCtx,
               m_Data);
}//run

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
