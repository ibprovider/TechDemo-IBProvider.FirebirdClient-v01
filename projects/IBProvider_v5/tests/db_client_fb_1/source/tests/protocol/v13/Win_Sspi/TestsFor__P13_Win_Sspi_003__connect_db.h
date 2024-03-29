////////////////////////////////////////////////////////////////////////////////
//IBProvider Tests. RemoteFB.
//                                                 Kovalenko Dmitry. 10.01.2020
#ifndef _TestsFor__P13_Win_Sspi_003__connect_db_H_
#define _TestsFor__P13_Win_Sspi_003__connect_db_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__P13_Win_Sspi_003__connect_db

class TestsFor__P13_Win_Sspi_003__connect_db
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef TestsFor__P13_Win_Sspi_003__connect_db              self_type;

  TestsFor__P13_Win_Sspi_003__connect_db(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_wstr_box wstr_box_type;

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

  using PFnExec=void (*)(TTSO_Tracer&  tracer,
                         wstr_box_type hostName,
                         wstr_box_type dbName,
                         TestCnParams& params);

 private:
  TestsFor__P13_Win_Sspi_003__connect_db(TTSO_GlobalContext* pParams,
                                            const char*      pTestID,
                                            CryptMode        cryptMode,
                                            CompressMode     compressMode,
                                            PFnExec          pfnExec);

  virtual ~TestsFor__P13_Win_Sspi_003__connect_db();

 public:
  static void create(TTSO_PushTest*      pTestPusher,
                     TTSO_GlobalContext* pParams);

  //Test interface -------------------------------------------------------
  virtual const char* get_id()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool can_exec()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static void Helper__Exec_Ok
        (TTSO_Tracer&  tracer,
         wstr_box_type hostName,
         wstr_box_type dbName,
         TestCnParams& params);

  static void Helper__Exec_Failed
        (TTSO_Tracer&  tracer,
         wstr_box_type hostName,
         wstr_box_type dbName,
         TestCnParams& params);

 private:
  const TTSO_GlobalContext::self_cptr m_spParams;
  const std::string                   m_testID;
  const CryptMode                     m_cryptMode;
  const CompressMode                  m_compressMode;

  const PFnExec                       m_pfnExec;

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
  static const tagCryptModeDescr    sm_params__CryptModes[];
  static const tagCompressModeDescr sm_params__CompressModes[];
};//class TestsFor__P13_Win_Sspi_003__connect_db

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
