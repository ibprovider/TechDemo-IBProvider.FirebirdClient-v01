////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                               Kovalenko Dmitry. 17.02.2019.
#ifndef _test_cn_params_H_
#define _test_cn_params_H_

#include "source/test_base.h"

#include "source/oledb/props2/values/datasource/ibp_oledb__props2__values__datasource.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestCnParams

class TestCnParams
{
 private:
  typedef TestCnParams                 self_type;

  TestCnParams(const self_type&);
  self_type& operator = (const self_type&);

 public:
  explicit TestCnParams(const TTSO_GlobalContext* const pParams);

  //interface ------------------------------------------------------------
  const TTSO_GlobalContext* GlobalCtx()const;

  ibp::oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* ptr()const;

  operator ibp::oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* ()const;

  //modificators ---------------------------------------------------------
  void set_dbprop_init__location(structure::t_const_wstr_box v);

  void set_dbprop_init__user_id(structure::t_const_wstr_box v);

  void set_dbprop_init__password(structure::t_const_wstr_box v);

  void set_dbprop_init__integrated_auth(structure::t_const_wstr_box v);

  void set_dbprop_init__ctype(structure::t_const_wstr_box v);

  void set_dbprop_init__remote__protocol(structure::t_const_wstr_box v);

  void set_dbprop_init__remote__protocol_type(structure::t_const_wstr_box v);

  void set_dbprop_init__remote__protocol_arch(structure::t_const_wstr_box v);

  void set_dbprop_init__remote__wire_crypt(structure::t_const_wstr_box v);

  void set_dbprop_init__remote__wire_compression(structure::t_const_wstr_box v);

  void set_dbprop_init__remote__wire_compression_type(structure::t_const_wstr_box v);

  void set_dbprop_init__remote__wire_compression_library(structure::t_const_wstr_box v);
  
  void set_dbprop_init__remote__wire_compression_library_64(structure::t_const_wstr_box v);

  void set_dbprop_init__remote__auth(structure::t_const_wstr_box v);

  void set_dbprop_newdb__page_size(LONG v);

 public:
  void reset_dbprop_init__remote__wire_crypt();

  void reset_dbprop_init__remote__wire_compression();

  void reset_dbprop_init__remote__wire_compression_type();

  void reset_dbprop_init__remote__wire_compression_library();

  void reset_dbprop_init__remote__wire_compression_library_64();

 private:
  const TTSO_GlobalContext::self_cptr m_spGlobalCtx;

  const ibp::oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE::self_ptr m_spDsPropValues;
};//class TestServices::tag_dbprops

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
