////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator
//                                                Kovalenko Dmitry. 04.10.2017.
#ifndef _oledb_variant__comparator2_context_std_H_
#define _oledb_variant__comparator2_context_std_H_

#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2_context.h>

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////
//class TDBVariantComparator2_Context_STD

class TDBVariantComparator2_Context_STD:public TDBVariantComparator2_Context
{
 private:
  typedef TDBVariantComparator2_Context_STD              self_type;

  TDBVariantComparator2_Context_STD(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TDBVariantComparator2_Context_STD();

  explicit TDBVariantComparator2_Context_STD(const TDBVariantCompare2_Settings& Settings);

 ~TDBVariantComparator2_Context_STD();

  //interface ------------------------------------------------------------
  virtual const TDBVariantCompare2_Settings& GetSettings()const COMP_W000004_OVERRIDE_FINAL;

  virtual const TDBVariantComparator2* GetComparator(DBTYPE dbtype1,
                                                     DBTYPE dbtype2) COMP_W000004_OVERRIDE;

 private: //typedefs -----------------------------------------------------
  class tag_helpers;
  class tag_get_descr;
  class tag_data;

 private:
  typedef const TDBVariantComparator2*    pcomparator_type;

  typedef pcomparator_type (*pfn_GetCompWith)(DBTYPE dbtype2);

 private:
  const TDBVariantCompare2_Settings m_Settings;

 private:
  static pcomparator_type Helper__Get_Comparator(DBTYPE dbtype1,
                                                 DBTYPE dbtype2);

  static pfn_GetCompWith Helper__Get_GetCompWith(DBTYPE dbtype1);
};//class TDBVariantComparator2_Context_STD

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}/*nms oledb_lib*/
#endif
