////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 15.09.2016
#ifndef _TestsFor__P13_Srp_002__create_db_H_
#define _TestsFor__P13_Srp_002__create_db_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__P13_Srp_002__create_db

class TestsFor__P13_Srp_002__create_db
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef TestsFor__P13_Srp_002__create_db              self_type;

  TestsFor__P13_Srp_002__create_db(const self_type&);
  self_type& operator = (const self_type&);

 public:
  enum class CryptMode
  {
   default_,
   disabled,
   enabled,
   required,
  };

  enum class CompressMode
  {
   default_,
   disabled,
   enabled,
   required,
  };

 private:
  TestsFor__P13_Srp_002__create_db(TTSO_GlobalContext* pParams,
                                   const char*         pTestID,
                                   const wchar_t*      pSrpName,
                                   CryptMode           cryptMode,
                                   CompressMode        compressMode);

  virtual ~TestsFor__P13_Srp_002__create_db();

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);

  //Test interface -------------------------------------------------------
  virtual std::string get_id()const COMP_W000004_OVERRIDE_FINAL;

  virtual bool can_exec()const COMP_W000004_OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const COMP_W000004_OVERRIDE_FINAL;

 private:
  const TTSO_GlobalContext::self_cptr m_spParams;
  const std::string                   m_testID;
  const std::wstring                  m_srpName;
  const CryptMode                     m_cryptMode;
  const CompressMode                  m_compressMode;

 private:
  struct tagCryptModeDescr
  {
   CryptMode   cryptMode;
   const char* sign;
  };

  struct tagCompressModeDescr
  {
   CompressMode compressMode;
   const char*  sign;
  };

 private:
  static const tagCryptModeDescr sm_params__CryptModes[];

  static const tagCompressModeDescr sm_params__CompressModes[];

  static const wchar_t* const sm_params__srpNames[];
};//class TestsFor__P13_Srp_002__create_db

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
