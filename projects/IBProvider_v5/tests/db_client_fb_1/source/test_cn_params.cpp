////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/test_cn_params.h"

#include "source/oledb/props2/descrs/ibp_oledb__props2__descrs__factory__dbinit_std.h"
#include "source/oledb/props2/descrs/ibp_oledb__props2__descrs__factory__dbinit_ext.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__manager__values.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestCnParams

TestCnParams::TestCnParams(const TTSO_GlobalContext* const pParams)
 :m_spGlobalCtx(structure::not_null_ptr(pParams))
 ,m_spDsPropValues(ibp::oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE::Create())
{
 assert(m_spGlobalCtx);
 assert(m_spDsPropValues);

 if(const TSYS_CommandLine::cmd_arg_ptr spCnStr=m_spGlobalCtx->args().get(c_prog_arg__cn_str,false))
 {
  oledb_lib::OLEDB_Props2__Data__Descrs::self_cptr
   spDescrs_STD(ibp::oledb::props2::IBP_OLEDB_Props2__Descrs_Factory__DBINIT_STD::CreatePropDescrs());

  oledb_lib::OLEDB_Props2__Data__Descrs::self_cptr
   spDescrs_EXT(ibp::oledb::props2::IBP_OLEDB_Props2__Descrs_Factory__DBINIT_EXT::CreatePropDescrs());

  oledb_lib::OLEDB_Props2__Manager__Values
   DsPropValuesMng;

  DsPropValuesMng.AddInfo(spDescrs_STD);
  DsPropValuesMng.AddInfo(spDescrs_EXT);

  oledb_lib::TDBPROP prop;

  prop.dwPropertyID=DBPROP_INIT_PROVIDERSTRING;
  prop.dwOptions   =DBPROPOPTIONS_REQUIRED;
  prop             =ole_lib::TVariant(spCnStr->m_value);

  DBPROPSET propset={};

  propset.guidPropertySet=DBPROPSET_DBINIT;
  propset.cProperties    =1;
  propset.rgProperties   =&prop;

  const HRESULT hr=DsPropValuesMng.SetProperties
                     (m_spDsPropValues,
                      1,
                      &propset,
                      true,
                      /*pfnSetFilter*/nullptr);

  if(hr!=S_OK)
  {
   structure::str_formatter fmsg("Failed to set connection string properties: %1. PropStatus: %2.");

   fmsg<<ole_lib::TestHResult(hr)<<oledb_lib::GetDBPropStatusName(prop.dwStatus);

   throw std::runtime_error(fmsg.str());
  }//if hr!=S_OK

  assert_hint(hr==S_OK);

  if(prop.dwStatus!=DBPROPSTATUS_OK)
  {
   structure::str_formatter fmsg("Failed to set connection string properties. PropStatus: %1.");

   fmsg<<oledb_lib::GetDBPropStatusName(prop.dwStatus);

   throw std::runtime_error(fmsg.str());
  }//if prop.dwStatus!=DBPROPSTATUS_OK
 }//if spCnStr
}//TestCnParams

//------------------------------------------------------------------------
const TTSO_GlobalContext* TestCnParams::GlobalCtx()const
{
 assert(m_spGlobalCtx);

 return m_spGlobalCtx;
}//GlobalCtx

//------------------------------------------------------------------------
ibp::oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* TestCnParams::ptr()const
{
 return m_spDsPropValues;
}//ptr

//------------------------------------------------------------------------
TestCnParams::operator ibp::oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* () const
{
 return m_spDsPropValues;
}//operator

//modificators -----------------------------------------------------------
void TestCnParams::set_dbprop_init__location
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (DBPROPSET_DBINIT,
   DBPROP_INIT_LOCATION,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__location

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__user_id
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (DBPROPSET_DBINIT,
   DBPROP_AUTH_USERID,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__user_id

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__password
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (DBPROPSET_DBINIT,
   DBPROP_AUTH_PASSWORD,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__password

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__integrated_auth
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (DBPROPSET_DBINIT,
   DBPROP_AUTH_INTEGRATED,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__integrated_auth

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__remote__protocol
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__PROTOCOL,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__remote__protocol

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__remote__protocol_arch
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__PROTOCOL_ARCHITECTURE,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__remote__protocol_arch

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__remote__protocol_type
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__PROTOCOL_TYPE,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__remote__protocol_type

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__remote__wire_crypt
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_CRYPT,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__remote__wire_crypt

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__remote__wire_compression
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__remote__wire_compression

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__remote__wire_compression_type
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_TYPE,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__remote__wire_compression_type

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__remote__wire_compression_library
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__remote__wire_compression_library

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__remote__wire_compression_library_64
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY_64,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__remote__wire_compression_library_64

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_init__remote__auth
                                      (structure::t_const_wstr_box const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__AUTH,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_init__remote__auth

//------------------------------------------------------------------------------
void TestCnParams::set_dbprop_newdb__page_size(LONG const v)
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_DATASOURCECREATE,
   ibprovider::IBP_DBPROP__DSCREATE__DATABASE_PAGE_SIZE,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(v));
}//set_dbprop_newdb__page_size

//reset methods ----------------------------------------------------------------
void TestCnParams::reset_dbprop_init__remote__wire_crypt()
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_CRYPT,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant::empty_variant);
}//set_dbprop_init__remote__wire_crypt

//------------------------------------------------------------------------------
void TestCnParams::reset_dbprop_init__remote__wire_compression()
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant::empty_variant);
}//reset_dbprop_init__remote__wire_compression

//------------------------------------------------------------------------------
void TestCnParams::reset_dbprop_init__remote__wire_compression_type()
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_TYPE,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant::empty_variant);
}//reset_dbprop_init__remote__wire_compression_type

//------------------------------------------------------------------------------
void TestCnParams::reset_dbprop_init__remote__wire_compression_library()
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant::empty_variant);
}//reset_dbprop_init__remote__wire_compression_library

//------------------------------------------------------------------------------
void TestCnParams::reset_dbprop_init__remote__wire_compression_library_64()
{
 assert(m_spDsPropValues);

 m_spDsPropValues->Direct__SetValue
  (ibprovider::IBP_DBPROPSET_INIT,
   ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY_64,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant::empty_variant);
}//reset_dbprop_init__remote__wire_compression_library_64

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
